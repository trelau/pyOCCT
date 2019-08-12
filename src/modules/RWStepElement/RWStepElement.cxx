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

void bind_RWStepElement_RWAnalysisItemWithinRepresentation(py::module &);
void bind_RWStepElement_RWCurve3dElementDescriptor(py::module &);
void bind_RWStepElement_RWCurveElementEndReleasePacket(py::module &);
void bind_RWStepElement_RWCurveElementSectionDefinition(py::module &);
void bind_RWStepElement_RWCurveElementSectionDerivedDefinitions(py::module &);
void bind_RWStepElement_RWElementDescriptor(py::module &);
void bind_RWStepElement_RWElementMaterial(py::module &);
void bind_RWStepElement_RWSurface3dElementDescriptor(py::module &);
void bind_RWStepElement_RWSurfaceElementProperty(py::module &);
void bind_RWStepElement_RWSurfaceSection(py::module &);
void bind_RWStepElement_RWSurfaceSectionField(py::module &);
void bind_RWStepElement_RWSurfaceSectionFieldConstant(py::module &);
void bind_RWStepElement_RWSurfaceSectionFieldVarying(py::module &);
void bind_RWStepElement_RWUniformSurfaceSection(py::module &);
void bind_RWStepElement_RWVolume3dElementDescriptor(py::module &);

PYBIND11_MODULE(RWStepElement, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepElement");

bind_RWStepElement_RWAnalysisItemWithinRepresentation(mod);
bind_RWStepElement_RWCurve3dElementDescriptor(mod);
bind_RWStepElement_RWCurveElementEndReleasePacket(mod);
bind_RWStepElement_RWCurveElementSectionDefinition(mod);
bind_RWStepElement_RWCurveElementSectionDerivedDefinitions(mod);
bind_RWStepElement_RWElementDescriptor(mod);
bind_RWStepElement_RWElementMaterial(mod);
bind_RWStepElement_RWSurface3dElementDescriptor(mod);
bind_RWStepElement_RWSurfaceElementProperty(mod);
bind_RWStepElement_RWSurfaceSection(mod);
bind_RWStepElement_RWSurfaceSectionField(mod);
bind_RWStepElement_RWSurfaceSectionFieldConstant(mod);
bind_RWStepElement_RWSurfaceSectionFieldVarying(mod);
bind_RWStepElement_RWUniformSurfaceSection(mod);
bind_RWStepElement_RWVolume3dElementDescriptor(mod);

}
