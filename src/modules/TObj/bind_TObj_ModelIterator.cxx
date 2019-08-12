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
#include <TObj_ObjectIterator.hxx>
#include <Standard_Handle.hxx>
#include <TObj_Model.hxx>
#include <Standard_TypeDef.hxx>
#include <TObj_Object.hxx>
#include <TObj_SequenceOfIterator.hxx>
#include <TObj_ModelIterator.hxx>
#include <Standard_Type.hxx>

void bind_TObj_ModelIterator(py::module &mod){

py::class_<TObj_ModelIterator, opencascade::handle<TObj_ModelIterator>, TObj_ObjectIterator> cls_TObj_ModelIterator(mod, "TObj_ModelIterator", "This class provides an iterator by all objects in the model.");

// Constructors
cls_TObj_ModelIterator.def(py::init<const opencascade::handle<TObj_Model> &>(), py::arg("theModel"));

// Fields

// Methods
cls_TObj_ModelIterator.def("More", (Standard_Boolean (TObj_ModelIterator::*)() const) &TObj_ModelIterator::More, "Returns True if iteration is not finished and method Value() will give the object");
cls_TObj_ModelIterator.def("Next", (void (TObj_ModelIterator::*)()) &TObj_ModelIterator::Next, "Iterates to the next object");
cls_TObj_ModelIterator.def("Value", (opencascade::handle<TObj_Object> (TObj_ModelIterator::*)() const) &TObj_ModelIterator::Value, "Returns current object (or MainObj of Model if iteration has finished)");
cls_TObj_ModelIterator.def_static("get_type_name_", (const char * (*)()) &TObj_ModelIterator::get_type_name, "None");
cls_TObj_ModelIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_ModelIterator::get_type_descriptor, "None");
cls_TObj_ModelIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_ModelIterator::*)() const) &TObj_ModelIterator::DynamicType, "None");

// Enums

}