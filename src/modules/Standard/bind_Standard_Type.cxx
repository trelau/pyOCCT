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
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_OStream.hxx>

void bind_Standard_Type(py::module &mod){

py::class_<Standard_Type, opencascade::handle<Standard_Type>, Standard_Transient> cls_Standard_Type(mod, "Standard_Type", "This class provides legacy interface (type descriptor) to run-time type information (RTTI) for OCCT classes inheriting from Standard_Transient.");

// Constructors

// Fields

// Methods
cls_Standard_Type.def("SystemName", (Standard_CString (Standard_Type::*)() const) &Standard_Type::SystemName, "Returns the system type name of the class (typeinfo.name)");
cls_Standard_Type.def("Name", (Standard_CString (Standard_Type::*)() const) &Standard_Type::Name, "Returns the given name of the class type (get_type_name)");
cls_Standard_Type.def("Size", (Standard_Size (Standard_Type::*)() const) &Standard_Type::Size, "Returns the size of the class instance in bytes");
cls_Standard_Type.def("Parent", (const opencascade::handle<Standard_Type> & (Standard_Type::*)() const) &Standard_Type::Parent, "Returns descriptor of the base class in the hierarchy");
cls_Standard_Type.def("SubType", (Standard_Boolean (Standard_Type::*)(const opencascade::handle<Standard_Type> &) const) &Standard_Type::SubType, "Returns True if this type is the same as theOther, or inherits from theOther. Note that multiple inheritance is not supported.", py::arg("theOther"));
cls_Standard_Type.def("SubType", (Standard_Boolean (Standard_Type::*)(const Standard_CString) const) &Standard_Type::SubType, "Returns True if this type is the same as theOther, or inherits from theOther. Note that multiple inheritance is not supported.", py::arg("theOther"));
cls_Standard_Type.def("Print", (void (Standard_Type::*)(Standard_OStream &) const) &Standard_Type::Print, "Prints type (address of descriptor + name) to a stream", py::arg("theStream"));
cls_Standard_Type.def_static("Register_", (Standard_Type * (*)(const char *, const char *, Standard_Size, const opencascade::handle<Standard_Type> &)) &Standard_Type::Register, "Register a type; returns either new or existing descriptor.", py::arg("theSystemName"), py::arg("theName"), py::arg("theSize"), py::arg("theParent"));
cls_Standard_Type.def_static("get_type_name_", (const char * (*)()) &Standard_Type::get_type_name, "None");
cls_Standard_Type.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Type::get_type_descriptor, "None");
cls_Standard_Type.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Type::*)() const) &Standard_Type::DynamicType, "None");

// Enums

}