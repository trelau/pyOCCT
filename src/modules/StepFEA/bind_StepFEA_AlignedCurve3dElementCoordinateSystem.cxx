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
#include <StepFEA_AlignedCurve3dElementCoordinateSystem.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_AlignedCurve3dElementCoordinateSystem(py::module &mod){

py::class_<StepFEA_AlignedCurve3dElementCoordinateSystem, opencascade::handle<StepFEA_AlignedCurve3dElementCoordinateSystem>, StepFEA_FeaRepresentationItem> cls_StepFEA_AlignedCurve3dElementCoordinateSystem(mod, "StepFEA_AlignedCurve3dElementCoordinateSystem", "Representation of STEP entity AlignedCurve3dElementCoordinateSystem");

// Constructors
cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def(py::init<>());

// Fields

// Methods
cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def("Init", (void (StepFEA_AlignedCurve3dElementCoordinateSystem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_AlignedCurve3dElementCoordinateSystem::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aCoordinateSystem"));
cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def("CoordinateSystem", (opencascade::handle<StepFEA_FeaAxis2Placement3d> (StepFEA_AlignedCurve3dElementCoordinateSystem::*)() const) &StepFEA_AlignedCurve3dElementCoordinateSystem::CoordinateSystem, "Returns field CoordinateSystem");
cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def("SetCoordinateSystem", (void (StepFEA_AlignedCurve3dElementCoordinateSystem::*)(const opencascade::handle<StepFEA_FeaAxis2Placement3d> &)) &StepFEA_AlignedCurve3dElementCoordinateSystem::SetCoordinateSystem, "Set field CoordinateSystem", py::arg("CoordinateSystem"));
cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def_static("get_type_name_", (const char * (*)()) &StepFEA_AlignedCurve3dElementCoordinateSystem::get_type_name, "None");
cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_AlignedCurve3dElementCoordinateSystem::get_type_descriptor, "None");
cls_StepFEA_AlignedCurve3dElementCoordinateSystem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_AlignedCurve3dElementCoordinateSystem::*)() const) &StepFEA_AlignedCurve3dElementCoordinateSystem::DynamicType, "None");

// Enums

}