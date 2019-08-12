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
#include <TDataStd_DeltaOnModificationOfIntArray.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_IntegerArray.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDF_DeltaOnModification.hxx>

void bind_TDataStd_IntegerArray(py::module &mod){

py::class_<TDataStd_IntegerArray, opencascade::handle<TDataStd_IntegerArray>, TDF_Attribute> cls_TDataStd_IntegerArray(mod, "TDataStd_IntegerArray", "Contains an array of integers.");

// Constructors
cls_TDataStd_IntegerArray.def(py::init<>());

// Fields

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

// Enums

}