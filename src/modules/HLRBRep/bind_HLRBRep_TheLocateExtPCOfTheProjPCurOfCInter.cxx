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
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.hxx>
#include <HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.hxx>

void bind_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter(py::module &mod){

py::class_<HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter, std::unique_ptr<HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter>> cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter(mod, "HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter", "None");

// Constructors
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def(py::init<>());
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def(py::init<const gp_Pnt2d &, const Standard_Address &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolU"));
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def(py::init<const gp_Pnt2d &, const Standard_Address &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));

// Fields

// Methods
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("Initialize", (void (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Address &, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("Perform", (void (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)(const gp_Pnt2d &, const Standard_Real)) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"), py::arg("U0"));
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("IsDone", (Standard_Boolean (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::IsDone, "Returns True if the distance is found.");
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("SquareDistance", (Standard_Real (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::SquareDistance, "Returns the value of the extremum square distance.");
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("IsMin", (Standard_Boolean (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::IsMin, "Returns True if the extremum distance is a minimum.");
cls_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter.def("Point", (const Extrema_POnCurv2d & (HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter::Point, "Returns the point of the extremum distance.");

// Enums

}