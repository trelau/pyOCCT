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
#include <LDOM_Attr.hxx>
#include <LDOMString.hxx>
#include <LDOM_Element.hxx>
#include <LDOM_BasicAttribute.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>

void bind_LDOM_Attr(py::module &mod){

py::class_<LDOM_Attr, std::unique_ptr<LDOM_Attr>, LDOM_Node> cls_LDOM_Attr(mod, "LDOM_Attr", "None");

// Constructors
cls_LDOM_Attr.def(py::init<>());
cls_LDOM_Attr.def(py::init<const LDOM_Attr &>(), py::arg("anOther"));

// Fields

// Methods
// cls_LDOM_Attr.def("operator=", (LDOM_Attr & (LDOM_Attr::*)(const LDOM_NullPtr *)) &LDOM_Attr::operator=, "None", py::arg("aNull"));
// cls_LDOM_Attr.def("operator=", (LDOM_Attr & (LDOM_Attr::*)(const LDOM_Attr &)) &LDOM_Attr::operator=, "None", py::arg("anOther"));
cls_LDOM_Attr.def("getName", (LDOMString (LDOM_Attr::*)() const) &LDOM_Attr::getName, "None");
cls_LDOM_Attr.def("getValue", (LDOMString (LDOM_Attr::*)() const) &LDOM_Attr::getValue, "None");
cls_LDOM_Attr.def("setValue", (void (LDOM_Attr::*)(const LDOMString &)) &LDOM_Attr::setValue, "None", py::arg("aValue"));

// Enums

}