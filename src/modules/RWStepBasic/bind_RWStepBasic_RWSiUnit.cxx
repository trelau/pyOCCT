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
#include <StepBasic_SiUnit.hxx>
#include <StepData_StepWriter.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnitName.hxx>
#include <TCollection_AsciiString.hxx>
#include <RWStepBasic_RWSiUnit.hxx>

void bind_RWStepBasic_RWSiUnit(py::module &mod){

py::class_<RWStepBasic_RWSiUnit, std::unique_ptr<RWStepBasic_RWSiUnit>> cls_RWStepBasic_RWSiUnit(mod, "RWStepBasic_RWSiUnit", "Read & Write Module for SiUnit");

// Constructors
cls_RWStepBasic_RWSiUnit.def(py::init<>());

// Fields

// Methods
// cls_RWStepBasic_RWSiUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWSiUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWSiUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWSiUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWSiUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWSiUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWSiUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWSiUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWSiUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWSiUnit.def("ReadStep", (void (RWStepBasic_RWSiUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_SiUnit> &) const) &RWStepBasic_RWSiUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWSiUnit.def("WriteStep", (void (RWStepBasic_RWSiUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_SiUnit> &) const) &RWStepBasic_RWSiUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWSiUnit.def("DecodePrefix", (Standard_Boolean (RWStepBasic_RWSiUnit::*)(StepBasic_SiPrefix &, const Standard_CString) const) &RWStepBasic_RWSiUnit::DecodePrefix, "None", py::arg("aPrefix"), py::arg("text"));
cls_RWStepBasic_RWSiUnit.def("DecodeName", (Standard_Boolean (RWStepBasic_RWSiUnit::*)(StepBasic_SiUnitName &, const Standard_CString) const) &RWStepBasic_RWSiUnit::DecodeName, "None", py::arg("aName"), py::arg("text"));
cls_RWStepBasic_RWSiUnit.def("EncodePrefix", (TCollection_AsciiString (RWStepBasic_RWSiUnit::*)(const StepBasic_SiPrefix) const) &RWStepBasic_RWSiUnit::EncodePrefix, "None", py::arg("aPrefix"));
cls_RWStepBasic_RWSiUnit.def("EncodeName", (TCollection_AsciiString (RWStepBasic_RWSiUnit::*)(const StepBasic_SiUnitName) const) &RWStepBasic_RWSiUnit::EncodeName, "None", py::arg("aName"));

// Enums

}