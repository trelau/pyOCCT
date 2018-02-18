/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOMBasicString.hxx>
#include <LDOM_MemManager.hxx>
#include <LDOM_BasicElement.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <LDOM_Document.hxx>
#include <LDOMString.hxx>
#include <LDOM_Element.hxx>
#include <LDOM_CDATASection.hxx>
#include <LDOM_Comment.hxx>
#include <LDOM_Text.hxx>
#include <LDOM_NodeList.hxx>
#include <LDOM_BasicNode.hxx>
#include <LDOM_BasicAttribute.hxx>
#include <LDOM_Node.hxx>
#include <LDOM_Attr.hxx>
#include <LDOM_BasicText.hxx>
#include <LDOM_CharacterData.hxx>
#include <LDOM_OSStream.hxx>
#include <Standard_OStream.hxx>
#include <TCollection_AsciiString.hxx>
#include <LDOM_XmlReader.hxx>
#include <Standard_IStream.hxx>
#include <LDOM_CharReference.hxx>
#include <LDOM_DocumentType.hxx>
#include <LDOM_LDOMImplementation.hxx>
#include <LDOM_XmlWriter.hxx>

PYBIND11_MODULE(LDOM, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.LDOMBasicString");
	py::module::import("OCCT.LDOMString");
	py::module::import("OCCT.TCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_MemManager.hxx
	py::class_<LDOM_MemManager, opencascade::handle<LDOM_MemManager>, Standard_Transient> cls_LDOM_MemManager(mod, "LDOM_MemManager", "None");
	cls_LDOM_MemManager.def(py::init<const Standard_Integer>(), py::arg("aBlockSize"));
	cls_LDOM_MemManager.def("Allocate", (void * (LDOM_MemManager::*)(const Standard_Integer)) &LDOM_MemManager::Allocate, "None", py::arg("aSize"));
	// cls_LDOM_MemManager.def("HashedAllocate", [](LDOM_MemManager &self, const char * aString, const Standard_Integer theLen, Standard_Integer & theHash){ const char * rv = self.HashedAllocate(aString, theLen, theHash); return std::tuple<const char *, Standard_Integer &>(rv, theHash); }, "None", py::arg("aString"), py::arg("theLen"), py::arg("theHash"));
	// cls_LDOM_MemManager.def("HashedAllocate", (void (LDOM_MemManager::*)(const char *, const Standard_Integer, LDOMBasicString &)) &LDOM_MemManager::HashedAllocate, "None", py::arg("aString"), py::arg("theLen"), py::arg("theResult"));
	// cls_LDOM_MemManager.def_static("Hash_", (Standard_Integer (*)(const char *, const Standard_Integer)) &LDOM_MemManager::Hash, "None", py::arg("theString"), py::arg("theLen"));
	// cls_LDOM_MemManager.def_static("CompareStrings_", (Standard_Boolean (*)(const char *, const Standard_Integer, const char *)) &LDOM_MemManager::CompareStrings, "None", py::arg("theString"), py::arg("theHashValue"), py::arg("theHashedStr"));
	cls_LDOM_MemManager.def("Self", (const LDOM_MemManager & (LDOM_MemManager::*)() const ) &LDOM_MemManager::Self, "None");
	cls_LDOM_MemManager.def("RootElement", (const LDOM_BasicElement * (LDOM_MemManager::*)() const ) &LDOM_MemManager::RootElement, "None");
	cls_LDOM_MemManager.def_static("get_type_name_", (const char * (*)()) &LDOM_MemManager::get_type_name, "None");
	cls_LDOM_MemManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LDOM_MemManager::get_type_descriptor, "None");
	cls_LDOM_MemManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (LDOM_MemManager::*)() const ) &LDOM_MemManager::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_Document.hxx
	py::class_<LDOM_Document, std::unique_ptr<LDOM_Document, Deleter<LDOM_Document>>> cls_LDOM_Document(mod, "LDOM_Document", "None");
	cls_LDOM_Document.def(py::init<>());
	cls_LDOM_Document.def(py::init<const LDOM_MemManager &>(), py::arg("aMemManager"));
	cls_LDOM_Document.def_static("createDocument_", (LDOM_Document (*)(const LDOMString &)) &LDOM_Document::createDocument, "None", py::arg("theQualifiedName"));
	cls_LDOM_Document.def("createElement", (LDOM_Element (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createElement, "None", py::arg("theTagName"));
	cls_LDOM_Document.def("createCDATASection", (LDOM_CDATASection (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createCDATASection, "None", py::arg("theData"));
	cls_LDOM_Document.def("createComment", (LDOM_Comment (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createComment, "None", py::arg("theData"));
	cls_LDOM_Document.def("createTextNode", (LDOM_Text (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createTextNode, "None", py::arg("theData"));
	cls_LDOM_Document.def("getDocumentElement", (LDOM_Element (LDOM_Document::*)() const ) &LDOM_Document::getDocumentElement, "None");
	cls_LDOM_Document.def("getElementsByTagName", (LDOM_NodeList (LDOM_Document::*)(const LDOMString &) const ) &LDOM_Document::getElementsByTagName, "None", py::arg("theTagName"));
	cls_LDOM_Document.def("__eq__", (Standard_Boolean (LDOM_Document::*)(const LDOM_Document &) const ) &LDOM_Document::operator==, py::is_operator(), "None", py::arg("anOther"));
	cls_LDOM_Document.def("__ne__", (Standard_Boolean (LDOM_Document::*)(const LDOM_Document &) const ) &LDOM_Document::operator!=, py::is_operator(), "None", py::arg("anOther"));
	// FIXME cls_LDOM_Document.def("__eq__", (Standard_Boolean (LDOM_Document::*)(const LDOM_NullPtr *) const ) &LDOM_Document::operator==, py::is_operator(), "None", py::arg(""));
	// FIXME cls_LDOM_Document.def("__ne__", (Standard_Boolean (LDOM_Document::*)(const LDOM_NullPtr *) const ) &LDOM_Document::operator!=, py::is_operator(), "None", py::arg(""));
	cls_LDOM_Document.def("isNull", (Standard_Boolean (LDOM_Document::*)() const ) &LDOM_Document::isNull, "None");
	// FIXME cls_LDOM_Document.def("assign", (LDOM_Document & (LDOM_Document::*)(const LDOM_NullPtr *)) &LDOM_Document::operator=, py::is_operator(), "None", py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_BasicNode.hxx
	py::class_<LDOM_BasicNode, std::unique_ptr<LDOM_BasicNode, Deleter<LDOM_BasicNode>>> cls_LDOM_BasicNode(mod, "LDOM_BasicNode", "None");
	cls_LDOM_BasicNode.def("isNull", (Standard_Boolean (LDOM_BasicNode::*)() const ) &LDOM_BasicNode::isNull, "None");
	cls_LDOM_BasicNode.def("getNodeType", (LDOM_Node::NodeType (LDOM_BasicNode::*)() const ) &LDOM_BasicNode::getNodeType, "None");
	cls_LDOM_BasicNode.def("GetSibling", (const LDOM_BasicNode * (LDOM_BasicNode::*)() const ) &LDOM_BasicNode::GetSibling, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_BasicElement.hxx
	py::class_<LDOM_BasicElement, std::unique_ptr<LDOM_BasicElement, Deleter<LDOM_BasicElement>>, LDOM_BasicNode> cls_LDOM_BasicElement(mod, "LDOM_BasicElement", "None");
	cls_LDOM_BasicElement.def(py::init<>());
	// cls_LDOM_BasicElement.def_static("Create_", (LDOM_BasicElement & (*)(const char *, const Standard_Integer, const opencascade::handle<LDOM_MemManager> &)) &LDOM_BasicElement::Create, "None", py::arg("aName"), py::arg("aLength"), py::arg("aDoc"));
	// FIXME cls_LDOM_BasicElement.def("assign", (LDOM_BasicElement & (LDOM_BasicElement::*)(const LDOM_NullPtr *)) &LDOM_BasicElement::operator=, py::is_operator(), "None", py::arg("aNull"));
	cls_LDOM_BasicElement.def("GetTagName", (const char * (LDOM_BasicElement::*)() const ) &LDOM_BasicElement::GetTagName, "None");
	cls_LDOM_BasicElement.def("GetFirstChild", (const LDOM_BasicNode * (LDOM_BasicElement::*)() const ) &LDOM_BasicElement::GetFirstChild, "None");
	cls_LDOM_BasicElement.def("GetLastChild", (const LDOM_BasicNode * (LDOM_BasicElement::*)() const ) &LDOM_BasicElement::GetLastChild, "None");
	// cls_LDOM_BasicElement.def("GetAttribute", (const LDOM_BasicAttribute & (LDOM_BasicElement::*)(const LDOMBasicString &, const LDOM_BasicNode *) const ) &LDOM_BasicElement::GetAttribute, "None", py::arg("aName"), py::arg("aLastCh"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_Node.hxx
	py::class_<LDOM_Node, std::unique_ptr<LDOM_Node, Deleter<LDOM_Node>>> cls_LDOM_Node(mod, "LDOM_Node", "None");
	cls_LDOM_Node.def(py::init<>());
	cls_LDOM_Node.def(py::init([] (const LDOM_Node &other) {return new LDOM_Node(other);}), "Copy constructor", py::arg("other"));
	cls_LDOM_Node.def("getOwnerDocument", (const LDOM_MemManager & (LDOM_Node::*)() const ) &LDOM_Node::getOwnerDocument, "None");
	cls_LDOM_Node.def("assign", (LDOM_Node & (LDOM_Node::*)(const LDOM_Node &)) &LDOM_Node::operator=, py::is_operator(), "None", py::arg("anOther"));
	// FIXME cls_LDOM_Node.def("assign", (LDOM_Node & (LDOM_Node::*)(const LDOM_NullPtr *)) &LDOM_Node::operator=, py::is_operator(), "None", py::arg("aNull"));
	// FIXME cls_LDOM_Node.def("__eq__", (Standard_Boolean (LDOM_Node::*)(const LDOM_NullPtr *) const ) &LDOM_Node::operator==, py::is_operator(), "None", py::arg(""));
	// FIXME cls_LDOM_Node.def("__ne__", (Standard_Boolean (LDOM_Node::*)(const LDOM_NullPtr *) const ) &LDOM_Node::operator!=, py::is_operator(), "None", py::arg(""));
	cls_LDOM_Node.def("__eq__", (Standard_Boolean (LDOM_Node::*)(const LDOM_Node &) const ) &LDOM_Node::operator==, py::is_operator(), "None", py::arg("anOther"));
	cls_LDOM_Node.def("__ne__", (Standard_Boolean (LDOM_Node::*)(const LDOM_Node &) const ) &LDOM_Node::operator!=, py::is_operator(), "None", py::arg("anOther"));
	cls_LDOM_Node.def("isNull", (Standard_Boolean (LDOM_Node::*)() const ) &LDOM_Node::isNull, "None");
	cls_LDOM_Node.def("getNodeType", (LDOM_Node::NodeType (LDOM_Node::*)() const ) &LDOM_Node::getNodeType, "None");
	cls_LDOM_Node.def("getNodeName", (LDOMString (LDOM_Node::*)() const ) &LDOM_Node::getNodeName, "None");
	cls_LDOM_Node.def("getNodeValue", (LDOMString (LDOM_Node::*)() const ) &LDOM_Node::getNodeValue, "None");
	cls_LDOM_Node.def("getFirstChild", (LDOM_Node (LDOM_Node::*)() const ) &LDOM_Node::getFirstChild, "None");
	cls_LDOM_Node.def("getLastChild", (LDOM_Node (LDOM_Node::*)() const ) &LDOM_Node::getLastChild, "None");
	cls_LDOM_Node.def("getNextSibling", (LDOM_Node (LDOM_Node::*)() const ) &LDOM_Node::getNextSibling, "None");
	cls_LDOM_Node.def("removeChild", (void (LDOM_Node::*)(const LDOM_Node &)) &LDOM_Node::removeChild, "None", py::arg("aChild"));
	cls_LDOM_Node.def("appendChild", (void (LDOM_Node::*)(const LDOM_Node &)) &LDOM_Node::appendChild, "None", py::arg("aChild"));
	cls_LDOM_Node.def("hasChildNodes", (Standard_Boolean (LDOM_Node::*)() const ) &LDOM_Node::hasChildNodes, "None");
	cls_LDOM_Node.def("SetValueClear", (void (LDOM_Node::*)() const ) &LDOM_Node::SetValueClear, "None");
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_Node.hxx
	py::enum_<LDOM_Node::NodeType>(cls_LDOM_Node, "NodeType", "None")
		.value("UNKNOWN", LDOM_Node::NodeType::UNKNOWN)
		.value("ELEMENT_NODE", LDOM_Node::NodeType::ELEMENT_NODE)
		.value("ATTRIBUTE_NODE", LDOM_Node::NodeType::ATTRIBUTE_NODE)
		.value("TEXT_NODE", LDOM_Node::NodeType::TEXT_NODE)
		.value("CDATA_SECTION_NODE", LDOM_Node::NodeType::CDATA_SECTION_NODE)
		.value("COMMENT_NODE", LDOM_Node::NodeType::COMMENT_NODE)
		.export_values();

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_BasicAttribute.hxx
	py::class_<LDOM_BasicAttribute, std::unique_ptr<LDOM_BasicAttribute, Deleter<LDOM_BasicAttribute>>, LDOM_BasicNode> cls_LDOM_BasicAttribute(mod, "LDOM_BasicAttribute", "None");
	cls_LDOM_BasicAttribute.def(py::init<>());
	// FIXME cls_LDOM_BasicAttribute.def("assign", (LDOM_BasicAttribute & (LDOM_BasicAttribute::*)(const LDOM_NullPtr *)) &LDOM_BasicAttribute::operator=, py::is_operator(), "None", py::arg("aNull"));
	cls_LDOM_BasicAttribute.def("GetName", (const char * (LDOM_BasicAttribute::*)() const ) &LDOM_BasicAttribute::GetName, "None");
	// cls_LDOM_BasicAttribute.def("GetValue", (const LDOMBasicString & (LDOM_BasicAttribute::*)() const ) &LDOM_BasicAttribute::GetValue, "None");
	// cls_LDOM_BasicAttribute.def("SetValue", (void (LDOM_BasicAttribute::*)(const LDOMBasicString &, const opencascade::handle<LDOM_MemManager> &)) &LDOM_BasicAttribute::SetValue, "None", py::arg("aValue"), py::arg("aDoc"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_Element.hxx
	py::class_<LDOM_Element, std::unique_ptr<LDOM_Element, Deleter<LDOM_Element>>, LDOM_Node> cls_LDOM_Element(mod, "LDOM_Element", "None");
	cls_LDOM_Element.def(py::init<>());
	cls_LDOM_Element.def(py::init([] (const LDOM_Element &other) {return new LDOM_Element(other);}), "Copy constructor", py::arg("other"));
	cls_LDOM_Element.def("assign", (LDOM_Element & (LDOM_Element::*)(const LDOM_Element &)) &LDOM_Element::operator=, py::is_operator(), "None", py::arg("anOther"));
	// FIXME cls_LDOM_Element.def("assign", (LDOM_Element & (LDOM_Element::*)(const LDOM_NullPtr *)) &LDOM_Element::operator=, py::is_operator(), "None", py::arg("aNull"));
	cls_LDOM_Element.def("getTagName", (LDOMString (LDOM_Element::*)() const ) &LDOM_Element::getTagName, "None");
	cls_LDOM_Element.def("getAttribute", (LDOMString (LDOM_Element::*)(const LDOMString &) const ) &LDOM_Element::getAttribute, "None", py::arg("aName"));
	cls_LDOM_Element.def("getAttributeNode", (LDOM_Attr (LDOM_Element::*)(const LDOMString &) const ) &LDOM_Element::getAttributeNode, "None", py::arg("aName"));
	cls_LDOM_Element.def("getElementsByTagName", (LDOM_NodeList (LDOM_Element::*)(const LDOMString &) const ) &LDOM_Element::getElementsByTagName, "None", py::arg("aName"));
	cls_LDOM_Element.def("setAttribute", (void (LDOM_Element::*)(const LDOMString &, const LDOMString &)) &LDOM_Element::setAttribute, "None", py::arg("aName"), py::arg("aValue"));
	cls_LDOM_Element.def("setAttributeNode", (void (LDOM_Element::*)(const LDOM_Attr &)) &LDOM_Element::setAttributeNode, "None", py::arg("aNewAttr"));
	cls_LDOM_Element.def("removeAttribute", (void (LDOM_Element::*)(const LDOMString &)) &LDOM_Element::removeAttribute, "None", py::arg("aName"));
	cls_LDOM_Element.def("GetChildByTagName", (LDOM_Element (LDOM_Element::*)(const LDOMString &) const ) &LDOM_Element::GetChildByTagName, "None", py::arg("aTagName"));
	cls_LDOM_Element.def("GetSiblingByTagName", (LDOM_Element (LDOM_Element::*)() const ) &LDOM_Element::GetSiblingByTagName, "None");
	cls_LDOM_Element.def("ReplaceElement", (void (LDOM_Element::*)(const LDOM_Element &)) &LDOM_Element::ReplaceElement, "None", py::arg("anOther"));
	cls_LDOM_Element.def("GetAttributesList", (LDOM_NodeList (LDOM_Element::*)() const ) &LDOM_Element::GetAttributesList, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_Attr.hxx
	py::class_<LDOM_Attr, std::unique_ptr<LDOM_Attr, Deleter<LDOM_Attr>>, LDOM_Node> cls_LDOM_Attr(mod, "LDOM_Attr", "None");
	cls_LDOM_Attr.def(py::init<>());
	cls_LDOM_Attr.def(py::init([] (const LDOM_Attr &other) {return new LDOM_Attr(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_LDOM_Attr.def("assign", (LDOM_Attr & (LDOM_Attr::*)(const LDOM_NullPtr *)) &LDOM_Attr::operator=, py::is_operator(), "None", py::arg("aNull"));
	cls_LDOM_Attr.def("assign", (LDOM_Attr & (LDOM_Attr::*)(const LDOM_Attr &)) &LDOM_Attr::operator=, py::is_operator(), "None", py::arg("anOther"));
	cls_LDOM_Attr.def("getName", (LDOMString (LDOM_Attr::*)() const ) &LDOM_Attr::getName, "None");
	cls_LDOM_Attr.def("getValue", (LDOMString (LDOM_Attr::*)() const ) &LDOM_Attr::getValue, "None");
	cls_LDOM_Attr.def("setValue", (void (LDOM_Attr::*)(const LDOMString &)) &LDOM_Attr::setValue, "None", py::arg("aValue"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_NodeList.hxx
	py::class_<LDOM_BasicNodeSequence, std::unique_ptr<LDOM_BasicNodeSequence, Deleter<LDOM_BasicNodeSequence>>> cls_LDOM_BasicNodeSequence(mod, "LDOM_BasicNodeSequence", "None");
	cls_LDOM_BasicNodeSequence.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_NodeList.hxx
	py::class_<LDOM_NodeList, std::unique_ptr<LDOM_NodeList, Deleter<LDOM_NodeList>>> cls_LDOM_NodeList(mod, "LDOM_NodeList", "None");
	cls_LDOM_NodeList.def(py::init<>());
	cls_LDOM_NodeList.def(py::init([] (const LDOM_NodeList &other) {return new LDOM_NodeList(other);}), "Copy constructor", py::arg("other"));
	cls_LDOM_NodeList.def("assign", (LDOM_NodeList & (LDOM_NodeList::*)(const LDOM_NodeList &)) &LDOM_NodeList::operator=, py::is_operator(), "None", py::arg("theOther"));
	// FIXME cls_LDOM_NodeList.def("assign", (LDOM_NodeList & (LDOM_NodeList::*)(const LDOM_NullPtr *)) &LDOM_NodeList::operator=, py::is_operator(), "None", py::arg(""));
	// FIXME cls_LDOM_NodeList.def("__eq__", (Standard_Boolean (LDOM_NodeList::*)(const LDOM_NullPtr *) const ) &LDOM_NodeList::operator==, py::is_operator(), "None", py::arg(""));
	// FIXME cls_LDOM_NodeList.def("__ne__", (Standard_Boolean (LDOM_NodeList::*)(const LDOM_NullPtr *) const ) &LDOM_NodeList::operator!=, py::is_operator(), "None", py::arg(""));
	cls_LDOM_NodeList.def("item", (LDOM_Node (LDOM_NodeList::*)(const Standard_Integer) const ) &LDOM_NodeList::item, "None", py::arg(""));
	cls_LDOM_NodeList.def("getLength", (Standard_Integer (LDOM_NodeList::*)() const ) &LDOM_NodeList::getLength, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_BasicText.hxx
	py::class_<LDOM_BasicText, std::unique_ptr<LDOM_BasicText, Deleter<LDOM_BasicText>>, LDOM_BasicNode> cls_LDOM_BasicText(mod, "LDOM_BasicText", "None");
	cls_LDOM_BasicText.def(py::init<>());
	// FIXME cls_LDOM_BasicText.def("assign", (LDOM_BasicText & (LDOM_BasicText::*)(const LDOM_NullPtr *)) &LDOM_BasicText::operator=, py::is_operator(), "None", py::arg("aNull"));
	// cls_LDOM_BasicText.def("GetData", (const LDOMBasicString & (LDOM_BasicText::*)() const ) &LDOM_BasicText::GetData, "None");
	// cls_LDOM_BasicText.def("SetData", (void (LDOM_BasicText::*)(const LDOMBasicString &, const opencascade::handle<LDOM_MemManager> &)) &LDOM_BasicText::SetData, "None", py::arg("aValue"), py::arg("aDoc"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_CharacterData.hxx
	py::class_<LDOM_CharacterData, std::unique_ptr<LDOM_CharacterData, Deleter<LDOM_CharacterData>>, LDOM_Node> cls_LDOM_CharacterData(mod, "LDOM_CharacterData", "None");
	cls_LDOM_CharacterData.def(py::init<>());
	cls_LDOM_CharacterData.def(py::init([] (const LDOM_CharacterData &other) {return new LDOM_CharacterData(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_LDOM_CharacterData.def("assign", (LDOM_CharacterData & (LDOM_CharacterData::*)(const LDOM_NullPtr *)) &LDOM_CharacterData::operator=, py::is_operator(), "None", py::arg("aNull"));
	cls_LDOM_CharacterData.def("assign", (LDOM_CharacterData & (LDOM_CharacterData::*)(const LDOM_CharacterData &)) &LDOM_CharacterData::operator=, py::is_operator(), "None", py::arg("anOther"));
	cls_LDOM_CharacterData.def("getData", (LDOMString (LDOM_CharacterData::*)() const ) &LDOM_CharacterData::getData, "None");
	cls_LDOM_CharacterData.def("setData", (void (LDOM_CharacterData::*)(const LDOMString &)) &LDOM_CharacterData::setData, "None", py::arg("aValue"));
	cls_LDOM_CharacterData.def("getLength", (Standard_Integer (LDOM_CharacterData::*)() const ) &LDOM_CharacterData::getLength, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_Text.hxx
	py::class_<LDOM_Text, std::unique_ptr<LDOM_Text, Deleter<LDOM_Text>>, LDOM_CharacterData> cls_LDOM_Text(mod, "LDOM_Text", "None");
	cls_LDOM_Text.def(py::init<>());
	cls_LDOM_Text.def(py::init([] (const LDOM_Text &other) {return new LDOM_Text(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_LDOM_Text.def("assign", (LDOM_Text & (LDOM_Text::*)(const LDOM_NullPtr *)) &LDOM_Text::operator=, py::is_operator(), "None", py::arg("theNull"));
	cls_LDOM_Text.def("assign", (LDOM_Text & (LDOM_Text::*)(const LDOM_Text &)) &LDOM_Text::operator=, py::is_operator(), "None", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_CDATASection.hxx
	py::class_<LDOM_CDATASection, std::unique_ptr<LDOM_CDATASection, Deleter<LDOM_CDATASection>>, LDOM_Text> cls_LDOM_CDATASection(mod, "LDOM_CDATASection", "None");
	cls_LDOM_CDATASection.def(py::init<>());
	cls_LDOM_CDATASection.def(py::init([] (const LDOM_CDATASection &other) {return new LDOM_CDATASection(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_LDOM_CDATASection.def("assign", (LDOM_CDATASection & (LDOM_CDATASection::*)(const LDOM_NullPtr *)) &LDOM_CDATASection::operator=, py::is_operator(), "None", py::arg("theNull"));
	cls_LDOM_CDATASection.def("assign", (LDOM_CDATASection & (LDOM_CDATASection::*)(const LDOM_CDATASection &)) &LDOM_CDATASection::operator=, py::is_operator(), "None", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_Comment.hxx
	py::class_<LDOM_Comment, std::unique_ptr<LDOM_Comment, Deleter<LDOM_Comment>>, LDOM_CharacterData> cls_LDOM_Comment(mod, "LDOM_Comment", "None");
	cls_LDOM_Comment.def(py::init<>());
	cls_LDOM_Comment.def(py::init([] (const LDOM_Comment &other) {return new LDOM_Comment(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_LDOM_Comment.def("assign", (LDOM_Comment & (LDOM_Comment::*)(const LDOM_NullPtr *)) &LDOM_Comment::operator=, py::is_operator(), "None", py::arg("theNull"));
	cls_LDOM_Comment.def("assign", (LDOM_Comment & (LDOM_Comment::*)(const LDOM_Comment &)) &LDOM_Comment::operator=, py::is_operator(), "None", py::arg("theOther"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_OSStream.hxx
	py::class_<LDOM_SBuffer, std::unique_ptr<LDOM_SBuffer, Deleter<LDOM_SBuffer>>, std::streambuf> cls_LDOM_SBuffer(mod, "LDOM_SBuffer", "Class LDOM_SBuffer inherits streambuf and redefines some virtual methods of it (overflow() and xsputn()). This class contains pointers on first and current element of sequence, also it has methods for the sequence management.");
	cls_LDOM_SBuffer.def(py::init<const Standard_Integer>(), py::arg("theMaxBuf"));
	cls_LDOM_SBuffer.def("str", (Standard_CString (LDOM_SBuffer::*)() const ) &LDOM_SBuffer::str, "Concatenates strings of all sequence elements into one string. Space for output string is allocated with operator new. Caller of this function is responsible for memory release after the string usage.");
	cls_LDOM_SBuffer.def("Length", (Standard_Integer (LDOM_SBuffer::*)() const ) &LDOM_SBuffer::Length, "Returns full length of data contained");
	cls_LDOM_SBuffer.def("Clear", (void (LDOM_SBuffer::*)()) &LDOM_SBuffer::Clear, "Clears first element of sequence and removes all others");
	cls_LDOM_SBuffer.def("overflow", [](LDOM_SBuffer &self) -> int { return self.overflow(); });
	cls_LDOM_SBuffer.def("overflow", (int (LDOM_SBuffer::*)(int)) &LDOM_SBuffer::overflow, "None", py::arg("c"));
	cls_LDOM_SBuffer.def("underflow", (int (LDOM_SBuffer::*)()) &LDOM_SBuffer::underflow, "None");
	cls_LDOM_SBuffer.def("xsputn", (std::streamsize (LDOM_SBuffer::*)(const char *, std::streamsize)) &LDOM_SBuffer::xsputn, "None", py::arg("s"), py::arg("n"));
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_OSStream.hxx
	py::class_<LDOM_OSStream, std::unique_ptr<LDOM_OSStream, Deleter<LDOM_OSStream>>> cls_LDOM_OSStream(mod, "LDOM_OSStream", "Subclass if std::ostream allowing to increase performance of outputting data into a string avoiding reallocation of buffer. Class LDOM_OSStream implements output into a sequence of strings and getting the result as a string. It inherits Standard_OStream (ostream). Beside methods of ostream, it also has additional useful methods: str(), Length() and Clear().");
	cls_LDOM_OSStream.def(py::init<const Standard_Integer>(), py::arg("theMaxBuf"));
	cls_LDOM_OSStream.def("str", (Standard_CString (LDOM_OSStream::*)() const ) &LDOM_OSStream::str, "None");
	cls_LDOM_OSStream.def("Length", (Standard_Integer (LDOM_OSStream::*)() const ) &LDOM_OSStream::Length, "None");
	cls_LDOM_OSStream.def("Clear", (void (LDOM_OSStream::*)()) &LDOM_OSStream::Clear, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_XmlReader.hxx
	py::class_<LDOM_XmlReader, std::unique_ptr<LDOM_XmlReader, Deleter<LDOM_XmlReader>>> cls_LDOM_XmlReader(mod, "LDOM_XmlReader", "None");
	// cls_LDOM_XmlReader.def(py::init<const opencascade::handle<LDOM_MemManager> &, TCollection_AsciiString &>(), py::arg("aDocument"), py::arg("anErrorString"));
	// cls_LDOM_XmlReader.def(py::init<const opencascade::handle<LDOM_MemManager> &, TCollection_AsciiString &, const Standard_Boolean>(), py::arg("aDocument"), py::arg("anErrorString"), py::arg("theTagPerStep"));
	// cls_LDOM_XmlReader.def("ReadRecord", (LDOM_XmlReader::RecordType (LDOM_XmlReader::*)(Standard_IStream &, LDOM_OSStream &)) &LDOM_XmlReader::ReadRecord, "None", py::arg("theIStream"), py::arg("theData"));
	cls_LDOM_XmlReader.def("GetElement", (LDOM_BasicElement & (LDOM_XmlReader::*)() const ) &LDOM_XmlReader::GetElement, "None");
	// cls_LDOM_XmlReader.def("CreateElement", (void (LDOM_XmlReader::*)(const char *, const Standard_Integer)) &LDOM_XmlReader::CreateElement, "None", py::arg("theName"), py::arg("theLen"));
	// cls_LDOM_XmlReader.def_static("getInteger_", (Standard_Boolean (*)(LDOMBasicString &, const char *, const char *)) &LDOM_XmlReader::getInteger, "None", py::arg("theValue"), py::arg("theStart"), py::arg("theEnd"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_XmlReader.hxx
	py::enum_<LDOM_XmlReader::RecordType>(cls_LDOM_XmlReader, "RecordType", "None")
		.value("XML_UNKNOWN", LDOM_XmlReader::RecordType::XML_UNKNOWN)
		.value("XML_HEADER", LDOM_XmlReader::RecordType::XML_HEADER)
		.value("XML_DOCTYPE", LDOM_XmlReader::RecordType::XML_DOCTYPE)
		.value("XML_COMMENT", LDOM_XmlReader::RecordType::XML_COMMENT)
		.value("XML_START_ELEMENT", LDOM_XmlReader::RecordType::XML_START_ELEMENT)
		.value("XML_END_ELEMENT", LDOM_XmlReader::RecordType::XML_END_ELEMENT)
		.value("XML_FULL_ELEMENT", LDOM_XmlReader::RecordType::XML_FULL_ELEMENT)
		.value("XML_TEXT", LDOM_XmlReader::RecordType::XML_TEXT)
		.value("XML_CDATA", LDOM_XmlReader::RecordType::XML_CDATA)
		.value("XML_EOF", LDOM_XmlReader::RecordType::XML_EOF)
		.export_values();

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_BasicNode.hxx
	py::class_<LDOM_NullPtr, std::unique_ptr<LDOM_NullPtr, Deleter<LDOM_NullPtr>>> cls_LDOM_NullPtr(mod, "LDOM_NullPtr", "None");
	cls_LDOM_NullPtr.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_CharReference.hxx
	py::class_<LDOM_CharReference, std::unique_ptr<LDOM_CharReference, Deleter<LDOM_CharReference>>> cls_LDOM_CharReference(mod, "LDOM_CharReference", "None");
	cls_LDOM_CharReference.def(py::init<>());
	// cls_LDOM_CharReference.def_static("Decode_", [](char * theSrc, Standard_Integer & theLen){ char * rv = LDOM_CharReference::Decode(theSrc, theLen); return std::tuple<char *, Standard_Integer &>(rv, theLen); }, "None", py::arg("theSrc"), py::arg("theLen"));
	// cls_LDOM_CharReference.def_static("Encode_", [](const char * theSrc, Standard_Integer & theLen, const Standard_Boolean isAttribute){ char * rv = LDOM_CharReference::Encode(theSrc, theLen, isAttribute); return std::tuple<char *, Standard_Integer &>(rv, theLen); }, "None", py::arg("theSrc"), py::arg("theLen"), py::arg("isAttribute"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_DocumentType.hxx
	py::class_<LDOM_DocumentType, std::unique_ptr<LDOM_DocumentType, Deleter<LDOM_DocumentType>>> cls_LDOM_DocumentType(mod, "LDOM_DocumentType", "None");
	cls_LDOM_DocumentType.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_LDOMImplementation.hxx
	py::class_<LDOM_LDOMImplementation, std::unique_ptr<LDOM_LDOMImplementation, Deleter<LDOM_LDOMImplementation>>> cls_LDOM_LDOMImplementation(mod, "LDOM_LDOMImplementation", "None");
	cls_LDOM_LDOMImplementation.def(py::init<>());
	cls_LDOM_LDOMImplementation.def_static("createDocument_", (LDOM_Document (*)(const LDOMString &, const LDOMString &, const LDOM_DocumentType &)) &LDOM_LDOMImplementation::createDocument, "None", py::arg("aNamespaceURI"), py::arg("aQualifiedName"), py::arg("aDocType"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOM_XmlWriter.hxx
	py::class_<LDOM_XmlWriter, std::unique_ptr<LDOM_XmlWriter, Deleter<LDOM_XmlWriter>>> cls_LDOM_XmlWriter(mod, "LDOM_XmlWriter", "None");
	cls_LDOM_XmlWriter.def(py::init<>());
	cls_LDOM_XmlWriter.def(py::init<const char *>(), py::arg("theEncoding"));
	cls_LDOM_XmlWriter.def("SetIndentation", (void (LDOM_XmlWriter::*)(const Standard_Integer)) &LDOM_XmlWriter::SetIndentation, "None", py::arg("theIndent"));
	cls_LDOM_XmlWriter.def("Write", (void (LDOM_XmlWriter::*)(Standard_OStream &, const LDOM_Document &)) &LDOM_XmlWriter::Write, "None", py::arg("theOStream"), py::arg("theDoc"));
	cls_LDOM_XmlWriter.def("Write", (void (LDOM_XmlWriter::*)(Standard_OStream &, const LDOM_Node &)) &LDOM_XmlWriter::Write, "None", py::arg("theOStream"), py::arg("theNode"));


}
