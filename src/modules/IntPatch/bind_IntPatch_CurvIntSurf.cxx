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
#include <IntPatch_CSFunction.hxx>
#include <math_FunctionSetRoot.hxx>
#include <gp_Pnt.hxx>
#include <IntPatch_CurvIntSurf.hxx>

void bind_IntPatch_CurvIntSurf(py::module &mod){

py::class_<IntPatch_CurvIntSurf, std::unique_ptr<IntPatch_CurvIntSurf>> cls_IntPatch_CurvIntSurf(mod, "IntPatch_CurvIntSurf", "None");

// Constructors
cls_IntPatch_CurvIntSurf.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const IntPatch_CSFunction &, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"));
cls_IntPatch_CurvIntSurf.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const IntPatch_CSFunction &, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"), py::arg("MarginCoef"));
cls_IntPatch_CurvIntSurf.def(py::init<const IntPatch_CSFunction &, const Standard_Real>(), py::arg("F"), py::arg("TolTangency"));

// Fields

// Methods
// cls_IntPatch_CurvIntSurf.def_static("operator new_", (void * (*)(size_t)) &IntPatch_CurvIntSurf::operator new, "None", py::arg("theSize"));
// cls_IntPatch_CurvIntSurf.def_static("operator delete_", (void (*)(void *)) &IntPatch_CurvIntSurf::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_CurvIntSurf.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_CurvIntSurf::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_CurvIntSurf.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_CurvIntSurf::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_CurvIntSurf.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_CurvIntSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_CurvIntSurf.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_CurvIntSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_CurvIntSurf.def("Perform", (void (IntPatch_CurvIntSurf::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_FunctionSetRoot &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_CurvIntSurf::Perform, "compute the solution it's possible to write to optimize: IntImp_IntCS inter(S1,C1,Toltangency) math_FunctionSetRoot rsnld(Inter.function()) while ...{ u=... v=... w=... inter.Perform(u,v,w,rsnld) } or IntImp_IntCS inter(Toltangency) inter.SetSurface(S); math_FunctionSetRoot rsnld(Inter.function()) while ...{ C=... inter.SetCurve(C); u=... v=... w=... inter.Perform(u,v,w,rsnld) }", py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Rsnld"), py::arg("u0"), py::arg("v0"), py::arg("u1"), py::arg("v1"), py::arg("w0"), py::arg("w1"));
cls_IntPatch_CurvIntSurf.def("IsDone", (Standard_Boolean (IntPatch_CurvIntSurf::*)() const) &IntPatch_CurvIntSurf::IsDone, "Returns TRUE if the creation completed without failure.");
cls_IntPatch_CurvIntSurf.def("IsEmpty", (Standard_Boolean (IntPatch_CurvIntSurf::*)() const) &IntPatch_CurvIntSurf::IsEmpty, "None");
cls_IntPatch_CurvIntSurf.def("Point", (const gp_Pnt & (IntPatch_CurvIntSurf::*)() const) &IntPatch_CurvIntSurf::Point, "returns the intersection point The exception NotDone is raised if IsDone is false. The exception DomainError is raised if IsEmpty is true.");
cls_IntPatch_CurvIntSurf.def("ParameterOnCurve", (Standard_Real (IntPatch_CurvIntSurf::*)() const) &IntPatch_CurvIntSurf::ParameterOnCurve, "None");
cls_IntPatch_CurvIntSurf.def("ParameterOnSurface", [](IntPatch_CurvIntSurf &self, Standard_Real & U, Standard_Real & V){ self.ParameterOnSurface(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_IntPatch_CurvIntSurf.def("Function", (IntPatch_CSFunction & (IntPatch_CurvIntSurf::*)()) &IntPatch_CurvIntSurf::Function, "return the math function which is used to compute the intersection");

// Enums

}