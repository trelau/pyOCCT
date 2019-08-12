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
#include <Geom2d_UndefinedValue.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_UndefinedValue(py::module &mod){

py::class_<Geom2d_UndefinedValue, opencascade::handle<Geom2d_UndefinedValue>, Standard_DomainError> cls_Geom2d_UndefinedValue(mod, "Geom2d_UndefinedValue", "None");

// Constructors
cls_Geom2d_UndefinedValue.def(py::init<>());
cls_Geom2d_UndefinedValue.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Geom2d_UndefinedValue.def_static("Raise_", (void (*)(const Standard_CString)) &Geom2d_UndefinedValue::Raise, "None", py::arg("theMessage"));
cls_Geom2d_UndefinedValue.def_static("Raise_", (void (*)(Standard_SStream &)) &Geom2d_UndefinedValue::Raise, "None", py::arg("theMessage"));
cls_Geom2d_UndefinedValue.def_static("NewInstance_", (opencascade::handle<Geom2d_UndefinedValue> (*)(const Standard_CString)) &Geom2d_UndefinedValue::NewInstance, "None", py::arg("theMessage"));
cls_Geom2d_UndefinedValue.def_static("get_type_name_", (const char * (*)()) &Geom2d_UndefinedValue::get_type_name, "None");
cls_Geom2d_UndefinedValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_UndefinedValue::get_type_descriptor, "None");
cls_Geom2d_UndefinedValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_UndefinedValue::*)() const) &Geom2d_UndefinedValue::DynamicType, "None");

// Enums

}