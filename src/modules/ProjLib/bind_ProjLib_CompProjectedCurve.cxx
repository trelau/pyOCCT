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
#include <Adaptor2d_Curve2d.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <ProjLib_HSequenceOfHSequenceOfPnt.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Pnt.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <ProjLib_CompProjectedCurve.hxx>

void bind_ProjLib_CompProjectedCurve(py::module &mod){

py::class_<ProjLib_CompProjectedCurve, std::unique_ptr<ProjLib_CompProjectedCurve, Deleter<ProjLib_CompProjectedCurve>>, Adaptor2d_Curve2d> cls_ProjLib_CompProjectedCurve(mod, "ProjLib_CompProjectedCurve", "None");

// Constructors
cls_ProjLib_CompProjectedCurve.def(py::init<>());
cls_ProjLib_CompProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("C"), py::arg("TolU"), py::arg("TolV"));
cls_ProjLib_CompProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("C"), py::arg("TolU"), py::arg("TolV"), py::arg("MaxDist"));

// Fields

// Methods
// cls_ProjLib_CompProjectedCurve.def_static("operator new_", (void * (*)(size_t)) &ProjLib_CompProjectedCurve::operator new, "None", py::arg("theSize"));
// cls_ProjLib_CompProjectedCurve.def_static("operator delete_", (void (*)(void *)) &ProjLib_CompProjectedCurve::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_CompProjectedCurve.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_CompProjectedCurve::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_CompProjectedCurve.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_CompProjectedCurve::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_CompProjectedCurve.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_CompProjectedCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_CompProjectedCurve.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_CompProjectedCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_CompProjectedCurve.def("Init", (void (ProjLib_CompProjectedCurve::*)()) &ProjLib_CompProjectedCurve::Init, "computes a set of projected point and determine the continuous parts of the projected curves. The points corresponding to a projection on the bounds of the surface are included in this set of points.");
cls_ProjLib_CompProjectedCurve.def("Load", (void (ProjLib_CompProjectedCurve::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_CompProjectedCurve::Load, "Changes the surface.", py::arg("S"));
cls_ProjLib_CompProjectedCurve.def("Load", (void (ProjLib_CompProjectedCurve::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &ProjLib_CompProjectedCurve::Load, "Changes the curve.", py::arg("C"));
cls_ProjLib_CompProjectedCurve.def("GetSurface", (const opencascade::handle<Adaptor3d_HSurface> & (ProjLib_CompProjectedCurve::*)() const) &ProjLib_CompProjectedCurve::GetSurface, "None");
cls_ProjLib_CompProjectedCurve.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (ProjLib_CompProjectedCurve::*)() const) &ProjLib_CompProjectedCurve::GetCurve, "None");
cls_ProjLib_CompProjectedCurve.def("GetTolerance", [](ProjLib_CompProjectedCurve &self, Standard_Real & TolU, Standard_Real & TolV){ self.GetTolerance(TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("TolU"), py::arg("TolV"));
cls_ProjLib_CompProjectedCurve.def("NbCurves", (Standard_Integer (ProjLib_CompProjectedCurve::*)() const) &ProjLib_CompProjectedCurve::NbCurves, "returns the number of continuous part of the projected curve");
cls_ProjLib_CompProjectedCurve.def("Bounds", [](ProjLib_CompProjectedCurve &self, const Standard_Integer Index, Standard_Real & Udeb, Standard_Real & Ufin){ self.Bounds(Index, Udeb, Ufin); return std::tuple<Standard_Real &, Standard_Real &>(Udeb, Ufin); }, "returns the bounds of the continuous part corresponding to Index", py::arg("Index"), py::arg("Udeb"), py::arg("Ufin"));
cls_ProjLib_CompProjectedCurve.def("IsSinglePnt", (Standard_Boolean (ProjLib_CompProjectedCurve::*)(const Standard_Integer, gp_Pnt2d &) const) &ProjLib_CompProjectedCurve::IsSinglePnt, "returns True if part of projection with number Index is a single point and writes its coordinates in P", py::arg("Index"), py::arg("P"));
cls_ProjLib_CompProjectedCurve.def("IsUIso", [](ProjLib_CompProjectedCurve &self, const Standard_Integer Index, Standard_Real & U){ Standard_Boolean rv = self.IsUIso(Index, U); return std::tuple<Standard_Boolean, Standard_Real &>(rv, U); }, "returns True if part of projection with number Index is an u-isoparametric curve of input surface", py::arg("Index"), py::arg("U"));
cls_ProjLib_CompProjectedCurve.def("IsVIso", [](ProjLib_CompProjectedCurve &self, const Standard_Integer Index, Standard_Real & V){ Standard_Boolean rv = self.IsVIso(Index, V); return std::tuple<Standard_Boolean, Standard_Real &>(rv, V); }, "returns True if part of projection with number Index is an v-isoparametric curve of input surface", py::arg("Index"), py::arg("V"));
cls_ProjLib_CompProjectedCurve.def("Value", (gp_Pnt2d (ProjLib_CompProjectedCurve::*)(const Standard_Real) const) &ProjLib_CompProjectedCurve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_ProjLib_CompProjectedCurve.def("D0", (void (ProjLib_CompProjectedCurve::*)(const Standard_Real, gp_Pnt2d &) const) &ProjLib_CompProjectedCurve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_ProjLib_CompProjectedCurve.def("D1", (void (ProjLib_CompProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &ProjLib_CompProjectedCurve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_ProjLib_CompProjectedCurve.def("D2", (void (ProjLib_CompProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &ProjLib_CompProjectedCurve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_ProjLib_CompProjectedCurve.def("DN", (gp_Vec2d (ProjLib_CompProjectedCurve::*)(const Standard_Real, const Standard_Integer) const) &ProjLib_CompProjectedCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if N < 1. Raised if N > 2.", py::arg("U"), py::arg("N"));
cls_ProjLib_CompProjectedCurve.def("FirstParameter", (Standard_Real (ProjLib_CompProjectedCurve::*)() const) &ProjLib_CompProjectedCurve::FirstParameter, "Returns the first parameter of the curve C which has a projection on S.");
cls_ProjLib_CompProjectedCurve.def("LastParameter", (Standard_Real (ProjLib_CompProjectedCurve::*)() const) &ProjLib_CompProjectedCurve::LastParameter, "Returns the last parameter of the curve C which has a projection on S.");
cls_ProjLib_CompProjectedCurve.def("NbIntervals", (Standard_Integer (ProjLib_CompProjectedCurve::*)(const GeomAbs_Shape) const) &ProjLib_CompProjectedCurve::NbIntervals, "Returns the number of intervals which define an S continuous part of the projected curve", py::arg("S"));
cls_ProjLib_CompProjectedCurve.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (ProjLib_CompProjectedCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &ProjLib_CompProjectedCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 2d points confusion. If <First> >= <Last>", py::arg("FirstParam"), py::arg("LastParam"), py::arg("Tol"));
cls_ProjLib_CompProjectedCurve.def("Intervals", (void (ProjLib_CompProjectedCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &ProjLib_CompProjectedCurve::Intervals, "Returns the parameters corresponding to S discontinuities.", py::arg("T"), py::arg("S"));
cls_ProjLib_CompProjectedCurve.def("MaxDistance", (Standard_Real (ProjLib_CompProjectedCurve::*)(const Standard_Integer) const) &ProjLib_CompProjectedCurve::MaxDistance, "returns the maximum distance between curve to project and surface", py::arg("Index"));
cls_ProjLib_CompProjectedCurve.def("GetSequence", (const opencascade::handle<ProjLib_HSequenceOfHSequenceOfPnt> & (ProjLib_CompProjectedCurve::*)() const) &ProjLib_CompProjectedCurve::GetSequence, "None");
cls_ProjLib_CompProjectedCurve.def("GetType", (GeomAbs_CurveType (ProjLib_CompProjectedCurve::*)() const) &ProjLib_CompProjectedCurve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");

// Enums

}