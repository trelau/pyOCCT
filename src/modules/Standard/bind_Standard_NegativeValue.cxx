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
#include <Standard_RangeError.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_NegativeValue.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Standard_NegativeValue(py::module &mod){

py::class_<Standard_NegativeValue, opencascade::handle<Standard_NegativeValue>, Standard_RangeError> cls_Standard_NegativeValue(mod, "Standard_NegativeValue", "None");

// Constructors
cls_Standard_NegativeValue.def(py::init<>());
cls_Standard_NegativeValue.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Standard_NegativeValue.def_static("Raise_", (void (*)(const Standard_CString)) &Standard_NegativeValue::Raise, "None", py::arg("theMessage"));
cls_Standard_NegativeValue.def_static("Raise_", (void (*)(Standard_SStream &)) &Standard_NegativeValue::Raise, "None", py::arg("theMessage"));
cls_Standard_NegativeValue.def_static("NewInstance_", (opencascade::handle<Standard_NegativeValue> (*)(const Standard_CString)) &Standard_NegativeValue::NewInstance, "None", py::arg("theMessage"));
cls_Standard_NegativeValue.def_static("get_type_name_", (const char * (*)()) &Standard_NegativeValue::get_type_name, "None");
cls_Standard_NegativeValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_NegativeValue::get_type_descriptor, "None");
cls_Standard_NegativeValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_NegativeValue::*)() const) &Standard_NegativeValue::DynamicType, "None");

// Enums

}