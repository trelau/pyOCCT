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

void bind_HashCode(py::module &);
void bind_TopoDS_Mismatch(py::module &);
void bind_TopoDS_Shape(py::module &);
void bind_TopoDS_ListOfShape(py::module &);
void bind_TopoDS_ListIteratorOfListOfShape(py::module &);
void bind_TopoDS_TShape(py::module &);
void bind_TopoDS_Edge(py::module &);
void bind_TopoDS_Face(py::module &);
void bind_TopoDS(py::module &);
void bind_TopoDS_Vertex(py::module &);
void bind_TopoDS_Compound(py::module &);
void bind_TopoDS_Wire(py::module &);
void bind_TopoDS_Builder(py::module &);
void bind_TopoDS_TWire(py::module &);
void bind_TopoDS_TShell(py::module &);
void bind_TopoDS_TSolid(py::module &);
void bind_TopoDS_TCompSolid(py::module &);
void bind_TopoDS_TCompound(py::module &);
void bind_TopoDS_Shell(py::module &);
void bind_TopoDS_Solid(py::module &);
void bind_TopoDS_CompSolid(py::module &);
void bind_TopoDS_TFace(py::module &);
void bind_TopoDS_TVertex(py::module &);
void bind_TopoDS_AlertWithShape(py::module &);
void bind_TopoDS_Iterator(py::module &);
void bind_TopoDS_TEdge(py::module &);
void bind_TopoDS_FrozenShape(py::module &);
void bind_TopoDS_HShape(py::module &);
void bind_TopoDS_LockedShape(py::module &);
void bind_TopoDS_UnCompatibleShapes(py::module &);

PYBIND11_MODULE(TopoDS, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Message");

bind_HashCode(mod);
bind_TopoDS_Mismatch(mod);
bind_TopoDS_Shape(mod);
bind_TopoDS_ListOfShape(mod);
bind_TopoDS_ListIteratorOfListOfShape(mod);
bind_TopoDS_TShape(mod);
bind_TopoDS_Edge(mod);
bind_TopoDS_Face(mod);
bind_TopoDS(mod);
bind_TopoDS_Vertex(mod);
bind_TopoDS_Compound(mod);
bind_TopoDS_Wire(mod);
bind_TopoDS_Builder(mod);
bind_TopoDS_TWire(mod);
bind_TopoDS_TShell(mod);
bind_TopoDS_TSolid(mod);
bind_TopoDS_TCompSolid(mod);
bind_TopoDS_TCompound(mod);
bind_TopoDS_Shell(mod);
bind_TopoDS_Solid(mod);
bind_TopoDS_CompSolid(mod);
bind_TopoDS_TFace(mod);
bind_TopoDS_TVertex(mod);
bind_TopoDS_AlertWithShape(mod);
bind_TopoDS_Iterator(mod);
bind_TopoDS_TEdge(mod);
bind_TopoDS_FrozenShape(mod);
bind_TopoDS_HShape(mod);
bind_TopoDS_LockedShape(mod);
bind_TopoDS_UnCompatibleShapes(mod);

}
