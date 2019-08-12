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
#include <AIS_Animation.hxx>
#include <Standard_Handle.hxx>
#include <AIS_AnimationCamera.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <V3d_View.hxx>
#include <Graphic3d_Camera.hxx>

void bind_AIS_AnimationCamera(py::module &mod){

py::class_<AIS_AnimationCamera, opencascade::handle<AIS_AnimationCamera>, AIS_Animation> cls_AIS_AnimationCamera(mod, "AIS_AnimationCamera", "Camera animation.");

// Constructors
cls_AIS_AnimationCamera.def(py::init<const TCollection_AsciiString &, const opencascade::handle<V3d_View> &>(), py::arg("theAnimationName"), py::arg("theView"));

// Fields

// Methods
cls_AIS_AnimationCamera.def_static("get_type_name_", (const char * (*)()) &AIS_AnimationCamera::get_type_name, "None");
cls_AIS_AnimationCamera.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_AnimationCamera::get_type_descriptor, "None");
cls_AIS_AnimationCamera.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_AnimationCamera::*)() const) &AIS_AnimationCamera::DynamicType, "None");
cls_AIS_AnimationCamera.def("View", (const opencascade::handle<V3d_View> & (AIS_AnimationCamera::*)() const) &AIS_AnimationCamera::View, "Return the target view.");
cls_AIS_AnimationCamera.def("CameraStart", (const opencascade::handle<Graphic3d_Camera> & (AIS_AnimationCamera::*)() const) &AIS_AnimationCamera::CameraStart, "Return camera start position.");
cls_AIS_AnimationCamera.def("SetCameraStart", (void (AIS_AnimationCamera::*)(const opencascade::handle<Graphic3d_Camera> &)) &AIS_AnimationCamera::SetCameraStart, "Define camera start position.", py::arg("theCameraStart"));
cls_AIS_AnimationCamera.def("CameraEnd", (const opencascade::handle<Graphic3d_Camera> & (AIS_AnimationCamera::*)() const) &AIS_AnimationCamera::CameraEnd, "Return camera end position.");
cls_AIS_AnimationCamera.def("SetCameraEnd", (void (AIS_AnimationCamera::*)(const opencascade::handle<Graphic3d_Camera> &)) &AIS_AnimationCamera::SetCameraEnd, "Define camera end position.", py::arg("theCameraEnd"));

// Enums

}