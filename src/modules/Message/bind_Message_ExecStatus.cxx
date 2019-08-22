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
#include <Message_Status.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_ExecStatus.hxx>
#include <Message_StatusType.hxx>

void bind_Message_ExecStatus(py::module &mod){

py::class_<Message_ExecStatus> cls_Message_ExecStatus(mod, "Message_ExecStatus", "Tiny class for extended handling of error / execution status of algorithm in universal way.");

// Constructors
cls_Message_ExecStatus.def(py::init<>());
cls_Message_ExecStatus.def(py::init<Message_Status>(), py::arg("status"));

// Fields

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

}