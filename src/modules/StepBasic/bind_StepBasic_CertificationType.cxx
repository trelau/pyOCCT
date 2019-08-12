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
#include <StepBasic_CertificationType.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_CertificationType(py::module &mod){

py::class_<StepBasic_CertificationType, opencascade::handle<StepBasic_CertificationType>, Standard_Transient> cls_StepBasic_CertificationType(mod, "StepBasic_CertificationType", "Representation of STEP entity CertificationType");

// Constructors
cls_StepBasic_CertificationType.def(py::init<>());

// Fields

// Methods
cls_StepBasic_CertificationType.def("Init", (void (StepBasic_CertificationType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_CertificationType::Init, "Initialize all fields (own and inherited)", py::arg("aDescription"));
cls_StepBasic_CertificationType.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_CertificationType::*)() const) &StepBasic_CertificationType::Description, "Returns field Description");
cls_StepBasic_CertificationType.def("SetDescription", (void (StepBasic_CertificationType::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_CertificationType::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_CertificationType.def_static("get_type_name_", (const char * (*)()) &StepBasic_CertificationType::get_type_name, "None");
cls_StepBasic_CertificationType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_CertificationType::get_type_descriptor, "None");
cls_StepBasic_CertificationType.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_CertificationType::*)() const) &StepBasic_CertificationType::DynamicType, "None");

// Enums

}