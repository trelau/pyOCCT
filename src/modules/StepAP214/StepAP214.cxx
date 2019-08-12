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

void bind_StepAP214(py::module &);
void bind_StepAP214_ApprovalItem(py::module &);
void bind_StepAP214_Array1OfApprovalItem(py::module &);
void bind_StepAP214_HArray1OfApprovalItem(py::module &);
void bind_StepAP214_AppliedApprovalAssignment(py::module &);
void bind_StepAP214_DateAndTimeItem(py::module &);
void bind_StepAP214_Array1OfDateAndTimeItem(py::module &);
void bind_StepAP214_HArray1OfDateAndTimeItem(py::module &);
void bind_StepAP214_AppliedDateAndTimeAssignment(py::module &);
void bind_StepAP214_DateItem(py::module &);
void bind_StepAP214_Array1OfDateItem(py::module &);
void bind_StepAP214_HArray1OfDateItem(py::module &);
void bind_StepAP214_AppliedDateAssignment(py::module &);
void bind_StepAP214_DocumentReferenceItem(py::module &);
void bind_StepAP214_Array1OfDocumentReferenceItem(py::module &);
void bind_StepAP214_HArray1OfDocumentReferenceItem(py::module &);
void bind_StepAP214_AppliedDocumentReference(py::module &);
void bind_StepAP214_ExternalIdentificationItem(py::module &);
void bind_StepAP214_Array1OfExternalIdentificationItem(py::module &);
void bind_StepAP214_HArray1OfExternalIdentificationItem(py::module &);
void bind_StepAP214_AppliedExternalIdentificationAssignment(py::module &);
void bind_StepAP214_GroupItem(py::module &);
void bind_StepAP214_Array1OfGroupItem(py::module &);
void bind_StepAP214_HArray1OfGroupItem(py::module &);
void bind_StepAP214_AppliedGroupAssignment(py::module &);
void bind_StepAP214_OrganizationItem(py::module &);
void bind_StepAP214_Array1OfOrganizationItem(py::module &);
void bind_StepAP214_HArray1OfOrganizationItem(py::module &);
void bind_StepAP214_AppliedOrganizationAssignment(py::module &);
void bind_StepAP214_PersonAndOrganizationItem(py::module &);
void bind_StepAP214_Array1OfPersonAndOrganizationItem(py::module &);
void bind_StepAP214_HArray1OfPersonAndOrganizationItem(py::module &);
void bind_StepAP214_AppliedPersonAndOrganizationAssignment(py::module &);
void bind_StepAP214_PresentedItemSelect(py::module &);
void bind_StepAP214_Array1OfPresentedItemSelect(py::module &);
void bind_StepAP214_HArray1OfPresentedItemSelect(py::module &);
void bind_StepAP214_AppliedPresentedItem(py::module &);
void bind_StepAP214_SecurityClassificationItem(py::module &);
void bind_StepAP214_Array1OfSecurityClassificationItem(py::module &);
void bind_StepAP214_HArray1OfSecurityClassificationItem(py::module &);
void bind_StepAP214_AppliedSecurityClassificationAssignment(py::module &);
void bind_StepAP214_AutoDesignDateAndPersonItem(py::module &);
void bind_StepAP214_Array1OfAutoDesignDateAndPersonItem(py::module &);
void bind_StepAP214_AutoDesignDateAndTimeItem(py::module &);
void bind_StepAP214_Array1OfAutoDesignDateAndTimeItem(py::module &);
void bind_StepAP214_AutoDesignDatedItem(py::module &);
void bind_StepAP214_Array1OfAutoDesignDatedItem(py::module &);
void bind_StepAP214_AutoDesignGeneralOrgItem(py::module &);
void bind_StepAP214_Array1OfAutoDesignGeneralOrgItem(py::module &);
void bind_StepAP214_AutoDesignGroupedItem(py::module &);
void bind_StepAP214_Array1OfAutoDesignGroupedItem(py::module &);
void bind_StepAP214_AutoDesignPresentedItemSelect(py::module &);
void bind_StepAP214_Array1OfAutoDesignPresentedItemSelect(py::module &);
void bind_StepAP214_AutoDesignReferencingItem(py::module &);
void bind_StepAP214_Array1OfAutoDesignReferencingItem(py::module &);
void bind_StepAP214_HArray1OfAutoDesignDateAndTimeItem(py::module &);
void bind_StepAP214_AutoDesignActualDateAndTimeAssignment(py::module &);
void bind_StepAP214_HArray1OfAutoDesignDatedItem(py::module &);
void bind_StepAP214_AutoDesignActualDateAssignment(py::module &);
void bind_StepAP214_HArray1OfAutoDesignGeneralOrgItem(py::module &);
void bind_StepAP214_AutoDesignApprovalAssignment(py::module &);
void bind_StepAP214_HArray1OfAutoDesignDateAndPersonItem(py::module &);
void bind_StepAP214_AutoDesignDateAndPersonAssignment(py::module &);
void bind_StepAP214_HArray1OfAutoDesignReferencingItem(py::module &);
void bind_StepAP214_AutoDesignDocumentReference(py::module &);
void bind_StepAP214_HArray1OfAutoDesignGroupedItem(py::module &);
void bind_StepAP214_AutoDesignGroupAssignment(py::module &);
void bind_StepAP214_AutoDesignNominalDateAndTimeAssignment(py::module &);
void bind_StepAP214_AutoDesignNominalDateAssignment(py::module &);
void bind_StepAP214_AutoDesignOrganizationAssignment(py::module &);
void bind_StepAP214_AutoDesignOrganizationItem(py::module &);
void bind_StepAP214_AutoDesignPersonAndOrganizationAssignment(py::module &);
void bind_StepAP214_HArray1OfAutoDesignPresentedItemSelect(py::module &);
void bind_StepAP214_AutoDesignPresentedItem(py::module &);
void bind_StepAP214_AutoDesignSecurityClassificationAssignment(py::module &);
void bind_StepAP214_Class(py::module &);
void bind_StepAP214_ExternallyDefinedClass(py::module &);
void bind_StepAP214_ExternallyDefinedGeneralProperty(py::module &);
void bind_StepAP214_Protocol(py::module &);
void bind_StepAP214_RepItemGroup(py::module &);

PYBIND11_MODULE(StepAP214, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.StepVisual");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepGeom");
py::module::import("OCCT.Interface");

bind_StepAP214(mod);
bind_StepAP214_ApprovalItem(mod);
bind_StepAP214_Array1OfApprovalItem(mod);
bind_StepAP214_HArray1OfApprovalItem(mod);
bind_StepAP214_AppliedApprovalAssignment(mod);
bind_StepAP214_DateAndTimeItem(mod);
bind_StepAP214_Array1OfDateAndTimeItem(mod);
bind_StepAP214_HArray1OfDateAndTimeItem(mod);
bind_StepAP214_AppliedDateAndTimeAssignment(mod);
bind_StepAP214_DateItem(mod);
bind_StepAP214_Array1OfDateItem(mod);
bind_StepAP214_HArray1OfDateItem(mod);
bind_StepAP214_AppliedDateAssignment(mod);
bind_StepAP214_DocumentReferenceItem(mod);
bind_StepAP214_Array1OfDocumentReferenceItem(mod);
bind_StepAP214_HArray1OfDocumentReferenceItem(mod);
bind_StepAP214_AppliedDocumentReference(mod);
bind_StepAP214_ExternalIdentificationItem(mod);
bind_StepAP214_Array1OfExternalIdentificationItem(mod);
bind_StepAP214_HArray1OfExternalIdentificationItem(mod);
bind_StepAP214_AppliedExternalIdentificationAssignment(mod);
bind_StepAP214_GroupItem(mod);
bind_StepAP214_Array1OfGroupItem(mod);
bind_StepAP214_HArray1OfGroupItem(mod);
bind_StepAP214_AppliedGroupAssignment(mod);
bind_StepAP214_OrganizationItem(mod);
bind_StepAP214_Array1OfOrganizationItem(mod);
bind_StepAP214_HArray1OfOrganizationItem(mod);
bind_StepAP214_AppliedOrganizationAssignment(mod);
bind_StepAP214_PersonAndOrganizationItem(mod);
bind_StepAP214_Array1OfPersonAndOrganizationItem(mod);
bind_StepAP214_HArray1OfPersonAndOrganizationItem(mod);
bind_StepAP214_AppliedPersonAndOrganizationAssignment(mod);
bind_StepAP214_PresentedItemSelect(mod);
bind_StepAP214_Array1OfPresentedItemSelect(mod);
bind_StepAP214_HArray1OfPresentedItemSelect(mod);
bind_StepAP214_AppliedPresentedItem(mod);
bind_StepAP214_SecurityClassificationItem(mod);
bind_StepAP214_Array1OfSecurityClassificationItem(mod);
bind_StepAP214_HArray1OfSecurityClassificationItem(mod);
bind_StepAP214_AppliedSecurityClassificationAssignment(mod);
bind_StepAP214_AutoDesignDateAndPersonItem(mod);
bind_StepAP214_Array1OfAutoDesignDateAndPersonItem(mod);
bind_StepAP214_AutoDesignDateAndTimeItem(mod);
bind_StepAP214_Array1OfAutoDesignDateAndTimeItem(mod);
bind_StepAP214_AutoDesignDatedItem(mod);
bind_StepAP214_Array1OfAutoDesignDatedItem(mod);
bind_StepAP214_AutoDesignGeneralOrgItem(mod);
bind_StepAP214_Array1OfAutoDesignGeneralOrgItem(mod);
bind_StepAP214_AutoDesignGroupedItem(mod);
bind_StepAP214_Array1OfAutoDesignGroupedItem(mod);
bind_StepAP214_AutoDesignPresentedItemSelect(mod);
bind_StepAP214_Array1OfAutoDesignPresentedItemSelect(mod);
bind_StepAP214_AutoDesignReferencingItem(mod);
bind_StepAP214_Array1OfAutoDesignReferencingItem(mod);
bind_StepAP214_HArray1OfAutoDesignDateAndTimeItem(mod);
bind_StepAP214_AutoDesignActualDateAndTimeAssignment(mod);
bind_StepAP214_HArray1OfAutoDesignDatedItem(mod);
bind_StepAP214_AutoDesignActualDateAssignment(mod);
bind_StepAP214_HArray1OfAutoDesignGeneralOrgItem(mod);
bind_StepAP214_AutoDesignApprovalAssignment(mod);
bind_StepAP214_HArray1OfAutoDesignDateAndPersonItem(mod);
bind_StepAP214_AutoDesignDateAndPersonAssignment(mod);
bind_StepAP214_HArray1OfAutoDesignReferencingItem(mod);
bind_StepAP214_AutoDesignDocumentReference(mod);
bind_StepAP214_HArray1OfAutoDesignGroupedItem(mod);
bind_StepAP214_AutoDesignGroupAssignment(mod);
bind_StepAP214_AutoDesignNominalDateAndTimeAssignment(mod);
bind_StepAP214_AutoDesignNominalDateAssignment(mod);
bind_StepAP214_AutoDesignOrganizationAssignment(mod);
bind_StepAP214_AutoDesignOrganizationItem(mod);
bind_StepAP214_AutoDesignPersonAndOrganizationAssignment(mod);
bind_StepAP214_HArray1OfAutoDesignPresentedItemSelect(mod);
bind_StepAP214_AutoDesignPresentedItem(mod);
bind_StepAP214_AutoDesignSecurityClassificationAssignment(mod);
bind_StepAP214_Class(mod);
bind_StepAP214_ExternallyDefinedClass(mod);
bind_StepAP214_ExternallyDefinedGeneralProperty(mod);
bind_StepAP214_Protocol(mod);
bind_StepAP214_RepItemGroup(mod);

}
