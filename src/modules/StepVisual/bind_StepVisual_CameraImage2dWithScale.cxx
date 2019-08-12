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
#include <StepVisual_CameraImage.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_CameraImage2dWithScale.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_CameraImage2dWithScale(py::module &mod){

py::class_<StepVisual_CameraImage2dWithScale, opencascade::handle<StepVisual_CameraImage2dWithScale>, StepVisual_CameraImage> cls_StepVisual_CameraImage2dWithScale(mod, "StepVisual_CameraImage2dWithScale", "None");

// Constructors
cls_StepVisual_CameraImage2dWithScale.def(py::init<>());

// Fields

// Methods
cls_StepVisual_CameraImage2dWithScale.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraImage2dWithScale::get_type_name, "None");
cls_StepVisual_CameraImage2dWithScale.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraImage2dWithScale::get_type_descriptor, "None");
cls_StepVisual_CameraImage2dWithScale.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraImage2dWithScale::*)() const) &StepVisual_CameraImage2dWithScale::DynamicType, "None");

// Enums

}