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
#include <V3d_DirectionalLight.hxx>
#include <Standard_Type.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir.hxx>
#include <Graphic3d_CLight.hxx>
#include <V3d_Viewer.hxx>

void bind_V3d_DirectionalLight(py::module &mod){

py::class_<V3d_DirectionalLight, opencascade::handle<V3d_DirectionalLight>, V3d_PositionLight> cls_V3d_DirectionalLight(mod, "V3d_DirectionalLight", "Directional light source for a viewer.");

// Constructors
cls_V3d_DirectionalLight.def(py::init<>());
cls_V3d_DirectionalLight.def(py::init<const V3d_TypeOfOrientation>(), py::arg("theDirection"));
cls_V3d_DirectionalLight.def(py::init<const V3d_TypeOfOrientation, const Quantity_Color &>(), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_DirectionalLight.def(py::init<const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Boolean>(), py::arg("theDirection"), py::arg("theColor"), py::arg("theIsHeadlight"));
cls_V3d_DirectionalLight.def(py::init<const gp_Dir &>(), py::arg("theDirection"));
cls_V3d_DirectionalLight.def(py::init<const gp_Dir &, const Quantity_Color &>(), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_DirectionalLight.def(py::init<const gp_Dir &, const Quantity_Color &, const Standard_Boolean>(), py::arg("theDirection"), py::arg("theColor"), py::arg("theIsHeadlight"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &>(), py::arg("theViewer"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const V3d_TypeOfOrientation>(), py::arg("theViewer"), py::arg("theDirection"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const V3d_TypeOfOrientation, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Boolean>(), py::arg("theViewer"), py::arg("theDirection"), py::arg("theColor"), py::arg("theIsHeadlight"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Boolean>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theIsHeadlight"));

// Fields

// Methods
cls_V3d_DirectionalLight.def_static("get_type_name_", (const char * (*)()) &V3d_DirectionalLight::get_type_name, "None");
cls_V3d_DirectionalLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_DirectionalLight::get_type_descriptor, "None");
cls_V3d_DirectionalLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_DirectionalLight::*)() const) &V3d_DirectionalLight::DynamicType, "None");
cls_V3d_DirectionalLight.def("SetDirection", (void (V3d_DirectionalLight::*)(V3d_TypeOfOrientation)) &V3d_DirectionalLight::SetDirection, "Defines the direction of the light source by a predefined orientation.", py::arg("theDirection"));

// Enums

}