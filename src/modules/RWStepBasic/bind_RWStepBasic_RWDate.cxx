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
#include <StepBasic_Date.hxx>
#include <StepData_StepWriter.hxx>
#include <RWStepBasic_RWDate.hxx>

void bind_RWStepBasic_RWDate(py::module &mod){

py::class_<RWStepBasic_RWDate, std::unique_ptr<RWStepBasic_RWDate, Deleter<RWStepBasic_RWDate>>> cls_RWStepBasic_RWDate(mod, "RWStepBasic_RWDate", "Read & Write Module for Date");

// Constructors
cls_RWStepBasic_RWDate.def(py::init<>());

// Fields

// Methods
// cls_RWStepBasic_RWDate.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWDate::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWDate.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWDate::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDate.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWDate::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWDate.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWDate::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWDate.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWDate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWDate.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWDate::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWDate.def("ReadStep", (void (RWStepBasic_RWDate::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_Date> &) const) &RWStepBasic_RWDate::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWDate.def("WriteStep", (void (RWStepBasic_RWDate::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_Date> &) const) &RWStepBasic_RWDate::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// Enums

}