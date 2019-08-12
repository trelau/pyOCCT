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
#include <GeomPlate_SequenceOfCurveConstraint.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <GeomPlate_HSequenceOfCurveConstraint.hxx>
#include <Standard_Type.hxx>

void bind_GeomPlate_HSequenceOfCurveConstraint(py::module &mod){

py::class_<GeomPlate_HSequenceOfCurveConstraint, opencascade::handle<GeomPlate_HSequenceOfCurveConstraint>, Standard_Transient> cls_GeomPlate_HSequenceOfCurveConstraint(mod, "GeomPlate_HSequenceOfCurveConstraint", "None", py::multiple_inheritance());

// Constructors
cls_GeomPlate_HSequenceOfCurveConstraint.def(py::init<>());
cls_GeomPlate_HSequenceOfCurveConstraint.def(py::init<const GeomPlate_SequenceOfCurveConstraint &>(), py::arg("theOther"));

// Fields

// Methods
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_HSequenceOfCurveConstraint::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator delete_", (void (*)(void *)) &GeomPlate_HSequenceOfCurveConstraint::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_HSequenceOfCurveConstraint::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_HSequenceOfCurveConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_HSequenceOfCurveConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_HSequenceOfCurveConstraint::operator delete, "None", py::arg(""), py::arg(""));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HSequenceOfCurveConstraint::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_GeomPlate_HSequenceOfCurveConstraint.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &GeomPlate_HSequenceOfCurveConstraint::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_GeomPlate_HSequenceOfCurveConstraint.def("Sequence", (const GeomPlate_SequenceOfCurveConstraint & (GeomPlate_HSequenceOfCurveConstraint::*)() const) &GeomPlate_HSequenceOfCurveConstraint::Sequence, "None");
cls_GeomPlate_HSequenceOfCurveConstraint.def("Append", (void (GeomPlate_HSequenceOfCurveConstraint::*)(const GeomPlate_SequenceOfCurveConstraint::value_type &)) &GeomPlate_HSequenceOfCurveConstraint::Append, "None", py::arg("theItem"));
cls_GeomPlate_HSequenceOfCurveConstraint.def("Append", (void (GeomPlate_HSequenceOfCurveConstraint::*)(GeomPlate_SequenceOfCurveConstraint &)) &GeomPlate_HSequenceOfCurveConstraint::Append, "None", py::arg("theSequence"));
cls_GeomPlate_HSequenceOfCurveConstraint.def("ChangeSequence", (GeomPlate_SequenceOfCurveConstraint & (GeomPlate_HSequenceOfCurveConstraint::*)()) &GeomPlate_HSequenceOfCurveConstraint::ChangeSequence, "None");
cls_GeomPlate_HSequenceOfCurveConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_HSequenceOfCurveConstraint::get_type_name, "None");
cls_GeomPlate_HSequenceOfCurveConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_HSequenceOfCurveConstraint::get_type_descriptor, "None");
cls_GeomPlate_HSequenceOfCurveConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_HSequenceOfCurveConstraint::*)() const) &GeomPlate_HSequenceOfCurveConstraint::DynamicType, "None");

// Enums

}