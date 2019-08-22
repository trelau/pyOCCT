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
#include <Standard_Handle.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlMNaming_NamedShapeDriver.hxx>
#include <XmlMNaming_NamingDriver.hxx>
#include <XmlMNaming_Shape1.hxx>
#include <XmlMNaming.hxx>

void bind_XmlMNaming(py::module &mod){

py::class_<XmlMNaming> cls_XmlMNaming(mod, "XmlMNaming", "None");

// Constructors

// Fields

// Methods
// cls_XmlMNaming.def_static("operator new_", (void * (*)(size_t)) &XmlMNaming::operator new, "None", py::arg("theSize"));
// cls_XmlMNaming.def_static("operator delete_", (void (*)(void *)) &XmlMNaming::operator delete, "None", py::arg("theAddress"));
// cls_XmlMNaming.def_static("operator new[]_", (void * (*)(size_t)) &XmlMNaming::operator new[], "None", py::arg("theSize"));
// cls_XmlMNaming.def_static("operator delete[]_", (void (*)(void *)) &XmlMNaming::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMNaming.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMNaming::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMNaming.def_static("operator delete_", (void (*)(void *, void *)) &XmlMNaming::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMNaming.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMNaming::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("aMessageDriver"));
cls_XmlMNaming.def_static("SetDocumentVersion_", (void (*)(const Standard_Integer)) &XmlMNaming::SetDocumentVersion, "None", py::arg("DocVersion"));
cls_XmlMNaming.def_static("DocumentVersion_", (Standard_Integer (*)()) &XmlMNaming::DocumentVersion, "None");

// Enums

}