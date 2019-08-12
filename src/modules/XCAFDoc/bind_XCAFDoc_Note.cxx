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
#include <Standard_Handle.hxx>
#include <XCAFDoc_Note.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <TCollection_ExtendedString.hxx>
#include <XCAFNoteObjects_NoteObject.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>

void bind_XCAFDoc_Note(py::module &mod){

py::class_<XCAFDoc_Note, opencascade::handle<XCAFDoc_Note>, TDF_Attribute> cls_XCAFDoc_Note(mod, "XCAFDoc_Note", "A base note attribute. Any note contains the name of the user created the note and the creation timestamp.");

// Fields

// Methods
cls_XCAFDoc_Note.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Note::get_type_name, "None");
cls_XCAFDoc_Note.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Note::get_type_descriptor, "None");
cls_XCAFDoc_Note.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Note::*)() const) &XCAFDoc_Note::DynamicType, "None");
cls_XCAFDoc_Note.def_static("IsMine_", (Standard_Boolean (*)(const TDF_Label &)) &XCAFDoc_Note::IsMine, "Checks if the given label represents a note.", py::arg("theLabel"));
cls_XCAFDoc_Note.def_static("Get_", (opencascade::handle<XCAFDoc_Note> (*)(const TDF_Label &)) &XCAFDoc_Note::Get, "Finds a reference attribute on the given label and returns it, if it is found", py::arg("theLabel"));
cls_XCAFDoc_Note.def("Set", (void (XCAFDoc_Note::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_Note::Set, "Sets the user name and the timestamp of the note.", py::arg("theUserName"), py::arg("theTimeStamp"));
cls_XCAFDoc_Note.def("UserName", (const TCollection_ExtendedString & (XCAFDoc_Note::*)() const) &XCAFDoc_Note::UserName, "Returns the user name, who created the note.");
cls_XCAFDoc_Note.def("TimeStamp", (const TCollection_ExtendedString & (XCAFDoc_Note::*)() const) &XCAFDoc_Note::TimeStamp, "Returns the timestamp of the note.");
cls_XCAFDoc_Note.def("IsOrphan", (Standard_Boolean (XCAFDoc_Note::*)() const) &XCAFDoc_Note::IsOrphan, "Checks if the note isn't linked to annotated items.");
cls_XCAFDoc_Note.def("GetObject", (opencascade::handle<XCAFNoteObjects_NoteObject> (XCAFDoc_Note::*)() const) &XCAFDoc_Note::GetObject, "Returns auxiliary data object");
cls_XCAFDoc_Note.def("SetObject", (void (XCAFDoc_Note::*)(const opencascade::handle<XCAFNoteObjects_NoteObject> &)) &XCAFDoc_Note::SetObject, "Updates auxiliary data", py::arg("theObject"));
cls_XCAFDoc_Note.def("Restore", (void (XCAFDoc_Note::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Note::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_Note.def("Paste", (void (XCAFDoc_Note::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Note::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_Note.def("Dump", (Standard_OStream & (XCAFDoc_Note::*)(Standard_OStream &) const) &XCAFDoc_Note::Dump, "None", py::arg("theOS"));

// Enums

}