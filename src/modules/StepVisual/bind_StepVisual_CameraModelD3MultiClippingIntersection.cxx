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
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.hxx>
#include <StepVisual_CameraModelD3MultiClippingIntersection.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_CameraModelD3MultiClippingIntersection(py::module &mod){

py::class_<StepVisual_CameraModelD3MultiClippingIntersection, opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection>, StepGeom_GeometricRepresentationItem> cls_StepVisual_CameraModelD3MultiClippingIntersection(mod, "StepVisual_CameraModelD3MultiClippingIntersection", "None");

// Constructors
cls_StepVisual_CameraModelD3MultiClippingIntersection.def(py::init<>());

// Fields

// Methods
cls_StepVisual_CameraModelD3MultiClippingIntersection.def("Init", (void (StepVisual_CameraModelD3MultiClippingIntersection::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect> &)) &StepVisual_CameraModelD3MultiClippingIntersection::Init, "None", py::arg("theName"), py::arg("theShapeClipping"));
cls_StepVisual_CameraModelD3MultiClippingIntersection.def("SetShapeClipping", (void (StepVisual_CameraModelD3MultiClippingIntersection::*)(const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect> &)) &StepVisual_CameraModelD3MultiClippingIntersection::SetShapeClipping, "None", py::arg("theShapeClipping"));
cls_StepVisual_CameraModelD3MultiClippingIntersection.def("ShapeClipping", (const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect> (StepVisual_CameraModelD3MultiClippingIntersection::*)()) &StepVisual_CameraModelD3MultiClippingIntersection::ShapeClipping, "None");
cls_StepVisual_CameraModelD3MultiClippingIntersection.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraModelD3MultiClippingIntersection::get_type_name, "None");
cls_StepVisual_CameraModelD3MultiClippingIntersection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraModelD3MultiClippingIntersection::get_type_descriptor, "None");
cls_StepVisual_CameraModelD3MultiClippingIntersection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraModelD3MultiClippingIntersection::*)() const) &StepVisual_CameraModelD3MultiClippingIntersection::DynamicType, "None");

// Enums

}