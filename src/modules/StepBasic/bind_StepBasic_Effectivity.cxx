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
#include <StepBasic_Effectivity.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_Effectivity(py::module &mod){

py::class_<StepBasic_Effectivity, opencascade::handle<StepBasic_Effectivity>, Standard_Transient> cls_StepBasic_Effectivity(mod, "StepBasic_Effectivity", "None");

// Constructors
cls_StepBasic_Effectivity.def(py::init<>());

// Fields

// Methods
cls_StepBasic_Effectivity.def("Init", (void (StepBasic_Effectivity::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Effectivity::Init, "None", py::arg("aid"));
cls_StepBasic_Effectivity.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_Effectivity::*)() const) &StepBasic_Effectivity::Id, "None");
cls_StepBasic_Effectivity.def("SetId", (void (StepBasic_Effectivity::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_Effectivity::SetId, "None", py::arg("aid"));
cls_StepBasic_Effectivity.def_static("get_type_name_", (const char * (*)()) &StepBasic_Effectivity::get_type_name, "None");
cls_StepBasic_Effectivity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_Effectivity::get_type_descriptor, "None");
cls_StepBasic_Effectivity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_Effectivity::*)() const) &StepBasic_Effectivity::DynamicType, "None");

// Enums

}