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
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Extrema_SequenceOfPOnCurv2d.hxx>
#include <Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.hxx>

void bind_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter(py::module &mod){

py::class_<Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter, math_FunctionWithDerivative> cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter(mod, "Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter", "None");

// Constructors
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def(py::init<>());
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &>(), py::arg("P"), py::arg("C"));

// Fields

// Methods
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Initialize", (void (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Adaptor2d_Curve2d &)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("SetPoint", (void (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const gp_Pnt2d &)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Value", [](Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Derivative", [](Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Values", [](Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("GetStateNumber", (Standard_Integer (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)()) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::GetStateNumber, "Save the found extremum.");
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("NbExt", (Standard_Integer (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::NbExt, "Return the nunber of found extrema.");
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("SquareDistance", (Standard_Real (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Standard_Integer) const) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("IsMin", (Standard_Boolean (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Standard_Integer) const) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Point", (const Extrema_POnCurv2d & (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Standard_Integer) const) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("SubIntervalInitialize", (void (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Standard_Real, const Standard_Real)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("SearchOfTolerance", (Standard_Real (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)()) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// Enums

}