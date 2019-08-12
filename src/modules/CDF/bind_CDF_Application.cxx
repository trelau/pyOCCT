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
#include <CDM_Application.hxx>
#include <Standard_Handle.hxx>
#include <CDF_Application.hxx>
#include <Standard_GUID.hxx>
#include <CDM_Document.hxx>
#include <CDM_CanCloseStatus.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <PCDM_ReaderStatus.hxx>
#include <Standard_IStream.hxx>
#include <PCDM_Reader.hxx>
#include <PCDM_StorageDriver.hxx>
#include <CDF_Session.hxx>
#include <Standard_Type.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <PCDM_RetrievalDriver.hxx>
#include <CDF_TypeOfActivation.hxx>
#include <CDM_MetaData.hxx>

void bind_CDF_Application(py::module &mod){

py::class_<CDF_Application, opencascade::handle<CDF_Application>, CDM_Application> cls_CDF_Application(mod, "CDF_Application", "None");

// Fields

// Methods
cls_CDF_Application.def_static("Load_", (opencascade::handle<CDF_Application> (*)(const Standard_GUID &)) &CDF_Application::Load, "plugs an application.", py::arg("aGUID"));
cls_CDF_Application.def("Open", (void (CDF_Application::*)(const opencascade::handle<CDM_Document> &)) &CDF_Application::Open, "puts the document in the current session directory and calls the virtual method Activate on it.", py::arg("aDocument"));
cls_CDF_Application.def("CanClose", (CDM_CanCloseStatus (CDF_Application::*)(const opencascade::handle<CDM_Document> &)) &CDF_Application::CanClose, "None", py::arg("aDocument"));
cls_CDF_Application.def("Close", (void (CDF_Application::*)(const opencascade::handle<CDM_Document> &)) &CDF_Application::Close, "removes the document of the current session directory and closes the document;", py::arg("aDocument"));
cls_CDF_Application.def("Retrieve", [](CDF_Application &self, const TCollection_ExtendedString & a0, const TCollection_ExtendedString & a1) -> opencascade::handle<CDM_Document> { return self.Retrieve(a0, a1); });
cls_CDF_Application.def("Retrieve", (opencascade::handle<CDM_Document> (CDF_Application::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const Standard_Boolean)) &CDF_Application::Retrieve, "This method retrieves a document from the database. If the Document references other documents which have been updated, the latest version of these documents will be used if {UseStorageConfiguration} is Standard_True. The content of {aFolder}, {aName} and {aVersion} depends on the Database Manager system. If the DBMS is only based on the OS, {aFolder} is a directory and {aName} is the name of a file. In this case the use of the syntax with {aVersion} has no sense. For example:", py::arg("aFolder"), py::arg("aName"), py::arg("UseStorageConfiguration"));
cls_CDF_Application.def("Retrieve", [](CDF_Application &self, const TCollection_ExtendedString & a0, const TCollection_ExtendedString & a1, const TCollection_ExtendedString & a2) -> opencascade::handle<CDM_Document> { return self.Retrieve(a0, a1, a2); });
cls_CDF_Application.def("Retrieve", (opencascade::handle<CDM_Document> (CDF_Application::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const Standard_Boolean)) &CDF_Application::Retrieve, "This method retrieves a document from the database. If the Document references other documents which have been updated, the latest version of these documents will be used if {UseStorageConfiguration} is Standard_True. -- If the DBMS is only based on the OS, this syntax should not be used.", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"), py::arg("UseStorageConfiguration"));
cls_CDF_Application.def("CanRetrieve", (PCDM_ReaderStatus (CDF_Application::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_Application::CanRetrieve, "None", py::arg("aFolder"), py::arg("aName"));
cls_CDF_Application.def("CanRetrieve", (PCDM_ReaderStatus (CDF_Application::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_Application::CanRetrieve, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_Application.def("GetRetrieveStatus", (PCDM_ReaderStatus (CDF_Application::*)() const) &CDF_Application::GetRetrieveStatus, "Checks status after Retrieve");
cls_CDF_Application.def("Read", (opencascade::handle<CDM_Document> (CDF_Application::*)(Standard_IStream &)) &CDF_Application::Read, "Reads aDoc from standard SEEKABLE stream theIStream, the stream should support SEEK fuctionality", py::arg("theIStream"));
cls_CDF_Application.def("ReaderFromFormat", (opencascade::handle<PCDM_Reader> (CDF_Application::*)(const TCollection_ExtendedString &)) &CDF_Application::ReaderFromFormat, "Returns instance of read driver for specified format.", py::arg("aFormat"));
cls_CDF_Application.def("WriterFromFormat", (opencascade::handle<PCDM_StorageDriver> (CDF_Application::*)(const TCollection_ExtendedString &)) &CDF_Application::WriterFromFormat, "Returns instance of storage driver for specified format.", py::arg("aFormat"));
cls_CDF_Application.def("Format", (Standard_Boolean (CDF_Application::*)(const TCollection_ExtendedString &, TCollection_ExtendedString &)) &CDF_Application::Format, "try to retrieve a Format directly in the file or in application resource by using extension. returns True if found;", py::arg("aFileName"), py::arg("theFormat"));
cls_CDF_Application.def("DefaultFolder", (Standard_ExtString (CDF_Application::*)()) &CDF_Application::DefaultFolder, "None");
cls_CDF_Application.def("SetDefaultFolder", (Standard_Boolean (CDF_Application::*)(const Standard_ExtString)) &CDF_Application::SetDefaultFolder, "None", py::arg("aFolder"));
cls_CDF_Application.def_static("get_type_name_", (const char * (*)()) &CDF_Application::get_type_name, "None");
cls_CDF_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_Application::get_type_descriptor, "None");
cls_CDF_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_Application::*)() const) &CDF_Application::DynamicType, "None");

// Enums

}