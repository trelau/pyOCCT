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
#include <TColStd_ListOfAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <XCAFDoc_AssemblyItemId.hxx>

void bind_XCAFDoc_AssemblyItemId(py::module &mod){

py::class_<XCAFDoc_AssemblyItemId, std::unique_ptr<XCAFDoc_AssemblyItemId, Deleter<XCAFDoc_AssemblyItemId>>> cls_XCAFDoc_AssemblyItemId(mod, "XCAFDoc_AssemblyItemId", "Unique item identifier in the hierarchical product structure. A full path to an assembly component in the 'part-of' graph starting from the root node.");

// Constructors
cls_XCAFDoc_AssemblyItemId.def(py::init<>());
cls_XCAFDoc_AssemblyItemId.def(py::init<const TColStd_ListOfAsciiString &>(), py::arg("thePath"));
cls_XCAFDoc_AssemblyItemId.def(py::init<const TCollection_AsciiString &>(), py::arg("theString"));

// Fields

// Methods
cls_XCAFDoc_AssemblyItemId.def("Init", (void (XCAFDoc_AssemblyItemId::*)(const TColStd_ListOfAsciiString &)) &XCAFDoc_AssemblyItemId::Init, "Initializes the item ID from a list of strings, where every string is a label entry.", py::arg("thePath"));
cls_XCAFDoc_AssemblyItemId.def("Init", (void (XCAFDoc_AssemblyItemId::*)(const TCollection_AsciiString &)) &XCAFDoc_AssemblyItemId::Init, "Initializes the item ID from a formatted path, where label entries are separated by '/' symbol.", py::arg("theString"));
cls_XCAFDoc_AssemblyItemId.def("IsNull", (Standard_Boolean (XCAFDoc_AssemblyItemId::*)() const) &XCAFDoc_AssemblyItemId::IsNull, "Returns true if the full path is empty, otherwise - false.");
cls_XCAFDoc_AssemblyItemId.def("Nullify", (void (XCAFDoc_AssemblyItemId::*)()) &XCAFDoc_AssemblyItemId::Nullify, "Clears the full path.");
cls_XCAFDoc_AssemblyItemId.def("IsChild", (Standard_Boolean (XCAFDoc_AssemblyItemId::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_AssemblyItemId::IsChild, "Checks if this item is a child of the given item.", py::arg("theOther"));
cls_XCAFDoc_AssemblyItemId.def("IsDirectChild", (Standard_Boolean (XCAFDoc_AssemblyItemId::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_AssemblyItemId::IsDirectChild, "Checks if this item is a direct child of the given item.", py::arg("theOther"));
cls_XCAFDoc_AssemblyItemId.def("IsEqual", (Standard_Boolean (XCAFDoc_AssemblyItemId::*)(const XCAFDoc_AssemblyItemId &) const) &XCAFDoc_AssemblyItemId::IsEqual, "Checks for item IDs equality.", py::arg("theOther"));
cls_XCAFDoc_AssemblyItemId.def("GetPath", (const TColStd_ListOfAsciiString & (XCAFDoc_AssemblyItemId::*)() const) &XCAFDoc_AssemblyItemId::GetPath, "Returns the full path as a list of label entries.");
cls_XCAFDoc_AssemblyItemId.def("ToString", (TCollection_AsciiString (XCAFDoc_AssemblyItemId::*)() const) &XCAFDoc_AssemblyItemId::ToString, "Returns the full pass as a formatted string.");

// Enums

}