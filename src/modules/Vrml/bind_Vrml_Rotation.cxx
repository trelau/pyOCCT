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
#include <Vrml_SFRotation.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Rotation.hxx>

void bind_Vrml_Rotation(py::module &mod){

py::class_<Vrml_Rotation, std::unique_ptr<Vrml_Rotation>> cls_Vrml_Rotation(mod, "Vrml_Rotation", "defines a Rotation node of VRML specifying matrix and transform properties. This node defines a 3D rotation about an arbitrary axis through the origin. By default : myRotation = (0 0 1 0)");

// Constructors
cls_Vrml_Rotation.def(py::init<>());
cls_Vrml_Rotation.def(py::init<const Vrml_SFRotation &>(), py::arg("aRotation"));

// Fields

// Methods
// cls_Vrml_Rotation.def_static("operator new_", (void * (*)(size_t)) &Vrml_Rotation::operator new, "None", py::arg("theSize"));
// cls_Vrml_Rotation.def_static("operator delete_", (void (*)(void *)) &Vrml_Rotation::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Rotation.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Rotation::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Rotation.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Rotation::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Rotation.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Rotation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Rotation.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Rotation::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Rotation.def("SetRotation", (void (Vrml_Rotation::*)(const Vrml_SFRotation &)) &Vrml_Rotation::SetRotation, "None", py::arg("aRotation"));
cls_Vrml_Rotation.def("Rotation", (Vrml_SFRotation (Vrml_Rotation::*)() const) &Vrml_Rotation::Rotation, "None");
cls_Vrml_Rotation.def("Print", (Standard_OStream & (Vrml_Rotation::*)(Standard_OStream &) const) &Vrml_Rotation::Print, "None", py::arg("anOStream"));

// Enums

}