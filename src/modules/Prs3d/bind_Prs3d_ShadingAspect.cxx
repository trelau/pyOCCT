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
#include <Prs3d_BasicAspect.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_TypeOfFacingModel.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Standard_TypeDef.hxx>

void bind_Prs3d_ShadingAspect(py::module &mod){

py::class_<Prs3d_ShadingAspect, opencascade::handle<Prs3d_ShadingAspect>, Prs3d_BasicAspect> cls_Prs3d_ShadingAspect(mod, "Prs3d_ShadingAspect", "A framework to define the display of shading. The attributes which make up this definition include: - fill aspect - color, and - material");

// Constructors
cls_Prs3d_ShadingAspect.def(py::init<>());
cls_Prs3d_ShadingAspect.def(py::init<const opencascade::handle<Graphic3d_AspectFillArea3d> &>(), py::arg("theAspect"));

// Fields

// Methods
cls_Prs3d_ShadingAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_ShadingAspect::get_type_name, "None");
cls_Prs3d_ShadingAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_ShadingAspect::get_type_descriptor, "None");
cls_Prs3d_ShadingAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_ShadingAspect::*)() const) &Prs3d_ShadingAspect::DynamicType, "None");
cls_Prs3d_ShadingAspect.def("SetColor", [](Prs3d_ShadingAspect &self, const Quantity_Color & a0) -> void { return self.SetColor(a0); });
cls_Prs3d_ShadingAspect.def("SetColor", (void (Prs3d_ShadingAspect::*)(const Quantity_Color &, const Aspect_TypeOfFacingModel)) &Prs3d_ShadingAspect::SetColor, "Change the polygons interior color and material ambient color.", py::arg("aColor"), py::arg("aModel"));
cls_Prs3d_ShadingAspect.def("SetMaterial", [](Prs3d_ShadingAspect &self, const Graphic3d_MaterialAspect & a0) -> void { return self.SetMaterial(a0); });
cls_Prs3d_ShadingAspect.def("SetMaterial", (void (Prs3d_ShadingAspect::*)(const Graphic3d_MaterialAspect &, const Aspect_TypeOfFacingModel)) &Prs3d_ShadingAspect::SetMaterial, "Change the polygons material aspect.", py::arg("aMaterial"), py::arg("aModel"));
cls_Prs3d_ShadingAspect.def("SetTransparency", [](Prs3d_ShadingAspect &self, const Standard_Real a0) -> void { return self.SetTransparency(a0); });
cls_Prs3d_ShadingAspect.def("SetTransparency", (void (Prs3d_ShadingAspect::*)(const Standard_Real, const Aspect_TypeOfFacingModel)) &Prs3d_ShadingAspect::SetTransparency, "Change the polygons transparency value. Warning : aValue must be in the range 0,1. 0 is the default (NO transparent)", py::arg("aValue"), py::arg("aModel"));
cls_Prs3d_ShadingAspect.def("Color", [](Prs3d_ShadingAspect &self) -> const Quantity_Color & { return self.Color(); });
cls_Prs3d_ShadingAspect.def("Color", (const Quantity_Color & (Prs3d_ShadingAspect::*)(const Aspect_TypeOfFacingModel) const) &Prs3d_ShadingAspect::Color, "Returns the polygons color.", py::arg("aModel"));
cls_Prs3d_ShadingAspect.def("Material", [](Prs3d_ShadingAspect &self) -> const Graphic3d_MaterialAspect & { return self.Material(); });
cls_Prs3d_ShadingAspect.def("Material", (const Graphic3d_MaterialAspect & (Prs3d_ShadingAspect::*)(const Aspect_TypeOfFacingModel) const) &Prs3d_ShadingAspect::Material, "Returns the polygons material aspect.", py::arg("aModel"));
cls_Prs3d_ShadingAspect.def("Transparency", [](Prs3d_ShadingAspect &self) -> Standard_Real { return self.Transparency(); });
cls_Prs3d_ShadingAspect.def("Transparency", (Standard_Real (Prs3d_ShadingAspect::*)(const Aspect_TypeOfFacingModel) const) &Prs3d_ShadingAspect::Transparency, "Returns the polygons transparency value.", py::arg("aModel"));
cls_Prs3d_ShadingAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectFillArea3d> & (Prs3d_ShadingAspect::*)() const) &Prs3d_ShadingAspect::Aspect, "Returns the polygons aspect properties.");
cls_Prs3d_ShadingAspect.def("SetAspect", (void (Prs3d_ShadingAspect::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Prs3d_ShadingAspect::SetAspect, "None", py::arg("theAspect"));

// Enums

}