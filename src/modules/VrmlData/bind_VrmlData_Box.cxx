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
#include <VrmlData_Geometry.hxx>
#include <VrmlData_Scene.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <VrmlData_Node.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <VrmlData_Box.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Box(py::module &mod){

py::class_<VrmlData_Box, opencascade::handle<VrmlData_Box>, VrmlData_Geometry> cls_VrmlData_Box(mod, "VrmlData_Box", "Inplementation of the Box node. This node is defined by Size vector, assumong that the box center is located in (0., 0., 0.) and that each corner is 0.5*|Size| distance from the center.");

// Constructors
cls_VrmlData_Box.def(py::init<>());
cls_VrmlData_Box.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_Box.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("sizeX"));
cls_VrmlData_Box.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("sizeX"), py::arg("sizeY"));
cls_VrmlData_Box.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("sizeX"), py::arg("sizeY"), py::arg("sizeZ"));

// Fields

// Methods
cls_VrmlData_Box.def("Size", (const gp_XYZ & (VrmlData_Box::*)() const) &VrmlData_Box::Size, "Query the Box size");
cls_VrmlData_Box.def("SetSize", (void (VrmlData_Box::*)(const gp_XYZ &)) &VrmlData_Box::SetSize, "Set the Box Size", py::arg("theSize"));
cls_VrmlData_Box.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_Box::*)()) &VrmlData_Box::TShape, "Query the primitive topology. This method returns a Null shape if there is an internal error during the primitive creation (zero radius, etc.)");
cls_VrmlData_Box.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Box::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Box::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_Box.def("Read", (VrmlData_ErrorStatus (VrmlData_Box::*)(VrmlData_InBuffer &)) &VrmlData_Box::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
cls_VrmlData_Box.def("Write", (VrmlData_ErrorStatus (VrmlData_Box::*)(const char *) const) &VrmlData_Box::Write, "Write the Node to output stream.", py::arg("thePrefix"));
cls_VrmlData_Box.def_static("get_type_name_", (const char * (*)()) &VrmlData_Box::get_type_name, "None");
cls_VrmlData_Box.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Box::get_type_descriptor, "None");
cls_VrmlData_Box.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Box::*)() const) &VrmlData_Box::DynamicType, "None");

// Enums

}