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
#include <XCAFDimTolObjects_DimensionFormVariance.hxx>

void bind_XCAFDimTolObjects_DimensionFormVariance(py::module &mod){

py::enum_<XCAFDimTolObjects_DimensionFormVariance>(mod, "XCAFDimTolObjects_DimensionFormVariance", "Defines value of form variance")
	.value("XCAFDimTolObjects_DimensionFormVariance_None", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_None)
	.value("XCAFDimTolObjects_DimensionFormVariance_A", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_A)
	.value("XCAFDimTolObjects_DimensionFormVariance_B", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_B)
	.value("XCAFDimTolObjects_DimensionFormVariance_C", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_C)
	.value("XCAFDimTolObjects_DimensionFormVariance_CD", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_CD)
	.value("XCAFDimTolObjects_DimensionFormVariance_D", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_D)
	.value("XCAFDimTolObjects_DimensionFormVariance_E", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_E)
	.value("XCAFDimTolObjects_DimensionFormVariance_EF", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_EF)
	.value("XCAFDimTolObjects_DimensionFormVariance_F", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_F)
	.value("XCAFDimTolObjects_DimensionFormVariance_FG", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_FG)
	.value("XCAFDimTolObjects_DimensionFormVariance_G", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_G)
	.value("XCAFDimTolObjects_DimensionFormVariance_H", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_H)
	.value("XCAFDimTolObjects_DimensionFormVariance_JS", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_JS)
	.value("XCAFDimTolObjects_DimensionFormVariance_J", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_J)
	.value("XCAFDimTolObjects_DimensionFormVariance_K", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_K)
	.value("XCAFDimTolObjects_DimensionFormVariance_M", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_M)
	.value("XCAFDimTolObjects_DimensionFormVariance_N", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_N)
	.value("XCAFDimTolObjects_DimensionFormVariance_P", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_P)
	.value("XCAFDimTolObjects_DimensionFormVariance_R", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_R)
	.value("XCAFDimTolObjects_DimensionFormVariance_S", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_S)
	.value("XCAFDimTolObjects_DimensionFormVariance_T", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_T)
	.value("XCAFDimTolObjects_DimensionFormVariance_U", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_U)
	.value("XCAFDimTolObjects_DimensionFormVariance_V", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_V)
	.value("XCAFDimTolObjects_DimensionFormVariance_X", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_X)
	.value("XCAFDimTolObjects_DimensionFormVariance_Y", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_Y)
	.value("XCAFDimTolObjects_DimensionFormVariance_Z", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_Z)
	.value("XCAFDimTolObjects_DimensionFormVariance_ZA", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_ZA)
	.value("XCAFDimTolObjects_DimensionFormVariance_ZB", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_ZB)
	.value("XCAFDimTolObjects_DimensionFormVariance_ZC", XCAFDimTolObjects_DimensionFormVariance::XCAFDimTolObjects_DimensionFormVariance_ZC)
	.export_values();


}