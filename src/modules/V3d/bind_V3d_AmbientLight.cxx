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
#include <Graphic3d_CLight.hxx>
#include <Standard_Handle.hxx>
#include <V3d_AmbientLight.hxx>
#include <Standard_Type.hxx>
#include <Quantity_Color.hxx>
#include <V3d_Viewer.hxx>

void bind_V3d_AmbientLight(py::module &mod){

py::class_<V3d_AmbientLight, opencascade::handle<V3d_AmbientLight>, Graphic3d_CLight> cls_V3d_AmbientLight(mod, "V3d_AmbientLight", "Creation of an ambient light source in a viewer.");

// Constructors
cls_V3d_AmbientLight.def(py::init<>());
cls_V3d_AmbientLight.def(py::init<const Quantity_Color &>(), py::arg("theColor"));
cls_V3d_AmbientLight.def(py::init<const opencascade::handle<V3d_Viewer> &>(), py::arg("theViewer"));
cls_V3d_AmbientLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theColor"));

// Fields

// Methods
cls_V3d_AmbientLight.def_static("get_type_name_", (const char * (*)()) &V3d_AmbientLight::get_type_name, "None");
cls_V3d_AmbientLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_AmbientLight::get_type_descriptor, "None");
cls_V3d_AmbientLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_AmbientLight::*)() const) &V3d_AmbientLight::DynamicType, "None");

// Enums

}