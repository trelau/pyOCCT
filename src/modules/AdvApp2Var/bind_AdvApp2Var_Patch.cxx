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
#include <AdvApp2Var_Context.hxx>
#include <AdvApp2Var_Framework.hxx>
#include <AdvApp2Var_EvaluatorFunc2Var.hxx>
#include <AdvApp2Var_Criterion.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <AdvApp2Var_Patch.hxx>

void bind_AdvApp2Var_Patch(py::module &mod){

py::class_<AdvApp2Var_Patch> cls_AdvApp2Var_Patch(mod, "AdvApp2Var_Patch", "used to store results on a domain [Ui,Ui+1]x[Vj,Vj+1]");

// Constructors
cls_AdvApp2Var_Patch.def(py::init<>());
cls_AdvApp2Var_Patch.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("U0"), py::arg("U1"), py::arg("V0"), py::arg("V1"), py::arg("iu"), py::arg("iv"));

// Fields

// Methods
// cls_AdvApp2Var_Patch.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Patch::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Patch.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Patch::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Patch.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Patch::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Patch.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Patch::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Patch.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Patch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Patch.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Patch::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Patch.def("IsDiscretised", (Standard_Boolean (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::IsDiscretised, "None");
cls_AdvApp2Var_Patch.def("Discretise", (void (AdvApp2Var_Patch::*)(const AdvApp2Var_Context &, const AdvApp2Var_Framework &, const AdvApp2Var_EvaluatorFunc2Var &)) &AdvApp2Var_Patch::Discretise, "None", py::arg("Conditions"), py::arg("Constraints"), py::arg("func"));
cls_AdvApp2Var_Patch.def("IsApproximated", (Standard_Boolean (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::IsApproximated, "None");
cls_AdvApp2Var_Patch.def("HasResult", (Standard_Boolean (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::HasResult, "None");
cls_AdvApp2Var_Patch.def("MakeApprox", (void (AdvApp2Var_Patch::*)(const AdvApp2Var_Context &, const AdvApp2Var_Framework &, const Standard_Integer)) &AdvApp2Var_Patch::MakeApprox, "None", py::arg("Conditions"), py::arg("Constraints"), py::arg("NumDec"));
cls_AdvApp2Var_Patch.def("AddConstraints", (void (AdvApp2Var_Patch::*)(const AdvApp2Var_Context &, const AdvApp2Var_Framework &)) &AdvApp2Var_Patch::AddConstraints, "None", py::arg("Conditions"), py::arg("Constraints"));
cls_AdvApp2Var_Patch.def("AddErrors", (void (AdvApp2Var_Patch::*)(const AdvApp2Var_Framework &)) &AdvApp2Var_Patch::AddErrors, "None", py::arg("Constraints"));
cls_AdvApp2Var_Patch.def("ChangeDomain", (void (AdvApp2Var_Patch::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AdvApp2Var_Patch::ChangeDomain, "None", py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"));
cls_AdvApp2Var_Patch.def("ResetApprox", (void (AdvApp2Var_Patch::*)()) &AdvApp2Var_Patch::ResetApprox, "None");
cls_AdvApp2Var_Patch.def("OverwriteApprox", (void (AdvApp2Var_Patch::*)()) &AdvApp2Var_Patch::OverwriteApprox, "None");
cls_AdvApp2Var_Patch.def("U0", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::U0, "None");
cls_AdvApp2Var_Patch.def("U1", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::U1, "None");
cls_AdvApp2Var_Patch.def("V0", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::V0, "None");
cls_AdvApp2Var_Patch.def("V1", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::V1, "None");
cls_AdvApp2Var_Patch.def("UOrder", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::UOrder, "None");
cls_AdvApp2Var_Patch.def("VOrder", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::VOrder, "None");
cls_AdvApp2Var_Patch.def("CutSense", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::CutSense, "None");
cls_AdvApp2Var_Patch.def("CutSense", (Standard_Integer (AdvApp2Var_Patch::*)(const AdvApp2Var_Criterion &, const Standard_Integer) const) &AdvApp2Var_Patch::CutSense, "None", py::arg("Crit"), py::arg("NumDec"));
cls_AdvApp2Var_Patch.def("NbCoeffInU", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::NbCoeffInU, "None");
cls_AdvApp2Var_Patch.def("NbCoeffInV", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::NbCoeffInV, "None");
cls_AdvApp2Var_Patch.def("ChangeNbCoeff", (void (AdvApp2Var_Patch::*)(const Standard_Integer, const Standard_Integer)) &AdvApp2Var_Patch::ChangeNbCoeff, "None", py::arg("NbCoeffU"), py::arg("NbCoeffV"));
cls_AdvApp2Var_Patch.def("Poles", (opencascade::handle<TColgp_HArray2OfPnt> (AdvApp2Var_Patch::*)(const Standard_Integer, const AdvApp2Var_Context &) const) &AdvApp2Var_Patch::Poles, "None", py::arg("SSPIndex"), py::arg("Conditions"));
cls_AdvApp2Var_Patch.def("Coefficients", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Patch::*)(const Standard_Integer, const AdvApp2Var_Context &) const) &AdvApp2Var_Patch::Coefficients, "None", py::arg("SSPIndex"), py::arg("Conditions"));
cls_AdvApp2Var_Patch.def("MaxErrors", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::MaxErrors, "None");
cls_AdvApp2Var_Patch.def("AverageErrors", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::AverageErrors, "None");
cls_AdvApp2Var_Patch.def("IsoErrors", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::IsoErrors, "None");
cls_AdvApp2Var_Patch.def("CritValue", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::CritValue, "None");
cls_AdvApp2Var_Patch.def("SetCritValue", (void (AdvApp2Var_Patch::*)(const Standard_Real)) &AdvApp2Var_Patch::SetCritValue, "None", py::arg("dist"));

// Enums

}