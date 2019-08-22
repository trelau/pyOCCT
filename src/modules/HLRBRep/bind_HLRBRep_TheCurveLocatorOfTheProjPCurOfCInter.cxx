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
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.hxx>

void bind_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter(py::module &mod){

py::class_<HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter> cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter(mod, "HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter", "None");

// Constructors

// Fields

// Methods
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("Locate_", (void (*)(const gp_Pnt2d &, const Standard_Address &, const Standard_Integer, Extrema_POnCurv2d &)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::Locate, "Among a set of points {C(ui),i=1,NbU}, locate the point P=C(uj) such that: distance(P,C) = Min{distance(P,C(ui))}", py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Papp"));
cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("Locate_", (void (*)(const gp_Pnt2d &, const Standard_Address &, const Standard_Integer, const Standard_Real, const Standard_Real, Extrema_POnCurv2d &)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::Locate, "Among a set of points {C(ui),i=1,NbU}, locate the point P=C(uj) such that: distance(P,C) = Min{distance(P,C(ui))} The research is done between umin and usup.", py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("Papp"));
// cls_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter.def_static("Locate_", (void (*)(const Standard_Address &, const Standard_Address &, const Standard_Integer, const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &)) &HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter::Locate, "Among two sets of points {C1(ui),i=1,NbU} and {C2(vj),j=1,NbV}, locate the two points P1=C1(uk) and P2=C2(vl) such that: distance(P1,P2) = Min {distance(C1(ui),C2(vj))}.", py::arg("C1"), py::arg("C2"), py::arg("NbU"), py::arg("NbV"), py::arg("Papp1"), py::arg("Papp2"));

// Enums

}