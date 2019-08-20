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
#include <LDOM_NodeList.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOM_Node.hxx>
#include <LDOM_Document.hxx>
#include <LDOM_Element.hxx>
#include <LDOM_BasicElement.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>
#include <LDOM_BasicNode.hxx>

void bind_LDOM_NodeList(py::module &mod){

py::class_<LDOM_NodeList, std::unique_ptr<LDOM_NodeList>> cls_LDOM_NodeList(mod, "LDOM_NodeList", "None");

// Constructors
cls_LDOM_NodeList.def(py::init<>());
cls_LDOM_NodeList.def(py::init<const LDOM_NodeList &>(), py::arg("theOther"));

// Fields

// Methods
// cls_LDOM_NodeList.def("operator=", (LDOM_NodeList & (LDOM_NodeList::*)(const LDOM_NodeList &)) &LDOM_NodeList::operator=, "None", py::arg("theOther"));
// cls_LDOM_NodeList.def("operator=", (LDOM_NodeList & (LDOM_NodeList::*)(const LDOM_NullPtr *)) &LDOM_NodeList::operator=, "None", py::arg(""));
// cls_LDOM_NodeList.def("__eq__", (Standard_Boolean (LDOM_NodeList::*)(const LDOM_NullPtr *) const) &LDOM_NodeList::operator==, py::is_operator(), "None", py::arg(""));
// cls_LDOM_NodeList.def("__ne__", (Standard_Boolean (LDOM_NodeList::*)(const LDOM_NullPtr *) const) &LDOM_NodeList::operator!=, py::is_operator(), "None", py::arg(""));
cls_LDOM_NodeList.def("item", (LDOM_Node (LDOM_NodeList::*)(const Standard_Integer) const) &LDOM_NodeList::item, "None", py::arg(""));
cls_LDOM_NodeList.def("getLength", (Standard_Integer (LDOM_NodeList::*)() const) &LDOM_NodeList::getLength, "None");

// Enums

}