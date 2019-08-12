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
#include <TObj_Object.hxx>
#include <TObj_ObjectIterator.hxx>
#include <Standard_Type.hxx>

void bind_TObj_ObjectIterator(py::module &mod){

py::class_<TObj_ObjectIterator, opencascade::handle<TObj_ObjectIterator>, Standard_Transient> cls_TObj_ObjectIterator(mod, "TObj_ObjectIterator", "This class provides an iterator by objects in a partition. (implements TObj_ObjectIterator interface)");

// Constructors

// Fields

// Methods
cls_TObj_ObjectIterator.def("More", (Standard_Boolean (TObj_ObjectIterator::*)() const) &TObj_ObjectIterator::More, "Returns True if iteration is not finished and method Current() will give the object. Default implementation returns False");
cls_TObj_ObjectIterator.def("Next", (void (TObj_ObjectIterator::*)()) &TObj_ObjectIterator::Next, "Iterates to the next object Default implementation does nothing");
cls_TObj_ObjectIterator.def("Value", (opencascade::handle<TObj_Object> (TObj_ObjectIterator::*)() const) &TObj_ObjectIterator::Value, "Returns current object (or null if iteration has finished) Default implementation returns null handle");
cls_TObj_ObjectIterator.def_static("get_type_name_", (const char * (*)()) &TObj_ObjectIterator::get_type_name, "None");
cls_TObj_ObjectIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_ObjectIterator::get_type_descriptor, "None");
cls_TObj_ObjectIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_ObjectIterator::*)() const) &TObj_ObjectIterator::DynamicType, "None");

// Enums

}