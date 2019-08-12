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
#include <Standard_DomainError.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StdFail_UndefinedValue.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_StdFail_UndefinedValue(py::module &mod){

py::class_<StdFail_UndefinedValue, opencascade::handle<StdFail_UndefinedValue>, Standard_DomainError> cls_StdFail_UndefinedValue(mod, "StdFail_UndefinedValue", "None");

// Constructors
cls_StdFail_UndefinedValue.def(py::init<>());
cls_StdFail_UndefinedValue.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_StdFail_UndefinedValue.def_static("Raise_", (void (*)(const Standard_CString)) &StdFail_UndefinedValue::Raise, "None", py::arg("theMessage"));
cls_StdFail_UndefinedValue.def_static("Raise_", (void (*)(Standard_SStream &)) &StdFail_UndefinedValue::Raise, "None", py::arg("theMessage"));
cls_StdFail_UndefinedValue.def_static("NewInstance_", (opencascade::handle<StdFail_UndefinedValue> (*)(const Standard_CString)) &StdFail_UndefinedValue::NewInstance, "None", py::arg("theMessage"));
cls_StdFail_UndefinedValue.def_static("get_type_name_", (const char * (*)()) &StdFail_UndefinedValue::get_type_name, "None");
cls_StdFail_UndefinedValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdFail_UndefinedValue::get_type_descriptor, "None");
cls_StdFail_UndefinedValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdFail_UndefinedValue::*)() const) &StdFail_UndefinedValue::DynamicType, "None");

// Enums

}