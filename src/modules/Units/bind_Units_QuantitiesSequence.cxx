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
#include <Units_QtsSequence.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Units_QuantitiesSequence.hxx>
#include <Standard_Type.hxx>

void bind_Units_QuantitiesSequence(py::module &mod){

py::class_<Units_QuantitiesSequence, opencascade::handle<Units_QuantitiesSequence>, Standard_Transient> cls_Units_QuantitiesSequence(mod, "Units_QuantitiesSequence", "None", py::multiple_inheritance());

// Constructors
cls_Units_QuantitiesSequence.def(py::init<>());
cls_Units_QuantitiesSequence.def(py::init<const Units_QtsSequence &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Units_QuantitiesSequence.def_static("operator new_", (void * (*)(size_t)) &Units_QuantitiesSequence::operator new, "None", py::arg("theSize"));
// cls_Units_QuantitiesSequence.def_static("operator delete_", (void (*)(void *)) &Units_QuantitiesSequence::operator delete, "None", py::arg("theAddress"));
// cls_Units_QuantitiesSequence.def_static("operator new[]_", (void * (*)(size_t)) &Units_QuantitiesSequence::operator new[], "None", py::arg("theSize"));
// cls_Units_QuantitiesSequence.def_static("operator delete[]_", (void (*)(void *)) &Units_QuantitiesSequence::operator delete[], "None", py::arg("theAddress"));
// cls_Units_QuantitiesSequence.def_static("operator new_", (void * (*)(size_t, void *)) &Units_QuantitiesSequence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Units_QuantitiesSequence.def_static("operator delete_", (void (*)(void *, void *)) &Units_QuantitiesSequence::operator delete, "None", py::arg(""), py::arg(""));
// cls_Units_QuantitiesSequence.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_QuantitiesSequence::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Units_QuantitiesSequence.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Units_QuantitiesSequence::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Units_QuantitiesSequence.def("Sequence", (const Units_QtsSequence & (Units_QuantitiesSequence::*)() const) &Units_QuantitiesSequence::Sequence, "None");
cls_Units_QuantitiesSequence.def("Append", (void (Units_QuantitiesSequence::*)(const Units_QtsSequence::value_type &)) &Units_QuantitiesSequence::Append, "None", py::arg("theItem"));
cls_Units_QuantitiesSequence.def("Append", (void (Units_QuantitiesSequence::*)(Units_QtsSequence &)) &Units_QuantitiesSequence::Append, "None", py::arg("theSequence"));
cls_Units_QuantitiesSequence.def("ChangeSequence", (Units_QtsSequence & (Units_QuantitiesSequence::*)()) &Units_QuantitiesSequence::ChangeSequence, "None");
cls_Units_QuantitiesSequence.def_static("get_type_name_", (const char * (*)()) &Units_QuantitiesSequence::get_type_name, "None");
cls_Units_QuantitiesSequence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Units_QuantitiesSequence::get_type_descriptor, "None");
cls_Units_QuantitiesSequence.def("DynamicType", (const opencascade::handle<Standard_Type> & (Units_QuantitiesSequence::*)() const) &Units_QuantitiesSequence::DynamicType, "None");

// Enums

}