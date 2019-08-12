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
#include <TObj_Object.hxx>
#include <TObj_SequenceOfObject.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_Type.hxx>

void bind_TObj_HSequenceOfObject(py::module &mod){

py::class_<TObj_HSequenceOfObject, opencascade::handle<TObj_HSequenceOfObject>, Standard_Transient> cls_TObj_HSequenceOfObject(mod, "TObj_HSequenceOfObject", "None", py::multiple_inheritance());

// Constructors
cls_TObj_HSequenceOfObject.def(py::init<>());
cls_TObj_HSequenceOfObject.def(py::init<const TObj_SequenceOfObject &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TObj_HSequenceOfObject.def_static("operator new_", (void * (*)(size_t)) &TObj_HSequenceOfObject::operator new, "None", py::arg("theSize"));
// cls_TObj_HSequenceOfObject.def_static("operator delete_", (void (*)(void *)) &TObj_HSequenceOfObject::operator delete, "None", py::arg("theAddress"));
// cls_TObj_HSequenceOfObject.def_static("operator new[]_", (void * (*)(size_t)) &TObj_HSequenceOfObject::operator new[], "None", py::arg("theSize"));
// cls_TObj_HSequenceOfObject.def_static("operator delete[]_", (void (*)(void *)) &TObj_HSequenceOfObject::operator delete[], "None", py::arg("theAddress"));
// cls_TObj_HSequenceOfObject.def_static("operator new_", (void * (*)(size_t, void *)) &TObj_HSequenceOfObject::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TObj_HSequenceOfObject.def_static("operator delete_", (void (*)(void *, void *)) &TObj_HSequenceOfObject::operator delete, "None", py::arg(""), py::arg(""));
// cls_TObj_HSequenceOfObject.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TObj_HSequenceOfObject::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TObj_HSequenceOfObject.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TObj_HSequenceOfObject::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TObj_HSequenceOfObject.def("Sequence", (const TObj_SequenceOfObject & (TObj_HSequenceOfObject::*)() const) &TObj_HSequenceOfObject::Sequence, "None");
cls_TObj_HSequenceOfObject.def("Append", (void (TObj_HSequenceOfObject::*)(const TObj_SequenceOfObject::value_type &)) &TObj_HSequenceOfObject::Append, "None", py::arg("theItem"));
cls_TObj_HSequenceOfObject.def("Append", (void (TObj_HSequenceOfObject::*)(TObj_SequenceOfObject &)) &TObj_HSequenceOfObject::Append, "None", py::arg("theSequence"));
cls_TObj_HSequenceOfObject.def("ChangeSequence", (TObj_SequenceOfObject & (TObj_HSequenceOfObject::*)()) &TObj_HSequenceOfObject::ChangeSequence, "None");
cls_TObj_HSequenceOfObject.def_static("get_type_name_", (const char * (*)()) &TObj_HSequenceOfObject::get_type_name, "None");
cls_TObj_HSequenceOfObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_HSequenceOfObject::get_type_descriptor, "None");
cls_TObj_HSequenceOfObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_HSequenceOfObject::*)() const) &TObj_HSequenceOfObject::DynamicType, "None");

// Enums

}