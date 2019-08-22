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
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Domain.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntCurve_IntConicConic.hxx>
#include <HLRBRep_TheIntConicCurveOfCInter.hxx>
#include <HLRBRep_TheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_CInter.hxx>

void bind_HLRBRep_CInter(py::module &mod){

py::class_<HLRBRep_CInter, IntRes2d_Intersection> cls_HLRBRep_CInter(mod, "HLRBRep_CInter", "None");

// Constructors
cls_HLRBRep_CInter.def(py::init<>());
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const Standard_Address &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def(py::init<const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Fields

// Methods
// cls_HLRBRep_CInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_CInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_CInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_CInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_CInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_CInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_CInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_CInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_CInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_CInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_CInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_CInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const Standard_Address &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("Perform", (void (HLRBRep_CInter::*)(const Standard_Address &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_CInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_CInter.def("ComputeDomain", (IntRes2d_Domain (HLRBRep_CInter::*)(const Standard_Address &, const Standard_Real) const) &HLRBRep_CInter::ComputeDomain, "Create a domain from a curve", py::arg("C1"), py::arg("TolDomain"));
cls_HLRBRep_CInter.def("SetMinNbSamples", (void (HLRBRep_CInter::*)(const Standard_Integer)) &HLRBRep_CInter::SetMinNbSamples, "Set / get minimum number of points in polygon intersection.", py::arg("theMinNbSamples"));
cls_HLRBRep_CInter.def("GetMinNbSamples", (Standard_Integer (HLRBRep_CInter::*)() const) &HLRBRep_CInter::GetMinNbSamples, "None");

// Enums

}