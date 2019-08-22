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
#include <XmlMDocStd_XLinkDriver.hxx>
#include <XmlMDocStd.hxx>

void bind_XmlMDocStd(py::module &mod){

py::class_<XmlMDocStd> cls_XmlMDocStd(mod, "XmlMDocStd", "Driver for TDocStd_XLink");

// Constructors

// Fields

// Methods
// cls_XmlMDocStd.def_static("operator new_", (void * (*)(size_t)) &XmlMDocStd::operator new, "None", py::arg("theSize"));
// cls_XmlMDocStd.def_static("operator delete_", (void (*)(void *)) &XmlMDocStd::operator delete, "None", py::arg("theAddress"));
// cls_XmlMDocStd.def_static("operator new[]_", (void * (*)(size_t)) &XmlMDocStd::operator new[], "None", py::arg("theSize"));
// cls_XmlMDocStd.def_static("operator delete[]_", (void (*)(void *)) &XmlMDocStd::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMDocStd.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMDocStd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMDocStd.def_static("operator delete_", (void (*)(void *, void *)) &XmlMDocStd::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMDocStd.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMDocStd::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("theMessageDriver"));

// Enums

}