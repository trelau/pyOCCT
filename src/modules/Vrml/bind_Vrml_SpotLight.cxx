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
#include <Vrml_SpotLight.hxx>

void bind_Vrml_SpotLight(py::module &mod){

py::class_<Vrml_SpotLight, std::unique_ptr<Vrml_SpotLight>> cls_Vrml_SpotLight(mod, "Vrml_SpotLight", "specifies a spot light node of VRML nodes specifying properties of lights. This node defines a spotlight light source. A spotlight is placed at a fixed location in 3D-space and illuminates in a cone along a particular direction. The intensity of the illumination drops off exponentially as a ray of light diverges from this direction toward the edges of cone. The rate of drop-off and agle of the cone are controlled by the dropOfRate and cutOffAngle Color is written as an RGB triple. Light intensity must be in the range 0.0 to 1.0, inclusive.");

// Constructors
cls_Vrml_SpotLight.def(py::init<>());
cls_Vrml_SpotLight.def(py::init<const Standard_Boolean, const Standard_Real, const Quantity_Color &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real>(), py::arg("aOnOff"), py::arg("aIntensity"), py::arg("aColor"), py::arg("aLocation"), py::arg("aDirection"), py::arg("aDropOffRate"), py::arg("aCutOffAngle"));

// Fields

// Methods
// cls_Vrml_SpotLight.def_static("operator new_", (void * (*)(size_t)) &Vrml_SpotLight::operator new, "None", py::arg("theSize"));
// cls_Vrml_SpotLight.def_static("operator delete_", (void (*)(void *)) &Vrml_SpotLight::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_SpotLight.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_SpotLight::operator new[], "None", py::arg("theSize"));
// cls_Vrml_SpotLight.def_static("operator delete[]_", (void (*)(void *)) &Vrml_SpotLight::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_SpotLight.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_SpotLight::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_SpotLight.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_SpotLight::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_SpotLight.def("SetOnOff", (void (Vrml_SpotLight::*)(const Standard_Boolean)) &Vrml_SpotLight::SetOnOff, "None", py::arg("anOnOff"));
cls_Vrml_SpotLight.def("OnOff", (Standard_Boolean (Vrml_SpotLight::*)() const) &Vrml_SpotLight::OnOff, "None");
cls_Vrml_SpotLight.def("SetIntensity", (void (Vrml_SpotLight::*)(const Standard_Real)) &Vrml_SpotLight::SetIntensity, "None", py::arg("aIntensity"));
cls_Vrml_SpotLight.def("Intensity", (Standard_Real (Vrml_SpotLight::*)() const) &Vrml_SpotLight::Intensity, "None");
cls_Vrml_SpotLight.def("SetColor", (void (Vrml_SpotLight::*)(const Quantity_Color &)) &Vrml_SpotLight::SetColor, "None", py::arg("aColor"));
cls_Vrml_SpotLight.def("Color", (Quantity_Color (Vrml_SpotLight::*)() const) &Vrml_SpotLight::Color, "None");
cls_Vrml_SpotLight.def("SetLocation", (void (Vrml_SpotLight::*)(const gp_Vec &)) &Vrml_SpotLight::SetLocation, "None", py::arg("aLocation"));
cls_Vrml_SpotLight.def("Location", (gp_Vec (Vrml_SpotLight::*)() const) &Vrml_SpotLight::Location, "None");
cls_Vrml_SpotLight.def("SetDirection", (void (Vrml_SpotLight::*)(const gp_Vec &)) &Vrml_SpotLight::SetDirection, "None", py::arg("aDirection"));
cls_Vrml_SpotLight.def("Direction", (gp_Vec (Vrml_SpotLight::*)() const) &Vrml_SpotLight::Direction, "None");
cls_Vrml_SpotLight.def("SetDropOffRate", (void (Vrml_SpotLight::*)(const Standard_Real)) &Vrml_SpotLight::SetDropOffRate, "None", py::arg("aDropOffRate"));
cls_Vrml_SpotLight.def("DropOffRate", (Standard_Real (Vrml_SpotLight::*)() const) &Vrml_SpotLight::DropOffRate, "None");
cls_Vrml_SpotLight.def("SetCutOffAngle", (void (Vrml_SpotLight::*)(const Standard_Real)) &Vrml_SpotLight::SetCutOffAngle, "None", py::arg("aCutOffAngle"));
cls_Vrml_SpotLight.def("CutOffAngle", (Standard_Real (Vrml_SpotLight::*)() const) &Vrml_SpotLight::CutOffAngle, "None");
cls_Vrml_SpotLight.def("Print", (Standard_OStream & (Vrml_SpotLight::*)(Standard_OStream &) const) &Vrml_SpotLight::Print, "None", py::arg("anOStream"));

// Enums

}