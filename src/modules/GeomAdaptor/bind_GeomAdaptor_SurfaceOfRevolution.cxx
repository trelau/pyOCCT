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
#include <gp_Ax1.hxx>
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
#include <gp_Ax3.hxx>
#include <GeomAdaptor_SurfaceOfRevolution.hxx>

void bind_GeomAdaptor_SurfaceOfRevolution(py::module &mod){

py::class_<GeomAdaptor_SurfaceOfRevolution, std::unique_ptr<GeomAdaptor_SurfaceOfRevolution>, GeomAdaptor_Surface> cls_GeomAdaptor_SurfaceOfRevolution(mod, "GeomAdaptor_SurfaceOfRevolution", "This class defines a complete surface of revolution. The surface is obtained by rotating a curve a complete revolution about an axis. The curve and the axis must be in the same plane. If the curve and the axis are not in the same plane it is always possible to be in the previous case after a cylindrical projection of the curve in a referenced plane. For a complete surface of revolution the parametric range is 0 <= U <= 2*PI. -- The parametric range for V is defined with the revolved curve. The origin of the U parametrization is given by the position of the revolved curve (reference). The direction of the revolution axis defines the positive sense of rotation (trigonometric sense) corresponding to the increasing of the parametric value U. The derivatives are always defined for the u direction. For the v direction the definition of the derivatives depends on the degree of continuity of the referenced curve.");

// Constructors
cls_GeomAdaptor_SurfaceOfRevolution.def(py::init<>());
cls_GeomAdaptor_SurfaceOfRevolution.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("C"));
cls_GeomAdaptor_SurfaceOfRevolution.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const gp_Ax1 &>(), py::arg("C"), py::arg("V"));

// Fields

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

// Enums

}