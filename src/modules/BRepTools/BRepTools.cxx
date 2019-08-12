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

void bind_BRepTools_History(py::module &);
void bind_BRepTools_Modifier(py::module &);
void bind_BRepTools_ReShape(py::module &);
void bind_BRepTools_WireExplorer(py::module &);
void bind_BRepTools_Modification(py::module &);
void bind_BRepTools(py::module &);
void bind_BRepTools_MapOfVertexPnt2d(py::module &);
void bind_BRepTools_DataMapIteratorOfMapOfVertexPnt2d(py::module &);
void bind_BRepTools_GTrsfModification(py::module &);
void bind_BRepTools_NurbsConvertModification(py::module &);
void bind_BRepTools_Quilt(py::module &);
void bind_BRepTools_ShapeSet(py::module &);
void bind_BRepTools_Substitution(py::module &);
void bind_BRepTools_TrsfModification(py::module &);

PYBIND11_MODULE(BRepTools, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Message");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.Poly");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.BRep");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomTools");

bind_BRepTools_History(mod);
bind_BRepTools_Modifier(mod);
bind_BRepTools_ReShape(mod);
bind_BRepTools_WireExplorer(mod);
bind_BRepTools_Modification(mod);
bind_BRepTools(mod);
bind_BRepTools_MapOfVertexPnt2d(mod);
bind_BRepTools_DataMapIteratorOfMapOfVertexPnt2d(mod);
bind_BRepTools_GTrsfModification(mod);
bind_BRepTools_NurbsConvertModification(mod);
bind_BRepTools_Quilt(mod);
bind_BRepTools_ShapeSet(mod);
bind_BRepTools_Substitution(mod);
bind_BRepTools_TrsfModification(mod);

}
