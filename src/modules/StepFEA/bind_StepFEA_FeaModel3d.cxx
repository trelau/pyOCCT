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
#include <StepFEA_FeaModel.hxx>
#include <Standard_Handle.hxx>
#include <StepFEA_FeaModel3d.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaModel3d(py::module &mod){

py::class_<StepFEA_FeaModel3d, opencascade::handle<StepFEA_FeaModel3d>, StepFEA_FeaModel> cls_StepFEA_FeaModel3d(mod, "StepFEA_FeaModel3d", "Representation of STEP entity FeaModel3d");

// Constructors
cls_StepFEA_FeaModel3d.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaModel3d.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaModel3d::get_type_name, "None");
cls_StepFEA_FeaModel3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaModel3d::get_type_descriptor, "None");
cls_StepFEA_FeaModel3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaModel3d::*)() const) &StepFEA_FeaModel3d::DynamicType, "None");

// Enums

}