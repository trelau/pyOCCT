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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColGeom_HSequenceOfBoundedCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <TColGeom2d_HSequenceOfBoundedCurve.hxx>
#include <ShapeUpgrade_Tool.hxx>
#include <ShapeUpgrade_EdgeDivide.hxx>
#include <ShapeUpgrade_ClosedEdgeDivide.hxx>
#include <ShapeUpgrade_WireDivide.hxx>
#include <ShapeUpgrade_FaceDivide.hxx>
#include <ShapeUpgrade_ClosedFaceDivide.hxx>
#include <ShapeUpgrade_FaceDivideArea.hxx>
#include <ShapeUpgrade_ShapeDivide.hxx>
#include <ShapeUpgrade_ShapeDivideArea.hxx>
#include <ShapeUpgrade_ShapeDivideContinuity.hxx>
#include <ShapeUpgrade_ShapeDivideAngle.hxx>
#include <ShapeUpgrade_ShapeConvertToBezier.hxx>
#include <ShapeUpgrade_ShapeDivideClosed.hxx>
#include <ShapeUpgrade_ShapeDivideClosedEdges.hxx>
#include <ShapeUpgrade_SplitCurve.hxx>
#include <ShapeUpgrade_SplitCurve2d.hxx>
#include <ShapeUpgrade_SplitCurve2dContinuity.hxx>
#include <ShapeUpgrade_ConvertCurve2dToBezier.hxx>
#include <ShapeUpgrade_SplitCurve3d.hxx>
#include <ShapeUpgrade_SplitCurve3dContinuity.hxx>
#include <ShapeUpgrade_ConvertCurve3dToBezier.hxx>
#include <ShapeUpgrade_SplitSurface.hxx>
#include <ShapeUpgrade_SplitSurfaceContinuity.hxx>
#include <ShapeUpgrade_SplitSurfaceAngle.hxx>
#include <ShapeUpgrade_ConvertSurfaceToBezierBasis.hxx>
#include <ShapeUpgrade_SplitSurfaceArea.hxx>
#include <ShapeUpgrade_ShellSewing.hxx>
#include <ShapeUpgrade_FixSmallCurves.hxx>
#include <ShapeUpgrade_FixSmallBezierCurves.hxx>
#include <ShapeUpgrade_RemoveLocations.hxx>
#include <ShapeUpgrade_RemoveInternalWires.hxx>
#include <ShapeUpgrade_UnifySameDomain.hxx>
#include <ShapeUpgrade.hxx>

void bind_ShapeUpgrade(py::module &mod){

py::class_<ShapeUpgrade> cls_ShapeUpgrade(mod, "ShapeUpgrade", "This package provides tools for splitting and converting shapes by some criteria. It provides modifications of the kind when one topological object can be converted or splitted to several ones. In particular this package contains high level API classes which perform: converting geometry of shapes up to given continuity, splitting revolutions by U to segments less than given value, converting to beziers, splitting closed faces.");

// Constructors

// Fields

// Methods
// cls_ShapeUpgrade.def_static("operator new_", (void * (*)(size_t)) &ShapeUpgrade::operator new, "None", py::arg("theSize"));
// cls_ShapeUpgrade.def_static("operator delete_", (void (*)(void *)) &ShapeUpgrade::operator delete, "None", py::arg("theAddress"));
// cls_ShapeUpgrade.def_static("operator new[]_", (void * (*)(size_t)) &ShapeUpgrade::operator new[], "None", py::arg("theSize"));
// cls_ShapeUpgrade.def_static("operator delete[]_", (void (*)(void *)) &ShapeUpgrade::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeUpgrade.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeUpgrade::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeUpgrade.def_static("operator delete_", (void (*)(void *, void *)) &ShapeUpgrade::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeUpgrade.def_static("C0BSplineToSequenceOfC1BSplineCurve_", (Standard_Boolean (*)(const opencascade::handle<Geom_BSplineCurve> &, opencascade::handle<TColGeom_HSequenceOfBoundedCurve> &)) &ShapeUpgrade::C0BSplineToSequenceOfC1BSplineCurve, "Unifies same domain faces and edges of specified shape", py::arg("BS"), py::arg("seqBS"));
cls_ShapeUpgrade.def_static("C0BSplineToSequenceOfC1BSplineCurve_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_BSplineCurve> &, opencascade::handle<TColGeom2d_HSequenceOfBoundedCurve> &)) &ShapeUpgrade::C0BSplineToSequenceOfC1BSplineCurve, "Converts C0 B-Spline curve into sequence of C1 B-Spline curves. This method splits B-Spline at the knots with multiplicities equal to degree, i.e. unlike method GeomConvert::C0BSplineToArrayOfC1BSplineCurve this one does not use any tolerance and therefore does not change the geometry of B-Spline. Returns True if C0 B-Spline was successfully splitted, else returns False (if BS is C1 B-Spline).", py::arg("BS"), py::arg("seqBS"));

// Enums

}