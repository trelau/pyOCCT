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
#include <StepVisual_PlanarBox.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_CameraModelD2.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_CameraModelD2(py::module &mod){

py::class_<StepVisual_CameraModelD2, opencascade::handle<StepVisual_CameraModelD2>, StepVisual_CameraModel> cls_StepVisual_CameraModelD2(mod, "StepVisual_CameraModelD2", "None");

// Constructors
cls_StepVisual_CameraModelD2.def(py::init<>());

// Fields

// Methods
cls_StepVisual_CameraModelD2.def("Init", (void (StepVisual_CameraModelD2::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_PlanarBox> &, const Standard_Boolean)) &StepVisual_CameraModelD2::Init, "None", py::arg("aName"), py::arg("aViewWindow"), py::arg("aViewWindowClipping"));
cls_StepVisual_CameraModelD2.def("SetViewWindow", (void (StepVisual_CameraModelD2::*)(const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_CameraModelD2::SetViewWindow, "None", py::arg("aViewWindow"));
cls_StepVisual_CameraModelD2.def("ViewWindow", (opencascade::handle<StepVisual_PlanarBox> (StepVisual_CameraModelD2::*)() const) &StepVisual_CameraModelD2::ViewWindow, "None");
cls_StepVisual_CameraModelD2.def("SetViewWindowClipping", (void (StepVisual_CameraModelD2::*)(const Standard_Boolean)) &StepVisual_CameraModelD2::SetViewWindowClipping, "None", py::arg("aViewWindowClipping"));
cls_StepVisual_CameraModelD2.def("ViewWindowClipping", (Standard_Boolean (StepVisual_CameraModelD2::*)() const) &StepVisual_CameraModelD2::ViewWindowClipping, "None");
cls_StepVisual_CameraModelD2.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraModelD2::get_type_name, "None");
cls_StepVisual_CameraModelD2.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraModelD2::get_type_descriptor, "None");
cls_StepVisual_CameraModelD2.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraModelD2::*)() const) &StepVisual_CameraModelD2::DynamicType, "None");

// Enums

}