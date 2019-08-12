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

void bind_ShapeUpgrade(py::module &);
void bind_ShapeUpgrade_Tool(py::module &);
void bind_ShapeUpgrade_EdgeDivide(py::module &);
void bind_ShapeUpgrade_ClosedEdgeDivide(py::module &);
void bind_ShapeUpgrade_FaceDivide(py::module &);
void bind_ShapeUpgrade_ClosedFaceDivide(py::module &);
void bind_ShapeUpgrade_SplitCurve(py::module &);
void bind_ShapeUpgrade_SplitCurve2d(py::module &);
void bind_ShapeUpgrade_ConvertCurve2dToBezier(py::module &);
void bind_ShapeUpgrade_SplitCurve3d(py::module &);
void bind_ShapeUpgrade_ConvertCurve3dToBezier(py::module &);
void bind_ShapeUpgrade_SplitSurface(py::module &);
void bind_ShapeUpgrade_ConvertSurfaceToBezierBasis(py::module &);
void bind_ShapeUpgrade_FaceDivideArea(py::module &);
void bind_ShapeUpgrade_FixSmallCurves(py::module &);
void bind_ShapeUpgrade_FixSmallBezierCurves(py::module &);
void bind_ShapeUpgrade_RemoveInternalWires(py::module &);
void bind_ShapeUpgrade_RemoveLocations(py::module &);
void bind_ShapeUpgrade_ShapeDivide(py::module &);
void bind_ShapeUpgrade_ShapeConvertToBezier(py::module &);
void bind_ShapeUpgrade_ShapeDivideAngle(py::module &);
void bind_ShapeUpgrade_ShapeDivideArea(py::module &);
void bind_ShapeUpgrade_ShapeDivideClosed(py::module &);
void bind_ShapeUpgrade_ShapeDivideClosedEdges(py::module &);
void bind_ShapeUpgrade_ShapeDivideContinuity(py::module &);
void bind_ShapeUpgrade_ShellSewing(py::module &);
void bind_ShapeUpgrade_SplitCurve2dContinuity(py::module &);
void bind_ShapeUpgrade_SplitCurve3dContinuity(py::module &);
void bind_ShapeUpgrade_SplitSurfaceAngle(py::module &);
void bind_ShapeUpgrade_SplitSurfaceArea(py::module &);
void bind_ShapeUpgrade_SplitSurfaceContinuity(py::module &);
void bind_ShapeUpgrade_UnifySameDomain(py::module &);
void bind_ShapeUpgrade_WireDivide(py::module &);

PYBIND11_MODULE(ShapeUpgrade, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColGeom2d");
py::module::import("OCCT.ShapeBuild");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.ShapeExtend");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Message");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.ShapeAnalysis");

bind_ShapeUpgrade(mod);
bind_ShapeUpgrade_Tool(mod);
bind_ShapeUpgrade_EdgeDivide(mod);
bind_ShapeUpgrade_ClosedEdgeDivide(mod);
bind_ShapeUpgrade_FaceDivide(mod);
bind_ShapeUpgrade_ClosedFaceDivide(mod);
bind_ShapeUpgrade_SplitCurve(mod);
bind_ShapeUpgrade_SplitCurve2d(mod);
bind_ShapeUpgrade_ConvertCurve2dToBezier(mod);
bind_ShapeUpgrade_SplitCurve3d(mod);
bind_ShapeUpgrade_ConvertCurve3dToBezier(mod);
bind_ShapeUpgrade_SplitSurface(mod);
bind_ShapeUpgrade_ConvertSurfaceToBezierBasis(mod);
bind_ShapeUpgrade_FaceDivideArea(mod);
bind_ShapeUpgrade_FixSmallCurves(mod);
bind_ShapeUpgrade_FixSmallBezierCurves(mod);
bind_ShapeUpgrade_RemoveInternalWires(mod);
bind_ShapeUpgrade_RemoveLocations(mod);
bind_ShapeUpgrade_ShapeDivide(mod);
bind_ShapeUpgrade_ShapeConvertToBezier(mod);
bind_ShapeUpgrade_ShapeDivideAngle(mod);
bind_ShapeUpgrade_ShapeDivideArea(mod);
bind_ShapeUpgrade_ShapeDivideClosed(mod);
bind_ShapeUpgrade_ShapeDivideClosedEdges(mod);
bind_ShapeUpgrade_ShapeDivideContinuity(mod);
bind_ShapeUpgrade_ShellSewing(mod);
bind_ShapeUpgrade_SplitCurve2dContinuity(mod);
bind_ShapeUpgrade_SplitCurve3dContinuity(mod);
bind_ShapeUpgrade_SplitSurfaceAngle(mod);
bind_ShapeUpgrade_SplitSurfaceArea(mod);
bind_ShapeUpgrade_SplitSurfaceContinuity(mod);
bind_ShapeUpgrade_UnifySameDomain(mod);
bind_ShapeUpgrade_WireDivide(mod);

}
