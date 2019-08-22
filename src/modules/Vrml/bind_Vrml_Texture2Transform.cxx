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
#include <gp_Vec2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Texture2Transform.hxx>

void bind_Vrml_Texture2Transform(py::module &mod){

py::class_<Vrml_Texture2Transform> cls_Vrml_Texture2Transform(mod, "Vrml_Texture2Transform", "defines a Texture2Transform node of VRML specifying properties of geometry and its appearance. This node defines a 2D transformation applied to texture coordinates. This affect the way textures are applied to the surfaces of subsequent shapes. Transformation consisits of(in order) a non-uniform scale about an arbitrary center point, a rotation about that same point, and a translation. This allows a user to change the size and position of the textures on the shape. By default : myTranslation (0 0) myRotation (0) myScaleFactor (1 1) myCenter (0 0)");

// Constructors
cls_Vrml_Texture2Transform.def(py::init<>());
cls_Vrml_Texture2Transform.def(py::init<const gp_Vec2d &, const Standard_Real, const gp_Vec2d &, const gp_Vec2d &>(), py::arg("aTranslation"), py::arg("aRotation"), py::arg("aScaleFactor"), py::arg("aCenter"));

// Fields

// Methods
// cls_Vrml_Texture2Transform.def_static("operator new_", (void * (*)(size_t)) &Vrml_Texture2Transform::operator new, "None", py::arg("theSize"));
// cls_Vrml_Texture2Transform.def_static("operator delete_", (void (*)(void *)) &Vrml_Texture2Transform::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Texture2Transform.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Texture2Transform::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Texture2Transform.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Texture2Transform::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Texture2Transform.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Texture2Transform::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Texture2Transform.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Texture2Transform::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Texture2Transform.def("SetTranslation", (void (Vrml_Texture2Transform::*)(const gp_Vec2d &)) &Vrml_Texture2Transform::SetTranslation, "None", py::arg("aTranslation"));
cls_Vrml_Texture2Transform.def("Translation", (gp_Vec2d (Vrml_Texture2Transform::*)() const) &Vrml_Texture2Transform::Translation, "None");
cls_Vrml_Texture2Transform.def("SetRotation", (void (Vrml_Texture2Transform::*)(const Standard_Real)) &Vrml_Texture2Transform::SetRotation, "None", py::arg("aRotation"));
cls_Vrml_Texture2Transform.def("Rotation", (Standard_Real (Vrml_Texture2Transform::*)() const) &Vrml_Texture2Transform::Rotation, "None");
cls_Vrml_Texture2Transform.def("SetScaleFactor", (void (Vrml_Texture2Transform::*)(const gp_Vec2d &)) &Vrml_Texture2Transform::SetScaleFactor, "None", py::arg("aScaleFactor"));
cls_Vrml_Texture2Transform.def("ScaleFactor", (gp_Vec2d (Vrml_Texture2Transform::*)() const) &Vrml_Texture2Transform::ScaleFactor, "None");
cls_Vrml_Texture2Transform.def("SetCenter", (void (Vrml_Texture2Transform::*)(const gp_Vec2d &)) &Vrml_Texture2Transform::SetCenter, "None", py::arg("aCenter"));
cls_Vrml_Texture2Transform.def("Center", (gp_Vec2d (Vrml_Texture2Transform::*)() const) &Vrml_Texture2Transform::Center, "None");
cls_Vrml_Texture2Transform.def("Print", (Standard_OStream & (Vrml_Texture2Transform::*)(Standard_OStream &) const) &Vrml_Texture2Transform::Print, "None", py::arg("anOStream"));

// Enums

}