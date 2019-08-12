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
#include <TDataStd_HDataMapOfStringReal.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TDataStd_DataMapOfStringReal.hxx>

void bind_TDataStd_HDataMapOfStringReal(py::module &mod){

py::class_<TDataStd_HDataMapOfStringReal, opencascade::handle<TDataStd_HDataMapOfStringReal>, Standard_Transient> cls_TDataStd_HDataMapOfStringReal(mod, "TDataStd_HDataMapOfStringReal", "Extension of TDataStd_DataMapOfStringReal class to be manipulated by handle.");

// Constructors
cls_TDataStd_HDataMapOfStringReal.def(py::init<>());
cls_TDataStd_HDataMapOfStringReal.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TDataStd_HDataMapOfStringReal.def(py::init<const TDataStd_DataMapOfStringReal &>(), py::arg("theOther"));

// Fields

// Methods
cls_TDataStd_HDataMapOfStringReal.def_static("get_type_name_", (const char * (*)()) &TDataStd_HDataMapOfStringReal::get_type_name, "None");
cls_TDataStd_HDataMapOfStringReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_HDataMapOfStringReal::get_type_descriptor, "None");
cls_TDataStd_HDataMapOfStringReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_HDataMapOfStringReal::*)() const) &TDataStd_HDataMapOfStringReal::DynamicType, "None");
cls_TDataStd_HDataMapOfStringReal.def("Map", (const TDataStd_DataMapOfStringReal & (TDataStd_HDataMapOfStringReal::*)() const) &TDataStd_HDataMapOfStringReal::Map, "None");
cls_TDataStd_HDataMapOfStringReal.def("ChangeMap", (TDataStd_DataMapOfStringReal & (TDataStd_HDataMapOfStringReal::*)()) &TDataStd_HDataMapOfStringReal::ChangeMap, "None");

// Enums

}