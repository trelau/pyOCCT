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
#include <StepFEA_FeaRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepFEA_ParametricSurface3dElementCoordinateSystem.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_ParametricSurface3dElementCoordinateSystem(py::module &mod){

py::class_<StepFEA_ParametricSurface3dElementCoordinateSystem, opencascade::handle<StepFEA_ParametricSurface3dElementCoordinateSystem>, StepFEA_FeaRepresentationItem> cls_StepFEA_ParametricSurface3dElementCoordinateSystem(mod, "StepFEA_ParametricSurface3dElementCoordinateSystem", "Representation of STEP entity ParametricSurface3dElementCoordinateSystem");

// Constructors
cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def(py::init<>());

// Fields

// Methods
cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("Init", (void (StepFEA_ParametricSurface3dElementCoordinateSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Real)) &StepFEA_ParametricSurface3dElementCoordinateSystem::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aAxis"), py::arg("aAngle"));
cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("Axis", (Standard_Integer (StepFEA_ParametricSurface3dElementCoordinateSystem::*)() const) &StepFEA_ParametricSurface3dElementCoordinateSystem::Axis, "Returns field Axis");
cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("SetAxis", (void (StepFEA_ParametricSurface3dElementCoordinateSystem::*)(const Standard_Integer)) &StepFEA_ParametricSurface3dElementCoordinateSystem::SetAxis, "Set field Axis", py::arg("Axis"));
cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("Angle", (Standard_Real (StepFEA_ParametricSurface3dElementCoordinateSystem::*)() const) &StepFEA_ParametricSurface3dElementCoordinateSystem::Angle, "Returns field Angle");
cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("SetAngle", (void (StepFEA_ParametricSurface3dElementCoordinateSystem::*)(const Standard_Real)) &StepFEA_ParametricSurface3dElementCoordinateSystem::SetAngle, "Set field Angle", py::arg("Angle"));
cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_ParametricSurface3dElementCoordinateSystem::get_type_name, "None");
cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_ParametricSurface3dElementCoordinateSystem::get_type_descriptor, "None");
cls_StepFEA_ParametricSurface3dElementCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_ParametricSurface3dElementCoordinateSystem::*)() const) &StepFEA_ParametricSurface3dElementCoordinateSystem::DynamicType, "None");

// Enums

}