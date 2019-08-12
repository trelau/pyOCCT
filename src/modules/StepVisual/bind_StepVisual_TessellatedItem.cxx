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
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepVisual_TessellatedItem.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_TessellatedItem(py::module &mod){

py::class_<StepVisual_TessellatedItem, opencascade::handle<StepVisual_TessellatedItem>, StepGeom_GeometricRepresentationItem> cls_StepVisual_TessellatedItem(mod, "StepVisual_TessellatedItem", "None");

// Constructors
cls_StepVisual_TessellatedItem.def(py::init<>());

// Fields

// Methods
// cls_StepVisual_TessellatedItem.def_static("operator new_", (void * (*)(size_t)) &StepVisual_TessellatedItem::operator new, "None", py::arg("theSize"));
// cls_StepVisual_TessellatedItem.def_static("operator delete_", (void (*)(void *)) &StepVisual_TessellatedItem::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_TessellatedItem.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_TessellatedItem::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_TessellatedItem.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_TessellatedItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_TessellatedItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_TessellatedItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_TessellatedItem.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_TessellatedItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepVisual_TessellatedItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_TessellatedItem::get_type_name, "None");
cls_StepVisual_TessellatedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TessellatedItem::get_type_descriptor, "None");
cls_StepVisual_TessellatedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TessellatedItem::*)() const) &StepVisual_TessellatedItem::DynamicType, "None");

// Enums

}