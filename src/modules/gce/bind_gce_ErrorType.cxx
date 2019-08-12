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
#include <gce_ErrorType.hxx>

void bind_gce_ErrorType(py::module &mod){

py::enum_<gce_ErrorType>(mod, "gce_ErrorType", "Indicates the outcome of a construction, i.e. whether it is successful or not, as explained below. gce_Done: Construction was successful. gce_ConfusedPoints: Two points are coincident. gce_NegativeRadius: Radius value is negative. gce_ColinearPoints: Three points are collinear. gce_IntersectionError: Intersection cannot be computed. gce_NullAxis: Axis is undefined. gce_NullAngle: Angle value is invalid (usually null). gce_NullRadius: Radius is null. gce_InvertAxis: Axis value is invalid. gce_BadAngle: Angle value is invalid. gce_InvertRadius: Radius value is incorrect (usually with respect to another radius). gce_NullFocusLength: Focal distance is null. gce_NullVector: Vector is null. gce_BadEquation: Coefficients are incorrect (applies to the equation of a geometric object).")
	.value("gce_Done", gce_ErrorType::gce_Done)
	.value("gce_ConfusedPoints", gce_ErrorType::gce_ConfusedPoints)
	.value("gce_NegativeRadius", gce_ErrorType::gce_NegativeRadius)
	.value("gce_ColinearPoints", gce_ErrorType::gce_ColinearPoints)
	.value("gce_IntersectionError", gce_ErrorType::gce_IntersectionError)
	.value("gce_NullAxis", gce_ErrorType::gce_NullAxis)
	.value("gce_NullAngle", gce_ErrorType::gce_NullAngle)
	.value("gce_NullRadius", gce_ErrorType::gce_NullRadius)
	.value("gce_InvertAxis", gce_ErrorType::gce_InvertAxis)
	.value("gce_BadAngle", gce_ErrorType::gce_BadAngle)
	.value("gce_InvertRadius", gce_ErrorType::gce_InvertRadius)
	.value("gce_NullFocusLength", gce_ErrorType::gce_NullFocusLength)
	.value("gce_NullVector", gce_ErrorType::gce_NullVector)
	.value("gce_BadEquation", gce_ErrorType::gce_BadEquation)
	.export_values();


}