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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <Bnd_Box.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopoDS_Vertex.hxx>
#include <Poly_Triangulation.hxx>
#include <TopLoc_Location.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Polygon3D.hxx>
#include <TopExp_Explorer.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Prs3d_ShapeTool.hxx>

void bind_Prs3d_ShapeTool(py::module &mod){

py::class_<Prs3d_ShapeTool, std::unique_ptr<Prs3d_ShapeTool, Deleter<Prs3d_ShapeTool>>> cls_Prs3d_ShapeTool(mod, "Prs3d_ShapeTool", "describes the behaviour requested for a wireframe shape presentation.");

// Constructors
cls_Prs3d_ShapeTool.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_Prs3d_ShapeTool.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("theAllVertices"));

// Fields

// Methods
// cls_Prs3d_ShapeTool.def_static("operator new_", (void * (*)(size_t)) &Prs3d_ShapeTool::operator new, "None", py::arg("theSize"));
// cls_Prs3d_ShapeTool.def_static("operator delete_", (void (*)(void *)) &Prs3d_ShapeTool::operator delete, "None", py::arg("theAddress"));
// cls_Prs3d_ShapeTool.def_static("operator new[]_", (void * (*)(size_t)) &Prs3d_ShapeTool::operator new[], "None", py::arg("theSize"));
// cls_Prs3d_ShapeTool.def_static("operator delete[]_", (void (*)(void *)) &Prs3d_ShapeTool::operator delete[], "None", py::arg("theAddress"));
// cls_Prs3d_ShapeTool.def_static("operator new_", (void * (*)(size_t, void *)) &Prs3d_ShapeTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Prs3d_ShapeTool.def_static("operator delete_", (void (*)(void *, void *)) &Prs3d_ShapeTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Prs3d_ShapeTool.def("InitFace", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::InitFace, "None");
cls_Prs3d_ShapeTool.def("MoreFace", (Standard_Boolean (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::MoreFace, "None");
cls_Prs3d_ShapeTool.def("NextFace", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::NextFace, "None");
cls_Prs3d_ShapeTool.def("GetFace", (const TopoDS_Face & (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::GetFace, "None");
cls_Prs3d_ShapeTool.def("FaceBound", (Bnd_Box (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::FaceBound, "None");
cls_Prs3d_ShapeTool.def("IsPlanarFace", (Standard_Boolean (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::IsPlanarFace, "None");
cls_Prs3d_ShapeTool.def("InitCurve", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::InitCurve, "None");
cls_Prs3d_ShapeTool.def("MoreCurve", (Standard_Boolean (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::MoreCurve, "None");
cls_Prs3d_ShapeTool.def("NextCurve", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::NextCurve, "None");
cls_Prs3d_ShapeTool.def("GetCurve", (const TopoDS_Edge & (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::GetCurve, "None");
cls_Prs3d_ShapeTool.def("CurveBound", (Bnd_Box (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::CurveBound, "None");
cls_Prs3d_ShapeTool.def("Neighbours", (Standard_Integer (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::Neighbours, "None");
cls_Prs3d_ShapeTool.def("FacesOfEdge", (opencascade::handle<TopTools_HSequenceOfShape> (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::FacesOfEdge, "None");
cls_Prs3d_ShapeTool.def("InitVertex", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::InitVertex, "None");
cls_Prs3d_ShapeTool.def("MoreVertex", (Standard_Boolean (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::MoreVertex, "None");
cls_Prs3d_ShapeTool.def("NextVertex", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::NextVertex, "None");
cls_Prs3d_ShapeTool.def("GetVertex", (const TopoDS_Vertex & (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::GetVertex, "None");
cls_Prs3d_ShapeTool.def("HasSurface", (Standard_Boolean (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::HasSurface, "None");
cls_Prs3d_ShapeTool.def("CurrentTriangulation", (opencascade::handle<Poly_Triangulation> (Prs3d_ShapeTool::*)(TopLoc_Location &) const) &Prs3d_ShapeTool::CurrentTriangulation, "None", py::arg("l"));
cls_Prs3d_ShapeTool.def("HasCurve", (Standard_Boolean (Prs3d_ShapeTool::*)() const) &Prs3d_ShapeTool::HasCurve, "None");
cls_Prs3d_ShapeTool.def("PolygonOnTriangulation", (void (Prs3d_ShapeTool::*)(opencascade::handle<Poly_PolygonOnTriangulation> &, opencascade::handle<Poly_Triangulation> &, TopLoc_Location &) const) &Prs3d_ShapeTool::PolygonOnTriangulation, "None", py::arg("Indices"), py::arg("T"), py::arg("l"));
cls_Prs3d_ShapeTool.def("Polygon3D", (opencascade::handle<Poly_Polygon3D> (Prs3d_ShapeTool::*)(TopLoc_Location &) const) &Prs3d_ShapeTool::Polygon3D, "None", py::arg("l"));
cls_Prs3d_ShapeTool.def_static("IsPlanarFace_", (Standard_Boolean (*)(const TopoDS_Face &)) &Prs3d_ShapeTool::IsPlanarFace, "None", py::arg("theFace"));

// Enums

}