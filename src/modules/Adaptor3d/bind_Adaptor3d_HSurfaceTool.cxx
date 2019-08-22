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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
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
#include <Adaptor3d_HSurfaceTool.hxx>

void bind_Adaptor3d_HSurfaceTool(py::module &mod){

py::class_<Adaptor3d_HSurfaceTool> cls_Adaptor3d_HSurfaceTool(mod, "Adaptor3d_HSurfaceTool", "None");

// Constructors

// Fields

// Methods
// cls_Adaptor3d_HSurfaceTool.def_static("operator new_", (void * (*)(size_t)) &Adaptor3d_HSurfaceTool::operator new, "None", py::arg("theSize"));
// cls_Adaptor3d_HSurfaceTool.def_static("operator delete_", (void (*)(void *)) &Adaptor3d_HSurfaceTool::operator delete, "None", py::arg("theAddress"));
// cls_Adaptor3d_HSurfaceTool.def_static("operator new[]_", (void * (*)(size_t)) &Adaptor3d_HSurfaceTool::operator new[], "None", py::arg("theSize"));
// cls_Adaptor3d_HSurfaceTool.def_static("operator delete[]_", (void (*)(void *)) &Adaptor3d_HSurfaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_Adaptor3d_HSurfaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &Adaptor3d_HSurfaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Adaptor3d_HSurfaceTool.def_static("operator delete_", (void (*)(void *, void *)) &Adaptor3d_HSurfaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Adaptor3d_HSurfaceTool.def_static("FirstUParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::FirstUParameter, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("FirstVParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::FirstVParameter, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("LastUParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::LastUParameter, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("LastVParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::LastVParameter, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("NbUIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const GeomAbs_Shape)) &Adaptor3d_HSurfaceTool::NbUIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_Adaptor3d_HSurfaceTool.def_static("NbVIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const GeomAbs_Shape)) &Adaptor3d_HSurfaceTool::NbVIntervals, "None", py::arg("S"), py::arg("Sh"));
cls_Adaptor3d_HSurfaceTool.def_static("UIntervals_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &Adaptor3d_HSurfaceTool::UIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_Adaptor3d_HSurfaceTool.def_static("VIntervals_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &Adaptor3d_HSurfaceTool::VIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
cls_Adaptor3d_HSurfaceTool.def_static("UTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::UTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_HSurfaceTool.def_static("VTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::VTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
cls_Adaptor3d_HSurfaceTool.def_static("IsUClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::IsUClosed, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("IsVClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::IsVClosed, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("IsUPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::IsUPeriodic, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("UPeriod_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::UPeriod, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("IsVPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::IsVPeriodic, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("VPeriod_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::VPeriod, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("Value_", (gp_Pnt (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::Value, "None", py::arg("S"), py::arg("u"), py::arg("v"));
cls_Adaptor3d_HSurfaceTool.def_static("D0_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &)) &Adaptor3d_HSurfaceTool::D0, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"));
cls_Adaptor3d_HSurfaceTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &Adaptor3d_HSurfaceTool::D1, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1u"), py::arg("D1v"));
cls_Adaptor3d_HSurfaceTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &Adaptor3d_HSurfaceTool::D2, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_Adaptor3d_HSurfaceTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &Adaptor3d_HSurfaceTool::D3, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_Adaptor3d_HSurfaceTool.def_static("DN_", (gp_Vec (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &Adaptor3d_HSurfaceTool::DN, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("Nu"), py::arg("Nv"));
cls_Adaptor3d_HSurfaceTool.def_static("UResolution_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real)) &Adaptor3d_HSurfaceTool::UResolution, "None", py::arg("S"), py::arg("R3d"));
cls_Adaptor3d_HSurfaceTool.def_static("VResolution_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real)) &Adaptor3d_HSurfaceTool::VResolution, "None", py::arg("S"), py::arg("R3d"));
cls_Adaptor3d_HSurfaceTool.def_static("GetType_", (GeomAbs_SurfaceType (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::GetType, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("Plane_", (gp_Pln (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Plane, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("Cylinder_", (gp_Cylinder (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Cylinder, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("Cone_", (gp_Cone (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Cone, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("Torus_", (gp_Torus (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Torus, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("Sphere_", (gp_Sphere (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Sphere, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("Bezier_", (opencascade::handle<Geom_BezierSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Bezier, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::BSpline, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("AxeOfRevolution_", (gp_Ax1 (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::AxeOfRevolution, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("Direction_", (gp_Dir (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Direction, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("BasisCurve_", (opencascade::handle<Adaptor3d_HCurve> (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::BasisCurve, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("BasisSurface_", (opencascade::handle<Adaptor3d_HSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::BasisSurface, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("OffsetValue_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::OffsetValue, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::NbSamplesU, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::NbSamplesV, "None", py::arg("S"));
cls_Adaptor3d_HSurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
cls_Adaptor3d_HSurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));

// Enums

}