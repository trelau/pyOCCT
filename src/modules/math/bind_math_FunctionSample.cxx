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
#include <math_FunctionSample.hxx>

void bind_math_FunctionSample(py::module &mod){

py::class_<math_FunctionSample, std::unique_ptr<math_FunctionSample>> cls_math_FunctionSample(mod, "math_FunctionSample", "This class gives a default sample (constant difference of parameter) for a function defined between two bound A,B.");

// Constructors
cls_math_FunctionSample.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("A"), py::arg("B"), py::arg("N"));

// Fields

// Methods
// cls_math_FunctionSample.def_static("operator new_", (void * (*)(size_t)) &math_FunctionSample::operator new, "None", py::arg("theSize"));
// cls_math_FunctionSample.def_static("operator delete_", (void (*)(void *)) &math_FunctionSample::operator delete, "None", py::arg("theAddress"));
// cls_math_FunctionSample.def_static("operator new[]_", (void * (*)(size_t)) &math_FunctionSample::operator new[], "None", py::arg("theSize"));
// cls_math_FunctionSample.def_static("operator delete[]_", (void (*)(void *)) &math_FunctionSample::operator delete[], "None", py::arg("theAddress"));
// cls_math_FunctionSample.def_static("operator new_", (void * (*)(size_t, void *)) &math_FunctionSample::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_FunctionSample.def_static("operator delete_", (void (*)(void *, void *)) &math_FunctionSample::operator delete, "None", py::arg(""), py::arg(""));
cls_math_FunctionSample.def("Bounds", [](math_FunctionSample &self, Standard_Real & A, Standard_Real & B){ self.Bounds(A, B); return std::tuple<Standard_Real &, Standard_Real &>(A, B); }, "Returns the bounds of parameters.", py::arg("A"), py::arg("B"));
cls_math_FunctionSample.def("NbPoints", (Standard_Integer (math_FunctionSample::*)() const) &math_FunctionSample::NbPoints, "Returns the number of sample points.");
cls_math_FunctionSample.def("GetParameter", (Standard_Real (math_FunctionSample::*)(const Standard_Integer) const) &math_FunctionSample::GetParameter, "Returns the value of parameter of the point of range Index : A + ((Index-1)/(NbPoints-1))*B. An exception is raised if Index<=0 or Index>NbPoints.", py::arg("Index"));

// Enums

}