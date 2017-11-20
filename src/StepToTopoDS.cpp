#include <pyOCCT_Common.hpp>

#include <NCollection_BaseMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <StepToTopoDS_DataMapOfRI.hxx>
#include <StepToTopoDS_DataMapOfRINames.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopoDS_Shape.hxx>
#include <StepToTopoDS_NMTool.hxx>
#include <StepToTopoDS_BuilderError.hxx>
#include <StepToTopoDS_TranslateShellError.hxx>
#include <StepToTopoDS_TranslateFaceError.hxx>
#include <StepToTopoDS_TranslateEdgeError.hxx>
#include <StepToTopoDS_TranslateVertexError.hxx>
#include <StepToTopoDS_TranslateVertexLoopError.hxx>
#include <StepToTopoDS_TranslatePolyLoopError.hxx>
#include <StepToTopoDS_GeometricToolError.hxx>
#include <StepToTopoDS_Root.hxx>
#include <StepShape_ConnectedFaceSet.hxx>
#include <StepToTopoDS_Tool.hxx>
#include <StepToTopoDS_TranslateShell.hxx>
#include <StepShape_FaceSurface.hxx>
#include <StepToTopoDS_TranslateFace.hxx>
#include <StepShape_FaceBound.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Surface.hxx>
#include <StepGeom_Surface.hxx>
#include <StepToTopoDS_TranslateEdgeLoopError.hxx>
#include <StepToTopoDS_TranslateEdgeLoop.hxx>
#include <StepShape_Edge.hxx>
#include <StepGeom_Curve.hxx>
#include <StepShape_EdgeCurve.hxx>
#include <StepShape_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <Geom2d_Curve.hxx>
#include <StepGeom_Pcurve.hxx>
#include <StepToTopoDS_TranslateEdge.hxx>
#include <StepToTopoDS_TranslateVertex.hxx>
#include <StepShape_PolyLoop.hxx>
#include <StepToTopoDS_TranslatePolyLoop.hxx>
#include <StepShape_VertexLoop.hxx>
#include <StepToTopoDS_TranslateVertexLoop.hxx>
#include <StepGeom_CompositeCurve.hxx>
#include <Transfer_TransientProcess.hxx>
#include <TopoDS_Wire.hxx>
#include <StepToTopoDS_TranslateCompositeCurve.hxx>
#include <StepGeom_CurveBoundedSurface.hxx>
#include <StepToTopoDS_TranslateCurveBoundedSurface.hxx>
#include <StepShape_ManifoldSolidBrep.hxx>
#include <StepShape_BrepWithVoids.hxx>
#include <StepShape_FacetedBrep.hxx>
#include <StepShape_FacetedBrepAndBrepWithVoids.hxx>
#include <StepShape_ShellBasedSurfaceModel.hxx>
#include <StepShape_GeometricSet.hxx>
#include <StepShape_EdgeBasedWireframeModel.hxx>
#include <StepShape_FaceBasedSurfaceModel.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <StepToTopoDS_Builder.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <StepGeom_CartesianTransformationOperator3d.hxx>
#include <gp_Trsf.hxx>
#include <StepRepr_MappedItem.hxx>
#include <StepToTopoDS_MakeTransformed.hxx>
#include <StepGeom_SurfaceCurve.hxx>
#include <StepShape_EdgeLoop.hxx>
#include <Geom_Curve.hxx>
#include <StepToTopoDS_GeometricTool.hxx>
#include <StepToTopoDS_DataMapOfTRI.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <StepToTopoDS_PointPair.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepToTopoDS_CartesianPointHasher.hxx>
#include <StepToTopoDS_PointPairHasher.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepToTopoDS.hxx>
#include <StepToTopoDS_PointEdgeMap.hxx>
#include <StepToTopoDS_PointVertexMap.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(StepToTopoDS, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepRepr");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.StepShape");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.StepGeom");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.Transfer");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_BuilderError.hxx
	py::enum_<StepToTopoDS_BuilderError>(mod, "StepToTopoDS_BuilderError", "None")
		.value("StepToTopoDS_BuilderDone", StepToTopoDS_BuilderError::StepToTopoDS_BuilderDone)
		.value("StepToTopoDS_BuilderOther", StepToTopoDS_BuilderError::StepToTopoDS_BuilderOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateShellError.hxx
	py::enum_<StepToTopoDS_TranslateShellError>(mod, "StepToTopoDS_TranslateShellError", "None")
		.value("StepToTopoDS_TranslateShellDone", StepToTopoDS_TranslateShellError::StepToTopoDS_TranslateShellDone)
		.value("StepToTopoDS_TranslateShellOther", StepToTopoDS_TranslateShellError::StepToTopoDS_TranslateShellOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateFaceError.hxx
	py::enum_<StepToTopoDS_TranslateFaceError>(mod, "StepToTopoDS_TranslateFaceError", "None")
		.value("StepToTopoDS_TranslateFaceDone", StepToTopoDS_TranslateFaceError::StepToTopoDS_TranslateFaceDone)
		.value("StepToTopoDS_TranslateFaceOther", StepToTopoDS_TranslateFaceError::StepToTopoDS_TranslateFaceOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateEdgeError.hxx
	py::enum_<StepToTopoDS_TranslateEdgeError>(mod, "StepToTopoDS_TranslateEdgeError", "None")
		.value("StepToTopoDS_TranslateEdgeDone", StepToTopoDS_TranslateEdgeError::StepToTopoDS_TranslateEdgeDone)
		.value("StepToTopoDS_TranslateEdgeOther", StepToTopoDS_TranslateEdgeError::StepToTopoDS_TranslateEdgeOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateVertexError.hxx
	py::enum_<StepToTopoDS_TranslateVertexError>(mod, "StepToTopoDS_TranslateVertexError", "None")
		.value("StepToTopoDS_TranslateVertexDone", StepToTopoDS_TranslateVertexError::StepToTopoDS_TranslateVertexDone)
		.value("StepToTopoDS_TranslateVertexOther", StepToTopoDS_TranslateVertexError::StepToTopoDS_TranslateVertexOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateVertexLoopError.hxx
	py::enum_<StepToTopoDS_TranslateVertexLoopError>(mod, "StepToTopoDS_TranslateVertexLoopError", "None")
		.value("StepToTopoDS_TranslateVertexLoopDone", StepToTopoDS_TranslateVertexLoopError::StepToTopoDS_TranslateVertexLoopDone)
		.value("StepToTopoDS_TranslateVertexLoopOther", StepToTopoDS_TranslateVertexLoopError::StepToTopoDS_TranslateVertexLoopOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslatePolyLoopError.hxx
	py::enum_<StepToTopoDS_TranslatePolyLoopError>(mod, "StepToTopoDS_TranslatePolyLoopError", "None")
		.value("StepToTopoDS_TranslatePolyLoopDone", StepToTopoDS_TranslatePolyLoopError::StepToTopoDS_TranslatePolyLoopDone)
		.value("StepToTopoDS_TranslatePolyLoopOther", StepToTopoDS_TranslatePolyLoopError::StepToTopoDS_TranslatePolyLoopOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_GeometricToolError.hxx
	py::enum_<StepToTopoDS_GeometricToolError>(mod, "StepToTopoDS_GeometricToolError", "None")
		.value("StepToTopoDS_GeometricToolDone", StepToTopoDS_GeometricToolError::StepToTopoDS_GeometricToolDone)
		.value("StepToTopoDS_GeometricToolIsDegenerated", StepToTopoDS_GeometricToolError::StepToTopoDS_GeometricToolIsDegenerated)
		.value("StepToTopoDS_GeometricToolHasNoPCurve", StepToTopoDS_GeometricToolError::StepToTopoDS_GeometricToolHasNoPCurve)
		.value("StepToTopoDS_GeometricToolWrong3dParameters", StepToTopoDS_GeometricToolError::StepToTopoDS_GeometricToolWrong3dParameters)
		.value("StepToTopoDS_GeometricToolNoProjectiOnCurve", StepToTopoDS_GeometricToolError::StepToTopoDS_GeometricToolNoProjectiOnCurve)
		.value("StepToTopoDS_GeometricToolOther", StepToTopoDS_GeometricToolError::StepToTopoDS_GeometricToolOther)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateEdgeLoopError.hxx
	py::enum_<StepToTopoDS_TranslateEdgeLoopError>(mod, "StepToTopoDS_TranslateEdgeLoopError", "None")
		.value("StepToTopoDS_TranslateEdgeLoopDone", StepToTopoDS_TranslateEdgeLoopError::StepToTopoDS_TranslateEdgeLoopDone)
		.value("StepToTopoDS_TranslateEdgeLoopOther", StepToTopoDS_TranslateEdgeLoopError::StepToTopoDS_TranslateEdgeLoopOther)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_NMTool.hxx
	py::class_<StepToTopoDS_NMTool, std::unique_ptr<StepToTopoDS_NMTool, Deleter<StepToTopoDS_NMTool>>> cls_StepToTopoDS_NMTool(mod, "StepToTopoDS_NMTool", "Provides data to process non-manifold topology when reading from STEP.");
	cls_StepToTopoDS_NMTool.def(py::init<>());
	cls_StepToTopoDS_NMTool.def(py::init<const StepToTopoDS_DataMapOfRI &, const StepToTopoDS_DataMapOfRINames &>(), py::arg("MapOfRI"), py::arg("MapOfRINames"));
	cls_StepToTopoDS_NMTool.def("Init", (void (StepToTopoDS_NMTool::*)(const StepToTopoDS_DataMapOfRI &, const StepToTopoDS_DataMapOfRINames &)) &StepToTopoDS_NMTool::Init, "None", py::arg("MapOfRI"), py::arg("MapOfRINames"));
	cls_StepToTopoDS_NMTool.def("SetActive", (void (StepToTopoDS_NMTool::*)(const Standard_Boolean)) &StepToTopoDS_NMTool::SetActive, "None", py::arg("isActive"));
	cls_StepToTopoDS_NMTool.def("IsActive", (Standard_Boolean (StepToTopoDS_NMTool::*)()) &StepToTopoDS_NMTool::IsActive, "None");
	cls_StepToTopoDS_NMTool.def("CleanUp", (void (StepToTopoDS_NMTool::*)()) &StepToTopoDS_NMTool::CleanUp, "None");
	cls_StepToTopoDS_NMTool.def("IsBound", (Standard_Boolean (StepToTopoDS_NMTool::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepToTopoDS_NMTool::IsBound, "None", py::arg("RI"));
	cls_StepToTopoDS_NMTool.def("IsBound", (Standard_Boolean (StepToTopoDS_NMTool::*)(const TCollection_AsciiString &)) &StepToTopoDS_NMTool::IsBound, "None", py::arg("RIName"));
	cls_StepToTopoDS_NMTool.def("Bind", (void (StepToTopoDS_NMTool::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const TopoDS_Shape &)) &StepToTopoDS_NMTool::Bind, "None", py::arg("RI"), py::arg("S"));
	cls_StepToTopoDS_NMTool.def("Bind", (void (StepToTopoDS_NMTool::*)(const TCollection_AsciiString &, const TopoDS_Shape &)) &StepToTopoDS_NMTool::Bind, "None", py::arg("RIName"), py::arg("S"));
	cls_StepToTopoDS_NMTool.def("Find", (const TopoDS_Shape & (StepToTopoDS_NMTool::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepToTopoDS_NMTool::Find, "None", py::arg("RI"));
	cls_StepToTopoDS_NMTool.def("Find", (const TopoDS_Shape & (StepToTopoDS_NMTool::*)(const TCollection_AsciiString &)) &StepToTopoDS_NMTool::Find, "None", py::arg("RIName"));
	cls_StepToTopoDS_NMTool.def("RegisterNMEdge", (void (StepToTopoDS_NMTool::*)(const TopoDS_Shape &)) &StepToTopoDS_NMTool::RegisterNMEdge, "None", py::arg("Edge"));
	cls_StepToTopoDS_NMTool.def("IsSuspectedAsClosing", (Standard_Boolean (StepToTopoDS_NMTool::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &StepToTopoDS_NMTool::IsSuspectedAsClosing, "None", py::arg("BaseShell"), py::arg("SuspectedShell"));
	cls_StepToTopoDS_NMTool.def("IsPureNMShell", (Standard_Boolean (StepToTopoDS_NMTool::*)(const TopoDS_Shape &)) &StepToTopoDS_NMTool::IsPureNMShell, "None", py::arg("Shell"));
	cls_StepToTopoDS_NMTool.def("SetIDEASCase", (void (StepToTopoDS_NMTool::*)(const Standard_Boolean)) &StepToTopoDS_NMTool::SetIDEASCase, "None", py::arg("IDEASCase"));
	cls_StepToTopoDS_NMTool.def("IsIDEASCase", (Standard_Boolean (StepToTopoDS_NMTool::*)()) &StepToTopoDS_NMTool::IsIDEASCase, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_Root.hxx
	py::class_<StepToTopoDS_Root, std::unique_ptr<StepToTopoDS_Root, Deleter<StepToTopoDS_Root>>> cls_StepToTopoDS_Root(mod, "StepToTopoDS_Root", "This class implements the common services for all classes of StepToTopoDS which report error and sets and returns precision.");
	cls_StepToTopoDS_Root.def("IsDone", (Standard_Boolean (StepToTopoDS_Root::*)() const ) &StepToTopoDS_Root::IsDone, "None");
	cls_StepToTopoDS_Root.def("Precision", (Standard_Real (StepToTopoDS_Root::*)() const ) &StepToTopoDS_Root::Precision, "Returns the value of 'MyPrecision'");
	cls_StepToTopoDS_Root.def("SetPrecision", (void (StepToTopoDS_Root::*)(const Standard_Real)) &StepToTopoDS_Root::SetPrecision, "Sets the value of 'MyPrecision'", py::arg("preci"));
	cls_StepToTopoDS_Root.def("MaxTol", (Standard_Real (StepToTopoDS_Root::*)() const ) &StepToTopoDS_Root::MaxTol, "Returns the value of 'MaxTol'");
	cls_StepToTopoDS_Root.def("SetMaxTol", (void (StepToTopoDS_Root::*)(const Standard_Real)) &StepToTopoDS_Root::SetMaxTol, "Sets the value of MaxTol", py::arg("maxpreci"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateShell.hxx
	py::class_<StepToTopoDS_TranslateShell, std::unique_ptr<StepToTopoDS_TranslateShell, Deleter<StepToTopoDS_TranslateShell>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateShell(mod, "StepToTopoDS_TranslateShell", "None");
	cls_StepToTopoDS_TranslateShell.def(py::init<>());
	cls_StepToTopoDS_TranslateShell.def(py::init<const opencascade::handle<StepShape_ConnectedFaceSet> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("CFS"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateShell.def("Init", (void (StepToTopoDS_TranslateShell::*)(const opencascade::handle<StepShape_ConnectedFaceSet> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateShell::Init, "None", py::arg("CFS"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateShell.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateShell::*)() const ) &StepToTopoDS_TranslateShell::Value, "None");
	cls_StepToTopoDS_TranslateShell.def("Error", (StepToTopoDS_TranslateShellError (StepToTopoDS_TranslateShell::*)() const ) &StepToTopoDS_TranslateShell::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateFace.hxx
	py::class_<StepToTopoDS_TranslateFace, std::unique_ptr<StepToTopoDS_TranslateFace, Deleter<StepToTopoDS_TranslateFace>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateFace(mod, "StepToTopoDS_TranslateFace", "None");
	cls_StepToTopoDS_TranslateFace.def(py::init<>());
	cls_StepToTopoDS_TranslateFace.def(py::init<const opencascade::handle<StepShape_FaceSurface> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("FS"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateFace.def("Init", (void (StepToTopoDS_TranslateFace::*)(const opencascade::handle<StepShape_FaceSurface> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateFace::Init, "None", py::arg("FS"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateFace.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateFace::*)() const ) &StepToTopoDS_TranslateFace::Value, "None");
	cls_StepToTopoDS_TranslateFace.def("Error", (StepToTopoDS_TranslateFaceError (StepToTopoDS_TranslateFace::*)() const ) &StepToTopoDS_TranslateFace::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateEdgeLoop.hxx
	py::class_<StepToTopoDS_TranslateEdgeLoop, std::unique_ptr<StepToTopoDS_TranslateEdgeLoop, Deleter<StepToTopoDS_TranslateEdgeLoop>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateEdgeLoop(mod, "StepToTopoDS_TranslateEdgeLoop", "None");
	cls_StepToTopoDS_TranslateEdgeLoop.def(py::init<>());
	cls_StepToTopoDS_TranslateEdgeLoop.def(py::init<const opencascade::handle<StepShape_FaceBound> &, const TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("FB"), py::arg("F"), py::arg("S"), py::arg("SS"), py::arg("ss"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateEdgeLoop.def("Init", (void (StepToTopoDS_TranslateEdgeLoop::*)(const opencascade::handle<StepShape_FaceBound> &, const TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Boolean, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateEdgeLoop::Init, "None", py::arg("FB"), py::arg("F"), py::arg("S"), py::arg("SS"), py::arg("ss"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateEdgeLoop.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateEdgeLoop::*)() const ) &StepToTopoDS_TranslateEdgeLoop::Value, "None");
	cls_StepToTopoDS_TranslateEdgeLoop.def("Error", (StepToTopoDS_TranslateEdgeLoopError (StepToTopoDS_TranslateEdgeLoop::*)() const ) &StepToTopoDS_TranslateEdgeLoop::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateEdge.hxx
	py::class_<StepToTopoDS_TranslateEdge, std::unique_ptr<StepToTopoDS_TranslateEdge, Deleter<StepToTopoDS_TranslateEdge>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateEdge(mod, "StepToTopoDS_TranslateEdge", "None");
	cls_StepToTopoDS_TranslateEdge.def(py::init<>());
	cls_StepToTopoDS_TranslateEdge.def(py::init<const opencascade::handle<StepShape_Edge> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("E"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateEdge.def("Init", (void (StepToTopoDS_TranslateEdge::*)(const opencascade::handle<StepShape_Edge> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateEdge::Init, "None", py::arg("E"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateEdge.def("MakeFromCurve3D", (void (StepToTopoDS_TranslateEdge::*)(const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepShape_EdgeCurve> &, const opencascade::handle<StepShape_Vertex> &, const Standard_Real, TopoDS_Edge &, TopoDS_Vertex &, TopoDS_Vertex &, StepToTopoDS_Tool &)) &StepToTopoDS_TranslateEdge::MakeFromCurve3D, "Warning! C3D is assumed to be a Curve 3D ... other cases to checked before calling this", py::arg("C3D"), py::arg("EC"), py::arg("Vend"), py::arg("preci"), py::arg("E"), py::arg("V1"), py::arg("V2"), py::arg("T"));
	cls_StepToTopoDS_TranslateEdge.def("MakePCurve", (opencascade::handle<Geom2d_Curve> (StepToTopoDS_TranslateEdge::*)(const opencascade::handle<StepGeom_Pcurve> &, const opencascade::handle<Geom_Surface> &) const ) &StepToTopoDS_TranslateEdge::MakePCurve, "None", py::arg("PCU"), py::arg("ConvSurf"));
	cls_StepToTopoDS_TranslateEdge.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateEdge::*)() const ) &StepToTopoDS_TranslateEdge::Value, "None");
	cls_StepToTopoDS_TranslateEdge.def("Error", (StepToTopoDS_TranslateEdgeError (StepToTopoDS_TranslateEdge::*)() const ) &StepToTopoDS_TranslateEdge::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateVertex.hxx
	py::class_<StepToTopoDS_TranslateVertex, std::unique_ptr<StepToTopoDS_TranslateVertex, Deleter<StepToTopoDS_TranslateVertex>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateVertex(mod, "StepToTopoDS_TranslateVertex", "None");
	cls_StepToTopoDS_TranslateVertex.def(py::init<>());
	cls_StepToTopoDS_TranslateVertex.def(py::init<const opencascade::handle<StepShape_Vertex> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("V"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateVertex.def("Init", (void (StepToTopoDS_TranslateVertex::*)(const opencascade::handle<StepShape_Vertex> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateVertex::Init, "None", py::arg("V"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateVertex.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateVertex::*)() const ) &StepToTopoDS_TranslateVertex::Value, "None");
	cls_StepToTopoDS_TranslateVertex.def("Error", (StepToTopoDS_TranslateVertexError (StepToTopoDS_TranslateVertex::*)() const ) &StepToTopoDS_TranslateVertex::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslatePolyLoop.hxx
	py::class_<StepToTopoDS_TranslatePolyLoop, std::unique_ptr<StepToTopoDS_TranslatePolyLoop, Deleter<StepToTopoDS_TranslatePolyLoop>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslatePolyLoop(mod, "StepToTopoDS_TranslatePolyLoop", "None");
	cls_StepToTopoDS_TranslatePolyLoop.def(py::init<>());
	cls_StepToTopoDS_TranslatePolyLoop.def(py::init<const opencascade::handle<StepShape_PolyLoop> &, StepToTopoDS_Tool &, const opencascade::handle<Geom_Surface> &, const TopoDS_Face &>(), py::arg("PL"), py::arg("T"), py::arg("S"), py::arg("F"));
	cls_StepToTopoDS_TranslatePolyLoop.def("Init", (void (StepToTopoDS_TranslatePolyLoop::*)(const opencascade::handle<StepShape_PolyLoop> &, StepToTopoDS_Tool &, const opencascade::handle<Geom_Surface> &, const TopoDS_Face &)) &StepToTopoDS_TranslatePolyLoop::Init, "None", py::arg("PL"), py::arg("T"), py::arg("S"), py::arg("F"));
	cls_StepToTopoDS_TranslatePolyLoop.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslatePolyLoop::*)() const ) &StepToTopoDS_TranslatePolyLoop::Value, "None");
	cls_StepToTopoDS_TranslatePolyLoop.def("Error", (StepToTopoDS_TranslatePolyLoopError (StepToTopoDS_TranslatePolyLoop::*)() const ) &StepToTopoDS_TranslatePolyLoop::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateVertexLoop.hxx
	py::class_<StepToTopoDS_TranslateVertexLoop, std::unique_ptr<StepToTopoDS_TranslateVertexLoop, Deleter<StepToTopoDS_TranslateVertexLoop>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateVertexLoop(mod, "StepToTopoDS_TranslateVertexLoop", "None");
	cls_StepToTopoDS_TranslateVertexLoop.def(py::init<>());
	cls_StepToTopoDS_TranslateVertexLoop.def(py::init<const opencascade::handle<StepShape_VertexLoop> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &>(), py::arg("VL"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateVertexLoop.def("Init", (void (StepToTopoDS_TranslateVertexLoop::*)(const opencascade::handle<StepShape_VertexLoop> &, StepToTopoDS_Tool &, StepToTopoDS_NMTool &)) &StepToTopoDS_TranslateVertexLoop::Init, "None", py::arg("VL"), py::arg("T"), py::arg("NMTool"));
	cls_StepToTopoDS_TranslateVertexLoop.def("Value", (const TopoDS_Shape & (StepToTopoDS_TranslateVertexLoop::*)() const ) &StepToTopoDS_TranslateVertexLoop::Value, "None");
	cls_StepToTopoDS_TranslateVertexLoop.def("Error", (StepToTopoDS_TranslateVertexLoopError (StepToTopoDS_TranslateVertexLoop::*)() const ) &StepToTopoDS_TranslateVertexLoop::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateCompositeCurve.hxx
	py::class_<StepToTopoDS_TranslateCompositeCurve, std::unique_ptr<StepToTopoDS_TranslateCompositeCurve, Deleter<StepToTopoDS_TranslateCompositeCurve>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateCompositeCurve(mod, "StepToTopoDS_TranslateCompositeCurve", "Translate STEP entity composite_curve to TopoDS_Wire If surface is given, the curve is assumed to lie on that surface and in case if any segment of it is a curve_on_surface, the pcurve for that segment will be taken. Note: a segment of composite_curve may be itself composite_curve. Only one-level protection against cyclic references is implemented.");
	cls_StepToTopoDS_TranslateCompositeCurve.def(py::init<>());
	cls_StepToTopoDS_TranslateCompositeCurve.def(py::init<const opencascade::handle<StepGeom_CompositeCurve> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("CC"), py::arg("TP"));
	cls_StepToTopoDS_TranslateCompositeCurve.def(py::init<const opencascade::handle<StepGeom_CompositeCurve> &, const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<Geom_Surface> &>(), py::arg("CC"), py::arg("TP"), py::arg("S"), py::arg("Surf"));
	cls_StepToTopoDS_TranslateCompositeCurve.def("Init", (Standard_Boolean (StepToTopoDS_TranslateCompositeCurve::*)(const opencascade::handle<StepGeom_CompositeCurve> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_TranslateCompositeCurve::Init, "Translates standalone composite_curve", py::arg("CC"), py::arg("TP"));
	cls_StepToTopoDS_TranslateCompositeCurve.def("Init", (Standard_Boolean (StepToTopoDS_TranslateCompositeCurve::*)(const opencascade::handle<StepGeom_CompositeCurve> &, const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<Geom_Surface> &)) &StepToTopoDS_TranslateCompositeCurve::Init, "Translates composite_curve lying on surface", py::arg("CC"), py::arg("TP"), py::arg("S"), py::arg("Surf"));
	cls_StepToTopoDS_TranslateCompositeCurve.def("Value", (const TopoDS_Wire & (StepToTopoDS_TranslateCompositeCurve::*)() const ) &StepToTopoDS_TranslateCompositeCurve::Value, "Returns result of last translation or null wire if failed.");
	cls_StepToTopoDS_TranslateCompositeCurve.def("IsInfiniteSegment", (Standard_Boolean (StepToTopoDS_TranslateCompositeCurve::*)() const ) &StepToTopoDS_TranslateCompositeCurve::IsInfiniteSegment, "Returns True if composite_curve contains a segment with infinite parameters.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_TranslateCurveBoundedSurface.hxx
	py::class_<StepToTopoDS_TranslateCurveBoundedSurface, std::unique_ptr<StepToTopoDS_TranslateCurveBoundedSurface, Deleter<StepToTopoDS_TranslateCurveBoundedSurface>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateCurveBoundedSurface(mod, "StepToTopoDS_TranslateCurveBoundedSurface", "Translate curve_bounded_surface into TopoDS_Face");
	cls_StepToTopoDS_TranslateCurveBoundedSurface.def(py::init<>());
	cls_StepToTopoDS_TranslateCurveBoundedSurface.def(py::init<const opencascade::handle<StepGeom_CurveBoundedSurface> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("CBS"), py::arg("TP"));
	cls_StepToTopoDS_TranslateCurveBoundedSurface.def("Init", (Standard_Boolean (StepToTopoDS_TranslateCurveBoundedSurface::*)(const opencascade::handle<StepGeom_CurveBoundedSurface> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_TranslateCurveBoundedSurface::Init, "Translate surface", py::arg("CBS"), py::arg("TP"));
	cls_StepToTopoDS_TranslateCurveBoundedSurface.def("Value", (const TopoDS_Face & (StepToTopoDS_TranslateCurveBoundedSurface::*)() const ) &StepToTopoDS_TranslateCurveBoundedSurface::Value, "Returns result of last translation or null wire if failed.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_Builder.hxx
	py::class_<StepToTopoDS_Builder, std::unique_ptr<StepToTopoDS_Builder, Deleter<StepToTopoDS_Builder>>, StepToTopoDS_Root> cls_StepToTopoDS_Builder(mod, "StepToTopoDS_Builder", "None");
	cls_StepToTopoDS_Builder.def(py::init<>());
	cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_ManifoldSolidBrep> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_BrepWithVoids> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_FacetedBrep> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_ShellBasedSurfaceModel> &, const opencascade::handle<Transfer_TransientProcess> &, StepToTopoDS_NMTool &>(), py::arg("S"), py::arg("TP"), py::arg("NMTool"));
	cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_GeometricSet> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_ManifoldSolidBrep> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_BrepWithVoids> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_FacetedBrep> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_ShellBasedSurfaceModel> &, const opencascade::handle<Transfer_TransientProcess> &, StepToTopoDS_NMTool &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"), py::arg("NMTool"));
	cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_EdgeBasedWireframeModel> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_FaceBasedSurfaceModel> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def("Init", [](StepToTopoDS_Builder &self, const opencascade::handle<StepShape_GeometricSet> & a0, const opencascade::handle<Transfer_TransientProcess> & a1) -> void { return self.Init(a0, a1); }, py::arg("S"), py::arg("TP"));
	cls_StepToTopoDS_Builder.def("Init", [](StepToTopoDS_Builder &self, const opencascade::handle<StepShape_GeometricSet> & a0, const opencascade::handle<Transfer_TransientProcess> & a1, const opencascade::handle<Transfer_ActorOfTransientProcess> & a2) -> void { return self.Init(a0, a1, a2); }, py::arg("S"), py::arg("TP"), py::arg("RA"));
	cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_GeometricSet> &, const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Transfer_ActorOfTransientProcess> &, const Standard_Boolean)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"), py::arg("RA"), py::arg("isManifold"));
	cls_StepToTopoDS_Builder.def("Value", (const TopoDS_Shape & (StepToTopoDS_Builder::*)() const ) &StepToTopoDS_Builder::Value, "None");
	cls_StepToTopoDS_Builder.def("Error", (StepToTopoDS_BuilderError (StepToTopoDS_Builder::*)() const ) &StepToTopoDS_Builder::Error, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_MakeTransformed.hxx
	py::class_<StepToTopoDS_MakeTransformed, std::unique_ptr<StepToTopoDS_MakeTransformed, Deleter<StepToTopoDS_MakeTransformed>>, StepToTopoDS_Root> cls_StepToTopoDS_MakeTransformed(mod, "StepToTopoDS_MakeTransformed", "Produces instances by Transformation of a basic item");
	cls_StepToTopoDS_MakeTransformed.def(py::init<>());
	cls_StepToTopoDS_MakeTransformed.def("Compute", (Standard_Boolean (StepToTopoDS_MakeTransformed::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepToTopoDS_MakeTransformed::Compute, "Computes a transformation to pass from an Origin placement to a Target placement. Returns True when done If not done, the transformation will by Identity", py::arg("Origin"), py::arg("Target"));
	cls_StepToTopoDS_MakeTransformed.def("Compute", (Standard_Boolean (StepToTopoDS_MakeTransformed::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepToTopoDS_MakeTransformed::Compute, "Computes a transformation defined by an operator 3D", py::arg("Operator"));
	cls_StepToTopoDS_MakeTransformed.def("Transformation", (const gp_Trsf & (StepToTopoDS_MakeTransformed::*)() const ) &StepToTopoDS_MakeTransformed::Transformation, "Returns the computed transformation (Identity if not yet or if failed)");
	cls_StepToTopoDS_MakeTransformed.def("Transform", (Standard_Boolean (StepToTopoDS_MakeTransformed::*)(TopoDS_Shape &) const ) &StepToTopoDS_MakeTransformed::Transform, "Applies the computed transformation to a shape Returns False if the transformation is Identity", py::arg("shape"));
	cls_StepToTopoDS_MakeTransformed.def("TranslateMappedItem", (TopoDS_Shape (StepToTopoDS_MakeTransformed::*)(const opencascade::handle<StepRepr_MappedItem> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_MakeTransformed::TranslateMappedItem, "Translates a MappedItem. More precisely A MappedItem has a MappingSource and a MappingTarget MappingSource has a MappedRepresentation and a MappingOrigin MappedRepresentation is the basic item to be instanced MappingOrigin is the starting placement MappingTarget is the final placement", py::arg("mapit"), py::arg("TP"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_GeometricTool.hxx
	py::class_<StepToTopoDS_GeometricTool, std::unique_ptr<StepToTopoDS_GeometricTool, Deleter<StepToTopoDS_GeometricTool>>> cls_StepToTopoDS_GeometricTool(mod, "StepToTopoDS_GeometricTool", "This class contains some algorithmic services specific to the mapping STEP to CAS.CADE");
	cls_StepToTopoDS_GeometricTool.def(py::init<>());
	cls_StepToTopoDS_GeometricTool.def_static("PCurve_", [](const opencascade::handle<StepGeom_SurfaceCurve> & a0, const opencascade::handle<StepGeom_Surface> & a1, opencascade::handle<StepGeom_Pcurve> & a2) -> Standard_Integer { return StepToTopoDS_GeometricTool::PCurve(a0, a1, a2); }, py::arg("SC"), py::arg("S"), py::arg("PC"));
	cls_StepToTopoDS_GeometricTool.def_static("PCurve_", (Standard_Integer (*)(const opencascade::handle<StepGeom_SurfaceCurve> &, const opencascade::handle<StepGeom_Surface> &, opencascade::handle<StepGeom_Pcurve> &, const Standard_Integer)) &StepToTopoDS_GeometricTool::PCurve, "None", py::arg("SC"), py::arg("S"), py::arg("PC"), py::arg("last"));
	cls_StepToTopoDS_GeometricTool.def_static("IsSeamCurve_", (Standard_Boolean (*)(const opencascade::handle<StepGeom_SurfaceCurve> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepShape_Edge> &, const opencascade::handle<StepShape_EdgeLoop> &)) &StepToTopoDS_GeometricTool::IsSeamCurve, "None", py::arg("SC"), py::arg("S"), py::arg("E"), py::arg("EL"));
	cls_StepToTopoDS_GeometricTool.def_static("IsLikeSeam_", (Standard_Boolean (*)(const opencascade::handle<StepGeom_SurfaceCurve> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepShape_Edge> &, const opencascade::handle<StepShape_EdgeLoop> &)) &StepToTopoDS_GeometricTool::IsLikeSeam, "None", py::arg("SC"), py::arg("S"), py::arg("E"), py::arg("EL"));
	cls_StepToTopoDS_GeometricTool.def_static("UpdateParam3d_", [](const opencascade::handle<Geom_Curve> & C, Standard_Real & w1, Standard_Real & w2, const Standard_Real preci){ Standard_Boolean rv = StepToTopoDS_GeometricTool::UpdateParam3d(C, w1, w2, preci); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, w1, w2); }, "None", py::arg("C"), py::arg("w1"), py::arg("w2"), py::arg("preci"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_Tool.hxx
	py::class_<StepToTopoDS_Tool, std::unique_ptr<StepToTopoDS_Tool, Deleter<StepToTopoDS_Tool>>> cls_StepToTopoDS_Tool(mod, "StepToTopoDS_Tool", "This Tool Class provides Information to build a Cas.Cad BRep from a ProSTEP Shape model.");
	cls_StepToTopoDS_Tool.def(py::init<>());
	cls_StepToTopoDS_Tool.def(py::init<const StepToTopoDS_DataMapOfTRI &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("Map"), py::arg("TP"));
	cls_StepToTopoDS_Tool.def("Init", (void (StepToTopoDS_Tool::*)(const StepToTopoDS_DataMapOfTRI &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Tool::Init, "None", py::arg("Map"), py::arg("TP"));
	cls_StepToTopoDS_Tool.def("IsBound", (Standard_Boolean (StepToTopoDS_Tool::*)(const opencascade::handle<StepShape_TopologicalRepresentationItem> &)) &StepToTopoDS_Tool::IsBound, "None", py::arg("TRI"));
	cls_StepToTopoDS_Tool.def("Bind", (void (StepToTopoDS_Tool::*)(const opencascade::handle<StepShape_TopologicalRepresentationItem> &, const TopoDS_Shape &)) &StepToTopoDS_Tool::Bind, "None", py::arg("TRI"), py::arg("S"));
	cls_StepToTopoDS_Tool.def("Find", (const TopoDS_Shape & (StepToTopoDS_Tool::*)(const opencascade::handle<StepShape_TopologicalRepresentationItem> &)) &StepToTopoDS_Tool::Find, "None", py::arg("TRI"));
	cls_StepToTopoDS_Tool.def("ClearEdgeMap", (void (StepToTopoDS_Tool::*)()) &StepToTopoDS_Tool::ClearEdgeMap, "None");
	cls_StepToTopoDS_Tool.def("IsEdgeBound", (Standard_Boolean (StepToTopoDS_Tool::*)(const StepToTopoDS_PointPair &)) &StepToTopoDS_Tool::IsEdgeBound, "None", py::arg("PP"));
	cls_StepToTopoDS_Tool.def("BindEdge", (void (StepToTopoDS_Tool::*)(const StepToTopoDS_PointPair &, const TopoDS_Edge &)) &StepToTopoDS_Tool::BindEdge, "None", py::arg("PP"), py::arg("E"));
	cls_StepToTopoDS_Tool.def("FindEdge", (const TopoDS_Edge & (StepToTopoDS_Tool::*)(const StepToTopoDS_PointPair &)) &StepToTopoDS_Tool::FindEdge, "None", py::arg("PP"));
	cls_StepToTopoDS_Tool.def("ClearVertexMap", (void (StepToTopoDS_Tool::*)()) &StepToTopoDS_Tool::ClearVertexMap, "None");
	cls_StepToTopoDS_Tool.def("IsVertexBound", (Standard_Boolean (StepToTopoDS_Tool::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepToTopoDS_Tool::IsVertexBound, "None", py::arg("PG"));
	cls_StepToTopoDS_Tool.def("BindVertex", (void (StepToTopoDS_Tool::*)(const opencascade::handle<StepGeom_CartesianPoint> &, const TopoDS_Vertex &)) &StepToTopoDS_Tool::BindVertex, "None", py::arg("P"), py::arg("V"));
	cls_StepToTopoDS_Tool.def("FindVertex", (const TopoDS_Vertex & (StepToTopoDS_Tool::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepToTopoDS_Tool::FindVertex, "None", py::arg("P"));
	cls_StepToTopoDS_Tool.def("ComputePCurve", (void (StepToTopoDS_Tool::*)(const Standard_Boolean)) &StepToTopoDS_Tool::ComputePCurve, "None", py::arg("B"));
	cls_StepToTopoDS_Tool.def("ComputePCurve", (Standard_Boolean (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::ComputePCurve, "None");
	cls_StepToTopoDS_Tool.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::TransientProcess, "None");
	cls_StepToTopoDS_Tool.def("AddContinuity", (void (StepToTopoDS_Tool::*)(const opencascade::handle<Geom_Surface> &)) &StepToTopoDS_Tool::AddContinuity, "None", py::arg("GeomSurf"));
	cls_StepToTopoDS_Tool.def("AddContinuity", (void (StepToTopoDS_Tool::*)(const opencascade::handle<Geom_Curve> &)) &StepToTopoDS_Tool::AddContinuity, "None", py::arg("GeomCurve"));
	cls_StepToTopoDS_Tool.def("AddContinuity", (void (StepToTopoDS_Tool::*)(const opencascade::handle<Geom2d_Curve> &)) &StepToTopoDS_Tool::AddContinuity, "None", py::arg("GeomCur2d"));
	cls_StepToTopoDS_Tool.def("C0Surf", (Standard_Integer (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::C0Surf, "None");
	cls_StepToTopoDS_Tool.def("C1Surf", (Standard_Integer (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::C1Surf, "None");
	cls_StepToTopoDS_Tool.def("C2Surf", (Standard_Integer (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::C2Surf, "None");
	cls_StepToTopoDS_Tool.def("C0Cur2", (Standard_Integer (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::C0Cur2, "None");
	cls_StepToTopoDS_Tool.def("C1Cur2", (Standard_Integer (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::C1Cur2, "None");
	cls_StepToTopoDS_Tool.def("C2Cur2", (Standard_Integer (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::C2Cur2, "None");
	cls_StepToTopoDS_Tool.def("C0Cur3", (Standard_Integer (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::C0Cur3, "None");
	cls_StepToTopoDS_Tool.def("C1Cur3", (Standard_Integer (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::C1Cur3, "None");
	cls_StepToTopoDS_Tool.def("C2Cur3", (Standard_Integer (StepToTopoDS_Tool::*)() const ) &StepToTopoDS_Tool::C2Cur3, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_CartesianPointHasher.hxx
	py::class_<StepToTopoDS_CartesianPointHasher, std::unique_ptr<StepToTopoDS_CartesianPointHasher, Deleter<StepToTopoDS_CartesianPointHasher>>> cls_StepToTopoDS_CartesianPointHasher(mod, "StepToTopoDS_CartesianPointHasher", "None");
	cls_StepToTopoDS_CartesianPointHasher.def(py::init<>());
	cls_StepToTopoDS_CartesianPointHasher.def_static("HashCode_", (Standard_Integer (*)(const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Integer)) &StepToTopoDS_CartesianPointHasher::HashCode, "Returns a HasCode value for the CartesianPoint", py::arg("K"), py::arg("Upper"));
	cls_StepToTopoDS_CartesianPointHasher.def_static("IsEqual_", (Standard_Boolean (*)(const opencascade::handle<StepGeom_CartesianPoint> &, const opencascade::handle<StepGeom_CartesianPoint> &)) &StepToTopoDS_CartesianPointHasher::IsEqual, "Returns True when the two CartesianPoint are the same", py::arg("K1"), py::arg("K2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_PointPair.hxx
	py::class_<StepToTopoDS_PointPair, std::unique_ptr<StepToTopoDS_PointPair, Deleter<StepToTopoDS_PointPair>>> cls_StepToTopoDS_PointPair(mod, "StepToTopoDS_PointPair", "Stores a pair of Points from step");
	cls_StepToTopoDS_PointPair.def(py::init<const opencascade::handle<StepGeom_CartesianPoint> &, const opencascade::handle<StepGeom_CartesianPoint> &>(), py::arg("P1"), py::arg("P2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_PointPairHasher.hxx
	py::class_<StepToTopoDS_PointPairHasher, std::unique_ptr<StepToTopoDS_PointPairHasher, Deleter<StepToTopoDS_PointPairHasher>>> cls_StepToTopoDS_PointPairHasher(mod, "StepToTopoDS_PointPairHasher", "None");
	cls_StepToTopoDS_PointPairHasher.def(py::init<>());
	cls_StepToTopoDS_PointPairHasher.def_static("HashCode_", (Standard_Integer (*)(const StepToTopoDS_PointPair &, const Standard_Integer)) &StepToTopoDS_PointPairHasher::HashCode, "Returns a HasCode value for the PointPair", py::arg("K"), py::arg("Upper"));
	cls_StepToTopoDS_PointPairHasher.def_static("IsEqual_", (Standard_Boolean (*)(const StepToTopoDS_PointPair &, const StepToTopoDS_PointPair &)) &StepToTopoDS_PointPairHasher::IsEqual, "Returns True when the two PointPair are the same", py::arg("K1"), py::arg("K2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS.hxx
	py::class_<StepToTopoDS, std::unique_ptr<StepToTopoDS, Deleter<StepToTopoDS>>> cls_StepToTopoDS(mod, "StepToTopoDS", "This package implements the mapping between AP214 Shape representation and CAS.CAD Shape Representation. The source schema is Part42 (which is included in AP214)");
	cls_StepToTopoDS.def(py::init<>());
	cls_StepToTopoDS.def_static("DecodeBuilderError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_BuilderError)) &StepToTopoDS::DecodeBuilderError, "None", py::arg("Error"));
	cls_StepToTopoDS.def_static("DecodeShellError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateShellError)) &StepToTopoDS::DecodeShellError, "None", py::arg("Error"));
	cls_StepToTopoDS.def_static("DecodeFaceError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateFaceError)) &StepToTopoDS::DecodeFaceError, "None", py::arg("Error"));
	cls_StepToTopoDS.def_static("DecodeEdgeError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateEdgeError)) &StepToTopoDS::DecodeEdgeError, "None", py::arg("Error"));
	cls_StepToTopoDS.def_static("DecodeVertexError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateVertexError)) &StepToTopoDS::DecodeVertexError, "None", py::arg("Error"));
	cls_StepToTopoDS.def_static("DecodeVertexLoopError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateVertexLoopError)) &StepToTopoDS::DecodeVertexLoopError, "None", py::arg("Error"));
	cls_StepToTopoDS.def_static("DecodePolyLoopError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslatePolyLoopError)) &StepToTopoDS::DecodePolyLoopError, "None", py::arg("Error"));
	cls_StepToTopoDS.def_static("DecodeGeometricToolError_", (Standard_CString (*)(const StepToTopoDS_GeometricToolError)) &StepToTopoDS::DecodeGeometricToolError, "None", py::arg("Error"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_DataMapOfRI.hxx
	bind_NCollection_DataMap<opencascade::handle<StepRepr_RepresentationItem>, TopoDS_Shape, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "StepToTopoDS_DataMapOfRI");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_DataMapOfRINames.hxx
	bind_NCollection_DataMap<TCollection_AsciiString, TopoDS_Shape, TCollection_AsciiString>(mod, "StepToTopoDS_DataMapOfRINames");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_DataMapOfTRI.hxx
	bind_NCollection_DataMap<opencascade::handle<StepShape_TopologicalRepresentationItem>, TopoDS_Shape, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "StepToTopoDS_DataMapOfTRI");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_PointEdgeMap.hxx
	bind_NCollection_DataMap<StepToTopoDS_PointPair, TopoDS_Edge, StepToTopoDS_PointPairHasher>(mod, "StepToTopoDS_PointEdgeMap");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepToTopoDS_PointVertexMap.hxx
	bind_NCollection_DataMap<opencascade::handle<StepGeom_CartesianPoint>, TopoDS_Vertex, StepToTopoDS_CartesianPointHasher>(mod, "StepToTopoDS_PointVertexMap");

	/* FIXME

	*/


}
