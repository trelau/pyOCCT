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
#include <XSControl_WorkSession.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Graph.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Transfer_FinderProcess.hxx>
#include <Interface_HGraph.hxx>
#include <STEPConstruct_Tool.hxx>
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
#include <StepData_StepModel.hxx>
#include <StepBasic_ApplicationProtocolDefinition.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <STEPConstruct_Assembly.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <STEPConstruct_ContextTool.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <TopoDS_Shape.hxx>
#include <TopLoc_Location.hxx>
#include <Transfer_Binder.hxx>
#include <StepShape_ContextDependentShapeRepresentation.hxx>
#include <STEPConstruct_UnitContext.hxx>
#include <STEPConstruct_Styles.hxx>
#include <STEPConstruct_ValidationProps.hxx>
#include <STEPConstruct_ExternRefs.hxx>
#include <STEPConstruct_PointHasher.hxx>
#include <STEPConstruct.hxx>
#include <Standard_Transient.hxx>
#include <StepShape_ShapeRepresentation.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <STEPConstruct_DataMapOfAsciiStringTransient.hxx>
#include <gp_Pnt.hxx>
#include <STEPConstruct_DataMapOfPointTransient.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepAP214_AppliedDocumentReference.hxx>
#include <StepBasic_DocumentFile.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <StepBasic_ProductRelatedProductCategory.hxx>
#include <StepBasic_DocumentType.hxx>
#include <StepBasic_ProductDefinitionContext.hxx>
#include <StepBasic_ProductContext.hxx>
#include <StepBasic_ApplicationContext.hxx>
#include <StepBasic_Product.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepVisual_StyledItem.hxx>
#include <StepVisual_PresentationStyleAssignment.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepVisual_MechanicalDesignGeometricPresentationRepresentation.hxx>
#include <StepVisual_Colour.hxx>
#include <Quantity_Color.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.hxx>
#include <StepRepr_GlobalUnitAssignedContext.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <StepRepr_GlobalUncertaintyAssignedContext.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnit.hxx>
#include <StepRepr_CharacterizedDefinition.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <StepBasic_Unit.hxx>
#include <bind_NCollection_DataMap.hxx>

PYBIND11_MODULE(STEPConstruct, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.XSControl");
py::module::import("OCCT.Interface");
py::module::import("OCCT.Transfer");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.StepAP203");
py::module::import("OCCT.StepData");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepGeom");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.StepAP214");
py::module::import("OCCT.StepVisual");
py::module::import("OCCT.Quantity");

// CLASS: STEPCONSTRUCT_TOOL
py::class_<STEPConstruct_Tool> cls_STEPConstruct_Tool(mod, "STEPConstruct_Tool", "Provides basic functionalities for tools which are intended for encoding/decoding specific STEP constructs");

// Constructors
cls_STEPConstruct_Tool.def(py::init<>());
cls_STEPConstruct_Tool.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));

// Methods
// cls_STEPConstruct_Tool.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_Tool::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_Tool.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_Tool::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_Tool.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_Tool::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_Tool.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_Tool.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_Tool.def("WS", (const opencascade::handle<XSControl_WorkSession> & (STEPConstruct_Tool::*)() const) &STEPConstruct_Tool::WS, "Returns currently loaded WorkSession");
cls_STEPConstruct_Tool.def("Model", (opencascade::handle<Interface_InterfaceModel> (STEPConstruct_Tool::*)() const) &STEPConstruct_Tool::Model, "Returns current model (Null if not loaded)");
cls_STEPConstruct_Tool.def("Graph", [](STEPConstruct_Tool &self) -> const Interface_Graph & { return self.Graph(); });
cls_STEPConstruct_Tool.def("Graph", (const Interface_Graph & (STEPConstruct_Tool::*)(const Standard_Boolean) const) &STEPConstruct_Tool::Graph, "Returns current graph (recomputing if necessary)", py::arg("recompute"));
cls_STEPConstruct_Tool.def("TransientProcess", (const opencascade::handle<Transfer_TransientProcess> & (STEPConstruct_Tool::*)() const) &STEPConstruct_Tool::TransientProcess, "Returns TransientProcess (reading; Null if not loaded)");
cls_STEPConstruct_Tool.def("FinderProcess", (const opencascade::handle<Transfer_FinderProcess> & (STEPConstruct_Tool::*)() const) &STEPConstruct_Tool::FinderProcess, "Returns FinderProcess (writing; Null if not loaded)");

// CLASS: STEPCONSTRUCT_AP203CONTEXT
py::class_<STEPConstruct_AP203Context> cls_STEPConstruct_AP203Context(mod, "STEPConstruct_AP203Context", "Maintains context specific for AP203 (required data and management information such as persons, dates, approvals etc.) It contains static entities (which can be shared), default values for person and organisation, and also provides tool for creating management entities around specific part (SDR).");

// Constructors
cls_STEPConstruct_AP203Context.def(py::init<>());

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

// CLASS: STEPCONSTRUCT_CONTEXTTOOL
py::class_<STEPConstruct_ContextTool> cls_STEPConstruct_ContextTool(mod, "STEPConstruct_ContextTool", "Maintains global context tool for writing. Gives access to Product Definition Context (one per Model) Maintains ApplicationProtocolDefinition entity (common for all products) Also maintains context specific for AP203 and provides set of methods to work with various STEP constructs as required by Actor");

// Constructors
cls_STEPConstruct_ContextTool.def(py::init<>());
cls_STEPConstruct_ContextTool.def(py::init<const opencascade::handle<StepData_StepModel> &>(), py::arg("aStepModel"));

// Methods
// cls_STEPConstruct_ContextTool.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_ContextTool::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_ContextTool.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_ContextTool::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_ContextTool.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_ContextTool::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_ContextTool.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_ContextTool::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_ContextTool.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_ContextTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_ContextTool.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_ContextTool::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_ContextTool.def("SetModel", (void (STEPConstruct_ContextTool::*)(const opencascade::handle<StepData_StepModel> &)) &STEPConstruct_ContextTool::SetModel, "Initialize ApplicationProtocolDefinition by the first entity of that type found in the model", py::arg("aStepModel"));
cls_STEPConstruct_ContextTool.def("GetAPD", (opencascade::handle<StepBasic_ApplicationProtocolDefinition> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetAPD, "None");
cls_STEPConstruct_ContextTool.def("AddAPD", [](STEPConstruct_ContextTool &self) -> void { return self.AddAPD(); });
cls_STEPConstruct_ContextTool.def("AddAPD", (void (STEPConstruct_ContextTool::*)(const Standard_Boolean)) &STEPConstruct_ContextTool::AddAPD, "None", py::arg("enforce"));
cls_STEPConstruct_ContextTool.def("IsAP203", (Standard_Boolean (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::IsAP203, "Returns True if APD.schema_name is config_control_design");
cls_STEPConstruct_ContextTool.def("IsAP214", (Standard_Boolean (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::IsAP214, "Returns True if APD.schema_name is automotive_design");
cls_STEPConstruct_ContextTool.def("IsAP242", (Standard_Boolean (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::IsAP242, "Returns True if APD.schema_name is ap242_managed_model_based_3d_engineering");
cls_STEPConstruct_ContextTool.def("GetACstatus", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetACstatus, "None");
cls_STEPConstruct_ContextTool.def("GetACschemaName", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetACschemaName, "None");
cls_STEPConstruct_ContextTool.def("GetACyear", (Standard_Integer (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetACyear, "None");
cls_STEPConstruct_ContextTool.def("GetACname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetACname, "None");
cls_STEPConstruct_ContextTool.def("SetACstatus", (void (STEPConstruct_ContextTool::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_ContextTool::SetACstatus, "None", py::arg("status"));
cls_STEPConstruct_ContextTool.def("SetACschemaName", (void (STEPConstruct_ContextTool::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_ContextTool::SetACschemaName, "None", py::arg("schemaName"));
cls_STEPConstruct_ContextTool.def("SetACyear", (void (STEPConstruct_ContextTool::*)(const Standard_Integer)) &STEPConstruct_ContextTool::SetACyear, "None", py::arg("year"));
cls_STEPConstruct_ContextTool.def("SetACname", (void (STEPConstruct_ContextTool::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_ContextTool::SetACname, "None", py::arg("name"));
cls_STEPConstruct_ContextTool.def("GetDefaultAxis", (opencascade::handle<StepGeom_Axis2Placement3d> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetDefaultAxis, "Returns a default axis placement");
cls_STEPConstruct_ContextTool.def("AP203Context", (STEPConstruct_AP203Context & (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::AP203Context, "Returns tool which maintains context specific for AP203");
cls_STEPConstruct_ContextTool.def("Level", (Standard_Integer (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::Level, "Returns current assembly level");
cls_STEPConstruct_ContextTool.def("NextLevel", (void (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::NextLevel, "None");
cls_STEPConstruct_ContextTool.def("PrevLevel", (void (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::PrevLevel, "None");
cls_STEPConstruct_ContextTool.def("SetLevel", (void (STEPConstruct_ContextTool::*)(const Standard_Integer)) &STEPConstruct_ContextTool::SetLevel, "Changes current assembly level", py::arg("lev"));
cls_STEPConstruct_ContextTool.def("Index", (Standard_Integer (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::Index, "Returns current index of assembly component on current level");
cls_STEPConstruct_ContextTool.def("NextIndex", (void (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::NextIndex, "None");
cls_STEPConstruct_ContextTool.def("PrevIndex", (void (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::PrevIndex, "None");
cls_STEPConstruct_ContextTool.def("SetIndex", (void (STEPConstruct_ContextTool::*)(const Standard_Integer)) &STEPConstruct_ContextTool::SetIndex, "Changes current index of assembly component on current level", py::arg("ind"));
cls_STEPConstruct_ContextTool.def("GetProductName", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::GetProductName, "Generates a product name basing on write.step.product.name parameter and current position in the assembly structure");
cls_STEPConstruct_ContextTool.def("GetRootsForPart", (opencascade::handle<TColStd_HSequenceOfTransient> (STEPConstruct_ContextTool::*)(const STEPConstruct_Part &)) &STEPConstruct_ContextTool::GetRootsForPart, "Produces and returns a full list of root entities required for part identified by SDRTool (including SDR itself)", py::arg("SDRTool"));
cls_STEPConstruct_ContextTool.def("GetRootsForAssemblyLink", (opencascade::handle<TColStd_HSequenceOfTransient> (STEPConstruct_ContextTool::*)(const STEPConstruct_Assembly &)) &STEPConstruct_ContextTool::GetRootsForAssemblyLink, "Produces and returns a full list of root entities required for assembly link identified by assembly (including NAUO and CDSR)", py::arg("assembly"));

// CLASS: STEPCONSTRUCT
py::class_<STEPConstruct> cls_STEPConstruct(mod, "STEPConstruct", "Defines tools for creation and investigation STEP constructs used for representing various kinds of data, such as product and assembly structure, unit contexts, associated information The creation of these structures is made according to currently active schema (AP203 or AP214 CD2 or DIS) This is taken from parameter write.step.schema");

// Methods
// cls_STEPConstruct.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct.def_static("operator delete_", (void (*)(void *)) &STEPConstruct::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct.def_static("FindEntity_", (opencascade::handle<StepRepr_RepresentationItem> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &)) &STEPConstruct::FindEntity, "Returns STEP entity of the (sub)type of RepresentationItem which is a result of the tranalation of the Shape, or Null if no result is recorded", py::arg("FinderProcess"), py::arg("Shape"));
cls_STEPConstruct.def_static("FindEntity_", (opencascade::handle<StepRepr_RepresentationItem> (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &, TopLoc_Location &)) &STEPConstruct::FindEntity, "The same as above, but in the case if item not found, repeats search on the same shape without location. The Loc corresponds to the location with which result is found (either location of the Shape, or Null)", py::arg("FinderProcess"), py::arg("Shape"), py::arg("Loc"));
cls_STEPConstruct.def_static("FindShape_", (TopoDS_Shape (*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<StepRepr_RepresentationItem> &)) &STEPConstruct::FindShape, "Returns Shape resulting from given STEP entity (Null if not mapped)", py::arg("TransientProcess"), py::arg("item"));
cls_STEPConstruct.def_static("FindCDSR_", (Standard_Boolean (*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, opencascade::handle<StepShape_ContextDependentShapeRepresentation> &)) &STEPConstruct::FindCDSR, "Find CDSR correcponding to the component in the specified assembly", py::arg("ComponentBinder"), py::arg("AssemblySDR"), py::arg("ComponentCDSR"));

// CLASS: STEPCONSTRUCT_ASSEMBLY
py::class_<STEPConstruct_Assembly> cls_STEPConstruct_Assembly(mod, "STEPConstruct_Assembly", "This operator creates and checks an item of an assembly, from its basic data : a ShapeRepresentation, a Location ...");

// Constructors
cls_STEPConstruct_Assembly.def(py::init<>());

// Methods
// cls_STEPConstruct_Assembly.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_Assembly::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_Assembly.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_Assembly::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_Assembly.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_Assembly::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_Assembly.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_Assembly::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_Assembly.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_Assembly::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_Assembly.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_Assembly::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_Assembly.def("Init", (void (STEPConstruct_Assembly::*)(const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepGeom_Axis2Placement3d> &)) &STEPConstruct_Assembly::Init, "Initialises with starting values Ax0 : origin axis (typically, standard XYZ) Loc : location to which place the item Makes a MappedItem Resulting Value is returned by ItemValue", py::arg("aSR"), py::arg("SDR0"), py::arg("Ax0"), py::arg("Loc"));
cls_STEPConstruct_Assembly.def("MakeRelationship", (void (STEPConstruct_Assembly::*)()) &STEPConstruct_Assembly::MakeRelationship, "Make a (ShapeRepresentationRelationship,...WithTransformation) Resulting Value is returned by ItemValue");
cls_STEPConstruct_Assembly.def("ItemValue", (opencascade::handle<Standard_Transient> (STEPConstruct_Assembly::*)() const) &STEPConstruct_Assembly::ItemValue, "Returns the Value If no Make... has been called, returns the starting SR");
cls_STEPConstruct_Assembly.def("ItemLocation", (opencascade::handle<StepGeom_Axis2Placement3d> (STEPConstruct_Assembly::*)() const) &STEPConstruct_Assembly::ItemLocation, "Returns the location of the item, computed from starting aLoc");
cls_STEPConstruct_Assembly.def("GetNAUO", (opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> (STEPConstruct_Assembly::*)() const) &STEPConstruct_Assembly::GetNAUO, "Returns NAUO object describing the assembly link");
cls_STEPConstruct_Assembly.def_static("CheckSRRReversesNAUO_", (Standard_Boolean (*)(const Interface_Graph &, const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &)) &STEPConstruct_Assembly::CheckSRRReversesNAUO, "Checks whether SRR's definition of assembly and component contradicts with NAUO definition or not, according to model schema (AP214 or AP203)", py::arg("theGraph"), py::arg("CDSR"));

// TYPEDEF: STEPCONSTRUCT_DATAMAPOFASCIISTRINGTRANSIENT
bind_NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient>, TCollection_AsciiString>(mod, "STEPConstruct_DataMapOfAsciiStringTransient", py::module_local(false));

// TYPEDEF: STEPCONSTRUCT_DATAMAPITERATOROFDATAMAPOFASCIISTRINGTRANSIENT

// CLASS: STEPCONSTRUCT_POINTHASHER
py::class_<STEPConstruct_PointHasher> cls_STEPConstruct_PointHasher(mod, "STEPConstruct_PointHasher", "None");

// Methods
// cls_STEPConstruct_PointHasher.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_PointHasher::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_PointHasher.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_PointHasher::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_PointHasher.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_PointHasher::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_PointHasher.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_PointHasher::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_PointHasher.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_PointHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_PointHasher.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_PointHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_PointHasher.def_static("HashCode_", (Standard_Integer (*)(const gp_Pnt &, const Standard_Integer)) &STEPConstruct_PointHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("Point"), py::arg("Upper"));
cls_STEPConstruct_PointHasher.def_static("IsEqual_", (Standard_Boolean (*)(const gp_Pnt &, const gp_Pnt &)) &STEPConstruct_PointHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("Point1"), py::arg("Point2"));

// TYPEDEF: STEPCONSTRUCT_DATAMAPOFPOINTTRANSIENT
bind_NCollection_DataMap<gp_Pnt, opencascade::handle<Standard_Transient>, STEPConstruct_PointHasher>(mod, "STEPConstruct_DataMapOfPointTransient", py::module_local(false));

// TYPEDEF: STEPCONSTRUCT_DATAMAPITERATOROFDATAMAPOFPOINTTRANSIENT

// CLASS: STEPCONSTRUCT_EXTERNREFS
py::class_<STEPConstruct_ExternRefs, STEPConstruct_Tool> cls_STEPConstruct_ExternRefs(mod, "STEPConstruct_ExternRefs", "Provides a tool for analyzing (reading) and creating (writing) references to external files in STEP");

// Constructors
cls_STEPConstruct_ExternRefs.def(py::init<>());
cls_STEPConstruct_ExternRefs.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));

// Methods
// cls_STEPConstruct_ExternRefs.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_ExternRefs::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_ExternRefs.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_ExternRefs::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_ExternRefs.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_ExternRefs::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_ExternRefs.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_ExternRefs::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_ExternRefs.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_ExternRefs::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_ExternRefs.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_ExternRefs::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_ExternRefs.def("Init", (Standard_Boolean (STEPConstruct_ExternRefs::*)(const opencascade::handle<XSControl_WorkSession> &)) &STEPConstruct_ExternRefs::Init, "Initializes tool; returns True if succeeded", py::arg("WS"));
cls_STEPConstruct_ExternRefs.def("Clear", (void (STEPConstruct_ExternRefs::*)()) &STEPConstruct_ExternRefs::Clear, "Clears internal fields (list of defined extern refs)");
cls_STEPConstruct_ExternRefs.def("LoadExternRefs", (Standard_Boolean (STEPConstruct_ExternRefs::*)()) &STEPConstruct_ExternRefs::LoadExternRefs, "Searches current STEP model for external references and loads them to the internal data structures NOTE: does not clear data structures before loading");
cls_STEPConstruct_ExternRefs.def("NbExternRefs", (Standard_Integer (STEPConstruct_ExternRefs::*)() const) &STEPConstruct_ExternRefs::NbExternRefs, "Returns number of defined extern references");
cls_STEPConstruct_ExternRefs.def("FileName", (Standard_CString (STEPConstruct_ExternRefs::*)(const Standard_Integer) const) &STEPConstruct_ExternRefs::FileName, "Returns filename for numth extern reference Returns Null if FileName is not defined or bad", py::arg("num"));
cls_STEPConstruct_ExternRefs.def("ProdDef", (opencascade::handle<StepBasic_ProductDefinition> (STEPConstruct_ExternRefs::*)(const Standard_Integer) const) &STEPConstruct_ExternRefs::ProdDef, "Returns ProductDefinition to which numth extern reference is associated. Returns Null if cannot be detected or if extern reference is not associated to SDR in a proper way.", py::arg("num"));
cls_STEPConstruct_ExternRefs.def("Format", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ExternRefs::*)(const Standard_Integer) const) &STEPConstruct_ExternRefs::Format, "Returns format identification string for the extern document Returns Null handle if format is not defined", py::arg("num"));
cls_STEPConstruct_ExternRefs.def("AddExternRef", (Standard_Integer (STEPConstruct_ExternRefs::*)(const Standard_CString, const opencascade::handle<StepBasic_ProductDefinition> &, const Standard_CString)) &STEPConstruct_ExternRefs::AddExternRef, "Create a new external reference with specified attributes attached to a given SDR <format> can be Null string, in that case this information is not written. Else, it can be 'STEP AP214' or 'STEP AP203' Returns index of a new extern ref", py::arg("filename"), py::arg("PD"), py::arg("format"));
cls_STEPConstruct_ExternRefs.def("checkAP214Shared", (void (STEPConstruct_ExternRefs::*)()) &STEPConstruct_ExternRefs::checkAP214Shared, "Check (create if it is null) all shared entities for the model");
cls_STEPConstruct_ExternRefs.def("WriteExternRefs", (Standard_Integer (STEPConstruct_ExternRefs::*)(const Standard_Integer) const) &STEPConstruct_ExternRefs::WriteExternRefs, "Adds all the currently defined external refs to the model Returns number of written extern refs", py::arg("num"));
cls_STEPConstruct_ExternRefs.def("SetAP214APD", (void (STEPConstruct_ExternRefs::*)(const opencascade::handle<StepBasic_ApplicationProtocolDefinition> &)) &STEPConstruct_ExternRefs::SetAP214APD, "Set the ApplicationProtocolDefinition of the PDM schema", py::arg("APD"));
cls_STEPConstruct_ExternRefs.def("GetAP214APD", (opencascade::handle<StepBasic_ApplicationProtocolDefinition> (STEPConstruct_ExternRefs::*)()) &STEPConstruct_ExternRefs::GetAP214APD, "Returns the ApplicationProtocolDefinition of the PDM schema NOTE: if not defined then create new APD with new Application Context");

// CLASS: STEPCONSTRUCT_PART
py::class_<STEPConstruct_Part> cls_STEPConstruct_Part(mod, "STEPConstruct_Part", "Provides tools for creating STEP structures associated with part (SDR), such as PRODUCT, PDF etc., as requied by current schema Also allows to investigate and modify this data");

// Constructors
cls_STEPConstruct_Part.def(py::init<>());

// Methods
// cls_STEPConstruct_Part.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_Part::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_Part.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_Part::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_Part.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_Part::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_Part.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_Part::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_Part.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_Part::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_Part.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_Part::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_Part.def("MakeSDR", (void (STEPConstruct_Part::*)(const opencascade::handle<StepShape_ShapeRepresentation> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ApplicationContext> &)) &STEPConstruct_Part::MakeSDR, "None", py::arg("aShape"), py::arg("aName"), py::arg("AC"));
cls_STEPConstruct_Part.def("ReadSDR", (void (STEPConstruct_Part::*)(const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &)) &STEPConstruct_Part::ReadSDR, "None", py::arg("aShape"));
cls_STEPConstruct_Part.def("IsDone", (Standard_Boolean (STEPConstruct_Part::*)() const) &STEPConstruct_Part::IsDone, "None");
cls_STEPConstruct_Part.def("SDRValue", (opencascade::handle<StepShape_ShapeDefinitionRepresentation> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::SDRValue, "Returns SDR or Null if not done");
cls_STEPConstruct_Part.def("SRValue", (opencascade::handle<StepShape_ShapeRepresentation> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::SRValue, "Returns SDR->UsedRepresentation() or Null if not done");
cls_STEPConstruct_Part.def("PC", (opencascade::handle<StepBasic_ProductContext> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PC, "None");
cls_STEPConstruct_Part.def("PCname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PCname, "None");
cls_STEPConstruct_Part.def("PCdisciplineType", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PCdisciplineType, "None");
cls_STEPConstruct_Part.def("SetPCname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPCname, "None", py::arg("name"));
cls_STEPConstruct_Part.def("SetPCdisciplineType", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPCdisciplineType, "None", py::arg("label"));
cls_STEPConstruct_Part.def("AC", (opencascade::handle<StepBasic_ApplicationContext> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::AC, "None");
cls_STEPConstruct_Part.def("ACapplication", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::ACapplication, "None");
cls_STEPConstruct_Part.def("SetACapplication", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetACapplication, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PDC", (opencascade::handle<StepBasic_ProductDefinitionContext> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDC, "None");
cls_STEPConstruct_Part.def("PDCname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDCname, "None");
cls_STEPConstruct_Part.def("PDCstage", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDCstage, "None");
cls_STEPConstruct_Part.def("SetPDCname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDCname, "None", py::arg("label"));
cls_STEPConstruct_Part.def("SetPDCstage", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDCstage, "None", py::arg("label"));
cls_STEPConstruct_Part.def("Product", (opencascade::handle<StepBasic_Product> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::Product, "None");
cls_STEPConstruct_Part.def("Pid", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::Pid, "None");
cls_STEPConstruct_Part.def("Pname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::Pname, "None");
cls_STEPConstruct_Part.def("Pdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::Pdescription, "None");
cls_STEPConstruct_Part.def("SetPid", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPid, "None", py::arg("id"));
cls_STEPConstruct_Part.def("SetPname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPname, "None", py::arg("label"));
cls_STEPConstruct_Part.def("SetPdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPdescription, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PDF", (opencascade::handle<StepBasic_ProductDefinitionFormation> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDF, "None");
cls_STEPConstruct_Part.def("PDFid", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDFid, "None");
cls_STEPConstruct_Part.def("PDFdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDFdescription, "None");
cls_STEPConstruct_Part.def("SetPDFid", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDFid, "None", py::arg("id"));
cls_STEPConstruct_Part.def("SetPDFdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDFdescription, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PD", (opencascade::handle<StepBasic_ProductDefinition> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PD, "None");
cls_STEPConstruct_Part.def("PDdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDdescription, "None");
cls_STEPConstruct_Part.def("SetPDdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDdescription, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PDS", (opencascade::handle<StepRepr_ProductDefinitionShape> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDS, "None");
cls_STEPConstruct_Part.def("PDSname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDSname, "None");
cls_STEPConstruct_Part.def("PDSdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PDSdescription, "None");
cls_STEPConstruct_Part.def("SetPDSname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDSname, "None", py::arg("label"));
cls_STEPConstruct_Part.def("SetPDSdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPDSdescription, "None", py::arg("text"));
cls_STEPConstruct_Part.def("PRPC", (opencascade::handle<StepBasic_ProductRelatedProductCategory> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PRPC, "None");
cls_STEPConstruct_Part.def("PRPCname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PRPCname, "None");
cls_STEPConstruct_Part.def("PRPCdescription", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_Part::*)() const) &STEPConstruct_Part::PRPCdescription, "None");
cls_STEPConstruct_Part.def("SetPRPCname", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPRPCname, "None", py::arg("label"));
cls_STEPConstruct_Part.def("SetPRPCdescription", (void (STEPConstruct_Part::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_Part::SetPRPCdescription, "None", py::arg("text"));

// CLASS: STEPCONSTRUCT_STYLES
py::class_<STEPConstruct_Styles, STEPConstruct_Tool> cls_STEPConstruct_Styles(mod, "STEPConstruct_Styles", "Provides a mechanism for reading and writing shape styles (such as color) to and from the STEP file This tool maintains a list of styles, either taking them from STEP model (reading), or filling it by calls to AddStyle or directly (writing). Some methods deal with general structures of styles and presentations in STEP, but there are methods which deal with particular implementation of colors (as described in RP)");

// Constructors
cls_STEPConstruct_Styles.def(py::init<>());
cls_STEPConstruct_Styles.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));

// Methods
// cls_STEPConstruct_Styles.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_Styles::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_Styles.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_Styles::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_Styles.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_Styles::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_Styles.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_Styles::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_Styles.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_Styles::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_Styles.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_Styles::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_Styles.def("Init", (Standard_Boolean (STEPConstruct_Styles::*)(const opencascade::handle<XSControl_WorkSession> &)) &STEPConstruct_Styles::Init, "Initializes tool; returns True if succeeded", py::arg("WS"));
cls_STEPConstruct_Styles.def("NbStyles", (Standard_Integer (STEPConstruct_Styles::*)() const) &STEPConstruct_Styles::NbStyles, "Returns number of defined styles");
cls_STEPConstruct_Styles.def("Style", (opencascade::handle<StepVisual_StyledItem> (STEPConstruct_Styles::*)(const Standard_Integer) const) &STEPConstruct_Styles::Style, "Returns style with given index", py::arg("i"));
cls_STEPConstruct_Styles.def("ClearStyles", (void (STEPConstruct_Styles::*)()) &STEPConstruct_Styles::ClearStyles, "Clears all defined styles and PSA sequence");
cls_STEPConstruct_Styles.def("AddStyle", (void (STEPConstruct_Styles::*)(const opencascade::handle<StepVisual_StyledItem> &)) &STEPConstruct_Styles::AddStyle, "Adds a style to a sequence", py::arg("style"));
cls_STEPConstruct_Styles.def("AddStyle", (opencascade::handle<StepVisual_StyledItem> (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepVisual_PresentationStyleAssignment> &, const opencascade::handle<StepVisual_StyledItem> &)) &STEPConstruct_Styles::AddStyle, "Create a style linking giving PSA to the item, and add it to the sequence of stored styles. If Override is not Null, then the resulting style will be of the subtype OverridingStyledItem.", py::arg("item"), py::arg("PSA"), py::arg("Override"));
cls_STEPConstruct_Styles.def("AddStyle", (opencascade::handle<StepVisual_StyledItem> (STEPConstruct_Styles::*)(const TopoDS_Shape &, const opencascade::handle<StepVisual_PresentationStyleAssignment> &, const opencascade::handle<StepVisual_StyledItem> &)) &STEPConstruct_Styles::AddStyle, "Create a style linking giving PSA to the Shape, and add it to the sequence of stored styles. If Override is not Null, then the resulting style will be of the subtype OverridingStyledItem. The Sape is used to find corresponding STEP entity by call to STEPConstruct::FindEntity(), then previous method is called.", py::arg("Shape"), py::arg("PSA"), py::arg("Override"));
cls_STEPConstruct_Styles.def("CreateMDGPR", (Standard_Boolean (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationContext> &, opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation> &)) &STEPConstruct_Styles::CreateMDGPR, "Create MDGPR, fill it with all the styles previously defined, and add it to the model", py::arg("Context"), py::arg("MDGPR"));
cls_STEPConstruct_Styles.def("CreateNAUOSRD", (Standard_Boolean (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &)) &STEPConstruct_Styles::CreateNAUOSRD, "Create MDGPR, fill it with all the styles previously defined, and add it to the model IMPORTANT: <initPDS> must be null when use for NAUO colors <initPDS> initialised only for SHUO case.", py::arg("Context"), py::arg("CDSR"), py::arg("initPDS"));
cls_STEPConstruct_Styles.def("FindContext", (opencascade::handle<StepRepr_RepresentationContext> (STEPConstruct_Styles::*)(const TopoDS_Shape &) const) &STEPConstruct_Styles::FindContext, "Searches the STEP model for the RepresentationContext in which given shape is defined. This context (if found) can be used then in call to CreateMDGPR()", py::arg("Shape"));
cls_STEPConstruct_Styles.def("LoadStyles", (Standard_Boolean (STEPConstruct_Styles::*)()) &STEPConstruct_Styles::LoadStyles, "Searches the STEP model for the MDGPR or DM entities (which bring styles) and fills sequence of styles");
cls_STEPConstruct_Styles.def("LoadInvisStyles", (Standard_Boolean (STEPConstruct_Styles::*)(opencascade::handle<TColStd_HSequenceOfTransient> &) const) &STEPConstruct_Styles::LoadInvisStyles, "Searches the STEP model for the INISIBILITY enteties (which bring styles) and fills out sequence of styles", py::arg("InvSyles"));
cls_STEPConstruct_Styles.def("MakeColorPSA", [](STEPConstruct_Styles &self, const opencascade::handle<StepRepr_RepresentationItem> & a0, const opencascade::handle<StepVisual_Colour> & a1, const opencascade::handle<StepVisual_Colour> & a2) -> opencascade::handle<StepVisual_PresentationStyleAssignment> { return self.MakeColorPSA(a0, a1, a2); });
cls_STEPConstruct_Styles.def("MakeColorPSA", (opencascade::handle<StepVisual_PresentationStyleAssignment> (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepVisual_Colour> &, const opencascade::handle<StepVisual_Colour> &, const Standard_Boolean) const) &STEPConstruct_Styles::MakeColorPSA, "Create a PresentationStyleAssignment entity which defines two colors (for filling surfaces and curves) if isForNAUO true then returns PresentationStyleByContext", py::arg("item"), py::arg("SurfCol"), py::arg("CurveCol"), py::arg("isForNAUO"));
cls_STEPConstruct_Styles.def("GetColorPSA", (opencascade::handle<StepVisual_PresentationStyleAssignment> (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepVisual_Colour> &)) &STEPConstruct_Styles::GetColorPSA, "Returns a PresentationStyleAssignment entity which defines surface and curve colors as Col. This PSA is either created or taken from internal map where all PSAs created by this method are remembered.", py::arg("item"), py::arg("Col"));
cls_STEPConstruct_Styles.def("GetColors", [](STEPConstruct_Styles &self, const opencascade::handle<StepVisual_StyledItem> & style, opencascade::handle<StepVisual_Colour> & SurfCol, opencascade::handle<StepVisual_Colour> & BoundCol, opencascade::handle<StepVisual_Colour> & CurveCol, Standard_Boolean & IsComponent){ Standard_Boolean rv = self.GetColors(style, SurfCol, BoundCol, CurveCol, IsComponent); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, IsComponent); }, "Extract color definitions from the style entity For each type of color supported, result can be either NULL if it is not defined by that style, or last definition (if they are 1 or more)", py::arg("style"), py::arg("SurfCol"), py::arg("BoundCol"), py::arg("CurveCol"), py::arg("IsComponent"));
cls_STEPConstruct_Styles.def_static("EncodeColor_", (opencascade::handle<StepVisual_Colour> (*)(const Quantity_Color &)) &STEPConstruct_Styles::EncodeColor, "Create STEP color entity by given Quantity_Color The analysis is performed for whether the color corresponds to one of standard colors predefined in STEP. In that case, PredefinedColour entity is created instead of RGBColour", py::arg("Col"));
cls_STEPConstruct_Styles.def_static("EncodeColor_", (opencascade::handle<StepVisual_Colour> (*)(const Quantity_Color &, STEPConstruct_DataMapOfAsciiStringTransient &, STEPConstruct_DataMapOfPointTransient &)) &STEPConstruct_Styles::EncodeColor, "Create STEP color entity by given Quantity_Color The analysis is performed for whether the color corresponds to one of standard colors predefined in STEP. In that case, PredefinedColour entity is created instead of RGBColour", py::arg("Col"), py::arg("DPDCs"), py::arg("ColRGBs"));
cls_STEPConstruct_Styles.def_static("DecodeColor_", (Standard_Boolean (*)(const opencascade::handle<StepVisual_Colour> &, Quantity_Color &)) &STEPConstruct_Styles::DecodeColor, "Decodes STEP color and fills the Quantity_Color. Returns True if OK or False if color is not recognized", py::arg("Colour"), py::arg("Col"));

// CLASS: STEPCONSTRUCT_UNITCONTEXT
py::class_<STEPConstruct_UnitContext> cls_STEPConstruct_UnitContext(mod, "STEPConstruct_UnitContext", "Tool for creation (encoding) and decoding (for writing and reading accordingly) context defining units and tolerances (uncerntanties)");

// Constructors
cls_STEPConstruct_UnitContext.def(py::init<>());

// Methods
// cls_STEPConstruct_UnitContext.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_UnitContext::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_UnitContext.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_UnitContext::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_UnitContext.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_UnitContext::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_UnitContext.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_UnitContext::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_UnitContext.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_UnitContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_UnitContext.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_UnitContext::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_UnitContext.def("Init", (void (STEPConstruct_UnitContext::*)(const Standard_Real)) &STEPConstruct_UnitContext::Init, "Creates new context (units are MM and radians, uncertainty equal to Tol3d)", py::arg("Tol3d"));
cls_STEPConstruct_UnitContext.def("IsDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::IsDone, "Returns True if Init was called successfully");
cls_STEPConstruct_UnitContext.def("Value", (opencascade::handle<StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx> (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::Value, "Returns context (or Null if not done)");
cls_STEPConstruct_UnitContext.def("ComputeFactors", (Standard_Integer (STEPConstruct_UnitContext::*)(const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &)) &STEPConstruct_UnitContext::ComputeFactors, "Computes the length, plane angle and solid angle conversion factor . Returns a status, 0 if OK", py::arg("aContext"));
cls_STEPConstruct_UnitContext.def("ComputeFactors", (Standard_Integer (STEPConstruct_UnitContext::*)(const opencascade::handle<StepBasic_NamedUnit> &)) &STEPConstruct_UnitContext::ComputeFactors, "None", py::arg("aUnit"));
cls_STEPConstruct_UnitContext.def("ComputeTolerance", (Standard_Integer (STEPConstruct_UnitContext::*)(const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &)) &STEPConstruct_UnitContext::ComputeTolerance, "Computes the uncertainty value (for length)", py::arg("aContext"));
cls_STEPConstruct_UnitContext.def("LengthFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::LengthFactor, "Returns the lengthFactor");
cls_STEPConstruct_UnitContext.def("PlaneAngleFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::PlaneAngleFactor, "Returns the planeAngleFactor");
cls_STEPConstruct_UnitContext.def("SolidAngleFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::SolidAngleFactor, "Returns the solidAngleFactor");
cls_STEPConstruct_UnitContext.def("Uncertainty", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::Uncertainty, "Returns the Uncertainty value (for length) It has been converted with LengthFactor");
cls_STEPConstruct_UnitContext.def("AreaFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::AreaFactor, "Returns the areaFactor");
cls_STEPConstruct_UnitContext.def("VolumeFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::VolumeFactor, "Returns the volumeFactor");
cls_STEPConstruct_UnitContext.def("HasUncertainty", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::HasUncertainty, "Tells if a Uncertainty (for length) is recorded");
cls_STEPConstruct_UnitContext.def("LengthDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::LengthDone, "Returns true if ComputeFactors has calculated a LengthFactor");
cls_STEPConstruct_UnitContext.def("PlaneAngleDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::PlaneAngleDone, "Returns true if ComputeFactors has calculated a PlaneAngleFactor");
cls_STEPConstruct_UnitContext.def("SolidAngleDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::SolidAngleDone, "Returns true if ComputeFactors has calculated a SolidAngleFactor");
cls_STEPConstruct_UnitContext.def("AreaDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::AreaDone, "Returns true if areaFactor is computed");
cls_STEPConstruct_UnitContext.def("VolumeDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::VolumeDone, "Returns true if volumeFactor is computed");
cls_STEPConstruct_UnitContext.def("StatusMessage", (Standard_CString (STEPConstruct_UnitContext::*)(const Standard_Integer) const) &STEPConstruct_UnitContext::StatusMessage, "Returns a message for a given status (0 - empty) This message can then be added as warning for transfer", py::arg("status"));
cls_STEPConstruct_UnitContext.def_static("ConvertSiPrefix_", (Standard_Real (*)(const StepBasic_SiPrefix)) &STEPConstruct_UnitContext::ConvertSiPrefix, "Convert SI prefix defined by enumertaion to corresponding real factor (e.g. 1e6 for mega)", py::arg("aPrefix"));

// CLASS: STEPCONSTRUCT_VALIDATIONPROPS
py::class_<STEPConstruct_ValidationProps, STEPConstruct_Tool> cls_STEPConstruct_ValidationProps(mod, "STEPConstruct_ValidationProps", "This class provides tools for access (write and read) the validation properties on shapes in the STEP file. These are surface area, solid volume and centroid.");

// Constructors
cls_STEPConstruct_ValidationProps.def(py::init<>());
cls_STEPConstruct_ValidationProps.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));

// Methods
// cls_STEPConstruct_ValidationProps.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_ValidationProps::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_ValidationProps.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_ValidationProps::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_ValidationProps.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_ValidationProps::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_ValidationProps.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_ValidationProps::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_ValidationProps.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_ValidationProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_ValidationProps.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_ValidationProps::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_ValidationProps.def("Init", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const opencascade::handle<XSControl_WorkSession> &)) &STEPConstruct_ValidationProps::Init, "Load worksession; returns True if succeeded", py::arg("WS"));
cls_STEPConstruct_ValidationProps.def("AddProp", [](STEPConstruct_ValidationProps &self, const TopoDS_Shape & a0, const opencascade::handle<StepRepr_RepresentationItem> & a1, const Standard_CString a2) -> Standard_Boolean { return self.AddProp(a0, a1, a2); });
cls_STEPConstruct_ValidationProps.def("AddProp", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, const opencascade::handle<StepRepr_RepresentationItem> &, const Standard_CString, const Standard_Boolean)) &STEPConstruct_ValidationProps::AddProp, "General method for adding (writing) a validation property for shape which should be already mapped on writing itself. It uses FindTarget() to find target STEP entity resulting from given shape, and associated context Returns True if success, False in case of fail", py::arg("Shape"), py::arg("Prop"), py::arg("Descr"), py::arg("instance"));
cls_STEPConstruct_ValidationProps.def("AddProp", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const StepRepr_CharacterizedDefinition &, const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepRepr_RepresentationItem> &, const Standard_CString)) &STEPConstruct_ValidationProps::AddProp, "General method for adding (writing) a validation property for shape which should be already mapped on writing itself. It takes target and Context entities which correspond to shape Returns True if success, False in case of fail", py::arg("target"), py::arg("Context"), py::arg("Prop"), py::arg("Descr"));
cls_STEPConstruct_ValidationProps.def("AddArea", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, const Standard_Real)) &STEPConstruct_ValidationProps::AddArea, "Adds surface area property for given shape (already mapped). Returns True if success, False in case of fail", py::arg("Shape"), py::arg("Area"));
cls_STEPConstruct_ValidationProps.def("AddVolume", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, const Standard_Real)) &STEPConstruct_ValidationProps::AddVolume, "Adds volume property for given shape (already mapped). Returns True if success, False in case of fail", py::arg("Shape"), py::arg("Vol"));
cls_STEPConstruct_ValidationProps.def("AddCentroid", [](STEPConstruct_ValidationProps &self, const TopoDS_Shape & a0, const gp_Pnt & a1) -> Standard_Boolean { return self.AddCentroid(a0, a1); });
cls_STEPConstruct_ValidationProps.def("AddCentroid", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, const gp_Pnt &, const Standard_Boolean)) &STEPConstruct_ValidationProps::AddCentroid, "Adds centroid property for given shape (already mapped). Returns True if success, False in case of fail If instance is True, then centroid is assigned to an instance of component in assembly", py::arg("Shape"), py::arg("Pnt"), py::arg("instance"));
cls_STEPConstruct_ValidationProps.def("FindTarget", [](STEPConstruct_ValidationProps &self, const TopoDS_Shape & a0, StepRepr_CharacterizedDefinition & a1, opencascade::handle<StepRepr_RepresentationContext> & a2) -> Standard_Boolean { return self.FindTarget(a0, a1, a2); });
cls_STEPConstruct_ValidationProps.def("FindTarget", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &, StepRepr_CharacterizedDefinition &, opencascade::handle<StepRepr_RepresentationContext> &, const Standard_Boolean)) &STEPConstruct_ValidationProps::FindTarget, "Finds target STEP entity to which validation props should be assigned, and corresponding context, starting from shape Returns True if success, False in case of fail", py::arg("S"), py::arg("target"), py::arg("Context"), py::arg("instance"));
cls_STEPConstruct_ValidationProps.def("LoadProps", (Standard_Boolean (STEPConstruct_ValidationProps::*)(TColStd_SequenceOfTransient &) const) &STEPConstruct_ValidationProps::LoadProps, "Searches for entities of the type PropertyDefinitionRepresentation in the model and fills the sequence by them", py::arg("seq"));
cls_STEPConstruct_ValidationProps.def("GetPropNAUO", (opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepRepr_PropertyDefinition> &) const) &STEPConstruct_ValidationProps::GetPropNAUO, "Returns CDSR associated with given PpD or NULL if not found (when, try GetPropSDR)", py::arg("PD"));
cls_STEPConstruct_ValidationProps.def("GetPropPD", (opencascade::handle<StepBasic_ProductDefinition> (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepRepr_PropertyDefinition> &) const) &STEPConstruct_ValidationProps::GetPropPD, "Returns SDR associated with given PpD or NULL if not found (when, try GetPropCDSR)", py::arg("PD"));
cls_STEPConstruct_ValidationProps.def("GetPropShape", (TopoDS_Shape (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepBasic_ProductDefinition> &) const) &STEPConstruct_ValidationProps::GetPropShape, "Returns Shape associated with given SDR or Null Shape if not found", py::arg("ProdDef"));
cls_STEPConstruct_ValidationProps.def("GetPropShape", (TopoDS_Shape (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepRepr_PropertyDefinition> &) const) &STEPConstruct_ValidationProps::GetPropShape, "Returns Shape associated with given PpD or Null Shape if not found", py::arg("PD"));
cls_STEPConstruct_ValidationProps.def("GetPropReal", [](STEPConstruct_ValidationProps &self, const opencascade::handle<StepRepr_RepresentationItem> & item, Standard_Real & Val, Standard_Boolean & isArea){ Standard_Boolean rv = self.GetPropReal(item, Val, isArea); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &>(rv, Val, isArea); }, "Returns value of Real-Valued property (Area or Volume) If Property is neither Area nor Volume, returns False Else returns True and isArea indicates whether property is area or volume", py::arg("item"), py::arg("Val"), py::arg("isArea"));
cls_STEPConstruct_ValidationProps.def("GetPropPnt", (Standard_Boolean (STEPConstruct_ValidationProps::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &, gp_Pnt &) const) &STEPConstruct_ValidationProps::GetPropPnt, "Returns value of Centriod property (or False if it is not)", py::arg("item"), py::arg("Context"), py::arg("Pnt"));
cls_STEPConstruct_ValidationProps.def("SetAssemblyShape", (void (STEPConstruct_ValidationProps::*)(const TopoDS_Shape &)) &STEPConstruct_ValidationProps::SetAssemblyShape, "Sets current assembly shape SDR (for FindCDSR calls)", py::arg("shape"));


}
