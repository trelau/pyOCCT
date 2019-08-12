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
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <VrmlData_TextureCoordinate.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_TextureCoordinate(py::module &mod){

py::class_<VrmlData_TextureCoordinate, opencascade::handle<VrmlData_TextureCoordinate>, VrmlData_Node> cls_VrmlData_TextureCoordinate(mod, "VrmlData_TextureCoordinate", "Implementation of the node TextureCoordinate");

// Constructors
cls_VrmlData_TextureCoordinate.def(py::init<>());
cls_VrmlData_TextureCoordinate.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_TextureCoordinate.def(py::init<const VrmlData_Scene &, const char *, const size_t>(), py::arg("theScene"), py::arg("theName"), py::arg("nPoints"));
cls_VrmlData_TextureCoordinate.def(py::init<const VrmlData_Scene &, const char *, const size_t, const gp_XY *>(), py::arg("theScene"), py::arg("theName"), py::arg("nPoints"), py::arg("arrPoints"));

// Fields

// Methods
cls_VrmlData_TextureCoordinate.def("AllocateValues", (Standard_Boolean (VrmlData_TextureCoordinate::*)(const Standard_Size)) &VrmlData_TextureCoordinate::AllocateValues, "Create a data array and assign the field myArray.", py::arg("theLength"));
cls_VrmlData_TextureCoordinate.def("Length", (size_t (VrmlData_TextureCoordinate::*)()) &VrmlData_TextureCoordinate::Length, "Query the number of points");
cls_VrmlData_TextureCoordinate.def("Points", (const gp_XY * (VrmlData_TextureCoordinate::*)()) &VrmlData_TextureCoordinate::Points, "Query the points");
cls_VrmlData_TextureCoordinate.def("SetPoints", (void (VrmlData_TextureCoordinate::*)(const size_t, const gp_XY *)) &VrmlData_TextureCoordinate::SetPoints, "Set the points array", py::arg("nPoints"), py::arg("arrPoints"));
cls_VrmlData_TextureCoordinate.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_TextureCoordinate::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_TextureCoordinate::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_TextureCoordinate.def("Read", (VrmlData_ErrorStatus (VrmlData_TextureCoordinate::*)(VrmlData_InBuffer &)) &VrmlData_TextureCoordinate::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_TextureCoordinate.def_static("get_type_name_", (const char * (*)()) &VrmlData_TextureCoordinate::get_type_name, "None");
cls_VrmlData_TextureCoordinate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_TextureCoordinate::get_type_descriptor, "None");
cls_VrmlData_TextureCoordinate.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_TextureCoordinate::*)() const) &VrmlData_TextureCoordinate::DynamicType, "None");

// Enums

}