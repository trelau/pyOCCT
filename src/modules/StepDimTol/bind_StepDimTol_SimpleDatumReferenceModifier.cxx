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
#include <StepDimTol_SimpleDatumReferenceModifier.hxx>

void bind_StepDimTol_SimpleDatumReferenceModifier(py::module &mod){

py::enum_<StepDimTol_SimpleDatumReferenceModifier>(mod, "StepDimTol_SimpleDatumReferenceModifier", "None")
	.value("StepDimTol_SDRMAnyCrossSection", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMAnyCrossSection)
	.value("StepDimTol_SDRMAnyLongitudinalSection", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMAnyLongitudinalSection)
	.value("StepDimTol_SDRMBasic", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMBasic)
	.value("StepDimTol_SDRMContactingFeature", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMContactingFeature)
	.value("StepDimTol_SDRMDegreeOfFreedomConstraintU", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintU)
	.value("StepDimTol_SDRMDegreeOfFreedomConstraintV", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintV)
	.value("StepDimTol_SDRMDegreeOfFreedomConstraintW", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintW)
	.value("StepDimTol_SDRMDegreeOfFreedomConstraintX", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintX)
	.value("StepDimTol_SDRMDegreeOfFreedomConstraintY", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintY)
	.value("StepDimTol_SDRMDegreeOfFreedomConstraintZ", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDegreeOfFreedomConstraintZ)
	.value("StepDimTol_SDRMDistanceVariable", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMDistanceVariable)
	.value("StepDimTol_SDRMFreeState", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMFreeState)
	.value("StepDimTol_SDRMLeastMaterialRequirement", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMLeastMaterialRequirement)
	.value("StepDimTol_SDRMLine", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMLine)
	.value("StepDimTol_SDRMMajorDiameter", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMMajorDiameter)
	.value("StepDimTol_SDRMMaximumMaterialRequirement", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMMaximumMaterialRequirement)
	.value("StepDimTol_SDRMMinorDiameter", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMMinorDiameter)
	.value("StepDimTol_SDRMOrientation", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMOrientation)
	.value("StepDimTol_SDRMPitchDiameter", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMPitchDiameter)
	.value("StepDimTol_SDRMPlane", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMPlane)
	.value("StepDimTol_SDRMPoint", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMPoint)
	.value("StepDimTol_SDRMTranslation", StepDimTol_SimpleDatumReferenceModifier::StepDimTol_SDRMTranslation)
	.export_values();


}