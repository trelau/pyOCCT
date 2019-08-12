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
#include <GeomAbs_JoinType.hxx>

void bind_GeomAbs_JoinType(py::module &mod){

py::enum_<GeomAbs_JoinType>(mod, "GeomAbs_JoinType", "Characterizes the type of a join, built by an algorithm for constructing parallel curves, between two consecutive arcs of a contour parallel to a given contour.")
	.value("GeomAbs_Arc", GeomAbs_JoinType::GeomAbs_Arc)
	.value("GeomAbs_Tangent", GeomAbs_JoinType::GeomAbs_Tangent)
	.value("GeomAbs_Intersection", GeomAbs_JoinType::GeomAbs_Intersection)
	.export_values();


}