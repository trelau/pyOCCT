#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TColGeom2d_Array1OfCurve.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <TColGeom2d_Array1OfBSplineCurve.hxx>
#include <TColGeom2d_HArray1OfBSplineCurve.hxx>
#include <TColGeom2d_Array1OfBezierCurve.hxx>
#include <TColGeom2d_SequenceOfGeometry.hxx>
#include <TColGeom2d_SequenceOfBoundedCurve.hxx>
#include <TColGeom2d_HSequenceOfBoundedCurve.hxx>
#include <TColGeom2d_HSequenceOfCurve.hxx>
#include <TColGeom2d_HArray1OfBezierCurve.hxx>

PYBIND11_MODULE(TColGeom2d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColGeom2d_Array1OfCurve, std::unique_ptr<TColGeom2d_Array1OfCurve, Deleter<TColGeom2d_Array1OfCurve>>> cls_TColGeom2d_Array1OfCurve(mod, "TColGeom2d_Array1OfCurve", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColGeom2d_Array1OfCurve.def(py::init<>());
	cls_TColGeom2d_Array1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_Array1OfCurve.def(py::init([] (const TColGeom2d_Array1OfCurve &other) {return new TColGeom2d_Array1OfCurve(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColGeom2d_Array1OfCurve.def(py::init<TColGeom2d_Array1OfCurve &&>(), py::arg("theOther"));
	cls_TColGeom2d_Array1OfCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_Array1OfCurve.def("begin", (TColGeom2d_Array1OfCurve::iterator (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColGeom2d_Array1OfCurve.def("end", (TColGeom2d_Array1OfCurve::iterator (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColGeom2d_Array1OfCurve.def("cbegin", (TColGeom2d_Array1OfCurve::const_iterator (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColGeom2d_Array1OfCurve.def("cend", (TColGeom2d_Array1OfCurve::const_iterator (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColGeom2d_Array1OfCurve.def("Init", (void (TColGeom2d_Array1OfCurve::*)(const opencascade::handle<Geom2d_Curve> &)) &TColGeom2d_Array1OfCurve::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColGeom2d_Array1OfCurve.def("Size", (Standard_Integer (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::Size, "Size query");
	cls_TColGeom2d_Array1OfCurve.def("Length", (Standard_Integer (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::Length, "Length query (the same)");
	cls_TColGeom2d_Array1OfCurve.def("IsEmpty", (Standard_Boolean (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColGeom2d_Array1OfCurve.def("Lower", (Standard_Integer (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::Lower, "Lower bound");
	cls_TColGeom2d_Array1OfCurve.def("Upper", (Standard_Integer (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::Upper, "Upper bound");
	cls_TColGeom2d_Array1OfCurve.def("IsDeletable", (Standard_Boolean (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::IsDeletable, "myDeletable flag");
	cls_TColGeom2d_Array1OfCurve.def("IsAllocated", (Standard_Boolean (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColGeom2d_Array1OfCurve.def("Assign", (TColGeom2d_Array1OfCurve & (TColGeom2d_Array1OfCurve::*)(const TColGeom2d_Array1OfCurve &)) &TColGeom2d_Array1OfCurve::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColGeom2d_Array1OfCurve.def("Move", (TColGeom2d_Array1OfCurve & (TColGeom2d_Array1OfCurve::*)(TColGeom2d_Array1OfCurve &&)) &TColGeom2d_Array1OfCurve::Move, "Move assignment", py::arg("theOther"));
	cls_TColGeom2d_Array1OfCurve.def("assign", (TColGeom2d_Array1OfCurve & (TColGeom2d_Array1OfCurve::*)(const TColGeom2d_Array1OfCurve &)) &TColGeom2d_Array1OfCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColGeom2d_Array1OfCurve.def("assign", (TColGeom2d_Array1OfCurve & (TColGeom2d_Array1OfCurve::*)(TColGeom2d_Array1OfCurve &&)) &TColGeom2d_Array1OfCurve::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColGeom2d_Array1OfCurve.def("First", (const opencascade::handle<Geom2d_Curve> & (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::First, "Returns first element");
	cls_TColGeom2d_Array1OfCurve.def("ChangeFirst", (opencascade::handle<Geom2d_Curve> & (TColGeom2d_Array1OfCurve::*)()) &TColGeom2d_Array1OfCurve::ChangeFirst, "Returns first element");
	cls_TColGeom2d_Array1OfCurve.def("Last", (const opencascade::handle<Geom2d_Curve> & (TColGeom2d_Array1OfCurve::*)() const ) &TColGeom2d_Array1OfCurve::Last, "Returns last element");
	cls_TColGeom2d_Array1OfCurve.def("ChangeLast", (opencascade::handle<Geom2d_Curve> & (TColGeom2d_Array1OfCurve::*)()) &TColGeom2d_Array1OfCurve::ChangeLast, "Returns last element");
	cls_TColGeom2d_Array1OfCurve.def("Value", (const opencascade::handle<Geom2d_Curve> & (TColGeom2d_Array1OfCurve::*)(const Standard_Integer) const ) &TColGeom2d_Array1OfCurve::Value, "Constant value access", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfCurve.def("__call__", (const opencascade::handle<Geom2d_Curve> & (TColGeom2d_Array1OfCurve::*)(const Standard_Integer) const ) &TColGeom2d_Array1OfCurve::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfCurve.def("ChangeValue", (opencascade::handle<Geom2d_Curve> & (TColGeom2d_Array1OfCurve::*)(const Standard_Integer)) &TColGeom2d_Array1OfCurve::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfCurve.def("__call__", (opencascade::handle<Geom2d_Curve> & (TColGeom2d_Array1OfCurve::*)(const Standard_Integer)) &TColGeom2d_Array1OfCurve::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfCurve.def("SetValue", (void (TColGeom2d_Array1OfCurve::*)(const Standard_Integer, const opencascade::handle<Geom2d_Curve> &)) &TColGeom2d_Array1OfCurve::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_Array1OfCurve.def("Resize", (void (TColGeom2d_Array1OfCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColGeom2d_Array1OfCurve::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColGeom2d_Array1OfCurve.def("__iter__", [](const TColGeom2d_Array1OfCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColGeom2d_Array1OfBSplineCurve, std::unique_ptr<TColGeom2d_Array1OfBSplineCurve, Deleter<TColGeom2d_Array1OfBSplineCurve>>> cls_TColGeom2d_Array1OfBSplineCurve(mod, "TColGeom2d_Array1OfBSplineCurve", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColGeom2d_Array1OfBSplineCurve.def(py::init<>());
	cls_TColGeom2d_Array1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_Array1OfBSplineCurve.def(py::init([] (const TColGeom2d_Array1OfBSplineCurve &other) {return new TColGeom2d_Array1OfBSplineCurve(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColGeom2d_Array1OfBSplineCurve.def(py::init<TColGeom2d_Array1OfBSplineCurve &&>(), py::arg("theOther"));
	cls_TColGeom2d_Array1OfBSplineCurve.def(py::init<const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("begin", (TColGeom2d_Array1OfBSplineCurve::iterator (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColGeom2d_Array1OfBSplineCurve.def("end", (TColGeom2d_Array1OfBSplineCurve::iterator (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColGeom2d_Array1OfBSplineCurve.def("cbegin", (TColGeom2d_Array1OfBSplineCurve::const_iterator (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColGeom2d_Array1OfBSplineCurve.def("cend", (TColGeom2d_Array1OfBSplineCurve::const_iterator (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColGeom2d_Array1OfBSplineCurve.def("Init", (void (TColGeom2d_Array1OfBSplineCurve::*)(const opencascade::handle<Geom2d_BSplineCurve> &)) &TColGeom2d_Array1OfBSplineCurve::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("Size", (Standard_Integer (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::Size, "Size query");
	cls_TColGeom2d_Array1OfBSplineCurve.def("Length", (Standard_Integer (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::Length, "Length query (the same)");
	cls_TColGeom2d_Array1OfBSplineCurve.def("IsEmpty", (Standard_Boolean (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColGeom2d_Array1OfBSplineCurve.def("Lower", (Standard_Integer (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::Lower, "Lower bound");
	cls_TColGeom2d_Array1OfBSplineCurve.def("Upper", (Standard_Integer (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::Upper, "Upper bound");
	cls_TColGeom2d_Array1OfBSplineCurve.def("IsDeletable", (Standard_Boolean (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::IsDeletable, "myDeletable flag");
	cls_TColGeom2d_Array1OfBSplineCurve.def("IsAllocated", (Standard_Boolean (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColGeom2d_Array1OfBSplineCurve.def("Assign", (TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_Array1OfBSplineCurve::*)(const TColGeom2d_Array1OfBSplineCurve &)) &TColGeom2d_Array1OfBSplineCurve::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColGeom2d_Array1OfBSplineCurve.def("Move", (TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_Array1OfBSplineCurve::*)(TColGeom2d_Array1OfBSplineCurve &&)) &TColGeom2d_Array1OfBSplineCurve::Move, "Move assignment", py::arg("theOther"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("assign", (TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_Array1OfBSplineCurve::*)(const TColGeom2d_Array1OfBSplineCurve &)) &TColGeom2d_Array1OfBSplineCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColGeom2d_Array1OfBSplineCurve.def("assign", (TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_Array1OfBSplineCurve::*)(TColGeom2d_Array1OfBSplineCurve &&)) &TColGeom2d_Array1OfBSplineCurve::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("First", (const opencascade::handle<Geom2d_BSplineCurve> & (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::First, "Returns first element");
	cls_TColGeom2d_Array1OfBSplineCurve.def("ChangeFirst", (opencascade::handle<Geom2d_BSplineCurve> & (TColGeom2d_Array1OfBSplineCurve::*)()) &TColGeom2d_Array1OfBSplineCurve::ChangeFirst, "Returns first element");
	cls_TColGeom2d_Array1OfBSplineCurve.def("Last", (const opencascade::handle<Geom2d_BSplineCurve> & (TColGeom2d_Array1OfBSplineCurve::*)() const ) &TColGeom2d_Array1OfBSplineCurve::Last, "Returns last element");
	cls_TColGeom2d_Array1OfBSplineCurve.def("ChangeLast", (opencascade::handle<Geom2d_BSplineCurve> & (TColGeom2d_Array1OfBSplineCurve::*)()) &TColGeom2d_Array1OfBSplineCurve::ChangeLast, "Returns last element");
	cls_TColGeom2d_Array1OfBSplineCurve.def("Value", (const opencascade::handle<Geom2d_BSplineCurve> & (TColGeom2d_Array1OfBSplineCurve::*)(const Standard_Integer) const ) &TColGeom2d_Array1OfBSplineCurve::Value, "Constant value access", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("__call__", (const opencascade::handle<Geom2d_BSplineCurve> & (TColGeom2d_Array1OfBSplineCurve::*)(const Standard_Integer) const ) &TColGeom2d_Array1OfBSplineCurve::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("ChangeValue", (opencascade::handle<Geom2d_BSplineCurve> & (TColGeom2d_Array1OfBSplineCurve::*)(const Standard_Integer)) &TColGeom2d_Array1OfBSplineCurve::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("__call__", (opencascade::handle<Geom2d_BSplineCurve> & (TColGeom2d_Array1OfBSplineCurve::*)(const Standard_Integer)) &TColGeom2d_Array1OfBSplineCurve::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("SetValue", (void (TColGeom2d_Array1OfBSplineCurve::*)(const Standard_Integer, const opencascade::handle<Geom2d_BSplineCurve> &)) &TColGeom2d_Array1OfBSplineCurve::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("Resize", (void (TColGeom2d_Array1OfBSplineCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColGeom2d_Array1OfBSplineCurve::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColGeom2d_Array1OfBSplineCurve.def("__iter__", [](const TColGeom2d_Array1OfBSplineCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColGeom2d_SequenceOfBoundedCurve, std::unique_ptr<TColGeom2d_SequenceOfBoundedCurve, Deleter<TColGeom2d_SequenceOfBoundedCurve>>, NCollection_BaseSequence> cls_TColGeom2d_SequenceOfBoundedCurve(mod, "TColGeom2d_SequenceOfBoundedCurve", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColGeom2d_SequenceOfBoundedCurve.def(py::init<>());
	cls_TColGeom2d_SequenceOfBoundedCurve.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def(py::init([] (const TColGeom2d_SequenceOfBoundedCurve &other) {return new TColGeom2d_SequenceOfBoundedCurve(other);}), "Copy constructor", py::arg("other"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("begin", (TColGeom2d_SequenceOfBoundedCurve::iterator (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("end", (TColGeom2d_SequenceOfBoundedCurve::iterator (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("cbegin", (TColGeom2d_SequenceOfBoundedCurve::const_iterator (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("cend", (TColGeom2d_SequenceOfBoundedCurve::const_iterator (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Size", (Standard_Integer (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::Size, "Number of items");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Length", (Standard_Integer (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::Length, "Number of items");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Lower", (Standard_Integer (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::Lower, "Method for consistency with other collections.");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Upper", (Standard_Integer (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::Upper, "Method for consistency with other collections.");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("IsEmpty", (Standard_Boolean (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::IsEmpty, "Empty query");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Reverse", (void (TColGeom2d_SequenceOfBoundedCurve::*)()) &TColGeom2d_SequenceOfBoundedCurve::Reverse, "Reverse sequence");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Exchange", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer, const Standard_Integer)) &TColGeom2d_SequenceOfBoundedCurve::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_SequenceOfBoundedCurve::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Clear", [](TColGeom2d_SequenceOfBoundedCurve &self) -> void { return self.Clear(); });
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Clear", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_SequenceOfBoundedCurve::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Assign", (TColGeom2d_SequenceOfBoundedCurve & (TColGeom2d_SequenceOfBoundedCurve::*)(const TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_SequenceOfBoundedCurve::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("assign", (TColGeom2d_SequenceOfBoundedCurve & (TColGeom2d_SequenceOfBoundedCurve::*)(const TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_SequenceOfBoundedCurve::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Remove", (void (TColGeom2d_SequenceOfBoundedCurve::*)(TColGeom2d_SequenceOfBoundedCurve::Iterator &)) &TColGeom2d_SequenceOfBoundedCurve::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Remove", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer)) &TColGeom2d_SequenceOfBoundedCurve::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Remove", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer, const Standard_Integer)) &TColGeom2d_SequenceOfBoundedCurve::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Append", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const opencascade::handle<Geom2d_BoundedCurve> &)) &TColGeom2d_SequenceOfBoundedCurve::Append, "Append one item", py::arg("theItem"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Append", (void (TColGeom2d_SequenceOfBoundedCurve::*)(TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_SequenceOfBoundedCurve::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Prepend", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const opencascade::handle<Geom2d_BoundedCurve> &)) &TColGeom2d_SequenceOfBoundedCurve::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Prepend", (void (TColGeom2d_SequenceOfBoundedCurve::*)(TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_SequenceOfBoundedCurve::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("InsertBefore", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer, const opencascade::handle<Geom2d_BoundedCurve> &)) &TColGeom2d_SequenceOfBoundedCurve::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("InsertBefore", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer, TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_SequenceOfBoundedCurve::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("InsertAfter", (void (TColGeom2d_SequenceOfBoundedCurve::*)(TColGeom2d_SequenceOfBoundedCurve::Iterator &, const opencascade::handle<Geom2d_BoundedCurve> &)) &TColGeom2d_SequenceOfBoundedCurve::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("InsertAfter", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer, TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_SequenceOfBoundedCurve::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("InsertAfter", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer, const opencascade::handle<Geom2d_BoundedCurve> &)) &TColGeom2d_SequenceOfBoundedCurve::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Split", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer, TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_SequenceOfBoundedCurve::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("First", (const opencascade::handle<Geom2d_BoundedCurve> & (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::First, "First item access");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("ChangeFirst", (opencascade::handle<Geom2d_BoundedCurve> & (TColGeom2d_SequenceOfBoundedCurve::*)()) &TColGeom2d_SequenceOfBoundedCurve::ChangeFirst, "First item access");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Last", (const opencascade::handle<Geom2d_BoundedCurve> & (TColGeom2d_SequenceOfBoundedCurve::*)() const ) &TColGeom2d_SequenceOfBoundedCurve::Last, "Last item access");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("ChangeLast", (opencascade::handle<Geom2d_BoundedCurve> & (TColGeom2d_SequenceOfBoundedCurve::*)()) &TColGeom2d_SequenceOfBoundedCurve::ChangeLast, "Last item access");
	cls_TColGeom2d_SequenceOfBoundedCurve.def("Value", (const opencascade::handle<Geom2d_BoundedCurve> & (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer) const ) &TColGeom2d_SequenceOfBoundedCurve::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("__call__", (const opencascade::handle<Geom2d_BoundedCurve> & (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer) const ) &TColGeom2d_SequenceOfBoundedCurve::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("ChangeValue", (opencascade::handle<Geom2d_BoundedCurve> & (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer)) &TColGeom2d_SequenceOfBoundedCurve::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("__call__", (opencascade::handle<Geom2d_BoundedCurve> & (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer)) &TColGeom2d_SequenceOfBoundedCurve::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("SetValue", (void (TColGeom2d_SequenceOfBoundedCurve::*)(const Standard_Integer, const opencascade::handle<Geom2d_BoundedCurve> &)) &TColGeom2d_SequenceOfBoundedCurve::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfBoundedCurve.def("__iter__", [](const TColGeom2d_SequenceOfBoundedCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColGeom2d_SequenceOfCurve, std::unique_ptr<TColGeom2d_SequenceOfCurve, Deleter<TColGeom2d_SequenceOfCurve>>, NCollection_BaseSequence> cls_TColGeom2d_SequenceOfCurve(mod, "TColGeom2d_SequenceOfCurve", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColGeom2d_SequenceOfCurve.def(py::init<>());
	cls_TColGeom2d_SequenceOfCurve.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColGeom2d_SequenceOfCurve.def(py::init([] (const TColGeom2d_SequenceOfCurve &other) {return new TColGeom2d_SequenceOfCurve(other);}), "Copy constructor", py::arg("other"));
	cls_TColGeom2d_SequenceOfCurve.def("begin", (TColGeom2d_SequenceOfCurve::iterator (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColGeom2d_SequenceOfCurve.def("end", (TColGeom2d_SequenceOfCurve::iterator (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom2d_SequenceOfCurve.def("cbegin", (TColGeom2d_SequenceOfCurve::const_iterator (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColGeom2d_SequenceOfCurve.def("cend", (TColGeom2d_SequenceOfCurve::const_iterator (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom2d_SequenceOfCurve.def("Size", (Standard_Integer (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::Size, "Number of items");
	cls_TColGeom2d_SequenceOfCurve.def("Length", (Standard_Integer (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::Length, "Number of items");
	cls_TColGeom2d_SequenceOfCurve.def("Lower", (Standard_Integer (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::Lower, "Method for consistency with other collections.");
	cls_TColGeom2d_SequenceOfCurve.def("Upper", (Standard_Integer (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::Upper, "Method for consistency with other collections.");
	cls_TColGeom2d_SequenceOfCurve.def("IsEmpty", (Standard_Boolean (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::IsEmpty, "Empty query");
	cls_TColGeom2d_SequenceOfCurve.def("Reverse", (void (TColGeom2d_SequenceOfCurve::*)()) &TColGeom2d_SequenceOfCurve::Reverse, "Reverse sequence");
	cls_TColGeom2d_SequenceOfCurve.def("Exchange", (void (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer, const Standard_Integer)) &TColGeom2d_SequenceOfCurve::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColGeom2d_SequenceOfCurve.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_SequenceOfCurve::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColGeom2d_SequenceOfCurve.def("Clear", [](TColGeom2d_SequenceOfCurve &self) -> void { return self.Clear(); });
	cls_TColGeom2d_SequenceOfCurve.def("Clear", (void (TColGeom2d_SequenceOfCurve::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_SequenceOfCurve::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColGeom2d_SequenceOfCurve.def("Assign", (TColGeom2d_SequenceOfCurve & (TColGeom2d_SequenceOfCurve::*)(const TColGeom2d_SequenceOfCurve &)) &TColGeom2d_SequenceOfCurve::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColGeom2d_SequenceOfCurve.def("assign", (TColGeom2d_SequenceOfCurve & (TColGeom2d_SequenceOfCurve::*)(const TColGeom2d_SequenceOfCurve &)) &TColGeom2d_SequenceOfCurve::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColGeom2d_SequenceOfCurve.def("Remove", (void (TColGeom2d_SequenceOfCurve::*)(TColGeom2d_SequenceOfCurve::Iterator &)) &TColGeom2d_SequenceOfCurve::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColGeom2d_SequenceOfCurve.def("Remove", (void (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer)) &TColGeom2d_SequenceOfCurve::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfCurve.def("Remove", (void (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer, const Standard_Integer)) &TColGeom2d_SequenceOfCurve::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColGeom2d_SequenceOfCurve.def("Append", (void (TColGeom2d_SequenceOfCurve::*)(const opencascade::handle<Geom2d_Curve> &)) &TColGeom2d_SequenceOfCurve::Append, "Append one item", py::arg("theItem"));
	cls_TColGeom2d_SequenceOfCurve.def("Append", (void (TColGeom2d_SequenceOfCurve::*)(TColGeom2d_SequenceOfCurve &)) &TColGeom2d_SequenceOfCurve::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfCurve.def("Prepend", (void (TColGeom2d_SequenceOfCurve::*)(const opencascade::handle<Geom2d_Curve> &)) &TColGeom2d_SequenceOfCurve::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColGeom2d_SequenceOfCurve.def("Prepend", (void (TColGeom2d_SequenceOfCurve::*)(TColGeom2d_SequenceOfCurve &)) &TColGeom2d_SequenceOfCurve::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfCurve.def("InsertBefore", (void (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer, const opencascade::handle<Geom2d_Curve> &)) &TColGeom2d_SequenceOfCurve::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfCurve.def("InsertBefore", (void (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer, TColGeom2d_SequenceOfCurve &)) &TColGeom2d_SequenceOfCurve::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfCurve.def("InsertAfter", (void (TColGeom2d_SequenceOfCurve::*)(TColGeom2d_SequenceOfCurve::Iterator &, const opencascade::handle<Geom2d_Curve> &)) &TColGeom2d_SequenceOfCurve::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfCurve.def("InsertAfter", (void (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer, TColGeom2d_SequenceOfCurve &)) &TColGeom2d_SequenceOfCurve::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfCurve.def("InsertAfter", (void (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer, const opencascade::handle<Geom2d_Curve> &)) &TColGeom2d_SequenceOfCurve::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfCurve.def("Split", (void (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer, TColGeom2d_SequenceOfCurve &)) &TColGeom2d_SequenceOfCurve::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfCurve.def("First", (const opencascade::handle<Geom2d_Curve> & (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::First, "First item access");
	cls_TColGeom2d_SequenceOfCurve.def("ChangeFirst", (opencascade::handle<Geom2d_Curve> & (TColGeom2d_SequenceOfCurve::*)()) &TColGeom2d_SequenceOfCurve::ChangeFirst, "First item access");
	cls_TColGeom2d_SequenceOfCurve.def("Last", (const opencascade::handle<Geom2d_Curve> & (TColGeom2d_SequenceOfCurve::*)() const ) &TColGeom2d_SequenceOfCurve::Last, "Last item access");
	cls_TColGeom2d_SequenceOfCurve.def("ChangeLast", (opencascade::handle<Geom2d_Curve> & (TColGeom2d_SequenceOfCurve::*)()) &TColGeom2d_SequenceOfCurve::ChangeLast, "Last item access");
	cls_TColGeom2d_SequenceOfCurve.def("Value", (const opencascade::handle<Geom2d_Curve> & (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer) const ) &TColGeom2d_SequenceOfCurve::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfCurve.def("__call__", (const opencascade::handle<Geom2d_Curve> & (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer) const ) &TColGeom2d_SequenceOfCurve::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfCurve.def("ChangeValue", (opencascade::handle<Geom2d_Curve> & (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer)) &TColGeom2d_SequenceOfCurve::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfCurve.def("__call__", (opencascade::handle<Geom2d_Curve> & (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer)) &TColGeom2d_SequenceOfCurve::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfCurve.def("SetValue", (void (TColGeom2d_SequenceOfCurve::*)(const Standard_Integer, const opencascade::handle<Geom2d_Curve> &)) &TColGeom2d_SequenceOfCurve::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfCurve.def("__iter__", [](const TColGeom2d_SequenceOfCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColGeom2d_Array1OfBezierCurve, std::unique_ptr<TColGeom2d_Array1OfBezierCurve, Deleter<TColGeom2d_Array1OfBezierCurve>>> cls_TColGeom2d_Array1OfBezierCurve(mod, "TColGeom2d_Array1OfBezierCurve", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColGeom2d_Array1OfBezierCurve.def(py::init<>());
	cls_TColGeom2d_Array1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_Array1OfBezierCurve.def(py::init([] (const TColGeom2d_Array1OfBezierCurve &other) {return new TColGeom2d_Array1OfBezierCurve(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColGeom2d_Array1OfBezierCurve.def(py::init<TColGeom2d_Array1OfBezierCurve &&>(), py::arg("theOther"));
	cls_TColGeom2d_Array1OfBezierCurve.def(py::init<const opencascade::handle<Geom2d_BezierCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_Array1OfBezierCurve.def("begin", (TColGeom2d_Array1OfBezierCurve::iterator (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColGeom2d_Array1OfBezierCurve.def("end", (TColGeom2d_Array1OfBezierCurve::iterator (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColGeom2d_Array1OfBezierCurve.def("cbegin", (TColGeom2d_Array1OfBezierCurve::const_iterator (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColGeom2d_Array1OfBezierCurve.def("cend", (TColGeom2d_Array1OfBezierCurve::const_iterator (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColGeom2d_Array1OfBezierCurve.def("Init", (void (TColGeom2d_Array1OfBezierCurve::*)(const opencascade::handle<Geom2d_BezierCurve> &)) &TColGeom2d_Array1OfBezierCurve::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColGeom2d_Array1OfBezierCurve.def("Size", (Standard_Integer (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::Size, "Size query");
	cls_TColGeom2d_Array1OfBezierCurve.def("Length", (Standard_Integer (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::Length, "Length query (the same)");
	cls_TColGeom2d_Array1OfBezierCurve.def("IsEmpty", (Standard_Boolean (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColGeom2d_Array1OfBezierCurve.def("Lower", (Standard_Integer (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::Lower, "Lower bound");
	cls_TColGeom2d_Array1OfBezierCurve.def("Upper", (Standard_Integer (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::Upper, "Upper bound");
	cls_TColGeom2d_Array1OfBezierCurve.def("IsDeletable", (Standard_Boolean (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::IsDeletable, "myDeletable flag");
	cls_TColGeom2d_Array1OfBezierCurve.def("IsAllocated", (Standard_Boolean (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColGeom2d_Array1OfBezierCurve.def("Assign", (TColGeom2d_Array1OfBezierCurve & (TColGeom2d_Array1OfBezierCurve::*)(const TColGeom2d_Array1OfBezierCurve &)) &TColGeom2d_Array1OfBezierCurve::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColGeom2d_Array1OfBezierCurve.def("Move", (TColGeom2d_Array1OfBezierCurve & (TColGeom2d_Array1OfBezierCurve::*)(TColGeom2d_Array1OfBezierCurve &&)) &TColGeom2d_Array1OfBezierCurve::Move, "Move assignment", py::arg("theOther"));
	cls_TColGeom2d_Array1OfBezierCurve.def("assign", (TColGeom2d_Array1OfBezierCurve & (TColGeom2d_Array1OfBezierCurve::*)(const TColGeom2d_Array1OfBezierCurve &)) &TColGeom2d_Array1OfBezierCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColGeom2d_Array1OfBezierCurve.def("assign", (TColGeom2d_Array1OfBezierCurve & (TColGeom2d_Array1OfBezierCurve::*)(TColGeom2d_Array1OfBezierCurve &&)) &TColGeom2d_Array1OfBezierCurve::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColGeom2d_Array1OfBezierCurve.def("First", (const opencascade::handle<Geom2d_BezierCurve> & (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::First, "Returns first element");
	cls_TColGeom2d_Array1OfBezierCurve.def("ChangeFirst", (opencascade::handle<Geom2d_BezierCurve> & (TColGeom2d_Array1OfBezierCurve::*)()) &TColGeom2d_Array1OfBezierCurve::ChangeFirst, "Returns first element");
	cls_TColGeom2d_Array1OfBezierCurve.def("Last", (const opencascade::handle<Geom2d_BezierCurve> & (TColGeom2d_Array1OfBezierCurve::*)() const ) &TColGeom2d_Array1OfBezierCurve::Last, "Returns last element");
	cls_TColGeom2d_Array1OfBezierCurve.def("ChangeLast", (opencascade::handle<Geom2d_BezierCurve> & (TColGeom2d_Array1OfBezierCurve::*)()) &TColGeom2d_Array1OfBezierCurve::ChangeLast, "Returns last element");
	cls_TColGeom2d_Array1OfBezierCurve.def("Value", (const opencascade::handle<Geom2d_BezierCurve> & (TColGeom2d_Array1OfBezierCurve::*)(const Standard_Integer) const ) &TColGeom2d_Array1OfBezierCurve::Value, "Constant value access", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfBezierCurve.def("__call__", (const opencascade::handle<Geom2d_BezierCurve> & (TColGeom2d_Array1OfBezierCurve::*)(const Standard_Integer) const ) &TColGeom2d_Array1OfBezierCurve::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfBezierCurve.def("ChangeValue", (opencascade::handle<Geom2d_BezierCurve> & (TColGeom2d_Array1OfBezierCurve::*)(const Standard_Integer)) &TColGeom2d_Array1OfBezierCurve::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfBezierCurve.def("__call__", (opencascade::handle<Geom2d_BezierCurve> & (TColGeom2d_Array1OfBezierCurve::*)(const Standard_Integer)) &TColGeom2d_Array1OfBezierCurve::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColGeom2d_Array1OfBezierCurve.def("SetValue", (void (TColGeom2d_Array1OfBezierCurve::*)(const Standard_Integer, const opencascade::handle<Geom2d_BezierCurve> &)) &TColGeom2d_Array1OfBezierCurve::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_Array1OfBezierCurve.def("Resize", (void (TColGeom2d_Array1OfBezierCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColGeom2d_Array1OfBezierCurve::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColGeom2d_Array1OfBezierCurve.def("__iter__", [](const TColGeom2d_Array1OfBezierCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HArray1OfCurve.hxx
	py::class_<TColGeom2d_HArray1OfCurve, opencascade::handle<TColGeom2d_HArray1OfCurve>, TColGeom2d_Array1OfCurve, Standard_Transient> cls_TColGeom2d_HArray1OfCurve(mod, "TColGeom2d_HArray1OfCurve", "None");
	cls_TColGeom2d_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom2d_Array1OfCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom2d_HArray1OfCurve.def(py::init<const TColGeom2d_Array1OfCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HArray1OfCurve.def("Array1", (const TColGeom2d_Array1OfCurve & (TColGeom2d_HArray1OfCurve::*)() const ) &TColGeom2d_HArray1OfCurve::Array1, "None");
	cls_TColGeom2d_HArray1OfCurve.def("ChangeArray1", (TColGeom2d_Array1OfCurve & (TColGeom2d_HArray1OfCurve::*)()) &TColGeom2d_HArray1OfCurve::ChangeArray1, "None");
	cls_TColGeom2d_HArray1OfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HArray1OfCurve::get_type_name, "None");
	cls_TColGeom2d_HArray1OfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HArray1OfCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HArray1OfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HArray1OfCurve::*)() const ) &TColGeom2d_HArray1OfCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HSequenceOfCurve.hxx
	py::class_<TColGeom2d_HSequenceOfCurve, opencascade::handle<TColGeom2d_HSequenceOfCurve>, TColGeom2d_SequenceOfCurve, Standard_Transient> cls_TColGeom2d_HSequenceOfCurve(mod, "TColGeom2d_HSequenceOfCurve", "None");
	cls_TColGeom2d_HSequenceOfCurve.def(py::init<>());
	cls_TColGeom2d_HSequenceOfCurve.def(py::init<const TColGeom2d_SequenceOfCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HSequenceOfCurve.def("Sequence", (const TColGeom2d_SequenceOfCurve & (TColGeom2d_HSequenceOfCurve::*)() const ) &TColGeom2d_HSequenceOfCurve::Sequence, "None");
	cls_TColGeom2d_HSequenceOfCurve.def("Append", (void (TColGeom2d_HSequenceOfCurve::*)(const TColGeom2d_SequenceOfCurve::value_type &)) &TColGeom2d_HSequenceOfCurve::Append, "None", py::arg("theItem"));
	cls_TColGeom2d_HSequenceOfCurve.def("Append", (void (TColGeom2d_HSequenceOfCurve::*)(TColGeom2d_SequenceOfCurve &)) &TColGeom2d_HSequenceOfCurve::Append, "None", py::arg("theSequence"));
	cls_TColGeom2d_HSequenceOfCurve.def("ChangeSequence", (TColGeom2d_SequenceOfCurve & (TColGeom2d_HSequenceOfCurve::*)()) &TColGeom2d_HSequenceOfCurve::ChangeSequence, "None");
	cls_TColGeom2d_HSequenceOfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HSequenceOfCurve::get_type_name, "None");
	cls_TColGeom2d_HSequenceOfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HSequenceOfCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HSequenceOfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HSequenceOfCurve::*)() const ) &TColGeom2d_HSequenceOfCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HArray1OfBSplineCurve.hxx
	py::class_<TColGeom2d_HArray1OfBSplineCurve, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve>, TColGeom2d_Array1OfBSplineCurve, Standard_Transient> cls_TColGeom2d_HArray1OfBSplineCurve(mod, "TColGeom2d_HArray1OfBSplineCurve", "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom2d_Array1OfBSplineCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<const TColGeom2d_Array1OfBSplineCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HArray1OfBSplineCurve.def("Array1", (const TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_HArray1OfBSplineCurve::*)() const ) &TColGeom2d_HArray1OfBSplineCurve::Array1, "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def("ChangeArray1", (TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_HArray1OfBSplineCurve::*)()) &TColGeom2d_HArray1OfBSplineCurve::ChangeArray1, "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HArray1OfBSplineCurve::get_type_name, "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HArray1OfBSplineCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HArray1OfBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HArray1OfBSplineCurve::*)() const ) &TColGeom2d_HArray1OfBSplineCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HArray1OfBezierCurve.hxx
	py::class_<TColGeom2d_HArray1OfBezierCurve, opencascade::handle<TColGeom2d_HArray1OfBezierCurve>, TColGeom2d_Array1OfBezierCurve, Standard_Transient> cls_TColGeom2d_HArray1OfBezierCurve(mod, "TColGeom2d_HArray1OfBezierCurve", "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom2d_Array1OfBezierCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<const TColGeom2d_Array1OfBezierCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HArray1OfBezierCurve.def("Array1", (const TColGeom2d_Array1OfBezierCurve & (TColGeom2d_HArray1OfBezierCurve::*)() const ) &TColGeom2d_HArray1OfBezierCurve::Array1, "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def("ChangeArray1", (TColGeom2d_Array1OfBezierCurve & (TColGeom2d_HArray1OfBezierCurve::*)()) &TColGeom2d_HArray1OfBezierCurve::ChangeArray1, "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HArray1OfBezierCurve::get_type_name, "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HArray1OfBezierCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HArray1OfBezierCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HArray1OfBezierCurve::*)() const ) &TColGeom2d_HArray1OfBezierCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColGeom2d_SequenceOfGeometry, std::unique_ptr<TColGeom2d_SequenceOfGeometry, Deleter<TColGeom2d_SequenceOfGeometry>>, NCollection_BaseSequence> cls_TColGeom2d_SequenceOfGeometry(mod, "TColGeom2d_SequenceOfGeometry", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColGeom2d_SequenceOfGeometry.def(py::init<>());
	cls_TColGeom2d_SequenceOfGeometry.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColGeom2d_SequenceOfGeometry.def(py::init([] (const TColGeom2d_SequenceOfGeometry &other) {return new TColGeom2d_SequenceOfGeometry(other);}), "Copy constructor", py::arg("other"));
	cls_TColGeom2d_SequenceOfGeometry.def("begin", (TColGeom2d_SequenceOfGeometry::iterator (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColGeom2d_SequenceOfGeometry.def("end", (TColGeom2d_SequenceOfGeometry::iterator (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom2d_SequenceOfGeometry.def("cbegin", (TColGeom2d_SequenceOfGeometry::const_iterator (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColGeom2d_SequenceOfGeometry.def("cend", (TColGeom2d_SequenceOfGeometry::const_iterator (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom2d_SequenceOfGeometry.def("Size", (Standard_Integer (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::Size, "Number of items");
	cls_TColGeom2d_SequenceOfGeometry.def("Length", (Standard_Integer (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::Length, "Number of items");
	cls_TColGeom2d_SequenceOfGeometry.def("Lower", (Standard_Integer (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::Lower, "Method for consistency with other collections.");
	cls_TColGeom2d_SequenceOfGeometry.def("Upper", (Standard_Integer (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::Upper, "Method for consistency with other collections.");
	cls_TColGeom2d_SequenceOfGeometry.def("IsEmpty", (Standard_Boolean (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::IsEmpty, "Empty query");
	cls_TColGeom2d_SequenceOfGeometry.def("Reverse", (void (TColGeom2d_SequenceOfGeometry::*)()) &TColGeom2d_SequenceOfGeometry::Reverse, "Reverse sequence");
	cls_TColGeom2d_SequenceOfGeometry.def("Exchange", (void (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer, const Standard_Integer)) &TColGeom2d_SequenceOfGeometry::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColGeom2d_SequenceOfGeometry.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_SequenceOfGeometry::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColGeom2d_SequenceOfGeometry.def("Clear", [](TColGeom2d_SequenceOfGeometry &self) -> void { return self.Clear(); });
	cls_TColGeom2d_SequenceOfGeometry.def("Clear", (void (TColGeom2d_SequenceOfGeometry::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_SequenceOfGeometry::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColGeom2d_SequenceOfGeometry.def("Assign", (TColGeom2d_SequenceOfGeometry & (TColGeom2d_SequenceOfGeometry::*)(const TColGeom2d_SequenceOfGeometry &)) &TColGeom2d_SequenceOfGeometry::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColGeom2d_SequenceOfGeometry.def("assign", (TColGeom2d_SequenceOfGeometry & (TColGeom2d_SequenceOfGeometry::*)(const TColGeom2d_SequenceOfGeometry &)) &TColGeom2d_SequenceOfGeometry::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColGeom2d_SequenceOfGeometry.def("Remove", (void (TColGeom2d_SequenceOfGeometry::*)(TColGeom2d_SequenceOfGeometry::Iterator &)) &TColGeom2d_SequenceOfGeometry::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColGeom2d_SequenceOfGeometry.def("Remove", (void (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer)) &TColGeom2d_SequenceOfGeometry::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfGeometry.def("Remove", (void (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer, const Standard_Integer)) &TColGeom2d_SequenceOfGeometry::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColGeom2d_SequenceOfGeometry.def("Append", (void (TColGeom2d_SequenceOfGeometry::*)(const opencascade::handle<Geom2d_Geometry> &)) &TColGeom2d_SequenceOfGeometry::Append, "Append one item", py::arg("theItem"));
	cls_TColGeom2d_SequenceOfGeometry.def("Append", (void (TColGeom2d_SequenceOfGeometry::*)(TColGeom2d_SequenceOfGeometry &)) &TColGeom2d_SequenceOfGeometry::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfGeometry.def("Prepend", (void (TColGeom2d_SequenceOfGeometry::*)(const opencascade::handle<Geom2d_Geometry> &)) &TColGeom2d_SequenceOfGeometry::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColGeom2d_SequenceOfGeometry.def("Prepend", (void (TColGeom2d_SequenceOfGeometry::*)(TColGeom2d_SequenceOfGeometry &)) &TColGeom2d_SequenceOfGeometry::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfGeometry.def("InsertBefore", (void (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer, const opencascade::handle<Geom2d_Geometry> &)) &TColGeom2d_SequenceOfGeometry::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfGeometry.def("InsertBefore", (void (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer, TColGeom2d_SequenceOfGeometry &)) &TColGeom2d_SequenceOfGeometry::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfGeometry.def("InsertAfter", (void (TColGeom2d_SequenceOfGeometry::*)(TColGeom2d_SequenceOfGeometry::Iterator &, const opencascade::handle<Geom2d_Geometry> &)) &TColGeom2d_SequenceOfGeometry::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfGeometry.def("InsertAfter", (void (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer, TColGeom2d_SequenceOfGeometry &)) &TColGeom2d_SequenceOfGeometry::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfGeometry.def("InsertAfter", (void (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer, const opencascade::handle<Geom2d_Geometry> &)) &TColGeom2d_SequenceOfGeometry::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfGeometry.def("Split", (void (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer, TColGeom2d_SequenceOfGeometry &)) &TColGeom2d_SequenceOfGeometry::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom2d_SequenceOfGeometry.def("First", (const opencascade::handle<Geom2d_Geometry> & (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::First, "First item access");
	cls_TColGeom2d_SequenceOfGeometry.def("ChangeFirst", (opencascade::handle<Geom2d_Geometry> & (TColGeom2d_SequenceOfGeometry::*)()) &TColGeom2d_SequenceOfGeometry::ChangeFirst, "First item access");
	cls_TColGeom2d_SequenceOfGeometry.def("Last", (const opencascade::handle<Geom2d_Geometry> & (TColGeom2d_SequenceOfGeometry::*)() const ) &TColGeom2d_SequenceOfGeometry::Last, "Last item access");
	cls_TColGeom2d_SequenceOfGeometry.def("ChangeLast", (opencascade::handle<Geom2d_Geometry> & (TColGeom2d_SequenceOfGeometry::*)()) &TColGeom2d_SequenceOfGeometry::ChangeLast, "Last item access");
	cls_TColGeom2d_SequenceOfGeometry.def("Value", (const opencascade::handle<Geom2d_Geometry> & (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer) const ) &TColGeom2d_SequenceOfGeometry::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfGeometry.def("__call__", (const opencascade::handle<Geom2d_Geometry> & (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer) const ) &TColGeom2d_SequenceOfGeometry::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfGeometry.def("ChangeValue", (opencascade::handle<Geom2d_Geometry> & (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer)) &TColGeom2d_SequenceOfGeometry::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfGeometry.def("__call__", (opencascade::handle<Geom2d_Geometry> & (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer)) &TColGeom2d_SequenceOfGeometry::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColGeom2d_SequenceOfGeometry.def("SetValue", (void (TColGeom2d_SequenceOfGeometry::*)(const Standard_Integer, const opencascade::handle<Geom2d_Geometry> &)) &TColGeom2d_SequenceOfGeometry::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom2d_SequenceOfGeometry.def("__iter__", [](const TColGeom2d_SequenceOfGeometry &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom2d_HSequenceOfBoundedCurve.hxx
	py::class_<TColGeom2d_HSequenceOfBoundedCurve, opencascade::handle<TColGeom2d_HSequenceOfBoundedCurve>, TColGeom2d_SequenceOfBoundedCurve, Standard_Transient> cls_TColGeom2d_HSequenceOfBoundedCurve(mod, "TColGeom2d_HSequenceOfBoundedCurve", "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def(py::init<>());
	cls_TColGeom2d_HSequenceOfBoundedCurve.def(py::init<const TColGeom2d_SequenceOfBoundedCurve &>(), py::arg("theOther"));
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("Sequence", (const TColGeom2d_SequenceOfBoundedCurve & (TColGeom2d_HSequenceOfBoundedCurve::*)() const ) &TColGeom2d_HSequenceOfBoundedCurve::Sequence, "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("Append", (void (TColGeom2d_HSequenceOfBoundedCurve::*)(const TColGeom2d_SequenceOfBoundedCurve::value_type &)) &TColGeom2d_HSequenceOfBoundedCurve::Append, "None", py::arg("theItem"));
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("Append", (void (TColGeom2d_HSequenceOfBoundedCurve::*)(TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_HSequenceOfBoundedCurve::Append, "None", py::arg("theSequence"));
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("ChangeSequence", (TColGeom2d_SequenceOfBoundedCurve & (TColGeom2d_HSequenceOfBoundedCurve::*)()) &TColGeom2d_HSequenceOfBoundedCurve::ChangeSequence, "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HSequenceOfBoundedCurve::get_type_name, "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HSequenceOfBoundedCurve::get_type_descriptor, "None");
	cls_TColGeom2d_HSequenceOfBoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HSequenceOfBoundedCurve::*)() const ) &TColGeom2d_HSequenceOfBoundedCurve::DynamicType, "None");


}
