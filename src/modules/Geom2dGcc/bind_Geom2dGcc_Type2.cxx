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
#include <Geom2dGcc_Type2.hxx>

void bind_Geom2dGcc_Type2(py::module &mod){

py::enum_<Geom2dGcc_Type2>(mod, "Geom2dGcc_Type2", "None")
	.value("Geom2dGcc_CuCuOnCu", Geom2dGcc_Type2::Geom2dGcc_CuCuOnCu)
	.value("Geom2dGcc_CiCuOnCu", Geom2dGcc_Type2::Geom2dGcc_CiCuOnCu)
	.value("Geom2dGcc_LiCuOnCu", Geom2dGcc_Type2::Geom2dGcc_LiCuOnCu)
	.value("Geom2dGcc_CuPtOnCu", Geom2dGcc_Type2::Geom2dGcc_CuPtOnCu)
	.value("Geom2dGcc_CuCuOnLi", Geom2dGcc_Type2::Geom2dGcc_CuCuOnLi)
	.value("Geom2dGcc_CiCuOnLi", Geom2dGcc_Type2::Geom2dGcc_CiCuOnLi)
	.value("Geom2dGcc_LiCuOnLi", Geom2dGcc_Type2::Geom2dGcc_LiCuOnLi)
	.value("Geom2dGcc_CuPtOnLi", Geom2dGcc_Type2::Geom2dGcc_CuPtOnLi)
	.value("Geom2dGcc_CuCuOnCi", Geom2dGcc_Type2::Geom2dGcc_CuCuOnCi)
	.value("Geom2dGcc_CiCuOnCi", Geom2dGcc_Type2::Geom2dGcc_CiCuOnCi)
	.value("Geom2dGcc_LiCuOnCi", Geom2dGcc_Type2::Geom2dGcc_LiCuOnCi)
	.value("Geom2dGcc_CuPtOnCi", Geom2dGcc_Type2::Geom2dGcc_CuPtOnCi)
	.export_values();


}