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
#include <Standard_Transient.hxx>
#include <VrmlData_Scene.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Node.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <NCollection_List.hxx>
#include <VrmlData_Group.hxx>

void bind_VrmlData_Node(py::module &mod){

py::class_<VrmlData_Node, opencascade::handle<VrmlData_Node>, Standard_Transient> cls_VrmlData_Node(mod, "VrmlData_Node", "Abstract VRML Node");

// Fields

// Methods
cls_VrmlData_Node.def("Scene", (const VrmlData_Scene & (VrmlData_Node::*)() const) &VrmlData_Node::Scene, "Query the Scene that contains this Node");
cls_VrmlData_Node.def("Name", (const char * (VrmlData_Node::*)() const) &VrmlData_Node::Name, "Query the name");
cls_VrmlData_Node.def("ReadNode", [](VrmlData_Node &self, VrmlData_InBuffer & a0, opencascade::handle<VrmlData_Node> & a1) -> VrmlData_ErrorStatus { return self.ReadNode(a0, a1); });
cls_VrmlData_Node.def("ReadNode", (VrmlData_ErrorStatus (VrmlData_Node::*)(VrmlData_InBuffer &, opencascade::handle<VrmlData_Node> &, const opencascade::handle<Standard_Type> &)) &VrmlData_Node::ReadNode, "Read a complete node definition from VRML stream", py::arg("theBuffer"), py::arg("theNode"), py::arg("Type"));
cls_VrmlData_Node.def("Read", (VrmlData_ErrorStatus (VrmlData_Node::*)(VrmlData_InBuffer &)) &VrmlData_Node::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_Node.def("Write", (VrmlData_ErrorStatus (VrmlData_Node::*)(const char *) const) &VrmlData_Node::Write, "Write the Node to output stream.", py::arg("thePrefix"));
cls_VrmlData_Node.def("IsDefault", (Standard_Boolean (VrmlData_Node::*)() const) &VrmlData_Node::IsDefault, "Returns True if the node is default, then it would not be written.");
cls_VrmlData_Node.def("WriteClosing", (VrmlData_ErrorStatus (VrmlData_Node::*)() const) &VrmlData_Node::WriteClosing, "Write the closing brace in the end of a node output.");
cls_VrmlData_Node.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Node::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Node::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified. This method nullifies the argument node if its member myScene differs from that one of the current instance.", py::arg(""));
cls_VrmlData_Node.def_static("ReadBoolean_", [](VrmlData_InBuffer & theBuffer, Standard_Boolean & theResult){ VrmlData_ErrorStatus rv = VrmlData_Node::ReadBoolean(theBuffer, theResult); return std::tuple<VrmlData_ErrorStatus, Standard_Boolean &>(rv, theResult); }, "Read one boolean value (TRUE or FALSE).", py::arg("theBuffer"), py::arg("theResult"));
cls_VrmlData_Node.def_static("ReadString_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &, TCollection_AsciiString &)) &VrmlData_Node::ReadString, "Read one quoted string, the quotes are removed.", py::arg("theBuffer"), py::arg("theRes"));
cls_VrmlData_Node.def_static("ReadMultiString_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &, NCollection_List<TCollection_AsciiString> &)) &VrmlData_Node::ReadMultiString, "Read one quoted string, the quotes are removed.", py::arg("theBuffer"), py::arg("theRes"));
cls_VrmlData_Node.def_static("ReadInteger_", (VrmlData_ErrorStatus (*)(VrmlData_InBuffer &, long &)) &VrmlData_Node::ReadInteger, "Read one integer value.", py::arg("theBuffer"), py::arg("theResult"));
cls_VrmlData_Node.def_static("OK_", (Standard_Boolean (*)(const VrmlData_ErrorStatus)) &VrmlData_Node::OK, "None", py::arg("theStat"));
cls_VrmlData_Node.def_static("OK_", (Standard_Boolean (*)(VrmlData_ErrorStatus &, const VrmlData_ErrorStatus)) &VrmlData_Node::OK, "None", py::arg("outStat"), py::arg("theStat"));
cls_VrmlData_Node.def_static("GlobalIndent_", (Standard_Integer (*)()) &VrmlData_Node::GlobalIndent, "Define the common Indent in spaces, for writing all nodes.");
cls_VrmlData_Node.def_static("get_type_name_", (const char * (*)()) &VrmlData_Node::get_type_name, "None");
cls_VrmlData_Node.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Node::get_type_descriptor, "None");
cls_VrmlData_Node.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Node::*)() const) &VrmlData_Node::DynamicType, "None");

// Enums

}