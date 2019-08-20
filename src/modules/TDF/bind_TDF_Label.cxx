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
#include <Standard_Handle.hxx>
#include <TDF_Data.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_OStream.hxx>
#include <TDF_IDFilter.hxx>
#include <TDF_AttributeIndexedMap.hxx>
#include <TDF_ChildIterator.hxx>
#include <TDF_AttributeIterator.hxx>
#include <TDF_LabelMapHasher.hxx>
#include <TDF_LabelNodePtr.hxx>

void bind_TDF_Label(py::module &mod){

py::class_<TDF_Label, std::unique_ptr<TDF_Label>> cls_TDF_Label(mod, "TDF_Label", "This class provides basic operations to define a label in a data structure. A label is a feature in the feature hierarchy. A label is always connected to a Data from TDF. To a label is attached attributes containing the software components information.");

// Constructors
cls_TDF_Label.def(py::init<>());

// Fields

// Methods
// cls_TDF_Label.def_static("operator new_", (void * (*)(size_t)) &TDF_Label::operator new, "None", py::arg("theSize"));
// cls_TDF_Label.def_static("operator delete_", (void (*)(void *)) &TDF_Label::operator delete, "None", py::arg("theAddress"));
// cls_TDF_Label.def_static("operator new[]_", (void * (*)(size_t)) &TDF_Label::operator new[], "None", py::arg("theSize"));
// cls_TDF_Label.def_static("operator delete[]_", (void (*)(void *)) &TDF_Label::operator delete[], "None", py::arg("theAddress"));
// cls_TDF_Label.def_static("operator new_", (void * (*)(size_t, void *)) &TDF_Label::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDF_Label.def_static("operator delete_", (void (*)(void *, void *)) &TDF_Label::operator delete, "None", py::arg(""), py::arg(""));
cls_TDF_Label.def("Nullify", (void (TDF_Label::*)()) &TDF_Label::Nullify, "Nullifies the label.");
cls_TDF_Label.def("Data", (opencascade::handle<TDF_Data> (TDF_Label::*)() const) &TDF_Label::Data, "Returns the Data owning <me>.");
cls_TDF_Label.def("Tag", (Standard_Integer (TDF_Label::*)() const) &TDF_Label::Tag, "Returns the tag of the label. This is the integer assigned randomly to a label in a data framework. This integer is used to identify this label in an entry.");
cls_TDF_Label.def("Father", (const TDF_Label (TDF_Label::*)() const) &TDF_Label::Father, "Returns the label father. This label may be null if the label is root.");
cls_TDF_Label.def("IsNull", (Standard_Boolean (TDF_Label::*)() const) &TDF_Label::IsNull, "Returns True if the <aLabel> is null, i.e. it has not been included in the data framework.");
cls_TDF_Label.def("Imported", (void (TDF_Label::*)(const Standard_Boolean) const) &TDF_Label::Imported, "Sets or unsets <me> and all its descendants as imported label, according to <aStatus>.", py::arg("aStatus"));
cls_TDF_Label.def("IsImported", (Standard_Boolean (TDF_Label::*)() const) &TDF_Label::IsImported, "Returns True if the <aLabel> is imported.");
cls_TDF_Label.def("IsEqual", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const) &TDF_Label::IsEqual, "Returns True if the <aLabel> is equal to me (same LabelNode*).", py::arg("aLabel"));
cls_TDF_Label.def("__eq__", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const) &TDF_Label::operator==, py::is_operator(), "None", py::arg("aLabel"));
cls_TDF_Label.def("IsDifferent", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const) &TDF_Label::IsDifferent, "None", py::arg("aLabel"));
cls_TDF_Label.def("__ne__", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const) &TDF_Label::operator!=, py::is_operator(), "None", py::arg("aLabel"));
cls_TDF_Label.def("IsRoot", (Standard_Boolean (TDF_Label::*)() const) &TDF_Label::IsRoot, "None");
cls_TDF_Label.def("IsAttribute", (Standard_Boolean (TDF_Label::*)(const Standard_GUID &) const) &TDF_Label::IsAttribute, "Returns true if <me> owns an attribute with <anID> as ID.", py::arg("anID"));
cls_TDF_Label.def("AddAttribute", [](TDF_Label &self, const opencascade::handle<TDF_Attribute> & a0) -> void { return self.AddAttribute(a0); });
cls_TDF_Label.def("AddAttribute", (void (TDF_Label::*)(const opencascade::handle<TDF_Attribute> &, const Standard_Boolean) const) &TDF_Label::AddAttribute, "Adds an Attribute to the current label. Raises if there is already one.", py::arg("anAttribute"), py::arg("append"));
cls_TDF_Label.def("ForgetAttribute", (void (TDF_Label::*)(const opencascade::handle<TDF_Attribute> &) const) &TDF_Label::ForgetAttribute, "Forgets an Attribute from the current label, setting its forgotten status true and its valid status false. Raises if the attribute is not in the structure.", py::arg("anAttribute"));
cls_TDF_Label.def("ForgetAttribute", (Standard_Boolean (TDF_Label::*)(const Standard_GUID &) const) &TDF_Label::ForgetAttribute, "Forgets the Attribute of GUID <aguid> from the current label . If the attribute doesn't exist returns False. Otherwise returns True.", py::arg("aguid"));
cls_TDF_Label.def("ForgetAllAttributes", [](TDF_Label &self) -> void { return self.ForgetAllAttributes(); });
cls_TDF_Label.def("ForgetAllAttributes", (void (TDF_Label::*)(const Standard_Boolean) const) &TDF_Label::ForgetAllAttributes, "Forgets all the attributes. Does it on also on the sub-labels if <clearChildren> is set to true. Of course, this method is compatible with Transaction & Delta mecanisms.", py::arg("clearChildren"));
cls_TDF_Label.def("ResumeAttribute", (void (TDF_Label::*)(const opencascade::handle<TDF_Attribute> &) const) &TDF_Label::ResumeAttribute, "Undo Forget action, setting its forgotten status false and its valid status true. Raises if the attribute is not in the structure.", py::arg("anAttribute"));
cls_TDF_Label.def("FindAttribute", (Standard_Boolean (TDF_Label::*)(const Standard_GUID &, opencascade::handle<TDF_Attribute> &) const) &TDF_Label::FindAttribute, "Finds an attribute of the current label, according to <anID>. If anAttribute is not a valid one, false is returned.", py::arg("anID"), py::arg("anAttribute"));
cls_TDF_Label.def("FindAttribute", (Standard_Boolean (TDF_Label::*)(const Standard_GUID &, const Standard_Integer, opencascade::handle<TDF_Attribute> &) const) &TDF_Label::FindAttribute, "Finds an attribute of the current label, according to <anID> and <aTransaction>. This attribute has/had to be a valid one for the given transaction index . So, this attribute is not necessary a valid one.", py::arg("anID"), py::arg("aTransaction"), py::arg("anAttribute"));
cls_TDF_Label.def("MayBeModified", (Standard_Boolean (TDF_Label::*)() const) &TDF_Label::MayBeModified, "Returns true if <me> or a DESCENDANT of <me> owns attributes not yet available in transaction 0. It means at least one of their attributes is new, modified or deleted.");
cls_TDF_Label.def("AttributesModified", (Standard_Boolean (TDF_Label::*)() const) &TDF_Label::AttributesModified, "Returns true if <me> owns attributes not yet available in transaction 0. It means at least one attribute is new, modified or deleted.");
cls_TDF_Label.def("HasAttribute", (Standard_Boolean (TDF_Label::*)() const) &TDF_Label::HasAttribute, "Returns true if this label has at least one attribute.");
cls_TDF_Label.def("NbAttributes", (Standard_Integer (TDF_Label::*)() const) &TDF_Label::NbAttributes, "Returns the number of attributes.");
cls_TDF_Label.def("Depth", (Standard_Integer (TDF_Label::*)() const) &TDF_Label::Depth, "Returns the depth of the label in the data framework. This corresponds to the number of fathers which this label has, and is used in determining whether a label is root, null or equivalent to another label. Exceptions: Standard_NullObject if this label is null. This is because a null object can have no depth.");
cls_TDF_Label.def("IsDescendant", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const) &TDF_Label::IsDescendant, "Returns True if <me> is a descendant of <aLabel>. Attention: every label is its own descendant.", py::arg("aLabel"));
cls_TDF_Label.def("Root", (const TDF_Label (TDF_Label::*)() const) &TDF_Label::Root, "Returns the root label Root of the data structure. This has a depth of 0. Exceptions: Standard_NullObject if this label is null. This is because a null object can have no depth.");
cls_TDF_Label.def("HasChild", (Standard_Boolean (TDF_Label::*)() const) &TDF_Label::HasChild, "Returns true if this label has at least one child.");
cls_TDF_Label.def("NbChildren", (Standard_Integer (TDF_Label::*)() const) &TDF_Label::NbChildren, "Returns the number of children.");
cls_TDF_Label.def("FindChild", [](TDF_Label &self, const Standard_Integer a0) -> TDF_Label { return self.FindChild(a0); });
cls_TDF_Label.def("FindChild", (TDF_Label (TDF_Label::*)(const Standard_Integer, const Standard_Boolean) const) &TDF_Label::FindChild, "Finds a child label having <aTag> as tag. Creates The tag aTag identifies the label which will be the parent. If create is true and no child label is found, a new one is created. Example: //creating a label with tag 10 at Root TDF_Label lab1 = aDF->Root().FindChild(10); //creating labels 7 and 2 on label 10 TDF_Label lab2 = lab1.FindChild(7); TDF_Label lab3 = lab1.FindChild(2);", py::arg("aTag"), py::arg("create"));
cls_TDF_Label.def("NewChild", (TDF_Label (TDF_Label::*)() const) &TDF_Label::NewChild, "Create a new child label of me using autoamtic delivery tags provided by TagSource.");
cls_TDF_Label.def("Transaction", (Standard_Integer (TDF_Label::*)() const) &TDF_Label::Transaction, "Returns the current transaction index.");
cls_TDF_Label.def("HasLowerNode", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const) &TDF_Label::HasLowerNode, "Returns true if node address of <me> is lower than <otherLabel> one. Used to quickly sort labels (not on entry criterion).", py::arg("otherLabel"));
cls_TDF_Label.def("HasGreaterNode", (Standard_Boolean (TDF_Label::*)(const TDF_Label &) const) &TDF_Label::HasGreaterNode, "Returns true if node address of <me> is greater than <otherLabel> one. Used to quickly sort labels (not on entry criterion).", py::arg("otherLabel"));
cls_TDF_Label.def("Dump", (Standard_OStream & (TDF_Label::*)(Standard_OStream &) const) &TDF_Label::Dump, "Dumps the minimum information about <me> on <aStream>.", py::arg("anOS"));
cls_TDF_Label.def("bits_left", (Standard_OStream & (TDF_Label::*)(Standard_OStream &) const) &TDF_Label::operator<<, py::is_operator(), "None", py::arg("anOS"));
cls_TDF_Label.def("ExtendedDump", (void (TDF_Label::*)(Standard_OStream &, const TDF_IDFilter &, TDF_AttributeIndexedMap &) const) &TDF_Label::ExtendedDump, "Dumps the label on <aStream> and its attributes rank in <aMap> if their IDs are kept by <IDFilter>.", py::arg("anOS"), py::arg("aFilter"), py::arg("aMap"));
cls_TDF_Label.def("EntryDump", (void (TDF_Label::*)(Standard_OStream &) const) &TDF_Label::EntryDump, "Dumps the label entry.", py::arg("anOS"));

// Enums

}