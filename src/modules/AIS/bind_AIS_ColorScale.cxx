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
#include <Standard_Handle.hxx>
#include <AIS_ColorScale.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_TypeOfColorScaleData.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Aspect_SequenceOfColor.hxx>
#include <Aspect_TypeOfColorScalePosition.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <Graphic3d_Group.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>

void bind_AIS_ColorScale(py::module &mod){

py::class_<AIS_ColorScale, opencascade::handle<AIS_ColorScale>, AIS_InteractiveObject> cls_AIS_ColorScale(mod, "AIS_ColorScale", "Class for drawing a custom color scale.");

// Constructors
cls_AIS_ColorScale.def(py::init<>());

// Fields

// Methods
cls_AIS_ColorScale.def_static("get_type_name_", (const char * (*)()) &AIS_ColorScale::get_type_name, "None");
cls_AIS_ColorScale.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ColorScale::get_type_descriptor, "None");
cls_AIS_ColorScale.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ColorScale::*)() const) &AIS_ColorScale::DynamicType, "None");
cls_AIS_ColorScale.def_static("FindColor_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Graphic3d_Vec3d &, const Graphic3d_Vec3d &, Quantity_Color &)) &AIS_ColorScale::FindColor, "Calculate color according passed value; returns true if value is in range or false, if isn't", py::arg("theValue"), py::arg("theMin"), py::arg("theMax"), py::arg("theColorsCount"), py::arg("theColorHlsMin"), py::arg("theColorHlsMax"), py::arg("theColor"));
cls_AIS_ColorScale.def_static("FindColor_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, Quantity_Color &)) &AIS_ColorScale::FindColor, "Calculate color according passed value; returns true if value is in range or false, if isn't", py::arg("theValue"), py::arg("theMin"), py::arg("theMax"), py::arg("theColorsCount"), py::arg("theColor"));
cls_AIS_ColorScale.def_static("hueToValidRange_", (Standard_Real (*)(const Standard_Real)) &AIS_ColorScale::hueToValidRange, "Shift hue into valid range. Lightness and Saturation should be specified in valid range [0.0, 1.0], however Hue might be given out of Quantity_Color range to specify desired range for interpolation.", py::arg("theHue"));
cls_AIS_ColorScale.def("FindColor", (Standard_Boolean (AIS_ColorScale::*)(const Standard_Real, Quantity_Color &) const) &AIS_ColorScale::FindColor, "Calculate color according passed value; returns true if value is in range or false, if isn't", py::arg("theValue"), py::arg("theColor"));
cls_AIS_ColorScale.def("GetMin", (Standard_Real (AIS_ColorScale::*)() const) &AIS_ColorScale::GetMin, "Returns minimal value of color scale, 0.0 by default.");
cls_AIS_ColorScale.def("SetMin", (void (AIS_ColorScale::*)(const Standard_Real)) &AIS_ColorScale::SetMin, "Sets the minimal value of color scale.", py::arg("theMin"));
cls_AIS_ColorScale.def("GetMax", (Standard_Real (AIS_ColorScale::*)() const) &AIS_ColorScale::GetMax, "Returns maximal value of color scale, 1.0 by default.");
cls_AIS_ColorScale.def("SetMax", (void (AIS_ColorScale::*)(const Standard_Real)) &AIS_ColorScale::SetMax, "Sets the maximal value of color scale.", py::arg("theMax"));
cls_AIS_ColorScale.def("GetRange", [](AIS_ColorScale &self, Standard_Real & theMin, Standard_Real & theMax){ self.GetRange(theMin, theMax); return std::tuple<Standard_Real &, Standard_Real &>(theMin, theMax); }, "Returns minimal and maximal values of color scale, 0.0 to 1.0 by default.", py::arg("theMin"), py::arg("theMax"));
cls_AIS_ColorScale.def("SetRange", (void (AIS_ColorScale::*)(const Standard_Real, const Standard_Real)) &AIS_ColorScale::SetRange, "Sets the minimal and maximal value of color scale. Note that values order will be ignored - the minimum and maximum values will be swapped if needed. ::SetReversed() should be called to swap displaying order.", py::arg("theMin"), py::arg("theMax"));
cls_AIS_ColorScale.def("HueMin", (Standard_Real (AIS_ColorScale::*)() const) &AIS_ColorScale::HueMin, "Returns the hue angle corresponding to minimum value, 230 by default (blue).");
cls_AIS_ColorScale.def("HueMax", (Standard_Real (AIS_ColorScale::*)() const) &AIS_ColorScale::HueMax, "Returns the hue angle corresponding to maximum value, 0 by default (red).");
cls_AIS_ColorScale.def("HueRange", [](AIS_ColorScale &self, Standard_Real & theMinAngle, Standard_Real & theMaxAngle){ self.HueRange(theMinAngle, theMaxAngle); return std::tuple<Standard_Real &, Standard_Real &>(theMinAngle, theMaxAngle); }, "Returns the hue angle range corresponding to minimum and maximum values, 230 to 0 by default (blue to red).", py::arg("theMinAngle"), py::arg("theMaxAngle"));
cls_AIS_ColorScale.def("SetHueRange", (void (AIS_ColorScale::*)(const Standard_Real, const Standard_Real)) &AIS_ColorScale::SetHueRange, "Sets hue angle range corresponding to minimum and maximum values. The valid angle range is [0, 360], see Quantity_Color and Quantity_TOC_HLS for more details.", py::arg("theMinAngle"), py::arg("theMaxAngle"));
cls_AIS_ColorScale.def("ColorRange", (void (AIS_ColorScale::*)(Quantity_Color &, Quantity_Color &) const) &AIS_ColorScale::ColorRange, "Returns color range corresponding to minimum and maximum values, blue to red by default.", py::arg("theMinColor"), py::arg("theMaxColor"));
cls_AIS_ColorScale.def("SetColorRange", (void (AIS_ColorScale::*)(const Quantity_Color &, const Quantity_Color &)) &AIS_ColorScale::SetColorRange, "Sets color range corresponding to minimum and maximum values.", py::arg("theMinColor"), py::arg("theMaxColor"));
cls_AIS_ColorScale.def("GetLabelType", (Aspect_TypeOfColorScaleData (AIS_ColorScale::*)() const) &AIS_ColorScale::GetLabelType, "Returns the type of labels, Aspect_TOCSD_AUTO by default. Aspect_TOCSD_AUTO - labels as boundary values for intervals Aspect_TOCSD_USER - user specified label is used");
cls_AIS_ColorScale.def("SetLabelType", (void (AIS_ColorScale::*)(const Aspect_TypeOfColorScaleData)) &AIS_ColorScale::SetLabelType, "Sets the type of labels. Aspect_TOCSD_AUTO - labels as boundary values for intervals Aspect_TOCSD_USER - user specified label is used", py::arg("theType"));
cls_AIS_ColorScale.def("GetColorType", (Aspect_TypeOfColorScaleData (AIS_ColorScale::*)() const) &AIS_ColorScale::GetColorType, "Returns the type of colors, Aspect_TOCSD_AUTO by default. Aspect_TOCSD_AUTO - value between Red and Blue Aspect_TOCSD_USER - user specified color from color map");
cls_AIS_ColorScale.def("SetColorType", (void (AIS_ColorScale::*)(const Aspect_TypeOfColorScaleData)) &AIS_ColorScale::SetColorType, "Sets the type of colors. Aspect_TOCSD_AUTO - value between Red and Blue Aspect_TOCSD_USER - user specified color from color map", py::arg("theType"));
cls_AIS_ColorScale.def("GetNumberOfIntervals", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetNumberOfIntervals, "Returns the number of color scale intervals, 10 by default.");
cls_AIS_ColorScale.def("SetNumberOfIntervals", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetNumberOfIntervals, "Sets the number of color scale intervals.", py::arg("theNum"));
cls_AIS_ColorScale.def("GetTitle", (const TCollection_ExtendedString & (AIS_ColorScale::*)() const) &AIS_ColorScale::GetTitle, "Returns the color scale title string, empty string by default.");
cls_AIS_ColorScale.def("SetTitle", (void (AIS_ColorScale::*)(const TCollection_ExtendedString &)) &AIS_ColorScale::SetTitle, "Sets the color scale title string.", py::arg("theTitle"));
cls_AIS_ColorScale.def("GetFormat", (const TCollection_AsciiString & (AIS_ColorScale::*)() const) &AIS_ColorScale::GetFormat, "Returns the format for numbers, '%.4g' by default. The same like format for function printf(). Used if GetLabelType() is TOCSD_AUTO;");
cls_AIS_ColorScale.def("Format", (const TCollection_AsciiString & (AIS_ColorScale::*)() const) &AIS_ColorScale::Format, "Returns the format of text.");
cls_AIS_ColorScale.def("SetFormat", (void (AIS_ColorScale::*)(const TCollection_AsciiString &)) &AIS_ColorScale::SetFormat, "Sets the color scale auto label format specification.", py::arg("theFormat"));
cls_AIS_ColorScale.def("GetLabel", (TCollection_ExtendedString (AIS_ColorScale::*)(const Standard_Integer) const) &AIS_ColorScale::GetLabel, "Returns the user specified label with index theIndex. Index is in range from 1 to GetNumberOfIntervals() or to GetNumberOfIntervals() + 1 if IsLabelAtBorder() is true. Returns empty string if label not defined.", py::arg("theIndex"));
cls_AIS_ColorScale.def("GetIntervalColor", (Quantity_Color (AIS_ColorScale::*)(const Standard_Integer) const) &AIS_ColorScale::GetIntervalColor, "Returns the user specified color from color map with index (starts at 1). Returns default color if index is out of range in color map.", py::arg("theIndex"));
cls_AIS_ColorScale.def("SetIntervalColor", (void (AIS_ColorScale::*)(const Quantity_Color &, const Standard_Integer)) &AIS_ColorScale::SetIntervalColor, "Sets the color of the specified interval. Note that list is automatically resized to include specified index.", py::arg("theColor"), py::arg("theIndex"));
cls_AIS_ColorScale.def("GetLabels", (void (AIS_ColorScale::*)(TColStd_SequenceOfExtendedString &) const) &AIS_ColorScale::GetLabels, "Returns the user specified labels.", py::arg("theLabels"));
cls_AIS_ColorScale.def("Labels", (const TColStd_SequenceOfExtendedString & (AIS_ColorScale::*)() const) &AIS_ColorScale::Labels, "Returns the user specified labels.");
cls_AIS_ColorScale.def("SetLabels", (void (AIS_ColorScale::*)(const TColStd_SequenceOfExtendedString &)) &AIS_ColorScale::SetLabels, "Sets the color scale labels. The length of the sequence should be equal to GetNumberOfIntervals() or to GetNumberOfIntervals() + 1 if IsLabelAtBorder() is true. If length of the sequence does not much the number of intervals, then these labels will be considered as 'free' and will be located at the virtual intervals corresponding to the number of labels (with flag IsLabelAtBorder() having the same effect as in normal case).", py::arg("theSeq"));
cls_AIS_ColorScale.def("GetColors", (void (AIS_ColorScale::*)(Aspect_SequenceOfColor &) const) &AIS_ColorScale::GetColors, "Returns the user specified colors.", py::arg("theColors"));
cls_AIS_ColorScale.def("GetColors", (const Aspect_SequenceOfColor & (AIS_ColorScale::*)() const) &AIS_ColorScale::GetColors, "Returns the user specified colors.");
cls_AIS_ColorScale.def("SetColors", (void (AIS_ColorScale::*)(const Aspect_SequenceOfColor &)) &AIS_ColorScale::SetColors, "Sets the color scale colors. The length of the sequence should be equal to GetNumberOfIntervals().", py::arg("theSeq"));
cls_AIS_ColorScale.def("GetLabelPosition", (Aspect_TypeOfColorScalePosition (AIS_ColorScale::*)() const) &AIS_ColorScale::GetLabelPosition, "Returns the position of labels concerning color filled rectangles, Aspect_TOCSP_RIGHT by default.");
cls_AIS_ColorScale.def("SetLabelPosition", (void (AIS_ColorScale::*)(const Aspect_TypeOfColorScalePosition)) &AIS_ColorScale::SetLabelPosition, "Sets the color scale labels position relative to color bar.", py::arg("thePos"));
cls_AIS_ColorScale.def("GetTitlePosition", (Aspect_TypeOfColorScalePosition (AIS_ColorScale::*)() const) &AIS_ColorScale::GetTitlePosition, "Returns the position of color scale title, Aspect_TOCSP_LEFT by default.");
cls_AIS_ColorScale.def("SetTitlePosition", (void (AIS_ColorScale::*)(const Aspect_TypeOfColorScalePosition)) &AIS_ColorScale::SetTitlePosition, "Sets the color scale title position.", py::arg("thePos"));
cls_AIS_ColorScale.def("IsReversed", (Standard_Boolean (AIS_ColorScale::*)() const) &AIS_ColorScale::IsReversed, "Returns TRUE if the labels and colors used in reversed order, FALSE by default. - Normal, bottom-up order with Minimal value on the Bottom and Maximum value on Top. - Reversed, top-down order with Maximum value on the Bottom and Minimum value on Top.");
cls_AIS_ColorScale.def("SetReversed", (void (AIS_ColorScale::*)(const Standard_Boolean)) &AIS_ColorScale::SetReversed, "Sets true if the labels and colors used in reversed order.", py::arg("theReverse"));
cls_AIS_ColorScale.def("IsSmoothTransition", (Standard_Boolean (AIS_ColorScale::*)() const) &AIS_ColorScale::IsSmoothTransition, "Return TRUE if color transition between neighbor intervals should be linearly interpolated, FALSE by default.");
cls_AIS_ColorScale.def("SetSmoothTransition", (void (AIS_ColorScale::*)(const Standard_Boolean)) &AIS_ColorScale::SetSmoothTransition, "Setup smooth color transition.", py::arg("theIsSmooth"));
cls_AIS_ColorScale.def("IsLabelAtBorder", (Standard_Boolean (AIS_ColorScale::*)() const) &AIS_ColorScale::IsLabelAtBorder, "Returns TRUE if the labels are placed at border of color intervals, TRUE by default. The automatically generated label will show value exactly on the current position: - value connecting two neighbor intervals (TRUE) - value in the middle of interval (FALSE)");
cls_AIS_ColorScale.def("SetLabelAtBorder", (void (AIS_ColorScale::*)(const Standard_Boolean)) &AIS_ColorScale::SetLabelAtBorder, "Sets true if the labels are placed at border of color intervals (TRUE by default). If set to False, labels will be drawn at color intervals rather than at borders.", py::arg("theOn"));
cls_AIS_ColorScale.def("IsLogarithmic", (Standard_Boolean (AIS_ColorScale::*)() const) &AIS_ColorScale::IsLogarithmic, "Returns TRUE if the color scale has logarithmic intervals, FALSE by default.");
cls_AIS_ColorScale.def("SetLogarithmic", (void (AIS_ColorScale::*)(const Standard_Boolean)) &AIS_ColorScale::SetLogarithmic, "Sets true if the color scale has logarithmic intervals.", py::arg("isLogarithmic"));
cls_AIS_ColorScale.def("SetLabel", (void (AIS_ColorScale::*)(const TCollection_ExtendedString &, const Standard_Integer)) &AIS_ColorScale::SetLabel, "Sets the color scale label at index. Note that list is automatically resized to include specified index.", py::arg("theLabel"), py::arg("theIndex"));
cls_AIS_ColorScale.def("GetSize", [](AIS_ColorScale &self, Standard_Integer & theBreadth, Standard_Integer & theHeight){ self.GetSize(theBreadth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theBreadth, theHeight); }, "Returns the size of color bar, 0 and 0 by default (e.g. should be set by user explicitly before displaying).", py::arg("theBreadth"), py::arg("theHeight"));
cls_AIS_ColorScale.def("SetSize", (void (AIS_ColorScale::*)(const Standard_Integer, const Standard_Integer)) &AIS_ColorScale::SetSize, "Sets the size of color bar.", py::arg("theBreadth"), py::arg("theHeight"));
cls_AIS_ColorScale.def("GetBreadth", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetBreadth, "Returns the breadth of color bar, 0 by default (e.g. should be set by user explicitly before displaying).");
cls_AIS_ColorScale.def("SetBreadth", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetBreadth, "Sets the width of color bar.", py::arg("theBreadth"));
cls_AIS_ColorScale.def("GetHeight", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetHeight, "Returns the height of color bar, 0 by default (e.g. should be set by user explicitly before displaying).");
cls_AIS_ColorScale.def("SetHeight", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetHeight, "Sets the height of color bar.", py::arg("theHeight"));
cls_AIS_ColorScale.def("GetPosition", [](AIS_ColorScale &self, Standard_Real & theX, Standard_Real & theY){ self.GetPosition(theX, theY); return std::tuple<Standard_Real &, Standard_Real &>(theX, theY); }, "Returns the bottom-left position of color scale, 0x0 by default.", py::arg("theX"), py::arg("theY"));
cls_AIS_ColorScale.def("SetPosition", (void (AIS_ColorScale::*)(const Standard_Integer, const Standard_Integer)) &AIS_ColorScale::SetPosition, "Sets the position of color scale.", py::arg("theX"), py::arg("theY"));
cls_AIS_ColorScale.def("GetXPosition", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetXPosition, "Returns the left position of color scale, 0 by default.");
cls_AIS_ColorScale.def("SetXPosition", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetXPosition, "Sets the left position of color scale.", py::arg("theX"));
cls_AIS_ColorScale.def("GetYPosition", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetYPosition, "Returns the bottom position of color scale, 0 by default.");
cls_AIS_ColorScale.def("SetYPosition", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetYPosition, "Sets the bottom position of color scale.", py::arg("theY"));
cls_AIS_ColorScale.def("GetTextHeight", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetTextHeight, "Returns the font height of text labels, 20 by default.");
cls_AIS_ColorScale.def("SetTextHeight", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetTextHeight, "Sets the height of text of color scale.", py::arg("theHeight"));
cls_AIS_ColorScale.def("TextWidth", (Standard_Integer (AIS_ColorScale::*)(const TCollection_ExtendedString &) const) &AIS_ColorScale::TextWidth, "Returns the width of text.", py::arg("theText"));
cls_AIS_ColorScale.def("TextHeight", (Standard_Integer (AIS_ColorScale::*)(const TCollection_ExtendedString &) const) &AIS_ColorScale::TextHeight, "Returns the height of text.", py::arg("theText"));
cls_AIS_ColorScale.def("TextSize", [](AIS_ColorScale &self, const TCollection_ExtendedString & theText, const Standard_Integer theHeight, Standard_Integer & theWidth, Standard_Integer & theAscent, Standard_Integer & theDescent){ self.TextSize(theText, theHeight, theWidth, theAscent, theDescent); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(theWidth, theAscent, theDescent); }, "None", py::arg("theText"), py::arg("theHeight"), py::arg("theWidth"), py::arg("theAscent"), py::arg("theDescent"));
cls_AIS_ColorScale.def("AcceptDisplayMode", (Standard_Boolean (AIS_ColorScale::*)(const Standard_Integer) const) &AIS_ColorScale::AcceptDisplayMode, "Return true if specified display mode is supported.", py::arg("theMode"));
cls_AIS_ColorScale.def("Compute", (void (AIS_ColorScale::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &AIS_ColorScale::Compute, "Compute presentation.", py::arg("thePresentationManager"), py::arg("thePresentation"), py::arg("theMode"));
cls_AIS_ColorScale.def("ComputeSelection", (void (AIS_ColorScale::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &AIS_ColorScale::ComputeSelection, "Compute selection - not implemented for color scale.", py::arg(""), py::arg(""));

// Enums

}