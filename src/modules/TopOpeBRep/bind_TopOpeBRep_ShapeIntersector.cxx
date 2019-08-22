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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRep_FacesIntersector.hxx>
#include <TopOpeBRep_EdgesIntersector.hxx>
#include <TopOpeBRep_FaceEdgeIntersector.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepTool_HBoxTool.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <TopOpeBRep_ShapeScanner.hxx>
#include <TopOpeBRep_ShapeIntersector.hxx>

void bind_TopOpeBRep_ShapeIntersector(py::module &mod){

py::class_<TopOpeBRep_ShapeIntersector> cls_TopOpeBRep_ShapeIntersector(mod, "TopOpeBRep_ShapeIntersector", "Intersect two shapes.");

// Constructors
cls_TopOpeBRep_ShapeIntersector.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_ShapeIntersector.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_ShapeIntersector::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_ShapeIntersector.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_ShapeIntersector::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_ShapeIntersector.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_ShapeIntersector::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_ShapeIntersector.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_ShapeIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_ShapeIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_ShapeIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_ShapeIntersector.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_ShapeIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_ShapeIntersector.def("InitIntersection", (void (TopOpeBRep_ShapeIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_ShapeIntersector::InitIntersection, "Initialize the intersection of shapes S1,S2.", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRep_ShapeIntersector.def("InitIntersection", (void (TopOpeBRep_ShapeIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRep_ShapeIntersector::InitIntersection, "Initialize the intersection of shapes S1,S2.", py::arg("S1"), py::arg("S2"), py::arg("F1"), py::arg("F2"));
cls_TopOpeBRep_ShapeIntersector.def("Shape", (const TopoDS_Shape & (TopOpeBRep_ShapeIntersector::*)(const Standard_Integer) const) &TopOpeBRep_ShapeIntersector::Shape, "return the shape <Index> ( = 1 or 2) given to InitIntersection(). Index = 1 will return S1, Index = 2 will return S2.", py::arg("Index"));
cls_TopOpeBRep_ShapeIntersector.def("MoreIntersection", (Standard_Boolean (TopOpeBRep_ShapeIntersector::*)() const) &TopOpeBRep_ShapeIntersector::MoreIntersection, "returns True if there are more intersection between two the shapes.");
cls_TopOpeBRep_ShapeIntersector.def("NextIntersection", (void (TopOpeBRep_ShapeIntersector::*)()) &TopOpeBRep_ShapeIntersector::NextIntersection, "search for the next intersection between the two shapes.");
cls_TopOpeBRep_ShapeIntersector.def("ChangeFacesIntersector", (TopOpeBRep_FacesIntersector & (TopOpeBRep_ShapeIntersector::*)()) &TopOpeBRep_ShapeIntersector::ChangeFacesIntersector, "return the current intersection of two Faces.");
cls_TopOpeBRep_ShapeIntersector.def("ChangeEdgesIntersector", (TopOpeBRep_EdgesIntersector & (TopOpeBRep_ShapeIntersector::*)()) &TopOpeBRep_ShapeIntersector::ChangeEdgesIntersector, "return the current intersection of two Edges.");
cls_TopOpeBRep_ShapeIntersector.def("ChangeFaceEdgeIntersector", (TopOpeBRep_FaceEdgeIntersector & (TopOpeBRep_ShapeIntersector::*)()) &TopOpeBRep_ShapeIntersector::ChangeFaceEdgeIntersector, "return the current intersection of a Face and an Edge.");
cls_TopOpeBRep_ShapeIntersector.def("CurrentGeomShape", (const TopoDS_Shape & (TopOpeBRep_ShapeIntersector::*)(const Standard_Integer) const) &TopOpeBRep_ShapeIntersector::CurrentGeomShape, "return geometric shape <Index> ( = 1 or 2 ) of current intersection.", py::arg("Index"));
cls_TopOpeBRep_ShapeIntersector.def("GetTolerances", [](TopOpeBRep_ShapeIntersector &self, Standard_Real & tol1, Standard_Real & tol2){ self.GetTolerances(tol1, tol2); return std::tuple<Standard_Real &, Standard_Real &>(tol1, tol2); }, "return MAX of intersection tolerances with which FacesIntersector from TopOpeBRep was working.", py::arg("tol1"), py::arg("tol2"));
cls_TopOpeBRep_ShapeIntersector.def("DumpCurrent", (void (TopOpeBRep_ShapeIntersector::*)(const Standard_Integer) const) &TopOpeBRep_ShapeIntersector::DumpCurrent, "None", py::arg("K"));
cls_TopOpeBRep_ShapeIntersector.def("Index", (Standard_Integer (TopOpeBRep_ShapeIntersector::*)(const Standard_Integer) const) &TopOpeBRep_ShapeIntersector::Index, "None", py::arg("K"));
cls_TopOpeBRep_ShapeIntersector.def("RejectedFaces", (void (TopOpeBRep_ShapeIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &)) &TopOpeBRep_ShapeIntersector::RejectedFaces, "None", py::arg("anObj"), py::arg("aReference"), py::arg("aListOfShape"));

// Enums

}