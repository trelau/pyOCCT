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
#include <StepFEA_Volume3dElementRepresentation.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepFEA_RWVolume3dElementRepresentation.hxx>

void bind_RWStepFEA_RWVolume3dElementRepresentation(py::module &mod){

py::class_<RWStepFEA_RWVolume3dElementRepresentation, std::unique_ptr<RWStepFEA_RWVolume3dElementRepresentation>> cls_RWStepFEA_RWVolume3dElementRepresentation(mod, "RWStepFEA_RWVolume3dElementRepresentation", "Read & Write tool for Volume3dElementRepresentation");

// Constructors
cls_RWStepFEA_RWVolume3dElementRepresentation.def(py::init<>());

// Fields

// Methods
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator new_", (void * (*)(size_t)) &RWStepFEA_RWVolume3dElementRepresentation::operator new, "None", py::arg("theSize"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator delete_", (void (*)(void *)) &RWStepFEA_RWVolume3dElementRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepFEA_RWVolume3dElementRepresentation::operator new[], "None", py::arg("theSize"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator delete[]_", (void (*)(void *)) &RWStepFEA_RWVolume3dElementRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepFEA_RWVolume3dElementRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepFEA_RWVolume3dElementRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepFEA_RWVolume3dElementRepresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepFEA_RWVolume3dElementRepresentation.def("ReadStep", (void (RWStepFEA_RWVolume3dElementRepresentation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepFEA_Volume3dElementRepresentation> &) const) &RWStepFEA_RWVolume3dElementRepresentation::ReadStep, "Reads Volume3dElementRepresentation", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepFEA_RWVolume3dElementRepresentation.def("WriteStep", (void (RWStepFEA_RWVolume3dElementRepresentation::*)(StepData_StepWriter &, const opencascade::handle<StepFEA_Volume3dElementRepresentation> &) const) &RWStepFEA_RWVolume3dElementRepresentation::WriteStep, "Writes Volume3dElementRepresentation", py::arg("SW"), py::arg("ent"));
cls_RWStepFEA_RWVolume3dElementRepresentation.def("Share", (void (RWStepFEA_RWVolume3dElementRepresentation::*)(const opencascade::handle<StepFEA_Volume3dElementRepresentation> &, Interface_EntityIterator &) const) &RWStepFEA_RWVolume3dElementRepresentation::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// Enums

}