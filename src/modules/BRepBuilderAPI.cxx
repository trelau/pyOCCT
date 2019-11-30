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
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <BRepBuilderAPI_EdgeError.hxx>
#include <BRepBuilderAPI_FaceError.hxx>
#include <BRepBuilderAPI_ShellError.hxx>
#include <BRepBuilderAPI_WireError.hxx>
#include <BRepBuilderAPI_PipeError.hxx>
#include <BRepBuilderAPI_ShapeModification.hxx>
#include <BRepBuilderAPI_TransitionMode.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepBuilderAPI_Command.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Plane.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeEdge2d.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_FindPlane.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeShell.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <BRepBuilderAPI_ModifyShape.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepBuilderAPI_NurbsConvert.hxx>
#include <BRepBuilderAPI_GTransform.hxx>
#include <BRepBuilderAPI_Copy.hxx>
#include <BRepBuilderAPI_Collect.hxx>
#include <BRepBuilderAPI.hxx>
#include <NCollection_UBTree.hxx>
#include <Bnd_Box.hxx>
#include <BRepBuilderAPI_BndBoxTreeSelector.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <NCollection_Vector.hxx>
#include <BRepBuilderAPI_VertexInspector.hxx>
#include <NCollection_CellFilter.hxx>
#include <BRepBuilderAPI_CellFilter.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepTools_Modification.hxx>
#include <BRepTools_Modifier.hxx>
#include <Standard_Transient.hxx>
#include <Geom_Surface.hxx>
#include <BRepBuilderAPI_FastSewing.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <BRep_Builder.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Vertex.hxx>
#include <NCollection_List.hxx>
#include <Standard_RangeError.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <NCollection_Sequence.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_GTrsf.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <BRepLib_MakeEdge.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <BRepLib_MakeEdge2d.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <BRepLib_MakeFace.hxx>
#include <BRepLib_MakePolygon.hxx>
#include <TopoDS_Shell.hxx>
#include <BRepLib_MakeShell.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepLib_MakeSolid.hxx>
#include <BRepLib_MakeVertex.hxx>
#include <BRepLib_MakeWire.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepTools_ReShape.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TColStd_IndexedMapOfInteger.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <TopLoc_Location.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TColStd_Array1OfBoolean.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <gp_Trsf.hxx>
#include <bind_NCollection_UBTree.hxx>
#include <bind_NCollection_Vector.hxx>
#include <bind_NCollection_CellFilter.hxx>

PYBIND11_MODULE(BRepBuilderAPI, mod) {

py::module::import("OCCT.gp");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Geom");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.BRep");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.BRepLib");
py::module::import("OCCT.Message");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TColgp");

// ENUM: BREPBUILDERAPI_EDGEERROR
py::enum_<BRepBuilderAPI_EdgeError>(mod, "BRepBuilderAPI_EdgeError", "Indicates the outcome of the construction of an edge, i.e. whether it has been successful or not, as explained below: - BRepBuilderAPI_EdgeDone No error occurred; The edge is correctly built. - BRepBuilderAPI_PointProjectionFailed No parameters were given but the projection of the 3D points on the curve failed. This happens when the point distance to the curve is greater than the precision value. - BRepBuilderAPI_ParameterOutOfRange The given parameters are not in the parametric range C->FirstParameter(), C->LastParameter() - BRepBuilderAPI_DifferentPointsOnClosedCurve The two vertices or points are the extremities of a closed curve but have different locations. - BRepBuilderAPI_PointWithInfiniteParameter A finite coordinate point was associated with an infinite parameter (see the Precision package for a definition of infinite values). - BRepBuilderAPI_DifferentsPointAndParameter The distance between the 3D point and the point evaluated on the curve with the parameter is greater than the precision. - BRepBuilderAPI_LineThroughIdenticPoints Two identical points were given to define a line (construction of an edge without curve); gp::Resolution is used for the confusion test.")
	.value("BRepBuilderAPI_EdgeDone", BRepBuilderAPI_EdgeError::BRepBuilderAPI_EdgeDone)
	.value("BRepBuilderAPI_PointProjectionFailed", BRepBuilderAPI_EdgeError::BRepBuilderAPI_PointProjectionFailed)
	.value("BRepBuilderAPI_ParameterOutOfRange", BRepBuilderAPI_EdgeError::BRepBuilderAPI_ParameterOutOfRange)
	.value("BRepBuilderAPI_DifferentPointsOnClosedCurve", BRepBuilderAPI_EdgeError::BRepBuilderAPI_DifferentPointsOnClosedCurve)
	.value("BRepBuilderAPI_PointWithInfiniteParameter", BRepBuilderAPI_EdgeError::BRepBuilderAPI_PointWithInfiniteParameter)
	.value("BRepBuilderAPI_DifferentsPointAndParameter", BRepBuilderAPI_EdgeError::BRepBuilderAPI_DifferentsPointAndParameter)
	.value("BRepBuilderAPI_LineThroughIdenticPoints", BRepBuilderAPI_EdgeError::BRepBuilderAPI_LineThroughIdenticPoints)
	.export_values();


// ENUM: BREPBUILDERAPI_FACEERROR
py::enum_<BRepBuilderAPI_FaceError>(mod, "BRepBuilderAPI_FaceError", "Indicates the outcome of the construction of a face, i.e. whether it has been successful or not, as explained below: - BRepBuilderAPI_FaceDone No error occurred. The face is correctly built. - BRepBuilderAPI_NoFace No initialization of the algorithm; only an empty constructor was used. - BRepBuilderAPI_NotPlanar No surface was given and the wire was not planar. - BRepBuilderAPI_CurveProjectionFailed Not used so far. - BRepBuilderAPI_ParametersOutOfRange The parameters given to limit the surface are out of its bounds.")
	.value("BRepBuilderAPI_FaceDone", BRepBuilderAPI_FaceError::BRepBuilderAPI_FaceDone)
	.value("BRepBuilderAPI_NoFace", BRepBuilderAPI_FaceError::BRepBuilderAPI_NoFace)
	.value("BRepBuilderAPI_NotPlanar", BRepBuilderAPI_FaceError::BRepBuilderAPI_NotPlanar)
	.value("BRepBuilderAPI_CurveProjectionFailed", BRepBuilderAPI_FaceError::BRepBuilderAPI_CurveProjectionFailed)
	.value("BRepBuilderAPI_ParametersOutOfRange", BRepBuilderAPI_FaceError::BRepBuilderAPI_ParametersOutOfRange)
	.export_values();


// ENUM: BREPBUILDERAPI_SHELLERROR
py::enum_<BRepBuilderAPI_ShellError>(mod, "BRepBuilderAPI_ShellError", "Indicates the outcome of the construction of a face, i.e. whether it is successful or not, as explained below: - BRepBuilderAPI_ShellDone No error occurred. The shell is correctly built. - BRepBuilderAPI_EmptyShell No initialization of the algorithm: only an empty constructor was used. - BRepBuilderAPI_DisconnectedShell not yet used - BRepBuilderAPI_ShellParametersOutOfRange The parameters given to limit the surface are out of its bounds.")
	.value("BRepBuilderAPI_ShellDone", BRepBuilderAPI_ShellError::BRepBuilderAPI_ShellDone)
	.value("BRepBuilderAPI_EmptyShell", BRepBuilderAPI_ShellError::BRepBuilderAPI_EmptyShell)
	.value("BRepBuilderAPI_DisconnectedShell", BRepBuilderAPI_ShellError::BRepBuilderAPI_DisconnectedShell)
	.value("BRepBuilderAPI_ShellParametersOutOfRange", BRepBuilderAPI_ShellError::BRepBuilderAPI_ShellParametersOutOfRange)
	.export_values();


// ENUM: BREPBUILDERAPI_WIREERROR
py::enum_<BRepBuilderAPI_WireError>(mod, "BRepBuilderAPI_WireError", "Indicates the outcome of wire construction, i.e. whether it is successful or not, as explained below: - BRepBuilderAPI_WireDone No error occurred. The wire is correctly built. - BRepBuilderAPI_EmptyWire No initialization of the algorithm. Only an empty constructor was used. - BRepBuilderAPI_DisconnectedWire The last edge which you attempted to add was not connected to the wire. - BRepBuilderAPI_NonManifoldWire The wire with some singularity.")
	.value("BRepBuilderAPI_WireDone", BRepBuilderAPI_WireError::BRepBuilderAPI_WireDone)
	.value("BRepBuilderAPI_EmptyWire", BRepBuilderAPI_WireError::BRepBuilderAPI_EmptyWire)
	.value("BRepBuilderAPI_DisconnectedWire", BRepBuilderAPI_WireError::BRepBuilderAPI_DisconnectedWire)
	.value("BRepBuilderAPI_NonManifoldWire", BRepBuilderAPI_WireError::BRepBuilderAPI_NonManifoldWire)
	.export_values();


// ENUM: BREPBUILDERAPI_PIPEERROR
py::enum_<BRepBuilderAPI_PipeError>(mod, "BRepBuilderAPI_PipeError", "Errors that can occur at (shell)pipe construction.")
	.value("BRepBuilderAPI_PipeDone", BRepBuilderAPI_PipeError::BRepBuilderAPI_PipeDone)
	.value("BRepBuilderAPI_PipeNotDone", BRepBuilderAPI_PipeError::BRepBuilderAPI_PipeNotDone)
	.value("BRepBuilderAPI_PlaneNotIntersectGuide", BRepBuilderAPI_PipeError::BRepBuilderAPI_PlaneNotIntersectGuide)
	.value("BRepBuilderAPI_ImpossibleContact", BRepBuilderAPI_PipeError::BRepBuilderAPI_ImpossibleContact)
	.export_values();


// ENUM: BREPBUILDERAPI_SHAPEMODIFICATION
py::enum_<BRepBuilderAPI_ShapeModification>(mod, "BRepBuilderAPI_ShapeModification", "Lists the possible types of modification to a shape following a topological operation: Preserved, Deleted, Trimmed, Merged or BoundaryModified. This enumeration enables you to assign a 'state' to the different shapes that are on the list of operands for each API function. The MakeShape class then uses this to determine what has happened to the shapes which constitute the list of operands.")
	.value("BRepBuilderAPI_Preserved", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_Preserved)
	.value("BRepBuilderAPI_Deleted", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_Deleted)
	.value("BRepBuilderAPI_Trimmed", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_Trimmed)
	.value("BRepBuilderAPI_Merged", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_Merged)
	.value("BRepBuilderAPI_BoundaryModified", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_BoundaryModified)
	.export_values();


// ENUM: BREPBUILDERAPI_TRANSITIONMODE
py::enum_<BRepBuilderAPI_TransitionMode>(mod, "BRepBuilderAPI_TransitionMode", "Option to manage discontinuities in Sweep")
	.value("BRepBuilderAPI_Transformed", BRepBuilderAPI_TransitionMode::BRepBuilderAPI_Transformed)
	.value("BRepBuilderAPI_RightCorner", BRepBuilderAPI_TransitionMode::BRepBuilderAPI_RightCorner)
	.value("BRepBuilderAPI_RoundCorner", BRepBuilderAPI_TransitionMode::BRepBuilderAPI_RoundCorner)
	.export_values();


// CLASS: BREPBUILDERAPI_COMMAND
py::class_<BRepBuilderAPI_Command> cls_BRepBuilderAPI_Command(mod, "BRepBuilderAPI_Command", "Root class for all commands in BRepBuilderAPI.");

// Methods
// cls_BRepBuilderAPI_Command.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_Command::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Command.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_Command::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Command.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_Command::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Command.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_Command::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Command.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_Command::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_Command.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_Command::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_Command.def("IsDone", (Standard_Boolean (BRepBuilderAPI_Command::*)() const) &BRepBuilderAPI_Command::IsDone, "None");
cls_BRepBuilderAPI_Command.def("Check", (void (BRepBuilderAPI_Command::*)() const) &BRepBuilderAPI_Command::Check, "Raises NotDone if done is false.");

// CLASS: BREPBUILDERAPI_MAKESHAPE
py::class_<BRepBuilderAPI_MakeShape, BRepBuilderAPI_Command> cls_BRepBuilderAPI_MakeShape(mod, "BRepBuilderAPI_MakeShape", "This is the root class for all shape constructions. It stores the result.");

// Methods
// cls_BRepBuilderAPI_MakeShape.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeShape::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeShape::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeShape.def("Build", (void (BRepBuilderAPI_MakeShape::*)()) &BRepBuilderAPI_MakeShape::Build, "This is called by Shape(). It does nothing but may be redefined.");
cls_BRepBuilderAPI_MakeShape.def("Shape", (const TopoDS_Shape & (BRepBuilderAPI_MakeShape::*)()) &BRepBuilderAPI_MakeShape::Shape, "Returns a shape built by the shape construction algorithm. Raises exception StdFail_NotDone if the shape was not built.");
cls_BRepBuilderAPI_MakeShape.def("Generated", (const TopTools_ListOfShape & (BRepBuilderAPI_MakeShape::*)(const TopoDS_Shape &)) &BRepBuilderAPI_MakeShape::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_MakeShape.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_MakeShape::*)(const TopoDS_Shape &)) &BRepBuilderAPI_MakeShape::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_MakeShape.def("IsDeleted", (Standard_Boolean (BRepBuilderAPI_MakeShape::*)(const TopoDS_Shape &)) &BRepBuilderAPI_MakeShape::IsDeleted, "Returns true if the shape S has been deleted.", py::arg("S"));

// CLASS: BREPBUILDERAPI
py::class_<BRepBuilderAPI> cls_BRepBuilderAPI(mod, "BRepBuilderAPI", "The BRepBuilderAPI package provides an Application Programming Interface for the BRep topology data structure.");

// Constructors
cls_BRepBuilderAPI.def(py::init<>());

// Methods
// cls_BRepBuilderAPI.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI.def_static("Plane_", (void (*)(const opencascade::handle<Geom_Plane> &)) &BRepBuilderAPI::Plane, "Sets the current plane.", py::arg("P"));
cls_BRepBuilderAPI.def_static("Plane_", (const opencascade::handle<Geom_Plane> & (*)()) &BRepBuilderAPI::Plane, "Returns the current plane.");
cls_BRepBuilderAPI.def_static("Precision_", (void (*)(const Standard_Real)) &BRepBuilderAPI::Precision, "Sets the default precision. The current Precision is returned.", py::arg("P"));
cls_BRepBuilderAPI.def_static("Precision_", (Standard_Real (*)()) &BRepBuilderAPI::Precision, "Returns the default precision.");

// TYPEDEF: BREPBUILDERAPI_BNDBOXTREE
bind_NCollection_UBTree<int, Bnd_Box>(mod, "BRepBuilderAPI_BndBoxTree", py::module_local(false));

// CLASS: BREPBUILDERAPI_BNDBOXTREESELECTOR
py::class_<BRepBuilderAPI_BndBoxTreeSelector, BRepBuilderAPI_BndBoxTree::Selector> cls_BRepBuilderAPI_BndBoxTreeSelector(mod, "BRepBuilderAPI_BndBoxTreeSelector", "Class BRepBuilderAPI_BndBoxTreeSelector derived from UBTree::Selector This class is used to select overlapping boxes, stored in NCollection::UBTree; contains methods to maintain the selection condition and to retrieve selected objects after search.");

// Constructors
cls_BRepBuilderAPI_BndBoxTreeSelector.def(py::init<>());

// Methods
cls_BRepBuilderAPI_BndBoxTreeSelector.def("Reject", (Standard_Boolean (BRepBuilderAPI_BndBoxTreeSelector::*)(const Bnd_Box &) const) &BRepBuilderAPI_BndBoxTreeSelector::Reject, "Implementation of rejection method", py::arg("theBox"));
cls_BRepBuilderAPI_BndBoxTreeSelector.def("Accept", (Standard_Boolean (BRepBuilderAPI_BndBoxTreeSelector::*)(const Standard_Integer &)) &BRepBuilderAPI_BndBoxTreeSelector::Accept, "Implementation of acceptance method This method is called when the bounding box intersect with the current. It stores the object - the index of box in the list of accepted objects.", py::arg("theObj"));
cls_BRepBuilderAPI_BndBoxTreeSelector.def("ClearResList", (void (BRepBuilderAPI_BndBoxTreeSelector::*)()) &BRepBuilderAPI_BndBoxTreeSelector::ClearResList, "Clear the list of intersecting boxes");
cls_BRepBuilderAPI_BndBoxTreeSelector.def("SetCurrent", (void (BRepBuilderAPI_BndBoxTreeSelector::*)(const Bnd_Box &)) &BRepBuilderAPI_BndBoxTreeSelector::SetCurrent, "Set current box to search for overlapping with him", py::arg("theBox"));
cls_BRepBuilderAPI_BndBoxTreeSelector.def("ResInd", (const TColStd_ListOfInteger & (BRepBuilderAPI_BndBoxTreeSelector::*)()) &BRepBuilderAPI_BndBoxTreeSelector::ResInd, "Get list of indexes of boxes intersecting with the current box");

// TYPEDEF: VECTOROFPOINT
bind_NCollection_Vector<gp_XYZ>(mod, "VectorOfPoint", py::module_local(false));

// CLASS: BREPBUILDERAPI_VERTEXINSPECTOR
py::class_<BRepBuilderAPI_VertexInspector, NCollection_CellFilter_InspectorXYZ> cls_BRepBuilderAPI_VertexInspector(mod, "BRepBuilderAPI_VertexInspector", "Class BRepBuilderAPI_VertexInspector derived from NCollection_CellFilter_InspectorXYZ This class define the Inspector interface for CellFilter algorithm, working with gp_XYZ points in 3d space. Used in search of coincidence points with a certain tolerance.");

// Constructors
cls_BRepBuilderAPI_VertexInspector.def(py::init<const Standard_Real>(), py::arg("theTol"));

// Methods
cls_BRepBuilderAPI_VertexInspector.def("Add", (void (BRepBuilderAPI_VertexInspector::*)(const gp_XYZ &)) &BRepBuilderAPI_VertexInspector::Add, "Keep the points used for comparison", py::arg("thePnt"));
cls_BRepBuilderAPI_VertexInspector.def("ClearResList", (void (BRepBuilderAPI_VertexInspector::*)()) &BRepBuilderAPI_VertexInspector::ClearResList, "Clear the list of adjacent points");
cls_BRepBuilderAPI_VertexInspector.def("SetCurrent", (void (BRepBuilderAPI_VertexInspector::*)(const gp_XYZ &)) &BRepBuilderAPI_VertexInspector::SetCurrent, "Set current point to search for coincidence", py::arg("theCurPnt"));
cls_BRepBuilderAPI_VertexInspector.def("ResInd", (const TColStd_ListOfInteger & (BRepBuilderAPI_VertexInspector::*)()) &BRepBuilderAPI_VertexInspector::ResInd, "Get list of indexes of points adjacent with the current");
cls_BRepBuilderAPI_VertexInspector.def("Inspect", (NCollection_CellFilter_Action (BRepBuilderAPI_VertexInspector::*)(const Standard_Integer)) &BRepBuilderAPI_VertexInspector::Inspect, "Implementation of inspection method", py::arg("theTarget"));

// TYPEDEF: BREPBUILDERAPI_CELLFILTER
/*
bind_NCollection_CellFilter<BRepBuilderAPI_VertexInspector>(mod, "BRepBuilderAPI_CellFilter", py::module_local(false));
*/

// CLASS: BREPBUILDERAPI_COLLECT
py::class_<BRepBuilderAPI_Collect> cls_BRepBuilderAPI_Collect(mod, "BRepBuilderAPI_Collect", "None");

// Constructors
cls_BRepBuilderAPI_Collect.def(py::init<>());

// Methods
// cls_BRepBuilderAPI_Collect.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_Collect::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Collect.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_Collect::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Collect.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_Collect::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Collect.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_Collect::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Collect.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_Collect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_Collect.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_Collect::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_Collect.def("Add", (void (BRepBuilderAPI_Collect::*)(const TopoDS_Shape &, BRepBuilderAPI_MakeShape &)) &BRepBuilderAPI_Collect::Add, "None", py::arg("SI"), py::arg("MKS"));
cls_BRepBuilderAPI_Collect.def("AddGenerated", (void (BRepBuilderAPI_Collect::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepBuilderAPI_Collect::AddGenerated, "None", py::arg("S"), py::arg("Gen"));
cls_BRepBuilderAPI_Collect.def("AddModif", (void (BRepBuilderAPI_Collect::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepBuilderAPI_Collect::AddModif, "None", py::arg("S"), py::arg("Mod"));
cls_BRepBuilderAPI_Collect.def("Filter", (void (BRepBuilderAPI_Collect::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Collect::Filter, "None", py::arg("SF"));
cls_BRepBuilderAPI_Collect.def("Modification", (const TopTools_DataMapOfShapeListOfShape & (BRepBuilderAPI_Collect::*)() const) &BRepBuilderAPI_Collect::Modification, "None");
cls_BRepBuilderAPI_Collect.def("Generated", (const TopTools_DataMapOfShapeListOfShape & (BRepBuilderAPI_Collect::*)() const) &BRepBuilderAPI_Collect::Generated, "None");

// CLASS: BREPBUILDERAPI_MODIFYSHAPE
py::class_<BRepBuilderAPI_ModifyShape, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_ModifyShape(mod, "BRepBuilderAPI_ModifyShape", "Implements the methods of MakeShape for the constant topology modifications. The methods are implemented when the modification uses a Modifier from BRepTools. Some of them have to be redefined if the modification is implemented with another tool (see Transform from BRepBuilderAPI for example). The BRepBuilderAPI package provides the following frameworks to perform modifications of this sort: - BRepBuilderAPI_Copy to produce the copy of a shape, - BRepBuilderAPI_Transform and BRepBuilderAPI_GTransform to apply a geometric transformation to a shape, - BRepBuilderAPI_NurbsConvert to convert the whole geometry of a shape into NURBS geometry, - BRepOffsetAPI_DraftAngle to build a tapered shape.");

// Methods
// cls_BRepBuilderAPI_ModifyShape.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_ModifyShape::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_ModifyShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_ModifyShape::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_ModifyShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_ModifyShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_ModifyShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_ModifyShape.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_ModifyShape::*)(const TopoDS_Shape &)) &BRepBuilderAPI_ModifyShape::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_ModifyShape.def("ModifiedShape", (TopoDS_Shape (BRepBuilderAPI_ModifyShape::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_ModifyShape::ModifiedShape, "Returns the modified shape corresponding to <S>. S can correspond to the entire initial shape or to its subshape. Exceptions Standard_NoSuchObject if S is not the initial shape or a subshape of the initial shape to which the transformation has been applied. Raises NoSuchObject from Standard if S is not the initial shape or a sub-shape of the initial shape.", py::arg("S"));

// CLASS: BREPBUILDERAPI_COPY
py::class_<BRepBuilderAPI_Copy, BRepBuilderAPI_ModifyShape> cls_BRepBuilderAPI_Copy(mod, "BRepBuilderAPI_Copy", "Duplication of a shape. A Copy object provides a framework for: - defining the construction of a duplicate shape, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_Copy.def(py::init<>());
cls_BRepBuilderAPI_Copy.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepBuilderAPI_Copy.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S"), py::arg("copyGeom"));
cls_BRepBuilderAPI_Copy.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("copyGeom"), py::arg("copyMesh"));

// Methods
// cls_BRepBuilderAPI_Copy.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_Copy::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Copy.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_Copy::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Copy.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_Copy::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Copy.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_Copy::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Copy.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_Copy::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_Copy.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_Copy::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_Copy.def("Perform", [](BRepBuilderAPI_Copy &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepBuilderAPI_Copy.def("Perform", [](BRepBuilderAPI_Copy &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Perform(a0, a1); });
cls_BRepBuilderAPI_Copy.def("Perform", (void (BRepBuilderAPI_Copy::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepBuilderAPI_Copy::Perform, "Copies the shape S. Use the function Shape to access the result. If copyMesh is True, triangulation contained in original shape will be copied along with geometry (by default, triangulation gets lost). If copyGeom is False, only topological objects will be copied, while geometry and triangulation will be shared with original shape.", py::arg("S"), py::arg("copyGeom"), py::arg("copyMesh"));

// CLASS: BREPBUILDERAPI_FASTSEWING
py::class_<BRepBuilderAPI_FastSewing, opencascade::handle<BRepBuilderAPI_FastSewing>, Standard_Transient> cls_BRepBuilderAPI_FastSewing(mod, "BRepBuilderAPI_FastSewing", "This class performs fast sewing of surfaces (faces). It supposes that all surfaces are finite and are naturally restricted by their bounds. Moreover, it supposes that stitched together surfaces have the same parameterization along common boundaries, therefore it does not perform time-consuming check for SameParameter property of edges.");

// Constructors
cls_BRepBuilderAPI_FastSewing.def(py::init<>());
cls_BRepBuilderAPI_FastSewing.def(py::init<const Standard_Real>(), py::arg("theTolerance"));

// Methods
cls_BRepBuilderAPI_FastSewing.def("Add", (Standard_Boolean (BRepBuilderAPI_FastSewing::*)(const TopoDS_Shape &)) &BRepBuilderAPI_FastSewing::Add, "Adds faces of a shape", py::arg("theShape"));
cls_BRepBuilderAPI_FastSewing.def("Add", (Standard_Boolean (BRepBuilderAPI_FastSewing::*)(const opencascade::handle<Geom_Surface> &)) &BRepBuilderAPI_FastSewing::Add, "Adds a surface", py::arg("theSurface"));
cls_BRepBuilderAPI_FastSewing.def("Perform", (void (BRepBuilderAPI_FastSewing::*)()) &BRepBuilderAPI_FastSewing::Perform, "Compute resulted shape");
cls_BRepBuilderAPI_FastSewing.def("SetTolerance", (void (BRepBuilderAPI_FastSewing::*)(const Standard_Real)) &BRepBuilderAPI_FastSewing::SetTolerance, "Sets tolerance", py::arg("theToler"));
cls_BRepBuilderAPI_FastSewing.def("GetTolerance", (Standard_Real (BRepBuilderAPI_FastSewing::*)() const) &BRepBuilderAPI_FastSewing::GetTolerance, "Returns tolerance");
cls_BRepBuilderAPI_FastSewing.def("GetResult", (const TopoDS_Shape & (BRepBuilderAPI_FastSewing::*)() const) &BRepBuilderAPI_FastSewing::GetResult, "Returns resulted shape");
cls_BRepBuilderAPI_FastSewing.def("GetStatuses", [](BRepBuilderAPI_FastSewing &self) -> BRepBuilderAPI_FastSewing::FS_VARStatuses { return self.GetStatuses(); });
cls_BRepBuilderAPI_FastSewing.def("GetStatuses", (BRepBuilderAPI_FastSewing::FS_VARStatuses (BRepBuilderAPI_FastSewing::*)(Standard_OStream *const)) &BRepBuilderAPI_FastSewing::GetStatuses, "Returns list of statuses. Print message if theOS != 0", py::arg("theOS"));
cls_BRepBuilderAPI_FastSewing.def_static("get_type_name_", (const char * (*)()) &BRepBuilderAPI_FastSewing::get_type_name, "None");
cls_BRepBuilderAPI_FastSewing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBuilderAPI_FastSewing::get_type_descriptor, "None");
cls_BRepBuilderAPI_FastSewing.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBuilderAPI_FastSewing::*)() const) &BRepBuilderAPI_FastSewing::DynamicType, "None");

// Enums
py::enum_<BRepBuilderAPI_FastSewing::FS_Statuses>(cls_BRepBuilderAPI_FastSewing, "FS_Statuses", "Enumeration of result statuses")
	.value("FS_OK", BRepBuilderAPI_FastSewing::FS_Statuses::FS_OK)
	.value("FS_Degenerated", BRepBuilderAPI_FastSewing::FS_Statuses::FS_Degenerated)
	.value("FS_FindVertexError", BRepBuilderAPI_FastSewing::FS_Statuses::FS_FindVertexError)
	.value("FS_FindEdgeError", BRepBuilderAPI_FastSewing::FS_Statuses::FS_FindEdgeError)
	.value("FS_FaceWithNullSurface", BRepBuilderAPI_FastSewing::FS_Statuses::FS_FaceWithNullSurface)
	.value("FS_NotNaturalBoundsFace", BRepBuilderAPI_FastSewing::FS_Statuses::FS_NotNaturalBoundsFace)
	.value("FS_InfiniteSurface", BRepBuilderAPI_FastSewing::FS_Statuses::FS_InfiniteSurface)
	.value("FS_EmptyInput", BRepBuilderAPI_FastSewing::FS_Statuses::FS_EmptyInput)
	.value("FS_Exception", BRepBuilderAPI_FastSewing::FS_Statuses::FS_Exception)
	.export_values();

// CLASS: BREPBUILDERAPI_FINDPLANE
py::class_<BRepBuilderAPI_FindPlane> cls_BRepBuilderAPI_FindPlane(mod, "BRepBuilderAPI_FindPlane", "Describes functions to find the plane in which the edges of a given shape are located. A FindPlane object provides a framework for: - extracting the edges of a given shape, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_FindPlane.def(py::init<>());
cls_BRepBuilderAPI_FindPlane.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepBuilderAPI_FindPlane.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("S"), py::arg("Tol"));

// Methods
// cls_BRepBuilderAPI_FindPlane.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_FindPlane::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_FindPlane::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_FindPlane::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_FindPlane::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_FindPlane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_FindPlane::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_FindPlane.def("Init", [](BRepBuilderAPI_FindPlane &self, const TopoDS_Shape & a0) -> void { return self.Init(a0); });
cls_BRepBuilderAPI_FindPlane.def("Init", (void (BRepBuilderAPI_FindPlane::*)(const TopoDS_Shape &, const Standard_Real)) &BRepBuilderAPI_FindPlane::Init, "Constructs the plane containing the edges of the shape S. A plane is built only if all the edges are within a distance of less than or equal to tolerance from a planar surface. This tolerance value is equal to the larger of the following two values: - Tol, where the default value is negative, or - the largest of the tolerance values assigned to the individual edges of S. Use the function Found to verify that a plane is built. The resulting plane is then retrieved using the function Plane.", py::arg("S"), py::arg("Tol"));
cls_BRepBuilderAPI_FindPlane.def("Found", (Standard_Boolean (BRepBuilderAPI_FindPlane::*)() const) &BRepBuilderAPI_FindPlane::Found, "Returns true if a plane containing the edges of the shape is found and built. Use the function Plane to consult the result.");
cls_BRepBuilderAPI_FindPlane.def("Plane", (opencascade::handle<Geom_Plane> (BRepBuilderAPI_FindPlane::*)() const) &BRepBuilderAPI_FindPlane::Plane, "Returns the plane containing the edges of the shape. Warning Use the function Found to verify that the plane is built. If a plane is not found, Plane returns a null handle.");

// CLASS: BREPBUILDERAPI_GTRANSFORM
py::class_<BRepBuilderAPI_GTransform, BRepBuilderAPI_ModifyShape> cls_BRepBuilderAPI_GTransform(mod, "BRepBuilderAPI_GTransform", "Geometric transformation on a shape. The transformation to be applied is defined as a gp_GTrsf transformation. It may be: - a transformation equivalent to a gp_Trsf transformation, the most common case: you should , however, use a BRepAPI_Transform object to perform this kind of transformation; or - an affinity, or - more generally, any type of point transformation which may be defined by a three row, four column matrix of transformation. In the last two cases, the underlying geometry of the following shapes may change: - a curve which supports an edge of the shape, or - a surface which supports a face of the shape; For example, a circle may be transformed into an ellipse when applying an affinity transformation. The transformation is applied to: - all the curves which support edges of the shape, and - all the surfaces which support faces of the shape. A GTransform object provides a framework for: - defining the geometric transformation to be applied, - implementing the transformation algorithm, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_GTransform.def(py::init<const gp_GTrsf &>(), py::arg("T"));
cls_BRepBuilderAPI_GTransform.def(py::init<const TopoDS_Shape &, const gp_GTrsf &>(), py::arg("S"), py::arg("T"));
cls_BRepBuilderAPI_GTransform.def(py::init<const TopoDS_Shape &, const gp_GTrsf &, const Standard_Boolean>(), py::arg("S"), py::arg("T"), py::arg("Copy"));

// Methods
// cls_BRepBuilderAPI_GTransform.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_GTransform::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_GTransform.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_GTransform::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_GTransform.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_GTransform::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_GTransform.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_GTransform::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_GTransform.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_GTransform::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_GTransform.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_GTransform::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_GTransform.def("Perform", [](BRepBuilderAPI_GTransform &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepBuilderAPI_GTransform.def("Perform", (void (BRepBuilderAPI_GTransform::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepBuilderAPI_GTransform::Perform, "Applies the geometric transformation defined at the time of construction of this framework to the shape S. - If the transformation T is direct and isometric (i.e. if the determinant of the vectorial part of T is equal to 1.), and if Copy equals false (default value), the resulting shape is the same as the original but with a new location assigned to it. - In all other cases, the transformation is applied to a duplicate of S. Use the function Shape to access the result. Note: this framework can be reused to apply the same geometric transformation to other shapes: just specify them by calling the function Perform again.", py::arg("S"), py::arg("Copy"));
cls_BRepBuilderAPI_GTransform.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_GTransform::*)(const TopoDS_Shape &)) &BRepBuilderAPI_GTransform::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_GTransform.def("ModifiedShape", (TopoDS_Shape (BRepBuilderAPI_GTransform::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_GTransform::ModifiedShape, "Returns the modified shape corresponding to <S>.", py::arg("S"));

// CLASS: BREPBUILDERAPI_MAKEEDGE
py::class_<BRepBuilderAPI_MakeEdge, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeEdge(mod, "BRepBuilderAPI_MakeEdge", "Provides methods to build edges.");

// Constructors
cls_BRepBuilderAPI_MakeEdge.def(py::init<>());
cls_BRepBuilderAPI_MakeEdge.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Lin &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Lin &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Lin &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Circ &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Circ &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Circ &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Circ &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Elips &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Elips &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Elips &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Elips &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Hypr &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Hypr &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Hypr &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Hypr &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Parab &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Parab &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Parab &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const gp_Parab &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &>(), py::arg("L"), py::arg("S"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));

// Methods
// cls_BRepBuilderAPI_MakeEdge.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeEdge::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeEdge::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeEdge::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeEdge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeEdge.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "None", py::arg("C"), py::arg("S"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("Init", (void (BRepBuilderAPI_MakeEdge::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge::Init, "Defines or redefines the arguments for the construction of an edge. This function is currently used after the empty constructor BRepAPI_MakeEdge().", py::arg("C"), py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeEdge::*)() const) &BRepBuilderAPI_MakeEdge::IsDone, "Returns true if the edge is built.");
cls_BRepBuilderAPI_MakeEdge.def("Error", (BRepBuilderAPI_EdgeError (BRepBuilderAPI_MakeEdge::*)() const) &BRepBuilderAPI_MakeEdge::Error, "Returns the construction status - BRepBuilderAPI_EdgeDone if the edge is built, or - another value of the BRepBuilderAPI_EdgeError enumeration indicating the reason of construction failure.");
cls_BRepBuilderAPI_MakeEdge.def("Edge", (const TopoDS_Edge & (BRepBuilderAPI_MakeEdge::*)()) &BRepBuilderAPI_MakeEdge::Edge, "Returns the constructed edge. Exceptions StdFail_NotDone if the edge is not built.");
cls_BRepBuilderAPI_MakeEdge.def("Vertex1", (const TopoDS_Vertex & (BRepBuilderAPI_MakeEdge::*)() const) &BRepBuilderAPI_MakeEdge::Vertex1, "Returns the first vertex of the edge. May be Null.");
cls_BRepBuilderAPI_MakeEdge.def("Vertex2", (const TopoDS_Vertex & (BRepBuilderAPI_MakeEdge::*)() const) &BRepBuilderAPI_MakeEdge::Vertex2, "Returns the second vertex of the edge. May be Null.");

// CLASS: BREPBUILDERAPI_MAKEEDGE2D
py::class_<BRepBuilderAPI_MakeEdge2d, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeEdge2d(mod, "BRepBuilderAPI_MakeEdge2d", "Provides methods to build edges.");

// Constructors
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Lin2d &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Lin2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Lin2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Circ2d &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Circ2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Elips2d &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Elips2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Elips2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Elips2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Hypr2d &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Hypr2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Hypr2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Hypr2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Parab2d &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Parab2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Parab2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const gp_Parab2d &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("L"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("L"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("L"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));

// Methods
// cls_BRepBuilderAPI_MakeEdge2d.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeEdge2d::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeEdge2d.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeEdge2d::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeEdge2d.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeEdge2d::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeEdge2d.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeEdge2d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeEdge2d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeEdge2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeEdge2d.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeEdge2d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeEdge2d.def("Init", (void (BRepBuilderAPI_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &)) &BRepBuilderAPI_MakeEdge2d::Init, "None", py::arg("C"));
cls_BRepBuilderAPI_MakeEdge2d.def("Init", (void (BRepBuilderAPI_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge2d::Init, "None", py::arg("C"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def("Init", (void (BRepBuilderAPI_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &)) &BRepBuilderAPI_MakeEdge2d::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakeEdge2d.def("Init", (void (BRepBuilderAPI_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &BRepBuilderAPI_MakeEdge2d::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakeEdge2d.def("Init", (void (BRepBuilderAPI_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge2d::Init, "None", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def("Init", (void (BRepBuilderAPI_MakeEdge2d::*)(const opencascade::handle<Geom2d_Curve> &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeEdge2d::Init, "None", py::arg("C"), py::arg("V1"), py::arg("V2"), py::arg("p1"), py::arg("p2"));
cls_BRepBuilderAPI_MakeEdge2d.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeEdge2d::*)() const) &BRepBuilderAPI_MakeEdge2d::IsDone, "None");
cls_BRepBuilderAPI_MakeEdge2d.def("Error", (BRepBuilderAPI_EdgeError (BRepBuilderAPI_MakeEdge2d::*)() const) &BRepBuilderAPI_MakeEdge2d::Error, "Returns the error description when NotDone.");
cls_BRepBuilderAPI_MakeEdge2d.def("Edge", (const TopoDS_Edge & (BRepBuilderAPI_MakeEdge2d::*)()) &BRepBuilderAPI_MakeEdge2d::Edge, "None");
cls_BRepBuilderAPI_MakeEdge2d.def("Vertex1", (const TopoDS_Vertex & (BRepBuilderAPI_MakeEdge2d::*)() const) &BRepBuilderAPI_MakeEdge2d::Vertex1, "Returns the first vertex of the edge. May be Null.");
cls_BRepBuilderAPI_MakeEdge2d.def("Vertex2", (const TopoDS_Vertex & (BRepBuilderAPI_MakeEdge2d::*)() const) &BRepBuilderAPI_MakeEdge2d::Vertex2, "Returns the second vertex of the edge. May be Null.");

// CLASS: BREPBUILDERAPI_MAKEFACE
py::class_<BRepBuilderAPI_MakeFace, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeFace(mod, "BRepBuilderAPI_MakeFace", "Provides methods to build faces.");

// Constructors
cls_BRepBuilderAPI_MakeFace.def(py::init<>());
cls_BRepBuilderAPI_MakeFace.def(py::init<const TopoDS_Face &>(), py::arg("F"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Pln &>(), py::arg("P"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cylinder &>(), py::arg("C"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cone &>(), py::arg("C"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Sphere &>(), py::arg("S"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Torus &>(), py::arg("C"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S"), py::arg("TolDegen"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Pln &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("W"), py::arg("OnlyPlane"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &>(), py::arg("P"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Pln &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("P"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cylinder &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Cone &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Sphere &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &>(), py::arg("C"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const gp_Torus &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("C"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &>(), py::arg("S"), py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Wire &, const Standard_Boolean>(), py::arg("S"), py::arg("W"), py::arg("Inside"));
cls_BRepBuilderAPI_MakeFace.def(py::init<const TopoDS_Face &, const TopoDS_Wire &>(), py::arg("F"), py::arg("W"));

// Methods
// cls_BRepBuilderAPI_MakeFace.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeFace::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeFace::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeFace::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeFace::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeFace.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeFace::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeFace.def("Init", (void (BRepBuilderAPI_MakeFace::*)(const TopoDS_Face &)) &BRepBuilderAPI_MakeFace::Init, "Initializes (or reinitializes) the construction of a face by creating a new object which is a copy of the face F, in order to add wires to it, using the function Add. Note: this complete copy of the geometry is only required if you want to work on the geometries of the two faces independently.", py::arg("F"));
cls_BRepBuilderAPI_MakeFace.def("Init", (void (BRepBuilderAPI_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Boolean, const Standard_Real)) &BRepBuilderAPI_MakeFace::Init, "Initializes (or reinitializes) the construction of a face on the surface S. If Bound is true, a wire is automatically created from the natural bounds of the surface S and added to the face in order to bound it. If Bound is false, no wire is added. This option is used when real bounds are known. These will be added to the face after this initialization, using the function Add. TolDegen parameter is used for resolution of degenerated edges if calculation of natural bounds is turned on.", py::arg("S"), py::arg("Bound"), py::arg("TolDegen"));
cls_BRepBuilderAPI_MakeFace.def("Init", (void (BRepBuilderAPI_MakeFace::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepBuilderAPI_MakeFace::Init, "Initializes (or reinitializes) the construction of a face on the surface S, limited in the u parametric direction by the two parameter values UMin and UMax and in the v parametric direction by the two parameter values VMin and VMax. Warning Error returns: - BRepBuilderAPI_ParametersOutOfRange when the parameters given are outside the bounds of the surface or the basis surface of a trimmed surface. TolDegen parameter is used for resolution of degenerated edges.", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("TolDegen"));
cls_BRepBuilderAPI_MakeFace.def("Add", (void (BRepBuilderAPI_MakeFace::*)(const TopoDS_Wire &)) &BRepBuilderAPI_MakeFace::Add, "Adds the wire W to the constructed face as a hole. Warning W must not cross the other bounds of the face, and all the bounds must define only one area on the surface. (Be careful, however, as this is not checked.) Example // a cylinder gp_Cylinder C = ..; // a wire TopoDS_Wire W = ...; BRepBuilderAPI_MakeFace MF(C); MF.Add(W); TopoDS_Face F = MF;", py::arg("W"));
cls_BRepBuilderAPI_MakeFace.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeFace::*)() const) &BRepBuilderAPI_MakeFace::IsDone, "Returns true if this algorithm has a valid face.");
cls_BRepBuilderAPI_MakeFace.def("Error", (BRepBuilderAPI_FaceError (BRepBuilderAPI_MakeFace::*)() const) &BRepBuilderAPI_MakeFace::Error, "Returns the construction status BRepBuilderAPI_FaceDone if the face is built, or - another value of the BRepBuilderAPI_FaceError enumeration indicating why the construction failed, in particular when the given parameters are outside the bounds of the surface.");
cls_BRepBuilderAPI_MakeFace.def("Face", (const TopoDS_Face & (BRepBuilderAPI_MakeFace::*)() const) &BRepBuilderAPI_MakeFace::Face, "Returns the constructed face. Exceptions StdFail_NotDone if no face is built.");

// CLASS: BREPBUILDERAPI_MAKEPOLYGON
py::class_<BRepBuilderAPI_MakePolygon, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakePolygon(mod, "BRepBuilderAPI_MakePolygon", "Describes functions to build polygonal wires. A polygonal wire can be built from any number of points or vertices, and consists of a sequence of connected rectilinear edges. When a point or vertex is added to the polygon if it is identic to the previous point no edge is built. The method added can be used to test it. Construction of a Polygonal Wire You can construct: - a complete polygonal wire by defining all its points or vertices (limited to four), or - an empty polygonal wire and add its points or vertices in sequence (unlimited number). A MakePolygon object provides a framework for: - initializing the construction of a polygonal wire, - adding points or vertices to the polygonal wire under construction, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_MakePolygon.def(py::init<>());
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("Close"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("Close"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("Close"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"));
cls_BRepBuilderAPI_MakePolygon.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Boolean>(), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("Close"));

// Methods
// cls_BRepBuilderAPI_MakePolygon.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakePolygon::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakePolygon::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakePolygon::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakePolygon::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakePolygon::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakePolygon.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakePolygon::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakePolygon.def("Add", (void (BRepBuilderAPI_MakePolygon::*)(const gp_Pnt &)) &BRepBuilderAPI_MakePolygon::Add, "None", py::arg("P"));
cls_BRepBuilderAPI_MakePolygon.def("Add", (void (BRepBuilderAPI_MakePolygon::*)(const TopoDS_Vertex &)) &BRepBuilderAPI_MakePolygon::Add, "Adds the point P or the vertex V at the end of the polygonal wire under construction. A vertex is automatically created on the point P. Warning - When P or V is coincident to the previous vertex, no edge is built. The method Added can be used to test for this. Neither P nor V is checked to verify that it is coincident with another vertex than the last one, of the polygonal wire under construction. It is also possible to add vertices on a closed polygon (built for example by using a constructor which declares the polygon closed, or after the use of the Close function). Consequently, be careful using this function: you might create: - a polygonal wire with two consecutive coincident edges, or - a non manifold polygonal wire. - P or V is not checked to verify if it is coincident with another vertex but the last one, of the polygonal wire under construction. It is also possible to add vertices on a closed polygon (built for example by using a constructor which declares the polygon closed, or after the use of the Close function). Consequently, be careful when using this function: you might create: - a polygonal wire with two consecutive coincident edges, or - a non-manifold polygonal wire.", py::arg("V"));
cls_BRepBuilderAPI_MakePolygon.def("Added", (Standard_Boolean (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::Added, "Returns true if the last vertex added to the constructed polygonal wire is not coincident with the previous one.");
cls_BRepBuilderAPI_MakePolygon.def("Close", (void (BRepBuilderAPI_MakePolygon::*)()) &BRepBuilderAPI_MakePolygon::Close, "Closes the polygonal wire under construction. Note - this is equivalent to adding the first vertex to the polygonal wire under construction.");
cls_BRepBuilderAPI_MakePolygon.def("FirstVertex", (const TopoDS_Vertex & (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::FirstVertex, "None");
cls_BRepBuilderAPI_MakePolygon.def("LastVertex", (const TopoDS_Vertex & (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::LastVertex, "Returns the first or the last vertex of the polygonal wire under construction. If the constructed polygonal wire is closed, the first and the last vertices are identical.");
cls_BRepBuilderAPI_MakePolygon.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::IsDone, "Returns true if this algorithm contains a valid polygonal wire (i.e. if there is at least one edge). IsDone returns false if fewer than two vertices have been chained together by this construction algorithm.");
cls_BRepBuilderAPI_MakePolygon.def("Edge", (const TopoDS_Edge & (BRepBuilderAPI_MakePolygon::*)() const) &BRepBuilderAPI_MakePolygon::Edge, "Returns the edge built between the last two points or vertices added to the constructed polygonal wire under construction. Warning If there is only one vertex in the polygonal wire, the result is a null edge.");
cls_BRepBuilderAPI_MakePolygon.def("Wire", (const TopoDS_Wire & (BRepBuilderAPI_MakePolygon::*)()) &BRepBuilderAPI_MakePolygon::Wire, "Returns the constructed polygonal wire, or the already built part of the polygonal wire under construction. Exceptions StdFail_NotDone if the wire is not built, i.e. if fewer than two vertices have been chained together by this construction algorithm.");

// CLASS: BREPBUILDERAPI_MAKESHELL
py::class_<BRepBuilderAPI_MakeShell, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeShell(mod, "BRepBuilderAPI_MakeShell", "Describes functions to build a shape corresponding to the skin of a surface. Note that the term shell in the class name has the same definition as that of a shell in STEP, in other words the skin of a shape, and not a solid model defined by surface and thickness. If you want to build the second sort of shell, you must use BRepOffsetAPI_MakeOffsetShape. A shell is made of a series of faces connected by their common edges. If the underlying surface of a face is not C2 continuous and the flag Segment is True, MakeShell breaks the surface down into several faces which are all C2 continuous and which are connected along the non-regular curves on the surface. The resulting shell contains all these faces. Construction of a Shell from a non-C2 continuous Surface A MakeShell object provides a framework for: - defining the construction of a shell, - implementing the construction algorithm, and - consulting the result. Warning The connected C2 faces in the shell resulting from a decomposition of the surface are not sewn. For a sewn result, you need to use BRepOffsetAPI_Sewing. For a shell with thickness, you need to use BRepOffsetAPI_MakeOffsetShape.");

// Constructors
cls_BRepBuilderAPI_MakeShell.def(py::init<>());
cls_BRepBuilderAPI_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
cls_BRepBuilderAPI_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S"), py::arg("Segment"));
cls_BRepBuilderAPI_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_BRepBuilderAPI_MakeShell.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));

// Methods
// cls_BRepBuilderAPI_MakeShell.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeShell::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeShell::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeShell::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeShell::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeShell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeShell.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeShell::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeShell.def("Init", [](BRepBuilderAPI_MakeShell &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_BRepBuilderAPI_MakeShell.def("Init", (void (BRepBuilderAPI_MakeShell::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBuilderAPI_MakeShell::Init, "Defines or redefines the arguments for the construction of a shell. The construction is initialized with the surface S, limited in the u parametric direction by the two parameter values UMin and UMax, and in the v parametric direction by the two parameter values VMin and VMax. Warning The function Error returns: - BRepBuilderAPI_ShellParametersOutOfRange when the given parameters are outside the bounds of the surface or the basis surface if S is trimmed", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Segment"));
cls_BRepBuilderAPI_MakeShell.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeShell::*)() const) &BRepBuilderAPI_MakeShell::IsDone, "Returns true if the shell is built.");
cls_BRepBuilderAPI_MakeShell.def("Error", (BRepBuilderAPI_ShellError (BRepBuilderAPI_MakeShell::*)() const) &BRepBuilderAPI_MakeShell::Error, "Returns the construction status: - BRepBuilderAPI_ShellDone if the shell is built, or - another value of the BRepBuilderAPI_ShellError enumeration indicating why the construction failed. This is frequently BRepBuilderAPI_ShellParametersOutOfRange indicating that the given parameters are outside the bounds of the surface.");
cls_BRepBuilderAPI_MakeShell.def("Shell", (const TopoDS_Shell & (BRepBuilderAPI_MakeShell::*)() const) &BRepBuilderAPI_MakeShell::Shell, "Returns the new Shell.");

// CLASS: BREPBUILDERAPI_MAKESOLID
py::class_<BRepBuilderAPI_MakeSolid, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeSolid(mod, "BRepBuilderAPI_MakeSolid", "Describes functions to build a solid from shells. A solid is made of one shell, or a series of shells, which do not intersect each other. One of these shells constitutes the outside skin of the solid. It may be closed (a finite solid) or open (an infinite solid). Other shells form hollows (cavities) in these previous ones. Each must bound a closed volume. A MakeSolid object provides a framework for: - defining and implementing the construction of a solid, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_MakeSolid.def(py::init<>());
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_CompSolid &>(), py::arg("S"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Shell &>(), py::arg("S"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"), py::arg("S3"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Solid &>(), py::arg("So"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Solid &, const TopoDS_Shell &>(), py::arg("So"), py::arg("S"));

// Methods
// cls_BRepBuilderAPI_MakeSolid.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeSolid::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeSolid::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeSolid::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeSolid::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeSolid.def("Add", (void (BRepBuilderAPI_MakeSolid::*)(const TopoDS_Shell &)) &BRepBuilderAPI_MakeSolid::Add, "Adds the shell to the current solid. Warning No check is done to verify the conditions of coherence of the resulting solid. In particular, S must not intersect other shells of the solid under construction. Besides, after all shells have been added, one of these shells should constitute the outside skin of the solid. It may be closed (a finite solid) or open (an infinite solid). Other shells form hollows (cavities) in these previous ones. Each must bound a closed volume.", py::arg("S"));
cls_BRepBuilderAPI_MakeSolid.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeSolid::*)() const) &BRepBuilderAPI_MakeSolid::IsDone, "Returns true if the solid is built. For this class, a solid under construction is always valid. If no shell has been added, it could be a whole-space solid. However, no check was done to verify the conditions of coherence of the resulting solid.");
cls_BRepBuilderAPI_MakeSolid.def("Solid", (const TopoDS_Solid & (BRepBuilderAPI_MakeSolid::*)()) &BRepBuilderAPI_MakeSolid::Solid, "Returns the new Solid.");
cls_BRepBuilderAPI_MakeSolid.def("IsDeleted", (Standard_Boolean (BRepBuilderAPI_MakeSolid::*)(const TopoDS_Shape &)) &BRepBuilderAPI_MakeSolid::IsDeleted, "None", py::arg("S"));

// CLASS: BREPBUILDERAPI_MAKEVERTEX
py::class_<BRepBuilderAPI_MakeVertex, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeVertex(mod, "BRepBuilderAPI_MakeVertex", "Describes functions to build BRepBuilder vertices directly from 3D geometric points. A vertex built using a MakeVertex object is only composed of a 3D point and a default precision value (Precision::Confusion()). Later on, 2D representations can be added, for example, when inserting a vertex in an edge. A MakeVertex object provides a framework for: - defining and implementing the construction of a vertex, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_MakeVertex.def(py::init<const gp_Pnt &>(), py::arg("P"));

// Methods
// cls_BRepBuilderAPI_MakeVertex.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeVertex::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeVertex::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeVertex::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeVertex::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeVertex.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeVertex.def("Vertex", (const TopoDS_Vertex & (BRepBuilderAPI_MakeVertex::*)()) &BRepBuilderAPI_MakeVertex::Vertex, "Returns the constructed vertex.");

// CLASS: BREPBUILDERAPI_MAKEWIRE
py::class_<BRepBuilderAPI_MakeWire, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeWire(mod, "BRepBuilderAPI_MakeWire", "Describes functions to build wires from edges. A wire can be built from any number of edges. To build a wire you first initialize the construction, then add edges in sequence. An unlimited number of edges can be added. The initialization of construction is done with: - no edge (an empty wire), or - edges of an existing wire, or - up to four connectable edges. In order to be added to a wire under construction, an edge (unless it is the first one) must satisfy the following condition: one of its vertices must be geometrically coincident with one of the vertices of the wire (provided that the highest tolerance factor is assigned to the two vertices). It could also be the same vertex. - The given edge is shared by the wire if it contains: - two vertices, identical to two vertices of the wire under construction (a general case of the wire closure), or - one vertex, identical to a vertex of the wire under construction; the other vertex not being geometrically coincident with another vertex of the wire. - In other cases, when one of the vertices of the edge is simply geometrically coincident with a vertex of the wire under construction (provided that the highest tolerance factor is assigned to the two vertices), the given edge is first copied and the coincident vertex is replaced in this new edge, by the coincident vertex of the wire. Note: it is possible to build non manifold wires using this construction tool. A MakeWire object provides a framework for: - initializing the construction of a wire, - adding edges to the wire under construction, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_MakeWire.def(py::init<>());
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Edge &>(), py::arg("E"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"), py::arg("E4"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Wire &, const TopoDS_Edge &>(), py::arg("W"), py::arg("E"));

// Methods
// cls_BRepBuilderAPI_MakeWire.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeWire::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeWire::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeWire::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeWire::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeWire::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeWire::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeWire.def("Add", (void (BRepBuilderAPI_MakeWire::*)(const TopoDS_Edge &)) &BRepBuilderAPI_MakeWire::Add, "Adds the edge E to the wire under construction. E must be connectable to the wire under construction, and, unless it is the first edge of the wire, must satisfy the following condition: one of its vertices must be geometrically coincident with one of the vertices of the wire (provided that the highest tolerance factor is assigned to the two vertices). It could also be the same vertex. Warning If E is not connectable to the wire under construction it is not added. The function Error will return BRepBuilderAPI_DisconnectedWire, the function IsDone will return false and the function Wire will raise an error, until a new connectable edge is added.", py::arg("E"));
cls_BRepBuilderAPI_MakeWire.def("Add", (void (BRepBuilderAPI_MakeWire::*)(const TopoDS_Wire &)) &BRepBuilderAPI_MakeWire::Add, "Add the edges of <W> to the current wire.", py::arg("W"));
cls_BRepBuilderAPI_MakeWire.def("Add", (void (BRepBuilderAPI_MakeWire::*)(const TopTools_ListOfShape &)) &BRepBuilderAPI_MakeWire::Add, "Adds the edges of <L> to the current wire. The edges are not to be consecutive. But they are to be all connected geometrically or topologically. If some of them are not connected the Status give DisconnectedWire but the 'Maker' is Done() and you can get the partial result. (ie connected to the first edgeof the list <L>)", py::arg("L"));
cls_BRepBuilderAPI_MakeWire.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeWire::*)() const) &BRepBuilderAPI_MakeWire::IsDone, "Returns true if this algorithm contains a valid wire. IsDone returns false if: - there are no edges in the wire, or - the last edge which you tried to add was not connectable.");
cls_BRepBuilderAPI_MakeWire.def("Error", (BRepBuilderAPI_WireError (BRepBuilderAPI_MakeWire::*)() const) &BRepBuilderAPI_MakeWire::Error, "Returns the construction status - BRepBuilderAPI_WireDone if the wire is built, or - another value of the BRepBuilderAPI_WireError enumeration indicating why the construction failed.");
cls_BRepBuilderAPI_MakeWire.def("Wire", (const TopoDS_Wire & (BRepBuilderAPI_MakeWire::*)()) &BRepBuilderAPI_MakeWire::Wire, "Returns the constructed wire; or the part of the wire under construction already built. Exceptions StdFail_NotDone if a wire is not built.");
cls_BRepBuilderAPI_MakeWire.def("Edge", (const TopoDS_Edge & (BRepBuilderAPI_MakeWire::*)() const) &BRepBuilderAPI_MakeWire::Edge, "Returns the last edge added to the wire under construction. Warning - This edge can be different from the original one (the argument of the function Add, for instance,) - A null edge is returned if there are no edges in the wire under construction, or if the last edge which you tried to add was not connectable..");
cls_BRepBuilderAPI_MakeWire.def("Vertex", (const TopoDS_Vertex & (BRepBuilderAPI_MakeWire::*)() const) &BRepBuilderAPI_MakeWire::Vertex, "Returns the last vertex of the last edge added to the wire under construction. Warning A null vertex is returned if there are no edges in the wire under construction, or if the last edge which you tried to add was not connectableR");

// CLASS: BREPBUILDERAPI_NURBSCONVERT
py::class_<BRepBuilderAPI_NurbsConvert, BRepBuilderAPI_ModifyShape> cls_BRepBuilderAPI_NurbsConvert(mod, "BRepBuilderAPI_NurbsConvert", "Conversion of the complete geometry of a shape (all 3D analytical representation of surfaces and curves) into NURBS geometry (execpt for Planes). For example, all curves supporting edges of the basis shape are converted into BSpline curves, and all surfaces supporting its faces are converted into BSpline surfaces.");

// Constructors
cls_BRepBuilderAPI_NurbsConvert.def(py::init<>());
cls_BRepBuilderAPI_NurbsConvert.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepBuilderAPI_NurbsConvert.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S"), py::arg("Copy"));

// Methods
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_NurbsConvert::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_NurbsConvert::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_NurbsConvert::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_NurbsConvert::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_NurbsConvert::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_NurbsConvert.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_NurbsConvert::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_NurbsConvert.def("Perform", [](BRepBuilderAPI_NurbsConvert &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepBuilderAPI_NurbsConvert.def("Perform", (void (BRepBuilderAPI_NurbsConvert::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepBuilderAPI_NurbsConvert::Perform, "Builds a new shape by converting the geometry of the shape S into NURBS geometry. Specifically, all curves supporting edges of S are converted into BSpline curves, and all surfaces supporting its faces are converted into BSpline surfaces. Use the function Shape to access the new shape. Note: this framework can be reused to convert other shapes: you specify them by calling the function Perform again.", py::arg("S"), py::arg("Copy"));
cls_BRepBuilderAPI_NurbsConvert.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_NurbsConvert::*)(const TopoDS_Shape &)) &BRepBuilderAPI_NurbsConvert::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_NurbsConvert.def("ModifiedShape", (TopoDS_Shape (BRepBuilderAPI_NurbsConvert::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_NurbsConvert::ModifiedShape, "Returns the modified shape corresponding to <S>. S can correspond to the entire initial shape or to its subshape. Exceptions Standard_NoSuchObject if S is not the initial shape or a subshape of the initial shape to which the transformation has been applied.", py::arg("S"));

// CLASS: BREPBUILDERAPI_SEWING
py::class_<BRepBuilderAPI_Sewing, opencascade::handle<BRepBuilderAPI_Sewing>, Standard_Transient> cls_BRepBuilderAPI_Sewing(mod, "BRepBuilderAPI_Sewing", "Provides methods to");

// Constructors
cls_BRepBuilderAPI_Sewing.def(py::init<>());
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real>(), py::arg("tolerance"));
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"));
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"), py::arg("option2"));
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"), py::arg("option2"), py::arg("option3"));
cls_BRepBuilderAPI_Sewing.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option1"), py::arg("option2"), py::arg("option3"), py::arg("option4"));

// Methods
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self) -> void { return self.Init(); });
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0) -> void { return self.Init(a0); });
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0, const Standard_Boolean a1) -> void { return self.Init(a0, a1); });
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0, const Standard_Boolean a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); });
cls_BRepBuilderAPI_Sewing.def("Init", [](BRepBuilderAPI_Sewing &self, const Standard_Real a0, const Standard_Boolean a1, const Standard_Boolean a2, const Standard_Boolean a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_BRepBuilderAPI_Sewing.def("Init", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &BRepBuilderAPI_Sewing::Init, "initialize the parameters if necessary", py::arg("tolerance"), py::arg("option1"), py::arg("option2"), py::arg("option3"), py::arg("option4"));
cls_BRepBuilderAPI_Sewing.def("Load", (void (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Sewing::Load, "Loades the context shape.", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("Add", (void (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Sewing::Add, "Defines the shapes to be sewed or controlled", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("Perform", [](BRepBuilderAPI_Sewing &self) -> void { return self.Perform(); });
cls_BRepBuilderAPI_Sewing.def("Perform", (void (BRepBuilderAPI_Sewing::*)(const opencascade::handle<Message_ProgressIndicator> &)) &BRepBuilderAPI_Sewing::Perform, "Computing thePI - progress indicator of algorithm", py::arg("thePI"));
cls_BRepBuilderAPI_Sewing.def("SewedShape", (const TopoDS_Shape & (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::SewedShape, "Gives the sewed shape a null shape if nothing constructed may be a face, a shell, a solid or a compound");
cls_BRepBuilderAPI_Sewing.def("SetContext", (void (BRepBuilderAPI_Sewing::*)(const opencascade::handle<BRepTools_ReShape> &)) &BRepBuilderAPI_Sewing::SetContext, "set context", py::arg("theContext"));
cls_BRepBuilderAPI_Sewing.def("GetContext", (const opencascade::handle<BRepTools_ReShape> & (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::GetContext, "return context");
cls_BRepBuilderAPI_Sewing.def("NbFreeEdges", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbFreeEdges, "Gives the number of free edges (edge shared by one face)");
cls_BRepBuilderAPI_Sewing.def("FreeEdge", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::FreeEdge, "Gives each free edge", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("NbMultipleEdges", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbMultipleEdges, "Gives the number of multiple edges (edge shared by more than two faces)");
cls_BRepBuilderAPI_Sewing.def("MultipleEdge", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::MultipleEdge, "Gives each multiple edge", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("NbContigousEdges", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbContigousEdges, "Gives the number of contigous edges (edge shared by two faces)");
cls_BRepBuilderAPI_Sewing.def("ContigousEdge", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::ContigousEdge, "Gives each contigous edge", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("ContigousEdgeCouple", (const TopTools_ListOfShape & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::ContigousEdgeCouple, "Gives the sections (edge) belonging to a contigous edge", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("IsSectionBound", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Edge &) const) &BRepBuilderAPI_Sewing::IsSectionBound, "Indicates if a section is bound (before use SectionToBoundary)", py::arg("section"));
cls_BRepBuilderAPI_Sewing.def("SectionToBoundary", (const TopoDS_Edge & (BRepBuilderAPI_Sewing::*)(const TopoDS_Edge &) const) &BRepBuilderAPI_Sewing::SectionToBoundary, "Gives the original edge (free boundary) which becomes the the section. Remember that sections constitute common edges. This imformation is important for control because with original edge we can find the surface to which the section is attached.", py::arg("section"));
cls_BRepBuilderAPI_Sewing.def("NbDegeneratedShapes", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbDegeneratedShapes, "Gives the number of degenerated shapes");
cls_BRepBuilderAPI_Sewing.def("DegeneratedShape", (const TopoDS_Shape & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::DegeneratedShape, "Gives each degenerated shape", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("IsDegenerated", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::IsDegenerated, "Indicates if a input shape is degenerated", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("IsModified", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::IsModified, "Indicates if a input shape has been modified", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("Modified", (const TopoDS_Shape & (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::Modified, "Gives a modifieded shape", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("IsModifiedSubShape", (Standard_Boolean (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::IsModifiedSubShape, "Indicates if a input subshape has been modified", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("ModifiedSubShape", (TopoDS_Shape (BRepBuilderAPI_Sewing::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Sewing::ModifiedSubShape, "Gives a modifieded subshape", py::arg("shape"));
cls_BRepBuilderAPI_Sewing.def("Dump", (void (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::Dump, "print the informations");
cls_BRepBuilderAPI_Sewing.def("NbDeletedFaces", (Standard_Integer (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NbDeletedFaces, "Gives the number of deleted faces (faces smallest than tolerance)");
cls_BRepBuilderAPI_Sewing.def("DeletedFace", (const TopoDS_Face & (BRepBuilderAPI_Sewing::*)(const Standard_Integer) const) &BRepBuilderAPI_Sewing::DeletedFace, "Gives each deleted face", py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("WhichFace", [](BRepBuilderAPI_Sewing &self, const TopoDS_Edge & a0) -> TopoDS_Face { return self.WhichFace(a0); });
cls_BRepBuilderAPI_Sewing.def("WhichFace", (TopoDS_Face (BRepBuilderAPI_Sewing::*)(const TopoDS_Edge &, const Standard_Integer) const) &BRepBuilderAPI_Sewing::WhichFace, "Gives a modified shape", py::arg("theEdg"), py::arg("index"));
cls_BRepBuilderAPI_Sewing.def("SameParameterMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::SameParameterMode, "Gets same parameter mode.");
cls_BRepBuilderAPI_Sewing.def("SetSameParameterMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetSameParameterMode, "Sets same parameter mode.", py::arg("SameParameterMode"));
cls_BRepBuilderAPI_Sewing.def("Tolerance", (Standard_Real (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::Tolerance, "Gives set tolerance.");
cls_BRepBuilderAPI_Sewing.def("SetTolerance", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real)) &BRepBuilderAPI_Sewing::SetTolerance, "Sets tolerance", py::arg("theToler"));
cls_BRepBuilderAPI_Sewing.def("MinTolerance", (Standard_Real (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::MinTolerance, "Gives set min tolerance.");
cls_BRepBuilderAPI_Sewing.def("SetMinTolerance", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real)) &BRepBuilderAPI_Sewing::SetMinTolerance, "Sets min tolerance", py::arg("theMinToler"));
cls_BRepBuilderAPI_Sewing.def("MaxTolerance", (Standard_Real (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::MaxTolerance, "Gives set max tolerance");
cls_BRepBuilderAPI_Sewing.def("SetMaxTolerance", (void (BRepBuilderAPI_Sewing::*)(const Standard_Real)) &BRepBuilderAPI_Sewing::SetMaxTolerance, "Sets max tolerance.", py::arg("theMaxToler"));
cls_BRepBuilderAPI_Sewing.def("FaceMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::FaceMode, "Returns mode for sewing faces By default - true.");
cls_BRepBuilderAPI_Sewing.def("SetFaceMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetFaceMode, "Sets mode for sewing faces By default - true.", py::arg("theFaceMode"));
cls_BRepBuilderAPI_Sewing.def("FloatingEdgesMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::FloatingEdgesMode, "Returns mode for sewing floating edges By default - false.");
cls_BRepBuilderAPI_Sewing.def("SetFloatingEdgesMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetFloatingEdgesMode, "Sets mode for sewing floating edges By default - false. Returns mode for cutting floating edges By default - false. Sets mode for cutting floating edges By default - false.", py::arg("theFloatingEdgesMode"));
cls_BRepBuilderAPI_Sewing.def("LocalTolerancesMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::LocalTolerancesMode, "Returns mode for accounting of local tolerances of edges and vertices during of merging.");
cls_BRepBuilderAPI_Sewing.def("SetLocalTolerancesMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetLocalTolerancesMode, "Sets mode for accounting of local tolerances of edges and vertices during of merging in this case WorkTolerance = myTolerance + tolEdge1+ tolEdg2;", py::arg("theLocalTolerancesMode"));
cls_BRepBuilderAPI_Sewing.def("SetNonManifoldMode", (void (BRepBuilderAPI_Sewing::*)(const Standard_Boolean)) &BRepBuilderAPI_Sewing::SetNonManifoldMode, "Sets mode for non-manifold sewing.", py::arg("theNonManifoldMode"));
cls_BRepBuilderAPI_Sewing.def("NonManifoldMode", (Standard_Boolean (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::NonManifoldMode, "Gets mode for non-manifold sewing.");
cls_BRepBuilderAPI_Sewing.def_static("get_type_name_", (const char * (*)()) &BRepBuilderAPI_Sewing::get_type_name, "None");
cls_BRepBuilderAPI_Sewing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBuilderAPI_Sewing::get_type_descriptor, "None");
cls_BRepBuilderAPI_Sewing.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBuilderAPI_Sewing::*)() const) &BRepBuilderAPI_Sewing::DynamicType, "None");

// CLASS: BREPBUILDERAPI_TRANSFORM
py::class_<BRepBuilderAPI_Transform, BRepBuilderAPI_ModifyShape> cls_BRepBuilderAPI_Transform(mod, "BRepBuilderAPI_Transform", "Geometric transformation on a shape. The transformation to be applied is defined as a gp_Trsf transformation, i.e. a transformation which does not modify the underlying geometry of shapes. The transformation is applied to: - all curves which support edges of a shape, and - all surfaces which support its faces. A Transform object provides a framework for: - defining the geometric transformation to be applied, - implementing the transformation algorithm, and - consulting the results.");

// Constructors
cls_BRepBuilderAPI_Transform.def(py::init<const gp_Trsf &>(), py::arg("T"));
cls_BRepBuilderAPI_Transform.def(py::init<const TopoDS_Shape &, const gp_Trsf &>(), py::arg("S"), py::arg("T"));
cls_BRepBuilderAPI_Transform.def(py::init<const TopoDS_Shape &, const gp_Trsf &, const Standard_Boolean>(), py::arg("S"), py::arg("T"), py::arg("Copy"));

// Methods
// cls_BRepBuilderAPI_Transform.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_Transform::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Transform.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_Transform::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Transform.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_Transform::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Transform.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_Transform::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Transform.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_Transform::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_Transform.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_Transform::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_Transform.def("Perform", [](BRepBuilderAPI_Transform &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepBuilderAPI_Transform.def("Perform", (void (BRepBuilderAPI_Transform::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepBuilderAPI_Transform::Perform, "pplies the geometric transformation defined at the time of construction of this framework to the shape S. - If the transformation T is direct and isometric, in other words, if the determinant of the vectorial part of T is equal to 1., and if Copy equals false (the default value), the resulting shape is the same as the original but with a new location assigned to it. - In all other cases, the transformation is applied to a duplicate of S. Use the function Shape to access the result. Note: this framework can be reused to apply the same geometric transformation to other shapes. You only need to specify them by calling the function Perform again.", py::arg("S"), py::arg("Copy"));
cls_BRepBuilderAPI_Transform.def("ModifiedShape", (TopoDS_Shape (BRepBuilderAPI_Transform::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Transform::ModifiedShape, "Returns the modified shape corresponding to <S>.", py::arg("S"));
cls_BRepBuilderAPI_Transform.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_Transform::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Transform::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));


}
