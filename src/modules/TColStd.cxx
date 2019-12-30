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
#include <NCollection_Array1.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Std.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <NCollection_Array2.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <NCollection_Sequence.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColStd_Array1OfByte.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <NCollection_List.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <NCollection_DefaultHasher.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>
#include <TColStd_ListOfTransient.hxx>
#include <NCollection_Map.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <TColStd_Array1OfAsciiString.hxx>
#include <TCollection_HAsciiString.hxx>
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
#include <TColStd_MapOfTransient.hxx>
#include <TColStd_DataMapOfAsciiStringInteger.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <TColStd_Array1OfListOfInteger.hxx>
#include <TColStd_HArray1OfListOfInteger.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <TColStd_IndexedMapOfInteger.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <TColStd_Array1OfBoolean.hxx>
#include <TCollection_BasicMap.hxx>
#include <TCollection_BasicMapIterator.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <Standard_NoSuchObject.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_MapIteratorOfPackedMapOfInteger.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TColStd_SequenceOfHExtendedString.hxx>
#include <TColStd_HSequenceOfHExtendedString.hxx>
#include <TColStd_MapOfAsciiString.hxx>
#include <TColStd_Array2OfBoolean.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <TColStd_DataMapOfStringInteger.hxx>
#include <TColStd_ListOfReal.hxx>
#include <TColStd_ListOfAsciiString.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TColStd_Array2OfTransient.hxx>
#include <TColStd_HArray2OfTransient.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
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
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_NCollection_Array2.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_Define_HSequence.hxx>
#include <bind_Define_HArray2.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>
#include <bind_NCollection_DefaultHasher.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_Map.hxx>
#include <bind_NCollection_IndexedMap.hxx>

PYBIND11_MODULE(TColStd, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");

// TYPEDEF: TCOLSTD_ARRAY1OFREAL
bind_NCollection_Array1<double>(mod, "TColStd_Array1OfReal", py::module_local(false));

// CLASS: TCOLSTD_HARRAY1OFREAL
bind_Define_HArray1<TColStd_HArray1OfReal, TColStd_Array1OfReal>(mod, "TColStd_HArray1OfReal");

// TYPEDEF: TCOLSTD_ARRAY1OFINTEGER
bind_NCollection_Array1<int>(mod, "TColStd_Array1OfInteger", py::module_local(false));

// CLASS: TCOLSTD_HARRAY1OFINTEGER
bind_Define_HArray1<TColStd_HArray1OfInteger, TColStd_Array1OfInteger>(mod, "TColStd_HArray1OfInteger");

// TYPEDEF: TCOLSTD_ARRAY2OFREAL
bind_NCollection_Array2<double>(mod, "TColStd_Array2OfReal", py::module_local(false));

// TYPEDEF: TCOLSTD_SEQUENCEOFREAL
bind_NCollection_Sequence<double>(mod, "TColStd_SequenceOfReal", py::module_local(false));

// CLASS: TCOLSTD_HSEQUENCEOFREAL
bind_Define_HSequence<TColStd_HSequenceOfReal, TColStd_SequenceOfReal>(mod, "TColStd_HSequenceOfReal");

// CLASS: TCOLSTD_HARRAY2OFREAL
bind_Define_HArray2<TColStd_HArray2OfReal, TColStd_Array2OfReal>(mod, "TColStd_HArray2OfReal");

// TYPEDEF: TCOLSTD_ARRAY1OFBYTE
bind_NCollection_Array1<unsigned char>(mod, "TColStd_Array1OfByte", py::module_local(false));

// CLASS: TCOLSTD_HARRAY1OFBYTE
bind_Define_HArray1<TColStd_HArray1OfByte, TColStd_Array1OfByte>(mod, "TColStd_HArray1OfByte");

// TYPEDEF: TCOLSTD_LISTOFINTEGER
bind_NCollection_List<int>(mod, "TColStd_ListOfInteger", py::module_local(false));

// TYPEDEF: TCOLSTD_LISTITERATOROFLISTOFINTEGER
bind_NCollection_TListIterator<int>(mod, "TColStd_ListIteratorOfListOfInteger", py::module_local(false));

// TYPEDEF: TCOLSTD_INDEXEDDATAMAPOFSTRINGSTRING
bind_NCollection_IndexedDataMap<TCollection_AsciiString, TCollection_AsciiString, TCollection_AsciiString>(mod, "TColStd_IndexedDataMapOfStringString", py::module_local(false));

// TYPEDEF: TCOLSTD_MAPTRANSIENTHASHER
bind_NCollection_DefaultHasher<opencascade::handle<Standard_Transient> >(mod, "TColStd_MapTransientHasher", py::module_local(false));

// TYPEDEF: TCOLSTD_SEQUENCEOFINTEGER
bind_NCollection_Sequence<int>(mod, "TColStd_SequenceOfInteger", py::module_local(false));

// TYPEDEF: TCOLSTD_MAPINTEGERHASHER
bind_NCollection_DefaultHasher<int>(mod, "TColStd_MapIntegerHasher", py::module_local(false));

// TYPEDEF: TCOLSTD_SEQUENCEOFEXTENDEDSTRING
bind_NCollection_Sequence<TCollection_ExtendedString>(mod, "TColStd_SequenceOfExtendedString", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPOFINTEGERLISTOFINTEGER
bind_NCollection_DataMap<int, NCollection_List<int>, NCollection_DefaultHasher<int> >(mod, "TColStd_DataMapOfIntegerListOfInteger", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPITERATOROFDATAMAPOFINTEGERLISTOFINTEGER

// TYPEDEF: TCOLSTD_LISTOFTRANSIENT
bind_NCollection_List<opencascade::handle<Standard_Transient> >(mod, "TColStd_ListOfTransient", py::module_local(false));

// TYPEDEF: TCOLSTD_LISTITERATOROFLISTOFTRANSIENT
bind_NCollection_TListIterator<opencascade::handle<Standard_Transient> >(mod, "TColStd_ListIteratorOfListOfTransient", py::module_local(false));

// TYPEDEF: TCOLSTD_MAPOFINTEGER
bind_NCollection_Map<int, NCollection_DefaultHasher<int> >(mod, "TColStd_MapOfInteger", py::module_local(false));

// TYPEDEF: TCOLSTD_MAPITERATOROFMAPOFINTEGER

// TYPEDEF: TCOLSTD_ARRAY1OFTRANSIENT
bind_NCollection_Array1<opencascade::handle<Standard_Transient> >(mod, "TColStd_Array1OfTransient", py::module_local(false));

// TYPEDEF: TCOLSTD_ARRAY1OFASCIISTRING
bind_NCollection_Array1<TCollection_AsciiString>(mod, "TColStd_Array1OfAsciiString", py::module_local(false));

// TYPEDEF: TCOLSTD_SEQUENCEOFHASCIISTRING
bind_NCollection_Sequence<opencascade::handle<TCollection_HAsciiString> >(mod, "TColStd_SequenceOfHAsciiString", py::module_local(false));

// CLASS: TCOLSTD_HSEQUENCEOFHASCIISTRING
bind_Define_HSequence<TColStd_HSequenceOfHAsciiString, TColStd_SequenceOfHAsciiString>(mod, "TColStd_HSequenceOfHAsciiString");

// TYPEDEF: TCOLSTD_ARRAY2OFINTEGER
bind_NCollection_Array2<int>(mod, "TColStd_Array2OfInteger", py::module_local(false));

// CLASS: TCOLSTD_HARRAY2OFINTEGER
bind_Define_HArray2<TColStd_HArray2OfInteger, TColStd_Array2OfInteger>(mod, "TColStd_HArray2OfInteger");

// TYPEDEF: TCOLSTD_SEQUENCEOFASCIISTRING
bind_NCollection_Sequence<TCollection_AsciiString>(mod, "TColStd_SequenceOfAsciiString", py::module_local(false));

// TYPEDEF: TCOLSTD_SEQUENCEOFADDRESS
bind_NCollection_Sequence<void *>(mod, "TColStd_SequenceOfAddress", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPOFINTEGERTRANSIENT
bind_NCollection_DataMap<int, opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<int> >(mod, "TColStd_DataMapOfIntegerTransient", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPITERATOROFDATAMAPOFINTEGERTRANSIENT

// CLASS: TCOLSTD_HSEQUENCEOFASCIISTRING
bind_Define_HSequence<TColStd_HSequenceOfAsciiString, TColStd_SequenceOfAsciiString>(mod, "TColStd_HSequenceOfAsciiString");

// TYPEDEF: TCOLSTD_INDEXEDMAPOFTRANSIENT
bind_NCollection_IndexedMap<opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TColStd_IndexedMapOfTransient", py::module_local(false));

// TYPEDEF: TCOLSTD_MAPOFTRANSIENT
bind_NCollection_Map<opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TColStd_MapOfTransient", py::module_local(false));

// TYPEDEF: TCOLSTD_MAPITERATOROFMAPOFTRANSIENT

// TYPEDEF: TCOLSTD_DATAMAPOFASCIISTRINGINTEGER
bind_NCollection_DataMap<TCollection_AsciiString, int, TCollection_AsciiString>(mod, "TColStd_DataMapOfAsciiStringInteger", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPITERATOROFDATAMAPOFASCIISTRINGINTEGER

// TYPEDEF: TCOLSTD_DATAMAPOFINTEGERINTEGER
bind_NCollection_DataMap<int, int, NCollection_DefaultHasher<int> >(mod, "TColStd_DataMapOfIntegerInteger", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPITERATOROFDATAMAPOFINTEGERINTEGER

// TYPEDEF: TCOLSTD_ARRAY1OFLISTOFINTEGER
bind_NCollection_Array1<NCollection_List<int> >(mod, "TColStd_Array1OfListOfInteger", py::module_local(false));

// CLASS: TCOLSTD_HARRAY1OFLISTOFINTEGER
bind_Define_HArray1<TColStd_HArray1OfListOfInteger, TColStd_Array1OfListOfInteger>(mod, "TColStd_HArray1OfListOfInteger");

// TYPEDEF: TCOLSTD_DATAMAPOFINTEGERREAL
bind_NCollection_DataMap<int, double, NCollection_DefaultHasher<int> >(mod, "TColStd_DataMapOfIntegerReal", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPITERATOROFDATAMAPOFINTEGERREAL

// TYPEDEF: TCOLSTD_INDEXEDMAPOFINTEGER
bind_NCollection_IndexedMap<int, NCollection_DefaultHasher<int> >(mod, "TColStd_IndexedMapOfInteger", py::module_local(false));

// TYPEDEF: TCOLSTD_SEQUENCEOFBOOLEAN
bind_NCollection_Sequence<bool>(mod, "TColStd_SequenceOfBoolean", py::module_local(false));

// TYPEDEF: TCOLSTD_ARRAY1OFBOOLEAN
bind_NCollection_Array1<bool>(mod, "TColStd_Array1OfBoolean", py::module_local(false));

// CLASS: TCOLSTD_PACKEDMAPOFINTEGER
py::class_<TColStd_PackedMapOfInteger> cls_TColStd_PackedMapOfInteger(mod, "TColStd_PackedMapOfInteger", "Optimized Map of integer values. Each block of 32 integers is stored in 8 bytes in memory.");

// Constructors
cls_TColStd_PackedMapOfInteger.def(py::init<>());
cls_TColStd_PackedMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TColStd_PackedMapOfInteger.def(py::init<const TColStd_PackedMapOfInteger &>(), py::arg("theOther"));

// Methods
// cls_TColStd_PackedMapOfInteger.def_static("operator new_", (void * (*)(size_t)) &TColStd_PackedMapOfInteger::operator new, "None", py::arg("theSize"));
// cls_TColStd_PackedMapOfInteger.def_static("operator delete_", (void (*)(void *)) &TColStd_PackedMapOfInteger::operator delete, "None", py::arg("theAddress"));
// cls_TColStd_PackedMapOfInteger.def_static("operator new[]_", (void * (*)(size_t)) &TColStd_PackedMapOfInteger::operator new[], "None", py::arg("theSize"));
// cls_TColStd_PackedMapOfInteger.def_static("operator delete[]_", (void (*)(void *)) &TColStd_PackedMapOfInteger::operator delete[], "None", py::arg("theAddress"));
// cls_TColStd_PackedMapOfInteger.def_static("operator new_", (void * (*)(size_t, void *)) &TColStd_PackedMapOfInteger::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColStd_PackedMapOfInteger.def_static("operator delete_", (void (*)(void *, void *)) &TColStd_PackedMapOfInteger::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColStd_PackedMapOfInteger.def("operator=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator=, "None", py::arg("Other"));
cls_TColStd_PackedMapOfInteger.def("Assign", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Assign, "None", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("ReSize", (void (TColStd_PackedMapOfInteger::*)(const Standard_Integer)) &TColStd_PackedMapOfInteger::ReSize, "None", py::arg("NbBuckets"));
cls_TColStd_PackedMapOfInteger.def("Clear", (void (TColStd_PackedMapOfInteger::*)()) &TColStd_PackedMapOfInteger::Clear, "None");
cls_TColStd_PackedMapOfInteger.def("Add", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const Standard_Integer)) &TColStd_PackedMapOfInteger::Add, "None", py::arg("aKey"));
cls_TColStd_PackedMapOfInteger.def("Contains", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const Standard_Integer) const) &TColStd_PackedMapOfInteger::Contains, "None", py::arg("aKey"));
cls_TColStd_PackedMapOfInteger.def("Remove", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const Standard_Integer)) &TColStd_PackedMapOfInteger::Remove, "None", py::arg("aKey"));
cls_TColStd_PackedMapOfInteger.def("NbBuckets", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::NbBuckets, "None");
cls_TColStd_PackedMapOfInteger.def("Extent", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::Extent, "None");
cls_TColStd_PackedMapOfInteger.def("IsEmpty", (Standard_Boolean (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::IsEmpty, "None");
cls_TColStd_PackedMapOfInteger.def("Statistics", (void (TColStd_PackedMapOfInteger::*)(Standard_OStream &) const) &TColStd_PackedMapOfInteger::Statistics, "None", py::arg("outStream"));
cls_TColStd_PackedMapOfInteger.def("GetMinimalMapped", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::GetMinimalMapped, "Query the minimal contained key value.");
cls_TColStd_PackedMapOfInteger.def("GetMaximalMapped", (Standard_Integer (TColStd_PackedMapOfInteger::*)() const) &TColStd_PackedMapOfInteger::GetMaximalMapped, "Query the maximal contained key value.");
cls_TColStd_PackedMapOfInteger.def("Union", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps. The new Map contains the values that are contained either in the first map or in the second map or in both. All previous contents of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg(""), py::arg(""));
cls_TColStd_PackedMapOfInteger.def("Unite", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union().", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("operator|=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator|=, "Overloaded operator version of Unite().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("Intersection", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous contents of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands. The order of operands makes no difference; the method minimizes internally the number of iterations using the smallest map for the loop.", py::arg(""), py::arg(""));
cls_TColStd_PackedMapOfInteger.def("Intersect", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection().", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("operator&=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator&=, "Overloaded operator version of Intersect().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("Subtraction", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous contents of this Map is cleared. This map (result of the boolean operation) can also be used as the first operand.", py::arg(""), py::arg(""));
cls_TColStd_PackedMapOfInteger.def("Subtract", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands.", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("__isub__", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator-=, py::is_operator(), "Overloaded operator version of Subtract().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("Difference", (void (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &, const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous contents of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg(""), py::arg(""));
cls_TColStd_PackedMapOfInteger.def("Differ", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference().", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("operator^=", (TColStd_PackedMapOfInteger & (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::operator^=, "Overloaded operator version of Differ().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("IsEqual", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::IsEqual, "Returns True if this map is equal to the given one, i.e. they contain the same sets of elements", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("__eq__", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::operator==, py::is_operator(), "Overloaded operator version of IsEqual().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("IsSubset", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::IsSubset, "Returns True if this map is subset of the given one, i.e. all elements contained in this map is contained also in the operand map. if this map is empty that this method returns true for any operand map.", py::arg(""));
cls_TColStd_PackedMapOfInteger.def("__le__", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::operator<=, py::is_operator(), "Overloaded operator version of IsSubset().", py::arg("MM"));
cls_TColStd_PackedMapOfInteger.def("HasIntersection", (Standard_Boolean (TColStd_PackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &) const) &TColStd_PackedMapOfInteger::HasIntersection, "Returns True if this map has common items with the given one.", py::arg(""));

// TYPEDEF: TCOLSTD_MAPITERATOROFPACKEDMAPOFINTEGER
py::class_<TColStd_PackedMapOfInteger::Iterator, TCollection_BasicMapIterator> cls_TColStd_PackedMapOfInteger_TColStd_MapIteratorOfPackedMapOfInteger(mod, "TColStd_MapIteratorOfPackedMapOfInteger", "Iterator of class TColStd_PackedMapOfInteger.");

// Constructors
cls_TColStd_PackedMapOfInteger_TColStd_MapIteratorOfPackedMapOfInteger.def(py::init<>());
cls_TColStd_PackedMapOfInteger_TColStd_MapIteratorOfPackedMapOfInteger.def(py::init<const TColStd_PackedMapOfInteger &>(), py::arg("theMap"));

// Methods
cls_TColStd_PackedMapOfInteger_TColStd_MapIteratorOfPackedMapOfInteger.def("Initialize", (void (TColStd_PackedMapOfInteger::Iterator::*)(const TColStd_PackedMapOfInteger &)) &TColStd_PackedMapOfInteger::Iterator::Initialize, "Re-initialize with the same or another Map instance.", py::arg("theMap"));
cls_TColStd_PackedMapOfInteger_TColStd_MapIteratorOfPackedMapOfInteger.def("Reset", (void (TColStd_PackedMapOfInteger::Iterator::*)()) &TColStd_PackedMapOfInteger::Iterator::Reset, "Restart the iteration");
cls_TColStd_PackedMapOfInteger_TColStd_MapIteratorOfPackedMapOfInteger.def("Key", (Standard_Integer (TColStd_PackedMapOfInteger::Iterator::*)() const) &TColStd_PackedMapOfInteger::Iterator::Key, "Query the iterated key.");
cls_TColStd_PackedMapOfInteger_TColStd_MapIteratorOfPackedMapOfInteger.def("Next", (void (TColStd_PackedMapOfInteger::Iterator::*)()) &TColStd_PackedMapOfInteger::Iterator::Next, "Increment the iterator");

// CLASS: TCOLSTD_HARRAY1OFTRANSIENT
bind_Define_HArray1<TColStd_HArray1OfTransient, TColStd_Array1OfTransient>(mod, "TColStd_HArray1OfTransient");

// TYPEDEF: TCOLSTD_SEQUENCEOFHEXTENDEDSTRING
bind_NCollection_Sequence<opencascade::handle<TCollection_HExtendedString> >(mod, "TColStd_SequenceOfHExtendedString", py::module_local(false));

// CLASS: TCOLSTD_HSEQUENCEOFHEXTENDEDSTRING
bind_Define_HSequence<TColStd_HSequenceOfHExtendedString, TColStd_SequenceOfHExtendedString>(mod, "TColStd_HSequenceOfHExtendedString");

// TYPEDEF: TCOLSTD_MAPOFASCIISTRING
bind_NCollection_Map<TCollection_AsciiString, TCollection_AsciiString>(mod, "TColStd_MapOfAsciiString", py::module_local(false));

// TYPEDEF: TCOLSTD_MAPITERATOROFMAPOFASCIISTRING

// TYPEDEF: TCOLSTD_ARRAY2OFBOOLEAN
bind_NCollection_Array2<bool>(mod, "TColStd_Array2OfBoolean", py::module_local(false));

// TYPEDEF: TCOLSTD_INDEXEDDATAMAPOFTRANSIENTTRANSIENT
bind_NCollection_IndexedDataMap<opencascade::handle<Standard_Transient>, opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TColStd_IndexedDataMapOfTransientTransient", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPOFSTRINGINTEGER
bind_NCollection_DataMap<TCollection_ExtendedString, int, TCollection_ExtendedString>(mod, "TColStd_DataMapOfStringInteger", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPITERATOROFDATAMAPOFSTRINGINTEGER

// TYPEDEF: TCOLSTD_LISTOFREAL
bind_NCollection_List<double>(mod, "TColStd_ListOfReal", py::module_local(false));

// TYPEDEF: TCOLSTD_LISTITERATOROFLISTOFREAL
bind_NCollection_TListIterator<double>(mod, "TColStd_ListIteratorOfListOfReal", py::module_local(false));

// TYPEDEF: TCOLSTD_LISTOFASCIISTRING
bind_NCollection_List<TCollection_AsciiString>(mod, "TColStd_ListOfAsciiString", py::module_local(false));

// TYPEDEF: TCOLSTD_LISTITERATOROFLISTOFASCIISTRING
bind_NCollection_TListIterator<TCollection_AsciiString>(mod, "TColStd_ListIteratorOfListOfAsciiString", py::module_local(false));

// CLASS: TCOLSTD_HARRAY1OFBOOLEAN
bind_Define_HArray1<TColStd_HArray1OfBoolean, TColStd_Array1OfBoolean>(mod, "TColStd_HArray1OfBoolean");

// CLASS: TCOLSTD_HSEQUENCEOFINTEGER
bind_Define_HSequence<TColStd_HSequenceOfInteger, TColStd_SequenceOfInteger>(mod, "TColStd_HSequenceOfInteger");

// TYPEDEF: TCOLSTD_SEQUENCEOFTRANSIENT
bind_NCollection_Sequence<opencascade::handle<Standard_Transient> >(mod, "TColStd_SequenceOfTransient", py::module_local(false));

// CLASS: TCOLSTD_HSEQUENCEOFTRANSIENT
bind_Define_HSequence<TColStd_HSequenceOfTransient, TColStd_SequenceOfTransient>(mod, "TColStd_HSequenceOfTransient");

// TYPEDEF: TCOLSTD_ARRAY2OFTRANSIENT
bind_NCollection_Array2<opencascade::handle<Standard_Transient> >(mod, "TColStd_Array2OfTransient", py::module_local(false));

// CLASS: TCOLSTD_HARRAY2OFTRANSIENT
bind_Define_HArray2<TColStd_HArray2OfTransient, TColStd_Array2OfTransient>(mod, "TColStd_HArray2OfTransient");

// CLASS: TCOLSTD_HPACKEDMAPOFINTEGER
py::class_<TColStd_HPackedMapOfInteger, opencascade::handle<TColStd_HPackedMapOfInteger>, Standard_Transient> cls_TColStd_HPackedMapOfInteger(mod, "TColStd_HPackedMapOfInteger", "Extension of TColStd_PackedMapOfInteger class to be manipulated by handle.");

// Constructors
cls_TColStd_HPackedMapOfInteger.def(py::init<>());
cls_TColStd_HPackedMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TColStd_HPackedMapOfInteger.def(py::init<const TColStd_PackedMapOfInteger &>(), py::arg("theOther"));

// Methods
cls_TColStd_HPackedMapOfInteger.def("Map", (const TColStd_PackedMapOfInteger & (TColStd_HPackedMapOfInteger::*)() const) &TColStd_HPackedMapOfInteger::Map, "Access to the map");
cls_TColStd_HPackedMapOfInteger.def("ChangeMap", (TColStd_PackedMapOfInteger & (TColStd_HPackedMapOfInteger::*)()) &TColStd_HPackedMapOfInteger::ChangeMap, "Access to the map for modification");
cls_TColStd_HPackedMapOfInteger.def_static("get_type_name_", (const char * (*)()) &TColStd_HPackedMapOfInteger::get_type_name, "None");
cls_TColStd_HPackedMapOfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HPackedMapOfInteger::get_type_descriptor, "None");
cls_TColStd_HPackedMapOfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HPackedMapOfInteger::*)() const) &TColStd_HPackedMapOfInteger::DynamicType, "None");

// CLASS: TCOLSTD_HARRAY1OFASCIISTRING
bind_Define_HArray1<TColStd_HArray1OfAsciiString, TColStd_Array1OfAsciiString>(mod, "TColStd_HArray1OfAsciiString");

// TYPEDEF: TCOLSTD_ARRAY1OFEXTENDEDSTRING
bind_NCollection_Array1<TCollection_ExtendedString>(mod, "TColStd_Array1OfExtendedString", py::module_local(false));

// CLASS: TCOLSTD_HARRAY1OFEXTENDEDSTRING
bind_Define_HArray1<TColStd_HArray1OfExtendedString, TColStd_Array1OfExtendedString>(mod, "TColStd_HArray1OfExtendedString");

// TYPEDEF: TCOLSTD_ARRAY1OFCHARACTER
bind_NCollection_Array1<char>(mod, "TColStd_Array1OfCharacter", py::module_local(false));

// TYPEDEF: TCOLSTD_ARRAY2OFCHARACTER
bind_NCollection_Array2<char>(mod, "TColStd_Array2OfCharacter", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPOFTRANSIENTTRANSIENT
bind_NCollection_DataMap<opencascade::handle<Standard_Transient>, opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TColStd_DataMapOfTransientTransient", py::module_local(false));

// TYPEDEF: TCOLSTD_DATAMAPITERATOROFDATAMAPOFTRANSIENTTRANSIENT

// CLASS: TCOLSTD_HARRAY1OFCHARACTER
bind_Define_HArray1<TColStd_HArray1OfCharacter, TColStd_Array1OfCharacter>(mod, "TColStd_HArray1OfCharacter");

// CLASS: TCOLSTD_HARRAY2OFBOOLEAN
bind_Define_HArray2<TColStd_HArray2OfBoolean, TColStd_Array2OfBoolean>(mod, "TColStd_HArray2OfBoolean");

// CLASS: TCOLSTD_HARRAY2OFCHARACTER
bind_Define_HArray2<TColStd_HArray2OfCharacter, TColStd_Array2OfCharacter>(mod, "TColStd_HArray2OfCharacter");

// CLASS: TCOLSTD_HSEQUENCEOFEXTENDEDSTRING
bind_Define_HSequence<TColStd_HSequenceOfExtendedString, TColStd_SequenceOfExtendedString>(mod, "TColStd_HSequenceOfExtendedString");

// TYPEDEF: TCOLSTD_MAPREALHASHER
bind_NCollection_DefaultHasher<double>(mod, "TColStd_MapRealHasher", py::module_local(false));

// TYPEDEF: TCOLSTD_INDEXEDMAPOFREAL
bind_NCollection_IndexedMap<double, NCollection_DefaultHasher<double> >(mod, "TColStd_IndexedMapOfReal", py::module_local(false));

// TYPEDEF: TCOLSTD_MAPOFREAL
bind_NCollection_Map<double, NCollection_DefaultHasher<double> >(mod, "TColStd_MapOfReal", py::module_local(false));

// TYPEDEF: TCOLSTD_MAPITERATOROFMAPOFREAL


}
