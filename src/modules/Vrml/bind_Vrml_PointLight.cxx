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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <gp_Vec.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_PointLight.hxx>

void bind_Vrml_PointLight(py::module &mod){

py::class_<Vrml_PointLight, std::unique_ptr<Vrml_PointLight>> cls_Vrml_PointLight(mod, "Vrml_PointLight", "defines a point light node of VRML specifying properties of lights. This node defines a point light source at a fixed 3D location A point source illuminates equally in all directions; that is omni-directional. Color is written as an RGB triple. Light intensity must be in the range 0.0 to 1.0, inclusive.");

// Constructors
cls_Vrml_PointLight.def(py::init<>());
cls_Vrml_PointLight.def(py::init<const Standard_Boolean, const Standard_Real, const Quantity_Color &, const gp_Vec &>(), py::arg("aOnOff"), py::arg("aIntensity"), py::arg("aColor"), py::arg("aLocation"));

// Fields

// Methods
// cls_Vrml_PointLight.def_static("operator new_", (void * (*)(size_t)) &Vrml_PointLight::operator new, "None", py::arg("theSize"));
// cls_Vrml_PointLight.def_static("operator delete_", (void (*)(void *)) &Vrml_PointLight::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_PointLight.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_PointLight::operator new[], "None", py::arg("theSize"));
// cls_Vrml_PointLight.def_static("operator delete[]_", (void (*)(void *)) &Vrml_PointLight::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_PointLight.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_PointLight::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_PointLight.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_PointLight::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_PointLight.def("SetOnOff", (void (Vrml_PointLight::*)(const Standard_Boolean)) &Vrml_PointLight::SetOnOff, "None", py::arg("aOnOff"));
cls_Vrml_PointLight.def("OnOff", (Standard_Boolean (Vrml_PointLight::*)() const) &Vrml_PointLight::OnOff, "None");
cls_Vrml_PointLight.def("SetIntensity", (void (Vrml_PointLight::*)(const Standard_Real)) &Vrml_PointLight::SetIntensity, "None", py::arg("aIntensity"));
cls_Vrml_PointLight.def("Intensity", (Standard_Real (Vrml_PointLight::*)() const) &Vrml_PointLight::Intensity, "None");
cls_Vrml_PointLight.def("SetColor", (void (Vrml_PointLight::*)(const Quantity_Color &)) &Vrml_PointLight::SetColor, "None", py::arg("aColor"));
cls_Vrml_PointLight.def("Color", (Quantity_Color (Vrml_PointLight::*)() const) &Vrml_PointLight::Color, "None");
cls_Vrml_PointLight.def("SetLocation", (void (Vrml_PointLight::*)(const gp_Vec &)) &Vrml_PointLight::SetLocation, "None", py::arg("aLocation"));
cls_Vrml_PointLight.def("Location", (gp_Vec (Vrml_PointLight::*)() const) &Vrml_PointLight::Location, "None");
cls_Vrml_PointLight.def("Print", (Standard_OStream & (Vrml_PointLight::*)(Standard_OStream &) const) &Vrml_PointLight::Print, "None", py::arg("anOStream"));

// Enums

}