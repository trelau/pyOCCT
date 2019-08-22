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
#include <TColStd_Array1OfReal.hxx>
#include <math_TrigonometricFunctionRoots.hxx>

void bind_math_TrigonometricFunctionRoots(py::module &mod){

py::class_<math_TrigonometricFunctionRoots> cls_math_TrigonometricFunctionRoots(mod, "math_TrigonometricFunctionRoots", "This class implements the solutions of the equation a*Cos(x)*Cos(x) + 2*b*Cos(x)*Sin(x) + c*Cos(x) + d*Sin(x) + e The degree of this equation can be 4, 3 or 2.");

// Constructors
cls_math_TrigonometricFunctionRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("InfBound"), py::arg("SupBound"));
cls_math_TrigonometricFunctionRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("D"), py::arg("E"), py::arg("InfBound"), py::arg("SupBound"));
cls_math_TrigonometricFunctionRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("InfBound"), py::arg("SupBound"));

// Fields

// Methods
// cls_math_TrigonometricFunctionRoots.def_static("operator new_", (void * (*)(size_t)) &math_TrigonometricFunctionRoots::operator new, "None", py::arg("theSize"));
// cls_math_TrigonometricFunctionRoots.def_static("operator delete_", (void (*)(void *)) &math_TrigonometricFunctionRoots::operator delete, "None", py::arg("theAddress"));
// cls_math_TrigonometricFunctionRoots.def_static("operator new[]_", (void * (*)(size_t)) &math_TrigonometricFunctionRoots::operator new[], "None", py::arg("theSize"));
// cls_math_TrigonometricFunctionRoots.def_static("operator delete[]_", (void (*)(void *)) &math_TrigonometricFunctionRoots::operator delete[], "None", py::arg("theAddress"));
// cls_math_TrigonometricFunctionRoots.def_static("operator new_", (void * (*)(size_t, void *)) &math_TrigonometricFunctionRoots::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_TrigonometricFunctionRoots.def_static("operator delete_", (void (*)(void *, void *)) &math_TrigonometricFunctionRoots::operator delete, "None", py::arg(""), py::arg(""));
cls_math_TrigonometricFunctionRoots.def("IsDone", (Standard_Boolean (math_TrigonometricFunctionRoots::*)() const) &math_TrigonometricFunctionRoots::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_TrigonometricFunctionRoots.def("InfiniteRoots", (Standard_Boolean (math_TrigonometricFunctionRoots::*)() const) &math_TrigonometricFunctionRoots::InfiniteRoots, "Returns true if there is an infinity of roots, otherwise returns false.");
cls_math_TrigonometricFunctionRoots.def("Value", (Standard_Real (math_TrigonometricFunctionRoots::*)(const Standard_Integer) const) &math_TrigonometricFunctionRoots::Value, "Returns the solution of range Index. An exception is raised if NotDone. An exception is raised if Index>NbSolutions. An exception is raised if there is an infinity of solutions.", py::arg("Index"));
cls_math_TrigonometricFunctionRoots.def("NbSolutions", (Standard_Integer (math_TrigonometricFunctionRoots::*)() const) &math_TrigonometricFunctionRoots::NbSolutions, "Returns the number of solutions found. An exception is raised if NotDone. An exception is raised if there is an infinity of solutions.");
cls_math_TrigonometricFunctionRoots.def("Dump", (void (math_TrigonometricFunctionRoots::*)(Standard_OStream &) const) &math_TrigonometricFunctionRoots::Dump, "Prints information on the current state of the object.", py::arg("o"));

// Enums

}