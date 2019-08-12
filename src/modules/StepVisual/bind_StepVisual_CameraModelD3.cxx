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
#include <StepVisual_CameraModel.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <StepVisual_ViewVolume.hxx>
#include <StepVisual_CameraModelD3.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_CameraModelD3(py::module &mod){

py::class_<StepVisual_CameraModelD3, opencascade::handle<StepVisual_CameraModelD3>, StepVisual_CameraModel> cls_StepVisual_CameraModelD3(mod, "StepVisual_CameraModelD3", "None");

// Constructors
cls_StepVisual_CameraModelD3.def(py::init<>());

// Fields

// Methods
cls_StepVisual_CameraModelD3.def("Init", (void (StepVisual_CameraModelD3::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepVisual_ViewVolume> &)) &StepVisual_CameraModelD3::Init, "None", py::arg("aName"), py::arg("aViewReferenceSystem"), py::arg("aPerspectiveOfVolume"));
cls_StepVisual_CameraModelD3.def("SetViewReferenceSystem", (void (StepVisual_CameraModelD3::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepVisual_CameraModelD3::SetViewReferenceSystem, "None", py::arg("aViewReferenceSystem"));
cls_StepVisual_CameraModelD3.def("ViewReferenceSystem", (opencascade::handle<StepGeom_Axis2Placement3d> (StepVisual_CameraModelD3::*)() const) &StepVisual_CameraModelD3::ViewReferenceSystem, "None");
cls_StepVisual_CameraModelD3.def("SetPerspectiveOfVolume", (void (StepVisual_CameraModelD3::*)(const opencascade::handle<StepVisual_ViewVolume> &)) &StepVisual_CameraModelD3::SetPerspectiveOfVolume, "None", py::arg("aPerspectiveOfVolume"));
cls_StepVisual_CameraModelD3.def("PerspectiveOfVolume", (opencascade::handle<StepVisual_ViewVolume> (StepVisual_CameraModelD3::*)() const) &StepVisual_CameraModelD3::PerspectiveOfVolume, "None");
cls_StepVisual_CameraModelD3.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraModelD3::get_type_name, "None");
cls_StepVisual_CameraModelD3.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraModelD3::get_type_descriptor, "None");
cls_StepVisual_CameraModelD3.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraModelD3::*)() const) &StepVisual_CameraModelD3::DynamicType, "None");

// Enums

}