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
#include <TDataStd_BooleanArray.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_BooleanArray(py::module &mod){

py::class_<TDataStd_BooleanArray, opencascade::handle<TDataStd_BooleanArray>, TDF_Attribute> cls_TDataStd_BooleanArray(mod, "TDataStd_BooleanArray", "An array of boolean values.");

// Constructors
cls_TDataStd_BooleanArray.def(py::init<>());

// Fields

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

// Enums

}