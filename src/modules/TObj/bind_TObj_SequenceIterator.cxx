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
#include <TObj_SequenceOfObject.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TObj_Object.hxx>
#include <TObj_SequenceIterator.hxx>

void bind_TObj_SequenceIterator(py::module &mod){

py::class_<TObj_SequenceIterator, opencascade::handle<TObj_SequenceIterator>, TObj_ObjectIterator> cls_TObj_SequenceIterator(mod, "TObj_SequenceIterator", "This class is an iterator on sequence");

// Constructors
cls_TObj_SequenceIterator.def(py::init<const opencascade::handle<TObj_HSequenceOfObject> &>(), py::arg("theObjects"));
cls_TObj_SequenceIterator.def(py::init<const opencascade::handle<TObj_HSequenceOfObject> &, const opencascade::handle<Standard_Type> &>(), py::arg("theObjects"), py::arg("theType"));

// Fields

// Methods
cls_TObj_SequenceIterator.def("More", (Standard_Boolean (TObj_SequenceIterator::*)() const) &TObj_SequenceIterator::More, "Returns True if there is a current Item in the iteration.");
cls_TObj_SequenceIterator.def("Next", (void (TObj_SequenceIterator::*)()) &TObj_SequenceIterator::Next, "Move to the next Item");
cls_TObj_SequenceIterator.def("Value", (opencascade::handle<TObj_Object> (TObj_SequenceIterator::*)() const) &TObj_SequenceIterator::Value, "Returns the current item");
cls_TObj_SequenceIterator.def_static("get_type_name_", (const char * (*)()) &TObj_SequenceIterator::get_type_name, "None");
cls_TObj_SequenceIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_SequenceIterator::get_type_descriptor, "None");
cls_TObj_SequenceIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_SequenceIterator::*)() const) &TObj_SequenceIterator::DynamicType, "None");

// Enums

}