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
#include <Quantity_Color.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <VrmlData_Material.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Material(py::module &mod){

py::class_<VrmlData_Material, opencascade::handle<VrmlData_Material>, VrmlData_Node> cls_VrmlData_Material(mod, "VrmlData_Material", "Implementation of the Material node");

// Constructors
cls_VrmlData_Material.def(py::init<>());
cls_VrmlData_Material.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_Material.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theAmbientIntensity"));
cls_VrmlData_Material.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theAmbientIntensity"), py::arg("theShininess"));
cls_VrmlData_Material.def(py::init<const VrmlData_Scene &, const char *, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theScene"), py::arg("theName"), py::arg("theAmbientIntensity"), py::arg("theShininess"), py::arg("theTransparency"));

// Fields

// Methods
cls_VrmlData_Material.def("AmbientIntensity", (Standard_Real (VrmlData_Material::*)() const) &VrmlData_Material::AmbientIntensity, "Query the Ambient Intensity value");
cls_VrmlData_Material.def("Shininess", (Standard_Real (VrmlData_Material::*)() const) &VrmlData_Material::Shininess, "Query the Shininess value");
cls_VrmlData_Material.def("Transparency", (Standard_Real (VrmlData_Material::*)() const) &VrmlData_Material::Transparency, "Query the Transparency value");
cls_VrmlData_Material.def("DiffuseColor", (const Quantity_Color & (VrmlData_Material::*)() const) &VrmlData_Material::DiffuseColor, "Query the Diffuse color");
cls_VrmlData_Material.def("EmissiveColor", (const Quantity_Color & (VrmlData_Material::*)() const) &VrmlData_Material::EmissiveColor, "Query the Emissive color");
cls_VrmlData_Material.def("SpecularColor", (const Quantity_Color & (VrmlData_Material::*)() const) &VrmlData_Material::SpecularColor, "Query the Specular color");
cls_VrmlData_Material.def("SetAmbientIntensity", (void (VrmlData_Material::*)(const Standard_Real)) &VrmlData_Material::SetAmbientIntensity, "Set the Ambient Intensity value", py::arg("theAmbientIntensity"));
cls_VrmlData_Material.def("SetShininess", (void (VrmlData_Material::*)(const Standard_Real)) &VrmlData_Material::SetShininess, "Set the Shininess value", py::arg("theShininess"));
cls_VrmlData_Material.def("SetTransparency", (void (VrmlData_Material::*)(const Standard_Real)) &VrmlData_Material::SetTransparency, "Set the Transparency value", py::arg("theTransparency"));
cls_VrmlData_Material.def("SetDiffuseColor", (void (VrmlData_Material::*)(const Quantity_Color &)) &VrmlData_Material::SetDiffuseColor, "Query the Diffuse color", py::arg("theColor"));
cls_VrmlData_Material.def("SetEmissiveColor", (void (VrmlData_Material::*)(const Quantity_Color &)) &VrmlData_Material::SetEmissiveColor, "Query the Emissive color", py::arg("theColor"));
cls_VrmlData_Material.def("SetSpecularColor", (void (VrmlData_Material::*)(const Quantity_Color &)) &VrmlData_Material::SetSpecularColor, "Query the Specular color", py::arg("theColor"));
cls_VrmlData_Material.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_Material::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_Material::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_Material.def("Read", (VrmlData_ErrorStatus (VrmlData_Material::*)(VrmlData_InBuffer &)) &VrmlData_Material::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_Material.def("Write", (VrmlData_ErrorStatus (VrmlData_Material::*)(const char *) const) &VrmlData_Material::Write, "Write the Node to the Scene output.", py::arg("thePrefix"));
cls_VrmlData_Material.def("IsDefault", (Standard_Boolean (VrmlData_Material::*)() const) &VrmlData_Material::IsDefault, "Returns True if the node is default, so that it should not be written.");
cls_VrmlData_Material.def_static("get_type_name_", (const char * (*)()) &VrmlData_Material::get_type_name, "None");
cls_VrmlData_Material.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Material::get_type_descriptor, "None");
cls_VrmlData_Material.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Material::*)() const) &VrmlData_Material::DynamicType, "None");

// Enums

}