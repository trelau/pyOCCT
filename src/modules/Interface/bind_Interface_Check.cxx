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
#include <Message_Msg.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Interface_CheckStatus.hxx>
#include <Interface_Check.hxx>
#include <Message_Messenger.hxx>
#include <Standard_Type.hxx>

void bind_Interface_Check(py::module &mod){

py::class_<Interface_Check, opencascade::handle<Interface_Check>, Standard_Transient> cls_Interface_Check(mod, "Interface_Check", "Defines a Check, as a list of Fail or Warning Messages under a literal form, which can be empty. A Check can also bring an Entity, which is the Entity to which the messages apply (this Entity may be any Transient Object).");

// Constructors
cls_Interface_Check.def(py::init<>());
cls_Interface_Check.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("anentity"));

// Fields

// Methods
cls_Interface_Check.def("SendFail", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::SendFail, "New name for AddFail (Msg)", py::arg("amsg"));
cls_Interface_Check.def("AddFail", (void (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Interface_Check::AddFail, "Records a new Fail message", py::arg("amess"));
cls_Interface_Check.def("AddFail", (void (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &Interface_Check::AddFail, "Records a new Fail message under two forms : final,original", py::arg("amess"), py::arg("orig"));
cls_Interface_Check.def("AddFail", [](Interface_Check &self, const Standard_CString a0) -> void { return self.AddFail(a0); });
cls_Interface_Check.def("AddFail", (void (Interface_Check::*)(const Standard_CString, const Standard_CString)) &Interface_Check::AddFail, "Records a new Fail message given as 'error text' directly If <orig> is given, a distinct original form is recorded else (D), the original form equates <amess>", py::arg("amess"), py::arg("orig"));
cls_Interface_Check.def("AddFail", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::AddFail, "Records a new Fail from the definition of a Msg (Original+Value)", py::arg("amsg"));
cls_Interface_Check.def("HasFailed", (Standard_Boolean (Interface_Check::*)() const) &Interface_Check::HasFailed, "Returns True if Check brings at least one Fail Message");
cls_Interface_Check.def("NbFails", (Standard_Integer (Interface_Check::*)() const) &Interface_Check::NbFails, "Returns count of recorded Fails");
cls_Interface_Check.def("Fail", [](Interface_Check &self, const Standard_Integer a0) -> const opencascade::handle<TCollection_HAsciiString> & { return self.Fail(a0); });
cls_Interface_Check.def("Fail", (const opencascade::handle<TCollection_HAsciiString> & (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::Fail, "Returns Fail Message as a String Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("CFail", [](Interface_Check &self, const Standard_Integer a0) -> Standard_CString { return self.CFail(a0); });
cls_Interface_Check.def("CFail", (Standard_CString (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::CFail, "Same as above, but returns a CString (to be printed ...) Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("Fails", [](Interface_Check &self) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return self.Fails(); });
cls_Interface_Check.def("Fails", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (Interface_Check::*)(const Standard_Boolean) const) &Interface_Check::Fails, "Returns the list of Fails, for a frontal-engine logic Final forms by default, Original forms if <final> is False Can be empty", py::arg("final"));
cls_Interface_Check.def("SendWarning", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::SendWarning, "New name for AddWarning", py::arg("amsg"));
cls_Interface_Check.def("AddWarning", (void (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Interface_Check::AddWarning, "Records a new Warning message", py::arg("amess"));
cls_Interface_Check.def("AddWarning", (void (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &Interface_Check::AddWarning, "Records a new Warning message under two forms : final,original", py::arg("amess"), py::arg("orig"));
cls_Interface_Check.def("AddWarning", [](Interface_Check &self, const Standard_CString a0) -> void { return self.AddWarning(a0); });
cls_Interface_Check.def("AddWarning", (void (Interface_Check::*)(const Standard_CString, const Standard_CString)) &Interface_Check::AddWarning, "Records a Warning message given as 'warning message' directly If <orig> is given, a distinct original form is recorded else (D), the original form equates <amess>", py::arg("amess"), py::arg("orig"));
cls_Interface_Check.def("AddWarning", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::AddWarning, "Records a new Warning from the definition of a Msg (Original+Value)", py::arg("amsg"));
cls_Interface_Check.def("HasWarnings", (Standard_Boolean (Interface_Check::*)() const) &Interface_Check::HasWarnings, "Returns True if Check brings at least one Warning Message");
cls_Interface_Check.def("NbWarnings", (Standard_Integer (Interface_Check::*)() const) &Interface_Check::NbWarnings, "Returns count of recorded Warning messages");
cls_Interface_Check.def("Warning", [](Interface_Check &self, const Standard_Integer a0) -> const opencascade::handle<TCollection_HAsciiString> & { return self.Warning(a0); });
cls_Interface_Check.def("Warning", (const opencascade::handle<TCollection_HAsciiString> & (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::Warning, "Returns Warning message as a String Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("CWarning", [](Interface_Check &self, const Standard_Integer a0) -> Standard_CString { return self.CWarning(a0); });
cls_Interface_Check.def("CWarning", (Standard_CString (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::CWarning, "Same as above, but returns a CString (to be printed ...) Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("Warnings", [](Interface_Check &self) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return self.Warnings(); });
cls_Interface_Check.def("Warnings", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (Interface_Check::*)(const Standard_Boolean) const) &Interface_Check::Warnings, "Returns the list of Warnings, for a frontal-engine logic Final forms by default, Original forms if <final> is False Can be empty", py::arg("final"));
cls_Interface_Check.def("SendMsg", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::SendMsg, "Records an information message This does not change the status of the Check", py::arg("amsg"));
cls_Interface_Check.def("NbInfoMsgs", (Standard_Integer (Interface_Check::*)() const) &Interface_Check::NbInfoMsgs, "Returns the count of recorded information messages");
cls_Interface_Check.def("InfoMsg", [](Interface_Check &self, const Standard_Integer a0) -> const opencascade::handle<TCollection_HAsciiString> & { return self.InfoMsg(a0); });
cls_Interface_Check.def("InfoMsg", (const opencascade::handle<TCollection_HAsciiString> & (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::InfoMsg, "Returns information message as a String", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("CInfoMsg", [](Interface_Check &self, const Standard_Integer a0) -> Standard_CString { return self.CInfoMsg(a0); });
cls_Interface_Check.def("CInfoMsg", (Standard_CString (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::CInfoMsg, "Same as above, but returns a CString (to be printed ...) Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("InfoMsgs", [](Interface_Check &self) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return self.InfoMsgs(); });
cls_Interface_Check.def("InfoMsgs", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (Interface_Check::*)(const Standard_Boolean) const) &Interface_Check::InfoMsgs, "Returns the list of Info Msg, for a frontal-engine logic Final forms by default, Original forms if <final> is False Can be empty", py::arg("final"));
cls_Interface_Check.def("Status", (Interface_CheckStatus (Interface_Check::*)() const) &Interface_Check::Status, "Returns the Check Status : OK, Warning or Fail");
cls_Interface_Check.def("Complies", (Standard_Boolean (Interface_Check::*)(const Interface_CheckStatus) const) &Interface_Check::Complies, "Tells if Check Status complies with a given one (i.e. also status for query)", py::arg("status"));
cls_Interface_Check.def("Complies", (Standard_Boolean (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Interface_CheckStatus) const) &Interface_Check::Complies, "Tells if a message is brought by a Check, as follows : <incl> = 0 : <mess> exactly matches one of the messages <incl> < 0 : <mess> is contained by one of the messages <incl> > 0 : <mess> contains one of the messages For <status> : for CheckWarning and CheckFail, considers only resp. Warning or Check messages. for CheckAny, considers all other values are ignored (answer will be false)", py::arg("mess"), py::arg("incl"), py::arg("status"));
cls_Interface_Check.def("HasEntity", (Standard_Boolean (Interface_Check::*)() const) &Interface_Check::HasEntity, "Returns True if a Check is devoted to an entity; else, it is global (for InterfaceModel's storing of global error messages)");
cls_Interface_Check.def("Entity", (const opencascade::handle<Standard_Transient> & (Interface_Check::*)() const) &Interface_Check::Entity, "Returns the entity on which the Check has been defined");
cls_Interface_Check.def("Clear", (void (Interface_Check::*)()) &Interface_Check::Clear, "Clears a check, in order to receive informations from transfer (Messages and Entity)");
cls_Interface_Check.def("ClearFails", (void (Interface_Check::*)()) &Interface_Check::ClearFails, "Clears the Fail Messages (for instance to keep only Warnings)");
cls_Interface_Check.def("ClearWarnings", (void (Interface_Check::*)()) &Interface_Check::ClearWarnings, "Clears the Warning Messages (for instance to keep only Fails)");
cls_Interface_Check.def("ClearInfoMsgs", (void (Interface_Check::*)()) &Interface_Check::ClearInfoMsgs, "Clears the Info Messages");
cls_Interface_Check.def("Remove", (Standard_Boolean (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Interface_CheckStatus)) &Interface_Check::Remove, "Removes the messages which comply with <mess>, as follows : <incl> = 0 : <mess> exactly matches one of the messages <incl> < 0 : <mess> is contained by one of the messages <incl> > 0 : <mess> contains one of the messages For <status> : for CheckWarning and CheckFail, considers only resp. Warning or Check messages. for CheckAny, considers all other values are ignored (nothing is done) Returns True if at least one message has been removed, False else", py::arg("mess"), py::arg("incl"), py::arg("status"));
cls_Interface_Check.def("Mend", [](Interface_Check &self, const Standard_CString a0) -> Standard_Boolean { return self.Mend(a0); });
cls_Interface_Check.def("Mend", (Standard_Boolean (Interface_Check::*)(const Standard_CString, const Standard_Integer)) &Interface_Check::Mend, "Mends messages, according <pref> and <num> According to <num>, works on the whole list of Fails if = 0(D) or only one Fail message, given its rank If <pref> is empty, converts Fail(s) to Warning(s) Else, does the conversion but prefixes the new Warning(s) but <pref> followed by a semi-column Some reserved values of <pref> are : 'FM' : standard prefix 'Mended' (can be translated) 'CF' : clears Fail(s) 'CW' : clears Warning(s) : here, <num> refers to Warning list 'CA' : clears all messages : here, <num> is ignored", py::arg("pref"), py::arg("num"));
cls_Interface_Check.def("SetEntity", (void (Interface_Check::*)(const opencascade::handle<Standard_Transient> &)) &Interface_Check::SetEntity, "Receives an entity result of a Transfer", py::arg("anentity"));
cls_Interface_Check.def("GetEntity", (void (Interface_Check::*)(const opencascade::handle<Standard_Transient> &)) &Interface_Check::GetEntity, "same as SetEntity (old form kept for compatibility) Warning : Does nothing if Entity field is not yet clear", py::arg("anentity"));
cls_Interface_Check.def("GetMessages", (void (Interface_Check::*)(const opencascade::handle<Interface_Check> &)) &Interface_Check::GetMessages, "Copies messages stored in another Check, cumulating Does not regard other's Entity. Used to cumulate messages", py::arg("other"));
cls_Interface_Check.def("GetAsWarning", (void (Interface_Check::*)(const opencascade::handle<Interface_Check> &, const Standard_Boolean)) &Interface_Check::GetAsWarning, "Copies messages converted into Warning messages If failsonly is true, only Fails are taken, and converted else, Warnings are taken too. Does not regard Entity Used to keep Fail messages as Warning, after a recovery", py::arg("other"), py::arg("failsonly"));
cls_Interface_Check.def("Print", [](Interface_Check &self, const opencascade::handle<Message_Messenger> & a0, const Standard_Integer a1) -> void { return self.Print(a0, a1); });
cls_Interface_Check.def("Print", (void (Interface_Check::*)(const opencascade::handle<Message_Messenger> &, const Standard_Integer, const Standard_Integer) const) &Interface_Check::Print, "Prints the messages of the check to an Messenger <level> = 1 : only fails <level> = 2 : fails and warnings <level> = 3 : all (fails, warnings, info msg) <final> : if positive (D) prints final values of messages if negative, prints originals if null, prints both forms", py::arg("S"), py::arg("level"), py::arg("final"));
cls_Interface_Check.def("Trace", [](Interface_Check &self) -> void { return self.Trace(); });
cls_Interface_Check.def("Trace", [](Interface_Check &self, const Standard_Integer a0) -> void { return self.Trace(a0); });
cls_Interface_Check.def("Trace", (void (Interface_Check::*)(const Standard_Integer, const Standard_Integer) const) &Interface_Check::Trace, "Prints the messages of the check to the default trace file By default, according to the default standard level Else, according level (see method Print)", py::arg("level"), py::arg("final"));
cls_Interface_Check.def_static("get_type_name_", (const char * (*)()) &Interface_Check::get_type_name, "None");
cls_Interface_Check.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_Check::get_type_descriptor, "None");
cls_Interface_Check.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_Check::*)() const) &Interface_Check::DynamicType, "None");

// Enums

}