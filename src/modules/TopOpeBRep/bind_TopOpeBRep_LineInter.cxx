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
#include <Standard_Handle.hxx>
#include <IntPatch_Line.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRep_TypeLineCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRep_VPointInter.hxx>
#include <TopOpeBRep_WPointInter.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Shape.hxx>
#include <IntPatch_WLine.hxx>
#include <IntPatch_GLine.hxx>
#include <IntPatch_RLine.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRep_Bipoint.hxx>
#include <Standard_OStream.hxx>
#include <IntPatch_ALine.hxx>
#include <TopOpeBRep_HArray1OfVPointInter.hxx>
#include <TopOpeBRep_LineInter.hxx>

void bind_TopOpeBRep_LineInter(py::module &mod){

py::class_<TopOpeBRep_LineInter, std::unique_ptr<TopOpeBRep_LineInter>> cls_TopOpeBRep_LineInter(mod, "TopOpeBRep_LineInter", "None");

// Constructors
cls_TopOpeBRep_LineInter.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_LineInter.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_LineInter::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_LineInter.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_LineInter::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_LineInter.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_LineInter::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_LineInter.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_LineInter::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_LineInter.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_LineInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_LineInter.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_LineInter::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_LineInter.def("SetLine", (void (TopOpeBRep_LineInter::*)(const opencascade::handle<IntPatch_Line> &, const BRepAdaptor_Surface &, const BRepAdaptor_Surface &)) &TopOpeBRep_LineInter::SetLine, "None", py::arg("L"), py::arg("S1"), py::arg("S2"));
cls_TopOpeBRep_LineInter.def("SetFaces", (void (TopOpeBRep_LineInter::*)(const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRep_LineInter::SetFaces, "None", py::arg("F1"), py::arg("F2"));
cls_TopOpeBRep_LineInter.def("TypeLineCurve", (TopOpeBRep_TypeLineCurve (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::TypeLineCurve, "None");
cls_TopOpeBRep_LineInter.def("NbVPoint", (Standard_Integer (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::NbVPoint, "None");
cls_TopOpeBRep_LineInter.def("VPoint", (const TopOpeBRep_VPointInter & (TopOpeBRep_LineInter::*)(const Standard_Integer) const) &TopOpeBRep_LineInter::VPoint, "None", py::arg("I"));
cls_TopOpeBRep_LineInter.def("ChangeVPoint", (TopOpeBRep_VPointInter & (TopOpeBRep_LineInter::*)(const Standard_Integer)) &TopOpeBRep_LineInter::ChangeVPoint, "None", py::arg("I"));
cls_TopOpeBRep_LineInter.def("SetINL", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::SetINL, "None");
cls_TopOpeBRep_LineInter.def("INL", (Standard_Boolean (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::INL, "None");
cls_TopOpeBRep_LineInter.def("SetIsVClosed", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::SetIsVClosed, "None");
cls_TopOpeBRep_LineInter.def("IsVClosed", (Standard_Boolean (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::IsVClosed, "None");
cls_TopOpeBRep_LineInter.def("SetOK", (void (TopOpeBRep_LineInter::*)(const Standard_Boolean)) &TopOpeBRep_LineInter::SetOK, "None", py::arg("B"));
cls_TopOpeBRep_LineInter.def("OK", (Standard_Boolean (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::OK, "None");
cls_TopOpeBRep_LineInter.def("SetHasVPonR", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::SetHasVPonR, "None");
cls_TopOpeBRep_LineInter.def("HasVPonR", (Standard_Boolean (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::HasVPonR, "None");
cls_TopOpeBRep_LineInter.def("SetVPBounds", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::SetVPBounds, "None");
cls_TopOpeBRep_LineInter.def("VPBounds", [](TopOpeBRep_LineInter &self, Standard_Integer & f, Standard_Integer & l, Standard_Integer & n){ self.VPBounds(f, l, n); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(f, l, n); }, "None", py::arg("f"), py::arg("l"), py::arg("n"));
cls_TopOpeBRep_LineInter.def("IsPeriodic", (Standard_Boolean (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::IsPeriodic, "None");
cls_TopOpeBRep_LineInter.def("Period", (Standard_Real (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::Period, "None");
cls_TopOpeBRep_LineInter.def("Bounds", [](TopOpeBRep_LineInter &self, Standard_Real & f, Standard_Real & l){ self.Bounds(f, l); return std::tuple<Standard_Real &, Standard_Real &>(f, l); }, "None", py::arg("f"), py::arg("l"));
cls_TopOpeBRep_LineInter.def("HasVInternal", (Standard_Boolean (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::HasVInternal, "None");
cls_TopOpeBRep_LineInter.def("NbWPoint", (Standard_Integer (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::NbWPoint, "None");
cls_TopOpeBRep_LineInter.def("WPoint", (const TopOpeBRep_WPointInter & (TopOpeBRep_LineInter::*)(const Standard_Integer)) &TopOpeBRep_LineInter::WPoint, "None", py::arg("I"));
cls_TopOpeBRep_LineInter.def("TransitionOnS1", (IntSurf_TypeTrans (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::TransitionOnS1, "None");
cls_TopOpeBRep_LineInter.def("TransitionOnS2", (IntSurf_TypeTrans (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::TransitionOnS2, "None");
cls_TopOpeBRep_LineInter.def("SituationS1", (IntSurf_Situation (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::SituationS1, "None");
cls_TopOpeBRep_LineInter.def("SituationS2", (IntSurf_Situation (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::SituationS2, "None");
cls_TopOpeBRep_LineInter.def("Curve", (opencascade::handle<Geom_Curve> (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::Curve, "None");
cls_TopOpeBRep_LineInter.def("Curve", (opencascade::handle<Geom_Curve> (TopOpeBRep_LineInter::*)(const Standard_Real, const Standard_Real) const) &TopOpeBRep_LineInter::Curve, "None", py::arg("parmin"), py::arg("parmax"));
cls_TopOpeBRep_LineInter.def("Arc", (const TopoDS_Shape & (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::Arc, "returns the edge of a RESTRICTION line (or a null edge).");
cls_TopOpeBRep_LineInter.def("ArcIsEdge", (Standard_Boolean (TopOpeBRep_LineInter::*)(const Standard_Integer) const) &TopOpeBRep_LineInter::ArcIsEdge, "returns true if Arc() edge (of a RESTRICTION line) is an edge of the original face <Index> (1 or 2).", py::arg("I"));
cls_TopOpeBRep_LineInter.def("LineW", (const opencascade::handle<IntPatch_WLine> & (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::LineW, "None");
cls_TopOpeBRep_LineInter.def("LineG", (const opencascade::handle<IntPatch_GLine> & (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::LineG, "None");
cls_TopOpeBRep_LineInter.def("LineR", (const opencascade::handle<IntPatch_RLine> & (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::LineR, "None");
cls_TopOpeBRep_LineInter.def("HasFirstPoint", (Standard_Boolean (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::HasFirstPoint, "None");
cls_TopOpeBRep_LineInter.def("HasLastPoint", (Standard_Boolean (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::HasLastPoint, "None");
cls_TopOpeBRep_LineInter.def("ComputeFaceFaceTransition", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::ComputeFaceFaceTransition, "None");
cls_TopOpeBRep_LineInter.def("FaceFaceTransition", (const TopOpeBRepDS_Transition & (TopOpeBRep_LineInter::*)(const Standard_Integer) const) &TopOpeBRep_LineInter::FaceFaceTransition, "None", py::arg("I"));
cls_TopOpeBRep_LineInter.def("Index", (void (TopOpeBRep_LineInter::*)(const Standard_Integer)) &TopOpeBRep_LineInter::Index, "None", py::arg("I"));
cls_TopOpeBRep_LineInter.def("Index", (Standard_Integer (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::Index, "None");
cls_TopOpeBRep_LineInter.def("DumpType", (void (TopOpeBRep_LineInter::*)() const) &TopOpeBRep_LineInter::DumpType, "None");
cls_TopOpeBRep_LineInter.def("DumpVPoint", (void (TopOpeBRep_LineInter::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRep_LineInter::DumpVPoint, "None", py::arg("I"), py::arg("s1"), py::arg("s2"));
cls_TopOpeBRep_LineInter.def("DumpBipoint", (void (TopOpeBRep_LineInter::*)(const TopOpeBRep_Bipoint &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &TopOpeBRep_LineInter::DumpBipoint, "None", py::arg("B"), py::arg("s1"), py::arg("s2"));
cls_TopOpeBRep_LineInter.def("SetTraceIndex", (void (TopOpeBRep_LineInter::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_LineInter::SetTraceIndex, "None", py::arg("exF1"), py::arg("exF2"));
cls_TopOpeBRep_LineInter.def("GetTraceIndex", [](TopOpeBRep_LineInter &self, Standard_Integer & exF1, Standard_Integer & exF2){ self.GetTraceIndex(exF1, exF2); return std::tuple<Standard_Integer &, Standard_Integer &>(exF1, exF2); }, "None", py::arg("exF1"), py::arg("exF2"));
cls_TopOpeBRep_LineInter.def("DumpLineTransitions", (Standard_OStream & (TopOpeBRep_LineInter::*)(Standard_OStream &) const) &TopOpeBRep_LineInter::DumpLineTransitions, "None", py::arg("OS"));

// Enums

}