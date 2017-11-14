#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BOPDS_Iterator.hxx>

#include <Message_Alert.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <BOPAlgo_Alerts.hxx>
#include <TopoDS_AlertWithShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BOPCol_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_Report.hxx>
#include <Standard_OStream.hxx>
#include <Message_ProgressIndicator.hxx>
#include <BOPAlgo_Options.hxx>
#include <BOPAlgo_Algo.hxx>
#include <BOPAlgo_Operation.hxx>
#include <BOPAlgo_CheckStatus.hxx>
#include <BOPCol_ListOfShape.hxx>
#include <BOPAlgo_CheckResult.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <BOPAlgo_ListOfCheckResult.hxx>
#include <BOPAlgo_ArgumentAnalyzer.hxx>
#include <BOPDS_DS.hxx>
#include <BOPDS_PDS.hxx>
#include <BOPDS_PIterator.hxx>
#include <IntTools_Context.hxx>
#include <BOPAlgo_SectionAttribute.hxx>
#include <BOPAlgo_GlueEnum.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <BOPAlgo_PPaveFiller.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BOPCol_IndexedDataMapOfShapeListOfShape.hxx>
#include <BOPAlgo_BuilderShape.hxx>
#include <BOPCol_DataMapOfShapeListOfShape.hxx>
#include <BOPCol_DataMapOfShapeShape.hxx>
#include <BOPAlgo_Builder.hxx>
#include <BOPAlgo_BOP.hxx>
#include <BOPAlgo_BuilderArea.hxx>
#include <TopoDS_Face.hxx>
#include <TopAbs_Orientation.hxx>
#include <BOPAlgo_BuilderFace.hxx>
#include <TopoDS_Solid.hxx>
#include <BOPAlgo_BuilderSolid.hxx>
#include <BOPAlgo_CellsBuilder.hxx>
#include <BOPAlgo_CheckerSI.hxx>
#include <BOPAlgo_MakerVolume.hxx>
#include <BOPAlgo_PArgumentAnalyzer.hxx>
#include <BOPAlgo_PBOP.hxx>
#include <BOPAlgo_PBuilder.hxx>
#include <BOPAlgo_Section.hxx>
#include <BOPAlgo_PSection.hxx>
#include <BOPAlgo_WireEdgeSet.hxx>
#include <BOPAlgo_PWireEdgeSet.hxx>
#include <BOPTools_ConnexityBlock.hxx>
#include <BOPAlgo_ShellSplitter.hxx>
#include <BOPAlgo_Splitter.hxx>
#include <BOPDS_PaveBlock.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfInteger.hxx>
#include <BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock.hxx>
#include <BOPDS_CommonBlock.hxx>
#include <BOPCol_IndexedDataMapOfShapeReal.hxx>
#include <BOPCol_ListOfListOfShape.hxx>
#include <BOPAlgo_Tools.hxx>
#include <TopoDS_Wire.hxx>
#include <BOPAlgo_WireSplitter.hxx>
#include <TopoDS_Edge.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_IndexedDataMap.hxx>

PYBIND11_MODULE(BOPAlgo, mod) {

	// IMPORT
	py::module::import("OCCT.Message");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.BOPCol");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.BOPDS");
	py::module::import("OCCT.IntTools");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.BOPTools");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Operation.hxx
	py::enum_<BOPAlgo_Operation>(mod, "BOPAlgo_Operation", "None")
		.value("BOPAlgo_COMMON", BOPAlgo_Operation::BOPAlgo_COMMON)
		.value("BOPAlgo_FUSE", BOPAlgo_Operation::BOPAlgo_FUSE)
		.value("BOPAlgo_CUT", BOPAlgo_Operation::BOPAlgo_CUT)
		.value("BOPAlgo_CUT21", BOPAlgo_Operation::BOPAlgo_CUT21)
		.value("BOPAlgo_SECTION", BOPAlgo_Operation::BOPAlgo_SECTION)
		.value("BOPAlgo_UNKNOWN", BOPAlgo_Operation::BOPAlgo_UNKNOWN)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_CheckStatus.hxx
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
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_GlueEnum.hxx
	py::enum_<BOPAlgo_GlueEnum>(mod, "BOPAlgo_GlueEnum", "The Enumeration describes an additional option for the algorithms in the Boolean Component such as General Fuse, Boolean operations, Section, Maker Volume, Splitter and Cells Builder algorithms.")
		.value("BOPAlgo_GlueOff", BOPAlgo_GlueEnum::BOPAlgo_GlueOff)
		.value("BOPAlgo_GlueShift", BOPAlgo_GlueEnum::BOPAlgo_GlueShift)
		.value("BOPAlgo_GlueFull", BOPAlgo_GlueEnum::BOPAlgo_GlueFull)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertBOPNotAllowed, opencascade::handle<BOPAlgo_AlertBOPNotAllowed>, Message_Alert> cls_BOPAlgo_AlertBOPNotAllowed(mod, "BOPAlgo_AlertBOPNotAllowed", "Boolean operation of given type is not allowed on the given inputs");
	cls_BOPAlgo_AlertBOPNotAllowed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertBOPNotAllowed::get_type_name, "None");
	cls_BOPAlgo_AlertBOPNotAllowed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertBOPNotAllowed::get_type_descriptor, "None");
	cls_BOPAlgo_AlertBOPNotAllowed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertBOPNotAllowed::*)() const ) &BOPAlgo_AlertBOPNotAllowed::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertBOPNotSet, opencascade::handle<BOPAlgo_AlertBOPNotSet>, Message_Alert> cls_BOPAlgo_AlertBOPNotSet(mod, "BOPAlgo_AlertBOPNotSet", "The type of Boolean Operation is not set");
	cls_BOPAlgo_AlertBOPNotSet.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertBOPNotSet::get_type_name, "None");
	cls_BOPAlgo_AlertBOPNotSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertBOPNotSet::get_type_descriptor, "None");
	cls_BOPAlgo_AlertBOPNotSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertBOPNotSet::*)() const ) &BOPAlgo_AlertBOPNotSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertBuilderFailed, opencascade::handle<BOPAlgo_AlertBuilderFailed>, Message_Alert> cls_BOPAlgo_AlertBuilderFailed(mod, "BOPAlgo_AlertBuilderFailed", "Building of the result shape has failed");
	cls_BOPAlgo_AlertBuilderFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertBuilderFailed::get_type_name, "None");
	cls_BOPAlgo_AlertBuilderFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertBuilderFailed::get_type_descriptor, "None");
	cls_BOPAlgo_AlertBuilderFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertBuilderFailed::*)() const ) &BOPAlgo_AlertBuilderFailed::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertIntersectionFailed, opencascade::handle<BOPAlgo_AlertIntersectionFailed>, Message_Alert> cls_BOPAlgo_AlertIntersectionFailed(mod, "BOPAlgo_AlertIntersectionFailed", "The intersection of the arguments has failed");
	cls_BOPAlgo_AlertIntersectionFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertIntersectionFailed::get_type_name, "None");
	cls_BOPAlgo_AlertIntersectionFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertIntersectionFailed::get_type_descriptor, "None");
	cls_BOPAlgo_AlertIntersectionFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertIntersectionFailed::*)() const ) &BOPAlgo_AlertIntersectionFailed::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertMultipleArguments, opencascade::handle<BOPAlgo_AlertMultipleArguments>, Message_Alert> cls_BOPAlgo_AlertMultipleArguments(mod, "BOPAlgo_AlertMultipleArguments", "The type of Boolean Operation is not set");
	cls_BOPAlgo_AlertMultipleArguments.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertMultipleArguments::get_type_name, "None");
	cls_BOPAlgo_AlertMultipleArguments.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertMultipleArguments::get_type_descriptor, "None");
	cls_BOPAlgo_AlertMultipleArguments.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertMultipleArguments::*)() const ) &BOPAlgo_AlertMultipleArguments::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertNoFiller, opencascade::handle<BOPAlgo_AlertNoFiller>, Message_Alert> cls_BOPAlgo_AlertNoFiller(mod, "BOPAlgo_AlertNoFiller", "The Pave Filler (the intersection tool) has not been created");
	cls_BOPAlgo_AlertNoFiller.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertNoFiller::get_type_name, "None");
	cls_BOPAlgo_AlertNoFiller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertNoFiller::get_type_descriptor, "None");
	cls_BOPAlgo_AlertNoFiller.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertNoFiller::*)() const ) &BOPAlgo_AlertNoFiller::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertNullInputShapes, opencascade::handle<BOPAlgo_AlertNullInputShapes>, Message_Alert> cls_BOPAlgo_AlertNullInputShapes(mod, "BOPAlgo_AlertNullInputShapes", "Null input shapes");
	cls_BOPAlgo_AlertNullInputShapes.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertNullInputShapes::get_type_name, "None");
	cls_BOPAlgo_AlertNullInputShapes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertNullInputShapes::get_type_descriptor, "None");
	cls_BOPAlgo_AlertNullInputShapes.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertNullInputShapes::*)() const ) &BOPAlgo_AlertNullInputShapes::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertPostTreatFF, opencascade::handle<BOPAlgo_AlertPostTreatFF>, Message_Alert> cls_BOPAlgo_AlertPostTreatFF(mod, "BOPAlgo_AlertPostTreatFF", "Cannot connect face intersection curves");
	cls_BOPAlgo_AlertPostTreatFF.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertPostTreatFF::get_type_name, "None");
	cls_BOPAlgo_AlertPostTreatFF.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertPostTreatFF::get_type_descriptor, "None");
	cls_BOPAlgo_AlertPostTreatFF.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertPostTreatFF::*)() const ) &BOPAlgo_AlertPostTreatFF::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertSolidBuilderFailed, opencascade::handle<BOPAlgo_AlertSolidBuilderFailed>, Message_Alert> cls_BOPAlgo_AlertSolidBuilderFailed(mod, "BOPAlgo_AlertSolidBuilderFailed", "The BuilderSolid algorithm has failed");
	cls_BOPAlgo_AlertSolidBuilderFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertSolidBuilderFailed::get_type_name, "None");
	cls_BOPAlgo_AlertSolidBuilderFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertSolidBuilderFailed::get_type_descriptor, "None");
	cls_BOPAlgo_AlertSolidBuilderFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertSolidBuilderFailed::*)() const ) &BOPAlgo_AlertSolidBuilderFailed::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertTooFewArguments, opencascade::handle<BOPAlgo_AlertTooFewArguments>, Message_Alert> cls_BOPAlgo_AlertTooFewArguments(mod, "BOPAlgo_AlertTooFewArguments", "There are no enough arguments to perform the operation");
	cls_BOPAlgo_AlertTooFewArguments.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertTooFewArguments::get_type_name, "None");
	cls_BOPAlgo_AlertTooFewArguments.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertTooFewArguments::get_type_descriptor, "None");
	cls_BOPAlgo_AlertTooFewArguments.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertTooFewArguments::*)() const ) &BOPAlgo_AlertTooFewArguments::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertBadPositioning, opencascade::handle<BOPAlgo_AlertBadPositioning>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertBadPositioning(mod, "BOPAlgo_AlertBadPositioning", "The positioning of the shapes leads to creation of the small edges without valid range");
	cls_BOPAlgo_AlertBadPositioning.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertBadPositioning.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertBadPositioning::get_type_name, "None");
	cls_BOPAlgo_AlertBadPositioning.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertBadPositioning::get_type_descriptor, "None");
	cls_BOPAlgo_AlertBadPositioning.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertBadPositioning::*)() const ) &BOPAlgo_AlertBadPositioning::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertEmptyShape, opencascade::handle<BOPAlgo_AlertEmptyShape>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertEmptyShape(mod, "BOPAlgo_AlertEmptyShape", "Some of the arguments are empty shapes");
	cls_BOPAlgo_AlertEmptyShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertEmptyShape.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertEmptyShape::get_type_name, "None");
	cls_BOPAlgo_AlertEmptyShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertEmptyShape::get_type_descriptor, "None");
	cls_BOPAlgo_AlertEmptyShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertEmptyShape::*)() const ) &BOPAlgo_AlertEmptyShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertNotSplittableEdge, opencascade::handle<BOPAlgo_AlertNotSplittableEdge>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertNotSplittableEdge(mod, "BOPAlgo_AlertNotSplittableEdge", "Some edges are very small and have such a small valid range, that they cannot be split");
	cls_BOPAlgo_AlertNotSplittableEdge.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertNotSplittableEdge.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertNotSplittableEdge::get_type_name, "None");
	cls_BOPAlgo_AlertNotSplittableEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertNotSplittableEdge::get_type_descriptor, "None");
	cls_BOPAlgo_AlertNotSplittableEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertNotSplittableEdge::*)() const ) &BOPAlgo_AlertNotSplittableEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertRemovalOfIBForEdgesFailed, opencascade::handle<BOPAlgo_AlertRemovalOfIBForEdgesFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed(mod, "BOPAlgo_AlertRemovalOfIBForEdgesFailed", "Removal of internal boundaries among Edges has failed");
	cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemovalOfIBForEdgesFailed::get_type_name, "None");
	cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemovalOfIBForEdgesFailed::get_type_descriptor, "None");
	cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemovalOfIBForEdgesFailed::*)() const ) &BOPAlgo_AlertRemovalOfIBForEdgesFailed::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertRemovalOfIBForFacesFailed, opencascade::handle<BOPAlgo_AlertRemovalOfIBForFacesFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertRemovalOfIBForFacesFailed(mod, "BOPAlgo_AlertRemovalOfIBForFacesFailed", "Removal of internal boundaries among Faces has failed");
	cls_BOPAlgo_AlertRemovalOfIBForFacesFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertRemovalOfIBForFacesFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemovalOfIBForFacesFailed::get_type_name, "None");
	cls_BOPAlgo_AlertRemovalOfIBForFacesFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemovalOfIBForFacesFailed::get_type_descriptor, "None");
	cls_BOPAlgo_AlertRemovalOfIBForFacesFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemovalOfIBForFacesFailed::*)() const ) &BOPAlgo_AlertRemovalOfIBForFacesFailed::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertRemovalOfIBForMDimShapes, opencascade::handle<BOPAlgo_AlertRemovalOfIBForMDimShapes>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertRemovalOfIBForMDimShapes(mod, "BOPAlgo_AlertRemovalOfIBForMDimShapes", "Removal of internal boundaries among the multi-dimensional shapes is not supported yet");
	cls_BOPAlgo_AlertRemovalOfIBForMDimShapes.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertRemovalOfIBForMDimShapes.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemovalOfIBForMDimShapes::get_type_name, "None");
	cls_BOPAlgo_AlertRemovalOfIBForMDimShapes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemovalOfIBForMDimShapes::get_type_descriptor, "None");
	cls_BOPAlgo_AlertRemovalOfIBForMDimShapes.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemovalOfIBForMDimShapes::*)() const ) &BOPAlgo_AlertRemovalOfIBForMDimShapes::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertRemovalOfIBForSolidsFailed, opencascade::handle<BOPAlgo_AlertRemovalOfIBForSolidsFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed(mod, "BOPAlgo_AlertRemovalOfIBForSolidsFailed", "Removal of internal boundaries among Solids has failed");
	cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemovalOfIBForSolidsFailed::get_type_name, "None");
	cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemovalOfIBForSolidsFailed::get_type_descriptor, "None");
	cls_BOPAlgo_AlertRemovalOfIBForSolidsFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemovalOfIBForSolidsFailed::*)() const ) &BOPAlgo_AlertRemovalOfIBForSolidsFailed::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertSelfInterferingShape, opencascade::handle<BOPAlgo_AlertSelfInterferingShape>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertSelfInterferingShape(mod, "BOPAlgo_AlertSelfInterferingShape", "Some of the arguments are self-interfering shapes");
	cls_BOPAlgo_AlertSelfInterferingShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertSelfInterferingShape.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertSelfInterferingShape::get_type_name, "None");
	cls_BOPAlgo_AlertSelfInterferingShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertSelfInterferingShape::get_type_descriptor, "None");
	cls_BOPAlgo_AlertSelfInterferingShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertSelfInterferingShape::*)() const ) &BOPAlgo_AlertSelfInterferingShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertShellSplitterFailed, opencascade::handle<BOPAlgo_AlertShellSplitterFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertShellSplitterFailed(mod, "BOPAlgo_AlertShellSplitterFailed", "The positioning of the shapes leads to creation of the small edges without valid range");
	cls_BOPAlgo_AlertShellSplitterFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertShellSplitterFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertShellSplitterFailed::get_type_name, "None");
	cls_BOPAlgo_AlertShellSplitterFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertShellSplitterFailed::get_type_descriptor, "None");
	cls_BOPAlgo_AlertShellSplitterFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertShellSplitterFailed::*)() const ) &BOPAlgo_AlertShellSplitterFailed::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Alerts.hxx
	py::class_<BOPAlgo_AlertTooSmallEdge, opencascade::handle<BOPAlgo_AlertTooSmallEdge>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertTooSmallEdge(mod, "BOPAlgo_AlertTooSmallEdge", "Some edges are too small and have no valid range");
	cls_BOPAlgo_AlertTooSmallEdge.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_BOPAlgo_AlertTooSmallEdge.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertTooSmallEdge::get_type_name, "None");
	cls_BOPAlgo_AlertTooSmallEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertTooSmallEdge::get_type_descriptor, "None");
	cls_BOPAlgo_AlertTooSmallEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertTooSmallEdge::*)() const ) &BOPAlgo_AlertTooSmallEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Options.hxx
	py::class_<BOPAlgo_Options, std::unique_ptr<BOPAlgo_Options, Deleter<BOPAlgo_Options>>> cls_BOPAlgo_Options(mod, "BOPAlgo_Options", "The class provides the following options for the algorithms in Boolean Component: - *Memory allocation tool* - tool for memory allocations; - *Error and warning reporting* - allows recording warnings and errors occurred during the operation. Error means that the algorithm has failed. - *Parallel processing mode* - provides the possibility to perform operation in parallel mode; - *Fuzzy tolerance* - additional tolerance for the operation to detect touching or coinciding cases; - *Progress indicator* - provides interface to track the progress of operation and stop the operation by user's break.");
	cls_BOPAlgo_Options.def(py::init<>());
	cls_BOPAlgo_Options.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_Options.def("Allocator", (const BOPCol_BaseAllocator & (BOPAlgo_Options::*)() const ) &BOPAlgo_Options::Allocator, "Returns allocator");
	cls_BOPAlgo_Options.def("Clear", (void (BOPAlgo_Options::*)()) &BOPAlgo_Options::Clear, "Clears all warnings and errors, and any data cached by the algorithm. User defined options are not cleared.");
	cls_BOPAlgo_Options.def("AddError", (void (BOPAlgo_Options::*)(const opencascade::handle<Message_Alert> &)) &BOPAlgo_Options::AddError, "Adds the alert as error (fail)", py::arg("theAlert"));
	cls_BOPAlgo_Options.def("AddWarning", (void (BOPAlgo_Options::*)(const opencascade::handle<Message_Alert> &)) &BOPAlgo_Options::AddWarning, "Adds the alert as warning", py::arg("theAlert"));
	cls_BOPAlgo_Options.def("HasErrors", (Standard_Boolean (BOPAlgo_Options::*)() const ) &BOPAlgo_Options::HasErrors, "Returns true if algorithm has failed");
	cls_BOPAlgo_Options.def("HasError", (Standard_Boolean (BOPAlgo_Options::*)(const opencascade::handle<Standard_Type> &) const ) &BOPAlgo_Options::HasError, "Returns true if algorithm has generated error of specified type", py::arg("theType"));
	cls_BOPAlgo_Options.def("HasWarnings", (Standard_Boolean (BOPAlgo_Options::*)() const ) &BOPAlgo_Options::HasWarnings, "Returns true if algorithm has generated some warning alerts");
	cls_BOPAlgo_Options.def("HasWarning", (Standard_Boolean (BOPAlgo_Options::*)(const opencascade::handle<Standard_Type> &) const ) &BOPAlgo_Options::HasWarning, "Returns true if algorithm has generated warning of specified type", py::arg("theType"));
	cls_BOPAlgo_Options.def("GetReport", (const opencascade::handle<Message_Report> & (BOPAlgo_Options::*)() const ) &BOPAlgo_Options::GetReport, "Returns report collecting all errors and warnings");
	cls_BOPAlgo_Options.def("DumpErrors", (void (BOPAlgo_Options::*)(Standard_OStream &) const ) &BOPAlgo_Options::DumpErrors, "Dumps the error status into the given stream", py::arg("theOS"));
	cls_BOPAlgo_Options.def("DumpWarnings", (void (BOPAlgo_Options::*)(Standard_OStream &) const ) &BOPAlgo_Options::DumpWarnings, "Dumps the warning statuses into the given stream", py::arg("theOS"));
	cls_BOPAlgo_Options.def("ClearWarnings", (void (BOPAlgo_Options::*)()) &BOPAlgo_Options::ClearWarnings, "Clears the warnings of the algorithm");
	cls_BOPAlgo_Options.def_static("GetParallelMode_", (Standard_Boolean (*)()) &BOPAlgo_Options::GetParallelMode, "Gets the global parallel mode");
	cls_BOPAlgo_Options.def_static("SetParallelMode_", (void (*)(const Standard_Boolean)) &BOPAlgo_Options::SetParallelMode, "Sets the global parallel mode", py::arg("theNewMode"));
	cls_BOPAlgo_Options.def("SetRunParallel", (void (BOPAlgo_Options::*)(const Standard_Boolean)) &BOPAlgo_Options::SetRunParallel, "Set the flag of parallel processing if <theFlag> is true the parallel processing is switched on if <theFlag> is false the parallel processing is switched off", py::arg("theFlag"));
	cls_BOPAlgo_Options.def("RunParallel", (Standard_Boolean (BOPAlgo_Options::*)() const ) &BOPAlgo_Options::RunParallel, "Returns the flag of parallel processing");
	cls_BOPAlgo_Options.def("SetFuzzyValue", (void (BOPAlgo_Options::*)(const Standard_Real)) &BOPAlgo_Options::SetFuzzyValue, "Sets the additional tolerance", py::arg("theFuzz"));
	cls_BOPAlgo_Options.def("FuzzyValue", (Standard_Real (BOPAlgo_Options::*)() const ) &BOPAlgo_Options::FuzzyValue, "Returns the additional tolerance");
	cls_BOPAlgo_Options.def("SetProgressIndicator", (void (BOPAlgo_Options::*)(const opencascade::handle<Message_ProgressIndicator> &)) &BOPAlgo_Options::SetProgressIndicator, "Set the Progress Indicator object.", py::arg("theObj"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Algo.hxx
	py::class_<BOPAlgo_Algo, std::unique_ptr<BOPAlgo_Algo, py::nodelete>, BOPAlgo_Options> cls_BOPAlgo_Algo(mod, "BOPAlgo_Algo", "The class provides the root interface for the algorithms in Boolean Component.");
	cls_BOPAlgo_Algo.def("Perform", (void (BOPAlgo_Algo::*)()) &BOPAlgo_Algo::Perform, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_CheckResult.hxx
	py::class_<BOPAlgo_CheckResult, std::unique_ptr<BOPAlgo_CheckResult, Deleter<BOPAlgo_CheckResult>>> cls_BOPAlgo_CheckResult(mod, "BOPAlgo_CheckResult", "contains information about faulty shapes and faulty types can't be processed by Boolean Operations");
	cls_BOPAlgo_CheckResult.def(py::init<>());
	cls_BOPAlgo_CheckResult.def("SetShape1", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::SetShape1, "sets ancestor shape (object) for faulty sub-shapes", py::arg("TheShape"));
	cls_BOPAlgo_CheckResult.def("AddFaultyShape1", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::AddFaultyShape1, "adds faulty sub-shapes from object to a list", py::arg("TheShape"));
	cls_BOPAlgo_CheckResult.def("SetShape2", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::SetShape2, "sets ancestor shape (tool) for faulty sub-shapes", py::arg("TheShape"));
	cls_BOPAlgo_CheckResult.def("AddFaultyShape2", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::AddFaultyShape2, "adds faulty sub-shapes from tool to a list", py::arg("TheShape"));
	cls_BOPAlgo_CheckResult.def("GetShape1", (const TopoDS_Shape & (BOPAlgo_CheckResult::*)() const ) &BOPAlgo_CheckResult::GetShape1, "returns ancestor shape (object) for faulties");
	cls_BOPAlgo_CheckResult.def("GetShape2", (const TopoDS_Shape & (BOPAlgo_CheckResult::*)() const ) &BOPAlgo_CheckResult::GetShape2, "returns ancestor shape (tool) for faulties");
	cls_BOPAlgo_CheckResult.def("GetFaultyShapes1", (const BOPCol_ListOfShape & (BOPAlgo_CheckResult::*)() const ) &BOPAlgo_CheckResult::GetFaultyShapes1, "returns list of faulty shapes for object");
	cls_BOPAlgo_CheckResult.def("GetFaultyShapes2", (const BOPCol_ListOfShape & (BOPAlgo_CheckResult::*)() const ) &BOPAlgo_CheckResult::GetFaultyShapes2, "returns list of faulty shapes for tool");
	cls_BOPAlgo_CheckResult.def("SetCheckStatus", (void (BOPAlgo_CheckResult::*)(const BOPAlgo_CheckStatus)) &BOPAlgo_CheckResult::SetCheckStatus, "set status of faulty", py::arg("TheStatus"));
	cls_BOPAlgo_CheckResult.def("GetCheckStatus", (BOPAlgo_CheckStatus (BOPAlgo_CheckResult::*)() const ) &BOPAlgo_CheckResult::GetCheckStatus, "gets status of faulty");
	cls_BOPAlgo_CheckResult.def("SetMaxDistance1", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxDistance1, "Sets max distance for the first shape", py::arg("theDist"));
	cls_BOPAlgo_CheckResult.def("SetMaxDistance2", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxDistance2, "Sets max distance for the second shape", py::arg("theDist"));
	cls_BOPAlgo_CheckResult.def("SetMaxParameter1", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxParameter1, "Sets the parameter for the first shape", py::arg("thePar"));
	cls_BOPAlgo_CheckResult.def("SetMaxParameter2", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxParameter2, "Sets the parameter for the second shape", py::arg("thePar"));
	cls_BOPAlgo_CheckResult.def("GetMaxDistance1", (Standard_Real (BOPAlgo_CheckResult::*)() const ) &BOPAlgo_CheckResult::GetMaxDistance1, "Returns the distance for the first shape");
	cls_BOPAlgo_CheckResult.def("GetMaxDistance2", (Standard_Real (BOPAlgo_CheckResult::*)() const ) &BOPAlgo_CheckResult::GetMaxDistance2, "Returns the distance for the second shape");
	cls_BOPAlgo_CheckResult.def("GetMaxParameter1", (Standard_Real (BOPAlgo_CheckResult::*)() const ) &BOPAlgo_CheckResult::GetMaxParameter1, "Returns the parameter for the fircst shape");
	cls_BOPAlgo_CheckResult.def("GetMaxParameter2", (Standard_Real (BOPAlgo_CheckResult::*)() const ) &BOPAlgo_CheckResult::GetMaxParameter2, "Returns the parameter for the second shape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_ArgumentAnalyzer.hxx
	py::class_<BOPAlgo_ArgumentAnalyzer, std::unique_ptr<BOPAlgo_ArgumentAnalyzer, Deleter<BOPAlgo_ArgumentAnalyzer>>, BOPAlgo_Algo> cls_BOPAlgo_ArgumentAnalyzer(mod, "BOPAlgo_ArgumentAnalyzer", "check the validity of argument(s) for Boolean Operations");
	cls_BOPAlgo_ArgumentAnalyzer.def(py::init<>());
	cls_BOPAlgo_ArgumentAnalyzer.def("SetShape1", (void (BOPAlgo_ArgumentAnalyzer::*)(const TopoDS_Shape &)) &BOPAlgo_ArgumentAnalyzer::SetShape1, "sets object shape", py::arg("TheShape"));
	cls_BOPAlgo_ArgumentAnalyzer.def("SetShape2", (void (BOPAlgo_ArgumentAnalyzer::*)(const TopoDS_Shape &)) &BOPAlgo_ArgumentAnalyzer::SetShape2, "sets tool shape", py::arg("TheShape"));
	cls_BOPAlgo_ArgumentAnalyzer.def("GetShape1", (const TopoDS_Shape & (BOPAlgo_ArgumentAnalyzer::*)() const ) &BOPAlgo_ArgumentAnalyzer::GetShape1, "returns object shape;");
	cls_BOPAlgo_ArgumentAnalyzer.def("GetShape2", (const TopoDS_Shape & (BOPAlgo_ArgumentAnalyzer::*)() const ) &BOPAlgo_ArgumentAnalyzer::GetShape2, "returns tool shape");
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
	cls_BOPAlgo_ArgumentAnalyzer.def("HasFaulty", (Standard_Boolean (BOPAlgo_ArgumentAnalyzer::*)() const ) &BOPAlgo_ArgumentAnalyzer::HasFaulty, "result of test");
	cls_BOPAlgo_ArgumentAnalyzer.def("GetCheckResult", (const BOPAlgo_ListOfCheckResult & (BOPAlgo_ArgumentAnalyzer::*)() const ) &BOPAlgo_ArgumentAnalyzer::GetCheckResult, "returns a result of test");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_PaveFiller.hxx
	py::class_<BOPAlgo_PaveFiller, std::unique_ptr<BOPAlgo_PaveFiller, Deleter<BOPAlgo_PaveFiller>>, BOPAlgo_Algo> cls_BOPAlgo_PaveFiller(mod, "BOPAlgo_PaveFiller", "The class represents the Intersection phase of the Boolean Operations algorithm. It performs the pairwise intersection of the sub-shapes of the arguments in the following order: 1. Vertex/Vertex; 2. Vertex/Edge; 3. Edge/Edge; 4. Vertex/Face; 5. Edge/Face; 6. Face/Face.");
	cls_BOPAlgo_PaveFiller.def(py::init<>());
	cls_BOPAlgo_PaveFiller.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_PaveFiller.def("DS", (const BOPDS_DS & (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::DS, "None");
	cls_BOPAlgo_PaveFiller.def("PDS", (BOPDS_PDS (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::PDS, "None");
	cls_BOPAlgo_PaveFiller.def("Iterator", (const BOPDS_PIterator & (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::Iterator, "None");
	cls_BOPAlgo_PaveFiller.def("SetArguments", (void (BOPAlgo_PaveFiller::*)(const BOPCol_ListOfShape &)) &BOPAlgo_PaveFiller::SetArguments, "None", py::arg("theLS"));
	cls_BOPAlgo_PaveFiller.def("Arguments", (const BOPCol_ListOfShape & (BOPAlgo_PaveFiller::*)() const ) &BOPAlgo_PaveFiller::Arguments, "None");
	cls_BOPAlgo_PaveFiller.def("Context", (const opencascade::handle<IntTools_Context> & (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::Context, "None");
	cls_BOPAlgo_PaveFiller.def("SetSectionAttribute", (void (BOPAlgo_PaveFiller::*)(const BOPAlgo_SectionAttribute &)) &BOPAlgo_PaveFiller::SetSectionAttribute, "None", py::arg("theSecAttr"));
	cls_BOPAlgo_PaveFiller.def("SetNonDestructive", (void (BOPAlgo_PaveFiller::*)(const Standard_Boolean)) &BOPAlgo_PaveFiller::SetNonDestructive, "Sets the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.", py::arg("theFlag"));
	cls_BOPAlgo_PaveFiller.def("NonDestructive", (Standard_Boolean (BOPAlgo_PaveFiller::*)() const ) &BOPAlgo_PaveFiller::NonDestructive, "Returns the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.");
	cls_BOPAlgo_PaveFiller.def("Perform", (void (BOPAlgo_PaveFiller::*)()) &BOPAlgo_PaveFiller::Perform, "None");
	cls_BOPAlgo_PaveFiller.def("SetGlue", (void (BOPAlgo_PaveFiller::*)(const BOPAlgo_GlueEnum)) &BOPAlgo_PaveFiller::SetGlue, "Sets the glue option for the algorithm", py::arg("theGlue"));
	cls_BOPAlgo_PaveFiller.def("Glue", (BOPAlgo_GlueEnum (BOPAlgo_PaveFiller::*)() const ) &BOPAlgo_PaveFiller::Glue, "Returns the glue option of the algorithm");
	cls_BOPAlgo_PaveFiller.def("SetAvoidBuildPCurve", (void (BOPAlgo_PaveFiller::*)(const Standard_Boolean)) &BOPAlgo_PaveFiller::SetAvoidBuildPCurve, "Sets the flag to avoid building of p-curves of edges on faces", py::arg("theValue"));
	cls_BOPAlgo_PaveFiller.def("IsAvoidBuildPCurve", (Standard_Boolean (BOPAlgo_PaveFiller::*)() const ) &BOPAlgo_PaveFiller::IsAvoidBuildPCurve, "Returns the flag to avoid building of p-curves of edges on faces");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_BuilderShape.hxx
	py::class_<BOPAlgo_BuilderShape, std::unique_ptr<BOPAlgo_BuilderShape, py::nodelete>, BOPAlgo_Algo> cls_BOPAlgo_BuilderShape(mod, "BOPAlgo_BuilderShape", "Root class for algorithms that has shape as result. The class provides the History mechanism, which allows tracking the modification of the input shapes during the operation.");
	cls_BOPAlgo_BuilderShape.def("Shape", (const TopoDS_Shape & (BOPAlgo_BuilderShape::*)() const ) &BOPAlgo_BuilderShape::Shape, "Returns the result of algorithm");
	cls_BOPAlgo_BuilderShape.def("Generated", (const TopTools_ListOfShape & (BOPAlgo_BuilderShape::*)(const TopoDS_Shape &)) &BOPAlgo_BuilderShape::Generated, "Returns the list of shapes generated from the shape theS.", py::arg("theS"));
	cls_BOPAlgo_BuilderShape.def("Modified", (const TopTools_ListOfShape & (BOPAlgo_BuilderShape::*)(const TopoDS_Shape &)) &BOPAlgo_BuilderShape::Modified, "Returns the list of shapes modified from the shape theS.", py::arg("theS"));
	cls_BOPAlgo_BuilderShape.def("IsDeleted", (Standard_Boolean (BOPAlgo_BuilderShape::*)(const TopoDS_Shape &)) &BOPAlgo_BuilderShape::IsDeleted, "Returns true if the shape theS has been deleted.", py::arg("theS"));
	cls_BOPAlgo_BuilderShape.def("HasDeleted", (Standard_Boolean (BOPAlgo_BuilderShape::*)() const ) &BOPAlgo_BuilderShape::HasDeleted, "Returns true if the at least one shape(or subshape) of arguments has been deleted.");
	cls_BOPAlgo_BuilderShape.def("HasGenerated", (Standard_Boolean (BOPAlgo_BuilderShape::*)() const ) &BOPAlgo_BuilderShape::HasGenerated, "Returns true if the at least one shape(or subshape) of arguments has generated shapes.");
	cls_BOPAlgo_BuilderShape.def("HasModified", (Standard_Boolean (BOPAlgo_BuilderShape::*)() const ) &BOPAlgo_BuilderShape::HasModified, "Returns true if the at least one shape(or subshape) of arguments has modified shapes.");
	cls_BOPAlgo_BuilderShape.def("ImagesResult", (const BOPCol_IndexedDataMapOfShapeListOfShape & (BOPAlgo_BuilderShape::*)() const ) &BOPAlgo_BuilderShape::ImagesResult, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Builder.hxx
	py::class_<BOPAlgo_Builder, std::unique_ptr<BOPAlgo_Builder, Deleter<BOPAlgo_Builder>>, BOPAlgo_BuilderShape> cls_BOPAlgo_Builder(mod, "BOPAlgo_Builder", "The class is a General Fuse algorithm - base algorithm for the algorithms in the Boolean Component. Its main purpose is to build the split parts of the argument shapes from which the result of the operations is combined. The result of the General Fuse algorithm itself is a compound containing all split parts of the arguments.");
	cls_BOPAlgo_Builder.def(py::init<>());
	cls_BOPAlgo_Builder.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_Builder.def("Clear", (void (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::Clear, "None");
	cls_BOPAlgo_Builder.def("PPaveFiller", (BOPAlgo_PPaveFiller (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::PPaveFiller, "None");
	cls_BOPAlgo_Builder.def("PDS", (BOPDS_PDS (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::PDS, "None");
	cls_BOPAlgo_Builder.def("AddArgument", (void (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::AddArgument, "None", py::arg("theShape"));
	cls_BOPAlgo_Builder.def("SetArguments", (void (BOPAlgo_Builder::*)(const BOPCol_ListOfShape &)) &BOPAlgo_Builder::SetArguments, "None", py::arg("theLS"));
	cls_BOPAlgo_Builder.def("Arguments", (const BOPCol_ListOfShape & (BOPAlgo_Builder::*)() const ) &BOPAlgo_Builder::Arguments, "None");
	cls_BOPAlgo_Builder.def("Perform", (void (BOPAlgo_Builder::*)()) &BOPAlgo_Builder::Perform, "None");
	cls_BOPAlgo_Builder.def("PerformWithFiller", (void (BOPAlgo_Builder::*)(const BOPAlgo_PaveFiller &)) &BOPAlgo_Builder::PerformWithFiller, "None", py::arg("theFiller"));
	cls_BOPAlgo_Builder.def("Generated", (const TopTools_ListOfShape & (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::Generated, "Returns the list of shapes generated from the shape theS.", py::arg("theS"));
	cls_BOPAlgo_Builder.def("Modified", (const TopTools_ListOfShape & (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::Modified, "Returns the list of shapes modified from the shape theS.", py::arg("theS"));
	cls_BOPAlgo_Builder.def("IsDeleted", (Standard_Boolean (BOPAlgo_Builder::*)(const TopoDS_Shape &)) &BOPAlgo_Builder::IsDeleted, "Returns true if the shape theS has been deleted.", py::arg("theS"));
	cls_BOPAlgo_Builder.def("Images", (const BOPCol_DataMapOfShapeListOfShape & (BOPAlgo_Builder::*)() const ) &BOPAlgo_Builder::Images, "None");
	cls_BOPAlgo_Builder.def("IsInterferred", (Standard_Boolean (BOPAlgo_Builder::*)(const TopoDS_Shape &) const ) &BOPAlgo_Builder::IsInterferred, "None", py::arg("theS"));
	cls_BOPAlgo_Builder.def("Origins", (const BOPCol_DataMapOfShapeListOfShape & (BOPAlgo_Builder::*)() const ) &BOPAlgo_Builder::Origins, "Returns myOrigins.");
	cls_BOPAlgo_Builder.def("ShapesSD", (const BOPCol_DataMapOfShapeShape & (BOPAlgo_Builder::*)() const ) &BOPAlgo_Builder::ShapesSD, "Returns myShapesSD.");
	cls_BOPAlgo_Builder.def("Splits", (const BOPCol_DataMapOfShapeListOfShape & (BOPAlgo_Builder::*)() const ) &BOPAlgo_Builder::Splits, "Returns mySplits.");
	cls_BOPAlgo_Builder.def("SetNonDestructive", (void (BOPAlgo_Builder::*)(const Standard_Boolean)) &BOPAlgo_Builder::SetNonDestructive, "Sets the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated. This flag is taken into account if internal PaveFiller is used only. In the case of calling PerformWithFiller the corresponding flag of that PaveFiller is in force.", py::arg("theFlag"));
	cls_BOPAlgo_Builder.def("NonDestructive", (Standard_Boolean (BOPAlgo_Builder::*)() const ) &BOPAlgo_Builder::NonDestructive, "Returns the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.");
	cls_BOPAlgo_Builder.def("SetGlue", (void (BOPAlgo_Builder::*)(const BOPAlgo_GlueEnum)) &BOPAlgo_Builder::SetGlue, "Sets the glue option for the algorithm", py::arg("theGlue"));
	cls_BOPAlgo_Builder.def("Glue", (BOPAlgo_GlueEnum (BOPAlgo_Builder::*)() const ) &BOPAlgo_Builder::Glue, "Returns the glue option of the algorithm");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_BOP.hxx
	py::class_<BOPAlgo_BOP, std::unique_ptr<BOPAlgo_BOP, Deleter<BOPAlgo_BOP>>, BOPAlgo_Builder> cls_BOPAlgo_BOP(mod, "BOPAlgo_BOP", "The class represents the Building part of the Boolean Operations algorithm. The arguments of the algorithms are divided in two groups - *Objects* and *Tools*. The algorithm builds the splits of the given arguments using the intersection results and combines the result of Boolean Operation of given type: - *FUSE* - union of two groups of objects; - *COMMON* - intersection of two groups of objects; - *CUT* - subtraction of one group from the other.");
	cls_BOPAlgo_BOP.def(py::init<>());
	cls_BOPAlgo_BOP.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_BOP.def("Clear", (void (BOPAlgo_BOP::*)()) &BOPAlgo_BOP::Clear, "Clears internal fields and arguments");
	cls_BOPAlgo_BOP.def("AddTool", (void (BOPAlgo_BOP::*)(const TopoDS_Shape &)) &BOPAlgo_BOP::AddTool, "Adds Tool argument of the operation", py::arg("theShape"));
	cls_BOPAlgo_BOP.def("SetTools", (void (BOPAlgo_BOP::*)(const BOPCol_ListOfShape &)) &BOPAlgo_BOP::SetTools, "None", py::arg("theShapes"));
	cls_BOPAlgo_BOP.def("SetOperation", (void (BOPAlgo_BOP::*)(const BOPAlgo_Operation)) &BOPAlgo_BOP::SetOperation, "None", py::arg("theOperation"));
	cls_BOPAlgo_BOP.def("Operation", (BOPAlgo_Operation (BOPAlgo_BOP::*)() const ) &BOPAlgo_BOP::Operation, "None");
	cls_BOPAlgo_BOP.def("Perform", (void (BOPAlgo_BOP::*)()) &BOPAlgo_BOP::Perform, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_BuilderArea.hxx
	py::class_<BOPAlgo_BuilderArea, std::unique_ptr<BOPAlgo_BuilderArea, py::nodelete>, BOPAlgo_Algo> cls_BOPAlgo_BuilderArea(mod, "BOPAlgo_BuilderArea", "The root class for algorithms to build faces/solids from set of edges/faces");
	cls_BOPAlgo_BuilderArea.def("SetContext", (void (BOPAlgo_BuilderArea::*)(const opencascade::handle<IntTools_Context> &)) &BOPAlgo_BuilderArea::SetContext, "Sets the context for the algorithms", py::arg("theContext"));
	cls_BOPAlgo_BuilderArea.def("Shapes", (const BOPCol_ListOfShape & (BOPAlgo_BuilderArea::*)() const ) &BOPAlgo_BuilderArea::Shapes, "Returns the input shapes");
	cls_BOPAlgo_BuilderArea.def("SetShapes", (void (BOPAlgo_BuilderArea::*)(const BOPCol_ListOfShape &)) &BOPAlgo_BuilderArea::SetShapes, "Sets the shapes for building areas", py::arg("theLS"));
	cls_BOPAlgo_BuilderArea.def("Loops", (const BOPCol_ListOfShape & (BOPAlgo_BuilderArea::*)() const ) &BOPAlgo_BuilderArea::Loops, "Returns the found loops");
	cls_BOPAlgo_BuilderArea.def("Areas", (const BOPCol_ListOfShape & (BOPAlgo_BuilderArea::*)() const ) &BOPAlgo_BuilderArea::Areas, "Returns the found areas");
	cls_BOPAlgo_BuilderArea.def("SetAvoidInternalShapes", (void (BOPAlgo_BuilderArea::*)(const Standard_Boolean)) &BOPAlgo_BuilderArea::SetAvoidInternalShapes, "Defines the preventing of addition of internal parts into result. The default value is FALSE, i.e. the internal parts are added into result.", py::arg("theAvoidInternal"));
	cls_BOPAlgo_BuilderArea.def("IsAvoidInternalShapes", (Standard_Boolean (BOPAlgo_BuilderArea::*)() const ) &BOPAlgo_BuilderArea::IsAvoidInternalShapes, "Returns the AvoidInternalShapes flag");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_BuilderFace.hxx
	py::class_<BOPAlgo_BuilderFace, std::unique_ptr<BOPAlgo_BuilderFace, Deleter<BOPAlgo_BuilderFace>>, BOPAlgo_BuilderArea> cls_BOPAlgo_BuilderFace(mod, "BOPAlgo_BuilderFace", "The algorithm to build new faces from the given faces and set of edges lying on this face.");
	cls_BOPAlgo_BuilderFace.def(py::init<>());
	cls_BOPAlgo_BuilderFace.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_BuilderFace.def("SetFace", (void (BOPAlgo_BuilderFace::*)(const TopoDS_Face &)) &BOPAlgo_BuilderFace::SetFace, "Sets the face generatix", py::arg("theFace"));
	cls_BOPAlgo_BuilderFace.def("Face", (const TopoDS_Face & (BOPAlgo_BuilderFace::*)() const ) &BOPAlgo_BuilderFace::Face, "Returns the face generatix");
	cls_BOPAlgo_BuilderFace.def("Perform", (void (BOPAlgo_BuilderFace::*)()) &BOPAlgo_BuilderFace::Perform, "Performs the algorithm");
	cls_BOPAlgo_BuilderFace.def("Orientation", (TopAbs_Orientation (BOPAlgo_BuilderFace::*)() const ) &BOPAlgo_BuilderFace::Orientation, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_BuilderSolid.hxx
	py::class_<BOPAlgo_BuilderSolid, std::unique_ptr<BOPAlgo_BuilderSolid, Deleter<BOPAlgo_BuilderSolid>>, BOPAlgo_BuilderArea> cls_BOPAlgo_BuilderSolid(mod, "BOPAlgo_BuilderSolid", "The algorithm to build solids from set of faces");
	cls_BOPAlgo_BuilderSolid.def(py::init<>());
	cls_BOPAlgo_BuilderSolid.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_BuilderSolid.def("SetSolid", (void (BOPAlgo_BuilderSolid::*)(const TopoDS_Solid &)) &BOPAlgo_BuilderSolid::SetSolid, "Sets the source solid <theSolid>", py::arg("theSolid"));
	cls_BOPAlgo_BuilderSolid.def("Solid", (const TopoDS_Solid & (BOPAlgo_BuilderSolid::*)() const ) &BOPAlgo_BuilderSolid::Solid, "Returns the source solid");
	cls_BOPAlgo_BuilderSolid.def("Perform", (void (BOPAlgo_BuilderSolid::*)()) &BOPAlgo_BuilderSolid::Perform, "Performs the algorithm");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_CellsBuilder.hxx
	py::class_<BOPAlgo_CellsBuilder, std::unique_ptr<BOPAlgo_CellsBuilder, Deleter<BOPAlgo_CellsBuilder>>, BOPAlgo_Builder> cls_BOPAlgo_CellsBuilder(mod, "BOPAlgo_CellsBuilder", "The algorithm is based on the General Fuse algorithm (GFA). The result of GFA is all split parts of the Arguments.");
	cls_BOPAlgo_CellsBuilder.def(py::init<>());
	cls_BOPAlgo_CellsBuilder.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPAlgo_CellsBuilder.def("Clear", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::Clear, "Redefined method Clear - clears the contents.");
	cls_BOPAlgo_CellsBuilder.def("AddToResult", [](BOPAlgo_CellsBuilder &self, const BOPCol_ListOfShape & a0, const BOPCol_ListOfShape & a1) -> void { return self.AddToResult(a0, a1); }, py::arg("theLSToTake"), py::arg("theLSToAvoid"));
	cls_BOPAlgo_CellsBuilder.def("AddToResult", [](BOPAlgo_CellsBuilder &self, const BOPCol_ListOfShape & a0, const BOPCol_ListOfShape & a1, const Standard_Integer a2) -> void { return self.AddToResult(a0, a1, a2); }, py::arg("theLSToTake"), py::arg("theLSToAvoid"), py::arg("theMaterial"));
	cls_BOPAlgo_CellsBuilder.def("AddToResult", (void (BOPAlgo_CellsBuilder::*)(const BOPCol_ListOfShape &, const BOPCol_ListOfShape &, const Standard_Integer, const Standard_Boolean)) &BOPAlgo_CellsBuilder::AddToResult, "Adding the parts to result. The parts are defined by two lists of shapes: <theLSToTake> defines the arguments which parts should be taken into result; <theLSToAvoid> defines the arguments which parts should not be taken into result; To be taken into result the part must be IN for all shapes from the list <theLSToTake> and must be OUT of all shapes from the list <theLSToAvoid>.", py::arg("theLSToTake"), py::arg("theLSToAvoid"), py::arg("theMaterial"), py::arg("theUpdate"));
	cls_BOPAlgo_CellsBuilder.def("AddAllToResult", [](BOPAlgo_CellsBuilder &self) -> void { return self.AddAllToResult(); });
	cls_BOPAlgo_CellsBuilder.def("AddAllToResult", [](BOPAlgo_CellsBuilder &self, const Standard_Integer a0) -> void { return self.AddAllToResult(a0); }, py::arg("theMaterial"));
	cls_BOPAlgo_CellsBuilder.def("AddAllToResult", (void (BOPAlgo_CellsBuilder::*)(const Standard_Integer, const Standard_Boolean)) &BOPAlgo_CellsBuilder::AddAllToResult, "Add all split parts to result. <theMaterial> defines the removal of internal boundaries; <theUpdate> parameter defines whether to remove boundaries now or not.", py::arg("theMaterial"), py::arg("theUpdate"));
	cls_BOPAlgo_CellsBuilder.def("RemoveFromResult", (void (BOPAlgo_CellsBuilder::*)(const BOPCol_ListOfShape &, const BOPCol_ListOfShape &)) &BOPAlgo_CellsBuilder::RemoveFromResult, "Removing the parts from result. The parts are defined by two lists of shapes: <theLSToTake> defines the arguments which parts should be removed from result; <theLSToAvoid> defines the arguments which parts should not be removed from result. To be removed from the result the part must be IN for all shapes from the list <theLSToTake> and must be OUT of all shapes from the list <theLSToAvoid>.", py::arg("theLSToTake"), py::arg("theLSToAvoid"));
	cls_BOPAlgo_CellsBuilder.def("RemoveAllFromResult", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::RemoveAllFromResult, "Remove all parts from result.");
	cls_BOPAlgo_CellsBuilder.def("RemoveInternalBoundaries", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::RemoveInternalBoundaries, "Removes internal boundaries between cells with the same material. If the result contains the cells with same material but of different dimension the removal of internal boundaries between these cells will not be performed. In case of some errors during the removal the method will set the appropriate warning status - use GetReport() to access them.");
	cls_BOPAlgo_CellsBuilder.def("GetAllParts", (const TopoDS_Shape & (BOPAlgo_CellsBuilder::*)() const ) &BOPAlgo_CellsBuilder::GetAllParts, "Get all split parts.");
	cls_BOPAlgo_CellsBuilder.def("MakeContainers", (void (BOPAlgo_CellsBuilder::*)()) &BOPAlgo_CellsBuilder::MakeContainers, "Makes the Containers of proper type from the parts added to result.");
	cls_BOPAlgo_CellsBuilder.def("Modified", (const TopTools_ListOfShape & (BOPAlgo_CellsBuilder::*)(const TopoDS_Shape &)) &BOPAlgo_CellsBuilder::Modified, "Returns the list of shapes generated from the shape theS.", py::arg("theS"));
	cls_BOPAlgo_CellsBuilder.def("IsDeleted", (Standard_Boolean (BOPAlgo_CellsBuilder::*)(const TopoDS_Shape &)) &BOPAlgo_CellsBuilder::IsDeleted, "Returns true if the shape theS has been deleted.", py::arg("theS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_SectionAttribute.hxx
	py::class_<BOPAlgo_SectionAttribute, std::unique_ptr<BOPAlgo_SectionAttribute, Deleter<BOPAlgo_SectionAttribute>>> cls_BOPAlgo_SectionAttribute(mod, "BOPAlgo_SectionAttribute", "Class is a container of three flags used by intersection algorithm");
	cls_BOPAlgo_SectionAttribute.def(py::init<>());
	cls_BOPAlgo_SectionAttribute.def(py::init<const Standard_Boolean>(), py::arg("Aproximation"));
	cls_BOPAlgo_SectionAttribute.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("Aproximation"), py::arg("PCurveOnS1"));
	cls_BOPAlgo_SectionAttribute.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("Aproximation"), py::arg("PCurveOnS1"), py::arg("PCurveOnS2"));
	cls_BOPAlgo_SectionAttribute.def("Approximation", (void (BOPAlgo_SectionAttribute::*)(const Standard_Boolean)) &BOPAlgo_SectionAttribute::Approximation, "Modifier", py::arg("theFlag"));
	cls_BOPAlgo_SectionAttribute.def("PCurveOnS1", (void (BOPAlgo_SectionAttribute::*)(const Standard_Boolean)) &BOPAlgo_SectionAttribute::PCurveOnS1, "Modifier", py::arg("theFlag"));
	cls_BOPAlgo_SectionAttribute.def("PCurveOnS2", (void (BOPAlgo_SectionAttribute::*)(const Standard_Boolean)) &BOPAlgo_SectionAttribute::PCurveOnS2, "Modifier", py::arg("theFlag"));
	cls_BOPAlgo_SectionAttribute.def("Approximation", (Standard_Boolean (BOPAlgo_SectionAttribute::*)() const ) &BOPAlgo_SectionAttribute::Approximation, "Selector");
	cls_BOPAlgo_SectionAttribute.def("PCurveOnS1", (Standard_Boolean (BOPAlgo_SectionAttribute::*)() const ) &BOPAlgo_SectionAttribute::PCurveOnS1, "Selector");
	cls_BOPAlgo_SectionAttribute.def("PCurveOnS2", (Standard_Boolean (BOPAlgo_SectionAttribute::*)() const ) &BOPAlgo_SectionAttribute::PCurveOnS2, "Selector");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_CheckerSI.hxx
	py::class_<BOPAlgo_CheckerSI, std::unique_ptr<BOPAlgo_CheckerSI, Deleter<BOPAlgo_CheckerSI>>, BOPAlgo_PaveFiller> cls_BOPAlgo_CheckerSI(mod, "BOPAlgo_CheckerSI", "Checks the shape on self-interference.");
	cls_BOPAlgo_CheckerSI.def(py::init<>());
	cls_BOPAlgo_CheckerSI.def("Perform", (void (BOPAlgo_CheckerSI::*)()) &BOPAlgo_CheckerSI::Perform, "None");
	cls_BOPAlgo_CheckerSI.def("SetLevelOfCheck", (void (BOPAlgo_CheckerSI::*)(const Standard_Integer)) &BOPAlgo_CheckerSI::SetLevelOfCheck, "Sets the level of checking shape on self-interference. It defines which interferences will be checked: 0 - only V/V; 1 - V/V and V/E; 2 - V/V, V/E and E/E; 3 - V/V, V/E, E/E and V/F; 4 - V/V, V/E, E/E, V/F and E/F; 5 - V/V, V/E, E/E, V/F, E/F and F/F; 6 - V/V, V/E, E/E, V/F, E/F, F/F and V/S; 7 - V/V, V/E, E/E, V/F, E/F, F/F, V/S and E/S; 8 - V/V, V/E, E/E, V/F, E/F, F/F, V/S, E/S and F/S; 9 - V/V, V/E, E/E, V/F, E/F, F/F, V/S, E/S, F/S and S/S - all interferences (Default value)", py::arg("theLevel"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_MakerVolume.hxx
	py::class_<BOPAlgo_MakerVolume, std::unique_ptr<BOPAlgo_MakerVolume, Deleter<BOPAlgo_MakerVolume>>, BOPAlgo_Builder> cls_BOPAlgo_MakerVolume(mod, "BOPAlgo_MakerVolume", "The algorithm is to build solids from set of shapes. It uses the BOPAlgo_Builder algorithm to intersect the given shapes and build the images of faces (if needed) and BOPAlgo_BuilderSolid algorithm to build the solids.");
	cls_BOPAlgo_MakerVolume.def(py::init<>());
	cls_BOPAlgo_MakerVolume.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_MakerVolume.def("Clear", (void (BOPAlgo_MakerVolume::*)()) &BOPAlgo_MakerVolume::Clear, "Clears the data.");
	cls_BOPAlgo_MakerVolume.def("SetIntersect", (void (BOPAlgo_MakerVolume::*)(const Standard_Boolean)) &BOPAlgo_MakerVolume::SetIntersect, "Sets the flag myIntersect: if <bIntersect> is TRUE the shapes from <myArguments> will be intersected. if <bIntersect> is FALSE no intersection will be done.", py::arg("bIntersect"));
	cls_BOPAlgo_MakerVolume.def("IsIntersect", (Standard_Boolean (BOPAlgo_MakerVolume::*)() const ) &BOPAlgo_MakerVolume::IsIntersect, "Returns the flag <myIntersect>.");
	cls_BOPAlgo_MakerVolume.def("Box", (const TopoDS_Solid & (BOPAlgo_MakerVolume::*)() const ) &BOPAlgo_MakerVolume::Box, "Returns the solid box <mySBox>.");
	cls_BOPAlgo_MakerVolume.def("Faces", (const BOPCol_ListOfShape & (BOPAlgo_MakerVolume::*)() const ) &BOPAlgo_MakerVolume::Faces, "Returns the processed faces <myFaces>.");
	cls_BOPAlgo_MakerVolume.def("SetAvoidInternalShapes", (void (BOPAlgo_MakerVolume::*)(const Standard_Boolean)) &BOPAlgo_MakerVolume::SetAvoidInternalShapes, "Defines the preventing of addition of internal for solid parts into the result. By default the internal parts are added into result.", py::arg("theAvoidInternal"));
	cls_BOPAlgo_MakerVolume.def("IsAvoidInternalShapes", (Standard_Boolean (BOPAlgo_MakerVolume::*)() const ) &BOPAlgo_MakerVolume::IsAvoidInternalShapes, "Returns the AvoidInternalShapes flag");
	cls_BOPAlgo_MakerVolume.def("Perform", (void (BOPAlgo_MakerVolume::*)()) &BOPAlgo_MakerVolume::Perform, "Performs the operation.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Section.hxx
	py::class_<BOPAlgo_Section, std::unique_ptr<BOPAlgo_Section, Deleter<BOPAlgo_Section>>, BOPAlgo_Builder> cls_BOPAlgo_Section(mod, "BOPAlgo_Section", "The algorithm to build a Section between the arguments. The Section consists of vertices and edges. The Section contains: 1. new vertices that are subjects of V/V, E/E, E/F, F/F interferences 2. vertices that are subjects of V/E, V/F interferences 3. new edges that are subjects of F/F interferences 4. edges that are Common Blocks");
	cls_BOPAlgo_Section.def(py::init<>());
	cls_BOPAlgo_Section.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_Section.def("BuildSection", (void (BOPAlgo_Section::*)()) &BOPAlgo_Section::BuildSection, "None");
	cls_BOPAlgo_Section.def("Generated", (const TopTools_ListOfShape & (BOPAlgo_Section::*)(const TopoDS_Shape &)) &BOPAlgo_Section::Generated, "Returns the list of shapes generated from the shape theS.", py::arg("theS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_WireEdgeSet.hxx
	py::class_<BOPAlgo_WireEdgeSet, std::unique_ptr<BOPAlgo_WireEdgeSet, Deleter<BOPAlgo_WireEdgeSet>>> cls_BOPAlgo_WireEdgeSet(mod, "BOPAlgo_WireEdgeSet", "None");
	cls_BOPAlgo_WireEdgeSet.def(py::init<>());
	cls_BOPAlgo_WireEdgeSet.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_WireEdgeSet.def("Clear", (void (BOPAlgo_WireEdgeSet::*)()) &BOPAlgo_WireEdgeSet::Clear, "None");
	cls_BOPAlgo_WireEdgeSet.def("SetFace", (void (BOPAlgo_WireEdgeSet::*)(const TopoDS_Face &)) &BOPAlgo_WireEdgeSet::SetFace, "None", py::arg("aF"));
	cls_BOPAlgo_WireEdgeSet.def("Face", (const TopoDS_Face & (BOPAlgo_WireEdgeSet::*)() const ) &BOPAlgo_WireEdgeSet::Face, "None");
	cls_BOPAlgo_WireEdgeSet.def("AddStartElement", (void (BOPAlgo_WireEdgeSet::*)(const TopoDS_Shape &)) &BOPAlgo_WireEdgeSet::AddStartElement, "None", py::arg("sS"));
	cls_BOPAlgo_WireEdgeSet.def("StartElements", (const BOPCol_ListOfShape & (BOPAlgo_WireEdgeSet::*)() const ) &BOPAlgo_WireEdgeSet::StartElements, "None");
	cls_BOPAlgo_WireEdgeSet.def("AddShape", (void (BOPAlgo_WireEdgeSet::*)(const TopoDS_Shape &)) &BOPAlgo_WireEdgeSet::AddShape, "None", py::arg("sS"));
	cls_BOPAlgo_WireEdgeSet.def("Shapes", (const BOPCol_ListOfShape & (BOPAlgo_WireEdgeSet::*)() const ) &BOPAlgo_WireEdgeSet::Shapes, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_ShellSplitter.hxx
	py::class_<BOPAlgo_ShellSplitter, std::unique_ptr<BOPAlgo_ShellSplitter, Deleter<BOPAlgo_ShellSplitter>>, BOPAlgo_Algo> cls_BOPAlgo_ShellSplitter(mod, "BOPAlgo_ShellSplitter", "The class provides the splitting of the set of connected faces on separate loops");
	cls_BOPAlgo_ShellSplitter.def(py::init<>());
	cls_BOPAlgo_ShellSplitter.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_ShellSplitter.def("AddStartElement", (void (BOPAlgo_ShellSplitter::*)(const TopoDS_Shape &)) &BOPAlgo_ShellSplitter::AddStartElement, "adds a face <theS> to process", py::arg("theS"));
	cls_BOPAlgo_ShellSplitter.def("StartElements", (const BOPCol_ListOfShape & (BOPAlgo_ShellSplitter::*)() const ) &BOPAlgo_ShellSplitter::StartElements, "return the faces to process");
	cls_BOPAlgo_ShellSplitter.def("Perform", (void (BOPAlgo_ShellSplitter::*)()) &BOPAlgo_ShellSplitter::Perform, "performs the algorithm");
	cls_BOPAlgo_ShellSplitter.def("Shells", (const BOPCol_ListOfShape & (BOPAlgo_ShellSplitter::*)() const ) &BOPAlgo_ShellSplitter::Shells, "returns the loops");
	cls_BOPAlgo_ShellSplitter.def_static("SplitBlock_", (void (*)(BOPTools_ConnexityBlock &)) &BOPAlgo_ShellSplitter::SplitBlock, "None", py::arg("theCB"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Splitter.hxx
	py::class_<BOPAlgo_Splitter, std::unique_ptr<BOPAlgo_Splitter, Deleter<BOPAlgo_Splitter>>, BOPAlgo_Builder> cls_BOPAlgo_Splitter(mod, "BOPAlgo_Splitter", "The **Splitter algorithm** is the algorithm for splitting a group of arbitrary shapes by the other group of arbitrary shapes. The arguments of the operation are divided on two groups: *Objects* - shapes that will be split; *Tools* - shapes by which the *Objects* will be split. The result of the operation contains only the split parts of the shapes from the group of *Objects*. The split parts of the shapes from the group of *Tools* are excluded from the result. The shapes can be split by the other shapes from the same group (in case these shapes are interfering).");
	cls_BOPAlgo_Splitter.def(py::init<>());
	cls_BOPAlgo_Splitter.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_Splitter.def("Clear", (void (BOPAlgo_Splitter::*)()) &BOPAlgo_Splitter::Clear, "Clears internal fields and arguments");
	cls_BOPAlgo_Splitter.def("AddTool", (void (BOPAlgo_Splitter::*)(const TopoDS_Shape &)) &BOPAlgo_Splitter::AddTool, "Adds Tool argument of the operation", py::arg("theShape"));
	cls_BOPAlgo_Splitter.def("SetTools", (void (BOPAlgo_Splitter::*)(const BOPCol_ListOfShape &)) &BOPAlgo_Splitter::SetTools, "Adds the Tool arguments of the operation", py::arg("theShapes"));
	cls_BOPAlgo_Splitter.def("Tools", (const BOPCol_ListOfShape & (BOPAlgo_Splitter::*)() const ) &BOPAlgo_Splitter::Tools, "Returns the Tool arguments of the operation");
	cls_BOPAlgo_Splitter.def("Perform", (void (BOPAlgo_Splitter::*)()) &BOPAlgo_Splitter::Perform, "Performs the operation");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_Tools.hxx
	py::class_<BOPAlgo_Tools, std::unique_ptr<BOPAlgo_Tools, Deleter<BOPAlgo_Tools>>> cls_BOPAlgo_Tools(mod, "BOPAlgo_Tools", "None");
	cls_BOPAlgo_Tools.def(py::init<>());
	cls_BOPAlgo_Tools.def_static("FillMap_", (void (*)(const opencascade::handle<BOPDS_PaveBlock> &, const Standard_Integer, BOPDS_IndexedDataMapOfPaveBlockListOfInteger &, const BOPCol_BaseAllocator &)) &BOPAlgo_Tools::FillMap, "None", py::arg("thePB1"), py::arg("theF"), py::arg("theMILI"), py::arg("theAllocator"));
	// FIXME cls_BOPAlgo_Tools.def_static("PerformCommonBlocks_", (void (*)(BOPDS_IndexedDataMapOfPaveBlockListOfPaveBlock &, const BOPCol_BaseAllocator &, BOPDS_PDS &)) &BOPAlgo_Tools::PerformCommonBlocks, "None", py::arg("theMBlocks"), py::arg("theAllocator"), py::arg("theDS"));
	// FIXME cls_BOPAlgo_Tools.def_static("PerformCommonBlocks_", (void (*)(const BOPDS_IndexedDataMapOfPaveBlockListOfInteger &, const BOPCol_BaseAllocator &, BOPDS_PDS &)) &BOPAlgo_Tools::PerformCommonBlocks, "None", py::arg("theMBlocks"), py::arg("theAllocator"), py::arg("pDS"));
	cls_BOPAlgo_Tools.def_static("ComputeToleranceOfCB_", (Standard_Real (*)(const opencascade::handle<BOPDS_CommonBlock> &, const BOPDS_PDS, const opencascade::handle<IntTools_Context> &)) &BOPAlgo_Tools::ComputeToleranceOfCB, "None", py::arg("theCB"), py::arg("theDS"), py::arg("theContext"));
	cls_BOPAlgo_Tools.def_static("EdgesToWires_", [](const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Integer { return BOPAlgo_Tools::EdgesToWires(a0, a1); }, py::arg("theEdges"), py::arg("theWires"));
	cls_BOPAlgo_Tools.def_static("EdgesToWires_", [](const TopoDS_Shape & a0, TopoDS_Shape & a1, const Standard_Boolean a2) -> Standard_Integer { return BOPAlgo_Tools::EdgesToWires(a0, a1, a2); }, py::arg("theEdges"), py::arg("theWires"), py::arg("theShared"));
	cls_BOPAlgo_Tools.def_static("EdgesToWires_", (Standard_Integer (*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Boolean, const Standard_Real)) &BOPAlgo_Tools::EdgesToWires, "Creates planar wires from the given edges. The input edges are expected to be planar. And for the performance sake the method does not check if the edges are really planar. Thus, the result wires will also be not planar if the input edges are not planar. The edges may be not shared, but the resulting wires will be sharing the coinciding parts and intersecting parts. The output wires may be non-manifold and contain free and multi-connected vertices. Parameters: <theEdges> - input edges; <theWires> - output wires; <theShared> - boolean flag which defines whether the input edges are already shared or have to be intersected; <theAngTol> - the angular tolerance which will be used for distinguishing the planes in which the edges are located. Default value is 1.e-8 which is used for intersection of planes in IntTools_FaceFace. Method returns the following error statuses: 0 - in case of success (at least one wire has been built); 1 - in case there are no edges in the given shape; 2 - sharing of the edges has failed.", py::arg("theEdges"), py::arg("theWires"), py::arg("theShared"), py::arg("theAngTol"));
	cls_BOPAlgo_Tools.def_static("WiresToFaces_", [](const TopoDS_Shape & a0, TopoDS_Shape & a1) -> Standard_Boolean { return BOPAlgo_Tools::WiresToFaces(a0, a1); }, py::arg("theWires"), py::arg("theFaces"));
	cls_BOPAlgo_Tools.def_static("WiresToFaces_", (Standard_Boolean (*)(const TopoDS_Shape &, TopoDS_Shape &, const Standard_Real)) &BOPAlgo_Tools::WiresToFaces, "Creates planar faces from given planar wires. The method does not check if the wires are really planar. The input wires may be non-manifold but should be shared. The wires located in the same planes and included into other wires will create holes in the faces built from outer wires. The tolerance values of the input shapes may be modified during the operation due to projection of the edges on the planes for creation of 2D curves. Parameters: <theWires> - the given wires; <theFaces> - the output faces; <theAngTol> - the angular tolerance for distinguishing the planes in which the wires are located. Default value is 1.e-8 which is used for intersection of planes in IntTools_FaceFace. Method returns TRUE in case of success, i.e. at least one face has been built.", py::arg("theWires"), py::arg("theFaces"), py::arg("theAngTol"));
	cls_BOPAlgo_Tools.def_static("IntersectVertices_", (void (*)(const BOPCol_IndexedDataMapOfShapeReal &, const Standard_Boolean, const Standard_Real, BOPCol_ListOfListOfShape &)) &BOPAlgo_Tools::IntersectVertices, "Finds chains of intersecting vertices", py::arg("theVertices"), py::arg("theRunParallel"), py::arg("theFuzzyValue"), py::arg("theChains"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_WireSplitter.hxx
	py::class_<BOPAlgo_WireSplitter, std::unique_ptr<BOPAlgo_WireSplitter, Deleter<BOPAlgo_WireSplitter>>, BOPAlgo_Algo> cls_BOPAlgo_WireSplitter(mod, "BOPAlgo_WireSplitter", "The class is to build loops from the given set of edges.");
	cls_BOPAlgo_WireSplitter.def(py::init<>());
	cls_BOPAlgo_WireSplitter.def(py::init<const BOPCol_BaseAllocator &>(), py::arg("theAllocator"));
	cls_BOPAlgo_WireSplitter.def("SetWES", (void (BOPAlgo_WireSplitter::*)(const BOPAlgo_WireEdgeSet &)) &BOPAlgo_WireSplitter::SetWES, "None", py::arg("theWES"));
	cls_BOPAlgo_WireSplitter.def("WES", (BOPAlgo_WireEdgeSet & (BOPAlgo_WireSplitter::*)()) &BOPAlgo_WireSplitter::WES, "None");
	cls_BOPAlgo_WireSplitter.def("SetContext", (void (BOPAlgo_WireSplitter::*)(const opencascade::handle<IntTools_Context> &)) &BOPAlgo_WireSplitter::SetContext, "Sets the context for the algorithm", py::arg("theContext"));
	cls_BOPAlgo_WireSplitter.def("Context", (const opencascade::handle<IntTools_Context> & (BOPAlgo_WireSplitter::*)()) &BOPAlgo_WireSplitter::Context, "Returns the context");
	cls_BOPAlgo_WireSplitter.def("Perform", (void (BOPAlgo_WireSplitter::*)()) &BOPAlgo_WireSplitter::Perform, "None");
	cls_BOPAlgo_WireSplitter.def_static("MakeWire_", (void (*)(BOPCol_ListOfShape &, TopoDS_Wire &)) &BOPAlgo_WireSplitter::MakeWire, "None", py::arg("theLE"), py::arg("theW"));
	cls_BOPAlgo_WireSplitter.def_static("SplitBlock_", (void (*)(const TopoDS_Face &, BOPTools_ConnexityBlock &, const opencascade::handle<IntTools_Context> &)) &BOPAlgo_WireSplitter::SplitBlock, "None", py::arg("theF"), py::arg("theCB"), py::arg("theContext"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_WireSplitter.lxx
	py::class_<BOPAlgo_EdgeInfo, std::unique_ptr<BOPAlgo_EdgeInfo, Deleter<BOPAlgo_EdgeInfo>>> cls_BOPAlgo_EdgeInfo(mod, "BOPAlgo_EdgeInfo", "None");
	cls_BOPAlgo_EdgeInfo.def(py::init<>());
	cls_BOPAlgo_EdgeInfo.def("SetEdge", (void (BOPAlgo_EdgeInfo::*)(const TopoDS_Edge &)) &BOPAlgo_EdgeInfo::SetEdge, "None", py::arg("theE"));
	cls_BOPAlgo_EdgeInfo.def("Edge", (const TopoDS_Edge & (BOPAlgo_EdgeInfo::*)() const ) &BOPAlgo_EdgeInfo::Edge, "None");
	cls_BOPAlgo_EdgeInfo.def("SetPassed", (void (BOPAlgo_EdgeInfo::*)(const Standard_Boolean)) &BOPAlgo_EdgeInfo::SetPassed, "None", py::arg("theFlag"));
	cls_BOPAlgo_EdgeInfo.def("Passed", (Standard_Boolean (BOPAlgo_EdgeInfo::*)() const ) &BOPAlgo_EdgeInfo::Passed, "None");
	cls_BOPAlgo_EdgeInfo.def("SetInFlag", (void (BOPAlgo_EdgeInfo::*)(const Standard_Boolean)) &BOPAlgo_EdgeInfo::SetInFlag, "None", py::arg("theFlag"));
	cls_BOPAlgo_EdgeInfo.def("IsIn", (Standard_Boolean (BOPAlgo_EdgeInfo::*)() const ) &BOPAlgo_EdgeInfo::IsIn, "None");
	cls_BOPAlgo_EdgeInfo.def("SetAngle", (void (BOPAlgo_EdgeInfo::*)(const Standard_Real)) &BOPAlgo_EdgeInfo::SetAngle, "None", py::arg("theAngle"));
	cls_BOPAlgo_EdgeInfo.def("Angle", (Standard_Real (BOPAlgo_EdgeInfo::*)() const ) &BOPAlgo_EdgeInfo::Angle, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BOPAlgo_ListOfCheckResult, std::unique_ptr<BOPAlgo_ListOfCheckResult, Deleter<BOPAlgo_ListOfCheckResult>>, NCollection_BaseList> cls_BOPAlgo_ListOfCheckResult(mod, "BOPAlgo_ListOfCheckResult", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BOPAlgo_ListOfCheckResult.def(py::init<>());
	cls_BOPAlgo_ListOfCheckResult.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPAlgo_ListOfCheckResult.def(py::init([] (const BOPAlgo_ListOfCheckResult &other) {return new BOPAlgo_ListOfCheckResult(other);}), "Copy constructor", py::arg("other"));
	cls_BOPAlgo_ListOfCheckResult.def("begin", (BOPAlgo_ListOfCheckResult::iterator (BOPAlgo_ListOfCheckResult::*)() const ) &BOPAlgo_ListOfCheckResult::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BOPAlgo_ListOfCheckResult.def("end", (BOPAlgo_ListOfCheckResult::iterator (BOPAlgo_ListOfCheckResult::*)() const ) &BOPAlgo_ListOfCheckResult::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BOPAlgo_ListOfCheckResult.def("cbegin", (BOPAlgo_ListOfCheckResult::const_iterator (BOPAlgo_ListOfCheckResult::*)() const ) &BOPAlgo_ListOfCheckResult::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BOPAlgo_ListOfCheckResult.def("cend", (BOPAlgo_ListOfCheckResult::const_iterator (BOPAlgo_ListOfCheckResult::*)() const ) &BOPAlgo_ListOfCheckResult::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BOPAlgo_ListOfCheckResult.def("Size", (Standard_Integer (BOPAlgo_ListOfCheckResult::*)() const ) &BOPAlgo_ListOfCheckResult::Size, "Size - Number of items");
	cls_BOPAlgo_ListOfCheckResult.def("Assign", (BOPAlgo_ListOfCheckResult & (BOPAlgo_ListOfCheckResult::*)(const BOPAlgo_ListOfCheckResult &)) &BOPAlgo_ListOfCheckResult::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPAlgo_ListOfCheckResult.def("assign", (BOPAlgo_ListOfCheckResult & (BOPAlgo_ListOfCheckResult::*)(const BOPAlgo_ListOfCheckResult &)) &BOPAlgo_ListOfCheckResult::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BOPAlgo_ListOfCheckResult.def("Clear", [](BOPAlgo_ListOfCheckResult &self) -> void { return self.Clear(); });
	cls_BOPAlgo_ListOfCheckResult.def("Clear", (void (BOPAlgo_ListOfCheckResult::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPAlgo_ListOfCheckResult::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BOPAlgo_ListOfCheckResult.def("First", (const BOPAlgo_CheckResult & (BOPAlgo_ListOfCheckResult::*)() const ) &BOPAlgo_ListOfCheckResult::First, "First item");
	cls_BOPAlgo_ListOfCheckResult.def("First", (BOPAlgo_CheckResult & (BOPAlgo_ListOfCheckResult::*)()) &BOPAlgo_ListOfCheckResult::First, "First item (non-const)");
	cls_BOPAlgo_ListOfCheckResult.def("Last", (const BOPAlgo_CheckResult & (BOPAlgo_ListOfCheckResult::*)() const ) &BOPAlgo_ListOfCheckResult::Last, "Last item");
	cls_BOPAlgo_ListOfCheckResult.def("Last", (BOPAlgo_CheckResult & (BOPAlgo_ListOfCheckResult::*)()) &BOPAlgo_ListOfCheckResult::Last, "Last item (non-const)");
	cls_BOPAlgo_ListOfCheckResult.def("Append", (BOPAlgo_CheckResult & (BOPAlgo_ListOfCheckResult::*)(const BOPAlgo_CheckResult &)) &BOPAlgo_ListOfCheckResult::Append, "Append one item at the end", py::arg("theItem"));
	cls_BOPAlgo_ListOfCheckResult.def("Append", (void (BOPAlgo_ListOfCheckResult::*)(const BOPAlgo_CheckResult &, BOPAlgo_ListOfCheckResult::Iterator &)) &BOPAlgo_ListOfCheckResult::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BOPAlgo_ListOfCheckResult.def("Append", (void (BOPAlgo_ListOfCheckResult::*)(BOPAlgo_ListOfCheckResult &)) &BOPAlgo_ListOfCheckResult::Append, "Append another list at the end", py::arg("theOther"));
	cls_BOPAlgo_ListOfCheckResult.def("Prepend", (BOPAlgo_CheckResult & (BOPAlgo_ListOfCheckResult::*)(const BOPAlgo_CheckResult &)) &BOPAlgo_ListOfCheckResult::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BOPAlgo_ListOfCheckResult.def("Prepend", (void (BOPAlgo_ListOfCheckResult::*)(BOPAlgo_ListOfCheckResult &)) &BOPAlgo_ListOfCheckResult::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BOPAlgo_ListOfCheckResult.def("RemoveFirst", (void (BOPAlgo_ListOfCheckResult::*)()) &BOPAlgo_ListOfCheckResult::RemoveFirst, "RemoveFirst item");
	cls_BOPAlgo_ListOfCheckResult.def("Remove", (void (BOPAlgo_ListOfCheckResult::*)(BOPAlgo_ListOfCheckResult::Iterator &)) &BOPAlgo_ListOfCheckResult::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BOPAlgo_ListOfCheckResult.def("InsertBefore", (BOPAlgo_CheckResult & (BOPAlgo_ListOfCheckResult::*)(const BOPAlgo_CheckResult &, BOPAlgo_ListOfCheckResult::Iterator &)) &BOPAlgo_ListOfCheckResult::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BOPAlgo_ListOfCheckResult.def("InsertBefore", (void (BOPAlgo_ListOfCheckResult::*)(BOPAlgo_ListOfCheckResult &, BOPAlgo_ListOfCheckResult::Iterator &)) &BOPAlgo_ListOfCheckResult::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BOPAlgo_ListOfCheckResult.def("InsertAfter", (BOPAlgo_CheckResult & (BOPAlgo_ListOfCheckResult::*)(const BOPAlgo_CheckResult &, BOPAlgo_ListOfCheckResult::Iterator &)) &BOPAlgo_ListOfCheckResult::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BOPAlgo_ListOfCheckResult.def("InsertAfter", (void (BOPAlgo_ListOfCheckResult::*)(BOPAlgo_ListOfCheckResult &, BOPAlgo_ListOfCheckResult::Iterator &)) &BOPAlgo_ListOfCheckResult::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BOPAlgo_ListOfCheckResult.def("Reverse", (void (BOPAlgo_ListOfCheckResult::*)()) &BOPAlgo_ListOfCheckResult::Reverse, "Reverse the list");
	cls_BOPAlgo_ListOfCheckResult.def("__iter__", [](const BOPAlgo_ListOfCheckResult &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BOPAlgo_ListIteratorOfListOfCheckResult, std::unique_ptr<BOPAlgo_ListIteratorOfListOfCheckResult, Deleter<BOPAlgo_ListIteratorOfListOfCheckResult>>> cls_BOPAlgo_ListIteratorOfListOfCheckResult(mod, "BOPAlgo_ListIteratorOfListOfCheckResult", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BOPAlgo_ListIteratorOfListOfCheckResult.def(py::init<>());
	cls_BOPAlgo_ListIteratorOfListOfCheckResult.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BOPAlgo_ListIteratorOfListOfCheckResult.def("More", (Standard_Boolean (BOPAlgo_ListIteratorOfListOfCheckResult::*)() const ) &BOPAlgo_ListIteratorOfListOfCheckResult::More, "Check end");
	cls_BOPAlgo_ListIteratorOfListOfCheckResult.def("Next", (void (BOPAlgo_ListIteratorOfListOfCheckResult::*)()) &BOPAlgo_ListIteratorOfListOfCheckResult::Next, "Make step");
	cls_BOPAlgo_ListIteratorOfListOfCheckResult.def("Value", (const BOPAlgo_CheckResult & (BOPAlgo_ListIteratorOfListOfCheckResult::*)() const ) &BOPAlgo_ListIteratorOfListOfCheckResult::Value, "Constant Value access");
	cls_BOPAlgo_ListIteratorOfListOfCheckResult.def("Value", (BOPAlgo_CheckResult & (BOPAlgo_ListIteratorOfListOfCheckResult::*)()) &BOPAlgo_ListIteratorOfListOfCheckResult::Value, "Non-const Value access");
	cls_BOPAlgo_ListIteratorOfListOfCheckResult.def("ChangeValue", (BOPAlgo_CheckResult & (BOPAlgo_ListIteratorOfListOfCheckResult::*)() const ) &BOPAlgo_ListIteratorOfListOfCheckResult::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_PPaveFiller.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_PArgumentAnalyzer.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_PBOP.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_PBuilder.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_PSection.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPAlgo_PWireEdgeSet.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BOPAlgo_ListOfEdgeInfo, std::unique_ptr<BOPAlgo_ListOfEdgeInfo, Deleter<BOPAlgo_ListOfEdgeInfo>>, NCollection_BaseList> cls_BOPAlgo_ListOfEdgeInfo(mod, "BOPAlgo_ListOfEdgeInfo", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BOPAlgo_ListOfEdgeInfo.def(py::init<>());
	cls_BOPAlgo_ListOfEdgeInfo.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPAlgo_ListOfEdgeInfo.def(py::init([] (const BOPAlgo_ListOfEdgeInfo &other) {return new BOPAlgo_ListOfEdgeInfo(other);}), "Copy constructor", py::arg("other"));
	cls_BOPAlgo_ListOfEdgeInfo.def("begin", (BOPAlgo_ListOfEdgeInfo::iterator (BOPAlgo_ListOfEdgeInfo::*)() const ) &BOPAlgo_ListOfEdgeInfo::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BOPAlgo_ListOfEdgeInfo.def("end", (BOPAlgo_ListOfEdgeInfo::iterator (BOPAlgo_ListOfEdgeInfo::*)() const ) &BOPAlgo_ListOfEdgeInfo::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BOPAlgo_ListOfEdgeInfo.def("cbegin", (BOPAlgo_ListOfEdgeInfo::const_iterator (BOPAlgo_ListOfEdgeInfo::*)() const ) &BOPAlgo_ListOfEdgeInfo::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BOPAlgo_ListOfEdgeInfo.def("cend", (BOPAlgo_ListOfEdgeInfo::const_iterator (BOPAlgo_ListOfEdgeInfo::*)() const ) &BOPAlgo_ListOfEdgeInfo::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BOPAlgo_ListOfEdgeInfo.def("Size", (Standard_Integer (BOPAlgo_ListOfEdgeInfo::*)() const ) &BOPAlgo_ListOfEdgeInfo::Size, "Size - Number of items");
	cls_BOPAlgo_ListOfEdgeInfo.def("Assign", (BOPAlgo_ListOfEdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)(const BOPAlgo_ListOfEdgeInfo &)) &BOPAlgo_ListOfEdgeInfo::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPAlgo_ListOfEdgeInfo.def("assign", (BOPAlgo_ListOfEdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)(const BOPAlgo_ListOfEdgeInfo &)) &BOPAlgo_ListOfEdgeInfo::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BOPAlgo_ListOfEdgeInfo.def("Clear", [](BOPAlgo_ListOfEdgeInfo &self) -> void { return self.Clear(); });
	cls_BOPAlgo_ListOfEdgeInfo.def("Clear", (void (BOPAlgo_ListOfEdgeInfo::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPAlgo_ListOfEdgeInfo::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BOPAlgo_ListOfEdgeInfo.def("First", (const BOPAlgo_EdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)() const ) &BOPAlgo_ListOfEdgeInfo::First, "First item");
	cls_BOPAlgo_ListOfEdgeInfo.def("First", (BOPAlgo_EdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)()) &BOPAlgo_ListOfEdgeInfo::First, "First item (non-const)");
	cls_BOPAlgo_ListOfEdgeInfo.def("Last", (const BOPAlgo_EdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)() const ) &BOPAlgo_ListOfEdgeInfo::Last, "Last item");
	cls_BOPAlgo_ListOfEdgeInfo.def("Last", (BOPAlgo_EdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)()) &BOPAlgo_ListOfEdgeInfo::Last, "Last item (non-const)");
	cls_BOPAlgo_ListOfEdgeInfo.def("Append", (BOPAlgo_EdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)(const BOPAlgo_EdgeInfo &)) &BOPAlgo_ListOfEdgeInfo::Append, "Append one item at the end", py::arg("theItem"));
	cls_BOPAlgo_ListOfEdgeInfo.def("Append", (void (BOPAlgo_ListOfEdgeInfo::*)(const BOPAlgo_EdgeInfo &, BOPAlgo_ListOfEdgeInfo::Iterator &)) &BOPAlgo_ListOfEdgeInfo::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BOPAlgo_ListOfEdgeInfo.def("Append", (void (BOPAlgo_ListOfEdgeInfo::*)(BOPAlgo_ListOfEdgeInfo &)) &BOPAlgo_ListOfEdgeInfo::Append, "Append another list at the end", py::arg("theOther"));
	cls_BOPAlgo_ListOfEdgeInfo.def("Prepend", (BOPAlgo_EdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)(const BOPAlgo_EdgeInfo &)) &BOPAlgo_ListOfEdgeInfo::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BOPAlgo_ListOfEdgeInfo.def("Prepend", (void (BOPAlgo_ListOfEdgeInfo::*)(BOPAlgo_ListOfEdgeInfo &)) &BOPAlgo_ListOfEdgeInfo::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BOPAlgo_ListOfEdgeInfo.def("RemoveFirst", (void (BOPAlgo_ListOfEdgeInfo::*)()) &BOPAlgo_ListOfEdgeInfo::RemoveFirst, "RemoveFirst item");
	cls_BOPAlgo_ListOfEdgeInfo.def("Remove", (void (BOPAlgo_ListOfEdgeInfo::*)(BOPAlgo_ListOfEdgeInfo::Iterator &)) &BOPAlgo_ListOfEdgeInfo::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BOPAlgo_ListOfEdgeInfo.def("InsertBefore", (BOPAlgo_EdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)(const BOPAlgo_EdgeInfo &, BOPAlgo_ListOfEdgeInfo::Iterator &)) &BOPAlgo_ListOfEdgeInfo::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BOPAlgo_ListOfEdgeInfo.def("InsertBefore", (void (BOPAlgo_ListOfEdgeInfo::*)(BOPAlgo_ListOfEdgeInfo &, BOPAlgo_ListOfEdgeInfo::Iterator &)) &BOPAlgo_ListOfEdgeInfo::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BOPAlgo_ListOfEdgeInfo.def("InsertAfter", (BOPAlgo_EdgeInfo & (BOPAlgo_ListOfEdgeInfo::*)(const BOPAlgo_EdgeInfo &, BOPAlgo_ListOfEdgeInfo::Iterator &)) &BOPAlgo_ListOfEdgeInfo::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BOPAlgo_ListOfEdgeInfo.def("InsertAfter", (void (BOPAlgo_ListOfEdgeInfo::*)(BOPAlgo_ListOfEdgeInfo &, BOPAlgo_ListOfEdgeInfo::Iterator &)) &BOPAlgo_ListOfEdgeInfo::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BOPAlgo_ListOfEdgeInfo.def("Reverse", (void (BOPAlgo_ListOfEdgeInfo::*)()) &BOPAlgo_ListOfEdgeInfo::Reverse, "Reverse the list");
	cls_BOPAlgo_ListOfEdgeInfo.def("__iter__", [](const BOPAlgo_ListOfEdgeInfo &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BOPAlgo_ListIteratorOfListOfEdgeInfo, std::unique_ptr<BOPAlgo_ListIteratorOfListOfEdgeInfo, Deleter<BOPAlgo_ListIteratorOfListOfEdgeInfo>>> cls_BOPAlgo_ListIteratorOfListOfEdgeInfo(mod, "BOPAlgo_ListIteratorOfListOfEdgeInfo", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BOPAlgo_ListIteratorOfListOfEdgeInfo.def(py::init<>());
	cls_BOPAlgo_ListIteratorOfListOfEdgeInfo.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BOPAlgo_ListIteratorOfListOfEdgeInfo.def("More", (Standard_Boolean (BOPAlgo_ListIteratorOfListOfEdgeInfo::*)() const ) &BOPAlgo_ListIteratorOfListOfEdgeInfo::More, "Check end");
	cls_BOPAlgo_ListIteratorOfListOfEdgeInfo.def("Next", (void (BOPAlgo_ListIteratorOfListOfEdgeInfo::*)()) &BOPAlgo_ListIteratorOfListOfEdgeInfo::Next, "Make step");
	cls_BOPAlgo_ListIteratorOfListOfEdgeInfo.def("Value", (const BOPAlgo_EdgeInfo & (BOPAlgo_ListIteratorOfListOfEdgeInfo::*)() const ) &BOPAlgo_ListIteratorOfListOfEdgeInfo::Value, "Constant Value access");
	cls_BOPAlgo_ListIteratorOfListOfEdgeInfo.def("Value", (BOPAlgo_EdgeInfo & (BOPAlgo_ListIteratorOfListOfEdgeInfo::*)()) &BOPAlgo_ListIteratorOfListOfEdgeInfo::Value, "Non-const Value access");
	cls_BOPAlgo_ListIteratorOfListOfEdgeInfo.def("ChangeValue", (BOPAlgo_EdgeInfo & (BOPAlgo_ListIteratorOfListOfEdgeInfo::*)() const ) &BOPAlgo_ListIteratorOfListOfEdgeInfo::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo, std::unique_ptr<BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo, Deleter<BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo>>, NCollection_BaseMap> cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo(mod, "BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def(py::init<>());
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def(py::init([] (const BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo &other) {return new BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo(other);}), "Copy constructor", py::arg("other"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("begin", (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::iterator (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)() const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("end", (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::iterator (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)() const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("cbegin", (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::const_iterator (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)() const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("cend", (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::const_iterator (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)() const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Exchange", (void (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo &)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Assign", (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo & (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo &)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("assign", (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo & (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo &)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("ReSize", (void (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Integer)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::ReSize, "ReSize", py::arg("N"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Add", (Standard_Integer (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const TopoDS_Shape &, const BOPAlgo_ListOfEdgeInfo &)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Contains", (Standard_Boolean (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const TopoDS_Shape &) const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Contains, "Contains", py::arg("theKey1"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Substitute", (void (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Integer, const TopoDS_Shape &, const BOPAlgo_ListOfEdgeInfo &)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Swap", (void (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Integer, const Standard_Integer)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("RemoveLast", (void (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)()) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::RemoveLast, "RemoveLast");
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("RemoveFromIndex", (void (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Integer)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("RemoveKey", (void (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const TopoDS_Shape &)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("FindKey", (const TopoDS_Shape & (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Integer) const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::FindKey, "FindKey", py::arg("theKey2"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("FindFromIndex", (const BOPAlgo_ListOfEdgeInfo & (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Integer) const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("__call__", (const BOPAlgo_ListOfEdgeInfo & (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Integer) const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("ChangeFromIndex", (BOPAlgo_ListOfEdgeInfo & (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Integer)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("__call__", (BOPAlgo_ListOfEdgeInfo & (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Integer)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("FindIndex", (Standard_Integer (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const TopoDS_Shape &) const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("FindFromKey", (const BOPAlgo_ListOfEdgeInfo & (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const TopoDS_Shape &) const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("ChangeFromKey", (BOPAlgo_ListOfEdgeInfo & (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const TopoDS_Shape &)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Seek", (const BOPAlgo_ListOfEdgeInfo * (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const TopoDS_Shape &) const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("ChangeSeek", (BOPAlgo_ListOfEdgeInfo * (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const TopoDS_Shape &)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("FindFromKey", (Standard_Boolean (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const TopoDS_Shape &, BOPAlgo_ListOfEdgeInfo &) const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Clear", [](BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo &self) -> void { return self.Clear(); });
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Clear", (void (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const Standard_Boolean)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Clear", (void (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("Size", (Standard_Integer (BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::*)() const ) &BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo::Size, "Size");
	cls_BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo.def("__iter__", [](const BOPAlgo_IndexedDataMapOfShapeListOfEdgeInfo &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
