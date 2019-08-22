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
#include <Adaptor3d_Curve.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Extrema_POnCurv.hxx>
#include <Extrema_POnSurf.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <Adaptor3d_CurvePtr.hxx>
#include <gp_Pnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Extrema_SequenceOfPOnCurv.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <Extrema_FuncExtCS.hxx>

void bind_Extrema_FuncExtCS(py::module &mod){

py::class_<Extrema_FuncExtCS, math_FunctionSetWithDerivatives> cls_Extrema_FuncExtCS(mod, "Extrema_FuncExtCS", "Function to find extrema of the distance between a curve and a surface.");

// Constructors
cls_Extrema_FuncExtCS.def(py::init<>());
cls_Extrema_FuncExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &>(), py::arg("C"), py::arg("S"));

// Fields

// Methods
// cls_Extrema_FuncExtCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_FuncExtCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_FuncExtCS.def_static("operator delete_", (void (*)(void *)) &Extrema_FuncExtCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_FuncExtCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_FuncExtCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_FuncExtCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_FuncExtCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_FuncExtCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_FuncExtCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_FuncExtCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_FuncExtCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_FuncExtCS.def("Initialize", (void (Extrema_FuncExtCS::*)(const Adaptor3d_Curve &, const Adaptor3d_Surface &)) &Extrema_FuncExtCS::Initialize, "sets the field mysurf of the function.", py::arg("C"), py::arg("S"));
cls_Extrema_FuncExtCS.def("NbVariables", (Standard_Integer (Extrema_FuncExtCS::*)() const) &Extrema_FuncExtCS::NbVariables, "None");
cls_Extrema_FuncExtCS.def("NbEquations", (Standard_Integer (Extrema_FuncExtCS::*)() const) &Extrema_FuncExtCS::NbEquations, "None");
cls_Extrema_FuncExtCS.def("Value", (Standard_Boolean (Extrema_FuncExtCS::*)(const math_Vector &, math_Vector &)) &Extrema_FuncExtCS::Value, "Calculation of Fi(U,V).", py::arg("UV"), py::arg("F"));
cls_Extrema_FuncExtCS.def("Derivatives", (Standard_Boolean (Extrema_FuncExtCS::*)(const math_Vector &, math_Matrix &)) &Extrema_FuncExtCS::Derivatives, "Calculation of Fi'(U,V).", py::arg("UV"), py::arg("DF"));
cls_Extrema_FuncExtCS.def("Values", (Standard_Boolean (Extrema_FuncExtCS::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Extrema_FuncExtCS::Values, "Calculation of Fi(U,V) and Fi'(U,V).", py::arg("UV"), py::arg("F"), py::arg("DF"));
cls_Extrema_FuncExtCS.def("GetStateNumber", (Standard_Integer (Extrema_FuncExtCS::*)()) &Extrema_FuncExtCS::GetStateNumber, "Save the found extremum.");
cls_Extrema_FuncExtCS.def("NbExt", (Standard_Integer (Extrema_FuncExtCS::*)() const) &Extrema_FuncExtCS::NbExt, "Return the number of found extrema.");
cls_Extrema_FuncExtCS.def("SquareDistance", (Standard_Real (Extrema_FuncExtCS::*)(const Standard_Integer) const) &Extrema_FuncExtCS::SquareDistance, "Return the value of the Nth distance.", py::arg("N"));
cls_Extrema_FuncExtCS.def("PointOnCurve", (const Extrema_POnCurv & (Extrema_FuncExtCS::*)(const Standard_Integer) const) &Extrema_FuncExtCS::PointOnCurve, "Returns the Nth extremum on C.", py::arg("N"));
cls_Extrema_FuncExtCS.def("PointOnSurface", (const Extrema_POnSurf & (Extrema_FuncExtCS::*)(const Standard_Integer) const) &Extrema_FuncExtCS::PointOnSurface, "Return the Nth extremum on S.", py::arg("N"));

// Enums

}