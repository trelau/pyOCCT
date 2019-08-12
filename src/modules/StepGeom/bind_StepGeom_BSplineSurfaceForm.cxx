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
#include <StepGeom_BSplineSurfaceForm.hxx>

void bind_StepGeom_BSplineSurfaceForm(py::module &mod){

py::enum_<StepGeom_BSplineSurfaceForm>(mod, "StepGeom_BSplineSurfaceForm", "None")
	.value("StepGeom_bssfPlaneSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfPlaneSurf)
	.value("StepGeom_bssfCylindricalSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfCylindricalSurf)
	.value("StepGeom_bssfConicalSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfConicalSurf)
	.value("StepGeom_bssfSphericalSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfSphericalSurf)
	.value("StepGeom_bssfToroidalSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfToroidalSurf)
	.value("StepGeom_bssfSurfOfRevolution", StepGeom_BSplineSurfaceForm::StepGeom_bssfSurfOfRevolution)
	.value("StepGeom_bssfRuledSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfRuledSurf)
	.value("StepGeom_bssfGeneralisedCone", StepGeom_BSplineSurfaceForm::StepGeom_bssfGeneralisedCone)
	.value("StepGeom_bssfQuadricSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfQuadricSurf)
	.value("StepGeom_bssfSurfOfLinearExtrusion", StepGeom_BSplineSurfaceForm::StepGeom_bssfSurfOfLinearExtrusion)
	.value("StepGeom_bssfUnspecified", StepGeom_BSplineSurfaceForm::StepGeom_bssfUnspecified)
	.export_values();


}