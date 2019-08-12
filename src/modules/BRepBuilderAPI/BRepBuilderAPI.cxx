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

void bind_BRepBuilderAPI_EdgeError(py::module &);
void bind_BRepBuilderAPI_FaceError(py::module &);
void bind_BRepBuilderAPI_ShellError(py::module &);
void bind_BRepBuilderAPI_WireError(py::module &);
void bind_BRepBuilderAPI_PipeError(py::module &);
void bind_BRepBuilderAPI_ShapeModification(py::module &);
void bind_BRepBuilderAPI_TransitionMode(py::module &);
void bind_BRepBuilderAPI_Command(py::module &);
void bind_BRepBuilderAPI_MakeShape(py::module &);
void bind_BRepBuilderAPI(py::module &);
void bind_BRepBuilderAPI_BndBoxTree(py::module &);
void bind_BRepBuilderAPI_BndBoxTreeSelector(py::module &);
void bind_VectorOfPoint(py::module &);
void bind_BRepBuilderAPI_VertexInspector(py::module &);
void bind_BRepBuilderAPI_CellFilter(py::module &);
void bind_BRepBuilderAPI_Collect(py::module &);
void bind_BRepBuilderAPI_ModifyShape(py::module &);
void bind_BRepBuilderAPI_Copy(py::module &);
void bind_BRepBuilderAPI_FastSewing(py::module &);
void bind_BRepBuilderAPI_FindPlane(py::module &);
void bind_BRepBuilderAPI_GTransform(py::module &);
void bind_BRepBuilderAPI_MakeEdge(py::module &);
void bind_BRepBuilderAPI_MakeEdge2d(py::module &);
void bind_BRepBuilderAPI_MakeFace(py::module &);
void bind_BRepBuilderAPI_MakePolygon(py::module &);
void bind_BRepBuilderAPI_MakeShell(py::module &);
void bind_BRepBuilderAPI_MakeSolid(py::module &);
void bind_BRepBuilderAPI_MakeVertex(py::module &);
void bind_BRepBuilderAPI_MakeWire(py::module &);
void bind_BRepBuilderAPI_NurbsConvert(py::module &);
void bind_BRepBuilderAPI_Sewing(py::module &);
void bind_BRepBuilderAPI_Transform(py::module &);

PYBIND11_MODULE(BRepBuilderAPI, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Geom");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.BRep");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.BRepLib");
py::module::import("OCCT.Message");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TColgp");

bind_BRepBuilderAPI_EdgeError(mod);
bind_BRepBuilderAPI_FaceError(mod);
bind_BRepBuilderAPI_ShellError(mod);
bind_BRepBuilderAPI_WireError(mod);
bind_BRepBuilderAPI_PipeError(mod);
bind_BRepBuilderAPI_ShapeModification(mod);
bind_BRepBuilderAPI_TransitionMode(mod);
bind_BRepBuilderAPI_Command(mod);
bind_BRepBuilderAPI_MakeShape(mod);
bind_BRepBuilderAPI(mod);
bind_BRepBuilderAPI_BndBoxTree(mod);
bind_BRepBuilderAPI_BndBoxTreeSelector(mod);
bind_VectorOfPoint(mod);
bind_BRepBuilderAPI_VertexInspector(mod);
bind_BRepBuilderAPI_CellFilter(mod);
bind_BRepBuilderAPI_Collect(mod);
bind_BRepBuilderAPI_ModifyShape(mod);
bind_BRepBuilderAPI_Copy(mod);
bind_BRepBuilderAPI_FastSewing(mod);
bind_BRepBuilderAPI_FindPlane(mod);
bind_BRepBuilderAPI_GTransform(mod);
bind_BRepBuilderAPI_MakeEdge(mod);
bind_BRepBuilderAPI_MakeEdge2d(mod);
bind_BRepBuilderAPI_MakeFace(mod);
bind_BRepBuilderAPI_MakePolygon(mod);
bind_BRepBuilderAPI_MakeShell(mod);
bind_BRepBuilderAPI_MakeSolid(mod);
bind_BRepBuilderAPI_MakeVertex(mod);
bind_BRepBuilderAPI_MakeWire(mod);
bind_BRepBuilderAPI_NurbsConvert(mod);
bind_BRepBuilderAPI_Sewing(mod);
bind_BRepBuilderAPI_Transform(mod);

}
