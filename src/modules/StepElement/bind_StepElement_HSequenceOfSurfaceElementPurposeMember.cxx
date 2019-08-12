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
#include <StepElement_SequenceOfSurfaceElementPurposeMember.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <StepElement_HSequenceOfSurfaceElementPurposeMember.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_HSequenceOfSurfaceElementPurposeMember(py::module &mod){

py::class_<StepElement_HSequenceOfSurfaceElementPurposeMember, opencascade::handle<StepElement_HSequenceOfSurfaceElementPurposeMember>, Standard_Transient> cls_StepElement_HSequenceOfSurfaceElementPurposeMember(mod, "StepElement_HSequenceOfSurfaceElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def(py::init<>());
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def(py::init<const StepElement_SequenceOfSurfaceElementPurposeMember &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("Sequence", (const StepElement_SequenceOfSurfaceElementPurposeMember & (StepElement_HSequenceOfSurfaceElementPurposeMember::*)() const) &StepElement_HSequenceOfSurfaceElementPurposeMember::Sequence, "None");
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("Append", (void (StepElement_HSequenceOfSurfaceElementPurposeMember::*)(const StepElement_SequenceOfSurfaceElementPurposeMember::value_type &)) &StepElement_HSequenceOfSurfaceElementPurposeMember::Append, "None", py::arg("theItem"));
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("Append", (void (StepElement_HSequenceOfSurfaceElementPurposeMember::*)(StepElement_SequenceOfSurfaceElementPurposeMember &)) &StepElement_HSequenceOfSurfaceElementPurposeMember::Append, "None", py::arg("theSequence"));
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("ChangeSequence", (StepElement_SequenceOfSurfaceElementPurposeMember & (StepElement_HSequenceOfSurfaceElementPurposeMember::*)()) &StepElement_HSequenceOfSurfaceElementPurposeMember::ChangeSequence, "None");
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HSequenceOfSurfaceElementPurposeMember::get_type_name, "None");
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HSequenceOfSurfaceElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HSequenceOfSurfaceElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HSequenceOfSurfaceElementPurposeMember::*)() const) &StepElement_HSequenceOfSurfaceElementPurposeMember::DynamicType, "None");

// Enums

}