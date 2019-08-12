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
#include <StepShape_SweptAreaSolid.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CurveBoundedSurface.hxx>
#include <StepGeom_Axis1Placement.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_RevolvedAreaSolid.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_RevolvedAreaSolid(py::module &mod){

py::class_<StepShape_RevolvedAreaSolid, opencascade::handle<StepShape_RevolvedAreaSolid>, StepShape_SweptAreaSolid> cls_StepShape_RevolvedAreaSolid(mod, "StepShape_RevolvedAreaSolid", "None");

// Constructors
cls_StepShape_RevolvedAreaSolid.def(py::init<>());

// Fields

// Methods
cls_StepShape_RevolvedAreaSolid.def("Init", (void (StepShape_RevolvedAreaSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CurveBoundedSurface> &, const opencascade::handle<StepGeom_Axis1Placement> &, const Standard_Real)) &StepShape_RevolvedAreaSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"), py::arg("aAxis"), py::arg("aAngle"));
cls_StepShape_RevolvedAreaSolid.def("SetAxis", (void (StepShape_RevolvedAreaSolid::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepShape_RevolvedAreaSolid::SetAxis, "None", py::arg("aAxis"));
cls_StepShape_RevolvedAreaSolid.def("Axis", (opencascade::handle<StepGeom_Axis1Placement> (StepShape_RevolvedAreaSolid::*)() const) &StepShape_RevolvedAreaSolid::Axis, "None");
cls_StepShape_RevolvedAreaSolid.def("SetAngle", (void (StepShape_RevolvedAreaSolid::*)(const Standard_Real)) &StepShape_RevolvedAreaSolid::SetAngle, "None", py::arg("aAngle"));
cls_StepShape_RevolvedAreaSolid.def("Angle", (Standard_Real (StepShape_RevolvedAreaSolid::*)() const) &StepShape_RevolvedAreaSolid::Angle, "None");
cls_StepShape_RevolvedAreaSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_RevolvedAreaSolid::get_type_name, "None");
cls_StepShape_RevolvedAreaSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_RevolvedAreaSolid::get_type_descriptor, "None");
cls_StepShape_RevolvedAreaSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_RevolvedAreaSolid::*)() const) &StepShape_RevolvedAreaSolid::DynamicType, "None");

// Enums

}