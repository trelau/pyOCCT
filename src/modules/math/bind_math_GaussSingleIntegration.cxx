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
#include <math_Function.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <math_GaussSingleIntegration.hxx>

void bind_math_GaussSingleIntegration(py::module &mod){

py::class_<math_GaussSingleIntegration, std::unique_ptr<math_GaussSingleIntegration>> cls_math_GaussSingleIntegration(mod, "math_GaussSingleIntegration", "This class implements the integration of a function of a single variable between the parameter bounds Lower and Upper. Warning: Order must be inferior or equal to 61.");

// Constructors
cls_math_GaussSingleIntegration.def(py::init<>());
cls_math_GaussSingleIntegration.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Lower"), py::arg("Upper"), py::arg("Order"));
cls_math_GaussSingleIntegration.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("F"), py::arg("Lower"), py::arg("Upper"), py::arg("Order"), py::arg("Tol"));

// Fields

// Methods
// cls_math_GaussSingleIntegration.def_static("operator new_", (void * (*)(size_t)) &math_GaussSingleIntegration::operator new, "None", py::arg("theSize"));
// cls_math_GaussSingleIntegration.def_static("operator delete_", (void (*)(void *)) &math_GaussSingleIntegration::operator delete, "None", py::arg("theAddress"));
// cls_math_GaussSingleIntegration.def_static("operator new[]_", (void * (*)(size_t)) &math_GaussSingleIntegration::operator new[], "None", py::arg("theSize"));
// cls_math_GaussSingleIntegration.def_static("operator delete[]_", (void (*)(void *)) &math_GaussSingleIntegration::operator delete[], "None", py::arg("theAddress"));
// cls_math_GaussSingleIntegration.def_static("operator new_", (void * (*)(size_t, void *)) &math_GaussSingleIntegration::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_GaussSingleIntegration.def_static("operator delete_", (void (*)(void *, void *)) &math_GaussSingleIntegration::operator delete, "None", py::arg(""), py::arg(""));
cls_math_GaussSingleIntegration.def("IsDone", (Standard_Boolean (math_GaussSingleIntegration::*)() const) &math_GaussSingleIntegration::IsDone, "returns True if all has been correctly done.");
cls_math_GaussSingleIntegration.def("Value", (Standard_Real (math_GaussSingleIntegration::*)() const) &math_GaussSingleIntegration::Value, "returns the value of the integral.");
cls_math_GaussSingleIntegration.def("Dump", (void (math_GaussSingleIntegration::*)(Standard_OStream &) const) &math_GaussSingleIntegration::Dump, "Prints information on the current state of the object.", py::arg("o"));

// Enums

}