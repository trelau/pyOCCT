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

void bind_GeomConvert(py::module &);
void bind_GeomConvert_ApproxCurve(py::module &);
void bind_GeomConvert_ApproxSurface(py::module &);
void bind_GeomConvert_BSplineCurveKnotSplitting(py::module &);
void bind_GeomConvert_BSplineCurveToBezierCurve(py::module &);
void bind_GeomConvert_BSplineSurfaceKnotSplitting(py::module &);
void bind_GeomConvert_BSplineSurfaceToBezierSurface(py::module &);
void bind_GeomConvert_CompBezierSurfacesToBSplineSurface(py::module &);
void bind_GeomConvert_CompCurveToBSplineCurve(py::module &);

PYBIND11_MODULE(GeomConvert, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Convert");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.TColgp");

bind_GeomConvert(mod);
bind_GeomConvert_ApproxCurve(mod);
bind_GeomConvert_ApproxSurface(mod);
bind_GeomConvert_BSplineCurveKnotSplitting(mod);
bind_GeomConvert_BSplineCurveToBezierCurve(mod);
bind_GeomConvert_BSplineSurfaceKnotSplitting(mod);
bind_GeomConvert_BSplineSurfaceToBezierSurface(mod);
bind_GeomConvert_CompBezierSurfacesToBSplineSurface(mod);
bind_GeomConvert_CompCurveToBSplineCurve(mod);

}
