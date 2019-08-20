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
#include <GeomAdaptor_Surface.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <gp_Ax1.hxx>
#include <GeomAdaptor_SurfaceOfLinearExtrusion.hxx>

void bind_GeomAdaptor_SurfaceOfLinearExtrusion(py::module &mod){

py::class_<GeomAdaptor_SurfaceOfLinearExtrusion, std::unique_ptr<GeomAdaptor_SurfaceOfLinearExtrusion>, GeomAdaptor_Surface> cls_GeomAdaptor_SurfaceOfLinearExtrusion(mod, "GeomAdaptor_SurfaceOfLinearExtrusion", "Generalised cylinder. This surface is obtained by sweeping a curve in a given direction. The parametrization range for the parameter U is defined with referenced the curve. The parametrization range for the parameter V is ]-infinite,+infinite[ The position of the curve gives the origin for the parameter V. The continuity of the surface is CN in the V direction.");

// Constructors
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def(py::init<>());
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("C"));
cls_GeomAdaptor_SurfaceOfLinearExtrusion.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const gp_Dir &>(), py::arg("C"), py::arg("V"));

// Fields

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

// Enums

}