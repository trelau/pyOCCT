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
#include <Prs3d_DimensionAspect.hxx>
#include <Standard_Type.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_TextAspect.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_DimensionArrowOrientation.hxx>
#include <Prs3d_DimensionTextVerticalPosition.hxx>
#include <Prs3d_DimensionTextHorizontalPosition.hxx>
#include <Prs3d_ArrowAspect.hxx>
#include <Quantity_Color.hxx>
#include <TCollection_AsciiString.hxx>

void bind_Prs3d_DimensionAspect(py::module &mod){

py::class_<Prs3d_DimensionAspect, opencascade::handle<Prs3d_DimensionAspect>, Prs3d_BasicAspect> cls_Prs3d_DimensionAspect(mod, "Prs3d_DimensionAspect", "defines the attributes when drawing a Length Presentation.");

// Constructors
cls_Prs3d_DimensionAspect.def(py::init<>());

// Fields

// Methods
cls_Prs3d_DimensionAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_DimensionAspect::get_type_name, "None");
cls_Prs3d_DimensionAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_DimensionAspect::get_type_descriptor, "None");
cls_Prs3d_DimensionAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::DynamicType, "None");
cls_Prs3d_DimensionAspect.def("LineAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::LineAspect, "Returns the settings for the display of lines used in presentation of dimensions.");
cls_Prs3d_DimensionAspect.def("SetLineAspect", (void (Prs3d_DimensionAspect::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_DimensionAspect::SetLineAspect, "Sets the display attributes of lines used in presentation of dimensions.", py::arg("theAspect"));
cls_Prs3d_DimensionAspect.def("TextAspect", (const opencascade::handle<Prs3d_TextAspect> & (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::TextAspect, "Returns the settings for the display of text used in presentation of dimensions.");
cls_Prs3d_DimensionAspect.def("SetTextAspect", (void (Prs3d_DimensionAspect::*)(const opencascade::handle<Prs3d_TextAspect> &)) &Prs3d_DimensionAspect::SetTextAspect, "Sets the display attributes of text used in presentation of dimensions.", py::arg("theAspect"));
cls_Prs3d_DimensionAspect.def("IsText3d", (Standard_Boolean (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::IsText3d, "Check if text for dimension label is 3d.");
cls_Prs3d_DimensionAspect.def("MakeText3d", (void (Prs3d_DimensionAspect::*)(const Standard_Boolean)) &Prs3d_DimensionAspect::MakeText3d, "Sets type of text.", py::arg("isText3d"));
cls_Prs3d_DimensionAspect.def("IsTextShaded", (Standard_Boolean (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::IsTextShaded, "Check if 3d text for dimension label is shaded.");
cls_Prs3d_DimensionAspect.def("MakeTextShaded", (void (Prs3d_DimensionAspect::*)(const Standard_Boolean)) &Prs3d_DimensionAspect::MakeTextShaded, "Turns on/off text shading for 3d text.", py::arg("theIsTextShaded"));
cls_Prs3d_DimensionAspect.def("IsArrows3d", (Standard_Boolean (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::IsArrows3d, "Gets type of arrows.");
cls_Prs3d_DimensionAspect.def("MakeArrows3d", (void (Prs3d_DimensionAspect::*)(const Standard_Boolean)) &Prs3d_DimensionAspect::MakeArrows3d, "Sets type of arrows.", py::arg("theIsArrows3d"));
cls_Prs3d_DimensionAspect.def("IsUnitsDisplayed", (Standard_Boolean (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::IsUnitsDisplayed, "Shows if Units are to be displayed along with dimension value.");
cls_Prs3d_DimensionAspect.def("MakeUnitsDisplayed", (void (Prs3d_DimensionAspect::*)(const Standard_Boolean)) &Prs3d_DimensionAspect::MakeUnitsDisplayed, "Specifies whether the units string should be displayed along with value label or not.", py::arg("theIsDisplayed"));
cls_Prs3d_DimensionAspect.def("SetArrowOrientation", (void (Prs3d_DimensionAspect::*)(const Prs3d_DimensionArrowOrientation)) &Prs3d_DimensionAspect::SetArrowOrientation, "Sets orientation of arrows (external or internal). By default orientation is chosen automatically according to situation and text label size.", py::arg("theArrowOrient"));
cls_Prs3d_DimensionAspect.def("ArrowOrientation", (Prs3d_DimensionArrowOrientation (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::ArrowOrientation, "Gets orientation of arrows (external or internal).");
cls_Prs3d_DimensionAspect.def("SetTextVerticalPosition", (void (Prs3d_DimensionAspect::*)(const Prs3d_DimensionTextVerticalPosition)) &Prs3d_DimensionAspect::SetTextVerticalPosition, "Sets vertical text alignment for text label.", py::arg("thePosition"));
cls_Prs3d_DimensionAspect.def("TextVerticalPosition", (Prs3d_DimensionTextVerticalPosition (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::TextVerticalPosition, "Gets vertical text alignment for text label.");
cls_Prs3d_DimensionAspect.def("SetTextHorizontalPosition", (void (Prs3d_DimensionAspect::*)(const Prs3d_DimensionTextHorizontalPosition)) &Prs3d_DimensionAspect::SetTextHorizontalPosition, "Sets horizontal text alignment for text label.", py::arg("thePosition"));
cls_Prs3d_DimensionAspect.def("TextHorizontalPosition", (Prs3d_DimensionTextHorizontalPosition (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::TextHorizontalPosition, "Gets horizontal text alignment for text label.");
cls_Prs3d_DimensionAspect.def("ArrowAspect", (const opencascade::handle<Prs3d_ArrowAspect> & (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::ArrowAspect, "Returns the settings for displaying arrows.");
cls_Prs3d_DimensionAspect.def("SetArrowAspect", (void (Prs3d_DimensionAspect::*)(const opencascade::handle<Prs3d_ArrowAspect> &)) &Prs3d_DimensionAspect::SetArrowAspect, "Sets the display attributes of arrows used in presentation of dimensions.", py::arg("theAspect"));
cls_Prs3d_DimensionAspect.def("SetCommonColor", (void (Prs3d_DimensionAspect::*)(const Quantity_Color &)) &Prs3d_DimensionAspect::SetCommonColor, "Sets the same color for all parts of dimension: lines, arrows and text.", py::arg("theColor"));
cls_Prs3d_DimensionAspect.def("SetExtensionSize", (void (Prs3d_DimensionAspect::*)(const Standard_Real)) &Prs3d_DimensionAspect::SetExtensionSize, "Sets extension size.", py::arg("theSize"));
cls_Prs3d_DimensionAspect.def("ExtensionSize", (Standard_Real (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::ExtensionSize, "Returns extension size.");
cls_Prs3d_DimensionAspect.def("SetArrowTailSize", (void (Prs3d_DimensionAspect::*)(const Standard_Real)) &Prs3d_DimensionAspect::SetArrowTailSize, "Set size for arrow tail (extension without text).", py::arg("theSize"));
cls_Prs3d_DimensionAspect.def("ArrowTailSize", (Standard_Real (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::ArrowTailSize, "Returns arrow tail size.");
cls_Prs3d_DimensionAspect.def("SetValueStringFormat", (void (Prs3d_DimensionAspect::*)(const TCollection_AsciiString &)) &Prs3d_DimensionAspect::SetValueStringFormat, "Sets 'sprintf'-syntax format for formatting dimension value labels.", py::arg("theFormat"));
cls_Prs3d_DimensionAspect.def("ValueStringFormat", (const TCollection_AsciiString & (Prs3d_DimensionAspect::*)() const) &Prs3d_DimensionAspect::ValueStringFormat, "Returns format.");

// Enums

}