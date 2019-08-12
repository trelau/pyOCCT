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
#include <StepRepr_RepresentationItem.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_RepresentationMap.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_RepresentationMap(py::module &mod){

py::class_<StepRepr_RepresentationMap, opencascade::handle<StepRepr_RepresentationMap>, Standard_Transient> cls_StepRepr_RepresentationMap(mod, "StepRepr_RepresentationMap", "None");

// Constructors
cls_StepRepr_RepresentationMap.def(py::init<>());

// Fields

// Methods
cls_StepRepr_RepresentationMap.def("Init", (void (StepRepr_RepresentationMap::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationMap::Init, "None", py::arg("aMappingOrigin"), py::arg("aMappedRepresentation"));
cls_StepRepr_RepresentationMap.def("SetMappingOrigin", (void (StepRepr_RepresentationMap::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_RepresentationMap::SetMappingOrigin, "None", py::arg("aMappingOrigin"));
cls_StepRepr_RepresentationMap.def("MappingOrigin", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_RepresentationMap::*)() const) &StepRepr_RepresentationMap::MappingOrigin, "None");
cls_StepRepr_RepresentationMap.def("SetMappedRepresentation", (void (StepRepr_RepresentationMap::*)(const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationMap::SetMappedRepresentation, "None", py::arg("aMappedRepresentation"));
cls_StepRepr_RepresentationMap.def("MappedRepresentation", (opencascade::handle<StepRepr_Representation> (StepRepr_RepresentationMap::*)() const) &StepRepr_RepresentationMap::MappedRepresentation, "None");
cls_StepRepr_RepresentationMap.def_static("get_type_name_", (const char * (*)()) &StepRepr_RepresentationMap::get_type_name, "None");
cls_StepRepr_RepresentationMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_RepresentationMap::get_type_descriptor, "None");
cls_StepRepr_RepresentationMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_RepresentationMap::*)() const) &StepRepr_RepresentationMap::DynamicType, "None");

// Enums

}