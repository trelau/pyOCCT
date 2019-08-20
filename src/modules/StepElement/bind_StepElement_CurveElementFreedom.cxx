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
#include <StepElement_EnumeratedCurveElementFreedom.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepElement_CurveElementFreedom.hxx>

void bind_StepElement_CurveElementFreedom(py::module &mod){

py::class_<StepElement_CurveElementFreedom, std::unique_ptr<StepElement_CurveElementFreedom>, StepData_SelectType> cls_StepElement_CurveElementFreedom(mod, "StepElement_CurveElementFreedom", "Representation of STEP SELECT type CurveElementFreedom");

// Constructors
cls_StepElement_CurveElementFreedom.def(py::init<>());

// Fields

// Methods
// cls_StepElement_CurveElementFreedom.def_static("operator new_", (void * (*)(size_t)) &StepElement_CurveElementFreedom::operator new, "None", py::arg("theSize"));
// cls_StepElement_CurveElementFreedom.def_static("operator delete_", (void (*)(void *)) &StepElement_CurveElementFreedom::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_CurveElementFreedom.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_CurveElementFreedom::operator new[], "None", py::arg("theSize"));
// cls_StepElement_CurveElementFreedom.def_static("operator delete[]_", (void (*)(void *)) &StepElement_CurveElementFreedom::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_CurveElementFreedom.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_CurveElementFreedom::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_CurveElementFreedom.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_CurveElementFreedom::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_CurveElementFreedom.def("CaseNum", (Standard_Integer (StepElement_CurveElementFreedom::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_CurveElementFreedom::CaseNum, "Recognizes a kind of CurveElementFreedom select type return 0", py::arg("ent"));
cls_StepElement_CurveElementFreedom.def("CaseMem", (Standard_Integer (StepElement_CurveElementFreedom::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_CurveElementFreedom::CaseMem, "Recognizes a items of select member CurveElementFreedomMember 1 -> EnumeratedCurveElementFreedom 2 -> ApplicationDefinedDegreeOfFreedom 0 else", py::arg("ent"));
cls_StepElement_CurveElementFreedom.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_CurveElementFreedom::*)() const) &StepElement_CurveElementFreedom::NewMember, "Returns a new select member the type CurveElementFreedomMember");
cls_StepElement_CurveElementFreedom.def("SetEnumeratedCurveElementFreedom", (void (StepElement_CurveElementFreedom::*)(const StepElement_EnumeratedCurveElementFreedom)) &StepElement_CurveElementFreedom::SetEnumeratedCurveElementFreedom, "Set Value for EnumeratedCurveElementFreedom", py::arg("aVal"));
cls_StepElement_CurveElementFreedom.def("EnumeratedCurveElementFreedom", (StepElement_EnumeratedCurveElementFreedom (StepElement_CurveElementFreedom::*)() const) &StepElement_CurveElementFreedom::EnumeratedCurveElementFreedom, "Returns Value as EnumeratedCurveElementFreedom (or Null if another type)");
cls_StepElement_CurveElementFreedom.def("SetApplicationDefinedDegreeOfFreedom", (void (StepElement_CurveElementFreedom::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_CurveElementFreedom::SetApplicationDefinedDegreeOfFreedom, "Set Value for ApplicationDefinedDegreeOfFreedom", py::arg("aVal"));
cls_StepElement_CurveElementFreedom.def("ApplicationDefinedDegreeOfFreedom", (opencascade::handle<TCollection_HAsciiString> (StepElement_CurveElementFreedom::*)() const) &StepElement_CurveElementFreedom::ApplicationDefinedDegreeOfFreedom, "Returns Value as ApplicationDefinedDegreeOfFreedom (or Null if another type)");

// Enums

}