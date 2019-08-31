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
#include <BOPDS_DS.hxx>
#include <BOPDS_Iterator.hxx>
#include <BOPAlgo_Operation.hxx>
#include <BOPAlgo_CheckStatus.hxx>
#include <BOPAlgo_GlueEnum.hxx>
#include <Message_Alert.hxx>
#include <Standard_Handle.hxx>
#include <BOPAlgo_Alerts.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_AlertWithShape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_Report.hxx>
#include <Standard_OStream.hxx>
#include <Message_ProgressIndicator.hxx>
#include <BOPAlgo_Options.hxx>
#include <BOPAlgo_Algo.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BOPAlgo_CheckResult.hxx>
#include <NCollection_List.hxx>
#include <BOPAlgo_ListOfCheckResult.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BOPAlgo_ArgumentAnalyzer.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <BOPAlgo_PPaveFiller.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BOPAlgo_BuilderShape.hxx>
#include <BOPDS_PDS.hxx>
#include <IntTools_Context.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BOPAlgo_Builder.hxx>
#include <BOPAlgo_ToolsProvider.hxx>
#include <BOPAlgo_BOP.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <BOPAlgo_BuilderArea.hxx>
#include <TopoDS_Face.hxx>
#include <TopAbs_Orientation.hxx>
#include <BOPAlgo_BuilderFace.hxx>
#include <TopTools_DataMapOfShapeBox.hxx>
#include <BOPAlgo_BuilderSolid.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <BOPAlgo_CellsBuilder.hxx>
#include <BOPAlgo_SectionAttribute.hxx>
#include <BOPDS_PIterator.hxx>
#include <NCollection_DataMap.hxx>
#include <BOPDS_PaveBlock.hxx>
#include <Bnd_Box.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfInteger.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <IntTools_ShrunkRange.hxx>
#include <BOPDS_IndexedDataMapOfShapeCoupleOfPaveBlocks.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <BOPDS_Curve.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <BOPDS_VectorOfCurve.hxx>
#include <BOPDS_IndexedMapOfPaveBlock.hxx>
#include <BOPDS_MapOfPaveBlock.hxx>
#include <BOPDS_DataMapOfPaveBlockListOfPaveBlock.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BOPDS_ListOfPaveBlock.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <TopoDS_Edge.hxx>
#include <BOPAlgo_CheckerSI.hxx>
#include <TopoDS_Solid.hxx>
#include <BOPAlgo_MakerVolume.hxx>
#include <BOPAlgo_PArgumentAnalyzer.hxx>
#include <BOPAlgo_PBOP.hxx>
#include <BOPAlgo_PBuilder.hxx>
#include <BOPAlgo_Section.hxx>
#include <BOPAlgo_PSection.hxx>
#include <BOPAlgo_WireEdgeSet.hxx>
#include <BOPAlgo_PWireEdgeSet.hxx>
#include <BRepTools_History.hxx>
#include <BOPAlgo_RemoveFeatures.hxx>
#include <BOPTools_ConnexityBlock.hxx>
#include <BOPTools_ListOfConnexityBlock.hxx>
#include <BOPAlgo_ShellSplitter.hxx>
#include <BOPAlgo_Splitter.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <BOPAlgo_Tools.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.hxx>
#include <BOPDS_CommonBlock.hxx>
#include <TopTools_IndexedDataMapOfShapeReal.hxx>
#include <TopTools_ListOfListOfShape.hxx>
#include <TopoDS_Wire.hxx>
#include <BOPAlgo_WireSplitter.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>

PYBIND11_MODULE(BOPAlgo, mod) {

py::module::import("OCCT.BOPDS");
py::module::import("OCCT.Message");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.IntTools");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.BOPTools");

// ENUM: BOPALGO_OPERATION
py::enum_<BOPAlgo_Operation>(mod, "BOPAlgo_Operation", "None")
	.value("BOPAlgo_COMMON", BOPAlgo_Operation::BOPAlgo_COMMON)
	.value("BOPAlgo_FUSE", BOPAlgo_Operation::BOPAlgo_FUSE)
	.value("BOPAlgo_CUT", BOPAlgo_Operation::BOPAlgo_CUT)
	.value("BOPAlgo_CUT21", BOPAlgo_Operation::BOPAlgo_CUT21)
	.value("BOPAlgo_SECTION", BOPAlgo_Operation::BOPAlgo_SECTION)
	.value("BOPAlgo_UNKNOWN", BOPAlgo_Operation::BOPAlgo_UNKNOWN)
	.export_values();


// ENUM: BOPALGO_CHECKSTATUS
py::enum_<BOPAlgo_CheckStatus>(mod, "BOPAlgo_CheckStatus", "None")
	.value("BOPAlgo_CheckUnknown", BOPAlgo_CheckStatus::BOPAlgo_CheckUnknown)
	.value("BOPAlgo_BadType", BOPAlgo_CheckStatus::BOPAlgo_BadType)
	.value("BOPAlgo_SelfIntersect", BOPAlgo_CheckStatus::BOPAlgo_SelfIntersect)
	.value("BOPAlgo_TooSmallEdge", BOPAlgo_CheckStatus::BOPAlgo_TooSmallEdge)
	.value("BOPAlgo_NonRecoverableFace", BOPAlgo_CheckStatus::BOPAlgo_NonRecoverableFace)
	.value("BOPAlgo_IncompatibilityOfVertex", BOPAlgo_CheckStatus::BOPAlgo_IncompatibilityOfVertex)
	.value("BOPAlgo_IncompatibilityOfEdge", BOPAlgo_CheckStatus::BOPAlgo_IncompatibilityOfEdge)
	.value("BOPAlgo_IncompatibilityOfFace", BOPAlgo_CheckStatus::BOPAlgo_IncompatibilityOfFace)
	.value("BOPAlgo_OperationAborted", BOPAlgo_CheckStatus::BOPAlgo_OperationAborted)
	.value("BOPAlgo_GeomAbs_C0", BOPAlgo_CheckStatus::BOPAlgo_GeomAbs_C0)
	.value("BOPAlgo_InvalidCurveOnSurface", BOPAlgo_CheckStatus::BOPAlgo_InvalidCurveOnSurface)
	.value("BOPAlgo_NotValid", BOPAlgo_CheckStatus::BOPAlgo_NotValid)
	.export_values();


// ENUM: BOPALGO_GLUEENUM
py::enum_<BOPAlgo_GlueEnum>(mod, "BOPAlgo_GlueEnum", "The Enumeration describes an additional option for the algorithms in the Boolean Component such as General Fuse, Boolean operations, Section, Maker Volume, Splitter and Cells Builder algorithms.")
	.value("BOPAlgo_GlueOff", BOPAlgo_GlueEnum::BOPAlgo_GlueOff)
	.value("BOPAlgo_GlueShift", BOPAlgo_GlueEnum::BOPAlgo_GlueShift)
	.value("BOPAlgo_GlueFull", BOPAlgo_GlueEnum::BOPAlgo_GlueFull)
	.export_values();


// CLASS: BOPALGO_ALERTBOPNOTALLOWED
py::class_<BOPAlgo_AlertBOPNotAllowed, opencascade::handle<BOPAlgo_AlertBOPNotAllowed>, Message_Alert> cls_BOPAlgo_AlertBOPNotAllowed(mod, "BOPAlgo_AlertBOPNotAllowed", "Boolean operation of given type is not allowed on the given inputs");

// Methods
cls_BOPAlgo_AlertBOPNotAllowed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertBOPNotAllowed::get_type_name, "None");
cls_BOPAlgo_AlertBOPNotAllowed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertBOPNotAllowed::get_type_descriptor, "None");
cls_BOPAlgo_AlertBOPNotAllowed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertBOPNotAllowed::*)() const) &BOPAlgo_AlertBOPNotAllowed::DynamicType, "None");

// CLASS: BOPALGO_ALERTBOPNOTSET
py::class_<BOPAlgo_AlertBOPNotSet, opencascade::handle<BOPAlgo_AlertBOPNotSet>, Message_Alert> cls_BOPAlgo_AlertBOPNotSet(mod, "BOPAlgo_AlertBOPNotSet", "The type of Boolean Operation is not set");

// Methods
cls_BOPAlgo_AlertBOPNotSet.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertBOPNotSet::get_type_name, "None");
cls_BOPAlgo_AlertBOPNotSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertBOPNotSet::get_type_descriptor, "None");
cls_BOPAlgo_AlertBOPNotSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertBOPNotSet::*)() const) &BOPAlgo_AlertBOPNotSet::DynamicType, "None");

// CLASS: BOPALGO_ALERTBUILDERFAILED
py::class_<BOPAlgo_AlertBuilderFailed, opencascade::handle<BOPAlgo_AlertBuilderFailed>, Message_Alert> cls_BOPAlgo_AlertBuilderFailed(mod, "BOPAlgo_AlertBuilderFailed", "Building of the result shape has failed");

// Methods
cls_BOPAlgo_AlertBuilderFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertBuilderFailed::get_type_name, "None");
cls_BOPAlgo_AlertBuilderFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertBuilderFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertBuilderFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertBuilderFailed::*)() const) &BOPAlgo_AlertBuilderFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTINTERSECTIONFAILED
py::class_<BOPAlgo_AlertIntersectionFailed, opencascade::handle<BOPAlgo_AlertIntersectionFailed>, Message_Alert> cls_BOPAlgo_AlertIntersectionFailed(mod, "BOPAlgo_AlertIntersectionFailed", "The intersection of the arguments has failed");

// Methods
cls_BOPAlgo_AlertIntersectionFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertIntersectionFailed::get_type_name, "None");
cls_BOPAlgo_AlertIntersectionFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertIntersectionFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertIntersectionFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertIntersectionFailed::*)() const) &BOPAlgo_AlertIntersectionFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTMULTIPLEARGUMENTS
py::class_<BOPAlgo_AlertMultipleArguments, opencascade::handle<BOPAlgo_AlertMultipleArguments>, Message_Alert> cls_BOPAlgo_AlertMultipleArguments(mod, "BOPAlgo_AlertMultipleArguments", "The type of Boolean Operation is not set");

// Methods
cls_BOPAlgo_AlertMultipleArguments.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertMultipleArguments::get_type_name, "None");
cls_BOPAlgo_AlertMultipleArguments.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertMultipleArguments::get_type_descriptor, "None");
cls_BOPAlgo_AlertMultipleArguments.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertMultipleArguments::*)() const) &BOPAlgo_AlertMultipleArguments::DynamicType, "None");

// CLASS: BOPALGO_ALERTNOFILLER
py::class_<BOPAlgo_AlertNoFiller, opencascade::handle<BOPAlgo_AlertNoFiller>, Message_Alert> cls_BOPAlgo_AlertNoFiller(mod, "BOPAlgo_AlertNoFiller", "The Pave Filler (the intersection tool) has not been created");

// Methods
cls_BOPAlgo_AlertNoFiller.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertNoFiller::get_type_name, "None");
cls_BOPAlgo_AlertNoFiller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertNoFiller::get_type_descriptor, "None");
cls_BOPAlgo_AlertNoFiller.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertNoFiller::*)() const) &BOPAlgo_AlertNoFiller::DynamicType, "None");

// CLASS: BOPALGO_ALERTNULLINPUTSHAPES
py::class_<BOPAlgo_AlertNullInputShapes, opencascade::handle<BOPAlgo_AlertNullInputShapes>, Message_Alert> cls_BOPAlgo_AlertNullInputShapes(mod, "BOPAlgo_AlertNullInputShapes", "Null input shapes");

// Methods
cls_BOPAlgo_AlertNullInputShapes.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertNullInputShapes::get_type_name, "None");
cls_BOPAlgo_AlertNullInputShapes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertNullInputShapes::get_type_descriptor, "None");
cls_BOPAlgo_AlertNullInputShapes.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertNullInputShapes::*)() const) &BOPAlgo_AlertNullInputShapes::DynamicType, "None");

// CLASS: BOPALGO_ALERTPOSTTREATFF
py::class_<BOPAlgo_AlertPostTreatFF, opencascade::handle<BOPAlgo_AlertPostTreatFF>, Message_Alert> cls_BOPAlgo_AlertPostTreatFF(mod, "BOPAlgo_AlertPostTreatFF", "Cannot connect face intersection curves");

// Methods
cls_BOPAlgo_AlertPostTreatFF.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertPostTreatFF::get_type_name, "None");
cls_BOPAlgo_AlertPostTreatFF.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertPostTreatFF::get_type_descriptor, "None");
cls_BOPAlgo_AlertPostTreatFF.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertPostTreatFF::*)() const) &BOPAlgo_AlertPostTreatFF::DynamicType, "None");

// CLASS: BOPALGO_ALERTSOLIDBUILDERFAILED
py::class_<BOPAlgo_AlertSolidBuilderFailed, opencascade::handle<BOPAlgo_AlertSolidBuilderFailed>, Message_Alert> cls_BOPAlgo_AlertSolidBuilderFailed(mod, "BOPAlgo_AlertSolidBuilderFailed", "The BuilderSolid algorithm has failed");

// Methods
cls_BOPAlgo_AlertSolidBuilderFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertSolidBuilderFailed::get_type_name, "None");
cls_BOPAlgo_AlertSolidBuilderFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertSolidBuilderFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertSolidBuilderFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertSolidBuilderFailed::*)() const) &BOPAlgo_AlertSolidBuilderFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTTOOFEWARGUMENTS
py::class_<BOPAlgo_AlertTooFewArguments, opencascade::handle<BOPAlgo_AlertTooFewArguments>, Message_Alert> cls_BOPAlgo_AlertTooFewArguments(mod, "BOPAlgo_AlertTooFewArguments", "There are no enough arguments to perform the operation");

// Methods
cls_BOPAlgo_AlertTooFewArguments.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertTooFewArguments::get_type_name, "None");
cls_BOPAlgo_AlertTooFewArguments.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertTooFewArguments::get_type_descriptor, "None");
cls_BOPAlgo_AlertTooFewArguments.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertTooFewArguments::*)() const) &BOPAlgo_AlertTooFewArguments::DynamicType, "None");

// CLASS: BOPALGO_ALERTBADPOSITIONING
py::class_<BOPAlgo_AlertBadPositioning, opencascade::handle<BOPAlgo_AlertBadPositioning>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertBadPositioning(mod, "BOPAlgo_AlertBadPositioning", "The positioning of the shapes leads to creation of the small edges without valid range");

// Constructors
cls_BOPAlgo_AlertBadPositioning.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertBadPositioning.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertBadPositioning::get_type_name, "None");
cls_BOPAlgo_AlertBadPositioning.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertBadPositioning::get_type_descriptor, "None");
cls_BOPAlgo_AlertBadPositioning.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertBadPositioning::*)() const) &BOPAlgo_AlertBadPositioning::DynamicType, "None");

// CLASS: BOPALGO_ALERTEMPTYSHAPE
py::class_<BOPAlgo_AlertEmptyShape, opencascade::handle<BOPAlgo_AlertEmptyShape>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertEmptyShape(mod, "BOPAlgo_AlertEmptyShape", "Some of the arguments are empty shapes");

// Constructors
cls_BOPAlgo_AlertEmptyShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertEmptyShape.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertEmptyShape::get_type_name, "None");
cls_BOPAlgo_AlertEmptyShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertEmptyShape::get_type_descriptor, "None");
cls_BOPAlgo_AlertEmptyShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertEmptyShape::*)() const) &BOPAlgo_AlertEmptyShape::DynamicType, "None");

// CLASS: BOPALGO_ALERTNOTSPLITTABLEEDGE
py::class_<BOPAlgo_AlertNotSplittableEdge, opencascade::handle<BOPAlgo_AlertNotSplittableEdge>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertNotSplittableEdge(mod, "BOPAlgo_AlertNotSplittableEdge", "Some edges are very small and have such a small valid range, that they cannot be split");

// Constructors
cls_BOPAlgo_AlertNotSplittableEdge.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertNotSplittableEdge.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertNotSplittableEdge::get_type_name, "None");
cls_BOPAlgo_AlertNotSplittableEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertNotSplittableEdge::get_type_descriptor, "None");
cls_BOPAlgo_AlertNotSplittableEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertNotSplittableEdge::*)() const) &BOPAlgo_AlertNotSplittableEdge::DynamicType, "None");

// CLASS: BOPALGO_ALERTREMOVALOFIBFOREDGESFAILED
py::class_<BOPAlgo_AlertRemovalOfIBForEdgesFailed, opencascade::handle<BOPAlgo_AlertRemovalOfIBForEdgesFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed(mod, "BOPAlgo_AlertRemovalOfIBForEdgesFailed", "Removal of internal boundaries among Edges has failed");

// Constructors
cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemovalOfIBForEdgesFailed::get_type_name, "None");
cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemovalOfIBForEdgesFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemovalOfIBForEdgesFailed::*)() const) &BOPAlgo_AlertRemovalOfIBForEdgesFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTREMOVALOFIBFORFACESFAILED
py::class_<BOPAlgo_AlertRemovalOfIBForFacesFailed, opencascade::handle<BOPAlgo_AlertRemovalOfIBForFacesFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertRemovalOfIBForFacesFailed(mod, "BOPAlgo_AlertRemovalOfIBForFacesFailed", "Removal of internal boundaries among Faces has failed");

// Constructors
cls_BOPAlgo_AlertRemovalOfIBForFacesFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertRemovalOfIBForFacesFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemovalOfIBForFacesFailed::get_type_name, "None");
cls_BOPAlgo_AlertRemovalOfIBForFacesFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemovalOfIBForFacesFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertRemovalOfIBForFacesFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemovalOfIBForFacesFailed::*)() const) &BOPAlgo_AlertRemovalOfIBForFacesFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTREMOVALOFIBFORMDIMSHAPES
py::class_<BOPAlgo_AlertRemovalOfIBForMDimShapes, opencascade::handle<BOPAlgo_AlertRemovalOfIBForMDimShapes>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertRemovalOfIBForMDimShapes(mod, "BOPAlgo_AlertRemovalOfIBForMDimShapes", "Removal of internal boundaries among the multi-dimensional shapes is not supported yet");

// Constructors
cls_BOPAlgo_AlertRemovalOfIBForMDimShapes.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertRemovalOfIBForMDimShapes.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemovalOfIBForMDimShapes::get_type_name, "None");
cls_BOPAlgo_AlertRemovalOfIBForMDimShapes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemovalOfIBForMDimShapes::get_type_descriptor, "None");
cls_BOPAlgo_AlertRemovalOfIBForMDimShapes.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemovalOfIBForMDimShapes::*)() const) &BOPAlgo_AlertRemovalOfIBForMDimShapes::DynamicType, "None");

// CLASS: BOPALGO_ALERTREMOVALOFIBFORSOLIDSFAILED
py::class_<BOPAlgo_AlertRemovalOfIBForSolidsFailed, opencascade::handle<BOPAlgo_AlertRemovalOfIBForSolidsFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed(mod, "BOPAlgo_AlertRemovalOfIBForSolidsFailed", "Removal of internal boundaries among Solids has failed");

// Constructors
cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemovalOfIBForSolidsFailed::get_type_name, "None");
cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemovalOfIBForSolidsFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemovalOfIBForSolidsFailed::*)() const) &BOPAlgo_AlertRemovalOfIBForSolidsFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTSELFINTERFERINGSHAPE
py::class_<BOPAlgo_AlertSelfInterferingShape, opencascade::handle<BOPAlgo_AlertSelfInterferingShape>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertSelfInterferingShape(mod, "BOPAlgo_AlertSelfInterferingShape", "Some of the arguments are self-interfering shapes");

// Constructors
cls_BOPAlgo_AlertSelfInterferingShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertSelfInterferingShape.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertSelfInterferingShape::get_type_name, "None");
cls_BOPAlgo_AlertSelfInterferingShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertSelfInterferingShape::get_type_descriptor, "None");
cls_BOPAlgo_AlertSelfInterferingShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertSelfInterferingShape::*)() const) &BOPAlgo_AlertSelfInterferingShape::DynamicType, "None");

// CLASS: BOPALGO_ALERTSHELLSPLITTERFAILED
py::class_<BOPAlgo_AlertShellSplitterFailed, opencascade::handle<BOPAlgo_AlertShellSplitterFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertShellSplitterFailed(mod, "BOPAlgo_AlertShellSplitterFailed", "The positioning of the shapes leads to creation of the small edges without valid range");

// Constructors
cls_BOPAlgo_AlertShellSplitterFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertShellSplitterFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertShellSplitterFailed::get_type_name, "None");
cls_BOPAlgo_AlertShellSplitterFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertShellSplitterFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertShellSplitterFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertShellSplitterFailed::*)() const) &BOPAlgo_AlertShellSplitterFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTTOOSMALLEDGE
py::class_<BOPAlgo_AlertTooSmallEdge, opencascade::handle<BOPAlgo_AlertTooSmallEdge>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertTooSmallEdge(mod, "BOPAlgo_AlertTooSmallEdge", "Some edges are too small and have no valid range");

// Constructors
cls_BOPAlgo_AlertTooSmallEdge.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertTooSmallEdge.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertTooSmallEdge::get_type_name, "None");
cls_BOPAlgo_AlertTooSmallEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertTooSmallEdge::get_type_descriptor, "None");
cls_BOPAlgo_AlertTooSmallEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertTooSmallEdge::*)() const) &BOPAlgo_AlertTooSmallEdge::DynamicType, "None");

// CLASS: BOPALGO_ALERTINTERSECTIONOFPAIROFSHAPESFAILED
py::class_<BOPAlgo_AlertIntersectionOfPairOfShapesFailed, opencascade::handle<BOPAlgo_AlertIntersectionOfPairOfShapesFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertIntersectionOfPairOfShapesFailed(mod, "BOPAlgo_AlertIntersectionOfPairOfShapesFailed", "Intersection of pair of shapes has failed");

// Constructors
cls_BOPAlgo_AlertIntersectionOfPairOfShapesFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertIntersectionOfPairOfShapesFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertIntersectionOfPairOfShapesFailed::get_type_name, "None");
cls_BOPAlgo_AlertIntersectionOfPairOfShapesFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertIntersectionOfPairOfShapesFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertIntersectionOfPairOfShapesFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertIntersectionOfPairOfShapesFailed::*)() const) &BOPAlgo_AlertIntersectionOfPairOfShapesFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTBUILDINGPCURVEFAILED
py::class_<BOPAlgo_AlertBuildingPCurveFailed, opencascade::handle<BOPAlgo_AlertBuildingPCurveFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertBuildingPCurveFailed(mod, "BOPAlgo_AlertBuildingPCurveFailed", "Building 2D curve of edge on face has failed");

// Constructors
cls_BOPAlgo_AlertBuildingPCurveFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertBuildingPCurveFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertBuildingPCurveFailed::get_type_name, "None");
cls_BOPAlgo_AlertBuildingPCurveFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertBuildingPCurveFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertBuildingPCurveFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertBuildingPCurveFailed::*)() const) &BOPAlgo_AlertBuildingPCurveFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTACQUIREDSELFINTERSECTION
py::class_<BOPAlgo_AlertAcquiredSelfIntersection, opencascade::handle<BOPAlgo_AlertAcquiredSelfIntersection>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertAcquiredSelfIntersection(mod, "BOPAlgo_AlertAcquiredSelfIntersection", "Some sub-shapes of some of the argument become connected through other shapes and the argument became self-interfered");

// Constructors
cls_BOPAlgo_AlertAcquiredSelfIntersection.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertAcquiredSelfIntersection.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertAcquiredSelfIntersection::get_type_name, "None");
cls_BOPAlgo_AlertAcquiredSelfIntersection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertAcquiredSelfIntersection::get_type_descriptor, "None");
cls_BOPAlgo_AlertAcquiredSelfIntersection.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertAcquiredSelfIntersection::*)() const) &BOPAlgo_AlertAcquiredSelfIntersection::DynamicType, "None");

// CLASS: BOPALGO_ALERTUNSUPPORTEDTYPE
py::class_<BOPAlgo_AlertUnsupportedType, opencascade::handle<BOPAlgo_AlertUnsupportedType>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertUnsupportedType(mod, "BOPAlgo_AlertUnsupportedType", "Unsupported type of input shape");

// Constructors
cls_BOPAlgo_AlertUnsupportedType.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertUnsupportedType.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertUnsupportedType::get_type_name, "None");
cls_BOPAlgo_AlertUnsupportedType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertUnsupportedType::get_type_descriptor, "None");
cls_BOPAlgo_AlertUnsupportedType.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertUnsupportedType::*)() const) &BOPAlgo_AlertUnsupportedType::DynamicType, "None");

// CLASS: BOPALGO_ALERTNOFACESTOREMOVE
py::class_<BOPAlgo_AlertNoFacesToRemove, opencascade::handle<BOPAlgo_AlertNoFacesToRemove>, Message_Alert> cls_BOPAlgo_AlertNoFacesToRemove(mod, "BOPAlgo_AlertNoFacesToRemove", "No faces have been found for removal");

// Methods
cls_BOPAlgo_AlertNoFacesToRemove.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertNoFacesToRemove::get_type_name, "None");
cls_BOPAlgo_AlertNoFacesToRemove.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertNoFacesToRemove::get_type_descriptor, "None");
cls_BOPAlgo_AlertNoFacesToRemove.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertNoFacesToRemove::*)() const) &BOPAlgo_AlertNoFacesToRemove::DynamicType, "None");

// CLASS: BOPALGO_ALERTUNABLETOREMOVETHEFEATURE
py::class_<BOPAlgo_AlertUnableToRemoveTheFeature, opencascade::handle<BOPAlgo_AlertUnableToRemoveTheFeature>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertUnableToRemoveTheFeature(mod, "BOPAlgo_AlertUnableToRemoveTheFeature", "Unable to remove the feature");

// Constructors
cls_BOPAlgo_AlertUnableToRemoveTheFeature.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertUnableToRemoveTheFeature.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertUnableToRemoveTheFeature::get_type_name, "None");
cls_BOPAlgo_AlertUnableToRemoveTheFeature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertUnableToRemoveTheFeature::get_type_descriptor, "None");
cls_BOPAlgo_AlertUnableToRemoveTheFeature.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertUnableToRemoveTheFeature::*)() const) &BOPAlgo_AlertUnableToRemoveTheFeature::DynamicType, "None");

// CLASS: BOPALGO_ALERTREMOVEFEATURESFAILED
py::class_<BOPAlgo_AlertRemoveFeaturesFailed, opencascade::handle<BOPAlgo_AlertRemoveFeaturesFailed>, Message_Alert> cls_BOPAlgo_AlertRemoveFeaturesFailed(mod, "BOPAlgo_AlertRemoveFeaturesFailed", "The Feature Removal algorithm has failed");

// Methods
cls_BOPAlgo_AlertRemoveFeaturesFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemoveFeaturesFailed::get_type_name, "None");
cls_BOPAlgo_AlertRemoveFeaturesFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemoveFeaturesFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertRemoveFeaturesFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemoveFeaturesFailed::*)() const) &BOPAlgo_AlertRemoveFeaturesFailed::DynamicType, "None");

// CLASS: BOPALGO_ALERTSOLIDBUILDERUNUSEDFACES
py::class_<BOPAlgo_AlertSolidBuilderUnusedFaces, opencascade::handle<BOPAlgo_AlertSolidBuilderUnusedFaces>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertSolidBuilderUnusedFaces(mod, "BOPAlgo_AlertSolidBuilderUnusedFaces", "Some of the faces passed to the Solid Builder algorithm have not been classified and not used for solids creation");

// Constructors
cls_BOPAlgo_AlertSolidBuilderUnusedFaces.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertSolidBuilderUnusedFaces.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertSolidBuilderUnusedFaces::get_type_name, "None");
cls_BOPAlgo_AlertSolidBuilderUnusedFaces.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertSolidBuilderUnusedFaces::get_type_descriptor, "None");
cls_BOPAlgo_AlertSolidBuilderUnusedFaces.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertSolidBuilderUnusedFaces::*)() const) &BOPAlgo_AlertSolidBuilderUnusedFaces::DynamicType, "None");

// CLASS: BOPALGO_ALERTUNABLETOORIENTTHESHAPE
py::class_<BOPAlgo_AlertUnableToOrientTheShape, opencascade::handle<BOPAlgo_AlertUnableToOrientTheShape>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertUnableToOrientTheShape(mod, "BOPAlgo_AlertUnableToOrientTheShape", "Unable to orient the shape correctly");

// Constructors
cls_BOPAlgo_AlertUnableToOrientTheShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BOPAlgo_AlertUnableToOrientTheShape.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertUnableToOrientTheShape::get_type_name, "None");
cls_BOPAlgo_AlertUnableToOrientTheShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertUnableToOrientTheShape::get_type_descriptor, "None");
cls_BOPAlgo_AlertUnableToOrientTheShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertUnableToOrientTheShape::*)() const) &BOPAlgo_AlertUnableToOrientTheShape::DynamicType, "None");

// CLASS: BOPALGO_OPTIONS
py::class_<BOPAlgo_Options> cls_BOPAlgo_Options(mod, "BOPAlgo_Options", "The class provides the following options for the algorithms in Boolean Component: - *Memory allocation tool* - tool for memory allocations; - *Error and warning reporting* - allows recording warnings and errors occurred during the operation. Error means that the algorithm has failed. - *Parallel processing mode* - provides the possibility to perform operation in parallel mode; - *Fuzzy tolerance* - additional tolerance for the operation to detect touching or coinciding cases; - *Progress indicator* - provides interface to track the progress of operation and stop the operation by user's break. - *Using the Oriented Bounding Boxes* - Allows using the Oriented Bounding Boxes of the shapes for filtering the intersections.");

// Constructors
cls_BOPAlgo_Options.def(py::init<>());
cls_BOPAlgo_Options.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_Options.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_Options::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_Options.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_Options::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_Options.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_Options::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_Options.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_Options::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_Options.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_Options::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_Options.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_Options::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_Options.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (BOPAlgo_Options::*)() const) &BOPAlgo_Options::Allocator, "Returns allocator");
cls_BOPAlgo_Options.def("Clear", (void (BOPAlgo_Options::*)()) &BOPAlgo_Options::Clear, "Clears all warnings and errors, and any data cached by the algorithm. User defined options are not cleared.");
cls_BOPAlgo_Options.def("AddError", (void (BOPAlgo_Options::*)(const opencascade::handle<Message_Alert> &)) &BOPAlgo_Options::AddError, "Adds the alert as error (fail)", py::arg("theAlert"));
cls_BOPAlgo_Options.def("AddWarning", (void (BOPAlgo_Options::*)(const opencascade::handle<Message_Alert> &)) &BOPAlgo_Options::AddWarning, "Adds the alert as warning", py::arg("theAlert"));
cls_BOPAlgo_Options.def("HasErrors", (Standard_Boolean (BOPAlgo_Options::*)() const) &BOPAlgo_Options::HasErrors, "Returns true if algorithm has failed");
cls_BOPAlgo_Options.def("HasError", (Standard_Boolean (BOPAlgo_Options::*)(const opencascade::handle<Standard_Type> &) const) &BOPAlgo_Options::HasError, "Returns true if algorithm has generated error of specified type", py::arg("theType"));
cls_BOPAlgo_Options.def("HasWarnings", (Standard_Boolean (BOPAlgo_Options::*)() const) &BOPAlgo_Options::HasWarnings, "Returns true if algorithm has generated some warning alerts");
cls_BOPAlgo_Options.def("HasWarning", (Standard_Boolean (BOPAlgo_Options::*)(const opencascade::handle<Standard_Type> &) const) &BOPAlgo_Options::HasWarning, "Returns true if algorithm has generated warning of specified type", py::arg("theType"));
cls_BOPAlgo_Options.def("GetReport", (const opencascade::handle<Message_Report> & (BOPAlgo_Options::*)() const) &BOPAlgo_Options::GetReport, "Returns report collecting all errors and warnings");
cls_BOPAlgo_Options.def("DumpErrors", (void (BOPAlgo_Options::*)(Standard_OStream &) const) &BOPAlgo_Options::DumpErrors, "Dumps the error status into the given stream", py::arg("theOS"));
cls_BOPAlgo_Options.def("DumpWarnings", (void (BOPAlgo_Options::*)(Standard_OStream &) const) &BOPAlgo_Options::DumpWarnings, "Dumps the warning statuses into the given stream", py::arg("theOS"));
cls_BOPAlgo_Options.def("ClearWarnings", (void (BOPAlgo_Options::*)()) &BOPAlgo_Options::ClearWarnings, "Clears the warnings of the algorithm");
cls_BOPAlgo_Options.def_static("GetParallelMode_", (Standard_Boolean (*)()) &BOPAlgo_Options::GetParallelMode, "Gets the global parallel mode");
cls_BOPAlgo_Options.def_static("SetParallelMode_", (void (*)(const Standard_Boolean)) &BOPAlgo_Options::SetParallelMode, "Sets the global parallel mode", py::arg("theNewMode"));
cls_BOPAlgo_Options.def("SetRunParallel", (void (BOPAlgo_Options::*)(const Standard_Boolean)) &BOPAlgo_Options::SetRunParallel, "Set the flag of parallel processing if <theFlag> is true the parallel processing is switched on if <theFlag> is false the parallel processing is switched off", py::arg("theFlag"));
cls_BOPAlgo_Options.def("RunParallel", (Standard_Boolean (BOPAlgo_Options::*)() const) &BOPAlgo_Options::RunParallel, "Returns the flag of parallel processing");
cls_BOPAlgo_Options.def("SetFuzzyValue", (void (BOPAlgo_Options::*)(const Standard_Real)) &BOPAlgo_Options::SetFuzzyValue, "Sets the additional tolerance", py::arg("theFuzz"));
cls_BOPAlgo_Options.def("FuzzyValue", (Standard_Real (BOPAlgo_Options::*)() const) &BOPAlgo_Options::FuzzyValue, "Returns the additional tolerance");
cls_BOPAlgo_Options.def("SetProgressIndicator", (void (BOPAlgo_Options::*)(const opencascade::handle<Message_ProgressIndicator> &)) &BOPAlgo_Options::SetProgressIndicator, "Set the Progress Indicator object.", py::arg("theObj"));
cls_BOPAlgo_Options.def("SetUseOBB", (void (BOPAlgo_Options::*)(const Standard_Boolean)) &BOPAlgo_Options::SetUseOBB, "Enables/Disables the usage of OBB", py::arg("theUseOBB"));
cls_BOPAlgo_Options.def("UseOBB", (Standard_Boolean (BOPAlgo_Options::*)() const) &BOPAlgo_Options::UseOBB, "Returns the flag defining usage of OBB");

// CLASS: BOPALGO_ALGO
py::class_<BOPAlgo_Algo, std::unique_ptr<BOPAlgo_Algo, py::nodelete>, BOPAlgo_Options> cls_BOPAlgo_Algo(mod, "BOPAlgo_Algo", "The class provides the root interface for the algorithms in Boolean Component.");

// Methods
// cls_BOPAlgo_Algo.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_Algo::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_Algo.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_Algo::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_Algo.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_Algo::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_Algo.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_Algo::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_Algo.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_Algo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_Algo.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_Algo::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_Algo.def("Perform", (void (BOPAlgo_Algo::*)()) &BOPAlgo_Algo::Perform, "None");

// CLASS: BOPALGO_CHECKRESULT
py::class_<BOPAlgo_CheckResult> cls_BOPAlgo_CheckResult(mod, "BOPAlgo_CheckResult", "contains information about faulty shapes and faulty types can't be processed by Boolean Operations");

// Constructors
cls_BOPAlgo_CheckResult.def(py::init<>());

// Methods
// cls_BOPAlgo_CheckResult.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_CheckResult::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_CheckResult.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_CheckResult::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_CheckResult.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_CheckResult::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_CheckResult.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_CheckResult::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_CheckResult.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_CheckResult::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_CheckResult.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_CheckResult::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_CheckResult.def("SetShape1", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::SetShape1, "sets ancestor shape (object) for faulty sub-shapes", py::arg("TheShape"));
cls_BOPAlgo_CheckResult.def("AddFaultyShape1", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::AddFaultyShape1, "adds faulty sub-shapes from object to a list", py::arg("TheShape"));
cls_BOPAlgo_CheckResult.def("SetShape2", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::SetShape2, "sets ancestor shape (tool) for faulty sub-shapes", py::arg("TheShape"));
cls_BOPAlgo_CheckResult.def("AddFaultyShape2", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::AddFaultyShape2, "adds faulty sub-shapes from tool to a list", py::arg("TheShape"));
cls_BOPAlgo_CheckResult.def("GetShape1", (const TopoDS_Shape & (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetShape1, "returns ancestor shape (object) for faulties");
cls_BOPAlgo_CheckResult.def("GetShape2", (const TopoDS_Shape & (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetShape2, "returns ancestor shape (tool) for faulties");
cls_BOPAlgo_CheckResult.def("GetFaultyShapes1", (const TopTools_ListOfShape & (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetFaultyShapes1, "returns list of faulty shapes for object");
cls_BOPAlgo_CheckResult.def("GetFaultyShapes2", (const TopTools_ListOfShape & (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetFaultyShapes2, "returns list of faulty shapes for tool");
cls_BOPAlgo_CheckResult.def("SetCheckStatus", (void (BOPAlgo_CheckResult::*)(const BOPAlgo_CheckStatus)) &BOPAlgo_CheckResult::SetCheckStatus, "set status of faulty", py::arg("TheStatus"));
cls_BOPAlgo_CheckResult.def("GetCheckStatus", (BOPAlgo_CheckStatus (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetCheckStatus, "gets status of faulty");
cls_BOPAlgo_CheckResult.def("SetMaxDistance1", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxDistance1, "Sets max distance for the first shape", py::arg("theDist"));
cls_BOPAlgo_CheckResult.def("SetMaxDistance2", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxDistance2, "Sets max distance for the second shape", py::arg("theDist"));
cls_BOPAlgo_CheckResult.def("SetMaxParameter1", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxParameter1, "Sets the parameter for the first shape", py::arg("thePar"));
cls_BOPAlgo_CheckResult.def("SetMaxParameter2", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxParameter2, "Sets the parameter for the second shape", py::arg("thePar"));
cls_BOPAlgo_CheckResult.def("GetMaxDistance1", (Standard_Real (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetMaxDistance1, "Returns the distance for the first shape");
cls_BOPAlgo_CheckResult.def("GetMaxDistance2", (Standard_Real (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetMaxDistance2, "Returns the distance for the second shape");
cls_BOPAlgo_CheckResult.def("GetMaxParameter1", (Standard_Real (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetMaxParameter1, "Returns the parameter for the fircst shape");
cls_BOPAlgo_CheckResult.def("GetMaxParameter2", (Standard_Real (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetMaxParameter2, "Returns the parameter for the second shape");

// TYPEDEF: BOPALGO_LISTOFCHECKRESULT
bind_NCollection_List<BOPAlgo_CheckResult>(mod, "BOPAlgo_ListOfCheckResult", py::module_local(false));

// TYPEDEF: BOPALGO_LISTITERATOROFLISTOFCHECKRESULT
bind_NCollection_TListIterator<BOPAlgo_CheckResult>(mod, "BOPAlgo_ListIteratorOfListOfCheckResult", py::module_local(false));

// CLASS: BOPALGO_ARGUMENTANALYZER
py::class_<BOPAlgo_ArgumentAnalyzer, BOPAlgo_Algo> cls_BOPAlgo_ArgumentAnalyzer(mod, "BOPAlgo_ArgumentAnalyzer", "check the validity of argument(s) for Boolean Operations");

// Constructors
cls_BOPAlgo_ArgumentAnalyzer.def(py::init<>());

// Methods
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_ArgumentAnalyzer::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_ArgumentAnalyzer::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_ArgumentAnalyzer::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_ArgumentAnalyzer::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_ArgumentAnalyzer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_ArgumentAnalyzer.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_ArgumentAnalyzer::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_ArgumentAnalyzer.def("SetShape1", (void (BOPAlgo_ArgumentAnalyzer::*)(const TopoDS_Shape &)) &BOPAlgo_ArgumentAnalyzer::SetShape1, "sets object shape", py::arg("TheShape"));
cls_BOPAlgo_ArgumentAnalyzer.def("SetShape2", (void (BOPAlgo_ArgumentAnalyzer::*)(const TopoDS_Shape &)) &BOPAlgo_ArgumentAnalyzer::SetShape2, "sets tool shape", py::arg("TheShape"));
cls_BOPAlgo_ArgumentAnalyzer.def("GetShape1", (const TopoDS_Shape & (BOPAlgo_ArgumentAnalyzer::*)() const) &BOPAlgo_ArgumentAnalyzer::GetShape1, "returns object shape;");
cls_BOPAlgo_ArgumentAnalyzer.def("GetShape2", (const TopoDS_Shape & (BOPAlgo_ArgumentAnalyzer::*)() const) &BOPAlgo_ArgumentAnalyzer::GetShape2, "returns tool shape");
cls_BOPAlgo_ArgumentAnalyzer.def("OperationType", (BOPAlgo_Operation & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::OperationType, "returns ref");
cls_BOPAlgo_ArgumentAnalyzer.def("StopOnFirstFaulty", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::StopOnFirstFaulty, "returns ref");
cls_BOPAlgo_ArgumentAnalyzer.def("ArgumentTypeMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::ArgumentTypeMode, "Returns (modifiable) mode that means checking types of shapes.");
cls_BOPAlgo_ArgumentAnalyzer.def("SelfInterMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::SelfInterMode, "Returns (modifiable) mode that means checking of self-intersection of shapes.");
cls_BOPAlgo_ArgumentAnalyzer.def("SmallEdgeMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::SmallEdgeMode, "Returns (modifiable) mode that means checking of small edges.");
cls_BOPAlgo_ArgumentAnalyzer.def("RebuildFaceMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::RebuildFaceMode, "Returns (modifiable) mode that means checking of possibility to split or rebuild faces.");
cls_BOPAlgo_ArgumentAnalyzer.def("TangentMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::TangentMode, "Returns (modifiable) mode that means checking of tangency between subshapes.");
cls_BOPAlgo_ArgumentAnalyzer.def("MergeVertexMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::MergeVertexMode, "Returns (modifiable) mode that means checking of problem of merging vertices.");
cls_BOPAlgo_ArgumentAnalyzer.def("MergeEdgeMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::MergeEdgeMode, "Returns (modifiable) mode that means checking of problem of merging edges.");
cls_BOPAlgo_ArgumentAnalyzer.def("ContinuityMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::ContinuityMode, "Returns (modifiable) mode that means checking of problem of continuity of the shape.");
cls_BOPAlgo_ArgumentAnalyzer.def("CurveOnSurfaceMode", (Standard_Boolean & (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::CurveOnSurfaceMode, "Returns (modifiable) mode that means checking of problem of invalid curve on surface.");
cls_BOPAlgo_ArgumentAnalyzer.def("Perform", (void (BOPAlgo_ArgumentAnalyzer::*)()) &BOPAlgo_ArgumentAnalyzer::Perform, "performs analysis");
cls_BOPAlgo_ArgumentAnalyzer.def("HasFaulty", (Standard_Boolean (BOPAlgo_ArgumentAnalyzer::*)() const) &BOPAlgo_ArgumentAnalyzer::HasFaulty, "result of test");
cls_BOPAlgo_ArgumentAnalyzer.def("GetCheckResult", (const BOPAlgo_ListOfCheckResult & (BOPAlgo_ArgumentAnalyzer::*)() const) &BOPAlgo_ArgumentAnalyzer::GetCheckResult, "returns a result of test");

// TYPEDEF: BOPALGO_PPAVEFILLER

// CLASS: BOPALGO_BUILDERSHAPE
py::class_<BOPAlgo_BuilderShape, std::unique_ptr<BOPAlgo_BuilderShape, py::nodelete>, BOPAlgo_Algo> cls_BOPAlgo_BuilderShape(mod, "BOPAlgo_BuilderShape", "Root class for algorithms that has shape as result. The class provides the History mechanism, which allows tracking the modification of the input shapes during the operation.");

// Methods
// cls_BOPAlgo_BuilderShape.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BuilderShape::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderShape.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BuilderShape::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderShape.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BuilderShape::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderShape.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BuilderShape::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderShape.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BuilderShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BuilderShape.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BuilderShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BuilderShape.def("Shape", (const TopoDS_Shape & (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::Shape, "Returns the result of algorithm");
cls_BOPAlgo_BuilderShape.def("Generated", (const TopTools_ListOfShape & (BOPAlgo_BuilderShape::*)(const TopoDS_Shape &)) &BOPAlgo_BuilderShape::Generated, "Returns the list of shapes generated from the shape theS.", py::arg("theS"));
cls_BOPAlgo_BuilderShape.def("Modified", (const TopTools_ListOfShape & (BOPAlgo_BuilderShape::*)(const TopoDS_Shape &)) &BOPAlgo_BuilderShape::Modified, "Returns the list of shapes modified from the shape theS.", py::arg("theS"));
cls_BOPAlgo_BuilderShape.def("IsDeleted", (Standard_Boolean (BOPAlgo_BuilderShape::*)(const TopoDS_Shape &)) &BOPAlgo_BuilderShape::IsDeleted, "Returns true if the shape theS has been deleted.", py::arg("theS"));
cls_BOPAlgo_BuilderShape.def("HasDeleted", (Standard_Boolean (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::HasDeleted, "Returns true if the at least one shape(or subshape) of arguments has been deleted.");
cls_BOPAlgo_BuilderShape.def("HasGenerated", (Standard_Boolean (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::HasGenerated, "Returns true if the at least one shape(or subshape) of arguments has generated shapes.");
cls_BOPAlgo_BuilderShape.def("HasModified", (Standard_Boolean (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::HasModified, "Returns true if the at least one shape(or subshape) of arguments has modified shapes.");
cls_BOPAlgo_BuilderShape.def("ImagesResult", (const TopTools_IndexedDataMapOfShapeListOfShape & (BOPAlgo_BuilderShape::*)() const) &BOPAlgo_BuilderShape::ImagesResult, "None");

// CLASS: BOPALGO_BUILDER
py::class_<BOPAlgo_Builder, BOPAlgo_BuilderShape> cls_BOPAlgo_Builder(mod, "BOPAlgo_Builder", "The class is a General Fuse algorithm - base algorithm for the algorithms in the Boolean Component. Its main purpose is to build the split parts of the argument shapes from which the result of the operations is combined. The result of the General Fuse algorithm itself is a compound containing all split parts of the arguments.");

// Constructors
cls_BOPAlgo_Builder.def(py::init<>());
cls_BOPAlgo_Builder.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_Builder.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_Builder::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_Builder.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_Builder::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_Builder.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_Builder::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_Builder.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_Builder.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_Builder.def("Clear", (void (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::Clear, "Clears the content of the algorithm.");
cls_BOPAlgo_Builder.def("PPaveFiller", (BOPAlgo_PPaveFiller (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::PPaveFiller, "Returns the PaveFiller, algorithm for sub-shapes intersection.");
cls_BOPAlgo_Builder.def("PDS", (BOPDS_PDS (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::PDS, "Returns the Data Structure, holder of intersection information.");
cls_BOPAlgo_Builder.def("Context", (opencascade::handle<IntTools_Context> (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Context, "Returns the Context, tool for cashing heavy algorithms.");
cls_BOPAlgo_Builder.def("AddArgument", (void (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::AddArgument, "Adds the argument to the operation.", py::arg("theShape"));
cls_BOPAlgo_Builder.def("SetArguments", (void (BOPAlgo_Builder::*)(const TopTools_ListOfShape &)) &BOPAlgo_Builder::SetArguments, "Sets the list of arguments for the operation.", py::arg("theLS"));
cls_BOPAlgo_Builder.def("Arguments", (const TopTools_ListOfShape & (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Arguments, "Returns the list of arguments.");
cls_BOPAlgo_Builder.def("SetNonDestructive", (void (BOPAlgo_Builder::*)(const Standard_Boolean)) &BOPAlgo_Builder::SetNonDestructive, "Sets the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated. This flag is taken into account if internal PaveFiller is used only. In the case of calling PerformWithFiller the corresponding flag of that PaveFiller is in force.", py::arg("theFlag"));
cls_BOPAlgo_Builder.def("NonDestructive", (Standard_Boolean (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::NonDestructive, "Returns the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.");
cls_BOPAlgo_Builder.def("SetGlue", (void (BOPAlgo_Builder::*)(const BOPAlgo_GlueEnum)) &BOPAlgo_Builder::SetGlue, "Sets the glue option for the algorithm", py::arg("theGlue"));
cls_BOPAlgo_Builder.def("Glue", (BOPAlgo_GlueEnum (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Glue, "Returns the glue option of the algorithm");
cls_BOPAlgo_Builder.def("SetCheckInverted", (void (BOPAlgo_Builder::*)(const Standard_Boolean)) &BOPAlgo_Builder::SetCheckInverted, "Enables/Disables the check of the input solids for inverted status", py::arg("theCheck"));
cls_BOPAlgo_Builder.def("CheckInverted", (Standard_Boolean (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::CheckInverted, "Returns the flag defining whether the check for input solids on inverted status should be performed or not.");
cls_BOPAlgo_Builder.def("Perform", (void (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::Perform, "Performs the operation. The intersection will be performed also.");
cls_BOPAlgo_Builder.def("PerformWithFiller", (void (BOPAlgo_Builder::*)(const BOPAlgo_PaveFiller &)) &BOPAlgo_Builder::PerformWithFiller, "Performs the operation with the prepared filler. The intersection will not be performed in this case.", py::arg("theFiller"));
cls_BOPAlgo_Builder.def("Generated", (const TopTools_ListOfShape & (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::Generated, "Returns the list of shapes generated from the shape theS.", py::arg("theS"));
cls_BOPAlgo_Builder.def("Modified", (const TopTools_ListOfShape & (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::Modified, "Returns the list of shapes modified from the shape theS.", py::arg("theS"));
cls_BOPAlgo_Builder.def("IsDeleted", (Standard_Boolean (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::IsDeleted, "Returns true if the shape theS has been deleted.", py::arg("theS"));
cls_BOPAlgo_Builder.def("Images", (const TopTools_DataMapOfShapeListOfShape & (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Images, "Returns the map of images.");
cls_BOPAlgo_Builder.def("Origins", (const TopTools_DataMapOfShapeListOfShape & (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::Origins, "Returns the map of origins.");
cls_BOPAlgo_Builder.def("ShapesSD", (const TopTools_DataMapOfShapeShape & (BOPAlgo_Builder::*)() const) &BOPAlgo_Builder::ShapesSD, "Returns the map of Same Domain (SD) shapes - coinciding shapes from different arguments.");

// CLASS: BOPALGO_TOOLSPROVIDER
py::class_<BOPAlgo_ToolsProvider, BOPAlgo_Builder> cls_BOPAlgo_ToolsProvider(mod, "BOPAlgo_ToolsProvider", "Auxiliary class providing API to operate tool arguments.");

// Constructors
cls_BOPAlgo_ToolsProvider.def(py::init<>());
cls_BOPAlgo_ToolsProvider.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_ToolsProvider.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_ToolsProvider::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_ToolsProvider.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_ToolsProvider::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_ToolsProvider.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_ToolsProvider::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_ToolsProvider.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_ToolsProvider::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_ToolsProvider.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_ToolsProvider::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_ToolsProvider.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_ToolsProvider::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_ToolsProvider.def("Clear", (void (BOPAlgo_ToolsProvider::*)()) &BOPAlgo_ToolsProvider::Clear, "Clears internal fields and arguments");
cls_BOPAlgo_ToolsProvider.def("AddTool", (void (BOPAlgo_ToolsProvider::*)(const TopoDS_Shape &)) &BOPAlgo_ToolsProvider::AddTool, "Adds Tool argument of the operation", py::arg("theShape"));
cls_BOPAlgo_ToolsProvider.def("SetTools", (void (BOPAlgo_ToolsProvider::*)(const TopTools_ListOfShape &)) &BOPAlgo_ToolsProvider::SetTools, "Adds the Tool arguments of the operation", py::arg("theShapes"));
cls_BOPAlgo_ToolsProvider.def("Tools", (const TopTools_ListOfShape & (BOPAlgo_ToolsProvider::*)() const) &BOPAlgo_ToolsProvider::Tools, "Returns the Tool arguments of the operation");

// CLASS: BOPALGO_BOP
py::class_<BOPAlgo_BOP, BOPAlgo_ToolsProvider> cls_BOPAlgo_BOP(mod, "BOPAlgo_BOP", "The class represents the Building part of the Boolean Operations algorithm. The arguments of the algorithms are divided in two groups - *Objects* and *Tools*. The algorithm builds the splits of the given arguments using the intersection results and combines the result of Boolean Operation of given type: - *FUSE* - union of two groups of objects; - *COMMON* - intersection of two groups of objects; - *CUT* - subtraction of one group from the other.");

// Constructors
cls_BOPAlgo_BOP.def(py::init<>());
cls_BOPAlgo_BOP.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_BOP.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BOP::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BOP.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BOP::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BOP.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BOP::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BOP.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BOP::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BOP.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BOP::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BOP.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BOP::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BOP.def("Clear", (void (BOPAlgo_BOP::*)()) &BOPAlgo_BOP::Clear, "Clears internal fields and arguments");
cls_BOPAlgo_BOP.def("SetOperation", (void (BOPAlgo_BOP::*)(const BOPAlgo_Operation)) &BOPAlgo_BOP::SetOperation, "None", py::arg("theOperation"));
cls_BOPAlgo_BOP.def("Operation", (BOPAlgo_Operation (BOPAlgo_BOP::*)() const) &BOPAlgo_BOP::Operation, "None");
cls_BOPAlgo_BOP.def("Perform", (void (BOPAlgo_BOP::*)()) &BOPAlgo_BOP::Perform, "None");

// CLASS: BOPALGO_BUILDERAREA
py::class_<BOPAlgo_BuilderArea, std::unique_ptr<BOPAlgo_BuilderArea, py::nodelete>, BOPAlgo_Algo> cls_BOPAlgo_BuilderArea(mod, "BOPAlgo_BuilderArea", "The root class for algorithms to build faces/solids from set of edges/faces");

// Methods
// cls_BOPAlgo_BuilderArea.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BuilderArea::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderArea.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BuilderArea::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderArea.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BuilderArea::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderArea.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BuilderArea::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderArea.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BuilderArea::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BuilderArea.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BuilderArea::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BuilderArea.def("SetContext", (void (BOPAlgo_BuilderArea::*)(const opencascade::handle<IntTools_Context> &)) &BOPAlgo_BuilderArea::SetContext, "Sets the context for the algorithms", py::arg("theContext"));
cls_BOPAlgo_BuilderArea.def("Shapes", (const TopTools_ListOfShape & (BOPAlgo_BuilderArea::*)() const) &BOPAlgo_BuilderArea::Shapes, "Returns the input shapes");
cls_BOPAlgo_BuilderArea.def("SetShapes", (void (BOPAlgo_BuilderArea::*)(const TopTools_ListOfShape &)) &BOPAlgo_BuilderArea::SetShapes, "Sets the shapes for building areas", py::arg("theLS"));
cls_BOPAlgo_BuilderArea.def("Loops", (const TopTools_ListOfShape & (BOPAlgo_BuilderArea::*)() const) &BOPAlgo_BuilderArea::Loops, "Returns the found loops");
cls_BOPAlgo_BuilderArea.def("Areas", (const TopTools_ListOfShape & (BOPAlgo_BuilderArea::*)() const) &BOPAlgo_BuilderArea::Areas, "Returns the found areas");
cls_BOPAlgo_BuilderArea.def("SetAvoidInternalShapes", (void (BOPAlgo_BuilderArea::*)(const Standard_Boolean)) &BOPAlgo_BuilderArea::SetAvoidInternalShapes, "Defines the preventing of addition of internal parts into result. The default value is FALSE, i.e. the internal parts are added into result.", py::arg("theAvoidInternal"));
cls_BOPAlgo_BuilderArea.def("IsAvoidInternalShapes", (Standard_Boolean (BOPAlgo_BuilderArea::*)() const) &BOPAlgo_BuilderArea::IsAvoidInternalShapes, "Returns the AvoidInternalShapes flag");

// CLASS: BOPALGO_BUILDERFACE
py::class_<BOPAlgo_BuilderFace, BOPAlgo_BuilderArea> cls_BOPAlgo_BuilderFace(mod, "BOPAlgo_BuilderFace", "The algorithm to build new faces from the given faces and set of edges lying on this face.");

// Constructors
cls_BOPAlgo_BuilderFace.def(py::init<>());
cls_BOPAlgo_BuilderFace.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_BuilderFace.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BuilderFace::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderFace.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BuilderFace::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderFace.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BuilderFace::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderFace.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BuilderFace::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderFace.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BuilderFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BuilderFace.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BuilderFace::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BuilderFace.def("SetFace", (void (BOPAlgo_BuilderFace::*)(const TopoDS_Face &)) &BOPAlgo_BuilderFace::SetFace, "Sets the face generatix", py::arg("theFace"));
cls_BOPAlgo_BuilderFace.def("Face", (const TopoDS_Face & (BOPAlgo_BuilderFace::*)() const) &BOPAlgo_BuilderFace::Face, "Returns the face generatix");
cls_BOPAlgo_BuilderFace.def("Perform", (void (BOPAlgo_BuilderFace::*)()) &BOPAlgo_BuilderFace::Perform, "Performs the algorithm");
cls_BOPAlgo_BuilderFace.def("Orientation", (TopAbs_Orientation (BOPAlgo_BuilderFace::*)() const) &BOPAlgo_BuilderFace::Orientation, "None");

// CLASS: BOPALGO_BUILDERSOLID
py::class_<BOPAlgo_BuilderSolid, BOPAlgo_BuilderArea> cls_BOPAlgo_BuilderSolid(mod, "BOPAlgo_BuilderSolid", "Solid Builder is the algorithm for building solids from set of faces. The given faces should be non-intersecting, i.e. all coinciding parts of the faces should be shared among them.");

// Constructors
cls_BOPAlgo_BuilderSolid.def(py::init<>());
cls_BOPAlgo_BuilderSolid.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_BuilderSolid.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_BuilderSolid::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderSolid.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_BuilderSolid::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderSolid.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_BuilderSolid::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_BuilderSolid.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_BuilderSolid::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_BuilderSolid.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_BuilderSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_BuilderSolid.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_BuilderSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_BuilderSolid.def("Perform", (void (BOPAlgo_BuilderSolid::*)()) &BOPAlgo_BuilderSolid::Perform, "Performs the construction of the solids from the given faces");
cls_BOPAlgo_BuilderSolid.def("GetBoxesMap", (const TopTools_DataMapOfShapeBox & (BOPAlgo_BuilderSolid::*)() const) &BOPAlgo_BuilderSolid::GetBoxesMap, "For classification purposes the algorithm builds the bounding boxes for all created solids. This method returns the data map of solid - box pairs.");

// CLASS: BOPALGO_CELLSBUILDER
py::class_<BOPAlgo_CellsBuilder, BOPAlgo_Builder> cls_BOPAlgo_CellsBuilder(mod, "BOPAlgo_CellsBuilder", "The algorithm is based on the General Fuse algorithm (GFA). The result of GFA is all split parts of the Arguments.");

// Constructors
cls_BOPAlgo_CellsBuilder.def(py::init<>());
cls_BOPAlgo_CellsBuilder.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_CellsBuilder.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_CellsBuilder::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_CellsBuilder.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_CellsBuilder::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_CellsBuilder.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_CellsBuilder::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_CellsBuilder.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_CellsBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_CellsBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_CellsBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_CellsBuilder.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_CellsBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_CellsBuilder.def("Clear", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::Clear, "Redefined method Clear - clears the contents.");
cls_BOPAlgo_CellsBuilder.def("AddToResult", [](BOPAlgo_CellsBuilder &self, const TopTools_ListOfShape & a0, const TopTools_ListOfShape & a1) -> void { return self.AddToResult(a0, a1); });
cls_BOPAlgo_CellsBuilder.def("AddToResult", [](BOPAlgo_CellsBuilder &self, const TopTools_ListOfShape & a0, const TopTools_ListOfShape & a1, const Standard_Integer a2) -> void { return self.AddToResult(a0, a1, a2); });
cls_BOPAlgo_CellsBuilder.def("AddToResult", (void (BOPAlgo_CellsBuilder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const Standard_Integer, const Standard_Boolean)) &BOPAlgo_CellsBuilder::AddToResult, "Adding the parts to result. The parts are defined by two lists of shapes: <theLSToTake> defines the arguments which parts should be taken into result; <theLSToAvoid> defines the arguments which parts should not be taken into result; To be taken into result the part must be IN for all shapes from the list <theLSToTake> and must be OUT of all shapes from the list <theLSToAvoid>.", py::arg("theLSToTake"), py::arg("theLSToAvoid"), py::arg("theMaterial"), py::arg("theUpdate"));
cls_BOPAlgo_CellsBuilder.def("AddAllToResult", [](BOPAlgo_CellsBuilder &self) -> void { return self.AddAllToResult(); });
cls_BOPAlgo_CellsBuilder.def("AddAllToResult", [](BOPAlgo_CellsBuilder &self, const Standard_Integer a0) -> void { return self.AddAllToResult(a0); });
cls_BOPAlgo_CellsBuilder.def("AddAllToResult", (void (BOPAlgo_CellsBuilder::*)(const Standard_Integer, const Standard_Boolean)) &BOPAlgo_CellsBuilder::AddAllToResult, "Add all split parts to result. <theMaterial> defines the removal of internal boundaries; <theUpdate> parameter defines whether to remove boundaries now or not.", py::arg("theMaterial"), py::arg("theUpdate"));
cls_BOPAlgo_CellsBuilder.def("RemoveFromResult", (void (BOPAlgo_CellsBuilder::*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &)) &BOPAlgo_CellsBuilder::RemoveFromResult, "Removing the parts from result. The parts are defined by two lists of shapes: <theLSToTake> defines the arguments which parts should be removed from result; <theLSToAvoid> defines the arguments which parts should not be removed from result. To be removed from the result the part must be IN for all shapes from the list <theLSToTake> and must be OUT of all shapes from the list <theLSToAvoid>.", py::arg("theLSToTake"), py::arg("theLSToAvoid"));
cls_BOPAlgo_CellsBuilder.def("RemoveAllFromResult", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::RemoveAllFromResult, "Remove all parts from result.");
cls_BOPAlgo_CellsBuilder.def("RemoveInternalBoundaries", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::RemoveInternalBoundaries, "Removes internal boundaries between cells with the same material. If the result contains the cells with same material but of different dimension the removal of internal boundaries between these cells will not be performed. In case of some errors during the removal the method will set the appropriate warning status - use GetReport() to access them.");
cls_BOPAlgo_CellsBuilder.def("GetAllParts", (const TopoDS_Shape & (BOPAlgo_CellsBuilder::*)() const) &BOPAlgo_CellsBuilder::GetAllParts, "Get all split parts.");
cls_BOPAlgo_CellsBuilder.def("MakeContainers", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::MakeContainers, "Makes the Containers of proper type from the parts added to result.");

// CLASS: BOPALGO_SECTIONATTRIBUTE
py::class_<BOPAlgo_SectionAttribute> cls_BOPAlgo_SectionAttribute(mod, "BOPAlgo_SectionAttribute", "Class is a container of the flags used by intersection algorithm");

// Constructors
cls_BOPAlgo_SectionAttribute.def(py::init<>());
cls_BOPAlgo_SectionAttribute.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("theAproximation"), py::arg("thePCurveOnS1"), py::arg("thePCurveOnS2"));

// Methods
cls_BOPAlgo_SectionAttribute.def("Approximation", (void (BOPAlgo_SectionAttribute::*)(const Standard_Boolean)) &BOPAlgo_SectionAttribute::Approximation, "Sets the Approximation flag", py::arg("theApprox"));
cls_BOPAlgo_SectionAttribute.def("PCurveOnS1", (void (BOPAlgo_SectionAttribute::*)(const Standard_Boolean)) &BOPAlgo_SectionAttribute::PCurveOnS1, "Sets the PCurveOnS1 flag", py::arg("thePCurveOnS1"));
cls_BOPAlgo_SectionAttribute.def("PCurveOnS2", (void (BOPAlgo_SectionAttribute::*)(const Standard_Boolean)) &BOPAlgo_SectionAttribute::PCurveOnS2, "Sets the PCurveOnS2 flag", py::arg("thePCurveOnS2"));
cls_BOPAlgo_SectionAttribute.def("Approximation", (Standard_Boolean (BOPAlgo_SectionAttribute::*)() const) &BOPAlgo_SectionAttribute::Approximation, "Returns the Approximation flag");
cls_BOPAlgo_SectionAttribute.def("PCurveOnS1", (Standard_Boolean (BOPAlgo_SectionAttribute::*)() const) &BOPAlgo_SectionAttribute::PCurveOnS1, "Returns the PCurveOnS1 flag");
cls_BOPAlgo_SectionAttribute.def("PCurveOnS2", (Standard_Boolean (BOPAlgo_SectionAttribute::*)() const) &BOPAlgo_SectionAttribute::PCurveOnS2, "Returns the PCurveOnS2 flag");

// CLASS: BOPALGO_PAVEFILLER
py::class_<BOPAlgo_PaveFiller, BOPAlgo_Algo> cls_BOPAlgo_PaveFiller(mod, "BOPAlgo_PaveFiller", "The class represents the Intersection phase of the Boolean Operations algorithm. It performs the pairwise intersection of the sub-shapes of the arguments in the following order: 1. Vertex/Vertex; 2. Vertex/Edge; 3. Edge/Edge; 4. Vertex/Face; 5. Edge/Face; 6. Face/Face.");

// Constructors
cls_BOPAlgo_PaveFiller.def(py::init<>());
cls_BOPAlgo_PaveFiller.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_PaveFiller.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_PaveFiller::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_PaveFiller.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_PaveFiller::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_PaveFiller.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_PaveFiller::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_PaveFiller.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_PaveFiller::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_PaveFiller.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_PaveFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_PaveFiller.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_PaveFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_PaveFiller.def("DS", (const BOPDS_DS & (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::DS, "None");
cls_BOPAlgo_PaveFiller.def("PDS", (BOPDS_PDS (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::PDS, "None");
// cls_BOPAlgo_PaveFiller.def("Iterator", (const BOPDS_PIterator & (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::Iterator, "None");
cls_BOPAlgo_PaveFiller.def("SetArguments", (void (BOPAlgo_PaveFiller::*)(const TopTools_ListOfShape &)) &BOPAlgo_PaveFiller::SetArguments, "None", py::arg("theLS"));
cls_BOPAlgo_PaveFiller.def("Arguments", (const TopTools_ListOfShape & (BOPAlgo_PaveFiller::*)() const) &BOPAlgo_PaveFiller::Arguments, "None");
cls_BOPAlgo_PaveFiller.def("Context", (const opencascade::handle<IntTools_Context> & (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::Context, "None");
cls_BOPAlgo_PaveFiller.def("SetSectionAttribute", (void (BOPAlgo_PaveFiller::*)(const BOPAlgo_SectionAttribute &)) &BOPAlgo_PaveFiller::SetSectionAttribute, "None", py::arg("theSecAttr"));
cls_BOPAlgo_PaveFiller.def("SetNonDestructive", (void (BOPAlgo_PaveFiller::*)(const Standard_Boolean)) &BOPAlgo_PaveFiller::SetNonDestructive, "Sets the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.", py::arg("theFlag"));
cls_BOPAlgo_PaveFiller.def("NonDestructive", (Standard_Boolean (BOPAlgo_PaveFiller::*)() const) &BOPAlgo_PaveFiller::NonDestructive, "Returns the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.");
cls_BOPAlgo_PaveFiller.def("Perform", (void (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::Perform, "None");
cls_BOPAlgo_PaveFiller.def("SetGlue", (void (BOPAlgo_PaveFiller::*)(const BOPAlgo_GlueEnum)) &BOPAlgo_PaveFiller::SetGlue, "Sets the glue option for the algorithm", py::arg("theGlue"));
cls_BOPAlgo_PaveFiller.def("Glue", (BOPAlgo_GlueEnum (BOPAlgo_PaveFiller::*)() const) &BOPAlgo_PaveFiller::Glue, "Returns the glue option of the algorithm");
cls_BOPAlgo_PaveFiller.def("SetAvoidBuildPCurve", (void (BOPAlgo_PaveFiller::*)(const Standard_Boolean)) &BOPAlgo_PaveFiller::SetAvoidBuildPCurve, "Sets the flag to avoid building of p-curves of edges on faces", py::arg("theValue"));
cls_BOPAlgo_PaveFiller.def("IsAvoidBuildPCurve", (Standard_Boolean (BOPAlgo_PaveFiller::*)() const) &BOPAlgo_PaveFiller::IsAvoidBuildPCurve, "Returns the flag to avoid building of p-curves of edges on faces");

// CLASS: BOPALGO_CHECKERSI
py::class_<BOPAlgo_CheckerSI, BOPAlgo_PaveFiller> cls_BOPAlgo_CheckerSI(mod, "BOPAlgo_CheckerSI", "Checks the shape on self-interference.");

// Constructors
cls_BOPAlgo_CheckerSI.def(py::init<>());

// Methods
// cls_BOPAlgo_CheckerSI.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_CheckerSI::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_CheckerSI.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_CheckerSI::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_CheckerSI.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_CheckerSI::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_CheckerSI.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_CheckerSI::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_CheckerSI.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_CheckerSI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_CheckerSI.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_CheckerSI::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_CheckerSI.def("Perform", (void (BOPAlgo_CheckerSI::*)()) &BOPAlgo_CheckerSI::Perform, "None");
cls_BOPAlgo_CheckerSI.def("SetLevelOfCheck", (void (BOPAlgo_CheckerSI::*)(const Standard_Integer)) &BOPAlgo_CheckerSI::SetLevelOfCheck, "Sets the level of checking shape on self-interference. It defines which interferences will be checked: 0 - only V/V; 1 - V/V and V/E; 2 - V/V, V/E and E/E; 3 - V/V, V/E, E/E and V/F; 4 - V/V, V/E, E/E, V/F and E/F; 5 - V/V, V/E, E/E, V/F, E/F and F/F; 6 - V/V, V/E, E/E, V/F, E/F, F/F and V/S; 7 - V/V, V/E, E/E, V/F, E/F, F/F, V/S and E/S; 8 - V/V, V/E, E/E, V/F, E/F, F/F, V/S, E/S and F/S; 9 - V/V, V/E, E/E, V/F, E/F, F/F, V/S, E/S, F/S and S/S - all interferences (Default value)", py::arg("theLevel"));

// CLASS: BOPALGO_MAKERVOLUME
py::class_<BOPAlgo_MakerVolume, BOPAlgo_Builder> cls_BOPAlgo_MakerVolume(mod, "BOPAlgo_MakerVolume", "The algorithm is to build solids from set of shapes. It uses the BOPAlgo_Builder algorithm to intersect the given shapes and build the images of faces (if needed) and BOPAlgo_BuilderSolid algorithm to build the solids.");

// Constructors
cls_BOPAlgo_MakerVolume.def(py::init<>());
cls_BOPAlgo_MakerVolume.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_MakerVolume.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_MakerVolume::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_MakerVolume.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_MakerVolume::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_MakerVolume.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_MakerVolume::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_MakerVolume.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_MakerVolume::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_MakerVolume.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_MakerVolume::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_MakerVolume.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_MakerVolume::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_MakerVolume.def("Clear", (void (BOPAlgo_MakerVolume::*)()) &BOPAlgo_MakerVolume::Clear, "Clears the data.");
cls_BOPAlgo_MakerVolume.def("SetIntersect", (void (BOPAlgo_MakerVolume::*)(const Standard_Boolean)) &BOPAlgo_MakerVolume::SetIntersect, "Sets the flag myIntersect: if <bIntersect> is TRUE the shapes from <myArguments> will be intersected. if <bIntersect> is FALSE no intersection will be done.", py::arg("bIntersect"));
cls_BOPAlgo_MakerVolume.def("IsIntersect", (Standard_Boolean (BOPAlgo_MakerVolume::*)() const) &BOPAlgo_MakerVolume::IsIntersect, "Returns the flag <myIntersect>.");
cls_BOPAlgo_MakerVolume.def("Box", (const TopoDS_Solid & (BOPAlgo_MakerVolume::*)() const) &BOPAlgo_MakerVolume::Box, "Returns the solid box <mySBox>.");
cls_BOPAlgo_MakerVolume.def("Faces", (const TopTools_ListOfShape & (BOPAlgo_MakerVolume::*)() const) &BOPAlgo_MakerVolume::Faces, "Returns the processed faces <myFaces>.");
cls_BOPAlgo_MakerVolume.def("SetAvoidInternalShapes", (void (BOPAlgo_MakerVolume::*)(const Standard_Boolean)) &BOPAlgo_MakerVolume::SetAvoidInternalShapes, "Defines the preventing of addition of internal for solid parts into the result. By default the internal parts are added into result.", py::arg("theAvoidInternal"));
cls_BOPAlgo_MakerVolume.def("IsAvoidInternalShapes", (Standard_Boolean (BOPAlgo_MakerVolume::*)() const) &BOPAlgo_MakerVolume::IsAvoidInternalShapes, "Returns the AvoidInternalShapes flag");
cls_BOPAlgo_MakerVolume.def("Perform", (void (BOPAlgo_MakerVolume::*)()) &BOPAlgo_MakerVolume::Perform, "Performs the operation.");

// TYPEDEF: BOPALGO_PARGUMENTANALYZER

// TYPEDEF: BOPALGO_PBOP

// TYPEDEF: BOPALGO_PBUILDER

// TYPEDEF: BOPALGO_PSECTION

// TYPEDEF: BOPALGO_PWIREEDGESET

// CLASS: BOPALGO_REMOVEFEATURES
py::class_<BOPAlgo_RemoveFeatures, BOPAlgo_Options> cls_BOPAlgo_RemoveFeatures(mod, "BOPAlgo_RemoveFeatures", "The RemoveFeatures algorithm is intended for reconstruction of the shape by removal of the unwanted parts from it. These parts can be holes, protrusions, spikes, fillets etc. The shape itself is not modified, the new shape is built in the result.");

// Constructors
cls_BOPAlgo_RemoveFeatures.def(py::init<>());

// Methods
// cls_BOPAlgo_RemoveFeatures.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_RemoveFeatures::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_RemoveFeatures::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_RemoveFeatures::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_RemoveFeatures::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_RemoveFeatures::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_RemoveFeatures::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_RemoveFeatures.def("SetShape", (void (BOPAlgo_RemoveFeatures::*)(const TopoDS_Shape &)) &BOPAlgo_RemoveFeatures::SetShape, "Sets the shape for processing.", py::arg("theShape"));
cls_BOPAlgo_RemoveFeatures.def("InputShape", (const TopoDS_Shape & (BOPAlgo_RemoveFeatures::*)() const) &BOPAlgo_RemoveFeatures::InputShape, "Returns the input shape");
cls_BOPAlgo_RemoveFeatures.def("AddFaceToRemove", (void (BOPAlgo_RemoveFeatures::*)(const TopoDS_Shape &)) &BOPAlgo_RemoveFeatures::AddFaceToRemove, "Adds the face to remove from the input shape.", py::arg("theFace"));
cls_BOPAlgo_RemoveFeatures.def("AddFacesToRemove", (void (BOPAlgo_RemoveFeatures::*)(const TopTools_ListOfShape &)) &BOPAlgo_RemoveFeatures::AddFacesToRemove, "Adds the faces to remove from the input shape.", py::arg("theFaces"));
cls_BOPAlgo_RemoveFeatures.def("FacesToRemove", (const TopTools_ListOfShape & (BOPAlgo_RemoveFeatures::*)() const) &BOPAlgo_RemoveFeatures::FacesToRemove, "Returns the list of faces which have been requested for removal from the input shape.");
cls_BOPAlgo_RemoveFeatures.def("Perform", (void (BOPAlgo_RemoveFeatures::*)()) &BOPAlgo_RemoveFeatures::Perform, "Performs the operation");
cls_BOPAlgo_RemoveFeatures.def("Clear", (void (BOPAlgo_RemoveFeatures::*)()) &BOPAlgo_RemoveFeatures::Clear, "Clears the contents of the algorithm from previous run, allowing reusing it for following removals.");
cls_BOPAlgo_RemoveFeatures.def("TrackHistory", (void (BOPAlgo_RemoveFeatures::*)(const Standard_Boolean)) &BOPAlgo_RemoveFeatures::TrackHistory, "Defines whether to track the modification of the shapes or not", py::arg("theFlag"));
cls_BOPAlgo_RemoveFeatures.def("History", (opencascade::handle<BRepTools_History> (BOPAlgo_RemoveFeatures::*)()) &BOPAlgo_RemoveFeatures::History, "Gets the History object");
cls_BOPAlgo_RemoveFeatures.def("Shape", (const TopoDS_Shape & (BOPAlgo_RemoveFeatures::*)() const) &BOPAlgo_RemoveFeatures::Shape, "Returns the resulting shape");

// CLASS: BOPALGO_SECTION
py::class_<BOPAlgo_Section, BOPAlgo_Builder> cls_BOPAlgo_Section(mod, "BOPAlgo_Section", "The algorithm to build a Section between the arguments. The Section consists of vertices and edges. The Section contains: 1. new vertices that are subjects of V/V, E/E, E/F, F/F interferences 2. vertices that are subjects of V/E, V/F interferences 3. new edges that are subjects of F/F interferences 4. edges that are Common Blocks");

// Constructors
cls_BOPAlgo_Section.def(py::init<>());
cls_BOPAlgo_Section.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_Section.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_Section::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_Section.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_Section::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_Section.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_Section::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_Section.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_Section::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_Section.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_Section::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_Section.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_Section::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: BOPALGO_SHELLSPLITTER
py::class_<BOPAlgo_ShellSplitter, BOPAlgo_Algo> cls_BOPAlgo_ShellSplitter(mod, "BOPAlgo_ShellSplitter", "The class provides the splitting of the set of connected faces on separate loops");

// Constructors
cls_BOPAlgo_ShellSplitter.def(py::init<>());
cls_BOPAlgo_ShellSplitter.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_ShellSplitter.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_ShellSplitter::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_ShellSplitter.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_ShellSplitter::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_ShellSplitter.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_ShellSplitter::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_ShellSplitter.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_ShellSplitter::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_ShellSplitter.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_ShellSplitter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_ShellSplitter.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_ShellSplitter::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_ShellSplitter.def("AddStartElement", (void (BOPAlgo_ShellSplitter::*)(const TopoDS_Shape &)) &BOPAlgo_ShellSplitter::AddStartElement, "adds a face <theS> to process", py::arg("theS"));
cls_BOPAlgo_ShellSplitter.def("StartElements", (const TopTools_ListOfShape & (BOPAlgo_ShellSplitter::*)() const) &BOPAlgo_ShellSplitter::StartElements, "return the faces to process");
cls_BOPAlgo_ShellSplitter.def("Perform", (void (BOPAlgo_ShellSplitter::*)()) &BOPAlgo_ShellSplitter::Perform, "performs the algorithm");
cls_BOPAlgo_ShellSplitter.def("Shells", (const TopTools_ListOfShape & (BOPAlgo_ShellSplitter::*)() const) &BOPAlgo_ShellSplitter::Shells, "returns the loops");
cls_BOPAlgo_ShellSplitter.def_static("SplitBlock_", (void (*)(BOPTools_ConnexityBlock &)) &BOPAlgo_ShellSplitter::SplitBlock, "None", py::arg("theCB"));

// CLASS: BOPALGO_SPLITTER
py::class_<BOPAlgo_Splitter, BOPAlgo_ToolsProvider> cls_BOPAlgo_Splitter(mod, "BOPAlgo_Splitter", "The **Splitter algorithm** is the algorithm for splitting a group of arbitrary shapes by the other group of arbitrary shapes. The arguments of the operation are divided on two groups: *Objects* - shapes that will be split; *Tools* - shapes by which the *Objects* will be split. The result of the operation contains only the split parts of the shapes from the group of *Objects*. The split parts of the shapes from the group of *Tools* are excluded from the result. The shapes can be split by the other shapes from the same group (in case these shapes are interfering).");

// Constructors
cls_BOPAlgo_Splitter.def(py::init<>());
cls_BOPAlgo_Splitter.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_Splitter.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_Splitter::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_Splitter.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_Splitter::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_Splitter.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_Splitter::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_Splitter.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_Splitter::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_Splitter.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_Splitter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_Splitter.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_Splitter::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_Splitter.def("Perform", (void (BOPAlgo_Splitter::*)()) &BOPAlgo_Splitter::Perform, "Performs the operation");

// CLASS: BOPALGO_TOOLS
py::class_<BOPAlgo_Tools> cls_BOPAlgo_Tools(mod, "BOPAlgo_Tools", "Provides tools used in the intersection part of Boolean operations");

// Methods
cls_BOPAlgo_Tools.def_static("FillMap_", (void (*)(const opencascade::handle<BOPDS_PaveBlock> &, const Standard_Integer, BOPDS_IndexedDataMapOfPaveBlockListOfInteger &, const opencascade::handle<NCollection_BaseAllocator> &)) &BOPAlgo_Tools::FillMap, "None", py::arg("thePB1"), py::arg("theF"), py::arg("theMILI"), py::arg("theAllocator"));
// cls_BOPAlgo_Tools.def_static("PerformCommonBlocks_", (void (*)(BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock &, const opencascade::handle<NCollection_BaseAllocator> &, BOPDS_PDS &)) &BOPAlgo_Tools::PerformCommonBlocks, "None", py::arg("theMBlocks"), py::arg("theAllocator"), py::arg("theDS"));
// cls_BOPAlgo_Tools.def_static("PerformCommonBlocks_", (void (*)(const BOPDS_IndexedDataMapOfPaveBlockListOfInteger &, const opencascade::handle<NCollection_BaseAllocator> &, BOPDS_PDS &)) &BOPAlgo_Tools::PerformCommonBlocks, "None", py::arg("theMBlocks"), py::arg("theAllocator"), py::arg("pDS"));
cls_BOPAlgo_Tools.def_static("ComputeToleranceOfCB_", (Standard_Real (*)(const opencascade::handle<BOPDS_CommonBlock> &, const BOPDS_PDS, const opencascade::handle<IntTools_Context> &)) &BOPAlgo_Tools::ComputeToleranceOfCB, "None", py::arg("theCB"), py::arg("theDS"), py::arg("theContext"));
cls_BOPAlgo_Tools.def_static("EdgesToWires_", [](const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Integer { return BOPAlgo_Tools::EdgesToWires(a0, a1); });
cls_BOPAlgo_Tools.def_static("EdgesToWires_", [](const TopoDS_Shape & a0, TopoDS_Shape & a1, const Standard_Boolean a2) -> Standard_Integer { return BOPAlgo_Tools::EdgesToWires(a0, a1, a2); });
cls_BOPAlgo_Tools.def_static("EdgesToWires_", (Standard_Integer (*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Boolean, const Standard_Real)) &BOPAlgo_Tools::EdgesToWires, "Creates planar wires from the given edges. The input edges are expected to be planar. And for the performance sake the method does not check if the edges are really planar. Thus, the result wires will also be not planar if the input edges are not planar. The edges may be not shared, but the resulting wires will be sharing the coinciding parts and intersecting parts. The output wires may be non-manifold and contain free and multi-connected vertices. Parameters: <theEdges> - input edges; <theWires> - output wires; <theShared> - boolean flag which defines whether the input edges are already shared or have to be intersected; <theAngTol> - the angular tolerance which will be used for distinguishing the planes in which the edges are located. Default value is 1.e-8 which is used for intersection of planes in IntTools_FaceFace. Method returns the following error statuses: 0 - in case of success (at least one wire has been built); 1 - in case there are no edges in the given shape; 2 - sharing of the edges has failed.", py::arg("theEdges"), py::arg("theWires"), py::arg("theShared"), py::arg("theAngTol"));
cls_BOPAlgo_Tools.def_static("WiresToFaces_", [](const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Boolean { return BOPAlgo_Tools::WiresToFaces(a0, a1); });
cls_BOPAlgo_Tools.def_static("WiresToFaces_", (Standard_Boolean (*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Real)) &BOPAlgo_Tools::WiresToFaces, "Creates planar faces from given planar wires. The method does not check if the wires are really planar. The input wires may be non-manifold but should be shared. The wires located in the same planes and included into other wires will create holes in the faces built from outer wires. The tolerance values of the input shapes may be modified during the operation due to projection of the edges on the planes for creation of 2D curves. Parameters: <theWires> - the given wires; <theFaces> - the output faces; <theAngTol> - the angular tolerance for distinguishing the planes in which the wires are located. Default value is 1.e-8 which is used for intersection of planes in IntTools_FaceFace. Method returns TRUE in case of success, i.e. at least one face has been built.", py::arg("theWires"), py::arg("theFaces"), py::arg("theAngTol"));
cls_BOPAlgo_Tools.def_static("IntersectVertices_", (void (*)(const TopTools_IndexedDataMapOfShapeReal &, const Standard_Boolean, const Standard_Real, TopTools_ListOfListOfShape &)) &BOPAlgo_Tools::IntersectVertices, "Finds chains of intersecting vertices", py::arg("theVertices"), py::arg("theRunParallel"), py::arg("theFuzzyValue"), py::arg("theChains"));
cls_BOPAlgo_Tools.def_static("TreatCompound_", (void (*)(const TopoDS_Shape &, TopTools_MapOfShape &, TopTools_ListOfShape &)) &BOPAlgo_Tools::TreatCompound, "Collect in the output list recursively all non-compound subshapes of the first level of the given shape theS. If a shape presents in the map theMFence it is skipped. All shapes put in the output are also added into theMFence.", py::arg("theS"), py::arg("theMFence"), py::arg("theLS"));
cls_BOPAlgo_Tools.def_static("ClassifyFaces_", [](const TopTools_ListOfShape & a0, const TopTools_ListOfShape & a1, const Standard_Boolean a2, opencascade::handle<IntTools_Context> & a3, TopTools_IndexedDataMapOfShapeListOfShape & a4) -> void { return BOPAlgo_Tools::ClassifyFaces(a0, a1, a2, a3, a4); });
cls_BOPAlgo_Tools.def_static("ClassifyFaces_", [](const TopTools_ListOfShape & a0, const TopTools_ListOfShape & a1, const Standard_Boolean a2, opencascade::handle<IntTools_Context> & a3, TopTools_IndexedDataMapOfShapeListOfShape & a4, const TopTools_DataMapOfShapeBox & a5) -> void { return BOPAlgo_Tools::ClassifyFaces(a0, a1, a2, a3, a4, a5); });
cls_BOPAlgo_Tools.def_static("ClassifyFaces_", (void (*)(const TopTools_ListOfShape &, const TopTools_ListOfShape &, const Standard_Boolean, opencascade::handle<IntTools_Context> &, TopTools_IndexedDataMapOfShapeListOfShape &, const TopTools_DataMapOfShapeBox &, const TopTools_DataMapOfShapeListOfShape &)) &BOPAlgo_Tools::ClassifyFaces, "Classifies the faces <theFaces> relatively solids <theSolids>. The IN faces for solids are stored into output data map <theInParts>.", py::arg("theFaces"), py::arg("theSolids"), py::arg("theRunParallel"), py::arg("theContext"), py::arg("theInParts"), py::arg("theShapeBoxMap"), py::arg("theSolidsIF"));

// CLASS: BOPALGO_WIREEDGESET
py::class_<BOPAlgo_WireEdgeSet> cls_BOPAlgo_WireEdgeSet(mod, "BOPAlgo_WireEdgeSet", "None");

// Constructors
cls_BOPAlgo_WireEdgeSet.def(py::init<>());
cls_BOPAlgo_WireEdgeSet.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_WireEdgeSet.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_WireEdgeSet::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_WireEdgeSet::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_WireEdgeSet::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_WireEdgeSet::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_WireEdgeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_WireEdgeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_WireEdgeSet.def("Clear", (void (BOPAlgo_WireEdgeSet::*)()) &BOPAlgo_WireEdgeSet::Clear, "None");
cls_BOPAlgo_WireEdgeSet.def("SetFace", (void (BOPAlgo_WireEdgeSet::*)(const TopoDS_Face &)) &BOPAlgo_WireEdgeSet::SetFace, "None", py::arg("aF"));
cls_BOPAlgo_WireEdgeSet.def("Face", (const TopoDS_Face & (BOPAlgo_WireEdgeSet::*)() const) &BOPAlgo_WireEdgeSet::Face, "None");
cls_BOPAlgo_WireEdgeSet.def("AddStartElement", (void (BOPAlgo_WireEdgeSet::*)(const TopoDS_Shape &)) &BOPAlgo_WireEdgeSet::AddStartElement, "None", py::arg("sS"));
cls_BOPAlgo_WireEdgeSet.def("StartElements", (const TopTools_ListOfShape & (BOPAlgo_WireEdgeSet::*)() const) &BOPAlgo_WireEdgeSet::StartElements, "None");
cls_BOPAlgo_WireEdgeSet.def("AddShape", (void (BOPAlgo_WireEdgeSet::*)(const TopoDS_Shape &)) &BOPAlgo_WireEdgeSet::AddShape, "None", py::arg("sS"));
cls_BOPAlgo_WireEdgeSet.def("Shapes", (const TopTools_ListOfShape & (BOPAlgo_WireEdgeSet::*)() const) &BOPAlgo_WireEdgeSet::Shapes, "None");

// CLASS: BOPALGO_WIRESPLITTER
py::class_<BOPAlgo_WireSplitter, BOPAlgo_Algo> cls_BOPAlgo_WireSplitter(mod, "BOPAlgo_WireSplitter", "The class is to build loops from the given set of edges.");

// Constructors
cls_BOPAlgo_WireSplitter.def(py::init<>());
cls_BOPAlgo_WireSplitter.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BOPAlgo_WireSplitter.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_WireSplitter::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_WireSplitter.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_WireSplitter::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_WireSplitter.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_WireSplitter::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_WireSplitter.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_WireSplitter::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_WireSplitter.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_WireSplitter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_WireSplitter.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_WireSplitter::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_WireSplitter.def("SetWES", (void (BOPAlgo_WireSplitter::*)(const BOPAlgo_WireEdgeSet &)) &BOPAlgo_WireSplitter::SetWES, "None", py::arg("theWES"));
cls_BOPAlgo_WireSplitter.def("WES", (BOPAlgo_WireEdgeSet & (BOPAlgo_WireSplitter::*)()) &BOPAlgo_WireSplitter::WES, "None");
cls_BOPAlgo_WireSplitter.def("SetContext", (void (BOPAlgo_WireSplitter::*)(const opencascade::handle<IntTools_Context> &)) &BOPAlgo_WireSplitter::SetContext, "Sets the context for the algorithm", py::arg("theContext"));
cls_BOPAlgo_WireSplitter.def("Context", (const opencascade::handle<IntTools_Context> & (BOPAlgo_WireSplitter::*)()) &BOPAlgo_WireSplitter::Context, "Returns the context");
cls_BOPAlgo_WireSplitter.def("Perform", (void (BOPAlgo_WireSplitter::*)()) &BOPAlgo_WireSplitter::Perform, "None");
cls_BOPAlgo_WireSplitter.def_static("MakeWire_", (void (*)(TopTools_ListOfShape &, TopoDS_Wire &)) &BOPAlgo_WireSplitter::MakeWire, "None", py::arg("theLE"), py::arg("theW"));
cls_BOPAlgo_WireSplitter.def_static("SplitBlock_", (void (*)(const TopoDS_Face &, BOPTools_ConnexityBlock &, const opencascade::handle<IntTools_Context> &)) &BOPAlgo_WireSplitter::SplitBlock, "None", py::arg("theF"), py::arg("theCB"), py::arg("theContext"));

// CLASS: BOPALGO_EDGEINFO
py::class_<BOPAlgo_EdgeInfo> cls_BOPAlgo_EdgeInfo(mod, "BOPAlgo_EdgeInfo", "None");

// Constructors
cls_BOPAlgo_EdgeInfo.def(py::init<>());

// Methods
cls_BOPAlgo_EdgeInfo.def("SetEdge", (void (BOPAlgo_EdgeInfo::*)(const TopoDS_Edge &)) &BOPAlgo_EdgeInfo::SetEdge, "None", py::arg("theE"));
cls_BOPAlgo_EdgeInfo.def("Edge", (const TopoDS_Edge & (BOPAlgo_EdgeInfo::*)() const) &BOPAlgo_EdgeInfo::Edge, "None");
cls_BOPAlgo_EdgeInfo.def("SetPassed", (void (BOPAlgo_EdgeInfo::*)(const Standard_Boolean)) &BOPAlgo_EdgeInfo::SetPassed, "None", py::arg("theFlag"));
cls_BOPAlgo_EdgeInfo.def("Passed", (Standard_Boolean (BOPAlgo_EdgeInfo::*)() const) &BOPAlgo_EdgeInfo::Passed, "None");
cls_BOPAlgo_EdgeInfo.def("SetInFlag", (void (BOPAlgo_EdgeInfo::*)(const Standard_Boolean)) &BOPAlgo_EdgeInfo::SetInFlag, "None", py::arg("theFlag"));
cls_BOPAlgo_EdgeInfo.def("IsIn", (Standard_Boolean (BOPAlgo_EdgeInfo::*)() const) &BOPAlgo_EdgeInfo::IsIn, "None");
cls_BOPAlgo_EdgeInfo.def("SetAngle", (void (BOPAlgo_EdgeInfo::*)(const Standard_Real)) &BOPAlgo_EdgeInfo::SetAngle, "None", py::arg("theAngle"));
cls_BOPAlgo_EdgeInfo.def("Angle", (Standard_Real (BOPAlgo_EdgeInfo::*)() const) &BOPAlgo_EdgeInfo::Angle, "None");

// TYPEDEF: BOPALGO_LISTOFEDGEINFO
bind_NCollection_List<BOPAlgo_EdgeInfo>(mod, "BOPAlgo_ListOfEdgeInfo", py::module_local(false));

// TYPEDEF: BOPALGO_LISTITERATOROFLISTOFEDGEINFO
bind_NCollection_TListIterator<BOPAlgo_EdgeInfo>(mod, "BOPAlgo_ListIteratorOfListOfEdgeInfo", py::module_local(false));

// TYPEDEF: BOPALGO_INDEXEDDATAMAPOFSHAPELISTOFEDGEINFO
bind_NCollection_IndexedDataMap<TopoDS_Shape, NCollection_List<BOPAlgo_EdgeInfo>, TopTools_ShapeMapHasher>(mod, "BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo", py::module_local(false));


}
