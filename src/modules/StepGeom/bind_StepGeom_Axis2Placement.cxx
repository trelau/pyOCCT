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
#include <StepGeom_Axis2Placement2d.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <StepGeom_Axis2Placement.hxx>

void bind_StepGeom_Axis2Placement(py::module &mod){

py::class_<StepGeom_Axis2Placement, std::unique_ptr<StepGeom_Axis2Placement, Deleter<StepGeom_Axis2Placement>>, StepData_SelectType> cls_StepGeom_Axis2Placement(mod, "StepGeom_Axis2Placement", "None");

// Constructors
cls_StepGeom_Axis2Placement.def(py::init<>());

// Fields

// Methods
// cls_StepGeom_Axis2Placement.def_static("operator new_", (void * (*)(size_t)) &StepGeom_Axis2Placement::operator new, "None", py::arg("theSize"));
// cls_StepGeom_Axis2Placement.def_static("operator delete_", (void (*)(void *)) &StepGeom_Axis2Placement::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_Axis2Placement.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_Axis2Placement::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_Axis2Placement.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_Axis2Placement::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_Axis2Placement.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_Axis2Placement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_Axis2Placement.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_Axis2Placement::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_Axis2Placement.def("CaseNum", (Standard_Integer (StepGeom_Axis2Placement::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_Axis2Placement::CaseNum, "Recognizes a Axis2Placement Kind Entity that is : 1 -> Axis2Placement2d 2 -> Axis2Placement3d 0 else", py::arg("ent"));
cls_StepGeom_Axis2Placement.def("Axis2Placement2d", (opencascade::handle<StepGeom_Axis2Placement2d> (StepGeom_Axis2Placement::*)() const) &StepGeom_Axis2Placement::Axis2Placement2d, "returns Value as a Axis2Placement2d (Null if another type)");
cls_StepGeom_Axis2Placement.def("Axis2Placement3d", (opencascade::handle<StepGeom_Axis2Placement3d> (StepGeom_Axis2Placement::*)() const) &StepGeom_Axis2Placement::Axis2Placement3d, "returns Value as a Axis2Placement3d (Null if another type)");

// Enums

}