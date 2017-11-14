#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Handle.hxx>
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepAP203_CcDesignApproval.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepAP203_RWCcDesignApproval.hxx>
#include <StepAP203_CcDesignCertification.hxx>
#include <RWStepAP203_RWCcDesignCertification.hxx>
#include <StepAP203_CcDesignContract.hxx>
#include <RWStepAP203_RWCcDesignContract.hxx>
#include <StepAP203_CcDesignDateAndTimeAssignment.hxx>
#include <RWStepAP203_RWCcDesignDateAndTimeAssignment.hxx>
#include <StepAP203_CcDesignPersonAndOrganizationAssignment.hxx>
#include <RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.hxx>
#include <StepAP203_CcDesignSecurityClassification.hxx>
#include <RWStepAP203_RWCcDesignSecurityClassification.hxx>
#include <StepAP203_CcDesignSpecificationReference.hxx>
#include <RWStepAP203_RWCcDesignSpecificationReference.hxx>
#include <StepAP203_Change.hxx>
#include <RWStepAP203_RWChange.hxx>
#include <StepAP203_ChangeRequest.hxx>
#include <RWStepAP203_RWChangeRequest.hxx>
#include <StepAP203_StartRequest.hxx>
#include <RWStepAP203_RWStartRequest.hxx>
#include <StepAP203_StartWork.hxx>
#include <RWStepAP203_RWStartWork.hxx>

PYBIND11_MODULE(RWStepAP203, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepData");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepAP203");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWCcDesignApproval.hxx
	py::class_<RWStepAP203_RWCcDesignApproval, std::unique_ptr<RWStepAP203_RWCcDesignApproval, Deleter<RWStepAP203_RWCcDesignApproval>>> cls_RWStepAP203_RWCcDesignApproval(mod, "RWStepAP203_RWCcDesignApproval", "Read & Write tool for CcDesignApproval");
	cls_RWStepAP203_RWCcDesignApproval.def(py::init<>());
	cls_RWStepAP203_RWCcDesignApproval.def("ReadStep", (void (RWStepAP203_RWCcDesignApproval::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignApproval> &) const ) &RWStepAP203_RWCcDesignApproval::ReadStep, "Reads CcDesignApproval", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignApproval.def("WriteStep", (void (RWStepAP203_RWCcDesignApproval::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignApproval> &) const ) &RWStepAP203_RWCcDesignApproval::WriteStep, "Writes CcDesignApproval", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignApproval.def("Share", (void (RWStepAP203_RWCcDesignApproval::*)(const opencascade::handle<StepAP203_CcDesignApproval> &, Interface_EntityIterator &) const ) &RWStepAP203_RWCcDesignApproval::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWCcDesignCertification.hxx
	py::class_<RWStepAP203_RWCcDesignCertification, std::unique_ptr<RWStepAP203_RWCcDesignCertification, Deleter<RWStepAP203_RWCcDesignCertification>>> cls_RWStepAP203_RWCcDesignCertification(mod, "RWStepAP203_RWCcDesignCertification", "Read & Write tool for CcDesignCertification");
	cls_RWStepAP203_RWCcDesignCertification.def(py::init<>());
	cls_RWStepAP203_RWCcDesignCertification.def("ReadStep", (void (RWStepAP203_RWCcDesignCertification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignCertification> &) const ) &RWStepAP203_RWCcDesignCertification::ReadStep, "Reads CcDesignCertification", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignCertification.def("WriteStep", (void (RWStepAP203_RWCcDesignCertification::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignCertification> &) const ) &RWStepAP203_RWCcDesignCertification::WriteStep, "Writes CcDesignCertification", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignCertification.def("Share", (void (RWStepAP203_RWCcDesignCertification::*)(const opencascade::handle<StepAP203_CcDesignCertification> &, Interface_EntityIterator &) const ) &RWStepAP203_RWCcDesignCertification::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWCcDesignContract.hxx
	py::class_<RWStepAP203_RWCcDesignContract, std::unique_ptr<RWStepAP203_RWCcDesignContract, Deleter<RWStepAP203_RWCcDesignContract>>> cls_RWStepAP203_RWCcDesignContract(mod, "RWStepAP203_RWCcDesignContract", "Read & Write tool for CcDesignContract");
	cls_RWStepAP203_RWCcDesignContract.def(py::init<>());
	cls_RWStepAP203_RWCcDesignContract.def("ReadStep", (void (RWStepAP203_RWCcDesignContract::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignContract> &) const ) &RWStepAP203_RWCcDesignContract::ReadStep, "Reads CcDesignContract", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignContract.def("WriteStep", (void (RWStepAP203_RWCcDesignContract::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignContract> &) const ) &RWStepAP203_RWCcDesignContract::WriteStep, "Writes CcDesignContract", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignContract.def("Share", (void (RWStepAP203_RWCcDesignContract::*)(const opencascade::handle<StepAP203_CcDesignContract> &, Interface_EntityIterator &) const ) &RWStepAP203_RWCcDesignContract::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWCcDesignDateAndTimeAssignment.hxx
	py::class_<RWStepAP203_RWCcDesignDateAndTimeAssignment, std::unique_ptr<RWStepAP203_RWCcDesignDateAndTimeAssignment, Deleter<RWStepAP203_RWCcDesignDateAndTimeAssignment>>> cls_RWStepAP203_RWCcDesignDateAndTimeAssignment(mod, "RWStepAP203_RWCcDesignDateAndTimeAssignment", "Read & Write tool for CcDesignDateAndTimeAssignment");
	cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def(py::init<>());
	cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def("ReadStep", (void (RWStepAP203_RWCcDesignDateAndTimeAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment> &) const ) &RWStepAP203_RWCcDesignDateAndTimeAssignment::ReadStep, "Reads CcDesignDateAndTimeAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def("WriteStep", (void (RWStepAP203_RWCcDesignDateAndTimeAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment> &) const ) &RWStepAP203_RWCcDesignDateAndTimeAssignment::WriteStep, "Writes CcDesignDateAndTimeAssignment", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def("Share", (void (RWStepAP203_RWCcDesignDateAndTimeAssignment::*)(const opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment> &, Interface_EntityIterator &) const ) &RWStepAP203_RWCcDesignDateAndTimeAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.hxx
	py::class_<RWStepAP203_RWCcDesignPersonAndOrganizationAssignment, std::unique_ptr<RWStepAP203_RWCcDesignPersonAndOrganizationAssignment, Deleter<RWStepAP203_RWCcDesignPersonAndOrganizationAssignment>>> cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment(mod, "RWStepAP203_RWCcDesignPersonAndOrganizationAssignment", "Read & Write tool for CcDesignPersonAndOrganizationAssignment");
	cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def(py::init<>());
	cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def("ReadStep", (void (RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> &) const ) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::ReadStep, "Reads CcDesignPersonAndOrganizationAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def("WriteStep", (void (RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> &) const ) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::WriteStep, "Writes CcDesignPersonAndOrganizationAssignment", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def("Share", (void (RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> &, Interface_EntityIterator &) const ) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWCcDesignSecurityClassification.hxx
	py::class_<RWStepAP203_RWCcDesignSecurityClassification, std::unique_ptr<RWStepAP203_RWCcDesignSecurityClassification, Deleter<RWStepAP203_RWCcDesignSecurityClassification>>> cls_RWStepAP203_RWCcDesignSecurityClassification(mod, "RWStepAP203_RWCcDesignSecurityClassification", "Read & Write tool for CcDesignSecurityClassification");
	cls_RWStepAP203_RWCcDesignSecurityClassification.def(py::init<>());
	cls_RWStepAP203_RWCcDesignSecurityClassification.def("ReadStep", (void (RWStepAP203_RWCcDesignSecurityClassification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignSecurityClassification> &) const ) &RWStepAP203_RWCcDesignSecurityClassification::ReadStep, "Reads CcDesignSecurityClassification", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignSecurityClassification.def("WriteStep", (void (RWStepAP203_RWCcDesignSecurityClassification::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignSecurityClassification> &) const ) &RWStepAP203_RWCcDesignSecurityClassification::WriteStep, "Writes CcDesignSecurityClassification", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignSecurityClassification.def("Share", (void (RWStepAP203_RWCcDesignSecurityClassification::*)(const opencascade::handle<StepAP203_CcDesignSecurityClassification> &, Interface_EntityIterator &) const ) &RWStepAP203_RWCcDesignSecurityClassification::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWCcDesignSpecificationReference.hxx
	py::class_<RWStepAP203_RWCcDesignSpecificationReference, std::unique_ptr<RWStepAP203_RWCcDesignSpecificationReference, Deleter<RWStepAP203_RWCcDesignSpecificationReference>>> cls_RWStepAP203_RWCcDesignSpecificationReference(mod, "RWStepAP203_RWCcDesignSpecificationReference", "Read & Write tool for CcDesignSpecificationReference");
	cls_RWStepAP203_RWCcDesignSpecificationReference.def(py::init<>());
	cls_RWStepAP203_RWCcDesignSpecificationReference.def("ReadStep", (void (RWStepAP203_RWCcDesignSpecificationReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignSpecificationReference> &) const ) &RWStepAP203_RWCcDesignSpecificationReference::ReadStep, "Reads CcDesignSpecificationReference", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignSpecificationReference.def("WriteStep", (void (RWStepAP203_RWCcDesignSpecificationReference::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignSpecificationReference> &) const ) &RWStepAP203_RWCcDesignSpecificationReference::WriteStep, "Writes CcDesignSpecificationReference", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWCcDesignSpecificationReference.def("Share", (void (RWStepAP203_RWCcDesignSpecificationReference::*)(const opencascade::handle<StepAP203_CcDesignSpecificationReference> &, Interface_EntityIterator &) const ) &RWStepAP203_RWCcDesignSpecificationReference::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWChange.hxx
	py::class_<RWStepAP203_RWChange, std::unique_ptr<RWStepAP203_RWChange, Deleter<RWStepAP203_RWChange>>> cls_RWStepAP203_RWChange(mod, "RWStepAP203_RWChange", "Read & Write tool for Change");
	cls_RWStepAP203_RWChange.def(py::init<>());
	cls_RWStepAP203_RWChange.def("ReadStep", (void (RWStepAP203_RWChange::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_Change> &) const ) &RWStepAP203_RWChange::ReadStep, "Reads Change", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWChange.def("WriteStep", (void (RWStepAP203_RWChange::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_Change> &) const ) &RWStepAP203_RWChange::WriteStep, "Writes Change", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWChange.def("Share", (void (RWStepAP203_RWChange::*)(const opencascade::handle<StepAP203_Change> &, Interface_EntityIterator &) const ) &RWStepAP203_RWChange::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWChangeRequest.hxx
	py::class_<RWStepAP203_RWChangeRequest, std::unique_ptr<RWStepAP203_RWChangeRequest, Deleter<RWStepAP203_RWChangeRequest>>> cls_RWStepAP203_RWChangeRequest(mod, "RWStepAP203_RWChangeRequest", "Read & Write tool for ChangeRequest");
	cls_RWStepAP203_RWChangeRequest.def(py::init<>());
	cls_RWStepAP203_RWChangeRequest.def("ReadStep", (void (RWStepAP203_RWChangeRequest::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_ChangeRequest> &) const ) &RWStepAP203_RWChangeRequest::ReadStep, "Reads ChangeRequest", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWChangeRequest.def("WriteStep", (void (RWStepAP203_RWChangeRequest::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_ChangeRequest> &) const ) &RWStepAP203_RWChangeRequest::WriteStep, "Writes ChangeRequest", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWChangeRequest.def("Share", (void (RWStepAP203_RWChangeRequest::*)(const opencascade::handle<StepAP203_ChangeRequest> &, Interface_EntityIterator &) const ) &RWStepAP203_RWChangeRequest::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWStartRequest.hxx
	py::class_<RWStepAP203_RWStartRequest, std::unique_ptr<RWStepAP203_RWStartRequest, Deleter<RWStepAP203_RWStartRequest>>> cls_RWStepAP203_RWStartRequest(mod, "RWStepAP203_RWStartRequest", "Read & Write tool for StartRequest");
	cls_RWStepAP203_RWStartRequest.def(py::init<>());
	cls_RWStepAP203_RWStartRequest.def("ReadStep", (void (RWStepAP203_RWStartRequest::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_StartRequest> &) const ) &RWStepAP203_RWStartRequest::ReadStep, "Reads StartRequest", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWStartRequest.def("WriteStep", (void (RWStepAP203_RWStartRequest::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_StartRequest> &) const ) &RWStepAP203_RWStartRequest::WriteStep, "Writes StartRequest", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWStartRequest.def("Share", (void (RWStepAP203_RWStartRequest::*)(const opencascade::handle<StepAP203_StartRequest> &, Interface_EntityIterator &) const ) &RWStepAP203_RWStartRequest::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\RWStepAP203_RWStartWork.hxx
	py::class_<RWStepAP203_RWStartWork, std::unique_ptr<RWStepAP203_RWStartWork, Deleter<RWStepAP203_RWStartWork>>> cls_RWStepAP203_RWStartWork(mod, "RWStepAP203_RWStartWork", "Read & Write tool for StartWork");
	cls_RWStepAP203_RWStartWork.def(py::init<>());
	cls_RWStepAP203_RWStartWork.def("ReadStep", (void (RWStepAP203_RWStartWork::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_StartWork> &) const ) &RWStepAP203_RWStartWork::ReadStep, "Reads StartWork", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
	cls_RWStepAP203_RWStartWork.def("WriteStep", (void (RWStepAP203_RWStartWork::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_StartWork> &) const ) &RWStepAP203_RWStartWork::WriteStep, "Writes StartWork", py::arg("SW"), py::arg("ent"));
	cls_RWStepAP203_RWStartWork.def("Share", (void (RWStepAP203_RWStartWork::*)(const opencascade::handle<StepAP203_StartWork> &, Interface_EntityIterator &) const ) &RWStepAP203_RWStartWork::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));


}
