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
#include <VrmlData_Coordinate.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Coordinate(py::module &mod){

py::class_<VrmlData_Coordinate, opencascade::handle<VrmlData_Coordinate>, VrmlData_ArrayVec3d> cls_VrmlData_Coordinate(mod, "VrmlData_Coordinate", "Implementation of the node Coordinate");

// Constructors
cls_VrmlData_Coordinate.def(py::init<>());
cls_VrmlData_Coordinate.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_Coordinate.def(py::init<const VrmlData_Scene &, const char *, const size_t>(), py::arg("theScene"), py::arg("theName"), py::arg("nPoints"));
cls_VrmlData_Coordinate.def(py::init<const VrmlData_Scene &, const char *, const size_t, const gp_XYZ *>(), py::arg("theScene"), py::arg("theName"), py::arg("nPoints"), py::arg("arrPoints"));

// Fields

// Methods
cls_VrmlData_Coordinate.def("Coordinate", (const gp_XYZ & (VrmlData_Coordinate::*)(const Standard_Integer) const) &VrmlData_Coordinate::Coordinate, "Query one point", py::arg("i"));
cls_VrmlData_Coordinate.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Coordinate::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Coordinate::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_Coordinate.def("Read", (VrmlData_ErrorStatus (VrmlData_Coordinate::*)(VrmlData_InBuffer &)) &VrmlData_Coordinate::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_Coordinate.def("Write", (VrmlData_ErrorStatus (VrmlData_Coordinate::*)(const char *) const) &VrmlData_Coordinate::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
cls_VrmlData_Coordinate.def_static("get_type_name_", (const char * (*)()) &VrmlData_Coordinate::get_type_name, "None");
cls_VrmlData_Coordinate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Coordinate::get_type_descriptor, "None");
cls_VrmlData_Coordinate.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Coordinate::*)() const) &VrmlData_Coordinate::DynamicType, "None");

// Enums

}