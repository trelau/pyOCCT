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
#include <IntRes2d_Intersection.hxx>
#include <Standard.hxx>
#include <gp_Lin2d.hxx>
#include <IntRes2d_Domain.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <IntCurve_IntConicConic.hxx>
#include <HLRBRep_TheIntConicCurveOfCInter.hxx>
#include <HLRBRep_IntConicCurveOfCInter.hxx>

void bind_HLRBRep_IntConicCurveOfCInter(py::module &mod){

py::class_<HLRBRep_IntConicCurveOfCInter, std::unique_ptr<HLRBRep_IntConicCurveOfCInter, Deleter<HLRBRep_IntConicCurveOfCInter>>, IntRes2d_Intersection> cls_HLRBRep_IntConicCurveOfCInter(mod, "HLRBRep_IntConicCurveOfCInter", "None");

// Constructors
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<>());
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def(py::init<const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Fields

// Methods
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_IntConicCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_IntConicCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_IntConicCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_IntConicCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_IntConicCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_IntConicCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_IntConicCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Lin2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between a line and a parametric curve.", py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between a line and a parametric curve.", py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between an ellipse and a parametric curve.", py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between a parabola and a parametric curve.", py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_IntConicCurveOfCInter.def("Perform", (void (HLRBRep_IntConicCurveOfCInter::*)(const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_IntConicCurveOfCInter::Perform, "Intersection between the main branch of an hyperbola and a parametric curve.", py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Enums

}