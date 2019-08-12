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
#include <Geom2dGcc_Type1.hxx>

void bind_Geom2dGcc_Type1(py::module &mod){

py::enum_<Geom2dGcc_Type1>(mod, "Geom2dGcc_Type1", "None")
	.value("Geom2dGcc_CuCuCu", Geom2dGcc_Type1::Geom2dGcc_CuCuCu)
	.value("Geom2dGcc_CiCuCu", Geom2dGcc_Type1::Geom2dGcc_CiCuCu)
	.value("Geom2dGcc_CiCiCu", Geom2dGcc_Type1::Geom2dGcc_CiCiCu)
	.value("Geom2dGcc_CiLiCu", Geom2dGcc_Type1::Geom2dGcc_CiLiCu)
	.value("Geom2dGcc_LiLiCu", Geom2dGcc_Type1::Geom2dGcc_LiLiCu)
	.value("Geom2dGcc_LiCuCu", Geom2dGcc_Type1::Geom2dGcc_LiCuCu)
	.export_values();


}