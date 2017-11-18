#include <pyOCCT_Common.hpp>

#include <StepData_ReadWriteModule.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_Handle.hxx>
#include <StepData_StepReaderData.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <StepData_StepWriter.hxx>
#include <Standard_Type.hxx>
#include <RWStepAP214_ReadWriteModule.hxx>
#include <StepData_GeneralModule.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_HAsciiString.hxx>
#include <RWStepAP214_GeneralModule.hxx>
#include <StepAP214_AutoDesignActualDateAndTimeAssignment.hxx>
#include <RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.hxx>
#include <StepAP214_AutoDesignActualDateAssignment.hxx>
#include <RWStepAP214_RWAutoDesignActualDateAssignment.hxx>
#include <StepAP214_AutoDesignApprovalAssignment.hxx>
#include <RWStepAP214_RWAutoDesignApprovalAssignment.hxx>
#include <StepAP214_AutoDesignDateAndPersonAssignment.hxx>
#include <RWStepAP214_RWAutoDesignDateAndPersonAssignment.hxx>
#include <StepAP214_AutoDesignGroupAssignment.hxx>
#include <RWStepAP214_RWAutoDesignGroupAssignment.hxx>
#include <StepAP214_AutoDesignNominalDateAndTimeAssignment.hxx>
#include <RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.hxx>
#include <StepAP214_AutoDesignNominalDateAssignment.hxx>
#include <RWStepAP214_RWAutoDesignNominalDateAssignment.hxx>
#include <StepAP214_AutoDesignOrganizationAssignment.hxx>
#include <RWStepAP214_RWAutoDesignOrganizationAssignment.hxx>
#include <StepAP214_AutoDesignPersonAndOrganizationAssignment.hxx>
#include <RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AutoDesignPresentedItem.hxx>
#include <RWStepAP214_RWAutoDesignPresentedItem.hxx>
#include <StepAP214_AutoDesignSecurityClassificationAssignment.hxx>
#include <RWStepAP214_RWAutoDesignSecurityClassificationAssignment.hxx>
#include <StepAP214_AutoDesignDocumentReference.hxx>
#include <RWStepAP214_RWAutoDesignDocumentReference.hxx>
#include <StepAP214_AppliedDateAndTimeAssignment.hxx>
#include <RWStepAP214_RWAppliedDateAndTimeAssignment.hxx>
#include <StepAP214_AppliedDateAssignment.hxx>
#include <RWStepAP214_RWAppliedDateAssignment.hxx>
#include <StepAP214_AppliedApprovalAssignment.hxx>
#include <RWStepAP214_RWAppliedApprovalAssignment.hxx>
#include <StepAP214_AppliedGroupAssignment.hxx>
#include <RWStepAP214_RWAppliedGroupAssignment.hxx>
#include <StepAP214_AppliedOrganizationAssignment.hxx>
#include <RWStepAP214_RWAppliedOrganizationAssignment.hxx>
#include <StepAP214_AppliedPersonAndOrganizationAssignment.hxx>
#include <RWStepAP214_RWAppliedPersonAndOrganizationAssignment.hxx>
#include <StepAP214_AppliedPresentedItem.hxx>
#include <RWStepAP214_RWAppliedPresentedItem.hxx>
#include <StepAP214_AppliedSecurityClassificationAssignment.hxx>
#include <RWStepAP214_RWAppliedSecurityClassificationAssignment.hxx>
#include <StepAP214_AppliedDocumentReference.hxx>
#include <RWStepAP214_RWAppliedDocumentReference.hxx>
#include <StepAP214_AppliedExternalIdentificationAssignment.hxx>
#include <RWStepAP214_RWAppliedExternalIdentificationAssignment.hxx>
#include <StepAP214_Class.hxx>
#include <RWStepAP214_RWClass.hxx>
#include <StepAP214_ExternallyDefinedClass.hxx>
#include <RWStepAP214_RWExternallyDefinedClass.hxx>
#include <StepAP214_ExternallyDefinedGeneralProperty.hxx>
#include <RWStepAP214_RWExternallyDefinedGeneralProperty.hxx>
#include <StepAP214_RepItemGroup.hxx>
#include <RWStepAP214_RWRepItemGroup.hxx>
#include <RWStepAP214.hxx>

PYBIND11_MODULE(RWStepAP214, mod) {

	// IMPORT
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepAP214");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_ReadWriteModule.hxx
	py::class_<RWStepAP214_ReadWriteModule, opencascade::handle<RWStepAP214_ReadWriteModule>, StepData_ReadWriteModule> cls_RWStepAP214_ReadWriteModule(mod, "RWStepAP214_ReadWriteModule", "General module to read and write StepAP214 entities");
	cls_RWStepAP214_ReadWriteModule.def(py::init<>());
	cls_RWStepAP214_ReadWriteModule.def("CaseStep", (Standard_Integer (RWStepAP214_ReadWriteModule::*)(const TCollection_AsciiString &) const ) &RWStepAP214_ReadWriteModule::CaseStep, "associates a positive Case Number to each type of StepAP214 entity, given as a String defined in the EXPRESS form", py::arg("atype"));
	cls_RWStepAP214_ReadWriteModule.def("CaseStep", (Standard_Integer (RWStepAP214_ReadWriteModule::*)(const TColStd_SequenceOfAsciiString &) const ) &RWStepAP214_ReadWriteModule::CaseStep, "associates a positive Case Number to each type of StepAP214 Complex entity, given as a String defined in the EXPRESS form", py::arg("types"));
	cls_RWStepAP214_ReadWriteModule.def("IsComplex", (Standard_Boolean (RWStepAP214_ReadWriteModule::*)(const Standard_Integer) const ) &RWStepAP214_ReadWriteModule::IsComplex, "returns True if the Case Number corresponds to a Complex Type", py::arg("CN"));
	cls_RWStepAP214_ReadWriteModule.def("StepType", (const TCollection_AsciiString & (RWStepAP214_ReadWriteModule::*)(const Standard_Integer) const ) &RWStepAP214_ReadWriteModule::StepType, "returns a StepType (defined in EXPRESS form which belongs to a Type of Entity, identified by its CaseNumber determined by Protocol", py::arg("CN"));
	cls_RWStepAP214_ReadWriteModule.def("ComplexType", (Standard_Boolean (RWStepAP214_ReadWriteModule::*)(const Standard_Integer, TColStd_SequenceOfAsciiString &) const ) &RWStepAP214_ReadWriteModule::ComplexType, "None", py::arg("CN"), py::arg("types"));
	cls_RWStepAP214_ReadWriteModule.def("ReadStep", (void (RWStepAP214_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const ) &RWStepAP214_ReadWriteModule::ReadStep, "None", py::arg("CN"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_ReadWriteModule.def("WriteStep", (void (RWStepAP214_ReadWriteModule::*)(const Standard_Integer, StepData_StepWriter &, const opencascade::handle<Standard_Transient> &) const ) &RWStepAP214_ReadWriteModule::WriteStep, "None", py::arg("CN"), py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &RWStepAP214_ReadWriteModule::get_type_name, "None");
	cls_RWStepAP214_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWStepAP214_ReadWriteModule::get_type_descriptor, "None");
	cls_RWStepAP214_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWStepAP214_ReadWriteModule::*)() const ) &RWStepAP214_ReadWriteModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_GeneralModule.hxx
	py::class_<RWStepAP214_GeneralModule, opencascade::handle<RWStepAP214_GeneralModule>, StepData_GeneralModule> cls_RWStepAP214_GeneralModule(mod, "RWStepAP214_GeneralModule", "Defines General Services for StepAP214 Entities (Share,Check,Copy; Trace already inherited) Depends (for case numbers) of Protocol from StepAP214");
	cls_RWStepAP214_GeneralModule.def(py::init<>());
	cls_RWStepAP214_GeneralModule.def("FillSharedCase", (void (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const ) &RWStepAP214_GeneralModule::FillSharedCase, "Specific filling of the list of Entities shared by an Entity <ent>, according to a Case Number <CN> (provided by StepAP214 Protocol).", py::arg("CN"), py::arg("ent"), py::arg("iter"));
	cls_RWStepAP214_GeneralModule.def("CheckCase", (void (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &RWStepAP214_GeneralModule::CheckCase, "Specific Checking of an Entity <ent>", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_RWStepAP214_GeneralModule.def("CopyCase", (void (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const ) &RWStepAP214_GeneralModule::CopyCase, "Specific Copy ('Deep') from <entfrom> to <entto> (same type) by using a CopyTool which provides its working Map. Use method Transferred from CopyTool to work", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_RWStepAP214_GeneralModule.def("NewVoid", (Standard_Boolean (RWStepAP214_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const ) &RWStepAP214_GeneralModule::NewVoid, "None", py::arg("CN"), py::arg("ent"));
	cls_RWStepAP214_GeneralModule.def("CategoryNumber", (Standard_Integer (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const ) &RWStepAP214_GeneralModule::CategoryNumber, "None", py::arg("CN"), py::arg("ent"), py::arg("shares"));
	cls_RWStepAP214_GeneralModule.def("Name", (opencascade::handle<TCollection_HAsciiString> (RWStepAP214_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const ) &RWStepAP214_GeneralModule::Name, "Returns the name of a STEP Entity according to its type", py::arg("CN"), py::arg("ent"), py::arg("shares"));
	cls_RWStepAP214_GeneralModule.def_static("get_type_name_", (const char * (*)()) &RWStepAP214_GeneralModule::get_type_name, "None");
	cls_RWStepAP214_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &RWStepAP214_GeneralModule::get_type_descriptor, "None");
	cls_RWStepAP214_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (RWStepAP214_GeneralModule::*)() const ) &RWStepAP214_GeneralModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignActualDateAndTimeAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignActualDateAndTimeAssignment, Deleter<RWStepAP214_RWAutoDesignActualDateAndTimeAssignment>>> cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment(mod, "RWStepAP214_RWAutoDesignActualDateAndTimeAssignment", "Read & Write Module for AutoDesignActualDateAndTimeAssignment");
	cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignActualDateAndTimeAssignment> &) const ) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignActualDateAndTimeAssignment> &) const ) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment.def("Share", (void (RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_AutoDesignActualDateAndTimeAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignActualDateAndTimeAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignActualDateAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignActualDateAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignActualDateAssignment, Deleter<RWStepAP214_RWAutoDesignActualDateAssignment>>> cls_RWStepAP214_RWAutoDesignActualDateAssignment(mod, "RWStepAP214_RWAutoDesignActualDateAssignment", "Read & Write Module for AutoDesignActualDateAssignment");
	cls_RWStepAP214_RWAutoDesignActualDateAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignActualDateAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignActualDateAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignActualDateAssignment> &) const ) &RWStepAP214_RWAutoDesignActualDateAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignActualDateAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignActualDateAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignActualDateAssignment> &) const ) &RWStepAP214_RWAutoDesignActualDateAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignActualDateAssignment.def("Share", (void (RWStepAP214_RWAutoDesignActualDateAssignment::*)(const opencascade::handle<StepAP214_AutoDesignActualDateAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignActualDateAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignApprovalAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignApprovalAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignApprovalAssignment, Deleter<RWStepAP214_RWAutoDesignApprovalAssignment>>> cls_RWStepAP214_RWAutoDesignApprovalAssignment(mod, "RWStepAP214_RWAutoDesignApprovalAssignment", "Read & Write Module for AutoDesignApprovalAssignment");
	cls_RWStepAP214_RWAutoDesignApprovalAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignApprovalAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignApprovalAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignApprovalAssignment> &) const ) &RWStepAP214_RWAutoDesignApprovalAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignApprovalAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignApprovalAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignApprovalAssignment> &) const ) &RWStepAP214_RWAutoDesignApprovalAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignApprovalAssignment.def("Share", (void (RWStepAP214_RWAutoDesignApprovalAssignment::*)(const opencascade::handle<StepAP214_AutoDesignApprovalAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignApprovalAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignDateAndPersonAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignDateAndPersonAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignDateAndPersonAssignment, Deleter<RWStepAP214_RWAutoDesignDateAndPersonAssignment>>> cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment(mod, "RWStepAP214_RWAutoDesignDateAndPersonAssignment", "Read & Write Module for AutoDesignDateAndPersonAssignment");
	cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignDateAndPersonAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment> &) const ) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignDateAndPersonAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment> &) const ) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignDateAndPersonAssignment.def("Share", (void (RWStepAP214_RWAutoDesignDateAndPersonAssignment::*)(const opencascade::handle<StepAP214_AutoDesignDateAndPersonAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignDateAndPersonAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignGroupAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignGroupAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignGroupAssignment, Deleter<RWStepAP214_RWAutoDesignGroupAssignment>>> cls_RWStepAP214_RWAutoDesignGroupAssignment(mod, "RWStepAP214_RWAutoDesignGroupAssignment", "Read & Write Module for AutoDesignGroupAssignment");
	cls_RWStepAP214_RWAutoDesignGroupAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignGroupAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignGroupAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignGroupAssignment> &) const ) &RWStepAP214_RWAutoDesignGroupAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignGroupAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignGroupAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignGroupAssignment> &) const ) &RWStepAP214_RWAutoDesignGroupAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignGroupAssignment.def("Share", (void (RWStepAP214_RWAutoDesignGroupAssignment::*)(const opencascade::handle<StepAP214_AutoDesignGroupAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignGroupAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment, Deleter<RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment>>> cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment(mod, "RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment", "Read & Write Module for AutoDesignNominalDateAndTimeAssignment");
	cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignNominalDateAndTimeAssignment> &) const ) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignNominalDateAndTimeAssignment> &) const ) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment.def("Share", (void (RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_AutoDesignNominalDateAndTimeAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignNominalDateAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignNominalDateAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignNominalDateAssignment, Deleter<RWStepAP214_RWAutoDesignNominalDateAssignment>>> cls_RWStepAP214_RWAutoDesignNominalDateAssignment(mod, "RWStepAP214_RWAutoDesignNominalDateAssignment", "Read & Write Module for AutoDesignNominalDateAssignment");
	cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignNominalDateAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignNominalDateAssignment> &) const ) &RWStepAP214_RWAutoDesignNominalDateAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignNominalDateAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignNominalDateAssignment> &) const ) &RWStepAP214_RWAutoDesignNominalDateAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignNominalDateAssignment.def("Share", (void (RWStepAP214_RWAutoDesignNominalDateAssignment::*)(const opencascade::handle<StepAP214_AutoDesignNominalDateAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignNominalDateAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignOrganizationAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignOrganizationAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignOrganizationAssignment, Deleter<RWStepAP214_RWAutoDesignOrganizationAssignment>>> cls_RWStepAP214_RWAutoDesignOrganizationAssignment(mod, "RWStepAP214_RWAutoDesignOrganizationAssignment", "Read & Write Module for AutoDesignOrganizationAssignment");
	cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignOrganizationAssignment> &) const ) &RWStepAP214_RWAutoDesignOrganizationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignOrganizationAssignment> &) const ) &RWStepAP214_RWAutoDesignOrganizationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignOrganizationAssignment.def("Share", (void (RWStepAP214_RWAutoDesignOrganizationAssignment::*)(const opencascade::handle<StepAP214_AutoDesignOrganizationAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignOrganizationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment, Deleter<RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment>>> cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment(mod, "RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment", "Read & Write Module for AutoDesignPersonAndOrganizationAssignment");
	cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignPersonAndOrganizationAssignment> &) const ) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignPersonAndOrganizationAssignment> &) const ) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment.def("Share", (void (RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP214_AutoDesignPersonAndOrganizationAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignPresentedItem.hxx
	py::class_<RWStepAP214_RWAutoDesignPresentedItem, std::unique_ptr<RWStepAP214_RWAutoDesignPresentedItem, Deleter<RWStepAP214_RWAutoDesignPresentedItem>>> cls_RWStepAP214_RWAutoDesignPresentedItem(mod, "RWStepAP214_RWAutoDesignPresentedItem", "Read & Write Module for AutoDesignPresentedItem");
	cls_RWStepAP214_RWAutoDesignPresentedItem.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignPresentedItem.def("ReadStep", (void (RWStepAP214_RWAutoDesignPresentedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignPresentedItem> &) const ) &RWStepAP214_RWAutoDesignPresentedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignPresentedItem.def("WriteStep", (void (RWStepAP214_RWAutoDesignPresentedItem::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignPresentedItem> &) const ) &RWStepAP214_RWAutoDesignPresentedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignPresentedItem.def("Share", (void (RWStepAP214_RWAutoDesignPresentedItem::*)(const opencascade::handle<StepAP214_AutoDesignPresentedItem> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignPresentedItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignSecurityClassificationAssignment.hxx
	py::class_<RWStepAP214_RWAutoDesignSecurityClassificationAssignment, std::unique_ptr<RWStepAP214_RWAutoDesignSecurityClassificationAssignment, Deleter<RWStepAP214_RWAutoDesignSecurityClassificationAssignment>>> cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment(mod, "RWStepAP214_RWAutoDesignSecurityClassificationAssignment", "Read & Write Module for AutoDesignSecurityClassificationAssignment");
	cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def("ReadStep", (void (RWStepAP214_RWAutoDesignSecurityClassificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignSecurityClassificationAssignment> &) const ) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def("WriteStep", (void (RWStepAP214_RWAutoDesignSecurityClassificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignSecurityClassificationAssignment> &) const ) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignSecurityClassificationAssignment.def("Share", (void (RWStepAP214_RWAutoDesignSecurityClassificationAssignment::*)(const opencascade::handle<StepAP214_AutoDesignSecurityClassificationAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignSecurityClassificationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAutoDesignDocumentReference.hxx
	py::class_<RWStepAP214_RWAutoDesignDocumentReference, std::unique_ptr<RWStepAP214_RWAutoDesignDocumentReference, Deleter<RWStepAP214_RWAutoDesignDocumentReference>>> cls_RWStepAP214_RWAutoDesignDocumentReference(mod, "RWStepAP214_RWAutoDesignDocumentReference", "Read & Write Module for AutoDesignDocumentReference");
	cls_RWStepAP214_RWAutoDesignDocumentReference.def(py::init<>());
	cls_RWStepAP214_RWAutoDesignDocumentReference.def("ReadStep", (void (RWStepAP214_RWAutoDesignDocumentReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AutoDesignDocumentReference> &) const ) &RWStepAP214_RWAutoDesignDocumentReference::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignDocumentReference.def("WriteStep", (void (RWStepAP214_RWAutoDesignDocumentReference::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AutoDesignDocumentReference> &) const ) &RWStepAP214_RWAutoDesignDocumentReference::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAutoDesignDocumentReference.def("Share", (void (RWStepAP214_RWAutoDesignDocumentReference::*)(const opencascade::handle<StepAP214_AutoDesignDocumentReference> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAutoDesignDocumentReference::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedDateAndTimeAssignment.hxx
	py::class_<RWStepAP214_RWAppliedDateAndTimeAssignment, std::unique_ptr<RWStepAP214_RWAppliedDateAndTimeAssignment, Deleter<RWStepAP214_RWAppliedDateAndTimeAssignment>>> cls_RWStepAP214_RWAppliedDateAndTimeAssignment(mod, "RWStepAP214_RWAppliedDateAndTimeAssignment", "Read & Write Module for AppliedDateAndTimeAssignment");
	cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def(py::init<>());
	cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedDateAndTimeAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> &) const ) &RWStepAP214_RWAppliedDateAndTimeAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedDateAndTimeAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> &) const ) &RWStepAP214_RWAppliedDateAndTimeAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedDateAndTimeAssignment.def("Share", (void (RWStepAP214_RWAppliedDateAndTimeAssignment::*)(const opencascade::handle<StepAP214_AppliedDateAndTimeAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedDateAndTimeAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedDateAssignment.hxx
	py::class_<RWStepAP214_RWAppliedDateAssignment, std::unique_ptr<RWStepAP214_RWAppliedDateAssignment, Deleter<RWStepAP214_RWAppliedDateAssignment>>> cls_RWStepAP214_RWAppliedDateAssignment(mod, "RWStepAP214_RWAppliedDateAssignment", "Read & Write Module for AppliedDateAssignment");
	cls_RWStepAP214_RWAppliedDateAssignment.def(py::init<>());
	cls_RWStepAP214_RWAppliedDateAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedDateAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedDateAssignment> &) const ) &RWStepAP214_RWAppliedDateAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedDateAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedDateAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedDateAssignment> &) const ) &RWStepAP214_RWAppliedDateAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedDateAssignment.def("Share", (void (RWStepAP214_RWAppliedDateAssignment::*)(const opencascade::handle<StepAP214_AppliedDateAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedDateAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedApprovalAssignment.hxx
	py::class_<RWStepAP214_RWAppliedApprovalAssignment, std::unique_ptr<RWStepAP214_RWAppliedApprovalAssignment, Deleter<RWStepAP214_RWAppliedApprovalAssignment>>> cls_RWStepAP214_RWAppliedApprovalAssignment(mod, "RWStepAP214_RWAppliedApprovalAssignment", "Read & Write Module for AppliedApprovalAssignment");
	cls_RWStepAP214_RWAppliedApprovalAssignment.def(py::init<>());
	cls_RWStepAP214_RWAppliedApprovalAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedApprovalAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedApprovalAssignment> &) const ) &RWStepAP214_RWAppliedApprovalAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedApprovalAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedApprovalAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedApprovalAssignment> &) const ) &RWStepAP214_RWAppliedApprovalAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedApprovalAssignment.def("Share", (void (RWStepAP214_RWAppliedApprovalAssignment::*)(const opencascade::handle<StepAP214_AppliedApprovalAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedApprovalAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedGroupAssignment.hxx
	py::class_<RWStepAP214_RWAppliedGroupAssignment, std::unique_ptr<RWStepAP214_RWAppliedGroupAssignment, Deleter<RWStepAP214_RWAppliedGroupAssignment>>> cls_RWStepAP214_RWAppliedGroupAssignment(mod, "RWStepAP214_RWAppliedGroupAssignment", "Read & Write tool for AppliedGroupAssignment");
	cls_RWStepAP214_RWAppliedGroupAssignment.def(py::init<>());
	cls_RWStepAP214_RWAppliedGroupAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedGroupAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedGroupAssignment> &) const ) &RWStepAP214_RWAppliedGroupAssignment::ReadStep, "Reads AppliedGroupAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedGroupAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedGroupAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedGroupAssignment> &) const ) &RWStepAP214_RWAppliedGroupAssignment::WriteStep, "Writes AppliedGroupAssignment", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedGroupAssignment.def("Share", (void (RWStepAP214_RWAppliedGroupAssignment::*)(const opencascade::handle<StepAP214_AppliedGroupAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedGroupAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedOrganizationAssignment.hxx
	py::class_<RWStepAP214_RWAppliedOrganizationAssignment, std::unique_ptr<RWStepAP214_RWAppliedOrganizationAssignment, Deleter<RWStepAP214_RWAppliedOrganizationAssignment>>> cls_RWStepAP214_RWAppliedOrganizationAssignment(mod, "RWStepAP214_RWAppliedOrganizationAssignment", "Read & Write Module for AppliedOrganizationAssignment");
	cls_RWStepAP214_RWAppliedOrganizationAssignment.def(py::init<>());
	cls_RWStepAP214_RWAppliedOrganizationAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedOrganizationAssignment> &) const ) &RWStepAP214_RWAppliedOrganizationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedOrganizationAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedOrganizationAssignment> &) const ) &RWStepAP214_RWAppliedOrganizationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedOrganizationAssignment.def("Share", (void (RWStepAP214_RWAppliedOrganizationAssignment::*)(const opencascade::handle<StepAP214_AppliedOrganizationAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedOrganizationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedPersonAndOrganizationAssignment.hxx
	py::class_<RWStepAP214_RWAppliedPersonAndOrganizationAssignment, std::unique_ptr<RWStepAP214_RWAppliedPersonAndOrganizationAssignment, Deleter<RWStepAP214_RWAppliedPersonAndOrganizationAssignment>>> cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment(mod, "RWStepAP214_RWAppliedPersonAndOrganizationAssignment", "Read & Write Module for AppliedPersonAndOrganizationAssignment");
	cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def(py::init<>());
	cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedPersonAndOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> &) const ) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedPersonAndOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> &) const ) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedPersonAndOrganizationAssignment.def("Share", (void (RWStepAP214_RWAppliedPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP214_AppliedPersonAndOrganizationAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedPersonAndOrganizationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedPresentedItem.hxx
	py::class_<RWStepAP214_RWAppliedPresentedItem, std::unique_ptr<RWStepAP214_RWAppliedPresentedItem, Deleter<RWStepAP214_RWAppliedPresentedItem>>> cls_RWStepAP214_RWAppliedPresentedItem(mod, "RWStepAP214_RWAppliedPresentedItem", "Read & Write Module for AppliedPresentedItem");
	cls_RWStepAP214_RWAppliedPresentedItem.def(py::init<>());
	cls_RWStepAP214_RWAppliedPresentedItem.def("ReadStep", (void (RWStepAP214_RWAppliedPresentedItem::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedPresentedItem> &) const ) &RWStepAP214_RWAppliedPresentedItem::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedPresentedItem.def("WriteStep", (void (RWStepAP214_RWAppliedPresentedItem::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedPresentedItem> &) const ) &RWStepAP214_RWAppliedPresentedItem::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedPresentedItem.def("Share", (void (RWStepAP214_RWAppliedPresentedItem::*)(const opencascade::handle<StepAP214_AppliedPresentedItem> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedPresentedItem::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedSecurityClassificationAssignment.hxx
	py::class_<RWStepAP214_RWAppliedSecurityClassificationAssignment, std::unique_ptr<RWStepAP214_RWAppliedSecurityClassificationAssignment, Deleter<RWStepAP214_RWAppliedSecurityClassificationAssignment>>> cls_RWStepAP214_RWAppliedSecurityClassificationAssignment(mod, "RWStepAP214_RWAppliedSecurityClassificationAssignment", "None");
	cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def(py::init<>());
	cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedSecurityClassificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> &) const ) &RWStepAP214_RWAppliedSecurityClassificationAssignment::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedSecurityClassificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> &) const ) &RWStepAP214_RWAppliedSecurityClassificationAssignment::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedSecurityClassificationAssignment.def("Share", (void (RWStepAP214_RWAppliedSecurityClassificationAssignment::*)(const opencascade::handle<StepAP214_AppliedSecurityClassificationAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedSecurityClassificationAssignment::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedDocumentReference.hxx
	py::class_<RWStepAP214_RWAppliedDocumentReference, std::unique_ptr<RWStepAP214_RWAppliedDocumentReference, Deleter<RWStepAP214_RWAppliedDocumentReference>>> cls_RWStepAP214_RWAppliedDocumentReference(mod, "RWStepAP214_RWAppliedDocumentReference", "Read & Write Module for AppliedDocumentReference");
	cls_RWStepAP214_RWAppliedDocumentReference.def(py::init<>());
	cls_RWStepAP214_RWAppliedDocumentReference.def("ReadStep", (void (RWStepAP214_RWAppliedDocumentReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedDocumentReference> &) const ) &RWStepAP214_RWAppliedDocumentReference::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedDocumentReference.def("WriteStep", (void (RWStepAP214_RWAppliedDocumentReference::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedDocumentReference> &) const ) &RWStepAP214_RWAppliedDocumentReference::WriteStep, "None", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedDocumentReference.def("Share", (void (RWStepAP214_RWAppliedDocumentReference::*)(const opencascade::handle<StepAP214_AppliedDocumentReference> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedDocumentReference::Share, "None", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWAppliedExternalIdentificationAssignment.hxx
	py::class_<RWStepAP214_RWAppliedExternalIdentificationAssignment, std::unique_ptr<RWStepAP214_RWAppliedExternalIdentificationAssignment, Deleter<RWStepAP214_RWAppliedExternalIdentificationAssignment>>> cls_RWStepAP214_RWAppliedExternalIdentificationAssignment(mod, "RWStepAP214_RWAppliedExternalIdentificationAssignment", "Read & Write tool for AppliedExternalIdentificationAssignment");
	cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def(py::init<>());
	cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def("ReadStep", (void (RWStepAP214_RWAppliedExternalIdentificationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment> &) const ) &RWStepAP214_RWAppliedExternalIdentificationAssignment::ReadStep, "Reads AppliedExternalIdentificationAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def("WriteStep", (void (RWStepAP214_RWAppliedExternalIdentificationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment> &) const ) &RWStepAP214_RWAppliedExternalIdentificationAssignment::WriteStep, "Writes AppliedExternalIdentificationAssignment", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWAppliedExternalIdentificationAssignment.def("Share", (void (RWStepAP214_RWAppliedExternalIdentificationAssignment::*)(const opencascade::handle<StepAP214_AppliedExternalIdentificationAssignment> &, Interface_EntityIterator &) const ) &RWStepAP214_RWAppliedExternalIdentificationAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWClass.hxx
	py::class_<RWStepAP214_RWClass, std::unique_ptr<RWStepAP214_RWClass, Deleter<RWStepAP214_RWClass>>> cls_RWStepAP214_RWClass(mod, "RWStepAP214_RWClass", "Read & Write tool for Class");
	cls_RWStepAP214_RWClass.def(py::init<>());
	cls_RWStepAP214_RWClass.def("ReadStep", (void (RWStepAP214_RWClass::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_Class> &) const ) &RWStepAP214_RWClass::ReadStep, "Reads Class", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWClass.def("WriteStep", (void (RWStepAP214_RWClass::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_Class> &) const ) &RWStepAP214_RWClass::WriteStep, "Writes Class", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWClass.def("Share", (void (RWStepAP214_RWClass::*)(const opencascade::handle<StepAP214_Class> &, Interface_EntityIterator &) const ) &RWStepAP214_RWClass::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWExternallyDefinedClass.hxx
	py::class_<RWStepAP214_RWExternallyDefinedClass, std::unique_ptr<RWStepAP214_RWExternallyDefinedClass, Deleter<RWStepAP214_RWExternallyDefinedClass>>> cls_RWStepAP214_RWExternallyDefinedClass(mod, "RWStepAP214_RWExternallyDefinedClass", "Read & Write tool for ExternallyDefinedClass");
	cls_RWStepAP214_RWExternallyDefinedClass.def(py::init<>());
	cls_RWStepAP214_RWExternallyDefinedClass.def("ReadStep", (void (RWStepAP214_RWExternallyDefinedClass::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_ExternallyDefinedClass> &) const ) &RWStepAP214_RWExternallyDefinedClass::ReadStep, "Reads ExternallyDefinedClass", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWExternallyDefinedClass.def("WriteStep", (void (RWStepAP214_RWExternallyDefinedClass::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_ExternallyDefinedClass> &) const ) &RWStepAP214_RWExternallyDefinedClass::WriteStep, "Writes ExternallyDefinedClass", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWExternallyDefinedClass.def("Share", (void (RWStepAP214_RWExternallyDefinedClass::*)(const opencascade::handle<StepAP214_ExternallyDefinedClass> &, Interface_EntityIterator &) const ) &RWStepAP214_RWExternallyDefinedClass::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWExternallyDefinedGeneralProperty.hxx
	py::class_<RWStepAP214_RWExternallyDefinedGeneralProperty, std::unique_ptr<RWStepAP214_RWExternallyDefinedGeneralProperty, Deleter<RWStepAP214_RWExternallyDefinedGeneralProperty>>> cls_RWStepAP214_RWExternallyDefinedGeneralProperty(mod, "RWStepAP214_RWExternallyDefinedGeneralProperty", "Read & Write tool for ExternallyDefinedGeneralProperty");
	cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def(py::init<>());
	cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def("ReadStep", (void (RWStepAP214_RWExternallyDefinedGeneralProperty::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty> &) const ) &RWStepAP214_RWExternallyDefinedGeneralProperty::ReadStep, "Reads ExternallyDefinedGeneralProperty", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def("WriteStep", (void (RWStepAP214_RWExternallyDefinedGeneralProperty::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty> &) const ) &RWStepAP214_RWExternallyDefinedGeneralProperty::WriteStep, "Writes ExternallyDefinedGeneralProperty", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWExternallyDefinedGeneralProperty.def("Share", (void (RWStepAP214_RWExternallyDefinedGeneralProperty::*)(const opencascade::handle<StepAP214_ExternallyDefinedGeneralProperty> &, Interface_EntityIterator &) const ) &RWStepAP214_RWExternallyDefinedGeneralProperty::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214_RWRepItemGroup.hxx
	py::class_<RWStepAP214_RWRepItemGroup, std::unique_ptr<RWStepAP214_RWRepItemGroup, Deleter<RWStepAP214_RWRepItemGroup>>> cls_RWStepAP214_RWRepItemGroup(mod, "RWStepAP214_RWRepItemGroup", "Read & Write tool for RepItemGroup");
	cls_RWStepAP214_RWRepItemGroup.def(py::init<>());
	cls_RWStepAP214_RWRepItemGroup.def("ReadStep", (void (RWStepAP214_RWRepItemGroup::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP214_RepItemGroup> &) const ) &RWStepAP214_RWRepItemGroup::ReadStep, "Reads RepItemGroup", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP214_RWRepItemGroup.def("WriteStep", (void (RWStepAP214_RWRepItemGroup::*)(StepData_StepWriter &, const opencascade::handle<StepAP214_RepItemGroup> &) const ) &RWStepAP214_RWRepItemGroup::WriteStep, "Writes RepItemGroup", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP214_RWRepItemGroup.def("Share", (void (RWStepAP214_RWRepItemGroup::*)(const opencascade::handle<StepAP214_RepItemGroup> &, Interface_EntityIterator &) const ) &RWStepAP214_RWRepItemGroup::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP214.hxx
	py::class_<RWStepAP214, std::unique_ptr<RWStepAP214, Deleter<RWStepAP214>>> cls_RWStepAP214(mod, "RWStepAP214", "None");
	cls_RWStepAP214.def(py::init<>());
	cls_RWStepAP214.def_static("Init_", (void (*)()) &RWStepAP214::Init, "enforced the initialisation of the libraries");


}
