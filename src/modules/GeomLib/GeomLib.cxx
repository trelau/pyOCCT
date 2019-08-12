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

void bind_GeomLib_InterpolationErrors(py::module &);
void bind_GeomLib_CheckCurveOnSurface(py::module &);
void bind_GeomLib(py::module &);
void bind_GeomLib_Array1OfMat(py::module &);
void bind_GeomLib_Check2dBSplineCurve(py::module &);
void bind_GeomLib_CheckBSplineCurve(py::module &);
void bind_GeomLib_DenominatorMultiplier(py::module &);
void bind_GeomLib_DenominatorMultiplierPtr(py::module &);
void bind_GeomLib_Interpolate(py::module &);
void bind_GeomLib_IsPlanarSurface(py::module &);
void bind_GeomLib_LogSample(py::module &);
void bind_GeomLib_MakeCurvefromApprox(py::module &);
void bind_GeomLib_PolyFunc(py::module &);
void bind_GeomLib_Tool(py::module &);

PYBIND11_MODULE(GeomLib, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Precision");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.math");
py::module::import("OCCT.AdvApprox");

bind_GeomLib_InterpolationErrors(mod);
bind_GeomLib_CheckCurveOnSurface(mod);
bind_GeomLib(mod);
bind_GeomLib_Array1OfMat(mod);
bind_GeomLib_Check2dBSplineCurve(mod);
bind_GeomLib_CheckBSplineCurve(mod);
bind_GeomLib_DenominatorMultiplier(mod);
bind_GeomLib_DenominatorMultiplierPtr(mod);
bind_GeomLib_Interpolate(mod);
bind_GeomLib_IsPlanarSurface(mod);
bind_GeomLib_LogSample(mod);
bind_GeomLib_MakeCurvefromApprox(mod);
bind_GeomLib_PolyFunc(mod);
bind_GeomLib_Tool(mod);

}
