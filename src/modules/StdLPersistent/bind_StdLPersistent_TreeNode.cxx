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
#include <StdObjMgt_Attribute.hxx>
#include <TDataStd_TreeNode.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_Transient.hxx>
#include <StdLPersistent_TreeNode.hxx>
#include <Standard_GUID.hxx>

void bind_StdLPersistent_TreeNode(py::module &mod){

py::class_<StdLPersistent_TreeNode, opencascade::handle<StdLPersistent_TreeNode>> cls_StdLPersistent_TreeNode(mod, "StdLPersistent_TreeNode", "None");

// Constructors

// Fields

// Methods
cls_StdLPersistent_TreeNode.def("Read", (void (StdLPersistent_TreeNode::*)(StdObjMgt_ReadData &)) &StdLPersistent_TreeNode::Read, "Read persistent data from a file.", py::arg("theReadData"));
cls_StdLPersistent_TreeNode.def("Write", (void (StdLPersistent_TreeNode::*)(StdObjMgt_WriteData &) const) &StdLPersistent_TreeNode::Write, "Write persistent data to a file.", py::arg("theWriteData"));
cls_StdLPersistent_TreeNode.def("PChildren", (void (StdLPersistent_TreeNode::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const) &StdLPersistent_TreeNode::PChildren, "Gets persistent child objects", py::arg(""));
cls_StdLPersistent_TreeNode.def("PName", (Standard_CString (StdLPersistent_TreeNode::*)() const) &StdLPersistent_TreeNode::PName, "Returns persistent type name");
cls_StdLPersistent_TreeNode.def("CreateAttribute", (opencascade::handle<TDF_Attribute> (StdLPersistent_TreeNode::*)()) &StdLPersistent_TreeNode::CreateAttribute, "Create an empty transient attribuite");
cls_StdLPersistent_TreeNode.def("ImportAttribute", (void (StdLPersistent_TreeNode::*)()) &StdLPersistent_TreeNode::ImportAttribute, "Import transient attribuite from the persistent data.");

// Enums

}