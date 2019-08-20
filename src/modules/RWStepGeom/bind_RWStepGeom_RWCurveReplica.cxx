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
#include <StepGeom_CurveReplica.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepGeom_RWCurveReplica.hxx>

void bind_RWStepGeom_RWCurveReplica(py::module &mod){

py::class_<RWStepGeom_RWCurveReplica, std::unique_ptr<RWStepGeom_RWCurveReplica>> cls_RWStepGeom_RWCurveReplica(mod, "RWStepGeom_RWCurveReplica", "Read & Write Module for CurveReplica");

// Constructors
cls_RWStepGeom_RWCurveReplica.def(py::init<>());

// Fields

// Methods
// cls_RWStepGeom_RWCurveReplica.def_static("operator new_", (void * (*)(size_t)) &RWStepGeom_RWCurveReplica::operator new, "None", py::arg("theSize"));
// cls_RWStepGeom_RWCurveReplica.def_static("operator delete_", (void (*)(void *)) &RWStepGeom_RWCurveReplica::operator delete, "None", py::arg("theAddress"));
// cls_RWStepGeom_RWCurveReplica.def_static("operator new[]_", (void * (*)(size_t)) &RWStepGeom_RWCurveReplica::operator new[], "None", py::arg("theSize"));
// cls_RWStepGeom_RWCurveReplica.def_static("operator delete[]_", (void (*)(void *)) &RWStepGeom_RWCurveReplica::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepGeom_RWCurveReplica.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepGeom_RWCurveReplica::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepGeom_RWCurveReplica.def_static("operator delete_", (void (*)(void *, void *)) &RWStepGeom_RWCurveReplica::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepGeom_RWCurveReplica.def("ReadStep", (void (RWStepGeom_RWCurveReplica::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepGeom_CurveReplica> &) const) &RWStepGeom_RWCurveReplica::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepGeom_RWCurveReplica.def("WriteStep", (void (RWStepGeom_RWCurveReplica::*)(StepData_StepWriter &, const opencascade::handle<StepGeom_CurveReplica> &) const) &RWStepGeom_RWCurveReplica::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepGeom_RWCurveReplica.def("Share", (void (RWStepGeom_RWCurveReplica::*)(const opencascade::handle<StepGeom_CurveReplica> &, Interface_EntityIterator &) const) &RWStepGeom_RWCurveReplica::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}