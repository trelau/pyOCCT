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
#include <StepVisual_PresentationLayerAssignment.hxx>
#include <StepVisual_PresentationRepresentation.hxx>
#include <StepVisual_PresentationLayerUsage.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_PresentationLayerUsage(py::module &mod){

py::class_<StepVisual_PresentationLayerUsage, opencascade::handle<StepVisual_PresentationLayerUsage>, Standard_Transient> cls_StepVisual_PresentationLayerUsage(mod, "StepVisual_PresentationLayerUsage", "Added from StepVisual Rev2 to Rev4");

// Constructors
cls_StepVisual_PresentationLayerUsage.def(py::init<>());

// Fields

// Methods
cls_StepVisual_PresentationLayerUsage.def("Init", (void (StepVisual_PresentationLayerUsage::*)(const opencascade::handle<StepVisual_PresentationLayerAssignment> &, const opencascade::handle<StepVisual_PresentationRepresentation> &)) &StepVisual_PresentationLayerUsage::Init, "None", py::arg("aAssignment"), py::arg("aPresentation"));
cls_StepVisual_PresentationLayerUsage.def("SetAssignment", (void (StepVisual_PresentationLayerUsage::*)(const opencascade::handle<StepVisual_PresentationLayerAssignment> &)) &StepVisual_PresentationLayerUsage::SetAssignment, "None", py::arg("aAssignment"));
cls_StepVisual_PresentationLayerUsage.def("Assignment", (opencascade::handle<StepVisual_PresentationLayerAssignment> (StepVisual_PresentationLayerUsage::*)() const) &StepVisual_PresentationLayerUsage::Assignment, "None");
cls_StepVisual_PresentationLayerUsage.def("SetPresentation", (void (StepVisual_PresentationLayerUsage::*)(const opencascade::handle<StepVisual_PresentationRepresentation> &)) &StepVisual_PresentationLayerUsage::SetPresentation, "None", py::arg("aPresentation"));
cls_StepVisual_PresentationLayerUsage.def("Presentation", (opencascade::handle<StepVisual_PresentationRepresentation> (StepVisual_PresentationLayerUsage::*)() const) &StepVisual_PresentationLayerUsage::Presentation, "None");
cls_StepVisual_PresentationLayerUsage.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationLayerUsage::get_type_name, "None");
cls_StepVisual_PresentationLayerUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationLayerUsage::get_type_descriptor, "None");
cls_StepVisual_PresentationLayerUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationLayerUsage::*)() const) &StepVisual_PresentationLayerUsage::DynamicType, "None");

// Enums

}