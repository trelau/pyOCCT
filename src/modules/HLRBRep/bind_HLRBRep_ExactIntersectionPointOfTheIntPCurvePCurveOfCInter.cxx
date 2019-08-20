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
#include <Standard_TypeDef.hxx>
#include <HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter.hxx>
#include <math_Vector.hxx>
#include <HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.hxx>

void bind_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter(py::module &mod){

py::class_<HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter, std::unique_ptr<HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter>> cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter(mod, "HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter", "None");

// Constructors
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def(py::init<const Standard_Address &, const Standard_Address &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Tol"));

// Fields

// Methods
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("Perform", [](HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter &self, const HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter & Poly1, const HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter & Poly2, Standard_Integer & NumSegOn1, Standard_Integer & NumSegOn2, Standard_Real & ParamOnSeg1, Standard_Real & ParamOnSeg2){ self.Perform(Poly1, Poly2, NumSegOn1, NumSegOn2, ParamOnSeg1, ParamOnSeg2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &, Standard_Real &>(NumSegOn1, NumSegOn2, ParamOnSeg1, ParamOnSeg2); }, "None", py::arg("Poly1"), py::arg("Poly2"), py::arg("NumSegOn1"), py::arg("NumSegOn2"), py::arg("ParamOnSeg1"), py::arg("ParamOnSeg2"));
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("Perform", (void (HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::Perform, "None", py::arg("Uo"), py::arg("Vo"), py::arg("UInf"), py::arg("VInf"), py::arg("USup"), py::arg("VSup"));
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("NbRoots", (Standard_Integer (HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::NbRoots, "None");
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("Roots", [](HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter &self, Standard_Real & U, Standard_Real & V){ self.Roots(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter.def("AnErrorOccurred", (Standard_Boolean (HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter::AnErrorOccurred, "None");

// Enums

}