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
#include <Storage_BaseDriver.hxx>
#include <Standard.hxx>
#include <Storage_Error.hxx>
#include <TCollection_AsciiString.hxx>
#include <Storage_OpenMode.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_Position.hxx>
#include <Standard_OStream.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_IStream.hxx>
#include <Standard_Handle.hxx>
#include <Storage_Data.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <FSD_FileHeader.hxx>
#include <Storage_HeaderData.hxx>
#include <FSD_BStream.hxx>
#include <FSD_BinaryFile.hxx>

void bind_FSD_BinaryFile(py::module &mod){

py::class_<FSD_BinaryFile, std::unique_ptr<FSD_BinaryFile>, Storage_BaseDriver> cls_FSD_BinaryFile(mod, "FSD_BinaryFile", "None");

// Constructors
cls_FSD_BinaryFile.def(py::init<>());

// Fields

// Methods
// cls_FSD_BinaryFile.def_static("operator new_", (void * (*)(size_t)) &FSD_BinaryFile::operator new, "None", py::arg("theSize"));
// cls_FSD_BinaryFile.def_static("operator delete_", (void (*)(void *)) &FSD_BinaryFile::operator delete, "None", py::arg("theAddress"));
// cls_FSD_BinaryFile.def_static("operator new[]_", (void * (*)(size_t)) &FSD_BinaryFile::operator new[], "None", py::arg("theSize"));
// cls_FSD_BinaryFile.def_static("operator delete[]_", (void (*)(void *)) &FSD_BinaryFile::operator delete[], "None", py::arg("theAddress"));
// cls_FSD_BinaryFile.def_static("operator new_", (void * (*)(size_t, void *)) &FSD_BinaryFile::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FSD_BinaryFile.def_static("operator delete_", (void (*)(void *, void *)) &FSD_BinaryFile::operator delete, "None", py::arg(""), py::arg(""));
cls_FSD_BinaryFile.def("Open", (Storage_Error (FSD_BinaryFile::*)(const TCollection_AsciiString &, const Storage_OpenMode)) &FSD_BinaryFile::Open, "None", py::arg("aName"), py::arg("aMode"));
cls_FSD_BinaryFile.def("IsEnd", (Standard_Boolean (FSD_BinaryFile::*)()) &FSD_BinaryFile::IsEnd, "None");
cls_FSD_BinaryFile.def("Tell", (Storage_Position (FSD_BinaryFile::*)()) &FSD_BinaryFile::Tell, "return position in the file. Return -1 upon error.");
cls_FSD_BinaryFile.def_static("IsGoodFileType_", (Storage_Error (*)(const TCollection_AsciiString &)) &FSD_BinaryFile::IsGoodFileType, "None", py::arg("aName"));
cls_FSD_BinaryFile.def("BeginWriteInfoSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteInfoSection, "None");
cls_FSD_BinaryFile.def_static("WriteInfo_", [](Standard_OStream & a0, const Standard_Integer a1, const TCollection_AsciiString & a2, const TCollection_AsciiString & a3, const TCollection_AsciiString & a4, const TCollection_AsciiString & a5, const TCollection_ExtendedString & a6, const TCollection_AsciiString & a7, const TCollection_ExtendedString & a8, const TColStd_SequenceOfAsciiString & a9) -> Standard_Integer { return FSD_BinaryFile::WriteInfo(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); });
cls_FSD_BinaryFile.def_static("WriteInfo_", (Standard_Integer (*)(Standard_OStream &, const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TColStd_SequenceOfAsciiString &, const Standard_Boolean)) &FSD_BinaryFile::WriteInfo, "None", py::arg("theOStream"), py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"), py::arg("theOnlyCount"));
cls_FSD_BinaryFile.def("WriteInfo", (void (FSD_BinaryFile::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TColStd_SequenceOfAsciiString &)) &FSD_BinaryFile::WriteInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
cls_FSD_BinaryFile.def("EndWriteInfoSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteInfoSection, "None");
cls_FSD_BinaryFile.def("EndWriteInfoSection", (Storage_Error (FSD_BinaryFile::*)(Standard_OStream &)) &FSD_BinaryFile::EndWriteInfoSection, "None", py::arg("theOStream"));
cls_FSD_BinaryFile.def("BeginReadInfoSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadInfoSection, "None");
cls_FSD_BinaryFile.def("ReadInfo", [](FSD_BinaryFile &self, Standard_Integer & nbObj, TCollection_AsciiString & dbVersion, TCollection_AsciiString & date, TCollection_AsciiString & schemaName, TCollection_AsciiString & schemaVersion, TCollection_ExtendedString & appName, TCollection_AsciiString & appVersion, TCollection_ExtendedString & objectType, TColStd_SequenceOfAsciiString & userInfo){ self.ReadInfo(nbObj, dbVersion, date, schemaName, schemaVersion, appName, appVersion, objectType, userInfo); return nbObj; }, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
cls_FSD_BinaryFile.def("ReadCompleteInfo", (void (FSD_BinaryFile::*)(Standard_IStream &, opencascade::handle<Storage_Data> &)) &FSD_BinaryFile::ReadCompleteInfo, "None", py::arg("theIStream"), py::arg("theData"));
cls_FSD_BinaryFile.def("EndReadInfoSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadInfoSection, "None");
cls_FSD_BinaryFile.def("BeginWriteCommentSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteCommentSection, "None");
cls_FSD_BinaryFile.def("BeginWriteCommentSection", (Storage_Error (FSD_BinaryFile::*)(Standard_OStream &)) &FSD_BinaryFile::BeginWriteCommentSection, "None", py::arg("theOStream"));
cls_FSD_BinaryFile.def("WriteComment", (void (FSD_BinaryFile::*)(const TColStd_SequenceOfExtendedString &)) &FSD_BinaryFile::WriteComment, "None", py::arg("userComments"));
cls_FSD_BinaryFile.def_static("WriteComment_", [](Standard_OStream & a0, const TColStd_SequenceOfExtendedString & a1) -> Standard_Integer { return FSD_BinaryFile::WriteComment(a0, a1); });
cls_FSD_BinaryFile.def_static("WriteComment_", (Standard_Integer (*)(Standard_OStream &, const TColStd_SequenceOfExtendedString &, const Standard_Boolean)) &FSD_BinaryFile::WriteComment, "None", py::arg("theOStream"), py::arg("theComments"), py::arg("theOnlyCount"));
cls_FSD_BinaryFile.def("EndWriteCommentSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteCommentSection, "None");
cls_FSD_BinaryFile.def("EndWriteCommentSection", (Storage_Error (FSD_BinaryFile::*)(Standard_OStream &)) &FSD_BinaryFile::EndWriteCommentSection, "None", py::arg("theOStream"));
cls_FSD_BinaryFile.def("BeginReadCommentSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadCommentSection, "None");
cls_FSD_BinaryFile.def("ReadComment", (void (FSD_BinaryFile::*)(TColStd_SequenceOfExtendedString &)) &FSD_BinaryFile::ReadComment, "None", py::arg("userComments"));
cls_FSD_BinaryFile.def_static("ReadComment_", (void (*)(Standard_IStream &, TColStd_SequenceOfExtendedString &)) &FSD_BinaryFile::ReadComment, "None", py::arg("theIStream"), py::arg("userComments"));
cls_FSD_BinaryFile.def("EndReadCommentSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadCommentSection, "None");
cls_FSD_BinaryFile.def("BeginWriteTypeSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteTypeSection, "None");
cls_FSD_BinaryFile.def("SetTypeSectionSize", (void (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::SetTypeSectionSize, "None", py::arg("aSize"));
cls_FSD_BinaryFile.def("WriteTypeInformations", (void (FSD_BinaryFile::*)(const Standard_Integer, const TCollection_AsciiString &)) &FSD_BinaryFile::WriteTypeInformations, "None", py::arg("typeNum"), py::arg("typeName"));
cls_FSD_BinaryFile.def("EndWriteTypeSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteTypeSection, "None");
cls_FSD_BinaryFile.def("BeginReadTypeSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadTypeSection, "None");
cls_FSD_BinaryFile.def("TypeSectionSize", (Standard_Integer (FSD_BinaryFile::*)()) &FSD_BinaryFile::TypeSectionSize, "None");
cls_FSD_BinaryFile.def_static("TypeSectionSize_", (Standard_Integer (*)(Standard_IStream &)) &FSD_BinaryFile::TypeSectionSize, "None", py::arg("theIStream"));
cls_FSD_BinaryFile.def("ReadTypeInformations", [](FSD_BinaryFile &self, Standard_Integer & typeNum, TCollection_AsciiString & typeName){ self.ReadTypeInformations(typeNum, typeName); return typeNum; }, "None", py::arg("typeNum"), py::arg("typeName"));
cls_FSD_BinaryFile.def_static("ReadTypeInformations_", [](Standard_IStream & theIStream, Standard_Integer & typeNum, TCollection_AsciiString & typeName){ FSD_BinaryFile::ReadTypeInformations(theIStream, typeNum, typeName); return typeNum; }, "None", py::arg("theIStream"), py::arg("typeNum"), py::arg("typeName"));
cls_FSD_BinaryFile.def("EndReadTypeSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadTypeSection, "None");
cls_FSD_BinaryFile.def("BeginWriteRootSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteRootSection, "None");
cls_FSD_BinaryFile.def("SetRootSectionSize", (void (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::SetRootSectionSize, "None", py::arg("aSize"));
cls_FSD_BinaryFile.def("WriteRoot", (void (FSD_BinaryFile::*)(const TCollection_AsciiString &, const Standard_Integer, const TCollection_AsciiString &)) &FSD_BinaryFile::WriteRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
cls_FSD_BinaryFile.def("EndWriteRootSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteRootSection, "None");
cls_FSD_BinaryFile.def("BeginReadRootSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadRootSection, "None");
cls_FSD_BinaryFile.def("RootSectionSize", (Standard_Integer (FSD_BinaryFile::*)()) &FSD_BinaryFile::RootSectionSize, "None");
cls_FSD_BinaryFile.def_static("RootSectionSize_", (Standard_Integer (*)(Standard_IStream &)) &FSD_BinaryFile::RootSectionSize, "None", py::arg("theIStream"));
cls_FSD_BinaryFile.def("ReadRoot", [](FSD_BinaryFile &self, TCollection_AsciiString & rootName, Standard_Integer & aRef, TCollection_AsciiString & aType){ self.ReadRoot(rootName, aRef, aType); return aRef; }, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
cls_FSD_BinaryFile.def_static("ReadRoot_", [](Standard_IStream & theIStream, TCollection_AsciiString & rootName, Standard_Integer & aRef, TCollection_AsciiString & aType){ FSD_BinaryFile::ReadRoot(theIStream, rootName, aRef, aType); return aRef; }, "None", py::arg("theIStream"), py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
cls_FSD_BinaryFile.def("EndReadRootSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadRootSection, "None");
cls_FSD_BinaryFile.def("BeginWriteRefSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteRefSection, "None");
cls_FSD_BinaryFile.def("SetRefSectionSize", (void (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::SetRefSectionSize, "None", py::arg("aSize"));
cls_FSD_BinaryFile.def("WriteReferenceType", (void (FSD_BinaryFile::*)(const Standard_Integer, const Standard_Integer)) &FSD_BinaryFile::WriteReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
cls_FSD_BinaryFile.def("EndWriteRefSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteRefSection, "None");
cls_FSD_BinaryFile.def("BeginReadRefSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadRefSection, "None");
cls_FSD_BinaryFile.def("RefSectionSize", (Standard_Integer (FSD_BinaryFile::*)()) &FSD_BinaryFile::RefSectionSize, "None");
cls_FSD_BinaryFile.def_static("RefSectionSize_", (Standard_Integer (*)(Standard_IStream &)) &FSD_BinaryFile::RefSectionSize, "None", py::arg("theIStream"));
cls_FSD_BinaryFile.def("ReadReferenceType", [](FSD_BinaryFile &self, Standard_Integer & reference, Standard_Integer & typeNum){ self.ReadReferenceType(reference, typeNum); return std::tuple<Standard_Integer &, Standard_Integer &>(reference, typeNum); }, "None", py::arg("reference"), py::arg("typeNum"));
cls_FSD_BinaryFile.def_static("ReadReferenceType_", [](Standard_IStream & theIStream, Standard_Integer & reference, Standard_Integer & typeNum){ FSD_BinaryFile::ReadReferenceType(theIStream, reference, typeNum); return std::tuple<Standard_Integer &, Standard_Integer &>(reference, typeNum); }, "None", py::arg("theIStream"), py::arg("reference"), py::arg("typeNum"));
cls_FSD_BinaryFile.def("EndReadRefSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadRefSection, "None");
cls_FSD_BinaryFile.def("BeginWriteDataSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteDataSection, "None");
cls_FSD_BinaryFile.def("WritePersistentObjectHeader", (void (FSD_BinaryFile::*)(const Standard_Integer, const Standard_Integer)) &FSD_BinaryFile::WritePersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
cls_FSD_BinaryFile.def("BeginWritePersistentObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWritePersistentObjectData, "None");
cls_FSD_BinaryFile.def("BeginWriteObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteObjectData, "None");
cls_FSD_BinaryFile.def("EndWriteObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteObjectData, "None");
cls_FSD_BinaryFile.def("EndWritePersistentObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWritePersistentObjectData, "None");
cls_FSD_BinaryFile.def("EndWriteDataSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteDataSection, "None");
cls_FSD_BinaryFile.def("BeginReadDataSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadDataSection, "None");
cls_FSD_BinaryFile.def("ReadPersistentObjectHeader", [](FSD_BinaryFile &self, Standard_Integer & aRef, Standard_Integer & aType){ self.ReadPersistentObjectHeader(aRef, aType); return std::tuple<Standard_Integer &, Standard_Integer &>(aRef, aType); }, "None", py::arg("aRef"), py::arg("aType"));
cls_FSD_BinaryFile.def("BeginReadPersistentObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadPersistentObjectData, "None");
cls_FSD_BinaryFile.def("BeginReadObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadObjectData, "None");
cls_FSD_BinaryFile.def("EndReadObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadObjectData, "None");
cls_FSD_BinaryFile.def("EndReadPersistentObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadPersistentObjectData, "None");
cls_FSD_BinaryFile.def("EndReadDataSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadDataSection, "None");
cls_FSD_BinaryFile.def("SkipObject", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::SkipObject, "None");
cls_FSD_BinaryFile.def("PutReference", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::PutReference, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("PutCharacter", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Character)) &FSD_BinaryFile::PutCharacter, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_left", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Character)) &FSD_BinaryFile::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("PutExtCharacter", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_ExtCharacter)) &FSD_BinaryFile::PutExtCharacter, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_left", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_ExtCharacter)) &FSD_BinaryFile::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_BinaryFile.def_static("PutInteger_", [](Standard_OStream & a0, const Standard_Integer a1) -> Standard_Integer { return FSD_BinaryFile::PutInteger(a0, a1); });
cls_FSD_BinaryFile.def_static("PutInteger_", (Standard_Integer (*)(Standard_OStream &, const Standard_Integer, const Standard_Boolean)) &FSD_BinaryFile::PutInteger, "None", py::arg("theOStream"), py::arg("aValue"), py::arg("theOnlyCount"));
cls_FSD_BinaryFile.def("PutInteger", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::PutInteger, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_left", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("PutBoolean", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Boolean)) &FSD_BinaryFile::PutBoolean, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_left", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Boolean)) &FSD_BinaryFile::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("PutReal", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Real)) &FSD_BinaryFile::PutReal, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_left", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Real)) &FSD_BinaryFile::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("PutShortReal", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_ShortReal)) &FSD_BinaryFile::PutShortReal, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_left", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_ShortReal)) &FSD_BinaryFile::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("GetReference", [](FSD_BinaryFile &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.GetReference(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("GetCharacter", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Character &)) &FSD_BinaryFile::GetCharacter, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_right", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Character &)) &FSD_BinaryFile::operator>>, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_BinaryFile.def_static("GetReference_", [](Standard_IStream & theIStream, Standard_Integer & aValue){ FSD_BinaryFile::GetReference(theIStream, aValue); return aValue; }, "None", py::arg("theIStream"), py::arg("aValue"));
cls_FSD_BinaryFile.def("GetExtCharacter", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_ExtCharacter &)) &FSD_BinaryFile::GetExtCharacter, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_right", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_ExtCharacter &)) &FSD_BinaryFile::operator>>, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("GetInteger", [](FSD_BinaryFile &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.GetInteger(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_right", [](FSD_BinaryFile &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.operator>>(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def_static("GetInteger_", [](Standard_IStream & theIStream, Standard_Integer & aValue){ FSD_BinaryFile::GetInteger(theIStream, aValue); return aValue; }, "None", py::arg("theIStream"), py::arg("aValue"));
cls_FSD_BinaryFile.def("GetBoolean", [](FSD_BinaryFile &self, Standard_Boolean & aValue){ Storage_BaseDriver & rv = self.GetBoolean(aValue); return std::tuple<Storage_BaseDriver &, Standard_Boolean &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_right", [](FSD_BinaryFile &self, Standard_Boolean & aValue){ Storage_BaseDriver & rv = self.operator>>(aValue); return std::tuple<Storage_BaseDriver &, Standard_Boolean &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("GetReal", [](FSD_BinaryFile &self, Standard_Real & aValue){ Storage_BaseDriver & rv = self.GetReal(aValue); return std::tuple<Storage_BaseDriver &, Standard_Real &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_right", [](FSD_BinaryFile &self, Standard_Real & aValue){ Storage_BaseDriver & rv = self.operator>>(aValue); return std::tuple<Storage_BaseDriver &, Standard_Real &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("GetShortReal", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_ShortReal &)) &FSD_BinaryFile::GetShortReal, "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("bits_right", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_ShortReal &)) &FSD_BinaryFile::operator>>, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_BinaryFile.def("Close", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::Close, "None");
cls_FSD_BinaryFile.def("Destroy", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::Destroy, "None");
cls_FSD_BinaryFile.def_static("InverseInt_", (Standard_Integer (*)(const Standard_Integer)) &FSD_BinaryFile::InverseInt, "Inverse bytes in integer value", py::arg("theValue"));
cls_FSD_BinaryFile.def_static("InverseExtChar_", (Standard_ExtCharacter (*)(const Standard_ExtCharacter)) &FSD_BinaryFile::InverseExtChar, "Inverse bytes in extended character value", py::arg("theValue"));
cls_FSD_BinaryFile.def_static("InverseReal_", (Standard_Real (*)(const Standard_Real)) &FSD_BinaryFile::InverseReal, "Inverse bytes in real value", py::arg("theValue"));
cls_FSD_BinaryFile.def_static("InverseShortReal_", (Standard_ShortReal (*)(const Standard_ShortReal)) &FSD_BinaryFile::InverseShortReal, "Inverse bytes in short real value", py::arg("theValue"));
cls_FSD_BinaryFile.def_static("InverseSize_", (Standard_Size (*)(const Standard_Size)) &FSD_BinaryFile::InverseSize, "Inverse bytes in size value", py::arg("theValue"));
cls_FSD_BinaryFile.def_static("InverseUint64_", (uint64_t (*)(const uint64_t)) &FSD_BinaryFile::InverseUint64, "Inverse bytes in 64bit unsigned int value", py::arg("theValue"));
cls_FSD_BinaryFile.def_static("ReadHeader_", (void (*)(Standard_IStream &, FSD_FileHeader &)) &FSD_BinaryFile::ReadHeader, "None", py::arg("theIStream"), py::arg("theFileHeader"));
cls_FSD_BinaryFile.def_static("ReadHeaderData_", (void (*)(Standard_IStream &, const opencascade::handle<Storage_HeaderData> &)) &FSD_BinaryFile::ReadHeaderData, "None", py::arg("theIStream"), py::arg("theHeaderData"));
cls_FSD_BinaryFile.def_static("ReadString_", (void (*)(Standard_IStream &, TCollection_AsciiString &)) &FSD_BinaryFile::ReadString, "None", py::arg("theIStream"), py::arg("buffer"));
cls_FSD_BinaryFile.def_static("ReadExtendedString_", (void (*)(Standard_IStream &, TCollection_ExtendedString &)) &FSD_BinaryFile::ReadExtendedString, "None", py::arg("theIStream"), py::arg("buffer"));
cls_FSD_BinaryFile.def_static("WriteHeader_", [](Standard_OStream & a0, const FSD_FileHeader & a1) -> Standard_Integer { return FSD_BinaryFile::WriteHeader(a0, a1); });
cls_FSD_BinaryFile.def_static("WriteHeader_", (Standard_Integer (*)(Standard_OStream &, const FSD_FileHeader &, const Standard_Boolean)) &FSD_BinaryFile::WriteHeader, "None", py::arg("theOStream"), py::arg("theHeader"), py::arg("theOnlyCount"));
cls_FSD_BinaryFile.def_static("MagicNumber_", (Standard_CString (*)()) &FSD_BinaryFile::MagicNumber, "None");

// Enums

}