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
#include <StepBasic_ProductContext.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductContext(py::module &mod){

py::class_<StepBasic_ProductContext, opencascade::handle<StepBasic_ProductContext>, StepBasic_ApplicationContextElement> cls_StepBasic_ProductContext(mod, "StepBasic_ProductContext", "None");

// Constructors
cls_StepBasic_ProductContext.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductContext.def("Init", (void (StepBasic_ProductContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductContext::Init, "None", py::arg("aName"), py::arg("aFrameOfReference"), py::arg("aDisciplineType"));
cls_StepBasic_ProductContext.def("SetDisciplineType", (void (StepBasic_ProductContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductContext::SetDisciplineType, "None", py::arg("aDisciplineType"));
cls_StepBasic_ProductContext.def("DisciplineType", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductContext::*)() const) &StepBasic_ProductContext::DisciplineType, "None");
cls_StepBasic_ProductContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductContext::get_type_name, "None");
cls_StepBasic_ProductContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductContext::get_type_descriptor, "None");
cls_StepBasic_ProductContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductContext::*)() const) &StepBasic_ProductContext::DynamicType, "None");

// Enums

}