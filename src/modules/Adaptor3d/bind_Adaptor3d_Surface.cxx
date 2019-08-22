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
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
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
#include <Adaptor3d_Surface.hxx>

void bind_Adaptor3d_Surface(py::module &mod){

py::class_<Adaptor3d_Surface> cls_Adaptor3d_Surface(mod, "Adaptor3d_Surface", "Root class for surfaces on which geometric algorithms work. An adapted surface is an interface between the services provided by a surface and those required of the surface by algorithms which use it. A derived concrete class is provided: GeomAdaptor_Surface for a surface from the Geom package. The Surface class describes the standard behaviour of a surface for generic algorithms.");

// Constructors

// Fields

// Methods
// cls_Adaptor3d_Surface.def_static("operator new_", (void * (*)(size_t)) &Adaptor3d_Surface::operator new, "None", py::arg("theSize"));
// cls_Adaptor3d_Surface.def_static("operator delete_", (void (*)(void *)) &Adaptor3d_Surface::operator delete, "None", py::arg("theAddress"));
// cls_Adaptor3d_Surface.def_static("operator new[]_", (void * (*)(size_t)) &Adaptor3d_Surface::operator new[], "None", py::arg("theSize"));
// cls_Adaptor3d_Surface.def_static("operator delete[]_", (void (*)(void *)) &Adaptor3d_Surface::operator delete[], "None", py::arg("theAddress"));
// cls_Adaptor3d_Surface.def_static("operator new_", (void * (*)(size_t, void *)) &Adaptor3d_Surface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Adaptor3d_Surface.def_static("operator delete_", (void (*)(void *, void *)) &Adaptor3d_Surface::operator delete, "None", py::arg(""), py::arg(""));
cls_Adaptor3d_Surface.def("FirstUParameter", (Standard_Real (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::FirstUParameter, "None");
cls_Adaptor3d_Surface.def("LastUParameter", (Standard_Real (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::LastUParameter, "None");
cls_Adaptor3d_Surface.def("FirstVParameter", (Standard_Real (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::FirstVParameter, "None");
cls_Adaptor3d_Surface.def("LastVParameter", (Standard_Real (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::LastVParameter, "None");
cls_Adaptor3d_Surface.def("UContinuity", (GeomAbs_Shape (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::UContinuity, "None");
cls_Adaptor3d_Surface.def("VContinuity", (GeomAbs_Shape (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::VContinuity, "None");
cls_Adaptor3d_Surface.def("NbUIntervals", (Standard_Integer (Adaptor3d_Surface::*)(const GeomAbs_Shape) const) &Adaptor3d_Surface::NbUIntervals, "Returns the number of U intervals for continuity <S>. May be one if UContinuity(me) >= <S>", py::arg("S"));
cls_Adaptor3d_Surface.def("NbVIntervals", (Standard_Integer (Adaptor3d_Surface::*)(const GeomAbs_Shape) const) &Adaptor3d_Surface::NbVIntervals, "Returns the number of V intervals for continuity <S>. May be one if VContinuity(me) >= <S>", py::arg("S"));
cls_Adaptor3d_Surface.def("UIntervals", (void (Adaptor3d_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor3d_Surface::UIntervals, "Returns the intervals with the requested continuity in the U direction.", py::arg("T"), py::arg("S"));
cls_Adaptor3d_Surface.def("VIntervals", (void (Adaptor3d_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor3d_Surface::VIntervals, "Returns the intervals with the requested continuity in the V direction.", py::arg("T"), py::arg("S"));
cls_Adaptor3d_Surface.def("UTrim", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor3d_Surface::UTrim, "Returns a surface trimmed in the U direction equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_Surface.def("VTrim", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor3d_Surface::VTrim, "Returns a surface trimmed in the V direction between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_Surface.def("IsUClosed", (Standard_Boolean (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::IsUClosed, "None");
cls_Adaptor3d_Surface.def("IsVClosed", (Standard_Boolean (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::IsVClosed, "None");
cls_Adaptor3d_Surface.def("IsUPeriodic", (Standard_Boolean (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::IsUPeriodic, "None");
cls_Adaptor3d_Surface.def("UPeriod", (Standard_Real (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::UPeriod, "None");
cls_Adaptor3d_Surface.def("IsVPeriodic", (Standard_Boolean (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::IsVPeriodic, "None");
cls_Adaptor3d_Surface.def("VPeriod", (Standard_Real (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::VPeriod, "None");
cls_Adaptor3d_Surface.def("Value", (gp_Pnt (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real) const) &Adaptor3d_Surface::Value, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"));
cls_Adaptor3d_Surface.def("D0", (void (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Adaptor3d_Surface::D0, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Adaptor3d_Surface.def("D1", (void (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Adaptor3d_Surface::D1, "Computes the point and the first derivatives on the surface. Raised if the continuity of the current intervals is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Adaptor3d_Surface.def("D2", (void (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Adaptor3d_Surface::D2, "Computes the point, the first and second derivatives on the surface. Raised if the continuity of the current intervals is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Adaptor3d_Surface.def("D3", (void (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Adaptor3d_Surface::D3, "Computes the point, the first, second and third derivatives on the surface. Raised if the continuity of the current intervals is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Adaptor3d_Surface.def("DN", (gp_Vec (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Adaptor3d_Surface::DN, "Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V). Raised if the current U interval is not not CNu and the current V interval is not CNv. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Adaptor3d_Surface.def("UResolution", (Standard_Real (Adaptor3d_Surface::*)(const Standard_Real) const) &Adaptor3d_Surface::UResolution, "Returns the parametric U resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_Adaptor3d_Surface.def("VResolution", (Standard_Real (Adaptor3d_Surface::*)(const Standard_Real) const) &Adaptor3d_Surface::VResolution, "Returns the parametric V resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_Adaptor3d_Surface.def("GetType", (GeomAbs_SurfaceType (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::GetType, "Returns the type of the surface : Plane, Cylinder, Cone, Sphere, Torus, BezierSurface, BSplineSurface, SurfaceOfRevolution, SurfaceOfExtrusion, OtherSurface");
cls_Adaptor3d_Surface.def("Plane", (gp_Pln (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::Plane, "None");
cls_Adaptor3d_Surface.def("Cylinder", (gp_Cylinder (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::Cylinder, "None");
cls_Adaptor3d_Surface.def("Cone", (gp_Cone (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::Cone, "None");
cls_Adaptor3d_Surface.def("Sphere", (gp_Sphere (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::Sphere, "None");
cls_Adaptor3d_Surface.def("Torus", (gp_Torus (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::Torus, "None");
cls_Adaptor3d_Surface.def("UDegree", (Standard_Integer (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::UDegree, "None");
cls_Adaptor3d_Surface.def("NbUPoles", (Standard_Integer (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::NbUPoles, "None");
cls_Adaptor3d_Surface.def("VDegree", (Standard_Integer (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::VDegree, "None");
cls_Adaptor3d_Surface.def("NbVPoles", (Standard_Integer (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::NbVPoles, "None");
cls_Adaptor3d_Surface.def("NbUKnots", (Standard_Integer (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::NbUKnots, "None");
cls_Adaptor3d_Surface.def("NbVKnots", (Standard_Integer (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::NbVKnots, "None");
cls_Adaptor3d_Surface.def("IsURational", (Standard_Boolean (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::IsURational, "None");
cls_Adaptor3d_Surface.def("IsVRational", (Standard_Boolean (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::IsVRational, "None");
cls_Adaptor3d_Surface.def("Bezier", (opencascade::handle<Geom_BezierSurface> (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::Bezier, "None");
cls_Adaptor3d_Surface.def("BSpline", (opencascade::handle<Geom_BSplineSurface> (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::BSpline, "None");
cls_Adaptor3d_Surface.def("AxeOfRevolution", (gp_Ax1 (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::AxeOfRevolution, "None");
cls_Adaptor3d_Surface.def("Direction", (gp_Dir (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::Direction, "None");
cls_Adaptor3d_Surface.def("BasisCurve", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::BasisCurve, "None");
cls_Adaptor3d_Surface.def("BasisSurface", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::BasisSurface, "None");
cls_Adaptor3d_Surface.def("OffsetValue", (Standard_Real (Adaptor3d_Surface::*)() const) &Adaptor3d_Surface::OffsetValue, "None");

// Enums

}