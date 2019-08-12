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
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnSurf.hxx>
#include <Extrema_GenLocateExtSS.hxx>

void bind_Extrema_GenLocateExtSS(py::module &mod){

py::class_<Extrema_GenLocateExtSS, std::unique_ptr<Extrema_GenLocateExtSS, Deleter<Extrema_GenLocateExtSS>>> cls_Extrema_GenLocateExtSS(mod, "Extrema_GenLocateExtSS", "With two close points it calculates the distance between two surfaces. This distance can be a minimum or a maximum.");

// Constructors
cls_Extrema_GenLocateExtSS.def(py::init<>());
cls_Extrema_GenLocateExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Tol1"), py::arg("Tol2"));

// Fields

// Methods
// cls_Extrema_GenLocateExtSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenLocateExtSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtSS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenLocateExtSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenLocateExtSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenLocateExtSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenLocateExtSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenLocateExtSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenLocateExtSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenLocateExtSS.def("Perform", (void (Extrema_GenLocateExtSS::*)(const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenLocateExtSS::Perform, "None", py::arg("S1"), py::arg("S2"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Tol1"), py::arg("Tol2"));
cls_Extrema_GenLocateExtSS.def("IsDone", (Standard_Boolean (Extrema_GenLocateExtSS::*)() const) &Extrema_GenLocateExtSS::IsDone, "Returns True if the distance is found.");
cls_Extrema_GenLocateExtSS.def("SquareDistance", (Standard_Real (Extrema_GenLocateExtSS::*)() const) &Extrema_GenLocateExtSS::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_GenLocateExtSS.def("PointOnS1", (const Extrema_POnSurf & (Extrema_GenLocateExtSS::*)() const) &Extrema_GenLocateExtSS::PointOnS1, "Returns the point of the extremum distance on S1.");
cls_Extrema_GenLocateExtSS.def("PointOnS2", (const Extrema_POnSurf & (Extrema_GenLocateExtSS::*)() const) &Extrema_GenLocateExtSS::PointOnS2, "Returns the point of the extremum distance on S2.");

// Enums

}