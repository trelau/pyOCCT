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
#include <math_FunctionWithDerivative.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <ChFi3d_SearchSing.hxx>

void bind_ChFi3d_SearchSing(py::module &mod){

py::class_<ChFi3d_SearchSing, std::unique_ptr<ChFi3d_SearchSing>, math_FunctionWithDerivative> cls_ChFi3d_SearchSing(mod, "ChFi3d_SearchSing", "Searches singularities on fillet. F(t) = (C1(t) - C2(t)).(C1'(t) - C2'(t));");

// Constructors
cls_ChFi3d_SearchSing.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("C1"), py::arg("C2"));

// Fields

// Methods
// cls_ChFi3d_SearchSing.def_static("operator new_", (void * (*)(size_t)) &ChFi3d_SearchSing::operator new, "None", py::arg("theSize"));
// cls_ChFi3d_SearchSing.def_static("operator delete_", (void (*)(void *)) &ChFi3d_SearchSing::operator delete, "None", py::arg("theAddress"));
// cls_ChFi3d_SearchSing.def_static("operator new[]_", (void * (*)(size_t)) &ChFi3d_SearchSing::operator new[], "None", py::arg("theSize"));
// cls_ChFi3d_SearchSing.def_static("operator delete[]_", (void (*)(void *)) &ChFi3d_SearchSing::operator delete[], "None", py::arg("theAddress"));
// cls_ChFi3d_SearchSing.def_static("operator new_", (void * (*)(size_t, void *)) &ChFi3d_SearchSing::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFi3d_SearchSing.def_static("operator delete_", (void (*)(void *, void *)) &ChFi3d_SearchSing::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFi3d_SearchSing.def("Value", [](ChFi3d_SearchSing &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value of the function <F> for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_ChFi3d_SearchSing.def("Derivative", [](ChFi3d_SearchSing &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
cls_ChFi3d_SearchSing.def("Values", [](ChFi3d_SearchSing &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// Enums

}