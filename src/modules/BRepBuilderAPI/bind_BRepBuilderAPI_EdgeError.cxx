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
#include <BRepBuilderAPI_EdgeError.hxx>

void bind_BRepBuilderAPI_EdgeError(py::module &mod){

py::enum_<BRepBuilderAPI_EdgeError>(mod, "BRepBuilderAPI_EdgeError", "Indicates the outcome of the construction of an edge, i.e. whether it has been successful or not, as explained below: - BRepBuilderAPI_EdgeDone No error occurred; The edge is correctly built. - BRepBuilderAPI_PointProjectionFailed No parameters were given but the projection of the 3D points on the curve failed. This happens when the point distance to the curve is greater than the precision value. - BRepBuilderAPI_ParameterOutOfRange The given parameters are not in the parametric range C->FirstParameter(), C->LastParameter() - BRepBuilderAPI_DifferentPointsOnClosedCurve The two vertices or points are the extremities of a closed curve but have different locations. - BRepBuilderAPI_PointWithInfiniteParameter A finite coordinate point was associated with an infinite parameter (see the Precision package for a definition of infinite values). - BRepBuilderAPI_DifferentsPointAndParameter The distance between the 3D point and the point evaluated on the curve with the parameter is greater than the precision. - BRepBuilderAPI_LineThroughIdenticPoints Two identical points were given to define a line (construction of an edge without curve); gp::Resolution is used for the confusion test.")
	.value("BRepBuilderAPI_EdgeDone", BRepBuilderAPI_EdgeError::BRepBuilderAPI_EdgeDone)
	.value("BRepBuilderAPI_PointProjectionFailed", BRepBuilderAPI_EdgeError::BRepBuilderAPI_PointProjectionFailed)
	.value("BRepBuilderAPI_ParameterOutOfRange", BRepBuilderAPI_EdgeError::BRepBuilderAPI_ParameterOutOfRange)
	.value("BRepBuilderAPI_DifferentPointsOnClosedCurve", BRepBuilderAPI_EdgeError::BRepBuilderAPI_DifferentPointsOnClosedCurve)
	.value("BRepBuilderAPI_PointWithInfiniteParameter", BRepBuilderAPI_EdgeError::BRepBuilderAPI_PointWithInfiniteParameter)
	.value("BRepBuilderAPI_DifferentsPointAndParameter", BRepBuilderAPI_EdgeError::BRepBuilderAPI_DifferentsPointAndParameter)
	.value("BRepBuilderAPI_LineThroughIdenticPoints", BRepBuilderAPI_EdgeError::BRepBuilderAPI_LineThroughIdenticPoints)
	.export_values();


}