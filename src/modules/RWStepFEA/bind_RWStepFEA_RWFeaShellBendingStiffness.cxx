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
#include <StepFEA_FeaShellBendingStiffness.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepFEA_RWFeaShellBendingStiffness.hxx>

void bind_RWStepFEA_RWFeaShellBendingStiffness(py::module &mod){

py::class_<RWStepFEA_RWFeaShellBendingStiffness, std::unique_ptr<RWStepFEA_RWFeaShellBendingStiffness, Deleter<RWStepFEA_RWFeaShellBendingStiffness>>> cls_RWStepFEA_RWFeaShellBendingStiffness(mod, "RWStepFEA_RWFeaShellBendingStiffness", "Read & Write tool for FeaShellBendingStiffness");

// Constructors
cls_RWStepFEA_RWFeaShellBendingStiffness.def(py::init<>());

// Fields

// Methods
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellBendingStiffness::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaShellBendingStiffness::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaShellBendingStiffness::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaShellBendingStiffness::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaShellBendingStiffness::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaShellBendingStiffness.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaShellBendingStiffness::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaShellBendingStiffness.def("ReadStep", (void (RWStepFEA_RWFeaShellBendingStiffness::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaShellBendingStiffness> &) const) &RWStepFEA_RWFeaShellBendingStiffness::ReadStep, "Reads FeaShellBendingStiffness", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellBendingStiffness.def("WriteStep", (void (RWStepFEA_RWFeaShellBendingStiffness::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaShellBendingStiffness> &) const) &RWStepFEA_RWFeaShellBendingStiffness::WriteStep, "Writes FeaShellBendingStiffness", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaShellBendingStiffness.def("Share", (void (RWStepFEA_RWFeaShellBendingStiffness::*)(const opencascade::handle<StepFEA_FeaShellBendingStiffness> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaShellBendingStiffness::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}