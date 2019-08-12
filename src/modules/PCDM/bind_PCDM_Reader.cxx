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
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_Application.hxx>
#include <Standard_IStream.hxx>
#include <Storage_Data.hxx>
#include <PCDM_ReaderStatus.hxx>
#include <PCDM_Reader.hxx>
#include <Standard_Type.hxx>

void bind_PCDM_Reader(py::module &mod){

py::class_<PCDM_Reader, opencascade::handle<PCDM_Reader>, Standard_Transient> cls_PCDM_Reader(mod, "PCDM_Reader", "None");

// Fields

// Methods
cls_PCDM_Reader.def("CreateDocument", (opencascade::handle<CDM_Document> (PCDM_Reader::*)()) &PCDM_Reader::CreateDocument, "this method is called by the framework before the read method.");
cls_PCDM_Reader.def("Read", (void (PCDM_Reader::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &PCDM_Reader::Read, "retrieves the content of the file into a new Document.", py::arg("aFileName"), py::arg("aNewDocument"), py::arg("anApplication"));
cls_PCDM_Reader.def("Read", (void (PCDM_Reader::*)(Standard_IStream &, const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &PCDM_Reader::Read, "None", py::arg("theIStream"), py::arg("theStorageData"), py::arg("theDoc"), py::arg("theApplication"));
cls_PCDM_Reader.def("GetStatus", (PCDM_ReaderStatus (PCDM_Reader::*)() const) &PCDM_Reader::GetStatus, "None");
cls_PCDM_Reader.def_static("get_type_name_", (const char * (*)()) &PCDM_Reader::get_type_name, "None");
cls_PCDM_Reader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_Reader::get_type_descriptor, "None");
cls_PCDM_Reader.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_Reader::*)() const) &PCDM_Reader::DynamicType, "None");

// Enums

}