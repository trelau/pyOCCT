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
#include <StepRepr_FeatureForDatumTargetRelationship.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepRepr_RWFeatureForDatumTargetRelationship.hxx>

void bind_RWStepRepr_RWFeatureForDatumTargetRelationship(py::module &mod){

py::class_<RWStepRepr_RWFeatureForDatumTargetRelationship, std::unique_ptr<RWStepRepr_RWFeatureForDatumTargetRelationship, Deleter<RWStepRepr_RWFeatureForDatumTargetRelationship>>> cls_RWStepRepr_RWFeatureForDatumTargetRelationship(mod, "RWStepRepr_RWFeatureForDatumTargetRelationship", "Read & Write tool for FeatureForDatumTargetRelationship");

// Constructors
cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def(py::init<>());

// Fields

// Methods
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWFeatureForDatumTargetRelationship::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def("ReadStep", (void (RWStepRepr_RWFeatureForDatumTargetRelationship::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_FeatureForDatumTargetRelationship> &) const) &RWStepRepr_RWFeatureForDatumTargetRelationship::ReadStep, "Reads ShapeAspectRelationship", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def("WriteStep", (void (RWStepRepr_RWFeatureForDatumTargetRelationship::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_FeatureForDatumTargetRelationship> &) const) &RWStepRepr_RWFeatureForDatumTargetRelationship::WriteStep, "Writes ShapeAspectRelationship", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWFeatureForDatumTargetRelationship.def("Share", (void (RWStepRepr_RWFeatureForDatumTargetRelationship::*)(const opencascade::handle<StepRepr_FeatureForDatumTargetRelationship> &, Interface_EntityIterator &) const) &RWStepRepr_RWFeatureForDatumTargetRelationship::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}