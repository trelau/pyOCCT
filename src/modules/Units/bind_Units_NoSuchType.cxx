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
#include <Standard_NoSuchObject.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Units_NoSuchType.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Units_NoSuchType(py::module &mod){

py::class_<Units_NoSuchType, opencascade::handle<Units_NoSuchType>, Standard_NoSuchObject> cls_Units_NoSuchType(mod, "Units_NoSuchType", "None");

// Constructors
cls_Units_NoSuchType.def(py::init<>());
cls_Units_NoSuchType.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Units_NoSuchType.def_static("Raise_", (void (*)(const Standard_CString)) &Units_NoSuchType::Raise, "None", py::arg("theMessage"));
cls_Units_NoSuchType.def_static("Raise_", (void (*)(Standard_SStream &)) &Units_NoSuchType::Raise, "None", py::arg("theMessage"));
cls_Units_NoSuchType.def_static("NewInstance_", (opencascade::handle<Units_NoSuchType> (*)(const Standard_CString)) &Units_NoSuchType::NewInstance, "None", py::arg("theMessage"));
cls_Units_NoSuchType.def_static("get_type_name_", (const char * (*)()) &Units_NoSuchType::get_type_name, "None");
cls_Units_NoSuchType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_NoSuchType::get_type_descriptor, "None");
cls_Units_NoSuchType.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_NoSuchType::*)() const) &Units_NoSuchType::DynamicType, "None");

// Enums

}