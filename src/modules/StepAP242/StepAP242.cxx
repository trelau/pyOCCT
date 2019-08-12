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

void bind_StepAP242_ItemIdentifiedRepresentationUsageDefinition(py::module &);
void bind_StepAP242_ItemIdentifiedRepresentationUsage(py::module &);
void bind_StepAP242_DraughtingModelItemAssociation(py::module &);
void bind_StepAP242_GeometricItemSpecificUsage(py::module &);
void bind_StepAP242_IdAttributeSelect(py::module &);
void bind_StepAP242_IdAttribute(py::module &);

PYBIND11_MODULE(StepAP242, mod) {

py::module::import("OCCT.StepData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.StepAP214");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.StepDimTol");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.TCollection");

bind_StepAP242_ItemIdentifiedRepresentationUsageDefinition(mod);
bind_StepAP242_ItemIdentifiedRepresentationUsage(mod);
bind_StepAP242_DraughtingModelItemAssociation(mod);
bind_StepAP242_GeometricItemSpecificUsage(mod);
bind_StepAP242_IdAttributeSelect(mod);
bind_StepAP242_IdAttribute(mod);

}
