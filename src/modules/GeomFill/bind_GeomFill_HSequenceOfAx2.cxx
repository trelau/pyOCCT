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
#include <GeomFill_SequenceOfAx2.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <GeomFill_HSequenceOfAx2.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_HSequenceOfAx2(py::module &mod){

py::class_<GeomFill_HSequenceOfAx2, opencascade::handle<GeomFill_HSequenceOfAx2>, Standard_Transient> cls_GeomFill_HSequenceOfAx2(mod, "GeomFill_HSequenceOfAx2", "None", py::multiple_inheritance());

// Constructors
cls_GeomFill_HSequenceOfAx2.def(py::init<>());
cls_GeomFill_HSequenceOfAx2.def(py::init<const GeomFill_SequenceOfAx2 &>(), py::arg("theOther"));

// Fields

// Methods
// cls_GeomFill_HSequenceOfAx2.def_static("operator new_", (void * (*)(size_t)) &GeomFill_HSequenceOfAx2::operator new, "None", py::arg("theSize"));
// cls_GeomFill_HSequenceOfAx2.def_static("operator delete_", (void (*)(void *)) &GeomFill_HSequenceOfAx2::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_HSequenceOfAx2.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_HSequenceOfAx2::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_HSequenceOfAx2.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_HSequenceOfAx2::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_HSequenceOfAx2.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_HSequenceOfAx2::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_HSequenceOfAx2.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_HSequenceOfAx2::operator delete, "None", py::arg(""), py::arg(""));
// cls_GeomFill_HSequenceOfAx2.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomFill_HSequenceOfAx2::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_GeomFill_HSequenceOfAx2.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomFill_HSequenceOfAx2::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_GeomFill_HSequenceOfAx2.def("Sequence", (const GeomFill_SequenceOfAx2 & (GeomFill_HSequenceOfAx2::*)() const) &GeomFill_HSequenceOfAx2::Sequence, "None");
cls_GeomFill_HSequenceOfAx2.def("Append", (void (GeomFill_HSequenceOfAx2::*)(const GeomFill_SequenceOfAx2::value_type &)) &GeomFill_HSequenceOfAx2::Append, "None", py::arg("theItem"));
cls_GeomFill_HSequenceOfAx2.def("Append", (void (GeomFill_HSequenceOfAx2::*)(GeomFill_SequenceOfAx2 &)) &GeomFill_HSequenceOfAx2::Append, "None", py::arg("theSequence"));
cls_GeomFill_HSequenceOfAx2.def("ChangeSequence", (GeomFill_SequenceOfAx2 & (GeomFill_HSequenceOfAx2::*)()) &GeomFill_HSequenceOfAx2::ChangeSequence, "None");
cls_GeomFill_HSequenceOfAx2.def_static("get_type_name_", (const char * (*)()) &GeomFill_HSequenceOfAx2::get_type_name, "None");
cls_GeomFill_HSequenceOfAx2.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_HSequenceOfAx2::get_type_descriptor, "None");
cls_GeomFill_HSequenceOfAx2.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_HSequenceOfAx2::*)() const) &GeomFill_HSequenceOfAx2::DynamicType, "None");

// Enums

}