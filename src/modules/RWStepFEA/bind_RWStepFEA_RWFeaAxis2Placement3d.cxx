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
#include <StepFEA_FeaAxis2Placement3d.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepFEA_RWFeaAxis2Placement3d.hxx>

void bind_RWStepFEA_RWFeaAxis2Placement3d(py::module &mod){

py::class_<RWStepFEA_RWFeaAxis2Placement3d, std::unique_ptr<RWStepFEA_RWFeaAxis2Placement3d>> cls_RWStepFEA_RWFeaAxis2Placement3d(mod, "RWStepFEA_RWFeaAxis2Placement3d", "Read & Write tool for FeaAxis2Placement3d");

// Constructors
cls_RWStepFEA_RWFeaAxis2Placement3d.def(py::init<>());

// Fields

// Methods
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWFeaAxis2Placement3d::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWFeaAxis2Placement3d::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWFeaAxis2Placement3d::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWFeaAxis2Placement3d::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWFeaAxis2Placement3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWFeaAxis2Placement3d.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWFeaAxis2Placement3d::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWFeaAxis2Placement3d.def("ReadStep", (void (RWStepFEA_RWFeaAxis2Placement3d::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_FeaAxis2Placement3d> &) const) &RWStepFEA_RWFeaAxis2Placement3d::ReadStep, "Reads FeaAxis2Placement3d", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWFeaAxis2Placement3d.def("WriteStep", (void (RWStepFEA_RWFeaAxis2Placement3d::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_FeaAxis2Placement3d> &) const) &RWStepFEA_RWFeaAxis2Placement3d::WriteStep, "Writes FeaAxis2Placement3d", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWFeaAxis2Placement3d.def("Share", (void (RWStepFEA_RWFeaAxis2Placement3d::*)(const opencascade::handle<StepFEA_FeaAxis2Placement3d> &, Interface_EntityIterator &) const) &RWStepFEA_RWFeaAxis2Placement3d::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}