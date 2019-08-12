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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <BinMDF_ADriver.hxx>
#include <Message_Messenger.hxx>

void bind_BinMDF_ADriver(py::module &mod){

py::class_<BinMDF_ADriver, opencascade::handle<BinMDF_ADriver>, Standard_Transient> cls_BinMDF_ADriver(mod, "BinMDF_ADriver", "Attribute Storage/Retrieval Driver.");

// Fields

// Methods
cls_BinMDF_ADriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDF_ADriver::*)() const) &BinMDF_ADriver::NewEmpty, "Creates a new attribute from TDF.");
cls_BinMDF_ADriver.def("SourceType", (const opencascade::handle<Standard_Type> & (BinMDF_ADriver::*)() const) &BinMDF_ADriver::SourceType, "Returns the type of source object, inheriting from Attribute from TDF.");
cls_BinMDF_ADriver.def("TypeName", (const TCollection_AsciiString & (BinMDF_ADriver::*)() const) &BinMDF_ADriver::TypeName, "Returns the type name of the attribute object");
cls_BinMDF_ADriver.def("Paste", (Standard_Boolean (BinMDF_ADriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const) &BinMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
cls_BinMDF_ADriver.def("Paste", (void (BinMDF_ADriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const) &BinMDF_ADriver::Paste, "Translate the contents of <aSource> and put it into <aTarget>, using the relocation table <aRelocTable> to keep the sharings.", py::arg("aSource"), py::arg("aTarget"), py::arg("aRelocTable"));
cls_BinMDF_ADriver.def_static("get_type_name_", (const char * (*)()) &BinMDF_ADriver::get_type_name, "None");
cls_BinMDF_ADriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDF_ADriver::get_type_descriptor, "None");
cls_BinMDF_ADriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDF_ADriver::*)() const) &BinMDF_ADriver::DynamicType, "None");

// Enums

}