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
#include <Adaptor3d_Curve.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Adaptor3d_CurvePtr.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <ProjLib_PrjResolve.hxx>

void bind_ProjLib_PrjResolve(py::module &mod){

py::class_<ProjLib_PrjResolve> cls_ProjLib_PrjResolve(mod, "ProjLib_PrjResolve", "None");

// Constructors
cls_ProjLib_PrjResolve.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Integer>(), py::arg("C"), py::arg("S"), py::arg("Fix"));

// Fields

// Methods
// cls_ProjLib_PrjResolve.def_static("operator new_", (void * (*)(size_t)) &ProjLib_PrjResolve::operator new, "None", py::arg("theSize"));
// cls_ProjLib_PrjResolve.def_static("operator delete_", (void (*)(void *)) &ProjLib_PrjResolve::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_PrjResolve.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_PrjResolve::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_PrjResolve.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_PrjResolve::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_PrjResolve.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_PrjResolve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_PrjResolve.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_PrjResolve::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_PrjResolve.def("Perform", [](ProjLib_PrjResolve &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const gp_Pnt2d & a3, const gp_Pnt2d & a4, const gp_Pnt2d & a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); });
cls_ProjLib_PrjResolve.def("Perform", [](ProjLib_PrjResolve &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const gp_Pnt2d & a3, const gp_Pnt2d & a4, const gp_Pnt2d & a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_ProjLib_PrjResolve.def("Perform", (void (ProjLib_PrjResolve::*)(const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &ProjLib_PrjResolve::Perform, "Calculates the ort from C(t) to S with a close point. The close point is defined by the parameter values U0 and V0. The function F(u,v)=distance(S(u,v),C(t)) has an extremum when gradient(F)=0. The algorithm searchs a zero near the close point.", py::arg("t"), py::arg("U"), py::arg("V"), py::arg("Tol"), py::arg("Inf"), py::arg("Sup"), py::arg("FTol"), py::arg("StrictInside"));
cls_ProjLib_PrjResolve.def("IsDone", (Standard_Boolean (ProjLib_PrjResolve::*)() const) &ProjLib_PrjResolve::IsDone, "Returns True if the distance is found.");
cls_ProjLib_PrjResolve.def("Solution", (gp_Pnt2d (ProjLib_PrjResolve::*)() const) &ProjLib_PrjResolve::Solution, "Returns the point of the extremum distance.");

// Enums

}