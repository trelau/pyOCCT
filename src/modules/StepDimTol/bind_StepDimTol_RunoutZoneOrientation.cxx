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
#include <StepBasic_PlaneAngleMeasureWithUnit.hxx>
#include <StepDimTol_RunoutZoneOrientation.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_RunoutZoneOrientation(py::module &mod){

py::class_<StepDimTol_RunoutZoneOrientation, opencascade::handle<StepDimTol_RunoutZoneOrientation>, Standard_Transient> cls_StepDimTol_RunoutZoneOrientation(mod, "StepDimTol_RunoutZoneOrientation", "Added for Dimensional Tolerances");

// Constructors
cls_StepDimTol_RunoutZoneOrientation.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_RunoutZoneOrientation.def("Init", (void (StepDimTol_RunoutZoneOrientation::*)(const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &)) &StepDimTol_RunoutZoneOrientation::Init, "Init all field own and inherited", py::arg("theAngle"));
cls_StepDimTol_RunoutZoneOrientation.def("Angle", (opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> (StepDimTol_RunoutZoneOrientation::*)()) &StepDimTol_RunoutZoneOrientation::Angle, "Returns field Angle");
cls_StepDimTol_RunoutZoneOrientation.def("SetAngle", (void (StepDimTol_RunoutZoneOrientation::*)(const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &)) &StepDimTol_RunoutZoneOrientation::SetAngle, "Set field Angle", py::arg("theAngle"));
cls_StepDimTol_RunoutZoneOrientation.def_static("get_type_name_", (const char * (*)()) &StepDimTol_RunoutZoneOrientation::get_type_name, "None");
cls_StepDimTol_RunoutZoneOrientation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_RunoutZoneOrientation::get_type_descriptor, "None");
cls_StepDimTol_RunoutZoneOrientation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_RunoutZoneOrientation::*)() const) &StepDimTol_RunoutZoneOrientation::DynamicType, "None");

// Enums

}