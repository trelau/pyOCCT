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
#include <StepDimTol_StraightnessTolerance.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepDimTol_RWStraightnessTolerance.hxx>

void bind_RWStepDimTol_RWStraightnessTolerance(py::module &mod){

py::class_<RWStepDimTol_RWStraightnessTolerance, std::unique_ptr<RWStepDimTol_RWStraightnessTolerance, Deleter<RWStepDimTol_RWStraightnessTolerance>>> cls_RWStepDimTol_RWStraightnessTolerance(mod, "RWStepDimTol_RWStraightnessTolerance", "Read & Write tool for StraightnessTolerance");

// Constructors
cls_RWStepDimTol_RWStraightnessTolerance.def(py::init<>());

// Fields

// Methods
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWStraightnessTolerance::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWStraightnessTolerance::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWStraightnessTolerance::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWStraightnessTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWStraightnessTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWStraightnessTolerance.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWStraightnessTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWStraightnessTolerance.def("ReadStep", (void (RWStepDimTol_RWStraightnessTolerance::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_StraightnessTolerance> &) const) &RWStepDimTol_RWStraightnessTolerance::ReadStep, "Reads StraightnessTolerance", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWStraightnessTolerance.def("WriteStep", (void (RWStepDimTol_RWStraightnessTolerance::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_StraightnessTolerance> &) const) &RWStepDimTol_RWStraightnessTolerance::WriteStep, "Writes StraightnessTolerance", py::arg("SW"), py::arg("ent"));
cls_RWStepDimTol_RWStraightnessTolerance.def("Share", (void (RWStepDimTol_RWStraightnessTolerance::*)(const opencascade::handle<StepDimTol_StraightnessTolerance> &, Interface_EntityIterator &) const) &RWStepDimTol_RWStraightnessTolerance::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}