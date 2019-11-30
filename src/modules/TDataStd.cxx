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
#include <TDataStd_RealEnum.hxx>
#include <TDF_Attribute.hxx>
#include <TDataStd_DeltaOnModificationOfIntArray.hxx>
#include <Standard_Std.hxx>
#include <TDataStd_IntegerArray.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDF_DeltaOnModification.hxx>
#include <TDataStd_DeltaOnModificationOfRealArray.hxx>
#include <TDataStd_RealArray.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TDataStd_DeltaOnModificationOfByteArray.hxx>
#include <TDataStd_ByteArray.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <TDataStd_DeltaOnModificationOfExtStringArray.hxx>
#include <TDataStd_ExtStringArray.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_HArray1OfExtendedString.hxx>
#include <TDataStd_BooleanArray.hxx>
#include <NCollection_Array1.hxx>
#include <TDataStd_LabelArray1.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TDataStd_HLabelArray1.hxx>
#include <TDataStd_ReferenceArray.hxx>
#include <TDF_DataSet.hxx>
#include <TDataStd_IntegerList.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TDataStd_RealList.hxx>
#include <TColStd_ListOfReal.hxx>
#include <NCollection_List.hxx>
#include <TDataStd_ListOfExtendedString.hxx>
#include <TDataStd_ExtStringList.hxx>
#include <TDataStd_ListOfByte.hxx>
#include <TDataStd_BooleanList.hxx>
#include <TDataStd_ReferenceList.hxx>
#include <TDF_LabelList.hxx>
#include <TDataStd_DeltaOnModificationOfIntPackedMap.hxx>
#include <TDataStd_IntPackedMap.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <TDataStd_Expression.hxx>
#include <TDF_AttributeList.hxx>
#include <TDataStd_Relation.hxx>
#include <NCollection_DataMap.hxx>
#include <TDataStd_DataMapOfStringReal.hxx>
#include <TDataStd_DataMapOfStringString.hxx>
#include <TDataStd_DataMapOfStringByte.hxx>
#include <TDataStd_DataMapOfStringHArray1OfInteger.hxx>
#include <TDataStd_DataMapOfStringHArray1OfReal.hxx>
#include <TDataStd_NamedData.hxx>
#include <TColStd_DataMapOfStringInteger.hxx>
#include <TDataStd_HDataMapOfStringInteger.hxx>
#include <TDataStd_HDataMapOfStringReal.hxx>
#include <TDataStd_HDataMapOfStringString.hxx>
#include <TDataStd_HDataMapOfStringByte.hxx>
#include <TDataStd_HDataMapOfStringHArray1OfInteger.hxx>
#include <TDataStd_HDataMapOfStringHArray1OfReal.hxx>
#include <TDataStd_Real.hxx>
#include <TDataStd_TreeNode.hxx>
#include <TDataStd_PtrTreeNode.hxx>
#include <TDF_AttributeDelta.hxx>
#include <TDataStd_ChildNodeIterator.hxx>
#include <TDataStd_Integer.hxx>
#include <TDataStd_UAttribute.hxx>
#include <TDataStd_Name.hxx>
#include <TDataStd_Comment.hxx>
#include <TDataStd_AsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <TDataStd_Variable.hxx>
#include <TDataStd_Directory.hxx>
#include <TDataStd_Tick.hxx>
#include <TDataStd_NoteBook.hxx>
#include <TDF_IDList.hxx>
#include <TDataStd_Current.hxx>
#include <TDataStd.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(TDataStd, mod) {

py::module::import("OCCT.TDF");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");

// ENUM: TDATASTD_REALENUM
py::enum_<TDataStd_RealEnum>(mod, "TDataStd_RealEnum", "The terms of this enumeration define the semantics of a real number value.")
	.value("TDataStd_SCALAR", TDataStd_RealEnum::TDataStd_SCALAR)
	.value("TDataStd_LENGTH", TDataStd_RealEnum::TDataStd_LENGTH)
	.value("TDataStd_ANGULAR", TDataStd_RealEnum::TDataStd_ANGULAR)
	.export_values();


// CLASS: TDATASTD_INTEGERARRAY
py::class_<TDataStd_IntegerArray, opencascade::handle<TDataStd_IntegerArray>, TDF_Attribute> cls_TDataStd_IntegerArray(mod, "TDataStd_IntegerArray", "Contains an array of integers.");

// Constructors
cls_TDataStd_IntegerArray.def(py::init<>());

// Methods
cls_TDataStd_IntegerArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_IntegerArray::get_type_name, "None");
cls_TDataStd_IntegerArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_IntegerArray::get_type_descriptor, "None");
cls_TDataStd_IntegerArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_IntegerArray::*)() const) &TDataStd_IntegerArray::DynamicType, "None");
cls_TDataStd_IntegerArray.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_IntegerArray::GetID, "class methods ============= Returns the GUID for arrays of integers.");
cls_TDataStd_IntegerArray.def_static("Set_", [](const TDF_Label & a0, const Standard_Integer a1, const Standard_Integer a2) -> opencascade::handle<TDataStd_IntegerArray> { return TDataStd_IntegerArray::Set(a0, a1, a2); });
cls_TDataStd_IntegerArray.def_static("Set_", (opencascade::handle<TDataStd_IntegerArray> (*)(const TDF_Label &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TDataStd_IntegerArray::Set, "Finds or creates on the <label> an integer array attribute with the specified <lower> and <upper> boundaries. If <isDelta> == False, DefaultDeltaOnModification is used. If <isDelta> == True, DeltaOnModification of the current attribute is used. If attribute is already set, all input parameters are refused and the found attribute is returned.", py::arg("label"), py::arg("lower"), py::arg("upper"), py::arg("isDelta"));
cls_TDataStd_IntegerArray.def_static("Set_", [](const TDF_Label & a0, const Standard_GUID & a1, const Standard_Integer a2, const Standard_Integer a3) -> opencascade::handle<TDataStd_IntegerArray> { return TDataStd_IntegerArray::Set(a0, a1, a2, a3); });
cls_TDataStd_IntegerArray.def_static("Set_", (opencascade::handle<TDataStd_IntegerArray> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TDataStd_IntegerArray::Set, "Finds, or creates, an IntegerArray attribute with explicit user defined <guid>. The IntegerArray attribute is returned.", py::arg("label"), py::arg("theGuid"), py::arg("lower"), py::arg("upper"), py::arg("isDelta"));
cls_TDataStd_IntegerArray.def("Init", (void (TDataStd_IntegerArray::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerArray::Init, "Initialize the inner array with bounds from <lower> to <upper>", py::arg("lower"), py::arg("upper"));
cls_TDataStd_IntegerArray.def("SetValue", (void (TDataStd_IntegerArray::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerArray::SetValue, "Sets the <Index>th element of the array to <Value> OutOfRange exception is raised if <Index> doesn't respect Lower and Upper bounds of the internal array.", py::arg("Index"), py::arg("Value"));
cls_TDataStd_IntegerArray.def("SetID", (void (TDataStd_IntegerArray::*)(const Standard_GUID &)) &TDataStd_IntegerArray::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_IntegerArray.def("SetID", (void (TDataStd_IntegerArray::*)()) &TDataStd_IntegerArray::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_IntegerArray.def("Value", (Standard_Integer (TDataStd_IntegerArray::*)(const Standard_Integer) const) &TDataStd_IntegerArray::Value, "Return the value of the <Index>th element of the array", py::arg("Index"));
cls_TDataStd_IntegerArray.def("__call__", (Standard_Integer (TDataStd_IntegerArray::*)(const Standard_Integer) const) &TDataStd_IntegerArray::operator(), py::is_operator(), "None", py::arg("Index"));
cls_TDataStd_IntegerArray.def("Lower", (Standard_Integer (TDataStd_IntegerArray::*)() const) &TDataStd_IntegerArray::Lower, "Returns the lower boundary of this array of integers.");
cls_TDataStd_IntegerArray.def("Upper", (Standard_Integer (TDataStd_IntegerArray::*)() const) &TDataStd_IntegerArray::Upper, "Return the upper boundary of this array of integers.");
cls_TDataStd_IntegerArray.def("Length", (Standard_Integer (TDataStd_IntegerArray::*)() const) &TDataStd_IntegerArray::Length, "Returns the length of this array of integers in terms of the number of elements it contains.");
cls_TDataStd_IntegerArray.def("ChangeArray", [](TDataStd_IntegerArray &self, const opencascade::handle<TColStd_HArray1OfInteger> & a0) -> void { return self.ChangeArray(a0); });
cls_TDataStd_IntegerArray.def("ChangeArray", (void (TDataStd_IntegerArray::*)(const opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Boolean)) &TDataStd_IntegerArray::ChangeArray, "Sets the inner array <myValue> of the IntegerArray attribute to <newArray>. If value of <newArray> differs from <myValue>, Backup performed and myValue refers to new instance of HArray1OfInteger that holds <newArray> values If <isCheckItems> equal True each item of <newArray> will be checked with each item of <myValue> for coincidence (to avoid backup).", py::arg("newArray"), py::arg("isCheckItems"));
cls_TDataStd_IntegerArray.def("Array", (const opencascade::handle<TColStd_HArray1OfInteger> & (TDataStd_IntegerArray::*)() const) &TDataStd_IntegerArray::Array, "Return the inner array of the IntegerArray attribute");
cls_TDataStd_IntegerArray.def("GetDelta", (Standard_Boolean (TDataStd_IntegerArray::*)() const) &TDataStd_IntegerArray::GetDelta, "None");
cls_TDataStd_IntegerArray.def("SetDelta", (void (TDataStd_IntegerArray::*)(const Standard_Boolean)) &TDataStd_IntegerArray::SetDelta, "for internal use only!", py::arg("isDelta"));
cls_TDataStd_IntegerArray.def("ID", (const Standard_GUID & (TDataStd_IntegerArray::*)() const) &TDataStd_IntegerArray::ID, "None");
cls_TDataStd_IntegerArray.def("Restore", (void (TDataStd_IntegerArray::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_IntegerArray::Restore, "None", py::arg("With"));
cls_TDataStd_IntegerArray.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_IntegerArray::*)() const) &TDataStd_IntegerArray::NewEmpty, "None");
cls_TDataStd_IntegerArray.def("Paste", (void (TDataStd_IntegerArray::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_IntegerArray::Paste, "Note. Uses inside ChangeArray() method", py::arg("Into"), py::arg("RT"));
cls_TDataStd_IntegerArray.def("Dump", (Standard_OStream & (TDataStd_IntegerArray::*)(Standard_OStream &) const) &TDataStd_IntegerArray::Dump, "None", py::arg("anOS"));
cls_TDataStd_IntegerArray.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TDataStd_IntegerArray::*)(const opencascade::handle<TDF_Attribute> &) const) &TDataStd_IntegerArray::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute>.", py::arg("anOldAttribute"));

// CLASS: TDATASTD_REALARRAY
py::class_<TDataStd_RealArray, opencascade::handle<TDataStd_RealArray>, TDF_Attribute> cls_TDataStd_RealArray(mod, "TDataStd_RealArray", "A framework for an attribute composed of a real number array.");

// Constructors
cls_TDataStd_RealArray.def(py::init<>());

// Methods
cls_TDataStd_RealArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_RealArray::get_type_name, "None");
cls_TDataStd_RealArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_RealArray::get_type_descriptor, "None");
cls_TDataStd_RealArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_RealArray::*)() const) &TDataStd_RealArray::DynamicType, "None");
cls_TDataStd_RealArray.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_RealArray::GetID, "class methods ============= Returns the GUID for arrays of reals.");
cls_TDataStd_RealArray.def_static("Set_", [](const TDF_Label & a0, const Standard_Integer a1, const Standard_Integer a2) -> opencascade::handle<TDataStd_RealArray> { return TDataStd_RealArray::Set(a0, a1, a2); });
cls_TDataStd_RealArray.def_static("Set_", (opencascade::handle<TDataStd_RealArray> (*)(const TDF_Label &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TDataStd_RealArray::Set, "Finds or creates on the <label> a real array attribute with the specified <lower> and <upper> boundaries. If <isDelta> == False, DefaultDeltaOnModification is used. If <isDelta> == True, DeltaOnModification of the current attribute is used. If attribute is already set, input parameter <isDelta> is refused and the found attribute returned.", py::arg("label"), py::arg("lower"), py::arg("upper"), py::arg("isDelta"));
cls_TDataStd_RealArray.def_static("Set_", [](const TDF_Label & a0, const Standard_GUID & a1, const Standard_Integer a2, const Standard_Integer a3) -> opencascade::handle<TDataStd_RealArray> { return TDataStd_RealArray::Set(a0, a1, a2, a3); });
cls_TDataStd_RealArray.def_static("Set_", (opencascade::handle<TDataStd_RealArray> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TDataStd_RealArray::Set, "Finds, or creates, an RealArray attribute with explicit user defined <guid>. The RealArray attribute is returned.", py::arg("label"), py::arg("theGuid"), py::arg("lower"), py::arg("upper"), py::arg("isDelta"));
cls_TDataStd_RealArray.def("Init", (void (TDataStd_RealArray::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_RealArray::Init, "Initialize the inner array with bounds from <lower> to <upper>", py::arg("lower"), py::arg("upper"));
cls_TDataStd_RealArray.def("SetID", (void (TDataStd_RealArray::*)(const Standard_GUID &)) &TDataStd_RealArray::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_RealArray.def("SetID", (void (TDataStd_RealArray::*)()) &TDataStd_RealArray::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_RealArray.def("SetValue", (void (TDataStd_RealArray::*)(const Standard_Integer, const Standard_Real)) &TDataStd_RealArray::SetValue, "Sets the <Index>th element of the array to <Value> OutOfRange exception is raised if <Index> doesn't respect Lower and Upper bounds of the internal array.", py::arg("Index"), py::arg("Value"));
cls_TDataStd_RealArray.def("Value", (Standard_Real (TDataStd_RealArray::*)(const Standard_Integer) const) &TDataStd_RealArray::Value, "Return the value of the <Index>th element of the array", py::arg("Index"));
cls_TDataStd_RealArray.def("__call__", (Standard_Real (TDataStd_RealArray::*)(const Standard_Integer) const) &TDataStd_RealArray::operator(), py::is_operator(), "None", py::arg("Index"));
cls_TDataStd_RealArray.def("Lower", (Standard_Integer (TDataStd_RealArray::*)() const) &TDataStd_RealArray::Lower, "Returns the lower boundary of the array.");
cls_TDataStd_RealArray.def("Upper", (Standard_Integer (TDataStd_RealArray::*)() const) &TDataStd_RealArray::Upper, "Returns the upper boundary of the array.");
cls_TDataStd_RealArray.def("Length", (Standard_Integer (TDataStd_RealArray::*)() const) &TDataStd_RealArray::Length, "Returns the number of elements of the array of reals in terms of the number of elements it contains.");
cls_TDataStd_RealArray.def("ChangeArray", [](TDataStd_RealArray &self, const opencascade::handle<TColStd_HArray1OfReal> & a0) -> void { return self.ChangeArray(a0); });
cls_TDataStd_RealArray.def("ChangeArray", (void (TDataStd_RealArray::*)(const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Boolean)) &TDataStd_RealArray::ChangeArray, "Sets the inner array <myValue> of the RealArray attribute to <newArray>. If value of <newArray> differs from <myValue>, Backup performed and myValue refers to new instance of HArray1OfReal that holds <newArray> values If <isCheckItems> equal True each item of <newArray> will be checked with each item of <myValue> for coincidence (to avoid backup).", py::arg("newArray"), py::arg("isCheckItems"));
cls_TDataStd_RealArray.def("Array", (const opencascade::handle<TColStd_HArray1OfReal> & (TDataStd_RealArray::*)() const) &TDataStd_RealArray::Array, "Returns the handle of this array of reals.");
cls_TDataStd_RealArray.def("GetDelta", (Standard_Boolean (TDataStd_RealArray::*)() const) &TDataStd_RealArray::GetDelta, "None");
cls_TDataStd_RealArray.def("SetDelta", (void (TDataStd_RealArray::*)(const Standard_Boolean)) &TDataStd_RealArray::SetDelta, "for internal use only!", py::arg("isDelta"));
cls_TDataStd_RealArray.def("ID", (const Standard_GUID & (TDataStd_RealArray::*)() const) &TDataStd_RealArray::ID, "None");
cls_TDataStd_RealArray.def("Restore", (void (TDataStd_RealArray::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_RealArray::Restore, "None", py::arg("With"));
cls_TDataStd_RealArray.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_RealArray::*)() const) &TDataStd_RealArray::NewEmpty, "None");
cls_TDataStd_RealArray.def("Paste", (void (TDataStd_RealArray::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_RealArray::Paste, "Note. Uses inside ChangeArray() method", py::arg("Into"), py::arg("RT"));
cls_TDataStd_RealArray.def("Dump", (Standard_OStream & (TDataStd_RealArray::*)(Standard_OStream &) const) &TDataStd_RealArray::Dump, "None", py::arg("anOS"));
cls_TDataStd_RealArray.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TDataStd_RealArray::*)(const opencascade::handle<TDF_Attribute> &) const) &TDataStd_RealArray::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute>.", py::arg("anOldAttribute"));

// CLASS: TDATASTD_BYTEARRAY
py::class_<TDataStd_ByteArray, opencascade::handle<TDataStd_ByteArray>, TDF_Attribute> cls_TDataStd_ByteArray(mod, "TDataStd_ByteArray", "An array of Byte (unsigned char) values.");

// Constructors
cls_TDataStd_ByteArray.def(py::init<>());

// Methods
cls_TDataStd_ByteArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_ByteArray::get_type_name, "None");
cls_TDataStd_ByteArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_ByteArray::get_type_descriptor, "None");
cls_TDataStd_ByteArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_ByteArray::*)() const) &TDataStd_ByteArray::DynamicType, "None");
cls_TDataStd_ByteArray.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_ByteArray::GetID, "Static methods ============== Returns an ID for array.");
cls_TDataStd_ByteArray.def_static("Set_", [](const TDF_Label & a0, const Standard_Integer a1, const Standard_Integer a2) -> opencascade::handle<TDataStd_ByteArray> { return TDataStd_ByteArray::Set(a0, a1, a2); });
cls_TDataStd_ByteArray.def_static("Set_", (opencascade::handle<TDataStd_ByteArray> (*)(const TDF_Label &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TDataStd_ByteArray::Set, "Finds or creates an attribute with the array on the specified label. If <isDelta> == False, DefaultDeltaOnModification is used. If <isDelta> == True, DeltaOnModification of the current attribute is used. If attribute is already set, all input parameters are refused and the found attribute is returned.", py::arg("label"), py::arg("lower"), py::arg("upper"), py::arg("isDelta"));
cls_TDataStd_ByteArray.def_static("Set_", [](const TDF_Label & a0, const Standard_GUID & a1, const Standard_Integer a2, const Standard_Integer a3) -> opencascade::handle<TDataStd_ByteArray> { return TDataStd_ByteArray::Set(a0, a1, a2, a3); });
cls_TDataStd_ByteArray.def_static("Set_", (opencascade::handle<TDataStd_ByteArray> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TDataStd_ByteArray::Set, "Finds or creates an attribute with byte array and explicit user defined <guid> on the specified label.", py::arg("label"), py::arg("theGuid"), py::arg("lower"), py::arg("upper"), py::arg("isDelta"));
cls_TDataStd_ByteArray.def("Init", (void (TDataStd_ByteArray::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_ByteArray::Init, "Initialize the inner array with bounds from <lower> to <upper>", py::arg("lower"), py::arg("upper"));
cls_TDataStd_ByteArray.def("SetValue", (void (TDataStd_ByteArray::*)(const Standard_Integer, const Standard_Byte)) &TDataStd_ByteArray::SetValue, "Sets the <Index>th element of the array to <Value> OutOfRange exception is raised if <Index> doesn't respect Lower and Upper bounds of the internal array.", py::arg("index"), py::arg("value"));
cls_TDataStd_ByteArray.def("SetID", (void (TDataStd_ByteArray::*)(const Standard_GUID &)) &TDataStd_ByteArray::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_ByteArray.def("SetID", (void (TDataStd_ByteArray::*)()) &TDataStd_ByteArray::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_ByteArray.def("Value", (Standard_Byte (TDataStd_ByteArray::*)(const Standard_Integer) const) &TDataStd_ByteArray::Value, "Return the value of the <Index>th element of the array.", py::arg("Index"));
cls_TDataStd_ByteArray.def("__call__", (Standard_Byte (TDataStd_ByteArray::*)(const Standard_Integer) const) &TDataStd_ByteArray::operator(), py::is_operator(), "None", py::arg("Index"));
cls_TDataStd_ByteArray.def("Lower", (Standard_Integer (TDataStd_ByteArray::*)() const) &TDataStd_ByteArray::Lower, "Returns the lower boundary of the array.");
cls_TDataStd_ByteArray.def("Upper", (Standard_Integer (TDataStd_ByteArray::*)() const) &TDataStd_ByteArray::Upper, "Returns the upper boundary of the array.");
cls_TDataStd_ByteArray.def("Length", (Standard_Integer (TDataStd_ByteArray::*)() const) &TDataStd_ByteArray::Length, "Returns the number of elements in the array.");
cls_TDataStd_ByteArray.def("InternalArray", (const opencascade::handle<TColStd_HArray1OfByte> & (TDataStd_ByteArray::*)() const) &TDataStd_ByteArray::InternalArray, "None");
cls_TDataStd_ByteArray.def("ChangeArray", [](TDataStd_ByteArray &self, const opencascade::handle<TColStd_HArray1OfByte> & a0) -> void { return self.ChangeArray(a0); });
cls_TDataStd_ByteArray.def("ChangeArray", (void (TDataStd_ByteArray::*)(const opencascade::handle<TColStd_HArray1OfByte> &, const Standard_Boolean)) &TDataStd_ByteArray::ChangeArray, "Sets the inner array <myValue> of the attribute to <newArray>. If value of <newArray> differs from <myValue>, Backup performed and myValue refers to new instance of HArray1OfInteger that holds <newArray> values. If <isCheckItems> equal True each item of <newArray> will be checked with each item of <myValue> for coincidence (to avoid backup).", py::arg("newArray"), py::arg("isCheckItems"));
cls_TDataStd_ByteArray.def("GetDelta", (Standard_Boolean (TDataStd_ByteArray::*)() const) &TDataStd_ByteArray::GetDelta, "None");
cls_TDataStd_ByteArray.def("SetDelta", (void (TDataStd_ByteArray::*)(const Standard_Boolean)) &TDataStd_ByteArray::SetDelta, "for internal use only!", py::arg("isDelta"));
cls_TDataStd_ByteArray.def("ID", (const Standard_GUID & (TDataStd_ByteArray::*)() const) &TDataStd_ByteArray::ID, "None");
cls_TDataStd_ByteArray.def("Restore", (void (TDataStd_ByteArray::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_ByteArray::Restore, "None", py::arg("with"));
cls_TDataStd_ByteArray.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_ByteArray::*)() const) &TDataStd_ByteArray::NewEmpty, "None");
cls_TDataStd_ByteArray.def("Paste", (void (TDataStd_ByteArray::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_ByteArray::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_ByteArray.def("Dump", (Standard_OStream & (TDataStd_ByteArray::*)(Standard_OStream &) const) &TDataStd_ByteArray::Dump, "None", py::arg("OS"));
cls_TDataStd_ByteArray.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TDataStd_ByteArray::*)(const opencascade::handle<TDF_Attribute> &) const) &TDataStd_ByteArray::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute>.", py::arg("anOldAttribute"));

// CLASS: TDATASTD_EXTSTRINGARRAY
py::class_<TDataStd_ExtStringArray, opencascade::handle<TDataStd_ExtStringArray>, TDF_Attribute> cls_TDataStd_ExtStringArray(mod, "TDataStd_ExtStringArray", "ExtStringArray Attribute. Handles an array of UNICODE strings (represented by the TCollection_ExtendedString class).");

// Constructors
cls_TDataStd_ExtStringArray.def(py::init<>());

// Methods
cls_TDataStd_ExtStringArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_ExtStringArray::get_type_name, "None");
cls_TDataStd_ExtStringArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_ExtStringArray::get_type_descriptor, "None");
cls_TDataStd_ExtStringArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_ExtStringArray::*)() const) &TDataStd_ExtStringArray::DynamicType, "None");
cls_TDataStd_ExtStringArray.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_ExtStringArray::GetID, "class methods ============= Returns the GUID for the attribute.");
cls_TDataStd_ExtStringArray.def_static("Set_", [](const TDF_Label & a0, const Standard_Integer a1, const Standard_Integer a2) -> opencascade::handle<TDataStd_ExtStringArray> { return TDataStd_ExtStringArray::Set(a0, a1, a2); });
cls_TDataStd_ExtStringArray.def_static("Set_", (opencascade::handle<TDataStd_ExtStringArray> (*)(const TDF_Label &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TDataStd_ExtStringArray::Set, "Finds, or creates, an ExtStringArray attribute with <lower> and <upper> bounds on the specified label. If <isDelta> == False, DefaultDeltaOnModification is used. If <isDelta> == True, DeltaOnModification of the current attribute is used. If attribute is already set, all input parameters are refused and the found attribute is returned.", py::arg("label"), py::arg("lower"), py::arg("upper"), py::arg("isDelta"));
cls_TDataStd_ExtStringArray.def_static("Set_", [](const TDF_Label & a0, const Standard_GUID & a1, const Standard_Integer a2, const Standard_Integer a3) -> opencascade::handle<TDataStd_ExtStringArray> { return TDataStd_ExtStringArray::Set(a0, a1, a2, a3); });
cls_TDataStd_ExtStringArray.def_static("Set_", (opencascade::handle<TDataStd_ExtStringArray> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TDataStd_ExtStringArray::Set, "Finds, or creates, an ExtStringArray attribute with explicit user defined <guid>. The ExtStringArray attribute is returned.", py::arg("label"), py::arg("theGuid"), py::arg("lower"), py::arg("upper"), py::arg("isDelta"));
cls_TDataStd_ExtStringArray.def("Init", (void (TDataStd_ExtStringArray::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_ExtStringArray::Init, "Initializes the inner array with bounds from <lower> to <upper>", py::arg("lower"), py::arg("upper"));
cls_TDataStd_ExtStringArray.def("SetValue", (void (TDataStd_ExtStringArray::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TDataStd_ExtStringArray::SetValue, "Sets the <Index>th element of the array to <Value> OutOfRange exception is raised if <Index> doesn't respect Lower and Upper bounds of the internal array.", py::arg("Index"), py::arg("Value"));
cls_TDataStd_ExtStringArray.def("SetID", (void (TDataStd_ExtStringArray::*)(const Standard_GUID &)) &TDataStd_ExtStringArray::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_ExtStringArray.def("SetID", (void (TDataStd_ExtStringArray::*)()) &TDataStd_ExtStringArray::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_ExtStringArray.def("Value", (const TCollection_ExtendedString & (TDataStd_ExtStringArray::*)(const Standard_Integer) const) &TDataStd_ExtStringArray::Value, "Returns the value of the <Index>th element of the array", py::arg("Index"));
cls_TDataStd_ExtStringArray.def("__call__", (const TCollection_ExtendedString & (TDataStd_ExtStringArray::*)(const Standard_Integer) const) &TDataStd_ExtStringArray::operator(), py::is_operator(), "None", py::arg("Index"));
cls_TDataStd_ExtStringArray.def("Lower", (Standard_Integer (TDataStd_ExtStringArray::*)() const) &TDataStd_ExtStringArray::Lower, "Return the lower bound.");
cls_TDataStd_ExtStringArray.def("Upper", (Standard_Integer (TDataStd_ExtStringArray::*)() const) &TDataStd_ExtStringArray::Upper, "Return the upper bound");
cls_TDataStd_ExtStringArray.def("Length", (Standard_Integer (TDataStd_ExtStringArray::*)() const) &TDataStd_ExtStringArray::Length, "Return the number of elements of <me>.");
cls_TDataStd_ExtStringArray.def("ChangeArray", [](TDataStd_ExtStringArray &self, const opencascade::handle<TColStd_HArray1OfExtendedString> & a0) -> void { return self.ChangeArray(a0); });
cls_TDataStd_ExtStringArray.def("ChangeArray", (void (TDataStd_ExtStringArray::*)(const opencascade::handle<TColStd_HArray1OfExtendedString> &, const Standard_Boolean)) &TDataStd_ExtStringArray::ChangeArray, "Sets the inner array <myValue> of the ExtStringArray attribute to <newArray>. If value of <newArray> differs from <myValue>, Backup performed and myValue refers to new instance of HArray1OfExtendedString that holds <newArray> values If <isCheckItems> equal True each item of <newArray> will be checked with each item of <myValue> for coincidence (to avoid backup).", py::arg("newArray"), py::arg("isCheckItems"));
cls_TDataStd_ExtStringArray.def("Array", (const opencascade::handle<TColStd_HArray1OfExtendedString> & (TDataStd_ExtStringArray::*)() const) &TDataStd_ExtStringArray::Array, "Return the inner array of the ExtStringArray attribute");
cls_TDataStd_ExtStringArray.def("GetDelta", (Standard_Boolean (TDataStd_ExtStringArray::*)() const) &TDataStd_ExtStringArray::GetDelta, "None");
cls_TDataStd_ExtStringArray.def("SetDelta", (void (TDataStd_ExtStringArray::*)(const Standard_Boolean)) &TDataStd_ExtStringArray::SetDelta, "for internal use only!", py::arg("isDelta"));
cls_TDataStd_ExtStringArray.def("ID", (const Standard_GUID & (TDataStd_ExtStringArray::*)() const) &TDataStd_ExtStringArray::ID, "None");
cls_TDataStd_ExtStringArray.def("Restore", (void (TDataStd_ExtStringArray::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_ExtStringArray::Restore, "None", py::arg("With"));
cls_TDataStd_ExtStringArray.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_ExtStringArray::*)() const) &TDataStd_ExtStringArray::NewEmpty, "None");
cls_TDataStd_ExtStringArray.def("Paste", (void (TDataStd_ExtStringArray::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_ExtStringArray::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_ExtStringArray.def("Dump", (Standard_OStream & (TDataStd_ExtStringArray::*)(Standard_OStream &) const) &TDataStd_ExtStringArray::Dump, "None", py::arg("anOS"));
cls_TDataStd_ExtStringArray.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TDataStd_ExtStringArray::*)(const opencascade::handle<TDF_Attribute> &) const) &TDataStd_ExtStringArray::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute>.", py::arg("anOldAttribute"));

// CLASS: TDATASTD_BOOLEANARRAY
py::class_<TDataStd_BooleanArray, opencascade::handle<TDataStd_BooleanArray>, TDF_Attribute> cls_TDataStd_BooleanArray(mod, "TDataStd_BooleanArray", "An array of boolean values.");

// Constructors
cls_TDataStd_BooleanArray.def(py::init<>());

// Methods
cls_TDataStd_BooleanArray.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_BooleanArray::GetID, "Static methods ============== Returns an ID for array.");
cls_TDataStd_BooleanArray.def_static("Set_", (opencascade::handle<TDataStd_BooleanArray> (*)(const TDF_Label &, const Standard_Integer, const Standard_Integer)) &TDataStd_BooleanArray::Set, "Finds or creates an attribute with internal boolean array.", py::arg("label"), py::arg("lower"), py::arg("upper"));
cls_TDataStd_BooleanArray.def_static("Set_", (opencascade::handle<TDataStd_BooleanArray> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Integer, const Standard_Integer)) &TDataStd_BooleanArray::Set, "Finds or creates an attribute with the array using explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"), py::arg("lower"), py::arg("upper"));
cls_TDataStd_BooleanArray.def("Init", (void (TDataStd_BooleanArray::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_BooleanArray::Init, "Initialize the inner array with bounds from <lower> to <upper>", py::arg("lower"), py::arg("upper"));
cls_TDataStd_BooleanArray.def("SetValue", (void (TDataStd_BooleanArray::*)(const Standard_Integer, const Standard_Boolean)) &TDataStd_BooleanArray::SetValue, "Sets the <Index>th element of the array to <Value> OutOfRange exception is raised if <Index> doesn't respect Lower and Upper bounds of the internal array.", py::arg("index"), py::arg("value"));
cls_TDataStd_BooleanArray.def("SetID", (void (TDataStd_BooleanArray::*)(const Standard_GUID &)) &TDataStd_BooleanArray::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_BooleanArray.def("SetID", (void (TDataStd_BooleanArray::*)()) &TDataStd_BooleanArray::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_BooleanArray.def("Value", (Standard_Boolean (TDataStd_BooleanArray::*)(const Standard_Integer) const) &TDataStd_BooleanArray::Value, "Return the value of the <Index>th element of the array.", py::arg("Index"));
cls_TDataStd_BooleanArray.def("__call__", (Standard_Boolean (TDataStd_BooleanArray::*)(const Standard_Integer) const) &TDataStd_BooleanArray::operator(), py::is_operator(), "None", py::arg("Index"));
cls_TDataStd_BooleanArray.def("Lower", (Standard_Integer (TDataStd_BooleanArray::*)() const) &TDataStd_BooleanArray::Lower, "Returns the lower boundary of the array.");
cls_TDataStd_BooleanArray.def("Upper", (Standard_Integer (TDataStd_BooleanArray::*)() const) &TDataStd_BooleanArray::Upper, "Returns the upper boundary of the array.");
cls_TDataStd_BooleanArray.def("Length", (Standard_Integer (TDataStd_BooleanArray::*)() const) &TDataStd_BooleanArray::Length, "Returns the number of elements in the array.");
cls_TDataStd_BooleanArray.def("InternalArray", (const opencascade::handle<TColStd_HArray1OfByte> & (TDataStd_BooleanArray::*)() const) &TDataStd_BooleanArray::InternalArray, "None");
cls_TDataStd_BooleanArray.def("SetInternalArray", (void (TDataStd_BooleanArray::*)(const opencascade::handle<TColStd_HArray1OfByte> &)) &TDataStd_BooleanArray::SetInternalArray, "None", py::arg("values"));
cls_TDataStd_BooleanArray.def("ID", (const Standard_GUID & (TDataStd_BooleanArray::*)() const) &TDataStd_BooleanArray::ID, "None");
cls_TDataStd_BooleanArray.def("Restore", (void (TDataStd_BooleanArray::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_BooleanArray::Restore, "None", py::arg("with"));
cls_TDataStd_BooleanArray.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_BooleanArray::*)() const) &TDataStd_BooleanArray::NewEmpty, "None");
cls_TDataStd_BooleanArray.def("Paste", (void (TDataStd_BooleanArray::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_BooleanArray::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_BooleanArray.def("Dump", (Standard_OStream & (TDataStd_BooleanArray::*)(Standard_OStream &) const) &TDataStd_BooleanArray::Dump, "None", py::arg("OS"));
cls_TDataStd_BooleanArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_BooleanArray::get_type_name, "None");
cls_TDataStd_BooleanArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_BooleanArray::get_type_descriptor, "None");
cls_TDataStd_BooleanArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_BooleanArray::*)() const) &TDataStd_BooleanArray::DynamicType, "None");

// TYPEDEF: TDATASTD_LABELARRAY1
bind_NCollection_Array1<TDF_Label>(mod, "TDataStd_LabelArray1", py::module_local(false));

// CLASS: TDATASTD_HLABELARRAY1
py::class_<TDataStd_HLabelArray1, opencascade::handle<TDataStd_HLabelArray1>, Standard_Transient> cls_TDataStd_HLabelArray1(mod, "TDataStd_HLabelArray1", "None", py::multiple_inheritance());

// Constructors
cls_TDataStd_HLabelArray1.def(py::init<>());
cls_TDataStd_HLabelArray1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TDataStd_HLabelArray1.def(py::init<const Standard_Integer, const Standard_Integer, const TDataStd_LabelArray1::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TDataStd_HLabelArray1.def(py::init<const TDataStd_LabelArray1 &>(), py::arg("theOther"));

// Methods
// cls_TDataStd_HLabelArray1.def_static("operator new_", (void * (*)(size_t)) &TDataStd_HLabelArray1::operator new, "None", py::arg("theSize"));
// cls_TDataStd_HLabelArray1.def_static("operator delete_", (void (*)(void *)) &TDataStd_HLabelArray1::operator delete, "None", py::arg("theAddress"));
// cls_TDataStd_HLabelArray1.def_static("operator new[]_", (void * (*)(size_t)) &TDataStd_HLabelArray1::operator new[], "None", py::arg("theSize"));
// cls_TDataStd_HLabelArray1.def_static("operator delete[]_", (void (*)(void *)) &TDataStd_HLabelArray1::operator delete[], "None", py::arg("theAddress"));
// cls_TDataStd_HLabelArray1.def_static("operator new_", (void * (*)(size_t, void *)) &TDataStd_HLabelArray1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDataStd_HLabelArray1.def_static("operator delete_", (void (*)(void *, void *)) &TDataStd_HLabelArray1::operator delete, "None", py::arg(""), py::arg(""));
// cls_TDataStd_HLabelArray1.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TDataStd_HLabelArray1::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TDataStd_HLabelArray1.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TDataStd_HLabelArray1::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TDataStd_HLabelArray1.def("Array1", (const TDataStd_LabelArray1 & (TDataStd_HLabelArray1::*)() const) &TDataStd_HLabelArray1::Array1, "None");
cls_TDataStd_HLabelArray1.def("ChangeArray1", (TDataStd_LabelArray1 & (TDataStd_HLabelArray1::*)()) &TDataStd_HLabelArray1::ChangeArray1, "None");
cls_TDataStd_HLabelArray1.def_static("get_type_name_", (const char * (*)()) &TDataStd_HLabelArray1::get_type_name, "None");
cls_TDataStd_HLabelArray1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HLabelArray1::get_type_descriptor, "None");
cls_TDataStd_HLabelArray1.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HLabelArray1::*)() const) &TDataStd_HLabelArray1::DynamicType, "None");

// CLASS: TDATASTD_REFERENCEARRAY
py::class_<TDataStd_ReferenceArray, opencascade::handle<TDataStd_ReferenceArray>, TDF_Attribute> cls_TDataStd_ReferenceArray(mod, "TDataStd_ReferenceArray", "Contains an array of references to the labels.");

// Constructors
cls_TDataStd_ReferenceArray.def(py::init<>());

// Methods
cls_TDataStd_ReferenceArray.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_ReferenceArray::GetID, "Static methods ============== Returns the ID of the array of references (labels) attribute.");
cls_TDataStd_ReferenceArray.def_static("Set_", (opencascade::handle<TDataStd_ReferenceArray> (*)(const TDF_Label &, const Standard_Integer, const Standard_Integer)) &TDataStd_ReferenceArray::Set, "Finds or creates an array of reference values (labels) attribute.", py::arg("label"), py::arg("lower"), py::arg("upper"));
cls_TDataStd_ReferenceArray.def_static("Set_", (opencascade::handle<TDataStd_ReferenceArray> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Integer, const Standard_Integer)) &TDataStd_ReferenceArray::Set, "Finds or creates an array of reference values (labels) attribute with explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"), py::arg("lower"), py::arg("upper"));
cls_TDataStd_ReferenceArray.def("Init", (void (TDataStd_ReferenceArray::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_ReferenceArray::Init, "Initialize the inner array with bounds from <lower> to <upper>", py::arg("lower"), py::arg("upper"));
cls_TDataStd_ReferenceArray.def("SetValue", (void (TDataStd_ReferenceArray::*)(const Standard_Integer, const TDF_Label &)) &TDataStd_ReferenceArray::SetValue, "Sets the <Index>th element of the array to <Value> OutOfRange exception is raised if <Index> doesn't respect Lower and Upper bounds of the internal array.", py::arg("index"), py::arg("value"));
cls_TDataStd_ReferenceArray.def("SetID", (void (TDataStd_ReferenceArray::*)(const Standard_GUID &)) &TDataStd_ReferenceArray::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_ReferenceArray.def("SetID", (void (TDataStd_ReferenceArray::*)()) &TDataStd_ReferenceArray::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_ReferenceArray.def("Value", (TDF_Label (TDataStd_ReferenceArray::*)(const Standard_Integer) const) &TDataStd_ReferenceArray::Value, "Returns the value of the <Index>th element of the array.", py::arg("Index"));
cls_TDataStd_ReferenceArray.def("__call__", (TDF_Label (TDataStd_ReferenceArray::*)(const Standard_Integer) const) &TDataStd_ReferenceArray::operator(), py::is_operator(), "None", py::arg("Index"));
cls_TDataStd_ReferenceArray.def("Lower", (Standard_Integer (TDataStd_ReferenceArray::*)() const) &TDataStd_ReferenceArray::Lower, "Returns the lower boundary of the array.");
cls_TDataStd_ReferenceArray.def("Upper", (Standard_Integer (TDataStd_ReferenceArray::*)() const) &TDataStd_ReferenceArray::Upper, "Returns the upper boundary of the array.");
cls_TDataStd_ReferenceArray.def("Length", (Standard_Integer (TDataStd_ReferenceArray::*)() const) &TDataStd_ReferenceArray::Length, "Returns the number of elements in the array.");
cls_TDataStd_ReferenceArray.def("InternalArray", (const opencascade::handle<TDataStd_HLabelArray1> & (TDataStd_ReferenceArray::*)() const) &TDataStd_ReferenceArray::InternalArray, "None");
cls_TDataStd_ReferenceArray.def("SetInternalArray", [](TDataStd_ReferenceArray &self, const opencascade::handle<TDataStd_HLabelArray1> & a0) -> void { return self.SetInternalArray(a0); });
cls_TDataStd_ReferenceArray.def("SetInternalArray", (void (TDataStd_ReferenceArray::*)(const opencascade::handle<TDataStd_HLabelArray1> &, const Standard_Boolean)) &TDataStd_ReferenceArray::SetInternalArray, "None", py::arg("values"), py::arg("isCheckItems"));
cls_TDataStd_ReferenceArray.def("ID", (const Standard_GUID & (TDataStd_ReferenceArray::*)() const) &TDataStd_ReferenceArray::ID, "None");
cls_TDataStd_ReferenceArray.def("Restore", (void (TDataStd_ReferenceArray::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_ReferenceArray::Restore, "None", py::arg("With"));
cls_TDataStd_ReferenceArray.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_ReferenceArray::*)() const) &TDataStd_ReferenceArray::NewEmpty, "None");
cls_TDataStd_ReferenceArray.def("Paste", (void (TDataStd_ReferenceArray::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_ReferenceArray::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_ReferenceArray.def("References", (void (TDataStd_ReferenceArray::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_ReferenceArray::References, "None", py::arg("DS"));
cls_TDataStd_ReferenceArray.def("Dump", (Standard_OStream & (TDataStd_ReferenceArray::*)(Standard_OStream &) const) &TDataStd_ReferenceArray::Dump, "None", py::arg("anOS"));
cls_TDataStd_ReferenceArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_ReferenceArray::get_type_name, "None");
cls_TDataStd_ReferenceArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_ReferenceArray::get_type_descriptor, "None");
cls_TDataStd_ReferenceArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_ReferenceArray::*)() const) &TDataStd_ReferenceArray::DynamicType, "None");

// CLASS: TDATASTD_INTEGERLIST
py::class_<TDataStd_IntegerList, opencascade::handle<TDataStd_IntegerList>, TDF_Attribute> cls_TDataStd_IntegerList(mod, "TDataStd_IntegerList", "Contains a list of integers.");

// Constructors
cls_TDataStd_IntegerList.def(py::init<>());

// Methods
cls_TDataStd_IntegerList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_IntegerList::GetID, "Static methods ============== Returns the ID of the list of integer attribute.");
cls_TDataStd_IntegerList.def_static("Set_", (opencascade::handle<TDataStd_IntegerList> (*)(const TDF_Label &)) &TDataStd_IntegerList::Set, "Finds or creates a list of integer values attribute.", py::arg("label"));
cls_TDataStd_IntegerList.def_static("Set_", (opencascade::handle<TDataStd_IntegerList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_IntegerList::Set, "Finds or creates a list of integer values attribute with explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_IntegerList.def("IsEmpty", (Standard_Boolean (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::IsEmpty, "None");
cls_TDataStd_IntegerList.def("Extent", (Standard_Integer (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::Extent, "None");
cls_TDataStd_IntegerList.def("Prepend", (void (TDataStd_IntegerList::*)(const Standard_Integer)) &TDataStd_IntegerList::Prepend, "None", py::arg("value"));
cls_TDataStd_IntegerList.def("Append", (void (TDataStd_IntegerList::*)(const Standard_Integer)) &TDataStd_IntegerList::Append, "None", py::arg("value"));
cls_TDataStd_IntegerList.def("SetID", (void (TDataStd_IntegerList::*)(const Standard_GUID &)) &TDataStd_IntegerList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_IntegerList.def("SetID", (void (TDataStd_IntegerList::*)()) &TDataStd_IntegerList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_IntegerList.def("InsertBefore", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerList::InsertBefore, "Inserts the <value> before the first meet of <before_value>.", py::arg("value"), py::arg("before_value"));
cls_TDataStd_IntegerList.def("InsertBeforeByIndex", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerList::InsertBeforeByIndex, "Inserts the <value> before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_IntegerList.def("InsertAfter", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerList::InsertAfter, "Inserts the <value> after the first meet of <after_value>.", py::arg("value"), py::arg("after_value"));
cls_TDataStd_IntegerList.def("InsertAfterByIndex", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer, const Standard_Integer)) &TDataStd_IntegerList::InsertAfterByIndex, "Inserts the <value> after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_IntegerList.def("Remove", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer)) &TDataStd_IntegerList::Remove, "Removes the first meet of the <value>.", py::arg("value"));
cls_TDataStd_IntegerList.def("RemoveByIndex", (Standard_Boolean (TDataStd_IntegerList::*)(const Standard_Integer)) &TDataStd_IntegerList::RemoveByIndex, "Removes a value at <index> position.", py::arg("index"));
cls_TDataStd_IntegerList.def("Clear", (void (TDataStd_IntegerList::*)()) &TDataStd_IntegerList::Clear, "None");
cls_TDataStd_IntegerList.def("First", (Standard_Integer (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::First, "None");
cls_TDataStd_IntegerList.def("Last", (Standard_Integer (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::Last, "None");
cls_TDataStd_IntegerList.def("List", (const TColStd_ListOfInteger & (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::List, "None");
cls_TDataStd_IntegerList.def("ID", (const Standard_GUID & (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::ID, "None");
cls_TDataStd_IntegerList.def("Restore", (void (TDataStd_IntegerList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_IntegerList::Restore, "None", py::arg("With"));
cls_TDataStd_IntegerList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::NewEmpty, "None");
cls_TDataStd_IntegerList.def("Paste", (void (TDataStd_IntegerList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_IntegerList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_IntegerList.def("Dump", (Standard_OStream & (TDataStd_IntegerList::*)(Standard_OStream &) const) &TDataStd_IntegerList::Dump, "None", py::arg("anOS"));
cls_TDataStd_IntegerList.def_static("get_type_name_", (const char * (*)()) &TDataStd_IntegerList::get_type_name, "None");
cls_TDataStd_IntegerList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_IntegerList::get_type_descriptor, "None");
cls_TDataStd_IntegerList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_IntegerList::*)() const) &TDataStd_IntegerList::DynamicType, "None");

// CLASS: TDATASTD_REALLIST
py::class_<TDataStd_RealList, opencascade::handle<TDataStd_RealList>, TDF_Attribute> cls_TDataStd_RealList(mod, "TDataStd_RealList", "Contains a list of doubles.");

// Constructors
cls_TDataStd_RealList.def(py::init<>());

// Methods
cls_TDataStd_RealList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_RealList::GetID, "Static methods ============== Returns the ID of the list of doubles attribute.");
cls_TDataStd_RealList.def_static("Set_", (opencascade::handle<TDataStd_RealList> (*)(const TDF_Label &)) &TDataStd_RealList::Set, "Finds or creates a list of double values attribute.", py::arg("label"));
cls_TDataStd_RealList.def_static("Set_", (opencascade::handle<TDataStd_RealList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_RealList::Set, "Finds or creates a list of double values attribute with explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_RealList.def("IsEmpty", (Standard_Boolean (TDataStd_RealList::*)() const) &TDataStd_RealList::IsEmpty, "None");
cls_TDataStd_RealList.def("Extent", (Standard_Integer (TDataStd_RealList::*)() const) &TDataStd_RealList::Extent, "None");
cls_TDataStd_RealList.def("Prepend", (void (TDataStd_RealList::*)(const Standard_Real)) &TDataStd_RealList::Prepend, "None", py::arg("value"));
cls_TDataStd_RealList.def("Append", (void (TDataStd_RealList::*)(const Standard_Real)) &TDataStd_RealList::Append, "None", py::arg("value"));
cls_TDataStd_RealList.def("SetID", (void (TDataStd_RealList::*)(const Standard_GUID &)) &TDataStd_RealList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_RealList.def("SetID", (void (TDataStd_RealList::*)()) &TDataStd_RealList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_RealList.def("InsertBefore", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Real, const Standard_Real)) &TDataStd_RealList::InsertBefore, "Inserts the <value> before the first meet of <before_value>.", py::arg("value"), py::arg("before_value"));
cls_TDataStd_RealList.def("InsertBeforeByIndex", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Integer, const Standard_Real)) &TDataStd_RealList::InsertBeforeByIndex, "Inserts the <value> before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_RealList.def("InsertAfter", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Real, const Standard_Real)) &TDataStd_RealList::InsertAfter, "Inserts the <value> after the first meet of <after_value>.", py::arg("value"), py::arg("after_value"));
cls_TDataStd_RealList.def("InsertAfterByIndex", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Integer, const Standard_Real)) &TDataStd_RealList::InsertAfterByIndex, "Inserts the <value> after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_RealList.def("Remove", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Real)) &TDataStd_RealList::Remove, "Removes the first meet of the <value>.", py::arg("value"));
cls_TDataStd_RealList.def("RemoveByIndex", (Standard_Boolean (TDataStd_RealList::*)(const Standard_Integer)) &TDataStd_RealList::RemoveByIndex, "Removes a value at <index> position.", py::arg("index"));
cls_TDataStd_RealList.def("Clear", (void (TDataStd_RealList::*)()) &TDataStd_RealList::Clear, "None");
cls_TDataStd_RealList.def("First", (Standard_Real (TDataStd_RealList::*)() const) &TDataStd_RealList::First, "None");
cls_TDataStd_RealList.def("Last", (Standard_Real (TDataStd_RealList::*)() const) &TDataStd_RealList::Last, "None");
cls_TDataStd_RealList.def("List", (const TColStd_ListOfReal & (TDataStd_RealList::*)() const) &TDataStd_RealList::List, "None");
cls_TDataStd_RealList.def("ID", (const Standard_GUID & (TDataStd_RealList::*)() const) &TDataStd_RealList::ID, "None");
cls_TDataStd_RealList.def("Restore", (void (TDataStd_RealList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_RealList::Restore, "None", py::arg("With"));
cls_TDataStd_RealList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_RealList::*)() const) &TDataStd_RealList::NewEmpty, "None");
cls_TDataStd_RealList.def("Paste", (void (TDataStd_RealList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_RealList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_RealList.def("Dump", (Standard_OStream & (TDataStd_RealList::*)(Standard_OStream &) const) &TDataStd_RealList::Dump, "None", py::arg("anOS"));
cls_TDataStd_RealList.def_static("get_type_name_", (const char * (*)()) &TDataStd_RealList::get_type_name, "None");
cls_TDataStd_RealList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_RealList::get_type_descriptor, "None");
cls_TDataStd_RealList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_RealList::*)() const) &TDataStd_RealList::DynamicType, "None");

// TYPEDEF: TDATASTD_LISTOFEXTENDEDSTRING
bind_NCollection_List<TCollection_ExtendedString>(mod, "TDataStd_ListOfExtendedString", py::module_local(false));

// TYPEDEF: TDATASTD_LISTITERATOROFLISTOFEXTENDEDSTRING
bind_NCollection_TListIterator<TCollection_ExtendedString>(mod, "TDataStd_ListIteratorOfListOfExtendedString", py::module_local(false));

// CLASS: TDATASTD_EXTSTRINGLIST
py::class_<TDataStd_ExtStringList, opencascade::handle<TDataStd_ExtStringList>, TDF_Attribute> cls_TDataStd_ExtStringList(mod, "TDataStd_ExtStringList", "Contains a list of ExtendedString.");

// Constructors
cls_TDataStd_ExtStringList.def(py::init<>());

// Methods
cls_TDataStd_ExtStringList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_ExtStringList::GetID, "Static methods ============== Returns the ID of the list of strings attribute.");
cls_TDataStd_ExtStringList.def_static("Set_", (opencascade::handle<TDataStd_ExtStringList> (*)(const TDF_Label &)) &TDataStd_ExtStringList::Set, "Finds or creates a list of string values attribute with explicit user defined <guid>.", py::arg("label"));
cls_TDataStd_ExtStringList.def_static("Set_", (opencascade::handle<TDataStd_ExtStringList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_ExtStringList::Set, "Finds or creates a list of string values attribute.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_ExtStringList.def("IsEmpty", (Standard_Boolean (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::IsEmpty, "None");
cls_TDataStd_ExtStringList.def("Extent", (Standard_Integer (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::Extent, "None");
cls_TDataStd_ExtStringList.def("Prepend", (void (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &)) &TDataStd_ExtStringList::Prepend, "None", py::arg("value"));
cls_TDataStd_ExtStringList.def("Append", (void (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &)) &TDataStd_ExtStringList::Append, "None", py::arg("value"));
cls_TDataStd_ExtStringList.def("SetID", (void (TDataStd_ExtStringList::*)(const Standard_GUID &)) &TDataStd_ExtStringList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_ExtStringList.def("SetID", (void (TDataStd_ExtStringList::*)()) &TDataStd_ExtStringList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_ExtStringList.def("InsertBefore", (Standard_Boolean (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &TDataStd_ExtStringList::InsertBefore, "Inserts the <value> before the first meet of <before_value>.", py::arg("value"), py::arg("before_value"));
cls_TDataStd_ExtStringList.def("InsertBefore", (Standard_Boolean (TDataStd_ExtStringList::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TDataStd_ExtStringList::InsertBefore, "Inserts the <value> before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_ExtStringList.def("InsertAfter", (Standard_Boolean (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &TDataStd_ExtStringList::InsertAfter, "Inserts the <value> after the first meet of <after_value>.", py::arg("value"), py::arg("after_value"));
cls_TDataStd_ExtStringList.def("InsertAfter", (Standard_Boolean (TDataStd_ExtStringList::*)(const Standard_Integer, const TCollection_ExtendedString &)) &TDataStd_ExtStringList::InsertAfter, "Inserts the <value> after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_ExtStringList.def("Remove", (Standard_Boolean (TDataStd_ExtStringList::*)(const TCollection_ExtendedString &)) &TDataStd_ExtStringList::Remove, "Removes the first meet of the <value>.", py::arg("value"));
cls_TDataStd_ExtStringList.def("Remove", (Standard_Boolean (TDataStd_ExtStringList::*)(const Standard_Integer)) &TDataStd_ExtStringList::Remove, "Removes a value at <index> position.", py::arg("index"));
cls_TDataStd_ExtStringList.def("Clear", (void (TDataStd_ExtStringList::*)()) &TDataStd_ExtStringList::Clear, "None");
cls_TDataStd_ExtStringList.def("First", (const TCollection_ExtendedString & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::First, "None");
cls_TDataStd_ExtStringList.def("Last", (const TCollection_ExtendedString & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::Last, "None");
cls_TDataStd_ExtStringList.def("List", (const TDataStd_ListOfExtendedString & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::List, "None");
cls_TDataStd_ExtStringList.def("ID", (const Standard_GUID & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::ID, "None");
cls_TDataStd_ExtStringList.def("Restore", (void (TDataStd_ExtStringList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_ExtStringList::Restore, "None", py::arg("With"));
cls_TDataStd_ExtStringList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::NewEmpty, "None");
cls_TDataStd_ExtStringList.def("Paste", (void (TDataStd_ExtStringList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_ExtStringList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_ExtStringList.def("Dump", (Standard_OStream & (TDataStd_ExtStringList::*)(Standard_OStream &) const) &TDataStd_ExtStringList::Dump, "None", py::arg("anOS"));
cls_TDataStd_ExtStringList.def_static("get_type_name_", (const char * (*)()) &TDataStd_ExtStringList::get_type_name, "None");
cls_TDataStd_ExtStringList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_ExtStringList::get_type_descriptor, "None");
cls_TDataStd_ExtStringList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_ExtStringList::*)() const) &TDataStd_ExtStringList::DynamicType, "None");

// TYPEDEF: TDATASTD_LISTOFBYTE
bind_NCollection_List<unsigned char>(mod, "TDataStd_ListOfByte", py::module_local(false));

// TYPEDEF: TDATASTD_LISTITERATOROFLISTOFBYTE
bind_NCollection_TListIterator<unsigned char>(mod, "TDataStd_ListIteratorOfListOfByte", py::module_local(false));

// CLASS: TDATASTD_BOOLEANLIST
py::class_<TDataStd_BooleanList, opencascade::handle<TDataStd_BooleanList>, TDF_Attribute> cls_TDataStd_BooleanList(mod, "TDataStd_BooleanList", "Contains a list of bolleans.");

// Constructors
cls_TDataStd_BooleanList.def(py::init<>());

// Methods
cls_TDataStd_BooleanList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_BooleanList::GetID, "Static methods ============== Returns the ID of the list of booleans attribute.");
cls_TDataStd_BooleanList.def_static("Set_", (opencascade::handle<TDataStd_BooleanList> (*)(const TDF_Label &)) &TDataStd_BooleanList::Set, "Finds or creates a list of boolean values attribute.", py::arg("label"));
cls_TDataStd_BooleanList.def_static("Set_", (opencascade::handle<TDataStd_BooleanList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_BooleanList::Set, "Finds or creates a list of boolean values attribute with explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_BooleanList.def("IsEmpty", (Standard_Boolean (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::IsEmpty, "None");
cls_TDataStd_BooleanList.def("Extent", (Standard_Integer (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::Extent, "None");
cls_TDataStd_BooleanList.def("Prepend", (void (TDataStd_BooleanList::*)(const Standard_Boolean)) &TDataStd_BooleanList::Prepend, "None", py::arg("value"));
cls_TDataStd_BooleanList.def("Append", (void (TDataStd_BooleanList::*)(const Standard_Boolean)) &TDataStd_BooleanList::Append, "None", py::arg("value"));
cls_TDataStd_BooleanList.def("Clear", (void (TDataStd_BooleanList::*)()) &TDataStd_BooleanList::Clear, "None");
cls_TDataStd_BooleanList.def("First", (Standard_Boolean (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::First, "None");
cls_TDataStd_BooleanList.def("Last", (Standard_Boolean (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::Last, "None");
cls_TDataStd_BooleanList.def("List", (const TDataStd_ListOfByte & (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::List, "1 - means TRUE, 0 - means FALSE.");
cls_TDataStd_BooleanList.def("InsertBefore", (Standard_Boolean (TDataStd_BooleanList::*)(const Standard_Integer, const Standard_Boolean)) &TDataStd_BooleanList::InsertBefore, "Inserts the <value> before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_BooleanList.def("InsertAfter", (Standard_Boolean (TDataStd_BooleanList::*)(const Standard_Integer, const Standard_Boolean)) &TDataStd_BooleanList::InsertAfter, "Inserts the <value> after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_BooleanList.def("Remove", (Standard_Boolean (TDataStd_BooleanList::*)(const Standard_Integer)) &TDataStd_BooleanList::Remove, "Removes a value at <index> position.", py::arg("index"));
cls_TDataStd_BooleanList.def("SetID", (void (TDataStd_BooleanList::*)(const Standard_GUID &)) &TDataStd_BooleanList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_BooleanList.def("SetID", (void (TDataStd_BooleanList::*)()) &TDataStd_BooleanList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_BooleanList.def("ID", (const Standard_GUID & (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::ID, "None");
cls_TDataStd_BooleanList.def("Restore", (void (TDataStd_BooleanList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_BooleanList::Restore, "None", py::arg("With"));
cls_TDataStd_BooleanList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::NewEmpty, "None");
cls_TDataStd_BooleanList.def("Paste", (void (TDataStd_BooleanList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_BooleanList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_BooleanList.def("Dump", (Standard_OStream & (TDataStd_BooleanList::*)(Standard_OStream &) const) &TDataStd_BooleanList::Dump, "None", py::arg("anOS"));
cls_TDataStd_BooleanList.def_static("get_type_name_", (const char * (*)()) &TDataStd_BooleanList::get_type_name, "None");
cls_TDataStd_BooleanList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_BooleanList::get_type_descriptor, "None");
cls_TDataStd_BooleanList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_BooleanList::*)() const) &TDataStd_BooleanList::DynamicType, "None");

// CLASS: TDATASTD_REFERENCELIST
py::class_<TDataStd_ReferenceList, opencascade::handle<TDataStd_ReferenceList>, TDF_Attribute> cls_TDataStd_ReferenceList(mod, "TDataStd_ReferenceList", "Contains a list of references.");

// Constructors
cls_TDataStd_ReferenceList.def(py::init<>());

// Methods
cls_TDataStd_ReferenceList.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_ReferenceList::GetID, "Static methods ============== Returns the ID of the list of references (labels) attribute.");
cls_TDataStd_ReferenceList.def_static("Set_", (opencascade::handle<TDataStd_ReferenceList> (*)(const TDF_Label &)) &TDataStd_ReferenceList::Set, "Finds or creates a list of reference values (labels) attribute.", py::arg("label"));
cls_TDataStd_ReferenceList.def_static("Set_", (opencascade::handle<TDataStd_ReferenceList> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_ReferenceList::Set, "Finds or creates a list of reference values (labels) attribute with explicit user defined <guid>.", py::arg("label"), py::arg("theGuid"));
cls_TDataStd_ReferenceList.def("IsEmpty", (Standard_Boolean (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::IsEmpty, "None");
cls_TDataStd_ReferenceList.def("Extent", (Standard_Integer (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::Extent, "None");
cls_TDataStd_ReferenceList.def("Prepend", (void (TDataStd_ReferenceList::*)(const TDF_Label &)) &TDataStd_ReferenceList::Prepend, "None", py::arg("value"));
cls_TDataStd_ReferenceList.def("Append", (void (TDataStd_ReferenceList::*)(const TDF_Label &)) &TDataStd_ReferenceList::Append, "None", py::arg("value"));
cls_TDataStd_ReferenceList.def("SetID", (void (TDataStd_ReferenceList::*)(const Standard_GUID &)) &TDataStd_ReferenceList::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("theGuid"));
cls_TDataStd_ReferenceList.def("SetID", (void (TDataStd_ReferenceList::*)()) &TDataStd_ReferenceList::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_ReferenceList.def("InsertBefore", (Standard_Boolean (TDataStd_ReferenceList::*)(const TDF_Label &, const TDF_Label &)) &TDataStd_ReferenceList::InsertBefore, "Inserts the <value> before the first meet of <before_value>.", py::arg("value"), py::arg("before_value"));
cls_TDataStd_ReferenceList.def("InsertBefore", (Standard_Boolean (TDataStd_ReferenceList::*)(const Standard_Integer, const TDF_Label &)) &TDataStd_ReferenceList::InsertBefore, "Inserts the label before the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("before_value"));
cls_TDataStd_ReferenceList.def("InsertAfter", (Standard_Boolean (TDataStd_ReferenceList::*)(const TDF_Label &, const TDF_Label &)) &TDataStd_ReferenceList::InsertAfter, "Inserts the <value> after the first meet of <after_value>.", py::arg("value"), py::arg("after_value"));
cls_TDataStd_ReferenceList.def("InsertAfter", (Standard_Boolean (TDataStd_ReferenceList::*)(const Standard_Integer, const TDF_Label &)) &TDataStd_ReferenceList::InsertAfter, "Inserts the label after the <index> position. The indices start with 1 .. Extent().", py::arg("index"), py::arg("after_value"));
cls_TDataStd_ReferenceList.def("Remove", (Standard_Boolean (TDataStd_ReferenceList::*)(const TDF_Label &)) &TDataStd_ReferenceList::Remove, "Removes the first meet of the <value>.", py::arg("value"));
cls_TDataStd_ReferenceList.def("Remove", (Standard_Boolean (TDataStd_ReferenceList::*)(const Standard_Integer)) &TDataStd_ReferenceList::Remove, "Removes a label at 'index' position.", py::arg("index"));
cls_TDataStd_ReferenceList.def("Clear", (void (TDataStd_ReferenceList::*)()) &TDataStd_ReferenceList::Clear, "None");
cls_TDataStd_ReferenceList.def("First", (const TDF_Label & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::First, "None");
cls_TDataStd_ReferenceList.def("Last", (const TDF_Label & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::Last, "None");
cls_TDataStd_ReferenceList.def("List", (const TDF_LabelList & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::List, "None");
cls_TDataStd_ReferenceList.def("ID", (const Standard_GUID & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::ID, "None");
cls_TDataStd_ReferenceList.def("Restore", (void (TDataStd_ReferenceList::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_ReferenceList::Restore, "None", py::arg("With"));
cls_TDataStd_ReferenceList.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::NewEmpty, "None");
cls_TDataStd_ReferenceList.def("Paste", (void (TDataStd_ReferenceList::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_ReferenceList::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_ReferenceList.def("References", (void (TDataStd_ReferenceList::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_ReferenceList::References, "None", py::arg("DS"));
cls_TDataStd_ReferenceList.def("Dump", (Standard_OStream & (TDataStd_ReferenceList::*)(Standard_OStream &) const) &TDataStd_ReferenceList::Dump, "None", py::arg("anOS"));
cls_TDataStd_ReferenceList.def_static("get_type_name_", (const char * (*)()) &TDataStd_ReferenceList::get_type_name, "None");
cls_TDataStd_ReferenceList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_ReferenceList::get_type_descriptor, "None");
cls_TDataStd_ReferenceList.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_ReferenceList::*)() const) &TDataStd_ReferenceList::DynamicType, "None");

// CLASS: TDATASTD_INTPACKEDMAP
py::class_<TDataStd_IntPackedMap, opencascade::handle<TDataStd_IntPackedMap>, TDF_Attribute> cls_TDataStd_IntPackedMap(mod, "TDataStd_IntPackedMap", "Attribute for storing TColStd_PackedMapOfInteger");

// Constructors
cls_TDataStd_IntPackedMap.def(py::init<>());

// Methods
cls_TDataStd_IntPackedMap.def_static("get_type_name_", (const char * (*)()) &TDataStd_IntPackedMap::get_type_name, "None");
cls_TDataStd_IntPackedMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_IntPackedMap::get_type_descriptor, "None");
cls_TDataStd_IntPackedMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::DynamicType, "None");
cls_TDataStd_IntPackedMap.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_IntPackedMap::GetID, "class methods ============= Returns the GUID of the attribute.");
cls_TDataStd_IntPackedMap.def_static("Set_", [](const TDF_Label & a0) -> opencascade::handle<TDataStd_IntPackedMap> { return TDataStd_IntPackedMap::Set(a0); });
cls_TDataStd_IntPackedMap.def_static("Set_", (opencascade::handle<TDataStd_IntPackedMap> (*)(const TDF_Label &, const Standard_Boolean)) &TDataStd_IntPackedMap::Set, "Finds or creates an integer map attribute on the given label. If <isDelta> == False, DefaultDeltaOnModification is used. If <isDelta> == True, DeltaOnModification of the current attribute is used. If attribute is already set, input parameter <isDelta> is refused and the found attribute returned. Attribute methods ===================", py::arg("label"), py::arg("isDelta"));
cls_TDataStd_IntPackedMap.def("ChangeMap", (Standard_Boolean (TDataStd_IntPackedMap::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &TDataStd_IntPackedMap::ChangeMap, "None", py::arg("theMap"));
cls_TDataStd_IntPackedMap.def("ChangeMap", (Standard_Boolean (TDataStd_IntPackedMap::*)(const TColStd_PackedMapOfInteger &)) &TDataStd_IntPackedMap::ChangeMap, "None", py::arg("theMap"));
cls_TDataStd_IntPackedMap.def("GetMap", (const TColStd_PackedMapOfInteger & (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::GetMap, "None");
cls_TDataStd_IntPackedMap.def("GetHMap", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::GetHMap, "None");
cls_TDataStd_IntPackedMap.def("Clear", (Standard_Boolean (TDataStd_IntPackedMap::*)()) &TDataStd_IntPackedMap::Clear, "None");
cls_TDataStd_IntPackedMap.def("Add", (Standard_Boolean (TDataStd_IntPackedMap::*)(const Standard_Integer)) &TDataStd_IntPackedMap::Add, "None", py::arg("theKey"));
cls_TDataStd_IntPackedMap.def("Remove", (Standard_Boolean (TDataStd_IntPackedMap::*)(const Standard_Integer)) &TDataStd_IntPackedMap::Remove, "None", py::arg("theKey"));
cls_TDataStd_IntPackedMap.def("Contains", (Standard_Boolean (TDataStd_IntPackedMap::*)(const Standard_Integer) const) &TDataStd_IntPackedMap::Contains, "None", py::arg("theKey"));
cls_TDataStd_IntPackedMap.def("Extent", (Standard_Integer (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::Extent, "None");
cls_TDataStd_IntPackedMap.def("IsEmpty", (Standard_Boolean (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::IsEmpty, "None");
cls_TDataStd_IntPackedMap.def("GetDelta", (Standard_Boolean (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::GetDelta, "None");
cls_TDataStd_IntPackedMap.def("SetDelta", (void (TDataStd_IntPackedMap::*)(const Standard_Boolean)) &TDataStd_IntPackedMap::SetDelta, "for internal use only!", py::arg("isDelta"));
cls_TDataStd_IntPackedMap.def("ID", (const Standard_GUID & (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::ID, "None");
cls_TDataStd_IntPackedMap.def("Restore", (void (TDataStd_IntPackedMap::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_IntPackedMap::Restore, "None", py::arg("with"));
cls_TDataStd_IntPackedMap.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_IntPackedMap::*)() const) &TDataStd_IntPackedMap::NewEmpty, "None");
cls_TDataStd_IntPackedMap.def("Paste", (void (TDataStd_IntPackedMap::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_IntPackedMap::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_IntPackedMap.def("Dump", (Standard_OStream & (TDataStd_IntPackedMap::*)(Standard_OStream &) const) &TDataStd_IntPackedMap::Dump, "None", py::arg("anOS"));
cls_TDataStd_IntPackedMap.def("DeltaOnModification", (opencascade::handle<TDF_DeltaOnModification> (TDataStd_IntPackedMap::*)(const opencascade::handle<TDF_Attribute> &) const) &TDataStd_IntPackedMap::DeltaOnModification, "Makes a DeltaOnModification between <me> and <anOldAttribute>.", py::arg("anOldAttribute"));

// CLASS: TDATASTD_EXPRESSION
py::class_<TDataStd_Expression, opencascade::handle<TDataStd_Expression>, TDF_Attribute> cls_TDataStd_Expression(mod, "TDataStd_Expression", "Expression attribute. ====================");

// Constructors
cls_TDataStd_Expression.def(py::init<>());

// Methods
cls_TDataStd_Expression.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Expression::GetID, "class methods =============");
cls_TDataStd_Expression.def_static("Set_", (opencascade::handle<TDataStd_Expression> (*)(const TDF_Label &)) &TDataStd_Expression::Set, "Find, or create, an Expression attribute. Expressionmethods ============", py::arg("label"));
cls_TDataStd_Expression.def("Name", (TCollection_ExtendedString (TDataStd_Expression::*)() const) &TDataStd_Expression::Name, "build and return the expression name");
cls_TDataStd_Expression.def("SetExpression", (void (TDataStd_Expression::*)(const TCollection_ExtendedString &)) &TDataStd_Expression::SetExpression, "None", py::arg("E"));
cls_TDataStd_Expression.def("GetExpression", (const TCollection_ExtendedString & (TDataStd_Expression::*)() const) &TDataStd_Expression::GetExpression, "None");
cls_TDataStd_Expression.def("GetVariables", (TDF_AttributeList & (TDataStd_Expression::*)()) &TDataStd_Expression::GetVariables, "None");
cls_TDataStd_Expression.def("ID", (const Standard_GUID & (TDataStd_Expression::*)() const) &TDataStd_Expression::ID, "None");
cls_TDataStd_Expression.def("Restore", (void (TDataStd_Expression::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Expression::Restore, "None", py::arg("With"));
cls_TDataStd_Expression.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Expression::*)() const) &TDataStd_Expression::NewEmpty, "None");
cls_TDataStd_Expression.def("Paste", (void (TDataStd_Expression::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Expression::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Expression.def("Dump", (Standard_OStream & (TDataStd_Expression::*)(Standard_OStream &) const) &TDataStd_Expression::Dump, "None", py::arg("anOS"));
cls_TDataStd_Expression.def_static("get_type_name_", (const char * (*)()) &TDataStd_Expression::get_type_name, "None");
cls_TDataStd_Expression.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Expression::get_type_descriptor, "None");
cls_TDataStd_Expression.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Expression::*)() const) &TDataStd_Expression::DynamicType, "None");

// CLASS: TDATASTD_RELATION
py::class_<TDataStd_Relation, opencascade::handle<TDataStd_Relation>, TDF_Attribute> cls_TDataStd_Relation(mod, "TDataStd_Relation", "Relation attribute. ==================");

// Constructors
cls_TDataStd_Relation.def(py::init<>());

// Methods
cls_TDataStd_Relation.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Relation::GetID, "class methods =============");
cls_TDataStd_Relation.def_static("Set_", (opencascade::handle<TDataStd_Relation> (*)(const TDF_Label &)) &TDataStd_Relation::Set, "Find, or create, an Relation attribute. Real methods ============", py::arg("label"));
cls_TDataStd_Relation.def("Name", (TCollection_ExtendedString (TDataStd_Relation::*)() const) &TDataStd_Relation::Name, "build and return the relation name");
cls_TDataStd_Relation.def("SetRelation", (void (TDataStd_Relation::*)(const TCollection_ExtendedString &)) &TDataStd_Relation::SetRelation, "None", py::arg("E"));
cls_TDataStd_Relation.def("GetRelation", (const TCollection_ExtendedString & (TDataStd_Relation::*)() const) &TDataStd_Relation::GetRelation, "None");
cls_TDataStd_Relation.def("GetVariables", (TDF_AttributeList & (TDataStd_Relation::*)()) &TDataStd_Relation::GetVariables, "None");
cls_TDataStd_Relation.def("ID", (const Standard_GUID & (TDataStd_Relation::*)() const) &TDataStd_Relation::ID, "None");
cls_TDataStd_Relation.def("Restore", (void (TDataStd_Relation::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Relation::Restore, "None", py::arg("With"));
cls_TDataStd_Relation.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Relation::*)() const) &TDataStd_Relation::NewEmpty, "None");
cls_TDataStd_Relation.def("Paste", (void (TDataStd_Relation::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Relation::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Relation.def("Dump", (Standard_OStream & (TDataStd_Relation::*)(Standard_OStream &) const) &TDataStd_Relation::Dump, "None", py::arg("anOS"));
cls_TDataStd_Relation.def_static("get_type_name_", (const char * (*)()) &TDataStd_Relation::get_type_name, "None");
cls_TDataStd_Relation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Relation::get_type_descriptor, "None");
cls_TDataStd_Relation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Relation::*)() const) &TDataStd_Relation::DynamicType, "None");

// TYPEDEF: TDATASTD_DATAMAPOFSTRINGREAL
bind_NCollection_DataMap<TCollection_ExtendedString, double, TCollection_ExtendedString>(mod, "TDataStd_DataMapOfStringReal", py::module_local(false));

// TYPEDEF: TDATASTD_DATAMAPITERATOROFDATAMAPOFSTRINGREAL

// TYPEDEF: TDATASTD_DATAMAPOFSTRINGSTRING
bind_NCollection_DataMap<TCollection_ExtendedString, TCollection_ExtendedString, TCollection_ExtendedString>(mod, "TDataStd_DataMapOfStringString", py::module_local(false));

// TYPEDEF: TDATASTD_DATAMAPITERATOROFDATAMAPOFSTRINGSTRING

// TYPEDEF: TDATASTD_DATAMAPOFSTRINGBYTE
bind_NCollection_DataMap<TCollection_ExtendedString, unsigned char, TCollection_ExtendedString>(mod, "TDataStd_DataMapOfStringByte", py::module_local(false));

// TYPEDEF: TDATASTD_DATAMAPITERATOROFDATAMAPOFSTRINGBYTE

// TYPEDEF: TDATASTD_DATAMAPOFSTRINGHARRAY1OFINTEGER
bind_NCollection_DataMap<TCollection_ExtendedString, opencascade::handle<TColStd_HArray1OfInteger>, TCollection_ExtendedString>(mod, "TDataStd_DataMapOfStringHArray1OfInteger", py::module_local(false));

// TYPEDEF: TDATASTD_DATAMAPITERATOROFDATAMAPOFSTRINGHARRAY1OFINTEGER

// TYPEDEF: TDATASTD_DATAMAPOFSTRINGHARRAY1OFREAL
bind_NCollection_DataMap<TCollection_ExtendedString, opencascade::handle<TColStd_HArray1OfReal>, TCollection_ExtendedString>(mod, "TDataStd_DataMapOfStringHArray1OfReal", py::module_local(false));

// TYPEDEF: TDATASTD_DATAMAPITERATOROFDATAMAPOFSTRINGHARRAY1OFREAL

// CLASS: TDATASTD_NAMEDDATA
py::class_<TDataStd_NamedData, opencascade::handle<TDataStd_NamedData>, TDF_Attribute> cls_TDataStd_NamedData(mod, "TDataStd_NamedData", "Contains a named data.");

// Constructors
cls_TDataStd_NamedData.def(py::init<>());

// Methods
cls_TDataStd_NamedData.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_NamedData::GetID, "Static methods ============== Returns the ID of the named data attribute.");
cls_TDataStd_NamedData.def_static("Set_", (opencascade::handle<TDataStd_NamedData> (*)(const TDF_Label &)) &TDataStd_NamedData::Set, "Finds or creates a named data attribute.", py::arg("label"));
cls_TDataStd_NamedData.def("HasIntegers", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasIntegers, "Returns true if at least one named integer value is kept in the attribute.");
cls_TDataStd_NamedData.def("HasInteger", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasInteger, "Returns true if the attribute contains specified by Name integer value.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetInteger", (Standard_Integer (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetInteger, "Returns the integer value specified by the Name. It returns 0 if internal map doesn't contain the specified integer (use HasInteger() to check before).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetInteger", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const Standard_Integer)) &TDataStd_NamedData::SetInteger, "Defines a named integer. If the integer already exists, it changes its value to <theInteger>.", py::arg("theName"), py::arg("theInteger"));
cls_TDataStd_NamedData.def("GetIntegersContainer", (const TColStd_DataMapOfStringInteger & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetIntegersContainer, "Returns the internal container of named integers.");
cls_TDataStd_NamedData.def("ChangeIntegers", (void (TDataStd_NamedData::*)(const TColStd_DataMapOfStringInteger &)) &TDataStd_NamedData::ChangeIntegers, "Replace the container content by new content of the <theIntegers>.", py::arg("theIntegers"));
cls_TDataStd_NamedData.def("HasReals", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasReals, "Returns true if at least one named real value is kept in the attribute.");
cls_TDataStd_NamedData.def("HasReal", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasReal, "Returns true if the attribute contains a real specified by Name.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetReal", (Standard_Real (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetReal, "Returns the named real. It returns 0.0 if there is no such a named real (use HasReal()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetReal", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const Standard_Real)) &TDataStd_NamedData::SetReal, "Defines a named real. If the real already exists, it changes its value to <theReal>.", py::arg("theName"), py::arg("theReal"));
cls_TDataStd_NamedData.def("GetRealsContainer", (const TDataStd_DataMapOfStringReal & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetRealsContainer, "Returns the internal container of named reals.");
cls_TDataStd_NamedData.def("ChangeReals", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringReal &)) &TDataStd_NamedData::ChangeReals, "Replace the container content by new content of the <theReals>.", py::arg("theReals"));
cls_TDataStd_NamedData.def("HasStrings", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasStrings, "Returns true if there are some named strings in the attribute.");
cls_TDataStd_NamedData.def("HasString", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasString, "Returns true if the attribute contains this named string.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetString", (const TCollection_ExtendedString & (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetString, "Returns the named string. It returns an empty string if there is no such a named string (use HasString()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetString", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &TDataStd_NamedData::SetString, "Defines a named string. If the string already exists, it changes its value to <theString>.", py::arg("theName"), py::arg("theString"));
cls_TDataStd_NamedData.def("GetStringsContainer", (const TDataStd_DataMapOfStringString & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetStringsContainer, "Returns the internal container of named strings.");
cls_TDataStd_NamedData.def("ChangeStrings", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringString &)) &TDataStd_NamedData::ChangeStrings, "Replace the container content by new content of the <theStrings>.", py::arg("theStrings"));
cls_TDataStd_NamedData.def("HasBytes", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasBytes, "Returns true if there are some named bytes in the attribute.");
cls_TDataStd_NamedData.def("HasByte", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasByte, "Returns true if the attribute contains this named byte.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetByte", (Standard_Byte (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetByte, "Returns the named byte. It returns 0 if there is no such a named byte (use HasByte()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetByte", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const Standard_Byte)) &TDataStd_NamedData::SetByte, "Defines a named byte. If the byte already exists, it changes its value to <theByte>.", py::arg("theName"), py::arg("theByte"));
cls_TDataStd_NamedData.def("GetBytesContainer", (const TDataStd_DataMapOfStringByte & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetBytesContainer, "Returns the internal container of named bytes.");
cls_TDataStd_NamedData.def("ChangeBytes", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringByte &)) &TDataStd_NamedData::ChangeBytes, "Replace the container content by new content of the <theBytes>.", py::arg("theBytes"));
cls_TDataStd_NamedData.def("HasArraysOfIntegers", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasArraysOfIntegers, "Returns true if there are some named arrays of integer values in the attribute.");
cls_TDataStd_NamedData.def("HasArrayOfIntegers", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasArrayOfIntegers, "Returns true if the attribute contains this named array of integer values.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetArrayOfIntegers", (const opencascade::handle<TColStd_HArray1OfInteger> & (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetArrayOfIntegers, "Returns the named array of integer values. It returns a NULL Handle if there is no such a named array of integers (use HasArrayOfIntegers()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetArrayOfIntegers", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &TDataStd_NamedData::SetArrayOfIntegers, "Defines a named array of integer values. If the array already exists, it changes its value to <theArrayOfIntegers>.", py::arg("theName"), py::arg("theArrayOfIntegers"));
cls_TDataStd_NamedData.def("GetArraysOfIntegersContainer", (const TDataStd_DataMapOfStringHArray1OfInteger & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetArraysOfIntegersContainer, "Returns the internal container of named arrays of integer values.");
cls_TDataStd_NamedData.def("ChangeArraysOfIntegers", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringHArray1OfInteger &)) &TDataStd_NamedData::ChangeArraysOfIntegers, "Replace the container content by new content of the <theArraysOfIntegers>.", py::arg("theArraysOfIntegers"));
cls_TDataStd_NamedData.def("HasArraysOfReals", (Standard_Boolean (TDataStd_NamedData::*)() const) &TDataStd_NamedData::HasArraysOfReals, "Returns true if there are some named arrays of real values in the attribute.");
cls_TDataStd_NamedData.def("HasArrayOfReals", (Standard_Boolean (TDataStd_NamedData::*)(const TCollection_ExtendedString &) const) &TDataStd_NamedData::HasArrayOfReals, "Returns true if the attribute contains this named array of real values.", py::arg("theName"));
cls_TDataStd_NamedData.def("GetArrayOfReals", (const opencascade::handle<TColStd_HArray1OfReal> & (TDataStd_NamedData::*)(const TCollection_ExtendedString &)) &TDataStd_NamedData::GetArrayOfReals, "Returns the named array of real values. It returns a NULL Handle if there is no such a named array of reals (use HasArrayOfReals()).", py::arg("theName"));
cls_TDataStd_NamedData.def("SetArrayOfReals", (void (TDataStd_NamedData::*)(const TCollection_ExtendedString &, const opencascade::handle<TColStd_HArray1OfReal> &)) &TDataStd_NamedData::SetArrayOfReals, "Defines a named array of real values. If the array already exists, it changes its value to <theArrayOfReals>.", py::arg("theName"), py::arg("theArrayOfReals"));
cls_TDataStd_NamedData.def("GetArraysOfRealsContainer", (const TDataStd_DataMapOfStringHArray1OfReal & (TDataStd_NamedData::*)()) &TDataStd_NamedData::GetArraysOfRealsContainer, "Returns the internal container of named arrays of real values.");
cls_TDataStd_NamedData.def("ChangeArraysOfReals", (void (TDataStd_NamedData::*)(const TDataStd_DataMapOfStringHArray1OfReal &)) &TDataStd_NamedData::ChangeArraysOfReals, "Replace the container content by new content of the <theArraysOfReals>.", py::arg("theArraysOfReals"));
cls_TDataStd_NamedData.def("ID", (const Standard_GUID & (TDataStd_NamedData::*)() const) &TDataStd_NamedData::ID, "None");
cls_TDataStd_NamedData.def("Restore", (void (TDataStd_NamedData::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_NamedData::Restore, "None", py::arg("With"));
cls_TDataStd_NamedData.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_NamedData::*)() const) &TDataStd_NamedData::NewEmpty, "None");
cls_TDataStd_NamedData.def("Paste", (void (TDataStd_NamedData::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_NamedData::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_NamedData.def("Dump", (Standard_OStream & (TDataStd_NamedData::*)(Standard_OStream &) const) &TDataStd_NamedData::Dump, "None", py::arg("anOS"));
cls_TDataStd_NamedData.def_static("get_type_name_", (const char * (*)()) &TDataStd_NamedData::get_type_name, "None");
cls_TDataStd_NamedData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_NamedData::get_type_descriptor, "None");
cls_TDataStd_NamedData.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_NamedData::*)() const) &TDataStd_NamedData::DynamicType, "None");

// CLASS: TDATASTD_REAL
py::class_<TDataStd_Real, opencascade::handle<TDataStd_Real>, TDF_Attribute> cls_TDataStd_Real(mod, "TDataStd_Real", "The basis to define a real number attribute.");

// Constructors
cls_TDataStd_Real.def(py::init<>());

// Methods
cls_TDataStd_Real.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Real::GetID, "class methods ============= Returns the default GUID for real numbers.");
cls_TDataStd_Real.def_static("Set_", (opencascade::handle<TDataStd_Real> (*)(const TDF_Label &, const Standard_Real)) &TDataStd_Real::Set, "Finds, or creates, a Real attribute with default GUID and sets <value>. The Real attribute is returned. The Real dimension is Scalar by default. Use SetDimension to overwrite. Real methods ============", py::arg("label"), py::arg("value"));
cls_TDataStd_Real.def_static("Set_", (opencascade::handle<TDataStd_Real> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Real)) &TDataStd_Real::Set, "Finds, or creates, a Real attribute with explicit GUID and sets <value>. The Real attribute is returned. Real methods ============", py::arg("label"), py::arg("guid"), py::arg("value"));
cls_TDataStd_Real.def("SetDimension", (void (TDataStd_Real::*)(const TDataStd_RealEnum)) &TDataStd_Real::SetDimension, "Obsolete method that will be removed in next versions. This field is not supported in the persistence mechanism.", py::arg("DIM"));
cls_TDataStd_Real.def("GetDimension", (TDataStd_RealEnum (TDataStd_Real::*)() const) &TDataStd_Real::GetDimension, "Obsolete method that will be removed in next versions. This field is not supported in the persistence mechanism.");
cls_TDataStd_Real.def("Set", (void (TDataStd_Real::*)(const Standard_Real)) &TDataStd_Real::Set, "Sets the real number V.", py::arg("V"));
cls_TDataStd_Real.def("SetID", (void (TDataStd_Real::*)(const Standard_GUID &)) &TDataStd_Real::SetID, "Sets the explicit GUID for the attribute.", py::arg("guid"));
cls_TDataStd_Real.def("SetID", (void (TDataStd_Real::*)()) &TDataStd_Real::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_Real.def("Get", (Standard_Real (TDataStd_Real::*)() const) &TDataStd_Real::Get, "Returns the real number value contained in the attribute.");
cls_TDataStd_Real.def("IsCaptured", (Standard_Boolean (TDataStd_Real::*)() const) &TDataStd_Real::IsCaptured, "Returns True if there is a reference on the same label");
cls_TDataStd_Real.def("ID", (const Standard_GUID & (TDataStd_Real::*)() const) &TDataStd_Real::ID, "None");
cls_TDataStd_Real.def("Restore", (void (TDataStd_Real::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Real::Restore, "None", py::arg("With"));
cls_TDataStd_Real.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Real::*)() const) &TDataStd_Real::NewEmpty, "None");
cls_TDataStd_Real.def("Paste", (void (TDataStd_Real::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Real::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Real.def("Dump", (Standard_OStream & (TDataStd_Real::*)(Standard_OStream &) const) &TDataStd_Real::Dump, "None", py::arg("anOS"));
cls_TDataStd_Real.def_static("get_type_name_", (const char * (*)()) &TDataStd_Real::get_type_name, "None");
cls_TDataStd_Real.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Real::get_type_descriptor, "None");
cls_TDataStd_Real.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Real::*)() const) &TDataStd_Real::DynamicType, "None");

// TYPEDEF: TDATASTD_PTRTREENODE

// CLASS: TDATASTD_TREENODE
py::class_<TDataStd_TreeNode, opencascade::handle<TDataStd_TreeNode>, TDF_Attribute> cls_TDataStd_TreeNode(mod, "TDataStd_TreeNode", "Allows you to define an explicit tree of labels which you can also edit. Without this class, the data structure cannot be fully edited. This service is required if for presentation purposes, you want to create an application with a tree which allows you to organize and link data as a function of application features.");

// Constructors
cls_TDataStd_TreeNode.def(py::init<>());

// Methods
cls_TDataStd_TreeNode.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::Find, "class methods working on the node =================================== Returns true if the tree node T is found on the label L. Otherwise, false is returned.", py::arg("L"), py::arg("T"));
cls_TDataStd_TreeNode.def_static("Set_", (opencascade::handle<TDataStd_TreeNode> (*)(const TDF_Label &)) &TDataStd_TreeNode::Set, "Finds or Creates a TreeNode attribute on the label <L> with the default tree ID, returned by the method <GetDefaultTreeID>. Returns the created/found TreeNode attribute.", py::arg("L"));
cls_TDataStd_TreeNode.def_static("Set_", (opencascade::handle<TDataStd_TreeNode> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_TreeNode::Set, "Finds or Creates a TreeNode attribute on the label <L>, with an explicit tree ID. <ExplicitTreeID> is the ID returned by <TDF_Attribute::ID> method. Returns the found/created TreeNode attribute.", py::arg("L"), py::arg("ExplicitTreeID"));
cls_TDataStd_TreeNode.def_static("GetDefaultTreeID_", (const Standard_GUID & (*)()) &TDataStd_TreeNode::GetDefaultTreeID, "returns a default tree ID. this ID is used by the <Set> method without explicit tree ID. Instance methods: ================");
cls_TDataStd_TreeNode.def("Append", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::Append, "Insert the TreeNode <Child> as last child of <me>. If the insertion is successful <me> becomes the Father of <Child>.", py::arg("Child"));
cls_TDataStd_TreeNode.def("Prepend", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::Prepend, "Insert the the TreeNode <Child> as first child of <me>. If the insertion is successful <me> becomes the Father of <Child>", py::arg("Child"));
cls_TDataStd_TreeNode.def("InsertBefore", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::InsertBefore, "Inserts the TreeNode <Node> before <me>. If insertion is successful <me> and <Node> belongs to the same Father.", py::arg("Node"));
cls_TDataStd_TreeNode.def("InsertAfter", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::InsertAfter, "Inserts the TreeNode <Node> after <me>. If insertion is successful <me> and <Node> belongs to the same Father.", py::arg("Node"));
cls_TDataStd_TreeNode.def("Remove", (Standard_Boolean (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::Remove, "Removes this tree node attribute from its father node. The result is that this attribute becomes a root node.");
cls_TDataStd_TreeNode.def("Depth", (Standard_Integer (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Depth, "Returns the depth of this tree node in the overall tree node structure. In other words, the number of father tree nodes of this one is returned.");
cls_TDataStd_TreeNode.def("NbChildren", [](TDataStd_TreeNode &self) -> Standard_Integer { return self.NbChildren(); });
cls_TDataStd_TreeNode.def("NbChildren", (Standard_Integer (TDataStd_TreeNode::*)(const Standard_Boolean) const) &TDataStd_TreeNode::NbChildren, "Returns the number of child nodes. If <allLevels> is true, the method counts children of all levels (children of children ...)", py::arg("allLevels"));
cls_TDataStd_TreeNode.def("IsAscendant", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &) const) &TDataStd_TreeNode::IsAscendant, "Returns true if this tree node attribute is an ascendant of of. In other words, if it is a father or the father of a father of of.", py::arg("of"));
cls_TDataStd_TreeNode.def("IsDescendant", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &) const) &TDataStd_TreeNode::IsDescendant, "Returns true if this tree node attribute is a descendant of of. In other words, if it is a child or the child of a child of of.", py::arg("of"));
cls_TDataStd_TreeNode.def("IsRoot", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::IsRoot, "Returns true if this tree node attribute is the ultimate father in the tree.");
cls_TDataStd_TreeNode.def("Root", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Root, "Returns the ultimate father of this tree node attribute.");
cls_TDataStd_TreeNode.def("IsFather", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &) const) &TDataStd_TreeNode::IsFather, "Returns true if this tree node attribute is a father of of.", py::arg("of"));
cls_TDataStd_TreeNode.def("IsChild", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &) const) &TDataStd_TreeNode::IsChild, "Returns true if this tree node attribute is a child of of.", py::arg("of"));
cls_TDataStd_TreeNode.def("HasFather", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasFather, "Returns true if this tree node attribute has a father tree node.");
cls_TDataStd_TreeNode.def("Father", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Father, "Returns the father TreeNode of <me>. Null if root.");
cls_TDataStd_TreeNode.def("HasNext", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasNext, "Returns true if this tree node attribute has a next tree node.");
cls_TDataStd_TreeNode.def("Next", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Next, "Returns the next tree node in this tree node attribute. Warning This tree node is null if it is the last one in this tree node attribute.Returns the next TreeNode of <me>. Null if last.");
cls_TDataStd_TreeNode.def("HasPrevious", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasPrevious, "Returns true if this tree node attribute has a previous tree node.");
cls_TDataStd_TreeNode.def("Previous", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Previous, "Returns the previous tree node of this tree node attribute. Warning This tree node is null if it is the first one in this tree node attribute.");
cls_TDataStd_TreeNode.def("HasFirst", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasFirst, "Returns true if this tree node attribute has a first child tree node.");
cls_TDataStd_TreeNode.def("First", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::First, "Returns the first child tree node in this tree node object.");
cls_TDataStd_TreeNode.def("HasLast", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasLast, "Returns true if this tree node attribute has a last child tree node.");
cls_TDataStd_TreeNode.def("Last", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::Last, "Returns the last child tree node in this tree node object.");
cls_TDataStd_TreeNode.def("FindLast", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::FindLast, "Returns the last child tree node in this tree node object. to set fields =============");
cls_TDataStd_TreeNode.def("SetTreeID", (void (TDataStd_TreeNode::*)(const Standard_GUID &)) &TDataStd_TreeNode::SetTreeID, "None", py::arg("explicitID"));
cls_TDataStd_TreeNode.def("SetFather", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetFather, "None", py::arg("F"));
cls_TDataStd_TreeNode.def("SetNext", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetNext, "None", py::arg("F"));
cls_TDataStd_TreeNode.def("SetPrevious", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetPrevious, "None", py::arg("F"));
cls_TDataStd_TreeNode.def("SetFirst", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetFirst, "None", py::arg("F"));
cls_TDataStd_TreeNode.def("SetLast", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetLast, "TreeNode callback: ==================", py::arg("F"));
cls_TDataStd_TreeNode.def("AfterAddition", (void (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::AfterAddition, "Connect the TreeNode to its father child list");
cls_TDataStd_TreeNode.def("BeforeForget", (void (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::BeforeForget, "Disconnect the TreeNode from its Father child list");
cls_TDataStd_TreeNode.def("AfterResume", (void (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::AfterResume, "Reconnect the TreeNode to its father child list.");
cls_TDataStd_TreeNode.def("BeforeUndo", [](TDataStd_TreeNode &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); });
cls_TDataStd_TreeNode.def("BeforeUndo", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDataStd_TreeNode::BeforeUndo, "Disconnect the TreeNode, if necessary.", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TDataStd_TreeNode.def("AfterUndo", [](TDataStd_TreeNode &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); });
cls_TDataStd_TreeNode.def("AfterUndo", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDataStd_TreeNode::AfterUndo, "Reconnect the TreeNode, if necessary. Implementation of Attribute methods: ===================================", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TDataStd_TreeNode.def("ID", (const Standard_GUID & (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::ID, "Returns the tree ID (default or explicit one depending onthe Set method used).");
cls_TDataStd_TreeNode.def("Restore", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_TreeNode::Restore, "None", py::arg("with"));
cls_TDataStd_TreeNode.def("Paste", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_TreeNode::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_TreeNode.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::NewEmpty, "None");
cls_TDataStd_TreeNode.def("References", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_TreeNode::References, "None", py::arg("aDataSet"));
cls_TDataStd_TreeNode.def("Dump", (Standard_OStream & (TDataStd_TreeNode::*)(Standard_OStream &) const) &TDataStd_TreeNode::Dump, "None", py::arg("anOS"));
cls_TDataStd_TreeNode.def_static("get_type_name_", (const char * (*)()) &TDataStd_TreeNode::get_type_name, "None");
cls_TDataStd_TreeNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_TreeNode::get_type_descriptor, "None");
cls_TDataStd_TreeNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::DynamicType, "None");

// CLASS: TDATASTD_INTEGER
py::class_<TDataStd_Integer, opencascade::handle<TDataStd_Integer>, TDF_Attribute> cls_TDataStd_Integer(mod, "TDataStd_Integer", "The basis to define an integer attribute.");

// Constructors
cls_TDataStd_Integer.def(py::init<>());

// Methods
cls_TDataStd_Integer.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Integer::GetID, "class methods ============= Returns the GUID for integers.");
cls_TDataStd_Integer.def_static("Set_", (opencascade::handle<TDataStd_Integer> (*)(const TDF_Label &, const Standard_Integer)) &TDataStd_Integer::Set, "Finds, or creates, an Integer attribute and sets <value> the Integer attribute is returned.", py::arg("label"), py::arg("value"));
cls_TDataStd_Integer.def_static("Set_", (opencascade::handle<TDataStd_Integer> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Integer)) &TDataStd_Integer::Set, "Finds, or creates, an Integer attribute with explicit user defined <guid> and sets <value>. The Integer attribute is returned.", py::arg("label"), py::arg("guid"), py::arg("value"));
cls_TDataStd_Integer.def("Set", (void (TDataStd_Integer::*)(const Standard_Integer)) &TDataStd_Integer::Set, "Integer methods ===============", py::arg("V"));
cls_TDataStd_Integer.def("SetID", (void (TDataStd_Integer::*)(const Standard_GUID &)) &TDataStd_Integer::SetID, "Sets the explicit GUID (user defined) for the attribute.", py::arg("guid"));
cls_TDataStd_Integer.def("SetID", (void (TDataStd_Integer::*)()) &TDataStd_Integer::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_Integer.def("Get", (Standard_Integer (TDataStd_Integer::*)() const) &TDataStd_Integer::Get, "Returns the integer value contained in the attribute.");
cls_TDataStd_Integer.def("IsCaptured", (Standard_Boolean (TDataStd_Integer::*)() const) &TDataStd_Integer::IsCaptured, "Returns True if there is a reference on the same label");
cls_TDataStd_Integer.def("ID", (const Standard_GUID & (TDataStd_Integer::*)() const) &TDataStd_Integer::ID, "None");
cls_TDataStd_Integer.def("Restore", (void (TDataStd_Integer::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Integer::Restore, "None", py::arg("With"));
cls_TDataStd_Integer.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Integer::*)() const) &TDataStd_Integer::NewEmpty, "None");
cls_TDataStd_Integer.def("Paste", (void (TDataStd_Integer::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Integer::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Integer.def("Dump", (Standard_OStream & (TDataStd_Integer::*)(Standard_OStream &) const) &TDataStd_Integer::Dump, "None", py::arg("anOS"));
cls_TDataStd_Integer.def_static("get_type_name_", (const char * (*)()) &TDataStd_Integer::get_type_name, "None");
cls_TDataStd_Integer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Integer::get_type_descriptor, "None");
cls_TDataStd_Integer.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Integer::*)() const) &TDataStd_Integer::DynamicType, "None");

// CLASS: TDATASTD_UATTRIBUTE
py::class_<TDataStd_UAttribute, opencascade::handle<TDataStd_UAttribute>, TDF_Attribute> cls_TDataStd_UAttribute(mod, "TDataStd_UAttribute", "None");

// Constructors
cls_TDataStd_UAttribute.def(py::init<>());

// Methods
cls_TDataStd_UAttribute.def_static("Set_", (opencascade::handle<TDataStd_UAttribute> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_UAttribute::Set, "api class methods ============= Find, or create, a UAttribute attribute with <LocalID> as Local GUID. The UAttribute attribute is returned. UAttribute methods ============", py::arg("label"), py::arg("LocalID"));
cls_TDataStd_UAttribute.def("SetID", (void (TDataStd_UAttribute::*)(const Standard_GUID &)) &TDataStd_UAttribute::SetID, "None", py::arg("LocalID"));
cls_TDataStd_UAttribute.def("ID", (const Standard_GUID & (TDataStd_UAttribute::*)() const) &TDataStd_UAttribute::ID, "None");
cls_TDataStd_UAttribute.def("Restore", (void (TDataStd_UAttribute::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_UAttribute::Restore, "None", py::arg("with"));
cls_TDataStd_UAttribute.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_UAttribute::*)() const) &TDataStd_UAttribute::NewEmpty, "None");
cls_TDataStd_UAttribute.def("Paste", (void (TDataStd_UAttribute::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_UAttribute::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_UAttribute.def("References", (void (TDataStd_UAttribute::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_UAttribute::References, "None", py::arg("DS"));
cls_TDataStd_UAttribute.def("Dump", (Standard_OStream & (TDataStd_UAttribute::*)(Standard_OStream &) const) &TDataStd_UAttribute::Dump, "None", py::arg("anOS"));
cls_TDataStd_UAttribute.def_static("get_type_name_", (const char * (*)()) &TDataStd_UAttribute::get_type_name, "None");
cls_TDataStd_UAttribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_UAttribute::get_type_descriptor, "None");
cls_TDataStd_UAttribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_UAttribute::*)() const) &TDataStd_UAttribute::DynamicType, "None");

// CLASS: TDATASTD_NAME
py::class_<TDataStd_Name, opencascade::handle<TDataStd_Name>, TDF_Attribute> cls_TDataStd_Name(mod, "TDataStd_Name", "Used to define a name attribute containing a string which specifies the name.");

// Constructors
cls_TDataStd_Name.def(py::init<>());

// Methods
cls_TDataStd_Name.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Name::GetID, "class methods working on the name itself ======================================== Returns the GUID for name attributes.");
cls_TDataStd_Name.def_static("Set_", (opencascade::handle<TDataStd_Name> (*)(const TDF_Label &, const TCollection_ExtendedString &)) &TDataStd_Name::Set, "Creates (if does not exist) and sets the name in the name attribute. from any label <L> search in father labels (L is not concerned) the first name attribute.if found set it in <father>. class methods working on the name tree ====================================== Search in the whole TDF_Data the Name attribute which fit with <fullPath>. Returns True if found. Search under <currentLabel> a label which fit with <name>. Returns True if found. Shortcut which avoids building a ListOfExtendedStrin. Search in the whole TDF_Data the label which fit with name Returns True if found. tools methods to translate path <-> pathlist =========================================== move to draw For Draw test we may provide this tool method which convert a path in a sequence of string to call after the FindLabel methods. Example: if it's given 'Assembly:Part_1:Sketch_5' it will return in <pathlist> the list of 3 strings: 'Assembly','Part_1','Sketch_5'. move to draw from <pathlist> build the string path Name methods ============", py::arg("label"), py::arg("string"));
cls_TDataStd_Name.def_static("Set_", (opencascade::handle<TDataStd_Name> (*)(const TDF_Label &, const Standard_GUID &, const TCollection_ExtendedString &)) &TDataStd_Name::Set, "Finds, or creates, a Name attribute with explicit user defined <guid> and sets <string>. The Name attribute is returned.", py::arg("label"), py::arg("guid"), py::arg("string"));
cls_TDataStd_Name.def("Set", (void (TDataStd_Name::*)(const TCollection_ExtendedString &)) &TDataStd_Name::Set, "Sets <S> as name. Raises if <S> is not a valid name.", py::arg("S"));
cls_TDataStd_Name.def("SetID", (void (TDataStd_Name::*)(const Standard_GUID &)) &TDataStd_Name::SetID, "Sets the explicit user defined GUID to the attribute.", py::arg("guid"));
cls_TDataStd_Name.def("SetID", (void (TDataStd_Name::*)()) &TDataStd_Name::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_Name.def("Get", (const TCollection_ExtendedString & (TDataStd_Name::*)() const) &TDataStd_Name::Get, "Returns the name contained in this name attribute.");
cls_TDataStd_Name.def("ID", (const Standard_GUID & (TDataStd_Name::*)() const) &TDataStd_Name::ID, "None");
cls_TDataStd_Name.def("Restore", (void (TDataStd_Name::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Name::Restore, "None", py::arg("with"));
cls_TDataStd_Name.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Name::*)() const) &TDataStd_Name::NewEmpty, "None");
cls_TDataStd_Name.def("Paste", (void (TDataStd_Name::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Name::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_Name.def("Dump", (Standard_OStream & (TDataStd_Name::*)(Standard_OStream &) const) &TDataStd_Name::Dump, "None", py::arg("anOS"));
cls_TDataStd_Name.def_static("get_type_name_", (const char * (*)()) &TDataStd_Name::get_type_name, "None");
cls_TDataStd_Name.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Name::get_type_descriptor, "None");
cls_TDataStd_Name.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Name::*)() const) &TDataStd_Name::DynamicType, "None");

// CLASS: TDATASTD_COMMENT
py::class_<TDataStd_Comment, opencascade::handle<TDataStd_Comment>, TDF_Attribute> cls_TDataStd_Comment(mod, "TDataStd_Comment", "Comment attribute. may be associated to any label to store user comment.");

// Constructors
cls_TDataStd_Comment.def(py::init<>());

// Methods
cls_TDataStd_Comment.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Comment::GetID, "class methods ============= Returns the GUID for comments.");
cls_TDataStd_Comment.def_static("Set_", (opencascade::handle<TDataStd_Comment> (*)(const TDF_Label &)) &TDataStd_Comment::Set, "Find, or create a Comment attribute. the Comment attribute is returned.", py::arg("label"));
cls_TDataStd_Comment.def_static("Set_", (opencascade::handle<TDataStd_Comment> (*)(const TDF_Label &, const TCollection_ExtendedString &)) &TDataStd_Comment::Set, "Finds, or creates a Comment attribute and sets the string. the Comment attribute is returned. Comment methods ============", py::arg("label"), py::arg("string"));
cls_TDataStd_Comment.def("Set", (void (TDataStd_Comment::*)(const TCollection_ExtendedString &)) &TDataStd_Comment::Set, "None", py::arg("S"));
cls_TDataStd_Comment.def("Get", (const TCollection_ExtendedString & (TDataStd_Comment::*)() const) &TDataStd_Comment::Get, "Returns the comment attribute.");
cls_TDataStd_Comment.def("ID", (const Standard_GUID & (TDataStd_Comment::*)() const) &TDataStd_Comment::ID, "None");
cls_TDataStd_Comment.def("Restore", (void (TDataStd_Comment::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Comment::Restore, "None", py::arg("with"));
cls_TDataStd_Comment.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Comment::*)() const) &TDataStd_Comment::NewEmpty, "None");
cls_TDataStd_Comment.def("Paste", (void (TDataStd_Comment::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Comment::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_Comment.def("Dump", (Standard_OStream & (TDataStd_Comment::*)(Standard_OStream &) const) &TDataStd_Comment::Dump, "None", py::arg("anOS"));
cls_TDataStd_Comment.def("AfterRetrieval", [](TDataStd_Comment &self) -> Standard_Boolean { return self.AfterRetrieval(); });
cls_TDataStd_Comment.def("AfterRetrieval", (Standard_Boolean (TDataStd_Comment::*)(const Standard_Boolean)) &TDataStd_Comment::AfterRetrieval, "None", py::arg("forceIt"));
cls_TDataStd_Comment.def_static("get_type_name_", (const char * (*)()) &TDataStd_Comment::get_type_name, "None");
cls_TDataStd_Comment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Comment::get_type_descriptor, "None");
cls_TDataStd_Comment.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Comment::*)() const) &TDataStd_Comment::DynamicType, "None");

// CLASS: TDATASTD_ASCIISTRING
py::class_<TDataStd_AsciiString, opencascade::handle<TDataStd_AsciiString>, TDF_Attribute> cls_TDataStd_AsciiString(mod, "TDataStd_AsciiString", "Used to define an AsciiString attribute containing a TCollection_AsciiString");

// Constructors
cls_TDataStd_AsciiString.def(py::init<>());

// Methods
cls_TDataStd_AsciiString.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_AsciiString::GetID, "class methods ============= Returns the GUID of the attribute.");
cls_TDataStd_AsciiString.def_static("Set_", (opencascade::handle<TDataStd_AsciiString> (*)(const TDF_Label &, const TCollection_AsciiString &)) &TDataStd_AsciiString::Set, "Finds, or creates an AsciiString attribute and sets the string. the AsciiString attribute is returned. AsciiString methods ===================", py::arg("label"), py::arg("string"));
cls_TDataStd_AsciiString.def_static("Set_", (opencascade::handle<TDataStd_AsciiString> (*)(const TDF_Label &, const Standard_GUID &, const TCollection_AsciiString &)) &TDataStd_AsciiString::Set, "Finds, or creates, an AsciiString attribute with explicit user defined <guid> and sets <string>. The Name attribute is returned.", py::arg("label"), py::arg("guid"), py::arg("string"));
cls_TDataStd_AsciiString.def("Set", (void (TDataStd_AsciiString::*)(const TCollection_AsciiString &)) &TDataStd_AsciiString::Set, "None", py::arg("S"));
cls_TDataStd_AsciiString.def("SetID", (void (TDataStd_AsciiString::*)(const Standard_GUID &)) &TDataStd_AsciiString::SetID, "Sets the explicit user defined GUID to the attribute.", py::arg("guid"));
cls_TDataStd_AsciiString.def("SetID", (void (TDataStd_AsciiString::*)()) &TDataStd_AsciiString::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_AsciiString.def("Get", (const TCollection_AsciiString & (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::Get, "None");
cls_TDataStd_AsciiString.def("IsEmpty", (Standard_Boolean (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::IsEmpty, "None");
cls_TDataStd_AsciiString.def("ID", (const Standard_GUID & (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::ID, "None");
cls_TDataStd_AsciiString.def("Restore", (void (TDataStd_AsciiString::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_AsciiString::Restore, "None", py::arg("with"));
cls_TDataStd_AsciiString.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::NewEmpty, "None");
cls_TDataStd_AsciiString.def("Paste", (void (TDataStd_AsciiString::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_AsciiString::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_AsciiString.def("Dump", (Standard_OStream & (TDataStd_AsciiString::*)(Standard_OStream &) const) &TDataStd_AsciiString::Dump, "None", py::arg("anOS"));
cls_TDataStd_AsciiString.def_static("get_type_name_", (const char * (*)()) &TDataStd_AsciiString::get_type_name, "None");
cls_TDataStd_AsciiString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_AsciiString::get_type_descriptor, "None");
cls_TDataStd_AsciiString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::DynamicType, "None");

// CLASS: TDATASTD_VARIABLE
py::class_<TDataStd_Variable, opencascade::handle<TDataStd_Variable>, TDF_Attribute> cls_TDataStd_Variable(mod, "TDataStd_Variable", "Variable attribute. ==================");

// Constructors
cls_TDataStd_Variable.def(py::init<>());

// Methods
cls_TDataStd_Variable.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Variable::GetID, "class methods =============");
cls_TDataStd_Variable.def_static("Set_", (opencascade::handle<TDataStd_Variable> (*)(const TDF_Label &)) &TDataStd_Variable::Set, "Find, or create, a Variable attribute. Real methods ============", py::arg("label"));
cls_TDataStd_Variable.def("Name", (void (TDataStd_Variable::*)(const TCollection_ExtendedString &)) &TDataStd_Variable::Name, "set or change the name of the variable, in myUnknown and my associated Name attribute.", py::arg("string"));
cls_TDataStd_Variable.def("Name", (const TCollection_ExtendedString & (TDataStd_Variable::*)() const) &TDataStd_Variable::Name, "returns string stored in the associated Name attribute.");
cls_TDataStd_Variable.def("Set", (void (TDataStd_Variable::*)(const Standard_Real) const) &TDataStd_Variable::Set, "retrieve or create the associated real attribute and set the value <value>.", py::arg("value"));
cls_TDataStd_Variable.def("Set", (void (TDataStd_Variable::*)(const Standard_Real, const TDataStd_RealEnum) const) &TDataStd_Variable::Set, "Obsolete method that will be removed in next versions. The dimension argument is not supported in the persistence mechanism.", py::arg("value"), py::arg("dimension"));
cls_TDataStd_Variable.def("IsValued", (Standard_Boolean (TDataStd_Variable::*)() const) &TDataStd_Variable::IsValued, "returns True if a Real attribute is associated.");
cls_TDataStd_Variable.def("Get", (Standard_Real (TDataStd_Variable::*)() const) &TDataStd_Variable::Get, "returns value stored in associated Real attribute.");
cls_TDataStd_Variable.def("Real", (opencascade::handle<TDataStd_Real> (TDataStd_Variable::*)() const) &TDataStd_Variable::Real, "returns associated Real attribute.");
cls_TDataStd_Variable.def("IsAssigned", (Standard_Boolean (TDataStd_Variable::*)() const) &TDataStd_Variable::IsAssigned, "returns True if an Expression attribute is associated. create(if doesn't exist), set and returns the assigned expression attribute.");
cls_TDataStd_Variable.def("Assign", (opencascade::handle<TDataStd_Expression> (TDataStd_Variable::*)() const) &TDataStd_Variable::Assign, "create(if doesn't exist) and returns the assigned expression attribute. fill it after.");
cls_TDataStd_Variable.def("Desassign", (void (TDataStd_Variable::*)() const) &TDataStd_Variable::Desassign, "if <me> is assigned delete the associated expression attribute.");
cls_TDataStd_Variable.def("Expression", (opencascade::handle<TDataStd_Expression> (TDataStd_Variable::*)() const) &TDataStd_Variable::Expression, "if <me> is assigned, returns associated Expression attribute.");
cls_TDataStd_Variable.def("IsCaptured", (Standard_Boolean (TDataStd_Variable::*)() const) &TDataStd_Variable::IsCaptured, "shortcut for <Real()->IsCaptured()>");
cls_TDataStd_Variable.def("IsConstant", (Standard_Boolean (TDataStd_Variable::*)() const) &TDataStd_Variable::IsConstant, "A constant value is not modified by regeneration.");
cls_TDataStd_Variable.def("Unit", (void (TDataStd_Variable::*)(const TCollection_AsciiString &)) &TDataStd_Variable::Unit, "None", py::arg("unit"));
cls_TDataStd_Variable.def("Unit", (const TCollection_AsciiString & (TDataStd_Variable::*)() const) &TDataStd_Variable::Unit, "to read/write fields ===================");
cls_TDataStd_Variable.def("Constant", (void (TDataStd_Variable::*)(const Standard_Boolean)) &TDataStd_Variable::Constant, "if <status> is True, this variable will not be modified by the solver.", py::arg("status"));
cls_TDataStd_Variable.def("ID", (const Standard_GUID & (TDataStd_Variable::*)() const) &TDataStd_Variable::ID, "None");
cls_TDataStd_Variable.def("Restore", (void (TDataStd_Variable::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Variable::Restore, "None", py::arg("With"));
cls_TDataStd_Variable.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Variable::*)() const) &TDataStd_Variable::NewEmpty, "None");
cls_TDataStd_Variable.def("Paste", (void (TDataStd_Variable::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Variable::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Variable.def("References", (void (TDataStd_Variable::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_Variable::References, "to export reference to the associated Name attribute.", py::arg("DS"));
cls_TDataStd_Variable.def("Dump", (Standard_OStream & (TDataStd_Variable::*)(Standard_OStream &) const) &TDataStd_Variable::Dump, "None", py::arg("anOS"));
cls_TDataStd_Variable.def_static("get_type_name_", (const char * (*)()) &TDataStd_Variable::get_type_name, "None");
cls_TDataStd_Variable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Variable::get_type_descriptor, "None");
cls_TDataStd_Variable.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Variable::*)() const) &TDataStd_Variable::DynamicType, "None");

// CLASS: TDATASTD_DIRECTORY
py::class_<TDataStd_Directory, opencascade::handle<TDataStd_Directory>, TDF_Attribute> cls_TDataStd_Directory(mod, "TDataStd_Directory", "Associates a directory in the data framework with a TDataStd_TagSource attribute. You can create a new directory label and add sub-directory or object labels to it,");

// Constructors
cls_TDataStd_Directory.def(py::init<>());

// Methods
cls_TDataStd_Directory.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TDataStd_Directory> &)) &TDataStd_Directory::Find, "class methods ============= Searches for a directory attribute on the label current, or on one of the father labels of current. If a directory attribute is found, true is returned, and the attribute found is set as D.", py::arg("current"), py::arg("D"));
cls_TDataStd_Directory.def_static("New_", (opencascade::handle<TDataStd_Directory> (*)(const TDF_Label &)) &TDataStd_Directory::New, "Creates an enpty Directory attribute, located at <label>. Raises if <label> has attribute", py::arg("label"));
cls_TDataStd_Directory.def_static("AddDirectory_", (opencascade::handle<TDataStd_Directory> (*)(const opencascade::handle<TDataStd_Directory> &)) &TDataStd_Directory::AddDirectory, "Creates a new sub-label and sets the sub-directory dir on that label.", py::arg("dir"));
cls_TDataStd_Directory.def_static("MakeObjectLabel_", (TDF_Label (*)(const opencascade::handle<TDataStd_Directory> &)) &TDataStd_Directory::MakeObjectLabel, "Makes new label and returns it to insert other object attributes (sketch,part...etc...)", py::arg("dir"));
cls_TDataStd_Directory.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Directory::GetID, "Directory methods ===============");
cls_TDataStd_Directory.def("ID", (const Standard_GUID & (TDataStd_Directory::*)() const) &TDataStd_Directory::ID, "None");
cls_TDataStd_Directory.def("Restore", (void (TDataStd_Directory::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Directory::Restore, "None", py::arg("with"));
cls_TDataStd_Directory.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Directory::*)() const) &TDataStd_Directory::NewEmpty, "None");
cls_TDataStd_Directory.def("Paste", (void (TDataStd_Directory::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Directory::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_Directory.def("References", (void (TDataStd_Directory::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_Directory::References, "None", py::arg("DS"));
cls_TDataStd_Directory.def("Dump", (Standard_OStream & (TDataStd_Directory::*)(Standard_OStream &) const) &TDataStd_Directory::Dump, "None", py::arg("anOS"));
cls_TDataStd_Directory.def_static("get_type_name_", (const char * (*)()) &TDataStd_Directory::get_type_name, "None");
cls_TDataStd_Directory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Directory::get_type_descriptor, "None");
cls_TDataStd_Directory.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Directory::*)() const) &TDataStd_Directory::DynamicType, "None");

// CLASS: TDATASTD_TICK
py::class_<TDataStd_Tick, opencascade::handle<TDataStd_Tick>, TDF_Attribute> cls_TDataStd_Tick(mod, "TDataStd_Tick", "Defines a boolean attribute. If it exists at a label - true, Otherwise - false.");

// Constructors
cls_TDataStd_Tick.def(py::init<>());

// Methods
cls_TDataStd_Tick.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Tick::GetID, "Static methods ==============");
cls_TDataStd_Tick.def_static("Set_", (opencascade::handle<TDataStd_Tick> (*)(const TDF_Label &)) &TDataStd_Tick::Set, "Find, or create, a Tick attribute. Tick methods ============", py::arg("label"));
cls_TDataStd_Tick.def("ID", (const Standard_GUID & (TDataStd_Tick::*)() const) &TDataStd_Tick::ID, "None");
cls_TDataStd_Tick.def("Restore", (void (TDataStd_Tick::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Tick::Restore, "None", py::arg("With"));
cls_TDataStd_Tick.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Tick::*)() const) &TDataStd_Tick::NewEmpty, "None");
cls_TDataStd_Tick.def("Paste", (void (TDataStd_Tick::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Tick::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Tick.def("Dump", (Standard_OStream & (TDataStd_Tick::*)(Standard_OStream &) const) &TDataStd_Tick::Dump, "None", py::arg("anOS"));
cls_TDataStd_Tick.def_static("get_type_name_", (const char * (*)()) &TDataStd_Tick::get_type_name, "None");
cls_TDataStd_Tick.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Tick::get_type_descriptor, "None");
cls_TDataStd_Tick.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Tick::*)() const) &TDataStd_Tick::DynamicType, "None");

// CLASS: TDATASTD_NOTEBOOK
py::class_<TDataStd_NoteBook, opencascade::handle<TDataStd_NoteBook>, TDF_Attribute> cls_TDataStd_NoteBook(mod, "TDataStd_NoteBook", "NoteBook Object attribute");

// Constructors
cls_TDataStd_NoteBook.def(py::init<>());

// Methods
cls_TDataStd_NoteBook.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TDataStd_NoteBook> &)) &TDataStd_NoteBook::Find, "class methods ============= try to retrieve a NoteBook attribute at <current> label or in fathers label of <current>. Returns True if found and set <N>.", py::arg("current"), py::arg("N"));
cls_TDataStd_NoteBook.def_static("New_", (opencascade::handle<TDataStd_NoteBook> (*)(const TDF_Label &)) &TDataStd_NoteBook::New, "Create an enpty NoteBook attribute, located at <label>. Raises if <label> has attribute", py::arg("label"));
cls_TDataStd_NoteBook.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_NoteBook::GetID, "NoteBook methods ===============");
cls_TDataStd_NoteBook.def("Append", [](TDataStd_NoteBook &self, const Standard_Real a0) -> opencascade::handle<TDataStd_Real> { return self.Append(a0); });
cls_TDataStd_NoteBook.def("Append", (opencascade::handle<TDataStd_Real> (TDataStd_NoteBook::*)(const Standard_Real, const Standard_Boolean)) &TDataStd_NoteBook::Append, "Tool to Create an Integer attribute from <value>, Insert it in a new son label of <me>. The Real attribute is returned.", py::arg("value"), py::arg("isExported"));
cls_TDataStd_NoteBook.def("Append", [](TDataStd_NoteBook &self, const Standard_Integer a0) -> opencascade::handle<TDataStd_Integer> { return self.Append(a0); });
cls_TDataStd_NoteBook.def("Append", (opencascade::handle<TDataStd_Integer> (TDataStd_NoteBook::*)(const Standard_Integer, const Standard_Boolean)) &TDataStd_NoteBook::Append, "Tool to Create an Real attribute from <value>, Insert it in a new son label of <me>. The Integer attribute is returned.", py::arg("value"), py::arg("isExported"));
cls_TDataStd_NoteBook.def("ID", (const Standard_GUID & (TDataStd_NoteBook::*)() const) &TDataStd_NoteBook::ID, "None");
cls_TDataStd_NoteBook.def("Restore", (void (TDataStd_NoteBook::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_NoteBook::Restore, "None", py::arg("with"));
cls_TDataStd_NoteBook.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_NoteBook::*)() const) &TDataStd_NoteBook::NewEmpty, "None");
cls_TDataStd_NoteBook.def("Paste", (void (TDataStd_NoteBook::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_NoteBook::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_NoteBook.def("Dump", (Standard_OStream & (TDataStd_NoteBook::*)(Standard_OStream &) const) &TDataStd_NoteBook::Dump, "None", py::arg("anOS"));
cls_TDataStd_NoteBook.def_static("get_type_name_", (const char * (*)()) &TDataStd_NoteBook::get_type_name, "None");
cls_TDataStd_NoteBook.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_NoteBook::get_type_descriptor, "None");
cls_TDataStd_NoteBook.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_NoteBook::*)() const) &TDataStd_NoteBook::DynamicType, "None");

// CLASS: TDATASTD
py::class_<TDataStd> cls_TDataStd(mod, "TDataStd", "This package defines standard attributes for modelling. These allow you to create and modify labels and attributes for many basic data types. Standard topological and visualization attributes have also been created. To find an attribute attached to a specific label, you use the GUID of the type of attribute you are looking for. To do this, first find this information using the method GetID as follows: Standard_GUID anID = MyAttributeClass::GetID(); Then, use the method Find for the label as follows: Standard_Boolean HasAttribute = aLabel.Find(anID,anAttribute); Note For information on the relations between this component of OCAF and the others, refer to the OCAF User's Guide.");

// Methods
// cls_TDataStd.def_static("operator new_", (void * (*)(size_t)) &TDataStd::operator new, "None", py::arg("theSize"));
// cls_TDataStd.def_static("operator delete_", (void (*)(void *)) &TDataStd::operator delete, "None", py::arg("theAddress"));
// cls_TDataStd.def_static("operator new[]_", (void * (*)(size_t)) &TDataStd::operator new[], "None", py::arg("theSize"));
// cls_TDataStd.def_static("operator delete[]_", (void (*)(void *)) &TDataStd::operator delete[], "None", py::arg("theAddress"));
// cls_TDataStd.def_static("operator new_", (void * (*)(size_t, void *)) &TDataStd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDataStd.def_static("operator delete_", (void (*)(void *, void *)) &TDataStd::operator delete, "None", py::arg(""), py::arg(""));
cls_TDataStd.def_static("IDList_", (void (*)(TDF_IDList &)) &TDataStd::IDList, "Appends to <anIDList> the list of the attributes IDs of this package. CAUTION: <anIDList> is NOT cleared before use.", py::arg("anIDList"));
cls_TDataStd.def_static("Print_", (Standard_OStream & (*)(const TDataStd_RealEnum, Standard_OStream &)) &TDataStd::Print, "Prints the name of the real dimension <DIM> as a String on the Stream <S> and returns <S>.", py::arg("DIM"), py::arg("S"));

// CLASS: TDATASTD_CHILDNODEITERATOR
py::class_<TDataStd_ChildNodeIterator> cls_TDataStd_ChildNodeIterator(mod, "TDataStd_ChildNodeIterator", "Iterates on the ChildStepren step of a step, at the first level only. It is possible to ask the iterator to explore all the sub step levels of the given one, with the option 'allLevels'.");

// Constructors
cls_TDataStd_ChildNodeIterator.def(py::init<>());
cls_TDataStd_ChildNodeIterator.def(py::init<const opencascade::handle<TDataStd_TreeNode> &>(), py::arg("aTreeNode"));
cls_TDataStd_ChildNodeIterator.def(py::init<const opencascade::handle<TDataStd_TreeNode> &, const Standard_Boolean>(), py::arg("aTreeNode"), py::arg("allLevels"));

// Methods
// cls_TDataStd_ChildNodeIterator.def_static("operator new_", (void * (*)(size_t)) &TDataStd_ChildNodeIterator::operator new, "None", py::arg("theSize"));
// cls_TDataStd_ChildNodeIterator.def_static("operator delete_", (void (*)(void *)) &TDataStd_ChildNodeIterator::operator delete, "None", py::arg("theAddress"));
// cls_TDataStd_ChildNodeIterator.def_static("operator new[]_", (void * (*)(size_t)) &TDataStd_ChildNodeIterator::operator new[], "None", py::arg("theSize"));
// cls_TDataStd_ChildNodeIterator.def_static("operator delete[]_", (void (*)(void *)) &TDataStd_ChildNodeIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TDataStd_ChildNodeIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TDataStd_ChildNodeIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDataStd_ChildNodeIterator.def_static("operator delete_", (void (*)(void *, void *)) &TDataStd_ChildNodeIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TDataStd_ChildNodeIterator.def("Initialize", [](TDataStd_ChildNodeIterator &self, const opencascade::handle<TDataStd_TreeNode> & a0) -> void { return self.Initialize(a0); });
cls_TDataStd_ChildNodeIterator.def("Initialize", (void (TDataStd_ChildNodeIterator::*)(const opencascade::handle<TDataStd_TreeNode> &, const Standard_Boolean)) &TDataStd_ChildNodeIterator::Initialize, "Initializes the iteration on the Children Step of the given Step. If <allLevels> option is set to true, it explores not only the first, but all the sub Step levels.", py::arg("aTreeNode"), py::arg("allLevels"));
cls_TDataStd_ChildNodeIterator.def("More", (Standard_Boolean (TDataStd_ChildNodeIterator::*)() const) &TDataStd_ChildNodeIterator::More, "Returns True if there is a current Item in the iteration.");
cls_TDataStd_ChildNodeIterator.def("Next", (void (TDataStd_ChildNodeIterator::*)()) &TDataStd_ChildNodeIterator::Next, "Move to the next Item");
cls_TDataStd_ChildNodeIterator.def("NextBrother", (void (TDataStd_ChildNodeIterator::*)()) &TDataStd_ChildNodeIterator::NextBrother, "Move to the next Brother. If there is none, go up etc. This method is interesting only with 'allLevels' behavior, because it avoids to explore the current Step ChildStepren.");
cls_TDataStd_ChildNodeIterator.def("Value", (const opencascade::handle<TDataStd_TreeNode> & (TDataStd_ChildNodeIterator::*)() const) &TDataStd_ChildNodeIterator::Value, "Returns the current item; a null Step if there is no one.");

// CLASS: TDATASTD_CURRENT
py::class_<TDataStd_Current, opencascade::handle<TDataStd_Current>, TDF_Attribute> cls_TDataStd_Current(mod, "TDataStd_Current", "this attribute, located at root label, manage an access to a current label.");

// Constructors
cls_TDataStd_Current.def(py::init<>());

// Methods
cls_TDataStd_Current.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Current::GetID, "class methods =============");
cls_TDataStd_Current.def_static("Set_", (void (*)(const TDF_Label &)) &TDataStd_Current::Set, "Set <L> as current of <L> Framework.", py::arg("L"));
cls_TDataStd_Current.def_static("Get_", (TDF_Label (*)(const TDF_Label &)) &TDataStd_Current::Get, "returns current of <acces> Framework. raise if (!Has)", py::arg("acces"));
cls_TDataStd_Current.def_static("Has_", (Standard_Boolean (*)(const TDF_Label &)) &TDataStd_Current::Has, "returns True if a current label is managed in <acces> Framework. class methods =============", py::arg("acces"));
cls_TDataStd_Current.def("SetLabel", (void (TDataStd_Current::*)(const TDF_Label &)) &TDataStd_Current::SetLabel, "None", py::arg("current"));
cls_TDataStd_Current.def("GetLabel", (TDF_Label (TDataStd_Current::*)() const) &TDataStd_Current::GetLabel, "None");
cls_TDataStd_Current.def("ID", (const Standard_GUID & (TDataStd_Current::*)() const) &TDataStd_Current::ID, "None");
cls_TDataStd_Current.def("Restore", (void (TDataStd_Current::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Current::Restore, "None", py::arg("With"));
cls_TDataStd_Current.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Current::*)() const) &TDataStd_Current::NewEmpty, "None");
cls_TDataStd_Current.def("Paste", (void (TDataStd_Current::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Current::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Current.def("Dump", (Standard_OStream & (TDataStd_Current::*)(Standard_OStream &) const) &TDataStd_Current::Dump, "None", py::arg("anOS"));
cls_TDataStd_Current.def_static("get_type_name_", (const char * (*)()) &TDataStd_Current::get_type_name, "None");
cls_TDataStd_Current.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Current::get_type_descriptor, "None");
cls_TDataStd_Current.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Current::*)() const) &TDataStd_Current::DynamicType, "None");

// CLASS: TDATASTD_DELTAONMODIFICATIONOFBYTEARRAY
py::class_<TDataStd_DeltaOnModificationOfByteArray, opencascade::handle<TDataStd_DeltaOnModificationOfByteArray>, TDF_DeltaOnModification> cls_TDataStd_DeltaOnModificationOfByteArray(mod, "TDataStd_DeltaOnModificationOfByteArray", "This class provides default services for an AttributeDelta on a MODIFICATION action.");

// Constructors
cls_TDataStd_DeltaOnModificationOfByteArray.def(py::init<const opencascade::handle<TDataStd_ByteArray> &>(), py::arg("Arr"));

// Methods
cls_TDataStd_DeltaOnModificationOfByteArray.def("Apply", (void (TDataStd_DeltaOnModificationOfByteArray::*)()) &TDataStd_DeltaOnModificationOfByteArray::Apply, "Applies the delta to the attribute.");
cls_TDataStd_DeltaOnModificationOfByteArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_DeltaOnModificationOfByteArray::get_type_name, "None");
cls_TDataStd_DeltaOnModificationOfByteArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_DeltaOnModificationOfByteArray::get_type_descriptor, "None");
cls_TDataStd_DeltaOnModificationOfByteArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_DeltaOnModificationOfByteArray::*)() const) &TDataStd_DeltaOnModificationOfByteArray::DynamicType, "None");

// CLASS: TDATASTD_DELTAONMODIFICATIONOFEXTSTRINGARRAY
py::class_<TDataStd_DeltaOnModificationOfExtStringArray, opencascade::handle<TDataStd_DeltaOnModificationOfExtStringArray>, TDF_DeltaOnModification> cls_TDataStd_DeltaOnModificationOfExtStringArray(mod, "TDataStd_DeltaOnModificationOfExtStringArray", "This class provides default services for an AttributeDelta on a MODIFICATION action.");

// Constructors
cls_TDataStd_DeltaOnModificationOfExtStringArray.def(py::init<const opencascade::handle<TDataStd_ExtStringArray> &>(), py::arg("Arr"));

// Methods
cls_TDataStd_DeltaOnModificationOfExtStringArray.def("Apply", (void (TDataStd_DeltaOnModificationOfExtStringArray::*)()) &TDataStd_DeltaOnModificationOfExtStringArray::Apply, "Applies the delta to the attribute.");
cls_TDataStd_DeltaOnModificationOfExtStringArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_DeltaOnModificationOfExtStringArray::get_type_name, "None");
cls_TDataStd_DeltaOnModificationOfExtStringArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_DeltaOnModificationOfExtStringArray::get_type_descriptor, "None");
cls_TDataStd_DeltaOnModificationOfExtStringArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_DeltaOnModificationOfExtStringArray::*)() const) &TDataStd_DeltaOnModificationOfExtStringArray::DynamicType, "None");

// CLASS: TDATASTD_DELTAONMODIFICATIONOFINTARRAY
py::class_<TDataStd_DeltaOnModificationOfIntArray, opencascade::handle<TDataStd_DeltaOnModificationOfIntArray>, TDF_DeltaOnModification> cls_TDataStd_DeltaOnModificationOfIntArray(mod, "TDataStd_DeltaOnModificationOfIntArray", "This class provides default services for an AttributeDelta on a MODIFICATION action.");

// Constructors
cls_TDataStd_DeltaOnModificationOfIntArray.def(py::init<const opencascade::handle<TDataStd_IntegerArray> &>(), py::arg("Arr"));

// Methods
cls_TDataStd_DeltaOnModificationOfIntArray.def("Apply", (void (TDataStd_DeltaOnModificationOfIntArray::*)()) &TDataStd_DeltaOnModificationOfIntArray::Apply, "Applies the delta to the attribute.");
cls_TDataStd_DeltaOnModificationOfIntArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_DeltaOnModificationOfIntArray::get_type_name, "None");
cls_TDataStd_DeltaOnModificationOfIntArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_DeltaOnModificationOfIntArray::get_type_descriptor, "None");
cls_TDataStd_DeltaOnModificationOfIntArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_DeltaOnModificationOfIntArray::*)() const) &TDataStd_DeltaOnModificationOfIntArray::DynamicType, "None");

// CLASS: TDATASTD_DELTAONMODIFICATIONOFINTPACKEDMAP
py::class_<TDataStd_DeltaOnModificationOfIntPackedMap, opencascade::handle<TDataStd_DeltaOnModificationOfIntPackedMap>, TDF_DeltaOnModification> cls_TDataStd_DeltaOnModificationOfIntPackedMap(mod, "TDataStd_DeltaOnModificationOfIntPackedMap", "This class provides default services for an AttributeDelta on a MODIFICATION action.");

// Constructors
cls_TDataStd_DeltaOnModificationOfIntPackedMap.def(py::init<const opencascade::handle<TDataStd_IntPackedMap> &>(), py::arg("Arr"));

// Methods
cls_TDataStd_DeltaOnModificationOfIntPackedMap.def("Apply", (void (TDataStd_DeltaOnModificationOfIntPackedMap::*)()) &TDataStd_DeltaOnModificationOfIntPackedMap::Apply, "Applies the delta to the attribute.");
cls_TDataStd_DeltaOnModificationOfIntPackedMap.def_static("get_type_name_", (const char * (*)()) &TDataStd_DeltaOnModificationOfIntPackedMap::get_type_name, "None");
cls_TDataStd_DeltaOnModificationOfIntPackedMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_DeltaOnModificationOfIntPackedMap::get_type_descriptor, "None");
cls_TDataStd_DeltaOnModificationOfIntPackedMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_DeltaOnModificationOfIntPackedMap::*)() const) &TDataStd_DeltaOnModificationOfIntPackedMap::DynamicType, "None");

// CLASS: TDATASTD_DELTAONMODIFICATIONOFREALARRAY
py::class_<TDataStd_DeltaOnModificationOfRealArray, opencascade::handle<TDataStd_DeltaOnModificationOfRealArray>, TDF_DeltaOnModification> cls_TDataStd_DeltaOnModificationOfRealArray(mod, "TDataStd_DeltaOnModificationOfRealArray", "This class provides default services for an AttributeDelta on a MODIFICATION action");

// Constructors
cls_TDataStd_DeltaOnModificationOfRealArray.def(py::init<const opencascade::handle<TDataStd_RealArray> &>(), py::arg("Arr"));

// Methods
cls_TDataStd_DeltaOnModificationOfRealArray.def("Apply", (void (TDataStd_DeltaOnModificationOfRealArray::*)()) &TDataStd_DeltaOnModificationOfRealArray::Apply, "Applies the delta to the attribute.");
cls_TDataStd_DeltaOnModificationOfRealArray.def_static("get_type_name_", (const char * (*)()) &TDataStd_DeltaOnModificationOfRealArray::get_type_name, "None");
cls_TDataStd_DeltaOnModificationOfRealArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_DeltaOnModificationOfRealArray::get_type_descriptor, "None");
cls_TDataStd_DeltaOnModificationOfRealArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_DeltaOnModificationOfRealArray::*)() const) &TDataStd_DeltaOnModificationOfRealArray::DynamicType, "None");

// CLASS: TDATASTD_HDATAMAPOFSTRINGBYTE
py::class_<TDataStd_HDataMapOfStringByte, opencascade::handle<TDataStd_HDataMapOfStringByte>, Standard_Transient> cls_TDataStd_HDataMapOfStringByte(mod, "TDataStd_HDataMapOfStringByte", "Extension of TDataStd_DataMapOfStringByte class to be manipulated by handle.");

// Constructors
cls_TDataStd_HDataMapOfStringByte.def(py::init<>());
cls_TDataStd_HDataMapOfStringByte.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TDataStd_HDataMapOfStringByte.def(py::init<const TDataStd_DataMapOfStringByte &>(), py::arg("theOther"));

// Methods
cls_TDataStd_HDataMapOfStringByte.def_static("get_type_name_", (const char * (*)()) &TDataStd_HDataMapOfStringByte::get_type_name, "None");
cls_TDataStd_HDataMapOfStringByte.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HDataMapOfStringByte::get_type_descriptor, "None");
cls_TDataStd_HDataMapOfStringByte.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HDataMapOfStringByte::*)() const) &TDataStd_HDataMapOfStringByte::DynamicType, "None");
cls_TDataStd_HDataMapOfStringByte.def("Map", (const TDataStd_DataMapOfStringByte & (TDataStd_HDataMapOfStringByte::*)() const) &TDataStd_HDataMapOfStringByte::Map, "None");
cls_TDataStd_HDataMapOfStringByte.def("ChangeMap", (TDataStd_DataMapOfStringByte & (TDataStd_HDataMapOfStringByte::*)()) &TDataStd_HDataMapOfStringByte::ChangeMap, "None");

// CLASS: TDATASTD_HDATAMAPOFSTRINGHARRAY1OFINTEGER
py::class_<TDataStd_HDataMapOfStringHArray1OfInteger, opencascade::handle<TDataStd_HDataMapOfStringHArray1OfInteger>, Standard_Transient> cls_TDataStd_HDataMapOfStringHArray1OfInteger(mod, "TDataStd_HDataMapOfStringHArray1OfInteger", "Extension of TDataStd_DataMapOfStringHArray1OfInteger class to be manipulated by handle.");

// Constructors
cls_TDataStd_HDataMapOfStringHArray1OfInteger.def(py::init<>());
cls_TDataStd_HDataMapOfStringHArray1OfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TDataStd_HDataMapOfStringHArray1OfInteger.def(py::init<const TDataStd_DataMapOfStringHArray1OfInteger &>(), py::arg("theOther"));

// Methods
cls_TDataStd_HDataMapOfStringHArray1OfInteger.def_static("get_type_name_", (const char * (*)()) &TDataStd_HDataMapOfStringHArray1OfInteger::get_type_name, "None");
cls_TDataStd_HDataMapOfStringHArray1OfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HDataMapOfStringHArray1OfInteger::get_type_descriptor, "None");
cls_TDataStd_HDataMapOfStringHArray1OfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HDataMapOfStringHArray1OfInteger::*)() const) &TDataStd_HDataMapOfStringHArray1OfInteger::DynamicType, "None");
cls_TDataStd_HDataMapOfStringHArray1OfInteger.def("Map", (const TDataStd_DataMapOfStringHArray1OfInteger & (TDataStd_HDataMapOfStringHArray1OfInteger::*)() const) &TDataStd_HDataMapOfStringHArray1OfInteger::Map, "None");
cls_TDataStd_HDataMapOfStringHArray1OfInteger.def("ChangeMap", (TDataStd_DataMapOfStringHArray1OfInteger & (TDataStd_HDataMapOfStringHArray1OfInteger::*)()) &TDataStd_HDataMapOfStringHArray1OfInteger::ChangeMap, "None");

// CLASS: TDATASTD_HDATAMAPOFSTRINGHARRAY1OFREAL
py::class_<TDataStd_HDataMapOfStringHArray1OfReal, opencascade::handle<TDataStd_HDataMapOfStringHArray1OfReal>, Standard_Transient> cls_TDataStd_HDataMapOfStringHArray1OfReal(mod, "TDataStd_HDataMapOfStringHArray1OfReal", "Extension of TDataStd_DataMapOfStringHArray1OfReal class to be manipulated by handle.");

// Constructors
cls_TDataStd_HDataMapOfStringHArray1OfReal.def(py::init<>());
cls_TDataStd_HDataMapOfStringHArray1OfReal.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TDataStd_HDataMapOfStringHArray1OfReal.def(py::init<const TDataStd_DataMapOfStringHArray1OfReal &>(), py::arg("theOther"));

// Methods
cls_TDataStd_HDataMapOfStringHArray1OfReal.def_static("get_type_name_", (const char * (*)()) &TDataStd_HDataMapOfStringHArray1OfReal::get_type_name, "None");
cls_TDataStd_HDataMapOfStringHArray1OfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HDataMapOfStringHArray1OfReal::get_type_descriptor, "None");
cls_TDataStd_HDataMapOfStringHArray1OfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HDataMapOfStringHArray1OfReal::*)() const) &TDataStd_HDataMapOfStringHArray1OfReal::DynamicType, "None");
cls_TDataStd_HDataMapOfStringHArray1OfReal.def("Map", (const TDataStd_DataMapOfStringHArray1OfReal & (TDataStd_HDataMapOfStringHArray1OfReal::*)() const) &TDataStd_HDataMapOfStringHArray1OfReal::Map, "None");
cls_TDataStd_HDataMapOfStringHArray1OfReal.def("ChangeMap", (TDataStd_DataMapOfStringHArray1OfReal & (TDataStd_HDataMapOfStringHArray1OfReal::*)()) &TDataStd_HDataMapOfStringHArray1OfReal::ChangeMap, "None");

// CLASS: TDATASTD_HDATAMAPOFSTRINGINTEGER
py::class_<TDataStd_HDataMapOfStringInteger, opencascade::handle<TDataStd_HDataMapOfStringInteger>, Standard_Transient> cls_TDataStd_HDataMapOfStringInteger(mod, "TDataStd_HDataMapOfStringInteger", "Extension of TColStd_DataMapOfStringInteger class to be manipulated by handle.");

// Constructors
cls_TDataStd_HDataMapOfStringInteger.def(py::init<>());
cls_TDataStd_HDataMapOfStringInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TDataStd_HDataMapOfStringInteger.def(py::init<const TColStd_DataMapOfStringInteger &>(), py::arg("theOther"));

// Methods
cls_TDataStd_HDataMapOfStringInteger.def_static("get_type_name_", (const char * (*)()) &TDataStd_HDataMapOfStringInteger::get_type_name, "None");
cls_TDataStd_HDataMapOfStringInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HDataMapOfStringInteger::get_type_descriptor, "None");
cls_TDataStd_HDataMapOfStringInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HDataMapOfStringInteger::*)() const) &TDataStd_HDataMapOfStringInteger::DynamicType, "None");
cls_TDataStd_HDataMapOfStringInteger.def("Map", (const TColStd_DataMapOfStringInteger & (TDataStd_HDataMapOfStringInteger::*)() const) &TDataStd_HDataMapOfStringInteger::Map, "None");
cls_TDataStd_HDataMapOfStringInteger.def("ChangeMap", (TColStd_DataMapOfStringInteger & (TDataStd_HDataMapOfStringInteger::*)()) &TDataStd_HDataMapOfStringInteger::ChangeMap, "None");

// CLASS: TDATASTD_HDATAMAPOFSTRINGREAL
py::class_<TDataStd_HDataMapOfStringReal, opencascade::handle<TDataStd_HDataMapOfStringReal>, Standard_Transient> cls_TDataStd_HDataMapOfStringReal(mod, "TDataStd_HDataMapOfStringReal", "Extension of TDataStd_DataMapOfStringReal class to be manipulated by handle.");

// Constructors
cls_TDataStd_HDataMapOfStringReal.def(py::init<>());
cls_TDataStd_HDataMapOfStringReal.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TDataStd_HDataMapOfStringReal.def(py::init<const TDataStd_DataMapOfStringReal &>(), py::arg("theOther"));

// Methods
cls_TDataStd_HDataMapOfStringReal.def_static("get_type_name_", (const char * (*)()) &TDataStd_HDataMapOfStringReal::get_type_name, "None");
cls_TDataStd_HDataMapOfStringReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HDataMapOfStringReal::get_type_descriptor, "None");
cls_TDataStd_HDataMapOfStringReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HDataMapOfStringReal::*)() const) &TDataStd_HDataMapOfStringReal::DynamicType, "None");
cls_TDataStd_HDataMapOfStringReal.def("Map", (const TDataStd_DataMapOfStringReal & (TDataStd_HDataMapOfStringReal::*)() const) &TDataStd_HDataMapOfStringReal::Map, "None");
cls_TDataStd_HDataMapOfStringReal.def("ChangeMap", (TDataStd_DataMapOfStringReal & (TDataStd_HDataMapOfStringReal::*)()) &TDataStd_HDataMapOfStringReal::ChangeMap, "None");

// CLASS: TDATASTD_HDATAMAPOFSTRINGSTRING
py::class_<TDataStd_HDataMapOfStringString, opencascade::handle<TDataStd_HDataMapOfStringString>, Standard_Transient> cls_TDataStd_HDataMapOfStringString(mod, "TDataStd_HDataMapOfStringString", "Extension of TDataStd_DataMapOfStringString class to be manipulated by handle.");

// Constructors
cls_TDataStd_HDataMapOfStringString.def(py::init<>());
cls_TDataStd_HDataMapOfStringString.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TDataStd_HDataMapOfStringString.def(py::init<const TDataStd_DataMapOfStringString &>(), py::arg("theOther"));

// Methods
cls_TDataStd_HDataMapOfStringString.def_static("get_type_name_", (const char * (*)()) &TDataStd_HDataMapOfStringString::get_type_name, "None");
cls_TDataStd_HDataMapOfStringString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HDataMapOfStringString::get_type_descriptor, "None");
cls_TDataStd_HDataMapOfStringString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HDataMapOfStringString::*)() const) &TDataStd_HDataMapOfStringString::DynamicType, "None");
cls_TDataStd_HDataMapOfStringString.def("Map", (const TDataStd_DataMapOfStringString & (TDataStd_HDataMapOfStringString::*)() const) &TDataStd_HDataMapOfStringString::Map, "None");
cls_TDataStd_HDataMapOfStringString.def("ChangeMap", (TDataStd_DataMapOfStringString & (TDataStd_HDataMapOfStringString::*)()) &TDataStd_HDataMapOfStringString::ChangeMap, "None");


}
