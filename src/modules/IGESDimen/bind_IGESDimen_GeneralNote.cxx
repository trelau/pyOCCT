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
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <IGESGraph_HArray1OfTextFontDef.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGraph_TextFontDef.hxx>
#include <gp_Pnt.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_GeneralNote(py::module &mod){

py::class_<IGESDimen_GeneralNote, opencascade::handle<IGESDimen_GeneralNote>, IGESData_IGESEntity> cls_IGESDimen_GeneralNote(mod, "IGESDimen_GeneralNote", "defines GeneralNote, Type <212> Form <0-8, 100-200, 105> in package IGESDimen Used for formatting boxed text in different ways");

// Constructors
cls_IGESDimen_GeneralNote.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_GeneralNote.def("Init", (void (IGESDimen_GeneralNote::*)(const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESGraph_HArray1OfTextFontDef> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColgp_HArray1OfXYZ> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &IGESDimen_GeneralNote::Init, "This method is used to set the fields of the class GeneralNote - nNbChars : number of chars strings - widths : Box widths - heights : Box heights - fontCodes : Font codes, default = 1 - fonts : Text Font Definition Entities - slants : Slant angles in radians - rotations : Rotation angles in radians - mirrorFlags : Mirror flags - rotFlags : Rotation internal text flags - start : Text start points - texts : Text strings raises exception if there is mismatch between the various Array Lengths.", py::arg("nbChars"), py::arg("widths"), py::arg("heights"), py::arg("fontCodes"), py::arg("fonts"), py::arg("slants"), py::arg("rotations"), py::arg("mirrorFlags"), py::arg("rotFlags"), py::arg("start"), py::arg("texts"));
cls_IGESDimen_GeneralNote.def("SetFormNumber", (void (IGESDimen_GeneralNote::*)(const Standard_Integer)) &IGESDimen_GeneralNote::SetFormNumber, "Changes FormNumber (indicates Graphical Representation) Error if not in ranges [0-8] or [100-102] or 105", py::arg("form"));
cls_IGESDimen_GeneralNote.def("NbStrings", (Standard_Integer (IGESDimen_GeneralNote::*)() const) &IGESDimen_GeneralNote::NbStrings, "returns number of text strings in General Note");
cls_IGESDimen_GeneralNote.def("NbCharacters", (Standard_Integer (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::NbCharacters, "returns number of characters of string or zero raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("BoxWidth", (Standard_Real (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::BoxWidth, "returns Box width of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("BoxHeight", (Standard_Real (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::BoxHeight, "returns Box height of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("IsFontEntity", (Standard_Boolean (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::IsFontEntity, "returns False if Value, True if Entity raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("FontCode", (Standard_Integer (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::FontCode, "returns Font code (default = 1) of string returns 0 if IsFontEntity () is True raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("FontEntity", (opencascade::handle<IGESGraph_TextFontDef> (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::FontEntity, "returns Text Font Definition Entity of string returns a Null Handle if IsFontEntity () returns False raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("SlantAngle", (Standard_Real (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::SlantAngle, "returns Slant angle of string in radians default value = PI/2 raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("RotationAngle", (Standard_Real (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::RotationAngle, "returns Rotation angle of string in radians raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("MirrorFlag", (Standard_Integer (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::MirrorFlag, "returns Mirror Flag of string 0 = no mirroring 1 = mirror axis is perpendicular to the text base line 2 = mirror axis is text base line raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("RotateFlag", (Standard_Integer (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::RotateFlag, "returns Rotate internal text Flag of string 0 = text horizontal 1 = text vertical raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("StartPoint", (gp_Pnt (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::StartPoint, "returns text start point of Index'th string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("TransformedStartPoint", (gp_Pnt (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::TransformedStartPoint, "returns text start point of Index'th string after Transformation raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("ZDepthStartPoint", (Standard_Real (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::ZDepthStartPoint, "returns distance from Start Point plane of string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def("Text", (opencascade::handle<TCollection_HAsciiString> (IGESDimen_GeneralNote::*)(const Standard_Integer) const) &IGESDimen_GeneralNote::Text, "returns text string raises exception if Index <= 0 or Index > NbStrings()", py::arg("Index"));
cls_IGESDimen_GeneralNote.def_static("get_type_name_", (const char * (*)()) &IGESDimen_GeneralNote::get_type_name, "None");
cls_IGESDimen_GeneralNote.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_GeneralNote::get_type_descriptor, "None");
cls_IGESDimen_GeneralNote.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_GeneralNote::*)() const) &IGESDimen_GeneralNote::DynamicType, "None");

// Enums

}