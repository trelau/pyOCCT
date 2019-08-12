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

void bind_BRepLib_EdgeError(py::module &);
void bind_BRepLib_ShapeModification(py::module &);
void bind_BRepLib_FaceError(py::module &);
void bind_BRepLib_ShellError(py::module &);
void bind_BRepLib_WireError(py::module &);
void bind_BRepLib_Command(py::module &);
void bind_BRepLib_MakeShape(py::module &);
void bind_BRepLib_MakeEdge(py::module &);
void bind_BRepLib_MakeEdge2d(py::module &);
void bind_BRepLib_MakeFace(py::module &);
void bind_BRepLib_MakePolygon(py::module &);
void bind_BRepLib_MakeShell(py::module &);
void bind_BRepLib_MakeSolid(py::module &);
void bind_BRepLib_MakeVertex(py::module &);
void bind_BRepLib_MakeWire(py::module &);
void bind_BRepLib(py::module &);
void bind_BRepLib_CheckCurveOnSurface(py::module &);
void bind_BRepLib_FindSurface(py::module &);
void bind_BRepLib_FuseEdges(py::module &);

PYBIND11_MODULE(BRepLib, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.GeomLib");
py::module::import("OCCT.TopLoc");

bind_BRepLib_EdgeError(mod);
bind_BRepLib_ShapeModification(mod);
bind_BRepLib_FaceError(mod);
bind_BRepLib_ShellError(mod);
bind_BRepLib_WireError(mod);
bind_BRepLib_Command(mod);
bind_BRepLib_MakeShape(mod);
bind_BRepLib_MakeEdge(mod);
bind_BRepLib_MakeEdge2d(mod);
bind_BRepLib_MakeFace(mod);
bind_BRepLib_MakePolygon(mod);
bind_BRepLib_MakeShell(mod);
bind_BRepLib_MakeSolid(mod);
bind_BRepLib_MakeVertex(mod);
bind_BRepLib_MakeWire(mod);
bind_BRepLib(mod);
bind_BRepLib_CheckCurveOnSurface(mod);
bind_BRepLib_FindSurface(mod);
bind_BRepLib_FuseEdges(mod);

}
