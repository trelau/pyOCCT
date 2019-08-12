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
#include <TDF_Attribute.hxx>
#include <TDataStd_DeltaOnModificationOfByteArray.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_ByteArray.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDF_DeltaOnModification.hxx>

void bind_TDataStd_ByteArray(py::module &mod){

py::class_<TDataStd_ByteArray, opencascade::handle<TDataStd_ByteArray>, TDF_Attribute> cls_TDataStd_ByteArray(mod, "TDataStd_ByteArray", "An array of Byte (unsigned char) values.");

// Constructors
cls_TDataStd_ByteArray.def(py::init<>());

// Fields

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

// Enums

}