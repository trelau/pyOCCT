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

void bind_ChFi3d_FilletShape(py::module &);
void bind_ChFi3d_Builder(py::module &);
void bind_ChFi3d_ChBuilder(py::module &);
void bind_ChFi3d_FilBuilder(py::module &);
void bind_ChFi3d(py::module &);
void bind_ChFi3d_SearchSing(py::module &);

PYBIND11_MODULE(ChFi3d, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.ChFiDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopOpeBRepBuild");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.math");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BRepBlend");
py::module::import("OCCT.Blend");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.AppBlend");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TopOpeBRepDS");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.Law");
py::module::import("OCCT.BlendFunc");

bind_ChFi3d_FilletShape(mod);
bind_ChFi3d_Builder(mod);
bind_ChFi3d_ChBuilder(mod);
bind_ChFi3d_FilBuilder(mod);
bind_ChFi3d(mod);
bind_ChFi3d_SearchSing(mod);

}
