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
#include <IntCurve_IConicTool.hxx>
#include <IntCurve_PConic.hxx>
#include <Standard_TypeDef.hxx>
#include <IntCurve_MyImpParToolOfIntImpConicParConic.hxx>

void bind_IntCurve_MyImpParToolOfIntImpConicParConic(py::module &mod){

py::class_<IntCurve_MyImpParToolOfIntImpConicParConic, std::unique_ptr<IntCurve_MyImpParToolOfIntImpConicParConic, Deleter<IntCurve_MyImpParToolOfIntImpConicParConic>>, math_FunctionWithDerivative> cls_IntCurve_MyImpParToolOfIntImpConicParConic(mod, "IntCurve_MyImpParToolOfIntImpConicParConic", "None");

// Constructors
cls_IntCurve_MyImpParToolOfIntImpConicParConic.def(py::init<const IntCurve_IConicTool &, const IntCurve_PConic &>(), py::arg("IT"), py::arg("PC"));

// Fields

// Methods
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator new_", (void * (*)(size_t)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator new, "None", py::arg("theSize"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator delete_", (void (*)(void *)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_MyImpParToolOfIntImpConicParConic.def("Value", [](IntCurve_MyImpParToolOfIntImpConicParConic &self, const Standard_Real Param, Standard_Real & F){ Standard_Boolean rv = self.Value(Param, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the signed distance between the implicit curve and the point at parameter Param on the parametrised curve.", py::arg("Param"), py::arg("F"));
cls_IntCurve_MyImpParToolOfIntImpConicParConic.def("Derivative", [](IntCurve_MyImpParToolOfIntImpConicParConic &self, const Standard_Real Param, Standard_Real & D){ Standard_Boolean rv = self.Derivative(Param, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Computes the derivative of the previous function at parameter Param.", py::arg("Param"), py::arg("D"));
cls_IntCurve_MyImpParToolOfIntImpConicParConic.def("Values", [](IntCurve_MyImpParToolOfIntImpConicParConic &self, const Standard_Real Param, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(Param, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Computes the value and the derivative of the function.", py::arg("Param"), py::arg("F"), py::arg("D"));

// Enums

}