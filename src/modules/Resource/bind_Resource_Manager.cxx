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
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Resource_Manager.hxx>
#include <Standard_Type.hxx>
#include <Resource_DataMapOfAsciiStringAsciiString.hxx>
#include <Resource_DataMapOfAsciiStringExtendedString.hxx>

void bind_Resource_Manager(py::module &mod){

py::class_<Resource_Manager, opencascade::handle<Resource_Manager>, Standard_Transient> cls_Resource_Manager(mod, "Resource_Manager", "Defines a resource structure and its management methods.");

// Constructors
cls_Resource_Manager.def(py::init<const Standard_CString>(), py::arg("aName"));
cls_Resource_Manager.def(py::init<const Standard_CString, const Standard_Boolean>(), py::arg("aName"), py::arg("Verbose"));
cls_Resource_Manager.def(py::init<const Standard_CString, TCollection_AsciiString &, TCollection_AsciiString &>(), py::arg("aName"), py::arg("aDefaultsDirectory"), py::arg("anUserDefaultsDirectory"));
cls_Resource_Manager.def(py::init<const Standard_CString, TCollection_AsciiString &, TCollection_AsciiString &, const Standard_Boolean>(), py::arg("aName"), py::arg("aDefaultsDirectory"), py::arg("anUserDefaultsDirectory"), py::arg("Verbose"));

// Fields

// Methods
cls_Resource_Manager.def("Save", (Standard_Boolean (Resource_Manager::*)() const) &Resource_Manager::Save, "Save the user resource structure in the specified file. Creates the file if it does not exist.");
cls_Resource_Manager.def("Find", (Standard_Boolean (Resource_Manager::*)(const Standard_CString) const) &Resource_Manager::Find, "returns True if the Resource does exist.", py::arg("aResource"));
cls_Resource_Manager.def("Integer", (Standard_Integer (Resource_Manager::*)(const Standard_CString) const) &Resource_Manager::Integer, "Gets the value of an integer resource according to its instance and its type.", py::arg("aResourceName"));
cls_Resource_Manager.def("Real", (Standard_Real (Resource_Manager::*)(const Standard_CString) const) &Resource_Manager::Real, "Gets the value of a real resource according to its instance and its type.", py::arg("aResourceName"));
cls_Resource_Manager.def("Value", (Standard_CString (Resource_Manager::*)(const Standard_CString) const) &Resource_Manager::Value, "Gets the value of a CString resource according to its instance and its type.", py::arg("aResourceName"));
cls_Resource_Manager.def("ExtValue", (Standard_ExtString (Resource_Manager::*)(const Standard_CString)) &Resource_Manager::ExtValue, "Gets the value of an ExtString resource according to its instance and its type.", py::arg("aResourceName"));
cls_Resource_Manager.def("SetResource", (void (Resource_Manager::*)(const Standard_CString, const Standard_Integer)) &Resource_Manager::SetResource, "Sets the new value of an integer resource. If the resource does not exist, it is created.", py::arg("aResourceName"), py::arg("aValue"));
cls_Resource_Manager.def("SetResource", (void (Resource_Manager::*)(const Standard_CString, const Standard_Real)) &Resource_Manager::SetResource, "Sets the new value of a real resource. If the resource does not exist, it is created.", py::arg("aResourceName"), py::arg("aValue"));
cls_Resource_Manager.def("SetResource", (void (Resource_Manager::*)(const Standard_CString, const Standard_CString)) &Resource_Manager::SetResource, "Sets the new value of an CString resource. If the resource does not exist, it is created.", py::arg("aResourceName"), py::arg("aValue"));
cls_Resource_Manager.def("SetResource", (void (Resource_Manager::*)(const Standard_CString, const Standard_ExtString)) &Resource_Manager::SetResource, "Sets the new value of an ExtString resource. If the resource does not exist, it is created.", py::arg("aResourceName"), py::arg("aValue"));
cls_Resource_Manager.def_static("GetResourcePath_", (void (*)(TCollection_AsciiString &, const Standard_CString, const Standard_Boolean)) &Resource_Manager::GetResourcePath, "Gets the resource file full path by its name. If corresponding environment variable is not set or file doesn't exist returns empty string.", py::arg("aPath"), py::arg("aName"), py::arg("isUserDefaults"));
cls_Resource_Manager.def_static("get_type_name_", (const char * (*)()) &Resource_Manager::get_type_name, "None");
cls_Resource_Manager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Resource_Manager::get_type_descriptor, "None");
cls_Resource_Manager.def("DynamicType", (const opencascade::handle<Standard_Type> & (Resource_Manager::*)() const) &Resource_Manager::DynamicType, "None");

// Enums

}