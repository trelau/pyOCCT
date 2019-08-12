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
#include <TDataStd_Comment.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Comment(py::module &mod){

py::class_<TDataStd_Comment, opencascade::handle<TDataStd_Comment>, TDF_Attribute> cls_TDataStd_Comment(mod, "TDataStd_Comment", "Comment attribute. may be associated to any label to store user comment.");

// Constructors
cls_TDataStd_Comment.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Comment.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Comment::GetID, "class methods ============= Returns the GUID for comments.");
cls_TDataStd_Comment.def_static("Set_", (opencascade::handle<TDataStd_Comment> (*)(const TDF_Label &)) &TDataStd_Comment::Set, "Find, or create a Comment attribute. the Comment attribute is returned.", py::arg("label"));
cls_TDataStd_Comment.def_static("Set_", (opencascade::handle<TDataStd_Comment> (*)(const TDF_Label &, const TCollection_ExtendedString &)) &TDataStd_Comment::Set, "Finds, or creates a Comment attribute and sets the string. the Comment attribute is returned. Comment methods ============", py::arg("label"), py::arg("string"));
cls_TDataStd_Comment.def("Set", (void (TDataStd_Comment::*)(const TCollection_ExtendedString &)) &TDataStd_Comment::Set, "None", py::arg("S"));
cls_TDataStd_Comment.def("Get", (const TCollection_ExtendedString & (TDataStd_Comment::*)() const) &TDataStd_Comment::Get, "Returns the comment attribute.");
cls_TDataStd_Comment.def("ID", (const Standard_GUID & (TDataStd_Comment::*)() const) &TDataStd_Comment::ID, "None");
cls_TDataStd_Comment.def("Restore", (void (TDataStd_Comment::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Comment::Restore, "None", py::arg("with"));
cls_TDataStd_Comment.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Comment::*)() const) &TDataStd_Comment::NewEmpty, "None");
cls_TDataStd_Comment.def("Paste", (void (TDataStd_Comment::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Comment::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_Comment.def("Dump", (Standard_OStream & (TDataStd_Comment::*)(Standard_OStream &) const) &TDataStd_Comment::Dump, "None", py::arg("anOS"));
cls_TDataStd_Comment.def("AfterRetrieval", [](TDataStd_Comment &self) -> Standard_Boolean { return self.AfterRetrieval(); });
cls_TDataStd_Comment.def("AfterRetrieval", (Standard_Boolean (TDataStd_Comment::*)(const Standard_Boolean)) &TDataStd_Comment::AfterRetrieval, "None", py::arg("forceIt"));
cls_TDataStd_Comment.def_static("get_type_name_", (const char * (*)()) &TDataStd_Comment::get_type_name, "None");
cls_TDataStd_Comment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Comment::get_type_descriptor, "None");
cls_TDataStd_Comment.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Comment::*)() const) &TDataStd_Comment::DynamicType, "None");

// Enums

}