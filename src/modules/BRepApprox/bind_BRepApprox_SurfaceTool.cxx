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
#include <BRepApprox_SurfaceTool.hxx>

void bind_BRepApprox_SurfaceTool(py::module &mod){

py::class_<BRepApprox_SurfaceTool, std::unique_ptr<BRepApprox_SurfaceTool>> cls_BRepApprox_SurfaceTool(mod, "BRepApprox_SurfaceTool", "None");

// Constructors

// Fields

// Methods
// cls_BRepApprox_SurfaceTool.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_SurfaceTool::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_SurfaceTool.def_static("operator delete_", (void (*)(void *)) &BRepApprox_SurfaceTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_SurfaceTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_SurfaceTool::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_SurfaceTool.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_SurfaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_SurfaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_SurfaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_SurfaceTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_SurfaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_SurfaceTool.def_static("FirstUParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::FirstUParameter, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("FirstVParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::FirstVParameter, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("LastUParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::LastUParameter, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("LastVParameter_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::LastVParameter, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("NbUIntervals_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const GeomAbs_Shape)) &BRepApprox_SurfaceTool::NbUIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_BRepApprox_SurfaceTool.def_static("NbVIntervals_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const GeomAbs_Shape)) &BRepApprox_SurfaceTool::NbVIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_BRepApprox_SurfaceTool.def_static("UIntervals_", (void (*)(const BRepAdaptor_Surface &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &BRepApprox_SurfaceTool::UIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_BRepApprox_SurfaceTool.def_static("VIntervals_", (void (*)(const BRepAdaptor_Surface &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &BRepApprox_SurfaceTool::VIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_BRepApprox_SurfaceTool.def_static("UTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepApprox_SurfaceTool::UTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_BRepApprox_SurfaceTool.def_static("VTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepApprox_SurfaceTool::VTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_BRepApprox_SurfaceTool.def_static("IsUClosed_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::IsUClosed, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("IsVClosed_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::IsVClosed, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("IsUPeriodic_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::IsUPeriodic, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("UPeriod_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::UPeriod, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("IsVPeriodic_", (Standard_Boolean (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::IsVPeriodic, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("VPeriod_", (Standard_Real (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::VPeriod, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("Value_", (gp_Pnt (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &BRepApprox_SurfaceTool::Value, "None", py::arg("S"), py::arg("u"), py::arg("v"));
cls_BRepApprox_SurfaceTool.def_static("D0_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &)) &BRepApprox_SurfaceTool::D0, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"));
cls_BRepApprox_SurfaceTool.def_static("D1_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &BRepApprox_SurfaceTool::D1, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1u"), py::arg("D1v"));
cls_BRepApprox_SurfaceTool.def_static("D2_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &BRepApprox_SurfaceTool::D2, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_BRepApprox_SurfaceTool.def_static("D3_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &BRepApprox_SurfaceTool::D3, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_BRepApprox_SurfaceTool.def_static("DN_", (gp_Vec (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &BRepApprox_SurfaceTool::DN, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("Nu"), py::arg("Nv"));
cls_BRepApprox_SurfaceTool.def_static("UResolution_", (Standard_Real (*)(const BRepAdaptor_Surface &, const Standard_Real)) &BRepApprox_SurfaceTool::UResolution, "None", py::arg("S"), py::arg("R3d"));
cls_BRepApprox_SurfaceTool.def_static("VResolution_", (Standard_Real (*)(const BRepAdaptor_Surface &, const Standard_Real)) &BRepApprox_SurfaceTool::VResolution, "None", py::arg("S"), py::arg("R3d"));
cls_BRepApprox_SurfaceTool.def_static("GetType_", (GeomAbs_SurfaceType (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::GetType, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("Plane_", (gp_Pln (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::Plane, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("Cylinder_", (gp_Cylinder (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::Cylinder, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("Cone_", (gp_Cone (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::Cone, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("Torus_", (gp_Torus (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::Torus, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("Sphere_", (gp_Sphere (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::Sphere, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("Bezier_", (opencascade::handle<Geom_BezierSurface> (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::Bezier, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineSurface> (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::BSpline, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("AxeOfRevolution_", (gp_Ax1 (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::AxeOfRevolution, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("Direction_", (gp_Dir (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::Direction, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("BasisCurve_", (opencascade::handle<Adaptor3d_HCurve> (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::BasisCurve, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::NbSamplesU, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &BRepApprox_SurfaceTool::NbSamplesV, "None", py::arg("S"));
cls_BRepApprox_SurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &BRepApprox_SurfaceTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
cls_BRepApprox_SurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real)) &BRepApprox_SurfaceTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));

// Enums

}