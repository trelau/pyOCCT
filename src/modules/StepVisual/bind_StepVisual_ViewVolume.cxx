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
#include <StepVisual_CentralOrParallel.hxx>
#include <Standard_Handle.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_PlanarBox.hxx>
#include <StepVisual_ViewVolume.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_ViewVolume(py::module &mod){

py::class_<StepVisual_ViewVolume, opencascade::handle<StepVisual_ViewVolume>, Standard_Transient> cls_StepVisual_ViewVolume(mod, "StepVisual_ViewVolume", "None");

// Constructors
cls_StepVisual_ViewVolume.def(py::init<>());

// Fields

// Methods
cls_StepVisual_ViewVolume.def("Init", (void (StepVisual_ViewVolume::*)(const StepVisual_CentralOrParallel, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_ViewVolume::Init, "None", py::arg("aProjectionType"), py::arg("aProjectionPoint"), py::arg("aViewPlaneDistance"), py::arg("aFrontPlaneDistance"), py::arg("aFrontPlaneClipping"), py::arg("aBackPlaneDistance"), py::arg("aBackPlaneClipping"), py::arg("aViewVolumeSidesClipping"), py::arg("aViewWindow"));
cls_StepVisual_ViewVolume.def("SetProjectionType", (void (StepVisual_ViewVolume::*)(const StepVisual_CentralOrParallel)) &StepVisual_ViewVolume::SetProjectionType, "None", py::arg("aProjectionType"));
cls_StepVisual_ViewVolume.def("ProjectionType", (StepVisual_CentralOrParallel (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::ProjectionType, "None");
cls_StepVisual_ViewVolume.def("SetProjectionPoint", (void (StepVisual_ViewVolume::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepVisual_ViewVolume::SetProjectionPoint, "None", py::arg("aProjectionPoint"));
cls_StepVisual_ViewVolume.def("ProjectionPoint", (opencascade::handle<StepGeom_CartesianPoint> (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::ProjectionPoint, "None");
cls_StepVisual_ViewVolume.def("SetViewPlaneDistance", (void (StepVisual_ViewVolume::*)(const Standard_Real)) &StepVisual_ViewVolume::SetViewPlaneDistance, "None", py::arg("aViewPlaneDistance"));
cls_StepVisual_ViewVolume.def("ViewPlaneDistance", (Standard_Real (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::ViewPlaneDistance, "None");
cls_StepVisual_ViewVolume.def("SetFrontPlaneDistance", (void (StepVisual_ViewVolume::*)(const Standard_Real)) &StepVisual_ViewVolume::SetFrontPlaneDistance, "None", py::arg("aFrontPlaneDistance"));
cls_StepVisual_ViewVolume.def("FrontPlaneDistance", (Standard_Real (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::FrontPlaneDistance, "None");
cls_StepVisual_ViewVolume.def("SetFrontPlaneClipping", (void (StepVisual_ViewVolume::*)(const Standard_Boolean)) &StepVisual_ViewVolume::SetFrontPlaneClipping, "None", py::arg("aFrontPlaneClipping"));
cls_StepVisual_ViewVolume.def("FrontPlaneClipping", (Standard_Boolean (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::FrontPlaneClipping, "None");
cls_StepVisual_ViewVolume.def("SetBackPlaneDistance", (void (StepVisual_ViewVolume::*)(const Standard_Real)) &StepVisual_ViewVolume::SetBackPlaneDistance, "None", py::arg("aBackPlaneDistance"));
cls_StepVisual_ViewVolume.def("BackPlaneDistance", (Standard_Real (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::BackPlaneDistance, "None");
cls_StepVisual_ViewVolume.def("SetBackPlaneClipping", (void (StepVisual_ViewVolume::*)(const Standard_Boolean)) &StepVisual_ViewVolume::SetBackPlaneClipping, "None", py::arg("aBackPlaneClipping"));
cls_StepVisual_ViewVolume.def("BackPlaneClipping", (Standard_Boolean (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::BackPlaneClipping, "None");
cls_StepVisual_ViewVolume.def("SetViewVolumeSidesClipping", (void (StepVisual_ViewVolume::*)(const Standard_Boolean)) &StepVisual_ViewVolume::SetViewVolumeSidesClipping, "None", py::arg("aViewVolumeSidesClipping"));
cls_StepVisual_ViewVolume.def("ViewVolumeSidesClipping", (Standard_Boolean (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::ViewVolumeSidesClipping, "None");
cls_StepVisual_ViewVolume.def("SetViewWindow", (void (StepVisual_ViewVolume::*)(const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_ViewVolume::SetViewWindow, "None", py::arg("aViewWindow"));
cls_StepVisual_ViewVolume.def("ViewWindow", (opencascade::handle<StepVisual_PlanarBox> (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::ViewWindow, "None");
cls_StepVisual_ViewVolume.def_static("get_type_name_", (const char * (*)()) &StepVisual_ViewVolume::get_type_name, "None");
cls_StepVisual_ViewVolume.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ViewVolume::get_type_descriptor, "None");
cls_StepVisual_ViewVolume.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ViewVolume::*)() const) &StepVisual_ViewVolume::DynamicType, "None");

// Enums

}