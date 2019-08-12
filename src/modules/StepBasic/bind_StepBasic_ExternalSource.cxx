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
#include <StepBasic_SourceItem.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_ExternalSource.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ExternalSource(py::module &mod){

py::class_<StepBasic_ExternalSource, opencascade::handle<StepBasic_ExternalSource>, Standard_Transient> cls_StepBasic_ExternalSource(mod, "StepBasic_ExternalSource", "Representation of STEP entity ExternalSource");

// Constructors
cls_StepBasic_ExternalSource.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ExternalSource.def("Init", (void (StepBasic_ExternalSource::*)(const StepBasic_SourceItem &)) &StepBasic_ExternalSource::Init, "Initialize all fields (own and inherited)", py::arg("aSourceId"));
cls_StepBasic_ExternalSource.def("SourceId", (StepBasic_SourceItem (StepBasic_ExternalSource::*)() const) &StepBasic_ExternalSource::SourceId, "Returns field SourceId");
cls_StepBasic_ExternalSource.def("SetSourceId", (void (StepBasic_ExternalSource::*)(const StepBasic_SourceItem &)) &StepBasic_ExternalSource::SetSourceId, "Set field SourceId", py::arg("SourceId"));
cls_StepBasic_ExternalSource.def_static("get_type_name_", (const char * (*)()) &StepBasic_ExternalSource::get_type_name, "None");
cls_StepBasic_ExternalSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ExternalSource::get_type_descriptor, "None");
cls_StepBasic_ExternalSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ExternalSource::*)() const) &StepBasic_ExternalSource::DynamicType, "None");

// Enums

}