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
#include <LDOM_Element.hxx>
#include <XmlObjMgt_Element.hxx>

void bind_XmlObjMgt_Element(py::module &mod){

py::class_<LDOM_Element, std::unique_ptr<LDOM_Element, Deleter<LDOM_Element>>, LDOM_Node> cls_XmlObjMgt_Element(mod, "XmlObjMgt_Element", "None", py::module_local());

// Constructors
cls_XmlObjMgt_Element.def(py::init<>());
cls_XmlObjMgt_Element.def(py::init<const LDOM_Element &>(), py::arg("anOther"));

// Fields

// Methods
// cls_XmlObjMgt_Element.def("operator=", (LDOM_Element & (LDOM_Element::*)(const LDOM_Element &)) &LDOM_Element::operator=, "None", py::arg("anOther"));
// cls_XmlObjMgt_Element.def("operator=", (LDOM_Element & (LDOM_Element::*)(const LDOM_NullPtr *)) &LDOM_Element::operator=, "None", py::arg("aNull"));
cls_XmlObjMgt_Element.def("getTagName", (LDOMString (LDOM_Element::*)() const) &LDOM_Element::getTagName, "None");
cls_XmlObjMgt_Element.def("getAttribute", (LDOMString (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::getAttribute, "None", py::arg("aName"));
cls_XmlObjMgt_Element.def("getAttributeNode", (LDOM_Attr (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::getAttributeNode, "None", py::arg("aName"));
cls_XmlObjMgt_Element.def("getElementsByTagName", (LDOM_NodeList (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::getElementsByTagName, "None", py::arg("aName"));
cls_XmlObjMgt_Element.def("setAttribute", (void (LDOM_Element::*)(const LDOMString &, const LDOMString &)) &LDOM_Element::setAttribute, "None", py::arg("aName"), py::arg("aValue"));
cls_XmlObjMgt_Element.def("setAttributeNode", (void (LDOM_Element::*)(const LDOM_Attr &)) &LDOM_Element::setAttributeNode, "None", py::arg("aNewAttr"));
cls_XmlObjMgt_Element.def("removeAttribute", (void (LDOM_Element::*)(const LDOMString &)) &LDOM_Element::removeAttribute, "None", py::arg("aName"));
cls_XmlObjMgt_Element.def("GetChildByTagName", (LDOM_Element (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::GetChildByTagName, "None", py::arg("aTagName"));
cls_XmlObjMgt_Element.def("GetSiblingByTagName", (LDOM_Element (LDOM_Element::*)() const) &LDOM_Element::GetSiblingByTagName, "None");
cls_XmlObjMgt_Element.def("ReplaceElement", (void (LDOM_Element::*)(const LDOM_Element &)) &LDOM_Element::ReplaceElement, "None", py::arg("anOther"));
cls_XmlObjMgt_Element.def("GetAttributesList", (LDOM_NodeList (LDOM_Element::*)() const) &LDOM_Element::GetAttributesList, "None");

// Enums

}