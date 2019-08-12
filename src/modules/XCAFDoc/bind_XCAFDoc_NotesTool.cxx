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
#include <XCAFDoc_NotesTool.hxx>
#include <Standard_Type.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelSequence.hxx>
#include <XCAFDoc_AssemblyItemId.hxx>
#include <XCAFDoc_Note.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <OSD_File.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <XCAFDoc_AssemblyItemRef.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>

void bind_XCAFDoc_NotesTool(py::module &mod){

py::class_<XCAFDoc_NotesTool, opencascade::handle<XCAFDoc_NotesTool>, TDF_Attribute> cls_XCAFDoc_NotesTool(mod, "XCAFDoc_NotesTool", "A tool to annotate items in the hierarchical product structure. There are two basic entities, which operates the notes tool: notes and annotated items. A note is a user defined data structure derived from the notes hive. An annotated item is represented by attribute attached to a separate label under the annotated items hive. Notes are linked with annotated items by means of attribute. Notes play parent roles and annotated items - child roles.");

// Constructors
cls_XCAFDoc_NotesTool.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_NotesTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_NotesTool::get_type_name, "None");
cls_XCAFDoc_NotesTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_NotesTool::get_type_descriptor, "None");
cls_XCAFDoc_NotesTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::DynamicType, "None");
cls_XCAFDoc_NotesTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_NotesTool::GetID, "Returns default attribute GUID");
cls_XCAFDoc_NotesTool.def_static("Set_", (opencascade::handle<XCAFDoc_NotesTool> (*)(const TDF_Label &)) &XCAFDoc_NotesTool::Set, "Create (if not exist) a notes tool from XCAFDoc on theLabel.", py::arg("theLabel"));
cls_XCAFDoc_NotesTool.def("GetNotesLabel", (TDF_Label (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::GetNotesLabel, "Returns the label of the notes hive.");
cls_XCAFDoc_NotesTool.def("GetAnnotatedItemsLabel", (TDF_Label (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::GetAnnotatedItemsLabel, "Returns the label of the annotated items hive.");
cls_XCAFDoc_NotesTool.def("NbNotes", (Standard_Integer (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::NbNotes, "Returns the number of labels in the notes hive.");
cls_XCAFDoc_NotesTool.def("NbAnnotatedItems", (Standard_Integer (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::NbAnnotatedItems, "Returns the number of labels in the annotated items hive.");
cls_XCAFDoc_NotesTool.def("GetNotes", (void (XCAFDoc_NotesTool::*)(TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetNotes, "Returns all labels from the notes hive. The label sequence isn't cleared beforehand.", py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetAnnotatedItems", (void (XCAFDoc_NotesTool::*)(TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetAnnotatedItems, "Returns all labels from the annotated items hive. The label sequence isn't cleared beforehand.", py::arg("theLabels"));
cls_XCAFDoc_NotesTool.def("IsAnnotatedItem", (Standard_Boolean (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_NotesTool::IsAnnotatedItem, "Checks if the given assembly item is annotated.", py::arg("theItemId"));
cls_XCAFDoc_NotesTool.def("IsAnnotatedItem", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &) const) &XCAFDoc_NotesTool::IsAnnotatedItem, "Checks if the given labeled item is annotated.", py::arg("theItemLabel"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItem", (TDF_Label (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_NotesTool::FindAnnotatedItem, "Finds a label of the given assembly item ID in the annotated items hive.", py::arg("theItemId"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItem", (TDF_Label (XCAFDoc_NotesTool::*)(const TDF_Label &) const) &XCAFDoc_NotesTool::FindAnnotatedItem, "Finds a label of the given labeled item in the annotated items hive.", py::arg("theItemLabel"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItemAttr", (TDF_Label (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, const Standard_GUID &) const) &XCAFDoc_NotesTool::FindAnnotatedItemAttr, "Finds a label of the given assembly item's attribute in the annotated items hive.", py::arg("theItemId"), py::arg("theGUID"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItemAttr", (TDF_Label (XCAFDoc_NotesTool::*)(const TDF_Label &, const Standard_GUID &) const) &XCAFDoc_NotesTool::FindAnnotatedItemAttr, "Finds a label of the given labeled item's attribute in the annotated items hive.", py::arg("theItemLabel"), py::arg("theGUID"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItemSubshape", (TDF_Label (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, Standard_Integer) const) &XCAFDoc_NotesTool::FindAnnotatedItemSubshape, "Finds a label of the given assembly item's subshape in the annotated items hive.", py::arg("theItemId"), py::arg("theSubshapeIndex"));
cls_XCAFDoc_NotesTool.def("FindAnnotatedItemSubshape", (TDF_Label (XCAFDoc_NotesTool::*)(const TDF_Label &, Standard_Integer) const) &XCAFDoc_NotesTool::FindAnnotatedItemSubshape, "Finds a label of the given labeled item's subshape in the annotated items hive.", py::arg("theItemLabel"), py::arg("theSubshapeIndex"));
cls_XCAFDoc_NotesTool.def("CreateComment", (opencascade::handle<XCAFDoc_Note> (XCAFDoc_NotesTool::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_NotesTool::CreateComment, "Create a new comment note. Creates a new label under the notes hive and attaches attribute (derived ftom", py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theComment"));
cls_XCAFDoc_NotesTool.def("CreateBalloon", (opencascade::handle<XCAFDoc_Note> (XCAFDoc_NotesTool::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &)) &XCAFDoc_NotesTool::CreateBalloon, "Create a new 'balloon' note. Creates a new label under the notes hive and attaches attribute (derived ftom", py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theComment"));
cls_XCAFDoc_NotesTool.def("CreateBinData", (opencascade::handle<XCAFDoc_Note> (XCAFDoc_NotesTool::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, OSD_File &)) &XCAFDoc_NotesTool::CreateBinData, "Create a new note with data loaded from a binary file. Creates a new label under the notes hive and attaches attribute (derived ftom", py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theFile"));
cls_XCAFDoc_NotesTool.def("CreateBinData", (opencascade::handle<XCAFDoc_Note> (XCAFDoc_NotesTool::*)(const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_ExtendedString &, const TCollection_AsciiString &, const opencascade::handle<TColStd_HArray1OfByte> &)) &XCAFDoc_NotesTool::CreateBinData, "Create a new note with data loaded from a byte data array. Creates a new label under the notes hive and attaches attribute (derived ftom", py::arg("theUserName"), py::arg("theTimeStamp"), py::arg("theTitle"), py::arg("theMIMEtype"), py::arg("theData"));
cls_XCAFDoc_NotesTool.def("GetNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetNotes, "Gets all note labels of the assembly item. Notes linked to item's subshapes or attributes aren't taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemId"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetNotes, "Gets all note labels of the labeled item. Notes linked to item's attributes aren't taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemLabel"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetAttrNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, const Standard_GUID &, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetAttrNotes, "Gets all note labels of the assembly item's attribute. Notes linked to the item itself or to item's subshapes aren't taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemId"), py::arg("theGUID"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetAttrNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const TDF_Label &, const Standard_GUID &, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetAttrNotes, "Gets all note labels of the labeled item's attribute. Notes linked to the item itself or to item's subshapes aren't taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemLabel"), py::arg("theGUID"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("GetSubshapeNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, Standard_Integer, TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetSubshapeNotes, "Gets all note labels of the annotated item. Notes linked to the item itself or to item's attributes taken into account. The label sequence isn't cleared beforehand.", py::arg("theItemId"), py::arg("theSubshapeIndex"), py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("AddNote", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &)) &XCAFDoc_NotesTool::AddNote, "Adds the given note to the assembly item.", py::arg("theNoteLabel"), py::arg("theItemId"));
cls_XCAFDoc_NotesTool.def("AddNote", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &)) &XCAFDoc_NotesTool::AddNote, "Adds the given note to the labeled item.", py::arg("theNoteLabel"), py::arg("theItemLabel"));
cls_XCAFDoc_NotesTool.def("AddNoteToAttr", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, const Standard_GUID &)) &XCAFDoc_NotesTool::AddNoteToAttr, "Adds the given note to the assembly item's attribute.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theGUID"));
cls_XCAFDoc_NotesTool.def("AddNoteToAttr", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, const Standard_GUID &)) &XCAFDoc_NotesTool::AddNoteToAttr, "Adds the given note to the labeled item's attribute.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theGUID"));
cls_XCAFDoc_NotesTool.def("AddNoteToSubshape", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, Standard_Integer)) &XCAFDoc_NotesTool::AddNoteToSubshape, "Adds the given note to the assembly item's subshape.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theSubshapeIndex"));
cls_XCAFDoc_NotesTool.def("AddNoteToSubshape", (opencascade::handle<XCAFDoc_AssemblyItemRef> (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, Standard_Integer)) &XCAFDoc_NotesTool::AddNoteToSubshape, "Adds the given note to the labeled item's subshape.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theSubshapeIndex"));
cls_XCAFDoc_NotesTool.def("RemoveNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const XCAFDoc_AssemblyItemId & a1) -> Standard_Boolean { return self.RemoveNote(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveNote, "Removes the given note from the assembly item.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const TDF_Label & a1) -> Standard_Boolean { return self.RemoveNote(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveNote, "Removes the given note from the labeled item.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveSubshapeNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const XCAFDoc_AssemblyItemId & a1, Standard_Integer a2) -> Standard_Boolean { return self.RemoveSubshapeNote(a0, a1, a2); });
cls_XCAFDoc_NotesTool.def("RemoveSubshapeNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, Standard_Integer, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveSubshapeNote, "Removes the given note from the assembly item's subshape.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theSubshapeIndex"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveSubshapeNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const TDF_Label & a1, Standard_Integer a2) -> Standard_Boolean { return self.RemoveSubshapeNote(a0, a1, a2); });
cls_XCAFDoc_NotesTool.def("RemoveSubshapeNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, Standard_Integer, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveSubshapeNote, "Removes the given note from the labeled item's subshape.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theSubshapeIndex"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAttrNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const XCAFDoc_AssemblyItemId & a1, const Standard_GUID & a2) -> Standard_Boolean { return self.RemoveAttrNote(a0, a1, a2); });
cls_XCAFDoc_NotesTool.def("RemoveAttrNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const XCAFDoc_AssemblyItemId &, const Standard_GUID &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAttrNote, "Removes a note from the assembly item's attribute.", py::arg("theNoteLabel"), py::arg("theItemId"), py::arg("theGUID"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAttrNote", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const TDF_Label & a1, const Standard_GUID & a2) -> Standard_Boolean { return self.RemoveAttrNote(a0, a1, a2); });
cls_XCAFDoc_NotesTool.def("RemoveAttrNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const TDF_Label &, const Standard_GUID &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAttrNote, "Removes a note from the labeled item's attribute.", py::arg("theNoteLabel"), py::arg("theItemLabel"), py::arg("theGUID"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllNotes", [](XCAFDoc_NotesTool &self, const XCAFDoc_AssemblyItemId & a0) -> Standard_Boolean { return self.RemoveAllNotes(a0); });
cls_XCAFDoc_NotesTool.def("RemoveAllNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllNotes, "Removes all notes from the assembly item.", py::arg("theItemId"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllNotes", [](XCAFDoc_NotesTool &self, const TDF_Label & a0) -> Standard_Boolean { return self.RemoveAllNotes(a0); });
cls_XCAFDoc_NotesTool.def("RemoveAllNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllNotes, "Removes all notes from the labeled item.", py::arg("theItemLabel"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllSubshapeNotes", [](XCAFDoc_NotesTool &self, const XCAFDoc_AssemblyItemId & a0, Standard_Integer a1) -> Standard_Boolean { return self.RemoveAllSubshapeNotes(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveAllSubshapeNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, Standard_Integer, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllSubshapeNotes, "Removes all notes from the assembly item's subshape.", py::arg("theItemId"), py::arg("theSubshapeIndex"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllAttrNotes", [](XCAFDoc_NotesTool &self, const XCAFDoc_AssemblyItemId & a0, const Standard_GUID & a1) -> Standard_Boolean { return self.RemoveAllAttrNotes(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveAllAttrNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const XCAFDoc_AssemblyItemId &, const Standard_GUID &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllAttrNotes, "Removes all notes from the assembly item's attribute.", py::arg("theItemId"), py::arg("theGUID"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("RemoveAllAttrNotes", [](XCAFDoc_NotesTool &self, const TDF_Label & a0, const Standard_GUID & a1) -> Standard_Boolean { return self.RemoveAllAttrNotes(a0, a1); });
cls_XCAFDoc_NotesTool.def("RemoveAllAttrNotes", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &, const Standard_GUID &, Standard_Boolean)) &XCAFDoc_NotesTool::RemoveAllAttrNotes, "Removes all notes from the labeled item's attribute.", py::arg("theItemLabel"), py::arg("theGUID"), py::arg("theDelIfOrphan"));
cls_XCAFDoc_NotesTool.def("DeleteNote", (Standard_Boolean (XCAFDoc_NotesTool::*)(const TDF_Label &)) &XCAFDoc_NotesTool::DeleteNote, "Deletes the given note. Removes all links with items annotated by the note.", py::arg("theNoteLabel"));
cls_XCAFDoc_NotesTool.def("DeleteNotes", (Standard_Integer (XCAFDoc_NotesTool::*)(TDF_LabelSequence &)) &XCAFDoc_NotesTool::DeleteNotes, "Deletes the given notes. Removes all links with items annotated by the notes.", py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("DeleteAllNotes", (Standard_Integer (XCAFDoc_NotesTool::*)()) &XCAFDoc_NotesTool::DeleteAllNotes, "Deletes all notes. Clears all annotations.");
cls_XCAFDoc_NotesTool.def("NbOrphanNotes", (Standard_Integer (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::NbOrphanNotes, "Returns number of notes that aren't linked to annotated items.");
cls_XCAFDoc_NotesTool.def("GetOrphanNotes", (void (XCAFDoc_NotesTool::*)(TDF_LabelSequence &) const) &XCAFDoc_NotesTool::GetOrphanNotes, "Returns note labels that aren't linked to annotated items. The label sequence isn't cleared beforehand.", py::arg("theNoteLabels"));
cls_XCAFDoc_NotesTool.def("DeleteOrphanNotes", (Standard_Integer (XCAFDoc_NotesTool::*)()) &XCAFDoc_NotesTool::DeleteOrphanNotes, "Deletes all notes that aren't linked to annotated items.");
cls_XCAFDoc_NotesTool.def("ID", (const Standard_GUID & (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::ID, "@}");
cls_XCAFDoc_NotesTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_NotesTool::*)() const) &XCAFDoc_NotesTool::NewEmpty, "None");
cls_XCAFDoc_NotesTool.def("Restore", (void (XCAFDoc_NotesTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_NotesTool::Restore, "None", py::arg("theAttrFrom"));
cls_XCAFDoc_NotesTool.def("Paste", (void (XCAFDoc_NotesTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_NotesTool::Paste, "None", py::arg("theAttrInto"), py::arg("theRT"));
cls_XCAFDoc_NotesTool.def("Dump", (Standard_OStream & (XCAFDoc_NotesTool::*)(Standard_OStream &) const) &XCAFDoc_NotesTool::Dump, "None", py::arg("theOS"));

// Enums

}