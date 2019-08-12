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
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <XmlLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>
#include <XmlObjMgt_Element.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlMDF_ADriver.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>

void bind_XmlLDrivers_DocumentRetrievalDriver(py::module &mod){

py::class_<XmlLDrivers_DocumentRetrievalDriver, opencascade::handle<XmlLDrivers_DocumentRetrievalDriver>, PCDM_RetrievalDriver> cls_XmlLDrivers_DocumentRetrievalDriver(mod, "XmlLDrivers_DocumentRetrievalDriver", "None");

// Constructors
cls_XmlLDrivers_DocumentRetrievalDriver.def(py::init<>());

// Fields

// Methods
cls_XmlLDrivers_DocumentRetrievalDriver.def("CreateDocument", (opencascade::handle<CDM_Document> (XmlLDrivers_DocumentRetrievalDriver::*)()) &XmlLDrivers_DocumentRetrievalDriver::CreateDocument, "None");
cls_XmlLDrivers_DocumentRetrievalDriver.def("Read", (void (XmlLDrivers_DocumentRetrievalDriver::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &XmlLDrivers_DocumentRetrievalDriver::Read, "None", py::arg("theFileName"), py::arg("theNewDocument"), py::arg("theApplication"));
cls_XmlLDrivers_DocumentRetrievalDriver.def("Read", (void (XmlLDrivers_DocumentRetrievalDriver::*)(Standard_IStream &, const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &XmlLDrivers_DocumentRetrievalDriver::Read, "None", py::arg("theIStream"), py::arg("theStorageData"), py::arg("theDoc"), py::arg("theApplication"));
cls_XmlLDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlLDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<Message_Messenger> &)) &XmlLDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_XmlLDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &XmlLDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_XmlLDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlLDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_XmlLDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlLDrivers_DocumentRetrievalDriver::*)() const) &XmlLDrivers_DocumentRetrievalDriver::DynamicType, "None");

// Enums

}