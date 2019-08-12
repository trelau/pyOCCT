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
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <BRepAdaptor_HArray1OfCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <BRepAdaptor_CompCurve.hxx>

void bind_BRepAdaptor_CompCurve(py::module &mod){

py::class_<BRepAdaptor_CompCurve, std::unique_ptr<BRepAdaptor_CompCurve, Deleter<BRepAdaptor_CompCurve>>, Adaptor3d_Curve> cls_BRepAdaptor_CompCurve(mod, "BRepAdaptor_CompCurve", "The Curve from BRepAdaptor allows to use a Wire of the BRep topology like a 3D curve. Warning: With this class of curve, C0 and C1 continuities are not assumed. So be careful with some algorithm! Please note that BRepAdaptor_CompCurve cannot be periodic curve at all (even if it contains single periodic edge).");

// Constructors
cls_BRepAdaptor_CompCurve.def(py::init<>());
cls_BRepAdaptor_CompCurve.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepAdaptor_CompCurve.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("W"), py::arg("KnotByCurvilinearAbcissa"));
cls_BRepAdaptor_CompCurve.def(py::init<const TopoDS_Wire &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("W"), py::arg("KnotByCurvilinearAbcissa"), py::arg("First"), py::arg("Last"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepAdaptor_CompCurve.def_static("operator new_", (void * (*)(size_t)) &BRepAdaptor_CompCurve::operator new, "None", py::arg("theSize"));
// cls_BRepAdaptor_CompCurve.def_static("operator delete_", (void (*)(void *)) &BRepAdaptor_CompCurve::operator delete, "None", py::arg("theAddress"));
// cls_BRepAdaptor_CompCurve.def_static("operator new[]_", (void * (*)(size_t)) &BRepAdaptor_CompCurve::operator new[], "None", py::arg("theSize"));
// cls_BRepAdaptor_CompCurve.def_static("operator delete[]_", (void (*)(void *)) &BRepAdaptor_CompCurve::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAdaptor_CompCurve.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAdaptor_CompCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAdaptor_CompCurve.def_static("operator delete_", (void (*)(void *, void *)) &BRepAdaptor_CompCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAdaptor_CompCurve.def("Initialize", (void (BRepAdaptor_CompCurve::*)(const TopoDS_Wire &, const Standard_Boolean)) &BRepAdaptor_CompCurve::Initialize, "Sets the wire <W>.", py::arg("W"), py::arg("KnotByCurvilinearAbcissa"));
cls_BRepAdaptor_CompCurve.def("Initialize", (void (BRepAdaptor_CompCurve::*)(const TopoDS_Wire &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepAdaptor_CompCurve::Initialize, "Sets wire <W> and trimmed parameter.", py::arg("W"), py::arg("KnotByCurvilinearAbcissa"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_BRepAdaptor_CompCurve.def("Wire", (const TopoDS_Wire & (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Wire, "Returns the wire.");
cls_BRepAdaptor_CompCurve.def("Edge", [](BRepAdaptor_CompCurve &self, const Standard_Real U, TopoDS_Edge & E, Standard_Real & UonE){ self.Edge(U, E, UonE); return UonE; }, "returns an edge and one parameter on them corresponding to the parameter U.", py::arg("U"), py::arg("E"), py::arg("UonE"));
cls_BRepAdaptor_CompCurve.def("FirstParameter", (Standard_Real (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::FirstParameter, "None");
cls_BRepAdaptor_CompCurve.def("LastParameter", (Standard_Real (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::LastParameter, "None");
cls_BRepAdaptor_CompCurve.def("Continuity", (GeomAbs_Shape (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Continuity, "None");
cls_BRepAdaptor_CompCurve.def("NbIntervals", (Standard_Integer (BRepAdaptor_CompCurve::*)(const GeomAbs_Shape) const) &BRepAdaptor_CompCurve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepAdaptor_CompCurve.def("Intervals", (void (BRepAdaptor_CompCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepAdaptor_CompCurve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepAdaptor_CompCurve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (BRepAdaptor_CompCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &BRepAdaptor_CompCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_BRepAdaptor_CompCurve.def("IsClosed", (Standard_Boolean (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::IsClosed, "None");
cls_BRepAdaptor_CompCurve.def("IsPeriodic", (Standard_Boolean (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::IsPeriodic, "None");
cls_BRepAdaptor_CompCurve.def("Period", (Standard_Real (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Period, "None");
cls_BRepAdaptor_CompCurve.def("Value", (gp_Pnt (BRepAdaptor_CompCurve::*)(const Standard_Real) const) &BRepAdaptor_CompCurve::Value, "Computes the point of parameter U on the curve", py::arg("U"));
cls_BRepAdaptor_CompCurve.def("D0", (void (BRepAdaptor_CompCurve::*)(const Standard_Real, gp_Pnt &) const) &BRepAdaptor_CompCurve::D0, "Computes the point of parameter U.", py::arg("U"), py::arg("P"));
cls_BRepAdaptor_CompCurve.def("D1", (void (BRepAdaptor_CompCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &BRepAdaptor_CompCurve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_BRepAdaptor_CompCurve.def("D2", (void (BRepAdaptor_CompCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &BRepAdaptor_CompCurve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_BRepAdaptor_CompCurve.def("D3", (void (BRepAdaptor_CompCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BRepAdaptor_CompCurve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepAdaptor_CompCurve.def("DN", (gp_Vec (BRepAdaptor_CompCurve::*)(const Standard_Real, const Standard_Integer) const) &BRepAdaptor_CompCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_BRepAdaptor_CompCurve.def("Resolution", (Standard_Real (BRepAdaptor_CompCurve::*)(const Standard_Real) const) &BRepAdaptor_CompCurve::Resolution, "returns the parametric resolution", py::arg("R3d"));
cls_BRepAdaptor_CompCurve.def("GetType", (GeomAbs_CurveType (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::GetType, "None");
cls_BRepAdaptor_CompCurve.def("Line", (gp_Lin (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Line, "None");
cls_BRepAdaptor_CompCurve.def("Circle", (gp_Circ (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Circle, "None");
cls_BRepAdaptor_CompCurve.def("Ellipse", (gp_Elips (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Ellipse, "None");
cls_BRepAdaptor_CompCurve.def("Hyperbola", (gp_Hypr (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Hyperbola, "None");
cls_BRepAdaptor_CompCurve.def("Parabola", (gp_Parab (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Parabola, "None");
cls_BRepAdaptor_CompCurve.def("Degree", (Standard_Integer (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Degree, "None");
cls_BRepAdaptor_CompCurve.def("IsRational", (Standard_Boolean (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::IsRational, "None");
cls_BRepAdaptor_CompCurve.def("NbPoles", (Standard_Integer (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::NbPoles, "None");
cls_BRepAdaptor_CompCurve.def("NbKnots", (Standard_Integer (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::NbKnots, "None");
cls_BRepAdaptor_CompCurve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::Bezier, "None");
cls_BRepAdaptor_CompCurve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (BRepAdaptor_CompCurve::*)() const) &BRepAdaptor_CompCurve::BSpline, "None");

// Enums

}