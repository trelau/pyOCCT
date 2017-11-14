#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BRepCheck_Status.hxx>
#include <NCollection_BaseList.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepCheck_ListOfStatus.hxx>
#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Type.hxx>
#include <BRepCheck_Result.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepCheck_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <BRepCheck_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <BRepCheck_Wire.hxx>
#include <BRepCheck_Face.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepCheck_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepCheck_Solid.hxx>
#include <BRepCheck_Analyzer.hxx>
#include <Standard_OStream.hxx>
#include <BRepCheck.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepCheck_DataMapOfShapeListOfStatus.hxx>
#include <BRepCheck_DataMapOfShapeResult.hxx>

PYBIND11_MODULE(BRepCheck, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopTools");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_Status.hxx
	py::enum_<BRepCheck_Status>(mod, "BRepCheck_Status", "None")
		.value("BRepCheck_NoError", BRepCheck_Status::BRepCheck_NoError)
		.value("BRepCheck_InvalidPointOnCurve", BRepCheck_Status::BRepCheck_InvalidPointOnCurve)
		.value("BRepCheck_InvalidPointOnCurveOnSurface", BRepCheck_Status::BRepCheck_InvalidPointOnCurveOnSurface)
		.value("BRepCheck_InvalidPointOnSurface", BRepCheck_Status::BRepCheck_InvalidPointOnSurface)
		.value("BRepCheck_No3DCurve", BRepCheck_Status::BRepCheck_No3DCurve)
		.value("BRepCheck_Multiple3DCurve", BRepCheck_Status::BRepCheck_Multiple3DCurve)
		.value("BRepCheck_Invalid3DCurve", BRepCheck_Status::BRepCheck_Invalid3DCurve)
		.value("BRepCheck_NoCurveOnSurface", BRepCheck_Status::BRepCheck_NoCurveOnSurface)
		.value("BRepCheck_InvalidCurveOnSurface", BRepCheck_Status::BRepCheck_InvalidCurveOnSurface)
		.value("BRepCheck_InvalidCurveOnClosedSurface", BRepCheck_Status::BRepCheck_InvalidCurveOnClosedSurface)
		.value("BRepCheck_InvalidSameRangeFlag", BRepCheck_Status::BRepCheck_InvalidSameRangeFlag)
		.value("BRepCheck_InvalidSameParameterFlag", BRepCheck_Status::BRepCheck_InvalidSameParameterFlag)
		.value("BRepCheck_InvalidDegeneratedFlag", BRepCheck_Status::BRepCheck_InvalidDegeneratedFlag)
		.value("BRepCheck_FreeEdge", BRepCheck_Status::BRepCheck_FreeEdge)
		.value("BRepCheck_InvalidMultiConnexity", BRepCheck_Status::BRepCheck_InvalidMultiConnexity)
		.value("BRepCheck_InvalidRange", BRepCheck_Status::BRepCheck_InvalidRange)
		.value("BRepCheck_EmptyWire", BRepCheck_Status::BRepCheck_EmptyWire)
		.value("BRepCheck_RedundantEdge", BRepCheck_Status::BRepCheck_RedundantEdge)
		.value("BRepCheck_SelfIntersectingWire", BRepCheck_Status::BRepCheck_SelfIntersectingWire)
		.value("BRepCheck_NoSurface", BRepCheck_Status::BRepCheck_NoSurface)
		.value("BRepCheck_InvalidWire", BRepCheck_Status::BRepCheck_InvalidWire)
		.value("BRepCheck_RedundantWire", BRepCheck_Status::BRepCheck_RedundantWire)
		.value("BRepCheck_IntersectingWires", BRepCheck_Status::BRepCheck_IntersectingWires)
		.value("BRepCheck_InvalidImbricationOfWires", BRepCheck_Status::BRepCheck_InvalidImbricationOfWires)
		.value("BRepCheck_EmptyShell", BRepCheck_Status::BRepCheck_EmptyShell)
		.value("BRepCheck_RedundantFace", BRepCheck_Status::BRepCheck_RedundantFace)
		.value("BRepCheck_InvalidImbricationOfShells", BRepCheck_Status::BRepCheck_InvalidImbricationOfShells)
		.value("BRepCheck_UnorientableShape", BRepCheck_Status::BRepCheck_UnorientableShape)
		.value("BRepCheck_NotClosed", BRepCheck_Status::BRepCheck_NotClosed)
		.value("BRepCheck_NotConnected", BRepCheck_Status::BRepCheck_NotConnected)
		.value("BRepCheck_SubshapeNotInShape", BRepCheck_Status::BRepCheck_SubshapeNotInShape)
		.value("BRepCheck_BadOrientation", BRepCheck_Status::BRepCheck_BadOrientation)
		.value("BRepCheck_BadOrientationOfSubshape", BRepCheck_Status::BRepCheck_BadOrientationOfSubshape)
		.value("BRepCheck_InvalidPolygonOnTriangulation", BRepCheck_Status::BRepCheck_InvalidPolygonOnTriangulation)
		.value("BRepCheck_InvalidToleranceValue", BRepCheck_Status::BRepCheck_InvalidToleranceValue)
		.value("BRepCheck_EnclosedRegion", BRepCheck_Status::BRepCheck_EnclosedRegion)
		.value("BRepCheck_CheckFail", BRepCheck_Status::BRepCheck_CheckFail)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_Result.hxx
	py::class_<BRepCheck_Result, opencascade::handle<BRepCheck_Result>, Standard_Transient> cls_BRepCheck_Result(mod, "BRepCheck_Result", "None");
	cls_BRepCheck_Result.def("Init", (void (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::Init, "None", py::arg("S"));
	cls_BRepCheck_Result.def("InContext", (void (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::InContext, "None", py::arg("ContextShape"));
	cls_BRepCheck_Result.def("Minimum", (void (BRepCheck_Result::*)()) &BRepCheck_Result::Minimum, "None");
	cls_BRepCheck_Result.def("Blind", (void (BRepCheck_Result::*)()) &BRepCheck_Result::Blind, "None");
	cls_BRepCheck_Result.def("SetFailStatus", (void (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::SetFailStatus, "None", py::arg("S"));
	cls_BRepCheck_Result.def("Status", (const BRepCheck_ListOfStatus & (BRepCheck_Result::*)() const ) &BRepCheck_Result::Status, "None");
	cls_BRepCheck_Result.def("IsMinimum", (Standard_Boolean (BRepCheck_Result::*)() const ) &BRepCheck_Result::IsMinimum, "None");
	cls_BRepCheck_Result.def("IsBlind", (Standard_Boolean (BRepCheck_Result::*)() const ) &BRepCheck_Result::IsBlind, "None");
	cls_BRepCheck_Result.def("StatusOnShape", (const BRepCheck_ListOfStatus & (BRepCheck_Result::*)(const TopoDS_Shape &)) &BRepCheck_Result::StatusOnShape, "If not already done, performs the InContext control and returns the list of status.", py::arg("S"));
	cls_BRepCheck_Result.def("InitContextIterator", (void (BRepCheck_Result::*)()) &BRepCheck_Result::InitContextIterator, "None");
	cls_BRepCheck_Result.def("MoreShapeInContext", (Standard_Boolean (BRepCheck_Result::*)() const ) &BRepCheck_Result::MoreShapeInContext, "None");
	cls_BRepCheck_Result.def("ContextualShape", (const TopoDS_Shape & (BRepCheck_Result::*)() const ) &BRepCheck_Result::ContextualShape, "None");
	cls_BRepCheck_Result.def("StatusOnShape", (const BRepCheck_ListOfStatus & (BRepCheck_Result::*)() const ) &BRepCheck_Result::StatusOnShape, "None");
	cls_BRepCheck_Result.def("NextShapeInContext", (void (BRepCheck_Result::*)()) &BRepCheck_Result::NextShapeInContext, "None");
	cls_BRepCheck_Result.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Result::get_type_name, "None");
	cls_BRepCheck_Result.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Result::get_type_descriptor, "None");
	cls_BRepCheck_Result.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Result::*)() const ) &BRepCheck_Result::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_Vertex.hxx
	py::class_<BRepCheck_Vertex, opencascade::handle<BRepCheck_Vertex>, BRepCheck_Result> cls_BRepCheck_Vertex(mod, "BRepCheck_Vertex", "None");
	cls_BRepCheck_Vertex.def(py::init<const TopoDS_Vertex &>(), py::arg("V"));
	cls_BRepCheck_Vertex.def("InContext", (void (BRepCheck_Vertex::*)(const TopoDS_Shape &)) &BRepCheck_Vertex::InContext, "None", py::arg("ContextShape"));
	cls_BRepCheck_Vertex.def("Minimum", (void (BRepCheck_Vertex::*)()) &BRepCheck_Vertex::Minimum, "None");
	cls_BRepCheck_Vertex.def("Blind", (void (BRepCheck_Vertex::*)()) &BRepCheck_Vertex::Blind, "None");
	cls_BRepCheck_Vertex.def("Tolerance", (Standard_Real (BRepCheck_Vertex::*)()) &BRepCheck_Vertex::Tolerance, "None");
	cls_BRepCheck_Vertex.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Vertex::get_type_name, "None");
	cls_BRepCheck_Vertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Vertex::get_type_descriptor, "None");
	cls_BRepCheck_Vertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Vertex::*)() const ) &BRepCheck_Vertex::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_Edge.hxx
	py::class_<BRepCheck_Edge, opencascade::handle<BRepCheck_Edge>, BRepCheck_Result> cls_BRepCheck_Edge(mod, "BRepCheck_Edge", "None");
	cls_BRepCheck_Edge.def(py::init<const TopoDS_Edge &>(), py::arg("E"));
	cls_BRepCheck_Edge.def("InContext", (void (BRepCheck_Edge::*)(const TopoDS_Shape &)) &BRepCheck_Edge::InContext, "None", py::arg("ContextShape"));
	cls_BRepCheck_Edge.def("Minimum", (void (BRepCheck_Edge::*)()) &BRepCheck_Edge::Minimum, "None");
	cls_BRepCheck_Edge.def("Blind", (void (BRepCheck_Edge::*)()) &BRepCheck_Edge::Blind, "None");
	cls_BRepCheck_Edge.def("GeometricControls", (Standard_Boolean (BRepCheck_Edge::*)() const ) &BRepCheck_Edge::GeometricControls, "None");
	cls_BRepCheck_Edge.def("GeometricControls", (void (BRepCheck_Edge::*)(const Standard_Boolean)) &BRepCheck_Edge::GeometricControls, "None", py::arg("B"));
	cls_BRepCheck_Edge.def("Tolerance", (Standard_Real (BRepCheck_Edge::*)()) &BRepCheck_Edge::Tolerance, "None");
	cls_BRepCheck_Edge.def("SetStatus", (void (BRepCheck_Edge::*)(const BRepCheck_Status)) &BRepCheck_Edge::SetStatus, "Sets status of Edge;", py::arg("theStatus"));
	cls_BRepCheck_Edge.def("CheckPolygonOnTriangulation", (BRepCheck_Status (BRepCheck_Edge::*)(const TopoDS_Edge &)) &BRepCheck_Edge::CheckPolygonOnTriangulation, "Checks, if polygon on triangulation of heEdge is out of 3D-curve of this edge.", py::arg("theEdge"));
	cls_BRepCheck_Edge.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Edge::get_type_name, "None");
	cls_BRepCheck_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Edge::get_type_descriptor, "None");
	cls_BRepCheck_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Edge::*)() const ) &BRepCheck_Edge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_Wire.hxx
	py::class_<BRepCheck_Wire, opencascade::handle<BRepCheck_Wire>, BRepCheck_Result> cls_BRepCheck_Wire(mod, "BRepCheck_Wire", "None");
	cls_BRepCheck_Wire.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
	cls_BRepCheck_Wire.def("InContext", (void (BRepCheck_Wire::*)(const TopoDS_Shape &)) &BRepCheck_Wire::InContext, "if <ContextShape> is a face, consequently checks SelfIntersect(), Closed(), Orientation() and Closed2d until faulty is found", py::arg("ContextShape"));
	cls_BRepCheck_Wire.def("Minimum", (void (BRepCheck_Wire::*)()) &BRepCheck_Wire::Minimum, "checks that the wire is not empty and 'connex'. Called by constructor");
	cls_BRepCheck_Wire.def("Blind", (void (BRepCheck_Wire::*)()) &BRepCheck_Wire::Blind, "Does nothing");
	cls_BRepCheck_Wire.def("Closed", [](BRepCheck_Wire &self) -> BRepCheck_Status { return self.Closed(); });
	// FIXME cls_BRepCheck_Wire.def("Closed", (BRepCheck_Status (BRepCheck_Wire::*)(const Standard_Boolean)) &BRepCheck_Wire::Closed, "Checks if the oriented edges of the wire give a closed wire. If the wire is closed, returns BRepCheck_NoError. Warning : if the first and last edge are infinite, the wire will be considered as a closed one. If <Update> is set to Standard_True, registers the status in the list. May return (and registers): **BRepCheck_NotConnected, if wire is not topologically closed **BRepCheck_RedundantEdge, if an edge is in wire more than 3 times or in case of 2 occurences if not with FORWARD and REVERSED orientation. **BRepCheck_NoError", py::arg("Update"));
	cls_BRepCheck_Wire.def("Closed2d", [](BRepCheck_Wire &self, const TopoDS_Face & a0) -> BRepCheck_Status { return self.Closed2d(a0); }, py::arg("F"));
	cls_BRepCheck_Wire.def("Closed2d", (BRepCheck_Status (BRepCheck_Wire::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepCheck_Wire::Closed2d, "Checks if edges of the wire give a wire closed in 2d space. Returns BRepCheck_NoError, or BRepCheck_NotClosed If <Update> is set to Standard_True, registers the status in the list.", py::arg("F"), py::arg("Update"));
	cls_BRepCheck_Wire.def("Orientation", [](BRepCheck_Wire &self, const TopoDS_Face & a0) -> BRepCheck_Status { return self.Orientation(a0); }, py::arg("F"));
	cls_BRepCheck_Wire.def("Orientation", (BRepCheck_Status (BRepCheck_Wire::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepCheck_Wire::Orientation, "Checks if the oriented edges of the wire are correctly oriented. An internal call is made to the method Closed. If no face exists, call the method with a null face (TopoDS_face()). If <Update> is set to Standard_True, registers the status in the list. May return (and registers): BRepCheck_InvalidDegeneratedFlag, BRepCheck_BadOrientationOfSubshape, BRepCheck_NotClosed, BRepCheck_NoError", py::arg("F"), py::arg("Update"));
	cls_BRepCheck_Wire.def("SelfIntersect", [](BRepCheck_Wire &self, const TopoDS_Face & a0, TopoDS_Edge & a1, TopoDS_Edge & a2) -> BRepCheck_Status { return self.SelfIntersect(a0, a1, a2); }, py::arg("F"), py::arg("E1"), py::arg("E2"));
	cls_BRepCheck_Wire.def("SelfIntersect", (BRepCheck_Status (BRepCheck_Wire::*)(const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Boolean)) &BRepCheck_Wire::SelfIntersect, "Checks if the wire intersect itself on the face <F>. <E1> and <E2> are the first intersecting edges found. <E2> may be a null edge when a self-intersecting edge is found.If <Update> is set to Standard_True, registers the status in the list. May return (and register): BRepCheck_EmptyWire, BRepCheck_SelfIntersectingWire, BRepCheck_NoCurveOnSurface, BRepCheck_NoError", py::arg("F"), py::arg("E1"), py::arg("E2"), py::arg("Update"));
	cls_BRepCheck_Wire.def("GeometricControls", (Standard_Boolean (BRepCheck_Wire::*)() const ) &BRepCheck_Wire::GeometricControls, "report SelfIntersect() check would be (is) done");
	cls_BRepCheck_Wire.def("GeometricControls", (void (BRepCheck_Wire::*)(const Standard_Boolean)) &BRepCheck_Wire::GeometricControls, "set SelfIntersect() to be checked", py::arg("B"));
	cls_BRepCheck_Wire.def("SetStatus", (void (BRepCheck_Wire::*)(const BRepCheck_Status)) &BRepCheck_Wire::SetStatus, "Sets status of Wire;", py::arg("theStatus"));
	cls_BRepCheck_Wire.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Wire::get_type_name, "None");
	cls_BRepCheck_Wire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Wire::get_type_descriptor, "None");
	cls_BRepCheck_Wire.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Wire::*)() const ) &BRepCheck_Wire::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_Face.hxx
	py::class_<BRepCheck_Face, opencascade::handle<BRepCheck_Face>, BRepCheck_Result> cls_BRepCheck_Face(mod, "BRepCheck_Face", "None");
	cls_BRepCheck_Face.def(py::init<const TopoDS_Face &>(), py::arg("F"));
	cls_BRepCheck_Face.def("InContext", (void (BRepCheck_Face::*)(const TopoDS_Shape &)) &BRepCheck_Face::InContext, "None", py::arg("ContextShape"));
	cls_BRepCheck_Face.def("Minimum", (void (BRepCheck_Face::*)()) &BRepCheck_Face::Minimum, "None");
	cls_BRepCheck_Face.def("Blind", (void (BRepCheck_Face::*)()) &BRepCheck_Face::Blind, "None");
	cls_BRepCheck_Face.def("IntersectWires", [](BRepCheck_Face &self) -> BRepCheck_Status { return self.IntersectWires(); });
	cls_BRepCheck_Face.def("IntersectWires", (BRepCheck_Status (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::IntersectWires, "None", py::arg("Update"));
	cls_BRepCheck_Face.def("ClassifyWires", [](BRepCheck_Face &self) -> BRepCheck_Status { return self.ClassifyWires(); });
	cls_BRepCheck_Face.def("ClassifyWires", (BRepCheck_Status (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::ClassifyWires, "None", py::arg("Update"));
	cls_BRepCheck_Face.def("OrientationOfWires", [](BRepCheck_Face &self) -> BRepCheck_Status { return self.OrientationOfWires(); });
	cls_BRepCheck_Face.def("OrientationOfWires", (BRepCheck_Status (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::OrientationOfWires, "None", py::arg("Update"));
	cls_BRepCheck_Face.def("SetUnorientable", (void (BRepCheck_Face::*)()) &BRepCheck_Face::SetUnorientable, "None");
	cls_BRepCheck_Face.def("SetStatus", (void (BRepCheck_Face::*)(const BRepCheck_Status)) &BRepCheck_Face::SetStatus, "Sets status of Face;", py::arg("theStatus"));
	cls_BRepCheck_Face.def("IsUnorientable", (Standard_Boolean (BRepCheck_Face::*)() const ) &BRepCheck_Face::IsUnorientable, "None");
	cls_BRepCheck_Face.def("GeometricControls", (Standard_Boolean (BRepCheck_Face::*)() const ) &BRepCheck_Face::GeometricControls, "None");
	cls_BRepCheck_Face.def("GeometricControls", (void (BRepCheck_Face::*)(const Standard_Boolean)) &BRepCheck_Face::GeometricControls, "None", py::arg("B"));
	cls_BRepCheck_Face.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Face::get_type_name, "None");
	cls_BRepCheck_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Face::get_type_descriptor, "None");
	cls_BRepCheck_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Face::*)() const ) &BRepCheck_Face::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_Shell.hxx
	py::class_<BRepCheck_Shell, opencascade::handle<BRepCheck_Shell>, BRepCheck_Result> cls_BRepCheck_Shell(mod, "BRepCheck_Shell", "None");
	cls_BRepCheck_Shell.def(py::init<const TopoDS_Shell &>(), py::arg("S"));
	cls_BRepCheck_Shell.def("InContext", (void (BRepCheck_Shell::*)(const TopoDS_Shape &)) &BRepCheck_Shell::InContext, "None", py::arg("ContextShape"));
	cls_BRepCheck_Shell.def("Minimum", (void (BRepCheck_Shell::*)()) &BRepCheck_Shell::Minimum, "None");
	cls_BRepCheck_Shell.def("Blind", (void (BRepCheck_Shell::*)()) &BRepCheck_Shell::Blind, "None");
	cls_BRepCheck_Shell.def("Closed", [](BRepCheck_Shell &self) -> BRepCheck_Status { return self.Closed(); });
	cls_BRepCheck_Shell.def("Closed", (BRepCheck_Status (BRepCheck_Shell::*)(const Standard_Boolean)) &BRepCheck_Shell::Closed, "Checks if the oriented faces of the shell give a closed shell. If the wire is closed, returns BRepCheck_NoError.If <Update> is set to Standard_True, registers the status in the list.", py::arg("Update"));
	cls_BRepCheck_Shell.def("Orientation", [](BRepCheck_Shell &self) -> BRepCheck_Status { return self.Orientation(); });
	cls_BRepCheck_Shell.def("Orientation", (BRepCheck_Status (BRepCheck_Shell::*)(const Standard_Boolean)) &BRepCheck_Shell::Orientation, "Checks if the oriented faces of the shell are correctly oriented. An internal call is made to the method Closed. If <Update> is set to Standard_True, registers the status in the list.", py::arg("Update"));
	cls_BRepCheck_Shell.def("SetUnorientable", (void (BRepCheck_Shell::*)()) &BRepCheck_Shell::SetUnorientable, "None");
	cls_BRepCheck_Shell.def("IsUnorientable", (Standard_Boolean (BRepCheck_Shell::*)() const ) &BRepCheck_Shell::IsUnorientable, "None");
	cls_BRepCheck_Shell.def("NbConnectedSet", (Standard_Integer (BRepCheck_Shell::*)(TopTools_ListOfShape &)) &BRepCheck_Shell::NbConnectedSet, "None", py::arg("theSets"));
	cls_BRepCheck_Shell.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Shell::get_type_name, "None");
	cls_BRepCheck_Shell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Shell::get_type_descriptor, "None");
	cls_BRepCheck_Shell.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Shell::*)() const ) &BRepCheck_Shell::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_Solid.hxx
	py::class_<BRepCheck_Solid, opencascade::handle<BRepCheck_Solid>, BRepCheck_Result> cls_BRepCheck_Solid(mod, "BRepCheck_Solid", "The class is to check a solid.");
	cls_BRepCheck_Solid.def(py::init<const TopoDS_Solid &>(), py::arg("theS"));
	cls_BRepCheck_Solid.def("InContext", (void (BRepCheck_Solid::*)(const TopoDS_Shape &)) &BRepCheck_Solid::InContext, "Checks the solid in context of the shape <theContextShape>", py::arg("theContextShape"));
	cls_BRepCheck_Solid.def("Minimum", (void (BRepCheck_Solid::*)()) &BRepCheck_Solid::Minimum, "Checks the solid per se.");
	cls_BRepCheck_Solid.def("Blind", (void (BRepCheck_Solid::*)()) &BRepCheck_Solid::Blind, "see the parent class for more details");
	cls_BRepCheck_Solid.def_static("get_type_name_", (const char * (*)()) &BRepCheck_Solid::get_type_name, "None");
	cls_BRepCheck_Solid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepCheck_Solid::get_type_descriptor, "None");
	cls_BRepCheck_Solid.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepCheck_Solid::*)() const ) &BRepCheck_Solid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_Analyzer.hxx
	py::class_<BRepCheck_Analyzer, std::unique_ptr<BRepCheck_Analyzer, Deleter<BRepCheck_Analyzer>>> cls_BRepCheck_Analyzer(mod, "BRepCheck_Analyzer", "A framework to check the overall validity of a shape. For a shape to be valid in Open CASCADE, it - or its component subshapes - must respect certain criteria. These criteria are checked by the function IsValid. Once you have determined whether a shape is valid or not, you can diagnose its specific anomalies and correct them using the services of the ShapeAnalysis, ShapeUpgrade, and ShapeFix packages.");
	cls_BRepCheck_Analyzer.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_BRepCheck_Analyzer.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S"), py::arg("GeomControls"));
	cls_BRepCheck_Analyzer.def("Init", [](BRepCheck_Analyzer &self, const TopoDS_Shape & a0) -> void { return self.Init(a0); }, py::arg("S"));
	cls_BRepCheck_Analyzer.def("Init", (void (BRepCheck_Analyzer::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepCheck_Analyzer::Init, "<S> is the shape to control. <GeomControls> If False only topological informaions are checked. The geometricals controls are For a Vertex : BRepCheck_InvalidTolerance NYI For an Edge : BRepCheck_InvalidCurveOnClosedSurface, BRepCheck_InvalidCurveOnSurface, BRepCheck_InvalidSameParameterFlag, BRepCheck_InvalidTolerance NYI For a face : BRepCheck_UnorientableShape, BRepCheck_IntersectingWires, BRepCheck_InvalidTolerance NYI For a wire : BRepCheck_SelfIntersectingWire", py::arg("S"), py::arg("GeomControls"));
	cls_BRepCheck_Analyzer.def("IsValid", (Standard_Boolean (BRepCheck_Analyzer::*)(const TopoDS_Shape &) const ) &BRepCheck_Analyzer::IsValid, "<S> is a subshape of the original shape. Returns <STandard_True> if no default has been detected on <S> and any of its subshape.", py::arg("S"));
	cls_BRepCheck_Analyzer.def("IsValid", (Standard_Boolean (BRepCheck_Analyzer::*)() const ) &BRepCheck_Analyzer::IsValid, "Returns true if no defect is detected on the shape S or any of its subshapes. Returns true if the shape S is valid. This function checks whether a given shape is valid by checking that: - the topology is correct - parameterization of edges in particular is correct. For the topology to be correct, the following conditions must be satisfied: - edges should have at least two vertices if they are not degenerate edges. The vertices should be within the range of the bounding edges at the tolerance specified in the vertex, - edges should share at least one face. The representation of the edges should be within the tolerance criterion assigned to them. - wires defining a face should not self-intersect and should be closed, - there should be one wire which contains all other wires inside a face, - wires should be correctly oriented with respect to each of the edges, - faces should be correctly oriented, in particular with respect to adjacent faces if these faces define a solid, - shells defining a solid should be closed. There should be one enclosing shell if the shape is a solid; To check parameterization of edge, there are 2 approaches depending on the edge?s contextual situation. - if the edge is either single, or it is in the context of a wire or a compound, its parameterization is defined by the parameterization of its 3D curve and is considered as valid. - If the edge is in the context of a face, it should have SameParameter and SameRange flags set to Standard_True. To check these flags, you should call the function BRep_Tool::SameParameter and BRep_Tool::SameRange for an edge. If at least one of these flags is set to Standard_False, the edge is considered as invalid without any additional check. If the edge is contained by a face, and it has SameParameter and SameRange flags set to Standard_True, IsValid checks whether representation of the edge on face, in context of which the edge is considered, has the same parameterization up to the tolerance value coded on the edge. For a given parameter t on the edge having C as a 3D curve and one PCurve P on a surface S (base surface of the reference face), this checks that |C(t) - S(P(t))| is less than or equal to tolerance, where tolerance is the tolerance value coded on the edge.");
	cls_BRepCheck_Analyzer.def("Result", (const opencascade::handle<BRepCheck_Result> & (BRepCheck_Analyzer::*)(const TopoDS_Shape &) const ) &BRepCheck_Analyzer::Result, "None", py::arg("SubS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck.hxx
	py::class_<BRepCheck, std::unique_ptr<BRepCheck, Deleter<BRepCheck>>> cls_BRepCheck(mod, "BRepCheck", "This package provides tools to check the validity of the BRep.");
	cls_BRepCheck.def(py::init<>());
	cls_BRepCheck.def_static("Add_", (void (*)(BRepCheck_ListOfStatus &, const BRepCheck_Status)) &BRepCheck::Add, "None", py::arg("List"), py::arg("Stat"));
	cls_BRepCheck.def_static("Print_", (void (*)(const BRepCheck_Status, Standard_OStream &)) &BRepCheck::Print, "None", py::arg("Stat"), py::arg("OS"));
	cls_BRepCheck.def_static("SelfIntersection_", (Standard_Boolean (*)(const TopoDS_Wire &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &)) &BRepCheck::SelfIntersection, "None", py::arg("W"), py::arg("F"), py::arg("E1"), py::arg("E2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BRepCheck_ListOfStatus, std::unique_ptr<BRepCheck_ListOfStatus, Deleter<BRepCheck_ListOfStatus>>, NCollection_BaseList> cls_BRepCheck_ListOfStatus(mod, "BRepCheck_ListOfStatus", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BRepCheck_ListOfStatus.def(py::init<>());
	cls_BRepCheck_ListOfStatus.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BRepCheck_ListOfStatus.def(py::init([] (const BRepCheck_ListOfStatus &other) {return new BRepCheck_ListOfStatus(other);}), "Copy constructor", py::arg("other"));
	cls_BRepCheck_ListOfStatus.def("begin", (BRepCheck_ListOfStatus::iterator (BRepCheck_ListOfStatus::*)() const ) &BRepCheck_ListOfStatus::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BRepCheck_ListOfStatus.def("end", (BRepCheck_ListOfStatus::iterator (BRepCheck_ListOfStatus::*)() const ) &BRepCheck_ListOfStatus::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BRepCheck_ListOfStatus.def("cbegin", (BRepCheck_ListOfStatus::const_iterator (BRepCheck_ListOfStatus::*)() const ) &BRepCheck_ListOfStatus::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BRepCheck_ListOfStatus.def("cend", (BRepCheck_ListOfStatus::const_iterator (BRepCheck_ListOfStatus::*)() const ) &BRepCheck_ListOfStatus::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BRepCheck_ListOfStatus.def("Size", (Standard_Integer (BRepCheck_ListOfStatus::*)() const ) &BRepCheck_ListOfStatus::Size, "Size - Number of items");
	cls_BRepCheck_ListOfStatus.def("Assign", (BRepCheck_ListOfStatus & (BRepCheck_ListOfStatus::*)(const BRepCheck_ListOfStatus &)) &BRepCheck_ListOfStatus::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepCheck_ListOfStatus.def("assign", (BRepCheck_ListOfStatus & (BRepCheck_ListOfStatus::*)(const BRepCheck_ListOfStatus &)) &BRepCheck_ListOfStatus::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BRepCheck_ListOfStatus.def("Clear", [](BRepCheck_ListOfStatus &self) -> void { return self.Clear(); });
	cls_BRepCheck_ListOfStatus.def("Clear", (void (BRepCheck_ListOfStatus::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepCheck_ListOfStatus::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BRepCheck_ListOfStatus.def("First", (const BRepCheck_Status & (BRepCheck_ListOfStatus::*)() const ) &BRepCheck_ListOfStatus::First, "First item");
	cls_BRepCheck_ListOfStatus.def("First", (BRepCheck_Status & (BRepCheck_ListOfStatus::*)()) &BRepCheck_ListOfStatus::First, "First item (non-const)");
	cls_BRepCheck_ListOfStatus.def("Last", (const BRepCheck_Status & (BRepCheck_ListOfStatus::*)() const ) &BRepCheck_ListOfStatus::Last, "Last item");
	cls_BRepCheck_ListOfStatus.def("Last", (BRepCheck_Status & (BRepCheck_ListOfStatus::*)()) &BRepCheck_ListOfStatus::Last, "Last item (non-const)");
	cls_BRepCheck_ListOfStatus.def("Append", (BRepCheck_Status & (BRepCheck_ListOfStatus::*)(const BRepCheck_Status &)) &BRepCheck_ListOfStatus::Append, "Append one item at the end", py::arg("theItem"));
	cls_BRepCheck_ListOfStatus.def("Append", (void (BRepCheck_ListOfStatus::*)(const BRepCheck_Status &, BRepCheck_ListOfStatus::Iterator &)) &BRepCheck_ListOfStatus::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BRepCheck_ListOfStatus.def("Append", (void (BRepCheck_ListOfStatus::*)(BRepCheck_ListOfStatus &)) &BRepCheck_ListOfStatus::Append, "Append another list at the end", py::arg("theOther"));
	cls_BRepCheck_ListOfStatus.def("Prepend", (BRepCheck_Status & (BRepCheck_ListOfStatus::*)(const BRepCheck_Status &)) &BRepCheck_ListOfStatus::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BRepCheck_ListOfStatus.def("Prepend", (void (BRepCheck_ListOfStatus::*)(BRepCheck_ListOfStatus &)) &BRepCheck_ListOfStatus::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BRepCheck_ListOfStatus.def("RemoveFirst", (void (BRepCheck_ListOfStatus::*)()) &BRepCheck_ListOfStatus::RemoveFirst, "RemoveFirst item");
	cls_BRepCheck_ListOfStatus.def("Remove", (void (BRepCheck_ListOfStatus::*)(BRepCheck_ListOfStatus::Iterator &)) &BRepCheck_ListOfStatus::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BRepCheck_ListOfStatus.def("InsertBefore", (BRepCheck_Status & (BRepCheck_ListOfStatus::*)(const BRepCheck_Status &, BRepCheck_ListOfStatus::Iterator &)) &BRepCheck_ListOfStatus::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BRepCheck_ListOfStatus.def("InsertBefore", (void (BRepCheck_ListOfStatus::*)(BRepCheck_ListOfStatus &, BRepCheck_ListOfStatus::Iterator &)) &BRepCheck_ListOfStatus::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BRepCheck_ListOfStatus.def("InsertAfter", (BRepCheck_Status & (BRepCheck_ListOfStatus::*)(const BRepCheck_Status &, BRepCheck_ListOfStatus::Iterator &)) &BRepCheck_ListOfStatus::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BRepCheck_ListOfStatus.def("InsertAfter", (void (BRepCheck_ListOfStatus::*)(BRepCheck_ListOfStatus &, BRepCheck_ListOfStatus::Iterator &)) &BRepCheck_ListOfStatus::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BRepCheck_ListOfStatus.def("Reverse", (void (BRepCheck_ListOfStatus::*)()) &BRepCheck_ListOfStatus::Reverse, "Reverse the list");
	cls_BRepCheck_ListOfStatus.def("__iter__", [](const BRepCheck_ListOfStatus &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BRepCheck_ListIteratorOfListOfStatus, std::unique_ptr<BRepCheck_ListIteratorOfListOfStatus, Deleter<BRepCheck_ListIteratorOfListOfStatus>>> cls_BRepCheck_ListIteratorOfListOfStatus(mod, "BRepCheck_ListIteratorOfListOfStatus", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BRepCheck_ListIteratorOfListOfStatus.def(py::init<>());
	cls_BRepCheck_ListIteratorOfListOfStatus.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BRepCheck_ListIteratorOfListOfStatus.def("More", (Standard_Boolean (BRepCheck_ListIteratorOfListOfStatus::*)() const ) &BRepCheck_ListIteratorOfListOfStatus::More, "Check end");
	cls_BRepCheck_ListIteratorOfListOfStatus.def("Next", (void (BRepCheck_ListIteratorOfListOfStatus::*)()) &BRepCheck_ListIteratorOfListOfStatus::Next, "Make step");
	cls_BRepCheck_ListIteratorOfListOfStatus.def("Value", (const BRepCheck_Status & (BRepCheck_ListIteratorOfListOfStatus::*)() const ) &BRepCheck_ListIteratorOfListOfStatus::Value, "Constant Value access");
	cls_BRepCheck_ListIteratorOfListOfStatus.def("Value", (BRepCheck_Status & (BRepCheck_ListIteratorOfListOfStatus::*)()) &BRepCheck_ListIteratorOfListOfStatus::Value, "Non-const Value access");
	cls_BRepCheck_ListIteratorOfListOfStatus.def("ChangeValue", (BRepCheck_Status & (BRepCheck_ListIteratorOfListOfStatus::*)() const ) &BRepCheck_ListIteratorOfListOfStatus::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepCheck_DataMapOfShapeListOfStatus, std::unique_ptr<BRepCheck_DataMapOfShapeListOfStatus, Deleter<BRepCheck_DataMapOfShapeListOfStatus>>, NCollection_BaseMap> cls_BRepCheck_DataMapOfShapeListOfStatus(mod, "BRepCheck_DataMapOfShapeListOfStatus", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepCheck_DataMapOfShapeListOfStatus.def(py::init<>());
	cls_BRepCheck_DataMapOfShapeListOfStatus.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def(py::init([] (const BRepCheck_DataMapOfShapeListOfStatus &other) {return new BRepCheck_DataMapOfShapeListOfStatus(other);}), "Copy constructor", py::arg("other"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("begin", (BRepCheck_DataMapOfShapeListOfStatus::iterator (BRepCheck_DataMapOfShapeListOfStatus::*)() const ) &BRepCheck_DataMapOfShapeListOfStatus::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("end", (BRepCheck_DataMapOfShapeListOfStatus::iterator (BRepCheck_DataMapOfShapeListOfStatus::*)() const ) &BRepCheck_DataMapOfShapeListOfStatus::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("cbegin", (BRepCheck_DataMapOfShapeListOfStatus::const_iterator (BRepCheck_DataMapOfShapeListOfStatus::*)() const ) &BRepCheck_DataMapOfShapeListOfStatus::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("cend", (BRepCheck_DataMapOfShapeListOfStatus::const_iterator (BRepCheck_DataMapOfShapeListOfStatus::*)() const ) &BRepCheck_DataMapOfShapeListOfStatus::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("Exchange", (void (BRepCheck_DataMapOfShapeListOfStatus::*)(BRepCheck_DataMapOfShapeListOfStatus &)) &BRepCheck_DataMapOfShapeListOfStatus::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("Assign", (BRepCheck_DataMapOfShapeListOfStatus & (BRepCheck_DataMapOfShapeListOfStatus::*)(const BRepCheck_DataMapOfShapeListOfStatus &)) &BRepCheck_DataMapOfShapeListOfStatus::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("assign", (BRepCheck_DataMapOfShapeListOfStatus & (BRepCheck_DataMapOfShapeListOfStatus::*)(const BRepCheck_DataMapOfShapeListOfStatus &)) &BRepCheck_DataMapOfShapeListOfStatus::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("ReSize", (void (BRepCheck_DataMapOfShapeListOfStatus::*)(const Standard_Integer)) &BRepCheck_DataMapOfShapeListOfStatus::ReSize, "ReSize", py::arg("N"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("Bind", (Standard_Boolean (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &, const BRepCheck_ListOfStatus &)) &BRepCheck_DataMapOfShapeListOfStatus::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepCheck_DataMapOfShapeListOfStatus.def("Bound", (BRepCheck_ListOfStatus * (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &, const BRepCheck_ListOfStatus &)) &BRepCheck_DataMapOfShapeListOfStatus::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("IsBound", (Standard_Boolean (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &) const ) &BRepCheck_DataMapOfShapeListOfStatus::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("UnBind", (Standard_Boolean (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &)) &BRepCheck_DataMapOfShapeListOfStatus::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepCheck_DataMapOfShapeListOfStatus.def("Seek", (const BRepCheck_ListOfStatus * (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &) const ) &BRepCheck_DataMapOfShapeListOfStatus::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepCheck_DataMapOfShapeListOfStatus.def("Find", (const BRepCheck_ListOfStatus & (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &) const ) &BRepCheck_DataMapOfShapeListOfStatus::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepCheck_DataMapOfShapeListOfStatus.def("Find", (Standard_Boolean (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &, BRepCheck_ListOfStatus &) const ) &BRepCheck_DataMapOfShapeListOfStatus::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("__call__", (const BRepCheck_ListOfStatus & (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &) const ) &BRepCheck_DataMapOfShapeListOfStatus::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepCheck_DataMapOfShapeListOfStatus.def("ChangeSeek", (BRepCheck_ListOfStatus * (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &)) &BRepCheck_DataMapOfShapeListOfStatus::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("ChangeFind", (BRepCheck_ListOfStatus & (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &)) &BRepCheck_DataMapOfShapeListOfStatus::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("__call__", (BRepCheck_ListOfStatus & (BRepCheck_DataMapOfShapeListOfStatus::*)(const TopoDS_Shape &)) &BRepCheck_DataMapOfShapeListOfStatus::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("Clear", [](BRepCheck_DataMapOfShapeListOfStatus &self) -> void { return self.Clear(); });
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("Clear", (void (BRepCheck_DataMapOfShapeListOfStatus::*)(const Standard_Boolean)) &BRepCheck_DataMapOfShapeListOfStatus::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("Clear", (void (BRepCheck_DataMapOfShapeListOfStatus::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepCheck_DataMapOfShapeListOfStatus::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("Size", (Standard_Integer (BRepCheck_DataMapOfShapeListOfStatus::*)() const ) &BRepCheck_DataMapOfShapeListOfStatus::Size, "Size");
	cls_BRepCheck_DataMapOfShapeListOfStatus.def("__iter__", [](const BRepCheck_DataMapOfShapeListOfStatus &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_DataMapOfShapeListOfStatus.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepCheck_DataMapOfShapeResult, std::unique_ptr<BRepCheck_DataMapOfShapeResult, Deleter<BRepCheck_DataMapOfShapeResult>>, NCollection_BaseMap> cls_BRepCheck_DataMapOfShapeResult(mod, "BRepCheck_DataMapOfShapeResult", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepCheck_DataMapOfShapeResult.def(py::init<>());
	cls_BRepCheck_DataMapOfShapeResult.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepCheck_DataMapOfShapeResult.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepCheck_DataMapOfShapeResult.def(py::init([] (const BRepCheck_DataMapOfShapeResult &other) {return new BRepCheck_DataMapOfShapeResult(other);}), "Copy constructor", py::arg("other"));
	cls_BRepCheck_DataMapOfShapeResult.def("begin", (BRepCheck_DataMapOfShapeResult::iterator (BRepCheck_DataMapOfShapeResult::*)() const ) &BRepCheck_DataMapOfShapeResult::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepCheck_DataMapOfShapeResult.def("end", (BRepCheck_DataMapOfShapeResult::iterator (BRepCheck_DataMapOfShapeResult::*)() const ) &BRepCheck_DataMapOfShapeResult::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepCheck_DataMapOfShapeResult.def("cbegin", (BRepCheck_DataMapOfShapeResult::const_iterator (BRepCheck_DataMapOfShapeResult::*)() const ) &BRepCheck_DataMapOfShapeResult::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepCheck_DataMapOfShapeResult.def("cend", (BRepCheck_DataMapOfShapeResult::const_iterator (BRepCheck_DataMapOfShapeResult::*)() const ) &BRepCheck_DataMapOfShapeResult::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepCheck_DataMapOfShapeResult.def("Exchange", (void (BRepCheck_DataMapOfShapeResult::*)(BRepCheck_DataMapOfShapeResult &)) &BRepCheck_DataMapOfShapeResult::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepCheck_DataMapOfShapeResult.def("Assign", (BRepCheck_DataMapOfShapeResult & (BRepCheck_DataMapOfShapeResult::*)(const BRepCheck_DataMapOfShapeResult &)) &BRepCheck_DataMapOfShapeResult::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepCheck_DataMapOfShapeResult.def("assign", (BRepCheck_DataMapOfShapeResult & (BRepCheck_DataMapOfShapeResult::*)(const BRepCheck_DataMapOfShapeResult &)) &BRepCheck_DataMapOfShapeResult::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepCheck_DataMapOfShapeResult.def("ReSize", (void (BRepCheck_DataMapOfShapeResult::*)(const Standard_Integer)) &BRepCheck_DataMapOfShapeResult::ReSize, "ReSize", py::arg("N"));
	cls_BRepCheck_DataMapOfShapeResult.def("Bind", (Standard_Boolean (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &, const opencascade::handle<BRepCheck_Result> &)) &BRepCheck_DataMapOfShapeResult::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepCheck_DataMapOfShapeResult.def("Bound", (opencascade::handle<BRepCheck_Result> * (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &, const opencascade::handle<BRepCheck_Result> &)) &BRepCheck_DataMapOfShapeResult::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepCheck_DataMapOfShapeResult.def("IsBound", (Standard_Boolean (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &) const ) &BRepCheck_DataMapOfShapeResult::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepCheck_DataMapOfShapeResult.def("UnBind", (Standard_Boolean (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &)) &BRepCheck_DataMapOfShapeResult::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepCheck_DataMapOfShapeResult.def("Seek", (const opencascade::handle<BRepCheck_Result> * (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &) const ) &BRepCheck_DataMapOfShapeResult::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepCheck_DataMapOfShapeResult.def("Find", (const opencascade::handle<BRepCheck_Result> & (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &) const ) &BRepCheck_DataMapOfShapeResult::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepCheck_DataMapOfShapeResult.def("Find", (Standard_Boolean (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &, opencascade::handle<BRepCheck_Result> &) const ) &BRepCheck_DataMapOfShapeResult::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepCheck_DataMapOfShapeResult.def("__call__", (const opencascade::handle<BRepCheck_Result> & (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &) const ) &BRepCheck_DataMapOfShapeResult::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepCheck_DataMapOfShapeResult.def("ChangeSeek", (opencascade::handle<BRepCheck_Result> * (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &)) &BRepCheck_DataMapOfShapeResult::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepCheck_DataMapOfShapeResult.def("ChangeFind", (opencascade::handle<BRepCheck_Result> & (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &)) &BRepCheck_DataMapOfShapeResult::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepCheck_DataMapOfShapeResult.def("__call__", (opencascade::handle<BRepCheck_Result> & (BRepCheck_DataMapOfShapeResult::*)(const TopoDS_Shape &)) &BRepCheck_DataMapOfShapeResult::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepCheck_DataMapOfShapeResult.def("Clear", [](BRepCheck_DataMapOfShapeResult &self) -> void { return self.Clear(); });
	cls_BRepCheck_DataMapOfShapeResult.def("Clear", (void (BRepCheck_DataMapOfShapeResult::*)(const Standard_Boolean)) &BRepCheck_DataMapOfShapeResult::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepCheck_DataMapOfShapeResult.def("Clear", (void (BRepCheck_DataMapOfShapeResult::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepCheck_DataMapOfShapeResult::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepCheck_DataMapOfShapeResult.def("Size", (Standard_Integer (BRepCheck_DataMapOfShapeResult::*)() const ) &BRepCheck_DataMapOfShapeResult::Size, "Size");
	cls_BRepCheck_DataMapOfShapeResult.def("__iter__", [](const BRepCheck_DataMapOfShapeResult &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepCheck_DataMapOfShapeResult.hxx

}
