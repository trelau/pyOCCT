#include <pyOCCT_Common.hpp>

#include <Font_FontAspect.hxx>
#include <NCollection_Vec2.hxx>
#include <Font_Rect.hxx>
#include <Font_FTFont.hxx>
#include <Standard_Transient.hxx>
#include <Font_FTLibrary.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Image_PixMap.hxx>
#include <NCollection_String.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <Font_TextFormatter.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Mutex.hxx>
#include <Font_BRepFont.hxx>
#include <gp_Ax3.hxx>
#include <Font_BRepTextBuilder.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Font_SystemFont.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <Font_NListOfSystemFont.hxx>
#include <Font_FontMgr.hxx>
#include <TColStd_SequenceOfHAsciiString.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(Font, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Image");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS
	struct ImportGraphic3d{
		ImportGraphic3d() { py::module::import("OCCT.Graphic3d"); }
	};


	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FontAspect.hxx
	py::enum_<Font_FontAspect>(mod, "Font_FontAspect", "Specifies aspect of system font.")
		.value("Font_FA_Undefined", Font_FontAspect::Font_FA_Undefined)
		.value("Font_FA_Regular", Font_FontAspect::Font_FA_Regular)
		.value("Font_FA_Bold", Font_FontAspect::Font_FA_Bold)
		.value("Font_FA_Italic", Font_FontAspect::Font_FA_Italic)
		.value("Font_FA_BoldItalic", Font_FontAspect::Font_FA_BoldItalic)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_NListOfSystemFont.hxx
	mod.def("IsEqual", (Standard_Boolean (*)(const opencascade::handle<Font_SystemFont> &, const opencascade::handle<Font_SystemFont> &)) &IsEqual, "None", py::arg("theFirstFont"), py::arg("theSecondFont"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_Rect.hxx
	py::class_<Font_Rect, std::unique_ptr<Font_Rect, Deleter<Font_Rect>>> cls_Font_Rect(mod, "Font_Rect", "Auxiliary POD structure - 2D rectangle definition.");
	cls_Font_Rect.def(py::init<>());
	cls_Font_Rect.def("TopLeft", (NCollection_Vec2<float> (Font_Rect::*)() const ) &Font_Rect::TopLeft, "Top-left corner as vec2.");
	cls_Font_Rect.def("TopLeft", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const ) &Font_Rect::TopLeft, "Top-left corner as vec2.", py::arg("theVec"));
	cls_Font_Rect.def("TopRight", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const ) &Font_Rect::TopRight, "Top-right corner as vec2.", py::arg("theVec"));
	cls_Font_Rect.def("BottomLeft", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const ) &Font_Rect::BottomLeft, "Bottom-left corner as vec2.", py::arg("theVec"));
	cls_Font_Rect.def("BottomRight", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const ) &Font_Rect::BottomRight, "Bottom-right corner as vec2.", py::arg("theVec"));
	cls_Font_Rect.def("Width", (float (Font_Rect::*)() const ) &Font_Rect::Width, "Rectangle width.");
	cls_Font_Rect.def("Height", (float (Font_Rect::*)() const ) &Font_Rect::Height, "Rectangle height.");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FTFont.hxx
	py::class_<FT_FaceRec_, std::unique_ptr<FT_FaceRec_, Deleter<FT_FaceRec_>>> cls_FT_FaceRec(mod, "FT_FaceRec", "None");
	cls_FT_FaceRec.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FTFont.hxx
	py::class_<FT_Vector_, std::unique_ptr<FT_Vector_, Deleter<FT_Vector_>>> cls_FT_Vector(mod, "FT_Vector", "None");
	cls_FT_Vector.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FTLibrary.hxx
	py::class_<Font_FTLibrary, opencascade::handle<Font_FTLibrary>, Standard_Transient> cls_Font_FTLibrary(mod, "Font_FTLibrary", "Wrapper over FT_Library. Provides access to FreeType library.");
	cls_Font_FTLibrary.def(py::init<>());
	cls_Font_FTLibrary.def("IsValid", (bool (Font_FTLibrary::*)() const ) &Font_FTLibrary::IsValid, "This method should always return true.");
	cls_Font_FTLibrary.def("Instance", (FT_Library (Font_FTLibrary::*)() const ) &Font_FTLibrary::Instance, "Access FT_Library instance.");
	cls_Font_FTLibrary.def_static("get_type_name_", (const char * (*)()) &Font_FTLibrary::get_type_name, "None");
	cls_Font_FTLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FTLibrary::get_type_descriptor, "None");
	cls_Font_FTLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FTLibrary::*)() const ) &Font_FTLibrary::DynamicType, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FTFont.hxx
	py::class_<Font_FTFont, opencascade::handle<Font_FTFont>, Standard_Transient> cls_Font_FTFont(mod, "Font_FTFont", "Wrapper over FreeType font. Notice that this class uses internal buffers for loaded glyphs and it is absolutely UNSAFE to load/read glyph from concurrent threads!");
	cls_Font_FTFont.def(py::init<>());
	cls_Font_FTFont.def(py::init<const opencascade::handle<Font_FTLibrary> &>(), py::arg("theFTLib"));
	cls_Font_FTFont.def("IsValid", (bool (Font_FTFont::*)() const ) &Font_FTFont::IsValid, "Returns true if font is loaded");
	cls_Font_FTFont.def("GlyphImage", (const Image_PixMap & (Font_FTFont::*)() const ) &Font_FTFont::GlyphImage, "Returns image plane for currently rendered glyph");
	cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const NCollection_String &, const unsigned int, const unsigned int)) &Font_FTFont::Init, "Initialize the font.", py::arg("theFontPath"), py::arg("thePointSize"), py::arg("theResolution"));
	cls_Font_FTFont.def("Init", (bool (Font_FTFont::*)(const NCollection_String &, const Font_FontAspect, const unsigned int, const unsigned int)) &Font_FTFont::Init, "Initialize the font.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("thePointSize"), py::arg("theResolution"));
	cls_Font_FTFont.def("Release", (void (Font_FTFont::*)()) &Font_FTFont::Release, "Release currently loaded font.");
	cls_Font_FTFont.def("RenderGlyph", (bool (Font_FTFont::*)(const Standard_Utf32Char)) &Font_FTFont::RenderGlyph, "Render specified glyph into internal buffer (bitmap).", py::arg("theChar"));
	cls_Font_FTFont.def("GlyphMaxSizeX", (unsigned int (Font_FTFont::*)() const ) &Font_FTFont::GlyphMaxSizeX, "Returns maximal glyph width in pixels (rendered to bitmap).");
	cls_Font_FTFont.def("GlyphMaxSizeY", (unsigned int (Font_FTFont::*)() const ) &Font_FTFont::GlyphMaxSizeY, "Returns maximal glyph height in pixels (rendered to bitmap).");
	cls_Font_FTFont.def("Ascender", (float (Font_FTFont::*)() const ) &Font_FTFont::Ascender, "Returns vertical distance from the horizontal baseline to the highest character coordinate.");
	cls_Font_FTFont.def("Descender", (float (Font_FTFont::*)() const ) &Font_FTFont::Descender, "Returns vertical distance from the horizontal baseline to the lowest character coordinate.");
	cls_Font_FTFont.def("LineSpacing", (float (Font_FTFont::*)() const ) &Font_FTFont::LineSpacing, "Returns default line spacing (the baseline-to-baseline distance).");
	cls_Font_FTFont.def("PointSize", (unsigned int (Font_FTFont::*)() const ) &Font_FTFont::PointSize, "Configured point size");
	cls_Font_FTFont.def("AdvanceX", (float (Font_FTFont::*)(const Standard_Utf32Char)) &Font_FTFont::AdvanceX, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUCharNext"));
	cls_Font_FTFont.def("AdvanceX", (float (Font_FTFont::*)(const Standard_Utf32Char, const Standard_Utf32Char)) &Font_FTFont::AdvanceX, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUChar"), py::arg("theUCharNext"));
	cls_Font_FTFont.def("AdvanceY", (float (Font_FTFont::*)(const Standard_Utf32Char)) &Font_FTFont::AdvanceY, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUCharNext"));
	cls_Font_FTFont.def("AdvanceY", (float (Font_FTFont::*)(const Standard_Utf32Char, const Standard_Utf32Char)) &Font_FTFont::AdvanceY, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUChar"), py::arg("theUCharNext"));
	cls_Font_FTFont.def("GlyphsNumber", (Standard_Integer (Font_FTFont::*)() const ) &Font_FTFont::GlyphsNumber, "Returns glyphs number in this font.");
	cls_Font_FTFont.def("GlyphRect", (void (Font_FTFont::*)(Font_Rect &) const ) &Font_FTFont::GlyphRect, "Retrieve glyph bitmap rectangle", py::arg("theRect"));
	cls_Font_FTFont.def("BoundingBox", (Font_Rect (Font_FTFont::*)(const NCollection_String &, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_FTFont::BoundingBox, "Computes bounding box of the given text using plain-text formatter (Font_TextFormatter). Note that bounding box takes into account the text alignment options. Its corners are relative to the text alignment anchor point, their coordinates can be negative.", py::arg("theString"), py::arg("theAlignX"), py::arg("theAlignY"), py::call_guard<ImportGraphic3d>());
	cls_Font_FTFont.def_static("get_type_name_", (const char * (*)()) &Font_FTFont::get_type_name, "None");
	cls_Font_FTFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FTFont::get_type_descriptor, "None");
	cls_Font_FTFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FTFont::*)() const ) &Font_FTFont::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_TextFormatter.hxx
	py::class_<Font_TextFormatter, std::unique_ptr<Font_TextFormatter, Deleter<Font_TextFormatter>>> cls_Font_TextFormatter(mod, "Font_TextFormatter", "This class intended to prepare formatted text.");
	cls_Font_TextFormatter.def(py::init<>());
	cls_Font_TextFormatter.def("SetupAlignment", (void (Font_TextFormatter::*)(const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_TextFormatter::SetupAlignment, "Setup alignment style.", py::arg("theAlignX"), py::arg("theAlignY"), py::call_guard<ImportGraphic3d>());
	cls_Font_TextFormatter.def("Reset", (void (Font_TextFormatter::*)()) &Font_TextFormatter::Reset, "Reset current progress.");
	cls_Font_TextFormatter.def("Append", (void (Font_TextFormatter::*)(const NCollection_String &, Font_FTFont &)) &Font_TextFormatter::Append, "Render specified text to inner buffer.", py::arg("theString"), py::arg("theFont"));
	cls_Font_TextFormatter.def("Format", (void (Font_TextFormatter::*)()) &Font_TextFormatter::Format, "Perform formatting on the buffered text. Should not be called more than once after initialization!");
	cls_Font_TextFormatter.def("TopLeft", (const NCollection_Vec2<Standard_ShortReal> & (Font_TextFormatter::*)(const Standard_Integer) const ) &Font_TextFormatter::TopLeft, "Returns specific glyph rectangle.", py::arg("theIndex"));
	cls_Font_TextFormatter.def("String", (const NCollection_String & (Font_TextFormatter::*)() const ) &Font_TextFormatter::String, "Returns current rendering string.");
	cls_Font_TextFormatter.def("TabSize", (Standard_Integer (Font_TextFormatter::*)() const ) &Font_TextFormatter::TabSize, "Returns tab size.");
	cls_Font_TextFormatter.def("ResultWidth", (Standard_ShortReal (Font_TextFormatter::*)() const ) &Font_TextFormatter::ResultWidth, "Returns width of formatted text.");
	cls_Font_TextFormatter.def("ResultHeight", (Standard_ShortReal (Font_TextFormatter::*)() const ) &Font_TextFormatter::ResultHeight, "Returns height of formatted text.");
	cls_Font_TextFormatter.def("BndBox", (void (Font_TextFormatter::*)(Font_Rect &) const ) &Font_TextFormatter::BndBox, "", py::arg("theBndBox"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_BRepFont.hxx
	py::class_<Font_BRepFont, opencascade::handle<Font_BRepFont>> cls_Font_BRepFont(mod, "Font_BRepFont", "This tool provides basic services for rendering of vectorized text glyphs as BRep shapes. Single instance initialize single font for sequential glyphs rendering with implicit caching of already rendered glyphs. Thus position of each glyph in the text is specified by shape location.");
	cls_Font_BRepFont.def(py::init<>());
	cls_Font_BRepFont.def(py::init<const NCollection_String &, const Standard_Real>(), py::arg("theFontPath"), py::arg("theSize"));
	cls_Font_BRepFont.def(py::init<const NCollection_String &, const Font_FontAspect, const Standard_Real>(), py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theSize"));
	cls_Font_BRepFont.def("Release", (void (Font_BRepFont::*)()) &Font_BRepFont::Release, "Release currently loaded font.");
	cls_Font_BRepFont.def("Init", (bool (Font_BRepFont::*)(const NCollection_String &, const Standard_Real)) &Font_BRepFont::Init, "Initialize the font.", py::arg("theFontPath"), py::arg("theSize"));
	cls_Font_BRepFont.def("Init", (bool (Font_BRepFont::*)(const NCollection_String &, const Font_FontAspect, const Standard_Real)) &Font_BRepFont::Init, "Initialize the font. Please take into account that size is specified NOT in typography points (pt.). If you need to specify size in points, value should be converted. Formula for pt. -> m conversion: aSizeMeters = 0.0254 * theSizePt / 72.0", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theSize"));
	cls_Font_BRepFont.def("RenderGlyph", (TopoDS_Shape (Font_BRepFont::*)(const Standard_Utf32Char &)) &Font_BRepFont::RenderGlyph, "Render single glyph as TopoDS_Shape.", py::arg("theChar"));
	cls_Font_BRepFont.def("SetCompositeCurveMode", (void (Font_BRepFont::*)(const Standard_Boolean)) &Font_BRepFont::SetCompositeCurveMode, "Setup glyph geometry construction mode. By default algorithm creates independent TopoDS_Edge for each original curve in the glyph (line segment or Bezie curve). Algorithm might optionally create composite BSpline curve for each contour which reduces memory footprint but limits curve class to C0. Notice that altering this flag clears currently accumulated cache!", py::arg("theToConcatenate"));
	cls_Font_BRepFont.def("Ascender", (Standard_Real (Font_BRepFont::*)() const ) &Font_BRepFont::Ascender, "Returns vertical distance from the horizontal baseline to the highest character coordinate.");
	cls_Font_BRepFont.def("Descender", (Standard_Real (Font_BRepFont::*)() const ) &Font_BRepFont::Descender, "Returns vertical distance from the horizontal baseline to the lowest character coordinate.");
	cls_Font_BRepFont.def("LineSpacing", (Standard_Real (Font_BRepFont::*)() const ) &Font_BRepFont::LineSpacing, "Returns default line spacing (the baseline-to-baseline distance).");
	cls_Font_BRepFont.def("PointSize", (Standard_Real (Font_BRepFont::*)() const ) &Font_BRepFont::PointSize, "Configured point size");
	cls_Font_BRepFont.def("AdvanceX", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char)) &Font_BRepFont::AdvanceX, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUCharNext"));
	cls_Font_BRepFont.def("AdvanceX", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char, const Standard_Utf32Char)) &Font_BRepFont::AdvanceX, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered horizontally.", py::arg("theUChar"), py::arg("theUCharNext"));
	cls_Font_BRepFont.def("AdvanceY", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char)) &Font_BRepFont::AdvanceY, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUCharNext"));
	cls_Font_BRepFont.def("AdvanceY", (Standard_Real (Font_BRepFont::*)(const Standard_Utf32Char, const Standard_Utf32Char)) &Font_BRepFont::AdvanceY, "Compute advance to the next character with kerning applied when applicable. Assuming text rendered vertically.", py::arg("theUChar"), py::arg("theUCharNext"));
	cls_Font_BRepFont.def("Scale", (Standard_Real (Font_BRepFont::*)() const ) &Font_BRepFont::Scale, "Returns scaling factor for current font size.");
	cls_Font_BRepFont.def("Mutex", (Standard_Mutex & (Font_BRepFont::*)()) &Font_BRepFont::Mutex, "Returns mutex.");
	cls_Font_BRepFont.def_static("get_type_name_", (const char * (*)()) &Font_BRepFont::get_type_name, "None");
	cls_Font_BRepFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_BRepFont::get_type_descriptor, "None");
	cls_Font_BRepFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_BRepFont::*)() const ) &Font_BRepFont::DynamicType, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_BRepTextBuilder.hxx
	py::class_<Font_BRepTextBuilder, std::unique_ptr<Font_BRepTextBuilder, Deleter<Font_BRepTextBuilder>>> cls_Font_BRepTextBuilder(mod, "Font_BRepTextBuilder", "Represents class for applying text formatting.");
	cls_Font_BRepTextBuilder.def(py::init<>());
	cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const Font_TextFormatter & a1) -> TopoDS_Shape { return self.Perform(a0, a1); }, py::arg("theFont"), py::arg("theFormatter"), py::call_guard<ImportGraphic3d>());
	cls_Font_BRepTextBuilder.def("Perform", (TopoDS_Shape (Font_BRepTextBuilder::*)(Font_BRepFont &, const Font_TextFormatter &, const gp_Ax3 &)) &Font_BRepTextBuilder::Perform, "Render text as BRep shape.", py::arg("theFont"), py::arg("theFormatter"), py::arg("thePenLoc"), py::call_guard<ImportGraphic3d>());
	cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1) -> TopoDS_Shape { return self.Perform(a0, a1); }, py::arg("theFont"), py::arg("theString"), py::call_guard<ImportGraphic3d>());
	cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1, const gp_Ax3 & a2) -> TopoDS_Shape { return self.Perform(a0, a1, a2); }, py::arg("theFont"), py::arg("theString"), py::arg("thePenLoc"), py::call_guard<ImportGraphic3d>());
	cls_Font_BRepTextBuilder.def("Perform", [](Font_BRepTextBuilder &self, Font_BRepFont & a0, const NCollection_String & a1, const gp_Ax3 & a2, const Graphic3d_HorizontalTextAlignment a3) -> TopoDS_Shape { return self.Perform(a0, a1, a2, a3); }, py::arg("theFont"), py::arg("theString"), py::arg("thePenLoc"), py::arg("theHAlign"), py::call_guard<ImportGraphic3d>());
	cls_Font_BRepTextBuilder.def("Perform", (TopoDS_Shape (Font_BRepTextBuilder::*)(Font_BRepFont &, const NCollection_String &, const gp_Ax3 &, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment)) &Font_BRepTextBuilder::Perform, "Render text as BRep shape.", py::arg("theFont"), py::arg("theString"), py::arg("thePenLoc"), py::arg("theHAlign"), py::arg("theVAlign"), py::call_guard<ImportGraphic3d>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_SystemFont.hxx
	py::class_<Font_SystemFont, opencascade::handle<Font_SystemFont>, Standard_Transient> cls_Font_SystemFont(mod, "Font_SystemFont", "Structure for store of Font System Information");
	cls_Font_SystemFont.def(py::init<>());
	cls_Font_SystemFont.def(py::init<const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const opencascade::handle<TCollection_HAsciiString> &>(), py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFilePath"));
	cls_Font_SystemFont.def(py::init<const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &>(), py::arg("theXLFD"), py::arg("theFilePath"));
	cls_Font_SystemFont.def("FontName", (opencascade::handle<TCollection_HAsciiString> (Font_SystemFont::*)() const ) &Font_SystemFont::FontName, "Returns font family name");
	cls_Font_SystemFont.def("FontPath", (opencascade::handle<TCollection_HAsciiString> (Font_SystemFont::*)() const ) &Font_SystemFont::FontPath, "Returns font file path Level: Public");
	cls_Font_SystemFont.def("FontAspect", (Font_FontAspect (Font_SystemFont::*)() const ) &Font_SystemFont::FontAspect, "Returns font aspect Level: Public");
	cls_Font_SystemFont.def("FontHeight", (Standard_Integer (Font_SystemFont::*)() const ) &Font_SystemFont::FontHeight, "Returns font height If returned value is equal -1 it means that font is resizable Level: Public");
	cls_Font_SystemFont.def("IsValid", (Standard_Boolean (Font_SystemFont::*)() const ) &Font_SystemFont::IsValid, "None");
	cls_Font_SystemFont.def("IsEqual", (Standard_Boolean (Font_SystemFont::*)(const opencascade::handle<Font_SystemFont> &) const ) &Font_SystemFont::IsEqual, "Return true if the FontName, FontAspect and FontSize are the same. Level: Public", py::arg("theOtherFont"));
	cls_Font_SystemFont.def_static("get_type_name_", (const char * (*)()) &Font_SystemFont::get_type_name, "None");
	cls_Font_SystemFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_SystemFont::get_type_descriptor, "None");
	cls_Font_SystemFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_SystemFont::*)() const ) &Font_SystemFont::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FontMgr.hxx
	py::class_<Font_FontMgr, opencascade::handle<Font_FontMgr>, Standard_Transient> cls_Font_FontMgr(mod, "Font_FontMgr", "Collects and provides information about available fonts in system.");
	cls_Font_FontMgr.def_static("GetInstance_", (opencascade::handle<Font_FontMgr> (*)()) &Font_FontMgr::GetInstance, "None");
	cls_Font_FontMgr.def("GetAvailableFonts", (const Font_NListOfSystemFont & (Font_FontMgr::*)() const ) &Font_FontMgr::GetAvailableFonts, "None");
	cls_Font_FontMgr.def("GetAvailableFontsNames", (void (Font_FontMgr::*)(TColStd_SequenceOfHAsciiString &) const ) &Font_FontMgr::GetAvailableFontsNames, "Returns sequence of available fonts names", py::arg("theFontsNames"));
	cls_Font_FontMgr.def("GetFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const Standard_Integer) const ) &Font_FontMgr::GetFont, "Returns font that match given parameters. If theFontName is empty string returned font can have any FontName. If theFontAspect is Font_FA_Undefined returned font can have any FontAspect. If theFontSize is '-1' returned font can have any FontSize.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFontSize"));
	cls_Font_FontMgr.def("FindFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const opencascade::handle<TCollection_HAsciiString> &, const Font_FontAspect, const Standard_Integer) const ) &Font_FontMgr::FindFont, "Tries to find font by given parameters. If the specified font is not found tries to use font names mapping. If the requested family name not found -> search for any font family with given aspect and height. If the font is still not found, returns any font available in the system. Returns NULL in case when the fonts are not found in the system.", py::arg("theFontName"), py::arg("theFontAspect"), py::arg("theFontSize"));
	cls_Font_FontMgr.def("CheckFont", (opencascade::handle<Font_SystemFont> (Font_FontMgr::*)(const Standard_CString) const ) &Font_FontMgr::CheckFont, "Read font file and retrieve information from it.", py::arg("theFontPath"));
	cls_Font_FontMgr.def("RegisterFont", (Standard_Boolean (Font_FontMgr::*)(const opencascade::handle<Font_SystemFont> &, const Standard_Boolean)) &Font_FontMgr::RegisterFont, "Register new font. If there is existing entity with the same name and properties but different path then font will will be overridden or ignored depending on theToOverride flag.", py::arg("theFont"), py::arg("theToOverride"));
	cls_Font_FontMgr.def_static("get_type_name_", (const char * (*)()) &Font_FontMgr::get_type_name, "None");
	cls_Font_FontMgr.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Font_FontMgr::get_type_descriptor, "None");
	cls_Font_FontMgr.def("DynamicType", (const opencascade::handle<Standard_Type> & (Font_FontMgr::*)() const ) &Font_FontMgr::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FTLibrary.hxx
	py::class_<FT_LibraryRec_, std::unique_ptr<FT_LibraryRec_, Deleter<FT_LibraryRec_>>> cls_FT_LibraryRec(mod, "FT_LibraryRec", "None");
	cls_FT_LibraryRec.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FTFont.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FTFont.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_NListOfSystemFont.hxx
	bind_NCollection_List<opencascade::handle<Font_SystemFont> >(mod, "Font_NListOfSystemFont");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Font_FTLibrary.hxx

}
