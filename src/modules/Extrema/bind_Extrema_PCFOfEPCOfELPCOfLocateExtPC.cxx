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
#include <gp_Pnt.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Extrema_SequenceOfPOnCurv.hxx>
#include <Extrema_PCFOfEPCOfELPCOfLocateExtPC.hxx>

void bind_Extrema_PCFOfEPCOfELPCOfLocateExtPC(py::module &mod){

py::class_<Extrema_PCFOfEPCOfELPCOfLocateExtPC, math_FunctionWithDerivative> cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC(mod, "Extrema_PCFOfEPCOfELPCOfLocateExtPC", "None");

// Constructors
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def(py::init<>());
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &>(), py::arg("P"), py::arg("C"));

// Fields

// Methods
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Initialize", (void (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Adaptor3d_Curve &)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("SetPoint", (void (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const gp_Pnt &)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Value", [](Extrema_PCFOfEPCOfELPCOfLocateExtPC &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Derivative", [](Extrema_PCFOfEPCOfELPCOfLocateExtPC &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Values", [](Extrema_PCFOfEPCOfELPCOfLocateExtPC &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("GetStateNumber", (Standard_Integer (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)()) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::GetStateNumber, "Save the found extremum.");
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("NbExt", (Standard_Integer (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)() const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::NbExt, "Return the nunber of found extrema.");
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("SquareDistance", (Standard_Real (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("IsMin", (Standard_Boolean (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("Point", (const Extrema_POnCurv & (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("SubIntervalInitialize", (void (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)(const Standard_Real, const Standard_Real)) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_PCFOfEPCOfELPCOfLocateExtPC.def("SearchOfTolerance", (Standard_Real (Extrema_PCFOfEPCOfELPCOfLocateExtPC::*)()) &Extrema_PCFOfEPCOfELPCOfLocateExtPC::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// Enums

}