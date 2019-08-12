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

void bind_StepAP203_ApprovedItem(py::module &);
void bind_StepAP203_Array1OfApprovedItem(py::module &);
void bind_StepAP203_CertifiedItem(py::module &);
void bind_StepAP203_Array1OfCertifiedItem(py::module &);
void bind_StepAP203_ChangeRequestItem(py::module &);
void bind_StepAP203_Array1OfChangeRequestItem(py::module &);
void bind_StepAP203_ClassifiedItem(py::module &);
void bind_StepAP203_Array1OfClassifiedItem(py::module &);
void bind_StepAP203_ContractedItem(py::module &);
void bind_StepAP203_Array1OfContractedItem(py::module &);
void bind_StepAP203_DateTimeItem(py::module &);
void bind_StepAP203_Array1OfDateTimeItem(py::module &);
void bind_StepAP203_PersonOrganizationItem(py::module &);
void bind_StepAP203_Array1OfPersonOrganizationItem(py::module &);
void bind_StepAP203_SpecifiedItem(py::module &);
void bind_StepAP203_Array1OfSpecifiedItem(py::module &);
void bind_StepAP203_StartRequestItem(py::module &);
void bind_StepAP203_Array1OfStartRequestItem(py::module &);
void bind_StepAP203_WorkItem(py::module &);
void bind_StepAP203_Array1OfWorkItem(py::module &);
void bind_StepAP203_HArray1OfApprovedItem(py::module &);
void bind_StepAP203_CcDesignApproval(py::module &);
void bind_StepAP203_HArray1OfCertifiedItem(py::module &);
void bind_StepAP203_CcDesignCertification(py::module &);
void bind_StepAP203_HArray1OfContractedItem(py::module &);
void bind_StepAP203_CcDesignContract(py::module &);
void bind_StepAP203_HArray1OfDateTimeItem(py::module &);
void bind_StepAP203_CcDesignDateAndTimeAssignment(py::module &);
void bind_StepAP203_HArray1OfPersonOrganizationItem(py::module &);
void bind_StepAP203_CcDesignPersonAndOrganizationAssignment(py::module &);
void bind_StepAP203_HArray1OfClassifiedItem(py::module &);
void bind_StepAP203_CcDesignSecurityClassification(py::module &);
void bind_StepAP203_HArray1OfSpecifiedItem(py::module &);
void bind_StepAP203_CcDesignSpecificationReference(py::module &);
void bind_StepAP203_HArray1OfWorkItem(py::module &);
void bind_StepAP203_Change(py::module &);
void bind_StepAP203_HArray1OfChangeRequestItem(py::module &);
void bind_StepAP203_ChangeRequest(py::module &);
void bind_StepAP203_HArray1OfStartRequestItem(py::module &);
void bind_StepAP203_StartRequest(py::module &);
void bind_StepAP203_StartWork(py::module &);

PYBIND11_MODULE(StepAP203, mod) {

py::module::import("OCCT.StepData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");

bind_StepAP203_ApprovedItem(mod);
bind_StepAP203_Array1OfApprovedItem(mod);
bind_StepAP203_CertifiedItem(mod);
bind_StepAP203_Array1OfCertifiedItem(mod);
bind_StepAP203_ChangeRequestItem(mod);
bind_StepAP203_Array1OfChangeRequestItem(mod);
bind_StepAP203_ClassifiedItem(mod);
bind_StepAP203_Array1OfClassifiedItem(mod);
bind_StepAP203_ContractedItem(mod);
bind_StepAP203_Array1OfContractedItem(mod);
bind_StepAP203_DateTimeItem(mod);
bind_StepAP203_Array1OfDateTimeItem(mod);
bind_StepAP203_PersonOrganizationItem(mod);
bind_StepAP203_Array1OfPersonOrganizationItem(mod);
bind_StepAP203_SpecifiedItem(mod);
bind_StepAP203_Array1OfSpecifiedItem(mod);
bind_StepAP203_StartRequestItem(mod);
bind_StepAP203_Array1OfStartRequestItem(mod);
bind_StepAP203_WorkItem(mod);
bind_StepAP203_Array1OfWorkItem(mod);
bind_StepAP203_HArray1OfApprovedItem(mod);
bind_StepAP203_CcDesignApproval(mod);
bind_StepAP203_HArray1OfCertifiedItem(mod);
bind_StepAP203_CcDesignCertification(mod);
bind_StepAP203_HArray1OfContractedItem(mod);
bind_StepAP203_CcDesignContract(mod);
bind_StepAP203_HArray1OfDateTimeItem(mod);
bind_StepAP203_CcDesignDateAndTimeAssignment(mod);
bind_StepAP203_HArray1OfPersonOrganizationItem(mod);
bind_StepAP203_CcDesignPersonAndOrganizationAssignment(mod);
bind_StepAP203_HArray1OfClassifiedItem(mod);
bind_StepAP203_CcDesignSecurityClassification(mod);
bind_StepAP203_HArray1OfSpecifiedItem(mod);
bind_StepAP203_CcDesignSpecificationReference(mod);
bind_StepAP203_HArray1OfWorkItem(mod);
bind_StepAP203_Change(mod);
bind_StepAP203_HArray1OfChangeRequestItem(mod);
bind_StepAP203_ChangeRequest(mod);
bind_StepAP203_HArray1OfStartRequestItem(mod);
bind_StepAP203_StartRequest(mod);
bind_StepAP203_StartWork(mod);

}
