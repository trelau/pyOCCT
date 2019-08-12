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
#include <StepShape_TypeQualifier.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_TypeQualifier(py::module &mod){

py::class_<StepShape_TypeQualifier, opencascade::handle<StepShape_TypeQualifier>, Standard_Transient> cls_StepShape_TypeQualifier(mod, "StepShape_TypeQualifier", "Added for Dimensional Tolerances");

// Constructors
cls_StepShape_TypeQualifier.def(py::init<>());

// Fields

// Methods
cls_StepShape_TypeQualifier.def("Init", (void (StepShape_TypeQualifier::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_TypeQualifier::Init, "None", py::arg("name"));
cls_StepShape_TypeQualifier.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepShape_TypeQualifier::*)() const) &StepShape_TypeQualifier::Name, "None");
cls_StepShape_TypeQualifier.def("SetName", (void (StepShape_TypeQualifier::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepShape_TypeQualifier::SetName, "None", py::arg("name"));
cls_StepShape_TypeQualifier.def_static("get_type_name_", (const char * (*)()) &StepShape_TypeQualifier::get_type_name, "None");
cls_StepShape_TypeQualifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_TypeQualifier::get_type_descriptor, "None");
cls_StepShape_TypeQualifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_TypeQualifier::*)() const) &StepShape_TypeQualifier::DynamicType, "None");

// Enums

}