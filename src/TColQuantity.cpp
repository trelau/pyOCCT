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
#include <TColQuantity_Array1OfLength.hxx>
#include <NCollection_Array2.hxx>
#include <TColQuantity_Array2OfLength.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TColQuantity_HArray1OfLength.hxx>
#include <TColQuantity_HArray2OfLength.hxx>

PYBIND11_MODULE(TColQuantity, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColQuantity_Array1OfLength, std::unique_ptr<TColQuantity_Array1OfLength, Deleter<TColQuantity_Array1OfLength>>> cls_TColQuantity_Array1OfLength(mod, "TColQuantity_Array1OfLength", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColQuantity_Array1OfLength.def(py::init<>());
	cls_TColQuantity_Array1OfLength.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColQuantity_Array1OfLength.def(py::init([] (const TColQuantity_Array1OfLength &other) {return new TColQuantity_Array1OfLength(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColQuantity_Array1OfLength.def(py::init<TColQuantity_Array1OfLength &&>(), py::arg("theOther"));
	cls_TColQuantity_Array1OfLength.def(py::init<const Quantity_Length &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColQuantity_Array1OfLength.def("begin", (TColQuantity_Array1OfLength::iterator (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColQuantity_Array1OfLength.def("end", (TColQuantity_Array1OfLength::iterator (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColQuantity_Array1OfLength.def("cbegin", (TColQuantity_Array1OfLength::const_iterator (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColQuantity_Array1OfLength.def("cend", (TColQuantity_Array1OfLength::const_iterator (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColQuantity_Array1OfLength.def("Init", (void (TColQuantity_Array1OfLength::*)(const Quantity_Length &)) &TColQuantity_Array1OfLength::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColQuantity_Array1OfLength.def("Size", (Standard_Integer (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::Size, "Size query");
	cls_TColQuantity_Array1OfLength.def("Length", (Standard_Integer (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::Length, "Length query (the same)");
	cls_TColQuantity_Array1OfLength.def("IsEmpty", (Standard_Boolean (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColQuantity_Array1OfLength.def("Lower", (Standard_Integer (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::Lower, "Lower bound");
	cls_TColQuantity_Array1OfLength.def("Upper", (Standard_Integer (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::Upper, "Upper bound");
	cls_TColQuantity_Array1OfLength.def("IsDeletable", (Standard_Boolean (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::IsDeletable, "myDeletable flag");
	cls_TColQuantity_Array1OfLength.def("IsAllocated", (Standard_Boolean (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColQuantity_Array1OfLength.def("Assign", (TColQuantity_Array1OfLength & (TColQuantity_Array1OfLength::*)(const TColQuantity_Array1OfLength &)) &TColQuantity_Array1OfLength::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColQuantity_Array1OfLength.def("Move", (TColQuantity_Array1OfLength & (TColQuantity_Array1OfLength::*)(TColQuantity_Array1OfLength &&)) &TColQuantity_Array1OfLength::Move, "Move assignment", py::arg("theOther"));
	cls_TColQuantity_Array1OfLength.def("assign", (TColQuantity_Array1OfLength & (TColQuantity_Array1OfLength::*)(const TColQuantity_Array1OfLength &)) &TColQuantity_Array1OfLength::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColQuantity_Array1OfLength.def("assign", (TColQuantity_Array1OfLength & (TColQuantity_Array1OfLength::*)(TColQuantity_Array1OfLength &&)) &TColQuantity_Array1OfLength::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColQuantity_Array1OfLength.def("First", (const Quantity_Length & (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::First, "Returns first element");
	cls_TColQuantity_Array1OfLength.def("ChangeFirst", (Quantity_Length & (TColQuantity_Array1OfLength::*)()) &TColQuantity_Array1OfLength::ChangeFirst, "Returns first element");
	cls_TColQuantity_Array1OfLength.def("Last", (const Quantity_Length & (TColQuantity_Array1OfLength::*)() const ) &TColQuantity_Array1OfLength::Last, "Returns last element");
	cls_TColQuantity_Array1OfLength.def("ChangeLast", (Quantity_Length & (TColQuantity_Array1OfLength::*)()) &TColQuantity_Array1OfLength::ChangeLast, "Returns last element");
	cls_TColQuantity_Array1OfLength.def("Value", (const Quantity_Length & (TColQuantity_Array1OfLength::*)(const Standard_Integer) const ) &TColQuantity_Array1OfLength::Value, "Constant value access", py::arg("theIndex"));
	cls_TColQuantity_Array1OfLength.def("__call__", (const Quantity_Length & (TColQuantity_Array1OfLength::*)(const Standard_Integer) const ) &TColQuantity_Array1OfLength::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColQuantity_Array1OfLength.def("ChangeValue", (Quantity_Length & (TColQuantity_Array1OfLength::*)(const Standard_Integer)) &TColQuantity_Array1OfLength::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColQuantity_Array1OfLength.def("__call__", (Quantity_Length & (TColQuantity_Array1OfLength::*)(const Standard_Integer)) &TColQuantity_Array1OfLength::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColQuantity_Array1OfLength.def("SetValue", (void (TColQuantity_Array1OfLength::*)(const Standard_Integer, const Quantity_Length &)) &TColQuantity_Array1OfLength::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColQuantity_Array1OfLength.def("Resize", (void (TColQuantity_Array1OfLength::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColQuantity_Array1OfLength::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColQuantity_Array1OfLength.def("__iter__", [](const TColQuantity_Array1OfLength &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColQuantity_Array2OfLength, std::unique_ptr<TColQuantity_Array2OfLength, Deleter<TColQuantity_Array2OfLength>>> cls_TColQuantity_Array2OfLength(mod, "TColQuantity_Array2OfLength", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColQuantity_Array2OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColQuantity_Array2OfLength.def(py::init([] (const TColQuantity_Array2OfLength &other) {return new TColQuantity_Array2OfLength(other);}), "Copy constructor", py::arg("other"));
	cls_TColQuantity_Array2OfLength.def(py::init<const Quantity_Length &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColQuantity_Array2OfLength.def("Init", (void (TColQuantity_Array2OfLength::*)(const Quantity_Length &)) &TColQuantity_Array2OfLength::Init, "Initialise the values", py::arg("theValue"));
	cls_TColQuantity_Array2OfLength.def("Size", (Standard_Integer (TColQuantity_Array2OfLength::*)() const ) &TColQuantity_Array2OfLength::Size, "Size (number of items)");
	cls_TColQuantity_Array2OfLength.def("Length", (Standard_Integer (TColQuantity_Array2OfLength::*)() const ) &TColQuantity_Array2OfLength::Length, "Length (number of items)");
	cls_TColQuantity_Array2OfLength.def("RowLength", (Standard_Integer (TColQuantity_Array2OfLength::*)() const ) &TColQuantity_Array2OfLength::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColQuantity_Array2OfLength.def("ColLength", (Standard_Integer (TColQuantity_Array2OfLength::*)() const ) &TColQuantity_Array2OfLength::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColQuantity_Array2OfLength.def("LowerRow", (Standard_Integer (TColQuantity_Array2OfLength::*)() const ) &TColQuantity_Array2OfLength::LowerRow, "LowerRow");
	cls_TColQuantity_Array2OfLength.def("UpperRow", (Standard_Integer (TColQuantity_Array2OfLength::*)() const ) &TColQuantity_Array2OfLength::UpperRow, "UpperRow");
	cls_TColQuantity_Array2OfLength.def("LowerCol", (Standard_Integer (TColQuantity_Array2OfLength::*)() const ) &TColQuantity_Array2OfLength::LowerCol, "LowerCol");
	cls_TColQuantity_Array2OfLength.def("UpperCol", (Standard_Integer (TColQuantity_Array2OfLength::*)() const ) &TColQuantity_Array2OfLength::UpperCol, "UpperCol");
	cls_TColQuantity_Array2OfLength.def("IsDeletable", (Standard_Boolean (TColQuantity_Array2OfLength::*)() const ) &TColQuantity_Array2OfLength::IsDeletable, "myDeletable flag");
	cls_TColQuantity_Array2OfLength.def("Assign", (TColQuantity_Array2OfLength & (TColQuantity_Array2OfLength::*)(const TColQuantity_Array2OfLength &)) &TColQuantity_Array2OfLength::Assign, "Assignment", py::arg("theOther"));
	cls_TColQuantity_Array2OfLength.def("assign", (TColQuantity_Array2OfLength & (TColQuantity_Array2OfLength::*)(const TColQuantity_Array2OfLength &)) &TColQuantity_Array2OfLength::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColQuantity_Array2OfLength.def("Value", (const Quantity_Length & (TColQuantity_Array2OfLength::*)(const Standard_Integer, const Standard_Integer) const ) &TColQuantity_Array2OfLength::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColQuantity_Array2OfLength.def("__call__", (const Quantity_Length & (TColQuantity_Array2OfLength::*)(const Standard_Integer, const Standard_Integer) const ) &TColQuantity_Array2OfLength::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColQuantity_Array2OfLength.def("ChangeValue", (Quantity_Length & (TColQuantity_Array2OfLength::*)(const Standard_Integer, const Standard_Integer)) &TColQuantity_Array2OfLength::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColQuantity_Array2OfLength.def("__call__", (Quantity_Length & (TColQuantity_Array2OfLength::*)(const Standard_Integer, const Standard_Integer)) &TColQuantity_Array2OfLength::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColQuantity_Array2OfLength.def("SetValue", (void (TColQuantity_Array2OfLength::*)(const Standard_Integer, const Standard_Integer, const Quantity_Length &)) &TColQuantity_Array2OfLength::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColQuantity_HArray1OfLength.hxx
	py::class_<TColQuantity_HArray1OfLength, opencascade::handle<TColQuantity_HArray1OfLength>, TColQuantity_Array1OfLength, Standard_Transient> cls_TColQuantity_HArray1OfLength(mod, "TColQuantity_HArray1OfLength", "None");
	cls_TColQuantity_HArray1OfLength.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColQuantity_HArray1OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const TColQuantity_Array1OfLength::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColQuantity_HArray1OfLength.def(py::init<const TColQuantity_Array1OfLength &>(), py::arg("theOther"));
	cls_TColQuantity_HArray1OfLength.def("Array1", (const TColQuantity_Array1OfLength & (TColQuantity_HArray1OfLength::*)() const ) &TColQuantity_HArray1OfLength::Array1, "None");
	cls_TColQuantity_HArray1OfLength.def("ChangeArray1", (TColQuantity_Array1OfLength & (TColQuantity_HArray1OfLength::*)()) &TColQuantity_HArray1OfLength::ChangeArray1, "None");
	cls_TColQuantity_HArray1OfLength.def_static("get_type_name_", (const char * (*)()) &TColQuantity_HArray1OfLength::get_type_name, "None");
	cls_TColQuantity_HArray1OfLength.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColQuantity_HArray1OfLength::get_type_descriptor, "None");
	cls_TColQuantity_HArray1OfLength.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColQuantity_HArray1OfLength::*)() const ) &TColQuantity_HArray1OfLength::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColQuantity_HArray2OfLength.hxx
	py::class_<TColQuantity_HArray2OfLength, opencascade::handle<TColQuantity_HArray2OfLength>, TColQuantity_Array2OfLength, Standard_Transient> cls_TColQuantity_HArray2OfLength(mod, "TColQuantity_HArray2OfLength", "None");
	cls_TColQuantity_HArray2OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColQuantity_HArray2OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColQuantity_Array2OfLength::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColQuantity_HArray2OfLength.def(py::init<const TColQuantity_Array2OfLength &>(), py::arg("theOther"));
	cls_TColQuantity_HArray2OfLength.def("Array2", (const TColQuantity_Array2OfLength & (TColQuantity_HArray2OfLength::*)() const ) &TColQuantity_HArray2OfLength::Array2, "None");
	cls_TColQuantity_HArray2OfLength.def("ChangeArray2", (TColQuantity_Array2OfLength & (TColQuantity_HArray2OfLength::*)()) &TColQuantity_HArray2OfLength::ChangeArray2, "None");
	cls_TColQuantity_HArray2OfLength.def_static("get_type_name_", (const char * (*)()) &TColQuantity_HArray2OfLength::get_type_name, "None");
	cls_TColQuantity_HArray2OfLength.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColQuantity_HArray2OfLength::get_type_descriptor, "None");
	cls_TColQuantity_HArray2OfLength.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColQuantity_HArray2OfLength::*)() const ) &TColQuantity_HArray2OfLength::DynamicType, "None");


}
