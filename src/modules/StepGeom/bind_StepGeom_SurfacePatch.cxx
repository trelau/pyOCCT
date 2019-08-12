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
#include <StepGeom_BoundedSurface.hxx>
#include <StepGeom_TransitionCode.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_SurfacePatch.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_SurfacePatch(py::module &mod){

py::class_<StepGeom_SurfacePatch, opencascade::handle<StepGeom_SurfacePatch>, Standard_Transient> cls_StepGeom_SurfacePatch(mod, "StepGeom_SurfacePatch", "None");

// Constructors
cls_StepGeom_SurfacePatch.def(py::init<>());

// Fields

// Methods
cls_StepGeom_SurfacePatch.def("Init", (void (StepGeom_SurfacePatch::*)(const opencascade::handle<StepGeom_BoundedSurface> &, const StepGeom_TransitionCode, const StepGeom_TransitionCode, const Standard_Boolean, const Standard_Boolean)) &StepGeom_SurfacePatch::Init, "None", py::arg("aParentSurface"), py::arg("aUTransition"), py::arg("aVTransition"), py::arg("aUSense"), py::arg("aVSense"));
cls_StepGeom_SurfacePatch.def("SetParentSurface", (void (StepGeom_SurfacePatch::*)(const opencascade::handle<StepGeom_BoundedSurface> &)) &StepGeom_SurfacePatch::SetParentSurface, "None", py::arg("aParentSurface"));
cls_StepGeom_SurfacePatch.def("ParentSurface", (opencascade::handle<StepGeom_BoundedSurface> (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::ParentSurface, "None");
cls_StepGeom_SurfacePatch.def("SetUTransition", (void (StepGeom_SurfacePatch::*)(const StepGeom_TransitionCode)) &StepGeom_SurfacePatch::SetUTransition, "None", py::arg("aUTransition"));
cls_StepGeom_SurfacePatch.def("UTransition", (StepGeom_TransitionCode (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::UTransition, "None");
cls_StepGeom_SurfacePatch.def("SetVTransition", (void (StepGeom_SurfacePatch::*)(const StepGeom_TransitionCode)) &StepGeom_SurfacePatch::SetVTransition, "None", py::arg("aVTransition"));
cls_StepGeom_SurfacePatch.def("VTransition", (StepGeom_TransitionCode (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::VTransition, "None");
cls_StepGeom_SurfacePatch.def("SetUSense", (void (StepGeom_SurfacePatch::*)(const Standard_Boolean)) &StepGeom_SurfacePatch::SetUSense, "None", py::arg("aUSense"));
cls_StepGeom_SurfacePatch.def("USense", (Standard_Boolean (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::USense, "None");
cls_StepGeom_SurfacePatch.def("SetVSense", (void (StepGeom_SurfacePatch::*)(const Standard_Boolean)) &StepGeom_SurfacePatch::SetVSense, "None", py::arg("aVSense"));
cls_StepGeom_SurfacePatch.def("VSense", (Standard_Boolean (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::VSense, "None");
cls_StepGeom_SurfacePatch.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfacePatch::get_type_name, "None");
cls_StepGeom_SurfacePatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfacePatch::get_type_descriptor, "None");
cls_StepGeom_SurfacePatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::DynamicType, "None");

// Enums

}