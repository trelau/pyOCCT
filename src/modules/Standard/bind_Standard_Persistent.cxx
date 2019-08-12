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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Persistent.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_Standard_Persistent(py::module &mod){

py::class_<Standard_Persistent, opencascade::handle<Standard_Persistent>, Standard_Transient> cls_Standard_Persistent(mod, "Standard_Persistent", "Root of 'persistent' classes, a legacy support of object oriented databases, now outdated.");

// Constructors
cls_Standard_Persistent.def(py::init<>());

// Fields

// Methods
// cls_Standard_Persistent.def_static("operator new_", (void * (*)(size_t)) &Standard_Persistent::operator new, "None", py::arg("theSize"));
// cls_Standard_Persistent.def_static("operator delete_", (void (*)(void *)) &Standard_Persistent::operator delete, "None", py::arg("theAddress"));
// cls_Standard_Persistent.def_static("operator new[]_", (void * (*)(size_t)) &Standard_Persistent::operator new[], "None", py::arg("theSize"));
// cls_Standard_Persistent.def_static("operator delete[]_", (void (*)(void *)) &Standard_Persistent::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_Persistent.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_Persistent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_Persistent.def_static("operator delete_", (void (*)(void *, void *)) &Standard_Persistent::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard_Persistent.def_static("get_type_name_", (const char * (*)()) &Standard_Persistent::get_type_name, "None");
cls_Standard_Persistent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Standard_Persistent::get_type_descriptor, "None");
cls_Standard_Persistent.def("DynamicType", (const opencascade::handle<Standard_Type> & (Standard_Persistent::*)() const) &Standard_Persistent::DynamicType, "None");
cls_Standard_Persistent.def("TypeNum", (Standard_Integer & (Standard_Persistent::*)()) &Standard_Persistent::TypeNum, "None");

// Enums

}