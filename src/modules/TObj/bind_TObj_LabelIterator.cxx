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
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TObj_Object.hxx>
#include <TDF_ChildIterator.hxx>
#include <TObj_LabelIterator.hxx>
#include <Standard_Type.hxx>

void bind_TObj_LabelIterator(py::module &mod){

py::class_<TObj_LabelIterator, opencascade::handle<TObj_LabelIterator>, TObj_ObjectIterator> cls_TObj_LabelIterator(mod, "TObj_LabelIterator", "This class is a basis for OCAF based iterators.");

// Fields

// Methods
cls_TObj_LabelIterator.def("More", (Standard_Boolean (TObj_LabelIterator::*)() const) &TObj_LabelIterator::More, "Returns True if there is a current Item in the iteration.");
cls_TObj_LabelIterator.def("Next", (void (TObj_LabelIterator::*)()) &TObj_LabelIterator::Next, "Move to the next Item");
cls_TObj_LabelIterator.def("Value", (opencascade::handle<TObj_Object> (TObj_LabelIterator::*)() const) &TObj_LabelIterator::Value, "Returns the current item");
cls_TObj_LabelIterator.def("LabelValue", (const TDF_Label & (TObj_LabelIterator::*)() const) &TObj_LabelIterator::LabelValue, "Returns the label of the current item");
cls_TObj_LabelIterator.def_static("get_type_name_", (const char * (*)()) &TObj_LabelIterator::get_type_name, "None");
cls_TObj_LabelIterator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_LabelIterator::get_type_descriptor, "None");
cls_TObj_LabelIterator.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_LabelIterator::*)() const) &TObj_LabelIterator::DynamicType, "None");

// Enums

}