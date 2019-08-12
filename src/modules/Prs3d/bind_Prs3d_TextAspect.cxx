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
#include <Prs3d_TextAspect.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <Graphic3d_TextPath.hxx>

void bind_Prs3d_TextAspect(py::module &mod){

py::class_<Prs3d_TextAspect, opencascade::handle<Prs3d_TextAspect>, Prs3d_BasicAspect> cls_Prs3d_TextAspect(mod, "Prs3d_TextAspect", "Defines the attributes when displaying a text.");

// Constructors
cls_Prs3d_TextAspect.def(py::init<>());
cls_Prs3d_TextAspect.def(py::init<const opencascade::handle<Graphic3d_AspectText3d> &>(), py::arg("theAspect"));

// Fields

// Methods
cls_Prs3d_TextAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_TextAspect::get_type_name, "None");
cls_Prs3d_TextAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_TextAspect::get_type_descriptor, "None");
cls_Prs3d_TextAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_TextAspect::*)() const) &Prs3d_TextAspect::DynamicType, "None");
cls_Prs3d_TextAspect.def("SetColor", (void (Prs3d_TextAspect::*)(const Quantity_Color &)) &Prs3d_TextAspect::SetColor, "Sets the color of the type used in text display.", py::arg("theColor"));
cls_Prs3d_TextAspect.def("SetFont", (void (Prs3d_TextAspect::*)(const Standard_CString)) &Prs3d_TextAspect::SetFont, "Sets the font used in text display.", py::arg("theFont"));
cls_Prs3d_TextAspect.def("SetHeightWidthRatio", (void (Prs3d_TextAspect::*)(const Standard_Real)) &Prs3d_TextAspect::SetHeightWidthRatio, "Returns the height-width ratio, also known as the expansion factor.", py::arg("theRatio"));
cls_Prs3d_TextAspect.def("SetSpace", (void (Prs3d_TextAspect::*)(const Standard_Real)) &Prs3d_TextAspect::SetSpace, "Sets the length of the box which text will occupy.", py::arg("theSpace"));
cls_Prs3d_TextAspect.def("SetHeight", (void (Prs3d_TextAspect::*)(const Standard_Real)) &Prs3d_TextAspect::SetHeight, "Sets the height of the text.", py::arg("theHeight"));
cls_Prs3d_TextAspect.def("SetAngle", (void (Prs3d_TextAspect::*)(const Standard_Real)) &Prs3d_TextAspect::SetAngle, "Sets the angle", py::arg("theAngle"));
cls_Prs3d_TextAspect.def("Height", (Standard_Real (Prs3d_TextAspect::*)() const) &Prs3d_TextAspect::Height, "Returns the height of the text box.");
cls_Prs3d_TextAspect.def("Angle", (Standard_Real (Prs3d_TextAspect::*)() const) &Prs3d_TextAspect::Angle, "Returns the angle");
cls_Prs3d_TextAspect.def("SetHorizontalJustification", (void (Prs3d_TextAspect::*)(const Graphic3d_HorizontalTextAlignment)) &Prs3d_TextAspect::SetHorizontalJustification, "Sets horizontal alignment of text.", py::arg("theJustification"));
cls_Prs3d_TextAspect.def("SetVerticalJustification", (void (Prs3d_TextAspect::*)(const Graphic3d_VerticalTextAlignment)) &Prs3d_TextAspect::SetVerticalJustification, "Sets the vertical alignment of text.", py::arg("theJustification"));
cls_Prs3d_TextAspect.def("SetOrientation", (void (Prs3d_TextAspect::*)(const Graphic3d_TextPath)) &Prs3d_TextAspect::SetOrientation, "Sets the orientation of text.", py::arg("theOrientation"));
cls_Prs3d_TextAspect.def("HorizontalJustification", (Graphic3d_HorizontalTextAlignment (Prs3d_TextAspect::*)() const) &Prs3d_TextAspect::HorizontalJustification, "Returns the horizontal alignment of the text. The range of values includes: - left - center - right, and - normal (justified).");
cls_Prs3d_TextAspect.def("VerticalJustification", (Graphic3d_VerticalTextAlignment (Prs3d_TextAspect::*)() const) &Prs3d_TextAspect::VerticalJustification, "Returns the vertical alignment of the text. The range of values includes: - normal - top - cap - half - base - bottom");
cls_Prs3d_TextAspect.def("Orientation", (Graphic3d_TextPath (Prs3d_TextAspect::*)() const) &Prs3d_TextAspect::Orientation, "Returns the orientation of the text. Text can be displayed in the following directions: - up - down - left, or - right");
cls_Prs3d_TextAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectText3d> & (Prs3d_TextAspect::*)() const) &Prs3d_TextAspect::Aspect, "Returns the purely textual attributes used in the display of text. These include: - color - font - height/width ratio, that is, the expansion factor, and - space between characters.");
cls_Prs3d_TextAspect.def("SetAspect", (void (Prs3d_TextAspect::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &Prs3d_TextAspect::SetAspect, "None", py::arg("theAspect"));

// Enums

}