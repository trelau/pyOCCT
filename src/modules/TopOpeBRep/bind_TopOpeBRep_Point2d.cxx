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
#include <IntRes2d_IntersectionPoint.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRep_P2Dstatus.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRep_Hctxff2d.hxx>
#include <TopOpeBRep_Hctxee2d.hxx>
#include <TopOpeBRep_EdgesIntersector.hxx>
#include <TopOpeBRep_Point2d.hxx>

void bind_TopOpeBRep_Point2d(py::module &mod){

py::class_<TopOpeBRep_Point2d, std::unique_ptr<TopOpeBRep_Point2d, Deleter<TopOpeBRep_Point2d>>> cls_TopOpeBRep_Point2d(mod, "TopOpeBRep_Point2d", "None");

// Constructors
cls_TopOpeBRep_Point2d.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_Point2d.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_Point2d::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_Point2d.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_Point2d::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_Point2d.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_Point2d::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_Point2d.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_Point2d::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_Point2d.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_Point2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_Point2d.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_Point2d::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_Point2d.def("Dump", [](TopOpeBRep_Point2d &self) -> void { return self.Dump(); });
cls_TopOpeBRep_Point2d.def("Dump", [](TopOpeBRep_Point2d &self, const Standard_Integer a0) -> void { return self.Dump(a0); });
cls_TopOpeBRep_Point2d.def("Dump", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const Standard_Integer) const) &TopOpeBRep_Point2d::Dump, "None", py::arg("ie1"), py::arg("ie2"));
cls_TopOpeBRep_Point2d.def("SetPint", (void (TopOpeBRep_Point2d::*)(const IntRes2d_IntersectionPoint &)) &TopOpeBRep_Point2d::SetPint, "None", py::arg("P"));
cls_TopOpeBRep_Point2d.def("HasPint", (Standard_Boolean (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::HasPint, "None");
cls_TopOpeBRep_Point2d.def("Pint", (const IntRes2d_IntersectionPoint & (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::Pint, "None");
cls_TopOpeBRep_Point2d.def("SetIsVertex", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRep_Point2d::SetIsVertex, "None", py::arg("I"), py::arg("B"));
cls_TopOpeBRep_Point2d.def("IsVertex", (Standard_Boolean (TopOpeBRep_Point2d::*)(const Standard_Integer) const) &TopOpeBRep_Point2d::IsVertex, "None", py::arg("I"));
cls_TopOpeBRep_Point2d.def("SetVertex", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const TopoDS_Vertex &)) &TopOpeBRep_Point2d::SetVertex, "None", py::arg("I"), py::arg("V"));
cls_TopOpeBRep_Point2d.def("Vertex", (const TopoDS_Vertex & (TopOpeBRep_Point2d::*)(const Standard_Integer) const) &TopOpeBRep_Point2d::Vertex, "None", py::arg("I"));
cls_TopOpeBRep_Point2d.def("SetTransition", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const TopOpeBRepDS_Transition &)) &TopOpeBRep_Point2d::SetTransition, "None", py::arg("I"), py::arg("T"));
cls_TopOpeBRep_Point2d.def("Transition", (const TopOpeBRepDS_Transition & (TopOpeBRep_Point2d::*)(const Standard_Integer) const) &TopOpeBRep_Point2d::Transition, "None", py::arg("I"));
cls_TopOpeBRep_Point2d.def("ChangeTransition", (TopOpeBRepDS_Transition & (TopOpeBRep_Point2d::*)(const Standard_Integer)) &TopOpeBRep_Point2d::ChangeTransition, "None", py::arg("I"));
cls_TopOpeBRep_Point2d.def("SetParameter", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const Standard_Real)) &TopOpeBRep_Point2d::SetParameter, "None", py::arg("I"), py::arg("P"));
cls_TopOpeBRep_Point2d.def("Parameter", (Standard_Real (TopOpeBRep_Point2d::*)(const Standard_Integer) const) &TopOpeBRep_Point2d::Parameter, "None", py::arg("I"));
cls_TopOpeBRep_Point2d.def("SetIsPointOfSegment", (void (TopOpeBRep_Point2d::*)(const Standard_Boolean)) &TopOpeBRep_Point2d::SetIsPointOfSegment, "None", py::arg("B"));
cls_TopOpeBRep_Point2d.def("IsPointOfSegment", (Standard_Boolean (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::IsPointOfSegment, "None");
cls_TopOpeBRep_Point2d.def("SetSegmentAncestors", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_Point2d::SetSegmentAncestors, "None", py::arg("IP1"), py::arg("IP2"));
cls_TopOpeBRep_Point2d.def("SegmentAncestors", [](TopOpeBRep_Point2d &self, Standard_Integer & IP1, Standard_Integer & IP2){ Standard_Boolean rv = self.SegmentAncestors(IP1, IP2); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IP1, IP2); }, "None", py::arg("IP1"), py::arg("IP2"));
cls_TopOpeBRep_Point2d.def("SetStatus", (void (TopOpeBRep_Point2d::*)(const TopOpeBRep_P2Dstatus)) &TopOpeBRep_Point2d::SetStatus, "None", py::arg("S"));
cls_TopOpeBRep_Point2d.def("Status", (TopOpeBRep_P2Dstatus (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::Status, "None");
cls_TopOpeBRep_Point2d.def("SetIndex", (void (TopOpeBRep_Point2d::*)(const Standard_Integer)) &TopOpeBRep_Point2d::SetIndex, "None", py::arg("X"));
cls_TopOpeBRep_Point2d.def("Index", (Standard_Integer (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::Index, "None");
cls_TopOpeBRep_Point2d.def("SetValue", (void (TopOpeBRep_Point2d::*)(const gp_Pnt &)) &TopOpeBRep_Point2d::SetValue, "None", py::arg("P"));
cls_TopOpeBRep_Point2d.def("Value", (const gp_Pnt & (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::Value, "None");
cls_TopOpeBRep_Point2d.def("SetValue2d", (void (TopOpeBRep_Point2d::*)(const gp_Pnt2d &)) &TopOpeBRep_Point2d::SetValue2d, "None", py::arg("P"));
cls_TopOpeBRep_Point2d.def("Value2d", (const gp_Pnt2d & (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::Value2d, "None");
cls_TopOpeBRep_Point2d.def("SetKeep", (void (TopOpeBRep_Point2d::*)(const Standard_Boolean)) &TopOpeBRep_Point2d::SetKeep, "None", py::arg("B"));
cls_TopOpeBRep_Point2d.def("Keep", (Standard_Boolean (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::Keep, "None");
cls_TopOpeBRep_Point2d.def("SetEdgesConfig", (void (TopOpeBRep_Point2d::*)(const TopOpeBRepDS_Config)) &TopOpeBRep_Point2d::SetEdgesConfig, "None", py::arg("C"));
cls_TopOpeBRep_Point2d.def("EdgesConfig", (TopOpeBRepDS_Config (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::EdgesConfig, "None");
cls_TopOpeBRep_Point2d.def("SetTolerance", (void (TopOpeBRep_Point2d::*)(const Standard_Real)) &TopOpeBRep_Point2d::SetTolerance, "None", py::arg("T"));
cls_TopOpeBRep_Point2d.def("Tolerance", (Standard_Real (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::Tolerance, "None");
cls_TopOpeBRep_Point2d.def("SetHctxff2d", (void (TopOpeBRep_Point2d::*)(const opencascade::handle<TopOpeBRep_Hctxff2d> &)) &TopOpeBRep_Point2d::SetHctxff2d, "None", py::arg("ff2d"));
cls_TopOpeBRep_Point2d.def("Hctxff2d", (opencascade::handle<TopOpeBRep_Hctxff2d> (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::Hctxff2d, "None");
cls_TopOpeBRep_Point2d.def("SetHctxee2d", (void (TopOpeBRep_Point2d::*)(const opencascade::handle<TopOpeBRep_Hctxee2d> &)) &TopOpeBRep_Point2d::SetHctxee2d, "None", py::arg("ee2d"));
cls_TopOpeBRep_Point2d.def("Hctxee2d", (opencascade::handle<TopOpeBRep_Hctxee2d> (TopOpeBRep_Point2d::*)() const) &TopOpeBRep_Point2d::Hctxee2d, "None");

// Enums

}