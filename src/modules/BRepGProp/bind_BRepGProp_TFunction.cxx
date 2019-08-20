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
#include <BRepGProp_UFunction.hxx>
#include <BRepGProp_TFunction.hxx>

void bind_BRepGProp_TFunction(py::module &mod){

py::class_<BRepGProp_TFunction, std::unique_ptr<BRepGProp_TFunction>, math_Function> cls_BRepGProp_TFunction(mod, "BRepGProp_TFunction", "This class represents the integrand function for the outer integral computation. The returned value represents the integral of UFunction. It depends on the value type and the flag IsByPoint.");

// Constructors
cls_BRepGProp_TFunction.def(py::init<const BRepGProp_Face &, const gp_Pnt &, const Standard_Boolean, const Standard_Address, const Standard_Real, const Standard_Real>(), py::arg("theSurface"), py::arg("theVertex"), py::arg("IsByPoint"), py::arg("theCoeffs"), py::arg("theUMin"), py::arg("theTolerance"));

// Fields

// Methods
// cls_BRepGProp_TFunction.def_static("operator new_", (void * (*)(size_t)) &BRepGProp_TFunction::operator new, "None", py::arg("theSize"));
// cls_BRepGProp_TFunction.def_static("operator delete_", (void (*)(void *)) &BRepGProp_TFunction::operator delete, "None", py::arg("theAddress"));
// cls_BRepGProp_TFunction.def_static("operator new[]_", (void * (*)(size_t)) &BRepGProp_TFunction::operator new[], "None", py::arg("theSize"));
// cls_BRepGProp_TFunction.def_static("operator delete[]_", (void (*)(void *)) &BRepGProp_TFunction::operator delete[], "None", py::arg("theAddress"));
// cls_BRepGProp_TFunction.def_static("operator new_", (void * (*)(size_t, void *)) &BRepGProp_TFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepGProp_TFunction.def_static("operator delete_", (void (*)(void *, void *)) &BRepGProp_TFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepGProp_TFunction.def("Init", (void (BRepGProp_TFunction::*)()) &BRepGProp_TFunction::Init, "None");
cls_BRepGProp_TFunction.def("SetNbKronrodPoints", (void (BRepGProp_TFunction::*)(const Standard_Integer)) &BRepGProp_TFunction::SetNbKronrodPoints, "Setting the expected number of Kronrod points for the outer integral computation. This number is required for computation of a value of tolerance for inner integral computation. After GetStateNumber method call, this number is recomputed by the same law as in math_KronrodSingleIntegration, i.e. next number of points is equal to the current number plus a square root of the current number. If the law in math_KronrodSingleIntegration is changed, the modification algo should be modified accordingly.", py::arg("theNbPoints"));
cls_BRepGProp_TFunction.def("SetValueType", (void (BRepGProp_TFunction::*)(const GProp_ValueType)) &BRepGProp_TFunction::SetValueType, "Setting the type of the value to be returned. This parameter is directly passed to the UFunction.", py::arg("aType"));
cls_BRepGProp_TFunction.def("SetTolerance", (void (BRepGProp_TFunction::*)(const Standard_Real)) &BRepGProp_TFunction::SetTolerance, "Setting the tolerance for inner integration", py::arg("aTol"));
cls_BRepGProp_TFunction.def("ErrorReached", (Standard_Real (BRepGProp_TFunction::*)() const) &BRepGProp_TFunction::ErrorReached, "Returns the relative reached error of all values computation since the last call of GetStateNumber method.");
cls_BRepGProp_TFunction.def("AbsolutError", (Standard_Real (BRepGProp_TFunction::*)() const) &BRepGProp_TFunction::AbsolutError, "Returns the absolut reached error of all values computation since the last call of GetStateNumber method.");
cls_BRepGProp_TFunction.def("Value", [](BRepGProp_TFunction &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Returns a value of the function. The value represents an integral of UFunction. It is computed with the predefined tolerance using the adaptive Gauss-Kronrod method.", py::arg("X"), py::arg("F"));
cls_BRepGProp_TFunction.def("GetStateNumber", (Standard_Integer (BRepGProp_TFunction::*)()) &BRepGProp_TFunction::GetStateNumber, "Redefined method. Remembers the error reached during computation of integral values since the object creation or the last call of GetStateNumber. It is invoked in each algorithm from the package math. Particularly in the algorithm math_KronrodSingleIntegration that is used to compute the integral of TFunction.");

// Enums

}