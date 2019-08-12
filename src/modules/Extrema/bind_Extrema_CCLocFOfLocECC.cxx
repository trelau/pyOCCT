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
#include <Adaptor3d_Curve.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Extrema_POnCurv.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_SequenceOfPOnCurv.hxx>
#include <Extrema_CCLocFOfLocECC.hxx>

void bind_Extrema_CCLocFOfLocECC(py::module &mod){

py::class_<Extrema_CCLocFOfLocECC, std::unique_ptr<Extrema_CCLocFOfLocECC, Deleter<Extrema_CCLocFOfLocECC>>, math_FunctionSetWithDerivatives> cls_Extrema_CCLocFOfLocECC(mod, "Extrema_CCLocFOfLocECC", "None");

// Constructors
cls_Extrema_CCLocFOfLocECC.def(py::init<>());
cls_Extrema_CCLocFOfLocECC.def(py::init<const Standard_Real>(), py::arg("thetol"));
cls_Extrema_CCLocFOfLocECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &>(), py::arg("C1"), py::arg("C2"));
cls_Extrema_CCLocFOfLocECC.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("thetol"));

// Fields

// Methods
// cls_Extrema_CCLocFOfLocECC.def_static("operator new_", (void * (*)(size_t)) &Extrema_CCLocFOfLocECC::operator new, "None", py::arg("theSize"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator delete_", (void (*)(void *)) &Extrema_CCLocFOfLocECC::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_CCLocFOfLocECC::operator new[], "None", py::arg("theSize"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator delete[]_", (void (*)(void *)) &Extrema_CCLocFOfLocECC::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_CCLocFOfLocECC::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_CCLocFOfLocECC.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_CCLocFOfLocECC::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_CCLocFOfLocECC.def("SetCurve", (void (Extrema_CCLocFOfLocECC::*)(const Standard_Integer, const Adaptor3d_Curve &)) &Extrema_CCLocFOfLocECC::SetCurve, "None", py::arg("theRank"), py::arg("C1"));
cls_Extrema_CCLocFOfLocECC.def("SetTolerance", (void (Extrema_CCLocFOfLocECC::*)(const Standard_Real)) &Extrema_CCLocFOfLocECC::SetTolerance, "None", py::arg("theTol"));
cls_Extrema_CCLocFOfLocECC.def("NbVariables", (Standard_Integer (Extrema_CCLocFOfLocECC::*)() const) &Extrema_CCLocFOfLocECC::NbVariables, "None");
cls_Extrema_CCLocFOfLocECC.def("NbEquations", (Standard_Integer (Extrema_CCLocFOfLocECC::*)() const) &Extrema_CCLocFOfLocECC::NbEquations, "None");
cls_Extrema_CCLocFOfLocECC.def("Value", (Standard_Boolean (Extrema_CCLocFOfLocECC::*)(const math_Vector &, math_Vector &)) &Extrema_CCLocFOfLocECC::Value, "Calculate Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_CCLocFOfLocECC.def("Derivatives", (Standard_Boolean (Extrema_CCLocFOfLocECC::*)(const math_Vector &, math_Matrix &)) &Extrema_CCLocFOfLocECC::Derivatives, "Calculate Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_CCLocFOfLocECC.def("Values", (Standard_Boolean (Extrema_CCLocFOfLocECC::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_CCLocFOfLocECC::Values, "Calculate Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_CCLocFOfLocECC.def("GetStateNumber", (Standard_Integer (Extrema_CCLocFOfLocECC::*)()) &Extrema_CCLocFOfLocECC::GetStateNumber, "Save the found extremum.");
cls_Extrema_CCLocFOfLocECC.def("NbExt", (Standard_Integer (Extrema_CCLocFOfLocECC::*)() const) &Extrema_CCLocFOfLocECC::NbExt, "Return the number of found extrema.");
cls_Extrema_CCLocFOfLocECC.def("SquareDistance", (Standard_Real (Extrema_CCLocFOfLocECC::*)(const Standard_Integer) const) &Extrema_CCLocFOfLocECC::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_CCLocFOfLocECC.def("Points", (void (Extrema_CCLocFOfLocECC::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnCurv &) const) &Extrema_CCLocFOfLocECC::Points, "Return the points of the Nth extreme distance.", py::arg("N"), py::arg("P1"), py::arg("P2"));
cls_Extrema_CCLocFOfLocECC.def("CurvePtr", (Standard_Address (Extrema_CCLocFOfLocECC::*)(const Standard_Integer) const) &Extrema_CCLocFOfLocECC::CurvePtr, "Returns a pointer to the curve specified in the constructor or in SetCurve() method.", py::arg("theRank"));
cls_Extrema_CCLocFOfLocECC.def("Tolerance", (Standard_Real (Extrema_CCLocFOfLocECC::*)() const) &Extrema_CCLocFOfLocECC::Tolerance, "Returns a tolerance specified in the constructor or in SetTolerance() method.");
cls_Extrema_CCLocFOfLocECC.def("SubIntervalInitialize", (void (Extrema_CCLocFOfLocECC::*)(const math_Vector &, const math_Vector &)) &Extrema_CCLocFOfLocECC::SubIntervalInitialize, "Determines of boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_CCLocFOfLocECC.def("SearchOfTolerance", (Standard_Real (Extrema_CCLocFOfLocECC::*)(const Standard_Address)) &Extrema_CCLocFOfLocECC::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.", py::arg("C"));

// Enums

}