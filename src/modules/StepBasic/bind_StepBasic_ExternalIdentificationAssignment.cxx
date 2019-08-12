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
#include <StepBasic_IdentificationAssignment.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_IdentificationRole.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <StepBasic_ExternalIdentificationAssignment.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ExternalIdentificationAssignment(py::module &mod){

py::class_<StepBasic_ExternalIdentificationAssignment, opencascade::handle<StepBasic_ExternalIdentificationAssignment>, StepBasic_IdentificationAssignment> cls_StepBasic_ExternalIdentificationAssignment(mod, "StepBasic_ExternalIdentificationAssignment", "Representation of STEP entity ExternalIdentificationAssignment");

// Constructors
cls_StepBasic_ExternalIdentificationAssignment.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ExternalIdentificationAssignment.def("Init", (void (StepBasic_ExternalIdentificationAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_IdentificationRole> &, const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ExternalIdentificationAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aIdentificationAssignment_AssignedId"), py::arg("aIdentificationAssignment_Role"), py::arg("aSource"));
cls_StepBasic_ExternalIdentificationAssignment.def("Source", (opencascade::handle<StepBasic_ExternalSource> (StepBasic_ExternalIdentificationAssignment::*)() const) &StepBasic_ExternalIdentificationAssignment::Source, "Returns field Source");
cls_StepBasic_ExternalIdentificationAssignment.def("SetSource", (void (StepBasic_ExternalIdentificationAssignment::*)(const opencascade::handle<StepBasic_ExternalSource> &)) &StepBasic_ExternalIdentificationAssignment::SetSource, "Set field Source", py::arg("Source"));
cls_StepBasic_ExternalIdentificationAssignment.def_static("get_type_name_", (const char * (*)()) &StepBasic_ExternalIdentificationAssignment::get_type_name, "None");
cls_StepBasic_ExternalIdentificationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ExternalIdentificationAssignment::get_type_descriptor, "None");
cls_StepBasic_ExternalIdentificationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ExternalIdentificationAssignment::*)() const) &StepBasic_ExternalIdentificationAssignment::DynamicType, "None");

// Enums

}