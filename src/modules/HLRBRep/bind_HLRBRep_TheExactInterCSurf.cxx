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
#include <HLRBRep_TheCSFunctionOfInterCSurf.hxx>
#include <math_FunctionSetRoot.hxx>
#include <gp_Pnt.hxx>
#include <HLRBRep_TheExactInterCSurf.hxx>

void bind_HLRBRep_TheExactInterCSurf(py::module &mod){

py::class_<HLRBRep_TheExactInterCSurf> cls_HLRBRep_TheExactInterCSurf(mod, "HLRBRep_TheExactInterCSurf", "None");

// Constructors
cls_HLRBRep_TheExactInterCSurf.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const HLRBRep_TheCSFunctionOfInterCSurf &, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"));
cls_HLRBRep_TheExactInterCSurf.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const HLRBRep_TheCSFunctionOfInterCSurf &, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"), py::arg("MarginCoef"));
cls_HLRBRep_TheExactInterCSurf.def(py::init<const HLRBRep_TheCSFunctionOfInterCSurf &, const Standard_Real>(), py::arg("F"), py::arg("TolTangency"));

// Fields

// Methods
// cls_HLRBRep_TheExactInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheExactInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheExactInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheExactInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheExactInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheExactInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheExactInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheExactInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheExactInterCSurf.def("Perform", (void (HLRBRep_TheExactInterCSurf::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_FunctionSetRoot &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRBRep_TheExactInterCSurf::Perform, "compute the solution it's possible to write to optimize: IntImp_IntCS inter(S1,C1,Toltangency) math_FunctionSetRoot rsnld(Inter.function()) while ...{ u=... v=... w=... inter.Perform(u,v,w,rsnld) } or IntImp_IntCS inter(Toltangency) inter.SetSurface(S); math_FunctionSetRoot rsnld(Inter.function()) while ...{ C=... inter.SetCurve(C); u=... v=... w=... inter.Perform(u,v,w,rsnld) }", py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Rsnld"), py::arg("u0"), py::arg("v0"), py::arg("u1"), py::arg("v1"), py::arg("w0"), py::arg("w1"));
cls_HLRBRep_TheExactInterCSurf.def("IsDone", (Standard_Boolean (HLRBRep_TheExactInterCSurf::*)() const) &HLRBRep_TheExactInterCSurf::IsDone, "Returns TRUE if the creation completed without failure.");
cls_HLRBRep_TheExactInterCSurf.def("IsEmpty", (Standard_Boolean (HLRBRep_TheExactInterCSurf::*)() const) &HLRBRep_TheExactInterCSurf::IsEmpty, "None");
cls_HLRBRep_TheExactInterCSurf.def("Point", (const gp_Pnt & (HLRBRep_TheExactInterCSurf::*)() const) &HLRBRep_TheExactInterCSurf::Point, "returns the intersection point The exception NotDone is raised if IsDone is false. The exception DomainError is raised if IsEmpty is true.");
cls_HLRBRep_TheExactInterCSurf.def("ParameterOnCurve", (Standard_Real (HLRBRep_TheExactInterCSurf::*)() const) &HLRBRep_TheExactInterCSurf::ParameterOnCurve, "None");
cls_HLRBRep_TheExactInterCSurf.def("ParameterOnSurface", [](HLRBRep_TheExactInterCSurf &self, Standard_Real & U, Standard_Real & V){ self.ParameterOnSurface(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_HLRBRep_TheExactInterCSurf.def("Function", (HLRBRep_TheCSFunctionOfInterCSurf & (HLRBRep_TheExactInterCSurf::*)()) &HLRBRep_TheExactInterCSurf::Function, "return the math function which is used to compute the intersection");

// Enums

}