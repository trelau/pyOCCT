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
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <GeomFill_QuasiAngularConvertor.hxx>

void bind_GeomFill_QuasiAngularConvertor(py::module &mod){

py::class_<GeomFill_QuasiAngularConvertor, std::unique_ptr<GeomFill_QuasiAngularConvertor>> cls_GeomFill_QuasiAngularConvertor(mod, "GeomFill_QuasiAngularConvertor", "To convert circular section in QuasiAngular Bezier form");

// Constructors
cls_GeomFill_QuasiAngularConvertor.def(py::init<>());

// Fields

// Methods
// cls_GeomFill_QuasiAngularConvertor.def_static("operator new_", (void * (*)(size_t)) &GeomFill_QuasiAngularConvertor::operator new, "None", py::arg("theSize"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator delete_", (void (*)(void *)) &GeomFill_QuasiAngularConvertor::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_QuasiAngularConvertor::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_QuasiAngularConvertor::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_QuasiAngularConvertor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_QuasiAngularConvertor::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_QuasiAngularConvertor.def("Initialized", (Standard_Boolean (GeomFill_QuasiAngularConvertor::*)() const) &GeomFill_QuasiAngularConvertor::Initialized, "say if <me> is Initialized");
cls_GeomFill_QuasiAngularConvertor.def("Init", (void (GeomFill_QuasiAngularConvertor::*)()) &GeomFill_QuasiAngularConvertor::Init, "None");
cls_GeomFill_QuasiAngularConvertor.def("Section", (void (GeomFill_QuasiAngularConvertor::*)(const gp_Pnt &, const gp_Pnt &, const gp_Vec &, const Standard_Real, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &GeomFill_QuasiAngularConvertor::Section, "None", py::arg("FirstPnt"), py::arg("Center"), py::arg("Dir"), py::arg("Angle"), py::arg("Poles"), py::arg("Weights"));
cls_GeomFill_QuasiAngularConvertor.def("Section", (void (GeomFill_QuasiAngularConvertor::*)(const gp_Pnt &, const gp_Vec &, const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_QuasiAngularConvertor::Section, "None", py::arg("FirstPnt"), py::arg("DFirstPnt"), py::arg("Center"), py::arg("DCenter"), py::arg("Dir"), py::arg("DDir"), py::arg("Angle"), py::arg("DAngle"), py::arg("Poles"), py::arg("DPoles"), py::arg("Weights"), py::arg("DWeights"));
cls_GeomFill_QuasiAngularConvertor.def("Section", (void (GeomFill_QuasiAngularConvertor::*)(const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_QuasiAngularConvertor::Section, "None", py::arg("FirstPnt"), py::arg("DFirstPnt"), py::arg("D2FirstPnt"), py::arg("Center"), py::arg("DCenter"), py::arg("D2Center"), py::arg("Dir"), py::arg("DDir"), py::arg("D2Dir"), py::arg("Angle"), py::arg("DAngle"), py::arg("D2Angle"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Weights"), py::arg("DWeights"), py::arg("D2Weights"));

// Enums

}