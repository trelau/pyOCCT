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

void bind_BiTgte_ContactType(py::module &);
void bind_BiTgte_Blend(py::module &);
void bind_BiTgte_CurveOnEdge(py::module &);
void bind_BiTgte_CurveOnVertex(py::module &);
void bind_BiTgte_HCurveOnEdge(py::module &);
void bind_BiTgte_HCurveOnVertex(py::module &);

PYBIND11_MODULE(BiTgte, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.BRepOffset");
py::module::import("OCCT.BRepFill");
py::module::import("OCCT.BRepAlgo");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.gp");

bind_BiTgte_ContactType(mod);
bind_BiTgte_Blend(mod);
bind_BiTgte_CurveOnEdge(mod);
bind_BiTgte_CurveOnVertex(mod);
bind_BiTgte_HCurveOnEdge(mod);
bind_BiTgte_HCurveOnVertex(mod);

}
