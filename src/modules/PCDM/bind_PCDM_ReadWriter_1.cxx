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
#include <Standard_IStream.hxx>
#include <PCDM_ReadWriter.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Storage_Data.hxx>
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_Messenger.hxx>
#include <PCDM_SequenceOfReference.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <PCDM_ReadWriter_1.hxx>
#include <Standard_Type.hxx>

void bind_PCDM_ReadWriter_1(py::module &mod){

py::class_<PCDM_ReadWriter_1, opencascade::handle<PCDM_ReadWriter_1>, PCDM_ReadWriter> cls_PCDM_ReadWriter_1(mod, "PCDM_ReadWriter_1", "None");

// Constructors
cls_PCDM_ReadWriter_1.def(py::init<>());

// Fields

// Methods
cls_PCDM_ReadWriter_1.def("Version", (TCollection_AsciiString (PCDM_ReadWriter_1::*)() const) &PCDM_ReadWriter_1::Version, "returns PCDM_ReadWriter_1.");
cls_PCDM_ReadWriter_1.def("WriteReferenceCounter", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter_1::WriteReferenceCounter, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter_1.def("WriteReferences", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &) const) &PCDM_ReadWriter_1::WriteReferences, "None", py::arg("aData"), py::arg("aDocument"), py::arg("theReferencerFileName"));
cls_PCDM_ReadWriter_1.def("WriteExtensions", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter_1::WriteExtensions, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter_1.def("WriteVersion", (void (PCDM_ReadWriter_1::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter_1::WriteVersion, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter_1.def("ReadReferenceCounter", (Standard_Integer (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter_1::ReadReferenceCounter, "None", py::arg("aFileName"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter_1.def("ReadReferences", (void (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, PCDM_SequenceOfReference &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter_1::ReadReferences, "None", py::arg("aFileName"), py::arg("theReferences"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter_1.def("ReadExtensions", (void (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, TColStd_SequenceOfExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter_1::ReadExtensions, "None", py::arg("aFileName"), py::arg("theExtensions"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter_1.def("ReadDocumentVersion", (Standard_Integer (PCDM_ReadWriter_1::*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter_1::ReadDocumentVersion, "None", py::arg("aFileName"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter_1.def_static("get_type_name_", (const char * (*)()) &PCDM_ReadWriter_1::get_type_name, "None");
cls_PCDM_ReadWriter_1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_ReadWriter_1::get_type_descriptor, "None");
cls_PCDM_ReadWriter_1.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_ReadWriter_1::*)() const) &PCDM_ReadWriter_1::DynamicType, "None");

// Enums

}