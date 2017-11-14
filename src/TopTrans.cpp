#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <TopTrans_CurveTransition.hxx>
#include <NCollection_Array2.hxx>
#include <TopTrans_Array2OfOrientation.hxx>
#include <TopTrans_SurfaceTransition.hxx>

PYBIND11_MODULE(TopTrans, mod) {

	// IMPORT
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTrans_CurveTransition.hxx
	py::class_<TopTrans_CurveTransition, std::unique_ptr<TopTrans_CurveTransition, Deleter<TopTrans_CurveTransition>>> cls_TopTrans_CurveTransition(mod, "TopTrans_CurveTransition", "This algorithm is used to compute the transition of a Curve intersecting a curvilinear boundary.");
	cls_TopTrans_CurveTransition.def(py::init<>());
	cls_TopTrans_CurveTransition.def("Reset", (void (TopTrans_CurveTransition::*)(const gp_Dir &, const gp_Dir &, const Standard_Real)) &TopTrans_CurveTransition::Reset, "Initialize a Transition with the local description of a Curve.", py::arg("Tgt"), py::arg("Norm"), py::arg("Curv"));
	cls_TopTrans_CurveTransition.def("Reset", (void (TopTrans_CurveTransition::*)(const gp_Dir &)) &TopTrans_CurveTransition::Reset, "Initialize a Transition with the local description of a straigth line.", py::arg("Tgt"));
	cls_TopTrans_CurveTransition.def("Compare", (void (TopTrans_CurveTransition::*)(const Standard_Real, const gp_Dir &, const gp_Dir &, const Standard_Real, const TopAbs_Orientation, const TopAbs_Orientation)) &TopTrans_CurveTransition::Compare, "Add a curve element to the boundary. If Or is REVERSED the curve is before the intersection, else if Or is FORWARD the curv is after the intersection and if Or is INTERNAL the intersection is in the middle of the curv.", py::arg("Tole"), py::arg("Tang"), py::arg("Norm"), py::arg("Curv"), py::arg("S"), py::arg("Or"));
	cls_TopTrans_CurveTransition.def("StateBefore", (TopAbs_State (TopTrans_CurveTransition::*)() const ) &TopTrans_CurveTransition::StateBefore, "returns the state of the curve before the intersection, this is the position relative to the boundary of a point very close to the intersection on the negative side of the tangent.");
	cls_TopTrans_CurveTransition.def("StateAfter", (TopAbs_State (TopTrans_CurveTransition::*)() const ) &TopTrans_CurveTransition::StateAfter, "returns the state of the curve after the intersection, this is the position relative to the boundary of a point very close to the intersection on the positive side of the tangent.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTrans_SurfaceTransition.hxx
	py::class_<TopTrans_SurfaceTransition, std::unique_ptr<TopTrans_SurfaceTransition, Deleter<TopTrans_SurfaceTransition>>> cls_TopTrans_SurfaceTransition(mod, "TopTrans_SurfaceTransition", "This algorithm is used to compute the transition of a 3D surface intersecting a topological surfacic boundary on a 3D curve ( intersection curve ). The boundary is described by a set of faces each face is described by - its support surface, - an orientation defining its matter side. The geometric elements are described locally at the intersection point by a second order development. A surface is described by the normal vector, the principal directions and the principal curvatures. A curve is described by the tangent, the normal and the curvature. The algorithm keeps track of the two faces elements closest to the part of the curve 'before' and 'after' the intersection, these two elements are updated for each new face. The position of the curve can be computed when at least one surface element has been given, this position is 'In','Out' or 'On' for the part of the curve 'Before' or 'After' the intersection.");
	cls_TopTrans_SurfaceTransition.def(py::init<>());
	cls_TopTrans_SurfaceTransition.def("Reset", (void (TopTrans_SurfaceTransition::*)(const gp_Dir &, const gp_Dir &, const gp_Dir &, const gp_Dir &, const Standard_Real, const Standard_Real)) &TopTrans_SurfaceTransition::Reset, "Initialize a Surface Transition with the local description of the intersection curve and of the reference surface. PREQUESITORY : Norm oriented OUTSIDE 'geometric matter'", py::arg("Tgt"), py::arg("Norm"), py::arg("MaxD"), py::arg("MinD"), py::arg("MaxCurv"), py::arg("MinCurv"));
	cls_TopTrans_SurfaceTransition.def("Reset", (void (TopTrans_SurfaceTransition::*)(const gp_Dir &, const gp_Dir &)) &TopTrans_SurfaceTransition::Reset, "Initialize a Surface Transition with the local description of a straight line.", py::arg("Tgt"), py::arg("Norm"));
	cls_TopTrans_SurfaceTransition.def("Compare", (void (TopTrans_SurfaceTransition::*)(const Standard_Real, const gp_Dir &, const gp_Dir &, const gp_Dir &, const Standard_Real, const Standard_Real, const TopAbs_Orientation, const TopAbs_Orientation)) &TopTrans_SurfaceTransition::Compare, "Add a face element to the boundary.", py::arg("Tole"), py::arg("Norm"), py::arg("MaxD"), py::arg("MinD"), py::arg("MaxCurv"), py::arg("MinCurv"), py::arg("S"), py::arg("O"));
	cls_TopTrans_SurfaceTransition.def("Compare", (void (TopTrans_SurfaceTransition::*)(const Standard_Real, const gp_Dir &, const TopAbs_Orientation, const TopAbs_Orientation)) &TopTrans_SurfaceTransition::Compare, "Add a plane or a cylindric face to the boundary.", py::arg("Tole"), py::arg("Norm"), py::arg("S"), py::arg("O"));
	cls_TopTrans_SurfaceTransition.def("StateBefore", (TopAbs_State (TopTrans_SurfaceTransition::*)() const ) &TopTrans_SurfaceTransition::StateBefore, "Returns the state of the reference surface before the interference, this is the position relative to the surface of a point very close to the intersection on the negative side of the tangent.");
	cls_TopTrans_SurfaceTransition.def("StateAfter", (TopAbs_State (TopTrans_SurfaceTransition::*)() const ) &TopTrans_SurfaceTransition::StateAfter, "Returns the state of the reference surface after interference, this is the position relative to the surface of a point very close to the intersection on the positive side of the tangent.");
	cls_TopTrans_SurfaceTransition.def_static("GetBefore_", (TopAbs_State (*)(const TopAbs_Orientation)) &TopTrans_SurfaceTransition::GetBefore, "None", py::arg("Tran"));
	cls_TopTrans_SurfaceTransition.def_static("GetAfter_", (TopAbs_State (*)(const TopAbs_Orientation)) &TopTrans_SurfaceTransition::GetAfter, "None", py::arg("Tran"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TopTrans_Array2OfOrientation, std::unique_ptr<TopTrans_Array2OfOrientation, Deleter<TopTrans_Array2OfOrientation>>> cls_TopTrans_Array2OfOrientation(mod, "TopTrans_Array2OfOrientation", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TopTrans_Array2OfOrientation.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TopTrans_Array2OfOrientation.def(py::init([] (const TopTrans_Array2OfOrientation &other) {return new TopTrans_Array2OfOrientation(other);}), "Copy constructor", py::arg("other"));
	cls_TopTrans_Array2OfOrientation.def(py::init<const TopAbs_Orientation &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TopTrans_Array2OfOrientation.def("Init", (void (TopTrans_Array2OfOrientation::*)(const TopAbs_Orientation &)) &TopTrans_Array2OfOrientation::Init, "Initialise the values", py::arg("theValue"));
	cls_TopTrans_Array2OfOrientation.def("Size", (Standard_Integer (TopTrans_Array2OfOrientation::*)() const ) &TopTrans_Array2OfOrientation::Size, "Size (number of items)");
	cls_TopTrans_Array2OfOrientation.def("Length", (Standard_Integer (TopTrans_Array2OfOrientation::*)() const ) &TopTrans_Array2OfOrientation::Length, "Length (number of items)");
	cls_TopTrans_Array2OfOrientation.def("RowLength", (Standard_Integer (TopTrans_Array2OfOrientation::*)() const ) &TopTrans_Array2OfOrientation::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TopTrans_Array2OfOrientation.def("ColLength", (Standard_Integer (TopTrans_Array2OfOrientation::*)() const ) &TopTrans_Array2OfOrientation::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TopTrans_Array2OfOrientation.def("LowerRow", (Standard_Integer (TopTrans_Array2OfOrientation::*)() const ) &TopTrans_Array2OfOrientation::LowerRow, "LowerRow");
	cls_TopTrans_Array2OfOrientation.def("UpperRow", (Standard_Integer (TopTrans_Array2OfOrientation::*)() const ) &TopTrans_Array2OfOrientation::UpperRow, "UpperRow");
	cls_TopTrans_Array2OfOrientation.def("LowerCol", (Standard_Integer (TopTrans_Array2OfOrientation::*)() const ) &TopTrans_Array2OfOrientation::LowerCol, "LowerCol");
	cls_TopTrans_Array2OfOrientation.def("UpperCol", (Standard_Integer (TopTrans_Array2OfOrientation::*)() const ) &TopTrans_Array2OfOrientation::UpperCol, "UpperCol");
	cls_TopTrans_Array2OfOrientation.def("IsDeletable", (Standard_Boolean (TopTrans_Array2OfOrientation::*)() const ) &TopTrans_Array2OfOrientation::IsDeletable, "myDeletable flag");
	cls_TopTrans_Array2OfOrientation.def("Assign", (TopTrans_Array2OfOrientation & (TopTrans_Array2OfOrientation::*)(const TopTrans_Array2OfOrientation &)) &TopTrans_Array2OfOrientation::Assign, "Assignment", py::arg("theOther"));
	cls_TopTrans_Array2OfOrientation.def("assign", (TopTrans_Array2OfOrientation & (TopTrans_Array2OfOrientation::*)(const TopTrans_Array2OfOrientation &)) &TopTrans_Array2OfOrientation::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopTrans_Array2OfOrientation.def("Value", (const TopAbs_Orientation & (TopTrans_Array2OfOrientation::*)(const Standard_Integer, const Standard_Integer) const ) &TopTrans_Array2OfOrientation::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TopTrans_Array2OfOrientation.def("__call__", (const TopAbs_Orientation & (TopTrans_Array2OfOrientation::*)(const Standard_Integer, const Standard_Integer) const ) &TopTrans_Array2OfOrientation::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TopTrans_Array2OfOrientation.def("ChangeValue", (TopAbs_Orientation & (TopTrans_Array2OfOrientation::*)(const Standard_Integer, const Standard_Integer)) &TopTrans_Array2OfOrientation::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TopTrans_Array2OfOrientation.def("__call__", (TopAbs_Orientation & (TopTrans_Array2OfOrientation::*)(const Standard_Integer, const Standard_Integer)) &TopTrans_Array2OfOrientation::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TopTrans_Array2OfOrientation.def("SetValue", (void (TopTrans_Array2OfOrientation::*)(const Standard_Integer, const Standard_Integer, const TopAbs_Orientation &)) &TopTrans_Array2OfOrientation::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));


}
