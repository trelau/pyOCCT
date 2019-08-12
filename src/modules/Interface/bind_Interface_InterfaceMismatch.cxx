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
#include <Interface_InterfaceError.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceMismatch.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Interface_InterfaceMismatch(py::module &mod){

py::class_<Interface_InterfaceMismatch, opencascade::handle<Interface_InterfaceMismatch>, Interface_InterfaceError> cls_Interface_InterfaceMismatch(mod, "Interface_InterfaceMismatch", "None");

// Constructors
cls_Interface_InterfaceMismatch.def(py::init<>());
cls_Interface_InterfaceMismatch.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Interface_InterfaceMismatch.def_static("Raise_", (void (*)(const Standard_CString)) &Interface_InterfaceMismatch::Raise, "None", py::arg("theMessage"));
cls_Interface_InterfaceMismatch.def_static("Raise_", (void (*)(Standard_SStream &)) &Interface_InterfaceMismatch::Raise, "None", py::arg("theMessage"));
cls_Interface_InterfaceMismatch.def_static("NewInstance_", (opencascade::handle<Interface_InterfaceMismatch> (*)(const Standard_CString)) &Interface_InterfaceMismatch::NewInstance, "None", py::arg("theMessage"));
cls_Interface_InterfaceMismatch.def_static("get_type_name_", (const char * (*)()) &Interface_InterfaceMismatch::get_type_name, "None");
cls_Interface_InterfaceMismatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_InterfaceMismatch::get_type_descriptor, "None");
cls_Interface_InterfaceMismatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_InterfaceMismatch::*)() const) &Interface_InterfaceMismatch::DynamicType, "None");

// Enums

}