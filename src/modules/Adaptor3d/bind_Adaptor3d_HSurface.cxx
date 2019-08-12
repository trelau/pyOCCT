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
#include <Standard_Transient.hxx>
#include <Adaptor3d_Surface.hxx>
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
#include <Standard_Type.hxx>

void bind_Adaptor3d_HSurface(py::module &mod){

py::class_<Adaptor3d_HSurface, opencascade::handle<Adaptor3d_HSurface>, Standard_Transient> cls_Adaptor3d_HSurface(mod, "Adaptor3d_HSurface", "Root class for surfaces manipulated by handles, on which geometric algorithms work. An adapted surface is an interface between the services provided by a surface and those required of the surface by algorithms which use it. A derived concrete class is provided: GeomAdaptor_HSurface for a surface from the Geom package.");

// Fields

// Methods
cls_Adaptor3d_HSurface.def("Surface", (const Adaptor3d_Surface & (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::Surface, "Returns a reference to the Surface inside the HSurface.");
cls_Adaptor3d_HSurface.def("FirstUParameter", (Standard_Real (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::FirstUParameter, "None");
cls_Adaptor3d_HSurface.def("LastUParameter", (Standard_Real (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::LastUParameter, "None");
cls_Adaptor3d_HSurface.def("FirstVParameter", (Standard_Real (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::FirstVParameter, "None");
cls_Adaptor3d_HSurface.def("LastVParameter", (Standard_Real (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::LastVParameter, "None");
cls_Adaptor3d_HSurface.def("UContinuity", (GeomAbs_Shape (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::UContinuity, "None");
cls_Adaptor3d_HSurface.def("VContinuity", (GeomAbs_Shape (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::VContinuity, "None");
cls_Adaptor3d_HSurface.def("NbUIntervals", (Standard_Integer (Adaptor3d_HSurface::*)(const GeomAbs_Shape) const) &Adaptor3d_HSurface::NbUIntervals, "None", py::arg("S"));
cls_Adaptor3d_HSurface.def("NbVIntervals", (Standard_Integer (Adaptor3d_HSurface::*)(const GeomAbs_Shape) const) &Adaptor3d_HSurface::NbVIntervals, "None", py::arg("S"));
cls_Adaptor3d_HSurface.def("UIntervals", (void (Adaptor3d_HSurface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor3d_HSurface::UIntervals, "None", py::arg("T"), py::arg("S"));
cls_Adaptor3d_HSurface.def("VIntervals", (void (Adaptor3d_HSurface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Adaptor3d_HSurface::VIntervals, "None", py::arg("T"), py::arg("S"));
cls_Adaptor3d_HSurface.def("UTrim", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor3d_HSurface::UTrim, "None", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_HSurface.def("VTrim", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &Adaptor3d_HSurface::VTrim, "None", py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_HSurface.def("IsUClosed", (Standard_Boolean (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::IsUClosed, "None");
cls_Adaptor3d_HSurface.def("IsVClosed", (Standard_Boolean (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::IsVClosed, "None");
cls_Adaptor3d_HSurface.def("IsUPeriodic", (Standard_Boolean (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::IsUPeriodic, "None");
cls_Adaptor3d_HSurface.def("UPeriod", (Standard_Real (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::UPeriod, "None");
cls_Adaptor3d_HSurface.def("IsVPeriodic", (Standard_Boolean (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::IsVPeriodic, "None");
cls_Adaptor3d_HSurface.def("VPeriod", (Standard_Real (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::VPeriod, "None");
cls_Adaptor3d_HSurface.def("Value", (gp_Pnt (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real) const) &Adaptor3d_HSurface::Value, "None", py::arg("U"), py::arg("V"));
cls_Adaptor3d_HSurface.def("D0", (void (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &Adaptor3d_HSurface::D0, "None", py::arg("U"), py::arg("V"), py::arg("P"));
cls_Adaptor3d_HSurface.def("D1", (void (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Adaptor3d_HSurface::D1, "None", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_Adaptor3d_HSurface.def("D2", (void (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Adaptor3d_HSurface::D2, "None", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Adaptor3d_HSurface.def("D3", (void (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Adaptor3d_HSurface::D3, "None", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Adaptor3d_HSurface.def("DN", (gp_Vec (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &Adaptor3d_HSurface::DN, "None", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_Adaptor3d_HSurface.def("UResolution", (Standard_Real (Adaptor3d_HSurface::*)(const Standard_Real) const) &Adaptor3d_HSurface::UResolution, "None", py::arg("R3d"));
cls_Adaptor3d_HSurface.def("VResolution", (Standard_Real (Adaptor3d_HSurface::*)(const Standard_Real) const) &Adaptor3d_HSurface::VResolution, "None", py::arg("R3d"));
cls_Adaptor3d_HSurface.def("GetType", (GeomAbs_SurfaceType (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::GetType, "None");
cls_Adaptor3d_HSurface.def("Plane", (gp_Pln (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::Plane, "None");
cls_Adaptor3d_HSurface.def("Cylinder", (gp_Cylinder (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::Cylinder, "None");
cls_Adaptor3d_HSurface.def("Cone", (gp_Cone (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::Cone, "None");
cls_Adaptor3d_HSurface.def("Sphere", (gp_Sphere (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::Sphere, "None");
cls_Adaptor3d_HSurface.def("Torus", (gp_Torus (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::Torus, "None");
cls_Adaptor3d_HSurface.def("UDegree", (Standard_Integer (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::UDegree, "None");
cls_Adaptor3d_HSurface.def("NbUPoles", (Standard_Integer (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::NbUPoles, "None");
cls_Adaptor3d_HSurface.def("VDegree", (Standard_Integer (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::VDegree, "None");
cls_Adaptor3d_HSurface.def("NbVPoles", (Standard_Integer (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::NbVPoles, "None");
cls_Adaptor3d_HSurface.def("NbUKnots", (Standard_Integer (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::NbUKnots, "None");
cls_Adaptor3d_HSurface.def("NbVKnots", (Standard_Integer (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::NbVKnots, "None");
cls_Adaptor3d_HSurface.def("IsURational", (Standard_Boolean (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::IsURational, "None");
cls_Adaptor3d_HSurface.def("IsVRational", (Standard_Boolean (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::IsVRational, "None");
cls_Adaptor3d_HSurface.def("Bezier", (opencascade::handle<Geom_BezierSurface> (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::Bezier, "None");
cls_Adaptor3d_HSurface.def("BSpline", (opencascade::handle<Geom_BSplineSurface> (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::BSpline, "None");
cls_Adaptor3d_HSurface.def("AxeOfRevolution", (gp_Ax1 (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::AxeOfRevolution, "None");
cls_Adaptor3d_HSurface.def("Direction", (gp_Dir (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::Direction, "None");
cls_Adaptor3d_HSurface.def("BasisCurve", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::BasisCurve, "None");
cls_Adaptor3d_HSurface.def("BasisSurface", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::BasisSurface, "None");
cls_Adaptor3d_HSurface.def("OffsetValue", (Standard_Real (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::OffsetValue, "None");
cls_Adaptor3d_HSurface.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_HSurface::get_type_name, "None");
cls_Adaptor3d_HSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_HSurface::get_type_descriptor, "None");
cls_Adaptor3d_HSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_HSurface::*)() const) &Adaptor3d_HSurface::DynamicType, "None");

// Enums

}