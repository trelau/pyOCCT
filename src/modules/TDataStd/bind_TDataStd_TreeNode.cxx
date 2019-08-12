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
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_TreeNode.hxx>
#include <Standard_GUID.hxx>
#include <TDF_AttributeDelta.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <TDataStd_ChildNodeIterator.hxx>
#include <Standard_Type.hxx>
#include <TDataStd_PtrTreeNode.hxx>

void bind_TDataStd_TreeNode(py::module &mod){

py::class_<TDataStd_TreeNode, opencascade::handle<TDataStd_TreeNode>, TDF_Attribute> cls_TDataStd_TreeNode(mod, "TDataStd_TreeNode", "Allows you to define an explicit tree of labels which you can also edit. Without this class, the data structure cannot be fully edited. This service is required if for presentation purposes, you want to create an application with a tree which allows you to organize and link data as a function of application features.");

// Constructors
cls_TDataStd_TreeNode.def(py::init<>());

// Fields

// Methods
cls_TDataStd_TreeNode.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::Find, "class methods working on the node =================================== Returns true if the tree node T is found on the label L. Otherwise, false is returned.", py::arg("L"), py::arg("T"));
cls_TDataStd_TreeNode.def_static("Set_", (opencascade::handle<TDataStd_TreeNode> (*)(const TDF_Label &)) &TDataStd_TreeNode::Set, "Finds or Creates a TreeNode attribute on the label <L> with the default tree ID, returned by the method <GetDefaultTreeID>. Returns the created/found TreeNode attribute.", py::arg("L"));
cls_TDataStd_TreeNode.def_static("Set_", (opencascade::handle<TDataStd_TreeNode> (*)(const TDF_Label &, const Standard_GUID &)) &TDataStd_TreeNode::Set, "Finds or Creates a TreeNode attribute on the label <L>, with an explicit tree ID. <ExplicitTreeID> is the ID returned by <TDF_Attribute::ID> method. Returns the found/created TreeNode attribute.", py::arg("L"), py::arg("ExplicitTreeID"));
cls_TDataStd_TreeNode.def_static("GetDefaultTreeID_", (const Standard_GUID & (*)()) &TDataStd_TreeNode::GetDefaultTreeID, "returns a default tree ID. this ID is used by the <Set> method without explicit tree ID. Instance methods: ================");
cls_TDataStd_TreeNode.def("Append", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::Append, "Insert the TreeNode <Child> as last child of <me>. If the insertion is successful <me> becomes the Father of <Child>.", py::arg("Child"));
cls_TDataStd_TreeNode.def("Prepend", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::Prepend, "Insert the the TreeNode <Child> as first child of <me>. If the insertion is successful <me> becomes the Father of <Child>", py::arg("Child"));
cls_TDataStd_TreeNode.def("InsertBefore", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::InsertBefore, "Inserts the TreeNode <Node> before <me>. If insertion is successful <me> and <Node> belongs to the same Father.", py::arg("Node"));
cls_TDataStd_TreeNode.def("InsertAfter", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::InsertAfter, "Inserts the TreeNode <Node> after <me>. If insertion is successful <me> and <Node> belongs to the same Father.", py::arg("Node"));
cls_TDataStd_TreeNode.def("Remove", (Standard_Boolean (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::Remove, "Removes this tree node attribute from its father node. The result is that this attribute becomes a root node.");
cls_TDataStd_TreeNode.def("Depth", (Standard_Integer (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Depth, "Returns the depth of this tree node in the overall tree node structure. In other words, the number of father tree nodes of this one is returned.");
cls_TDataStd_TreeNode.def("NbChildren", [](TDataStd_TreeNode &self) -> Standard_Integer { return self.NbChildren(); });
cls_TDataStd_TreeNode.def("NbChildren", (Standard_Integer (TDataStd_TreeNode::*)(const Standard_Boolean) const) &TDataStd_TreeNode::NbChildren, "Returns the number of child nodes. If <allLevels> is true, the method counts children of all levels (children of children ...)", py::arg("allLevels"));
cls_TDataStd_TreeNode.def("IsAscendant", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &) const) &TDataStd_TreeNode::IsAscendant, "Returns true if this tree node attribute is an ascendant of of. In other words, if it is a father or the father of a father of of.", py::arg("of"));
cls_TDataStd_TreeNode.def("IsDescendant", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &) const) &TDataStd_TreeNode::IsDescendant, "Returns true if this tree node attribute is a descendant of of. In other words, if it is a child or the child of a child of of.", py::arg("of"));
cls_TDataStd_TreeNode.def("IsRoot", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::IsRoot, "Returns true if this tree node attribute is the ultimate father in the tree.");
cls_TDataStd_TreeNode.def("Root", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Root, "Returns the ultimate father of this tree node attribute.");
cls_TDataStd_TreeNode.def("IsFather", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &) const) &TDataStd_TreeNode::IsFather, "Returns true if this tree node attribute is a father of of.", py::arg("of"));
cls_TDataStd_TreeNode.def("IsChild", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &) const) &TDataStd_TreeNode::IsChild, "Returns true if this tree node attribute is a child of of.", py::arg("of"));
cls_TDataStd_TreeNode.def("HasFather", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasFather, "Returns true if this tree node attribute has a father tree node.");
cls_TDataStd_TreeNode.def("Father", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Father, "Returns the father TreeNode of <me>. Null if root.");
cls_TDataStd_TreeNode.def("HasNext", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasNext, "Returns true if this tree node attribute has a next tree node.");
cls_TDataStd_TreeNode.def("Next", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Next, "Returns the next tree node in this tree node attribute. Warning This tree node is null if it is the last one in this tree node attribute.Returns the next TreeNode of <me>. Null if last.");
cls_TDataStd_TreeNode.def("HasPrevious", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasPrevious, "Returns true if this tree node attribute has a previous tree node.");
cls_TDataStd_TreeNode.def("Previous", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::Previous, "Returns the previous tree node of this tree node attribute. Warning This tree node is null if it is the first one in this tree node attribute.");
cls_TDataStd_TreeNode.def("HasFirst", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasFirst, "Returns true if this tree node attribute has a first child tree node.");
cls_TDataStd_TreeNode.def("First", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::First, "Returns the first child tree node in this tree node object.");
cls_TDataStd_TreeNode.def("HasLast", (Standard_Boolean (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::HasLast, "Returns true if this tree node attribute has a last child tree node.");
cls_TDataStd_TreeNode.def("Last", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::Last, "Returns the last child tree node in this tree node object.");
cls_TDataStd_TreeNode.def("FindLast", (opencascade::handle<TDataStd_TreeNode> (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::FindLast, "Returns the last child tree node in this tree node object. to set fields =============");
cls_TDataStd_TreeNode.def("SetTreeID", (void (TDataStd_TreeNode::*)(const Standard_GUID &)) &TDataStd_TreeNode::SetTreeID, "None", py::arg("explicitID"));
cls_TDataStd_TreeNode.def("SetFather", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetFather, "None", py::arg("F"));
cls_TDataStd_TreeNode.def("SetNext", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetNext, "None", py::arg("F"));
cls_TDataStd_TreeNode.def("SetPrevious", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetPrevious, "None", py::arg("F"));
cls_TDataStd_TreeNode.def("SetFirst", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetFirst, "None", py::arg("F"));
cls_TDataStd_TreeNode.def("SetLast", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDataStd_TreeNode> &)) &TDataStd_TreeNode::SetLast, "TreeNode callback: ==================", py::arg("F"));
cls_TDataStd_TreeNode.def("AfterAddition", (void (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::AfterAddition, "Connect the TreeNode to its father child list");
cls_TDataStd_TreeNode.def("BeforeForget", (void (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::BeforeForget, "Disconnect the TreeNode from its Father child list");
cls_TDataStd_TreeNode.def("AfterResume", (void (TDataStd_TreeNode::*)()) &TDataStd_TreeNode::AfterResume, "Reconnect the TreeNode to its father child list.");
cls_TDataStd_TreeNode.def("BeforeUndo", [](TDataStd_TreeNode &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.BeforeUndo(a0); });
cls_TDataStd_TreeNode.def("BeforeUndo", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDataStd_TreeNode::BeforeUndo, "Disconnect the TreeNode, if necessary.", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TDataStd_TreeNode.def("AfterUndo", [](TDataStd_TreeNode &self, const opencascade::handle<TDF_AttributeDelta> & a0) -> Standard_Boolean { return self.AfterUndo(a0); });
cls_TDataStd_TreeNode.def("AfterUndo", (Standard_Boolean (TDataStd_TreeNode::*)(const opencascade::handle<TDF_AttributeDelta> &, const Standard_Boolean)) &TDataStd_TreeNode::AfterUndo, "Reconnect the TreeNode, if necessary. Implementation of Attribute methods: ===================================", py::arg("anAttDelta"), py::arg("forceIt"));
cls_TDataStd_TreeNode.def("ID", (const Standard_GUID & (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::ID, "Returns the tree ID (default or explicit one depending onthe Set method used).");
cls_TDataStd_TreeNode.def("Restore", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_TreeNode::Restore, "None", py::arg("with"));
cls_TDataStd_TreeNode.def("Paste", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_TreeNode::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataStd_TreeNode.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::NewEmpty, "None");
cls_TDataStd_TreeNode.def("References", (void (TDataStd_TreeNode::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataStd_TreeNode::References, "None", py::arg("aDataSet"));
cls_TDataStd_TreeNode.def("Dump", (Standard_OStream & (TDataStd_TreeNode::*)(Standard_OStream &) const) &TDataStd_TreeNode::Dump, "None", py::arg("anOS"));
cls_TDataStd_TreeNode.def_static("get_type_name_", (const char * (*)()) &TDataStd_TreeNode::get_type_name, "None");
cls_TDataStd_TreeNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_TreeNode::get_type_descriptor, "None");
cls_TDataStd_TreeNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_TreeNode::*)() const) &TDataStd_TreeNode::DynamicType, "None");

// Enums

}