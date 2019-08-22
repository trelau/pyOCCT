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
#include <gp_Pnt2d.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.hxx>
#include <Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.hxx>

void bind_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter(py::module &mod){

py::class_<Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter> cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter(mod, "Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter", "None");

// Constructors
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def(py::init<>());
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolU"));
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));

// Fields

// Methods
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("Initialize", (void (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("Perform", (void (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)(const gp_Pnt2d &, const Standard_Real)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"), py::arg("U0"));
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("IsDone", (Standard_Boolean (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::IsDone, "Returns True if the distance is found.");
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("SquareDistance", (Standard_Real (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::SquareDistance, "Returns the value of the extremum square distance.");
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("IsMin", (Standard_Boolean (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::IsMin, "Returns True if the extremum distance is a minimum.");
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("Point", (const Extrema_POnCurv2d & (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::Point, "Returns the point of the extremum distance.");

// Enums

}