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
#include <StepElement_HArray1OfSurfaceSection.hxx>
#include <Standard_TypeDef.hxx>
#include <StepElement_SurfaceSectionFieldVarying.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_SurfaceSectionFieldVarying(py::module &mod){

py::class_<StepElement_SurfaceSectionFieldVarying, opencascade::handle<StepElement_SurfaceSectionFieldVarying>, StepElement_SurfaceSectionField> cls_StepElement_SurfaceSectionFieldVarying(mod, "StepElement_SurfaceSectionFieldVarying", "Representation of STEP entity SurfaceSectionFieldVarying");

// Constructors
cls_StepElement_SurfaceSectionFieldVarying.def(py::init<>());

// Fields

// Methods
cls_StepElement_SurfaceSectionFieldVarying.def("Init", (void (StepElement_SurfaceSectionFieldVarying::*)(const opencascade::handle<StepElement_HArray1OfSurfaceSection> &, const Standard_Boolean)) &StepElement_SurfaceSectionFieldVarying::Init, "Initialize all fields (own and inherited)", py::arg("aDefinitions"), py::arg("aAdditionalNodeValues"));
cls_StepElement_SurfaceSectionFieldVarying.def("Definitions", (opencascade::handle<StepElement_HArray1OfSurfaceSection> (StepElement_SurfaceSectionFieldVarying::*)() const) &StepElement_SurfaceSectionFieldVarying::Definitions, "Returns field Definitions");
cls_StepElement_SurfaceSectionFieldVarying.def("SetDefinitions", (void (StepElement_SurfaceSectionFieldVarying::*)(const opencascade::handle<StepElement_HArray1OfSurfaceSection> &)) &StepElement_SurfaceSectionFieldVarying::SetDefinitions, "Set field Definitions", py::arg("Definitions"));
cls_StepElement_SurfaceSectionFieldVarying.def("AdditionalNodeValues", (Standard_Boolean (StepElement_SurfaceSectionFieldVarying::*)() const) &StepElement_SurfaceSectionFieldVarying::AdditionalNodeValues, "Returns field AdditionalNodeValues");
cls_StepElement_SurfaceSectionFieldVarying.def("SetAdditionalNodeValues", (void (StepElement_SurfaceSectionFieldVarying::*)(const Standard_Boolean)) &StepElement_SurfaceSectionFieldVarying::SetAdditionalNodeValues, "Set field AdditionalNodeValues", py::arg("AdditionalNodeValues"));
cls_StepElement_SurfaceSectionFieldVarying.def_static("get_type_name_", (const char * (*)()) &StepElement_SurfaceSectionFieldVarying::get_type_name, "None");
cls_StepElement_SurfaceSectionFieldVarying.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_SurfaceSectionFieldVarying::get_type_descriptor, "None");
cls_StepElement_SurfaceSectionFieldVarying.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_SurfaceSectionFieldVarying::*)() const) &StepElement_SurfaceSectionFieldVarying::DynamicType, "None");

// Enums

}