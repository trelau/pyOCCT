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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepGeom_Plane.hxx>
#include <StepVisual_CameraModelD3MultiClippingIntersection.hxx>
#include <StepVisual_CameraModelD3MultiClippingUnionSelect.hxx>

void bind_StepVisual_CameraModelD3MultiClippingUnionSelect(py::module &mod){

py::class_<StepVisual_CameraModelD3MultiClippingUnionSelect, std::unique_ptr<StepVisual_CameraModelD3MultiClippingUnionSelect, Deleter<StepVisual_CameraModelD3MultiClippingUnionSelect>>, StepData_SelectType> cls_StepVisual_CameraModelD3MultiClippingUnionSelect(mod, "StepVisual_CameraModelD3MultiClippingUnionSelect", "None");

// Constructors
cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_CameraModelD3MultiClippingUnionSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_CameraModelD3MultiClippingUnionSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_CameraModelD3MultiClippingUnionSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_CameraModelD3MultiClippingUnionSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_CameraModelD3MultiClippingUnionSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_CameraModelD3MultiClippingUnionSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def("CaseNum", (Standard_Integer (StepVisual_CameraModelD3MultiClippingUnionSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepVisual_CameraModelD3MultiClippingUnionSelect::CaseNum, "Recognizes a IdAttributeSelect Kind Entity that is : 1 -> Plane 2 -> CameraModelD3MultiClippingIntersection 0 else", py::arg("ent"));
cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def("Plane", (opencascade::handle<StepGeom_Plane> (StepVisual_CameraModelD3MultiClippingUnionSelect::*)() const) &StepVisual_CameraModelD3MultiClippingUnionSelect::Plane, "returns Value as a Plane (Null if another type)");
cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def("CameraModelD3MultiClippingIntersection", (opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection> (StepVisual_CameraModelD3MultiClippingUnionSelect::*)() const) &StepVisual_CameraModelD3MultiClippingUnionSelect::CameraModelD3MultiClippingIntersection, "returns Value as a CameraModelD3MultiClippingIntersection (Null if another type)");

// Enums

}