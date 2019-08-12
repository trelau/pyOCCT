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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepData_SelectMember.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepGeom_TrimmingSelect.hxx>

void bind_StepGeom_TrimmingSelect(py::module &mod){

py::class_<StepGeom_TrimmingSelect, std::unique_ptr<StepGeom_TrimmingSelect, Deleter<StepGeom_TrimmingSelect>>, StepData_SelectType> cls_StepGeom_TrimmingSelect(mod, "StepGeom_TrimmingSelect", "None");

// Constructors
cls_StepGeom_TrimmingSelect.def(py::init<>());

// Fields

// Methods
// cls_StepGeom_TrimmingSelect.def_static("operator new_", (void * (*)(size_t)) &StepGeom_TrimmingSelect::operator new, "None", py::arg("theSize"));
// cls_StepGeom_TrimmingSelect.def_static("operator delete_", (void (*)(void *)) &StepGeom_TrimmingSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_TrimmingSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_TrimmingSelect::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_TrimmingSelect.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_TrimmingSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_TrimmingSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_TrimmingSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_TrimmingSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_TrimmingSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_TrimmingSelect.def("CaseNum", (Standard_Integer (StepGeom_TrimmingSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_TrimmingSelect::CaseNum, "Recognizes a TrimmingSelect Kind Entity that is : 1 -> CartesianPoint 0 else (i.e. Real)", py::arg("ent"));
cls_StepGeom_TrimmingSelect.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepGeom_TrimmingSelect::*)() const) &StepGeom_TrimmingSelect::NewMember, "Returns a TrimmingMember (for PARAMETER_VALUE) as preferred");
cls_StepGeom_TrimmingSelect.def("CaseMem", (Standard_Integer (StepGeom_TrimmingSelect::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepGeom_TrimmingSelect::CaseMem, "Recognizes a SelectMember as Real, named as PARAMETER_VALUE 1 -> ParameterValue i.e. Real 0 else (i.e. Entity)", py::arg("ent"));
cls_StepGeom_TrimmingSelect.def("CartesianPoint", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_TrimmingSelect::*)() const) &StepGeom_TrimmingSelect::CartesianPoint, "returns Value as a CartesianPoint (Null if another type)");
cls_StepGeom_TrimmingSelect.def("SetParameterValue", (void (StepGeom_TrimmingSelect::*)(const Standard_Real)) &StepGeom_TrimmingSelect::SetParameterValue, "sets the ParameterValue as Real", py::arg("aParameterValue"));
cls_StepGeom_TrimmingSelect.def("ParameterValue", (Standard_Real (StepGeom_TrimmingSelect::*)() const) &StepGeom_TrimmingSelect::ParameterValue, "returns Value as a Real (0.0 if not a Real)");

// Enums

}