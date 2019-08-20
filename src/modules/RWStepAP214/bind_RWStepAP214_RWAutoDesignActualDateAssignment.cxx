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
#include <StepAP214_AutoDesignActualDateAssignment.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepAP214_RWAutoDesignActualDateAssignment.hxx>

void bind_RWStepAP214_RWAutoDesignActualDateAssignment(py::module &mod){

py::class_<RWStepAP214_RWAutoDesignActualDateAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignActualDateAssignment>> cls_RWStepAP214_RWAutoDesignActualDateAssignment(mod, "RWStepAP214_RWAutoDesignActualDateAssignment", "Read & Write Module for AutoDesignActualDateAssignment");

// Constructors
cls_RWStepAP214_RWAutoDesignActualDateAssignment.def(py::init<>());

// Fields

// Methods
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214_RWAutoDesignActualDateAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214_RWAutoDesignActualDateAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214_RWAutoDesignActualDateAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignActualDateAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignActualDateAssignment> &) const) &RWStepAP214_RWAutoDesignActualDateAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignActualDateAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignActualDateAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignActualDateAssignment> &) const) &RWStepAP214_RWAutoDesignActualDateAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepAP214_RWAutoDesignActualDateAssignment.def("Share", (void (RWStepAP214_RWAutoDesignActualDateAssignment::*)(const opencascade::handle<StepAP214_AutoDesignActualDateAssignment> &, Interface_EntityIterator &) const) &RWStepAP214_RWAutoDesignActualDateAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}