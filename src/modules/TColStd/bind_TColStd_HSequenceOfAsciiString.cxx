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
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <Standard_Type.hxx>

void bind_TColStd_HSequenceOfAsciiString(py::module &mod){

py::class_<TColStd_HSequenceOfAsciiString, opencascade::handle<TColStd_HSequenceOfAsciiString>, Standard_Transient> cls_TColStd_HSequenceOfAsciiString(mod, "TColStd_HSequenceOfAsciiString", "None", py::multiple_inheritance());

// Constructors
cls_TColStd_HSequenceOfAsciiString.def(py::init<>());
cls_TColStd_HSequenceOfAsciiString.def(py::init<const TColStd_SequenceOfAsciiString &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColStd_HSequenceOfAsciiString.def_static("operator new_", (void * (*)(size_t)) &TColStd_HSequenceOfAsciiString::operator new, "None", py::arg("theSize"));
// cls_TColStd_HSequenceOfAsciiString.def_static("operator delete_", (void (*)(void *)) &TColStd_HSequenceOfAsciiString::operator delete, "None", py::arg("theAddress"));
// cls_TColStd_HSequenceOfAsciiString.def_static("operator new[]_", (void * (*)(size_t)) &TColStd_HSequenceOfAsciiString::operator new[], "None", py::arg("theSize"));
// cls_TColStd_HSequenceOfAsciiString.def_static("operator delete[]_", (void (*)(void *)) &TColStd_HSequenceOfAsciiString::operator delete[], "None", py::arg("theAddress"));
// cls_TColStd_HSequenceOfAsciiString.def_static("operator new_", (void * (*)(size_t, void *)) &TColStd_HSequenceOfAsciiString::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColStd_HSequenceOfAsciiString.def_static("operator delete_", (void (*)(void *, void *)) &TColStd_HSequenceOfAsciiString::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColStd_HSequenceOfAsciiString.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HSequenceOfAsciiString::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColStd_HSequenceOfAsciiString.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HSequenceOfAsciiString::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColStd_HSequenceOfAsciiString.def("Sequence", (const TColStd_SequenceOfAsciiString & (TColStd_HSequenceOfAsciiString::*)() const) &TColStd_HSequenceOfAsciiString::Sequence, "None");
cls_TColStd_HSequenceOfAsciiString.def("Append", (void (TColStd_HSequenceOfAsciiString::*)(const TColStd_SequenceOfAsciiString::value_type &)) &TColStd_HSequenceOfAsciiString::Append, "None", py::arg("theItem"));
cls_TColStd_HSequenceOfAsciiString.def("Append", (void (TColStd_HSequenceOfAsciiString::*)(TColStd_SequenceOfAsciiString &)) &TColStd_HSequenceOfAsciiString::Append, "None", py::arg("theSequence"));
cls_TColStd_HSequenceOfAsciiString.def("ChangeSequence", (TColStd_SequenceOfAsciiString & (TColStd_HSequenceOfAsciiString::*)()) &TColStd_HSequenceOfAsciiString::ChangeSequence, "None");
cls_TColStd_HSequenceOfAsciiString.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfAsciiString::get_type_name, "None");
cls_TColStd_HSequenceOfAsciiString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfAsciiString::get_type_descriptor, "None");
cls_TColStd_HSequenceOfAsciiString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfAsciiString::*)() const) &TColStd_HSequenceOfAsciiString::DynamicType, "None");

// Enums

}