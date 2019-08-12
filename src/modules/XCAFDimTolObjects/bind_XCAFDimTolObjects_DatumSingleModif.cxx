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
#include <XCAFDimTolObjects_DatumSingleModif.hxx>

void bind_XCAFDimTolObjects_DatumSingleModif(py::module &mod){

py::enum_<XCAFDimTolObjects_DatumSingleModif>(mod, "XCAFDimTolObjects_DatumSingleModif", "Defines modifirs")
	.value("XCAFDimTolObjects_DatumSingleModif_AnyCrossSection", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_AnyCrossSection)
	.value("XCAFDimTolObjects_DatumSingleModif_Any_LongitudinalSection", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Any_LongitudinalSection)
	.value("XCAFDimTolObjects_DatumSingleModif_Basic", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Basic)
	.value("XCAFDimTolObjects_DatumSingleModif_ContactingFeature", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_ContactingFeature)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintU", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintU)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintV", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintV)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintW", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintW)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintX", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintX)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintY", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintY)
	.value("XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintZ", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DegreeOfFreedomConstraintZ)
	.value("XCAFDimTolObjects_DatumSingleModif_DistanceVariable", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_DistanceVariable)
	.value("XCAFDimTolObjects_DatumSingleModif_FreeState", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_FreeState)
	.value("XCAFDimTolObjects_DatumSingleModif_LeastMaterialRequirement", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_LeastMaterialRequirement)
	.value("XCAFDimTolObjects_DatumSingleModif_Line", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Line)
	.value("XCAFDimTolObjects_DatumSingleModif_MajorDiameter", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_MajorDiameter)
	.value("XCAFDimTolObjects_DatumSingleModif_MaximumMaterialRequirement", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_MaximumMaterialRequirement)
	.value("XCAFDimTolObjects_DatumSingleModif_MinorDiameter", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_MinorDiameter)
	.value("XCAFDimTolObjects_DatumSingleModif_Orientation", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Orientation)
	.value("XCAFDimTolObjects_DatumSingleModif_PitchDiameter", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_PitchDiameter)
	.value("XCAFDimTolObjects_DatumSingleModif_Plane", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Plane)
	.value("XCAFDimTolObjects_DatumSingleModif_Point", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Point)
	.value("XCAFDimTolObjects_DatumSingleModif_Translation", XCAFDimTolObjects_DatumSingleModif::XCAFDimTolObjects_DatumSingleModif_Translation)
	.export_values();


}