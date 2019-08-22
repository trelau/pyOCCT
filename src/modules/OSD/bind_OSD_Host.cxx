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
#include <OSD_SysType.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_OEMType.hxx>
#include <OSD_Error.hxx>
#include <OSD_Host.hxx>

void bind_OSD_Host(py::module &mod){

py::class_<OSD_Host> cls_OSD_Host(mod, "OSD_Host", "Carries information about a Host System version ,host name, nodename ...");

// Constructors
cls_OSD_Host.def(py::init<>());

// Fields

// Methods
// cls_OSD_Host.def_static("operator new_", (void * (*)(size_t)) &OSD_Host::operator new, "None", py::arg("theSize"));
// cls_OSD_Host.def_static("operator delete_", (void (*)(void *)) &OSD_Host::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Host.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Host::operator new[], "None", py::arg("theSize"));
// cls_OSD_Host.def_static("operator delete[]_", (void (*)(void *)) &OSD_Host::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Host.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Host::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Host.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Host::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Host.def("SystemVersion", (TCollection_AsciiString (OSD_Host::*)()) &OSD_Host::SystemVersion, "Returns system name and version");
cls_OSD_Host.def("SystemId", (OSD_SysType (OSD_Host::*)() const) &OSD_Host::SystemId, "Returns the system type (UNIX System V, UNIX BSD, MS-DOS...)");
cls_OSD_Host.def("HostName", (TCollection_AsciiString (OSD_Host::*)()) &OSD_Host::HostName, "Returns host name.");
cls_OSD_Host.def("AvailableMemory", (Standard_Integer (OSD_Host::*)()) &OSD_Host::AvailableMemory, "Returns available memory in Kilobytes.");
cls_OSD_Host.def("InternetAddress", (TCollection_AsciiString (OSD_Host::*)()) &OSD_Host::InternetAddress, "Returns Internet address of current host.");
cls_OSD_Host.def("MachineType", (OSD_OEMType (OSD_Host::*)()) &OSD_Host::MachineType, "Returns type of current machine.");
cls_OSD_Host.def("Failed", (Standard_Boolean (OSD_Host::*)() const) &OSD_Host::Failed, "Returns TRUE if an error occurs");
cls_OSD_Host.def("Reset", (void (OSD_Host::*)()) &OSD_Host::Reset, "Resets error counter to zero");
cls_OSD_Host.def("Perror", (void (OSD_Host::*)()) &OSD_Host::Perror, "Raises OSD_Error");
cls_OSD_Host.def("Error", (Standard_Integer (OSD_Host::*)() const) &OSD_Host::Error, "Returns error number if 'Failed' is TRUE.");

// Enums

}