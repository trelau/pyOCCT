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
#include <Standard_Std.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Array1.hxx>
#include <IGESDimen_Array1OfGeneralNote.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IGESDimen_HArray1OfGeneralNote.hxx>
#include <IGESDimen_Protocol.hxx>
#include <IGESDimen_CenterLine.hxx>
#include <IGESDimen_Section.hxx>
#include <IGESDimen_WitnessLine.hxx>
#include <IGESDimen_AngularDimension.hxx>
#include <IGESDimen_CurveDimension.hxx>
#include <IGESDimen_DiameterDimension.hxx>
#include <IGESDimen_FlagNote.hxx>
#include <IGESDimen_GeneralLabel.hxx>
#include <IGESDimen_NewGeneralNote.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <IGESDimen_LinearDimension.hxx>
#include <IGESDimen_OrdinateDimension.hxx>
#include <IGESDimen_PointDimension.hxx>
#include <IGESDimen_RadiusDimension.hxx>
#include <IGESDimen_GeneralSymbol.hxx>
#include <IGESDimen_SectionedArea.hxx>
#include <IGESDimen_DimensionedGeometry.hxx>
#include <IGESDimen_NewDimensionedGeometry.hxx>
#include <IGESDimen_DimensionUnits.hxx>
#include <IGESDimen_DimensionTolerance.hxx>
#include <IGESDimen_DimensionDisplayData.hxx>
#include <IGESDimen_BasicDimension.hxx>
#include <IGESDimen_ToolCenterLine.hxx>
#include <IGESDimen_ToolSection.hxx>
#include <IGESDimen_ToolWitnessLine.hxx>
#include <IGESDimen_ToolAngularDimension.hxx>
#include <IGESDimen_ToolCurveDimension.hxx>
#include <IGESDimen_ToolDiameterDimension.hxx>
#include <IGESDimen_ToolFlagNote.hxx>
#include <IGESDimen_ToolGeneralLabel.hxx>
#include <IGESDimen_ToolGeneralNote.hxx>
#include <IGESDimen_ToolNewGeneralNote.hxx>
#include <IGESDimen_ToolLeaderArrow.hxx>
#include <IGESDimen_ToolLinearDimension.hxx>
#include <IGESDimen_ToolOrdinateDimension.hxx>
#include <IGESDimen_ToolPointDimension.hxx>
#include <IGESDimen_ToolRadiusDimension.hxx>
#include <IGESDimen_ToolGeneralSymbol.hxx>
#include <IGESDimen_ToolSectionedArea.hxx>
#include <IGESDimen_ToolDimensionedGeometry.hxx>
#include <IGESDimen_ToolNewDimensionedGeometry.hxx>
#include <IGESDimen_ToolDimensionUnits.hxx>
#include <IGESDimen_ToolDimensionTolerance.hxx>
#include <IGESDimen_ToolDimensionDisplayData.hxx>
#include <IGESDimen_ToolBasicDimension.hxx>
#include <IGESDimen_ReadWriteModule.hxx>
#include <IGESDimen_GeneralModule.hxx>
#include <IGESDimen_SpecificModule.hxx>
#include <IGESDimen.hxx>
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <IGESDimen_Array1OfLeaderArrow.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESDimen_HArray1OfLeaderArrow.hxx>
#include <gp_XYZ.hxx>
#include <IGESData_GeneralModule.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESGeom_CircularArc.hxx>
#include <IGESGeom_CompositeCurve.hxx>
#include <IGESData_Protocol.hxx>
#include <Interface_Protocol.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <IGESData_SpecificModule.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <bind_NCollection_Array1.hxx>

PYBIND11_MODULE(IGESDimen, mod) {

py::module::import("OCCT.IGESData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.IGESGraph");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Interface");
py::module::import("OCCT.gp");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.IGESGeom");
py::module::import("OCCT.Message");

// CLASS: IGESDIMEN_GENERALNOTE
py::class_<IGESDimen_GeneralNote, opencascade::handle<IGESDimen_GeneralNote>, IGESData_IGESEntity> cls_IGESDimen_GeneralNote(mod, "IGESDimen_GeneralNote", "defines GeneralNote, Type <212> Form <0-8, 100-200, 105> in package IGESDimen Used for formatting boxed text in different ways");

// Constructors
cls_IGESDimen_GeneralNote.def(py::init<>());

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

// TYPEDEF: IGESDIMEN_ARRAY1OFGENERALNOTE
bind_NCollection_Array1<opencascade::handle<IGESDimen_GeneralNote> >(mod, "IGESDimen_Array1OfGeneralNote", py::module_local(false));

// CLASS: IGESDIMEN_HARRAY1OFGENERALNOTE
py::class_<IGESDimen_HArray1OfGeneralNote, opencascade::handle<IGESDimen_HArray1OfGeneralNote>, Standard_Transient> cls_IGESDimen_HArray1OfGeneralNote(mod, "IGESDimen_HArray1OfGeneralNote", "None", py::multiple_inheritance());

// Constructors
cls_IGESDimen_HArray1OfGeneralNote.def(py::init<>());
cls_IGESDimen_HArray1OfGeneralNote.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESDimen_HArray1OfGeneralNote.def(py::init<const Standard_Integer, const Standard_Integer, const IGESDimen_Array1OfGeneralNote::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESDimen_HArray1OfGeneralNote.def(py::init<const IGESDimen_Array1OfGeneralNote &>(), py::arg("theOther"));

// Methods
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_HArray1OfGeneralNote::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator delete_", (void (*)(void *)) &IGESDimen_HArray1OfGeneralNote::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_HArray1OfGeneralNote::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_HArray1OfGeneralNote::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_HArray1OfGeneralNote::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_HArray1OfGeneralNote::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDimen_HArray1OfGeneralNote::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDimen_HArray1OfGeneralNote::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESDimen_HArray1OfGeneralNote.def("Array1", (const IGESDimen_Array1OfGeneralNote & (IGESDimen_HArray1OfGeneralNote::*)() const) &IGESDimen_HArray1OfGeneralNote::Array1, "None");
cls_IGESDimen_HArray1OfGeneralNote.def("ChangeArray1", (IGESDimen_Array1OfGeneralNote & (IGESDimen_HArray1OfGeneralNote::*)()) &IGESDimen_HArray1OfGeneralNote::ChangeArray1, "None");
cls_IGESDimen_HArray1OfGeneralNote.def_static("get_type_name_", (const char * (*)()) &IGESDimen_HArray1OfGeneralNote::get_type_name, "None");
cls_IGESDimen_HArray1OfGeneralNote.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_HArray1OfGeneralNote::get_type_descriptor, "None");
cls_IGESDimen_HArray1OfGeneralNote.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_HArray1OfGeneralNote::*)() const) &IGESDimen_HArray1OfGeneralNote::DynamicType, "None");

// CLASS: IGESDIMEN
py::class_<IGESDimen> cls_IGESDimen(mod, "IGESDimen", "This package represents Entities applied to Dimensions ie. Annotation Entities and attached Properties and Associativities.");

// Constructors
cls_IGESDimen.def(py::init<>());

// Methods
// cls_IGESDimen.def_static("operator new_", (void * (*)(size_t)) &IGESDimen::operator new, "None", py::arg("theSize"));
// cls_IGESDimen.def_static("operator delete_", (void (*)(void *)) &IGESDimen::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen.def_static("Init_", (void (*)()) &IGESDimen::Init, "Prepares dynamic data (Protocol, Modules) for this package");
cls_IGESDimen.def_static("Protocol_", (opencascade::handle<IGESDimen_Protocol> (*)()) &IGESDimen::Protocol, "Returns the Protocol for this Package");

// CLASS: IGESDIMEN_ANGULARDIMENSION
py::class_<IGESDimen_AngularDimension, opencascade::handle<IGESDimen_AngularDimension>, IGESData_IGESEntity> cls_IGESDimen_AngularDimension(mod, "IGESDimen_AngularDimension", "defines AngularDimension, Type <202> Form <0> in package IGESDimen Used to dimension angles");

// Constructors
cls_IGESDimen_AngularDimension.def(py::init<>());

// Methods
cls_IGESDimen_AngularDimension.def("Init", (void (IGESDimen_AngularDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESDimen_WitnessLine> &, const gp_XY &, const Standard_Real, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_LeaderArrow> &)) &IGESDimen_AngularDimension::Init, "This method is used to set the fields of the class AngularDimension - aNote : General Note Entity - aLine : First Witness Line Entity or Null Handle - anotherLine : Second Witness Line Entity or Null Handle - aVertex : Coordinates of vertex point - aRadius : Radius of leader arcs - aLeader : First Leader Entity - anotherLeader : Second Leader Entity", py::arg("aNote"), py::arg("aLine"), py::arg("anotherLine"), py::arg("aVertex"), py::arg("aRadius"), py::arg("aLeader"), py::arg("anotherLeader"));
cls_IGESDimen_AngularDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::Note, "returns the General Note Entity of the Dimension.");
cls_IGESDimen_AngularDimension.def("HasFirstWitnessLine", (Standard_Boolean (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::HasFirstWitnessLine, "returns False if theFirstWitnessLine is Null Handle.");
cls_IGESDimen_AngularDimension.def("FirstWitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::FirstWitnessLine, "returns the First Witness Line Entity or Null Handle.");
cls_IGESDimen_AngularDimension.def("HasSecondWitnessLine", (Standard_Boolean (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::HasSecondWitnessLine, "returns False if theSecondWitnessLine is Null Handle.");
cls_IGESDimen_AngularDimension.def("SecondWitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::SecondWitnessLine, "returns the Second Witness Line Entity or Null Handle.");
cls_IGESDimen_AngularDimension.def("Vertex", (gp_Pnt2d (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::Vertex, "returns the co-ordinates of the Vertex point as Pnt2d from gp.");
cls_IGESDimen_AngularDimension.def("TransformedVertex", (gp_Pnt2d (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::TransformedVertex, "returns the co-ordinates of the Vertex point as Pnt2d from gp after Transformation. (Z = 0.0 for Transformation)");
cls_IGESDimen_AngularDimension.def("Radius", (Standard_Real (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::Radius, "returns the Radius of the Leader arcs.");
cls_IGESDimen_AngularDimension.def("FirstLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::FirstLeader, "returns the First Leader Entity.");
cls_IGESDimen_AngularDimension.def("SecondLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::SecondLeader, "returns the Second Leader Entity.");
cls_IGESDimen_AngularDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_AngularDimension::get_type_name, "None");
cls_IGESDimen_AngularDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_AngularDimension::get_type_descriptor, "None");
cls_IGESDimen_AngularDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_AngularDimension::*)() const) &IGESDimen_AngularDimension::DynamicType, "None");

// CLASS: IGESDIMEN_LEADERARROW
py::class_<IGESDimen_LeaderArrow, opencascade::handle<IGESDimen_LeaderArrow>, IGESData_IGESEntity> cls_IGESDimen_LeaderArrow(mod, "IGESDimen_LeaderArrow", "defines LeaderArrow, Type <214> Form <1-12> in package IGESDimen Consists of one or more line segments except when leader is part of an angular dimension, with links to presumed text item");

// Constructors
cls_IGESDimen_LeaderArrow.def(py::init<>());

// Methods
cls_IGESDimen_LeaderArrow.def("Init", (void (IGESDimen_LeaderArrow::*)(const Standard_Real, const Standard_Real, const Standard_Real, const gp_XY &, const opencascade::handle<TColgp_HArray1OfXY> &)) &IGESDimen_LeaderArrow::Init, "This method is used to set the fields of the class LeaderArrow - height : ArrowHead height - width : ArrowHead width - depth : Z Depth - position : ArrowHead coordinates - segments : Segment tail coordinate pairs", py::arg("height"), py::arg("width"), py::arg("depth"), py::arg("position"), py::arg("segments"));
cls_IGESDimen_LeaderArrow.def("SetFormNumber", (void (IGESDimen_LeaderArrow::*)(const Standard_Integer)) &IGESDimen_LeaderArrow::SetFormNumber, "Changes FormNumber (indicates the Shape of the Arrow) Error if not in range [0-12]", py::arg("form"));
cls_IGESDimen_LeaderArrow.def("NbSegments", (Standard_Integer (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::NbSegments, "returns number of segments");
cls_IGESDimen_LeaderArrow.def("ArrowHeadHeight", (Standard_Real (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::ArrowHeadHeight, "returns ArrowHead height");
cls_IGESDimen_LeaderArrow.def("ArrowHeadWidth", (Standard_Real (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::ArrowHeadWidth, "returns ArrowHead width");
cls_IGESDimen_LeaderArrow.def("ZDepth", (Standard_Real (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::ZDepth, "returns Z depth");
cls_IGESDimen_LeaderArrow.def("ArrowHead", (gp_Pnt2d (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::ArrowHead, "returns ArrowHead co-ordinates");
cls_IGESDimen_LeaderArrow.def("TransformedArrowHead", (gp_Pnt (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::TransformedArrowHead, "returns ArrowHead co-ordinates after Transformation");
cls_IGESDimen_LeaderArrow.def("SegmentTail", (gp_Pnt2d (IGESDimen_LeaderArrow::*)(const Standard_Integer) const) &IGESDimen_LeaderArrow::SegmentTail, "returns segment tail co-ordinates. raises exception if Index <= 0 or Index > NbSegments", py::arg("Index"));
cls_IGESDimen_LeaderArrow.def("TransformedSegmentTail", (gp_Pnt (IGESDimen_LeaderArrow::*)(const Standard_Integer) const) &IGESDimen_LeaderArrow::TransformedSegmentTail, "returns segment tail co-ordinates after Transformation. raises exception if Index <= 0 or Index > NbSegments", py::arg("Index"));
cls_IGESDimen_LeaderArrow.def_static("get_type_name_", (const char * (*)()) &IGESDimen_LeaderArrow::get_type_name, "None");
cls_IGESDimen_LeaderArrow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_LeaderArrow::get_type_descriptor, "None");
cls_IGESDimen_LeaderArrow.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_LeaderArrow::*)() const) &IGESDimen_LeaderArrow::DynamicType, "None");

// TYPEDEF: IGESDIMEN_ARRAY1OFLEADERARROW
bind_NCollection_Array1<opencascade::handle<IGESDimen_LeaderArrow> >(mod, "IGESDimen_Array1OfLeaderArrow", py::module_local(false));

// CLASS: IGESDIMEN_BASICDIMENSION
py::class_<IGESDimen_BasicDimension, opencascade::handle<IGESDimen_BasicDimension>, IGESData_IGESEntity> cls_IGESDimen_BasicDimension(mod, "IGESDimen_BasicDimension", "Defines IGES Basic Dimension, Type 406, Form 31, in package IGESDimen The basic Dimension Property indicates that the referencing dimension entity is to be displayed with a box around text.");

// Constructors
cls_IGESDimen_BasicDimension.def(py::init<>());

// Methods
cls_IGESDimen_BasicDimension.def("Init", (void (IGESDimen_BasicDimension::*)(const Standard_Integer, const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &)) &IGESDimen_BasicDimension::Init, "None", py::arg("nbPropVal"), py::arg("lowerLeft"), py::arg("lowerRight"), py::arg("upperRight"), py::arg("upperLeft"));
cls_IGESDimen_BasicDimension.def("NbPropertyValues", (Standard_Integer (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::NbPropertyValues, "returns the number of properties = 8");
cls_IGESDimen_BasicDimension.def("LowerLeft", (gp_Pnt2d (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::LowerLeft, "returns coordinates of lower left corner");
cls_IGESDimen_BasicDimension.def("LowerRight", (gp_Pnt2d (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::LowerRight, "returns coordinates of lower right corner");
cls_IGESDimen_BasicDimension.def("UpperRight", (gp_Pnt2d (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::UpperRight, "returns coordinates of upper right corner");
cls_IGESDimen_BasicDimension.def("UpperLeft", (gp_Pnt2d (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::UpperLeft, "returns coordinates of upper left corner");
cls_IGESDimen_BasicDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_BasicDimension::get_type_name, "None");
cls_IGESDimen_BasicDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_BasicDimension::get_type_descriptor, "None");
cls_IGESDimen_BasicDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_BasicDimension::*)() const) &IGESDimen_BasicDimension::DynamicType, "None");

// CLASS: IGESDIMEN_CENTERLINE
py::class_<IGESDimen_CenterLine, opencascade::handle<IGESDimen_CenterLine>, IGESData_IGESEntity> cls_IGESDimen_CenterLine(mod, "IGESDimen_CenterLine", "defines CenterLine, Type <106> Form <20-21> in package IGESDimen Is an entity appearing as crosshairs or as a construction between 2 positions");

// Constructors
cls_IGESDimen_CenterLine.def(py::init<>());

// Methods
cls_IGESDimen_CenterLine.def("Init", (void (IGESDimen_CenterLine::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<TColgp_HArray1OfXY> &)) &IGESDimen_CenterLine::Init, "This method is used to set the fields of the class CenterLine - aDataType : Interpretation Flag, always = 1 - aZDisplacement : Common z displacement - dataPnts : Data points (x and y)", py::arg("aDataType"), py::arg("aZdisp"), py::arg("dataPnts"));
cls_IGESDimen_CenterLine.def("SetCrossHair", (void (IGESDimen_CenterLine::*)(const Standard_Boolean)) &IGESDimen_CenterLine::SetCrossHair, "Sets FormNumber to 20 if <mode> is True, 21 else", py::arg("mode"));
cls_IGESDimen_CenterLine.def("Datatype", (Standard_Integer (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::Datatype, "returns Interpretation Flag : IP = 1.");
cls_IGESDimen_CenterLine.def("NbPoints", (Standard_Integer (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::NbPoints, "returns Number of Data Points.");
cls_IGESDimen_CenterLine.def("ZDisplacement", (Standard_Real (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::ZDisplacement, "returns Common Z displacement.");
cls_IGESDimen_CenterLine.def("Point", (gp_Pnt (IGESDimen_CenterLine::*)(const Standard_Integer) const) &IGESDimen_CenterLine::Point, "returns the data point as Pnt from gp. raises exception if Index <= 0 or Index > NbPoints()", py::arg("Index"));
cls_IGESDimen_CenterLine.def("TransformedPoint", (gp_Pnt (IGESDimen_CenterLine::*)(const Standard_Integer) const) &IGESDimen_CenterLine::TransformedPoint, "returns the data point as Pnt from gp after Transformation. raises exception if Index <= 0 or Index > NbPoints()", py::arg("Index"));
cls_IGESDimen_CenterLine.def("IsCrossHair", (Standard_Boolean (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::IsCrossHair, "returns True if Form is 20.");
cls_IGESDimen_CenterLine.def_static("get_type_name_", (const char * (*)()) &IGESDimen_CenterLine::get_type_name, "None");
cls_IGESDimen_CenterLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_CenterLine::get_type_descriptor, "None");
cls_IGESDimen_CenterLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_CenterLine::*)() const) &IGESDimen_CenterLine::DynamicType, "None");

// CLASS: IGESDIMEN_CURVEDIMENSION
py::class_<IGESDimen_CurveDimension, opencascade::handle<IGESDimen_CurveDimension>, IGESData_IGESEntity> cls_IGESDimen_CurveDimension(mod, "IGESDimen_CurveDimension", "defines CurveDimension, Type <204> Form <0> in package IGESDimen Used to dimension curves Consists of one tail segment of nonzero length beginning with an arrowhead and which serves to define the orientation");

// Constructors
cls_IGESDimen_CurveDimension.def(py::init<>());

// Methods
cls_IGESDimen_CurveDimension.def("Init", (void (IGESDimen_CurveDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESDimen_WitnessLine> &)) &IGESDimen_CurveDimension::Init, "This method is used to set the fields of the class CurveDimension - aNote : General Note Entity - aCurve : First Curve Entity - anotherCurve : Second Curve Entity or a Null Handle - aLeader : First Leader Entity - anotherLeader : Second Leader Entity - aLine : First Witness Line Entity or a Null Handle - anotherLine : Second Witness Line Entity or a Null Handle", py::arg("aNote"), py::arg("aCurve"), py::arg("anotherCurve"), py::arg("aLeader"), py::arg("anotherLeader"), py::arg("aLine"), py::arg("anotherLine"));
cls_IGESDimen_CurveDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::Note, "returns the General Note Entity");
cls_IGESDimen_CurveDimension.def("FirstCurve", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::FirstCurve, "returns the First curve Entity");
cls_IGESDimen_CurveDimension.def("HasSecondCurve", (Standard_Boolean (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::HasSecondCurve, "returns False if theSecondCurve is a Null Handle.");
cls_IGESDimen_CurveDimension.def("SecondCurve", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::SecondCurve, "returns the Second curve Entity or a Null Handle.");
cls_IGESDimen_CurveDimension.def("FirstLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::FirstLeader, "returns the First Leader Entity");
cls_IGESDimen_CurveDimension.def("SecondLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::SecondLeader, "returns the Second Leader Entity");
cls_IGESDimen_CurveDimension.def("HasFirstWitnessLine", (Standard_Boolean (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::HasFirstWitnessLine, "returns False if theFirstWitnessLine is a Null Handle.");
cls_IGESDimen_CurveDimension.def("FirstWitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::FirstWitnessLine, "returns the First Witness Line Entity or a Null Handle.");
cls_IGESDimen_CurveDimension.def("HasSecondWitnessLine", (Standard_Boolean (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::HasSecondWitnessLine, "returns False if theSecondWitnessLine is a Null Handle.");
cls_IGESDimen_CurveDimension.def("SecondWitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::SecondWitnessLine, "returns the Second Witness Line Entity or a Null Handle.");
cls_IGESDimen_CurveDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_CurveDimension::get_type_name, "None");
cls_IGESDimen_CurveDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_CurveDimension::get_type_descriptor, "None");
cls_IGESDimen_CurveDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_CurveDimension::*)() const) &IGESDimen_CurveDimension::DynamicType, "None");

// CLASS: IGESDIMEN_DIAMETERDIMENSION
py::class_<IGESDimen_DiameterDimension, opencascade::handle<IGESDimen_DiameterDimension>, IGESData_IGESEntity> cls_IGESDimen_DiameterDimension(mod, "IGESDimen_DiameterDimension", "defines DiameterDimension, Type <206> Form <0> in package IGESDimen Used for dimensioning diameters");

// Constructors
cls_IGESDimen_DiameterDimension.def(py::init<>());

// Methods
cls_IGESDimen_DiameterDimension.def("Init", (void (IGESDimen_DiameterDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const gp_XY &)) &IGESDimen_DiameterDimension::Init, "This method is used to set the fields of the class DiameterDimension - aNote : General Note Entity - aLeader : First Leader Entity - anotherLeader : Second Leader Entity or a Null Handle. - aCenter : Arc center coordinates", py::arg("aNote"), py::arg("aLeader"), py::arg("anotherLeader"), py::arg("aCenter"));
cls_IGESDimen_DiameterDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::Note, "returns the General Note Entity");
cls_IGESDimen_DiameterDimension.def("FirstLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::FirstLeader, "returns the First Leader Entity");
cls_IGESDimen_DiameterDimension.def("HasSecondLeader", (Standard_Boolean (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::HasSecondLeader, "returns False if theSecondleader is a Null Handle.");
cls_IGESDimen_DiameterDimension.def("SecondLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::SecondLeader, "returns the Second Leader Entity");
cls_IGESDimen_DiameterDimension.def("Center", (gp_Pnt2d (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::Center, "returns the Arc Center co-ordinates as Pnt2d from package gp");
cls_IGESDimen_DiameterDimension.def("TransformedCenter", (gp_Pnt2d (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::TransformedCenter, "returns the Arc Center co-ordinates as Pnt2d from package gp after Transformation. (Z = 0.0 for Transformation)");
cls_IGESDimen_DiameterDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DiameterDimension::get_type_name, "None");
cls_IGESDimen_DiameterDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DiameterDimension::get_type_descriptor, "None");
cls_IGESDimen_DiameterDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DiameterDimension::*)() const) &IGESDimen_DiameterDimension::DynamicType, "None");

// CLASS: IGESDIMEN_DIMENSIONDISPLAYDATA
py::class_<IGESDimen_DimensionDisplayData, opencascade::handle<IGESDimen_DimensionDisplayData>, IGESData_IGESEntity> cls_IGESDimen_DimensionDisplayData(mod, "IGESDimen_DimensionDisplayData", "Defines IGES Dimension Display Data, Type <406> Form <30>, in package IGESDimen The Dimensional Display Data Property is optional but when present must be referenced by a dimension entity. The information it contains could be extracted from the text, leader and witness line data with difficulty.");

// Constructors
cls_IGESDimen_DimensionDisplayData.def(py::init<>());

// Methods
cls_IGESDimen_DimensionDisplayData.def("Init", (void (IGESDimen_DimensionDisplayData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESDimen_DimensionDisplayData::Init, "None", py::arg("numProps"), py::arg("aDimType"), py::arg("aLabelPos"), py::arg("aCharSet"), py::arg("aString"), py::arg("aSymbol"), py::arg("anAng"), py::arg("anAlign"), py::arg("aLevel"), py::arg("aPlace"), py::arg("anOrient"), py::arg("initVal"), py::arg("notes"), py::arg("startInd"), py::arg("endInd"));
cls_IGESDimen_DimensionDisplayData.def("NbPropertyValues", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::NbPropertyValues, "returns the number of property values (14)");
cls_IGESDimen_DimensionDisplayData.def("DimensionType", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::DimensionType, "returns the dimension type");
cls_IGESDimen_DimensionDisplayData.def("LabelPosition", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::LabelPosition, "returns the preferred label position");
cls_IGESDimen_DimensionDisplayData.def("CharacterSet", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::CharacterSet, "returns the character set interpretation");
cls_IGESDimen_DimensionDisplayData.def("LString", (opencascade::handle<TCollection_HAsciiString> (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::LString, "returns e.g., 8HDIAMETER");
cls_IGESDimen_DimensionDisplayData.def("DecimalSymbol", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::DecimalSymbol, "None");
cls_IGESDimen_DimensionDisplayData.def("WitnessLineAngle", (Standard_Real (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::WitnessLineAngle, "returns the witness line angle in radians");
cls_IGESDimen_DimensionDisplayData.def("TextAlignment", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::TextAlignment, "returns the text alignment");
cls_IGESDimen_DimensionDisplayData.def("TextLevel", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::TextLevel, "returns the text level");
cls_IGESDimen_DimensionDisplayData.def("TextPlacement", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::TextPlacement, "returns the preferred text placement");
cls_IGESDimen_DimensionDisplayData.def("ArrowHeadOrientation", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::ArrowHeadOrientation, "returns the arrowhead orientation");
cls_IGESDimen_DimensionDisplayData.def("InitialValue", (Standard_Real (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::InitialValue, "returns the primary dimension initial value");
cls_IGESDimen_DimensionDisplayData.def("NbSupplementaryNotes", (Standard_Integer (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::NbSupplementaryNotes, "returns the number of supplementary notes or zero");
cls_IGESDimen_DimensionDisplayData.def("SupplementaryNote", (Standard_Integer (IGESDimen_DimensionDisplayData::*)(const Standard_Integer) const) &IGESDimen_DimensionDisplayData::SupplementaryNote, "returns the Index'th supplementary note raises exception if Index <= 0 or Index > NbSupplementaryNotes()", py::arg("Index"));
cls_IGESDimen_DimensionDisplayData.def("StartIndex", (Standard_Integer (IGESDimen_DimensionDisplayData::*)(const Standard_Integer) const) &IGESDimen_DimensionDisplayData::StartIndex, "returns the Index'th note start index raises exception if Index <= 0 or Index > NbSupplementaryNotes()", py::arg("Index"));
cls_IGESDimen_DimensionDisplayData.def("EndIndex", (Standard_Integer (IGESDimen_DimensionDisplayData::*)(const Standard_Integer) const) &IGESDimen_DimensionDisplayData::EndIndex, "returns the Index'th note end index raises exception if Index <= 0 or Index > NbSupplemetaryNotes()", py::arg("Index"));
cls_IGESDimen_DimensionDisplayData.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DimensionDisplayData::get_type_name, "None");
cls_IGESDimen_DimensionDisplayData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DimensionDisplayData::get_type_descriptor, "None");
cls_IGESDimen_DimensionDisplayData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DimensionDisplayData::*)() const) &IGESDimen_DimensionDisplayData::DynamicType, "None");

// CLASS: IGESDIMEN_DIMENSIONEDGEOMETRY
py::class_<IGESDimen_DimensionedGeometry, opencascade::handle<IGESDimen_DimensionedGeometry>, IGESData_IGESEntity> cls_IGESDimen_DimensionedGeometry(mod, "IGESDimen_DimensionedGeometry", "Defines IGES Dimensioned Geometry, Type <402> Form <13>, in package IGESDimen This entity has been replaced by the new form of Dimensioned Geometry Associativity Entity (Type 402, Form 21) and should no longer be used by preprocessors.");

// Constructors
cls_IGESDimen_DimensionedGeometry.def(py::init<>());

// Methods
cls_IGESDimen_DimensionedGeometry.def("Init", (void (IGESDimen_DimensionedGeometry::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDimen_DimensionedGeometry::Init, "None", py::arg("nbDims"), py::arg("aDimension"), py::arg("entities"));
cls_IGESDimen_DimensionedGeometry.def("NbDimensions", (Standard_Integer (IGESDimen_DimensionedGeometry::*)() const) &IGESDimen_DimensionedGeometry::NbDimensions, "returns the number of dimensions");
cls_IGESDimen_DimensionedGeometry.def("NbGeometryEntities", (Standard_Integer (IGESDimen_DimensionedGeometry::*)() const) &IGESDimen_DimensionedGeometry::NbGeometryEntities, "returns the number of associated geometry entities");
cls_IGESDimen_DimensionedGeometry.def("DimensionEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_DimensionedGeometry::*)() const) &IGESDimen_DimensionedGeometry::DimensionEntity, "returns the Dimension entity");
cls_IGESDimen_DimensionedGeometry.def("GeometryEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_DimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_DimensionedGeometry::GeometryEntity, "returns the num'th Geometry entity raises exception if Index <= 0 or Index > NbGeometryEntities()", py::arg("Index"));
cls_IGESDimen_DimensionedGeometry.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DimensionedGeometry::get_type_name, "None");
cls_IGESDimen_DimensionedGeometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DimensionedGeometry::get_type_descriptor, "None");
cls_IGESDimen_DimensionedGeometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DimensionedGeometry::*)() const) &IGESDimen_DimensionedGeometry::DynamicType, "None");

// CLASS: IGESDIMEN_DIMENSIONTOLERANCE
py::class_<IGESDimen_DimensionTolerance, opencascade::handle<IGESDimen_DimensionTolerance>, IGESData_IGESEntity> cls_IGESDimen_DimensionTolerance(mod, "IGESDimen_DimensionTolerance", "defines Dimension Tolerance, Type <406>, Form <29> in package IGESDimen Provides tolerance information for a dimension which can be used by the receiving system to regenerate the dimension.");

// Constructors
cls_IGESDimen_DimensionTolerance.def(py::init<>());

// Methods
cls_IGESDimen_DimensionTolerance.def("Init", (void (IGESDimen_DimensionTolerance::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Integer)) &IGESDimen_DimensionTolerance::Init, "This method is used to set the fields of the class DimensionTolerance - nbPropVal : Number of property values, default = 8 - aSecTolFlag : Secondary Tolerance Flag 0 = Applies to primary dimension 1 = Applies to secondary dimension 2 = Display values as fractions - aTolType : Tolerance Type 1 = Bilateral 2 = Upper/Lower 3 = Unilateral Upper 4 = Unilateral Lower 5 = Range - min before max 6 = Range - min after max 7 = Range - min above max 8 = Range - min below max 9 = Nominal + Range - min above max 10 = Nominal + Range - min below max - aTolPlaceFlag : Tolerance Placement Flag 1 = Before nominal value 2 = After nominal value 3 = Above nominal value 4 = Below nominal value - anUpperTol : Upper Tolerance - aLowerTol : Lower Tolerance - aSignFlag : Sign Suppression Flag - aFracFlag : Fraction Flag 0 = Display values as decimal numbers 1 = Display values as mixed fractions 2 = Display values as fractions - aPrecision : Precision Value", py::arg("nbPropVal"), py::arg("aSecTolFlag"), py::arg("aTolType"), py::arg("aTolPlaceFlag"), py::arg("anUpperTol"), py::arg("aLowerTol"), py::arg("aSignFlag"), py::arg("aFracFlag"), py::arg("aPrecision"));
cls_IGESDimen_DimensionTolerance.def("NbPropertyValues", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::NbPropertyValues, "returns the number of property values, always = 8");
cls_IGESDimen_DimensionTolerance.def("SecondaryToleranceFlag", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::SecondaryToleranceFlag, "returns the Secondary Tolerance Flag");
cls_IGESDimen_DimensionTolerance.def("ToleranceType", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::ToleranceType, "returns the Tolerance Type");
cls_IGESDimen_DimensionTolerance.def("TolerancePlacementFlag", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::TolerancePlacementFlag, "returns the Tolerance Placement Flag, default = 2");
cls_IGESDimen_DimensionTolerance.def("UpperTolerance", (Standard_Real (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::UpperTolerance, "returns the Upper or Bilateral Tolerance Value");
cls_IGESDimen_DimensionTolerance.def("LowerTolerance", (Standard_Real (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::LowerTolerance, "returns the Lower Tolerance Value");
cls_IGESDimen_DimensionTolerance.def("SignSuppressionFlag", (Standard_Boolean (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::SignSuppressionFlag, "returns the Sign Suppression Flag");
cls_IGESDimen_DimensionTolerance.def("FractionFlag", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::FractionFlag, "returns the Fraction Flag");
cls_IGESDimen_DimensionTolerance.def("Precision", (Standard_Integer (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::Precision, "returns the Precision for Value Display");
cls_IGESDimen_DimensionTolerance.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DimensionTolerance::get_type_name, "None");
cls_IGESDimen_DimensionTolerance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DimensionTolerance::get_type_descriptor, "None");
cls_IGESDimen_DimensionTolerance.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DimensionTolerance::*)() const) &IGESDimen_DimensionTolerance::DynamicType, "None");

// CLASS: IGESDIMEN_DIMENSIONUNITS
py::class_<IGESDimen_DimensionUnits, opencascade::handle<IGESDimen_DimensionUnits>, IGESData_IGESEntity> cls_IGESDimen_DimensionUnits(mod, "IGESDimen_DimensionUnits", "defines Dimension Units, Type <406>, Form <28> in package IGESDimen Describes the units and formatting details of the nominal value of a dimension.");

// Constructors
cls_IGESDimen_DimensionUnits.def(py::init<>());

// Methods
cls_IGESDimen_DimensionUnits.def("Init", (void (IGESDimen_DimensionUnits::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer)) &IGESDimen_DimensionUnits::Init, "This method is used to set the fields of the class DimensionUnits - nbPropVal : Number of property values, always = 6 - aSecondPos : Secondary Dimension Position 0 = This is the main text 1 = Before primary dimension 2 = After primary dimension 3 = Above primary dimension 4 = Below primary dimension - aUnitsInd : Units Indicator - aCharSet : Character Set used - aFormat : Format HAsciiString 1 = Standard ASCII 1001 = Symbol Font 1 1002 = Symbol Font 2 1003 = Drafting Font - aFracFlag : Fraction Flag 0 = Display values as decimal numbers 1 = Display values as fractions - aPrecision : Precision Value", py::arg("nbPropVal"), py::arg("aSecondPos"), py::arg("aUnitsInd"), py::arg("aCharSet"), py::arg("aFormat"), py::arg("aFracFlag"), py::arg("aPrecision"));
cls_IGESDimen_DimensionUnits.def("NbPropertyValues", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::NbPropertyValues, "returns the number of property values");
cls_IGESDimen_DimensionUnits.def("SecondaryDimenPosition", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::SecondaryDimenPosition, "returns position of secondary dimension w.r.t. primary dimension");
cls_IGESDimen_DimensionUnits.def("UnitsIndicator", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::UnitsIndicator, "returns the units indicator");
cls_IGESDimen_DimensionUnits.def("CharacterSet", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::CharacterSet, "returns the character set interpretation");
cls_IGESDimen_DimensionUnits.def("FormatString", (opencascade::handle<TCollection_HAsciiString> (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::FormatString, "returns the string used in formatting value");
cls_IGESDimen_DimensionUnits.def("FractionFlag", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::FractionFlag, "returns the fraction flag");
cls_IGESDimen_DimensionUnits.def("PrecisionOrDenominator", (Standard_Integer (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::PrecisionOrDenominator, "returns the precision/denominator number of decimal places when FractionFlag() = 0 denominator of fraction when FractionFlag() = 1");
cls_IGESDimen_DimensionUnits.def_static("get_type_name_", (const char * (*)()) &IGESDimen_DimensionUnits::get_type_name, "None");
cls_IGESDimen_DimensionUnits.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_DimensionUnits::get_type_descriptor, "None");
cls_IGESDimen_DimensionUnits.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_DimensionUnits::*)() const) &IGESDimen_DimensionUnits::DynamicType, "None");

// CLASS: IGESDIMEN_HARRAY1OFLEADERARROW
py::class_<IGESDimen_HArray1OfLeaderArrow, opencascade::handle<IGESDimen_HArray1OfLeaderArrow>, Standard_Transient> cls_IGESDimen_HArray1OfLeaderArrow(mod, "IGESDimen_HArray1OfLeaderArrow", "None", py::multiple_inheritance());

// Constructors
cls_IGESDimen_HArray1OfLeaderArrow.def(py::init<>());
cls_IGESDimen_HArray1OfLeaderArrow.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESDimen_HArray1OfLeaderArrow.def(py::init<const Standard_Integer, const Standard_Integer, const IGESDimen_Array1OfLeaderArrow::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESDimen_HArray1OfLeaderArrow.def(py::init<const IGESDimen_Array1OfLeaderArrow &>(), py::arg("theOther"));

// Methods
// cls_IGESDimen_HArray1OfLeaderArrow.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_HArray1OfLeaderArrow::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_HArray1OfLeaderArrow.def_static("operator delete_", (void (*)(void *)) &IGESDimen_HArray1OfLeaderArrow::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_HArray1OfLeaderArrow.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_HArray1OfLeaderArrow::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_HArray1OfLeaderArrow.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_HArray1OfLeaderArrow::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_HArray1OfLeaderArrow.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_HArray1OfLeaderArrow::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_HArray1OfLeaderArrow.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_HArray1OfLeaderArrow::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESDimen_HArray1OfLeaderArrow.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDimen_HArray1OfLeaderArrow::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESDimen_HArray1OfLeaderArrow.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDimen_HArray1OfLeaderArrow::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESDimen_HArray1OfLeaderArrow.def("Array1", (const IGESDimen_Array1OfLeaderArrow & (IGESDimen_HArray1OfLeaderArrow::*)() const) &IGESDimen_HArray1OfLeaderArrow::Array1, "None");
cls_IGESDimen_HArray1OfLeaderArrow.def("ChangeArray1", (IGESDimen_Array1OfLeaderArrow & (IGESDimen_HArray1OfLeaderArrow::*)()) &IGESDimen_HArray1OfLeaderArrow::ChangeArray1, "None");
cls_IGESDimen_HArray1OfLeaderArrow.def_static("get_type_name_", (const char * (*)()) &IGESDimen_HArray1OfLeaderArrow::get_type_name, "None");
cls_IGESDimen_HArray1OfLeaderArrow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_HArray1OfLeaderArrow::get_type_descriptor, "None");
cls_IGESDimen_HArray1OfLeaderArrow.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_HArray1OfLeaderArrow::*)() const) &IGESDimen_HArray1OfLeaderArrow::DynamicType, "None");

// CLASS: IGESDIMEN_FLAGNOTE
py::class_<IGESDimen_FlagNote, opencascade::handle<IGESDimen_FlagNote>, IGESData_IGESEntity> cls_IGESDimen_FlagNote(mod, "IGESDimen_FlagNote", "defines FlagNote, Type <208> Form <0> in package IGESDimen Is label information formatted in different ways");

// Constructors
cls_IGESDimen_FlagNote.def(py::init<>());

// Methods
cls_IGESDimen_FlagNote.def("Init", (void (IGESDimen_FlagNote::*)(const gp_XYZ &, const Standard_Real, const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_HArray1OfLeaderArrow> &)) &IGESDimen_FlagNote::Init, "This method is used to set the fields of the class FlagNote - leftCorner : Lower left corner of the Flag - anAngle : Rotation angle in radians - aNote : General Note Entity - someLeaders : Leader Entities", py::arg("leftCorner"), py::arg("anAngle"), py::arg("aNote"), py::arg("someLeaders"));
cls_IGESDimen_FlagNote.def("LowerLeftCorner", (gp_Pnt (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::LowerLeftCorner, "returns Lower Left coordinate of Flag as Pnt from package gp");
cls_IGESDimen_FlagNote.def("TransformedLowerLeftCorner", (gp_Pnt (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::TransformedLowerLeftCorner, "returns Lower Left coordinate of Flag as Pnt from package gp after Transformation.");
cls_IGESDimen_FlagNote.def("Angle", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::Angle, "returns Rotation angle in radians");
cls_IGESDimen_FlagNote.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::Note, "returns General Note Entity");
cls_IGESDimen_FlagNote.def("NbLeaders", (Standard_Integer (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::NbLeaders, "returns number of Arrows (Leaders) or zero");
cls_IGESDimen_FlagNote.def("Leader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_FlagNote::*)(const Standard_Integer) const) &IGESDimen_FlagNote::Leader, "returns Leader Entity raises exception if Index <= 0 or Index > NbLeaders()", py::arg("Index"));
cls_IGESDimen_FlagNote.def("Height", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::Height, "returns Height computed by the formula : Height = 2 * CH where CH is from theNote");
cls_IGESDimen_FlagNote.def("CharacterHeight", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::CharacterHeight, "returns the Character Height (from General Note)");
cls_IGESDimen_FlagNote.def("Length", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::Length, "returns Length computed by the formula : Length = TW + 0.4*CH where CH is from theNote and TW is from theNote");
cls_IGESDimen_FlagNote.def("TextWidth", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::TextWidth, "returns the Text Width (from General Note)");
cls_IGESDimen_FlagNote.def("TipLength", (Standard_Real (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::TipLength, "returns TipLength computed by the formula : TipLength = 0.5 * H / tan 35(deg) where H is Height()");
cls_IGESDimen_FlagNote.def_static("get_type_name_", (const char * (*)()) &IGESDimen_FlagNote::get_type_name, "None");
cls_IGESDimen_FlagNote.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_FlagNote::get_type_descriptor, "None");
cls_IGESDimen_FlagNote.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_FlagNote::*)() const) &IGESDimen_FlagNote::DynamicType, "None");

// CLASS: IGESDIMEN_GENERALLABEL
py::class_<IGESDimen_GeneralLabel, opencascade::handle<IGESDimen_GeneralLabel>, IGESData_IGESEntity> cls_IGESDimen_GeneralLabel(mod, "IGESDimen_GeneralLabel", "defines GeneralLabel, Type <210> Form <0> in package IGESDimen Used for general labeling with leaders");

// Constructors
cls_IGESDimen_GeneralLabel.def(py::init<>());

// Methods
cls_IGESDimen_GeneralLabel.def("Init", (void (IGESDimen_GeneralLabel::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_HArray1OfLeaderArrow> &)) &IGESDimen_GeneralLabel::Init, "This method is used to set the fields of the class GeneralLabel - aNote : General Note Entity - someLeaders : Associated Leader Entities", py::arg("aNote"), py::arg("someLeaders"));
cls_IGESDimen_GeneralLabel.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_GeneralLabel::*)() const) &IGESDimen_GeneralLabel::Note, "returns General Note Entity");
cls_IGESDimen_GeneralLabel.def("NbLeaders", (Standard_Integer (IGESDimen_GeneralLabel::*)() const) &IGESDimen_GeneralLabel::NbLeaders, "returns Number of Leaders");
cls_IGESDimen_GeneralLabel.def("Leader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_GeneralLabel::*)(const Standard_Integer) const) &IGESDimen_GeneralLabel::Leader, "returns Leader Entity raises exception if Index <= 0 or Index > NbLeaders()", py::arg("Index"));
cls_IGESDimen_GeneralLabel.def_static("get_type_name_", (const char * (*)()) &IGESDimen_GeneralLabel::get_type_name, "None");
cls_IGESDimen_GeneralLabel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_GeneralLabel::get_type_descriptor, "None");
cls_IGESDimen_GeneralLabel.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_GeneralLabel::*)() const) &IGESDimen_GeneralLabel::DynamicType, "None");

// CLASS: IGESDIMEN_GENERALMODULE
py::class_<IGESDimen_GeneralModule, opencascade::handle<IGESDimen_GeneralModule>, IGESData_GeneralModule> cls_IGESDimen_GeneralModule(mod, "IGESDimen_GeneralModule", "Definition of General Services for IGESDimen (specific part) This Services comprise : Shared & Implied Lists, Copy, Check");

// Constructors
cls_IGESDimen_GeneralModule.def(py::init<>());

// Methods
cls_IGESDimen_GeneralModule.def("OwnSharedCase", (void (IGESDimen_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESDimen_GeneralModule::OwnSharedCase, "Lists the Entities shared by a given IGESEntity <ent>, from its specific parameters : specific for each type", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESDimen_GeneralModule.def("DirChecker", (IGESData_DirChecker (IGESDimen_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESDimen_GeneralModule::DirChecker, "Returns a DirChecker, specific for each type of Entity (identified by its Case Number) : this DirChecker defines constraints which must be respected by the DirectoryPart", py::arg("CN"), py::arg("ent"));
cls_IGESDimen_GeneralModule.def("OwnCheckCase", (void (IGESDimen_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_GeneralModule::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_GeneralModule.def("NewVoid", (Standard_Boolean (IGESDimen_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &IGESDimen_GeneralModule::NewVoid, "Specific creation of a new void entity", py::arg("CN"), py::arg("entto"));
cls_IGESDimen_GeneralModule.def("OwnCopyCase", (void (IGESDimen_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const) &IGESDimen_GeneralModule::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_GeneralModule.def("CategoryNumber", (Standard_Integer (IGESDimen_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &IGESDimen_GeneralModule::CategoryNumber, "Returns a category number which characterizes an entity Drawing for all", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_IGESDimen_GeneralModule.def_static("get_type_name_", (const char * (*)()) &IGESDimen_GeneralModule::get_type_name, "None");
cls_IGESDimen_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_GeneralModule::get_type_descriptor, "None");
cls_IGESDimen_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_GeneralModule::*)() const) &IGESDimen_GeneralModule::DynamicType, "None");

// CLASS: IGESDIMEN_GENERALSYMBOL
py::class_<IGESDimen_GeneralSymbol, opencascade::handle<IGESDimen_GeneralSymbol>, IGESData_IGESEntity> cls_IGESDimen_GeneralSymbol(mod, "IGESDimen_GeneralSymbol", "defines General Symbol, Type <228>, Form <0-3,5001-9999> in package IGESDimen Consists of zero or one (Form 0) or one (all other forms), one or more geometry entities which define a symbol, and zero, one or more associated leaders.");

// Constructors
cls_IGESDimen_GeneralSymbol.def(py::init<>());

// Methods
cls_IGESDimen_GeneralSymbol.def("Init", (void (IGESDimen_GeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<IGESDimen_HArray1OfLeaderArrow> &)) &IGESDimen_GeneralSymbol::Init, "This method is used to set the fields of the class GeneralSymbol - aNote : General Note, null for form 0 - allGeoms : Geometric Entities - allLeaders : Leader Arrows", py::arg("aNote"), py::arg("allGeoms"), py::arg("allLeaders"));
cls_IGESDimen_GeneralSymbol.def("SetFormNumber", (void (IGESDimen_GeneralSymbol::*)(const Standard_Integer)) &IGESDimen_GeneralSymbol::SetFormNumber, "Changes FormNumber (indicates the Nature of the Symbole) Error if not in ranges [0-3] or [> 5000]", py::arg("form"));
cls_IGESDimen_GeneralSymbol.def("HasNote", (Standard_Boolean (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::HasNote, "returns True if there is associated General Note Entity");
cls_IGESDimen_GeneralSymbol.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::Note, "returns Null handle for form 0 only");
cls_IGESDimen_GeneralSymbol.def("NbGeomEntities", (Standard_Integer (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::NbGeomEntities, "returns number of Geometry Entities");
cls_IGESDimen_GeneralSymbol.def("GeomEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_GeneralSymbol::*)(const Standard_Integer) const) &IGESDimen_GeneralSymbol::GeomEntity, "returns the Index'th Geometry Entity raises exception if Index <= 0 or Index > NbGeomEntities()", py::arg("Index"));
cls_IGESDimen_GeneralSymbol.def("NbLeaders", (Standard_Integer (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::NbLeaders, "returns number of Leaders or zero if not specified");
cls_IGESDimen_GeneralSymbol.def("LeaderArrow", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_GeneralSymbol::*)(const Standard_Integer) const) &IGESDimen_GeneralSymbol::LeaderArrow, "returns the Index'th Leader Arrow raises exception if Index <= 0 or Index > NbLeaders()", py::arg("Index"));
cls_IGESDimen_GeneralSymbol.def_static("get_type_name_", (const char * (*)()) &IGESDimen_GeneralSymbol::get_type_name, "None");
cls_IGESDimen_GeneralSymbol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_GeneralSymbol::get_type_descriptor, "None");
cls_IGESDimen_GeneralSymbol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::DynamicType, "None");

// CLASS: IGESDIMEN_LINEARDIMENSION
py::class_<IGESDimen_LinearDimension, opencascade::handle<IGESDimen_LinearDimension>, IGESData_IGESEntity> cls_IGESDimen_LinearDimension(mod, "IGESDimen_LinearDimension", "defines LinearDimension, Type <216> Form <0> in package IGESDimen Used for linear dimensioning");

// Constructors
cls_IGESDimen_LinearDimension.def(py::init<>());

// Methods
cls_IGESDimen_LinearDimension.def("Init", (void (IGESDimen_LinearDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESDimen_WitnessLine> &)) &IGESDimen_LinearDimension::Init, "This method is used to set the fields of the class LinearDimension - aNote : General Note Entity - aLeader : First Leader Entity - anotherLeader : Second Leader Entity - aWitness : First Witness Line Entity or a Null Handle - anotherWitness : Second Witness Line Entity or a Null Handle", py::arg("aNote"), py::arg("aLeader"), py::arg("anotherLeader"), py::arg("aWitness"), py::arg("anotherWitness"));
cls_IGESDimen_LinearDimension.def("SetFormNumber", (void (IGESDimen_LinearDimension::*)(const Standard_Integer)) &IGESDimen_LinearDimension::SetFormNumber, "Changes FormNumber (indicates the Nature of the Dimension Unspecified, Diameter or Radius) Error if not in range [0-2]", py::arg("form"));
cls_IGESDimen_LinearDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::Note, "returns General Note Entity");
cls_IGESDimen_LinearDimension.def("FirstLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::FirstLeader, "returns first Leader Entity");
cls_IGESDimen_LinearDimension.def("SecondLeader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::SecondLeader, "returns second Leader Entity");
cls_IGESDimen_LinearDimension.def("HasFirstWitness", (Standard_Boolean (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::HasFirstWitness, "returns False if no first witness line");
cls_IGESDimen_LinearDimension.def("FirstWitness", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::FirstWitness, "returns first Witness Line Entity or a Null Handle");
cls_IGESDimen_LinearDimension.def("HasSecondWitness", (Standard_Boolean (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::HasSecondWitness, "returns False if no second witness line");
cls_IGESDimen_LinearDimension.def("SecondWitness", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::SecondWitness, "returns second Witness Line Entity or a Null Handle");
cls_IGESDimen_LinearDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_LinearDimension::get_type_name, "None");
cls_IGESDimen_LinearDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_LinearDimension::get_type_descriptor, "None");
cls_IGESDimen_LinearDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_LinearDimension::*)() const) &IGESDimen_LinearDimension::DynamicType, "None");

// CLASS: IGESDIMEN_NEWDIMENSIONEDGEOMETRY
py::class_<IGESDimen_NewDimensionedGeometry, opencascade::handle<IGESDimen_NewDimensionedGeometry>, IGESData_IGESEntity> cls_IGESDimen_NewDimensionedGeometry(mod, "IGESDimen_NewDimensionedGeometry", "defines New Dimensioned Geometry, Type <402>, Form <21> in package IGESDimen Links a dimension entity with the geometry entities it is dimensioning, so that later, in the receiving database, the dimension can be automatically recalculated and redrawn should the geometry be changed.");

// Constructors
cls_IGESDimen_NewDimensionedGeometry.def(py::init<>());

// Methods
cls_IGESDimen_NewDimensionedGeometry.def("Init", (void (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const Standard_Real, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColgp_HArray1OfXYZ> &)) &IGESDimen_NewDimensionedGeometry::Init, "This method is used to set the fields of the class NewDimensionedGeometry - nbDimen : Number of Dimensions, default = 1 - aDimen : Dimension Entity - anOrientation : Dimension Orientation Flag - anAngle : Angle Value - allEntities : Geometric Entities - allLocations : Dimension Location Flags - allPoints : Points on the Geometry Entities exception raised if lengths of entities, locations, points are not the same", py::arg("nbDimens"), py::arg("aDimen"), py::arg("anOrientation"), py::arg("anAngle"), py::arg("allEntities"), py::arg("allLocations"), py::arg("allPoints"));
cls_IGESDimen_NewDimensionedGeometry.def("NbDimensions", (Standard_Integer (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::NbDimensions, "returns the number of dimensions");
cls_IGESDimen_NewDimensionedGeometry.def("NbGeometries", (Standard_Integer (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::NbGeometries, "returns the number of associated geometry entities");
cls_IGESDimen_NewDimensionedGeometry.def("DimensionEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::DimensionEntity, "returns the dimension entity");
cls_IGESDimen_NewDimensionedGeometry.def("DimensionOrientationFlag", (Standard_Integer (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::DimensionOrientationFlag, "returns the dimension orientation flag");
cls_IGESDimen_NewDimensionedGeometry.def("AngleValue", (Standard_Real (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::AngleValue, "returns the angle value");
cls_IGESDimen_NewDimensionedGeometry.def("GeometryEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_NewDimensionedGeometry::GeometryEntity, "returns the Index'th geometry entity raises exception if Index <= 0 or Index > NbGeometries()", py::arg("Index"));
cls_IGESDimen_NewDimensionedGeometry.def("DimensionLocationFlag", (Standard_Integer (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_NewDimensionedGeometry::DimensionLocationFlag, "returns the Index'th geometry entity's dimension location flag raises exception if Index <= 0 or Index > NbGeometries()", py::arg("Index"));
cls_IGESDimen_NewDimensionedGeometry.def("Point", (gp_Pnt (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_NewDimensionedGeometry::Point, "coordinate of point on Index'th geometry entity raises exception if Index <= 0 or Index > NbGeometries()", py::arg("Index"));
cls_IGESDimen_NewDimensionedGeometry.def("TransformedPoint", (gp_Pnt (IGESDimen_NewDimensionedGeometry::*)(const Standard_Integer) const) &IGESDimen_NewDimensionedGeometry::TransformedPoint, "coordinate of point on Index'th geometry entity after Transformation raises exception if Index <= 0 or Index > NbGeometries()", py::arg("Index"));
cls_IGESDimen_NewDimensionedGeometry.def_static("get_type_name_", (const char * (*)()) &IGESDimen_NewDimensionedGeometry::get_type_name, "None");
cls_IGESDimen_NewDimensionedGeometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_NewDimensionedGeometry::get_type_descriptor, "None");
cls_IGESDimen_NewDimensionedGeometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_NewDimensionedGeometry::*)() const) &IGESDimen_NewDimensionedGeometry::DynamicType, "None");

// CLASS: IGESDIMEN_NEWGENERALNOTE
py::class_<IGESDimen_NewGeneralNote, opencascade::handle<IGESDimen_NewGeneralNote>, IGESData_IGESEntity> cls_IGESDimen_NewGeneralNote(mod, "IGESDimen_NewGeneralNote", "defines NewGeneralNote, Type <213> Form <0> in package IGESDimen Further attributes for formatting text strings");

// Constructors
cls_IGESDimen_NewGeneralNote.def(py::init<>());

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

// CLASS: IGESDIMEN_ORDINATEDIMENSION
py::class_<IGESDimen_OrdinateDimension, opencascade::handle<IGESDimen_OrdinateDimension>, IGESData_IGESEntity> cls_IGESDimen_OrdinateDimension(mod, "IGESDimen_OrdinateDimension", "defines IGES Ordinate Dimension, Type <218> Form <0, 1>, in package IGESDimen Note : The ordinate dimension entity is used to indicate dimensions from a common base line. Dimensioning is only permitted along the XT or YT axis.");

// Constructors
cls_IGESDimen_OrdinateDimension.def(py::init<>());

// Methods
cls_IGESDimen_OrdinateDimension.def("Init", (void (IGESDimen_OrdinateDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const Standard_Boolean, const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESDimen_LeaderArrow> &)) &IGESDimen_OrdinateDimension::Init, "None", py::arg("aNote"), py::arg("aType"), py::arg("aLine"), py::arg("anArrow"));
cls_IGESDimen_OrdinateDimension.def("IsLine", (Standard_Boolean (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::IsLine, "returns True if Witness Line and False if Leader (only for Form 0)");
cls_IGESDimen_OrdinateDimension.def("IsLeader", (Standard_Boolean (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::IsLeader, "returns True if Leader and False if Witness Line (only for Form 0)");
cls_IGESDimen_OrdinateDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::Note, "returns the General Note entity associated.");
cls_IGESDimen_OrdinateDimension.def("WitnessLine", (opencascade::handle<IGESDimen_WitnessLine> (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::WitnessLine, "returns the Witness Line associated or Null handle");
cls_IGESDimen_OrdinateDimension.def("Leader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::Leader, "returns the Leader associated or Null handle");
cls_IGESDimen_OrdinateDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_OrdinateDimension::get_type_name, "None");
cls_IGESDimen_OrdinateDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_OrdinateDimension::get_type_descriptor, "None");
cls_IGESDimen_OrdinateDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_OrdinateDimension::*)() const) &IGESDimen_OrdinateDimension::DynamicType, "None");

// CLASS: IGESDIMEN_POINTDIMENSION
py::class_<IGESDimen_PointDimension, opencascade::handle<IGESDimen_PointDimension>, IGESData_IGESEntity> cls_IGESDimen_PointDimension(mod, "IGESDimen_PointDimension", "defines IGES Point Dimension, Type <220> Form <0>, in package IGESDimen A Point Dimension Entity consists of a leader, text, and an optional circle or hexagon enclosing the text IGES specs for this entity mention SimpleClosedPlanarCurve Entity(106/63)which is not listed in LIST.Text In the sequel we have ignored this & considered only the other two entity for representing the hexagon or circle enclosing the text.");

// Constructors
cls_IGESDimen_PointDimension.def(py::init<>());

// Methods
cls_IGESDimen_PointDimension.def("Init", (void (IGESDimen_PointDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESData_IGESEntity> &)) &IGESDimen_PointDimension::Init, "None", py::arg("aNote"), py::arg("anArrow"), py::arg("aGeom"));
cls_IGESDimen_PointDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::Note, "None");
cls_IGESDimen_PointDimension.def("LeaderArrow", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::LeaderArrow, "None");
cls_IGESDimen_PointDimension.def("GeomCase", (Standard_Integer (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::GeomCase, "returns the type of geometric entity. 0 if no hexagon or circle encloses the text 1 if CircularArc 2 if CompositeCurve 3 otherwise");
cls_IGESDimen_PointDimension.def("Geom", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::Geom, "returns the Geometry Entity, Null handle if GeomCase(me) .eq. 0");
cls_IGESDimen_PointDimension.def("CircularArc", (opencascade::handle<IGESGeom_CircularArc> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::CircularArc, "returns Null handle if GeomCase(me) .ne. 1");
cls_IGESDimen_PointDimension.def("CompositeCurve", (opencascade::handle<IGESGeom_CompositeCurve> (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::CompositeCurve, "returns Null handle if GeomCase(me) .ne. 2");
cls_IGESDimen_PointDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_PointDimension::get_type_name, "None");
cls_IGESDimen_PointDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_PointDimension::get_type_descriptor, "None");
cls_IGESDimen_PointDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_PointDimension::*)() const) &IGESDimen_PointDimension::DynamicType, "None");

// CLASS: IGESDIMEN_PROTOCOL
py::class_<IGESDimen_Protocol, opencascade::handle<IGESDimen_Protocol>, IGESData_Protocol> cls_IGESDimen_Protocol(mod, "IGESDimen_Protocol", "Description of Protocol for IGESDimen");

// Constructors
cls_IGESDimen_Protocol.def(py::init<>());

// Methods
cls_IGESDimen_Protocol.def("NbResources", (Standard_Integer (IGESDimen_Protocol::*)() const) &IGESDimen_Protocol::NbResources, "Gives the count of Resource Protocol. Here, two (Protocols from IGESGraph and IGESGeom)");
cls_IGESDimen_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESDimen_Protocol::*)(const Standard_Integer) const) &IGESDimen_Protocol::Resource, "Returns a Resource, given a rank.", py::arg("num"));
cls_IGESDimen_Protocol.def("TypeNumber", (Standard_Integer (IGESDimen_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &IGESDimen_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type This Case Number is then used in Libraries : the various Modules attached to this class of Protocol must use them in accordance (for a given value of TypeNumber, they must consider the same Type as the Protocol defines)", py::arg("atype"));
cls_IGESDimen_Protocol.def_static("get_type_name_", (const char * (*)()) &IGESDimen_Protocol::get_type_name, "None");
cls_IGESDimen_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_Protocol::get_type_descriptor, "None");
cls_IGESDimen_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_Protocol::*)() const) &IGESDimen_Protocol::DynamicType, "None");

// CLASS: IGESDIMEN_RADIUSDIMENSION
py::class_<IGESDimen_RadiusDimension, opencascade::handle<IGESDimen_RadiusDimension>, IGESData_IGESEntity> cls_IGESDimen_RadiusDimension(mod, "IGESDimen_RadiusDimension", "Defines IGES Radius Dimension, type <222> Form <0, 1>, in package IGESDimen. A Radius Dimension Entity consists of a General Note, a leader, and an arc center point. A second form of this entity accounts for the occasional need to have two leader entities referenced.");

// Constructors
cls_IGESDimen_RadiusDimension.def(py::init<>());

// Methods
cls_IGESDimen_RadiusDimension.def("Init", (void (IGESDimen_RadiusDimension::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_LeaderArrow> &, const gp_XY &, const opencascade::handle<IGESDimen_LeaderArrow> &)) &IGESDimen_RadiusDimension::Init, "None", py::arg("aNote"), py::arg("anArrow"), py::arg("arcCenter"), py::arg("anotherArrow"));
cls_IGESDimen_RadiusDimension.def("InitForm", (void (IGESDimen_RadiusDimension::*)(const Standard_Integer)) &IGESDimen_RadiusDimension::InitForm, "Allows to change Form Number (1 admits null arrow)", py::arg("form"));
cls_IGESDimen_RadiusDimension.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::Note, "returns the General Note entity");
cls_IGESDimen_RadiusDimension.def("Leader", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::Leader, "returns the Leader Arrow entity");
cls_IGESDimen_RadiusDimension.def("Center", (gp_Pnt2d (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::Center, "returns the coordinates of the Arc Center");
cls_IGESDimen_RadiusDimension.def("TransformedCenter", (gp_Pnt (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::TransformedCenter, "returns the coordinates of the Arc Center after Transformation (Z coord taken from ZDepth of Leader Entity)");
cls_IGESDimen_RadiusDimension.def("HasLeader2", (Standard_Boolean (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::HasLeader2, "returns True if form is 1, False if 0");
cls_IGESDimen_RadiusDimension.def("Leader2", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::Leader2, "returns Null handle if Form is 0");
cls_IGESDimen_RadiusDimension.def_static("get_type_name_", (const char * (*)()) &IGESDimen_RadiusDimension::get_type_name, "None");
cls_IGESDimen_RadiusDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_RadiusDimension::get_type_descriptor, "None");
cls_IGESDimen_RadiusDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_RadiusDimension::*)() const) &IGESDimen_RadiusDimension::DynamicType, "None");

// CLASS: IGESDIMEN_READWRITEMODULE
py::class_<IGESDimen_ReadWriteModule, opencascade::handle<IGESDimen_ReadWriteModule>, IGESData_ReadWriteModule> cls_IGESDimen_ReadWriteModule(mod, "IGESDimen_ReadWriteModule", "Defines Dimen File Access Module for IGESDimen (specific parts) Specific actions concern : Read and Write Own Parameters of an IGESEntity");

// Constructors
cls_IGESDimen_ReadWriteModule.def(py::init<>());

// Methods
cls_IGESDimen_ReadWriteModule.def("CaseIGES", (Standard_Integer (IGESDimen_ReadWriteModule::*)(const Standard_Integer, const Standard_Integer) const) &IGESDimen_ReadWriteModule::CaseIGES, "Defines Case Numbers for Entities of IGESDimen", py::arg("typenum"), py::arg("formnum"));
cls_IGESDimen_ReadWriteModule.def("ReadOwnParams", (void (IGESDimen_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ReadWriteModule::ReadOwnParams, "Reads own parameters from file for an Entity of IGESDimen", py::arg("CN"), py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ReadWriteModule.def("WriteOwnParams", (void (IGESDimen_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, IGESData_IGESWriter &) const) &IGESDimen_ReadWriteModule::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("CN"), py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &IGESDimen_ReadWriteModule::get_type_name, "None");
cls_IGESDimen_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_ReadWriteModule::get_type_descriptor, "None");
cls_IGESDimen_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_ReadWriteModule::*)() const) &IGESDimen_ReadWriteModule::DynamicType, "None");

// CLASS: IGESDIMEN_SECTION
py::class_<IGESDimen_Section, opencascade::handle<IGESDimen_Section>, IGESData_IGESEntity> cls_IGESDimen_Section(mod, "IGESDimen_Section", "defines Section, Type <106> Form <31-38> in package IGESDimen Contains information to display sectioned sides");

// Constructors
cls_IGESDimen_Section.def(py::init<>());

// Methods
cls_IGESDimen_Section.def("Init", (void (IGESDimen_Section::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<TColgp_HArray1OfXY> &)) &IGESDimen_Section::Init, "This method is used to set the fields of the class Section - dataType : Interpretation Flag, always = 1 - aDisp : Common z displacement - dataPoints : Data points", py::arg("dataType"), py::arg("aDisp"), py::arg("dataPoints"));
cls_IGESDimen_Section.def("SetFormNumber", (void (IGESDimen_Section::*)(const Standard_Integer)) &IGESDimen_Section::SetFormNumber, "Changes FormNumber (indicates the Type of the Hatches) Error if not in range [31-38]", py::arg("form"));
cls_IGESDimen_Section.def("Datatype", (Standard_Integer (IGESDimen_Section::*)() const) &IGESDimen_Section::Datatype, "returns Interpretation Flag, always = 1");
cls_IGESDimen_Section.def("NbPoints", (Standard_Integer (IGESDimen_Section::*)() const) &IGESDimen_Section::NbPoints, "returns number of Data Points");
cls_IGESDimen_Section.def("ZDisplacement", (Standard_Real (IGESDimen_Section::*)() const) &IGESDimen_Section::ZDisplacement, "returns common Z displacement");
cls_IGESDimen_Section.def("Point", (gp_Pnt (IGESDimen_Section::*)(const Standard_Integer) const) &IGESDimen_Section::Point, "returns Index'th data point raises exception if Index <= 0 or Index > NbPoints()", py::arg("Index"));
cls_IGESDimen_Section.def("TransformedPoint", (gp_Pnt (IGESDimen_Section::*)(const Standard_Integer) const) &IGESDimen_Section::TransformedPoint, "returns Index'th data point after Transformation raises exception if Index <= 0 or Index > NbPoints()", py::arg("Index"));
cls_IGESDimen_Section.def_static("get_type_name_", (const char * (*)()) &IGESDimen_Section::get_type_name, "None");
cls_IGESDimen_Section.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_Section::get_type_descriptor, "None");
cls_IGESDimen_Section.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_Section::*)() const) &IGESDimen_Section::DynamicType, "None");

// CLASS: IGESDIMEN_SECTIONEDAREA
py::class_<IGESDimen_SectionedArea, opencascade::handle<IGESDimen_SectionedArea>, IGESData_IGESEntity> cls_IGESDimen_SectionedArea(mod, "IGESDimen_SectionedArea", "defines IGES Sectioned Area, Type <230> Form <0>, in package IGESDimen A sectioned area is a portion of a design which is to be filled with a pattern of lines. Ordinarily, this entity is used to reveal or expose shape or material characteri- stics defined by other entities. It consists of a pointer to an exterior definition curve, a specification of the pattern of lines, the coordinates of a point on a pattern line, the distance between the pattern lines, the angle between the pattern lines and the X-axis of definition space, and the specification of any enclosed definition curves (commonly known as islands).");

// Constructors
cls_IGESDimen_SectionedArea.def(py::init<>());

// Methods
cls_IGESDimen_SectionedArea.def("Init", (void (IGESDimen_SectionedArea::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const gp_XYZ &, const Standard_Real, const Standard_Real, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDimen_SectionedArea::Init, "None", py::arg("aCurve"), py::arg("aPattern"), py::arg("aPoint"), py::arg("aDistance"), py::arg("anAngle"), py::arg("someIslands"));
cls_IGESDimen_SectionedArea.def("SetInverted", (void (IGESDimen_SectionedArea::*)(const Standard_Boolean)) &IGESDimen_SectionedArea::SetInverted, "Sets the cross hatches to be inverted or not, according value of <mode> (corresponds to FormNumber)", py::arg("mode"));
cls_IGESDimen_SectionedArea.def("IsInverted", (Standard_Boolean (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::IsInverted, "Returns True if cross hatches as Inverted, else they are Standard (Inverted : Form=1, Standard : Form=0)");
cls_IGESDimen_SectionedArea.def("ExteriorCurve", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::ExteriorCurve, "returns the exterior definition curve");
cls_IGESDimen_SectionedArea.def("Pattern", (Standard_Integer (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::Pattern, "returns fill pattern code");
cls_IGESDimen_SectionedArea.def("PassingPoint", (gp_Pnt (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::PassingPoint, "returns point thru which line should pass");
cls_IGESDimen_SectionedArea.def("TransformedPassingPoint", (gp_Pnt (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::TransformedPassingPoint, "returns point thru which line should pass after Transformation");
cls_IGESDimen_SectionedArea.def("ZDepth", (Standard_Real (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::ZDepth, "returns the Z depth");
cls_IGESDimen_SectionedArea.def("Distance", (Standard_Real (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::Distance, "returns the normal distance between lines");
cls_IGESDimen_SectionedArea.def("Angle", (Standard_Real (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::Angle, "returns the angle of lines with XT axis");
cls_IGESDimen_SectionedArea.def("NbIslands", (Standard_Integer (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::NbIslands, "returns the number of island curves");
cls_IGESDimen_SectionedArea.def("IslandCurve", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_SectionedArea::*)(const Standard_Integer) const) &IGESDimen_SectionedArea::IslandCurve, "returns the interior definition curves, returns Null Handle exception raised if Index <= 0 or Index > NbIslands()", py::arg("Index"));
cls_IGESDimen_SectionedArea.def_static("get_type_name_", (const char * (*)()) &IGESDimen_SectionedArea::get_type_name, "None");
cls_IGESDimen_SectionedArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_SectionedArea::get_type_descriptor, "None");
cls_IGESDimen_SectionedArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_SectionedArea::*)() const) &IGESDimen_SectionedArea::DynamicType, "None");

// CLASS: IGESDIMEN_SPECIFICMODULE
py::class_<IGESDimen_SpecificModule, opencascade::handle<IGESDimen_SpecificModule>, IGESData_SpecificModule> cls_IGESDimen_SpecificModule(mod, "IGESDimen_SpecificModule", "Defines Services attached to IGES Entities : Dump & OwnCorrect, for IGESDimen");

// Constructors
cls_IGESDimen_SpecificModule.def(py::init<>());

// Methods
cls_IGESDimen_SpecificModule.def("OwnDump", (void (IGESDimen_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_SpecificModule::OwnDump, "Specific Dump (own parameters) for IGESDimen", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESDimen_SpecificModule.def("OwnCorrect", (Standard_Boolean (IGESDimen_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESDimen_SpecificModule::OwnCorrect, "Performs non-ambiguous Corrections on Entities which support them (BasicDimension,CenterLine,DimensionDisplayData, DimensionTolerance,DimensionUnits,DimensionedGeometry, NewDimensionedGeometry,Section,WitnessLine)", py::arg("CN"), py::arg("ent"));
cls_IGESDimen_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESDimen_SpecificModule::get_type_name, "None");
cls_IGESDimen_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_SpecificModule::get_type_descriptor, "None");
cls_IGESDimen_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_SpecificModule::*)() const) &IGESDimen_SpecificModule::DynamicType, "None");

// CLASS: IGESDIMEN_TOOLANGULARDIMENSION
py::class_<IGESDimen_ToolAngularDimension> cls_IGESDimen_ToolAngularDimension(mod, "IGESDimen_ToolAngularDimension", "Tool to work on a AngularDimension. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolAngularDimension.def(py::init<>());

// Methods
// cls_IGESDimen_ToolAngularDimension.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolAngularDimension::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolAngularDimension.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolAngularDimension::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolAngularDimension.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolAngularDimension::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolAngularDimension.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolAngularDimension::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolAngularDimension.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolAngularDimension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolAngularDimension.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolAngularDimension::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolAngularDimension.def("ReadOwnParams", (void (IGESDimen_ToolAngularDimension::*)(const opencascade::handle<IGESDimen_AngularDimension> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolAngularDimension::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolAngularDimension.def("WriteOwnParams", (void (IGESDimen_ToolAngularDimension::*)(const opencascade::handle<IGESDimen_AngularDimension> &, IGESData_IGESWriter &) const) &IGESDimen_ToolAngularDimension::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolAngularDimension.def("OwnShared", (void (IGESDimen_ToolAngularDimension::*)(const opencascade::handle<IGESDimen_AngularDimension> &, Interface_EntityIterator &) const) &IGESDimen_ToolAngularDimension::OwnShared, "Lists the Entities shared by a AngularDimension <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolAngularDimension.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolAngularDimension::*)(const opencascade::handle<IGESDimen_AngularDimension> &) const) &IGESDimen_ToolAngularDimension::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolAngularDimension.def("OwnCheck", (void (IGESDimen_ToolAngularDimension::*)(const opencascade::handle<IGESDimen_AngularDimension> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolAngularDimension::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolAngularDimension.def("OwnCopy", (void (IGESDimen_ToolAngularDimension::*)(const opencascade::handle<IGESDimen_AngularDimension> &, const opencascade::handle<IGESDimen_AngularDimension> &, Interface_CopyTool &) const) &IGESDimen_ToolAngularDimension::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolAngularDimension.def("OwnDump", (void (IGESDimen_ToolAngularDimension::*)(const opencascade::handle<IGESDimen_AngularDimension> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolAngularDimension::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLBASICDIMENSION
py::class_<IGESDimen_ToolBasicDimension> cls_IGESDimen_ToolBasicDimension(mod, "IGESDimen_ToolBasicDimension", "Tool to work on a BasicDimension. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolBasicDimension.def(py::init<>());

// Methods
// cls_IGESDimen_ToolBasicDimension.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolBasicDimension::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolBasicDimension.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolBasicDimension::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolBasicDimension.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolBasicDimension::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolBasicDimension.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolBasicDimension::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolBasicDimension.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolBasicDimension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolBasicDimension.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolBasicDimension::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolBasicDimension.def("ReadOwnParams", (void (IGESDimen_ToolBasicDimension::*)(const opencascade::handle<IGESDimen_BasicDimension> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolBasicDimension::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolBasicDimension.def("WriteOwnParams", (void (IGESDimen_ToolBasicDimension::*)(const opencascade::handle<IGESDimen_BasicDimension> &, IGESData_IGESWriter &) const) &IGESDimen_ToolBasicDimension::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolBasicDimension.def("OwnShared", (void (IGESDimen_ToolBasicDimension::*)(const opencascade::handle<IGESDimen_BasicDimension> &, Interface_EntityIterator &) const) &IGESDimen_ToolBasicDimension::OwnShared, "Lists the Entities shared by a BasicDimension <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolBasicDimension.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolBasicDimension::*)(const opencascade::handle<IGESDimen_BasicDimension> &) const) &IGESDimen_ToolBasicDimension::OwnCorrect, "Sets automatic unambiguous Correction on a BasicDimension (NbPropertyValues forced to 8)", py::arg("ent"));
cls_IGESDimen_ToolBasicDimension.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolBasicDimension::*)(const opencascade::handle<IGESDimen_BasicDimension> &) const) &IGESDimen_ToolBasicDimension::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolBasicDimension.def("OwnCheck", (void (IGESDimen_ToolBasicDimension::*)(const opencascade::handle<IGESDimen_BasicDimension> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolBasicDimension::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolBasicDimension.def("OwnCopy", (void (IGESDimen_ToolBasicDimension::*)(const opencascade::handle<IGESDimen_BasicDimension> &, const opencascade::handle<IGESDimen_BasicDimension> &, Interface_CopyTool &) const) &IGESDimen_ToolBasicDimension::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolBasicDimension.def("OwnDump", (void (IGESDimen_ToolBasicDimension::*)(const opencascade::handle<IGESDimen_BasicDimension> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolBasicDimension::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLCENTERLINE
py::class_<IGESDimen_ToolCenterLine> cls_IGESDimen_ToolCenterLine(mod, "IGESDimen_ToolCenterLine", "Tool to work on a CenterLine. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolCenterLine.def(py::init<>());

// Methods
// cls_IGESDimen_ToolCenterLine.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolCenterLine::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolCenterLine.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolCenterLine::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolCenterLine.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolCenterLine::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolCenterLine.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolCenterLine::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolCenterLine.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolCenterLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolCenterLine.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolCenterLine::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolCenterLine.def("ReadOwnParams", (void (IGESDimen_ToolCenterLine::*)(const opencascade::handle<IGESDimen_CenterLine> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolCenterLine::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolCenterLine.def("WriteOwnParams", (void (IGESDimen_ToolCenterLine::*)(const opencascade::handle<IGESDimen_CenterLine> &, IGESData_IGESWriter &) const) &IGESDimen_ToolCenterLine::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolCenterLine.def("OwnShared", (void (IGESDimen_ToolCenterLine::*)(const opencascade::handle<IGESDimen_CenterLine> &, Interface_EntityIterator &) const) &IGESDimen_ToolCenterLine::OwnShared, "Lists the Entities shared by a CenterLine <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolCenterLine.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolCenterLine::*)(const opencascade::handle<IGESDimen_CenterLine> &) const) &IGESDimen_ToolCenterLine::OwnCorrect, "Sets automatic unambiguous Correction on a CenterLine (LineFont forced to Rank = 1, DataType forced to 1)", py::arg("ent"));
cls_IGESDimen_ToolCenterLine.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolCenterLine::*)(const opencascade::handle<IGESDimen_CenterLine> &) const) &IGESDimen_ToolCenterLine::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolCenterLine.def("OwnCheck", (void (IGESDimen_ToolCenterLine::*)(const opencascade::handle<IGESDimen_CenterLine> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolCenterLine::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolCenterLine.def("OwnCopy", (void (IGESDimen_ToolCenterLine::*)(const opencascade::handle<IGESDimen_CenterLine> &, const opencascade::handle<IGESDimen_CenterLine> &, Interface_CopyTool &) const) &IGESDimen_ToolCenterLine::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolCenterLine.def("OwnDump", (void (IGESDimen_ToolCenterLine::*)(const opencascade::handle<IGESDimen_CenterLine> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolCenterLine::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLCURVEDIMENSION
py::class_<IGESDimen_ToolCurveDimension> cls_IGESDimen_ToolCurveDimension(mod, "IGESDimen_ToolCurveDimension", "Tool to work on a CurveDimension. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolCurveDimension.def(py::init<>());

// Methods
// cls_IGESDimen_ToolCurveDimension.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolCurveDimension::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolCurveDimension.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolCurveDimension::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolCurveDimension.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolCurveDimension::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolCurveDimension.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolCurveDimension::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolCurveDimension.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolCurveDimension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolCurveDimension.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolCurveDimension::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolCurveDimension.def("ReadOwnParams", (void (IGESDimen_ToolCurveDimension::*)(const opencascade::handle<IGESDimen_CurveDimension> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolCurveDimension::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolCurveDimension.def("WriteOwnParams", (void (IGESDimen_ToolCurveDimension::*)(const opencascade::handle<IGESDimen_CurveDimension> &, IGESData_IGESWriter &) const) &IGESDimen_ToolCurveDimension::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolCurveDimension.def("OwnShared", (void (IGESDimen_ToolCurveDimension::*)(const opencascade::handle<IGESDimen_CurveDimension> &, Interface_EntityIterator &) const) &IGESDimen_ToolCurveDimension::OwnShared, "Lists the Entities shared by a CurveDimension <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolCurveDimension.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolCurveDimension::*)(const opencascade::handle<IGESDimen_CurveDimension> &) const) &IGESDimen_ToolCurveDimension::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolCurveDimension.def("OwnCheck", (void (IGESDimen_ToolCurveDimension::*)(const opencascade::handle<IGESDimen_CurveDimension> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolCurveDimension::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolCurveDimension.def("OwnCopy", (void (IGESDimen_ToolCurveDimension::*)(const opencascade::handle<IGESDimen_CurveDimension> &, const opencascade::handle<IGESDimen_CurveDimension> &, Interface_CopyTool &) const) &IGESDimen_ToolCurveDimension::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolCurveDimension.def("OwnDump", (void (IGESDimen_ToolCurveDimension::*)(const opencascade::handle<IGESDimen_CurveDimension> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolCurveDimension::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLDIAMETERDIMENSION
py::class_<IGESDimen_ToolDiameterDimension> cls_IGESDimen_ToolDiameterDimension(mod, "IGESDimen_ToolDiameterDimension", "Tool to work on a DiameterDimension. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolDiameterDimension.def(py::init<>());

// Methods
// cls_IGESDimen_ToolDiameterDimension.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolDiameterDimension::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolDiameterDimension::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolDiameterDimension::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolDiameterDimension::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolDiameterDimension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolDiameterDimension::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolDiameterDimension.def("ReadOwnParams", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolDiameterDimension::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolDiameterDimension.def("WriteOwnParams", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, IGESData_IGESWriter &) const) &IGESDimen_ToolDiameterDimension::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolDiameterDimension.def("OwnShared", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, Interface_EntityIterator &) const) &IGESDimen_ToolDiameterDimension::OwnShared, "Lists the Entities shared by a DiameterDimension <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolDiameterDimension.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &) const) &IGESDimen_ToolDiameterDimension::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolDiameterDimension.def("OwnCheck", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolDiameterDimension::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolDiameterDimension.def("OwnCopy", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, const opencascade::handle<IGESDimen_DiameterDimension> &, Interface_CopyTool &) const) &IGESDimen_ToolDiameterDimension::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolDiameterDimension.def("OwnDump", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolDiameterDimension::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLDIMENSIONDISPLAYDATA
py::class_<IGESDimen_ToolDimensionDisplayData> cls_IGESDimen_ToolDimensionDisplayData(mod, "IGESDimen_ToolDimensionDisplayData", "Tool to work on a DimensionDisplayData. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolDimensionDisplayData.def(py::init<>());

// Methods
// cls_IGESDimen_ToolDimensionDisplayData.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolDimensionDisplayData::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolDimensionDisplayData.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolDimensionDisplayData::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionDisplayData.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolDimensionDisplayData::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolDimensionDisplayData.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolDimensionDisplayData::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionDisplayData.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolDimensionDisplayData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionDisplayData.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolDimensionDisplayData::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolDimensionDisplayData.def("ReadOwnParams", (void (IGESDimen_ToolDimensionDisplayData::*)(const opencascade::handle<IGESDimen_DimensionDisplayData> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolDimensionDisplayData::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolDimensionDisplayData.def("WriteOwnParams", (void (IGESDimen_ToolDimensionDisplayData::*)(const opencascade::handle<IGESDimen_DimensionDisplayData> &, IGESData_IGESWriter &) const) &IGESDimen_ToolDimensionDisplayData::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolDimensionDisplayData.def("OwnShared", (void (IGESDimen_ToolDimensionDisplayData::*)(const opencascade::handle<IGESDimen_DimensionDisplayData> &, Interface_EntityIterator &) const) &IGESDimen_ToolDimensionDisplayData::OwnShared, "Lists the Entities shared by a DimensionDisplayData <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolDimensionDisplayData.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolDimensionDisplayData::*)(const opencascade::handle<IGESDimen_DimensionDisplayData> &) const) &IGESDimen_ToolDimensionDisplayData::OwnCorrect, "Sets automatic unambiguous Correction on a DimensionDisplayData (NbPropertyValues forced to 14)", py::arg("ent"));
cls_IGESDimen_ToolDimensionDisplayData.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolDimensionDisplayData::*)(const opencascade::handle<IGESDimen_DimensionDisplayData> &) const) &IGESDimen_ToolDimensionDisplayData::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolDimensionDisplayData.def("OwnCheck", (void (IGESDimen_ToolDimensionDisplayData::*)(const opencascade::handle<IGESDimen_DimensionDisplayData> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolDimensionDisplayData::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolDimensionDisplayData.def("OwnCopy", (void (IGESDimen_ToolDimensionDisplayData::*)(const opencascade::handle<IGESDimen_DimensionDisplayData> &, const opencascade::handle<IGESDimen_DimensionDisplayData> &, Interface_CopyTool &) const) &IGESDimen_ToolDimensionDisplayData::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolDimensionDisplayData.def("OwnDump", (void (IGESDimen_ToolDimensionDisplayData::*)(const opencascade::handle<IGESDimen_DimensionDisplayData> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolDimensionDisplayData::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLDIMENSIONEDGEOMETRY
py::class_<IGESDimen_ToolDimensionedGeometry> cls_IGESDimen_ToolDimensionedGeometry(mod, "IGESDimen_ToolDimensionedGeometry", "Tool to work on a DimensionedGeometry. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolDimensionedGeometry.def(py::init<>());

// Methods
// cls_IGESDimen_ToolDimensionedGeometry.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolDimensionedGeometry::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolDimensionedGeometry.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolDimensionedGeometry::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionedGeometry.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolDimensionedGeometry::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolDimensionedGeometry.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolDimensionedGeometry::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionedGeometry.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolDimensionedGeometry::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionedGeometry.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolDimensionedGeometry::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolDimensionedGeometry.def("ReadOwnParams", (void (IGESDimen_ToolDimensionedGeometry::*)(const opencascade::handle<IGESDimen_DimensionedGeometry> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolDimensionedGeometry::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolDimensionedGeometry.def("WriteOwnParams", (void (IGESDimen_ToolDimensionedGeometry::*)(const opencascade::handle<IGESDimen_DimensionedGeometry> &, IGESData_IGESWriter &) const) &IGESDimen_ToolDimensionedGeometry::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolDimensionedGeometry.def("OwnShared", (void (IGESDimen_ToolDimensionedGeometry::*)(const opencascade::handle<IGESDimen_DimensionedGeometry> &, Interface_EntityIterator &) const) &IGESDimen_ToolDimensionedGeometry::OwnShared, "Lists the Entities shared by a DimensionedGeometry <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolDimensionedGeometry.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolDimensionedGeometry::*)(const opencascade::handle<IGESDimen_DimensionedGeometry> &) const) &IGESDimen_ToolDimensionedGeometry::OwnCorrect, "Sets automatic unambiguous Correction on a DimensionedGeometry (NbDimensions forced to 1)", py::arg("ent"));
cls_IGESDimen_ToolDimensionedGeometry.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolDimensionedGeometry::*)(const opencascade::handle<IGESDimen_DimensionedGeometry> &) const) &IGESDimen_ToolDimensionedGeometry::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolDimensionedGeometry.def("OwnCheck", (void (IGESDimen_ToolDimensionedGeometry::*)(const opencascade::handle<IGESDimen_DimensionedGeometry> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolDimensionedGeometry::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolDimensionedGeometry.def("OwnCopy", (void (IGESDimen_ToolDimensionedGeometry::*)(const opencascade::handle<IGESDimen_DimensionedGeometry> &, const opencascade::handle<IGESDimen_DimensionedGeometry> &, Interface_CopyTool &) const) &IGESDimen_ToolDimensionedGeometry::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolDimensionedGeometry.def("OwnDump", (void (IGESDimen_ToolDimensionedGeometry::*)(const opencascade::handle<IGESDimen_DimensionedGeometry> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolDimensionedGeometry::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLDIMENSIONTOLERANCE
py::class_<IGESDimen_ToolDimensionTolerance> cls_IGESDimen_ToolDimensionTolerance(mod, "IGESDimen_ToolDimensionTolerance", "Tool to work on a DimensionTolerance. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolDimensionTolerance.def(py::init<>());

// Methods
// cls_IGESDimen_ToolDimensionTolerance.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolDimensionTolerance::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolDimensionTolerance.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolDimensionTolerance::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionTolerance.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolDimensionTolerance::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolDimensionTolerance.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolDimensionTolerance::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionTolerance.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolDimensionTolerance::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionTolerance.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolDimensionTolerance::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolDimensionTolerance.def("ReadOwnParams", (void (IGESDimen_ToolDimensionTolerance::*)(const opencascade::handle<IGESDimen_DimensionTolerance> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolDimensionTolerance::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolDimensionTolerance.def("WriteOwnParams", (void (IGESDimen_ToolDimensionTolerance::*)(const opencascade::handle<IGESDimen_DimensionTolerance> &, IGESData_IGESWriter &) const) &IGESDimen_ToolDimensionTolerance::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolDimensionTolerance.def("OwnShared", (void (IGESDimen_ToolDimensionTolerance::*)(const opencascade::handle<IGESDimen_DimensionTolerance> &, Interface_EntityIterator &) const) &IGESDimen_ToolDimensionTolerance::OwnShared, "Lists the Entities shared by a DimensionTolerance <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolDimensionTolerance.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolDimensionTolerance::*)(const opencascade::handle<IGESDimen_DimensionTolerance> &) const) &IGESDimen_ToolDimensionTolerance::OwnCorrect, "Sets automatic unambiguous Correction on a DimensionTolerance (NbPropertyValues forced to 8)", py::arg("ent"));
cls_IGESDimen_ToolDimensionTolerance.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolDimensionTolerance::*)(const opencascade::handle<IGESDimen_DimensionTolerance> &) const) &IGESDimen_ToolDimensionTolerance::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolDimensionTolerance.def("OwnCheck", (void (IGESDimen_ToolDimensionTolerance::*)(const opencascade::handle<IGESDimen_DimensionTolerance> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolDimensionTolerance::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolDimensionTolerance.def("OwnCopy", (void (IGESDimen_ToolDimensionTolerance::*)(const opencascade::handle<IGESDimen_DimensionTolerance> &, const opencascade::handle<IGESDimen_DimensionTolerance> &, Interface_CopyTool &) const) &IGESDimen_ToolDimensionTolerance::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolDimensionTolerance.def("OwnDump", (void (IGESDimen_ToolDimensionTolerance::*)(const opencascade::handle<IGESDimen_DimensionTolerance> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolDimensionTolerance::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLDIMENSIONUNITS
py::class_<IGESDimen_ToolDimensionUnits> cls_IGESDimen_ToolDimensionUnits(mod, "IGESDimen_ToolDimensionUnits", "Tool to work on a DimensionUnits. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolDimensionUnits.def(py::init<>());

// Methods
// cls_IGESDimen_ToolDimensionUnits.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolDimensionUnits::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolDimensionUnits.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolDimensionUnits::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionUnits.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolDimensionUnits::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolDimensionUnits.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolDimensionUnits::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionUnits.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolDimensionUnits::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolDimensionUnits.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolDimensionUnits::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolDimensionUnits.def("ReadOwnParams", (void (IGESDimen_ToolDimensionUnits::*)(const opencascade::handle<IGESDimen_DimensionUnits> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolDimensionUnits::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolDimensionUnits.def("WriteOwnParams", (void (IGESDimen_ToolDimensionUnits::*)(const opencascade::handle<IGESDimen_DimensionUnits> &, IGESData_IGESWriter &) const) &IGESDimen_ToolDimensionUnits::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolDimensionUnits.def("OwnShared", (void (IGESDimen_ToolDimensionUnits::*)(const opencascade::handle<IGESDimen_DimensionUnits> &, Interface_EntityIterator &) const) &IGESDimen_ToolDimensionUnits::OwnShared, "Lists the Entities shared by a DimensionUnits <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolDimensionUnits.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolDimensionUnits::*)(const opencascade::handle<IGESDimen_DimensionUnits> &) const) &IGESDimen_ToolDimensionUnits::OwnCorrect, "Sets automatic unambiguous Correction on a DimensionUnits (NbPropertyValues forced to 6)", py::arg("ent"));
cls_IGESDimen_ToolDimensionUnits.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolDimensionUnits::*)(const opencascade::handle<IGESDimen_DimensionUnits> &) const) &IGESDimen_ToolDimensionUnits::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolDimensionUnits.def("OwnCheck", (void (IGESDimen_ToolDimensionUnits::*)(const opencascade::handle<IGESDimen_DimensionUnits> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolDimensionUnits::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolDimensionUnits.def("OwnCopy", (void (IGESDimen_ToolDimensionUnits::*)(const opencascade::handle<IGESDimen_DimensionUnits> &, const opencascade::handle<IGESDimen_DimensionUnits> &, Interface_CopyTool &) const) &IGESDimen_ToolDimensionUnits::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolDimensionUnits.def("OwnDump", (void (IGESDimen_ToolDimensionUnits::*)(const opencascade::handle<IGESDimen_DimensionUnits> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolDimensionUnits::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLFLAGNOTE
py::class_<IGESDimen_ToolFlagNote> cls_IGESDimen_ToolFlagNote(mod, "IGESDimen_ToolFlagNote", "Tool to work on a FlagNote. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolFlagNote.def(py::init<>());

// Methods
// cls_IGESDimen_ToolFlagNote.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolFlagNote::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolFlagNote.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolFlagNote::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolFlagNote.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolFlagNote::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolFlagNote.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolFlagNote::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolFlagNote.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolFlagNote::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolFlagNote.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolFlagNote::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolFlagNote.def("ReadOwnParams", (void (IGESDimen_ToolFlagNote::*)(const opencascade::handle<IGESDimen_FlagNote> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolFlagNote::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolFlagNote.def("WriteOwnParams", (void (IGESDimen_ToolFlagNote::*)(const opencascade::handle<IGESDimen_FlagNote> &, IGESData_IGESWriter &) const) &IGESDimen_ToolFlagNote::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolFlagNote.def("OwnShared", (void (IGESDimen_ToolFlagNote::*)(const opencascade::handle<IGESDimen_FlagNote> &, Interface_EntityIterator &) const) &IGESDimen_ToolFlagNote::OwnShared, "Lists the Entities shared by a FlagNote <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolFlagNote.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolFlagNote::*)(const opencascade::handle<IGESDimen_FlagNote> &) const) &IGESDimen_ToolFlagNote::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolFlagNote.def("OwnCheck", (void (IGESDimen_ToolFlagNote::*)(const opencascade::handle<IGESDimen_FlagNote> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolFlagNote::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolFlagNote.def("OwnCopy", (void (IGESDimen_ToolFlagNote::*)(const opencascade::handle<IGESDimen_FlagNote> &, const opencascade::handle<IGESDimen_FlagNote> &, Interface_CopyTool &) const) &IGESDimen_ToolFlagNote::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolFlagNote.def("OwnDump", (void (IGESDimen_ToolFlagNote::*)(const opencascade::handle<IGESDimen_FlagNote> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolFlagNote::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLGENERALLABEL
py::class_<IGESDimen_ToolGeneralLabel> cls_IGESDimen_ToolGeneralLabel(mod, "IGESDimen_ToolGeneralLabel", "Tool to work on a GeneralLabel. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolGeneralLabel.def(py::init<>());

// Methods
// cls_IGESDimen_ToolGeneralLabel.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolGeneralLabel::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolGeneralLabel.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolGeneralLabel::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralLabel.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolGeneralLabel::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolGeneralLabel.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolGeneralLabel::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralLabel.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolGeneralLabel::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralLabel.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolGeneralLabel::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolGeneralLabel.def("ReadOwnParams", (void (IGESDimen_ToolGeneralLabel::*)(const opencascade::handle<IGESDimen_GeneralLabel> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolGeneralLabel::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolGeneralLabel.def("WriteOwnParams", (void (IGESDimen_ToolGeneralLabel::*)(const opencascade::handle<IGESDimen_GeneralLabel> &, IGESData_IGESWriter &) const) &IGESDimen_ToolGeneralLabel::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolGeneralLabel.def("OwnShared", (void (IGESDimen_ToolGeneralLabel::*)(const opencascade::handle<IGESDimen_GeneralLabel> &, Interface_EntityIterator &) const) &IGESDimen_ToolGeneralLabel::OwnShared, "Lists the Entities shared by a GeneralLabel <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolGeneralLabel.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolGeneralLabel::*)(const opencascade::handle<IGESDimen_GeneralLabel> &) const) &IGESDimen_ToolGeneralLabel::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolGeneralLabel.def("OwnCheck", (void (IGESDimen_ToolGeneralLabel::*)(const opencascade::handle<IGESDimen_GeneralLabel> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolGeneralLabel::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolGeneralLabel.def("OwnCopy", (void (IGESDimen_ToolGeneralLabel::*)(const opencascade::handle<IGESDimen_GeneralLabel> &, const opencascade::handle<IGESDimen_GeneralLabel> &, Interface_CopyTool &) const) &IGESDimen_ToolGeneralLabel::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolGeneralLabel.def("OwnDump", (void (IGESDimen_ToolGeneralLabel::*)(const opencascade::handle<IGESDimen_GeneralLabel> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolGeneralLabel::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLGENERALNOTE
py::class_<IGESDimen_ToolGeneralNote> cls_IGESDimen_ToolGeneralNote(mod, "IGESDimen_ToolGeneralNote", "Tool to work on a GeneralNote. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolGeneralNote.def(py::init<>());

// Methods
// cls_IGESDimen_ToolGeneralNote.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolGeneralNote::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolGeneralNote.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolGeneralNote::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralNote.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolGeneralNote::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolGeneralNote.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolGeneralNote::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralNote.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolGeneralNote::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralNote.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolGeneralNote::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolGeneralNote.def("ReadOwnParams", (void (IGESDimen_ToolGeneralNote::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolGeneralNote::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolGeneralNote.def("WriteOwnParams", (void (IGESDimen_ToolGeneralNote::*)(const opencascade::handle<IGESDimen_GeneralNote> &, IGESData_IGESWriter &) const) &IGESDimen_ToolGeneralNote::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolGeneralNote.def("OwnShared", (void (IGESDimen_ToolGeneralNote::*)(const opencascade::handle<IGESDimen_GeneralNote> &, Interface_EntityIterator &) const) &IGESDimen_ToolGeneralNote::OwnShared, "Lists the Entities shared by a GeneralNote <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolGeneralNote.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolGeneralNote::*)(const opencascade::handle<IGESDimen_GeneralNote> &) const) &IGESDimen_ToolGeneralNote::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolGeneralNote.def("OwnCheck", (void (IGESDimen_ToolGeneralNote::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolGeneralNote::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolGeneralNote.def("OwnCopy", (void (IGESDimen_ToolGeneralNote::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESDimen_GeneralNote> &, Interface_CopyTool &) const) &IGESDimen_ToolGeneralNote::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolGeneralNote.def("OwnDump", (void (IGESDimen_ToolGeneralNote::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolGeneralNote::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLGENERALSYMBOL
py::class_<IGESDimen_ToolGeneralSymbol> cls_IGESDimen_ToolGeneralSymbol(mod, "IGESDimen_ToolGeneralSymbol", "Tool to work on a GeneralSymbol. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolGeneralSymbol.def(py::init<>());

// Methods
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolGeneralSymbol::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolGeneralSymbol::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolGeneralSymbol::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolGeneralSymbol::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolGeneralSymbol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolGeneralSymbol.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolGeneralSymbol::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolGeneralSymbol.def("ReadOwnParams", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolGeneralSymbol::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolGeneralSymbol.def("WriteOwnParams", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, IGESData_IGESWriter &) const) &IGESDimen_ToolGeneralSymbol::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolGeneralSymbol.def("OwnShared", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, Interface_EntityIterator &) const) &IGESDimen_ToolGeneralSymbol::OwnShared, "Lists the Entities shared by a GeneralSymbol <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolGeneralSymbol.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &) const) &IGESDimen_ToolGeneralSymbol::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolGeneralSymbol.def("OwnCheck", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolGeneralSymbol::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolGeneralSymbol.def("OwnCopy", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, const opencascade::handle<IGESDimen_GeneralSymbol> &, Interface_CopyTool &) const) &IGESDimen_ToolGeneralSymbol::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolGeneralSymbol.def("OwnDump", (void (IGESDimen_ToolGeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralSymbol> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolGeneralSymbol::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLLEADERARROW
py::class_<IGESDimen_ToolLeaderArrow> cls_IGESDimen_ToolLeaderArrow(mod, "IGESDimen_ToolLeaderArrow", "Tool to work on a LeaderArrow. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolLeaderArrow.def(py::init<>());

// Methods
// cls_IGESDimen_ToolLeaderArrow.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolLeaderArrow::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolLeaderArrow.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolLeaderArrow::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolLeaderArrow.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolLeaderArrow::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolLeaderArrow.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolLeaderArrow::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolLeaderArrow.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolLeaderArrow::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolLeaderArrow.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolLeaderArrow::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolLeaderArrow.def("ReadOwnParams", (void (IGESDimen_ToolLeaderArrow::*)(const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolLeaderArrow::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolLeaderArrow.def("WriteOwnParams", (void (IGESDimen_ToolLeaderArrow::*)(const opencascade::handle<IGESDimen_LeaderArrow> &, IGESData_IGESWriter &) const) &IGESDimen_ToolLeaderArrow::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolLeaderArrow.def("OwnShared", (void (IGESDimen_ToolLeaderArrow::*)(const opencascade::handle<IGESDimen_LeaderArrow> &, Interface_EntityIterator &) const) &IGESDimen_ToolLeaderArrow::OwnShared, "Lists the Entities shared by a LeaderArrow <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolLeaderArrow.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolLeaderArrow::*)(const opencascade::handle<IGESDimen_LeaderArrow> &) const) &IGESDimen_ToolLeaderArrow::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolLeaderArrow.def("OwnCheck", (void (IGESDimen_ToolLeaderArrow::*)(const opencascade::handle<IGESDimen_LeaderArrow> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolLeaderArrow::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolLeaderArrow.def("OwnCopy", (void (IGESDimen_ToolLeaderArrow::*)(const opencascade::handle<IGESDimen_LeaderArrow> &, const opencascade::handle<IGESDimen_LeaderArrow> &, Interface_CopyTool &) const) &IGESDimen_ToolLeaderArrow::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolLeaderArrow.def("OwnDump", (void (IGESDimen_ToolLeaderArrow::*)(const opencascade::handle<IGESDimen_LeaderArrow> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolLeaderArrow::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLLINEARDIMENSION
py::class_<IGESDimen_ToolLinearDimension> cls_IGESDimen_ToolLinearDimension(mod, "IGESDimen_ToolLinearDimension", "Tool to work on a LinearDimension. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolLinearDimension.def(py::init<>());

// Methods
// cls_IGESDimen_ToolLinearDimension.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolLinearDimension::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolLinearDimension.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolLinearDimension::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolLinearDimension.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolLinearDimension::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolLinearDimension.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolLinearDimension::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolLinearDimension.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolLinearDimension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolLinearDimension.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolLinearDimension::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolLinearDimension.def("ReadOwnParams", (void (IGESDimen_ToolLinearDimension::*)(const opencascade::handle<IGESDimen_LinearDimension> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolLinearDimension::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolLinearDimension.def("WriteOwnParams", (void (IGESDimen_ToolLinearDimension::*)(const opencascade::handle<IGESDimen_LinearDimension> &, IGESData_IGESWriter &) const) &IGESDimen_ToolLinearDimension::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolLinearDimension.def("OwnShared", (void (IGESDimen_ToolLinearDimension::*)(const opencascade::handle<IGESDimen_LinearDimension> &, Interface_EntityIterator &) const) &IGESDimen_ToolLinearDimension::OwnShared, "Lists the Entities shared by a LinearDimension <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolLinearDimension.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolLinearDimension::*)(const opencascade::handle<IGESDimen_LinearDimension> &) const) &IGESDimen_ToolLinearDimension::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolLinearDimension.def("OwnCheck", (void (IGESDimen_ToolLinearDimension::*)(const opencascade::handle<IGESDimen_LinearDimension> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolLinearDimension::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolLinearDimension.def("OwnCopy", (void (IGESDimen_ToolLinearDimension::*)(const opencascade::handle<IGESDimen_LinearDimension> &, const opencascade::handle<IGESDimen_LinearDimension> &, Interface_CopyTool &) const) &IGESDimen_ToolLinearDimension::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolLinearDimension.def("OwnDump", (void (IGESDimen_ToolLinearDimension::*)(const opencascade::handle<IGESDimen_LinearDimension> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolLinearDimension::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLNEWDIMENSIONEDGEOMETRY
py::class_<IGESDimen_ToolNewDimensionedGeometry> cls_IGESDimen_ToolNewDimensionedGeometry(mod, "IGESDimen_ToolNewDimensionedGeometry", "Tool to work on a NewDimensionedGeometry. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolNewDimensionedGeometry.def(py::init<>());

// Methods
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolNewDimensionedGeometry::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolNewDimensionedGeometry::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolNewDimensionedGeometry::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolNewDimensionedGeometry::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolNewDimensionedGeometry::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolNewDimensionedGeometry::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolNewDimensionedGeometry.def("ReadOwnParams", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolNewDimensionedGeometry::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("WriteOwnParams", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, IGESData_IGESWriter &) const) &IGESDimen_ToolNewDimensionedGeometry::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnShared", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, Interface_EntityIterator &) const) &IGESDimen_ToolNewDimensionedGeometry::OwnShared, "Lists the Entities shared by a NewDimensionedGeometry <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &) const) &IGESDimen_ToolNewDimensionedGeometry::OwnCorrect, "Sets automatic unambiguous Correction on a NewDimensionedGeometry (NbDimensions forced to 1, Transf Nullified in D.E.)", py::arg("ent"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &) const) &IGESDimen_ToolNewDimensionedGeometry::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnCheck", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolNewDimensionedGeometry::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnCopy", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, Interface_CopyTool &) const) &IGESDimen_ToolNewDimensionedGeometry::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnDump", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolNewDimensionedGeometry::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLNEWGENERALNOTE
py::class_<IGESDimen_ToolNewGeneralNote> cls_IGESDimen_ToolNewGeneralNote(mod, "IGESDimen_ToolNewGeneralNote", "Tool to work on a NewGeneralNote. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolNewGeneralNote.def(py::init<>());

// Methods
// cls_IGESDimen_ToolNewGeneralNote.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolNewGeneralNote::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolNewGeneralNote.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolNewGeneralNote::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolNewGeneralNote.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolNewGeneralNote::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolNewGeneralNote.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolNewGeneralNote::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolNewGeneralNote.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolNewGeneralNote::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolNewGeneralNote.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolNewGeneralNote::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolNewGeneralNote.def("ReadOwnParams", (void (IGESDimen_ToolNewGeneralNote::*)(const opencascade::handle<IGESDimen_NewGeneralNote> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolNewGeneralNote::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolNewGeneralNote.def("WriteOwnParams", (void (IGESDimen_ToolNewGeneralNote::*)(const opencascade::handle<IGESDimen_NewGeneralNote> &, IGESData_IGESWriter &) const) &IGESDimen_ToolNewGeneralNote::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolNewGeneralNote.def("OwnShared", (void (IGESDimen_ToolNewGeneralNote::*)(const opencascade::handle<IGESDimen_NewGeneralNote> &, Interface_EntityIterator &) const) &IGESDimen_ToolNewGeneralNote::OwnShared, "Lists the Entities shared by a NewGeneralNote <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolNewGeneralNote.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolNewGeneralNote::*)(const opencascade::handle<IGESDimen_NewGeneralNote> &) const) &IGESDimen_ToolNewGeneralNote::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolNewGeneralNote.def("OwnCheck", (void (IGESDimen_ToolNewGeneralNote::*)(const opencascade::handle<IGESDimen_NewGeneralNote> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolNewGeneralNote::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolNewGeneralNote.def("OwnCopy", (void (IGESDimen_ToolNewGeneralNote::*)(const opencascade::handle<IGESDimen_NewGeneralNote> &, const opencascade::handle<IGESDimen_NewGeneralNote> &, Interface_CopyTool &) const) &IGESDimen_ToolNewGeneralNote::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolNewGeneralNote.def("OwnDump", (void (IGESDimen_ToolNewGeneralNote::*)(const opencascade::handle<IGESDimen_NewGeneralNote> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolNewGeneralNote::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLORDINATEDIMENSION
py::class_<IGESDimen_ToolOrdinateDimension> cls_IGESDimen_ToolOrdinateDimension(mod, "IGESDimen_ToolOrdinateDimension", "Tool to work on a OrdinateDimension. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolOrdinateDimension.def(py::init<>());

// Methods
// cls_IGESDimen_ToolOrdinateDimension.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolOrdinateDimension::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolOrdinateDimension.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolOrdinateDimension::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolOrdinateDimension.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolOrdinateDimension::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolOrdinateDimension.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolOrdinateDimension::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolOrdinateDimension.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolOrdinateDimension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolOrdinateDimension.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolOrdinateDimension::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolOrdinateDimension.def("ReadOwnParams", (void (IGESDimen_ToolOrdinateDimension::*)(const opencascade::handle<IGESDimen_OrdinateDimension> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolOrdinateDimension::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolOrdinateDimension.def("WriteOwnParams", (void (IGESDimen_ToolOrdinateDimension::*)(const opencascade::handle<IGESDimen_OrdinateDimension> &, IGESData_IGESWriter &) const) &IGESDimen_ToolOrdinateDimension::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolOrdinateDimension.def("OwnShared", (void (IGESDimen_ToolOrdinateDimension::*)(const opencascade::handle<IGESDimen_OrdinateDimension> &, Interface_EntityIterator &) const) &IGESDimen_ToolOrdinateDimension::OwnShared, "Lists the Entities shared by a OrdinateDimension <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolOrdinateDimension.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolOrdinateDimension::*)(const opencascade::handle<IGESDimen_OrdinateDimension> &) const) &IGESDimen_ToolOrdinateDimension::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolOrdinateDimension.def("OwnCheck", (void (IGESDimen_ToolOrdinateDimension::*)(const opencascade::handle<IGESDimen_OrdinateDimension> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolOrdinateDimension::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolOrdinateDimension.def("OwnCopy", (void (IGESDimen_ToolOrdinateDimension::*)(const opencascade::handle<IGESDimen_OrdinateDimension> &, const opencascade::handle<IGESDimen_OrdinateDimension> &, Interface_CopyTool &) const) &IGESDimen_ToolOrdinateDimension::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolOrdinateDimension.def("OwnDump", (void (IGESDimen_ToolOrdinateDimension::*)(const opencascade::handle<IGESDimen_OrdinateDimension> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolOrdinateDimension::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLPOINTDIMENSION
py::class_<IGESDimen_ToolPointDimension> cls_IGESDimen_ToolPointDimension(mod, "IGESDimen_ToolPointDimension", "Tool to work on a PointDimension. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolPointDimension.def(py::init<>());

// Methods
// cls_IGESDimen_ToolPointDimension.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolPointDimension::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolPointDimension.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolPointDimension::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolPointDimension.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolPointDimension::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolPointDimension.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolPointDimension::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolPointDimension.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolPointDimension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolPointDimension.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolPointDimension::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolPointDimension.def("ReadOwnParams", (void (IGESDimen_ToolPointDimension::*)(const opencascade::handle<IGESDimen_PointDimension> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolPointDimension::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolPointDimension.def("WriteOwnParams", (void (IGESDimen_ToolPointDimension::*)(const opencascade::handle<IGESDimen_PointDimension> &, IGESData_IGESWriter &) const) &IGESDimen_ToolPointDimension::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolPointDimension.def("OwnShared", (void (IGESDimen_ToolPointDimension::*)(const opencascade::handle<IGESDimen_PointDimension> &, Interface_EntityIterator &) const) &IGESDimen_ToolPointDimension::OwnShared, "Lists the Entities shared by a PointDimension <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolPointDimension.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolPointDimension::*)(const opencascade::handle<IGESDimen_PointDimension> &) const) &IGESDimen_ToolPointDimension::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolPointDimension.def("OwnCheck", (void (IGESDimen_ToolPointDimension::*)(const opencascade::handle<IGESDimen_PointDimension> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolPointDimension::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolPointDimension.def("OwnCopy", (void (IGESDimen_ToolPointDimension::*)(const opencascade::handle<IGESDimen_PointDimension> &, const opencascade::handle<IGESDimen_PointDimension> &, Interface_CopyTool &) const) &IGESDimen_ToolPointDimension::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolPointDimension.def("OwnDump", (void (IGESDimen_ToolPointDimension::*)(const opencascade::handle<IGESDimen_PointDimension> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolPointDimension::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLRADIUSDIMENSION
py::class_<IGESDimen_ToolRadiusDimension> cls_IGESDimen_ToolRadiusDimension(mod, "IGESDimen_ToolRadiusDimension", "Tool to work on a RadiusDimension. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolRadiusDimension.def(py::init<>());

// Methods
// cls_IGESDimen_ToolRadiusDimension.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolRadiusDimension::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolRadiusDimension.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolRadiusDimension::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolRadiusDimension.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolRadiusDimension::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolRadiusDimension.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolRadiusDimension::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolRadiusDimension.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolRadiusDimension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolRadiusDimension.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolRadiusDimension::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolRadiusDimension.def("ReadOwnParams", (void (IGESDimen_ToolRadiusDimension::*)(const opencascade::handle<IGESDimen_RadiusDimension> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolRadiusDimension::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolRadiusDimension.def("WriteOwnParams", (void (IGESDimen_ToolRadiusDimension::*)(const opencascade::handle<IGESDimen_RadiusDimension> &, IGESData_IGESWriter &) const) &IGESDimen_ToolRadiusDimension::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolRadiusDimension.def("OwnShared", (void (IGESDimen_ToolRadiusDimension::*)(const opencascade::handle<IGESDimen_RadiusDimension> &, Interface_EntityIterator &) const) &IGESDimen_ToolRadiusDimension::OwnShared, "Lists the Entities shared by a RadiusDimension <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolRadiusDimension.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolRadiusDimension::*)(const opencascade::handle<IGESDimen_RadiusDimension> &) const) &IGESDimen_ToolRadiusDimension::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolRadiusDimension.def("OwnCheck", (void (IGESDimen_ToolRadiusDimension::*)(const opencascade::handle<IGESDimen_RadiusDimension> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolRadiusDimension::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolRadiusDimension.def("OwnCopy", (void (IGESDimen_ToolRadiusDimension::*)(const opencascade::handle<IGESDimen_RadiusDimension> &, const opencascade::handle<IGESDimen_RadiusDimension> &, Interface_CopyTool &) const) &IGESDimen_ToolRadiusDimension::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolRadiusDimension.def("OwnDump", (void (IGESDimen_ToolRadiusDimension::*)(const opencascade::handle<IGESDimen_RadiusDimension> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolRadiusDimension::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLSECTION
py::class_<IGESDimen_ToolSection> cls_IGESDimen_ToolSection(mod, "IGESDimen_ToolSection", "Tool to work on a Section. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolSection.def(py::init<>());

// Methods
// cls_IGESDimen_ToolSection.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolSection::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolSection.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolSection::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolSection.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolSection::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolSection.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolSection::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolSection.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolSection.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolSection::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolSection.def("ReadOwnParams", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolSection::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolSection.def("WriteOwnParams", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, IGESData_IGESWriter &) const) &IGESDimen_ToolSection::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolSection.def("OwnShared", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, Interface_EntityIterator &) const) &IGESDimen_ToolSection::OwnShared, "Lists the Entities shared by a Section <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolSection.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &) const) &IGESDimen_ToolSection::OwnCorrect, "Sets automatic unambiguous Correction on a Section (LineFont forced to Rank = 1, DataType forced to 1)", py::arg("ent"));
cls_IGESDimen_ToolSection.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &) const) &IGESDimen_ToolSection::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolSection.def("OwnCheck", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolSection::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolSection.def("OwnCopy", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, const opencascade::handle<IGESDimen_Section> &, Interface_CopyTool &) const) &IGESDimen_ToolSection::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolSection.def("OwnDump", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolSection::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLSECTIONEDAREA
py::class_<IGESDimen_ToolSectionedArea> cls_IGESDimen_ToolSectionedArea(mod, "IGESDimen_ToolSectionedArea", "Tool to work on a SectionedArea. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolSectionedArea.def(py::init<>());

// Methods
// cls_IGESDimen_ToolSectionedArea.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolSectionedArea::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolSectionedArea.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolSectionedArea::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolSectionedArea.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolSectionedArea::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolSectionedArea.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolSectionedArea::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolSectionedArea.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolSectionedArea::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolSectionedArea.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolSectionedArea::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolSectionedArea.def("ReadOwnParams", (void (IGESDimen_ToolSectionedArea::*)(const opencascade::handle<IGESDimen_SectionedArea> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolSectionedArea::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolSectionedArea.def("WriteOwnParams", (void (IGESDimen_ToolSectionedArea::*)(const opencascade::handle<IGESDimen_SectionedArea> &, IGESData_IGESWriter &) const) &IGESDimen_ToolSectionedArea::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolSectionedArea.def("OwnShared", (void (IGESDimen_ToolSectionedArea::*)(const opencascade::handle<IGESDimen_SectionedArea> &, Interface_EntityIterator &) const) &IGESDimen_ToolSectionedArea::OwnShared, "Lists the Entities shared by a SectionedArea <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolSectionedArea.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolSectionedArea::*)(const opencascade::handle<IGESDimen_SectionedArea> &) const) &IGESDimen_ToolSectionedArea::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolSectionedArea.def("OwnCheck", (void (IGESDimen_ToolSectionedArea::*)(const opencascade::handle<IGESDimen_SectionedArea> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolSectionedArea::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolSectionedArea.def("OwnCopy", (void (IGESDimen_ToolSectionedArea::*)(const opencascade::handle<IGESDimen_SectionedArea> &, const opencascade::handle<IGESDimen_SectionedArea> &, Interface_CopyTool &) const) &IGESDimen_ToolSectionedArea::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolSectionedArea.def("OwnDump", (void (IGESDimen_ToolSectionedArea::*)(const opencascade::handle<IGESDimen_SectionedArea> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolSectionedArea::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_TOOLWITNESSLINE
py::class_<IGESDimen_ToolWitnessLine> cls_IGESDimen_ToolWitnessLine(mod, "IGESDimen_ToolWitnessLine", "Tool to work on a WitnessLine. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolWitnessLine.def(py::init<>());

// Methods
// cls_IGESDimen_ToolWitnessLine.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolWitnessLine::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolWitnessLine.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolWitnessLine::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolWitnessLine.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolWitnessLine::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolWitnessLine.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolWitnessLine::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolWitnessLine.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolWitnessLine::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolWitnessLine.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolWitnessLine::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolWitnessLine.def("ReadOwnParams", (void (IGESDimen_ToolWitnessLine::*)(const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolWitnessLine::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolWitnessLine.def("WriteOwnParams", (void (IGESDimen_ToolWitnessLine::*)(const opencascade::handle<IGESDimen_WitnessLine> &, IGESData_IGESWriter &) const) &IGESDimen_ToolWitnessLine::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolWitnessLine.def("OwnShared", (void (IGESDimen_ToolWitnessLine::*)(const opencascade::handle<IGESDimen_WitnessLine> &, Interface_EntityIterator &) const) &IGESDimen_ToolWitnessLine::OwnShared, "Lists the Entities shared by a WitnessLine <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolWitnessLine.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolWitnessLine::*)(const opencascade::handle<IGESDimen_WitnessLine> &) const) &IGESDimen_ToolWitnessLine::OwnCorrect, "Sets automatic unambiguous Correction on a WitnessLine (LineFont forced to Rank = 1, DataType forced to 1)", py::arg("ent"));
cls_IGESDimen_ToolWitnessLine.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolWitnessLine::*)(const opencascade::handle<IGESDimen_WitnessLine> &) const) &IGESDimen_ToolWitnessLine::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolWitnessLine.def("OwnCheck", (void (IGESDimen_ToolWitnessLine::*)(const opencascade::handle<IGESDimen_WitnessLine> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolWitnessLine::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolWitnessLine.def("OwnCopy", (void (IGESDimen_ToolWitnessLine::*)(const opencascade::handle<IGESDimen_WitnessLine> &, const opencascade::handle<IGESDimen_WitnessLine> &, Interface_CopyTool &) const) &IGESDimen_ToolWitnessLine::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolWitnessLine.def("OwnDump", (void (IGESDimen_ToolWitnessLine::*)(const opencascade::handle<IGESDimen_WitnessLine> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolWitnessLine::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESDIMEN_WITNESSLINE
py::class_<IGESDimen_WitnessLine, opencascade::handle<IGESDimen_WitnessLine>, IGESData_IGESEntity> cls_IGESDimen_WitnessLine(mod, "IGESDimen_WitnessLine", "defines WitnessLine, Type <106> Form <40> in package IGESDimen Contains one or more straight line segments associated with drafting entities of various types");

// Constructors
cls_IGESDimen_WitnessLine.def(py::init<>());

// Methods
cls_IGESDimen_WitnessLine.def("Init", (void (IGESDimen_WitnessLine::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<TColgp_HArray1OfXY> &)) &IGESDimen_WitnessLine::Init, "This method is used to set the fields of the class WitnessLine - dataType : Interpretation Flag, always = 1 - aDispl : Common z displacement - dataPoints : Data points", py::arg("dataType"), py::arg("aDisp"), py::arg("dataPoints"));
cls_IGESDimen_WitnessLine.def("Datatype", (Standard_Integer (IGESDimen_WitnessLine::*)() const) &IGESDimen_WitnessLine::Datatype, "returns Interpretation Flag, always = 1");
cls_IGESDimen_WitnessLine.def("NbPoints", (Standard_Integer (IGESDimen_WitnessLine::*)() const) &IGESDimen_WitnessLine::NbPoints, "returns number of Data Points");
cls_IGESDimen_WitnessLine.def("ZDisplacement", (Standard_Real (IGESDimen_WitnessLine::*)() const) &IGESDimen_WitnessLine::ZDisplacement, "returns common Z displacement");
cls_IGESDimen_WitnessLine.def("Point", (gp_Pnt (IGESDimen_WitnessLine::*)(const Standard_Integer) const) &IGESDimen_WitnessLine::Point, "returns Index'th. data point raises exception if Index <= 0 or Index > NbPoints", py::arg("Index"));
cls_IGESDimen_WitnessLine.def("TransformedPoint", (gp_Pnt (IGESDimen_WitnessLine::*)(const Standard_Integer) const) &IGESDimen_WitnessLine::TransformedPoint, "returns data point after Transformation. raises exception if Index <= 0 or Index > NbPoints", py::arg("Index"));
cls_IGESDimen_WitnessLine.def_static("get_type_name_", (const char * (*)()) &IGESDimen_WitnessLine::get_type_name, "None");
cls_IGESDimen_WitnessLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_WitnessLine::get_type_descriptor, "None");
cls_IGESDimen_WitnessLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_WitnessLine::*)() const) &IGESDimen_WitnessLine::DynamicType, "None");


}
