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
#include <PCDM_Writer.hxx>
#include <Standard_Handle.hxx>
#include <PCDM_Document.hxx>
#include <CDM_Document.hxx>
#include <PCDM_SequenceOfDocument.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <PCDM_StoreStatus.hxx>
#include <PCDM_StorageDriver.hxx>
#include <Standard_Type.hxx>

void bind_PCDM_StorageDriver(py::module &mod){

py::class_<PCDM_StorageDriver, opencascade::handle<PCDM_StorageDriver>, PCDM_Writer> cls_PCDM_StorageDriver(mod, "PCDM_StorageDriver", "persistent implemention of storage.");

// Constructors

// Fields

// Methods
cls_PCDM_StorageDriver.def("Make", (opencascade::handle<PCDM_Document> (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &)) &PCDM_StorageDriver::Make, "raises NotImplemented.", py::arg("aDocument"));
cls_PCDM_StorageDriver.def("Make", (void (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &, PCDM_SequenceOfDocument &)) &PCDM_StorageDriver::Make, "By default, puts in the Sequence the document returns by the previous Make method.", py::arg("aDocument"), py::arg("Documents"));
cls_PCDM_StorageDriver.def("Write", (void (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &PCDM_StorageDriver::Write, "Warning! raises DriverError if an error occurs during inside the Make method. stores the content of the Document into a new file.", py::arg("aDocument"), py::arg("aFileName"));
cls_PCDM_StorageDriver.def("Write", (void (PCDM_StorageDriver::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &PCDM_StorageDriver::Write, "Write <theDocument> to theOStream", py::arg("theDocument"), py::arg("theOStream"));
cls_PCDM_StorageDriver.def("SetFormat", (void (PCDM_StorageDriver::*)(const TCollection_ExtendedString &)) &PCDM_StorageDriver::SetFormat, "None", py::arg("aformat"));
cls_PCDM_StorageDriver.def("GetFormat", (TCollection_ExtendedString (PCDM_StorageDriver::*)() const) &PCDM_StorageDriver::GetFormat, "None");
cls_PCDM_StorageDriver.def("IsError", (Standard_Boolean (PCDM_StorageDriver::*)() const) &PCDM_StorageDriver::IsError, "None");
cls_PCDM_StorageDriver.def("SetIsError", (void (PCDM_StorageDriver::*)(const Standard_Boolean)) &PCDM_StorageDriver::SetIsError, "None", py::arg("theIsError"));
cls_PCDM_StorageDriver.def("GetStoreStatus", (PCDM_StoreStatus (PCDM_StorageDriver::*)() const) &PCDM_StorageDriver::GetStoreStatus, "None");
cls_PCDM_StorageDriver.def("SetStoreStatus", (void (PCDM_StorageDriver::*)(const PCDM_StoreStatus)) &PCDM_StorageDriver::SetStoreStatus, "None", py::arg("theStoreStatus"));
cls_PCDM_StorageDriver.def_static("get_type_name_", (const char * (*)()) &PCDM_StorageDriver::get_type_name, "None");
cls_PCDM_StorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_StorageDriver::get_type_descriptor, "None");
cls_PCDM_StorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_StorageDriver::*)() const) &PCDM_StorageDriver::DynamicType, "None");

// Enums

}