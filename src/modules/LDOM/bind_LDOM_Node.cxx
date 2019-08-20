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
#include <LDOM_Node.hxx>
#include <LDOM_MemManager.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOMString.hxx>
#include <LDOM_BasicAttribute.hxx>
#include <LDOM_BasicElement.hxx>
#include <LDOM_BasicText.hxx>
#include <LDOM_NodeList.hxx>
#include <LDOM_BasicNode.hxx>
#include <Standard_Handle.hxx>

void bind_LDOM_Node(py::module &mod){

py::class_<LDOM_Node, std::unique_ptr<LDOM_Node>> cls_LDOM_Node(mod, "LDOM_Node", "None");

// Constructors
cls_LDOM_Node.def(py::init<>());
cls_LDOM_Node.def(py::init<const LDOM_Node &>(), py::arg("anOther"));

// Fields

// Methods
cls_LDOM_Node.def("getOwnerDocument", (const LDOM_MemManager & (LDOM_Node::*)() const) &LDOM_Node::getOwnerDocument, "None");
// cls_LDOM_Node.def("operator=", (LDOM_Node & (LDOM_Node::*)(const LDOM_Node &)) &LDOM_Node::operator=, "None", py::arg("anOther"));
// cls_LDOM_Node.def("operator=", (LDOM_Node & (LDOM_Node::*)(const LDOM_NullPtr *)) &LDOM_Node::operator=, "None", py::arg("aNull"));
// cls_LDOM_Node.def("__eq__", (Standard_Boolean (LDOM_Node::*)(const LDOM_NullPtr *) const) &LDOM_Node::operator==, py::is_operator(), "None", py::arg(""));
// cls_LDOM_Node.def("__ne__", (Standard_Boolean (LDOM_Node::*)(const LDOM_NullPtr *) const) &LDOM_Node::operator!=, py::is_operator(), "None", py::arg(""));
// cls_LDOM_Node.def("__eq__", (Standard_Boolean (LDOM_Node::*)(const LDOM_Node &) const) &LDOM_Node::operator==, py::is_operator(), "None", py::arg("anOther"));
// cls_LDOM_Node.def("__ne__", (Standard_Boolean (LDOM_Node::*)(const LDOM_Node &) const) &LDOM_Node::operator!=, py::is_operator(), "None", py::arg("anOther"));
cls_LDOM_Node.def("isNull", (Standard_Boolean (LDOM_Node::*)() const) &LDOM_Node::isNull, "None");
cls_LDOM_Node.def("getNodeType", (LDOM_Node::NodeType (LDOM_Node::*)() const) &LDOM_Node::getNodeType, "None");
cls_LDOM_Node.def("getNodeName", (LDOMString (LDOM_Node::*)() const) &LDOM_Node::getNodeName, "None");
cls_LDOM_Node.def("getNodeValue", (LDOMString (LDOM_Node::*)() const) &LDOM_Node::getNodeValue, "None");
cls_LDOM_Node.def("getFirstChild", (LDOM_Node (LDOM_Node::*)() const) &LDOM_Node::getFirstChild, "None");
cls_LDOM_Node.def("getLastChild", (LDOM_Node (LDOM_Node::*)() const) &LDOM_Node::getLastChild, "None");
cls_LDOM_Node.def("getNextSibling", (LDOM_Node (LDOM_Node::*)() const) &LDOM_Node::getNextSibling, "None");
cls_LDOM_Node.def("removeChild", (void (LDOM_Node::*)(const LDOM_Node &)) &LDOM_Node::removeChild, "None", py::arg("aChild"));
cls_LDOM_Node.def("appendChild", (void (LDOM_Node::*)(const LDOM_Node &)) &LDOM_Node::appendChild, "None", py::arg("aChild"));
cls_LDOM_Node.def("hasChildNodes", (Standard_Boolean (LDOM_Node::*)() const) &LDOM_Node::hasChildNodes, "None");
cls_LDOM_Node.def("SetValueClear", (void (LDOM_Node::*)() const) &LDOM_Node::SetValueClear, "None");

// Enums
py::enum_<LDOM_Node::NodeType>(cls_LDOM_Node, "NodeType", "None")
	.value("UNKNOWN", LDOM_Node::NodeType::UNKNOWN)
	.value("ELEMENT_NODE", LDOM_Node::NodeType::ELEMENT_NODE)
	.value("ATTRIBUTE_NODE", LDOM_Node::NodeType::ATTRIBUTE_NODE)
	.value("TEXT_NODE", LDOM_Node::NodeType::TEXT_NODE)
	.value("CDATA_SECTION_NODE", LDOM_Node::NodeType::CDATA_SECTION_NODE)
	.value("COMMENT_NODE", LDOM_Node::NodeType::COMMENT_NODE)
	.export_values();

}