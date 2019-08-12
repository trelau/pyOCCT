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
#include <StepFEA_FeaAxis2Placement3d.hxx>
#include <StepFEA_AlignedSurface3dElementCoordinateSystem.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_AlignedSurface3dElementCoordinateSystem(py::module &mod){

py::class_<StepFEA_AlignedSurface3dElementCoordinateSystem, opencascade::handle<StepFEA_AlignedSurface3dElementCoordinateSystem>, StepFEA_FeaRepresentationItem> cls_StepFEA_AlignedSurface3dElementCoordinateSystem(mod, "StepFEA_AlignedSurface3dElementCoordinateSystem", "Representation of STEP entity AlignedSurface3dElementCoordinateSystem");

// Constructors
cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def(py::init<>());

// Fields

// Methods
cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def("Init", (void (StepFEA_AlignedSurface3dElementCoordinateSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_AlignedSurface3dElementCoordinateSystem::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aCoordinateSystem"));
cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def("CoordinateSystem", (opencascade::handle<StepFEA_FeaAxis2Placement3d> (StepFEA_AlignedSurface3dElementCoordinateSystem::*)() const) &StepFEA_AlignedSurface3dElementCoordinateSystem::CoordinateSystem, "Returns field CoordinateSystem");
cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def("SetCoordinateSystem", (void (StepFEA_AlignedSurface3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_AlignedSurface3dElementCoordinateSystem::SetCoordinateSystem, "Set field CoordinateSystem", py::arg("CoordinateSystem"));
cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_AlignedSurface3dElementCoordinateSystem::get_type_name, "None");
cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_AlignedSurface3dElementCoordinateSystem::get_type_descriptor, "None");
cls_StepFEA_AlignedSurface3dElementCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_AlignedSurface3dElementCoordinateSystem::*)() const) &StepFEA_AlignedSurface3dElementCoordinateSystem::DynamicType, "None");

// Enums

}