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
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.hxx>

void bind_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter(py::module &mod){

py::class_<Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter, std::unique_ptr<Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter, Deleter<Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter>>, math_FunctionSetWithDerivatives> cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter(mod, "Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("curve1"), py::arg("curve2"));

// Fields

// Methods
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("NbVariables", (Standard_Integer (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::NbVariables, "returns 2.");
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("NbEquations", (Standard_Integer (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::NbEquations, "returns 2.");
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("Value", (Standard_Boolean (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)(const math_Vector &, math_Vector &)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::Value, "computes the values <F> of the Functions for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("Derivatives", (Standard_Boolean (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)(const math_Vector &, math_Matrix &)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::Derivatives, "returns the values <D> of the derivatives for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("Values", (Standard_Boolean (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}