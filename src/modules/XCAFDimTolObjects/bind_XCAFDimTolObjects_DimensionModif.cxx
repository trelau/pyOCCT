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
#include <XCAFDimTolObjects_DimensionModif.hxx>

void bind_XCAFDimTolObjects_DimensionModif(py::module &mod){

py::enum_<XCAFDimTolObjects_DimensionModif>(mod, "XCAFDimTolObjects_DimensionModif", "Defines modifirs")
	.value("XCAFDimTolObjects_DimensionModif_ControlledRadius", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_ControlledRadius)
	.value("XCAFDimTolObjects_DimensionModif_Square", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_Square)
	.value("XCAFDimTolObjects_DimensionModif_StatisticalTolerance", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_StatisticalTolerance)
	.value("XCAFDimTolObjects_DimensionModif_ContinuousFeature", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_ContinuousFeature)
	.value("XCAFDimTolObjects_DimensionModif_TwoPointSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_TwoPointSize)
	.value("XCAFDimTolObjects_DimensionModif_LocalSizeDefinedBySphere", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_LocalSizeDefinedBySphere)
	.value("XCAFDimTolObjects_DimensionModif_LeastSquaresAssociationCriterion", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_LeastSquaresAssociationCriterion)
	.value("XCAFDimTolObjects_DimensionModif_MaximumInscribedAssociation", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MaximumInscribedAssociation)
	.value("XCAFDimTolObjects_DimensionModif_MinimumCircumscribedAssociation", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MinimumCircumscribedAssociation)
	.value("XCAFDimTolObjects_DimensionModif_CircumferenceDiameter", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_CircumferenceDiameter)
	.value("XCAFDimTolObjects_DimensionModif_AreaDiameter", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_AreaDiameter)
	.value("XCAFDimTolObjects_DimensionModif_VolumeDiameter", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_VolumeDiameter)
	.value("XCAFDimTolObjects_DimensionModif_MaximumSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MaximumSize)
	.value("XCAFDimTolObjects_DimensionModif_MinimumSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MinimumSize)
	.value("XCAFDimTolObjects_DimensionModif_AverageSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_AverageSize)
	.value("XCAFDimTolObjects_DimensionModif_MedianSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MedianSize)
	.value("XCAFDimTolObjects_DimensionModif_MidRangeSize", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_MidRangeSize)
	.value("XCAFDimTolObjects_DimensionModif_RangeOfSizes", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_RangeOfSizes)
	.value("XCAFDimTolObjects_DimensionModif_AnyRestrictedPortionOfFeature", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_AnyRestrictedPortionOfFeature)
	.value("XCAFDimTolObjects_DimensionModif_AnyCrossSection", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_AnyCrossSection)
	.value("XCAFDimTolObjects_DimensionModif_SpecificFixedCrossSection", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_SpecificFixedCrossSection)
	.value("XCAFDimTolObjects_DimensionModif_CommonTolerance", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_CommonTolerance)
	.value("XCAFDimTolObjects_DimensionModif_FreeStateCondition", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_FreeStateCondition)
	.value("XCAFDimTolObjects_DimensionModif_Between", XCAFDimTolObjects_DimensionModif::XCAFDimTolObjects_DimensionModif_Between)
	.export_values();


}