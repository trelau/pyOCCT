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
#include <gp_Pnt2d.hxx>
#include <Bisector_PointOnBis.hxx>

void bind_Bisector_PointOnBis(py::module &mod){

py::class_<Bisector_PointOnBis> cls_Bisector_PointOnBis(mod, "Bisector_PointOnBis", "None");

// Constructors
cls_Bisector_PointOnBis.def(py::init<>());
cls_Bisector_PointOnBis.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt2d &>(), py::arg("Param1"), py::arg("Param2"), py::arg("ParamBis"), py::arg("Distance"), py::arg("Point"));

// Fields

// Methods
// cls_Bisector_PointOnBis.def_static("operator new_", (void * (*)(size_t)) &Bisector_PointOnBis::operator new, "None", py::arg("theSize"));
// cls_Bisector_PointOnBis.def_static("operator delete_", (void (*)(void *)) &Bisector_PointOnBis::operator delete, "None", py::arg("theAddress"));
// cls_Bisector_PointOnBis.def_static("operator new[]_", (void * (*)(size_t)) &Bisector_PointOnBis::operator new[], "None", py::arg("theSize"));
// cls_Bisector_PointOnBis.def_static("operator delete[]_", (void (*)(void *)) &Bisector_PointOnBis::operator delete[], "None", py::arg("theAddress"));
// cls_Bisector_PointOnBis.def_static("operator new_", (void * (*)(size_t, void *)) &Bisector_PointOnBis::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bisector_PointOnBis.def_static("operator delete_", (void (*)(void *, void *)) &Bisector_PointOnBis::operator delete, "None", py::arg(""), py::arg(""));
cls_Bisector_PointOnBis.def("ParamOnC1", (void (Bisector_PointOnBis::*)(const Standard_Real)) &Bisector_PointOnBis::ParamOnC1, "None", py::arg("Param"));
cls_Bisector_PointOnBis.def("ParamOnC2", (void (Bisector_PointOnBis::*)(const Standard_Real)) &Bisector_PointOnBis::ParamOnC2, "None", py::arg("Param"));
cls_Bisector_PointOnBis.def("ParamOnBis", (void (Bisector_PointOnBis::*)(const Standard_Real)) &Bisector_PointOnBis::ParamOnBis, "None", py::arg("Param"));
cls_Bisector_PointOnBis.def("Distance", (void (Bisector_PointOnBis::*)(const Standard_Real)) &Bisector_PointOnBis::Distance, "None", py::arg("Distance"));
cls_Bisector_PointOnBis.def("IsInfinite", (void (Bisector_PointOnBis::*)(const Standard_Boolean)) &Bisector_PointOnBis::IsInfinite, "None", py::arg("Infinite"));
cls_Bisector_PointOnBis.def("Point", (void (Bisector_PointOnBis::*)(const gp_Pnt2d &)) &Bisector_PointOnBis::Point, "None", py::arg("P"));
cls_Bisector_PointOnBis.def("ParamOnC1", (Standard_Real (Bisector_PointOnBis::*)() const) &Bisector_PointOnBis::ParamOnC1, "None");
cls_Bisector_PointOnBis.def("ParamOnC2", (Standard_Real (Bisector_PointOnBis::*)() const) &Bisector_PointOnBis::ParamOnC2, "None");
cls_Bisector_PointOnBis.def("ParamOnBis", (Standard_Real (Bisector_PointOnBis::*)() const) &Bisector_PointOnBis::ParamOnBis, "None");
cls_Bisector_PointOnBis.def("Distance", (Standard_Real (Bisector_PointOnBis::*)() const) &Bisector_PointOnBis::Distance, "None");
cls_Bisector_PointOnBis.def("Point", (gp_Pnt2d (Bisector_PointOnBis::*)() const) &Bisector_PointOnBis::Point, "None");
cls_Bisector_PointOnBis.def("IsInfinite", (Standard_Boolean (Bisector_PointOnBis::*)() const) &Bisector_PointOnBis::IsInfinite, "None");
cls_Bisector_PointOnBis.def("Dump", (void (Bisector_PointOnBis::*)() const) &Bisector_PointOnBis::Dump, "None");

// Enums

}