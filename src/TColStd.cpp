/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

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
#include <NCollection_Templates.hpp>

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
	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array1OfReal.hxx
	other_mod = py::module::import("OCCT.TColQuantity");
	if (py::hasattr(other_mod, "TColQuantity_Array1OfLength")) {
		mod.attr("TColStd_Array1OfReal") = other_mod.attr("TColQuantity_Array1OfLength");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array1OfInteger.hxx
	bind_NCollection_Array1<int>(mod, "TColStd_Array1OfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_SequenceOfReal.hxx
	bind_NCollection_Sequence<double>(mod, "TColStd_SequenceOfReal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array2OfReal.hxx
	other_mod = py::module::import("OCCT.TColQuantity");
	if (py::hasattr(other_mod, "TColQuantity_Array2OfLength")) {
		mod.attr("TColStd_Array2OfReal") = other_mod.attr("TColQuantity_Array2OfLength");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array1OfByte.hxx
	bind_NCollection_Array1<unsigned char>(mod, "TColStd_Array1OfByte");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_SequenceOfHAsciiString.hxx
	bind_NCollection_Sequence<opencascade::handle<TCollection_HAsciiString> >(mod, "TColStd_SequenceOfHAsciiString");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array2OfInteger.hxx
	bind_NCollection_Array2<int>(mod, "TColStd_Array2OfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_SequenceOfAsciiString.hxx
	bind_NCollection_Sequence<TCollection_AsciiString>(mod, "TColStd_SequenceOfAsciiString");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array1OfListOfInteger.hxx
	bind_NCollection_Array1<NCollection_List<int> >(mod, "TColStd_Array1OfListOfInteger");

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array1OfBoolean.hxx
	bind_NCollection_Array1<bool>(mod, "TColStd_Array1OfBoolean");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_SequenceOfInteger.hxx
	bind_NCollection_Sequence<int>(mod, "TColStd_SequenceOfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array1OfTransient.hxx
	bind_NCollection_Array1<opencascade::handle<Standard_Transient> >(mod, "TColStd_Array1OfTransient");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_SequenceOfTransient.hxx
	bind_NCollection_Sequence<opencascade::handle<Standard_Transient> >(mod, "TColStd_SequenceOfTransient");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array2OfTransient.hxx
	bind_NCollection_Array2<opencascade::handle<Standard_Transient> >(mod, "TColStd_Array2OfTransient");

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array1OfAsciiString.hxx
	bind_NCollection_Array1<TCollection_AsciiString>(mod, "TColStd_Array1OfAsciiString");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_SequenceOfHExtendedString.hxx
	bind_NCollection_Sequence<opencascade::handle<TCollection_HExtendedString> >(mod, "TColStd_SequenceOfHExtendedString");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapIteratorOfPackedMapOfInteger.hxx
	py::class_<TColStd_MapIteratorOfPackedMapOfInteger, std::unique_ptr<TColStd_MapIteratorOfPackedMapOfInteger, Deleter<TColStd_MapIteratorOfPackedMapOfInteger>>, TCollection_BasicMapIterator> cls_TColStd_MapIteratorOfPackedMapOfInteger(mod, "TColStd_MapIteratorOfPackedMapOfInteger", "Iterator of class TColStd_PackedMapOfInteger");
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def(py::init<>());
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def(py::init<const TColStd_PackedMapOfInteger &>(), py::arg(""));
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Initialize", (void (TColStd_MapIteratorOfPackedMapOfInteger::*)(const TColStd_PackedMapOfInteger &)) &TColStd_MapIteratorOfPackedMapOfInteger::Initialize, "Re-initialize with the same or another Map instance.", py::arg(""));
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Reset", (void (TColStd_MapIteratorOfPackedMapOfInteger::*)()) &TColStd_MapIteratorOfPackedMapOfInteger::Reset, "Restart the iteraton");
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Key", (Standard_Integer (TColStd_MapIteratorOfPackedMapOfInteger::*)() const ) &TColStd_MapIteratorOfPackedMapOfInteger::Key, "Query the iterated key. Defined in TColStd_PackedMapOfInteger.cxx");
	cls_TColStd_MapIteratorOfPackedMapOfInteger.def("Next", (void (TColStd_MapIteratorOfPackedMapOfInteger::*)()) &TColStd_MapIteratorOfPackedMapOfInteger::Next, "Increment the iterator");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array1OfExtendedString.hxx
	bind_NCollection_Array1<TCollection_ExtendedString>(mod, "TColStd_Array1OfExtendedString");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array1OfCharacter.hxx
	bind_NCollection_Array1<char>(mod, "TColStd_Array1OfCharacter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array2OfBoolean.hxx
	bind_NCollection_Array2<bool>(mod, "TColStd_Array2OfBoolean");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_Array2OfCharacter.hxx
	bind_NCollection_Array2<char>(mod, "TColStd_Array2OfCharacter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_SequenceOfExtendedString.hxx
	bind_NCollection_Sequence<TCollection_ExtendedString>(mod, "TColStd_SequenceOfExtendedString");

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_ListOfInteger.hxx
	bind_NCollection_List<int>(mod, "TColStd_ListOfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_ListOfInteger.hxx
	bind_NCollection_TListIterator<int>(mod, "TColStd_ListIteratorOfListOfInteger");

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_IndexedDataMapOfStringString.hxx
	bind_NCollection_IndexedDataMap<TCollection_AsciiString, TCollection_AsciiString, TCollection_AsciiString>(mod, "TColStd_IndexedDataMapOfStringString");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_ListOfTransient.hxx
	bind_NCollection_List<opencascade::handle<Standard_Transient> >(mod, "TColStd_ListOfTransient");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_ListOfTransient.hxx
	bind_NCollection_TListIterator<opencascade::handle<Standard_Transient> >(mod, "TColStd_ListIteratorOfListOfTransient");

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapTransientHasher.hxx
	bind_NCollection_DefaultHasher<opencascade::handle<Standard_Transient> >(mod, "TColStd_MapTransientHasher");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapOfTransient.hxx
	bind_NCollection_Map<opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TColStd_MapOfTransient");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapIntegerHasher.hxx
	bind_NCollection_DefaultHasher<int>(mod, "TColStd_MapIntegerHasher");

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfIntegerListOfInteger.hxx
	bind_NCollection_DataMap<int, NCollection_List<int>, NCollection_DefaultHasher<int> >(mod, "TColStd_DataMapOfIntegerListOfInteger");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapOfInteger.hxx
	bind_NCollection_Map<int, NCollection_DefaultHasher<int> >(mod, "TColStd_MapOfInteger");

	/* FIXME

	*/

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_SequenceOfAddress.hxx
	bind_NCollection_Sequence<void *>(mod, "TColStd_SequenceOfAddress");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfIntegerTransient.hxx
	bind_NCollection_DataMap<int, opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<int> >(mod, "TColStd_DataMapOfIntegerTransient");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_IndexedMapOfTransient.hxx
	bind_NCollection_IndexedMap<opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TColStd_IndexedMapOfTransient");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfAsciiStringInteger.hxx
	bind_NCollection_DataMap<TCollection_AsciiString, int, TCollection_AsciiString>(mod, "TColStd_DataMapOfAsciiStringInteger");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfIntegerInteger.hxx
	bind_NCollection_DataMap<int, int, NCollection_DefaultHasher<int> >(mod, "TColStd_DataMapOfIntegerInteger");

	/* FIXME

	*/

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_IndexedMapOfInteger.hxx
	bind_NCollection_IndexedMap<int, NCollection_DefaultHasher<int> >(mod, "TColStd_IndexedMapOfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_SequenceOfBoolean.hxx
	bind_NCollection_Sequence<bool>(mod, "TColStd_SequenceOfBoolean");

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapOfAsciiString.hxx
	bind_NCollection_Map<TCollection_AsciiString, TCollection_AsciiString>(mod, "TColStd_MapOfAsciiString");

	/* FIXME

	*/

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_IndexedDataMapOfTransientTransient.hxx
	bind_NCollection_IndexedDataMap<opencascade::handle<Standard_Transient>, opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TColStd_IndexedDataMapOfTransientTransient");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfStringInteger.hxx
	bind_NCollection_DataMap<TCollection_ExtendedString, int, TCollection_ExtendedString>(mod, "TColStd_DataMapOfStringInteger");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_ListOfReal.hxx
	bind_NCollection_List<double>(mod, "TColStd_ListOfReal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_ListOfReal.hxx
	bind_NCollection_TListIterator<double>(mod, "TColStd_ListIteratorOfListOfReal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_ListOfAsciiString.hxx
	bind_NCollection_List<TCollection_AsciiString>(mod, "TColStd_ListOfAsciiString");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_ListOfAsciiString.hxx
	bind_NCollection_TListIterator<TCollection_AsciiString>(mod, "TColStd_ListIteratorOfListOfAsciiString");

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfIntegerReal.hxx
	bind_NCollection_DataMap<int, double, NCollection_DefaultHasher<int> >(mod, "TColStd_DataMapOfIntegerReal");

	/* FIXME

	*/

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_DataMapOfTransientTransient.hxx
	bind_NCollection_DataMap<opencascade::handle<Standard_Transient>, opencascade::handle<Standard_Transient>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "TColStd_DataMapOfTransientTransient");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapRealHasher.hxx
	bind_NCollection_DefaultHasher<double>(mod, "TColStd_MapRealHasher");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_IndexedMapOfReal.hxx
	bind_NCollection_IndexedMap<double, NCollection_DefaultHasher<double> >(mod, "TColStd_IndexedMapOfReal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColStd_MapOfReal.hxx
	bind_NCollection_Map<double, NCollection_DefaultHasher<double> >(mod, "TColStd_MapOfReal");

	/* FIXME

	*/


}
