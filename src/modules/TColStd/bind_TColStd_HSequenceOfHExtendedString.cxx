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
#include <TColStd_SequenceOfHExtendedString.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TColStd_HSequenceOfHExtendedString.hxx>
#include <Standard_Type.hxx>

void bind_TColStd_HSequenceOfHExtendedString(py::module &mod){

py::class_<TColStd_HSequenceOfHExtendedString, opencascade::handle<TColStd_HSequenceOfHExtendedString>, Standard_Transient> cls_TColStd_HSequenceOfHExtendedString(mod, "TColStd_HSequenceOfHExtendedString", "None", py::multiple_inheritance());

// Constructors
cls_TColStd_HSequenceOfHExtendedString.def(py::init<>());
cls_TColStd_HSequenceOfHExtendedString.def(py::init<const TColStd_SequenceOfHExtendedString &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColStd_HSequenceOfHExtendedString.def_static("operator new_", (void * (*)(size_t)) &TColStd_HSequenceOfHExtendedString::operator new, "None", py::arg("theSize"));
// cls_TColStd_HSequenceOfHExtendedString.def_static("operator delete_", (void (*)(void *)) &TColStd_HSequenceOfHExtendedString::operator delete, "None", py::arg("theAddress"));
// cls_TColStd_HSequenceOfHExtendedString.def_static("operator new[]_", (void * (*)(size_t)) &TColStd_HSequenceOfHExtendedString::operator new[], "None", py::arg("theSize"));
// cls_TColStd_HSequenceOfHExtendedString.def_static("operator delete[]_", (void (*)(void *)) &TColStd_HSequenceOfHExtendedString::operator delete[], "None", py::arg("theAddress"));
// cls_TColStd_HSequenceOfHExtendedString.def_static("operator new_", (void * (*)(size_t, void *)) &TColStd_HSequenceOfHExtendedString::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColStd_HSequenceOfHExtendedString.def_static("operator delete_", (void (*)(void *, void *)) &TColStd_HSequenceOfHExtendedString::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColStd_HSequenceOfHExtendedString.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HSequenceOfHExtendedString::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColStd_HSequenceOfHExtendedString.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HSequenceOfHExtendedString::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColStd_HSequenceOfHExtendedString.def("Sequence", (const TColStd_SequenceOfHExtendedString & (TColStd_HSequenceOfHExtendedString::*)() const) &TColStd_HSequenceOfHExtendedString::Sequence, "None");
cls_TColStd_HSequenceOfHExtendedString.def("Append", (void (TColStd_HSequenceOfHExtendedString::*)(const TColStd_SequenceOfHExtendedString::value_type &)) &TColStd_HSequenceOfHExtendedString::Append, "None", py::arg("theItem"));
cls_TColStd_HSequenceOfHExtendedString.def("Append", (void (TColStd_HSequenceOfHExtendedString::*)(TColStd_SequenceOfHExtendedString &)) &TColStd_HSequenceOfHExtendedString::Append, "None", py::arg("theSequence"));
cls_TColStd_HSequenceOfHExtendedString.def("ChangeSequence", (TColStd_SequenceOfHExtendedString & (TColStd_HSequenceOfHExtendedString::*)()) &TColStd_HSequenceOfHExtendedString::ChangeSequence, "None");
cls_TColStd_HSequenceOfHExtendedString.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfHExtendedString::get_type_name, "None");
cls_TColStd_HSequenceOfHExtendedString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfHExtendedString::get_type_descriptor, "None");
cls_TColStd_HSequenceOfHExtendedString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfHExtendedString::*)() const) &TColStd_HSequenceOfHExtendedString::DynamicType, "None");

// Enums

}