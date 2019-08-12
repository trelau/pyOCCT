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
#include <Transfer_SequenceOfBinder.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Transfer_HSequenceOfBinder.hxx>
#include <Standard_Type.hxx>

void bind_Transfer_HSequenceOfBinder(py::module &mod){

py::class_<Transfer_HSequenceOfBinder, opencascade::handle<Transfer_HSequenceOfBinder>, Standard_Transient> cls_Transfer_HSequenceOfBinder(mod, "Transfer_HSequenceOfBinder", "None", py::multiple_inheritance());

// Constructors
cls_Transfer_HSequenceOfBinder.def(py::init<>());
cls_Transfer_HSequenceOfBinder.def(py::init<const Transfer_SequenceOfBinder &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Transfer_HSequenceOfBinder.def_static("operator new_", (void * (*)(size_t)) &Transfer_HSequenceOfBinder::operator new, "None", py::arg("theSize"));
// cls_Transfer_HSequenceOfBinder.def_static("operator delete_", (void (*)(void *)) &Transfer_HSequenceOfBinder::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_HSequenceOfBinder.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_HSequenceOfBinder::operator new[], "None", py::arg("theSize"));
// cls_Transfer_HSequenceOfBinder.def_static("operator delete[]_", (void (*)(void *)) &Transfer_HSequenceOfBinder::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_HSequenceOfBinder.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_HSequenceOfBinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_HSequenceOfBinder.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_HSequenceOfBinder::operator delete, "None", py::arg(""), py::arg(""));
// cls_Transfer_HSequenceOfBinder.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Transfer_HSequenceOfBinder::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Transfer_HSequenceOfBinder.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Transfer_HSequenceOfBinder::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Transfer_HSequenceOfBinder.def("Sequence", (const Transfer_SequenceOfBinder & (Transfer_HSequenceOfBinder::*)() const) &Transfer_HSequenceOfBinder::Sequence, "None");
cls_Transfer_HSequenceOfBinder.def("Append", (void (Transfer_HSequenceOfBinder::*)(const Transfer_SequenceOfBinder::value_type &)) &Transfer_HSequenceOfBinder::Append, "None", py::arg("theItem"));
cls_Transfer_HSequenceOfBinder.def("Append", (void (Transfer_HSequenceOfBinder::*)(Transfer_SequenceOfBinder &)) &Transfer_HSequenceOfBinder::Append, "None", py::arg("theSequence"));
cls_Transfer_HSequenceOfBinder.def("ChangeSequence", (Transfer_SequenceOfBinder & (Transfer_HSequenceOfBinder::*)()) &Transfer_HSequenceOfBinder::ChangeSequence, "None");
cls_Transfer_HSequenceOfBinder.def_static("get_type_name_", (const char * (*)()) &Transfer_HSequenceOfBinder::get_type_name, "None");
cls_Transfer_HSequenceOfBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_HSequenceOfBinder::get_type_descriptor, "None");
cls_Transfer_HSequenceOfBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_HSequenceOfBinder::*)() const) &Transfer_HSequenceOfBinder::DynamicType, "None");

// Enums

}