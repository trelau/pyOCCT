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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <gp_Pnt.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESDimen_NewGeneralNote.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_NewGeneralNote(py::module &mod){

py::class_<IGESDimen_NewGeneralNote, opencascade::handle<IGESDimen_NewGeneralNote>, IGESData_IGESEntity> cls_IGESDimen_NewGeneralNote(mod, "IGESDimen_NewGeneralNote", "defines NewGeneralNote, Type <213> Form <0> in package IGESDimen Further attributes for formatting text strings");

// Constructors
cls_IGESDimen_NewGeneralNote.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_NewGeneralNote.def("Init", (void (IGESDimen_NewGeneralNote::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const gp_XYZ &, const Standard_Real, const gp_XYZ &, const Standard_Real, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColgp_HArray1OfXYZ> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &IGESDimen_NewGeneralNote::Init, "This method is used to set the fields of the class NewGeneralNote - width : Width of text containment area - height : Height of text containment area - justifyCode : Justification code - areaLoc : Text containment area location - areaRotationAngle : Text containment area rotation - baseLinePos : Base line position - normalInterlineSpace : Normal interline spacing - charDisplays : Character display type - charWidths : Character width - charHeights : Character height - interCharSpc : Intercharacter spacing - interLineSpc : Interline spacing - fontStyles : Font style - charAngles : Character angle - controlCodeStrings : Control Code string - nbChars : Number of characters in string - boxWidths : Box width - boxHeights : Box height - charSetCodes : Character Set Interpretation - charSetEntities : Character Set Font - slAngles : Slant angle of text in radians - rotAngles : Rotation angle of text in radians - mirrorFlags : Type of mirroring - rotateFlags : Rotate internal text flag - startPoints : Text start point - texts : Text strings raises exception if there is mismatch between the various Array Lengths.", py::arg("width"), py::arg("height"), py::arg("justifyCode"), py::arg("areaLoc"), py::arg("areaRotationAngle"), py::arg("baseLinePos"), py::arg("normalInterlineSpace"), py::arg("charDisplays"), py::arg("charWidths"), py::arg("charHeights"), py::arg("interCharSpc"), py::arg("interLineSpc"), py::arg("fontStyles"), py::arg("charAngles"), py::arg("controlCodeStrings"), py::arg("nbChars"), py::arg("boxWidths"), py::arg("boxHeights"), py::arg("charSetCodes"), py::arg("charSetEntities"), py::arg("slAngles"), py::arg("rotAngles"), py::arg("mirrorFlags"), py::arg("rotateFlags"), py::arg("startPoints"), py::arg("texts"));
cls_IGESDimen_NewGeneralNote.def("TextWidth", (Standard_Real (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::TextWidth, "returns width of text containment area of all strings in the note");
cls_IGESDimen_NewGeneralNote.def("TextHeight", (Standard_Real (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::TextHeight, "returns height of text containment area of all strings in the note");
cls_IGESDimen_NewGeneralNote.def("JustifyCode", (Standard_Integer (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::JustifyCode, "returns Justification code of all strings within the note 0 = no justification 1 = right justified 2 = center justified 3 = left justified");
cls_IGESDimen_NewGeneralNote.def("AreaLocation", (gp_Pnt (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::AreaLocation, "returns Text containment area Location point");
cls_IGESDimen_NewGeneralNote.def("TransformedAreaLocation", (gp_Pnt (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::TransformedAreaLocation, "returns Text containment area Location point after Transformation");
cls_IGESDimen_NewGeneralNote.def("ZDepthAreaLocation", (Standard_Real (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::ZDepthAreaLocation, "returns distance from the containment area plane");
cls_IGESDimen_NewGeneralNote.def("AreaRotationAngle", (Standard_Real (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::AreaRotationAngle, "returns rotation angle of text containment area in radians");
cls_IGESDimen_NewGeneralNote.def("BaseLinePosition", (gp_Pnt (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::BaseLinePosition, "returns position of first base line");
cls_IGESDimen_NewGeneralNote.def("TransformedBaseLinePosition", (gp_Pnt (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::TransformedBaseLinePosition, "returns position of first base line after Transformation");
cls_IGESDimen_NewGeneralNote.def("ZDepthBaseLinePosition", (Standard_Real (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::ZDepthBaseLinePosition, "returns distance from the Base line position plane");
cls_IGESDimen_NewGeneralNote.def("NormalInterlineSpace", (Standard_Real (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::NormalInterlineSpace, "returns Normal Interline Spacing");
cls_IGESDimen_NewGeneralNote.def("NbStrings", (Standard_Integer (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::NbStrings, "returns number of text HAsciiStrings");
cls_IGESDimen_NewGeneralNote.def("CharacterDisplay", (Standard_Integer (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::CharacterDisplay, "returns Fixed/Variable width character display of string 0 = Fixed 1 = Variable raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("IsVariable", (Standard_Boolean (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::IsVariable, "returns False if Character display width is Fixed optional method, if required raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("CharacterWidth", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::CharacterWidth, "returns Character Width of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("CharacterHeight", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::CharacterHeight, "returns Character Height of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("InterCharacterSpace", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::InterCharacterSpace, "returns Inter-character spacing of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("InterlineSpace", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::InterlineSpace, "returns Interline spacing of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("FontStyle", (Standard_Integer (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::FontStyle, "returns FontStyle of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("CharacterAngle", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::CharacterAngle, "returns CharacterAngle of string Angle returned will be between 0 and 2PI raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("ControlCodeString", (opencascade::handle<TCollection_HAsciiString> (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::ControlCodeString, "returns ControlCodeString of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("NbCharacters", (Standard_Integer (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::NbCharacters, "returns number of characters in string or zero raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("BoxWidth", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::BoxWidth, "returns Box width of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("BoxHeight", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::BoxHeight, "returns Box height of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("IsCharSetEntity", (Standard_Boolean (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::IsCharSetEntity, "returns False if Value, True if Pointer (Entity) raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("CharSetCode", (Standard_Integer (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::CharSetCode, "returns Character Set Interpretation (default = 1) of string returns 0 if IsCharSetEntity () is True 1 = Standard ASCII 1001 = Symbol Font1 1002 = Symbol Font2 1003 = Symbol Font3 raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("CharSetEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::CharSetEntity, "returns Character Set Interpretation of string returns a Null Handle if IsCharSetEntity () is False raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("SlantAngle", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::SlantAngle, "returns Slant angle of string in radians default value = PI/2 raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("RotationAngle", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::RotationAngle, "returns Rotation angle of string in radians raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("MirrorFlag", (Standard_Integer (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::MirrorFlag, "returns Mirror Flag of string 0 = no mirroring 1 = mirror axis is perpendicular to the text base line 2 = mirror axis is text base line raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("IsMirrored", (Standard_Boolean (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::IsMirrored, "returns False if MirrorFlag = 0. ie. no mirroring else returns True raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("RotateFlag", (Standard_Integer (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::RotateFlag, "returns Rotate internal text Flag of string 0 = text horizontal 1 = text vertical raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("StartPoint", (gp_Pnt (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::StartPoint, "returns text start point of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("TransformedStartPoint", (gp_Pnt (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::TransformedStartPoint, "returns text start point of string after Transformation raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("ZDepthStartPoint", (Standard_Real (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::ZDepthStartPoint, "returns distance from the start point plane raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def("Text", (opencascade::handle<TCollection_HAsciiString> (IGESDimen_NewGeneralNote::*)(const Standard_Integer) const) &IGESDimen_NewGeneralNote::Text, "returns text string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_NewGeneralNote.def_static("get_type_name_", (const char * (*)()) &IGESDimen_NewGeneralNote::get_type_name, "None");
cls_IGESDimen_NewGeneralNote.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_NewGeneralNote::get_type_descriptor, "None");
cls_IGESDimen_NewGeneralNote.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_NewGeneralNote::*)() const) &IGESDimen_NewGeneralNote::DynamicType, "None");

// Enums

}