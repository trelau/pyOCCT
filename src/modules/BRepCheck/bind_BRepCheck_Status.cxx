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
#include <BRepCheck_Status.hxx>

void bind_BRepCheck_Status(py::module &mod){

py::enum_<BRepCheck_Status>(mod, "BRepCheck_Status", "None")
	.value("BRepCheck_NoError", BRepCheck_Status::BRepCheck_NoError)
	.value("BRepCheck_InvalidPointOnCurve", BRepCheck_Status::BRepCheck_InvalidPointOnCurve)
	.value("BRepCheck_InvalidPointOnCurveOnSurface", BRepCheck_Status::BRepCheck_InvalidPointOnCurveOnSurface)
	.value("BRepCheck_InvalidPointOnSurface", BRepCheck_Status::BRepCheck_InvalidPointOnSurface)
	.value("BRepCheck_No3DCurve", BRepCheck_Status::BRepCheck_No3DCurve)
	.value("BRepCheck_Multiple3DCurve", BRepCheck_Status::BRepCheck_Multiple3DCurve)
	.value("BRepCheck_Invalid3DCurve", BRepCheck_Status::BRepCheck_Invalid3DCurve)
	.value("BRepCheck_NoCurveOnSurface", BRepCheck_Status::BRepCheck_NoCurveOnSurface)
	.value("BRepCheck_InvalidCurveOnSurface", BRepCheck_Status::BRepCheck_InvalidCurveOnSurface)
	.value("BRepCheck_InvalidCurveOnClosedSurface", BRepCheck_Status::BRepCheck_InvalidCurveOnClosedSurface)
	.value("BRepCheck_InvalidSameRangeFlag", BRepCheck_Status::BRepCheck_InvalidSameRangeFlag)
	.value("BRepCheck_InvalidSameParameterFlag", BRepCheck_Status::BRepCheck_InvalidSameParameterFlag)
	.value("BRepCheck_InvalidDegeneratedFlag", BRepCheck_Status::BRepCheck_InvalidDegeneratedFlag)
	.value("BRepCheck_FreeEdge", BRepCheck_Status::BRepCheck_FreeEdge)
	.value("BRepCheck_InvalidMultiConnexity", BRepCheck_Status::BRepCheck_InvalidMultiConnexity)
	.value("BRepCheck_InvalidRange", BRepCheck_Status::BRepCheck_InvalidRange)
	.value("BRepCheck_EmptyWire", BRepCheck_Status::BRepCheck_EmptyWire)
	.value("BRepCheck_RedundantEdge", BRepCheck_Status::BRepCheck_RedundantEdge)
	.value("BRepCheck_SelfIntersectingWire", BRepCheck_Status::BRepCheck_SelfIntersectingWire)
	.value("BRepCheck_NoSurface", BRepCheck_Status::BRepCheck_NoSurface)
	.value("BRepCheck_InvalidWire", BRepCheck_Status::BRepCheck_InvalidWire)
	.value("BRepCheck_RedundantWire", BRepCheck_Status::BRepCheck_RedundantWire)
	.value("BRepCheck_IntersectingWires", BRepCheck_Status::BRepCheck_IntersectingWires)
	.value("BRepCheck_InvalidImbricationOfWires", BRepCheck_Status::BRepCheck_InvalidImbricationOfWires)
	.value("BRepCheck_EmptyShell", BRepCheck_Status::BRepCheck_EmptyShell)
	.value("BRepCheck_RedundantFace", BRepCheck_Status::BRepCheck_RedundantFace)
	.value("BRepCheck_InvalidImbricationOfShells", BRepCheck_Status::BRepCheck_InvalidImbricationOfShells)
	.value("BRepCheck_UnorientableShape", BRepCheck_Status::BRepCheck_UnorientableShape)
	.value("BRepCheck_NotClosed", BRepCheck_Status::BRepCheck_NotClosed)
	.value("BRepCheck_NotConnected", BRepCheck_Status::BRepCheck_NotConnected)
	.value("BRepCheck_SubshapeNotInShape", BRepCheck_Status::BRepCheck_SubshapeNotInShape)
	.value("BRepCheck_BadOrientation", BRepCheck_Status::BRepCheck_BadOrientation)
	.value("BRepCheck_BadOrientationOfSubshape", BRepCheck_Status::BRepCheck_BadOrientationOfSubshape)
	.value("BRepCheck_InvalidPolygonOnTriangulation", BRepCheck_Status::BRepCheck_InvalidPolygonOnTriangulation)
	.value("BRepCheck_InvalidToleranceValue", BRepCheck_Status::BRepCheck_InvalidToleranceValue)
	.value("BRepCheck_EnclosedRegion", BRepCheck_Status::BRepCheck_EnclosedRegion)
	.value("BRepCheck_CheckFail", BRepCheck_Status::BRepCheck_CheckFail)
	.export_values();


}