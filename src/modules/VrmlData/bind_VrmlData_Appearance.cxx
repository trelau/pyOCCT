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
#include <VrmlData_Material.hxx>
#include <VrmlData_Texture.hxx>
#include <VrmlData_TextureTransform.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_Appearance.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Appearance(py::module &mod){

py::class_<VrmlData_Appearance, opencascade::handle<VrmlData_Appearance>, VrmlData_Node> cls_VrmlData_Appearance(mod, "VrmlData_Appearance", "Implementation of the Appearance node type");

// Constructors
cls_VrmlData_Appearance.def(py::init<>());
cls_VrmlData_Appearance.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));

// Fields

// Methods
cls_VrmlData_Appearance.def("Material", (const opencascade::handle<VrmlData_Material> & (VrmlData_Appearance::*)() const) &VrmlData_Appearance::Material, "Query the Material");
cls_VrmlData_Appearance.def("Texture", (const opencascade::handle<VrmlData_Texture> & (VrmlData_Appearance::*)() const) &VrmlData_Appearance::Texture, "Query the Texture");
cls_VrmlData_Appearance.def("TextureTransform", (const opencascade::handle<VrmlData_TextureTransform> & (VrmlData_Appearance::*)() const) &VrmlData_Appearance::TextureTransform, "Query the TextureTransform");
cls_VrmlData_Appearance.def("SetMaterial", (void (VrmlData_Appearance::*)(const opencascade::handle<VrmlData_Material> &)) &VrmlData_Appearance::SetMaterial, "Set the Material", py::arg("theMat"));
cls_VrmlData_Appearance.def("SetTexture", (void (VrmlData_Appearance::*)(const opencascade::handle<VrmlData_Texture> &)) &VrmlData_Appearance::SetTexture, "Set the Texture", py::arg("theTexture"));
cls_VrmlData_Appearance.def("SetTextureTransform", (void (VrmlData_Appearance::*)(const opencascade::handle<VrmlData_TextureTransform> &)) &VrmlData_Appearance::SetTextureTransform, "Set the Texture Transform", py::arg("theTT"));
cls_VrmlData_Appearance.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Appearance::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Appearance::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg(""));
cls_VrmlData_Appearance.def("Read", (VrmlData_ErrorStatus (VrmlData_Appearance::*)(VrmlData_InBuffer &)) &VrmlData_Appearance::Read, "Read the node from input stream.", py::arg("theBuffer"));
cls_VrmlData_Appearance.def("Write", (VrmlData_ErrorStatus (VrmlData_Appearance::*)(const char *) const) &VrmlData_Appearance::Write, "Write the Node from input stream.", py::arg("thePrefix"));
cls_VrmlData_Appearance.def("IsDefault", (Standard_Boolean (VrmlData_Appearance::*)() const) &VrmlData_Appearance::IsDefault, "Returns True if the node is default, so that it should not be written.");
cls_VrmlData_Appearance.def_static("get_type_name_", (const char * (*)()) &VrmlData_Appearance::get_type_name, "None");
cls_VrmlData_Appearance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Appearance::get_type_descriptor, "None");
cls_VrmlData_Appearance.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Appearance::*)() const) &VrmlData_Appearance::DynamicType, "None");

// Enums

}