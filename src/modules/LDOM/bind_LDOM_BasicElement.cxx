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
#include <LDOM_BasicNode.hxx>
#include <LDOM_Node.hxx>
#include <LDOM_BasicElement.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>
#include <LDOM_BasicAttribute.hxx>
#include <LDOMBasicString.hxx>
#include <LDOMParser.hxx>
#include <LDOM_XmlReader.hxx>
#include <LDOM_Document.hxx>
#include <LDOM_Element.hxx>
#include <LDOM_NodeList.hxx>

void bind_LDOM_BasicElement(py::module &mod){

py::class_<LDOM_BasicElement, std::unique_ptr<LDOM_BasicElement>, LDOM_BasicNode> cls_LDOM_BasicElement(mod, "LDOM_BasicElement", "None");

// Constructors
cls_LDOM_BasicElement.def(py::init<>());

// Fields

// Methods
// cls_LDOM_BasicElement.def_static("Create_", (LDOM_BasicElement & (*)(const char *, const Standard_Integer, const opencascade::handle<LDOM_MemManager> &)) &LDOM_BasicElement::Create, "None", py::arg("aName"), py::arg("aLength"), py::arg("aDoc"));
// cls_LDOM_BasicElement.def("operator=", (LDOM_BasicElement & (LDOM_BasicElement::*)(const LDOM_NullPtr *)) &LDOM_BasicElement::operator=, "None", py::arg("aNull"));
cls_LDOM_BasicElement.def("GetTagName", (const char * (LDOM_BasicElement::*)() const) &LDOM_BasicElement::GetTagName, "None");
cls_LDOM_BasicElement.def("GetFirstChild", (const LDOM_BasicNode * (LDOM_BasicElement::*)() const) &LDOM_BasicElement::GetFirstChild, "None");
cls_LDOM_BasicElement.def("GetLastChild", (const LDOM_BasicNode * (LDOM_BasicElement::*)() const) &LDOM_BasicElement::GetLastChild, "None");
cls_LDOM_BasicElement.def("GetAttribute", (const LDOM_BasicAttribute & (LDOM_BasicElement::*)(const LDOMBasicString &, const LDOM_BasicNode *) const) &LDOM_BasicElement::GetAttribute, "None", py::arg("aName"), py::arg("aLastCh"));

// Enums

}