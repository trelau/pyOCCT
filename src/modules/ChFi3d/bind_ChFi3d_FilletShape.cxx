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
#include <ChFi3d_FilletShape.hxx>

void bind_ChFi3d_FilletShape(py::module &mod){

py::enum_<ChFi3d_FilletShape>(mod, "ChFi3d_FilletShape", "Lists the types of fillet shapes. These include the following: - ChFi3d_Rational (default value), which is the standard NURBS representation of circles, - ChFi3d_QuasiAngular, which is a NURBS representation of circles where the parameters match those of the circle, - ChFi3d_Polynomial, which corresponds to a polynomial approximation of circles. This type facilitates the implementation of the construction algorithm.")
	.value("ChFi3d_Rational", ChFi3d_FilletShape::ChFi3d_Rational)
	.value("ChFi3d_QuasiAngular", ChFi3d_FilletShape::ChFi3d_QuasiAngular)
	.value("ChFi3d_Polynomial", ChFi3d_FilletShape::ChFi3d_Polynomial)
	.export_values();


}