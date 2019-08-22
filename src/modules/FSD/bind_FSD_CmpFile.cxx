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
#include <FSD_File.hxx>
#include <Standard.hxx>
#include <Storage_Error.hxx>
#include <TCollection_AsciiString.hxx>
#include <Storage_OpenMode.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <FSD_CmpFile.hxx>

void bind_FSD_CmpFile(py::module &mod){

py::class_<FSD_CmpFile, FSD_File> cls_FSD_CmpFile(mod, "FSD_CmpFile", "None");

// Constructors
cls_FSD_CmpFile.def(py::init<>());

// Fields

// Methods
// cls_FSD_CmpFile.def_static("operator new_", (void * (*)(size_t)) &FSD_CmpFile::operator new, "None", py::arg("theSize"));
// cls_FSD_CmpFile.def_static("operator delete_", (void (*)(void *)) &FSD_CmpFile::operator delete, "None", py::arg("theAddress"));
// cls_FSD_CmpFile.def_static("operator new[]_", (void * (*)(size_t)) &FSD_CmpFile::operator new[], "None", py::arg("theSize"));
// cls_FSD_CmpFile.def_static("operator delete[]_", (void (*)(void *)) &FSD_CmpFile::operator delete[], "None", py::arg("theAddress"));
// cls_FSD_CmpFile.def_static("operator new_", (void * (*)(size_t, void *)) &FSD_CmpFile::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FSD_CmpFile.def_static("operator delete_", (void (*)(void *, void *)) &FSD_CmpFile::operator delete, "None", py::arg(""), py::arg(""));
cls_FSD_CmpFile.def("Open", (Storage_Error (FSD_CmpFile::*)(const TCollection_AsciiString &, const Storage_OpenMode)) &FSD_CmpFile::Open, "None", py::arg("aName"), py::arg("aMode"));
cls_FSD_CmpFile.def_static("IsGoodFileType_", (Storage_Error (*)(const TCollection_AsciiString &)) &FSD_CmpFile::IsGoodFileType, "None", py::arg("aName"));
cls_FSD_CmpFile.def("BeginWriteInfoSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWriteInfoSection, "None");
cls_FSD_CmpFile.def("BeginReadInfoSection", (Storage_Error (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadInfoSection, "None");
cls_FSD_CmpFile.def("WritePersistentObjectHeader", (void (FSD_CmpFile::*)(const Standard_Integer, const Standard_Integer)) &FSD_CmpFile::WritePersistentObjectHeader, "None", py::arg("aRef"), py::arg("aType"));
cls_FSD_CmpFile.def("BeginWritePersistentObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWritePersistentObjectData, "None");
cls_FSD_CmpFile.def("BeginWriteObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::BeginWriteObjectData, "None");
cls_FSD_CmpFile.def("EndWriteObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::EndWriteObjectData, "None");
cls_FSD_CmpFile.def("EndWritePersistentObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::EndWritePersistentObjectData, "None");
cls_FSD_CmpFile.def("ReadPersistentObjectHeader", [](FSD_CmpFile &self, Standard_Integer & aRef, Standard_Integer & aType){ self.ReadPersistentObjectHeader(aRef, aType); return std::tuple<Standard_Integer &, Standard_Integer &>(aRef, aType); }, "None", py::arg("aRef"), py::arg("aType"));
cls_FSD_CmpFile.def("BeginReadPersistentObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadPersistentObjectData, "None");
cls_FSD_CmpFile.def("BeginReadObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::BeginReadObjectData, "None");
cls_FSD_CmpFile.def("EndReadObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadObjectData, "None");
cls_FSD_CmpFile.def("EndReadPersistentObjectData", (void (FSD_CmpFile::*)()) &FSD_CmpFile::EndReadPersistentObjectData, "None");
cls_FSD_CmpFile.def("Destroy", (void (FSD_CmpFile::*)()) &FSD_CmpFile::Destroy, "None");
cls_FSD_CmpFile.def_static("MagicNumber_", (Standard_CString (*)()) &FSD_CmpFile::MagicNumber, "None");

// Enums

}