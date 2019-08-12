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
#include <LDOM_MemManager.hxx>
#include <LDOMString.hxx>
#include <XmlObjMgt_DOMString.hxx>

void bind_XmlObjMgt_DOMString(py::module &mod){

py::class_<LDOMString, std::unique_ptr<LDOMString, Deleter<LDOMString>>, LDOMBasicString> cls_XmlObjMgt_DOMString(mod, "XmlObjMgt_DOMString", "None", py::module_local());

// Constructors
cls_XmlObjMgt_DOMString.def(py::init<>());
// cls_XmlObjMgt_DOMString.def(py::init<const LDOMString &>(), py::arg("anOther"));
cls_XmlObjMgt_DOMString.def(py::init<const Standard_Integer>(), py::arg("aValue"));
cls_XmlObjMgt_DOMString.def(py::init<const char *>(), py::arg("aValue"));

// Fields

// Methods
cls_XmlObjMgt_DOMString.def("getOwnerDocument", (const LDOM_MemManager & (LDOMString::*)() const) &LDOMString::getOwnerDocument, "None", py::call_guard<ImportLDOM>());
// cls_XmlObjMgt_DOMString.def("operator=", (LDOMString & (LDOMString::*)(const LDOM_NullPtr *)) &LDOMString::operator=, "None", py::arg("aNull"));
// cls_XmlObjMgt_DOMString.def("operator=", (LDOMString & (LDOMString::*)(const LDOMString &)) &LDOMString::operator=, "None", py::arg("anOther"));

// Enums

}