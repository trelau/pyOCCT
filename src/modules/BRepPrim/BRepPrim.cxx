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

void bind_BRepPrim_Direction(py::module &);
void bind_BRepPrim_Builder(py::module &);
void bind_BRepPrim_GWedge(py::module &);
void bind_BRepPrim_Wedge(py::module &);
void bind_BRepPrim_OneAxis(py::module &);
void bind_BRepPrim_Revolution(py::module &);
void bind_BRepPrim_Cone(py::module &);
void bind_BRepPrim_Cylinder(py::module &);
void bind_BRepPrim_Sphere(py::module &);
void bind_BRepPrim_Torus(py::module &);
void bind_BRepPrim_FaceBuilder(py::module &);

PYBIND11_MODULE(BRepPrim, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.BRep");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");

bind_BRepPrim_Direction(mod);
bind_BRepPrim_Builder(mod);
bind_BRepPrim_GWedge(mod);
bind_BRepPrim_Wedge(mod);
bind_BRepPrim_OneAxis(mod);
bind_BRepPrim_Revolution(mod);
bind_BRepPrim_Cone(mod);
bind_BRepPrim_Cylinder(mod);
bind_BRepPrim_Sphere(mod);
bind_BRepPrim_Torus(mod);
bind_BRepPrim_FaceBuilder(mod);

}
