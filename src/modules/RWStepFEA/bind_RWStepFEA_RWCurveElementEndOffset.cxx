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
#include <StepFEA_CurveElementEndOffset.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepFEA_RWCurveElementEndOffset.hxx>

void bind_RWStepFEA_RWCurveElementEndOffset(py::module &mod){

py::class_<RWStepFEA_RWCurveElementEndOffset, std::unique_ptr<RWStepFEA_RWCurveElementEndOffset>> cls_RWStepFEA_RWCurveElementEndOffset(mod, "RWStepFEA_RWCurveElementEndOffset", "Read & Write tool for CurveElementEndOffset");

// Constructors
cls_RWStepFEA_RWCurveElementEndOffset.def(py::init<>());

// Fields

// Methods
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementEndOffset::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWCurveElementEndOffset::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWCurveElementEndOffset::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWCurveElementEndOffset::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWCurveElementEndOffset::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWCurveElementEndOffset.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWCurveElementEndOffset::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWCurveElementEndOffset.def("ReadStep", (void (RWStepFEA_RWCurveElementEndOffset::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_CurveElementEndOffset> &) const) &RWStepFEA_RWCurveElementEndOffset::ReadStep, "Reads CurveElementEndOffset", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementEndOffset.def("WriteStep", (void (RWStepFEA_RWCurveElementEndOffset::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_CurveElementEndOffset> &) const) &RWStepFEA_RWCurveElementEndOffset::WriteStep, "Writes CurveElementEndOffset", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWCurveElementEndOffset.def("Share", (void (RWStepFEA_RWCurveElementEndOffset::*)(const opencascade::handle<StepFEA_CurveElementEndOffset> &, Interface_EntityIterator &) const) &RWStepFEA_RWCurveElementEndOffset::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}