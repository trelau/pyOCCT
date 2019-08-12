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
#include <BSplCLib_KnotDistribution.hxx>

void bind_BSplCLib_KnotDistribution(py::module &mod){

py::enum_<BSplCLib_KnotDistribution>(mod, "BSplCLib_KnotDistribution", "This enumeration describes the repartition of the knots sequence. If all the knots differ by the same positive constant from the preceding knot the 'KnotDistribution' is <Uniform> else it is <NonUniform>")
	.value("BSplCLib_NonUniform", BSplCLib_KnotDistribution::BSplCLib_NonUniform)
	.value("BSplCLib_Uniform", BSplCLib_KnotDistribution::BSplCLib_Uniform)
	.export_values();


}