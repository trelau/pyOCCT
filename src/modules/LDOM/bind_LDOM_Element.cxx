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
#include <LDOM_Element.hxx>
#include <LDOMString.hxx>
#include <LDOM_Attr.hxx>
#include <LDOM_NodeList.hxx>
#include <LDOM_Document.hxx>
#include <LDOMParser.hxx>
#include <LDOM_BasicElement.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>

void bind_LDOM_Element(py::module &mod){

py::class_<LDOM_Element, std::unique_ptr<LDOM_Element, Deleter<LDOM_Element>>, LDOM_Node> cls_LDOM_Element(mod, "LDOM_Element", "None");

// Constructors
cls_LDOM_Element.def(py::init<>());
cls_LDOM_Element.def(py::init<const LDOM_Element &>(), py::arg("anOther"));

// Fields

// Methods
// cls_LDOM_Element.def("operator=", (LDOM_Element & (LDOM_Element::*)(const LDOM_Element &)) &LDOM_Element::operator=, "None", py::arg("anOther"));
// cls_LDOM_Element.def("operator=", (LDOM_Element & (LDOM_Element::*)(const LDOM_NullPtr *)) &LDOM_Element::operator=, "None", py::arg("aNull"));
cls_LDOM_Element.def("getTagName", (LDOMString (LDOM_Element::*)() const) &LDOM_Element::getTagName, "None");
cls_LDOM_Element.def("getAttribute", (LDOMString (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::getAttribute, "None", py::arg("aName"));
cls_LDOM_Element.def("getAttributeNode", (LDOM_Attr (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::getAttributeNode, "None", py::arg("aName"));
cls_LDOM_Element.def("getElementsByTagName", (LDOM_NodeList (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::getElementsByTagName, "None", py::arg("aName"));
cls_LDOM_Element.def("setAttribute", (void (LDOM_Element::*)(const LDOMString &, const LDOMString &)) &LDOM_Element::setAttribute, "None", py::arg("aName"), py::arg("aValue"));
cls_LDOM_Element.def("setAttributeNode", (void (LDOM_Element::*)(const LDOM_Attr &)) &LDOM_Element::setAttributeNode, "None", py::arg("aNewAttr"));
cls_LDOM_Element.def("removeAttribute", (void (LDOM_Element::*)(const LDOMString &)) &LDOM_Element::removeAttribute, "None", py::arg("aName"));
cls_LDOM_Element.def("GetChildByTagName", (LDOM_Element (LDOM_Element::*)(const LDOMString &) const) &LDOM_Element::GetChildByTagName, "None", py::arg("aTagName"));
cls_LDOM_Element.def("GetSiblingByTagName", (LDOM_Element (LDOM_Element::*)() const) &LDOM_Element::GetSiblingByTagName, "None");
cls_LDOM_Element.def("ReplaceElement", (void (LDOM_Element::*)(const LDOM_Element &)) &LDOM_Element::ReplaceElement, "None", py::arg("anOther"));
cls_LDOM_Element.def("GetAttributesList", (LDOM_NodeList (LDOM_Element::*)() const) &LDOM_Element::GetAttributesList, "None");

// Enums

}