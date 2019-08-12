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
#include <Font_FTFont.hxx>
#include <NCollection_String.hxx>
#include <Standard_TypeDef.hxx>
#include <Font_FontAspect.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Mutex.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Curve.hxx>
#include <NCollection_DataMap.hxx>
#include <Geom_Surface.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <Geom2dAdaptor_HCurve.hxx>
#include <Geom2dConvert_CompCurveToBSplineCurve.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <BRep_Builder.hxx>
#include <ShapeFix_Face.hxx>
#include <Font_BRepFont.hxx>
#include <Standard_Type.hxx>

void bind_Font_BRepFont(py::module &mod){

/*
py::class_<Font_BRepFont, opencascade::handle<Font_BRepFont>> cls_Font_BRepFont(mod, "Font_BRepFont", "This tool provides basic services for rendering of vectorized text glyphs as BRep shapes. Single instance initialize single font for sequential glyphs rendering with implicit caching of already rendered glyphs. Thus position of each glyph in the text is specified by shape location.");

// Constructors
cls_Font_BRepFont.def(py::init<>());
cls_Font_BRepFont.def(py::init<const NCollection_String &, const Standard_Real>(), py::arg("theFontPath"), py::arg("theSize"));
cls_Font_BRepFont.def(py::init<const NCollection_String &, const Font_FontAspect, const Standard_Real>(), py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theSize"));

// Fields

// Methods
cls_Font_BRepFont.def("Release", (void (Font_BRepFont::*)()) &Font_BRepFont::Release, "Release currently loaded font.");
cls_Font_BRepFont.def("Init", (bool (Font_BRepFont::*)(const NCollection_String &, const Standard_Real)) &Font_BRepFont::Init, "Initialize the font.", py::arg("theFontPath"), py::arg("theSize"));
cls_Font_BRepFont.def("Init", (bool (Font_BRepFont::*)(const NCollection_String &, const Font_FontAspect, const Standard_Real)) &Font_BRepFont::Init, "Initialize the font. Please take into account that size is specified NOT in typography points (pt.). If you need to specify size in points, value should be converted. Formula for pt. -> m conversion: aSizeMeters = 0.0254 * theSizePt / 72.0", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theSize"));
cls_Font_BRepFont.def("RenderGlyph", (TopoDS_Shape (Font_BRepFont::*)(const Standard_Utf32Char &)) &Font_BRepFont::RenderGlyph, "Render single glyph as TopoDS_Shape.", py::arg("theChar"));
cls_Font_BRepFont.def("SetCompositeCurveMode", (void (Font_BRepFont::*)(const Standard_Boolean)) &Font_BRepFont::SetCompositeCurveMode, "Setup glyph geometry construction mode. By default algorithm creates independent TopoDS_Edge for each original curve in the glyph (line segment or Bezie curve). Algorithm might optionally create composite BSpline curve for each contour which reduces memory footprint but limits curve class to C0. Notice that altering this flag clears currently accumulated cache!", py::arg("theToConcatenate"));
cls_Font_BRepFont.def("SetWidthScaling", (void (Font_BRepFont::*)(const float)) &Font_BRepFont::SetWidthScaling, "Setup glyph scaling along X-axis. By default glyphs are not scaled (scaling factor = 1.0)", py::arg("theScaleFactor"));
cls_Font_BRepFont.def("Ascender", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::Ascender, "Returns vertical distance from the horizontal baseline to the highest character coordinate.");
cls_Font_BRepFont.def("Descender", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::Descender, "Returns vertical distance from the horizontal baseline to the lowest character coordinate.");
cls_Font_BRepFont.def("LineSpacing", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::LineSpacing, "Returns default line spacing (the baseline-to-baseline distance).");
cls_Font_BRepFont.def("PointSize", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::PointSize, "Configured point size");
cls_Font_BRepFont.def("AdvanceX", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char)) &Font_BRepFont::AdvanceX, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUCharNext"));
cls_Font_BRepFont.def("AdvanceX", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char, const Standard_Utf32Char)) &Font_BRepFont::AdvanceX, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_BRepFont.def("AdvanceY", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char)) &Font_BRepFont::AdvanceY, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUCharNext"));
cls_Font_BRepFont.def("AdvanceY", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char, const Standard_Utf32Char)) &Font_BRepFont::AdvanceY, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_BRepFont.def("Scale", (Standard_Real (Font_BRepFont::*)() const) &Font_BRepFont::Scale, "Returns scaling factor for current font size.");
cls_Font_BRepFont.def("Mutex", (Standard_Mutex & (Font_BRepFont::*)()) &Font_BRepFont::Mutex, "Returns mutex.");
cls_Font_BRepFont.def_static("get_type_name_", (const char * (*)()) &Font_BRepFont::get_type_name, "None");
cls_Font_BRepFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_BRepFont::get_type_descriptor, "None");
cls_Font_BRepFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_BRepFont::*)() const) &Font_BRepFont::DynamicType, "None");

// Enums
*/

}