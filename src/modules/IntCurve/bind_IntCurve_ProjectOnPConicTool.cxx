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
#include <IntCurve_PConic.hxx>
#include <gp_Pnt2d.hxx>
#include <IntCurve_ProjectOnPConicTool.hxx>

void bind_IntCurve_ProjectOnPConicTool(py::module &mod){

py::class_<IntCurve_ProjectOnPConicTool, std::unique_ptr<IntCurve_ProjectOnPConicTool, Deleter<IntCurve_ProjectOnPConicTool>>> cls_IntCurve_ProjectOnPConicTool(mod, "IntCurve_ProjectOnPConicTool", "This class provides a tool which computes the parameter of a point near a parametric conic.");

// Constructors

// Fields

// Methods
// cls_IntCurve_ProjectOnPConicTool.def_static("operator new_", (void * (*)(size_t)) &IntCurve_ProjectOnPConicTool::operator new, "None", py::arg("theSize"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator delete_", (void (*)(void *)) &IntCurve_ProjectOnPConicTool::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_ProjectOnPConicTool::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_ProjectOnPConicTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_ProjectOnPConicTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_ProjectOnPConicTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_ProjectOnPConicTool.def_static("FindParameter_", (Standard_Real (*)(const IntCurve_PConic &, const gp_Pnt2d &, const Standard_Real)) &IntCurve_ProjectOnPConicTool::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. In that case, no bounds are given. The research of the rigth parameter has to be made on the natural parametric domain of the curve.", py::arg("C"), py::arg("Pnt"), py::arg("Tol"));
cls_IntCurve_ProjectOnPConicTool.def_static("FindParameter_", (Standard_Real (*)(const IntCurve_PConic &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &IntCurve_ProjectOnPConicTool::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. LowParameter and HighParameter give the boundaries of the interval in wich the parameter certainly lies. These parameters are given to implement a more efficient algoritm. So, it is not necessary to check that the returned value verifies LowParameter <= Value <= HighParameter.", py::arg("C"), py::arg("Pnt"), py::arg("LowParameter"), py::arg("HighParameter"), py::arg("Tol"));

// Enums

}