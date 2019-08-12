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
#include <VrmlData_Cone.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Cone(py::module &mod){

py::class_<VrmlData_Cone, opencascade::handle<VrmlData_Cone>, VrmlData_Geometry> cls_VrmlData_Cone(mod, "VrmlData_Cone", "Implementation of the Cone node. The cone is located with its middle of the height segment in (0., 0., 0.) The height is oriented along OY.");

// Constructors
cls_VrmlData_Cone.def(py::init<>());
cls_VrmlData_Cone.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_Cone.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theBottomRadius"));
cls_VrmlData_Cone.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theBottomRadius"), py::arg("theHeight"));

// Fields

// Methods
cls_VrmlData_Cone.def("BottomRadius", (Standard_Real (VrmlData_Cone::*)() const) &VrmlData_Cone::BottomRadius, "Query the Bottom Radius");
cls_VrmlData_Cone.def("Height", (Standard_Real (VrmlData_Cone::*)() const) &VrmlData_Cone::Height, "Query the Height");
cls_VrmlData_Cone.def("HasBottom", (Standard_Boolean (VrmlData_Cone::*)() const) &VrmlData_Cone::HasBottom, "Query if the bottom circle is included");
cls_VrmlData_Cone.def("HasSide", (Standard_Boolean (VrmlData_Cone::*)() const) &VrmlData_Cone::HasSide, "Query if the side surface is included");
cls_VrmlData_Cone.def("SetBottomRadius", (void (VrmlData_Cone::*)(const Standard_Real)) &VrmlData_Cone::SetBottomRadius, "Set the Bottom Radius", py::arg("theRadius"));
cls_VrmlData_Cone.def("SetHeight", (void (VrmlData_Cone::*)(const Standard_Real)) &VrmlData_Cone::SetHeight, "Set the Height", py::arg("theHeight"));
cls_VrmlData_Cone.def("SetFaces", (void (VrmlData_Cone::*)(const Standard_Boolean, const Standard_Boolean)) &VrmlData_Cone::SetFaces, "Set which faces are included", py::arg("hasBottom"), py::arg("hasSide"));
cls_VrmlData_Cone.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_Cone::*)()) &VrmlData_Cone::TShape, "Query the primitive topology. This method returns a Null shape if there is an internal error during the primitive creation (zero radius, etc.)");
cls_VrmlData_Cone.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Cone::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Cone::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_Cone.def("Read", (VrmlData_ErrorStatus (VrmlData_Cone::*)(VrmlData_InBuffer &)) &VrmlData_Cone::Read, "Fill the Node internal data from the given input stream.", py::arg("theBuffer"));
cls_VrmlData_Cone.def("Write", (VrmlData_ErrorStatus (VrmlData_Cone::*)(const char *) const) &VrmlData_Cone::Write, "Write the Node to output stream.", py::arg("thePrefix"));
cls_VrmlData_Cone.def_static("get_type_name_", (const char * (*)()) &VrmlData_Cone::get_type_name, "None");
cls_VrmlData_Cone.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Cone::get_type_descriptor, "None");
cls_VrmlData_Cone.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Cone::*)() const) &VrmlData_Cone::DynamicType, "None");

// Enums

}