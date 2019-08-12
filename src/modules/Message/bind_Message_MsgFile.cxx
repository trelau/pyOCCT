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
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Message_MsgFile.hxx>

void bind_Message_MsgFile(py::module &mod){

py::class_<Message_MsgFile, std::unique_ptr<Message_MsgFile, Deleter<Message_MsgFile>>> cls_Message_MsgFile(mod, "Message_MsgFile", "A tool providing facility to load definitions of message strings from resource file(s).");

// Constructors

// Fields

// Methods
// cls_Message_MsgFile.def_static("operator new_", (void * (*)(size_t)) &Message_MsgFile::operator new, "None", py::arg("theSize"));
// cls_Message_MsgFile.def_static("operator delete_", (void (*)(void *)) &Message_MsgFile::operator delete, "None", py::arg("theAddress"));
// cls_Message_MsgFile.def_static("operator new[]_", (void * (*)(size_t)) &Message_MsgFile::operator new[], "None", py::arg("theSize"));
// cls_Message_MsgFile.def_static("operator delete[]_", (void (*)(void *)) &Message_MsgFile::operator delete[], "None", py::arg("theAddress"));
// cls_Message_MsgFile.def_static("operator new_", (void * (*)(size_t, void *)) &Message_MsgFile::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Message_MsgFile.def_static("operator delete_", (void (*)(void *, void *)) &Message_MsgFile::operator delete, "None", py::arg(""), py::arg(""));
cls_Message_MsgFile.def_static("Load_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString)) &Message_MsgFile::Load, "Load message file <theFileName> from directory <theDirName> or its sub-directory", py::arg("theDirName"), py::arg("theFileName"));
cls_Message_MsgFile.def_static("LoadFile_", (Standard_Boolean (*)(const Standard_CString)) &Message_MsgFile::LoadFile, "Load the messages from the given file, additive to any previously loaded messages. Messages with same keywords, if already present, are replaced with the new ones.", py::arg("theFName"));
cls_Message_MsgFile.def_static("LoadFromEnv_", [](const Standard_CString a0, const Standard_CString a1) -> Standard_Boolean { return Message_MsgFile::LoadFromEnv(a0, a1); });
cls_Message_MsgFile.def_static("LoadFromEnv_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString, const Standard_CString)) &Message_MsgFile::LoadFromEnv, "Loads the messages from the file with name (without extension) given by environment variable. Extension of the file name is given separately. If its not defined, it is taken: - by default from environment CSF_LANGUAGE, - if not defined either, as 'us'.", py::arg("theEnvName"), py::arg("theFileName"), py::arg("theLangExt"));
cls_Message_MsgFile.def_static("LoadFromString_", [](const Standard_CString a0) -> Standard_Boolean { return Message_MsgFile::LoadFromString(a0); });
cls_Message_MsgFile.def_static("LoadFromString_", (Standard_Boolean (*)(const Standard_CString, const Standard_Integer)) &Message_MsgFile::LoadFromString, "Loads the messages from the given text buffer.", py::arg("theContent"), py::arg("theLength"));
cls_Message_MsgFile.def_static("AddMsg_", (Standard_Boolean (*)(const TCollection_AsciiString &, const TCollection_ExtendedString &)) &Message_MsgFile::AddMsg, "Adds new message to the map. Parameter <key> gives the key of the message, <text> defines the message itself. If there already was defined the message identified by the same keyword, it is replaced with the new one.", py::arg("key"), py::arg("text"));
cls_Message_MsgFile.def_static("HasMsg_", (Standard_Boolean (*)(const TCollection_AsciiString &)) &Message_MsgFile::HasMsg, "Returns True if message with specified keyword is registered", py::arg("key"));
cls_Message_MsgFile.def_static("Msg_", (const TCollection_ExtendedString & (*)(const Standard_CString)) &Message_MsgFile::Msg, "None", py::arg("key"));
cls_Message_MsgFile.def_static("Msg_", (const TCollection_ExtendedString & (*)(const TCollection_AsciiString &)) &Message_MsgFile::Msg, "Gives the text for the message identified by the keyword <key> If there are no messages with such keyword defined, the error message is returned. In that case reference to static string is returned, it can be chenged with next call(s) to Msg(). Note: The error message is constructed like 'Unknown message: <key>', and can itself be customized by defining message with key Message_Msg_BadKeyword.", py::arg("key"));

// Enums

}