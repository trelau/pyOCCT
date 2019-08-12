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
#include <Standard_OStream.hxx>
#include <Vrml_Scale.hxx>

void bind_Vrml_Scale(py::module &mod){

py::class_<Vrml_Scale, std::unique_ptr<Vrml_Scale, Deleter<Vrml_Scale>>> cls_Vrml_Scale(mod, "Vrml_Scale", "defines a Scale node of VRML specifying transform properties. This node defines a 3D scaling about the origin. By default : myRotation = (1 1 1)");

// Constructors
cls_Vrml_Scale.def(py::init<>());
cls_Vrml_Scale.def(py::init<const gp_Vec &>(), py::arg("aScaleFactor"));

// Fields

// Methods
// cls_Vrml_Scale.def_static("operator new_", (void * (*)(size_t)) &Vrml_Scale::operator new, "None", py::arg("theSize"));
// cls_Vrml_Scale.def_static("operator delete_", (void (*)(void *)) &Vrml_Scale::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Scale.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Scale::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Scale.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Scale::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Scale.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Scale::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Scale.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Scale::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Scale.def("SetScaleFactor", (void (Vrml_Scale::*)(const gp_Vec &)) &Vrml_Scale::SetScaleFactor, "None", py::arg("aScaleFactor"));
cls_Vrml_Scale.def("ScaleFactor", (gp_Vec (Vrml_Scale::*)() const) &Vrml_Scale::ScaleFactor, "None");
cls_Vrml_Scale.def("Print", (Standard_OStream & (Vrml_Scale::*)(Standard_OStream &) const) &Vrml_Scale::Print, "None", py::arg("anOStream"));

// Enums

}