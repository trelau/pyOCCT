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
#include <BinMDocStd_XLinkDriver.hxx>
#include <BinMDocStd.hxx>

void bind_BinMDocStd(py::module &mod){

py::class_<BinMDocStd> cls_BinMDocStd(mod, "BinMDocStd", "Storage and Retrieval drivers for TDocStd modelling attributes.");

// Constructors

// Fields

// Methods
// cls_BinMDocStd.def_static("operator new_", (void * (*)(size_t)) &BinMDocStd::operator new, "None", py::arg("theSize"));
// cls_BinMDocStd.def_static("operator delete_", (void (*)(void *)) &BinMDocStd::operator delete, "None", py::arg("theAddress"));
// cls_BinMDocStd.def_static("operator new[]_", (void * (*)(size_t)) &BinMDocStd::operator new[], "None", py::arg("theSize"));
// cls_BinMDocStd.def_static("operator delete[]_", (void (*)(void *)) &BinMDocStd::operator delete[], "None", py::arg("theAddress"));
// cls_BinMDocStd.def_static("operator new_", (void * (*)(size_t, void *)) &BinMDocStd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinMDocStd.def_static("operator delete_", (void (*)(void *, void *)) &BinMDocStd::operator delete, "None", py::arg(""), py::arg(""));
cls_BinMDocStd.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinMDocStd::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));

// Enums

}