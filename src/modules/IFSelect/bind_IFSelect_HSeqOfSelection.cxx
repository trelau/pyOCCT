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
#include <IFSelect_TSeqOfSelection.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <IFSelect_HSeqOfSelection.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_HSeqOfSelection(py::module &mod){

py::class_<IFSelect_HSeqOfSelection, opencascade::handle<IFSelect_HSeqOfSelection>, Standard_Transient> cls_IFSelect_HSeqOfSelection(mod, "IFSelect_HSeqOfSelection", "None", py::multiple_inheritance());

// Constructors
cls_IFSelect_HSeqOfSelection.def(py::init<>());
cls_IFSelect_HSeqOfSelection.def(py::init<const IFSelect_TSeqOfSelection &>(), py::arg("theOther"));

// Fields

// Methods
// cls_IFSelect_HSeqOfSelection.def_static("operator new_", (void * (*)(size_t)) &IFSelect_HSeqOfSelection::operator new, "None", py::arg("theSize"));
// cls_IFSelect_HSeqOfSelection.def_static("operator delete_", (void (*)(void *)) &IFSelect_HSeqOfSelection::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_HSeqOfSelection.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_HSeqOfSelection::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_HSeqOfSelection.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_HSeqOfSelection::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_HSeqOfSelection.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_HSeqOfSelection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_HSeqOfSelection.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_HSeqOfSelection::operator delete, "None", py::arg(""), py::arg(""));
// cls_IFSelect_HSeqOfSelection.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IFSelect_HSeqOfSelection::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IFSelect_HSeqOfSelection.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IFSelect_HSeqOfSelection::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IFSelect_HSeqOfSelection.def("Sequence", (const IFSelect_TSeqOfSelection & (IFSelect_HSeqOfSelection::*)() const) &IFSelect_HSeqOfSelection::Sequence, "None");
cls_IFSelect_HSeqOfSelection.def("Append", (void (IFSelect_HSeqOfSelection::*)(const IFSelect_TSeqOfSelection::value_type &)) &IFSelect_HSeqOfSelection::Append, "None", py::arg("theItem"));
cls_IFSelect_HSeqOfSelection.def("Append", (void (IFSelect_HSeqOfSelection::*)(IFSelect_TSeqOfSelection &)) &IFSelect_HSeqOfSelection::Append, "None", py::arg("theSequence"));
cls_IFSelect_HSeqOfSelection.def("ChangeSequence", (IFSelect_TSeqOfSelection & (IFSelect_HSeqOfSelection::*)()) &IFSelect_HSeqOfSelection::ChangeSequence, "None");
cls_IFSelect_HSeqOfSelection.def_static("get_type_name_", (const char * (*)()) &IFSelect_HSeqOfSelection::get_type_name, "None");
cls_IFSelect_HSeqOfSelection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_HSeqOfSelection::get_type_descriptor, "None");
cls_IFSelect_HSeqOfSelection.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_HSeqOfSelection::*)() const) &IFSelect_HSeqOfSelection::DynamicType, "None");

// Enums

}