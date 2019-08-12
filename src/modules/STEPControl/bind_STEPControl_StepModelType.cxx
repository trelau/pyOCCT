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
#include <STEPControl_StepModelType.hxx>

void bind_STEPControl_StepModelType(py::module &mod){

py::enum_<STEPControl_StepModelType>(mod, "STEPControl_StepModelType", "Gives you the choice of translation mode for an Open CASCADE shape that is being translated to STEP. - STEPControl_AsIs translates an Open CASCADE shape to its highest possible STEP representation. - STEPControl_ManifoldSolidBrep translates an Open CASCADE shape to a STEP manifold_solid_brep or brep_with_voids entity. - STEPControl_FacetedBrep translates an Open CASCADE shape into a STEP faceted_brep entity. - STEPControl_ShellBasedSurfaceModel translates an Open CASCADE shape into a STEP shell_based_surface_model entity. - STEPControl_GeometricCurveSet translates an Open CASCADE shape into a STEP geometric_curve_set entity.")
	.value("STEPControl_AsIs", STEPControl_StepModelType::STEPControl_AsIs)
	.value("STEPControl_ManifoldSolidBrep", STEPControl_StepModelType::STEPControl_ManifoldSolidBrep)
	.value("STEPControl_BrepWithVoids", STEPControl_StepModelType::STEPControl_BrepWithVoids)
	.value("STEPControl_FacetedBrep", STEPControl_StepModelType::STEPControl_FacetedBrep)
	.value("STEPControl_FacetedBrepAndBrepWithVoids", STEPControl_StepModelType::STEPControl_FacetedBrepAndBrepWithVoids)
	.value("STEPControl_ShellBasedSurfaceModel", STEPControl_StepModelType::STEPControl_ShellBasedSurfaceModel)
	.value("STEPControl_GeometricCurveSet", STEPControl_StepModelType::STEPControl_GeometricCurveSet)
	.value("STEPControl_Hybrid", STEPControl_StepModelType::STEPControl_Hybrid)
	.export_values();


}