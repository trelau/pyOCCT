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
#include <RWStepAP214_ReadWriteModule.hxx>
#include <RWStepAP214_GeneralModule.hxx>
#include <RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.hxx>
#include <RWStepAP214_RWAutoDesignActualDateAssignment.hxx>
#include <RWStepAP214_RWAutoDesignApprovalAssignment.hxx>
#include <RWStepAP214_RWAutoDesignDateAndPersonAssignment.hxx>
#include <RWStepAP214_RWAutoDesignGroupAssignment.hxx>
#include <RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.hxx>
#include <RWStepAP214_RWAutoDesignNominalDateAssignment.hxx>
#include <RWStepAP214_RWAutoDesignOrganizationAssignment.hxx>
#include <RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.hxx>
#include <RWStepAP214_RWAutoDesignPresentedItem.hxx>
#include <RWStepAP214_RWAutoDesignSecurityClassificationAssignment.hxx>
#include <RWStepAP214_RWAutoDesignDocumentReference.hxx>
#include <RWStepAP214_RWAppliedDateAndTimeAssignment.hxx>
#include <RWStepAP214_RWAppliedDateAssignment.hxx>
#include <RWStepAP214_RWAppliedApprovalAssignment.hxx>
#include <RWStepAP214_RWAppliedGroupAssignment.hxx>
#include <RWStepAP214_RWAppliedOrganizationAssignment.hxx>
#include <RWStepAP214_RWAppliedPersonAndOrganizationAssignment.hxx>
#include <RWStepAP214_RWAppliedPresentedItem.hxx>
#include <RWStepAP214_RWAppliedSecurityClassificationAssignment.hxx>
#include <RWStepAP214_RWAppliedDocumentReference.hxx>
#include <RWStepAP214_RWAppliedExternalIdentificationAssignment.hxx>
#include <RWStepAP214_RWClass.hxx>
#include <RWStepAP214_RWExternallyDefinedClass.hxx>
#include <RWStepAP214_RWExternallyDefinedGeneralProperty.hxx>
#include <RWStepAP214_RWRepItemGroup.hxx>
#include <RWStepAP214.hxx>

void bind_RWStepAP214(py::module &mod){

py::class_<RWStepAP214, std::unique_ptr<RWStepAP214>> cls_RWStepAP214(mod, "RWStepAP214", "None");

// Constructors

// Fields

// Methods
// cls_RWStepAP214.def_static("operator new_", (void * (*)(size_t)) &RWStepAP214::operator new, "None", py::arg("theSize"));
// cls_RWStepAP214.def_static("operator delete_", (void (*)(void *)) &RWStepAP214::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP214.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP214::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP214.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP214::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP214.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP214::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP214.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP214::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP214.def_static("Init_", (void (*)()) &RWStepAP214::Init, "enforced the initialisation of the libraries");

// Enums

}