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
#include <OSD_Path.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <OSD_Error.hxx>
#include <OSD_Disk.hxx>

void bind_OSD_Disk(py::module &mod){

py::class_<OSD_Disk> cls_OSD_Disk(mod, "OSD_Disk", "Disk management (a set of disk oriented tools)");

// Constructors
cls_OSD_Disk.def(py::init<>());
cls_OSD_Disk.def(py::init<const OSD_Path &>(), py::arg("Name"));
cls_OSD_Disk.def(py::init<const Standard_CString>(), py::arg("PathName"));

// Fields

// Methods
// cls_OSD_Disk.def_static("operator new_", (void * (*)(size_t)) &OSD_Disk::operator new, "None", py::arg("theSize"));
// cls_OSD_Disk.def_static("operator delete_", (void (*)(void *)) &OSD_Disk::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Disk.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Disk::operator new[], "None", py::arg("theSize"));
// cls_OSD_Disk.def_static("operator delete[]_", (void (*)(void *)) &OSD_Disk::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Disk.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Disk::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Disk.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Disk::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Disk.def("Name", (OSD_Path (OSD_Disk::*)() const) &OSD_Disk::Name, "Returns disk name of <me>.");
cls_OSD_Disk.def("SetName", (void (OSD_Disk::*)(const OSD_Path &)) &OSD_Disk::SetName, "Instantiates <me> with <Name>.", py::arg("Name"));
cls_OSD_Disk.def("DiskSize", (Standard_Integer (OSD_Disk::*)()) &OSD_Disk::DiskSize, "Returns total disk capacity in 512 bytes blocks.");
cls_OSD_Disk.def("DiskFree", (Standard_Integer (OSD_Disk::*)()) &OSD_Disk::DiskFree, "Returns free available 512 bytes blocks on disk.");
cls_OSD_Disk.def("Failed", (Standard_Boolean (OSD_Disk::*)() const) &OSD_Disk::Failed, "Returns TRUE if an error occurs");
cls_OSD_Disk.def("Reset", (void (OSD_Disk::*)()) &OSD_Disk::Reset, "Resets error counter to zero");
cls_OSD_Disk.def("Perror", (void (OSD_Disk::*)()) &OSD_Disk::Perror, "Raises OSD_Error");
cls_OSD_Disk.def("Error", (Standard_Integer (OSD_Disk::*)() const) &OSD_Disk::Error, "Returns error number if 'Failed' is TRUE.");

// Enums

}