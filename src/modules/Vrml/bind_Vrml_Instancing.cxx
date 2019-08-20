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
#include <Vrml_Instancing.hxx>

void bind_Vrml_Instancing(py::module &mod){

py::class_<Vrml_Instancing, std::unique_ptr<Vrml_Instancing>> cls_Vrml_Instancing(mod, "Vrml_Instancing", "defines 'instancing' - using the same instance of a node multiple times. It is accomplished by using the 'DEF' and 'USE' keywords. The DEF keyword both defines a named node, and creates a single instance of it. The USE keyword indicates that the most recently defined instance should be used again. If several nades were given the same name, then the last DEF encountered during parsing 'wins'. DEF/USE is limited to a single file.");

// Constructors
cls_Vrml_Instancing.def(py::init<const TCollection_AsciiString &>(), py::arg("aString"));

// Fields

// Methods
// cls_Vrml_Instancing.def_static("operator new_", (void * (*)(size_t)) &Vrml_Instancing::operator new, "None", py::arg("theSize"));
// cls_Vrml_Instancing.def_static("operator delete_", (void (*)(void *)) &Vrml_Instancing::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Instancing.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Instancing::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Instancing.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Instancing::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Instancing.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Instancing::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Instancing.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Instancing::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Instancing.def("DEF", (Standard_OStream & (Vrml_Instancing::*)(Standard_OStream &) const) &Vrml_Instancing::DEF, "Adds 'USE <myName>' in anOStream (VRML file).", py::arg("anOStream"));
cls_Vrml_Instancing.def("USE", (Standard_OStream & (Vrml_Instancing::*)(Standard_OStream &) const) &Vrml_Instancing::USE, "None", py::arg("anOStream"));

// Enums

}