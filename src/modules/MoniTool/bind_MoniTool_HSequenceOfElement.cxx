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
#include <MoniTool_SequenceOfElement.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <MoniTool_HSequenceOfElement.hxx>
#include <Standard_Type.hxx>

void bind_MoniTool_HSequenceOfElement(py::module &mod){

py::class_<MoniTool_HSequenceOfElement, opencascade::handle<MoniTool_HSequenceOfElement>, Standard_Transient> cls_MoniTool_HSequenceOfElement(mod, "MoniTool_HSequenceOfElement", "None", py::multiple_inheritance());

// Constructors
cls_MoniTool_HSequenceOfElement.def(py::init<>());
cls_MoniTool_HSequenceOfElement.def(py::init<const MoniTool_SequenceOfElement &>(), py::arg("theOther"));

// Fields

// Methods
// cls_MoniTool_HSequenceOfElement.def_static("operator new_", (void * (*)(size_t)) &MoniTool_HSequenceOfElement::operator new, "None", py::arg("theSize"));
// cls_MoniTool_HSequenceOfElement.def_static("operator delete_", (void (*)(void *)) &MoniTool_HSequenceOfElement::operator delete, "None", py::arg("theAddress"));
// cls_MoniTool_HSequenceOfElement.def_static("operator new[]_", (void * (*)(size_t)) &MoniTool_HSequenceOfElement::operator new[], "None", py::arg("theSize"));
// cls_MoniTool_HSequenceOfElement.def_static("operator delete[]_", (void (*)(void *)) &MoniTool_HSequenceOfElement::operator delete[], "None", py::arg("theAddress"));
// cls_MoniTool_HSequenceOfElement.def_static("operator new_", (void * (*)(size_t, void *)) &MoniTool_HSequenceOfElement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MoniTool_HSequenceOfElement.def_static("operator delete_", (void (*)(void *, void *)) &MoniTool_HSequenceOfElement::operator delete, "None", py::arg(""), py::arg(""));
// cls_MoniTool_HSequenceOfElement.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &MoniTool_HSequenceOfElement::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_MoniTool_HSequenceOfElement.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &MoniTool_HSequenceOfElement::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_MoniTool_HSequenceOfElement.def("Sequence", (const MoniTool_SequenceOfElement & (MoniTool_HSequenceOfElement::*)() const) &MoniTool_HSequenceOfElement::Sequence, "None");
cls_MoniTool_HSequenceOfElement.def("Append", (void (MoniTool_HSequenceOfElement::*)(const MoniTool_SequenceOfElement::value_type &)) &MoniTool_HSequenceOfElement::Append, "None", py::arg("theItem"));
cls_MoniTool_HSequenceOfElement.def("Append", (void (MoniTool_HSequenceOfElement::*)(MoniTool_SequenceOfElement &)) &MoniTool_HSequenceOfElement::Append, "None", py::arg("theSequence"));
cls_MoniTool_HSequenceOfElement.def("ChangeSequence", (MoniTool_SequenceOfElement & (MoniTool_HSequenceOfElement::*)()) &MoniTool_HSequenceOfElement::ChangeSequence, "None");
cls_MoniTool_HSequenceOfElement.def_static("get_type_name_", (const char * (*)()) &MoniTool_HSequenceOfElement::get_type_name, "None");
cls_MoniTool_HSequenceOfElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_HSequenceOfElement::get_type_descriptor, "None");
cls_MoniTool_HSequenceOfElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_HSequenceOfElement::*)() const) &MoniTool_HSequenceOfElement::DynamicType, "None");

// Enums

}