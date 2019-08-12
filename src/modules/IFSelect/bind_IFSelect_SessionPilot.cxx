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
#include <IFSelect_Activator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_WorkSession.hxx>
#include <IFSelect_WorkLibrary.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <Standard_Transient.hxx>
#include <IFSelect_SignCounter.hxx>
#include <IFSelect_PrintCount.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfAsciiString.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>

void bind_IFSelect_SessionPilot(py::module &mod){

py::class_<IFSelect_SessionPilot, opencascade::handle<IFSelect_SessionPilot>, IFSelect_Activator> cls_IFSelect_SessionPilot(mod, "IFSelect_SessionPilot", "A SessionPilot is intended to make easier the use of a WorkSession. It receives commands, under alphanumeric form, then calls a library of Activators to interprete and run them.");

// Constructors
cls_IFSelect_SessionPilot.def(py::init<>());
cls_IFSelect_SessionPilot.def(py::init<const Standard_CString>(), py::arg("prompt"));

// Fields

// Methods
cls_IFSelect_SessionPilot.def("Session", (opencascade::handle<IFSelect_WorkSession> (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::Session, "Returns the WorkSession which is worked on");
cls_IFSelect_SessionPilot.def("Library", (opencascade::handle<IFSelect_WorkLibrary> (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::Library, "Returns the WorKlibrary (Null if not set). WorkLibrary is used to Read and Write Files, according to the Norm");
cls_IFSelect_SessionPilot.def("RecordMode", (Standard_Boolean (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::RecordMode, "Returns the Record Mode for Commands. Default is False.");
cls_IFSelect_SessionPilot.def("SetSession", (void (IFSelect_SessionPilot::*)(const opencascade::handle<IFSelect_WorkSession> &)) &IFSelect_SessionPilot::SetSession, "Sets a WorkSession to be worked on", py::arg("WS"));
cls_IFSelect_SessionPilot.def("SetLibrary", (void (IFSelect_SessionPilot::*)(const opencascade::handle<IFSelect_WorkLibrary> &)) &IFSelect_SessionPilot::SetLibrary, "Sets a WorkLibrary", py::arg("WL"));
cls_IFSelect_SessionPilot.def("SetRecordMode", (void (IFSelect_SessionPilot::*)(const Standard_Boolean)) &IFSelect_SessionPilot::SetRecordMode, "Changes the RecordMode.", py::arg("mode"));
cls_IFSelect_SessionPilot.def("SetCommandLine", (void (IFSelect_SessionPilot::*)(const TCollection_AsciiString &)) &IFSelect_SessionPilot::SetCommandLine, "Sets the value of the Command Line to be interpreted Also prepares the interpretation (splitting by blanks)", py::arg("command"));
cls_IFSelect_SessionPilot.def("CommandLine", (const TCollection_AsciiString & (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::CommandLine, "Returns the Command Line to be interpreted");
cls_IFSelect_SessionPilot.def("CommandPart", [](IFSelect_SessionPilot &self) -> Standard_CString { return self.CommandPart(); });
cls_IFSelect_SessionPilot.def("CommandPart", (Standard_CString (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::CommandPart, "Returns the part of the command line which begins at argument <numarg> between 0 and NbWords-1 (by default, all the line) Empty string if out of range", py::arg("numarg"));
cls_IFSelect_SessionPilot.def("NbWords", (Standard_Integer (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::NbWords, "Returns the count of words of the Command Line, separated by blanks : 0 if empty, one if a command without args, else it gives the count of args minus one. Warning : limited to 10 (command title + 9 args)");
cls_IFSelect_SessionPilot.def("Word", (const TCollection_AsciiString & (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::Word, "Returns a word given its rank in the Command Line. Begins at 0 which is the Command Title, 1 is the 1st arg., etc...", py::arg("num"));
cls_IFSelect_SessionPilot.def("Arg", (Standard_CString (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::Arg, "Returns a word given its rank, as a CString. As for Word, begins at 0 (the command name), etc...", py::arg("num"));
cls_IFSelect_SessionPilot.def("RemoveWord", (Standard_Boolean (IFSelect_SessionPilot::*)(const Standard_Integer)) &IFSelect_SessionPilot::RemoveWord, "Removes a word given its rank. Returns True if Done, False if <num> is out of range", py::arg("num"));
cls_IFSelect_SessionPilot.def("NbCommands", (Standard_Integer (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::NbCommands, "Returns the count of recorded Commands");
cls_IFSelect_SessionPilot.def("Command", (const TCollection_AsciiString & (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::Command, "Returns a recorded Command, given its rank (from 1)", py::arg("num"));
cls_IFSelect_SessionPilot.def("RecordItem", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SessionPilot::RecordItem, "Allows to associate a Transient Value with the last execution as a partial result Returns RetDone if item is not Null, RetFail if item is Null Remark : it is nullified for each Perform", py::arg("item"));
cls_IFSelect_SessionPilot.def("RecordedItem", (opencascade::handle<Standard_Transient> (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::RecordedItem, "Returns the Transient Object which was recorded with the current Line Command. If none was, returns a Null Handle");
cls_IFSelect_SessionPilot.def("Clear", (void (IFSelect_SessionPilot::*)()) &IFSelect_SessionPilot::Clear, "Clears the recorded informations (commands, objects)");
cls_IFSelect_SessionPilot.def("ReadScript", [](IFSelect_SessionPilot &self) -> IFSelect_ReturnStatus { return self.ReadScript(); });
cls_IFSelect_SessionPilot.def("ReadScript", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const Standard_CString)) &IFSelect_SessionPilot::ReadScript, "Reads commands from a Script File, named <file>. By default (file = ''), reads from standard input with a prompt Else (reading from a file), the read commands are displayed onto standard output. Allows nested reads. Reading is stopped either by command x or exit, or by reaching end of file Return Value follows the rules of Do : RetEnd for normal end, RetFail if script could not be opened", py::arg("file"));
cls_IFSelect_SessionPilot.def("Perform", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)()) &IFSelect_SessionPilot::Perform, "Executes the Command, itself (for built-in commands, which have priority) or by using the list of Activators. The value returned is : RetVoid if nothing done (void command) RetDone if execution OK, RetEnd if END OF SESSION, RetError if command unknown or incorrect, RetFail if error on execution If execution is OK and RecordMode is set, this Command Line is recorded to the list (see below).");
cls_IFSelect_SessionPilot.def("ExecuteAlias", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const TCollection_AsciiString &)) &IFSelect_SessionPilot::ExecuteAlias, "Executes the Commands, except that the command name (word 0) is aliased. The rest of the command line is unchanged If <alias> is empty, Executes with no change", py::arg("aliasname"));
cls_IFSelect_SessionPilot.def("Execute", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const TCollection_AsciiString &)) &IFSelect_SessionPilot::Execute, "Sets the Command then tries to execute it. Return value : same as for Perform", py::arg("command"));
cls_IFSelect_SessionPilot.def("ExecuteCounter", [](IFSelect_SessionPilot &self, const opencascade::handle<IFSelect_SignCounter> & a0, const Standard_Integer a1) -> IFSelect_ReturnStatus { return self.ExecuteCounter(a0, a1); });
cls_IFSelect_SessionPilot.def("ExecuteCounter", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const opencascade::handle<IFSelect_SignCounter> &, const Standard_Integer, const IFSelect_PrintCount)) &IFSelect_SessionPilot::ExecuteCounter, "Executes a Counter in a general way If <numword> is greater than count of command words, it counts all the model. Else it considers the word <numword> as the identifier of a Selection <mode> gives the mode of printing results, default is CountByItem", py::arg("counter"), py::arg("numword"), py::arg("mode"));
cls_IFSelect_SessionPilot.def("Number", (Standard_Integer (IFSelect_SessionPilot::*)(const Standard_CString) const) &IFSelect_SessionPilot::Number, "Interprets a string value as an entity number : if it gives an integer, returns its value else, considers it as ENtityLabel (preferably case sensitive) in case of failure, returns 0", py::arg("val"));
cls_IFSelect_SessionPilot.def("Do", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &IFSelect_SessionPilot::Do, "Processes specific commands, which are : x or exit for end of session ? or help for help messages xcommand to control command lines (Record Mode, List, Clear, File Output ...) xsource to execute a command file (no nesting allowed), in case of error, source is stopped and keyword recovers xstep is a simple prefix (useful in a wider environment, to avoid conflicts on command names) xset control commands which create items with names", py::arg("number"), py::arg("session"));
cls_IFSelect_SessionPilot.def("Help", (Standard_CString (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::Help, "Help for specific commands (apart from general command help)", py::arg("number"));
cls_IFSelect_SessionPilot.def_static("get_type_name_", (const char * (*)()) &IFSelect_SessionPilot::get_type_name, "None");
cls_IFSelect_SessionPilot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SessionPilot::get_type_descriptor, "None");
cls_IFSelect_SessionPilot.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::DynamicType, "None");

// Enums

}