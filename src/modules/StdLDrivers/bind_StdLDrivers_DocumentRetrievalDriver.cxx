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
#include <StdLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Storage_HeaderData.hxx>
#include <Storage_Error.hxx>

void bind_StdLDrivers_DocumentRetrievalDriver(py::module &mod){

py::class_<StdLDrivers_DocumentRetrievalDriver, opencascade::handle<StdLDrivers_DocumentRetrievalDriver>, PCDM_RetrievalDriver> cls_StdLDrivers_DocumentRetrievalDriver(mod, "StdLDrivers_DocumentRetrievalDriver", "retrieval driver of a Part document");

// Constructors

// Fields

// Methods
cls_StdLDrivers_DocumentRetrievalDriver.def("CreateDocument", (opencascade::handle<CDM_Document> (StdLDrivers_DocumentRetrievalDriver::*)()) &StdLDrivers_DocumentRetrievalDriver::CreateDocument, "Create an empty TDocStd_Document.");
cls_StdLDrivers_DocumentRetrievalDriver.def("Read", (void (StdLDrivers_DocumentRetrievalDriver::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &StdLDrivers_DocumentRetrievalDriver::Read, "Retrieve the content of a file into a new document.", py::arg("theFileName"), py::arg("theNewDocument"), py::arg("theApplication"));
cls_StdLDrivers_DocumentRetrievalDriver.def("Read", (void (StdLDrivers_DocumentRetrievalDriver::*)(Standard_IStream &, const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &StdLDrivers_DocumentRetrievalDriver::Read, "Override pure virtual method (raises exception Standard_NotImplemented)", py::arg("theIStream"), py::arg("theStorageData"), py::arg("theDoc"), py::arg("theApplication"));
cls_StdLDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &StdLDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_StdLDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdLDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_StdLDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdLDrivers_DocumentRetrievalDriver::*)() const) &StdLDrivers_DocumentRetrievalDriver::DynamicType, "None");

// Enums

}