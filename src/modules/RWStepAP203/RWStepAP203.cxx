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

void bind_RWStepAP203_RWCcDesignApproval(py::module &);
void bind_RWStepAP203_RWCcDesignCertification(py::module &);
void bind_RWStepAP203_RWCcDesignContract(py::module &);
void bind_RWStepAP203_RWCcDesignDateAndTimeAssignment(py::module &);
void bind_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment(py::module &);
void bind_RWStepAP203_RWCcDesignSecurityClassification(py::module &);
void bind_RWStepAP203_RWCcDesignSpecificationReference(py::module &);
void bind_RWStepAP203_RWChange(py::module &);
void bind_RWStepAP203_RWChangeRequest(py::module &);
void bind_RWStepAP203_RWStartRequest(py::module &);
void bind_RWStepAP203_RWStartWork(py::module &);

PYBIND11_MODULE(RWStepAP203, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepAP203");

bind_RWStepAP203_RWCcDesignApproval(mod);
bind_RWStepAP203_RWCcDesignCertification(mod);
bind_RWStepAP203_RWCcDesignContract(mod);
bind_RWStepAP203_RWCcDesignDateAndTimeAssignment(mod);
bind_RWStepAP203_RWCcDesignPersonAndOrganizationAssignment(mod);
bind_RWStepAP203_RWCcDesignSecurityClassification(mod);
bind_RWStepAP203_RWCcDesignSpecificationReference(mod);
bind_RWStepAP203_RWChange(mod);
bind_RWStepAP203_RWChangeRequest(mod);
bind_RWStepAP203_RWStartRequest(mod);
bind_RWStepAP203_RWStartWork(mod);

}
