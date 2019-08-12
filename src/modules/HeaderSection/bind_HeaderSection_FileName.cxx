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
#include <TCollection_HAsciiString.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <HeaderSection_FileName.hxx>
#include <Standard_Type.hxx>

void bind_HeaderSection_FileName(py::module &mod){

py::class_<HeaderSection_FileName, opencascade::handle<HeaderSection_FileName>, Standard_Transient> cls_HeaderSection_FileName(mod, "HeaderSection_FileName", "None");

// Constructors
cls_HeaderSection_FileName.def(py::init<>());

// Fields

// Methods
cls_HeaderSection_FileName.def("Init", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::Init, "None", py::arg("aName"), py::arg("aTimeStamp"), py::arg("aAuthor"), py::arg("aOrganization"), py::arg("aPreprocessorVersion"), py::arg("aOriginatingSystem"), py::arg("aAuthorisation"));
cls_HeaderSection_FileName.def("SetName", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetName, "None", py::arg("aName"));
cls_HeaderSection_FileName.def("Name", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const) &HeaderSection_FileName::Name, "None");
cls_HeaderSection_FileName.def("SetTimeStamp", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetTimeStamp, "None", py::arg("aTimeStamp"));
cls_HeaderSection_FileName.def("TimeStamp", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const) &HeaderSection_FileName::TimeStamp, "None");
cls_HeaderSection_FileName.def("SetAuthor", (void (HeaderSection_FileName::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &HeaderSection_FileName::SetAuthor, "None", py::arg("aAuthor"));
cls_HeaderSection_FileName.def("Author", (opencascade::handle<Interface_HArray1OfHAsciiString> (HeaderSection_FileName::*)() const) &HeaderSection_FileName::Author, "None");
cls_HeaderSection_FileName.def("AuthorValue", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)(const Standard_Integer) const) &HeaderSection_FileName::AuthorValue, "None", py::arg("num"));
cls_HeaderSection_FileName.def("NbAuthor", (Standard_Integer (HeaderSection_FileName::*)() const) &HeaderSection_FileName::NbAuthor, "None");
cls_HeaderSection_FileName.def("SetOrganization", (void (HeaderSection_FileName::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &HeaderSection_FileName::SetOrganization, "None", py::arg("aOrganization"));
cls_HeaderSection_FileName.def("Organization", (opencascade::handle<Interface_HArray1OfHAsciiString> (HeaderSection_FileName::*)() const) &HeaderSection_FileName::Organization, "None");
cls_HeaderSection_FileName.def("OrganizationValue", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)(const Standard_Integer) const) &HeaderSection_FileName::OrganizationValue, "None", py::arg("num"));
cls_HeaderSection_FileName.def("NbOrganization", (Standard_Integer (HeaderSection_FileName::*)() const) &HeaderSection_FileName::NbOrganization, "None");
cls_HeaderSection_FileName.def("SetPreprocessorVersion", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetPreprocessorVersion, "None", py::arg("aPreprocessorVersion"));
cls_HeaderSection_FileName.def("PreprocessorVersion", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const) &HeaderSection_FileName::PreprocessorVersion, "None");
cls_HeaderSection_FileName.def("SetOriginatingSystem", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetOriginatingSystem, "None", py::arg("aOriginatingSystem"));
cls_HeaderSection_FileName.def("OriginatingSystem", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const) &HeaderSection_FileName::OriginatingSystem, "None");
cls_HeaderSection_FileName.def("SetAuthorisation", (void (HeaderSection_FileName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &HeaderSection_FileName::SetAuthorisation, "None", py::arg("aAuthorisation"));
cls_HeaderSection_FileName.def("Authorisation", (opencascade::handle<TCollection_HAsciiString> (HeaderSection_FileName::*)() const) &HeaderSection_FileName::Authorisation, "None");
cls_HeaderSection_FileName.def_static("get_type_name_", (const char * (*)()) &HeaderSection_FileName::get_type_name, "None");
cls_HeaderSection_FileName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HeaderSection_FileName::get_type_descriptor, "None");
cls_HeaderSection_FileName.def("DynamicType", (const opencascade::handle<Standard_Type> & (HeaderSection_FileName::*)() const) &HeaderSection_FileName::DynamicType, "None");

// Enums

}