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
#include <StepRepr_ShapeAspect.hxx>
#include <Standard_Handle.hxx>
#include <StepFEA_FeaModelDefinition.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaModelDefinition(py::module &mod){

py::class_<StepFEA_FeaModelDefinition, opencascade::handle<StepFEA_FeaModelDefinition>, StepRepr_ShapeAspect> cls_StepFEA_FeaModelDefinition(mod, "StepFEA_FeaModelDefinition", "Representation of STEP entity FeaModelDefinition");

// Constructors
cls_StepFEA_FeaModelDefinition.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaModelDefinition.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaModelDefinition::get_type_name, "None");
cls_StepFEA_FeaModelDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaModelDefinition::get_type_descriptor, "None");
cls_StepFEA_FeaModelDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaModelDefinition::*)() const) &StepFEA_FeaModelDefinition::DynamicType, "None");

// Enums

}