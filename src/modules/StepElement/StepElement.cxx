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

void bind_StepElement_ElementVolume(py::module &);
void bind_StepElement_CurveEdge(py::module &);
void bind_StepElement_EnumeratedCurveElementFreedom(py::module &);
void bind_StepElement_UnspecifiedValue(py::module &);
void bind_StepElement_EnumeratedVolumeElementPurpose(py::module &);
void bind_StepElement_EnumeratedSurfaceElementPurpose(py::module &);
void bind_StepElement_ElementOrder(py::module &);
void bind_StepElement_EnumeratedCurveElementPurpose(py::module &);
void bind_StepElement_Element2dShape(py::module &);
void bind_StepElement_Volume3dElementShape(py::module &);
void bind_StepElement_ElementMaterial(py::module &);
void bind_StepElement_SequenceOfElementMaterial(py::module &);
void bind_StepElement_HSequenceOfElementMaterial(py::module &);
void bind_StepElement_ElementAspect(py::module &);
void bind_StepElement_CurveElementSectionDefinition(py::module &);
void bind_StepElement_SequenceOfCurveElementSectionDefinition(py::module &);
void bind_StepElement_HSequenceOfCurveElementSectionDefinition(py::module &);
void bind_StepElement_AnalysisItemWithinRepresentation(py::module &);
void bind_StepElement_CurveElementFreedom(py::module &);
void bind_StepElement_CurveElementEndReleasePacket(py::module &);
void bind_StepElement_Array1OfCurveElementEndReleasePacket(py::module &);
void bind_StepElement_Array1OfCurveElementSectionDefinition(py::module &);
void bind_StepElement_CurveElementPurposeMember(py::module &);
void bind_StepElement_SequenceOfCurveElementPurposeMember(py::module &);
void bind_StepElement_HSequenceOfCurveElementPurposeMember(py::module &);
void bind_StepElement_Array1OfHSequenceOfCurveElementPurposeMember(py::module &);
void bind_StepElement_SurfaceElementPurposeMember(py::module &);
void bind_StepElement_SequenceOfSurfaceElementPurposeMember(py::module &);
void bind_StepElement_HSequenceOfSurfaceElementPurposeMember(py::module &);
void bind_StepElement_Array1OfHSequenceOfSurfaceElementPurposeMember(py::module &);
void bind_StepElement_MeasureOrUnspecifiedValue(py::module &);
void bind_StepElement_Array1OfMeasureOrUnspecifiedValue(py::module &);
void bind_StepElement_SurfaceSection(py::module &);
void bind_StepElement_Array1OfSurfaceSection(py::module &);
void bind_StepElement_VolumeElementPurpose(py::module &);
void bind_StepElement_Array1OfVolumeElementPurpose(py::module &);
void bind_StepElement_VolumeElementPurposeMember(py::module &);
void bind_StepElement_Array1OfVolumeElementPurposeMember(py::module &);
void bind_StepElement_Array2OfCurveElementPurposeMember(py::module &);
void bind_StepElement_SurfaceElementPurpose(py::module &);
void bind_StepElement_Array2OfSurfaceElementPurpose(py::module &);
void bind_StepElement_Array2OfSurfaceElementPurposeMember(py::module &);
void bind_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember(py::module &);
void bind_StepElement_ElementDescriptor(py::module &);
void bind_StepElement_Curve3dElementDescriptor(py::module &);
void bind_StepElement_CurveElementFreedomMember(py::module &);
void bind_StepElement_CurveElementPurpose(py::module &);
void bind_StepElement_HArray1OfMeasureOrUnspecifiedValue(py::module &);
void bind_StepElement_CurveElementSectionDerivedDefinitions(py::module &);
void bind_StepElement_ElementAspectMember(py::module &);
void bind_StepElement_HArray1OfCurveElementEndReleasePacket(py::module &);
void bind_StepElement_HArray1OfCurveElementSectionDefinition(py::module &);
void bind_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember(py::module &);
void bind_StepElement_HArray1OfSurfaceSection(py::module &);
void bind_StepElement_HArray1OfVolumeElementPurpose(py::module &);
void bind_StepElement_HArray1OfVolumeElementPurposeMember(py::module &);
void bind_StepElement_HArray2OfCurveElementPurposeMember(py::module &);
void bind_StepElement_HArray2OfSurfaceElementPurpose(py::module &);
void bind_StepElement_HArray2OfSurfaceElementPurposeMember(py::module &);
void bind_StepElement_MeasureOrUnspecifiedValueMember(py::module &);
void bind_StepElement_Surface3dElementDescriptor(py::module &);
void bind_StepElement_SurfaceElementProperty(py::module &);
void bind_StepElement_SurfaceSectionField(py::module &);
void bind_StepElement_SurfaceSectionFieldConstant(py::module &);
void bind_StepElement_SurfaceSectionFieldVarying(py::module &);
void bind_StepElement_UniformSurfaceSection(py::module &);
void bind_StepElement_Volume3dElementDescriptor(py::module &);

PYBIND11_MODULE(StepElement, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StepData");
py::module::import("OCCT.TColStd");

bind_StepElement_ElementVolume(mod);
bind_StepElement_CurveEdge(mod);
bind_StepElement_EnumeratedCurveElementFreedom(mod);
bind_StepElement_UnspecifiedValue(mod);
bind_StepElement_EnumeratedVolumeElementPurpose(mod);
bind_StepElement_EnumeratedSurfaceElementPurpose(mod);
bind_StepElement_ElementOrder(mod);
bind_StepElement_EnumeratedCurveElementPurpose(mod);
bind_StepElement_Element2dShape(mod);
bind_StepElement_Volume3dElementShape(mod);
bind_StepElement_ElementMaterial(mod);
bind_StepElement_SequenceOfElementMaterial(mod);
bind_StepElement_HSequenceOfElementMaterial(mod);
bind_StepElement_ElementAspect(mod);
bind_StepElement_CurveElementSectionDefinition(mod);
bind_StepElement_SequenceOfCurveElementSectionDefinition(mod);
bind_StepElement_HSequenceOfCurveElementSectionDefinition(mod);
bind_StepElement_AnalysisItemWithinRepresentation(mod);
bind_StepElement_CurveElementFreedom(mod);
bind_StepElement_CurveElementEndReleasePacket(mod);
bind_StepElement_Array1OfCurveElementEndReleasePacket(mod);
bind_StepElement_Array1OfCurveElementSectionDefinition(mod);
bind_StepElement_CurveElementPurposeMember(mod);
bind_StepElement_SequenceOfCurveElementPurposeMember(mod);
bind_StepElement_HSequenceOfCurveElementPurposeMember(mod);
bind_StepElement_Array1OfHSequenceOfCurveElementPurposeMember(mod);
bind_StepElement_SurfaceElementPurposeMember(mod);
bind_StepElement_SequenceOfSurfaceElementPurposeMember(mod);
bind_StepElement_HSequenceOfSurfaceElementPurposeMember(mod);
bind_StepElement_Array1OfHSequenceOfSurfaceElementPurposeMember(mod);
bind_StepElement_MeasureOrUnspecifiedValue(mod);
bind_StepElement_Array1OfMeasureOrUnspecifiedValue(mod);
bind_StepElement_SurfaceSection(mod);
bind_StepElement_Array1OfSurfaceSection(mod);
bind_StepElement_VolumeElementPurpose(mod);
bind_StepElement_Array1OfVolumeElementPurpose(mod);
bind_StepElement_VolumeElementPurposeMember(mod);
bind_StepElement_Array1OfVolumeElementPurposeMember(mod);
bind_StepElement_Array2OfCurveElementPurposeMember(mod);
bind_StepElement_SurfaceElementPurpose(mod);
bind_StepElement_Array2OfSurfaceElementPurpose(mod);
bind_StepElement_Array2OfSurfaceElementPurposeMember(mod);
bind_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember(mod);
bind_StepElement_ElementDescriptor(mod);
bind_StepElement_Curve3dElementDescriptor(mod);
bind_StepElement_CurveElementFreedomMember(mod);
bind_StepElement_CurveElementPurpose(mod);
bind_StepElement_HArray1OfMeasureOrUnspecifiedValue(mod);
bind_StepElement_CurveElementSectionDerivedDefinitions(mod);
bind_StepElement_ElementAspectMember(mod);
bind_StepElement_HArray1OfCurveElementEndReleasePacket(mod);
bind_StepElement_HArray1OfCurveElementSectionDefinition(mod);
bind_StepElement_HArray1OfHSequenceOfSurfaceElementPurposeMember(mod);
bind_StepElement_HArray1OfSurfaceSection(mod);
bind_StepElement_HArray1OfVolumeElementPurpose(mod);
bind_StepElement_HArray1OfVolumeElementPurposeMember(mod);
bind_StepElement_HArray2OfCurveElementPurposeMember(mod);
bind_StepElement_HArray2OfSurfaceElementPurpose(mod);
bind_StepElement_HArray2OfSurfaceElementPurposeMember(mod);
bind_StepElement_MeasureOrUnspecifiedValueMember(mod);
bind_StepElement_Surface3dElementDescriptor(mod);
bind_StepElement_SurfaceElementProperty(mod);
bind_StepElement_SurfaceSectionField(mod);
bind_StepElement_SurfaceSectionFieldConstant(mod);
bind_StepElement_SurfaceSectionFieldVarying(mod);
bind_StepElement_UniformSurfaceSection(mod);
bind_StepElement_Volume3dElementDescriptor(mod);

}
