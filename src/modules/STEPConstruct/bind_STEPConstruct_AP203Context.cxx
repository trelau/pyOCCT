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
#include <StepBasic_Approval.hxx>
#include <StepBasic_DateAndTime.hxx>
#include <StepBasic_PersonAndOrganization.hxx>
#include <StepBasic_SecurityClassificationLevel.hxx>
#include <StepBasic_PersonAndOrganizationRole.hxx>
#include <StepBasic_DateTimeRole.hxx>
#include <StepBasic_ApprovalRole.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <STEPConstruct_Part.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <StepAP203_CcDesignPersonAndOrganizationAssignment.hxx>
#include <StepAP203_CcDesignSecurityClassification.hxx>
#include <StepAP203_CcDesignDateAndTimeAssignment.hxx>
#include <StepAP203_CcDesignApproval.hxx>
#include <StepBasic_ApprovalPersonOrganization.hxx>
#include <StepBasic_ApprovalDateTime.hxx>
#include <StepBasic_ProductCategoryRelationship.hxx>
#include <STEPConstruct_AP203Context.hxx>

void bind_STEPConstruct_AP203Context(py::module &mod){

py::class_<STEPConstruct_AP203Context> cls_STEPConstruct_AP203Context(mod, "STEPConstruct_AP203Context", "Maintains context specific for AP203 (required data and management information such as persons, dates, approvals etc.) It contains static entities (which can be shared), default values for person and organisation, and also provides tool for creating management entities around specific part (SDR).");

// Constructors
cls_STEPConstruct_AP203Context.def(py::init<>());

// Fields

// Methods
// cls_STEPConstruct_AP203Context.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_AP203Context::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_AP203Context.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_AP203Context::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_AP203Context.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_AP203Context::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_AP203Context.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_AP203Context::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_AP203Context.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_AP203Context::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_AP203Context.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_AP203Context::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_AP203Context.def("DefaultApproval", (opencascade::handle<StepBasic_Approval> (STEPConstruct_AP203Context::*)()) &STEPConstruct_AP203Context::DefaultApproval, "Returns default approval entity which is used when no other data are available");
cls_STEPConstruct_AP203Context.def("SetDefaultApproval", (void (STEPConstruct_AP203Context::*)(const opencascade::handle<StepBasic_Approval> &)) &STEPConstruct_AP203Context::SetDefaultApproval, "Sets default approval", py::arg("app"));
cls_STEPConstruct_AP203Context.def("DefaultDateAndTime", (opencascade::handle<StepBasic_DateAndTime> (STEPConstruct_AP203Context::*)()) &STEPConstruct_AP203Context::DefaultDateAndTime, "Returns default date_and_time entity which is used when no other data are available");
cls_STEPConstruct_AP203Context.def("SetDefaultDateAndTime", (void (STEPConstruct_AP203Context::*)(const opencascade::handle<StepBasic_DateAndTime> &)) &STEPConstruct_AP203Context::SetDefaultDateAndTime, "Sets default date_and_time entity", py::arg("dt"));
cls_STEPConstruct_AP203Context.def("DefaultPersonAndOrganization", (opencascade::handle<StepBasic_PersonAndOrganization> (STEPConstruct_AP203Context::*)()) &STEPConstruct_AP203Context::DefaultPersonAndOrganization, "Returns default person_and_organization entity which is used when no other data are available");
cls_STEPConstruct_AP203Context.def("SetDefaultPersonAndOrganization", (void (STEPConstruct_AP203Context::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &)) &STEPConstruct_AP203Context::SetDefaultPersonAndOrganization, "Sets default person_and_organization entity", py::arg("po"));
cls_STEPConstruct_AP203Context.def("DefaultSecurityClassificationLevel", (opencascade::handle<StepBasic_SecurityClassificationLevel> (STEPConstruct_AP203Context::*)()) &STEPConstruct_AP203Context::DefaultSecurityClassificationLevel, "Returns default security_classification_level entity which is used when no other data are available");
cls_STEPConstruct_AP203Context.def("SetDefaultSecurityClassificationLevel", (void (STEPConstruct_AP203Context::*)(const opencascade::handle<StepBasic_SecurityClassificationLevel> &)) &STEPConstruct_AP203Context::SetDefaultSecurityClassificationLevel, "Sets default security_classification_level", py::arg("sc"));
cls_STEPConstruct_AP203Context.def("RoleCreator", (opencascade::handle<StepBasic_PersonAndOrganizationRole> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::RoleCreator, "None");
cls_STEPConstruct_AP203Context.def("RoleDesignOwner", (opencascade::handle<StepBasic_PersonAndOrganizationRole> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::RoleDesignOwner, "None");
cls_STEPConstruct_AP203Context.def("RoleDesignSupplier", (opencascade::handle<StepBasic_PersonAndOrganizationRole> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::RoleDesignSupplier, "None");
cls_STEPConstruct_AP203Context.def("RoleClassificationOfficer", (opencascade::handle<StepBasic_PersonAndOrganizationRole> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::RoleClassificationOfficer, "None");
cls_STEPConstruct_AP203Context.def("RoleCreationDate", (opencascade::handle<StepBasic_DateTimeRole> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::RoleCreationDate, "None");
cls_STEPConstruct_AP203Context.def("RoleClassificationDate", (opencascade::handle<StepBasic_DateTimeRole> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::RoleClassificationDate, "None");
cls_STEPConstruct_AP203Context.def("RoleApprover", (opencascade::handle<StepBasic_ApprovalRole> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::RoleApprover, "Return predefined PersonAndOrganizationRole and DateTimeRole entities named 'creator', 'design owner', 'design supplier', 'classification officer', 'creation date', 'classification date', 'approver'");
cls_STEPConstruct_AP203Context.def("Init", (void (STEPConstruct_AP203Context::*)(const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &)) &STEPConstruct_AP203Context::Init, "Takes SDR (part) which brings all standard data around part (common for AP203 and AP214) and creates all the additional entities required for AP203", py::arg("sdr"));
cls_STEPConstruct_AP203Context.def("Init", (void (STEPConstruct_AP203Context::*)(const STEPConstruct_Part &)) &STEPConstruct_AP203Context::Init, "Takes tool which describes standard data around part (common for AP203 and AP214) and creates all the additional entities required for AP203", py::arg("SDRTool"));
cls_STEPConstruct_AP203Context.def("Init", (void (STEPConstruct_AP203Context::*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &STEPConstruct_AP203Context::Init, "Takes NAUO which describes assembly link to component and creates the security_classification entity associated to it as required by the AP203", py::arg("nauo"));
cls_STEPConstruct_AP203Context.def("GetCreator", (opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetCreator, "None");
cls_STEPConstruct_AP203Context.def("GetDesignOwner", (opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetDesignOwner, "None");
cls_STEPConstruct_AP203Context.def("GetDesignSupplier", (opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetDesignSupplier, "None");
cls_STEPConstruct_AP203Context.def("GetClassificationOfficer", (opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetClassificationOfficer, "None");
cls_STEPConstruct_AP203Context.def("GetSecurity", (opencascade::handle<StepAP203_CcDesignSecurityClassification> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetSecurity, "None");
cls_STEPConstruct_AP203Context.def("GetCreationDate", (opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetCreationDate, "None");
cls_STEPConstruct_AP203Context.def("GetClassificationDate", (opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetClassificationDate, "None");
cls_STEPConstruct_AP203Context.def("GetApproval", (opencascade::handle<StepAP203_CcDesignApproval> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetApproval, "None");
cls_STEPConstruct_AP203Context.def("GetApprover", (opencascade::handle<StepBasic_ApprovalPersonOrganization> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetApprover, "None");
cls_STEPConstruct_AP203Context.def("GetApprovalDateTime", (opencascade::handle<StepBasic_ApprovalDateTime> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetApprovalDateTime, "None");
cls_STEPConstruct_AP203Context.def("GetProductCategoryRelationship", (opencascade::handle<StepBasic_ProductCategoryRelationship> (STEPConstruct_AP203Context::*)() const) &STEPConstruct_AP203Context::GetProductCategoryRelationship, "Return entities (roots) instantiated for the part by method Init");
cls_STEPConstruct_AP203Context.def("Clear", (void (STEPConstruct_AP203Context::*)()) &STEPConstruct_AP203Context::Clear, "Clears all fields describing entities specific to each part");
cls_STEPConstruct_AP203Context.def("InitRoles", (void (STEPConstruct_AP203Context::*)()) &STEPConstruct_AP203Context::InitRoles, "Initializes constant fields (shared entities)");
cls_STEPConstruct_AP203Context.def("InitAssembly", (void (STEPConstruct_AP203Context::*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &STEPConstruct_AP203Context::InitAssembly, "Initializes all missing data which are required for assembly", py::arg("nauo"));
cls_STEPConstruct_AP203Context.def("InitSecurityRequisites", (void (STEPConstruct_AP203Context::*)()) &STEPConstruct_AP203Context::InitSecurityRequisites, "Initializes ClassificationOfficer and ClassificationDate entities according to Security entity");
cls_STEPConstruct_AP203Context.def("InitApprovalRequisites", (void (STEPConstruct_AP203Context::*)()) &STEPConstruct_AP203Context::InitApprovalRequisites, "Initializes Approver and ApprovalDateTime entities according to Approval entity");

// Enums

}