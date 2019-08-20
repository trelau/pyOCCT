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
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Domain.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntCurve_IntConicConic.hxx>
#include <Geom2dInt_TheIntConicCurveOfGInter.hxx>
#include <Geom2dInt_TheIntPCurvePCurveOfGInter.hxx>
#include <Geom2dInt_GInter.hxx>

void bind_Geom2dInt_GInter(py::module &mod){

py::class_<Geom2dInt_GInter, std::unique_ptr<Geom2dInt_GInter>, IntRes2d_Intersection> cls_Geom2dInt_GInter(mod, "Geom2dInt_GInter", "None");

// Constructors
cls_Geom2dInt_GInter.def(py::init<>());
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Fields

// Methods
// cls_Geom2dInt_GInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_GInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_GInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_GInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_GInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_GInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_GInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_GInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_GInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_GInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_GInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_GInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("ComputeDomain", (IntRes2d_Domain (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const Standard_Real) const) &Geom2dInt_GInter::ComputeDomain, "Create a domain from a curve", py::arg("C1"), py::arg("TolDomain"));
cls_Geom2dInt_GInter.def("SetMinNbSamples", (void (Geom2dInt_GInter::*)(const Standard_Integer)) &Geom2dInt_GInter::SetMinNbSamples, "Set / get minimum number of points in polygon intersection.", py::arg("theMinNbSamples"));
cls_Geom2dInt_GInter.def("GetMinNbSamples", (Standard_Integer (Geom2dInt_GInter::*)() const) &Geom2dInt_GInter::GetMinNbSamples, "None");

// Enums

}