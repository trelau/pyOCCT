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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Quantity_HArray1OfColor.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Material.hxx>
#include <Standard_Type.hxx>

void bind_Vrml_Material(py::module &mod){

py::class_<Vrml_Material, opencascade::handle<Vrml_Material>, Standard_Transient> cls_Vrml_Material(mod, "Vrml_Material", "defines a Material node of VRML specifying properties of geometry and its appearance. This node defines the current surface material properties for all subsequent shapes. Material sets several components of the current material during traversal. Different shapes interpret materials with multiple values differently. To bind materials to shapes, use a MaterialBinding node.");

// Constructors
cls_Vrml_Material.def(py::init<const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &>(), py::arg("aAmbientColor"), py::arg("aDiffuseColor"), py::arg("aSpecularColor"), py::arg("aEmissiveColor"), py::arg("aShininess"), py::arg("aTransparency"));
cls_Vrml_Material.def(py::init<>());

// Fields

// Methods
cls_Vrml_Material.def("SetAmbientColor", (void (Vrml_Material::*)(const opencascade::handle<Quantity_HArray1OfColor> &)) &Vrml_Material::SetAmbientColor, "None", py::arg("aAmbientColor"));
cls_Vrml_Material.def("AmbientColor", (opencascade::handle<Quantity_HArray1OfColor> (Vrml_Material::*)() const) &Vrml_Material::AmbientColor, "None");
cls_Vrml_Material.def("SetDiffuseColor", (void (Vrml_Material::*)(const opencascade::handle<Quantity_HArray1OfColor> &)) &Vrml_Material::SetDiffuseColor, "None", py::arg("aDiffuseColor"));
cls_Vrml_Material.def("DiffuseColor", (opencascade::handle<Quantity_HArray1OfColor> (Vrml_Material::*)() const) &Vrml_Material::DiffuseColor, "None");
cls_Vrml_Material.def("SetSpecularColor", (void (Vrml_Material::*)(const opencascade::handle<Quantity_HArray1OfColor> &)) &Vrml_Material::SetSpecularColor, "None", py::arg("aSpecularColor"));
cls_Vrml_Material.def("SpecularColor", (opencascade::handle<Quantity_HArray1OfColor> (Vrml_Material::*)() const) &Vrml_Material::SpecularColor, "None");
cls_Vrml_Material.def("SetEmissiveColor", (void (Vrml_Material::*)(const opencascade::handle<Quantity_HArray1OfColor> &)) &Vrml_Material::SetEmissiveColor, "None", py::arg("aEmissiveColor"));
cls_Vrml_Material.def("EmissiveColor", (opencascade::handle<Quantity_HArray1OfColor> (Vrml_Material::*)() const) &Vrml_Material::EmissiveColor, "None");
cls_Vrml_Material.def("SetShininess", (void (Vrml_Material::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &Vrml_Material::SetShininess, "None", py::arg("aShininess"));
cls_Vrml_Material.def("Shininess", (opencascade::handle<TColStd_HArray1OfReal> (Vrml_Material::*)() const) &Vrml_Material::Shininess, "None");
cls_Vrml_Material.def("SetTransparency", (void (Vrml_Material::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &Vrml_Material::SetTransparency, "None", py::arg("aTransparency"));
cls_Vrml_Material.def("Transparency", (opencascade::handle<TColStd_HArray1OfReal> (Vrml_Material::*)() const) &Vrml_Material::Transparency, "None");
cls_Vrml_Material.def("Print", (Standard_OStream & (Vrml_Material::*)(Standard_OStream &) const) &Vrml_Material::Print, "None", py::arg("anOStream"));
cls_Vrml_Material.def_static("get_type_name_", (const char * (*)()) &Vrml_Material::get_type_name, "None");
cls_Vrml_Material.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_Material::get_type_descriptor, "None");
cls_Vrml_Material.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_Material::*)() const) &Vrml_Material::DynamicType, "None");

// Enums

}