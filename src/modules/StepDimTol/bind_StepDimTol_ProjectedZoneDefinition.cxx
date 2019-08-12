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
#include <StepRepr_ShapeAspect.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepDimTol_ProjectedZoneDefinition.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_ProjectedZoneDefinition(py::module &mod){

py::class_<StepDimTol_ProjectedZoneDefinition, opencascade::handle<StepDimTol_ProjectedZoneDefinition>, StepDimTol_ToleranceZoneDefinition> cls_StepDimTol_ProjectedZoneDefinition(mod, "StepDimTol_ProjectedZoneDefinition", "Representation of STEP entity ProjectedZoneDefinition");

// Constructors
cls_StepDimTol_ProjectedZoneDefinition.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_ProjectedZoneDefinition.def("Init", (void (StepDimTol_ProjectedZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, const opencascade::handle<StepRepr_HArray1OfShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_ProjectedZoneDefinition::Init, "Initialize all fields (own and inherited)", py::arg("theZone"), py::arg("theBoundaries"), py::arg("theProjectionEnd"), py::arg("theProjectionLength"));
cls_StepDimTol_ProjectedZoneDefinition.def("ProjectionEnd", (opencascade::handle<StepRepr_ShapeAspect> (StepDimTol_ProjectedZoneDefinition::*)() const) &StepDimTol_ProjectedZoneDefinition::ProjectionEnd, "Returns field ProjectionEnd");
cls_StepDimTol_ProjectedZoneDefinition.def("SetProjectionEnd", (void (StepDimTol_ProjectedZoneDefinition::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_ProjectedZoneDefinition::SetProjectionEnd, "Set field ProjectionEnd", py::arg("theProjectionEnd"));
cls_StepDimTol_ProjectedZoneDefinition.def("ProjectionLength", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepDimTol_ProjectedZoneDefinition::*)()) &StepDimTol_ProjectedZoneDefinition::ProjectionLength, "Returns field ProjectionLength");
cls_StepDimTol_ProjectedZoneDefinition.def("SetProjectionLength", (void (StepDimTol_ProjectedZoneDefinition::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepDimTol_ProjectedZoneDefinition::SetProjectionLength, "Set field ProjectionLength", py::arg("theProjectionLength"));
cls_StepDimTol_ProjectedZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ProjectedZoneDefinition::get_type_name, "None");
cls_StepDimTol_ProjectedZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ProjectedZoneDefinition::get_type_descriptor, "None");
cls_StepDimTol_ProjectedZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ProjectedZoneDefinition::*)() const) &StepDimTol_ProjectedZoneDefinition::DynamicType, "None");

// Enums

}