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
#include <ProjLib_SequenceOfHSequenceOfPnt.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <ProjLib_HSequenceOfHSequenceOfPnt.hxx>
#include <Standard_Type.hxx>

void bind_ProjLib_HSequenceOfHSequenceOfPnt(py::module &mod){

py::class_<ProjLib_HSequenceOfHSequenceOfPnt, opencascade::handle<ProjLib_HSequenceOfHSequenceOfPnt>, Standard_Transient> cls_ProjLib_HSequenceOfHSequenceOfPnt(mod, "ProjLib_HSequenceOfHSequenceOfPnt", "None", py::multiple_inheritance());

// Constructors
cls_ProjLib_HSequenceOfHSequenceOfPnt.def(py::init<>());
cls_ProjLib_HSequenceOfHSequenceOfPnt.def(py::init<const ProjLib_SequenceOfHSequenceOfPnt &>(), py::arg("theOther"));

// Fields

// Methods
// cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("operator new_", (void * (*)(size_t)) &ProjLib_HSequenceOfHSequenceOfPnt::operator new, "None", py::arg("theSize"));
// cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("operator delete_", (void (*)(void *)) &ProjLib_HSequenceOfHSequenceOfPnt::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_HSequenceOfHSequenceOfPnt::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_HSequenceOfHSequenceOfPnt::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_HSequenceOfHSequenceOfPnt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_HSequenceOfHSequenceOfPnt::operator delete, "None", py::arg(""), py::arg(""));
// cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &ProjLib_HSequenceOfHSequenceOfPnt::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &ProjLib_HSequenceOfHSequenceOfPnt::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_ProjLib_HSequenceOfHSequenceOfPnt.def("Sequence", (const ProjLib_SequenceOfHSequenceOfPnt & (ProjLib_HSequenceOfHSequenceOfPnt::*)() const) &ProjLib_HSequenceOfHSequenceOfPnt::Sequence, "None");
cls_ProjLib_HSequenceOfHSequenceOfPnt.def("Append", (void (ProjLib_HSequenceOfHSequenceOfPnt::*)(const ProjLib_SequenceOfHSequenceOfPnt::value_type &)) &ProjLib_HSequenceOfHSequenceOfPnt::Append, "None", py::arg("theItem"));
cls_ProjLib_HSequenceOfHSequenceOfPnt.def("Append", (void (ProjLib_HSequenceOfHSequenceOfPnt::*)(ProjLib_SequenceOfHSequenceOfPnt &)) &ProjLib_HSequenceOfHSequenceOfPnt::Append, "None", py::arg("theSequence"));
cls_ProjLib_HSequenceOfHSequenceOfPnt.def("ChangeSequence", (ProjLib_SequenceOfHSequenceOfPnt & (ProjLib_HSequenceOfHSequenceOfPnt::*)()) &ProjLib_HSequenceOfHSequenceOfPnt::ChangeSequence, "None");
cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("get_type_name_", (const char * (*)()) &ProjLib_HSequenceOfHSequenceOfPnt::get_type_name, "None");
cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ProjLib_HSequenceOfHSequenceOfPnt::get_type_descriptor, "None");
cls_ProjLib_HSequenceOfHSequenceOfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (ProjLib_HSequenceOfHSequenceOfPnt::*)() const) &ProjLib_HSequenceOfHSequenceOfPnt::DynamicType, "None");

// Enums

}