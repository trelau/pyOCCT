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
#include <TopoDS_Shape.hxx>
#include <Font_BRepFont.hxx>
#include <Font_TextFormatter.hxx>
#include <gp_Ax3.hxx>
#include <NCollection_String.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <BRep_Builder.hxx>
#include <Font_BRepTextBuilder.hxx>

void bind_Font_BRepTextBuilder(py::module &mod){

py::class_<Font_BRepTextBuilder, std::unique_ptr<Font_BRepTextBuilder>> cls_Font_BRepTextBuilder(mod, "Font_BRepTextBuilder", "Represents class for applying text formatting.");

// Constructors

// Fields

// Methods
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const Font_TextFormatter & a1) -> TopoDS_Shape { return self.Perform(a0, a1); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", (TopoDS_Shape (Font_BRepTextBuilder::*)(Font_BRepFont &, const Font_TextFormatter &, const gp_Ax3 &)) &Font_BRepTextBuilder::Perform, "Render text as BRep shape.", py::arg("theFont"), py::arg("theFormatter"), py::arg("thePenLoc"), py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1) -> TopoDS_Shape { return self.Perform(a0, a1); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1, const gp_Ax3 & a2) -> TopoDS_Shape { return self.Perform(a0, a1, a2); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1, const gp_Ax3 & a2, const Graphic3d_HorizontalTextAlignment a3) -> TopoDS_Shape { return self.Perform(a0, a1, a2, a3); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", (TopoDS_Shape (Font_BRepTextBuilder::*)(Font_BRepFont &, const NCollection_String &, const gp_Ax3 &, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_BRepTextBuilder::Perform, "Render text as BRep shape.", py::arg("theFont"), py::arg("theString"), py::arg("thePenLoc"), py::arg("theHAlign"), py::arg("theVAlign"), py::call_guard<ImportGraphic3d>());

// Enums

}