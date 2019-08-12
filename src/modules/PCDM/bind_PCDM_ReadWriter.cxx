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
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Storage_Data.hxx>
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_Messenger.hxx>
#include <PCDM_SequenceOfReference.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Storage_BaseDriver.hxx>
#include <Storage_OpenMode.hxx>
#include <PCDM_ReadWriter.hxx>
#include <Standard_IStream.hxx>
#include <Standard_Type.hxx>

void bind_PCDM_ReadWriter(py::module &mod){

py::class_<PCDM_ReadWriter, opencascade::handle<PCDM_ReadWriter>, Standard_Transient> cls_PCDM_ReadWriter(mod, "PCDM_ReadWriter", "None");

// Fields

// Methods
cls_PCDM_ReadWriter.def("Version", (TCollection_AsciiString (PCDM_ReadWriter::*)() const) &PCDM_ReadWriter::Version, "returns PCDM_ReadWriter_1.");
cls_PCDM_ReadWriter.def("WriteReferenceCounter", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter::WriteReferenceCounter, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter.def("WriteReferences", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &) const) &PCDM_ReadWriter::WriteReferences, "None", py::arg("aData"), py::arg("aDocument"), py::arg("theReferencerFileName"));
cls_PCDM_ReadWriter.def("WriteExtensions", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter::WriteExtensions, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter.def("WriteVersion", (void (PCDM_ReadWriter::*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &) const) &PCDM_ReadWriter::WriteVersion, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter.def("ReadReferenceCounter", (Standard_Integer (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter::ReadReferenceCounter, "None", py::arg("theFileName"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter.def("ReadReferences", (void (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, PCDM_SequenceOfReference &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter::ReadReferences, "None", py::arg("aFileName"), py::arg("theReferences"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter.def("ReadExtensions", (void (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, TColStd_SequenceOfExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter::ReadExtensions, "None", py::arg("aFileName"), py::arg("theExtensions"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter.def("ReadDocumentVersion", (Standard_Integer (PCDM_ReadWriter::*)(const TCollection_ExtendedString &, const opencascade::handle<Message_Messenger> &) const) &PCDM_ReadWriter::ReadDocumentVersion, "None", py::arg("aFileName"), py::arg("theMsgDriver"));
cls_PCDM_ReadWriter.def_static("Open_", (void (*)(Storage_BaseDriver &, const TCollection_ExtendedString &, const Storage_OpenMode)) &PCDM_ReadWriter::Open, "None", py::arg("aDriver"), py::arg("aFileName"), py::arg("anOpenMode"));
cls_PCDM_ReadWriter.def_static("Reader_", (opencascade::handle<PCDM_ReadWriter> (*)(const TCollection_ExtendedString &)) &PCDM_ReadWriter::Reader, "returns the convenient Reader for a File.", py::arg("aFileName"));
cls_PCDM_ReadWriter.def_static("Writer_", (opencascade::handle<PCDM_ReadWriter> (*)()) &PCDM_ReadWriter::Writer, "None");
cls_PCDM_ReadWriter.def_static("WriteFileFormat_", (void (*)(const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &)) &PCDM_ReadWriter::WriteFileFormat, "None", py::arg("aData"), py::arg("aDocument"));
cls_PCDM_ReadWriter.def_static("FileFormat_", (TCollection_ExtendedString (*)(const TCollection_ExtendedString &)) &PCDM_ReadWriter::FileFormat, "tries to get a format in the file. returns an empty string if the file could not be read or does not have a FileFormat information.", py::arg("aFileName"));
cls_PCDM_ReadWriter.def_static("FileFormat_", (TCollection_ExtendedString (*)(Standard_IStream &, opencascade::handle<Storage_Data> &)) &PCDM_ReadWriter::FileFormat, "tries to get a format from the stream. returns an empty string if the file could not be read or does not have a FileFormat information.", py::arg("theIStream"), py::arg("theData"));
cls_PCDM_ReadWriter.def_static("get_type_name_", (const char * (*)()) &PCDM_ReadWriter::get_type_name, "None");
cls_PCDM_ReadWriter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PCDM_ReadWriter::get_type_descriptor, "None");
cls_PCDM_ReadWriter.def("DynamicType", (const opencascade::handle<Standard_Type> & (PCDM_ReadWriter::*)() const) &PCDM_ReadWriter::DynamicType, "None");

// Enums

}