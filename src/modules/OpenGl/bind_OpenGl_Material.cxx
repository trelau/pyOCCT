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
#include <OpenGl_Vec.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_Material.hxx>

void bind_OpenGl_Material(py::module &mod){

py::class_<OpenGl_Material, std::unique_ptr<OpenGl_Material>> cls_OpenGl_Material(mod, "OpenGl_Material", "OpenGL material definition");

// Constructors

// Fields
cls_OpenGl_Material.def_readwrite("Ambient", &OpenGl_Material::Ambient, "ambient reflection coefficient");
cls_OpenGl_Material.def_readwrite("Diffuse", &OpenGl_Material::Diffuse, "diffuse reflection coefficient");
cls_OpenGl_Material.def_readwrite("Specular", &OpenGl_Material::Specular, "glossy reflection coefficient");
cls_OpenGl_Material.def_readwrite("Emission", &OpenGl_Material::Emission, "material emission");
cls_OpenGl_Material.def_readwrite("Params", &OpenGl_Material::Params, "extra packed parameters");

// Methods
cls_OpenGl_Material.def("Shine", (float (OpenGl_Material::*)() const) &OpenGl_Material::Shine, "None");
cls_OpenGl_Material.def("ChangeShine", (float & (OpenGl_Material::*)()) &OpenGl_Material::ChangeShine, "None");
cls_OpenGl_Material.def("Transparency", (float (OpenGl_Material::*)() const) &OpenGl_Material::Transparency, "None");
cls_OpenGl_Material.def("ChangeTransparency", (float & (OpenGl_Material::*)()) &OpenGl_Material::ChangeTransparency, "None");
cls_OpenGl_Material.def("SetColor", (void (OpenGl_Material::*)(const OpenGl_Vec4 &)) &OpenGl_Material::SetColor, "Set material color.", py::arg("theColor"));
// cls_OpenGl_Material.def("Init", (void (OpenGl_Material::*)(const Graphic3d_MaterialAspect &, const Quantity_Color &)) &OpenGl_Material::Init, "Initialize material", py::arg("theProp"), py::arg("theInteriorColor"));
cls_OpenGl_Material.def("Packed", (const OpenGl_Vec4 * (OpenGl_Material::*)() const) &OpenGl_Material::Packed, "Returns packed (serialized) representation of material properties");
cls_OpenGl_Material.def_static("NbOfVec4_", (Standard_Integer (*)()) &OpenGl_Material::NbOfVec4, "None");
cls_OpenGl_Material.def("IsEqual", (bool (OpenGl_Material::*)(const OpenGl_Material &) const) &OpenGl_Material::IsEqual, "Check this material for equality with another material (without tolerance!).", py::arg("theOther"));
cls_OpenGl_Material.def("__eq__", (bool (OpenGl_Material::*)(const OpenGl_Material &)) &OpenGl_Material::operator==, py::is_operator(), "Check this material for equality with another material (without tolerance!).", py::arg("theOther"));
cls_OpenGl_Material.def("__eq__", (bool (OpenGl_Material::*)(const OpenGl_Material &) const) &OpenGl_Material::operator==, py::is_operator(), "None", py::arg("theOther"));
cls_OpenGl_Material.def("__ne__", (bool (OpenGl_Material::*)(const OpenGl_Material &)) &OpenGl_Material::operator!=, py::is_operator(), "Check this material for non-equality with another material (without tolerance!).", py::arg("theOther"));
cls_OpenGl_Material.def("__ne__", (bool (OpenGl_Material::*)(const OpenGl_Material &) const) &OpenGl_Material::operator!=, py::is_operator(), "None", py::arg("theOther"));

// Enums

}