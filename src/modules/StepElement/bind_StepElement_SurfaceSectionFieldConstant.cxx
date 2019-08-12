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
#include <StepElement_SurfaceSectionField.hxx>
#include <Standard_Handle.hxx>
#include <StepElement_SurfaceSection.hxx>
#include <StepElement_SurfaceSectionFieldConstant.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_SurfaceSectionFieldConstant(py::module &mod){

py::class_<StepElement_SurfaceSectionFieldConstant, opencascade::handle<StepElement_SurfaceSectionFieldConstant>, StepElement_SurfaceSectionField> cls_StepElement_SurfaceSectionFieldConstant(mod, "StepElement_SurfaceSectionFieldConstant", "Representation of STEP entity SurfaceSectionFieldConstant");

// Constructors
cls_StepElement_SurfaceSectionFieldConstant.def(py::init<>());

// Fields

// Methods
cls_StepElement_SurfaceSectionFieldConstant.def("Init", (void (StepElement_SurfaceSectionFieldConstant::*)(const opencascade::handle<StepElement_SurfaceSection> &)) &StepElement_SurfaceSectionFieldConstant::Init, "Initialize all fields (own and inherited)", py::arg("aDefinition"));
cls_StepElement_SurfaceSectionFieldConstant.def("Definition", (opencascade::handle<StepElement_SurfaceSection> (StepElement_SurfaceSectionFieldConstant::*)() const) &StepElement_SurfaceSectionFieldConstant::Definition, "Returns field Definition");
cls_StepElement_SurfaceSectionFieldConstant.def("SetDefinition", (void (StepElement_SurfaceSectionFieldConstant::*)(const opencascade::handle<StepElement_SurfaceSection> &)) &StepElement_SurfaceSectionFieldConstant::SetDefinition, "Set field Definition", py::arg("Definition"));
cls_StepElement_SurfaceSectionFieldConstant.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceSectionFieldConstant::get_type_name, "None");
cls_StepElement_SurfaceSectionFieldConstant.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceSectionFieldConstant::get_type_descriptor, "None");
cls_StepElement_SurfaceSectionFieldConstant.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceSectionFieldConstant::*)() const) &StepElement_SurfaceSectionFieldConstant::DynamicType, "None");

// Enums

}