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
#include <StepBasic_ConversionBasedUnit.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepBasic_RWConversionBasedUnit.hxx>

void bind_RWStepBasic_RWConversionBasedUnit(py::module &mod){

py::class_<RWStepBasic_RWConversionBasedUnit, std::unique_ptr<RWStepBasic_RWConversionBasedUnit>> cls_RWStepBasic_RWConversionBasedUnit(mod, "RWStepBasic_RWConversionBasedUnit", "Read & Write Module for ConversionBasedUnit");

// Constructors
cls_RWStepBasic_RWConversionBasedUnit.def(py::init<>());

// Fields

// Methods
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnit::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnit::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWConversionBasedUnit::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWConversionBasedUnit::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWConversionBasedUnit::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWConversionBasedUnit.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWConversionBasedUnit::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWConversionBasedUnit.def("ReadStep", (void (RWStepBasic_RWConversionBasedUnit::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_ConversionBasedUnit> &) const) &RWStepBasic_RWConversionBasedUnit::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnit.def("WriteStep", (void (RWStepBasic_RWConversionBasedUnit::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_ConversionBasedUnit> &) const) &RWStepBasic_RWConversionBasedUnit::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepBasic_RWConversionBasedUnit.def("Share", (void (RWStepBasic_RWConversionBasedUnit::*)(const opencascade::handle<StepBasic_ConversionBasedUnit> &, Interface_EntityIterator &) const) &RWStepBasic_RWConversionBasedUnit::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}