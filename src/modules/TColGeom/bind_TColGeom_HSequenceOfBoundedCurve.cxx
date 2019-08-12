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
#include <TColGeom_SequenceOfBoundedCurve.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TColGeom_HSequenceOfBoundedCurve.hxx>
#include <Standard_Type.hxx>

void bind_TColGeom_HSequenceOfBoundedCurve(py::module &mod){

py::class_<TColGeom_HSequenceOfBoundedCurve, opencascade::handle<TColGeom_HSequenceOfBoundedCurve>, Standard_Transient> cls_TColGeom_HSequenceOfBoundedCurve(mod, "TColGeom_HSequenceOfBoundedCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom_HSequenceOfBoundedCurve.def(py::init<>());
cls_TColGeom_HSequenceOfBoundedCurve.def(py::init<const TColGeom_SequenceOfBoundedCurve &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom_HSequenceOfBoundedCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom_HSequenceOfBoundedCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom_HSequenceOfBoundedCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom_HSequenceOfBoundedCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom_HSequenceOfBoundedCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom_HSequenceOfBoundedCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HSequenceOfBoundedCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom_HSequenceOfBoundedCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HSequenceOfBoundedCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom_HSequenceOfBoundedCurve.def("Sequence", (const TColGeom_SequenceOfBoundedCurve & (TColGeom_HSequenceOfBoundedCurve::*)() const) &TColGeom_HSequenceOfBoundedCurve::Sequence, "None");
cls_TColGeom_HSequenceOfBoundedCurve.def("Append", (void (TColGeom_HSequenceOfBoundedCurve::*)(const TColGeom_SequenceOfBoundedCurve::value_type &)) &TColGeom_HSequenceOfBoundedCurve::Append, "None", py::arg("theItem"));
cls_TColGeom_HSequenceOfBoundedCurve.def("Append", (void (TColGeom_HSequenceOfBoundedCurve::*)(TColGeom_SequenceOfBoundedCurve &)) &TColGeom_HSequenceOfBoundedCurve::Append, "None", py::arg("theSequence"));
cls_TColGeom_HSequenceOfBoundedCurve.def("ChangeSequence", (TColGeom_SequenceOfBoundedCurve & (TColGeom_HSequenceOfBoundedCurve::*)()) &TColGeom_HSequenceOfBoundedCurve::ChangeSequence, "None");
cls_TColGeom_HSequenceOfBoundedCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom_HSequenceOfBoundedCurve::get_type_name, "None");
cls_TColGeom_HSequenceOfBoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HSequenceOfBoundedCurve::get_type_descriptor, "None");
cls_TColGeom_HSequenceOfBoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HSequenceOfBoundedCurve::*)() const) &TColGeom_HSequenceOfBoundedCurve::DynamicType, "None");

// Enums

}