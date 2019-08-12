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
#include <StepBasic_ExternalIdentificationAssignment.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepBasic_RWExternalIdentificationAssignment.hxx>

void bind_RWStepBasic_RWExternalIdentificationAssignment(py::module &mod){

py::class_<RWStepBasic_RWExternalIdentificationAssignment, std::unique_ptr<RWStepBasic_RWExternalIdentificationAssignment, Deleter<RWStepBasic_RWExternalIdentificationAssignment>>> cls_RWStepBasic_RWExternalIdentificationAssignment(mod, "RWStepBasic_RWExternalIdentificationAssignment", "Read & Write tool for ExternalIdentificationAssignment");

// Constructors
cls_RWStepBasic_RWExternalIdentificationAssignment.def(py::init<>());

// Fields

// Methods
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWExternalIdentificationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWExternalIdentificationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWExternalIdentificationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWExternalIdentificationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWExternalIdentificationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWExternalIdentificationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWExternalIdentificationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWExternalIdentificationAssignment.def("ReadStep", (void (RWStepBasic_RWExternalIdentificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ExternalIdentificationAssignment> &) const) &RWStepBasic_RWExternalIdentificationAssignment::ReadStep, "Reads ExternalIdentificationAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWExternalIdentificationAssignment.def("WriteStep", (void (RWStepBasic_RWExternalIdentificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ExternalIdentificationAssignment> &) const) &RWStepBasic_RWExternalIdentificationAssignment::WriteStep, "Writes ExternalIdentificationAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWExternalIdentificationAssignment.def("Share", (void (RWStepBasic_RWExternalIdentificationAssignment::*)(const opencascade::handle<StepBasic_ExternalIdentificationAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWExternalIdentificationAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}