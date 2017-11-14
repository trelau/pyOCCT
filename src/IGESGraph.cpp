#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESGraph_TextFontDef.hxx>
#include <gp_XYZ.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Type.hxx>
#include <IGESGraph_TextDisplayTemplate.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfInteger.hxx>
#include <NCollection_Array1.hxx>
#include <IGESGraph_Array1OfTextDisplayTemplate.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IGESGraph_HArray1OfTextDisplayTemplate.hxx>
#include <IGESGraph_Array1OfTextFontDef.hxx>
#include <IGESGraph_HArray1OfTextFontDef.hxx>
#include <IGESData_ColorEntity.hxx>
#include <IGESGraph_Color.hxx>
#include <IGESGraph_Array1OfColor.hxx>
#include <IGESGraph_HArray1OfColor.hxx>
#include <IGESData_Protocol.hxx>
#include <Interface_Protocol.hxx>
#include <IGESGraph_Protocol.hxx>
#include <IGESData_LineFontEntity.hxx>
#include <IGESBasic_SubfigureDef.hxx>
#include <IGESGraph_LineFontDefTemplate.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <IGESGraph_LineFontDefPattern.hxx>
#include <IGESData_LevelListEntity.hxx>
#include <IGESGraph_DefinitionLevel.hxx>
#include <IGESGraph_NominalSize.hxx>
#include <IGESGraph_DrawingSize.hxx>
#include <IGESGraph_DrawingUnits.hxx>
#include <IGESGraph_IntercharacterSpacing.hxx>
#include <IGESGraph_LineFontPredefined.hxx>
#include <IGESGraph_HighLight.hxx>
#include <IGESGraph_Pick.hxx>
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <IGESGraph_UniformRectGrid.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESGraph_ToolLineFontDefTemplate.hxx>
#include <IGESGraph_ToolLineFontDefPattern.hxx>
#include <IGESGraph_ToolTextFontDef.hxx>
#include <IGESGraph_ToolTextDisplayTemplate.hxx>
#include <IGESGraph_ToolColor.hxx>
#include <IGESGraph_ToolDefinitionLevel.hxx>
#include <IGESGraph_ToolNominalSize.hxx>
#include <IGESGraph_ToolDrawingSize.hxx>
#include <IGESGraph_ToolDrawingUnits.hxx>
#include <IGESGraph_ToolIntercharacterSpacing.hxx>
#include <IGESGraph_ToolLineFontPredefined.hxx>
#include <IGESGraph_ToolHighLight.hxx>
#include <IGESGraph_ToolPick.hxx>
#include <IGESGraph_ToolUniformRectGrid.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <IGESGraph_ReadWriteModule.hxx>
#include <IGESData_GeneralModule.hxx>
#include <IGESGraph_GeneralModule.hxx>
#include <IGESData_SpecificModule.hxx>
#include <IGESGraph_SpecificModule.hxx>
#include <IGESGraph.hxx>

PYBIND11_MODULE(IGESGraph, mod) {

	// IMPORT
	py::module::import("OCCT.IGESData");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.IGESBasic");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.Message");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_TextDisplayTemplate.hxx
	py::class_<IGESGraph_TextDisplayTemplate, opencascade::handle<IGESGraph_TextDisplayTemplate>, IGESData_IGESEntity> cls_IGESGraph_TextDisplayTemplate(mod, "IGESGraph_TextDisplayTemplate", "defines IGES TextDisplayTemplate Entity, Type <312>, form <0, 1> in package IGESGraph");
	cls_IGESGraph_TextDisplayTemplate.def(py::init<>());
	cls_IGESGraph_TextDisplayTemplate.def("Init", (void (IGESGraph_TextDisplayTemplate::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const opencascade::handle<IGESGraph_TextFontDef> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const gp_XYZ &)) &IGESGraph_TextDisplayTemplate::Init, "This method is used to set the fields of the class TextDisplayTemplate - aWidth : Character box width - aHeight : Character box height - afontCode : Font code - aFontEntity : Text Font Definition Entity - aSlantAngle : Slant angle - aRotationAngle : Rotation angle - aMirrorFlag : Mirror Flag - aRotationFlag : Rotate internal text flag - aCorner : Lower left corner coordinates(Form No. 0), Increments from coordinates (Form No. 1)", py::arg("aWidth"), py::arg("aHeight"), py::arg("aFontCode"), py::arg("aFontEntity"), py::arg("aSlantAngle"), py::arg("aRotationAngle"), py::arg("aMirrorFlag"), py::arg("aRotationFlag"), py::arg("aCorner"));
	cls_IGESGraph_TextDisplayTemplate.def("SetIncremental", (void (IGESGraph_TextDisplayTemplate::*)(const Standard_Boolean)) &IGESGraph_TextDisplayTemplate::SetIncremental, "Sets <me> to be Incremental (Form 1) if <mode> is True, or Basolute (Form 0) else", py::arg("mode"));
	cls_IGESGraph_TextDisplayTemplate.def("IsIncremental", (Standard_Boolean (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::IsIncremental, "returns True if entity is Incremental (Form 1). False if entity is Absolute (Form 0).");
	cls_IGESGraph_TextDisplayTemplate.def("BoxWidth", (Standard_Real (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::BoxWidth, "returns Character Box Width.");
	cls_IGESGraph_TextDisplayTemplate.def("BoxHeight", (Standard_Real (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::BoxHeight, "returns Character Box Height.");
	cls_IGESGraph_TextDisplayTemplate.def("IsFontEntity", (Standard_Boolean (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::IsFontEntity, "returns False if theFontEntity is Null, True otherwise.");
	cls_IGESGraph_TextDisplayTemplate.def("FontCode", (Standard_Integer (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::FontCode, "returns the font code.");
	cls_IGESGraph_TextDisplayTemplate.def("FontEntity", (opencascade::handle<IGESGraph_TextFontDef> (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::FontEntity, "returns Text Font Definition Entity used to define the font.");
	cls_IGESGraph_TextDisplayTemplate.def("SlantAngle", (Standard_Real (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::SlantAngle, "returns slant angle of character in radians.");
	cls_IGESGraph_TextDisplayTemplate.def("RotationAngle", (Standard_Real (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::RotationAngle, "returns Rotation angle of text block in radians.");
	cls_IGESGraph_TextDisplayTemplate.def("MirrorFlag", (Standard_Integer (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::MirrorFlag, "returns Mirror flag Mirror flag : 0 = no mirroring. 1 = mirror axis perpendicular to text base line. 2 = mirror axis is text base line.");
	cls_IGESGraph_TextDisplayTemplate.def("RotateFlag", (Standard_Integer (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::RotateFlag, "returns Rotate internal text flag. Rotate internal text flag : 0 = text horizontal. 1 = text vertical.");
	cls_IGESGraph_TextDisplayTemplate.def("StartingCorner", (gp_Pnt (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::StartingCorner, "If IsIncremental() returns False, gets coordinates of lower left corner of first character box. If IsIncremental() returns True, gets increments from X, Y, Z coordinates found in parent entity.");
	cls_IGESGraph_TextDisplayTemplate.def("TransformedStartingCorner", (gp_Pnt (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::TransformedStartingCorner, "If IsIncremental() returns False, gets coordinates of lower left corner of first character box. If IsIncremental() returns True, gets increments from X, Y, Z coordinates found in parent entity.");
	cls_IGESGraph_TextDisplayTemplate.def_static("get_type_name_", (const char * (*)()) &IGESGraph_TextDisplayTemplate::get_type_name, "None");
	cls_IGESGraph_TextDisplayTemplate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_TextDisplayTemplate::get_type_descriptor, "None");
	cls_IGESGraph_TextDisplayTemplate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_TextDisplayTemplate::*)() const ) &IGESGraph_TextDisplayTemplate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_TextFontDef.hxx
	py::class_<IGESGraph_TextFontDef, opencascade::handle<IGESGraph_TextFontDef>, IGESData_IGESEntity> cls_IGESGraph_TextFontDef(mod, "IGESGraph_TextFontDef", "defines IGES Text Font Definition Entity, Type <310> in package IGESGraph");
	cls_IGESGraph_TextFontDef.def(py::init<>());
	cls_IGESGraph_TextFontDef.def("Init", (void (IGESGraph_TextFontDef::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<IGESGraph_TextFontDef> &, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &)) &IGESGraph_TextFontDef::Init, "This method is used to set the fields of the class TextFontDef - aFontCode : Font Code - aFontName : Font Name - aSupersededFont : Number of superseded font - aSupersededEntity : Text Definition Entity - aScale : No. of grid units = 1 text height unit - allASCIICodes : ASCII codes for characters - allNextCharX & Y : Grid locations of the next character's origin (Integer vals) - allPenMotions : No. of pen motions for the characters - allPenFlags : Pen up/down flags, 0 = Down (default), 1 = Up - allMovePenToX & Y : Grid locations the pen will move to This method initializes the fields of the class TextFontDef. An exception is raised if the lengths of allASCIICodes, allNextChars, allPenMotions, allPenFlags and allMovePenTo are not same.", py::arg("aFontCode"), py::arg("aFontName"), py::arg("aSupersededFont"), py::arg("aSupersededEntity"), py::arg("aScale"), py::arg("allASCIICodes"), py::arg("allNextCharX"), py::arg("allNextCharY"), py::arg("allPenMotions"), py::arg("allPenFlags"), py::arg("allMovePenToX"), py::arg("allMovePenToY"));
	cls_IGESGraph_TextFontDef.def("FontCode", (Standard_Integer (IGESGraph_TextFontDef::*)() const ) &IGESGraph_TextFontDef::FontCode, "returns the font code.");
	cls_IGESGraph_TextFontDef.def("FontName", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_TextFontDef::*)() const ) &IGESGraph_TextFontDef::FontName, "returns the font name.");
	cls_IGESGraph_TextFontDef.def("IsSupersededFontEntity", (Standard_Boolean (IGESGraph_TextFontDef::*)() const ) &IGESGraph_TextFontDef::IsSupersededFontEntity, "True if this definition supersedes another TextFontDefinition Entity, False if it supersedes value.");
	cls_IGESGraph_TextFontDef.def("SupersededFontCode", (Standard_Integer (IGESGraph_TextFontDef::*)() const ) &IGESGraph_TextFontDef::SupersededFontCode, "returns the font number which this entity modifies.");
	cls_IGESGraph_TextFontDef.def("SupersededFontEntity", (opencascade::handle<IGESGraph_TextFontDef> (IGESGraph_TextFontDef::*)() const ) &IGESGraph_TextFontDef::SupersededFontEntity, "returns the font entity which this entity modifies.");
	cls_IGESGraph_TextFontDef.def("Scale", (Standard_Integer (IGESGraph_TextFontDef::*)() const ) &IGESGraph_TextFontDef::Scale, "returns the number of grid units which equal one text height unit.");
	cls_IGESGraph_TextFontDef.def("NbCharacters", (Standard_Integer (IGESGraph_TextFontDef::*)() const ) &IGESGraph_TextFontDef::NbCharacters, "returns the number of characters in this definition.");
	cls_IGESGraph_TextFontDef.def("ASCIICode", (Standard_Integer (IGESGraph_TextFontDef::*)(const Standard_Integer) const ) &IGESGraph_TextFontDef::ASCIICode, "returns the ASCII code of Chnum'th character. Exception OutOfRange is raised if Chnum <= 0 or Chnum > NbCharacters", py::arg("Chnum"));
	cls_IGESGraph_TextFontDef.def("NextCharOrigin", (void (IGESGraph_TextFontDef::*)(const Standard_Integer, Standard_Integer &, Standard_Integer &) const ) &IGESGraph_TextFontDef::NextCharOrigin, "returns grid location of origin of character next to Chnum'th char. Exception OutOfRange is raised if Chnum <= 0 or Chnum > NbCharacters", py::arg("Chnum"), py::arg("NX"), py::arg("NY"));
	cls_IGESGraph_TextFontDef.def("NbPenMotions", (Standard_Integer (IGESGraph_TextFontDef::*)(const Standard_Integer) const ) &IGESGraph_TextFontDef::NbPenMotions, "returns number of pen motions for Chnum'th character. Exception OutOfRange is raised if Chnum <= 0 or Chnum > NbCharacters", py::arg("Chnum"));
	cls_IGESGraph_TextFontDef.def("IsPenUp", (Standard_Boolean (IGESGraph_TextFontDef::*)(const Standard_Integer, const Standard_Integer) const ) &IGESGraph_TextFontDef::IsPenUp, "returns pen status(True if 1, False if 0) of Motionnum'th motion of Chnum'th character. Exception raised if Chnum <= 0 or Chnum > NbCharacters or Motionnum <= 0 or Motionnum > NbPenMotions", py::arg("Chnum"), py::arg("Motionnum"));
	cls_IGESGraph_TextFontDef.def("NextPenPosition", (void (IGESGraph_TextFontDef::*)(const Standard_Integer, const Standard_Integer, Standard_Integer &, Standard_Integer &) const ) &IGESGraph_TextFontDef::NextPenPosition, "None", py::arg("Chnum"), py::arg("Motionnum"), py::arg("IX"), py::arg("IY"));
	cls_IGESGraph_TextFontDef.def_static("get_type_name_", (const char * (*)()) &IGESGraph_TextFontDef::get_type_name, "None");
	cls_IGESGraph_TextFontDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_TextFontDef::get_type_descriptor, "None");
	cls_IGESGraph_TextFontDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_TextFontDef::*)() const ) &IGESGraph_TextFontDef::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<IGESGraph_Array1OfTextDisplayTemplate, std::unique_ptr<IGESGraph_Array1OfTextDisplayTemplate, Deleter<IGESGraph_Array1OfTextDisplayTemplate>>> cls_IGESGraph_Array1OfTextDisplayTemplate(mod, "IGESGraph_Array1OfTextDisplayTemplate", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def(py::init<>());
	cls_IGESGraph_Array1OfTextDisplayTemplate.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def(py::init([] (const IGESGraph_Array1OfTextDisplayTemplate &other) {return new IGESGraph_Array1OfTextDisplayTemplate(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_IGESGraph_Array1OfTextDisplayTemplate.def(py::init<IGESGraph_Array1OfTextDisplayTemplate &&>(), py::arg("theOther"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def(py::init<const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("begin", (IGESGraph_Array1OfTextDisplayTemplate::iterator (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::begin, "Returns an iterator pointing to the first element in the array.");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("end", (IGESGraph_Array1OfTextDisplayTemplate::iterator (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("cbegin", (IGESGraph_Array1OfTextDisplayTemplate::const_iterator (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("cend", (IGESGraph_Array1OfTextDisplayTemplate::const_iterator (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("Init", (void (IGESGraph_Array1OfTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &)) &IGESGraph_Array1OfTextDisplayTemplate::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("Size", (Standard_Integer (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::Size, "Size query");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("Length", (Standard_Integer (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::Length, "Length query (the same)");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("IsEmpty", (Standard_Boolean (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::IsEmpty, "Return TRUE if array has zero length.");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("Lower", (Standard_Integer (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::Lower, "Lower bound");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("Upper", (Standard_Integer (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::Upper, "Upper bound");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("IsDeletable", (Standard_Boolean (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::IsDeletable, "myDeletable flag");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("IsAllocated", (Standard_Boolean (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("Assign", (IGESGraph_Array1OfTextDisplayTemplate & (IGESGraph_Array1OfTextDisplayTemplate::*)(const IGESGraph_Array1OfTextDisplayTemplate &)) &IGESGraph_Array1OfTextDisplayTemplate::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_IGESGraph_Array1OfTextDisplayTemplate.def("Move", (IGESGraph_Array1OfTextDisplayTemplate & (IGESGraph_Array1OfTextDisplayTemplate::*)(IGESGraph_Array1OfTextDisplayTemplate &&)) &IGESGraph_Array1OfTextDisplayTemplate::Move, "Move assignment", py::arg("theOther"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("assign", (IGESGraph_Array1OfTextDisplayTemplate & (IGESGraph_Array1OfTextDisplayTemplate::*)(const IGESGraph_Array1OfTextDisplayTemplate &)) &IGESGraph_Array1OfTextDisplayTemplate::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_IGESGraph_Array1OfTextDisplayTemplate.def("assign", (IGESGraph_Array1OfTextDisplayTemplate & (IGESGraph_Array1OfTextDisplayTemplate::*)(IGESGraph_Array1OfTextDisplayTemplate &&)) &IGESGraph_Array1OfTextDisplayTemplate::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("First", (const opencascade::handle<IGESGraph_TextDisplayTemplate> & (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::First, "Returns first element");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("ChangeFirst", (opencascade::handle<IGESGraph_TextDisplayTemplate> & (IGESGraph_Array1OfTextDisplayTemplate::*)()) &IGESGraph_Array1OfTextDisplayTemplate::ChangeFirst, "Returns first element");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("Last", (const opencascade::handle<IGESGraph_TextDisplayTemplate> & (IGESGraph_Array1OfTextDisplayTemplate::*)() const ) &IGESGraph_Array1OfTextDisplayTemplate::Last, "Returns last element");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("ChangeLast", (opencascade::handle<IGESGraph_TextDisplayTemplate> & (IGESGraph_Array1OfTextDisplayTemplate::*)()) &IGESGraph_Array1OfTextDisplayTemplate::ChangeLast, "Returns last element");
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("Value", (const opencascade::handle<IGESGraph_TextDisplayTemplate> & (IGESGraph_Array1OfTextDisplayTemplate::*)(const Standard_Integer) const ) &IGESGraph_Array1OfTextDisplayTemplate::Value, "Constant value access", py::arg("theIndex"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("__call__", (const opencascade::handle<IGESGraph_TextDisplayTemplate> & (IGESGraph_Array1OfTextDisplayTemplate::*)(const Standard_Integer) const ) &IGESGraph_Array1OfTextDisplayTemplate::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("ChangeValue", (opencascade::handle<IGESGraph_TextDisplayTemplate> & (IGESGraph_Array1OfTextDisplayTemplate::*)(const Standard_Integer)) &IGESGraph_Array1OfTextDisplayTemplate::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("__call__", (opencascade::handle<IGESGraph_TextDisplayTemplate> & (IGESGraph_Array1OfTextDisplayTemplate::*)(const Standard_Integer)) &IGESGraph_Array1OfTextDisplayTemplate::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("SetValue", (void (IGESGraph_Array1OfTextDisplayTemplate::*)(const Standard_Integer, const opencascade::handle<IGESGraph_TextDisplayTemplate> &)) &IGESGraph_Array1OfTextDisplayTemplate::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("Resize", (void (IGESGraph_Array1OfTextDisplayTemplate::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &IGESGraph_Array1OfTextDisplayTemplate::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_IGESGraph_Array1OfTextDisplayTemplate.def("__iter__", [](const IGESGraph_Array1OfTextDisplayTemplate &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<IGESGraph_Array1OfTextFontDef, std::unique_ptr<IGESGraph_Array1OfTextFontDef, Deleter<IGESGraph_Array1OfTextFontDef>>> cls_IGESGraph_Array1OfTextFontDef(mod, "IGESGraph_Array1OfTextFontDef", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_IGESGraph_Array1OfTextFontDef.def(py::init<>());
	cls_IGESGraph_Array1OfTextFontDef.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESGraph_Array1OfTextFontDef.def(py::init([] (const IGESGraph_Array1OfTextFontDef &other) {return new IGESGraph_Array1OfTextFontDef(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_IGESGraph_Array1OfTextFontDef.def(py::init<IGESGraph_Array1OfTextFontDef &&>(), py::arg("theOther"));
	cls_IGESGraph_Array1OfTextFontDef.def(py::init<const opencascade::handle<IGESGraph_TextFontDef> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESGraph_Array1OfTextFontDef.def("begin", (IGESGraph_Array1OfTextFontDef::iterator (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::begin, "Returns an iterator pointing to the first element in the array.");
	cls_IGESGraph_Array1OfTextFontDef.def("end", (IGESGraph_Array1OfTextFontDef::iterator (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_IGESGraph_Array1OfTextFontDef.def("cbegin", (IGESGraph_Array1OfTextFontDef::const_iterator (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_IGESGraph_Array1OfTextFontDef.def("cend", (IGESGraph_Array1OfTextFontDef::const_iterator (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_IGESGraph_Array1OfTextFontDef.def("Init", (void (IGESGraph_Array1OfTextFontDef::*)(const opencascade::handle<IGESGraph_TextFontDef> &)) &IGESGraph_Array1OfTextFontDef::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_IGESGraph_Array1OfTextFontDef.def("Size", (Standard_Integer (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::Size, "Size query");
	cls_IGESGraph_Array1OfTextFontDef.def("Length", (Standard_Integer (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::Length, "Length query (the same)");
	cls_IGESGraph_Array1OfTextFontDef.def("IsEmpty", (Standard_Boolean (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::IsEmpty, "Return TRUE if array has zero length.");
	cls_IGESGraph_Array1OfTextFontDef.def("Lower", (Standard_Integer (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::Lower, "Lower bound");
	cls_IGESGraph_Array1OfTextFontDef.def("Upper", (Standard_Integer (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::Upper, "Upper bound");
	cls_IGESGraph_Array1OfTextFontDef.def("IsDeletable", (Standard_Boolean (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::IsDeletable, "myDeletable flag");
	cls_IGESGraph_Array1OfTextFontDef.def("IsAllocated", (Standard_Boolean (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_IGESGraph_Array1OfTextFontDef.def("Assign", (IGESGraph_Array1OfTextFontDef & (IGESGraph_Array1OfTextFontDef::*)(const IGESGraph_Array1OfTextFontDef &)) &IGESGraph_Array1OfTextFontDef::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_IGESGraph_Array1OfTextFontDef.def("Move", (IGESGraph_Array1OfTextFontDef & (IGESGraph_Array1OfTextFontDef::*)(IGESGraph_Array1OfTextFontDef &&)) &IGESGraph_Array1OfTextFontDef::Move, "Move assignment", py::arg("theOther"));
	cls_IGESGraph_Array1OfTextFontDef.def("assign", (IGESGraph_Array1OfTextFontDef & (IGESGraph_Array1OfTextFontDef::*)(const IGESGraph_Array1OfTextFontDef &)) &IGESGraph_Array1OfTextFontDef::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_IGESGraph_Array1OfTextFontDef.def("assign", (IGESGraph_Array1OfTextFontDef & (IGESGraph_Array1OfTextFontDef::*)(IGESGraph_Array1OfTextFontDef &&)) &IGESGraph_Array1OfTextFontDef::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_IGESGraph_Array1OfTextFontDef.def("First", (const opencascade::handle<IGESGraph_TextFontDef> & (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::First, "Returns first element");
	cls_IGESGraph_Array1OfTextFontDef.def("ChangeFirst", (opencascade::handle<IGESGraph_TextFontDef> & (IGESGraph_Array1OfTextFontDef::*)()) &IGESGraph_Array1OfTextFontDef::ChangeFirst, "Returns first element");
	cls_IGESGraph_Array1OfTextFontDef.def("Last", (const opencascade::handle<IGESGraph_TextFontDef> & (IGESGraph_Array1OfTextFontDef::*)() const ) &IGESGraph_Array1OfTextFontDef::Last, "Returns last element");
	cls_IGESGraph_Array1OfTextFontDef.def("ChangeLast", (opencascade::handle<IGESGraph_TextFontDef> & (IGESGraph_Array1OfTextFontDef::*)()) &IGESGraph_Array1OfTextFontDef::ChangeLast, "Returns last element");
	cls_IGESGraph_Array1OfTextFontDef.def("Value", (const opencascade::handle<IGESGraph_TextFontDef> & (IGESGraph_Array1OfTextFontDef::*)(const Standard_Integer) const ) &IGESGraph_Array1OfTextFontDef::Value, "Constant value access", py::arg("theIndex"));
	cls_IGESGraph_Array1OfTextFontDef.def("__call__", (const opencascade::handle<IGESGraph_TextFontDef> & (IGESGraph_Array1OfTextFontDef::*)(const Standard_Integer) const ) &IGESGraph_Array1OfTextFontDef::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_IGESGraph_Array1OfTextFontDef.def("ChangeValue", (opencascade::handle<IGESGraph_TextFontDef> & (IGESGraph_Array1OfTextFontDef::*)(const Standard_Integer)) &IGESGraph_Array1OfTextFontDef::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_IGESGraph_Array1OfTextFontDef.def("__call__", (opencascade::handle<IGESGraph_TextFontDef> & (IGESGraph_Array1OfTextFontDef::*)(const Standard_Integer)) &IGESGraph_Array1OfTextFontDef::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_IGESGraph_Array1OfTextFontDef.def("SetValue", (void (IGESGraph_Array1OfTextFontDef::*)(const Standard_Integer, const opencascade::handle<IGESGraph_TextFontDef> &)) &IGESGraph_Array1OfTextFontDef::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_IGESGraph_Array1OfTextFontDef.def("Resize", (void (IGESGraph_Array1OfTextFontDef::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &IGESGraph_Array1OfTextFontDef::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_IGESGraph_Array1OfTextFontDef.def("__iter__", [](const IGESGraph_Array1OfTextFontDef &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_Color.hxx
	py::class_<IGESGraph_Color, opencascade::handle<IGESGraph_Color>, IGESData_ColorEntity> cls_IGESGraph_Color(mod, "IGESGraph_Color", "defines IGESColor, Type <314> Form <0> in package IGESGraph");
	cls_IGESGraph_Color.def(py::init<>());
	cls_IGESGraph_Color.def("Init", (void (IGESGraph_Color::*)(const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &)) &IGESGraph_Color::Init, "This method is used to set the fields of the class Color - red : Red color intensity (range 0.0 to 100.0) - green : Green color intensity (range 0.0 to 100.0) - blue : Blue color intensity (range 0.0 to 100.0) - aColorName : Name of the color (optional)", py::arg("red"), py::arg("green"), py::arg("blue"), py::arg("aColorName"));
	cls_IGESGraph_Color.def("RGBIntensity", (void (IGESGraph_Color::*)(Standard_Real &, Standard_Real &, Standard_Real &) const ) &IGESGraph_Color::RGBIntensity, "None", py::arg("Red"), py::arg("Green"), py::arg("Blue"));
	cls_IGESGraph_Color.def("CMYIntensity", (void (IGESGraph_Color::*)(Standard_Real &, Standard_Real &, Standard_Real &) const ) &IGESGraph_Color::CMYIntensity, "None", py::arg("Cyan"), py::arg("Magenta"), py::arg("Yellow"));
	cls_IGESGraph_Color.def("HLSPercentage", (void (IGESGraph_Color::*)(Standard_Real &, Standard_Real &, Standard_Real &) const ) &IGESGraph_Color::HLSPercentage, "None", py::arg("Hue"), py::arg("Lightness"), py::arg("Saturation"));
	cls_IGESGraph_Color.def("HasColorName", (Standard_Boolean (IGESGraph_Color::*)() const ) &IGESGraph_Color::HasColorName, "returns True if optional character string is assigned, False otherwise.");
	cls_IGESGraph_Color.def("ColorName", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_Color::*)() const ) &IGESGraph_Color::ColorName, "if HasColorName() is True returns the Verbal description of the Color.");
	cls_IGESGraph_Color.def_static("get_type_name_", (const char * (*)()) &IGESGraph_Color::get_type_name, "None");
	cls_IGESGraph_Color.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_Color::get_type_descriptor, "None");
	cls_IGESGraph_Color.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_Color::*)() const ) &IGESGraph_Color::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<IGESGraph_Array1OfColor, std::unique_ptr<IGESGraph_Array1OfColor, Deleter<IGESGraph_Array1OfColor>>> cls_IGESGraph_Array1OfColor(mod, "IGESGraph_Array1OfColor", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_IGESGraph_Array1OfColor.def(py::init<>());
	cls_IGESGraph_Array1OfColor.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESGraph_Array1OfColor.def(py::init([] (const IGESGraph_Array1OfColor &other) {return new IGESGraph_Array1OfColor(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_IGESGraph_Array1OfColor.def(py::init<IGESGraph_Array1OfColor &&>(), py::arg("theOther"));
	cls_IGESGraph_Array1OfColor.def(py::init<const opencascade::handle<IGESGraph_Color> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESGraph_Array1OfColor.def("begin", (IGESGraph_Array1OfColor::iterator (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::begin, "Returns an iterator pointing to the first element in the array.");
	cls_IGESGraph_Array1OfColor.def("end", (IGESGraph_Array1OfColor::iterator (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_IGESGraph_Array1OfColor.def("cbegin", (IGESGraph_Array1OfColor::const_iterator (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_IGESGraph_Array1OfColor.def("cend", (IGESGraph_Array1OfColor::const_iterator (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_IGESGraph_Array1OfColor.def("Init", (void (IGESGraph_Array1OfColor::*)(const opencascade::handle<IGESGraph_Color> &)) &IGESGraph_Array1OfColor::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_IGESGraph_Array1OfColor.def("Size", (Standard_Integer (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::Size, "Size query");
	cls_IGESGraph_Array1OfColor.def("Length", (Standard_Integer (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::Length, "Length query (the same)");
	cls_IGESGraph_Array1OfColor.def("IsEmpty", (Standard_Boolean (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::IsEmpty, "Return TRUE if array has zero length.");
	cls_IGESGraph_Array1OfColor.def("Lower", (Standard_Integer (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::Lower, "Lower bound");
	cls_IGESGraph_Array1OfColor.def("Upper", (Standard_Integer (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::Upper, "Upper bound");
	cls_IGESGraph_Array1OfColor.def("IsDeletable", (Standard_Boolean (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::IsDeletable, "myDeletable flag");
	cls_IGESGraph_Array1OfColor.def("IsAllocated", (Standard_Boolean (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_IGESGraph_Array1OfColor.def("Assign", (IGESGraph_Array1OfColor & (IGESGraph_Array1OfColor::*)(const IGESGraph_Array1OfColor &)) &IGESGraph_Array1OfColor::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_IGESGraph_Array1OfColor.def("Move", (IGESGraph_Array1OfColor & (IGESGraph_Array1OfColor::*)(IGESGraph_Array1OfColor &&)) &IGESGraph_Array1OfColor::Move, "Move assignment", py::arg("theOther"));
	cls_IGESGraph_Array1OfColor.def("assign", (IGESGraph_Array1OfColor & (IGESGraph_Array1OfColor::*)(const IGESGraph_Array1OfColor &)) &IGESGraph_Array1OfColor::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_IGESGraph_Array1OfColor.def("assign", (IGESGraph_Array1OfColor & (IGESGraph_Array1OfColor::*)(IGESGraph_Array1OfColor &&)) &IGESGraph_Array1OfColor::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_IGESGraph_Array1OfColor.def("First", (const opencascade::handle<IGESGraph_Color> & (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::First, "Returns first element");
	cls_IGESGraph_Array1OfColor.def("ChangeFirst", (opencascade::handle<IGESGraph_Color> & (IGESGraph_Array1OfColor::*)()) &IGESGraph_Array1OfColor::ChangeFirst, "Returns first element");
	cls_IGESGraph_Array1OfColor.def("Last", (const opencascade::handle<IGESGraph_Color> & (IGESGraph_Array1OfColor::*)() const ) &IGESGraph_Array1OfColor::Last, "Returns last element");
	cls_IGESGraph_Array1OfColor.def("ChangeLast", (opencascade::handle<IGESGraph_Color> & (IGESGraph_Array1OfColor::*)()) &IGESGraph_Array1OfColor::ChangeLast, "Returns last element");
	cls_IGESGraph_Array1OfColor.def("Value", (const opencascade::handle<IGESGraph_Color> & (IGESGraph_Array1OfColor::*)(const Standard_Integer) const ) &IGESGraph_Array1OfColor::Value, "Constant value access", py::arg("theIndex"));
	cls_IGESGraph_Array1OfColor.def("__call__", (const opencascade::handle<IGESGraph_Color> & (IGESGraph_Array1OfColor::*)(const Standard_Integer) const ) &IGESGraph_Array1OfColor::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_IGESGraph_Array1OfColor.def("ChangeValue", (opencascade::handle<IGESGraph_Color> & (IGESGraph_Array1OfColor::*)(const Standard_Integer)) &IGESGraph_Array1OfColor::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_IGESGraph_Array1OfColor.def("__call__", (opencascade::handle<IGESGraph_Color> & (IGESGraph_Array1OfColor::*)(const Standard_Integer)) &IGESGraph_Array1OfColor::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_IGESGraph_Array1OfColor.def("SetValue", (void (IGESGraph_Array1OfColor::*)(const Standard_Integer, const opencascade::handle<IGESGraph_Color> &)) &IGESGraph_Array1OfColor::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_IGESGraph_Array1OfColor.def("Resize", (void (IGESGraph_Array1OfColor::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &IGESGraph_Array1OfColor::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_IGESGraph_Array1OfColor.def("__iter__", [](const IGESGraph_Array1OfColor &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_Protocol.hxx
	py::class_<IGESGraph_Protocol, opencascade::handle<IGESGraph_Protocol>, IGESData_Protocol> cls_IGESGraph_Protocol(mod, "IGESGraph_Protocol", "Description of Protocol for IGESGraph");
	cls_IGESGraph_Protocol.def(py::init<>());
	cls_IGESGraph_Protocol.def("NbResources", (Standard_Integer (IGESGraph_Protocol::*)() const ) &IGESGraph_Protocol::NbResources, "Gives the count of Resource Protocol. Here, one (Protocol from IGESBasic)");
	cls_IGESGraph_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESGraph_Protocol::*)(const Standard_Integer) const ) &IGESGraph_Protocol::Resource, "Returns a Resource, given a rank.", py::arg("num"));
	cls_IGESGraph_Protocol.def("TypeNumber", (Standard_Integer (IGESGraph_Protocol::*)(const opencascade::handle<Standard_Type> &) const ) &IGESGraph_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type This Case Number is then used in Libraries : the various Modules attached to this class of Protocol must use them in accordance (for a given value of TypeNumber, they must consider the same Type as the Protocol defines)", py::arg("atype"));
	cls_IGESGraph_Protocol.def_static("get_type_name_", (const char * (*)()) &IGESGraph_Protocol::get_type_name, "None");
	cls_IGESGraph_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_Protocol::get_type_descriptor, "None");
	cls_IGESGraph_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_Protocol::*)() const ) &IGESGraph_Protocol::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_LineFontDefTemplate.hxx
	py::class_<IGESGraph_LineFontDefTemplate, opencascade::handle<IGESGraph_LineFontDefTemplate>, IGESData_LineFontEntity> cls_IGESGraph_LineFontDefTemplate(mod, "IGESGraph_LineFontDefTemplate", "defines IGESLineFontDefTemplate, Type <304> Form <1> in package IGESGraph");
	cls_IGESGraph_LineFontDefTemplate.def(py::init<>());
	cls_IGESGraph_LineFontDefTemplate.def("Init", (void (IGESGraph_LineFontDefTemplate::*)(const Standard_Integer, const opencascade::handle<IGESBasic_SubfigureDef> &, const Standard_Real, const Standard_Real)) &IGESGraph_LineFontDefTemplate::Init, "This method is used to set the fields of the class LineFontDefTemplate - anOrientation : Orientation of Template figure on anchoring curve - aTemplate : SubfigureDef entity used as Template figure - aDistance : Distance between the neighbouring Template figures - aScale : Scale factor applied to the Template figure", py::arg("anOrientation"), py::arg("aTemplate"), py::arg("aDistance"), py::arg("aScale"));
	cls_IGESGraph_LineFontDefTemplate.def("Orientation", (Standard_Integer (IGESGraph_LineFontDefTemplate::*)() const ) &IGESGraph_LineFontDefTemplate::Orientation, "if return value = 0, Each Template display is oriented by aligning the axis of the SubfigureDef with the axis of the definition space of the anchoring curve. = 1, Each Template display is oriented by aligning X-axis of the SubfigureDef with the tangent vector of the anchoring curve at the point of incidence of the curve and the origin of subfigure. Similarly Z-axis is aligned.");
	cls_IGESGraph_LineFontDefTemplate.def("TemplateEntity", (opencascade::handle<IGESBasic_SubfigureDef> (IGESGraph_LineFontDefTemplate::*)() const ) &IGESGraph_LineFontDefTemplate::TemplateEntity, "returns SubfigureDef as the Entity used as Template figure.");
	cls_IGESGraph_LineFontDefTemplate.def("Distance", (Standard_Real (IGESGraph_LineFontDefTemplate::*)() const ) &IGESGraph_LineFontDefTemplate::Distance, "returns the Distance between any two Template figures on the anchoring curve.");
	cls_IGESGraph_LineFontDefTemplate.def("Scale", (Standard_Real (IGESGraph_LineFontDefTemplate::*)() const ) &IGESGraph_LineFontDefTemplate::Scale, "returns the Scaling factor applied to SubfigureDef to form Template figure.");
	cls_IGESGraph_LineFontDefTemplate.def_static("get_type_name_", (const char * (*)()) &IGESGraph_LineFontDefTemplate::get_type_name, "None");
	cls_IGESGraph_LineFontDefTemplate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_LineFontDefTemplate::get_type_descriptor, "None");
	cls_IGESGraph_LineFontDefTemplate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_LineFontDefTemplate::*)() const ) &IGESGraph_LineFontDefTemplate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_LineFontDefPattern.hxx
	py::class_<IGESGraph_LineFontDefPattern, opencascade::handle<IGESGraph_LineFontDefPattern>, IGESData_LineFontEntity> cls_IGESGraph_LineFontDefPattern(mod, "IGESGraph_LineFontDefPattern", "defines IGESLineFontDefPattern, Type <304> Form <2> in package IGESGraph");
	cls_IGESGraph_LineFontDefPattern.def(py::init<>());
	cls_IGESGraph_LineFontDefPattern.def("Init", (void (IGESGraph_LineFontDefPattern::*)(const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESGraph_LineFontDefPattern::Init, "This method is used to set the fields of the class LineFontDefPattern - allSegLength : Containing lengths of respective segments - aPattern : HAsciiString indicating visible-blank segments", py::arg("allSegLength"), py::arg("aPattern"));
	cls_IGESGraph_LineFontDefPattern.def("NbSegments", (Standard_Integer (IGESGraph_LineFontDefPattern::*)() const ) &IGESGraph_LineFontDefPattern::NbSegments, "returns the number of segments in the visible-blank pattern");
	cls_IGESGraph_LineFontDefPattern.def("Length", (Standard_Real (IGESGraph_LineFontDefPattern::*)(const Standard_Integer) const ) &IGESGraph_LineFontDefPattern::Length, "returns the Length of Index'th segment of the basic pattern raises exception if Index <= 0 or Index > NbSegments", py::arg("Index"));
	cls_IGESGraph_LineFontDefPattern.def("DisplayPattern", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_LineFontDefPattern::*)() const ) &IGESGraph_LineFontDefPattern::DisplayPattern, "returns the string indicating which segments of the basic pattern are visible and which are blanked. e.g: theNbSegments = 5 and if Bit Pattern = 10110, which means that segments 2, 3 and 5 are visible, whereas segments 1 and 4 are blank. The method returns '2H16' as the HAsciiString. Note: The bits are right justified. (16h = 10110)");
	cls_IGESGraph_LineFontDefPattern.def("IsVisible", (Standard_Boolean (IGESGraph_LineFontDefPattern::*)(const Standard_Integer) const ) &IGESGraph_LineFontDefPattern::IsVisible, "The Display Pattern is decrypted to return True if the Index'th basic pattern is Visible, False otherwise. If Index > NbSegments or Index <= 0 then return value is False.", py::arg("Index"));
	cls_IGESGraph_LineFontDefPattern.def_static("get_type_name_", (const char * (*)()) &IGESGraph_LineFontDefPattern::get_type_name, "None");
	cls_IGESGraph_LineFontDefPattern.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_LineFontDefPattern::get_type_descriptor, "None");
	cls_IGESGraph_LineFontDefPattern.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_LineFontDefPattern::*)() const ) &IGESGraph_LineFontDefPattern::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_DefinitionLevel.hxx
	py::class_<IGESGraph_DefinitionLevel, opencascade::handle<IGESGraph_DefinitionLevel>, IGESData_LevelListEntity> cls_IGESGraph_DefinitionLevel(mod, "IGESGraph_DefinitionLevel", "defines IGESDefinitionLevel, Type <406> Form <1> in package IGESGraph");
	cls_IGESGraph_DefinitionLevel.def(py::init<>());
	cls_IGESGraph_DefinitionLevel.def("Init", (void (IGESGraph_DefinitionLevel::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESGraph_DefinitionLevel::Init, "This method is used to set the fields of the class DefinitionLevel - allLevelNumbers : Values of Level Numbers", py::arg("allLevelNumbers"));
	cls_IGESGraph_DefinitionLevel.def("NbPropertyValues", (Standard_Integer (IGESGraph_DefinitionLevel::*)() const ) &IGESGraph_DefinitionLevel::NbPropertyValues, "returns the number of property values in <me>");
	cls_IGESGraph_DefinitionLevel.def("NbLevelNumbers", (Standard_Integer (IGESGraph_DefinitionLevel::*)() const ) &IGESGraph_DefinitionLevel::NbLevelNumbers, "Must return the count of levels (== NbPropertyValues)");
	cls_IGESGraph_DefinitionLevel.def("LevelNumber", (Standard_Integer (IGESGraph_DefinitionLevel::*)(const Standard_Integer) const ) &IGESGraph_DefinitionLevel::LevelNumber, "returns the Level Number of <me> indicated by <LevelIndex> raises an exception if LevelIndex is <= 0 or LevelIndex > NbPropertyValues", py::arg("LevelIndex"));
	cls_IGESGraph_DefinitionLevel.def_static("get_type_name_", (const char * (*)()) &IGESGraph_DefinitionLevel::get_type_name, "None");
	cls_IGESGraph_DefinitionLevel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_DefinitionLevel::get_type_descriptor, "None");
	cls_IGESGraph_DefinitionLevel.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_DefinitionLevel::*)() const ) &IGESGraph_DefinitionLevel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_NominalSize.hxx
	py::class_<IGESGraph_NominalSize, opencascade::handle<IGESGraph_NominalSize>, IGESData_IGESEntity> cls_IGESGraph_NominalSize(mod, "IGESGraph_NominalSize", "defines IGESNominalSize, Type <406> Form <13> in package IGESGraph");
	cls_IGESGraph_NominalSize.def(py::init<>());
	cls_IGESGraph_NominalSize.def("Init", (void (IGESGraph_NominalSize::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESGraph_NominalSize::Init, "This method is used to set the fields of the class NominalSize - nbProps : Number of property values (2 or 3) - aNominalSizeValue : NominalSize Value - aNominalSizeName : NominalSize Name - aStandardName : Name of relevant engineering standard", py::arg("nbProps"), py::arg("aNominalSizeValue"), py::arg("aNominalSizeName"), py::arg("aStandardName"));
	cls_IGESGraph_NominalSize.def("NbPropertyValues", (Standard_Integer (IGESGraph_NominalSize::*)() const ) &IGESGraph_NominalSize::NbPropertyValues, "returns the number of property values in <me>");
	cls_IGESGraph_NominalSize.def("NominalSizeValue", (Standard_Real (IGESGraph_NominalSize::*)() const ) &IGESGraph_NominalSize::NominalSizeValue, "returns the value of <me>");
	cls_IGESGraph_NominalSize.def("NominalSizeName", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_NominalSize::*)() const ) &IGESGraph_NominalSize::NominalSizeName, "returns the name of <me>");
	cls_IGESGraph_NominalSize.def("HasStandardName", (Standard_Boolean (IGESGraph_NominalSize::*)() const ) &IGESGraph_NominalSize::HasStandardName, "returns True if an engineering Standard is defined for <me> else, returns False");
	cls_IGESGraph_NominalSize.def("StandardName", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_NominalSize::*)() const ) &IGESGraph_NominalSize::StandardName, "returns the name of the relevant engineering standard of <me>");
	cls_IGESGraph_NominalSize.def_static("get_type_name_", (const char * (*)()) &IGESGraph_NominalSize::get_type_name, "None");
	cls_IGESGraph_NominalSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_NominalSize::get_type_descriptor, "None");
	cls_IGESGraph_NominalSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_NominalSize::*)() const ) &IGESGraph_NominalSize::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_DrawingSize.hxx
	py::class_<IGESGraph_DrawingSize, opencascade::handle<IGESGraph_DrawingSize>, IGESData_IGESEntity> cls_IGESGraph_DrawingSize(mod, "IGESGraph_DrawingSize", "defines IGESDrawingSize, Type <406> Form <16> in package IGESGraph");
	cls_IGESGraph_DrawingSize.def(py::init<>());
	cls_IGESGraph_DrawingSize.def("Init", (void (IGESGraph_DrawingSize::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &IGESGraph_DrawingSize::Init, "This method is used to set the fields of the class DrawingSize - nbProps : Number of property values (NP = 2) - aXSize : Extent of Drawing along positive XD axis - aYSize : Extent of Drawing along positive YD axis", py::arg("nbProps"), py::arg("aXSize"), py::arg("aYSize"));
	cls_IGESGraph_DrawingSize.def("NbPropertyValues", (Standard_Integer (IGESGraph_DrawingSize::*)() const ) &IGESGraph_DrawingSize::NbPropertyValues, "returns the number of property values in <me> (NP = 2)");
	cls_IGESGraph_DrawingSize.def("XSize", (Standard_Real (IGESGraph_DrawingSize::*)() const ) &IGESGraph_DrawingSize::XSize, "returns the extent of Drawing along positive XD axis");
	cls_IGESGraph_DrawingSize.def("YSize", (Standard_Real (IGESGraph_DrawingSize::*)() const ) &IGESGraph_DrawingSize::YSize, "returns the extent of Drawing along positive YD axis");
	cls_IGESGraph_DrawingSize.def_static("get_type_name_", (const char * (*)()) &IGESGraph_DrawingSize::get_type_name, "None");
	cls_IGESGraph_DrawingSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_DrawingSize::get_type_descriptor, "None");
	cls_IGESGraph_DrawingSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_DrawingSize::*)() const ) &IGESGraph_DrawingSize::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_DrawingUnits.hxx
	py::class_<IGESGraph_DrawingUnits, opencascade::handle<IGESGraph_DrawingUnits>, IGESData_IGESEntity> cls_IGESGraph_DrawingUnits(mod, "IGESGraph_DrawingUnits", "defines IGESDrawingUnits, Type <406> Form <17> in package IGESGraph");
	cls_IGESGraph_DrawingUnits.def(py::init<>());
	cls_IGESGraph_DrawingUnits.def("Init", (void (IGESGraph_DrawingUnits::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IGESGraph_DrawingUnits::Init, "This method is used to set the fields of the class DrawingUnits - nbProps : Number of property values (NP = 2) - aFlag : DrawingUnits Flag - aUnit : DrawingUnits Name", py::arg("nbProps"), py::arg("aFlag"), py::arg("aUnit"));
	cls_IGESGraph_DrawingUnits.def("NbPropertyValues", (Standard_Integer (IGESGraph_DrawingUnits::*)() const ) &IGESGraph_DrawingUnits::NbPropertyValues, "returns the number of property values in <me>");
	cls_IGESGraph_DrawingUnits.def("Flag", (Standard_Integer (IGESGraph_DrawingUnits::*)() const ) &IGESGraph_DrawingUnits::Flag, "returns the drawing space units of <me>");
	cls_IGESGraph_DrawingUnits.def("Unit", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_DrawingUnits::*)() const ) &IGESGraph_DrawingUnits::Unit, "returns the name of the drawing space units of <me>");
	cls_IGESGraph_DrawingUnits.def("UnitValue", (Standard_Real (IGESGraph_DrawingUnits::*)() const ) &IGESGraph_DrawingUnits::UnitValue, "Computes the value of the unit, in meters, according Flag (same values as for GlobalSection from IGESData)");
	cls_IGESGraph_DrawingUnits.def_static("get_type_name_", (const char * (*)()) &IGESGraph_DrawingUnits::get_type_name, "None");
	cls_IGESGraph_DrawingUnits.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_DrawingUnits::get_type_descriptor, "None");
	cls_IGESGraph_DrawingUnits.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_DrawingUnits::*)() const ) &IGESGraph_DrawingUnits::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_IntercharacterSpacing.hxx
	py::class_<IGESGraph_IntercharacterSpacing, opencascade::handle<IGESGraph_IntercharacterSpacing>, IGESData_IGESEntity> cls_IGESGraph_IntercharacterSpacing(mod, "IGESGraph_IntercharacterSpacing", "defines IGESIntercharacterSpacing, Type <406> Form <18> in package IGESGraph");
	cls_IGESGraph_IntercharacterSpacing.def(py::init<>());
	cls_IGESGraph_IntercharacterSpacing.def("Init", (void (IGESGraph_IntercharacterSpacing::*)(const Standard_Integer, const Standard_Real)) &IGESGraph_IntercharacterSpacing::Init, "This method is used to set the fields of the class IntercharacterSpacing - nbProps : Number of property values (NP = 1) - anISpace : Intercharacter spacing percentage", py::arg("nbProps"), py::arg("anISpace"));
	cls_IGESGraph_IntercharacterSpacing.def("NbPropertyValues", (Standard_Integer (IGESGraph_IntercharacterSpacing::*)() const ) &IGESGraph_IntercharacterSpacing::NbPropertyValues, "returns the number of property values in <me>");
	cls_IGESGraph_IntercharacterSpacing.def("ISpace", (Standard_Real (IGESGraph_IntercharacterSpacing::*)() const ) &IGESGraph_IntercharacterSpacing::ISpace, "returns the Intercharacter Space of <me> in percentage of the text height (Range = 0..100)");
	cls_IGESGraph_IntercharacterSpacing.def_static("get_type_name_", (const char * (*)()) &IGESGraph_IntercharacterSpacing::get_type_name, "None");
	cls_IGESGraph_IntercharacterSpacing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_IntercharacterSpacing::get_type_descriptor, "None");
	cls_IGESGraph_IntercharacterSpacing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_IntercharacterSpacing::*)() const ) &IGESGraph_IntercharacterSpacing::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_LineFontPredefined.hxx
	py::class_<IGESGraph_LineFontPredefined, opencascade::handle<IGESGraph_LineFontPredefined>, IGESData_IGESEntity> cls_IGESGraph_LineFontPredefined(mod, "IGESGraph_LineFontPredefined", "defines IGESLineFontPredefined, Type <406> Form <19> in package IGESGraph");
	cls_IGESGraph_LineFontPredefined.def(py::init<>());
	cls_IGESGraph_LineFontPredefined.def("Init", (void (IGESGraph_LineFontPredefined::*)(const Standard_Integer, const Standard_Integer)) &IGESGraph_LineFontPredefined::Init, "This method is used to set the fields of the class LineFontPredefined - nbProps : Number of property values (NP = 1) - aLineFontPatternCode : Line Font Pattern Code", py::arg("nbProps"), py::arg("aLineFontPatternCode"));
	cls_IGESGraph_LineFontPredefined.def("NbPropertyValues", (Standard_Integer (IGESGraph_LineFontPredefined::*)() const ) &IGESGraph_LineFontPredefined::NbPropertyValues, "returns the number of property values in <me>");
	cls_IGESGraph_LineFontPredefined.def("LineFontPatternCode", (Standard_Integer (IGESGraph_LineFontPredefined::*)() const ) &IGESGraph_LineFontPredefined::LineFontPatternCode, "returns the Line Font Pattern Code of <me>");
	cls_IGESGraph_LineFontPredefined.def_static("get_type_name_", (const char * (*)()) &IGESGraph_LineFontPredefined::get_type_name, "None");
	cls_IGESGraph_LineFontPredefined.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_LineFontPredefined::get_type_descriptor, "None");
	cls_IGESGraph_LineFontPredefined.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_LineFontPredefined::*)() const ) &IGESGraph_LineFontPredefined::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_HighLight.hxx
	py::class_<IGESGraph_HighLight, opencascade::handle<IGESGraph_HighLight>, IGESData_IGESEntity> cls_IGESGraph_HighLight(mod, "IGESGraph_HighLight", "defines IGESHighLight, Type <406> Form <20> in package IGESGraph");
	cls_IGESGraph_HighLight.def(py::init<>());
	cls_IGESGraph_HighLight.def("Init", (void (IGESGraph_HighLight::*)(const Standard_Integer, const Standard_Integer)) &IGESGraph_HighLight::Init, "This method is used to set the fields of the class HighLight - nbProps : Number of property values (NP = 1) - aHighLightStatus : HighLight Flag", py::arg("nbProps"), py::arg("aHighLightStatus"));
	cls_IGESGraph_HighLight.def("NbPropertyValues", (Standard_Integer (IGESGraph_HighLight::*)() const ) &IGESGraph_HighLight::NbPropertyValues, "returns the number of property values in <me>");
	cls_IGESGraph_HighLight.def("HighLightStatus", (Standard_Integer (IGESGraph_HighLight::*)() const ) &IGESGraph_HighLight::HighLightStatus, "returns 0 if <me> is not highlighted(default), 1 if <me> is highlighted");
	cls_IGESGraph_HighLight.def("IsHighLighted", (Standard_Boolean (IGESGraph_HighLight::*)() const ) &IGESGraph_HighLight::IsHighLighted, "returns True if entity is highlighted");
	cls_IGESGraph_HighLight.def_static("get_type_name_", (const char * (*)()) &IGESGraph_HighLight::get_type_name, "None");
	cls_IGESGraph_HighLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_HighLight::get_type_descriptor, "None");
	cls_IGESGraph_HighLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_HighLight::*)() const ) &IGESGraph_HighLight::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_Pick.hxx
	py::class_<IGESGraph_Pick, opencascade::handle<IGESGraph_Pick>, IGESData_IGESEntity> cls_IGESGraph_Pick(mod, "IGESGraph_Pick", "defines IGESPick, Type <406> Form <21> in package IGESGraph");
	cls_IGESGraph_Pick.def(py::init<>());
	cls_IGESGraph_Pick.def("Init", (void (IGESGraph_Pick::*)(const Standard_Integer, const Standard_Integer)) &IGESGraph_Pick::Init, "This method is used to set the fields of the class Pick - nbProps : Number of property values (NP = 1) - aPickStatus : Pick Flag", py::arg("nbProps"), py::arg("aPickStatus"));
	cls_IGESGraph_Pick.def("NbPropertyValues", (Standard_Integer (IGESGraph_Pick::*)() const ) &IGESGraph_Pick::NbPropertyValues, "returns the number of property values in <me>.");
	cls_IGESGraph_Pick.def("PickFlag", (Standard_Integer (IGESGraph_Pick::*)() const ) &IGESGraph_Pick::PickFlag, "returns 0 if <me> is pickable(default), 1 if <me> is not pickable.");
	cls_IGESGraph_Pick.def("IsPickable", (Standard_Boolean (IGESGraph_Pick::*)() const ) &IGESGraph_Pick::IsPickable, "returns True if thePick is 0.");
	cls_IGESGraph_Pick.def_static("get_type_name_", (const char * (*)()) &IGESGraph_Pick::get_type_name, "None");
	cls_IGESGraph_Pick.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_Pick::get_type_descriptor, "None");
	cls_IGESGraph_Pick.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_Pick::*)() const ) &IGESGraph_Pick::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_UniformRectGrid.hxx
	py::class_<IGESGraph_UniformRectGrid, opencascade::handle<IGESGraph_UniformRectGrid>, IGESData_IGESEntity> cls_IGESGraph_UniformRectGrid(mod, "IGESGraph_UniformRectGrid", "defines IGESUniformRectGrid, Type <406> Form <22> in package IGESGraph");
	cls_IGESGraph_UniformRectGrid.def(py::init<>());
	cls_IGESGraph_UniformRectGrid.def("Init", (void (IGESGraph_UniformRectGrid::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const gp_XY &, const gp_XY &, const Standard_Integer, const Standard_Integer)) &IGESGraph_UniformRectGrid::Init, "This method is used to set the fields of the class UniformRectGrid - nbProps : Number of property values (NP = 9) - finite : Finite/Infinite grid flag - line : Line/Point grid flag - weighted : Weighted/Unweighted grid flag - aGridPoint : Point on the grid - aGridSpacing : Grid spacing - pointsX : No. of points/lines in X Direction - pointsY : No. of points/lines in Y Direction", py::arg("nbProps"), py::arg("finite"), py::arg("line"), py::arg("weighted"), py::arg("aGridPoint"), py::arg("aGridSpacing"), py::arg("pointsX"), py::arg("pointsY"));
	cls_IGESGraph_UniformRectGrid.def("NbPropertyValues", (Standard_Integer (IGESGraph_UniformRectGrid::*)() const ) &IGESGraph_UniformRectGrid::NbPropertyValues, "returns the number of property values in <me>.");
	cls_IGESGraph_UniformRectGrid.def("IsFinite", (Standard_Boolean (IGESGraph_UniformRectGrid::*)() const ) &IGESGraph_UniformRectGrid::IsFinite, "returns False if <me> is an infinite grid, True if <me> is a finite grid.");
	cls_IGESGraph_UniformRectGrid.def("IsLine", (Standard_Boolean (IGESGraph_UniformRectGrid::*)() const ) &IGESGraph_UniformRectGrid::IsLine, "returns False if <me> is a Point grid, True if <me> is a Line grid.");
	cls_IGESGraph_UniformRectGrid.def("IsWeighted", (Standard_Boolean (IGESGraph_UniformRectGrid::*)() const ) &IGESGraph_UniformRectGrid::IsWeighted, "returns False if <me> is a Weighted grid, True if <me> is not a Weighted grid.");
	cls_IGESGraph_UniformRectGrid.def("GridPoint", (gp_Pnt2d (IGESGraph_UniformRectGrid::*)() const ) &IGESGraph_UniformRectGrid::GridPoint, "returns coordinates of lower left corner, if <me> is a finite grid, coordinates of an arbitrary point, if <me> is an infinite grid.");
	cls_IGESGraph_UniformRectGrid.def("GridSpacing", (gp_Vec2d (IGESGraph_UniformRectGrid::*)() const ) &IGESGraph_UniformRectGrid::GridSpacing, "returns the grid-spacing in drawing coordinates.");
	cls_IGESGraph_UniformRectGrid.def("NbPointsX", (Standard_Integer (IGESGraph_UniformRectGrid::*)() const ) &IGESGraph_UniformRectGrid::NbPointsX, "returns the no. of points/lines in X direction (only applicable if IsFinite() = 1, i.e: a finite grid).");
	cls_IGESGraph_UniformRectGrid.def("NbPointsY", (Standard_Integer (IGESGraph_UniformRectGrid::*)() const ) &IGESGraph_UniformRectGrid::NbPointsY, "returns the no. of points/lines in Y direction (only applicable if IsFinite() = 1, i.e: a finite grid).");
	cls_IGESGraph_UniformRectGrid.def_static("get_type_name_", (const char * (*)()) &IGESGraph_UniformRectGrid::get_type_name, "None");
	cls_IGESGraph_UniformRectGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_UniformRectGrid::get_type_descriptor, "None");
	cls_IGESGraph_UniformRectGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_UniformRectGrid::*)() const ) &IGESGraph_UniformRectGrid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolLineFontDefTemplate.hxx
	py::class_<IGESGraph_ToolLineFontDefTemplate, std::unique_ptr<IGESGraph_ToolLineFontDefTemplate, Deleter<IGESGraph_ToolLineFontDefTemplate>>> cls_IGESGraph_ToolLineFontDefTemplate(mod, "IGESGraph_ToolLineFontDefTemplate", "Tool to work on a LineFontDefTemplate. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolLineFontDefTemplate.def(py::init<>());
	cls_IGESGraph_ToolLineFontDefTemplate.def("ReadOwnParams", (void (IGESGraph_ToolLineFontDefTemplate::*)(const opencascade::handle<IGESGraph_LineFontDefTemplate> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolLineFontDefTemplate::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolLineFontDefTemplate.def("WriteOwnParams", (void (IGESGraph_ToolLineFontDefTemplate::*)(const opencascade::handle<IGESGraph_LineFontDefTemplate> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolLineFontDefTemplate::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolLineFontDefTemplate.def("OwnShared", (void (IGESGraph_ToolLineFontDefTemplate::*)(const opencascade::handle<IGESGraph_LineFontDefTemplate> &, Interface_EntityIterator &) const ) &IGESGraph_ToolLineFontDefTemplate::OwnShared, "Lists the Entities shared by a LineFontDefTemplate <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolLineFontDefTemplate.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolLineFontDefTemplate::*)(const opencascade::handle<IGESGraph_LineFontDefTemplate> &) const ) &IGESGraph_ToolLineFontDefTemplate::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolLineFontDefTemplate.def("OwnCheck", (void (IGESGraph_ToolLineFontDefTemplate::*)(const opencascade::handle<IGESGraph_LineFontDefTemplate> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolLineFontDefTemplate::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolLineFontDefTemplate.def("OwnCopy", (void (IGESGraph_ToolLineFontDefTemplate::*)(const opencascade::handle<IGESGraph_LineFontDefTemplate> &, const opencascade::handle<IGESGraph_LineFontDefTemplate> &, Interface_CopyTool &) const ) &IGESGraph_ToolLineFontDefTemplate::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolLineFontDefTemplate.def("OwnDump", (void (IGESGraph_ToolLineFontDefTemplate::*)(const opencascade::handle<IGESGraph_LineFontDefTemplate> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolLineFontDefTemplate::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolLineFontDefPattern.hxx
	py::class_<IGESGraph_ToolLineFontDefPattern, std::unique_ptr<IGESGraph_ToolLineFontDefPattern, Deleter<IGESGraph_ToolLineFontDefPattern>>> cls_IGESGraph_ToolLineFontDefPattern(mod, "IGESGraph_ToolLineFontDefPattern", "Tool to work on a LineFontDefPattern. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolLineFontDefPattern.def(py::init<>());
	cls_IGESGraph_ToolLineFontDefPattern.def("ReadOwnParams", (void (IGESGraph_ToolLineFontDefPattern::*)(const opencascade::handle<IGESGraph_LineFontDefPattern> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolLineFontDefPattern::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolLineFontDefPattern.def("WriteOwnParams", (void (IGESGraph_ToolLineFontDefPattern::*)(const opencascade::handle<IGESGraph_LineFontDefPattern> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolLineFontDefPattern::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolLineFontDefPattern.def("OwnShared", (void (IGESGraph_ToolLineFontDefPattern::*)(const opencascade::handle<IGESGraph_LineFontDefPattern> &, Interface_EntityIterator &) const ) &IGESGraph_ToolLineFontDefPattern::OwnShared, "Lists the Entities shared by a LineFontDefPattern <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolLineFontDefPattern.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolLineFontDefPattern::*)(const opencascade::handle<IGESGraph_LineFontDefPattern> &) const ) &IGESGraph_ToolLineFontDefPattern::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolLineFontDefPattern.def("OwnCheck", (void (IGESGraph_ToolLineFontDefPattern::*)(const opencascade::handle<IGESGraph_LineFontDefPattern> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolLineFontDefPattern::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolLineFontDefPattern.def("OwnCopy", (void (IGESGraph_ToolLineFontDefPattern::*)(const opencascade::handle<IGESGraph_LineFontDefPattern> &, const opencascade::handle<IGESGraph_LineFontDefPattern> &, Interface_CopyTool &) const ) &IGESGraph_ToolLineFontDefPattern::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolLineFontDefPattern.def("OwnDump", (void (IGESGraph_ToolLineFontDefPattern::*)(const opencascade::handle<IGESGraph_LineFontDefPattern> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolLineFontDefPattern::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolTextFontDef.hxx
	py::class_<IGESGraph_ToolTextFontDef, std::unique_ptr<IGESGraph_ToolTextFontDef, Deleter<IGESGraph_ToolTextFontDef>>> cls_IGESGraph_ToolTextFontDef(mod, "IGESGraph_ToolTextFontDef", "Tool to work on a TextFontDef. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolTextFontDef.def(py::init<>());
	cls_IGESGraph_ToolTextFontDef.def("ReadOwnParams", (void (IGESGraph_ToolTextFontDef::*)(const opencascade::handle<IGESGraph_TextFontDef> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolTextFontDef::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolTextFontDef.def("WriteOwnParams", (void (IGESGraph_ToolTextFontDef::*)(const opencascade::handle<IGESGraph_TextFontDef> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolTextFontDef::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolTextFontDef.def("OwnShared", (void (IGESGraph_ToolTextFontDef::*)(const opencascade::handle<IGESGraph_TextFontDef> &, Interface_EntityIterator &) const ) &IGESGraph_ToolTextFontDef::OwnShared, "Lists the Entities shared by a TextFontDef <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolTextFontDef.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolTextFontDef::*)(const opencascade::handle<IGESGraph_TextFontDef> &) const ) &IGESGraph_ToolTextFontDef::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolTextFontDef.def("OwnCheck", (void (IGESGraph_ToolTextFontDef::*)(const opencascade::handle<IGESGraph_TextFontDef> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolTextFontDef::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolTextFontDef.def("OwnCopy", (void (IGESGraph_ToolTextFontDef::*)(const opencascade::handle<IGESGraph_TextFontDef> &, const opencascade::handle<IGESGraph_TextFontDef> &, Interface_CopyTool &) const ) &IGESGraph_ToolTextFontDef::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolTextFontDef.def("OwnDump", (void (IGESGraph_ToolTextFontDef::*)(const opencascade::handle<IGESGraph_TextFontDef> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolTextFontDef::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolTextDisplayTemplate.hxx
	py::class_<IGESGraph_ToolTextDisplayTemplate, std::unique_ptr<IGESGraph_ToolTextDisplayTemplate, Deleter<IGESGraph_ToolTextDisplayTemplate>>> cls_IGESGraph_ToolTextDisplayTemplate(mod, "IGESGraph_ToolTextDisplayTemplate", "Tool to work on a TextDisplayTemplate. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolTextDisplayTemplate.def(py::init<>());
	cls_IGESGraph_ToolTextDisplayTemplate.def("ReadOwnParams", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolTextDisplayTemplate::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolTextDisplayTemplate.def("WriteOwnParams", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolTextDisplayTemplate::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolTextDisplayTemplate.def("OwnShared", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, Interface_EntityIterator &) const ) &IGESGraph_ToolTextDisplayTemplate::OwnShared, "Lists the Entities shared by a TextDisplayTemplate <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolTextDisplayTemplate.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &) const ) &IGESGraph_ToolTextDisplayTemplate::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolTextDisplayTemplate.def("OwnCheck", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolTextDisplayTemplate::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolTextDisplayTemplate.def("OwnCopy", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const opencascade::handle<IGESGraph_TextDisplayTemplate> &, Interface_CopyTool &) const ) &IGESGraph_ToolTextDisplayTemplate::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolTextDisplayTemplate.def("OwnDump", (void (IGESGraph_ToolTextDisplayTemplate::*)(const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolTextDisplayTemplate::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolColor.hxx
	py::class_<IGESGraph_ToolColor, std::unique_ptr<IGESGraph_ToolColor, Deleter<IGESGraph_ToolColor>>> cls_IGESGraph_ToolColor(mod, "IGESGraph_ToolColor", "Tool to work on a Color. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolColor.def(py::init<>());
	cls_IGESGraph_ToolColor.def("ReadOwnParams", (void (IGESGraph_ToolColor::*)(const opencascade::handle<IGESGraph_Color> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolColor::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolColor.def("WriteOwnParams", (void (IGESGraph_ToolColor::*)(const opencascade::handle<IGESGraph_Color> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolColor::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolColor.def("OwnShared", (void (IGESGraph_ToolColor::*)(const opencascade::handle<IGESGraph_Color> &, Interface_EntityIterator &) const ) &IGESGraph_ToolColor::OwnShared, "Lists the Entities shared by a Color <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolColor.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolColor::*)(const opencascade::handle<IGESGraph_Color> &) const ) &IGESGraph_ToolColor::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolColor.def("OwnCheck", (void (IGESGraph_ToolColor::*)(const opencascade::handle<IGESGraph_Color> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolColor::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolColor.def("OwnCopy", (void (IGESGraph_ToolColor::*)(const opencascade::handle<IGESGraph_Color> &, const opencascade::handle<IGESGraph_Color> &, Interface_CopyTool &) const ) &IGESGraph_ToolColor::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolColor.def("OwnDump", (void (IGESGraph_ToolColor::*)(const opencascade::handle<IGESGraph_Color> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolColor::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolDefinitionLevel.hxx
	py::class_<IGESGraph_ToolDefinitionLevel, std::unique_ptr<IGESGraph_ToolDefinitionLevel, Deleter<IGESGraph_ToolDefinitionLevel>>> cls_IGESGraph_ToolDefinitionLevel(mod, "IGESGraph_ToolDefinitionLevel", "Tool to work on a DefinitionLevel. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolDefinitionLevel.def(py::init<>());
	cls_IGESGraph_ToolDefinitionLevel.def("ReadOwnParams", (void (IGESGraph_ToolDefinitionLevel::*)(const opencascade::handle<IGESGraph_DefinitionLevel> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolDefinitionLevel::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolDefinitionLevel.def("WriteOwnParams", (void (IGESGraph_ToolDefinitionLevel::*)(const opencascade::handle<IGESGraph_DefinitionLevel> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolDefinitionLevel::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolDefinitionLevel.def("OwnShared", (void (IGESGraph_ToolDefinitionLevel::*)(const opencascade::handle<IGESGraph_DefinitionLevel> &, Interface_EntityIterator &) const ) &IGESGraph_ToolDefinitionLevel::OwnShared, "Lists the Entities shared by a DefinitionLevel <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolDefinitionLevel.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolDefinitionLevel::*)(const opencascade::handle<IGESGraph_DefinitionLevel> &) const ) &IGESGraph_ToolDefinitionLevel::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolDefinitionLevel.def("OwnCheck", (void (IGESGraph_ToolDefinitionLevel::*)(const opencascade::handle<IGESGraph_DefinitionLevel> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolDefinitionLevel::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolDefinitionLevel.def("OwnCopy", (void (IGESGraph_ToolDefinitionLevel::*)(const opencascade::handle<IGESGraph_DefinitionLevel> &, const opencascade::handle<IGESGraph_DefinitionLevel> &, Interface_CopyTool &) const ) &IGESGraph_ToolDefinitionLevel::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolDefinitionLevel.def("OwnDump", (void (IGESGraph_ToolDefinitionLevel::*)(const opencascade::handle<IGESGraph_DefinitionLevel> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolDefinitionLevel::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolNominalSize.hxx
	py::class_<IGESGraph_ToolNominalSize, std::unique_ptr<IGESGraph_ToolNominalSize, Deleter<IGESGraph_ToolNominalSize>>> cls_IGESGraph_ToolNominalSize(mod, "IGESGraph_ToolNominalSize", "Tool to work on a NominalSize. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolNominalSize.def(py::init<>());
	cls_IGESGraph_ToolNominalSize.def("ReadOwnParams", (void (IGESGraph_ToolNominalSize::*)(const opencascade::handle<IGESGraph_NominalSize> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolNominalSize::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolNominalSize.def("WriteOwnParams", (void (IGESGraph_ToolNominalSize::*)(const opencascade::handle<IGESGraph_NominalSize> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolNominalSize::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolNominalSize.def("OwnShared", (void (IGESGraph_ToolNominalSize::*)(const opencascade::handle<IGESGraph_NominalSize> &, Interface_EntityIterator &) const ) &IGESGraph_ToolNominalSize::OwnShared, "Lists the Entities shared by a NominalSize <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolNominalSize.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolNominalSize::*)(const opencascade::handle<IGESGraph_NominalSize> &) const ) &IGESGraph_ToolNominalSize::OwnCorrect, "Sets automatic unambiguous Correction on a NominalSize (NbPropertyValues forced to 2 or 3 according HasStandardName)", py::arg("ent"));
	cls_IGESGraph_ToolNominalSize.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolNominalSize::*)(const opencascade::handle<IGESGraph_NominalSize> &) const ) &IGESGraph_ToolNominalSize::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolNominalSize.def("OwnCheck", (void (IGESGraph_ToolNominalSize::*)(const opencascade::handle<IGESGraph_NominalSize> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolNominalSize::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolNominalSize.def("OwnCopy", (void (IGESGraph_ToolNominalSize::*)(const opencascade::handle<IGESGraph_NominalSize> &, const opencascade::handle<IGESGraph_NominalSize> &, Interface_CopyTool &) const ) &IGESGraph_ToolNominalSize::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolNominalSize.def("OwnDump", (void (IGESGraph_ToolNominalSize::*)(const opencascade::handle<IGESGraph_NominalSize> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolNominalSize::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolDrawingSize.hxx
	py::class_<IGESGraph_ToolDrawingSize, std::unique_ptr<IGESGraph_ToolDrawingSize, Deleter<IGESGraph_ToolDrawingSize>>> cls_IGESGraph_ToolDrawingSize(mod, "IGESGraph_ToolDrawingSize", "Tool to work on a DrawingSize. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolDrawingSize.def(py::init<>());
	cls_IGESGraph_ToolDrawingSize.def("ReadOwnParams", (void (IGESGraph_ToolDrawingSize::*)(const opencascade::handle<IGESGraph_DrawingSize> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolDrawingSize::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolDrawingSize.def("WriteOwnParams", (void (IGESGraph_ToolDrawingSize::*)(const opencascade::handle<IGESGraph_DrawingSize> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolDrawingSize::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolDrawingSize.def("OwnShared", (void (IGESGraph_ToolDrawingSize::*)(const opencascade::handle<IGESGraph_DrawingSize> &, Interface_EntityIterator &) const ) &IGESGraph_ToolDrawingSize::OwnShared, "Lists the Entities shared by a DrawingSize <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolDrawingSize.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolDrawingSize::*)(const opencascade::handle<IGESGraph_DrawingSize> &) const ) &IGESGraph_ToolDrawingSize::OwnCorrect, "Sets automatic unambiguous Correction on a DrawingSize (NbPropertyValues forced to 2)", py::arg("ent"));
	cls_IGESGraph_ToolDrawingSize.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolDrawingSize::*)(const opencascade::handle<IGESGraph_DrawingSize> &) const ) &IGESGraph_ToolDrawingSize::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolDrawingSize.def("OwnCheck", (void (IGESGraph_ToolDrawingSize::*)(const opencascade::handle<IGESGraph_DrawingSize> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolDrawingSize::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolDrawingSize.def("OwnCopy", (void (IGESGraph_ToolDrawingSize::*)(const opencascade::handle<IGESGraph_DrawingSize> &, const opencascade::handle<IGESGraph_DrawingSize> &, Interface_CopyTool &) const ) &IGESGraph_ToolDrawingSize::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolDrawingSize.def("OwnDump", (void (IGESGraph_ToolDrawingSize::*)(const opencascade::handle<IGESGraph_DrawingSize> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolDrawingSize::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolDrawingUnits.hxx
	py::class_<IGESGraph_ToolDrawingUnits, std::unique_ptr<IGESGraph_ToolDrawingUnits, Deleter<IGESGraph_ToolDrawingUnits>>> cls_IGESGraph_ToolDrawingUnits(mod, "IGESGraph_ToolDrawingUnits", "Tool to work on a DrawingUnits. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolDrawingUnits.def(py::init<>());
	cls_IGESGraph_ToolDrawingUnits.def("ReadOwnParams", (void (IGESGraph_ToolDrawingUnits::*)(const opencascade::handle<IGESGraph_DrawingUnits> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolDrawingUnits::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolDrawingUnits.def("WriteOwnParams", (void (IGESGraph_ToolDrawingUnits::*)(const opencascade::handle<IGESGraph_DrawingUnits> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolDrawingUnits::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolDrawingUnits.def("OwnShared", (void (IGESGraph_ToolDrawingUnits::*)(const opencascade::handle<IGESGraph_DrawingUnits> &, Interface_EntityIterator &) const ) &IGESGraph_ToolDrawingUnits::OwnShared, "Lists the Entities shared by a DrawingUnits <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolDrawingUnits.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolDrawingUnits::*)(const opencascade::handle<IGESGraph_DrawingUnits> &) const ) &IGESGraph_ToolDrawingUnits::OwnCorrect, "Sets automatic unambiguous Correction on a DrawingUnits (NbPropertyValues forced to 2)", py::arg("ent"));
	cls_IGESGraph_ToolDrawingUnits.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolDrawingUnits::*)(const opencascade::handle<IGESGraph_DrawingUnits> &) const ) &IGESGraph_ToolDrawingUnits::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolDrawingUnits.def("OwnCheck", (void (IGESGraph_ToolDrawingUnits::*)(const opencascade::handle<IGESGraph_DrawingUnits> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolDrawingUnits::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolDrawingUnits.def("OwnCopy", (void (IGESGraph_ToolDrawingUnits::*)(const opencascade::handle<IGESGraph_DrawingUnits> &, const opencascade::handle<IGESGraph_DrawingUnits> &, Interface_CopyTool &) const ) &IGESGraph_ToolDrawingUnits::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolDrawingUnits.def("OwnDump", (void (IGESGraph_ToolDrawingUnits::*)(const opencascade::handle<IGESGraph_DrawingUnits> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolDrawingUnits::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolIntercharacterSpacing.hxx
	py::class_<IGESGraph_ToolIntercharacterSpacing, std::unique_ptr<IGESGraph_ToolIntercharacterSpacing, Deleter<IGESGraph_ToolIntercharacterSpacing>>> cls_IGESGraph_ToolIntercharacterSpacing(mod, "IGESGraph_ToolIntercharacterSpacing", "Tool to work on a IntercharacterSpacing. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolIntercharacterSpacing.def(py::init<>());
	cls_IGESGraph_ToolIntercharacterSpacing.def("ReadOwnParams", (void (IGESGraph_ToolIntercharacterSpacing::*)(const opencascade::handle<IGESGraph_IntercharacterSpacing> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolIntercharacterSpacing::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolIntercharacterSpacing.def("WriteOwnParams", (void (IGESGraph_ToolIntercharacterSpacing::*)(const opencascade::handle<IGESGraph_IntercharacterSpacing> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolIntercharacterSpacing::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolIntercharacterSpacing.def("OwnShared", (void (IGESGraph_ToolIntercharacterSpacing::*)(const opencascade::handle<IGESGraph_IntercharacterSpacing> &, Interface_EntityIterator &) const ) &IGESGraph_ToolIntercharacterSpacing::OwnShared, "Lists the Entities shared by a IntercharacterSpacing <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolIntercharacterSpacing.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolIntercharacterSpacing::*)(const opencascade::handle<IGESGraph_IntercharacterSpacing> &) const ) &IGESGraph_ToolIntercharacterSpacing::OwnCorrect, "Sets automatic unambiguous Correction on a IntercharacterSpacing (NbPropertyValues forced to 1)", py::arg("ent"));
	cls_IGESGraph_ToolIntercharacterSpacing.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolIntercharacterSpacing::*)(const opencascade::handle<IGESGraph_IntercharacterSpacing> &) const ) &IGESGraph_ToolIntercharacterSpacing::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolIntercharacterSpacing.def("OwnCheck", (void (IGESGraph_ToolIntercharacterSpacing::*)(const opencascade::handle<IGESGraph_IntercharacterSpacing> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolIntercharacterSpacing::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolIntercharacterSpacing.def("OwnCopy", (void (IGESGraph_ToolIntercharacterSpacing::*)(const opencascade::handle<IGESGraph_IntercharacterSpacing> &, const opencascade::handle<IGESGraph_IntercharacterSpacing> &, Interface_CopyTool &) const ) &IGESGraph_ToolIntercharacterSpacing::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolIntercharacterSpacing.def("OwnDump", (void (IGESGraph_ToolIntercharacterSpacing::*)(const opencascade::handle<IGESGraph_IntercharacterSpacing> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolIntercharacterSpacing::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolLineFontPredefined.hxx
	py::class_<IGESGraph_ToolLineFontPredefined, std::unique_ptr<IGESGraph_ToolLineFontPredefined, Deleter<IGESGraph_ToolLineFontPredefined>>> cls_IGESGraph_ToolLineFontPredefined(mod, "IGESGraph_ToolLineFontPredefined", "Tool to work on a LineFontPredefined. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolLineFontPredefined.def(py::init<>());
	cls_IGESGraph_ToolLineFontPredefined.def("ReadOwnParams", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolLineFontPredefined::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolLineFontPredefined.def("WriteOwnParams", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolLineFontPredefined::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolLineFontPredefined.def("OwnShared", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, Interface_EntityIterator &) const ) &IGESGraph_ToolLineFontPredefined::OwnShared, "Lists the Entities shared by a LineFontPredefined <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolLineFontPredefined.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &) const ) &IGESGraph_ToolLineFontPredefined::OwnCorrect, "Sets automatic unambiguous Correction on a LineFontPredefined (NbPropertyValues forced to 1)", py::arg("ent"));
	cls_IGESGraph_ToolLineFontPredefined.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &) const ) &IGESGraph_ToolLineFontPredefined::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolLineFontPredefined.def("OwnCheck", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolLineFontPredefined::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolLineFontPredefined.def("OwnCopy", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, const opencascade::handle<IGESGraph_LineFontPredefined> &, Interface_CopyTool &) const ) &IGESGraph_ToolLineFontPredefined::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolLineFontPredefined.def("OwnDump", (void (IGESGraph_ToolLineFontPredefined::*)(const opencascade::handle<IGESGraph_LineFontPredefined> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolLineFontPredefined::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolHighLight.hxx
	py::class_<IGESGraph_ToolHighLight, std::unique_ptr<IGESGraph_ToolHighLight, Deleter<IGESGraph_ToolHighLight>>> cls_IGESGraph_ToolHighLight(mod, "IGESGraph_ToolHighLight", "Tool to work on a HighLight. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolHighLight.def(py::init<>());
	cls_IGESGraph_ToolHighLight.def("ReadOwnParams", (void (IGESGraph_ToolHighLight::*)(const opencascade::handle<IGESGraph_HighLight> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolHighLight::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolHighLight.def("WriteOwnParams", (void (IGESGraph_ToolHighLight::*)(const opencascade::handle<IGESGraph_HighLight> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolHighLight::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolHighLight.def("OwnShared", (void (IGESGraph_ToolHighLight::*)(const opencascade::handle<IGESGraph_HighLight> &, Interface_EntityIterator &) const ) &IGESGraph_ToolHighLight::OwnShared, "Lists the Entities shared by a HighLight <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolHighLight.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolHighLight::*)(const opencascade::handle<IGESGraph_HighLight> &) const ) &IGESGraph_ToolHighLight::OwnCorrect, "Sets automatic unambiguous Correction on a HighLight (NbPropertyValues forced to 1)", py::arg("ent"));
	cls_IGESGraph_ToolHighLight.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolHighLight::*)(const opencascade::handle<IGESGraph_HighLight> &) const ) &IGESGraph_ToolHighLight::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolHighLight.def("OwnCheck", (void (IGESGraph_ToolHighLight::*)(const opencascade::handle<IGESGraph_HighLight> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolHighLight::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolHighLight.def("OwnCopy", (void (IGESGraph_ToolHighLight::*)(const opencascade::handle<IGESGraph_HighLight> &, const opencascade::handle<IGESGraph_HighLight> &, Interface_CopyTool &) const ) &IGESGraph_ToolHighLight::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolHighLight.def("OwnDump", (void (IGESGraph_ToolHighLight::*)(const opencascade::handle<IGESGraph_HighLight> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolHighLight::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolPick.hxx
	py::class_<IGESGraph_ToolPick, std::unique_ptr<IGESGraph_ToolPick, Deleter<IGESGraph_ToolPick>>> cls_IGESGraph_ToolPick(mod, "IGESGraph_ToolPick", "Tool to work on a Pick. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolPick.def(py::init<>());
	cls_IGESGraph_ToolPick.def("ReadOwnParams", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolPick::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolPick.def("WriteOwnParams", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolPick::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolPick.def("OwnShared", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, Interface_EntityIterator &) const ) &IGESGraph_ToolPick::OwnShared, "Lists the Entities shared by a Pick <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolPick.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &) const ) &IGESGraph_ToolPick::OwnCorrect, "Sets automatic unambiguous Correction on a Pick (NbPropertyValues forced to 1)", py::arg("ent"));
	cls_IGESGraph_ToolPick.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &) const ) &IGESGraph_ToolPick::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolPick.def("OwnCheck", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolPick::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolPick.def("OwnCopy", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, const opencascade::handle<IGESGraph_Pick> &, Interface_CopyTool &) const ) &IGESGraph_ToolPick::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolPick.def("OwnDump", (void (IGESGraph_ToolPick::*)(const opencascade::handle<IGESGraph_Pick> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolPick::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ToolUniformRectGrid.hxx
	py::class_<IGESGraph_ToolUniformRectGrid, std::unique_ptr<IGESGraph_ToolUniformRectGrid, Deleter<IGESGraph_ToolUniformRectGrid>>> cls_IGESGraph_ToolUniformRectGrid(mod, "IGESGraph_ToolUniformRectGrid", "Tool to work on a UniformRectGrid. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");
	cls_IGESGraph_ToolUniformRectGrid.def(py::init<>());
	cls_IGESGraph_ToolUniformRectGrid.def("ReadOwnParams", (void (IGESGraph_ToolUniformRectGrid::*)(const opencascade::handle<IGESGraph_UniformRectGrid> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ToolUniformRectGrid::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ToolUniformRectGrid.def("WriteOwnParams", (void (IGESGraph_ToolUniformRectGrid::*)(const opencascade::handle<IGESGraph_UniformRectGrid> &, IGESData_IGESWriter &) const ) &IGESGraph_ToolUniformRectGrid::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ToolUniformRectGrid.def("OwnShared", (void (IGESGraph_ToolUniformRectGrid::*)(const opencascade::handle<IGESGraph_UniformRectGrid> &, Interface_EntityIterator &) const ) &IGESGraph_ToolUniformRectGrid::OwnShared, "Lists the Entities shared by a UniformRectGrid <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_ToolUniformRectGrid.def("OwnCorrect", (Standard_Boolean (IGESGraph_ToolUniformRectGrid::*)(const opencascade::handle<IGESGraph_UniformRectGrid> &) const ) &IGESGraph_ToolUniformRectGrid::OwnCorrect, "Sets automatic unambiguous Correction on a UniformRectGrid (NbPropertyValues forced to 9)", py::arg("ent"));
	cls_IGESGraph_ToolUniformRectGrid.def("DirChecker", (IGESData_DirChecker (IGESGraph_ToolUniformRectGrid::*)(const opencascade::handle<IGESGraph_UniformRectGrid> &) const ) &IGESGraph_ToolUniformRectGrid::DirChecker, "Returns specific DirChecker", py::arg("ent"));
	cls_IGESGraph_ToolUniformRectGrid.def("OwnCheck", (void (IGESGraph_ToolUniformRectGrid::*)(const opencascade::handle<IGESGraph_UniformRectGrid> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_ToolUniformRectGrid::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_ToolUniformRectGrid.def("OwnCopy", (void (IGESGraph_ToolUniformRectGrid::*)(const opencascade::handle<IGESGraph_UniformRectGrid> &, const opencascade::handle<IGESGraph_UniformRectGrid> &, Interface_CopyTool &) const ) &IGESGraph_ToolUniformRectGrid::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_ToolUniformRectGrid.def("OwnDump", (void (IGESGraph_ToolUniformRectGrid::*)(const opencascade::handle<IGESGraph_UniformRectGrid> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_ToolUniformRectGrid::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_ReadWriteModule.hxx
	py::class_<IGESGraph_ReadWriteModule, opencascade::handle<IGESGraph_ReadWriteModule>, IGESData_ReadWriteModule> cls_IGESGraph_ReadWriteModule(mod, "IGESGraph_ReadWriteModule", "Defines Graph File Access Module for IGESGraph (specific parts) Specific actions concern : Read and Write Own Parameters of an IGESEntity.");
	cls_IGESGraph_ReadWriteModule.def(py::init<>());
	cls_IGESGraph_ReadWriteModule.def("CaseIGES", (Standard_Integer (IGESGraph_ReadWriteModule::*)(const Standard_Integer, const Standard_Integer) const ) &IGESGraph_ReadWriteModule::CaseIGES, "Defines Case Numbers for Entities of IGESGraph", py::arg("typenum"), py::arg("formnum"));
	cls_IGESGraph_ReadWriteModule.def("ReadOwnParams", (void (IGESGraph_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const ) &IGESGraph_ReadWriteModule::ReadOwnParams, "Reads own parameters from file for an Entity of IGESGraph", py::arg("CN"), py::arg("ent"), py::arg("IR"), py::arg("PR"));
	cls_IGESGraph_ReadWriteModule.def("WriteOwnParams", (void (IGESGraph_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, IGESData_IGESWriter &) const ) &IGESGraph_ReadWriteModule::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("CN"), py::arg("ent"), py::arg("IW"));
	cls_IGESGraph_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &IGESGraph_ReadWriteModule::get_type_name, "None");
	cls_IGESGraph_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_ReadWriteModule::get_type_descriptor, "None");
	cls_IGESGraph_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_ReadWriteModule::*)() const ) &IGESGraph_ReadWriteModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_GeneralModule.hxx
	py::class_<IGESGraph_GeneralModule, opencascade::handle<IGESGraph_GeneralModule>, IGESData_GeneralModule> cls_IGESGraph_GeneralModule(mod, "IGESGraph_GeneralModule", "Definition of General Services for IGESGraph (specific part) This Services comprise : Shared & Implied Lists, Copy, Check");
	cls_IGESGraph_GeneralModule.def(py::init<>());
	cls_IGESGraph_GeneralModule.def("OwnSharedCase", (void (IGESGraph_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const ) &IGESGraph_GeneralModule::OwnSharedCase, "Lists the Entities shared by a given IGESEntity <ent>, from its specific parameters : specific for each type", py::arg("CN"), py::arg("ent"), py::arg("iter"));
	cls_IGESGraph_GeneralModule.def("DirChecker", (IGESData_DirChecker (IGESGraph_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const ) &IGESGraph_GeneralModule::DirChecker, "Returns a DirChecker, specific for each type of Entity (identified by its Case Number) : this DirChecker defines constraints which must be respected by the DirectoryPart", py::arg("CN"), py::arg("ent"));
	cls_IGESGraph_GeneralModule.def("OwnCheckCase", (void (IGESGraph_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const ) &IGESGraph_GeneralModule::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
	cls_IGESGraph_GeneralModule.def("NewVoid", (Standard_Boolean (IGESGraph_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const ) &IGESGraph_GeneralModule::NewVoid, "Specific creation of a new void entity", py::arg("CN"), py::arg("entto"));
	cls_IGESGraph_GeneralModule.def("OwnCopyCase", (void (IGESGraph_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const ) &IGESGraph_GeneralModule::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
	cls_IGESGraph_GeneralModule.def("CategoryNumber", (Standard_Integer (IGESGraph_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const ) &IGESGraph_GeneralModule::CategoryNumber, "Returns a category number which characterizes an entity Drawing for all", py::arg("CN"), py::arg("ent"), py::arg("shares"));
	cls_IGESGraph_GeneralModule.def_static("get_type_name_", (const char * (*)()) &IGESGraph_GeneralModule::get_type_name, "None");
	cls_IGESGraph_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_GeneralModule::get_type_descriptor, "None");
	cls_IGESGraph_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_GeneralModule::*)() const ) &IGESGraph_GeneralModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_SpecificModule.hxx
	py::class_<IGESGraph_SpecificModule, opencascade::handle<IGESGraph_SpecificModule>, IGESData_SpecificModule> cls_IGESGraph_SpecificModule(mod, "IGESGraph_SpecificModule", "Defines Services attached to IGES Entities : Dump & OwnCorrect, for IGESGraph");
	cls_IGESGraph_SpecificModule.def(py::init<>());
	cls_IGESGraph_SpecificModule.def("OwnDump", (void (IGESGraph_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const ) &IGESGraph_SpecificModule::OwnDump, "Specific Dump (own parameters) for IGESGraph", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
	cls_IGESGraph_SpecificModule.def("OwnCorrect", (Standard_Boolean (IGESGraph_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const ) &IGESGraph_SpecificModule::OwnCorrect, "Performs non-ambiguous Corrections on Entities which support them (DrawingSize,DrawingUnits,HighLight,IntercharacterSpacing, LineFontPredefined,NominalSize,Pick,UniformRectGrid)", py::arg("CN"), py::arg("ent"));
	cls_IGESGraph_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESGraph_SpecificModule::get_type_name, "None");
	cls_IGESGraph_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_SpecificModule::get_type_descriptor, "None");
	cls_IGESGraph_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_SpecificModule::*)() const ) &IGESGraph_SpecificModule::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph.hxx
	py::class_<IGESGraph, std::unique_ptr<IGESGraph, Deleter<IGESGraph>>> cls_IGESGraph(mod, "IGESGraph", "This package contains the group of classes necessary to define Graphic data among Structure Entities. (e.g., Fonts, Colors, Screen management ...)");
	cls_IGESGraph.def(py::init<>());
	cls_IGESGraph.def_static("Init_", (void (*)()) &IGESGraph::Init, "Prepares dynamic data (Protocol, Modules) for this package");
	cls_IGESGraph.def_static("Protocol_", (opencascade::handle<IGESGraph_Protocol> (*)()) &IGESGraph::Protocol, "Returns the Protocol for this Package");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_HArray1OfTextDisplayTemplate.hxx
	py::class_<IGESGraph_HArray1OfTextDisplayTemplate, opencascade::handle<IGESGraph_HArray1OfTextDisplayTemplate>, IGESGraph_Array1OfTextDisplayTemplate, Standard_Transient> cls_IGESGraph_HArray1OfTextDisplayTemplate(mod, "IGESGraph_HArray1OfTextDisplayTemplate", "None");
	cls_IGESGraph_HArray1OfTextDisplayTemplate.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESGraph_HArray1OfTextDisplayTemplate.def(py::init<const Standard_Integer, const Standard_Integer, const IGESGraph_Array1OfTextDisplayTemplate::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_IGESGraph_HArray1OfTextDisplayTemplate.def(py::init<const IGESGraph_Array1OfTextDisplayTemplate &>(), py::arg("theOther"));
	cls_IGESGraph_HArray1OfTextDisplayTemplate.def("Array1", (const IGESGraph_Array1OfTextDisplayTemplate & (IGESGraph_HArray1OfTextDisplayTemplate::*)() const ) &IGESGraph_HArray1OfTextDisplayTemplate::Array1, "None");
	cls_IGESGraph_HArray1OfTextDisplayTemplate.def("ChangeArray1", (IGESGraph_Array1OfTextDisplayTemplate & (IGESGraph_HArray1OfTextDisplayTemplate::*)()) &IGESGraph_HArray1OfTextDisplayTemplate::ChangeArray1, "None");
	cls_IGESGraph_HArray1OfTextDisplayTemplate.def_static("get_type_name_", (const char * (*)()) &IGESGraph_HArray1OfTextDisplayTemplate::get_type_name, "None");
	cls_IGESGraph_HArray1OfTextDisplayTemplate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_HArray1OfTextDisplayTemplate::get_type_descriptor, "None");
	cls_IGESGraph_HArray1OfTextDisplayTemplate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_HArray1OfTextDisplayTemplate::*)() const ) &IGESGraph_HArray1OfTextDisplayTemplate::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_HArray1OfTextFontDef.hxx
	py::class_<IGESGraph_HArray1OfTextFontDef, opencascade::handle<IGESGraph_HArray1OfTextFontDef>, IGESGraph_Array1OfTextFontDef, Standard_Transient> cls_IGESGraph_HArray1OfTextFontDef(mod, "IGESGraph_HArray1OfTextFontDef", "None");
	cls_IGESGraph_HArray1OfTextFontDef.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESGraph_HArray1OfTextFontDef.def(py::init<const Standard_Integer, const Standard_Integer, const IGESGraph_Array1OfTextFontDef::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_IGESGraph_HArray1OfTextFontDef.def(py::init<const IGESGraph_Array1OfTextFontDef &>(), py::arg("theOther"));
	cls_IGESGraph_HArray1OfTextFontDef.def("Array1", (const IGESGraph_Array1OfTextFontDef & (IGESGraph_HArray1OfTextFontDef::*)() const ) &IGESGraph_HArray1OfTextFontDef::Array1, "None");
	cls_IGESGraph_HArray1OfTextFontDef.def("ChangeArray1", (IGESGraph_Array1OfTextFontDef & (IGESGraph_HArray1OfTextFontDef::*)()) &IGESGraph_HArray1OfTextFontDef::ChangeArray1, "None");
	cls_IGESGraph_HArray1OfTextFontDef.def_static("get_type_name_", (const char * (*)()) &IGESGraph_HArray1OfTextFontDef::get_type_name, "None");
	cls_IGESGraph_HArray1OfTextFontDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_HArray1OfTextFontDef::get_type_descriptor, "None");
	cls_IGESGraph_HArray1OfTextFontDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_HArray1OfTextFontDef::*)() const ) &IGESGraph_HArray1OfTextFontDef::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESGraph_HArray1OfColor.hxx
	py::class_<IGESGraph_HArray1OfColor, opencascade::handle<IGESGraph_HArray1OfColor>, IGESGraph_Array1OfColor, Standard_Transient> cls_IGESGraph_HArray1OfColor(mod, "IGESGraph_HArray1OfColor", "None");
	cls_IGESGraph_HArray1OfColor.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_IGESGraph_HArray1OfColor.def(py::init<const Standard_Integer, const Standard_Integer, const IGESGraph_Array1OfColor::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_IGESGraph_HArray1OfColor.def(py::init<const IGESGraph_Array1OfColor &>(), py::arg("theOther"));
	cls_IGESGraph_HArray1OfColor.def("Array1", (const IGESGraph_Array1OfColor & (IGESGraph_HArray1OfColor::*)() const ) &IGESGraph_HArray1OfColor::Array1, "None");
	cls_IGESGraph_HArray1OfColor.def("ChangeArray1", (IGESGraph_Array1OfColor & (IGESGraph_HArray1OfColor::*)()) &IGESGraph_HArray1OfColor::ChangeArray1, "None");
	cls_IGESGraph_HArray1OfColor.def_static("get_type_name_", (const char * (*)()) &IGESGraph_HArray1OfColor::get_type_name, "None");
	cls_IGESGraph_HArray1OfColor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_HArray1OfColor::get_type_descriptor, "None");
	cls_IGESGraph_HArray1OfColor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_HArray1OfColor::*)() const ) &IGESGraph_HArray1OfColor::DynamicType, "None");


}
