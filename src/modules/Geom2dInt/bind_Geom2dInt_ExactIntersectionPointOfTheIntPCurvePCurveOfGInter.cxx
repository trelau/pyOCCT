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
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.hxx>
#include <Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.hxx>
#include <math_Vector.hxx>
#include <Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.hxx>

void bind_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter(py::module &mod){

py::class_<Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter, std::unique_ptr<Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter, Deleter<Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter>>> cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter(mod, "Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Tol"));

// Fields

// Methods
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("Perform", [](Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter &self, const Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter & Poly1, const Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter & Poly2, Standard_Integer & NumSegOn1, Standard_Integer & NumSegOn2, Standard_Real & ParamOnSeg1, Standard_Real & ParamOnSeg2){ self.Perform(Poly1, Poly2, NumSegOn1, NumSegOn2, ParamOnSeg1, ParamOnSeg2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &, Standard_Real &>(NumSegOn1, NumSegOn2, ParamOnSeg1, ParamOnSeg2); }, "None", py::arg("Poly1"), py::arg("Poly2"), py::arg("NumSegOn1"), py::arg("NumSegOn2"), py::arg("ParamOnSeg1"), py::arg("ParamOnSeg2"));
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("Perform", (void (Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::Perform, "None", py::arg("Uo"), py::arg("Vo"), py::arg("UInf"), py::arg("VInf"), py::arg("USup"), py::arg("VSup"));
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("NbRoots", (Standard_Integer (Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::NbRoots, "None");
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("Roots", [](Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter &self, Standard_Real & U, Standard_Real & V){ self.Roots(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("AnErrorOccurred", (Standard_Boolean (Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::AnErrorOccurred, "None");

// Enums

}