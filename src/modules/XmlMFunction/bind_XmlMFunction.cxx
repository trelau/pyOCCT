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
#include <XmlMFunction_FunctionDriver.hxx>
#include <XmlMFunction_ScopeDriver.hxx>
#include <XmlMFunction_GraphNodeDriver.hxx>
#include <XmlMFunction.hxx>

void bind_XmlMFunction(py::module &mod){

py::class_<XmlMFunction, std::unique_ptr<XmlMFunction, Deleter<XmlMFunction>>> cls_XmlMFunction(mod, "XmlMFunction", "None");

// Constructors

// Fields

// Methods
// cls_XmlMFunction.def_static("operator new_", (void * (*)(size_t)) &XmlMFunction::operator new, "None", py::arg("theSize"));
// cls_XmlMFunction.def_static("operator delete_", (void (*)(void *)) &XmlMFunction::operator delete, "None", py::arg("theAddress"));
// cls_XmlMFunction.def_static("operator new[]_", (void * (*)(size_t)) &XmlMFunction::operator new[], "None", py::arg("theSize"));
// cls_XmlMFunction.def_static("operator delete[]_", (void (*)(void *)) &XmlMFunction::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMFunction.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMFunction.def_static("operator delete_", (void (*)(void *, void *)) &XmlMFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMFunction.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMFunction::AddDrivers, "Adds the attribute storage drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("theMessageDriver"));

// Enums

}