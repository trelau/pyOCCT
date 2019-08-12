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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <AppParCurves_Constraint.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2d_Curve.hxx>
#include <ProjLib_ComputeApproxOnPolarSurface.hxx>

void bind_ProjLib_ComputeApproxOnPolarSurface(py::module &mod){

py::class_<ProjLib_ComputeApproxOnPolarSurface, std::unique_ptr<ProjLib_ComputeApproxOnPolarSurface, Deleter<ProjLib_ComputeApproxOnPolarSurface>>> cls_ProjLib_ComputeApproxOnPolarSurface(mod, "ProjLib_ComputeApproxOnPolarSurface", "Approximate the projection of a 3d curve on an polar surface and stores the result in Approx. The result is a 2d curve. The evaluation of the current point of the 2d curve is done with the evaluation of the extrema P3d - Surface. For approximation some parameters are used, including required tolerance of approximation. Tolerance is maximal possible value of 3d deviation of 3d projection of projected curve from 'exact' 3d projection. Since algorithm searches 2d curve on surface, required 2d tolerance is computed from 3d tolerance with help of U,V resolutions of surface. 3d and 2d tolerances have sence only for curves on surface, it defines precision of projecting and approximation and have nothing to do with distance between the projected curve and the surface.");

// Constructors
cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<>());
cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("C"), py::arg("S"));
cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("Tol"));
cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("InitCurve2d"), py::arg("C"), py::arg("S"), py::arg("Tol"));
cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("InitCurve2d"), py::arg("InitCurve2dBis"), py::arg("C"), py::arg("S"), py::arg("Tol"));

// Fields

// Methods
// cls_ProjLib_ComputeApproxOnPolarSurface.def_static("operator new_", (void * (*)(size_t)) &ProjLib_ComputeApproxOnPolarSurface::operator new, "None", py::arg("theSize"));
// cls_ProjLib_ComputeApproxOnPolarSurface.def_static("operator delete_", (void (*)(void *)) &ProjLib_ComputeApproxOnPolarSurface::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_ComputeApproxOnPolarSurface.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_ComputeApproxOnPolarSurface::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_ComputeApproxOnPolarSurface.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_ComputeApproxOnPolarSurface::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_ComputeApproxOnPolarSurface.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_ComputeApproxOnPolarSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_ComputeApproxOnPolarSurface.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_ComputeApproxOnPolarSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_ComputeApproxOnPolarSurface.def("SetDegree", (void (ProjLib_ComputeApproxOnPolarSurface::*)(const Standard_Integer, const Standard_Integer)) &ProjLib_ComputeApproxOnPolarSurface::SetDegree, "Set min and max possible degree of result BSpline curve2d, which is got by approximation. If theDegMin/Max < 0, algorithm uses values min = 2, max = 8.", py::arg("theDegMin"), py::arg("theDegMax"));
cls_ProjLib_ComputeApproxOnPolarSurface.def("SetMaxSegments", (void (ProjLib_ComputeApproxOnPolarSurface::*)(const Standard_Integer)) &ProjLib_ComputeApproxOnPolarSurface::SetMaxSegments, "Set the parameter, which defines maximal value of parametric intervals the projected curve can be cut for approximation. If theMaxSegments < 0, algorithm uses default value = 1000.", py::arg("theMaxSegments"));
cls_ProjLib_ComputeApproxOnPolarSurface.def("SetBndPnt", (void (ProjLib_ComputeApproxOnPolarSurface::*)(const AppParCurves_Constraint)) &ProjLib_ComputeApproxOnPolarSurface::SetBndPnt, "Set the parameter, which defines type of boundary condition between segments during approximation. It can be AppParCurves_PassPoint or AppParCurves_TangencyPoint. Default value is AppParCurves_TangencyPoint.", py::arg("theBndPnt"));
cls_ProjLib_ComputeApproxOnPolarSurface.def("SetMaxDist", (void (ProjLib_ComputeApproxOnPolarSurface::*)(const Standard_Real)) &ProjLib_ComputeApproxOnPolarSurface::SetMaxDist, "Set the parameter, which defines maximal possible distance between projected curve and surface. It is used only for projecting on not analytical surfaces. If theMaxDist < 0, algoritm uses default value 100.*Tolerance. If real distance between curve and surface more then theMaxDist, algorithm stops working.", py::arg("theMaxDist"));
cls_ProjLib_ComputeApproxOnPolarSurface.def("SetTolerance", (void (ProjLib_ComputeApproxOnPolarSurface::*)(const Standard_Real)) &ProjLib_ComputeApproxOnPolarSurface::SetTolerance, "Set the tolerance used to project the curve on the surface. Default value is Precision::Approximation().", py::arg("theTolerance"));
cls_ProjLib_ComputeApproxOnPolarSurface.def("Perform", (void (ProjLib_ComputeApproxOnPolarSurface::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ComputeApproxOnPolarSurface::Perform, "Method, which performs projecting, using default values of parameters or they must be set by corresponding methods before using.", py::arg("C"), py::arg("S"));
cls_ProjLib_ComputeApproxOnPolarSurface.def("Perform", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ComputeApproxOnPolarSurface::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ComputeApproxOnPolarSurface::Perform, "Method, which performs projecting, using default values of parameters or they must be set by corresponding methods before using. Parameter InitCurve2d is any rough estimation of 2d result curve.", py::arg("InitCurve2d"), py::arg("C"), py::arg("S"));
cls_ProjLib_ComputeApproxOnPolarSurface.def("BuildInitialCurve2d", (opencascade::handle<Adaptor2d_HCurve2d> (ProjLib_ComputeApproxOnPolarSurface::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ComputeApproxOnPolarSurface::BuildInitialCurve2d, "Builds initial 2d curve as BSpline with degree = 1 using Extrema algoritm. Method is used in method Perform(...).", py::arg("Curve"), py::arg("S"));
cls_ProjLib_ComputeApproxOnPolarSurface.def("ProjectUsingInitialCurve2d", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ComputeApproxOnPolarSurface::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &ProjLib_ComputeApproxOnPolarSurface::ProjectUsingInitialCurve2d, "Method, which performs projecting. Method is used in method Perform(...).", py::arg("Curve"), py::arg("S"), py::arg("InitCurve2d"));
cls_ProjLib_ComputeApproxOnPolarSurface.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ComputeApproxOnPolarSurface::*)() const) &ProjLib_ComputeApproxOnPolarSurface::BSpline, "Returns result curve 2d.");
cls_ProjLib_ComputeApproxOnPolarSurface.def("Curve2d", (opencascade::handle<Geom2d_Curve> (ProjLib_ComputeApproxOnPolarSurface::*)() const) &ProjLib_ComputeApproxOnPolarSurface::Curve2d, "Returns second 2d curve.");
cls_ProjLib_ComputeApproxOnPolarSurface.def("IsDone", (Standard_Boolean (ProjLib_ComputeApproxOnPolarSurface::*)() const) &ProjLib_ComputeApproxOnPolarSurface::IsDone, "None");
cls_ProjLib_ComputeApproxOnPolarSurface.def("Tolerance", (Standard_Real (ProjLib_ComputeApproxOnPolarSurface::*)() const) &ProjLib_ComputeApproxOnPolarSurface::Tolerance, "returns the reached Tolerance.");

// Enums

}