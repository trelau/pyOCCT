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
#include <StepDimTol_ToleranceZoneForm.hxx>
#include <StepData_StepWriter.hxx>
#include <RWStepDimTol_RWToleranceZoneForm.hxx>

void bind_RWStepDimTol_RWToleranceZoneForm(py::module &mod){

py::class_<RWStepDimTol_RWToleranceZoneForm, std::unique_ptr<RWStepDimTol_RWToleranceZoneForm, Deleter<RWStepDimTol_RWToleranceZoneForm>>> cls_RWStepDimTol_RWToleranceZoneForm(mod, "RWStepDimTol_RWToleranceZoneForm", "Read & Write tool for ToleranceZoneForm");

// Constructors
cls_RWStepDimTol_RWToleranceZoneForm.def(py::init<>());

// Fields

// Methods
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator new_", (void * (*)(size_t)) &RWStepDimTol_RWToleranceZoneForm::operator new, "None", py::arg("theSize"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator delete_", (void (*)(void *)) &RWStepDimTol_RWToleranceZoneForm::operator delete, "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator new[]_", (void * (*)(size_t)) &RWStepDimTol_RWToleranceZoneForm::operator new[], "None", py::arg("theSize"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator delete[]_", (void (*)(void *)) &RWStepDimTol_RWToleranceZoneForm::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepDimTol_RWToleranceZoneForm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepDimTol_RWToleranceZoneForm.def_static("operator delete_", (void (*)(void *, void *)) &RWStepDimTol_RWToleranceZoneForm::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepDimTol_RWToleranceZoneForm.def("ReadStep", (void (RWStepDimTol_RWToleranceZoneForm::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepDimTol_ToleranceZoneForm> &) const) &RWStepDimTol_RWToleranceZoneForm::ReadStep, "Reads ToleranceZoneForm", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepDimTol_RWToleranceZoneForm.def("WriteStep", (void (RWStepDimTol_RWToleranceZoneForm::*)(StepData_StepWriter &, const opencascade::handle<StepDimTol_ToleranceZoneForm> &) const) &RWStepDimTol_RWToleranceZoneForm::WriteStep, "Writes ToleranceZoneForm", py::arg("SW"), py::arg("ent"));

// Enums

}