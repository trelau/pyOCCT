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
#include <AIS_InteractiveObject.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Pnt.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <Font_FontAspect.hxx>
#include <gp_Ax2.hxx>
#include <Aspect_TypeOfDisplayText.hxx>
#include <Standard_Handle.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <TCollection_AsciiString.hxx>
#include <AIS_TextLabel.hxx>
#include <Standard_Type.hxx>

void bind_AIS_TextLabel(py::module &mod){

py::class_<AIS_TextLabel, opencascade::handle<AIS_TextLabel>, AIS_InteractiveObject> cls_AIS_TextLabel(mod, "AIS_TextLabel", "Presentation of the text.");

// Constructors
cls_AIS_TextLabel.def(py::init<>());

// Fields

// Methods
cls_AIS_TextLabel.def("SetColor", (void (AIS_TextLabel::*)(const Quantity_Color &)) &AIS_TextLabel::SetColor, "Setup color of entire text.", py::arg("theColor"));
cls_AIS_TextLabel.def("SetTransparency", (void (AIS_TextLabel::*)(const Standard_Real)) &AIS_TextLabel::SetTransparency, "Setup transparency within [0, 1] range.", py::arg("theValue"));
cls_AIS_TextLabel.def("UnsetTransparency", (void (AIS_TextLabel::*)()) &AIS_TextLabel::UnsetTransparency, "Removes the transparency setting.");
cls_AIS_TextLabel.def("SetMaterial", (void (AIS_TextLabel::*)(const Graphic3d_MaterialAspect &)) &AIS_TextLabel::SetMaterial, "Material has no effect for text label.", py::arg(""));
cls_AIS_TextLabel.def("SetText", (void (AIS_TextLabel::*)(const TCollection_ExtendedString &)) &AIS_TextLabel::SetText, "Setup text.", py::arg("theText"));
cls_AIS_TextLabel.def("SetPosition", (void (AIS_TextLabel::*)(const gp_Pnt &)) &AIS_TextLabel::SetPosition, "Setup position.", py::arg("thePosition"));
cls_AIS_TextLabel.def("SetHJustification", (void (AIS_TextLabel::*)(const Graphic3d_HorizontalTextAlignment)) &AIS_TextLabel::SetHJustification, "Setup horizontal justification.", py::arg("theHJust"));
cls_AIS_TextLabel.def("SetVJustification", (void (AIS_TextLabel::*)(const Graphic3d_VerticalTextAlignment)) &AIS_TextLabel::SetVJustification, "Setup vertical justification.", py::arg("theVJust"));
cls_AIS_TextLabel.def("SetAngle", (void (AIS_TextLabel::*)(const Standard_Real)) &AIS_TextLabel::SetAngle, "Setup angle.", py::arg("theAngle"));
cls_AIS_TextLabel.def("SetZoomable", (void (AIS_TextLabel::*)(const Standard_Boolean)) &AIS_TextLabel::SetZoomable, "Setup zoomable property.", py::arg("theIsZoomable"));
cls_AIS_TextLabel.def("SetHeight", (void (AIS_TextLabel::*)(const Standard_Real)) &AIS_TextLabel::SetHeight, "Setup height.", py::arg("theHeight"));
cls_AIS_TextLabel.def("SetFontAspect", (void (AIS_TextLabel::*)(const Font_FontAspect)) &AIS_TextLabel::SetFontAspect, "Setup font aspect.", py::arg("theFontAspect"));
cls_AIS_TextLabel.def("SetFont", (void (AIS_TextLabel::*)(Standard_CString)) &AIS_TextLabel::SetFont, "Setup font.", py::arg("theFont"));
cls_AIS_TextLabel.def("SetOrientation3D", (void (AIS_TextLabel::*)(const gp_Ax2 &)) &AIS_TextLabel::SetOrientation3D, "Setup label orientation in the model 3D space.", py::arg("theOrientation"));
cls_AIS_TextLabel.def("UnsetOrientation3D", (void (AIS_TextLabel::*)()) &AIS_TextLabel::UnsetOrientation3D, "Reset label orientation in the model 3D space.");
cls_AIS_TextLabel.def("Position", (const gp_Pnt & (AIS_TextLabel::*)() const) &AIS_TextLabel::Position, "Returns position.");
cls_AIS_TextLabel.def("Orientation3D", (const gp_Ax2 & (AIS_TextLabel::*)() const) &AIS_TextLabel::Orientation3D, "Returns label orientation in the model 3D space.");
cls_AIS_TextLabel.def("HasOrientation3D", (Standard_Boolean (AIS_TextLabel::*)() const) &AIS_TextLabel::HasOrientation3D, "Returns true if the current text placement mode uses text orientation in the model 3D space.");
cls_AIS_TextLabel.def("SetFlipping", (void (AIS_TextLabel::*)(const Standard_Boolean)) &AIS_TextLabel::SetFlipping, "None", py::arg("theIsFlipping"));
cls_AIS_TextLabel.def("HasFlipping", (Standard_Boolean (AIS_TextLabel::*)() const) &AIS_TextLabel::HasFlipping, "None");
cls_AIS_TextLabel.def("SetDisplayType", (void (AIS_TextLabel::*)(const Aspect_TypeOfDisplayText)) &AIS_TextLabel::SetDisplayType, "Define the display type of the text.", py::arg("theDisplayType"));
cls_AIS_TextLabel.def("SetColorSubTitle", (void (AIS_TextLabel::*)(const Quantity_Color &)) &AIS_TextLabel::SetColorSubTitle, "Modifies the colour of the subtitle for the TODT_SUBTITLE TextDisplayType and the colour of backgroubd for the TODT_DEKALE TextDisplayType.", py::arg("theColor"));
cls_AIS_TextLabel.def_static("get_type_name_", (const char * (*)()) &AIS_TextLabel::get_type_name, "None");
cls_AIS_TextLabel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TextLabel::get_type_descriptor, "None");
cls_AIS_TextLabel.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TextLabel::*)() const) &AIS_TextLabel::DynamicType, "None");

// Enums

}