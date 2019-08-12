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
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <IntPatch_CSFunction.hxx>

void bind_IntPatch_CSFunction(py::module &mod){

py::class_<IntPatch_CSFunction, std::unique_ptr<IntPatch_CSFunction, Deleter<IntPatch_CSFunction>>, math_FunctionSetWithDerivatives> cls_IntPatch_CSFunction(mod, "IntPatch_CSFunction", "this function is associated to the intersection between a curve on surface and a surface .");

// Constructors
cls_IntPatch_CSFunction.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S1"), py::arg("C"), py::arg("S2"));

// Fields

// Methods
// cls_IntPatch_CSFunction.def_static("operator new_", (void * (*)(size_t)) &IntPatch_CSFunction::operator new, "None", py::arg("theSize"));
// cls_IntPatch_CSFunction.def_static("operator delete_", (void (*)(void *)) &IntPatch_CSFunction::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_CSFunction.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_CSFunction::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_CSFunction.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_CSFunction::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_CSFunction.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_CSFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_CSFunction.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_CSFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_CSFunction.def("NbVariables", (Standard_Integer (IntPatch_CSFunction::*)() const) &IntPatch_CSFunction::NbVariables, "None");
cls_IntPatch_CSFunction.def("NbEquations", (Standard_Integer (IntPatch_CSFunction::*)() const) &IntPatch_CSFunction::NbEquations, "None");
cls_IntPatch_CSFunction.def("Value", (Standard_Boolean (IntPatch_CSFunction::*)(const math_Vector &, math_Vector &)) &IntPatch_CSFunction::Value, "None", py::arg("X"), py::arg("F"));
cls_IntPatch_CSFunction.def("Derivatives", (Standard_Boolean (IntPatch_CSFunction::*)(const math_Vector &, math_Matrix &)) &IntPatch_CSFunction::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_IntPatch_CSFunction.def("Values", (Standard_Boolean (IntPatch_CSFunction::*)(const math_Vector &, math_Vector &, math_Matrix &)) &IntPatch_CSFunction::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_IntPatch_CSFunction.def("Point", (const gp_Pnt & (IntPatch_CSFunction::*)() const) &IntPatch_CSFunction::Point, "None");
cls_IntPatch_CSFunction.def("Root", (Standard_Real (IntPatch_CSFunction::*)() const) &IntPatch_CSFunction::Root, "None");
cls_IntPatch_CSFunction.def("AuxillarSurface", (const opencascade::handle<Adaptor3d_HSurface> & (IntPatch_CSFunction::*)() const) &IntPatch_CSFunction::AuxillarSurface, "None");
cls_IntPatch_CSFunction.def("AuxillarCurve", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_CSFunction::*)() const) &IntPatch_CSFunction::AuxillarCurve, "None");

// Enums

}