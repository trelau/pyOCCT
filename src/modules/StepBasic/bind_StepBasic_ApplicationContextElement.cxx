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
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ApplicationContext.hxx>
#include <StepBasic_ApplicationContextElement.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ApplicationContextElement(py::module &mod){

py::class_<StepBasic_ApplicationContextElement, opencascade::handle<StepBasic_ApplicationContextElement>, Standard_Transient> cls_StepBasic_ApplicationContextElement(mod, "StepBasic_ApplicationContextElement", "None");

// Constructors
cls_StepBasic_ApplicationContextElement.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ApplicationContextElement.def("Init", (void (StepBasic_ApplicationContextElement::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &)) &StepBasic_ApplicationContextElement::Init, "None", py::arg("aName"), py::arg("aFrameOfReference"));
cls_StepBasic_ApplicationContextElement.def("SetName", (void (StepBasic_ApplicationContextElement::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationContextElement::SetName, "None", py::arg("aName"));
cls_StepBasic_ApplicationContextElement.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApplicationContextElement::*)() const) &StepBasic_ApplicationContextElement::Name, "None");
cls_StepBasic_ApplicationContextElement.def("SetFrameOfReference", (void (StepBasic_ApplicationContextElement::*)(const opencascade::handle<StepBasic_ApplicationContext> &)) &StepBasic_ApplicationContextElement::SetFrameOfReference, "None", py::arg("aFrameOfReference"));
cls_StepBasic_ApplicationContextElement.def("FrameOfReference", (opencascade::handle<StepBasic_ApplicationContext> (StepBasic_ApplicationContextElement::*)() const) &StepBasic_ApplicationContextElement::FrameOfReference, "None");
cls_StepBasic_ApplicationContextElement.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApplicationContextElement::get_type_name, "None");
cls_StepBasic_ApplicationContextElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApplicationContextElement::get_type_descriptor, "None");
cls_StepBasic_ApplicationContextElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApplicationContextElement::*)() const) &StepBasic_ApplicationContextElement::DynamicType, "None");

// Enums

}