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
#include <Adaptor3d_Surface.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <gp_Ax1.hxx>
#include <gp_Dir.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <BSplSLib_Cache.hxx>
#include <GeomEvaluator_Surface.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_OffsetCurve.hxx>
#include <BSplCLib_Cache.hxx>
#include <GeomEvaluator_Curve.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <Standard_Std.hxx>
#include <GeomAdaptor_GHSurface.hxx>
#include <Standard_Type.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <GeomAdaptor_GHCurve.hxx>
#include <GeomAdaptor_HCurve.hxx>
#include <GeomAdaptor.hxx>
#include <GeomAdaptor_SurfaceOfLinearExtrusion.hxx>
#include <GeomAdaptor_HSurfaceOfLinearExtrusion.hxx>
#include <gp_Ax3.hxx>
#include <GeomAdaptor_SurfaceOfRevolution.hxx>
#include <GeomAdaptor_HSurfaceOfRevolution.hxx>

PYBIND11_MODULE(GeomAdaptor, mod) {

py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.BSplSLib");
py::module::import("OCCT.BSplCLib");

// CLASS: GEOMADAPTOR_SURFACE
py::class_<GeomAdaptor_Surface, Adaptor3d_Surface> cls_GeomAdaptor_Surface(mod, "GeomAdaptor_Surface", "An interface between the services provided by any surface from the package Geom and those required of the surface by algorithms which use it. Creation of the loaded surface the surface is C1 by piece");

// Constructors
cls_GeomAdaptor_Surface.def(py::init<>());
cls_GeomAdaptor_Surface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
cls_GeomAdaptor_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"));
cls_GeomAdaptor_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("TolU"));
cls_GeomAdaptor_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("TolU"), py::arg("TolV"));

// Methods
// cls_GeomAdaptor_Surface.def_static("operator new_", (void * (*)(size_t)) &GeomAdaptor_Surface::operator new, "None", py::arg("theSize"));
// cls_GeomAdaptor_Surface.def_static("operator delete_", (void (*)(void *)) &GeomAdaptor_Surface::operator delete, "None", py::arg("theAddress"));
// cls_GeomAdaptor_Surface.def_static("operator new[]_", (void * (*)(size_t)) &GeomAdaptor_Surface::operator new[], "None", py::arg("theSize"));
// cls_GeomAdaptor_Surface.def_static("operator delete[]_", (void (*)(void *)) &GeomAdaptor_Surface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAdaptor_Surface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAdaptor_Surface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAdaptor_Surface.def_static("operator delete_", (void (*)(void *, void *)) &GeomAdaptor_Surface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAdaptor_Surface.def("Load", (void (GeomAdaptor_Surface::*)(const opencascade::handle<Geom_Surface> &)) &GeomAdaptor_Surface::Load, "None", py::arg("S"));
cls_GeomAdaptor_Surface.def("Load", [](GeomAdaptor_Surface &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Load(a0, a1, a2, a3, a4); });
cls_GeomAdaptor_Surface.def("Load", [](GeomAdaptor_Surface &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Load(a0, a1, a2, a3, a4, a5); });
cls_GeomAdaptor_Surface.def("Load", (void (GeomAdaptor_Surface::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomAdaptor_Surface::Load, "ConstructionError is raised if UFirst>ULast or VFirst>VLast", py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("TolU"), py::arg("TolV"));
cls_GeomAdaptor_Surface.def("Surface", (const opencascade::handle<Geom_Surface> & (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::Surface, "None");
cls_GeomAdaptor_Surface.def("FirstUParameter", (Standard_Real (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::FirstUParameter, "None");
cls_GeomAdaptor_Surface.def("LastUParameter", (Standard_Real (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::LastUParameter, "None");
cls_GeomAdaptor_Surface.def("FirstVParameter", (Standard_Real (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::FirstVParameter, "None");
cls_GeomAdaptor_Surface.def("LastVParameter", (Standard_Real (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::LastVParameter, "None");
cls_GeomAdaptor_Surface.def("UContinuity", (GeomAbs_Shape (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::UContinuity, "None");
cls_GeomAdaptor_Surface.def("VContinuity", (GeomAbs_Shape (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::VContinuity, "None");
cls_GeomAdaptor_Surface.def("NbUIntervals", (Standard_Integer (GeomAdaptor_Surface::*)(const GeomAbs_Shape) const) &GeomAdaptor_Surface::NbUIntervals, "Returns the number of U intervals for continuity <S>. May be one if UContinuity(me) >= <S>", py::arg("S"));
cls_GeomAdaptor_Surface.def("NbVIntervals", (Standard_Integer (GeomAdaptor_Surface::*)(const GeomAbs_Shape) const) &GeomAdaptor_Surface::NbVIntervals, "Returns the number of V intervals for continuity <S>. May be one if VContinuity(me) >= <S>", py::arg("S"));
cls_GeomAdaptor_Surface.def("UIntervals", (void (GeomAdaptor_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomAdaptor_Surface::UIntervals, "Returns the intervals with the requested continuity in the U direction.", py::arg("T"), py::arg("S"));
cls_GeomAdaptor_Surface.def("VIntervals", (void (GeomAdaptor_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomAdaptor_Surface::VIntervals, "Returns the intervals with the requested continuity in the V direction.", py::arg("T"), py::arg("S"));
cls_GeomAdaptor_Surface.def("UTrim", (opencascade::handle<Adaptor3d_HSurface> (GeomAdaptor_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &GeomAdaptor_Surface::UTrim, "Returns a surface trimmed in the U direction equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_GeomAdaptor_Surface.def("VTrim", (opencascade::handle<Adaptor3d_HSurface> (GeomAdaptor_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &GeomAdaptor_Surface::VTrim, "Returns a surface trimmed in the V direction between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_GeomAdaptor_Surface.def("IsUClosed", (Standard_Boolean (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::IsUClosed, "None");
cls_GeomAdaptor_Surface.def("IsVClosed", (Standard_Boolean (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::IsVClosed, "None");
cls_GeomAdaptor_Surface.def("IsUPeriodic", (Standard_Boolean (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::IsUPeriodic, "None");
cls_GeomAdaptor_Surface.def("UPeriod", (Standard_Real (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::UPeriod, "None");
cls_GeomAdaptor_Surface.def("IsVPeriodic", (Standard_Boolean (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::IsVPeriodic, "None");
cls_GeomAdaptor_Surface.def("VPeriod", (Standard_Real (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::VPeriod, "None");
cls_GeomAdaptor_Surface.def("Value", (gp_Pnt (GeomAdaptor_Surface::*)(const Standard_Real, const Standard_Real) const) &GeomAdaptor_Surface::Value, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"));
cls_GeomAdaptor_Surface.def("D0", (void (GeomAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &GeomAdaptor_Surface::D0, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_GeomAdaptor_Surface.def("D1", (void (GeomAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomAdaptor_Surface::D1, "Computes the point and the first derivatives on the surface.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_GeomAdaptor_Surface.def("D2", (void (GeomAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomAdaptor_Surface::D2, "Computes the point, the first and second derivatives on the surface.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_GeomAdaptor_Surface.def("D3", (void (GeomAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomAdaptor_Surface::D3, "Computes the point, the first, second and third derivatives on the surface.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_GeomAdaptor_Surface.def("DN", (gp_Vec (GeomAdaptor_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &GeomAdaptor_Surface::DN, "Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V).", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_GeomAdaptor_Surface.def("UResolution", (Standard_Real (GeomAdaptor_Surface::*)(const Standard_Real) const) &GeomAdaptor_Surface::UResolution, "Returns the parametric U resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_GeomAdaptor_Surface.def("VResolution", (Standard_Real (GeomAdaptor_Surface::*)(const Standard_Real) const) &GeomAdaptor_Surface::VResolution, "Returns the parametric V resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_GeomAdaptor_Surface.def("GetType", (GeomAbs_SurfaceType (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::GetType, "Returns the type of the surface : Plane, Cylinder, Cone, Sphere, Torus, BezierSurface, BSplineSurface, SurfaceOfRevolution, SurfaceOfExtrusion, OtherSurface");
cls_GeomAdaptor_Surface.def("Plane", (gp_Pln (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::Plane, "None");
cls_GeomAdaptor_Surface.def("Cylinder", (gp_Cylinder (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::Cylinder, "None");
cls_GeomAdaptor_Surface.def("Cone", (gp_Cone (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::Cone, "None");
cls_GeomAdaptor_Surface.def("Sphere", (gp_Sphere (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::Sphere, "None");
cls_GeomAdaptor_Surface.def("Torus", (gp_Torus (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::Torus, "None");
cls_GeomAdaptor_Surface.def("UDegree", (Standard_Integer (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::UDegree, "None");
cls_GeomAdaptor_Surface.def("NbUPoles", (Standard_Integer (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::NbUPoles, "None");
cls_GeomAdaptor_Surface.def("VDegree", (Standard_Integer (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::VDegree, "None");
cls_GeomAdaptor_Surface.def("NbVPoles", (Standard_Integer (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::NbVPoles, "None");
cls_GeomAdaptor_Surface.def("NbUKnots", (Standard_Integer (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::NbUKnots, "None");
cls_GeomAdaptor_Surface.def("NbVKnots", (Standard_Integer (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::NbVKnots, "None");
cls_GeomAdaptor_Surface.def("IsURational", (Standard_Boolean (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::IsURational, "None");
cls_GeomAdaptor_Surface.def("IsVRational", (Standard_Boolean (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::IsVRational, "None");
cls_GeomAdaptor_Surface.def("Bezier", (opencascade::handle<Geom_BezierSurface> (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::Bezier, "This will NOT make a copy of the Bezier Surface : If you want to modify the Surface please make a copy yourself Also it will NOT trim the surface to myU/VFirst/Last.");
cls_GeomAdaptor_Surface.def("BSpline", (opencascade::handle<Geom_BSplineSurface> (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::BSpline, "This will NOT make a copy of the BSpline Surface : If you want to modify the Surface please make a copy yourself Also it will NOT trim the surface to myU/VFirst/Last.");
cls_GeomAdaptor_Surface.def("AxeOfRevolution", (gp_Ax1 (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::AxeOfRevolution, "None");
cls_GeomAdaptor_Surface.def("Direction", (gp_Dir (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::Direction, "None");
cls_GeomAdaptor_Surface.def("BasisCurve", (opencascade::handle<Adaptor3d_HCurve> (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::BasisCurve, "None");
cls_GeomAdaptor_Surface.def("BasisSurface", (opencascade::handle<Adaptor3d_HSurface> (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::BasisSurface, "None");
cls_GeomAdaptor_Surface.def("OffsetValue", (Standard_Real (GeomAdaptor_Surface::*)() const) &GeomAdaptor_Surface::OffsetValue, "None");

// CLASS: GEOMADAPTOR_CURVE
py::class_<GeomAdaptor_Curve, Adaptor3d_Curve> cls_GeomAdaptor_Curve(mod, "GeomAdaptor_Curve", "This class provides an interface between the services provided by any curve from the package Geom and those required of the curve by algorithms which use it. Creation of the loaded curve the curve is C1 by piece.");

// Constructors
cls_GeomAdaptor_Curve.def(py::init<>());
cls_GeomAdaptor_Curve.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("C"));
cls_GeomAdaptor_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UFirst"), py::arg("ULast"));

// Methods
// cls_GeomAdaptor_Curve.def_static("operator new_", (void * (*)(size_t)) &GeomAdaptor_Curve::operator new, "None", py::arg("theSize"));
// cls_GeomAdaptor_Curve.def_static("operator delete_", (void (*)(void *)) &GeomAdaptor_Curve::operator delete, "None", py::arg("theAddress"));
// cls_GeomAdaptor_Curve.def_static("operator new[]_", (void * (*)(size_t)) &GeomAdaptor_Curve::operator new[], "None", py::arg("theSize"));
// cls_GeomAdaptor_Curve.def_static("operator delete[]_", (void (*)(void *)) &GeomAdaptor_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAdaptor_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAdaptor_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAdaptor_Curve.def_static("operator delete_", (void (*)(void *, void *)) &GeomAdaptor_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAdaptor_Curve.def("Reset", (void (GeomAdaptor_Curve::*)()) &GeomAdaptor_Curve::Reset, "Reset currently loaded curve (undone Load()).");
cls_GeomAdaptor_Curve.def("Load", (void (GeomAdaptor_Curve::*)(const opencascade::handle<Geom_Curve> &)) &GeomAdaptor_Curve::Load, "None", py::arg("C"));
cls_GeomAdaptor_Curve.def("Load", (void (GeomAdaptor_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &GeomAdaptor_Curve::Load, "ConstructionError is raised if Ufirst>Ulast", py::arg("C"), py::arg("UFirst"), py::arg("ULast"));
cls_GeomAdaptor_Curve.def("Curve", (const opencascade::handle<Geom_Curve> & (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Curve, "Provides a curve inherited from Hcurve from Adaptor. This is inherited to provide easy to use constructors.");
cls_GeomAdaptor_Curve.def("FirstParameter", (Standard_Real (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::FirstParameter, "None");
cls_GeomAdaptor_Curve.def("LastParameter", (Standard_Real (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::LastParameter, "None");
cls_GeomAdaptor_Curve.def("Continuity", (GeomAbs_Shape (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Continuity, "None");
cls_GeomAdaptor_Curve.def("NbIntervals", (Standard_Integer (GeomAdaptor_Curve::*)(const GeomAbs_Shape) const) &GeomAdaptor_Curve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomAdaptor_Curve.def("Intervals", (void (GeomAdaptor_Curve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomAdaptor_Curve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomAdaptor_Curve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (GeomAdaptor_Curve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &GeomAdaptor_Curve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_GeomAdaptor_Curve.def("IsClosed", (Standard_Boolean (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::IsClosed, "None");
cls_GeomAdaptor_Curve.def("IsPeriodic", (Standard_Boolean (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::IsPeriodic, "None");
cls_GeomAdaptor_Curve.def("Period", (Standard_Real (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Period, "None");
cls_GeomAdaptor_Curve.def("Value", (gp_Pnt (GeomAdaptor_Curve::*)(const Standard_Real) const) &GeomAdaptor_Curve::Value, "Computes the point of parameter U on the curve", py::arg("U"));
cls_GeomAdaptor_Curve.def("D0", (void (GeomAdaptor_Curve::*)(const Standard_Real, gp_Pnt &) const) &GeomAdaptor_Curve::D0, "Computes the point of parameter U.", py::arg("U"), py::arg("P"));
cls_GeomAdaptor_Curve.def("D1", (void (GeomAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomAdaptor_Curve::D1, "Computes the point of parameter U on the curve with its first derivative.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomAdaptor_Curve.def("D2", (void (GeomAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomAdaptor_Curve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_GeomAdaptor_Curve.def("D3", (void (GeomAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomAdaptor_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_GeomAdaptor_Curve.def("DN", (gp_Vec (GeomAdaptor_Curve::*)(const Standard_Real, const Standard_Integer) const) &GeomAdaptor_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Warning : On the specific case of BSplineCurve: if the curve is cut in interval of continuity CN, the derivatives are computed on the current interval. else the derivatives are computed on the basis curve. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_GeomAdaptor_Curve.def("Resolution", (Standard_Real (GeomAdaptor_Curve::*)(const Standard_Real) const) &GeomAdaptor_Curve::Resolution, "returns the parametric resolution", py::arg("R3d"));
cls_GeomAdaptor_Curve.def("GetType", (GeomAbs_CurveType (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::GetType, "None");
cls_GeomAdaptor_Curve.def("Line", (gp_Lin (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Line, "None");
cls_GeomAdaptor_Curve.def("Circle", (gp_Circ (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Circle, "None");
cls_GeomAdaptor_Curve.def("Ellipse", (gp_Elips (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Ellipse, "None");
cls_GeomAdaptor_Curve.def("Hyperbola", (gp_Hypr (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Hyperbola, "None");
cls_GeomAdaptor_Curve.def("Parabola", (gp_Parab (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Parabola, "None");
cls_GeomAdaptor_Curve.def("Degree", (Standard_Integer (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Degree, "this should NEVER make a copy of the underlying curve to read the relevant information");
cls_GeomAdaptor_Curve.def("IsRational", (Standard_Boolean (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::IsRational, "this should NEVER make a copy of the underlying curve to read the relevant information");
cls_GeomAdaptor_Curve.def("NbPoles", (Standard_Integer (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::NbPoles, "this should NEVER make a copy of the underlying curve to read the relevant information");
cls_GeomAdaptor_Curve.def("NbKnots", (Standard_Integer (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::NbKnots, "this should NEVER make a copy of the underlying curve to read the relevant information");
cls_GeomAdaptor_Curve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::Bezier, "this will NOT make a copy of the Bezier Curve : If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");
cls_GeomAdaptor_Curve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::BSpline, "this will NOT make a copy of the BSpline Curve : If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");
cls_GeomAdaptor_Curve.def("OffsetCurve", (opencascade::handle<Geom_OffsetCurve> (GeomAdaptor_Curve::*)() const) &GeomAdaptor_Curve::OffsetCurve, "None");

// CLASS: GEOMADAPTOR_GHSURFACE
py::class_<GeomAdaptor_GHSurface, opencascade::handle<GeomAdaptor_GHSurface>, Adaptor3d_HSurface> cls_GeomAdaptor_GHSurface(mod, "GeomAdaptor_GHSurface", "None");

// Constructors
cls_GeomAdaptor_GHSurface.def(py::init<>());
cls_GeomAdaptor_GHSurface.def(py::init<const GeomAdaptor_Surface &>(), py::arg("S"));

// Methods
cls_GeomAdaptor_GHSurface.def("Set", (void (GeomAdaptor_GHSurface::*)(const GeomAdaptor_Surface &)) &GeomAdaptor_GHSurface::Set, "Sets the field of the GenHSurface.", py::arg("S"));
cls_GeomAdaptor_GHSurface.def("Surface", (const Adaptor3d_Surface & (GeomAdaptor_GHSurface::*)() const) &GeomAdaptor_GHSurface::Surface, "Returns a reference to the Surface inside the HSurface. This is redefined from HSurface, cannot be inline.");
cls_GeomAdaptor_GHSurface.def("ChangeSurface", (GeomAdaptor_Surface & (GeomAdaptor_GHSurface::*)()) &GeomAdaptor_GHSurface::ChangeSurface, "Returns the surface used to create the GenHSurface.");
cls_GeomAdaptor_GHSurface.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_GHSurface::get_type_name, "None");
cls_GeomAdaptor_GHSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_GHSurface::get_type_descriptor, "None");
cls_GeomAdaptor_GHSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_GHSurface::*)() const) &GeomAdaptor_GHSurface::DynamicType, "None");

// CLASS: GEOMADAPTOR_HSURFACE
py::class_<GeomAdaptor_HSurface, opencascade::handle<GeomAdaptor_HSurface>, GeomAdaptor_GHSurface> cls_GeomAdaptor_HSurface(mod, "GeomAdaptor_HSurface", "An interface between the services provided by any surface from the package Geom and those required of the surface by algorithms which use it. Provides a surface handled by reference.");

// Constructors
cls_GeomAdaptor_HSurface.def(py::init<>());
cls_GeomAdaptor_HSurface.def(py::init<const GeomAdaptor_Surface &>(), py::arg("AS"));
cls_GeomAdaptor_HSurface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
cls_GeomAdaptor_HSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"));
cls_GeomAdaptor_HSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("TolU"));
cls_GeomAdaptor_HSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("TolU"), py::arg("TolV"));

// Methods
cls_GeomAdaptor_HSurface.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_HSurface::get_type_name, "None");
cls_GeomAdaptor_HSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_HSurface::get_type_descriptor, "None");
cls_GeomAdaptor_HSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_HSurface::*)() const) &GeomAdaptor_HSurface::DynamicType, "None");

// CLASS: GEOMADAPTOR
py::class_<GeomAdaptor> cls_GeomAdaptor(mod, "GeomAdaptor", "this package contains the geometric definition of curve and surface necessary to use algorithmes.");

// Methods
// cls_GeomAdaptor.def_static("operator new_", (void * (*)(size_t)) &GeomAdaptor::operator new, "None", py::arg("theSize"));
// cls_GeomAdaptor.def_static("operator delete_", (void (*)(void *)) &GeomAdaptor::operator delete, "None", py::arg("theAddress"));
// cls_GeomAdaptor.def_static("operator new[]_", (void * (*)(size_t)) &GeomAdaptor::operator new[], "None", py::arg("theSize"));
// cls_GeomAdaptor.def_static("operator delete[]_", (void (*)(void *)) &GeomAdaptor::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAdaptor.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAdaptor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAdaptor.def_static("operator delete_", (void (*)(void *, void *)) &GeomAdaptor::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAdaptor.def_static("MakeCurve_", (opencascade::handle<Geom_Curve> (*)(const Adaptor3d_Curve &)) &GeomAdaptor::MakeCurve, "Inherited from GHCurve. Provides a curve handled by reference. Build a Geom_Curve using the informations from the Curve from Adaptor3d", py::arg("C"));
cls_GeomAdaptor.def_static("MakeSurface_", [](const Adaptor3d_Surface & a0) -> opencascade::handle<Geom_Surface> { return GeomAdaptor::MakeSurface(a0); });
cls_GeomAdaptor.def_static("MakeSurface_", (opencascade::handle<Geom_Surface> (*)(const Adaptor3d_Surface &, const Standard_Boolean)) &GeomAdaptor::MakeSurface, "Build a Geom_Surface using the informations from the Surface from Adaptor3d", py::arg("theS"), py::arg("theTrimFlag"));

// CLASS: GEOMADAPTOR_GHCURVE
py::class_<GeomAdaptor_GHCurve, opencascade::handle<GeomAdaptor_GHCurve>, Adaptor3d_HCurve> cls_GeomAdaptor_GHCurve(mod, "GeomAdaptor_GHCurve", "None");

// Constructors
cls_GeomAdaptor_GHCurve.def(py::init<>());
cls_GeomAdaptor_GHCurve.def(py::init<const GeomAdaptor_Curve &>(), py::arg("C"));

// Methods
cls_GeomAdaptor_GHCurve.def("Set", (void (GeomAdaptor_GHCurve::*)(const GeomAdaptor_Curve &)) &GeomAdaptor_GHCurve::Set, "Sets the field of the GenHCurve.", py::arg("C"));
cls_GeomAdaptor_GHCurve.def("Curve", (const Adaptor3d_Curve & (GeomAdaptor_GHCurve::*)() const) &GeomAdaptor_GHCurve::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_GeomAdaptor_GHCurve.def("GetCurve", (Adaptor3d_Curve & (GeomAdaptor_GHCurve::*)()) &GeomAdaptor_GHCurve::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_GeomAdaptor_GHCurve.def("ChangeCurve", (GeomAdaptor_Curve & (GeomAdaptor_GHCurve::*)()) &GeomAdaptor_GHCurve::ChangeCurve, "Returns the curve used to create the GenHCurve.");
cls_GeomAdaptor_GHCurve.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_GHCurve::get_type_name, "None");
cls_GeomAdaptor_GHCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_GHCurve::get_type_descriptor, "None");
cls_GeomAdaptor_GHCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_GHCurve::*)() const) &GeomAdaptor_GHCurve::DynamicType, "None");

// CLASS: GEOMADAPTOR_HCURVE
py::class_<GeomAdaptor_HCurve, opencascade::handle<GeomAdaptor_HCurve>, GeomAdaptor_GHCurve> cls_GeomAdaptor_HCurve(mod, "GeomAdaptor_HCurve", "An interface between the services provided by any curve from the package Geom and those required of the curve by algorithms which use it.");

// Constructors
cls_GeomAdaptor_HCurve.def(py::init<>());
cls_GeomAdaptor_HCurve.def(py::init<const GeomAdaptor_Curve &>(), py::arg("AS"));
cls_GeomAdaptor_HCurve.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("S"));
cls_GeomAdaptor_HCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"));

// Methods
cls_GeomAdaptor_HCurve.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_HCurve::get_type_name, "None");
cls_GeomAdaptor_HCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_HCurve::get_type_descriptor, "None");
cls_GeomAdaptor_HCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_HCurve::*)() const) &GeomAdaptor_HCurve::DynamicType, "None");

// CLASS: GEOMADAPTOR_SURFACEOFLINEAREXTRUSION
py::class_<GeomAdaptor_SurfaceOfLinearExtrusion, GeomAdaptor_Surface> cls_GeomAdaptor_SurfaceOfLinearExtrusion(mod, "GeomAdaptor_SurfaceOfLinearExtrusion", "Generalised cylinder. This surface is obtained by sweeping a curve in a given direction. The parametrization range for the parameter U is defined with referenced the curve. The parametrization range for the parameter V is ]-infinite,+infinite[ The position of the curve gives the origin for the parameter V. The continuity of the surface is CN in the V direction.");

// Constructors
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def(py::init<>());
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("C"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const gp_Dir &>(), py::arg("C"), py::arg("V"));

// Methods
// cls_GeomAdaptor_SurfaceOfLinearExtrusion.def_static("operator new_", (void * (*)(size_t)) &GeomAdaptor_SurfaceOfLinearExtrusion::operator new, "None", py::arg("theSize"));
// cls_GeomAdaptor_SurfaceOfLinearExtrusion.def_static("operator delete_", (void (*)(void *)) &GeomAdaptor_SurfaceOfLinearExtrusion::operator delete, "None", py::arg("theAddress"));
// cls_GeomAdaptor_SurfaceOfLinearExtrusion.def_static("operator new[]_", (void * (*)(size_t)) &GeomAdaptor_SurfaceOfLinearExtrusion::operator new[], "None", py::arg("theSize"));
// cls_GeomAdaptor_SurfaceOfLinearExtrusion.def_static("operator delete[]_", (void (*)(void *)) &GeomAdaptor_SurfaceOfLinearExtrusion::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAdaptor_SurfaceOfLinearExtrusion.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAdaptor_SurfaceOfLinearExtrusion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAdaptor_SurfaceOfLinearExtrusion.def_static("operator delete_", (void (*)(void *, void *)) &GeomAdaptor_SurfaceOfLinearExtrusion::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("Load", (void (GeomAdaptor_SurfaceOfLinearExtrusion::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomAdaptor_SurfaceOfLinearExtrusion::Load, "Changes the Curve", py::arg("C"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("Load", (void (GeomAdaptor_SurfaceOfLinearExtrusion::*)(const gp_Dir &)) &GeomAdaptor_SurfaceOfLinearExtrusion::Load, "Changes the Direction", py::arg("V"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("FirstUParameter", (Standard_Real (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::FirstUParameter, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("LastUParameter", (Standard_Real (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::LastUParameter, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("FirstVParameter", (Standard_Real (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::FirstVParameter, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("LastVParameter", (Standard_Real (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::LastVParameter, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("UContinuity", (GeomAbs_Shape (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::UContinuity, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("VContinuity", (GeomAbs_Shape (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::VContinuity, "Return CN.");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("NbUIntervals", (Standard_Integer (GeomAdaptor_SurfaceOfLinearExtrusion::*)(const GeomAbs_Shape) const) &GeomAdaptor_SurfaceOfLinearExtrusion::NbUIntervals, "Returns the number of U intervals for continuity <S>. May be one if UContinuity(me) >= <S>", py::arg("S"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("NbVIntervals", (Standard_Integer (GeomAdaptor_SurfaceOfLinearExtrusion::*)(const GeomAbs_Shape) const) &GeomAdaptor_SurfaceOfLinearExtrusion::NbVIntervals, "Returns the number of V intervals for continuity <S>. May be one if VContinuity(me) >= <S>", py::arg("S"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("UIntervals", (void (GeomAdaptor_SurfaceOfLinearExtrusion::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomAdaptor_SurfaceOfLinearExtrusion::UIntervals, "Returns the intervals with the requested continuity in the U direction.", py::arg("T"), py::arg("S"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("VIntervals", (void (GeomAdaptor_SurfaceOfLinearExtrusion::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomAdaptor_SurfaceOfLinearExtrusion::VIntervals, "Returns the intervals with the requested continuity in the V direction.", py::arg("T"), py::arg("S"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("UTrim", (opencascade::handle<Adaptor3d_HSurface> (GeomAdaptor_SurfaceOfLinearExtrusion::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &GeomAdaptor_SurfaceOfLinearExtrusion::UTrim, "Returns a surface trimmed in the U direction equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("VTrim", (opencascade::handle<Adaptor3d_HSurface> (GeomAdaptor_SurfaceOfLinearExtrusion::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &GeomAdaptor_SurfaceOfLinearExtrusion::VTrim, "Returns a surface trimmed in the V direction between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("IsUClosed", (Standard_Boolean (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::IsUClosed, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("IsVClosed", (Standard_Boolean (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::IsVClosed, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("IsUPeriodic", (Standard_Boolean (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::IsUPeriodic, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("UPeriod", (Standard_Real (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::UPeriod, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("IsVPeriodic", (Standard_Boolean (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::IsVPeriodic, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("VPeriod", (Standard_Real (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::VPeriod, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("UResolution", (Standard_Real (GeomAdaptor_SurfaceOfLinearExtrusion::*)(const Standard_Real) const) &GeomAdaptor_SurfaceOfLinearExtrusion::UResolution, "Returns the parametric U resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("VResolution", (Standard_Real (GeomAdaptor_SurfaceOfLinearExtrusion::*)(const Standard_Real) const) &GeomAdaptor_SurfaceOfLinearExtrusion::VResolution, "Returns the parametric V resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("GetType", (GeomAbs_SurfaceType (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::GetType, "Returns the type of the surface : Plane, Cylinder, Cone, Sphere, Torus, BezierSurface, BSplineSurface, SurfaceOfRevolution, SurfaceOfExtrusion, OtherSurface");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("Plane", (gp_Pln (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::Plane, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("Cylinder", (gp_Cylinder (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::Cylinder, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("Cone", (gp_Cone (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::Cone, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("Sphere", (gp_Sphere (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::Sphere, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("Torus", (gp_Torus (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::Torus, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("UDegree", (Standard_Integer (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::UDegree, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("NbUPoles", (Standard_Integer (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::NbUPoles, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("IsURational", (Standard_Boolean (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::IsURational, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("IsVRational", (Standard_Boolean (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::IsVRational, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("Bezier", (opencascade::handle<Geom_BezierSurface> (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::Bezier, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("BSpline", (opencascade::handle<Geom_BSplineSurface> (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::BSpline, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("AxeOfRevolution", (gp_Ax1 (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::AxeOfRevolution, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("Direction", (gp_Dir (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::Direction, "None");
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def("BasisCurve", (opencascade::handle<Adaptor3d_HCurve> (GeomAdaptor_SurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_SurfaceOfLinearExtrusion::BasisCurve, "None");

// CLASS: GEOMADAPTOR_HSURFACEOFLINEAREXTRUSION
py::class_<GeomAdaptor_HSurfaceOfLinearExtrusion, opencascade::handle<GeomAdaptor_HSurfaceOfLinearExtrusion>, Adaptor3d_HSurface> cls_GeomAdaptor_HSurfaceOfLinearExtrusion(mod, "GeomAdaptor_HSurfaceOfLinearExtrusion", "None");

// Constructors
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def(py::init<>());
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def(py::init<const GeomAdaptor_SurfaceOfLinearExtrusion &>(), py::arg("S"));

// Methods
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def("Set", (void (GeomAdaptor_HSurfaceOfLinearExtrusion::*)(const GeomAdaptor_SurfaceOfLinearExtrusion &)) &GeomAdaptor_HSurfaceOfLinearExtrusion::Set, "Sets the field of the GenHSurface.", py::arg("S"));
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def("Surface", (const Adaptor3d_Surface & (GeomAdaptor_HSurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_HSurfaceOfLinearExtrusion::Surface, "Returns a reference to the Surface inside the HSurface. This is redefined from HSurface, cannot be inline.");
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def("ChangeSurface", (GeomAdaptor_SurfaceOfLinearExtrusion & (GeomAdaptor_HSurfaceOfLinearExtrusion::*)()) &GeomAdaptor_HSurfaceOfLinearExtrusion::ChangeSurface, "Returns the surface used to create the GenHSurface.");
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_HSurfaceOfLinearExtrusion::get_type_name, "None");
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_HSurfaceOfLinearExtrusion::get_type_descriptor, "None");
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_HSurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_HSurfaceOfLinearExtrusion::DynamicType, "None");

// CLASS: GEOMADAPTOR_SURFACEOFREVOLUTION
py::class_<GeomAdaptor_SurfaceOfRevolution, GeomAdaptor_Surface> cls_GeomAdaptor_SurfaceOfRevolution(mod, "GeomAdaptor_SurfaceOfRevolution", "This class defines a complete surface of revolution. The surface is obtained by rotating a curve a complete revolution about an axis. The curve and the axis must be in the same plane. If the curve and the axis are not in the same plane it is always possible to be in the previous case after a cylindrical projection of the curve in a referenced plane. For a complete surface of revolution the parametric range is 0 <= U <= 2*PI. -- The parametric range for V is defined with the revolved curve. The origin of the U parametrization is given by the position of the revolved curve (reference). The direction of the revolution axis defines the positive sense of rotation (trigonometric sense) corresponding to the increasing of the parametric value U. The derivatives are always defined for the u direction. For the v direction the definition of the derivatives depends on the degree of continuity of the referenced curve.");

// Constructors
cls_GeomAdaptor_SurfaceOfRevolution.def(py::init<>());
cls_GeomAdaptor_SurfaceOfRevolution.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("C"));
cls_GeomAdaptor_SurfaceOfRevolution.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const gp_Ax1 &>(), py::arg("C"), py::arg("V"));

// Methods
// cls_GeomAdaptor_SurfaceOfRevolution.def_static("operator new_", (void * (*)(size_t)) &GeomAdaptor_SurfaceOfRevolution::operator new, "None", py::arg("theSize"));
// cls_GeomAdaptor_SurfaceOfRevolution.def_static("operator delete_", (void (*)(void *)) &GeomAdaptor_SurfaceOfRevolution::operator delete, "None", py::arg("theAddress"));
// cls_GeomAdaptor_SurfaceOfRevolution.def_static("operator new[]_", (void * (*)(size_t)) &GeomAdaptor_SurfaceOfRevolution::operator new[], "None", py::arg("theSize"));
// cls_GeomAdaptor_SurfaceOfRevolution.def_static("operator delete[]_", (void (*)(void *)) &GeomAdaptor_SurfaceOfRevolution::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAdaptor_SurfaceOfRevolution.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAdaptor_SurfaceOfRevolution::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAdaptor_SurfaceOfRevolution.def_static("operator delete_", (void (*)(void *, void *)) &GeomAdaptor_SurfaceOfRevolution::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAdaptor_SurfaceOfRevolution.def("Load", (void (GeomAdaptor_SurfaceOfRevolution::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomAdaptor_SurfaceOfRevolution::Load, "Changes the Curve", py::arg("C"));
cls_GeomAdaptor_SurfaceOfRevolution.def("Load", (void (GeomAdaptor_SurfaceOfRevolution::*)(const gp_Ax1 &)) &GeomAdaptor_SurfaceOfRevolution::Load, "Changes the Direction", py::arg("V"));
cls_GeomAdaptor_SurfaceOfRevolution.def("AxeOfRevolution", (gp_Ax1 (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::AxeOfRevolution, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("FirstUParameter", (Standard_Real (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::FirstUParameter, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("LastUParameter", (Standard_Real (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::LastUParameter, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("FirstVParameter", (Standard_Real (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::FirstVParameter, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("LastVParameter", (Standard_Real (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::LastVParameter, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("UContinuity", (GeomAbs_Shape (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::UContinuity, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("VContinuity", (GeomAbs_Shape (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::VContinuity, "Return CN.");
cls_GeomAdaptor_SurfaceOfRevolution.def("NbUIntervals", (Standard_Integer (GeomAdaptor_SurfaceOfRevolution::*)(const GeomAbs_Shape) const) &GeomAdaptor_SurfaceOfRevolution::NbUIntervals, "Returns the number of U intervals for continuity <S>. May be one if UContinuity(me) >= <S>", py::arg("S"));
cls_GeomAdaptor_SurfaceOfRevolution.def("NbVIntervals", (Standard_Integer (GeomAdaptor_SurfaceOfRevolution::*)(const GeomAbs_Shape) const) &GeomAdaptor_SurfaceOfRevolution::NbVIntervals, "Returns the number of V intervals for continuity <S>. May be one if VContinuity(me) >= <S>", py::arg("S"));
cls_GeomAdaptor_SurfaceOfRevolution.def("UIntervals", (void (GeomAdaptor_SurfaceOfRevolution::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomAdaptor_SurfaceOfRevolution::UIntervals, "Returns the intervals with the requested continuity in the U direction.", py::arg("T"), py::arg("S"));
cls_GeomAdaptor_SurfaceOfRevolution.def("VIntervals", (void (GeomAdaptor_SurfaceOfRevolution::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomAdaptor_SurfaceOfRevolution::VIntervals, "Returns the intervals with the requested continuity in the V direction.", py::arg("T"), py::arg("S"));
cls_GeomAdaptor_SurfaceOfRevolution.def("UTrim", (opencascade::handle<Adaptor3d_HSurface> (GeomAdaptor_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &GeomAdaptor_SurfaceOfRevolution::UTrim, "Returns a surface trimmed in the U direction equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_GeomAdaptor_SurfaceOfRevolution.def("VTrim", (opencascade::handle<Adaptor3d_HSurface> (GeomAdaptor_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &GeomAdaptor_SurfaceOfRevolution::VTrim, "Returns a surface trimmed in the V direction between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_GeomAdaptor_SurfaceOfRevolution.def("IsUClosed", (Standard_Boolean (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::IsUClosed, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("IsVClosed", (Standard_Boolean (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::IsVClosed, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("IsUPeriodic", (Standard_Boolean (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::IsUPeriodic, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("UPeriod", (Standard_Real (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::UPeriod, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("IsVPeriodic", (Standard_Boolean (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::IsVPeriodic, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("VPeriod", (Standard_Real (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::VPeriod, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("UResolution", (Standard_Real (GeomAdaptor_SurfaceOfRevolution::*)(const Standard_Real) const) &GeomAdaptor_SurfaceOfRevolution::UResolution, "Returns the parametric U resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_GeomAdaptor_SurfaceOfRevolution.def("VResolution", (Standard_Real (GeomAdaptor_SurfaceOfRevolution::*)(const Standard_Real) const) &GeomAdaptor_SurfaceOfRevolution::VResolution, "Returns the parametric V resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_GeomAdaptor_SurfaceOfRevolution.def("GetType", (GeomAbs_SurfaceType (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::GetType, "Returns the type of the surface : Plane, Cylinder, Cone, Sphere, Torus, BezierSurface, BSplineSurface, SurfaceOfRevolution, SurfaceOfExtrusion, OtherSurface");
cls_GeomAdaptor_SurfaceOfRevolution.def("Plane", (gp_Pln (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::Plane, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("Cylinder", (gp_Cylinder (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::Cylinder, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("Cone", (gp_Cone (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::Cone, "Apex of the Cone = Cone.Position().Location() ==> ReferenceRadius = 0.");
cls_GeomAdaptor_SurfaceOfRevolution.def("Sphere", (gp_Sphere (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::Sphere, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("Torus", (gp_Torus (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::Torus, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("VDegree", (Standard_Integer (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::VDegree, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("NbVPoles", (Standard_Integer (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::NbVPoles, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("NbVKnots", (Standard_Integer (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::NbVKnots, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("IsURational", (Standard_Boolean (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::IsURational, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("IsVRational", (Standard_Boolean (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::IsVRational, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("Bezier", (opencascade::handle<Geom_BezierSurface> (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::Bezier, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("BSpline", (opencascade::handle<Geom_BSplineSurface> (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::BSpline, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("Axis", (const gp_Ax3 & (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::Axis, "None");
cls_GeomAdaptor_SurfaceOfRevolution.def("BasisCurve", (opencascade::handle<Adaptor3d_HCurve> (GeomAdaptor_SurfaceOfRevolution::*)() const) &GeomAdaptor_SurfaceOfRevolution::BasisCurve, "None");

// CLASS: GEOMADAPTOR_HSURFACEOFREVOLUTION
py::class_<GeomAdaptor_HSurfaceOfRevolution, opencascade::handle<GeomAdaptor_HSurfaceOfRevolution>, Adaptor3d_HSurface> cls_GeomAdaptor_HSurfaceOfRevolution(mod, "GeomAdaptor_HSurfaceOfRevolution", "None");

// Constructors
cls_GeomAdaptor_HSurfaceOfRevolution.def(py::init<>());
cls_GeomAdaptor_HSurfaceOfRevolution.def(py::init<const GeomAdaptor_SurfaceOfRevolution &>(), py::arg("S"));

// Methods
cls_GeomAdaptor_HSurfaceOfRevolution.def("Set", (void (GeomAdaptor_HSurfaceOfRevolution::*)(const GeomAdaptor_SurfaceOfRevolution &)) &GeomAdaptor_HSurfaceOfRevolution::Set, "Sets the field of the GenHSurface.", py::arg("S"));
cls_GeomAdaptor_HSurfaceOfRevolution.def("Surface", (const Adaptor3d_Surface & (GeomAdaptor_HSurfaceOfRevolution::*)() const) &GeomAdaptor_HSurfaceOfRevolution::Surface, "Returns a reference to the Surface inside the HSurface. This is redefined from HSurface, cannot be inline.");
cls_GeomAdaptor_HSurfaceOfRevolution.def("ChangeSurface", (GeomAdaptor_SurfaceOfRevolution & (GeomAdaptor_HSurfaceOfRevolution::*)()) &GeomAdaptor_HSurfaceOfRevolution::ChangeSurface, "Returns the surface used to create the GenHSurface.");
cls_GeomAdaptor_HSurfaceOfRevolution.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_HSurfaceOfRevolution::get_type_name, "None");
cls_GeomAdaptor_HSurfaceOfRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_HSurfaceOfRevolution::get_type_descriptor, "None");
cls_GeomAdaptor_HSurfaceOfRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_HSurfaceOfRevolution::*)() const) &GeomAdaptor_HSurfaceOfRevolution::DynamicType, "None");


}
