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
#include <Geom_SequenceOfBSplineSurface.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Geom_HSequenceOfBSplineSurface.hxx>
#include <Standard_Type.hxx>

void bind_Geom_HSequenceOfBSplineSurface(py::module &mod){

py::class_<Geom_HSequenceOfBSplineSurface, opencascade::handle<Geom_HSequenceOfBSplineSurface>, Standard_Transient> cls_Geom_HSequenceOfBSplineSurface(mod, "Geom_HSequenceOfBSplineSurface", "None", py::multiple_inheritance());

// Constructors
cls_Geom_HSequenceOfBSplineSurface.def(py::init<>());
cls_Geom_HSequenceOfBSplineSurface.def(py::init<const Geom_SequenceOfBSplineSurface &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Geom_HSequenceOfBSplineSurface.def_static("operator new_", (void * (*)(size_t)) &Geom_HSequenceOfBSplineSurface::operator new, "None", py::arg("theSize"));
// cls_Geom_HSequenceOfBSplineSurface.def_static("operator delete_", (void (*)(void *)) &Geom_HSequenceOfBSplineSurface::operator delete, "None", py::arg("theAddress"));
// cls_Geom_HSequenceOfBSplineSurface.def_static("operator new[]_", (void * (*)(size_t)) &Geom_HSequenceOfBSplineSurface::operator new[], "None", py::arg("theSize"));
// cls_Geom_HSequenceOfBSplineSurface.def_static("operator delete[]_", (void (*)(void *)) &Geom_HSequenceOfBSplineSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Geom_HSequenceOfBSplineSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Geom_HSequenceOfBSplineSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom_HSequenceOfBSplineSurface.def_static("operator delete_", (void (*)(void *, void *)) &Geom_HSequenceOfBSplineSurface::operator delete, "None", py::arg(""), py::arg(""));
// cls_Geom_HSequenceOfBSplineSurface.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Geom_HSequenceOfBSplineSurface::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Geom_HSequenceOfBSplineSurface.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Geom_HSequenceOfBSplineSurface::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Geom_HSequenceOfBSplineSurface.def("Sequence", (const Geom_SequenceOfBSplineSurface & (Geom_HSequenceOfBSplineSurface::*)() const) &Geom_HSequenceOfBSplineSurface::Sequence, "None");
cls_Geom_HSequenceOfBSplineSurface.def("Append", (void (Geom_HSequenceOfBSplineSurface::*)(const Geom_SequenceOfBSplineSurface::value_type &)) &Geom_HSequenceOfBSplineSurface::Append, "None", py::arg("theItem"));
cls_Geom_HSequenceOfBSplineSurface.def("Append", (void (Geom_HSequenceOfBSplineSurface::*)(Geom_SequenceOfBSplineSurface &)) &Geom_HSequenceOfBSplineSurface::Append, "None", py::arg("theSequence"));
cls_Geom_HSequenceOfBSplineSurface.def("ChangeSequence", (Geom_SequenceOfBSplineSurface & (Geom_HSequenceOfBSplineSurface::*)()) &Geom_HSequenceOfBSplineSurface::ChangeSequence, "None");
cls_Geom_HSequenceOfBSplineSurface.def_static("get_type_name_", (const char * (*)()) &Geom_HSequenceOfBSplineSurface::get_type_name, "None");
cls_Geom_HSequenceOfBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_HSequenceOfBSplineSurface::get_type_descriptor, "None");
cls_Geom_HSequenceOfBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_HSequenceOfBSplineSurface::*)() const) &Geom_HSequenceOfBSplineSurface::DynamicType, "None");

// Enums

}