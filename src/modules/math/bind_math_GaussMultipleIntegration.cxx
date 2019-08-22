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
#include <math_MultipleVarFunction.hxx>
#include <math_Vector.hxx>
#include <math_IntegerVector.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <math_GaussMultipleIntegration.hxx>

void bind_math_GaussMultipleIntegration(py::module &mod){

py::class_<math_GaussMultipleIntegration> cls_math_GaussMultipleIntegration(mod, "math_GaussMultipleIntegration", "This class implements the integration of a function of multiple variables between the parameter bounds Lower[a..b] and Upper[a..b]. Warning: Each element of Order must be inferior or equal to 61.");

// Constructors
cls_math_GaussMultipleIntegration.def(py::init<math_MultipleVarFunction &, const math_Vector &, const math_Vector &, const math_IntegerVector &>(), py::arg("F"), py::arg("Lower"), py::arg("Upper"), py::arg("Order"));

// Fields

// Methods
// cls_math_GaussMultipleIntegration.def_static("operator new_", (void * (*)(size_t)) &math_GaussMultipleIntegration::operator new, "None", py::arg("theSize"));
// cls_math_GaussMultipleIntegration.def_static("operator delete_", (void (*)(void *)) &math_GaussMultipleIntegration::operator delete, "None", py::arg("theAddress"));
// cls_math_GaussMultipleIntegration.def_static("operator new[]_", (void * (*)(size_t)) &math_GaussMultipleIntegration::operator new[], "None", py::arg("theSize"));
// cls_math_GaussMultipleIntegration.def_static("operator delete[]_", (void (*)(void *)) &math_GaussMultipleIntegration::operator delete[], "None", py::arg("theAddress"));
// cls_math_GaussMultipleIntegration.def_static("operator new_", (void * (*)(size_t, void *)) &math_GaussMultipleIntegration::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_GaussMultipleIntegration.def_static("operator delete_", (void (*)(void *, void *)) &math_GaussMultipleIntegration::operator delete, "None", py::arg(""), py::arg(""));
cls_math_GaussMultipleIntegration.def("IsDone", (Standard_Boolean (math_GaussMultipleIntegration::*)() const) &math_GaussMultipleIntegration::IsDone, "returns True if all has been correctly done.");
cls_math_GaussMultipleIntegration.def("Value", (Standard_Real (math_GaussMultipleIntegration::*)() const) &math_GaussMultipleIntegration::Value, "returns the value of the integral.");
cls_math_GaussMultipleIntegration.def("Dump", (void (math_GaussMultipleIntegration::*)(Standard_OStream &) const) &math_GaussMultipleIntegration::Dump, "Prints information on the current state of the object.", py::arg("o"));

// Enums

}