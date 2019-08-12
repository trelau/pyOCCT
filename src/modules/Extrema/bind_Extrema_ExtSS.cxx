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
#include <Adaptor3d_SurfacePtr.hxx>
#include <Extrema_ExtElSS.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <Extrema_ExtSS.hxx>

void bind_Extrema_ExtSS(py::module &mod){

py::class_<Extrema_ExtSS, std::unique_ptr<Extrema_ExtSS, Deleter<Extrema_ExtSS>>> cls_Extrema_ExtSS(mod, "Extrema_ExtSS", "It calculates all the extremum distances between two surfaces. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtSS.def(py::init<>());
cls_Extrema_ExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("TolS1"), py::arg("TolS2"));
cls_Extrema_ExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("Uinf1"), py::arg("Usup1"), py::arg("Vinf1"), py::arg("Vsup1"), py::arg("Uinf2"), py::arg("Usup2"), py::arg("Vinf2"), py::arg("Vsup2"), py::arg("TolS1"), py::arg("TolS2"));

// Fields

// Methods
// cls_Extrema_ExtSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtSS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtSS.def("Initialize", (void (Extrema_ExtSS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtSS::Initialize, "Initializes the fields of the algorithm.", py::arg("S2"), py::arg("Uinf2"), py::arg("Usup2"), py::arg("Vinf2"), py::arg("Vsup2"), py::arg("TolS1"));
cls_Extrema_ExtSS.def("Perform", (void (Extrema_ExtSS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtSS::Perform, "Computes the distances. An exception is raised if the fieds have not been initialized.", py::arg("S1"), py::arg("Uinf1"), py::arg("Usup1"), py::arg("Vinf1"), py::arg("Vsup1"), py::arg("TolS1"));
cls_Extrema_ExtSS.def("IsDone", (Standard_Boolean (Extrema_ExtSS::*)() const) &Extrema_ExtSS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtSS.def("IsParallel", (Standard_Boolean (Extrema_ExtSS::*)() const) &Extrema_ExtSS::IsParallel, "Returns True if the curve is on a parallel surface.");
cls_Extrema_ExtSS.def("NbExt", (Standard_Integer (Extrema_ExtSS::*)() const) &Extrema_ExtSS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtSS.def("SquareDistance", (Standard_Real (Extrema_ExtSS::*)(const Standard_Integer) const) &Extrema_ExtSS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtSS.def("Points", (void (Extrema_ExtSS::*)(const Standard_Integer, Extrema_POnSurf &, Extrema_POnSurf &) const) &Extrema_ExtSS::Points, "Returns the point of the Nth resulting distance.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// Enums

}