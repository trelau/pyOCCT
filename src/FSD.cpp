#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <FSD_BStream.hxx>
#include <FSD_FileHeader.hxx>
#include <Storage_BaseDriver.hxx>
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
#include <Storage_HeaderData.hxx>
#include <FSD_BinaryFile.hxx>
#include <FSD_FStream.hxx>
#include <FSD_CmpFile.hxx>
#include <FSD_File.hxx>

PYBIND11_MODULE(FSD, mod) {

	// IMPORT
	py::module::import("OCCT.Storage");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\FSD_FileHeader.hxx
	py::class_<FSD_FileHeader, std::unique_ptr<FSD_FileHeader, Deleter<FSD_FileHeader>>> cls_FSD_FileHeader(mod, "FSD_FileHeader", "None");
	cls_FSD_FileHeader.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\FSD_BinaryFile.hxx
	py::class_<FSD_BinaryFile, std::unique_ptr<FSD_BinaryFile, Deleter<FSD_BinaryFile>>, Storage_BaseDriver> cls_FSD_BinaryFile(mod, "FSD_BinaryFile", "None");
	cls_FSD_BinaryFile.def(py::init<>());
	cls_FSD_BinaryFile.def("Open", (Storage_Error (FSD_BinaryFile::*)(const TCollection_AsciiString &, const Storage_OpenMode)) &FSD_BinaryFile::Open, "None", py::arg("aName"), py::arg("aMode"));
	cls_FSD_BinaryFile.def("IsEnd", (Standard_Boolean (FSD_BinaryFile::*)()) &FSD_BinaryFile::IsEnd, "None");
	cls_FSD_BinaryFile.def("Tell", (Storage_Position (FSD_BinaryFile::*)()) &FSD_BinaryFile::Tell, "return position in the file. Return -1 upon error.");
	cls_FSD_BinaryFile.def_static("IsGoodFileType_", (Storage_Error (*)(const TCollection_AsciiString &)) &FSD_BinaryFile::IsGoodFileType, "None", py::arg("aName"));
	cls_FSD_BinaryFile.def("BeginWriteInfoSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteInfoSection, "None");
	cls_FSD_BinaryFile.def_static("WriteInfo_", [](Standard_OStream & a0, const Standard_Integer a1, const TCollection_AsciiString & a2, const TCollection_AsciiString & a3, const TCollection_AsciiString & a4, const TCollection_AsciiString & a5, const TCollection_ExtendedString & a6, const TCollection_AsciiString & a7, const TCollection_ExtendedString & a8, const TColStd_SequenceOfAsciiString & a9) -> Standard_Integer { return FSD_BinaryFile::WriteInfo(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }, py::arg("theOStream"), py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
	cls_FSD_BinaryFile.def_static("WriteInfo_", (Standard_Integer (*)(Standard_OStream &, const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TColStd_SequenceOfAsciiString &, const Standard_Boolean)) &FSD_BinaryFile::WriteInfo, "None", py::arg("theOStream"), py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"), py::arg("theOnlyCount"));
	cls_FSD_BinaryFile.def("WriteInfo", (void (FSD_BinaryFile::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TColStd_SequenceOfAsciiString &)) &FSD_BinaryFile::WriteInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
	cls_FSD_BinaryFile.def("EndWriteInfoSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteInfoSection, "None");
	cls_FSD_BinaryFile.def("EndWriteInfoSection", (Storage_Error (FSD_BinaryFile::*)(Standard_OStream &)) &FSD_BinaryFile::EndWriteInfoSection, "None", py::arg("theOStream"));
	cls_FSD_BinaryFile.def("BeginReadInfoSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadInfoSection, "None");
	cls_FSD_BinaryFile.def("ReadInfo", (void (FSD_BinaryFile::*)(Standard_Integer &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_ExtendedString &, TCollection_AsciiString &, TCollection_ExtendedString &, TColStd_SequenceOfAsciiString &)) &FSD_BinaryFile::ReadInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
	cls_FSD_BinaryFile.def("ReadCompleteInfo", (void (FSD_BinaryFile::*)(Standard_IStream &, opencascade::handle<Storage_Data> &)) &FSD_BinaryFile::ReadCompleteInfo, "None", py::arg("theIStream"), py::arg("theData"));
	cls_FSD_BinaryFile.def("EndReadInfoSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadInfoSection, "None");
	cls_FSD_BinaryFile.def("BeginWriteCommentSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteCommentSection, "None");
	cls_FSD_BinaryFile.def("BeginWriteCommentSection", (Storage_Error (FSD_BinaryFile::*)(Standard_OStream &)) &FSD_BinaryFile::BeginWriteCommentSection, "None", py::arg("theOStream"));
	cls_FSD_BinaryFile.def("WriteComment", (void (FSD_BinaryFile::*)(const TColStd_SequenceOfExtendedString &)) &FSD_BinaryFile::WriteComment, "None", py::arg("userComments"));
	cls_FSD_BinaryFile.def_static("WriteComment_", [](Standard_OStream & a0, const TColStd_SequenceOfExtendedString & a1) -> Standard_Integer { return FSD_BinaryFile::WriteComment(a0, a1); }, py::arg("theOStream"), py::arg("theComments"));
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
	cls_FSD_BinaryFile.def("ReadTypeInformations", (void (FSD_BinaryFile::*)(Standard_Integer &, TCollection_AsciiString &)) &FSD_BinaryFile::ReadTypeInformations, "None", py::arg("typeNum"), py::arg("typeName"));
	cls_FSD_BinaryFile.def_static("ReadTypeInformations_", (void (*)(Standard_IStream &, Standard_Integer &, TCollection_AsciiString &)) &FSD_BinaryFile::ReadTypeInformations, "None", py::arg("theIStream"), py::arg("typeNum"), py::arg("typeName"));
	cls_FSD_BinaryFile.def("EndReadTypeSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadTypeSection, "None");
	cls_FSD_BinaryFile.def("BeginWriteRootSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteRootSection, "None");
	cls_FSD_BinaryFile.def("SetRootSectionSize", (void (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::SetRootSectionSize, "None", py::arg("aSize"));
	cls_FSD_BinaryFile.def("WriteRoot", (void (FSD_BinaryFile::*)(const TCollection_AsciiString &, const Standard_Integer, const TCollection_AsciiString &)) &FSD_BinaryFile::WriteRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
	cls_FSD_BinaryFile.def("EndWriteRootSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteRootSection, "None");
	cls_FSD_BinaryFile.def("BeginReadRootSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadRootSection, "None");
	cls_FSD_BinaryFile.def("RootSectionSize", (Standard_Integer (FSD_BinaryFile::*)()) &FSD_BinaryFile::RootSectionSize, "None");
	cls_FSD_BinaryFile.def_static("RootSectionSize_", (Standard_Integer (*)(Standard_IStream &)) &FSD_BinaryFile::RootSectionSize, "None", py::arg("theIStream"));
	cls_FSD_BinaryFile.def("ReadRoot", (void (FSD_BinaryFile::*)(TCollection_AsciiString &, Standard_Integer &, TCollection_AsciiString &)) &FSD_BinaryFile::ReadRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
	cls_FSD_BinaryFile.def_static("ReadRoot_", (void (*)(Standard_IStream &, TCollection_AsciiString &, Standard_Integer &, TCollection_AsciiString &)) &FSD_BinaryFile::ReadRoot, "None", py::arg("theIStream"), py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
	cls_FSD_BinaryFile.def("EndReadRootSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadRootSection, "None");
	cls_FSD_BinaryFile.def("BeginWriteRefSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteRefSection, "None");
	cls_FSD_BinaryFile.def("SetRefSectionSize", (void (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::SetRefSectionSize, "None", py::arg("aSize"));
	cls_FSD_BinaryFile.def("WriteReferenceType", (void (FSD_BinaryFile::*)(const Standard_Integer, const Standard_Integer)) &FSD_BinaryFile::WriteReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
	cls_FSD_BinaryFile.def("EndWriteRefSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteRefSection, "None");
	cls_FSD_BinaryFile.def("BeginReadRefSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadRefSection, "None");
	cls_FSD_BinaryFile.def("RefSectionSize", (Standard_Integer (FSD_BinaryFile::*)()) &FSD_BinaryFile::RefSectionSize, "None");
	cls_FSD_BinaryFile.def_static("RefSectionSize_", (Standard_Integer (*)(Standard_IStream &)) &FSD_BinaryFile::RefSectionSize, "None", py::arg("theIStream"));
	cls_FSD_BinaryFile.def("ReadReferenceType", (void (FSD_BinaryFile::*)(Standard_Integer &, Standard_Integer &)) &FSD_BinaryFile::ReadReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
	cls_FSD_BinaryFile.def_static("ReadReferenceType_", (void (*)(Standard_IStream &, Standard_Integer &, Standard_Integer &)) &FSD_BinaryFile::ReadReferenceType, "None", py::arg("theIStream"), py::arg("reference"), py::arg("typeNum"));
	cls_FSD_BinaryFile.def("EndReadRefSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadRefSection, "None");
	cls_FSD_BinaryFile.def("BeginWriteDataSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteDataSection, "None");
	cls_FSD_BinaryFile.def("WritePersistentObjectHeader", (void (FSD_BinaryFile::*)(const Standard_Integer, const Standard_Integer)) &FSD_BinaryFile::WritePersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
	cls_FSD_BinaryFile.def("BeginWritePersistentObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWritePersistentObjectData, "None");
	cls_FSD_BinaryFile.def("BeginWriteObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginWriteObjectData, "None");
	cls_FSD_BinaryFile.def("EndWriteObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteObjectData, "None");
	cls_FSD_BinaryFile.def("EndWritePersistentObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWritePersistentObjectData, "None");
	cls_FSD_BinaryFile.def("EndWriteDataSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndWriteDataSection, "None");
	cls_FSD_BinaryFile.def("BeginReadDataSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadDataSection, "None");
	cls_FSD_BinaryFile.def("ReadPersistentObjectHeader", (void (FSD_BinaryFile::*)(Standard_Integer &, Standard_Integer &)) &FSD_BinaryFile::ReadPersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
	cls_FSD_BinaryFile.def("BeginReadPersistentObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadPersistentObjectData, "None");
	cls_FSD_BinaryFile.def("BeginReadObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::BeginReadObjectData, "None");
	cls_FSD_BinaryFile.def("EndReadObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadObjectData, "None");
	cls_FSD_BinaryFile.def("EndReadPersistentObjectData", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadPersistentObjectData, "None");
	cls_FSD_BinaryFile.def("EndReadDataSection", (Storage_Error (FSD_BinaryFile::*)()) &FSD_BinaryFile::EndReadDataSection, "None");
	cls_FSD_BinaryFile.def("SkipObject", (void (FSD_BinaryFile::*)()) &FSD_BinaryFile::SkipObject, "None");
	cls_FSD_BinaryFile.def("PutReference", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::PutReference, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("PutCharacter", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Character)) &FSD_BinaryFile::PutCharacter, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator<<", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Character)) &FSD_BinaryFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("PutExtCharacter", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_ExtCharacter)) &FSD_BinaryFile::PutExtCharacter, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator<<", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_ExtCharacter)) &FSD_BinaryFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def_static("PutInteger_", [](Standard_OStream & a0, const Standard_Integer a1) -> Standard_Integer { return FSD_BinaryFile::PutInteger(a0, a1); }, py::arg("theOStream"), py::arg("aValue"));
	cls_FSD_BinaryFile.def_static("PutInteger_", (Standard_Integer (*)(Standard_OStream &, const Standard_Integer, const Standard_Boolean)) &FSD_BinaryFile::PutInteger, "None", py::arg("theOStream"), py::arg("aValue"), py::arg("theOnlyCount"));
	cls_FSD_BinaryFile.def("PutInteger", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::PutInteger, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator<<", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Integer)) &FSD_BinaryFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("PutBoolean", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Boolean)) &FSD_BinaryFile::PutBoolean, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator<<", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Boolean)) &FSD_BinaryFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("PutReal", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Real)) &FSD_BinaryFile::PutReal, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator<<", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_Real)) &FSD_BinaryFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("PutShortReal", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_ShortReal)) &FSD_BinaryFile::PutShortReal, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator<<", (Storage_BaseDriver & (FSD_BinaryFile::*)(const Standard_ShortReal)) &FSD_BinaryFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("GetReference", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Integer &)) &FSD_BinaryFile::GetReference, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("GetCharacter", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Character &)) &FSD_BinaryFile::GetCharacter, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator>>", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Character &)) &FSD_BinaryFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def_static("GetReference_", (void (*)(Standard_IStream &, Standard_Integer &)) &FSD_BinaryFile::GetReference, "None", py::arg("theIStream"), py::arg("aValue"));
	cls_FSD_BinaryFile.def("GetExtCharacter", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_ExtCharacter &)) &FSD_BinaryFile::GetExtCharacter, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator>>", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_ExtCharacter &)) &FSD_BinaryFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("GetInteger", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Integer &)) &FSD_BinaryFile::GetInteger, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator>>", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Integer &)) &FSD_BinaryFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def_static("GetInteger_", (void (*)(Standard_IStream &, Standard_Integer &)) &FSD_BinaryFile::GetInteger, "None", py::arg("theIStream"), py::arg("aValue"));
	cls_FSD_BinaryFile.def("GetBoolean", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Boolean &)) &FSD_BinaryFile::GetBoolean, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator>>", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Boolean &)) &FSD_BinaryFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("GetReal", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Real &)) &FSD_BinaryFile::GetReal, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator>>", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_Real &)) &FSD_BinaryFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("GetShortReal", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_ShortReal &)) &FSD_BinaryFile::GetShortReal, "None", py::arg("aValue"));
	cls_FSD_BinaryFile.def("operator>>", (Storage_BaseDriver & (FSD_BinaryFile::*)(Standard_ShortReal &)) &FSD_BinaryFile::operator>>, "None", py::arg("aValue"));
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
	cls_FSD_BinaryFile.def_static("WriteHeader_", [](Standard_OStream & a0, const FSD_FileHeader & a1) -> Standard_Integer { return FSD_BinaryFile::WriteHeader(a0, a1); }, py::arg("theOStream"), py::arg("theHeader"));
	cls_FSD_BinaryFile.def_static("WriteHeader_", (Standard_Integer (*)(Standard_OStream &, const FSD_FileHeader &, const Standard_Boolean)) &FSD_BinaryFile::WriteHeader, "None", py::arg("theOStream"), py::arg("theHeader"), py::arg("theOnlyCount"));
	cls_FSD_BinaryFile.def_static("MagicNumber_", (Standard_CString (*)()) &FSD_BinaryFile::MagicNumber, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FSD_CmpFile.hxx
	py::class_<FSD_CmpFile, std::unique_ptr<FSD_CmpFile, Deleter<FSD_CmpFile>>, Storage_BaseDriver> cls_FSD_CmpFile(mod, "FSD_CmpFile", "None");
	cls_FSD_CmpFile.def(py::init<>());
	cls_FSD_CmpFile.def("Open", (Storage_Error (FSD_CmpFile::*)(const TCollection_AsciiString &, const Storage_OpenMode)) &FSD_CmpFile::Open, "None", py::arg("aName"), py::arg("aMode"));
	cls_FSD_CmpFile.def("IsEnd", (Standard_Boolean (FSD_CmpFile::*)()) &FSD_CmpFile::IsEnd, "None");
	cls_FSD_CmpFile.def("Tell", (Storage_Position (FSD_CmpFile::*)()) &FSD_CmpFile::Tell, "return position in the file. Return -1 upon error.");
	cls_FSD_CmpFile.def_static("IsGoodFileType_", (Storage_Error (*)(const TCollection_AsciiString &)) &FSD_CmpFile::IsGoodFileType, "None", py::arg("aName"));
	cls_FSD_CmpFile.def("BeginWriteInfoSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWriteInfoSection, "None");
	cls_FSD_CmpFile.def("WriteInfo", (void (FSD_CmpFile::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TColStd_SequenceOfAsciiString &)) &FSD_CmpFile::WriteInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
	cls_FSD_CmpFile.def("EndWriteInfoSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndWriteInfoSection, "None");
	cls_FSD_CmpFile.def("BeginReadInfoSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadInfoSection, "None");
	cls_FSD_CmpFile.def("ReadInfo", (void (FSD_CmpFile::*)(Standard_Integer &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_ExtendedString &, TCollection_AsciiString &, TCollection_ExtendedString &, TColStd_SequenceOfAsciiString &)) &FSD_CmpFile::ReadInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
	cls_FSD_CmpFile.def("ReadCompleteInfo", (void (FSD_CmpFile::*)(Standard_IStream &, opencascade::handle<Storage_Data> &)) &FSD_CmpFile::ReadCompleteInfo, "None", py::arg("theIStream"), py::arg("theData"));
	cls_FSD_CmpFile.def("EndReadInfoSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadInfoSection, "None");
	cls_FSD_CmpFile.def("BeginWriteCommentSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWriteCommentSection, "None");
	cls_FSD_CmpFile.def("WriteComment", (void (FSD_CmpFile::*)(const TColStd_SequenceOfExtendedString &)) &FSD_CmpFile::WriteComment, "None", py::arg("userComments"));
	cls_FSD_CmpFile.def("EndWriteCommentSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndWriteCommentSection, "None");
	cls_FSD_CmpFile.def("BeginReadCommentSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadCommentSection, "None");
	cls_FSD_CmpFile.def("ReadComment", (void (FSD_CmpFile::*)(TColStd_SequenceOfExtendedString &)) &FSD_CmpFile::ReadComment, "None", py::arg("userComments"));
	cls_FSD_CmpFile.def("EndReadCommentSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadCommentSection, "None");
	cls_FSD_CmpFile.def("BeginWriteTypeSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWriteTypeSection, "None");
	cls_FSD_CmpFile.def("SetTypeSectionSize", (void (FSD_CmpFile::*)(const Standard_Integer)) &FSD_CmpFile::SetTypeSectionSize, "None", py::arg("aSize"));
	cls_FSD_CmpFile.def("WriteTypeInformations", (void (FSD_CmpFile::*)(const Standard_Integer, const TCollection_AsciiString &)) &FSD_CmpFile::WriteTypeInformations, "None", py::arg("typeNum"), py::arg("typeName"));
	cls_FSD_CmpFile.def("EndWriteTypeSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndWriteTypeSection, "None");
	cls_FSD_CmpFile.def("BeginReadTypeSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadTypeSection, "None");
	cls_FSD_CmpFile.def("TypeSectionSize", (Standard_Integer (FSD_CmpFile::*)()) &FSD_CmpFile::TypeSectionSize, "None");
	cls_FSD_CmpFile.def("ReadTypeInformations", (void (FSD_CmpFile::*)(Standard_Integer &, TCollection_AsciiString &)) &FSD_CmpFile::ReadTypeInformations, "None", py::arg("typeNum"), py::arg("typeName"));
	cls_FSD_CmpFile.def("EndReadTypeSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadTypeSection, "None");
	cls_FSD_CmpFile.def("BeginWriteRootSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWriteRootSection, "None");
	cls_FSD_CmpFile.def("SetRootSectionSize", (void (FSD_CmpFile::*)(const Standard_Integer)) &FSD_CmpFile::SetRootSectionSize, "None", py::arg("aSize"));
	cls_FSD_CmpFile.def("WriteRoot", (void (FSD_CmpFile::*)(const TCollection_AsciiString &, const Standard_Integer, const TCollection_AsciiString &)) &FSD_CmpFile::WriteRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
	cls_FSD_CmpFile.def("EndWriteRootSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndWriteRootSection, "None");
	cls_FSD_CmpFile.def("BeginReadRootSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadRootSection, "None");
	cls_FSD_CmpFile.def("RootSectionSize", (Standard_Integer (FSD_CmpFile::*)()) &FSD_CmpFile::RootSectionSize, "None");
	cls_FSD_CmpFile.def("ReadRoot", (void (FSD_CmpFile::*)(TCollection_AsciiString &, Standard_Integer &, TCollection_AsciiString &)) &FSD_CmpFile::ReadRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
	cls_FSD_CmpFile.def("EndReadRootSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadRootSection, "None");
	cls_FSD_CmpFile.def("BeginWriteRefSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWriteRefSection, "None");
	cls_FSD_CmpFile.def("SetRefSectionSize", (void (FSD_CmpFile::*)(const Standard_Integer)) &FSD_CmpFile::SetRefSectionSize, "None", py::arg("aSize"));
	cls_FSD_CmpFile.def("WriteReferenceType", (void (FSD_CmpFile::*)(const Standard_Integer, const Standard_Integer)) &FSD_CmpFile::WriteReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
	cls_FSD_CmpFile.def("EndWriteRefSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndWriteRefSection, "None");
	cls_FSD_CmpFile.def("BeginReadRefSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadRefSection, "None");
	cls_FSD_CmpFile.def("RefSectionSize", (Standard_Integer (FSD_CmpFile::*)()) &FSD_CmpFile::RefSectionSize, "None");
	cls_FSD_CmpFile.def("ReadReferenceType", (void (FSD_CmpFile::*)(Standard_Integer &, Standard_Integer &)) &FSD_CmpFile::ReadReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
	cls_FSD_CmpFile.def("EndReadRefSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadRefSection, "None");
	cls_FSD_CmpFile.def("BeginWriteDataSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWriteDataSection, "None");
	cls_FSD_CmpFile.def("WritePersistentObjectHeader", (void (FSD_CmpFile::*)(const Standard_Integer, const Standard_Integer)) &FSD_CmpFile::WritePersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
	cls_FSD_CmpFile.def("BeginWritePersistentObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWritePersistentObjectData, "None");
	cls_FSD_CmpFile.def("BeginWriteObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWriteObjectData, "None");
	cls_FSD_CmpFile.def("EndWriteObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::EndWriteObjectData, "None");
	cls_FSD_CmpFile.def("EndWritePersistentObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::EndWritePersistentObjectData, "None");
	cls_FSD_CmpFile.def("EndWriteDataSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndWriteDataSection, "None");
	cls_FSD_CmpFile.def("BeginReadDataSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadDataSection, "None");
	cls_FSD_CmpFile.def("ReadPersistentObjectHeader", (void (FSD_CmpFile::*)(Standard_Integer &, Standard_Integer &)) &FSD_CmpFile::ReadPersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
	cls_FSD_CmpFile.def("BeginReadPersistentObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadPersistentObjectData, "None");
	cls_FSD_CmpFile.def("BeginReadObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadObjectData, "None");
	cls_FSD_CmpFile.def("EndReadObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadObjectData, "None");
	cls_FSD_CmpFile.def("EndReadPersistentObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadPersistentObjectData, "None");
	cls_FSD_CmpFile.def("EndReadDataSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadDataSection, "None");
	cls_FSD_CmpFile.def("SkipObject", (void (FSD_CmpFile::*)()) &FSD_CmpFile::SkipObject, "None");
	cls_FSD_CmpFile.def("PutReference", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_Integer)) &FSD_CmpFile::PutReference, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("PutCharacter", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_Character)) &FSD_CmpFile::PutCharacter, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator<<", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_Character)) &FSD_CmpFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("PutExtCharacter", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_ExtCharacter)) &FSD_CmpFile::PutExtCharacter, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator<<", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_ExtCharacter)) &FSD_CmpFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("PutInteger", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_Integer)) &FSD_CmpFile::PutInteger, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator<<", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_Integer)) &FSD_CmpFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("PutBoolean", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_Boolean)) &FSD_CmpFile::PutBoolean, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator<<", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_Boolean)) &FSD_CmpFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("PutReal", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_Real)) &FSD_CmpFile::PutReal, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator<<", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_Real)) &FSD_CmpFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("PutShortReal", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_ShortReal)) &FSD_CmpFile::PutShortReal, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator<<", (Storage_BaseDriver & (FSD_CmpFile::*)(const Standard_ShortReal)) &FSD_CmpFile::operator<<, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("GetReference", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_Integer &)) &FSD_CmpFile::GetReference, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("GetCharacter", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_Character &)) &FSD_CmpFile::GetCharacter, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator>>", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_Character &)) &FSD_CmpFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("GetExtCharacter", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_ExtCharacter &)) &FSD_CmpFile::GetExtCharacter, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator>>", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_ExtCharacter &)) &FSD_CmpFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("GetInteger", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_Integer &)) &FSD_CmpFile::GetInteger, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator>>", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_Integer &)) &FSD_CmpFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("GetBoolean", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_Boolean &)) &FSD_CmpFile::GetBoolean, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator>>", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_Boolean &)) &FSD_CmpFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("GetReal", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_Real &)) &FSD_CmpFile::GetReal, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator>>", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_Real &)) &FSD_CmpFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("GetShortReal", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_ShortReal &)) &FSD_CmpFile::GetShortReal, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("operator>>", (Storage_BaseDriver & (FSD_CmpFile::*)(Standard_ShortReal &)) &FSD_CmpFile::operator>>, "None", py::arg("aValue"));
	cls_FSD_CmpFile.def("Close", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::Close, "None");
	cls_FSD_CmpFile.def("Destroy", (void (FSD_CmpFile::*)()) &FSD_CmpFile::Destroy, "None");
	cls_FSD_CmpFile.def_static("MagicNumber_", (Standard_CString (*)()) &FSD_CmpFile::MagicNumber, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FSD_File.hxx
	py::class_<FSD_File, std::unique_ptr<FSD_File, Deleter<FSD_File>>, Storage_BaseDriver> cls_FSD_File(mod, "FSD_File", "A general driver which defines as a file, the physical container for data to be stored or retrieved.");
	cls_FSD_File.def(py::init<>());
	cls_FSD_File.def("Open", (Storage_Error (FSD_File::*)(const TCollection_AsciiString &, const Storage_OpenMode)) &FSD_File::Open, "Assigns as aName the name of the file to be driven by this driver. aMode precises if the file is opened in read or write mode. The function returns Storage_VSOk if the file is opened correctly, or any other value of the Storage_Error enumeration which specifies the problem encountered.", py::arg("aName"), py::arg("aMode"));
	cls_FSD_File.def("IsEnd", (Standard_Boolean (FSD_File::*)()) &FSD_File::IsEnd, "None");
	cls_FSD_File.def("Tell", (Storage_Position (FSD_File::*)()) &FSD_File::Tell, "return position in the file. Return -1 upon error.");
	cls_FSD_File.def_static("IsGoodFileType_", (Storage_Error (*)(const TCollection_AsciiString &)) &FSD_File::IsGoodFileType, "None", py::arg("aName"));
	cls_FSD_File.def("BeginWriteInfoSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteInfoSection, "None");
	cls_FSD_File.def("WriteInfo", (void (FSD_File::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const TCollection_ExtendedString &, const TColStd_SequenceOfAsciiString &)) &FSD_File::WriteInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
	cls_FSD_File.def("EndWriteInfoSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteInfoSection, "None");
	cls_FSD_File.def("BeginReadInfoSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadInfoSection, "None");
	cls_FSD_File.def("ReadInfo", (void (FSD_File::*)(Standard_Integer &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_ExtendedString &, TCollection_AsciiString &, TCollection_ExtendedString &, TColStd_SequenceOfAsciiString &)) &FSD_File::ReadInfo, "None", py::arg("nbObj"), py::arg("dbVersion"), py::arg("date"), py::arg("schemaName"), py::arg("schemaVersion"), py::arg("appName"), py::arg("appVersion"), py::arg("objectType"), py::arg("userInfo"));
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
	cls_FSD_File.def("ReadTypeInformations", (void (FSD_File::*)(Standard_Integer &, TCollection_AsciiString &)) &FSD_File::ReadTypeInformations, "None", py::arg("typeNum"), py::arg("typeName"));
	cls_FSD_File.def("EndReadTypeSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadTypeSection, "None");
	cls_FSD_File.def("BeginWriteRootSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteRootSection, "None");
	cls_FSD_File.def("SetRootSectionSize", (void (FSD_File::*)(const Standard_Integer)) &FSD_File::SetRootSectionSize, "None", py::arg("aSize"));
	cls_FSD_File.def("WriteRoot", (void (FSD_File::*)(const TCollection_AsciiString &, const Standard_Integer, const TCollection_AsciiString &)) &FSD_File::WriteRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
	cls_FSD_File.def("EndWriteRootSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteRootSection, "None");
	cls_FSD_File.def("BeginReadRootSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadRootSection, "None");
	cls_FSD_File.def("RootSectionSize", (Standard_Integer (FSD_File::*)()) &FSD_File::RootSectionSize, "None");
	cls_FSD_File.def("ReadRoot", (void (FSD_File::*)(TCollection_AsciiString &, Standard_Integer &, TCollection_AsciiString &)) &FSD_File::ReadRoot, "None", py::arg("rootName"), py::arg("aRef"), py::arg("aType"));
	cls_FSD_File.def("EndReadRootSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadRootSection, "None");
	cls_FSD_File.def("BeginWriteRefSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteRefSection, "None");
	cls_FSD_File.def("SetRefSectionSize", (void (FSD_File::*)(const Standard_Integer)) &FSD_File::SetRefSectionSize, "None", py::arg("aSize"));
	cls_FSD_File.def("WriteReferenceType", (void (FSD_File::*)(const Standard_Integer, const Standard_Integer)) &FSD_File::WriteReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
	cls_FSD_File.def("EndWriteRefSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteRefSection, "None");
	cls_FSD_File.def("BeginReadRefSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadRefSection, "None");
	cls_FSD_File.def("RefSectionSize", (Standard_Integer (FSD_File::*)()) &FSD_File::RefSectionSize, "None");
	cls_FSD_File.def("ReadReferenceType", (void (FSD_File::*)(Standard_Integer &, Standard_Integer &)) &FSD_File::ReadReferenceType, "None", py::arg("reference"), py::arg("typeNum"));
	cls_FSD_File.def("EndReadRefSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadRefSection, "None");
	cls_FSD_File.def("BeginWriteDataSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginWriteDataSection, "None");
	cls_FSD_File.def("WritePersistentObjectHeader", (void (FSD_File::*)(const Standard_Integer, const Standard_Integer)) &FSD_File::WritePersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
	cls_FSD_File.def("BeginWritePersistentObjectData", (void (FSD_File::*)()) &FSD_File::BeginWritePersistentObjectData, "None");
	cls_FSD_File.def("BeginWriteObjectData", (void (FSD_File::*)()) &FSD_File::BeginWriteObjectData, "None");
	cls_FSD_File.def("EndWriteObjectData", (void (FSD_File::*)()) &FSD_File::EndWriteObjectData, "None");
	cls_FSD_File.def("EndWritePersistentObjectData", (void (FSD_File::*)()) &FSD_File::EndWritePersistentObjectData, "None");
	cls_FSD_File.def("EndWriteDataSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndWriteDataSection, "None");
	cls_FSD_File.def("BeginReadDataSection", (Storage_Error (FSD_File::*)()) &FSD_File::BeginReadDataSection, "None");
	cls_FSD_File.def("ReadPersistentObjectHeader", (void (FSD_File::*)(Standard_Integer &, Standard_Integer &)) &FSD_File::ReadPersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
	cls_FSD_File.def("BeginReadPersistentObjectData", (void (FSD_File::*)()) &FSD_File::BeginReadPersistentObjectData, "None");
	cls_FSD_File.def("BeginReadObjectData", (void (FSD_File::*)()) &FSD_File::BeginReadObjectData, "None");
	cls_FSD_File.def("EndReadObjectData", (void (FSD_File::*)()) &FSD_File::EndReadObjectData, "None");
	cls_FSD_File.def("EndReadPersistentObjectData", (void (FSD_File::*)()) &FSD_File::EndReadPersistentObjectData, "None");
	cls_FSD_File.def("EndReadDataSection", (Storage_Error (FSD_File::*)()) &FSD_File::EndReadDataSection, "None");
	cls_FSD_File.def("SkipObject", (void (FSD_File::*)()) &FSD_File::SkipObject, "None");
	cls_FSD_File.def("PutReference", (Storage_BaseDriver & (FSD_File::*)(const Standard_Integer)) &FSD_File::PutReference, "None", py::arg("aValue"));
	cls_FSD_File.def("PutCharacter", (Storage_BaseDriver & (FSD_File::*)(const Standard_Character)) &FSD_File::PutCharacter, "None", py::arg("aValue"));
	cls_FSD_File.def("operator<<", (Storage_BaseDriver & (FSD_File::*)(const Standard_Character)) &FSD_File::operator<<, "None", py::arg("aValue"));
	cls_FSD_File.def("PutExtCharacter", (Storage_BaseDriver & (FSD_File::*)(const Standard_ExtCharacter)) &FSD_File::PutExtCharacter, "None", py::arg("aValue"));
	cls_FSD_File.def("operator<<", (Storage_BaseDriver & (FSD_File::*)(const Standard_ExtCharacter)) &FSD_File::operator<<, "None", py::arg("aValue"));
	cls_FSD_File.def("PutInteger", (Storage_BaseDriver & (FSD_File::*)(const Standard_Integer)) &FSD_File::PutInteger, "None", py::arg("aValue"));
	cls_FSD_File.def("operator<<", (Storage_BaseDriver & (FSD_File::*)(const Standard_Integer)) &FSD_File::operator<<, "None", py::arg("aValue"));
	cls_FSD_File.def("PutBoolean", (Storage_BaseDriver & (FSD_File::*)(const Standard_Boolean)) &FSD_File::PutBoolean, "None", py::arg("aValue"));
	cls_FSD_File.def("operator<<", (Storage_BaseDriver & (FSD_File::*)(const Standard_Boolean)) &FSD_File::operator<<, "None", py::arg("aValue"));
	cls_FSD_File.def("PutReal", (Storage_BaseDriver & (FSD_File::*)(const Standard_Real)) &FSD_File::PutReal, "None", py::arg("aValue"));
	cls_FSD_File.def("operator<<", (Storage_BaseDriver & (FSD_File::*)(const Standard_Real)) &FSD_File::operator<<, "None", py::arg("aValue"));
	cls_FSD_File.def("PutShortReal", (Storage_BaseDriver & (FSD_File::*)(const Standard_ShortReal)) &FSD_File::PutShortReal, "None", py::arg("aValue"));
	cls_FSD_File.def("operator<<", (Storage_BaseDriver & (FSD_File::*)(const Standard_ShortReal)) &FSD_File::operator<<, "None", py::arg("aValue"));
	cls_FSD_File.def("GetReference", (Storage_BaseDriver & (FSD_File::*)(Standard_Integer &)) &FSD_File::GetReference, "None", py::arg("aValue"));
	cls_FSD_File.def("GetCharacter", (Storage_BaseDriver & (FSD_File::*)(Standard_Character &)) &FSD_File::GetCharacter, "None", py::arg("aValue"));
	cls_FSD_File.def("operator>>", (Storage_BaseDriver & (FSD_File::*)(Standard_Character &)) &FSD_File::operator>>, "None", py::arg("aValue"));
	cls_FSD_File.def("GetExtCharacter", (Storage_BaseDriver & (FSD_File::*)(Standard_ExtCharacter &)) &FSD_File::GetExtCharacter, "None", py::arg("aValue"));
	cls_FSD_File.def("operator>>", (Storage_BaseDriver & (FSD_File::*)(Standard_ExtCharacter &)) &FSD_File::operator>>, "None", py::arg("aValue"));
	cls_FSD_File.def("GetInteger", (Storage_BaseDriver & (FSD_File::*)(Standard_Integer &)) &FSD_File::GetInteger, "None", py::arg("aValue"));
	cls_FSD_File.def("operator>>", (Storage_BaseDriver & (FSD_File::*)(Standard_Integer &)) &FSD_File::operator>>, "None", py::arg("aValue"));
	cls_FSD_File.def("GetBoolean", (Storage_BaseDriver & (FSD_File::*)(Standard_Boolean &)) &FSD_File::GetBoolean, "None", py::arg("aValue"));
	cls_FSD_File.def("operator>>", (Storage_BaseDriver & (FSD_File::*)(Standard_Boolean &)) &FSD_File::operator>>, "None", py::arg("aValue"));
	cls_FSD_File.def("GetReal", (Storage_BaseDriver & (FSD_File::*)(Standard_Real &)) &FSD_File::GetReal, "None", py::arg("aValue"));
	cls_FSD_File.def("operator>>", (Storage_BaseDriver & (FSD_File::*)(Standard_Real &)) &FSD_File::operator>>, "None", py::arg("aValue"));
	cls_FSD_File.def("GetShortReal", (Storage_BaseDriver & (FSD_File::*)(Standard_ShortReal &)) &FSD_File::GetShortReal, "None", py::arg("aValue"));
	cls_FSD_File.def("operator>>", (Storage_BaseDriver & (FSD_File::*)(Standard_ShortReal &)) &FSD_File::operator>>, "None", py::arg("aValue"));
	cls_FSD_File.def("Close", (Storage_Error (FSD_File::*)()) &FSD_File::Close, "Closes the file driven by this driver. This file was opened by the last call to the function Open. The function returns Storage_VSOk if the closure is correctly done, or any other value of the Storage_Error enumeration which specifies the problem encountered.");
	cls_FSD_File.def("Destroy", (void (FSD_File::*)()) &FSD_File::Destroy, "None");
	cls_FSD_File.def_static("MagicNumber_", (Standard_CString (*)()) &FSD_File::MagicNumber, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FSD_BStream.hxx
	// C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\fstream
	py::class_<FSD_FStream, std::unique_ptr<FSD_FStream, Deleter<FSD_FStream>>, basic_iostream<char, char_traits<char>>> cls_FSD_FStream(mod, "FSD_FStream", "None");
	cls_FSD_FStream.def(py::init<>());
	cls_FSD_FStream.def(py::init<const char *>(), py::arg("_Filename"));
	cls_FSD_FStream.def(py::init<const char *, ios_base::openmode>(), py::arg("_Filename"), py::arg("_Mode"));
	cls_FSD_FStream.def(py::init<const char *, ios_base::openmode, int>(), py::arg("_Filename"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def(py::init<const std::string &>(), py::arg("_Str"));
	cls_FSD_FStream.def(py::init<const std::string &, ios_base::openmode>(), py::arg("_Str"), py::arg("_Mode"));
	cls_FSD_FStream.def(py::init<const std::string &, ios_base::openmode, int>(), py::arg("_Str"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def(py::init<const wchar_t *>(), py::arg("_Filename"));
	cls_FSD_FStream.def(py::init<const wchar_t *, ios_base::openmode>(), py::arg("_Filename"), py::arg("_Mode"));
	cls_FSD_FStream.def(py::init<const wchar_t *, ios_base::openmode, int>(), py::arg("_Filename"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def(py::init<const std::wstring &>(), py::arg("_Str"));
	cls_FSD_FStream.def(py::init<const std::wstring &, ios_base::openmode>(), py::arg("_Str"), py::arg("_Mode"));
	cls_FSD_FStream.def(py::init<const std::wstring &, ios_base::openmode, int>(), py::arg("_Str"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def(py::init<const unsigned short *>(), py::arg("_Filename"));
	cls_FSD_FStream.def(py::init<const unsigned short *, ios_base::openmode>(), py::arg("_Filename"), py::arg("_Mode"));
	cls_FSD_FStream.def(py::init<const unsigned short *, ios_base::openmode, int>(), py::arg("_Filename"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def(py::init<FILE *>(), py::arg("_File"));
	// FIXME cls_FSD_FStream.def(py::init<std::FSD_FStream::_Myt &&>(), py::arg("_Right"));
	cls_FSD_FStream.def(py::init([] (const std::FSD_FStream::_Myt &other) {return new FSD_FStream(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_FSD_FStream.def("assign", (std::FSD_FStream::_Myt & (FSD_FStream::*)(std::FSD_FStream::_Myt &&)) &FSD_FStream::operator=, py::is_operator(), "None", py::arg("_Right"));
	// FIXME cls_FSD_FStream.def("_Assign_rv", (void (FSD_FStream::*)(std::FSD_FStream::_Myt &&)) &FSD_FStream::_Assign_rv, "None", py::arg("_Right"));
	cls_FSD_FStream.def("swap", (void (FSD_FStream::*)(std::FSD_FStream::_Myt &)) &FSD_FStream::swap, "None", py::arg("_Right"));
	cls_FSD_FStream.def("assign", (std::FSD_FStream::_Myt & (FSD_FStream::*)(const std::FSD_FStream::_Myt &)) &FSD_FStream::operator=, py::is_operator(), "None", py::arg(""));
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const wchar_t * a0) -> void { return self.open(a0); }, py::arg("_Filename"));
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const wchar_t * a0, ios_base::openmode a1) -> void { return self.open(a0, a1); }, py::arg("_Filename"), py::arg("_Mode"));
	cls_FSD_FStream.def("open", (void (FSD_FStream::*)(const wchar_t *, ios_base::openmode, int)) &FSD_FStream::open, "None", py::arg("_Filename"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const std::wstring & a0) -> void { return self.open(a0); }, py::arg("_Str"));
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const std::wstring & a0, ios_base::openmode a1) -> void { return self.open(a0, a1); }, py::arg("_Str"), py::arg("_Mode"));
	cls_FSD_FStream.def("open", (void (FSD_FStream::*)(const std::wstring &, ios_base::openmode, int)) &FSD_FStream::open, "None", py::arg("_Str"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def("open", (void (FSD_FStream::*)(const wchar_t *, ios_base::open_mode)) &FSD_FStream::open, "None", py::arg("_Filename"), py::arg("_Mode"));
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const unsigned short * a0) -> void { return self.open(a0); }, py::arg("_Filename"));
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const unsigned short * a0, ios_base::openmode a1) -> void { return self.open(a0, a1); }, py::arg("_Filename"), py::arg("_Mode"));
	cls_FSD_FStream.def("open", (void (FSD_FStream::*)(const unsigned short *, ios_base::openmode, int)) &FSD_FStream::open, "None", py::arg("_Filename"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def("open", (void (FSD_FStream::*)(const unsigned short *, ios_base::open_mode)) &FSD_FStream::open, "None", py::arg("_Filename"), py::arg("_Mode"));
	cls_FSD_FStream.def("rdbuf", (std::FSD_FStream::_Myfb * (FSD_FStream::*)() const ) &FSD_FStream::rdbuf, "None");
	cls_FSD_FStream.def("is_open", (bool (FSD_FStream::*)() const ) &FSD_FStream::is_open, "None");
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const char * a0) -> void { return self.open(a0); }, py::arg("_Filename"));
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const char * a0, ios_base::openmode a1) -> void { return self.open(a0, a1); }, py::arg("_Filename"), py::arg("_Mode"));
	cls_FSD_FStream.def("open", (void (FSD_FStream::*)(const char *, ios_base::openmode, int)) &FSD_FStream::open, "None", py::arg("_Filename"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const std::string & a0) -> void { return self.open(a0); }, py::arg("_Str"));
	cls_FSD_FStream.def("open", [](FSD_FStream &self, const std::string & a0, ios_base::openmode a1) -> void { return self.open(a0, a1); }, py::arg("_Str"), py::arg("_Mode"));
	cls_FSD_FStream.def("open", (void (FSD_FStream::*)(const std::string &, ios_base::openmode, int)) &FSD_FStream::open, "None", py::arg("_Str"), py::arg("_Mode"), py::arg("_Prot"));
	cls_FSD_FStream.def("open", (void (FSD_FStream::*)(const char *, ios_base::open_mode)) &FSD_FStream::open, "None", py::arg("_Filename"), py::arg("_Mode"));
	cls_FSD_FStream.def("close", (void (FSD_FStream::*)()) &FSD_FStream::close, "None");


}
