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
#include <BinMDF_ADriver.hxx>
#include <BinMDF_ReferenceDriver.hxx>
#include <BinMDF_TagSourceDriver.hxx>
#include <BinMDF.hxx>

void bind_BinMDF(py::module &mod){

py::class_<BinMDF, std::unique_ptr<BinMDF>> cls_BinMDF(mod, "BinMDF", "This package provides classes and methods to translate a transient DF into a persistent one and vice versa.");

// Constructors

// Fields

// Methods
// cls_BinMDF.def_static("operator new_", (void * (*)(size_t)) &BinMDF::operator new, "None", py::arg("theSize"));
// cls_BinMDF.def_static("operator delete_", (void (*)(void *)) &BinMDF::operator delete, "None", py::arg("theAddress"));
// cls_BinMDF.def_static("operator new[]_", (void * (*)(size_t)) &BinMDF::operator new[], "None", py::arg("theSize"));
// cls_BinMDF.def_static("operator delete[]_", (void (*)(void *)) &BinMDF::operator delete[], "None", py::arg("theAddress"));
// cls_BinMDF.def_static("operator new_", (void * (*)(size_t, void *)) &BinMDF::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinMDF.def_static("operator delete_", (void (*)(void *, void *)) &BinMDF::operator delete, "None", py::arg(""), py::arg(""));
cls_BinMDF.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinMDF::AddDrivers, "Adds the attribute storage drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("aMsgDrv"));

// Enums

}