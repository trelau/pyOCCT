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
#include <IGESData_LineFontEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESBasic_SubfigureDef.hxx>
#include <IGESGraph_LineFontDefTemplate.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_LineFontDefTemplate(py::module &mod){

py::class_<IGESGraph_LineFontDefTemplate, opencascade::handle<IGESGraph_LineFontDefTemplate>, IGESData_LineFontEntity> cls_IGESGraph_LineFontDefTemplate(mod, "IGESGraph_LineFontDefTemplate", "defines IGESLineFontDefTemplate, Type <304> Form <1> in package IGESGraph");

// Constructors
cls_IGESGraph_LineFontDefTemplate.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_LineFontDefTemplate.def("Init", (void (IGESGraph_LineFontDefTemplate::*)(const Standard_Integer, const opencascade::handle<IGESBasic_SubfigureDef> &, const Standard_Real, const Standard_Real)) &IGESGraph_LineFontDefTemplate::Init, "This method is used to set the fields of the class LineFontDefTemplate - anOrientation : Orientation of Template figure on anchoring curve - aTemplate : SubfigureDef entity used as Template figure - aDistance : Distance between the neighbouring Template figures - aScale : Scale factor applied to the Template figure", py::arg("anOrientation"), py::arg("aTemplate"), py::arg("aDistance"), py::arg("aScale"));
cls_IGESGraph_LineFontDefTemplate.def("Orientation", (Standard_Integer (IGESGraph_LineFontDefTemplate::*)() const) &IGESGraph_LineFontDefTemplate::Orientation, "if return value = 0, Each Template display is oriented by aligning the axis of the SubfigureDef with the axis of the definition space of the anchoring curve. = 1, Each Template display is oriented by aligning X-axis of the SubfigureDef with the tangent vector of the anchoring curve at the point of incidence of the curve and the origin of subfigure. Similarly Z-axis is aligned.");
cls_IGESGraph_LineFontDefTemplate.def("TemplateEntity", (opencascade::handle<IGESBasic_SubfigureDef> (IGESGraph_LineFontDefTemplate::*)() const) &IGESGraph_LineFontDefTemplate::TemplateEntity, "returns SubfigureDef as the Entity used as Template figure.");
cls_IGESGraph_LineFontDefTemplate.def("Distance", (Standard_Real (IGESGraph_LineFontDefTemplate::*)() const) &IGESGraph_LineFontDefTemplate::Distance, "returns the Distance between any two Template figures on the anchoring curve.");
cls_IGESGraph_LineFontDefTemplate.def("Scale", (Standard_Real (IGESGraph_LineFontDefTemplate::*)() const) &IGESGraph_LineFontDefTemplate::Scale, "returns the Scaling factor applied to SubfigureDef to form Template figure.");
cls_IGESGraph_LineFontDefTemplate.def_static("get_type_name_", (const char * (*)()) &IGESGraph_LineFontDefTemplate::get_type_name, "None");
cls_IGESGraph_LineFontDefTemplate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_LineFontDefTemplate::get_type_descriptor, "None");
cls_IGESGraph_LineFontDefTemplate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_LineFontDefTemplate::*)() const) &IGESGraph_LineFontDefTemplate::DynamicType, "None");

// Enums

}