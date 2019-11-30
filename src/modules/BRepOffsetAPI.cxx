/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <BRepTools_ReShape.hxx>
#include <BRepBuilderAPI_ModifyShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <Draft_ErrorStatus.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepOffsetAPI_DraftAngle.hxx>
#include <Standard_Handle.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <BRepOffsetAPI_FindContigousEdges.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <BRepBuilderAPI_TransitionMode.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Shell.hxx>
#include <BRepFill_Draft.hxx>
#include <BRepOffsetAPI_MakeDraft.hxx>
#include <TopoDS_Wire.hxx>
#include <GeomAbs_JoinType.hxx>
#include <BRepFill_Evolved.hxx>
#include <BRepFill_AdvancedEvolved.hxx>
#include <BRepOffsetAPI_MakeEvolved.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <BRepFill_Filling.hxx>
#include <BRepOffsetAPI_MakeFilling.hxx>
#include <BRepFill_ListOfOffsetWire.hxx>
#include <BRepOffsetAPI_MakeOffset.hxx>
#include <BRepOffset_Mode.hxx>
#include <BRepOffset_MakeOffset.hxx>
#include <BRepOffsetAPI_MakeOffsetShape.hxx>
#include <BRepOffset_MakeSimpleOffset.hxx>
#include <BRepPrimAPI_MakeSweep.hxx>
#include <GeomFill_Trihedron.hxx>
#include <BRepFill_Pipe.hxx>
#include <BRepOffsetAPI_MakePipe.hxx>
#include <gp_Ax2.hxx>
#include <BRepFill_TypeOfContact.hxx>
#include <TopoDS_Vertex.hxx>
#include <Law_Function.hxx>
#include <BRepBuilderAPI_PipeError.hxx>
#include <BRepFill_PipeShell.hxx>
#include <BRepOffsetAPI_MakePipeShell.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <NCollection_Sequence.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <BRepOffsetAPI_SequenceOfSequenceOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepOffsetAPI_MiddlePath.hxx>
#include <BRepAlgo_NormalProjection.hxx>
#include <BRepOffsetAPI_NormalProjection.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <BRepOffsetAPI_SequenceOfSequenceOfReal.hxx>
#include <BRepOffsetAPI_Sewing.hxx>
#include <Approx_ParametrizationType.hxx>
#include <Geom_BSplineSurface.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <TopTools_DataMapOfShapeListOfInteger.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(BRepOffsetAPI, mod) {

py::module::import("OCCT.TopoDS");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.BRepBuilderAPI");
py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Draft");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Geom");
py::module::import("OCCT.BRepFill");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.BRepOffset");
py::module::import("OCCT.BRepPrimAPI");
py::module::import("OCCT.GeomFill");
py::module::import("OCCT.Law");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.BRepAlgo");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Approx");

// CLASS: BREPOFFSETAPI_DRAFTANGLE
py::class_<BRepOffsetAPI_DraftAngle, BRepBuilderAPI_ModifyShape> cls_BRepOffsetAPI_DraftAngle(mod, "BRepOffsetAPI_DraftAngle", "Taper-adding transformations on a shape. The resulting shape is constructed by defining one face to be tapered after another one, as well as the geometric properties of their tapered transformation. Each tapered transformation is propagated along the series of faces which are tangential to one another and which contains the face to be tapered. This algorithm is useful in the construction of molds or dies. It facilitates the removal of the article being produced. A DraftAngle object provides a framework for: - initializing the construction algorithm with a given shape, - acquiring the data characterizing the faces to be tapered, - implementing the construction algorithm, and - consulting the results. Warning - This algorithm treats planar, cylindrical and conical faces. - Do not use shapes, which with a draft angle added to a face would modify the topology. This would, for example, involve creation of new vertices, edges or faces, or suppression of existing vertices, edges or faces. - Any face, which is continuous in tangency with the face to be tapered, will also be tapered. These connected faces must also respect the above criteria.");

// Constructors
cls_BRepOffsetAPI_DraftAngle.def(py::init<>());
cls_BRepOffsetAPI_DraftAngle.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
// cls_BRepOffsetAPI_DraftAngle.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_DraftAngle::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_DraftAngle::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_DraftAngle::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_DraftAngle::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_DraftAngle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_DraftAngle::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_DraftAngle.def("Clear", (void (BRepOffsetAPI_DraftAngle::*)()) &BRepOffsetAPI_DraftAngle::Clear, "Cancels the results of all taper-adding transformations performed by this algorithm on the initial shape. These results will have been defined by successive calls to the function Add.");
cls_BRepOffsetAPI_DraftAngle.def("Init", (void (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Shape &)) &BRepOffsetAPI_DraftAngle::Init, "Initializes, or reinitializes this taper-adding algorithm with the shape S. S will be referred to as the initial shape of this algorithm.", py::arg("S"));
cls_BRepOffsetAPI_DraftAngle.def("Add", [](BRepOffsetAPI_DraftAngle &self, const TopoDS_Face & a0, const gp_Dir & a1, const Standard_Real a2, const gp_Pln & a3) -> void { return self.Add(a0, a1, a2, a3); });
cls_BRepOffsetAPI_DraftAngle.def("Add", (void (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Face &, const gp_Dir &, const Standard_Real, const gp_Pln &, const Standard_Boolean)) &BRepOffsetAPI_DraftAngle::Add, "Adds the face F, the direction Direction, the angle Angle, the plane NeutralPlane, and the flag Flag to the framework created at construction time, and with this data, defines the taper-adding transformation. F is a face, which belongs to the initial shape of this algorithm or to the shape loaded by the function Init. Only planar, cylindrical or conical faces can be tapered: - If the face F is planar, it is tapered by inclining it through the angle Angle about the line of intersection between the plane NeutralPlane and F. Direction indicates the side of NeutralPlane from which matter is removed if Angle is positive or added if Angle is negative. - If F is cylindrical or conical, it is transformed in the same way on a single face, resulting in a conical face if F is cylindrical, and a conical or cylindrical face if it is already conical. The taper-adding transformation is propagated from the face F along the series of planar, cylindrical or conical faces containing F, which are tangential to one another. Use the function AddDone to check if this taper-adding transformation is successful. Warning Nothing is done if: - the face F does not belong to the initial shape of this algorithm, or - the face F is not planar, cylindrical or conical. Exceptions - Standard_NullObject if the initial shape is not defined, i.e. if this algorithm has not been initialized with the non-empty constructor or the Init function. - Standard_ConstructionError if the previous call to Add has failed. The function AddDone ought to have been used to check for this, and the function Remove to cancel the results of the unsuccessful taper-adding transformation and to retrieve the previous shape.", py::arg("F"), py::arg("Direction"), py::arg("Angle"), py::arg("NeutralPlane"), py::arg("Flag"));
cls_BRepOffsetAPI_DraftAngle.def("AddDone", (Standard_Boolean (BRepOffsetAPI_DraftAngle::*)() const) &BRepOffsetAPI_DraftAngle::AddDone, "Returns true if the previous taper-adding transformation performed by this algorithm in the last call to Add, was successful. If AddDone returns false: - the function ProblematicShape returns the face on which the error occurred, - the function Remove has to be used to cancel the results of the unsuccessful taper-adding transformation and to retrieve the previous shape. Exceptions Standard_NullObject if the initial shape has not been defined, i.e. if this algorithm has not been initialized with the non-empty constructor or the .Init function.");
cls_BRepOffsetAPI_DraftAngle.def("Remove", (void (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Face &)) &BRepOffsetAPI_DraftAngle::Remove, "Cancels the taper-adding transformation previously performed by this algorithm on the face F and the series of tangential faces which contain F, and retrieves the shape before the last taper-adding transformation. Warning You will have to use this function if the previous call to Add fails. Use the function AddDone to check it. Exceptions - Standard_NullObject if the initial shape has not been defined, i.e. if this algorithm has not been initialized with the non-empty constructor or the Init function. - Standard_NoSuchObject if F has not been added or has already been removed.", py::arg("F"));
cls_BRepOffsetAPI_DraftAngle.def("ProblematicShape", (const TopoDS_Shape & (BRepOffsetAPI_DraftAngle::*)() const) &BRepOffsetAPI_DraftAngle::ProblematicShape, "Returns the shape on which an error occurred after an unsuccessful call to Add or when IsDone returns false. Exceptions Standard_NullObject if the initial shape has not been defined, i.e. if this algorithm has not been initialized with the non-empty constructor or the Init function.");
cls_BRepOffsetAPI_DraftAngle.def("Status", (Draft_ErrorStatus (BRepOffsetAPI_DraftAngle::*)() const) &BRepOffsetAPI_DraftAngle::Status, "Returns an error status when an error has occured (Face, Edge or Vertex recomputaion problem). Otherwise returns Draft_NoError. The method may be called if AddDone returns Standard_False, or when IsDone returns Standard_False.");
cls_BRepOffsetAPI_DraftAngle.def("ConnectedFaces", (const TopTools_ListOfShape & (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Face &) const) &BRepOffsetAPI_DraftAngle::ConnectedFaces, "Returns all the faces which have been added together with the face <F>.", py::arg("F"));
cls_BRepOffsetAPI_DraftAngle.def("ModifiedFaces", (const TopTools_ListOfShape & (BRepOffsetAPI_DraftAngle::*)() const) &BRepOffsetAPI_DraftAngle::ModifiedFaces, "Returns all the faces on which a modification has been given.");
cls_BRepOffsetAPI_DraftAngle.def("Build", (void (BRepOffsetAPI_DraftAngle::*)()) &BRepOffsetAPI_DraftAngle::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepOffsetAPI_DraftAngle.def("CorrectWires", (void (BRepOffsetAPI_DraftAngle::*)()) &BRepOffsetAPI_DraftAngle::CorrectWires, "None");
cls_BRepOffsetAPI_DraftAngle.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Shape &)) &BRepOffsetAPI_DraftAngle::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_DraftAngle.def("Modified", (const TopTools_ListOfShape & (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Shape &)) &BRepOffsetAPI_DraftAngle::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_DraftAngle.def("ModifiedShape", (TopoDS_Shape (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_DraftAngle::ModifiedShape, "Returns the modified shape corresponding to <S>. S can correspond to the entire initial shape or to its subshape. Raises exceptions Standard_NoSuchObject if S is not the initial shape or a subshape of the initial shape to which the transformation has been applied.", py::arg("S"));

// CLASS: BREPOFFSETAPI_FINDCONTIGOUSEDGES
py::class_<BRepOffsetAPI_FindContigousEdges> cls_BRepOffsetAPI_FindContigousEdges(mod, "BRepOffsetAPI_FindContigousEdges", "Provides methods to identify contigous boundaries for continuity control (C0, C1, ...)");

// Constructors
cls_BRepOffsetAPI_FindContigousEdges.def(py::init<>());
cls_BRepOffsetAPI_FindContigousEdges.def(py::init<const Standard_Real>(), py::arg("tolerance"));
cls_BRepOffsetAPI_FindContigousEdges.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option"));

// Methods
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_FindContigousEdges::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_FindContigousEdges::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_FindContigousEdges::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_FindContigousEdges::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_FindContigousEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_FindContigousEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_FindContigousEdges.def("Init", (void (BRepOffsetAPI_FindContigousEdges::*)(const Standard_Real, const Standard_Boolean)) &BRepOffsetAPI_FindContigousEdges::Init, "Initializes this algorithm for identifying contiguous edges on shapes using the tolerance of contiguity tolerance. This tolerance value is used to determine whether two edges or sections of edges are coincident. Use the function Add to define the shapes to be checked. Sets <option> to false.", py::arg("tolerance"), py::arg("option"));
cls_BRepOffsetAPI_FindContigousEdges.def("Add", (void (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Shape &)) &BRepOffsetAPI_FindContigousEdges::Add, "Adds the shape shape to the list of shapes to be checked by this algorithm. Once all the shapes to be checked have been added, use the function Perform to find the contiguous edges and the function ContigousEdge to return these edges.", py::arg("shape"));
cls_BRepOffsetAPI_FindContigousEdges.def("Perform", (void (BRepOffsetAPI_FindContigousEdges::*)()) &BRepOffsetAPI_FindContigousEdges::Perform, "Finds coincident parts of edges of two or more shapes added to this algorithm and breaks down these edges into contiguous and non-contiguous sections on copies of the initial shapes. The function ContigousEdge returns contiguous edges. The function Modified can be used to return modified copies of the initial shapes where one or more edges were broken down into contiguous and non-contiguous sections. Warning This function must be used once all the shapes to be checked have been added. It is not possible to add further shapes subsequently and then to repeat the call to Perform.");
// cls_BRepOffsetAPI_FindContigousEdges.def("NbEdges", (Standard_Integer (BRepOffsetAPI_FindContigousEdges::*)() const) &BRepOffsetAPI_FindContigousEdges::NbEdges, "Gives the number of edges (free edges + contigous edges + multiple edge)");
cls_BRepOffsetAPI_FindContigousEdges.def("NbContigousEdges", (Standard_Integer (BRepOffsetAPI_FindContigousEdges::*)() const) &BRepOffsetAPI_FindContigousEdges::NbContigousEdges, "Returns the number of contiguous edges found by the function Perform on the shapes added to this algorithm.");
cls_BRepOffsetAPI_FindContigousEdges.def("ContigousEdge", (const TopoDS_Edge & (BRepOffsetAPI_FindContigousEdges::*)(const Standard_Integer) const) &BRepOffsetAPI_FindContigousEdges::ContigousEdge, "Returns the contiguous edge of index index found by the function Perform on the shapes added to this algorithm. Exceptions Standard_OutOfRange if: - index is less than 1, or - index is greater than the number of contiguous edges found by the function Perform on the shapes added to this algorithm.", py::arg("index"));
cls_BRepOffsetAPI_FindContigousEdges.def("ContigousEdgeCouple", (const TopTools_ListOfShape & (BRepOffsetAPI_FindContigousEdges::*)(const Standard_Integer) const) &BRepOffsetAPI_FindContigousEdges::ContigousEdgeCouple, "Returns a list of edges coincident with the contiguous edge of index index found by the function Perform. There are as many edges in the list as there are faces adjacent to this contiguous edge. Exceptions Standard_OutOfRange if: - index is less than 1, or - index is greater than the number of contiguous edges found by the function Perform on the shapes added to this algorithm.", py::arg("index"));
cls_BRepOffsetAPI_FindContigousEdges.def("SectionToBoundary", (const TopoDS_Edge & (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Edge &) const) &BRepOffsetAPI_FindContigousEdges::SectionToBoundary, "Returns the edge on the initial shape, of which the modified copy contains the edge section. section is coincident with a contiguous edge found by the function Perform. Use the function ContigousEdgeCouple to obtain a valid section. This information is useful for verification purposes, since it provides a means of determining the surface to which the contiguous edge belongs. Exceptions Standard_NoSuchObject if section is not coincident with a contiguous edge. Use the function ContigousEdgeCouple to obtain a valid section.", py::arg("section"));
cls_BRepOffsetAPI_FindContigousEdges.def("NbDegeneratedShapes", (Standard_Integer (BRepOffsetAPI_FindContigousEdges::*)() const) &BRepOffsetAPI_FindContigousEdges::NbDegeneratedShapes, "Gives the number of degenerated shapes");
cls_BRepOffsetAPI_FindContigousEdges.def("DegeneratedShape", (const TopoDS_Shape & (BRepOffsetAPI_FindContigousEdges::*)(const Standard_Integer) const) &BRepOffsetAPI_FindContigousEdges::DegeneratedShape, "Gives a degenerated shape", py::arg("index"));
cls_BRepOffsetAPI_FindContigousEdges.def("IsDegenerated", (Standard_Boolean (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_FindContigousEdges::IsDegenerated, "Indicates if a input shape is degenerated", py::arg("shape"));
cls_BRepOffsetAPI_FindContigousEdges.def("IsModified", (Standard_Boolean (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_FindContigousEdges::IsModified, "Returns true if the copy of the initial shape shape was modified by the function Perform (i.e. if one or more of its edges was broken down into contiguous and non-contiguous sections). Warning Returns false if shape is not one of the initial shapes added to this algorithm.", py::arg("shape"));
cls_BRepOffsetAPI_FindContigousEdges.def("Modified", (const TopoDS_Shape & (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_FindContigousEdges::Modified, "Gives a modifieded shape Raises NoSuchObject if shape has not been modified", py::arg("shape"));
cls_BRepOffsetAPI_FindContigousEdges.def("Dump", (void (BRepOffsetAPI_FindContigousEdges::*)() const) &BRepOffsetAPI_FindContigousEdges::Dump, "Dump properties of resulting shape.");

// CLASS: BREPOFFSETAPI_MAKEDRAFT
py::class_<BRepOffsetAPI_MakeDraft, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MakeDraft(mod, "BRepOffsetAPI_MakeDraft", "Build a draft surface along a wire");

// Constructors
cls_BRepOffsetAPI_MakeDraft.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Real>(), py::arg("Shape"), py::arg("Dir"), py::arg("Angle"));

// Methods
// cls_BRepOffsetAPI_MakeDraft.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeDraft::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeDraft::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeDraft::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeDraft::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeDraft::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeDraft.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeDraft::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeDraft.def("SetOptions", [](BRepOffsetAPI_MakeDraft &self) -> void { return self.SetOptions(); });
cls_BRepOffsetAPI_MakeDraft.def("SetOptions", [](BRepOffsetAPI_MakeDraft &self, const BRepBuilderAPI_TransitionMode a0) -> void { return self.SetOptions(a0); });
cls_BRepOffsetAPI_MakeDraft.def("SetOptions", [](BRepOffsetAPI_MakeDraft &self, const BRepBuilderAPI_TransitionMode a0, const Standard_Real a1) -> void { return self.SetOptions(a0, a1); });
cls_BRepOffsetAPI_MakeDraft.def("SetOptions", (void (BRepOffsetAPI_MakeDraft::*)(const BRepBuilderAPI_TransitionMode, const Standard_Real, const Standard_Real)) &BRepOffsetAPI_MakeDraft::SetOptions, "Sets the options of this draft tool. If a transition has to be performed, it can be defined by the mode Style as RightCorner or RoundCorner, RightCorner being a corner defined by a sharp angle, and RoundCorner being a rounded corner. AngleMin is an angular tolerance used to detect whether a transition has to be performed or not. AngleMax sets the maximum value within which a RightCorner transition can be performed. AngleMin and AngleMax are expressed in radians.", py::arg("Style"), py::arg("AngleMin"), py::arg("AngleMax"));
cls_BRepOffsetAPI_MakeDraft.def("SetDraft", [](BRepOffsetAPI_MakeDraft &self) -> void { return self.SetDraft(); });
cls_BRepOffsetAPI_MakeDraft.def("SetDraft", (void (BRepOffsetAPI_MakeDraft::*)(const Standard_Boolean)) &BRepOffsetAPI_MakeDraft::SetDraft, "Sets the direction of the draft for this object. If IsInternal is true, the draft is internal to the argument Shape used in the constructor.", py::arg("IsInternal"));
cls_BRepOffsetAPI_MakeDraft.def("Perform", (void (BRepOffsetAPI_MakeDraft::*)(const Standard_Real)) &BRepOffsetAPI_MakeDraft::Perform, "Performs the draft using the length LengthMax as the maximum length for the corner edge between two draft faces.", py::arg("LengthMax"));
cls_BRepOffsetAPI_MakeDraft.def("Perform", [](BRepOffsetAPI_MakeDraft &self, const opencascade::handle<Geom_Surface> & a0) -> void { return self.Perform(a0); });
cls_BRepOffsetAPI_MakeDraft.def("Perform", (void (BRepOffsetAPI_MakeDraft::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean)) &BRepOffsetAPI_MakeDraft::Perform, "Performs the draft up to the surface Surface. If KeepInsideSurface is true, the part of Surface inside the draft is kept in the result.", py::arg("Surface"), py::arg("KeepInsideSurface"));
cls_BRepOffsetAPI_MakeDraft.def("Perform", [](BRepOffsetAPI_MakeDraft &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepOffsetAPI_MakeDraft.def("Perform", (void (BRepOffsetAPI_MakeDraft::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepOffsetAPI_MakeDraft::Perform, "Performs the draft up to the shape StopShape. If KeepOutSide is true, the part of StopShape which is outside the Draft is kept in the result.", py::arg("StopShape"), py::arg("KeepOutSide"));
cls_BRepOffsetAPI_MakeDraft.def("Shell", (TopoDS_Shell (BRepOffsetAPI_MakeDraft::*)() const) &BRepOffsetAPI_MakeDraft::Shell, "Returns the shell resulting from performance of the draft along the wire.");
cls_BRepOffsetAPI_MakeDraft.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeDraft::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeDraft::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));

// CLASS: BREPOFFSETAPI_MAKEEVOLVED
py::class_<BRepOffsetAPI_MakeEvolved, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MakeEvolved(mod, "BRepOffsetAPI_MakeEvolved", "Describes functions to build evolved shapes. An evolved shape is built from a planar spine (face or wire) and a profile (wire). The evolved shape is the unlooped sweep (pipe) of the profile along the spine. Self-intersections are removed. A MakeEvolved object provides a framework for: - defining the construction of an evolved shape, - implementing the construction algorithm, and - consulting the result. Computes an Evolved by 1 - sweeping a profile along a spine. 2 - removing the self-intersections.");

// Constructors
cls_BRepOffsetAPI_MakeEvolved.def(py::init<>());
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &>(), py::arg("theSpine"), py::arg("theProfile"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const GeomAbs_JoinType>(), py::arg("theSpine"), py::arg("theProfile"), py::arg("theJoinType"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("theSpine"), py::arg("theProfile"), py::arg("theJoinType"), py::arg("theIsAxeProf"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean>(), py::arg("theSpine"), py::arg("theProfile"), py::arg("theJoinType"), py::arg("theIsAxeProf"), py::arg("theIsSolid"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("theSpine"), py::arg("theProfile"), py::arg("theJoinType"), py::arg("theIsAxeProf"), py::arg("theIsSolid"), py::arg("theIsProfOnSpine"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("theSpine"), py::arg("theProfile"), py::arg("theJoinType"), py::arg("theIsAxeProf"), py::arg("theIsSolid"), py::arg("theIsProfOnSpine"), py::arg("theTol"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Boolean>(), py::arg("theSpine"), py::arg("theProfile"), py::arg("theJoinType"), py::arg("theIsAxeProf"), py::arg("theIsSolid"), py::arg("theIsProfOnSpine"), py::arg("theTol"), py::arg("theIsVolume"));
cls_BRepOffsetAPI_MakeEvolved.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("theSpine"), py::arg("theProfile"), py::arg("theJoinType"), py::arg("theIsAxeProf"), py::arg("theIsSolid"), py::arg("theIsProfOnSpine"), py::arg("theTol"), py::arg("theIsVolume"), py::arg("theRunInParallel"));

// Methods
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeEvolved::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeEvolved::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeEvolved::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeEvolved::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeEvolved::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeEvolved.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeEvolved::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeEvolved.def("Evolved", (const BRepFill_Evolved & (BRepOffsetAPI_MakeEvolved::*)() const) &BRepOffsetAPI_MakeEvolved::Evolved, "None");
cls_BRepOffsetAPI_MakeEvolved.def("Build", (void (BRepOffsetAPI_MakeEvolved::*)()) &BRepOffsetAPI_MakeEvolved::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepOffsetAPI_MakeEvolved.def("GeneratedShapes", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeEvolved::*)(const TopoDS_Shape &, const TopoDS_Shape &) const) &BRepOffsetAPI_MakeEvolved::GeneratedShapes, "Returns the shapes created from a subshape <SpineShape> of the spine and a subshape <ProfShape> on the profile.", py::arg("SpineShape"), py::arg("ProfShape"));
cls_BRepOffsetAPI_MakeEvolved.def("Top", (const TopoDS_Shape & (BRepOffsetAPI_MakeEvolved::*)() const) &BRepOffsetAPI_MakeEvolved::Top, "Return the face Top if <Solid> is True in the constructor.");
cls_BRepOffsetAPI_MakeEvolved.def("Bottom", (const TopoDS_Shape & (BRepOffsetAPI_MakeEvolved::*)() const) &BRepOffsetAPI_MakeEvolved::Bottom, "Return the face Bottom if <Solid> is True in the constructor.");

// CLASS: BREPOFFSETAPI_MAKEFILLING
py::class_<BRepOffsetAPI_MakeFilling, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MakeFilling(mod, "BRepOffsetAPI_MakeFilling", "N-Side Filling This algorithm avoids to build a face from: * a set of edges defining the bounds of the face and some constraints the surface of the face has to satisfy * a set of edges and points defining some constraints the support surface has to satisfy * an initial surface to deform for satisfying the constraints * a set of parameters to control the constraints.");

// Constructors
cls_BRepOffsetAPI_MakeFilling.def(py::init<>());
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer>(), py::arg("Degree"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("MaxDeg"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("MaxDeg"), py::arg("MaxSegments"));

// Methods
// cls_BRepOffsetAPI_MakeFilling.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeFilling::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeFilling::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeFilling::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeFilling::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeFilling::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeFilling::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", [](BRepOffsetAPI_MakeFilling &self) -> void { return self.SetConstrParam(); });
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Real a0) -> void { return self.SetConstrParam(a0); });
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetConstrParam(a0, a1); });
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetConstrParam(a0, a1, a2); });
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", (void (BRepOffsetAPI_MakeFilling::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepOffsetAPI_MakeFilling::SetConstrParam, "Sets the values of Tolerances used to control the constraint. Tol2d: Tol3d: it is the maximum distance allowed between the support surface and the constraints TolAng: it is the maximum angle allowed between the normal of the surface and the constraints TolCurv: it is the maximum difference of curvature allowed between the surface and the constraint", py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", [](BRepOffsetAPI_MakeFilling &self) -> void { return self.SetResolParam(); });
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Integer a0) -> void { return self.SetResolParam(a0); });
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.SetResolParam(a0, a1); });
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.SetResolParam(a0, a1, a2); });
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", (void (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &BRepOffsetAPI_MakeFilling::SetResolParam, "Sets the parameters used for resolution. The default values of these parameters have been chosen for a good ratio quality/performance. Degree: it is the order of energy criterion to minimize for computing the deformation of the surface. The default value is 3 The recommanded value is i+2 where i is the maximum order of the constraints. NbPtsOnCur: it is the average number of points for discretisation of the edges. NbIter: it is the maximum number of iterations of the process. For each iteration the number of discretisation points is increased. Anisotropie:", py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"));
cls_BRepOffsetAPI_MakeFilling.def("SetApproxParam", [](BRepOffsetAPI_MakeFilling &self) -> void { return self.SetApproxParam(); });
cls_BRepOffsetAPI_MakeFilling.def("SetApproxParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Integer a0) -> void { return self.SetApproxParam(a0); });
cls_BRepOffsetAPI_MakeFilling.def("SetApproxParam", (void (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer, const Standard_Integer)) &BRepOffsetAPI_MakeFilling::SetApproxParam, "Sets the parameters used to approximate the filling surface. These include: - MaxDeg - the highest degree which the polynomial defining the filling surface can have - MaxSegments - the greatest number of segments which the filling surface can have.", py::arg("MaxDeg"), py::arg("MaxSegments"));
cls_BRepOffsetAPI_MakeFilling.def("LoadInitSurface", (void (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Face &)) &BRepOffsetAPI_MakeFilling::LoadInitSurface, "Loads the initial surface Surf to begin the construction of the surface. This optional function is useful if the surface resulting from construction for the algorithm is likely to be complex. The support surface of the face under construction is computed by a deformation of Surf which satisfies the given constraints. The set of bounding edges defines the wire of the face. If no initial surface is given, the algorithm computes it automatically. If the set of edges is not connected (Free constraint), missing edges are automatically computed. Important: the initial surface must have orthogonal local coordinates, i.e. partial derivatives dS/du and dS/dv must be orthogonal at each point of surface. If this condition breaks, distortions of resulting surface are possible.", py::arg("Surf"));
cls_BRepOffsetAPI_MakeFilling.def("Add", [](BRepOffsetAPI_MakeFilling &self, const TopoDS_Edge & a0, const GeomAbs_Shape a1) -> Standard_Integer { return self.Add(a0, a1); });
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Edge &, const GeomAbs_Shape, const Standard_Boolean)) &BRepOffsetAPI_MakeFilling::Add, "Adds a new constraint which also defines an edge of the wire of the face Order: Order of the constraint: GeomAbs_C0 : the surface has to pass by 3D representation of the edge GeomAbs_G1 : the surface has to pass by 3D representation of the edge and to respect tangency with the first face of the edge GeomAbs_G2 : the surface has to pass by 3D representation of the edge and to respect tangency and curvature with the first face of the edge. Raises ConstructionError if the edge has no representation on a face and Order is GeomAbs_G1 or GeomAbs_G2.", py::arg("Constr"), py::arg("Order"), py::arg("IsBound"));
cls_BRepOffsetAPI_MakeFilling.def("Add", [](BRepOffsetAPI_MakeFilling &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const GeomAbs_Shape a2) -> Standard_Integer { return self.Add(a0, a1, a2); });
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Edge &, const TopoDS_Face &, const GeomAbs_Shape, const Standard_Boolean)) &BRepOffsetAPI_MakeFilling::Add, "Adds a new constraint which also defines an edge of the wire of the face Order: Order of the constraint: GeomAbs_C0 : the surface has to pass by 3D representation of the edge GeomAbs_G1 : the surface has to pass by 3D representation of the edge and to respect tangency with the given face GeomAbs_G2 : the surface has to pass by 3D representation of the edge and to respect tangency and curvature with the given face. Raises ConstructionError if the edge has no 2d representation on the given face", py::arg("Constr"), py::arg("Support"), py::arg("Order"), py::arg("IsBound"));
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Face &, const GeomAbs_Shape)) &BRepOffsetAPI_MakeFilling::Add, "Adds a free constraint on a face. The corresponding edge has to be automatically recomputed. It is always a bound.", py::arg("Support"), py::arg("Order"));
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const gp_Pnt &)) &BRepOffsetAPI_MakeFilling::Add, "Adds a punctual constraint.", py::arg("Point"));
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const Standard_Real, const Standard_Real, const TopoDS_Face &, const GeomAbs_Shape)) &BRepOffsetAPI_MakeFilling::Add, "Adds a punctual constraint.", py::arg("U"), py::arg("V"), py::arg("Support"), py::arg("Order"));
cls_BRepOffsetAPI_MakeFilling.def("Build", (void (BRepOffsetAPI_MakeFilling::*)()) &BRepOffsetAPI_MakeFilling::Build, "Builds the resulting faces");
cls_BRepOffsetAPI_MakeFilling.def("IsDone", (Standard_Boolean (BRepOffsetAPI_MakeFilling::*)() const) &BRepOffsetAPI_MakeFilling::IsDone, "Tests whether computation of the filling plate has been completed.");
cls_BRepOffsetAPI_MakeFilling.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeFilling::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_MakeFilling.def("G0Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)() const) &BRepOffsetAPI_MakeFilling::G0Error, "Returns the maximum distance between the result and the constraints. This is set at construction time.");
cls_BRepOffsetAPI_MakeFilling.def("G1Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)() const) &BRepOffsetAPI_MakeFilling::G1Error, "Returns the maximum angle between the result and the constraints. This is set at construction time.");
cls_BRepOffsetAPI_MakeFilling.def("G2Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)() const) &BRepOffsetAPI_MakeFilling::G2Error, "Returns the maximum angle between the result and the constraints. This is set at construction time.");
cls_BRepOffsetAPI_MakeFilling.def("G0Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer)) &BRepOffsetAPI_MakeFilling::G0Error, "Returns the maximum distance attained between the result and the constraint Index. This is set at construction time.", py::arg("Index"));
cls_BRepOffsetAPI_MakeFilling.def("G1Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer)) &BRepOffsetAPI_MakeFilling::G1Error, "Returns the maximum angle between the result and the constraints. This is set at construction time.", py::arg("Index"));
cls_BRepOffsetAPI_MakeFilling.def("G2Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer)) &BRepOffsetAPI_MakeFilling::G2Error, "Returns the greatest difference in curvature found between the result and the constraint Index.", py::arg("Index"));

// CLASS: BREPOFFSETAPI_MAKEOFFSET
py::class_<BRepOffsetAPI_MakeOffset, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MakeOffset(mod, "BRepOffsetAPI_MakeOffset", "Describes algorithms for offsetting wires from a set of wires contained in a planar face. A MakeOffset object provides a framework for: - defining the construction of an offset, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepOffsetAPI_MakeOffset.def(py::init<>());
cls_BRepOffsetAPI_MakeOffset.def(py::init<const TopoDS_Face &>(), py::arg("Spine"));
cls_BRepOffsetAPI_MakeOffset.def(py::init<const TopoDS_Face &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Join"));
cls_BRepOffsetAPI_MakeOffset.def(py::init<const TopoDS_Face &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Join"), py::arg("IsOpenResult"));
cls_BRepOffsetAPI_MakeOffset.def(py::init<const TopoDS_Wire &>(), py::arg("Spine"));
cls_BRepOffsetAPI_MakeOffset.def(py::init<const TopoDS_Wire &, const GeomAbs_JoinType>(), py::arg("Spine"), py::arg("Join"));
cls_BRepOffsetAPI_MakeOffset.def(py::init<const TopoDS_Wire &, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("Spine"), py::arg("Join"), py::arg("IsOpenResult"));

// Methods
// cls_BRepOffsetAPI_MakeOffset.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeOffset::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeOffset.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeOffset::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeOffset.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeOffset::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeOffset.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeOffset::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeOffset.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeOffset::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeOffset.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeOffset::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeOffset.def("Init", [](BRepOffsetAPI_MakeOffset &self, const TopoDS_Face & a0) -> void { return self.Init(a0); });
cls_BRepOffsetAPI_MakeOffset.def("Init", [](BRepOffsetAPI_MakeOffset &self, const TopoDS_Face & a0, const GeomAbs_JoinType a1) -> void { return self.Init(a0, a1); });
cls_BRepOffsetAPI_MakeOffset.def("Init", (void (BRepOffsetAPI_MakeOffset::*)(const TopoDS_Face &, const GeomAbs_JoinType, const Standard_Boolean)) &BRepOffsetAPI_MakeOffset::Init, "Initializes the algorithm to construct parallels to the spine Spine. Join defines the type of parallel generated by the salient vertices of the spine. The default type is GeomAbs_Arc where the vertices generate sections of a circle. If join type is GeomAbs_Intersection, the edges that intersect in a salient vertex generate the edges prolonged until intersection.", py::arg("Spine"), py::arg("Join"), py::arg("IsOpenResult"));
cls_BRepOffsetAPI_MakeOffset.def("Init", [](BRepOffsetAPI_MakeOffset &self) -> void { return self.Init(); });
cls_BRepOffsetAPI_MakeOffset.def("Init", [](BRepOffsetAPI_MakeOffset &self, const GeomAbs_JoinType a0) -> void { return self.Init(a0); });
cls_BRepOffsetAPI_MakeOffset.def("Init", (void (BRepOffsetAPI_MakeOffset::*)(const GeomAbs_JoinType, const Standard_Boolean)) &BRepOffsetAPI_MakeOffset::Init, "Initialize the evaluation of Offseting.", py::arg("Join"), py::arg("IsOpenResult"));
cls_BRepOffsetAPI_MakeOffset.def("AddWire", (void (BRepOffsetAPI_MakeOffset::*)(const TopoDS_Wire &)) &BRepOffsetAPI_MakeOffset::AddWire, "Initializes the algorithm to construct parallels to the wire Spine.", py::arg("Spine"));
cls_BRepOffsetAPI_MakeOffset.def("Perform", [](BRepOffsetAPI_MakeOffset &self, const Standard_Real a0) -> void { return self.Perform(a0); });
cls_BRepOffsetAPI_MakeOffset.def("Perform", (void (BRepOffsetAPI_MakeOffset::*)(const Standard_Real, const Standard_Real)) &BRepOffsetAPI_MakeOffset::Perform, "Computes a parallel to the spine at distance Offset and at an altitude Alt from the plane of the spine in relation to the normal to the spine. Exceptions: StdFail_NotDone if the offset is not built.", py::arg("Offset"), py::arg("Alt"));
cls_BRepOffsetAPI_MakeOffset.def("Build", (void (BRepOffsetAPI_MakeOffset::*)()) &BRepOffsetAPI_MakeOffset::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepOffsetAPI_MakeOffset.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeOffset::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeOffset::Generated, "returns a list of the created shapes from the shape <S>.", py::arg("S"));

// CLASS: BREPOFFSETAPI_MAKEOFFSETSHAPE
py::class_<BRepOffsetAPI_MakeOffsetShape, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MakeOffsetShape(mod, "BRepOffsetAPI_MakeOffsetShape", "Describes functions to build a shell out of a shape. The result is an unlooped shape parallel to the source shape. A MakeOffsetShape object provides a framework for: - defining the construction of a shell - implementing the construction algorithm - consulting the result.");

// Constructors
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<>());
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"));
cls_BRepOffsetAPI_MakeOffsetShape.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("RemoveIntEdges"));

// Methods
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeOffsetShape::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeOffsetShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeOffsetShape::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeOffsetShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeOffsetShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeOffsetShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeOffsetShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformBySimple", (void (BRepOffsetAPI_MakeOffsetShape::*)(const TopoDS_Shape &, const Standard_Real)) &BRepOffsetAPI_MakeOffsetShape::PerformBySimple, "Constructs offset shape for the given one using simple algorithm without intersections computation.", py::arg("theS"), py::arg("theOffsetValue"));
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.PerformByJoin(a0, a1, a2); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3) -> void { return self.PerformByJoin(a0, a1, a2, a3); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4) -> void { return self.PerformByJoin(a0, a1, a2, a3, a4); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.PerformByJoin(a0, a1, a2, a3, a4, a5); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", [](BRepOffsetAPI_MakeOffsetShape &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const BRepOffset_Mode a3, const Standard_Boolean a4, const Standard_Boolean a5, const GeomAbs_JoinType a6) -> void { return self.PerformByJoin(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepOffsetAPI_MakeOffsetShape.def("PerformByJoin", (void (BRepOffsetAPI_MakeOffsetShape::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean)) &BRepOffsetAPI_MakeOffsetShape::PerformByJoin, "Constructs a shape parallel to the shape S, where - S may be a face, a shell, a solid or a compound of these shape kinds; - Offset is the offset value. The offset shape is constructed: - outside S, if Offset is positive, - inside S, if Offset is negative; - Tol defines the coincidence tolerance criterion for generated shapes; - Mode defines the construction type of parallels applied to the free edges of shape S; currently, only one construction type is implemented, namely the one where the free edges do not generate parallels; this corresponds to the default value BRepOffset_Skin; - Intersection specifies how the algorithm must work in order to limit the parallels to two adjacent shapes: - if Intersection is false (default value), the intersection is calculated with the parallels to the two adjacent shapes, - if Intersection is true, the intersection is calculated by taking all generated parallels into account; this computation method is more general as it avoids some self-intersections generated in the offset shape from features of small dimensions on shape S, however this method has not been completely implemented and therefore is not recommended for use; - SelfInter tells the algorithm whether a computation to eliminate self-intersections must be applied to the resulting shape; however, as this functionality is not yet implemented, it is recommended to use the default value (false); - Join defines how to fill the holes that may appear between parallels to the two adjacent faces. It may take values GeomAbs_Arc or GeomAbs_Intersection: - if Join is equal to GeomAbs_Arc, then pipes are generated between two free edges of two adjacent parallels, and spheres are generated on 'images' of vertices; it is the default value, - if Join is equal to GeomAbs_Intersection, then the parallels to the two adjacent faces are enlarged and intersected, so that there are no free edges on parallels to faces. RemoveIntEdges flag defines whether to remove the INTERNAL edges from the result or not. Warnings 1. All the faces of the shape S should be based on the surfaces with continuity at least C1. 2. The offset value should be sufficiently small to avoid self-intersections in resulting shape. Otherwise these self-intersections may appear inside an offset face if its initial surface is not plane or sphere or cylinder, also some non-adjacent offset faces may intersect each other. Also, some offset surfaces may 'turn inside out'. 3. The algorithm may fail if the shape S contains vertices where more than 3 edges converge. 4. Since 3d-offset algorithm involves intersection of surfaces, it is under limitations of surface intersection algorithm. 5. A result cannot be generated if the underlying geometry of S is BSpline with continuity C0. Exceptions Geom_UndefinedDerivative if the underlying geometry of S is BSpline with continuity C0.", py::arg("S"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("RemoveIntEdges"));
cls_BRepOffsetAPI_MakeOffsetShape.def("MakeOffset", (const BRepOffset_MakeOffset & (BRepOffsetAPI_MakeOffsetShape::*)() const) &BRepOffsetAPI_MakeOffsetShape::MakeOffset, "Returns instance of the unrelying intersection / arc algorithm.");
cls_BRepOffsetAPI_MakeOffsetShape.def("Build", (void (BRepOffsetAPI_MakeOffsetShape::*)()) &BRepOffsetAPI_MakeOffsetShape::Build, "Does nothing.");
cls_BRepOffsetAPI_MakeOffsetShape.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeOffsetShape::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeOffsetShape::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_MakeOffsetShape.def("GeneratedEdge", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeOffsetShape::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeOffsetShape::GeneratedEdge, "Returns the list of edges generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_MakeOffsetShape.def("GetJoinType", (GeomAbs_JoinType (BRepOffsetAPI_MakeOffsetShape::*)() const) &BRepOffsetAPI_MakeOffsetShape::GetJoinType, "Returns offset join type.");

// CLASS: BREPOFFSETAPI_MAKEPIPE
py::class_<BRepOffsetAPI_MakePipe, BRepPrimAPI_MakeSweep> cls_BRepOffsetAPI_MakePipe(mod, "BRepOffsetAPI_MakePipe", "Describes functions to build pipes. A pipe is built a basis shape (called the profile) along a wire (called the spine) by sweeping. The profile must not contain solids. A MakePipe object provides a framework for: - defining the construction of a pipe, - implementing the construction algorithm, and - consulting the result. Warning The MakePipe class implements pipe constructions with G1 continuous spines only.");

// Constructors
cls_BRepOffsetAPI_MakePipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &>(), py::arg("Spine"), py::arg("Profile"));
cls_BRepOffsetAPI_MakePipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"));
cls_BRepOffsetAPI_MakePipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &, const GeomFill_Trihedron, const Standard_Boolean>(), py::arg("Spine"), py::arg("Profile"), py::arg("aMode"), py::arg("ForceApproxC1"));

// Methods
// cls_BRepOffsetAPI_MakePipe.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakePipe::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakePipe::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakePipe::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakePipe::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakePipe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipe.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakePipe::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakePipe.def("Pipe", (const BRepFill_Pipe & (BRepOffsetAPI_MakePipe::*)() const) &BRepOffsetAPI_MakePipe::Pipe, "None");
cls_BRepOffsetAPI_MakePipe.def("Build", (void (BRepOffsetAPI_MakePipe::*)()) &BRepOffsetAPI_MakePipe::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepOffsetAPI_MakePipe.def("FirstShape", (TopoDS_Shape (BRepOffsetAPI_MakePipe::*)()) &BRepOffsetAPI_MakePipe::FirstShape, "Returns the TopoDS Shape of the bottom of the prism.");
cls_BRepOffsetAPI_MakePipe.def("LastShape", (TopoDS_Shape (BRepOffsetAPI_MakePipe::*)()) &BRepOffsetAPI_MakePipe::LastShape, "Returns the TopoDS Shape of the top of the prism.");
cls_BRepOffsetAPI_MakePipe.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakePipe::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakePipe::Generated, "None", py::arg("S"));
cls_BRepOffsetAPI_MakePipe.def("Generated", (TopoDS_Shape (BRepOffsetAPI_MakePipe::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepOffsetAPI_MakePipe::Generated, "None", py::arg("SSpine"), py::arg("SProfile"));
cls_BRepOffsetAPI_MakePipe.def("ErrorOnSurface", (Standard_Real (BRepOffsetAPI_MakePipe::*)() const) &BRepOffsetAPI_MakePipe::ErrorOnSurface, "None");

// CLASS: BREPOFFSETAPI_MAKEPIPESHELL
py::class_<BRepOffsetAPI_MakePipeShell, BRepPrimAPI_MakeSweep> cls_BRepOffsetAPI_MakePipeShell(mod, "BRepOffsetAPI_MakePipeShell", "This class provides for a framework to construct a shell or a solid along a spine consisting in a wire. To produce a solid, the initial wire must be closed. Two approaches are used: - definition by section - by a section and a scaling law - by addition of successive intermediary sections - definition by sweep mode. - pseudo-Frenet - constant - binormal constant - normal defined by a surface support - normal defined by a guiding contour. The two global approaches can also be combined. You can also close the surface later in order to form a solid. Warning: some limitations exist -- Mode with auxilary spine is incompatible with hometetic laws -- Mode with auxilary spine and keep contact produce only CO surface.");

// Constructors
cls_BRepOffsetAPI_MakePipeShell.def(py::init<const TopoDS_Wire &>(), py::arg("Spine"));

// Methods
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakePipeShell::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakePipeShell::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakePipeShell::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakePipeShell::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakePipeShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakePipeShell.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakePipeShell::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", [](BRepOffsetAPI_MakePipeShell &self) -> void { return self.SetMode(); });
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets a Frenet or a CorrectedFrenet trihedron to perform the sweeping If IsFrenet is false, a corrected Frenet trihedron is used.", py::arg("IsFrenet"));
cls_BRepOffsetAPI_MakePipeShell.def("SetDiscreteMode", (void (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::SetDiscreteMode, "Sets a Discrete trihedron to perform the sweeping");
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (void (BRepOffsetAPI_MakePipeShell::*)(const gp_Ax2 &)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets a fixed trihedron to perform the sweeping all sections will be parallel.", py::arg("Axe"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (void (BRepOffsetAPI_MakePipeShell::*)(const gp_Dir &)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets a fixed BiNormal direction to perform the -- sweeping. Angular relations beetween the section(s) and <BiNormal> will be constant", py::arg("BiNormal"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (Standard_Boolean (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets support to the spine to define the BiNormal of the trihedron, like the normal to the surfaces. Warning: To be effective, Each edge of the <spine> must have an representaion on one face of<SpineSupport>", py::arg("SpineSupport"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Wire & a0, const Standard_Boolean a1) -> void { return self.SetMode(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("SetMode", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Wire &, const Standard_Boolean, const BRepFill_TypeOfContact)) &BRepOffsetAPI_MakePipeShell::SetMode, "Sets an auxiliary spine to define the Normal For each Point of the Spine P, an Point Q is evalued on <AuxiliarySpine> If <CurvilinearEquivalence> Q split <AuxiliarySpine> with the same length ratio than P split <Spline>. Else the plan define by P and the tangent to the <Spine> intersect <AuxiliarySpine> in Q. If <KeepContact> equals BRepFill_NoContact: The Normal is defined by the vector PQ. If <KeepContact> equals BRepFill_Contact: The Normal is defined to achieve that the sweeped section is in contact to the auxiliarySpine. The width of section is constant all along the path. In other words, the auxiliary spine lies on the swept surface, but not necessarily is a boundary of this surface. However, the auxiliary spine has to be close enough to the main spine to provide intersection with any section all along the path. If <KeepContact> equals BRepFill_ContactOnBorder: The auxiliary spine becomes a boundary of the swept surface and the width of section varies along the path. Give section to sweep. Possibilities are : - Give one or sevral section - Give one profile and an homotetic law. - Automatic compute of correspondance beetween spine, and section on the sweeped shape - correspondance beetween spine, and section on the sweeped shape defined by a vertex of the spine", py::arg("AuxiliarySpine"), py::arg("CurvilinearEquivalence"), py::arg("KeepContact"));
cls_BRepOffsetAPI_MakePipeShell.def("Add", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0) -> void { return self.Add(a0); });
cls_BRepOffsetAPI_MakePipeShell.def("Add", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Add(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("Add", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::Add, "Adds the section Profile to this framework. First and last sections may be punctual, so the shape Profile may be both wire and vertex. Correspondent point on spine is computed automatically. If WithContact is true, the section is translated to be in contact with the spine. If WithCorrection is true, the section is rotated to be orthogonal to the spine?s tangent in the correspondent point. This option has no sense if the section is punctual (Profile is of type TopoDS_Vertex).", py::arg("Profile"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepOffsetAPI_MakePipeShell.def("Add", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const TopoDS_Vertex & a1) -> void { return self.Add(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("Add", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const TopoDS_Vertex & a1, const Standard_Boolean a2) -> void { return self.Add(a0, a1, a2); });
cls_BRepOffsetAPI_MakePipeShell.def("Add", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::Add, "Adds the section Profile to this framework. Correspondent point on the spine is given by Location. Warning: To be effective, it is not recommended to combine methods Add and SetLaw.", py::arg("Profile"), py::arg("Location"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1) -> void { return self.SetLaw(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const Standard_Boolean a2) -> void { return self.SetLaw(a0, a1, a2); });
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &, const opencascade::handle<Law_Function> &, const Standard_Boolean, const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::SetLaw, "Sets the evolution law defined by the wire Profile with its position (Location, WithContact, WithCorrection are the same options as in methods Add) and a homotetic law defined by the function L. Warning: To be effective, it is not recommended to combine methods Add and SetLaw.", py::arg("Profile"), py::arg("L"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const TopoDS_Vertex & a2) -> void { return self.SetLaw(a0, a1, a2); });
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", [](BRepOffsetAPI_MakePipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const TopoDS_Vertex & a2, const Standard_Boolean a3) -> void { return self.SetLaw(a0, a1, a2, a3); });
cls_BRepOffsetAPI_MakePipeShell.def("SetLaw", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &, const opencascade::handle<Law_Function> &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::SetLaw, "Sets the evolution law defined by the wire Profile with its position (Location, WithContact, WithCorrection are the same options as in methods Add) and a homotetic law defined by the function L. Warning: To be effective, it is not recommended to combine methods Add and SetLaw.", py::arg("Profile"), py::arg("L"), py::arg("Location"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepOffsetAPI_MakePipeShell.def("Delete", (void (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakePipeShell::Delete, "Removes the section Profile from this framework.", py::arg("Profile"));
cls_BRepOffsetAPI_MakePipeShell.def("IsReady", (Standard_Boolean (BRepOffsetAPI_MakePipeShell::*)() const) &BRepOffsetAPI_MakePipeShell::IsReady, "Returns true if this tool object is ready to build the shape, i.e. has a definition for the wire section Profile.");
cls_BRepOffsetAPI_MakePipeShell.def("GetStatus", (BRepBuilderAPI_PipeError (BRepOffsetAPI_MakePipeShell::*)() const) &BRepOffsetAPI_MakePipeShell::GetStatus, "Get a status, when Simulate or Build failed. It can be BRepBuilderAPI_PipeDone, BRepBuilderAPI_PipeNotDone, BRepBuilderAPI_PlaneNotIntersectGuide, BRepBuilderAPI_ImpossibleContact.");
cls_BRepOffsetAPI_MakePipeShell.def("SetTolerance", [](BRepOffsetAPI_MakePipeShell &self) -> void { return self.SetTolerance(); });
cls_BRepOffsetAPI_MakePipeShell.def("SetTolerance", [](BRepOffsetAPI_MakePipeShell &self, const Standard_Real a0) -> void { return self.SetTolerance(a0); });
cls_BRepOffsetAPI_MakePipeShell.def("SetTolerance", [](BRepOffsetAPI_MakePipeShell &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); });
cls_BRepOffsetAPI_MakePipeShell.def("SetTolerance", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &BRepOffsetAPI_MakePipeShell::SetTolerance, "Sets the following tolerance values - 3D tolerance Tol3d - boundary tolerance BoundTol - angular tolerance TolAngular.", py::arg("Tol3d"), py::arg("BoundTol"), py::arg("TolAngular"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMaxDegree", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Integer)) &BRepOffsetAPI_MakePipeShell::SetMaxDegree, "Define the maximum V degree of resulting surface", py::arg("NewMaxDegree"));
cls_BRepOffsetAPI_MakePipeShell.def("SetMaxSegments", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Integer)) &BRepOffsetAPI_MakePipeShell::SetMaxSegments, "Define the maximum number of spans in V-direction on resulting surface", py::arg("NewMaxSegments"));
cls_BRepOffsetAPI_MakePipeShell.def("SetForceApproxC1", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Boolean)) &BRepOffsetAPI_MakePipeShell::SetForceApproxC1, "Set the flag that indicates attempt to approximate a C1-continuous surface if a swept surface proved to be C0.", py::arg("ForceApproxC1"));
cls_BRepOffsetAPI_MakePipeShell.def("SetTransitionMode", [](BRepOffsetAPI_MakePipeShell &self) -> void { return self.SetTransitionMode(); });
cls_BRepOffsetAPI_MakePipeShell.def("SetTransitionMode", (void (BRepOffsetAPI_MakePipeShell::*)(const BRepBuilderAPI_TransitionMode)) &BRepOffsetAPI_MakePipeShell::SetTransitionMode, "Sets the transition mode to manage discontinuities on the swept shape caused by fractures on the spine. The transition mode can be BRepBuilderAPI_Transformed (default value), BRepBuilderAPI_RightCorner, BRepBuilderAPI_RoundCorner: - RepBuilderAPI_Transformed: discontinuities are treated by modification of the sweeping mode. The pipe is 'transformed' at the fractures of the spine. This mode assumes building a self-intersected shell. - BRepBuilderAPI_RightCorner: discontinuities are treated like right corner. Two pieces of the pipe corresponding to two adjacent segments of the spine are extended and intersected at a fracture of the spine. - BRepBuilderAPI_RoundCorner: discontinuities are treated like round corner. The corner is treated as rotation of the profile around an axis which passes through the point of the spine's fracture. This axis is based on cross product of directions tangent to the adjacent segments of the spine at their common point. Warnings The mode BRepBuilderAPI_RightCorner provides a valid result if intersection of two pieces of the pipe (corresponding to two adjacent segments of the spine) in the neighborhood of the spine?s fracture is connected and planar. This condition can be violated if the spine is non-linear in some neighborhood of the fracture or if the profile was set with a scaling law. The last mode, BRepBuilderAPI_RoundCorner, will assuredly provide a good result only if a profile was set with option WithCorrection = True, i.e. it is strictly orthogonal to the spine.", py::arg("Mode"));
cls_BRepOffsetAPI_MakePipeShell.def("Simulate", (void (BRepOffsetAPI_MakePipeShell::*)(const Standard_Integer, TopTools_ListOfShape &)) &BRepOffsetAPI_MakePipeShell::Simulate, "Simulates the resulting shape by calculating its cross-sections. The spine is devided by this cross-sections into (NumberOfSection - 1) equal parts, the number of cross-sections is NumberOfSection. The cross-sections are wires and they are returned in the list Result. This gives a rapid preview of the resulting shape, which will be obtained using the settings you have provided. Raises NotDone if <me> it is not Ready", py::arg("NumberOfSection"), py::arg("Result"));
cls_BRepOffsetAPI_MakePipeShell.def("Build", (void (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepOffsetAPI_MakePipeShell.def("MakeSolid", (Standard_Boolean (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::MakeSolid, "Transforms the sweeping Shell in Solid. If a propfile is not closed returns False");
cls_BRepOffsetAPI_MakePipeShell.def("FirstShape", (TopoDS_Shape (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::FirstShape, "Returns the TopoDS Shape of the bottom of the sweep.");
cls_BRepOffsetAPI_MakePipeShell.def("LastShape", (TopoDS_Shape (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::LastShape, "Returns the TopoDS Shape of the top of the sweep.");
cls_BRepOffsetAPI_MakePipeShell.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakePipeShell::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakePipeShell::Generated, "Returns a list of new shapes generated from the shape S by the shell-generating algorithm. This function is redefined from BRepOffsetAPI_MakeShape::Generated. S can be an edge or a vertex of a given Profile (see methods Add).", py::arg("S"));
cls_BRepOffsetAPI_MakePipeShell.def("ErrorOnSurface", (Standard_Real (BRepOffsetAPI_MakePipeShell::*)() const) &BRepOffsetAPI_MakePipeShell::ErrorOnSurface, "None");
cls_BRepOffsetAPI_MakePipeShell.def("Profiles", (void (BRepOffsetAPI_MakePipeShell::*)(TopTools_ListOfShape &)) &BRepOffsetAPI_MakePipeShell::Profiles, "Returns the list of original profiles", py::arg("theProfiles"));
cls_BRepOffsetAPI_MakePipeShell.def("Spine", (const TopoDS_Wire & (BRepOffsetAPI_MakePipeShell::*)()) &BRepOffsetAPI_MakePipeShell::Spine, "Returns the spine");

// CLASS: BREPOFFSETAPI_MAKETHICKSOLID
py::class_<BRepOffsetAPI_MakeThickSolid, BRepOffsetAPI_MakeOffsetShape> cls_BRepOffsetAPI_MakeThickSolid(mod, "BRepOffsetAPI_MakeThickSolid", "Describes functions to build hollowed solids. A hollowed solid is built from an initial solid and a set of faces on this solid, which are to be removed. The remaining faces of the solid become the walls of the hollowed solid, their thickness defined at the time of construction. the solid is built from an initial solid <S> and a set of faces {Fi} from <S>, builds a solid composed by two shells closed by the {Fi}. First shell <SS> is composed by all the faces of <S> expected {Fi}. Second shell is the offset shell of <SS>. A MakeThickSolid object provides a framework for: - defining the cross-section of a hollowed solid, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<>());
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"));
cls_BRepOffsetAPI_MakeThickSolid.def(py::init<const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("RemoveIntEdges"));

// Methods
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeThickSolid::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeThickSolid::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeThickSolid::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeThickSolid::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeThickSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeThickSolid.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeThickSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidBySimple", (void (BRepOffsetAPI_MakeThickSolid::*)(const TopoDS_Shape &, const Standard_Real)) &BRepOffsetAPI_MakeThickSolid::MakeThickSolidBySimple, "Constructs solid using simple algorithm. According to its nature it is not possible to set list of the closing faces. This algorithm does not support faces removing. It is caused by fact that intersections are not computed during offset creation. Non-closed shell or face is expected as input.", py::arg("theS"), py::arg("theOffsetValue"));
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3, const BRepOffset_Mode a4) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3, a4); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3, const BRepOffset_Mode a4, const Standard_Boolean a5) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3, a4, a5); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3, const BRepOffset_Mode a4, const Standard_Boolean a5, const Standard_Boolean a6) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", [](BRepOffsetAPI_MakeThickSolid &self, const TopoDS_Shape & a0, const TopTools_ListOfShape & a1, const Standard_Real a2, const Standard_Real a3, const BRepOffset_Mode a4, const Standard_Boolean a5, const Standard_Boolean a6, const GeomAbs_JoinType a7) -> void { return self.MakeThickSolidByJoin(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_BRepOffsetAPI_MakeThickSolid.def("MakeThickSolidByJoin", (void (BRepOffsetAPI_MakeThickSolid::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const Standard_Real, const Standard_Real, const BRepOffset_Mode, const Standard_Boolean, const Standard_Boolean, const GeomAbs_JoinType, const Standard_Boolean)) &BRepOffsetAPI_MakeThickSolid::MakeThickSolidByJoin, "Constructs a hollowed solid from the solid S by removing the set of faces ClosingFaces from S, where: Offset defines the thickness of the walls. Its sign indicates which side of the surface of the solid the hollowed shape is built on; - Tol defines the tolerance criterion for coincidence in generated shapes; - Mode defines the construction type of parallels applied to free edges of shape S. Currently, only one construction type is implemented, namely the one where the free edges do not generate parallels; this corresponds to the default value BRepOffset_Skin; Intersection specifies how the algorithm must work in order to limit the parallels to two adjacent shapes: - if Intersection is false (default value), the intersection is calculated with the parallels to the two adjacent shapes, - if Intersection is true, the intersection is calculated by taking account of all parallels generated; this computation method is more general as it avoids self-intersections generated in the offset shape from features of small dimensions on shape S, however this method has not been completely implemented and therefore is not recommended for use; - SelfInter tells the algorithm whether a computation to eliminate self-intersections needs to be applied to the resulting shape. However, as this functionality is not yet implemented, you should use the default value (false); - Join defines how to fill the holes that may appear between parallels to the two adjacent faces. It may take values GeomAbs_Arc or GeomAbs_Intersection: - if Join is equal to GeomAbs_Arc, then pipes are generated between two free edges of two adjacent parallels, and spheres are generated on 'images' of vertices; it is the default value, - if Join is equal to GeomAbs_Intersection, then the parallels to the two adjacent faces are enlarged and intersected, so that there are no free edges on parallels to faces. RemoveIntEdges flag defines whether to remove the INTERNAL edges from the result or not. Warnings Since the algorithm of MakeThickSolid is based on MakeOffsetShape algorithm, the warnings are the same as for MakeOffsetShape.", py::arg("S"), py::arg("ClosingFaces"), py::arg("Offset"), py::arg("Tol"), py::arg("Mode"), py::arg("Intersection"), py::arg("SelfInter"), py::arg("Join"), py::arg("RemoveIntEdges"));
cls_BRepOffsetAPI_MakeThickSolid.def("Build", (void (BRepOffsetAPI_MakeThickSolid::*)()) &BRepOffsetAPI_MakeThickSolid::Build, "None");
cls_BRepOffsetAPI_MakeThickSolid.def("Modified", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeThickSolid::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeThickSolid::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));

// TYPEDEF: BREPOFFSETAPI_SEQUENCEOFSEQUENCEOFSHAPE
bind_NCollection_Sequence<NCollection_Sequence<TopoDS_Shape> >(mod, "BRepOffsetAPI_SequenceOfSequenceOfShape", py::module_local(false));

// CLASS: BREPOFFSETAPI_MIDDLEPATH
py::class_<BRepOffsetAPI_MiddlePath, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MiddlePath(mod, "BRepOffsetAPI_MiddlePath", "Describes functions to build a middle path of a pipe-like shape");

// Constructors
cls_BRepOffsetAPI_MiddlePath.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("aShape"), py::arg("StartShape"), py::arg("EndShape"));

// Methods
// cls_BRepOffsetAPI_MiddlePath.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MiddlePath::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MiddlePath::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MiddlePath::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MiddlePath::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MiddlePath::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MiddlePath.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MiddlePath::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MiddlePath.def("Build", (void (BRepOffsetAPI_MiddlePath::*)()) &BRepOffsetAPI_MiddlePath::Build, "None");

// CLASS: BREPOFFSETAPI_NORMALPROJECTION
py::class_<BRepOffsetAPI_NormalProjection, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_NormalProjection(mod, "BRepOffsetAPI_NormalProjection", "A framework to define projection onto a shape according to the normal from each point to be projected. The target shape is a face, and the source shape is an edge or a wire.");

// Constructors
cls_BRepOffsetAPI_NormalProjection.def(py::init<>());
cls_BRepOffsetAPI_NormalProjection.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Methods
// cls_BRepOffsetAPI_NormalProjection.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_NormalProjection::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_NormalProjection::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_NormalProjection::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_NormalProjection::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_NormalProjection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_NormalProjection::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_NormalProjection.def("Init", (void (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Shape &)) &BRepOffsetAPI_NormalProjection::Init, "Initializes the empty constructor framework with the shape S.", py::arg("S"));
cls_BRepOffsetAPI_NormalProjection.def("Add", (void (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Shape &)) &BRepOffsetAPI_NormalProjection::Add, "Adds the shape ToProj to the framework for calculation of the projection by Compute3d. ToProj is an edge or a wire and will be projected onto the basis shape. Exceptions Standard_ConstructionError if ToProj is not added.", py::arg("ToProj"));
cls_BRepOffsetAPI_NormalProjection.def("SetParams", (void (BRepOffsetAPI_NormalProjection::*)(const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepOffsetAPI_NormalProjection::SetParams, "Sets the parameters used for computation Tol3 is the requiered tolerance between the 3d projected curve and its 2d representation InternalContinuity is the order of constraints used for approximation MaxDeg and MaxSeg are the maximum degree and the maximum number of segment for BSpline resulting of an approximation.", py::arg("Tol3D"), py::arg("Tol2D"), py::arg("InternalContinuity"), py::arg("MaxDegree"), py::arg("MaxSeg"));
cls_BRepOffsetAPI_NormalProjection.def("SetMaxDistance", (void (BRepOffsetAPI_NormalProjection::*)(const Standard_Real)) &BRepOffsetAPI_NormalProjection::SetMaxDistance, "Sets the maximum distance between target shape and shape to project. If this condition is not satisfied then corresponding part of solution is discarded. if MaxDist < 0 then this method does not affect the algorithm", py::arg("MaxDist"));
cls_BRepOffsetAPI_NormalProjection.def("SetLimit", [](BRepOffsetAPI_NormalProjection &self) -> void { return self.SetLimit(); });
cls_BRepOffsetAPI_NormalProjection.def("SetLimit", (void (BRepOffsetAPI_NormalProjection::*)(const Standard_Boolean)) &BRepOffsetAPI_NormalProjection::SetLimit, "Manage limitation of projected edges.", py::arg("FaceBoundaries"));
cls_BRepOffsetAPI_NormalProjection.def("Compute3d", [](BRepOffsetAPI_NormalProjection &self) -> void { return self.Compute3d(); });
cls_BRepOffsetAPI_NormalProjection.def("Compute3d", (void (BRepOffsetAPI_NormalProjection::*)(const Standard_Boolean)) &BRepOffsetAPI_NormalProjection::Compute3d, "Returns true if a 3D curve is computed. If not, false is returned and an initial 3D curve is kept to build the resulting edges.", py::arg("With3d"));
cls_BRepOffsetAPI_NormalProjection.def("Build", (void (BRepOffsetAPI_NormalProjection::*)()) &BRepOffsetAPI_NormalProjection::Build, "Builds the result of the projection as a compound of wires. Tries to build oriented wires.");
cls_BRepOffsetAPI_NormalProjection.def("IsDone", (Standard_Boolean (BRepOffsetAPI_NormalProjection::*)() const) &BRepOffsetAPI_NormalProjection::IsDone, "Returns true if the object was correctly built by the shape construction algorithm. If at the construction time of the shape, the algorithm cannot be completed, or the original data is corrupted, IsDone returns false and therefore protects the use of functions to access the result of the construction (typically the Shape function).");
cls_BRepOffsetAPI_NormalProjection.def("Projection", (const TopoDS_Shape & (BRepOffsetAPI_NormalProjection::*)() const) &BRepOffsetAPI_NormalProjection::Projection, "Performs the projection. The construction of the result is performed by Build. Exceptions StdFail_NotDone if the projection was not performed.");
cls_BRepOffsetAPI_NormalProjection.def("Couple", (const TopoDS_Shape & (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Edge &) const) &BRepOffsetAPI_NormalProjection::Couple, "Returns the initial face corresponding to the projected edge E. Exceptions StdFail_NotDone if no face was found. Standard_NoSuchObject if if a face corresponding to E has already been found.", py::arg("E"));
cls_BRepOffsetAPI_NormalProjection.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Shape &)) &BRepOffsetAPI_NormalProjection::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_NormalProjection.def("Ancestor", (const TopoDS_Shape & (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Edge &) const) &BRepOffsetAPI_NormalProjection::Ancestor, "Returns the initial edge corresponding to the edge E resulting from the computation of the projection. Exceptions StdFail_NotDone if no edge was found. Standard_NoSuchObject if an edge corresponding to E has already been found.", py::arg("E"));
cls_BRepOffsetAPI_NormalProjection.def("BuildWire", (Standard_Boolean (BRepOffsetAPI_NormalProjection::*)(TopTools_ListOfShape &) const) &BRepOffsetAPI_NormalProjection::BuildWire, "build the result as a list of wire if possible in -- a first returns a wire only if there is only a wire.", py::arg("Liste"));

// TYPEDEF: BREPOFFSETAPI_SEQUENCEOFSEQUENCEOFREAL
bind_NCollection_Sequence<NCollection_Sequence<double> >(mod, "BRepOffsetAPI_SequenceOfSequenceOfReal", py::module_local(false));

// TYPEDEF: BREPOFFSETAPI_SEWING
py::class_<BRepBuilderAPI_Sewing, opencascade::handle<BRepBuilderAPI_Sewing>, Standard_Transient> cls_BRepOffsetAPI_Sewing(mod, "BRepOffsetAPI_Sewing", "Provides methods to", py::module_local());

// Constructors
cls_BRepOffsetAPI_Sewing.def(py::init<>());
cls_BRepOffsetAPI_Sewing.def(py::init<const Standard_Real>(), py::arg("tolerance"));
cls_BRepOffsetAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"));
cls_BRepOffsetAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"), py::arg("option2"));
cls_BRepOffsetAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"), py::arg("option2"), py::arg("option3"));
cls_BRepOffsetAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"), py::arg("option2"), py::arg("option3"), py::arg("option4"));

// Methods
cls_BRepOffsetAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self) -> void { return self.Init(); });
cls_BRepOffsetAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0) -> void { return self.Init(a0); });
cls_BRepOffsetAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0, const Standard_Boolean a1) -> void { return self.Init(a0, a1); });
cls_BRepOffsetAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0, const Standard_Boolean a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepOffsetAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0, const Standard_Boolean a1, const Standard_Boolean a2, const Standard_Boolean a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_BRepOffsetAPI_Sewing.def("Init", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &BRepBuilderAPI_Sewing::Init, "initialize the parameters if necessary", py::arg("tolerance"), py::arg("option1"), py::arg("option2"), py::arg("option3"), py::arg("option4"));
cls_BRepOffsetAPI_Sewing.def("Load", (void (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Sewing::Load, "Loades the context shape.", py::arg("shape"));
cls_BRepOffsetAPI_Sewing.def("Add", (void (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Sewing::Add, "Defines the shapes to be sewed or controlled", py::arg("shape"));
cls_BRepOffsetAPI_Sewing.def("Perform", [](BRepBuilderAPI_Sewing &self) -> void { return self.Perform(); });
cls_BRepOffsetAPI_Sewing.def("Perform", (void (BRepBuilderAPI_Sewing::*)(const opencascade::handle<Message_ProgressIndicator> &)) &BRepBuilderAPI_Sewing::Perform, "Computing thePI - progress indicator of algorithm", py::arg("thePI"));
cls_BRepOffsetAPI_Sewing.def("SewedShape", (const TopoDS_Shape & (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::SewedShape, "Gives the sewed shape a null shape if nothing constructed may be a face, a shell, a solid or a compound");
cls_BRepOffsetAPI_Sewing.def("SetContext", (void (BRepBuilderAPI_Sewing::*)(const opencascade::handle<BRepTools_ReShape> &)) &BRepBuilderAPI_Sewing::SetContext, "set context", py::arg("theContext"));
cls_BRepOffsetAPI_Sewing.def("GetContext", (const opencascade::handle<BRepTools_ReShape> & (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::GetContext, "return context");
cls_BRepOffsetAPI_Sewing.def("NbFreeEdges", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbFreeEdges, "Gives the number of free edges (edge shared by one face)");
cls_BRepOffsetAPI_Sewing.def("FreeEdge", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::FreeEdge, "Gives each free edge", py::arg("index"));
cls_BRepOffsetAPI_Sewing.def("NbMultipleEdges", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbMultipleEdges, "Gives the number of multiple edges (edge shared by more than two faces)");
cls_BRepOffsetAPI_Sewing.def("MultipleEdge", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::MultipleEdge, "Gives each multiple edge", py::arg("index"));
cls_BRepOffsetAPI_Sewing.def("NbContigousEdges", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbContigousEdges, "Gives the number of contigous edges (edge shared by two faces)");
cls_BRepOffsetAPI_Sewing.def("ContigousEdge", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::ContigousEdge, "Gives each contigous edge", py::arg("index"));
cls_BRepOffsetAPI_Sewing.def("ContigousEdgeCouple", (const TopTools_ListOfShape & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::ContigousEdgeCouple, "Gives the sections (edge) belonging to a contigous edge", py::arg("index"));
cls_BRepOffsetAPI_Sewing.def("IsSectionBound", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Edge &) const) &BRepBuilderAPI_Sewing::IsSectionBound, "Indicates if a section is bound (before use SectionToBoundary)", py::arg("section"));
cls_BRepOffsetAPI_Sewing.def("SectionToBoundary", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const TopoDS_Edge &) const) &BRepBuilderAPI_Sewing::SectionToBoundary, "Gives the original edge (free boundary) which becomes the the section. Remember that sections constitute common edges. This imformation is important for control because with original edge we can find the surface to which the section is attached.", py::arg("section"));
cls_BRepOffsetAPI_Sewing.def("NbDegeneratedShapes", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbDegeneratedShapes, "Gives the number of degenerated shapes");
cls_BRepOffsetAPI_Sewing.def("DegeneratedShape", (const TopoDS_Shape & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::DegeneratedShape, "Gives each degenerated shape", py::arg("index"));
cls_BRepOffsetAPI_Sewing.def("IsDegenerated", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::IsDegenerated, "Indicates if a input shape is degenerated", py::arg("shape"));
cls_BRepOffsetAPI_Sewing.def("IsModified", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::IsModified, "Indicates if a input shape has been modified", py::arg("shape"));
cls_BRepOffsetAPI_Sewing.def("Modified", (const TopoDS_Shape & (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::Modified, "Gives a modifieded shape", py::arg("shape"));
cls_BRepOffsetAPI_Sewing.def("IsModifiedSubShape", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::IsModifiedSubShape, "Indicates if a input subshape has been modified", py::arg("shape"));
cls_BRepOffsetAPI_Sewing.def("ModifiedSubShape", (TopoDS_Shape (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::ModifiedSubShape, "Gives a modifieded subshape", py::arg("shape"));
cls_BRepOffsetAPI_Sewing.def("Dump", (void (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::Dump, "print the informations");
cls_BRepOffsetAPI_Sewing.def("NbDeletedFaces", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbDeletedFaces, "Gives the number of deleted faces (faces smallest than tolerance)");
cls_BRepOffsetAPI_Sewing.def("DeletedFace", (const TopoDS_Face & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::DeletedFace, "Gives each deleted face", py::arg("index"));
cls_BRepOffsetAPI_Sewing.def("WhichFace", [](BRepBuilderAPI_Sewing &self, const TopoDS_Edge & a0) -> TopoDS_Face { return self.WhichFace(a0); });
cls_BRepOffsetAPI_Sewing.def("WhichFace", (TopoDS_Face (BRepBuilderAPI_Sewing::*)(const TopoDS_Edge &, const Standard_Integer) const) &BRepBuilderAPI_Sewing::WhichFace, "Gives a modified shape", py::arg("theEdg"), py::arg("index"));
cls_BRepOffsetAPI_Sewing.def("SameParameterMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::SameParameterMode, "Gets same parameter mode.");
cls_BRepOffsetAPI_Sewing.def("SetSameParameterMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetSameParameterMode, "Sets same parameter mode.", py::arg("SameParameterMode"));
cls_BRepOffsetAPI_Sewing.def("Tolerance", (Standard_Real (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::Tolerance, "Gives set tolerance.");
cls_BRepOffsetAPI_Sewing.def("SetTolerance", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real)) &BRepBuilderAPI_Sewing::SetTolerance, "Sets tolerance", py::arg("theToler"));
cls_BRepOffsetAPI_Sewing.def("MinTolerance", (Standard_Real (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::MinTolerance, "Gives set min tolerance.");
cls_BRepOffsetAPI_Sewing.def("SetMinTolerance", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real)) &BRepBuilderAPI_Sewing::SetMinTolerance, "Sets min tolerance", py::arg("theMinToler"));
cls_BRepOffsetAPI_Sewing.def("MaxTolerance", (Standard_Real (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::MaxTolerance, "Gives set max tolerance");
cls_BRepOffsetAPI_Sewing.def("SetMaxTolerance", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real)) &BRepBuilderAPI_Sewing::SetMaxTolerance, "Sets max tolerance.", py::arg("theMaxToler"));
cls_BRepOffsetAPI_Sewing.def("FaceMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::FaceMode, "Returns mode for sewing faces By default - true.");
cls_BRepOffsetAPI_Sewing.def("SetFaceMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetFaceMode, "Sets mode for sewing faces By default - true.", py::arg("theFaceMode"));
cls_BRepOffsetAPI_Sewing.def("FloatingEdgesMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::FloatingEdgesMode, "Returns mode for sewing floating edges By default - false.");
cls_BRepOffsetAPI_Sewing.def("SetFloatingEdgesMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetFloatingEdgesMode, "Sets mode for sewing floating edges By default - false. Returns mode for cutting floating edges By default - false. Sets mode for cutting floating edges By default - false.", py::arg("theFloatingEdgesMode"));
cls_BRepOffsetAPI_Sewing.def("LocalTolerancesMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::LocalTolerancesMode, "Returns mode for accounting of local tolerances of edges and vertices during of merging.");
cls_BRepOffsetAPI_Sewing.def("SetLocalTolerancesMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetLocalTolerancesMode, "Sets mode for accounting of local tolerances of edges and vertices during of merging in this case WorkTolerance = myTolerance + tolEdge1+ tolEdg2;", py::arg("theLocalTolerancesMode"));
cls_BRepOffsetAPI_Sewing.def("SetNonManifoldMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetNonManifoldMode, "Sets mode for non-manifold sewing.", py::arg("theNonManifoldMode"));
cls_BRepOffsetAPI_Sewing.def("NonManifoldMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NonManifoldMode, "Gets mode for non-manifold sewing.");
cls_BRepOffsetAPI_Sewing.def_static("get_type_name_", (const char * (*)()) &BRepBuilderAPI_Sewing::get_type_name, "None");
cls_BRepOffsetAPI_Sewing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBuilderAPI_Sewing::get_type_descriptor, "None");
cls_BRepOffsetAPI_Sewing.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::DynamicType, "None");

// CLASS: BREPOFFSETAPI_THRUSECTIONS
py::class_<BRepOffsetAPI_ThruSections, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_ThruSections(mod, "BRepOffsetAPI_ThruSections", "Describes functions to build a loft. This is a shell or a solid passing through a set of sections in a given sequence. Usually sections are wires, but the first and the last sections may be vertices (punctual sections).");

// Constructors
cls_BRepOffsetAPI_ThruSections.def(py::init<>());
cls_BRepOffsetAPI_ThruSections.def(py::init<const Standard_Boolean>(), py::arg("isSolid"));
cls_BRepOffsetAPI_ThruSections.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("isSolid"), py::arg("ruled"));
cls_BRepOffsetAPI_ThruSections.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Real>(), py::arg("isSolid"), py::arg("ruled"), py::arg("pres3d"));

// Methods
// cls_BRepOffsetAPI_ThruSections.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_ThruSections::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_ThruSections::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_ThruSections::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_ThruSections::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_ThruSections::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_ThruSections.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_ThruSections::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_ThruSections.def("Init", [](BRepOffsetAPI_ThruSections &self) -> void { return self.Init(); });
cls_BRepOffsetAPI_ThruSections.def("Init", [](BRepOffsetAPI_ThruSections &self, const Standard_Boolean a0) -> void { return self.Init(a0); });
cls_BRepOffsetAPI_ThruSections.def("Init", [](BRepOffsetAPI_ThruSections &self, const Standard_Boolean a0, const Standard_Boolean a1) -> void { return self.Init(a0, a1); });
cls_BRepOffsetAPI_ThruSections.def("Init", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Real)) &BRepOffsetAPI_ThruSections::Init, "Initializes this algorithm for building a shell or a solid passing through a set of sections, where: - isSolid is set to true if this construction algorithm is required to build a solid or to false if it is required to build a shell. false is the default value; - ruled is set to true if the faces generated between the edges of two consecutive wires are ruled surfaces or to false (the default value) if they are smoothed out by approximation, - pres3d defines the precision criterion used by the approximation algorithm; the default value is 1.0e-6. Use AddWire and AddVertex to define the successive sections of the shell or solid to be built.", py::arg("isSolid"), py::arg("ruled"), py::arg("pres3d"));
cls_BRepOffsetAPI_ThruSections.def("AddWire", (void (BRepOffsetAPI_ThruSections::*)(const TopoDS_Wire &)) &BRepOffsetAPI_ThruSections::AddWire, "Adds the wire wire to the set of sections through which the shell or solid is built. Use the Build function to construct the shape.", py::arg("wire"));
cls_BRepOffsetAPI_ThruSections.def("AddVertex", (void (BRepOffsetAPI_ThruSections::*)(const TopoDS_Vertex &)) &BRepOffsetAPI_ThruSections::AddVertex, "Adds the vertex Vertex (punctual section) to the set of sections through which the shell or solid is built. A vertex may be added to the set of sections only as first or last section. At least one wire must be added to the set of sections by the method AddWire. Use the Build function to construct the shape.", py::arg("aVertex"));
cls_BRepOffsetAPI_ThruSections.def("CheckCompatibility", [](BRepOffsetAPI_ThruSections &self) -> void { return self.CheckCompatibility(); });
cls_BRepOffsetAPI_ThruSections.def("CheckCompatibility", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Boolean)) &BRepOffsetAPI_ThruSections::CheckCompatibility, "Sets/unsets the option to compute origin and orientation on wires to avoid twisted results and update wires to have same number of edges.", py::arg("check"));
cls_BRepOffsetAPI_ThruSections.def("SetSmoothing", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Boolean)) &BRepOffsetAPI_ThruSections::SetSmoothing, "Define the approximation algorithm", py::arg("UseSmoothing"));
cls_BRepOffsetAPI_ThruSections.def("SetParType", (void (BRepOffsetAPI_ThruSections::*)(const Approx_ParametrizationType)) &BRepOffsetAPI_ThruSections::SetParType, "Define the type of parametrization used in the approximation", py::arg("ParType"));
cls_BRepOffsetAPI_ThruSections.def("SetContinuity", (void (BRepOffsetAPI_ThruSections::*)(const GeomAbs_Shape)) &BRepOffsetAPI_ThruSections::SetContinuity, "Define the Continuity used in the approximation", py::arg("C"));
cls_BRepOffsetAPI_ThruSections.def("SetCriteriumWeight", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &BRepOffsetAPI_ThruSections::SetCriteriumWeight, "define the Weights associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_BRepOffsetAPI_ThruSections.def("SetMaxDegree", (void (BRepOffsetAPI_ThruSections::*)(const Standard_Integer)) &BRepOffsetAPI_ThruSections::SetMaxDegree, "Define the maximal U degree of result surface", py::arg("MaxDeg"));
cls_BRepOffsetAPI_ThruSections.def("ParType", (Approx_ParametrizationType (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::ParType, "returns the type of parametrization used in the approximation");
cls_BRepOffsetAPI_ThruSections.def("Continuity", (GeomAbs_Shape (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::Continuity, "returns the Continuity used in the approximation");
cls_BRepOffsetAPI_ThruSections.def("MaxDegree", (Standard_Integer (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::MaxDegree, "returns the maximal U degree of result surface");
cls_BRepOffsetAPI_ThruSections.def("UseSmoothing", (Standard_Boolean (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::UseSmoothing, "Define the approximation algorithm");
cls_BRepOffsetAPI_ThruSections.def("CriteriumWeight", [](BRepOffsetAPI_ThruSections &self, Standard_Real & W1, Standard_Real & W2, Standard_Real & W3){ self.CriteriumWeight(W1, W2, W3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W1, W2, W3); }, "returns the Weights associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_BRepOffsetAPI_ThruSections.def("Build", (void (BRepOffsetAPI_ThruSections::*)()) &BRepOffsetAPI_ThruSections::Build, "None");
cls_BRepOffsetAPI_ThruSections.def("FirstShape", (const TopoDS_Shape & (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::FirstShape, "Returns the TopoDS Shape of the bottom of the loft if solid");
cls_BRepOffsetAPI_ThruSections.def("LastShape", (const TopoDS_Shape & (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::LastShape, "Returns the TopoDS Shape of the top of the loft if solid");
cls_BRepOffsetAPI_ThruSections.def("GeneratedFace", (TopoDS_Shape (BRepOffsetAPI_ThruSections::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_ThruSections::GeneratedFace, "if Ruled Returns the Face generated by each edge except the last wire if smoothed Returns the Face generated by each edge of the first wire", py::arg("Edge"));
cls_BRepOffsetAPI_ThruSections.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_ThruSections::*)(const TopoDS_Shape &)) &BRepOffsetAPI_ThruSections::Generated, "Returns a list of new shapes generated from the shape S by the shell-generating algorithm. This function is redefined from BRepBuilderAPI_MakeShape::Generated. S can be an edge or a vertex of a given Profile (see methods AddWire and AddVertex).", py::arg("S"));
cls_BRepOffsetAPI_ThruSections.def("Wires", (const TopTools_ListOfShape & (BRepOffsetAPI_ThruSections::*)() const) &BRepOffsetAPI_ThruSections::Wires, "Returns the list of original wires");


}
