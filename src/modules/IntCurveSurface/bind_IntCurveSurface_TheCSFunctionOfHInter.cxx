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
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <IntCurveSurface_TheCSFunctionOfHInter.hxx>

void bind_IntCurveSurface_TheCSFunctionOfHInter(py::module &mod){

py::class_<IntCurveSurface_TheCSFunctionOfHInter, std::unique_ptr<IntCurveSurface_TheCSFunctionOfHInter>, math_FunctionSetWithDerivatives> cls_IntCurveSurface_TheCSFunctionOfHInter(mod, "IntCurveSurface_TheCSFunctionOfHInter", "None");

// Constructors
cls_IntCurveSurface_TheCSFunctionOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"));

// Fields

// Methods
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheCSFunctionOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheCSFunctionOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheCSFunctionOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheCSFunctionOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheCSFunctionOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheCSFunctionOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheCSFunctionOfHInter.def("NbVariables", (Standard_Integer (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::NbVariables, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("NbEquations", (Standard_Integer (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::NbEquations, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Value", (Standard_Boolean (IntCurveSurface_TheCSFunctionOfHInter::*)(const math_Vector &, math_Vector &)) &IntCurveSurface_TheCSFunctionOfHInter::Value, "None", py::arg("X"), py::arg("F"));
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Derivatives", (Standard_Boolean (IntCurveSurface_TheCSFunctionOfHInter::*)(const math_Vector &, math_Matrix &)) &IntCurveSurface_TheCSFunctionOfHInter::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Values", (Standard_Boolean (IntCurveSurface_TheCSFunctionOfHInter::*)(const math_Vector &, math_Vector &, math_Matrix &)) &IntCurveSurface_TheCSFunctionOfHInter::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Point", (const gp_Pnt & (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::Point, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Root", (Standard_Real (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::Root, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("AuxillarSurface", (const opencascade::handle<Adaptor3d_HSurface> & (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::AuxillarSurface, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("AuxillarCurve", (const opencascade::handle<Adaptor3d_HCurve> & (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::AuxillarCurve, "None");

// Enums

}