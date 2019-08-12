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
#include <Graphic3d_AspectText3d.hxx>
#include <Standard_Type.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_TypeOfStyleText.hxx>
#include <Aspect_TypeOfDisplayText.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Graphic3d_AspectTextDefinitionError.hxx>
#include <TCollection_AsciiString.hxx>
#include <Font_FontAspect.hxx>
#include <Graphic3d_ShaderProgram.hxx>

void bind_Graphic3d_AspectText3d(py::module &mod){

py::class_<Graphic3d_AspectText3d, opencascade::handle<Graphic3d_AspectText3d>, Standard_Transient> cls_Graphic3d_AspectText3d(mod, "Graphic3d_AspectText3d", "Creates and updates a group of attributes for text primitives. This group contains the color, font, expansion factor (height/width ratio), and inter-character space.");

// Constructors
cls_Graphic3d_AspectText3d.def(py::init<>());
cls_Graphic3d_AspectText3d.def(py::init<const Quantity_Color &, const Standard_CString, const Standard_Real, const Standard_Real>(), py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"));
cls_Graphic3d_AspectText3d.def(py::init<const Quantity_Color &, const Standard_CString, const Standard_Real, const Standard_Real, const Aspect_TypeOfStyleText>(), py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"));
cls_Graphic3d_AspectText3d.def(py::init<const Quantity_Color &, const Standard_CString, const Standard_Real, const Standard_Real, const Aspect_TypeOfStyleText, const Aspect_TypeOfDisplayText>(), py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"), py::arg("theDisplayType"));

// Fields

// Methods
cls_Graphic3d_AspectText3d.def_static("get_type_name_", (const char * (*)()) &Graphic3d_AspectText3d::get_type_name, "None");
cls_Graphic3d_AspectText3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_AspectText3d::get_type_descriptor, "None");
cls_Graphic3d_AspectText3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::DynamicType, "None");
cls_Graphic3d_AspectText3d.def("Color", (const Quantity_Color & (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::Color, "Return the text color.");
cls_Graphic3d_AspectText3d.def("ColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::ColorRGBA, "Return the text color.");
cls_Graphic3d_AspectText3d.def("SetColor", (void (Graphic3d_AspectText3d::*)(const Quantity_Color &)) &Graphic3d_AspectText3d::SetColor, "Modifies the color.", py::arg("theColor"));
cls_Graphic3d_AspectText3d.def("SetColor", (void (Graphic3d_AspectText3d::*)(const Quantity_ColorRGBA &)) &Graphic3d_AspectText3d::SetColor, "Modifies the color.", py::arg("theColor"));
cls_Graphic3d_AspectText3d.def("SetExpansionFactor", (void (Graphic3d_AspectText3d::*)(const Standard_Real)) &Graphic3d_AspectText3d::SetExpansionFactor, "Modifies the expansion factor (height/width ratio) If the factor is less than 1, the characters will be higher than they are wide.", py::arg("theFactor"));
cls_Graphic3d_AspectText3d.def("Font", (const TCollection_AsciiString & (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::Font, "Return the font.");
cls_Graphic3d_AspectText3d.def("SetFont", (void (Graphic3d_AspectText3d::*)(const TCollection_AsciiString &)) &Graphic3d_AspectText3d::SetFont, "Modifies the font.", py::arg("theFont"));
cls_Graphic3d_AspectText3d.def("SetFont", (void (Graphic3d_AspectText3d::*)(const Standard_CString)) &Graphic3d_AspectText3d::SetFont, "Modifies the font.", py::arg("theFont"));
cls_Graphic3d_AspectText3d.def("Space", (Standard_Real (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::Space, "Return the space between characters.");
cls_Graphic3d_AspectText3d.def("SetSpace", (void (Graphic3d_AspectText3d::*)(const Standard_Real)) &Graphic3d_AspectText3d::SetSpace, "Modifies the space between the characters.", py::arg("theSpace"));
cls_Graphic3d_AspectText3d.def("Style", (Aspect_TypeOfStyleText (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::Style, "Return the text style.");
cls_Graphic3d_AspectText3d.def("SetStyle", (void (Graphic3d_AspectText3d::*)(const Aspect_TypeOfStyleText)) &Graphic3d_AspectText3d::SetStyle, "Modifies the style of the text. * TOST_NORMAL Default text. The text is displayed like any other graphic object. This text can be hidden by another object that is nearest from the point of view. * TOST_ANNOTATION The text is always visible. The text is displayed over the other object according to the priority.", py::arg("theStyle"));
cls_Graphic3d_AspectText3d.def("DisplayType", (Aspect_TypeOfDisplayText (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::DisplayType, "Return display type.");
cls_Graphic3d_AspectText3d.def("SetDisplayType", (void (Graphic3d_AspectText3d::*)(const Aspect_TypeOfDisplayText)) &Graphic3d_AspectText3d::SetDisplayType, "Define the display type of the text.", py::arg("theDisplayType"));
cls_Graphic3d_AspectText3d.def("ColorSubTitleRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::ColorSubTitleRGBA, "Return subtitle color.");
cls_Graphic3d_AspectText3d.def("ColorSubTitle", (const Quantity_Color & (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::ColorSubTitle, "Return subtitle color.");
cls_Graphic3d_AspectText3d.def("SetColorSubTitle", (void (Graphic3d_AspectText3d::*)(const Quantity_Color &)) &Graphic3d_AspectText3d::SetColorSubTitle, "Modifies the color of the subtitle for the TODT_SUBTITLE TextDisplayType and the color of background for the TODT_DEKALE TextDisplayType.", py::arg("theColor"));
cls_Graphic3d_AspectText3d.def("SetColorSubTitle", (void (Graphic3d_AspectText3d::*)(const Quantity_ColorRGBA &)) &Graphic3d_AspectText3d::SetColorSubTitle, "Modifies the color of the subtitle for the TODT_SUBTITLE TextDisplayType and the color of background for the TODT_DEKALE TextDisplayType.", py::arg("theColor"));
cls_Graphic3d_AspectText3d.def("GetTextZoomable", (bool (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::GetTextZoomable, "Returns TRUE when the Text Zoomable is on.");
cls_Graphic3d_AspectText3d.def("SetTextZoomable", (void (Graphic3d_AspectText3d::*)(const bool)) &Graphic3d_AspectText3d::SetTextZoomable, "Turns usage of text zoomable on/off", py::arg("theFlag"));
cls_Graphic3d_AspectText3d.def("GetTextAngle", (Standard_Real (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::GetTextAngle, "Returns Angle of degree");
cls_Graphic3d_AspectText3d.def("SetTextAngle", (void (Graphic3d_AspectText3d::*)(const Standard_Real)) &Graphic3d_AspectText3d::SetTextAngle, "Turns usage of text rotated", py::arg("theAngle"));
cls_Graphic3d_AspectText3d.def("GetTextFontAspect", (Font_FontAspect (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::GetTextFontAspect, "Returns text FontAspect");
cls_Graphic3d_AspectText3d.def("SetTextFontAspect", (void (Graphic3d_AspectText3d::*)(const Font_FontAspect)) &Graphic3d_AspectText3d::SetTextFontAspect, "Turns usage of Aspect text", py::arg("theFontAspect"));
cls_Graphic3d_AspectText3d.def("ShaderProgram", (const opencascade::handle<Graphic3d_ShaderProgram> & (Graphic3d_AspectText3d::*)() const) &Graphic3d_AspectText3d::ShaderProgram, "Return the shader program.");
cls_Graphic3d_AspectText3d.def("SetShaderProgram", (void (Graphic3d_AspectText3d::*)(const opencascade::handle<Graphic3d_ShaderProgram> &)) &Graphic3d_AspectText3d::SetShaderProgram, "Sets up OpenGL/GLSL shader program.", py::arg("theProgram"));
// cls_Graphic3d_AspectText3d.def("Values", [](Graphic3d_AspectText3d &self, Quantity_Color & theColor, Standard_CString & theFont, Standard_Real & theExpansionFactor, Standard_Real & theSpace){ self.Values(theColor, theFont, theExpansionFactor, theSpace); return std::tuple<Standard_CString &, Standard_Real &, Standard_Real &>(theFont, theExpansionFactor, theSpace); }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"));
// cls_Graphic3d_AspectText3d.def("Values", [](Graphic3d_AspectText3d &self, Quantity_Color & theColor, Standard_CString & theFont, Standard_Real & theExpansionFactor, Standard_Real & theSpace, Aspect_TypeOfStyleText & theStyle, Aspect_TypeOfDisplayText & theDisplayType, Quantity_Color & theColorSubTitle){ self.Values(theColor, theFont, theExpansionFactor, theSpace, theStyle, theDisplayType, theColorSubTitle); return std::tuple<Standard_CString &, Standard_Real &, Standard_Real &>(theFont, theExpansionFactor, theSpace); }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"), py::arg("theDisplayType"), py::arg("theColorSubTitle"));
// cls_Graphic3d_AspectText3d.def("Values", [](Graphic3d_AspectText3d &self, Quantity_Color & theColor, Standard_CString & theFont, Standard_Real & theExpansionFactor, Standard_Real & theSpace, Aspect_TypeOfStyleText & theStyle, Aspect_TypeOfDisplayText & theDisplayType, Quantity_Color & theColorSubTitle, Standard_Boolean & theTextZoomable, Standard_Real & theTextAngle){ self.Values(theColor, theFont, theExpansionFactor, theSpace, theStyle, theDisplayType, theColorSubTitle, theTextZoomable, theTextAngle); return std::tuple<Standard_CString &, Standard_Real &, Standard_Real &, Standard_Boolean &, Standard_Real &>(theFont, theExpansionFactor, theSpace, theTextZoomable, theTextAngle); }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"), py::arg("theDisplayType"), py::arg("theColorSubTitle"), py::arg("theTextZoomable"), py::arg("theTextAngle"));
// cls_Graphic3d_AspectText3d.def("Values", [](Graphic3d_AspectText3d &self, Quantity_Color & theColor, Standard_CString & theFont, Standard_Real & theExpansionFactor, Standard_Real & theSpace, Aspect_TypeOfStyleText & theStyle, Aspect_TypeOfDisplayText & theDisplayType, Quantity_Color & theColorSubTitle, Standard_Boolean & theTextZoomable, Standard_Real & theTextAngle, Font_FontAspect & theTextFontAspect){ self.Values(theColor, theFont, theExpansionFactor, theSpace, theStyle, theDisplayType, theColorSubTitle, theTextZoomable, theTextAngle, theTextFontAspect); return std::tuple<Standard_CString &, Standard_Real &, Standard_Real &, Standard_Boolean &, Standard_Real &>(theFont, theExpansionFactor, theSpace, theTextZoomable, theTextAngle); }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theFont"), py::arg("theExpansionFactor"), py::arg("theSpace"), py::arg("theStyle"), py::arg("theDisplayType"), py::arg("theColorSubTitle"), py::arg("theTextZoomable"), py::arg("theTextAngle"), py::arg("theTextFontAspect"));

// Enums

}