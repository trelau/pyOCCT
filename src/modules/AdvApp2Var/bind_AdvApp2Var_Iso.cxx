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
#include <GeomAbs_IsoType.hxx>
#include <Standard_TypeDef.hxx>
#include <AdvApp2Var_Context.hxx>
#include <AdvApp2Var_EvaluatorFunc2Var.hxx>
#include <AdvApp2Var_Node.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <AdvApp2Var_Iso.hxx>

void bind_AdvApp2Var_Iso(py::module &mod){

py::class_<AdvApp2Var_Iso, std::unique_ptr<AdvApp2Var_Iso, Deleter<AdvApp2Var_Iso>>> cls_AdvApp2Var_Iso(mod, "AdvApp2Var_Iso", "used to store constraints on a line U = Ui or V = Vj");

// Constructors
cls_AdvApp2Var_Iso.def(py::init<>());
// cls_AdvApp2Var_Iso.def(py::init<const GeomAbs_IsoType, const Standard_Integer, const Standard_Integer>(), py::arg("type"), py::arg("iu"), py::arg("iv"));
cls_AdvApp2Var_Iso.def(py::init<const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("type"), py::arg("cte"), py::arg("Ufirst"), py::arg("Ulast"), py::arg("Vfirst"), py::arg("Vlast"), py::arg("pos"), py::arg("iu"), py::arg("iv"));

// Fields

// Methods
// cls_AdvApp2Var_Iso.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Iso::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Iso.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Iso::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Iso.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Iso::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Iso.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Iso::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Iso.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Iso::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Iso.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Iso::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Iso.def("IsApproximated", (Standard_Boolean (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::IsApproximated, "None");
cls_AdvApp2Var_Iso.def("HasResult", (Standard_Boolean (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::HasResult, "None");
cls_AdvApp2Var_Iso.def("MakeApprox", (void (AdvApp2Var_Iso::*)(const AdvApp2Var_Context &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const AdvApp2Var_EvaluatorFunc2Var &, AdvApp2Var_Node &, AdvApp2Var_Node &)) &AdvApp2Var_Iso::MakeApprox, "None", py::arg("Conditions"), py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"), py::arg("func"), py::arg("NodeBegin"), py::arg("NodeEnd"));
cls_AdvApp2Var_Iso.def("ChangeDomain", (void (AdvApp2Var_Iso::*)(const Standard_Real, const Standard_Real)) &AdvApp2Var_Iso::ChangeDomain, "None", py::arg("a"), py::arg("b"));
cls_AdvApp2Var_Iso.def("ChangeDomain", (void (AdvApp2Var_Iso::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AdvApp2Var_Iso::ChangeDomain, "None", py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"));
cls_AdvApp2Var_Iso.def("SetConstante", (void (AdvApp2Var_Iso::*)(const Standard_Real)) &AdvApp2Var_Iso::SetConstante, "None", py::arg("newcte"));
cls_AdvApp2Var_Iso.def("SetPosition", (void (AdvApp2Var_Iso::*)(const Standard_Integer)) &AdvApp2Var_Iso::SetPosition, "None", py::arg("newpos"));
cls_AdvApp2Var_Iso.def("ResetApprox", (void (AdvApp2Var_Iso::*)()) &AdvApp2Var_Iso::ResetApprox, "None");
cls_AdvApp2Var_Iso.def("OverwriteApprox", (void (AdvApp2Var_Iso::*)()) &AdvApp2Var_Iso::OverwriteApprox, "None");
cls_AdvApp2Var_Iso.def("Type", (GeomAbs_IsoType (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::Type, "None");
cls_AdvApp2Var_Iso.def("Constante", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::Constante, "None");
cls_AdvApp2Var_Iso.def("T0", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::T0, "None");
cls_AdvApp2Var_Iso.def("T1", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::T1, "None");
cls_AdvApp2Var_Iso.def("U0", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::U0, "None");
cls_AdvApp2Var_Iso.def("U1", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::U1, "None");
cls_AdvApp2Var_Iso.def("V0", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::V0, "None");
cls_AdvApp2Var_Iso.def("V1", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::V1, "None");
cls_AdvApp2Var_Iso.def("UOrder", (Standard_Integer (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::UOrder, "None");
cls_AdvApp2Var_Iso.def("VOrder", (Standard_Integer (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::VOrder, "None");
cls_AdvApp2Var_Iso.def("Position", (Standard_Integer (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::Position, "None");
cls_AdvApp2Var_Iso.def("NbCoeff", (Standard_Integer (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::NbCoeff, "None");
cls_AdvApp2Var_Iso.def("Polynom", (const opencascade::handle<TColStd_HArray1OfReal> & (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::Polynom, "None");
cls_AdvApp2Var_Iso.def("SomTab", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::SomTab, "None");
cls_AdvApp2Var_Iso.def("DifTab", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::DifTab, "None");
cls_AdvApp2Var_Iso.def("MaxErrors", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::MaxErrors, "None");
cls_AdvApp2Var_Iso.def("MoyErrors", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::MoyErrors, "None");

// Enums

}