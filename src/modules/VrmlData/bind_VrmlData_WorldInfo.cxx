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
#include <NCollection_List.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_WorldInfo.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_WorldInfo(py::module &mod){

py::class_<VrmlData_WorldInfo, opencascade::handle<VrmlData_WorldInfo>, VrmlData_Node> cls_VrmlData_WorldInfo(mod, "VrmlData_WorldInfo", "Data type for WorldInfo node");

// Constructors
cls_VrmlData_WorldInfo.def(py::init<>());
cls_VrmlData_WorldInfo.def(py::init<const VrmlData_Scene &>(), py::arg("theScene"));
cls_VrmlData_WorldInfo.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_WorldInfo.def(py::init<const VrmlData_Scene &, const char *, const char *>(), py::arg("theScene"), py::arg("theName"), py::arg("theTitle"));

// Fields

// Methods
cls_VrmlData_WorldInfo.def("SetTitle", (void (VrmlData_WorldInfo::*)(const char *)) &VrmlData_WorldInfo::SetTitle, "Set or modify the title.", py::arg("theString"));
cls_VrmlData_WorldInfo.def("AddInfo", (void (VrmlData_WorldInfo::*)(const char *)) &VrmlData_WorldInfo::AddInfo, "Add a string to the list of info strings.", py::arg("theString"));
cls_VrmlData_WorldInfo.def("Title", (const char * (VrmlData_WorldInfo::*)() const) &VrmlData_WorldInfo::Title, "Query the title string.");
cls_VrmlData_WorldInfo.def("InfoIterator", (NCollection_List<const char *>::Iterator (VrmlData_WorldInfo::*)() const) &VrmlData_WorldInfo::InfoIterator, "Return the iterator of Info strings.");
cls_VrmlData_WorldInfo.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_WorldInfo::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_WorldInfo::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_WorldInfo.def("Read", (VrmlData_ErrorStatus (VrmlData_WorldInfo::*)(VrmlData_InBuffer &)) &VrmlData_WorldInfo::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_WorldInfo.def("Write", (VrmlData_ErrorStatus (VrmlData_WorldInfo::*)(const char *) const) &VrmlData_WorldInfo::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
cls_VrmlData_WorldInfo.def("IsDefault", (Standard_Boolean (VrmlData_WorldInfo::*)() const) &VrmlData_WorldInfo::IsDefault, "Returns True if the node is default, then it would not be written.");
cls_VrmlData_WorldInfo.def_static("get_type_name_", (const char * (*)()) &VrmlData_WorldInfo::get_type_name, "None");
cls_VrmlData_WorldInfo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_WorldInfo::get_type_descriptor, "None");
cls_VrmlData_WorldInfo.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_WorldInfo::*)() const) &VrmlData_WorldInfo::DynamicType, "None");

// Enums

}