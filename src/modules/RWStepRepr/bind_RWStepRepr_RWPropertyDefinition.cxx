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
#include <StepRepr_PropertyDefinition.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepRepr_RWPropertyDefinition.hxx>

void bind_RWStepRepr_RWPropertyDefinition(py::module &mod){

py::class_<RWStepRepr_RWPropertyDefinition, std::unique_ptr<RWStepRepr_RWPropertyDefinition, Deleter<RWStepRepr_RWPropertyDefinition>>> cls_RWStepRepr_RWPropertyDefinition(mod, "RWStepRepr_RWPropertyDefinition", "Read & Write tool for PropertyDefinition");

// Constructors
cls_RWStepRepr_RWPropertyDefinition.def(py::init<>());

// Fields

// Methods
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWPropertyDefinition::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWPropertyDefinition::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWPropertyDefinition::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWPropertyDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWPropertyDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWPropertyDefinition.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWPropertyDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWPropertyDefinition.def("ReadStep", (void (RWStepRepr_RWPropertyDefinition::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_PropertyDefinition> &) const) &RWStepRepr_RWPropertyDefinition::ReadStep, "Reads PropertyDefinition", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWPropertyDefinition.def("WriteStep", (void (RWStepRepr_RWPropertyDefinition::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_PropertyDefinition> &) const) &RWStepRepr_RWPropertyDefinition::WriteStep, "Writes PropertyDefinition", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWPropertyDefinition.def("Share", (void (RWStepRepr_RWPropertyDefinition::*)(const opencascade::handle<StepRepr_PropertyDefinition> &, Interface_EntityIterator &) const) &RWStepRepr_RWPropertyDefinition::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}