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

void bind_PeriodicInterval(py::module &mod){

py::class_<PeriodicInterval> cls_PeriodicInterval(mod, "PeriodicInterval", "None");

// Constructors
cls_PeriodicInterval.def(py::init<const IntRes2d_Domain &>(), py::arg("Domain"));
cls_PeriodicInterval.def(py::init<>());
cls_PeriodicInterval.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("a"), py::arg("b"));

// Fields
cls_PeriodicInterval.def_readwrite("Binf", &PeriodicInterval::Binf, "None");
cls_PeriodicInterval.def_readwrite("Bsup", &PeriodicInterval::Bsup, "None");
cls_PeriodicInterval.def_readwrite("isnull", &PeriodicInterval::isnull, "None");

// Methods
cls_PeriodicInterval.def("SetNull", (void (PeriodicInterval::*)()) &PeriodicInterval::SetNull, "None");
cls_PeriodicInterval.def("IsNull", (Standard_Boolean (PeriodicInterval::*)()) &PeriodicInterval::IsNull, "None");
cls_PeriodicInterval.def("Complement", (void (PeriodicInterval::*)()) &PeriodicInterval::Complement, "None");
cls_PeriodicInterval.def("Length", (Standard_Real (PeriodicInterval::*)()) &PeriodicInterval::Length, "None");
cls_PeriodicInterval.def("SetValues", (void (PeriodicInterval::*)(const Standard_Real, const Standard_Real)) &PeriodicInterval::SetValues, "None", py::arg("a"), py::arg("b"));
cls_PeriodicInterval.def("Normalize", (void (PeriodicInterval::*)()) &PeriodicInterval::Normalize, "None");
// cls_PeriodicInterval.def("FirstIntersection", (PeriodicInterval (PeriodicInterval::*)(PeriodicInterval &)) &PeriodicInterval::FirstIntersection, "None", py::arg("I1"));
// cls_PeriodicInterval.def("SecondIntersection", (PeriodicInterval (PeriodicInterval::*)(PeriodicInterval &)) &PeriodicInterval::SecondIntersection, "None", py::arg("I2"));

// Enums

}