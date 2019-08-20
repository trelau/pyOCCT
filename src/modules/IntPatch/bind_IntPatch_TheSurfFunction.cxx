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
#include <IntSurf_Quadric.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <IntPatch_TheSurfFunction.hxx>

void bind_IntPatch_TheSurfFunction(py::module &mod){

py::class_<IntPatch_TheSurfFunction, std::unique_ptr<IntPatch_TheSurfFunction>, math_FunctionSetWithDerivatives> cls_IntPatch_TheSurfFunction(mod, "IntPatch_TheSurfFunction", "None");

// Constructors
cls_IntPatch_TheSurfFunction.def(py::init<>());
cls_IntPatch_TheSurfFunction.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const IntSurf_Quadric &>(), py::arg("PS"), py::arg("IS"));
cls_IntPatch_TheSurfFunction.def(py::init<const IntSurf_Quadric &>(), py::arg("IS"));

// Fields

// Methods
// cls_IntPatch_TheSurfFunction.def_static("operator new_", (void * (*)(size_t)) &IntPatch_TheSurfFunction::operator new, "None", py::arg("theSize"));
// cls_IntPatch_TheSurfFunction.def_static("operator delete_", (void (*)(void *)) &IntPatch_TheSurfFunction::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_TheSurfFunction.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_TheSurfFunction::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_TheSurfFunction.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_TheSurfFunction::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_TheSurfFunction.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_TheSurfFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_TheSurfFunction.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_TheSurfFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_TheSurfFunction.def("Set", (void (IntPatch_TheSurfFunction::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_TheSurfFunction::Set, "None", py::arg("PS"));
cls_IntPatch_TheSurfFunction.def("SetImplicitSurface", (void (IntPatch_TheSurfFunction::*)(const IntSurf_Quadric &)) &IntPatch_TheSurfFunction::SetImplicitSurface, "None", py::arg("IS"));
cls_IntPatch_TheSurfFunction.def("Set", (void (IntPatch_TheSurfFunction::*)(const Standard_Real)) &IntPatch_TheSurfFunction::Set, "None", py::arg("Tolerance"));
cls_IntPatch_TheSurfFunction.def("NbVariables", (Standard_Integer (IntPatch_TheSurfFunction::*)() const) &IntPatch_TheSurfFunction::NbVariables, "None");
cls_IntPatch_TheSurfFunction.def("NbEquations", (Standard_Integer (IntPatch_TheSurfFunction::*)() const) &IntPatch_TheSurfFunction::NbEquations, "None");
cls_IntPatch_TheSurfFunction.def("Value", (Standard_Boolean (IntPatch_TheSurfFunction::*)(const math_Vector &, math_Vector &)) &IntPatch_TheSurfFunction::Value, "None", py::arg("X"), py::arg("F"));
cls_IntPatch_TheSurfFunction.def("Derivatives", (Standard_Boolean (IntPatch_TheSurfFunction::*)(const math_Vector &, math_Matrix &)) &IntPatch_TheSurfFunction::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_IntPatch_TheSurfFunction.def("Values", (Standard_Boolean (IntPatch_TheSurfFunction::*)(const math_Vector &, math_Vector &, math_Matrix &)) &IntPatch_TheSurfFunction::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_IntPatch_TheSurfFunction.def("Root", (Standard_Real (IntPatch_TheSurfFunction::*)() const) &IntPatch_TheSurfFunction::Root, "None");
cls_IntPatch_TheSurfFunction.def("Tolerance", (Standard_Real (IntPatch_TheSurfFunction::*)() const) &IntPatch_TheSurfFunction::Tolerance, "Returns the value Tol so that if Abs(Func.Root())<Tol the function is considered null.");
cls_IntPatch_TheSurfFunction.def("Point", (const gp_Pnt & (IntPatch_TheSurfFunction::*)() const) &IntPatch_TheSurfFunction::Point, "None");
cls_IntPatch_TheSurfFunction.def("IsTangent", (Standard_Boolean (IntPatch_TheSurfFunction::*)()) &IntPatch_TheSurfFunction::IsTangent, "None");
cls_IntPatch_TheSurfFunction.def("Direction3d", (const gp_Vec & (IntPatch_TheSurfFunction::*)()) &IntPatch_TheSurfFunction::Direction3d, "None");
cls_IntPatch_TheSurfFunction.def("Direction2d", (const gp_Dir2d & (IntPatch_TheSurfFunction::*)()) &IntPatch_TheSurfFunction::Direction2d, "None");
cls_IntPatch_TheSurfFunction.def("PSurface", (const opencascade::handle<Adaptor3d_HSurface> & (IntPatch_TheSurfFunction::*)() const) &IntPatch_TheSurfFunction::PSurface, "None");
cls_IntPatch_TheSurfFunction.def("ISurface", (const IntSurf_Quadric & (IntPatch_TheSurfFunction::*)() const) &IntPatch_TheSurfFunction::ISurface, "None");

// Enums

}