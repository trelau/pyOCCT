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
#include <StepDimTol_ToleranceZoneDefinition.hxx>
#include <Standard_Handle.hxx>
#include <StepDimTol_ToleranceZone.hxx>
#include <StepRepr_HArray1OfShapeAspect.hxx>
#include <StepDimTol_RunoutZoneOrientation.hxx>
#include <StepDimTol_RunoutZoneDefinition.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_RunoutZoneDefinition(py::module &mod){

py::class_<StepDimTol_RunoutZoneDefinition, opencascade::handle<StepDimTol_RunoutZoneDefinition>, StepDimTol_ToleranceZoneDefinition> cls_StepDimTol_RunoutZoneDefinition(mod, "StepDimTol_RunoutZoneDefinition", "Representation of STEP entity ToleranceZoneDefinition");

// Constructors
cls_StepDimTol_RunoutZoneDefinition.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_RunoutZoneDefinition.def("Init", (void (StepDimTol_RunoutZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, const opencascade::handle<StepRepr_HArray1OfShapeAspect> &, const opencascade::handle<StepDimTol_RunoutZoneOrientation> &)) &StepDimTol_RunoutZoneDefinition::Init, "Initialize all fields (own and inherited)", py::arg("theZone"), py::arg("theBoundaries"), py::arg("theOrientation"));
cls_StepDimTol_RunoutZoneDefinition.def("Orientation", (opencascade::handle<StepDimTol_RunoutZoneOrientation> (StepDimTol_RunoutZoneDefinition::*)() const) &StepDimTol_RunoutZoneDefinition::Orientation, "Returns field Orientation");
cls_StepDimTol_RunoutZoneDefinition.def("SetOrientation", (void (StepDimTol_RunoutZoneDefinition::*)(const opencascade::handle<StepDimTol_RunoutZoneOrientation> &)) &StepDimTol_RunoutZoneDefinition::SetOrientation, "Set field Orientation", py::arg("theOrientation"));
cls_StepDimTol_RunoutZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_RunoutZoneDefinition::get_type_name, "None");
cls_StepDimTol_RunoutZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_RunoutZoneDefinition::get_type_descriptor, "None");
cls_StepDimTol_RunoutZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_RunoutZoneDefinition::*)() const) &StepDimTol_RunoutZoneDefinition::DynamicType, "None");

// Enums

}