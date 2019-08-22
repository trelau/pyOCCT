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
#include <BRepGProp_Face.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <GProp_ValueType.hxx>
#include <gp_XYZ.hxx>
#include <BRepGProp_UFunction.hxx>

void bind_BRepGProp_UFunction(py::module &mod){

py::class_<BRepGProp_UFunction, math_Function> cls_BRepGProp_UFunction(mod, "BRepGProp_UFunction", "This class represents the integrand function for computation of an inner integral. The returned value depends on the value type and the flag IsByPoint.");

// Constructors
cls_BRepGProp_UFunction.def(py::init<const BRepGProp_Face &, const gp_Pnt &, const Standard_Boolean, const Standard_Address>(), py::arg("theSurface"), py::arg("theVertex"), py::arg("IsByPoint"), py::arg("theCoeffs"));

// Fields

// Methods
// cls_BRepGProp_UFunction.def_static("operator new_", (void * (*)(size_t)) &BRepGProp_UFunction::operator new, "None", py::arg("theSize"));
// cls_BRepGProp_UFunction.def_static("operator delete_", (void (*)(void *)) &BRepGProp_UFunction::operator delete, "None", py::arg("theAddress"));
// cls_BRepGProp_UFunction.def_static("operator new[]_", (void * (*)(size_t)) &BRepGProp_UFunction::operator new[], "None", py::arg("theSize"));
// cls_BRepGProp_UFunction.def_static("operator delete[]_", (void (*)(void *)) &BRepGProp_UFunction::operator delete[], "None", py::arg("theAddress"));
// cls_BRepGProp_UFunction.def_static("operator new_", (void * (*)(size_t, void *)) &BRepGProp_UFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepGProp_UFunction.def_static("operator delete_", (void (*)(void *, void *)) &BRepGProp_UFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepGProp_UFunction.def("SetValueType", (void (BRepGProp_UFunction::*)(const GProp_ValueType)) &BRepGProp_UFunction::SetValueType, "Setting the type of the value to be returned.", py::arg("theType"));
cls_BRepGProp_UFunction.def("SetVParam", (void (BRepGProp_UFunction::*)(const Standard_Real)) &BRepGProp_UFunction::SetVParam, "Setting the V parameter that is constant during the integral computation.", py::arg("theVParam"));
cls_BRepGProp_UFunction.def("Value", [](BRepGProp_UFunction &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Returns a value of the function.", py::arg("X"), py::arg("F"));

// Enums

}