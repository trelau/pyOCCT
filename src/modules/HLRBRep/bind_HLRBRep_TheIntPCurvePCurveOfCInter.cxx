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
#include <HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter.hxx>
#include <HLRBRep_TheIntPCurvePCurveOfCInter.hxx>

void bind_HLRBRep_TheIntPCurvePCurveOfCInter(py::module &mod){

py::class_<HLRBRep_TheIntPCurvePCurveOfCInter, std::unique_ptr<HLRBRep_TheIntPCurvePCurveOfCInter>, IntRes2d_Intersection> cls_HLRBRep_TheIntPCurvePCurveOfCInter(mod, "HLRBRep_TheIntPCurvePCurveOfCInter", "None");

// Constructors
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def(py::init<>());

// Fields

// Methods
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheIntPCurvePCurveOfCInter.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheIntPCurvePCurveOfCInter::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def("Perform", (void (HLRBRep_TheIntPCurvePCurveOfCInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntPCurvePCurveOfCInter::Perform, "None", py::arg("Curve1"), py::arg("Domain1"), py::arg("Curve2"), py::arg("Domain2"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def("Perform", (void (HLRBRep_TheIntPCurvePCurveOfCInter::*)(const Standard_Address &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &HLRBRep_TheIntPCurvePCurveOfCInter::Perform, "None", py::arg("Curve1"), py::arg("Domain1"), py::arg("TolConf"), py::arg("Tol"));
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def("SetMinNbSamples", (void (HLRBRep_TheIntPCurvePCurveOfCInter::*)(const Standard_Integer)) &HLRBRep_TheIntPCurvePCurveOfCInter::SetMinNbSamples, "Set / get minimum number of points in polygon for intersection.", py::arg("theMinNbSamples"));
cls_HLRBRep_TheIntPCurvePCurveOfCInter.def("GetMinNbSamples", (Standard_Integer (HLRBRep_TheIntPCurvePCurveOfCInter::*)() const) &HLRBRep_TheIntPCurvePCurveOfCInter::GetMinNbSamples, "None");

// Enums

}