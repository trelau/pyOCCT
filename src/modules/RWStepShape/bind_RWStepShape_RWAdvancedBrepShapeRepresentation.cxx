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
#include <StepShape_AdvancedBrepShapeRepresentation.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepShape_RWAdvancedBrepShapeRepresentation.hxx>

void bind_RWStepShape_RWAdvancedBrepShapeRepresentation(py::module &mod){

py::class_<RWStepShape_RWAdvancedBrepShapeRepresentation, std::unique_ptr<RWStepShape_RWAdvancedBrepShapeRepresentation>> cls_RWStepShape_RWAdvancedBrepShapeRepresentation(mod, "RWStepShape_RWAdvancedBrepShapeRepresentation", "Read & Write Module for AdvancedBrepShapeRepresentation");

// Constructors
cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def(py::init<>());

// Fields

// Methods
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWAdvancedBrepShapeRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def("ReadStep", (void (RWStepShape_RWAdvancedBrepShapeRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> &) const) &RWStepShape_RWAdvancedBrepShapeRepresentation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def("WriteStep", (void (RWStepShape_RWAdvancedBrepShapeRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> &) const) &RWStepShape_RWAdvancedBrepShapeRepresentation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWAdvancedBrepShapeRepresentation.def("Share", (void (RWStepShape_RWAdvancedBrepShapeRepresentation::*)(const opencascade::handle<StepShape_AdvancedBrepShapeRepresentation> &, Interface_EntityIterator &) const) &RWStepShape_RWAdvancedBrepShapeRepresentation::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}