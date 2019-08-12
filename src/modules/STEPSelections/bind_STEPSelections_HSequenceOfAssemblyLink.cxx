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
#include <STEPSelections_SequenceOfAssemblyLink.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <STEPSelections_HSequenceOfAssemblyLink.hxx>
#include <Standard_Type.hxx>

void bind_STEPSelections_HSequenceOfAssemblyLink(py::module &mod){

py::class_<STEPSelections_HSequenceOfAssemblyLink, opencascade::handle<STEPSelections_HSequenceOfAssemblyLink>, Standard_Transient> cls_STEPSelections_HSequenceOfAssemblyLink(mod, "STEPSelections_HSequenceOfAssemblyLink", "None", py::multiple_inheritance());

// Constructors
cls_STEPSelections_HSequenceOfAssemblyLink.def(py::init<>());
cls_STEPSelections_HSequenceOfAssemblyLink.def(py::init<const STEPSelections_SequenceOfAssemblyLink &>(), py::arg("theOther"));

// Fields

// Methods
// cls_STEPSelections_HSequenceOfAssemblyLink.def_static("operator new_", (void * (*)(size_t)) &STEPSelections_HSequenceOfAssemblyLink::operator new, "None", py::arg("theSize"));
// cls_STEPSelections_HSequenceOfAssemblyLink.def_static("operator delete_", (void (*)(void *)) &STEPSelections_HSequenceOfAssemblyLink::operator delete, "None", py::arg("theAddress"));
// cls_STEPSelections_HSequenceOfAssemblyLink.def_static("operator new[]_", (void * (*)(size_t)) &STEPSelections_HSequenceOfAssemblyLink::operator new[], "None", py::arg("theSize"));
// cls_STEPSelections_HSequenceOfAssemblyLink.def_static("operator delete[]_", (void (*)(void *)) &STEPSelections_HSequenceOfAssemblyLink::operator delete[], "None", py::arg("theAddress"));
// cls_STEPSelections_HSequenceOfAssemblyLink.def_static("operator new_", (void * (*)(size_t, void *)) &STEPSelections_HSequenceOfAssemblyLink::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPSelections_HSequenceOfAssemblyLink.def_static("operator delete_", (void (*)(void *, void *)) &STEPSelections_HSequenceOfAssemblyLink::operator delete, "None", py::arg(""), py::arg(""));
// cls_STEPSelections_HSequenceOfAssemblyLink.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &STEPSelections_HSequenceOfAssemblyLink::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_STEPSelections_HSequenceOfAssemblyLink.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &STEPSelections_HSequenceOfAssemblyLink::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_STEPSelections_HSequenceOfAssemblyLink.def("Sequence", (const STEPSelections_SequenceOfAssemblyLink & (STEPSelections_HSequenceOfAssemblyLink::*)() const) &STEPSelections_HSequenceOfAssemblyLink::Sequence, "None");
cls_STEPSelections_HSequenceOfAssemblyLink.def("Append", (void (STEPSelections_HSequenceOfAssemblyLink::*)(const STEPSelections_SequenceOfAssemblyLink::value_type &)) &STEPSelections_HSequenceOfAssemblyLink::Append, "None", py::arg("theItem"));
cls_STEPSelections_HSequenceOfAssemblyLink.def("Append", (void (STEPSelections_HSequenceOfAssemblyLink::*)(STEPSelections_SequenceOfAssemblyLink &)) &STEPSelections_HSequenceOfAssemblyLink::Append, "None", py::arg("theSequence"));
cls_STEPSelections_HSequenceOfAssemblyLink.def("ChangeSequence", (STEPSelections_SequenceOfAssemblyLink & (STEPSelections_HSequenceOfAssemblyLink::*)()) &STEPSelections_HSequenceOfAssemblyLink::ChangeSequence, "None");
cls_STEPSelections_HSequenceOfAssemblyLink.def_static("get_type_name_", (const char * (*)()) &STEPSelections_HSequenceOfAssemblyLink::get_type_name, "None");
cls_STEPSelections_HSequenceOfAssemblyLink.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_HSequenceOfAssemblyLink::get_type_descriptor, "None");
cls_STEPSelections_HSequenceOfAssemblyLink.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_HSequenceOfAssemblyLink::*)() const) &STEPSelections_HSequenceOfAssemblyLink::DynamicType, "None");

// Enums

}