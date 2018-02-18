/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <BRepFeat_StatusError.hxx>
#include <BOPAlgo_BOP.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Face.hxx>
#include <BOPCol_MapOfShape.hxx>
#include <BOPCol_ListOfShape.hxx>
#include <BRepFeat_Builder.hxx>
#include <gp_Ax1.hxx>
#include <BRepFeat_Status.hxx>
#include <BRepFeat_MakeCylindricalHole.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Compound.hxx>
#include <BRepFeat_SplitShape.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <BRepFeat_Form.hxx>
#include <gp_Pnt.hxx>
#include <Geom_Plane.hxx>
#include <BRepFeat_RibSlot.hxx>
#include <gp_Dir.hxx>
#include <BRepFeat_MakePrism.hxx>
#include <BRepFeat_MakeRevol.hxx>
#include <BRepFeat_MakePipe.hxx>
#include <LocOpe_Operation.hxx>
#include <BRepFeat_Gluer.hxx>
#include <BRepFeat_MakeDPrism.hxx>
#include <gp_Vec.hxx>
#include <BRepFeat_MakeLinearForm.hxx>
#include <BRepFeat_MakeRevolutionForm.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <BRepTopAdaptor_FClass2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <TopoDS_Solid.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_OStream.hxx>
#include <BRepFeat.hxx>
#include <BRepFeat_PerfSelection.hxx>

PYBIND11_MODULE(BRepFeat, mod) {

	// IMPORT
	py::module::import("OCCT.BOPAlgo");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.BOPCol");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.BRepBuilderAPI");
	py::module::import("OCCT.TColGeom");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.LocOpe");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.BRepTopAdaptor");
	py::module::import("OCCT.Geom2dAdaptor");
	py::module::import("OCCT.TopAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_StatusError.hxx
	py::enum_<BRepFeat_StatusError>(mod, "BRepFeat_StatusError", "Discribes the error.")
		.value("BRepFeat_OK", BRepFeat_StatusError::BRepFeat_OK)
		.value("BRepFeat_BadDirect", BRepFeat_StatusError::BRepFeat_BadDirect)
		.value("BRepFeat_BadIntersect", BRepFeat_StatusError::BRepFeat_BadIntersect)
		.value("BRepFeat_EmptyBaryCurve", BRepFeat_StatusError::BRepFeat_EmptyBaryCurve)
		.value("BRepFeat_EmptyCutResult", BRepFeat_StatusError::BRepFeat_EmptyCutResult)
		.value("BRepFeat_FalseSide", BRepFeat_StatusError::BRepFeat_FalseSide)
		.value("BRepFeat_IncDirection", BRepFeat_StatusError::BRepFeat_IncDirection)
		.value("BRepFeat_IncSlidFace", BRepFeat_StatusError::BRepFeat_IncSlidFace)
		.value("BRepFeat_IncParameter", BRepFeat_StatusError::BRepFeat_IncParameter)
		.value("BRepFeat_IncTypes", BRepFeat_StatusError::BRepFeat_IncTypes)
		.value("BRepFeat_IntervalOverlap", BRepFeat_StatusError::BRepFeat_IntervalOverlap)
		.value("BRepFeat_InvFirstShape", BRepFeat_StatusError::BRepFeat_InvFirstShape)
		.value("BRepFeat_InvOption", BRepFeat_StatusError::BRepFeat_InvOption)
		.value("BRepFeat_InvShape", BRepFeat_StatusError::BRepFeat_InvShape)
		.value("BRepFeat_LocOpeNotDone", BRepFeat_StatusError::BRepFeat_LocOpeNotDone)
		.value("BRepFeat_LocOpeInvNotDone", BRepFeat_StatusError::BRepFeat_LocOpeInvNotDone)
		.value("BRepFeat_NoExtFace", BRepFeat_StatusError::BRepFeat_NoExtFace)
		.value("BRepFeat_NoFaceProf", BRepFeat_StatusError::BRepFeat_NoFaceProf)
		.value("BRepFeat_NoGluer", BRepFeat_StatusError::BRepFeat_NoGluer)
		.value("BRepFeat_NoIntersectF", BRepFeat_StatusError::BRepFeat_NoIntersectF)
		.value("BRepFeat_NoIntersectU", BRepFeat_StatusError::BRepFeat_NoIntersectU)
		.value("BRepFeat_NoParts", BRepFeat_StatusError::BRepFeat_NoParts)
		.value("BRepFeat_NoProjPt", BRepFeat_StatusError::BRepFeat_NoProjPt)
		.value("BRepFeat_NotInitialized", BRepFeat_StatusError::BRepFeat_NotInitialized)
		.value("BRepFeat_NotYetImplemented", BRepFeat_StatusError::BRepFeat_NotYetImplemented)
		.value("BRepFeat_NullRealTool", BRepFeat_StatusError::BRepFeat_NullRealTool)
		.value("BRepFeat_NullToolF", BRepFeat_StatusError::BRepFeat_NullToolF)
		.value("BRepFeat_NullToolU", BRepFeat_StatusError::BRepFeat_NullToolU)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_PerfSelection.hxx
	py::enum_<BRepFeat_PerfSelection>(mod, "BRepFeat_PerfSelection", "To declare the type of selection semantics for local operation Perform methods - NoSelection - SelectionFU - selection of a face up to which a local operation will be performed - SelectionU - selection of a point up to which a local operation will be performed - SelectionSh - selection of a shape on which a local operation will be performed - SelectionShU - selection of a shape up to which a local operation will be performed.")
		.value("BRepFeat_NoSelection", BRepFeat_PerfSelection::BRepFeat_NoSelection)
		.value("BRepFeat_SelectionFU", BRepFeat_PerfSelection::BRepFeat_SelectionFU)
		.value("BRepFeat_SelectionU", BRepFeat_PerfSelection::BRepFeat_SelectionU)
		.value("BRepFeat_SelectionSh", BRepFeat_PerfSelection::BRepFeat_SelectionSh)
		.value("BRepFeat_SelectionShU", BRepFeat_PerfSelection::BRepFeat_SelectionShU)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_Status.hxx
	py::enum_<BRepFeat_Status>(mod, "BRepFeat_Status", "None")
		.value("BRepFeat_NoError", BRepFeat_Status::BRepFeat_NoError)
		.value("BRepFeat_InvalidPlacement", BRepFeat_Status::BRepFeat_InvalidPlacement)
		.value("BRepFeat_HoleTooLong", BRepFeat_Status::BRepFeat_HoleTooLong)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_Builder.hxx
	py::class_<BRepFeat_Builder, std::unique_ptr<BRepFeat_Builder, Deleter<BRepFeat_Builder>>, BOPAlgo_BOP> cls_BRepFeat_Builder(mod, "BRepFeat_Builder", "Provides a basic tool to implement features topological operations. The main goal of the algorithm is to perform the result of the operation according to the kept parts of the tool. Input data: a) DS; b) The kept parts of the tool; If the map of the kept parts of the tool is not filled boolean operation of the given type will be performed; c) Operation required. Steps: a) Fill myShapes, myRemoved maps; b) Rebuild edges and faces; c) Build images of the object; d) Build the result of the operation. Result: Result shape of the operation required.");
	cls_BRepFeat_Builder.def(py::init<>());
	cls_BRepFeat_Builder.def("Clear", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::Clear, "Clears internal fields and arguments.");
	cls_BRepFeat_Builder.def("Init", (void (BRepFeat_Builder::*)(const TopoDS_Shape &)) &BRepFeat_Builder::Init, "Initialyzes the object of local boolean operation.", py::arg("theShape"));
	cls_BRepFeat_Builder.def("Init", (void (BRepFeat_Builder::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_Builder::Init, "Initialyzes the arguments of local boolean operation.", py::arg("theShape"), py::arg("theTool"));
	cls_BRepFeat_Builder.def("SetOperation", (void (BRepFeat_Builder::*)(const Standard_Integer)) &BRepFeat_Builder::SetOperation, "Sets the operation of local boolean operation. If theFuse = 0 than the operation is CUT, otherwise FUSE.", py::arg("theFuse"));
	cls_BRepFeat_Builder.def("SetOperation", (void (BRepFeat_Builder::*)(const Standard_Integer, const Standard_Boolean)) &BRepFeat_Builder::SetOperation, "Sets the operation of local boolean operation. If theFlag = TRUE it means that no selection of parts of the tool is needed, t.e. no second part. In that case if theFuse = 0 than operation is COMMON, otherwise CUT21. If theFlag = FALSE SetOperation(theFuse) function is called.", py::arg("theFuse"), py::arg("theFlag"));
	cls_BRepFeat_Builder.def("PartsOfTool", (void (BRepFeat_Builder::*)(TopTools_ListOfShape &)) &BRepFeat_Builder::PartsOfTool, "Collects parts of the tool.", py::arg("theLT"));
	cls_BRepFeat_Builder.def("KeepParts", (void (BRepFeat_Builder::*)(const TopTools_ListOfShape &)) &BRepFeat_Builder::KeepParts, "Initialyzes parts of the tool for second step of algorithm. Collects shapes and all sub-shapes into myShapes map.", py::arg("theIm"));
	cls_BRepFeat_Builder.def("KeepPart", (void (BRepFeat_Builder::*)(const TopoDS_Shape &)) &BRepFeat_Builder::KeepPart, "Adds shape theS and all its sub-shapes into myShapes map.", py::arg("theS"));
	cls_BRepFeat_Builder.def("PerformResult", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::PerformResult, "Main function to build the result of the local operation required.");
	cls_BRepFeat_Builder.def("RebuildFaces", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::RebuildFaces, "Rebuilds faces in accordance with the kept parts of the tool.");
	cls_BRepFeat_Builder.def("RebuildEdge", (void (BRepFeat_Builder::*)(const TopoDS_Shape &, const TopoDS_Face &, const BOPCol_MapOfShape &, BOPCol_ListOfShape &)) &BRepFeat_Builder::RebuildEdge, "Rebuilds edges in accordance with the kept parts of the tool.", py::arg("theE"), py::arg("theF"), py::arg("theME"), py::arg("aLEIm"));
	cls_BRepFeat_Builder.def("CheckSolidImages", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::CheckSolidImages, "Collects the images of the object, that contains in the images of the tool.");
	cls_BRepFeat_Builder.def("FillRemoved", (void (BRepFeat_Builder::*)()) &BRepFeat_Builder::FillRemoved, "Collects the removed parts of the tool into myRemoved map.");
	cls_BRepFeat_Builder.def("FillRemoved", (void (BRepFeat_Builder::*)(const TopoDS_Shape &, BOPCol_MapOfShape &)) &BRepFeat_Builder::FillRemoved, "Adds the shape S and its sub-shapes into myRemoved map.", py::arg("theS"), py::arg("theM"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_MakeCylindricalHole.hxx
	py::class_<BRepFeat_MakeCylindricalHole, std::unique_ptr<BRepFeat_MakeCylindricalHole, Deleter<BRepFeat_MakeCylindricalHole>>, BRepFeat_Builder> cls_BRepFeat_MakeCylindricalHole(mod, "BRepFeat_MakeCylindricalHole", "Provides a tool to make cylindrical holes on a shape.");
	cls_BRepFeat_MakeCylindricalHole.def(py::init<>());
	cls_BRepFeat_MakeCylindricalHole.def("Init", (void (BRepFeat_MakeCylindricalHole::*)(const gp_Ax1 &)) &BRepFeat_MakeCylindricalHole::Init, "Sets the axis of the hole(s).", py::arg("Axis"));
	cls_BRepFeat_MakeCylindricalHole.def("Init", (void (BRepFeat_MakeCylindricalHole::*)(const TopoDS_Shape &, const gp_Ax1 &)) &BRepFeat_MakeCylindricalHole::Init, "Sets the shape and axis on which hole(s) will be performed.", py::arg("S"), py::arg("Axis"));
	cls_BRepFeat_MakeCylindricalHole.def("Perform", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real)) &BRepFeat_MakeCylindricalHole::Perform, "Performs every holes of radius <Radius>. This command has the same effect as a cut operation with an infinite cylinder defined by the given axis and <Radius>.", py::arg("Radius"));
	cls_BRepFeat_MakeCylindricalHole.def("Perform", [](BRepFeat_MakeCylindricalHole &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); }, py::arg("Radius"), py::arg("PFrom"), py::arg("PTo"));
	cls_BRepFeat_MakeCylindricalHole.def("Perform", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepFeat_MakeCylindricalHole::Perform, "Performs evry hole of radius <Radius> located between PFrom and PTo on the given axis. If <WithControl> is set to Standard_False no control are done on the resulting shape after the operation is performed.", py::arg("Radius"), py::arg("PFrom"), py::arg("PTo"), py::arg("WithControl"));
	cls_BRepFeat_MakeCylindricalHole.def("PerformThruNext", [](BRepFeat_MakeCylindricalHole &self, const Standard_Real a0) -> void { return self.PerformThruNext(a0); }, py::arg("Radius"));
	cls_BRepFeat_MakeCylindricalHole.def("PerformThruNext", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real, const Standard_Boolean)) &BRepFeat_MakeCylindricalHole::PerformThruNext, "Performs the first hole of radius <Radius>, in the direction of the defined axis. First hole signify first encountered after the origin of the axis. If <WithControl> is set to Standard_False no control are done on the resulting shape after the operation is performed.", py::arg("Radius"), py::arg("WithControl"));
	cls_BRepFeat_MakeCylindricalHole.def("PerformUntilEnd", [](BRepFeat_MakeCylindricalHole &self, const Standard_Real a0) -> void { return self.PerformUntilEnd(a0); }, py::arg("Radius"));
	cls_BRepFeat_MakeCylindricalHole.def("PerformUntilEnd", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real, const Standard_Boolean)) &BRepFeat_MakeCylindricalHole::PerformUntilEnd, "Performs evry holes of radius <Radius> located after the origin of the given axis. If <WithControl> is set to Standard_False no control are done on the resulting shape after the operation is performed.", py::arg("Radius"), py::arg("WithControl"));
	cls_BRepFeat_MakeCylindricalHole.def("PerformBlind", [](BRepFeat_MakeCylindricalHole &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.PerformBlind(a0, a1); }, py::arg("Radius"), py::arg("Length"));
	cls_BRepFeat_MakeCylindricalHole.def("PerformBlind", (void (BRepFeat_MakeCylindricalHole::*)(const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepFeat_MakeCylindricalHole::PerformBlind, "Performs a blind hole of radius <Radius> and length <Length>. The length is measured from the origin of the given axis. If <WithControl> is set to Standard_False no control are done after the operation is performed.", py::arg("Radius"), py::arg("Length"), py::arg("WithControl"));
	cls_BRepFeat_MakeCylindricalHole.def("Status", (BRepFeat_Status (BRepFeat_MakeCylindricalHole::*)() const ) &BRepFeat_MakeCylindricalHole::Status, "Returns the status after a hole is performed.");
	cls_BRepFeat_MakeCylindricalHole.def("Build", (void (BRepFeat_MakeCylindricalHole::*)()) &BRepFeat_MakeCylindricalHole::Build, "Builds the resulting shape (redefined from MakeShape). Invalidates the given parts of tools if any, and performs the result of the local operation.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_SplitShape.hxx
	py::class_<BRepFeat_SplitShape, std::unique_ptr<BRepFeat_SplitShape, Deleter<BRepFeat_SplitShape>>, BRepBuilderAPI_MakeShape> cls_BRepFeat_SplitShape(mod, "BRepFeat_SplitShape", "One of the most significant aspects of BRepFeat functionality is the use of local operations as opposed to global ones. In a global operation, you would first construct a form of the type you wanted in your final feature, and then remove matter so that it could fit into your initial basis object. In a local operation, however, you specify the domain of the feature construction with aspects of the shape on which the feature is being created. These semantics are expressed in terms of a member shape of the basis shape from which - or up to which - matter will be added or removed. As a result, local operations make calculations simpler and faster than global operations. In BRepFeat, the semantics of local operations define features constructed from a contour or a part of the basis shape referred to as the tool. In a SplitShape object, wires or edges of a face in the basis shape to be used as a part of the feature are cut out and projected to a plane outside or inside the basis shape. By rebuilding the initial shape incorporating the edges and the faces of the tool, protrusion or depression features can be constructed.");
	cls_BRepFeat_SplitShape.def(py::init<>());
	cls_BRepFeat_SplitShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_BRepFeat_SplitShape.def("Add", (Standard_Boolean (BRepFeat_SplitShape::*)(const TopTools_SequenceOfShape &)) &BRepFeat_SplitShape::Add, "Add splitting edges or wires for whole initial shape withot additional specification edge->face, edge->edge This method puts edge on the corresponding faces from initial shape", py::arg("theEdges"));
	cls_BRepFeat_SplitShape.def("Init", (void (BRepFeat_SplitShape::*)(const TopoDS_Shape &)) &BRepFeat_SplitShape::Init, "Initializes the process on the shape <S>.", py::arg("S"));
	cls_BRepFeat_SplitShape.def("SetCheckInterior", (void (BRepFeat_SplitShape::*)(const Standard_Boolean)) &BRepFeat_SplitShape::SetCheckInterior, "Set the flag of check internal intersections default value is True (to check)", py::arg("ToCheckInterior"));
	cls_BRepFeat_SplitShape.def("Add", (void (BRepFeat_SplitShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &BRepFeat_SplitShape::Add, "Adds the wire <W> on the face <F>. Raises NoSuchObject if <F> does not belong to the original shape.", py::arg("W"), py::arg("F"));
	cls_BRepFeat_SplitShape.def("Add", (void (BRepFeat_SplitShape::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_SplitShape::Add, "Adds the edge <E> on the face <F>.", py::arg("E"), py::arg("F"));
	cls_BRepFeat_SplitShape.def("Add", (void (BRepFeat_SplitShape::*)(const TopoDS_Compound &, const TopoDS_Face &)) &BRepFeat_SplitShape::Add, "Adds the compound <Comp> on the face <F>. The compound <Comp> must consist of edges lying on the face <F>. If edges are geometrically connected, they must be connected topologically, i.e. they must share common vertices.", py::arg("Comp"), py::arg("F"));
	cls_BRepFeat_SplitShape.def("Add", (void (BRepFeat_SplitShape::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepFeat_SplitShape::Add, "Adds the edge <E> on the existing edge <EOn>.", py::arg("E"), py::arg("EOn"));
	cls_BRepFeat_SplitShape.def("DirectLeft", (const TopTools_ListOfShape & (BRepFeat_SplitShape::*)() const ) &BRepFeat_SplitShape::DirectLeft, "Returns the faces which are the left of the projected wires.");
	cls_BRepFeat_SplitShape.def("Left", (const TopTools_ListOfShape & (BRepFeat_SplitShape::*)() const ) &BRepFeat_SplitShape::Left, "Returns the faces of the 'left' part on the shape. (It is build from DirectLeft, with the faces connected to this set, and so on...). Raises NotDone if IsDone returns <Standard_False>.");
	cls_BRepFeat_SplitShape.def("Build", (void (BRepFeat_SplitShape::*)()) &BRepFeat_SplitShape::Build, "Builds the cut and the resulting faces and edges as well.");
	cls_BRepFeat_SplitShape.def("IsDeleted", (Standard_Boolean (BRepFeat_SplitShape::*)(const TopoDS_Shape &)) &BRepFeat_SplitShape::IsDeleted, "Returns true if the shape has been deleted.", py::arg("S"));
	cls_BRepFeat_SplitShape.def("Modified", (const TopTools_ListOfShape & (BRepFeat_SplitShape::*)(const TopoDS_Shape &)) &BRepFeat_SplitShape::Modified, "Returns the list of generated Faces.", py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_Form.hxx
	py::class_<BRepFeat_Form, std::unique_ptr<BRepFeat_Form, Deleter<BRepFeat_Form>>, BRepBuilderAPI_MakeShape> cls_BRepFeat_Form(mod, "BRepFeat_Form", "Provides general functions to build form features. Form features can be depressions or protrusions and include the following types: - Cylinder - Draft Prism - Prism - Revolved feature - Pipe In each case, you have a choice of operation type between the following: - removing matter (a Boolean cut: Fuse setting 0) - adding matter (Boolean fusion: Fuse setting 1) The semantics of form feature creation is based on the construction of shapes: - along a length - up to a limiting face - from a limiting face to a height - above and/or below a plane The shape defining construction of the feature can be either the supporting edge or the concerned area of a face. In case of the supporting edge, this contour can be attached to a face of the basis shape by binding. When the contour is bound to this face, the information that the contour will slide on the face becomes available to the relevant class methods. In case of the concerned area of a face, you could, for example, cut it out and move it to a different height which will define the limiting face of a protrusion or depression. Topological definition with local operations of this sort makes calculations simpler and faster than a global operation. The latter would entail a second phase of removing unwanted matter to get the same result.");
	cls_BRepFeat_Form.def("Modified", (const TopTools_ListOfShape & (BRepFeat_Form::*)(const TopoDS_Shape &)) &BRepFeat_Form::Modified, "returns the list of generated Faces.", py::arg("F"));
	cls_BRepFeat_Form.def("Generated", (const TopTools_ListOfShape & (BRepFeat_Form::*)(const TopoDS_Shape &)) &BRepFeat_Form::Generated, "returns a list of the created faces from the shape <S>.", py::arg("S"));
	cls_BRepFeat_Form.def("IsDeleted", (Standard_Boolean (BRepFeat_Form::*)(const TopoDS_Shape &)) &BRepFeat_Form::IsDeleted, "None", py::arg("S"));
	cls_BRepFeat_Form.def("FirstShape", (const TopTools_ListOfShape & (BRepFeat_Form::*)() const ) &BRepFeat_Form::FirstShape, "Returns the list of shapes created at the bottom of the created form. It may be an empty list.");
	cls_BRepFeat_Form.def("LastShape", (const TopTools_ListOfShape & (BRepFeat_Form::*)() const ) &BRepFeat_Form::LastShape, "Returns the list of shapes created at the top of the created form. It may be an empty list.");
	cls_BRepFeat_Form.def("NewEdges", (const TopTools_ListOfShape & (BRepFeat_Form::*)() const ) &BRepFeat_Form::NewEdges, "Returns a list of the limiting and glueing edges generated by the feature. These edges did not originally exist in the basis shape. The list provides the information necessary for subsequent addition of fillets. It may be an empty list.");
	cls_BRepFeat_Form.def("TgtEdges", (const TopTools_ListOfShape & (BRepFeat_Form::*)() const ) &BRepFeat_Form::TgtEdges, "Returns a list of the tangent edges among the limiting and glueing edges generated by the feature. These edges did not originally exist in the basis shape and are tangent to the face against which the feature is built. The list provides the information necessary for subsequent addition of fillets. It may be an empty list. If an edge is tangent, no fillet is possible, and the edge must subsequently be removed if you want to add a fillet.");
	cls_BRepFeat_Form.def("BasisShapeValid", (void (BRepFeat_Form::*)()) &BRepFeat_Form::BasisShapeValid, "Initializes the topological construction if the basis shape is present.");
	cls_BRepFeat_Form.def("GeneratedShapeValid", (void (BRepFeat_Form::*)()) &BRepFeat_Form::GeneratedShapeValid, "Initializes the topological construction if the generated shape S is present.");
	cls_BRepFeat_Form.def("ShapeFromValid", (void (BRepFeat_Form::*)()) &BRepFeat_Form::ShapeFromValid, "Initializes the topological construction if the shape is present from the specified integer on.");
	cls_BRepFeat_Form.def("ShapeUntilValid", (void (BRepFeat_Form::*)()) &BRepFeat_Form::ShapeUntilValid, "Initializes the topological construction if the shape is present until the specified integer.");
	cls_BRepFeat_Form.def("GluedFacesValid", (void (BRepFeat_Form::*)()) &BRepFeat_Form::GluedFacesValid, "Initializes the topological construction if the glued face is present.");
	cls_BRepFeat_Form.def("SketchFaceValid", (void (BRepFeat_Form::*)()) &BRepFeat_Form::SketchFaceValid, "Initializes the topological construction if the sketch face is present. If the sketch face is inside the basis shape, local operations such as glueing can be performed.");
	cls_BRepFeat_Form.def("PerfSelectionValid", (void (BRepFeat_Form::*)()) &BRepFeat_Form::PerfSelectionValid, "Initializes the topological construction if the selected face is present.");
	cls_BRepFeat_Form.def("Curves", (void (BRepFeat_Form::*)(TColGeom_SequenceOfCurve &)) &BRepFeat_Form::Curves, "None", py::arg("S"));
	cls_BRepFeat_Form.def("BarycCurve", (opencascade::handle<Geom_Curve> (BRepFeat_Form::*)()) &BRepFeat_Form::BarycCurve, "None");
	cls_BRepFeat_Form.def("CurrentStatusError", (BRepFeat_StatusError (BRepFeat_Form::*)() const ) &BRepFeat_Form::CurrentStatusError, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_RibSlot.hxx
	py::class_<BRepFeat_RibSlot, std::unique_ptr<BRepFeat_RibSlot, Deleter<BRepFeat_RibSlot>>, BRepBuilderAPI_MakeShape> cls_BRepFeat_RibSlot(mod, "BRepFeat_RibSlot", "Provides functions to build mechanical features. Mechanical features include ribs - protrusions and grooves (or slots) - depressions along planar (linear) surfaces or revolution surfaces. The semantics of mechanical features is built around giving thickness to a contour. This thickness can either be unilateral - on one side of the contour - or bilateral - on both sides. As in the semantics of form features, the thickness is defined by construction of shapes in specific contexts. The development contexts differ, however,in case of mechanical features. Here they include extrusion: - to a limiting face of the basis shape - to or from a limiting plane - to a height.");
	cls_BRepFeat_RibSlot.def("IsDeleted", (Standard_Boolean (BRepFeat_RibSlot::*)(const TopoDS_Shape &)) &BRepFeat_RibSlot::IsDeleted, "Returns true if F a TopoDS_Shape of type edge or face has been deleted.", py::arg("F"));
	cls_BRepFeat_RibSlot.def("Modified", (const TopTools_ListOfShape & (BRepFeat_RibSlot::*)(const TopoDS_Shape &)) &BRepFeat_RibSlot::Modified, "Returns the list of generated Faces F. This list may be empty.", py::arg("F"));
	cls_BRepFeat_RibSlot.def("Generated", (const TopTools_ListOfShape & (BRepFeat_RibSlot::*)(const TopoDS_Shape &)) &BRepFeat_RibSlot::Generated, "Returns a list TopTools_ListOfShape of the faces S created in the shape.", py::arg("S"));
	cls_BRepFeat_RibSlot.def("FirstShape", (const TopTools_ListOfShape & (BRepFeat_RibSlot::*)() const ) &BRepFeat_RibSlot::FirstShape, "Returns the list of shapes created at the bottom of the created form. It may be an empty list.");
	cls_BRepFeat_RibSlot.def("LastShape", (const TopTools_ListOfShape & (BRepFeat_RibSlot::*)() const ) &BRepFeat_RibSlot::LastShape, "Returns the list of shapes created at the top of the created form. It may be an empty list.");
	cls_BRepFeat_RibSlot.def("FacesForDraft", (const TopTools_ListOfShape & (BRepFeat_RibSlot::*)() const ) &BRepFeat_RibSlot::FacesForDraft, "Returns a list of the limiting and glueing faces generated by the feature. These faces did not originally exist in the basis shape. The list provides the information necessary for subsequent addition of a draft to a face. It may be an empty list. If a face has tangent edges, no draft is possible, and the tangent edges must subsequently be removed if you want to add a draft to the face.");
	cls_BRepFeat_RibSlot.def("NewEdges", (const TopTools_ListOfShape & (BRepFeat_RibSlot::*)() const ) &BRepFeat_RibSlot::NewEdges, "Returns a list of the limiting and glueing edges generated by the feature. These edges did not originally exist in the basis shape. The list provides the information necessary for subsequent addition of fillets. It may be an empty list.");
	cls_BRepFeat_RibSlot.def("TgtEdges", (const TopTools_ListOfShape & (BRepFeat_RibSlot::*)() const ) &BRepFeat_RibSlot::TgtEdges, "Returns a list of the tangent edges among the limiting and glueing edges generated by the feature. These edges did not originally exist in the basis shape and are tangent to the face against which the feature is built. The list provides the information necessary for subsequent addition of fillets. It may be an empty list. If an edge is tangent, no fillet is possible, and the edge must subsequently be removed if you want to add a fillet.");
	cls_BRepFeat_RibSlot.def_static("IntPar_", (Standard_Real (*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &)) &BRepFeat_RibSlot::IntPar, "None", py::arg("C"), py::arg("P"));
	cls_BRepFeat_RibSlot.def_static("ChoiceOfFaces_", (TopoDS_Face (*)(TopTools_ListOfShape &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Plane> &)) &BRepFeat_RibSlot::ChoiceOfFaces, "None", py::arg("faces"), py::arg("cc"), py::arg("par"), py::arg("bnd"), py::arg("Pln"));
	cls_BRepFeat_RibSlot.def("CurrentStatusError", (BRepFeat_StatusError (BRepFeat_RibSlot::*)() const ) &BRepFeat_RibSlot::CurrentStatusError, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_MakePrism.hxx
	py::class_<BRepFeat_MakePrism, std::unique_ptr<BRepFeat_MakePrism, Deleter<BRepFeat_MakePrism>>, BRepFeat_Form> cls_BRepFeat_MakePrism(mod, "BRepFeat_MakePrism", "Describes functions to build prism features. These can be depressions or protrusions. The semantics of prism feature creation is based on the construction of shapes: - along a length - up to a limiting face - from a limiting face to a height. The shape defining construction of the prism feature can be either the supporting edge or the concerned area of a face. In case of the supporting edge, this contour can be attached to a face of the basis shape by binding. When the contour is bound to this face, the information that the contour will slide on the face becomes available to the relevant class methods. In case of the concerned area of a face, you could, for example, cut it out and move it to a different height which will define the limiting face of a protrusion or depression.");
	cls_BRepFeat_MakePrism.def(py::init<>());
	cls_BRepFeat_MakePrism.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const gp_Dir &, const Standard_Integer, const Standard_Boolean>(), py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Direction"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakePrism.def("Init", (void (BRepFeat_MakePrism::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const gp_Dir &, const Standard_Integer, const Standard_Boolean)) &BRepFeat_MakePrism::Init, "Initializes this algorithm for building prisms along surfaces. A face Pbase is selected in the shape Sbase to serve as the basis for the prism. The orientation of the prism will be defined by the vector Direction. Fuse offers a choice between: - removing matter with a Boolean cut using the setting 0 - adding matter with Boolean fusion using the setting 1. The sketch face Skface serves to determine the type of operation. If it is inside the basis shape, a local operation such as glueing can be performed.", py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Direction"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakePrism.def("Add", (void (BRepFeat_MakePrism::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakePrism::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
	cls_BRepFeat_MakePrism.def("Perform", (void (BRepFeat_MakePrism::*)(const Standard_Real)) &BRepFeat_MakePrism::Perform, "None", py::arg("Length"));
	cls_BRepFeat_MakePrism.def("Perform", (void (BRepFeat_MakePrism::*)(const TopoDS_Shape &)) &BRepFeat_MakePrism::Perform, "None", py::arg("Until"));
	cls_BRepFeat_MakePrism.def("Perform", (void (BRepFeat_MakePrism::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_MakePrism::Perform, "Assigns one of the following semantics - to a height Length - to a face Until - from a face From to a height Until. Reconstructs the feature topologically according to the semantic option chosen.", py::arg("From"), py::arg("Until"));
	cls_BRepFeat_MakePrism.def("PerformUntilEnd", (void (BRepFeat_MakePrism::*)()) &BRepFeat_MakePrism::PerformUntilEnd, "Realizes a semi-infinite prism, limited by the position of the prism base. All other faces extend infinitely.");
	cls_BRepFeat_MakePrism.def("PerformFromEnd", (void (BRepFeat_MakePrism::*)(const TopoDS_Shape &)) &BRepFeat_MakePrism::PerformFromEnd, "Realizes a semi-infinite prism, limited by the face Funtil.", py::arg("FUntil"));
	cls_BRepFeat_MakePrism.def("PerformThruAll", (void (BRepFeat_MakePrism::*)()) &BRepFeat_MakePrism::PerformThruAll, "Builds an infinite prism. The infinite descendants will not be kept in the result.");
	cls_BRepFeat_MakePrism.def("PerformUntilHeight", (void (BRepFeat_MakePrism::*)(const TopoDS_Shape &, const Standard_Real)) &BRepFeat_MakePrism::PerformUntilHeight, "Assigns both a limiting shape, Until from TopoDS_Shape, and a height, Length at which to stop generation of the prism feature.", py::arg("Until"), py::arg("Length"));
	cls_BRepFeat_MakePrism.def("Curves", (void (BRepFeat_MakePrism::*)(TColGeom_SequenceOfCurve &)) &BRepFeat_MakePrism::Curves, "Returns the list of curves S parallel to the axis of the prism.", py::arg("S"));
	cls_BRepFeat_MakePrism.def("BarycCurve", (opencascade::handle<Geom_Curve> (BRepFeat_MakePrism::*)()) &BRepFeat_MakePrism::BarycCurve, "Generates a curve along the center of mass of the primitive.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_MakeRevol.hxx
	py::class_<BRepFeat_MakeRevol, std::unique_ptr<BRepFeat_MakeRevol, Deleter<BRepFeat_MakeRevol>>, BRepFeat_Form> cls_BRepFeat_MakeRevol(mod, "BRepFeat_MakeRevol", "Describes functions to build revolved shells from basis shapes.");
	cls_BRepFeat_MakeRevol.def(py::init<>());
	cls_BRepFeat_MakeRevol.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const gp_Ax1 &, const Standard_Integer, const Standard_Boolean>(), py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Axis"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakeRevol.def("Init", (void (BRepFeat_MakeRevol::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const gp_Ax1 &, const Standard_Integer, const Standard_Boolean)) &BRepFeat_MakeRevol::Init, "None", py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Axis"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakeRevol.def("Add", (void (BRepFeat_MakeRevol::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakeRevol::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
	cls_BRepFeat_MakeRevol.def("Perform", (void (BRepFeat_MakeRevol::*)(const Standard_Real)) &BRepFeat_MakeRevol::Perform, "None", py::arg("Angle"));
	cls_BRepFeat_MakeRevol.def("Perform", (void (BRepFeat_MakeRevol::*)(const TopoDS_Shape &)) &BRepFeat_MakeRevol::Perform, "None", py::arg("Until"));
	cls_BRepFeat_MakeRevol.def("Perform", (void (BRepFeat_MakeRevol::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_MakeRevol::Perform, "Reconstructs the feature topologically.", py::arg("From"), py::arg("Until"));
	cls_BRepFeat_MakeRevol.def("PerformThruAll", (void (BRepFeat_MakeRevol::*)()) &BRepFeat_MakeRevol::PerformThruAll, "Builds an infinite shell. The infinite descendants will not be kept in the result.");
	cls_BRepFeat_MakeRevol.def("PerformUntilAngle", (void (BRepFeat_MakeRevol::*)(const TopoDS_Shape &, const Standard_Real)) &BRepFeat_MakeRevol::PerformUntilAngle, "Assigns both a limiting shape, Until from TopoDS_Shape, and an angle, Angle at which to stop generation of the revolved shell feature.", py::arg("Until"), py::arg("Angle"));
	cls_BRepFeat_MakeRevol.def("Curves", (void (BRepFeat_MakeRevol::*)(TColGeom_SequenceOfCurve &)) &BRepFeat_MakeRevol::Curves, "None", py::arg("S"));
	cls_BRepFeat_MakeRevol.def("BarycCurve", (opencascade::handle<Geom_Curve> (BRepFeat_MakeRevol::*)()) &BRepFeat_MakeRevol::BarycCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_MakePipe.hxx
	py::class_<BRepFeat_MakePipe, std::unique_ptr<BRepFeat_MakePipe, Deleter<BRepFeat_MakePipe>>, BRepFeat_Form> cls_BRepFeat_MakePipe(mod, "BRepFeat_MakePipe", "Constructs compound shapes with pipe features. These can be depressions or protrusions. The semantics of pipe feature creation is based on the construction of shapes: - along a length - up to a limiting face - from a limiting face to a height. The shape defining construction of the pipe feature can be either the supporting edge or the concerned area of a face. In case of the supporting edge, this contour can be attached to a face of the basis shape by binding. When the contour is bound to this face, the information that the contour will slide on the face becomes available to the relevant class methods. In case of the concerned area of a face, you could, for example, cut it out and move it to a different height which will define the limiting face of a protrusion or depression.");
	cls_BRepFeat_MakePipe.def(py::init<>());
	cls_BRepFeat_MakePipe.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Wire &, const Standard_Integer, const Standard_Boolean>(), py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Spine"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakePipe.def("Init", (void (BRepFeat_MakePipe::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Wire &, const Standard_Integer, const Standard_Boolean)) &BRepFeat_MakePipe::Init, "Initializes this algorithm for adding pipes to shapes. A face Pbase is selected in the shape Sbase to serve as the basis for the pipe. It will be defined by the wire Spine. Fuse offers a choice between: - removing matter with a Boolean cut using the setting 0 - adding matter with Boolean fusion using the setting 1. The sketch face Skface serves to determine the type of operation. If it is inside the basis shape, a local operation such as glueing can be performed.", py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Spine"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakePipe.def("Add", (void (BRepFeat_MakePipe::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakePipe::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
	cls_BRepFeat_MakePipe.def("Perform", (void (BRepFeat_MakePipe::*)()) &BRepFeat_MakePipe::Perform, "None");
	cls_BRepFeat_MakePipe.def("Perform", (void (BRepFeat_MakePipe::*)(const TopoDS_Shape &)) &BRepFeat_MakePipe::Perform, "None", py::arg("Until"));
	cls_BRepFeat_MakePipe.def("Perform", (void (BRepFeat_MakePipe::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_MakePipe::Perform, "Assigns one of the following semantics - to a face Until - from a face From to a height Until. Reconstructs the feature topologically according to the semantic option chosen.", py::arg("From"), py::arg("Until"));
	cls_BRepFeat_MakePipe.def("Curves", (void (BRepFeat_MakePipe::*)(TColGeom_SequenceOfCurve &)) &BRepFeat_MakePipe::Curves, "None", py::arg("S"));
	cls_BRepFeat_MakePipe.def("BarycCurve", (opencascade::handle<Geom_Curve> (BRepFeat_MakePipe::*)()) &BRepFeat_MakePipe::BarycCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_Gluer.hxx
	py::class_<BRepFeat_Gluer, std::unique_ptr<BRepFeat_Gluer, Deleter<BRepFeat_Gluer>>, BRepBuilderAPI_MakeShape> cls_BRepFeat_Gluer(mod, "BRepFeat_Gluer", "One of the most significant aspects of BRepFeat functionality is the use of local operations as opposed to global ones. In a global operation, you would first construct a form of the type you wanted in your final feature, and then remove matter so that it could fit into your initial basis object. In a local operation, however, you specify the domain of the feature construction with aspects of the shape on which the feature is being created. These semantics are expressed in terms of a member shape of the basis shape from which - or up to which - matter will be added or removed. As a result, local operations make calculations simpler and faster than global operations. Glueing uses wires or edges of a face in the basis shape. These are to become a part of the feature. They are first cut out and then projected to a plane outside or inside the basis shape. By rebuilding the initial shape incorporating the edges and the faces of the tool, protrusion features can be constructed.");
	cls_BRepFeat_Gluer.def(py::init<>());
	cls_BRepFeat_Gluer.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Snew"), py::arg("Sbase"));
	cls_BRepFeat_Gluer.def("Init", (void (BRepFeat_Gluer::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_Gluer::Init, "Initializes the new shape Snew and the basis shape Sbase for the local glueing operation.", py::arg("Snew"), py::arg("Sbase"));
	cls_BRepFeat_Gluer.def("Bind", (void (BRepFeat_Gluer::*)(const TopoDS_Face &, const TopoDS_Face &)) &BRepFeat_Gluer::Bind, "Defines a contact between Fnew on the new shape Snew and Fbase on the basis shape Sbase. Informs other methods that Fnew in the new shape Snew is connected to the face Fbase in the basis shape Sbase. The contact faces of the glued shape must not have parts outside the contact faces of the basis shape. This indicates that glueing is possible.", py::arg("Fnew"), py::arg("Fbase"));
	cls_BRepFeat_Gluer.def("Bind", (void (BRepFeat_Gluer::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BRepFeat_Gluer::Bind, "nforms other methods that the edge Enew in the new shape is the same as the edge Ebase in the basis shape and is therefore attached to the basis shape. This indicates that glueing is possible.", py::arg("Enew"), py::arg("Ebase"));
	cls_BRepFeat_Gluer.def("OpeType", (LocOpe_Operation (BRepFeat_Gluer::*)() const ) &BRepFeat_Gluer::OpeType, "Determine which operation type to use glueing or sliding.");
	cls_BRepFeat_Gluer.def("BasisShape", (const TopoDS_Shape & (BRepFeat_Gluer::*)() const ) &BRepFeat_Gluer::BasisShape, "Returns the basis shape of the compound shape.");
	cls_BRepFeat_Gluer.def("GluedShape", (const TopoDS_Shape & (BRepFeat_Gluer::*)() const ) &BRepFeat_Gluer::GluedShape, "Returns the resulting compound shape.");
	cls_BRepFeat_Gluer.def("Build", (void (BRepFeat_Gluer::*)()) &BRepFeat_Gluer::Build, "This is called by Shape(). It does nothing but may be redefined.");
	cls_BRepFeat_Gluer.def("IsDeleted", (Standard_Boolean (BRepFeat_Gluer::*)(const TopoDS_Shape &)) &BRepFeat_Gluer::IsDeleted, "returns the status of the Face after the shape creation.", py::arg("F"));
	cls_BRepFeat_Gluer.def("Modified", (const TopTools_ListOfShape & (BRepFeat_Gluer::*)(const TopoDS_Shape &)) &BRepFeat_Gluer::Modified, "returns the list of generated Faces.", py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_MakeDPrism.hxx
	py::class_<BRepFeat_MakeDPrism, std::unique_ptr<BRepFeat_MakeDPrism, Deleter<BRepFeat_MakeDPrism>>, BRepFeat_Form> cls_BRepFeat_MakeDPrism(mod, "BRepFeat_MakeDPrism", "Describes functions to build draft prism topologies from basis shape surfaces. These can be depressions or protrusions. The semantics of draft prism feature creation is based on the construction of shapes: - along a length - up to a limiting face - from a limiting face to a height. The shape defining construction of the draft prism feature can be either the supporting edge or the concerned area of a face. In case of the supporting edge, this contour can be attached to a face of the basis shape by binding. When the contour is bound to this face, the information that the contour will slide on the face becomes available to the relevant class methods. In case of the concerned area of a face, you could, for example, cut it out and move it to a different height which will define the limiting face of a protrusion or depression.");
	cls_BRepFeat_MakeDPrism.def(py::init<const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Angle"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakeDPrism.def(py::init<>());
	cls_BRepFeat_MakeDPrism.def("Init", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Face &, const Standard_Real, const Standard_Integer, const Standard_Boolean)) &BRepFeat_MakeDPrism::Init, "Initializes this algorithm for building draft prisms along surfaces. A face Pbase is selected in the basis shape Sbase to serve as the basis from the draft prism. The draft will be defined by the angle Angle and Fuse offers a choice between: - removing matter with a Boolean cut using the setting 0 - adding matter with Boolean fusion using the setting 1. The sketch face Skface serves to determine the type of operation. If it is inside the basis shape, a local operation such as glueing can be performed.", py::arg("Sbase"), py::arg("Pbase"), py::arg("Skface"), py::arg("Angle"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakeDPrism.def("Add", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakeDPrism::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
	cls_BRepFeat_MakeDPrism.def("Perform", (void (BRepFeat_MakeDPrism::*)(const Standard_Real)) &BRepFeat_MakeDPrism::Perform, "None", py::arg("Height"));
	cls_BRepFeat_MakeDPrism.def("Perform", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &)) &BRepFeat_MakeDPrism::Perform, "None", py::arg("Until"));
	cls_BRepFeat_MakeDPrism.def("Perform", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepFeat_MakeDPrism::Perform, "Assigns one of the following semantics - to a height Height - to a face Until - from a face From to a height Until. Reconstructs the feature topologically according to the semantic option chosen.", py::arg("From"), py::arg("Until"));
	cls_BRepFeat_MakeDPrism.def("PerformUntilEnd", (void (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::PerformUntilEnd, "Realizes a semi-infinite prism, limited by the position of the prism base.");
	cls_BRepFeat_MakeDPrism.def("PerformFromEnd", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &)) &BRepFeat_MakeDPrism::PerformFromEnd, "Realizes a semi-infinite prism, limited by the face Funtil.", py::arg("FUntil"));
	cls_BRepFeat_MakeDPrism.def("PerformThruAll", (void (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::PerformThruAll, "Builds an infinite prism. The infinite descendants will not be kept in the result.");
	cls_BRepFeat_MakeDPrism.def("PerformUntilHeight", (void (BRepFeat_MakeDPrism::*)(const TopoDS_Shape &, const Standard_Real)) &BRepFeat_MakeDPrism::PerformUntilHeight, "Assigns both a limiting shape, Until from TopoDS_Shape, and a height, Height at which to stop generation of the prism feature.", py::arg("Until"), py::arg("Height"));
	cls_BRepFeat_MakeDPrism.def("Curves", (void (BRepFeat_MakeDPrism::*)(TColGeom_SequenceOfCurve &)) &BRepFeat_MakeDPrism::Curves, "None", py::arg("S"));
	cls_BRepFeat_MakeDPrism.def("BarycCurve", (opencascade::handle<Geom_Curve> (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::BarycCurve, "None");
	cls_BRepFeat_MakeDPrism.def("BossEdges", (void (BRepFeat_MakeDPrism::*)(const Standard_Integer)) &BRepFeat_MakeDPrism::BossEdges, "Determination of TopEdges and LatEdges. sig = 1 -> TopEdges = FirstShape of the DPrism sig = 2 -> TOpEdges = LastShape of the DPrism", py::arg("sig"));
	cls_BRepFeat_MakeDPrism.def("TopEdges", (const TopTools_ListOfShape & (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::TopEdges, "Returns the list of TopoDS Edges of the top of the boss.");
	cls_BRepFeat_MakeDPrism.def("LatEdges", (const TopTools_ListOfShape & (BRepFeat_MakeDPrism::*)()) &BRepFeat_MakeDPrism::LatEdges, "Returns the list of TopoDS Edges of the bottom of the boss.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_MakeLinearForm.hxx
	py::class_<BRepFeat_MakeLinearForm, std::unique_ptr<BRepFeat_MakeLinearForm, Deleter<BRepFeat_MakeLinearForm>>, BRepFeat_RibSlot> cls_BRepFeat_MakeLinearForm(mod, "BRepFeat_MakeLinearForm", "Builds a rib or a groove along a developable, planar surface. The semantics of mechanical features is built around giving thickness to a contour. This thickness can either be symmetrical - on one side of the contour - or dissymmetrical - on both sides. As in the semantics of form features, the thickness is defined by construction of shapes in specific contexts. The development contexts differ, however, in case of mechanical features. Here they include extrusion: - to a limiting face of the basis shape - to or from a limiting plane - to a height.");
	cls_BRepFeat_MakeLinearForm.def(py::init<>());
	cls_BRepFeat_MakeLinearForm.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const opencascade::handle<Geom_Plane> &, const gp_Vec &, const gp_Vec &, const Standard_Integer, const Standard_Boolean>(), py::arg("Sbase"), py::arg("W"), py::arg("P"), py::arg("Direction"), py::arg("Direction1"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakeLinearForm.def("Init", (void (BRepFeat_MakeLinearForm::*)(const TopoDS_Shape &, const TopoDS_Wire &, const opencascade::handle<Geom_Plane> &, const gp_Vec &, const gp_Vec &, const Standard_Integer, const Standard_Boolean)) &BRepFeat_MakeLinearForm::Init, "Initializes this construction algorithm. A contour W, a shape Sbase and a plane P are initialized to serve as the basic elements in the construction of the rib or groove. The vectors for defining the direction(s) in which thickness will be built up are given by Direction and Direction1. Fuse offers a choice between: - removing matter with a Boolean cut using the setting 0 in case of the groove - adding matter with Boolean fusion using the setting 1 in case of the rib.", py::arg("Sbase"), py::arg("W"), py::arg("P"), py::arg("Direction"), py::arg("Direction1"), py::arg("Fuse"), py::arg("Modify"));
	cls_BRepFeat_MakeLinearForm.def("Add", (void (BRepFeat_MakeLinearForm::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakeLinearForm::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
	cls_BRepFeat_MakeLinearForm.def("Perform", (void (BRepFeat_MakeLinearForm::*)()) &BRepFeat_MakeLinearForm::Perform, "Performs a prism from the wire to the plane along the basis shape Sbase. Reconstructs the feature topologically.");
	// cls_BRepFeat_MakeLinearForm.def("TransformShapeFU", (void (BRepFeat_MakeLinearForm::*)(const Standard_Integer)) &BRepFeat_MakeLinearForm::TransformShapeFU, "Limits construction of the linear form feature by using one of the following three semantics: - from a limiting plane - to a limiting plane - from one limiting plane to another. The setting is provided by a flag, flag, which can be set to from and/or until. The third semantic possibility above is selected by showing both from and until at the same time.", py::arg("flag"));
	cls_BRepFeat_MakeLinearForm.def("Propagate", [](BRepFeat_MakeLinearForm &self, TopTools_ListOfShape & L, const TopoDS_Face & F, const gp_Pnt & FPoint, const gp_Pnt & LPoint, Standard_Boolean & falseside){ Standard_Boolean rv = self.Propagate(L, F, FPoint, LPoint, falseside); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, falseside); }, "None", py::arg("L"), py::arg("F"), py::arg("FPoint"), py::arg("LPoint"), py::arg("falseside"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat_MakeRevolutionForm.hxx
	py::class_<BRepFeat_MakeRevolutionForm, std::unique_ptr<BRepFeat_MakeRevolutionForm, Deleter<BRepFeat_MakeRevolutionForm>>, BRepFeat_RibSlot> cls_BRepFeat_MakeRevolutionForm(mod, "BRepFeat_MakeRevolutionForm", "MakeRevolutionForm Generates a surface of revolution in the feature as it slides along a revolved face in the basis shape. The semantics of mechanical features is built around giving thickness to a contour. This thickness can either be unilateral - on one side of the contour - or bilateral - on both sides. As in the semantics of form features, the thickness is defined by construction of shapes in specific contexts. The development contexts differ, however,in case of mechanical features. Here they include extrusion: - to a limiting face of the basis shape - to or from a limiting plane - to a height.");
	cls_BRepFeat_MakeRevolutionForm.def(py::init<>());
	cls_BRepFeat_MakeRevolutionForm.def(py::init<const TopoDS_Shape &, const TopoDS_Wire &, const opencascade::handle<Geom_Plane> &, const gp_Ax1 &, const Standard_Real, const Standard_Real, const Standard_Integer, Standard_Boolean &>(), py::arg("Sbase"), py::arg("W"), py::arg("Plane"), py::arg("Axis"), py::arg("Height1"), py::arg("Height2"), py::arg("Fuse"), py::arg("Sliding"));
	cls_BRepFeat_MakeRevolutionForm.def("Init", [](BRepFeat_MakeRevolutionForm &self, const TopoDS_Shape & Sbase, const TopoDS_Wire & W, const opencascade::handle<Geom_Plane> & Plane, const gp_Ax1 & Axis, const Standard_Real Height1, const Standard_Real Height2, const Standard_Integer Fuse, Standard_Boolean & Sliding){ self.Init(Sbase, W, Plane, Axis, Height1, Height2, Fuse, Sliding); return Sliding; }, "Initializes this construction algorithm A contour W, a shape Sbase and a plane P are initialized to serve as the basic elements in the construction of the rib or groove. The axis Axis of the revolved surface in the basis shape defines the feature's axis of revolution. Height1 and Height2 may be used as limits to the construction of the feature. Fuse offers a choice between: - removing matter with a Boolean cut using the setting 0 in case of the groove - adding matter with Boolean fusion using the setting 1 in case of the rib.", py::arg("Sbase"), py::arg("W"), py::arg("Plane"), py::arg("Axis"), py::arg("Height1"), py::arg("Height2"), py::arg("Fuse"), py::arg("Sliding"));
	cls_BRepFeat_MakeRevolutionForm.def("Add", (void (BRepFeat_MakeRevolutionForm::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepFeat_MakeRevolutionForm::Add, "Indicates that the edge <E> will slide on the face <OnFace>. Raises ConstructionError if the face does not belong to the basis shape, or the edge to the prismed shape.", py::arg("E"), py::arg("OnFace"));
	cls_BRepFeat_MakeRevolutionForm.def("Perform", (void (BRepFeat_MakeRevolutionForm::*)()) &BRepFeat_MakeRevolutionForm::Perform, "Performs a prism from the wire to the plane along the basis shape S. Reconstructs the feature topologically.");
	cls_BRepFeat_MakeRevolutionForm.def("Propagate", [](BRepFeat_MakeRevolutionForm &self, TopTools_ListOfShape & L, const TopoDS_Face & F, const gp_Pnt & FPoint, const gp_Pnt & LPoint, Standard_Boolean & falseside){ Standard_Boolean rv = self.Propagate(L, F, FPoint, LPoint, falseside); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, falseside); }, "None", py::arg("L"), py::arg("F"), py::arg("FPoint"), py::arg("LPoint"), py::arg("falseside"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepFeat.hxx
	py::class_<BRepFeat, std::unique_ptr<BRepFeat, Deleter<BRepFeat>>> cls_BRepFeat(mod, "BRepFeat", "BRepFeat is necessary for the creation and manipulation of both form and mechanical features in a Boundary Representation framework. Form features can be depressions or protrusions and include the following types: - Cylinder - Draft Prism - Prism - Revolved feature - Pipe Depending on whether you wish to make a depression or a protrusion, you can choose your operation type between the following: - removing matter (a Boolean cut: Fuse setting 0) - adding matter (Boolean fusion: Fuse setting 1) The semantics of form feature creation is based on the construction of shapes: - for a certain length in a certain direction - up to a limiting face - from a limiting face at a height - above and/or below a plane The shape defining the construction of a feature can be either a supporting edge or a concerned area of a face. In case of supporting edge, this contour can be attached to a face of the basis shape by binding. When the contour is bound to this face, the information that the contour will slide on the face becomes available to the relevant class methods. In case of the concerned area of a face, you could, for example, cut it out and move it at a different height, which will define the limiting face of a protrusion or depression. Topological definition with local operations of this sort makes calculations simpler and faster than a global operation. The latter would entail a second phase of removing unwanted matter to get the same result. Mechanical features include ribs - protrusions - and grooves (or slots) - depressions along planar (linear) surfaces or revolution surfaces. The semantics of mechanical features is based on giving thickness to a contour. This thickness can either be unilateral - on one side of the contour - or bilateral - on both sides. As in the semantics of form features, the thickness is defined by construction of shapes in specific contexts. However, in case of mechanical features, development contexts differ. Here they include extrusion: - to a limiting face of the basis shape - to or from a limiting plane - to a height.");
	cls_BRepFeat.def(py::init<>());
	cls_BRepFeat.def_static("SampleEdges_", (void (*)(const TopoDS_Shape &, TColgp_SequenceOfPnt &)) &BRepFeat::SampleEdges, "None", py::arg("S"), py::arg("Pt"));
	cls_BRepFeat.def_static("Barycenter_", (void (*)(const TopoDS_Shape &, gp_Pnt &)) &BRepFeat::Barycenter, "None", py::arg("S"), py::arg("Pt"));
	cls_BRepFeat.def_static("ParametricBarycenter_", (Standard_Real (*)(const TopoDS_Shape &, const opencascade::handle<Geom_Curve> &)) &BRepFeat::ParametricBarycenter, "None", py::arg("S"), py::arg("C"));
	cls_BRepFeat.def_static("ParametricMinMax_", [](const TopoDS_Shape & S, const opencascade::handle<Geom_Curve> & C, Standard_Real & prmin, Standard_Real & prmax, Standard_Real & prbmin, Standard_Real & prbmax, Standard_Boolean & flag, const Standard_Boolean Ori){ BRepFeat::ParametricMinMax(S, C, prmin, prmax, prbmin, prbmax, flag, Ori); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Boolean &>(prmin, prmax, prbmin, prbmax, flag); }, "Ori = True taking account the orientation", py::arg("S"), py::arg("C"), py::arg("prmin"), py::arg("prmax"), py::arg("prbmin"), py::arg("prbmax"), py::arg("flag"), py::arg("Ori"));
	cls_BRepFeat.def_static("IsInside_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &)) &BRepFeat::IsInside, "None", py::arg("F1"), py::arg("F2"));
	// cls_BRepFeat.def_static("IsInOut_", (Standard_Boolean (*)(const BRepTopAdaptor_FClass2d &, const Geom2dAdaptor_Curve &)) &BRepFeat::IsInOut, "None", py::arg("FC"), py::arg("AC"));
	cls_BRepFeat.def_static("FaceUntil_", (void (*)(const TopoDS_Shape &, TopoDS_Face &)) &BRepFeat::FaceUntil, "None", py::arg("S"), py::arg("F"));
	cls_BRepFeat.def_static("Tool_", (TopoDS_Solid (*)(const TopoDS_Shape &, const TopoDS_Face &, const TopAbs_Orientation)) &BRepFeat::Tool, "None", py::arg("SRef"), py::arg("Fac"), py::arg("Orf"));
	cls_BRepFeat.def_static("Print_", (Standard_OStream & (*)(const BRepFeat_StatusError, Standard_OStream &)) &BRepFeat::Print, "Prints the Error description of the State <St> as a String on the Stream <S> and returns <S>.", py::arg("SE"), py::arg("S"));


}
