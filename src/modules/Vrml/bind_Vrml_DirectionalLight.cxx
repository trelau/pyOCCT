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
#include <Vrml_DirectionalLight.hxx>

void bind_Vrml_DirectionalLight(py::module &mod){

py::class_<Vrml_DirectionalLight, std::unique_ptr<Vrml_DirectionalLight>> cls_Vrml_DirectionalLight(mod, "Vrml_DirectionalLight", "defines a directional light node of VRML specifying properties of lights. This node defines a directional light source that illuminates along rays parallel to a given 3-dimentional vector Color is written as an RGB triple. Light intensity must be in the range 0.0 to 1.0, inclusive.");

// Constructors
cls_Vrml_DirectionalLight.def(py::init<>());
cls_Vrml_DirectionalLight.def(py::init<const Standard_Boolean, const Standard_Real, const Quantity_Color &, const gp_Vec &>(), py::arg("aOnOff"), py::arg("aIntensity"), py::arg("aColor"), py::arg("aDirection"));

// Fields

// Methods
// cls_Vrml_DirectionalLight.def_static("operator new_", (void * (*)(size_t)) &Vrml_DirectionalLight::operator new, "None", py::arg("theSize"));
// cls_Vrml_DirectionalLight.def_static("operator delete_", (void (*)(void *)) &Vrml_DirectionalLight::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_DirectionalLight.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_DirectionalLight::operator new[], "None", py::arg("theSize"));
// cls_Vrml_DirectionalLight.def_static("operator delete[]_", (void (*)(void *)) &Vrml_DirectionalLight::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_DirectionalLight.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_DirectionalLight::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_DirectionalLight.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_DirectionalLight::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_DirectionalLight.def("SetOnOff", (void (Vrml_DirectionalLight::*)(const Standard_Boolean)) &Vrml_DirectionalLight::SetOnOff, "None", py::arg("aOnOff"));
cls_Vrml_DirectionalLight.def("OnOff", (Standard_Boolean (Vrml_DirectionalLight::*)() const) &Vrml_DirectionalLight::OnOff, "None");
cls_Vrml_DirectionalLight.def("SetIntensity", (void (Vrml_DirectionalLight::*)(const Standard_Real)) &Vrml_DirectionalLight::SetIntensity, "None", py::arg("aIntensity"));
cls_Vrml_DirectionalLight.def("Intensity", (Standard_Real (Vrml_DirectionalLight::*)() const) &Vrml_DirectionalLight::Intensity, "None");
cls_Vrml_DirectionalLight.def("SetColor", (void (Vrml_DirectionalLight::*)(const Quantity_Color &)) &Vrml_DirectionalLight::SetColor, "None", py::arg("aColor"));
cls_Vrml_DirectionalLight.def("Color", (Quantity_Color (Vrml_DirectionalLight::*)() const) &Vrml_DirectionalLight::Color, "None");
cls_Vrml_DirectionalLight.def("SetDirection", (void (Vrml_DirectionalLight::*)(const gp_Vec &)) &Vrml_DirectionalLight::SetDirection, "None", py::arg("aDirection"));
cls_Vrml_DirectionalLight.def("Direction", (gp_Vec (Vrml_DirectionalLight::*)() const) &Vrml_DirectionalLight::Direction, "None");
cls_Vrml_DirectionalLight.def("Print", (Standard_OStream & (Vrml_DirectionalLight::*)(Standard_OStream &) const) &Vrml_DirectionalLight::Print, "None", py::arg("anOStream"));

// Enums

}