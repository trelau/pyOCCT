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
#include <TCollection_ExtendedString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_IStream.hxx>
#include <Standard_Handle.hxx>
#include <Storage_Data.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <FSD_FStream.hxx>
#include <FSD_File.hxx>

void bind_FSD_File(py::module &mod){

py::class_<FSD_File, std::unique_ptr<FSD_File, Deleter<FSD_File>>, Storage_BaseDriver> cls_FSD_File(mod, "FSD_File", "A general driver which defines as a file, the physical container for data to be stored or retrieved.");

// Constructors
cls_FSD_File.def(py::init<>());

// Fields

// Methods
// cls_FSD_File.def_static("operator new_", (void * (*)(size_t)) &FSD_File::operator new, "None", py::arg("theSize"));
// cls_FSD_File.def_static("operator delete_", (void (*)(void *)) &FSD_File::operator delete, "None", py::arg("theAddress"));
// cls_FSD_File.def_static("operator new[]_", (void * (*)(size_t)) &FSD_File::operator new[], "None", py::arg("theSize"));
// cls_FSD_File.def_static("operator delete[]_", (void (*)(void *)) &FSD_File::operator delete[], "None", py::arg("theAddress"));
// cls_FSD_File.def_static("operator new_", (void * (*)(size_t, void *)) &FSD_File::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FSD_File.def_static("operator delete_", (void (*)(void *, void *)) &FSD_File::operator delete, "None", py::arg(""), py::arg(""));
cls_FSD_File.def("Open", (Storage_Error (FSD_File::*)(const TCollection_AsciiString &, const Storage_OpenMode)) &FSD_File::Open, "Assigns as aName the name of the file to be driven by this driver. aMode precises if the file is opened in read or write mode. The function returns Storage_VSOk if the file is opened correctly, or any other value of the Storage_Error enumeration which specifies the problem encountered.", py::arg("aName"), py::arg("aMode"));
cls_FSD_File.def("IsEnd", (Standard_Boolean (FSD_File::*)()) &FSD_File::IsEnd, "None");
cls_FSD_File.def("Tell", (Storage_Position (FSD_File::*)()) &FSD_File::Tell, "return position in the file. Return -1 upon error.");
cls_FSD_File.def_static("IsGoodFileType_", (Storage_Error (*)(const TCollection_AsciiString &)) &FSD_File::IsGoodFileType, "None", py::arg("aName"));
cls_FSD_File.def("BeginWriteInfoSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteInfoSection, "None");
cls_FSD_File.def("WriteInfo", (void (FSD_File::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TColStd_SequenceOfAsciiString &)) &FSD_File::WriteInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
cls_FSD_File.def("EndWriteInfoSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteInfoSection, "None");
cls_FSD_File.def("BeginReadInfoSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadInfoSection, "None");
cls_FSD_File.def("ReadInfo", [](FSD_File &self, Standard_Integer & nbObj, TCollection_AsciiString & dbVersion, TCollection_AsciiString & date, TCollection_AsciiString & schemaName, TCollection_AsciiString & schemaVersion, TCollection_ExtendedString & appName, TCollection_AsciiString & appVersion, TCollection_ExtendedString & objectType, TColStd_SequenceOfAsciiString & userInfo){ self.ReadInfo(nbObj, dbVersion, date, schemaName, schemaVersion, appName, appVersion, objectType, userInfo); return nbObj; }, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
cls_FSD_File.def("ReadCompleteInfo", (void (FSD_File::*)(Standard_IStream &, opencascade::handle<Storage_Data> &)) &FSD_File::ReadCompleteInfo, "None", py::arg("theIStream"), py::arg("theData"));
cls_FSD_File.def("EndReadInfoSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadInfoSection, "None");
cls_FSD_File.def("BeginWriteCommentSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteCommentSection, "None");
cls_FSD_File.def("WriteComment", (void (FSD_File::*)(const TColStd_SequenceOfExtendedString &)) &FSD_File::WriteComment, "None", py::arg("userComments"));
cls_FSD_File.def("EndWriteCommentSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteCommentSection, "None");
cls_FSD_File.def("BeginReadCommentSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadCommentSection, "None");
cls_FSD_File.def("ReadComment", (void (FSD_File::*)(TColStd_SequenceOfExtendedString &)) &FSD_File::ReadComment, "None", py::arg("userComments"));
cls_FSD_File.def("EndReadCommentSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadCommentSection, "None");
cls_FSD_File.def("BeginWriteTypeSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteTypeSection, "None");
cls_FSD_File.def("SetTypeSectionSize", (void (FSD_File::*)(const Standard_Integer)) &FSD_File::SetTypeSectionSize, "None", py::arg("aSize"));
cls_FSD_File.def("WriteTypeInformations", (void (FSD_File::*)(const Standard_Integer, const TCollection_AsciiString &)) &FSD_File::WriteTypeInformations, "None", py::arg("typeNum"), py::arg("typeName"));
cls_FSD_File.def("EndWriteTypeSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteTypeSection, "None");
cls_FSD_File.def("BeginReadTypeSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadTypeSection, "None");
cls_FSD_File.def("TypeSectionSize", (Standard_Integer (FSD_File::*)()) &FSD_File::TypeSectionSize, "None");
cls_FSD_File.def("ReadTypeInformations", [](FSD_File &self, Standard_Integer & typeNum, TCollection_AsciiString & typeName){ self.ReadTypeInformations(typeNum, typeName); return typeNum; }, "None", py::arg("typeNum"), py::arg("typeName"));
cls_FSD_File.def("EndReadTypeSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadTypeSection, "None");
cls_FSD_File.def("BeginWriteRootSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteRootSection, "None");
cls_FSD_File.def("SetRootSectionSize", (void (FSD_File::*)(const Standard_Integer)) &FSD_File::SetRootSectionSize, "None", py::arg("aSize"));
cls_FSD_File.def("WriteRoot", (void (FSD_File::*)(const TCollection_AsciiString &, const Standard_Integer, const TCollection_AsciiString &)) &FSD_File::WriteRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
cls_FSD_File.def("EndWriteRootSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteRootSection, "None");
cls_FSD_File.def("BeginReadRootSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadRootSection, "None");
cls_FSD_File.def("RootSectionSize", (Standard_Integer (FSD_File::*)()) &FSD_File::RootSectionSize, "None");
cls_FSD_File.def("ReadRoot", [](FSD_File &self, TCollection_AsciiString & rootName, Standard_Integer & aRef, TCollection_AsciiString & aType){ self.ReadRoot(rootName, aRef, aType); return aRef; }, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
cls_FSD_File.def("EndReadRootSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadRootSection, "None");
cls_FSD_File.def("BeginWriteRefSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteRefSection, "None");
cls_FSD_File.def("SetRefSectionSize", (void (FSD_File::*)(const Standard_Integer)) &FSD_File::SetRefSectionSize, "None", py::arg("aSize"));
cls_FSD_File.def("WriteReferenceType", (void (FSD_File::*)(const Standard_Integer, const Standard_Integer)) &FSD_File::WriteReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
cls_FSD_File.def("EndWriteRefSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteRefSection, "None");
cls_FSD_File.def("BeginReadRefSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadRefSection, "None");
cls_FSD_File.def("RefSectionSize", (Standard_Integer (FSD_File::*)()) &FSD_File::RefSectionSize, "None");
cls_FSD_File.def("ReadReferenceType", [](FSD_File &self, Standard_Integer & reference, Standard_Integer & typeNum){ self.ReadReferenceType(reference, typeNum); return std::tuple<Standard_Integer &, Standard_Integer &>(reference, typeNum); }, "None", py::arg("reference"), py::arg("typeNum"));
cls_FSD_File.def("EndReadRefSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadRefSection, "None");
cls_FSD_File.def("BeginWriteDataSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteDataSection, "None");
cls_FSD_File.def("WritePersistentObjectHeader", (void (FSD_File::*)(const Standard_Integer, const Standard_Integer)) &FSD_File::WritePersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
cls_FSD_File.def("BeginWritePersistentObjectData", (void (FSD_File::*)()) &FSD_File::BeginWritePersistentObjectData, "None");
cls_FSD_File.def("BeginWriteObjectData", (void (FSD_File::*)()) &FSD_File::BeginWriteObjectData, "None");
cls_FSD_File.def("EndWriteObjectData", (void (FSD_File::*)()) &FSD_File::EndWriteObjectData, "None");
cls_FSD_File.def("EndWritePersistentObjectData", (void (FSD_File::*)()) &FSD_File::EndWritePersistentObjectData, "None");
cls_FSD_File.def("EndWriteDataSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteDataSection, "None");
cls_FSD_File.def("BeginReadDataSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadDataSection, "None");
cls_FSD_File.def("ReadPersistentObjectHeader", [](FSD_File &self, Standard_Integer & aRef, Standard_Integer & aType){ self.ReadPersistentObjectHeader(aRef, aType); return std::tuple<Standard_Integer &, Standard_Integer &>(aRef, aType); }, "None", py::arg("aRef"), py::arg("aType"));
cls_FSD_File.def("BeginReadPersistentObjectData", (void (FSD_File::*)()) &FSD_File::BeginReadPersistentObjectData, "None");
cls_FSD_File.def("BeginReadObjectData", (void (FSD_File::*)()) &FSD_File::BeginReadObjectData, "None");
cls_FSD_File.def("EndReadObjectData", (void (FSD_File::*)()) &FSD_File::EndReadObjectData, "None");
cls_FSD_File.def("EndReadPersistentObjectData", (void (FSD_File::*)()) &FSD_File::EndReadPersistentObjectData, "None");
cls_FSD_File.def("EndReadDataSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadDataSection, "None");
cls_FSD_File.def("SkipObject", (void (FSD_File::*)()) &FSD_File::SkipObject, "None");
cls_FSD_File.def("PutReference", (Storage_BaseDriver & (FSD_File::*)(const Standard_Integer)) &FSD_File::PutReference, "None", py::arg("aValue"));
cls_FSD_File.def("PutCharacter", (Storage_BaseDriver & (FSD_File::*)(const Standard_Character)) &FSD_File::PutCharacter, "None", py::arg("aValue"));
cls_FSD_File.def("bits_left", (Storage_BaseDriver & (FSD_File::*)(const Standard_Character)) &FSD_File::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_File.def("PutExtCharacter", (Storage_BaseDriver & (FSD_File::*)(const Standard_ExtCharacter)) &FSD_File::PutExtCharacter, "None", py::arg("aValue"));
cls_FSD_File.def("bits_left", (Storage_BaseDriver & (FSD_File::*)(const Standard_ExtCharacter)) &FSD_File::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_File.def("PutInteger", (Storage_BaseDriver & (FSD_File::*)(const Standard_Integer)) &FSD_File::PutInteger, "None", py::arg("aValue"));
cls_FSD_File.def("bits_left", (Storage_BaseDriver & (FSD_File::*)(const Standard_Integer)) &FSD_File::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_File.def("PutBoolean", (Storage_BaseDriver & (FSD_File::*)(const Standard_Boolean)) &FSD_File::PutBoolean, "None", py::arg("aValue"));
cls_FSD_File.def("bits_left", (Storage_BaseDriver & (FSD_File::*)(const Standard_Boolean)) &FSD_File::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_File.def("PutReal", (Storage_BaseDriver & (FSD_File::*)(const Standard_Real)) &FSD_File::PutReal, "None", py::arg("aValue"));
cls_FSD_File.def("bits_left", (Storage_BaseDriver & (FSD_File::*)(const Standard_Real)) &FSD_File::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_File.def("PutShortReal", (Storage_BaseDriver & (FSD_File::*)(const Standard_ShortReal)) &FSD_File::PutShortReal, "None", py::arg("aValue"));
cls_FSD_File.def("bits_left", (Storage_BaseDriver & (FSD_File::*)(const Standard_ShortReal)) &FSD_File::operator<<, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_File.def("GetReference", [](FSD_File &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.GetReference(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_File.def("GetCharacter", (Storage_BaseDriver & (FSD_File::*)(Standard_Character &)) &FSD_File::GetCharacter, "None", py::arg("aValue"));
cls_FSD_File.def("bits_right", (Storage_BaseDriver & (FSD_File::*)(Standard_Character &)) &FSD_File::operator>>, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_File.def("GetExtCharacter", (Storage_BaseDriver & (FSD_File::*)(Standard_ExtCharacter &)) &FSD_File::GetExtCharacter, "None", py::arg("aValue"));
cls_FSD_File.def("bits_right", (Storage_BaseDriver & (FSD_File::*)(Standard_ExtCharacter &)) &FSD_File::operator>>, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_File.def("GetInteger", [](FSD_File &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.GetInteger(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_File.def("bits_right", [](FSD_File &self, Standard_Integer & aValue){ Storage_BaseDriver & rv = self.operator>>(aValue); return std::tuple<Storage_BaseDriver &, Standard_Integer &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_File.def("GetBoolean", [](FSD_File &self, Standard_Boolean & aValue){ Storage_BaseDriver & rv = self.GetBoolean(aValue); return std::tuple<Storage_BaseDriver &, Standard_Boolean &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_File.def("bits_right", [](FSD_File &self, Standard_Boolean & aValue){ Storage_BaseDriver & rv = self.operator>>(aValue); return std::tuple<Storage_BaseDriver &, Standard_Boolean &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_File.def("GetReal", [](FSD_File &self, Standard_Real & aValue){ Storage_BaseDriver & rv = self.GetReal(aValue); return std::tuple<Storage_BaseDriver &, Standard_Real &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_File.def("bits_right", [](FSD_File &self, Standard_Real & aValue){ Storage_BaseDriver & rv = self.operator>>(aValue); return std::tuple<Storage_BaseDriver &, Standard_Real &>(rv, aValue); }, "None", py::arg("aValue"));
cls_FSD_File.def("GetShortReal", (Storage_BaseDriver & (FSD_File::*)(Standard_ShortReal &)) &FSD_File::GetShortReal, "None", py::arg("aValue"));
cls_FSD_File.def("bits_right", (Storage_BaseDriver & (FSD_File::*)(Standard_ShortReal &)) &FSD_File::operator>>, py::is_operator(), "None", py::arg("aValue"));
cls_FSD_File.def("Close", (Storage_Error (FSD_File::*)()) &FSD_File::Close, "Closes the file driven by this driver. This file was opened by the last call to the function Open. The function returns Storage_VSOk if the closure is correctly done, or any other value of the Storage_Error enumeration which specifies the problem encountered.");
cls_FSD_File.def("Destroy", (void (FSD_File::*)()) &FSD_File::Destroy, "None");
cls_FSD_File.def_static("MagicNumber_", (Standard_CString (*)()) &FSD_File::MagicNumber, "None");

// Enums

}