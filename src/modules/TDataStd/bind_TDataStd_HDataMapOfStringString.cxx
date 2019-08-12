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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_HDataMapOfStringString.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TDataStd_DataMapOfStringString.hxx>

void bind_TDataStd_HDataMapOfStringString(py::module &mod){

py::class_<TDataStd_HDataMapOfStringString, opencascade::handle<TDataStd_HDataMapOfStringString>, Standard_Transient> cls_TDataStd_HDataMapOfStringString(mod, "TDataStd_HDataMapOfStringString", "Extension of TDataStd_DataMapOfStringString class to be manipulated by handle.");

// Constructors
cls_TDataStd_HDataMapOfStringString.def(py::init<>());
cls_TDataStd_HDataMapOfStringString.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TDataStd_HDataMapOfStringString.def(py::init<const TDataStd_DataMapOfStringString &>(), py::arg("theOther"));

// Fields

// Methods
cls_TDataStd_HDataMapOfStringString.def_static("get_type_name_", (const char * (*)()) &TDataStd_HDataMapOfStringString::get_type_name, "None");
cls_TDataStd_HDataMapOfStringString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HDataMapOfStringString::get_type_descriptor, "None");
cls_TDataStd_HDataMapOfStringString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HDataMapOfStringString::*)() const) &TDataStd_HDataMapOfStringString::DynamicType, "None");
cls_TDataStd_HDataMapOfStringString.def("Map", (const TDataStd_DataMapOfStringString & (TDataStd_HDataMapOfStringString::*)() const) &TDataStd_HDataMapOfStringString::Map, "None");
cls_TDataStd_HDataMapOfStringString.def("ChangeMap", (TDataStd_DataMapOfStringString & (TDataStd_HDataMapOfStringString::*)()) &TDataStd_HDataMapOfStringString::ChangeMap, "None");

// Enums

}