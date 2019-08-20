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
#include <Adaptor2d_Curve2d.hxx>
#include <IntRes2d_Domain.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.hxx>
#include <Geom2dInt_TheIntPCurvePCurveOfGInter.hxx>

void bind_Geom2dInt_TheIntPCurvePCurveOfGInter(py::module &mod){

py::class_<Geom2dInt_TheIntPCurvePCurveOfGInter, std::unique_ptr<Geom2dInt_TheIntPCurvePCurveOfGInter>, IntRes2d_Intersection> cls_Geom2dInt_TheIntPCurvePCurveOfGInter(mod, "Geom2dInt_TheIntPCurvePCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def(py::init<>());

// Fields

// Methods
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntPCurvePCurveOfGInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntPCurvePCurveOfGInter::Perform, "None", py::arg("Curve1"), py::arg("Domain1"), py::arg("Curve2"), py::arg("Domain2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntPCurvePCurveOfGInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntPCurvePCurveOfGInter::Perform, "None", py::arg("Curve1"), py::arg("Domain1"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def("SetMinNbSamples", (void (Geom2dInt_TheIntPCurvePCurveOfGInter::*)(const Standard_Integer)) &Geom2dInt_TheIntPCurvePCurveOfGInter::SetMinNbSamples, "Set / get minimum number of points in polygon for intersection.", py::arg("theMinNbSamples"));
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def("GetMinNbSamples", (Standard_Integer (Geom2dInt_TheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_TheIntPCurvePCurveOfGInter::GetMinNbSamples, "None");

// Enums

}