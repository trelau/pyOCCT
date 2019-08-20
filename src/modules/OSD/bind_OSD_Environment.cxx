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
#include <Standard_TypeDef.hxx>
#include <OSD_Error.hxx>
#include <OSD_Environment.hxx>

void bind_OSD_Environment(py::module &mod){

py::class_<OSD_Environment, std::unique_ptr<OSD_Environment>> cls_OSD_Environment(mod, "OSD_Environment", "Management of system environment variables An environment variable is composed of a variable name and its value.");

// Constructors
cls_OSD_Environment.def(py::init<>());
cls_OSD_Environment.def(py::init<const TCollection_AsciiString &>(), py::arg("Name"));
cls_OSD_Environment.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("Name"), py::arg("Value"));

// Fields

// Methods
// cls_OSD_Environment.def_static("operator new_", (void * (*)(size_t)) &OSD_Environment::operator new, "None", py::arg("theSize"));
// cls_OSD_Environment.def_static("operator delete_", (void (*)(void *)) &OSD_Environment::operator delete, "None", py::arg("theAddress"));
// cls_OSD_Environment.def_static("operator new[]_", (void * (*)(size_t)) &OSD_Environment::operator new[], "None", py::arg("theSize"));
// cls_OSD_Environment.def_static("operator delete[]_", (void (*)(void *)) &OSD_Environment::operator delete[], "None", py::arg("theAddress"));
// cls_OSD_Environment.def_static("operator new_", (void * (*)(size_t, void *)) &OSD_Environment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OSD_Environment.def_static("operator delete_", (void (*)(void *, void *)) &OSD_Environment::operator delete, "None", py::arg(""), py::arg(""));
cls_OSD_Environment.def("SetValue", (void (OSD_Environment::*)(const TCollection_AsciiString &)) &OSD_Environment::SetValue, "Changes environment variable value. Raises ConstructionError either if the string contains characters not in range of ' '...'~' or if the string contains the character '$' which is forbiden.", py::arg("Value"));
cls_OSD_Environment.def("Value", (TCollection_AsciiString (OSD_Environment::*)()) &OSD_Environment::Value, "Gets the value of an environment variable");
cls_OSD_Environment.def("SetName", (void (OSD_Environment::*)(const TCollection_AsciiString &)) &OSD_Environment::SetName, "Changes environment variable name. Raises ConstructionError either if the string contains characters not in range of ' '...'~' or if the string contains the character '$' which is forbiden.", py::arg("name"));
cls_OSD_Environment.def("Name", (TCollection_AsciiString (OSD_Environment::*)() const) &OSD_Environment::Name, "Gets the name of <me>.");
cls_OSD_Environment.def("Build", (void (OSD_Environment::*)()) &OSD_Environment::Build, "Sets the value of an environment variable into system (physically).");
cls_OSD_Environment.def("Remove", (void (OSD_Environment::*)()) &OSD_Environment::Remove, "Removes (physically) an environment variable");
cls_OSD_Environment.def("Failed", (Standard_Boolean (OSD_Environment::*)() const) &OSD_Environment::Failed, "Returns TRUE if an error occurs");
cls_OSD_Environment.def("Reset", (void (OSD_Environment::*)()) &OSD_Environment::Reset, "Resets error counter to zero");
cls_OSD_Environment.def("Perror", (void (OSD_Environment::*)()) &OSD_Environment::Perror, "Raises OSD_Error");
cls_OSD_Environment.def("Error", (Standard_Integer (OSD_Environment::*)() const) &OSD_Environment::Error, "Returns error number if 'Failed' is TRUE.");

// Enums

}