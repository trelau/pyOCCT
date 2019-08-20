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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <Standard_Handle.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeFix_SplitTool.hxx>

void bind_ShapeFix_SplitTool(py::module &mod){

py::class_<ShapeFix_SplitTool, std::unique_ptr<ShapeFix_SplitTool>> cls_ShapeFix_SplitTool(mod, "ShapeFix_SplitTool", "Tool for splitting and cutting edges; includes methods used in OverlappingTool and IntersectionTool");

// Constructors
cls_ShapeFix_SplitTool.def(py::init<>());

// Fields

// Methods
// cls_ShapeFix_SplitTool.def_static("operator new_", (void * (*)(size_t)) &ShapeFix_SplitTool::operator new, "None", py::arg("theSize"));
// cls_ShapeFix_SplitTool.def_static("operator delete_", (void (*)(void *)) &ShapeFix_SplitTool::operator delete, "None", py::arg("theAddress"));
// cls_ShapeFix_SplitTool.def_static("operator new[]_", (void * (*)(size_t)) &ShapeFix_SplitTool::operator new[], "None", py::arg("theSize"));
// cls_ShapeFix_SplitTool.def_static("operator delete[]_", (void (*)(void *)) &ShapeFix_SplitTool::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeFix_SplitTool.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeFix_SplitTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeFix_SplitTool.def_static("operator delete_", (void (*)(void *, void *)) &ShapeFix_SplitTool::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeFix_SplitTool.def("SplitEdge", (Standard_Boolean (ShapeFix_SplitTool::*)(const TopoDS_Edge &, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real, const Standard_Real) const) &ShapeFix_SplitTool::SplitEdge, "Split edge on two new edges using new vertex 'vert' and 'param' - parameter for splitting The 'face' is necessary for pcurves and using TransferParameterProj", py::arg("edge"), py::arg("param"), py::arg("vert"), py::arg("face"), py::arg("newE1"), py::arg("newE2"), py::arg("tol3d"), py::arg("tol2d"));
cls_ShapeFix_SplitTool.def("SplitEdge", (Standard_Boolean (ShapeFix_SplitTool::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Real, const Standard_Real) const) &ShapeFix_SplitTool::SplitEdge, "Split edge on two new edges using new vertex 'vert' and 'param1' and 'param2' - parameter for splitting and cutting The 'face' is necessary for pcurves and using TransferParameterProj", py::arg("edge"), py::arg("param1"), py::arg("param2"), py::arg("vert"), py::arg("face"), py::arg("newE1"), py::arg("newE2"), py::arg("tol3d"), py::arg("tol2d"));
cls_ShapeFix_SplitTool.def("CutEdge", [](ShapeFix_SplitTool &self, const TopoDS_Edge & edge, const Standard_Real pend, const Standard_Real cut, const TopoDS_Face & face, Standard_Boolean & iscutline){ Standard_Boolean rv = self.CutEdge(edge, pend, cut, face, iscutline); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, iscutline); }, "Cut edge by parameters pend and cut", py::arg("edge"), py::arg("pend"), py::arg("cut"), py::arg("face"), py::arg("iscutline"));
cls_ShapeFix_SplitTool.def("SplitEdge", [](ShapeFix_SplitTool &self, const TopoDS_Edge & edge, const Standard_Real fp, const TopoDS_Vertex & V1, const Standard_Real lp, const TopoDS_Vertex & V2, const TopoDS_Face & face, TopTools_SequenceOfShape & SeqE, Standard_Integer & aNum, const opencascade::handle<ShapeBuild_ReShape> & context, const Standard_Real tol3d, const Standard_Real tol2d){ Standard_Boolean rv = self.SplitEdge(edge, fp, V1, lp, V2, face, SeqE, aNum, context, tol3d, tol2d); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, aNum); }, "Split edge on two new edges using two new vertex V1 and V2 and two parameters for splitting - fp and lp correspondingly The 'face' is necessary for pcurves and using TransferParameterProj aNum - number of edge in SeqE which corresponding to [fp,lp]", py::arg("edge"), py::arg("fp"), py::arg("V1"), py::arg("lp"), py::arg("V2"), py::arg("face"), py::arg("SeqE"), py::arg("aNum"), py::arg("context"), py::arg("tol3d"), py::arg("tol2d"));

// Enums

}