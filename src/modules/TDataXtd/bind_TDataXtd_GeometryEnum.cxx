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
#include <TDataXtd_GeometryEnum.hxx>

void bind_TDataXtd_GeometryEnum(py::module &mod){

py::enum_<TDataXtd_GeometryEnum>(mod, "TDataXtd_GeometryEnum", "The terms of this enumeration define the types of geometric shapes available.")
	.value("TDataXtd_ANY_GEOM", TDataXtd_GeometryEnum::TDataXtd_ANY_GEOM)
	.value("TDataXtd_POINT", TDataXtd_GeometryEnum::TDataXtd_POINT)
	.value("TDataXtd_LINE", TDataXtd_GeometryEnum::TDataXtd_LINE)
	.value("TDataXtd_CIRCLE", TDataXtd_GeometryEnum::TDataXtd_CIRCLE)
	.value("TDataXtd_ELLIPSE", TDataXtd_GeometryEnum::TDataXtd_ELLIPSE)
	.value("TDataXtd_SPLINE", TDataXtd_GeometryEnum::TDataXtd_SPLINE)
	.value("TDataXtd_PLANE", TDataXtd_GeometryEnum::TDataXtd_PLANE)
	.value("TDataXtd_CYLINDER", TDataXtd_GeometryEnum::TDataXtd_CYLINDER)
	.export_values();


}