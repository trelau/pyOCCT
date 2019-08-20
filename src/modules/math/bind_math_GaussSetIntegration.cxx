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
#include <math_FunctionSet.hxx>
#include <math_Vector.hxx>
#include <math_IntegerVector.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <math_GaussSetIntegration.hxx>

void bind_math_GaussSetIntegration(py::module &mod){

py::class_<math_GaussSetIntegration, std::unique_ptr<math_GaussSetIntegration>> cls_math_GaussSetIntegration(mod, "math_GaussSetIntegration", "-- This class implements the integration of a set of N functions of M variables variables between the parameter bounds Lower[a..b] and Upper[a..b]. Warning: - The case M>1 is not implemented.");

// Constructors
cls_math_GaussSetIntegration.def(py::init<math_FunctionSet &, const math_Vector &, const math_Vector &, const math_IntegerVector &>(), py::arg("F"), py::arg("Lower"), py::arg("Upper"), py::arg("Order"));

// Fields

// Methods
// cls_math_GaussSetIntegration.def_static("operator new_", (void * (*)(size_t)) &math_GaussSetIntegration::operator new, "None", py::arg("theSize"));
// cls_math_GaussSetIntegration.def_static("operator delete_", (void (*)(void *)) &math_GaussSetIntegration::operator delete, "None", py::arg("theAddress"));
// cls_math_GaussSetIntegration.def_static("operator new[]_", (void * (*)(size_t)) &math_GaussSetIntegration::operator new[], "None", py::arg("theSize"));
// cls_math_GaussSetIntegration.def_static("operator delete[]_", (void (*)(void *)) &math_GaussSetIntegration::operator delete[], "None", py::arg("theAddress"));
// cls_math_GaussSetIntegration.def_static("operator new_", (void * (*)(size_t, void *)) &math_GaussSetIntegration::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_GaussSetIntegration.def_static("operator delete_", (void (*)(void *, void *)) &math_GaussSetIntegration::operator delete, "None", py::arg(""), py::arg(""));
cls_math_GaussSetIntegration.def("IsDone", (Standard_Boolean (math_GaussSetIntegration::*)() const) &math_GaussSetIntegration::IsDone, "returns True if all has been correctly done.");
cls_math_GaussSetIntegration.def("Value", (const math_Vector & (math_GaussSetIntegration::*)() const) &math_GaussSetIntegration::Value, "returns the value of the integral.");
cls_math_GaussSetIntegration.def("Dump", (void (math_GaussSetIntegration::*)(Standard_OStream &) const) &math_GaussSetIntegration::Dump, "Prints information on the current state of the object.", py::arg("o"));

// Enums

}