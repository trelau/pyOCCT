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
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Node.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <VrmlData_Color.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Color(py::module &mod){

py::class_<VrmlData_Color, opencascade::handle<VrmlData_Color>, VrmlData_ArrayVec3d> cls_VrmlData_Color(mod, "VrmlData_Color", "Implementation of the node Color");

// Constructors
cls_VrmlData_Color.def(py::init<>());
cls_VrmlData_Color.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_Color.def(py::init<const VrmlData_Scene &, const char *, const size_t>(), py::arg("theScene"), py::arg("theName"), py::arg("nColors"));
cls_VrmlData_Color.def(py::init<const VrmlData_Scene &, const char *, const size_t, const gp_XYZ *>(), py::arg("theScene"), py::arg("theName"), py::arg("nColors"), py::arg("arrColors"));

// Fields

// Methods
cls_VrmlData_Color.def("Color", (const Quantity_Color (VrmlData_Color::*)(const Standard_Integer) const) &VrmlData_Color::Color, "Query one color", py::arg("i"));
cls_VrmlData_Color.def("SetColors", (void (VrmlData_Color::*)(const size_t, const gp_XYZ *)) &VrmlData_Color::SetColors, "Set the array data", py::arg("nColors"), py::arg("arrColors"));
cls_VrmlData_Color.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Color::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Color::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_Color.def("Read", (VrmlData_ErrorStatus (VrmlData_Color::*)(VrmlData_InBuffer &)) &VrmlData_Color::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_Color.def("Write", (VrmlData_ErrorStatus (VrmlData_Color::*)(const char *) const) &VrmlData_Color::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
cls_VrmlData_Color.def_static("get_type_name_", (const char * (*)()) &VrmlData_Color::get_type_name, "None");
cls_VrmlData_Color.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Color::get_type_descriptor, "None");
cls_VrmlData_Color.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Color::*)() const) &VrmlData_Color::DynamicType, "None");

// Enums

}