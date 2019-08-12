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
#include <Message_Messenger.hxx>
#include <Standard_Type.hxx>
#include <Message_Printer.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_SequenceOfPrinters.hxx>
#include <Message_Gravity.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>

void bind_Message_Messenger(py::module &mod){

py::class_<Message_Messenger, opencascade::handle<Message_Messenger>, Standard_Transient> cls_Message_Messenger(mod, "Message_Messenger", "Messenger is API class providing general-purpose interface for libraries that may issue text messages without knowledge of how these messages will be further processed.");

// Constructors
cls_Message_Messenger.def(py::init<>());
cls_Message_Messenger.def(py::init<const opencascade::handle<Message_Printer> &>(), py::arg("thePrinter"));

// Fields

// Methods
cls_Message_Messenger.def_static("get_type_name_", (const char * (*)()) &Message_Messenger::get_type_name, "None");
cls_Message_Messenger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_Messenger::get_type_descriptor, "None");
cls_Message_Messenger.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_Messenger::*)() const) &Message_Messenger::DynamicType, "None");
cls_Message_Messenger.def("AddPrinter", (Standard_Boolean (Message_Messenger::*)(const opencascade::handle<Message_Printer> &)) &Message_Messenger::AddPrinter, "Add a printer to the messenger. The printer will be added only if it is not yet in the list. Returns True if printer has been added.", py::arg("thePrinter"));
cls_Message_Messenger.def("RemovePrinter", (Standard_Boolean (Message_Messenger::*)(const opencascade::handle<Message_Printer> &)) &Message_Messenger::RemovePrinter, "Removes specified printer from the messenger. Returns True if this printer has been found in the list and removed.", py::arg("thePrinter"));
cls_Message_Messenger.def("RemovePrinters", (Standard_Integer (Message_Messenger::*)(const opencascade::handle<Standard_Type> &)) &Message_Messenger::RemovePrinters, "Removes printers of specified type (including derived classes) from the messenger. Returns number of removed printers.", py::arg("theType"));
cls_Message_Messenger.def("Printers", (const Message_SequenceOfPrinters & (Message_Messenger::*)() const) &Message_Messenger::Printers, "Returns current sequence of printers");
cls_Message_Messenger.def("ChangePrinters", (Message_SequenceOfPrinters & (Message_Messenger::*)()) &Message_Messenger::ChangePrinters, "Returns sequence of printers The sequence can be modified.");
cls_Message_Messenger.def("Send", [](Message_Messenger &self, const Standard_CString a0) -> void { return self.Send(a0); });
cls_Message_Messenger.def("Send", [](Message_Messenger &self, const Standard_CString a0, const Message_Gravity a1) -> void { return self.Send(a0, a1); });
cls_Message_Messenger.def("Send", (void (Message_Messenger::*)(const Standard_CString, const Message_Gravity, const Standard_Boolean) const) &Message_Messenger::Send, "Dispatch a message to all the printers in the list. Three versions of string representations are accepted for convenience, by default all are converted to ExtendedString. The parameter putEndl specifies whether the new line should be started after this message (default) or not (may have sense in some conditions).", py::arg("theString"), py::arg("theGravity"), py::arg("putEndl"));
cls_Message_Messenger.def("Send", [](Message_Messenger &self, const TCollection_AsciiString & a0) -> void { return self.Send(a0); });
cls_Message_Messenger.def("Send", [](Message_Messenger &self, const TCollection_AsciiString & a0, const Message_Gravity a1) -> void { return self.Send(a0, a1); });
cls_Message_Messenger.def("Send", (void (Message_Messenger::*)(const TCollection_AsciiString &, const Message_Gravity, const Standard_Boolean) const) &Message_Messenger::Send, "See above", py::arg("theString"), py::arg("theGravity"), py::arg("putEndl"));
cls_Message_Messenger.def("Send", [](Message_Messenger &self, const TCollection_ExtendedString & a0) -> void { return self.Send(a0); });
cls_Message_Messenger.def("Send", [](Message_Messenger &self, const TCollection_ExtendedString & a0, const Message_Gravity a1) -> void { return self.Send(a0, a1); });
cls_Message_Messenger.def("Send", (void (Message_Messenger::*)(const TCollection_ExtendedString &, const Message_Gravity, const Standard_Boolean) const) &Message_Messenger::Send, "See above", py::arg("theString"), py::arg("theGravity"), py::arg("putEndl"));

// Enums

}