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
#include <Standard_Transient.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <Standard_Type.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>

void bind_Graphic3d_SequenceOfHClipPlane(py::module &mod){

py::class_<Graphic3d_SequenceOfHClipPlane, opencascade::handle<Graphic3d_SequenceOfHClipPlane>, Standard_Transient> cls_Graphic3d_SequenceOfHClipPlane(mod, "Graphic3d_SequenceOfHClipPlane", "Class defining the sequence of clipping planes.", py::multiple_inheritance());

// Constructors
cls_Graphic3d_SequenceOfHClipPlane.def(py::init<>());

// Fields

// Methods
cls_Graphic3d_SequenceOfHClipPlane.def_static("get_type_name_", (const char * (*)()) &Graphic3d_SequenceOfHClipPlane::get_type_name, "None");
cls_Graphic3d_SequenceOfHClipPlane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_SequenceOfHClipPlane::get_type_descriptor, "None");
cls_Graphic3d_SequenceOfHClipPlane.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_SequenceOfHClipPlane::*)() const) &Graphic3d_SequenceOfHClipPlane::DynamicType, "None");
// cls_Graphic3d_SequenceOfHClipPlane.def_static("operator new_", (void * (*)(size_t)) &Graphic3d_SequenceOfHClipPlane::operator new, "None", py::arg("theSize"));
// cls_Graphic3d_SequenceOfHClipPlane.def_static("operator delete_", (void (*)(void *)) &Graphic3d_SequenceOfHClipPlane::operator delete, "None", py::arg("theAddress"));
// cls_Graphic3d_SequenceOfHClipPlane.def_static("operator new[]_", (void * (*)(size_t)) &Graphic3d_SequenceOfHClipPlane::operator new[], "None", py::arg("theSize"));
// cls_Graphic3d_SequenceOfHClipPlane.def_static("operator delete[]_", (void (*)(void *)) &Graphic3d_SequenceOfHClipPlane::operator delete[], "None", py::arg("theAddress"));
// cls_Graphic3d_SequenceOfHClipPlane.def_static("operator new_", (void * (*)(size_t, void *)) &Graphic3d_SequenceOfHClipPlane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Graphic3d_SequenceOfHClipPlane.def_static("operator delete_", (void (*)(void *, void *)) &Graphic3d_SequenceOfHClipPlane::operator delete, "None", py::arg(""), py::arg(""));
// cls_Graphic3d_SequenceOfHClipPlane.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Graphic3d_SequenceOfHClipPlane::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Graphic3d_SequenceOfHClipPlane.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Graphic3d_SequenceOfHClipPlane::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Graphic3d_SequenceOfHClipPlane.def("ToOverrideGlobal", (Standard_Boolean (Graphic3d_SequenceOfHClipPlane::*)() const) &Graphic3d_SequenceOfHClipPlane::ToOverrideGlobal, "Return true if local properties should override global properties.");
cls_Graphic3d_SequenceOfHClipPlane.def("SetOverrideGlobal", (void (Graphic3d_SequenceOfHClipPlane::*)(const Standard_Boolean)) &Graphic3d_SequenceOfHClipPlane::SetOverrideGlobal, "Setup flag defining if local properties should override global properties.", py::arg("theToOverride"));

// Enums

}