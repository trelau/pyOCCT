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
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <CSLib_Class2d.hxx>

void bind_CSLib_Class2d(py::module &mod){

py::class_<CSLib_Class2d> cls_CSLib_Class2d(mod, "CSLib_Class2d", "*** Class2d : Low level algorithm for 2d classification this class was moved from package BRepTopAdaptor");

// Constructors
cls_CSLib_Class2d.def(py::init<const TColgp_Array1OfPnt2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("TP"), py::arg("aTolu"), py::arg("aTolv"), py::arg("umin"), py::arg("vmin"), py::arg("umax"), py::arg("vmax"));

// Fields

// Methods
// cls_CSLib_Class2d.def_static("operator new_", (void * (*)(size_t)) &CSLib_Class2d::operator new, "None", py::arg("theSize"));
// cls_CSLib_Class2d.def_static("operator delete_", (void (*)(void *)) &CSLib_Class2d::operator delete, "None", py::arg("theAddress"));
// cls_CSLib_Class2d.def_static("operator new[]_", (void * (*)(size_t)) &CSLib_Class2d::operator new[], "None", py::arg("theSize"));
// cls_CSLib_Class2d.def_static("operator delete[]_", (void (*)(void *)) &CSLib_Class2d::operator delete[], "None", py::arg("theAddress"));
// cls_CSLib_Class2d.def_static("operator new_", (void * (*)(size_t, void *)) &CSLib_Class2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CSLib_Class2d.def_static("operator delete_", (void (*)(void *, void *)) &CSLib_Class2d::operator delete, "None", py::arg(""), py::arg(""));
cls_CSLib_Class2d.def("SiDans", (Standard_Integer (CSLib_Class2d::*)(const gp_Pnt2d &) const) &CSLib_Class2d::SiDans, "None", py::arg("P"));
cls_CSLib_Class2d.def("SiDans_OnMode", (Standard_Integer (CSLib_Class2d::*)(const gp_Pnt2d &, const Standard_Real) const) &CSLib_Class2d::SiDans_OnMode, "None", py::arg("P"), py::arg("Tol"));
cls_CSLib_Class2d.def("InternalSiDans", (Standard_Integer (CSLib_Class2d::*)(const Standard_Real, const Standard_Real) const) &CSLib_Class2d::InternalSiDans, "None", py::arg("X"), py::arg("Y"));
cls_CSLib_Class2d.def("InternalSiDansOuOn", (Standard_Integer (CSLib_Class2d::*)(const Standard_Real, const Standard_Real) const) &CSLib_Class2d::InternalSiDansOuOn, "None", py::arg("X"), py::arg("Y"));
cls_CSLib_Class2d.def("Copy", (const CSLib_Class2d & (CSLib_Class2d::*)(const CSLib_Class2d &) const) &CSLib_Class2d::Copy, "None", py::arg("Other"));
// cls_CSLib_Class2d.def("operator=", (const CSLib_Class2d & (CSLib_Class2d::*)(const CSLib_Class2d &) const) &CSLib_Class2d::operator=, "None", py::arg("Other"));
cls_CSLib_Class2d.def("Destroy", (void (CSLib_Class2d::*)()) &CSLib_Class2d::Destroy, "None");

// Enums

}