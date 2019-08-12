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
#include <Message_Status.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <Message_Msg.hxx>
#include <Message_ExecStatus.hxx>
#include <Message_Messenger.hxx>
#include <Message_Gravity.hxx>
#include <Message_Algorithm.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <TColStd_HSequenceOfHExtendedString.hxx>
#include <TColStd_SequenceOfHExtendedString.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <Message_HArrayOfMsg.hxx>

void bind_Message_Algorithm(py::module &mod){

py::class_<Message_Algorithm, opencascade::handle<Message_Algorithm>, Standard_Transient> cls_Message_Algorithm(mod, "Message_Algorithm", "Class Message_Algorithm is intended to be the base class for classes implementing algorithms or any operations that need to provide extended information on its execution to the caller / user.");

// Constructors
cls_Message_Algorithm.def(py::init<>());

// Fields

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

// Enums

}