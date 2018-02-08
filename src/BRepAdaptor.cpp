/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Adaptor3d_Surface.hxx>
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
#include <Adaptor3d_Curve.hxx>
#include <TopoDS_Edge.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_OffsetCurve.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <NCollection_Array1.hxx>
#include <BRepAdaptor_Array1OfCurve.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <BRepAdaptor_HArray1OfCurve.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepAdaptor_CompCurve.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <BRepAdaptor_Curve2d.hxx>
#include <BRepAdaptor_HCompCurve.hxx>
#include <BRepAdaptor_HCurve.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(BRepAdaptor, mod) {

	// IMPORT
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.GeomAdaptor");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Geom2dAdaptor");
	py::module::import("OCCT.Adaptor2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_Surface.hxx
	py::class_<BRepAdaptor_Surface, std::unique_ptr<BRepAdaptor_Surface, Deleter<BRepAdaptor_Surface>>, Adaptor3d_Surface> cls_BRepAdaptor_Surface(mod, "BRepAdaptor_Surface", "The Surface from BRepAdaptor allows to use a Face of the BRep topology look like a 3D surface.");
	cls_BRepAdaptor_Surface.def(py::init<>());
	cls_BRepAdaptor_Surface.def(py::init<const TopoDS_Face &>(), py::arg("F"));
	cls_BRepAdaptor_Surface.def(py::init<const TopoDS_Face &, const Standard_Boolean>(), py::arg("F"), py::arg("R"));
	cls_BRepAdaptor_Surface.def("Initialize", [](BRepAdaptor_Surface &self, const TopoDS_Face & a0) -> void { return self.Initialize(a0); }, py::arg("F"));
	cls_BRepAdaptor_Surface.def("Initialize", (void (BRepAdaptor_Surface::*)(const TopoDS_Face &, const Standard_Boolean)) &BRepAdaptor_Surface::Initialize, "Sets the surface to the geometry of <F>.", py::arg("F"), py::arg("Restriction"));
	cls_BRepAdaptor_Surface.def("Surface", (const GeomAdaptor_Surface & (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Surface, "Returns the surface.");
	cls_BRepAdaptor_Surface.def("ChangeSurface", (GeomAdaptor_Surface & (BRepAdaptor_Surface::*)()) &BRepAdaptor_Surface::ChangeSurface, "Returns the surface.");
	cls_BRepAdaptor_Surface.def("Trsf", (const gp_Trsf & (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Trsf, "Returns the surface coordinate system.");
	cls_BRepAdaptor_Surface.def("Face", (const TopoDS_Face & (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Face, "Returns the face.");
	cls_BRepAdaptor_Surface.def("Tolerance", (Standard_Real (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Tolerance, "Returns the face tolerance.");
	cls_BRepAdaptor_Surface.def("FirstUParameter", (Standard_Real (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::FirstUParameter, "None");
	cls_BRepAdaptor_Surface.def("LastUParameter", (Standard_Real (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::LastUParameter, "None");
	cls_BRepAdaptor_Surface.def("FirstVParameter", (Standard_Real (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::FirstVParameter, "None");
	cls_BRepAdaptor_Surface.def("LastVParameter", (Standard_Real (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::LastVParameter, "None");
	cls_BRepAdaptor_Surface.def("UContinuity", (GeomAbs_Shape (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::UContinuity, "None");
	cls_BRepAdaptor_Surface.def("VContinuity", (GeomAbs_Shape (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::VContinuity, "None");
	cls_BRepAdaptor_Surface.def("NbUIntervals", (Standard_Integer (BRepAdaptor_Surface::*)(const GeomAbs_Shape) const ) &BRepAdaptor_Surface::NbUIntervals, "If necessary, breaks the surface in U intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
	cls_BRepAdaptor_Surface.def("NbVIntervals", (Standard_Integer (BRepAdaptor_Surface::*)(const GeomAbs_Shape) const ) &BRepAdaptor_Surface::NbVIntervals, "If necessary, breaks the surface in V intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
	cls_BRepAdaptor_Surface.def("UIntervals", (void (BRepAdaptor_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BRepAdaptor_Surface::UIntervals, "Returns the intervals with the requested continuity in the U direction.", py::arg("T"), py::arg("S"));
	cls_BRepAdaptor_Surface.def("VIntervals", (void (BRepAdaptor_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BRepAdaptor_Surface::VIntervals, "Returns the intervals with the requested continuity in the V direction.", py::arg("T"), py::arg("S"));
	cls_BRepAdaptor_Surface.def("UTrim", (opencascade::handle<Adaptor3d_HSurface> (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &BRepAdaptor_Surface::UTrim, "Returns a surface trimmed in the U direction equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_BRepAdaptor_Surface.def("VTrim", (opencascade::handle<Adaptor3d_HSurface> (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &BRepAdaptor_Surface::VTrim, "Returns a surface trimmed in the V direction between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_BRepAdaptor_Surface.def("IsUClosed", (Standard_Boolean (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::IsUClosed, "None");
	cls_BRepAdaptor_Surface.def("IsVClosed", (Standard_Boolean (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::IsVClosed, "None");
	cls_BRepAdaptor_Surface.def("IsUPeriodic", (Standard_Boolean (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::IsUPeriodic, "None");
	cls_BRepAdaptor_Surface.def("UPeriod", (Standard_Real (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::UPeriod, "None");
	cls_BRepAdaptor_Surface.def("IsVPeriodic", (Standard_Boolean (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::IsVPeriodic, "None");
	cls_BRepAdaptor_Surface.def("VPeriod", (Standard_Real (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::VPeriod, "None");
	cls_BRepAdaptor_Surface.def("Value", (gp_Pnt (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real) const ) &BRepAdaptor_Surface::Value, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"));
	cls_BRepAdaptor_Surface.def("D0", (void (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const ) &BRepAdaptor_Surface::D0, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
	cls_BRepAdaptor_Surface.def("D1", (void (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &BRepAdaptor_Surface::D1, "Computes the point and the first derivatives on the surface. Raised if the continuity of the current intervals is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
	cls_BRepAdaptor_Surface.def("D2", (void (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BRepAdaptor_Surface::D2, "Computes the point, the first and second derivatives on the surface. Raised if the continuity of the current intervals is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
	cls_BRepAdaptor_Surface.def("D3", (void (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BRepAdaptor_Surface::D3, "Computes the point, the first, second and third derivatives on the surface. Raised if the continuity of the current intervals is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
	cls_BRepAdaptor_Surface.def("DN", (gp_Vec (BRepAdaptor_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &BRepAdaptor_Surface::DN, "Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V). Raised if the current U interval is not not CNu and the current V interval is not CNv. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
	cls_BRepAdaptor_Surface.def("UResolution", (Standard_Real (BRepAdaptor_Surface::*)(const Standard_Real) const ) &BRepAdaptor_Surface::UResolution, "Returns the parametric U resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_BRepAdaptor_Surface.def("VResolution", (Standard_Real (BRepAdaptor_Surface::*)(const Standard_Real) const ) &BRepAdaptor_Surface::VResolution, "Returns the parametric V resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_BRepAdaptor_Surface.def("GetType", (GeomAbs_SurfaceType (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::GetType, "Returns the type of the surface : Plane, Cylinder, Cone, Sphere, Torus, BezierSurface, BSplineSurface, SurfaceOfRevolution, SurfaceOfExtrusion, OtherSurface");
	cls_BRepAdaptor_Surface.def("Plane", (gp_Pln (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Plane, "None");
	cls_BRepAdaptor_Surface.def("Cylinder", (gp_Cylinder (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Cylinder, "None");
	cls_BRepAdaptor_Surface.def("Cone", (gp_Cone (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Cone, "None");
	cls_BRepAdaptor_Surface.def("Sphere", (gp_Sphere (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Sphere, "None");
	cls_BRepAdaptor_Surface.def("Torus", (gp_Torus (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Torus, "None");
	cls_BRepAdaptor_Surface.def("UDegree", (Standard_Integer (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::UDegree, "None");
	cls_BRepAdaptor_Surface.def("NbUPoles", (Standard_Integer (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::NbUPoles, "None");
	cls_BRepAdaptor_Surface.def("VDegree", (Standard_Integer (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::VDegree, "None");
	cls_BRepAdaptor_Surface.def("NbVPoles", (Standard_Integer (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::NbVPoles, "None");
	cls_BRepAdaptor_Surface.def("NbUKnots", (Standard_Integer (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::NbUKnots, "None");
	cls_BRepAdaptor_Surface.def("NbVKnots", (Standard_Integer (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::NbVKnots, "None");
	cls_BRepAdaptor_Surface.def("IsURational", (Standard_Boolean (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::IsURational, "None");
	cls_BRepAdaptor_Surface.def("IsVRational", (Standard_Boolean (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::IsVRational, "None");
	cls_BRepAdaptor_Surface.def("Bezier", (opencascade::handle<Geom_BezierSurface> (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Bezier, "None");
	cls_BRepAdaptor_Surface.def("BSpline", (opencascade::handle<Geom_BSplineSurface> (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::BSpline, "Warning : this will make a copy of the BSpline Surface since it applies to it the myTsrf transformation Be Carefull when using this method");
	cls_BRepAdaptor_Surface.def("AxeOfRevolution", (gp_Ax1 (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::AxeOfRevolution, "None");
	cls_BRepAdaptor_Surface.def("Direction", (gp_Dir (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::Direction, "None");
	cls_BRepAdaptor_Surface.def("BasisCurve", (opencascade::handle<Adaptor3d_HCurve> (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::BasisCurve, "only for SurfaceOfExtrusion and SurfaceOfRevolution Warning: this will make a copy of the underlying curve since it applies to it the transformation myTrsf. Be carefull when using this method.");
	cls_BRepAdaptor_Surface.def("BasisSurface", (opencascade::handle<Adaptor3d_HSurface> (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::BasisSurface, "None");
	cls_BRepAdaptor_Surface.def("OffsetValue", (Standard_Real (BRepAdaptor_Surface::*)() const ) &BRepAdaptor_Surface::OffsetValue, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_Curve.hxx
	py::class_<BRepAdaptor_Curve, std::unique_ptr<BRepAdaptor_Curve, Deleter<BRepAdaptor_Curve>>, Adaptor3d_Curve> cls_BRepAdaptor_Curve(mod, "BRepAdaptor_Curve", "The Curve from BRepAdaptor allows to use an Edge of the BRep topology like a 3D curve.");
	cls_BRepAdaptor_Curve.def(py::init<>());
	cls_BRepAdaptor_Curve.def(py::init<const TopoDS_Edge &>(), py::arg("E"));
	cls_BRepAdaptor_Curve.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));
	cls_BRepAdaptor_Curve.def("Initialize", (void (BRepAdaptor_Curve::*)(const TopoDS_Edge &)) &BRepAdaptor_Curve::Initialize, "Sets the Curve <me> to acces to the geometry of edge <E>.", py::arg("E"));
	cls_BRepAdaptor_Curve.def("Initialize", (void (BRepAdaptor_Curve::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepAdaptor_Curve::Initialize, "Sets the Curve <me> to acces to the geometry of edge <E>. The geometry will be computed using the parametric curve of <E> on the face <F>. An Error is raised if the edge does not have a pcurve on the face.", py::arg("E"), py::arg("F"));
	cls_BRepAdaptor_Curve.def("Trsf", (const gp_Trsf & (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Trsf, "Returns the coordinate system of the curve.");
	cls_BRepAdaptor_Curve.def("Is3DCurve", (Standard_Boolean (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Is3DCurve, "Returns True if the edge geometry is computed from a 3D curve.");
	cls_BRepAdaptor_Curve.def("IsCurveOnSurface", (Standard_Boolean (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::IsCurveOnSurface, "Returns True if the edge geometry is computed from a pcurve on a surface.");
	cls_BRepAdaptor_Curve.def("Curve", (const GeomAdaptor_Curve & (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Curve, "Returns the Curve of the edge.");
	cls_BRepAdaptor_Curve.def("CurveOnSurface", (const Adaptor3d_CurveOnSurface & (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::CurveOnSurface, "Returns the CurveOnSurface of the edge.");
	cls_BRepAdaptor_Curve.def("Edge", (const TopoDS_Edge & (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Edge, "Returns the edge.");
	cls_BRepAdaptor_Curve.def("Tolerance", (Standard_Real (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Tolerance, "Returns the edge tolerance.");
	cls_BRepAdaptor_Curve.def("FirstParameter", (Standard_Real (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::FirstParameter, "None");
	cls_BRepAdaptor_Curve.def("LastParameter", (Standard_Real (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::LastParameter, "None");
	cls_BRepAdaptor_Curve.def("Continuity", (GeomAbs_Shape (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Continuity, "None");
	cls_BRepAdaptor_Curve.def("NbIntervals", (Standard_Integer (BRepAdaptor_Curve::*)(const GeomAbs_Shape) const ) &BRepAdaptor_Curve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BRepAdaptor_Curve.def("Intervals", (void (BRepAdaptor_Curve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BRepAdaptor_Curve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BRepAdaptor_Curve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (BRepAdaptor_Curve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &BRepAdaptor_Curve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_BRepAdaptor_Curve.def("IsClosed", (Standard_Boolean (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::IsClosed, "None");
	cls_BRepAdaptor_Curve.def("IsPeriodic", (Standard_Boolean (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::IsPeriodic, "None");
	cls_BRepAdaptor_Curve.def("Period", (Standard_Real (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Period, "None");
	cls_BRepAdaptor_Curve.def("Value", (gp_Pnt (BRepAdaptor_Curve::*)(const Standard_Real) const ) &BRepAdaptor_Curve::Value, "Computes the point of parameter U on the curve", py::arg("U"));
	cls_BRepAdaptor_Curve.def("D0", (void (BRepAdaptor_Curve::*)(const Standard_Real, gp_Pnt &) const ) &BRepAdaptor_Curve::D0, "Computes the point of parameter U.", py::arg("U"), py::arg("P"));
	cls_BRepAdaptor_Curve.def("D1", (void (BRepAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &BRepAdaptor_Curve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_BRepAdaptor_Curve.def("D2", (void (BRepAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &BRepAdaptor_Curve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_BRepAdaptor_Curve.def("D3", (void (BRepAdaptor_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BRepAdaptor_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_BRepAdaptor_Curve.def("DN", (gp_Vec (BRepAdaptor_Curve::*)(const Standard_Real, const Standard_Integer) const ) &BRepAdaptor_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_BRepAdaptor_Curve.def("Resolution", (Standard_Real (BRepAdaptor_Curve::*)(const Standard_Real) const ) &BRepAdaptor_Curve::Resolution, "returns the parametric resolution", py::arg("R3d"));
	cls_BRepAdaptor_Curve.def("GetType", (GeomAbs_CurveType (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::GetType, "None");
	cls_BRepAdaptor_Curve.def("Line", (gp_Lin (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Line, "None");
	cls_BRepAdaptor_Curve.def("Circle", (gp_Circ (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Circle, "None");
	cls_BRepAdaptor_Curve.def("Ellipse", (gp_Elips (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Ellipse, "None");
	cls_BRepAdaptor_Curve.def("Hyperbola", (gp_Hypr (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Hyperbola, "None");
	cls_BRepAdaptor_Curve.def("Parabola", (gp_Parab (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Parabola, "None");
	cls_BRepAdaptor_Curve.def("Degree", (Standard_Integer (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Degree, "None");
	cls_BRepAdaptor_Curve.def("IsRational", (Standard_Boolean (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::IsRational, "None");
	cls_BRepAdaptor_Curve.def("NbPoles", (Standard_Integer (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::NbPoles, "None");
	cls_BRepAdaptor_Curve.def("NbKnots", (Standard_Integer (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::NbKnots, "None");
	cls_BRepAdaptor_Curve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::Bezier, "Warning : This will make a copy of the Bezier Curve since it applies to it myTsrf . Be carefull when using this method");
	cls_BRepAdaptor_Curve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::BSpline, "Warning : This will make a copy of the BSpline Curve since it applies to it myTsrf . Be carefull when using this method");
	cls_BRepAdaptor_Curve.def("OffsetCurve", (opencascade::handle<Geom_OffsetCurve> (BRepAdaptor_Curve::*)() const ) &BRepAdaptor_Curve::OffsetCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_Array1OfCurve.hxx
	bind_NCollection_Array1<BRepAdaptor_Curve>(mod, "BRepAdaptor_Array1OfCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_CompCurve.hxx
	py::class_<BRepAdaptor_CompCurve, std::unique_ptr<BRepAdaptor_CompCurve, Deleter<BRepAdaptor_CompCurve>>, Adaptor3d_Curve> cls_BRepAdaptor_CompCurve(mod, "BRepAdaptor_CompCurve", "The Curve from BRepAdaptor allows to use a Wire of the BRep topology like a 3D curve. Warning: With this class of curve, C0 and C1 continuities are not assumed. So be carful with some algorithm!");
	cls_BRepAdaptor_CompCurve.def(py::init<>());
	cls_BRepAdaptor_CompCurve.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
	cls_BRepAdaptor_CompCurve.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("W"), py::arg("KnotByCurvilinearAbcissa"));
	cls_BRepAdaptor_CompCurve.def(py::init<const TopoDS_Wire &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("W"), py::arg("KnotByCurvilinearAbcissa"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_BRepAdaptor_CompCurve.def("Initialize", (void (BRepAdaptor_CompCurve::*)(const TopoDS_Wire &, const Standard_Boolean)) &BRepAdaptor_CompCurve::Initialize, "Sets the wire <W>.", py::arg("W"), py::arg("KnotByCurvilinearAbcissa"));
	cls_BRepAdaptor_CompCurve.def("Initialize", (void (BRepAdaptor_CompCurve::*)(const TopoDS_Wire &, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepAdaptor_CompCurve::Initialize, "Sets wire <W> and trimmed parameter.", py::arg("W"), py::arg("KnotByCurvilinearAbcissa"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_BRepAdaptor_CompCurve.def("SetPeriodic", (void (BRepAdaptor_CompCurve::*)(const Standard_Boolean)) &BRepAdaptor_CompCurve::SetPeriodic, "Set the flag Periodic. Warning: This method has no effect if the wire is not closed", py::arg("Periodic"));
	cls_BRepAdaptor_CompCurve.def("Wire", (const TopoDS_Wire & (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Wire, "Returns the wire.");
	cls_BRepAdaptor_CompCurve.def("Edge", [](BRepAdaptor_CompCurve &self, const Standard_Real U, TopoDS_Edge & E, Standard_Real & UonE){ self.Edge(U, E, UonE); return UonE; }, "returns an edge and one parameter on them corresponding to the parameter U.", py::arg("U"), py::arg("E"), py::arg("UonE"));
	cls_BRepAdaptor_CompCurve.def("FirstParameter", (Standard_Real (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::FirstParameter, "None");
	cls_BRepAdaptor_CompCurve.def("LastParameter", (Standard_Real (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::LastParameter, "None");
	cls_BRepAdaptor_CompCurve.def("Continuity", (GeomAbs_Shape (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Continuity, "None");
	cls_BRepAdaptor_CompCurve.def("NbIntervals", (Standard_Integer (BRepAdaptor_CompCurve::*)(const GeomAbs_Shape) const ) &BRepAdaptor_CompCurve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BRepAdaptor_CompCurve.def("Intervals", (void (BRepAdaptor_CompCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BRepAdaptor_CompCurve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BRepAdaptor_CompCurve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (BRepAdaptor_CompCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &BRepAdaptor_CompCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_BRepAdaptor_CompCurve.def("IsClosed", (Standard_Boolean (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::IsClosed, "None");
	cls_BRepAdaptor_CompCurve.def("IsPeriodic", (Standard_Boolean (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::IsPeriodic, "None");
	cls_BRepAdaptor_CompCurve.def("Period", (Standard_Real (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Period, "None");
	cls_BRepAdaptor_CompCurve.def("Value", (gp_Pnt (BRepAdaptor_CompCurve::*)(const Standard_Real) const ) &BRepAdaptor_CompCurve::Value, "Computes the point of parameter U on the curve", py::arg("U"));
	cls_BRepAdaptor_CompCurve.def("D0", (void (BRepAdaptor_CompCurve::*)(const Standard_Real, gp_Pnt &) const ) &BRepAdaptor_CompCurve::D0, "Computes the point of parameter U.", py::arg("U"), py::arg("P"));
	cls_BRepAdaptor_CompCurve.def("D1", (void (BRepAdaptor_CompCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &BRepAdaptor_CompCurve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_BRepAdaptor_CompCurve.def("D2", (void (BRepAdaptor_CompCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &BRepAdaptor_CompCurve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_BRepAdaptor_CompCurve.def("D3", (void (BRepAdaptor_CompCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BRepAdaptor_CompCurve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_BRepAdaptor_CompCurve.def("DN", (gp_Vec (BRepAdaptor_CompCurve::*)(const Standard_Real, const Standard_Integer) const ) &BRepAdaptor_CompCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_BRepAdaptor_CompCurve.def("Resolution", (Standard_Real (BRepAdaptor_CompCurve::*)(const Standard_Real) const ) &BRepAdaptor_CompCurve::Resolution, "returns the parametric resolution", py::arg("R3d"));
	cls_BRepAdaptor_CompCurve.def("GetType", (GeomAbs_CurveType (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::GetType, "None");
	cls_BRepAdaptor_CompCurve.def("Line", (gp_Lin (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Line, "None");
	cls_BRepAdaptor_CompCurve.def("Circle", (gp_Circ (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Circle, "None");
	cls_BRepAdaptor_CompCurve.def("Ellipse", (gp_Elips (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Ellipse, "None");
	cls_BRepAdaptor_CompCurve.def("Hyperbola", (gp_Hypr (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Hyperbola, "None");
	cls_BRepAdaptor_CompCurve.def("Parabola", (gp_Parab (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Parabola, "None");
	cls_BRepAdaptor_CompCurve.def("Degree", (Standard_Integer (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Degree, "None");
	cls_BRepAdaptor_CompCurve.def("IsRational", (Standard_Boolean (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::IsRational, "None");
	cls_BRepAdaptor_CompCurve.def("NbPoles", (Standard_Integer (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::NbPoles, "None");
	cls_BRepAdaptor_CompCurve.def("NbKnots", (Standard_Integer (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::NbKnots, "None");
	cls_BRepAdaptor_CompCurve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::Bezier, "None");
	cls_BRepAdaptor_CompCurve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (BRepAdaptor_CompCurve::*)() const ) &BRepAdaptor_CompCurve::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_Curve2d.hxx
	py::class_<BRepAdaptor_Curve2d, std::unique_ptr<BRepAdaptor_Curve2d, Deleter<BRepAdaptor_Curve2d>>, Geom2dAdaptor_Curve> cls_BRepAdaptor_Curve2d(mod, "BRepAdaptor_Curve2d", "The Curve2d from BRepAdaptor allows to use an Edge on a Face like a 2d curve. (curve in the parametric space).");
	cls_BRepAdaptor_Curve2d.def(py::init<>());
	cls_BRepAdaptor_Curve2d.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("E"), py::arg("F"));
	cls_BRepAdaptor_Curve2d.def("Initialize", (void (BRepAdaptor_Curve2d::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepAdaptor_Curve2d::Initialize, "Initialize with the pcurve of <E> on <F>.", py::arg("E"), py::arg("F"));
	cls_BRepAdaptor_Curve2d.def("Edge", (const TopoDS_Edge & (BRepAdaptor_Curve2d::*)() const ) &BRepAdaptor_Curve2d::Edge, "Returns the Edge.");
	cls_BRepAdaptor_Curve2d.def("Face", (const TopoDS_Face & (BRepAdaptor_Curve2d::*)() const ) &BRepAdaptor_Curve2d::Face, "Returns the Face.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_HCompCurve.hxx
	py::class_<BRepAdaptor_HCompCurve, opencascade::handle<BRepAdaptor_HCompCurve>, Adaptor3d_HCurve> cls_BRepAdaptor_HCompCurve(mod, "BRepAdaptor_HCompCurve", "None");
	cls_BRepAdaptor_HCompCurve.def(py::init<>());
	cls_BRepAdaptor_HCompCurve.def(py::init<const BRepAdaptor_CompCurve &>(), py::arg("C"));
	cls_BRepAdaptor_HCompCurve.def("Set", (void (BRepAdaptor_HCompCurve::*)(const BRepAdaptor_CompCurve &)) &BRepAdaptor_HCompCurve::Set, "Sets the field of the GenHCurve.", py::arg("C"));
	cls_BRepAdaptor_HCompCurve.def("Curve", (const Adaptor3d_Curve & (BRepAdaptor_HCompCurve::*)() const ) &BRepAdaptor_HCompCurve::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_BRepAdaptor_HCompCurve.def("GetCurve", (Adaptor3d_Curve & (BRepAdaptor_HCompCurve::*)()) &BRepAdaptor_HCompCurve::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_BRepAdaptor_HCompCurve.def("ChangeCurve", (BRepAdaptor_CompCurve & (BRepAdaptor_HCompCurve::*)()) &BRepAdaptor_HCompCurve::ChangeCurve, "Returns the curve used to create the GenHCurve.");
	cls_BRepAdaptor_HCompCurve.def_static("get_type_name_", (const char * (*)()) &BRepAdaptor_HCompCurve::get_type_name, "None");
	cls_BRepAdaptor_HCompCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAdaptor_HCompCurve::get_type_descriptor, "None");
	cls_BRepAdaptor_HCompCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAdaptor_HCompCurve::*)() const ) &BRepAdaptor_HCompCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_HCurve.hxx
	py::class_<BRepAdaptor_HCurve, opencascade::handle<BRepAdaptor_HCurve>, Adaptor3d_HCurve> cls_BRepAdaptor_HCurve(mod, "BRepAdaptor_HCurve", "None");
	cls_BRepAdaptor_HCurve.def(py::init<>());
	cls_BRepAdaptor_HCurve.def(py::init<const BRepAdaptor_Curve &>(), py::arg("C"));
	cls_BRepAdaptor_HCurve.def("Set", (void (BRepAdaptor_HCurve::*)(const BRepAdaptor_Curve &)) &BRepAdaptor_HCurve::Set, "Sets the field of the GenHCurve.", py::arg("C"));
	cls_BRepAdaptor_HCurve.def("Curve", (const Adaptor3d_Curve & (BRepAdaptor_HCurve::*)() const ) &BRepAdaptor_HCurve::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_BRepAdaptor_HCurve.def("GetCurve", (Adaptor3d_Curve & (BRepAdaptor_HCurve::*)()) &BRepAdaptor_HCurve::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_BRepAdaptor_HCurve.def("ChangeCurve", (BRepAdaptor_Curve & (BRepAdaptor_HCurve::*)()) &BRepAdaptor_HCurve::ChangeCurve, "Returns the curve used to create the GenHCurve.");
	cls_BRepAdaptor_HCurve.def_static("get_type_name_", (const char * (*)()) &BRepAdaptor_HCurve::get_type_name, "None");
	cls_BRepAdaptor_HCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAdaptor_HCurve::get_type_descriptor, "None");
	cls_BRepAdaptor_HCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAdaptor_HCurve::*)() const ) &BRepAdaptor_HCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_HCurve2d.hxx
	py::class_<BRepAdaptor_HCurve2d, opencascade::handle<BRepAdaptor_HCurve2d>, Adaptor2d_HCurve2d> cls_BRepAdaptor_HCurve2d(mod, "BRepAdaptor_HCurve2d", "None");
	cls_BRepAdaptor_HCurve2d.def(py::init<>());
	cls_BRepAdaptor_HCurve2d.def(py::init<const BRepAdaptor_Curve2d &>(), py::arg("C"));
	cls_BRepAdaptor_HCurve2d.def("Set", (void (BRepAdaptor_HCurve2d::*)(const BRepAdaptor_Curve2d &)) &BRepAdaptor_HCurve2d::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
	cls_BRepAdaptor_HCurve2d.def("Curve2d", (const Adaptor2d_Curve2d & (BRepAdaptor_HCurve2d::*)() const ) &BRepAdaptor_HCurve2d::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
	cls_BRepAdaptor_HCurve2d.def("ChangeCurve2d", (BRepAdaptor_Curve2d & (BRepAdaptor_HCurve2d::*)()) &BRepAdaptor_HCurve2d::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
	cls_BRepAdaptor_HCurve2d.def_static("get_type_name_", (const char * (*)()) &BRepAdaptor_HCurve2d::get_type_name, "None");
	cls_BRepAdaptor_HCurve2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAdaptor_HCurve2d::get_type_descriptor, "None");
	cls_BRepAdaptor_HCurve2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAdaptor_HCurve2d::*)() const ) &BRepAdaptor_HCurve2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_HSurface.hxx
	py::class_<BRepAdaptor_HSurface, opencascade::handle<BRepAdaptor_HSurface>, Adaptor3d_HSurface> cls_BRepAdaptor_HSurface(mod, "BRepAdaptor_HSurface", "None");
	cls_BRepAdaptor_HSurface.def(py::init<>());
	cls_BRepAdaptor_HSurface.def(py::init<const BRepAdaptor_Surface &>(), py::arg("S"));
	cls_BRepAdaptor_HSurface.def("Set", (void (BRepAdaptor_HSurface::*)(const BRepAdaptor_Surface &)) &BRepAdaptor_HSurface::Set, "Sets the field of the GenHSurface.", py::arg("S"));
	cls_BRepAdaptor_HSurface.def("Surface", (const Adaptor3d_Surface & (BRepAdaptor_HSurface::*)() const ) &BRepAdaptor_HSurface::Surface, "Returns a reference to the Surface inside the HSurface. This is redefined from HSurface, cannot be inline.");
	cls_BRepAdaptor_HSurface.def("ChangeSurface", (BRepAdaptor_Surface & (BRepAdaptor_HSurface::*)()) &BRepAdaptor_HSurface::ChangeSurface, "Returns the surface used to create the GenHSurface.");
	cls_BRepAdaptor_HSurface.def_static("get_type_name_", (const char * (*)()) &BRepAdaptor_HSurface::get_type_name, "None");
	cls_BRepAdaptor_HSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAdaptor_HSurface::get_type_descriptor, "None");
	cls_BRepAdaptor_HSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAdaptor_HSurface::*)() const ) &BRepAdaptor_HSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepAdaptor_HArray1OfCurve.hxx
	py::class_<BRepAdaptor_HArray1OfCurve, opencascade::handle<BRepAdaptor_HArray1OfCurve>, BRepAdaptor_Array1OfCurve, Standard_Transient> cls_BRepAdaptor_HArray1OfCurve(mod, "BRepAdaptor_HArray1OfCurve", "None");
	cls_BRepAdaptor_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_BRepAdaptor_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer, const BRepAdaptor_Array1OfCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_BRepAdaptor_HArray1OfCurve.def(py::init<const BRepAdaptor_Array1OfCurve &>(), py::arg("theOther"));
	cls_BRepAdaptor_HArray1OfCurve.def("Array1", (const BRepAdaptor_Array1OfCurve & (BRepAdaptor_HArray1OfCurve::*)() const ) &BRepAdaptor_HArray1OfCurve::Array1, "None");
	cls_BRepAdaptor_HArray1OfCurve.def("ChangeArray1", (BRepAdaptor_Array1OfCurve & (BRepAdaptor_HArray1OfCurve::*)()) &BRepAdaptor_HArray1OfCurve::ChangeArray1, "None");
	cls_BRepAdaptor_HArray1OfCurve.def_static("get_type_name_", (const char * (*)()) &BRepAdaptor_HArray1OfCurve::get_type_name, "None");
	cls_BRepAdaptor_HArray1OfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAdaptor_HArray1OfCurve::get_type_descriptor, "None");
	cls_BRepAdaptor_HArray1OfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAdaptor_HArray1OfCurve::*)() const ) &BRepAdaptor_HArray1OfCurve::DynamicType, "None");


}
