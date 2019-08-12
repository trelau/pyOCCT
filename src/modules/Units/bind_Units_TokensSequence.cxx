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
#include <Units_TksSequence.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Units_TokensSequence.hxx>
#include <Standard_Type.hxx>

void bind_Units_TokensSequence(py::module &mod){

py::class_<Units_TokensSequence, opencascade::handle<Units_TokensSequence>, Standard_Transient> cls_Units_TokensSequence(mod, "Units_TokensSequence", "None", py::multiple_inheritance());

// Constructors
cls_Units_TokensSequence.def(py::init<>());
cls_Units_TokensSequence.def(py::init<const Units_TksSequence &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Units_TokensSequence.def_static("operator new_", (void * (*)(size_t)) &Units_TokensSequence::operator new, "None", py::arg("theSize"));
// cls_Units_TokensSequence.def_static("operator delete_", (void (*)(void *)) &Units_TokensSequence::operator delete, "None", py::arg("theAddress"));
// cls_Units_TokensSequence.def_static("operator new[]_", (void * (*)(size_t)) &Units_TokensSequence::operator new[], "None", py::arg("theSize"));
// cls_Units_TokensSequence.def_static("operator delete[]_", (void (*)(void *)) &Units_TokensSequence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_TokensSequence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_TokensSequence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_TokensSequence.def_static("operator delete_", (void (*)(void *, void *)) &Units_TokensSequence::operator delete, "None", py::arg(""), py::arg(""));
// cls_Units_TokensSequence.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_TokensSequence::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Units_TokensSequence.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_TokensSequence::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Units_TokensSequence.def("Sequence", (const Units_TksSequence & (Units_TokensSequence::*)() const) &Units_TokensSequence::Sequence, "None");
cls_Units_TokensSequence.def("Append", (void (Units_TokensSequence::*)(const Units_TksSequence::value_type &)) &Units_TokensSequence::Append, "None", py::arg("theItem"));
cls_Units_TokensSequence.def("Append", (void (Units_TokensSequence::*)(Units_TksSequence &)) &Units_TokensSequence::Append, "None", py::arg("theSequence"));
cls_Units_TokensSequence.def("ChangeSequence", (Units_TksSequence & (Units_TokensSequence::*)()) &Units_TokensSequence::ChangeSequence, "None");
cls_Units_TokensSequence.def_static("get_type_name_", (const char * (*)()) &Units_TokensSequence::get_type_name, "None");
cls_Units_TokensSequence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_TokensSequence::get_type_descriptor, "None");
cls_Units_TokensSequence.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_TokensSequence::*)() const) &Units_TokensSequence::DynamicType, "None");

// Enums

}