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
#include <OSD_SingleProtection.hxx>
#include <OSD_FileNode.hxx>
#include <OSD_File.hxx>
#include <OSD_Directory.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_Protection.hxx>

void bind_OSD_Protection(py::module &mod){

py::class_<OSD_Protection> cls_OSD_Protection(mod, "OSD_Protection", "This class provides data to manage file protection Example:These rights are treated in a system dependent manner : On UNIX you have User,Group and Other rights On VMS you have Owner,Group,World and System rights An automatic conversion is done between OSD and UNIX/VMS.");

// Constructors
cls_OSD_Protection.def(py::init<>());
cls_OSD_Protection.def(py::init<const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection>(), py::arg("System"), py::arg("User"), py::arg("Group"), py::arg("World"));

// Fields

// Methods
// cls_OSD_Protection.def_static("operator new_", (void * (*)(size_t)) &OSD_Protection::operator new, "None", py::arg("theSize"));
// cls_OSD_Protection.def_static("operator delete_", (void (*)(void *)) &OSD_Protection::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Protection.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Protection::operator new[], "None", py::arg("theSize"));
// cls_OSD_Protection.def_static("operator delete[]_", (void (*)(void *)) &OSD_Protection::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Protection.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Protection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Protection.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Protection::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Protection.def("Values", (void (OSD_Protection::*)(OSD_SingleProtection &, OSD_SingleProtection &, OSD_SingleProtection &, OSD_SingleProtection &)) &OSD_Protection::Values, "Retrieves values of fields", py::arg("System"), py::arg("User"), py::arg("Group"), py::arg("World"));
cls_OSD_Protection.def("SetValues", (void (OSD_Protection::*)(const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection, const OSD_SingleProtection)) &OSD_Protection::SetValues, "Sets values of fields", py::arg("System"), py::arg("User"), py::arg("Group"), py::arg("World"));
cls_OSD_Protection.def("SetSystem", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetSystem, "Sets protection of 'System'", py::arg("priv"));
cls_OSD_Protection.def("SetUser", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetUser, "Sets protection of 'User'", py::arg("priv"));
cls_OSD_Protection.def("SetGroup", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetGroup, "Sets protection of 'Group'", py::arg("priv"));
cls_OSD_Protection.def("SetWorld", (void (OSD_Protection::*)(const OSD_SingleProtection)) &OSD_Protection::SetWorld, "Sets protection of 'World'", py::arg("priv"));
cls_OSD_Protection.def("System", (OSD_SingleProtection (OSD_Protection::*)() const) &OSD_Protection::System, "Gets protection of 'System'");
cls_OSD_Protection.def("User", (OSD_SingleProtection (OSD_Protection::*)() const) &OSD_Protection::User, "Gets protection of 'User'");
cls_OSD_Protection.def("Group", (OSD_SingleProtection (OSD_Protection::*)() const) &OSD_Protection::Group, "Gets protection of 'Group'");
cls_OSD_Protection.def("World", (OSD_SingleProtection (OSD_Protection::*)() const) &OSD_Protection::World, "Gets protection of 'World'");
cls_OSD_Protection.def("Add", (void (OSD_Protection::*)(OSD_SingleProtection &, const OSD_SingleProtection)) &OSD_Protection::Add, "Add a right to a single protection. ex: aProt = RWD me.Add(aProt,X) -> aProt = RWXD", py::arg("aProt"), py::arg("aRight"));
cls_OSD_Protection.def("Sub", (void (OSD_Protection::*)(OSD_SingleProtection &, const OSD_SingleProtection)) &OSD_Protection::Sub, "Subtract a right to a single protection. ex: aProt = RWD me.Sub(aProt,RW) -> aProt = D But me.Sub(aProt,RWX) is also valid and gives same result.", py::arg("aProt"), py::arg("aRight"));

// Enums

}