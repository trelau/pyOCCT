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
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <BinMNaming_NamedShapeDriver.hxx>
#include <BinMNaming_NamingDriver.hxx>
#include <BinMNaming.hxx>

void bind_BinMNaming(py::module &mod){

py::class_<BinMNaming, std::unique_ptr<BinMNaming, Deleter<BinMNaming>>> cls_BinMNaming(mod, "BinMNaming", "Storage/Retrieval drivers for TNaming attributes");

// Constructors

// Fields

// Methods
// cls_BinMNaming.def_static("operator new_", (void * (*)(size_t)) &BinMNaming::operator new, "None", py::arg("theSize"));
// cls_BinMNaming.def_static("operator delete_", (void (*)(void *)) &BinMNaming::operator delete, "None", py::arg("theAddress"));
// cls_BinMNaming.def_static("operator new[]_", (void * (*)(size_t)) &BinMNaming::operator new[], "None", py::arg("theSize"));
// cls_BinMNaming.def_static("operator delete[]_", (void (*)(void *)) &BinMNaming::operator delete[], "None", py::arg("theAddress"));
// cls_BinMNaming.def_static("operator new_", (void * (*)(size_t, void *)) &BinMNaming::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinMNaming.def_static("operator delete_", (void (*)(void *, void *)) &BinMNaming::operator delete, "None", py::arg(""), py::arg(""));
cls_BinMNaming.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinMNaming::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));
cls_BinMNaming.def_static("SetDocumentVersion_", (void (*)(const Standard_Integer)) &BinMNaming::SetDocumentVersion, "None", py::arg("DocVersion"));
cls_BinMNaming.def_static("DocumentVersion_", (Standard_Integer (*)()) &BinMNaming::DocumentVersion, "None");

// Enums

}