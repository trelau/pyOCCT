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
#include <Storage_SeqOfRoot.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Storage_HSeqOfRoot.hxx>
#include <Standard_Type.hxx>

void bind_Storage_HSeqOfRoot(py::module &mod){

py::class_<Storage_HSeqOfRoot, opencascade::handle<Storage_HSeqOfRoot>, Standard_Transient> cls_Storage_HSeqOfRoot(mod, "Storage_HSeqOfRoot", "None", py::multiple_inheritance());

// Constructors
cls_Storage_HSeqOfRoot.def(py::init<>());
cls_Storage_HSeqOfRoot.def(py::init<const Storage_SeqOfRoot &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Storage_HSeqOfRoot.def_static("operator new_", (void * (*)(size_t)) &Storage_HSeqOfRoot::operator new, "None", py::arg("theSize"));
// cls_Storage_HSeqOfRoot.def_static("operator delete_", (void (*)(void *)) &Storage_HSeqOfRoot::operator delete, "None", py::arg("theAddress"));
// cls_Storage_HSeqOfRoot.def_static("operator new[]_", (void * (*)(size_t)) &Storage_HSeqOfRoot::operator new[], "None", py::arg("theSize"));
// cls_Storage_HSeqOfRoot.def_static("operator delete[]_", (void (*)(void *)) &Storage_HSeqOfRoot::operator delete[], "None", py::arg("theAddress"));
// cls_Storage_HSeqOfRoot.def_static("operator new_", (void * (*)(size_t, void *)) &Storage_HSeqOfRoot::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Storage_HSeqOfRoot.def_static("operator delete_", (void (*)(void *, void *)) &Storage_HSeqOfRoot::operator delete, "None", py::arg(""), py::arg(""));
// cls_Storage_HSeqOfRoot.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Storage_HSeqOfRoot::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Storage_HSeqOfRoot.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Storage_HSeqOfRoot::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Storage_HSeqOfRoot.def("Sequence", (const Storage_SeqOfRoot & (Storage_HSeqOfRoot::*)() const) &Storage_HSeqOfRoot::Sequence, "None");
cls_Storage_HSeqOfRoot.def("Append", (void (Storage_HSeqOfRoot::*)(const Storage_SeqOfRoot::value_type &)) &Storage_HSeqOfRoot::Append, "None", py::arg("theItem"));
cls_Storage_HSeqOfRoot.def("Append", (void (Storage_HSeqOfRoot::*)(Storage_SeqOfRoot &)) &Storage_HSeqOfRoot::Append, "None", py::arg("theSequence"));
cls_Storage_HSeqOfRoot.def("ChangeSequence", (Storage_SeqOfRoot & (Storage_HSeqOfRoot::*)()) &Storage_HSeqOfRoot::ChangeSequence, "None");
cls_Storage_HSeqOfRoot.def_static("get_type_name_", (const char * (*)()) &Storage_HSeqOfRoot::get_type_name, "None");
cls_Storage_HSeqOfRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Storage_HSeqOfRoot::get_type_descriptor, "None");
cls_Storage_HSeqOfRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (Storage_HSeqOfRoot::*)() const) &Storage_HSeqOfRoot::DynamicType, "None");

// Enums

}