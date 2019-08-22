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
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <TopAbs_State.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <IntCurveSurface_SequenceOfPnt.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TopExp_Explorer.hxx>
#include <TopOpeBRep_FaceEdgeIntersector.hxx>

void bind_TopOpeBRep_FaceEdgeIntersector(py::module &mod){

py::class_<TopOpeBRep_FaceEdgeIntersector> cls_TopOpeBRep_FaceEdgeIntersector(mod, "TopOpeBRep_FaceEdgeIntersector", "Describes the intersection of a face and an edge.");

// Constructors
cls_TopOpeBRep_FaceEdgeIntersector.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_FaceEdgeIntersector.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_FaceEdgeIntersector::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_FaceEdgeIntersector.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_FaceEdgeIntersector::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_FaceEdgeIntersector.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_FaceEdgeIntersector::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_FaceEdgeIntersector.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_FaceEdgeIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_FaceEdgeIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_FaceEdgeIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_FaceEdgeIntersector.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_FaceEdgeIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_FaceEdgeIntersector.def("Perform", (void (TopOpeBRep_FaceEdgeIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_FaceEdgeIntersector::Perform, "None", py::arg("F"), py::arg("E"));
cls_TopOpeBRep_FaceEdgeIntersector.def("IsEmpty", (Standard_Boolean (TopOpeBRep_FaceEdgeIntersector::*)()) &TopOpeBRep_FaceEdgeIntersector::IsEmpty, "None");
cls_TopOpeBRep_FaceEdgeIntersector.def("Shape", (const TopoDS_Shape & (TopOpeBRep_FaceEdgeIntersector::*)(const Standard_Integer) const) &TopOpeBRep_FaceEdgeIntersector::Shape, "returns intersected face or edge according to value of <Index> = 1 or 2", py::arg("Index"));
cls_TopOpeBRep_FaceEdgeIntersector.def("ForceTolerance", (void (TopOpeBRep_FaceEdgeIntersector::*)(const Standard_Real)) &TopOpeBRep_FaceEdgeIntersector::ForceTolerance, "Force the tolerance values used by the next Perform(S1,S2) call.", py::arg("tol"));
cls_TopOpeBRep_FaceEdgeIntersector.def("Tolerance", (Standard_Real (TopOpeBRep_FaceEdgeIntersector::*)() const) &TopOpeBRep_FaceEdgeIntersector::Tolerance, "Return the tolerance value used in the last Perform() call If ForceTolerance() has been called, return the given value. If not, return value extracted from shapes.");
cls_TopOpeBRep_FaceEdgeIntersector.def("NbPoints", (Standard_Integer (TopOpeBRep_FaceEdgeIntersector::*)() const) &TopOpeBRep_FaceEdgeIntersector::NbPoints, "None");
cls_TopOpeBRep_FaceEdgeIntersector.def("InitPoint", (void (TopOpeBRep_FaceEdgeIntersector::*)()) &TopOpeBRep_FaceEdgeIntersector::InitPoint, "None");
cls_TopOpeBRep_FaceEdgeIntersector.def("MorePoint", (Standard_Boolean (TopOpeBRep_FaceEdgeIntersector::*)() const) &TopOpeBRep_FaceEdgeIntersector::MorePoint, "None");
cls_TopOpeBRep_FaceEdgeIntersector.def("NextPoint", (void (TopOpeBRep_FaceEdgeIntersector::*)()) &TopOpeBRep_FaceEdgeIntersector::NextPoint, "None");
cls_TopOpeBRep_FaceEdgeIntersector.def("Value", (gp_Pnt (TopOpeBRep_FaceEdgeIntersector::*)() const) &TopOpeBRep_FaceEdgeIntersector::Value, "return the 3D point of the current intersection point.");
cls_TopOpeBRep_FaceEdgeIntersector.def("Parameter", (Standard_Real (TopOpeBRep_FaceEdgeIntersector::*)() const) &TopOpeBRep_FaceEdgeIntersector::Parameter, "parametre de Value() sur l'arete");
cls_TopOpeBRep_FaceEdgeIntersector.def("UVPoint", (void (TopOpeBRep_FaceEdgeIntersector::*)(gp_Pnt2d &) const) &TopOpeBRep_FaceEdgeIntersector::UVPoint, "parametre de Value() sur la face", py::arg("P"));
cls_TopOpeBRep_FaceEdgeIntersector.def("State", (TopAbs_State (TopOpeBRep_FaceEdgeIntersector::*)() const) &TopOpeBRep_FaceEdgeIntersector::State, "IN ou ON / a la face. Les points OUT ne sont pas retournes.");
cls_TopOpeBRep_FaceEdgeIntersector.def("Transition", (TopOpeBRepDS_Transition (TopOpeBRep_FaceEdgeIntersector::*)(const Standard_Integer, const TopAbs_Orientation) const) &TopOpeBRep_FaceEdgeIntersector::Transition, "Index = 1 transition par rapport a la face, en cheminant sur l'arete", py::arg("Index"), py::arg("FaceOrientation"));
cls_TopOpeBRep_FaceEdgeIntersector.def("IsVertex", (Standard_Boolean (TopOpeBRep_FaceEdgeIntersector::*)(const TopoDS_Shape &, const gp_Pnt &, const Standard_Real, TopoDS_Vertex &)) &TopOpeBRep_FaceEdgeIntersector::IsVertex, "None", py::arg("S"), py::arg("P"), py::arg("Tol"), py::arg("V"));
cls_TopOpeBRep_FaceEdgeIntersector.def("IsVertex", (Standard_Boolean (TopOpeBRep_FaceEdgeIntersector::*)(const Standard_Integer, TopoDS_Vertex &)) &TopOpeBRep_FaceEdgeIntersector::IsVertex, "None", py::arg("I"), py::arg("V"));
cls_TopOpeBRep_FaceEdgeIntersector.def("Index", (Standard_Integer (TopOpeBRep_FaceEdgeIntersector::*)() const) &TopOpeBRep_FaceEdgeIntersector::Index, "trace only");

// Enums

}