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
#include <TDF_LabelNode.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Data.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TDF_HAllocator.hxx>
#include <TDF_Label.hxx>
#include <TDF_LabelNodePtr.hxx>

void bind_TDF_LabelNode(py::module &mod){

py::class_<TDF_LabelNode, std::unique_ptr<TDF_LabelNode, py::nodelete>> cls_TDF_LabelNode(mod, "TDF_LabelNode", "None");

// Constructors

// Fields

// Methods
cls_TDF_LabelNode.def("Father", (TDF_LabelNode * (TDF_LabelNode::*)() const) &TDF_LabelNode::Father, "None");
cls_TDF_LabelNode.def("Brother", (TDF_LabelNode * (TDF_LabelNode::*)() const) &TDF_LabelNode::Brother, "None");
cls_TDF_LabelNode.def("FirstChild", (TDF_LabelNode * (TDF_LabelNode::*)() const) &TDF_LabelNode::FirstChild, "None");
cls_TDF_LabelNode.def("FirstAttribute", (const opencascade::handle<TDF_Attribute> & (TDF_LabelNode::*)() const) &TDF_LabelNode::FirstAttribute, "None");
cls_TDF_LabelNode.def("Tag", (Standard_Integer (TDF_LabelNode::*)() const) &TDF_LabelNode::Tag, "None");
cls_TDF_LabelNode.def("Depth", (Standard_Integer (TDF_LabelNode::*)() const) &TDF_LabelNode::Depth, "None");
cls_TDF_LabelNode.def("IsRoot", (Standard_Boolean (TDF_LabelNode::*)() const) &TDF_LabelNode::IsRoot, "None");
cls_TDF_LabelNode.def("Data", (TDF_Data * (TDF_LabelNode::*)() const) &TDF_LabelNode::Data, "None");
cls_TDF_LabelNode.def("AttributesModified", (void (TDF_LabelNode::*)(const Standard_Boolean)) &TDF_LabelNode::AttributesModified, "None", py::arg("aStatus"));
cls_TDF_LabelNode.def("AttributesModified", (Standard_Boolean (TDF_LabelNode::*)() const) &TDF_LabelNode::AttributesModified, "None");
cls_TDF_LabelNode.def("MayBeModified", (void (TDF_LabelNode::*)(const Standard_Boolean)) &TDF_LabelNode::MayBeModified, "None", py::arg("aStatus"));
cls_TDF_LabelNode.def("MayBeModified", (Standard_Boolean (TDF_LabelNode::*)() const) &TDF_LabelNode::MayBeModified, "None");

// Enums

}