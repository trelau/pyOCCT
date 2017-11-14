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
#include <TShort_Array1OfShortReal.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TShort_HArray1OfShortReal.hxx>
#include <NCollection_Array2.hxx>
#include <TShort_Array2OfShortReal.hxx>
#include <TShort_HArray2OfShortReal.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TShort_SequenceOfShortReal.hxx>
#include <TShort_HSequenceOfShortReal.hxx>

PYBIND11_MODULE(TShort, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TShort_Array1OfShortReal, std::unique_ptr<TShort_Array1OfShortReal, Deleter<TShort_Array1OfShortReal>>> cls_TShort_Array1OfShortReal(mod, "TShort_Array1OfShortReal", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TShort_Array1OfShortReal.def(py::init<>());
	cls_TShort_Array1OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TShort_Array1OfShortReal.def(py::init([] (const TShort_Array1OfShortReal &other) {return new TShort_Array1OfShortReal(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TShort_Array1OfShortReal.def(py::init<TShort_Array1OfShortReal &&>(), py::arg("theOther"));
	cls_TShort_Array1OfShortReal.def(py::init<const Standard_ShortReal &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TShort_Array1OfShortReal.def("begin", (TShort_Array1OfShortReal::iterator (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TShort_Array1OfShortReal.def("end", (TShort_Array1OfShortReal::iterator (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TShort_Array1OfShortReal.def("cbegin", (TShort_Array1OfShortReal::const_iterator (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TShort_Array1OfShortReal.def("cend", (TShort_Array1OfShortReal::const_iterator (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TShort_Array1OfShortReal.def("Init", (void (TShort_Array1OfShortReal::*)(const Standard_ShortReal &)) &TShort_Array1OfShortReal::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TShort_Array1OfShortReal.def("Size", (Standard_Integer (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::Size, "Size query");
	cls_TShort_Array1OfShortReal.def("Length", (Standard_Integer (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::Length, "Length query (the same)");
	cls_TShort_Array1OfShortReal.def("IsEmpty", (Standard_Boolean (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::IsEmpty, "Return TRUE if array has zero length.");
	cls_TShort_Array1OfShortReal.def("Lower", (Standard_Integer (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::Lower, "Lower bound");
	cls_TShort_Array1OfShortReal.def("Upper", (Standard_Integer (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::Upper, "Upper bound");
	cls_TShort_Array1OfShortReal.def("IsDeletable", (Standard_Boolean (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::IsDeletable, "myDeletable flag");
	cls_TShort_Array1OfShortReal.def("IsAllocated", (Standard_Boolean (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TShort_Array1OfShortReal.def("Assign", (TShort_Array1OfShortReal & (TShort_Array1OfShortReal::*)(const TShort_Array1OfShortReal &)) &TShort_Array1OfShortReal::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TShort_Array1OfShortReal.def("Move", (TShort_Array1OfShortReal & (TShort_Array1OfShortReal::*)(TShort_Array1OfShortReal &&)) &TShort_Array1OfShortReal::Move, "Move assignment", py::arg("theOther"));
	cls_TShort_Array1OfShortReal.def("assign", (TShort_Array1OfShortReal & (TShort_Array1OfShortReal::*)(const TShort_Array1OfShortReal &)) &TShort_Array1OfShortReal::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TShort_Array1OfShortReal.def("assign", (TShort_Array1OfShortReal & (TShort_Array1OfShortReal::*)(TShort_Array1OfShortReal &&)) &TShort_Array1OfShortReal::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TShort_Array1OfShortReal.def("First", (const Standard_ShortReal & (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::First, "Returns first element");
	cls_TShort_Array1OfShortReal.def("ChangeFirst", (Standard_ShortReal & (TShort_Array1OfShortReal::*)()) &TShort_Array1OfShortReal::ChangeFirst, "Returns first element");
	cls_TShort_Array1OfShortReal.def("Last", (const Standard_ShortReal & (TShort_Array1OfShortReal::*)() const ) &TShort_Array1OfShortReal::Last, "Returns last element");
	cls_TShort_Array1OfShortReal.def("ChangeLast", (Standard_ShortReal & (TShort_Array1OfShortReal::*)()) &TShort_Array1OfShortReal::ChangeLast, "Returns last element");
	cls_TShort_Array1OfShortReal.def("Value", (const Standard_ShortReal & (TShort_Array1OfShortReal::*)(const Standard_Integer) const ) &TShort_Array1OfShortReal::Value, "Constant value access", py::arg("theIndex"));
	cls_TShort_Array1OfShortReal.def("__call__", (const Standard_ShortReal & (TShort_Array1OfShortReal::*)(const Standard_Integer) const ) &TShort_Array1OfShortReal::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TShort_Array1OfShortReal.def("ChangeValue", (Standard_ShortReal & (TShort_Array1OfShortReal::*)(const Standard_Integer)) &TShort_Array1OfShortReal::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TShort_Array1OfShortReal.def("__call__", (Standard_ShortReal & (TShort_Array1OfShortReal::*)(const Standard_Integer)) &TShort_Array1OfShortReal::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TShort_Array1OfShortReal.def("SetValue", (void (TShort_Array1OfShortReal::*)(const Standard_Integer, const Standard_ShortReal &)) &TShort_Array1OfShortReal::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TShort_Array1OfShortReal.def("Resize", (void (TShort_Array1OfShortReal::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TShort_Array1OfShortReal::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TShort_Array1OfShortReal.def("__iter__", [](const TShort_Array1OfShortReal &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TShort_Array2OfShortReal, std::unique_ptr<TShort_Array2OfShortReal, Deleter<TShort_Array2OfShortReal>>> cls_TShort_Array2OfShortReal(mod, "TShort_Array2OfShortReal", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TShort_Array2OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TShort_Array2OfShortReal.def(py::init([] (const TShort_Array2OfShortReal &other) {return new TShort_Array2OfShortReal(other);}), "Copy constructor", py::arg("other"));
	cls_TShort_Array2OfShortReal.def(py::init<const Standard_ShortReal &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TShort_Array2OfShortReal.def("Init", (void (TShort_Array2OfShortReal::*)(const Standard_ShortReal &)) &TShort_Array2OfShortReal::Init, "Initialise the values", py::arg("theValue"));
	cls_TShort_Array2OfShortReal.def("Size", (Standard_Integer (TShort_Array2OfShortReal::*)() const ) &TShort_Array2OfShortReal::Size, "Size (number of items)");
	cls_TShort_Array2OfShortReal.def("Length", (Standard_Integer (TShort_Array2OfShortReal::*)() const ) &TShort_Array2OfShortReal::Length, "Length (number of items)");
	cls_TShort_Array2OfShortReal.def("RowLength", (Standard_Integer (TShort_Array2OfShortReal::*)() const ) &TShort_Array2OfShortReal::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TShort_Array2OfShortReal.def("ColLength", (Standard_Integer (TShort_Array2OfShortReal::*)() const ) &TShort_Array2OfShortReal::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TShort_Array2OfShortReal.def("LowerRow", (Standard_Integer (TShort_Array2OfShortReal::*)() const ) &TShort_Array2OfShortReal::LowerRow, "LowerRow");
	cls_TShort_Array2OfShortReal.def("UpperRow", (Standard_Integer (TShort_Array2OfShortReal::*)() const ) &TShort_Array2OfShortReal::UpperRow, "UpperRow");
	cls_TShort_Array2OfShortReal.def("LowerCol", (Standard_Integer (TShort_Array2OfShortReal::*)() const ) &TShort_Array2OfShortReal::LowerCol, "LowerCol");
	cls_TShort_Array2OfShortReal.def("UpperCol", (Standard_Integer (TShort_Array2OfShortReal::*)() const ) &TShort_Array2OfShortReal::UpperCol, "UpperCol");
	cls_TShort_Array2OfShortReal.def("IsDeletable", (Standard_Boolean (TShort_Array2OfShortReal::*)() const ) &TShort_Array2OfShortReal::IsDeletable, "myDeletable flag");
	cls_TShort_Array2OfShortReal.def("Assign", (TShort_Array2OfShortReal & (TShort_Array2OfShortReal::*)(const TShort_Array2OfShortReal &)) &TShort_Array2OfShortReal::Assign, "Assignment", py::arg("theOther"));
	cls_TShort_Array2OfShortReal.def("assign", (TShort_Array2OfShortReal & (TShort_Array2OfShortReal::*)(const TShort_Array2OfShortReal &)) &TShort_Array2OfShortReal::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TShort_Array2OfShortReal.def("Value", (const Standard_ShortReal & (TShort_Array2OfShortReal::*)(const Standard_Integer, const Standard_Integer) const ) &TShort_Array2OfShortReal::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TShort_Array2OfShortReal.def("__call__", (const Standard_ShortReal & (TShort_Array2OfShortReal::*)(const Standard_Integer, const Standard_Integer) const ) &TShort_Array2OfShortReal::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TShort_Array2OfShortReal.def("ChangeValue", (Standard_ShortReal & (TShort_Array2OfShortReal::*)(const Standard_Integer, const Standard_Integer)) &TShort_Array2OfShortReal::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TShort_Array2OfShortReal.def("__call__", (Standard_ShortReal & (TShort_Array2OfShortReal::*)(const Standard_Integer, const Standard_Integer)) &TShort_Array2OfShortReal::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TShort_Array2OfShortReal.def("SetValue", (void (TShort_Array2OfShortReal::*)(const Standard_Integer, const Standard_Integer, const Standard_ShortReal &)) &TShort_Array2OfShortReal::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TShort_SequenceOfShortReal, std::unique_ptr<TShort_SequenceOfShortReal, Deleter<TShort_SequenceOfShortReal>>, NCollection_BaseSequence> cls_TShort_SequenceOfShortReal(mod, "TShort_SequenceOfShortReal", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TShort_SequenceOfShortReal.def(py::init<>());
	cls_TShort_SequenceOfShortReal.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TShort_SequenceOfShortReal.def(py::init([] (const TShort_SequenceOfShortReal &other) {return new TShort_SequenceOfShortReal(other);}), "Copy constructor", py::arg("other"));
	cls_TShort_SequenceOfShortReal.def("begin", (TShort_SequenceOfShortReal::iterator (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TShort_SequenceOfShortReal.def("end", (TShort_SequenceOfShortReal::iterator (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TShort_SequenceOfShortReal.def("cbegin", (TShort_SequenceOfShortReal::const_iterator (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TShort_SequenceOfShortReal.def("cend", (TShort_SequenceOfShortReal::const_iterator (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TShort_SequenceOfShortReal.def("Size", (Standard_Integer (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::Size, "Number of items");
	cls_TShort_SequenceOfShortReal.def("Length", (Standard_Integer (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::Length, "Number of items");
	cls_TShort_SequenceOfShortReal.def("Lower", (Standard_Integer (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::Lower, "Method for consistency with other collections.");
	cls_TShort_SequenceOfShortReal.def("Upper", (Standard_Integer (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::Upper, "Method for consistency with other collections.");
	cls_TShort_SequenceOfShortReal.def("IsEmpty", (Standard_Boolean (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::IsEmpty, "Empty query");
	cls_TShort_SequenceOfShortReal.def("Reverse", (void (TShort_SequenceOfShortReal::*)()) &TShort_SequenceOfShortReal::Reverse, "Reverse sequence");
	cls_TShort_SequenceOfShortReal.def("Exchange", (void (TShort_SequenceOfShortReal::*)(const Standard_Integer, const Standard_Integer)) &TShort_SequenceOfShortReal::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TShort_SequenceOfShortReal.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TShort_SequenceOfShortReal::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TShort_SequenceOfShortReal.def("Clear", [](TShort_SequenceOfShortReal &self) -> void { return self.Clear(); });
	cls_TShort_SequenceOfShortReal.def("Clear", (void (TShort_SequenceOfShortReal::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TShort_SequenceOfShortReal::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TShort_SequenceOfShortReal.def("Assign", (TShort_SequenceOfShortReal & (TShort_SequenceOfShortReal::*)(const TShort_SequenceOfShortReal &)) &TShort_SequenceOfShortReal::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TShort_SequenceOfShortReal.def("assign", (TShort_SequenceOfShortReal & (TShort_SequenceOfShortReal::*)(const TShort_SequenceOfShortReal &)) &TShort_SequenceOfShortReal::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TShort_SequenceOfShortReal.def("Remove", (void (TShort_SequenceOfShortReal::*)(TShort_SequenceOfShortReal::Iterator &)) &TShort_SequenceOfShortReal::Remove, "Remove one item", py::arg("thePosition"));
	cls_TShort_SequenceOfShortReal.def("Remove", (void (TShort_SequenceOfShortReal::*)(const Standard_Integer)) &TShort_SequenceOfShortReal::Remove, "Remove one item", py::arg("theIndex"));
	cls_TShort_SequenceOfShortReal.def("Remove", (void (TShort_SequenceOfShortReal::*)(const Standard_Integer, const Standard_Integer)) &TShort_SequenceOfShortReal::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TShort_SequenceOfShortReal.def("Append", (void (TShort_SequenceOfShortReal::*)(const Standard_ShortReal &)) &TShort_SequenceOfShortReal::Append, "Append one item", py::arg("theItem"));
	cls_TShort_SequenceOfShortReal.def("Append", (void (TShort_SequenceOfShortReal::*)(TShort_SequenceOfShortReal &)) &TShort_SequenceOfShortReal::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TShort_SequenceOfShortReal.def("Prepend", (void (TShort_SequenceOfShortReal::*)(const Standard_ShortReal &)) &TShort_SequenceOfShortReal::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TShort_SequenceOfShortReal.def("Prepend", (void (TShort_SequenceOfShortReal::*)(TShort_SequenceOfShortReal &)) &TShort_SequenceOfShortReal::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TShort_SequenceOfShortReal.def("InsertBefore", (void (TShort_SequenceOfShortReal::*)(const Standard_Integer, const Standard_ShortReal &)) &TShort_SequenceOfShortReal::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TShort_SequenceOfShortReal.def("InsertBefore", (void (TShort_SequenceOfShortReal::*)(const Standard_Integer, TShort_SequenceOfShortReal &)) &TShort_SequenceOfShortReal::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TShort_SequenceOfShortReal.def("InsertAfter", (void (TShort_SequenceOfShortReal::*)(TShort_SequenceOfShortReal::Iterator &, const Standard_ShortReal &)) &TShort_SequenceOfShortReal::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TShort_SequenceOfShortReal.def("InsertAfter", (void (TShort_SequenceOfShortReal::*)(const Standard_Integer, TShort_SequenceOfShortReal &)) &TShort_SequenceOfShortReal::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TShort_SequenceOfShortReal.def("InsertAfter", (void (TShort_SequenceOfShortReal::*)(const Standard_Integer, const Standard_ShortReal &)) &TShort_SequenceOfShortReal::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TShort_SequenceOfShortReal.def("Split", (void (TShort_SequenceOfShortReal::*)(const Standard_Integer, TShort_SequenceOfShortReal &)) &TShort_SequenceOfShortReal::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TShort_SequenceOfShortReal.def("First", (const Standard_ShortReal & (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::First, "First item access");
	cls_TShort_SequenceOfShortReal.def("ChangeFirst", (Standard_ShortReal & (TShort_SequenceOfShortReal::*)()) &TShort_SequenceOfShortReal::ChangeFirst, "First item access");
	cls_TShort_SequenceOfShortReal.def("Last", (const Standard_ShortReal & (TShort_SequenceOfShortReal::*)() const ) &TShort_SequenceOfShortReal::Last, "Last item access");
	cls_TShort_SequenceOfShortReal.def("ChangeLast", (Standard_ShortReal & (TShort_SequenceOfShortReal::*)()) &TShort_SequenceOfShortReal::ChangeLast, "Last item access");
	cls_TShort_SequenceOfShortReal.def("Value", (const Standard_ShortReal & (TShort_SequenceOfShortReal::*)(const Standard_Integer) const ) &TShort_SequenceOfShortReal::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TShort_SequenceOfShortReal.def("__call__", (const Standard_ShortReal & (TShort_SequenceOfShortReal::*)(const Standard_Integer) const ) &TShort_SequenceOfShortReal::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TShort_SequenceOfShortReal.def("ChangeValue", (Standard_ShortReal & (TShort_SequenceOfShortReal::*)(const Standard_Integer)) &TShort_SequenceOfShortReal::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TShort_SequenceOfShortReal.def("__call__", (Standard_ShortReal & (TShort_SequenceOfShortReal::*)(const Standard_Integer)) &TShort_SequenceOfShortReal::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TShort_SequenceOfShortReal.def("SetValue", (void (TShort_SequenceOfShortReal::*)(const Standard_Integer, const Standard_ShortReal &)) &TShort_SequenceOfShortReal::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TShort_SequenceOfShortReal.def("__iter__", [](const TShort_SequenceOfShortReal &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TShort_HArray1OfShortReal.hxx
	py::class_<TShort_HArray1OfShortReal, opencascade::handle<TShort_HArray1OfShortReal>, TShort_Array1OfShortReal, Standard_Transient> cls_TShort_HArray1OfShortReal(mod, "TShort_HArray1OfShortReal", "None");
	cls_TShort_HArray1OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TShort_HArray1OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer, const TShort_Array1OfShortReal::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TShort_HArray1OfShortReal.def(py::init<const TShort_Array1OfShortReal &>(), py::arg("theOther"));
	cls_TShort_HArray1OfShortReal.def("Array1", (const TShort_Array1OfShortReal & (TShort_HArray1OfShortReal::*)() const ) &TShort_HArray1OfShortReal::Array1, "None");
	cls_TShort_HArray1OfShortReal.def("ChangeArray1", (TShort_Array1OfShortReal & (TShort_HArray1OfShortReal::*)()) &TShort_HArray1OfShortReal::ChangeArray1, "None");
	cls_TShort_HArray1OfShortReal.def_static("get_type_name_", (const char * (*)()) &TShort_HArray1OfShortReal::get_type_name, "None");
	cls_TShort_HArray1OfShortReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TShort_HArray1OfShortReal::get_type_descriptor, "None");
	cls_TShort_HArray1OfShortReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TShort_HArray1OfShortReal::*)() const ) &TShort_HArray1OfShortReal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TShort_HArray2OfShortReal.hxx
	py::class_<TShort_HArray2OfShortReal, opencascade::handle<TShort_HArray2OfShortReal>, TShort_Array2OfShortReal, Standard_Transient> cls_TShort_HArray2OfShortReal(mod, "TShort_HArray2OfShortReal", "None");
	cls_TShort_HArray2OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TShort_HArray2OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TShort_Array2OfShortReal::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TShort_HArray2OfShortReal.def(py::init<const TShort_Array2OfShortReal &>(), py::arg("theOther"));
	cls_TShort_HArray2OfShortReal.def("Array2", (const TShort_Array2OfShortReal & (TShort_HArray2OfShortReal::*)() const ) &TShort_HArray2OfShortReal::Array2, "None");
	cls_TShort_HArray2OfShortReal.def("ChangeArray2", (TShort_Array2OfShortReal & (TShort_HArray2OfShortReal::*)()) &TShort_HArray2OfShortReal::ChangeArray2, "None");
	cls_TShort_HArray2OfShortReal.def_static("get_type_name_", (const char * (*)()) &TShort_HArray2OfShortReal::get_type_name, "None");
	cls_TShort_HArray2OfShortReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TShort_HArray2OfShortReal::get_type_descriptor, "None");
	cls_TShort_HArray2OfShortReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TShort_HArray2OfShortReal::*)() const ) &TShort_HArray2OfShortReal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TShort_HSequenceOfShortReal.hxx
	py::class_<TShort_HSequenceOfShortReal, opencascade::handle<TShort_HSequenceOfShortReal>, TShort_SequenceOfShortReal, Standard_Transient> cls_TShort_HSequenceOfShortReal(mod, "TShort_HSequenceOfShortReal", "None");
	cls_TShort_HSequenceOfShortReal.def(py::init<>());
	cls_TShort_HSequenceOfShortReal.def(py::init<const TShort_SequenceOfShortReal &>(), py::arg("theOther"));
	cls_TShort_HSequenceOfShortReal.def("Sequence", (const TShort_SequenceOfShortReal & (TShort_HSequenceOfShortReal::*)() const ) &TShort_HSequenceOfShortReal::Sequence, "None");
	cls_TShort_HSequenceOfShortReal.def("Append", (void (TShort_HSequenceOfShortReal::*)(const TShort_SequenceOfShortReal::value_type &)) &TShort_HSequenceOfShortReal::Append, "None", py::arg("theItem"));
	cls_TShort_HSequenceOfShortReal.def("Append", (void (TShort_HSequenceOfShortReal::*)(TShort_SequenceOfShortReal &)) &TShort_HSequenceOfShortReal::Append, "None", py::arg("theSequence"));
	cls_TShort_HSequenceOfShortReal.def("ChangeSequence", (TShort_SequenceOfShortReal & (TShort_HSequenceOfShortReal::*)()) &TShort_HSequenceOfShortReal::ChangeSequence, "None");
	cls_TShort_HSequenceOfShortReal.def_static("get_type_name_", (const char * (*)()) &TShort_HSequenceOfShortReal::get_type_name, "None");
	cls_TShort_HSequenceOfShortReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TShort_HSequenceOfShortReal::get_type_descriptor, "None");
	cls_TShort_HSequenceOfShortReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TShort_HSequenceOfShortReal::*)() const ) &TShort_HSequenceOfShortReal::DynamicType, "None");


}
