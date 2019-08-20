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
#include <IntAna2d_Outils.hxx>

void bind_MyDirectPolynomialRoots(py::module &mod){

py::class_<MyDirectPolynomialRoots, std::unique_ptr<MyDirectPolynomialRoots>> cls_MyDirectPolynomialRoots(mod, "MyDirectPolynomialRoots", "None");

// Constructors
// cls_MyDirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A4"), py::arg("A3"), py::arg("A2"), py::arg("A1"), py::arg("A0"));
// cls_MyDirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("A1"), py::arg("A0"));

// Fields

// Methods
cls_MyDirectPolynomialRoots.def("NbSolutions", (Standard_Integer (MyDirectPolynomialRoots::*)() const) &MyDirectPolynomialRoots::NbSolutions, "None");
cls_MyDirectPolynomialRoots.def("Value", (Standard_Real (MyDirectPolynomialRoots::*)(const Standard_Integer) const) &MyDirectPolynomialRoots::Value, "None", py::arg("i"));
cls_MyDirectPolynomialRoots.def("IsDone", (Standard_Real (MyDirectPolynomialRoots::*)() const) &MyDirectPolynomialRoots::IsDone, "None");
cls_MyDirectPolynomialRoots.def("InfiniteRoots", (Standard_Boolean (MyDirectPolynomialRoots::*)() const) &MyDirectPolynomialRoots::InfiniteRoots, "None");

// Enums

}