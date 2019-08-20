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
#include <OSD_FileNode.hxx>
#include <OSD_Directory.hxx>
#include <OSD_Path.hxx>
#include <OSD_Protection.hxx>

void bind_OSD_Directory(py::module &mod){

py::class_<OSD_Directory, std::unique_ptr<OSD_Directory>, OSD_FileNode> cls_OSD_Directory(mod, "OSD_Directory", "Management of directories (a set of directory oriented tools)");

// Constructors
cls_OSD_Directory.def(py::init<>());
cls_OSD_Directory.def(py::init<const OSD_Path &>(), py::arg("theName"));

// Fields

// Methods
cls_OSD_Directory.def_static("BuildTemporary_", (OSD_Directory (*)()) &OSD_Directory::BuildTemporary, "Creates a temporary Directory in current directory. This directory is automatically removed when object dies.");
cls_OSD_Directory.def("Build", (void (OSD_Directory::*)(const OSD_Protection &)) &OSD_Directory::Build, "Creates (physically) a directory. When a directory of the same name already exists, no error is returned, and only <Protect> is applied to the existing directory.", py::arg("Protect"));

// Enums

}