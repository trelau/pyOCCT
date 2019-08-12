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
#include <StepShape_SweptFaceSolid.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_FaceSurface.hxx>
#include <StepGeom_Axis1Placement.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_RevolvedFaceSolid.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_RevolvedFaceSolid(py::module &mod){

py::class_<StepShape_RevolvedFaceSolid, opencascade::handle<StepShape_RevolvedFaceSolid>, StepShape_SweptFaceSolid> cls_StepShape_RevolvedFaceSolid(mod, "StepShape_RevolvedFaceSolid", "None");

// Constructors
cls_StepShape_RevolvedFaceSolid.def(py::init<>());

// Fields

// Methods
cls_StepShape_RevolvedFaceSolid.def("Init", (void (StepShape_RevolvedFaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_FaceSurface> &)) &StepShape_RevolvedFaceSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"));
cls_StepShape_RevolvedFaceSolid.def("Init", (void (StepShape_RevolvedFaceSolid::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_FaceSurface> &, const opencascade::handle<StepGeom_Axis1Placement> &, const Standard_Real)) &StepShape_RevolvedFaceSolid::Init, "None", py::arg("aName"), py::arg("aSweptArea"), py::arg("aAxis"), py::arg("aAngle"));
cls_StepShape_RevolvedFaceSolid.def("SetAxis", (void (StepShape_RevolvedFaceSolid::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepShape_RevolvedFaceSolid::SetAxis, "None", py::arg("aAxis"));
cls_StepShape_RevolvedFaceSolid.def("Axis", (opencascade::handle<StepGeom_Axis1Placement> (StepShape_RevolvedFaceSolid::*)() const) &StepShape_RevolvedFaceSolid::Axis, "None");
cls_StepShape_RevolvedFaceSolid.def("SetAngle", (void (StepShape_RevolvedFaceSolid::*)(const Standard_Real)) &StepShape_RevolvedFaceSolid::SetAngle, "None", py::arg("aAngle"));
cls_StepShape_RevolvedFaceSolid.def("Angle", (Standard_Real (StepShape_RevolvedFaceSolid::*)() const) &StepShape_RevolvedFaceSolid::Angle, "None");
cls_StepShape_RevolvedFaceSolid.def_static("get_type_name_", (const char * (*)()) &StepShape_RevolvedFaceSolid::get_type_name, "None");
cls_StepShape_RevolvedFaceSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_RevolvedFaceSolid::get_type_descriptor, "None");
cls_StepShape_RevolvedFaceSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_RevolvedFaceSolid::*)() const) &StepShape_RevolvedFaceSolid::DynamicType, "None");

// Enums

}