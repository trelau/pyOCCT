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
#include <GeomAbs_BSplKnotDistribution.hxx>

void bind_GeomAbs_BSplKnotDistribution(py::module &mod){

py::enum_<GeomAbs_BSplKnotDistribution>(mod, "GeomAbs_BSplKnotDistribution", "This enumeration is used in the classes BSplineCurve and BSplineSurface to describe the repartition of set of knots. (comments in classes BSplineCurve and BSplineSurface)")
	.value("GeomAbs_NonUniform", GeomAbs_BSplKnotDistribution::GeomAbs_NonUniform)
	.value("GeomAbs_Uniform", GeomAbs_BSplKnotDistribution::GeomAbs_Uniform)
	.value("GeomAbs_QuasiUniform", GeomAbs_BSplKnotDistribution::GeomAbs_QuasiUniform)
	.value("GeomAbs_PiecewiseBezier", GeomAbs_BSplKnotDistribution::GeomAbs_PiecewiseBezier)
	.export_values();


}