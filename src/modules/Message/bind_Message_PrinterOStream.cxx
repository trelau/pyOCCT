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
#include <Message_Printer.hxx>
#include <Standard_Handle.hxx>
#include <Message_PrinterOStream.hxx>
#include <Standard_Type.hxx>
#include <Message_Gravity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>

void bind_Message_PrinterOStream(py::module &mod){

py::class_<Message_PrinterOStream, opencascade::handle<Message_PrinterOStream>, Message_Printer> cls_Message_PrinterOStream(mod, "Message_PrinterOStream", "Implementation of a message printer associated with an ostream The ostream may be either externally defined one (e.g. cout), or file stream maintained internally (depending on constructor).");

// Constructors
cls_Message_PrinterOStream.def(py::init<>());
cls_Message_PrinterOStream.def(py::init<const Message_Gravity>(), py::arg("theTraceLevel"));
cls_Message_PrinterOStream.def(py::init<const Standard_CString, const Standard_Boolean>(), py::arg("theFileName"), py::arg("theDoAppend"));
cls_Message_PrinterOStream.def(py::init<const Standard_CString, const Standard_Boolean, const Message_Gravity>(), py::arg("theFileName"), py::arg("theDoAppend"), py::arg("theTraceLevel"));

// Fields

// Methods
cls_Message_PrinterOStream.def_static("get_type_name_", (const char * (*)()) &Message_PrinterOStream::get_type_name, "None");
cls_Message_PrinterOStream.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_PrinterOStream::get_type_descriptor, "None");
cls_Message_PrinterOStream.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_PrinterOStream::*)() const) &Message_PrinterOStream::DynamicType, "None");
cls_Message_PrinterOStream.def("Close", (void (Message_PrinterOStream::*)()) &Message_PrinterOStream::Close, "Flushes the output stream and destroys it if it has been specified externally with option doFree (or if it is internal file stream)");
cls_Message_PrinterOStream.def("GetUseUtf8", (Standard_Boolean (Message_PrinterOStream::*)() const) &Message_PrinterOStream::GetUseUtf8, "Returns option to convert non-Ascii symbols to UTF8 encoding");
cls_Message_PrinterOStream.def("SetUseUtf8", (void (Message_PrinterOStream::*)(const Standard_Boolean)) &Message_PrinterOStream::SetUseUtf8, "Sets option to convert non-Ascii symbols to UTF8 encoding", py::arg("useUtf8"));
cls_Message_PrinterOStream.def("GetStream", (Standard_OStream & (Message_PrinterOStream::*)() const) &Message_PrinterOStream::GetStream, "Returns reference to the output stream");
cls_Message_PrinterOStream.def("Send", [](Message_PrinterOStream &self, const Standard_CString a0, const Message_Gravity a1) -> void { return self.Send(a0, a1); });
cls_Message_PrinterOStream.def("Send", (void (Message_PrinterOStream::*)(const Standard_CString, const Message_Gravity, const Standard_Boolean) const) &Message_PrinterOStream::Send, "Puts a message to the current stream if its gravity is equal or greater to the trace level set by SetTraceLevel()", py::arg("theString"), py::arg("theGravity"), py::arg("putEndl"));
cls_Message_PrinterOStream.def("Send", [](Message_PrinterOStream &self, const TCollection_AsciiString & a0, const Message_Gravity a1) -> void { return self.Send(a0, a1); });
cls_Message_PrinterOStream.def("Send", (void (Message_PrinterOStream::*)(const TCollection_AsciiString &, const Message_Gravity, const Standard_Boolean) const) &Message_PrinterOStream::Send, "Puts a message to the current stream if its gravity is equal or greater to the trace level set by SetTraceLevel()", py::arg("theString"), py::arg("theGravity"), py::arg("putEndl"));
cls_Message_PrinterOStream.def("Send", [](Message_PrinterOStream &self, const TCollection_ExtendedString & a0, const Message_Gravity a1) -> void { return self.Send(a0, a1); });
cls_Message_PrinterOStream.def("Send", (void (Message_PrinterOStream::*)(const TCollection_ExtendedString &, const Message_Gravity, const Standard_Boolean) const) &Message_PrinterOStream::Send, "Puts a message to the current stream if its gravity is equal or greater to the trace level set by SetTraceLevel() Non-Ascii symbols are converted to UTF-8 if UseUtf8 option is set, else replaced by symbols '?'", py::arg("theString"), py::arg("theGravity"), py::arg("putEndl"));

// Enums

}