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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_PresentationArea.hxx>
#include <StepVisual_PresentationSet.hxx>
#include <StepVisual_AreaInSet.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_AreaInSet(py::module &mod){

py::class_<StepVisual_AreaInSet, opencascade::handle<StepVisual_AreaInSet>, Standard_Transient> cls_StepVisual_AreaInSet(mod, "StepVisual_AreaInSet", "None");

// Constructors
cls_StepVisual_AreaInSet.def(py::init<>());

// Fields

// Methods
cls_StepVisual_AreaInSet.def("Init", (void (StepVisual_AreaInSet::*)(const opencascade::handle<StepVisual_PresentationArea> &, const opencascade::handle<StepVisual_PresentationSet> &)) &StepVisual_AreaInSet::Init, "None", py::arg("aArea"), py::arg("aInSet"));
cls_StepVisual_AreaInSet.def("SetArea", (void (StepVisual_AreaInSet::*)(const opencascade::handle<StepVisual_PresentationArea> &)) &StepVisual_AreaInSet::SetArea, "None", py::arg("aArea"));
cls_StepVisual_AreaInSet.def("Area", (opencascade::handle<StepVisual_PresentationArea> (StepVisual_AreaInSet::*)() const) &StepVisual_AreaInSet::Area, "None");
cls_StepVisual_AreaInSet.def("SetInSet", (void (StepVisual_AreaInSet::*)(const opencascade::handle<StepVisual_PresentationSet> &)) &StepVisual_AreaInSet::SetInSet, "None", py::arg("aInSet"));
cls_StepVisual_AreaInSet.def("InSet", (opencascade::handle<StepVisual_PresentationSet> (StepVisual_AreaInSet::*)() const) &StepVisual_AreaInSet::InSet, "None");
cls_StepVisual_AreaInSet.def_static("get_type_name_", (const char * (*)()) &StepVisual_AreaInSet::get_type_name, "None");
cls_StepVisual_AreaInSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AreaInSet::get_type_descriptor, "None");
cls_StepVisual_AreaInSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AreaInSet::*)() const) &StepVisual_AreaInSet::DynamicType, "None");

// Enums

}