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
#include <NCollection_Sequence.hxx>
#include <Standard_Handle.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <AIS_Manipulator.hxx>
#include <Standard_Type.hxx>

void bind_AIS_ManipulatorObjectSequence(py::module &mod){

py::class_<AIS_ManipulatorObjectSequence, opencascade::handle<AIS_ManipulatorObjectSequence>, Standard_Transient> cls_AIS_ManipulatorObjectSequence(mod, "AIS_ManipulatorObjectSequence", "None", py::multiple_inheritance());

// Constructors
cls_AIS_ManipulatorObjectSequence.def(py::init<>());
cls_AIS_ManipulatorObjectSequence.def(py::init<const NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> > &>(), py::arg("theOther"));

// Fields

// Methods
// cls_AIS_ManipulatorObjectSequence.def_static("operator new_", (void * (*)(size_t)) &AIS_ManipulatorObjectSequence::operator new, "None", py::arg("theSize"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator delete_", (void (*)(void *)) &AIS_ManipulatorObjectSequence::operator delete, "None", py::arg("theAddress"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator new[]_", (void * (*)(size_t)) &AIS_ManipulatorObjectSequence::operator new[], "None", py::arg("theSize"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator delete[]_", (void (*)(void *)) &AIS_ManipulatorObjectSequence::operator delete[], "None", py::arg("theAddress"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator new_", (void * (*)(size_t, void *)) &AIS_ManipulatorObjectSequence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator delete_", (void (*)(void *, void *)) &AIS_ManipulatorObjectSequence::operator delete, "None", py::arg(""), py::arg(""));
// cls_AIS_ManipulatorObjectSequence.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &AIS_ManipulatorObjectSequence::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &AIS_ManipulatorObjectSequence::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_AIS_ManipulatorObjectSequence.def("Sequence", (const NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> > & (AIS_ManipulatorObjectSequence::*)() const) &AIS_ManipulatorObjectSequence::Sequence, "None");
cls_AIS_ManipulatorObjectSequence.def("Append", (void (AIS_ManipulatorObjectSequence::*)(const NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> >::value_type &)) &AIS_ManipulatorObjectSequence::Append, "None", py::arg("theItem"));
cls_AIS_ManipulatorObjectSequence.def("Append", (void (AIS_ManipulatorObjectSequence::*)(NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> > &)) &AIS_ManipulatorObjectSequence::Append, "None", py::arg("theSequence"));
cls_AIS_ManipulatorObjectSequence.def("ChangeSequence", (NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> > & (AIS_ManipulatorObjectSequence::*)()) &AIS_ManipulatorObjectSequence::ChangeSequence, "None");
cls_AIS_ManipulatorObjectSequence.def_static("get_type_name_", (const char * (*)()) &AIS_ManipulatorObjectSequence::get_type_name, "None");
cls_AIS_ManipulatorObjectSequence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ManipulatorObjectSequence::get_type_descriptor, "None");
cls_AIS_ManipulatorObjectSequence.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ManipulatorObjectSequence::*)() const) &AIS_ManipulatorObjectSequence::DynamicType, "None");

// Enums

}