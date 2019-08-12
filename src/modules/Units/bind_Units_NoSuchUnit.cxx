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
#include <Units_NoSuchUnit.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Units_NoSuchUnit(py::module &mod){

py::class_<Units_NoSuchUnit, opencascade::handle<Units_NoSuchUnit>, Standard_NoSuchObject> cls_Units_NoSuchUnit(mod, "Units_NoSuchUnit", "None");

// Constructors
cls_Units_NoSuchUnit.def(py::init<>());
cls_Units_NoSuchUnit.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Units_NoSuchUnit.def_static("Raise_", (void (*)(const Standard_CString)) &Units_NoSuchUnit::Raise, "None", py::arg("theMessage"));
cls_Units_NoSuchUnit.def_static("Raise_", (void (*)(Standard_SStream &)) &Units_NoSuchUnit::Raise, "None", py::arg("theMessage"));
cls_Units_NoSuchUnit.def_static("NewInstance_", (opencascade::handle<Units_NoSuchUnit> (*)(const Standard_CString)) &Units_NoSuchUnit::NewInstance, "None", py::arg("theMessage"));
cls_Units_NoSuchUnit.def_static("get_type_name_", (const char * (*)()) &Units_NoSuchUnit::get_type_name, "None");
cls_Units_NoSuchUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_NoSuchUnit::get_type_descriptor, "None");
cls_Units_NoSuchUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_NoSuchUnit::*)() const) &Units_NoSuchUnit::DynamicType, "None");

// Enums

}