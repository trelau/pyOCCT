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
#include <Graphic3d_PresentationAttributes.hxx>
#include <Standard_Type.hxx>
#include <Aspect_TypeOfHighlightMethod.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>

void bind_Graphic3d_PresentationAttributes(py::module &mod){

py::class_<Graphic3d_PresentationAttributes, opencascade::handle<Graphic3d_PresentationAttributes>, Standard_Transient> cls_Graphic3d_PresentationAttributes(mod, "Graphic3d_PresentationAttributes", "Class defines presentation properties.");

// Constructors
cls_Graphic3d_PresentationAttributes.def(py::init<>());

// Fields

// Methods
cls_Graphic3d_PresentationAttributes.def_static("get_type_name_", (const char * (*)()) &Graphic3d_PresentationAttributes::get_type_name, "None");
cls_Graphic3d_PresentationAttributes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_PresentationAttributes::get_type_descriptor, "None");
cls_Graphic3d_PresentationAttributes.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_PresentationAttributes::*)() const) &Graphic3d_PresentationAttributes::DynamicType, "None");
cls_Graphic3d_PresentationAttributes.def("Method", (Aspect_TypeOfHighlightMethod (Graphic3d_PresentationAttributes::*)() const) &Graphic3d_PresentationAttributes::Method, "Returns highlight method, Aspect_TOHM_COLOR by default.");
cls_Graphic3d_PresentationAttributes.def("SetMethod", (void (Graphic3d_PresentationAttributes::*)(const Aspect_TypeOfHighlightMethod)) &Graphic3d_PresentationAttributes::SetMethod, "Changes highlight method to the given one.", py::arg("theMethod"));
cls_Graphic3d_PresentationAttributes.def("ColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_PresentationAttributes::*)() const) &Graphic3d_PresentationAttributes::ColorRGBA, "Returns basic presentation color (including alpha channel).");
cls_Graphic3d_PresentationAttributes.def("Color", (const Quantity_Color & (Graphic3d_PresentationAttributes::*)() const) &Graphic3d_PresentationAttributes::Color, "Returns basic presentation color, Quantity_NOC_WHITE by default.");
cls_Graphic3d_PresentationAttributes.def("SetColor", (void (Graphic3d_PresentationAttributes::*)(const Quantity_Color &)) &Graphic3d_PresentationAttributes::SetColor, "Sets basic presentation color (RGB components, does not modifies transparency).", py::arg("theColor"));
cls_Graphic3d_PresentationAttributes.def("Transparency", (Standard_ShortReal (Graphic3d_PresentationAttributes::*)() const) &Graphic3d_PresentationAttributes::Transparency, "Returns basic presentation transparency (0 - opaque, 1 - fully transparent), 0 by default (opaque).");
cls_Graphic3d_PresentationAttributes.def("SetTransparency", (void (Graphic3d_PresentationAttributes::*)(const Standard_ShortReal)) &Graphic3d_PresentationAttributes::SetTransparency, "Sets basic presentation transparency (0 - opaque, 1 - fully transparent).", py::arg("theTranspCoef"));
cls_Graphic3d_PresentationAttributes.def("ZLayer", (Graphic3d_ZLayerId (Graphic3d_PresentationAttributes::*)() const) &Graphic3d_PresentationAttributes::ZLayer, "Returns presentation Zlayer, Graphic3d_ZLayerId_Default by default. Graphic3d_ZLayerId_UNKNOWN means undefined (a layer of main presentation to be used).");
cls_Graphic3d_PresentationAttributes.def("SetZLayer", (void (Graphic3d_PresentationAttributes::*)(const Graphic3d_ZLayerId)) &Graphic3d_PresentationAttributes::SetZLayer, "Sets presentation Zlayer.", py::arg("theLayer"));
cls_Graphic3d_PresentationAttributes.def("DisplayMode", (Standard_Integer (Graphic3d_PresentationAttributes::*)() const) &Graphic3d_PresentationAttributes::DisplayMode, "Returns display mode, 0 by default. -1 means undefined (main display mode of presentation to be used).");
cls_Graphic3d_PresentationAttributes.def("SetDisplayMode", (void (Graphic3d_PresentationAttributes::*)(const Standard_Integer)) &Graphic3d_PresentationAttributes::SetDisplayMode, "Sets display mode.", py::arg("theMode"));
cls_Graphic3d_PresentationAttributes.def("BasicFillAreaAspect", (const opencascade::handle<Graphic3d_AspectFillArea3d> & (Graphic3d_PresentationAttributes::*)() const) &Graphic3d_PresentationAttributes::BasicFillAreaAspect, "Return basic presentation fill area aspect, NULL by default. When set, might be used instead of Color() property.");
cls_Graphic3d_PresentationAttributes.def("SetBasicFillAreaAspect", (void (Graphic3d_PresentationAttributes::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Graphic3d_PresentationAttributes::SetBasicFillAreaAspect, "Sets basic presentation fill area aspect.", py::arg("theAspect"));

// Enums

}