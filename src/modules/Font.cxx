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
#include <Font_FontAspect.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Font_SystemFont.hxx>
#include <Font_NListOfSystemFont.hxx>
#include <NCollection_Vec2.hxx>
#include <Font_Rect.hxx>
#include <Font_FTFont.hxx>
#include <Standard_Transient.hxx>
#include <Font_FTLibrary.hxx>
#include <Image_PixMap.hxx>
#include <NCollection_String.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Vector.hxx>
#include <Font_TextFormatter.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Mutex.hxx>
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
#include <gp_Ax3.hxx>
#include <Font_BRepTextBuilder.hxx>
#include <TCollection_HAsciiString.hxx>
#include <NCollection_List.hxx>
#include <Font_FontMgr.hxx>
#include <TColStd_SequenceOfHAsciiString.hxx>
#include <bind_NCollection_List.hxx>

PYBIND11_MODULE(Font, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Image");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.Geom2dConvert");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.BRep");
py::module::import("OCCT.ShapeFix");
py::module::import("OCCT.gp");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");

struct ImportGraphic3d{
	ImportGraphic3d() { py::module::import("OCCT.Graphic3d"); }
};

// ENUM: FONT_FONTASPECT
py::enum_<Font_FontAspect>(mod, "Font_FontAspect", "Specifies aspect of system font.")
	.value("Font_FA_Undefined", Font_FontAspect::Font_FA_Undefined)
	.value("Font_FA_Regular", Font_FontAspect::Font_FA_Regular)
	.value("Font_FA_Bold", Font_FontAspect::Font_FA_Bold)
	.value("Font_FA_Italic", Font_FontAspect::Font_FA_Italic)
	.value("Font_FA_BoldItalic", Font_FontAspect::Font_FA_BoldItalic)
	.export_values();


// FUNCTION: ISEQUAL
mod.def("IsEqual", (Standard_Boolean (*) (const opencascade::handle<Font_SystemFont> &, const opencascade::handle<Font_SystemFont> &)) &IsEqual, "None", py::arg("theFirstFont"), py::arg("theSecondFont"));

// CLASS: FONT_RECT
py::class_<Font_Rect> cls_Font_Rect(mod, "Font_Rect", "Auxiliary POD structure - 2D rectangle definition.");

// Fields
cls_Font_Rect.def_readwrite("Left", &Font_Rect::Left, "left position");
cls_Font_Rect.def_readwrite("Right", &Font_Rect::Right, "right position");
cls_Font_Rect.def_readwrite("Top", &Font_Rect::Top, "top position");
cls_Font_Rect.def_readwrite("Bottom", &Font_Rect::Bottom, "bottom position");

// Methods
cls_Font_Rect.def("TopLeft", (NCollection_Vec2<float> (Font_Rect::*)() const) &Font_Rect::TopLeft, "Top-left corner as vec2.");
cls_Font_Rect.def("TopLeft", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::TopLeft, "Top-left corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("TopRight", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::TopRight, "Top-right corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("BottomLeft", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::BottomLeft, "Bottom-left corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("BottomRight", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::BottomRight, "Bottom-right corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("Width", (float (Font_Rect::*)() const) &Font_Rect::Width, "Rectangle width.");
cls_Font_Rect.def("Height", (float (Font_Rect::*)() const) &Font_Rect::Height, "Rectangle height.");

// TYPEDEF: FT_FACE

// TYPEDEF: FT_VECTOR

// CLASS: FONT_FTFONT
py::class_<Font_FTFont, opencascade::handle<Font_FTFont>, Standard_Transient> cls_Font_FTFont(mod, "Font_FTFont", "Wrapper over FreeType font. Notice that this class uses internal buffers for loaded glyphs and it is absolutely UNSAFE to load/read glyph from concurrent threads!");

// Constructors
cls_Font_FTFont.def(py::init<>());
cls_Font_FTFont.def(py::init<const opencascade::handle<Font_FTLibrary> &>(), py::arg("theFTLib"));

// Methods
cls_Font_FTFont.def("IsValid", (bool (Font_FTFont::*)() const) &Font_FTFont::IsValid, "Returns true if font is loaded");
cls_Font_FTFont.def("GlyphImage", (const Image_PixMap & (Font_FTFont::*)() const) &Font_FTFont::GlyphImage, "Returns image plane for currently rendered glyph");
cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const NCollection_String &, const unsigned int, const unsigned int)) &Font_FTFont::Init, "Initialize the font.", py::arg("theFontPath"), py::arg("thePointSize"), py::arg("theResolution"));
cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const NCollection_String &, const Font_FontAspect, const unsigned int, const unsigned int)) &Font_FTFont::Init, "Initialize the font.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("thePointSize"), py::arg("theResolution"));
cls_Font_FTFont.def("IsSingleStrokeFont", (bool (Font_FTFont::*)() const) &Font_FTFont::IsSingleStrokeFont, "Return TRUE if this is single-stroke (one-line) font, FALSE by default. Such fonts define single-line glyphs instead of closed contours, so that they are rendered incorrectly by normal software.");
cls_Font_FTFont.def("SetSingleStrokeFont", (void (Font_FTFont::*)(bool)) &Font_FTFont::SetSingleStrokeFont, "Set if this font should be rendered as single-stroke (one-line).", py::arg("theIsSingleLine"));
cls_Font_FTFont.def("Release", (void (Font_FTFont::*)()) &Font_FTFont::Release, "Release currently loaded font.");
cls_Font_FTFont.def("RenderGlyph", (bool (Font_FTFont::*)(const Standard_Utf32Char)) &Font_FTFont::RenderGlyph, "Render specified glyph into internal buffer (bitmap).", py::arg("theChar"));
cls_Font_FTFont.def("GlyphMaxSizeX", (unsigned int (Font_FTFont::*)() const) &Font_FTFont::GlyphMaxSizeX, "Returns maximal glyph width in pixels (rendered to bitmap).");
cls_Font_FTFont.def("GlyphMaxSizeY", (unsigned int (Font_FTFont::*)() const) &Font_FTFont::GlyphMaxSizeY, "Returns maximal glyph height in pixels (rendered to bitmap).");
cls_Font_FTFont.def("Ascender", (float (Font_FTFont::*)() const) &Font_FTFont::Ascender, "Returns vertical distance from the horizontal baseline to the highest character coordinate.");
cls_Font_FTFont.def("Descender", (float (Font_FTFont::*)() const) &Font_FTFont::Descender, "Returns vertical distance from the horizontal baseline to the lowest character coordinate.");
cls_Font_FTFont.def("LineSpacing", (float (Font_FTFont::*)() const) &Font_FTFont::LineSpacing, "Returns default line spacing (the baseline-to-baseline distance).");
cls_Font_FTFont.def("PointSize", (unsigned int (Font_FTFont::*)() const) &Font_FTFont::PointSize, "Configured point size");
cls_Font_FTFont.def("SetWidthScaling", (void (Font_FTFont::*)(const float)) &Font_FTFont::SetWidthScaling, "Setup glyph scaling along X-axis. By default glyphs are not scaled (scaling factor = 1.0)", py::arg("theScaleFactor"));
cls_Font_FTFont.def("AdvanceX", (float (Font_FTFont::*)(Standard_Utf32Char) const) &Font_FTFont::AdvanceX, "Compute horizontal advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUCharNext"));
cls_Font_FTFont.def("AdvanceX", (float (Font_FTFont::*)(Standard_Utf32Char, Standard_Utf32Char)) &Font_FTFont::AdvanceX, "Compute horizontal advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_FTFont.def("AdvanceY", (float (Font_FTFont::*)(Standard_Utf32Char) const) &Font_FTFont::AdvanceY, "Compute vertical advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUCharNext"));
cls_Font_FTFont.def("AdvanceY", (float (Font_FTFont::*)(Standard_Utf32Char, Standard_Utf32Char)) &Font_FTFont::AdvanceY, "Compute vertical advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUChar"), py::arg("theUCharNext"));
cls_Font_FTFont.def("GlyphsNumber", (Standard_Integer (Font_FTFont::*)() const) &Font_FTFont::GlyphsNumber, "Returns glyphs number in this font.");
cls_Font_FTFont.def("GlyphRect", (void (Font_FTFont::*)(Font_Rect &) const) &Font_FTFont::GlyphRect, "Retrieve glyph bitmap rectangle", py::arg("theRect"));
cls_Font_FTFont.def("BoundingBox", (Font_Rect (Font_FTFont::*)(const NCollection_String &, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_FTFont::BoundingBox, "Computes bounding box of the given text using plain-text formatter (Font_TextFormatter). Note that bounding box takes into account the text alignment options. Its corners are relative to the text alignment anchor point, their coordinates can be negative.", py::arg("theString"), py::arg("theAlignX"), py::arg("theAlignY"));
cls_Font_FTFont.def_static("get_type_name_", (const char * (*)()) &Font_FTFont::get_type_name, "None");
cls_Font_FTFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FTFont::get_type_descriptor, "None");
cls_Font_FTFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FTFont::*)() const) &Font_FTFont::DynamicType, "None");

// CLASS: FONT_TEXTFORMATTER
py::class_<Font_TextFormatter> cls_Font_TextFormatter(mod, "Font_TextFormatter", "This class intended to prepare formatted text.");

// Constructors
cls_Font_TextFormatter.def(py::init<>());

// Methods
cls_Font_TextFormatter.def("SetupAlignment", (void (Font_TextFormatter::*)(const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_TextFormatter::SetupAlignment, "Setup alignment style.", py::arg("theAlignX"), py::arg("theAlignY"), py::call_guard<ImportGraphic3d>());
cls_Font_TextFormatter.def("Reset", (void (Font_TextFormatter::*)()) &Font_TextFormatter::Reset, "Reset current progress.");
cls_Font_TextFormatter.def("Append", (void (Font_TextFormatter::*)(const NCollection_String &, Font_FTFont &)) &Font_TextFormatter::Append, "Render specified text to inner buffer.", py::arg("theString"), py::arg("theFont"));
cls_Font_TextFormatter.def("Format", (void (Font_TextFormatter::*)()) &Font_TextFormatter::Format, "Perform formatting on the buffered text. Should not be called more than once after initialization!");
cls_Font_TextFormatter.def("TopLeft", (const NCollection_Vec2<Standard_ShortReal> & (Font_TextFormatter::*)(const Standard_Integer) const) &Font_TextFormatter::TopLeft, "Returns specific glyph rectangle.", py::arg("theIndex"));
cls_Font_TextFormatter.def("String", (const NCollection_String & (Font_TextFormatter::*)() const) &Font_TextFormatter::String, "Returns current rendering string.");
cls_Font_TextFormatter.def("TabSize", (Standard_Integer (Font_TextFormatter::*)() const) &Font_TextFormatter::TabSize, "Returns tab size.");
cls_Font_TextFormatter.def("ResultWidth", (Standard_ShortReal (Font_TextFormatter::*)() const) &Font_TextFormatter::ResultWidth, "Returns width of formatted text.");
cls_Font_TextFormatter.def("ResultHeight", (Standard_ShortReal (Font_TextFormatter::*)() const) &Font_TextFormatter::ResultHeight, "Returns height of formatted text.");
cls_Font_TextFormatter.def("BndBox", (void (Font_TextFormatter::*)(Font_Rect &) const) &Font_TextFormatter::BndBox, "", py::arg("theBndBox"));

// CLASS: FONT_BREPFONT
/*
py::class_<Font_BRepFont, opencascade::handle<Font_BRepFont>> cls_Font_BRepFont(mod, "Font_BRepFont", "This tool provides basic services for rendering of vectorized text glyphs as BRep shapes. Single instance initialize single font for sequential glyphs rendering with implicit caching of already rendered glyphs. Thus position of each glyph in the text is specified by shape location.");

// Constructors
cls_Font_BRepFont.def(py::init<>());
cls_Font_BRepFont.def(py::init<const NCollection_String &, const Standard_Real>(), py::arg("theFontPath"), py::arg("theSize"));
cls_Font_BRepFont.def(py::init<const NCollection_String &, const Font_FontAspect, const Standard_Real>(), py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theSize"));

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
*/

// CLASS: FONT_BREPTEXTBUILDER
py::class_<Font_BRepTextBuilder> cls_Font_BRepTextBuilder(mod, "Font_BRepTextBuilder", "Represents class for applying text formatting.");

// Methods
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const Font_TextFormatter & a1) -> TopoDS_Shape { return self.Perform(a0, a1); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", (TopoDS_Shape (Font_BRepTextBuilder::*)(Font_BRepFont &, const Font_TextFormatter &, const gp_Ax3 &)) &Font_BRepTextBuilder::Perform, "Render text as BRep shape.", py::arg("theFont"), py::arg("theFormatter"), py::arg("thePenLoc"), py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1) -> TopoDS_Shape { return self.Perform(a0, a1); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1, const gp_Ax3 & a2) -> TopoDS_Shape { return self.Perform(a0, a1, a2); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1, const gp_Ax3 & a2, const Graphic3d_HorizontalTextAlignment a3) -> TopoDS_Shape { return self.Perform(a0, a1, a2, a3); }, py::call_guard<ImportGraphic3d>());
cls_Font_BRepTextBuilder.def("Perform", (TopoDS_Shape (Font_BRepTextBuilder::*)(Font_BRepFont &, const NCollection_String &, const gp_Ax3 &, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_BRepTextBuilder::Perform, "Render text as BRep shape.", py::arg("theFont"), py::arg("theString"), py::arg("thePenLoc"), py::arg("theHAlign"), py::arg("theVAlign"), py::call_guard<ImportGraphic3d>());

// CLASS: FONT_SYSTEMFONT
py::class_<Font_SystemFont, opencascade::handle<Font_SystemFont>, Standard_Transient> cls_Font_SystemFont(mod, "Font_SystemFont", "This class stores information about the font, which is merely a file path and cached metadata about the font.");

// Constructors
cls_Font_SystemFont.def(py::init<>());
cls_Font_SystemFont.def(py::init<const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const opencascade::handle<TCollection_HAsciiString> &>(), py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFilePath"));
cls_Font_SystemFont.def(py::init<const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &>(), py::arg("theXLFD"), py::arg("theFilePath"));

// Methods
cls_Font_SystemFont.def_static("get_type_name_", (const char * (*)()) &Font_SystemFont::get_type_name, "None");
cls_Font_SystemFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_SystemFont::get_type_descriptor, "None");
cls_Font_SystemFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_SystemFont::*)() const) &Font_SystemFont::DynamicType, "None");
cls_Font_SystemFont.def("FontName", (const opencascade::handle<TCollection_HAsciiString> & (Font_SystemFont::*)() const) &Font_SystemFont::FontName, "Returns font family name.");
cls_Font_SystemFont.def("FontPath", (const opencascade::handle<TCollection_HAsciiString> & (Font_SystemFont::*)() const) &Font_SystemFont::FontPath, "Returns font file path.");
cls_Font_SystemFont.def("FontAspect", (Font_FontAspect (Font_SystemFont::*)() const) &Font_SystemFont::FontAspect, "Returns font aspect.");
cls_Font_SystemFont.def("FontHeight", (Standard_Integer (Font_SystemFont::*)() const) &Font_SystemFont::FontHeight, "Returns font height. If returned value is equal -1 it means that font is resizable.");
cls_Font_SystemFont.def("IsValid", (Standard_Boolean (Font_SystemFont::*)() const) &Font_SystemFont::IsValid, "None");
cls_Font_SystemFont.def("IsEqual", (Standard_Boolean (Font_SystemFont::*)(const opencascade::handle<Font_SystemFont> &) const) &Font_SystemFont::IsEqual, "Return true if the FontName, FontAspect and FontSize are the same.", py::arg("theOtherFont"));
cls_Font_SystemFont.def("IsSingleStrokeFont", (Standard_Boolean (Font_SystemFont::*)() const) &Font_SystemFont::IsSingleStrokeFont, "Return TRUE if this is single-stroke (one-line) font, FALSE by default. Such fonts define single-line glyphs instead of closed contours, so that they are rendered incorrectly by normal software.");
cls_Font_SystemFont.def("SetSingleStrokeFont", (void (Font_SystemFont::*)(Standard_Boolean)) &Font_SystemFont::SetSingleStrokeFont, "Set if this font should be rendered as single-stroke (one-line).", py::arg("theIsSingleLine"));

// TYPEDEF: FONT_NLISTOFSYSTEMFONT
bind_NCollection_List<opencascade::handle<Font_SystemFont> >(mod, "Font_NListOfSystemFont", py::module_local(false));

// CLASS: FONT_FONTMGR
py::class_<Font_FontMgr, opencascade::handle<Font_FontMgr>, Standard_Transient> cls_Font_FontMgr(mod, "Font_FontMgr", "Collects and provides information about available fonts in system.");

// Methods
cls_Font_FontMgr.def_static("GetInstance_", (opencascade::handle<Font_FontMgr> (*)()) &Font_FontMgr::GetInstance, "None");
cls_Font_FontMgr.def("GetAvailableFonts", (const Font_NListOfSystemFont & (Font_FontMgr::*)() const) &Font_FontMgr::GetAvailableFonts, "None");
cls_Font_FontMgr.def("GetAvailableFontsNames", (void (Font_FontMgr::*)(TColStd_SequenceOfHAsciiString &) const) &Font_FontMgr::GetAvailableFontsNames, "Returns sequence of available fonts names", py::arg("theFontsNames"));
cls_Font_FontMgr.def("GetFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const Standard_Integer) const) &Font_FontMgr::GetFont, "Returns font that match given parameters. If theFontName is empty string returned font can have any FontName. If theFontAspect is Font_FA_Undefined returned font can have any FontAspect. If theFontSize is '-1' returned font can have any FontSize.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFontSize"));
cls_Font_FontMgr.def("FindFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const Standard_Integer) const) &Font_FontMgr::FindFont, "Tries to find font by given parameters. If the specified font is not found tries to use font names mapping. If the requested family name not found -> search for any font family with given aspect and height. If the font is still not found, returns any font available in the system. Returns NULL in case when the fonts are not found in the system.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFontSize"));
cls_Font_FontMgr.def("CheckFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const Standard_CString) const) &Font_FontMgr::CheckFont, "Read font file and retrieve information from it.", py::arg("theFontPath"));
cls_Font_FontMgr.def("RegisterFont", (Standard_Boolean (Font_FontMgr::*)(const opencascade::handle<Font_SystemFont> &, const Standard_Boolean)) &Font_FontMgr::RegisterFont, "Register new font. If there is existing entity with the same name and properties but different path then font will will be overridden or ignored depending on theToOverride flag.", py::arg("theFont"), py::arg("theToOverride"));
cls_Font_FontMgr.def_static("get_type_name_", (const char * (*)()) &Font_FontMgr::get_type_name, "None");
cls_Font_FontMgr.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FontMgr::get_type_descriptor, "None");
cls_Font_FontMgr.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FontMgr::*)() const) &Font_FontMgr::DynamicType, "None");

// TYPEDEF: FT_LIBRARY

// CLASS: FONT_FTLIBRARY
py::class_<Font_FTLibrary, opencascade::handle<Font_FTLibrary>, Standard_Transient> cls_Font_FTLibrary(mod, "Font_FTLibrary", "Wrapper over FT_Library. Provides access to FreeType library.");

// Constructors
cls_Font_FTLibrary.def(py::init<>());

// Methods
cls_Font_FTLibrary.def("IsValid", (bool (Font_FTLibrary::*)() const) &Font_FTLibrary::IsValid, "This method should always return true.");
// cls_Font_FTLibrary.def("Instance", (FT_Library (Font_FTLibrary::*)() const) &Font_FTLibrary::Instance, "Access FT_Library instance.");
cls_Font_FTLibrary.def_static("get_type_name_", (const char * (*)()) &Font_FTLibrary::get_type_name, "None");
cls_Font_FTLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FTLibrary::get_type_descriptor, "None");
cls_Font_FTLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FTLibrary::*)() const) &Font_FTLibrary::DynamicType, "None");


}
