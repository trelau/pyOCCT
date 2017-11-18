#include <pyOCCT_Common.hpp>

#include <TopoDSToStep_BuilderError.hxx>
#include <TopoDSToStep_MakeFaceError.hxx>
#include <TopoDSToStep_MakeWireError.hxx>
#include <TopoDSToStep_MakeEdgeError.hxx>
#include <TopoDSToStep_MakeVertexError.hxx>
#include <MoniTool_DataMapOfShapeTransient.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDSToStep_Tool.hxx>
#include <TopoDSToStep_Root.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TopoDS_Solid.hxx>
#include <StepShape_ManifoldSolidBrep.hxx>
#include <TopoDSToStep_MakeManifoldSolidBrep.hxx>
#include <StepShape_BrepWithVoids.hxx>
#include <TopoDSToStep_MakeBrepWithVoids.hxx>
#include <StepShape_FacetedBrep.hxx>
#include <TopoDSToStep_MakeFacetedBrep.hxx>
#include <StepShape_FacetedBrepAndBrepWithVoids.hxx>
#include <TopoDSToStep_MakeFacetedBrepAndBrepWithVoids.hxx>
#include <StepShape_ShellBasedSurfaceModel.hxx>
#include <TopoDSToStep_MakeShellBasedSurfaceModel.hxx>
#include <StepShape_GeometricCurveSet.hxx>
#include <TopoDSToStep_MakeGeometricCurveSet.hxx>
#include <TopoDSToStep_Builder.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TopoDSToStep_WireframeBuilder.hxx>
#include <TopoDSToStep_FacetedError.hxx>
#include <TopoDSToStep_FacetedTool.hxx>
#include <TopoDSToStep_MakeStepFace.hxx>
#include <TopoDSToStep_MakeStepWire.hxx>
#include <TopoDSToStep_MakeStepEdge.hxx>
#include <TopoDSToStep_MakeStepVertex.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Transient.hxx>
#include <TopoDSToStep.hxx>

PYBIND11_MODULE(TopoDSToStep, mod) {

	// IMPORT
	py::module::import("OCCT.MoniTool");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.StepShape");
	py::module::import("OCCT.Transfer");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_BuilderError.hxx
	py::enum_<TopoDSToStep_BuilderError>(mod, "TopoDSToStep_BuilderError", "None")
		.value("TopoDSToStep_BuilderDone", TopoDSToStep_BuilderError::TopoDSToStep_BuilderDone)
		.value("TopoDSToStep_NoFaceMapped", TopoDSToStep_BuilderError::TopoDSToStep_NoFaceMapped)
		.value("TopoDSToStep_BuilderOther", TopoDSToStep_BuilderError::TopoDSToStep_BuilderOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeFaceError.hxx
	py::enum_<TopoDSToStep_MakeFaceError>(mod, "TopoDSToStep_MakeFaceError", "None")
		.value("TopoDSToStep_FaceDone", TopoDSToStep_MakeFaceError::TopoDSToStep_FaceDone)
		.value("TopoDSToStep_InfiniteFace", TopoDSToStep_MakeFaceError::TopoDSToStep_InfiniteFace)
		.value("TopoDSToStep_NonManifoldFace", TopoDSToStep_MakeFaceError::TopoDSToStep_NonManifoldFace)
		.value("TopoDSToStep_NoWireMapped", TopoDSToStep_MakeFaceError::TopoDSToStep_NoWireMapped)
		.value("TopoDSToStep_FaceOther", TopoDSToStep_MakeFaceError::TopoDSToStep_FaceOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeWireError.hxx
	py::enum_<TopoDSToStep_MakeWireError>(mod, "TopoDSToStep_MakeWireError", "None")
		.value("TopoDSToStep_WireDone", TopoDSToStep_MakeWireError::TopoDSToStep_WireDone)
		.value("TopoDSToStep_NonManifoldWire", TopoDSToStep_MakeWireError::TopoDSToStep_NonManifoldWire)
		.value("TopoDSToStep_WireOther", TopoDSToStep_MakeWireError::TopoDSToStep_WireOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeEdgeError.hxx
	py::enum_<TopoDSToStep_MakeEdgeError>(mod, "TopoDSToStep_MakeEdgeError", "None")
		.value("TopoDSToStep_EdgeDone", TopoDSToStep_MakeEdgeError::TopoDSToStep_EdgeDone)
		.value("TopoDSToStep_NonManifoldEdge", TopoDSToStep_MakeEdgeError::TopoDSToStep_NonManifoldEdge)
		.value("TopoDSToStep_EdgeOther", TopoDSToStep_MakeEdgeError::TopoDSToStep_EdgeOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeVertexError.hxx
	py::enum_<TopoDSToStep_MakeVertexError>(mod, "TopoDSToStep_MakeVertexError", "None")
		.value("TopoDSToStep_VertexDone", TopoDSToStep_MakeVertexError::TopoDSToStep_VertexDone)
		.value("TopoDSToStep_VertexOther", TopoDSToStep_MakeVertexError::TopoDSToStep_VertexOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_FacetedError.hxx
	py::enum_<TopoDSToStep_FacetedError>(mod, "TopoDSToStep_FacetedError", "None")
		.value("TopoDSToStep_FacetedDone", TopoDSToStep_FacetedError::TopoDSToStep_FacetedDone)
		.value("TopoDSToStep_SurfaceNotPlane", TopoDSToStep_FacetedError::TopoDSToStep_SurfaceNotPlane)
		.value("TopoDSToStep_PCurveNotLinear", TopoDSToStep_FacetedError::TopoDSToStep_PCurveNotLinear)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_Tool.hxx
	py::class_<TopoDSToStep_Tool, std::unique_ptr<TopoDSToStep_Tool, Deleter<TopoDSToStep_Tool>>> cls_TopoDSToStep_Tool(mod, "TopoDSToStep_Tool", "This Tool Class provides Information to build a ProSTEP Shape model from a Cas.Cad BRep.");
	cls_TopoDSToStep_Tool.def(py::init<>());
	cls_TopoDSToStep_Tool.def(py::init<const MoniTool_DataMapOfShapeTransient &, const Standard_Boolean>(), py::arg("M"), py::arg("FacetedContext"));
	cls_TopoDSToStep_Tool.def("Init", (void (TopoDSToStep_Tool::*)(const MoniTool_DataMapOfShapeTransient &, const Standard_Boolean)) &TopoDSToStep_Tool::Init, "None", py::arg("M"), py::arg("FacetedContext"));
	cls_TopoDSToStep_Tool.def("IsBound", (Standard_Boolean (TopoDSToStep_Tool::*)(const TopoDS_Shape &)) &TopoDSToStep_Tool::IsBound, "None", py::arg("S"));
	cls_TopoDSToStep_Tool.def("Bind", (void (TopoDSToStep_Tool::*)(const TopoDS_Shape &, const opencascade::handle<StepShape_TopologicalRepresentationItem> &)) &TopoDSToStep_Tool::Bind, "None", py::arg("S"), py::arg("T"));
	cls_TopoDSToStep_Tool.def("Find", (opencascade::handle<StepShape_TopologicalRepresentationItem> (TopoDSToStep_Tool::*)(const TopoDS_Shape &)) &TopoDSToStep_Tool::Find, "None", py::arg("S"));
	cls_TopoDSToStep_Tool.def("Faceted", (Standard_Boolean (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::Faceted, "None");
	cls_TopoDSToStep_Tool.def("SetCurrentShell", (void (TopoDSToStep_Tool::*)(const TopoDS_Shell &)) &TopoDSToStep_Tool::SetCurrentShell, "None", py::arg("S"));
	cls_TopoDSToStep_Tool.def("CurrentShell", (const TopoDS_Shell & (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::CurrentShell, "None");
	cls_TopoDSToStep_Tool.def("SetCurrentFace", (void (TopoDSToStep_Tool::*)(const TopoDS_Face &)) &TopoDSToStep_Tool::SetCurrentFace, "None", py::arg("F"));
	cls_TopoDSToStep_Tool.def("CurrentFace", (const TopoDS_Face & (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::CurrentFace, "None");
	cls_TopoDSToStep_Tool.def("SetCurrentWire", (void (TopoDSToStep_Tool::*)(const TopoDS_Wire &)) &TopoDSToStep_Tool::SetCurrentWire, "None", py::arg("W"));
	cls_TopoDSToStep_Tool.def("CurrentWire", (const TopoDS_Wire & (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::CurrentWire, "None");
	cls_TopoDSToStep_Tool.def("SetCurrentEdge", (void (TopoDSToStep_Tool::*)(const TopoDS_Edge &)) &TopoDSToStep_Tool::SetCurrentEdge, "None", py::arg("E"));
	cls_TopoDSToStep_Tool.def("CurrentEdge", (const TopoDS_Edge & (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::CurrentEdge, "None");
	cls_TopoDSToStep_Tool.def("SetCurrentVertex", (void (TopoDSToStep_Tool::*)(const TopoDS_Vertex &)) &TopoDSToStep_Tool::SetCurrentVertex, "None", py::arg("V"));
	cls_TopoDSToStep_Tool.def("CurrentVertex", (const TopoDS_Vertex & (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::CurrentVertex, "None");
	cls_TopoDSToStep_Tool.def("Lowest3DTolerance", (Standard_Real (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::Lowest3DTolerance, "None");
	cls_TopoDSToStep_Tool.def("SetSurfaceReversed", (void (TopoDSToStep_Tool::*)(const Standard_Boolean)) &TopoDSToStep_Tool::SetSurfaceReversed, "None", py::arg("B"));
	cls_TopoDSToStep_Tool.def("SurfaceReversed", (Standard_Boolean (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::SurfaceReversed, "None");
	cls_TopoDSToStep_Tool.def("Map", (const MoniTool_DataMapOfShapeTransient & (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::Map, "None");
	cls_TopoDSToStep_Tool.def("PCurveMode", (Standard_Integer (TopoDSToStep_Tool::*)() const ) &TopoDSToStep_Tool::PCurveMode, "Returns mode for writing pcurves (initialized by parameter write.surfacecurve.mode)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_Root.hxx
	py::class_<TopoDSToStep_Root, std::unique_ptr<TopoDSToStep_Root, Deleter<TopoDSToStep_Root>>> cls_TopoDSToStep_Root(mod, "TopoDSToStep_Root", "This class implements the common services for all classes of TopoDSToStep which report error.");
	cls_TopoDSToStep_Root.def("Tolerance", (Standard_Real & (TopoDSToStep_Root::*)()) &TopoDSToStep_Root::Tolerance, "Returns (modifiable) the tolerance to be used for writing If not set, starts at 0.0001");
	cls_TopoDSToStep_Root.def("IsDone", (Standard_Boolean (TopoDSToStep_Root::*)() const ) &TopoDSToStep_Root::IsDone, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeManifoldSolidBrep.hxx
	py::class_<TopoDSToStep_MakeManifoldSolidBrep, std::unique_ptr<TopoDSToStep_MakeManifoldSolidBrep, Deleter<TopoDSToStep_MakeManifoldSolidBrep>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeManifoldSolidBrep(mod, "TopoDSToStep_MakeManifoldSolidBrep", "This class implements the mapping between classes Shell or Solid from TopoDS and ManifoldSolidBrep from StepShape. All the topology and geometry comprised into the shell or the solid are taken into account and translated.");
	cls_TopoDSToStep_MakeManifoldSolidBrep.def(py::init<const TopoDS_Shell &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));
	cls_TopoDSToStep_MakeManifoldSolidBrep.def(py::init<const TopoDS_Solid &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));
	cls_TopoDSToStep_MakeManifoldSolidBrep.def("Value", (const opencascade::handle<StepShape_ManifoldSolidBrep> & (TopoDSToStep_MakeManifoldSolidBrep::*)() const ) &TopoDSToStep_MakeManifoldSolidBrep::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeBrepWithVoids.hxx
	py::class_<TopoDSToStep_MakeBrepWithVoids, std::unique_ptr<TopoDSToStep_MakeBrepWithVoids, Deleter<TopoDSToStep_MakeBrepWithVoids>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeBrepWithVoids(mod, "TopoDSToStep_MakeBrepWithVoids", "This class implements the mapping between classes Solid from TopoDS and BrepWithVoids from StepShape. All the topology and geometry comprised into the shell or the solid are taken into account and translated.");
	cls_TopoDSToStep_MakeBrepWithVoids.def(py::init<const TopoDS_Solid &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));
	cls_TopoDSToStep_MakeBrepWithVoids.def("Value", (const opencascade::handle<StepShape_BrepWithVoids> & (TopoDSToStep_MakeBrepWithVoids::*)() const ) &TopoDSToStep_MakeBrepWithVoids::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeFacetedBrep.hxx
	py::class_<TopoDSToStep_MakeFacetedBrep, std::unique_ptr<TopoDSToStep_MakeFacetedBrep, Deleter<TopoDSToStep_MakeFacetedBrep>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeFacetedBrep(mod, "TopoDSToStep_MakeFacetedBrep", "This class implements the mapping between classes Shell or Solid from TopoDS and FacetedBrep from StepShape. All the topology and geometry comprised into the shell or the solid are taken into account and translated.");
	cls_TopoDSToStep_MakeFacetedBrep.def(py::init<const TopoDS_Shell &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));
	cls_TopoDSToStep_MakeFacetedBrep.def(py::init<const TopoDS_Solid &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));
	cls_TopoDSToStep_MakeFacetedBrep.def("Value", (const opencascade::handle<StepShape_FacetedBrep> & (TopoDSToStep_MakeFacetedBrep::*)() const ) &TopoDSToStep_MakeFacetedBrep::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeFacetedBrepAndBrepWithVoids.hxx
	py::class_<TopoDSToStep_MakeFacetedBrepAndBrepWithVoids, std::unique_ptr<TopoDSToStep_MakeFacetedBrepAndBrepWithVoids, Deleter<TopoDSToStep_MakeFacetedBrepAndBrepWithVoids>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeFacetedBrepAndBrepWithVoids(mod, "TopoDSToStep_MakeFacetedBrepAndBrepWithVoids", "This class implements the mapping between classes Solid from TopoDS and FacetedBrepAndBrepWithVoids from StepShape. All the topology and geometry comprised into the shell or the solid are taken into account and translated.");
	cls_TopoDSToStep_MakeFacetedBrepAndBrepWithVoids.def(py::init<const TopoDS_Solid &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));
	cls_TopoDSToStep_MakeFacetedBrepAndBrepWithVoids.def("Value", (const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> & (TopoDSToStep_MakeFacetedBrepAndBrepWithVoids::*)() const ) &TopoDSToStep_MakeFacetedBrepAndBrepWithVoids::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeShellBasedSurfaceModel.hxx
	py::class_<TopoDSToStep_MakeShellBasedSurfaceModel, std::unique_ptr<TopoDSToStep_MakeShellBasedSurfaceModel, Deleter<TopoDSToStep_MakeShellBasedSurfaceModel>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeShellBasedSurfaceModel(mod, "TopoDSToStep_MakeShellBasedSurfaceModel", "This class implements the mapping between classes Face, Shell or Solid from TopoDS and ShellBasedSurfaceModel from StepShape. All the topology and geometry comprised into the shape are taken into account and translated.");
	cls_TopoDSToStep_MakeShellBasedSurfaceModel.def(py::init<const TopoDS_Face &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("F"), py::arg("FP"));
	cls_TopoDSToStep_MakeShellBasedSurfaceModel.def(py::init<const TopoDS_Shell &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));
	cls_TopoDSToStep_MakeShellBasedSurfaceModel.def(py::init<const TopoDS_Solid &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("FP"));
	cls_TopoDSToStep_MakeShellBasedSurfaceModel.def("Value", (const opencascade::handle<StepShape_ShellBasedSurfaceModel> & (TopoDSToStep_MakeShellBasedSurfaceModel::*)() const ) &TopoDSToStep_MakeShellBasedSurfaceModel::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeGeometricCurveSet.hxx
	py::class_<TopoDSToStep_MakeGeometricCurveSet, std::unique_ptr<TopoDSToStep_MakeGeometricCurveSet, Deleter<TopoDSToStep_MakeGeometricCurveSet>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeGeometricCurveSet(mod, "TopoDSToStep_MakeGeometricCurveSet", "This class implements the mapping between a Shape from TopoDS and a GeometricCurveSet from StepShape in order to create a GeometricallyBoundedWireframeRepresentation.");
	cls_TopoDSToStep_MakeGeometricCurveSet.def(py::init<const TopoDS_Shape &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("SH"), py::arg("FP"));
	cls_TopoDSToStep_MakeGeometricCurveSet.def("Value", (const opencascade::handle<StepShape_GeometricCurveSet> & (TopoDSToStep_MakeGeometricCurveSet::*)() const ) &TopoDSToStep_MakeGeometricCurveSet::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_Builder.hxx
	py::class_<TopoDSToStep_Builder, std::unique_ptr<TopoDSToStep_Builder, Deleter<TopoDSToStep_Builder>>, TopoDSToStep_Root> cls_TopoDSToStep_Builder(mod, "TopoDSToStep_Builder", "This builder Class provides services to build a ProSTEP Shape model from a Cas.Cad BRep.");
	cls_TopoDSToStep_Builder.def(py::init<>());
	cls_TopoDSToStep_Builder.def(py::init<const TopoDS_Shape &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_Builder.def("Init", (void (TopoDSToStep_Builder::*)(const TopoDS_Shape &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_Builder::Init, "None", py::arg("S"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_Builder.def("Error", (TopoDSToStep_BuilderError (TopoDSToStep_Builder::*)() const ) &TopoDSToStep_Builder::Error, "None");
	cls_TopoDSToStep_Builder.def("Value", (const opencascade::handle<StepShape_TopologicalRepresentationItem> & (TopoDSToStep_Builder::*)() const ) &TopoDSToStep_Builder::Value, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_WireframeBuilder.hxx
	py::class_<TopoDSToStep_WireframeBuilder, std::unique_ptr<TopoDSToStep_WireframeBuilder, Deleter<TopoDSToStep_WireframeBuilder>>, TopoDSToStep_Root> cls_TopoDSToStep_WireframeBuilder(mod, "TopoDSToStep_WireframeBuilder", "This builder Class provides services to build a ProSTEP Wireframemodel from a Cas.Cad BRep.");
	cls_TopoDSToStep_WireframeBuilder.def(py::init<>());
	cls_TopoDSToStep_WireframeBuilder.def(py::init<const TopoDS_Shape &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("S"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_WireframeBuilder.def("Init", (void (TopoDSToStep_WireframeBuilder::*)(const TopoDS_Shape &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_WireframeBuilder::Init, "None", py::arg("S"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_WireframeBuilder.def("Error", (TopoDSToStep_BuilderError (TopoDSToStep_WireframeBuilder::*)() const ) &TopoDSToStep_WireframeBuilder::Error, "None");
	cls_TopoDSToStep_WireframeBuilder.def("Value", (const opencascade::handle<TColStd_HSequenceOfTransient> & (TopoDSToStep_WireframeBuilder::*)() const ) &TopoDSToStep_WireframeBuilder::Value, "None");
	cls_TopoDSToStep_WireframeBuilder.def("GetTrimmedCurveFromEdge", (Standard_Boolean (TopoDSToStep_WireframeBuilder::*)(const TopoDS_Edge &, const TopoDS_Face &, MoniTool_DataMapOfShapeTransient &, opencascade::handle<TColStd_HSequenceOfTransient> &) const ) &TopoDSToStep_WireframeBuilder::GetTrimmedCurveFromEdge, "Extraction of Trimmed Curves from TopoDS_Edge for the Creation of a GeometricallyBoundedWireframeRepresentation", py::arg("E"), py::arg("F"), py::arg("M"), py::arg("L"));
	cls_TopoDSToStep_WireframeBuilder.def("GetTrimmedCurveFromFace", (Standard_Boolean (TopoDSToStep_WireframeBuilder::*)(const TopoDS_Face &, MoniTool_DataMapOfShapeTransient &, opencascade::handle<TColStd_HSequenceOfTransient> &) const ) &TopoDSToStep_WireframeBuilder::GetTrimmedCurveFromFace, "Extraction of Trimmed Curves from TopoDS_Face for the Creation of a GeometricallyBoundedWireframeRepresentation", py::arg("F"), py::arg("M"), py::arg("L"));
	cls_TopoDSToStep_WireframeBuilder.def("GetTrimmedCurveFromShape", (Standard_Boolean (TopoDSToStep_WireframeBuilder::*)(const TopoDS_Shape &, MoniTool_DataMapOfShapeTransient &, opencascade::handle<TColStd_HSequenceOfTransient> &) const ) &TopoDSToStep_WireframeBuilder::GetTrimmedCurveFromShape, "Extraction of Trimmed Curves from any TopoDS_Shape for the Creation of a GeometricallyBoundedWireframeRepresentation", py::arg("S"), py::arg("M"), py::arg("L"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_FacetedTool.hxx
	py::class_<TopoDSToStep_FacetedTool, std::unique_ptr<TopoDSToStep_FacetedTool, Deleter<TopoDSToStep_FacetedTool>>> cls_TopoDSToStep_FacetedTool(mod, "TopoDSToStep_FacetedTool", "This Tool Class provides Information about Faceted Shapes to be mapped to STEP.");
	cls_TopoDSToStep_FacetedTool.def(py::init<>());
	cls_TopoDSToStep_FacetedTool.def_static("CheckTopoDSShape_", (TopoDSToStep_FacetedError (*)(const TopoDS_Shape &)) &TopoDSToStep_FacetedTool::CheckTopoDSShape, "None", py::arg("SH"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeStepFace.hxx
	py::class_<TopoDSToStep_MakeStepFace, std::unique_ptr<TopoDSToStep_MakeStepFace, Deleter<TopoDSToStep_MakeStepFace>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeStepFace(mod, "TopoDSToStep_MakeStepFace", "This class implements the mapping between classes Face from TopoDS and TopologicalRepresentationItem from StepShape.");
	cls_TopoDSToStep_MakeStepFace.def(py::init<>());
	cls_TopoDSToStep_MakeStepFace.def(py::init<const TopoDS_Face &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("F"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_MakeStepFace.def("Init", (void (TopoDSToStep_MakeStepFace::*)(const TopoDS_Face &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_MakeStepFace::Init, "None", py::arg("F"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_MakeStepFace.def("Value", (const opencascade::handle<StepShape_TopologicalRepresentationItem> & (TopoDSToStep_MakeStepFace::*)() const ) &TopoDSToStep_MakeStepFace::Value, "None");
	cls_TopoDSToStep_MakeStepFace.def("Error", (TopoDSToStep_MakeFaceError (TopoDSToStep_MakeStepFace::*)() const ) &TopoDSToStep_MakeStepFace::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeStepWire.hxx
	py::class_<TopoDSToStep_MakeStepWire, std::unique_ptr<TopoDSToStep_MakeStepWire, Deleter<TopoDSToStep_MakeStepWire>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeStepWire(mod, "TopoDSToStep_MakeStepWire", "This class implements the mapping between classes Wire from TopoDS and TopologicalRepresentationItem from StepShape.");
	cls_TopoDSToStep_MakeStepWire.def(py::init<>());
	cls_TopoDSToStep_MakeStepWire.def(py::init<const TopoDS_Wire &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("W"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_MakeStepWire.def("Init", (void (TopoDSToStep_MakeStepWire::*)(const TopoDS_Wire &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_MakeStepWire::Init, "None", py::arg("W"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_MakeStepWire.def("Value", (const opencascade::handle<StepShape_TopologicalRepresentationItem> & (TopoDSToStep_MakeStepWire::*)() const ) &TopoDSToStep_MakeStepWire::Value, "None");
	cls_TopoDSToStep_MakeStepWire.def("Error", (TopoDSToStep_MakeWireError (TopoDSToStep_MakeStepWire::*)() const ) &TopoDSToStep_MakeStepWire::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeStepEdge.hxx
	py::class_<TopoDSToStep_MakeStepEdge, std::unique_ptr<TopoDSToStep_MakeStepEdge, Deleter<TopoDSToStep_MakeStepEdge>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeStepEdge(mod, "TopoDSToStep_MakeStepEdge", "This class implements the mapping between classes Edge from TopoDS and TopologicalRepresentationItem from StepShape.");
	cls_TopoDSToStep_MakeStepEdge.def(py::init<>());
	cls_TopoDSToStep_MakeStepEdge.def(py::init<const TopoDS_Edge &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("E"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_MakeStepEdge.def("Init", (void (TopoDSToStep_MakeStepEdge::*)(const TopoDS_Edge &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_MakeStepEdge::Init, "None", py::arg("E"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_MakeStepEdge.def("Value", (const opencascade::handle<StepShape_TopologicalRepresentationItem> & (TopoDSToStep_MakeStepEdge::*)() const ) &TopoDSToStep_MakeStepEdge::Value, "None");
	cls_TopoDSToStep_MakeStepEdge.def("Error", (TopoDSToStep_MakeEdgeError (TopoDSToStep_MakeStepEdge::*)() const ) &TopoDSToStep_MakeStepEdge::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep_MakeStepVertex.hxx
	py::class_<TopoDSToStep_MakeStepVertex, std::unique_ptr<TopoDSToStep_MakeStepVertex, Deleter<TopoDSToStep_MakeStepVertex>>, TopoDSToStep_Root> cls_TopoDSToStep_MakeStepVertex(mod, "TopoDSToStep_MakeStepVertex", "This class implements the mapping between classes Vertex from TopoDS and TopologicalRepresentationItem from StepShape.");
	cls_TopoDSToStep_MakeStepVertex.def(py::init<>());
	cls_TopoDSToStep_MakeStepVertex.def(py::init<const TopoDS_Vertex &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("V"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_MakeStepVertex.def("Init", (void (TopoDSToStep_MakeStepVertex::*)(const TopoDS_Vertex &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_MakeStepVertex::Init, "None", py::arg("V"), py::arg("T"), py::arg("FP"));
	cls_TopoDSToStep_MakeStepVertex.def("Value", (const opencascade::handle<StepShape_TopologicalRepresentationItem> & (TopoDSToStep_MakeStepVertex::*)() const ) &TopoDSToStep_MakeStepVertex::Value, "None");
	cls_TopoDSToStep_MakeStepVertex.def("Error", (TopoDSToStep_MakeVertexError (TopoDSToStep_MakeStepVertex::*)() const ) &TopoDSToStep_MakeStepVertex::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopoDSToStep.hxx
	py::class_<TopoDSToStep, std::unique_ptr<TopoDSToStep, Deleter<TopoDSToStep>>> cls_TopoDSToStep(mod, "TopoDSToStep", "This package implements the mapping between CAS.CAD Shape representation and AP214 Shape Representation. The target schema is pms_c4 (a subset of AP214)");
	cls_TopoDSToStep.def(py::init<>());
	cls_TopoDSToStep.def_static("DecodeBuilderError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_BuilderError)) &TopoDSToStep::DecodeBuilderError, "None", py::arg("E"));
	cls_TopoDSToStep.def_static("DecodeFaceError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_MakeFaceError)) &TopoDSToStep::DecodeFaceError, "None", py::arg("E"));
	cls_TopoDSToStep.def_static("DecodeWireError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_MakeWireError)) &TopoDSToStep::DecodeWireError, "None", py::arg("E"));
	cls_TopoDSToStep.def_static("DecodeEdgeError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_MakeEdgeError)) &TopoDSToStep::DecodeEdgeError, "None", py::arg("E"));
	cls_TopoDSToStep.def_static("DecodeVertexError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_MakeVertexError)) &TopoDSToStep::DecodeVertexError, "Returns a new shape without undirect surfaces.", py::arg("E"));
	cls_TopoDSToStep.def_static("AddResult_", (void (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &, const opencascade::handle<Standard_Transient> &)) &TopoDSToStep::AddResult, "Adds an entity into the list of results (binders) for shape stored in FinderProcess", py::arg("FP"), py::arg("Shape"), py::arg("entity"));
	cls_TopoDSToStep.def_static("AddResult_", (void (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDSToStep_Tool &)) &TopoDSToStep::AddResult, "Adds all entities recorded in Tool into the map of results (binders) stored in FinderProcess", py::arg("FP"), py::arg("Tool"));


}
