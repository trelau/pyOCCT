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
#include <StepFEA_EnumeratedDegreeOfFreedom.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepFEA_DegreeOfFreedom.hxx>

void bind_StepFEA_DegreeOfFreedom(py::module &mod){

py::class_<StepFEA_DegreeOfFreedom, std::unique_ptr<StepFEA_DegreeOfFreedom>, StepData_SelectType> cls_StepFEA_DegreeOfFreedom(mod, "StepFEA_DegreeOfFreedom", "Representation of STEP SELECT type DegreeOfFreedom");

// Constructors
cls_StepFEA_DegreeOfFreedom.def(py::init<>());

// Fields

// Methods
// cls_StepFEA_DegreeOfFreedom.def_static("operator new_", (void * (*)(size_t)) &StepFEA_DegreeOfFreedom::operator new, "None", py::arg("theSize"));
// cls_StepFEA_DegreeOfFreedom.def_static("operator delete_", (void (*)(void *)) &StepFEA_DegreeOfFreedom::operator delete, "None", py::arg("theAddress"));
// cls_StepFEA_DegreeOfFreedom.def_static("operator new[]_", (void * (*)(size_t)) &StepFEA_DegreeOfFreedom::operator new[], "None", py::arg("theSize"));
// cls_StepFEA_DegreeOfFreedom.def_static("operator delete[]_", (void (*)(void *)) &StepFEA_DegreeOfFreedom::operator delete[], "None", py::arg("theAddress"));
// cls_StepFEA_DegreeOfFreedom.def_static("operator new_", (void * (*)(size_t, void *)) &StepFEA_DegreeOfFreedom::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepFEA_DegreeOfFreedom.def_static("operator delete_", (void (*)(void *, void *)) &StepFEA_DegreeOfFreedom::operator delete, "None", py::arg(""), py::arg(""));
cls_StepFEA_DegreeOfFreedom.def("CaseNum", (Standard_Integer (StepFEA_DegreeOfFreedom::*)(const opencascade::handle<Standard_Transient> &) const) &StepFEA_DegreeOfFreedom::CaseNum, "Recognizes a kind of CurveElementFreedom select type return 0", py::arg("ent"));
cls_StepFEA_DegreeOfFreedom.def("CaseMem", (Standard_Integer (StepFEA_DegreeOfFreedom::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepFEA_DegreeOfFreedom::CaseMem, "Recognizes a items of select member CurveElementFreedomMember 1 -> EnumeratedCurveElementFreedom 2 -> ApplicationDefinedDegreeOfFreedom 0 else", py::arg("ent"));
cls_StepFEA_DegreeOfFreedom.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepFEA_DegreeOfFreedom::*)() const) &StepFEA_DegreeOfFreedom::NewMember, "Returns a new select member the type CurveElementFreedomMember");
cls_StepFEA_DegreeOfFreedom.def("SetEnumeratedDegreeOfFreedom", (void (StepFEA_DegreeOfFreedom::*)(const StepFEA_EnumeratedDegreeOfFreedom)) &StepFEA_DegreeOfFreedom::SetEnumeratedDegreeOfFreedom, "Returns Value as EnumeratedDegreeOfFreedom (or Null if another type)", py::arg("aVal"));
cls_StepFEA_DegreeOfFreedom.def("EnumeratedDegreeOfFreedom", (StepFEA_EnumeratedDegreeOfFreedom (StepFEA_DegreeOfFreedom::*)() const) &StepFEA_DegreeOfFreedom::EnumeratedDegreeOfFreedom, "Returns Value as EnumeratedDegreeOfFreedom (or Null if another type)");
cls_StepFEA_DegreeOfFreedom.def("SetApplicationDefinedDegreeOfFreedom", (void (StepFEA_DegreeOfFreedom::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepFEA_DegreeOfFreedom::SetApplicationDefinedDegreeOfFreedom, "Set Value for ApplicationDefinedDegreeOfFreedom", py::arg("aVal"));
cls_StepFEA_DegreeOfFreedom.def("ApplicationDefinedDegreeOfFreedom", (opencascade::handle<TCollection_HAsciiString> (StepFEA_DegreeOfFreedom::*)() const) &StepFEA_DegreeOfFreedom::ApplicationDefinedDegreeOfFreedom, "Returns Value as ApplicationDefinedDegreeOfFreedom (or Null if another type)");

// Enums

}