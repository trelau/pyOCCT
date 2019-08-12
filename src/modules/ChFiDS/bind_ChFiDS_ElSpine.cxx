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
#include <Adaptor3d_Curve.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Ax1.hxx>
#include <Geom_Curve.hxx>
#include <ChFiDS_SurfData.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <TColgp_SequenceOfAx1.hxx>
#include <ChFiDS_ElSpine.hxx>

void bind_ChFiDS_ElSpine(py::module &mod){

py::class_<ChFiDS_ElSpine, std::unique_ptr<ChFiDS_ElSpine, Deleter<ChFiDS_ElSpine>>, Adaptor3d_Curve> cls_ChFiDS_ElSpine(mod, "ChFiDS_ElSpine", "Elementary Spine for cheminements and approximations.");

// Constructors
cls_ChFiDS_ElSpine.def(py::init<>());

// Fields

// Methods
// cls_ChFiDS_ElSpine.def_static("operator new_", (void * (*)(size_t)) &ChFiDS_ElSpine::operator new, "None", py::arg("theSize"));
// cls_ChFiDS_ElSpine.def_static("operator delete_", (void (*)(void *)) &ChFiDS_ElSpine::operator delete, "None", py::arg("theAddress"));
// cls_ChFiDS_ElSpine.def_static("operator new[]_", (void * (*)(size_t)) &ChFiDS_ElSpine::operator new[], "None", py::arg("theSize"));
// cls_ChFiDS_ElSpine.def_static("operator delete[]_", (void (*)(void *)) &ChFiDS_ElSpine::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiDS_ElSpine.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiDS_ElSpine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiDS_ElSpine.def_static("operator delete_", (void (*)(void *, void *)) &ChFiDS_ElSpine::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFiDS_ElSpine.def("FirstParameter", (Standard_Real (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::FirstParameter, "None");
cls_ChFiDS_ElSpine.def("LastParameter", (Standard_Real (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::LastParameter, "None");
cls_ChFiDS_ElSpine.def("GetSavedFirstParameter", (Standard_Real (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::GetSavedFirstParameter, "None");
cls_ChFiDS_ElSpine.def("GetSavedLastParameter", (Standard_Real (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::GetSavedLastParameter, "None");
cls_ChFiDS_ElSpine.def("Continuity", (GeomAbs_Shape (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Continuity, "None");
cls_ChFiDS_ElSpine.def("NbIntervals", (Standard_Integer (ChFiDS_ElSpine::*)(const GeomAbs_Shape) const) &ChFiDS_ElSpine::NbIntervals, "None", py::arg("S"));
cls_ChFiDS_ElSpine.def("Intervals", (void (ChFiDS_ElSpine::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &ChFiDS_ElSpine::Intervals, "None", py::arg("T"), py::arg("S"));
cls_ChFiDS_ElSpine.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (ChFiDS_ElSpine::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &ChFiDS_ElSpine::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion.", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_ChFiDS_ElSpine.def("Resolution", (Standard_Real (ChFiDS_ElSpine::*)(const Standard_Real) const) &ChFiDS_ElSpine::Resolution, "None", py::arg("R3d"));
cls_ChFiDS_ElSpine.def("GetType", (GeomAbs_CurveType (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::GetType, "None");
cls_ChFiDS_ElSpine.def("IsPeriodic", (Standard_Boolean (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::IsPeriodic, "None");
cls_ChFiDS_ElSpine.def("SetPeriodic", (void (ChFiDS_ElSpine::*)(const Standard_Boolean)) &ChFiDS_ElSpine::SetPeriodic, "None", py::arg("I"));
cls_ChFiDS_ElSpine.def("Period", (Standard_Real (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Period, "None");
cls_ChFiDS_ElSpine.def("Value", (gp_Pnt (ChFiDS_ElSpine::*)(const Standard_Real) const) &ChFiDS_ElSpine::Value, "None", py::arg("AbsC"));
cls_ChFiDS_ElSpine.def("D0", (void (ChFiDS_ElSpine::*)(const Standard_Real, gp_Pnt &) const) &ChFiDS_ElSpine::D0, "None", py::arg("AbsC"), py::arg("P"));
cls_ChFiDS_ElSpine.def("D1", (void (ChFiDS_ElSpine::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &ChFiDS_ElSpine::D1, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"));
cls_ChFiDS_ElSpine.def("D2", (void (ChFiDS_ElSpine::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &ChFiDS_ElSpine::D2, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_ChFiDS_ElSpine.def("D3", (void (ChFiDS_ElSpine::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &ChFiDS_ElSpine::D3, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_ChFiDS_ElSpine.def("FirstParameter", (void (ChFiDS_ElSpine::*)(const Standard_Real)) &ChFiDS_ElSpine::FirstParameter, "None", py::arg("P"));
cls_ChFiDS_ElSpine.def("LastParameter", (void (ChFiDS_ElSpine::*)(const Standard_Real)) &ChFiDS_ElSpine::LastParameter, "None", py::arg("P"));
cls_ChFiDS_ElSpine.def("SaveFirstParameter", (void (ChFiDS_ElSpine::*)()) &ChFiDS_ElSpine::SaveFirstParameter, "None");
cls_ChFiDS_ElSpine.def("SaveLastParameter", (void (ChFiDS_ElSpine::*)()) &ChFiDS_ElSpine::SaveLastParameter, "None");
cls_ChFiDS_ElSpine.def("SetOrigin", (void (ChFiDS_ElSpine::*)(const Standard_Real)) &ChFiDS_ElSpine::SetOrigin, "None", py::arg("O"));
cls_ChFiDS_ElSpine.def("FirstPointAndTgt", (void (ChFiDS_ElSpine::*)(gp_Pnt &, gp_Vec &) const) &ChFiDS_ElSpine::FirstPointAndTgt, "None", py::arg("P"), py::arg("T"));
cls_ChFiDS_ElSpine.def("LastPointAndTgt", (void (ChFiDS_ElSpine::*)(gp_Pnt &, gp_Vec &) const) &ChFiDS_ElSpine::LastPointAndTgt, "None", py::arg("P"), py::arg("T"));
cls_ChFiDS_ElSpine.def("NbVertices", (Standard_Integer (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::NbVertices, "None");
cls_ChFiDS_ElSpine.def("VertexWithTangent", (const gp_Ax1 & (ChFiDS_ElSpine::*)(const Standard_Integer) const) &ChFiDS_ElSpine::VertexWithTangent, "None", py::arg("Index"));
cls_ChFiDS_ElSpine.def("SetFirstPointAndTgt", (void (ChFiDS_ElSpine::*)(const gp_Pnt &, const gp_Vec &)) &ChFiDS_ElSpine::SetFirstPointAndTgt, "None", py::arg("P"), py::arg("T"));
cls_ChFiDS_ElSpine.def("SetLastPointAndTgt", (void (ChFiDS_ElSpine::*)(const gp_Pnt &, const gp_Vec &)) &ChFiDS_ElSpine::SetLastPointAndTgt, "None", py::arg("P"), py::arg("T"));
cls_ChFiDS_ElSpine.def("AddVertexWithTangent", (void (ChFiDS_ElSpine::*)(const gp_Ax1 &)) &ChFiDS_ElSpine::AddVertexWithTangent, "None", py::arg("anAx1"));
cls_ChFiDS_ElSpine.def("SetCurve", (void (ChFiDS_ElSpine::*)(const opencascade::handle<Geom_Curve> &)) &ChFiDS_ElSpine::SetCurve, "None", py::arg("C"));
cls_ChFiDS_ElSpine.def("Previous", (const opencascade::handle<ChFiDS_SurfData> & (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Previous, "None");
cls_ChFiDS_ElSpine.def("ChangePrevious", (opencascade::handle<ChFiDS_SurfData> & (ChFiDS_ElSpine::*)()) &ChFiDS_ElSpine::ChangePrevious, "None");
cls_ChFiDS_ElSpine.def("Next", (const opencascade::handle<ChFiDS_SurfData> & (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Next, "None");
cls_ChFiDS_ElSpine.def("ChangeNext", (opencascade::handle<ChFiDS_SurfData> & (ChFiDS_ElSpine::*)()) &ChFiDS_ElSpine::ChangeNext, "None");
cls_ChFiDS_ElSpine.def("Line", (gp_Lin (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Line, "None");
cls_ChFiDS_ElSpine.def("Circle", (gp_Circ (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Circle, "None");
cls_ChFiDS_ElSpine.def("Ellipse", (gp_Elips (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Ellipse, "None");
cls_ChFiDS_ElSpine.def("Hyperbola", (gp_Hypr (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Hyperbola, "None");
cls_ChFiDS_ElSpine.def("Parabola", (gp_Parab (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Parabola, "None");
cls_ChFiDS_ElSpine.def("Bezier", (opencascade::handle<Geom_BezierCurve> (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::Bezier, "None");
cls_ChFiDS_ElSpine.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (ChFiDS_ElSpine::*)() const) &ChFiDS_ElSpine::BSpline, "None");

// Enums

}