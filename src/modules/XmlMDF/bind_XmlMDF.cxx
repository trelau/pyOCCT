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
#include <TDF_Data.hxx>
#include <XmlObjMgt_Element.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <Message_Messenger.hxx>
#include <TDF_Label.hxx>
#include <XmlMDF_MapOfDriver.hxx>
#include <XmlMDF_ADriver.hxx>
#include <XmlMDF_TagSourceDriver.hxx>
#include <XmlMDF_ReferenceDriver.hxx>
#include <XmlMDF.hxx>

void bind_XmlMDF(py::module &mod){

py::class_<XmlMDF, std::unique_ptr<XmlMDF, Deleter<XmlMDF>>> cls_XmlMDF(mod, "XmlMDF", "This package provides classes and methods to translate a transient DF into a persistent one and vice versa.");

// Constructors

// Fields

// Methods
// cls_XmlMDF.def_static("operator new_", (void * (*)(size_t)) &XmlMDF::operator new, "None", py::arg("theSize"));
// cls_XmlMDF.def_static("operator delete_", (void (*)(void *)) &XmlMDF::operator delete, "None", py::arg("theAddress"));
// cls_XmlMDF.def_static("operator new[]_", (void * (*)(size_t)) &XmlMDF::operator new[], "None", py::arg("theSize"));
// cls_XmlMDF.def_static("operator delete[]_", (void (*)(void *)) &XmlMDF::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMDF.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMDF::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMDF.def_static("operator delete_", (void (*)(void *, void *)) &XmlMDF::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMDF.def_static("FromTo_", (void (*)(const opencascade::handle<TDF_Data> &, XmlObjMgt_Element &, XmlObjMgt_SRelocationTable &, const opencascade::handle<XmlMDF_ADriverTable> &)) &XmlMDF::FromTo, "Translates a transient <aSource> into a persistent <aTarget>.", py::arg("aSource"), py::arg("aTarget"), py::arg("aReloc"), py::arg("aDrivers"));
cls_XmlMDF.def_static("FromTo_", (Standard_Boolean (*)(const XmlObjMgt_Element &, opencascade::handle<TDF_Data> &, XmlObjMgt_RRelocationTable &, const opencascade::handle<XmlMDF_ADriverTable> &)) &XmlMDF::FromTo, "Translates a persistent <aSource> into a transient <aTarget>. Returns True if completed successfully (False on error)", py::arg("aSource"), py::arg("aTarget"), py::arg("aReloc"), py::arg("aDrivers"));
cls_XmlMDF.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMDF::AddDrivers, "Adds the attribute storage drivers to <aDriverSeq>.", py::arg("aDriverTable"), py::arg("theMessageDriver"));

// Enums

}