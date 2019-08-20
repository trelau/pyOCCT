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
#include <StepRepr_StructuralResponseProperty.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepRepr_RWStructuralResponseProperty.hxx>

void bind_RWStepRepr_RWStructuralResponseProperty(py::module &mod){

py::class_<RWStepRepr_RWStructuralResponseProperty, std::unique_ptr<RWStepRepr_RWStructuralResponseProperty>> cls_RWStepRepr_RWStructuralResponseProperty(mod, "RWStepRepr_RWStructuralResponseProperty", "Read & Write tool for StructuralResponseProperty");

// Constructors
cls_RWStepRepr_RWStructuralResponseProperty.def(py::init<>());

// Fields

// Methods
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWStructuralResponseProperty::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWStructuralResponseProperty::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWStructuralResponseProperty::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWStructuralResponseProperty::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWStructuralResponseProperty::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWStructuralResponseProperty.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWStructuralResponseProperty::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWStructuralResponseProperty.def("ReadStep", (void (RWStepRepr_RWStructuralResponseProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_StructuralResponseProperty> &) const) &RWStepRepr_RWStructuralResponseProperty::ReadStep, "Reads StructuralResponseProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWStructuralResponseProperty.def("WriteStep", (void (RWStepRepr_RWStructuralResponseProperty::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_StructuralResponseProperty> &) const) &RWStepRepr_RWStructuralResponseProperty::WriteStep, "Writes StructuralResponseProperty", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWStructuralResponseProperty.def("Share", (void (RWStepRepr_RWStructuralResponseProperty::*)(const opencascade::handle<StepRepr_StructuralResponseProperty> &, Interface_EntityIterator &) const) &RWStepRepr_RWStructuralResponseProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}