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
#include <TCollection_AsciiString.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Info.hxx>

void bind_Vrml_Info(py::module &mod){

py::class_<Vrml_Info, std::unique_ptr<Vrml_Info>> cls_Vrml_Info(mod, "Vrml_Info", "defines a Info node of VRML specifying properties of geometry and its appearance. It is used to store information in the scene graph, Typically for application-specific purposes, copyright messages, or other strings.");

// Constructors
cls_Vrml_Info.def(py::init<>());
cls_Vrml_Info.def(py::init<const TCollection_AsciiString &>(), py::arg("aString"));

// Fields

// Methods
// cls_Vrml_Info.def_static("operator new_", (void * (*)(size_t)) &Vrml_Info::operator new, "None", py::arg("theSize"));
// cls_Vrml_Info.def_static("operator delete_", (void (*)(void *)) &Vrml_Info::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Info.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Info::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Info.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Info::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Info.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Info::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Info.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Info::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Info.def("SetString", (void (Vrml_Info::*)(const TCollection_AsciiString &)) &Vrml_Info::SetString, "None", py::arg("aString"));
cls_Vrml_Info.def("String", (TCollection_AsciiString (Vrml_Info::*)() const) &Vrml_Info::String, "None");
cls_Vrml_Info.def("Print", (Standard_OStream & (Vrml_Info::*)(Standard_OStream &) const) &Vrml_Info::Print, "None", py::arg("anOStream"));

// Enums

}