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
#include <Standard_Type.hxx>

void bind_StepBasic_ApplicationContext(py::module &mod){

py::class_<StepBasic_ApplicationContext, opencascade::handle<StepBasic_ApplicationContext>, Standard_Transient> cls_StepBasic_ApplicationContext(mod, "StepBasic_ApplicationContext", "None");

// Constructors
cls_StepBasic_ApplicationContext.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ApplicationContext.def("Init", (void (StepBasic_ApplicationContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationContext::Init, "None", py::arg("aApplication"));
cls_StepBasic_ApplicationContext.def("SetApplication", (void (StepBasic_ApplicationContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ApplicationContext::SetApplication, "None", py::arg("aApplication"));
cls_StepBasic_ApplicationContext.def("Application", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ApplicationContext::*)() const) &StepBasic_ApplicationContext::Application, "None");
cls_StepBasic_ApplicationContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_ApplicationContext::get_type_name, "None");
cls_StepBasic_ApplicationContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ApplicationContext::get_type_descriptor, "None");
cls_StepBasic_ApplicationContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ApplicationContext::*)() const) &StepBasic_ApplicationContext::DynamicType, "None");

// Enums

}