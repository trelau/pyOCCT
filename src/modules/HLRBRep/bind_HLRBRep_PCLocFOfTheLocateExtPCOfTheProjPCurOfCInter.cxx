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
#include <math_FunctionWithDerivative.hxx>
#include <Standard.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Extrema_SequenceOfPOnCurv2d.hxx>
#include <HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.hxx>

void bind_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter(py::module &mod){

py::class_<HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter, math_FunctionWithDerivative> cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter(mod, "HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter", "None");

// Constructors
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def(py::init<>());
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def(py::init<const gp_Pnt2d &, const Standard_Address &>(), py::arg("P"), py::arg("C"));

// Fields

// Methods
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Initialize", (void (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Address &)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("SetPoint", (void (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const gp_Pnt2d &)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Value", [](HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Derivative", [](HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Values", [](HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("GetStateNumber", (Standard_Integer (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)()) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::GetStateNumber, "Save the found extremum.");
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("NbExt", (Standard_Integer (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)() const) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::NbExt, "Return the nunber of found extrema.");
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("SquareDistance", (Standard_Real (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Integer) const) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("IsMin", (Standard_Boolean (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Integer) const) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("Point", (const Extrema_POnCurv2d & (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Integer) const) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::Point, "Returns the Nth extremum.", py::arg("N"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("SubIntervalInitialize", (void (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)(const Standard_Real, const Standard_Real)) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter.def("SearchOfTolerance", (Standard_Real (HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::*)()) &HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// Enums

}