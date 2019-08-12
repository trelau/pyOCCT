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
#include <StepDimTol_ToleranceZone.hxx>
#include <StepRepr_HArray1OfShapeAspect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_ToleranceZoneDefinition.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_ToleranceZoneDefinition(py::module &mod){

py::class_<StepDimTol_ToleranceZoneDefinition, opencascade::handle<StepDimTol_ToleranceZoneDefinition>, Standard_Transient> cls_StepDimTol_ToleranceZoneDefinition(mod, "StepDimTol_ToleranceZoneDefinition", "Representation of STEP entity ToleranceZoneDefinition");

// Constructors
cls_StepDimTol_ToleranceZoneDefinition.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_ToleranceZoneDefinition.def("Init", (void (StepDimTol_ToleranceZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &, const opencascade::handle<StepRepr_HArray1OfShapeAspect> &)) &StepDimTol_ToleranceZoneDefinition::Init, "Initialize all fields (own and inherited)", py::arg("theZone"), py::arg("theBoundaries"));
cls_StepDimTol_ToleranceZoneDefinition.def("Boundaries", (opencascade::handle<StepRepr_HArray1OfShapeAspect> (StepDimTol_ToleranceZoneDefinition::*)() const) &StepDimTol_ToleranceZoneDefinition::Boundaries, "Returns field Boundaries");
cls_StepDimTol_ToleranceZoneDefinition.def("SetBoundaries", (void (StepDimTol_ToleranceZoneDefinition::*)(const opencascade::handle<StepRepr_HArray1OfShapeAspect> &)) &StepDimTol_ToleranceZoneDefinition::SetBoundaries, "Set field Boundaries", py::arg("theBoundaries"));
cls_StepDimTol_ToleranceZoneDefinition.def("NbBoundaries", (Standard_Integer (StepDimTol_ToleranceZoneDefinition::*)() const) &StepDimTol_ToleranceZoneDefinition::NbBoundaries, "Returns number of Boundaries");
cls_StepDimTol_ToleranceZoneDefinition.def("BoundariesValue", (opencascade::handle<StepRepr_ShapeAspect> (StepDimTol_ToleranceZoneDefinition::*)(const Standard_Integer) const) &StepDimTol_ToleranceZoneDefinition::BoundariesValue, "Returns Boundaries with the given number", py::arg("theNum"));
cls_StepDimTol_ToleranceZoneDefinition.def("SetBoundariesValue", (void (StepDimTol_ToleranceZoneDefinition::*)(const Standard_Integer, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepDimTol_ToleranceZoneDefinition::SetBoundariesValue, "Sets Boundaries with given number", py::arg("theNum"), py::arg("theItem"));
cls_StepDimTol_ToleranceZoneDefinition.def("Zone", (opencascade::handle<StepDimTol_ToleranceZone> (StepDimTol_ToleranceZoneDefinition::*)()) &StepDimTol_ToleranceZoneDefinition::Zone, "Returns field Zone");
cls_StepDimTol_ToleranceZoneDefinition.def("SetZone", (void (StepDimTol_ToleranceZoneDefinition::*)(const opencascade::handle<StepDimTol_ToleranceZone> &)) &StepDimTol_ToleranceZoneDefinition::SetZone, "Set field Zone", py::arg("theZone"));
cls_StepDimTol_ToleranceZoneDefinition.def_static("get_type_name_", (const char * (*)()) &StepDimTol_ToleranceZoneDefinition::get_type_name, "None");
cls_StepDimTol_ToleranceZoneDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_ToleranceZoneDefinition::get_type_descriptor, "None");
cls_StepDimTol_ToleranceZoneDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_ToleranceZoneDefinition::*)() const) &StepDimTol_ToleranceZoneDefinition::DynamicType, "None");

// Enums

}