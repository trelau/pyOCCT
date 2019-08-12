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
#include <V3d_PositionLight.hxx>
#include <Standard_Handle.hxx>
#include <V3d_SpotLight.hxx>
#include <Standard_Type.hxx>
#include <gp_Pnt.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <Quantity_Color.hxx>
#include <gp_Dir.hxx>
#include <Graphic3d_CLight.hxx>
#include <V3d_Viewer.hxx>
#include <Standard_TypeDef.hxx>

void bind_V3d_SpotLight(py::module &mod){

py::class_<V3d_SpotLight, opencascade::handle<V3d_SpotLight>, V3d_PositionLight> cls_V3d_SpotLight(mod, "V3d_SpotLight", "Creation and modification of a spot. The attenuation factor F determines the illumination of a surface: Where Distance is the distance from the source to the surface. The default values (1.0, 0.0) correspond to a minimum of attenuation. The concentration factor determines the dispersion of the light on the surface, the default value (1.0) corresponds to a minimum of dispersion.");

// Constructors
cls_V3d_SpotLight.def(py::init<const gp_Pnt &>(), py::arg("thePos"));
cls_V3d_SpotLight.def(py::init<const gp_Pnt &, const V3d_TypeOfOrientation>(), py::arg("thePos"), py::arg("theDirection"));
cls_V3d_SpotLight.def(py::init<const gp_Pnt &, const V3d_TypeOfOrientation, const Quantity_Color &>(), py::arg("thePos"), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_SpotLight.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("thePos"), py::arg("theDirection"));
cls_V3d_SpotLight.def(py::init<const gp_Pnt &, const gp_Dir &, const Quantity_Color &>(), py::arg("thePos"), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"), py::arg("theConstAttenuation"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"), py::arg("theConcentration"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"), py::arg("theConcentration"), py::arg("theAngle"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theConstAttenuation"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"), py::arg("theConcentration"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"), py::arg("theConcentration"), py::arg("theAngle"));

// Fields

// Methods
cls_V3d_SpotLight.def_static("get_type_name_", (const char * (*)()) &V3d_SpotLight::get_type_name, "None");
cls_V3d_SpotLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_SpotLight::get_type_descriptor, "None");
cls_V3d_SpotLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_SpotLight::*)() const) &V3d_SpotLight::DynamicType, "None");
cls_V3d_SpotLight.def("SetDirection", (void (V3d_SpotLight::*)(V3d_TypeOfOrientation)) &V3d_SpotLight::SetDirection, "Defines the direction of the light source according to a predefined directional vector.", py::arg("theOrientation"));

// Enums

}