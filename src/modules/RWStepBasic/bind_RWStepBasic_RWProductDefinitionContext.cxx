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
#include <Standard_Handle.hxx>
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepBasic_RWProductDefinitionContext.hxx>

void bind_RWStepBasic_RWProductDefinitionContext(py::module &mod){

py::class_<RWStepBasic_RWProductDefinitionContext> cls_RWStepBasic_RWProductDefinitionContext(mod, "RWStepBasic_RWProductDefinitionContext", "Read & Write Module for ProductDefinitionContext");

// Constructors
cls_RWStepBasic_RWProductDefinitionContext.def(py::init<>());

// Fields

// Methods
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionContext::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionContext::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWProductDefinitionContext::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWProductDefinitionContext::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWProductDefinitionContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWProductDefinitionContext.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWProductDefinitionContext::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWProductDefinitionContext.def("ReadStep", (void (RWStepBasic_RWProductDefinitionContext::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ProductDefinitionContext> &) const) &RWStepBasic_RWProductDefinitionContext::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionContext.def("WriteStep", (void (RWStepBasic_RWProductDefinitionContext::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ProductDefinitionContext> &) const) &RWStepBasic_RWProductDefinitionContext::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWProductDefinitionContext.def("Share", (void (RWStepBasic_RWProductDefinitionContext::*)(const opencascade::handle<StepBasic_ProductDefinitionContext> &, Interface_EntityIterator &) const) &RWStepBasic_RWProductDefinitionContext::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}