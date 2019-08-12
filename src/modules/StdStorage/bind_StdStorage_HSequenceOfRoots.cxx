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
#include <StdStorage_SequenceOfRoots.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <StdStorage_HSequenceOfRoots.hxx>
#include <Standard_Type.hxx>

void bind_StdStorage_HSequenceOfRoots(py::module &mod){

py::class_<StdStorage_HSequenceOfRoots, opencascade::handle<StdStorage_HSequenceOfRoots>, Standard_Transient> cls_StdStorage_HSequenceOfRoots(mod, "StdStorage_HSequenceOfRoots", "None", py::multiple_inheritance());

// Constructors
cls_StdStorage_HSequenceOfRoots.def(py::init<>());
cls_StdStorage_HSequenceOfRoots.def(py::init<const StdStorage_SequenceOfRoots &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StdStorage_HSequenceOfRoots.def_static("operator new_", (void * (*)(size_t)) &StdStorage_HSequenceOfRoots::operator new, "None", py::arg("theSize"));
// cls_StdStorage_HSequenceOfRoots.def_static("operator delete_", (void (*)(void *)) &StdStorage_HSequenceOfRoots::operator delete, "None", py::arg("theAddress"));
// cls_StdStorage_HSequenceOfRoots.def_static("operator new[]_", (void * (*)(size_t)) &StdStorage_HSequenceOfRoots::operator new[], "None", py::arg("theSize"));
// cls_StdStorage_HSequenceOfRoots.def_static("operator delete[]_", (void (*)(void *)) &StdStorage_HSequenceOfRoots::operator delete[], "None", py::arg("theAddress"));
// cls_StdStorage_HSequenceOfRoots.def_static("operator new_", (void * (*)(size_t, void *)) &StdStorage_HSequenceOfRoots::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdStorage_HSequenceOfRoots.def_static("operator delete_", (void (*)(void *, void *)) &StdStorage_HSequenceOfRoots::operator delete, "None", py::arg(""), py::arg(""));
// cls_StdStorage_HSequenceOfRoots.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StdStorage_HSequenceOfRoots::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StdStorage_HSequenceOfRoots.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StdStorage_HSequenceOfRoots::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StdStorage_HSequenceOfRoots.def("Sequence", (const StdStorage_SequenceOfRoots & (StdStorage_HSequenceOfRoots::*)() const) &StdStorage_HSequenceOfRoots::Sequence, "None");
cls_StdStorage_HSequenceOfRoots.def("Append", (void (StdStorage_HSequenceOfRoots::*)(const StdStorage_SequenceOfRoots::value_type &)) &StdStorage_HSequenceOfRoots::Append, "None", py::arg("theItem"));
cls_StdStorage_HSequenceOfRoots.def("Append", (void (StdStorage_HSequenceOfRoots::*)(StdStorage_SequenceOfRoots &)) &StdStorage_HSequenceOfRoots::Append, "None", py::arg("theSequence"));
cls_StdStorage_HSequenceOfRoots.def("ChangeSequence", (StdStorage_SequenceOfRoots & (StdStorage_HSequenceOfRoots::*)()) &StdStorage_HSequenceOfRoots::ChangeSequence, "None");
cls_StdStorage_HSequenceOfRoots.def_static("get_type_name_", (const char * (*)()) &StdStorage_HSequenceOfRoots::get_type_name, "None");
cls_StdStorage_HSequenceOfRoots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdStorage_HSequenceOfRoots::get_type_descriptor, "None");
cls_StdStorage_HSequenceOfRoots.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdStorage_HSequenceOfRoots::*)() const) &StdStorage_HSequenceOfRoots::DynamicType, "None");

// Enums

}