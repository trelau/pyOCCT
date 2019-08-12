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
#include <StepShape_SolidModel.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CartesianTransformationOperator3d.hxx>
#include <StepShape_SolidReplica.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_SolidReplica(py::module &mod){

py::class_<StepShape_SolidReplica, opencascade::handle<StepShape_SolidReplica>, StepShape_SolidModel> cls_StepShape_SolidReplica(mod, "StepShape_SolidReplica", "None");

// Constructors
cls_StepShape_SolidReplica.def(py::init<>());

// Fields

// Methods
cls_StepShape_SolidReplica.def("Init", (void (StepShape_SolidReplica::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepShape_SolidModel> &, const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepShape_SolidReplica::Init, "None", py::arg("aName"), py::arg("aParentSolid"), py::arg("aTransformation"));
cls_StepShape_SolidReplica.def("SetParentSolid", (void (StepShape_SolidReplica::*)(const opencascade::handle<StepShape_SolidModel> &)) &StepShape_SolidReplica::SetParentSolid, "None", py::arg("aParentSolid"));
cls_StepShape_SolidReplica.def("ParentSolid", (opencascade::handle<StepShape_SolidModel> (StepShape_SolidReplica::*)() const) &StepShape_SolidReplica::ParentSolid, "None");
cls_StepShape_SolidReplica.def("SetTransformation", (void (StepShape_SolidReplica::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepShape_SolidReplica::SetTransformation, "None", py::arg("aTransformation"));
cls_StepShape_SolidReplica.def("Transformation", (opencascade::handle<StepGeom_CartesianTransformationOperator3d> (StepShape_SolidReplica::*)() const) &StepShape_SolidReplica::Transformation, "None");
cls_StepShape_SolidReplica.def_static("get_type_name_", (const char * (*)()) &StepShape_SolidReplica::get_type_name, "None");
cls_StepShape_SolidReplica.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_SolidReplica::get_type_descriptor, "None");
cls_StepShape_SolidReplica.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_SolidReplica::*)() const) &StepShape_SolidReplica::DynamicType, "None");

// Enums

}