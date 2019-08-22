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

void bind_GeomAdaptor_Surface(py::module &mod){

py::class_<GeomAdaptor_Surface, Adaptor3d_Surface> cls_GeomAdaptor_Surface(mod, "GeomAdaptor_Surface", "An interface between the services provided by any surface from the package Geom and those required of the surface by algorithms which use it. Creation of the loaded surface the surface is C1 by piece");

// Constructors
cls_GeomAdaptor_Surface.def(py::init<>());
cls_GeomAdaptor_Surface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
cls_GeomAdaptor_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"));
cls_GeomAdaptor_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("TolU"));
cls_GeomAdaptor_Surface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("TolU"), py::arg("TolV"));

// Fields

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

// Enums

}