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
#include <Prs3d_DatumParts.hxx>

void bind_Prs3d_DatumParts(py::module &mod){

py::enum_<Prs3d_DatumParts>(mod, "Prs3d_DatumParts", "Enumeration defining a part of datum aspect, see Prs3d_Datum.")
	.value("Prs3d_DP_Origin", Prs3d_DatumParts::Prs3d_DP_Origin)
	.value("Prs3d_DP_XAxis", Prs3d_DatumParts::Prs3d_DP_XAxis)
	.value("Prs3d_DP_YAxis", Prs3d_DatumParts::Prs3d_DP_YAxis)
	.value("Prs3d_DP_ZAxis", Prs3d_DatumParts::Prs3d_DP_ZAxis)
	.value("Prs3d_DP_XArrow", Prs3d_DatumParts::Prs3d_DP_XArrow)
	.value("Prs3d_DP_YArrow", Prs3d_DatumParts::Prs3d_DP_YArrow)
	.value("Prs3d_DP_ZArrow", Prs3d_DatumParts::Prs3d_DP_ZArrow)
	.value("Prs3d_DP_XOYAxis", Prs3d_DatumParts::Prs3d_DP_XOYAxis)
	.value("Prs3d_DP_YOZAxis", Prs3d_DatumParts::Prs3d_DP_YOZAxis)
	.value("Prs3d_DP_XOZAxis", Prs3d_DatumParts::Prs3d_DP_XOZAxis)
	.value("Prs3d_DP_None", Prs3d_DatumParts::Prs3d_DP_None)
	.export_values();


}