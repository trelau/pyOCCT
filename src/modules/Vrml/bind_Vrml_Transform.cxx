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
#include <gp_Vec.hxx>
#include <Vrml_SFRotation.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Transform.hxx>

void bind_Vrml_Transform(py::module &mod){

py::class_<Vrml_Transform, std::unique_ptr<Vrml_Transform, Deleter<Vrml_Transform>>> cls_Vrml_Transform(mod, "Vrml_Transform", "defines a Transform of VRML specifying transform properties. This node defines a geometric 3D transformation consisting of (in order) a (possibly) non-uniform scale about an arbitrary point, a rotation about an arbitrary point and axis and translation. By default : myTranslation (0,0,0) myRotation (0,0,1,0) myScaleFactor (1,1,1) myScaleOrientation (0,0,1,0) myCenter (0,0,0)");

// Constructors
cls_Vrml_Transform.def(py::init<>());
cls_Vrml_Transform.def(py::init<const gp_Vec &, const Vrml_SFRotation &, const gp_Vec &, const Vrml_SFRotation &, const gp_Vec &>(), py::arg("aTranslation"), py::arg("aRotation"), py::arg("aScaleFactor"), py::arg("aScaleOrientation"), py::arg("aCenter"));

// Fields

// Methods
// cls_Vrml_Transform.def_static("operator new_", (void * (*)(size_t)) &Vrml_Transform::operator new, "None", py::arg("theSize"));
// cls_Vrml_Transform.def_static("operator delete_", (void (*)(void *)) &Vrml_Transform::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Transform.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Transform::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Transform.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Transform::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Transform.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Transform::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Transform.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Transform::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Transform.def("SetTranslation", (void (Vrml_Transform::*)(const gp_Vec &)) &Vrml_Transform::SetTranslation, "None", py::arg("aTranslation"));
cls_Vrml_Transform.def("Translation", (gp_Vec (Vrml_Transform::*)() const) &Vrml_Transform::Translation, "None");
cls_Vrml_Transform.def("SetRotation", (void (Vrml_Transform::*)(const Vrml_SFRotation &)) &Vrml_Transform::SetRotation, "None", py::arg("aRotation"));
cls_Vrml_Transform.def("Rotation", (Vrml_SFRotation (Vrml_Transform::*)() const) &Vrml_Transform::Rotation, "None");
cls_Vrml_Transform.def("SetScaleFactor", (void (Vrml_Transform::*)(const gp_Vec &)) &Vrml_Transform::SetScaleFactor, "None", py::arg("aScaleFactor"));
cls_Vrml_Transform.def("ScaleFactor", (gp_Vec (Vrml_Transform::*)() const) &Vrml_Transform::ScaleFactor, "None");
cls_Vrml_Transform.def("SetScaleOrientation", (void (Vrml_Transform::*)(const Vrml_SFRotation &)) &Vrml_Transform::SetScaleOrientation, "None", py::arg("aScaleOrientation"));
cls_Vrml_Transform.def("ScaleOrientation", (Vrml_SFRotation (Vrml_Transform::*)() const) &Vrml_Transform::ScaleOrientation, "None");
cls_Vrml_Transform.def("SetCenter", (void (Vrml_Transform::*)(const gp_Vec &)) &Vrml_Transform::SetCenter, "None", py::arg("aCenter"));
cls_Vrml_Transform.def("Center", (gp_Vec (Vrml_Transform::*)() const) &Vrml_Transform::Center, "None");
cls_Vrml_Transform.def("Print", (Standard_OStream & (Vrml_Transform::*)(Standard_OStream &) const) &Vrml_Transform::Print, "None", py::arg("anOStream"));

// Enums

}