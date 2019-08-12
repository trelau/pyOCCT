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
#include <math_ValueAndWeight.hxx>

void bind_math_ValueAndWeight(py::module &mod){

py::class_<math_ValueAndWeight, std::unique_ptr<math_ValueAndWeight, Deleter<math_ValueAndWeight>>> cls_math_ValueAndWeight(mod, "math_ValueAndWeight", "Simple container storing two reals: value and weight");

// Constructors
cls_math_ValueAndWeight.def(py::init<>());
cls_math_ValueAndWeight.def(py::init<Standard_Real, Standard_Real>(), py::arg("theValue"), py::arg("theWeight"));

// Fields

// Methods
// cls_math_ValueAndWeight.def_static("operator new_", (void * (*)(size_t)) &math_ValueAndWeight::operator new, "None", py::arg("theSize"));
// cls_math_ValueAndWeight.def_static("operator delete_", (void (*)(void *)) &math_ValueAndWeight::operator delete, "None", py::arg("theAddress"));
// cls_math_ValueAndWeight.def_static("operator new[]_", (void * (*)(size_t)) &math_ValueAndWeight::operator new[], "None", py::arg("theSize"));
// cls_math_ValueAndWeight.def_static("operator delete[]_", (void (*)(void *)) &math_ValueAndWeight::operator delete[], "None", py::arg("theAddress"));
// cls_math_ValueAndWeight.def_static("operator new_", (void * (*)(size_t, void *)) &math_ValueAndWeight::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_ValueAndWeight.def_static("operator delete_", (void (*)(void *, void *)) &math_ValueAndWeight::operator delete, "None", py::arg(""), py::arg(""));
cls_math_ValueAndWeight.def("Value", (Standard_Real (math_ValueAndWeight::*)() const) &math_ValueAndWeight::Value, "None");
cls_math_ValueAndWeight.def("Weight", (Standard_Real (math_ValueAndWeight::*)() const) &math_ValueAndWeight::Weight, "None");

// Enums

}