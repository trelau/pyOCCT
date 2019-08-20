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
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopExp_Explorer.hxx>
#include <TopExp.hxx>

void bind_TopExp(py::module &mod){

py::class_<TopExp, std::unique_ptr<TopExp>> cls_TopExp(mod, "TopExp", "This package provides basic tools to explore the topological data structures.");

// Constructors

// Fields

// Methods
// cls_TopExp.def_static("operator new_", (void * (*)(size_t)) &TopExp::operator new, "None", py::arg("theSize"));
// cls_TopExp.def_static("operator delete_", (void (*)(void *)) &TopExp::operator delete, "None", py::arg("theAddress"));
// cls_TopExp.def_static("operator new[]_", (void * (*)(size_t)) &TopExp::operator new[], "None", py::arg("theSize"));
// cls_TopExp.def_static("operator delete[]_", (void (*)(void *)) &TopExp::operator delete[], "None", py::arg("theAddress"));
// cls_TopExp.def_static("operator new_", (void * (*)(size_t, void *)) &TopExp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopExp.def_static("operator delete_", (void (*)(void *, void *)) &TopExp::operator delete, "None", py::arg(""), py::arg(""));
cls_TopExp.def_static("MapShapes_", (void (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, TopTools_IndexedMapOfShape &)) &TopExp::MapShapes, "Tool to explore a topological data structure. Stores in the map <M> all the sub-shapes of <S> of type <T>.", py::arg("S"), py::arg("T"), py::arg("M"));
cls_TopExp.def_static("MapShapes_", (void (*)(const TopoDS_Shape &, TopTools_IndexedMapOfShape &)) &TopExp::MapShapes, "Stores in the map <M> all the sub-shapes of <S>.", py::arg("S"), py::arg("M"));
cls_TopExp.def_static("MapShapes_", (void (*)(const TopoDS_Shape &, TopTools_MapOfShape &)) &TopExp::MapShapes, "Stores in the map <M> all the sub-shapes of <S>.", py::arg("S"), py::arg("M"));
cls_TopExp.def_static("MapShapesAndAncestors_", (void (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, TopTools_IndexedDataMapOfShapeListOfShape &)) &TopExp::MapShapesAndAncestors, "Stores in the map <M> all the subshape of <S> of type <TS> for each one append to the list all the ancestors of type <TA>. For example map all the edges and bind the list of faces. Warning: The map is not cleared at first.", py::arg("S"), py::arg("TS"), py::arg("TA"), py::arg("M"));
cls_TopExp.def_static("MapShapesAndUniqueAncestors_", [](const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1, const TopAbs_ShapeEnum a2, TopTools_IndexedDataMapOfShapeListOfShape & a3) -> void { return TopExp::MapShapesAndUniqueAncestors(a0, a1, a2, a3); });
cls_TopExp.def_static("MapShapesAndUniqueAncestors_", (void (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum, TopTools_IndexedDataMapOfShapeListOfShape &, const Standard_Boolean)) &TopExp::MapShapesAndUniqueAncestors, "Stores in the map <M> all the subshape of <S> of type <TS> for each one append to the list all unique ancestors of type <TA>. For example map all the edges and bind the list of faces. useOrientation = True : taking account the ancestor orientation Warning: The map is not cleared at first.", py::arg("S"), py::arg("TS"), py::arg("TA"), py::arg("M"), py::arg("useOrientation"));
cls_TopExp.def_static("FirstVertex_", [](const TopoDS_Edge & a0) -> TopoDS_Vertex { return TopExp::FirstVertex(a0); });
cls_TopExp.def_static("FirstVertex_", (TopoDS_Vertex (*)(const TopoDS_Edge &, const Standard_Boolean)) &TopExp::FirstVertex, "Returns the Vertex of orientation FORWARD in E. If there is none returns a Null Shape. CumOri = True : taking account the edge orientation", py::arg("E"), py::arg("CumOri"));
cls_TopExp.def_static("LastVertex_", [](const TopoDS_Edge & a0) -> TopoDS_Vertex { return TopExp::LastVertex(a0); });
cls_TopExp.def_static("LastVertex_", (TopoDS_Vertex (*)(const TopoDS_Edge &, const Standard_Boolean)) &TopExp::LastVertex, "Returns the Vertex of orientation REVERSED in E. If there is none returns a Null Shape. CumOri = True : taking account the edge orientation", py::arg("E"), py::arg("CumOri"));
cls_TopExp.def_static("Vertices_", [](const TopoDS_Edge & a0, TopoDS_Vertex & a1, TopoDS_Vertex & a2) -> void { return TopExp::Vertices(a0, a1, a2); });
cls_TopExp.def_static("Vertices_", (void (*)(const TopoDS_Edge &, TopoDS_Vertex &, TopoDS_Vertex &, const Standard_Boolean)) &TopExp::Vertices, "Returns in Vfirst, Vlast the FORWARD and REVERSED vertices of the edge <E>. May be null shapes. CumOri = True : taking account the edge orientation", py::arg("E"), py::arg("Vfirst"), py::arg("Vlast"), py::arg("CumOri"));
cls_TopExp.def_static("Vertices_", (void (*)(const TopoDS_Wire &, TopoDS_Vertex &, TopoDS_Vertex &)) &TopExp::Vertices, "Returns in Vfirst, Vlast the first and last vertices of the open wire <W>. May be null shapes. if <W> is closed Vfirst and Vlast are a same vertex on <W>. if <W> is no manifold. VFirst and VLast are null shapes.", py::arg("W"), py::arg("Vfirst"), py::arg("Vlast"));
cls_TopExp.def_static("CommonVertex_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Edge &, TopoDS_Vertex &)) &TopExp::CommonVertex, "Finds the vertex <V> common to the two edges <E1,E2>, returns True if this vertex exists.", py::arg("E1"), py::arg("E2"), py::arg("V"));

// Enums

}