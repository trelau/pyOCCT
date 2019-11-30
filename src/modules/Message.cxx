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
#include <Message_Gravity.hxx>
#include <Message_StatusType.hxx>
#include <Message_Status.hxx>
#include <Standard_Handle.hxx>
#include <Message_Messenger.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <Message_Printer.hxx>
#include <Standard_Type.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <NCollection_Sequence.hxx>
#include <Message_SequenceOfPrinters.hxx>
#include <Message_Alert.hxx>
#include <NCollection_List.hxx>
#include <Message_ListOfAlert.hxx>
#include <Standard_OStream.hxx>
#include <Message_Report.hxx>
#include <Standard_Mutex.hxx>
#include <Standard.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Message_ProgressScale.hxx>
#include <Message_SequenceOfProgressScale.hxx>
#include <Message_ProgressIndicator.hxx>
#include <Message_ExecStatus.hxx>
#include <Message_Msg.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_Handle.hxx>
#include <Message_HArrayOfMsg.hxx>
#include <Message_Algorithm.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <TColStd_HSequenceOfHExtendedString.hxx>
#include <TColStd_SequenceOfHExtendedString.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <Message_MsgFile.hxx>
#include <Message_PrinterOStream.hxx>
#include <Message_ProgressSentry.hxx>
#include <Message.hxx>
#include <Message_ListOfMsg.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Handle.hxx>
#include <bind_NCollection_TListIterator.hxx>

PYBIND11_MODULE(Message, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");

// ENUM: MESSAGE_GRAVITY
py::enum_<Message_Gravity>(mod, "Message_Gravity", "Defines gravity level of messages - Trace: low-level details on algorithm execution (usually for debug purposes) - Info: informative message - Warning: warning message - Alarm: non-critical error - Fail: fatal error")
	.value("Message_Trace", Message_Gravity::Message_Trace)
	.value("Message_Info", Message_Gravity::Message_Info)
	.value("Message_Warning", Message_Gravity::Message_Warning)
	.value("Message_Alarm", Message_Gravity::Message_Alarm)
	.value("Message_Fail", Message_Gravity::Message_Fail)
	.export_values();


// ENUM: MESSAGE_STATUSTYPE
py::enum_<Message_StatusType>(mod, "Message_StatusType", "Definition of types of execution status supported by the class Message_ExecStatus")
	.value("Message_DONE", Message_StatusType::Message_DONE)
	.value("Message_WARN", Message_StatusType::Message_WARN)
	.value("Message_ALARM", Message_StatusType::Message_ALARM)
	.value("Message_FAIL", Message_StatusType::Message_FAIL)
	.export_values();


// ENUM: MESSAGE_STATUS
py::enum_<Message_Status>(mod, "Message_Status", "Enumeration covering all execution statuses supported by the class Message_ExecStatus: 32 statuses per each of 4 types (DONE, WARN, ALARM, FAIL)")
	.value("Message_None", Message_Status::Message_None)
	.value("Message_Done1", Message_Status::Message_Done1)
	.value("Message_Done2", Message_Status::Message_Done2)
	.value("Message_Done3", Message_Status::Message_Done3)
	.value("Message_Done4", Message_Status::Message_Done4)
	.value("Message_Done5", Message_Status::Message_Done5)
	.value("Message_Done6", Message_Status::Message_Done6)
	.value("Message_Done7", Message_Status::Message_Done7)
	.value("Message_Done8", Message_Status::Message_Done8)
	.value("Message_Done9", Message_Status::Message_Done9)
	.value("Message_Done10", Message_Status::Message_Done10)
	.value("Message_Done11", Message_Status::Message_Done11)
	.value("Message_Done12", Message_Status::Message_Done12)
	.value("Message_Done13", Message_Status::Message_Done13)
	.value("Message_Done14", Message_Status::Message_Done14)
	.value("Message_Done15", Message_Status::Message_Done15)
	.value("Message_Done16", Message_Status::Message_Done16)
	.value("Message_Done17", Message_Status::Message_Done17)
	.value("Message_Done18", Message_Status::Message_Done18)
	.value("Message_Done19", Message_Status::Message_Done19)
	.value("Message_Done20", Message_Status::Message_Done20)
	.value("Message_Done21", Message_Status::Message_Done21)
	.value("Message_Done22", Message_Status::Message_Done22)
	.value("Message_Done23", Message_Status::Message_Done23)
	.value("Message_Done24", Message_Status::Message_Done24)
	.value("Message_Done25", Message_Status::Message_Done25)
	.value("Message_Done26", Message_Status::Message_Done26)
	.value("Message_Done27", Message_Status::Message_Done27)
	.value("Message_Done28", Message_Status::Message_Done28)
	.value("Message_Done29", Message_Status::Message_Done29)
	.value("Message_Done30", Message_Status::Message_Done30)
	.value("Message_Done31", Message_Status::Message_Done31)
	.value("Message_Done32", Message_Status::Message_Done32)
	.value("Message_Warn1", Message_Status::Message_Warn1)
	.value("Message_Warn2", Message_Status::Message_Warn2)
	.value("Message_Warn3", Message_Status::Message_Warn3)
	.value("Message_Warn4", Message_Status::Message_Warn4)
	.value("Message_Warn5", Message_Status::Message_Warn5)
	.value("Message_Warn6", Message_Status::Message_Warn6)
	.value("Message_Warn7", Message_Status::Message_Warn7)
	.value("Message_Warn8", Message_Status::Message_Warn8)
	.value("Message_Warn9", Message_Status::Message_Warn9)
	.value("Message_Warn10", Message_Status::Message_Warn10)
	.value("Message_Warn11", Message_Status::Message_Warn11)
	.value("Message_Warn12", Message_Status::Message_Warn12)
	.value("Message_Warn13", Message_Status::Message_Warn13)
	.value("Message_Warn14", Message_Status::Message_Warn14)
	.value("Message_Warn15", Message_Status::Message_Warn15)
	.value("Message_Warn16", Message_Status::Message_Warn16)
	.value("Message_Warn17", Message_Status::Message_Warn17)
	.value("Message_Warn18", Message_Status::Message_Warn18)
	.value("Message_Warn19", Message_Status::Message_Warn19)
	.value("Message_Warn20", Message_Status::Message_Warn20)
	.value("Message_Warn21", Message_Status::Message_Warn21)
	.value("Message_Warn22", Message_Status::Message_Warn22)
	.value("Message_Warn23", Message_Status::Message_Warn23)
	.value("Message_Warn24", Message_Status::Message_Warn24)
	.value("Message_Warn25", Message_Status::Message_Warn25)
	.value("Message_Warn26", Message_Status::Message_Warn26)
	.value("Message_Warn27", Message_Status::Message_Warn27)
	.value("Message_Warn28", Message_Status::Message_Warn28)
	.value("Message_Warn29", Message_Status::Message_Warn29)
	.value("Message_Warn30", Message_Status::Message_Warn30)
	.value("Message_Warn31", Message_Status::Message_Warn31)
	.value("Message_Warn32", Message_Status::Message_Warn32)
	.value("Message_Alarm1", Message_Status::Message_Alarm1)
	.value("Message_Alarm2", Message_Status::Message_Alarm2)
	.value("Message_Alarm3", Message_Status::Message_Alarm3)
	.value("Message_Alarm4", Message_Status::Message_Alarm4)
	.value("Message_Alarm5", Message_Status::Message_Alarm5)
	.value("Message_Alarm6", Message_Status::Message_Alarm6)
	.value("Message_Alarm7", Message_Status::Message_Alarm7)
	.value("Message_Alarm8", Message_Status::Message_Alarm8)
	.value("Message_Alarm9", Message_Status::Message_Alarm9)
	.value("Message_Alarm10", Message_Status::Message_Alarm10)
	.value("Message_Alarm11", Message_Status::Message_Alarm11)
	.value("Message_Alarm12", Message_Status::Message_Alarm12)
	.value("Message_Alarm13", Message_Status::Message_Alarm13)
	.value("Message_Alarm14", Message_Status::Message_Alarm14)
	.value("Message_Alarm15", Message_Status::Message_Alarm15)
	.value("Message_Alarm16", Message_Status::Message_Alarm16)
	.value("Message_Alarm17", Message_Status::Message_Alarm17)
	.value("Message_Alarm18", Message_Status::Message_Alarm18)
	.value("Message_Alarm19", Message_Status::Message_Alarm19)
	.value("Message_Alarm20", Message_Status::Message_Alarm20)
	.value("Message_Alarm21", Message_Status::Message_Alarm21)
	.value("Message_Alarm22", Message_Status::Message_Alarm22)
	.value("Message_Alarm23", Message_Status::Message_Alarm23)
	.value("Message_Alarm24", Message_Status::Message_Alarm24)
	.value("Message_Alarm25", Message_Status::Message_Alarm25)
	.value("Message_Alarm26", Message_Status::Message_Alarm26)
	.value("Message_Alarm27", Message_Status::Message_Alarm27)
	.value("Message_Alarm28", Message_Status::Message_Alarm28)
	.value("Message_Alarm29", Message_Status::Message_Alarm29)
	.value("Message_Alarm30", Message_Status::Message_Alarm30)
	.value("Message_Alarm31", Message_Status::Message_Alarm31)
	.value("Message_Alarm32", Message_Status::Message_Alarm32)
	.value("Message_Fail1", Message_Status::Message_Fail1)
	.value("Message_Fail2", Message_Status::Message_Fail2)
	.value("Message_Fail3", Message_Status::Message_Fail3)
	.value("Message_Fail4", Message_Status::Message_Fail4)
	.value("Message_Fail5", Message_Status::Message_Fail5)
	.value("Message_Fail6", Message_Status::Message_Fail6)
	.value("Message_Fail7", Message_Status::Message_Fail7)
	.value("Message_Fail8", Message_Status::Message_Fail8)
	.value("Message_Fail9", Message_Status::Message_Fail9)
	.value("Message_Fail10", Message_Status::Message_Fail10)
	.value("Message_Fail11", Message_Status::Message_Fail11)
	.value("Message_Fail12", Message_Status::Message_Fail12)
	.value("Message_Fail13", Message_Status::Message_Fail13)
	.value("Message_Fail14", Message_Status::Message_Fail14)
	.value("Message_Fail15", Message_Status::Message_Fail15)
	.value("Message_Fail16", Message_Status::Message_Fail16)
	.value("Message_Fail17", Message_Status::Message_Fail17)
	.value("Message_Fail18", Message_Status::Message_Fail18)
	.value("Message_Fail19", Message_Status::Message_Fail19)
	.value("Message_Fail20", Message_Status::Message_Fail20)
	.value("Message_Fail21", Message_Status::Message_Fail21)
	.value("Message_Fail22", Message_Status::Message_Fail22)
	.value("Message_Fail23", Message_Status::Message_Fail23)
	.value("Message_Fail24", Message_Status::Message_Fail24)
	.value("Message_Fail25", Message_Status::Message_Fail25)
	.value("Message_Fail26", Message_Status::Message_Fail26)
	.value("Message_Fail27", Message_Status::Message_Fail27)
	.value("Message_Fail28", Message_Status::Message_Fail28)
	.value("Message_Fail29", Message_Status::Message_Fail29)
	.value("Message_Fail30", Message_Status::Message_Fail30)
	.value("Message_Fail31", Message_Status::Message_Fail31)
	.value("Message_Fail32", Message_Status::Message_Fail32)
	.export_values();


// FUNCTION: MESSAGE_ENDLINE
mod.def("Message_EndLine", (const opencascade::handle<Message_Messenger> & (*) (const opencascade::handle<Message_Messenger> &)) &Message_EndLine, "None", py::arg("theMessenger"));

// CLASS: MESSAGE_PRINTER
py::class_<Message_Printer, opencascade::handle<Message_Printer>, Standard_Transient> cls_Message_Printer(mod, "Message_Printer", "Abstract interface class defining printer as output context for text messages");

// Methods
cls_Message_Printer.def_static("get_type_name_", (const char * (*)()) &Message_Printer::get_type_name, "None");
cls_Message_Printer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_Printer::get_type_descriptor, "None");
cls_Message_Printer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_Printer::*)() const) &Message_Printer::DynamicType, "None");
cls_Message_Printer.def("GetTraceLevel", (Message_Gravity (Message_Printer::*)() const) &Message_Printer::GetTraceLevel, "Return trace level used for filtering messages; messages with lover gravity will be ignored.");
cls_Message_Printer.def("SetTraceLevel", (void (Message_Printer::*)(const Message_Gravity)) &Message_Printer::SetTraceLevel, "Set trace level used for filtering messages. By default, trace level is Message_Info, so that all messages are output", py::arg("theTraceLevel"));
cls_Message_Printer.def("Send", (void (Message_Printer::*)(const TCollection_ExtendedString &, const Message_Gravity, const Standard_Boolean) const) &Message_Printer::Send, "Send a string message with specified trace level. The parameter theToPutEol specified whether end-of-line should be added to the end of the message. This method must be redefined in descentant.", py::arg("theString"), py::arg("theGravity"), py::arg("theToPutEol"));
cls_Message_Printer.def("Send", (void (Message_Printer::*)(const Standard_CString, const Message_Gravity, const Standard_Boolean) const) &Message_Printer::Send, "Send a string message with specified trace level. The parameter theToPutEol specified whether end-of-line should be added to the end of the message. Default implementation calls first method Send().", py::arg("theString"), py::arg("theGravity"), py::arg("theToPutEol"));
cls_Message_Printer.def("Send", (void (Message_Printer::*)(const TCollection_AsciiString &, const Message_Gravity, const Standard_Boolean) const) &Message_Printer::Send, "Send a string message with specified trace level. The parameter theToPutEol specified whether end-of-line should be added to the end of the message. Default implementation calls first method Send().", py::arg("theString"), py::arg("theGravity"), py::arg("theToPutEol"));

// TYPEDEF: MESSAGE_SEQUENCEOFPRINTERS
bind_NCollection_Sequence<opencascade::handle<Message_Printer> >(mod, "Message_SequenceOfPrinters", py::module_local(false));

// CLASS: MESSAGE_MESSENGER
py::class_<Message_Messenger, opencascade::handle<Message_Messenger>, Standard_Transient> cls_Message_Messenger(mod, "Message_Messenger", "Messenger is API class providing general-purpose interface for libraries that may issue text messages without knowledge of how these messages will be further processed.");

// Constructors
cls_Message_Messenger.def(py::init<>());
cls_Message_Messenger.def(py::init<const opencascade::handle<Message_Printer> &>(), py::arg("thePrinter"));

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

// CLASS: MESSAGE_ALERT
py::class_<Message_Alert, opencascade::handle<Message_Alert>, Standard_Transient> cls_Message_Alert(mod, "Message_Alert", "Base class of the hierarchy of classes describing various situations occurring during execution of some algorithm or procedure.");

// Constructors
cls_Message_Alert.def(py::init<>());

// Methods
cls_Message_Alert.def("GetMessageKey", (Standard_CString (Message_Alert::*)() const) &Message_Alert::GetMessageKey, "Return a C string to be used as a key for generating text user messages describing this alert. The messages are generated with help of Message_Msg class, in Message_Report::Dump(). Base implementation returns dynamic type name of the instance.");
cls_Message_Alert.def("SupportsMerge", (Standard_Boolean (Message_Alert::*)() const) &Message_Alert::SupportsMerge, "Return true if this type of alert can be merged with other of the same type to avoid duplication. Basis implementation returns true.");
cls_Message_Alert.def("Merge", (Standard_Boolean (Message_Alert::*)(const opencascade::handle<Message_Alert> &)) &Message_Alert::Merge, "If possible, merge data contained in this alert to theTarget.", py::arg("theTarget"));
cls_Message_Alert.def_static("get_type_name_", (const char * (*)()) &Message_Alert::get_type_name, "None");
cls_Message_Alert.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_Alert::get_type_descriptor, "None");
cls_Message_Alert.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_Alert::*)() const) &Message_Alert::DynamicType, "None");

// TYPEDEF: MESSAGE_LISTOFALERT
bind_NCollection_List<opencascade::handle<Message_Alert> >(mod, "Message_ListOfAlert", py::module_local(false));

// CLASS: MESSAGE_REPORT
py::class_<Message_Report, opencascade::handle<Message_Report>, Standard_Transient> cls_Message_Report(mod, "Message_Report", "Container for alert messages, sorted according to their gravity.");

// Constructors
cls_Message_Report.def(py::init<>());

// Methods
cls_Message_Report.def("AddAlert", (void (Message_Report::*)(Message_Gravity, const opencascade::handle<Message_Alert> &)) &Message_Report::AddAlert, "Add alert with specified gravity. This method is thread-safe, i.e. alerts can be added from parallel threads safely.", py::arg("theGravity"), py::arg("theAlert"));
cls_Message_Report.def("GetAlerts", (const Message_ListOfAlert & (Message_Report::*)(Message_Gravity) const) &Message_Report::GetAlerts, "Returns list of collected alerts with specified gravity", py::arg("theGravity"));
cls_Message_Report.def("HasAlert", (Standard_Boolean (Message_Report::*)(const opencascade::handle<Standard_Type> &)) &Message_Report::HasAlert, "Returns true if specific type of alert is recorded", py::arg("theType"));
cls_Message_Report.def("HasAlert", (Standard_Boolean (Message_Report::*)(const opencascade::handle<Standard_Type> &, Message_Gravity)) &Message_Report::HasAlert, "Returns true if specific type of alert is recorded with specified gravity", py::arg("theType"), py::arg("theGravity"));
cls_Message_Report.def("Clear", (void (Message_Report::*)()) &Message_Report::Clear, "Clears all collected alerts");
cls_Message_Report.def("Clear", (void (Message_Report::*)(Message_Gravity)) &Message_Report::Clear, "Clears collected alerts with specified gravity", py::arg("theGravity"));
cls_Message_Report.def("Clear", (void (Message_Report::*)(const opencascade::handle<Standard_Type> &)) &Message_Report::Clear, "Clears collected alerts with specified type", py::arg("theType"));
cls_Message_Report.def("Dump", (void (Message_Report::*)(Standard_OStream &)) &Message_Report::Dump, "Dumps all collected alerts to stream", py::arg("theOS"));
cls_Message_Report.def("Dump", (void (Message_Report::*)(Standard_OStream &, Message_Gravity)) &Message_Report::Dump, "Dumps collected alerts with specified gravity to stream", py::arg("theOS"), py::arg("theGravity"));
cls_Message_Report.def("SendMessages", (void (Message_Report::*)(const opencascade::handle<Message_Messenger> &)) &Message_Report::SendMessages, "Sends all collected alerts to messenger", py::arg("theMessenger"));
cls_Message_Report.def("SendMessages", (void (Message_Report::*)(const opencascade::handle<Message_Messenger> &, Message_Gravity)) &Message_Report::SendMessages, "Dumps collected alerts with specified gravity to messenger", py::arg("theMessenger"), py::arg("theGravity"));
cls_Message_Report.def("Merge", (void (Message_Report::*)(const opencascade::handle<Message_Report> &)) &Message_Report::Merge, "Merges data from theOther report into this", py::arg("theOther"));
cls_Message_Report.def("Merge", (void (Message_Report::*)(const opencascade::handle<Message_Report> &, Message_Gravity)) &Message_Report::Merge, "Merges alerts with specified gravity from theOther report into this", py::arg("theOther"), py::arg("theGravity"));
cls_Message_Report.def_static("get_type_name_", (const char * (*)()) &Message_Report::get_type_name, "None");
cls_Message_Report.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_Report::get_type_descriptor, "None");
cls_Message_Report.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_Report::*)() const) &Message_Report::DynamicType, "None");

// CLASS: MESSAGE_PROGRESSSCALE
py::class_<Message_ProgressScale> cls_Message_ProgressScale(mod, "Message_ProgressScale", "Internal data structure for scale in ProgressIndicator");

// Constructors
cls_Message_ProgressScale.def(py::init<>());

// Methods
// cls_Message_ProgressScale.def_static("operator new_", (void * (*)(size_t)) &Message_ProgressScale::operator new, "None", py::arg("theSize"));
// cls_Message_ProgressScale.def_static("operator delete_", (void (*)(void *)) &Message_ProgressScale::operator delete, "None", py::arg("theAddress"));
// cls_Message_ProgressScale.def_static("operator new[]_", (void * (*)(size_t)) &Message_ProgressScale::operator new[], "None", py::arg("theSize"));
// cls_Message_ProgressScale.def_static("operator delete[]_", (void (*)(void *)) &Message_ProgressScale::operator delete[], "None", py::arg("theAddress"));
// cls_Message_ProgressScale.def_static("operator new_", (void * (*)(size_t, void *)) &Message_ProgressScale::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Message_ProgressScale.def_static("operator delete_", (void (*)(void *, void *)) &Message_ProgressScale::operator delete, "None", py::arg(""), py::arg(""));
cls_Message_ProgressScale.def("SetName", (void (Message_ProgressScale::*)(const Standard_CString)) &Message_ProgressScale::SetName, "None", py::arg("theName"));
cls_Message_ProgressScale.def("SetName", (void (Message_ProgressScale::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_ProgressScale::SetName, "Sets scale name", py::arg("theName"));
cls_Message_ProgressScale.def("GetName", (opencascade::handle<TCollection_HAsciiString> (Message_ProgressScale::*)() const) &Message_ProgressScale::GetName, "Gets scale name Name may be Null handle if not set");
cls_Message_ProgressScale.def("SetMin", (void (Message_ProgressScale::*)(const Standard_Real)) &Message_ProgressScale::SetMin, "Sets minimum value of scale", py::arg("theMin"));
cls_Message_ProgressScale.def("GetMin", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetMin, "Gets minimum value of scale");
cls_Message_ProgressScale.def("SetMax", (void (Message_ProgressScale::*)(const Standard_Real)) &Message_ProgressScale::SetMax, "Sets minimum value of scale", py::arg("theMax"));
cls_Message_ProgressScale.def("GetMax", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetMax, "Gets minimum value of scale");
cls_Message_ProgressScale.def("SetRange", (void (Message_ProgressScale::*)(const Standard_Real, const Standard_Real)) &Message_ProgressScale::SetRange, "Set both min and max", py::arg("min"), py::arg("max"));
cls_Message_ProgressScale.def("SetStep", (void (Message_ProgressScale::*)(const Standard_Real)) &Message_ProgressScale::SetStep, "Sets default step", py::arg("theStep"));
cls_Message_ProgressScale.def("GetStep", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetStep, "Gets default step");
cls_Message_ProgressScale.def("SetInfinite", [](Message_ProgressScale &self) -> void { return self.SetInfinite(); });
cls_Message_ProgressScale.def("SetInfinite", (void (Message_ProgressScale::*)(const Standard_Boolean)) &Message_ProgressScale::SetInfinite, "Sets flag for infinite scale", py::arg("theInfinite"));
cls_Message_ProgressScale.def("GetInfinite", (Standard_Boolean (Message_ProgressScale::*)() const) &Message_ProgressScale::GetInfinite, "Gets flag for infinite scale");
cls_Message_ProgressScale.def("SetScale", [](Message_ProgressScale &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetScale(a0, a1, a2); });
cls_Message_ProgressScale.def("SetScale", (void (Message_ProgressScale::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Message_ProgressScale::SetScale, "Set all scale parameters", py::arg("min"), py::arg("max"), py::arg("step"), py::arg("theInfinite"));
cls_Message_ProgressScale.def("SetSpan", (void (Message_ProgressScale::*)(const Standard_Real, const Standard_Real)) &Message_ProgressScale::SetSpan, "Defines span occupied by the scale on the basis scale", py::arg("first"), py::arg("last"));
cls_Message_ProgressScale.def("GetFirst", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetFirst, "None");
cls_Message_ProgressScale.def("GetLast", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetLast, "Return information on span occupied by the scale on the base scale");
cls_Message_ProgressScale.def("LocalToBase", (Standard_Real (Message_ProgressScale::*)(const Standard_Real) const) &Message_ProgressScale::LocalToBase, "None", py::arg("val"));
cls_Message_ProgressScale.def("BaseToLocal", (Standard_Real (Message_ProgressScale::*)(const Standard_Real) const) &Message_ProgressScale::BaseToLocal, "Convert value from this scale to base one and back", py::arg("val"));

// TYPEDEF: MESSAGE_SEQUENCEOFPROGRESSSCALE
bind_NCollection_Sequence<Message_ProgressScale>(mod, "Message_SequenceOfProgressScale", py::module_local(false));

// CLASS: MESSAGE_PROGRESSINDICATOR
py::class_<Message_ProgressIndicator, opencascade::handle<Message_ProgressIndicator>, Standard_Transient> cls_Message_ProgressIndicator(mod, "Message_ProgressIndicator", "Defines abstract interface from program to the 'user'. This includes progress indication and user break mechanisms.");

// Methods
cls_Message_ProgressIndicator.def("Reset", (void (Message_ProgressIndicator::*)()) &Message_ProgressIndicator::Reset, "Drops all scopes and sets scale from 0 to 100, step 1 This scale has name 'Step'");
cls_Message_ProgressIndicator.def("SetName", (void (Message_ProgressIndicator::*)(const Standard_CString)) &Message_ProgressIndicator::SetName, "None", py::arg("name"));
cls_Message_ProgressIndicator.def("SetName", (void (Message_ProgressIndicator::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_ProgressIndicator::SetName, "Set (optional) name for scale", py::arg("name"));
cls_Message_ProgressIndicator.def("SetRange", (void (Message_ProgressIndicator::*)(const Standard_Real, const Standard_Real)) &Message_ProgressIndicator::SetRange, "Set range for current scale", py::arg("min"), py::arg("max"));
cls_Message_ProgressIndicator.def("SetStep", (void (Message_ProgressIndicator::*)(const Standard_Real)) &Message_ProgressIndicator::SetStep, "Set step for current scale", py::arg("step"));
cls_Message_ProgressIndicator.def("SetInfinite", [](Message_ProgressIndicator &self) -> void { return self.SetInfinite(); });
cls_Message_ProgressIndicator.def("SetInfinite", (void (Message_ProgressIndicator::*)(const Standard_Boolean)) &Message_ProgressIndicator::SetInfinite, "Set or drop infinite mode for the current scale", py::arg("isInf"));
cls_Message_ProgressIndicator.def("SetScale", [](Message_ProgressIndicator &self, const Standard_CString a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.SetScale(a0, a1, a2, a3); });
cls_Message_ProgressIndicator.def("SetScale", (void (Message_ProgressIndicator::*)(const Standard_CString, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Message_ProgressIndicator::SetScale, "None", py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressIndicator.def("SetScale", [](Message_ProgressIndicator &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetScale(a0, a1, a2); });
cls_Message_ProgressIndicator.def("SetScale", (void (Message_ProgressIndicator::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Message_ProgressIndicator::SetScale, "Set all parameters for current scale", py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressIndicator.def("GetScale", [](Message_ProgressIndicator &self, Standard_Real & min, Standard_Real & max, Standard_Real & step, Standard_Boolean & isInf){ self.GetScale(min, max, step, isInf); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Boolean &>(min, max, step, isInf); }, "Returns all parameters for current scale", py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressIndicator.def("SetValue", (void (Message_ProgressIndicator::*)(const Standard_Real)) &Message_ProgressIndicator::SetValue, "None", py::arg("val"));
cls_Message_ProgressIndicator.def("GetValue", (Standard_Real (Message_ProgressIndicator::*)() const) &Message_ProgressIndicator::GetValue, "Set and get progress value at current scale If the value to be set is more than currently set one, or out of range for the current scale, it is limited by that range");
cls_Message_ProgressIndicator.def("Increment", (void (Message_ProgressIndicator::*)()) &Message_ProgressIndicator::Increment, "None");
cls_Message_ProgressIndicator.def("Increment", (void (Message_ProgressIndicator::*)(const Standard_Real)) &Message_ProgressIndicator::Increment, "Increment the progress value by the default of specified step", py::arg("step"));
cls_Message_ProgressIndicator.def("NewScope", [](Message_ProgressIndicator &self) -> Standard_Boolean { return self.NewScope(); });
cls_Message_ProgressIndicator.def("NewScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_CString)) &Message_ProgressIndicator::NewScope, "None", py::arg("name"));
cls_Message_ProgressIndicator.def("NewScope", (Standard_Boolean (Message_ProgressIndicator::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_ProgressIndicator::NewScope, "None", py::arg("name"));
cls_Message_ProgressIndicator.def("NewScope", [](Message_ProgressIndicator &self, const Standard_Real a0) -> Standard_Boolean { return self.NewScope(a0); });
cls_Message_ProgressIndicator.def("NewScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_Real, const Standard_CString)) &Message_ProgressIndicator::NewScope, "None", py::arg("span"), py::arg("name"));
cls_Message_ProgressIndicator.def("NewScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &)) &Message_ProgressIndicator::NewScope, "Creates new scope on a part of a current scale from current position with span either equal to default step, or specified The scale for the new scope will have specified name and ranged from 0 to 100 with step 1 Returns False if something is wrong in arguments or in current position of progress indicator; scope is opened anyway", py::arg("span"), py::arg("name"));
cls_Message_ProgressIndicator.def("EndScope", (Standard_Boolean (Message_ProgressIndicator::*)()) &Message_ProgressIndicator::EndScope, "Close the current scope and thus return to previous scale Updates position to be at the end of the closing scope Returns False if no scope is opened");
cls_Message_ProgressIndicator.def("NextScope", [](Message_ProgressIndicator &self) -> Standard_Boolean { return self.NextScope(); });
cls_Message_ProgressIndicator.def("NextScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_CString)) &Message_ProgressIndicator::NextScope, "None", py::arg("name"));
cls_Message_ProgressIndicator.def("NextScope", [](Message_ProgressIndicator &self, const Standard_Real a0) -> Standard_Boolean { return self.NextScope(a0); });
cls_Message_ProgressIndicator.def("NextScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_Real, const Standard_CString)) &Message_ProgressIndicator::NextScope, "Optimized version of { return EndScope() && NewScope(); }", py::arg("span"), py::arg("name"));
cls_Message_ProgressIndicator.def("UserBreak", (Standard_Boolean (Message_ProgressIndicator::*)()) &Message_ProgressIndicator::UserBreak, "Should return True if user has send a break signal. Default implementation returns False.");
cls_Message_ProgressIndicator.def("Show", [](Message_ProgressIndicator &self) -> Standard_Boolean { return self.Show(); });
cls_Message_ProgressIndicator.def("Show", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_Boolean)) &Message_ProgressIndicator::Show, "Update presentation of the progress indicator Called when progress position is changed Flag force is intended for forcing update in case if it is optimized; all internal calls from ProgressIndicator are done with this flag equal to False", py::arg("force"));
cls_Message_ProgressIndicator.def("GetPosition", (Standard_Real (Message_ProgressIndicator::*)() const) &Message_ProgressIndicator::GetPosition, "Returns total progress position on the basic scale ranged from 0. to 1.");
cls_Message_ProgressIndicator.def("GetNbScopes", (Standard_Integer (Message_ProgressIndicator::*)() const) &Message_ProgressIndicator::GetNbScopes, "Returns current number of opened scopes This number is always >=1 as top-level scale is always present");
cls_Message_ProgressIndicator.def("GetScope", (const Message_ProgressScale & (Message_ProgressIndicator::*)(const Standard_Integer) const) &Message_ProgressIndicator::GetScope, "Returns data for scale of index-th scope The first scope is current one, the last is the top-level one", py::arg("index"));
cls_Message_ProgressIndicator.def_static("get_type_name_", (const char * (*)()) &Message_ProgressIndicator::get_type_name, "None");
cls_Message_ProgressIndicator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_ProgressIndicator::get_type_descriptor, "None");
cls_Message_ProgressIndicator.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_ProgressIndicator::*)() const) &Message_ProgressIndicator::DynamicType, "None");

// CLASS: MESSAGE_EXECSTATUS
py::class_<Message_ExecStatus> cls_Message_ExecStatus(mod, "Message_ExecStatus", "Tiny class for extended handling of error / execution status of algorithm in universal way.");

// Constructors
cls_Message_ExecStatus.def(py::init<>());
cls_Message_ExecStatus.def(py::init<Message_Status>(), py::arg("status"));

// Methods
cls_Message_ExecStatus.def("Set", (void (Message_ExecStatus::*)(Message_Status)) &Message_ExecStatus::Set, "Sets a status flag", py::arg("status"));
cls_Message_ExecStatus.def("IsSet", (Standard_Boolean (Message_ExecStatus::*)(Message_Status) const) &Message_ExecStatus::IsSet, "Check status for being set", py::arg("status"));
cls_Message_ExecStatus.def("Clear", (void (Message_ExecStatus::*)(Message_Status)) &Message_ExecStatus::Clear, "Clear one status", py::arg("status"));
cls_Message_ExecStatus.def("IsDone", (Standard_Boolean (Message_ExecStatus::*)() const) &Message_ExecStatus::IsDone, "Check if at least one status of each type is set");
cls_Message_ExecStatus.def("IsFail", (Standard_Boolean (Message_ExecStatus::*)() const) &Message_ExecStatus::IsFail, "None");
cls_Message_ExecStatus.def("IsWarn", (Standard_Boolean (Message_ExecStatus::*)() const) &Message_ExecStatus::IsWarn, "None");
cls_Message_ExecStatus.def("IsAlarm", (Standard_Boolean (Message_ExecStatus::*)() const) &Message_ExecStatus::IsAlarm, "None");
cls_Message_ExecStatus.def("SetAllDone", (void (Message_ExecStatus::*)()) &Message_ExecStatus::SetAllDone, "Set all statuses of each type");
cls_Message_ExecStatus.def("SetAllWarn", (void (Message_ExecStatus::*)()) &Message_ExecStatus::SetAllWarn, "None");
cls_Message_ExecStatus.def("SetAllAlarm", (void (Message_ExecStatus::*)()) &Message_ExecStatus::SetAllAlarm, "None");
cls_Message_ExecStatus.def("SetAllFail", (void (Message_ExecStatus::*)()) &Message_ExecStatus::SetAllFail, "None");
cls_Message_ExecStatus.def("ClearAllDone", (void (Message_ExecStatus::*)()) &Message_ExecStatus::ClearAllDone, "Clear all statuses of each type");
cls_Message_ExecStatus.def("ClearAllWarn", (void (Message_ExecStatus::*)()) &Message_ExecStatus::ClearAllWarn, "None");
cls_Message_ExecStatus.def("ClearAllAlarm", (void (Message_ExecStatus::*)()) &Message_ExecStatus::ClearAllAlarm, "None");
cls_Message_ExecStatus.def("ClearAllFail", (void (Message_ExecStatus::*)()) &Message_ExecStatus::ClearAllFail, "None");
cls_Message_ExecStatus.def("Clear", (void (Message_ExecStatus::*)()) &Message_ExecStatus::Clear, "Clear all statuses");
cls_Message_ExecStatus.def("Add", (void (Message_ExecStatus::*)(const Message_ExecStatus &)) &Message_ExecStatus::Add, "Add statuses to me from theOther execution status", py::arg("theOther"));
cls_Message_ExecStatus.def("operator|=", (const Message_ExecStatus & (Message_ExecStatus::*)(const Message_ExecStatus &)) &Message_ExecStatus::operator|=, "None", py::arg("theOther"));
cls_Message_ExecStatus.def("And", (void (Message_ExecStatus::*)(const Message_ExecStatus &)) &Message_ExecStatus::And, "Leave only the statuses common with theOther", py::arg("theOther"));
cls_Message_ExecStatus.def("operator&=", (const Message_ExecStatus & (Message_ExecStatus::*)(const Message_ExecStatus &)) &Message_ExecStatus::operator&=, "None", py::arg("theOther"));
cls_Message_ExecStatus.def_static("StatusIndex_", (Standard_Integer (*)(Message_Status)) &Message_ExecStatus::StatusIndex, "Returns index of status in whole range [FirstStatus, LastStatus]", py::arg("status"));
cls_Message_ExecStatus.def_static("LocalStatusIndex_", (Standard_Integer (*)(Message_Status)) &Message_ExecStatus::LocalStatusIndex, "Returns index of status inside type of status (Done or Warn or, etc) in range [1, StatusesPerType]", py::arg("status"));
cls_Message_ExecStatus.def_static("TypeOfStatus_", (Message_StatusType (*)(Message_Status)) &Message_ExecStatus::TypeOfStatus, "Returns status type (DONE, WARN, ALARM, or FAIL)", py::arg("status"));
cls_Message_ExecStatus.def_static("StatusByIndex_", (Message_Status (*)(const Standard_Integer)) &Message_ExecStatus::StatusByIndex, "Returns status with index theIndex in whole range [FirstStatus, LastStatus]", py::arg("theIndex"));

// Enums
py::enum_<Message_ExecStatus::StatusRange>(cls_Message_ExecStatus, "StatusRange", "Definitions of range of available statuses")
	.value("FirstStatus", Message_ExecStatus::StatusRange::FirstStatus)
	.value("StatusesPerType", Message_ExecStatus::StatusRange::StatusesPerType)
	.value("NbStatuses", Message_ExecStatus::StatusRange::NbStatuses)
	.value("LastStatus", Message_ExecStatus::StatusRange::LastStatus)
	.export_values();

// CLASS: MESSAGE_MSG
py::class_<Message_Msg> cls_Message_Msg(mod, "Message_Msg", "This class provides a tool for constructing the parametrized message basing on resources loaded by Message_MsgFile tool.");

// Constructors
cls_Message_Msg.def(py::init<>());
cls_Message_Msg.def(py::init<const Message_Msg &>(), py::arg("theMsg"));
cls_Message_Msg.def(py::init<const Standard_CString>(), py::arg("theKey"));
cls_Message_Msg.def(py::init<const TCollection_ExtendedString &>(), py::arg("theKey"));

// Methods
// cls_Message_Msg.def_static("operator new_", (void * (*)(size_t)) &Message_Msg::operator new, "None", py::arg("theSize"));
// cls_Message_Msg.def_static("operator delete_", (void (*)(void *)) &Message_Msg::operator delete, "None", py::arg("theAddress"));
// cls_Message_Msg.def_static("operator new[]_", (void * (*)(size_t)) &Message_Msg::operator new[], "None", py::arg("theSize"));
// cls_Message_Msg.def_static("operator delete[]_", (void (*)(void *)) &Message_Msg::operator delete[], "None", py::arg("theAddress"));
// cls_Message_Msg.def_static("operator new_", (void * (*)(size_t, void *)) &Message_Msg::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Message_Msg.def_static("operator delete_", (void (*)(void *, void *)) &Message_Msg::operator delete, "None", py::arg(""), py::arg(""));
cls_Message_Msg.def("Set", (void (Message_Msg::*)(const Standard_CString)) &Message_Msg::Set, "Set a message body text -- can be used as alternative to using messages from resource file", py::arg("theMsg"));
cls_Message_Msg.def("Set", (void (Message_Msg::*)(const TCollection_ExtendedString &)) &Message_Msg::Set, "Set a message body text -- can be used as alternative to using messages from resource file", py::arg("theMsg"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const Standard_CString)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const Standard_CString)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const TCollection_AsciiString &)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const TCollection_AsciiString &)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const TCollection_ExtendedString &)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const TCollection_ExtendedString &)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const opencascade::handle<TCollection_HExtendedString> &)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const opencascade::handle<TCollection_HExtendedString> &)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const Standard_Integer)) &Message_Msg::Arg, "Set a value for %..d, %..i, %..o, %..u, %..x or %..X conversion", py::arg("theInt"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const Standard_Integer)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theInt"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const Standard_Real)) &Message_Msg::Arg, "Set a value for %..f, %..e, %..E, %..g or %..G conversion", py::arg("theReal"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const Standard_Real)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theReal"));
cls_Message_Msg.def("Original", (const TCollection_ExtendedString & (Message_Msg::*)() const) &Message_Msg::Original, "Returns the original message text");
cls_Message_Msg.def("Value", (const TCollection_ExtendedString & (Message_Msg::*)() const) &Message_Msg::Value, "Returns current state of the message text with parameters to the moment");
cls_Message_Msg.def("IsEdited", (Standard_Boolean (Message_Msg::*)() const) &Message_Msg::IsEdited, "Tells if Value differs from Original");
cls_Message_Msg.def("Get", (const TCollection_ExtendedString & (Message_Msg::*)()) &Message_Msg::Get, "Return the resulting message string with all parameters filled. If some parameters were not yet filled by calls to methods Arg (or <<), these parameters are filled by the word UNKNOWN");

// TYPEDEF: MESSAGE_ARRAYOFMSG
bind_NCollection_Array1<NCollection_Handle<Message_Msg> >(mod, "Message_ArrayOfMsg", py::module_local(false));

// TYPEDEF: MESSAGE_HARRAYOFMSG
bind_NCollection_Handle<NCollection_Array1<NCollection_Handle<Message_Msg> > >(mod, "Message_HArrayOfMsg", py::module_local(false));

// CLASS: MESSAGE_ALGORITHM
py::class_<Message_Algorithm, opencascade::handle<Message_Algorithm>, Standard_Transient> cls_Message_Algorithm(mod, "Message_Algorithm", "Class Message_Algorithm is intended to be the base class for classes implementing algorithms or any operations that need to provide extended information on its execution to the caller / user.");

// Constructors
cls_Message_Algorithm.def(py::init<>());

// Methods
cls_Message_Algorithm.def("SetStatus", (void (Message_Algorithm::*)(const Message_Status &)) &Message_Algorithm::SetStatus, "Sets status with no parameter", py::arg("theStat"));
cls_Message_Algorithm.def("SetStatus", (void (Message_Algorithm::*)(const Message_Status &, const Standard_Integer)) &Message_Algorithm::SetStatus, "Sets status with integer parameter", py::arg("theStat"), py::arg("theInt"));
cls_Message_Algorithm.def("SetStatus", [](Message_Algorithm &self, const Message_Status & a0, const Standard_CString a1) -> void { return self.SetStatus(a0, a1); });
cls_Message_Algorithm.def("SetStatus", (void (Message_Algorithm::*)(const Message_Status &, const Standard_CString, const Standard_Boolean)) &Message_Algorithm::SetStatus, "Sets status with string parameter. If noRepetitions is True, the parameter will be added only if it has not been yet recorded for the same status flag", py::arg("theStat"), py::arg("theStr"), py::arg("noRepetitions"));
cls_Message_Algorithm.def("SetStatus", [](Message_Algorithm &self, const Message_Status & a0, const TCollection_AsciiString & a1) -> void { return self.SetStatus(a0, a1); });
cls_Message_Algorithm.def("SetStatus", (void (Message_Algorithm::*)(const Message_Status &, const TCollection_AsciiString &, const Standard_Boolean)) &Message_Algorithm::SetStatus, "Sets status with string parameter If noRepetitions is True, the parameter will be added only if it has not been yet recorded for the same status flag", py::arg("theStat"), py::arg("theStr"), py::arg("noRepetitions"));
cls_Message_Algorithm.def("SetStatus", [](Message_Algorithm &self, const Message_Status & a0, const opencascade::handle<TCollection_HAsciiString> & a1) -> void { return self.SetStatus(a0, a1); });
cls_Message_Algorithm.def("SetStatus", (void (Message_Algorithm::*)(const Message_Status &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean)) &Message_Algorithm::SetStatus, "Sets status with string parameter If noRepetitions is True, the parameter will be added only if it has not been yet recorded for the same status flag", py::arg("theStat"), py::arg("theStr"), py::arg("noRepetitions"));
cls_Message_Algorithm.def("SetStatus", [](Message_Algorithm &self, const Message_Status & a0, const TCollection_ExtendedString & a1) -> void { return self.SetStatus(a0, a1); });
cls_Message_Algorithm.def("SetStatus", (void (Message_Algorithm::*)(const Message_Status &, const TCollection_ExtendedString &, const Standard_Boolean)) &Message_Algorithm::SetStatus, "Sets status with string parameter If noRepetitions is True, the parameter will be added only if it has not been yet recorded for the same status flag", py::arg("theStat"), py::arg("theStr"), py::arg("noRepetitions"));
cls_Message_Algorithm.def("SetStatus", [](Message_Algorithm &self, const Message_Status & a0, const opencascade::handle<TCollection_HExtendedString> & a1) -> void { return self.SetStatus(a0, a1); });
cls_Message_Algorithm.def("SetStatus", (void (Message_Algorithm::*)(const Message_Status &, const opencascade::handle<TCollection_HExtendedString> &, const Standard_Boolean)) &Message_Algorithm::SetStatus, "Sets status with string parameter If noRepetitions is True, the parameter will be added only if it has not been yet recorded for the same status flag", py::arg("theStat"), py::arg("theStr"), py::arg("noRepetitions"));
cls_Message_Algorithm.def("SetStatus", (void (Message_Algorithm::*)(const Message_Status &, const Message_Msg &)) &Message_Algorithm::SetStatus, "Sets status with preformatted message. This message will be used directly to report the status; automatic generation of status messages will be disabled for it.", py::arg("theStat"), py::arg("theMsg"));
cls_Message_Algorithm.def("GetStatus", (const Message_ExecStatus & (Message_Algorithm::*)() const) &Message_Algorithm::GetStatus, "Returns copy of exec status of algorithm");
cls_Message_Algorithm.def("ChangeStatus", (Message_ExecStatus & (Message_Algorithm::*)()) &Message_Algorithm::ChangeStatus, "Returns exec status of algorithm");
cls_Message_Algorithm.def("ClearStatus", (void (Message_Algorithm::*)()) &Message_Algorithm::ClearStatus, "Clear exec status of algorithm");
cls_Message_Algorithm.def("SetMessenger", (void (Message_Algorithm::*)(const opencascade::handle<Message_Messenger> &)) &Message_Algorithm::SetMessenger, "Sets messenger to algorithm", py::arg("theMsgr"));
cls_Message_Algorithm.def("GetMessenger", (opencascade::handle<Message_Messenger> (Message_Algorithm::*)() const) &Message_Algorithm::GetMessenger, "Returns messenger of algorithm. The returned handle is always non-null and can be used for sending messages.");
cls_Message_Algorithm.def("SendStatusMessages", [](Message_Algorithm &self, const Message_ExecStatus & a0) -> void { return self.SendStatusMessages(a0); });
cls_Message_Algorithm.def("SendStatusMessages", [](Message_Algorithm &self, const Message_ExecStatus & a0, const Message_Gravity a1) -> void { return self.SendStatusMessages(a0, a1); });
cls_Message_Algorithm.def("SendStatusMessages", (void (Message_Algorithm::*)(const Message_ExecStatus &, const Message_Gravity, const Standard_Integer) const) &Message_Algorithm::SendStatusMessages, "Print messages for all status flags that have been set during algorithm execution, excluding statuses that are NOT set in theFilter.", py::arg("theFilter"), py::arg("theTraceLevel"), py::arg("theMaxCount"));
cls_Message_Algorithm.def("SendMessages", [](Message_Algorithm &self) -> void { return self.SendMessages(); });
cls_Message_Algorithm.def("SendMessages", [](Message_Algorithm &self, const Message_Gravity a0) -> void { return self.SendMessages(a0); });
cls_Message_Algorithm.def("SendMessages", (void (Message_Algorithm::*)(const Message_Gravity, const Standard_Integer) const) &Message_Algorithm::SendMessages, "Convenient variant of SendStatusMessages() with theFilter having defined all WARN, ALARM, and FAIL (but not DONE) status flags", py::arg("theTraceLevel"), py::arg("theMaxCount"));
cls_Message_Algorithm.def("AddStatus", (void (Message_Algorithm::*)(const opencascade::handle<Message_Algorithm> &)) &Message_Algorithm::AddStatus, "Add statuses to this algorithm from other algorithm (including messages)", py::arg("theOther"));
cls_Message_Algorithm.def("AddStatus", (void (Message_Algorithm::*)(const Message_ExecStatus &, const opencascade::handle<Message_Algorithm> &)) &Message_Algorithm::AddStatus, "Add statuses to this algorithm from other algorithm, but only those items are moved that correspond to statuses set in theStatus", py::arg("theStatus"), py::arg("theOther"));
cls_Message_Algorithm.def("GetMessageNumbers", (opencascade::handle<TColStd_HPackedMapOfInteger> (Message_Algorithm::*)(const Message_Status &) const) &Message_Algorithm::GetMessageNumbers, "Return the numbers associated with the indicated status; Null handle if no such status or no numbers associated with it", py::arg("theStatus"));
cls_Message_Algorithm.def("GetMessageStrings", (opencascade::handle<TColStd_HSequenceOfHExtendedString> (Message_Algorithm::*)(const Message_Status &) const) &Message_Algorithm::GetMessageStrings, "Return the strings associated with the indicated status; Null handle if no such status or no strings associated with it", py::arg("theStatus"));
cls_Message_Algorithm.def_static("PrepareReport_", (TCollection_ExtendedString (*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &, const Standard_Integer)) &Message_Algorithm::PrepareReport, "Prepares a string containing a list of integers contained in theError map, but not more than theMaxCount", py::arg("theError"), py::arg("theMaxCount"));
cls_Message_Algorithm.def_static("PrepareReport_", (TCollection_ExtendedString (*)(const TColStd_SequenceOfHExtendedString &, const Standard_Integer)) &Message_Algorithm::PrepareReport, "Prepares a string containing a list of names contained in theReportSeq sequence, but not more than theMaxCount", py::arg("theReportSeq"), py::arg("theMaxCount"));
cls_Message_Algorithm.def_static("get_type_name_", (const char * (*)()) &Message_Algorithm::get_type_name, "None");
cls_Message_Algorithm.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_Algorithm::get_type_descriptor, "None");
cls_Message_Algorithm.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_Algorithm::*)() const) &Message_Algorithm::DynamicType, "None");

// CLASS: MESSAGE
py::class_<Message> cls_Message(mod, "Message", "Defines - tools to work with messages - basic tools intended for progress indication");

// Constructors
cls_Message.def(py::init<>());

// Methods
// cls_Message.def_static("operator new_", (void * (*)(size_t)) &Message::operator new, "None", py::arg("theSize"));
// cls_Message.def_static("operator delete_", (void (*)(void *)) &Message::operator delete, "None", py::arg("theAddress"));
// cls_Message.def_static("operator new[]_", (void * (*)(size_t)) &Message::operator new[], "None", py::arg("theSize"));
// cls_Message.def_static("operator delete[]_", (void (*)(void *)) &Message::operator delete[], "None", py::arg("theAddress"));
// cls_Message.def_static("operator new_", (void * (*)(size_t, void *)) &Message::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Message.def_static("operator delete_", (void (*)(void *, void *)) &Message::operator delete, "None", py::arg(""), py::arg(""));
cls_Message.def_static("DefaultMessenger_", (const opencascade::handle<Message_Messenger> & (*)()) &Message::DefaultMessenger, "Defines default messenger for OCCT applications. This is global static instance of the messenger. By default, it contains single printer directed to std::cout. It can be customized according to the application needs.");
cls_Message.def_static("FillTime_", (TCollection_AsciiString (*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &Message::FillTime, "Returns the string filled with values of hours, minutes and seconds. Example: 1. (5, 12, 26.3345) returns '05h:12m:26.33s', 2. (0, 6, 34.496 ) returns '06m:34.50s', 3. (0, 0, 4.5 ) returns '4.50s'", py::arg("Hour"), py::arg("Minute"), py::arg("Second"));

// TYPEDEF: MESSAGE_LISTOFMSG
bind_NCollection_List<Message_Msg>(mod, "Message_ListOfMsg", py::module_local(false));

// TYPEDEF: MESSAGE_LISTITERATOROFLISTOFMSG
bind_NCollection_TListIterator<Message_Msg>(mod, "Message_ListIteratorOfListOfMsg", py::module_local(false));

// CLASS: MESSAGE_MSGFILE
py::class_<Message_MsgFile> cls_Message_MsgFile(mod, "Message_MsgFile", "A tool providing facility to load definitions of message strings from resource file(s).");

// Constructors
cls_Message_MsgFile.def(py::init<>());

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

// CLASS: MESSAGE_PRINTEROSTREAM
py::class_<Message_PrinterOStream, opencascade::handle<Message_PrinterOStream>, Message_Printer> cls_Message_PrinterOStream(mod, "Message_PrinterOStream", "Implementation of a message printer associated with an std::ostream The std::ostream may be either externally defined one (e.g. std::cout), or file stream maintained internally (depending on constructor).");

// Constructors
cls_Message_PrinterOStream.def(py::init<>());
cls_Message_PrinterOStream.def(py::init<const Message_Gravity>(), py::arg("theTraceLevel"));
cls_Message_PrinterOStream.def(py::init<const Standard_CString, const Standard_Boolean>(), py::arg("theFileName"), py::arg("theDoAppend"));
cls_Message_PrinterOStream.def(py::init<const Standard_CString, const Standard_Boolean, const Message_Gravity>(), py::arg("theFileName"), py::arg("theDoAppend"), py::arg("theTraceLevel"));

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

// CLASS: MESSAGE_PROGRESSSENTRY
py::class_<Message_ProgressSentry> cls_Message_ProgressSentry(mod, "Message_ProgressSentry", "This class is a tool allowing to manage opening/closing scopes in the ProgressIndicator in convenient and safe way.");

// Constructors
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const Standard_CString, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const Standard_CString, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const Standard_CString, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"), py::arg("newScopeSpan"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"), py::arg("newScopeSpan"));

// Methods
// cls_Message_ProgressSentry.def_static("operator new_", (void * (*)(size_t)) &Message_ProgressSentry::operator new, "None", py::arg("theSize"));
// cls_Message_ProgressSentry.def_static("operator delete_", (void (*)(void *)) &Message_ProgressSentry::operator delete, "None", py::arg("theAddress"));
// cls_Message_ProgressSentry.def_static("operator new[]_", (void * (*)(size_t)) &Message_ProgressSentry::operator new[], "None", py::arg("theSize"));
// cls_Message_ProgressSentry.def_static("operator delete[]_", (void (*)(void *)) &Message_ProgressSentry::operator delete[], "None", py::arg("theAddress"));
// cls_Message_ProgressSentry.def_static("operator new_", (void * (*)(size_t, void *)) &Message_ProgressSentry::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Message_ProgressSentry.def_static("operator delete_", (void (*)(void *, void *)) &Message_ProgressSentry::operator delete, "None", py::arg(""), py::arg(""));
cls_Message_ProgressSentry.def("Relieve", (void (Message_ProgressSentry::*)()) &Message_ProgressSentry::Relieve, "Moves progress indicator to the end of the current scale and relieves sentry from its duty. Methods other than Show() will do nothing after this one is called.");
cls_Message_ProgressSentry.def("Next", [](Message_ProgressSentry &self) -> void { return self.Next(); });
cls_Message_ProgressSentry.def("Next", (void (Message_ProgressSentry::*)(const Standard_CString) const) &Message_ProgressSentry::Next, "None", py::arg("name"));
cls_Message_ProgressSentry.def("Next", [](Message_ProgressSentry &self, const Standard_Real a0) -> void { return self.Next(a0); });
cls_Message_ProgressSentry.def("Next", (void (Message_ProgressSentry::*)(const Standard_Real, const Standard_CString) const) &Message_ProgressSentry::Next, "None", py::arg("span"), py::arg("name"));
cls_Message_ProgressSentry.def("Next", (void (Message_ProgressSentry::*)(const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &) const) &Message_ProgressSentry::Next, "Closes current scope and opens next one with either specified or default span", py::arg("span"), py::arg("name"));
cls_Message_ProgressSentry.def("More", (Standard_Boolean (Message_ProgressSentry::*)() const) &Message_ProgressSentry::More, "Returns False if ProgressIndicator signals UserBreak");
cls_Message_ProgressSentry.def("Show", (void (Message_ProgressSentry::*)() const) &Message_ProgressSentry::Show, "Forces update of progress indicator display");


}
