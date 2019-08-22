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
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Bisector_Curve.hxx>
#include <Bisector_BisecAna.hxx>
#include <Bisector_BisecPC.hxx>
#include <Bisector_BisecCC.hxx>
#include <Bisector_Bisec.hxx>
#include <Bisector_Inter.hxx>
#include <Bisector_PointOnBis.hxx>
#include <Bisector_PolyBis.hxx>
#include <Bisector_FunctionH.hxx>
#include <Bisector_FunctionInter.hxx>
#include <Bisector.hxx>

void bind_Bisector(py::module &mod){

py::class_<Bisector> cls_Bisector(mod, "Bisector", "This package provides the bisecting line between two geometric elements.");

// Constructors

// Fields

// Methods
// cls_Bisector.def_static("operator new_", (void * (*)(size_t)) &Bisector::operator new, "None", py::arg("theSize"));
// cls_Bisector.def_static("operator delete_", (void (*)(void *)) &Bisector::operator delete, "None", py::arg("theAddress"));
// cls_Bisector.def_static("operator new[]_", (void * (*)(size_t)) &Bisector::operator new[], "None", py::arg("theSize"));
// cls_Bisector.def_static("operator delete[]_", (void (*)(void *)) &Bisector::operator delete[], "None", py::arg("theAddress"));
// cls_Bisector.def_static("operator new_", (void * (*)(size_t, void *)) &Bisector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bisector.def_static("operator delete_", (void (*)(void *, void *)) &Bisector::operator delete, "None", py::arg(""), py::arg(""));
cls_Bisector.def_static("IsConvex_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real)) &Bisector::IsConvex, "None", py::arg("Cu"), py::arg("Sign"));

// Enums

}