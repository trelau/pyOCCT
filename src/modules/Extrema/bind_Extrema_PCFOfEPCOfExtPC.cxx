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
#include <Extrema_PCFOfEPCOfExtPC.hxx>

void bind_Extrema_PCFOfEPCOfExtPC(py::module &mod){

py::class_<Extrema_PCFOfEPCOfExtPC, std::unique_ptr<Extrema_PCFOfEPCOfExtPC, Deleter<Extrema_PCFOfEPCOfExtPC>>, math_FunctionWithDerivative> cls_Extrema_PCFOfEPCOfExtPC(mod, "Extrema_PCFOfEPCOfExtPC", "None");

// Constructors
cls_Extrema_PCFOfEPCOfExtPC.def(py::init<>());
cls_Extrema_PCFOfEPCOfExtPC.def(py::init<const gp_Pnt &, const Adaptor3d_Curve &>(), py::arg("P"), py::arg("C"));

// Fields

// Methods
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator new_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfExtPC::operator new, "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator delete_", (void (*)(void *)) &Extrema_PCFOfEPCOfExtPC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfExtPC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_PCFOfEPCOfExtPC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_PCFOfEPCOfExtPC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_PCFOfEPCOfExtPC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_PCFOfEPCOfExtPC.def("Initialize", (void (Extrema_PCFOfEPCOfExtPC::*)(const Adaptor3d_Curve &)) &Extrema_PCFOfEPCOfExtPC::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Extrema_PCFOfEPCOfExtPC.def("SetPoint", (void (Extrema_PCFOfEPCOfExtPC::*)(const gp_Pnt &)) &Extrema_PCFOfEPCOfExtPC::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Extrema_PCFOfEPCOfExtPC.def("Value", [](Extrema_PCFOfEPCOfExtPC &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Extrema_PCFOfEPCOfExtPC.def("Derivative", [](Extrema_PCFOfEPCOfExtPC &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfExtPC.def("Values", [](Extrema_PCFOfEPCOfExtPC &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfExtPC.def("GetStateNumber", (Standard_Integer (Extrema_PCFOfEPCOfExtPC::*)()) &Extrema_PCFOfEPCOfExtPC::GetStateNumber, "Save the found extremum.");
cls_Extrema_PCFOfEPCOfExtPC.def("NbExt", (Standard_Integer (Extrema_PCFOfEPCOfExtPC::*)() const) &Extrema_PCFOfEPCOfExtPC::NbExt, "Return the nunber of found extrema.");
cls_Extrema_PCFOfEPCOfExtPC.def("SquareDistance", (Standard_Real (Extrema_PCFOfEPCOfExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC.def("IsMin", (Standard_Boolean (Extrema_PCFOfEPCOfExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC.def("Point", (const Extrema_POnCurv & (Extrema_PCFOfEPCOfExtPC::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC.def("SubIntervalInitialize", (void (Extrema_PCFOfEPCOfExtPC::*)(const Standard_Real, const Standard_Real)) &Extrema_PCFOfEPCOfExtPC::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_PCFOfEPCOfExtPC.def("SearchOfTolerance", (Standard_Real (Extrema_PCFOfEPCOfExtPC::*)()) &Extrema_PCFOfEPCOfExtPC::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// Enums

}