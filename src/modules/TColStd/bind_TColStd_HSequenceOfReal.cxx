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
#include <TColStd_SequenceOfReal.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <Standard_Type.hxx>

void bind_TColStd_HSequenceOfReal(py::module &mod){

py::class_<TColStd_HSequenceOfReal, opencascade::handle<TColStd_HSequenceOfReal>, Standard_Transient> cls_TColStd_HSequenceOfReal(mod, "TColStd_HSequenceOfReal", "None", py::multiple_inheritance());

// Constructors
cls_TColStd_HSequenceOfReal.def(py::init<>());
cls_TColStd_HSequenceOfReal.def(py::init<const TColStd_SequenceOfReal &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColStd_HSequenceOfReal.def_static("operator new_", (void * (*)(size_t)) &TColStd_HSequenceOfReal::operator new, "None", py::arg("theSize"));
// cls_TColStd_HSequenceOfReal.def_static("operator delete_", (void (*)(void *)) &TColStd_HSequenceOfReal::operator delete, "None", py::arg("theAddress"));
// cls_TColStd_HSequenceOfReal.def_static("operator new[]_", (void * (*)(size_t)) &TColStd_HSequenceOfReal::operator new[], "None", py::arg("theSize"));
// cls_TColStd_HSequenceOfReal.def_static("operator delete[]_", (void (*)(void *)) &TColStd_HSequenceOfReal::operator delete[], "None", py::arg("theAddress"));
// cls_TColStd_HSequenceOfReal.def_static("operator new_", (void * (*)(size_t, void *)) &TColStd_HSequenceOfReal::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColStd_HSequenceOfReal.def_static("operator delete_", (void (*)(void *, void *)) &TColStd_HSequenceOfReal::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColStd_HSequenceOfReal.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HSequenceOfReal::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColStd_HSequenceOfReal.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HSequenceOfReal::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColStd_HSequenceOfReal.def("Sequence", (const TColStd_SequenceOfReal & (TColStd_HSequenceOfReal::*)() const) &TColStd_HSequenceOfReal::Sequence, "None");
cls_TColStd_HSequenceOfReal.def("Append", (void (TColStd_HSequenceOfReal::*)(const TColStd_SequenceOfReal::value_type &)) &TColStd_HSequenceOfReal::Append, "None", py::arg("theItem"));
cls_TColStd_HSequenceOfReal.def("Append", (void (TColStd_HSequenceOfReal::*)(TColStd_SequenceOfReal &)) &TColStd_HSequenceOfReal::Append, "None", py::arg("theSequence"));
cls_TColStd_HSequenceOfReal.def("ChangeSequence", (TColStd_SequenceOfReal & (TColStd_HSequenceOfReal::*)()) &TColStd_HSequenceOfReal::ChangeSequence, "None");
cls_TColStd_HSequenceOfReal.def_static("get_type_name_", (const char * (*)()) &TColStd_HSequenceOfReal::get_type_name, "None");
cls_TColStd_HSequenceOfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HSequenceOfReal::get_type_descriptor, "None");
cls_TColStd_HSequenceOfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HSequenceOfReal::*)() const) &TColStd_HSequenceOfReal::DynamicType, "None");

// Enums

}