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
#include <VrmlData_ArrayVec3d.hxx>
#include <VrmlData_Scene.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Node.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <VrmlData_Normal.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Normal(py::module &mod){

py::class_<VrmlData_Normal, opencascade::handle<VrmlData_Normal>, VrmlData_ArrayVec3d> cls_VrmlData_Normal(mod, "VrmlData_Normal", "Implementation of the node Normal");

// Constructors
cls_VrmlData_Normal.def(py::init<>());
cls_VrmlData_Normal.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_Normal.def(py::init<const VrmlData_Scene &, const char *, const size_t>(), py::arg("theScene"), py::arg("theName"), py::arg("nVec"));
cls_VrmlData_Normal.def(py::init<const VrmlData_Scene &, const char *, const size_t, const gp_XYZ *>(), py::arg("theScene"), py::arg("theName"), py::arg("nVec"), py::arg("arrVec"));

// Fields

// Methods
cls_VrmlData_Normal.def("Normal", (const gp_XYZ & (VrmlData_Normal::*)(const Standard_Integer) const) &VrmlData_Normal::Normal, "Query one normal", py::arg("i"));
cls_VrmlData_Normal.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Normal::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Normal::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_Normal.def("Read", (VrmlData_ErrorStatus (VrmlData_Normal::*)(VrmlData_InBuffer &)) &VrmlData_Normal::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_Normal.def("Write", (VrmlData_ErrorStatus (VrmlData_Normal::*)(const char *) const) &VrmlData_Normal::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
cls_VrmlData_Normal.def_static("get_type_name_", (const char * (*)()) &VrmlData_Normal::get_type_name, "None");
cls_VrmlData_Normal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Normal::get_type_descriptor, "None");
cls_VrmlData_Normal.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Normal::*)() const) &VrmlData_Normal::DynamicType, "None");

// Enums

}