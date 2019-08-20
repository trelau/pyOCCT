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
#include <OSD_Path.hxx>

void bind_OSD_Path(py::module &mod){

py::class_<OSD_Path, std::unique_ptr<OSD_Path>> cls_OSD_Path(mod, "OSD_Path", "None");

// Constructors
cls_OSD_Path.def(py::init<>());
cls_OSD_Path.def(py::init<const TCollection_AsciiString &>(), py::arg("aDependentName"));
cls_OSD_Path.def(py::init<const TCollection_AsciiString &, const OSD_SysType>(), py::arg("aDependentName"), py::arg("aSysType"));
cls_OSD_Path.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("aNode"), py::arg("aUsername"), py::arg("aPassword"), py::arg("aDisk"), py::arg("aTrek"), py::arg("aName"), py::arg("anExtension"));

// Fields

// Methods
// cls_OSD_Path.def_static("operator new_", (void * (*)(size_t)) &OSD_Path::operator new, "None", py::arg("theSize"));
// cls_OSD_Path.def_static("operator delete_", (void (*)(void *)) &OSD_Path::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Path.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Path::operator new[], "None", py::arg("theSize"));
// cls_OSD_Path.def_static("operator delete[]_", (void (*)(void *)) &OSD_Path::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Path.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Path::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Path.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Path::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Path.def("Values", (void (OSD_Path::*)(TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &, TCollection_AsciiString &) const) &OSD_Path::Values, "Gets each component of a path.", py::arg("aNode"), py::arg("aUsername"), py::arg("aPassword"), py::arg("aDisk"), py::arg("aTrek"), py::arg("aName"), py::arg("anExtension"));
cls_OSD_Path.def("SetValues", (void (OSD_Path::*)(const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &)) &OSD_Path::SetValues, "Sets each component of a path.", py::arg("aNode"), py::arg("aUsername"), py::arg("aPassword"), py::arg("aDisk"), py::arg("aTrek"), py::arg("aName"), py::arg("anExtension"));
cls_OSD_Path.def("SystemName", [](OSD_Path &self, TCollection_AsciiString & a0) -> void { return self.SystemName(a0); });
cls_OSD_Path.def("SystemName", (void (OSD_Path::*)(TCollection_AsciiString &, const OSD_SysType) const) &OSD_Path::SystemName, "Returns system dependent path <aType> is one among Unix,VMS ... This function is not private because you may need to display system dependent path on a front-end. It can be useful when communicating with another system. For instance when you want to communicate between VMS and Unix to transfer files, or to do a remote procedure call using files. example : OSD_Path myPath ('sparc4', 'sga', 'secret_passwd', '$5$dkb100','|users|examples'); Internal ( Dependent_name ); On UNIX sga'secret_passwd':/users/examples On VMS sparc4'sga secret_passwd'::$5$dkb100:[users.examples] Sets each component of a Path giving its system dependent name.", py::arg("FullName"), py::arg("aType"));
cls_OSD_Path.def("ExpandedName", (void (OSD_Path::*)(TCollection_AsciiString &)) &OSD_Path::ExpandedName, "Returns system dependent path resolving logical symbols.", py::arg("aName"));
cls_OSD_Path.def_static("IsValid_", [](const TCollection_AsciiString & a0) -> Standard_Boolean { return OSD_Path::IsValid(a0); });
cls_OSD_Path.def_static("IsValid_", (Standard_Boolean (*)(const TCollection_AsciiString &, const OSD_SysType)) &OSD_Path::IsValid, "Returns TRUE if <theDependentName> is valid for this SysType.", py::arg("theDependentName"), py::arg("theSysType"));
cls_OSD_Path.def("UpTrek", (void (OSD_Path::*)()) &OSD_Path::UpTrek, "This removes the last directory name in <aTrek> and returns result. ex: me = '|usr|bin|todo.sh' me.UpTrek() gives me = '|usr|todo.sh' if <me> contains '|', me.UpTrek() will give again '|' without any error.");
cls_OSD_Path.def("DownTrek", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::DownTrek, "This appends a directory name into the Trek. ex: me = '|usr|todo.sh' me.DownTrek('bin') gives me = '|usr|bin|todo.sh'.", py::arg("aName"));
cls_OSD_Path.def("TrekLength", (Standard_Integer (OSD_Path::*)() const) &OSD_Path::TrekLength, "Returns number of components in Trek of <me>. ex: me = '|usr|sys|etc|bin' me.TrekLength() returns 4.");
cls_OSD_Path.def("RemoveATrek", (void (OSD_Path::*)(const Standard_Integer)) &OSD_Path::RemoveATrek, "This removes a component of Trek in <me> at position <where>. The first component of Trek is numbered 1. ex: me = '|usr|bin|' me.RemoveATrek(1) gives me = '|bin|' To avoid a 'NumericError' because of a bad <where>, use TrekLength() to know number of components of Trek in <me>.", py::arg("where"));
cls_OSD_Path.def("RemoveATrek", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::RemoveATrek, "This removes <aName> from <me> in Trek. No error is raised if <aName> is not in <me>. ex: me = '|usr|sys|etc|doc' me.RemoveATrek('sys') gives me = '|usr|etc|doc'.", py::arg("aName"));
cls_OSD_Path.def("TrekValue", (TCollection_AsciiString (OSD_Path::*)(const Standard_Integer) const) &OSD_Path::TrekValue, "Returns component of Trek in <me> at position <where>. ex: me = '|usr|bin|sys|' me.TrekValue(2) returns 'bin'", py::arg("where"));
cls_OSD_Path.def("InsertATrek", (void (OSD_Path::*)(const TCollection_AsciiString &, const Standard_Integer)) &OSD_Path::InsertATrek, "This inserts <aName> at position <where> into Trek of <me>. ex: me = '|usr|etc|' me.InsertATrek('sys',2) gives me = '|usr|sys|etc'", py::arg("aName"), py::arg("where"));
cls_OSD_Path.def("Node", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Node, "Returns Node of <me>.");
cls_OSD_Path.def("UserName", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::UserName, "Returns UserName of <me>.");
cls_OSD_Path.def("Password", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Password, "Returns Password of <me>.");
cls_OSD_Path.def("Disk", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Disk, "Returns Disk of <me>.");
cls_OSD_Path.def("Trek", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Trek, "Returns Trek of <me>.");
cls_OSD_Path.def("Name", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Name, "Returns file name of <me>. If <me> hasn't been initialized, it returns an empty AsciiString.");
cls_OSD_Path.def("Extension", (TCollection_AsciiString (OSD_Path::*)() const) &OSD_Path::Extension, "Returns my extension name. This returns an empty string if path contains no file name.");
cls_OSD_Path.def("SetNode", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetNode, "Sets Node of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetUserName", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetUserName, "Sets UserName of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetPassword", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetPassword, "Sets Password of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetDisk", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetDisk, "Sets Disk of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetTrek", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetTrek, "Sets Trek of <me>.", py::arg("aName"));
cls_OSD_Path.def("SetName", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetName, "Sets file name of <me>. If <me> hasn't been initialized, it returns an empty AsciiString.", py::arg("aName"));
cls_OSD_Path.def("SetExtension", (void (OSD_Path::*)(const TCollection_AsciiString &)) &OSD_Path::SetExtension, "Sets my extension name.", py::arg("aName"));
// cls_OSD_Path.def("LocateExecFile", (Standard_Boolean (OSD_Path::*)(OSD_Path &)) &OSD_Path::LocateExecFile, "Finds the full path of an executable file, like the 'which' Unix utility. Uses the path environment variable. Returns False if executable file not found.", py::arg("aPath"));
cls_OSD_Path.def_static("RelativePath_", (TCollection_AsciiString (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &OSD_Path::RelativePath, "Returns the relative file path between the absolute directory path <DirPath> and the absolute file path <AbsFilePath>. If <DirPath> starts with '/', pathes are handled as on Unix, if it starts with a letter followed by ':', as on WNT. In particular on WNT directory names are not key sensitive. If handling fails, an empty string is returned.", py::arg("DirPath"), py::arg("AbsFilePath"));
cls_OSD_Path.def_static("AbsolutePath_", (TCollection_AsciiString (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &OSD_Path::AbsolutePath, "Returns the absolute file path from the absolute directory path <DirPath> and the relative file path returned by RelativePath(). If the RelFilePath is an absolute path, it is returned and the directory path is ignored. If handling fails, an empty string is returned.", py::arg("DirPath"), py::arg("RelFilePath"));

// Enums

}