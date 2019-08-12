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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_AsciiString.hxx>
#include <TDF_Label.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_AsciiString(py::module &mod){

py::class_<TDataStd_AsciiString, opencascade::handle<TDataStd_AsciiString>, TDF_Attribute> cls_TDataStd_AsciiString(mod, "TDataStd_AsciiString", "Used to define an AsciiString attribute containing a TCollection_AsciiString");

// Constructors
cls_TDataStd_AsciiString.def(py::init<>());

// Fields

// Methods
cls_TDataStd_AsciiString.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_AsciiString::GetID, "class methods ============= Returns the GUID of the attribute.");
cls_TDataStd_AsciiString.def_static("Set_", (opencascade::handle<TDataStd_AsciiString> (*)(const TDF_Label &, const TCollection_AsciiString &)) &TDataStd_AsciiString::Set, "Finds, or creates an AsciiString attribute and sets the string. the AsciiString attribute is returned. AsciiString methods ===================", py::arg("label"), py::arg("string"));
cls_TDataStd_AsciiString.def_static("Set_", (opencascade::handle<TDataStd_AsciiString> (*)(const TDF_Label &, const Standard_GUID &, const TCollection_AsciiString &)) &TDataStd_AsciiString::Set, "Finds, or creates, an AsciiString attribute with explicit user defined <guid> and sets <string>. The Name attribute is returned.", py::arg("label"), py::arg("guid"), py::arg("string"));
cls_TDataStd_AsciiString.def("Set", (void (TDataStd_AsciiString::*)(const TCollection_AsciiString &)) &TDataStd_AsciiString::Set, "None", py::arg("S"));
cls_TDataStd_AsciiString.def("SetID", (void (TDataStd_AsciiString::*)(const Standard_GUID &)) &TDataStd_AsciiString::SetID, "Sets the explicit user defined GUID to the attribute.", py::arg("guid"));
cls_TDataStd_AsciiString.def("SetID", (void (TDataStd_AsciiString::*)()) &TDataStd_AsciiString::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_AsciiString.def("Get", (const TCollection_AsciiString & (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::Get, "None");
cls_TDataStd_AsciiString.def("IsEmpty", (Standard_Boolean (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::IsEmpty, "None");
cls_TDataStd_AsciiString.def("ID", (const Standard_GUID & (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::ID, "None");
cls_TDataStd_AsciiString.def("Restore", (void (TDataStd_AsciiString::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_AsciiString::Restore, "None", py::arg("with"));
cls_TDataStd_AsciiString.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::NewEmpty, "None");
cls_TDataStd_AsciiString.def("Paste", (void (TDataStd_AsciiString::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_AsciiString::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_AsciiString.def("Dump", (Standard_OStream & (TDataStd_AsciiString::*)(Standard_OStream &) const) &TDataStd_AsciiString::Dump, "None", py::arg("anOS"));
cls_TDataStd_AsciiString.def_static("get_type_name_", (const char * (*)()) &TDataStd_AsciiString::get_type_name, "None");
cls_TDataStd_AsciiString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_AsciiString::get_type_descriptor, "None");
cls_TDataStd_AsciiString.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_AsciiString::*)() const) &TDataStd_AsciiString::DynamicType, "None");

// Enums

}