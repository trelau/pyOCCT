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
#include <PCDM_RetrievalDriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_Application.hxx>
#include <Standard_IStream.hxx>
#include <Storage_Data.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <BinLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <BinLDrivers_DocumentSection.hxx>
#include <Storage_Position.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <BinLDrivers_VectorOfDocumentSection.hxx>

void bind_BinLDrivers_DocumentRetrievalDriver(py::module &mod){

py::class_<BinLDrivers_DocumentRetrievalDriver, opencascade::handle<BinLDrivers_DocumentRetrievalDriver>, PCDM_RetrievalDriver> cls_BinLDrivers_DocumentRetrievalDriver(mod, "BinLDrivers_DocumentRetrievalDriver", "None");

// Constructors
cls_BinLDrivers_DocumentRetrievalDriver.def(py::init<>());

// Fields

// Methods
cls_BinLDrivers_DocumentRetrievalDriver.def("CreateDocument", (opencascade::handle<CDM_Document> (BinLDrivers_DocumentRetrievalDriver::*)()) &BinLDrivers_DocumentRetrievalDriver::CreateDocument, "pure virtual method definition");
cls_BinLDrivers_DocumentRetrievalDriver.def("Read", (void (BinLDrivers_DocumentRetrievalDriver::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &BinLDrivers_DocumentRetrievalDriver::Read, "retrieves the content of the file into a new Document.", py::arg("theFileName"), py::arg("theNewDocument"), py::arg("theApplication"));
cls_BinLDrivers_DocumentRetrievalDriver.def("Read", (void (BinLDrivers_DocumentRetrievalDriver::*)(Standard_IStream &, const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &BinLDrivers_DocumentRetrievalDriver::Read, "None", py::arg("theIStream"), py::arg("theStorageData"), py::arg("theDoc"), py::arg("theApplication"));
cls_BinLDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinLDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<Message_Messenger> &)) &BinLDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_BinLDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &BinLDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_BinLDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinLDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_BinLDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinLDrivers_DocumentRetrievalDriver::*)() const) &BinLDrivers_DocumentRetrievalDriver::DynamicType, "None");

// Enums

}