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
#include <IFSelect_Activator.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>

void bind_IFSelect_Activator(py::module &mod){

py::class_<IFSelect_Activator, opencascade::handle<IFSelect_Activator>, Standard_Transient> cls_IFSelect_Activator(mod, "IFSelect_Activator", "Defines the general frame for working with a SessionPilot. Each Activator treats a set of Commands. Commands are given as alphanumeric strings. They can be of two main forms : - classic, to list, evaluate, enrich the session (by itself) : no specific remark, its complete execution must be described - creation of a new item : instead of creatinf it plus adding it to the session (which is a classic way), it is possible to create it and make it recorded by the SessionPilot : then, the Pilot will add it to the session; this way allows the Pilot to manage itself named items");

// Fields

// Methods
cls_IFSelect_Activator.def_static("Adding_", (void (*)(const opencascade::handle<IFSelect_Activator> &, const Standard_Integer, const Standard_CString, const Standard_Integer)) &IFSelect_Activator::Adding, "Records, in a Dictionary available for all the Activators, the command title an Activator can process, attached with its number, proper for this Activator <mode> allows to distinguish various execution modes 0: default mode; 1 : for xset", py::arg("actor"), py::arg("number"), py::arg("command"), py::arg("mode"));
cls_IFSelect_Activator.def("Add", (void (IFSelect_Activator::*)(const Standard_Integer, const Standard_CString) const) &IFSelect_Activator::Add, "Allows a self-definition by an Activator of the Commands it processes, call the class method Adding (mode 0)", py::arg("number"), py::arg("command"));
cls_IFSelect_Activator.def("AddSet", (void (IFSelect_Activator::*)(const Standard_Integer, const Standard_CString) const) &IFSelect_Activator::AddSet, "Same as Add but specifies that this command is candidate for xset (creation of items, xset : named items; mode 1)", py::arg("number"), py::arg("command"));
cls_IFSelect_Activator.def_static("Remove_", (void (*)(const Standard_CString)) &IFSelect_Activator::Remove, "Removes a Command, if it is recorded (else, does nothing)", py::arg("command"));
cls_IFSelect_Activator.def_static("Select_", [](const Standard_CString command, Standard_Integer & number, opencascade::handle<IFSelect_Activator> & actor){ Standard_Boolean rv = IFSelect_Activator::Select(command, number, actor); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, number); }, "Selects, for a Command given by its title, an actor with its command number. Returns True if found, False else", py::arg("command"), py::arg("number"), py::arg("actor"));
cls_IFSelect_Activator.def_static("Mode_", (Standard_Integer (*)(const Standard_CString)) &IFSelect_Activator::Mode, "Returns mode recorded for a command. -1 if not found", py::arg("command"));
cls_IFSelect_Activator.def_static("Commands_", []() -> opencascade::handle<TColStd_HSequenceOfAsciiString> { return IFSelect_Activator::Commands(); });
cls_IFSelect_Activator.def_static("Commands_", [](const Standard_Integer a0) -> opencascade::handle<TColStd_HSequenceOfAsciiString> { return IFSelect_Activator::Commands(a0); });
cls_IFSelect_Activator.def_static("Commands_", (opencascade::handle<TColStd_HSequenceOfAsciiString> (*)(const Standard_Integer, const Standard_CString)) &IFSelect_Activator::Commands, "Returns, for a root of command title, the list of possible commands. <mode> : -1 (D) for all commands if <commands> is empty -1 + command : about a Group , >= 0 see Adding By default, it returns the whole list of known commands.", py::arg("mode"), py::arg("command"));
cls_IFSelect_Activator.def("Do", (IFSelect_ReturnStatus (IFSelect_Activator::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &IFSelect_Activator::Do, "Tries to execute a Command Line. <number> is the number of the command for this Activator. It Must forecast to record the result of the execution, for need of Undo-Redo Must Returns : 0 for a void command (not to be recorded), 1 if execution OK, -1 if command incorrect, -2 if error on execution", py::arg("number"), py::arg("pilot"));
cls_IFSelect_Activator.def("Help", (Standard_CString (IFSelect_Activator::*)(const Standard_Integer) const) &IFSelect_Activator::Help, "Sends a short help message for a given command identified by it number for this Activator (must take one line max)", py::arg("number"));
cls_IFSelect_Activator.def("Group", (Standard_CString (IFSelect_Activator::*)() const) &IFSelect_Activator::Group, "None");
cls_IFSelect_Activator.def("File", (Standard_CString (IFSelect_Activator::*)() const) &IFSelect_Activator::File, "None");
cls_IFSelect_Activator.def("SetForGroup", [](IFSelect_Activator &self, const Standard_CString a0) -> void { return self.SetForGroup(a0); });
cls_IFSelect_Activator.def("SetForGroup", (void (IFSelect_Activator::*)(const Standard_CString, const Standard_CString)) &IFSelect_Activator::SetForGroup, "Group and SetGroup define a 'Group of commands' which correspond to an Activator. Default is 'XSTEP' Also a file may be attached", py::arg("group"), py::arg("file"));
cls_IFSelect_Activator.def_static("get_type_name_", (const char * (*)()) &IFSelect_Activator::get_type_name, "None");
cls_IFSelect_Activator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Activator::get_type_descriptor, "None");
cls_IFSelect_Activator.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Activator::*)() const) &IFSelect_Activator::DynamicType, "None");

// Enums

}