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
#include <StepBasic_ApplicationContextElement.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ApplicationContext.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinitionContext(py::module &mod){

py::class_<StepBasic_ProductDefinitionContext, opencascade::handle<StepBasic_ProductDefinitionContext>, StepBasic_ApplicationContextElement> cls_StepBasic_ProductDefinitionContext(mod, "StepBasic_ProductDefinitionContext", "None");

// Constructors
cls_StepBasic_ProductDefinitionContext.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinitionContext.def("Init", (void (StepBasic_ProductDefinitionContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionContext::Init, "None", py::arg("aName"), py::arg("aFrameOfReference"), py::arg("aLifeCycleStage"));
cls_StepBasic_ProductDefinitionContext.def("SetLifeCycleStage", (void (StepBasic_ProductDefinitionContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionContext::SetLifeCycleStage, "None", py::arg("aLifeCycleStage"));
cls_StepBasic_ProductDefinitionContext.def("LifeCycleStage", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionContext::*)() const) &StepBasic_ProductDefinitionContext::LifeCycleStage, "None");
cls_StepBasic_ProductDefinitionContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionContext::get_type_name, "None");
cls_StepBasic_ProductDefinitionContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionContext::get_type_descriptor, "None");
cls_StepBasic_ProductDefinitionContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionContext::*)() const) &StepBasic_ProductDefinitionContext::DynamicType, "None");

// Enums

}