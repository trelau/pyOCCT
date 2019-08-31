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

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepAP203");

// CLASS: RWSTEPAP203_RWCCDESIGNAPPROVAL
py::class_<RWStepAP203_RWCcDesignApproval> cls_RWStepAP203_RWCcDesignApproval(mod, "RWStepAP203_RWCcDesignApproval", "Read & Write tool for CcDesignApproval");

// Constructors
cls_RWStepAP203_RWCcDesignApproval.def(py::init<>());

// Methods
// cls_RWStepAP203_RWCcDesignApproval.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignApproval::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignApproval.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWCcDesignApproval::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignApproval.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignApproval::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignApproval.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWCcDesignApproval::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignApproval.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWCcDesignApproval::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignApproval.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWCcDesignApproval::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWCcDesignApproval.def("ReadStep", (void (RWStepAP203_RWCcDesignApproval::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignApproval> &) const) &RWStepAP203_RWCcDesignApproval::ReadStep, "Reads CcDesignApproval", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignApproval.def("WriteStep", (void (RWStepAP203_RWCcDesignApproval::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignApproval> &) const) &RWStepAP203_RWCcDesignApproval::WriteStep, "Writes CcDesignApproval", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignApproval.def("Share", (void (RWStepAP203_RWCcDesignApproval::*)(const opencascade::handle<StepAP203_CcDesignApproval> &, Interface_EntityIterator &) const) &RWStepAP203_RWCcDesignApproval::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWCCDESIGNCERTIFICATION
py::class_<RWStepAP203_RWCcDesignCertification> cls_RWStepAP203_RWCcDesignCertification(mod, "RWStepAP203_RWCcDesignCertification", "Read & Write tool for CcDesignCertification");

// Constructors
cls_RWStepAP203_RWCcDesignCertification.def(py::init<>());

// Methods
// cls_RWStepAP203_RWCcDesignCertification.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignCertification::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignCertification.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWCcDesignCertification::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignCertification.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignCertification::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignCertification.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWCcDesignCertification::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignCertification.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWCcDesignCertification::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignCertification.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWCcDesignCertification::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWCcDesignCertification.def("ReadStep", (void (RWStepAP203_RWCcDesignCertification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignCertification> &) const) &RWStepAP203_RWCcDesignCertification::ReadStep, "Reads CcDesignCertification", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignCertification.def("WriteStep", (void (RWStepAP203_RWCcDesignCertification::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignCertification> &) const) &RWStepAP203_RWCcDesignCertification::WriteStep, "Writes CcDesignCertification", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignCertification.def("Share", (void (RWStepAP203_RWCcDesignCertification::*)(const opencascade::handle<StepAP203_CcDesignCertification> &, Interface_EntityIterator &) const) &RWStepAP203_RWCcDesignCertification::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWCCDESIGNCONTRACT
py::class_<RWStepAP203_RWCcDesignContract> cls_RWStepAP203_RWCcDesignContract(mod, "RWStepAP203_RWCcDesignContract", "Read & Write tool for CcDesignContract");

// Constructors
cls_RWStepAP203_RWCcDesignContract.def(py::init<>());

// Methods
// cls_RWStepAP203_RWCcDesignContract.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignContract::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignContract.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWCcDesignContract::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignContract.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignContract::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignContract.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWCcDesignContract::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignContract.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWCcDesignContract::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignContract.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWCcDesignContract::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWCcDesignContract.def("ReadStep", (void (RWStepAP203_RWCcDesignContract::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignContract> &) const) &RWStepAP203_RWCcDesignContract::ReadStep, "Reads CcDesignContract", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignContract.def("WriteStep", (void (RWStepAP203_RWCcDesignContract::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignContract> &) const) &RWStepAP203_RWCcDesignContract::WriteStep, "Writes CcDesignContract", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignContract.def("Share", (void (RWStepAP203_RWCcDesignContract::*)(const opencascade::handle<StepAP203_CcDesignContract> &, Interface_EntityIterator &) const) &RWStepAP203_RWCcDesignContract::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWCCDESIGNDATEANDTIMEASSIGNMENT
py::class_<RWStepAP203_RWCcDesignDateAndTimeAssignment> cls_RWStepAP203_RWCcDesignDateAndTimeAssignment(mod, "RWStepAP203_RWCcDesignDateAndTimeAssignment", "Read & Write tool for CcDesignDateAndTimeAssignment");

// Constructors
cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def(py::init<>());

// Methods
// cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignDateAndTimeAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWCcDesignDateAndTimeAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignDateAndTimeAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWCcDesignDateAndTimeAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWCcDesignDateAndTimeAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWCcDesignDateAndTimeAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def("ReadStep", (void (RWStepAP203_RWCcDesignDateAndTimeAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment> &) const) &RWStepAP203_RWCcDesignDateAndTimeAssignment::ReadStep, "Reads CcDesignDateAndTimeAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def("WriteStep", (void (RWStepAP203_RWCcDesignDateAndTimeAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment> &) const) &RWStepAP203_RWCcDesignDateAndTimeAssignment::WriteStep, "Writes CcDesignDateAndTimeAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignDateAndTimeAssignment.def("Share", (void (RWStepAP203_RWCcDesignDateAndTimeAssignment::*)(const opencascade::handle<StepAP203_CcDesignDateAndTimeAssignment> &, Interface_EntityIterator &) const) &RWStepAP203_RWCcDesignDateAndTimeAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWCCDESIGNPERSONANDORGANIZATIONASSIGNMENT
py::class_<RWStepAP203_RWCcDesignPersonAndOrganizationAssignment> cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment(mod, "RWStepAP203_RWCcDesignPersonAndOrganizationAssignment", "Read & Write tool for CcDesignPersonAndOrganizationAssignment");

// Constructors
cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def(py::init<>());

// Methods
// cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def("ReadStep", (void (RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> &) const) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::ReadStep, "Reads CcDesignPersonAndOrganizationAssignment", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def("WriteStep", (void (RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> &) const) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::WriteStep, "Writes CcDesignPersonAndOrganizationAssignment", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment.def("Share", (void (RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::*)(const opencascade::handle<StepAP203_CcDesignPersonAndOrganizationAssignment> &, Interface_EntityIterator &) const) &RWStepAP203_RWCcDesignPersonAndOrganizationAssignment::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWCCDESIGNSECURITYCLASSIFICATION
py::class_<RWStepAP203_RWCcDesignSecurityClassification> cls_RWStepAP203_RWCcDesignSecurityClassification(mod, "RWStepAP203_RWCcDesignSecurityClassification", "Read & Write tool for CcDesignSecurityClassification");

// Constructors
cls_RWStepAP203_RWCcDesignSecurityClassification.def(py::init<>());

// Methods
// cls_RWStepAP203_RWCcDesignSecurityClassification.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignSecurityClassification::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignSecurityClassification.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWCcDesignSecurityClassification::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignSecurityClassification.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignSecurityClassification::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignSecurityClassification.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWCcDesignSecurityClassification::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignSecurityClassification.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWCcDesignSecurityClassification::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignSecurityClassification.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWCcDesignSecurityClassification::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWCcDesignSecurityClassification.def("ReadStep", (void (RWStepAP203_RWCcDesignSecurityClassification::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignSecurityClassification> &) const) &RWStepAP203_RWCcDesignSecurityClassification::ReadStep, "Reads CcDesignSecurityClassification", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignSecurityClassification.def("WriteStep", (void (RWStepAP203_RWCcDesignSecurityClassification::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignSecurityClassification> &) const) &RWStepAP203_RWCcDesignSecurityClassification::WriteStep, "Writes CcDesignSecurityClassification", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignSecurityClassification.def("Share", (void (RWStepAP203_RWCcDesignSecurityClassification::*)(const opencascade::handle<StepAP203_CcDesignSecurityClassification> &, Interface_EntityIterator &) const) &RWStepAP203_RWCcDesignSecurityClassification::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWCCDESIGNSPECIFICATIONREFERENCE
py::class_<RWStepAP203_RWCcDesignSpecificationReference> cls_RWStepAP203_RWCcDesignSpecificationReference(mod, "RWStepAP203_RWCcDesignSpecificationReference", "Read & Write tool for CcDesignSpecificationReference");

// Constructors
cls_RWStepAP203_RWCcDesignSpecificationReference.def(py::init<>());

// Methods
// cls_RWStepAP203_RWCcDesignSpecificationReference.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignSpecificationReference::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignSpecificationReference.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWCcDesignSpecificationReference::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignSpecificationReference.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWCcDesignSpecificationReference::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWCcDesignSpecificationReference.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWCcDesignSpecificationReference::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignSpecificationReference.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWCcDesignSpecificationReference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWCcDesignSpecificationReference.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWCcDesignSpecificationReference::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWCcDesignSpecificationReference.def("ReadStep", (void (RWStepAP203_RWCcDesignSpecificationReference::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_CcDesignSpecificationReference> &) const) &RWStepAP203_RWCcDesignSpecificationReference::ReadStep, "Reads CcDesignSpecificationReference", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignSpecificationReference.def("WriteStep", (void (RWStepAP203_RWCcDesignSpecificationReference::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_CcDesignSpecificationReference> &) const) &RWStepAP203_RWCcDesignSpecificationReference::WriteStep, "Writes CcDesignSpecificationReference", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWCcDesignSpecificationReference.def("Share", (void (RWStepAP203_RWCcDesignSpecificationReference::*)(const opencascade::handle<StepAP203_CcDesignSpecificationReference> &, Interface_EntityIterator &) const) &RWStepAP203_RWCcDesignSpecificationReference::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWCHANGE
py::class_<RWStepAP203_RWChange> cls_RWStepAP203_RWChange(mod, "RWStepAP203_RWChange", "Read & Write tool for Change");

// Constructors
cls_RWStepAP203_RWChange.def(py::init<>());

// Methods
// cls_RWStepAP203_RWChange.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWChange::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWChange.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWChange::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWChange.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWChange::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWChange.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWChange::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWChange.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWChange::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWChange.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWChange::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWChange.def("ReadStep", (void (RWStepAP203_RWChange::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_Change> &) const) &RWStepAP203_RWChange::ReadStep, "Reads Change", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWChange.def("WriteStep", (void (RWStepAP203_RWChange::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_Change> &) const) &RWStepAP203_RWChange::WriteStep, "Writes Change", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWChange.def("Share", (void (RWStepAP203_RWChange::*)(const opencascade::handle<StepAP203_Change> &, Interface_EntityIterator &) const) &RWStepAP203_RWChange::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWCHANGEREQUEST
py::class_<RWStepAP203_RWChangeRequest> cls_RWStepAP203_RWChangeRequest(mod, "RWStepAP203_RWChangeRequest", "Read & Write tool for ChangeRequest");

// Constructors
cls_RWStepAP203_RWChangeRequest.def(py::init<>());

// Methods
// cls_RWStepAP203_RWChangeRequest.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWChangeRequest::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWChangeRequest.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWChangeRequest::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWChangeRequest.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWChangeRequest::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWChangeRequest.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWChangeRequest::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWChangeRequest.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWChangeRequest::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWChangeRequest.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWChangeRequest::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWChangeRequest.def("ReadStep", (void (RWStepAP203_RWChangeRequest::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_ChangeRequest> &) const) &RWStepAP203_RWChangeRequest::ReadStep, "Reads ChangeRequest", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWChangeRequest.def("WriteStep", (void (RWStepAP203_RWChangeRequest::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_ChangeRequest> &) const) &RWStepAP203_RWChangeRequest::WriteStep, "Writes ChangeRequest", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWChangeRequest.def("Share", (void (RWStepAP203_RWChangeRequest::*)(const opencascade::handle<StepAP203_ChangeRequest> &, Interface_EntityIterator &) const) &RWStepAP203_RWChangeRequest::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWSTARTREQUEST
py::class_<RWStepAP203_RWStartRequest> cls_RWStepAP203_RWStartRequest(mod, "RWStepAP203_RWStartRequest", "Read & Write tool for StartRequest");

// Constructors
cls_RWStepAP203_RWStartRequest.def(py::init<>());

// Methods
// cls_RWStepAP203_RWStartRequest.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWStartRequest::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWStartRequest.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWStartRequest::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWStartRequest.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWStartRequest::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWStartRequest.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWStartRequest::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWStartRequest.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWStartRequest::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWStartRequest.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWStartRequest::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWStartRequest.def("ReadStep", (void (RWStepAP203_RWStartRequest::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_StartRequest> &) const) &RWStepAP203_RWStartRequest::ReadStep, "Reads StartRequest", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWStartRequest.def("WriteStep", (void (RWStepAP203_RWStartRequest::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_StartRequest> &) const) &RWStepAP203_RWStartRequest::WriteStep, "Writes StartRequest", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWStartRequest.def("Share", (void (RWStepAP203_RWStartRequest::*)(const opencascade::handle<StepAP203_StartRequest> &, Interface_EntityIterator &) const) &RWStepAP203_RWStartRequest::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));

// CLASS: RWSTEPAP203_RWSTARTWORK
py::class_<RWStepAP203_RWStartWork> cls_RWStepAP203_RWStartWork(mod, "RWStepAP203_RWStartWork", "Read & Write tool for StartWork");

// Constructors
cls_RWStepAP203_RWStartWork.def(py::init<>());

// Methods
// cls_RWStepAP203_RWStartWork.def_static("operator new_", (void * (*)(size_t)) &RWStepAP203_RWStartWork::operator new, "None", py::arg("theSize"));
// cls_RWStepAP203_RWStartWork.def_static("operator delete_", (void (*)(void *)) &RWStepAP203_RWStartWork::operator delete, "None", py::arg("theAddress"));
// cls_RWStepAP203_RWStartWork.def_static("operator new[]_", (void * (*)(size_t)) &RWStepAP203_RWStartWork::operator new[], "None", py::arg("theSize"));
// cls_RWStepAP203_RWStartWork.def_static("operator delete[]_", (void (*)(void *)) &RWStepAP203_RWStartWork::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepAP203_RWStartWork.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepAP203_RWStartWork::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepAP203_RWStartWork.def_static("operator delete_", (void (*)(void *, void *)) &RWStepAP203_RWStartWork::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepAP203_RWStartWork.def("ReadStep", (void (RWStepAP203_RWStartWork::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepAP203_StartWork> &) const) &RWStepAP203_RWStartWork::ReadStep, "Reads StartWork", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepAP203_RWStartWork.def("WriteStep", (void (RWStepAP203_RWStartWork::*)(StepData_StepWriter &, const opencascade::handle<StepAP203_StartWork> &) const) &RWStepAP203_RWStartWork::WriteStep, "Writes StartWork", py::arg("SW"), py::arg("ent"));
cls_RWStepAP203_RWStartWork.def("Share", (void (RWStepAP203_RWStartWork::*)(const opencascade::handle<StepAP203_StartWork> &, Interface_EntityIterator &) const) &RWStepAP203_RWStartWork::Share, "Fills data for graph (shared items)", py::arg("ent"), py::arg("iter"));


}
