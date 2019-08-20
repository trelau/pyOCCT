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
#include <StepBasic_OrganizationRole.hxx>
#include <StepData_StepWriter.hxx>
#include <RWStepBasic_RWOrganizationRole.hxx>

void bind_RWStepBasic_RWOrganizationRole(py::module &mod){

py::class_<RWStepBasic_RWOrganizationRole, std::unique_ptr<RWStepBasic_RWOrganizationRole>> cls_RWStepBasic_RWOrganizationRole(mod, "RWStepBasic_RWOrganizationRole", "Read & Write Module for OrganizationRole");

// Constructors
cls_RWStepBasic_RWOrganizationRole.def(py::init<>());

// Fields

// Methods
// cls_RWStepBasic_RWOrganizationRole.def_static("operator new_", (void * (*)(size_t)) &RWStepBasic_RWOrganizationRole::operator new, "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator delete_", (void (*)(void *)) &RWStepBasic_RWOrganizationRole::operator delete, "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator new[]_", (void * (*)(size_t)) &RWStepBasic_RWOrganizationRole::operator new[], "None", py::arg("theSize"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator delete[]_", (void (*)(void *)) &RWStepBasic_RWOrganizationRole::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepBasic_RWOrganizationRole::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepBasic_RWOrganizationRole.def_static("operator delete_", (void (*)(void *, void *)) &RWStepBasic_RWOrganizationRole::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepBasic_RWOrganizationRole.def("ReadStep", (void (RWStepBasic_RWOrganizationRole::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepBasic_OrganizationRole> &) const) &RWStepBasic_RWOrganizationRole::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepBasic_RWOrganizationRole.def("WriteStep", (void (RWStepBasic_RWOrganizationRole::*)(StepData_StepWriter &, const opencascade::handle<StepBasic_OrganizationRole> &) const) &RWStepBasic_RWOrganizationRole::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// Enums

}