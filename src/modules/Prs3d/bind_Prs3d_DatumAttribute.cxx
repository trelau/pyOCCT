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
#include <Prs3d_DatumAttribute.hxx>

void bind_Prs3d_DatumAttribute(py::module &mod){

py::enum_<Prs3d_DatumAttribute>(mod, "Prs3d_DatumAttribute", "Enumeration defining a part of datum aspect, see Prs3d_Datum.")
	.value("Prs3d_DA_XAxisLength", Prs3d_DatumAttribute::Prs3d_DA_XAxisLength)
	.value("Prs3d_DA_YAxisLength", Prs3d_DatumAttribute::Prs3d_DA_YAxisLength)
	.value("Prs3d_DA_ZAxisLength", Prs3d_DatumAttribute::Prs3d_DA_ZAxisLength)
	.value("Prs3d_DP_ShadingTubeRadiusPercent", Prs3d_DatumAttribute::Prs3d_DP_ShadingTubeRadiusPercent)
	.value("Prs3d_DP_ShadingConeRadiusPercent", Prs3d_DatumAttribute::Prs3d_DP_ShadingConeRadiusPercent)
	.value("Prs3d_DP_ShadingConeLengthPercent", Prs3d_DatumAttribute::Prs3d_DP_ShadingConeLengthPercent)
	.value("Prs3d_DP_ShadingOriginRadiusPercent", Prs3d_DatumAttribute::Prs3d_DP_ShadingOriginRadiusPercent)
	.value("Prs3d_DP_ShadingNumberOfFacettes", Prs3d_DatumAttribute::Prs3d_DP_ShadingNumberOfFacettes)
	.export_values();


}