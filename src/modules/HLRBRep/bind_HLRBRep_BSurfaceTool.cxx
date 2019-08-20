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
#include <BRepAdaptor_Surface.hxx>
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
#include <gp_Torus.hxx>
#include <gp_Sphere.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <gp_Ax1.hxx>
#include <gp_Dir.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <HLRBRep_BSurfaceTool.hxx>

void bind_HLRBRep_BSurfaceTool(py::module &mod){

py::class_<HLRBRep_BSurfaceTool, std::unique_ptr<HLRBRep_BSurfaceTool>> cls_HLRBRep_BSurfaceTool(mod, "HLRBRep_BSurfaceTool", "None");

// Constructors

// Fields

// Methods
// cls_HLRBRep_BSurfaceTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_BSurfaceTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_BSurfaceTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_BSurfaceTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_BSurfaceTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_BSurfaceTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_BSurfaceTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_BSurfaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_BSurfaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_BSurfaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_BSurfaceTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_BSurfaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_BSurfaceTool.def_static("FirstUParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::FirstUParameter, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("FirstVParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::FirstVParameter, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("LastUParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::LastUParameter, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("LastVParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::LastVParameter, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbUIntervals_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const GeomAbs_Shape)) &HLRBRep_BSurfaceTool::NbUIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_HLRBRep_BSurfaceTool.def_static("NbVIntervals_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const GeomAbs_Shape)) &HLRBRep_BSurfaceTool::NbVIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_HLRBRep_BSurfaceTool.def_static("UIntervals_", (void (*)(const BRepAdaptor_Surface &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_BSurfaceTool::UIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_HLRBRep_BSurfaceTool.def_static("VIntervals_", (void (*)(const BRepAdaptor_Surface &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &HLRBRep_BSurfaceTool::VIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_HLRBRep_BSurfaceTool.def_static("UTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::UTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_HLRBRep_BSurfaceTool.def_static("VTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::VTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_HLRBRep_BSurfaceTool.def_static("IsUClosed_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsUClosed, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsVClosed_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsVClosed, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsUPeriodic_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsUPeriodic, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("UPeriod_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::UPeriod, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsVPeriodic_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsVPeriodic, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("VPeriod_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::VPeriod, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Value_", (gp_Pnt (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::Value, "None", py::arg("S"), py::arg("u"), py::arg("v"));
cls_HLRBRep_BSurfaceTool.def_static("D0_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &)) &HLRBRep_BSurfaceTool::D0, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"));
cls_HLRBRep_BSurfaceTool.def_static("D1_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &HLRBRep_BSurfaceTool::D1, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1u"), py::arg("D1v"));
cls_HLRBRep_BSurfaceTool.def_static("D2_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_BSurfaceTool::D2, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_HLRBRep_BSurfaceTool.def_static("D3_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &HLRBRep_BSurfaceTool::D3, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_HLRBRep_BSurfaceTool.def_static("DN_", (gp_Vec (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &HLRBRep_BSurfaceTool::DN, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("Nu"), py::arg("Nv"));
cls_HLRBRep_BSurfaceTool.def_static("UContinuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::UContinuity, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("VContinuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::VContinuity, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("UDegree_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::UDegree, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbUPoles_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbUPoles, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbUKnots_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbUKnots, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsURational_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsURational, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("VDegree_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::VDegree, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbVPoles_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbVPoles, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbVKnots_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbVKnots, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("IsVRational_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::IsVRational, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("UResolution_", (Standard_Real (*)(const BRepAdaptor_Surface &, const Standard_Real)) &HLRBRep_BSurfaceTool::UResolution, "None", py::arg("S"), py::arg("R3d"));
cls_HLRBRep_BSurfaceTool.def_static("VResolution_", (Standard_Real (*)(const BRepAdaptor_Surface &, const Standard_Real)) &HLRBRep_BSurfaceTool::VResolution, "None", py::arg("S"), py::arg("R3d"));
cls_HLRBRep_BSurfaceTool.def_static("GetType_", (GeomAbs_SurfaceType (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::GetType, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Plane_", (gp_Pln (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Plane, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Cylinder_", (gp_Cylinder (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Cylinder, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Cone_", (gp_Cone (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Cone, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Torus_", (gp_Torus (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Torus, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Sphere_", (gp_Sphere (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Sphere, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Bezier_", (opencascade::handle<Geom_BezierSurface> (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Bezier, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineSurface> (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::BSpline, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("AxeOfRevolution_", (gp_Ax1 (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::AxeOfRevolution, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("Direction_", (gp_Dir (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Direction, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("BasisCurve_", (opencascade::handle<Adaptor3d_HCurve> (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::BasisCurve, "None", py::arg("S"));
// cls_HLRBRep_BSurfaceTool.def_static("Axis_", (gp_Ax1 (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::Axis, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbSamplesU, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &HLRBRep_BSurfaceTool::NbSamplesV, "None", py::arg("S"));
cls_HLRBRep_BSurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
cls_HLRBRep_BSurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &HLRBRep_BSurfaceTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));

// Enums

}