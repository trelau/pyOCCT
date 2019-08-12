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
#include <Resource_Manager.hxx>
#include <Message_Messenger.hxx>
#include <CDM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <CDM_Reference.hxx>
#include <CDM_MetaData.hxx>
#include <CDM_Application.hxx>
#include <Standard_Type.hxx>

void bind_CDM_Application(py::module &mod){

py::class_<CDM_Application, opencascade::handle<CDM_Application>, Standard_Transient> cls_CDM_Application(mod, "CDM_Application", "None");

// Fields

// Methods
cls_CDM_Application.def("Resources", (opencascade::handle<Resource_Manager> (CDM_Application::*)()) &CDM_Application::Resources, "The manager returned by this virtual method will be used to search for Format.Retrieval resource items.");
cls_CDM_Application.def("MessageDriver", (opencascade::handle<Message_Messenger> (CDM_Application::*)()) &CDM_Application::MessageDriver, "Returns default messenger;");
cls_CDM_Application.def("BeginOfUpdate", (void (CDM_Application::*)(const opencascade::handle<CDM_Document> &)) &CDM_Application::BeginOfUpdate, "this method is called before the update of a document. By default, writes in MessageDriver().", py::arg("aDocument"));
cls_CDM_Application.def("EndOfUpdate", (void (CDM_Application::*)(const opencascade::handle<CDM_Document> &, const Standard_Boolean, const TCollection_ExtendedString &)) &CDM_Application::EndOfUpdate, "this method is called affter the update of a document. By default, writes in MessageDriver().", py::arg("aDocument"), py::arg("theStatus"), py::arg("ErrorString"));
cls_CDM_Application.def("Write", (void (CDM_Application::*)(const Standard_ExtString)) &CDM_Application::Write, "writes the string in the application MessagerDriver.", py::arg("aString"));
cls_CDM_Application.def("Name", (TCollection_ExtendedString (CDM_Application::*)() const) &CDM_Application::Name, "Returns the application name.");
cls_CDM_Application.def("Version", (TCollection_AsciiString (CDM_Application::*)() const) &CDM_Application::Version, "Returns the application version.");
cls_CDM_Application.def_static("get_type_name_", (const char * (*)()) &CDM_Application::get_type_name, "None");
cls_CDM_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDM_Application::get_type_descriptor, "None");
cls_CDM_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDM_Application::*)() const) &CDM_Application::DynamicType, "None");

// Enums

}