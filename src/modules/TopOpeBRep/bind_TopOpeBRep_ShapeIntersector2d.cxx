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
#include <TopOpeBRep_EdgesIntersector.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepTool_HBoxTool.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <TopOpeBRep_ShapeScanner.hxx>
#include <TopOpeBRep_ShapeIntersector2d.hxx>

void bind_TopOpeBRep_ShapeIntersector2d(py::module &mod){

py::class_<TopOpeBRep_ShapeIntersector2d> cls_TopOpeBRep_ShapeIntersector2d(mod, "TopOpeBRep_ShapeIntersector2d", "Intersect two shapes.");

// Constructors
cls_TopOpeBRep_ShapeIntersector2d.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_ShapeIntersector2d.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_ShapeIntersector2d::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_ShapeIntersector2d.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_ShapeIntersector2d::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_ShapeIntersector2d.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_ShapeIntersector2d::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_ShapeIntersector2d.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_ShapeIntersector2d::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_ShapeIntersector2d.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_ShapeIntersector2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_ShapeIntersector2d.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_ShapeIntersector2d::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_ShapeIntersector2d.def("InitIntersection", (void (TopOpeBRep_ShapeIntersector2d::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_ShapeIntersector2d::InitIntersection, "Initialize the intersection of shapes S1,S2.", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRep_ShapeIntersector2d.def("Shape", (const TopoDS_Shape & (TopOpeBRep_ShapeIntersector2d::*)(const Standard_Integer) const) &TopOpeBRep_ShapeIntersector2d::Shape, "return the shape <Index> ( = 1 or 2) given to InitIntersection(). Index = 1 will return S1, Index = 2 will return S2.", py::arg("Index"));
cls_TopOpeBRep_ShapeIntersector2d.def("MoreIntersection", (Standard_Boolean (TopOpeBRep_ShapeIntersector2d::*)() const) &TopOpeBRep_ShapeIntersector2d::MoreIntersection, "returns True if there are more intersection between two the shapes.");
cls_TopOpeBRep_ShapeIntersector2d.def("NextIntersection", (void (TopOpeBRep_ShapeIntersector2d::*)()) &TopOpeBRep_ShapeIntersector2d::NextIntersection, "search for the next intersection between the two shapes.");
cls_TopOpeBRep_ShapeIntersector2d.def("ChangeEdgesIntersector", (TopOpeBRep_EdgesIntersector & (TopOpeBRep_ShapeIntersector2d::*)()) &TopOpeBRep_ShapeIntersector2d::ChangeEdgesIntersector, "return the current intersection of two Edges.");
cls_TopOpeBRep_ShapeIntersector2d.def("CurrentGeomShape", (const TopoDS_Shape & (TopOpeBRep_ShapeIntersector2d::*)(const Standard_Integer) const) &TopOpeBRep_ShapeIntersector2d::CurrentGeomShape, "return geometric shape <Index> ( = 1 or 2 ) of current intersection.", py::arg("Index"));
cls_TopOpeBRep_ShapeIntersector2d.def("DumpCurrent", (void (TopOpeBRep_ShapeIntersector2d::*)(const Standard_Integer) const) &TopOpeBRep_ShapeIntersector2d::DumpCurrent, "None", py::arg("K"));
cls_TopOpeBRep_ShapeIntersector2d.def("Index", (Standard_Integer (TopOpeBRep_ShapeIntersector2d::*)(const Standard_Integer) const) &TopOpeBRep_ShapeIntersector2d::Index, "None", py::arg("K"));

// Enums

}