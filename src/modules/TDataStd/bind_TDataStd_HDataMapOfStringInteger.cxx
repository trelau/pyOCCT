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
#include <TDataStd_HDataMapOfStringInteger.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_DataMapOfStringInteger.hxx>

void bind_TDataStd_HDataMapOfStringInteger(py::module &mod){

py::class_<TDataStd_HDataMapOfStringInteger, opencascade::handle<TDataStd_HDataMapOfStringInteger>, Standard_Transient> cls_TDataStd_HDataMapOfStringInteger(mod, "TDataStd_HDataMapOfStringInteger", "Extension of TColStd_DataMapOfStringInteger class to be manipulated by handle.");

// Constructors
cls_TDataStd_HDataMapOfStringInteger.def(py::init<>());
cls_TDataStd_HDataMapOfStringInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TDataStd_HDataMapOfStringInteger.def(py::init<const TColStd_DataMapOfStringInteger &>(), py::arg("theOther"));

// Fields

// Methods
cls_TDataStd_HDataMapOfStringInteger.def_static("get_type_name_", (const char * (*)()) &TDataStd_HDataMapOfStringInteger::get_type_name, "None");
cls_TDataStd_HDataMapOfStringInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HDataMapOfStringInteger::get_type_descriptor, "None");
cls_TDataStd_HDataMapOfStringInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HDataMapOfStringInteger::*)() const) &TDataStd_HDataMapOfStringInteger::DynamicType, "None");
cls_TDataStd_HDataMapOfStringInteger.def("Map", (const TColStd_DataMapOfStringInteger & (TDataStd_HDataMapOfStringInteger::*)() const) &TDataStd_HDataMapOfStringInteger::Map, "None");
cls_TDataStd_HDataMapOfStringInteger.def("ChangeMap", (TColStd_DataMapOfStringInteger & (TDataStd_HDataMapOfStringInteger::*)()) &TDataStd_HDataMapOfStringInteger::ChangeMap, "None");

// Enums

}