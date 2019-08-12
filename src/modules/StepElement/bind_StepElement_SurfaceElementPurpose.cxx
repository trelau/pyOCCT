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
#include <StepElement_EnumeratedSurfaceElementPurpose.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepElement_SurfaceElementPurpose.hxx>

void bind_StepElement_SurfaceElementPurpose(py::module &mod){

py::class_<StepElement_SurfaceElementPurpose, std::unique_ptr<StepElement_SurfaceElementPurpose, Deleter<StepElement_SurfaceElementPurpose>>, StepData_SelectType> cls_StepElement_SurfaceElementPurpose(mod, "StepElement_SurfaceElementPurpose", "Representation of STEP SELECT type SurfaceElementPurpose");

// Constructors
cls_StepElement_SurfaceElementPurpose.def(py::init<>());

// Fields

// Methods
// cls_StepElement_SurfaceElementPurpose.def_static("operator new_", (void * (*)(size_t)) &StepElement_SurfaceElementPurpose::operator new, "None", py::arg("theSize"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator delete_", (void (*)(void *)) &StepElement_SurfaceElementPurpose::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_SurfaceElementPurpose::operator new[], "None", py::arg("theSize"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator delete[]_", (void (*)(void *)) &StepElement_SurfaceElementPurpose::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_SurfaceElementPurpose::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_SurfaceElementPurpose.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_SurfaceElementPurpose::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_SurfaceElementPurpose.def("CaseNum", (Standard_Integer (StepElement_SurfaceElementPurpose::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_SurfaceElementPurpose::CaseNum, "Recognizes a kind of SurfaceElementPurpose select type return 0", py::arg("ent"));
cls_StepElement_SurfaceElementPurpose.def("CaseMem", (Standard_Integer (StepElement_SurfaceElementPurpose::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_SurfaceElementPurpose::CaseMem, "Recognizes a items of select member SurfaceElementPurposeMember 1 -> EnumeratedSurfaceElementPurpose 2 -> ApplicationDefinedElementPurpose 0 else", py::arg("ent"));
cls_StepElement_SurfaceElementPurpose.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_SurfaceElementPurpose::*)() const) &StepElement_SurfaceElementPurpose::NewMember, "Returns a new select member the type SurfaceElementPurposeMember");
cls_StepElement_SurfaceElementPurpose.def("SetEnumeratedSurfaceElementPurpose", (void (StepElement_SurfaceElementPurpose::*)(const StepElement_EnumeratedSurfaceElementPurpose)) &StepElement_SurfaceElementPurpose::SetEnumeratedSurfaceElementPurpose, "Set Value for EnumeratedSurfaceElementPurpose", py::arg("aVal"));
cls_StepElement_SurfaceElementPurpose.def("EnumeratedSurfaceElementPurpose", (StepElement_EnumeratedSurfaceElementPurpose (StepElement_SurfaceElementPurpose::*)() const) &StepElement_SurfaceElementPurpose::EnumeratedSurfaceElementPurpose, "Returns Value as EnumeratedSurfaceElementPurpose (or Null if another type)");
cls_StepElement_SurfaceElementPurpose.def("SetApplicationDefinedElementPurpose", (void (StepElement_SurfaceElementPurpose::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepElement_SurfaceElementPurpose::SetApplicationDefinedElementPurpose, "Set Value for ApplicationDefinedElementPurpose", py::arg("aVal"));
cls_StepElement_SurfaceElementPurpose.def("ApplicationDefinedElementPurpose", (opencascade::handle<TCollection_HAsciiString> (StepElement_SurfaceElementPurpose::*)() const) &StepElement_SurfaceElementPurpose::ApplicationDefinedElementPurpose, "Returns Value as ApplicationDefinedElementPurpose (or Null if another type)");

// Enums

}