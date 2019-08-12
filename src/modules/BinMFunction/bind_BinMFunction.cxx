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
#include <BinMFunction_FunctionDriver.hxx>
#include <BinMFunction_GraphNodeDriver.hxx>
#include <BinMFunction_ScopeDriver.hxx>
#include <BinMFunction.hxx>

void bind_BinMFunction(py::module &mod){

py::class_<BinMFunction, std::unique_ptr<BinMFunction, Deleter<BinMFunction>>> cls_BinMFunction(mod, "BinMFunction", "Storage and Retrieval drivers for TFunction modelling attributes.");

// Constructors

// Fields

// Methods
// cls_BinMFunction.def_static("operator new_", (void * (*)(size_t)) &BinMFunction::operator new, "None", py::arg("theSize"));
// cls_BinMFunction.def_static("operator delete_", (void (*)(void *)) &BinMFunction::operator delete, "None", py::arg("theAddress"));
// cls_BinMFunction.def_static("operator new[]_", (void * (*)(size_t)) &BinMFunction::operator new[], "None", py::arg("theSize"));
// cls_BinMFunction.def_static("operator delete[]_", (void (*)(void *)) &BinMFunction::operator delete[], "None", py::arg("theAddress"));
// cls_BinMFunction.def_static("operator new_", (void * (*)(size_t, void *)) &BinMFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinMFunction.def_static("operator delete_", (void (*)(void *, void *)) &BinMFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_BinMFunction.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinMFunction::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));

// Enums

}