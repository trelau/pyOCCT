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
#include <OSD_Protection.hxx>
#include <Quantity_Date.hxx>
#include <OSD_Error.hxx>
#include <OSD_FileNode.hxx>

void bind_OSD_FileNode(py::module &mod){

py::class_<OSD_FileNode, std::unique_ptr<OSD_FileNode, py::nodelete>> cls_OSD_FileNode(mod, "OSD_FileNode", "A class for 'File' and 'Directory' grouping common methods (file/directory manipulation tools). The 'file oriented' name means files or directories which are in fact hard coded as files.");

// Constructors

// Fields

// Methods
// cls_OSD_FileNode.def_static("operator new_", (void * (*)(size_t)) &OSD_FileNode::operator new, "None", py::arg("theSize"));
// cls_OSD_FileNode.def_static("operator delete_", (void (*)(void *)) &OSD_FileNode::operator delete, "None", py::arg("theAddress"));
// cls_OSD_FileNode.def_static("operator new[]_", (void * (*)(size_t)) &OSD_FileNode::operator new[], "None", py::arg("theSize"));
// cls_OSD_FileNode.def_static("operator delete[]_", (void (*)(void *)) &OSD_FileNode::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_FileNode.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_FileNode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_FileNode.def_static("operator delete_", (void (*)(void *, void *)) &OSD_FileNode::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_FileNode.def("Path", (void (OSD_FileNode::*)(OSD_Path &) const) &OSD_FileNode::Path, "Gets file name and path.", py::arg("Name"));
cls_OSD_FileNode.def("SetPath", (void (OSD_FileNode::*)(const OSD_Path &)) &OSD_FileNode::SetPath, "Sets file name and path. If a name is not found, it raises a program error.", py::arg("Name"));
cls_OSD_FileNode.def("Exists", (Standard_Boolean (OSD_FileNode::*)()) &OSD_FileNode::Exists, "Returns TRUE if <me> exists.");
cls_OSD_FileNode.def("Remove", (void (OSD_FileNode::*)()) &OSD_FileNode::Remove, "Erases the FileNode from directory");
cls_OSD_FileNode.def("Move", (void (OSD_FileNode::*)(const OSD_Path &)) &OSD_FileNode::Move, "Moves <me> into another directory", py::arg("NewPath"));
cls_OSD_FileNode.def("Copy", (void (OSD_FileNode::*)(const OSD_Path &)) &OSD_FileNode::Copy, "Copies <me> to another FileNode", py::arg("ToPath"));
cls_OSD_FileNode.def("Protection", (OSD_Protection (OSD_FileNode::*)()) &OSD_FileNode::Protection, "Returns access mode of <me>.");
cls_OSD_FileNode.def("SetProtection", (void (OSD_FileNode::*)(const OSD_Protection &)) &OSD_FileNode::SetProtection, "Changes protection of the FileNode", py::arg("Prot"));
cls_OSD_FileNode.def("AccessMoment", (Quantity_Date (OSD_FileNode::*)()) &OSD_FileNode::AccessMoment, "Returns last write access. On UNIX, AccessMoment and CreationMoment return the same value.");
cls_OSD_FileNode.def("CreationMoment", (Quantity_Date (OSD_FileNode::*)()) &OSD_FileNode::CreationMoment, "Returns creation date. On UNIX, AccessMoment and CreationMoment return the same value.");
cls_OSD_FileNode.def("Failed", (Standard_Boolean (OSD_FileNode::*)() const) &OSD_FileNode::Failed, "Returns TRUE if an error occurs");
cls_OSD_FileNode.def("Reset", (void (OSD_FileNode::*)()) &OSD_FileNode::Reset, "Resets error counter to zero");
cls_OSD_FileNode.def("Perror", (void (OSD_FileNode::*)()) &OSD_FileNode::Perror, "Raises OSD_Error");
cls_OSD_FileNode.def("Error", (Standard_Integer (OSD_FileNode::*)() const) &OSD_FileNode::Error, "Returns error number if 'Failed' is TRUE.");

// Enums

}