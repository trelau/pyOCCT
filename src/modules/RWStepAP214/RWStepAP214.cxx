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

void bind_RWStepAP214(py::module &);
void bind_RWStepAP214_GeneralModule(py::module &);
void bind_RWStepAP214_ReadWriteModule(py::module &);
void bind_RWStepAP214_RWAppliedApprovalAssignment(py::module &);
void bind_RWStepAP214_RWAppliedDateAndTimeAssignment(py::module &);
void bind_RWStepAP214_RWAppliedDateAssignment(py::module &);
void bind_RWStepAP214_RWAppliedDocumentReference(py::module &);
void bind_RWStepAP214_RWAppliedExternalIdentificationAssignment(py::module &);
void bind_RWStepAP214_RWAppliedGroupAssignment(py::module &);
void bind_RWStepAP214_RWAppliedOrganizationAssignment(py::module &);
void bind_RWStepAP214_RWAppliedPersonAndOrganizationAssignment(py::module &);
void bind_RWStepAP214_RWAppliedPresentedItem(py::module &);
void bind_RWStepAP214_RWAppliedSecurityClassificationAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignActualDateAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignApprovalAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignDateAndPersonAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignDocumentReference(py::module &);
void bind_RWStepAP214_RWAutoDesignGroupAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignNominalDateAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignOrganizationAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment(py::module &);
void bind_RWStepAP214_RWAutoDesignPresentedItem(py::module &);
void bind_RWStepAP214_RWAutoDesignSecurityClassificationAssignment(py::module &);
void bind_RWStepAP214_RWClass(py::module &);
void bind_RWStepAP214_RWExternallyDefinedClass(py::module &);
void bind_RWStepAP214_RWExternallyDefinedGeneralProperty(py::module &);
void bind_RWStepAP214_RWRepItemGroup(py::module &);

PYBIND11_MODULE(RWStepAP214, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.StepAP214");

bind_RWStepAP214(mod);
bind_RWStepAP214_GeneralModule(mod);
bind_RWStepAP214_ReadWriteModule(mod);
bind_RWStepAP214_RWAppliedApprovalAssignment(mod);
bind_RWStepAP214_RWAppliedDateAndTimeAssignment(mod);
bind_RWStepAP214_RWAppliedDateAssignment(mod);
bind_RWStepAP214_RWAppliedDocumentReference(mod);
bind_RWStepAP214_RWAppliedExternalIdentificationAssignment(mod);
bind_RWStepAP214_RWAppliedGroupAssignment(mod);
bind_RWStepAP214_RWAppliedOrganizationAssignment(mod);
bind_RWStepAP214_RWAppliedPersonAndOrganizationAssignment(mod);
bind_RWStepAP214_RWAppliedPresentedItem(mod);
bind_RWStepAP214_RWAppliedSecurityClassificationAssignment(mod);
bind_RWStepAP214_RWAutoDesignActualDateAndTimeAssignment(mod);
bind_RWStepAP214_RWAutoDesignActualDateAssignment(mod);
bind_RWStepAP214_RWAutoDesignApprovalAssignment(mod);
bind_RWStepAP214_RWAutoDesignDateAndPersonAssignment(mod);
bind_RWStepAP214_RWAutoDesignDocumentReference(mod);
bind_RWStepAP214_RWAutoDesignGroupAssignment(mod);
bind_RWStepAP214_RWAutoDesignNominalDateAndTimeAssignment(mod);
bind_RWStepAP214_RWAutoDesignNominalDateAssignment(mod);
bind_RWStepAP214_RWAutoDesignOrganizationAssignment(mod);
bind_RWStepAP214_RWAutoDesignPersonAndOrganizationAssignment(mod);
bind_RWStepAP214_RWAutoDesignPresentedItem(mod);
bind_RWStepAP214_RWAutoDesignSecurityClassificationAssignment(mod);
bind_RWStepAP214_RWClass(mod);
bind_RWStepAP214_RWExternallyDefinedClass(mod);
bind_RWStepAP214_RWExternallyDefinedGeneralProperty(mod);
bind_RWStepAP214_RWRepItemGroup(mod);

}
