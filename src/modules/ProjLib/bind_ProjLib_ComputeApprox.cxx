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
#include <AppParCurves_Constraint.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <ProjLib_ComputeApprox.hxx>

void bind_ProjLib_ComputeApprox(py::module &mod){

py::class_<ProjLib_ComputeApprox, std::unique_ptr<ProjLib_ComputeApprox>> cls_ProjLib_ComputeApprox(mod, "ProjLib_ComputeApprox", "Approximate the projection of a 3d curve on an analytic surface and stores the result in Approx. The result is a 2d curve. For approximation some parameters are used, including required tolerance of approximation. Tolerance is maximal possible value of 3d deviation of 3d projection of projected curve from 'exact' 3d projection. Since algorithm searches 2d curve on surface, required 2d tolerance is computed from 3d tolerance with help of U,V resolutions of surface. 3d and 2d tolerances have sence only for curves on surface, it defines precision of projecting and approximation and have nothing to do with distance between the projected curve and the surface.");

// Constructors
cls_ProjLib_ComputeApprox.def(py::init<>());
cls_ProjLib_ComputeApprox.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("Tol"));

// Fields

// Methods
// cls_ProjLib_ComputeApprox.def_static("operator new_", (void * (*)(size_t)) &ProjLib_ComputeApprox::operator new, "None", py::arg("theSize"));
// cls_ProjLib_ComputeApprox.def_static("operator delete_", (void (*)(void *)) &ProjLib_ComputeApprox::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_ComputeApprox.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_ComputeApprox::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_ComputeApprox.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_ComputeApprox::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_ComputeApprox.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_ComputeApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_ComputeApprox.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_ComputeApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_ComputeApprox.def("Perform", (void (ProjLib_ComputeApprox::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ComputeApprox::Perform, "Performs projecting. In case of approximation current values of parameters are used: default values or set by corresponding methods Set...", py::arg("C"), py::arg("S"));
cls_ProjLib_ComputeApprox.def("SetTolerance", (void (ProjLib_ComputeApprox::*)(const Standard_Real)) &ProjLib_ComputeApprox::SetTolerance, "Set tolerance of approximation. Default value is Precision::Confusion().", py::arg("theTolerance"));
cls_ProjLib_ComputeApprox.def("SetDegree", (void (ProjLib_ComputeApprox::*)(const Standard_Integer, const Standard_Integer)) &ProjLib_ComputeApprox::SetDegree, "Set min and max possible degree of result BSpline curve2d, which is got by approximation. If theDegMin/Max < 0, algorithm uses values that are chosen depending of types curve 3d and surface.", py::arg("theDegMin"), py::arg("theDegMax"));
cls_ProjLib_ComputeApprox.def("SetMaxSegments", (void (ProjLib_ComputeApprox::*)(const Standard_Integer)) &ProjLib_ComputeApprox::SetMaxSegments, "Set the parameter, which defines maximal value of parametric intervals the projected curve can be cut for approximation. If theMaxSegments < 0, algorithm uses default value = 1000.", py::arg("theMaxSegments"));
cls_ProjLib_ComputeApprox.def("SetBndPnt", (void (ProjLib_ComputeApprox::*)(const AppParCurves_Constraint)) &ProjLib_ComputeApprox::SetBndPnt, "Set the parameter, which defines type of boundary condition between segments during approximation. It can be AppParCurves_PassPoint or AppParCurves_TangencyPoint. Default value is AppParCurves_TangencyPoint;", py::arg("theBndPnt"));
cls_ProjLib_ComputeApprox.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ComputeApprox::*)() const) &ProjLib_ComputeApprox::BSpline, "None");
cls_ProjLib_ComputeApprox.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (ProjLib_ComputeApprox::*)() const) &ProjLib_ComputeApprox::Bezier, "None");
cls_ProjLib_ComputeApprox.def("Tolerance", (Standard_Real (ProjLib_ComputeApprox::*)() const) &ProjLib_ComputeApprox::Tolerance, "returns the reached Tolerance.");

// Enums

}