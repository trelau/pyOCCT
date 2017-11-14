#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <StepBasic_ApprovalAssignment.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_Approval.hxx>
#include <StepAP203_HArray1OfApprovedItem.hxx>
#include <Standard_Type.hxx>
#include <StepAP203_CcDesignApproval.hxx>
#include <StepBasic_CertificationAssignment.hxx>
#include <StepBasic_Certification.hxx>
#include <StepAP203_HArray1OfCertifiedItem.hxx>
#include <StepAP203_CcDesignCertification.hxx>
#include <StepBasic_ContractAssignment.hxx>
#include <StepBasic_Contract.hxx>
#include <StepAP203_HArray1OfContractedItem.hxx>
#include <StepAP203_CcDesignContract.hxx>
#include <StepBasic_DateAndTimeAssignment.hxx>
#include <StepBasic_DateAndTime.hxx>
#include <StepBasic_DateTimeRole.hxx>
#include <StepAP203_HArray1OfDateTimeItem.hxx>
#include <StepAP203_CcDesignDateAndTimeAssignment.hxx>
#include <StepBasic_PersonAndOrganizationAssignment.hxx>
#include <StepBasic_PersonAndOrganization.hxx>
#include <StepBasic_PersonAndOrganizationRole.hxx>
#include <StepAP203_HArray1OfPersonOrganizationItem.hxx>
#include <StepAP203_CcDesignPersonAndOrganizationAssignment.hxx>
#include <StepBasic_SecurityClassificationAssignment.hxx>
#include <StepBasic_SecurityClassification.hxx>
#include <StepAP203_HArray1OfClassifiedItem.hxx>
#include <StepAP203_CcDesignSecurityClassification.hxx>
#include <StepBasic_DocumentReference.hxx>
#include <StepBasic_Document.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepAP203_HArray1OfSpecifiedItem.hxx>
#include <StepAP203_CcDesignSpecificationReference.hxx>
#include <StepBasic_ActionAssignment.hxx>
#include <StepBasic_Action.hxx>
#include <StepAP203_HArray1OfWorkItem.hxx>
#include <StepAP203_Change.hxx>
#include <StepBasic_ActionRequestAssignment.hxx>
#include <StepBasic_VersionedActionRequest.hxx>
#include <StepAP203_HArray1OfChangeRequestItem.hxx>
#include <StepAP203_ChangeRequest.hxx>
#include <StepAP203_HArray1OfStartRequestItem.hxx>
#include <StepAP203_StartRequest.hxx>
#include <StepAP203_StartWork.hxx>
#include <StepData_SelectType.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepRepr_ConfigurationEffectivity.hxx>
#include <StepRepr_ConfigurationItem.hxx>
#include <StepAP203_ApprovedItem.hxx>
#include <NCollection_Array1.hxx>
#include <StepAP203_Array1OfApprovedItem.hxx>
#include <StepRepr_SuppliedPartRelationship.hxx>
#include <StepAP203_CertifiedItem.hxx>
#include <StepAP203_Array1OfCertifiedItem.hxx>
#include <StepAP203_ChangeRequestItem.hxx>
#include <StepAP203_Array1OfChangeRequestItem.hxx>
#include <StepRepr_AssemblyComponentUsage.hxx>
#include <StepAP203_ClassifiedItem.hxx>
#include <StepAP203_Array1OfClassifiedItem.hxx>
#include <StepAP203_ContractedItem.hxx>
#include <StepAP203_Array1OfContractedItem.hxx>
#include <StepBasic_ApprovalPersonOrganization.hxx>
#include <StepAP203_DateTimeItem.hxx>
#include <StepAP203_Array1OfDateTimeItem.hxx>
#include <StepBasic_Product.hxx>
#include <StepAP203_PersonOrganizationItem.hxx>
#include <StepAP203_Array1OfPersonOrganizationItem.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepAP203_SpecifiedItem.hxx>
#include <StepAP203_Array1OfSpecifiedItem.hxx>
#include <StepAP203_StartRequestItem.hxx>
#include <StepAP203_Array1OfStartRequestItem.hxx>
#include <StepAP203_WorkItem.hxx>
#include <StepAP203_Array1OfWorkItem.hxx>
#include <NCollection_BaseAllocator.hxx>

PYBIND11_MODULE(StepAP203, mod) {

	// IMPORT
	py::module::import("OCCT.StepBasic");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.StepRepr");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_CcDesignApproval.hxx
	py::class_<StepAP203_CcDesignApproval, opencascade::handle<StepAP203_CcDesignApproval>, StepBasic_ApprovalAssignment> cls_StepAP203_CcDesignApproval(mod, "StepAP203_CcDesignApproval", "Representation of STEP entity CcDesignApproval");
	cls_StepAP203_CcDesignApproval.def(py::init<>());
	cls_StepAP203_CcDesignApproval.def("Init", (void (StepAP203_CcDesignApproval::*)(const opencascade::handle<StepBasic_Approval> &, const opencascade::handle<StepAP203_HArray1OfApprovedItem> &)) &StepAP203_CcDesignApproval::Init, "Initialize all fields (own and inherited)", py::arg("aApprovalAssignment_AssignedApproval"), py::arg("aItems"));
	cls_StepAP203_CcDesignApproval.def("Items", (opencascade::handle<StepAP203_HArray1OfApprovedItem> (StepAP203_CcDesignApproval::*)() const ) &StepAP203_CcDesignApproval::Items, "Returns field Items");
	cls_StepAP203_CcDesignApproval.def("SetItems", (void (StepAP203_CcDesignApproval::*)(const opencascade::handle<StepAP203_HArray1OfApprovedItem> &)) &StepAP203_CcDesignApproval::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_CcDesignApproval.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignApproval::get_type_name, "None");
	cls_StepAP203_CcDesignApproval.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignApproval::get_type_descriptor, "None");
	cls_StepAP203_CcDesignApproval.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignApproval::*)() const ) &StepAP203_CcDesignApproval::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_CcDesignCertification.hxx
	py::class_<StepAP203_CcDesignCertification, opencascade::handle<StepAP203_CcDesignCertification>, StepBasic_CertificationAssignment> cls_StepAP203_CcDesignCertification(mod, "StepAP203_CcDesignCertification", "Representation of STEP entity CcDesignCertification");
	cls_StepAP203_CcDesignCertification.def(py::init<>());
	cls_StepAP203_CcDesignCertification.def("Init", (void (StepAP203_CcDesignCertification::*)(const opencascade::handle<StepBasic_Certification> &, const opencascade::handle<StepAP203_HArray1OfCertifiedItem> &)) &StepAP203_CcDesignCertification::Init, "Initialize all fields (own and inherited)", py::arg("aCertificationAssignment_AssignedCertification"), py::arg("aItems"));
	cls_StepAP203_CcDesignCertification.def("Items", (opencascade::handle<StepAP203_HArray1OfCertifiedItem> (StepAP203_CcDesignCertification::*)() const ) &StepAP203_CcDesignCertification::Items, "Returns field Items");
	cls_StepAP203_CcDesignCertification.def("SetItems", (void (StepAP203_CcDesignCertification::*)(const opencascade::handle<StepAP203_HArray1OfCertifiedItem> &)) &StepAP203_CcDesignCertification::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_CcDesignCertification.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignCertification::get_type_name, "None");
	cls_StepAP203_CcDesignCertification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignCertification::get_type_descriptor, "None");
	cls_StepAP203_CcDesignCertification.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignCertification::*)() const ) &StepAP203_CcDesignCertification::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_CcDesignContract.hxx
	py::class_<StepAP203_CcDesignContract, opencascade::handle<StepAP203_CcDesignContract>, StepBasic_ContractAssignment> cls_StepAP203_CcDesignContract(mod, "StepAP203_CcDesignContract", "Representation of STEP entity CcDesignContract");
	cls_StepAP203_CcDesignContract.def(py::init<>());
	cls_StepAP203_CcDesignContract.def("Init", (void (StepAP203_CcDesignContract::*)(const opencascade::handle<StepBasic_Contract> &, const opencascade::handle<StepAP203_HArray1OfContractedItem> &)) &StepAP203_CcDesignContract::Init, "Initialize all fields (own and inherited)", py::arg("aContractAssignment_AssignedContract"), py::arg("aItems"));
	cls_StepAP203_CcDesignContract.def("Items", (opencascade::handle<StepAP203_HArray1OfContractedItem> (StepAP203_CcDesignContract::*)() const ) &StepAP203_CcDesignContract::Items, "Returns field Items");
	cls_StepAP203_CcDesignContract.def("SetItems", (void (StepAP203_CcDesignContract::*)(const opencascade::handle<StepAP203_HArray1OfContractedItem> &)) &StepAP203_CcDesignContract::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_CcDesignContract.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignContract::get_type_name, "None");
	cls_StepAP203_CcDesignContract.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignContract::get_type_descriptor, "None");
	cls_StepAP203_CcDesignContract.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignContract::*)() const ) &StepAP203_CcDesignContract::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_CcDesignDateAndTimeAssignment.hxx
	py::class_<StepAP203_CcDesignDateAndTimeAssignment, opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment>, StepBasic_DateAndTimeAssignment> cls_StepAP203_CcDesignDateAndTimeAssignment(mod, "StepAP203_CcDesignDateAndTimeAssignment", "Representation of STEP entity CcDesignDateAndTimeAssignment");
	cls_StepAP203_CcDesignDateAndTimeAssignment.def(py::init<>());
	cls_StepAP203_CcDesignDateAndTimeAssignment.def("Init", (void (StepAP203_CcDesignDateAndTimeAssignment::*)(const opencascade::handle<StepBasic_DateAndTime> &, const opencascade::handle<StepBasic_DateTimeRole> &, const opencascade::handle<StepAP203_HArray1OfDateTimeItem> &)) &StepAP203_CcDesignDateAndTimeAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aDateAndTimeAssignment_AssignedDateAndTime"), py::arg("aDateAndTimeAssignment_Role"), py::arg("aItems"));
	cls_StepAP203_CcDesignDateAndTimeAssignment.def("Items", (opencascade::handle<StepAP203_HArray1OfDateTimeItem> (StepAP203_CcDesignDateAndTimeAssignment::*)() const ) &StepAP203_CcDesignDateAndTimeAssignment::Items, "Returns field Items");
	cls_StepAP203_CcDesignDateAndTimeAssignment.def("SetItems", (void (StepAP203_CcDesignDateAndTimeAssignment::*)(const opencascade::handle<StepAP203_HArray1OfDateTimeItem> &)) &StepAP203_CcDesignDateAndTimeAssignment::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_CcDesignDateAndTimeAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignDateAndTimeAssignment::get_type_name, "None");
	cls_StepAP203_CcDesignDateAndTimeAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignDateAndTimeAssignment::get_type_descriptor, "None");
	cls_StepAP203_CcDesignDateAndTimeAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignDateAndTimeAssignment::*)() const ) &StepAP203_CcDesignDateAndTimeAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_CcDesignPersonAndOrganizationAssignment.hxx
	py::class_<StepAP203_CcDesignPersonAndOrganizationAssignment, opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment>, StepBasic_PersonAndOrganizationAssignment> cls_StepAP203_CcDesignPersonAndOrganizationAssignment(mod, "StepAP203_CcDesignPersonAndOrganizationAssignment", "Representation of STEP entity CcDesignPersonAndOrganizationAssignment");
	cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def(py::init<>());
	cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def("Init", (void (StepAP203_CcDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepBasic_PersonAndOrganization> &, const opencascade::handle<StepBasic_PersonAndOrganizationRole> &, const opencascade::handle<StepAP203_HArray1OfPersonOrganizationItem> &)) &StepAP203_CcDesignPersonAndOrganizationAssignment::Init, "Initialize all fields (own and inherited)", py::arg("aPersonAndOrganizationAssignment_AssignedPersonAndOrganization"), py::arg("aPersonAndOrganizationAssignment_Role"), py::arg("aItems"));
	cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def("Items", (opencascade::handle<StepAP203_HArray1OfPersonOrganizationItem> (StepAP203_CcDesignPersonAndOrganizationAssignment::*)() const ) &StepAP203_CcDesignPersonAndOrganizationAssignment::Items, "Returns field Items");
	cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def("SetItems", (void (StepAP203_CcDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP203_HArray1OfPersonOrganizationItem> &)) &StepAP203_CcDesignPersonAndOrganizationAssignment::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignPersonAndOrganizationAssignment::get_type_name, "None");
	cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignPersonAndOrganizationAssignment::get_type_descriptor, "None");
	cls_StepAP203_CcDesignPersonAndOrganizationAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignPersonAndOrganizationAssignment::*)() const ) &StepAP203_CcDesignPersonAndOrganizationAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_CcDesignSecurityClassification.hxx
	py::class_<StepAP203_CcDesignSecurityClassification, opencascade::handle<StepAP203_CcDesignSecurityClassification>, StepBasic_SecurityClassificationAssignment> cls_StepAP203_CcDesignSecurityClassification(mod, "StepAP203_CcDesignSecurityClassification", "Representation of STEP entity CcDesignSecurityClassification");
	cls_StepAP203_CcDesignSecurityClassification.def(py::init<>());
	cls_StepAP203_CcDesignSecurityClassification.def("Init", (void (StepAP203_CcDesignSecurityClassification::*)(const opencascade::handle<StepBasic_SecurityClassification> &, const opencascade::handle<StepAP203_HArray1OfClassifiedItem> &)) &StepAP203_CcDesignSecurityClassification::Init, "Initialize all fields (own and inherited)", py::arg("aSecurityClassificationAssignment_AssignedSecurityClassification"), py::arg("aItems"));
	cls_StepAP203_CcDesignSecurityClassification.def("Items", (opencascade::handle<StepAP203_HArray1OfClassifiedItem> (StepAP203_CcDesignSecurityClassification::*)() const ) &StepAP203_CcDesignSecurityClassification::Items, "Returns field Items");
	cls_StepAP203_CcDesignSecurityClassification.def("SetItems", (void (StepAP203_CcDesignSecurityClassification::*)(const opencascade::handle<StepAP203_HArray1OfClassifiedItem> &)) &StepAP203_CcDesignSecurityClassification::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_CcDesignSecurityClassification.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignSecurityClassification::get_type_name, "None");
	cls_StepAP203_CcDesignSecurityClassification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignSecurityClassification::get_type_descriptor, "None");
	cls_StepAP203_CcDesignSecurityClassification.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignSecurityClassification::*)() const ) &StepAP203_CcDesignSecurityClassification::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_CcDesignSpecificationReference.hxx
	py::class_<StepAP203_CcDesignSpecificationReference, opencascade::handle<StepAP203_CcDesignSpecificationReference>, StepBasic_DocumentReference> cls_StepAP203_CcDesignSpecificationReference(mod, "StepAP203_CcDesignSpecificationReference", "Representation of STEP entity CcDesignSpecificationReference");
	cls_StepAP203_CcDesignSpecificationReference.def(py::init<>());
	cls_StepAP203_CcDesignSpecificationReference.def("Init", (void (StepAP203_CcDesignSpecificationReference::*)(const opencascade::handle<StepBasic_Document> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepAP203_HArray1OfSpecifiedItem> &)) &StepAP203_CcDesignSpecificationReference::Init, "Initialize all fields (own and inherited)", py::arg("aDocumentReference_AssignedDocument"), py::arg("aDocumentReference_Source"), py::arg("aItems"));
	cls_StepAP203_CcDesignSpecificationReference.def("Items", (opencascade::handle<StepAP203_HArray1OfSpecifiedItem> (StepAP203_CcDesignSpecificationReference::*)() const ) &StepAP203_CcDesignSpecificationReference::Items, "Returns field Items");
	cls_StepAP203_CcDesignSpecificationReference.def("SetItems", (void (StepAP203_CcDesignSpecificationReference::*)(const opencascade::handle<StepAP203_HArray1OfSpecifiedItem> &)) &StepAP203_CcDesignSpecificationReference::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_CcDesignSpecificationReference.def_static("get_type_name_", (const char * (*)()) &StepAP203_CcDesignSpecificationReference::get_type_name, "None");
	cls_StepAP203_CcDesignSpecificationReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_CcDesignSpecificationReference::get_type_descriptor, "None");
	cls_StepAP203_CcDesignSpecificationReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_CcDesignSpecificationReference::*)() const ) &StepAP203_CcDesignSpecificationReference::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_Change.hxx
	py::class_<StepAP203_Change, opencascade::handle<StepAP203_Change>, StepBasic_ActionAssignment> cls_StepAP203_Change(mod, "StepAP203_Change", "Representation of STEP entity Change");
	cls_StepAP203_Change.def(py::init<>());
	cls_StepAP203_Change.def("Init", (void (StepAP203_Change::*)(const opencascade::handle<StepBasic_Action> &, const opencascade::handle<StepAP203_HArray1OfWorkItem> &)) &StepAP203_Change::Init, "Initialize all fields (own and inherited)", py::arg("aActionAssignment_AssignedAction"), py::arg("aItems"));
	cls_StepAP203_Change.def("Items", (opencascade::handle<StepAP203_HArray1OfWorkItem> (StepAP203_Change::*)() const ) &StepAP203_Change::Items, "Returns field Items");
	cls_StepAP203_Change.def("SetItems", (void (StepAP203_Change::*)(const opencascade::handle<StepAP203_HArray1OfWorkItem> &)) &StepAP203_Change::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_Change.def_static("get_type_name_", (const char * (*)()) &StepAP203_Change::get_type_name, "None");
	cls_StepAP203_Change.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_Change::get_type_descriptor, "None");
	cls_StepAP203_Change.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_Change::*)() const ) &StepAP203_Change::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_ChangeRequest.hxx
	py::class_<StepAP203_ChangeRequest, opencascade::handle<StepAP203_ChangeRequest>, StepBasic_ActionRequestAssignment> cls_StepAP203_ChangeRequest(mod, "StepAP203_ChangeRequest", "Representation of STEP entity ChangeRequest");
	cls_StepAP203_ChangeRequest.def(py::init<>());
	cls_StepAP203_ChangeRequest.def("Init", (void (StepAP203_ChangeRequest::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &, const opencascade::handle<StepAP203_HArray1OfChangeRequestItem> &)) &StepAP203_ChangeRequest::Init, "Initialize all fields (own and inherited)", py::arg("aActionRequestAssignment_AssignedActionRequest"), py::arg("aItems"));
	cls_StepAP203_ChangeRequest.def("Items", (opencascade::handle<StepAP203_HArray1OfChangeRequestItem> (StepAP203_ChangeRequest::*)() const ) &StepAP203_ChangeRequest::Items, "Returns field Items");
	cls_StepAP203_ChangeRequest.def("SetItems", (void (StepAP203_ChangeRequest::*)(const opencascade::handle<StepAP203_HArray1OfChangeRequestItem> &)) &StepAP203_ChangeRequest::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_ChangeRequest.def_static("get_type_name_", (const char * (*)()) &StepAP203_ChangeRequest::get_type_name, "None");
	cls_StepAP203_ChangeRequest.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_ChangeRequest::get_type_descriptor, "None");
	cls_StepAP203_ChangeRequest.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_ChangeRequest::*)() const ) &StepAP203_ChangeRequest::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_StartRequest.hxx
	py::class_<StepAP203_StartRequest, opencascade::handle<StepAP203_StartRequest>, StepBasic_ActionRequestAssignment> cls_StepAP203_StartRequest(mod, "StepAP203_StartRequest", "Representation of STEP entity StartRequest");
	cls_StepAP203_StartRequest.def(py::init<>());
	cls_StepAP203_StartRequest.def("Init", (void (StepAP203_StartRequest::*)(const opencascade::handle<StepBasic_VersionedActionRequest> &, const opencascade::handle<StepAP203_HArray1OfStartRequestItem> &)) &StepAP203_StartRequest::Init, "Initialize all fields (own and inherited)", py::arg("aActionRequestAssignment_AssignedActionRequest"), py::arg("aItems"));
	cls_StepAP203_StartRequest.def("Items", (opencascade::handle<StepAP203_HArray1OfStartRequestItem> (StepAP203_StartRequest::*)() const ) &StepAP203_StartRequest::Items, "Returns field Items");
	cls_StepAP203_StartRequest.def("SetItems", (void (StepAP203_StartRequest::*)(const opencascade::handle<StepAP203_HArray1OfStartRequestItem> &)) &StepAP203_StartRequest::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_StartRequest.def_static("get_type_name_", (const char * (*)()) &StepAP203_StartRequest::get_type_name, "None");
	cls_StepAP203_StartRequest.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_StartRequest::get_type_descriptor, "None");
	cls_StepAP203_StartRequest.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_StartRequest::*)() const ) &StepAP203_StartRequest::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_StartWork.hxx
	py::class_<StepAP203_StartWork, opencascade::handle<StepAP203_StartWork>, StepBasic_ActionAssignment> cls_StepAP203_StartWork(mod, "StepAP203_StartWork", "Representation of STEP entity StartWork");
	cls_StepAP203_StartWork.def(py::init<>());
	cls_StepAP203_StartWork.def("Init", (void (StepAP203_StartWork::*)(const opencascade::handle<StepBasic_Action> &, const opencascade::handle<StepAP203_HArray1OfWorkItem> &)) &StepAP203_StartWork::Init, "Initialize all fields (own and inherited)", py::arg("aActionAssignment_AssignedAction"), py::arg("aItems"));
	cls_StepAP203_StartWork.def("Items", (opencascade::handle<StepAP203_HArray1OfWorkItem> (StepAP203_StartWork::*)() const ) &StepAP203_StartWork::Items, "Returns field Items");
	cls_StepAP203_StartWork.def("SetItems", (void (StepAP203_StartWork::*)(const opencascade::handle<StepAP203_HArray1OfWorkItem> &)) &StepAP203_StartWork::SetItems, "Set field Items", py::arg("Items"));
	cls_StepAP203_StartWork.def_static("get_type_name_", (const char * (*)()) &StepAP203_StartWork::get_type_name, "None");
	cls_StepAP203_StartWork.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_StartWork::get_type_descriptor, "None");
	cls_StepAP203_StartWork.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_StartWork::*)() const ) &StepAP203_StartWork::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_ApprovedItem.hxx
	py::class_<StepAP203_ApprovedItem, std::unique_ptr<StepAP203_ApprovedItem, Deleter<StepAP203_ApprovedItem>>, StepData_SelectType> cls_StepAP203_ApprovedItem(mod, "StepAP203_ApprovedItem", "Representation of STEP SELECT type ApprovedItem");
	cls_StepAP203_ApprovedItem.def(py::init<>());
	cls_StepAP203_ApprovedItem.def("CaseNum", (Standard_Integer (StepAP203_ApprovedItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_ApprovedItem::CaseNum, "Recognizes a kind of ApprovedItem select type 1 -> ProductDefinitionFormation from StepBasic 2 -> ProductDefinition from StepBasic 3 -> ConfigurationEffectivity from StepRepr 4 -> ConfigurationItem from StepRepr 5 -> SecurityClassification from StepBasic 6 -> ChangeRequest from StepAP203 7 -> Change from StepAP203 8 -> StartRequest from StepAP203 9 -> StartWork from StepAP203 10 -> Certification from StepBasic 11 -> Contract from StepBasic 0 else", py::arg("ent"));
	cls_StepAP203_ApprovedItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("ConfigurationEffectivity", (opencascade::handle<StepRepr_ConfigurationEffectivity> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::ConfigurationEffectivity, "Returns Value as ConfigurationEffectivity (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("ConfigurationItem", (opencascade::handle<StepRepr_ConfigurationItem> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::ConfigurationItem, "Returns Value as ConfigurationItem (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("SecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::SecurityClassification, "Returns Value as SecurityClassification (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("ChangeRequest", (opencascade::handle<StepAP203_ChangeRequest> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::ChangeRequest, "Returns Value as ChangeRequest (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("Change", (opencascade::handle<StepAP203_Change> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::Change, "Returns Value as Change (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("StartRequest", (opencascade::handle<StepAP203_StartRequest> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::StartRequest, "Returns Value as StartRequest (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("StartWork", (opencascade::handle<StepAP203_StartWork> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::StartWork, "Returns Value as StartWork (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("Certification", (opencascade::handle<StepBasic_Certification> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::Certification, "Returns Value as Certification (or Null if another type)");
	cls_StepAP203_ApprovedItem.def("Contract", (opencascade::handle<StepBasic_Contract> (StepAP203_ApprovedItem::*)() const ) &StepAP203_ApprovedItem::Contract, "Returns Value as Contract (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_CertifiedItem.hxx
	py::class_<StepAP203_CertifiedItem, std::unique_ptr<StepAP203_CertifiedItem, Deleter<StepAP203_CertifiedItem>>, StepData_SelectType> cls_StepAP203_CertifiedItem(mod, "StepAP203_CertifiedItem", "Representation of STEP SELECT type CertifiedItem");
	cls_StepAP203_CertifiedItem.def(py::init<>());
	cls_StepAP203_CertifiedItem.def("CaseNum", (Standard_Integer (StepAP203_CertifiedItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_CertifiedItem::CaseNum, "Recognizes a kind of CertifiedItem select type 1 -> SuppliedPartRelationship from StepRepr 0 else", py::arg("ent"));
	cls_StepAP203_CertifiedItem.def("SuppliedPartRelationship", (opencascade::handle<StepRepr_SuppliedPartRelationship> (StepAP203_CertifiedItem::*)() const ) &StepAP203_CertifiedItem::SuppliedPartRelationship, "Returns Value as SuppliedPartRelationship (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_ChangeRequestItem.hxx
	py::class_<StepAP203_ChangeRequestItem, std::unique_ptr<StepAP203_ChangeRequestItem, Deleter<StepAP203_ChangeRequestItem>>, StepData_SelectType> cls_StepAP203_ChangeRequestItem(mod, "StepAP203_ChangeRequestItem", "Representation of STEP SELECT type ChangeRequestItem");
	cls_StepAP203_ChangeRequestItem.def(py::init<>());
	cls_StepAP203_ChangeRequestItem.def("CaseNum", (Standard_Integer (StepAP203_ChangeRequestItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_ChangeRequestItem::CaseNum, "Recognizes a kind of ChangeRequestItem select type 1 -> ProductDefinitionFormation from StepBasic 0 else", py::arg("ent"));
	cls_StepAP203_ChangeRequestItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_ChangeRequestItem::*)() const ) &StepAP203_ChangeRequestItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_ClassifiedItem.hxx
	py::class_<StepAP203_ClassifiedItem, std::unique_ptr<StepAP203_ClassifiedItem, Deleter<StepAP203_ClassifiedItem>>, StepData_SelectType> cls_StepAP203_ClassifiedItem(mod, "StepAP203_ClassifiedItem", "Representation of STEP SELECT type ClassifiedItem");
	cls_StepAP203_ClassifiedItem.def(py::init<>());
	cls_StepAP203_ClassifiedItem.def("CaseNum", (Standard_Integer (StepAP203_ClassifiedItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_ClassifiedItem::CaseNum, "Recognizes a kind of ClassifiedItem select type 1 -> ProductDefinitionFormation from StepBasic 2 -> AssemblyComponentUsage from StepRepr 0 else", py::arg("ent"));
	cls_StepAP203_ClassifiedItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_ClassifiedItem::*)() const ) &StepAP203_ClassifiedItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");
	cls_StepAP203_ClassifiedItem.def("AssemblyComponentUsage", (opencascade::handle<StepRepr_AssemblyComponentUsage> (StepAP203_ClassifiedItem::*)() const ) &StepAP203_ClassifiedItem::AssemblyComponentUsage, "Returns Value as AssemblyComponentUsage (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_ContractedItem.hxx
	py::class_<StepAP203_ContractedItem, std::unique_ptr<StepAP203_ContractedItem, Deleter<StepAP203_ContractedItem>>, StepData_SelectType> cls_StepAP203_ContractedItem(mod, "StepAP203_ContractedItem", "Representation of STEP SELECT type ContractedItem");
	cls_StepAP203_ContractedItem.def(py::init<>());
	cls_StepAP203_ContractedItem.def("CaseNum", (Standard_Integer (StepAP203_ContractedItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_ContractedItem::CaseNum, "Recognizes a kind of ContractedItem select type 1 -> ProductDefinitionFormation from StepBasic 0 else", py::arg("ent"));
	cls_StepAP203_ContractedItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_ContractedItem::*)() const ) &StepAP203_ContractedItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_DateTimeItem.hxx
	py::class_<StepAP203_DateTimeItem, std::unique_ptr<StepAP203_DateTimeItem, Deleter<StepAP203_DateTimeItem>>, StepData_SelectType> cls_StepAP203_DateTimeItem(mod, "StepAP203_DateTimeItem", "Representation of STEP SELECT type DateTimeItem");
	cls_StepAP203_DateTimeItem.def(py::init<>());
	cls_StepAP203_DateTimeItem.def("CaseNum", (Standard_Integer (StepAP203_DateTimeItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_DateTimeItem::CaseNum, "Recognizes a kind of DateTimeItem select type 1 -> ProductDefinition from StepBasic 2 -> ChangeRequest from StepAP203 3 -> StartRequest from StepAP203 4 -> Change from StepAP203 5 -> StartWork from StepAP203 6 -> ApprovalPersonOrganization from StepBasic 7 -> Contract from StepBasic 8 -> SecurityClassification from StepBasic 9 -> Certification from StepBasic 0 else", py::arg("ent"));
	cls_StepAP203_DateTimeItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP203_DateTimeItem::*)() const ) &StepAP203_DateTimeItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
	cls_StepAP203_DateTimeItem.def("ChangeRequest", (opencascade::handle<StepAP203_ChangeRequest> (StepAP203_DateTimeItem::*)() const ) &StepAP203_DateTimeItem::ChangeRequest, "Returns Value as ChangeRequest (or Null if another type)");
	cls_StepAP203_DateTimeItem.def("StartRequest", (opencascade::handle<StepAP203_StartRequest> (StepAP203_DateTimeItem::*)() const ) &StepAP203_DateTimeItem::StartRequest, "Returns Value as StartRequest (or Null if another type)");
	cls_StepAP203_DateTimeItem.def("Change", (opencascade::handle<StepAP203_Change> (StepAP203_DateTimeItem::*)() const ) &StepAP203_DateTimeItem::Change, "Returns Value as Change (or Null if another type)");
	cls_StepAP203_DateTimeItem.def("StartWork", (opencascade::handle<StepAP203_StartWork> (StepAP203_DateTimeItem::*)() const ) &StepAP203_DateTimeItem::StartWork, "Returns Value as StartWork (or Null if another type)");
	cls_StepAP203_DateTimeItem.def("ApprovalPersonOrganization", (opencascade::handle<StepBasic_ApprovalPersonOrganization> (StepAP203_DateTimeItem::*)() const ) &StepAP203_DateTimeItem::ApprovalPersonOrganization, "Returns Value as ApprovalPersonOrganization (or Null if another type)");
	cls_StepAP203_DateTimeItem.def("Contract", (opencascade::handle<StepBasic_Contract> (StepAP203_DateTimeItem::*)() const ) &StepAP203_DateTimeItem::Contract, "Returns Value as Contract (or Null if another type)");
	cls_StepAP203_DateTimeItem.def("SecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepAP203_DateTimeItem::*)() const ) &StepAP203_DateTimeItem::SecurityClassification, "Returns Value as SecurityClassification (or Null if another type)");
	cls_StepAP203_DateTimeItem.def("Certification", (opencascade::handle<StepBasic_Certification> (StepAP203_DateTimeItem::*)() const ) &StepAP203_DateTimeItem::Certification, "Returns Value as Certification (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_PersonOrganizationItem.hxx
	py::class_<StepAP203_PersonOrganizationItem, std::unique_ptr<StepAP203_PersonOrganizationItem, Deleter<StepAP203_PersonOrganizationItem>>, StepData_SelectType> cls_StepAP203_PersonOrganizationItem(mod, "StepAP203_PersonOrganizationItem", "Representation of STEP SELECT type PersonOrganizationItem");
	cls_StepAP203_PersonOrganizationItem.def(py::init<>());
	cls_StepAP203_PersonOrganizationItem.def("CaseNum", (Standard_Integer (StepAP203_PersonOrganizationItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_PersonOrganizationItem::CaseNum, "Recognizes a kind of PersonOrganizationItem select type 1 -> Change from StepAP203 2 -> StartWork from StepAP203 3 -> ChangeRequest from StepAP203 4 -> StartRequest from StepAP203 5 -> ConfigurationItem from StepRepr 6 -> Product from StepBasic 7 -> ProductDefinitionFormation from StepBasic 8 -> ProductDefinition from StepBasic 9 -> Contract from StepBasic 10 -> SecurityClassification from StepBasic 0 else", py::arg("ent"));
	cls_StepAP203_PersonOrganizationItem.def("Change", (opencascade::handle<StepAP203_Change> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::Change, "Returns Value as Change (or Null if another type)");
	cls_StepAP203_PersonOrganizationItem.def("StartWork", (opencascade::handle<StepAP203_StartWork> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::StartWork, "Returns Value as StartWork (or Null if another type)");
	cls_StepAP203_PersonOrganizationItem.def("ChangeRequest", (opencascade::handle<StepAP203_ChangeRequest> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::ChangeRequest, "Returns Value as ChangeRequest (or Null if another type)");
	cls_StepAP203_PersonOrganizationItem.def("StartRequest", (opencascade::handle<StepAP203_StartRequest> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::StartRequest, "Returns Value as StartRequest (or Null if another type)");
	cls_StepAP203_PersonOrganizationItem.def("ConfigurationItem", (opencascade::handle<StepRepr_ConfigurationItem> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::ConfigurationItem, "Returns Value as ConfigurationItem (or Null if another type)");
	cls_StepAP203_PersonOrganizationItem.def("Product", (opencascade::handle<StepBasic_Product> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::Product, "Returns Value as Product (or Null if another type)");
	cls_StepAP203_PersonOrganizationItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");
	cls_StepAP203_PersonOrganizationItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
	cls_StepAP203_PersonOrganizationItem.def("Contract", (opencascade::handle<StepBasic_Contract> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::Contract, "Returns Value as Contract (or Null if another type)");
	cls_StepAP203_PersonOrganizationItem.def("SecurityClassification", (opencascade::handle<StepBasic_SecurityClassification> (StepAP203_PersonOrganizationItem::*)() const ) &StepAP203_PersonOrganizationItem::SecurityClassification, "Returns Value as SecurityClassification (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_SpecifiedItem.hxx
	py::class_<StepAP203_SpecifiedItem, std::unique_ptr<StepAP203_SpecifiedItem, Deleter<StepAP203_SpecifiedItem>>, StepData_SelectType> cls_StepAP203_SpecifiedItem(mod, "StepAP203_SpecifiedItem", "Representation of STEP SELECT type SpecifiedItem");
	cls_StepAP203_SpecifiedItem.def(py::init<>());
	cls_StepAP203_SpecifiedItem.def("CaseNum", (Standard_Integer (StepAP203_SpecifiedItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_SpecifiedItem::CaseNum, "Recognizes a kind of SpecifiedItem select type 1 -> ProductDefinition from StepBasic 2 -> ShapeAspect from StepRepr 0 else", py::arg("ent"));
	cls_StepAP203_SpecifiedItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepAP203_SpecifiedItem::*)() const ) &StepAP203_SpecifiedItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
	cls_StepAP203_SpecifiedItem.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepAP203_SpecifiedItem::*)() const ) &StepAP203_SpecifiedItem::ShapeAspect, "Returns Value as ShapeAspect (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_StartRequestItem.hxx
	py::class_<StepAP203_StartRequestItem, std::unique_ptr<StepAP203_StartRequestItem, Deleter<StepAP203_StartRequestItem>>, StepData_SelectType> cls_StepAP203_StartRequestItem(mod, "StepAP203_StartRequestItem", "Representation of STEP SELECT type StartRequestItem");
	cls_StepAP203_StartRequestItem.def(py::init<>());
	cls_StepAP203_StartRequestItem.def("CaseNum", (Standard_Integer (StepAP203_StartRequestItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_StartRequestItem::CaseNum, "Recognizes a kind of StartRequestItem select type 1 -> ProductDefinitionFormation from StepBasic 0 else", py::arg("ent"));
	cls_StepAP203_StartRequestItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_StartRequestItem::*)() const ) &StepAP203_StartRequestItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_WorkItem.hxx
	py::class_<StepAP203_WorkItem, std::unique_ptr<StepAP203_WorkItem, Deleter<StepAP203_WorkItem>>, StepData_SelectType> cls_StepAP203_WorkItem(mod, "StepAP203_WorkItem", "Representation of STEP SELECT type WorkItem");
	cls_StepAP203_WorkItem.def(py::init<>());
	cls_StepAP203_WorkItem.def("CaseNum", (Standard_Integer (StepAP203_WorkItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepAP203_WorkItem::CaseNum, "Recognizes a kind of WorkItem select type 1 -> ProductDefinitionFormation from StepBasic 0 else", py::arg("ent"));
	cls_StepAP203_WorkItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepAP203_WorkItem::*)() const ) &StepAP203_WorkItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfApprovedItem, std::unique_ptr<StepAP203_Array1OfApprovedItem, Deleter<StepAP203_Array1OfApprovedItem>>> cls_StepAP203_Array1OfApprovedItem(mod, "StepAP203_Array1OfApprovedItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfApprovedItem.def(py::init<>());
	cls_StepAP203_Array1OfApprovedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfApprovedItem.def(py::init([] (const StepAP203_Array1OfApprovedItem &other) {return new StepAP203_Array1OfApprovedItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfApprovedItem.def(py::init<StepAP203_Array1OfApprovedItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfApprovedItem.def(py::init<const StepAP203_ApprovedItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfApprovedItem.def("begin", (StepAP203_Array1OfApprovedItem::iterator (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfApprovedItem.def("end", (StepAP203_Array1OfApprovedItem::iterator (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfApprovedItem.def("cbegin", (StepAP203_Array1OfApprovedItem::const_iterator (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfApprovedItem.def("cend", (StepAP203_Array1OfApprovedItem::const_iterator (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfApprovedItem.def("Init", (void (StepAP203_Array1OfApprovedItem::*)(const StepAP203_ApprovedItem &)) &StepAP203_Array1OfApprovedItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfApprovedItem.def("Size", (Standard_Integer (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::Size, "Size query");
	cls_StepAP203_Array1OfApprovedItem.def("Length", (Standard_Integer (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfApprovedItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfApprovedItem.def("Lower", (Standard_Integer (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfApprovedItem.def("Upper", (Standard_Integer (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfApprovedItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfApprovedItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfApprovedItem.def("Assign", (StepAP203_Array1OfApprovedItem & (StepAP203_Array1OfApprovedItem::*)(const StepAP203_Array1OfApprovedItem &)) &StepAP203_Array1OfApprovedItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfApprovedItem.def("Move", (StepAP203_Array1OfApprovedItem & (StepAP203_Array1OfApprovedItem::*)(StepAP203_Array1OfApprovedItem &&)) &StepAP203_Array1OfApprovedItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfApprovedItem.def("assign", (StepAP203_Array1OfApprovedItem & (StepAP203_Array1OfApprovedItem::*)(const StepAP203_Array1OfApprovedItem &)) &StepAP203_Array1OfApprovedItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfApprovedItem.def("assign", (StepAP203_Array1OfApprovedItem & (StepAP203_Array1OfApprovedItem::*)(StepAP203_Array1OfApprovedItem &&)) &StepAP203_Array1OfApprovedItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfApprovedItem.def("First", (const StepAP203_ApprovedItem & (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::First, "Returns first element");
	cls_StepAP203_Array1OfApprovedItem.def("ChangeFirst", (StepAP203_ApprovedItem & (StepAP203_Array1OfApprovedItem::*)()) &StepAP203_Array1OfApprovedItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfApprovedItem.def("Last", (const StepAP203_ApprovedItem & (StepAP203_Array1OfApprovedItem::*)() const ) &StepAP203_Array1OfApprovedItem::Last, "Returns last element");
	cls_StepAP203_Array1OfApprovedItem.def("ChangeLast", (StepAP203_ApprovedItem & (StepAP203_Array1OfApprovedItem::*)()) &StepAP203_Array1OfApprovedItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfApprovedItem.def("Value", (const StepAP203_ApprovedItem & (StepAP203_Array1OfApprovedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfApprovedItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfApprovedItem.def("__call__", (const StepAP203_ApprovedItem & (StepAP203_Array1OfApprovedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfApprovedItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfApprovedItem.def("ChangeValue", (StepAP203_ApprovedItem & (StepAP203_Array1OfApprovedItem::*)(const Standard_Integer)) &StepAP203_Array1OfApprovedItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfApprovedItem.def("__call__", (StepAP203_ApprovedItem & (StepAP203_Array1OfApprovedItem::*)(const Standard_Integer)) &StepAP203_Array1OfApprovedItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfApprovedItem.def("SetValue", (void (StepAP203_Array1OfApprovedItem::*)(const Standard_Integer, const StepAP203_ApprovedItem &)) &StepAP203_Array1OfApprovedItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfApprovedItem.def("Resize", (void (StepAP203_Array1OfApprovedItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfApprovedItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfApprovedItem.def("__iter__", [](const StepAP203_Array1OfApprovedItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfCertifiedItem, std::unique_ptr<StepAP203_Array1OfCertifiedItem, Deleter<StepAP203_Array1OfCertifiedItem>>> cls_StepAP203_Array1OfCertifiedItem(mod, "StepAP203_Array1OfCertifiedItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfCertifiedItem.def(py::init<>());
	cls_StepAP203_Array1OfCertifiedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfCertifiedItem.def(py::init([] (const StepAP203_Array1OfCertifiedItem &other) {return new StepAP203_Array1OfCertifiedItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfCertifiedItem.def(py::init<StepAP203_Array1OfCertifiedItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfCertifiedItem.def(py::init<const StepAP203_CertifiedItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfCertifiedItem.def("begin", (StepAP203_Array1OfCertifiedItem::iterator (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfCertifiedItem.def("end", (StepAP203_Array1OfCertifiedItem::iterator (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfCertifiedItem.def("cbegin", (StepAP203_Array1OfCertifiedItem::const_iterator (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfCertifiedItem.def("cend", (StepAP203_Array1OfCertifiedItem::const_iterator (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfCertifiedItem.def("Init", (void (StepAP203_Array1OfCertifiedItem::*)(const StepAP203_CertifiedItem &)) &StepAP203_Array1OfCertifiedItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfCertifiedItem.def("Size", (Standard_Integer (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::Size, "Size query");
	cls_StepAP203_Array1OfCertifiedItem.def("Length", (Standard_Integer (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfCertifiedItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfCertifiedItem.def("Lower", (Standard_Integer (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfCertifiedItem.def("Upper", (Standard_Integer (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfCertifiedItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfCertifiedItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfCertifiedItem.def("Assign", (StepAP203_Array1OfCertifiedItem & (StepAP203_Array1OfCertifiedItem::*)(const StepAP203_Array1OfCertifiedItem &)) &StepAP203_Array1OfCertifiedItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfCertifiedItem.def("Move", (StepAP203_Array1OfCertifiedItem & (StepAP203_Array1OfCertifiedItem::*)(StepAP203_Array1OfCertifiedItem &&)) &StepAP203_Array1OfCertifiedItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfCertifiedItem.def("assign", (StepAP203_Array1OfCertifiedItem & (StepAP203_Array1OfCertifiedItem::*)(const StepAP203_Array1OfCertifiedItem &)) &StepAP203_Array1OfCertifiedItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfCertifiedItem.def("assign", (StepAP203_Array1OfCertifiedItem & (StepAP203_Array1OfCertifiedItem::*)(StepAP203_Array1OfCertifiedItem &&)) &StepAP203_Array1OfCertifiedItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfCertifiedItem.def("First", (const StepAP203_CertifiedItem & (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::First, "Returns first element");
	cls_StepAP203_Array1OfCertifiedItem.def("ChangeFirst", (StepAP203_CertifiedItem & (StepAP203_Array1OfCertifiedItem::*)()) &StepAP203_Array1OfCertifiedItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfCertifiedItem.def("Last", (const StepAP203_CertifiedItem & (StepAP203_Array1OfCertifiedItem::*)() const ) &StepAP203_Array1OfCertifiedItem::Last, "Returns last element");
	cls_StepAP203_Array1OfCertifiedItem.def("ChangeLast", (StepAP203_CertifiedItem & (StepAP203_Array1OfCertifiedItem::*)()) &StepAP203_Array1OfCertifiedItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfCertifiedItem.def("Value", (const StepAP203_CertifiedItem & (StepAP203_Array1OfCertifiedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfCertifiedItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfCertifiedItem.def("__call__", (const StepAP203_CertifiedItem & (StepAP203_Array1OfCertifiedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfCertifiedItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfCertifiedItem.def("ChangeValue", (StepAP203_CertifiedItem & (StepAP203_Array1OfCertifiedItem::*)(const Standard_Integer)) &StepAP203_Array1OfCertifiedItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfCertifiedItem.def("__call__", (StepAP203_CertifiedItem & (StepAP203_Array1OfCertifiedItem::*)(const Standard_Integer)) &StepAP203_Array1OfCertifiedItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfCertifiedItem.def("SetValue", (void (StepAP203_Array1OfCertifiedItem::*)(const Standard_Integer, const StepAP203_CertifiedItem &)) &StepAP203_Array1OfCertifiedItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfCertifiedItem.def("Resize", (void (StepAP203_Array1OfCertifiedItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfCertifiedItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfCertifiedItem.def("__iter__", [](const StepAP203_Array1OfCertifiedItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfContractedItem, std::unique_ptr<StepAP203_Array1OfContractedItem, Deleter<StepAP203_Array1OfContractedItem>>> cls_StepAP203_Array1OfContractedItem(mod, "StepAP203_Array1OfContractedItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfContractedItem.def(py::init<>());
	cls_StepAP203_Array1OfContractedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfContractedItem.def(py::init([] (const StepAP203_Array1OfContractedItem &other) {return new StepAP203_Array1OfContractedItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfContractedItem.def(py::init<StepAP203_Array1OfContractedItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfContractedItem.def(py::init<const StepAP203_ContractedItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfContractedItem.def("begin", (StepAP203_Array1OfContractedItem::iterator (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfContractedItem.def("end", (StepAP203_Array1OfContractedItem::iterator (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfContractedItem.def("cbegin", (StepAP203_Array1OfContractedItem::const_iterator (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfContractedItem.def("cend", (StepAP203_Array1OfContractedItem::const_iterator (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfContractedItem.def("Init", (void (StepAP203_Array1OfContractedItem::*)(const StepAP203_ContractedItem &)) &StepAP203_Array1OfContractedItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfContractedItem.def("Size", (Standard_Integer (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::Size, "Size query");
	cls_StepAP203_Array1OfContractedItem.def("Length", (Standard_Integer (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfContractedItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfContractedItem.def("Lower", (Standard_Integer (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfContractedItem.def("Upper", (Standard_Integer (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfContractedItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfContractedItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfContractedItem.def("Assign", (StepAP203_Array1OfContractedItem & (StepAP203_Array1OfContractedItem::*)(const StepAP203_Array1OfContractedItem &)) &StepAP203_Array1OfContractedItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfContractedItem.def("Move", (StepAP203_Array1OfContractedItem & (StepAP203_Array1OfContractedItem::*)(StepAP203_Array1OfContractedItem &&)) &StepAP203_Array1OfContractedItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfContractedItem.def("assign", (StepAP203_Array1OfContractedItem & (StepAP203_Array1OfContractedItem::*)(const StepAP203_Array1OfContractedItem &)) &StepAP203_Array1OfContractedItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfContractedItem.def("assign", (StepAP203_Array1OfContractedItem & (StepAP203_Array1OfContractedItem::*)(StepAP203_Array1OfContractedItem &&)) &StepAP203_Array1OfContractedItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfContractedItem.def("First", (const StepAP203_ContractedItem & (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::First, "Returns first element");
	cls_StepAP203_Array1OfContractedItem.def("ChangeFirst", (StepAP203_ContractedItem & (StepAP203_Array1OfContractedItem::*)()) &StepAP203_Array1OfContractedItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfContractedItem.def("Last", (const StepAP203_ContractedItem & (StepAP203_Array1OfContractedItem::*)() const ) &StepAP203_Array1OfContractedItem::Last, "Returns last element");
	cls_StepAP203_Array1OfContractedItem.def("ChangeLast", (StepAP203_ContractedItem & (StepAP203_Array1OfContractedItem::*)()) &StepAP203_Array1OfContractedItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfContractedItem.def("Value", (const StepAP203_ContractedItem & (StepAP203_Array1OfContractedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfContractedItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfContractedItem.def("__call__", (const StepAP203_ContractedItem & (StepAP203_Array1OfContractedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfContractedItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfContractedItem.def("ChangeValue", (StepAP203_ContractedItem & (StepAP203_Array1OfContractedItem::*)(const Standard_Integer)) &StepAP203_Array1OfContractedItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfContractedItem.def("__call__", (StepAP203_ContractedItem & (StepAP203_Array1OfContractedItem::*)(const Standard_Integer)) &StepAP203_Array1OfContractedItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfContractedItem.def("SetValue", (void (StepAP203_Array1OfContractedItem::*)(const Standard_Integer, const StepAP203_ContractedItem &)) &StepAP203_Array1OfContractedItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfContractedItem.def("Resize", (void (StepAP203_Array1OfContractedItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfContractedItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfContractedItem.def("__iter__", [](const StepAP203_Array1OfContractedItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfDateTimeItem, std::unique_ptr<StepAP203_Array1OfDateTimeItem, Deleter<StepAP203_Array1OfDateTimeItem>>> cls_StepAP203_Array1OfDateTimeItem(mod, "StepAP203_Array1OfDateTimeItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfDateTimeItem.def(py::init<>());
	cls_StepAP203_Array1OfDateTimeItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfDateTimeItem.def(py::init([] (const StepAP203_Array1OfDateTimeItem &other) {return new StepAP203_Array1OfDateTimeItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfDateTimeItem.def(py::init<StepAP203_Array1OfDateTimeItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfDateTimeItem.def(py::init<const StepAP203_DateTimeItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfDateTimeItem.def("begin", (StepAP203_Array1OfDateTimeItem::iterator (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfDateTimeItem.def("end", (StepAP203_Array1OfDateTimeItem::iterator (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfDateTimeItem.def("cbegin", (StepAP203_Array1OfDateTimeItem::const_iterator (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfDateTimeItem.def("cend", (StepAP203_Array1OfDateTimeItem::const_iterator (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfDateTimeItem.def("Init", (void (StepAP203_Array1OfDateTimeItem::*)(const StepAP203_DateTimeItem &)) &StepAP203_Array1OfDateTimeItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfDateTimeItem.def("Size", (Standard_Integer (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::Size, "Size query");
	cls_StepAP203_Array1OfDateTimeItem.def("Length", (Standard_Integer (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfDateTimeItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfDateTimeItem.def("Lower", (Standard_Integer (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfDateTimeItem.def("Upper", (Standard_Integer (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfDateTimeItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfDateTimeItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfDateTimeItem.def("Assign", (StepAP203_Array1OfDateTimeItem & (StepAP203_Array1OfDateTimeItem::*)(const StepAP203_Array1OfDateTimeItem &)) &StepAP203_Array1OfDateTimeItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfDateTimeItem.def("Move", (StepAP203_Array1OfDateTimeItem & (StepAP203_Array1OfDateTimeItem::*)(StepAP203_Array1OfDateTimeItem &&)) &StepAP203_Array1OfDateTimeItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfDateTimeItem.def("assign", (StepAP203_Array1OfDateTimeItem & (StepAP203_Array1OfDateTimeItem::*)(const StepAP203_Array1OfDateTimeItem &)) &StepAP203_Array1OfDateTimeItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfDateTimeItem.def("assign", (StepAP203_Array1OfDateTimeItem & (StepAP203_Array1OfDateTimeItem::*)(StepAP203_Array1OfDateTimeItem &&)) &StepAP203_Array1OfDateTimeItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfDateTimeItem.def("First", (const StepAP203_DateTimeItem & (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::First, "Returns first element");
	cls_StepAP203_Array1OfDateTimeItem.def("ChangeFirst", (StepAP203_DateTimeItem & (StepAP203_Array1OfDateTimeItem::*)()) &StepAP203_Array1OfDateTimeItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfDateTimeItem.def("Last", (const StepAP203_DateTimeItem & (StepAP203_Array1OfDateTimeItem::*)() const ) &StepAP203_Array1OfDateTimeItem::Last, "Returns last element");
	cls_StepAP203_Array1OfDateTimeItem.def("ChangeLast", (StepAP203_DateTimeItem & (StepAP203_Array1OfDateTimeItem::*)()) &StepAP203_Array1OfDateTimeItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfDateTimeItem.def("Value", (const StepAP203_DateTimeItem & (StepAP203_Array1OfDateTimeItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfDateTimeItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfDateTimeItem.def("__call__", (const StepAP203_DateTimeItem & (StepAP203_Array1OfDateTimeItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfDateTimeItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfDateTimeItem.def("ChangeValue", (StepAP203_DateTimeItem & (StepAP203_Array1OfDateTimeItem::*)(const Standard_Integer)) &StepAP203_Array1OfDateTimeItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfDateTimeItem.def("__call__", (StepAP203_DateTimeItem & (StepAP203_Array1OfDateTimeItem::*)(const Standard_Integer)) &StepAP203_Array1OfDateTimeItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfDateTimeItem.def("SetValue", (void (StepAP203_Array1OfDateTimeItem::*)(const Standard_Integer, const StepAP203_DateTimeItem &)) &StepAP203_Array1OfDateTimeItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfDateTimeItem.def("Resize", (void (StepAP203_Array1OfDateTimeItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfDateTimeItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfDateTimeItem.def("__iter__", [](const StepAP203_Array1OfDateTimeItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfPersonOrganizationItem, std::unique_ptr<StepAP203_Array1OfPersonOrganizationItem, Deleter<StepAP203_Array1OfPersonOrganizationItem>>> cls_StepAP203_Array1OfPersonOrganizationItem(mod, "StepAP203_Array1OfPersonOrganizationItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfPersonOrganizationItem.def(py::init<>());
	cls_StepAP203_Array1OfPersonOrganizationItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def(py::init([] (const StepAP203_Array1OfPersonOrganizationItem &other) {return new StepAP203_Array1OfPersonOrganizationItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfPersonOrganizationItem.def(py::init<StepAP203_Array1OfPersonOrganizationItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def(py::init<const StepAP203_PersonOrganizationItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("begin", (StepAP203_Array1OfPersonOrganizationItem::iterator (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("end", (StepAP203_Array1OfPersonOrganizationItem::iterator (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("cbegin", (StepAP203_Array1OfPersonOrganizationItem::const_iterator (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("cend", (StepAP203_Array1OfPersonOrganizationItem::const_iterator (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("Init", (void (StepAP203_Array1OfPersonOrganizationItem::*)(const StepAP203_PersonOrganizationItem &)) &StepAP203_Array1OfPersonOrganizationItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("Size", (Standard_Integer (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::Size, "Size query");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("Length", (Standard_Integer (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("Lower", (Standard_Integer (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("Upper", (Standard_Integer (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("Assign", (StepAP203_Array1OfPersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)(const StepAP203_Array1OfPersonOrganizationItem &)) &StepAP203_Array1OfPersonOrganizationItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfPersonOrganizationItem.def("Move", (StepAP203_Array1OfPersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)(StepAP203_Array1OfPersonOrganizationItem &&)) &StepAP203_Array1OfPersonOrganizationItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("assign", (StepAP203_Array1OfPersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)(const StepAP203_Array1OfPersonOrganizationItem &)) &StepAP203_Array1OfPersonOrganizationItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfPersonOrganizationItem.def("assign", (StepAP203_Array1OfPersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)(StepAP203_Array1OfPersonOrganizationItem &&)) &StepAP203_Array1OfPersonOrganizationItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("First", (const StepAP203_PersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::First, "Returns first element");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("ChangeFirst", (StepAP203_PersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)()) &StepAP203_Array1OfPersonOrganizationItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("Last", (const StepAP203_PersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)() const ) &StepAP203_Array1OfPersonOrganizationItem::Last, "Returns last element");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("ChangeLast", (StepAP203_PersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)()) &StepAP203_Array1OfPersonOrganizationItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfPersonOrganizationItem.def("Value", (const StepAP203_PersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfPersonOrganizationItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("__call__", (const StepAP203_PersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfPersonOrganizationItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("ChangeValue", (StepAP203_PersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)(const Standard_Integer)) &StepAP203_Array1OfPersonOrganizationItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("__call__", (StepAP203_PersonOrganizationItem & (StepAP203_Array1OfPersonOrganizationItem::*)(const Standard_Integer)) &StepAP203_Array1OfPersonOrganizationItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("SetValue", (void (StepAP203_Array1OfPersonOrganizationItem::*)(const Standard_Integer, const StepAP203_PersonOrganizationItem &)) &StepAP203_Array1OfPersonOrganizationItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("Resize", (void (StepAP203_Array1OfPersonOrganizationItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfPersonOrganizationItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfPersonOrganizationItem.def("__iter__", [](const StepAP203_Array1OfPersonOrganizationItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfClassifiedItem, std::unique_ptr<StepAP203_Array1OfClassifiedItem, Deleter<StepAP203_Array1OfClassifiedItem>>> cls_StepAP203_Array1OfClassifiedItem(mod, "StepAP203_Array1OfClassifiedItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfClassifiedItem.def(py::init<>());
	cls_StepAP203_Array1OfClassifiedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfClassifiedItem.def(py::init([] (const StepAP203_Array1OfClassifiedItem &other) {return new StepAP203_Array1OfClassifiedItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfClassifiedItem.def(py::init<StepAP203_Array1OfClassifiedItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfClassifiedItem.def(py::init<const StepAP203_ClassifiedItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfClassifiedItem.def("begin", (StepAP203_Array1OfClassifiedItem::iterator (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfClassifiedItem.def("end", (StepAP203_Array1OfClassifiedItem::iterator (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfClassifiedItem.def("cbegin", (StepAP203_Array1OfClassifiedItem::const_iterator (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfClassifiedItem.def("cend", (StepAP203_Array1OfClassifiedItem::const_iterator (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfClassifiedItem.def("Init", (void (StepAP203_Array1OfClassifiedItem::*)(const StepAP203_ClassifiedItem &)) &StepAP203_Array1OfClassifiedItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfClassifiedItem.def("Size", (Standard_Integer (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::Size, "Size query");
	cls_StepAP203_Array1OfClassifiedItem.def("Length", (Standard_Integer (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfClassifiedItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfClassifiedItem.def("Lower", (Standard_Integer (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfClassifiedItem.def("Upper", (Standard_Integer (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfClassifiedItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfClassifiedItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfClassifiedItem.def("Assign", (StepAP203_Array1OfClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)(const StepAP203_Array1OfClassifiedItem &)) &StepAP203_Array1OfClassifiedItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfClassifiedItem.def("Move", (StepAP203_Array1OfClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)(StepAP203_Array1OfClassifiedItem &&)) &StepAP203_Array1OfClassifiedItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfClassifiedItem.def("assign", (StepAP203_Array1OfClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)(const StepAP203_Array1OfClassifiedItem &)) &StepAP203_Array1OfClassifiedItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfClassifiedItem.def("assign", (StepAP203_Array1OfClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)(StepAP203_Array1OfClassifiedItem &&)) &StepAP203_Array1OfClassifiedItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfClassifiedItem.def("First", (const StepAP203_ClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::First, "Returns first element");
	cls_StepAP203_Array1OfClassifiedItem.def("ChangeFirst", (StepAP203_ClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)()) &StepAP203_Array1OfClassifiedItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfClassifiedItem.def("Last", (const StepAP203_ClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)() const ) &StepAP203_Array1OfClassifiedItem::Last, "Returns last element");
	cls_StepAP203_Array1OfClassifiedItem.def("ChangeLast", (StepAP203_ClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)()) &StepAP203_Array1OfClassifiedItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfClassifiedItem.def("Value", (const StepAP203_ClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfClassifiedItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfClassifiedItem.def("__call__", (const StepAP203_ClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfClassifiedItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfClassifiedItem.def("ChangeValue", (StepAP203_ClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)(const Standard_Integer)) &StepAP203_Array1OfClassifiedItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfClassifiedItem.def("__call__", (StepAP203_ClassifiedItem & (StepAP203_Array1OfClassifiedItem::*)(const Standard_Integer)) &StepAP203_Array1OfClassifiedItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfClassifiedItem.def("SetValue", (void (StepAP203_Array1OfClassifiedItem::*)(const Standard_Integer, const StepAP203_ClassifiedItem &)) &StepAP203_Array1OfClassifiedItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfClassifiedItem.def("Resize", (void (StepAP203_Array1OfClassifiedItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfClassifiedItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfClassifiedItem.def("__iter__", [](const StepAP203_Array1OfClassifiedItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfSpecifiedItem, std::unique_ptr<StepAP203_Array1OfSpecifiedItem, Deleter<StepAP203_Array1OfSpecifiedItem>>> cls_StepAP203_Array1OfSpecifiedItem(mod, "StepAP203_Array1OfSpecifiedItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfSpecifiedItem.def(py::init<>());
	cls_StepAP203_Array1OfSpecifiedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfSpecifiedItem.def(py::init([] (const StepAP203_Array1OfSpecifiedItem &other) {return new StepAP203_Array1OfSpecifiedItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfSpecifiedItem.def(py::init<StepAP203_Array1OfSpecifiedItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfSpecifiedItem.def(py::init<const StepAP203_SpecifiedItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfSpecifiedItem.def("begin", (StepAP203_Array1OfSpecifiedItem::iterator (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfSpecifiedItem.def("end", (StepAP203_Array1OfSpecifiedItem::iterator (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfSpecifiedItem.def("cbegin", (StepAP203_Array1OfSpecifiedItem::const_iterator (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfSpecifiedItem.def("cend", (StepAP203_Array1OfSpecifiedItem::const_iterator (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfSpecifiedItem.def("Init", (void (StepAP203_Array1OfSpecifiedItem::*)(const StepAP203_SpecifiedItem &)) &StepAP203_Array1OfSpecifiedItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfSpecifiedItem.def("Size", (Standard_Integer (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::Size, "Size query");
	cls_StepAP203_Array1OfSpecifiedItem.def("Length", (Standard_Integer (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfSpecifiedItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfSpecifiedItem.def("Lower", (Standard_Integer (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfSpecifiedItem.def("Upper", (Standard_Integer (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfSpecifiedItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfSpecifiedItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfSpecifiedItem.def("Assign", (StepAP203_Array1OfSpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)(const StepAP203_Array1OfSpecifiedItem &)) &StepAP203_Array1OfSpecifiedItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfSpecifiedItem.def("Move", (StepAP203_Array1OfSpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)(StepAP203_Array1OfSpecifiedItem &&)) &StepAP203_Array1OfSpecifiedItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfSpecifiedItem.def("assign", (StepAP203_Array1OfSpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)(const StepAP203_Array1OfSpecifiedItem &)) &StepAP203_Array1OfSpecifiedItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfSpecifiedItem.def("assign", (StepAP203_Array1OfSpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)(StepAP203_Array1OfSpecifiedItem &&)) &StepAP203_Array1OfSpecifiedItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfSpecifiedItem.def("First", (const StepAP203_SpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::First, "Returns first element");
	cls_StepAP203_Array1OfSpecifiedItem.def("ChangeFirst", (StepAP203_SpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)()) &StepAP203_Array1OfSpecifiedItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfSpecifiedItem.def("Last", (const StepAP203_SpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)() const ) &StepAP203_Array1OfSpecifiedItem::Last, "Returns last element");
	cls_StepAP203_Array1OfSpecifiedItem.def("ChangeLast", (StepAP203_SpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)()) &StepAP203_Array1OfSpecifiedItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfSpecifiedItem.def("Value", (const StepAP203_SpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfSpecifiedItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfSpecifiedItem.def("__call__", (const StepAP203_SpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfSpecifiedItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfSpecifiedItem.def("ChangeValue", (StepAP203_SpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)(const Standard_Integer)) &StepAP203_Array1OfSpecifiedItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfSpecifiedItem.def("__call__", (StepAP203_SpecifiedItem & (StepAP203_Array1OfSpecifiedItem::*)(const Standard_Integer)) &StepAP203_Array1OfSpecifiedItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfSpecifiedItem.def("SetValue", (void (StepAP203_Array1OfSpecifiedItem::*)(const Standard_Integer, const StepAP203_SpecifiedItem &)) &StepAP203_Array1OfSpecifiedItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfSpecifiedItem.def("Resize", (void (StepAP203_Array1OfSpecifiedItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfSpecifiedItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfSpecifiedItem.def("__iter__", [](const StepAP203_Array1OfSpecifiedItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfWorkItem, std::unique_ptr<StepAP203_Array1OfWorkItem, Deleter<StepAP203_Array1OfWorkItem>>> cls_StepAP203_Array1OfWorkItem(mod, "StepAP203_Array1OfWorkItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfWorkItem.def(py::init<>());
	cls_StepAP203_Array1OfWorkItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfWorkItem.def(py::init([] (const StepAP203_Array1OfWorkItem &other) {return new StepAP203_Array1OfWorkItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfWorkItem.def(py::init<StepAP203_Array1OfWorkItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfWorkItem.def(py::init<const StepAP203_WorkItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfWorkItem.def("begin", (StepAP203_Array1OfWorkItem::iterator (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfWorkItem.def("end", (StepAP203_Array1OfWorkItem::iterator (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfWorkItem.def("cbegin", (StepAP203_Array1OfWorkItem::const_iterator (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfWorkItem.def("cend", (StepAP203_Array1OfWorkItem::const_iterator (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfWorkItem.def("Init", (void (StepAP203_Array1OfWorkItem::*)(const StepAP203_WorkItem &)) &StepAP203_Array1OfWorkItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfWorkItem.def("Size", (Standard_Integer (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::Size, "Size query");
	cls_StepAP203_Array1OfWorkItem.def("Length", (Standard_Integer (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfWorkItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfWorkItem.def("Lower", (Standard_Integer (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfWorkItem.def("Upper", (Standard_Integer (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfWorkItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfWorkItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfWorkItem.def("Assign", (StepAP203_Array1OfWorkItem & (StepAP203_Array1OfWorkItem::*)(const StepAP203_Array1OfWorkItem &)) &StepAP203_Array1OfWorkItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfWorkItem.def("Move", (StepAP203_Array1OfWorkItem & (StepAP203_Array1OfWorkItem::*)(StepAP203_Array1OfWorkItem &&)) &StepAP203_Array1OfWorkItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfWorkItem.def("assign", (StepAP203_Array1OfWorkItem & (StepAP203_Array1OfWorkItem::*)(const StepAP203_Array1OfWorkItem &)) &StepAP203_Array1OfWorkItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfWorkItem.def("assign", (StepAP203_Array1OfWorkItem & (StepAP203_Array1OfWorkItem::*)(StepAP203_Array1OfWorkItem &&)) &StepAP203_Array1OfWorkItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfWorkItem.def("First", (const StepAP203_WorkItem & (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::First, "Returns first element");
	cls_StepAP203_Array1OfWorkItem.def("ChangeFirst", (StepAP203_WorkItem & (StepAP203_Array1OfWorkItem::*)()) &StepAP203_Array1OfWorkItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfWorkItem.def("Last", (const StepAP203_WorkItem & (StepAP203_Array1OfWorkItem::*)() const ) &StepAP203_Array1OfWorkItem::Last, "Returns last element");
	cls_StepAP203_Array1OfWorkItem.def("ChangeLast", (StepAP203_WorkItem & (StepAP203_Array1OfWorkItem::*)()) &StepAP203_Array1OfWorkItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfWorkItem.def("Value", (const StepAP203_WorkItem & (StepAP203_Array1OfWorkItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfWorkItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfWorkItem.def("__call__", (const StepAP203_WorkItem & (StepAP203_Array1OfWorkItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfWorkItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfWorkItem.def("ChangeValue", (StepAP203_WorkItem & (StepAP203_Array1OfWorkItem::*)(const Standard_Integer)) &StepAP203_Array1OfWorkItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfWorkItem.def("__call__", (StepAP203_WorkItem & (StepAP203_Array1OfWorkItem::*)(const Standard_Integer)) &StepAP203_Array1OfWorkItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfWorkItem.def("SetValue", (void (StepAP203_Array1OfWorkItem::*)(const Standard_Integer, const StepAP203_WorkItem &)) &StepAP203_Array1OfWorkItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfWorkItem.def("Resize", (void (StepAP203_Array1OfWorkItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfWorkItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfWorkItem.def("__iter__", [](const StepAP203_Array1OfWorkItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfChangeRequestItem, std::unique_ptr<StepAP203_Array1OfChangeRequestItem, Deleter<StepAP203_Array1OfChangeRequestItem>>> cls_StepAP203_Array1OfChangeRequestItem(mod, "StepAP203_Array1OfChangeRequestItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfChangeRequestItem.def(py::init<>());
	cls_StepAP203_Array1OfChangeRequestItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfChangeRequestItem.def(py::init([] (const StepAP203_Array1OfChangeRequestItem &other) {return new StepAP203_Array1OfChangeRequestItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfChangeRequestItem.def(py::init<StepAP203_Array1OfChangeRequestItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfChangeRequestItem.def(py::init<const StepAP203_ChangeRequestItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfChangeRequestItem.def("begin", (StepAP203_Array1OfChangeRequestItem::iterator (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfChangeRequestItem.def("end", (StepAP203_Array1OfChangeRequestItem::iterator (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfChangeRequestItem.def("cbegin", (StepAP203_Array1OfChangeRequestItem::const_iterator (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfChangeRequestItem.def("cend", (StepAP203_Array1OfChangeRequestItem::const_iterator (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfChangeRequestItem.def("Init", (void (StepAP203_Array1OfChangeRequestItem::*)(const StepAP203_ChangeRequestItem &)) &StepAP203_Array1OfChangeRequestItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfChangeRequestItem.def("Size", (Standard_Integer (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::Size, "Size query");
	cls_StepAP203_Array1OfChangeRequestItem.def("Length", (Standard_Integer (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfChangeRequestItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfChangeRequestItem.def("Lower", (Standard_Integer (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfChangeRequestItem.def("Upper", (Standard_Integer (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfChangeRequestItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfChangeRequestItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfChangeRequestItem.def("Assign", (StepAP203_Array1OfChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)(const StepAP203_Array1OfChangeRequestItem &)) &StepAP203_Array1OfChangeRequestItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfChangeRequestItem.def("Move", (StepAP203_Array1OfChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)(StepAP203_Array1OfChangeRequestItem &&)) &StepAP203_Array1OfChangeRequestItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfChangeRequestItem.def("assign", (StepAP203_Array1OfChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)(const StepAP203_Array1OfChangeRequestItem &)) &StepAP203_Array1OfChangeRequestItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfChangeRequestItem.def("assign", (StepAP203_Array1OfChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)(StepAP203_Array1OfChangeRequestItem &&)) &StepAP203_Array1OfChangeRequestItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfChangeRequestItem.def("First", (const StepAP203_ChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::First, "Returns first element");
	cls_StepAP203_Array1OfChangeRequestItem.def("ChangeFirst", (StepAP203_ChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)()) &StepAP203_Array1OfChangeRequestItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfChangeRequestItem.def("Last", (const StepAP203_ChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)() const ) &StepAP203_Array1OfChangeRequestItem::Last, "Returns last element");
	cls_StepAP203_Array1OfChangeRequestItem.def("ChangeLast", (StepAP203_ChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)()) &StepAP203_Array1OfChangeRequestItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfChangeRequestItem.def("Value", (const StepAP203_ChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfChangeRequestItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfChangeRequestItem.def("__call__", (const StepAP203_ChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfChangeRequestItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfChangeRequestItem.def("ChangeValue", (StepAP203_ChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)(const Standard_Integer)) &StepAP203_Array1OfChangeRequestItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfChangeRequestItem.def("__call__", (StepAP203_ChangeRequestItem & (StepAP203_Array1OfChangeRequestItem::*)(const Standard_Integer)) &StepAP203_Array1OfChangeRequestItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfChangeRequestItem.def("SetValue", (void (StepAP203_Array1OfChangeRequestItem::*)(const Standard_Integer, const StepAP203_ChangeRequestItem &)) &StepAP203_Array1OfChangeRequestItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfChangeRequestItem.def("Resize", (void (StepAP203_Array1OfChangeRequestItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfChangeRequestItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfChangeRequestItem.def("__iter__", [](const StepAP203_Array1OfChangeRequestItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<StepAP203_Array1OfStartRequestItem, std::unique_ptr<StepAP203_Array1OfStartRequestItem, Deleter<StepAP203_Array1OfStartRequestItem>>> cls_StepAP203_Array1OfStartRequestItem(mod, "StepAP203_Array1OfStartRequestItem", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_StepAP203_Array1OfStartRequestItem.def(py::init<>());
	cls_StepAP203_Array1OfStartRequestItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfStartRequestItem.def(py::init([] (const StepAP203_Array1OfStartRequestItem &other) {return new StepAP203_Array1OfStartRequestItem(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_StepAP203_Array1OfStartRequestItem.def(py::init<StepAP203_Array1OfStartRequestItem &&>(), py::arg("theOther"));
	cls_StepAP203_Array1OfStartRequestItem.def(py::init<const StepAP203_StartRequestItem &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_Array1OfStartRequestItem.def("begin", (StepAP203_Array1OfStartRequestItem::iterator (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::begin, "Returns an iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfStartRequestItem.def("end", (StepAP203_Array1OfStartRequestItem::iterator (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfStartRequestItem.def("cbegin", (StepAP203_Array1OfStartRequestItem::const_iterator (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_StepAP203_Array1OfStartRequestItem.def("cend", (StepAP203_Array1OfStartRequestItem::const_iterator (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_StepAP203_Array1OfStartRequestItem.def("Init", (void (StepAP203_Array1OfStartRequestItem::*)(const StepAP203_StartRequestItem &)) &StepAP203_Array1OfStartRequestItem::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_StepAP203_Array1OfStartRequestItem.def("Size", (Standard_Integer (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::Size, "Size query");
	cls_StepAP203_Array1OfStartRequestItem.def("Length", (Standard_Integer (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::Length, "Length query (the same)");
	cls_StepAP203_Array1OfStartRequestItem.def("IsEmpty", (Standard_Boolean (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::IsEmpty, "Return TRUE if array has zero length.");
	cls_StepAP203_Array1OfStartRequestItem.def("Lower", (Standard_Integer (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::Lower, "Lower bound");
	cls_StepAP203_Array1OfStartRequestItem.def("Upper", (Standard_Integer (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::Upper, "Upper bound");
	cls_StepAP203_Array1OfStartRequestItem.def("IsDeletable", (Standard_Boolean (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::IsDeletable, "myDeletable flag");
	cls_StepAP203_Array1OfStartRequestItem.def("IsAllocated", (Standard_Boolean (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_StepAP203_Array1OfStartRequestItem.def("Assign", (StepAP203_Array1OfStartRequestItem & (StepAP203_Array1OfStartRequestItem::*)(const StepAP203_Array1OfStartRequestItem &)) &StepAP203_Array1OfStartRequestItem::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfStartRequestItem.def("Move", (StepAP203_Array1OfStartRequestItem & (StepAP203_Array1OfStartRequestItem::*)(StepAP203_Array1OfStartRequestItem &&)) &StepAP203_Array1OfStartRequestItem::Move, "Move assignment", py::arg("theOther"));
	cls_StepAP203_Array1OfStartRequestItem.def("assign", (StepAP203_Array1OfStartRequestItem & (StepAP203_Array1OfStartRequestItem::*)(const StepAP203_Array1OfStartRequestItem &)) &StepAP203_Array1OfStartRequestItem::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_StepAP203_Array1OfStartRequestItem.def("assign", (StepAP203_Array1OfStartRequestItem & (StepAP203_Array1OfStartRequestItem::*)(StepAP203_Array1OfStartRequestItem &&)) &StepAP203_Array1OfStartRequestItem::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_StepAP203_Array1OfStartRequestItem.def("First", (const StepAP203_StartRequestItem & (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::First, "Returns first element");
	cls_StepAP203_Array1OfStartRequestItem.def("ChangeFirst", (StepAP203_StartRequestItem & (StepAP203_Array1OfStartRequestItem::*)()) &StepAP203_Array1OfStartRequestItem::ChangeFirst, "Returns first element");
	cls_StepAP203_Array1OfStartRequestItem.def("Last", (const StepAP203_StartRequestItem & (StepAP203_Array1OfStartRequestItem::*)() const ) &StepAP203_Array1OfStartRequestItem::Last, "Returns last element");
	cls_StepAP203_Array1OfStartRequestItem.def("ChangeLast", (StepAP203_StartRequestItem & (StepAP203_Array1OfStartRequestItem::*)()) &StepAP203_Array1OfStartRequestItem::ChangeLast, "Returns last element");
	cls_StepAP203_Array1OfStartRequestItem.def("Value", (const StepAP203_StartRequestItem & (StepAP203_Array1OfStartRequestItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfStartRequestItem::Value, "Constant value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfStartRequestItem.def("__call__", (const StepAP203_StartRequestItem & (StepAP203_Array1OfStartRequestItem::*)(const Standard_Integer) const ) &StepAP203_Array1OfStartRequestItem::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_StepAP203_Array1OfStartRequestItem.def("ChangeValue", (StepAP203_StartRequestItem & (StepAP203_Array1OfStartRequestItem::*)(const Standard_Integer)) &StepAP203_Array1OfStartRequestItem::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_StepAP203_Array1OfStartRequestItem.def("__call__", (StepAP203_StartRequestItem & (StepAP203_Array1OfStartRequestItem::*)(const Standard_Integer)) &StepAP203_Array1OfStartRequestItem::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_StepAP203_Array1OfStartRequestItem.def("SetValue", (void (StepAP203_Array1OfStartRequestItem::*)(const Standard_Integer, const StepAP203_StartRequestItem &)) &StepAP203_Array1OfStartRequestItem::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_StepAP203_Array1OfStartRequestItem.def("Resize", (void (StepAP203_Array1OfStartRequestItem::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &StepAP203_Array1OfStartRequestItem::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_StepAP203_Array1OfStartRequestItem.def("__iter__", [](const StepAP203_Array1OfStartRequestItem &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfApprovedItem.hxx
	py::class_<StepAP203_HArray1OfApprovedItem, opencascade::handle<StepAP203_HArray1OfApprovedItem>, StepAP203_Array1OfApprovedItem, Standard_Transient> cls_StepAP203_HArray1OfApprovedItem(mod, "StepAP203_HArray1OfApprovedItem", "None");
	cls_StepAP203_HArray1OfApprovedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfApprovedItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfApprovedItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfApprovedItem.def(py::init<const StepAP203_Array1OfApprovedItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfApprovedItem.def("Array1", (const StepAP203_Array1OfApprovedItem & (StepAP203_HArray1OfApprovedItem::*)() const ) &StepAP203_HArray1OfApprovedItem::Array1, "None");
	cls_StepAP203_HArray1OfApprovedItem.def("ChangeArray1", (StepAP203_Array1OfApprovedItem & (StepAP203_HArray1OfApprovedItem::*)()) &StepAP203_HArray1OfApprovedItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfApprovedItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfApprovedItem::get_type_name, "None");
	cls_StepAP203_HArray1OfApprovedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfApprovedItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfApprovedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfApprovedItem::*)() const ) &StepAP203_HArray1OfApprovedItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfCertifiedItem.hxx
	py::class_<StepAP203_HArray1OfCertifiedItem, opencascade::handle<StepAP203_HArray1OfCertifiedItem>, StepAP203_Array1OfCertifiedItem, Standard_Transient> cls_StepAP203_HArray1OfCertifiedItem(mod, "StepAP203_HArray1OfCertifiedItem", "None");
	cls_StepAP203_HArray1OfCertifiedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfCertifiedItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfCertifiedItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfCertifiedItem.def(py::init<const StepAP203_Array1OfCertifiedItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfCertifiedItem.def("Array1", (const StepAP203_Array1OfCertifiedItem & (StepAP203_HArray1OfCertifiedItem::*)() const ) &StepAP203_HArray1OfCertifiedItem::Array1, "None");
	cls_StepAP203_HArray1OfCertifiedItem.def("ChangeArray1", (StepAP203_Array1OfCertifiedItem & (StepAP203_HArray1OfCertifiedItem::*)()) &StepAP203_HArray1OfCertifiedItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfCertifiedItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfCertifiedItem::get_type_name, "None");
	cls_StepAP203_HArray1OfCertifiedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfCertifiedItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfCertifiedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfCertifiedItem::*)() const ) &StepAP203_HArray1OfCertifiedItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfChangeRequestItem.hxx
	py::class_<StepAP203_HArray1OfChangeRequestItem, opencascade::handle<StepAP203_HArray1OfChangeRequestItem>, StepAP203_Array1OfChangeRequestItem, Standard_Transient> cls_StepAP203_HArray1OfChangeRequestItem(mod, "StepAP203_HArray1OfChangeRequestItem", "None");
	cls_StepAP203_HArray1OfChangeRequestItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfChangeRequestItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfChangeRequestItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfChangeRequestItem.def(py::init<const StepAP203_Array1OfChangeRequestItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfChangeRequestItem.def("Array1", (const StepAP203_Array1OfChangeRequestItem & (StepAP203_HArray1OfChangeRequestItem::*)() const ) &StepAP203_HArray1OfChangeRequestItem::Array1, "None");
	cls_StepAP203_HArray1OfChangeRequestItem.def("ChangeArray1", (StepAP203_Array1OfChangeRequestItem & (StepAP203_HArray1OfChangeRequestItem::*)()) &StepAP203_HArray1OfChangeRequestItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfChangeRequestItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfChangeRequestItem::get_type_name, "None");
	cls_StepAP203_HArray1OfChangeRequestItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfChangeRequestItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfChangeRequestItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfChangeRequestItem::*)() const ) &StepAP203_HArray1OfChangeRequestItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfClassifiedItem.hxx
	py::class_<StepAP203_HArray1OfClassifiedItem, opencascade::handle<StepAP203_HArray1OfClassifiedItem>, StepAP203_Array1OfClassifiedItem, Standard_Transient> cls_StepAP203_HArray1OfClassifiedItem(mod, "StepAP203_HArray1OfClassifiedItem", "None");
	cls_StepAP203_HArray1OfClassifiedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfClassifiedItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfClassifiedItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfClassifiedItem.def(py::init<const StepAP203_Array1OfClassifiedItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfClassifiedItem.def("Array1", (const StepAP203_Array1OfClassifiedItem & (StepAP203_HArray1OfClassifiedItem::*)() const ) &StepAP203_HArray1OfClassifiedItem::Array1, "None");
	cls_StepAP203_HArray1OfClassifiedItem.def("ChangeArray1", (StepAP203_Array1OfClassifiedItem & (StepAP203_HArray1OfClassifiedItem::*)()) &StepAP203_HArray1OfClassifiedItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfClassifiedItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfClassifiedItem::get_type_name, "None");
	cls_StepAP203_HArray1OfClassifiedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfClassifiedItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfClassifiedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfClassifiedItem::*)() const ) &StepAP203_HArray1OfClassifiedItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfContractedItem.hxx
	py::class_<StepAP203_HArray1OfContractedItem, opencascade::handle<StepAP203_HArray1OfContractedItem>, StepAP203_Array1OfContractedItem, Standard_Transient> cls_StepAP203_HArray1OfContractedItem(mod, "StepAP203_HArray1OfContractedItem", "None");
	cls_StepAP203_HArray1OfContractedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfContractedItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfContractedItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfContractedItem.def(py::init<const StepAP203_Array1OfContractedItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfContractedItem.def("Array1", (const StepAP203_Array1OfContractedItem & (StepAP203_HArray1OfContractedItem::*)() const ) &StepAP203_HArray1OfContractedItem::Array1, "None");
	cls_StepAP203_HArray1OfContractedItem.def("ChangeArray1", (StepAP203_Array1OfContractedItem & (StepAP203_HArray1OfContractedItem::*)()) &StepAP203_HArray1OfContractedItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfContractedItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfContractedItem::get_type_name, "None");
	cls_StepAP203_HArray1OfContractedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfContractedItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfContractedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfContractedItem::*)() const ) &StepAP203_HArray1OfContractedItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfDateTimeItem.hxx
	py::class_<StepAP203_HArray1OfDateTimeItem, opencascade::handle<StepAP203_HArray1OfDateTimeItem>, StepAP203_Array1OfDateTimeItem, Standard_Transient> cls_StepAP203_HArray1OfDateTimeItem(mod, "StepAP203_HArray1OfDateTimeItem", "None");
	cls_StepAP203_HArray1OfDateTimeItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfDateTimeItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfDateTimeItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfDateTimeItem.def(py::init<const StepAP203_Array1OfDateTimeItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfDateTimeItem.def("Array1", (const StepAP203_Array1OfDateTimeItem & (StepAP203_HArray1OfDateTimeItem::*)() const ) &StepAP203_HArray1OfDateTimeItem::Array1, "None");
	cls_StepAP203_HArray1OfDateTimeItem.def("ChangeArray1", (StepAP203_Array1OfDateTimeItem & (StepAP203_HArray1OfDateTimeItem::*)()) &StepAP203_HArray1OfDateTimeItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfDateTimeItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfDateTimeItem::get_type_name, "None");
	cls_StepAP203_HArray1OfDateTimeItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfDateTimeItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfDateTimeItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfDateTimeItem::*)() const ) &StepAP203_HArray1OfDateTimeItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfPersonOrganizationItem.hxx
	py::class_<StepAP203_HArray1OfPersonOrganizationItem, opencascade::handle<StepAP203_HArray1OfPersonOrganizationItem>, StepAP203_Array1OfPersonOrganizationItem, Standard_Transient> cls_StepAP203_HArray1OfPersonOrganizationItem(mod, "StepAP203_HArray1OfPersonOrganizationItem", "None");
	cls_StepAP203_HArray1OfPersonOrganizationItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfPersonOrganizationItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfPersonOrganizationItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfPersonOrganizationItem.def(py::init<const StepAP203_Array1OfPersonOrganizationItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfPersonOrganizationItem.def("Array1", (const StepAP203_Array1OfPersonOrganizationItem & (StepAP203_HArray1OfPersonOrganizationItem::*)() const ) &StepAP203_HArray1OfPersonOrganizationItem::Array1, "None");
	cls_StepAP203_HArray1OfPersonOrganizationItem.def("ChangeArray1", (StepAP203_Array1OfPersonOrganizationItem & (StepAP203_HArray1OfPersonOrganizationItem::*)()) &StepAP203_HArray1OfPersonOrganizationItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfPersonOrganizationItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfPersonOrganizationItem::get_type_name, "None");
	cls_StepAP203_HArray1OfPersonOrganizationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfPersonOrganizationItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfPersonOrganizationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfPersonOrganizationItem::*)() const ) &StepAP203_HArray1OfPersonOrganizationItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfSpecifiedItem.hxx
	py::class_<StepAP203_HArray1OfSpecifiedItem, opencascade::handle<StepAP203_HArray1OfSpecifiedItem>, StepAP203_Array1OfSpecifiedItem, Standard_Transient> cls_StepAP203_HArray1OfSpecifiedItem(mod, "StepAP203_HArray1OfSpecifiedItem", "None");
	cls_StepAP203_HArray1OfSpecifiedItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfSpecifiedItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfSpecifiedItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfSpecifiedItem.def(py::init<const StepAP203_Array1OfSpecifiedItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfSpecifiedItem.def("Array1", (const StepAP203_Array1OfSpecifiedItem & (StepAP203_HArray1OfSpecifiedItem::*)() const ) &StepAP203_HArray1OfSpecifiedItem::Array1, "None");
	cls_StepAP203_HArray1OfSpecifiedItem.def("ChangeArray1", (StepAP203_Array1OfSpecifiedItem & (StepAP203_HArray1OfSpecifiedItem::*)()) &StepAP203_HArray1OfSpecifiedItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfSpecifiedItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfSpecifiedItem::get_type_name, "None");
	cls_StepAP203_HArray1OfSpecifiedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfSpecifiedItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfSpecifiedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfSpecifiedItem::*)() const ) &StepAP203_HArray1OfSpecifiedItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfStartRequestItem.hxx
	py::class_<StepAP203_HArray1OfStartRequestItem, opencascade::handle<StepAP203_HArray1OfStartRequestItem>, StepAP203_Array1OfStartRequestItem, Standard_Transient> cls_StepAP203_HArray1OfStartRequestItem(mod, "StepAP203_HArray1OfStartRequestItem", "None");
	cls_StepAP203_HArray1OfStartRequestItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfStartRequestItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfStartRequestItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfStartRequestItem.def(py::init<const StepAP203_Array1OfStartRequestItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfStartRequestItem.def("Array1", (const StepAP203_Array1OfStartRequestItem & (StepAP203_HArray1OfStartRequestItem::*)() const ) &StepAP203_HArray1OfStartRequestItem::Array1, "None");
	cls_StepAP203_HArray1OfStartRequestItem.def("ChangeArray1", (StepAP203_Array1OfStartRequestItem & (StepAP203_HArray1OfStartRequestItem::*)()) &StepAP203_HArray1OfStartRequestItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfStartRequestItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfStartRequestItem::get_type_name, "None");
	cls_StepAP203_HArray1OfStartRequestItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfStartRequestItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfStartRequestItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfStartRequestItem::*)() const ) &StepAP203_HArray1OfStartRequestItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepAP203_HArray1OfWorkItem.hxx
	py::class_<StepAP203_HArray1OfWorkItem, opencascade::handle<StepAP203_HArray1OfWorkItem>, StepAP203_Array1OfWorkItem, Standard_Transient> cls_StepAP203_HArray1OfWorkItem(mod, "StepAP203_HArray1OfWorkItem", "None");
	cls_StepAP203_HArray1OfWorkItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepAP203_HArray1OfWorkItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepAP203_Array1OfWorkItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepAP203_HArray1OfWorkItem.def(py::init<const StepAP203_Array1OfWorkItem &>(), py::arg("theOther"));
	cls_StepAP203_HArray1OfWorkItem.def("Array1", (const StepAP203_Array1OfWorkItem & (StepAP203_HArray1OfWorkItem::*)() const ) &StepAP203_HArray1OfWorkItem::Array1, "None");
	cls_StepAP203_HArray1OfWorkItem.def("ChangeArray1", (StepAP203_Array1OfWorkItem & (StepAP203_HArray1OfWorkItem::*)()) &StepAP203_HArray1OfWorkItem::ChangeArray1, "None");
	cls_StepAP203_HArray1OfWorkItem.def_static("get_type_name_", (const char * (*)()) &StepAP203_HArray1OfWorkItem::get_type_name, "None");
	cls_StepAP203_HArray1OfWorkItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP203_HArray1OfWorkItem::get_type_descriptor, "None");
	cls_StepAP203_HArray1OfWorkItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP203_HArray1OfWorkItem::*)() const ) &StepAP203_HArray1OfWorkItem::DynamicType, "None");


}
