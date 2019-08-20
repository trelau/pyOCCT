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
#include <math_Function.hxx>
#include <Standard.hxx>
#include <CPnts_RealFunction.hxx>
#include <Standard_TypeDef.hxx>
#include <CPnts_MyGaussFunction.hxx>

void bind_CPnts_MyGaussFunction(py::module &mod){

py::class_<CPnts_MyGaussFunction, std::unique_ptr<CPnts_MyGaussFunction>, math_Function> cls_CPnts_MyGaussFunction(mod, "CPnts_MyGaussFunction", "for implementation, compute values for Gauss");

// Constructors
cls_CPnts_MyGaussFunction.def(py::init<>());

// Fields

// Methods
// cls_CPnts_MyGaussFunction.def_static("operator new_", (void * (*)(size_t)) &CPnts_MyGaussFunction::operator new, "None", py::arg("theSize"));
// cls_CPnts_MyGaussFunction.def_static("operator delete_", (void (*)(void *)) &CPnts_MyGaussFunction::operator delete, "None", py::arg("theAddress"));
// cls_CPnts_MyGaussFunction.def_static("operator new[]_", (void * (*)(size_t)) &CPnts_MyGaussFunction::operator new[], "None", py::arg("theSize"));
// cls_CPnts_MyGaussFunction.def_static("operator delete[]_", (void (*)(void *)) &CPnts_MyGaussFunction::operator delete[], "None", py::arg("theAddress"));
// cls_CPnts_MyGaussFunction.def_static("operator new_", (void * (*)(size_t, void *)) &CPnts_MyGaussFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CPnts_MyGaussFunction.def_static("operator delete_", (void (*)(void *, void *)) &CPnts_MyGaussFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_CPnts_MyGaussFunction.def("Init", (void (CPnts_MyGaussFunction::*)(const CPnts_RealFunction &, const Standard_Address)) &CPnts_MyGaussFunction::Init, "F is a pointer on a function D is a client data", py::arg("F"), py::arg("D"));
cls_CPnts_MyGaussFunction.def("Value", [](CPnts_MyGaussFunction &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));

// Enums

}