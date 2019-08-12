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
#include <IntAna_ResultType.hxx>

void bind_IntAna_ResultType(py::module &mod){

py::enum_<IntAna_ResultType>(mod, "IntAna_ResultType", "None")
	.value("IntAna_Point", IntAna_ResultType::IntAna_Point)
	.value("IntAna_Line", IntAna_ResultType::IntAna_Line)
	.value("IntAna_Circle", IntAna_ResultType::IntAna_Circle)
	.value("IntAna_PointAndCircle", IntAna_ResultType::IntAna_PointAndCircle)
	.value("IntAna_Ellipse", IntAna_ResultType::IntAna_Ellipse)
	.value("IntAna_Parabola", IntAna_ResultType::IntAna_Parabola)
	.value("IntAna_Hyperbola", IntAna_ResultType::IntAna_Hyperbola)
	.value("IntAna_Empty", IntAna_ResultType::IntAna_Empty)
	.value("IntAna_Same", IntAna_ResultType::IntAna_Same)
	.value("IntAna_NoGeometricSolution", IntAna_ResultType::IntAna_NoGeometricSolution)
	.export_values();


}