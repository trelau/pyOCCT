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
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESGraph_TextFontDef.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfInteger.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_TextFontDef(py::module &mod){

py::class_<IGESGraph_TextFontDef, opencascade::handle<IGESGraph_TextFontDef>, IGESData_IGESEntity> cls_IGESGraph_TextFontDef(mod, "IGESGraph_TextFontDef", "defines IGES Text Font Definition Entity, Type <310> in package IGESGraph");

// Constructors
cls_IGESGraph_TextFontDef.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_TextFontDef.def("Init", (void (IGESGraph_TextFontDef::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<IGESGraph_TextFontDef> &, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &)) &IGESGraph_TextFontDef::Init, "This method is used to set the fields of the class TextFontDef - aFontCode : Font Code - aFontName : Font Name - aSupersededFont : Number of superseded font - aSupersededEntity : Text Definition Entity - aScale : No. of grid units = 1 text height unit - allASCIICodes : ASCII codes for characters - allNextCharX & Y : Grid locations of the next character's origin (Integer vals) - allPenMotions : No. of pen motions for the characters - allPenFlags : Pen up/down flags, 0 = Down (default), 1 = Up - allMovePenToX & Y : Grid locations the pen will move to This method initializes the fields of the class TextFontDef. An exception is raised if the lengths of allASCIICodes, allNextChars, allPenMotions, allPenFlags and allMovePenTo are not same.", py::arg("aFontCode"), py::arg("aFontName"), py::arg("aSupersededFont"), py::arg("aSupersededEntity"), py::arg("aScale"), py::arg("allASCIICodes"), py::arg("allNextCharX"), py::arg("allNextCharY"), py::arg("allPenMotions"), py::arg("allPenFlags"), py::arg("allMovePenToX"), py::arg("allMovePenToY"));
cls_IGESGraph_TextFontDef.def("FontCode", (Standard_Integer (IGESGraph_TextFontDef::*)() const) &IGESGraph_TextFontDef::FontCode, "returns the font code.");
cls_IGESGraph_TextFontDef.def("FontName", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_TextFontDef::*)() const) &IGESGraph_TextFontDef::FontName, "returns the font name.");
cls_IGESGraph_TextFontDef.def("IsSupersededFontEntity", (Standard_Boolean (IGESGraph_TextFontDef::*)() const) &IGESGraph_TextFontDef::IsSupersededFontEntity, "True if this definition supersedes another TextFontDefinition Entity, False if it supersedes value.");
cls_IGESGraph_TextFontDef.def("SupersededFontCode", (Standard_Integer (IGESGraph_TextFontDef::*)() const) &IGESGraph_TextFontDef::SupersededFontCode, "returns the font number which this entity modifies.");
cls_IGESGraph_TextFontDef.def("SupersededFontEntity", (opencascade::handle<IGESGraph_TextFontDef> (IGESGraph_TextFontDef::*)() const) &IGESGraph_TextFontDef::SupersededFontEntity, "returns the font entity which this entity modifies.");
cls_IGESGraph_TextFontDef.def("Scale", (Standard_Integer (IGESGraph_TextFontDef::*)() const) &IGESGraph_TextFontDef::Scale, "returns the number of grid units which equal one text height unit.");
cls_IGESGraph_TextFontDef.def("NbCharacters", (Standard_Integer (IGESGraph_TextFontDef::*)() const) &IGESGraph_TextFontDef::NbCharacters, "returns the number of characters in this definition.");
cls_IGESGraph_TextFontDef.def("ASCIICode", (Standard_Integer (IGESGraph_TextFontDef::*)(const Standard_Integer) const) &IGESGraph_TextFontDef::ASCIICode, "returns the ASCII code of Chnum'th character. Exception OutOfRange is raised if Chnum <= 0 or Chnum > NbCharacters", py::arg("Chnum"));
cls_IGESGraph_TextFontDef.def("NextCharOrigin", [](IGESGraph_TextFontDef &self, const Standard_Integer Chnum, Standard_Integer & NX, Standard_Integer & NY){ self.NextCharOrigin(Chnum, NX, NY); return std::tuple<Standard_Integer &, Standard_Integer &>(NX, NY); }, "returns grid location of origin of character next to Chnum'th char. Exception OutOfRange is raised if Chnum <= 0 or Chnum > NbCharacters", py::arg("Chnum"), py::arg("NX"), py::arg("NY"));
cls_IGESGraph_TextFontDef.def("NbPenMotions", (Standard_Integer (IGESGraph_TextFontDef::*)(const Standard_Integer) const) &IGESGraph_TextFontDef::NbPenMotions, "returns number of pen motions for Chnum'th character. Exception OutOfRange is raised if Chnum <= 0 or Chnum > NbCharacters", py::arg("Chnum"));
cls_IGESGraph_TextFontDef.def("IsPenUp", (Standard_Boolean (IGESGraph_TextFontDef::*)(const Standard_Integer, const Standard_Integer) const) &IGESGraph_TextFontDef::IsPenUp, "returns pen status(True if 1, False if 0) of Motionnum'th motion of Chnum'th character. Exception raised if Chnum <= 0 or Chnum > NbCharacters or Motionnum <= 0 or Motionnum > NbPenMotions", py::arg("Chnum"), py::arg("Motionnum"));
cls_IGESGraph_TextFontDef.def("NextPenPosition", [](IGESGraph_TextFontDef &self, const Standard_Integer Chnum, const Standard_Integer Motionnum, Standard_Integer & IX, Standard_Integer & IY){ self.NextPenPosition(Chnum, Motionnum, IX, IY); return std::tuple<Standard_Integer &, Standard_Integer &>(IX, IY); }, "None", py::arg("Chnum"), py::arg("Motionnum"), py::arg("IX"), py::arg("IY"));
cls_IGESGraph_TextFontDef.def_static("get_type_name_", (const char * (*)()) &IGESGraph_TextFontDef::get_type_name, "None");
cls_IGESGraph_TextFontDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_TextFontDef::get_type_descriptor, "None");
cls_IGESGraph_TextFontDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_TextFontDef::*)() const) &IGESGraph_TextFontDef::DynamicType, "None");

// Enums

}