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
#include <StepAP214_AppliedDateAndTimeAssignment.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepAP214_RWAppliedDateAndTimeAssignment.hxx>

void bind_RWStepAP214_RWAppliedDateAndTimeAssignment(py::module &mod){

py::class_<RWStepAP214_RWAppliedDateAndTimeAssignment, std::unique_ptr<RWStepAP214_RWAppliedDateAndTimeAssignment>> cls_RWStepAP214_RWAppliedDateAndTimeAssignment(mod, "RWStepAP214_RWAppliedDateAndTimeAssignment", "Read & Write Module for AppliedDateAndTimeAssignment");

// Constructors
cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def(py::init<>());

// Fields

// Methods
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAppliedDateAndTimeAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedDateAndTimeAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> &) const) &RWStepAP214_RWAppliedDateAndTimeAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedDateAndTimeAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> &) const) &RWStepAP214_RWAppliedDateAndTimeAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def("Share", (void (RWStepAP214_RWAppliedDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAppliedDateAndTimeAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}