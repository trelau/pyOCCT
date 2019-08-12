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
#include <PCDM_StorageDriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_OStream.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <BinLDrivers_DocumentStorageDriver.hxx>
#include <Standard_Type.hxx>
#include <TDF_Label.hxx>
#include <BinLDrivers_DocumentSection.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <TDF_LabelList.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <TColStd_MapOfTransient.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <BinLDrivers_VectorOfDocumentSection.hxx>

void bind_BinLDrivers_DocumentStorageDriver(py::module &mod){

py::class_<BinLDrivers_DocumentStorageDriver, opencascade::handle<BinLDrivers_DocumentStorageDriver>, PCDM_StorageDriver> cls_BinLDrivers_DocumentStorageDriver(mod, "BinLDrivers_DocumentStorageDriver", "persistent implemention of storage a document in a binary file");

// Constructors
cls_BinLDrivers_DocumentStorageDriver.def(py::init<>());

// Fields

// Methods
cls_BinLDrivers_DocumentStorageDriver.def("Write", (void (BinLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &BinLDrivers_DocumentStorageDriver::Write, "Write <theDocument> to the binary file <theFileName>", py::arg("theDocument"), py::arg("theFileName"));
cls_BinLDrivers_DocumentStorageDriver.def("Write", (void (BinLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &BinLDrivers_DocumentStorageDriver::Write, "Write <theDocument> to theOStream", py::arg("theDocument"), py::arg("theOStream"));
cls_BinLDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinLDrivers_DocumentStorageDriver::*)(const opencascade::handle<Message_Messenger> &)) &BinLDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_BinLDrivers_DocumentStorageDriver.def("AddSection", [](BinLDrivers_DocumentStorageDriver &self, const TCollection_AsciiString & a0) -> void { return self.AddSection(a0); });
cls_BinLDrivers_DocumentStorageDriver.def("AddSection", (void (BinLDrivers_DocumentStorageDriver::*)(const TCollection_AsciiString &, const Standard_Boolean)) &BinLDrivers_DocumentStorageDriver::AddSection, "Create a section that should be written after the OCAF data", py::arg("theName"), py::arg("isPostRead"));
cls_BinLDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &BinLDrivers_DocumentStorageDriver::get_type_name, "None");
cls_BinLDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinLDrivers_DocumentStorageDriver::get_type_descriptor, "None");
cls_BinLDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinLDrivers_DocumentStorageDriver::*)() const) &BinLDrivers_DocumentStorageDriver::DynamicType, "None");

// Enums

}