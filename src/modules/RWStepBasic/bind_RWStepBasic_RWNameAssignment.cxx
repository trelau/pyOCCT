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
#include <StepBasic_NameAssignment.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepBasic_RWNameAssignment.hxx>

void bind_RWStepBasic_RWNameAssignment(py::module &mod){

py::class_<RWStepBasic_RWNameAssignment, std::unique_ptr<RWStepBasic_RWNameAssignment, Deleter<RWStepBasic_RWNameAssignment>>> cls_RWStepBasic_RWNameAssignment(mod, "RWStepBasic_RWNameAssignment", "Read & Write tool for NameAssignment");

// Constructors
cls_RWStepBasic_RWNameAssignment.def(py::init<>());

// Fields

// Methods
// cls_RWStepBasic_RWNameAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWNameAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWNameAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWNameAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWNameAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWNameAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWNameAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWNameAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWNameAssignment.def("ReadStep", (void (RWStepBasic_RWNameAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_NameAssignment> &) const) &RWStepBasic_RWNameAssignment::ReadStep, "Reads NameAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWNameAssignment.def("WriteStep", (void (RWStepBasic_RWNameAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_NameAssignment> &) const) &RWStepBasic_RWNameAssignment::WriteStep, "Writes NameAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWNameAssignment.def("Share", (void (RWStepBasic_RWNameAssignment::*)(const opencascade::handle<StepBasic_NameAssignment> &, Interface_EntityIterator &) const) &RWStepBasic_RWNameAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}