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
#include <TColgp_SequenceOfXY.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TColgp_HSequenceOfXY.hxx>
#include <Standard_Type.hxx>

void bind_TColgp_HSequenceOfXY(py::module &mod){

py::class_<TColgp_HSequenceOfXY, opencascade::handle<TColgp_HSequenceOfXY>, Standard_Transient> cls_TColgp_HSequenceOfXY(mod, "TColgp_HSequenceOfXY", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfXY.def(py::init<>());
cls_TColgp_HSequenceOfXY.def(py::init<const TColgp_SequenceOfXY &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColgp_HSequenceOfXY.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfXY::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfXY.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfXY::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfXY.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfXY::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfXY.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfXY::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfXY.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfXY::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfXY.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfXY::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfXY.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfXY::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfXY.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfXY::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfXY.def("Sequence", (const TColgp_SequenceOfXY & (TColgp_HSequenceOfXY::*)() const) &TColgp_HSequenceOfXY::Sequence, "None");
cls_TColgp_HSequenceOfXY.def("Append", (void (TColgp_HSequenceOfXY::*)(const TColgp_SequenceOfXY::value_type &)) &TColgp_HSequenceOfXY::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfXY.def("Append", (void (TColgp_HSequenceOfXY::*)(TColgp_SequenceOfXY &)) &TColgp_HSequenceOfXY::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfXY.def("ChangeSequence", (TColgp_SequenceOfXY & (TColgp_HSequenceOfXY::*)()) &TColgp_HSequenceOfXY::ChangeSequence, "None");
cls_TColgp_HSequenceOfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfXY::get_type_name, "None");
cls_TColgp_HSequenceOfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfXY::get_type_descriptor, "None");
cls_TColgp_HSequenceOfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfXY::*)() const) &TColgp_HSequenceOfXY::DynamicType, "None");

// Enums

}