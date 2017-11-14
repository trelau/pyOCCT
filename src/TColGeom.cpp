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
#include <TColGeom_Array1OfSurface.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TColGeom_HArray1OfSurface.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <TColGeom_Array1OfBSplineCurve.hxx>
#include <TColGeom_HArray1OfBSplineCurve.hxx>
#include <TColGeom_Array1OfBezierCurve.hxx>
#include <NCollection_Array2.hxx>
#include <TColGeom_Array2OfBezierSurface.hxx>
#include <TColGeom_SequenceOfBoundedCurve.hxx>
#include <TColGeom_HSequenceOfBoundedCurve.hxx>
#include <TColGeom_Array2OfSurface.hxx>
#include <TColGeom_HArray2OfSurface.hxx>
#include <TColGeom_HSequenceOfCurve.hxx>
#include <TColGeom_Array1OfCurve.hxx>
#include <TColGeom_HArray1OfCurve.hxx>
#include <TColGeom_HArray1OfBezierCurve.hxx>
#include <TColGeom_SequenceOfSurface.hxx>

PYBIND11_MODULE(TColGeom, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColGeom_Array1OfSurface, std::unique_ptr<TColGeom_Array1OfSurface, Deleter<TColGeom_Array1OfSurface>>> cls_TColGeom_Array1OfSurface(mod, "TColGeom_Array1OfSurface", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColGeom_Array1OfSurface.def(py::init<>());
	cls_TColGeom_Array1OfSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_Array1OfSurface.def(py::init([] (const TColGeom_Array1OfSurface &other) {return new TColGeom_Array1OfSurface(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColGeom_Array1OfSurface.def(py::init<TColGeom_Array1OfSurface &&>(), py::arg("theOther"));
	cls_TColGeom_Array1OfSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_Array1OfSurface.def("begin", (TColGeom_Array1OfSurface::iterator (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColGeom_Array1OfSurface.def("end", (TColGeom_Array1OfSurface::iterator (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColGeom_Array1OfSurface.def("cbegin", (TColGeom_Array1OfSurface::const_iterator (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColGeom_Array1OfSurface.def("cend", (TColGeom_Array1OfSurface::const_iterator (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColGeom_Array1OfSurface.def("Init", (void (TColGeom_Array1OfSurface::*)(const opencascade::handle<Geom_Surface> &)) &TColGeom_Array1OfSurface::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColGeom_Array1OfSurface.def("Size", (Standard_Integer (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::Size, "Size query");
	cls_TColGeom_Array1OfSurface.def("Length", (Standard_Integer (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::Length, "Length query (the same)");
	cls_TColGeom_Array1OfSurface.def("IsEmpty", (Standard_Boolean (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColGeom_Array1OfSurface.def("Lower", (Standard_Integer (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::Lower, "Lower bound");
	cls_TColGeom_Array1OfSurface.def("Upper", (Standard_Integer (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::Upper, "Upper bound");
	cls_TColGeom_Array1OfSurface.def("IsDeletable", (Standard_Boolean (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::IsDeletable, "myDeletable flag");
	cls_TColGeom_Array1OfSurface.def("IsAllocated", (Standard_Boolean (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColGeom_Array1OfSurface.def("Assign", (TColGeom_Array1OfSurface & (TColGeom_Array1OfSurface::*)(const TColGeom_Array1OfSurface &)) &TColGeom_Array1OfSurface::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColGeom_Array1OfSurface.def("Move", (TColGeom_Array1OfSurface & (TColGeom_Array1OfSurface::*)(TColGeom_Array1OfSurface &&)) &TColGeom_Array1OfSurface::Move, "Move assignment", py::arg("theOther"));
	cls_TColGeom_Array1OfSurface.def("assign", (TColGeom_Array1OfSurface & (TColGeom_Array1OfSurface::*)(const TColGeom_Array1OfSurface &)) &TColGeom_Array1OfSurface::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColGeom_Array1OfSurface.def("assign", (TColGeom_Array1OfSurface & (TColGeom_Array1OfSurface::*)(TColGeom_Array1OfSurface &&)) &TColGeom_Array1OfSurface::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColGeom_Array1OfSurface.def("First", (const opencascade::handle<Geom_Surface> & (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::First, "Returns first element");
	cls_TColGeom_Array1OfSurface.def("ChangeFirst", (opencascade::handle<Geom_Surface> & (TColGeom_Array1OfSurface::*)()) &TColGeom_Array1OfSurface::ChangeFirst, "Returns first element");
	cls_TColGeom_Array1OfSurface.def("Last", (const opencascade::handle<Geom_Surface> & (TColGeom_Array1OfSurface::*)() const ) &TColGeom_Array1OfSurface::Last, "Returns last element");
	cls_TColGeom_Array1OfSurface.def("ChangeLast", (opencascade::handle<Geom_Surface> & (TColGeom_Array1OfSurface::*)()) &TColGeom_Array1OfSurface::ChangeLast, "Returns last element");
	cls_TColGeom_Array1OfSurface.def("Value", (const opencascade::handle<Geom_Surface> & (TColGeom_Array1OfSurface::*)(const Standard_Integer) const ) &TColGeom_Array1OfSurface::Value, "Constant value access", py::arg("theIndex"));
	cls_TColGeom_Array1OfSurface.def("__call__", (const opencascade::handle<Geom_Surface> & (TColGeom_Array1OfSurface::*)(const Standard_Integer) const ) &TColGeom_Array1OfSurface::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColGeom_Array1OfSurface.def("ChangeValue", (opencascade::handle<Geom_Surface> & (TColGeom_Array1OfSurface::*)(const Standard_Integer)) &TColGeom_Array1OfSurface::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColGeom_Array1OfSurface.def("__call__", (opencascade::handle<Geom_Surface> & (TColGeom_Array1OfSurface::*)(const Standard_Integer)) &TColGeom_Array1OfSurface::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColGeom_Array1OfSurface.def("SetValue", (void (TColGeom_Array1OfSurface::*)(const Standard_Integer, const opencascade::handle<Geom_Surface> &)) &TColGeom_Array1OfSurface::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_Array1OfSurface.def("Resize", (void (TColGeom_Array1OfSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColGeom_Array1OfSurface::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColGeom_Array1OfSurface.def("__iter__", [](const TColGeom_Array1OfSurface &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColGeom_Array1OfBSplineCurve, std::unique_ptr<TColGeom_Array1OfBSplineCurve, Deleter<TColGeom_Array1OfBSplineCurve>>> cls_TColGeom_Array1OfBSplineCurve(mod, "TColGeom_Array1OfBSplineCurve", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColGeom_Array1OfBSplineCurve.def(py::init<>());
	cls_TColGeom_Array1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_Array1OfBSplineCurve.def(py::init([] (const TColGeom_Array1OfBSplineCurve &other) {return new TColGeom_Array1OfBSplineCurve(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColGeom_Array1OfBSplineCurve.def(py::init<TColGeom_Array1OfBSplineCurve &&>(), py::arg("theOther"));
	cls_TColGeom_Array1OfBSplineCurve.def(py::init<const opencascade::handle<Geom_BSplineCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_Array1OfBSplineCurve.def("begin", (TColGeom_Array1OfBSplineCurve::iterator (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColGeom_Array1OfBSplineCurve.def("end", (TColGeom_Array1OfBSplineCurve::iterator (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColGeom_Array1OfBSplineCurve.def("cbegin", (TColGeom_Array1OfBSplineCurve::const_iterator (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColGeom_Array1OfBSplineCurve.def("cend", (TColGeom_Array1OfBSplineCurve::const_iterator (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColGeom_Array1OfBSplineCurve.def("Init", (void (TColGeom_Array1OfBSplineCurve::*)(const opencascade::handle<Geom_BSplineCurve> &)) &TColGeom_Array1OfBSplineCurve::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColGeom_Array1OfBSplineCurve.def("Size", (Standard_Integer (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::Size, "Size query");
	cls_TColGeom_Array1OfBSplineCurve.def("Length", (Standard_Integer (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::Length, "Length query (the same)");
	cls_TColGeom_Array1OfBSplineCurve.def("IsEmpty", (Standard_Boolean (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColGeom_Array1OfBSplineCurve.def("Lower", (Standard_Integer (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::Lower, "Lower bound");
	cls_TColGeom_Array1OfBSplineCurve.def("Upper", (Standard_Integer (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::Upper, "Upper bound");
	cls_TColGeom_Array1OfBSplineCurve.def("IsDeletable", (Standard_Boolean (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::IsDeletable, "myDeletable flag");
	cls_TColGeom_Array1OfBSplineCurve.def("IsAllocated", (Standard_Boolean (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColGeom_Array1OfBSplineCurve.def("Assign", (TColGeom_Array1OfBSplineCurve & (TColGeom_Array1OfBSplineCurve::*)(const TColGeom_Array1OfBSplineCurve &)) &TColGeom_Array1OfBSplineCurve::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColGeom_Array1OfBSplineCurve.def("Move", (TColGeom_Array1OfBSplineCurve & (TColGeom_Array1OfBSplineCurve::*)(TColGeom_Array1OfBSplineCurve &&)) &TColGeom_Array1OfBSplineCurve::Move, "Move assignment", py::arg("theOther"));
	cls_TColGeom_Array1OfBSplineCurve.def("assign", (TColGeom_Array1OfBSplineCurve & (TColGeom_Array1OfBSplineCurve::*)(const TColGeom_Array1OfBSplineCurve &)) &TColGeom_Array1OfBSplineCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColGeom_Array1OfBSplineCurve.def("assign", (TColGeom_Array1OfBSplineCurve & (TColGeom_Array1OfBSplineCurve::*)(TColGeom_Array1OfBSplineCurve &&)) &TColGeom_Array1OfBSplineCurve::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColGeom_Array1OfBSplineCurve.def("First", (const opencascade::handle<Geom_BSplineCurve> & (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::First, "Returns first element");
	cls_TColGeom_Array1OfBSplineCurve.def("ChangeFirst", (opencascade::handle<Geom_BSplineCurve> & (TColGeom_Array1OfBSplineCurve::*)()) &TColGeom_Array1OfBSplineCurve::ChangeFirst, "Returns first element");
	cls_TColGeom_Array1OfBSplineCurve.def("Last", (const opencascade::handle<Geom_BSplineCurve> & (TColGeom_Array1OfBSplineCurve::*)() const ) &TColGeom_Array1OfBSplineCurve::Last, "Returns last element");
	cls_TColGeom_Array1OfBSplineCurve.def("ChangeLast", (opencascade::handle<Geom_BSplineCurve> & (TColGeom_Array1OfBSplineCurve::*)()) &TColGeom_Array1OfBSplineCurve::ChangeLast, "Returns last element");
	cls_TColGeom_Array1OfBSplineCurve.def("Value", (const opencascade::handle<Geom_BSplineCurve> & (TColGeom_Array1OfBSplineCurve::*)(const Standard_Integer) const ) &TColGeom_Array1OfBSplineCurve::Value, "Constant value access", py::arg("theIndex"));
	cls_TColGeom_Array1OfBSplineCurve.def("__call__", (const opencascade::handle<Geom_BSplineCurve> & (TColGeom_Array1OfBSplineCurve::*)(const Standard_Integer) const ) &TColGeom_Array1OfBSplineCurve::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColGeom_Array1OfBSplineCurve.def("ChangeValue", (opencascade::handle<Geom_BSplineCurve> & (TColGeom_Array1OfBSplineCurve::*)(const Standard_Integer)) &TColGeom_Array1OfBSplineCurve::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColGeom_Array1OfBSplineCurve.def("__call__", (opencascade::handle<Geom_BSplineCurve> & (TColGeom_Array1OfBSplineCurve::*)(const Standard_Integer)) &TColGeom_Array1OfBSplineCurve::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColGeom_Array1OfBSplineCurve.def("SetValue", (void (TColGeom_Array1OfBSplineCurve::*)(const Standard_Integer, const opencascade::handle<Geom_BSplineCurve> &)) &TColGeom_Array1OfBSplineCurve::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_Array1OfBSplineCurve.def("Resize", (void (TColGeom_Array1OfBSplineCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColGeom_Array1OfBSplineCurve::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColGeom_Array1OfBSplineCurve.def("__iter__", [](const TColGeom_Array1OfBSplineCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColGeom_SequenceOfBoundedCurve, std::unique_ptr<TColGeom_SequenceOfBoundedCurve, Deleter<TColGeom_SequenceOfBoundedCurve>>, NCollection_BaseSequence> cls_TColGeom_SequenceOfBoundedCurve(mod, "TColGeom_SequenceOfBoundedCurve", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColGeom_SequenceOfBoundedCurve.def(py::init<>());
	cls_TColGeom_SequenceOfBoundedCurve.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColGeom_SequenceOfBoundedCurve.def(py::init([] (const TColGeom_SequenceOfBoundedCurve &other) {return new TColGeom_SequenceOfBoundedCurve(other);}), "Copy constructor", py::arg("other"));
	cls_TColGeom_SequenceOfBoundedCurve.def("begin", (TColGeom_SequenceOfBoundedCurve::iterator (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColGeom_SequenceOfBoundedCurve.def("end", (TColGeom_SequenceOfBoundedCurve::iterator (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom_SequenceOfBoundedCurve.def("cbegin", (TColGeom_SequenceOfBoundedCurve::const_iterator (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColGeom_SequenceOfBoundedCurve.def("cend", (TColGeom_SequenceOfBoundedCurve::const_iterator (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom_SequenceOfBoundedCurve.def("Size", (Standard_Integer (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::Size, "Number of items");
	cls_TColGeom_SequenceOfBoundedCurve.def("Length", (Standard_Integer (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::Length, "Number of items");
	cls_TColGeom_SequenceOfBoundedCurve.def("Lower", (Standard_Integer (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::Lower, "Method for consistency with other collections.");
	cls_TColGeom_SequenceOfBoundedCurve.def("Upper", (Standard_Integer (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::Upper, "Method for consistency with other collections.");
	cls_TColGeom_SequenceOfBoundedCurve.def("IsEmpty", (Standard_Boolean (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::IsEmpty, "Empty query");
	cls_TColGeom_SequenceOfBoundedCurve.def("Reverse", (void (TColGeom_SequenceOfBoundedCurve::*)()) &TColGeom_SequenceOfBoundedCurve::Reverse, "Reverse sequence");
	cls_TColGeom_SequenceOfBoundedCurve.def("Exchange", (void (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_SequenceOfBoundedCurve::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColGeom_SequenceOfBoundedCurve.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_SequenceOfBoundedCurve::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Clear", [](TColGeom_SequenceOfBoundedCurve &self) -> void { return self.Clear(); });
	cls_TColGeom_SequenceOfBoundedCurve.def("Clear", (void (TColGeom_SequenceOfBoundedCurve::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_SequenceOfBoundedCurve::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Assign", (TColGeom_SequenceOfBoundedCurve & (TColGeom_SequenceOfBoundedCurve::*)(const TColGeom_SequenceOfBoundedCurve &)) &TColGeom_SequenceOfBoundedCurve::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColGeom_SequenceOfBoundedCurve.def("assign", (TColGeom_SequenceOfBoundedCurve & (TColGeom_SequenceOfBoundedCurve::*)(const TColGeom_SequenceOfBoundedCurve &)) &TColGeom_SequenceOfBoundedCurve::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Remove", (void (TColGeom_SequenceOfBoundedCurve::*)(TColGeom_SequenceOfBoundedCurve::Iterator &)) &TColGeom_SequenceOfBoundedCurve::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Remove", (void (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer)) &TColGeom_SequenceOfBoundedCurve::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Remove", (void (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_SequenceOfBoundedCurve::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Append", (void (TColGeom_SequenceOfBoundedCurve::*)(const opencascade::handle<Geom_BoundedCurve> &)) &TColGeom_SequenceOfBoundedCurve::Append, "Append one item", py::arg("theItem"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Append", (void (TColGeom_SequenceOfBoundedCurve::*)(TColGeom_SequenceOfBoundedCurve &)) &TColGeom_SequenceOfBoundedCurve::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Prepend", (void (TColGeom_SequenceOfBoundedCurve::*)(const opencascade::handle<Geom_BoundedCurve> &)) &TColGeom_SequenceOfBoundedCurve::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Prepend", (void (TColGeom_SequenceOfBoundedCurve::*)(TColGeom_SequenceOfBoundedCurve &)) &TColGeom_SequenceOfBoundedCurve::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom_SequenceOfBoundedCurve.def("InsertBefore", (void (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer, const opencascade::handle<Geom_BoundedCurve> &)) &TColGeom_SequenceOfBoundedCurve::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_SequenceOfBoundedCurve.def("InsertBefore", (void (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer, TColGeom_SequenceOfBoundedCurve &)) &TColGeom_SequenceOfBoundedCurve::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom_SequenceOfBoundedCurve.def("InsertAfter", (void (TColGeom_SequenceOfBoundedCurve::*)(TColGeom_SequenceOfBoundedCurve::Iterator &, const opencascade::handle<Geom_BoundedCurve> &)) &TColGeom_SequenceOfBoundedCurve::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColGeom_SequenceOfBoundedCurve.def("InsertAfter", (void (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer, TColGeom_SequenceOfBoundedCurve &)) &TColGeom_SequenceOfBoundedCurve::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom_SequenceOfBoundedCurve.def("InsertAfter", (void (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer, const opencascade::handle<Geom_BoundedCurve> &)) &TColGeom_SequenceOfBoundedCurve::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_SequenceOfBoundedCurve.def("Split", (void (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer, TColGeom_SequenceOfBoundedCurve &)) &TColGeom_SequenceOfBoundedCurve::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom_SequenceOfBoundedCurve.def("First", (const opencascade::handle<Geom_BoundedCurve> & (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::First, "First item access");
	cls_TColGeom_SequenceOfBoundedCurve.def("ChangeFirst", (opencascade::handle<Geom_BoundedCurve> & (TColGeom_SequenceOfBoundedCurve::*)()) &TColGeom_SequenceOfBoundedCurve::ChangeFirst, "First item access");
	cls_TColGeom_SequenceOfBoundedCurve.def("Last", (const opencascade::handle<Geom_BoundedCurve> & (TColGeom_SequenceOfBoundedCurve::*)() const ) &TColGeom_SequenceOfBoundedCurve::Last, "Last item access");
	cls_TColGeom_SequenceOfBoundedCurve.def("ChangeLast", (opencascade::handle<Geom_BoundedCurve> & (TColGeom_SequenceOfBoundedCurve::*)()) &TColGeom_SequenceOfBoundedCurve::ChangeLast, "Last item access");
	cls_TColGeom_SequenceOfBoundedCurve.def("Value", (const opencascade::handle<Geom_BoundedCurve> & (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer) const ) &TColGeom_SequenceOfBoundedCurve::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColGeom_SequenceOfBoundedCurve.def("__call__", (const opencascade::handle<Geom_BoundedCurve> & (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer) const ) &TColGeom_SequenceOfBoundedCurve::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColGeom_SequenceOfBoundedCurve.def("ChangeValue", (opencascade::handle<Geom_BoundedCurve> & (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer)) &TColGeom_SequenceOfBoundedCurve::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColGeom_SequenceOfBoundedCurve.def("__call__", (opencascade::handle<Geom_BoundedCurve> & (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer)) &TColGeom_SequenceOfBoundedCurve::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColGeom_SequenceOfBoundedCurve.def("SetValue", (void (TColGeom_SequenceOfBoundedCurve::*)(const Standard_Integer, const opencascade::handle<Geom_BoundedCurve> &)) &TColGeom_SequenceOfBoundedCurve::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_SequenceOfBoundedCurve.def("__iter__", [](const TColGeom_SequenceOfBoundedCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColGeom_Array2OfSurface, std::unique_ptr<TColGeom_Array2OfSurface, Deleter<TColGeom_Array2OfSurface>>> cls_TColGeom_Array2OfSurface(mod, "TColGeom_Array2OfSurface", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColGeom_Array2OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColGeom_Array2OfSurface.def(py::init([] (const TColGeom_Array2OfSurface &other) {return new TColGeom_Array2OfSurface(other);}), "Copy constructor", py::arg("other"));
	cls_TColGeom_Array2OfSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColGeom_Array2OfSurface.def("Init", (void (TColGeom_Array2OfSurface::*)(const opencascade::handle<Geom_Surface> &)) &TColGeom_Array2OfSurface::Init, "Initialise the values", py::arg("theValue"));
	cls_TColGeom_Array2OfSurface.def("Size", (Standard_Integer (TColGeom_Array2OfSurface::*)() const ) &TColGeom_Array2OfSurface::Size, "Size (number of items)");
	cls_TColGeom_Array2OfSurface.def("Length", (Standard_Integer (TColGeom_Array2OfSurface::*)() const ) &TColGeom_Array2OfSurface::Length, "Length (number of items)");
	cls_TColGeom_Array2OfSurface.def("RowLength", (Standard_Integer (TColGeom_Array2OfSurface::*)() const ) &TColGeom_Array2OfSurface::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColGeom_Array2OfSurface.def("ColLength", (Standard_Integer (TColGeom_Array2OfSurface::*)() const ) &TColGeom_Array2OfSurface::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColGeom_Array2OfSurface.def("LowerRow", (Standard_Integer (TColGeom_Array2OfSurface::*)() const ) &TColGeom_Array2OfSurface::LowerRow, "LowerRow");
	cls_TColGeom_Array2OfSurface.def("UpperRow", (Standard_Integer (TColGeom_Array2OfSurface::*)() const ) &TColGeom_Array2OfSurface::UpperRow, "UpperRow");
	cls_TColGeom_Array2OfSurface.def("LowerCol", (Standard_Integer (TColGeom_Array2OfSurface::*)() const ) &TColGeom_Array2OfSurface::LowerCol, "LowerCol");
	cls_TColGeom_Array2OfSurface.def("UpperCol", (Standard_Integer (TColGeom_Array2OfSurface::*)() const ) &TColGeom_Array2OfSurface::UpperCol, "UpperCol");
	cls_TColGeom_Array2OfSurface.def("IsDeletable", (Standard_Boolean (TColGeom_Array2OfSurface::*)() const ) &TColGeom_Array2OfSurface::IsDeletable, "myDeletable flag");
	cls_TColGeom_Array2OfSurface.def("Assign", (TColGeom_Array2OfSurface & (TColGeom_Array2OfSurface::*)(const TColGeom_Array2OfSurface &)) &TColGeom_Array2OfSurface::Assign, "Assignment", py::arg("theOther"));
	cls_TColGeom_Array2OfSurface.def("assign", (TColGeom_Array2OfSurface & (TColGeom_Array2OfSurface::*)(const TColGeom_Array2OfSurface &)) &TColGeom_Array2OfSurface::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColGeom_Array2OfSurface.def("Value", (const opencascade::handle<Geom_Surface> & (TColGeom_Array2OfSurface::*)(const Standard_Integer, const Standard_Integer) const ) &TColGeom_Array2OfSurface::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColGeom_Array2OfSurface.def("__call__", (const opencascade::handle<Geom_Surface> & (TColGeom_Array2OfSurface::*)(const Standard_Integer, const Standard_Integer) const ) &TColGeom_Array2OfSurface::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColGeom_Array2OfSurface.def("ChangeValue", (opencascade::handle<Geom_Surface> & (TColGeom_Array2OfSurface::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_Array2OfSurface::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColGeom_Array2OfSurface.def("__call__", (opencascade::handle<Geom_Surface> & (TColGeom_Array2OfSurface::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_Array2OfSurface::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColGeom_Array2OfSurface.def("SetValue", (void (TColGeom_Array2OfSurface::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<Geom_Surface> &)) &TColGeom_Array2OfSurface::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColGeom_SequenceOfCurve, std::unique_ptr<TColGeom_SequenceOfCurve, Deleter<TColGeom_SequenceOfCurve>>, NCollection_BaseSequence> cls_TColGeom_SequenceOfCurve(mod, "TColGeom_SequenceOfCurve", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColGeom_SequenceOfCurve.def(py::init<>());
	cls_TColGeom_SequenceOfCurve.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColGeom_SequenceOfCurve.def(py::init([] (const TColGeom_SequenceOfCurve &other) {return new TColGeom_SequenceOfCurve(other);}), "Copy constructor", py::arg("other"));
	cls_TColGeom_SequenceOfCurve.def("begin", (TColGeom_SequenceOfCurve::iterator (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColGeom_SequenceOfCurve.def("end", (TColGeom_SequenceOfCurve::iterator (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom_SequenceOfCurve.def("cbegin", (TColGeom_SequenceOfCurve::const_iterator (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColGeom_SequenceOfCurve.def("cend", (TColGeom_SequenceOfCurve::const_iterator (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom_SequenceOfCurve.def("Size", (Standard_Integer (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::Size, "Number of items");
	cls_TColGeom_SequenceOfCurve.def("Length", (Standard_Integer (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::Length, "Number of items");
	cls_TColGeom_SequenceOfCurve.def("Lower", (Standard_Integer (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::Lower, "Method for consistency with other collections.");
	cls_TColGeom_SequenceOfCurve.def("Upper", (Standard_Integer (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::Upper, "Method for consistency with other collections.");
	cls_TColGeom_SequenceOfCurve.def("IsEmpty", (Standard_Boolean (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::IsEmpty, "Empty query");
	cls_TColGeom_SequenceOfCurve.def("Reverse", (void (TColGeom_SequenceOfCurve::*)()) &TColGeom_SequenceOfCurve::Reverse, "Reverse sequence");
	cls_TColGeom_SequenceOfCurve.def("Exchange", (void (TColGeom_SequenceOfCurve::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_SequenceOfCurve::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColGeom_SequenceOfCurve.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_SequenceOfCurve::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColGeom_SequenceOfCurve.def("Clear", [](TColGeom_SequenceOfCurve &self) -> void { return self.Clear(); });
	cls_TColGeom_SequenceOfCurve.def("Clear", (void (TColGeom_SequenceOfCurve::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_SequenceOfCurve::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColGeom_SequenceOfCurve.def("Assign", (TColGeom_SequenceOfCurve & (TColGeom_SequenceOfCurve::*)(const TColGeom_SequenceOfCurve &)) &TColGeom_SequenceOfCurve::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColGeom_SequenceOfCurve.def("assign", (TColGeom_SequenceOfCurve & (TColGeom_SequenceOfCurve::*)(const TColGeom_SequenceOfCurve &)) &TColGeom_SequenceOfCurve::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColGeom_SequenceOfCurve.def("Remove", (void (TColGeom_SequenceOfCurve::*)(TColGeom_SequenceOfCurve::Iterator &)) &TColGeom_SequenceOfCurve::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColGeom_SequenceOfCurve.def("Remove", (void (TColGeom_SequenceOfCurve::*)(const Standard_Integer)) &TColGeom_SequenceOfCurve::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColGeom_SequenceOfCurve.def("Remove", (void (TColGeom_SequenceOfCurve::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_SequenceOfCurve::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColGeom_SequenceOfCurve.def("Append", (void (TColGeom_SequenceOfCurve::*)(const opencascade::handle<Geom_Curve> &)) &TColGeom_SequenceOfCurve::Append, "Append one item", py::arg("theItem"));
	cls_TColGeom_SequenceOfCurve.def("Append", (void (TColGeom_SequenceOfCurve::*)(TColGeom_SequenceOfCurve &)) &TColGeom_SequenceOfCurve::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom_SequenceOfCurve.def("Prepend", (void (TColGeom_SequenceOfCurve::*)(const opencascade::handle<Geom_Curve> &)) &TColGeom_SequenceOfCurve::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColGeom_SequenceOfCurve.def("Prepend", (void (TColGeom_SequenceOfCurve::*)(TColGeom_SequenceOfCurve &)) &TColGeom_SequenceOfCurve::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom_SequenceOfCurve.def("InsertBefore", (void (TColGeom_SequenceOfCurve::*)(const Standard_Integer, const opencascade::handle<Geom_Curve> &)) &TColGeom_SequenceOfCurve::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_SequenceOfCurve.def("InsertBefore", (void (TColGeom_SequenceOfCurve::*)(const Standard_Integer, TColGeom_SequenceOfCurve &)) &TColGeom_SequenceOfCurve::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom_SequenceOfCurve.def("InsertAfter", (void (TColGeom_SequenceOfCurve::*)(TColGeom_SequenceOfCurve::Iterator &, const opencascade::handle<Geom_Curve> &)) &TColGeom_SequenceOfCurve::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColGeom_SequenceOfCurve.def("InsertAfter", (void (TColGeom_SequenceOfCurve::*)(const Standard_Integer, TColGeom_SequenceOfCurve &)) &TColGeom_SequenceOfCurve::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom_SequenceOfCurve.def("InsertAfter", (void (TColGeom_SequenceOfCurve::*)(const Standard_Integer, const opencascade::handle<Geom_Curve> &)) &TColGeom_SequenceOfCurve::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_SequenceOfCurve.def("Split", (void (TColGeom_SequenceOfCurve::*)(const Standard_Integer, TColGeom_SequenceOfCurve &)) &TColGeom_SequenceOfCurve::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom_SequenceOfCurve.def("First", (const opencascade::handle<Geom_Curve> & (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::First, "First item access");
	cls_TColGeom_SequenceOfCurve.def("ChangeFirst", (opencascade::handle<Geom_Curve> & (TColGeom_SequenceOfCurve::*)()) &TColGeom_SequenceOfCurve::ChangeFirst, "First item access");
	cls_TColGeom_SequenceOfCurve.def("Last", (const opencascade::handle<Geom_Curve> & (TColGeom_SequenceOfCurve::*)() const ) &TColGeom_SequenceOfCurve::Last, "Last item access");
	cls_TColGeom_SequenceOfCurve.def("ChangeLast", (opencascade::handle<Geom_Curve> & (TColGeom_SequenceOfCurve::*)()) &TColGeom_SequenceOfCurve::ChangeLast, "Last item access");
	cls_TColGeom_SequenceOfCurve.def("Value", (const opencascade::handle<Geom_Curve> & (TColGeom_SequenceOfCurve::*)(const Standard_Integer) const ) &TColGeom_SequenceOfCurve::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColGeom_SequenceOfCurve.def("__call__", (const opencascade::handle<Geom_Curve> & (TColGeom_SequenceOfCurve::*)(const Standard_Integer) const ) &TColGeom_SequenceOfCurve::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColGeom_SequenceOfCurve.def("ChangeValue", (opencascade::handle<Geom_Curve> & (TColGeom_SequenceOfCurve::*)(const Standard_Integer)) &TColGeom_SequenceOfCurve::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColGeom_SequenceOfCurve.def("__call__", (opencascade::handle<Geom_Curve> & (TColGeom_SequenceOfCurve::*)(const Standard_Integer)) &TColGeom_SequenceOfCurve::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColGeom_SequenceOfCurve.def("SetValue", (void (TColGeom_SequenceOfCurve::*)(const Standard_Integer, const opencascade::handle<Geom_Curve> &)) &TColGeom_SequenceOfCurve::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_SequenceOfCurve.def("__iter__", [](const TColGeom_SequenceOfCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColGeom_Array1OfCurve, std::unique_ptr<TColGeom_Array1OfCurve, Deleter<TColGeom_Array1OfCurve>>> cls_TColGeom_Array1OfCurve(mod, "TColGeom_Array1OfCurve", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColGeom_Array1OfCurve.def(py::init<>());
	cls_TColGeom_Array1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_Array1OfCurve.def(py::init([] (const TColGeom_Array1OfCurve &other) {return new TColGeom_Array1OfCurve(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColGeom_Array1OfCurve.def(py::init<TColGeom_Array1OfCurve &&>(), py::arg("theOther"));
	cls_TColGeom_Array1OfCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_Array1OfCurve.def("begin", (TColGeom_Array1OfCurve::iterator (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColGeom_Array1OfCurve.def("end", (TColGeom_Array1OfCurve::iterator (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColGeom_Array1OfCurve.def("cbegin", (TColGeom_Array1OfCurve::const_iterator (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColGeom_Array1OfCurve.def("cend", (TColGeom_Array1OfCurve::const_iterator (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColGeom_Array1OfCurve.def("Init", (void (TColGeom_Array1OfCurve::*)(const opencascade::handle<Geom_Curve> &)) &TColGeom_Array1OfCurve::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColGeom_Array1OfCurve.def("Size", (Standard_Integer (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::Size, "Size query");
	cls_TColGeom_Array1OfCurve.def("Length", (Standard_Integer (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::Length, "Length query (the same)");
	cls_TColGeom_Array1OfCurve.def("IsEmpty", (Standard_Boolean (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColGeom_Array1OfCurve.def("Lower", (Standard_Integer (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::Lower, "Lower bound");
	cls_TColGeom_Array1OfCurve.def("Upper", (Standard_Integer (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::Upper, "Upper bound");
	cls_TColGeom_Array1OfCurve.def("IsDeletable", (Standard_Boolean (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::IsDeletable, "myDeletable flag");
	cls_TColGeom_Array1OfCurve.def("IsAllocated", (Standard_Boolean (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColGeom_Array1OfCurve.def("Assign", (TColGeom_Array1OfCurve & (TColGeom_Array1OfCurve::*)(const TColGeom_Array1OfCurve &)) &TColGeom_Array1OfCurve::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColGeom_Array1OfCurve.def("Move", (TColGeom_Array1OfCurve & (TColGeom_Array1OfCurve::*)(TColGeom_Array1OfCurve &&)) &TColGeom_Array1OfCurve::Move, "Move assignment", py::arg("theOther"));
	cls_TColGeom_Array1OfCurve.def("assign", (TColGeom_Array1OfCurve & (TColGeom_Array1OfCurve::*)(const TColGeom_Array1OfCurve &)) &TColGeom_Array1OfCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColGeom_Array1OfCurve.def("assign", (TColGeom_Array1OfCurve & (TColGeom_Array1OfCurve::*)(TColGeom_Array1OfCurve &&)) &TColGeom_Array1OfCurve::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColGeom_Array1OfCurve.def("First", (const opencascade::handle<Geom_Curve> & (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::First, "Returns first element");
	cls_TColGeom_Array1OfCurve.def("ChangeFirst", (opencascade::handle<Geom_Curve> & (TColGeom_Array1OfCurve::*)()) &TColGeom_Array1OfCurve::ChangeFirst, "Returns first element");
	cls_TColGeom_Array1OfCurve.def("Last", (const opencascade::handle<Geom_Curve> & (TColGeom_Array1OfCurve::*)() const ) &TColGeom_Array1OfCurve::Last, "Returns last element");
	cls_TColGeom_Array1OfCurve.def("ChangeLast", (opencascade::handle<Geom_Curve> & (TColGeom_Array1OfCurve::*)()) &TColGeom_Array1OfCurve::ChangeLast, "Returns last element");
	cls_TColGeom_Array1OfCurve.def("Value", (const opencascade::handle<Geom_Curve> & (TColGeom_Array1OfCurve::*)(const Standard_Integer) const ) &TColGeom_Array1OfCurve::Value, "Constant value access", py::arg("theIndex"));
	cls_TColGeom_Array1OfCurve.def("__call__", (const opencascade::handle<Geom_Curve> & (TColGeom_Array1OfCurve::*)(const Standard_Integer) const ) &TColGeom_Array1OfCurve::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColGeom_Array1OfCurve.def("ChangeValue", (opencascade::handle<Geom_Curve> & (TColGeom_Array1OfCurve::*)(const Standard_Integer)) &TColGeom_Array1OfCurve::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColGeom_Array1OfCurve.def("__call__", (opencascade::handle<Geom_Curve> & (TColGeom_Array1OfCurve::*)(const Standard_Integer)) &TColGeom_Array1OfCurve::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColGeom_Array1OfCurve.def("SetValue", (void (TColGeom_Array1OfCurve::*)(const Standard_Integer, const opencascade::handle<Geom_Curve> &)) &TColGeom_Array1OfCurve::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_Array1OfCurve.def("Resize", (void (TColGeom_Array1OfCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColGeom_Array1OfCurve::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColGeom_Array1OfCurve.def("__iter__", [](const TColGeom_Array1OfCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColGeom_Array1OfBezierCurve, std::unique_ptr<TColGeom_Array1OfBezierCurve, Deleter<TColGeom_Array1OfBezierCurve>>> cls_TColGeom_Array1OfBezierCurve(mod, "TColGeom_Array1OfBezierCurve", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColGeom_Array1OfBezierCurve.def(py::init<>());
	cls_TColGeom_Array1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_Array1OfBezierCurve.def(py::init([] (const TColGeom_Array1OfBezierCurve &other) {return new TColGeom_Array1OfBezierCurve(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColGeom_Array1OfBezierCurve.def(py::init<TColGeom_Array1OfBezierCurve &&>(), py::arg("theOther"));
	cls_TColGeom_Array1OfBezierCurve.def(py::init<const opencascade::handle<Geom_BezierCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_Array1OfBezierCurve.def("begin", (TColGeom_Array1OfBezierCurve::iterator (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColGeom_Array1OfBezierCurve.def("end", (TColGeom_Array1OfBezierCurve::iterator (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColGeom_Array1OfBezierCurve.def("cbegin", (TColGeom_Array1OfBezierCurve::const_iterator (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColGeom_Array1OfBezierCurve.def("cend", (TColGeom_Array1OfBezierCurve::const_iterator (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColGeom_Array1OfBezierCurve.def("Init", (void (TColGeom_Array1OfBezierCurve::*)(const opencascade::handle<Geom_BezierCurve> &)) &TColGeom_Array1OfBezierCurve::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColGeom_Array1OfBezierCurve.def("Size", (Standard_Integer (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::Size, "Size query");
	cls_TColGeom_Array1OfBezierCurve.def("Length", (Standard_Integer (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::Length, "Length query (the same)");
	cls_TColGeom_Array1OfBezierCurve.def("IsEmpty", (Standard_Boolean (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColGeom_Array1OfBezierCurve.def("Lower", (Standard_Integer (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::Lower, "Lower bound");
	cls_TColGeom_Array1OfBezierCurve.def("Upper", (Standard_Integer (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::Upper, "Upper bound");
	cls_TColGeom_Array1OfBezierCurve.def("IsDeletable", (Standard_Boolean (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::IsDeletable, "myDeletable flag");
	cls_TColGeom_Array1OfBezierCurve.def("IsAllocated", (Standard_Boolean (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColGeom_Array1OfBezierCurve.def("Assign", (TColGeom_Array1OfBezierCurve & (TColGeom_Array1OfBezierCurve::*)(const TColGeom_Array1OfBezierCurve &)) &TColGeom_Array1OfBezierCurve::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColGeom_Array1OfBezierCurve.def("Move", (TColGeom_Array1OfBezierCurve & (TColGeom_Array1OfBezierCurve::*)(TColGeom_Array1OfBezierCurve &&)) &TColGeom_Array1OfBezierCurve::Move, "Move assignment", py::arg("theOther"));
	cls_TColGeom_Array1OfBezierCurve.def("assign", (TColGeom_Array1OfBezierCurve & (TColGeom_Array1OfBezierCurve::*)(const TColGeom_Array1OfBezierCurve &)) &TColGeom_Array1OfBezierCurve::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColGeom_Array1OfBezierCurve.def("assign", (TColGeom_Array1OfBezierCurve & (TColGeom_Array1OfBezierCurve::*)(TColGeom_Array1OfBezierCurve &&)) &TColGeom_Array1OfBezierCurve::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColGeom_Array1OfBezierCurve.def("First", (const opencascade::handle<Geom_BezierCurve> & (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::First, "Returns first element");
	cls_TColGeom_Array1OfBezierCurve.def("ChangeFirst", (opencascade::handle<Geom_BezierCurve> & (TColGeom_Array1OfBezierCurve::*)()) &TColGeom_Array1OfBezierCurve::ChangeFirst, "Returns first element");
	cls_TColGeom_Array1OfBezierCurve.def("Last", (const opencascade::handle<Geom_BezierCurve> & (TColGeom_Array1OfBezierCurve::*)() const ) &TColGeom_Array1OfBezierCurve::Last, "Returns last element");
	cls_TColGeom_Array1OfBezierCurve.def("ChangeLast", (opencascade::handle<Geom_BezierCurve> & (TColGeom_Array1OfBezierCurve::*)()) &TColGeom_Array1OfBezierCurve::ChangeLast, "Returns last element");
	cls_TColGeom_Array1OfBezierCurve.def("Value", (const opencascade::handle<Geom_BezierCurve> & (TColGeom_Array1OfBezierCurve::*)(const Standard_Integer) const ) &TColGeom_Array1OfBezierCurve::Value, "Constant value access", py::arg("theIndex"));
	cls_TColGeom_Array1OfBezierCurve.def("__call__", (const opencascade::handle<Geom_BezierCurve> & (TColGeom_Array1OfBezierCurve::*)(const Standard_Integer) const ) &TColGeom_Array1OfBezierCurve::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColGeom_Array1OfBezierCurve.def("ChangeValue", (opencascade::handle<Geom_BezierCurve> & (TColGeom_Array1OfBezierCurve::*)(const Standard_Integer)) &TColGeom_Array1OfBezierCurve::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColGeom_Array1OfBezierCurve.def("__call__", (opencascade::handle<Geom_BezierCurve> & (TColGeom_Array1OfBezierCurve::*)(const Standard_Integer)) &TColGeom_Array1OfBezierCurve::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColGeom_Array1OfBezierCurve.def("SetValue", (void (TColGeom_Array1OfBezierCurve::*)(const Standard_Integer, const opencascade::handle<Geom_BezierCurve> &)) &TColGeom_Array1OfBezierCurve::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_Array1OfBezierCurve.def("Resize", (void (TColGeom_Array1OfBezierCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColGeom_Array1OfBezierCurve::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColGeom_Array1OfBezierCurve.def("__iter__", [](const TColGeom_Array1OfBezierCurve &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray1OfSurface.hxx
	py::class_<TColGeom_HArray1OfSurface, opencascade::handle<TColGeom_HArray1OfSurface>, TColGeom_Array1OfSurface, Standard_Transient> cls_TColGeom_HArray1OfSurface(mod, "TColGeom_HArray1OfSurface", "None");
	cls_TColGeom_HArray1OfSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_HArray1OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfSurface::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom_HArray1OfSurface.def(py::init<const TColGeom_Array1OfSurface &>(), py::arg("theOther"));
	cls_TColGeom_HArray1OfSurface.def("Array1", (const TColGeom_Array1OfSurface & (TColGeom_HArray1OfSurface::*)() const ) &TColGeom_HArray1OfSurface::Array1, "None");
	cls_TColGeom_HArray1OfSurface.def("ChangeArray1", (TColGeom_Array1OfSurface & (TColGeom_HArray1OfSurface::*)()) &TColGeom_HArray1OfSurface::ChangeArray1, "None");
	cls_TColGeom_HArray1OfSurface.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfSurface::get_type_name, "None");
	cls_TColGeom_HArray1OfSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfSurface::get_type_descriptor, "None");
	cls_TColGeom_HArray1OfSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfSurface::*)() const ) &TColGeom_HArray1OfSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HSequenceOfCurve.hxx
	py::class_<TColGeom_HSequenceOfCurve, opencascade::handle<TColGeom_HSequenceOfCurve>, TColGeom_SequenceOfCurve, Standard_Transient> cls_TColGeom_HSequenceOfCurve(mod, "TColGeom_HSequenceOfCurve", "None");
	cls_TColGeom_HSequenceOfCurve.def(py::init<>());
	cls_TColGeom_HSequenceOfCurve.def(py::init<const TColGeom_SequenceOfCurve &>(), py::arg("theOther"));
	cls_TColGeom_HSequenceOfCurve.def("Sequence", (const TColGeom_SequenceOfCurve & (TColGeom_HSequenceOfCurve::*)() const ) &TColGeom_HSequenceOfCurve::Sequence, "None");
	cls_TColGeom_HSequenceOfCurve.def("Append", (void (TColGeom_HSequenceOfCurve::*)(const TColGeom_SequenceOfCurve::value_type &)) &TColGeom_HSequenceOfCurve::Append, "None", py::arg("theItem"));
	cls_TColGeom_HSequenceOfCurve.def("Append", (void (TColGeom_HSequenceOfCurve::*)(TColGeom_SequenceOfCurve &)) &TColGeom_HSequenceOfCurve::Append, "None", py::arg("theSequence"));
	cls_TColGeom_HSequenceOfCurve.def("ChangeSequence", (TColGeom_SequenceOfCurve & (TColGeom_HSequenceOfCurve::*)()) &TColGeom_HSequenceOfCurve::ChangeSequence, "None");
	cls_TColGeom_HSequenceOfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HSequenceOfCurve::get_type_name, "None");
	cls_TColGeom_HSequenceOfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HSequenceOfCurve::get_type_descriptor, "None");
	cls_TColGeom_HSequenceOfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HSequenceOfCurve::*)() const ) &TColGeom_HSequenceOfCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray1OfBSplineCurve.hxx
	py::class_<TColGeom_HArray1OfBSplineCurve, opencascade::handle<TColGeom_HArray1OfBSplineCurve>, TColGeom_Array1OfBSplineCurve, Standard_Transient> cls_TColGeom_HArray1OfBSplineCurve(mod, "TColGeom_HArray1OfBSplineCurve", "None");
	cls_TColGeom_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfBSplineCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom_HArray1OfBSplineCurve.def(py::init<const TColGeom_Array1OfBSplineCurve &>(), py::arg("theOther"));
	cls_TColGeom_HArray1OfBSplineCurve.def("Array1", (const TColGeom_Array1OfBSplineCurve & (TColGeom_HArray1OfBSplineCurve::*)() const ) &TColGeom_HArray1OfBSplineCurve::Array1, "None");
	cls_TColGeom_HArray1OfBSplineCurve.def("ChangeArray1", (TColGeom_Array1OfBSplineCurve & (TColGeom_HArray1OfBSplineCurve::*)()) &TColGeom_HArray1OfBSplineCurve::ChangeArray1, "None");
	cls_TColGeom_HArray1OfBSplineCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfBSplineCurve::get_type_name, "None");
	cls_TColGeom_HArray1OfBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfBSplineCurve::get_type_descriptor, "None");
	cls_TColGeom_HArray1OfBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfBSplineCurve::*)() const ) &TColGeom_HArray1OfBSplineCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray1OfBezierCurve.hxx
	py::class_<TColGeom_HArray1OfBezierCurve, opencascade::handle<TColGeom_HArray1OfBezierCurve>, TColGeom_Array1OfBezierCurve, Standard_Transient> cls_TColGeom_HArray1OfBezierCurve(mod, "TColGeom_HArray1OfBezierCurve", "None");
	cls_TColGeom_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfBezierCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom_HArray1OfBezierCurve.def(py::init<const TColGeom_Array1OfBezierCurve &>(), py::arg("theOther"));
	cls_TColGeom_HArray1OfBezierCurve.def("Array1", (const TColGeom_Array1OfBezierCurve & (TColGeom_HArray1OfBezierCurve::*)() const ) &TColGeom_HArray1OfBezierCurve::Array1, "None");
	cls_TColGeom_HArray1OfBezierCurve.def("ChangeArray1", (TColGeom_Array1OfBezierCurve & (TColGeom_HArray1OfBezierCurve::*)()) &TColGeom_HArray1OfBezierCurve::ChangeArray1, "None");
	cls_TColGeom_HArray1OfBezierCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfBezierCurve::get_type_name, "None");
	cls_TColGeom_HArray1OfBezierCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfBezierCurve::get_type_descriptor, "None");
	cls_TColGeom_HArray1OfBezierCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfBezierCurve::*)() const ) &TColGeom_HArray1OfBezierCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColGeom_Array2OfBezierSurface, std::unique_ptr<TColGeom_Array2OfBezierSurface, Deleter<TColGeom_Array2OfBezierSurface>>> cls_TColGeom_Array2OfBezierSurface(mod, "TColGeom_Array2OfBezierSurface", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColGeom_Array2OfBezierSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColGeom_Array2OfBezierSurface.def(py::init([] (const TColGeom_Array2OfBezierSurface &other) {return new TColGeom_Array2OfBezierSurface(other);}), "Copy constructor", py::arg("other"));
	cls_TColGeom_Array2OfBezierSurface.def(py::init<const opencascade::handle<Geom_BezierSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColGeom_Array2OfBezierSurface.def("Init", (void (TColGeom_Array2OfBezierSurface::*)(const opencascade::handle<Geom_BezierSurface> &)) &TColGeom_Array2OfBezierSurface::Init, "Initialise the values", py::arg("theValue"));
	cls_TColGeom_Array2OfBezierSurface.def("Size", (Standard_Integer (TColGeom_Array2OfBezierSurface::*)() const ) &TColGeom_Array2OfBezierSurface::Size, "Size (number of items)");
	cls_TColGeom_Array2OfBezierSurface.def("Length", (Standard_Integer (TColGeom_Array2OfBezierSurface::*)() const ) &TColGeom_Array2OfBezierSurface::Length, "Length (number of items)");
	cls_TColGeom_Array2OfBezierSurface.def("RowLength", (Standard_Integer (TColGeom_Array2OfBezierSurface::*)() const ) &TColGeom_Array2OfBezierSurface::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColGeom_Array2OfBezierSurface.def("ColLength", (Standard_Integer (TColGeom_Array2OfBezierSurface::*)() const ) &TColGeom_Array2OfBezierSurface::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColGeom_Array2OfBezierSurface.def("LowerRow", (Standard_Integer (TColGeom_Array2OfBezierSurface::*)() const ) &TColGeom_Array2OfBezierSurface::LowerRow, "LowerRow");
	cls_TColGeom_Array2OfBezierSurface.def("UpperRow", (Standard_Integer (TColGeom_Array2OfBezierSurface::*)() const ) &TColGeom_Array2OfBezierSurface::UpperRow, "UpperRow");
	cls_TColGeom_Array2OfBezierSurface.def("LowerCol", (Standard_Integer (TColGeom_Array2OfBezierSurface::*)() const ) &TColGeom_Array2OfBezierSurface::LowerCol, "LowerCol");
	cls_TColGeom_Array2OfBezierSurface.def("UpperCol", (Standard_Integer (TColGeom_Array2OfBezierSurface::*)() const ) &TColGeom_Array2OfBezierSurface::UpperCol, "UpperCol");
	cls_TColGeom_Array2OfBezierSurface.def("IsDeletable", (Standard_Boolean (TColGeom_Array2OfBezierSurface::*)() const ) &TColGeom_Array2OfBezierSurface::IsDeletable, "myDeletable flag");
	cls_TColGeom_Array2OfBezierSurface.def("Assign", (TColGeom_Array2OfBezierSurface & (TColGeom_Array2OfBezierSurface::*)(const TColGeom_Array2OfBezierSurface &)) &TColGeom_Array2OfBezierSurface::Assign, "Assignment", py::arg("theOther"));
	cls_TColGeom_Array2OfBezierSurface.def("assign", (TColGeom_Array2OfBezierSurface & (TColGeom_Array2OfBezierSurface::*)(const TColGeom_Array2OfBezierSurface &)) &TColGeom_Array2OfBezierSurface::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColGeom_Array2OfBezierSurface.def("Value", (const opencascade::handle<Geom_BezierSurface> & (TColGeom_Array2OfBezierSurface::*)(const Standard_Integer, const Standard_Integer) const ) &TColGeom_Array2OfBezierSurface::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColGeom_Array2OfBezierSurface.def("__call__", (const opencascade::handle<Geom_BezierSurface> & (TColGeom_Array2OfBezierSurface::*)(const Standard_Integer, const Standard_Integer) const ) &TColGeom_Array2OfBezierSurface::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColGeom_Array2OfBezierSurface.def("ChangeValue", (opencascade::handle<Geom_BezierSurface> & (TColGeom_Array2OfBezierSurface::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_Array2OfBezierSurface::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColGeom_Array2OfBezierSurface.def("__call__", (opencascade::handle<Geom_BezierSurface> & (TColGeom_Array2OfBezierSurface::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_Array2OfBezierSurface::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColGeom_Array2OfBezierSurface.def("SetValue", (void (TColGeom_Array2OfBezierSurface::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<Geom_BezierSurface> &)) &TColGeom_Array2OfBezierSurface::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HSequenceOfBoundedCurve.hxx
	py::class_<TColGeom_HSequenceOfBoundedCurve, opencascade::handle<TColGeom_HSequenceOfBoundedCurve>, TColGeom_SequenceOfBoundedCurve, Standard_Transient> cls_TColGeom_HSequenceOfBoundedCurve(mod, "TColGeom_HSequenceOfBoundedCurve", "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def(py::init<>());
	cls_TColGeom_HSequenceOfBoundedCurve.def(py::init<const TColGeom_SequenceOfBoundedCurve &>(), py::arg("theOther"));
	cls_TColGeom_HSequenceOfBoundedCurve.def("Sequence", (const TColGeom_SequenceOfBoundedCurve & (TColGeom_HSequenceOfBoundedCurve::*)() const ) &TColGeom_HSequenceOfBoundedCurve::Sequence, "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def("Append", (void (TColGeom_HSequenceOfBoundedCurve::*)(const TColGeom_SequenceOfBoundedCurve::value_type &)) &TColGeom_HSequenceOfBoundedCurve::Append, "None", py::arg("theItem"));
	cls_TColGeom_HSequenceOfBoundedCurve.def("Append", (void (TColGeom_HSequenceOfBoundedCurve::*)(TColGeom_SequenceOfBoundedCurve &)) &TColGeom_HSequenceOfBoundedCurve::Append, "None", py::arg("theSequence"));
	cls_TColGeom_HSequenceOfBoundedCurve.def("ChangeSequence", (TColGeom_SequenceOfBoundedCurve & (TColGeom_HSequenceOfBoundedCurve::*)()) &TColGeom_HSequenceOfBoundedCurve::ChangeSequence, "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HSequenceOfBoundedCurve::get_type_name, "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HSequenceOfBoundedCurve::get_type_descriptor, "None");
	cls_TColGeom_HSequenceOfBoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HSequenceOfBoundedCurve::*)() const ) &TColGeom_HSequenceOfBoundedCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray2OfSurface.hxx
	py::class_<TColGeom_HArray2OfSurface, opencascade::handle<TColGeom_HArray2OfSurface>, TColGeom_Array2OfSurface, Standard_Transient> cls_TColGeom_HArray2OfSurface(mod, "TColGeom_HArray2OfSurface", "None");
	cls_TColGeom_HArray2OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColGeom_HArray2OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColGeom_Array2OfSurface::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColGeom_HArray2OfSurface.def(py::init<const TColGeom_Array2OfSurface &>(), py::arg("theOther"));
	cls_TColGeom_HArray2OfSurface.def("Array2", (const TColGeom_Array2OfSurface & (TColGeom_HArray2OfSurface::*)() const ) &TColGeom_HArray2OfSurface::Array2, "None");
	cls_TColGeom_HArray2OfSurface.def("ChangeArray2", (TColGeom_Array2OfSurface & (TColGeom_HArray2OfSurface::*)()) &TColGeom_HArray2OfSurface::ChangeArray2, "None");
	cls_TColGeom_HArray2OfSurface.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray2OfSurface::get_type_name, "None");
	cls_TColGeom_HArray2OfSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray2OfSurface::get_type_descriptor, "None");
	cls_TColGeom_HArray2OfSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray2OfSurface::*)() const ) &TColGeom_HArray2OfSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColGeom_HArray1OfCurve.hxx
	py::class_<TColGeom_HArray1OfCurve, opencascade::handle<TColGeom_HArray1OfCurve>, TColGeom_Array1OfCurve, Standard_Transient> cls_TColGeom_HArray1OfCurve(mod, "TColGeom_HArray1OfCurve", "None");
	cls_TColGeom_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColGeom_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColGeom_HArray1OfCurve.def(py::init<const TColGeom_Array1OfCurve &>(), py::arg("theOther"));
	cls_TColGeom_HArray1OfCurve.def("Array1", (const TColGeom_Array1OfCurve & (TColGeom_HArray1OfCurve::*)() const ) &TColGeom_HArray1OfCurve::Array1, "None");
	cls_TColGeom_HArray1OfCurve.def("ChangeArray1", (TColGeom_Array1OfCurve & (TColGeom_HArray1OfCurve::*)()) &TColGeom_HArray1OfCurve::ChangeArray1, "None");
	cls_TColGeom_HArray1OfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfCurve::get_type_name, "None");
	cls_TColGeom_HArray1OfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfCurve::get_type_descriptor, "None");
	cls_TColGeom_HArray1OfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfCurve::*)() const ) &TColGeom_HArray1OfCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColGeom_SequenceOfSurface, std::unique_ptr<TColGeom_SequenceOfSurface, Deleter<TColGeom_SequenceOfSurface>>, NCollection_BaseSequence> cls_TColGeom_SequenceOfSurface(mod, "TColGeom_SequenceOfSurface", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColGeom_SequenceOfSurface.def(py::init<>());
	cls_TColGeom_SequenceOfSurface.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColGeom_SequenceOfSurface.def(py::init([] (const TColGeom_SequenceOfSurface &other) {return new TColGeom_SequenceOfSurface(other);}), "Copy constructor", py::arg("other"));
	cls_TColGeom_SequenceOfSurface.def("begin", (TColGeom_SequenceOfSurface::iterator (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColGeom_SequenceOfSurface.def("end", (TColGeom_SequenceOfSurface::iterator (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom_SequenceOfSurface.def("cbegin", (TColGeom_SequenceOfSurface::const_iterator (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColGeom_SequenceOfSurface.def("cend", (TColGeom_SequenceOfSurface::const_iterator (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColGeom_SequenceOfSurface.def("Size", (Standard_Integer (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::Size, "Number of items");
	cls_TColGeom_SequenceOfSurface.def("Length", (Standard_Integer (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::Length, "Number of items");
	cls_TColGeom_SequenceOfSurface.def("Lower", (Standard_Integer (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::Lower, "Method for consistency with other collections.");
	cls_TColGeom_SequenceOfSurface.def("Upper", (Standard_Integer (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::Upper, "Method for consistency with other collections.");
	cls_TColGeom_SequenceOfSurface.def("IsEmpty", (Standard_Boolean (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::IsEmpty, "Empty query");
	cls_TColGeom_SequenceOfSurface.def("Reverse", (void (TColGeom_SequenceOfSurface::*)()) &TColGeom_SequenceOfSurface::Reverse, "Reverse sequence");
	cls_TColGeom_SequenceOfSurface.def("Exchange", (void (TColGeom_SequenceOfSurface::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_SequenceOfSurface::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColGeom_SequenceOfSurface.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_SequenceOfSurface::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColGeom_SequenceOfSurface.def("Clear", [](TColGeom_SequenceOfSurface &self) -> void { return self.Clear(); });
	cls_TColGeom_SequenceOfSurface.def("Clear", (void (TColGeom_SequenceOfSurface::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_SequenceOfSurface::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColGeom_SequenceOfSurface.def("Assign", (TColGeom_SequenceOfSurface & (TColGeom_SequenceOfSurface::*)(const TColGeom_SequenceOfSurface &)) &TColGeom_SequenceOfSurface::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColGeom_SequenceOfSurface.def("assign", (TColGeom_SequenceOfSurface & (TColGeom_SequenceOfSurface::*)(const TColGeom_SequenceOfSurface &)) &TColGeom_SequenceOfSurface::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColGeom_SequenceOfSurface.def("Remove", (void (TColGeom_SequenceOfSurface::*)(TColGeom_SequenceOfSurface::Iterator &)) &TColGeom_SequenceOfSurface::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColGeom_SequenceOfSurface.def("Remove", (void (TColGeom_SequenceOfSurface::*)(const Standard_Integer)) &TColGeom_SequenceOfSurface::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColGeom_SequenceOfSurface.def("Remove", (void (TColGeom_SequenceOfSurface::*)(const Standard_Integer, const Standard_Integer)) &TColGeom_SequenceOfSurface::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColGeom_SequenceOfSurface.def("Append", (void (TColGeom_SequenceOfSurface::*)(const opencascade::handle<Geom_Surface> &)) &TColGeom_SequenceOfSurface::Append, "Append one item", py::arg("theItem"));
	cls_TColGeom_SequenceOfSurface.def("Append", (void (TColGeom_SequenceOfSurface::*)(TColGeom_SequenceOfSurface &)) &TColGeom_SequenceOfSurface::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom_SequenceOfSurface.def("Prepend", (void (TColGeom_SequenceOfSurface::*)(const opencascade::handle<Geom_Surface> &)) &TColGeom_SequenceOfSurface::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColGeom_SequenceOfSurface.def("Prepend", (void (TColGeom_SequenceOfSurface::*)(TColGeom_SequenceOfSurface &)) &TColGeom_SequenceOfSurface::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColGeom_SequenceOfSurface.def("InsertBefore", (void (TColGeom_SequenceOfSurface::*)(const Standard_Integer, const opencascade::handle<Geom_Surface> &)) &TColGeom_SequenceOfSurface::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_SequenceOfSurface.def("InsertBefore", (void (TColGeom_SequenceOfSurface::*)(const Standard_Integer, TColGeom_SequenceOfSurface &)) &TColGeom_SequenceOfSurface::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom_SequenceOfSurface.def("InsertAfter", (void (TColGeom_SequenceOfSurface::*)(TColGeom_SequenceOfSurface::Iterator &, const opencascade::handle<Geom_Surface> &)) &TColGeom_SequenceOfSurface::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColGeom_SequenceOfSurface.def("InsertAfter", (void (TColGeom_SequenceOfSurface::*)(const Standard_Integer, TColGeom_SequenceOfSurface &)) &TColGeom_SequenceOfSurface::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom_SequenceOfSurface.def("InsertAfter", (void (TColGeom_SequenceOfSurface::*)(const Standard_Integer, const opencascade::handle<Geom_Surface> &)) &TColGeom_SequenceOfSurface::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_SequenceOfSurface.def("Split", (void (TColGeom_SequenceOfSurface::*)(const Standard_Integer, TColGeom_SequenceOfSurface &)) &TColGeom_SequenceOfSurface::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColGeom_SequenceOfSurface.def("First", (const opencascade::handle<Geom_Surface> & (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::First, "First item access");
	cls_TColGeom_SequenceOfSurface.def("ChangeFirst", (opencascade::handle<Geom_Surface> & (TColGeom_SequenceOfSurface::*)()) &TColGeom_SequenceOfSurface::ChangeFirst, "First item access");
	cls_TColGeom_SequenceOfSurface.def("Last", (const opencascade::handle<Geom_Surface> & (TColGeom_SequenceOfSurface::*)() const ) &TColGeom_SequenceOfSurface::Last, "Last item access");
	cls_TColGeom_SequenceOfSurface.def("ChangeLast", (opencascade::handle<Geom_Surface> & (TColGeom_SequenceOfSurface::*)()) &TColGeom_SequenceOfSurface::ChangeLast, "Last item access");
	cls_TColGeom_SequenceOfSurface.def("Value", (const opencascade::handle<Geom_Surface> & (TColGeom_SequenceOfSurface::*)(const Standard_Integer) const ) &TColGeom_SequenceOfSurface::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColGeom_SequenceOfSurface.def("__call__", (const opencascade::handle<Geom_Surface> & (TColGeom_SequenceOfSurface::*)(const Standard_Integer) const ) &TColGeom_SequenceOfSurface::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColGeom_SequenceOfSurface.def("ChangeValue", (opencascade::handle<Geom_Surface> & (TColGeom_SequenceOfSurface::*)(const Standard_Integer)) &TColGeom_SequenceOfSurface::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColGeom_SequenceOfSurface.def("__call__", (opencascade::handle<Geom_Surface> & (TColGeom_SequenceOfSurface::*)(const Standard_Integer)) &TColGeom_SequenceOfSurface::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColGeom_SequenceOfSurface.def("SetValue", (void (TColGeom_SequenceOfSurface::*)(const Standard_Integer, const opencascade::handle<Geom_Surface> &)) &TColGeom_SequenceOfSurface::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColGeom_SequenceOfSurface.def("__iter__", [](const TColGeom_SequenceOfSurface &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
