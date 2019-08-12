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
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelNodePtr.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_AttributeIterator.hxx>

void bind_TDF_AttributeIterator(py::module &mod){

py::class_<TDF_AttributeIterator, std::unique_ptr<TDF_AttributeIterator, Deleter<TDF_AttributeIterator>>> cls_TDF_AttributeIterator(mod, "TDF_AttributeIterator", "None");

// Constructors
cls_TDF_AttributeIterator.def(py::init<>());
cls_TDF_AttributeIterator.def(py::init<const TDF_Label &>(), py::arg("aLabel"));
cls_TDF_AttributeIterator.def(py::init<const TDF_Label &, const Standard_Boolean>(), py::arg("aLabel"), py::arg("withoutForgotten"));
cls_TDF_AttributeIterator.def(py::init<const TDF_LabelNodePtr>(), py::arg("aLabelNode"));
cls_TDF_AttributeIterator.def(py::init<const TDF_LabelNodePtr, const Standard_Boolean>(), py::arg("aLabelNode"), py::arg("withoutForgotten"));

// Fields

// Methods
cls_TDF_AttributeIterator.def("Initialize", [](TDF_AttributeIterator &self, const TDF_Label & a0) -> void { return self.Initialize(a0); });
cls_TDF_AttributeIterator.def("Initialize", (void (TDF_AttributeIterator::*)(const TDF_Label &, const Standard_Boolean)) &TDF_AttributeIterator::Initialize, "None", py::arg("aLabel"), py::arg("withoutForgotten"));
cls_TDF_AttributeIterator.def("More", (Standard_Boolean (TDF_AttributeIterator::*)() const) &TDF_AttributeIterator::More, "None");
cls_TDF_AttributeIterator.def("Next", (void (TDF_AttributeIterator::*)()) &TDF_AttributeIterator::Next, "None");
cls_TDF_AttributeIterator.def("Value", (opencascade::handle<TDF_Attribute> (TDF_AttributeIterator::*)() const) &TDF_AttributeIterator::Value, "None");

// Enums

}