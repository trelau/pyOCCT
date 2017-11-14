#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Adaptor3d_TopolTool.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Type.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>
#include <TopoDS_Face.hxx>
#include <BRepTopAdaptor_FClass2d.hxx>
#include <BRepTopAdaptor_SeqOfPtr.hxx>
#include <BRepTopAdaptor_Tool.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <BRepTopAdaptor_HVertex.hxx>

PYBIND11_MODULE(BRepTopAdaptor, mod) {

	// IMPORT
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.BRepAdaptor");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepTopAdaptor_TopolTool.hxx
	py::class_<BRepTopAdaptor_TopolTool, opencascade::handle<BRepTopAdaptor_TopolTool>, Adaptor3d_TopolTool> cls_BRepTopAdaptor_TopolTool(mod, "BRepTopAdaptor_TopolTool", "None");
	cls_BRepTopAdaptor_TopolTool.def(py::init<>());
	cls_BRepTopAdaptor_TopolTool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("Surface"));
	cls_BRepTopAdaptor_TopolTool.def("Initialize", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Initialize, "None");
	cls_BRepTopAdaptor_TopolTool.def("Initialize", (void (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepTopAdaptor_TopolTool::Initialize, "None", py::arg("S"));
	cls_BRepTopAdaptor_TopolTool.def("Initialize", (void (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepTopAdaptor_TopolTool::Initialize, "None", py::arg("Curve"));
	cls_BRepTopAdaptor_TopolTool.def("Init", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Init, "None");
	cls_BRepTopAdaptor_TopolTool.def("More", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::More, "None");
	cls_BRepTopAdaptor_TopolTool.def("Value", (opencascade::handle<Adaptor2d_HCurve2d> (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Value, "None");
	cls_BRepTopAdaptor_TopolTool.def("Next", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Next, "None");
	cls_BRepTopAdaptor_TopolTool.def("Edge", (Standard_Address (BRepTopAdaptor_TopolTool::*)() const ) &BRepTopAdaptor_TopolTool::Edge, "None");
	cls_BRepTopAdaptor_TopolTool.def("InitVertexIterator", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::InitVertexIterator, "None");
	cls_BRepTopAdaptor_TopolTool.def("MoreVertex", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::MoreVertex, "None");
	cls_BRepTopAdaptor_TopolTool.def("Vertex", (opencascade::handle<Adaptor3d_HVertex> (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Vertex, "None");
	cls_BRepTopAdaptor_TopolTool.def("NextVertex", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::NextVertex, "None");
	cls_BRepTopAdaptor_TopolTool.def("Classify", [](BRepTopAdaptor_TopolTool &self, const gp_Pnt2d & a0, const Standard_Real a1) -> TopAbs_State { return self.Classify(a0, a1); }, py::arg("P2d"), py::arg("Tol"));
	cls_BRepTopAdaptor_TopolTool.def("Classify", (TopAbs_State (BRepTopAdaptor_TopolTool::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &BRepTopAdaptor_TopolTool::Classify, "None", py::arg("P2d"), py::arg("Tol"), py::arg("RecadreOnPeriodic"));
	cls_BRepTopAdaptor_TopolTool.def("IsThePointOn", [](BRepTopAdaptor_TopolTool &self, const gp_Pnt2d & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsThePointOn(a0, a1); }, py::arg("P2d"), py::arg("Tol"));
	cls_BRepTopAdaptor_TopolTool.def("IsThePointOn", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &BRepTopAdaptor_TopolTool::IsThePointOn, "see the code for specifications)", py::arg("P2d"), py::arg("Tol"), py::arg("RecadreOnPeriodic"));
	cls_BRepTopAdaptor_TopolTool.def("Orientation", (TopAbs_Orientation (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepTopAdaptor_TopolTool::Orientation, "If the function returns the orientation of the arc. If the orientation is FORWARD or REVERSED, the arc is a 'real' limit of the surface. If the orientation is INTERNAL or EXTERNAL, the arc is considered as an arc on the surface.", py::arg("C"));
	cls_BRepTopAdaptor_TopolTool.def("Orientation", (TopAbs_Orientation (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &BRepTopAdaptor_TopolTool::Orientation, "If the function returns the orientation of the arc. If the orientation is FORWARD or REVERSED, the arc is a 'real' limit of the surface. If the orientation is INTERNAL or EXTERNAL, the arc is considered as an arc on the surface.", py::arg("C"));
	cls_BRepTopAdaptor_TopolTool.def("Destroy", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Destroy, "None");
	cls_BRepTopAdaptor_TopolTool.def("Has3d", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)() const ) &BRepTopAdaptor_TopolTool::Has3d, "answers if arcs and vertices may have 3d representations, so that we could use Tol3d and Pnt methods.");
	cls_BRepTopAdaptor_TopolTool.def("Tol3d", (Standard_Real (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &) const ) &BRepTopAdaptor_TopolTool::Tol3d, "returns 3d tolerance of the arc C", py::arg("C"));
	cls_BRepTopAdaptor_TopolTool.def("Tol3d", (Standard_Real (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &) const ) &BRepTopAdaptor_TopolTool::Tol3d, "returns 3d tolerance of the vertex V", py::arg("V"));
	cls_BRepTopAdaptor_TopolTool.def("Pnt", (gp_Pnt (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &) const ) &BRepTopAdaptor_TopolTool::Pnt, "returns 3d point of the vertex V", py::arg("V"));
	cls_BRepTopAdaptor_TopolTool.def("ComputeSamplePoints", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::ComputeSamplePoints, "None");
	cls_BRepTopAdaptor_TopolTool.def("NbSamplesU", (Standard_Integer (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::NbSamplesU, "compute the sample-points for the intersections algorithms");
	cls_BRepTopAdaptor_TopolTool.def("NbSamplesV", (Standard_Integer (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::NbSamplesV, "compute the sample-points for the intersections algorithms");
	cls_BRepTopAdaptor_TopolTool.def("NbSamples", (Standard_Integer (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::NbSamples, "compute the sample-points for the intersections algorithms");
	cls_BRepTopAdaptor_TopolTool.def("SamplePoint", (void (BRepTopAdaptor_TopolTool::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt &)) &BRepTopAdaptor_TopolTool::SamplePoint, "None", py::arg("Index"), py::arg("P2d"), py::arg("P3d"));
	cls_BRepTopAdaptor_TopolTool.def("DomainIsInfinite", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::DomainIsInfinite, "None");
	cls_BRepTopAdaptor_TopolTool.def_static("get_type_name_", (const char * (*)()) &BRepTopAdaptor_TopolTool::get_type_name, "None");
	cls_BRepTopAdaptor_TopolTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTopAdaptor_TopolTool::get_type_descriptor, "None");
	cls_BRepTopAdaptor_TopolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTopAdaptor_TopolTool::*)() const ) &BRepTopAdaptor_TopolTool::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepTopAdaptor_FClass2d.hxx
	py::class_<BRepTopAdaptor_FClass2d, std::unique_ptr<BRepTopAdaptor_FClass2d, Deleter<BRepTopAdaptor_FClass2d>>> cls_BRepTopAdaptor_FClass2d(mod, "BRepTopAdaptor_FClass2d", "None");
	cls_BRepTopAdaptor_FClass2d.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("Tol"));
	cls_BRepTopAdaptor_FClass2d.def("PerformInfinitePoint", (TopAbs_State (BRepTopAdaptor_FClass2d::*)() const ) &BRepTopAdaptor_FClass2d::PerformInfinitePoint, "None");
	cls_BRepTopAdaptor_FClass2d.def("Perform", [](BRepTopAdaptor_FClass2d &self, const gp_Pnt2d & a0) -> TopAbs_State { return self.Perform(a0); }, py::arg("Puv"));
	cls_BRepTopAdaptor_FClass2d.def("Perform", (TopAbs_State (BRepTopAdaptor_FClass2d::*)(const gp_Pnt2d &, const Standard_Boolean) const ) &BRepTopAdaptor_FClass2d::Perform, "None", py::arg("Puv"), py::arg("RecadreOnPeriodic"));
	cls_BRepTopAdaptor_FClass2d.def("Destroy", (void (BRepTopAdaptor_FClass2d::*)()) &BRepTopAdaptor_FClass2d::Destroy, "None");
	cls_BRepTopAdaptor_FClass2d.def("Copy", (const BRepTopAdaptor_FClass2d & (BRepTopAdaptor_FClass2d::*)(const BRepTopAdaptor_FClass2d &) const ) &BRepTopAdaptor_FClass2d::Copy, "None", py::arg("Other"));
	cls_BRepTopAdaptor_FClass2d.def("assign", (const BRepTopAdaptor_FClass2d & (BRepTopAdaptor_FClass2d::*)(const BRepTopAdaptor_FClass2d &) const ) &BRepTopAdaptor_FClass2d::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_BRepTopAdaptor_FClass2d.def("TestOnRestriction", [](BRepTopAdaptor_FClass2d &self, const gp_Pnt2d & a0, const Standard_Real a1) -> TopAbs_State { return self.TestOnRestriction(a0, a1); }, py::arg("Puv"), py::arg("Tol"));
	cls_BRepTopAdaptor_FClass2d.def("TestOnRestriction", (TopAbs_State (BRepTopAdaptor_FClass2d::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean) const ) &BRepTopAdaptor_FClass2d::TestOnRestriction, "Test a point with +- an offset (Tol) and returns On if some points are OUT an some are IN (Caution: Internal use . see the code for more details)", py::arg("Puv"), py::arg("Tol"), py::arg("RecadreOnPeriodic"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepTopAdaptor_Tool.hxx
	py::class_<BRepTopAdaptor_Tool, std::unique_ptr<BRepTopAdaptor_Tool, Deleter<BRepTopAdaptor_Tool>>> cls_BRepTopAdaptor_Tool(mod, "BRepTopAdaptor_Tool", "None");
	cls_BRepTopAdaptor_Tool.def(py::init<>());
	cls_BRepTopAdaptor_Tool.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("Tol2d"));
	cls_BRepTopAdaptor_Tool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("Surface"), py::arg("Tol2d"));
	cls_BRepTopAdaptor_Tool.def("Init", (void (BRepTopAdaptor_Tool::*)(const TopoDS_Face &, const Standard_Real)) &BRepTopAdaptor_Tool::Init, "None", py::arg("F"), py::arg("Tol2d"));
	cls_BRepTopAdaptor_Tool.def("Init", (void (BRepTopAdaptor_Tool::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real)) &BRepTopAdaptor_Tool::Init, "None", py::arg("Surface"), py::arg("Tol2d"));
	cls_BRepTopAdaptor_Tool.def("GetTopolTool", (opencascade::handle<BRepTopAdaptor_TopolTool> (BRepTopAdaptor_Tool::*)()) &BRepTopAdaptor_Tool::GetTopolTool, "None");
	cls_BRepTopAdaptor_Tool.def("SetTopolTool", (void (BRepTopAdaptor_Tool::*)(const opencascade::handle<BRepTopAdaptor_TopolTool> &)) &BRepTopAdaptor_Tool::SetTopolTool, "None", py::arg("TT"));
	cls_BRepTopAdaptor_Tool.def("GetSurface", (opencascade::handle<Adaptor3d_HSurface> (BRepTopAdaptor_Tool::*)()) &BRepTopAdaptor_Tool::GetSurface, "None");
	cls_BRepTopAdaptor_Tool.def("Destroy", (void (BRepTopAdaptor_Tool::*)()) &BRepTopAdaptor_Tool::Destroy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepTopAdaptor_HVertex.hxx
	py::class_<BRepTopAdaptor_HVertex, opencascade::handle<BRepTopAdaptor_HVertex>, Adaptor3d_HVertex> cls_BRepTopAdaptor_HVertex(mod, "BRepTopAdaptor_HVertex", "None");
	cls_BRepTopAdaptor_HVertex.def(py::init<const TopoDS_Vertex &, const opencascade::handle<BRepAdaptor_HCurve2d> &>(), py::arg("Vtx"), py::arg("Curve"));
	cls_BRepTopAdaptor_HVertex.def("Vertex", (const TopoDS_Vertex & (BRepTopAdaptor_HVertex::*)() const ) &BRepTopAdaptor_HVertex::Vertex, "None");
	cls_BRepTopAdaptor_HVertex.def("ChangeVertex", (TopoDS_Vertex & (BRepTopAdaptor_HVertex::*)()) &BRepTopAdaptor_HVertex::ChangeVertex, "None");
	cls_BRepTopAdaptor_HVertex.def("Value", (gp_Pnt2d (BRepTopAdaptor_HVertex::*)()) &BRepTopAdaptor_HVertex::Value, "None");
	cls_BRepTopAdaptor_HVertex.def("Parameter", (Standard_Real (BRepTopAdaptor_HVertex::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepTopAdaptor_HVertex::Parameter, "None", py::arg("C"));
	cls_BRepTopAdaptor_HVertex.def("Resolution", (Standard_Real (BRepTopAdaptor_HVertex::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepTopAdaptor_HVertex::Resolution, "Parametric resolution (2d).", py::arg("C"));
	cls_BRepTopAdaptor_HVertex.def("Orientation", (TopAbs_Orientation (BRepTopAdaptor_HVertex::*)()) &BRepTopAdaptor_HVertex::Orientation, "None");
	cls_BRepTopAdaptor_HVertex.def("IsSame", (Standard_Boolean (BRepTopAdaptor_HVertex::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &BRepTopAdaptor_HVertex::IsSame, "None", py::arg("Other"));
	cls_BRepTopAdaptor_HVertex.def_static("get_type_name_", (const char * (*)()) &BRepTopAdaptor_HVertex::get_type_name, "None");
	cls_BRepTopAdaptor_HVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTopAdaptor_HVertex::get_type_descriptor, "None");
	cls_BRepTopAdaptor_HVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTopAdaptor_HVertex::*)() const ) &BRepTopAdaptor_HVertex::DynamicType, "None");

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_SequenceOfAddress")) {
		mod.attr("BRepTopAdaptor_SeqOfPtr") = other_mod.attr("TColStd_SequenceOfAddress");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BRepTopAdaptor_MapOfShapeTool, std::unique_ptr<BRepTopAdaptor_MapOfShapeTool, Deleter<BRepTopAdaptor_MapOfShapeTool>>, NCollection_BaseMap> cls_BRepTopAdaptor_MapOfShapeTool(mod, "BRepTopAdaptor_MapOfShapeTool", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BRepTopAdaptor_MapOfShapeTool.def(py::init<>());
	cls_BRepTopAdaptor_MapOfShapeTool.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BRepTopAdaptor_MapOfShapeTool.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BRepTopAdaptor_MapOfShapeTool.def(py::init([] (const BRepTopAdaptor_MapOfShapeTool &other) {return new BRepTopAdaptor_MapOfShapeTool(other);}), "Copy constructor", py::arg("other"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("begin", (BRepTopAdaptor_MapOfShapeTool::iterator (BRepTopAdaptor_MapOfShapeTool::*)() const ) &BRepTopAdaptor_MapOfShapeTool::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BRepTopAdaptor_MapOfShapeTool.def("end", (BRepTopAdaptor_MapOfShapeTool::iterator (BRepTopAdaptor_MapOfShapeTool::*)() const ) &BRepTopAdaptor_MapOfShapeTool::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BRepTopAdaptor_MapOfShapeTool.def("cbegin", (BRepTopAdaptor_MapOfShapeTool::const_iterator (BRepTopAdaptor_MapOfShapeTool::*)() const ) &BRepTopAdaptor_MapOfShapeTool::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BRepTopAdaptor_MapOfShapeTool.def("cend", (BRepTopAdaptor_MapOfShapeTool::const_iterator (BRepTopAdaptor_MapOfShapeTool::*)() const ) &BRepTopAdaptor_MapOfShapeTool::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BRepTopAdaptor_MapOfShapeTool.def("Exchange", (void (BRepTopAdaptor_MapOfShapeTool::*)(BRepTopAdaptor_MapOfShapeTool &)) &BRepTopAdaptor_MapOfShapeTool::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("Assign", (BRepTopAdaptor_MapOfShapeTool & (BRepTopAdaptor_MapOfShapeTool::*)(const BRepTopAdaptor_MapOfShapeTool &)) &BRepTopAdaptor_MapOfShapeTool::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("assign", (BRepTopAdaptor_MapOfShapeTool & (BRepTopAdaptor_MapOfShapeTool::*)(const BRepTopAdaptor_MapOfShapeTool &)) &BRepTopAdaptor_MapOfShapeTool::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("ReSize", (void (BRepTopAdaptor_MapOfShapeTool::*)(const Standard_Integer)) &BRepTopAdaptor_MapOfShapeTool::ReSize, "ReSize", py::arg("N"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("Bind", (Standard_Boolean (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &, const BRepTopAdaptor_Tool &)) &BRepTopAdaptor_MapOfShapeTool::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BRepTopAdaptor_MapOfShapeTool.def("Bound", (BRepTopAdaptor_Tool * (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &, const BRepTopAdaptor_Tool &)) &BRepTopAdaptor_MapOfShapeTool::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("IsBound", (Standard_Boolean (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &) const ) &BRepTopAdaptor_MapOfShapeTool::IsBound, "IsBound", py::arg("theKey"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("UnBind", (Standard_Boolean (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &)) &BRepTopAdaptor_MapOfShapeTool::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BRepTopAdaptor_MapOfShapeTool.def("Seek", (const BRepTopAdaptor_Tool * (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &) const ) &BRepTopAdaptor_MapOfShapeTool::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BRepTopAdaptor_MapOfShapeTool.def("Find", (const BRepTopAdaptor_Tool & (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &) const ) &BRepTopAdaptor_MapOfShapeTool::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BRepTopAdaptor_MapOfShapeTool.def("Find", (Standard_Boolean (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &, BRepTopAdaptor_Tool &) const ) &BRepTopAdaptor_MapOfShapeTool::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("__call__", (const BRepTopAdaptor_Tool & (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &) const ) &BRepTopAdaptor_MapOfShapeTool::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BRepTopAdaptor_MapOfShapeTool.def("ChangeSeek", (BRepTopAdaptor_Tool * (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &)) &BRepTopAdaptor_MapOfShapeTool::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("ChangeFind", (BRepTopAdaptor_Tool & (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &)) &BRepTopAdaptor_MapOfShapeTool::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("__call__", (BRepTopAdaptor_Tool & (BRepTopAdaptor_MapOfShapeTool::*)(const TopoDS_Shape &)) &BRepTopAdaptor_MapOfShapeTool::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("Clear", [](BRepTopAdaptor_MapOfShapeTool &self) -> void { return self.Clear(); });
	cls_BRepTopAdaptor_MapOfShapeTool.def("Clear", (void (BRepTopAdaptor_MapOfShapeTool::*)(const Standard_Boolean)) &BRepTopAdaptor_MapOfShapeTool::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("Clear", (void (BRepTopAdaptor_MapOfShapeTool::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRepTopAdaptor_MapOfShapeTool::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BRepTopAdaptor_MapOfShapeTool.def("Size", (Standard_Integer (BRepTopAdaptor_MapOfShapeTool::*)() const ) &BRepTopAdaptor_MapOfShapeTool::Size, "Size");
	cls_BRepTopAdaptor_MapOfShapeTool.def("__iter__", [](const BRepTopAdaptor_MapOfShapeTool &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepTopAdaptor_MapOfShapeTool.hxx

}
