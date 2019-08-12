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
#include <StepAP203_Change.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepAP203_RWChange.hxx>

void bind_RWStepAP203_RWChange(py::module &mod){

py::class_<RWStepAP203_RWChange, std::unique_ptr<RWStepAP203_RWChange, Deleter<RWStepAP203_RWChange>>> cls_RWStepAP203_RWChange(mod, "RWStepAP203_RWChange", "Read & Write tool for Change");

// Constructors
cls_RWStepAP203_RWChange.def(py::init<>());

// Fields

// Methods
// cls_RWStepAP203_RWChange.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWChange::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWChange.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWChange::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWChange.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWChange::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWChange.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWChange::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWChange.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWChange::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWChange.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWChange::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWChange.def("ReadStep", (void (RWStepAP203_RWChange::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_Change> &) const) &RWStepAP203_RWChange::ReadStep, "Reads Change", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWChange.def("WriteStep", (void (RWStepAP203_RWChange::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_Change> &) const) &RWStepAP203_RWChange::WriteStep, "Writes Change", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWChange.def("Share", (void (RWStepAP203_RWChange::*)(const opencascade::handle<StepAP203_Change> &, Interface_EntityIterator &) const) &RWStepAP203_RWChange::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}