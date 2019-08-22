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
#include <StepAP214_Protocol.hxx>
#include <StepAP214_AutoDesignDateAndPersonItem.hxx>
#include <StepAP214_AutoDesignDateAndTimeItem.hxx>
#include <StepAP214_AutoDesignDatedItem.hxx>
#include <StepAP214_AutoDesignGeneralOrgItem.hxx>
#include <StepAP214_AutoDesignOrganizationItem.hxx>
#include <StepAP214_AutoDesignGroupedItem.hxx>
#include <StepAP214_AutoDesignPresentedItemSelect.hxx>
#include <StepAP214_AutoDesignReferencingItem.hxx>
#include <StepAP214_DateAndTimeItem.hxx>
#include <StepAP214_DateItem.hxx>
#include <StepAP214_ApprovalItem.hxx>
#include <StepAP214_OrganizationItem.hxx>
#include <StepAP214_DocumentReferenceItem.hxx>
#include <StepAP214_GroupItem.hxx>
#include <StepAP214_PersonAndOrganizationItem.hxx>
#include <StepAP214_PresentedItemSelect.hxx>
#include <StepAP214_SecurityClassificationItem.hxx>
#include <StepAP214_AutoDesignApprovalAssignment.hxx>
#include <StepAP214_AutoDesignActualDateAndTimeAssignment.hxx>
#include <StepAP214_AutoDesignNominalDateAndTimeAssignment.hxx>
#include <StepAP214_AutoDesignActualDateAssignment.hxx>
#include <StepAP214_AutoDesignNominalDateAssignment.hxx>
#include <StepAP214_AutoDesignGroupAssignment.hxx>
#include <StepAP214_AutoDesignOrganizationAssignment.hxx>
#include <StepAP214_AutoDesignDateAndPersonAssignment.hxx>
#include <StepAP214_AutoDesignPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AutoDesignPresentedItem.hxx>
#include <StepAP214_AutoDesignSecurityClassificationAssignment.hxx>
#include <StepAP214_AutoDesignDocumentReference.hxx>
#include <StepAP214_AppliedApprovalAssignment.hxx>
#include <StepAP214_AppliedDateAndTimeAssignment.hxx>
#include <StepAP214_AppliedDateAssignment.hxx>
#include <StepAP214_AppliedGroupAssignment.hxx>
#include <StepAP214_AppliedOrganizationAssignment.hxx>
#include <StepAP214_AppliedPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AppliedPresentedItem.hxx>
#include <StepAP214_AppliedSecurityClassificationAssignment.hxx>
#include <StepAP214_AppliedDocumentReference.hxx>
#include <StepAP214_AppliedExternalIdentificationAssignment.hxx>
#include <StepAP214_Class.hxx>
#include <StepAP214_ExternalIdentificationItem.hxx>
#include <StepAP214_ExternallyDefinedClass.hxx>
#include <StepAP214_ExternallyDefinedGeneralProperty.hxx>
#include <StepAP214_RepItemGroup.hxx>
#include <StepAP214.hxx>

void bind_StepAP214(py::module &mod){

py::class_<StepAP214> cls_StepAP214(mod, "StepAP214", "Complete AP214 CC1 , Revision 4 Upgrading from Revision 2 to Revision 4 : 26 Mar 1997 Splitting in sub-schemas : 5 Nov 1997");

// Constructors

// Fields

// Methods
// cls_StepAP214.def_static("operator new_", (void * (*)(size_t)) &StepAP214::operator new, "None", py::arg("theSize"));
// cls_StepAP214.def_static("operator delete_", (void (*)(void *)) &StepAP214::operator delete, "None", py::arg("theAddress"));
// cls_StepAP214.def_static("operator new[]_", (void * (*)(size_t)) &StepAP214::operator new[], "None", py::arg("theSize"));
// cls_StepAP214.def_static("operator delete[]_", (void (*)(void *)) &StepAP214::operator delete[], "None", py::arg("theAddress"));
// cls_StepAP214.def_static("operator new_", (void * (*)(size_t, void *)) &StepAP214::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepAP214.def_static("operator delete_", (void (*)(void *, void *)) &StepAP214::operator delete, "None", py::arg(""), py::arg(""));
cls_StepAP214.def_static("Protocol_", (opencascade::handle<StepAP214_Protocol> (*)()) &StepAP214::Protocol, "creates a Protocol");

// Enums

}