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
#include <Standard_Type.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_DataInfo.hxx>

void bind_Transfer_DataInfo(py::module &mod){

py::class_<Transfer_DataInfo, std::unique_ptr<Transfer_DataInfo, Deleter<Transfer_DataInfo>>> cls_Transfer_DataInfo(mod, "Transfer_DataInfo", "Gives informations on an object Used as template to instantiate Mapper and SimpleBinder This class is for Transient");

// Constructors

// Fields

// Methods
// cls_Transfer_DataInfo.def_static("operator new_", (void * (*)(size_t)) &Transfer_DataInfo::operator new, "None", py::arg("theSize"));
// cls_Transfer_DataInfo.def_static("operator delete_", (void (*)(void *)) &Transfer_DataInfo::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_DataInfo.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_DataInfo::operator new[], "None", py::arg("theSize"));
// cls_Transfer_DataInfo.def_static("operator delete[]_", (void (*)(void *)) &Transfer_DataInfo::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_DataInfo.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_DataInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_DataInfo.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_DataInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_DataInfo.def_static("Type_", (opencascade::handle<Standard_Type> (*)(const opencascade::handle<Standard_Transient> &)) &Transfer_DataInfo::Type, "Returns the Type attached to an object Here, the Dynamic Type of a Transient. Null Type if unknown", py::arg("ent"));
cls_Transfer_DataInfo.def_static("TypeName_", (Standard_CString (*)(const opencascade::handle<Standard_Transient> &)) &Transfer_DataInfo::TypeName, "Returns Type Name (string) Allows to name type of non-handled objects", py::arg("ent"));

// Enums

}