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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <ShapeExtend_WireData.hxx>
#include <ShapeFix_DataMapOfShapeBox2d.hxx>
#include <Bnd_Box2d.hxx>
#include <Geom2d_Curve.hxx>
#include <ShapeFix_IntersectionTool.hxx>

void bind_ShapeFix_IntersectionTool(py::module &mod){

py::class_<ShapeFix_IntersectionTool, std::unique_ptr<ShapeFix_IntersectionTool, Deleter<ShapeFix_IntersectionTool>>> cls_ShapeFix_IntersectionTool(mod, "ShapeFix_IntersectionTool", "Tool for fixing selfintersecting wire and intersecting wires");

// Constructors
cls_ShapeFix_IntersectionTool.def(py::init<const opencascade::handle<ShapeBuild_ReShape> &, const Standard_Real>(), py::arg("context"), py::arg("preci"));
cls_ShapeFix_IntersectionTool.def(py::init<const opencascade::handle<ShapeBuild_ReShape> &, const Standard_Real, const Standard_Real>(), py::arg("context"), py::arg("preci"), py::arg("maxtol"));

// Fields

// Methods
// cls_ShapeFix_IntersectionTool.def_static("operator new_", (void * (*)(size_t)) &ShapeFix_IntersectionTool::operator new, "None", py::arg("theSize"));
// cls_ShapeFix_IntersectionTool.def_static("operator delete_", (void (*)(void *)) &ShapeFix_IntersectionTool::operator delete, "None", py::arg("theAddress"));
// cls_ShapeFix_IntersectionTool.def_static("operator new[]_", (void * (*)(size_t)) &ShapeFix_IntersectionTool::operator new[], "None", py::arg("theSize"));
// cls_ShapeFix_IntersectionTool.def_static("operator delete[]_", (void (*)(void *)) &ShapeFix_IntersectionTool::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeFix_IntersectionTool.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeFix_IntersectionTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeFix_IntersectionTool.def_static("operator delete_", (void (*)(void *, void *)) &ShapeFix_IntersectionTool::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeFix_IntersectionTool.def("Context", (opencascade::handle<ShapeBuild_ReShape> (ShapeFix_IntersectionTool::*)() const) &ShapeFix_IntersectionTool::Context, "Returns context");
cls_ShapeFix_IntersectionTool.def("SplitEdge", (Standard_Boolean (ShapeFix_IntersectionTool::*)(const TopoDS_Edge &, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real) const) &ShapeFix_IntersectionTool::SplitEdge, "Split edge on two new edges using new vertex 'vert' and 'param' - parameter for splitting The 'face' is necessary for pcurves and using TransferParameterProj", py::arg("edge"), py::arg("param"), py::arg("vert"), py::arg("face"), py::arg("newE1"), py::arg("newE2"), py::arg("preci"));
cls_ShapeFix_IntersectionTool.def("CutEdge", [](ShapeFix_IntersectionTool &self, const TopoDS_Edge & edge, const Standard_Real pend, const Standard_Real cut, const TopoDS_Face & face, Standard_Boolean & iscutline){ Standard_Boolean rv = self.CutEdge(edge, pend, cut, face, iscutline); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, iscutline); }, "Cut edge by parameters pend and cut", py::arg("edge"), py::arg("pend"), py::arg("cut"), py::arg("face"), py::arg("iscutline"));
cls_ShapeFix_IntersectionTool.def("FixSelfIntersectWire", [](ShapeFix_IntersectionTool &self, opencascade::handle<ShapeExtend_WireData> & sewd, const TopoDS_Face & face, Standard_Integer & NbSplit, Standard_Integer & NbCut, Standard_Integer & NbRemoved){ Standard_Boolean rv = self.FixSelfIntersectWire(sewd, face, NbSplit, NbCut, NbRemoved); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &, Standard_Integer &>(rv, NbSplit, NbCut, NbRemoved); }, "None", py::arg("sewd"), py::arg("face"), py::arg("NbSplit"), py::arg("NbCut"), py::arg("NbRemoved"));
cls_ShapeFix_IntersectionTool.def("FixIntersectingWires", (Standard_Boolean (ShapeFix_IntersectionTool::*)(TopoDS_Face &) const) &ShapeFix_IntersectionTool::FixIntersectingWires, "None", py::arg("face"));

// Enums

}