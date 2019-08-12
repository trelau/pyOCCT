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
#include <Standard_Failure.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Plugin_Failure.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Plugin_Failure(py::module &mod){

py::class_<Plugin_Failure, opencascade::handle<Plugin_Failure>, Standard_Failure> cls_Plugin_Failure(mod, "Plugin_Failure", "None");

// Constructors
cls_Plugin_Failure.def(py::init<>());
cls_Plugin_Failure.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Plugin_Failure.def_static("Raise_", (void (*)(const Standard_CString)) &Plugin_Failure::Raise, "None", py::arg("theMessage"));
cls_Plugin_Failure.def_static("Raise_", (void (*)(Standard_SStream &)) &Plugin_Failure::Raise, "None", py::arg("theMessage"));
cls_Plugin_Failure.def_static("NewInstance_", (opencascade::handle<Plugin_Failure> (*)(const Standard_CString)) &Plugin_Failure::NewInstance, "None", py::arg("theMessage"));
cls_Plugin_Failure.def_static("get_type_name_", (const char * (*)()) &Plugin_Failure::get_type_name, "None");
cls_Plugin_Failure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Plugin_Failure::get_type_descriptor, "None");
cls_Plugin_Failure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Plugin_Failure::*)() const) &Plugin_Failure::DynamicType, "None");

// Enums

}