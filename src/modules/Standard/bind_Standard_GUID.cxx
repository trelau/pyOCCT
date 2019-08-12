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
#include <Standard_TypeDef.hxx>
#include <Standard_UUID.hxx>
#include <Standard_GUID.hxx>
#include <Standard_PCharacter.hxx>
#include <Standard_PExtCharacter.hxx>
#include <Standard_OStream.hxx>

void bind_Standard_GUID(py::module &mod){

py::class_<Standard_GUID, std::unique_ptr<Standard_GUID, Deleter<Standard_GUID>>> cls_Standard_GUID(mod, "Standard_GUID", "None");

// Constructors
cls_Standard_GUID.def(py::init<>());
cls_Standard_GUID.def(py::init<const Standard_CString>(), py::arg("aGuid"));
cls_Standard_GUID.def(py::init<const Standard_ExtString>(), py::arg("aGuid"));
cls_Standard_GUID.def(py::init<const Standard_Integer, const Standard_ExtCharacter, const Standard_ExtCharacter, const Standard_ExtCharacter, const Standard_Byte, const Standard_Byte, const Standard_Byte, const Standard_Byte, const Standard_Byte, const Standard_Byte>(), py::arg("a32b"), py::arg("a16b1"), py::arg("a16b2"), py::arg("a16b3"), py::arg("a8b1"), py::arg("a8b2"), py::arg("a8b3"), py::arg("a8b4"), py::arg("a8b5"), py::arg("a8b6"));
cls_Standard_GUID.def(py::init<const Standard_UUID &>(), py::arg("aGuid"));
cls_Standard_GUID.def(py::init<const Standard_GUID &>(), py::arg("aGuid"));

// Fields

// Methods
// cls_Standard_GUID.def_static("operator new_", (void * (*)(size_t)) &Standard_GUID::operator new, "None", py::arg("theSize"));
// cls_Standard_GUID.def_static("operator delete_", (void (*)(void *)) &Standard_GUID::operator delete, "None", py::arg("theAddress"));
// cls_Standard_GUID.def_static("operator new[]_", (void * (*)(size_t)) &Standard_GUID::operator new[], "None", py::arg("theSize"));
// cls_Standard_GUID.def_static("operator delete[]_", (void (*)(void *)) &Standard_GUID::operator delete[], "None", py::arg("theAddress"));
// cls_Standard_GUID.def_static("operator new_", (void * (*)(size_t, void *)) &Standard_GUID::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Standard_GUID.def_static("operator delete_", (void (*)(void *, void *)) &Standard_GUID::operator delete, "None", py::arg(""), py::arg(""));
cls_Standard_GUID.def("ToUUID", (Standard_UUID (Standard_GUID::*)() const) &Standard_GUID::ToUUID, "None");
cls_Standard_GUID.def("ToCString", (void (Standard_GUID::*)(const Standard_PCharacter) const) &Standard_GUID::ToCString, "translate the GUID into ascii string the aStrGuid is allocated by user. the guid have the following format:", py::arg("aStrGuid"));
cls_Standard_GUID.def("ToExtString", (void (Standard_GUID::*)(const Standard_PExtCharacter) const) &Standard_GUID::ToExtString, "translate the GUID into unicode string the aStrGuid is allocated by user. the guid have the following format:", py::arg("aStrGuid"));
cls_Standard_GUID.def("IsSame", (Standard_Boolean (Standard_GUID::*)(const Standard_GUID &) const) &Standard_GUID::IsSame, "None", py::arg("uid"));
cls_Standard_GUID.def("__eq__", (Standard_Boolean (Standard_GUID::*)(const Standard_GUID &) const) &Standard_GUID::operator==, py::is_operator(), "None", py::arg("uid"));
cls_Standard_GUID.def("IsNotSame", (Standard_Boolean (Standard_GUID::*)(const Standard_GUID &) const) &Standard_GUID::IsNotSame, "None", py::arg("uid"));
cls_Standard_GUID.def("__ne__", (Standard_Boolean (Standard_GUID::*)(const Standard_GUID &) const) &Standard_GUID::operator!=, py::is_operator(), "None", py::arg("uid"));
cls_Standard_GUID.def("Assign", (void (Standard_GUID::*)(const Standard_GUID &)) &Standard_GUID::Assign, "None", py::arg("uid"));
// cls_Standard_GUID.def("operator=", (void (Standard_GUID::*)(const Standard_GUID &)) &Standard_GUID::operator=, "None", py::arg("uid"));
cls_Standard_GUID.def("Assign", (void (Standard_GUID::*)(const Standard_UUID &)) &Standard_GUID::Assign, "None", py::arg("uid"));
// cls_Standard_GUID.def("operator=", (void (Standard_GUID::*)(const Standard_UUID &)) &Standard_GUID::operator=, "None", py::arg("uid"));
cls_Standard_GUID.def("ShallowDump", (void (Standard_GUID::*)(Standard_OStream &) const) &Standard_GUID::ShallowDump, "Display the GUID with the following format:", py::arg("aStream"));
cls_Standard_GUID.def_static("CheckGUIDFormat_", (Standard_Boolean (*)(const Standard_CString)) &Standard_GUID::CheckGUIDFormat, "Check the format of a GUID string. It checks the size, the position of the '-' and the correct size of fields.", py::arg("aGuid"));
cls_Standard_GUID.def("Hash", (Standard_Integer (Standard_GUID::*)(const Standard_Integer) const) &Standard_GUID::Hash, "Hash function for GUID.", py::arg("Upper"));
cls_Standard_GUID.def_static("HashCode_", (Standard_Integer (*)(const Standard_GUID &, const Standard_Integer)) &Standard_GUID::HashCode, "H method used by collections.", py::arg("aguid"), py::arg("Upper"));
cls_Standard_GUID.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_GUID &, const Standard_GUID &)) &Standard_GUID::IsEqual, "Returns True when the two GUID are the same.", py::arg("string1"), py::arg("string2"));

// Enums

}