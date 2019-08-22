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
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.hxx>

void bind_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter(py::module &mod){

py::class_<HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter, math_FunctionSetWithDerivatives> cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter(mod, "HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter", "None");

// Constructors
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def(py::init<const Standard_Address &, const Standard_Address &>(), py::arg("curve1"), py::arg("curve2"));

// Fields

// Methods
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("NbVariables", (Standard_Integer (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::NbVariables, "returns 2.");
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("NbEquations", (Standard_Integer (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::NbEquations, "returns 2.");
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("Value", (Standard_Boolean (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)(const math_Vector &, math_Vector &)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::Value, "computes the values <F> of the Functions for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("Derivatives", (Standard_Boolean (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)(const math_Vector &, math_Matrix &)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::Derivatives, "returns the values <D> of the derivatives for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.def("Values", (Standard_Boolean (HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::*)(const math_Vector &, math_Vector &, math_Matrix &)) &HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}