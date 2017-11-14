#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_OStream.hxx>
#include <AppParCurves_MultiPoint.hxx>
#include <NCollection_Array1.hxx>
#include <AppParCurves_Array1OfMultiPoint.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <AppParCurves_HArray1OfMultiPoint.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_Constraint.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <AppParCurves_ConstraintCouple.hxx>
#include <AppParCurves_Array1OfConstraintCouple.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <AppParCurves_SequenceOfMultiCurve.hxx>
#include <AppParCurves.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <math_IntegerVector.hxx>
#include <AppParCurves_Array1OfMultiBSpCurve.hxx>
#include <AppParCurves_Array1OfMultiCurve.hxx>
#include <AppParCurves_HArray1OfMultiBSpCurve.hxx>
#include <AppParCurves_HArray1OfMultiCurve.hxx>
#include <AppParCurves_SequenceOfMultiBSpCurve.hxx>

PYBIND11_MODULE(AppParCurves, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.math");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_Constraint.hxx
	py::enum_<AppParCurves_Constraint>(mod, "AppParCurves_Constraint", "- NoConstraint: this point has no constraints. - PassPoint: the approximation curve passes through this point. - TangencyPoint: this point has a tangency constraint. - CurvaturePoint: this point has a curvature constraint.")
		.value("AppParCurves_NoConstraint", AppParCurves_Constraint::AppParCurves_NoConstraint)
		.value("AppParCurves_PassPoint", AppParCurves_Constraint::AppParCurves_PassPoint)
		.value("AppParCurves_TangencyPoint", AppParCurves_Constraint::AppParCurves_TangencyPoint)
		.value("AppParCurves_CurvaturePoint", AppParCurves_Constraint::AppParCurves_CurvaturePoint)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_MultiPoint.lxx
	mod.def("operator<<", (Standard_OStream & (*)(Standard_OStream &, const AppParCurves_MultiPoint &)) &operator<<, "None", py::arg("o"), py::arg("M"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_MultiPoint.hxx
	py::class_<AppParCurves_MultiPoint, std::unique_ptr<AppParCurves_MultiPoint, Deleter<AppParCurves_MultiPoint>>> cls_AppParCurves_MultiPoint(mod, "AppParCurves_MultiPoint", "This class describes Points composing a MultiPoint. These points can be 2D or 3D. The user must first give the 3D Points and then the 2D Points. They are Poles of a Bezier Curve. This class is used either to define data input or results when performing the approximation of several lines in parallel.");
	cls_AppParCurves_MultiPoint.def(py::init<>());
	cls_AppParCurves_MultiPoint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("NbPoints"), py::arg("NbPoints2d"));
	cls_AppParCurves_MultiPoint.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("tabP"));
	cls_AppParCurves_MultiPoint.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("tabP2d"));
	cls_AppParCurves_MultiPoint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &>(), py::arg("tabP"), py::arg("tabP2d"));
	cls_AppParCurves_MultiPoint.def("SetPoint", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const gp_Pnt &)) &AppParCurves_MultiPoint::SetPoint, "the 3d Point of range Index of this MultiPoint is set to <Point>. An exception is raised if Index < 0 or Index > number of 3d Points.", py::arg("Index"), py::arg("Point"));
	cls_AppParCurves_MultiPoint.def("Point", (const gp_Pnt & (AppParCurves_MultiPoint::*)(const Standard_Integer) const ) &AppParCurves_MultiPoint::Point, "returns the 3d Point of range Index. An exception is raised if Index < 0 or Index < number of 3d Points.", py::arg("Index"));
	cls_AppParCurves_MultiPoint.def("SetPoint2d", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const gp_Pnt2d &)) &AppParCurves_MultiPoint::SetPoint2d, "The 2d Point of range Index is set to <Point>. An exception is raised if Index > 3d Points or Index > total number of Points.", py::arg("Index"), py::arg("Point"));
	cls_AppParCurves_MultiPoint.def("Point2d", (const gp_Pnt2d & (AppParCurves_MultiPoint::*)(const Standard_Integer) const ) &AppParCurves_MultiPoint::Point2d, "returns the 2d Point of range Index. An exception is raised if index <= number of 3d Points or Index > total number of Points.", py::arg("Index"));
	cls_AppParCurves_MultiPoint.def("Dimension", (Standard_Integer (AppParCurves_MultiPoint::*)(const Standard_Integer) const ) &AppParCurves_MultiPoint::Dimension, "returns the dimension of the point of range Index. An exception is raised if Index <0 or Index > NbCurves.", py::arg("Index"));
	cls_AppParCurves_MultiPoint.def("NbPoints", (Standard_Integer (AppParCurves_MultiPoint::*)() const ) &AppParCurves_MultiPoint::NbPoints, "returns the number of points of dimension 3D.");
	cls_AppParCurves_MultiPoint.def("NbPoints2d", (Standard_Integer (AppParCurves_MultiPoint::*)() const ) &AppParCurves_MultiPoint::NbPoints2d, "returns the number of points of dimension 2D.");
	cls_AppParCurves_MultiPoint.def("Transform", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiPoint::Transform, "Applies a transformation to the curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve. newz = z + dz*oldz", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"), py::arg("z"), py::arg("dz"));
	cls_AppParCurves_MultiPoint.def("Transform2d", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiPoint::Transform2d, "Applies a transformation to the Curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve.", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"));
	// FIXME cls_AppParCurves_MultiPoint.def("Dump", (void (AppParCurves_MultiPoint::*)(Standard_OStream &) const ) &AppParCurves_MultiPoint::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<AppParCurves_Array1OfMultiPoint, std::unique_ptr<AppParCurves_Array1OfMultiPoint, Deleter<AppParCurves_Array1OfMultiPoint>>> cls_AppParCurves_Array1OfMultiPoint(mod, "AppParCurves_Array1OfMultiPoint", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_AppParCurves_Array1OfMultiPoint.def(py::init<>());
	cls_AppParCurves_Array1OfMultiPoint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_Array1OfMultiPoint.def(py::init([] (const AppParCurves_Array1OfMultiPoint &other) {return new AppParCurves_Array1OfMultiPoint(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_AppParCurves_Array1OfMultiPoint.def(py::init<AppParCurves_Array1OfMultiPoint &&>(), py::arg("theOther"));
	cls_AppParCurves_Array1OfMultiPoint.def(py::init<const AppParCurves_MultiPoint &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_Array1OfMultiPoint.def("begin", (AppParCurves_Array1OfMultiPoint::iterator (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::begin, "Returns an iterator pointing to the first element in the array.");
	cls_AppParCurves_Array1OfMultiPoint.def("end", (AppParCurves_Array1OfMultiPoint::iterator (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_AppParCurves_Array1OfMultiPoint.def("cbegin", (AppParCurves_Array1OfMultiPoint::const_iterator (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_AppParCurves_Array1OfMultiPoint.def("cend", (AppParCurves_Array1OfMultiPoint::const_iterator (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_AppParCurves_Array1OfMultiPoint.def("Init", (void (AppParCurves_Array1OfMultiPoint::*)(const AppParCurves_MultiPoint &)) &AppParCurves_Array1OfMultiPoint::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_AppParCurves_Array1OfMultiPoint.def("Size", (Standard_Integer (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::Size, "Size query");
	cls_AppParCurves_Array1OfMultiPoint.def("Length", (Standard_Integer (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::Length, "Length query (the same)");
	cls_AppParCurves_Array1OfMultiPoint.def("IsEmpty", (Standard_Boolean (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::IsEmpty, "Return TRUE if array has zero length.");
	cls_AppParCurves_Array1OfMultiPoint.def("Lower", (Standard_Integer (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::Lower, "Lower bound");
	cls_AppParCurves_Array1OfMultiPoint.def("Upper", (Standard_Integer (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::Upper, "Upper bound");
	cls_AppParCurves_Array1OfMultiPoint.def("IsDeletable", (Standard_Boolean (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::IsDeletable, "myDeletable flag");
	cls_AppParCurves_Array1OfMultiPoint.def("IsAllocated", (Standard_Boolean (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_AppParCurves_Array1OfMultiPoint.def("Assign", (AppParCurves_Array1OfMultiPoint & (AppParCurves_Array1OfMultiPoint::*)(const AppParCurves_Array1OfMultiPoint &)) &AppParCurves_Array1OfMultiPoint::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_AppParCurves_Array1OfMultiPoint.def("Move", (AppParCurves_Array1OfMultiPoint & (AppParCurves_Array1OfMultiPoint::*)(AppParCurves_Array1OfMultiPoint &&)) &AppParCurves_Array1OfMultiPoint::Move, "Move assignment", py::arg("theOther"));
	cls_AppParCurves_Array1OfMultiPoint.def("assign", (AppParCurves_Array1OfMultiPoint & (AppParCurves_Array1OfMultiPoint::*)(const AppParCurves_Array1OfMultiPoint &)) &AppParCurves_Array1OfMultiPoint::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_AppParCurves_Array1OfMultiPoint.def("assign", (AppParCurves_Array1OfMultiPoint & (AppParCurves_Array1OfMultiPoint::*)(AppParCurves_Array1OfMultiPoint &&)) &AppParCurves_Array1OfMultiPoint::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_AppParCurves_Array1OfMultiPoint.def("First", (const AppParCurves_MultiPoint & (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::First, "Returns first element");
	cls_AppParCurves_Array1OfMultiPoint.def("ChangeFirst", (AppParCurves_MultiPoint & (AppParCurves_Array1OfMultiPoint::*)()) &AppParCurves_Array1OfMultiPoint::ChangeFirst, "Returns first element");
	cls_AppParCurves_Array1OfMultiPoint.def("Last", (const AppParCurves_MultiPoint & (AppParCurves_Array1OfMultiPoint::*)() const ) &AppParCurves_Array1OfMultiPoint::Last, "Returns last element");
	cls_AppParCurves_Array1OfMultiPoint.def("ChangeLast", (AppParCurves_MultiPoint & (AppParCurves_Array1OfMultiPoint::*)()) &AppParCurves_Array1OfMultiPoint::ChangeLast, "Returns last element");
	cls_AppParCurves_Array1OfMultiPoint.def("Value", (const AppParCurves_MultiPoint & (AppParCurves_Array1OfMultiPoint::*)(const Standard_Integer) const ) &AppParCurves_Array1OfMultiPoint::Value, "Constant value access", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiPoint.def("__call__", (const AppParCurves_MultiPoint & (AppParCurves_Array1OfMultiPoint::*)(const Standard_Integer) const ) &AppParCurves_Array1OfMultiPoint::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiPoint.def("ChangeValue", (AppParCurves_MultiPoint & (AppParCurves_Array1OfMultiPoint::*)(const Standard_Integer)) &AppParCurves_Array1OfMultiPoint::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiPoint.def("__call__", (AppParCurves_MultiPoint & (AppParCurves_Array1OfMultiPoint::*)(const Standard_Integer)) &AppParCurves_Array1OfMultiPoint::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiPoint.def("SetValue", (void (AppParCurves_Array1OfMultiPoint::*)(const Standard_Integer, const AppParCurves_MultiPoint &)) &AppParCurves_Array1OfMultiPoint::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_Array1OfMultiPoint.def("Resize", (void (AppParCurves_Array1OfMultiPoint::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &AppParCurves_Array1OfMultiPoint::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_AppParCurves_Array1OfMultiPoint.def("__iter__", [](const AppParCurves_Array1OfMultiPoint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_MultiCurve.hxx
	py::class_<AppParCurves_MultiCurve, std::unique_ptr<AppParCurves_MultiCurve, Deleter<AppParCurves_MultiCurve>>> cls_AppParCurves_MultiCurve(mod, "AppParCurves_MultiCurve", "This class describes a MultiCurve approximating a Multiline. As a Multiline is a set of n lines, a MultiCurve is a set of n curves. These curves are Bezier curves. A MultiCurve is composed of m MultiPoint. The approximating degree of these n curves is the same for each one.");
	cls_AppParCurves_MultiCurve.def(py::init<>());
	cls_AppParCurves_MultiCurve.def(py::init<const Standard_Integer>(), py::arg("NbPol"));
	cls_AppParCurves_MultiCurve.def(py::init<const AppParCurves_Array1OfMultiPoint &>(), py::arg("tabMU"));
	cls_AppParCurves_MultiCurve.def("SetNbPoles", (void (AppParCurves_MultiCurve::*)(const Standard_Integer)) &AppParCurves_MultiCurve::SetNbPoles, "The number of poles of the MultiCurve will be set to <nbPoles>.", py::arg("nbPoles"));
	cls_AppParCurves_MultiCurve.def("SetValue", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const AppParCurves_MultiPoint &)) &AppParCurves_MultiCurve::SetValue, "sets the MultiPoint of range Index to the value <MPoint>. An exception is raised if Index <0 or Index >NbMPoint.", py::arg("Index"), py::arg("MPoint"));
	cls_AppParCurves_MultiCurve.def("NbCurves", (Standard_Integer (AppParCurves_MultiCurve::*)() const ) &AppParCurves_MultiCurve::NbCurves, "Returns the number of curves resulting from the approximation of a MultiLine.");
	cls_AppParCurves_MultiCurve.def("NbPoles", (Standard_Integer (AppParCurves_MultiCurve::*)() const ) &AppParCurves_MultiCurve::NbPoles, "Returns the number of poles on curves resulting from the approximation of a MultiLine.");
	cls_AppParCurves_MultiCurve.def("Degree", (Standard_Integer (AppParCurves_MultiCurve::*)() const ) &AppParCurves_MultiCurve::Degree, "returns the degree of the curves.");
	cls_AppParCurves_MultiCurve.def("Dimension", (Standard_Integer (AppParCurves_MultiCurve::*)(const Standard_Integer) const ) &AppParCurves_MultiCurve::Dimension, "returns the dimension of the CuIndex curve. An exception is raised if CuIndex<0 or CuIndex>NbCurves.", py::arg("CuIndex"));
	cls_AppParCurves_MultiCurve.def("Curve", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, TColgp_Array1OfPnt &) const ) &AppParCurves_MultiCurve::Curve, "returns the Pole array of the curve of range CuIndex. An exception is raised if the dimension of the curve is 2d.", py::arg("CuIndex"), py::arg("TabPnt"));
	cls_AppParCurves_MultiCurve.def("Curve", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, TColgp_Array1OfPnt2d &) const ) &AppParCurves_MultiCurve::Curve, "returns the Pole array of the curve of range CuIndex. An exception is raised if the dimension of the curve is 3d.", py::arg("CuIndex"), py::arg("TabPnt"));
	cls_AppParCurves_MultiCurve.def("Value", (const AppParCurves_MultiPoint & (AppParCurves_MultiCurve::*)(const Standard_Integer) const ) &AppParCurves_MultiCurve::Value, "returns the Index MultiPoint. An exception is raised if Index <0 or Index >Degree+1.", py::arg("Index"));
	cls_AppParCurves_MultiCurve.def("Pole", (const gp_Pnt & (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Integer) const ) &AppParCurves_MultiCurve::Pole, "returns the Nieme pole of the CuIndex curve. the curve must be a 3D curve.", py::arg("CuIndex"), py::arg("Nieme"));
	cls_AppParCurves_MultiCurve.def("Pole2d", (const gp_Pnt2d & (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Integer) const ) &AppParCurves_MultiCurve::Pole2d, "returns the Nieme pole of the CuIndex curve. the curve must be a 2D curve.", py::arg("CuIndex"), py::arg("Nieme"));
	cls_AppParCurves_MultiCurve.def("Transform", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiCurve::Transform, "Applies a transformation to the curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve. newz = z + dz*oldz", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"), py::arg("z"), py::arg("dz"));
	cls_AppParCurves_MultiCurve.def("Transform2d", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiCurve::Transform2d, "Applies a transformation to the Curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve.", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"));
	cls_AppParCurves_MultiCurve.def("Value", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &) const ) &AppParCurves_MultiCurve::Value, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
	cls_AppParCurves_MultiCurve.def("Value", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &) const ) &AppParCurves_MultiCurve::Value, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
	cls_AppParCurves_MultiCurve.def("D1", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &) const ) &AppParCurves_MultiCurve::D1, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
	cls_AppParCurves_MultiCurve.def("D1", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &AppParCurves_MultiCurve::D1, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
	cls_AppParCurves_MultiCurve.def("D2", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &AppParCurves_MultiCurve::D2, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
	cls_AppParCurves_MultiCurve.def("D2", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &AppParCurves_MultiCurve::D2, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
	// FIXME cls_AppParCurves_MultiCurve.def("Dump", (void (AppParCurves_MultiCurve::*)(Standard_OStream &) const ) &AppParCurves_MultiCurve::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_MultiBSpCurve.hxx
	py::class_<AppParCurves_MultiBSpCurve, std::unique_ptr<AppParCurves_MultiBSpCurve, Deleter<AppParCurves_MultiBSpCurve>>, AppParCurves_MultiCurve> cls_AppParCurves_MultiBSpCurve(mod, "AppParCurves_MultiBSpCurve", "This class describes a MultiBSpCurve approximating a Multiline. Just as a Multiline is a set of a given number of lines, a MultiBSpCurve is a set of a specified number of bsplines defined by: - A specified number of MultiPoints - the poles of a specified number of curves - The degree of approximation identical for each of the specified number of curves.");
	cls_AppParCurves_MultiBSpCurve.def(py::init<>());
	cls_AppParCurves_MultiBSpCurve.def(py::init<const Standard_Integer>(), py::arg("NbPol"));
	cls_AppParCurves_MultiBSpCurve.def(py::init<const AppParCurves_Array1OfMultiPoint &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &>(), py::arg("tabMU"), py::arg("Knots"), py::arg("Mults"));
	cls_AppParCurves_MultiBSpCurve.def(py::init<const AppParCurves_MultiCurve &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &>(), py::arg("SC"), py::arg("Knots"), py::arg("Mults"));
	cls_AppParCurves_MultiBSpCurve.def("SetKnots", (void (AppParCurves_MultiBSpCurve::*)(const TColStd_Array1OfReal &)) &AppParCurves_MultiBSpCurve::SetKnots, "Knots of the multiBSpCurve are assigned to <theknots>.", py::arg("theKnots"));
	cls_AppParCurves_MultiBSpCurve.def("SetMultiplicities", (void (AppParCurves_MultiBSpCurve::*)(const TColStd_Array1OfInteger &)) &AppParCurves_MultiBSpCurve::SetMultiplicities, "Multiplicities of the multiBSpCurve are assigned to <theMults>.", py::arg("theMults"));
	cls_AppParCurves_MultiBSpCurve.def("Knots", (const TColStd_Array1OfReal & (AppParCurves_MultiBSpCurve::*)() const ) &AppParCurves_MultiBSpCurve::Knots, "Returns an array of Reals containing the multiplicities of curves resulting from the approximation.");
	cls_AppParCurves_MultiBSpCurve.def("Multiplicities", (const TColStd_Array1OfInteger & (AppParCurves_MultiBSpCurve::*)() const ) &AppParCurves_MultiBSpCurve::Multiplicities, "Returns an array of Reals containing the multiplicities of curves resulting from the approximation.");
	cls_AppParCurves_MultiBSpCurve.def("Degree", (Standard_Integer (AppParCurves_MultiBSpCurve::*)() const ) &AppParCurves_MultiBSpCurve::Degree, "returns the degree of the curve(s).");
	cls_AppParCurves_MultiBSpCurve.def("Value", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &) const ) &AppParCurves_MultiBSpCurve::Value, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
	cls_AppParCurves_MultiBSpCurve.def("Value", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &) const ) &AppParCurves_MultiBSpCurve::Value, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
	cls_AppParCurves_MultiBSpCurve.def("D1", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &) const ) &AppParCurves_MultiBSpCurve::D1, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
	cls_AppParCurves_MultiBSpCurve.def("D1", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &AppParCurves_MultiBSpCurve::D1, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
	cls_AppParCurves_MultiBSpCurve.def("D2", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &AppParCurves_MultiBSpCurve::D2, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
	cls_AppParCurves_MultiBSpCurve.def("D2", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &AppParCurves_MultiBSpCurve::D2, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
	// FIXME cls_AppParCurves_MultiBSpCurve.def("Dump", (void (AppParCurves_MultiBSpCurve::*)(Standard_OStream &) const ) &AppParCurves_MultiBSpCurve::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_ConstraintCouple.hxx
	py::class_<AppParCurves_ConstraintCouple, std::unique_ptr<AppParCurves_ConstraintCouple, Deleter<AppParCurves_ConstraintCouple>>> cls_AppParCurves_ConstraintCouple(mod, "AppParCurves_ConstraintCouple", "associates an index and a constraint for an object. This couple is used by AppDef_TheVariational when performing approximations.");
	cls_AppParCurves_ConstraintCouple.def(py::init<>());
	cls_AppParCurves_ConstraintCouple.def(py::init<const Standard_Integer, const AppParCurves_Constraint>(), py::arg("TheIndex"), py::arg("Cons"));
	cls_AppParCurves_ConstraintCouple.def("Index", (Standard_Integer (AppParCurves_ConstraintCouple::*)() const ) &AppParCurves_ConstraintCouple::Index, "returns the index of the constraint object.");
	cls_AppParCurves_ConstraintCouple.def("Constraint", (AppParCurves_Constraint (AppParCurves_ConstraintCouple::*)() const ) &AppParCurves_ConstraintCouple::Constraint, "returns the constraint of the object.");
	cls_AppParCurves_ConstraintCouple.def("SetIndex", (void (AppParCurves_ConstraintCouple::*)(const Standard_Integer)) &AppParCurves_ConstraintCouple::SetIndex, "Changes the index of the constraint object.", py::arg("TheIndex"));
	cls_AppParCurves_ConstraintCouple.def("SetConstraint", (void (AppParCurves_ConstraintCouple::*)(const AppParCurves_Constraint)) &AppParCurves_ConstraintCouple::SetConstraint, "Changes the constraint of the object.", py::arg("Cons"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<AppParCurves_Array1OfConstraintCouple, std::unique_ptr<AppParCurves_Array1OfConstraintCouple, Deleter<AppParCurves_Array1OfConstraintCouple>>> cls_AppParCurves_Array1OfConstraintCouple(mod, "AppParCurves_Array1OfConstraintCouple", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_AppParCurves_Array1OfConstraintCouple.def(py::init<>());
	cls_AppParCurves_Array1OfConstraintCouple.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_Array1OfConstraintCouple.def(py::init([] (const AppParCurves_Array1OfConstraintCouple &other) {return new AppParCurves_Array1OfConstraintCouple(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_AppParCurves_Array1OfConstraintCouple.def(py::init<AppParCurves_Array1OfConstraintCouple &&>(), py::arg("theOther"));
	cls_AppParCurves_Array1OfConstraintCouple.def(py::init<const AppParCurves_ConstraintCouple &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_Array1OfConstraintCouple.def("begin", (AppParCurves_Array1OfConstraintCouple::iterator (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::begin, "Returns an iterator pointing to the first element in the array.");
	cls_AppParCurves_Array1OfConstraintCouple.def("end", (AppParCurves_Array1OfConstraintCouple::iterator (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_AppParCurves_Array1OfConstraintCouple.def("cbegin", (AppParCurves_Array1OfConstraintCouple::const_iterator (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_AppParCurves_Array1OfConstraintCouple.def("cend", (AppParCurves_Array1OfConstraintCouple::const_iterator (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_AppParCurves_Array1OfConstraintCouple.def("Init", (void (AppParCurves_Array1OfConstraintCouple::*)(const AppParCurves_ConstraintCouple &)) &AppParCurves_Array1OfConstraintCouple::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_AppParCurves_Array1OfConstraintCouple.def("Size", (Standard_Integer (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::Size, "Size query");
	cls_AppParCurves_Array1OfConstraintCouple.def("Length", (Standard_Integer (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::Length, "Length query (the same)");
	cls_AppParCurves_Array1OfConstraintCouple.def("IsEmpty", (Standard_Boolean (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::IsEmpty, "Return TRUE if array has zero length.");
	cls_AppParCurves_Array1OfConstraintCouple.def("Lower", (Standard_Integer (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::Lower, "Lower bound");
	cls_AppParCurves_Array1OfConstraintCouple.def("Upper", (Standard_Integer (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::Upper, "Upper bound");
	cls_AppParCurves_Array1OfConstraintCouple.def("IsDeletable", (Standard_Boolean (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::IsDeletable, "myDeletable flag");
	cls_AppParCurves_Array1OfConstraintCouple.def("IsAllocated", (Standard_Boolean (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_AppParCurves_Array1OfConstraintCouple.def("Assign", (AppParCurves_Array1OfConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)(const AppParCurves_Array1OfConstraintCouple &)) &AppParCurves_Array1OfConstraintCouple::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_AppParCurves_Array1OfConstraintCouple.def("Move", (AppParCurves_Array1OfConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)(AppParCurves_Array1OfConstraintCouple &&)) &AppParCurves_Array1OfConstraintCouple::Move, "Move assignment", py::arg("theOther"));
	cls_AppParCurves_Array1OfConstraintCouple.def("assign", (AppParCurves_Array1OfConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)(const AppParCurves_Array1OfConstraintCouple &)) &AppParCurves_Array1OfConstraintCouple::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_AppParCurves_Array1OfConstraintCouple.def("assign", (AppParCurves_Array1OfConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)(AppParCurves_Array1OfConstraintCouple &&)) &AppParCurves_Array1OfConstraintCouple::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_AppParCurves_Array1OfConstraintCouple.def("First", (const AppParCurves_ConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::First, "Returns first element");
	cls_AppParCurves_Array1OfConstraintCouple.def("ChangeFirst", (AppParCurves_ConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)()) &AppParCurves_Array1OfConstraintCouple::ChangeFirst, "Returns first element");
	cls_AppParCurves_Array1OfConstraintCouple.def("Last", (const AppParCurves_ConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)() const ) &AppParCurves_Array1OfConstraintCouple::Last, "Returns last element");
	cls_AppParCurves_Array1OfConstraintCouple.def("ChangeLast", (AppParCurves_ConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)()) &AppParCurves_Array1OfConstraintCouple::ChangeLast, "Returns last element");
	cls_AppParCurves_Array1OfConstraintCouple.def("Value", (const AppParCurves_ConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)(const Standard_Integer) const ) &AppParCurves_Array1OfConstraintCouple::Value, "Constant value access", py::arg("theIndex"));
	cls_AppParCurves_Array1OfConstraintCouple.def("__call__", (const AppParCurves_ConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)(const Standard_Integer) const ) &AppParCurves_Array1OfConstraintCouple::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_AppParCurves_Array1OfConstraintCouple.def("ChangeValue", (AppParCurves_ConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)(const Standard_Integer)) &AppParCurves_Array1OfConstraintCouple::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_AppParCurves_Array1OfConstraintCouple.def("__call__", (AppParCurves_ConstraintCouple & (AppParCurves_Array1OfConstraintCouple::*)(const Standard_Integer)) &AppParCurves_Array1OfConstraintCouple::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_AppParCurves_Array1OfConstraintCouple.def("SetValue", (void (AppParCurves_Array1OfConstraintCouple::*)(const Standard_Integer, const AppParCurves_ConstraintCouple &)) &AppParCurves_Array1OfConstraintCouple::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_Array1OfConstraintCouple.def("Resize", (void (AppParCurves_Array1OfConstraintCouple::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &AppParCurves_Array1OfConstraintCouple::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_AppParCurves_Array1OfConstraintCouple.def("__iter__", [](const AppParCurves_Array1OfConstraintCouple &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_LeastSquare, std::unique_ptr<AppParCurves_LeastSquare, Deleter<AppParCurves_LeastSquare>>> cls_AppParCurves_LeastSquare(mod, "AppParCurves_LeastSquare", "None");
	cls_AppParCurves_LeastSquare.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_ResolConstraint, std::unique_ptr<AppParCurves_ResolConstraint, Deleter<AppParCurves_ResolConstraint>>> cls_AppParCurves_ResolConstraint(mod, "AppParCurves_ResolConstraint", "None");
	cls_AppParCurves_ResolConstraint.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_Function, std::unique_ptr<AppParCurves_Function, Deleter<AppParCurves_Function>>> cls_AppParCurves_Function(mod, "AppParCurves_Function", "None");
	cls_AppParCurves_Function.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_BSpFunction, std::unique_ptr<AppParCurves_BSpFunction, Deleter<AppParCurves_BSpFunction>>> cls_AppParCurves_BSpFunction(mod, "AppParCurves_BSpFunction", "None");
	cls_AppParCurves_BSpFunction.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_Gradient, std::unique_ptr<AppParCurves_Gradient, Deleter<AppParCurves_Gradient>>> cls_AppParCurves_Gradient(mod, "AppParCurves_Gradient", "None");
	cls_AppParCurves_Gradient.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_Gradient_BFGS, std::unique_ptr<AppParCurves_Gradient_BFGS, Deleter<AppParCurves_Gradient_BFGS>>> cls_AppParCurves_Gradient_BFGS(mod, "AppParCurves_Gradient_BFGS", "None");
	cls_AppParCurves_Gradient_BFGS.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_ParLeastSquare, std::unique_ptr<AppParCurves_ParLeastSquare, Deleter<AppParCurves_ParLeastSquare>>> cls_AppParCurves_ParLeastSquare(mod, "AppParCurves_ParLeastSquare", "None");
	cls_AppParCurves_ParLeastSquare.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_ResConstraint, std::unique_ptr<AppParCurves_ResConstraint, Deleter<AppParCurves_ResConstraint>>> cls_AppParCurves_ResConstraint(mod, "AppParCurves_ResConstraint", "None");
	cls_AppParCurves_ResConstraint.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_ParFunction, std::unique_ptr<AppParCurves_ParFunction, Deleter<AppParCurves_ParFunction>>> cls_AppParCurves_ParFunction(mod, "AppParCurves_ParFunction", "None");
	cls_AppParCurves_ParFunction.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_BSpGradient, std::unique_ptr<AppParCurves_BSpGradient, Deleter<AppParCurves_BSpGradient>>> cls_AppParCurves_BSpGradient(mod, "AppParCurves_BSpGradient", "None");
	cls_AppParCurves_BSpGradient.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_BSpGradient_BFGS, std::unique_ptr<AppParCurves_BSpGradient_BFGS, Deleter<AppParCurves_BSpGradient_BFGS>>> cls_AppParCurves_BSpGradient_BFGS(mod, "AppParCurves_BSpGradient_BFGS", "None");
	cls_AppParCurves_BSpGradient_BFGS.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_BSpParLeastSquare, std::unique_ptr<AppParCurves_BSpParLeastSquare, Deleter<AppParCurves_BSpParLeastSquare>>> cls_AppParCurves_BSpParLeastSquare(mod, "AppParCurves_BSpParLeastSquare", "None");
	cls_AppParCurves_BSpParLeastSquare.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves_BSpParFunction, std::unique_ptr<AppParCurves_BSpParFunction, Deleter<AppParCurves_BSpParFunction>>> cls_AppParCurves_BSpParFunction(mod, "AppParCurves_BSpParFunction", "None");
	cls_AppParCurves_BSpParFunction.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves.hxx
	py::class_<AppParCurves, std::unique_ptr<AppParCurves, Deleter<AppParCurves>>> cls_AppParCurves(mod, "AppParCurves", "Parallel Approximation in n curves. This package gives all the algorithms used to approximate a MultiLine described by the tool MLineTool. The result of the approximation will be a MultiCurve.");
	cls_AppParCurves.def(py::init<>());
	cls_AppParCurves.def_static("BernsteinMatrix_", (void (*)(const Standard_Integer, const math_Vector &, math_Matrix &)) &AppParCurves::BernsteinMatrix, "None", py::arg("NbPoles"), py::arg("U"), py::arg("A"));
	cls_AppParCurves.def_static("Bernstein_", (void (*)(const Standard_Integer, const math_Vector &, math_Matrix &, math_Matrix &)) &AppParCurves::Bernstein, "None", py::arg("NbPoles"), py::arg("U"), py::arg("A"), py::arg("DA"));
	cls_AppParCurves.def_static("SecondDerivativeBernstein_", (void (*)(const Standard_Real, math_Vector &)) &AppParCurves::SecondDerivativeBernstein, "None", py::arg("U"), py::arg("DDA"));
	cls_AppParCurves.def_static("SplineFunction_", (void (*)(const Standard_Integer, const Standard_Integer, const math_Vector &, const math_Vector &, math_Matrix &, math_Matrix &, math_IntegerVector &)) &AppParCurves::SplineFunction, "None", py::arg("NbPoles"), py::arg("Degree"), py::arg("Parameters"), py::arg("FlatKnots"), py::arg("A"), py::arg("DA"), py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<AppParCurves_Array1OfMultiBSpCurve, std::unique_ptr<AppParCurves_Array1OfMultiBSpCurve, Deleter<AppParCurves_Array1OfMultiBSpCurve>>> cls_AppParCurves_Array1OfMultiBSpCurve(mod, "AppParCurves_Array1OfMultiBSpCurve", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_AppParCurves_Array1OfMultiBSpCurve.def(py::init<>());
	cls_AppParCurves_Array1OfMultiBSpCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def(py::init([] (const AppParCurves_Array1OfMultiBSpCurve &other) {return new AppParCurves_Array1OfMultiBSpCurve(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_AppParCurves_Array1OfMultiBSpCurve.def(py::init<AppParCurves_Array1OfMultiBSpCurve &&>(), py::arg("theOther"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def(py::init<const AppParCurves_MultiBSpCurve &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("begin", (AppParCurves_Array1OfMultiBSpCurve::iterator (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::begin, "Returns an iterator pointing to the first element in the array.");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("end", (AppParCurves_Array1OfMultiBSpCurve::iterator (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("cbegin", (AppParCurves_Array1OfMultiBSpCurve::const_iterator (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("cend", (AppParCurves_Array1OfMultiBSpCurve::const_iterator (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("Init", (void (AppParCurves_Array1OfMultiBSpCurve::*)(const AppParCurves_MultiBSpCurve &)) &AppParCurves_Array1OfMultiBSpCurve::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("Size", (Standard_Integer (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::Size, "Size query");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("Length", (Standard_Integer (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::Length, "Length query (the same)");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("IsEmpty", (Standard_Boolean (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::IsEmpty, "Return TRUE if array has zero length.");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("Lower", (Standard_Integer (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::Lower, "Lower bound");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("Upper", (Standard_Integer (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::Upper, "Upper bound");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("IsDeletable", (Standard_Boolean (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::IsDeletable, "myDeletable flag");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("IsAllocated", (Standard_Boolean (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("Assign", (AppParCurves_Array1OfMultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)(const AppParCurves_Array1OfMultiBSpCurve &)) &AppParCurves_Array1OfMultiBSpCurve::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_AppParCurves_Array1OfMultiBSpCurve.def("Move", (AppParCurves_Array1OfMultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)(AppParCurves_Array1OfMultiBSpCurve &&)) &AppParCurves_Array1OfMultiBSpCurve::Move, "Move assignment", py::arg("theOther"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("assign", (AppParCurves_Array1OfMultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)(const AppParCurves_Array1OfMultiBSpCurve &)) &AppParCurves_Array1OfMultiBSpCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_AppParCurves_Array1OfMultiBSpCurve.def("assign", (AppParCurves_Array1OfMultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)(AppParCurves_Array1OfMultiBSpCurve &&)) &AppParCurves_Array1OfMultiBSpCurve::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("First", (const AppParCurves_MultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::First, "Returns first element");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("ChangeFirst", (AppParCurves_MultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)()) &AppParCurves_Array1OfMultiBSpCurve::ChangeFirst, "Returns first element");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("Last", (const AppParCurves_MultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)() const ) &AppParCurves_Array1OfMultiBSpCurve::Last, "Returns last element");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("ChangeLast", (AppParCurves_MultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)()) &AppParCurves_Array1OfMultiBSpCurve::ChangeLast, "Returns last element");
	cls_AppParCurves_Array1OfMultiBSpCurve.def("Value", (const AppParCurves_MultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)(const Standard_Integer) const ) &AppParCurves_Array1OfMultiBSpCurve::Value, "Constant value access", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("__call__", (const AppParCurves_MultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)(const Standard_Integer) const ) &AppParCurves_Array1OfMultiBSpCurve::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("ChangeValue", (AppParCurves_MultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)(const Standard_Integer)) &AppParCurves_Array1OfMultiBSpCurve::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("__call__", (AppParCurves_MultiBSpCurve & (AppParCurves_Array1OfMultiBSpCurve::*)(const Standard_Integer)) &AppParCurves_Array1OfMultiBSpCurve::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("SetValue", (void (AppParCurves_Array1OfMultiBSpCurve::*)(const Standard_Integer, const AppParCurves_MultiBSpCurve &)) &AppParCurves_Array1OfMultiBSpCurve::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("Resize", (void (AppParCurves_Array1OfMultiBSpCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &AppParCurves_Array1OfMultiBSpCurve::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_AppParCurves_Array1OfMultiBSpCurve.def("__iter__", [](const AppParCurves_Array1OfMultiBSpCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<AppParCurves_Array1OfMultiCurve, std::unique_ptr<AppParCurves_Array1OfMultiCurve, Deleter<AppParCurves_Array1OfMultiCurve>>> cls_AppParCurves_Array1OfMultiCurve(mod, "AppParCurves_Array1OfMultiCurve", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_AppParCurves_Array1OfMultiCurve.def(py::init<>());
	cls_AppParCurves_Array1OfMultiCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_Array1OfMultiCurve.def(py::init([] (const AppParCurves_Array1OfMultiCurve &other) {return new AppParCurves_Array1OfMultiCurve(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_AppParCurves_Array1OfMultiCurve.def(py::init<AppParCurves_Array1OfMultiCurve &&>(), py::arg("theOther"));
	cls_AppParCurves_Array1OfMultiCurve.def(py::init<const AppParCurves_MultiCurve &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_Array1OfMultiCurve.def("begin", (AppParCurves_Array1OfMultiCurve::iterator (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::begin, "Returns an iterator pointing to the first element in the array.");
	cls_AppParCurves_Array1OfMultiCurve.def("end", (AppParCurves_Array1OfMultiCurve::iterator (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_AppParCurves_Array1OfMultiCurve.def("cbegin", (AppParCurves_Array1OfMultiCurve::const_iterator (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_AppParCurves_Array1OfMultiCurve.def("cend", (AppParCurves_Array1OfMultiCurve::const_iterator (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_AppParCurves_Array1OfMultiCurve.def("Init", (void (AppParCurves_Array1OfMultiCurve::*)(const AppParCurves_MultiCurve &)) &AppParCurves_Array1OfMultiCurve::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_AppParCurves_Array1OfMultiCurve.def("Size", (Standard_Integer (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::Size, "Size query");
	cls_AppParCurves_Array1OfMultiCurve.def("Length", (Standard_Integer (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::Length, "Length query (the same)");
	cls_AppParCurves_Array1OfMultiCurve.def("IsEmpty", (Standard_Boolean (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::IsEmpty, "Return TRUE if array has zero length.");
	cls_AppParCurves_Array1OfMultiCurve.def("Lower", (Standard_Integer (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::Lower, "Lower bound");
	cls_AppParCurves_Array1OfMultiCurve.def("Upper", (Standard_Integer (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::Upper, "Upper bound");
	cls_AppParCurves_Array1OfMultiCurve.def("IsDeletable", (Standard_Boolean (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::IsDeletable, "myDeletable flag");
	cls_AppParCurves_Array1OfMultiCurve.def("IsAllocated", (Standard_Boolean (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_AppParCurves_Array1OfMultiCurve.def("Assign", (AppParCurves_Array1OfMultiCurve & (AppParCurves_Array1OfMultiCurve::*)(const AppParCurves_Array1OfMultiCurve &)) &AppParCurves_Array1OfMultiCurve::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_AppParCurves_Array1OfMultiCurve.def("Move", (AppParCurves_Array1OfMultiCurve & (AppParCurves_Array1OfMultiCurve::*)(AppParCurves_Array1OfMultiCurve &&)) &AppParCurves_Array1OfMultiCurve::Move, "Move assignment", py::arg("theOther"));
	cls_AppParCurves_Array1OfMultiCurve.def("assign", (AppParCurves_Array1OfMultiCurve & (AppParCurves_Array1OfMultiCurve::*)(const AppParCurves_Array1OfMultiCurve &)) &AppParCurves_Array1OfMultiCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_AppParCurves_Array1OfMultiCurve.def("assign", (AppParCurves_Array1OfMultiCurve & (AppParCurves_Array1OfMultiCurve::*)(AppParCurves_Array1OfMultiCurve &&)) &AppParCurves_Array1OfMultiCurve::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_AppParCurves_Array1OfMultiCurve.def("First", (const AppParCurves_MultiCurve & (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::First, "Returns first element");
	cls_AppParCurves_Array1OfMultiCurve.def("ChangeFirst", (AppParCurves_MultiCurve & (AppParCurves_Array1OfMultiCurve::*)()) &AppParCurves_Array1OfMultiCurve::ChangeFirst, "Returns first element");
	cls_AppParCurves_Array1OfMultiCurve.def("Last", (const AppParCurves_MultiCurve & (AppParCurves_Array1OfMultiCurve::*)() const ) &AppParCurves_Array1OfMultiCurve::Last, "Returns last element");
	cls_AppParCurves_Array1OfMultiCurve.def("ChangeLast", (AppParCurves_MultiCurve & (AppParCurves_Array1OfMultiCurve::*)()) &AppParCurves_Array1OfMultiCurve::ChangeLast, "Returns last element");
	cls_AppParCurves_Array1OfMultiCurve.def("Value", (const AppParCurves_MultiCurve & (AppParCurves_Array1OfMultiCurve::*)(const Standard_Integer) const ) &AppParCurves_Array1OfMultiCurve::Value, "Constant value access", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiCurve.def("__call__", (const AppParCurves_MultiCurve & (AppParCurves_Array1OfMultiCurve::*)(const Standard_Integer) const ) &AppParCurves_Array1OfMultiCurve::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiCurve.def("ChangeValue", (AppParCurves_MultiCurve & (AppParCurves_Array1OfMultiCurve::*)(const Standard_Integer)) &AppParCurves_Array1OfMultiCurve::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiCurve.def("__call__", (AppParCurves_MultiCurve & (AppParCurves_Array1OfMultiCurve::*)(const Standard_Integer)) &AppParCurves_Array1OfMultiCurve::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_AppParCurves_Array1OfMultiCurve.def("SetValue", (void (AppParCurves_Array1OfMultiCurve::*)(const Standard_Integer, const AppParCurves_MultiCurve &)) &AppParCurves_Array1OfMultiCurve::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_Array1OfMultiCurve.def("Resize", (void (AppParCurves_Array1OfMultiCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &AppParCurves_Array1OfMultiCurve::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_AppParCurves_Array1OfMultiCurve.def("__iter__", [](const AppParCurves_Array1OfMultiCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_HArray1OfMultiPoint.hxx
	py::class_<AppParCurves_HArray1OfMultiPoint, opencascade::handle<AppParCurves_HArray1OfMultiPoint>, AppParCurves_Array1OfMultiPoint, Standard_Transient> cls_AppParCurves_HArray1OfMultiPoint(mod, "AppParCurves_HArray1OfMultiPoint", "None");
	cls_AppParCurves_HArray1OfMultiPoint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_HArray1OfMultiPoint.def(py::init<const Standard_Integer, const Standard_Integer, const AppParCurves_Array1OfMultiPoint::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_AppParCurves_HArray1OfMultiPoint.def(py::init<const AppParCurves_Array1OfMultiPoint &>(), py::arg("theOther"));
	cls_AppParCurves_HArray1OfMultiPoint.def("Array1", (const AppParCurves_Array1OfMultiPoint & (AppParCurves_HArray1OfMultiPoint::*)() const ) &AppParCurves_HArray1OfMultiPoint::Array1, "None");
	cls_AppParCurves_HArray1OfMultiPoint.def("ChangeArray1", (AppParCurves_Array1OfMultiPoint & (AppParCurves_HArray1OfMultiPoint::*)()) &AppParCurves_HArray1OfMultiPoint::ChangeArray1, "None");
	cls_AppParCurves_HArray1OfMultiPoint.def_static("get_type_name_", (const char * (*)()) &AppParCurves_HArray1OfMultiPoint::get_type_name, "None");
	cls_AppParCurves_HArray1OfMultiPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppParCurves_HArray1OfMultiPoint::get_type_descriptor, "None");
	cls_AppParCurves_HArray1OfMultiPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppParCurves_HArray1OfMultiPoint::*)() const ) &AppParCurves_HArray1OfMultiPoint::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_HArray1OfConstraintCouple.hxx
	py::class_<AppParCurves_HArray1OfConstraintCouple, opencascade::handle<AppParCurves_HArray1OfConstraintCouple>, AppParCurves_Array1OfConstraintCouple, Standard_Transient> cls_AppParCurves_HArray1OfConstraintCouple(mod, "AppParCurves_HArray1OfConstraintCouple", "None");
	cls_AppParCurves_HArray1OfConstraintCouple.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_HArray1OfConstraintCouple.def(py::init<const Standard_Integer, const Standard_Integer, const AppParCurves_Array1OfConstraintCouple::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_AppParCurves_HArray1OfConstraintCouple.def(py::init<const AppParCurves_Array1OfConstraintCouple &>(), py::arg("theOther"));
	cls_AppParCurves_HArray1OfConstraintCouple.def("Array1", (const AppParCurves_Array1OfConstraintCouple & (AppParCurves_HArray1OfConstraintCouple::*)() const ) &AppParCurves_HArray1OfConstraintCouple::Array1, "None");
	cls_AppParCurves_HArray1OfConstraintCouple.def("ChangeArray1", (AppParCurves_Array1OfConstraintCouple & (AppParCurves_HArray1OfConstraintCouple::*)()) &AppParCurves_HArray1OfConstraintCouple::ChangeArray1, "None");
	cls_AppParCurves_HArray1OfConstraintCouple.def_static("get_type_name_", (const char * (*)()) &AppParCurves_HArray1OfConstraintCouple::get_type_name, "None");
	cls_AppParCurves_HArray1OfConstraintCouple.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppParCurves_HArray1OfConstraintCouple::get_type_descriptor, "None");
	cls_AppParCurves_HArray1OfConstraintCouple.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppParCurves_HArray1OfConstraintCouple::*)() const ) &AppParCurves_HArray1OfConstraintCouple::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<AppParCurves_SequenceOfMultiCurve, std::unique_ptr<AppParCurves_SequenceOfMultiCurve, Deleter<AppParCurves_SequenceOfMultiCurve>>, NCollection_BaseSequence> cls_AppParCurves_SequenceOfMultiCurve(mod, "AppParCurves_SequenceOfMultiCurve", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_AppParCurves_SequenceOfMultiCurve.def(py::init<>());
	cls_AppParCurves_SequenceOfMultiCurve.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_AppParCurves_SequenceOfMultiCurve.def(py::init([] (const AppParCurves_SequenceOfMultiCurve &other) {return new AppParCurves_SequenceOfMultiCurve(other);}), "Copy constructor", py::arg("other"));
	cls_AppParCurves_SequenceOfMultiCurve.def("begin", (AppParCurves_SequenceOfMultiCurve::iterator (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_AppParCurves_SequenceOfMultiCurve.def("end", (AppParCurves_SequenceOfMultiCurve::iterator (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_AppParCurves_SequenceOfMultiCurve.def("cbegin", (AppParCurves_SequenceOfMultiCurve::const_iterator (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_AppParCurves_SequenceOfMultiCurve.def("cend", (AppParCurves_SequenceOfMultiCurve::const_iterator (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_AppParCurves_SequenceOfMultiCurve.def("Size", (Standard_Integer (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::Size, "Number of items");
	cls_AppParCurves_SequenceOfMultiCurve.def("Length", (Standard_Integer (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::Length, "Number of items");
	cls_AppParCurves_SequenceOfMultiCurve.def("Lower", (Standard_Integer (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::Lower, "Method for consistency with other collections.");
	cls_AppParCurves_SequenceOfMultiCurve.def("Upper", (Standard_Integer (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::Upper, "Method for consistency with other collections.");
	cls_AppParCurves_SequenceOfMultiCurve.def("IsEmpty", (Standard_Boolean (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::IsEmpty, "Empty query");
	cls_AppParCurves_SequenceOfMultiCurve.def("Reverse", (void (AppParCurves_SequenceOfMultiCurve::*)()) &AppParCurves_SequenceOfMultiCurve::Reverse, "Reverse sequence");
	cls_AppParCurves_SequenceOfMultiCurve.def("Exchange", (void (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer, const Standard_Integer)) &AppParCurves_SequenceOfMultiCurve::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_AppParCurves_SequenceOfMultiCurve.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_SequenceOfMultiCurve::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Clear", [](AppParCurves_SequenceOfMultiCurve &self) -> void { return self.Clear(); });
	cls_AppParCurves_SequenceOfMultiCurve.def("Clear", (void (AppParCurves_SequenceOfMultiCurve::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_SequenceOfMultiCurve::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Assign", (AppParCurves_SequenceOfMultiCurve & (AppParCurves_SequenceOfMultiCurve::*)(const AppParCurves_SequenceOfMultiCurve &)) &AppParCurves_SequenceOfMultiCurve::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_AppParCurves_SequenceOfMultiCurve.def("assign", (AppParCurves_SequenceOfMultiCurve & (AppParCurves_SequenceOfMultiCurve::*)(const AppParCurves_SequenceOfMultiCurve &)) &AppParCurves_SequenceOfMultiCurve::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Remove", (void (AppParCurves_SequenceOfMultiCurve::*)(AppParCurves_SequenceOfMultiCurve::Iterator &)) &AppParCurves_SequenceOfMultiCurve::Remove, "Remove one item", py::arg("thePosition"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Remove", (void (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer)) &AppParCurves_SequenceOfMultiCurve::Remove, "Remove one item", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Remove", (void (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer, const Standard_Integer)) &AppParCurves_SequenceOfMultiCurve::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Append", (void (AppParCurves_SequenceOfMultiCurve::*)(const AppParCurves_MultiCurve &)) &AppParCurves_SequenceOfMultiCurve::Append, "Append one item", py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Append", (void (AppParCurves_SequenceOfMultiCurve::*)(AppParCurves_SequenceOfMultiCurve &)) &AppParCurves_SequenceOfMultiCurve::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Prepend", (void (AppParCurves_SequenceOfMultiCurve::*)(const AppParCurves_MultiCurve &)) &AppParCurves_SequenceOfMultiCurve::Prepend, "Prepend one item", py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Prepend", (void (AppParCurves_SequenceOfMultiCurve::*)(AppParCurves_SequenceOfMultiCurve &)) &AppParCurves_SequenceOfMultiCurve::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiCurve.def("InsertBefore", (void (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer, const AppParCurves_MultiCurve &)) &AppParCurves_SequenceOfMultiCurve::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiCurve.def("InsertBefore", (void (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer, AppParCurves_SequenceOfMultiCurve &)) &AppParCurves_SequenceOfMultiCurve::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiCurve.def("InsertAfter", (void (AppParCurves_SequenceOfMultiCurve::*)(AppParCurves_SequenceOfMultiCurve::Iterator &, const AppParCurves_MultiCurve &)) &AppParCurves_SequenceOfMultiCurve::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiCurve.def("InsertAfter", (void (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer, AppParCurves_SequenceOfMultiCurve &)) &AppParCurves_SequenceOfMultiCurve::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiCurve.def("InsertAfter", (void (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer, const AppParCurves_MultiCurve &)) &AppParCurves_SequenceOfMultiCurve::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiCurve.def("Split", (void (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer, AppParCurves_SequenceOfMultiCurve &)) &AppParCurves_SequenceOfMultiCurve::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiCurve.def("First", (const AppParCurves_MultiCurve & (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::First, "First item access");
	cls_AppParCurves_SequenceOfMultiCurve.def("ChangeFirst", (AppParCurves_MultiCurve & (AppParCurves_SequenceOfMultiCurve::*)()) &AppParCurves_SequenceOfMultiCurve::ChangeFirst, "First item access");
	cls_AppParCurves_SequenceOfMultiCurve.def("Last", (const AppParCurves_MultiCurve & (AppParCurves_SequenceOfMultiCurve::*)() const ) &AppParCurves_SequenceOfMultiCurve::Last, "Last item access");
	cls_AppParCurves_SequenceOfMultiCurve.def("ChangeLast", (AppParCurves_MultiCurve & (AppParCurves_SequenceOfMultiCurve::*)()) &AppParCurves_SequenceOfMultiCurve::ChangeLast, "Last item access");
	cls_AppParCurves_SequenceOfMultiCurve.def("Value", (const AppParCurves_MultiCurve & (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer) const ) &AppParCurves_SequenceOfMultiCurve::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiCurve.def("__call__", (const AppParCurves_MultiCurve & (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer) const ) &AppParCurves_SequenceOfMultiCurve::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiCurve.def("ChangeValue", (AppParCurves_MultiCurve & (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer)) &AppParCurves_SequenceOfMultiCurve::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiCurve.def("__call__", (AppParCurves_MultiCurve & (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer)) &AppParCurves_SequenceOfMultiCurve::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiCurve.def("SetValue", (void (AppParCurves_SequenceOfMultiCurve::*)(const Standard_Integer, const AppParCurves_MultiCurve &)) &AppParCurves_SequenceOfMultiCurve::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiCurve.def("__iter__", [](const AppParCurves_SequenceOfMultiCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_HArray1OfMultiBSpCurve.hxx
	py::class_<AppParCurves_HArray1OfMultiBSpCurve, opencascade::handle<AppParCurves_HArray1OfMultiBSpCurve>, AppParCurves_Array1OfMultiBSpCurve, Standard_Transient> cls_AppParCurves_HArray1OfMultiBSpCurve(mod, "AppParCurves_HArray1OfMultiBSpCurve", "None");
	cls_AppParCurves_HArray1OfMultiBSpCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_HArray1OfMultiBSpCurve.def(py::init<const Standard_Integer, const Standard_Integer, const AppParCurves_Array1OfMultiBSpCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_AppParCurves_HArray1OfMultiBSpCurve.def(py::init<const AppParCurves_Array1OfMultiBSpCurve &>(), py::arg("theOther"));
	cls_AppParCurves_HArray1OfMultiBSpCurve.def("Array1", (const AppParCurves_Array1OfMultiBSpCurve & (AppParCurves_HArray1OfMultiBSpCurve::*)() const ) &AppParCurves_HArray1OfMultiBSpCurve::Array1, "None");
	cls_AppParCurves_HArray1OfMultiBSpCurve.def("ChangeArray1", (AppParCurves_Array1OfMultiBSpCurve & (AppParCurves_HArray1OfMultiBSpCurve::*)()) &AppParCurves_HArray1OfMultiBSpCurve::ChangeArray1, "None");
	cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("get_type_name_", (const char * (*)()) &AppParCurves_HArray1OfMultiBSpCurve::get_type_name, "None");
	cls_AppParCurves_HArray1OfMultiBSpCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppParCurves_HArray1OfMultiBSpCurve::get_type_descriptor, "None");
	cls_AppParCurves_HArray1OfMultiBSpCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppParCurves_HArray1OfMultiBSpCurve::*)() const ) &AppParCurves_HArray1OfMultiBSpCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\AppParCurves_HArray1OfMultiCurve.hxx
	py::class_<AppParCurves_HArray1OfMultiCurve, opencascade::handle<AppParCurves_HArray1OfMultiCurve>, AppParCurves_Array1OfMultiCurve, Standard_Transient> cls_AppParCurves_HArray1OfMultiCurve(mod, "AppParCurves_HArray1OfMultiCurve", "None");
	cls_AppParCurves_HArray1OfMultiCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_AppParCurves_HArray1OfMultiCurve.def(py::init<const Standard_Integer, const Standard_Integer, const AppParCurves_Array1OfMultiCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_AppParCurves_HArray1OfMultiCurve.def(py::init<const AppParCurves_Array1OfMultiCurve &>(), py::arg("theOther"));
	cls_AppParCurves_HArray1OfMultiCurve.def("Array1", (const AppParCurves_Array1OfMultiCurve & (AppParCurves_HArray1OfMultiCurve::*)() const ) &AppParCurves_HArray1OfMultiCurve::Array1, "None");
	cls_AppParCurves_HArray1OfMultiCurve.def("ChangeArray1", (AppParCurves_Array1OfMultiCurve & (AppParCurves_HArray1OfMultiCurve::*)()) &AppParCurves_HArray1OfMultiCurve::ChangeArray1, "None");
	cls_AppParCurves_HArray1OfMultiCurve.def_static("get_type_name_", (const char * (*)()) &AppParCurves_HArray1OfMultiCurve::get_type_name, "None");
	cls_AppParCurves_HArray1OfMultiCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppParCurves_HArray1OfMultiCurve::get_type_descriptor, "None");
	cls_AppParCurves_HArray1OfMultiCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppParCurves_HArray1OfMultiCurve::*)() const ) &AppParCurves_HArray1OfMultiCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<AppParCurves_SequenceOfMultiBSpCurve, std::unique_ptr<AppParCurves_SequenceOfMultiBSpCurve, Deleter<AppParCurves_SequenceOfMultiBSpCurve>>, NCollection_BaseSequence> cls_AppParCurves_SequenceOfMultiBSpCurve(mod, "AppParCurves_SequenceOfMultiBSpCurve", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def(py::init<>());
	cls_AppParCurves_SequenceOfMultiBSpCurve.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def(py::init([] (const AppParCurves_SequenceOfMultiBSpCurve &other) {return new AppParCurves_SequenceOfMultiBSpCurve(other);}), "Copy constructor", py::arg("other"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("begin", (AppParCurves_SequenceOfMultiBSpCurve::iterator (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("end", (AppParCurves_SequenceOfMultiBSpCurve::iterator (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("cbegin", (AppParCurves_SequenceOfMultiBSpCurve::const_iterator (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("cend", (AppParCurves_SequenceOfMultiBSpCurve::const_iterator (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Size", (Standard_Integer (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::Size, "Number of items");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Length", (Standard_Integer (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::Length, "Number of items");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Lower", (Standard_Integer (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::Lower, "Method for consistency with other collections.");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Upper", (Standard_Integer (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::Upper, "Method for consistency with other collections.");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("IsEmpty", (Standard_Boolean (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::IsEmpty, "Empty query");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Reverse", (void (AppParCurves_SequenceOfMultiBSpCurve::*)()) &AppParCurves_SequenceOfMultiBSpCurve::Reverse, "Reverse sequence");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Exchange", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer, const Standard_Integer)) &AppParCurves_SequenceOfMultiBSpCurve::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_SequenceOfMultiBSpCurve::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Clear", [](AppParCurves_SequenceOfMultiBSpCurve &self) -> void { return self.Clear(); });
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Clear", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_SequenceOfMultiBSpCurve::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Assign", (AppParCurves_SequenceOfMultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)(const AppParCurves_SequenceOfMultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("assign", (AppParCurves_SequenceOfMultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)(const AppParCurves_SequenceOfMultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Remove", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(AppParCurves_SequenceOfMultiBSpCurve::Iterator &)) &AppParCurves_SequenceOfMultiBSpCurve::Remove, "Remove one item", py::arg("thePosition"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Remove", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer)) &AppParCurves_SequenceOfMultiBSpCurve::Remove, "Remove one item", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Remove", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer, const Standard_Integer)) &AppParCurves_SequenceOfMultiBSpCurve::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Append", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const AppParCurves_MultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::Append, "Append one item", py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Append", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(AppParCurves_SequenceOfMultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Prepend", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const AppParCurves_MultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::Prepend, "Prepend one item", py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Prepend", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(AppParCurves_SequenceOfMultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("InsertBefore", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer, const AppParCurves_MultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("InsertBefore", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer, AppParCurves_SequenceOfMultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("InsertAfter", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(AppParCurves_SequenceOfMultiBSpCurve::Iterator &, const AppParCurves_MultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("InsertAfter", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer, AppParCurves_SequenceOfMultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("InsertAfter", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer, const AppParCurves_MultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Split", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer, AppParCurves_SequenceOfMultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("First", (const AppParCurves_MultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::First, "First item access");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("ChangeFirst", (AppParCurves_MultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)()) &AppParCurves_SequenceOfMultiBSpCurve::ChangeFirst, "First item access");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Last", (const AppParCurves_MultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)() const ) &AppParCurves_SequenceOfMultiBSpCurve::Last, "Last item access");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("ChangeLast", (AppParCurves_MultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)()) &AppParCurves_SequenceOfMultiBSpCurve::ChangeLast, "Last item access");
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("Value", (const AppParCurves_MultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer) const ) &AppParCurves_SequenceOfMultiBSpCurve::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("__call__", (const AppParCurves_MultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer) const ) &AppParCurves_SequenceOfMultiBSpCurve::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("ChangeValue", (AppParCurves_MultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer)) &AppParCurves_SequenceOfMultiBSpCurve::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("__call__", (AppParCurves_MultiBSpCurve & (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer)) &AppParCurves_SequenceOfMultiBSpCurve::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("SetValue", (void (AppParCurves_SequenceOfMultiBSpCurve::*)(const Standard_Integer, const AppParCurves_MultiBSpCurve &)) &AppParCurves_SequenceOfMultiBSpCurve::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_AppParCurves_SequenceOfMultiBSpCurve.def("__iter__", [](const AppParCurves_SequenceOfMultiBSpCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
