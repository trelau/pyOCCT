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
#include <StepShape_ValueFormatTypeQualifier.hxx>
#include <StepData_StepWriter.hxx>
#include <RWStepShape_RWValueFormatTypeQualifier.hxx>

void bind_RWStepShape_RWValueFormatTypeQualifier(py::module &mod){

py::class_<RWStepShape_RWValueFormatTypeQualifier, std::unique_ptr<RWStepShape_RWValueFormatTypeQualifier, Deleter<RWStepShape_RWValueFormatTypeQualifier>>> cls_RWStepShape_RWValueFormatTypeQualifier(mod, "RWStepShape_RWValueFormatTypeQualifier", "Read & Write tool for ValueFormatTypeQualifier");

// Constructors
cls_RWStepShape_RWValueFormatTypeQualifier.def(py::init<>());

// Fields

// Methods
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWValueFormatTypeQualifier::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWValueFormatTypeQualifier::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWValueFormatTypeQualifier::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWValueFormatTypeQualifier::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWValueFormatTypeQualifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWValueFormatTypeQualifier.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWValueFormatTypeQualifier::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWValueFormatTypeQualifier.def("ReadStep", (void (RWStepShape_RWValueFormatTypeQualifier::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_ValueFormatTypeQualifier> &) const) &RWStepShape_RWValueFormatTypeQualifier::ReadStep, "Reads ValueFormatTypeQualifier", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWValueFormatTypeQualifier.def("WriteStep", (void (RWStepShape_RWValueFormatTypeQualifier::*)(StepData_StepWriter &, const opencascade::handle<StepShape_ValueFormatTypeQualifier> &) const) &RWStepShape_RWValueFormatTypeQualifier::WriteStep, "Writes ValueFormatTypeQualifier", py::arg("SW"), py::arg("ent"));

// Enums

}