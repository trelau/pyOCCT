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
#include <GeomAbs_CurveType.hxx>

void bind_GeomAbs_CurveType(py::module &mod){

py::enum_<GeomAbs_CurveType>(mod, "GeomAbs_CurveType", "Identifies the type of a curve.")
	.value("GeomAbs_Line", GeomAbs_CurveType::GeomAbs_Line)
	.value("GeomAbs_Circle", GeomAbs_CurveType::GeomAbs_Circle)
	.value("GeomAbs_Ellipse", GeomAbs_CurveType::GeomAbs_Ellipse)
	.value("GeomAbs_Hyperbola", GeomAbs_CurveType::GeomAbs_Hyperbola)
	.value("GeomAbs_Parabola", GeomAbs_CurveType::GeomAbs_Parabola)
	.value("GeomAbs_BezierCurve", GeomAbs_CurveType::GeomAbs_BezierCurve)
	.value("GeomAbs_BSplineCurve", GeomAbs_CurveType::GeomAbs_BSplineCurve)
	.value("GeomAbs_OffsetCurve", GeomAbs_CurveType::GeomAbs_OffsetCurve)
	.value("GeomAbs_OtherCurve", GeomAbs_CurveType::GeomAbs_OtherCurve)
	.export_values();


}