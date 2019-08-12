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
#include <VrmlData_ListOfNode.hxx>
#include <NCollection_List.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_Scene.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Group.hxx>
#include <Bnd_B3f.hxx>
#include <gp_Trsf.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <TopoDS_Shape.hxx>
#include <VrmlData_DataMapOfShapeAppearance.hxx>
#include <Standard_IStream.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Group(py::module &mod){

py::class_<VrmlData_Group, opencascade::handle<VrmlData_Group>, VrmlData_Node> cls_VrmlData_Group(mod, "VrmlData_Group", "Implementation of node 'Group'");

// Constructors
cls_VrmlData_Group.def(py::init<>());
cls_VrmlData_Group.def(py::init<const Standard_Boolean>(), py::arg("isTransform"));
cls_VrmlData_Group.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_Group.def(py::init<const VrmlData_Scene &, const char *, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("isTransform"));

// Fields

// Methods
cls_VrmlData_Group.def("AddNode", (opencascade::handle<VrmlData_Node> & (VrmlData_Group::*)(const opencascade::handle<VrmlData_Node> &)) &VrmlData_Group::AddNode, "Add one node to the Group.", py::arg("theNode"));
cls_VrmlData_Group.def("RemoveNode", (Standard_Boolean (VrmlData_Group::*)(const opencascade::handle<VrmlData_Node> &)) &VrmlData_Group::RemoveNode, "Remove one node from the Group.", py::arg("theNode"));
cls_VrmlData_Group.def("NodeIterator", (VrmlData_Group::Iterator (VrmlData_Group::*)() const) &VrmlData_Group::NodeIterator, "Create iterator on nodes belonging to the Group.");
cls_VrmlData_Group.def("Box", (const Bnd_B3f & (VrmlData_Group::*)() const) &VrmlData_Group::Box, "Query the bounding box.");
cls_VrmlData_Group.def("SetBox", (void (VrmlData_Group::*)(const Bnd_B3f &)) &VrmlData_Group::SetBox, "Set the bounding box.", py::arg("theBox"));
cls_VrmlData_Group.def("SetTransform", (Standard_Boolean (VrmlData_Group::*)(const gp_Trsf &)) &VrmlData_Group::SetTransform, "Set the transformation. Returns True if the group is Transform type, otherwise do nothing and return False.", py::arg("theTrsf"));
cls_VrmlData_Group.def("GetTransform", (const gp_Trsf & (VrmlData_Group::*)() const) &VrmlData_Group::GetTransform, "Query the transform value. For group without transformation this always returns Identity");
cls_VrmlData_Group.def("IsTransform", (Standard_Boolean (VrmlData_Group::*)() const) &VrmlData_Group::IsTransform, "Query if the node is Transform type.");
cls_VrmlData_Group.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Group::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Group::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_Group.def("Read", (VrmlData_ErrorStatus (VrmlData_Group::*)(VrmlData_InBuffer &)) &VrmlData_Group::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
cls_VrmlData_Group.def("Write", (VrmlData_ErrorStatus (VrmlData_Group::*)(const char *) const) &VrmlData_Group::Write, "Write the Node to output stream.", py::arg("thePrefix"));
cls_VrmlData_Group.def("FindNode", (opencascade::handle<VrmlData_Node> (VrmlData_Group::*)(const char *, gp_Trsf &) const) &VrmlData_Group::FindNode, "Find a node by its name, inside this Group", py::arg("theName"), py::arg("theLocation"));
cls_VrmlData_Group.def("Shape", (void (VrmlData_Group::*)(TopoDS_Shape &, VrmlData_DataMapOfShapeAppearance *)) &VrmlData_Group::Shape, "Get the shape representing the group geometry.", py::arg("theShape"), py::arg("pMapApp"));
cls_VrmlData_Group.def_static("get_type_name_", (const char * (*)()) &VrmlData_Group::get_type_name, "None");
cls_VrmlData_Group.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Group::get_type_descriptor, "None");
cls_VrmlData_Group.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Group::*)() const) &VrmlData_Group::DynamicType, "None");

// Enums

}