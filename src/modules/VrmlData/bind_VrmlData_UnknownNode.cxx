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
#include <VrmlData_Node.hxx>
#include <VrmlData_Scene.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_UnknownNode.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_UnknownNode(py::module &mod){

py::class_<VrmlData_UnknownNode, opencascade::handle<VrmlData_UnknownNode>, VrmlData_Node> cls_VrmlData_UnknownNode(mod, "VrmlData_UnknownNode", "Definition of UnknownNode -- placeholder for node types that are not processed now.");

// Constructors
cls_VrmlData_UnknownNode.def(py::init<>());
cls_VrmlData_UnknownNode.def(py::init<const VrmlData_Scene &>(), py::arg("theScene"));
cls_VrmlData_UnknownNode.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_UnknownNode.def(py::init<const VrmlData_Scene &, const char *, const char *>(), py::arg("theScene"), py::arg("theName"), py::arg("theTitle"));

// Fields

// Methods
cls_VrmlData_UnknownNode.def("Read", (VrmlData_ErrorStatus (VrmlData_UnknownNode::*)(VrmlData_InBuffer &)) &VrmlData_UnknownNode::Read, "Read the unknown node, till the last closing brace of it.", py::arg("theBuffer"));
cls_VrmlData_UnknownNode.def("GetTitle", (const TCollection_AsciiString & (VrmlData_UnknownNode::*)() const) &VrmlData_UnknownNode::GetTitle, "Query the title of the unknown node.");
cls_VrmlData_UnknownNode.def("IsDefault", (Standard_Boolean (VrmlData_UnknownNode::*)() const) &VrmlData_UnknownNode::IsDefault, "Check if the Node is non-writeable -- always returns true.");
cls_VrmlData_UnknownNode.def_static("get_type_name_", (const char * (*)()) &VrmlData_UnknownNode::get_type_name, "None");
cls_VrmlData_UnknownNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_UnknownNode::get_type_descriptor, "None");
cls_VrmlData_UnknownNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_UnknownNode::*)() const) &VrmlData_UnknownNode::DynamicType, "None");

// Enums

}