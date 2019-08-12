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
#include <StepElement_SequenceOfCurveElementPurposeMember.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <StepElement_HSequenceOfCurveElementPurposeMember.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_HSequenceOfCurveElementPurposeMember(py::module &mod){

py::class_<StepElement_HSequenceOfCurveElementPurposeMember, opencascade::handle<StepElement_HSequenceOfCurveElementPurposeMember>, Standard_Transient> cls_StepElement_HSequenceOfCurveElementPurposeMember(mod, "StepElement_HSequenceOfCurveElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HSequenceOfCurveElementPurposeMember.def(py::init<>());
cls_StepElement_HSequenceOfCurveElementPurposeMember.def(py::init<const StepElement_SequenceOfCurveElementPurposeMember &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HSequenceOfCurveElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HSequenceOfCurveElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HSequenceOfCurveElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HSequenceOfCurveElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfCurveElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("Sequence", (const StepElement_SequenceOfCurveElementPurposeMember & (StepElement_HSequenceOfCurveElementPurposeMember::*)() const) &StepElement_HSequenceOfCurveElementPurposeMember::Sequence, "None");
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("Append", (void (StepElement_HSequenceOfCurveElementPurposeMember::*)(const StepElement_SequenceOfCurveElementPurposeMember::value_type &)) &StepElement_HSequenceOfCurveElementPurposeMember::Append, "None", py::arg("theItem"));
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("Append", (void (StepElement_HSequenceOfCurveElementPurposeMember::*)(StepElement_SequenceOfCurveElementPurposeMember &)) &StepElement_HSequenceOfCurveElementPurposeMember::Append, "None", py::arg("theSequence"));
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("ChangeSequence", (StepElement_SequenceOfCurveElementPurposeMember & (StepElement_HSequenceOfCurveElementPurposeMember::*)()) &StepElement_HSequenceOfCurveElementPurposeMember::ChangeSequence, "None");
cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HSequenceOfCurveElementPurposeMember::get_type_name, "None");
cls_StepElement_HSequenceOfCurveElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HSequenceOfCurveElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HSequenceOfCurveElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HSequenceOfCurveElementPurposeMember::*)() const) &StepElement_HSequenceOfCurveElementPurposeMember::DynamicType, "None");

// Enums

}