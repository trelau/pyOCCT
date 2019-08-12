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
#include <StepDimTol_GeometricToleranceType.hxx>

void bind_StepDimTol_GeometricToleranceType(py::module &mod){

py::enum_<StepDimTol_GeometricToleranceType>(mod, "StepDimTol_GeometricToleranceType", "None")
	.value("StepDimTol_GTTAngularityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTAngularityTolerance)
	.value("StepDimTol_GTTCircularRunoutTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTCircularRunoutTolerance)
	.value("StepDimTol_GTTCoaxialityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTCoaxialityTolerance)
	.value("StepDimTol_GTTConcentricityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTConcentricityTolerance)
	.value("StepDimTol_GTTCylindricityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTCylindricityTolerance)
	.value("StepDimTol_GTTFlatnessTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTFlatnessTolerance)
	.value("StepDimTol_GTTLineProfileTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTLineProfileTolerance)
	.value("StepDimTol_GTTParallelismTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTParallelismTolerance)
	.value("StepDimTol_GTTPerpendicularityTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTPerpendicularityTolerance)
	.value("StepDimTol_GTTPositionTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTPositionTolerance)
	.value("StepDimTol_GTTRoundnessTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTRoundnessTolerance)
	.value("StepDimTol_GTTStraightnessTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTStraightnessTolerance)
	.value("StepDimTol_GTTSurfaceProfileTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTSurfaceProfileTolerance)
	.value("StepDimTol_GTTSymmetryTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTSymmetryTolerance)
	.value("StepDimTol_GTTTotalRunoutTolerance", StepDimTol_GeometricToleranceType::StepDimTol_GTTTotalRunoutTolerance)
	.export_values();


}