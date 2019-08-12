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
#include <LDOMBasicString.hxx>
#include <LDOMString.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOM_MemManager.hxx>
#include <LDOM_Document.hxx>
#include <LDOM_Node.hxx>
#include <LDOM_Element.hxx>
#include <LDOM_BasicElement.hxx>
#include <LDOM_BasicAttribute.hxx>
#include <LDOM_BasicText.hxx>
#include <Standard_Handle.hxx>

void bind_LDOMString(py::module &mod){

py::class_<LDOMString, std::unique_ptr<LDOMString, Deleter<LDOMString>>, LDOMBasicString> cls_LDOMString(mod, "LDOMString", "None");

// Constructors
cls_LDOMString.def(py::init<>());
// cls_LDOMString.def(py::init<const LDOMString &>(), py::arg("anOther"));
cls_LDOMString.def(py::init<const Standard_Integer>(), py::arg("aValue"));
cls_LDOMString.def(py::init<const char *>(), py::arg("aValue"));

// Fields

// Methods
cls_LDOMString.def("getOwnerDocument", (const LDOM_MemManager & (LDOMString::*)() const) &LDOMString::getOwnerDocument, "None", py::call_guard<ImportLDOM>());
// cls_LDOMString.def("operator=", (LDOMString & (LDOMString::*)(const LDOM_NullPtr *)) &LDOMString::operator=, "None", py::arg("aNull"));
// cls_LDOMString.def("operator=", (LDOMString & (LDOMString::*)(const LDOMString &)) &LDOMString::operator=, "None", py::arg("anOther"));

// Enums

}