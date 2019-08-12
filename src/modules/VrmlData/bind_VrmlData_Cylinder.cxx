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
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <VrmlData_Node.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <VrmlData_Cylinder.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Cylinder(py::module &mod){

py::class_<VrmlData_Cylinder, opencascade::handle<VrmlData_Cylinder>, VrmlData_Geometry> cls_VrmlData_Cylinder(mod, "VrmlData_Cylinder", "Implementation of the Cylinder node");

// Constructors
cls_VrmlData_Cylinder.def(py::init<>());
cls_VrmlData_Cylinder.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_Cylinder.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theRadius"));
cls_VrmlData_Cylinder.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theRadius"), py::arg("theHeight"));

// Fields

// Methods
cls_VrmlData_Cylinder.def("Radius", (Standard_Real (VrmlData_Cylinder::*)() const) &VrmlData_Cylinder::Radius, "Query the Radius");
cls_VrmlData_Cylinder.def("Height", (Standard_Real (VrmlData_Cylinder::*)() const) &VrmlData_Cylinder::Height, "Query the Height");
cls_VrmlData_Cylinder.def("HasBottom", (Standard_Boolean (VrmlData_Cylinder::*)() const) &VrmlData_Cylinder::HasBottom, "Query if the bottom circle is included");
cls_VrmlData_Cylinder.def("HasSide", (Standard_Boolean (VrmlData_Cylinder::*)() const) &VrmlData_Cylinder::HasSide, "Query if the side surface is included");
cls_VrmlData_Cylinder.def("HasTop", (Standard_Boolean (VrmlData_Cylinder::*)() const) &VrmlData_Cylinder::HasTop, "Query if the top surface is included");
cls_VrmlData_Cylinder.def("SetRadius", (void (VrmlData_Cylinder::*)(const Standard_Real)) &VrmlData_Cylinder::SetRadius, "Set the Radius", py::arg("theRadius"));
cls_VrmlData_Cylinder.def("SetHeight", (void (VrmlData_Cylinder::*)(const Standard_Real)) &VrmlData_Cylinder::SetHeight, "Set the Height", py::arg("theHeight"));
cls_VrmlData_Cylinder.def("SetFaces", (void (VrmlData_Cylinder::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &VrmlData_Cylinder::SetFaces, "Set which faces are included", py::arg("hasBottom"), py::arg("hasSide"), py::arg("hasTop"));
cls_VrmlData_Cylinder.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_Cylinder::*)()) &VrmlData_Cylinder::TShape, "Query the primitive topology. This method returns a Null shape if there is an internal error during the primitive creation (zero radius, etc.)");
cls_VrmlData_Cylinder.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Cylinder::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Cylinder::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_Cylinder.def("Read", (VrmlData_ErrorStatus (VrmlData_Cylinder::*)(VrmlData_InBuffer &)) &VrmlData_Cylinder::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
cls_VrmlData_Cylinder.def("Write", (VrmlData_ErrorStatus (VrmlData_Cylinder::*)(const char *) const) &VrmlData_Cylinder::Write, "Write the Node to output stream.", py::arg("thePrefix"));
cls_VrmlData_Cylinder.def_static("get_type_name_", (const char * (*)()) &VrmlData_Cylinder::get_type_name, "None");
cls_VrmlData_Cylinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Cylinder::get_type_descriptor, "None");
cls_VrmlData_Cylinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Cylinder::*)() const) &VrmlData_Cylinder::DynamicType, "None");

// Enums

}