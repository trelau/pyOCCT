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
#include <Standard_Handle.hxx>
#include <VrmlData_Appearance.hxx>
#include <VrmlData_Geometry.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_ShapeNode.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_ShapeNode(py::module &mod){

py::class_<VrmlData_ShapeNode, opencascade::handle<VrmlData_ShapeNode>, VrmlData_Node> cls_VrmlData_ShapeNode(mod, "VrmlData_ShapeNode", "Implementation of the Shape node type");

// Constructors
cls_VrmlData_ShapeNode.def(py::init<>());
cls_VrmlData_ShapeNode.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));

// Fields

// Methods
cls_VrmlData_ShapeNode.def("Appearance", (const opencascade::handle<VrmlData_Appearance> & (VrmlData_ShapeNode::*)() const) &VrmlData_ShapeNode::Appearance, "Query the Appearance.");
cls_VrmlData_ShapeNode.def("Geometry", (const opencascade::handle<VrmlData_Geometry> & (VrmlData_ShapeNode::*)() const) &VrmlData_ShapeNode::Geometry, "Query the Geometry.");
cls_VrmlData_ShapeNode.def("SetAppearance", (void (VrmlData_ShapeNode::*)(const opencascade::handle<VrmlData_Appearance> &)) &VrmlData_ShapeNode::SetAppearance, "Set the Appearance", py::arg("theAppear"));
cls_VrmlData_ShapeNode.def("SetGeometry", (void (VrmlData_ShapeNode::*)(const opencascade::handle<VrmlData_Geometry> &)) &VrmlData_ShapeNode::SetGeometry, "Set the Geometry", py::arg("theGeometry"));
cls_VrmlData_ShapeNode.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_ShapeNode::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_ShapeNode::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_ShapeNode.def("Read", (VrmlData_ErrorStatus (VrmlData_ShapeNode::*)(VrmlData_InBuffer &)) &VrmlData_ShapeNode::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
cls_VrmlData_ShapeNode.def("Write", (VrmlData_ErrorStatus (VrmlData_ShapeNode::*)(const char *) const) &VrmlData_ShapeNode::Write, "Write the Node to output stream.", py::arg("thePrefix"));
cls_VrmlData_ShapeNode.def("IsDefault", (Standard_Boolean (VrmlData_ShapeNode::*)() const) &VrmlData_ShapeNode::IsDefault, "Check if the Shape Node is writeable.");
cls_VrmlData_ShapeNode.def_static("get_type_name_", (const char * (*)()) &VrmlData_ShapeNode::get_type_name, "None");
cls_VrmlData_ShapeNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_ShapeNode::get_type_descriptor, "None");
cls_VrmlData_ShapeNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_ShapeNode::*)() const) &VrmlData_ShapeNode::DynamicType, "None");

// Enums

}