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
#include <Standard_OStream.hxx>
#include <math_DirectPolynomialRoots.hxx>

void bind_math_DirectPolynomialRoots(py::module &mod){

py::class_<math_DirectPolynomialRoots, std::unique_ptr<math_DirectPolynomialRoots, Deleter<math_DirectPolynomialRoots>>> cls_math_DirectPolynomialRoots(mod, "math_DirectPolynomialRoots", "This class implements the calculation of all the real roots of a real polynomial of degree <= 4 using a direct method. Once found, the roots are polished using the Newton method.");

// Constructors
cls_math_DirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"));
cls_math_DirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_math_DirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"));
cls_math_DirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"));

// Fields

// Methods
// cls_math_DirectPolynomialRoots.def_static("operator new_", (void * (*)(size_t)) &math_DirectPolynomialRoots::operator new, "None", py::arg("theSize"));
// cls_math_DirectPolynomialRoots.def_static("operator delete_", (void (*)(void *)) &math_DirectPolynomialRoots::operator delete, "None", py::arg("theAddress"));
// cls_math_DirectPolynomialRoots.def_static("operator new[]_", (void * (*)(size_t)) &math_DirectPolynomialRoots::operator new[], "None", py::arg("theSize"));
// cls_math_DirectPolynomialRoots.def_static("operator delete[]_", (void (*)(void *)) &math_DirectPolynomialRoots::operator delete[], "None", py::arg("theAddress"));
// cls_math_DirectPolynomialRoots.def_static("operator new_", (void * (*)(size_t, void *)) &math_DirectPolynomialRoots::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_DirectPolynomialRoots.def_static("operator delete_", (void (*)(void *, void *)) &math_DirectPolynomialRoots::operator delete, "None", py::arg(""), py::arg(""));
cls_math_DirectPolynomialRoots.def("IsDone", (Standard_Boolean (math_DirectPolynomialRoots::*)() const) &math_DirectPolynomialRoots::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_DirectPolynomialRoots.def("InfiniteRoots", (Standard_Boolean (math_DirectPolynomialRoots::*)() const) &math_DirectPolynomialRoots::InfiniteRoots, "Returns true if there is an infinity of roots, otherwise returns false.");
cls_math_DirectPolynomialRoots.def("NbSolutions", (Standard_Integer (math_DirectPolynomialRoots::*)() const) &math_DirectPolynomialRoots::NbSolutions, "returns the number of solutions. An exception is raised if there are an infinity of roots.");
cls_math_DirectPolynomialRoots.def("Value", (Standard_Real (math_DirectPolynomialRoots::*)(const Standard_Integer) const) &math_DirectPolynomialRoots::Value, "returns the value of the Nieme root. An exception is raised if there are an infinity of roots. Exception RangeError is raised if Nieme is < 1 or Nieme > NbSolutions.", py::arg("Nieme"));
cls_math_DirectPolynomialRoots.def("Dump", (void (math_DirectPolynomialRoots::*)(Standard_OStream &) const) &math_DirectPolynomialRoots::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}