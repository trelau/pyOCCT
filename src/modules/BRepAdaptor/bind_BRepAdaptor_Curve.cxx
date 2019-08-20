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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Trsf.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
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
#include <Geom_OffsetCurve.hxx>
#include <Adaptor3d_HCurveOnSurface.hxx>
#include <BRepAdaptor_Curve.hxx>

void bind_BRepAdaptor_Curve(py::module &mod){

py::class_<BRepAdaptor_Curve, std::unique_ptr<BRepAdaptor_Curve>, Adaptor3d_Curve> cls_BRepAdaptor_Curve(mod, "BRepAdaptor_Curve", "The Curve from BRepAdaptor allows to use an Edge of the BRep topology like a 3D curve.");

// Constructors
cls_BRepAdaptor_Curve.def(py::init<>());
cls_BRepAdaptor_Curve.def(py::init<const TopoDS_Edge &>(), py::arg("E"));
cls_BRepAdaptor_Curve.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));

// Fields

// Methods
// cls_BRepAdaptor_Curve.def_static("operator new_", (void * (*)(size_t)) &BRepAdaptor_Curve::operator new, "None", py::arg("theSize"));
// cls_BRepAdaptor_Curve.def_static("operator delete_", (void (*)(void *)) &BRepAdaptor_Curve::operator delete, "None", py::arg("theAddress"));
// cls_BRepAdaptor_Curve.def_static("operator new[]_", (void * (*)(size_t)) &BRepAdaptor_Curve::operator new[], "None", py::arg("theSize"));
// cls_BRepAdaptor_Curve.def_static("operator delete[]_", (void (*)(void *)) &BRepAdaptor_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAdaptor_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAdaptor_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAdaptor_Curve.def_static("operator delete_", (void (*)(void *, void *)) &BRepAdaptor_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAdaptor_Curve.def("Initialize", (void (BRepAdaptor_Curve::*)(const TopoDS_Edge &)) &BRepAdaptor_Curve::Initialize, "Sets the Curve <me> to acces to the geometry of edge <E>.", py::arg("E"));
cls_BRepAdaptor_Curve.def("Initialize", (void (BRepAdaptor_Curve::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepAdaptor_Curve::Initialize, "Sets the Curve <me> to acces to the geometry of edge <E>. The geometry will be computed using the parametric curve of <E> on the face <F>. An Error is raised if the edge does not have a pcurve on the face.", py::arg("E"), py::arg("F"));
cls_BRepAdaptor_Curve.def("Trsf", (const gp_Trsf & (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Trsf, "Returns the coordinate system of the curve.");
cls_BRepAdaptor_Curve.def("Is3DCurve", (Standard_Boolean (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Is3DCurve, "Returns True if the edge geometry is computed from a 3D curve.");
cls_BRepAdaptor_Curve.def("IsCurveOnSurface", (Standard_Boolean (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::IsCurveOnSurface, "Returns True if the edge geometry is computed from a pcurve on a surface.");
cls_BRepAdaptor_Curve.def("Curve", (const GeomAdaptor_Curve & (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Curve, "Returns the Curve of the edge.");
cls_BRepAdaptor_Curve.def("CurveOnSurface", (const Adaptor3d_CurveOnSurface & (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::CurveOnSurface, "Returns the CurveOnSurface of the edge.");
cls_BRepAdaptor_Curve.def("Edge", (const TopoDS_Edge & (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Edge, "Returns the edge.");
cls_BRepAdaptor_Curve.def("Tolerance", (Standard_Real (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Tolerance, "Returns the edge tolerance.");
cls_BRepAdaptor_Curve.def("FirstParameter", (Standard_Real (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::FirstParameter, "None");
cls_BRepAdaptor_Curve.def("LastParameter", (Standard_Real (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::LastParameter, "None");
cls_BRepAdaptor_Curve.def("Continuity", (GeomAbs_Shape (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Continuity, "None");
cls_BRepAdaptor_Curve.def("NbIntervals", (Standard_Integer (BRepAdaptor_Curve::*)(const GeomAbs_Shape) const) &BRepAdaptor_Curve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepAdaptor_Curve.def("Intervals", (void (BRepAdaptor_Curve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepAdaptor_Curve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepAdaptor_Curve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (BRepAdaptor_Curve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &BRepAdaptor_Curve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_BRepAdaptor_Curve.def("IsClosed", (Standard_Boolean (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::IsClosed, "None");
cls_BRepAdaptor_Curve.def("IsPeriodic", (Standard_Boolean (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::IsPeriodic, "None");
cls_BRepAdaptor_Curve.def("Period", (Standard_Real (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Period, "None");
cls_BRepAdaptor_Curve.def("Value", (gp_Pnt (BRepAdaptor_Curve::*)(const Standard_Real) const) &BRepAdaptor_Curve::Value, "Computes the point of parameter U on the curve", py::arg("U"));
cls_BRepAdaptor_Curve.def("D0", (void (BRepAdaptor_Curve::*)(const Standard_Real, gp_Pnt &) const) &BRepAdaptor_Curve::D0, "Computes the point of parameter U.", py::arg("U"), py::arg("P"));
cls_BRepAdaptor_Curve.def("D1", (void (BRepAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &BRepAdaptor_Curve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_BRepAdaptor_Curve.def("D2", (void (BRepAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &BRepAdaptor_Curve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_BRepAdaptor_Curve.def("D3", (void (BRepAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BRepAdaptor_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepAdaptor_Curve.def("DN", (gp_Vec (BRepAdaptor_Curve::*)(const Standard_Real, const Standard_Integer) const) &BRepAdaptor_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_BRepAdaptor_Curve.def("Resolution", (Standard_Real (BRepAdaptor_Curve::*)(const Standard_Real) const) &BRepAdaptor_Curve::Resolution, "returns the parametric resolution", py::arg("R3d"));
cls_BRepAdaptor_Curve.def("GetType", (GeomAbs_CurveType (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::GetType, "None");
cls_BRepAdaptor_Curve.def("Line", (gp_Lin (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Line, "None");
cls_BRepAdaptor_Curve.def("Circle", (gp_Circ (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Circle, "None");
cls_BRepAdaptor_Curve.def("Ellipse", (gp_Elips (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Ellipse, "None");
cls_BRepAdaptor_Curve.def("Hyperbola", (gp_Hypr (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Hyperbola, "None");
cls_BRepAdaptor_Curve.def("Parabola", (gp_Parab (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Parabola, "None");
cls_BRepAdaptor_Curve.def("Degree", (Standard_Integer (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Degree, "None");
cls_BRepAdaptor_Curve.def("IsRational", (Standard_Boolean (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::IsRational, "None");
cls_BRepAdaptor_Curve.def("NbPoles", (Standard_Integer (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::NbPoles, "None");
cls_BRepAdaptor_Curve.def("NbKnots", (Standard_Integer (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::NbKnots, "None");
cls_BRepAdaptor_Curve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::Bezier, "Warning : This will make a copy of the Bezier Curve since it applies to it myTsrf . Be carefull when using this method");
cls_BRepAdaptor_Curve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::BSpline, "Warning : This will make a copy of the BSpline Curve since it applies to it myTsrf . Be carefull when using this method");
cls_BRepAdaptor_Curve.def("OffsetCurve", (opencascade::handle<Geom_OffsetCurve> (BRepAdaptor_Curve::*)() const) &BRepAdaptor_Curve::OffsetCurve, "None");

// Enums

}