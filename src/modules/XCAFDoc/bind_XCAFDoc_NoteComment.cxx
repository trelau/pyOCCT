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
#include <XCAFDoc_Note.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_NoteComment.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDF_Attribute.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>

void bind_XCAFDoc_NoteComment(py::module &mod){

py::class_<XCAFDoc_NoteComment, opencascade::handle<XCAFDoc_NoteComment>, XCAFDoc_Note> cls_XCAFDoc_NoteComment(mod, "XCAFDoc_NoteComment", "A comment note attribute. Contains a textual comment.");

// Constructors
cls_XCAFDoc_NoteComment.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_NoteComment.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_NoteComment::get_type_name, "None");
cls_XCAFDoc_NoteComment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_NoteComment::get_type_descriptor, "None");
cls_XCAFDoc_NoteComment.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_NoteComment::*)() const) &XCAFDoc_NoteComment::DynamicType, "None");
cls_XCAFDoc_NoteComment.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_NoteComment::GetID, "Returns default attribute GUID");
cls_XCAFDoc_NoteComment.def_static("Get_", (opencascade::handle<XCAFDoc_NoteComment> (*)(const TDF_Label &)) &XCAFDoc_NoteComment::Get, "Finds a reference attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_NoteComment.def_static("Set_", (opencascade::handle<XCAFDoc_NoteComment> (*)(const TDF_Label &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_NoteComment::Set, "Create (if not exist) a comment note on the given label.", py::arg("theLabel"), py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theComment"));
cls_XCAFDoc_NoteComment.def("Set", (void (XCAFDoc_NoteComment::*)(const TCollection_ExtendedString &)) &XCAFDoc_NoteComment::Set, "Sets the comment text.", py::arg("theComment"));
cls_XCAFDoc_NoteComment.def("Comment", (const TCollection_ExtendedString & (XCAFDoc_NoteComment::*)() const) &XCAFDoc_NoteComment::Comment, "Returns the comment text.");
cls_XCAFDoc_NoteComment.def("ID", (const Standard_GUID & (XCAFDoc_NoteComment::*)() const) &XCAFDoc_NoteComment::ID, "None");
cls_XCAFDoc_NoteComment.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_NoteComment::*)() const) &XCAFDoc_NoteComment::NewEmpty, "None");
cls_XCAFDoc_NoteComment.def("Restore", (void (XCAFDoc_NoteComment::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_NoteComment::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_NoteComment.def("Paste", (void (XCAFDoc_NoteComment::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_NoteComment::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_NoteComment.def("Dump", (Standard_OStream & (XCAFDoc_NoteComment::*)(Standard_OStream &) const) &XCAFDoc_NoteComment::Dump, "None", py::arg("theOS"));

// Enums

}