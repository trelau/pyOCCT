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
#include <StepDimTol_GeometricToleranceModifier.hxx>

void bind_StepDimTol_GeometricToleranceModifier(py::module &mod){

py::enum_<StepDimTol_GeometricToleranceModifier>(mod, "StepDimTol_GeometricToleranceModifier", "None")
	.value("StepDimTol_GTMAnyCrossSection", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMAnyCrossSection)
	.value("StepDimTol_GTMCommonZone", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMCommonZone)
	.value("StepDimTol_GTMEachRadialElement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMEachRadialElement)
	.value("StepDimTol_GTMFreeState", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMFreeState)
	.value("StepDimTol_GTMLeastMaterialRequirement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMLeastMaterialRequirement)
	.value("StepDimTol_GTMLineElement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMLineElement)
	.value("StepDimTol_GTMMajorDiameter", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMMajorDiameter)
	.value("StepDimTol_GTMMaximumMaterialRequirement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMMaximumMaterialRequirement)
	.value("StepDimTol_GTMMinorDiameter", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMMinorDiameter)
	.value("StepDimTol_GTMNotConvex", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMNotConvex)
	.value("StepDimTol_GTMPitchDiameter", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMPitchDiameter)
	.value("StepDimTol_GTMReciprocityRequirement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMReciprocityRequirement)
	.value("StepDimTol_GTMSeparateRequirement", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMSeparateRequirement)
	.value("StepDimTol_GTMStatisticalTolerance", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMStatisticalTolerance)
	.value("StepDimTol_GTMTangentPlane", StepDimTol_GeometricToleranceModifier::StepDimTol_GTMTangentPlane)
	.export_values();


}