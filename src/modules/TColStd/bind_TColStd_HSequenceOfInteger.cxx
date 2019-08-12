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
#include <TColStd_SequenceOfInteger.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <Standard_Type.hxx>

void bind_TColStd_HSequenceOfInteger(py::module &mod){

py::class_<TColStd_HSequenceOfInteger, opencascade::handle<TColStd_HSequenceOfInteger>, Standard_Transient> cls_TColStd_HSequenceOfInteger(mod, "TColStd_HSequenceOfInteger", "None", py::multiple_inheritance());

// Constructors
cls_TColStd_HSequenceOfInteger.def(py::init<>());
cls_TColStd_HSequenceOfInteger.def(py::init<const TColStd_SequenceOfInteger &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColStd_HSequenceOfInteger.def_static("operator new_", (void * (*)(size_t)) &TColStd_HSequenceOfInteger::operator new, "None", py::arg("theSize"));
// cls_TColStd_HSequenceOfInteger.def_static("operator delete_", (void (*)(void *)) &TColStd_HSequenceOfInteger::operator delete, "None", py::arg("theAddress"));
// cls_TColStd_HSequenceOfInteger.def_static("operator new[]_", (void * (*)(size_t)) &TColStd_HSequenceOfInteger::operator new[], "None", py::arg("theSize"));
// cls_TColStd_HSequenceOfInteger.def_static("operator delete[]_", (void (*)(void *)) &TColStd_HSequenceOfInteger::operator delete[], "None", py::arg("theAddress"));
// cls_TColStd_HSequenceOfInteger.def_static("operator new_", (void * (*)(size_t, void *)) &TColStd_HSequenceOfInteger::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColStd_HSequenceOfInteger.def_static("operator delete_", (void (*)(void *, void *)) &TColStd_HSequenceOfInteger::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColStd_HSequenceOfInteger.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HSequenceOfInteger::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColStd_HSequenceOfInteger.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HSequenceOfInteger::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColStd_HSequenceOfInteger.def("Sequence", (const TColStd_SequenceOfInteger & (TColStd_HSequenceOfInteger::*)() const) &TColStd_HSequenceOfInteger::Sequence, "None");
cls_TColStd_HSequenceOfInteger.def("Append", (void (TColStd_HSequenceOfInteger::*)(const TColStd_SequenceOfInteger::value_type &)) &TColStd_HSequenceOfInteger::Append, "None", py::arg("theItem"));
cls_TColStd_HSequenceOfInteger.def("Append", (void (TColStd_HSequenceOfInteger::*)(TColStd_SequenceOfInteger &)) &TColStd_HSequenceOfInteger::Append, "None", py::arg("theSequence"));
cls_TColStd_HSequenceOfInteger.def("ChangeSequence", (TColStd_SequenceOfInteger & (TColStd_HSequenceOfInteger::*)()) &TColStd_HSequenceOfInteger::ChangeSequence, "None");
cls_TColStd_HSequenceOfInteger.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfInteger::get_type_name, "None");
cls_TColStd_HSequenceOfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfInteger::get_type_descriptor, "None");
cls_TColStd_HSequenceOfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfInteger::*)() const) &TColStd_HSequenceOfInteger::DynamicType, "None");

// Enums

}