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
#include <Standard.hxx>
#include <TCollection_AsciiString.hxx>
#include <Quantity_Date.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_Path.hxx>
#include <OSD_Error.hxx>
#include <OSD_Process.hxx>

void bind_OSD_Process(py::module &mod){

py::class_<OSD_Process> cls_OSD_Process(mod, "OSD_Process", "A set of system process tools");

// Constructors
cls_OSD_Process.def(py::init<>());

// Fields

// Methods
// cls_OSD_Process.def_static("operator new_", (void * (*)(size_t)) &OSD_Process::operator new, "None", py::arg("theSize"));
// cls_OSD_Process.def_static("operator delete_", (void (*)(void *)) &OSD_Process::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Process.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Process::operator new[], "None", py::arg("theSize"));
// cls_OSD_Process.def_static("operator delete[]_", (void (*)(void *)) &OSD_Process::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Process.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Process::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Process.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Process::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Process.def("TerminalType", (void (OSD_Process::*)(TCollection_AsciiString &)) &OSD_Process::TerminalType, "Returns the terminal used (vt100, vt200 ,sun-cmd ...)", py::arg("Name"));
cls_OSD_Process.def("SystemDate", (Quantity_Date (OSD_Process::*)()) &OSD_Process::SystemDate, "Gets system date.");
cls_OSD_Process.def("UserName", (TCollection_AsciiString (OSD_Process::*)()) &OSD_Process::UserName, "Returns the user name.");
cls_OSD_Process.def("IsSuperUser", (Standard_Boolean (OSD_Process::*)()) &OSD_Process::IsSuperUser, "Returns True if the process user is the super-user.");
cls_OSD_Process.def("ProcessId", (Standard_Integer (OSD_Process::*)()) &OSD_Process::ProcessId, "Returns the 'Process Id'");
cls_OSD_Process.def("CurrentDirectory", (OSD_Path (OSD_Process::*)()) &OSD_Process::CurrentDirectory, "Returns the current path where the process is.");
cls_OSD_Process.def("SetCurrentDirectory", (void (OSD_Process::*)(const OSD_Path &)) &OSD_Process::SetCurrentDirectory, "Changes the current process directory.", py::arg("where"));
cls_OSD_Process.def("Failed", (Standard_Boolean (OSD_Process::*)() const) &OSD_Process::Failed, "Returns TRUE if an error occurs");
cls_OSD_Process.def("Reset", (void (OSD_Process::*)()) &OSD_Process::Reset, "Resets error counter to zero");
cls_OSD_Process.def("Perror", (void (OSD_Process::*)()) &OSD_Process::Perror, "Raises OSD_Error");
cls_OSD_Process.def("Error", (Standard_Integer (OSD_Process::*)() const) &OSD_Process::Error, "Returns error number if 'Failed' is TRUE.");

// Enums

}