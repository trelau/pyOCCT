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
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_ReferenceArray.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDataStd_HLabelArray1.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_ReferenceArray(py::module &mod){

py::class_<TDataStd_ReferenceArray, opencascade::handle<TDataStd_ReferenceArray>, TDF_Attribute> cls_TDataStd_ReferenceArray(mod, "TDataStd_ReferenceArray", "Contains an array of references to the labels.");

// Constructors
cls_TDataStd_ReferenceArray.def(py::init<>());

// Fields

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

// Enums

}