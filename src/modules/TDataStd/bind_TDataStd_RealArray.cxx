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
#include <TDataStd_DeltaOnModificationOfRealArray.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_RealArray.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDF_DeltaOnModification.hxx>

void bind_TDataStd_RealArray(py::module &mod){

py::class_<TDataStd_RealArray, opencascade::handle<TDataStd_RealArray>, TDF_Attribute> cls_TDataStd_RealArray(mod, "TDataStd_RealArray", "A framework for an attribute composed of a real number array.");

// Constructors
cls_TDataStd_RealArray.def(py::init<>());

// Fields

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

// Enums

}