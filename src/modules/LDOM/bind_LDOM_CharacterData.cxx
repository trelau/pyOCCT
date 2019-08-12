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
#include <LDOM_CharacterData.hxx>
#include <LDOMString.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOM_BasicText.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>

void bind_LDOM_CharacterData(py::module &mod){

py::class_<LDOM_CharacterData, std::unique_ptr<LDOM_CharacterData, Deleter<LDOM_CharacterData>>, LDOM_Node> cls_LDOM_CharacterData(mod, "LDOM_CharacterData", "None");

// Constructors
cls_LDOM_CharacterData.def(py::init<>());
cls_LDOM_CharacterData.def(py::init<const LDOM_CharacterData &>(), py::arg("theOther"));

// Fields

// Methods
// cls_LDOM_CharacterData.def("operator=", (LDOM_CharacterData & (LDOM_CharacterData::*)(const LDOM_NullPtr *)) &LDOM_CharacterData::operator=, "None", py::arg("aNull"));
// cls_LDOM_CharacterData.def("operator=", (LDOM_CharacterData & (LDOM_CharacterData::*)(const LDOM_CharacterData &)) &LDOM_CharacterData::operator=, "None", py::arg("anOther"));
cls_LDOM_CharacterData.def("getData", (LDOMString (LDOM_CharacterData::*)() const) &LDOM_CharacterData::getData, "None");
cls_LDOM_CharacterData.def("setData", (void (LDOM_CharacterData::*)(const LDOMString &)) &LDOM_CharacterData::setData, "None", py::arg("aValue"));
cls_LDOM_CharacterData.def("getLength", (Standard_Integer (LDOM_CharacterData::*)() const) &LDOM_CharacterData::getLength, "None");

// Enums

}