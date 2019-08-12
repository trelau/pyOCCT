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
#include <GeomPlate_SequenceOfPointConstraint.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <GeomPlate_HSequenceOfPointConstraint.hxx>
#include <Standard_Type.hxx>

void bind_GeomPlate_HSequenceOfPointConstraint(py::module &mod){

py::class_<GeomPlate_HSequenceOfPointConstraint, opencascade::handle<GeomPlate_HSequenceOfPointConstraint>, Standard_Transient> cls_GeomPlate_HSequenceOfPointConstraint(mod, "GeomPlate_HSequenceOfPointConstraint", "None", py::multiple_inheritance());

// Constructors
cls_GeomPlate_HSequenceOfPointConstraint.def(py::init<>());
cls_GeomPlate_HSequenceOfPointConstraint.def(py::init<const GeomPlate_SequenceOfPointConstraint &>(), py::arg("theOther"));

// Fields

// Methods
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_HSequenceOfPointConstraint::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator delete_", (void (*)(void *)) &GeomPlate_HSequenceOfPointConstraint::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_HSequenceOfPointConstraint::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_HSequenceOfPointConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_HSequenceOfPointConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_HSequenceOfPointConstraint::operator delete, "None", py::arg(""), py::arg(""));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HSequenceOfPointConstraint::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_GeomPlate_HSequenceOfPointConstraint.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HSequenceOfPointConstraint::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_GeomPlate_HSequenceOfPointConstraint.def("Sequence", (const GeomPlate_SequenceOfPointConstraint & (GeomPlate_HSequenceOfPointConstraint::*)() const) &GeomPlate_HSequenceOfPointConstraint::Sequence, "None");
cls_GeomPlate_HSequenceOfPointConstraint.def("Append", (void (GeomPlate_HSequenceOfPointConstraint::*)(const GeomPlate_SequenceOfPointConstraint::value_type &)) &GeomPlate_HSequenceOfPointConstraint::Append, "None", py::arg("theItem"));
cls_GeomPlate_HSequenceOfPointConstraint.def("Append", (void (GeomPlate_HSequenceOfPointConstraint::*)(GeomPlate_SequenceOfPointConstraint &)) &GeomPlate_HSequenceOfPointConstraint::Append, "None", py::arg("theSequence"));
cls_GeomPlate_HSequenceOfPointConstraint.def("ChangeSequence", (GeomPlate_SequenceOfPointConstraint & (GeomPlate_HSequenceOfPointConstraint::*)()) &GeomPlate_HSequenceOfPointConstraint::ChangeSequence, "None");
cls_GeomPlate_HSequenceOfPointConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HSequenceOfPointConstraint::get_type_name, "None");
cls_GeomPlate_HSequenceOfPointConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HSequenceOfPointConstraint::get_type_descriptor, "None");
cls_GeomPlate_HSequenceOfPointConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HSequenceOfPointConstraint::*)() const) &GeomPlate_HSequenceOfPointConstraint::DynamicType, "None");

// Enums

}