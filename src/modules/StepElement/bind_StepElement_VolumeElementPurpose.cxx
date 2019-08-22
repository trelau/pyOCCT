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
#include <StepElement_EnumeratedVolumeElementPurpose.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepElement_VolumeElementPurpose.hxx>

void bind_StepElement_VolumeElementPurpose(py::module &mod){

py::class_<StepElement_VolumeElementPurpose, StepData_SelectType> cls_StepElement_VolumeElementPurpose(mod, "StepElement_VolumeElementPurpose", "Representation of STEP SELECT type VolumeElementPurpose");

// Constructors
cls_StepElement_VolumeElementPurpose.def(py::init<>());

// Fields

// Methods
// cls_StepElement_VolumeElementPurpose.def_static("operator new_", (void * (*)(size_t)) &StepElement_VolumeElementPurpose::operator new, "None", py::arg("theSize"));
// cls_StepElement_VolumeElementPurpose.def_static("operator delete_", (void (*)(void *)) &StepElement_VolumeElementPurpose::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_VolumeElementPurpose.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_VolumeElementPurpose::operator new[], "None", py::arg("theSize"));
// cls_StepElement_VolumeElementPurpose.def_static("operator delete[]_", (void (*)(void *)) &StepElement_VolumeElementPurpose::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_VolumeElementPurpose.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_VolumeElementPurpose::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_VolumeElementPurpose.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_VolumeElementPurpose::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_VolumeElementPurpose.def("CaseNum", (Standard_Integer (StepElement_VolumeElementPurpose::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_VolumeElementPurpose::CaseNum, "Recognizes a kind of VolumeElementPurpose select type return 0", py::arg("ent"));
cls_StepElement_VolumeElementPurpose.def("CaseMem", (Standard_Integer (StepElement_VolumeElementPurpose::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_VolumeElementPurpose::CaseMem, "Recognizes a items of select member VolumeElementPurposeMember 1 -> EnumeratedVolumeElementPurpose 2 -> ApplicationDefinedElementPurpose 0 else", py::arg("ent"));
cls_StepElement_VolumeElementPurpose.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_VolumeElementPurpose::*)() const) &StepElement_VolumeElementPurpose::NewMember, "Returns a new select member the type VolumeElementPurposeMember");
cls_StepElement_VolumeElementPurpose.def("SetEnumeratedVolumeElementPurpose", (void (StepElement_VolumeElementPurpose::*)(const StepElement_EnumeratedVolumeElementPurpose)) &StepElement_VolumeElementPurpose::SetEnumeratedVolumeElementPurpose, "Set Value for EnumeratedVolumeElementPurpose", py::arg("aVal"));
cls_StepElement_VolumeElementPurpose.def("EnumeratedVolumeElementPurpose", (StepElement_EnumeratedVolumeElementPurpose (StepElement_VolumeElementPurpose::*)() const) &StepElement_VolumeElementPurpose::EnumeratedVolumeElementPurpose, "Returns Value as EnumeratedVolumeElementPurpose (or Null if another type)");
cls_StepElement_VolumeElementPurpose.def("SetApplicationDefinedElementPurpose", (void (StepElement_VolumeElementPurpose::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_VolumeElementPurpose::SetApplicationDefinedElementPurpose, "Set Value for ApplicationDefinedElementPurpose", py::arg("aVal"));
cls_StepElement_VolumeElementPurpose.def("ApplicationDefinedElementPurpose", (opencascade::handle<TCollection_HAsciiString> (StepElement_VolumeElementPurpose::*)() const) &StepElement_VolumeElementPurpose::ApplicationDefinedElementPurpose, "Returns Value as ApplicationDefinedElementPurpose (or Null if another type)");

// Enums

}