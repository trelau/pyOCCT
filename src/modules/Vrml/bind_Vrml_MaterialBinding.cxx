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
#include <Standard.hxx>
#include <Vrml_MaterialBindingAndNormalBinding.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_MaterialBinding.hxx>

void bind_Vrml_MaterialBinding(py::module &mod){

py::class_<Vrml_MaterialBinding, std::unique_ptr<Vrml_MaterialBinding, Deleter<Vrml_MaterialBinding>>> cls_Vrml_MaterialBinding(mod, "Vrml_MaterialBinding", "defines a MaterialBinding node of VRML specifying properties of geometry and its appearance. Material nodes may contain more than one material. This node specifies how the current materials are bound to shapes that follow in the scene graph. Each shape node may interpret bindings differently. For example, a Sphere node is always drawn using the first material in the material node, no matter what the current MaterialBinding, while a Cube node may use six different materials to draw each of its six faces, depending on the MaterialBinding.");

// Constructors
cls_Vrml_MaterialBinding.def(py::init<const Vrml_MaterialBindingAndNormalBinding>(), py::arg("aValue"));
cls_Vrml_MaterialBinding.def(py::init<>());

// Fields

// Methods
// cls_Vrml_MaterialBinding.def_static("operator new_", (void * (*)(size_t)) &Vrml_MaterialBinding::operator new, "None", py::arg("theSize"));
// cls_Vrml_MaterialBinding.def_static("operator delete_", (void (*)(void *)) &Vrml_MaterialBinding::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_MaterialBinding.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_MaterialBinding::operator new[], "None", py::arg("theSize"));
// cls_Vrml_MaterialBinding.def_static("operator delete[]_", (void (*)(void *)) &Vrml_MaterialBinding::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_MaterialBinding.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_MaterialBinding::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_MaterialBinding.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_MaterialBinding::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_MaterialBinding.def("SetValue", (void (Vrml_MaterialBinding::*)(const Vrml_MaterialBindingAndNormalBinding)) &Vrml_MaterialBinding::SetValue, "None", py::arg("aValue"));
cls_Vrml_MaterialBinding.def("Value", (Vrml_MaterialBindingAndNormalBinding (Vrml_MaterialBinding::*)() const) &Vrml_MaterialBinding::Value, "None");
cls_Vrml_MaterialBinding.def("Print", (Standard_OStream & (Vrml_MaterialBinding::*)(Standard_OStream &) const) &Vrml_MaterialBinding::Print, "None", py::arg("anOStream"));

// Enums

}