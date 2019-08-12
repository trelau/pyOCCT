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

void bind_BRepPrimAPI_MakeSweep(py::module &);
void bind_BRepPrimAPI_MakeBox(py::module &);
void bind_BRepPrimAPI_MakeOneAxis(py::module &);
void bind_BRepPrimAPI_MakeCone(py::module &);
void bind_BRepPrimAPI_MakeCylinder(py::module &);
void bind_BRepPrimAPI_MakeHalfSpace(py::module &);
void bind_BRepPrimAPI_MakePrism(py::module &);
void bind_BRepPrimAPI_MakeRevol(py::module &);
void bind_BRepPrimAPI_MakeRevolution(py::module &);
void bind_BRepPrimAPI_MakeSphere(py::module &);
void bind_BRepPrimAPI_MakeTorus(py::module &);
void bind_BRepPrimAPI_MakeWedge(py::module &);

PYBIND11_MODULE(BRepPrimAPI, mod) {

py::module::import("OCCT.BRepBuilderAPI");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.BRepPrim");
py::module::import("OCCT.BRepSweep");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Geom");

bind_BRepPrimAPI_MakeSweep(mod);
bind_BRepPrimAPI_MakeBox(mod);
bind_BRepPrimAPI_MakeOneAxis(mod);
bind_BRepPrimAPI_MakeCone(mod);
bind_BRepPrimAPI_MakeCylinder(mod);
bind_BRepPrimAPI_MakeHalfSpace(mod);
bind_BRepPrimAPI_MakePrism(mod);
bind_BRepPrimAPI_MakeRevol(mod);
bind_BRepPrimAPI_MakeRevolution(mod);
bind_BRepPrimAPI_MakeSphere(mod);
bind_BRepPrimAPI_MakeTorus(mod);
bind_BRepPrimAPI_MakeWedge(mod);

}
