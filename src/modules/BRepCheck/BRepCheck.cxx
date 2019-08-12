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

void bind_BRepCheck_Status(py::module &);
void bind_BRepCheck_ListOfStatus(py::module &);
void bind_BRepCheck_ListIteratorOfListOfStatus(py::module &);
void bind_BRepCheck(py::module &);
void bind_BRepCheck_DataMapOfShapeListOfStatus(py::module &);
void bind_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus(py::module &);
void bind_BRepCheck_Result(py::module &);
void bind_BRepCheck_DataMapOfShapeResult(py::module &);
void bind_BRepCheck_DataMapIteratorOfDataMapOfShapeResult(py::module &);
void bind_BRepCheck_Analyzer(py::module &);
void bind_BRepCheck_Edge(py::module &);
void bind_BRepCheck_Face(py::module &);
void bind_BRepCheck_Shell(py::module &);
void bind_BRepCheck_Solid(py::module &);
void bind_BRepCheck_Vertex(py::module &);
void bind_BRepCheck_Wire(py::module &);

PYBIND11_MODULE(BRepCheck, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BRep");
py::module::import("OCCT.Adaptor3d");

bind_BRepCheck_Status(mod);
bind_BRepCheck_ListOfStatus(mod);
bind_BRepCheck_ListIteratorOfListOfStatus(mod);
bind_BRepCheck(mod);
bind_BRepCheck_DataMapOfShapeListOfStatus(mod);
bind_BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus(mod);
bind_BRepCheck_Result(mod);
bind_BRepCheck_DataMapOfShapeResult(mod);
bind_BRepCheck_DataMapIteratorOfDataMapOfShapeResult(mod);
bind_BRepCheck_Analyzer(mod);
bind_BRepCheck_Edge(mod);
bind_BRepCheck_Face(mod);
bind_BRepCheck_Shell(mod);
bind_BRepCheck_Solid(mod);
bind_BRepCheck_Vertex(mod);
bind_BRepCheck_Wire(mod);

}
