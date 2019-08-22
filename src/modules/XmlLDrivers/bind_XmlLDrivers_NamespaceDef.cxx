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
#include <XmlLDrivers_NamespaceDef.hxx>

void bind_XmlLDrivers_NamespaceDef(py::module &mod){

py::class_<XmlLDrivers_NamespaceDef> cls_XmlLDrivers_NamespaceDef(mod, "XmlLDrivers_NamespaceDef", "None");

// Constructors
cls_XmlLDrivers_NamespaceDef.def(py::init<>());
cls_XmlLDrivers_NamespaceDef.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("thePrefix"), py::arg("theURI"));

// Fields

// Methods
// cls_XmlLDrivers_NamespaceDef.def_static("operator new_", (void * (*)(size_t)) &XmlLDrivers_NamespaceDef::operator new, "None", py::arg("theSize"));
// cls_XmlLDrivers_NamespaceDef.def_static("operator delete_", (void (*)(void *)) &XmlLDrivers_NamespaceDef::operator delete, "None", py::arg("theAddress"));
// cls_XmlLDrivers_NamespaceDef.def_static("operator new[]_", (void * (*)(size_t)) &XmlLDrivers_NamespaceDef::operator new[], "None", py::arg("theSize"));
// cls_XmlLDrivers_NamespaceDef.def_static("operator delete[]_", (void (*)(void *)) &XmlLDrivers_NamespaceDef::operator delete[], "None", py::arg("theAddress"));
// cls_XmlLDrivers_NamespaceDef.def_static("operator new_", (void * (*)(size_t, void *)) &XmlLDrivers_NamespaceDef::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlLDrivers_NamespaceDef.def_static("operator delete_", (void (*)(void *, void *)) &XmlLDrivers_NamespaceDef::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlLDrivers_NamespaceDef.def("Prefix", (const TCollection_AsciiString & (XmlLDrivers_NamespaceDef::*)() const) &XmlLDrivers_NamespaceDef::Prefix, "None");
cls_XmlLDrivers_NamespaceDef.def("URI", (const TCollection_AsciiString & (XmlLDrivers_NamespaceDef::*)() const) &XmlLDrivers_NamespaceDef::URI, "None");

// Enums

}