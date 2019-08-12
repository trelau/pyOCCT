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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <CDM_MetaData.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_Document.hxx>
#include <PCDM_ReferenceIterator.hxx>
#include <CDF_MetaDataDriver.hxx>
#include <Standard_Type.hxx>

void bind_CDF_MetaDataDriver(py::module &mod){

py::class_<CDF_MetaDataDriver, opencascade::handle<CDF_MetaDataDriver>, Standard_Transient> cls_CDF_MetaDataDriver(mod, "CDF_MetaDataDriver", "this class list the method that must be available for a specific DBMS");

// Fields

// Methods
cls_CDF_MetaDataDriver.def("HasVersionCapability", (Standard_Boolean (CDF_MetaDataDriver::*)()) &CDF_MetaDataDriver::HasVersionCapability, "returns true if the MetaDataDriver can manage different versions of a Data. By default, returns Standard_False.");
cls_CDF_MetaDataDriver.def("CreateDependsOn", (void (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_MetaData> &, const opencascade::handle<CDM_MetaData> &)) &CDF_MetaDataDriver::CreateDependsOn, "Creates a 'Depends On' relation between two Datas. By default does nothing", py::arg("aFirstData"), py::arg("aSecondData"));
cls_CDF_MetaDataDriver.def("CreateReference", (void (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_MetaData> &, const opencascade::handle<CDM_MetaData> &, const Standard_Integer, const Standard_Integer)) &CDF_MetaDataDriver::CreateReference, "None", py::arg("aFrom"), py::arg("aTo"), py::arg("aReferenceIdentifier"), py::arg("aToDocumentVersion"));
cls_CDF_MetaDataDriver.def("HasVersion", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::HasVersion, "by default return Standard_True.", py::arg("aFolder"), py::arg("aName"));
cls_CDF_MetaDataDriver.def("BuildFileName", (TCollection_ExtendedString (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_Document> &)) &CDF_MetaDataDriver::BuildFileName, "None", py::arg("aDocument"));
cls_CDF_MetaDataDriver.def("SetName", (TCollection_ExtendedString (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::SetName, "this methods is usefull if the name of an object -- depends on the metadatadriver. For example a Driver -- based on the operating system can choose to add the extension of file to create to the object.", py::arg("aDocument"), py::arg("aName"));
cls_CDF_MetaDataDriver.def("Find", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::Find, "should indicate whether meta-data exist in the DBMS corresponding to the Data. aVersion may be NULL;", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_MetaDataDriver.def("HasReadPermission", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::HasReadPermission, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_MetaDataDriver.def("MetaData", (opencascade::handle<CDM_MetaData> (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::MetaData, "should return the MetaData stored in the DBMS with the meta-data corresponding to the Data. If the MetaDataDriver has version management capabilities the version has to be set in the returned MetaData. aVersion may be NULL MetaData is called by GetMetaData If the version is set to NULL, MetaData should return the last version of the metadata", py::arg("aFolder"), py::arg("aName"), py::arg("aVersion"));
cls_CDF_MetaDataDriver.def("LastVersion", (opencascade::handle<CDM_MetaData> (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_MetaData> &)) &CDF_MetaDataDriver::LastVersion, "by default returns aMetaDATA should return the MetaData stored in the DBMS with the meta-data corresponding to the path. If the MetaDataDriver has version management capabilities the version has to be set in the returned MetaData. MetaData is called by GetMetaData If the version is not included in the path , MetaData should return the last version of the metadata is deferred;", py::arg("aMetaData"));
cls_CDF_MetaDataDriver.def("CreateMetaData", (opencascade::handle<CDM_MetaData> (CDF_MetaDataDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::CreateMetaData, "should create meta-data corresponding to aData and maintaining a meta-link between these meta-data and aFileName CreateMetaData is called by CreateData If the metadata-driver has version capabilities, version must be set in the returned Data.", py::arg("aDocument"), py::arg("aFileName"));
cls_CDF_MetaDataDriver.def("FindFolder", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &)) &CDF_MetaDataDriver::FindFolder, "None", py::arg("aFolder"));
cls_CDF_MetaDataDriver.def("DefaultFolder", (TCollection_ExtendedString (CDF_MetaDataDriver::*)()) &CDF_MetaDataDriver::DefaultFolder, "None");
cls_CDF_MetaDataDriver.def("ReferenceIterator", (opencascade::handle<PCDM_ReferenceIterator> (CDF_MetaDataDriver::*)()) &CDF_MetaDataDriver::ReferenceIterator, "None");
cls_CDF_MetaDataDriver.def("Find", (Standard_Boolean (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::Find, "calls Find with an empty version", py::arg("aFolder"), py::arg("aName"));
cls_CDF_MetaDataDriver.def("MetaData", (opencascade::handle<CDM_MetaData> (CDF_MetaDataDriver::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &CDF_MetaDataDriver::MetaData, "calls MetaData with an empty version", py::arg("aFolder"), py::arg("aName"));
cls_CDF_MetaDataDriver.def_static("get_type_name_", (const char * (*)()) &CDF_MetaDataDriver::get_type_name, "None");
cls_CDF_MetaDataDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_MetaDataDriver::get_type_descriptor, "None");
cls_CDF_MetaDataDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_MetaDataDriver::*)() const) &CDF_MetaDataDriver::DynamicType, "None");

// Enums

}