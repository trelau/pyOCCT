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
#include <V3d_PositionalLight.hxx>
#include <Standard_Type.hxx>
#include <gp_Pnt.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_CLight.hxx>
#include <V3d_Viewer.hxx>
#include <Standard_TypeDef.hxx>

void bind_V3d_PositionalLight(py::module &mod){

py::class_<V3d_PositionalLight, opencascade::handle<V3d_PositionalLight>, V3d_PositionLight> cls_V3d_PositionalLight(mod, "V3d_PositionalLight", "Creation and modification of an isolated (positional) light source. It is also defined by the color and two attenuation factors ConstAttentuation() and LinearAttentuation(). The resulting attenuation factor determining the illumination of a surface depends on the following formula: Where Distance is the distance of the isolated source from the surface.");

// Constructors
cls_V3d_PositionalLight.def(py::init<const gp_Pnt &>(), py::arg("thePos"));
cls_V3d_PositionalLight.def(py::init<const gp_Pnt &, const Quantity_Color &>(), py::arg("thePos"), py::arg("theColor"));
cls_V3d_PositionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_V3d_PositionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theColor"));
cls_V3d_PositionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theColor"), py::arg("theConstAttenuation"));
cls_V3d_PositionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));

// Fields

// Methods
cls_V3d_PositionalLight.def_static("get_type_name_", (const char * (*)()) &V3d_PositionalLight::get_type_name, "None");
cls_V3d_PositionalLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_PositionalLight::get_type_descriptor, "None");
cls_V3d_PositionalLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_PositionalLight::*)() const) &V3d_PositionalLight::DynamicType, "None");

// Enums

}