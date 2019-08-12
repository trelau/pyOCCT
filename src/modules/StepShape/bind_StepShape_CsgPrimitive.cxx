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
#include <StepShape_Sphere.hxx>
#include <StepShape_Block.hxx>
#include <StepShape_RightAngularWedge.hxx>
#include <StepShape_Torus.hxx>
#include <StepShape_RightCircularCone.hxx>
#include <StepShape_RightCircularCylinder.hxx>
#include <StepShape_CsgPrimitive.hxx>

void bind_StepShape_CsgPrimitive(py::module &mod){

py::class_<StepShape_CsgPrimitive, std::unique_ptr<StepShape_CsgPrimitive, Deleter<StepShape_CsgPrimitive>>, StepData_SelectType> cls_StepShape_CsgPrimitive(mod, "StepShape_CsgPrimitive", "None");

// Constructors
cls_StepShape_CsgPrimitive.def(py::init<>());

// Fields

// Methods
// cls_StepShape_CsgPrimitive.def_static("operator new_", (void * (*)(size_t)) &StepShape_CsgPrimitive::operator new, "None", py::arg("theSize"));
// cls_StepShape_CsgPrimitive.def_static("operator delete_", (void (*)(void *)) &StepShape_CsgPrimitive::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_CsgPrimitive.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_CsgPrimitive::operator new[], "None", py::arg("theSize"));
// cls_StepShape_CsgPrimitive.def_static("operator delete[]_", (void (*)(void *)) &StepShape_CsgPrimitive::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_CsgPrimitive.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_CsgPrimitive::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_CsgPrimitive.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_CsgPrimitive::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_CsgPrimitive.def("CaseNum", (Standard_Integer (StepShape_CsgPrimitive::*)(const opencascade::handle<Standard_Transient> &) const) &StepShape_CsgPrimitive::CaseNum, "Recognizes a CsgPrimitive Kind Entity that is : 1 -> Sphere 2 -> Block 3 -> RightAngularWedge 4 -> Torus 5 -> RightCircularCone 6 -> RightCircularCylinder 0 else", py::arg("ent"));
cls_StepShape_CsgPrimitive.def("Sphere", (opencascade::handle<StepShape_Sphere> (StepShape_CsgPrimitive::*)() const) &StepShape_CsgPrimitive::Sphere, "returns Value as a Sphere (Null if another type)");
cls_StepShape_CsgPrimitive.def("Block", (opencascade::handle<StepShape_Block> (StepShape_CsgPrimitive::*)() const) &StepShape_CsgPrimitive::Block, "returns Value as a Block (Null if another type)");
cls_StepShape_CsgPrimitive.def("RightAngularWedge", (opencascade::handle<StepShape_RightAngularWedge> (StepShape_CsgPrimitive::*)() const) &StepShape_CsgPrimitive::RightAngularWedge, "returns Value as a RightAngularWedge (Null if another type)");
cls_StepShape_CsgPrimitive.def("Torus", (opencascade::handle<StepShape_Torus> (StepShape_CsgPrimitive::*)() const) &StepShape_CsgPrimitive::Torus, "returns Value as a Torus (Null if another type)");
cls_StepShape_CsgPrimitive.def("RightCircularCone", (opencascade::handle<StepShape_RightCircularCone> (StepShape_CsgPrimitive::*)() const) &StepShape_CsgPrimitive::RightCircularCone, "returns Value as a RightCircularCone (Null if another type)");
cls_StepShape_CsgPrimitive.def("RightCircularCylinder", (opencascade::handle<StepShape_RightCircularCylinder> (StepShape_CsgPrimitive::*)() const) &StepShape_CsgPrimitive::RightCircularCylinder, "returns Value as a RightCircularCylinder (Null if another type)");

// Enums

}