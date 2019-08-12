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

void bind_ShapePersistent_TriangleMode(py::module &);
void bind_ShapePersistent(py::module &);
void bind_ShapePersistent_TopoDS(py::module &);
void bind_ShapePersistent_Geom(py::module &);
void bind_ShapePersistent_Geom2d(py::module &);
void bind_ShapePersistent_HArray1(py::module &);
void bind_ShapePersistent_Poly(py::module &);
void bind_ShapePersistent_BRep(py::module &);
void bind_ShapePersistent_Geom2d_Curve(py::module &);
void bind_ShapePersistent_Geom_Curve(py::module &);
void bind_ShapePersistent_HArray2(py::module &);
void bind_ShapePersistent_Geom_Surface(py::module &);
void bind_ShapePersistent_HSequence(py::module &);

PYBIND11_MODULE(ShapePersistent, mod) {

py::module::import("OCCT.StdObjMgt");
py::module::import("OCCT.StdPersistent");
py::module::import("OCCT.StdObject");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.StdLPersistent");
py::module::import("OCCT.Geom");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Poly");
py::module::import("OCCT.BRep");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.GeomAbs");

bind_ShapePersistent_TriangleMode(mod);
bind_ShapePersistent(mod);
bind_ShapePersistent_TopoDS(mod);
bind_ShapePersistent_Geom(mod);
bind_ShapePersistent_Geom2d(mod);
bind_ShapePersistent_HArray1(mod);
bind_ShapePersistent_Poly(mod);
bind_ShapePersistent_BRep(mod);
bind_ShapePersistent_Geom2d_Curve(mod);
bind_ShapePersistent_Geom_Curve(mod);
bind_ShapePersistent_HArray2(mod);
bind_ShapePersistent_Geom_Surface(mod);
bind_ShapePersistent_HSequence(mod);

}
