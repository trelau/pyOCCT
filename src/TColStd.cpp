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
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <NCollection_Array2.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TColStd_Array1OfByte.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <TColStd_ListOfTransient.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <NCollection_Map.hxx>
#include <TColStd_MapOfTransient.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <TColStd_Array1OfAsciiString.hxx>
#include <TColStd_SequenceOfHAsciiString.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <TColStd_Array2OfInteger.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <TColStd_SequenceOfAddress.hxx>
#include <TColStd_DataMapOfIntegerTransient.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <NCollection_IndexedMap.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <TColStd_DataMapOfAsciiStringInteger.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <TColStd_Array1OfListOfInteger.hxx>
#include <TColStd_HArray1OfListOfInteger.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_IndexedMapOfInteger.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <TColStd_Array1OfBoolean.hxx>
#include <TColStd_MapOfAsciiString.hxx>
#include <TColStd_Array2OfBoolean.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <TColStd_DataMapOfStringInteger.hxx>
#include <TColStd_ListOfReal.hxx>
#include <TColStd_ListOfAsciiString.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TColStd_Array2OfTransient.hxx>
#include <TColStd_HArray2OfTransient.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <TColStd_SequenceOfHExtendedString.hxx>
#include <TColStd_HSequenceOfHExtendedString.hxx>
#include <TCollection_BasicMapIterator.hxx>
#include <TColStd_MapIteratorOfPackedMapOfInteger.hxx>
#include <TColStd_Array1OfExtendedString.hxx>
#include <TColStd_HArray1OfExtendedString.hxx>
#include <TColStd_Array1OfCharacter.hxx>
#include <TColStd_Array2OfCharacter.hxx>
#include <TColStd_DataMapOfTransientTransient.hxx>
#include <TColStd_HArray1OfCharacter.hxx>
#include <TColStd_HArray2OfBoolean.hxx>
#include <TColStd_HArray2OfCharacter.hxx>
#include <TColStd_HSequenceOfExtendedString.hxx>
#include <TColStd_MapRealHasher.hxx>
#include <TColStd_IndexedMapOfReal.hxx>
#include <TColStd_MapOfReal.hxx>

PYBIND11_MODULE(TColStd, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	other_mod = py::module::import("OCCT.TColQuantity");
	if (py::hasattr(other_mod, "TColQuantity_Array1OfLength")) {
		mod.attr("TColStd_Array1OfReal") = other_mod.attr("TColQuantity_Array1OfLength");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColStd_Array1OfInteger, std::unique_ptr<TColStd_Array1OfInteger, Deleter<TColStd_Array1OfInteger>>> cls_TColStd_Array1OfInteger(mod, "TColStd_Array1OfInteger", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColStd_Array1OfInteger.def(py::init<>());
	cls_TColStd_Array1OfInteger.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfInteger.def(py::init([] (const TColStd_Array1OfInteger &other) {return new TColStd_Array1OfInteger(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColStd_Array1OfInteger.def(py::init<TColStd_Array1OfInteger &&>(), py::arg("theOther"));
	cls_TColStd_Array1OfInteger.def(py::init<const Standard_Integer &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfInteger.def("begin", (TColStd_Array1OfInteger::iterator (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfInteger.def("end", (TColStd_Array1OfInteger::iterator (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfInteger.def("cbegin", (TColStd_Array1OfInteger::const_iterator (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfInteger.def("cend", (TColStd_Array1OfInteger::const_iterator (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfInteger.def("Init", (void (TColStd_Array1OfInteger::*)(const Standard_Integer &)) &TColStd_Array1OfInteger::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColStd_Array1OfInteger.def("Size", (Standard_Integer (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::Size, "Size query");
	cls_TColStd_Array1OfInteger.def("Length", (Standard_Integer (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::Length, "Length query (the same)");
	cls_TColStd_Array1OfInteger.def("IsEmpty", (Standard_Boolean (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColStd_Array1OfInteger.def("Lower", (Standard_Integer (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::Lower, "Lower bound");
	cls_TColStd_Array1OfInteger.def("Upper", (Standard_Integer (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::Upper, "Upper bound");
	cls_TColStd_Array1OfInteger.def("IsDeletable", (Standard_Boolean (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::IsDeletable, "myDeletable flag");
	cls_TColStd_Array1OfInteger.def("IsAllocated", (Standard_Boolean (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColStd_Array1OfInteger.def("Assign", (TColStd_Array1OfInteger & (TColStd_Array1OfInteger::*)(const TColStd_Array1OfInteger &)) &TColStd_Array1OfInteger::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfInteger.def("Move", (TColStd_Array1OfInteger & (TColStd_Array1OfInteger::*)(TColStd_Array1OfInteger &&)) &TColStd_Array1OfInteger::Move, "Move assignment", py::arg("theOther"));
	cls_TColStd_Array1OfInteger.def("assign", (TColStd_Array1OfInteger & (TColStd_Array1OfInteger::*)(const TColStd_Array1OfInteger &)) &TColStd_Array1OfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfInteger.def("assign", (TColStd_Array1OfInteger & (TColStd_Array1OfInteger::*)(TColStd_Array1OfInteger &&)) &TColStd_Array1OfInteger::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColStd_Array1OfInteger.def("First", (const Standard_Integer & (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::First, "Returns first element");
	cls_TColStd_Array1OfInteger.def("ChangeFirst", (Standard_Integer & (TColStd_Array1OfInteger::*)()) &TColStd_Array1OfInteger::ChangeFirst, "Returns first element");
	cls_TColStd_Array1OfInteger.def("Last", (const Standard_Integer & (TColStd_Array1OfInteger::*)() const ) &TColStd_Array1OfInteger::Last, "Returns last element");
	cls_TColStd_Array1OfInteger.def("ChangeLast", (Standard_Integer & (TColStd_Array1OfInteger::*)()) &TColStd_Array1OfInteger::ChangeLast, "Returns last element");
	cls_TColStd_Array1OfInteger.def("Value", (const Standard_Integer & (TColStd_Array1OfInteger::*)(const Standard_Integer) const ) &TColStd_Array1OfInteger::Value, "Constant value access", py::arg("theIndex"));
	cls_TColStd_Array1OfInteger.def("__call__", (const Standard_Integer & (TColStd_Array1OfInteger::*)(const Standard_Integer) const ) &TColStd_Array1OfInteger::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColStd_Array1OfInteger.def("ChangeValue", (Standard_Integer & (TColStd_Array1OfInteger::*)(const Standard_Integer)) &TColStd_Array1OfInteger::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColStd_Array1OfInteger.def("__call__", (Standard_Integer & (TColStd_Array1OfInteger::*)(const Standard_Integer)) &TColStd_Array1OfInteger::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColStd_Array1OfInteger.def("SetValue", (void (TColStd_Array1OfInteger::*)(const Standard_Integer, const Standard_Integer &)) &TColStd_Array1OfInteger::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_Array1OfInteger.def("Resize", (void (TColStd_Array1OfInteger::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColStd_Array1OfInteger::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColStd_Array1OfInteger.def("__iter__", [](const TColStd_Array1OfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColStd_SequenceOfReal, std::unique_ptr<TColStd_SequenceOfReal, Deleter<TColStd_SequenceOfReal>>, NCollection_BaseSequence> cls_TColStd_SequenceOfReal(mod, "TColStd_SequenceOfReal", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColStd_SequenceOfReal.def(py::init<>());
	cls_TColStd_SequenceOfReal.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_SequenceOfReal.def(py::init([] (const TColStd_SequenceOfReal &other) {return new TColStd_SequenceOfReal(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_SequenceOfReal.def("begin", (TColStd_SequenceOfReal::iterator (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfReal.def("end", (TColStd_SequenceOfReal::iterator (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfReal.def("cbegin", (TColStd_SequenceOfReal::const_iterator (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfReal.def("cend", (TColStd_SequenceOfReal::const_iterator (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfReal.def("Size", (Standard_Integer (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::Size, "Number of items");
	cls_TColStd_SequenceOfReal.def("Length", (Standard_Integer (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::Length, "Number of items");
	cls_TColStd_SequenceOfReal.def("Lower", (Standard_Integer (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::Lower, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfReal.def("Upper", (Standard_Integer (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::Upper, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfReal.def("IsEmpty", (Standard_Boolean (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::IsEmpty, "Empty query");
	cls_TColStd_SequenceOfReal.def("Reverse", (void (TColStd_SequenceOfReal::*)()) &TColStd_SequenceOfReal::Reverse, "Reverse sequence");
	cls_TColStd_SequenceOfReal.def("Exchange", (void (TColStd_SequenceOfReal::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfReal::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColStd_SequenceOfReal.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfReal::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColStd_SequenceOfReal.def("Clear", [](TColStd_SequenceOfReal &self) -> void { return self.Clear(); });
	cls_TColStd_SequenceOfReal.def("Clear", (void (TColStd_SequenceOfReal::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfReal::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColStd_SequenceOfReal.def("Assign", (TColStd_SequenceOfReal & (TColStd_SequenceOfReal::*)(const TColStd_SequenceOfReal &)) &TColStd_SequenceOfReal::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_SequenceOfReal.def("assign", (TColStd_SequenceOfReal & (TColStd_SequenceOfReal::*)(const TColStd_SequenceOfReal &)) &TColStd_SequenceOfReal::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_SequenceOfReal.def("Remove", (void (TColStd_SequenceOfReal::*)(TColStd_SequenceOfReal::Iterator &)) &TColStd_SequenceOfReal::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColStd_SequenceOfReal.def("Remove", (void (TColStd_SequenceOfReal::*)(const Standard_Integer)) &TColStd_SequenceOfReal::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColStd_SequenceOfReal.def("Remove", (void (TColStd_SequenceOfReal::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfReal::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColStd_SequenceOfReal.def("Append", (void (TColStd_SequenceOfReal::*)(const Standard_Real &)) &TColStd_SequenceOfReal::Append, "Append one item", py::arg("theItem"));
	cls_TColStd_SequenceOfReal.def("Append", (void (TColStd_SequenceOfReal::*)(TColStd_SequenceOfReal &)) &TColStd_SequenceOfReal::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfReal.def("Prepend", (void (TColStd_SequenceOfReal::*)(const Standard_Real &)) &TColStd_SequenceOfReal::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColStd_SequenceOfReal.def("Prepend", (void (TColStd_SequenceOfReal::*)(TColStd_SequenceOfReal &)) &TColStd_SequenceOfReal::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfReal.def("InsertBefore", (void (TColStd_SequenceOfReal::*)(const Standard_Integer, const Standard_Real &)) &TColStd_SequenceOfReal::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfReal.def("InsertBefore", (void (TColStd_SequenceOfReal::*)(const Standard_Integer, TColStd_SequenceOfReal &)) &TColStd_SequenceOfReal::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfReal.def("InsertAfter", (void (TColStd_SequenceOfReal::*)(TColStd_SequenceOfReal::Iterator &, const Standard_Real &)) &TColStd_SequenceOfReal::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColStd_SequenceOfReal.def("InsertAfter", (void (TColStd_SequenceOfReal::*)(const Standard_Integer, TColStd_SequenceOfReal &)) &TColStd_SequenceOfReal::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfReal.def("InsertAfter", (void (TColStd_SequenceOfReal::*)(const Standard_Integer, const Standard_Real &)) &TColStd_SequenceOfReal::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfReal.def("Split", (void (TColStd_SequenceOfReal::*)(const Standard_Integer, TColStd_SequenceOfReal &)) &TColStd_SequenceOfReal::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfReal.def("First", (const Standard_Real & (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::First, "First item access");
	cls_TColStd_SequenceOfReal.def("ChangeFirst", (Standard_Real & (TColStd_SequenceOfReal::*)()) &TColStd_SequenceOfReal::ChangeFirst, "First item access");
	cls_TColStd_SequenceOfReal.def("Last", (const Standard_Real & (TColStd_SequenceOfReal::*)() const ) &TColStd_SequenceOfReal::Last, "Last item access");
	cls_TColStd_SequenceOfReal.def("ChangeLast", (Standard_Real & (TColStd_SequenceOfReal::*)()) &TColStd_SequenceOfReal::ChangeLast, "Last item access");
	cls_TColStd_SequenceOfReal.def("Value", (const Standard_Real & (TColStd_SequenceOfReal::*)(const Standard_Integer) const ) &TColStd_SequenceOfReal::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfReal.def("__call__", (const Standard_Real & (TColStd_SequenceOfReal::*)(const Standard_Integer) const ) &TColStd_SequenceOfReal::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfReal.def("ChangeValue", (Standard_Real & (TColStd_SequenceOfReal::*)(const Standard_Integer)) &TColStd_SequenceOfReal::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfReal.def("__call__", (Standard_Real & (TColStd_SequenceOfReal::*)(const Standard_Integer)) &TColStd_SequenceOfReal::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfReal.def("SetValue", (void (TColStd_SequenceOfReal::*)(const Standard_Integer, const Standard_Real &)) &TColStd_SequenceOfReal::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfReal.def("__iter__", [](const TColStd_SequenceOfReal &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	other_mod = py::module::import("OCCT.TColQuantity");
	if (py::hasattr(other_mod, "TColQuantity_Array2OfLength")) {
		mod.attr("TColStd_Array2OfReal") = other_mod.attr("TColQuantity_Array2OfLength");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColStd_Array1OfByte, std::unique_ptr<TColStd_Array1OfByte, Deleter<TColStd_Array1OfByte>>> cls_TColStd_Array1OfByte(mod, "TColStd_Array1OfByte", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColStd_Array1OfByte.def(py::init<>());
	cls_TColStd_Array1OfByte.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfByte.def(py::init([] (const TColStd_Array1OfByte &other) {return new TColStd_Array1OfByte(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColStd_Array1OfByte.def(py::init<TColStd_Array1OfByte &&>(), py::arg("theOther"));
	cls_TColStd_Array1OfByte.def(py::init<const Standard_Byte &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfByte.def("begin", (TColStd_Array1OfByte::iterator (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfByte.def("end", (TColStd_Array1OfByte::iterator (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfByte.def("cbegin", (TColStd_Array1OfByte::const_iterator (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfByte.def("cend", (TColStd_Array1OfByte::const_iterator (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfByte.def("Init", (void (TColStd_Array1OfByte::*)(const Standard_Byte &)) &TColStd_Array1OfByte::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColStd_Array1OfByte.def("Size", (Standard_Integer (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::Size, "Size query");
	cls_TColStd_Array1OfByte.def("Length", (Standard_Integer (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::Length, "Length query (the same)");
	cls_TColStd_Array1OfByte.def("IsEmpty", (Standard_Boolean (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColStd_Array1OfByte.def("Lower", (Standard_Integer (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::Lower, "Lower bound");
	cls_TColStd_Array1OfByte.def("Upper", (Standard_Integer (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::Upper, "Upper bound");
	cls_TColStd_Array1OfByte.def("IsDeletable", (Standard_Boolean (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::IsDeletable, "myDeletable flag");
	cls_TColStd_Array1OfByte.def("IsAllocated", (Standard_Boolean (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColStd_Array1OfByte.def("Assign", (TColStd_Array1OfByte & (TColStd_Array1OfByte::*)(const TColStd_Array1OfByte &)) &TColStd_Array1OfByte::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfByte.def("Move", (TColStd_Array1OfByte & (TColStd_Array1OfByte::*)(TColStd_Array1OfByte &&)) &TColStd_Array1OfByte::Move, "Move assignment", py::arg("theOther"));
	cls_TColStd_Array1OfByte.def("assign", (TColStd_Array1OfByte & (TColStd_Array1OfByte::*)(const TColStd_Array1OfByte &)) &TColStd_Array1OfByte::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfByte.def("assign", (TColStd_Array1OfByte & (TColStd_Array1OfByte::*)(TColStd_Array1OfByte &&)) &TColStd_Array1OfByte::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColStd_Array1OfByte.def("First", (const Standard_Byte & (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::First, "Returns first element");
	cls_TColStd_Array1OfByte.def("ChangeFirst", (Standard_Byte & (TColStd_Array1OfByte::*)()) &TColStd_Array1OfByte::ChangeFirst, "Returns first element");
	cls_TColStd_Array1OfByte.def("Last", (const Standard_Byte & (TColStd_Array1OfByte::*)() const ) &TColStd_Array1OfByte::Last, "Returns last element");
	cls_TColStd_Array1OfByte.def("ChangeLast", (Standard_Byte & (TColStd_Array1OfByte::*)()) &TColStd_Array1OfByte::ChangeLast, "Returns last element");
	cls_TColStd_Array1OfByte.def("Value", (const Standard_Byte & (TColStd_Array1OfByte::*)(const Standard_Integer) const ) &TColStd_Array1OfByte::Value, "Constant value access", py::arg("theIndex"));
	cls_TColStd_Array1OfByte.def("__call__", (const Standard_Byte & (TColStd_Array1OfByte::*)(const Standard_Integer) const ) &TColStd_Array1OfByte::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColStd_Array1OfByte.def("ChangeValue", (Standard_Byte & (TColStd_Array1OfByte::*)(const Standard_Integer)) &TColStd_Array1OfByte::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColStd_Array1OfByte.def("__call__", (Standard_Byte & (TColStd_Array1OfByte::*)(const Standard_Integer)) &TColStd_Array1OfByte::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColStd_Array1OfByte.def("SetValue", (void (TColStd_Array1OfByte::*)(const Standard_Integer, const Standard_Byte &)) &TColStd_Array1OfByte::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_Array1OfByte.def("Resize", (void (TColStd_Array1OfByte::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColStd_Array1OfByte::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColStd_Array1OfByte.def("__iter__", [](const TColStd_Array1OfByte &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColStd_SequenceOfHAsciiString, std::unique_ptr<TColStd_SequenceOfHAsciiString, Deleter<TColStd_SequenceOfHAsciiString>>, NCollection_BaseSequence> cls_TColStd_SequenceOfHAsciiString(mod, "TColStd_SequenceOfHAsciiString", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColStd_SequenceOfHAsciiString.def(py::init<>());
	cls_TColStd_SequenceOfHAsciiString.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_SequenceOfHAsciiString.def(py::init([] (const TColStd_SequenceOfHAsciiString &other) {return new TColStd_SequenceOfHAsciiString(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_SequenceOfHAsciiString.def("begin", (TColStd_SequenceOfHAsciiString::iterator (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfHAsciiString.def("end", (TColStd_SequenceOfHAsciiString::iterator (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfHAsciiString.def("cbegin", (TColStd_SequenceOfHAsciiString::const_iterator (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfHAsciiString.def("cend", (TColStd_SequenceOfHAsciiString::const_iterator (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfHAsciiString.def("Size", (Standard_Integer (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::Size, "Number of items");
	cls_TColStd_SequenceOfHAsciiString.def("Length", (Standard_Integer (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::Length, "Number of items");
	cls_TColStd_SequenceOfHAsciiString.def("Lower", (Standard_Integer (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::Lower, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfHAsciiString.def("Upper", (Standard_Integer (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::Upper, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfHAsciiString.def("IsEmpty", (Standard_Boolean (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::IsEmpty, "Empty query");
	cls_TColStd_SequenceOfHAsciiString.def("Reverse", (void (TColStd_SequenceOfHAsciiString::*)()) &TColStd_SequenceOfHAsciiString::Reverse, "Reverse sequence");
	cls_TColStd_SequenceOfHAsciiString.def("Exchange", (void (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfHAsciiString::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColStd_SequenceOfHAsciiString.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfHAsciiString::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColStd_SequenceOfHAsciiString.def("Clear", [](TColStd_SequenceOfHAsciiString &self) -> void { return self.Clear(); });
	cls_TColStd_SequenceOfHAsciiString.def("Clear", (void (TColStd_SequenceOfHAsciiString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfHAsciiString::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColStd_SequenceOfHAsciiString.def("Assign", (TColStd_SequenceOfHAsciiString & (TColStd_SequenceOfHAsciiString::*)(const TColStd_SequenceOfHAsciiString &)) &TColStd_SequenceOfHAsciiString::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_SequenceOfHAsciiString.def("assign", (TColStd_SequenceOfHAsciiString & (TColStd_SequenceOfHAsciiString::*)(const TColStd_SequenceOfHAsciiString &)) &TColStd_SequenceOfHAsciiString::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_SequenceOfHAsciiString.def("Remove", (void (TColStd_SequenceOfHAsciiString::*)(TColStd_SequenceOfHAsciiString::Iterator &)) &TColStd_SequenceOfHAsciiString::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColStd_SequenceOfHAsciiString.def("Remove", (void (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer)) &TColStd_SequenceOfHAsciiString::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColStd_SequenceOfHAsciiString.def("Remove", (void (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfHAsciiString::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColStd_SequenceOfHAsciiString.def("Append", (void (TColStd_SequenceOfHAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &)) &TColStd_SequenceOfHAsciiString::Append, "Append one item", py::arg("theItem"));
	cls_TColStd_SequenceOfHAsciiString.def("Append", (void (TColStd_SequenceOfHAsciiString::*)(TColStd_SequenceOfHAsciiString &)) &TColStd_SequenceOfHAsciiString::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfHAsciiString.def("Prepend", (void (TColStd_SequenceOfHAsciiString::*)(const opencascade::handle<TCollection_HAsciiString> &)) &TColStd_SequenceOfHAsciiString::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColStd_SequenceOfHAsciiString.def("Prepend", (void (TColStd_SequenceOfHAsciiString::*)(TColStd_SequenceOfHAsciiString &)) &TColStd_SequenceOfHAsciiString::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfHAsciiString.def("InsertBefore", (void (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &TColStd_SequenceOfHAsciiString::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfHAsciiString.def("InsertBefore", (void (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer, TColStd_SequenceOfHAsciiString &)) &TColStd_SequenceOfHAsciiString::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfHAsciiString.def("InsertAfter", (void (TColStd_SequenceOfHAsciiString::*)(TColStd_SequenceOfHAsciiString::Iterator &, const opencascade::handle<TCollection_HAsciiString> &)) &TColStd_SequenceOfHAsciiString::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColStd_SequenceOfHAsciiString.def("InsertAfter", (void (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer, TColStd_SequenceOfHAsciiString &)) &TColStd_SequenceOfHAsciiString::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfHAsciiString.def("InsertAfter", (void (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &TColStd_SequenceOfHAsciiString::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfHAsciiString.def("Split", (void (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer, TColStd_SequenceOfHAsciiString &)) &TColStd_SequenceOfHAsciiString::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfHAsciiString.def("First", (const opencascade::handle<TCollection_HAsciiString> & (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::First, "First item access");
	cls_TColStd_SequenceOfHAsciiString.def("ChangeFirst", (opencascade::handle<TCollection_HAsciiString> & (TColStd_SequenceOfHAsciiString::*)()) &TColStd_SequenceOfHAsciiString::ChangeFirst, "First item access");
	cls_TColStd_SequenceOfHAsciiString.def("Last", (const opencascade::handle<TCollection_HAsciiString> & (TColStd_SequenceOfHAsciiString::*)() const ) &TColStd_SequenceOfHAsciiString::Last, "Last item access");
	cls_TColStd_SequenceOfHAsciiString.def("ChangeLast", (opencascade::handle<TCollection_HAsciiString> & (TColStd_SequenceOfHAsciiString::*)()) &TColStd_SequenceOfHAsciiString::ChangeLast, "Last item access");
	cls_TColStd_SequenceOfHAsciiString.def("Value", (const opencascade::handle<TCollection_HAsciiString> & (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer) const ) &TColStd_SequenceOfHAsciiString::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfHAsciiString.def("__call__", (const opencascade::handle<TCollection_HAsciiString> & (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer) const ) &TColStd_SequenceOfHAsciiString::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfHAsciiString.def("ChangeValue", (opencascade::handle<TCollection_HAsciiString> & (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer)) &TColStd_SequenceOfHAsciiString::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfHAsciiString.def("__call__", (opencascade::handle<TCollection_HAsciiString> & (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer)) &TColStd_SequenceOfHAsciiString::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfHAsciiString.def("SetValue", (void (TColStd_SequenceOfHAsciiString::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &TColStd_SequenceOfHAsciiString::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfHAsciiString.def("__iter__", [](const TColStd_SequenceOfHAsciiString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColStd_Array2OfInteger, std::unique_ptr<TColStd_Array2OfInteger, Deleter<TColStd_Array2OfInteger>>> cls_TColStd_Array2OfInteger(mod, "TColStd_Array2OfInteger", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColStd_Array2OfInteger.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColStd_Array2OfInteger.def(py::init([] (const TColStd_Array2OfInteger &other) {return new TColStd_Array2OfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_Array2OfInteger.def(py::init<const Standard_Integer &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColStd_Array2OfInteger.def("Init", (void (TColStd_Array2OfInteger::*)(const Standard_Integer &)) &TColStd_Array2OfInteger::Init, "Initialise the values", py::arg("theValue"));
	cls_TColStd_Array2OfInteger.def("Size", (Standard_Integer (TColStd_Array2OfInteger::*)() const ) &TColStd_Array2OfInteger::Size, "Size (number of items)");
	cls_TColStd_Array2OfInteger.def("Length", (Standard_Integer (TColStd_Array2OfInteger::*)() const ) &TColStd_Array2OfInteger::Length, "Length (number of items)");
	cls_TColStd_Array2OfInteger.def("RowLength", (Standard_Integer (TColStd_Array2OfInteger::*)() const ) &TColStd_Array2OfInteger::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColStd_Array2OfInteger.def("ColLength", (Standard_Integer (TColStd_Array2OfInteger::*)() const ) &TColStd_Array2OfInteger::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColStd_Array2OfInteger.def("LowerRow", (Standard_Integer (TColStd_Array2OfInteger::*)() const ) &TColStd_Array2OfInteger::LowerRow, "LowerRow");
	cls_TColStd_Array2OfInteger.def("UpperRow", (Standard_Integer (TColStd_Array2OfInteger::*)() const ) &TColStd_Array2OfInteger::UpperRow, "UpperRow");
	cls_TColStd_Array2OfInteger.def("LowerCol", (Standard_Integer (TColStd_Array2OfInteger::*)() const ) &TColStd_Array2OfInteger::LowerCol, "LowerCol");
	cls_TColStd_Array2OfInteger.def("UpperCol", (Standard_Integer (TColStd_Array2OfInteger::*)() const ) &TColStd_Array2OfInteger::UpperCol, "UpperCol");
	cls_TColStd_Array2OfInteger.def("IsDeletable", (Standard_Boolean (TColStd_Array2OfInteger::*)() const ) &TColStd_Array2OfInteger::IsDeletable, "myDeletable flag");
	cls_TColStd_Array2OfInteger.def("Assign", (TColStd_Array2OfInteger & (TColStd_Array2OfInteger::*)(const TColStd_Array2OfInteger &)) &TColStd_Array2OfInteger::Assign, "Assignment", py::arg("theOther"));
	cls_TColStd_Array2OfInteger.def("assign", (TColStd_Array2OfInteger & (TColStd_Array2OfInteger::*)(const TColStd_Array2OfInteger &)) &TColStd_Array2OfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_Array2OfInteger.def("Value", (const Standard_Integer & (TColStd_Array2OfInteger::*)(const Standard_Integer, const Standard_Integer) const ) &TColStd_Array2OfInteger::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfInteger.def("__call__", (const Standard_Integer & (TColStd_Array2OfInteger::*)(const Standard_Integer, const Standard_Integer) const ) &TColStd_Array2OfInteger::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfInteger.def("ChangeValue", (Standard_Integer & (TColStd_Array2OfInteger::*)(const Standard_Integer, const Standard_Integer)) &TColStd_Array2OfInteger::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfInteger.def("__call__", (Standard_Integer & (TColStd_Array2OfInteger::*)(const Standard_Integer, const Standard_Integer)) &TColStd_Array2OfInteger::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfInteger.def("SetValue", (void (TColStd_Array2OfInteger::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer &)) &TColStd_Array2OfInteger::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColStd_SequenceOfAsciiString, std::unique_ptr<TColStd_SequenceOfAsciiString, Deleter<TColStd_SequenceOfAsciiString>>, NCollection_BaseSequence> cls_TColStd_SequenceOfAsciiString(mod, "TColStd_SequenceOfAsciiString", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColStd_SequenceOfAsciiString.def(py::init<>());
	cls_TColStd_SequenceOfAsciiString.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_SequenceOfAsciiString.def(py::init([] (const TColStd_SequenceOfAsciiString &other) {return new TColStd_SequenceOfAsciiString(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_SequenceOfAsciiString.def("begin", (TColStd_SequenceOfAsciiString::iterator (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfAsciiString.def("end", (TColStd_SequenceOfAsciiString::iterator (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfAsciiString.def("cbegin", (TColStd_SequenceOfAsciiString::const_iterator (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfAsciiString.def("cend", (TColStd_SequenceOfAsciiString::const_iterator (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfAsciiString.def("Size", (Standard_Integer (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::Size, "Number of items");
	cls_TColStd_SequenceOfAsciiString.def("Length", (Standard_Integer (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::Length, "Number of items");
	cls_TColStd_SequenceOfAsciiString.def("Lower", (Standard_Integer (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::Lower, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfAsciiString.def("Upper", (Standard_Integer (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::Upper, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfAsciiString.def("IsEmpty", (Standard_Boolean (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::IsEmpty, "Empty query");
	cls_TColStd_SequenceOfAsciiString.def("Reverse", (void (TColStd_SequenceOfAsciiString::*)()) &TColStd_SequenceOfAsciiString::Reverse, "Reverse sequence");
	cls_TColStd_SequenceOfAsciiString.def("Exchange", (void (TColStd_SequenceOfAsciiString::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfAsciiString::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColStd_SequenceOfAsciiString.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfAsciiString::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColStd_SequenceOfAsciiString.def("Clear", [](TColStd_SequenceOfAsciiString &self) -> void { return self.Clear(); });
	cls_TColStd_SequenceOfAsciiString.def("Clear", (void (TColStd_SequenceOfAsciiString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfAsciiString::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColStd_SequenceOfAsciiString.def("Assign", (TColStd_SequenceOfAsciiString & (TColStd_SequenceOfAsciiString::*)(const TColStd_SequenceOfAsciiString &)) &TColStd_SequenceOfAsciiString::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_SequenceOfAsciiString.def("assign", (TColStd_SequenceOfAsciiString & (TColStd_SequenceOfAsciiString::*)(const TColStd_SequenceOfAsciiString &)) &TColStd_SequenceOfAsciiString::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_SequenceOfAsciiString.def("Remove", (void (TColStd_SequenceOfAsciiString::*)(TColStd_SequenceOfAsciiString::Iterator &)) &TColStd_SequenceOfAsciiString::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColStd_SequenceOfAsciiString.def("Remove", (void (TColStd_SequenceOfAsciiString::*)(const Standard_Integer)) &TColStd_SequenceOfAsciiString::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColStd_SequenceOfAsciiString.def("Remove", (void (TColStd_SequenceOfAsciiString::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfAsciiString::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColStd_SequenceOfAsciiString.def("Append", (void (TColStd_SequenceOfAsciiString::*)(const TCollection_AsciiString &)) &TColStd_SequenceOfAsciiString::Append, "Append one item", py::arg("theItem"));
	cls_TColStd_SequenceOfAsciiString.def("Append", (void (TColStd_SequenceOfAsciiString::*)(TColStd_SequenceOfAsciiString &)) &TColStd_SequenceOfAsciiString::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfAsciiString.def("Prepend", (void (TColStd_SequenceOfAsciiString::*)(const TCollection_AsciiString &)) &TColStd_SequenceOfAsciiString::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColStd_SequenceOfAsciiString.def("Prepend", (void (TColStd_SequenceOfAsciiString::*)(TColStd_SequenceOfAsciiString &)) &TColStd_SequenceOfAsciiString::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfAsciiString.def("InsertBefore", (void (TColStd_SequenceOfAsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TColStd_SequenceOfAsciiString::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfAsciiString.def("InsertBefore", (void (TColStd_SequenceOfAsciiString::*)(const Standard_Integer, TColStd_SequenceOfAsciiString &)) &TColStd_SequenceOfAsciiString::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfAsciiString.def("InsertAfter", (void (TColStd_SequenceOfAsciiString::*)(TColStd_SequenceOfAsciiString::Iterator &, const TCollection_AsciiString &)) &TColStd_SequenceOfAsciiString::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColStd_SequenceOfAsciiString.def("InsertAfter", (void (TColStd_SequenceOfAsciiString::*)(const Standard_Integer, TColStd_SequenceOfAsciiString &)) &TColStd_SequenceOfAsciiString::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfAsciiString.def("InsertAfter", (void (TColStd_SequenceOfAsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TColStd_SequenceOfAsciiString::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfAsciiString.def("Split", (void (TColStd_SequenceOfAsciiString::*)(const Standard_Integer, TColStd_SequenceOfAsciiString &)) &TColStd_SequenceOfAsciiString::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfAsciiString.def("First", (const TCollection_AsciiString & (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::First, "First item access");
	cls_TColStd_SequenceOfAsciiString.def("ChangeFirst", (TCollection_AsciiString & (TColStd_SequenceOfAsciiString::*)()) &TColStd_SequenceOfAsciiString::ChangeFirst, "First item access");
	cls_TColStd_SequenceOfAsciiString.def("Last", (const TCollection_AsciiString & (TColStd_SequenceOfAsciiString::*)() const ) &TColStd_SequenceOfAsciiString::Last, "Last item access");
	cls_TColStd_SequenceOfAsciiString.def("ChangeLast", (TCollection_AsciiString & (TColStd_SequenceOfAsciiString::*)()) &TColStd_SequenceOfAsciiString::ChangeLast, "Last item access");
	cls_TColStd_SequenceOfAsciiString.def("Value", (const TCollection_AsciiString & (TColStd_SequenceOfAsciiString::*)(const Standard_Integer) const ) &TColStd_SequenceOfAsciiString::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfAsciiString.def("__call__", (const TCollection_AsciiString & (TColStd_SequenceOfAsciiString::*)(const Standard_Integer) const ) &TColStd_SequenceOfAsciiString::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfAsciiString.def("ChangeValue", (TCollection_AsciiString & (TColStd_SequenceOfAsciiString::*)(const Standard_Integer)) &TColStd_SequenceOfAsciiString::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfAsciiString.def("__call__", (TCollection_AsciiString & (TColStd_SequenceOfAsciiString::*)(const Standard_Integer)) &TColStd_SequenceOfAsciiString::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfAsciiString.def("SetValue", (void (TColStd_SequenceOfAsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TColStd_SequenceOfAsciiString::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfAsciiString.def("__iter__", [](const TColStd_SequenceOfAsciiString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColStd_Array1OfListOfInteger, std::unique_ptr<TColStd_Array1OfListOfInteger, Deleter<TColStd_Array1OfListOfInteger>>> cls_TColStd_Array1OfListOfInteger(mod, "TColStd_Array1OfListOfInteger", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColStd_Array1OfListOfInteger.def(py::init<>());
	cls_TColStd_Array1OfListOfInteger.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfListOfInteger.def(py::init([] (const TColStd_Array1OfListOfInteger &other) {return new TColStd_Array1OfListOfInteger(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColStd_Array1OfListOfInteger.def(py::init<TColStd_Array1OfListOfInteger &&>(), py::arg("theOther"));
	cls_TColStd_Array1OfListOfInteger.def(py::init<const TColStd_ListOfInteger &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfListOfInteger.def("begin", (TColStd_Array1OfListOfInteger::iterator (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfListOfInteger.def("end", (TColStd_Array1OfListOfInteger::iterator (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfListOfInteger.def("cbegin", (TColStd_Array1OfListOfInteger::const_iterator (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfListOfInteger.def("cend", (TColStd_Array1OfListOfInteger::const_iterator (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfListOfInteger.def("Init", (void (TColStd_Array1OfListOfInteger::*)(const TColStd_ListOfInteger &)) &TColStd_Array1OfListOfInteger::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColStd_Array1OfListOfInteger.def("Size", (Standard_Integer (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::Size, "Size query");
	cls_TColStd_Array1OfListOfInteger.def("Length", (Standard_Integer (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::Length, "Length query (the same)");
	cls_TColStd_Array1OfListOfInteger.def("IsEmpty", (Standard_Boolean (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColStd_Array1OfListOfInteger.def("Lower", (Standard_Integer (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::Lower, "Lower bound");
	cls_TColStd_Array1OfListOfInteger.def("Upper", (Standard_Integer (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::Upper, "Upper bound");
	cls_TColStd_Array1OfListOfInteger.def("IsDeletable", (Standard_Boolean (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::IsDeletable, "myDeletable flag");
	cls_TColStd_Array1OfListOfInteger.def("IsAllocated", (Standard_Boolean (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColStd_Array1OfListOfInteger.def("Assign", (TColStd_Array1OfListOfInteger & (TColStd_Array1OfListOfInteger::*)(const TColStd_Array1OfListOfInteger &)) &TColStd_Array1OfListOfInteger::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfListOfInteger.def("Move", (TColStd_Array1OfListOfInteger & (TColStd_Array1OfListOfInteger::*)(TColStd_Array1OfListOfInteger &&)) &TColStd_Array1OfListOfInteger::Move, "Move assignment", py::arg("theOther"));
	cls_TColStd_Array1OfListOfInteger.def("assign", (TColStd_Array1OfListOfInteger & (TColStd_Array1OfListOfInteger::*)(const TColStd_Array1OfListOfInteger &)) &TColStd_Array1OfListOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfListOfInteger.def("assign", (TColStd_Array1OfListOfInteger & (TColStd_Array1OfListOfInteger::*)(TColStd_Array1OfListOfInteger &&)) &TColStd_Array1OfListOfInteger::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColStd_Array1OfListOfInteger.def("First", (const TColStd_ListOfInteger & (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::First, "Returns first element");
	cls_TColStd_Array1OfListOfInteger.def("ChangeFirst", (TColStd_ListOfInteger & (TColStd_Array1OfListOfInteger::*)()) &TColStd_Array1OfListOfInteger::ChangeFirst, "Returns first element");
	cls_TColStd_Array1OfListOfInteger.def("Last", (const TColStd_ListOfInteger & (TColStd_Array1OfListOfInteger::*)() const ) &TColStd_Array1OfListOfInteger::Last, "Returns last element");
	cls_TColStd_Array1OfListOfInteger.def("ChangeLast", (TColStd_ListOfInteger & (TColStd_Array1OfListOfInteger::*)()) &TColStd_Array1OfListOfInteger::ChangeLast, "Returns last element");
	cls_TColStd_Array1OfListOfInteger.def("Value", (const TColStd_ListOfInteger & (TColStd_Array1OfListOfInteger::*)(const Standard_Integer) const ) &TColStd_Array1OfListOfInteger::Value, "Constant value access", py::arg("theIndex"));
	cls_TColStd_Array1OfListOfInteger.def("__call__", (const TColStd_ListOfInteger & (TColStd_Array1OfListOfInteger::*)(const Standard_Integer) const ) &TColStd_Array1OfListOfInteger::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColStd_Array1OfListOfInteger.def("ChangeValue", (TColStd_ListOfInteger & (TColStd_Array1OfListOfInteger::*)(const Standard_Integer)) &TColStd_Array1OfListOfInteger::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColStd_Array1OfListOfInteger.def("__call__", (TColStd_ListOfInteger & (TColStd_Array1OfListOfInteger::*)(const Standard_Integer)) &TColStd_Array1OfListOfInteger::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColStd_Array1OfListOfInteger.def("SetValue", (void (TColStd_Array1OfListOfInteger::*)(const Standard_Integer, const TColStd_ListOfInteger &)) &TColStd_Array1OfListOfInteger::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_Array1OfListOfInteger.def("Resize", (void (TColStd_Array1OfListOfInteger::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColStd_Array1OfListOfInteger::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColStd_Array1OfListOfInteger.def("__iter__", [](const TColStd_Array1OfListOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_PackedMapOfInteger.hxx
	py::class_<TColStd_PackedMapOfInteger, std::unique_ptr<TColStd_PackedMapOfInteger, Deleter<TColStd_PackedMapOfInteger>>> cls_TColStd_PackedMapOfInteger(mod, "TColStd_PackedMapOfInteger", "Optimized Map of integer values. Each block of 32 integers is stored in 8 bytes in memory.");
	cls_TColStd_PackedMapOfInteger.def(py::init<>());
	cls_TColStd_PackedMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_PackedMapOfInteger.def(py::init([] (const TColStd_PackedMapOfInteger &other) {return new TColStd_PackedMapOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_PackedMapOfInteger.def("assign", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_TColStd_PackedMapOfInteger.def("Assign", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Assign, "None", py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("ReSize", (void (TColStd_PackedMapOfInteger::*)(const Standard_Integer)) &TColStd_PackedMapOfInteger::ReSize, "None", py::arg("NbBuckets"));
	cls_TColStd_PackedMapOfInteger.def("Clear", (void (TColStd_PackedMapOfInteger::*)()) &TColStd_PackedMapOfInteger::Clear, "None");
	cls_TColStd_PackedMapOfInteger.def("Add", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const Standard_Integer)) &TColStd_PackedMapOfInteger::Add, "None", py::arg("aKey"));
	cls_TColStd_PackedMapOfInteger.def("Contains", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const Standard_Integer) const ) &TColStd_PackedMapOfInteger::Contains, "None", py::arg("aKey"));
	cls_TColStd_PackedMapOfInteger.def("Remove", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const Standard_Integer)) &TColStd_PackedMapOfInteger::Remove, "None", py::arg("aKey"));
	cls_TColStd_PackedMapOfInteger.def("NbBuckets", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const ) &TColStd_PackedMapOfInteger::NbBuckets, "None");
	cls_TColStd_PackedMapOfInteger.def("Extent", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const ) &TColStd_PackedMapOfInteger::Extent, "None");
	cls_TColStd_PackedMapOfInteger.def("IsEmpty", (Standard_Boolean (TColStd_PackedMapOfInteger::*)() const ) &TColStd_PackedMapOfInteger::IsEmpty, "None");
	cls_TColStd_PackedMapOfInteger.def("Statistics", (void (TColStd_PackedMapOfInteger::*)(Standard_OStream &) const ) &TColStd_PackedMapOfInteger::Statistics, "None", py::arg("outStream"));
	cls_TColStd_PackedMapOfInteger.def("GetMinimalMapped", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const ) &TColStd_PackedMapOfInteger::GetMinimalMapped, "Query the minimal contained key value.");
	cls_TColStd_PackedMapOfInteger.def("GetMaximalMapped", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const ) &TColStd_PackedMapOfInteger::GetMaximalMapped, "Query the maximal contained key value.");
	cls_TColStd_PackedMapOfInteger.def("Union", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps. The new Map contains the values that are contained either in the first map or in the second map or in both. All previous contents of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg(""), py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("Unite", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union().", py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("operator|=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator|=, "Overloaded operator version of Unite().", py::arg("MM"));
	cls_TColStd_PackedMapOfInteger.def("Intersection", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous contents of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands. The order of operands makes no difference; the method minimizes internally the number of iterations using the smallest map for the loop.", py::arg(""), py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("Intersect", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection().", py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("operator&=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator&=, "Overloaded operator version of Intersect().", py::arg("MM"));
	cls_TColStd_PackedMapOfInteger.def("Subtraction", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous contents of this Map is cleared. This map (result of the boolean operation) can also be used as the first operand.", py::arg(""), py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("Subtract", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands.", py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("__isub__", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator-=, "Overloaded operator version of Subtract().", py::arg("MM"));
	cls_TColStd_PackedMapOfInteger.def("Difference", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous contents of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg(""), py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("Differ", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference().", py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("operator^=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator^=, "Overloaded operator version of Differ().", py::arg("MM"));
	cls_TColStd_PackedMapOfInteger.def("IsEqual", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const ) &TColStd_PackedMapOfInteger::IsEqual, "Returns True if this map is equal to the given one, i.e. they contain the same sets of elements", py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("__eq__", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const ) &TColStd_PackedMapOfInteger::operator==, py::is_operator(), "Overloaded operator version of IsEqual().", py::arg("MM"));
	cls_TColStd_PackedMapOfInteger.def("IsSubset", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const ) &TColStd_PackedMapOfInteger::IsSubset, "Returns True if this map is subset of the given one, i.e. all elements contained in this map is contained also in the operand map. if this map is empty that this method returns true for any operand map.", py::arg(""));
	cls_TColStd_PackedMapOfInteger.def("__le__", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const ) &TColStd_PackedMapOfInteger::operator<=, py::is_operator(), "Overloaded operator version of IsSubset().", py::arg("MM"));
	cls_TColStd_PackedMapOfInteger.def("HasIntersection", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const ) &TColStd_PackedMapOfInteger::HasIntersection, "Returns True if this map has common items with the given one.", py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColStd_Array1OfBoolean, std::unique_ptr<TColStd_Array1OfBoolean, Deleter<TColStd_Array1OfBoolean>>> cls_TColStd_Array1OfBoolean(mod, "TColStd_Array1OfBoolean", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColStd_Array1OfBoolean.def(py::init<>());
	cls_TColStd_Array1OfBoolean.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfBoolean.def(py::init([] (const TColStd_Array1OfBoolean &other) {return new TColStd_Array1OfBoolean(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColStd_Array1OfBoolean.def(py::init<TColStd_Array1OfBoolean &&>(), py::arg("theOther"));
	cls_TColStd_Array1OfBoolean.def(py::init<const Standard_Boolean &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfBoolean.def("begin", (TColStd_Array1OfBoolean::iterator (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfBoolean.def("end", (TColStd_Array1OfBoolean::iterator (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfBoolean.def("cbegin", (TColStd_Array1OfBoolean::const_iterator (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfBoolean.def("cend", (TColStd_Array1OfBoolean::const_iterator (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfBoolean.def("Init", (void (TColStd_Array1OfBoolean::*)(const Standard_Boolean &)) &TColStd_Array1OfBoolean::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColStd_Array1OfBoolean.def("Size", (Standard_Integer (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::Size, "Size query");
	cls_TColStd_Array1OfBoolean.def("Length", (Standard_Integer (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::Length, "Length query (the same)");
	cls_TColStd_Array1OfBoolean.def("IsEmpty", (Standard_Boolean (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColStd_Array1OfBoolean.def("Lower", (Standard_Integer (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::Lower, "Lower bound");
	cls_TColStd_Array1OfBoolean.def("Upper", (Standard_Integer (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::Upper, "Upper bound");
	cls_TColStd_Array1OfBoolean.def("IsDeletable", (Standard_Boolean (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::IsDeletable, "myDeletable flag");
	cls_TColStd_Array1OfBoolean.def("IsAllocated", (Standard_Boolean (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColStd_Array1OfBoolean.def("Assign", (TColStd_Array1OfBoolean & (TColStd_Array1OfBoolean::*)(const TColStd_Array1OfBoolean &)) &TColStd_Array1OfBoolean::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfBoolean.def("Move", (TColStd_Array1OfBoolean & (TColStd_Array1OfBoolean::*)(TColStd_Array1OfBoolean &&)) &TColStd_Array1OfBoolean::Move, "Move assignment", py::arg("theOther"));
	cls_TColStd_Array1OfBoolean.def("assign", (TColStd_Array1OfBoolean & (TColStd_Array1OfBoolean::*)(const TColStd_Array1OfBoolean &)) &TColStd_Array1OfBoolean::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfBoolean.def("assign", (TColStd_Array1OfBoolean & (TColStd_Array1OfBoolean::*)(TColStd_Array1OfBoolean &&)) &TColStd_Array1OfBoolean::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColStd_Array1OfBoolean.def("First", (const Standard_Boolean & (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::First, "Returns first element");
	cls_TColStd_Array1OfBoolean.def("ChangeFirst", (Standard_Boolean & (TColStd_Array1OfBoolean::*)()) &TColStd_Array1OfBoolean::ChangeFirst, "Returns first element");
	cls_TColStd_Array1OfBoolean.def("Last", (const Standard_Boolean & (TColStd_Array1OfBoolean::*)() const ) &TColStd_Array1OfBoolean::Last, "Returns last element");
	cls_TColStd_Array1OfBoolean.def("ChangeLast", (Standard_Boolean & (TColStd_Array1OfBoolean::*)()) &TColStd_Array1OfBoolean::ChangeLast, "Returns last element");
	cls_TColStd_Array1OfBoolean.def("Value", (const Standard_Boolean & (TColStd_Array1OfBoolean::*)(const Standard_Integer) const ) &TColStd_Array1OfBoolean::Value, "Constant value access", py::arg("theIndex"));
	cls_TColStd_Array1OfBoolean.def("__call__", (const Standard_Boolean & (TColStd_Array1OfBoolean::*)(const Standard_Integer) const ) &TColStd_Array1OfBoolean::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColStd_Array1OfBoolean.def("ChangeValue", (Standard_Boolean & (TColStd_Array1OfBoolean::*)(const Standard_Integer)) &TColStd_Array1OfBoolean::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColStd_Array1OfBoolean.def("__call__", (Standard_Boolean & (TColStd_Array1OfBoolean::*)(const Standard_Integer)) &TColStd_Array1OfBoolean::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColStd_Array1OfBoolean.def("SetValue", (void (TColStd_Array1OfBoolean::*)(const Standard_Integer, const Standard_Boolean &)) &TColStd_Array1OfBoolean::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_Array1OfBoolean.def("Resize", (void (TColStd_Array1OfBoolean::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColStd_Array1OfBoolean::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColStd_Array1OfBoolean.def("__iter__", [](const TColStd_Array1OfBoolean &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColStd_SequenceOfInteger, std::unique_ptr<TColStd_SequenceOfInteger, Deleter<TColStd_SequenceOfInteger>>, NCollection_BaseSequence> cls_TColStd_SequenceOfInteger(mod, "TColStd_SequenceOfInteger", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColStd_SequenceOfInteger.def(py::init<>());
	cls_TColStd_SequenceOfInteger.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_SequenceOfInteger.def(py::init([] (const TColStd_SequenceOfInteger &other) {return new TColStd_SequenceOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_SequenceOfInteger.def("begin", (TColStd_SequenceOfInteger::iterator (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfInteger.def("end", (TColStd_SequenceOfInteger::iterator (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfInteger.def("cbegin", (TColStd_SequenceOfInteger::const_iterator (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfInteger.def("cend", (TColStd_SequenceOfInteger::const_iterator (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfInteger.def("Size", (Standard_Integer (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::Size, "Number of items");
	cls_TColStd_SequenceOfInteger.def("Length", (Standard_Integer (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::Length, "Number of items");
	cls_TColStd_SequenceOfInteger.def("Lower", (Standard_Integer (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::Lower, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfInteger.def("Upper", (Standard_Integer (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::Upper, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfInteger.def("IsEmpty", (Standard_Boolean (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::IsEmpty, "Empty query");
	cls_TColStd_SequenceOfInteger.def("Reverse", (void (TColStd_SequenceOfInteger::*)()) &TColStd_SequenceOfInteger::Reverse, "Reverse sequence");
	cls_TColStd_SequenceOfInteger.def("Exchange", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfInteger::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColStd_SequenceOfInteger.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfInteger::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColStd_SequenceOfInteger.def("Clear", [](TColStd_SequenceOfInteger &self) -> void { return self.Clear(); });
	cls_TColStd_SequenceOfInteger.def("Clear", (void (TColStd_SequenceOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfInteger::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColStd_SequenceOfInteger.def("Assign", (TColStd_SequenceOfInteger & (TColStd_SequenceOfInteger::*)(const TColStd_SequenceOfInteger &)) &TColStd_SequenceOfInteger::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_SequenceOfInteger.def("assign", (TColStd_SequenceOfInteger & (TColStd_SequenceOfInteger::*)(const TColStd_SequenceOfInteger &)) &TColStd_SequenceOfInteger::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_SequenceOfInteger.def("Remove", (void (TColStd_SequenceOfInteger::*)(TColStd_SequenceOfInteger::Iterator &)) &TColStd_SequenceOfInteger::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColStd_SequenceOfInteger.def("Remove", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer)) &TColStd_SequenceOfInteger::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColStd_SequenceOfInteger.def("Remove", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfInteger::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColStd_SequenceOfInteger.def("Append", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer &)) &TColStd_SequenceOfInteger::Append, "Append one item", py::arg("theItem"));
	cls_TColStd_SequenceOfInteger.def("Append", (void (TColStd_SequenceOfInteger::*)(TColStd_SequenceOfInteger &)) &TColStd_SequenceOfInteger::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfInteger.def("Prepend", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer &)) &TColStd_SequenceOfInteger::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColStd_SequenceOfInteger.def("Prepend", (void (TColStd_SequenceOfInteger::*)(TColStd_SequenceOfInteger &)) &TColStd_SequenceOfInteger::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfInteger.def("InsertBefore", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer, const Standard_Integer &)) &TColStd_SequenceOfInteger::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfInteger.def("InsertBefore", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer, TColStd_SequenceOfInteger &)) &TColStd_SequenceOfInteger::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfInteger.def("InsertAfter", (void (TColStd_SequenceOfInteger::*)(TColStd_SequenceOfInteger::Iterator &, const Standard_Integer &)) &TColStd_SequenceOfInteger::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColStd_SequenceOfInteger.def("InsertAfter", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer, TColStd_SequenceOfInteger &)) &TColStd_SequenceOfInteger::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfInteger.def("InsertAfter", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer, const Standard_Integer &)) &TColStd_SequenceOfInteger::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfInteger.def("Split", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer, TColStd_SequenceOfInteger &)) &TColStd_SequenceOfInteger::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfInteger.def("First", (const Standard_Integer & (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::First, "First item access");
	cls_TColStd_SequenceOfInteger.def("ChangeFirst", (Standard_Integer & (TColStd_SequenceOfInteger::*)()) &TColStd_SequenceOfInteger::ChangeFirst, "First item access");
	cls_TColStd_SequenceOfInteger.def("Last", (const Standard_Integer & (TColStd_SequenceOfInteger::*)() const ) &TColStd_SequenceOfInteger::Last, "Last item access");
	cls_TColStd_SequenceOfInteger.def("ChangeLast", (Standard_Integer & (TColStd_SequenceOfInteger::*)()) &TColStd_SequenceOfInteger::ChangeLast, "Last item access");
	cls_TColStd_SequenceOfInteger.def("Value", (const Standard_Integer & (TColStd_SequenceOfInteger::*)(const Standard_Integer) const ) &TColStd_SequenceOfInteger::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfInteger.def("__call__", (const Standard_Integer & (TColStd_SequenceOfInteger::*)(const Standard_Integer) const ) &TColStd_SequenceOfInteger::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfInteger.def("ChangeValue", (Standard_Integer & (TColStd_SequenceOfInteger::*)(const Standard_Integer)) &TColStd_SequenceOfInteger::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfInteger.def("__call__", (Standard_Integer & (TColStd_SequenceOfInteger::*)(const Standard_Integer)) &TColStd_SequenceOfInteger::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfInteger.def("SetValue", (void (TColStd_SequenceOfInteger::*)(const Standard_Integer, const Standard_Integer &)) &TColStd_SequenceOfInteger::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfInteger.def("__iter__", [](const TColStd_SequenceOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColStd_Array1OfTransient, std::unique_ptr<TColStd_Array1OfTransient, Deleter<TColStd_Array1OfTransient>>> cls_TColStd_Array1OfTransient(mod, "TColStd_Array1OfTransient", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColStd_Array1OfTransient.def(py::init<>());
	cls_TColStd_Array1OfTransient.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfTransient.def(py::init([] (const TColStd_Array1OfTransient &other) {return new TColStd_Array1OfTransient(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColStd_Array1OfTransient.def(py::init<TColStd_Array1OfTransient &&>(), py::arg("theOther"));
	cls_TColStd_Array1OfTransient.def(py::init<const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfTransient.def("begin", (TColStd_Array1OfTransient::iterator (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfTransient.def("end", (TColStd_Array1OfTransient::iterator (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfTransient.def("cbegin", (TColStd_Array1OfTransient::const_iterator (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfTransient.def("cend", (TColStd_Array1OfTransient::const_iterator (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfTransient.def("Init", (void (TColStd_Array1OfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_Array1OfTransient::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColStd_Array1OfTransient.def("Size", (Standard_Integer (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::Size, "Size query");
	cls_TColStd_Array1OfTransient.def("Length", (Standard_Integer (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::Length, "Length query (the same)");
	cls_TColStd_Array1OfTransient.def("IsEmpty", (Standard_Boolean (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColStd_Array1OfTransient.def("Lower", (Standard_Integer (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::Lower, "Lower bound");
	cls_TColStd_Array1OfTransient.def("Upper", (Standard_Integer (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::Upper, "Upper bound");
	cls_TColStd_Array1OfTransient.def("IsDeletable", (Standard_Boolean (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::IsDeletable, "myDeletable flag");
	cls_TColStd_Array1OfTransient.def("IsAllocated", (Standard_Boolean (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColStd_Array1OfTransient.def("Assign", (TColStd_Array1OfTransient & (TColStd_Array1OfTransient::*)(const TColStd_Array1OfTransient &)) &TColStd_Array1OfTransient::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfTransient.def("Move", (TColStd_Array1OfTransient & (TColStd_Array1OfTransient::*)(TColStd_Array1OfTransient &&)) &TColStd_Array1OfTransient::Move, "Move assignment", py::arg("theOther"));
	cls_TColStd_Array1OfTransient.def("assign", (TColStd_Array1OfTransient & (TColStd_Array1OfTransient::*)(const TColStd_Array1OfTransient &)) &TColStd_Array1OfTransient::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfTransient.def("assign", (TColStd_Array1OfTransient & (TColStd_Array1OfTransient::*)(TColStd_Array1OfTransient &&)) &TColStd_Array1OfTransient::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColStd_Array1OfTransient.def("First", (const opencascade::handle<Standard_Transient> & (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::First, "Returns first element");
	cls_TColStd_Array1OfTransient.def("ChangeFirst", (opencascade::handle<Standard_Transient> & (TColStd_Array1OfTransient::*)()) &TColStd_Array1OfTransient::ChangeFirst, "Returns first element");
	cls_TColStd_Array1OfTransient.def("Last", (const opencascade::handle<Standard_Transient> & (TColStd_Array1OfTransient::*)() const ) &TColStd_Array1OfTransient::Last, "Returns last element");
	cls_TColStd_Array1OfTransient.def("ChangeLast", (opencascade::handle<Standard_Transient> & (TColStd_Array1OfTransient::*)()) &TColStd_Array1OfTransient::ChangeLast, "Returns last element");
	cls_TColStd_Array1OfTransient.def("Value", (const opencascade::handle<Standard_Transient> & (TColStd_Array1OfTransient::*)(const Standard_Integer) const ) &TColStd_Array1OfTransient::Value, "Constant value access", py::arg("theIndex"));
	cls_TColStd_Array1OfTransient.def("__call__", (const opencascade::handle<Standard_Transient> & (TColStd_Array1OfTransient::*)(const Standard_Integer) const ) &TColStd_Array1OfTransient::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColStd_Array1OfTransient.def("ChangeValue", (opencascade::handle<Standard_Transient> & (TColStd_Array1OfTransient::*)(const Standard_Integer)) &TColStd_Array1OfTransient::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColStd_Array1OfTransient.def("__call__", (opencascade::handle<Standard_Transient> & (TColStd_Array1OfTransient::*)(const Standard_Integer)) &TColStd_Array1OfTransient::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColStd_Array1OfTransient.def("SetValue", (void (TColStd_Array1OfTransient::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &TColStd_Array1OfTransient::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_Array1OfTransient.def("Resize", (void (TColStd_Array1OfTransient::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColStd_Array1OfTransient::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColStd_Array1OfTransient.def("__iter__", [](const TColStd_Array1OfTransient &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColStd_SequenceOfTransient, std::unique_ptr<TColStd_SequenceOfTransient, Deleter<TColStd_SequenceOfTransient>>, NCollection_BaseSequence> cls_TColStd_SequenceOfTransient(mod, "TColStd_SequenceOfTransient", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColStd_SequenceOfTransient.def(py::init<>());
	cls_TColStd_SequenceOfTransient.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_SequenceOfTransient.def(py::init([] (const TColStd_SequenceOfTransient &other) {return new TColStd_SequenceOfTransient(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_SequenceOfTransient.def("begin", (TColStd_SequenceOfTransient::iterator (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfTransient.def("end", (TColStd_SequenceOfTransient::iterator (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfTransient.def("cbegin", (TColStd_SequenceOfTransient::const_iterator (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfTransient.def("cend", (TColStd_SequenceOfTransient::const_iterator (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfTransient.def("Size", (Standard_Integer (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::Size, "Number of items");
	cls_TColStd_SequenceOfTransient.def("Length", (Standard_Integer (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::Length, "Number of items");
	cls_TColStd_SequenceOfTransient.def("Lower", (Standard_Integer (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::Lower, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfTransient.def("Upper", (Standard_Integer (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::Upper, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfTransient.def("IsEmpty", (Standard_Boolean (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::IsEmpty, "Empty query");
	cls_TColStd_SequenceOfTransient.def("Reverse", (void (TColStd_SequenceOfTransient::*)()) &TColStd_SequenceOfTransient::Reverse, "Reverse sequence");
	cls_TColStd_SequenceOfTransient.def("Exchange", (void (TColStd_SequenceOfTransient::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfTransient::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColStd_SequenceOfTransient.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfTransient::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColStd_SequenceOfTransient.def("Clear", [](TColStd_SequenceOfTransient &self) -> void { return self.Clear(); });
	cls_TColStd_SequenceOfTransient.def("Clear", (void (TColStd_SequenceOfTransient::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfTransient::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColStd_SequenceOfTransient.def("Assign", (TColStd_SequenceOfTransient & (TColStd_SequenceOfTransient::*)(const TColStd_SequenceOfTransient &)) &TColStd_SequenceOfTransient::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_SequenceOfTransient.def("assign", (TColStd_SequenceOfTransient & (TColStd_SequenceOfTransient::*)(const TColStd_SequenceOfTransient &)) &TColStd_SequenceOfTransient::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_SequenceOfTransient.def("Remove", (void (TColStd_SequenceOfTransient::*)(TColStd_SequenceOfTransient::Iterator &)) &TColStd_SequenceOfTransient::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColStd_SequenceOfTransient.def("Remove", (void (TColStd_SequenceOfTransient::*)(const Standard_Integer)) &TColStd_SequenceOfTransient::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColStd_SequenceOfTransient.def("Remove", (void (TColStd_SequenceOfTransient::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfTransient::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColStd_SequenceOfTransient.def("Append", (void (TColStd_SequenceOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_SequenceOfTransient::Append, "Append one item", py::arg("theItem"));
	cls_TColStd_SequenceOfTransient.def("Append", (void (TColStd_SequenceOfTransient::*)(TColStd_SequenceOfTransient &)) &TColStd_SequenceOfTransient::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfTransient.def("Prepend", (void (TColStd_SequenceOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_SequenceOfTransient::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColStd_SequenceOfTransient.def("Prepend", (void (TColStd_SequenceOfTransient::*)(TColStd_SequenceOfTransient &)) &TColStd_SequenceOfTransient::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfTransient.def("InsertBefore", (void (TColStd_SequenceOfTransient::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &TColStd_SequenceOfTransient::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfTransient.def("InsertBefore", (void (TColStd_SequenceOfTransient::*)(const Standard_Integer, TColStd_SequenceOfTransient &)) &TColStd_SequenceOfTransient::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfTransient.def("InsertAfter", (void (TColStd_SequenceOfTransient::*)(TColStd_SequenceOfTransient::Iterator &, const opencascade::handle<Standard_Transient> &)) &TColStd_SequenceOfTransient::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColStd_SequenceOfTransient.def("InsertAfter", (void (TColStd_SequenceOfTransient::*)(const Standard_Integer, TColStd_SequenceOfTransient &)) &TColStd_SequenceOfTransient::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfTransient.def("InsertAfter", (void (TColStd_SequenceOfTransient::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &TColStd_SequenceOfTransient::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfTransient.def("Split", (void (TColStd_SequenceOfTransient::*)(const Standard_Integer, TColStd_SequenceOfTransient &)) &TColStd_SequenceOfTransient::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfTransient.def("First", (const opencascade::handle<Standard_Transient> & (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::First, "First item access");
	cls_TColStd_SequenceOfTransient.def("ChangeFirst", (opencascade::handle<Standard_Transient> & (TColStd_SequenceOfTransient::*)()) &TColStd_SequenceOfTransient::ChangeFirst, "First item access");
	cls_TColStd_SequenceOfTransient.def("Last", (const opencascade::handle<Standard_Transient> & (TColStd_SequenceOfTransient::*)() const ) &TColStd_SequenceOfTransient::Last, "Last item access");
	cls_TColStd_SequenceOfTransient.def("ChangeLast", (opencascade::handle<Standard_Transient> & (TColStd_SequenceOfTransient::*)()) &TColStd_SequenceOfTransient::ChangeLast, "Last item access");
	cls_TColStd_SequenceOfTransient.def("Value", (const opencascade::handle<Standard_Transient> & (TColStd_SequenceOfTransient::*)(const Standard_Integer) const ) &TColStd_SequenceOfTransient::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfTransient.def("__call__", (const opencascade::handle<Standard_Transient> & (TColStd_SequenceOfTransient::*)(const Standard_Integer) const ) &TColStd_SequenceOfTransient::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfTransient.def("ChangeValue", (opencascade::handle<Standard_Transient> & (TColStd_SequenceOfTransient::*)(const Standard_Integer)) &TColStd_SequenceOfTransient::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfTransient.def("__call__", (opencascade::handle<Standard_Transient> & (TColStd_SequenceOfTransient::*)(const Standard_Integer)) &TColStd_SequenceOfTransient::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfTransient.def("SetValue", (void (TColStd_SequenceOfTransient::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &TColStd_SequenceOfTransient::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfTransient.def("__iter__", [](const TColStd_SequenceOfTransient &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColStd_Array2OfTransient, std::unique_ptr<TColStd_Array2OfTransient, Deleter<TColStd_Array2OfTransient>>> cls_TColStd_Array2OfTransient(mod, "TColStd_Array2OfTransient", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColStd_Array2OfTransient.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColStd_Array2OfTransient.def(py::init([] (const TColStd_Array2OfTransient &other) {return new TColStd_Array2OfTransient(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_Array2OfTransient.def(py::init<const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColStd_Array2OfTransient.def("Init", (void (TColStd_Array2OfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_Array2OfTransient::Init, "Initialise the values", py::arg("theValue"));
	cls_TColStd_Array2OfTransient.def("Size", (Standard_Integer (TColStd_Array2OfTransient::*)() const ) &TColStd_Array2OfTransient::Size, "Size (number of items)");
	cls_TColStd_Array2OfTransient.def("Length", (Standard_Integer (TColStd_Array2OfTransient::*)() const ) &TColStd_Array2OfTransient::Length, "Length (number of items)");
	cls_TColStd_Array2OfTransient.def("RowLength", (Standard_Integer (TColStd_Array2OfTransient::*)() const ) &TColStd_Array2OfTransient::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColStd_Array2OfTransient.def("ColLength", (Standard_Integer (TColStd_Array2OfTransient::*)() const ) &TColStd_Array2OfTransient::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColStd_Array2OfTransient.def("LowerRow", (Standard_Integer (TColStd_Array2OfTransient::*)() const ) &TColStd_Array2OfTransient::LowerRow, "LowerRow");
	cls_TColStd_Array2OfTransient.def("UpperRow", (Standard_Integer (TColStd_Array2OfTransient::*)() const ) &TColStd_Array2OfTransient::UpperRow, "UpperRow");
	cls_TColStd_Array2OfTransient.def("LowerCol", (Standard_Integer (TColStd_Array2OfTransient::*)() const ) &TColStd_Array2OfTransient::LowerCol, "LowerCol");
	cls_TColStd_Array2OfTransient.def("UpperCol", (Standard_Integer (TColStd_Array2OfTransient::*)() const ) &TColStd_Array2OfTransient::UpperCol, "UpperCol");
	cls_TColStd_Array2OfTransient.def("IsDeletable", (Standard_Boolean (TColStd_Array2OfTransient::*)() const ) &TColStd_Array2OfTransient::IsDeletable, "myDeletable flag");
	cls_TColStd_Array2OfTransient.def("Assign", (TColStd_Array2OfTransient & (TColStd_Array2OfTransient::*)(const TColStd_Array2OfTransient &)) &TColStd_Array2OfTransient::Assign, "Assignment", py::arg("theOther"));
	cls_TColStd_Array2OfTransient.def("assign", (TColStd_Array2OfTransient & (TColStd_Array2OfTransient::*)(const TColStd_Array2OfTransient &)) &TColStd_Array2OfTransient::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_Array2OfTransient.def("Value", (const opencascade::handle<Standard_Transient> & (TColStd_Array2OfTransient::*)(const Standard_Integer, const Standard_Integer) const ) &TColStd_Array2OfTransient::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfTransient.def("__call__", (const opencascade::handle<Standard_Transient> & (TColStd_Array2OfTransient::*)(const Standard_Integer, const Standard_Integer) const ) &TColStd_Array2OfTransient::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfTransient.def("ChangeValue", (opencascade::handle<Standard_Transient> & (TColStd_Array2OfTransient::*)(const Standard_Integer, const Standard_Integer)) &TColStd_Array2OfTransient::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfTransient.def("__call__", (opencascade::handle<Standard_Transient> & (TColStd_Array2OfTransient::*)(const Standard_Integer, const Standard_Integer)) &TColStd_Array2OfTransient::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfTransient.def("SetValue", (void (TColStd_Array2OfTransient::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &TColStd_Array2OfTransient::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HPackedMapOfInteger.hxx
	py::class_<TColStd_HPackedMapOfInteger, opencascade::handle<TColStd_HPackedMapOfInteger>, Standard_Transient> cls_TColStd_HPackedMapOfInteger(mod, "TColStd_HPackedMapOfInteger", "Extension of TColStd_PackedMapOfInteger class to be manipulated by handle.");
	cls_TColStd_HPackedMapOfInteger.def(py::init<>());
	cls_TColStd_HPackedMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_HPackedMapOfInteger.def(py::init<const TColStd_PackedMapOfInteger &>(), py::arg("theOther"));
	cls_TColStd_HPackedMapOfInteger.def("Map", (const TColStd_PackedMapOfInteger & (TColStd_HPackedMapOfInteger::*)() const ) &TColStd_HPackedMapOfInteger::Map, "Access to the map");
	cls_TColStd_HPackedMapOfInteger.def("ChangeMap", (TColStd_PackedMapOfInteger & (TColStd_HPackedMapOfInteger::*)()) &TColStd_HPackedMapOfInteger::ChangeMap, "Access to the map for modification");
	cls_TColStd_HPackedMapOfInteger.def_static("get_type_name_", (const char * (*)()) &TColStd_HPackedMapOfInteger::get_type_name, "None");
	cls_TColStd_HPackedMapOfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HPackedMapOfInteger::get_type_descriptor, "None");
	cls_TColStd_HPackedMapOfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HPackedMapOfInteger::*)() const ) &TColStd_HPackedMapOfInteger::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColStd_Array1OfAsciiString, std::unique_ptr<TColStd_Array1OfAsciiString, Deleter<TColStd_Array1OfAsciiString>>> cls_TColStd_Array1OfAsciiString(mod, "TColStd_Array1OfAsciiString", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColStd_Array1OfAsciiString.def(py::init<>());
	cls_TColStd_Array1OfAsciiString.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfAsciiString.def(py::init([] (const TColStd_Array1OfAsciiString &other) {return new TColStd_Array1OfAsciiString(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColStd_Array1OfAsciiString.def(py::init<TColStd_Array1OfAsciiString &&>(), py::arg("theOther"));
	cls_TColStd_Array1OfAsciiString.def(py::init<const TCollection_AsciiString &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfAsciiString.def("begin", (TColStd_Array1OfAsciiString::iterator (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfAsciiString.def("end", (TColStd_Array1OfAsciiString::iterator (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfAsciiString.def("cbegin", (TColStd_Array1OfAsciiString::const_iterator (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfAsciiString.def("cend", (TColStd_Array1OfAsciiString::const_iterator (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfAsciiString.def("Init", (void (TColStd_Array1OfAsciiString::*)(const TCollection_AsciiString &)) &TColStd_Array1OfAsciiString::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColStd_Array1OfAsciiString.def("Size", (Standard_Integer (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::Size, "Size query");
	cls_TColStd_Array1OfAsciiString.def("Length", (Standard_Integer (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::Length, "Length query (the same)");
	cls_TColStd_Array1OfAsciiString.def("IsEmpty", (Standard_Boolean (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColStd_Array1OfAsciiString.def("Lower", (Standard_Integer (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::Lower, "Lower bound");
	cls_TColStd_Array1OfAsciiString.def("Upper", (Standard_Integer (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::Upper, "Upper bound");
	cls_TColStd_Array1OfAsciiString.def("IsDeletable", (Standard_Boolean (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::IsDeletable, "myDeletable flag");
	cls_TColStd_Array1OfAsciiString.def("IsAllocated", (Standard_Boolean (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColStd_Array1OfAsciiString.def("Assign", (TColStd_Array1OfAsciiString & (TColStd_Array1OfAsciiString::*)(const TColStd_Array1OfAsciiString &)) &TColStd_Array1OfAsciiString::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfAsciiString.def("Move", (TColStd_Array1OfAsciiString & (TColStd_Array1OfAsciiString::*)(TColStd_Array1OfAsciiString &&)) &TColStd_Array1OfAsciiString::Move, "Move assignment", py::arg("theOther"));
	cls_TColStd_Array1OfAsciiString.def("assign", (TColStd_Array1OfAsciiString & (TColStd_Array1OfAsciiString::*)(const TColStd_Array1OfAsciiString &)) &TColStd_Array1OfAsciiString::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfAsciiString.def("assign", (TColStd_Array1OfAsciiString & (TColStd_Array1OfAsciiString::*)(TColStd_Array1OfAsciiString &&)) &TColStd_Array1OfAsciiString::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColStd_Array1OfAsciiString.def("First", (const TCollection_AsciiString & (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::First, "Returns first element");
	cls_TColStd_Array1OfAsciiString.def("ChangeFirst", (TCollection_AsciiString & (TColStd_Array1OfAsciiString::*)()) &TColStd_Array1OfAsciiString::ChangeFirst, "Returns first element");
	cls_TColStd_Array1OfAsciiString.def("Last", (const TCollection_AsciiString & (TColStd_Array1OfAsciiString::*)() const ) &TColStd_Array1OfAsciiString::Last, "Returns last element");
	cls_TColStd_Array1OfAsciiString.def("ChangeLast", (TCollection_AsciiString & (TColStd_Array1OfAsciiString::*)()) &TColStd_Array1OfAsciiString::ChangeLast, "Returns last element");
	cls_TColStd_Array1OfAsciiString.def("Value", (const TCollection_AsciiString & (TColStd_Array1OfAsciiString::*)(const Standard_Integer) const ) &TColStd_Array1OfAsciiString::Value, "Constant value access", py::arg("theIndex"));
	cls_TColStd_Array1OfAsciiString.def("__call__", (const TCollection_AsciiString & (TColStd_Array1OfAsciiString::*)(const Standard_Integer) const ) &TColStd_Array1OfAsciiString::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColStd_Array1OfAsciiString.def("ChangeValue", (TCollection_AsciiString & (TColStd_Array1OfAsciiString::*)(const Standard_Integer)) &TColStd_Array1OfAsciiString::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColStd_Array1OfAsciiString.def("__call__", (TCollection_AsciiString & (TColStd_Array1OfAsciiString::*)(const Standard_Integer)) &TColStd_Array1OfAsciiString::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColStd_Array1OfAsciiString.def("SetValue", (void (TColStd_Array1OfAsciiString::*)(const Standard_Integer, const TCollection_AsciiString &)) &TColStd_Array1OfAsciiString::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_Array1OfAsciiString.def("Resize", (void (TColStd_Array1OfAsciiString::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColStd_Array1OfAsciiString::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColStd_Array1OfAsciiString.def("__iter__", [](const TColStd_Array1OfAsciiString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColStd_SequenceOfHExtendedString, std::unique_ptr<TColStd_SequenceOfHExtendedString, Deleter<TColStd_SequenceOfHExtendedString>>, NCollection_BaseSequence> cls_TColStd_SequenceOfHExtendedString(mod, "TColStd_SequenceOfHExtendedString", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColStd_SequenceOfHExtendedString.def(py::init<>());
	cls_TColStd_SequenceOfHExtendedString.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_SequenceOfHExtendedString.def(py::init([] (const TColStd_SequenceOfHExtendedString &other) {return new TColStd_SequenceOfHExtendedString(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_SequenceOfHExtendedString.def("begin", (TColStd_SequenceOfHExtendedString::iterator (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfHExtendedString.def("end", (TColStd_SequenceOfHExtendedString::iterator (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfHExtendedString.def("cbegin", (TColStd_SequenceOfHExtendedString::const_iterator (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfHExtendedString.def("cend", (TColStd_SequenceOfHExtendedString::const_iterator (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfHExtendedString.def("Size", (Standard_Integer (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::Size, "Number of items");
	cls_TColStd_SequenceOfHExtendedString.def("Length", (Standard_Integer (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::Length, "Number of items");
	cls_TColStd_SequenceOfHExtendedString.def("Lower", (Standard_Integer (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::Lower, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfHExtendedString.def("Upper", (Standard_Integer (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::Upper, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfHExtendedString.def("IsEmpty", (Standard_Boolean (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::IsEmpty, "Empty query");
	cls_TColStd_SequenceOfHExtendedString.def("Reverse", (void (TColStd_SequenceOfHExtendedString::*)()) &TColStd_SequenceOfHExtendedString::Reverse, "Reverse sequence");
	cls_TColStd_SequenceOfHExtendedString.def("Exchange", (void (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfHExtendedString::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColStd_SequenceOfHExtendedString.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfHExtendedString::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColStd_SequenceOfHExtendedString.def("Clear", [](TColStd_SequenceOfHExtendedString &self) -> void { return self.Clear(); });
	cls_TColStd_SequenceOfHExtendedString.def("Clear", (void (TColStd_SequenceOfHExtendedString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfHExtendedString::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColStd_SequenceOfHExtendedString.def("Assign", (TColStd_SequenceOfHExtendedString & (TColStd_SequenceOfHExtendedString::*)(const TColStd_SequenceOfHExtendedString &)) &TColStd_SequenceOfHExtendedString::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_SequenceOfHExtendedString.def("assign", (TColStd_SequenceOfHExtendedString & (TColStd_SequenceOfHExtendedString::*)(const TColStd_SequenceOfHExtendedString &)) &TColStd_SequenceOfHExtendedString::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_SequenceOfHExtendedString.def("Remove", (void (TColStd_SequenceOfHExtendedString::*)(TColStd_SequenceOfHExtendedString::Iterator &)) &TColStd_SequenceOfHExtendedString::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColStd_SequenceOfHExtendedString.def("Remove", (void (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer)) &TColStd_SequenceOfHExtendedString::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColStd_SequenceOfHExtendedString.def("Remove", (void (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfHExtendedString::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColStd_SequenceOfHExtendedString.def("Append", (void (TColStd_SequenceOfHExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &)) &TColStd_SequenceOfHExtendedString::Append, "Append one item", py::arg("theItem"));
	cls_TColStd_SequenceOfHExtendedString.def("Append", (void (TColStd_SequenceOfHExtendedString::*)(TColStd_SequenceOfHExtendedString &)) &TColStd_SequenceOfHExtendedString::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfHExtendedString.def("Prepend", (void (TColStd_SequenceOfHExtendedString::*)(const opencascade::handle<TCollection_HExtendedString> &)) &TColStd_SequenceOfHExtendedString::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColStd_SequenceOfHExtendedString.def("Prepend", (void (TColStd_SequenceOfHExtendedString::*)(TColStd_SequenceOfHExtendedString &)) &TColStd_SequenceOfHExtendedString::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfHExtendedString.def("InsertBefore", (void (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer, const opencascade::handle<TCollection_HExtendedString> &)) &TColStd_SequenceOfHExtendedString::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfHExtendedString.def("InsertBefore", (void (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer, TColStd_SequenceOfHExtendedString &)) &TColStd_SequenceOfHExtendedString::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfHExtendedString.def("InsertAfter", (void (TColStd_SequenceOfHExtendedString::*)(TColStd_SequenceOfHExtendedString::Iterator &, const opencascade::handle<TCollection_HExtendedString> &)) &TColStd_SequenceOfHExtendedString::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColStd_SequenceOfHExtendedString.def("InsertAfter", (void (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer, TColStd_SequenceOfHExtendedString &)) &TColStd_SequenceOfHExtendedString::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfHExtendedString.def("InsertAfter", (void (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer, const opencascade::handle<TCollection_HExtendedString> &)) &TColStd_SequenceOfHExtendedString::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfHExtendedString.def("Split", (void (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer, TColStd_SequenceOfHExtendedString &)) &TColStd_SequenceOfHExtendedString::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfHExtendedString.def("First", (const opencascade::handle<TCollection_HExtendedString> & (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::First, "First item access");
	cls_TColStd_SequenceOfHExtendedString.def("ChangeFirst", (opencascade::handle<TCollection_HExtendedString> & (TColStd_SequenceOfHExtendedString::*)()) &TColStd_SequenceOfHExtendedString::ChangeFirst, "First item access");
	cls_TColStd_SequenceOfHExtendedString.def("Last", (const opencascade::handle<TCollection_HExtendedString> & (TColStd_SequenceOfHExtendedString::*)() const ) &TColStd_SequenceOfHExtendedString::Last, "Last item access");
	cls_TColStd_SequenceOfHExtendedString.def("ChangeLast", (opencascade::handle<TCollection_HExtendedString> & (TColStd_SequenceOfHExtendedString::*)()) &TColStd_SequenceOfHExtendedString::ChangeLast, "Last item access");
	cls_TColStd_SequenceOfHExtendedString.def("Value", (const opencascade::handle<TCollection_HExtendedString> & (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer) const ) &TColStd_SequenceOfHExtendedString::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfHExtendedString.def("__call__", (const opencascade::handle<TCollection_HExtendedString> & (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer) const ) &TColStd_SequenceOfHExtendedString::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfHExtendedString.def("ChangeValue", (opencascade::handle<TCollection_HExtendedString> & (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer)) &TColStd_SequenceOfHExtendedString::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfHExtendedString.def("__call__", (opencascade::handle<TCollection_HExtendedString> & (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer)) &TColStd_SequenceOfHExtendedString::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfHExtendedString.def("SetValue", (void (TColStd_SequenceOfHExtendedString::*)(const Standard_Integer, const opencascade::handle<TCollection_HExtendedString> &)) &TColStd_SequenceOfHExtendedString::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfHExtendedString.def("__iter__", [](const TColStd_SequenceOfHExtendedString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapIteratorOfPackedMapOfInteger.hxx
	py::class_<TColStd_MapIteratorOfPackedMapOfInteger, std::unique_ptr<TColStd_MapIteratorOfPackedMapOfInteger, Deleter<TColStd_MapIteratorOfPackedMapOfInteger>>, TCollection_BasicMapIterator> cls_TColStd_MapIteratorOfPackedMapOfInteger(mod, "TColStd_MapIteratorOfPackedMapOfInteger", "Iterator of class TColStd_PackedMapOfInteger");
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def(py::init<>());
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def(py::init<const TColStd_PackedMapOfInteger &>(), py::arg(""));
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Initialize", (void (TColStd_MapIteratorOfPackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_MapIteratorOfPackedMapOfInteger::Initialize, "Re-initialize with the same or another Map instance.", py::arg(""));
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Reset", (void (TColStd_MapIteratorOfPackedMapOfInteger::*)()) &TColStd_MapIteratorOfPackedMapOfInteger::Reset, "Restart the iteraton");
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Key", (Standard_Integer (TColStd_MapIteratorOfPackedMapOfInteger::*)() const ) &TColStd_MapIteratorOfPackedMapOfInteger::Key, "Query the iterated key. Defined in TColStd_PackedMapOfInteger.cxx");
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Next", (void (TColStd_MapIteratorOfPackedMapOfInteger::*)()) &TColStd_MapIteratorOfPackedMapOfInteger::Next, "Increment the iterator");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColStd_Array1OfExtendedString, std::unique_ptr<TColStd_Array1OfExtendedString, Deleter<TColStd_Array1OfExtendedString>>> cls_TColStd_Array1OfExtendedString(mod, "TColStd_Array1OfExtendedString", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColStd_Array1OfExtendedString.def(py::init<>());
	cls_TColStd_Array1OfExtendedString.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfExtendedString.def(py::init([] (const TColStd_Array1OfExtendedString &other) {return new TColStd_Array1OfExtendedString(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColStd_Array1OfExtendedString.def(py::init<TColStd_Array1OfExtendedString &&>(), py::arg("theOther"));
	cls_TColStd_Array1OfExtendedString.def(py::init<const TCollection_ExtendedString &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfExtendedString.def("begin", (TColStd_Array1OfExtendedString::iterator (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfExtendedString.def("end", (TColStd_Array1OfExtendedString::iterator (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfExtendedString.def("cbegin", (TColStd_Array1OfExtendedString::const_iterator (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfExtendedString.def("cend", (TColStd_Array1OfExtendedString::const_iterator (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfExtendedString.def("Init", (void (TColStd_Array1OfExtendedString::*)(const TCollection_ExtendedString &)) &TColStd_Array1OfExtendedString::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColStd_Array1OfExtendedString.def("Size", (Standard_Integer (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::Size, "Size query");
	cls_TColStd_Array1OfExtendedString.def("Length", (Standard_Integer (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::Length, "Length query (the same)");
	cls_TColStd_Array1OfExtendedString.def("IsEmpty", (Standard_Boolean (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColStd_Array1OfExtendedString.def("Lower", (Standard_Integer (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::Lower, "Lower bound");
	cls_TColStd_Array1OfExtendedString.def("Upper", (Standard_Integer (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::Upper, "Upper bound");
	cls_TColStd_Array1OfExtendedString.def("IsDeletable", (Standard_Boolean (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::IsDeletable, "myDeletable flag");
	cls_TColStd_Array1OfExtendedString.def("IsAllocated", (Standard_Boolean (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColStd_Array1OfExtendedString.def("Assign", (TColStd_Array1OfExtendedString & (TColStd_Array1OfExtendedString::*)(const TColStd_Array1OfExtendedString &)) &TColStd_Array1OfExtendedString::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfExtendedString.def("Move", (TColStd_Array1OfExtendedString & (TColStd_Array1OfExtendedString::*)(TColStd_Array1OfExtendedString &&)) &TColStd_Array1OfExtendedString::Move, "Move assignment", py::arg("theOther"));
	cls_TColStd_Array1OfExtendedString.def("assign", (TColStd_Array1OfExtendedString & (TColStd_Array1OfExtendedString::*)(const TColStd_Array1OfExtendedString &)) &TColStd_Array1OfExtendedString::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfExtendedString.def("assign", (TColStd_Array1OfExtendedString & (TColStd_Array1OfExtendedString::*)(TColStd_Array1OfExtendedString &&)) &TColStd_Array1OfExtendedString::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColStd_Array1OfExtendedString.def("First", (const TCollection_ExtendedString & (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::First, "Returns first element");
	cls_TColStd_Array1OfExtendedString.def("ChangeFirst", (TCollection_ExtendedString & (TColStd_Array1OfExtendedString::*)()) &TColStd_Array1OfExtendedString::ChangeFirst, "Returns first element");
	cls_TColStd_Array1OfExtendedString.def("Last", (const TCollection_ExtendedString & (TColStd_Array1OfExtendedString::*)() const ) &TColStd_Array1OfExtendedString::Last, "Returns last element");
	cls_TColStd_Array1OfExtendedString.def("ChangeLast", (TCollection_ExtendedString & (TColStd_Array1OfExtendedString::*)()) &TColStd_Array1OfExtendedString::ChangeLast, "Returns last element");
	cls_TColStd_Array1OfExtendedString.def("Value", (const TCollection_ExtendedString & (TColStd_Array1OfExtendedString::*)(const Standard_Integer) const ) &TColStd_Array1OfExtendedString::Value, "Constant value access", py::arg("theIndex"));
	cls_TColStd_Array1OfExtendedString.def("__call__", (const TCollection_ExtendedString & (TColStd_Array1OfExtendedString::*)(const Standard_Integer) const ) &TColStd_Array1OfExtendedString::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColStd_Array1OfExtendedString.def("ChangeValue", (TCollection_ExtendedString & (TColStd_Array1OfExtendedString::*)(const Standard_Integer)) &TColStd_Array1OfExtendedString::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColStd_Array1OfExtendedString.def("__call__", (TCollection_ExtendedString & (TColStd_Array1OfExtendedString::*)(const Standard_Integer)) &TColStd_Array1OfExtendedString::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColStd_Array1OfExtendedString.def("SetValue", (void (TColStd_Array1OfExtendedString::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TColStd_Array1OfExtendedString::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_Array1OfExtendedString.def("Resize", (void (TColStd_Array1OfExtendedString::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColStd_Array1OfExtendedString::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColStd_Array1OfExtendedString.def("__iter__", [](const TColStd_Array1OfExtendedString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColStd_Array1OfCharacter, std::unique_ptr<TColStd_Array1OfCharacter, Deleter<TColStd_Array1OfCharacter>>> cls_TColStd_Array1OfCharacter(mod, "TColStd_Array1OfCharacter", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColStd_Array1OfCharacter.def(py::init<>());
	cls_TColStd_Array1OfCharacter.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfCharacter.def(py::init([] (const TColStd_Array1OfCharacter &other) {return new TColStd_Array1OfCharacter(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColStd_Array1OfCharacter.def(py::init<TColStd_Array1OfCharacter &&>(), py::arg("theOther"));
	cls_TColStd_Array1OfCharacter.def(py::init<const Standard_Character &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_Array1OfCharacter.def("begin", (TColStd_Array1OfCharacter::iterator (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfCharacter.def("end", (TColStd_Array1OfCharacter::iterator (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfCharacter.def("cbegin", (TColStd_Array1OfCharacter::const_iterator (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColStd_Array1OfCharacter.def("cend", (TColStd_Array1OfCharacter::const_iterator (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColStd_Array1OfCharacter.def("Init", (void (TColStd_Array1OfCharacter::*)(const Standard_Character &)) &TColStd_Array1OfCharacter::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColStd_Array1OfCharacter.def("Size", (Standard_Integer (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::Size, "Size query");
	cls_TColStd_Array1OfCharacter.def("Length", (Standard_Integer (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::Length, "Length query (the same)");
	cls_TColStd_Array1OfCharacter.def("IsEmpty", (Standard_Boolean (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColStd_Array1OfCharacter.def("Lower", (Standard_Integer (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::Lower, "Lower bound");
	cls_TColStd_Array1OfCharacter.def("Upper", (Standard_Integer (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::Upper, "Upper bound");
	cls_TColStd_Array1OfCharacter.def("IsDeletable", (Standard_Boolean (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::IsDeletable, "myDeletable flag");
	cls_TColStd_Array1OfCharacter.def("IsAllocated", (Standard_Boolean (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColStd_Array1OfCharacter.def("Assign", (TColStd_Array1OfCharacter & (TColStd_Array1OfCharacter::*)(const TColStd_Array1OfCharacter &)) &TColStd_Array1OfCharacter::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfCharacter.def("Move", (TColStd_Array1OfCharacter & (TColStd_Array1OfCharacter::*)(TColStd_Array1OfCharacter &&)) &TColStd_Array1OfCharacter::Move, "Move assignment", py::arg("theOther"));
	cls_TColStd_Array1OfCharacter.def("assign", (TColStd_Array1OfCharacter & (TColStd_Array1OfCharacter::*)(const TColStd_Array1OfCharacter &)) &TColStd_Array1OfCharacter::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColStd_Array1OfCharacter.def("assign", (TColStd_Array1OfCharacter & (TColStd_Array1OfCharacter::*)(TColStd_Array1OfCharacter &&)) &TColStd_Array1OfCharacter::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColStd_Array1OfCharacter.def("First", (const Standard_Character & (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::First, "Returns first element");
	cls_TColStd_Array1OfCharacter.def("ChangeFirst", (Standard_Character & (TColStd_Array1OfCharacter::*)()) &TColStd_Array1OfCharacter::ChangeFirst, "Returns first element");
	cls_TColStd_Array1OfCharacter.def("Last", (const Standard_Character & (TColStd_Array1OfCharacter::*)() const ) &TColStd_Array1OfCharacter::Last, "Returns last element");
	cls_TColStd_Array1OfCharacter.def("ChangeLast", (Standard_Character & (TColStd_Array1OfCharacter::*)()) &TColStd_Array1OfCharacter::ChangeLast, "Returns last element");
	cls_TColStd_Array1OfCharacter.def("Value", (const Standard_Character & (TColStd_Array1OfCharacter::*)(const Standard_Integer) const ) &TColStd_Array1OfCharacter::Value, "Constant value access", py::arg("theIndex"));
	cls_TColStd_Array1OfCharacter.def("__call__", (const Standard_Character & (TColStd_Array1OfCharacter::*)(const Standard_Integer) const ) &TColStd_Array1OfCharacter::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColStd_Array1OfCharacter.def("ChangeValue", (Standard_Character & (TColStd_Array1OfCharacter::*)(const Standard_Integer)) &TColStd_Array1OfCharacter::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColStd_Array1OfCharacter.def("__call__", (Standard_Character & (TColStd_Array1OfCharacter::*)(const Standard_Integer)) &TColStd_Array1OfCharacter::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColStd_Array1OfCharacter.def("SetValue", (void (TColStd_Array1OfCharacter::*)(const Standard_Integer, const Standard_Character &)) &TColStd_Array1OfCharacter::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_Array1OfCharacter.def("Resize", (void (TColStd_Array1OfCharacter::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColStd_Array1OfCharacter::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColStd_Array1OfCharacter.def("__iter__", [](const TColStd_Array1OfCharacter &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColStd_Array2OfBoolean, std::unique_ptr<TColStd_Array2OfBoolean, Deleter<TColStd_Array2OfBoolean>>> cls_TColStd_Array2OfBoolean(mod, "TColStd_Array2OfBoolean", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColStd_Array2OfBoolean.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColStd_Array2OfBoolean.def(py::init([] (const TColStd_Array2OfBoolean &other) {return new TColStd_Array2OfBoolean(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_Array2OfBoolean.def(py::init<const Standard_Boolean &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColStd_Array2OfBoolean.def("Init", (void (TColStd_Array2OfBoolean::*)(const Standard_Boolean &)) &TColStd_Array2OfBoolean::Init, "Initialise the values", py::arg("theValue"));
	cls_TColStd_Array2OfBoolean.def("Size", (Standard_Integer (TColStd_Array2OfBoolean::*)() const ) &TColStd_Array2OfBoolean::Size, "Size (number of items)");
	cls_TColStd_Array2OfBoolean.def("Length", (Standard_Integer (TColStd_Array2OfBoolean::*)() const ) &TColStd_Array2OfBoolean::Length, "Length (number of items)");
	cls_TColStd_Array2OfBoolean.def("RowLength", (Standard_Integer (TColStd_Array2OfBoolean::*)() const ) &TColStd_Array2OfBoolean::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColStd_Array2OfBoolean.def("ColLength", (Standard_Integer (TColStd_Array2OfBoolean::*)() const ) &TColStd_Array2OfBoolean::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColStd_Array2OfBoolean.def("LowerRow", (Standard_Integer (TColStd_Array2OfBoolean::*)() const ) &TColStd_Array2OfBoolean::LowerRow, "LowerRow");
	cls_TColStd_Array2OfBoolean.def("UpperRow", (Standard_Integer (TColStd_Array2OfBoolean::*)() const ) &TColStd_Array2OfBoolean::UpperRow, "UpperRow");
	cls_TColStd_Array2OfBoolean.def("LowerCol", (Standard_Integer (TColStd_Array2OfBoolean::*)() const ) &TColStd_Array2OfBoolean::LowerCol, "LowerCol");
	cls_TColStd_Array2OfBoolean.def("UpperCol", (Standard_Integer (TColStd_Array2OfBoolean::*)() const ) &TColStd_Array2OfBoolean::UpperCol, "UpperCol");
	cls_TColStd_Array2OfBoolean.def("IsDeletable", (Standard_Boolean (TColStd_Array2OfBoolean::*)() const ) &TColStd_Array2OfBoolean::IsDeletable, "myDeletable flag");
	cls_TColStd_Array2OfBoolean.def("Assign", (TColStd_Array2OfBoolean & (TColStd_Array2OfBoolean::*)(const TColStd_Array2OfBoolean &)) &TColStd_Array2OfBoolean::Assign, "Assignment", py::arg("theOther"));
	cls_TColStd_Array2OfBoolean.def("assign", (TColStd_Array2OfBoolean & (TColStd_Array2OfBoolean::*)(const TColStd_Array2OfBoolean &)) &TColStd_Array2OfBoolean::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_Array2OfBoolean.def("Value", (const Standard_Boolean & (TColStd_Array2OfBoolean::*)(const Standard_Integer, const Standard_Integer) const ) &TColStd_Array2OfBoolean::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfBoolean.def("__call__", (const Standard_Boolean & (TColStd_Array2OfBoolean::*)(const Standard_Integer, const Standard_Integer) const ) &TColStd_Array2OfBoolean::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfBoolean.def("ChangeValue", (Standard_Boolean & (TColStd_Array2OfBoolean::*)(const Standard_Integer, const Standard_Integer)) &TColStd_Array2OfBoolean::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfBoolean.def("__call__", (Standard_Boolean & (TColStd_Array2OfBoolean::*)(const Standard_Integer, const Standard_Integer)) &TColStd_Array2OfBoolean::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfBoolean.def("SetValue", (void (TColStd_Array2OfBoolean::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean &)) &TColStd_Array2OfBoolean::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColStd_Array2OfCharacter, std::unique_ptr<TColStd_Array2OfCharacter, Deleter<TColStd_Array2OfCharacter>>> cls_TColStd_Array2OfCharacter(mod, "TColStd_Array2OfCharacter", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColStd_Array2OfCharacter.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColStd_Array2OfCharacter.def(py::init([] (const TColStd_Array2OfCharacter &other) {return new TColStd_Array2OfCharacter(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_Array2OfCharacter.def(py::init<const Standard_Character &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColStd_Array2OfCharacter.def("Init", (void (TColStd_Array2OfCharacter::*)(const Standard_Character &)) &TColStd_Array2OfCharacter::Init, "Initialise the values", py::arg("theValue"));
	cls_TColStd_Array2OfCharacter.def("Size", (Standard_Integer (TColStd_Array2OfCharacter::*)() const ) &TColStd_Array2OfCharacter::Size, "Size (number of items)");
	cls_TColStd_Array2OfCharacter.def("Length", (Standard_Integer (TColStd_Array2OfCharacter::*)() const ) &TColStd_Array2OfCharacter::Length, "Length (number of items)");
	cls_TColStd_Array2OfCharacter.def("RowLength", (Standard_Integer (TColStd_Array2OfCharacter::*)() const ) &TColStd_Array2OfCharacter::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColStd_Array2OfCharacter.def("ColLength", (Standard_Integer (TColStd_Array2OfCharacter::*)() const ) &TColStd_Array2OfCharacter::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColStd_Array2OfCharacter.def("LowerRow", (Standard_Integer (TColStd_Array2OfCharacter::*)() const ) &TColStd_Array2OfCharacter::LowerRow, "LowerRow");
	cls_TColStd_Array2OfCharacter.def("UpperRow", (Standard_Integer (TColStd_Array2OfCharacter::*)() const ) &TColStd_Array2OfCharacter::UpperRow, "UpperRow");
	cls_TColStd_Array2OfCharacter.def("LowerCol", (Standard_Integer (TColStd_Array2OfCharacter::*)() const ) &TColStd_Array2OfCharacter::LowerCol, "LowerCol");
	cls_TColStd_Array2OfCharacter.def("UpperCol", (Standard_Integer (TColStd_Array2OfCharacter::*)() const ) &TColStd_Array2OfCharacter::UpperCol, "UpperCol");
	cls_TColStd_Array2OfCharacter.def("IsDeletable", (Standard_Boolean (TColStd_Array2OfCharacter::*)() const ) &TColStd_Array2OfCharacter::IsDeletable, "myDeletable flag");
	cls_TColStd_Array2OfCharacter.def("Assign", (TColStd_Array2OfCharacter & (TColStd_Array2OfCharacter::*)(const TColStd_Array2OfCharacter &)) &TColStd_Array2OfCharacter::Assign, "Assignment", py::arg("theOther"));
	cls_TColStd_Array2OfCharacter.def("assign", (TColStd_Array2OfCharacter & (TColStd_Array2OfCharacter::*)(const TColStd_Array2OfCharacter &)) &TColStd_Array2OfCharacter::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_Array2OfCharacter.def("Value", (const Standard_Character & (TColStd_Array2OfCharacter::*)(const Standard_Integer, const Standard_Integer) const ) &TColStd_Array2OfCharacter::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfCharacter.def("__call__", (const Standard_Character & (TColStd_Array2OfCharacter::*)(const Standard_Integer, const Standard_Integer) const ) &TColStd_Array2OfCharacter::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfCharacter.def("ChangeValue", (Standard_Character & (TColStd_Array2OfCharacter::*)(const Standard_Integer, const Standard_Integer)) &TColStd_Array2OfCharacter::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfCharacter.def("__call__", (Standard_Character & (TColStd_Array2OfCharacter::*)(const Standard_Integer, const Standard_Integer)) &TColStd_Array2OfCharacter::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColStd_Array2OfCharacter.def("SetValue", (void (TColStd_Array2OfCharacter::*)(const Standard_Integer, const Standard_Integer, const Standard_Character &)) &TColStd_Array2OfCharacter::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColStd_SequenceOfExtendedString, std::unique_ptr<TColStd_SequenceOfExtendedString, Deleter<TColStd_SequenceOfExtendedString>>, NCollection_BaseSequence> cls_TColStd_SequenceOfExtendedString(mod, "TColStd_SequenceOfExtendedString", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColStd_SequenceOfExtendedString.def(py::init<>());
	cls_TColStd_SequenceOfExtendedString.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_SequenceOfExtendedString.def(py::init([] (const TColStd_SequenceOfExtendedString &other) {return new TColStd_SequenceOfExtendedString(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_SequenceOfExtendedString.def("begin", (TColStd_SequenceOfExtendedString::iterator (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfExtendedString.def("end", (TColStd_SequenceOfExtendedString::iterator (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfExtendedString.def("cbegin", (TColStd_SequenceOfExtendedString::const_iterator (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfExtendedString.def("cend", (TColStd_SequenceOfExtendedString::const_iterator (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfExtendedString.def("Size", (Standard_Integer (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::Size, "Number of items");
	cls_TColStd_SequenceOfExtendedString.def("Length", (Standard_Integer (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::Length, "Number of items");
	cls_TColStd_SequenceOfExtendedString.def("Lower", (Standard_Integer (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::Lower, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfExtendedString.def("Upper", (Standard_Integer (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::Upper, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfExtendedString.def("IsEmpty", (Standard_Boolean (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::IsEmpty, "Empty query");
	cls_TColStd_SequenceOfExtendedString.def("Reverse", (void (TColStd_SequenceOfExtendedString::*)()) &TColStd_SequenceOfExtendedString::Reverse, "Reverse sequence");
	cls_TColStd_SequenceOfExtendedString.def("Exchange", (void (TColStd_SequenceOfExtendedString::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfExtendedString::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColStd_SequenceOfExtendedString.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfExtendedString::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColStd_SequenceOfExtendedString.def("Clear", [](TColStd_SequenceOfExtendedString &self) -> void { return self.Clear(); });
	cls_TColStd_SequenceOfExtendedString.def("Clear", (void (TColStd_SequenceOfExtendedString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfExtendedString::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColStd_SequenceOfExtendedString.def("Assign", (TColStd_SequenceOfExtendedString & (TColStd_SequenceOfExtendedString::*)(const TColStd_SequenceOfExtendedString &)) &TColStd_SequenceOfExtendedString::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_SequenceOfExtendedString.def("assign", (TColStd_SequenceOfExtendedString & (TColStd_SequenceOfExtendedString::*)(const TColStd_SequenceOfExtendedString &)) &TColStd_SequenceOfExtendedString::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_SequenceOfExtendedString.def("Remove", (void (TColStd_SequenceOfExtendedString::*)(TColStd_SequenceOfExtendedString::Iterator &)) &TColStd_SequenceOfExtendedString::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColStd_SequenceOfExtendedString.def("Remove", (void (TColStd_SequenceOfExtendedString::*)(const Standard_Integer)) &TColStd_SequenceOfExtendedString::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColStd_SequenceOfExtendedString.def("Remove", (void (TColStd_SequenceOfExtendedString::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfExtendedString::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColStd_SequenceOfExtendedString.def("Append", (void (TColStd_SequenceOfExtendedString::*)(const TCollection_ExtendedString &)) &TColStd_SequenceOfExtendedString::Append, "Append one item", py::arg("theItem"));
	cls_TColStd_SequenceOfExtendedString.def("Append", (void (TColStd_SequenceOfExtendedString::*)(TColStd_SequenceOfExtendedString &)) &TColStd_SequenceOfExtendedString::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfExtendedString.def("Prepend", (void (TColStd_SequenceOfExtendedString::*)(const TCollection_ExtendedString &)) &TColStd_SequenceOfExtendedString::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColStd_SequenceOfExtendedString.def("Prepend", (void (TColStd_SequenceOfExtendedString::*)(TColStd_SequenceOfExtendedString &)) &TColStd_SequenceOfExtendedString::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfExtendedString.def("InsertBefore", (void (TColStd_SequenceOfExtendedString::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TColStd_SequenceOfExtendedString::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfExtendedString.def("InsertBefore", (void (TColStd_SequenceOfExtendedString::*)(const Standard_Integer, TColStd_SequenceOfExtendedString &)) &TColStd_SequenceOfExtendedString::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfExtendedString.def("InsertAfter", (void (TColStd_SequenceOfExtendedString::*)(TColStd_SequenceOfExtendedString::Iterator &, const TCollection_ExtendedString &)) &TColStd_SequenceOfExtendedString::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColStd_SequenceOfExtendedString.def("InsertAfter", (void (TColStd_SequenceOfExtendedString::*)(const Standard_Integer, TColStd_SequenceOfExtendedString &)) &TColStd_SequenceOfExtendedString::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfExtendedString.def("InsertAfter", (void (TColStd_SequenceOfExtendedString::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TColStd_SequenceOfExtendedString::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfExtendedString.def("Split", (void (TColStd_SequenceOfExtendedString::*)(const Standard_Integer, TColStd_SequenceOfExtendedString &)) &TColStd_SequenceOfExtendedString::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfExtendedString.def("First", (const TCollection_ExtendedString & (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::First, "First item access");
	cls_TColStd_SequenceOfExtendedString.def("ChangeFirst", (TCollection_ExtendedString & (TColStd_SequenceOfExtendedString::*)()) &TColStd_SequenceOfExtendedString::ChangeFirst, "First item access");
	cls_TColStd_SequenceOfExtendedString.def("Last", (const TCollection_ExtendedString & (TColStd_SequenceOfExtendedString::*)() const ) &TColStd_SequenceOfExtendedString::Last, "Last item access");
	cls_TColStd_SequenceOfExtendedString.def("ChangeLast", (TCollection_ExtendedString & (TColStd_SequenceOfExtendedString::*)()) &TColStd_SequenceOfExtendedString::ChangeLast, "Last item access");
	cls_TColStd_SequenceOfExtendedString.def("Value", (const TCollection_ExtendedString & (TColStd_SequenceOfExtendedString::*)(const Standard_Integer) const ) &TColStd_SequenceOfExtendedString::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfExtendedString.def("__call__", (const TCollection_ExtendedString & (TColStd_SequenceOfExtendedString::*)(const Standard_Integer) const ) &TColStd_SequenceOfExtendedString::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfExtendedString.def("ChangeValue", (TCollection_ExtendedString & (TColStd_SequenceOfExtendedString::*)(const Standard_Integer)) &TColStd_SequenceOfExtendedString::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfExtendedString.def("__call__", (TCollection_ExtendedString & (TColStd_SequenceOfExtendedString::*)(const Standard_Integer)) &TColStd_SequenceOfExtendedString::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfExtendedString.def("SetValue", (void (TColStd_SequenceOfExtendedString::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TColStd_SequenceOfExtendedString::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfExtendedString.def("__iter__", [](const TColStd_SequenceOfExtendedString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray1OfReal.hxx
	py::class_<TColStd_HArray1OfReal, opencascade::handle<TColStd_HArray1OfReal>, TColStd_Array1OfReal, Standard_Transient> cls_TColStd_HArray1OfReal(mod, "TColStd_HArray1OfReal", "None");
	cls_TColStd_HArray1OfReal.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_HArray1OfReal.def(py::init<const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColStd_HArray1OfReal.def(py::init<const TColStd_Array1OfReal &>(), py::arg("theOther"));
	cls_TColStd_HArray1OfReal.def("Array1", (const TColStd_Array1OfReal & (TColStd_HArray1OfReal::*)() const ) &TColStd_HArray1OfReal::Array1, "None");
	cls_TColStd_HArray1OfReal.def("ChangeArray1", (TColStd_Array1OfReal & (TColStd_HArray1OfReal::*)()) &TColStd_HArray1OfReal::ChangeArray1, "None");
	cls_TColStd_HArray1OfReal.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray1OfReal::get_type_name, "None");
	cls_TColStd_HArray1OfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray1OfReal::get_type_descriptor, "None");
	cls_TColStd_HArray1OfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray1OfReal::*)() const ) &TColStd_HArray1OfReal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray1OfInteger.hxx
	py::class_<TColStd_HArray1OfInteger, opencascade::handle<TColStd_HArray1OfInteger>, TColStd_Array1OfInteger, Standard_Transient> cls_TColStd_HArray1OfInteger(mod, "TColStd_HArray1OfInteger", "None");
	cls_TColStd_HArray1OfInteger.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_HArray1OfInteger.def(py::init<const Standard_Integer, const Standard_Integer, const TColStd_Array1OfInteger::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColStd_HArray1OfInteger.def(py::init<const TColStd_Array1OfInteger &>(), py::arg("theOther"));
	cls_TColStd_HArray1OfInteger.def("Array1", (const TColStd_Array1OfInteger & (TColStd_HArray1OfInteger::*)() const ) &TColStd_HArray1OfInteger::Array1, "None");
	cls_TColStd_HArray1OfInteger.def("ChangeArray1", (TColStd_Array1OfInteger & (TColStd_HArray1OfInteger::*)()) &TColStd_HArray1OfInteger::ChangeArray1, "None");
	cls_TColStd_HArray1OfInteger.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray1OfInteger::get_type_name, "None");
	cls_TColStd_HArray1OfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray1OfInteger::get_type_descriptor, "None");
	cls_TColStd_HArray1OfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray1OfInteger::*)() const ) &TColStd_HArray1OfInteger::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray2OfReal.hxx
	py::class_<TColStd_HArray2OfReal, opencascade::handle<TColStd_HArray2OfReal>, TColStd_Array2OfReal, Standard_Transient> cls_TColStd_HArray2OfReal(mod, "TColStd_HArray2OfReal", "None");
	cls_TColStd_HArray2OfReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColStd_HArray2OfReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array2OfReal::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColStd_HArray2OfReal.def(py::init<const TColStd_Array2OfReal &>(), py::arg("theOther"));
	cls_TColStd_HArray2OfReal.def("Array2", (const TColStd_Array2OfReal & (TColStd_HArray2OfReal::*)() const ) &TColStd_HArray2OfReal::Array2, "None");
	cls_TColStd_HArray2OfReal.def("ChangeArray2", (TColStd_Array2OfReal & (TColStd_HArray2OfReal::*)()) &TColStd_HArray2OfReal::ChangeArray2, "None");
	cls_TColStd_HArray2OfReal.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray2OfReal::get_type_name, "None");
	cls_TColStd_HArray2OfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray2OfReal::get_type_descriptor, "None");
	cls_TColStd_HArray2OfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray2OfReal::*)() const ) &TColStd_HArray2OfReal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HSequenceOfReal.hxx
	py::class_<TColStd_HSequenceOfReal, opencascade::handle<TColStd_HSequenceOfReal>, TColStd_SequenceOfReal, Standard_Transient> cls_TColStd_HSequenceOfReal(mod, "TColStd_HSequenceOfReal", "None");
	cls_TColStd_HSequenceOfReal.def(py::init<>());
	cls_TColStd_HSequenceOfReal.def(py::init<const TColStd_SequenceOfReal &>(), py::arg("theOther"));
	cls_TColStd_HSequenceOfReal.def("Sequence", (const TColStd_SequenceOfReal & (TColStd_HSequenceOfReal::*)() const ) &TColStd_HSequenceOfReal::Sequence, "None");
	cls_TColStd_HSequenceOfReal.def("Append", (void (TColStd_HSequenceOfReal::*)(const TColStd_SequenceOfReal::value_type &)) &TColStd_HSequenceOfReal::Append, "None", py::arg("theItem"));
	cls_TColStd_HSequenceOfReal.def("Append", (void (TColStd_HSequenceOfReal::*)(TColStd_SequenceOfReal &)) &TColStd_HSequenceOfReal::Append, "None", py::arg("theSequence"));
	cls_TColStd_HSequenceOfReal.def("ChangeSequence", (TColStd_SequenceOfReal & (TColStd_HSequenceOfReal::*)()) &TColStd_HSequenceOfReal::ChangeSequence, "None");
	cls_TColStd_HSequenceOfReal.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfReal::get_type_name, "None");
	cls_TColStd_HSequenceOfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfReal::get_type_descriptor, "None");
	cls_TColStd_HSequenceOfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfReal::*)() const ) &TColStd_HSequenceOfReal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TColStd_ListOfInteger, std::unique_ptr<TColStd_ListOfInteger, Deleter<TColStd_ListOfInteger>>, NCollection_BaseList> cls_TColStd_ListOfInteger(mod, "TColStd_ListOfInteger", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TColStd_ListOfInteger.def(py::init<>());
	cls_TColStd_ListOfInteger.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_ListOfInteger.def(py::init([] (const TColStd_ListOfInteger &other) {return new TColStd_ListOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_ListOfInteger.def("begin", (TColStd_ListOfInteger::iterator (TColStd_ListOfInteger::*)() const ) &TColStd_ListOfInteger::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TColStd_ListOfInteger.def("end", (TColStd_ListOfInteger::iterator (TColStd_ListOfInteger::*)() const ) &TColStd_ListOfInteger::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TColStd_ListOfInteger.def("cbegin", (TColStd_ListOfInteger::const_iterator (TColStd_ListOfInteger::*)() const ) &TColStd_ListOfInteger::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TColStd_ListOfInteger.def("cend", (TColStd_ListOfInteger::const_iterator (TColStd_ListOfInteger::*)() const ) &TColStd_ListOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TColStd_ListOfInteger.def("Size", (Standard_Integer (TColStd_ListOfInteger::*)() const ) &TColStd_ListOfInteger::Size, "Size - Number of items");
	cls_TColStd_ListOfInteger.def("Assign", (TColStd_ListOfInteger & (TColStd_ListOfInteger::*)(const TColStd_ListOfInteger &)) &TColStd_ListOfInteger::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_ListOfInteger.def("assign", (TColStd_ListOfInteger & (TColStd_ListOfInteger::*)(const TColStd_ListOfInteger &)) &TColStd_ListOfInteger::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_ListOfInteger.def("Clear", [](TColStd_ListOfInteger &self) -> void { return self.Clear(); });
	cls_TColStd_ListOfInteger.def("Clear", (void (TColStd_ListOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_ListOfInteger::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TColStd_ListOfInteger.def("First", (const Standard_Integer & (TColStd_ListOfInteger::*)() const ) &TColStd_ListOfInteger::First, "First item");
	cls_TColStd_ListOfInteger.def("First", (Standard_Integer & (TColStd_ListOfInteger::*)()) &TColStd_ListOfInteger::First, "First item (non-const)");
	cls_TColStd_ListOfInteger.def("Last", (const Standard_Integer & (TColStd_ListOfInteger::*)() const ) &TColStd_ListOfInteger::Last, "Last item");
	cls_TColStd_ListOfInteger.def("Last", (Standard_Integer & (TColStd_ListOfInteger::*)()) &TColStd_ListOfInteger::Last, "Last item (non-const)");
	cls_TColStd_ListOfInteger.def("Append", (Standard_Integer & (TColStd_ListOfInteger::*)(const Standard_Integer &)) &TColStd_ListOfInteger::Append, "Append one item at the end", py::arg("theItem"));
	cls_TColStd_ListOfInteger.def("Append", (void (TColStd_ListOfInteger::*)(const Standard_Integer &, TColStd_ListOfInteger::Iterator &)) &TColStd_ListOfInteger::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfInteger.def("Append", (void (TColStd_ListOfInteger::*)(TColStd_ListOfInteger &)) &TColStd_ListOfInteger::Append, "Append another list at the end", py::arg("theOther"));
	cls_TColStd_ListOfInteger.def("Prepend", (Standard_Integer & (TColStd_ListOfInteger::*)(const Standard_Integer &)) &TColStd_ListOfInteger::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TColStd_ListOfInteger.def("Prepend", (void (TColStd_ListOfInteger::*)(TColStd_ListOfInteger &)) &TColStd_ListOfInteger::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TColStd_ListOfInteger.def("RemoveFirst", (void (TColStd_ListOfInteger::*)()) &TColStd_ListOfInteger::RemoveFirst, "RemoveFirst item");
	cls_TColStd_ListOfInteger.def("Remove", (void (TColStd_ListOfInteger::*)(TColStd_ListOfInteger::Iterator &)) &TColStd_ListOfInteger::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TColStd_ListOfInteger.def("InsertBefore", (Standard_Integer & (TColStd_ListOfInteger::*)(const Standard_Integer &, TColStd_ListOfInteger::Iterator &)) &TColStd_ListOfInteger::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfInteger.def("InsertBefore", (void (TColStd_ListOfInteger::*)(TColStd_ListOfInteger &, TColStd_ListOfInteger::Iterator &)) &TColStd_ListOfInteger::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TColStd_ListOfInteger.def("InsertAfter", (Standard_Integer & (TColStd_ListOfInteger::*)(const Standard_Integer &, TColStd_ListOfInteger::Iterator &)) &TColStd_ListOfInteger::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfInteger.def("InsertAfter", (void (TColStd_ListOfInteger::*)(TColStd_ListOfInteger &, TColStd_ListOfInteger::Iterator &)) &TColStd_ListOfInteger::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TColStd_ListOfInteger.def("Reverse", (void (TColStd_ListOfInteger::*)()) &TColStd_ListOfInteger::Reverse, "Reverse the list");
	cls_TColStd_ListOfInteger.def("__iter__", [](const TColStd_ListOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TColStd_ListIteratorOfListOfInteger, std::unique_ptr<TColStd_ListIteratorOfListOfInteger, Deleter<TColStd_ListIteratorOfListOfInteger>>> cls_TColStd_ListIteratorOfListOfInteger(mod, "TColStd_ListIteratorOfListOfInteger", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TColStd_ListIteratorOfListOfInteger.def(py::init<>());
	cls_TColStd_ListIteratorOfListOfInteger.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TColStd_ListIteratorOfListOfInteger.def("More", (Standard_Boolean (TColStd_ListIteratorOfListOfInteger::*)() const ) &TColStd_ListIteratorOfListOfInteger::More, "Check end");
	cls_TColStd_ListIteratorOfListOfInteger.def("Next", (void (TColStd_ListIteratorOfListOfInteger::*)()) &TColStd_ListIteratorOfListOfInteger::Next, "Make step");
	cls_TColStd_ListIteratorOfListOfInteger.def("Value", (const int & (TColStd_ListIteratorOfListOfInteger::*)() const ) &TColStd_ListIteratorOfListOfInteger::Value, "Constant Value access");
	cls_TColStd_ListIteratorOfListOfInteger.def("Value", (int & (TColStd_ListIteratorOfListOfInteger::*)()) &TColStd_ListIteratorOfListOfInteger::Value, "Non-const Value access");
	cls_TColStd_ListIteratorOfListOfInteger.def("ChangeValue", (int & (TColStd_ListIteratorOfListOfInteger::*)() const ) &TColStd_ListIteratorOfListOfInteger::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray1OfByte.hxx
	py::class_<TColStd_HArray1OfByte, opencascade::handle<TColStd_HArray1OfByte>, TColStd_Array1OfByte, Standard_Transient> cls_TColStd_HArray1OfByte(mod, "TColStd_HArray1OfByte", "None");
	cls_TColStd_HArray1OfByte.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_HArray1OfByte.def(py::init<const Standard_Integer, const Standard_Integer, const TColStd_Array1OfByte::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColStd_HArray1OfByte.def(py::init<const TColStd_Array1OfByte &>(), py::arg("theOther"));
	cls_TColStd_HArray1OfByte.def("Array1", (const TColStd_Array1OfByte & (TColStd_HArray1OfByte::*)() const ) &TColStd_HArray1OfByte::Array1, "None");
	cls_TColStd_HArray1OfByte.def("ChangeArray1", (TColStd_Array1OfByte & (TColStd_HArray1OfByte::*)()) &TColStd_HArray1OfByte::ChangeArray1, "None");
	cls_TColStd_HArray1OfByte.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray1OfByte::get_type_name, "None");
	cls_TColStd_HArray1OfByte.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray1OfByte::get_type_descriptor, "None");
	cls_TColStd_HArray1OfByte.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray1OfByte::*)() const ) &TColStd_HArray1OfByte::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<TColStd_IndexedDataMapOfStringString, std::unique_ptr<TColStd_IndexedDataMapOfStringString, Deleter<TColStd_IndexedDataMapOfStringString>>, NCollection_BaseMap> cls_TColStd_IndexedDataMapOfStringString(mod, "TColStd_IndexedDataMapOfStringString", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_TColStd_IndexedDataMapOfStringString.def(py::init<>());
	cls_TColStd_IndexedDataMapOfStringString.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_IndexedDataMapOfStringString.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_IndexedDataMapOfStringString.def(py::init([] (const TColStd_IndexedDataMapOfStringString &other) {return new TColStd_IndexedDataMapOfStringString(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_IndexedDataMapOfStringString.def("begin", (TColStd_IndexedDataMapOfStringString::iterator (TColStd_IndexedDataMapOfStringString::*)() const ) &TColStd_IndexedDataMapOfStringString::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TColStd_IndexedDataMapOfStringString.def("end", (TColStd_IndexedDataMapOfStringString::iterator (TColStd_IndexedDataMapOfStringString::*)() const ) &TColStd_IndexedDataMapOfStringString::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TColStd_IndexedDataMapOfStringString.def("cbegin", (TColStd_IndexedDataMapOfStringString::const_iterator (TColStd_IndexedDataMapOfStringString::*)() const ) &TColStd_IndexedDataMapOfStringString::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_IndexedDataMapOfStringString.def("cend", (TColStd_IndexedDataMapOfStringString::const_iterator (TColStd_IndexedDataMapOfStringString::*)() const ) &TColStd_IndexedDataMapOfStringString::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_IndexedDataMapOfStringString.def("Exchange", (void (TColStd_IndexedDataMapOfStringString::*)(TColStd_IndexedDataMapOfStringString &)) &TColStd_IndexedDataMapOfStringString::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_IndexedDataMapOfStringString.def("Assign", (TColStd_IndexedDataMapOfStringString & (TColStd_IndexedDataMapOfStringString::*)(const TColStd_IndexedDataMapOfStringString &)) &TColStd_IndexedDataMapOfStringString::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_IndexedDataMapOfStringString.def("assign", (TColStd_IndexedDataMapOfStringString & (TColStd_IndexedDataMapOfStringString::*)(const TColStd_IndexedDataMapOfStringString &)) &TColStd_IndexedDataMapOfStringString::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_IndexedDataMapOfStringString.def("ReSize", (void (TColStd_IndexedDataMapOfStringString::*)(const Standard_Integer)) &TColStd_IndexedDataMapOfStringString::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_IndexedDataMapOfStringString.def("Add", (Standard_Integer (TColStd_IndexedDataMapOfStringString::*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &TColStd_IndexedDataMapOfStringString::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_TColStd_IndexedDataMapOfStringString.def("Contains", (Standard_Boolean (TColStd_IndexedDataMapOfStringString::*)(const TCollection_AsciiString &) const ) &TColStd_IndexedDataMapOfStringString::Contains, "Contains", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfStringString.def("Substitute", (void (TColStd_IndexedDataMapOfStringString::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &)) &TColStd_IndexedDataMapOfStringString::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_TColStd_IndexedDataMapOfStringString.def("Swap", (void (TColStd_IndexedDataMapOfStringString::*)(const Standard_Integer, const Standard_Integer)) &TColStd_IndexedDataMapOfStringString::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TColStd_IndexedDataMapOfStringString.def("RemoveLast", (void (TColStd_IndexedDataMapOfStringString::*)()) &TColStd_IndexedDataMapOfStringString::RemoveLast, "RemoveLast");
	cls_TColStd_IndexedDataMapOfStringString.def("RemoveFromIndex", (void (TColStd_IndexedDataMapOfStringString::*)(const Standard_Integer)) &TColStd_IndexedDataMapOfStringString::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfStringString.def("RemoveKey", (void (TColStd_IndexedDataMapOfStringString::*)(const TCollection_AsciiString &)) &TColStd_IndexedDataMapOfStringString::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfStringString.def("FindKey", (const TCollection_AsciiString & (TColStd_IndexedDataMapOfStringString::*)(const Standard_Integer) const ) &TColStd_IndexedDataMapOfStringString::FindKey, "FindKey", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfStringString.def("FindFromIndex", (const TCollection_AsciiString & (TColStd_IndexedDataMapOfStringString::*)(const Standard_Integer) const ) &TColStd_IndexedDataMapOfStringString::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfStringString.def("__call__", (const TCollection_AsciiString & (TColStd_IndexedDataMapOfStringString::*)(const Standard_Integer) const ) &TColStd_IndexedDataMapOfStringString::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfStringString.def("ChangeFromIndex", (TCollection_AsciiString & (TColStd_IndexedDataMapOfStringString::*)(const Standard_Integer)) &TColStd_IndexedDataMapOfStringString::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfStringString.def("__call__", (TCollection_AsciiString & (TColStd_IndexedDataMapOfStringString::*)(const Standard_Integer)) &TColStd_IndexedDataMapOfStringString::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfStringString.def("FindIndex", (Standard_Integer (TColStd_IndexedDataMapOfStringString::*)(const TCollection_AsciiString &) const ) &TColStd_IndexedDataMapOfStringString::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfStringString.def("FindFromKey", (const TCollection_AsciiString & (TColStd_IndexedDataMapOfStringString::*)(const TCollection_AsciiString &) const ) &TColStd_IndexedDataMapOfStringString::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfStringString.def("ChangeFromKey", (TCollection_AsciiString & (TColStd_IndexedDataMapOfStringString::*)(const TCollection_AsciiString &)) &TColStd_IndexedDataMapOfStringString::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_TColStd_IndexedDataMapOfStringString.def("Seek", (const TCollection_AsciiString * (TColStd_IndexedDataMapOfStringString::*)(const TCollection_AsciiString &) const ) &TColStd_IndexedDataMapOfStringString::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_TColStd_IndexedDataMapOfStringString.def("ChangeSeek", (TCollection_AsciiString * (TColStd_IndexedDataMapOfStringString::*)(const TCollection_AsciiString &)) &TColStd_IndexedDataMapOfStringString::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfStringString.def("FindFromKey", (Standard_Boolean (TColStd_IndexedDataMapOfStringString::*)(const TCollection_AsciiString &, TCollection_AsciiString &) const ) &TColStd_IndexedDataMapOfStringString::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_TColStd_IndexedDataMapOfStringString.def("Clear", [](TColStd_IndexedDataMapOfStringString &self) -> void { return self.Clear(); });
	cls_TColStd_IndexedDataMapOfStringString.def("Clear", (void (TColStd_IndexedDataMapOfStringString::*)(const Standard_Boolean)) &TColStd_IndexedDataMapOfStringString::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_IndexedDataMapOfStringString.def("Clear", (void (TColStd_IndexedDataMapOfStringString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_IndexedDataMapOfStringString::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_IndexedDataMapOfStringString.def("Size", (Standard_Integer (TColStd_IndexedDataMapOfStringString::*)() const ) &TColStd_IndexedDataMapOfStringString::Size, "Size");
	cls_TColStd_IndexedDataMapOfStringString.def("__iter__", [](const TColStd_IndexedDataMapOfStringString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TColStd_ListOfTransient, std::unique_ptr<TColStd_ListOfTransient, Deleter<TColStd_ListOfTransient>>, NCollection_BaseList> cls_TColStd_ListOfTransient(mod, "TColStd_ListOfTransient", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TColStd_ListOfTransient.def(py::init<>());
	cls_TColStd_ListOfTransient.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_ListOfTransient.def(py::init([] (const TColStd_ListOfTransient &other) {return new TColStd_ListOfTransient(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_ListOfTransient.def("begin", (TColStd_ListOfTransient::iterator (TColStd_ListOfTransient::*)() const ) &TColStd_ListOfTransient::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TColStd_ListOfTransient.def("end", (TColStd_ListOfTransient::iterator (TColStd_ListOfTransient::*)() const ) &TColStd_ListOfTransient::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TColStd_ListOfTransient.def("cbegin", (TColStd_ListOfTransient::const_iterator (TColStd_ListOfTransient::*)() const ) &TColStd_ListOfTransient::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TColStd_ListOfTransient.def("cend", (TColStd_ListOfTransient::const_iterator (TColStd_ListOfTransient::*)() const ) &TColStd_ListOfTransient::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TColStd_ListOfTransient.def("Size", (Standard_Integer (TColStd_ListOfTransient::*)() const ) &TColStd_ListOfTransient::Size, "Size - Number of items");
	cls_TColStd_ListOfTransient.def("Assign", (TColStd_ListOfTransient & (TColStd_ListOfTransient::*)(const TColStd_ListOfTransient &)) &TColStd_ListOfTransient::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_ListOfTransient.def("assign", (TColStd_ListOfTransient & (TColStd_ListOfTransient::*)(const TColStd_ListOfTransient &)) &TColStd_ListOfTransient::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_ListOfTransient.def("Clear", [](TColStd_ListOfTransient &self) -> void { return self.Clear(); });
	cls_TColStd_ListOfTransient.def("Clear", (void (TColStd_ListOfTransient::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_ListOfTransient::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TColStd_ListOfTransient.def("First", (const opencascade::handle<Standard_Transient> & (TColStd_ListOfTransient::*)() const ) &TColStd_ListOfTransient::First, "First item");
	cls_TColStd_ListOfTransient.def("First", (opencascade::handle<Standard_Transient> & (TColStd_ListOfTransient::*)()) &TColStd_ListOfTransient::First, "First item (non-const)");
	cls_TColStd_ListOfTransient.def("Last", (const opencascade::handle<Standard_Transient> & (TColStd_ListOfTransient::*)() const ) &TColStd_ListOfTransient::Last, "Last item");
	cls_TColStd_ListOfTransient.def("Last", (opencascade::handle<Standard_Transient> & (TColStd_ListOfTransient::*)()) &TColStd_ListOfTransient::Last, "Last item (non-const)");
	cls_TColStd_ListOfTransient.def("Append", (opencascade::handle<Standard_Transient> & (TColStd_ListOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_ListOfTransient::Append, "Append one item at the end", py::arg("theItem"));
	cls_TColStd_ListOfTransient.def("Append", (void (TColStd_ListOfTransient::*)(const opencascade::handle<Standard_Transient> &, TColStd_ListOfTransient::Iterator &)) &TColStd_ListOfTransient::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfTransient.def("Append", (void (TColStd_ListOfTransient::*)(TColStd_ListOfTransient &)) &TColStd_ListOfTransient::Append, "Append another list at the end", py::arg("theOther"));
	cls_TColStd_ListOfTransient.def("Prepend", (opencascade::handle<Standard_Transient> & (TColStd_ListOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_ListOfTransient::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TColStd_ListOfTransient.def("Prepend", (void (TColStd_ListOfTransient::*)(TColStd_ListOfTransient &)) &TColStd_ListOfTransient::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TColStd_ListOfTransient.def("RemoveFirst", (void (TColStd_ListOfTransient::*)()) &TColStd_ListOfTransient::RemoveFirst, "RemoveFirst item");
	cls_TColStd_ListOfTransient.def("Remove", (void (TColStd_ListOfTransient::*)(TColStd_ListOfTransient::Iterator &)) &TColStd_ListOfTransient::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TColStd_ListOfTransient.def("InsertBefore", (opencascade::handle<Standard_Transient> & (TColStd_ListOfTransient::*)(const opencascade::handle<Standard_Transient> &, TColStd_ListOfTransient::Iterator &)) &TColStd_ListOfTransient::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfTransient.def("InsertBefore", (void (TColStd_ListOfTransient::*)(TColStd_ListOfTransient &, TColStd_ListOfTransient::Iterator &)) &TColStd_ListOfTransient::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TColStd_ListOfTransient.def("InsertAfter", (opencascade::handle<Standard_Transient> & (TColStd_ListOfTransient::*)(const opencascade::handle<Standard_Transient> &, TColStd_ListOfTransient::Iterator &)) &TColStd_ListOfTransient::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfTransient.def("InsertAfter", (void (TColStd_ListOfTransient::*)(TColStd_ListOfTransient &, TColStd_ListOfTransient::Iterator &)) &TColStd_ListOfTransient::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TColStd_ListOfTransient.def("Reverse", (void (TColStd_ListOfTransient::*)()) &TColStd_ListOfTransient::Reverse, "Reverse the list");
	cls_TColStd_ListOfTransient.def("__iter__", [](const TColStd_ListOfTransient &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TColStd_ListIteratorOfListOfTransient, std::unique_ptr<TColStd_ListIteratorOfListOfTransient, Deleter<TColStd_ListIteratorOfListOfTransient>>> cls_TColStd_ListIteratorOfListOfTransient(mod, "TColStd_ListIteratorOfListOfTransient", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TColStd_ListIteratorOfListOfTransient.def(py::init<>());
	cls_TColStd_ListIteratorOfListOfTransient.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TColStd_ListIteratorOfListOfTransient.def("More", (Standard_Boolean (TColStd_ListIteratorOfListOfTransient::*)() const ) &TColStd_ListIteratorOfListOfTransient::More, "Check end");
	cls_TColStd_ListIteratorOfListOfTransient.def("Next", (void (TColStd_ListIteratorOfListOfTransient::*)()) &TColStd_ListIteratorOfListOfTransient::Next, "Make step");
	cls_TColStd_ListIteratorOfListOfTransient.def("Value", (const opencascade::handle<Standard_Transient> & (TColStd_ListIteratorOfListOfTransient::*)() const ) &TColStd_ListIteratorOfListOfTransient::Value, "Constant Value access");
	cls_TColStd_ListIteratorOfListOfTransient.def("Value", (opencascade::handle<Standard_Transient> & (TColStd_ListIteratorOfListOfTransient::*)()) &TColStd_ListIteratorOfListOfTransient::Value, "Non-const Value access");
	cls_TColStd_ListIteratorOfListOfTransient.def("ChangeValue", (opencascade::handle<Standard_Transient> & (TColStd_ListIteratorOfListOfTransient::*)() const ) &TColStd_ListIteratorOfListOfTransient::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HSequenceOfInteger.hxx
	py::class_<TColStd_HSequenceOfInteger, opencascade::handle<TColStd_HSequenceOfInteger>, TColStd_SequenceOfInteger, Standard_Transient> cls_TColStd_HSequenceOfInteger(mod, "TColStd_HSequenceOfInteger", "None");
	cls_TColStd_HSequenceOfInteger.def(py::init<>());
	cls_TColStd_HSequenceOfInteger.def(py::init<const TColStd_SequenceOfInteger &>(), py::arg("theOther"));
	cls_TColStd_HSequenceOfInteger.def("Sequence", (const TColStd_SequenceOfInteger & (TColStd_HSequenceOfInteger::*)() const ) &TColStd_HSequenceOfInteger::Sequence, "None");
	cls_TColStd_HSequenceOfInteger.def("Append", (void (TColStd_HSequenceOfInteger::*)(const TColStd_SequenceOfInteger::value_type &)) &TColStd_HSequenceOfInteger::Append, "None", py::arg("theItem"));
	cls_TColStd_HSequenceOfInteger.def("Append", (void (TColStd_HSequenceOfInteger::*)(TColStd_SequenceOfInteger &)) &TColStd_HSequenceOfInteger::Append, "None", py::arg("theSequence"));
	cls_TColStd_HSequenceOfInteger.def("ChangeSequence", (TColStd_SequenceOfInteger & (TColStd_HSequenceOfInteger::*)()) &TColStd_HSequenceOfInteger::ChangeSequence, "None");
	cls_TColStd_HSequenceOfInteger.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfInteger::get_type_name, "None");
	cls_TColStd_HSequenceOfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfInteger::get_type_descriptor, "None");
	cls_TColStd_HSequenceOfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfInteger::*)() const ) &TColStd_HSequenceOfInteger::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DefaultHasher.hxx
	py::class_<TColStd_MapTransientHasher, std::unique_ptr<TColStd_MapTransientHasher, Deleter<TColStd_MapTransientHasher>>> cls_TColStd_MapTransientHasher(mod, "TColStd_MapTransientHasher", "Purpose: The DefaultHasher is a Hasher that is used by default in NCollection maps. To compute the hash code of the key is used the global function HashCode. To compare two keys is used the global function IsEqual.");
	cls_TColStd_MapTransientHasher.def(py::init<>());
	cls_TColStd_MapTransientHasher.def_static("HashCode_", (Standard_Integer (*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &TColStd_MapTransientHasher::HashCode, "None", py::arg("theKey"), py::arg("Upper"));
	cls_TColStd_MapTransientHasher.def_static("IsEqual_", (Standard_Boolean (*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &TColStd_MapTransientHasher::IsEqual, "None", py::arg("theKey1"), py::arg("theKey2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<TColStd_MapOfTransient, std::unique_ptr<TColStd_MapOfTransient, Deleter<TColStd_MapOfTransient>>, NCollection_BaseMap> cls_TColStd_MapOfTransient(mod, "TColStd_MapOfTransient", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_TColStd_MapOfTransient.def(py::init<>());
	cls_TColStd_MapOfTransient.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_MapOfTransient.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_MapOfTransient.def(py::init([] (const TColStd_MapOfTransient &other) {return new TColStd_MapOfTransient(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_MapOfTransient.def("cbegin", (TColStd_MapOfTransient::const_iterator (TColStd_MapOfTransient::*)() const ) &TColStd_MapOfTransient::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_MapOfTransient.def("cend", (TColStd_MapOfTransient::const_iterator (TColStd_MapOfTransient::*)() const ) &TColStd_MapOfTransient::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_MapOfTransient.def("Exchange", (void (TColStd_MapOfTransient::*)(TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_MapOfTransient.def("Assign", (TColStd_MapOfTransient & (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_MapOfTransient.def("assign", (TColStd_MapOfTransient & (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_TColStd_MapOfTransient.def("ReSize", (void (TColStd_MapOfTransient::*)(const Standard_Integer)) &TColStd_MapOfTransient::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_MapOfTransient.def("Add", (Standard_Boolean (TColStd_MapOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_MapOfTransient::Add, "Add", py::arg("K"));
	cls_TColStd_MapOfTransient.def("Added", (const opencascade::handle<Standard_Transient> & (TColStd_MapOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_MapOfTransient::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_TColStd_MapOfTransient.def("Contains", (Standard_Boolean (TColStd_MapOfTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_MapOfTransient::Contains, "Contains", py::arg("K"));
	cls_TColStd_MapOfTransient.def("Remove", (Standard_Boolean (TColStd_MapOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_MapOfTransient::Remove, "Remove", py::arg("K"));
	cls_TColStd_MapOfTransient.def("Clear", [](TColStd_MapOfTransient &self) -> void { return self.Clear(); });
	cls_TColStd_MapOfTransient.def("Clear", (void (TColStd_MapOfTransient::*)(const Standard_Boolean)) &TColStd_MapOfTransient::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_MapOfTransient.def("Clear", (void (TColStd_MapOfTransient::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_MapOfTransient::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_MapOfTransient.def("Size", (Standard_Integer (TColStd_MapOfTransient::*)() const ) &TColStd_MapOfTransient::Size, "Size");
	cls_TColStd_MapOfTransient.def("IsEqual", (Standard_Boolean (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &) const ) &TColStd_MapOfTransient::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_TColStd_MapOfTransient.def("Contains", (Standard_Boolean (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &) const ) &TColStd_MapOfTransient::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_TColStd_MapOfTransient.def("Union", (void (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &, const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfTransient.def("Unite", (Standard_Boolean (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfTransient.def("HasIntersection", (Standard_Boolean (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &) const ) &TColStd_MapOfTransient::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_TColStd_MapOfTransient.def("Intersection", (void (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &, const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfTransient.def("Intersect", (Standard_Boolean (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfTransient.def("Subtraction", (void (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &, const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfTransient.def("Subtract", (Standard_Boolean (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfTransient.def("Difference", (void (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &, const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfTransient.def("Differ", (Standard_Boolean (TColStd_MapOfTransient::*)(const TColStd_MapOfTransient &)) &TColStd_MapOfTransient::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapOfTransient.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DefaultHasher.hxx
	py::class_<TColStd_MapIntegerHasher, std::unique_ptr<TColStd_MapIntegerHasher, Deleter<TColStd_MapIntegerHasher>>> cls_TColStd_MapIntegerHasher(mod, "TColStd_MapIntegerHasher", "Purpose: The DefaultHasher is a Hasher that is used by default in NCollection maps. To compute the hash code of the key is used the global function HashCode. To compare two keys is used the global function IsEqual.");
	cls_TColStd_MapIntegerHasher.def(py::init<>());
	cls_TColStd_MapIntegerHasher.def_static("HashCode_", (Standard_Integer (*)(const Standard_Integer &, const Standard_Integer)) &TColStd_MapIntegerHasher::HashCode, "None", py::arg("theKey"), py::arg("Upper"));
	cls_TColStd_MapIntegerHasher.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_Integer &, const Standard_Integer &)) &TColStd_MapIntegerHasher::IsEqual, "None", py::arg("theKey1"), py::arg("theKey2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HSequenceOfExtendedString.hxx
	py::class_<TColStd_HSequenceOfExtendedString, opencascade::handle<TColStd_HSequenceOfExtendedString>, TColStd_SequenceOfExtendedString, Standard_Transient> cls_TColStd_HSequenceOfExtendedString(mod, "TColStd_HSequenceOfExtendedString", "None");
	cls_TColStd_HSequenceOfExtendedString.def(py::init<>());
	cls_TColStd_HSequenceOfExtendedString.def(py::init<const TColStd_SequenceOfExtendedString &>(), py::arg("theOther"));
	cls_TColStd_HSequenceOfExtendedString.def("Sequence", (const TColStd_SequenceOfExtendedString & (TColStd_HSequenceOfExtendedString::*)() const ) &TColStd_HSequenceOfExtendedString::Sequence, "None");
	cls_TColStd_HSequenceOfExtendedString.def("Append", (void (TColStd_HSequenceOfExtendedString::*)(const TColStd_SequenceOfExtendedString::value_type &)) &TColStd_HSequenceOfExtendedString::Append, "None", py::arg("theItem"));
	cls_TColStd_HSequenceOfExtendedString.def("Append", (void (TColStd_HSequenceOfExtendedString::*)(TColStd_SequenceOfExtendedString &)) &TColStd_HSequenceOfExtendedString::Append, "None", py::arg("theSequence"));
	cls_TColStd_HSequenceOfExtendedString.def("ChangeSequence", (TColStd_SequenceOfExtendedString & (TColStd_HSequenceOfExtendedString::*)()) &TColStd_HSequenceOfExtendedString::ChangeSequence, "None");
	cls_TColStd_HSequenceOfExtendedString.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfExtendedString::get_type_name, "None");
	cls_TColStd_HSequenceOfExtendedString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfExtendedString::get_type_descriptor, "None");
	cls_TColStd_HSequenceOfExtendedString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfExtendedString::*)() const ) &TColStd_HSequenceOfExtendedString::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TColStd_DataMapOfIntegerListOfInteger, std::unique_ptr<TColStd_DataMapOfIntegerListOfInteger, Deleter<TColStd_DataMapOfIntegerListOfInteger>>, NCollection_BaseMap> cls_TColStd_DataMapOfIntegerListOfInteger(mod, "TColStd_DataMapOfIntegerListOfInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_DataMapOfIntegerListOfInteger.def(py::init<>());
	cls_TColStd_DataMapOfIntegerListOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def(py::init([] (const TColStd_DataMapOfIntegerListOfInteger &other) {return new TColStd_DataMapOfIntegerListOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("begin", (TColStd_DataMapOfIntegerListOfInteger::iterator (TColStd_DataMapOfIntegerListOfInteger::*)() const ) &TColStd_DataMapOfIntegerListOfInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfIntegerListOfInteger.def("end", (TColStd_DataMapOfIntegerListOfInteger::iterator (TColStd_DataMapOfIntegerListOfInteger::*)() const ) &TColStd_DataMapOfIntegerListOfInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfIntegerListOfInteger.def("cbegin", (TColStd_DataMapOfIntegerListOfInteger::const_iterator (TColStd_DataMapOfIntegerListOfInteger::*)() const ) &TColStd_DataMapOfIntegerListOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfIntegerListOfInteger.def("cend", (TColStd_DataMapOfIntegerListOfInteger::const_iterator (TColStd_DataMapOfIntegerListOfInteger::*)() const ) &TColStd_DataMapOfIntegerListOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfIntegerListOfInteger.def("Exchange", (void (TColStd_DataMapOfIntegerListOfInteger::*)(TColStd_DataMapOfIntegerListOfInteger &)) &TColStd_DataMapOfIntegerListOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("Assign", (TColStd_DataMapOfIntegerListOfInteger & (TColStd_DataMapOfIntegerListOfInteger::*)(const TColStd_DataMapOfIntegerListOfInteger &)) &TColStd_DataMapOfIntegerListOfInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("assign", (TColStd_DataMapOfIntegerListOfInteger & (TColStd_DataMapOfIntegerListOfInteger::*)(const TColStd_DataMapOfIntegerListOfInteger &)) &TColStd_DataMapOfIntegerListOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("ReSize", (void (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer)) &TColStd_DataMapOfIntegerListOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("Bind", (Standard_Boolean (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &, const TColStd_ListOfInteger &)) &TColStd_DataMapOfIntegerListOfInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TColStd_DataMapOfIntegerListOfInteger.def("Bound", (TColStd_ListOfInteger * (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &, const TColStd_ListOfInteger &)) &TColStd_DataMapOfIntegerListOfInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("IsBound", (Standard_Boolean (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerListOfInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("UnBind", (Standard_Boolean (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerListOfInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerListOfInteger.def("Seek", (const TColStd_ListOfInteger * (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerListOfInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerListOfInteger.def("Find", (const TColStd_ListOfInteger & (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerListOfInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerListOfInteger.def("Find", (Standard_Boolean (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &, TColStd_ListOfInteger &) const ) &TColStd_DataMapOfIntegerListOfInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("__call__", (const TColStd_ListOfInteger & (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerListOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerListOfInteger.def("ChangeSeek", (TColStd_ListOfInteger * (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerListOfInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("ChangeFind", (TColStd_ListOfInteger & (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerListOfInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("__call__", (TColStd_ListOfInteger & (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerListOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("Clear", [](TColStd_DataMapOfIntegerListOfInteger &self) -> void { return self.Clear(); });
	cls_TColStd_DataMapOfIntegerListOfInteger.def("Clear", (void (TColStd_DataMapOfIntegerListOfInteger::*)(const Standard_Boolean)) &TColStd_DataMapOfIntegerListOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("Clear", (void (TColStd_DataMapOfIntegerListOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_DataMapOfIntegerListOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_DataMapOfIntegerListOfInteger.def("Size", (Standard_Integer (TColStd_DataMapOfIntegerListOfInteger::*)() const ) &TColStd_DataMapOfIntegerListOfInteger::Size, "Size");
	cls_TColStd_DataMapOfIntegerListOfInteger.def("__iter__", [](const TColStd_DataMapOfIntegerListOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfIntegerListOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<TColStd_MapOfInteger, std::unique_ptr<TColStd_MapOfInteger, Deleter<TColStd_MapOfInteger>>, NCollection_BaseMap> cls_TColStd_MapOfInteger(mod, "TColStd_MapOfInteger", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_TColStd_MapOfInteger.def(py::init<>());
	cls_TColStd_MapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_MapOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_MapOfInteger.def(py::init([] (const TColStd_MapOfInteger &other) {return new TColStd_MapOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_MapOfInteger.def("cbegin", (TColStd_MapOfInteger::const_iterator (TColStd_MapOfInteger::*)() const ) &TColStd_MapOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_MapOfInteger.def("cend", (TColStd_MapOfInteger::const_iterator (TColStd_MapOfInteger::*)() const ) &TColStd_MapOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_MapOfInteger.def("Exchange", (void (TColStd_MapOfInteger::*)(TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_MapOfInteger.def("Assign", (TColStd_MapOfInteger & (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_MapOfInteger.def("assign", (TColStd_MapOfInteger & (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_TColStd_MapOfInteger.def("ReSize", (void (TColStd_MapOfInteger::*)(const Standard_Integer)) &TColStd_MapOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_MapOfInteger.def("Add", (Standard_Boolean (TColStd_MapOfInteger::*)(const Standard_Integer &)) &TColStd_MapOfInteger::Add, "Add", py::arg("K"));
	cls_TColStd_MapOfInteger.def("Added", (const Standard_Integer & (TColStd_MapOfInteger::*)(const Standard_Integer &)) &TColStd_MapOfInteger::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_TColStd_MapOfInteger.def("Contains", (Standard_Boolean (TColStd_MapOfInteger::*)(const Standard_Integer &) const ) &TColStd_MapOfInteger::Contains, "Contains", py::arg("K"));
	cls_TColStd_MapOfInteger.def("Remove", (Standard_Boolean (TColStd_MapOfInteger::*)(const Standard_Integer &)) &TColStd_MapOfInteger::Remove, "Remove", py::arg("K"));
	cls_TColStd_MapOfInteger.def("Clear", [](TColStd_MapOfInteger &self) -> void { return self.Clear(); });
	cls_TColStd_MapOfInteger.def("Clear", (void (TColStd_MapOfInteger::*)(const Standard_Boolean)) &TColStd_MapOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_MapOfInteger.def("Clear", (void (TColStd_MapOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_MapOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_MapOfInteger.def("Size", (Standard_Integer (TColStd_MapOfInteger::*)() const ) &TColStd_MapOfInteger::Size, "Size");
	cls_TColStd_MapOfInteger.def("IsEqual", (Standard_Boolean (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &) const ) &TColStd_MapOfInteger::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_TColStd_MapOfInteger.def("Contains", (Standard_Boolean (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &) const ) &TColStd_MapOfInteger::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_TColStd_MapOfInteger.def("Union", (void (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &, const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfInteger.def("Unite", (Standard_Boolean (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfInteger.def("HasIntersection", (Standard_Boolean (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &) const ) &TColStd_MapOfInteger::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_TColStd_MapOfInteger.def("Intersection", (void (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &, const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfInteger.def("Intersect", (Standard_Boolean (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfInteger.def("Subtraction", (void (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &, const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfInteger.def("Subtract", (Standard_Boolean (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfInteger.def("Difference", (void (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &, const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfInteger.def("Differ", (Standard_Boolean (TColStd_MapOfInteger::*)(const TColStd_MapOfInteger &)) &TColStd_MapOfInteger::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray1OfTransient.hxx
	py::class_<TColStd_HArray1OfTransient, opencascade::handle<TColStd_HArray1OfTransient>, TColStd_Array1OfTransient, Standard_Transient> cls_TColStd_HArray1OfTransient(mod, "TColStd_HArray1OfTransient", "None");
	cls_TColStd_HArray1OfTransient.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_HArray1OfTransient.def(py::init<const Standard_Integer, const Standard_Integer, const TColStd_Array1OfTransient::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColStd_HArray1OfTransient.def(py::init<const TColStd_Array1OfTransient &>(), py::arg("theOther"));
	cls_TColStd_HArray1OfTransient.def("Array1", (const TColStd_Array1OfTransient & (TColStd_HArray1OfTransient::*)() const ) &TColStd_HArray1OfTransient::Array1, "None");
	cls_TColStd_HArray1OfTransient.def("ChangeArray1", (TColStd_Array1OfTransient & (TColStd_HArray1OfTransient::*)()) &TColStd_HArray1OfTransient::ChangeArray1, "None");
	cls_TColStd_HArray1OfTransient.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray1OfTransient::get_type_name, "None");
	cls_TColStd_HArray1OfTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray1OfTransient::get_type_descriptor, "None");
	cls_TColStd_HArray1OfTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray1OfTransient::*)() const ) &TColStd_HArray1OfTransient::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray1OfAsciiString.hxx
	py::class_<TColStd_HArray1OfAsciiString, opencascade::handle<TColStd_HArray1OfAsciiString>, TColStd_Array1OfAsciiString, Standard_Transient> cls_TColStd_HArray1OfAsciiString(mod, "TColStd_HArray1OfAsciiString", "None");
	cls_TColStd_HArray1OfAsciiString.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_HArray1OfAsciiString.def(py::init<const Standard_Integer, const Standard_Integer, const TColStd_Array1OfAsciiString::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColStd_HArray1OfAsciiString.def(py::init<const TColStd_Array1OfAsciiString &>(), py::arg("theOther"));
	cls_TColStd_HArray1OfAsciiString.def("Array1", (const TColStd_Array1OfAsciiString & (TColStd_HArray1OfAsciiString::*)() const ) &TColStd_HArray1OfAsciiString::Array1, "None");
	cls_TColStd_HArray1OfAsciiString.def("ChangeArray1", (TColStd_Array1OfAsciiString & (TColStd_HArray1OfAsciiString::*)()) &TColStd_HArray1OfAsciiString::ChangeArray1, "None");
	cls_TColStd_HArray1OfAsciiString.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray1OfAsciiString::get_type_name, "None");
	cls_TColStd_HArray1OfAsciiString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray1OfAsciiString::get_type_descriptor, "None");
	cls_TColStd_HArray1OfAsciiString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray1OfAsciiString::*)() const ) &TColStd_HArray1OfAsciiString::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HSequenceOfHAsciiString.hxx
	py::class_<TColStd_HSequenceOfHAsciiString, opencascade::handle<TColStd_HSequenceOfHAsciiString>, TColStd_SequenceOfHAsciiString, Standard_Transient> cls_TColStd_HSequenceOfHAsciiString(mod, "TColStd_HSequenceOfHAsciiString", "None");
	cls_TColStd_HSequenceOfHAsciiString.def(py::init<>());
	cls_TColStd_HSequenceOfHAsciiString.def(py::init<const TColStd_SequenceOfHAsciiString &>(), py::arg("theOther"));
	cls_TColStd_HSequenceOfHAsciiString.def("Sequence", (const TColStd_SequenceOfHAsciiString & (TColStd_HSequenceOfHAsciiString::*)() const ) &TColStd_HSequenceOfHAsciiString::Sequence, "None");
	cls_TColStd_HSequenceOfHAsciiString.def("Append", (void (TColStd_HSequenceOfHAsciiString::*)(const TColStd_SequenceOfHAsciiString::value_type &)) &TColStd_HSequenceOfHAsciiString::Append, "None", py::arg("theItem"));
	cls_TColStd_HSequenceOfHAsciiString.def("Append", (void (TColStd_HSequenceOfHAsciiString::*)(TColStd_SequenceOfHAsciiString &)) &TColStd_HSequenceOfHAsciiString::Append, "None", py::arg("theSequence"));
	cls_TColStd_HSequenceOfHAsciiString.def("ChangeSequence", (TColStd_SequenceOfHAsciiString & (TColStd_HSequenceOfHAsciiString::*)()) &TColStd_HSequenceOfHAsciiString::ChangeSequence, "None");
	cls_TColStd_HSequenceOfHAsciiString.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfHAsciiString::get_type_name, "None");
	cls_TColStd_HSequenceOfHAsciiString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfHAsciiString::get_type_descriptor, "None");
	cls_TColStd_HSequenceOfHAsciiString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfHAsciiString::*)() const ) &TColStd_HSequenceOfHAsciiString::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray2OfInteger.hxx
	py::class_<TColStd_HArray2OfInteger, opencascade::handle<TColStd_HArray2OfInteger>, TColStd_Array2OfInteger, Standard_Transient> cls_TColStd_HArray2OfInteger(mod, "TColStd_HArray2OfInteger", "None");
	cls_TColStd_HArray2OfInteger.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColStd_HArray2OfInteger.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array2OfInteger::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColStd_HArray2OfInteger.def(py::init<const TColStd_Array2OfInteger &>(), py::arg("theOther"));
	cls_TColStd_HArray2OfInteger.def("Array2", (const TColStd_Array2OfInteger & (TColStd_HArray2OfInteger::*)() const ) &TColStd_HArray2OfInteger::Array2, "None");
	cls_TColStd_HArray2OfInteger.def("ChangeArray2", (TColStd_Array2OfInteger & (TColStd_HArray2OfInteger::*)()) &TColStd_HArray2OfInteger::ChangeArray2, "None");
	cls_TColStd_HArray2OfInteger.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray2OfInteger::get_type_name, "None");
	cls_TColStd_HArray2OfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray2OfInteger::get_type_descriptor, "None");
	cls_TColStd_HArray2OfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray2OfInteger::*)() const ) &TColStd_HArray2OfInteger::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HSequenceOfAsciiString.hxx
	py::class_<TColStd_HSequenceOfAsciiString, opencascade::handle<TColStd_HSequenceOfAsciiString>, TColStd_SequenceOfAsciiString, Standard_Transient> cls_TColStd_HSequenceOfAsciiString(mod, "TColStd_HSequenceOfAsciiString", "None");
	cls_TColStd_HSequenceOfAsciiString.def(py::init<>());
	cls_TColStd_HSequenceOfAsciiString.def(py::init<const TColStd_SequenceOfAsciiString &>(), py::arg("theOther"));
	cls_TColStd_HSequenceOfAsciiString.def("Sequence", (const TColStd_SequenceOfAsciiString & (TColStd_HSequenceOfAsciiString::*)() const ) &TColStd_HSequenceOfAsciiString::Sequence, "None");
	cls_TColStd_HSequenceOfAsciiString.def("Append", (void (TColStd_HSequenceOfAsciiString::*)(const TColStd_SequenceOfAsciiString::value_type &)) &TColStd_HSequenceOfAsciiString::Append, "None", py::arg("theItem"));
	cls_TColStd_HSequenceOfAsciiString.def("Append", (void (TColStd_HSequenceOfAsciiString::*)(TColStd_SequenceOfAsciiString &)) &TColStd_HSequenceOfAsciiString::Append, "None", py::arg("theSequence"));
	cls_TColStd_HSequenceOfAsciiString.def("ChangeSequence", (TColStd_SequenceOfAsciiString & (TColStd_HSequenceOfAsciiString::*)()) &TColStd_HSequenceOfAsciiString::ChangeSequence, "None");
	cls_TColStd_HSequenceOfAsciiString.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfAsciiString::get_type_name, "None");
	cls_TColStd_HSequenceOfAsciiString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfAsciiString::get_type_descriptor, "None");
	cls_TColStd_HSequenceOfAsciiString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfAsciiString::*)() const ) &TColStd_HSequenceOfAsciiString::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColStd_SequenceOfAddress, std::unique_ptr<TColStd_SequenceOfAddress, Deleter<TColStd_SequenceOfAddress>>, NCollection_BaseSequence> cls_TColStd_SequenceOfAddress(mod, "TColStd_SequenceOfAddress", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColStd_SequenceOfAddress.def(py::init<>());
	cls_TColStd_SequenceOfAddress.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_SequenceOfAddress.def(py::init([] (const TColStd_SequenceOfAddress &other) {return new TColStd_SequenceOfAddress(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_SequenceOfAddress.def("begin", (TColStd_SequenceOfAddress::iterator (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfAddress.def("end", (TColStd_SequenceOfAddress::iterator (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfAddress.def("cbegin", (TColStd_SequenceOfAddress::const_iterator (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfAddress.def("cend", (TColStd_SequenceOfAddress::const_iterator (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfAddress.def("Size", (Standard_Integer (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::Size, "Number of items");
	cls_TColStd_SequenceOfAddress.def("Length", (Standard_Integer (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::Length, "Number of items");
	cls_TColStd_SequenceOfAddress.def("Lower", (Standard_Integer (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::Lower, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfAddress.def("Upper", (Standard_Integer (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::Upper, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfAddress.def("IsEmpty", (Standard_Boolean (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::IsEmpty, "Empty query");
	cls_TColStd_SequenceOfAddress.def("Reverse", (void (TColStd_SequenceOfAddress::*)()) &TColStd_SequenceOfAddress::Reverse, "Reverse sequence");
	cls_TColStd_SequenceOfAddress.def("Exchange", (void (TColStd_SequenceOfAddress::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfAddress::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColStd_SequenceOfAddress.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfAddress::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColStd_SequenceOfAddress.def("Clear", [](TColStd_SequenceOfAddress &self) -> void { return self.Clear(); });
	cls_TColStd_SequenceOfAddress.def("Clear", (void (TColStd_SequenceOfAddress::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfAddress::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColStd_SequenceOfAddress.def("Assign", (TColStd_SequenceOfAddress & (TColStd_SequenceOfAddress::*)(const TColStd_SequenceOfAddress &)) &TColStd_SequenceOfAddress::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_SequenceOfAddress.def("assign", (TColStd_SequenceOfAddress & (TColStd_SequenceOfAddress::*)(const TColStd_SequenceOfAddress &)) &TColStd_SequenceOfAddress::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_SequenceOfAddress.def("Remove", (void (TColStd_SequenceOfAddress::*)(TColStd_SequenceOfAddress::Iterator &)) &TColStd_SequenceOfAddress::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColStd_SequenceOfAddress.def("Remove", (void (TColStd_SequenceOfAddress::*)(const Standard_Integer)) &TColStd_SequenceOfAddress::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColStd_SequenceOfAddress.def("Remove", (void (TColStd_SequenceOfAddress::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfAddress::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColStd_SequenceOfAddress.def("Append", (void (TColStd_SequenceOfAddress::*)(const Standard_Address &)) &TColStd_SequenceOfAddress::Append, "Append one item", py::arg("theItem"));
	cls_TColStd_SequenceOfAddress.def("Append", (void (TColStd_SequenceOfAddress::*)(TColStd_SequenceOfAddress &)) &TColStd_SequenceOfAddress::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfAddress.def("Prepend", (void (TColStd_SequenceOfAddress::*)(const Standard_Address &)) &TColStd_SequenceOfAddress::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColStd_SequenceOfAddress.def("Prepend", (void (TColStd_SequenceOfAddress::*)(TColStd_SequenceOfAddress &)) &TColStd_SequenceOfAddress::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfAddress.def("InsertBefore", (void (TColStd_SequenceOfAddress::*)(const Standard_Integer, const Standard_Address &)) &TColStd_SequenceOfAddress::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfAddress.def("InsertBefore", (void (TColStd_SequenceOfAddress::*)(const Standard_Integer, TColStd_SequenceOfAddress &)) &TColStd_SequenceOfAddress::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfAddress.def("InsertAfter", (void (TColStd_SequenceOfAddress::*)(TColStd_SequenceOfAddress::Iterator &, const Standard_Address &)) &TColStd_SequenceOfAddress::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColStd_SequenceOfAddress.def("InsertAfter", (void (TColStd_SequenceOfAddress::*)(const Standard_Integer, TColStd_SequenceOfAddress &)) &TColStd_SequenceOfAddress::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfAddress.def("InsertAfter", (void (TColStd_SequenceOfAddress::*)(const Standard_Integer, const Standard_Address &)) &TColStd_SequenceOfAddress::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfAddress.def("Split", (void (TColStd_SequenceOfAddress::*)(const Standard_Integer, TColStd_SequenceOfAddress &)) &TColStd_SequenceOfAddress::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfAddress.def("First", (const Standard_Address & (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::First, "First item access");
	cls_TColStd_SequenceOfAddress.def("ChangeFirst", (Standard_Address & (TColStd_SequenceOfAddress::*)()) &TColStd_SequenceOfAddress::ChangeFirst, "First item access");
	cls_TColStd_SequenceOfAddress.def("Last", (const Standard_Address & (TColStd_SequenceOfAddress::*)() const ) &TColStd_SequenceOfAddress::Last, "Last item access");
	cls_TColStd_SequenceOfAddress.def("ChangeLast", (Standard_Address & (TColStd_SequenceOfAddress::*)()) &TColStd_SequenceOfAddress::ChangeLast, "Last item access");
	cls_TColStd_SequenceOfAddress.def("Value", (const Standard_Address & (TColStd_SequenceOfAddress::*)(const Standard_Integer) const ) &TColStd_SequenceOfAddress::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfAddress.def("__call__", (const Standard_Address & (TColStd_SequenceOfAddress::*)(const Standard_Integer) const ) &TColStd_SequenceOfAddress::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfAddress.def("ChangeValue", (Standard_Address & (TColStd_SequenceOfAddress::*)(const Standard_Integer)) &TColStd_SequenceOfAddress::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfAddress.def("__call__", (Standard_Address & (TColStd_SequenceOfAddress::*)(const Standard_Integer)) &TColStd_SequenceOfAddress::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfAddress.def("SetValue", (void (TColStd_SequenceOfAddress::*)(const Standard_Integer, const Standard_Address &)) &TColStd_SequenceOfAddress::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfAddress.def("__iter__", [](const TColStd_SequenceOfAddress &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TColStd_DataMapOfIntegerTransient, std::unique_ptr<TColStd_DataMapOfIntegerTransient, Deleter<TColStd_DataMapOfIntegerTransient>>, NCollection_BaseMap> cls_TColStd_DataMapOfIntegerTransient(mod, "TColStd_DataMapOfIntegerTransient", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_DataMapOfIntegerTransient.def(py::init<>());
	cls_TColStd_DataMapOfIntegerTransient.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_DataMapOfIntegerTransient.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_DataMapOfIntegerTransient.def(py::init([] (const TColStd_DataMapOfIntegerTransient &other) {return new TColStd_DataMapOfIntegerTransient(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_DataMapOfIntegerTransient.def("begin", (TColStd_DataMapOfIntegerTransient::iterator (TColStd_DataMapOfIntegerTransient::*)() const ) &TColStd_DataMapOfIntegerTransient::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfIntegerTransient.def("end", (TColStd_DataMapOfIntegerTransient::iterator (TColStd_DataMapOfIntegerTransient::*)() const ) &TColStd_DataMapOfIntegerTransient::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfIntegerTransient.def("cbegin", (TColStd_DataMapOfIntegerTransient::const_iterator (TColStd_DataMapOfIntegerTransient::*)() const ) &TColStd_DataMapOfIntegerTransient::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfIntegerTransient.def("cend", (TColStd_DataMapOfIntegerTransient::const_iterator (TColStd_DataMapOfIntegerTransient::*)() const ) &TColStd_DataMapOfIntegerTransient::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfIntegerTransient.def("Exchange", (void (TColStd_DataMapOfIntegerTransient::*)(TColStd_DataMapOfIntegerTransient &)) &TColStd_DataMapOfIntegerTransient::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerTransient.def("Assign", (TColStd_DataMapOfIntegerTransient & (TColStd_DataMapOfIntegerTransient::*)(const TColStd_DataMapOfIntegerTransient &)) &TColStd_DataMapOfIntegerTransient::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerTransient.def("assign", (TColStd_DataMapOfIntegerTransient & (TColStd_DataMapOfIntegerTransient::*)(const TColStd_DataMapOfIntegerTransient &)) &TColStd_DataMapOfIntegerTransient::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerTransient.def("ReSize", (void (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer)) &TColStd_DataMapOfIntegerTransient::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_DataMapOfIntegerTransient.def("Bind", (Standard_Boolean (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &, const opencascade::handle<Standard_Transient> &)) &TColStd_DataMapOfIntegerTransient::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TColStd_DataMapOfIntegerTransient.def("Bound", (opencascade::handle<Standard_Transient> * (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &, const opencascade::handle<Standard_Transient> &)) &TColStd_DataMapOfIntegerTransient::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TColStd_DataMapOfIntegerTransient.def("IsBound", (Standard_Boolean (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerTransient::IsBound, "IsBound", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerTransient.def("UnBind", (Standard_Boolean (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerTransient::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerTransient.def("Seek", (const opencascade::handle<Standard_Transient> * (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerTransient::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerTransient.def("Find", (const opencascade::handle<Standard_Transient> & (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerTransient::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerTransient.def("Find", (Standard_Boolean (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &, opencascade::handle<Standard_Transient> &) const ) &TColStd_DataMapOfIntegerTransient::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TColStd_DataMapOfIntegerTransient.def("__call__", (const opencascade::handle<Standard_Transient> & (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerTransient::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerTransient.def("ChangeSeek", (opencascade::handle<Standard_Transient> * (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerTransient::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerTransient.def("ChangeFind", (opencascade::handle<Standard_Transient> & (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerTransient::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerTransient.def("__call__", (opencascade::handle<Standard_Transient> & (TColStd_DataMapOfIntegerTransient::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerTransient::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerTransient.def("Clear", [](TColStd_DataMapOfIntegerTransient &self) -> void { return self.Clear(); });
	cls_TColStd_DataMapOfIntegerTransient.def("Clear", (void (TColStd_DataMapOfIntegerTransient::*)(const Standard_Boolean)) &TColStd_DataMapOfIntegerTransient::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_DataMapOfIntegerTransient.def("Clear", (void (TColStd_DataMapOfIntegerTransient::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_DataMapOfIntegerTransient::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_DataMapOfIntegerTransient.def("Size", (Standard_Integer (TColStd_DataMapOfIntegerTransient::*)() const ) &TColStd_DataMapOfIntegerTransient::Size, "Size");
	cls_TColStd_DataMapOfIntegerTransient.def("__iter__", [](const TColStd_DataMapOfIntegerTransient &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfIntegerTransient.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
	py::class_<TColStd_IndexedMapOfTransient, std::unique_ptr<TColStd_IndexedMapOfTransient, Deleter<TColStd_IndexedMapOfTransient>>, NCollection_BaseMap> cls_TColStd_IndexedMapOfTransient(mod, "TColStd_IndexedMapOfTransient", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_IndexedMapOfTransient.def(py::init<>());
	cls_TColStd_IndexedMapOfTransient.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_IndexedMapOfTransient.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_IndexedMapOfTransient.def(py::init([] (const TColStd_IndexedMapOfTransient &other) {return new TColStd_IndexedMapOfTransient(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_IndexedMapOfTransient.def("cbegin", (TColStd_IndexedMapOfTransient::const_iterator (TColStd_IndexedMapOfTransient::*)() const ) &TColStd_IndexedMapOfTransient::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_IndexedMapOfTransient.def("cend", (TColStd_IndexedMapOfTransient::const_iterator (TColStd_IndexedMapOfTransient::*)() const ) &TColStd_IndexedMapOfTransient::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_IndexedMapOfTransient.def("Exchange", (void (TColStd_IndexedMapOfTransient::*)(TColStd_IndexedMapOfTransient &)) &TColStd_IndexedMapOfTransient::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_IndexedMapOfTransient.def("Assign", (TColStd_IndexedMapOfTransient & (TColStd_IndexedMapOfTransient::*)(const TColStd_IndexedMapOfTransient &)) &TColStd_IndexedMapOfTransient::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_IndexedMapOfTransient.def("assign", (TColStd_IndexedMapOfTransient & (TColStd_IndexedMapOfTransient::*)(const TColStd_IndexedMapOfTransient &)) &TColStd_IndexedMapOfTransient::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_IndexedMapOfTransient.def("ReSize", (void (TColStd_IndexedMapOfTransient::*)(const Standard_Integer)) &TColStd_IndexedMapOfTransient::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_IndexedMapOfTransient.def("Add", (Standard_Integer (TColStd_IndexedMapOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_IndexedMapOfTransient::Add, "Add", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfTransient.def("Contains", (Standard_Boolean (TColStd_IndexedMapOfTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_IndexedMapOfTransient::Contains, "Contains", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfTransient.def("Substitute", (void (TColStd_IndexedMapOfTransient::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &TColStd_IndexedMapOfTransient::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
	cls_TColStd_IndexedMapOfTransient.def("Swap", (void (TColStd_IndexedMapOfTransient::*)(const Standard_Integer, const Standard_Integer)) &TColStd_IndexedMapOfTransient::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TColStd_IndexedMapOfTransient.def("RemoveLast", (void (TColStd_IndexedMapOfTransient::*)()) &TColStd_IndexedMapOfTransient::RemoveLast, "RemoveLast");
	cls_TColStd_IndexedMapOfTransient.def("RemoveFromIndex", (void (TColStd_IndexedMapOfTransient::*)(const Standard_Integer)) &TColStd_IndexedMapOfTransient::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TColStd_IndexedMapOfTransient.def("RemoveKey", (Standard_Boolean (TColStd_IndexedMapOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_IndexedMapOfTransient::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfTransient.def("FindKey", (const opencascade::handle<Standard_Transient> & (TColStd_IndexedMapOfTransient::*)(const Standard_Integer) const ) &TColStd_IndexedMapOfTransient::FindKey, "FindKey", py::arg("theKey2"));
	cls_TColStd_IndexedMapOfTransient.def("__call__", (const opencascade::handle<Standard_Transient> & (TColStd_IndexedMapOfTransient::*)(const Standard_Integer) const ) &TColStd_IndexedMapOfTransient::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TColStd_IndexedMapOfTransient.def("FindIndex", (Standard_Integer (TColStd_IndexedMapOfTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_IndexedMapOfTransient::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfTransient.def("Clear", [](TColStd_IndexedMapOfTransient &self) -> void { return self.Clear(); });
	cls_TColStd_IndexedMapOfTransient.def("Clear", (void (TColStd_IndexedMapOfTransient::*)(const Standard_Boolean)) &TColStd_IndexedMapOfTransient::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_IndexedMapOfTransient.def("Clear", (void (TColStd_IndexedMapOfTransient::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_IndexedMapOfTransient::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_IndexedMapOfTransient.def("Size", (Standard_Integer (TColStd_IndexedMapOfTransient::*)() const ) &TColStd_IndexedMapOfTransient::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TColStd_DataMapOfAsciiStringInteger, std::unique_ptr<TColStd_DataMapOfAsciiStringInteger, Deleter<TColStd_DataMapOfAsciiStringInteger>>, NCollection_BaseMap> cls_TColStd_DataMapOfAsciiStringInteger(mod, "TColStd_DataMapOfAsciiStringInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_DataMapOfAsciiStringInteger.def(py::init<>());
	cls_TColStd_DataMapOfAsciiStringInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_DataMapOfAsciiStringInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_DataMapOfAsciiStringInteger.def(py::init([] (const TColStd_DataMapOfAsciiStringInteger &other) {return new TColStd_DataMapOfAsciiStringInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("begin", (TColStd_DataMapOfAsciiStringInteger::iterator (TColStd_DataMapOfAsciiStringInteger::*)() const ) &TColStd_DataMapOfAsciiStringInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfAsciiStringInteger.def("end", (TColStd_DataMapOfAsciiStringInteger::iterator (TColStd_DataMapOfAsciiStringInteger::*)() const ) &TColStd_DataMapOfAsciiStringInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfAsciiStringInteger.def("cbegin", (TColStd_DataMapOfAsciiStringInteger::const_iterator (TColStd_DataMapOfAsciiStringInteger::*)() const ) &TColStd_DataMapOfAsciiStringInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfAsciiStringInteger.def("cend", (TColStd_DataMapOfAsciiStringInteger::const_iterator (TColStd_DataMapOfAsciiStringInteger::*)() const ) &TColStd_DataMapOfAsciiStringInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfAsciiStringInteger.def("Exchange", (void (TColStd_DataMapOfAsciiStringInteger::*)(TColStd_DataMapOfAsciiStringInteger &)) &TColStd_DataMapOfAsciiStringInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("Assign", (TColStd_DataMapOfAsciiStringInteger & (TColStd_DataMapOfAsciiStringInteger::*)(const TColStd_DataMapOfAsciiStringInteger &)) &TColStd_DataMapOfAsciiStringInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("assign", (TColStd_DataMapOfAsciiStringInteger & (TColStd_DataMapOfAsciiStringInteger::*)(const TColStd_DataMapOfAsciiStringInteger &)) &TColStd_DataMapOfAsciiStringInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("ReSize", (void (TColStd_DataMapOfAsciiStringInteger::*)(const Standard_Integer)) &TColStd_DataMapOfAsciiStringInteger::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("Bind", (Standard_Boolean (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &, const Standard_Integer &)) &TColStd_DataMapOfAsciiStringInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TColStd_DataMapOfAsciiStringInteger.def("Bound", (Standard_Integer * (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &, const Standard_Integer &)) &TColStd_DataMapOfAsciiStringInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("IsBound", (Standard_Boolean (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &) const ) &TColStd_DataMapOfAsciiStringInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("UnBind", (Standard_Boolean (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &)) &TColStd_DataMapOfAsciiStringInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfAsciiStringInteger.def("Seek", (const Standard_Integer * (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &) const ) &TColStd_DataMapOfAsciiStringInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfAsciiStringInteger.def("Find", (const Standard_Integer & (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &) const ) &TColStd_DataMapOfAsciiStringInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfAsciiStringInteger.def("Find", (Standard_Boolean (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &, Standard_Integer &) const ) &TColStd_DataMapOfAsciiStringInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("__call__", (const Standard_Integer & (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &) const ) &TColStd_DataMapOfAsciiStringInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfAsciiStringInteger.def("ChangeSeek", (Standard_Integer * (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &)) &TColStd_DataMapOfAsciiStringInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("ChangeFind", (Standard_Integer & (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &)) &TColStd_DataMapOfAsciiStringInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("__call__", (Standard_Integer & (TColStd_DataMapOfAsciiStringInteger::*)(const TCollection_AsciiString &)) &TColStd_DataMapOfAsciiStringInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("Clear", [](TColStd_DataMapOfAsciiStringInteger &self) -> void { return self.Clear(); });
	cls_TColStd_DataMapOfAsciiStringInteger.def("Clear", (void (TColStd_DataMapOfAsciiStringInteger::*)(const Standard_Boolean)) &TColStd_DataMapOfAsciiStringInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("Clear", (void (TColStd_DataMapOfAsciiStringInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_DataMapOfAsciiStringInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_DataMapOfAsciiStringInteger.def("Size", (Standard_Integer (TColStd_DataMapOfAsciiStringInteger::*)() const ) &TColStd_DataMapOfAsciiStringInteger::Size, "Size");
	cls_TColStd_DataMapOfAsciiStringInteger.def("__iter__", [](const TColStd_DataMapOfAsciiStringInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfAsciiStringInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TColStd_DataMapOfIntegerInteger, std::unique_ptr<TColStd_DataMapOfIntegerInteger, Deleter<TColStd_DataMapOfIntegerInteger>>, NCollection_BaseMap> cls_TColStd_DataMapOfIntegerInteger(mod, "TColStd_DataMapOfIntegerInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_DataMapOfIntegerInteger.def(py::init<>());
	cls_TColStd_DataMapOfIntegerInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_DataMapOfIntegerInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_DataMapOfIntegerInteger.def(py::init([] (const TColStd_DataMapOfIntegerInteger &other) {return new TColStd_DataMapOfIntegerInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_DataMapOfIntegerInteger.def("begin", (TColStd_DataMapOfIntegerInteger::iterator (TColStd_DataMapOfIntegerInteger::*)() const ) &TColStd_DataMapOfIntegerInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfIntegerInteger.def("end", (TColStd_DataMapOfIntegerInteger::iterator (TColStd_DataMapOfIntegerInteger::*)() const ) &TColStd_DataMapOfIntegerInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfIntegerInteger.def("cbegin", (TColStd_DataMapOfIntegerInteger::const_iterator (TColStd_DataMapOfIntegerInteger::*)() const ) &TColStd_DataMapOfIntegerInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfIntegerInteger.def("cend", (TColStd_DataMapOfIntegerInteger::const_iterator (TColStd_DataMapOfIntegerInteger::*)() const ) &TColStd_DataMapOfIntegerInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfIntegerInteger.def("Exchange", (void (TColStd_DataMapOfIntegerInteger::*)(TColStd_DataMapOfIntegerInteger &)) &TColStd_DataMapOfIntegerInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerInteger.def("Assign", (TColStd_DataMapOfIntegerInteger & (TColStd_DataMapOfIntegerInteger::*)(const TColStd_DataMapOfIntegerInteger &)) &TColStd_DataMapOfIntegerInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerInteger.def("assign", (TColStd_DataMapOfIntegerInteger & (TColStd_DataMapOfIntegerInteger::*)(const TColStd_DataMapOfIntegerInteger &)) &TColStd_DataMapOfIntegerInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerInteger.def("ReSize", (void (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer)) &TColStd_DataMapOfIntegerInteger::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_DataMapOfIntegerInteger.def("Bind", (Standard_Boolean (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &, const Standard_Integer &)) &TColStd_DataMapOfIntegerInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TColStd_DataMapOfIntegerInteger.def("Bound", (Standard_Integer * (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &, const Standard_Integer &)) &TColStd_DataMapOfIntegerInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TColStd_DataMapOfIntegerInteger.def("IsBound", (Standard_Boolean (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerInteger.def("UnBind", (Standard_Boolean (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerInteger.def("Seek", (const Standard_Integer * (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerInteger.def("Find", (const Standard_Integer & (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerInteger.def("Find", (Standard_Boolean (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &, Standard_Integer &) const ) &TColStd_DataMapOfIntegerInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TColStd_DataMapOfIntegerInteger.def("__call__", (const Standard_Integer & (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerInteger.def("ChangeSeek", (Standard_Integer * (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerInteger.def("ChangeFind", (Standard_Integer & (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerInteger.def("__call__", (Standard_Integer & (TColStd_DataMapOfIntegerInteger::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerInteger.def("Clear", [](TColStd_DataMapOfIntegerInteger &self) -> void { return self.Clear(); });
	cls_TColStd_DataMapOfIntegerInteger.def("Clear", (void (TColStd_DataMapOfIntegerInteger::*)(const Standard_Boolean)) &TColStd_DataMapOfIntegerInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_DataMapOfIntegerInteger.def("Clear", (void (TColStd_DataMapOfIntegerInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_DataMapOfIntegerInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_DataMapOfIntegerInteger.def("Size", (Standard_Integer (TColStd_DataMapOfIntegerInteger::*)() const ) &TColStd_DataMapOfIntegerInteger::Size, "Size");
	cls_TColStd_DataMapOfIntegerInteger.def("__iter__", [](const TColStd_DataMapOfIntegerInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfIntegerInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray1OfListOfInteger.hxx
	py::class_<TColStd_HArray1OfListOfInteger, opencascade::handle<TColStd_HArray1OfListOfInteger>, TColStd_Array1OfListOfInteger, Standard_Transient> cls_TColStd_HArray1OfListOfInteger(mod, "TColStd_HArray1OfListOfInteger", "None");
	cls_TColStd_HArray1OfListOfInteger.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_HArray1OfListOfInteger.def(py::init<const Standard_Integer, const Standard_Integer, const TColStd_Array1OfListOfInteger::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColStd_HArray1OfListOfInteger.def(py::init<const TColStd_Array1OfListOfInteger &>(), py::arg("theOther"));
	cls_TColStd_HArray1OfListOfInteger.def("Array1", (const TColStd_Array1OfListOfInteger & (TColStd_HArray1OfListOfInteger::*)() const ) &TColStd_HArray1OfListOfInteger::Array1, "None");
	cls_TColStd_HArray1OfListOfInteger.def("ChangeArray1", (TColStd_Array1OfListOfInteger & (TColStd_HArray1OfListOfInteger::*)()) &TColStd_HArray1OfListOfInteger::ChangeArray1, "None");
	cls_TColStd_HArray1OfListOfInteger.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray1OfListOfInteger::get_type_name, "None");
	cls_TColStd_HArray1OfListOfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray1OfListOfInteger::get_type_descriptor, "None");
	cls_TColStd_HArray1OfListOfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray1OfListOfInteger::*)() const ) &TColStd_HArray1OfListOfInteger::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
	py::class_<TColStd_IndexedMapOfInteger, std::unique_ptr<TColStd_IndexedMapOfInteger, Deleter<TColStd_IndexedMapOfInteger>>, NCollection_BaseMap> cls_TColStd_IndexedMapOfInteger(mod, "TColStd_IndexedMapOfInteger", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_IndexedMapOfInteger.def(py::init<>());
	cls_TColStd_IndexedMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_IndexedMapOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_IndexedMapOfInteger.def(py::init([] (const TColStd_IndexedMapOfInteger &other) {return new TColStd_IndexedMapOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_IndexedMapOfInteger.def("cbegin", (TColStd_IndexedMapOfInteger::const_iterator (TColStd_IndexedMapOfInteger::*)() const ) &TColStd_IndexedMapOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_IndexedMapOfInteger.def("cend", (TColStd_IndexedMapOfInteger::const_iterator (TColStd_IndexedMapOfInteger::*)() const ) &TColStd_IndexedMapOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_IndexedMapOfInteger.def("Exchange", (void (TColStd_IndexedMapOfInteger::*)(TColStd_IndexedMapOfInteger &)) &TColStd_IndexedMapOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_IndexedMapOfInteger.def("Assign", (TColStd_IndexedMapOfInteger & (TColStd_IndexedMapOfInteger::*)(const TColStd_IndexedMapOfInteger &)) &TColStd_IndexedMapOfInteger::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_IndexedMapOfInteger.def("assign", (TColStd_IndexedMapOfInteger & (TColStd_IndexedMapOfInteger::*)(const TColStd_IndexedMapOfInteger &)) &TColStd_IndexedMapOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_IndexedMapOfInteger.def("ReSize", (void (TColStd_IndexedMapOfInteger::*)(const Standard_Integer)) &TColStd_IndexedMapOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_IndexedMapOfInteger.def("Add", (Standard_Integer (TColStd_IndexedMapOfInteger::*)(const Standard_Integer &)) &TColStd_IndexedMapOfInteger::Add, "Add", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfInteger.def("Contains", (Standard_Boolean (TColStd_IndexedMapOfInteger::*)(const Standard_Integer &) const ) &TColStd_IndexedMapOfInteger::Contains, "Contains", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfInteger.def("Substitute", (void (TColStd_IndexedMapOfInteger::*)(const Standard_Integer, const Standard_Integer &)) &TColStd_IndexedMapOfInteger::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
	cls_TColStd_IndexedMapOfInteger.def("Swap", (void (TColStd_IndexedMapOfInteger::*)(const Standard_Integer, const Standard_Integer)) &TColStd_IndexedMapOfInteger::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TColStd_IndexedMapOfInteger.def("RemoveLast", (void (TColStd_IndexedMapOfInteger::*)()) &TColStd_IndexedMapOfInteger::RemoveLast, "RemoveLast");
	cls_TColStd_IndexedMapOfInteger.def("RemoveFromIndex", (void (TColStd_IndexedMapOfInteger::*)(const Standard_Integer)) &TColStd_IndexedMapOfInteger::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TColStd_IndexedMapOfInteger.def("RemoveKey", (Standard_Boolean (TColStd_IndexedMapOfInteger::*)(const Standard_Integer &)) &TColStd_IndexedMapOfInteger::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfInteger.def("FindKey", (const Standard_Integer & (TColStd_IndexedMapOfInteger::*)(const Standard_Integer) const ) &TColStd_IndexedMapOfInteger::FindKey, "FindKey", py::arg("theKey2"));
	cls_TColStd_IndexedMapOfInteger.def("__call__", (const Standard_Integer & (TColStd_IndexedMapOfInteger::*)(const Standard_Integer) const ) &TColStd_IndexedMapOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TColStd_IndexedMapOfInteger.def("FindIndex", (Standard_Integer (TColStd_IndexedMapOfInteger::*)(const Standard_Integer &) const ) &TColStd_IndexedMapOfInteger::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfInteger.def("Clear", [](TColStd_IndexedMapOfInteger &self) -> void { return self.Clear(); });
	cls_TColStd_IndexedMapOfInteger.def("Clear", (void (TColStd_IndexedMapOfInteger::*)(const Standard_Boolean)) &TColStd_IndexedMapOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_IndexedMapOfInteger.def("Clear", (void (TColStd_IndexedMapOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_IndexedMapOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_IndexedMapOfInteger.def("Size", (Standard_Integer (TColStd_IndexedMapOfInteger::*)() const ) &TColStd_IndexedMapOfInteger::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColStd_SequenceOfBoolean, std::unique_ptr<TColStd_SequenceOfBoolean, Deleter<TColStd_SequenceOfBoolean>>, NCollection_BaseSequence> cls_TColStd_SequenceOfBoolean(mod, "TColStd_SequenceOfBoolean", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColStd_SequenceOfBoolean.def(py::init<>());
	cls_TColStd_SequenceOfBoolean.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_SequenceOfBoolean.def(py::init([] (const TColStd_SequenceOfBoolean &other) {return new TColStd_SequenceOfBoolean(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_SequenceOfBoolean.def("begin", (TColStd_SequenceOfBoolean::iterator (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfBoolean.def("end", (TColStd_SequenceOfBoolean::iterator (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfBoolean.def("cbegin", (TColStd_SequenceOfBoolean::const_iterator (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColStd_SequenceOfBoolean.def("cend", (TColStd_SequenceOfBoolean::const_iterator (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColStd_SequenceOfBoolean.def("Size", (Standard_Integer (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::Size, "Number of items");
	cls_TColStd_SequenceOfBoolean.def("Length", (Standard_Integer (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::Length, "Number of items");
	cls_TColStd_SequenceOfBoolean.def("Lower", (Standard_Integer (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::Lower, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfBoolean.def("Upper", (Standard_Integer (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::Upper, "Method for consistency with other collections.");
	cls_TColStd_SequenceOfBoolean.def("IsEmpty", (Standard_Boolean (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::IsEmpty, "Empty query");
	cls_TColStd_SequenceOfBoolean.def("Reverse", (void (TColStd_SequenceOfBoolean::*)()) &TColStd_SequenceOfBoolean::Reverse, "Reverse sequence");
	cls_TColStd_SequenceOfBoolean.def("Exchange", (void (TColStd_SequenceOfBoolean::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfBoolean::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColStd_SequenceOfBoolean.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfBoolean::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColStd_SequenceOfBoolean.def("Clear", [](TColStd_SequenceOfBoolean &self) -> void { return self.Clear(); });
	cls_TColStd_SequenceOfBoolean.def("Clear", (void (TColStd_SequenceOfBoolean::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_SequenceOfBoolean::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColStd_SequenceOfBoolean.def("Assign", (TColStd_SequenceOfBoolean & (TColStd_SequenceOfBoolean::*)(const TColStd_SequenceOfBoolean &)) &TColStd_SequenceOfBoolean::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_SequenceOfBoolean.def("assign", (TColStd_SequenceOfBoolean & (TColStd_SequenceOfBoolean::*)(const TColStd_SequenceOfBoolean &)) &TColStd_SequenceOfBoolean::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_SequenceOfBoolean.def("Remove", (void (TColStd_SequenceOfBoolean::*)(TColStd_SequenceOfBoolean::Iterator &)) &TColStd_SequenceOfBoolean::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColStd_SequenceOfBoolean.def("Remove", (void (TColStd_SequenceOfBoolean::*)(const Standard_Integer)) &TColStd_SequenceOfBoolean::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColStd_SequenceOfBoolean.def("Remove", (void (TColStd_SequenceOfBoolean::*)(const Standard_Integer, const Standard_Integer)) &TColStd_SequenceOfBoolean::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColStd_SequenceOfBoolean.def("Append", (void (TColStd_SequenceOfBoolean::*)(const Standard_Boolean &)) &TColStd_SequenceOfBoolean::Append, "Append one item", py::arg("theItem"));
	cls_TColStd_SequenceOfBoolean.def("Append", (void (TColStd_SequenceOfBoolean::*)(TColStd_SequenceOfBoolean &)) &TColStd_SequenceOfBoolean::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfBoolean.def("Prepend", (void (TColStd_SequenceOfBoolean::*)(const Standard_Boolean &)) &TColStd_SequenceOfBoolean::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColStd_SequenceOfBoolean.def("Prepend", (void (TColStd_SequenceOfBoolean::*)(TColStd_SequenceOfBoolean &)) &TColStd_SequenceOfBoolean::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColStd_SequenceOfBoolean.def("InsertBefore", (void (TColStd_SequenceOfBoolean::*)(const Standard_Integer, const Standard_Boolean &)) &TColStd_SequenceOfBoolean::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfBoolean.def("InsertBefore", (void (TColStd_SequenceOfBoolean::*)(const Standard_Integer, TColStd_SequenceOfBoolean &)) &TColStd_SequenceOfBoolean::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfBoolean.def("InsertAfter", (void (TColStd_SequenceOfBoolean::*)(TColStd_SequenceOfBoolean::Iterator &, const Standard_Boolean &)) &TColStd_SequenceOfBoolean::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColStd_SequenceOfBoolean.def("InsertAfter", (void (TColStd_SequenceOfBoolean::*)(const Standard_Integer, TColStd_SequenceOfBoolean &)) &TColStd_SequenceOfBoolean::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfBoolean.def("InsertAfter", (void (TColStd_SequenceOfBoolean::*)(const Standard_Integer, const Standard_Boolean &)) &TColStd_SequenceOfBoolean::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfBoolean.def("Split", (void (TColStd_SequenceOfBoolean::*)(const Standard_Integer, TColStd_SequenceOfBoolean &)) &TColStd_SequenceOfBoolean::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColStd_SequenceOfBoolean.def("First", (const Standard_Boolean & (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::First, "First item access");
	cls_TColStd_SequenceOfBoolean.def("ChangeFirst", (Standard_Boolean & (TColStd_SequenceOfBoolean::*)()) &TColStd_SequenceOfBoolean::ChangeFirst, "First item access");
	cls_TColStd_SequenceOfBoolean.def("Last", (const Standard_Boolean & (TColStd_SequenceOfBoolean::*)() const ) &TColStd_SequenceOfBoolean::Last, "Last item access");
	cls_TColStd_SequenceOfBoolean.def("ChangeLast", (Standard_Boolean & (TColStd_SequenceOfBoolean::*)()) &TColStd_SequenceOfBoolean::ChangeLast, "Last item access");
	cls_TColStd_SequenceOfBoolean.def("Value", (const Standard_Boolean & (TColStd_SequenceOfBoolean::*)(const Standard_Integer) const ) &TColStd_SequenceOfBoolean::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfBoolean.def("__call__", (const Standard_Boolean & (TColStd_SequenceOfBoolean::*)(const Standard_Integer) const ) &TColStd_SequenceOfBoolean::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfBoolean.def("ChangeValue", (Standard_Boolean & (TColStd_SequenceOfBoolean::*)(const Standard_Integer)) &TColStd_SequenceOfBoolean::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColStd_SequenceOfBoolean.def("__call__", (Standard_Boolean & (TColStd_SequenceOfBoolean::*)(const Standard_Integer)) &TColStd_SequenceOfBoolean::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColStd_SequenceOfBoolean.def("SetValue", (void (TColStd_SequenceOfBoolean::*)(const Standard_Integer, const Standard_Boolean &)) &TColStd_SequenceOfBoolean::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColStd_SequenceOfBoolean.def("__iter__", [](const TColStd_SequenceOfBoolean &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray1OfBoolean.hxx
	py::class_<TColStd_HArray1OfBoolean, opencascade::handle<TColStd_HArray1OfBoolean>, TColStd_Array1OfBoolean, Standard_Transient> cls_TColStd_HArray1OfBoolean(mod, "TColStd_HArray1OfBoolean", "None");
	cls_TColStd_HArray1OfBoolean.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_HArray1OfBoolean.def(py::init<const Standard_Integer, const Standard_Integer, const TColStd_Array1OfBoolean::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColStd_HArray1OfBoolean.def(py::init<const TColStd_Array1OfBoolean &>(), py::arg("theOther"));
	cls_TColStd_HArray1OfBoolean.def("Array1", (const TColStd_Array1OfBoolean & (TColStd_HArray1OfBoolean::*)() const ) &TColStd_HArray1OfBoolean::Array1, "None");
	cls_TColStd_HArray1OfBoolean.def("ChangeArray1", (TColStd_Array1OfBoolean & (TColStd_HArray1OfBoolean::*)()) &TColStd_HArray1OfBoolean::ChangeArray1, "None");
	cls_TColStd_HArray1OfBoolean.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray1OfBoolean::get_type_name, "None");
	cls_TColStd_HArray1OfBoolean.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray1OfBoolean::get_type_descriptor, "None");
	cls_TColStd_HArray1OfBoolean.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray1OfBoolean::*)() const ) &TColStd_HArray1OfBoolean::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<TColStd_MapOfAsciiString, std::unique_ptr<TColStd_MapOfAsciiString, Deleter<TColStd_MapOfAsciiString>>, NCollection_BaseMap> cls_TColStd_MapOfAsciiString(mod, "TColStd_MapOfAsciiString", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_TColStd_MapOfAsciiString.def(py::init<>());
	cls_TColStd_MapOfAsciiString.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_MapOfAsciiString.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_MapOfAsciiString.def(py::init([] (const TColStd_MapOfAsciiString &other) {return new TColStd_MapOfAsciiString(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_MapOfAsciiString.def("cbegin", (TColStd_MapOfAsciiString::const_iterator (TColStd_MapOfAsciiString::*)() const ) &TColStd_MapOfAsciiString::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_MapOfAsciiString.def("cend", (TColStd_MapOfAsciiString::const_iterator (TColStd_MapOfAsciiString::*)() const ) &TColStd_MapOfAsciiString::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_MapOfAsciiString.def("Exchange", (void (TColStd_MapOfAsciiString::*)(TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_MapOfAsciiString.def("Assign", (TColStd_MapOfAsciiString & (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_MapOfAsciiString.def("assign", (TColStd_MapOfAsciiString & (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_TColStd_MapOfAsciiString.def("ReSize", (void (TColStd_MapOfAsciiString::*)(const Standard_Integer)) &TColStd_MapOfAsciiString::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_MapOfAsciiString.def("Add", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TCollection_AsciiString &)) &TColStd_MapOfAsciiString::Add, "Add", py::arg("K"));
	cls_TColStd_MapOfAsciiString.def("Added", (const TCollection_AsciiString & (TColStd_MapOfAsciiString::*)(const TCollection_AsciiString &)) &TColStd_MapOfAsciiString::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_TColStd_MapOfAsciiString.def("Contains", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TCollection_AsciiString &) const ) &TColStd_MapOfAsciiString::Contains, "Contains", py::arg("K"));
	cls_TColStd_MapOfAsciiString.def("Remove", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TCollection_AsciiString &)) &TColStd_MapOfAsciiString::Remove, "Remove", py::arg("K"));
	cls_TColStd_MapOfAsciiString.def("Clear", [](TColStd_MapOfAsciiString &self) -> void { return self.Clear(); });
	cls_TColStd_MapOfAsciiString.def("Clear", (void (TColStd_MapOfAsciiString::*)(const Standard_Boolean)) &TColStd_MapOfAsciiString::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_MapOfAsciiString.def("Clear", (void (TColStd_MapOfAsciiString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_MapOfAsciiString::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_MapOfAsciiString.def("Size", (Standard_Integer (TColStd_MapOfAsciiString::*)() const ) &TColStd_MapOfAsciiString::Size, "Size");
	cls_TColStd_MapOfAsciiString.def("IsEqual", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &) const ) &TColStd_MapOfAsciiString::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_TColStd_MapOfAsciiString.def("Contains", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &) const ) &TColStd_MapOfAsciiString::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_TColStd_MapOfAsciiString.def("Union", (void (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &, const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfAsciiString.def("Unite", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfAsciiString.def("HasIntersection", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &) const ) &TColStd_MapOfAsciiString::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_TColStd_MapOfAsciiString.def("Intersection", (void (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &, const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfAsciiString.def("Intersect", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfAsciiString.def("Subtraction", (void (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &, const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfAsciiString.def("Subtract", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfAsciiString.def("Difference", (void (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &, const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfAsciiString.def("Differ", (Standard_Boolean (TColStd_MapOfAsciiString::*)(const TColStd_MapOfAsciiString &)) &TColStd_MapOfAsciiString::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapOfAsciiString.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray2OfBoolean.hxx
	py::class_<TColStd_HArray2OfBoolean, opencascade::handle<TColStd_HArray2OfBoolean>, TColStd_Array2OfBoolean, Standard_Transient> cls_TColStd_HArray2OfBoolean(mod, "TColStd_HArray2OfBoolean", "None");
	cls_TColStd_HArray2OfBoolean.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColStd_HArray2OfBoolean.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array2OfBoolean::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColStd_HArray2OfBoolean.def(py::init<const TColStd_Array2OfBoolean &>(), py::arg("theOther"));
	cls_TColStd_HArray2OfBoolean.def("Array2", (const TColStd_Array2OfBoolean & (TColStd_HArray2OfBoolean::*)() const ) &TColStd_HArray2OfBoolean::Array2, "None");
	cls_TColStd_HArray2OfBoolean.def("ChangeArray2", (TColStd_Array2OfBoolean & (TColStd_HArray2OfBoolean::*)()) &TColStd_HArray2OfBoolean::ChangeArray2, "None");
	cls_TColStd_HArray2OfBoolean.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray2OfBoolean::get_type_name, "None");
	cls_TColStd_HArray2OfBoolean.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray2OfBoolean::get_type_descriptor, "None");
	cls_TColStd_HArray2OfBoolean.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray2OfBoolean::*)() const ) &TColStd_HArray2OfBoolean::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<TColStd_IndexedDataMapOfTransientTransient, std::unique_ptr<TColStd_IndexedDataMapOfTransientTransient, Deleter<TColStd_IndexedDataMapOfTransientTransient>>, NCollection_BaseMap> cls_TColStd_IndexedDataMapOfTransientTransient(mod, "TColStd_IndexedDataMapOfTransientTransient", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_TColStd_IndexedDataMapOfTransientTransient.def(py::init<>());
	cls_TColStd_IndexedDataMapOfTransientTransient.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def(py::init([] (const TColStd_IndexedDataMapOfTransientTransient &other) {return new TColStd_IndexedDataMapOfTransientTransient(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("begin", (TColStd_IndexedDataMapOfTransientTransient::iterator (TColStd_IndexedDataMapOfTransientTransient::*)() const ) &TColStd_IndexedDataMapOfTransientTransient::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TColStd_IndexedDataMapOfTransientTransient.def("end", (TColStd_IndexedDataMapOfTransientTransient::iterator (TColStd_IndexedDataMapOfTransientTransient::*)() const ) &TColStd_IndexedDataMapOfTransientTransient::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TColStd_IndexedDataMapOfTransientTransient.def("cbegin", (TColStd_IndexedDataMapOfTransientTransient::const_iterator (TColStd_IndexedDataMapOfTransientTransient::*)() const ) &TColStd_IndexedDataMapOfTransientTransient::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_IndexedDataMapOfTransientTransient.def("cend", (TColStd_IndexedDataMapOfTransientTransient::const_iterator (TColStd_IndexedDataMapOfTransientTransient::*)() const ) &TColStd_IndexedDataMapOfTransientTransient::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Exchange", (void (TColStd_IndexedDataMapOfTransientTransient::*)(TColStd_IndexedDataMapOfTransientTransient &)) &TColStd_IndexedDataMapOfTransientTransient::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Assign", (TColStd_IndexedDataMapOfTransientTransient & (TColStd_IndexedDataMapOfTransientTransient::*)(const TColStd_IndexedDataMapOfTransientTransient &)) &TColStd_IndexedDataMapOfTransientTransient::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("assign", (TColStd_IndexedDataMapOfTransientTransient & (TColStd_IndexedDataMapOfTransientTransient::*)(const TColStd_IndexedDataMapOfTransientTransient &)) &TColStd_IndexedDataMapOfTransientTransient::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("ReSize", (void (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Integer)) &TColStd_IndexedDataMapOfTransientTransient::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Add", (Standard_Integer (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &TColStd_IndexedDataMapOfTransientTransient::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Contains", (Standard_Boolean (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_IndexedDataMapOfTransientTransient::Contains, "Contains", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Substitute", (void (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &TColStd_IndexedDataMapOfTransientTransient::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Swap", (void (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Integer, const Standard_Integer)) &TColStd_IndexedDataMapOfTransientTransient::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("RemoveLast", (void (TColStd_IndexedDataMapOfTransientTransient::*)()) &TColStd_IndexedDataMapOfTransientTransient::RemoveLast, "RemoveLast");
	cls_TColStd_IndexedDataMapOfTransientTransient.def("RemoveFromIndex", (void (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Integer)) &TColStd_IndexedDataMapOfTransientTransient::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("RemoveKey", (void (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_IndexedDataMapOfTransientTransient::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("FindKey", (const opencascade::handle<Standard_Transient> & (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Integer) const ) &TColStd_IndexedDataMapOfTransientTransient::FindKey, "FindKey", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("FindFromIndex", (const opencascade::handle<Standard_Transient> & (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Integer) const ) &TColStd_IndexedDataMapOfTransientTransient::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("__call__", (const opencascade::handle<Standard_Transient> & (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Integer) const ) &TColStd_IndexedDataMapOfTransientTransient::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("ChangeFromIndex", (opencascade::handle<Standard_Transient> & (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Integer)) &TColStd_IndexedDataMapOfTransientTransient::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("__call__", (opencascade::handle<Standard_Transient> & (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Integer)) &TColStd_IndexedDataMapOfTransientTransient::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("FindIndex", (Standard_Integer (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_IndexedDataMapOfTransientTransient::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("FindFromKey", (const opencascade::handle<Standard_Transient> & (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_IndexedDataMapOfTransientTransient::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("ChangeFromKey", (opencascade::handle<Standard_Transient> & (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_IndexedDataMapOfTransientTransient::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_TColStd_IndexedDataMapOfTransientTransient.def("Seek", (const opencascade::handle<Standard_Transient> * (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_IndexedDataMapOfTransientTransient::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_TColStd_IndexedDataMapOfTransientTransient.def("ChangeSeek", (opencascade::handle<Standard_Transient> * (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_IndexedDataMapOfTransientTransient::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("FindFromKey", (Standard_Boolean (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const ) &TColStd_IndexedDataMapOfTransientTransient::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Clear", [](TColStd_IndexedDataMapOfTransientTransient &self) -> void { return self.Clear(); });
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Clear", (void (TColStd_IndexedDataMapOfTransientTransient::*)(const Standard_Boolean)) &TColStd_IndexedDataMapOfTransientTransient::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Clear", (void (TColStd_IndexedDataMapOfTransientTransient::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_IndexedDataMapOfTransientTransient::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_IndexedDataMapOfTransientTransient.def("Size", (Standard_Integer (TColStd_IndexedDataMapOfTransientTransient::*)() const ) &TColStd_IndexedDataMapOfTransientTransient::Size, "Size");
	cls_TColStd_IndexedDataMapOfTransientTransient.def("__iter__", [](const TColStd_IndexedDataMapOfTransientTransient &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TColStd_DataMapOfStringInteger, std::unique_ptr<TColStd_DataMapOfStringInteger, Deleter<TColStd_DataMapOfStringInteger>>, NCollection_BaseMap> cls_TColStd_DataMapOfStringInteger(mod, "TColStd_DataMapOfStringInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_DataMapOfStringInteger.def(py::init<>());
	cls_TColStd_DataMapOfStringInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_DataMapOfStringInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_DataMapOfStringInteger.def(py::init([] (const TColStd_DataMapOfStringInteger &other) {return new TColStd_DataMapOfStringInteger(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_DataMapOfStringInteger.def("begin", (TColStd_DataMapOfStringInteger::iterator (TColStd_DataMapOfStringInteger::*)() const ) &TColStd_DataMapOfStringInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfStringInteger.def("end", (TColStd_DataMapOfStringInteger::iterator (TColStd_DataMapOfStringInteger::*)() const ) &TColStd_DataMapOfStringInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfStringInteger.def("cbegin", (TColStd_DataMapOfStringInteger::const_iterator (TColStd_DataMapOfStringInteger::*)() const ) &TColStd_DataMapOfStringInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfStringInteger.def("cend", (TColStd_DataMapOfStringInteger::const_iterator (TColStd_DataMapOfStringInteger::*)() const ) &TColStd_DataMapOfStringInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfStringInteger.def("Exchange", (void (TColStd_DataMapOfStringInteger::*)(TColStd_DataMapOfStringInteger &)) &TColStd_DataMapOfStringInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_DataMapOfStringInteger.def("Assign", (TColStd_DataMapOfStringInteger & (TColStd_DataMapOfStringInteger::*)(const TColStd_DataMapOfStringInteger &)) &TColStd_DataMapOfStringInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_DataMapOfStringInteger.def("assign", (TColStd_DataMapOfStringInteger & (TColStd_DataMapOfStringInteger::*)(const TColStd_DataMapOfStringInteger &)) &TColStd_DataMapOfStringInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_DataMapOfStringInteger.def("ReSize", (void (TColStd_DataMapOfStringInteger::*)(const Standard_Integer)) &TColStd_DataMapOfStringInteger::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_DataMapOfStringInteger.def("Bind", (Standard_Boolean (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &, const Standard_Integer &)) &TColStd_DataMapOfStringInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TColStd_DataMapOfStringInteger.def("Bound", (Standard_Integer * (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &, const Standard_Integer &)) &TColStd_DataMapOfStringInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TColStd_DataMapOfStringInteger.def("IsBound", (Standard_Boolean (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &) const ) &TColStd_DataMapOfStringInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_TColStd_DataMapOfStringInteger.def("UnBind", (Standard_Boolean (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &)) &TColStd_DataMapOfStringInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfStringInteger.def("Seek", (const Standard_Integer * (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &) const ) &TColStd_DataMapOfStringInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfStringInteger.def("Find", (const Standard_Integer & (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &) const ) &TColStd_DataMapOfStringInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfStringInteger.def("Find", (Standard_Boolean (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &, Standard_Integer &) const ) &TColStd_DataMapOfStringInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TColStd_DataMapOfStringInteger.def("__call__", (const Standard_Integer & (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &) const ) &TColStd_DataMapOfStringInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfStringInteger.def("ChangeSeek", (Standard_Integer * (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &)) &TColStd_DataMapOfStringInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TColStd_DataMapOfStringInteger.def("ChangeFind", (Standard_Integer & (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &)) &TColStd_DataMapOfStringInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TColStd_DataMapOfStringInteger.def("__call__", (Standard_Integer & (TColStd_DataMapOfStringInteger::*)(const TCollection_ExtendedString &)) &TColStd_DataMapOfStringInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TColStd_DataMapOfStringInteger.def("Clear", [](TColStd_DataMapOfStringInteger &self) -> void { return self.Clear(); });
	cls_TColStd_DataMapOfStringInteger.def("Clear", (void (TColStd_DataMapOfStringInteger::*)(const Standard_Boolean)) &TColStd_DataMapOfStringInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_DataMapOfStringInteger.def("Clear", (void (TColStd_DataMapOfStringInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_DataMapOfStringInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_DataMapOfStringInteger.def("Size", (Standard_Integer (TColStd_DataMapOfStringInteger::*)() const ) &TColStd_DataMapOfStringInteger::Size, "Size");
	cls_TColStd_DataMapOfStringInteger.def("__iter__", [](const TColStd_DataMapOfStringInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfStringInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TColStd_ListOfReal, std::unique_ptr<TColStd_ListOfReal, Deleter<TColStd_ListOfReal>>, NCollection_BaseList> cls_TColStd_ListOfReal(mod, "TColStd_ListOfReal", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TColStd_ListOfReal.def(py::init<>());
	cls_TColStd_ListOfReal.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_ListOfReal.def(py::init([] (const TColStd_ListOfReal &other) {return new TColStd_ListOfReal(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_ListOfReal.def("begin", (TColStd_ListOfReal::iterator (TColStd_ListOfReal::*)() const ) &TColStd_ListOfReal::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TColStd_ListOfReal.def("end", (TColStd_ListOfReal::iterator (TColStd_ListOfReal::*)() const ) &TColStd_ListOfReal::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TColStd_ListOfReal.def("cbegin", (TColStd_ListOfReal::const_iterator (TColStd_ListOfReal::*)() const ) &TColStd_ListOfReal::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TColStd_ListOfReal.def("cend", (TColStd_ListOfReal::const_iterator (TColStd_ListOfReal::*)() const ) &TColStd_ListOfReal::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TColStd_ListOfReal.def("Size", (Standard_Integer (TColStd_ListOfReal::*)() const ) &TColStd_ListOfReal::Size, "Size - Number of items");
	cls_TColStd_ListOfReal.def("Assign", (TColStd_ListOfReal & (TColStd_ListOfReal::*)(const TColStd_ListOfReal &)) &TColStd_ListOfReal::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_ListOfReal.def("assign", (TColStd_ListOfReal & (TColStd_ListOfReal::*)(const TColStd_ListOfReal &)) &TColStd_ListOfReal::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_ListOfReal.def("Clear", [](TColStd_ListOfReal &self) -> void { return self.Clear(); });
	cls_TColStd_ListOfReal.def("Clear", (void (TColStd_ListOfReal::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_ListOfReal::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TColStd_ListOfReal.def("First", (const Standard_Real & (TColStd_ListOfReal::*)() const ) &TColStd_ListOfReal::First, "First item");
	cls_TColStd_ListOfReal.def("First", (Standard_Real & (TColStd_ListOfReal::*)()) &TColStd_ListOfReal::First, "First item (non-const)");
	cls_TColStd_ListOfReal.def("Last", (const Standard_Real & (TColStd_ListOfReal::*)() const ) &TColStd_ListOfReal::Last, "Last item");
	cls_TColStd_ListOfReal.def("Last", (Standard_Real & (TColStd_ListOfReal::*)()) &TColStd_ListOfReal::Last, "Last item (non-const)");
	cls_TColStd_ListOfReal.def("Append", (Standard_Real & (TColStd_ListOfReal::*)(const Standard_Real &)) &TColStd_ListOfReal::Append, "Append one item at the end", py::arg("theItem"));
	cls_TColStd_ListOfReal.def("Append", (void (TColStd_ListOfReal::*)(const Standard_Real &, TColStd_ListOfReal::Iterator &)) &TColStd_ListOfReal::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfReal.def("Append", (void (TColStd_ListOfReal::*)(TColStd_ListOfReal &)) &TColStd_ListOfReal::Append, "Append another list at the end", py::arg("theOther"));
	cls_TColStd_ListOfReal.def("Prepend", (Standard_Real & (TColStd_ListOfReal::*)(const Standard_Real &)) &TColStd_ListOfReal::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TColStd_ListOfReal.def("Prepend", (void (TColStd_ListOfReal::*)(TColStd_ListOfReal &)) &TColStd_ListOfReal::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TColStd_ListOfReal.def("RemoveFirst", (void (TColStd_ListOfReal::*)()) &TColStd_ListOfReal::RemoveFirst, "RemoveFirst item");
	cls_TColStd_ListOfReal.def("Remove", (void (TColStd_ListOfReal::*)(TColStd_ListOfReal::Iterator &)) &TColStd_ListOfReal::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TColStd_ListOfReal.def("InsertBefore", (Standard_Real & (TColStd_ListOfReal::*)(const Standard_Real &, TColStd_ListOfReal::Iterator &)) &TColStd_ListOfReal::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfReal.def("InsertBefore", (void (TColStd_ListOfReal::*)(TColStd_ListOfReal &, TColStd_ListOfReal::Iterator &)) &TColStd_ListOfReal::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TColStd_ListOfReal.def("InsertAfter", (Standard_Real & (TColStd_ListOfReal::*)(const Standard_Real &, TColStd_ListOfReal::Iterator &)) &TColStd_ListOfReal::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfReal.def("InsertAfter", (void (TColStd_ListOfReal::*)(TColStd_ListOfReal &, TColStd_ListOfReal::Iterator &)) &TColStd_ListOfReal::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TColStd_ListOfReal.def("Reverse", (void (TColStd_ListOfReal::*)()) &TColStd_ListOfReal::Reverse, "Reverse the list");
	cls_TColStd_ListOfReal.def("__iter__", [](const TColStd_ListOfReal &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TColStd_ListIteratorOfListOfReal, std::unique_ptr<TColStd_ListIteratorOfListOfReal, Deleter<TColStd_ListIteratorOfListOfReal>>> cls_TColStd_ListIteratorOfListOfReal(mod, "TColStd_ListIteratorOfListOfReal", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TColStd_ListIteratorOfListOfReal.def(py::init<>());
	cls_TColStd_ListIteratorOfListOfReal.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TColStd_ListIteratorOfListOfReal.def("More", (Standard_Boolean (TColStd_ListIteratorOfListOfReal::*)() const ) &TColStd_ListIteratorOfListOfReal::More, "Check end");
	cls_TColStd_ListIteratorOfListOfReal.def("Next", (void (TColStd_ListIteratorOfListOfReal::*)()) &TColStd_ListIteratorOfListOfReal::Next, "Make step");
	cls_TColStd_ListIteratorOfListOfReal.def("Value", (const double & (TColStd_ListIteratorOfListOfReal::*)() const ) &TColStd_ListIteratorOfListOfReal::Value, "Constant Value access");
	cls_TColStd_ListIteratorOfListOfReal.def("Value", (double & (TColStd_ListIteratorOfListOfReal::*)()) &TColStd_ListIteratorOfListOfReal::Value, "Non-const Value access");
	cls_TColStd_ListIteratorOfListOfReal.def("ChangeValue", (double & (TColStd_ListIteratorOfListOfReal::*)() const ) &TColStd_ListIteratorOfListOfReal::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TColStd_ListOfAsciiString, std::unique_ptr<TColStd_ListOfAsciiString, Deleter<TColStd_ListOfAsciiString>>, NCollection_BaseList> cls_TColStd_ListOfAsciiString(mod, "TColStd_ListOfAsciiString", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TColStd_ListOfAsciiString.def(py::init<>());
	cls_TColStd_ListOfAsciiString.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColStd_ListOfAsciiString.def(py::init([] (const TColStd_ListOfAsciiString &other) {return new TColStd_ListOfAsciiString(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_ListOfAsciiString.def("begin", (TColStd_ListOfAsciiString::iterator (TColStd_ListOfAsciiString::*)() const ) &TColStd_ListOfAsciiString::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TColStd_ListOfAsciiString.def("end", (TColStd_ListOfAsciiString::iterator (TColStd_ListOfAsciiString::*)() const ) &TColStd_ListOfAsciiString::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TColStd_ListOfAsciiString.def("cbegin", (TColStd_ListOfAsciiString::const_iterator (TColStd_ListOfAsciiString::*)() const ) &TColStd_ListOfAsciiString::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TColStd_ListOfAsciiString.def("cend", (TColStd_ListOfAsciiString::const_iterator (TColStd_ListOfAsciiString::*)() const ) &TColStd_ListOfAsciiString::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TColStd_ListOfAsciiString.def("Size", (Standard_Integer (TColStd_ListOfAsciiString::*)() const ) &TColStd_ListOfAsciiString::Size, "Size - Number of items");
	cls_TColStd_ListOfAsciiString.def("Assign", (TColStd_ListOfAsciiString & (TColStd_ListOfAsciiString::*)(const TColStd_ListOfAsciiString &)) &TColStd_ListOfAsciiString::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_ListOfAsciiString.def("assign", (TColStd_ListOfAsciiString & (TColStd_ListOfAsciiString::*)(const TColStd_ListOfAsciiString &)) &TColStd_ListOfAsciiString::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColStd_ListOfAsciiString.def("Clear", [](TColStd_ListOfAsciiString &self) -> void { return self.Clear(); });
	cls_TColStd_ListOfAsciiString.def("Clear", (void (TColStd_ListOfAsciiString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_ListOfAsciiString::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TColStd_ListOfAsciiString.def("First", (const TCollection_AsciiString & (TColStd_ListOfAsciiString::*)() const ) &TColStd_ListOfAsciiString::First, "First item");
	cls_TColStd_ListOfAsciiString.def("First", (TCollection_AsciiString & (TColStd_ListOfAsciiString::*)()) &TColStd_ListOfAsciiString::First, "First item (non-const)");
	cls_TColStd_ListOfAsciiString.def("Last", (const TCollection_AsciiString & (TColStd_ListOfAsciiString::*)() const ) &TColStd_ListOfAsciiString::Last, "Last item");
	cls_TColStd_ListOfAsciiString.def("Last", (TCollection_AsciiString & (TColStd_ListOfAsciiString::*)()) &TColStd_ListOfAsciiString::Last, "Last item (non-const)");
	cls_TColStd_ListOfAsciiString.def("Append", (TCollection_AsciiString & (TColStd_ListOfAsciiString::*)(const TCollection_AsciiString &)) &TColStd_ListOfAsciiString::Append, "Append one item at the end", py::arg("theItem"));
	cls_TColStd_ListOfAsciiString.def("Append", (void (TColStd_ListOfAsciiString::*)(const TCollection_AsciiString &, TColStd_ListOfAsciiString::Iterator &)) &TColStd_ListOfAsciiString::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfAsciiString.def("Append", (void (TColStd_ListOfAsciiString::*)(TColStd_ListOfAsciiString &)) &TColStd_ListOfAsciiString::Append, "Append another list at the end", py::arg("theOther"));
	cls_TColStd_ListOfAsciiString.def("Prepend", (TCollection_AsciiString & (TColStd_ListOfAsciiString::*)(const TCollection_AsciiString &)) &TColStd_ListOfAsciiString::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TColStd_ListOfAsciiString.def("Prepend", (void (TColStd_ListOfAsciiString::*)(TColStd_ListOfAsciiString &)) &TColStd_ListOfAsciiString::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TColStd_ListOfAsciiString.def("RemoveFirst", (void (TColStd_ListOfAsciiString::*)()) &TColStd_ListOfAsciiString::RemoveFirst, "RemoveFirst item");
	cls_TColStd_ListOfAsciiString.def("Remove", (void (TColStd_ListOfAsciiString::*)(TColStd_ListOfAsciiString::Iterator &)) &TColStd_ListOfAsciiString::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TColStd_ListOfAsciiString.def("InsertBefore", (TCollection_AsciiString & (TColStd_ListOfAsciiString::*)(const TCollection_AsciiString &, TColStd_ListOfAsciiString::Iterator &)) &TColStd_ListOfAsciiString::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfAsciiString.def("InsertBefore", (void (TColStd_ListOfAsciiString::*)(TColStd_ListOfAsciiString &, TColStd_ListOfAsciiString::Iterator &)) &TColStd_ListOfAsciiString::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TColStd_ListOfAsciiString.def("InsertAfter", (TCollection_AsciiString & (TColStd_ListOfAsciiString::*)(const TCollection_AsciiString &, TColStd_ListOfAsciiString::Iterator &)) &TColStd_ListOfAsciiString::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TColStd_ListOfAsciiString.def("InsertAfter", (void (TColStd_ListOfAsciiString::*)(TColStd_ListOfAsciiString &, TColStd_ListOfAsciiString::Iterator &)) &TColStd_ListOfAsciiString::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TColStd_ListOfAsciiString.def("Reverse", (void (TColStd_ListOfAsciiString::*)()) &TColStd_ListOfAsciiString::Reverse, "Reverse the list");
	cls_TColStd_ListOfAsciiString.def("__iter__", [](const TColStd_ListOfAsciiString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TColStd_ListIteratorOfListOfAsciiString, std::unique_ptr<TColStd_ListIteratorOfListOfAsciiString, Deleter<TColStd_ListIteratorOfListOfAsciiString>>> cls_TColStd_ListIteratorOfListOfAsciiString(mod, "TColStd_ListIteratorOfListOfAsciiString", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TColStd_ListIteratorOfListOfAsciiString.def(py::init<>());
	cls_TColStd_ListIteratorOfListOfAsciiString.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TColStd_ListIteratorOfListOfAsciiString.def("More", (Standard_Boolean (TColStd_ListIteratorOfListOfAsciiString::*)() const ) &TColStd_ListIteratorOfListOfAsciiString::More, "Check end");
	cls_TColStd_ListIteratorOfListOfAsciiString.def("Next", (void (TColStd_ListIteratorOfListOfAsciiString::*)()) &TColStd_ListIteratorOfListOfAsciiString::Next, "Make step");
	cls_TColStd_ListIteratorOfListOfAsciiString.def("Value", (const TCollection_AsciiString & (TColStd_ListIteratorOfListOfAsciiString::*)() const ) &TColStd_ListIteratorOfListOfAsciiString::Value, "Constant Value access");
	cls_TColStd_ListIteratorOfListOfAsciiString.def("Value", (TCollection_AsciiString & (TColStd_ListIteratorOfListOfAsciiString::*)()) &TColStd_ListIteratorOfListOfAsciiString::Value, "Non-const Value access");
	cls_TColStd_ListIteratorOfListOfAsciiString.def("ChangeValue", (TCollection_AsciiString & (TColStd_ListIteratorOfListOfAsciiString::*)() const ) &TColStd_ListIteratorOfListOfAsciiString::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HSequenceOfTransient.hxx
	py::class_<TColStd_HSequenceOfTransient, opencascade::handle<TColStd_HSequenceOfTransient>, TColStd_SequenceOfTransient, Standard_Transient> cls_TColStd_HSequenceOfTransient(mod, "TColStd_HSequenceOfTransient", "None");
	cls_TColStd_HSequenceOfTransient.def(py::init<>());
	cls_TColStd_HSequenceOfTransient.def(py::init<const TColStd_SequenceOfTransient &>(), py::arg("theOther"));
	cls_TColStd_HSequenceOfTransient.def("Sequence", (const TColStd_SequenceOfTransient & (TColStd_HSequenceOfTransient::*)() const ) &TColStd_HSequenceOfTransient::Sequence, "None");
	cls_TColStd_HSequenceOfTransient.def("Append", (void (TColStd_HSequenceOfTransient::*)(const TColStd_SequenceOfTransient::value_type &)) &TColStd_HSequenceOfTransient::Append, "None", py::arg("theItem"));
	cls_TColStd_HSequenceOfTransient.def("Append", (void (TColStd_HSequenceOfTransient::*)(TColStd_SequenceOfTransient &)) &TColStd_HSequenceOfTransient::Append, "None", py::arg("theSequence"));
	cls_TColStd_HSequenceOfTransient.def("ChangeSequence", (TColStd_SequenceOfTransient & (TColStd_HSequenceOfTransient::*)()) &TColStd_HSequenceOfTransient::ChangeSequence, "None");
	cls_TColStd_HSequenceOfTransient.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfTransient::get_type_name, "None");
	cls_TColStd_HSequenceOfTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfTransient::get_type_descriptor, "None");
	cls_TColStd_HSequenceOfTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfTransient::*)() const ) &TColStd_HSequenceOfTransient::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray2OfTransient.hxx
	py::class_<TColStd_HArray2OfTransient, opencascade::handle<TColStd_HArray2OfTransient>, TColStd_Array2OfTransient, Standard_Transient> cls_TColStd_HArray2OfTransient(mod, "TColStd_HArray2OfTransient", "None");
	cls_TColStd_HArray2OfTransient.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColStd_HArray2OfTransient.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array2OfTransient::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColStd_HArray2OfTransient.def(py::init<const TColStd_Array2OfTransient &>(), py::arg("theOther"));
	cls_TColStd_HArray2OfTransient.def("Array2", (const TColStd_Array2OfTransient & (TColStd_HArray2OfTransient::*)() const ) &TColStd_HArray2OfTransient::Array2, "None");
	cls_TColStd_HArray2OfTransient.def("ChangeArray2", (TColStd_Array2OfTransient & (TColStd_HArray2OfTransient::*)()) &TColStd_HArray2OfTransient::ChangeArray2, "None");
	cls_TColStd_HArray2OfTransient.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray2OfTransient::get_type_name, "None");
	cls_TColStd_HArray2OfTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray2OfTransient::get_type_descriptor, "None");
	cls_TColStd_HArray2OfTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray2OfTransient::*)() const ) &TColStd_HArray2OfTransient::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TColStd_DataMapOfIntegerReal, std::unique_ptr<TColStd_DataMapOfIntegerReal, Deleter<TColStd_DataMapOfIntegerReal>>, NCollection_BaseMap> cls_TColStd_DataMapOfIntegerReal(mod, "TColStd_DataMapOfIntegerReal", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_DataMapOfIntegerReal.def(py::init<>());
	cls_TColStd_DataMapOfIntegerReal.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_DataMapOfIntegerReal.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_DataMapOfIntegerReal.def(py::init([] (const TColStd_DataMapOfIntegerReal &other) {return new TColStd_DataMapOfIntegerReal(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_DataMapOfIntegerReal.def("begin", (TColStd_DataMapOfIntegerReal::iterator (TColStd_DataMapOfIntegerReal::*)() const ) &TColStd_DataMapOfIntegerReal::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfIntegerReal.def("end", (TColStd_DataMapOfIntegerReal::iterator (TColStd_DataMapOfIntegerReal::*)() const ) &TColStd_DataMapOfIntegerReal::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfIntegerReal.def("cbegin", (TColStd_DataMapOfIntegerReal::const_iterator (TColStd_DataMapOfIntegerReal::*)() const ) &TColStd_DataMapOfIntegerReal::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfIntegerReal.def("cend", (TColStd_DataMapOfIntegerReal::const_iterator (TColStd_DataMapOfIntegerReal::*)() const ) &TColStd_DataMapOfIntegerReal::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfIntegerReal.def("Exchange", (void (TColStd_DataMapOfIntegerReal::*)(TColStd_DataMapOfIntegerReal &)) &TColStd_DataMapOfIntegerReal::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerReal.def("Assign", (TColStd_DataMapOfIntegerReal & (TColStd_DataMapOfIntegerReal::*)(const TColStd_DataMapOfIntegerReal &)) &TColStd_DataMapOfIntegerReal::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerReal.def("assign", (TColStd_DataMapOfIntegerReal & (TColStd_DataMapOfIntegerReal::*)(const TColStd_DataMapOfIntegerReal &)) &TColStd_DataMapOfIntegerReal::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_DataMapOfIntegerReal.def("ReSize", (void (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer)) &TColStd_DataMapOfIntegerReal::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_DataMapOfIntegerReal.def("Bind", (Standard_Boolean (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &, const Standard_Real &)) &TColStd_DataMapOfIntegerReal::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TColStd_DataMapOfIntegerReal.def("Bound", (Standard_Real * (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &, const Standard_Real &)) &TColStd_DataMapOfIntegerReal::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TColStd_DataMapOfIntegerReal.def("IsBound", (Standard_Boolean (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerReal::IsBound, "IsBound", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerReal.def("UnBind", (Standard_Boolean (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerReal::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerReal.def("Seek", (const Standard_Real * (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerReal::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerReal.def("Find", (const Standard_Real & (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerReal::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerReal.def("Find", (Standard_Boolean (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &, Standard_Real &) const ) &TColStd_DataMapOfIntegerReal::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TColStd_DataMapOfIntegerReal.def("__call__", (const Standard_Real & (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &) const ) &TColStd_DataMapOfIntegerReal::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfIntegerReal.def("ChangeSeek", (Standard_Real * (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerReal::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerReal.def("ChangeFind", (Standard_Real & (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerReal::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerReal.def("__call__", (Standard_Real & (TColStd_DataMapOfIntegerReal::*)(const Standard_Integer &)) &TColStd_DataMapOfIntegerReal::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TColStd_DataMapOfIntegerReal.def("Clear", [](TColStd_DataMapOfIntegerReal &self) -> void { return self.Clear(); });
	cls_TColStd_DataMapOfIntegerReal.def("Clear", (void (TColStd_DataMapOfIntegerReal::*)(const Standard_Boolean)) &TColStd_DataMapOfIntegerReal::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_DataMapOfIntegerReal.def("Clear", (void (TColStd_DataMapOfIntegerReal::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_DataMapOfIntegerReal::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_DataMapOfIntegerReal.def("Size", (Standard_Integer (TColStd_DataMapOfIntegerReal::*)() const ) &TColStd_DataMapOfIntegerReal::Size, "Size");
	cls_TColStd_DataMapOfIntegerReal.def("__iter__", [](const TColStd_DataMapOfIntegerReal &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfIntegerReal.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HSequenceOfHExtendedString.hxx
	py::class_<TColStd_HSequenceOfHExtendedString, opencascade::handle<TColStd_HSequenceOfHExtendedString>, TColStd_SequenceOfHExtendedString, Standard_Transient> cls_TColStd_HSequenceOfHExtendedString(mod, "TColStd_HSequenceOfHExtendedString", "None");
	cls_TColStd_HSequenceOfHExtendedString.def(py::init<>());
	cls_TColStd_HSequenceOfHExtendedString.def(py::init<const TColStd_SequenceOfHExtendedString &>(), py::arg("theOther"));
	cls_TColStd_HSequenceOfHExtendedString.def("Sequence", (const TColStd_SequenceOfHExtendedString & (TColStd_HSequenceOfHExtendedString::*)() const ) &TColStd_HSequenceOfHExtendedString::Sequence, "None");
	cls_TColStd_HSequenceOfHExtendedString.def("Append", (void (TColStd_HSequenceOfHExtendedString::*)(const TColStd_SequenceOfHExtendedString::value_type &)) &TColStd_HSequenceOfHExtendedString::Append, "None", py::arg("theItem"));
	cls_TColStd_HSequenceOfHExtendedString.def("Append", (void (TColStd_HSequenceOfHExtendedString::*)(TColStd_SequenceOfHExtendedString &)) &TColStd_HSequenceOfHExtendedString::Append, "None", py::arg("theSequence"));
	cls_TColStd_HSequenceOfHExtendedString.def("ChangeSequence", (TColStd_SequenceOfHExtendedString & (TColStd_HSequenceOfHExtendedString::*)()) &TColStd_HSequenceOfHExtendedString::ChangeSequence, "None");
	cls_TColStd_HSequenceOfHExtendedString.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfHExtendedString::get_type_name, "None");
	cls_TColStd_HSequenceOfHExtendedString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfHExtendedString::get_type_descriptor, "None");
	cls_TColStd_HSequenceOfHExtendedString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfHExtendedString::*)() const ) &TColStd_HSequenceOfHExtendedString::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray1OfExtendedString.hxx
	py::class_<TColStd_HArray1OfExtendedString, opencascade::handle<TColStd_HArray1OfExtendedString>, TColStd_Array1OfExtendedString, Standard_Transient> cls_TColStd_HArray1OfExtendedString(mod, "TColStd_HArray1OfExtendedString", "None");
	cls_TColStd_HArray1OfExtendedString.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_HArray1OfExtendedString.def(py::init<const Standard_Integer, const Standard_Integer, const TColStd_Array1OfExtendedString::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColStd_HArray1OfExtendedString.def(py::init<const TColStd_Array1OfExtendedString &>(), py::arg("theOther"));
	cls_TColStd_HArray1OfExtendedString.def("Array1", (const TColStd_Array1OfExtendedString & (TColStd_HArray1OfExtendedString::*)() const ) &TColStd_HArray1OfExtendedString::Array1, "None");
	cls_TColStd_HArray1OfExtendedString.def("ChangeArray1", (TColStd_Array1OfExtendedString & (TColStd_HArray1OfExtendedString::*)()) &TColStd_HArray1OfExtendedString::ChangeArray1, "None");
	cls_TColStd_HArray1OfExtendedString.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray1OfExtendedString::get_type_name, "None");
	cls_TColStd_HArray1OfExtendedString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray1OfExtendedString::get_type_descriptor, "None");
	cls_TColStd_HArray1OfExtendedString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray1OfExtendedString::*)() const ) &TColStd_HArray1OfExtendedString::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray1OfCharacter.hxx
	py::class_<TColStd_HArray1OfCharacter, opencascade::handle<TColStd_HArray1OfCharacter>, TColStd_Array1OfCharacter, Standard_Transient> cls_TColStd_HArray1OfCharacter(mod, "TColStd_HArray1OfCharacter", "None");
	cls_TColStd_HArray1OfCharacter.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColStd_HArray1OfCharacter.def(py::init<const Standard_Integer, const Standard_Integer, const TColStd_Array1OfCharacter::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColStd_HArray1OfCharacter.def(py::init<const TColStd_Array1OfCharacter &>(), py::arg("theOther"));
	cls_TColStd_HArray1OfCharacter.def("Array1", (const TColStd_Array1OfCharacter & (TColStd_HArray1OfCharacter::*)() const ) &TColStd_HArray1OfCharacter::Array1, "None");
	cls_TColStd_HArray1OfCharacter.def("ChangeArray1", (TColStd_Array1OfCharacter & (TColStd_HArray1OfCharacter::*)()) &TColStd_HArray1OfCharacter::ChangeArray1, "None");
	cls_TColStd_HArray1OfCharacter.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray1OfCharacter::get_type_name, "None");
	cls_TColStd_HArray1OfCharacter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray1OfCharacter::get_type_descriptor, "None");
	cls_TColStd_HArray1OfCharacter.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray1OfCharacter::*)() const ) &TColStd_HArray1OfCharacter::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_HArray2OfCharacter.hxx
	py::class_<TColStd_HArray2OfCharacter, opencascade::handle<TColStd_HArray2OfCharacter>, TColStd_Array2OfCharacter, Standard_Transient> cls_TColStd_HArray2OfCharacter(mod, "TColStd_HArray2OfCharacter", "None");
	cls_TColStd_HArray2OfCharacter.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColStd_HArray2OfCharacter.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array2OfCharacter::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColStd_HArray2OfCharacter.def(py::init<const TColStd_Array2OfCharacter &>(), py::arg("theOther"));
	cls_TColStd_HArray2OfCharacter.def("Array2", (const TColStd_Array2OfCharacter & (TColStd_HArray2OfCharacter::*)() const ) &TColStd_HArray2OfCharacter::Array2, "None");
	cls_TColStd_HArray2OfCharacter.def("ChangeArray2", (TColStd_Array2OfCharacter & (TColStd_HArray2OfCharacter::*)()) &TColStd_HArray2OfCharacter::ChangeArray2, "None");
	cls_TColStd_HArray2OfCharacter.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray2OfCharacter::get_type_name, "None");
	cls_TColStd_HArray2OfCharacter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray2OfCharacter::get_type_descriptor, "None");
	cls_TColStd_HArray2OfCharacter.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray2OfCharacter::*)() const ) &TColStd_HArray2OfCharacter::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TColStd_DataMapOfTransientTransient, std::unique_ptr<TColStd_DataMapOfTransientTransient, Deleter<TColStd_DataMapOfTransientTransient>>, NCollection_BaseMap> cls_TColStd_DataMapOfTransientTransient(mod, "TColStd_DataMapOfTransientTransient", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_DataMapOfTransientTransient.def(py::init<>());
	cls_TColStd_DataMapOfTransientTransient.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_DataMapOfTransientTransient.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_DataMapOfTransientTransient.def(py::init([] (const TColStd_DataMapOfTransientTransient &other) {return new TColStd_DataMapOfTransientTransient(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_DataMapOfTransientTransient.def("begin", (TColStd_DataMapOfTransientTransient::iterator (TColStd_DataMapOfTransientTransient::*)() const ) &TColStd_DataMapOfTransientTransient::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfTransientTransient.def("end", (TColStd_DataMapOfTransientTransient::iterator (TColStd_DataMapOfTransientTransient::*)() const ) &TColStd_DataMapOfTransientTransient::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfTransientTransient.def("cbegin", (TColStd_DataMapOfTransientTransient::const_iterator (TColStd_DataMapOfTransientTransient::*)() const ) &TColStd_DataMapOfTransientTransient::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_DataMapOfTransientTransient.def("cend", (TColStd_DataMapOfTransientTransient::const_iterator (TColStd_DataMapOfTransientTransient::*)() const ) &TColStd_DataMapOfTransientTransient::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_DataMapOfTransientTransient.def("Exchange", (void (TColStd_DataMapOfTransientTransient::*)(TColStd_DataMapOfTransientTransient &)) &TColStd_DataMapOfTransientTransient::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_DataMapOfTransientTransient.def("Assign", (TColStd_DataMapOfTransientTransient & (TColStd_DataMapOfTransientTransient::*)(const TColStd_DataMapOfTransientTransient &)) &TColStd_DataMapOfTransientTransient::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_DataMapOfTransientTransient.def("assign", (TColStd_DataMapOfTransientTransient & (TColStd_DataMapOfTransientTransient::*)(const TColStd_DataMapOfTransientTransient &)) &TColStd_DataMapOfTransientTransient::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_DataMapOfTransientTransient.def("ReSize", (void (TColStd_DataMapOfTransientTransient::*)(const Standard_Integer)) &TColStd_DataMapOfTransientTransient::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_DataMapOfTransientTransient.def("Bind", (Standard_Boolean (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &TColStd_DataMapOfTransientTransient::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TColStd_DataMapOfTransientTransient.def("Bound", (opencascade::handle<Standard_Transient> * (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &TColStd_DataMapOfTransientTransient::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TColStd_DataMapOfTransientTransient.def("IsBound", (Standard_Boolean (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_DataMapOfTransientTransient::IsBound, "IsBound", py::arg("theKey"));
	cls_TColStd_DataMapOfTransientTransient.def("UnBind", (Standard_Boolean (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_DataMapOfTransientTransient::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfTransientTransient.def("Seek", (const opencascade::handle<Standard_Transient> * (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_DataMapOfTransientTransient::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfTransientTransient.def("Find", (const opencascade::handle<Standard_Transient> & (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_DataMapOfTransientTransient::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfTransientTransient.def("Find", (Standard_Boolean (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const ) &TColStd_DataMapOfTransientTransient::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TColStd_DataMapOfTransientTransient.def("__call__", (const opencascade::handle<Standard_Transient> & (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &) const ) &TColStd_DataMapOfTransientTransient::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TColStd_DataMapOfTransientTransient.def("ChangeSeek", (opencascade::handle<Standard_Transient> * (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_DataMapOfTransientTransient::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TColStd_DataMapOfTransientTransient.def("ChangeFind", (opencascade::handle<Standard_Transient> & (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_DataMapOfTransientTransient::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TColStd_DataMapOfTransientTransient.def("__call__", (opencascade::handle<Standard_Transient> & (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<Standard_Transient> &)) &TColStd_DataMapOfTransientTransient::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TColStd_DataMapOfTransientTransient.def("Clear", [](TColStd_DataMapOfTransientTransient &self) -> void { return self.Clear(); });
	cls_TColStd_DataMapOfTransientTransient.def("Clear", (void (TColStd_DataMapOfTransientTransient::*)(const Standard_Boolean)) &TColStd_DataMapOfTransientTransient::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_DataMapOfTransientTransient.def("Clear", (void (TColStd_DataMapOfTransientTransient::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_DataMapOfTransientTransient::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_DataMapOfTransientTransient.def("Size", (Standard_Integer (TColStd_DataMapOfTransientTransient::*)() const ) &TColStd_DataMapOfTransientTransient::Size, "Size");
	cls_TColStd_DataMapOfTransientTransient.def("__iter__", [](const TColStd_DataMapOfTransientTransient &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfTransientTransient.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DefaultHasher.hxx
	py::class_<TColStd_MapRealHasher, std::unique_ptr<TColStd_MapRealHasher, Deleter<TColStd_MapRealHasher>>> cls_TColStd_MapRealHasher(mod, "TColStd_MapRealHasher", "Purpose: The DefaultHasher is a Hasher that is used by default in NCollection maps. To compute the hash code of the key is used the global function HashCode. To compare two keys is used the global function IsEqual.");
	cls_TColStd_MapRealHasher.def(py::init<>());
	cls_TColStd_MapRealHasher.def_static("HashCode_", (Standard_Integer (*)(const Standard_Real &, const Standard_Integer)) &TColStd_MapRealHasher::HashCode, "None", py::arg("theKey"), py::arg("Upper"));
	cls_TColStd_MapRealHasher.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_Real &, const Standard_Real &)) &TColStd_MapRealHasher::IsEqual, "None", py::arg("theKey1"), py::arg("theKey2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedMap.hxx
	py::class_<TColStd_IndexedMapOfReal, std::unique_ptr<TColStd_IndexedMapOfReal, Deleter<TColStd_IndexedMapOfReal>>, NCollection_BaseMap> cls_TColStd_IndexedMapOfReal(mod, "TColStd_IndexedMapOfReal", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1..Extent. See the class Map from NCollection for a discussion about the number of buckets.");
	cls_TColStd_IndexedMapOfReal.def(py::init<>());
	cls_TColStd_IndexedMapOfReal.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_IndexedMapOfReal.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_IndexedMapOfReal.def(py::init([] (const TColStd_IndexedMapOfReal &other) {return new TColStd_IndexedMapOfReal(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_IndexedMapOfReal.def("cbegin", (TColStd_IndexedMapOfReal::const_iterator (TColStd_IndexedMapOfReal::*)() const ) &TColStd_IndexedMapOfReal::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_IndexedMapOfReal.def("cend", (TColStd_IndexedMapOfReal::const_iterator (TColStd_IndexedMapOfReal::*)() const ) &TColStd_IndexedMapOfReal::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_IndexedMapOfReal.def("Exchange", (void (TColStd_IndexedMapOfReal::*)(TColStd_IndexedMapOfReal &)) &TColStd_IndexedMapOfReal::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_IndexedMapOfReal.def("Assign", (TColStd_IndexedMapOfReal & (TColStd_IndexedMapOfReal::*)(const TColStd_IndexedMapOfReal &)) &TColStd_IndexedMapOfReal::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_IndexedMapOfReal.def("assign", (TColStd_IndexedMapOfReal & (TColStd_IndexedMapOfReal::*)(const TColStd_IndexedMapOfReal &)) &TColStd_IndexedMapOfReal::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColStd_IndexedMapOfReal.def("ReSize", (void (TColStd_IndexedMapOfReal::*)(const Standard_Integer)) &TColStd_IndexedMapOfReal::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_IndexedMapOfReal.def("Add", (Standard_Integer (TColStd_IndexedMapOfReal::*)(const Standard_Real &)) &TColStd_IndexedMapOfReal::Add, "Add", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfReal.def("Contains", (Standard_Boolean (TColStd_IndexedMapOfReal::*)(const Standard_Real &) const ) &TColStd_IndexedMapOfReal::Contains, "Contains", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfReal.def("Substitute", (void (TColStd_IndexedMapOfReal::*)(const Standard_Integer, const Standard_Real &)) &TColStd_IndexedMapOfReal::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"));
	cls_TColStd_IndexedMapOfReal.def("Swap", (void (TColStd_IndexedMapOfReal::*)(const Standard_Integer, const Standard_Integer)) &TColStd_IndexedMapOfReal::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_TColStd_IndexedMapOfReal.def("RemoveLast", (void (TColStd_IndexedMapOfReal::*)()) &TColStd_IndexedMapOfReal::RemoveLast, "RemoveLast");
	cls_TColStd_IndexedMapOfReal.def("RemoveFromIndex", (void (TColStd_IndexedMapOfReal::*)(const Standard_Integer)) &TColStd_IndexedMapOfReal::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_TColStd_IndexedMapOfReal.def("RemoveKey", (Standard_Boolean (TColStd_IndexedMapOfReal::*)(const Standard_Real &)) &TColStd_IndexedMapOfReal::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfReal.def("FindKey", (const Standard_Real & (TColStd_IndexedMapOfReal::*)(const Standard_Integer) const ) &TColStd_IndexedMapOfReal::FindKey, "FindKey", py::arg("theKey2"));
	cls_TColStd_IndexedMapOfReal.def("__call__", (const Standard_Real & (TColStd_IndexedMapOfReal::*)(const Standard_Integer) const ) &TColStd_IndexedMapOfReal::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_TColStd_IndexedMapOfReal.def("FindIndex", (Standard_Integer (TColStd_IndexedMapOfReal::*)(const Standard_Real &) const ) &TColStd_IndexedMapOfReal::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_TColStd_IndexedMapOfReal.def("Clear", [](TColStd_IndexedMapOfReal &self) -> void { return self.Clear(); });
	cls_TColStd_IndexedMapOfReal.def("Clear", (void (TColStd_IndexedMapOfReal::*)(const Standard_Boolean)) &TColStd_IndexedMapOfReal::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_IndexedMapOfReal.def("Clear", (void (TColStd_IndexedMapOfReal::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_IndexedMapOfReal::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_IndexedMapOfReal.def("Size", (Standard_Integer (TColStd_IndexedMapOfReal::*)() const ) &TColStd_IndexedMapOfReal::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<TColStd_MapOfReal, std::unique_ptr<TColStd_MapOfReal, Deleter<TColStd_MapOfReal>>, NCollection_BaseMap> cls_TColStd_MapOfReal(mod, "TColStd_MapOfReal", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_TColStd_MapOfReal.def(py::init<>());
	cls_TColStd_MapOfReal.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TColStd_MapOfReal.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TColStd_MapOfReal.def(py::init([] (const TColStd_MapOfReal &other) {return new TColStd_MapOfReal(other);}), "Copy constructor", py::arg("other"));
	cls_TColStd_MapOfReal.def("cbegin", (TColStd_MapOfReal::const_iterator (TColStd_MapOfReal::*)() const ) &TColStd_MapOfReal::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TColStd_MapOfReal.def("cend", (TColStd_MapOfReal::const_iterator (TColStd_MapOfReal::*)() const ) &TColStd_MapOfReal::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TColStd_MapOfReal.def("Exchange", (void (TColStd_MapOfReal::*)(TColStd_MapOfReal &)) &TColStd_MapOfReal::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TColStd_MapOfReal.def("Assign", (TColStd_MapOfReal & (TColStd_MapOfReal::*)(const TColStd_MapOfReal &)) &TColStd_MapOfReal::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColStd_MapOfReal.def("assign", (TColStd_MapOfReal & (TColStd_MapOfReal::*)(const TColStd_MapOfReal &)) &TColStd_MapOfReal::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_TColStd_MapOfReal.def("ReSize", (void (TColStd_MapOfReal::*)(const Standard_Integer)) &TColStd_MapOfReal::ReSize, "ReSize", py::arg("N"));
	cls_TColStd_MapOfReal.def("Add", (Standard_Boolean (TColStd_MapOfReal::*)(const Standard_Real &)) &TColStd_MapOfReal::Add, "Add", py::arg("K"));
	cls_TColStd_MapOfReal.def("Added", (const Standard_Real & (TColStd_MapOfReal::*)(const Standard_Real &)) &TColStd_MapOfReal::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_TColStd_MapOfReal.def("Contains", (Standard_Boolean (TColStd_MapOfReal::*)(const Standard_Real &) const ) &TColStd_MapOfReal::Contains, "Contains", py::arg("K"));
	cls_TColStd_MapOfReal.def("Remove", (Standard_Boolean (TColStd_MapOfReal::*)(const Standard_Real &)) &TColStd_MapOfReal::Remove, "Remove", py::arg("K"));
	cls_TColStd_MapOfReal.def("Clear", [](TColStd_MapOfReal &self) -> void { return self.Clear(); });
	cls_TColStd_MapOfReal.def("Clear", (void (TColStd_MapOfReal::*)(const Standard_Boolean)) &TColStd_MapOfReal::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TColStd_MapOfReal.def("Clear", (void (TColStd_MapOfReal::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_MapOfReal::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TColStd_MapOfReal.def("Size", (Standard_Integer (TColStd_MapOfReal::*)() const ) &TColStd_MapOfReal::Size, "Size");
	cls_TColStd_MapOfReal.def("IsEqual", (Standard_Boolean (TColStd_MapOfReal::*)(const TColStd_MapOfReal &) const ) &TColStd_MapOfReal::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_TColStd_MapOfReal.def("Contains", (Standard_Boolean (TColStd_MapOfReal::*)(const TColStd_MapOfReal &) const ) &TColStd_MapOfReal::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_TColStd_MapOfReal.def("Union", (void (TColStd_MapOfReal::*)(const TColStd_MapOfReal &, const TColStd_MapOfReal &)) &TColStd_MapOfReal::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfReal.def("Unite", (Standard_Boolean (TColStd_MapOfReal::*)(const TColStd_MapOfReal &)) &TColStd_MapOfReal::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfReal.def("HasIntersection", (Standard_Boolean (TColStd_MapOfReal::*)(const TColStd_MapOfReal &) const ) &TColStd_MapOfReal::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_TColStd_MapOfReal.def("Intersection", (void (TColStd_MapOfReal::*)(const TColStd_MapOfReal &, const TColStd_MapOfReal &)) &TColStd_MapOfReal::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfReal.def("Intersect", (Standard_Boolean (TColStd_MapOfReal::*)(const TColStd_MapOfReal &)) &TColStd_MapOfReal::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfReal.def("Subtraction", (void (TColStd_MapOfReal::*)(const TColStd_MapOfReal &, const TColStd_MapOfReal &)) &TColStd_MapOfReal::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfReal.def("Subtract", (Standard_Boolean (TColStd_MapOfReal::*)(const TColStd_MapOfReal &)) &TColStd_MapOfReal::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_TColStd_MapOfReal.def("Difference", (void (TColStd_MapOfReal::*)(const TColStd_MapOfReal &, const TColStd_MapOfReal &)) &TColStd_MapOfReal::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_TColStd_MapOfReal.def("Differ", (Standard_Boolean (TColStd_MapOfReal::*)(const TColStd_MapOfReal &)) &TColStd_MapOfReal::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapOfReal.hxx

}
