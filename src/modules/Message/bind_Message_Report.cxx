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
#include <Message_Gravity.hxx>
#include <Standard_Handle.hxx>
#include <Message_Alert.hxx>
#include <Message_ListOfAlert.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <Standard_OStream.hxx>
#include <Message_Messenger.hxx>
#include <Message_Report.hxx>
#include <Standard_Mutex.hxx>

void bind_Message_Report(py::module &mod){

py::class_<Message_Report, opencascade::handle<Message_Report>, Standard_Transient> cls_Message_Report(mod, "Message_Report", "Container for alert messages, sorted according to their gravity.");

// Constructors
cls_Message_Report.def(py::init<>());

// Fields

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

// Enums

}