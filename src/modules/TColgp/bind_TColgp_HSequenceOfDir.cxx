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
#include <TColgp_SequenceOfDir.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TColgp_HSequenceOfDir.hxx>
#include <Standard_Type.hxx>

void bind_TColgp_HSequenceOfDir(py::module &mod){

py::class_<TColgp_HSequenceOfDir, opencascade::handle<TColgp_HSequenceOfDir>, Standard_Transient> cls_TColgp_HSequenceOfDir(mod, "TColgp_HSequenceOfDir", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfDir.def(py::init<>());
cls_TColgp_HSequenceOfDir.def(py::init<const TColgp_SequenceOfDir &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColgp_HSequenceOfDir.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfDir::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfDir.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfDir::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfDir.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfDir::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfDir.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfDir::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfDir.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfDir::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfDir.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfDir::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfDir.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfDir::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfDir.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfDir::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfDir.def("Sequence", (const TColgp_SequenceOfDir & (TColgp_HSequenceOfDir::*)() const) &TColgp_HSequenceOfDir::Sequence, "None");
cls_TColgp_HSequenceOfDir.def("Append", (void (TColgp_HSequenceOfDir::*)(const TColgp_SequenceOfDir::value_type &)) &TColgp_HSequenceOfDir::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfDir.def("Append", (void (TColgp_HSequenceOfDir::*)(TColgp_SequenceOfDir &)) &TColgp_HSequenceOfDir::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfDir.def("ChangeSequence", (TColgp_SequenceOfDir & (TColgp_HSequenceOfDir::*)()) &TColgp_HSequenceOfDir::ChangeSequence, "None");
cls_TColgp_HSequenceOfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfDir::get_type_name, "None");
cls_TColgp_HSequenceOfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfDir::get_type_descriptor, "None");
cls_TColgp_HSequenceOfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfDir::*)() const) &TColgp_HSequenceOfDir::DynamicType, "None");

// Enums

}