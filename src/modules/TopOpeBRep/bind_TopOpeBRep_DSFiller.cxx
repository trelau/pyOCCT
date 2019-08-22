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
#include <TopOpeBRepTool_ShapeClassifier.hxx>
#include <Standard.hxx>
#include <TopOpeBRepTool_PShapeClassifier.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRep_ShapeIntersector.hxx>
#include <TopOpeBRep_ShapeIntersector2d.hxx>
#include <TopOpeBRep_FacesFiller.hxx>
#include <TopOpeBRep_EdgesFiller.hxx>
#include <TopOpeBRep_FaceEdgeFiller.hxx>
#include <TopOpeBRep_DSFiller.hxx>

void bind_TopOpeBRep_DSFiller(py::module &mod){

py::class_<TopOpeBRep_DSFiller> cls_TopOpeBRep_DSFiller(mod, "TopOpeBRep_DSFiller", "Provides class methods to fill a datastructure with results of intersections.");

// Constructors
cls_TopOpeBRep_DSFiller.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_DSFiller.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_DSFiller::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_DSFiller.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_DSFiller::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_DSFiller.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_DSFiller::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_DSFiller.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_DSFiller::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_DSFiller.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_DSFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_DSFiller.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_DSFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_DSFiller.def("PShapeClassifier", (TopOpeBRepTool_PShapeClassifier (TopOpeBRep_DSFiller::*)() const) &TopOpeBRep_DSFiller::PShapeClassifier, "return field myPShapeClassifier. set field myPShapeClassifier.");
cls_TopOpeBRep_DSFiller.def("Insert", [](TopOpeBRep_DSFiller &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a2) -> void { return self.Insert(a0, a1, a2); });
cls_TopOpeBRep_DSFiller.def("Insert", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Boolean)) &TopOpeBRep_DSFiller::Insert, "Stores in <DS> the intersections of <S1> and <S2>. if orientFORWARD = True S FORWARD,REVERSED --> FORWARD S EXTERNAL,INTERNAL --> EXTERNAL,INTERNAL", py::arg("S1"), py::arg("S2"), py::arg("HDS"), py::arg("orientFORWARD"));
cls_TopOpeBRep_DSFiller.def("InsertIntersection", [](TopOpeBRep_DSFiller &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a2) -> void { return self.InsertIntersection(a0, a1, a2); });
cls_TopOpeBRep_DSFiller.def("InsertIntersection", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Boolean)) &TopOpeBRep_DSFiller::InsertIntersection, "Stores in <DS> the intersections of <S1> and <S2>. if orientFORWARD = True S FORWAR,REVERSED --> FORWARD S EXTERNAL,INTERNAL --> EXTERNAL,INTERNAL", py::arg("S1"), py::arg("S2"), py::arg("HDS"), py::arg("orientFORWARD"));
cls_TopOpeBRep_DSFiller.def("Complete", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_DSFiller::Complete, "None", py::arg("HDS"));
cls_TopOpeBRep_DSFiller.def("Insert2d", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_DSFiller::Insert2d, "Stores in <DS> the intersections of <S1> and <S2>. S1 et S2 contain only SameDomain Face", py::arg("S1"), py::arg("S2"), py::arg("HDS"));
cls_TopOpeBRep_DSFiller.def("InsertIntersection2d", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_DSFiller::InsertIntersection2d, "S1, S2 set of tangent face lance les intersections 2d pour coder correctement les faces SameDomain.", py::arg("S1"), py::arg("S2"), py::arg("HDS"));
cls_TopOpeBRep_DSFiller.def("IsMadeOf1d", (Standard_Boolean (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &) const) &TopOpeBRep_DSFiller::IsMadeOf1d, "None", py::arg("S"));
cls_TopOpeBRep_DSFiller.def("IsContext1d", (Standard_Boolean (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &) const) &TopOpeBRep_DSFiller::IsContext1d, "None", py::arg("S"));
cls_TopOpeBRep_DSFiller.def("Insert1d", [](TopOpeBRep_DSFiller &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const TopoDS_Face & a2, const TopoDS_Face & a3, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a4) -> void { return self.Insert1d(a0, a1, a2, a3, a4); });
cls_TopOpeBRep_DSFiller.def("Insert1d", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Face &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Boolean)) &TopOpeBRep_DSFiller::Insert1d, "Stores in <DS> the intersections of <S1> and <S2>. S1 and S2 are edges or wires. S1 edges have a 2d representation in face F1 S2 edges have a 2d representation in face F2 F1 is the face which surface is taken as reference for 2d description of S1 and S2 edges. if orientFORWARD = True S FORWARD,REVERSED --> FORWARD S EXTERNAL,INTERNAL --> EXTERNAL,INTERNAL", py::arg("S1"), py::arg("S2"), py::arg("F1"), py::arg("F2"), py::arg("HDS"), py::arg("orientFORWARD"));
cls_TopOpeBRep_DSFiller.def("ChangeShapeIntersector", (TopOpeBRep_ShapeIntersector & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeShapeIntersector, "None");
cls_TopOpeBRep_DSFiller.def("ChangeShapeIntersector2d", (TopOpeBRep_ShapeIntersector2d & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeShapeIntersector2d, "None");
cls_TopOpeBRep_DSFiller.def("ChangeFacesFiller", (TopOpeBRep_FacesFiller & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeFacesFiller, "None");
cls_TopOpeBRep_DSFiller.def("ChangeEdgesFiller", (TopOpeBRep_EdgesFiller & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeEdgesFiller, "None");
cls_TopOpeBRep_DSFiller.def("ChangeFaceEdgeFiller", (TopOpeBRep_FaceEdgeFiller & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeFaceEdgeFiller, "None");
cls_TopOpeBRep_DSFiller.def("GapFiller", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const) &TopOpeBRep_DSFiller::GapFiller, "None", py::arg("HDS"));
cls_TopOpeBRep_DSFiller.def("CompleteDS", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const) &TopOpeBRep_DSFiller::CompleteDS, "Update the data structure with relevant informations deduced from the intersections.", py::arg("HDS"));
cls_TopOpeBRep_DSFiller.def("Filter", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const) &TopOpeBRep_DSFiller::Filter, "None", py::arg("HDS"));
cls_TopOpeBRep_DSFiller.def("Reducer", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const) &TopOpeBRep_DSFiller::Reducer, "None", py::arg("HDS"));
cls_TopOpeBRep_DSFiller.def("RemoveUnsharedGeometry", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_DSFiller::RemoveUnsharedGeometry, "None", py::arg("HDS"));
cls_TopOpeBRep_DSFiller.def("Checker", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const) &TopOpeBRep_DSFiller::Checker, "None", py::arg("HDS"));
cls_TopOpeBRep_DSFiller.def("CompleteDS2d", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const) &TopOpeBRep_DSFiller::CompleteDS2d, "Update the data structure with relevant informations deduced from the intersections 2d.", py::arg("HDS"));

// Enums

}