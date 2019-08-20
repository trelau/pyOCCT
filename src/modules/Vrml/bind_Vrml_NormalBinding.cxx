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
#include <Vrml_NormalBinding.hxx>

void bind_Vrml_NormalBinding(py::module &mod){

py::class_<Vrml_NormalBinding, std::unique_ptr<Vrml_NormalBinding>> cls_Vrml_NormalBinding(mod, "Vrml_NormalBinding", "defines a NormalBinding node of VRML specifying properties of geometry and its appearance. This node specifies how the current normals are bound to shapes that follow in the scene graph. Each shape node may interpret bindings differently. The bindings for faces and vertices are meaningful only for shapes that are made from faces and vertices. Similarly, the indexed bindings are only used by the shapes that allow indexing. For bindings that require multiple normals, be sure to have at least as many normals defined as are necessary; otherwise, errors will occur.");

// Constructors
cls_Vrml_NormalBinding.def(py::init<const Vrml_MaterialBindingAndNormalBinding>(), py::arg("aValue"));
cls_Vrml_NormalBinding.def(py::init<>());

// Fields

// Methods
// cls_Vrml_NormalBinding.def_static("operator new_", (void * (*)(size_t)) &Vrml_NormalBinding::operator new, "None", py::arg("theSize"));
// cls_Vrml_NormalBinding.def_static("operator delete_", (void (*)(void *)) &Vrml_NormalBinding::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_NormalBinding.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_NormalBinding::operator new[], "None", py::arg("theSize"));
// cls_Vrml_NormalBinding.def_static("operator delete[]_", (void (*)(void *)) &Vrml_NormalBinding::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_NormalBinding.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_NormalBinding::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_NormalBinding.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_NormalBinding::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_NormalBinding.def("SetValue", (void (Vrml_NormalBinding::*)(const Vrml_MaterialBindingAndNormalBinding)) &Vrml_NormalBinding::SetValue, "None", py::arg("aValue"));
cls_Vrml_NormalBinding.def("Value", (Vrml_MaterialBindingAndNormalBinding (Vrml_NormalBinding::*)() const) &Vrml_NormalBinding::Value, "None");
cls_Vrml_NormalBinding.def("Print", (Standard_OStream & (Vrml_NormalBinding::*)(Standard_OStream &) const) &Vrml_NormalBinding::Print, "None", py::arg("anOStream"));

// Enums

}