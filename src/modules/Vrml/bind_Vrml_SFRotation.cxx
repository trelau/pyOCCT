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
#include <Standard_TypeDef.hxx>
#include <Vrml_SFRotation.hxx>

void bind_Vrml_SFRotation(py::module &mod){

py::class_<Vrml_SFRotation> cls_Vrml_SFRotation(mod, "Vrml_SFRotation", "defines SFRotation type of VRML field types. The 4 values represent an axis of rotation followed by amount of right-handed rotation about the that axis, in radians.");

// Constructors
cls_Vrml_SFRotation.def(py::init<>());
cls_Vrml_SFRotation.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aRotationX"), py::arg("aRotationY"), py::arg("aRotationZ"), py::arg("anAngle"));

// Fields

// Methods
// cls_Vrml_SFRotation.def_static("operator new_", (void * (*)(size_t)) &Vrml_SFRotation::operator new, "None", py::arg("theSize"));
// cls_Vrml_SFRotation.def_static("operator delete_", (void (*)(void *)) &Vrml_SFRotation::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_SFRotation.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_SFRotation::operator new[], "None", py::arg("theSize"));
// cls_Vrml_SFRotation.def_static("operator delete[]_", (void (*)(void *)) &Vrml_SFRotation::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_SFRotation.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_SFRotation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_SFRotation.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_SFRotation::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_SFRotation.def("SetRotationX", (void (Vrml_SFRotation::*)(const Standard_Real)) &Vrml_SFRotation::SetRotationX, "None", py::arg("aRotationX"));
cls_Vrml_SFRotation.def("RotationX", (Standard_Real (Vrml_SFRotation::*)() const) &Vrml_SFRotation::RotationX, "None");
cls_Vrml_SFRotation.def("SetRotationY", (void (Vrml_SFRotation::*)(const Standard_Real)) &Vrml_SFRotation::SetRotationY, "None", py::arg("aRotationY"));
cls_Vrml_SFRotation.def("RotationY", (Standard_Real (Vrml_SFRotation::*)() const) &Vrml_SFRotation::RotationY, "None");
cls_Vrml_SFRotation.def("SetRotationZ", (void (Vrml_SFRotation::*)(const Standard_Real)) &Vrml_SFRotation::SetRotationZ, "None", py::arg("aRotationZ"));
cls_Vrml_SFRotation.def("RotationZ", (Standard_Real (Vrml_SFRotation::*)() const) &Vrml_SFRotation::RotationZ, "None");
cls_Vrml_SFRotation.def("SetAngle", (void (Vrml_SFRotation::*)(const Standard_Real)) &Vrml_SFRotation::SetAngle, "None", py::arg("anAngle"));
cls_Vrml_SFRotation.def("Angle", (Standard_Real (Vrml_SFRotation::*)() const) &Vrml_SFRotation::Angle, "None");

// Enums

}