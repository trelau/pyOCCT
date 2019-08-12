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
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_SequenceOfPOnCurv2d.hxx>
#include <Extrema_CCLocFOfLocECC2d.hxx>

void bind_Extrema_CCLocFOfLocECC2d(py::module &mod){

py::class_<Extrema_CCLocFOfLocECC2d, std::unique_ptr<Extrema_CCLocFOfLocECC2d, Deleter<Extrema_CCLocFOfLocECC2d>>, math_FunctionSetWithDerivatives> cls_Extrema_CCLocFOfLocECC2d(mod, "Extrema_CCLocFOfLocECC2d", "None");

// Constructors
cls_Extrema_CCLocFOfLocECC2d.def(py::init<>());
cls_Extrema_CCLocFOfLocECC2d.def(py::init<const Standard_Real>(), py::arg("thetol"));
cls_Extrema_CCLocFOfLocECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_CCLocFOfLocECC2d.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("thetol"));

// Fields

// Methods
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_CCLocFOfLocECC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_CCLocFOfLocECC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_CCLocFOfLocECC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_CCLocFOfLocECC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_CCLocFOfLocECC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_CCLocFOfLocECC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_CCLocFOfLocECC2d.def("SetCurve", (void (Extrema_CCLocFOfLocECC2d::*)(const Standard_Integer, const Adaptor2d_Curve2d &)) &Extrema_CCLocFOfLocECC2d::SetCurve, "None", py::arg("theRank"), py::arg("C1"));
cls_Extrema_CCLocFOfLocECC2d.def("SetTolerance", (void (Extrema_CCLocFOfLocECC2d::*)(const Standard_Real)) &Extrema_CCLocFOfLocECC2d::SetTolerance, "None", py::arg("theTol"));
cls_Extrema_CCLocFOfLocECC2d.def("NbVariables", (Standard_Integer (Extrema_CCLocFOfLocECC2d::*)() const) &Extrema_CCLocFOfLocECC2d::NbVariables, "None");
cls_Extrema_CCLocFOfLocECC2d.def("NbEquations", (Standard_Integer (Extrema_CCLocFOfLocECC2d::*)() const) &Extrema_CCLocFOfLocECC2d::NbEquations, "None");
cls_Extrema_CCLocFOfLocECC2d.def("Value", (Standard_Boolean (Extrema_CCLocFOfLocECC2d::*)(const math_Vector &, math_Vector &)) &Extrema_CCLocFOfLocECC2d::Value, "Calculate Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_CCLocFOfLocECC2d.def("Derivatives", (Standard_Boolean (Extrema_CCLocFOfLocECC2d::*)(const math_Vector &, math_Matrix &)) &Extrema_CCLocFOfLocECC2d::Derivatives, "Calculate Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_CCLocFOfLocECC2d.def("Values", (Standard_Boolean (Extrema_CCLocFOfLocECC2d::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_CCLocFOfLocECC2d::Values, "Calculate Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_CCLocFOfLocECC2d.def("GetStateNumber", (Standard_Integer (Extrema_CCLocFOfLocECC2d::*)()) &Extrema_CCLocFOfLocECC2d::GetStateNumber, "Save the found extremum.");
cls_Extrema_CCLocFOfLocECC2d.def("NbExt", (Standard_Integer (Extrema_CCLocFOfLocECC2d::*)() const) &Extrema_CCLocFOfLocECC2d::NbExt, "Return the number of found extrema.");
cls_Extrema_CCLocFOfLocECC2d.def("SquareDistance", (Standard_Real (Extrema_CCLocFOfLocECC2d::*)(const Standard_Integer) const) &Extrema_CCLocFOfLocECC2d::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_CCLocFOfLocECC2d.def("Points", (void (Extrema_CCLocFOfLocECC2d::*)(const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &) const) &Extrema_CCLocFOfLocECC2d::Points, "Return the points of the Nth extreme distance.", py::arg("N"), py::arg("P1"), py::arg("P2"));
cls_Extrema_CCLocFOfLocECC2d.def("CurvePtr", (Standard_Address (Extrema_CCLocFOfLocECC2d::*)(const Standard_Integer) const) &Extrema_CCLocFOfLocECC2d::CurvePtr, "Returns a pointer to the curve specified in the constructor or in SetCurve() method.", py::arg("theRank"));
cls_Extrema_CCLocFOfLocECC2d.def("Tolerance", (Standard_Real (Extrema_CCLocFOfLocECC2d::*)() const) &Extrema_CCLocFOfLocECC2d::Tolerance, "Returns a tolerance specified in the constructor or in SetTolerance() method.");
cls_Extrema_CCLocFOfLocECC2d.def("SubIntervalInitialize", (void (Extrema_CCLocFOfLocECC2d::*)(const math_Vector &, const math_Vector &)) &Extrema_CCLocFOfLocECC2d::SubIntervalInitialize, "Determines of boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_CCLocFOfLocECC2d.def("SearchOfTolerance", (Standard_Real (Extrema_CCLocFOfLocECC2d::*)(const Standard_Address)) &Extrema_CCLocFOfLocECC2d::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.", py::arg("C"));

// Enums

}