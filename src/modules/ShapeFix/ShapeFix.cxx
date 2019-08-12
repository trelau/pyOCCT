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

void bind_ShapeFix_Root(py::module &);
void bind_ShapeFix_DataMapOfShapeBox2d(py::module &);
void bind_ShapeFix_DataMapIteratorOfDataMapOfShapeBox2d(py::module &);
void bind_ShapeFix_Face(py::module &);
void bind_ShapeFix(py::module &);
void bind_ShapeFix_WireSegment(py::module &);
void bind_ShapeFix_SequenceOfWireSegment(py::module &);
void bind_ShapeFix_ComposeShell(py::module &);
void bind_ShapeFix_Edge(py::module &);
void bind_ShapeFix_EdgeConnect(py::module &);
void bind_ShapeFix_EdgeProjAux(py::module &);
void bind_ShapeFix_FaceConnect(py::module &);
void bind_ShapeFix_FixSmallFace(py::module &);
void bind_ShapeFix_FixSmallSolid(py::module &);
void bind_ShapeFix_FreeBounds(py::module &);
void bind_ShapeFix_IntersectionTool(py::module &);
void bind_ShapeFix_Shape(py::module &);
void bind_ShapeFix_Solid(py::module &);
void bind_ShapeFix_Shell(py::module &);
void bind_ShapeFix_Wire(py::module &);
void bind_ShapeFix_ShapeTolerance(py::module &);
void bind_ShapeFix_SplitCommonVertex(py::module &);
void bind_ShapeFix_SplitTool(py::module &);
void bind_ShapeFix_Wireframe(py::module &);
void bind_ShapeFix_WireVertex(py::module &);

PYBIND11_MODULE(ShapeFix, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.ShapeBuild");
py::module::import("OCCT.ShapeExtend");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Message");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Geom");
py::module::import("OCCT.ShapeAnalysis");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.gp");
py::module::import("OCCT.ShapeConstruct");
py::module::import("OCCT.Geom2d");

bind_ShapeFix_Root(mod);
bind_ShapeFix_DataMapOfShapeBox2d(mod);
bind_ShapeFix_DataMapIteratorOfDataMapOfShapeBox2d(mod);
bind_ShapeFix_Face(mod);
bind_ShapeFix(mod);
bind_ShapeFix_WireSegment(mod);
bind_ShapeFix_SequenceOfWireSegment(mod);
bind_ShapeFix_ComposeShell(mod);
bind_ShapeFix_Edge(mod);
bind_ShapeFix_EdgeConnect(mod);
bind_ShapeFix_EdgeProjAux(mod);
bind_ShapeFix_FaceConnect(mod);
bind_ShapeFix_FixSmallFace(mod);
bind_ShapeFix_FixSmallSolid(mod);
bind_ShapeFix_FreeBounds(mod);
bind_ShapeFix_IntersectionTool(mod);
bind_ShapeFix_Shape(mod);
bind_ShapeFix_Solid(mod);
bind_ShapeFix_Shell(mod);
bind_ShapeFix_Wire(mod);
bind_ShapeFix_ShapeTolerance(mod);
bind_ShapeFix_SplitCommonVertex(mod);
bind_ShapeFix_SplitTool(mod);
bind_ShapeFix_Wireframe(mod);
bind_ShapeFix_WireVertex(mod);

}
