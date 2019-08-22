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
#include <LDOM_BasicAttribute.hxx>
#include <LDOMBasicString.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>
#include <LDOMString.hxx>
#include <LDOM_Attr.hxx>
#include <LDOM_Element.hxx>
#include <LDOM_BasicElement.hxx>
#include <LDOM_XmlReader.hxx>
#include <Standard_TypeDef.hxx>

void bind_LDOM_BasicAttribute(py::module &mod){

py::class_<LDOM_BasicAttribute, LDOM_BasicNode> cls_LDOM_BasicAttribute(mod, "LDOM_BasicAttribute", "None");

// Constructors
cls_LDOM_BasicAttribute.def(py::init<>());

// Fields

// Methods
// cls_LDOM_BasicAttribute.def("operator=", (LDOM_BasicAttribute & (LDOM_BasicAttribute::*)(const LDOM_NullPtr *)) &LDOM_BasicAttribute::operator=, "None", py::arg("aNull"));
cls_LDOM_BasicAttribute.def("GetName", (const char * (LDOM_BasicAttribute::*)() const) &LDOM_BasicAttribute::GetName, "None");
cls_LDOM_BasicAttribute.def("GetValue", (const LDOMBasicString & (LDOM_BasicAttribute::*)() const) &LDOM_BasicAttribute::GetValue, "None");
// cls_LDOM_BasicAttribute.def("SetValue", (void (LDOM_BasicAttribute::*)(const LDOMBasicString &, const opencascade::handle<LDOM_MemManager> &)) &LDOM_BasicAttribute::SetValue, "None", py::arg("aValue"), py::arg("aDoc"));

// Enums

}