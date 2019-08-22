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
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_Msg.hxx>
#include <Message_MsgFile.hxx>
#include <Message_Algorithm.hxx>
#include <Message_Printer.hxx>
#include <Message_PrinterOStream.hxx>
#include <Message_ProgressIndicator.hxx>
#include <Message_ProgressScale.hxx>
#include <Message_ProgressSentry.hxx>
#include <Message.hxx>

void bind_Message(py::module &mod){

py::class_<Message> cls_Message(mod, "Message", "Defines - tools to work with messages - basic tools intended for progress indication");

// Constructors

// Fields

// Methods
// cls_Message.def_static("operator new_", (void * (*)(size_t)) &Message::operator new, "None", py::arg("theSize"));
// cls_Message.def_static("operator delete_", (void (*)(void *)) &Message::operator delete, "None", py::arg("theAddress"));
// cls_Message.def_static("operator new[]_", (void * (*)(size_t)) &Message::operator new[], "None", py::arg("theSize"));
// cls_Message.def_static("operator delete[]_", (void (*)(void *)) &Message::operator delete[], "None", py::arg("theAddress"));
// cls_Message.def_static("operator new_", (void * (*)(size_t, void *)) &Message::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Message.def_static("operator delete_", (void (*)(void *, void *)) &Message::operator delete, "None", py::arg(""), py::arg(""));
cls_Message.def_static("DefaultMessenger_", (const opencascade::handle<Message_Messenger> & (*)()) &Message::DefaultMessenger, "Defines default messenger for OCCT applications. This is global static instance of the messenger. By default, it contains single printer directed to cout. It can be customized according to the application needs.");
cls_Message.def_static("FillTime_", (TCollection_AsciiString (*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &Message::FillTime, "Returns the string filled with values of hours, minutes and seconds. Example: 1. (5, 12, 26.3345) returns '05h:12m:26.33s', 2. (0, 6, 34.496 ) returns '06m:34.50s', 3. (0, 0, 4.5 ) returns '4.50s'", py::arg("Hour"), py::arg("Minute"), py::arg("Second"));

// Enums

}