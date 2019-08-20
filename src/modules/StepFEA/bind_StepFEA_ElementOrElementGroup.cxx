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
#include <StepFEA_ElementRepresentation.hxx>
#include <StepFEA_ElementGroup.hxx>
#include <StepFEA_ElementOrElementGroup.hxx>

void bind_StepFEA_ElementOrElementGroup(py::module &mod){

py::class_<StepFEA_ElementOrElementGroup, std::unique_ptr<StepFEA_ElementOrElementGroup>, StepData_SelectType> cls_StepFEA_ElementOrElementGroup(mod, "StepFEA_ElementOrElementGroup", "Representation of STEP SELECT type ElementOrElementGroup");

// Constructors
cls_StepFEA_ElementOrElementGroup.def(py::init<>());

// Fields

// Methods
// cls_StepFEA_ElementOrElementGroup.def_static("operator new_", (void * (*)(size_t)) &StepFEA_ElementOrElementGroup::operator new, "None", py::arg("theSize"));
// cls_StepFEA_ElementOrElementGroup.def_static("operator delete_", (void (*)(void *)) &StepFEA_ElementOrElementGroup::operator delete, "None", py::arg("theAddress"));
// cls_StepFEA_ElementOrElementGroup.def_static("operator new[]_", (void * (*)(size_t)) &StepFEA_ElementOrElementGroup::operator new[], "None", py::arg("theSize"));
// cls_StepFEA_ElementOrElementGroup.def_static("operator delete[]_", (void (*)(void *)) &StepFEA_ElementOrElementGroup::operator delete[], "None", py::arg("theAddress"));
// cls_StepFEA_ElementOrElementGroup.def_static("operator new_", (void * (*)(size_t, void *)) &StepFEA_ElementOrElementGroup::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepFEA_ElementOrElementGroup.def_static("operator delete_", (void (*)(void *, void *)) &StepFEA_ElementOrElementGroup::operator delete, "None", py::arg(""), py::arg(""));
cls_StepFEA_ElementOrElementGroup.def("CaseNum", (Standard_Integer (StepFEA_ElementOrElementGroup::*)(const opencascade::handle<Standard_Transient> &) const) &StepFEA_ElementOrElementGroup::CaseNum, "Recognizes a kind of ElementOrElementGroup select type 1 -> ElementRepresentation from StepFEA 2 -> ElementGroup from StepFEA 0 else", py::arg("ent"));
cls_StepFEA_ElementOrElementGroup.def("ElementRepresentation", (opencascade::handle<StepFEA_ElementRepresentation> (StepFEA_ElementOrElementGroup::*)() const) &StepFEA_ElementOrElementGroup::ElementRepresentation, "Returns Value as ElementRepresentation (or Null if another type)");
cls_StepFEA_ElementOrElementGroup.def("ElementGroup", (opencascade::handle<StepFEA_ElementGroup> (StepFEA_ElementOrElementGroup::*)() const) &StepFEA_ElementOrElementGroup::ElementGroup, "Returns Value as ElementGroup (or Null if another type)");

// Enums

}