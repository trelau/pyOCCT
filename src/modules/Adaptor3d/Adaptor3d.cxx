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

void bind_Adaptor3d_Curve(py::module &);
void bind_Adaptor3d_CurveOnSurface(py::module &);
void bind_Adaptor3d_CurveOnSurfacePtr(py::module &);
void bind_Adaptor3d_CurvePtr(py::module &);
void bind_Adaptor3d_HCurve(py::module &);
void bind_Adaptor3d_HCurveOnSurface(py::module &);
void bind_Adaptor3d_IsoCurve(py::module &);
void bind_Adaptor3d_HIsoCurve(py::module &);
void bind_Adaptor3d_HSurface(py::module &);
void bind_Adaptor3d_Surface(py::module &);
void bind_Adaptor3d_HSurfaceTool(py::module &);
void bind_Adaptor3d_HVertex(py::module &);
void bind_Adaptor3d_InterFunc(py::module &);
void bind_Adaptor3d_SurfacePtr(py::module &);
void bind_Adaptor3d_TopolTool(py::module &);

PYBIND11_MODULE(Adaptor3d, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.math");

bind_Adaptor3d_Curve(mod);
bind_Adaptor3d_CurveOnSurface(mod);
bind_Adaptor3d_CurveOnSurfacePtr(mod);
bind_Adaptor3d_CurvePtr(mod);
bind_Adaptor3d_HCurve(mod);
bind_Adaptor3d_HCurveOnSurface(mod);
bind_Adaptor3d_IsoCurve(mod);
bind_Adaptor3d_HIsoCurve(mod);
bind_Adaptor3d_HSurface(mod);
bind_Adaptor3d_Surface(mod);
bind_Adaptor3d_HSurfaceTool(mod);
bind_Adaptor3d_HVertex(mod);
bind_Adaptor3d_InterFunc(mod);
bind_Adaptor3d_SurfacePtr(mod);
bind_Adaptor3d_TopolTool(mod);

}
