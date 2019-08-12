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
#include <Vrml_Translation.hxx>

void bind_Vrml_Translation(py::module &mod){

py::class_<Vrml_Translation, std::unique_ptr<Vrml_Translation, Deleter<Vrml_Translation>>> cls_Vrml_Translation(mod, "Vrml_Translation", "defines a Translation of VRML specifying transform properties. This node defines a translation by 3D vector. By default : myTranslation (0,0,0)");

// Constructors
cls_Vrml_Translation.def(py::init<>());
cls_Vrml_Translation.def(py::init<const gp_Vec &>(), py::arg("aTranslation"));

// Fields

// Methods
// cls_Vrml_Translation.def_static("operator new_", (void * (*)(size_t)) &Vrml_Translation::operator new, "None", py::arg("theSize"));
// cls_Vrml_Translation.def_static("operator delete_", (void (*)(void *)) &Vrml_Translation::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Translation.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Translation::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Translation.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Translation::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Translation.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Translation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Translation.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Translation::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Translation.def("SetTranslation", (void (Vrml_Translation::*)(const gp_Vec &)) &Vrml_Translation::SetTranslation, "None", py::arg("aTranslation"));
cls_Vrml_Translation.def("Translation", (gp_Vec (Vrml_Translation::*)() const) &Vrml_Translation::Translation, "None");
cls_Vrml_Translation.def("Print", (Standard_OStream & (Vrml_Translation::*)(Standard_OStream &) const) &Vrml_Translation::Print, "None", py::arg("anOStream"));

// Enums

}