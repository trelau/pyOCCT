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
#include <IntCurveSurface_TheCSFunctionOfHInter.hxx>
#include <math_FunctionSetRoot.hxx>
#include <gp_Pnt.hxx>
#include <IntCurveSurface_TheExactHInter.hxx>

void bind_IntCurveSurface_TheExactHInter(py::module &mod){

py::class_<IntCurveSurface_TheExactHInter, std::unique_ptr<IntCurveSurface_TheExactHInter, Deleter<IntCurveSurface_TheExactHInter>>> cls_IntCurveSurface_TheExactHInter(mod, "IntCurveSurface_TheExactHInter", "None");

// Constructors
cls_IntCurveSurface_TheExactHInter.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const IntCurveSurface_TheCSFunctionOfHInter &, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"));
cls_IntCurveSurface_TheExactHInter.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const IntCurveSurface_TheCSFunctionOfHInter &, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"), py::arg("MarginCoef"));
cls_IntCurveSurface_TheExactHInter.def(py::init<const IntCurveSurface_TheCSFunctionOfHInter &, const Standard_Real>(), py::arg("F"), py::arg("TolTangency"));

// Fields

// Methods
// cls_IntCurveSurface_TheExactHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheExactHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheExactHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheExactHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheExactHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheExactHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheExactHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheExactHInter.def("Perform", (void (IntCurveSurface_TheExactHInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_FunctionSetRoot &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntCurveSurface_TheExactHInter::Perform, "compute the solution it's possible to write to optimize: IntImp_IntCS inter(S1,C1,Toltangency) math_FunctionSetRoot rsnld(Inter.function()) while ...{ u=... v=... w=... inter.Perform(u,v,w,rsnld) } or IntImp_IntCS inter(Toltangency) inter.SetSurface(S); math_FunctionSetRoot rsnld(Inter.function()) while ...{ C=... inter.SetCurve(C); u=... v=... w=... inter.Perform(u,v,w,rsnld) }", py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Rsnld"), py::arg("u0"), py::arg("v0"), py::arg("u1"), py::arg("v1"), py::arg("w0"), py::arg("w1"));
cls_IntCurveSurface_TheExactHInter.def("IsDone", (Standard_Boolean (IntCurveSurface_TheExactHInter::*)() const) &IntCurveSurface_TheExactHInter::IsDone, "Returns TRUE if the creation completed without failure.");
cls_IntCurveSurface_TheExactHInter.def("IsEmpty", (Standard_Boolean (IntCurveSurface_TheExactHInter::*)() const) &IntCurveSurface_TheExactHInter::IsEmpty, "None");
cls_IntCurveSurface_TheExactHInter.def("Point", (const gp_Pnt & (IntCurveSurface_TheExactHInter::*)() const) &IntCurveSurface_TheExactHInter::Point, "returns the intersection point The exception NotDone is raised if IsDone is false. The exception DomainError is raised if IsEmpty is true.");
cls_IntCurveSurface_TheExactHInter.def("ParameterOnCurve", (Standard_Real (IntCurveSurface_TheExactHInter::*)() const) &IntCurveSurface_TheExactHInter::ParameterOnCurve, "None");
cls_IntCurveSurface_TheExactHInter.def("ParameterOnSurface", [](IntCurveSurface_TheExactHInter &self, Standard_Real & U, Standard_Real & V){ self.ParameterOnSurface(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_IntCurveSurface_TheExactHInter.def("Function", (IntCurveSurface_TheCSFunctionOfHInter & (IntCurveSurface_TheExactHInter::*)()) &IntCurveSurface_TheExactHInter::Function, "return the math function which is used to compute the intersection");

// Enums

}