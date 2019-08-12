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

void bind_Geom_Geometry(py::module &);
void bind_Geom_Curve(py::module &);
void bind_Geom_Surface(py::module &);
void bind_Geom_BoundedSurface(py::module &);
void bind_Geom_BezierSurface(py::module &);
void bind_Geom_BSplineSurface(py::module &);
void bind_Geom_Transformation(py::module &);
void bind_Geom_ElementarySurface(py::module &);
void bind_Geom_Plane(py::module &);
void bind_Geom_Line(py::module &);
void bind_Geom_BoundedCurve(py::module &);
void bind_Geom_BSplineCurve(py::module &);
void bind_Geom_BezierCurve(py::module &);
void bind_Geom_TrimmedCurve(py::module &);
void bind_Geom_Conic(py::module &);
void bind_Geom_Circle(py::module &);
void bind_Geom_ConicalSurface(py::module &);
void bind_Geom_CylindricalSurface(py::module &);
void bind_Geom_Ellipse(py::module &);
void bind_Geom_Hyperbola(py::module &);
void bind_Geom_RectangularTrimmedSurface(py::module &);
void bind_Geom_SequenceOfBSplineSurface(py::module &);
void bind_Geom_HSequenceOfBSplineSurface(py::module &);
void bind_Geom_OsculatingSurface(py::module &);
void bind_Geom_AxisPlacement(py::module &);
void bind_Geom_Axis1Placement(py::module &);
void bind_Geom_Axis2Placement(py::module &);
void bind_Geom_Point(py::module &);
void bind_Geom_CartesianPoint(py::module &);
void bind_Geom_Vector(py::module &);
void bind_Geom_Direction(py::module &);
void bind_Geom_OffsetCurve(py::module &);
void bind_Geom_OffsetSurface(py::module &);
void bind_Geom_Parabola(py::module &);
void bind_Geom_SphericalSurface(py::module &);
void bind_Geom_SweptSurface(py::module &);
void bind_Geom_SurfaceOfLinearExtrusion(py::module &);
void bind_Geom_SurfaceOfRevolution(py::module &);
void bind_Geom_ToroidalSurface(py::module &);
void bind_Geom_UndefinedDerivative(py::module &);
void bind_Geom_UndefinedValue(py::module &);
void bind_Geom_VectorWithMagnitude(py::module &);

PYBIND11_MODULE(Geom, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.BSplSLib");
py::module::import("OCCT.BSplCLib");
py::module::import("OCCT.NCollection");

bind_Geom_Geometry(mod);
bind_Geom_Curve(mod);
bind_Geom_Surface(mod);
bind_Geom_BoundedSurface(mod);
bind_Geom_BezierSurface(mod);
bind_Geom_BSplineSurface(mod);
bind_Geom_Transformation(mod);
bind_Geom_ElementarySurface(mod);
bind_Geom_Plane(mod);
bind_Geom_Line(mod);
bind_Geom_BoundedCurve(mod);
bind_Geom_BSplineCurve(mod);
bind_Geom_BezierCurve(mod);
bind_Geom_TrimmedCurve(mod);
bind_Geom_Conic(mod);
bind_Geom_Circle(mod);
bind_Geom_ConicalSurface(mod);
bind_Geom_CylindricalSurface(mod);
bind_Geom_Ellipse(mod);
bind_Geom_Hyperbola(mod);
bind_Geom_RectangularTrimmedSurface(mod);
bind_Geom_SequenceOfBSplineSurface(mod);
bind_Geom_HSequenceOfBSplineSurface(mod);
bind_Geom_OsculatingSurface(mod);
bind_Geom_AxisPlacement(mod);
bind_Geom_Axis1Placement(mod);
bind_Geom_Axis2Placement(mod);
bind_Geom_Point(mod);
bind_Geom_CartesianPoint(mod);
bind_Geom_Vector(mod);
bind_Geom_Direction(mod);
bind_Geom_OffsetCurve(mod);
bind_Geom_OffsetSurface(mod);
bind_Geom_Parabola(mod);
bind_Geom_SphericalSurface(mod);
bind_Geom_SweptSurface(mod);
bind_Geom_SurfaceOfLinearExtrusion(mod);
bind_Geom_SurfaceOfRevolution(mod);
bind_Geom_ToroidalSurface(mod);
bind_Geom_UndefinedDerivative(mod);
bind_Geom_UndefinedValue(mod);
bind_Geom_VectorWithMagnitude(mod);

}
