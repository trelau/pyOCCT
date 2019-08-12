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
#include <Contap_TheSequenceOfPoint.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Contap_TheHSequenceOfPoint.hxx>
#include <Standard_Type.hxx>

void bind_Contap_TheHSequenceOfPoint(py::module &mod){

py::class_<Contap_TheHSequenceOfPoint, opencascade::handle<Contap_TheHSequenceOfPoint>, Standard_Transient> cls_Contap_TheHSequenceOfPoint(mod, "Contap_TheHSequenceOfPoint", "None", py::multiple_inheritance());

// Constructors
cls_Contap_TheHSequenceOfPoint.def(py::init<>());
cls_Contap_TheHSequenceOfPoint.def(py::init<const Contap_TheSequenceOfPoint &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Contap_TheHSequenceOfPoint.def_static("operator new_", (void * (*)(size_t)) &Contap_TheHSequenceOfPoint::operator new, "None", py::arg("theSize"));
// cls_Contap_TheHSequenceOfPoint.def_static("operator delete_", (void (*)(void *)) &Contap_TheHSequenceOfPoint::operator delete, "None", py::arg("theAddress"));
// cls_Contap_TheHSequenceOfPoint.def_static("operator new[]_", (void * (*)(size_t)) &Contap_TheHSequenceOfPoint::operator new[], "None", py::arg("theSize"));
// cls_Contap_TheHSequenceOfPoint.def_static("operator delete[]_", (void (*)(void *)) &Contap_TheHSequenceOfPoint::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_TheHSequenceOfPoint.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_TheHSequenceOfPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_TheHSequenceOfPoint.def_static("operator delete_", (void (*)(void *, void *)) &Contap_TheHSequenceOfPoint::operator delete, "None", py::arg(""), py::arg(""));
// cls_Contap_TheHSequenceOfPoint.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Contap_TheHSequenceOfPoint::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Contap_TheHSequenceOfPoint.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Contap_TheHSequenceOfPoint::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Contap_TheHSequenceOfPoint.def("Sequence", (const Contap_TheSequenceOfPoint & (Contap_TheHSequenceOfPoint::*)() const) &Contap_TheHSequenceOfPoint::Sequence, "None");
cls_Contap_TheHSequenceOfPoint.def("Append", (void (Contap_TheHSequenceOfPoint::*)(const Contap_TheSequenceOfPoint::value_type &)) &Contap_TheHSequenceOfPoint::Append, "None", py::arg("theItem"));
cls_Contap_TheHSequenceOfPoint.def("Append", (void (Contap_TheHSequenceOfPoint::*)(Contap_TheSequenceOfPoint &)) &Contap_TheHSequenceOfPoint::Append, "None", py::arg("theSequence"));
cls_Contap_TheHSequenceOfPoint.def("ChangeSequence", (Contap_TheSequenceOfPoint & (Contap_TheHSequenceOfPoint::*)()) &Contap_TheHSequenceOfPoint::ChangeSequence, "None");
cls_Contap_TheHSequenceOfPoint.def_static("get_type_name_", (const char * (*)()) &Contap_TheHSequenceOfPoint::get_type_name, "None");
cls_Contap_TheHSequenceOfPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Contap_TheHSequenceOfPoint::get_type_descriptor, "None");
cls_Contap_TheHSequenceOfPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (Contap_TheHSequenceOfPoint::*)() const) &Contap_TheHSequenceOfPoint::DynamicType, "None");

// Enums

}