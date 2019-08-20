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
#include <TopOpeBRepTool_OutCurveType.hxx>
#include <TopOpeBRepTool_GeomTool.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Surface.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <Geom2d_Curve.hxx>
#include <TopAbs_Orientation.hxx>
#include <Geom_Surface.hxx>
#include <BRep_Builder.hxx>
#include <TopOpeBRepTool_CurveTool.hxx>
#include <TopOpeBRepDS_BuildTool.hxx>

void bind_TopOpeBRepDS_BuildTool(py::module &mod){

py::class_<TopOpeBRepDS_BuildTool, std::unique_ptr<TopOpeBRepDS_BuildTool>> cls_TopOpeBRepDS_BuildTool(mod, "TopOpeBRepDS_BuildTool", "Provides a Tool to build topologies. Used to instantiate the Builder algorithm.");

// Constructors
cls_TopOpeBRepDS_BuildTool.def(py::init<>());
cls_TopOpeBRepDS_BuildTool.def(py::init<const TopOpeBRepTool_OutCurveType>(), py::arg("OutCurveType"));
cls_TopOpeBRepDS_BuildTool.def(py::init<const TopOpeBRepTool_GeomTool &>(), py::arg("GT"));

// Fields

// Methods
// cls_TopOpeBRepDS_BuildTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_BuildTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_BuildTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_BuildTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_BuildTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_BuildTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_BuildTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_BuildTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_BuildTool.def("GetGeomTool", (const TopOpeBRepTool_GeomTool & (TopOpeBRepDS_BuildTool::*)() const) &TopOpeBRepDS_BuildTool::GetGeomTool, "None");
cls_TopOpeBRepDS_BuildTool.def("ChangeGeomTool", (TopOpeBRepTool_GeomTool & (TopOpeBRepDS_BuildTool::*)()) &TopOpeBRepDS_BuildTool::ChangeGeomTool, "None");
cls_TopOpeBRepDS_BuildTool.def("MakeVertex", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Point &) const) &TopOpeBRepDS_BuildTool::MakeVertex, "None", py::arg("V"), py::arg("P"));
cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Curve &) const) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"), py::arg("C"));
cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Curve &, const TopOpeBRepDS_DataStructure &) const) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"), py::arg("C"), py::arg("DS"));
cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"), py::arg("C"), py::arg("Tol"));
cls_TopOpeBRepDS_BuildTool.def("MakeEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::MakeEdge, "None", py::arg("E"));
cls_TopOpeBRepDS_BuildTool.def("MakeWire", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::MakeWire, "None", py::arg("W"));
cls_TopOpeBRepDS_BuildTool.def("MakeFace", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopOpeBRepDS_Surface &) const) &TopOpeBRepDS_BuildTool::MakeFace, "None", py::arg("F"), py::arg("S"));
cls_TopOpeBRepDS_BuildTool.def("MakeShell", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::MakeShell, "None", py::arg("Sh"));
cls_TopOpeBRepDS_BuildTool.def("MakeSolid", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::MakeSolid, "None", py::arg("S"));
cls_TopOpeBRepDS_BuildTool.def("CopyEdge", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::CopyEdge, "Make an edge <Eou> with the curve of the edge <Ein>", py::arg("Ein"), py::arg("Eou"));
cls_TopOpeBRepDS_BuildTool.def("GetOrientedEdgeVertices", [](TopOpeBRepDS_BuildTool &self, TopoDS_Edge & E, TopoDS_Vertex & Vmin, TopoDS_Vertex & Vmax, Standard_Real & Parmin, Standard_Real & Parmax){ self.GetOrientedEdgeVertices(E, Vmin, Vmax, Parmin, Parmax); return std::tuple<Standard_Real &, Standard_Real &>(Parmin, Parmax); }, "None", py::arg("E"), py::arg("Vmin"), py::arg("Vmax"), py::arg("Parmin"), py::arg("Parmax"));
cls_TopOpeBRepDS_BuildTool.def("UpdateEdgeCurveTol", [](TopOpeBRepDS_BuildTool &self, const TopoDS_Face & F1, const TopoDS_Face & F2, TopoDS_Edge & E, const opencascade::handle<Geom_Curve> & C3Dnew, const Standard_Real tol3d, const Standard_Real tol2d1, const Standard_Real tol2d2, Standard_Real & newtol, Standard_Real & newparmin, Standard_Real & newparmax){ self.UpdateEdgeCurveTol(F1, F2, E, C3Dnew, tol3d, tol2d1, tol2d2, newtol, newparmin, newparmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(newtol, newparmin, newparmax); }, "None", py::arg("F1"), py::arg("F2"), py::arg("E"), py::arg("C3Dnew"), py::arg("tol3d"), py::arg("tol2d1"), py::arg("tol2d2"), py::arg("newtol"), py::arg("newparmin"), py::arg("newparmax"));
cls_TopOpeBRepDS_BuildTool.def("ApproxCurves", [](TopOpeBRepDS_BuildTool &self, const TopOpeBRepDS_Curve & C, TopoDS_Edge & E, Standard_Integer & inewC, const opencascade::handle<TopOpeBRepDS_HDataStructure> & HDS){ self.ApproxCurves(C, E, inewC, HDS); return inewC; }, "None", py::arg("C"), py::arg("E"), py::arg("inewC"), py::arg("HDS"));
cls_TopOpeBRepDS_BuildTool.def("ComputePCurves", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Edge &, TopOpeBRepDS_Curve &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean) const) &TopOpeBRepDS_BuildTool::ComputePCurves, "None", py::arg("C"), py::arg("E"), py::arg("newC"), py::arg("CompPC1"), py::arg("CompPC2"), py::arg("CompC3D"));
cls_TopOpeBRepDS_BuildTool.def("PutPCurves", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Edge &, const Standard_Boolean, const Standard_Boolean) const) &TopOpeBRepDS_BuildTool::PutPCurves, "None", py::arg("newC"), py::arg("E"), py::arg("CompPC1"), py::arg("CompPC2"));
cls_TopOpeBRepDS_BuildTool.def("RecomputeCurves", [](TopOpeBRepDS_BuildTool &self, const TopOpeBRepDS_Curve & C, const TopoDS_Edge & oldE, TopoDS_Edge & E, Standard_Integer & inewC, const opencascade::handle<TopOpeBRepDS_HDataStructure> & HDS){ self.RecomputeCurves(C, oldE, E, inewC, HDS); return inewC; }, "None", py::arg("C"), py::arg("oldE"), py::arg("E"), py::arg("inewC"), py::arg("HDS"));
cls_TopOpeBRepDS_BuildTool.def("CopyFace", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::CopyFace, "Make a face <Fou> with the surface of the face <Fin>", py::arg("Fin"), py::arg("Fou"));
cls_TopOpeBRepDS_BuildTool.def("AddEdgeVertex", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddEdgeVertex, "None", py::arg("Ein"), py::arg("Eou"), py::arg("V"));
cls_TopOpeBRepDS_BuildTool.def("AddEdgeVertex", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddEdgeVertex, "None", py::arg("E"), py::arg("V"));
cls_TopOpeBRepDS_BuildTool.def("AddWireEdge", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddWireEdge, "None", py::arg("W"), py::arg("E"));
cls_TopOpeBRepDS_BuildTool.def("AddFaceWire", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddFaceWire, "None", py::arg("F"), py::arg("W"));
cls_TopOpeBRepDS_BuildTool.def("AddShellFace", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddShellFace, "None", py::arg("Sh"), py::arg("F"));
cls_TopOpeBRepDS_BuildTool.def("AddSolidShell", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::AddSolidShell, "None", py::arg("S"), py::arg("Sh"));
cls_TopOpeBRepDS_BuildTool.def("Parameter", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real) const) &TopOpeBRepDS_BuildTool::Parameter, "Sets the parameter <P> for the vertex <V> on the edge <E>.", py::arg("E"), py::arg("V"), py::arg("P"));
cls_TopOpeBRepDS_BuildTool.def("Range", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real) const) &TopOpeBRepDS_BuildTool::Range, "Sets the range of edge <E>.", py::arg("E"), py::arg("first"), py::arg("last"));
cls_TopOpeBRepDS_BuildTool.def("UpdateEdge", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::UpdateEdge, "Sets the range of edge <Eou> from <Ein> only when <Ein> has a closed geometry.", py::arg("Ein"), py::arg("Eou"));
cls_TopOpeBRepDS_BuildTool.def("Parameter", (void (TopOpeBRepDS_BuildTool::*)(const TopOpeBRepDS_Curve &, TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::Parameter, "Compute the parameter of the vertex <V>, supported by the edge <E>, on the curve <C>.", py::arg("C"), py::arg("E"), py::arg("V"));
cls_TopOpeBRepDS_BuildTool.def("Curve3D", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const) &TopOpeBRepDS_BuildTool::Curve3D, "Sets the curve <C> for the edge <E>", py::arg("E"), py::arg("C"), py::arg("Tol"));
cls_TopOpeBRepDS_BuildTool.def("PCurve", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, TopoDS_Shape &, const opencascade::handle<Geom2d_Curve> &) const) &TopOpeBRepDS_BuildTool::PCurve, "Sets the pcurve <C> for the edge <E> on the face <F>. If OverWrite is True the old pcurve if there is one is overwritten, else the two pcurves are set.", py::arg("F"), py::arg("E"), py::arg("C"));
cls_TopOpeBRepDS_BuildTool.def("PCurve", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, TopoDS_Shape &, const TopOpeBRepDS_Curve &, const opencascade::handle<Geom2d_Curve> &) const) &TopOpeBRepDS_BuildTool::PCurve, "None", py::arg("F"), py::arg("E"), py::arg("CDS"), py::arg("C"));
cls_TopOpeBRepDS_BuildTool.def("Orientation", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const TopAbs_Orientation) const) &TopOpeBRepDS_BuildTool::Orientation, "None", py::arg("S"), py::arg("O"));
cls_TopOpeBRepDS_BuildTool.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::Orientation, "None", py::arg("S"));
cls_TopOpeBRepDS_BuildTool.def("Closed", (void (TopOpeBRepDS_BuildTool::*)(TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_BuildTool::Closed, "None", py::arg("S"), py::arg("B"));
cls_TopOpeBRepDS_BuildTool.def("Approximation", (Standard_Boolean (TopOpeBRepDS_BuildTool::*)() const) &TopOpeBRepDS_BuildTool::Approximation, "None");
cls_TopOpeBRepDS_BuildTool.def("UpdateSurface", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &) const) &TopOpeBRepDS_BuildTool::UpdateSurface, "None", py::arg("F"), py::arg("SU"));
cls_TopOpeBRepDS_BuildTool.def("UpdateSurface", (void (TopOpeBRepDS_BuildTool::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &) const) &TopOpeBRepDS_BuildTool::UpdateSurface, "None", py::arg("E"), py::arg("oldF"), py::arg("newF"));
cls_TopOpeBRepDS_BuildTool.def("OverWrite", (Standard_Boolean (TopOpeBRepDS_BuildTool::*)() const) &TopOpeBRepDS_BuildTool::OverWrite, "None");
cls_TopOpeBRepDS_BuildTool.def("OverWrite", (void (TopOpeBRepDS_BuildTool::*)(const Standard_Boolean)) &TopOpeBRepDS_BuildTool::OverWrite, "None", py::arg("O"));
cls_TopOpeBRepDS_BuildTool.def("Translate", (Standard_Boolean (TopOpeBRepDS_BuildTool::*)() const) &TopOpeBRepDS_BuildTool::Translate, "None");
cls_TopOpeBRepDS_BuildTool.def("Translate", (void (TopOpeBRepDS_BuildTool::*)(const Standard_Boolean)) &TopOpeBRepDS_BuildTool::Translate, "None", py::arg("T"));

// Enums

}