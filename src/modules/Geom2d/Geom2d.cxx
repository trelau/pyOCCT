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

void bind_Geom2d_Geometry(py::module &);
void bind_Geom2d_Curve(py::module &);
void bind_Geom2d_BoundedCurve(py::module &);
void bind_Geom2d_BezierCurve(py::module &);
void bind_Geom2d_BSplineCurve(py::module &);
void bind_Geom2d_TrimmedCurve(py::module &);
void bind_Geom2d_Conic(py::module &);
void bind_Geom2d_Circle(py::module &);
void bind_Geom2d_Ellipse(py::module &);
void bind_Geom2d_Hyperbola(py::module &);
void bind_Geom2d_Line(py::module &);
void bind_Geom2d_Parabola(py::module &);
void bind_Geom2d_AxisPlacement(py::module &);
void bind_Geom2d_Point(py::module &);
void bind_Geom2d_CartesianPoint(py::module &);
void bind_Geom2d_Vector(py::module &);
void bind_Geom2d_Direction(py::module &);
void bind_Geom2d_OffsetCurve(py::module &);
void bind_Geom2d_Transformation(py::module &);
void bind_Geom2d_UndefinedDerivative(py::module &);
void bind_Geom2d_UndefinedValue(py::module &);
void bind_Geom2d_VectorWithMagnitude(py::module &);

PYBIND11_MODULE(Geom2d, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.BSplCLib");

bind_Geom2d_Geometry(mod);
bind_Geom2d_Curve(mod);
bind_Geom2d_BoundedCurve(mod);
bind_Geom2d_BezierCurve(mod);
bind_Geom2d_BSplineCurve(mod);
bind_Geom2d_TrimmedCurve(mod);
bind_Geom2d_Conic(mod);
bind_Geom2d_Circle(mod);
bind_Geom2d_Ellipse(mod);
bind_Geom2d_Hyperbola(mod);
bind_Geom2d_Line(mod);
bind_Geom2d_Parabola(mod);
bind_Geom2d_AxisPlacement(mod);
bind_Geom2d_Point(mod);
bind_Geom2d_CartesianPoint(mod);
bind_Geom2d_Vector(mod);
bind_Geom2d_Direction(mod);
bind_Geom2d_OffsetCurve(mod);
bind_Geom2d_Transformation(mod);
bind_Geom2d_UndefinedDerivative(mod);
bind_Geom2d_UndefinedValue(mod);
bind_Geom2d_VectorWithMagnitude(mod);

}
