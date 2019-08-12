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
#include <CDM_MetaData.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <CDM_Document.hxx>
#include <Standard_OStream.hxx>
#include <CDM_Reference.hxx>
#include <CDM_Application.hxx>
#include <Standard_Type.hxx>
#include <CDM_MetaDataLookUpTable.hxx>
#include <CDM_DocumentPointer.hxx>

void bind_CDM_MetaData(py::module &mod){

py::class_<CDM_MetaData, opencascade::handle<CDM_MetaData>, Standard_Transient> cls_CDM_MetaData(mod, "CDM_MetaData", "None");

// Constructors

// Fields

// Methods
cls_CDM_MetaData.def_static("LookUp_", (opencascade::handle<CDM_MetaData> (*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const Standard_Boolean)) &CDM_MetaData::LookUp, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aPath"), py::arg("aFileName"), py::arg("ReadOnly"));
cls_CDM_MetaData.def_static("LookUp_", (opencascade::handle<CDM_MetaData> (*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const Standard_Boolean)) &CDM_MetaData::LookUp, "None", py::arg("aFolder"), py::arg("aName"), py::arg("aPath"), py::arg("aVersion"), py::arg("aFileName"), py::arg("ReadOnly"));
cls_CDM_MetaData.def("IsRetrieved", (Standard_Boolean (CDM_MetaData::*)() const) &CDM_MetaData::IsRetrieved, "None");
cls_CDM_MetaData.def("Document", (opencascade::handle<CDM_Document> (CDM_MetaData::*)() const) &CDM_MetaData::Document, "None");
cls_CDM_MetaData.def("Folder", (TCollection_ExtendedString (CDM_MetaData::*)() const) &CDM_MetaData::Folder, "returns the folder in which the meta-data has to be created or has to be found.");
cls_CDM_MetaData.def("Name", (TCollection_ExtendedString (CDM_MetaData::*)() const) &CDM_MetaData::Name, "returns the name under which the meta-data has to be created or has to be found.");
cls_CDM_MetaData.def("Version", (TCollection_ExtendedString (CDM_MetaData::*)() const) &CDM_MetaData::Version, "returns the version under which the meta-data has to be found. Warning: raises NoSuchObject from Standard if no Version has been defined");
cls_CDM_MetaData.def("HasVersion", (Standard_Boolean (CDM_MetaData::*)() const) &CDM_MetaData::HasVersion, "indicates that the version has to be taken into account when searching the corresponding meta-data.");
cls_CDM_MetaData.def("FileName", (TCollection_ExtendedString (CDM_MetaData::*)() const) &CDM_MetaData::FileName, "None");
cls_CDM_MetaData.def("Print", (Standard_OStream & (CDM_MetaData::*)(Standard_OStream &) const) &CDM_MetaData::Print, "None", py::arg("anOStream"));
// cls_CDM_MetaData.def("bits_left", (Standard_OStream & (CDM_MetaData::*)(Standard_OStream &)) &CDM_MetaData::operator<<, py::is_operator(), "None", py::arg("anOStream"));
cls_CDM_MetaData.def("Path", (TCollection_ExtendedString (CDM_MetaData::*)() const) &CDM_MetaData::Path, "None");
cls_CDM_MetaData.def("UnsetDocument", (void (CDM_MetaData::*)()) &CDM_MetaData::UnsetDocument, "None");
cls_CDM_MetaData.def("IsReadOnly", (Standard_Boolean (CDM_MetaData::*)() const) &CDM_MetaData::IsReadOnly, "None");
cls_CDM_MetaData.def("SetIsReadOnly", (void (CDM_MetaData::*)()) &CDM_MetaData::SetIsReadOnly, "None");
cls_CDM_MetaData.def("UnsetIsReadOnly", (void (CDM_MetaData::*)()) &CDM_MetaData::UnsetIsReadOnly, "None");
cls_CDM_MetaData.def_static("get_type_name_", (const char * (*)()) &CDM_MetaData::get_type_name, "None");
cls_CDM_MetaData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_MetaData::get_type_descriptor, "None");
cls_CDM_MetaData.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_MetaData::*)() const) &CDM_MetaData::DynamicType, "None");

// Enums

}