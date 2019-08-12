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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Texture.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Texture(py::module &mod){

py::class_<VrmlData_Texture, opencascade::handle<VrmlData_Texture>, VrmlData_Node> cls_VrmlData_Texture(mod, "VrmlData_Texture", "Implementation of the Texture node");

// Fields

// Methods
cls_VrmlData_Texture.def("RepeatS", (Standard_Boolean (VrmlData_Texture::*)() const) &VrmlData_Texture::RepeatS, "Query the RepeatS value");
cls_VrmlData_Texture.def("RepeatT", (Standard_Boolean (VrmlData_Texture::*)() const) &VrmlData_Texture::RepeatT, "Query the RepeatT value");
cls_VrmlData_Texture.def("SetRepeatS", (void (VrmlData_Texture::*)(const Standard_Boolean)) &VrmlData_Texture::SetRepeatS, "Set the RepeatS flag", py::arg("theFlag"));
cls_VrmlData_Texture.def("SetRepeatT", (void (VrmlData_Texture::*)(const Standard_Boolean)) &VrmlData_Texture::SetRepeatT, "Set the RepeatT flag", py::arg("theFlag"));
cls_VrmlData_Texture.def_static("get_type_name_", (const char * (*)()) &VrmlData_Texture::get_type_name, "None");
cls_VrmlData_Texture.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Texture::get_type_descriptor, "None");
cls_VrmlData_Texture.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Texture::*)() const) &VrmlData_Texture::DynamicType, "None");

// Enums

}