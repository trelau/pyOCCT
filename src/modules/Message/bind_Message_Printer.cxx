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
#include <Standard_Handle.hxx>
#include <Message_Printer.hxx>
#include <Standard_Type.hxx>
#include <Message_Gravity.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>

void bind_Message_Printer(py::module &mod){

py::class_<Message_Printer, opencascade::handle<Message_Printer>, Standard_Transient> cls_Message_Printer(mod, "Message_Printer", "Abstract interface class defining printer as output context for text messages");

// Fields

// Methods
cls_Message_Printer.def_static("get_type_name_", (const char * (*)()) &Message_Printer::get_type_name, "None");
cls_Message_Printer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_Printer::get_type_descriptor, "None");
cls_Message_Printer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_Printer::*)() const) &Message_Printer::DynamicType, "None");
cls_Message_Printer.def("GetTraceLevel", (Message_Gravity (Message_Printer::*)() const) &Message_Printer::GetTraceLevel, "Return trace level used for filtering messages; messages with lover gravity will be ignored.");
cls_Message_Printer.def("SetTraceLevel", (void (Message_Printer::*)(const Message_Gravity)) &Message_Printer::SetTraceLevel, "Set trace level used for filtering messages. By default, trace level is Message_Info, so that all messages are output", py::arg("theTraceLevel"));
cls_Message_Printer.def("Send", (void (Message_Printer::*)(const TCollection_ExtendedString &, const Message_Gravity, const Standard_Boolean) const) &Message_Printer::Send, "Send a string message with specified trace level. The parameter theToPutEol specified whether end-of-line should be added to the end of the message. This method must be redefined in descentant.", py::arg("theString"), py::arg("theGravity"), py::arg("theToPutEol"));
cls_Message_Printer.def("Send", (void (Message_Printer::*)(const Standard_CString, const Message_Gravity, const Standard_Boolean) const) &Message_Printer::Send, "Send a string message with specified trace level. The parameter theToPutEol specified whether end-of-line should be added to the end of the message. Default implementation calls first method Send().", py::arg("theString"), py::arg("theGravity"), py::arg("theToPutEol"));
cls_Message_Printer.def("Send", (void (Message_Printer::*)(const TCollection_AsciiString &, const Message_Gravity, const Standard_Boolean) const) &Message_Printer::Send, "Send a string message with specified trace level. The parameter theToPutEol specified whether end-of-line should be added to the end of the message. Default implementation calls first method Send().", py::arg("theString"), py::arg("theGravity"), py::arg("theToPutEol"));

// Enums

}