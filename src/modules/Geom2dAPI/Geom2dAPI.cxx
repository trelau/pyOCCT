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

void bind_Geom2dAPI_ExtremaCurveCurve(py::module &);
void bind_Geom2dAPI_InterCurveCurve(py::module &);
void bind_Geom2dAPI_Interpolate(py::module &);
void bind_Geom2dAPI_PointsToBSpline(py::module &);
void bind_Geom2dAPI_ProjectPointOnCurve(py::module &);

PYBIND11_MODULE(Geom2dAPI, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.Geom2dInt");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Approx");

bind_Geom2dAPI_ExtremaCurveCurve(mod);
bind_Geom2dAPI_InterCurveCurve(mod);
bind_Geom2dAPI_Interpolate(mod);
bind_Geom2dAPI_PointsToBSpline(mod);
bind_Geom2dAPI_ProjectPointOnCurve(mod);

}
