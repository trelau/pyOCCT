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
#include <LDOM_Node.hxx>
#include <LDOMBasicString.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Standard_Handle.hxx>

void bind_LDOMBasicString(py::module &mod){

py::class_<LDOMBasicString, std::unique_ptr<LDOMBasicString>> cls_LDOMBasicString(mod, "LDOMBasicString", "None");

// Constructors
cls_LDOMBasicString.def(py::init<>());
cls_LDOMBasicString.def(py::init<const LDOMBasicString &>(), py::arg("anOther"));
cls_LDOMBasicString.def(py::init<const Standard_Integer>(), py::arg("aValue"));
cls_LDOMBasicString.def(py::init<const char *>(), py::arg("aValue"));
cls_LDOMBasicString.def(py::init<const char *, const opencascade::handle<LDOM_MemManager> &>(), py::arg("aValue"), py::arg("aDoc"));
cls_LDOMBasicString.def(py::init<const char *, const Standard_Integer, const opencascade::handle<LDOM_MemManager> &>(), py::arg("aValue"), py::arg("aLen"), py::arg("aDoc"));

// Fields

// Methods
cls_LDOMBasicString.def("Type", (LDOMBasicString::StringType (LDOMBasicString::*)() const) &LDOMBasicString::Type, "None");
cls_LDOMBasicString.def("GetInteger", [](LDOMBasicString &self, Standard_Integer & aResult){ Standard_Boolean rv = self.GetInteger(aResult); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, aResult); }, "None", py::arg("aResult"));
cls_LDOMBasicString.def("GetString", (const char * (LDOMBasicString::*)() const) &LDOMBasicString::GetString, "None");
cls_LDOMBasicString.def("equals", (Standard_Boolean (LDOMBasicString::*)(const LDOMBasicString &) const) &LDOMBasicString::equals, "None", py::arg("anOther"));
// cls_LDOMBasicString.def("operator=", (LDOMBasicString & (LDOMBasicString::*)(const LDOM_NullPtr *)) &LDOMBasicString::operator=, "None", py::arg(""));
// cls_LDOMBasicString.def("operator=", (LDOMBasicString & (LDOMBasicString::*)(const LDOMBasicString &)) &LDOMBasicString::operator=, "None", py::arg("anOther"));
// cls_LDOMBasicString.def("__eq__", (Standard_Boolean (LDOMBasicString::*)(const LDOM_NullPtr *) const) &LDOMBasicString::operator==, py::is_operator(), "None", py::arg(""));
// cls_LDOMBasicString.def("__ne__", (Standard_Boolean (LDOMBasicString::*)(const LDOM_NullPtr *) const) &LDOMBasicString::operator!=, py::is_operator(), "None", py::arg(""));
// cls_LDOMBasicString.def("__eq__", (Standard_Boolean (LDOMBasicString::*)(const LDOMBasicString &) const) &LDOMBasicString::operator==, py::is_operator(), "None", py::arg("anOther"));
// cls_LDOMBasicString.def("__ne__", (Standard_Boolean (LDOMBasicString::*)(const LDOMBasicString &) const) &LDOMBasicString::operator!=, py::is_operator(), "None", py::arg("anOther"));

// Enums
py::enum_<LDOMBasicString::StringType>(cls_LDOMBasicString, "StringType", "None")
	.value("LDOM_NULL", LDOMBasicString::StringType::LDOM_NULL)
	.value("LDOM_Integer", LDOMBasicString::StringType::LDOM_Integer)
	.value("LDOM_AsciiFree", LDOMBasicString::StringType::LDOM_AsciiFree)
	.value("LDOM_AsciiDoc", LDOMBasicString::StringType::LDOM_AsciiDoc)
	.value("LDOM_AsciiDocClear", LDOMBasicString::StringType::LDOM_AsciiDocClear)
	.value("LDOM_AsciiHashed", LDOMBasicString::StringType::LDOM_AsciiHashed)
	.export_values();

}