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
#include <Extrema_POnCurv.hxx>
#include <Extrema_POnSurf.hxx>
#include <Extrema_GenLocateExtCS.hxx>

void bind_Extrema_GenLocateExtCS(py::module &mod){

py::class_<Extrema_GenLocateExtCS, std::unique_ptr<Extrema_GenLocateExtCS, Deleter<Extrema_GenLocateExtCS>>> cls_Extrema_GenLocateExtCS(mod, "Extrema_GenLocateExtCS", "With two close points it calculates the distance between two surfaces. This distance can be a minimum or a maximum.");

// Constructors
cls_Extrema_GenLocateExtCS.def(py::init<>());
cls_Extrema_GenLocateExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("T"), py::arg("U"), py::arg("V"), py::arg("Tol1"), py::arg("Tol2"));

// Fields

// Methods
// cls_Extrema_GenLocateExtCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenLocateExtCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtCS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenLocateExtCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenLocateExtCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenLocateExtCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenLocateExtCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenLocateExtCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenLocateExtCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenLocateExtCS.def("Perform", (void (Extrema_GenLocateExtCS::*)(const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenLocateExtCS::Perform, "None", py::arg("C"), py::arg("S"), py::arg("T"), py::arg("U"), py::arg("V"), py::arg("Tol1"), py::arg("Tol2"));
cls_Extrema_GenLocateExtCS.def("IsDone", (Standard_Boolean (Extrema_GenLocateExtCS::*)() const) &Extrema_GenLocateExtCS::IsDone, "Returns True if the distance is found.");
cls_Extrema_GenLocateExtCS.def("SquareDistance", (Standard_Real (Extrema_GenLocateExtCS::*)() const) &Extrema_GenLocateExtCS::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_GenLocateExtCS.def("PointOnCurve", (const Extrema_POnCurv & (Extrema_GenLocateExtCS::*)() const) &Extrema_GenLocateExtCS::PointOnCurve, "Returns the point of the extremum distance on C.");
cls_Extrema_GenLocateExtCS.def("PointOnSurface", (const Extrema_POnSurf & (Extrema_GenLocateExtCS::*)() const) &Extrema_GenLocateExtCS::PointOnSurface, "Returns the point of the extremum distance on S.");

// Enums

}