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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_SolidModel.hxx>
#include <StepShape_HalfSpaceSolid.hxx>
#include <StepShape_CsgPrimitive.hxx>
#include <StepShape_BooleanResult.hxx>
#include <StepShape_BooleanOperand.hxx>

void bind_StepShape_BooleanOperand(py::module &mod){

py::class_<StepShape_BooleanOperand, std::unique_ptr<StepShape_BooleanOperand>> cls_StepShape_BooleanOperand(mod, "StepShape_BooleanOperand", "None");

// Constructors
cls_StepShape_BooleanOperand.def(py::init<>());

// Fields

// Methods
// cls_StepShape_BooleanOperand.def_static("operator new_", (void * (*)(size_t)) &StepShape_BooleanOperand::operator new, "None", py::arg("theSize"));
// cls_StepShape_BooleanOperand.def_static("operator delete_", (void (*)(void *)) &StepShape_BooleanOperand::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_BooleanOperand.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_BooleanOperand::operator new[], "None", py::arg("theSize"));
// cls_StepShape_BooleanOperand.def_static("operator delete[]_", (void (*)(void *)) &StepShape_BooleanOperand::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_BooleanOperand.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_BooleanOperand::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_BooleanOperand.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_BooleanOperand::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_BooleanOperand.def("SetTypeOfContent", (void (StepShape_BooleanOperand::*)(const Standard_Integer)) &StepShape_BooleanOperand::SetTypeOfContent, "None", py::arg("aTypeOfContent"));
cls_StepShape_BooleanOperand.def("TypeOfContent", (Standard_Integer (StepShape_BooleanOperand::*)() const) &StepShape_BooleanOperand::TypeOfContent, "None");
cls_StepShape_BooleanOperand.def("SolidModel", (opencascade::handle<StepShape_SolidModel> (StepShape_BooleanOperand::*)() const) &StepShape_BooleanOperand::SolidModel, "returns Value as a SolidModel (Null if another type)");
cls_StepShape_BooleanOperand.def("SetSolidModel", (void (StepShape_BooleanOperand::*)(const opencascade::handle<StepShape_SolidModel> &)) &StepShape_BooleanOperand::SetSolidModel, "None", py::arg("aSolidModel"));
cls_StepShape_BooleanOperand.def("HalfSpaceSolid", (opencascade::handle<StepShape_HalfSpaceSolid> (StepShape_BooleanOperand::*)() const) &StepShape_BooleanOperand::HalfSpaceSolid, "returns Value as a HalfSpaceSolid (Null if another type)");
cls_StepShape_BooleanOperand.def("SetHalfSpaceSolid", (void (StepShape_BooleanOperand::*)(const opencascade::handle<StepShape_HalfSpaceSolid> &)) &StepShape_BooleanOperand::SetHalfSpaceSolid, "None", py::arg("aHalfSpaceSolid"));
cls_StepShape_BooleanOperand.def("CsgPrimitive", (StepShape_CsgPrimitive (StepShape_BooleanOperand::*)() const) &StepShape_BooleanOperand::CsgPrimitive, "returns Value as a CsgPrimitive (Null if another type) CsgPrimitive is another Select Type");
cls_StepShape_BooleanOperand.def("SetCsgPrimitive", (void (StepShape_BooleanOperand::*)(const StepShape_CsgPrimitive &)) &StepShape_BooleanOperand::SetCsgPrimitive, "None", py::arg("aCsgPrimitive"));
cls_StepShape_BooleanOperand.def("BooleanResult", (opencascade::handle<StepShape_BooleanResult> (StepShape_BooleanOperand::*)() const) &StepShape_BooleanOperand::BooleanResult, "returns Value as a BooleanResult (Null if another type)");
cls_StepShape_BooleanOperand.def("SetBooleanResult", (void (StepShape_BooleanOperand::*)(const opencascade::handle<StepShape_BooleanResult> &)) &StepShape_BooleanOperand::SetBooleanResult, "None", py::arg("aBooleanResult"));

// Enums

}