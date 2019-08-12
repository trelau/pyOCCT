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
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <Standard.hxx>
#include <Adaptor3d_Surface.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <Extrema_FuncPSDist.hxx>

void bind_Extrema_FuncPSDist(py::module &mod){

py::class_<Extrema_FuncPSDist, std::unique_ptr<Extrema_FuncPSDist, Deleter<Extrema_FuncPSDist>>, math_MultipleVarFunctionWithGradient> cls_Extrema_FuncPSDist(mod, "Extrema_FuncPSDist", "Functional for search of extremum of the square Euclidean distance between point P and surface S, starting from approximate solution (u0, v0).");

// Constructors
cls_Extrema_FuncPSDist.def(py::init<const Adaptor3d_Surface &, const gp_Pnt &>(), py::arg("theS"), py::arg("theP"));

// Fields

// Methods
// cls_Extrema_FuncPSDist.def_static("operator new_", (void * (*)(size_t)) &Extrema_FuncPSDist::operator new, "None", py::arg("theSize"));
// cls_Extrema_FuncPSDist.def_static("operator delete_", (void (*)(void *)) &Extrema_FuncPSDist::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_FuncPSDist.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_FuncPSDist::operator new[], "None", py::arg("theSize"));
// cls_Extrema_FuncPSDist.def_static("operator delete[]_", (void (*)(void *)) &Extrema_FuncPSDist::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_FuncPSDist.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_FuncPSDist::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_FuncPSDist.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_FuncPSDist::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_FuncPSDist.def("NbVariables", (Standard_Integer (Extrema_FuncPSDist::*)() const) &Extrema_FuncPSDist::NbVariables, "Number of variables.");
cls_Extrema_FuncPSDist.def("Value", [](Extrema_FuncPSDist &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Value.", py::arg("X"), py::arg("F"));
cls_Extrema_FuncPSDist.def("Gradient", (Standard_Boolean (Extrema_FuncPSDist::*)(const math_Vector &, math_Vector &)) &Extrema_FuncPSDist::Gradient, "Gradient.", py::arg("X"), py::arg("G"));
cls_Extrema_FuncPSDist.def("Values", [](Extrema_FuncPSDist &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Value and gradient.", py::arg("X"), py::arg("F"), py::arg("G"));

// Enums

}