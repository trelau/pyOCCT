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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <gp_Trsf.hxx>
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
#include <BRepAdaptor_Surface.hxx>

void bind_BRepAdaptor_Surface(py::module &mod){

py::class_<BRepAdaptor_Surface, std::unique_ptr<BRepAdaptor_Surface>, Adaptor3d_Surface> cls_BRepAdaptor_Surface(mod, "BRepAdaptor_Surface", "The Surface from BRepAdaptor allows to use a Face of the BRep topology look like a 3D surface.");

// Constructors
cls_BRepAdaptor_Surface.def(py::init<>());
cls_BRepAdaptor_Surface.def(py::init<const TopoDS_Face &>(), py::arg("F"));
cls_BRepAdaptor_Surface.def(py::init<const TopoDS_Face &, const Standard_Boolean>(), py::arg("F"), py::arg("R"));

// Fields

// Methods
// cls_BRepAdaptor_Surface.def_static("operator new_", (void * (*)(size_t)) &BRepAdaptor_Surface::operator new, "None", py::arg("theSize"));
// cls_BRepAdaptor_Surface.def_static("operator delete_", (void (*)(void *)) &BRepAdaptor_Surface::operator delete, "None", py::arg("theAddress"));
// cls_BRepAdaptor_Surface.def_static("operator new[]_", (void * (*)(size_t)) &BRepAdaptor_Surface::operator new[], "None", py::arg("theSize"));
// cls_BRepAdaptor_Surface.def_static("operator delete[]_", (void (*)(void *)) &BRepAdaptor_Surface::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAdaptor_Surface.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAdaptor_Surface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAdaptor_Surface.def_static("operator delete_", (void (*)(void *, void *)) &BRepAdaptor_Surface::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAdaptor_Surface.def("Initialize", [](BRepAdaptor_Surface &self, const TopoDS_Face & a0) -> void { return self.Initialize(a0); });
cls_BRepAdaptor_Surface.def("Initialize", (void (BRepAdaptor_Surface::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepAdaptor_Surface::Initialize, "Sets the surface to the geometry of <F>.", py::arg("F"), py::arg("Restriction"));
cls_BRepAdaptor_Surface.def("Surface", (const GeomAdaptor_Surface & (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Surface, "Returns the surface.");
cls_BRepAdaptor_Surface.def("ChangeSurface", (GeomAdaptor_Surface & (BRepAdaptor_Surface::*)()) &BRepAdaptor_Surface::ChangeSurface, "Returns the surface.");
cls_BRepAdaptor_Surface.def("Trsf", (const gp_Trsf & (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Trsf, "Returns the surface coordinate system.");
cls_BRepAdaptor_Surface.def("Face", (const TopoDS_Face & (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Face, "Returns the face.");
cls_BRepAdaptor_Surface.def("Tolerance", (Standard_Real (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Tolerance, "Returns the face tolerance.");
cls_BRepAdaptor_Surface.def("FirstUParameter", (Standard_Real (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::FirstUParameter, "None");
cls_BRepAdaptor_Surface.def("LastUParameter", (Standard_Real (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::LastUParameter, "None");
cls_BRepAdaptor_Surface.def("FirstVParameter", (Standard_Real (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::FirstVParameter, "None");
cls_BRepAdaptor_Surface.def("LastVParameter", (Standard_Real (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::LastVParameter, "None");
cls_BRepAdaptor_Surface.def("UContinuity", (GeomAbs_Shape (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::UContinuity, "None");
cls_BRepAdaptor_Surface.def("VContinuity", (GeomAbs_Shape (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::VContinuity, "None");
cls_BRepAdaptor_Surface.def("NbUIntervals", (Standard_Integer (BRepAdaptor_Surface::*)(const GeomAbs_Shape) const) &BRepAdaptor_Surface::NbUIntervals, "If necessary, breaks the surface in U intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_BRepAdaptor_Surface.def("NbVIntervals", (Standard_Integer (BRepAdaptor_Surface::*)(const GeomAbs_Shape) const) &BRepAdaptor_Surface::NbVIntervals, "If necessary, breaks the surface in V intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_BRepAdaptor_Surface.def("UIntervals", (void (BRepAdaptor_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepAdaptor_Surface::UIntervals, "Returns the intervals with the requested continuity in the U direction.", py::arg("T"), py::arg("S"));
cls_BRepAdaptor_Surface.def("VIntervals", (void (BRepAdaptor_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepAdaptor_Surface::VIntervals, "Returns the intervals with the requested continuity in the V direction.", py::arg("T"), py::arg("S"));
cls_BRepAdaptor_Surface.def("UTrim", (opencascade::handle<Adaptor3d_HSurface> (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &BRepAdaptor_Surface::UTrim, "Returns a surface trimmed in the U direction equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_BRepAdaptor_Surface.def("VTrim", (opencascade::handle<Adaptor3d_HSurface> (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &BRepAdaptor_Surface::VTrim, "Returns a surface trimmed in the V direction between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_BRepAdaptor_Surface.def("IsUClosed", (Standard_Boolean (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::IsUClosed, "None");
cls_BRepAdaptor_Surface.def("IsVClosed", (Standard_Boolean (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::IsVClosed, "None");
cls_BRepAdaptor_Surface.def("IsUPeriodic", (Standard_Boolean (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::IsUPeriodic, "None");
cls_BRepAdaptor_Surface.def("UPeriod", (Standard_Real (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::UPeriod, "None");
cls_BRepAdaptor_Surface.def("IsVPeriodic", (Standard_Boolean (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::IsVPeriodic, "None");
cls_BRepAdaptor_Surface.def("VPeriod", (Standard_Real (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::VPeriod, "None");
cls_BRepAdaptor_Surface.def("Value", (gp_Pnt (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real) const) &BRepAdaptor_Surface::Value, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"));
cls_BRepAdaptor_Surface.def("D0", (void (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &BRepAdaptor_Surface::D0, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_BRepAdaptor_Surface.def("D1", (void (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &BRepAdaptor_Surface::D1, "Computes the point and the first derivatives on the surface. Raised if the continuity of the current intervals is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_BRepAdaptor_Surface.def("D2", (void (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BRepAdaptor_Surface::D2, "Computes the point, the first and second derivatives on the surface. Raised if the continuity of the current intervals is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_BRepAdaptor_Surface.def("D3", (void (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &BRepAdaptor_Surface::D3, "Computes the point, the first, second and third derivatives on the surface. Raised if the continuity of the current intervals is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_BRepAdaptor_Surface.def("DN", (gp_Vec (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &BRepAdaptor_Surface::DN, "Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V). Raised if the current U interval is not not CNu and the current V interval is not CNv. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_BRepAdaptor_Surface.def("UResolution", (Standard_Real (BRepAdaptor_Surface::*)(const Standard_Real) const) &BRepAdaptor_Surface::UResolution, "Returns the parametric U resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_BRepAdaptor_Surface.def("VResolution", (Standard_Real (BRepAdaptor_Surface::*)(const Standard_Real) const) &BRepAdaptor_Surface::VResolution, "Returns the parametric V resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_BRepAdaptor_Surface.def("GetType", (GeomAbs_SurfaceType (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::GetType, "Returns the type of the surface : Plane, Cylinder, Cone, Sphere, Torus, BezierSurface, BSplineSurface, SurfaceOfRevolution, SurfaceOfExtrusion, OtherSurface");
cls_BRepAdaptor_Surface.def("Plane", (gp_Pln (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Plane, "None");
cls_BRepAdaptor_Surface.def("Cylinder", (gp_Cylinder (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Cylinder, "None");
cls_BRepAdaptor_Surface.def("Cone", (gp_Cone (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Cone, "None");
cls_BRepAdaptor_Surface.def("Sphere", (gp_Sphere (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Sphere, "None");
cls_BRepAdaptor_Surface.def("Torus", (gp_Torus (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Torus, "None");
cls_BRepAdaptor_Surface.def("UDegree", (Standard_Integer (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::UDegree, "None");
cls_BRepAdaptor_Surface.def("NbUPoles", (Standard_Integer (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::NbUPoles, "None");
cls_BRepAdaptor_Surface.def("VDegree", (Standard_Integer (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::VDegree, "None");
cls_BRepAdaptor_Surface.def("NbVPoles", (Standard_Integer (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::NbVPoles, "None");
cls_BRepAdaptor_Surface.def("NbUKnots", (Standard_Integer (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::NbUKnots, "None");
cls_BRepAdaptor_Surface.def("NbVKnots", (Standard_Integer (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::NbVKnots, "None");
cls_BRepAdaptor_Surface.def("IsURational", (Standard_Boolean (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::IsURational, "None");
cls_BRepAdaptor_Surface.def("IsVRational", (Standard_Boolean (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::IsVRational, "None");
cls_BRepAdaptor_Surface.def("Bezier", (opencascade::handle<Geom_BezierSurface> (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Bezier, "None");
cls_BRepAdaptor_Surface.def("BSpline", (opencascade::handle<Geom_BSplineSurface> (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::BSpline, "Warning : this will make a copy of the BSpline Surface since it applies to it the myTsrf transformation Be Carefull when using this method");
cls_BRepAdaptor_Surface.def("AxeOfRevolution", (gp_Ax1 (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::AxeOfRevolution, "None");
cls_BRepAdaptor_Surface.def("Direction", (gp_Dir (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::Direction, "None");
cls_BRepAdaptor_Surface.def("BasisCurve", (opencascade::handle<Adaptor3d_HCurve> (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::BasisCurve, "only for SurfaceOfExtrusion and SurfaceOfRevolution Warning: this will make a copy of the underlying curve since it applies to it the transformation myTrsf. Be carefull when using this method.");
cls_BRepAdaptor_Surface.def("BasisSurface", (opencascade::handle<Adaptor3d_HSurface> (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::BasisSurface, "None");
cls_BRepAdaptor_Surface.def("OffsetValue", (Standard_Real (BRepAdaptor_Surface::*)() const) &BRepAdaptor_Surface::OffsetValue, "None");

// Enums

}