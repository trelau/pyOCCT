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
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Domain.hxx>
#include <IntCurve_IntConicConic_Tool.hxx>

void bind_Interval(py::module &mod){

py::class_<Interval, std::unique_ptr<Interval>> cls_Interval(mod, "Interval", "None");

// Constructors
// cls_Interval.def(py::init<>());
// cls_Interval.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("a"), py::arg("b"));
// cls_Interval.def(py::init<const IntRes2d_Domain &>(), py::arg("Domain"));
// cls_Interval.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean>(), py::arg("a"), py::arg("hf"), py::arg("b"), py::arg("hl"));

// Fields
cls_Interval.def_readwrite("Binf", &Interval::Binf, "None");
cls_Interval.def_readwrite("Bsup", &Interval::Bsup, "None");
cls_Interval.def_readwrite("HasFirstBound", &Interval::HasFirstBound, "None");
cls_Interval.def_readwrite("HasLastBound", &Interval::HasLastBound, "None");
cls_Interval.def_readwrite("IsNull", &Interval::IsNull, "None");

// Methods
// cls_Interval.def("Length", (Standard_Real (Interval::*)()) &Interval::Length, "None");
// cls_Interval.def("IntersectionWithBounded", (Interval (Interval::*)(const Interval &)) &Interval::IntersectionWithBounded, "None", py::arg("Inter"));

// Enums

}