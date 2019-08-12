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

void bind_GeomToStep_Root(py::module &);
void bind_GeomToStep_MakeAxis1Placement(py::module &);
void bind_GeomToStep_MakeAxis2Placement2d(py::module &);
void bind_GeomToStep_MakeAxis2Placement3d(py::module &);
void bind_GeomToStep_MakeBoundedCurve(py::module &);
void bind_GeomToStep_MakeBoundedSurface(py::module &);
void bind_GeomToStep_MakeBSplineCurveWithKnots(py::module &);
void bind_GeomToStep_MakeBSplineCurveWithKnotsAndRationalBSplineCurve(py::module &);
void bind_GeomToStep_MakeBSplineSurfaceWithKnots(py::module &);
void bind_GeomToStep_MakeBSplineSurfaceWithKnotsAndRationalBSplineSurface(py::module &);
void bind_GeomToStep_MakeCartesianPoint(py::module &);
void bind_GeomToStep_MakeCircle(py::module &);
void bind_GeomToStep_MakeConic(py::module &);
void bind_GeomToStep_MakeConicalSurface(py::module &);
void bind_GeomToStep_MakeCurve(py::module &);
void bind_GeomToStep_MakeCylindricalSurface(py::module &);
void bind_GeomToStep_MakeDirection(py::module &);
void bind_GeomToStep_MakeElementarySurface(py::module &);
void bind_GeomToStep_MakeEllipse(py::module &);
void bind_GeomToStep_MakeHyperbola(py::module &);
void bind_GeomToStep_MakeLine(py::module &);
void bind_GeomToStep_MakeParabola(py::module &);
void bind_GeomToStep_MakePlane(py::module &);
void bind_GeomToStep_MakePolyline(py::module &);
void bind_GeomToStep_MakeRectangularTrimmedSurface(py::module &);
void bind_GeomToStep_MakeSphericalSurface(py::module &);
void bind_GeomToStep_MakeSurface(py::module &);
void bind_GeomToStep_MakeSurfaceOfLinearExtrusion(py::module &);
void bind_GeomToStep_MakeSurfaceOfRevolution(py::module &);
void bind_GeomToStep_MakeSweptSurface(py::module &);
void bind_GeomToStep_MakeToroidalSurface(py::module &);
void bind_GeomToStep_MakeVector(py::module &);

PYBIND11_MODULE(GeomToStep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.StepGeom");
py::module::import("OCCT.TColgp");

bind_GeomToStep_Root(mod);
bind_GeomToStep_MakeAxis1Placement(mod);
bind_GeomToStep_MakeAxis2Placement2d(mod);
bind_GeomToStep_MakeAxis2Placement3d(mod);
bind_GeomToStep_MakeBoundedCurve(mod);
bind_GeomToStep_MakeBoundedSurface(mod);
bind_GeomToStep_MakeBSplineCurveWithKnots(mod);
bind_GeomToStep_MakeBSplineCurveWithKnotsAndRationalBSplineCurve(mod);
bind_GeomToStep_MakeBSplineSurfaceWithKnots(mod);
bind_GeomToStep_MakeBSplineSurfaceWithKnotsAndRationalBSplineSurface(mod);
bind_GeomToStep_MakeCartesianPoint(mod);
bind_GeomToStep_MakeCircle(mod);
bind_GeomToStep_MakeConic(mod);
bind_GeomToStep_MakeConicalSurface(mod);
bind_GeomToStep_MakeCurve(mod);
bind_GeomToStep_MakeCylindricalSurface(mod);
bind_GeomToStep_MakeDirection(mod);
bind_GeomToStep_MakeElementarySurface(mod);
bind_GeomToStep_MakeEllipse(mod);
bind_GeomToStep_MakeHyperbola(mod);
bind_GeomToStep_MakeLine(mod);
bind_GeomToStep_MakeParabola(mod);
bind_GeomToStep_MakePlane(mod);
bind_GeomToStep_MakePolyline(mod);
bind_GeomToStep_MakeRectangularTrimmedSurface(mod);
bind_GeomToStep_MakeSphericalSurface(mod);
bind_GeomToStep_MakeSurface(mod);
bind_GeomToStep_MakeSurfaceOfLinearExtrusion(mod);
bind_GeomToStep_MakeSurfaceOfRevolution(mod);
bind_GeomToStep_MakeSweptSurface(mod);
bind_GeomToStep_MakeToroidalSurface(mod);
bind_GeomToStep_MakeVector(mod);

}
