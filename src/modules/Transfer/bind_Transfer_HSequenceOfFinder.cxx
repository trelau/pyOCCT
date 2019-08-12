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
#include <Transfer_SequenceOfFinder.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Transfer_HSequenceOfFinder.hxx>
#include <Standard_Type.hxx>

void bind_Transfer_HSequenceOfFinder(py::module &mod){

py::class_<Transfer_HSequenceOfFinder, opencascade::handle<Transfer_HSequenceOfFinder>, Standard_Transient> cls_Transfer_HSequenceOfFinder(mod, "Transfer_HSequenceOfFinder", "None", py::multiple_inheritance());

// Constructors
cls_Transfer_HSequenceOfFinder.def(py::init<>());
cls_Transfer_HSequenceOfFinder.def(py::init<const Transfer_SequenceOfFinder &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Transfer_HSequenceOfFinder.def_static("operator new_", (void * (*)(size_t)) &Transfer_HSequenceOfFinder::operator new, "None", py::arg("theSize"));
// cls_Transfer_HSequenceOfFinder.def_static("operator delete_", (void (*)(void *)) &Transfer_HSequenceOfFinder::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_HSequenceOfFinder.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_HSequenceOfFinder::operator new[], "None", py::arg("theSize"));
// cls_Transfer_HSequenceOfFinder.def_static("operator delete[]_", (void (*)(void *)) &Transfer_HSequenceOfFinder::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_HSequenceOfFinder.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_HSequenceOfFinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_HSequenceOfFinder.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_HSequenceOfFinder::operator delete, "None", py::arg(""), py::arg(""));
// cls_Transfer_HSequenceOfFinder.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Transfer_HSequenceOfFinder::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Transfer_HSequenceOfFinder.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Transfer_HSequenceOfFinder::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Transfer_HSequenceOfFinder.def("Sequence", (const Transfer_SequenceOfFinder & (Transfer_HSequenceOfFinder::*)() const) &Transfer_HSequenceOfFinder::Sequence, "None");
cls_Transfer_HSequenceOfFinder.def("Append", (void (Transfer_HSequenceOfFinder::*)(const Transfer_SequenceOfFinder::value_type &)) &Transfer_HSequenceOfFinder::Append, "None", py::arg("theItem"));
cls_Transfer_HSequenceOfFinder.def("Append", (void (Transfer_HSequenceOfFinder::*)(Transfer_SequenceOfFinder &)) &Transfer_HSequenceOfFinder::Append, "None", py::arg("theSequence"));
cls_Transfer_HSequenceOfFinder.def("ChangeSequence", (Transfer_SequenceOfFinder & (Transfer_HSequenceOfFinder::*)()) &Transfer_HSequenceOfFinder::ChangeSequence, "None");
cls_Transfer_HSequenceOfFinder.def_static("get_type_name_", (const char * (*)()) &Transfer_HSequenceOfFinder::get_type_name, "None");
cls_Transfer_HSequenceOfFinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_HSequenceOfFinder::get_type_descriptor, "None");
cls_Transfer_HSequenceOfFinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_HSequenceOfFinder::*)() const) &Transfer_HSequenceOfFinder::DynamicType, "None");

// Enums

}