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
#include <TDataStd_DeltaOnModificationOfExtStringArray.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_ExtStringArray.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_HArray1OfExtendedString.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDF_DeltaOnModification.hxx>

void bind_TDataStd_ExtStringArray(py::module &mod){

py::class_<TDataStd_ExtStringArray, opencascade::handle<TDataStd_ExtStringArray>, TDF_Attribute> cls_TDataStd_ExtStringArray(mod, "TDataStd_ExtStringArray", "ExtStringArray Attribute. Handles an array of UNICODE strings (represented by the TCollection_ExtendedString class).");

// Constructors
cls_TDataStd_ExtStringArray.def(py::init<>());

// Fields

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

// Enums

}