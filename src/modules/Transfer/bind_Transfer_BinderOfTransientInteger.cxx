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
#include <Transfer_SimpleBinderOfTransient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_BinderOfTransientInteger.hxx>
#include <Standard_Type.hxx>

void bind_Transfer_BinderOfTransientInteger(py::module &mod){

py::class_<Transfer_BinderOfTransientInteger, opencascade::handle<Transfer_BinderOfTransientInteger>, Transfer_SimpleBinderOfTransient> cls_Transfer_BinderOfTransientInteger(mod, "Transfer_BinderOfTransientInteger", "This type of Binder allows to attach as result, besides a Transient Object, an Integer Value, which can be an Index in the Object if it defines a List, for instance");

// Constructors
cls_Transfer_BinderOfTransientInteger.def(py::init<>());

// Fields

// Methods
cls_Transfer_BinderOfTransientInteger.def("SetInteger", (void (Transfer_BinderOfTransientInteger::*)(const Standard_Integer)) &Transfer_BinderOfTransientInteger::SetInteger, "Sets a value for the integer part", py::arg("value"));
cls_Transfer_BinderOfTransientInteger.def("Integer", (Standard_Integer (Transfer_BinderOfTransientInteger::*)() const) &Transfer_BinderOfTransientInteger::Integer, "Returns the value set for the integer part");
cls_Transfer_BinderOfTransientInteger.def_static("get_type_name_", (const char * (*)()) &Transfer_BinderOfTransientInteger::get_type_name, "None");
cls_Transfer_BinderOfTransientInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_BinderOfTransientInteger::get_type_descriptor, "None");
cls_Transfer_BinderOfTransientInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_BinderOfTransientInteger::*)() const) &Transfer_BinderOfTransientInteger::DynamicType, "None");

// Enums

}