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
#include <StepFEA_SequenceOfElementRepresentation.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <StepFEA_HSequenceOfElementRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_HSequenceOfElementRepresentation(py::module &mod){

py::class_<StepFEA_HSequenceOfElementRepresentation, opencascade::handle<StepFEA_HSequenceOfElementRepresentation>, Standard_Transient> cls_StepFEA_HSequenceOfElementRepresentation(mod, "StepFEA_HSequenceOfElementRepresentation", "None", py::multiple_inheritance());

// Constructors
cls_StepFEA_HSequenceOfElementRepresentation.def(py::init<>());
cls_StepFEA_HSequenceOfElementRepresentation.def(py::init<const StepFEA_SequenceOfElementRepresentation &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepFEA_HSequenceOfElementRepresentation.def_static("operator new_", (void * (*)(size_t)) &StepFEA_HSequenceOfElementRepresentation::operator new, "None", py::arg("theSize"));
// cls_StepFEA_HSequenceOfElementRepresentation.def_static("operator delete_", (void (*)(void *)) &StepFEA_HSequenceOfElementRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_StepFEA_HSequenceOfElementRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &StepFEA_HSequenceOfElementRepresentation::operator new[], "None", py::arg("theSize"));
// cls_StepFEA_HSequenceOfElementRepresentation.def_static("operator delete[]_", (void (*)(void *)) &StepFEA_HSequenceOfElementRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_StepFEA_HSequenceOfElementRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &StepFEA_HSequenceOfElementRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepFEA_HSequenceOfElementRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &StepFEA_HSequenceOfElementRepresentation::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepFEA_HSequenceOfElementRepresentation.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepFEA_HSequenceOfElementRepresentation::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepFEA_HSequenceOfElementRepresentation.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepFEA_HSequenceOfElementRepresentation::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepFEA_HSequenceOfElementRepresentation.def("Sequence", (const StepFEA_SequenceOfElementRepresentation & (StepFEA_HSequenceOfElementRepresentation::*)() const) &StepFEA_HSequenceOfElementRepresentation::Sequence, "None");
cls_StepFEA_HSequenceOfElementRepresentation.def("Append", (void (StepFEA_HSequenceOfElementRepresentation::*)(const StepFEA_SequenceOfElementRepresentation::value_type &)) &StepFEA_HSequenceOfElementRepresentation::Append, "None", py::arg("theItem"));
cls_StepFEA_HSequenceOfElementRepresentation.def("Append", (void (StepFEA_HSequenceOfElementRepresentation::*)(StepFEA_SequenceOfElementRepresentation &)) &StepFEA_HSequenceOfElementRepresentation::Append, "None", py::arg("theSequence"));
cls_StepFEA_HSequenceOfElementRepresentation.def("ChangeSequence", (StepFEA_SequenceOfElementRepresentation & (StepFEA_HSequenceOfElementRepresentation::*)()) &StepFEA_HSequenceOfElementRepresentation::ChangeSequence, "None");
cls_StepFEA_HSequenceOfElementRepresentation.def_static("get_type_name_", (const char * (*)()) &StepFEA_HSequenceOfElementRepresentation::get_type_name, "None");
cls_StepFEA_HSequenceOfElementRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_HSequenceOfElementRepresentation::get_type_descriptor, "None");
cls_StepFEA_HSequenceOfElementRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_HSequenceOfElementRepresentation::*)() const) &StepFEA_HSequenceOfElementRepresentation::DynamicType, "None");

// Enums

}