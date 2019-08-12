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
#include <Standard_Handle.hxx>
#include <VrmlData_TextureTransform.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_TextureTransform(py::module &mod){

py::class_<VrmlData_TextureTransform, opencascade::handle<VrmlData_TextureTransform>, VrmlData_Node> cls_VrmlData_TextureTransform(mod, "VrmlData_TextureTransform", "Implementation of the TextureTransform node");

// Fields

// Methods
cls_VrmlData_TextureTransform.def("Center", (const gp_XY & (VrmlData_TextureTransform::*)() const) &VrmlData_TextureTransform::Center, "Query the Center");
cls_VrmlData_TextureTransform.def("Rotation", (Standard_Real (VrmlData_TextureTransform::*)() const) &VrmlData_TextureTransform::Rotation, "Query the Rotation");
cls_VrmlData_TextureTransform.def("Scale", (const gp_XY & (VrmlData_TextureTransform::*)() const) &VrmlData_TextureTransform::Scale, "Query the Scale");
cls_VrmlData_TextureTransform.def("Translation", (const gp_XY & (VrmlData_TextureTransform::*)() const) &VrmlData_TextureTransform::Translation, "Query the Translation");
cls_VrmlData_TextureTransform.def("SetCenter", (void (VrmlData_TextureTransform::*)(const gp_XY &)) &VrmlData_TextureTransform::SetCenter, "Set the Center", py::arg("V"));
cls_VrmlData_TextureTransform.def("SetRotation", (void (VrmlData_TextureTransform::*)(const Standard_Real)) &VrmlData_TextureTransform::SetRotation, "Set the Rotation", py::arg("V"));
cls_VrmlData_TextureTransform.def("SetScale", (void (VrmlData_TextureTransform::*)(const gp_XY &)) &VrmlData_TextureTransform::SetScale, "Set the Scale", py::arg("V"));
cls_VrmlData_TextureTransform.def("SetTranslation", (void (VrmlData_TextureTransform::*)(const gp_XY &)) &VrmlData_TextureTransform::SetTranslation, "Set the Translation", py::arg("V"));
cls_VrmlData_TextureTransform.def_static("get_type_name_", (const char * (*)()) &VrmlData_TextureTransform::get_type_name, "None");
cls_VrmlData_TextureTransform.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_TextureTransform::get_type_descriptor, "None");
cls_VrmlData_TextureTransform.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_TextureTransform::*)() const) &VrmlData_TextureTransform::DynamicType, "None");

// Enums

}