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
#include <Bnd_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRep_SequenceOfPoint2d.hxx>
#include <TopOpeBRep_Point2d.hxx>
#include <TopOpeBRep_P2Dstatus.hxx>
#include <IntRes2d_IntersectionSegment.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Pnt.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <IntRes2d_Domain.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom2dInt_GInter.hxx>
#include <IntRes2d_SequenceOfIntersectionPoint.hxx>
#include <IntRes2d_SequenceOfIntersectionSegment.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopOpeBRep_EdgesIntersector.hxx>

void bind_TopOpeBRep_EdgesIntersector(py::module &mod){

py::class_<TopOpeBRep_EdgesIntersector, std::unique_ptr<TopOpeBRep_EdgesIntersector>> cls_TopOpeBRep_EdgesIntersector(mod, "TopOpeBRep_EdgesIntersector", "Describes the intersection of two edges on the same surface");

// Constructors
cls_TopOpeBRep_EdgesIntersector.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_EdgesIntersector.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_EdgesIntersector::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_EdgesIntersector.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_EdgesIntersector::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_EdgesIntersector.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_EdgesIntersector::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_EdgesIntersector.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_EdgesIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_EdgesIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_EdgesIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_EdgesIntersector.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_EdgesIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_EdgesIntersector.def("SetFaces", (void (TopOpeBRep_EdgesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_EdgesIntersector::SetFaces, "None", py::arg("F1"), py::arg("F2"));
cls_TopOpeBRep_EdgesIntersector.def("SetFaces", (void (TopOpeBRep_EdgesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &)) &TopOpeBRep_EdgesIntersector::SetFaces, "None", py::arg("F1"), py::arg("F2"), py::arg("B1"), py::arg("B2"));
cls_TopOpeBRep_EdgesIntersector.def("ForceTolerances", (void (TopOpeBRep_EdgesIntersector::*)(const Standard_Real, const Standard_Real)) &TopOpeBRep_EdgesIntersector::ForceTolerances, "None", py::arg("Tol1"), py::arg("Tol2"));
cls_TopOpeBRep_EdgesIntersector.def("Dimension", (void (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer)) &TopOpeBRep_EdgesIntersector::Dimension, "None", py::arg("D"));
cls_TopOpeBRep_EdgesIntersector.def("Dimension", (Standard_Integer (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::Dimension, "set working space dimension D = 1 for E &|| W, 2 for E in F");
cls_TopOpeBRep_EdgesIntersector.def("Perform", [](TopOpeBRep_EdgesIntersector &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.Perform(a0, a1); });
cls_TopOpeBRep_EdgesIntersector.def("Perform", (void (TopOpeBRep_EdgesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRep_EdgesIntersector::Perform, "None", py::arg("E1"), py::arg("E2"), py::arg("ReduceSegments"));
cls_TopOpeBRep_EdgesIntersector.def("IsEmpty", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)()) &TopOpeBRep_EdgesIntersector::IsEmpty, "None");
cls_TopOpeBRep_EdgesIntersector.def("HasSegment", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::HasSegment, "true if at least one intersection segment.");
cls_TopOpeBRep_EdgesIntersector.def("SameDomain", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::SameDomain, "= mySameDomain.");
cls_TopOpeBRep_EdgesIntersector.def("Edge", (const TopoDS_Shape & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const) &TopOpeBRep_EdgesIntersector::Edge, "None", py::arg("Index"));
cls_TopOpeBRep_EdgesIntersector.def("Curve", (const Geom2dAdaptor_Curve & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const) &TopOpeBRep_EdgesIntersector::Curve, "None", py::arg("Index"));
cls_TopOpeBRep_EdgesIntersector.def("Face", (const TopoDS_Shape & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const) &TopOpeBRep_EdgesIntersector::Face, "None", py::arg("Index"));
cls_TopOpeBRep_EdgesIntersector.def("Surface", (const BRepAdaptor_Surface & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const) &TopOpeBRep_EdgesIntersector::Surface, "None", py::arg("Index"));
cls_TopOpeBRep_EdgesIntersector.def("SurfacesSameOriented", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::SurfacesSameOriented, "None");
cls_TopOpeBRep_EdgesIntersector.def("FacesSameOriented", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::FacesSameOriented, "None");
cls_TopOpeBRep_EdgesIntersector.def("ToleranceMax", (Standard_Real (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::ToleranceMax, "None");
cls_TopOpeBRep_EdgesIntersector.def("Tolerances", [](TopOpeBRep_EdgesIntersector &self, Standard_Real & tol1, Standard_Real & tol2){ self.Tolerances(tol1, tol2); return std::tuple<Standard_Real &, Standard_Real &>(tol1, tol2); }, "None", py::arg("tol1"), py::arg("tol2"));
cls_TopOpeBRep_EdgesIntersector.def("NbPoints", (Standard_Integer (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::NbPoints, "None");
cls_TopOpeBRep_EdgesIntersector.def("NbSegments", (Standard_Integer (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::NbSegments, "None");
cls_TopOpeBRep_EdgesIntersector.def("Dump", [](TopOpeBRep_EdgesIntersector &self, const TCollection_AsciiString & a0) -> void { return self.Dump(a0); });
cls_TopOpeBRep_EdgesIntersector.def("Dump", [](TopOpeBRep_EdgesIntersector &self, const TCollection_AsciiString & a0, const Standard_Integer a1) -> void { return self.Dump(a0, a1); });
cls_TopOpeBRep_EdgesIntersector.def("Dump", (void (TopOpeBRep_EdgesIntersector::*)(const TCollection_AsciiString &, const Standard_Integer, const Standard_Integer)) &TopOpeBRep_EdgesIntersector::Dump, "None", py::arg("str"), py::arg("ie1"), py::arg("ie2"));
cls_TopOpeBRep_EdgesIntersector.def("InitPoint", [](TopOpeBRep_EdgesIntersector &self) -> void { return self.InitPoint(); });
cls_TopOpeBRep_EdgesIntersector.def("InitPoint", (void (TopOpeBRep_EdgesIntersector::*)(const Standard_Boolean)) &TopOpeBRep_EdgesIntersector::InitPoint, "None", py::arg("selectkeep"));
cls_TopOpeBRep_EdgesIntersector.def("MorePoint", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::MorePoint, "None");
cls_TopOpeBRep_EdgesIntersector.def("NextPoint", (void (TopOpeBRep_EdgesIntersector::*)()) &TopOpeBRep_EdgesIntersector::NextPoint, "None");
cls_TopOpeBRep_EdgesIntersector.def("Points", (const TopOpeBRep_SequenceOfPoint2d & (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::Points, "None");
cls_TopOpeBRep_EdgesIntersector.def("Point", (const TopOpeBRep_Point2d & (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::Point, "None");
cls_TopOpeBRep_EdgesIntersector.def("Point", (const TopOpeBRep_Point2d & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const) &TopOpeBRep_EdgesIntersector::Point, "None", py::arg("I"));
cls_TopOpeBRep_EdgesIntersector.def("ReduceSegment", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)(TopOpeBRep_Point2d &, TopOpeBRep_Point2d &, TopOpeBRep_Point2d &) const) &TopOpeBRep_EdgesIntersector::ReduceSegment, "None", py::arg("P1"), py::arg("P2"), py::arg("Pn"));
cls_TopOpeBRep_EdgesIntersector.def("Status1", (TopOpeBRep_P2Dstatus (TopOpeBRep_EdgesIntersector::*)() const) &TopOpeBRep_EdgesIntersector::Status1, "None");

// Enums

}