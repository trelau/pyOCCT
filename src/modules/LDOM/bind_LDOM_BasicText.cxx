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
#include <LDOM_BasicText.hxx>
#include <LDOMBasicString.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>
#include <LDOMString.hxx>
#include <LDOMParser.hxx>
#include <LDOM_Document.hxx>
#include <LDOM_BasicElement.hxx>
#include <LDOM_CharacterData.hxx>

void bind_LDOM_BasicText(py::module &mod){

py::class_<LDOM_BasicText, std::unique_ptr<LDOM_BasicText>, LDOM_BasicNode> cls_LDOM_BasicText(mod, "LDOM_BasicText", "None");

// Constructors
cls_LDOM_BasicText.def(py::init<>());

// Fields

// Methods
// cls_LDOM_BasicText.def("operator=", (LDOM_BasicText & (LDOM_BasicText::*)(const LDOM_NullPtr *)) &LDOM_BasicText::operator=, "None", py::arg("aNull"));
cls_LDOM_BasicText.def("GetData", (const LDOMBasicString & (LDOM_BasicText::*)() const) &LDOM_BasicText::GetData, "None");
// cls_LDOM_BasicText.def("SetData", (void (LDOM_BasicText::*)(const LDOMBasicString &, const opencascade::handle<LDOM_MemManager> &)) &LDOM_BasicText::SetData, "None", py::arg("aValue"), py::arg("aDoc"));

// Enums

}