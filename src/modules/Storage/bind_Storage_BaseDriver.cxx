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
#include <Standard.hxx>
#include <Storage_Error.hxx>
#include <TCollection_AsciiString.hxx>
#include <Storage_OpenMode.hxx>
#include <Standard_IStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_Position.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Storage_Data.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Storage_BaseDriver.hxx>

void bind_Storage_BaseDriver(py::module &mod){

py::class_<Storage_BaseDriver, std::unique_ptr<Storage_BaseDriver, Deleter<Storage_BaseDriver>>> cls_Storage_BaseDriver(mod, "Storage_BaseDriver", "Root class for drivers. A driver assigns a physical container to data to be stored or retrieved, for instance a file. The FSD package provides two derived concrete classes : - FSD_File is a general driver which defines a file as the container of data.");

// Fields

// Methods
// cls_Storage_BaseDriver.def_static("operator new_", (void * (*)(size_t)) &Storage_BaseDriver::operator new, "None", py::arg("theSize"));
// cls_Storage_BaseDriver.def_static("operator delete_", (void (*)(void *)) &Storage_BaseDriver::operator delete, "None", py::arg("theAddress"));
// cls_Storage_BaseDriver.def_static("operator new[]_", (void * (*)(size_t)) &Storage_BaseDriver::operator new[], "None", py::arg("theSize"));
// cls_Storage_BaseDriver.def_static("operator delete[]_", (void (*)(void *)) &Storage_BaseDriver::operator delete[], "None", py::arg("theAddress"));
// cls_Storage_BaseDriver.def_static("operator new_", (void * (*)(size_t, void *)) &Storage_BaseDriver::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Storage_BaseDriver.def_static("operator delete_", (void (*)(void *, void *)) &Storage_BaseDriver::operator delete, "None", py::arg(""), py::arg(""));
cls_Storage_BaseDriver.def("Open", (Storage_Error (Storage_BaseDriver::*)(const TCollection_AsciiString &, const Storage_OpenMode)) &Storage_BaseDriver::Open, "None", py::arg("aName"), py::arg("aMode"));
cls_Storage_BaseDriver.def("Name", (TCollection_AsciiString (Storage_BaseDriver::*)() const) &Storage_BaseDriver::Name, "None");
cls_Storage_BaseDriver.def("OpenMode", (Storage_OpenMode (Storage_BaseDriver::*)() const) &Storage_BaseDriver::OpenMode, "None");
cls_Storage_BaseDriver.def_static("ReadMagicNumber_", (TCollection_AsciiString (*)(Standard_IStream &)) &Storage_BaseDriver::ReadMagicNumber, "None", py::arg("theIStream"));
cls_Storage_BaseDriver.def("IsEnd", (Standard_Boolean (Storage_BaseDriver::*)()) &Storage_BaseDriver::IsEnd, "returns True if we are at end of the stream");
cls_Storage_BaseDriver.def("Tell", (Storage_Position (Storage_BaseDriver::*)()) &Storage_BaseDriver::Tell, "return position in the file. Return -1 upon error.");
cls_Storage_BaseDriver.def("BeginWriteInfoSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteInfoSection, "None");
cls_Storage_BaseDriver.def("WriteInfo", (void (Storage_BaseDriver::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TColStd_SequenceOfAsciiString &)) &Storage_BaseDriver::WriteInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
cls_Storage_BaseDriver.def("EndWriteInfoSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteInfoSection, "None");
cls_Storage_BaseDriver.def("BeginReadInfoSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadInfoSection, "None");
cls_Storage_BaseDriver.def("ReadInfo", [](Storage_BaseDriver &self, Standard_Integer & nbObj, TCollection_AsciiString & dbVersion, TCollection_AsciiString & date, TCollection_AsciiString & schemaName, TCollection_AsciiString & schemaVersion, TCollection_ExtendedString & appName, TCollection_AsciiString & appVersion, TCollection_ExtendedString & objectType, TColStd_SequenceOfAsciiString & userInfo){ self.ReadInfo(nbObj, dbVersion, date, schemaName, schemaVersion, appName, appVersion, objectType, userInfo); return nbObj; }, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
cls_Storage_BaseDriver.def("ReadCompleteInfo", (void (Storage_BaseDriver::*)(Standard_IStream &, opencascade::handle<Storage_Data> &)) &Storage_BaseDriver::ReadCompleteInfo, "None", py::arg("theIStream"), py::arg("theData"));
cls_Storage_BaseDriver.def("EndReadInfoSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadInfoSection, "None");
cls_Storage_BaseDriver.def("BeginWriteCommentSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteCommentSection, "None");
cls_Storage_BaseDriver.def("WriteComment", (void (Storage_BaseDriver::*)(const TColStd_SequenceOfExtendedString &)) &Storage_BaseDriver::WriteComment, "None", py::arg("userComments"));
cls_Storage_BaseDriver.def("EndWriteCommentSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteCommentSection, "None");
cls_Storage_BaseDriver.def("BeginReadCommentSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadCommentSection, "None");
cls_Storage_BaseDriver.def("ReadComment", (void (Storage_BaseDriver::*)(TColStd_SequenceOfExtendedString &)) &Storage_BaseDriver::ReadComment, "None", py::arg("userComments"));
cls_Storage_BaseDriver.def("EndReadCommentSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadCommentSection, "None");
cls_Storage_BaseDriver.def("BeginWriteTypeSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteTypeSection, "None");
cls_Storage_BaseDriver.def("SetTypeSectionSize", (void (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::SetTypeSectionSize, "None", py::arg("aSize"));
cls_Storage_BaseDriver.def("WriteTypeInformations", (void (Storage_BaseDriver::*)(const Standard_Integer, const TCollection_AsciiString &)) &Storage_BaseDriver::WriteTypeInformations, "None", py::arg("typeNum"), py::arg("typeName"));
cls_Storage_BaseDriver.def("EndWriteTypeSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteTypeSection, "None");
cls_Storage_BaseDriver.def("BeginReadTypeSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadTypeSection, "None");
cls_Storage_BaseDriver.def("TypeSectionSize", (Standard_Integer (Storage_BaseDriver::*)()) &Storage_BaseDriver::TypeSectionSize, "None");
cls_Storage_BaseDriver.def("ReadTypeInformations", [](Storage_BaseDriver &self, Standard_Integer & typeNum, TCollection_AsciiString & typeName){ self.ReadTypeInformations(typeNum, typeName); return typeNum; }, "None", py::arg("typeNum"), py::arg("typeName"));
cls_Storage_BaseDriver.def("EndReadTypeSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadTypeSection, "None");
cls_Storage_BaseDriver.def("BeginWriteRootSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteRootSection, "None");
cls_Storage_BaseDriver.def("SetRootSectionSize", (void (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::SetRootSectionSize, "None", py::arg("aSize"));
cls_Storage_BaseDriver.def("WriteRoot", (void (Storage_BaseDriver::*)(const TCollection_AsciiString &, const Standard_Integer, const TCollection_AsciiString &)) &Storage_BaseDriver::WriteRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
cls_Storage_BaseDriver.def("EndWriteRootSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteRootSection, "None");
cls_Storage_BaseDriver.def("BeginReadRootSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadRootSection, "None");
cls_Storage_BaseDriver.def("RootSectionSize", (Standard_Integer (Storage_BaseDriver::*)()) &Storage_BaseDriver::RootSectionSize, "None");
cls_Storage_BaseDriver.def("ReadRoot", [](Storage_BaseDriver &self, TCollection_AsciiString & rootName, Standard_Integer & aRef, TCollection_AsciiString & aType){ self.ReadRoot(rootName, aRef, aType); return aRef; }, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
cls_Storage_BaseDriver.def("EndReadRootSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadRootSection, "None");
cls_Storage_BaseDriver.def("BeginWriteRefSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteRefSection, "None");
cls_Storage_BaseDriver.def("SetRefSectionSize", (void (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::SetRefSectionSize, "None", py::arg("aSize"));
cls_Storage_BaseDriver.def("WriteReferenceType", (void (Storage_BaseDriver::*)(const Standard_Integer, const Standard_Integer)) &Storage_BaseDriver::WriteReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
cls_Storage_BaseDriver.def("EndWriteRefSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteRefSection, "None");
cls_Storage_BaseDriver.def("BeginReadRefSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadRefSection, "None");
cls_Storage_BaseDriver.def("RefSectionSize", (Standard_Integer (Storage_BaseDriver::*)()) &Storage_BaseDriver::RefSectionSize, "None");
cls_Storage_BaseDriver.def("ReadReferenceType", [](Storage_BaseDriver &self, Standard_Integer & reference, Standard_Integer & typeNum){ self.ReadReferenceType(reference, typeNum); return std::tuple<Standard_Integer &, Standard_Integer &>(reference, typeNum); }, "None", py::arg("reference"), py::arg("typeNum"));
cls_Storage_BaseDriver.def("EndReadRefSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadRefSection, "None");
cls_Storage_BaseDriver.def("BeginWriteDataSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteDataSection, "None");
cls_Storage_BaseDriver.def("WritePersistentObjectHeader", (void (Storage_BaseDriver::*)(const Standard_Integer, const Standard_Integer)) &Storage_BaseDriver::WritePersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
cls_Storage_BaseDriver.def("BeginWritePersistentObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWritePersistentObjectData, "None");
cls_Storage_BaseDriver.def("BeginWriteObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginWriteObjectData, "None");
cls_Storage_BaseDriver.def("EndWriteObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteObjectData, "None");
cls_Storage_BaseDriver.def("EndWritePersistentObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWritePersistentObjectData, "None");
cls_Storage_BaseDriver.def("EndWriteDataSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndWriteDataSection, "None");
cls_Storage_BaseDriver.def("BeginReadDataSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadDataSection, "None");
cls_Storage_BaseDriver.def("ReadPersistentObjectHeader", [](Storage_BaseDriver &self, Standard_Integer & aRef, Standard_Integer & aType){ self.ReadPersistentObjectHeader(aRef, aType); return std::tuple<Standard_Integer &, Standard_Integer &>(aRef, aType); }, "None", py::arg("aRef"), py::arg("aType"));
cls_Storage_BaseDriver.def("BeginReadPersistentObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadPersistentObjectData, "None");
cls_Storage_BaseDriver.def("BeginReadObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::BeginReadObjectData, "None");
cls_Storage_BaseDriver.def("EndReadObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadObjectData, "None");
cls_Storage_BaseDriver.def("EndReadPersistentObjectData", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadPersistentObjectData, "None");
cls_Storage_BaseDriver.def("EndReadDataSection", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::EndReadDataSection, "None");
cls_Storage_BaseDriver.def("SkipObject", (void (Storage_BaseDriver::*)()) &Storage_BaseDriver::SkipObject, "None");
cls_Storage_BaseDriver.def("PutReference", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::PutReference, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("PutCharacter", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Character)) &Storage_BaseDriver::PutCharacter, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Character)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("PutExtCharacter", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_ExtCharacter)) &Storage_BaseDriver::PutExtCharacter, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_ExtCharacter)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("PutInteger", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::PutInteger, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Integer)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("PutBoolean", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Boolean)) &Storage_BaseDriver::PutBoolean, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Boolean)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("PutReal", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Real)) &Storage_BaseDriver::PutReal, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_Real)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("PutShortReal", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_ShortReal)) &Storage_BaseDriver::PutShortReal, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_left", (Storage_BaseDriver & (Storage_BaseDriver::*)(const Standard_ShortReal)) &Storage_BaseDriver::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("GetReference", [](Storage_BaseDriver &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.GetReference(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("GetCharacter", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_Character &)) &Storage_BaseDriver::GetCharacter, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_right", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_Character &)) &Storage_BaseDriver::operator>>, py::is_operator(), "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("GetExtCharacter", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_ExtCharacter &)) &Storage_BaseDriver::GetExtCharacter, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_right", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_ExtCharacter &)) &Storage_BaseDriver::operator>>, py::is_operator(), "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("GetInteger", [](Storage_BaseDriver &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.GetInteger(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_right", [](Storage_BaseDriver &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.operator>>(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("GetBoolean", [](Storage_BaseDriver &self, Standard_Boolean & aValue){ Storage_BaseDriver & rv = self.GetBoolean(aValue); return std::tuple<Storage_BaseDriver &, Standard_Boolean &>(rv, aValue); }, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_right", [](Storage_BaseDriver &self, Standard_Boolean & aValue){ Storage_BaseDriver & rv = self.operator>>(aValue); return std::tuple<Storage_BaseDriver &, Standard_Boolean &>(rv, aValue); }, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("GetReal", [](Storage_BaseDriver &self, Standard_Real & aValue){ Storage_BaseDriver & rv = self.GetReal(aValue); return std::tuple<Storage_BaseDriver &, Standard_Real &>(rv, aValue); }, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_right", [](Storage_BaseDriver &self, Standard_Real & aValue){ Storage_BaseDriver & rv = self.operator>>(aValue); return std::tuple<Storage_BaseDriver &, Standard_Real &>(rv, aValue); }, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("GetShortReal", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_ShortReal &)) &Storage_BaseDriver::GetShortReal, "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("bits_right", (Storage_BaseDriver & (Storage_BaseDriver::*)(Standard_ShortReal &)) &Storage_BaseDriver::operator>>, py::is_operator(), "None", py::arg("aValue"));
cls_Storage_BaseDriver.def("Close", (Storage_Error (Storage_BaseDriver::*)()) &Storage_BaseDriver::Close, "None");

// Enums

}