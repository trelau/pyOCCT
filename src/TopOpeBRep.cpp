#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TopOpeBRepTool_ShapeClassifier.hxx>

#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepTool_BoxSort.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRep_ShapeScanner.hxx>
#include <TopOpeBRep_TypeLineCurve.hxx>
#include <TopOpeBRep_PPntOn2S.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <TopOpeBRep_WPointInter.hxx>
#include <TopOpeBRep_PThePointOfIntersection.hxx>
#include <IntPatch_Point.hxx>
#include <IntSurf_Transition.hxx>
#include <TopAbs_State.hxx>
#include <TopOpeBRep_VPointInter.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <NCollection_Array1.hxx>
#include <TopOpeBRep_Array1OfVPointInter.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TopOpeBRep_HArray1OfVPointInter.hxx>
#include <TopOpeBRep_Bipoint.hxx>
#include <IntPatch_Line.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <Geom_Curve.hxx>
#include <IntPatch_WLine.hxx>
#include <IntPatch_GLine.hxx>
#include <IntPatch_RLine.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRep_LineInter.hxx>
#include <TopOpeBRep_Array1OfLineInter.hxx>
#include <TopOpeBRep_HArray1OfLineInter.hxx>
#include <Bnd_Box.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopOpeBRep_FacesIntersector.hxx>
#include <TopOpeBRep_P2Dstatus.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <TopOpeBRep_Hctxff2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <IntRes2d_Domain.hxx>
#include <TopOpeBRep_Hctxee2d.hxx>
#include <TopOpeBRep_SequenceOfPoint2d.hxx>
#include <TopOpeBRep_Point2d.hxx>
#include <TopOpeBRep_EdgesIntersector.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopOpeBRep_FaceEdgeIntersector.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRep_ShapeIntersector.hxx>
#include <TopOpeBRep_ShapeIntersector2d.hxx>
#include <TopOpeBRep_PFacesIntersector.hxx>
#include <TopOpeBRep_PLineInter.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <TopOpeBRep_DataMapOfTopolTool.hxx>
#include <TopOpeBRep_PointClassifier.hxx>
#include <TopOpeBRep_PFacesFiller.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <TopOpeBRep_FFDumper.hxx>
#include <TopOpeBRep_VPointInterClassifier.hxx>
#include <TopOpeBRep_VPointInterIterator.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRepTool_PShapeClassifier.hxx>
#include <TopOpeBRep_FacesFiller.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <TopOpeBRepDS_PDataStructure.hxx>
#include <TopOpeBRep_PEdgesIntersector.hxx>
#include <TopOpeBRep_EdgesFiller.hxx>
#include <TopOpeBRep_FaceEdgeFiller.hxx>
#include <TopOpeBRep_DSFiller.hxx>
#include <TopOpeBRep_WPointInterIterator.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <TopOpeBRep_GeomTool.hxx>
#include <TopOpeBRep_PointGeomTool.hxx>
#include <TopOpeBRep_FFTransitionTool.hxx>
#include <TopOpeBRep.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <TopOpeBRep_ListOfBipoint.hxx>
#include <TopOpeBRep_PIntRes2d_IntersectionPoint.hxx>

PYBIND11_MODULE(TopOpeBRep, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.TopOpeBRepTool");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.IntSurf");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.IntPatch");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.BRepAdaptor");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopOpeBRepDS");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom2dAdaptor");
	py::module::import("OCCT.IntRes2d");
	py::module::import("OCCT.Geom2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_TypeLineCurve.hxx
	py::enum_<TopOpeBRep_TypeLineCurve>(mod, "TopOpeBRep_TypeLineCurve", "None")
		.value("TopOpeBRep_ANALYTIC", TopOpeBRep_TypeLineCurve::TopOpeBRep_ANALYTIC)
		.value("TopOpeBRep_RESTRICTION", TopOpeBRep_TypeLineCurve::TopOpeBRep_RESTRICTION)
		.value("TopOpeBRep_WALKING", TopOpeBRep_TypeLineCurve::TopOpeBRep_WALKING)
		.value("TopOpeBRep_LINE", TopOpeBRep_TypeLineCurve::TopOpeBRep_LINE)
		.value("TopOpeBRep_CIRCLE", TopOpeBRep_TypeLineCurve::TopOpeBRep_CIRCLE)
		.value("TopOpeBRep_ELLIPSE", TopOpeBRep_TypeLineCurve::TopOpeBRep_ELLIPSE)
		.value("TopOpeBRep_PARABOLA", TopOpeBRep_TypeLineCurve::TopOpeBRep_PARABOLA)
		.value("TopOpeBRep_HYPERBOLA", TopOpeBRep_TypeLineCurve::TopOpeBRep_HYPERBOLA)
		.value("TopOpeBRep_OTHERTYPE", TopOpeBRep_TypeLineCurve::TopOpeBRep_OTHERTYPE)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_P2Dstatus.hxx
	py::enum_<TopOpeBRep_P2Dstatus>(mod, "TopOpeBRep_P2Dstatus", "None")
		.value("TopOpeBRep_P2DUNK", TopOpeBRep_P2Dstatus::TopOpeBRep_P2DUNK)
		.value("TopOpeBRep_P2DINT", TopOpeBRep_P2Dstatus::TopOpeBRep_P2DINT)
		.value("TopOpeBRep_P2DSGF", TopOpeBRep_P2Dstatus::TopOpeBRep_P2DSGF)
		.value("TopOpeBRep_P2DSGL", TopOpeBRep_P2Dstatus::TopOpeBRep_P2DSGL)
		.value("TopOpeBRep_P2DNEW", TopOpeBRep_P2Dstatus::TopOpeBRep_P2DNEW)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_ShapeScanner.hxx
	py::class_<TopOpeBRep_ShapeScanner, std::unique_ptr<TopOpeBRep_ShapeScanner, Deleter<TopOpeBRep_ShapeScanner>>> cls_TopOpeBRep_ShapeScanner(mod, "TopOpeBRep_ShapeScanner", "Find, among the subshapes SS of a reference shape RS, the ones which 3D box interfers with the box of a shape S (SS and S are of the same type).");
	cls_TopOpeBRep_ShapeScanner.def(py::init<>());
	cls_TopOpeBRep_ShapeScanner.def("Clear", (void (TopOpeBRep_ShapeScanner::*)()) &TopOpeBRep_ShapeScanner::Clear, "None");
	cls_TopOpeBRep_ShapeScanner.def("AddBoxesMakeCOB", [](TopOpeBRep_ShapeScanner &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.AddBoxesMakeCOB(a0, a1); }, py::arg("S"), py::arg("TS"));
	cls_TopOpeBRep_ShapeScanner.def("AddBoxesMakeCOB", (void (TopOpeBRep_ShapeScanner::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRep_ShapeScanner::AddBoxesMakeCOB, "None", py::arg("S"), py::arg("TS"), py::arg("TA"));
	cls_TopOpeBRep_ShapeScanner.def("Init", (void (TopOpeBRep_ShapeScanner::*)(const TopoDS_Shape &)) &TopOpeBRep_ShapeScanner::Init, "None", py::arg("E"));
	cls_TopOpeBRep_ShapeScanner.def("Init", (void (TopOpeBRep_ShapeScanner::*)(TopOpeBRepTool_ShapeExplorer &)) &TopOpeBRep_ShapeScanner::Init, "None", py::arg("X"));
	cls_TopOpeBRep_ShapeScanner.def("More", (Standard_Boolean (TopOpeBRep_ShapeScanner::*)() const ) &TopOpeBRep_ShapeScanner::More, "None");
	cls_TopOpeBRep_ShapeScanner.def("Next", (void (TopOpeBRep_ShapeScanner::*)()) &TopOpeBRep_ShapeScanner::Next, "None");
	cls_TopOpeBRep_ShapeScanner.def("Current", (const TopoDS_Shape & (TopOpeBRep_ShapeScanner::*)() const ) &TopOpeBRep_ShapeScanner::Current, "None");
	cls_TopOpeBRep_ShapeScanner.def("BoxSort", (const TopOpeBRepTool_BoxSort & (TopOpeBRep_ShapeScanner::*)() const ) &TopOpeBRep_ShapeScanner::BoxSort, "None");
	cls_TopOpeBRep_ShapeScanner.def("ChangeBoxSort", (TopOpeBRepTool_BoxSort & (TopOpeBRep_ShapeScanner::*)()) &TopOpeBRep_ShapeScanner::ChangeBoxSort, "None");
	cls_TopOpeBRep_ShapeScanner.def("Index", (Standard_Integer (TopOpeBRep_ShapeScanner::*)() const ) &TopOpeBRep_ShapeScanner::Index, "None");
	cls_TopOpeBRep_ShapeScanner.def("DumpCurrent", (Standard_OStream & (TopOpeBRep_ShapeScanner::*)(Standard_OStream &) const ) &TopOpeBRep_ShapeScanner::DumpCurrent, "None", py::arg("OS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_WPointInter.hxx
	py::class_<TopOpeBRep_WPointInter, std::unique_ptr<TopOpeBRep_WPointInter, Deleter<TopOpeBRep_WPointInter>>> cls_TopOpeBRep_WPointInter(mod, "TopOpeBRep_WPointInter", "None");
	cls_TopOpeBRep_WPointInter.def(py::init<>());
	cls_TopOpeBRep_WPointInter.def("Set", (void (TopOpeBRep_WPointInter::*)(const IntSurf_PntOn2S &)) &TopOpeBRep_WPointInter::Set, "None", py::arg("P"));
	cls_TopOpeBRep_WPointInter.def("ParametersOnS1", (void (TopOpeBRep_WPointInter::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRep_WPointInter::ParametersOnS1, "None", py::arg("U"), py::arg("V"));
	cls_TopOpeBRep_WPointInter.def("ParametersOnS2", (void (TopOpeBRep_WPointInter::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRep_WPointInter::ParametersOnS2, "None", py::arg("U"), py::arg("V"));
	cls_TopOpeBRep_WPointInter.def("Parameters", (void (TopOpeBRep_WPointInter::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &TopOpeBRep_WPointInter::Parameters, "None", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
	cls_TopOpeBRep_WPointInter.def("ValueOnS1", (gp_Pnt2d (TopOpeBRep_WPointInter::*)() const ) &TopOpeBRep_WPointInter::ValueOnS1, "None");
	cls_TopOpeBRep_WPointInter.def("ValueOnS2", (gp_Pnt2d (TopOpeBRep_WPointInter::*)() const ) &TopOpeBRep_WPointInter::ValueOnS2, "None");
	cls_TopOpeBRep_WPointInter.def("Value", (const gp_Pnt & (TopOpeBRep_WPointInter::*)() const ) &TopOpeBRep_WPointInter::Value, "None");
	cls_TopOpeBRep_WPointInter.def("PPntOn2SDummy", (TopOpeBRep_PPntOn2S (TopOpeBRep_WPointInter::*)() const ) &TopOpeBRep_WPointInter::PPntOn2SDummy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_VPointInter.hxx
	py::class_<TopOpeBRep_VPointInter, std::unique_ptr<TopOpeBRep_VPointInter, Deleter<TopOpeBRep_VPointInter>>> cls_TopOpeBRep_VPointInter(mod, "TopOpeBRep_VPointInter", "None");
	cls_TopOpeBRep_VPointInter.def(py::init<>());
	cls_TopOpeBRep_VPointInter.def("SetPoint", (void (TopOpeBRep_VPointInter::*)(const IntPatch_Point &)) &TopOpeBRep_VPointInter::SetPoint, "None", py::arg("P"));
	cls_TopOpeBRep_VPointInter.def("SetShapes", (void (TopOpeBRep_VPointInter::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_VPointInter::SetShapes, "None", py::arg("I1"), py::arg("I2"));
	cls_TopOpeBRep_VPointInter.def("GetShapes", (void (TopOpeBRep_VPointInter::*)(Standard_Integer &, Standard_Integer &) const ) &TopOpeBRep_VPointInter::GetShapes, "None", py::arg("I1"), py::arg("I2"));
	cls_TopOpeBRep_VPointInter.def("TransitionOnS1", (IntSurf_Transition (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::TransitionOnS1, "None");
	cls_TopOpeBRep_VPointInter.def("TransitionOnS2", (IntSurf_Transition (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::TransitionOnS2, "None");
	cls_TopOpeBRep_VPointInter.def("TransitionLineArc1", (IntSurf_Transition (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::TransitionLineArc1, "None");
	cls_TopOpeBRep_VPointInter.def("TransitionLineArc2", (IntSurf_Transition (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::TransitionLineArc2, "None");
	cls_TopOpeBRep_VPointInter.def("IsOnDomS1", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::IsOnDomS1, "None");
	cls_TopOpeBRep_VPointInter.def("IsOnDomS2", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::IsOnDomS2, "None");
	cls_TopOpeBRep_VPointInter.def("ParametersOnS1", (void (TopOpeBRep_VPointInter::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRep_VPointInter::ParametersOnS1, "None", py::arg("u"), py::arg("v"));
	cls_TopOpeBRep_VPointInter.def("ParametersOnS2", (void (TopOpeBRep_VPointInter::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRep_VPointInter::ParametersOnS2, "None", py::arg("u"), py::arg("v"));
	cls_TopOpeBRep_VPointInter.def("Value", (const gp_Pnt & (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::Value, "None");
	cls_TopOpeBRep_VPointInter.def("Tolerance", (Standard_Real (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::Tolerance, "None");
	cls_TopOpeBRep_VPointInter.def("ArcOnS1", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::ArcOnS1, "None");
	cls_TopOpeBRep_VPointInter.def("ArcOnS2", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::ArcOnS2, "None");
	cls_TopOpeBRep_VPointInter.def("ParameterOnLine", (Standard_Real (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::ParameterOnLine, "None");
	cls_TopOpeBRep_VPointInter.def("ParameterOnArc1", (Standard_Real (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::ParameterOnArc1, "None");
	cls_TopOpeBRep_VPointInter.def("IsVertexOnS1", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::IsVertexOnS1, "Returns TRUE if the point is a vertex on the initial restriction facet of the first surface.");
	cls_TopOpeBRep_VPointInter.def("VertexOnS1", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::VertexOnS1, "Returns the information about the point when it is on the domain of the first patch, i-e when the function IsVertexOnS1 returns True. Otherwise, an exception is raised.");
	cls_TopOpeBRep_VPointInter.def("ParameterOnArc2", (Standard_Real (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::ParameterOnArc2, "None");
	cls_TopOpeBRep_VPointInter.def("IsVertexOnS2", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::IsVertexOnS2, "Returns TRUE if the point is a vertex on the initial restriction facet of the second surface.");
	cls_TopOpeBRep_VPointInter.def("VertexOnS2", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::VertexOnS2, "Returns the information about the point when it is on the domain of the second patch, i-e when the function IsVertexOnS2 returns True. Otherwise, an exception is raised.");
	cls_TopOpeBRep_VPointInter.def("IsInternal", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::IsInternal, "None");
	cls_TopOpeBRep_VPointInter.def("IsMultiple", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::IsMultiple, "Returns True if the point belongs to several intersection lines.");
	cls_TopOpeBRep_VPointInter.def("State", (TopAbs_State (TopOpeBRep_VPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_VPointInter::State, "get state of VPoint within the domain of geometric shape domain <I> (= 1 or 2).", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("State", (void (TopOpeBRep_VPointInter::*)(const TopAbs_State, const Standard_Integer)) &TopOpeBRep_VPointInter::State, "Set the state of VPoint within the domain of the geometric shape <I> (= 1 or 2).", py::arg("S"), py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("EdgeON", (void (TopOpeBRep_VPointInter::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Integer)) &TopOpeBRep_VPointInter::EdgeON, "set the shape Eon of shape I (1,2) containing the point, and parameter <Par> of point on <Eon>.", py::arg("Eon"), py::arg("Par"), py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("EdgeON", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_VPointInter::EdgeON, "get the edge of shape I (1,2) containing the point.", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("EdgeONParameter", (Standard_Real (TopOpeBRep_VPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_VPointInter::EdgeONParameter, "get the parameter on edge of shape I (1,2) containing the point.", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("ShapeIndex", (Standard_Integer (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::ShapeIndex, "returns value of filed myShapeIndex = 0,1,2,3 0 means the VPoint is on no restriction 1 means the VPoint is on the restriction 1 2 means the VPoint is on the restriction 2 3 means the VPoint is on the restrictions 1 and 2");
	cls_TopOpeBRep_VPointInter.def("ShapeIndex", (void (TopOpeBRep_VPointInter::*)(const Standard_Integer)) &TopOpeBRep_VPointInter::ShapeIndex, "set value of shape supporting me (0,1,2,3).", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("Edge", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_VPointInter::Edge, "get the edge of shape I (1,2) containing the point. Returned shape is null if the VPoint is not on an edge of shape I (1,2).", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("EdgeParameter", (Standard_Real (TopOpeBRep_VPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_VPointInter::EdgeParameter, "get the parameter on edge of shape I (1,2) containing the point", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("SurfaceParameters", (gp_Pnt2d (TopOpeBRep_VPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_VPointInter::SurfaceParameters, "get the parameter on surface of shape I (1,2) containing the point", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("IsVertex", (Standard_Boolean (TopOpeBRep_VPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_VPointInter::IsVertex, "None", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("Vertex", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_VPointInter::Vertex, "None", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("UpdateKeep", (void (TopOpeBRep_VPointInter::*)()) &TopOpeBRep_VPointInter::UpdateKeep, "set myKeep value according to current states.");
	cls_TopOpeBRep_VPointInter.def("Keep", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::Keep, "Returns value of myKeep (does not evaluate states) False at creation of VPoint. Updated by State(State from TopAbs,Integer from Standard)");
	cls_TopOpeBRep_VPointInter.def("ChangeKeep", (void (TopOpeBRep_VPointInter::*)(const Standard_Boolean)) &TopOpeBRep_VPointInter::ChangeKeep, "updates VPointInter flag 'keep' with <keep>.", py::arg("keep"));
	cls_TopOpeBRep_VPointInter.def("EqualpP", (Standard_Boolean (TopOpeBRep_VPointInter::*)(const TopOpeBRep_VPointInter &) const ) &TopOpeBRep_VPointInter::EqualpP, "returns <True> if the 3d points and the parameters of the VPoints are same", py::arg("VP"));
	cls_TopOpeBRep_VPointInter.def("ParonE", (Standard_Boolean (TopOpeBRep_VPointInter::*)(const TopoDS_Edge &, Standard_Real &) const ) &TopOpeBRep_VPointInter::ParonE, "returns <false> if the vpoint is not given on arc <E>, else returns <par> parameter on <E>", py::arg("E"), py::arg("par"));
	cls_TopOpeBRep_VPointInter.def("Index", (void (TopOpeBRep_VPointInter::*)(const Standard_Integer)) &TopOpeBRep_VPointInter::Index, "None", py::arg("I"));
	cls_TopOpeBRep_VPointInter.def("Index", (Standard_Integer (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::Index, "None");
	// FIXME cls_TopOpeBRep_VPointInter.def("Dump", (Standard_OStream & (TopOpeBRep_VPointInter::*)(const Standard_Integer, const TopoDS_Face &, Standard_OStream &) const ) &TopOpeBRep_VPointInter::Dump, "None", py::arg("I"), py::arg("F"), py::arg("OS"));
	// FIXME cls_TopOpeBRep_VPointInter.def("Dump", (Standard_OStream & (TopOpeBRep_VPointInter::*)(const TopoDS_Face &, const TopoDS_Face &, Standard_OStream &) const ) &TopOpeBRep_VPointInter::Dump, "None", py::arg("F1"), py::arg("F2"), py::arg("OS"));
	cls_TopOpeBRep_VPointInter.def("PThePointOfIntersectionDummy", (TopOpeBRep_PThePointOfIntersection (TopOpeBRep_VPointInter::*)() const ) &TopOpeBRep_VPointInter::PThePointOfIntersectionDummy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TopOpeBRep_Array1OfVPointInter, std::unique_ptr<TopOpeBRep_Array1OfVPointInter, Deleter<TopOpeBRep_Array1OfVPointInter>>> cls_TopOpeBRep_Array1OfVPointInter(mod, "TopOpeBRep_Array1OfVPointInter", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TopOpeBRep_Array1OfVPointInter.def(py::init<>());
	cls_TopOpeBRep_Array1OfVPointInter.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TopOpeBRep_Array1OfVPointInter.def(py::init([] (const TopOpeBRep_Array1OfVPointInter &other) {return new TopOpeBRep_Array1OfVPointInter(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TopOpeBRep_Array1OfVPointInter.def(py::init<TopOpeBRep_Array1OfVPointInter &&>(), py::arg("theOther"));
	cls_TopOpeBRep_Array1OfVPointInter.def(py::init<const TopOpeBRep_VPointInter &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TopOpeBRep_Array1OfVPointInter.def("begin", (TopOpeBRep_Array1OfVPointInter::iterator (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TopOpeBRep_Array1OfVPointInter.def("end", (TopOpeBRep_Array1OfVPointInter::iterator (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TopOpeBRep_Array1OfVPointInter.def("cbegin", (TopOpeBRep_Array1OfVPointInter::const_iterator (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TopOpeBRep_Array1OfVPointInter.def("cend", (TopOpeBRep_Array1OfVPointInter::const_iterator (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TopOpeBRep_Array1OfVPointInter.def("Init", (void (TopOpeBRep_Array1OfVPointInter::*)(const TopOpeBRep_VPointInter &)) &TopOpeBRep_Array1OfVPointInter::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TopOpeBRep_Array1OfVPointInter.def("Size", (Standard_Integer (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::Size, "Size query");
	cls_TopOpeBRep_Array1OfVPointInter.def("Length", (Standard_Integer (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::Length, "Length query (the same)");
	cls_TopOpeBRep_Array1OfVPointInter.def("IsEmpty", (Standard_Boolean (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::IsEmpty, "Return TRUE if array has zero length.");
	cls_TopOpeBRep_Array1OfVPointInter.def("Lower", (Standard_Integer (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::Lower, "Lower bound");
	cls_TopOpeBRep_Array1OfVPointInter.def("Upper", (Standard_Integer (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::Upper, "Upper bound");
	cls_TopOpeBRep_Array1OfVPointInter.def("IsDeletable", (Standard_Boolean (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::IsDeletable, "myDeletable flag");
	cls_TopOpeBRep_Array1OfVPointInter.def("IsAllocated", (Standard_Boolean (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TopOpeBRep_Array1OfVPointInter.def("Assign", (TopOpeBRep_Array1OfVPointInter & (TopOpeBRep_Array1OfVPointInter::*)(const TopOpeBRep_Array1OfVPointInter &)) &TopOpeBRep_Array1OfVPointInter::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TopOpeBRep_Array1OfVPointInter.def("Move", (TopOpeBRep_Array1OfVPointInter & (TopOpeBRep_Array1OfVPointInter::*)(TopOpeBRep_Array1OfVPointInter &&)) &TopOpeBRep_Array1OfVPointInter::Move, "Move assignment", py::arg("theOther"));
	cls_TopOpeBRep_Array1OfVPointInter.def("assign", (TopOpeBRep_Array1OfVPointInter & (TopOpeBRep_Array1OfVPointInter::*)(const TopOpeBRep_Array1OfVPointInter &)) &TopOpeBRep_Array1OfVPointInter::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TopOpeBRep_Array1OfVPointInter.def("assign", (TopOpeBRep_Array1OfVPointInter & (TopOpeBRep_Array1OfVPointInter::*)(TopOpeBRep_Array1OfVPointInter &&)) &TopOpeBRep_Array1OfVPointInter::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TopOpeBRep_Array1OfVPointInter.def("First", (const TopOpeBRep_VPointInter & (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::First, "Returns first element");
	cls_TopOpeBRep_Array1OfVPointInter.def("ChangeFirst", (TopOpeBRep_VPointInter & (TopOpeBRep_Array1OfVPointInter::*)()) &TopOpeBRep_Array1OfVPointInter::ChangeFirst, "Returns first element");
	cls_TopOpeBRep_Array1OfVPointInter.def("Last", (const TopOpeBRep_VPointInter & (TopOpeBRep_Array1OfVPointInter::*)() const ) &TopOpeBRep_Array1OfVPointInter::Last, "Returns last element");
	cls_TopOpeBRep_Array1OfVPointInter.def("ChangeLast", (TopOpeBRep_VPointInter & (TopOpeBRep_Array1OfVPointInter::*)()) &TopOpeBRep_Array1OfVPointInter::ChangeLast, "Returns last element");
	cls_TopOpeBRep_Array1OfVPointInter.def("Value", (const TopOpeBRep_VPointInter & (TopOpeBRep_Array1OfVPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_Array1OfVPointInter::Value, "Constant value access", py::arg("theIndex"));
	cls_TopOpeBRep_Array1OfVPointInter.def("__call__", (const TopOpeBRep_VPointInter & (TopOpeBRep_Array1OfVPointInter::*)(const Standard_Integer) const ) &TopOpeBRep_Array1OfVPointInter::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TopOpeBRep_Array1OfVPointInter.def("ChangeValue", (TopOpeBRep_VPointInter & (TopOpeBRep_Array1OfVPointInter::*)(const Standard_Integer)) &TopOpeBRep_Array1OfVPointInter::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TopOpeBRep_Array1OfVPointInter.def("__call__", (TopOpeBRep_VPointInter & (TopOpeBRep_Array1OfVPointInter::*)(const Standard_Integer)) &TopOpeBRep_Array1OfVPointInter::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TopOpeBRep_Array1OfVPointInter.def("SetValue", (void (TopOpeBRep_Array1OfVPointInter::*)(const Standard_Integer, const TopOpeBRep_VPointInter &)) &TopOpeBRep_Array1OfVPointInter::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TopOpeBRep_Array1OfVPointInter.def("Resize", (void (TopOpeBRep_Array1OfVPointInter::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TopOpeBRep_Array1OfVPointInter::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TopOpeBRep_Array1OfVPointInter.def("__iter__", [](const TopOpeBRep_Array1OfVPointInter &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_Bipoint.hxx
	py::class_<TopOpeBRep_Bipoint, std::unique_ptr<TopOpeBRep_Bipoint, Deleter<TopOpeBRep_Bipoint>>> cls_TopOpeBRep_Bipoint(mod, "TopOpeBRep_Bipoint", "None");
	cls_TopOpeBRep_Bipoint.def(py::init<>());
	cls_TopOpeBRep_Bipoint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("I1"), py::arg("I2"));
	cls_TopOpeBRep_Bipoint.def("I1", (Standard_Integer (TopOpeBRep_Bipoint::*)() const ) &TopOpeBRep_Bipoint::I1, "None");
	cls_TopOpeBRep_Bipoint.def("I2", (Standard_Integer (TopOpeBRep_Bipoint::*)() const ) &TopOpeBRep_Bipoint::I2, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_LineInter.hxx
	py::class_<TopOpeBRep_LineInter, std::unique_ptr<TopOpeBRep_LineInter, Deleter<TopOpeBRep_LineInter>>> cls_TopOpeBRep_LineInter(mod, "TopOpeBRep_LineInter", "None");
	cls_TopOpeBRep_LineInter.def(py::init<>());
	cls_TopOpeBRep_LineInter.def("SetLine", (void (TopOpeBRep_LineInter::*)(const opencascade::handle<IntPatch_Line> &, const BRepAdaptor_Surface &, const BRepAdaptor_Surface &)) &TopOpeBRep_LineInter::SetLine, "None", py::arg("L"), py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRep_LineInter.def("SetFaces", (void (TopOpeBRep_LineInter::*)(const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRep_LineInter::SetFaces, "None", py::arg("F1"), py::arg("F2"));
	cls_TopOpeBRep_LineInter.def("TypeLineCurve", (TopOpeBRep_TypeLineCurve (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::TypeLineCurve, "None");
	cls_TopOpeBRep_LineInter.def("NbVPoint", (Standard_Integer (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::NbVPoint, "None");
	cls_TopOpeBRep_LineInter.def("VPoint", (const TopOpeBRep_VPointInter & (TopOpeBRep_LineInter::*)(const Standard_Integer) const ) &TopOpeBRep_LineInter::VPoint, "None", py::arg("I"));
	cls_TopOpeBRep_LineInter.def("ChangeVPoint", (TopOpeBRep_VPointInter & (TopOpeBRep_LineInter::*)(const Standard_Integer)) &TopOpeBRep_LineInter::ChangeVPoint, "None", py::arg("I"));
	cls_TopOpeBRep_LineInter.def("SetINL", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::SetINL, "None");
	cls_TopOpeBRep_LineInter.def("INL", (Standard_Boolean (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::INL, "None");
	cls_TopOpeBRep_LineInter.def("SetIsVClosed", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::SetIsVClosed, "None");
	cls_TopOpeBRep_LineInter.def("IsVClosed", (Standard_Boolean (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::IsVClosed, "None");
	cls_TopOpeBRep_LineInter.def("SetOK", (void (TopOpeBRep_LineInter::*)(const Standard_Boolean)) &TopOpeBRep_LineInter::SetOK, "None", py::arg("B"));
	cls_TopOpeBRep_LineInter.def("OK", (Standard_Boolean (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::OK, "None");
	cls_TopOpeBRep_LineInter.def("SetHasVPonR", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::SetHasVPonR, "None");
	cls_TopOpeBRep_LineInter.def("HasVPonR", (Standard_Boolean (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::HasVPonR, "None");
	cls_TopOpeBRep_LineInter.def("SetVPBounds", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::SetVPBounds, "None");
	cls_TopOpeBRep_LineInter.def("VPBounds", (void (TopOpeBRep_LineInter::*)(Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &TopOpeBRep_LineInter::VPBounds, "None", py::arg("f"), py::arg("l"), py::arg("n"));
	cls_TopOpeBRep_LineInter.def("IsPeriodic", (Standard_Boolean (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::IsPeriodic, "None");
	cls_TopOpeBRep_LineInter.def("Period", (Standard_Real (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::Period, "None");
	cls_TopOpeBRep_LineInter.def("Bounds", (void (TopOpeBRep_LineInter::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRep_LineInter::Bounds, "None", py::arg("f"), py::arg("l"));
	cls_TopOpeBRep_LineInter.def("HasVInternal", (Standard_Boolean (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::HasVInternal, "None");
	cls_TopOpeBRep_LineInter.def("NbWPoint", (Standard_Integer (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::NbWPoint, "None");
	cls_TopOpeBRep_LineInter.def("WPoint", (const TopOpeBRep_WPointInter & (TopOpeBRep_LineInter::*)(const Standard_Integer)) &TopOpeBRep_LineInter::WPoint, "None", py::arg("I"));
	cls_TopOpeBRep_LineInter.def("TransitionOnS1", (IntSurf_TypeTrans (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::TransitionOnS1, "None");
	cls_TopOpeBRep_LineInter.def("TransitionOnS2", (IntSurf_TypeTrans (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::TransitionOnS2, "None");
	cls_TopOpeBRep_LineInter.def("SituationS1", (IntSurf_Situation (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::SituationS1, "None");
	cls_TopOpeBRep_LineInter.def("SituationS2", (IntSurf_Situation (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::SituationS2, "None");
	cls_TopOpeBRep_LineInter.def("Curve", (opencascade::handle<Geom_Curve> (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::Curve, "None");
	cls_TopOpeBRep_LineInter.def("Curve", (opencascade::handle<Geom_Curve> (TopOpeBRep_LineInter::*)(const Standard_Real, const Standard_Real) const ) &TopOpeBRep_LineInter::Curve, "None", py::arg("parmin"), py::arg("parmax"));
	cls_TopOpeBRep_LineInter.def("Arc", (const TopoDS_Shape & (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::Arc, "returns the edge of a RESTRICTION line (or a null edge).");
	cls_TopOpeBRep_LineInter.def("ArcIsEdge", (Standard_Boolean (TopOpeBRep_LineInter::*)(const Standard_Integer) const ) &TopOpeBRep_LineInter::ArcIsEdge, "returns true if Arc() edge (of a RESTRICTION line) is an edge of the original face <Index> (1 or 2).", py::arg("I"));
	cls_TopOpeBRep_LineInter.def("LineW", (const opencascade::handle<IntPatch_WLine> & (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::LineW, "None");
	cls_TopOpeBRep_LineInter.def("LineG", (const opencascade::handle<IntPatch_GLine> & (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::LineG, "None");
	cls_TopOpeBRep_LineInter.def("LineR", (const opencascade::handle<IntPatch_RLine> & (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::LineR, "None");
	cls_TopOpeBRep_LineInter.def("HasFirstPoint", (Standard_Boolean (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::HasFirstPoint, "None");
	cls_TopOpeBRep_LineInter.def("HasLastPoint", (Standard_Boolean (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::HasLastPoint, "None");
	cls_TopOpeBRep_LineInter.def("ComputeFaceFaceTransition", (void (TopOpeBRep_LineInter::*)()) &TopOpeBRep_LineInter::ComputeFaceFaceTransition, "None");
	cls_TopOpeBRep_LineInter.def("FaceFaceTransition", (const TopOpeBRepDS_Transition & (TopOpeBRep_LineInter::*)(const Standard_Integer) const ) &TopOpeBRep_LineInter::FaceFaceTransition, "None", py::arg("I"));
	cls_TopOpeBRep_LineInter.def("Index", (void (TopOpeBRep_LineInter::*)(const Standard_Integer)) &TopOpeBRep_LineInter::Index, "None", py::arg("I"));
	cls_TopOpeBRep_LineInter.def("Index", (Standard_Integer (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::Index, "None");
	cls_TopOpeBRep_LineInter.def("DumpType", (void (TopOpeBRep_LineInter::*)() const ) &TopOpeBRep_LineInter::DumpType, "None");
	cls_TopOpeBRep_LineInter.def("DumpVPoint", (void (TopOpeBRep_LineInter::*)(const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &) const ) &TopOpeBRep_LineInter::DumpVPoint, "None", py::arg("I"), py::arg("s1"), py::arg("s2"));
	cls_TopOpeBRep_LineInter.def("DumpBipoint", (void (TopOpeBRep_LineInter::*)(const TopOpeBRep_Bipoint &, const TCollection_AsciiString &, const TCollection_AsciiString &) const ) &TopOpeBRep_LineInter::DumpBipoint, "None", py::arg("B"), py::arg("s1"), py::arg("s2"));
	cls_TopOpeBRep_LineInter.def("SetTraceIndex", (void (TopOpeBRep_LineInter::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_LineInter::SetTraceIndex, "None", py::arg("exF1"), py::arg("exF2"));
	cls_TopOpeBRep_LineInter.def("GetTraceIndex", (void (TopOpeBRep_LineInter::*)(Standard_Integer &, Standard_Integer &) const ) &TopOpeBRep_LineInter::GetTraceIndex, "None", py::arg("exF1"), py::arg("exF2"));
	cls_TopOpeBRep_LineInter.def("DumpLineTransitions", (Standard_OStream & (TopOpeBRep_LineInter::*)(Standard_OStream &) const ) &TopOpeBRep_LineInter::DumpLineTransitions, "None", py::arg("OS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TopOpeBRep_Array1OfLineInter, std::unique_ptr<TopOpeBRep_Array1OfLineInter, Deleter<TopOpeBRep_Array1OfLineInter>>> cls_TopOpeBRep_Array1OfLineInter(mod, "TopOpeBRep_Array1OfLineInter", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TopOpeBRep_Array1OfLineInter.def(py::init<>());
	cls_TopOpeBRep_Array1OfLineInter.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TopOpeBRep_Array1OfLineInter.def(py::init([] (const TopOpeBRep_Array1OfLineInter &other) {return new TopOpeBRep_Array1OfLineInter(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TopOpeBRep_Array1OfLineInter.def(py::init<TopOpeBRep_Array1OfLineInter &&>(), py::arg("theOther"));
	cls_TopOpeBRep_Array1OfLineInter.def(py::init<const TopOpeBRep_LineInter &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TopOpeBRep_Array1OfLineInter.def("begin", (TopOpeBRep_Array1OfLineInter::iterator (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TopOpeBRep_Array1OfLineInter.def("end", (TopOpeBRep_Array1OfLineInter::iterator (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TopOpeBRep_Array1OfLineInter.def("cbegin", (TopOpeBRep_Array1OfLineInter::const_iterator (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TopOpeBRep_Array1OfLineInter.def("cend", (TopOpeBRep_Array1OfLineInter::const_iterator (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TopOpeBRep_Array1OfLineInter.def("Init", (void (TopOpeBRep_Array1OfLineInter::*)(const TopOpeBRep_LineInter &)) &TopOpeBRep_Array1OfLineInter::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TopOpeBRep_Array1OfLineInter.def("Size", (Standard_Integer (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::Size, "Size query");
	cls_TopOpeBRep_Array1OfLineInter.def("Length", (Standard_Integer (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::Length, "Length query (the same)");
	cls_TopOpeBRep_Array1OfLineInter.def("IsEmpty", (Standard_Boolean (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::IsEmpty, "Return TRUE if array has zero length.");
	cls_TopOpeBRep_Array1OfLineInter.def("Lower", (Standard_Integer (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::Lower, "Lower bound");
	cls_TopOpeBRep_Array1OfLineInter.def("Upper", (Standard_Integer (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::Upper, "Upper bound");
	cls_TopOpeBRep_Array1OfLineInter.def("IsDeletable", (Standard_Boolean (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::IsDeletable, "myDeletable flag");
	cls_TopOpeBRep_Array1OfLineInter.def("IsAllocated", (Standard_Boolean (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TopOpeBRep_Array1OfLineInter.def("Assign", (TopOpeBRep_Array1OfLineInter & (TopOpeBRep_Array1OfLineInter::*)(const TopOpeBRep_Array1OfLineInter &)) &TopOpeBRep_Array1OfLineInter::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TopOpeBRep_Array1OfLineInter.def("Move", (TopOpeBRep_Array1OfLineInter & (TopOpeBRep_Array1OfLineInter::*)(TopOpeBRep_Array1OfLineInter &&)) &TopOpeBRep_Array1OfLineInter::Move, "Move assignment", py::arg("theOther"));
	cls_TopOpeBRep_Array1OfLineInter.def("assign", (TopOpeBRep_Array1OfLineInter & (TopOpeBRep_Array1OfLineInter::*)(const TopOpeBRep_Array1OfLineInter &)) &TopOpeBRep_Array1OfLineInter::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TopOpeBRep_Array1OfLineInter.def("assign", (TopOpeBRep_Array1OfLineInter & (TopOpeBRep_Array1OfLineInter::*)(TopOpeBRep_Array1OfLineInter &&)) &TopOpeBRep_Array1OfLineInter::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TopOpeBRep_Array1OfLineInter.def("First", (const TopOpeBRep_LineInter & (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::First, "Returns first element");
	cls_TopOpeBRep_Array1OfLineInter.def("ChangeFirst", (TopOpeBRep_LineInter & (TopOpeBRep_Array1OfLineInter::*)()) &TopOpeBRep_Array1OfLineInter::ChangeFirst, "Returns first element");
	cls_TopOpeBRep_Array1OfLineInter.def("Last", (const TopOpeBRep_LineInter & (TopOpeBRep_Array1OfLineInter::*)() const ) &TopOpeBRep_Array1OfLineInter::Last, "Returns last element");
	cls_TopOpeBRep_Array1OfLineInter.def("ChangeLast", (TopOpeBRep_LineInter & (TopOpeBRep_Array1OfLineInter::*)()) &TopOpeBRep_Array1OfLineInter::ChangeLast, "Returns last element");
	cls_TopOpeBRep_Array1OfLineInter.def("Value", (const TopOpeBRep_LineInter & (TopOpeBRep_Array1OfLineInter::*)(const Standard_Integer) const ) &TopOpeBRep_Array1OfLineInter::Value, "Constant value access", py::arg("theIndex"));
	cls_TopOpeBRep_Array1OfLineInter.def("__call__", (const TopOpeBRep_LineInter & (TopOpeBRep_Array1OfLineInter::*)(const Standard_Integer) const ) &TopOpeBRep_Array1OfLineInter::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TopOpeBRep_Array1OfLineInter.def("ChangeValue", (TopOpeBRep_LineInter & (TopOpeBRep_Array1OfLineInter::*)(const Standard_Integer)) &TopOpeBRep_Array1OfLineInter::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TopOpeBRep_Array1OfLineInter.def("__call__", (TopOpeBRep_LineInter & (TopOpeBRep_Array1OfLineInter::*)(const Standard_Integer)) &TopOpeBRep_Array1OfLineInter::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TopOpeBRep_Array1OfLineInter.def("SetValue", (void (TopOpeBRep_Array1OfLineInter::*)(const Standard_Integer, const TopOpeBRep_LineInter &)) &TopOpeBRep_Array1OfLineInter::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TopOpeBRep_Array1OfLineInter.def("Resize", (void (TopOpeBRep_Array1OfLineInter::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TopOpeBRep_Array1OfLineInter::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TopOpeBRep_Array1OfLineInter.def("__iter__", [](const TopOpeBRep_Array1OfLineInter &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_FacesIntersector.hxx
	py::class_<TopOpeBRep_FacesIntersector, std::unique_ptr<TopOpeBRep_FacesIntersector, Deleter<TopOpeBRep_FacesIntersector>>> cls_TopOpeBRep_FacesIntersector(mod, "TopOpeBRep_FacesIntersector", "Describes the intersection of two faces.");
	cls_TopOpeBRep_FacesIntersector.def(py::init<>());
	cls_TopOpeBRep_FacesIntersector.def("Perform", (void (TopOpeBRep_FacesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_FacesIntersector::Perform, "Computes the intersection of faces S1 and S2.", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRep_FacesIntersector.def("Perform", (void (TopOpeBRep_FacesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &)) &TopOpeBRep_FacesIntersector::Perform, "Computes the intersection of faces S1 and S2.", py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"));
	cls_TopOpeBRep_FacesIntersector.def("IsEmpty", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::IsEmpty, "None");
	cls_TopOpeBRep_FacesIntersector.def("IsDone", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)() const ) &TopOpeBRep_FacesIntersector::IsDone, "None");
	cls_TopOpeBRep_FacesIntersector.def("SameDomain", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)() const ) &TopOpeBRep_FacesIntersector::SameDomain, "Returns True if Perform() arguments are two faces with the same surface.");
	cls_TopOpeBRep_FacesIntersector.def("Face", (const TopoDS_Shape & (TopOpeBRep_FacesIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_FacesIntersector::Face, "returns first or second intersected face.", py::arg("Index"));
	cls_TopOpeBRep_FacesIntersector.def("SurfacesSameOriented", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)() const ) &TopOpeBRep_FacesIntersector::SurfacesSameOriented, "Returns True if Perform() arguments are two faces SameDomain() and normals on both side. Raise if SameDomain is False");
	cls_TopOpeBRep_FacesIntersector.def("IsRestriction", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)(const TopoDS_Shape &) const ) &TopOpeBRep_FacesIntersector::IsRestriction, "returns true if edge <E> is found as same as the edge associated with a RESTRICTION line.", py::arg("E"));
	cls_TopOpeBRep_FacesIntersector.def("Restrictions", (const TopTools_IndexedMapOfShape & (TopOpeBRep_FacesIntersector::*)() const ) &TopOpeBRep_FacesIntersector::Restrictions, "returns the map of edges found as TopeBRepBRep_RESTRICTION");
	cls_TopOpeBRep_FacesIntersector.def("PrepareLines", (void (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::PrepareLines, "None");
	cls_TopOpeBRep_FacesIntersector.def("Lines", (opencascade::handle<TopOpeBRep_HArray1OfLineInter> (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::Lines, "None");
	cls_TopOpeBRep_FacesIntersector.def("NbLines", (Standard_Integer (TopOpeBRep_FacesIntersector::*)() const ) &TopOpeBRep_FacesIntersector::NbLines, "None");
	cls_TopOpeBRep_FacesIntersector.def("InitLine", (void (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::InitLine, "None");
	cls_TopOpeBRep_FacesIntersector.def("MoreLine", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)() const ) &TopOpeBRep_FacesIntersector::MoreLine, "None");
	cls_TopOpeBRep_FacesIntersector.def("NextLine", (void (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::NextLine, "None");
	cls_TopOpeBRep_FacesIntersector.def("CurrentLine", (TopOpeBRep_LineInter & (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::CurrentLine, "None");
	cls_TopOpeBRep_FacesIntersector.def("CurrentLineIndex", (Standard_Integer (TopOpeBRep_FacesIntersector::*)() const ) &TopOpeBRep_FacesIntersector::CurrentLineIndex, "None");
	cls_TopOpeBRep_FacesIntersector.def("ChangeLine", (TopOpeBRep_LineInter & (TopOpeBRep_FacesIntersector::*)(const Standard_Integer)) &TopOpeBRep_FacesIntersector::ChangeLine, "None", py::arg("IL"));
	cls_TopOpeBRep_FacesIntersector.def("ForceTolerances", (void (TopOpeBRep_FacesIntersector::*)(const Standard_Real, const Standard_Real)) &TopOpeBRep_FacesIntersector::ForceTolerances, "Force the tolerance values used by the next Perform(S1,S2) call.", py::arg("tolarc"), py::arg("toltang"));
	cls_TopOpeBRep_FacesIntersector.def("GetTolerances", (void (TopOpeBRep_FacesIntersector::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRep_FacesIntersector::GetTolerances, "Return the tolerance values used in the last Perform() call If ForceTolerances() has been called, return the given values. If not, return values extracted from shapes.", py::arg("tolarc"), py::arg("toltang"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_Hctxff2d.hxx
	py::class_<TopOpeBRep_Hctxff2d, opencascade::handle<TopOpeBRep_Hctxff2d>, Standard_Transient> cls_TopOpeBRep_Hctxff2d(mod, "TopOpeBRep_Hctxff2d", "None");
	cls_TopOpeBRep_Hctxff2d.def(py::init<>());
	cls_TopOpeBRep_Hctxff2d.def("SetFaces", (void (TopOpeBRep_Hctxff2d::*)(const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRep_Hctxff2d::SetFaces, "None", py::arg("F1"), py::arg("F2"));
	cls_TopOpeBRep_Hctxff2d.def("SetHSurfaces", (void (TopOpeBRep_Hctxff2d::*)(const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HSurface> &)) &TopOpeBRep_Hctxff2d::SetHSurfaces, "None", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRep_Hctxff2d.def("SetTolerances", (void (TopOpeBRep_Hctxff2d::*)(const Standard_Real, const Standard_Real)) &TopOpeBRep_Hctxff2d::SetTolerances, "None", py::arg("Tol1"), py::arg("Tol2"));
	cls_TopOpeBRep_Hctxff2d.def("GetTolerances", (void (TopOpeBRep_Hctxff2d::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRep_Hctxff2d::GetTolerances, "None", py::arg("Tol1"), py::arg("Tol2"));
	cls_TopOpeBRep_Hctxff2d.def("GetMaxTolerance", (Standard_Real (TopOpeBRep_Hctxff2d::*)() const ) &TopOpeBRep_Hctxff2d::GetMaxTolerance, "None");
	cls_TopOpeBRep_Hctxff2d.def("Face", (const TopoDS_Face & (TopOpeBRep_Hctxff2d::*)(const Standard_Integer) const ) &TopOpeBRep_Hctxff2d::Face, "None", py::arg("I"));
	cls_TopOpeBRep_Hctxff2d.def("HSurface", (opencascade::handle<BRepAdaptor_HSurface> (TopOpeBRep_Hctxff2d::*)(const Standard_Integer) const ) &TopOpeBRep_Hctxff2d::HSurface, "None", py::arg("I"));
	cls_TopOpeBRep_Hctxff2d.def("SurfacesSameOriented", (Standard_Boolean (TopOpeBRep_Hctxff2d::*)() const ) &TopOpeBRep_Hctxff2d::SurfacesSameOriented, "None");
	cls_TopOpeBRep_Hctxff2d.def("FacesSameOriented", (Standard_Boolean (TopOpeBRep_Hctxff2d::*)() const ) &TopOpeBRep_Hctxff2d::FacesSameOriented, "None");
	cls_TopOpeBRep_Hctxff2d.def("FaceSameOrientedWithRef", (Standard_Boolean (TopOpeBRep_Hctxff2d::*)(const Standard_Integer) const ) &TopOpeBRep_Hctxff2d::FaceSameOrientedWithRef, "None", py::arg("I"));
	cls_TopOpeBRep_Hctxff2d.def_static("get_type_name_", (const char * (*)()) &TopOpeBRep_Hctxff2d::get_type_name, "None");
	cls_TopOpeBRep_Hctxff2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRep_Hctxff2d::get_type_descriptor, "None");
	cls_TopOpeBRep_Hctxff2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRep_Hctxff2d::*)() const ) &TopOpeBRep_Hctxff2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_Hctxee2d.hxx
	py::class_<TopOpeBRep_Hctxee2d, opencascade::handle<TopOpeBRep_Hctxee2d>, Standard_Transient> cls_TopOpeBRep_Hctxee2d(mod, "TopOpeBRep_Hctxee2d", "None");
	cls_TopOpeBRep_Hctxee2d.def(py::init<>());
	cls_TopOpeBRep_Hctxee2d.def("SetEdges", (void (TopOpeBRep_Hctxee2d::*)(const TopoDS_Edge &, const TopoDS_Edge &, const BRepAdaptor_Surface &, const BRepAdaptor_Surface &)) &TopOpeBRep_Hctxee2d::SetEdges, "None", py::arg("E1"), py::arg("E2"), py::arg("BAS1"), py::arg("BAS2"));
	cls_TopOpeBRep_Hctxee2d.def("Edge", (const TopoDS_Shape & (TopOpeBRep_Hctxee2d::*)(const Standard_Integer) const ) &TopOpeBRep_Hctxee2d::Edge, "None", py::arg("I"));
	cls_TopOpeBRep_Hctxee2d.def("Curve", (const Geom2dAdaptor_Curve & (TopOpeBRep_Hctxee2d::*)(const Standard_Integer) const ) &TopOpeBRep_Hctxee2d::Curve, "None", py::arg("I"));
	cls_TopOpeBRep_Hctxee2d.def("Domain", (const IntRes2d_Domain & (TopOpeBRep_Hctxee2d::*)(const Standard_Integer) const ) &TopOpeBRep_Hctxee2d::Domain, "None", py::arg("I"));
	cls_TopOpeBRep_Hctxee2d.def_static("get_type_name_", (const char * (*)()) &TopOpeBRep_Hctxee2d::get_type_name, "None");
	cls_TopOpeBRep_Hctxee2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRep_Hctxee2d::get_type_descriptor, "None");
	cls_TopOpeBRep_Hctxee2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRep_Hctxee2d::*)() const ) &TopOpeBRep_Hctxee2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_EdgesIntersector.hxx
	py::class_<TopOpeBRep_EdgesIntersector, std::unique_ptr<TopOpeBRep_EdgesIntersector, Deleter<TopOpeBRep_EdgesIntersector>>> cls_TopOpeBRep_EdgesIntersector(mod, "TopOpeBRep_EdgesIntersector", "Describes the intersection of two edges on the same surface");
	cls_TopOpeBRep_EdgesIntersector.def(py::init<>());
	cls_TopOpeBRep_EdgesIntersector.def("SetFaces", (void (TopOpeBRep_EdgesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_EdgesIntersector::SetFaces, "None", py::arg("F1"), py::arg("F2"));
	cls_TopOpeBRep_EdgesIntersector.def("SetFaces", (void (TopOpeBRep_EdgesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &)) &TopOpeBRep_EdgesIntersector::SetFaces, "None", py::arg("F1"), py::arg("F2"), py::arg("B1"), py::arg("B2"));
	cls_TopOpeBRep_EdgesIntersector.def("ForceTolerances", (void (TopOpeBRep_EdgesIntersector::*)(const Standard_Real, const Standard_Real)) &TopOpeBRep_EdgesIntersector::ForceTolerances, "None", py::arg("Tol1"), py::arg("Tol2"));
	cls_TopOpeBRep_EdgesIntersector.def("Dimension", (void (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer)) &TopOpeBRep_EdgesIntersector::Dimension, "None", py::arg("D"));
	cls_TopOpeBRep_EdgesIntersector.def("Dimension", (Standard_Integer (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::Dimension, "set working space dimension D = 1 for E &|| W, 2 for E in F");
	cls_TopOpeBRep_EdgesIntersector.def("Perform", [](TopOpeBRep_EdgesIntersector &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.Perform(a0, a1); }, py::arg("E1"), py::arg("E2"));
	cls_TopOpeBRep_EdgesIntersector.def("Perform", (void (TopOpeBRep_EdgesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRep_EdgesIntersector::Perform, "None", py::arg("E1"), py::arg("E2"), py::arg("ReduceSegments"));
	cls_TopOpeBRep_EdgesIntersector.def("IsEmpty", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)()) &TopOpeBRep_EdgesIntersector::IsEmpty, "None");
	cls_TopOpeBRep_EdgesIntersector.def("HasSegment", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::HasSegment, "true if at least one intersection segment.");
	cls_TopOpeBRep_EdgesIntersector.def("SameDomain", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::SameDomain, "= mySameDomain.");
	cls_TopOpeBRep_EdgesIntersector.def("Edge", (const TopoDS_Shape & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_EdgesIntersector::Edge, "None", py::arg("Index"));
	cls_TopOpeBRep_EdgesIntersector.def("Curve", (const Geom2dAdaptor_Curve & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_EdgesIntersector::Curve, "None", py::arg("Index"));
	cls_TopOpeBRep_EdgesIntersector.def("Face", (const TopoDS_Shape & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_EdgesIntersector::Face, "None", py::arg("Index"));
	cls_TopOpeBRep_EdgesIntersector.def("Surface", (const BRepAdaptor_Surface & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_EdgesIntersector::Surface, "None", py::arg("Index"));
	cls_TopOpeBRep_EdgesIntersector.def("SurfacesSameOriented", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::SurfacesSameOriented, "None");
	cls_TopOpeBRep_EdgesIntersector.def("FacesSameOriented", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::FacesSameOriented, "None");
	cls_TopOpeBRep_EdgesIntersector.def("ToleranceMax", (Standard_Real (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::ToleranceMax, "None");
	cls_TopOpeBRep_EdgesIntersector.def("Tolerances", (void (TopOpeBRep_EdgesIntersector::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRep_EdgesIntersector::Tolerances, "None", py::arg("tol1"), py::arg("tol2"));
	cls_TopOpeBRep_EdgesIntersector.def("NbPoints", (Standard_Integer (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::NbPoints, "None");
	cls_TopOpeBRep_EdgesIntersector.def("NbSegments", (Standard_Integer (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::NbSegments, "None");
	// FIXME cls_TopOpeBRep_EdgesIntersector.def("Dump", [](TopOpeBRep_EdgesIntersector &self, const TCollection_AsciiString & a0) -> void { return self.Dump(a0); }, py::arg("str"));
	// FIXME cls_TopOpeBRep_EdgesIntersector.def("Dump", [](TopOpeBRep_EdgesIntersector &self, const TCollection_AsciiString & a0, const Standard_Integer a1) -> void { return self.Dump(a0, a1); }, py::arg("str"), py::arg("ie1"));
	// FIXME cls_TopOpeBRep_EdgesIntersector.def("Dump", (void (TopOpeBRep_EdgesIntersector::*)(const TCollection_AsciiString &, const Standard_Integer, const Standard_Integer)) &TopOpeBRep_EdgesIntersector::Dump, "None", py::arg("str"), py::arg("ie1"), py::arg("ie2"));
	cls_TopOpeBRep_EdgesIntersector.def("InitPoint", [](TopOpeBRep_EdgesIntersector &self) -> void { return self.InitPoint(); });
	cls_TopOpeBRep_EdgesIntersector.def("InitPoint", (void (TopOpeBRep_EdgesIntersector::*)(const Standard_Boolean)) &TopOpeBRep_EdgesIntersector::InitPoint, "None", py::arg("selectkeep"));
	cls_TopOpeBRep_EdgesIntersector.def("MorePoint", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::MorePoint, "None");
	cls_TopOpeBRep_EdgesIntersector.def("NextPoint", (void (TopOpeBRep_EdgesIntersector::*)()) &TopOpeBRep_EdgesIntersector::NextPoint, "None");
	cls_TopOpeBRep_EdgesIntersector.def("Points", (const TopOpeBRep_SequenceOfPoint2d & (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::Points, "None");
	cls_TopOpeBRep_EdgesIntersector.def("Point", (const TopOpeBRep_Point2d & (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::Point, "None");
	cls_TopOpeBRep_EdgesIntersector.def("Point", (const TopOpeBRep_Point2d & (TopOpeBRep_EdgesIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_EdgesIntersector::Point, "None", py::arg("I"));
	cls_TopOpeBRep_EdgesIntersector.def("ReduceSegment", (Standard_Boolean (TopOpeBRep_EdgesIntersector::*)(TopOpeBRep_Point2d &, TopOpeBRep_Point2d &, TopOpeBRep_Point2d &) const ) &TopOpeBRep_EdgesIntersector::ReduceSegment, "None", py::arg("P1"), py::arg("P2"), py::arg("Pn"));
	cls_TopOpeBRep_EdgesIntersector.def("Status1", (TopOpeBRep_P2Dstatus (TopOpeBRep_EdgesIntersector::*)() const ) &TopOpeBRep_EdgesIntersector::Status1, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_Point2d.hxx
	py::class_<TopOpeBRep_Point2d, std::unique_ptr<TopOpeBRep_Point2d, Deleter<TopOpeBRep_Point2d>>> cls_TopOpeBRep_Point2d(mod, "TopOpeBRep_Point2d", "None");
	cls_TopOpeBRep_Point2d.def(py::init<>());
	// FIXME cls_TopOpeBRep_Point2d.def("Dump", [](TopOpeBRep_Point2d &self) -> void { return self.Dump(); });
	// FIXME cls_TopOpeBRep_Point2d.def("Dump", [](TopOpeBRep_Point2d &self, const Standard_Integer a0) -> void { return self.Dump(a0); }, py::arg("ie1"));
	// FIXME cls_TopOpeBRep_Point2d.def("Dump", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const Standard_Integer) const ) &TopOpeBRep_Point2d::Dump, "None", py::arg("ie1"), py::arg("ie2"));
	cls_TopOpeBRep_Point2d.def("SetPint", (void (TopOpeBRep_Point2d::*)(const IntRes2d_IntersectionPoint &)) &TopOpeBRep_Point2d::SetPint, "None", py::arg("P"));
	cls_TopOpeBRep_Point2d.def("HasPint", (Standard_Boolean (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::HasPint, "None");
	cls_TopOpeBRep_Point2d.def("Pint", (const IntRes2d_IntersectionPoint & (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::Pint, "None");
	cls_TopOpeBRep_Point2d.def("SetIsVertex", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRep_Point2d::SetIsVertex, "None", py::arg("I"), py::arg("B"));
	cls_TopOpeBRep_Point2d.def("IsVertex", (Standard_Boolean (TopOpeBRep_Point2d::*)(const Standard_Integer) const ) &TopOpeBRep_Point2d::IsVertex, "None", py::arg("I"));
	cls_TopOpeBRep_Point2d.def("SetVertex", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const TopoDS_Vertex &)) &TopOpeBRep_Point2d::SetVertex, "None", py::arg("I"), py::arg("V"));
	cls_TopOpeBRep_Point2d.def("Vertex", (const TopoDS_Vertex & (TopOpeBRep_Point2d::*)(const Standard_Integer) const ) &TopOpeBRep_Point2d::Vertex, "None", py::arg("I"));
	cls_TopOpeBRep_Point2d.def("SetTransition", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const TopOpeBRepDS_Transition &)) &TopOpeBRep_Point2d::SetTransition, "None", py::arg("I"), py::arg("T"));
	cls_TopOpeBRep_Point2d.def("Transition", (const TopOpeBRepDS_Transition & (TopOpeBRep_Point2d::*)(const Standard_Integer) const ) &TopOpeBRep_Point2d::Transition, "None", py::arg("I"));
	cls_TopOpeBRep_Point2d.def("ChangeTransition", (TopOpeBRepDS_Transition & (TopOpeBRep_Point2d::*)(const Standard_Integer)) &TopOpeBRep_Point2d::ChangeTransition, "None", py::arg("I"));
	cls_TopOpeBRep_Point2d.def("SetParameter", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const Standard_Real)) &TopOpeBRep_Point2d::SetParameter, "None", py::arg("I"), py::arg("P"));
	cls_TopOpeBRep_Point2d.def("Parameter", (Standard_Real (TopOpeBRep_Point2d::*)(const Standard_Integer) const ) &TopOpeBRep_Point2d::Parameter, "None", py::arg("I"));
	cls_TopOpeBRep_Point2d.def("SetIsPointOfSegment", (void (TopOpeBRep_Point2d::*)(const Standard_Boolean)) &TopOpeBRep_Point2d::SetIsPointOfSegment, "None", py::arg("B"));
	cls_TopOpeBRep_Point2d.def("IsPointOfSegment", (Standard_Boolean (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::IsPointOfSegment, "None");
	cls_TopOpeBRep_Point2d.def("SetSegmentAncestors", (void (TopOpeBRep_Point2d::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_Point2d::SetSegmentAncestors, "None", py::arg("IP1"), py::arg("IP2"));
	cls_TopOpeBRep_Point2d.def("SegmentAncestors", (Standard_Boolean (TopOpeBRep_Point2d::*)(Standard_Integer &, Standard_Integer &) const ) &TopOpeBRep_Point2d::SegmentAncestors, "None", py::arg("IP1"), py::arg("IP2"));
	cls_TopOpeBRep_Point2d.def("SetStatus", (void (TopOpeBRep_Point2d::*)(const TopOpeBRep_P2Dstatus)) &TopOpeBRep_Point2d::SetStatus, "None", py::arg("S"));
	cls_TopOpeBRep_Point2d.def("Status", (TopOpeBRep_P2Dstatus (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::Status, "None");
	cls_TopOpeBRep_Point2d.def("SetIndex", (void (TopOpeBRep_Point2d::*)(const Standard_Integer)) &TopOpeBRep_Point2d::SetIndex, "None", py::arg("X"));
	cls_TopOpeBRep_Point2d.def("Index", (Standard_Integer (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::Index, "None");
	cls_TopOpeBRep_Point2d.def("SetValue", (void (TopOpeBRep_Point2d::*)(const gp_Pnt &)) &TopOpeBRep_Point2d::SetValue, "None", py::arg("P"));
	cls_TopOpeBRep_Point2d.def("Value", (const gp_Pnt & (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::Value, "None");
	cls_TopOpeBRep_Point2d.def("SetValue2d", (void (TopOpeBRep_Point2d::*)(const gp_Pnt2d &)) &TopOpeBRep_Point2d::SetValue2d, "None", py::arg("P"));
	cls_TopOpeBRep_Point2d.def("Value2d", (const gp_Pnt2d & (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::Value2d, "None");
	cls_TopOpeBRep_Point2d.def("SetKeep", (void (TopOpeBRep_Point2d::*)(const Standard_Boolean)) &TopOpeBRep_Point2d::SetKeep, "None", py::arg("B"));
	cls_TopOpeBRep_Point2d.def("Keep", (Standard_Boolean (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::Keep, "None");
	cls_TopOpeBRep_Point2d.def("SetEdgesConfig", (void (TopOpeBRep_Point2d::*)(const TopOpeBRepDS_Config)) &TopOpeBRep_Point2d::SetEdgesConfig, "None", py::arg("C"));
	cls_TopOpeBRep_Point2d.def("EdgesConfig", (TopOpeBRepDS_Config (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::EdgesConfig, "None");
	cls_TopOpeBRep_Point2d.def("SetTolerance", (void (TopOpeBRep_Point2d::*)(const Standard_Real)) &TopOpeBRep_Point2d::SetTolerance, "None", py::arg("T"));
	cls_TopOpeBRep_Point2d.def("Tolerance", (Standard_Real (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::Tolerance, "None");
	cls_TopOpeBRep_Point2d.def("SetHctxff2d", (void (TopOpeBRep_Point2d::*)(const opencascade::handle<TopOpeBRep_Hctxff2d> &)) &TopOpeBRep_Point2d::SetHctxff2d, "None", py::arg("ff2d"));
	cls_TopOpeBRep_Point2d.def("Hctxff2d", (opencascade::handle<TopOpeBRep_Hctxff2d> (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::Hctxff2d, "None");
	cls_TopOpeBRep_Point2d.def("SetHctxee2d", (void (TopOpeBRep_Point2d::*)(const opencascade::handle<TopOpeBRep_Hctxee2d> &)) &TopOpeBRep_Point2d::SetHctxee2d, "None", py::arg("ee2d"));
	cls_TopOpeBRep_Point2d.def("Hctxee2d", (opencascade::handle<TopOpeBRep_Hctxee2d> (TopOpeBRep_Point2d::*)() const ) &TopOpeBRep_Point2d::Hctxee2d, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_FaceEdgeIntersector.hxx
	py::class_<TopOpeBRep_FaceEdgeIntersector, std::unique_ptr<TopOpeBRep_FaceEdgeIntersector, Deleter<TopOpeBRep_FaceEdgeIntersector>>> cls_TopOpeBRep_FaceEdgeIntersector(mod, "TopOpeBRep_FaceEdgeIntersector", "Describes the intersection of a face and an edge.");
	cls_TopOpeBRep_FaceEdgeIntersector.def(py::init<>());
	cls_TopOpeBRep_FaceEdgeIntersector.def("Perform", (void (TopOpeBRep_FaceEdgeIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_FaceEdgeIntersector::Perform, "None", py::arg("F"), py::arg("E"));
	cls_TopOpeBRep_FaceEdgeIntersector.def("IsEmpty", (Standard_Boolean (TopOpeBRep_FaceEdgeIntersector::*)()) &TopOpeBRep_FaceEdgeIntersector::IsEmpty, "None");
	cls_TopOpeBRep_FaceEdgeIntersector.def("Shape", (const TopoDS_Shape & (TopOpeBRep_FaceEdgeIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_FaceEdgeIntersector::Shape, "returns intersected face or edge according to value of <Index> = 1 or 2", py::arg("Index"));
	cls_TopOpeBRep_FaceEdgeIntersector.def("ForceTolerance", (void (TopOpeBRep_FaceEdgeIntersector::*)(const Standard_Real)) &TopOpeBRep_FaceEdgeIntersector::ForceTolerance, "Force the tolerance values used by the next Perform(S1,S2) call.", py::arg("tol"));
	cls_TopOpeBRep_FaceEdgeIntersector.def("Tolerance", (Standard_Real (TopOpeBRep_FaceEdgeIntersector::*)() const ) &TopOpeBRep_FaceEdgeIntersector::Tolerance, "Return the tolerance value used in the last Perform() call If ForceTolerance() has been called, return the given value. If not, return value extracted from shapes.");
	cls_TopOpeBRep_FaceEdgeIntersector.def("NbPoints", (Standard_Integer (TopOpeBRep_FaceEdgeIntersector::*)() const ) &TopOpeBRep_FaceEdgeIntersector::NbPoints, "None");
	cls_TopOpeBRep_FaceEdgeIntersector.def("InitPoint", (void (TopOpeBRep_FaceEdgeIntersector::*)()) &TopOpeBRep_FaceEdgeIntersector::InitPoint, "None");
	cls_TopOpeBRep_FaceEdgeIntersector.def("MorePoint", (Standard_Boolean (TopOpeBRep_FaceEdgeIntersector::*)() const ) &TopOpeBRep_FaceEdgeIntersector::MorePoint, "None");
	cls_TopOpeBRep_FaceEdgeIntersector.def("NextPoint", (void (TopOpeBRep_FaceEdgeIntersector::*)()) &TopOpeBRep_FaceEdgeIntersector::NextPoint, "None");
	cls_TopOpeBRep_FaceEdgeIntersector.def("Value", (gp_Pnt (TopOpeBRep_FaceEdgeIntersector::*)() const ) &TopOpeBRep_FaceEdgeIntersector::Value, "return the 3D point of the current intersection point.");
	cls_TopOpeBRep_FaceEdgeIntersector.def("Parameter", (Standard_Real (TopOpeBRep_FaceEdgeIntersector::*)() const ) &TopOpeBRep_FaceEdgeIntersector::Parameter, "parametre de Value() sur l'arete");
	cls_TopOpeBRep_FaceEdgeIntersector.def("UVPoint", (void (TopOpeBRep_FaceEdgeIntersector::*)(gp_Pnt2d &) const ) &TopOpeBRep_FaceEdgeIntersector::UVPoint, "parametre de Value() sur la face", py::arg("P"));
	cls_TopOpeBRep_FaceEdgeIntersector.def("State", (TopAbs_State (TopOpeBRep_FaceEdgeIntersector::*)() const ) &TopOpeBRep_FaceEdgeIntersector::State, "IN ou ON / a la face. Les points OUT ne sont pas retournes.");
	cls_TopOpeBRep_FaceEdgeIntersector.def("Transition", (TopOpeBRepDS_Transition (TopOpeBRep_FaceEdgeIntersector::*)(const Standard_Integer, const TopAbs_Orientation) const ) &TopOpeBRep_FaceEdgeIntersector::Transition, "Index = 1 transition par rapport a la face, en cheminant sur l'arete", py::arg("Index"), py::arg("FaceOrientation"));
	cls_TopOpeBRep_FaceEdgeIntersector.def("IsVertex", (Standard_Boolean (TopOpeBRep_FaceEdgeIntersector::*)(const TopoDS_Shape &, const gp_Pnt &, const Standard_Real, TopoDS_Vertex &)) &TopOpeBRep_FaceEdgeIntersector::IsVertex, "None", py::arg("S"), py::arg("P"), py::arg("Tol"), py::arg("V"));
	cls_TopOpeBRep_FaceEdgeIntersector.def("IsVertex", (Standard_Boolean (TopOpeBRep_FaceEdgeIntersector::*)(const Standard_Integer, TopoDS_Vertex &)) &TopOpeBRep_FaceEdgeIntersector::IsVertex, "None", py::arg("I"), py::arg("V"));
	cls_TopOpeBRep_FaceEdgeIntersector.def("Index", (Standard_Integer (TopOpeBRep_FaceEdgeIntersector::*)() const ) &TopOpeBRep_FaceEdgeIntersector::Index, "trace only");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_ShapeIntersector.hxx
	py::class_<TopOpeBRep_ShapeIntersector, std::unique_ptr<TopOpeBRep_ShapeIntersector, Deleter<TopOpeBRep_ShapeIntersector>>> cls_TopOpeBRep_ShapeIntersector(mod, "TopOpeBRep_ShapeIntersector", "Intersect two shapes.");
	cls_TopOpeBRep_ShapeIntersector.def(py::init<>());
	cls_TopOpeBRep_ShapeIntersector.def("InitIntersection", (void (TopOpeBRep_ShapeIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_ShapeIntersector::InitIntersection, "Initialize the intersection of shapes S1,S2.", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRep_ShapeIntersector.def("InitIntersection", (void (TopOpeBRep_ShapeIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Face &)) &TopOpeBRep_ShapeIntersector::InitIntersection, "Initialize the intersection of shapes S1,S2.", py::arg("S1"), py::arg("S2"), py::arg("F1"), py::arg("F2"));
	cls_TopOpeBRep_ShapeIntersector.def("Shape", (const TopoDS_Shape & (TopOpeBRep_ShapeIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_ShapeIntersector::Shape, "return the shape <Index> ( = 1 or 2) given to InitIntersection(). Index = 1 will return S1, Index = 2 will return S2.", py::arg("Index"));
	cls_TopOpeBRep_ShapeIntersector.def("MoreIntersection", (Standard_Boolean (TopOpeBRep_ShapeIntersector::*)() const ) &TopOpeBRep_ShapeIntersector::MoreIntersection, "returns True if there are more intersection between two the shapes.");
	cls_TopOpeBRep_ShapeIntersector.def("NextIntersection", (void (TopOpeBRep_ShapeIntersector::*)()) &TopOpeBRep_ShapeIntersector::NextIntersection, "search for the next intersection between the two shapes.");
	cls_TopOpeBRep_ShapeIntersector.def("ChangeFacesIntersector", (TopOpeBRep_FacesIntersector & (TopOpeBRep_ShapeIntersector::*)()) &TopOpeBRep_ShapeIntersector::ChangeFacesIntersector, "return the current intersection of two Faces.");
	cls_TopOpeBRep_ShapeIntersector.def("ChangeEdgesIntersector", (TopOpeBRep_EdgesIntersector & (TopOpeBRep_ShapeIntersector::*)()) &TopOpeBRep_ShapeIntersector::ChangeEdgesIntersector, "return the current intersection of two Edges.");
	cls_TopOpeBRep_ShapeIntersector.def("ChangeFaceEdgeIntersector", (TopOpeBRep_FaceEdgeIntersector & (TopOpeBRep_ShapeIntersector::*)()) &TopOpeBRep_ShapeIntersector::ChangeFaceEdgeIntersector, "return the current intersection of a Face and an Edge.");
	cls_TopOpeBRep_ShapeIntersector.def("CurrentGeomShape", (const TopoDS_Shape & (TopOpeBRep_ShapeIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_ShapeIntersector::CurrentGeomShape, "return geometric shape <Index> ( = 1 or 2 ) of current intersection.", py::arg("Index"));
	cls_TopOpeBRep_ShapeIntersector.def("GetTolerances", (void (TopOpeBRep_ShapeIntersector::*)(Standard_Real &, Standard_Real &) const ) &TopOpeBRep_ShapeIntersector::GetTolerances, "return MAX of intersection tolerances with which FacesIntersector from TopOpeBRep was working.", py::arg("tol1"), py::arg("tol2"));
	cls_TopOpeBRep_ShapeIntersector.def("DumpCurrent", (void (TopOpeBRep_ShapeIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_ShapeIntersector::DumpCurrent, "None", py::arg("K"));
	cls_TopOpeBRep_ShapeIntersector.def("Index", (Standard_Integer (TopOpeBRep_ShapeIntersector::*)(const Standard_Integer) const ) &TopOpeBRep_ShapeIntersector::Index, "None", py::arg("K"));
	cls_TopOpeBRep_ShapeIntersector.def("RejectedFaces", (void (TopOpeBRep_ShapeIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &)) &TopOpeBRep_ShapeIntersector::RejectedFaces, "None", py::arg("anObj"), py::arg("aReference"), py::arg("aListOfShape"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_ShapeIntersector2d.hxx
	py::class_<TopOpeBRep_ShapeIntersector2d, std::unique_ptr<TopOpeBRep_ShapeIntersector2d, Deleter<TopOpeBRep_ShapeIntersector2d>>> cls_TopOpeBRep_ShapeIntersector2d(mod, "TopOpeBRep_ShapeIntersector2d", "Intersect two shapes.");
	cls_TopOpeBRep_ShapeIntersector2d.def(py::init<>());
	cls_TopOpeBRep_ShapeIntersector2d.def("InitIntersection", (void (TopOpeBRep_ShapeIntersector2d::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_ShapeIntersector2d::InitIntersection, "Initialize the intersection of shapes S1,S2.", py::arg("S1"), py::arg("S2"));
	cls_TopOpeBRep_ShapeIntersector2d.def("Shape", (const TopoDS_Shape & (TopOpeBRep_ShapeIntersector2d::*)(const Standard_Integer) const ) &TopOpeBRep_ShapeIntersector2d::Shape, "return the shape <Index> ( = 1 or 2) given to InitIntersection(). Index = 1 will return S1, Index = 2 will return S2.", py::arg("Index"));
	cls_TopOpeBRep_ShapeIntersector2d.def("MoreIntersection", (Standard_Boolean (TopOpeBRep_ShapeIntersector2d::*)() const ) &TopOpeBRep_ShapeIntersector2d::MoreIntersection, "returns True if there are more intersection between two the shapes.");
	cls_TopOpeBRep_ShapeIntersector2d.def("NextIntersection", (void (TopOpeBRep_ShapeIntersector2d::*)()) &TopOpeBRep_ShapeIntersector2d::NextIntersection, "search for the next intersection between the two shapes.");
	cls_TopOpeBRep_ShapeIntersector2d.def("ChangeEdgesIntersector", (TopOpeBRep_EdgesIntersector & (TopOpeBRep_ShapeIntersector2d::*)()) &TopOpeBRep_ShapeIntersector2d::ChangeEdgesIntersector, "return the current intersection of two Edges.");
	cls_TopOpeBRep_ShapeIntersector2d.def("CurrentGeomShape", (const TopoDS_Shape & (TopOpeBRep_ShapeIntersector2d::*)(const Standard_Integer) const ) &TopOpeBRep_ShapeIntersector2d::CurrentGeomShape, "return geometric shape <Index> ( = 1 or 2 ) of current intersection.", py::arg("Index"));
	cls_TopOpeBRep_ShapeIntersector2d.def("DumpCurrent", (void (TopOpeBRep_ShapeIntersector2d::*)(const Standard_Integer) const ) &TopOpeBRep_ShapeIntersector2d::DumpCurrent, "None", py::arg("K"));
	cls_TopOpeBRep_ShapeIntersector2d.def("Index", (Standard_Integer (TopOpeBRep_ShapeIntersector2d::*)(const Standard_Integer) const ) &TopOpeBRep_ShapeIntersector2d::Index, "None", py::arg("K"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_PointClassifier.hxx
	py::class_<TopOpeBRep_PointClassifier, std::unique_ptr<TopOpeBRep_PointClassifier, Deleter<TopOpeBRep_PointClassifier>>> cls_TopOpeBRep_PointClassifier(mod, "TopOpeBRep_PointClassifier", "None");
	cls_TopOpeBRep_PointClassifier.def(py::init<>());
	cls_TopOpeBRep_PointClassifier.def("Init", (void (TopOpeBRep_PointClassifier::*)()) &TopOpeBRep_PointClassifier::Init, "None");
	cls_TopOpeBRep_PointClassifier.def("Load", (void (TopOpeBRep_PointClassifier::*)(const TopoDS_Face &)) &TopOpeBRep_PointClassifier::Load, "None", py::arg("F"));
	cls_TopOpeBRep_PointClassifier.def("Classify", (TopAbs_State (TopOpeBRep_PointClassifier::*)(const TopoDS_Face &, const gp_Pnt2d &, const Standard_Real)) &TopOpeBRep_PointClassifier::Classify, "compute position of point <P> regarding with the face <F>.", py::arg("F"), py::arg("P"), py::arg("Tol"));
	cls_TopOpeBRep_PointClassifier.def("State", (TopAbs_State (TopOpeBRep_PointClassifier::*)() const ) &TopOpeBRep_PointClassifier::State, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_FFDumper.hxx
	py::class_<TopOpeBRep_FFDumper, opencascade::handle<TopOpeBRep_FFDumper>, Standard_Transient> cls_TopOpeBRep_FFDumper(mod, "TopOpeBRep_FFDumper", "None");
	cls_TopOpeBRep_FFDumper.def(py::init<const TopOpeBRep_PFacesFiller &>(), py::arg("PFF"));
	cls_TopOpeBRep_FFDumper.def("Init", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_PFacesFiller &)) &TopOpeBRep_FFDumper::Init, "None", py::arg("PFF"));
	cls_TopOpeBRep_FFDumper.def("DumpLine", (void (TopOpeBRep_FFDumper::*)(const Standard_Integer)) &TopOpeBRep_FFDumper::DumpLine, "None", py::arg("I"));
	cls_TopOpeBRep_FFDumper.def("DumpLine", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_LineInter &)) &TopOpeBRep_FFDumper::DumpLine, "None", py::arg("L"));
	cls_TopOpeBRep_FFDumper.def("DumpVP", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_VPointInter &)) &TopOpeBRep_FFDumper::DumpVP, "None", py::arg("VP"));
	cls_TopOpeBRep_FFDumper.def("DumpVP", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_VPointInter &, const Standard_Integer)) &TopOpeBRep_FFDumper::DumpVP, "None", py::arg("VP"), py::arg("ISI"));
	cls_TopOpeBRep_FFDumper.def("ExploreIndex", (Standard_Integer (TopOpeBRep_FFDumper::*)(const TopoDS_Shape &, const Standard_Integer) const ) &TopOpeBRep_FFDumper::ExploreIndex, "None", py::arg("S"), py::arg("ISI"));
	cls_TopOpeBRep_FFDumper.def("DumpDSP", (void (TopOpeBRep_FFDumper::*)(const TopOpeBRep_VPointInter &, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Boolean) const ) &TopOpeBRep_FFDumper::DumpDSP, "None", py::arg("VP"), py::arg("GK"), py::arg("G"), py::arg("newinDS"));
	cls_TopOpeBRep_FFDumper.def("PFacesFillerDummy", (TopOpeBRep_PFacesFiller (TopOpeBRep_FFDumper::*)() const ) &TopOpeBRep_FFDumper::PFacesFillerDummy, "None");
	cls_TopOpeBRep_FFDumper.def_static("get_type_name_", (const char * (*)()) &TopOpeBRep_FFDumper::get_type_name, "None");
	cls_TopOpeBRep_FFDumper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRep_FFDumper::get_type_descriptor, "None");
	cls_TopOpeBRep_FFDumper.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRep_FFDumper::*)() const ) &TopOpeBRep_FFDumper::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_VPointInterClassifier.hxx
	py::class_<TopOpeBRep_VPointInterClassifier, std::unique_ptr<TopOpeBRep_VPointInterClassifier, Deleter<TopOpeBRep_VPointInterClassifier>>> cls_TopOpeBRep_VPointInterClassifier(mod, "TopOpeBRep_VPointInterClassifier", "None");
	cls_TopOpeBRep_VPointInterClassifier.def(py::init<>());
	cls_TopOpeBRep_VPointInterClassifier.def("VPointPosition", (TopAbs_State (TopOpeBRep_VPointInterClassifier::*)(const TopoDS_Shape &, TopOpeBRep_VPointInter &, const Standard_Integer, TopOpeBRep_PointClassifier &, const Standard_Boolean, const Standard_Real)) &TopOpeBRep_VPointInterClassifier::VPointPosition, "compute position of VPoint <VP> regarding with face <F>. <ShapeIndex> (= 1,2) indicates which (u,v) point of <VP> is used. when state is ON, set VP.EdgeON() with the edge containing <VP> and associated parameter. returns state of VP on ShapeIndex.", py::arg("F"), py::arg("VP"), py::arg("ShapeIndex"), py::arg("PC"), py::arg("AssumeINON"), py::arg("Tol"));
	cls_TopOpeBRep_VPointInterClassifier.def("Edge", (const TopoDS_Shape & (TopOpeBRep_VPointInterClassifier::*)() const ) &TopOpeBRep_VPointInterClassifier::Edge, "returns the edge containing the VPoint <VP> used in the last VPointPosition() call. Edge is defined if the state previously computed is ON, else Edge is a null shape.");
	cls_TopOpeBRep_VPointInterClassifier.def("EdgeParameter", (Standard_Real (TopOpeBRep_VPointInterClassifier::*)() const ) &TopOpeBRep_VPointInterClassifier::EdgeParameter, "returns the parameter of the VPoint <VP> on Edge()");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_VPointInterIterator.hxx
	py::class_<TopOpeBRep_VPointInterIterator, std::unique_ptr<TopOpeBRep_VPointInterIterator, Deleter<TopOpeBRep_VPointInterIterator>>> cls_TopOpeBRep_VPointInterIterator(mod, "TopOpeBRep_VPointInterIterator", "None");
	cls_TopOpeBRep_VPointInterIterator.def(py::init<>());
	cls_TopOpeBRep_VPointInterIterator.def(py::init<const TopOpeBRep_LineInter &>(), py::arg("LI"));
	cls_TopOpeBRep_VPointInterIterator.def("Init", [](TopOpeBRep_VPointInterIterator &self, const TopOpeBRep_LineInter & a0) -> void { return self.Init(a0); }, py::arg("LI"));
	cls_TopOpeBRep_VPointInterIterator.def("Init", (void (TopOpeBRep_VPointInterIterator::*)(const TopOpeBRep_LineInter &, const Standard_Boolean)) &TopOpeBRep_VPointInterIterator::Init, "None", py::arg("LI"), py::arg("checkkeep"));
	cls_TopOpeBRep_VPointInterIterator.def("Init", (void (TopOpeBRep_VPointInterIterator::*)()) &TopOpeBRep_VPointInterIterator::Init, "None");
	cls_TopOpeBRep_VPointInterIterator.def("More", (Standard_Boolean (TopOpeBRep_VPointInterIterator::*)() const ) &TopOpeBRep_VPointInterIterator::More, "None");
	cls_TopOpeBRep_VPointInterIterator.def("Next", (void (TopOpeBRep_VPointInterIterator::*)()) &TopOpeBRep_VPointInterIterator::Next, "None");
	cls_TopOpeBRep_VPointInterIterator.def("CurrentVP", (const TopOpeBRep_VPointInter & (TopOpeBRep_VPointInterIterator::*)()) &TopOpeBRep_VPointInterIterator::CurrentVP, "None");
	cls_TopOpeBRep_VPointInterIterator.def("CurrentVPIndex", (Standard_Integer (TopOpeBRep_VPointInterIterator::*)() const ) &TopOpeBRep_VPointInterIterator::CurrentVPIndex, "None");
	cls_TopOpeBRep_VPointInterIterator.def("ChangeCurrentVP", (TopOpeBRep_VPointInter & (TopOpeBRep_VPointInterIterator::*)()) &TopOpeBRep_VPointInterIterator::ChangeCurrentVP, "None");
	cls_TopOpeBRep_VPointInterIterator.def("PLineInterDummy", (TopOpeBRep_PLineInter (TopOpeBRep_VPointInterIterator::*)() const ) &TopOpeBRep_VPointInterIterator::PLineInterDummy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_FacesFiller.hxx
	py::class_<TopOpeBRep_FacesFiller, std::unique_ptr<TopOpeBRep_FacesFiller, Deleter<TopOpeBRep_FacesFiller>>> cls_TopOpeBRep_FacesFiller(mod, "TopOpeBRep_FacesFiller", "Fills a DataStructure from TopOpeBRepDS with the result of Face/Face instersection described by FacesIntersector from TopOpeBRep. if the faces have same Domain, record it in the DS. else record lines and points and attach list of interferences to the faces, the lines and the edges.");
	cls_TopOpeBRep_FacesFiller.def(py::init<>());
	cls_TopOpeBRep_FacesFiller.def("Insert", (void (TopOpeBRep_FacesFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopOpeBRep_FacesIntersector &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_FacesFiller::Insert, "Stores in <DS> the intersections of <S1> and <S2>.", py::arg("F1"), py::arg("F2"), py::arg("FACINT"), py::arg("HDS"));
	cls_TopOpeBRep_FacesFiller.def("ProcessSectionEdges", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ProcessSectionEdges, "None");
	cls_TopOpeBRep_FacesFiller.def("ChangePointClassifier", (TopOpeBRep_PointClassifier & (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ChangePointClassifier, "None");
	cls_TopOpeBRep_FacesFiller.def("PShapeClassifier", (TopOpeBRepTool_PShapeClassifier (TopOpeBRep_FacesFiller::*)() const ) &TopOpeBRep_FacesFiller::PShapeClassifier, "return field myPShapeClassifier.");
	cls_TopOpeBRep_FacesFiller.def("SetPShapeClassifier", (void (TopOpeBRep_FacesFiller::*)(const TopOpeBRepTool_PShapeClassifier &)) &TopOpeBRep_FacesFiller::SetPShapeClassifier, "set field myPShapeClassifier.", py::arg("PSC"));
	cls_TopOpeBRep_FacesFiller.def("LoadLine", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::LoadLine, "None", py::arg("L"));
	cls_TopOpeBRep_FacesFiller.def("CheckLine", (Standard_Boolean (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &) const ) &TopOpeBRep_FacesFiller::CheckLine, "None", py::arg("L"));
	cls_TopOpeBRep_FacesFiller.def("VP_Position", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_FacesIntersector &)) &TopOpeBRep_FacesFiller::VP_Position, "compute position of VPoints of lines", py::arg("FACINT"));
	cls_TopOpeBRep_FacesFiller.def("VP_Position", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::VP_Position, "compute position of VPoints of line L", py::arg("L"));
	cls_TopOpeBRep_FacesFiller.def("VP_PositionOnL", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::VP_PositionOnL, "compute position of VPoints of non-restriction line L.", py::arg("L"));
	cls_TopOpeBRep_FacesFiller.def("VP_PositionOnR", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::VP_PositionOnR, "compute position of VPoints of restriction line L.", py::arg("L"));
	cls_TopOpeBRep_FacesFiller.def("VP_Position", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_VPointInter &, TopOpeBRep_VPointInterClassifier &)) &TopOpeBRep_FacesFiller::VP_Position, "compute position of VP with current faces, according to VP.ShapeIndex() .", py::arg("VP"), py::arg("VPC"));
	cls_TopOpeBRep_FacesFiller.def("ProcessLine", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ProcessLine, "Process current intersection line (set by LoadLine)");
	cls_TopOpeBRep_FacesFiller.def("ResetDSC", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ResetDSC, "None");
	cls_TopOpeBRep_FacesFiller.def("ProcessRLine", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ProcessRLine, "Process current restriction line, adding restriction edge and computing face/edge interference.");
	cls_TopOpeBRep_FacesFiller.def("FillLineVPonR", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::FillLineVPonR, "VP processing for restriction line and line sharing same domain with section edges : - if restriction : Adds restriction edges as section edges and compute face/edge interference. - if same domain : If line share same domain with section edges, compute parts of line IN/IN the two faces, and compute curve/point interference for VP boundaries.");
	cls_TopOpeBRep_FacesFiller.def("FillLine", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::FillLine, "None");
	cls_TopOpeBRep_FacesFiller.def("AddShapesLine", (void (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::AddShapesLine, "compute 3d curve, pcurves and face/curve interferences for current NDSC. Add them to the DS.");
	cls_TopOpeBRep_FacesFiller.def("GetESL", (void (TopOpeBRep_FacesFiller::*)(TopTools_ListOfShape &)) &TopOpeBRep_FacesFiller::GetESL, "Get map <mapES > of restriction edges having parts IN one of the 2 faces.", py::arg("LES"));
	cls_TopOpeBRep_FacesFiller.def("ProcessVPR", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_FacesFiller &, const TopOpeBRep_VPointInter &)) &TopOpeBRep_FacesFiller::ProcessVPR, "calling the followings ProcessVPIonR and ProcessVPonR.", py::arg("FF"), py::arg("VP"));
	cls_TopOpeBRep_FacesFiller.def("ProcessVPIonR", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_VPointInterIterator &, const TopOpeBRepDS_Transition &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRep_FacesFiller::ProcessVPIonR, "processing ProcessVPonR for VPI.", py::arg("VPI"), py::arg("trans1"), py::arg("F1"), py::arg("ShapeIndex"));
	cls_TopOpeBRep_FacesFiller.def("ProcessVPonR", (void (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &, const TopOpeBRepDS_Transition &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRep_FacesFiller::ProcessVPonR, "adds <VP>'s geometric point (if not stored) and computes (curve or edge)/(point or vertex) interference.", py::arg("VP"), py::arg("trans1"), py::arg("F1"), py::arg("ShapeIndex"));
	cls_TopOpeBRep_FacesFiller.def("ProcessVPonclosingR", (void (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &, const TopoDS_Shape &, const Standard_Integer, const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const Standard_Boolean, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRep_FacesFiller::ProcessVPonclosingR, "VP processing on closing arc.", py::arg("VP"), py::arg("F1"), py::arg("ShapeIndex"), py::arg("transEdge"), py::arg("PVKind"), py::arg("PVIndex"), py::arg("EPIfound"), py::arg("IEPI"));
	cls_TopOpeBRep_FacesFiller.def("ProcessVPondgE", (Standard_Boolean (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &, const Standard_Integer, TopOpeBRepDS_Kind &, Standard_Integer &, Standard_Boolean &, opencascade::handle<TopOpeBRepDS_Interference> &, Standard_Boolean &, opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRep_FacesFiller::ProcessVPondgE, "VP processing on degenerated arc.", py::arg("VP"), py::arg("ShapeIndex"), py::arg("PVKind"), py::arg("PVIndex"), py::arg("EPIfound"), py::arg("IEPI"), py::arg("CPIfound"), py::arg("ICPI"));
	cls_TopOpeBRep_FacesFiller.def("ProcessVPInotonR", (void (TopOpeBRep_FacesFiller::*)(TopOpeBRep_VPointInterIterator &)) &TopOpeBRep_FacesFiller::ProcessVPInotonR, "processing ProcessVPnotonR for VPI.", py::arg("VPI"));
	cls_TopOpeBRep_FacesFiller.def("ProcessVPnotonR", (void (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &)) &TopOpeBRep_FacesFiller::ProcessVPnotonR, "adds <VP>'s geometrical point to the DS (if not stored) and computes curve point interference.", py::arg("VP"));
	cls_TopOpeBRep_FacesFiller.def("GetGeometry", (Standard_Boolean (TopOpeBRep_FacesFiller::*)(TopOpeBRepDS_ListIteratorOfListOfInterference &, const TopOpeBRep_VPointInter &, Standard_Integer &, TopOpeBRepDS_Kind &)) &TopOpeBRep_FacesFiller::GetGeometry, "Get the geometry of a DS point <DSP>. Search for it with ScanInterfList (previous method). if found, set <G> to the geometry of the interference found. else, add the point <DSP> in the <DS> and set <G> to the value of the new geometry such created. returns the value of ScanInterfList().", py::arg("IT"), py::arg("VP"), py::arg("G"), py::arg("K"));
	cls_TopOpeBRep_FacesFiller.def("MakeGeometry", (Standard_Integer (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &, const Standard_Integer, TopOpeBRepDS_Kind &)) &TopOpeBRep_FacesFiller::MakeGeometry, "None", py::arg("VP"), py::arg("ShapeIndex"), py::arg("K"));
	cls_TopOpeBRep_FacesFiller.def("StoreCurveInterference", (void (TopOpeBRep_FacesFiller::*)(const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRep_FacesFiller::StoreCurveInterference, "Add interference <I> to list myDSCIL. on a given line, at first call, add a new DS curve.", py::arg("I"));
	cls_TopOpeBRep_FacesFiller.def("GetFFGeometry", (Standard_Boolean (TopOpeBRep_FacesFiller::*)(const TopOpeBRepDS_Point &, TopOpeBRepDS_Kind &, Standard_Integer &) const ) &TopOpeBRep_FacesFiller::GetFFGeometry, "search for G = geometry of Point which is identical to <DSP> among the DS Points created in the CURRENT face/face intersection ( current Insert() call).", py::arg("DSP"), py::arg("K"), py::arg("G"));
	cls_TopOpeBRep_FacesFiller.def("GetFFGeometry", (Standard_Boolean (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_VPointInter &, TopOpeBRepDS_Kind &, Standard_Integer &) const ) &TopOpeBRep_FacesFiller::GetFFGeometry, "search for G = geometry of Point which is identical to <VP> among the DS Points created in the CURRENT face/face intersection ( current Insert() call).", py::arg("VP"), py::arg("K"), py::arg("G"));
	cls_TopOpeBRep_FacesFiller.def("ChangeFacesIntersector", (TopOpeBRep_FacesIntersector & (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ChangeFacesIntersector, "None");
	cls_TopOpeBRep_FacesFiller.def("HDataStructure", (opencascade::handle<TopOpeBRepDS_HDataStructure> (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::HDataStructure, "None");
	cls_TopOpeBRep_FacesFiller.def("ChangeDataStructure", (TopOpeBRepDS_DataStructure & (TopOpeBRep_FacesFiller::*)()) &TopOpeBRep_FacesFiller::ChangeDataStructure, "None");
	cls_TopOpeBRep_FacesFiller.def("Face", (const TopoDS_Face & (TopOpeBRep_FacesFiller::*)(const Standard_Integer) const ) &TopOpeBRep_FacesFiller::Face, "None", py::arg("I"));
	cls_TopOpeBRep_FacesFiller.def("FaceFaceTransition", (const TopOpeBRepDS_Transition & (TopOpeBRep_FacesFiller::*)(const TopOpeBRep_LineInter &, const Standard_Integer) const ) &TopOpeBRep_FacesFiller::FaceFaceTransition, "None", py::arg("L"), py::arg("I"));
	cls_TopOpeBRep_FacesFiller.def("FaceFaceTransition", (const TopOpeBRepDS_Transition & (TopOpeBRep_FacesFiller::*)(const Standard_Integer) const ) &TopOpeBRep_FacesFiller::FaceFaceTransition, "None", py::arg("I"));
	cls_TopOpeBRep_FacesFiller.def("PFacesIntersectorDummy", (TopOpeBRep_PFacesIntersector (TopOpeBRep_FacesFiller::*)() const ) &TopOpeBRep_FacesFiller::PFacesIntersectorDummy, "None");
	cls_TopOpeBRep_FacesFiller.def("PDataStructureDummy", (TopOpeBRepDS_PDataStructure (TopOpeBRep_FacesFiller::*)() const ) &TopOpeBRep_FacesFiller::PDataStructureDummy, "None");
	cls_TopOpeBRep_FacesFiller.def("PLineInterDummy", (TopOpeBRep_PLineInter (TopOpeBRep_FacesFiller::*)() const ) &TopOpeBRep_FacesFiller::PLineInterDummy, "None");
	cls_TopOpeBRep_FacesFiller.def("SetTraceIndex", (void (TopOpeBRep_FacesFiller::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_FacesFiller::SetTraceIndex, "None", py::arg("exF1"), py::arg("exF2"));
	cls_TopOpeBRep_FacesFiller.def("GetTraceIndex", (void (TopOpeBRep_FacesFiller::*)(Standard_Integer &, Standard_Integer &) const ) &TopOpeBRep_FacesFiller::GetTraceIndex, "None", py::arg("exF1"), py::arg("exF2"));
	cls_TopOpeBRep_FacesFiller.def_static("Lminmax_", (void (*)(const TopOpeBRep_LineInter &, Standard_Real &, Standard_Real &)) &TopOpeBRep_FacesFiller::Lminmax, "Computes <pmin> and <pmax> the upper and lower bounds of <L> enclosing all vpoints.", py::arg("L"), py::arg("pmin"), py::arg("pmax"));
	cls_TopOpeBRep_FacesFiller.def_static("LSameDomainERL_", (Standard_Boolean (*)(const TopOpeBRep_LineInter &, const TopTools_ListOfShape &)) &TopOpeBRep_FacesFiller::LSameDomainERL, "Returns <True> if <L> shares a same geometric domain with at least one of the section edges of <ERL>.", py::arg("L"), py::arg("ERL"));
	cls_TopOpeBRep_FacesFiller.def_static("IsVPtransLok_", (Standard_Boolean (*)(const TopOpeBRep_LineInter &, const Standard_Integer, const Standard_Integer, TopOpeBRepDS_Transition &)) &TopOpeBRep_FacesFiller::IsVPtransLok, "Computes the transition <T> of the VPoint <iVP> on the edge of <SI12>. Returns <False> if the status is unknown.", py::arg("L"), py::arg("iVP"), py::arg("SI12"), py::arg("T"));
	cls_TopOpeBRep_FacesFiller.def_static("TransvpOK_", (Standard_Boolean (*)(const TopOpeBRep_LineInter &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TopOpeBRep_FacesFiller::TransvpOK, "Computes transition on line for VP<iVP> on edge restriction of <SI>. If <isINOUT> : returns <true> if transition computed is IN/OUT else : returns <true> if transition computed is OUT/IN.", py::arg("L"), py::arg("iVP"), py::arg("SI"), py::arg("isINOUT"));
	cls_TopOpeBRep_FacesFiller.def_static("VPParamOnER_", (Standard_Real (*)(const TopOpeBRep_VPointInter &, const TopOpeBRep_LineInter &)) &TopOpeBRep_FacesFiller::VPParamOnER, "Returns parameter u of vp on the restriction edge.", py::arg("vp"), py::arg("Lrest"));
	cls_TopOpeBRep_FacesFiller.def_static("EqualpPonR_", (Standard_Boolean (*)(const TopOpeBRep_LineInter &, const TopOpeBRep_VPointInter &, const TopOpeBRep_VPointInter &)) &TopOpeBRep_FacesFiller::EqualpPonR, "None", py::arg("Lrest"), py::arg("VP1"), py::arg("VP2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_EdgesFiller.hxx
	py::class_<TopOpeBRep_EdgesFiller, std::unique_ptr<TopOpeBRep_EdgesFiller, Deleter<TopOpeBRep_EdgesFiller>>> cls_TopOpeBRep_EdgesFiller(mod, "TopOpeBRep_EdgesFiller", "Fills a TopOpeBRepDS_DataStructure with Edge/Edge instersection data described by TopOpeBRep_EdgesIntersector.");
	cls_TopOpeBRep_EdgesFiller.def(py::init<>());
	cls_TopOpeBRep_EdgesFiller.def("Insert", (void (TopOpeBRep_EdgesFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopOpeBRep_EdgesIntersector &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_EdgesFiller::Insert, "None", py::arg("E1"), py::arg("E2"), py::arg("EI"), py::arg("HDS"));
	cls_TopOpeBRep_EdgesFiller.def("Face", (void (TopOpeBRep_EdgesFiller::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRep_EdgesFiller::Face, "None", py::arg("I"), py::arg("F"));
	cls_TopOpeBRep_EdgesFiller.def("Face", (const TopoDS_Shape & (TopOpeBRep_EdgesFiller::*)(const Standard_Integer) const ) &TopOpeBRep_EdgesFiller::Face, "None", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_FaceEdgeFiller.hxx
	py::class_<TopOpeBRep_FaceEdgeFiller, std::unique_ptr<TopOpeBRep_FaceEdgeFiller, Deleter<TopOpeBRep_FaceEdgeFiller>>> cls_TopOpeBRep_FaceEdgeFiller(mod, "TopOpeBRep_FaceEdgeFiller", "None");
	cls_TopOpeBRep_FaceEdgeFiller.def(py::init<>());
	cls_TopOpeBRep_FaceEdgeFiller.def("Insert", (void (TopOpeBRep_FaceEdgeFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopOpeBRep_FaceEdgeIntersector &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_FaceEdgeFiller::Insert, "None", py::arg("F"), py::arg("E"), py::arg("FEINT"), py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_DSFiller.hxx
	py::class_<TopOpeBRep_DSFiller, std::unique_ptr<TopOpeBRep_DSFiller, Deleter<TopOpeBRep_DSFiller>>> cls_TopOpeBRep_DSFiller(mod, "TopOpeBRep_DSFiller", "Provides class methods to fill a datastructure with results of intersections.");
	cls_TopOpeBRep_DSFiller.def(py::init<>());
	cls_TopOpeBRep_DSFiller.def("PShapeClassifier", (TopOpeBRepTool_PShapeClassifier (TopOpeBRep_DSFiller::*)() const ) &TopOpeBRep_DSFiller::PShapeClassifier, "return field myPShapeClassifier. set field myPShapeClassifier.");
	cls_TopOpeBRep_DSFiller.def("Insert", [](TopOpeBRep_DSFiller &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a2) -> void { return self.Insert(a0, a1, a2); }, py::arg("S1"), py::arg("S2"), py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("Insert", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Boolean)) &TopOpeBRep_DSFiller::Insert, "Stores in <DS> the intersections of <S1> and <S2>. if orientFORWARD = True S FORWARD,REVERSED --> FORWARD S EXTERNAL,INTERNAL --> EXTERNAL,INTERNAL", py::arg("S1"), py::arg("S2"), py::arg("HDS"), py::arg("orientFORWARD"));
	cls_TopOpeBRep_DSFiller.def("InsertIntersection", [](TopOpeBRep_DSFiller &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a2) -> void { return self.InsertIntersection(a0, a1, a2); }, py::arg("S1"), py::arg("S2"), py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("InsertIntersection", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Boolean)) &TopOpeBRep_DSFiller::InsertIntersection, "Stores in <DS> the intersections of <S1> and <S2>. if orientFORWARD = True S FORWAR,REVERSED --> FORWARD S EXTERNAL,INTERNAL --> EXTERNAL,INTERNAL", py::arg("S1"), py::arg("S2"), py::arg("HDS"), py::arg("orientFORWARD"));
	cls_TopOpeBRep_DSFiller.def("Complete", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_DSFiller::Complete, "None", py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("Insert2d", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_DSFiller::Insert2d, "Stores in <DS> the intersections of <S1> and <S2>. S1 et S2 contain only SameDomain Face", py::arg("S1"), py::arg("S2"), py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("InsertIntersection2d", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_DSFiller::InsertIntersection2d, "S1, S2 set of tangent face lance les intersections 2d pour coder correctement les faces SameDomain.", py::arg("S1"), py::arg("S2"), py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("IsMadeOf1d", (Standard_Boolean (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &) const ) &TopOpeBRep_DSFiller::IsMadeOf1d, "None", py::arg("S"));
	cls_TopOpeBRep_DSFiller.def("IsContext1d", (Standard_Boolean (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &) const ) &TopOpeBRep_DSFiller::IsContext1d, "None", py::arg("S"));
	cls_TopOpeBRep_DSFiller.def("Insert1d", [](TopOpeBRep_DSFiller &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const TopoDS_Face & a2, const TopoDS_Face & a3, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a4) -> void { return self.Insert1d(a0, a1, a2, a3, a4); }, py::arg("S1"), py::arg("S2"), py::arg("F1"), py::arg("F2"), py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("Insert1d", (void (TopOpeBRep_DSFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Face &, const TopoDS_Face &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Boolean)) &TopOpeBRep_DSFiller::Insert1d, "Stores in <DS> the intersections of <S1> and <S2>. S1 and S2 are edges or wires. S1 edges have a 2d representation in face F1 S2 edges have a 2d representation in face F2 F1 is the face which surface is taken as reference for 2d description of S1 and S2 edges. if orientFORWARD = True S FORWARD,REVERSED --> FORWARD S EXTERNAL,INTERNAL --> EXTERNAL,INTERNAL", py::arg("S1"), py::arg("S2"), py::arg("F1"), py::arg("F2"), py::arg("HDS"), py::arg("orientFORWARD"));
	cls_TopOpeBRep_DSFiller.def("ChangeShapeIntersector", (TopOpeBRep_ShapeIntersector & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeShapeIntersector, "None");
	cls_TopOpeBRep_DSFiller.def("ChangeShapeIntersector2d", (TopOpeBRep_ShapeIntersector2d & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeShapeIntersector2d, "None");
	cls_TopOpeBRep_DSFiller.def("ChangeFacesFiller", (TopOpeBRep_FacesFiller & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeFacesFiller, "None");
	cls_TopOpeBRep_DSFiller.def("ChangeEdgesFiller", (TopOpeBRep_EdgesFiller & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeEdgesFiller, "None");
	cls_TopOpeBRep_DSFiller.def("ChangeFaceEdgeFiller", (TopOpeBRep_FaceEdgeFiller & (TopOpeBRep_DSFiller::*)()) &TopOpeBRep_DSFiller::ChangeFaceEdgeFiller, "None");
	cls_TopOpeBRep_DSFiller.def("GapFiller", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const ) &TopOpeBRep_DSFiller::GapFiller, "None", py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("CompleteDS", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const ) &TopOpeBRep_DSFiller::CompleteDS, "Update the data structure with relevant informations deduced from the intersections.", py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("Filter", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const ) &TopOpeBRep_DSFiller::Filter, "None", py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("Reducer", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const ) &TopOpeBRep_DSFiller::Reducer, "None", py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("RemoveUnsharedGeometry", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_DSFiller::RemoveUnsharedGeometry, "None", py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("Checker", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const ) &TopOpeBRep_DSFiller::Checker, "None", py::arg("HDS"));
	cls_TopOpeBRep_DSFiller.def("CompleteDS2d", (void (TopOpeBRep_DSFiller::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &) const ) &TopOpeBRep_DSFiller::CompleteDS2d, "Update the data structure with relevant informations deduced from the intersections 2d.", py::arg("HDS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_WPointInterIterator.hxx
	py::class_<TopOpeBRep_WPointInterIterator, std::unique_ptr<TopOpeBRep_WPointInterIterator, Deleter<TopOpeBRep_WPointInterIterator>>> cls_TopOpeBRep_WPointInterIterator(mod, "TopOpeBRep_WPointInterIterator", "None");
	cls_TopOpeBRep_WPointInterIterator.def(py::init<>());
	cls_TopOpeBRep_WPointInterIterator.def(py::init<const TopOpeBRep_LineInter &>(), py::arg("LI"));
	cls_TopOpeBRep_WPointInterIterator.def("Init", (void (TopOpeBRep_WPointInterIterator::*)(const TopOpeBRep_LineInter &)) &TopOpeBRep_WPointInterIterator::Init, "None", py::arg("LI"));
	cls_TopOpeBRep_WPointInterIterator.def("Init", (void (TopOpeBRep_WPointInterIterator::*)()) &TopOpeBRep_WPointInterIterator::Init, "None");
	cls_TopOpeBRep_WPointInterIterator.def("More", (Standard_Boolean (TopOpeBRep_WPointInterIterator::*)() const ) &TopOpeBRep_WPointInterIterator::More, "None");
	cls_TopOpeBRep_WPointInterIterator.def("Next", (void (TopOpeBRep_WPointInterIterator::*)()) &TopOpeBRep_WPointInterIterator::Next, "None");
	cls_TopOpeBRep_WPointInterIterator.def("CurrentWP", (const TopOpeBRep_WPointInter & (TopOpeBRep_WPointInterIterator::*)()) &TopOpeBRep_WPointInterIterator::CurrentWP, "None");
	cls_TopOpeBRep_WPointInterIterator.def("PLineInterDummy", (TopOpeBRep_PLineInter (TopOpeBRep_WPointInterIterator::*)() const ) &TopOpeBRep_WPointInterIterator::PLineInterDummy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_GeomTool.hxx
	py::class_<TopOpeBRep_GeomTool, std::unique_ptr<TopOpeBRep_GeomTool, Deleter<TopOpeBRep_GeomTool>>> cls_TopOpeBRep_GeomTool(mod, "TopOpeBRep_GeomTool", "Provide services needed by the DSFiller");
	cls_TopOpeBRep_GeomTool.def(py::init<>());
	cls_TopOpeBRep_GeomTool.def_static("MakeCurves_", (void (*)(const Standard_Real, const Standard_Real, const TopOpeBRep_LineInter &, const TopoDS_Shape &, const TopoDS_Shape &, TopOpeBRepDS_Curve &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &)) &TopOpeBRep_GeomTool::MakeCurves, "Make the DS curve <C> and the pcurves <PC1,PC2> from intersection line <L> lying on shapes <S1,S2>. <min,max> = <L> bounds", py::arg("min"), py::arg("max"), py::arg("L"), py::arg("S1"), py::arg("S2"), py::arg("C"), py::arg("PC1"), py::arg("PC2"));
	cls_TopOpeBRep_GeomTool.def_static("MakeCurve_", (void (*)(const Standard_Real, const Standard_Real, const TopOpeBRep_LineInter &, opencascade::handle<Geom_Curve> &)) &TopOpeBRep_GeomTool::MakeCurve, "None", py::arg("min"), py::arg("max"), py::arg("L"), py::arg("C"));
	cls_TopOpeBRep_GeomTool.def_static("MakeBSpline1fromWALKING3d_", (opencascade::handle<Geom_Curve> (*)(const TopOpeBRep_LineInter &)) &TopOpeBRep_GeomTool::MakeBSpline1fromWALKING3d, "None", py::arg("L"));
	cls_TopOpeBRep_GeomTool.def_static("MakeBSpline1fromWALKING2d_", (opencascade::handle<Geom2d_Curve> (*)(const TopOpeBRep_LineInter &, const Standard_Integer)) &TopOpeBRep_GeomTool::MakeBSpline1fromWALKING2d, "None", py::arg("L"), py::arg("SI"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_PointGeomTool.hxx
	py::class_<TopOpeBRep_PointGeomTool, std::unique_ptr<TopOpeBRep_PointGeomTool, Deleter<TopOpeBRep_PointGeomTool>>> cls_TopOpeBRep_PointGeomTool(mod, "TopOpeBRep_PointGeomTool", "Provide services needed by the Fillers");
	cls_TopOpeBRep_PointGeomTool.def(py::init<>());
	cls_TopOpeBRep_PointGeomTool.def_static("MakePoint_", (TopOpeBRepDS_Point (*)(const TopOpeBRep_VPointInter &)) &TopOpeBRep_PointGeomTool::MakePoint, "None", py::arg("IP"));
	cls_TopOpeBRep_PointGeomTool.def_static("MakePoint_", (TopOpeBRepDS_Point (*)(const TopOpeBRep_Point2d &)) &TopOpeBRep_PointGeomTool::MakePoint, "None", py::arg("P2D"));
	cls_TopOpeBRep_PointGeomTool.def_static("MakePoint_", (TopOpeBRepDS_Point (*)(const TopOpeBRep_FaceEdgeIntersector &)) &TopOpeBRep_PointGeomTool::MakePoint, "None", py::arg("FEI"));
	cls_TopOpeBRep_PointGeomTool.def_static("MakePoint_", (TopOpeBRepDS_Point (*)(const TopoDS_Shape &)) &TopOpeBRep_PointGeomTool::MakePoint, "None", py::arg("S"));
	cls_TopOpeBRep_PointGeomTool.def_static("IsEqual_", (Standard_Boolean (*)(const TopOpeBRepDS_Point &, const TopOpeBRepDS_Point &)) &TopOpeBRep_PointGeomTool::IsEqual, "None", py::arg("DSP1"), py::arg("DSP2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_FFTransitionTool.hxx
	py::class_<TopOpeBRep_FFTransitionTool, std::unique_ptr<TopOpeBRep_FFTransitionTool, Deleter<TopOpeBRep_FFTransitionTool>>> cls_TopOpeBRep_FFTransitionTool(mod, "TopOpeBRep_FFTransitionTool", "None");
	cls_TopOpeBRep_FFTransitionTool.def(py::init<>());
	cls_TopOpeBRep_FFTransitionTool.def_static("ProcessLineTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_VPointInter &, const Standard_Integer, const TopAbs_Orientation)) &TopOpeBRep_FFTransitionTool::ProcessLineTransition, "None", py::arg("P"), py::arg("Index"), py::arg("EdgeOrientation"));
	cls_TopOpeBRep_FFTransitionTool.def_static("ProcessLineTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_VPointInter &, const TopOpeBRep_LineInter &)) &TopOpeBRep_FFTransitionTool::ProcessLineTransition, "None", py::arg("P"), py::arg("L"));
	cls_TopOpeBRep_FFTransitionTool.def_static("ProcessEdgeTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_VPointInter &, const Standard_Integer, const TopAbs_Orientation)) &TopOpeBRep_FFTransitionTool::ProcessEdgeTransition, "None", py::arg("P"), py::arg("Index"), py::arg("LineOrientation"));
	cls_TopOpeBRep_FFTransitionTool.def_static("ProcessFaceTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_LineInter &, const Standard_Integer, const TopAbs_Orientation)) &TopOpeBRep_FFTransitionTool::ProcessFaceTransition, "None", py::arg("L"), py::arg("Index"), py::arg("FaceOrientation"));
	cls_TopOpeBRep_FFTransitionTool.def_static("ProcessEdgeONTransition_", (TopOpeBRepDS_Transition (*)(const TopOpeBRep_VPointInter &, const Standard_Integer, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_FFTransitionTool::ProcessEdgeONTransition, "compute transition on 'IntPatch_Restriction line' edge <R> when crossing edge <E> of face <F> at point <VP>. VP is given on edge <E> of face <F> of index <Index> (1 or 2). <VP> has been classified by FacesFiller as TopAbs_ON an edge <R> of the other face than <F> of current (face/face) intersection. Transition depends on the orientation of E in F. This method should be provided by IntPatch_Line (NYI)", py::arg("VP"), py::arg("Index"), py::arg("R"), py::arg("E"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep.hxx
	py::class_<TopOpeBRep, std::unique_ptr<TopOpeBRep, Deleter<TopOpeBRep>>> cls_TopOpeBRep(mod, "TopOpeBRep", "This package provides the topological operations on the BRep data structure.");
	cls_TopOpeBRep.def(py::init<>());
	cls_TopOpeBRep.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRep_TypeLineCurve, Standard_OStream &)) &TopOpeBRep::Print, "Prints the name of <TLC> as a String on the Stream <S> and returns <S>.", py::arg("TLC"), py::arg("OS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_PPntOn2S.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_PThePointOfIntersection.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_HArray1OfVPointInter.hxx
	py::class_<TopOpeBRep_HArray1OfVPointInter, opencascade::handle<TopOpeBRep_HArray1OfVPointInter>, TopOpeBRep_Array1OfVPointInter, Standard_Transient> cls_TopOpeBRep_HArray1OfVPointInter(mod, "TopOpeBRep_HArray1OfVPointInter", "None");
	cls_TopOpeBRep_HArray1OfVPointInter.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TopOpeBRep_HArray1OfVPointInter.def(py::init<const Standard_Integer, const Standard_Integer, const TopOpeBRep_Array1OfVPointInter::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TopOpeBRep_HArray1OfVPointInter.def(py::init<const TopOpeBRep_Array1OfVPointInter &>(), py::arg("theOther"));
	cls_TopOpeBRep_HArray1OfVPointInter.def("Array1", (const TopOpeBRep_Array1OfVPointInter & (TopOpeBRep_HArray1OfVPointInter::*)() const ) &TopOpeBRep_HArray1OfVPointInter::Array1, "None");
	cls_TopOpeBRep_HArray1OfVPointInter.def("ChangeArray1", (TopOpeBRep_Array1OfVPointInter & (TopOpeBRep_HArray1OfVPointInter::*)()) &TopOpeBRep_HArray1OfVPointInter::ChangeArray1, "None");
	cls_TopOpeBRep_HArray1OfVPointInter.def_static("get_type_name_", (const char * (*)()) &TopOpeBRep_HArray1OfVPointInter::get_type_name, "None");
	cls_TopOpeBRep_HArray1OfVPointInter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRep_HArray1OfVPointInter::get_type_descriptor, "None");
	cls_TopOpeBRep_HArray1OfVPointInter.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRep_HArray1OfVPointInter::*)() const ) &TopOpeBRep_HArray1OfVPointInter::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_HArray1OfLineInter.hxx
	py::class_<TopOpeBRep_HArray1OfLineInter, opencascade::handle<TopOpeBRep_HArray1OfLineInter>, TopOpeBRep_Array1OfLineInter, Standard_Transient> cls_TopOpeBRep_HArray1OfLineInter(mod, "TopOpeBRep_HArray1OfLineInter", "None");
	cls_TopOpeBRep_HArray1OfLineInter.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TopOpeBRep_HArray1OfLineInter.def(py::init<const Standard_Integer, const Standard_Integer, const TopOpeBRep_Array1OfLineInter::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TopOpeBRep_HArray1OfLineInter.def(py::init<const TopOpeBRep_Array1OfLineInter &>(), py::arg("theOther"));
	cls_TopOpeBRep_HArray1OfLineInter.def("Array1", (const TopOpeBRep_Array1OfLineInter & (TopOpeBRep_HArray1OfLineInter::*)() const ) &TopOpeBRep_HArray1OfLineInter::Array1, "None");
	cls_TopOpeBRep_HArray1OfLineInter.def("ChangeArray1", (TopOpeBRep_Array1OfLineInter & (TopOpeBRep_HArray1OfLineInter::*)()) &TopOpeBRep_HArray1OfLineInter::ChangeArray1, "None");
	cls_TopOpeBRep_HArray1OfLineInter.def_static("get_type_name_", (const char * (*)()) &TopOpeBRep_HArray1OfLineInter::get_type_name, "None");
	cls_TopOpeBRep_HArray1OfLineInter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRep_HArray1OfLineInter::get_type_descriptor, "None");
	cls_TopOpeBRep_HArray1OfLineInter.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRep_HArray1OfLineInter::*)() const ) &TopOpeBRep_HArray1OfLineInter::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TopOpeBRep_SequenceOfPoint2d, std::unique_ptr<TopOpeBRep_SequenceOfPoint2d, Deleter<TopOpeBRep_SequenceOfPoint2d>>, NCollection_BaseSequence> cls_TopOpeBRep_SequenceOfPoint2d(mod, "TopOpeBRep_SequenceOfPoint2d", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TopOpeBRep_SequenceOfPoint2d.def(py::init<>());
	cls_TopOpeBRep_SequenceOfPoint2d.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TopOpeBRep_SequenceOfPoint2d.def(py::init([] (const TopOpeBRep_SequenceOfPoint2d &other) {return new TopOpeBRep_SequenceOfPoint2d(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("begin", (TopOpeBRep_SequenceOfPoint2d::iterator (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TopOpeBRep_SequenceOfPoint2d.def("end", (TopOpeBRep_SequenceOfPoint2d::iterator (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TopOpeBRep_SequenceOfPoint2d.def("cbegin", (TopOpeBRep_SequenceOfPoint2d::const_iterator (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TopOpeBRep_SequenceOfPoint2d.def("cend", (TopOpeBRep_SequenceOfPoint2d::const_iterator (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TopOpeBRep_SequenceOfPoint2d.def("Size", (Standard_Integer (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::Size, "Number of items");
	cls_TopOpeBRep_SequenceOfPoint2d.def("Length", (Standard_Integer (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::Length, "Number of items");
	cls_TopOpeBRep_SequenceOfPoint2d.def("Lower", (Standard_Integer (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::Lower, "Method for consistency with other collections.");
	cls_TopOpeBRep_SequenceOfPoint2d.def("Upper", (Standard_Integer (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::Upper, "Method for consistency with other collections.");
	cls_TopOpeBRep_SequenceOfPoint2d.def("IsEmpty", (Standard_Boolean (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::IsEmpty, "Empty query");
	cls_TopOpeBRep_SequenceOfPoint2d.def("Reverse", (void (TopOpeBRep_SequenceOfPoint2d::*)()) &TopOpeBRep_SequenceOfPoint2d::Reverse, "Reverse sequence");
	cls_TopOpeBRep_SequenceOfPoint2d.def("Exchange", (void (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_SequenceOfPoint2d::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TopOpeBRep_SequenceOfPoint2d.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRep_SequenceOfPoint2d::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Clear", [](TopOpeBRep_SequenceOfPoint2d &self) -> void { return self.Clear(); });
	cls_TopOpeBRep_SequenceOfPoint2d.def("Clear", (void (TopOpeBRep_SequenceOfPoint2d::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRep_SequenceOfPoint2d::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Assign", (TopOpeBRep_SequenceOfPoint2d & (TopOpeBRep_SequenceOfPoint2d::*)(const TopOpeBRep_SequenceOfPoint2d &)) &TopOpeBRep_SequenceOfPoint2d::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("assign", (TopOpeBRep_SequenceOfPoint2d & (TopOpeBRep_SequenceOfPoint2d::*)(const TopOpeBRep_SequenceOfPoint2d &)) &TopOpeBRep_SequenceOfPoint2d::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Remove", (void (TopOpeBRep_SequenceOfPoint2d::*)(TopOpeBRep_SequenceOfPoint2d::Iterator &)) &TopOpeBRep_SequenceOfPoint2d::Remove, "Remove one item", py::arg("thePosition"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Remove", (void (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer)) &TopOpeBRep_SequenceOfPoint2d::Remove, "Remove one item", py::arg("theIndex"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Remove", (void (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_SequenceOfPoint2d::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Append", (void (TopOpeBRep_SequenceOfPoint2d::*)(const TopOpeBRep_Point2d &)) &TopOpeBRep_SequenceOfPoint2d::Append, "Append one item", py::arg("theItem"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Append", (void (TopOpeBRep_SequenceOfPoint2d::*)(TopOpeBRep_SequenceOfPoint2d &)) &TopOpeBRep_SequenceOfPoint2d::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Prepend", (void (TopOpeBRep_SequenceOfPoint2d::*)(const TopOpeBRep_Point2d &)) &TopOpeBRep_SequenceOfPoint2d::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Prepend", (void (TopOpeBRep_SequenceOfPoint2d::*)(TopOpeBRep_SequenceOfPoint2d &)) &TopOpeBRep_SequenceOfPoint2d::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("InsertBefore", (void (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer, const TopOpeBRep_Point2d &)) &TopOpeBRep_SequenceOfPoint2d::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("InsertBefore", (void (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer, TopOpeBRep_SequenceOfPoint2d &)) &TopOpeBRep_SequenceOfPoint2d::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("InsertAfter", (void (TopOpeBRep_SequenceOfPoint2d::*)(TopOpeBRep_SequenceOfPoint2d::Iterator &, const TopOpeBRep_Point2d &)) &TopOpeBRep_SequenceOfPoint2d::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("InsertAfter", (void (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer, TopOpeBRep_SequenceOfPoint2d &)) &TopOpeBRep_SequenceOfPoint2d::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("InsertAfter", (void (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer, const TopOpeBRep_Point2d &)) &TopOpeBRep_SequenceOfPoint2d::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("Split", (void (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer, TopOpeBRep_SequenceOfPoint2d &)) &TopOpeBRep_SequenceOfPoint2d::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("First", (const TopOpeBRep_Point2d & (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::First, "First item access");
	cls_TopOpeBRep_SequenceOfPoint2d.def("ChangeFirst", (TopOpeBRep_Point2d & (TopOpeBRep_SequenceOfPoint2d::*)()) &TopOpeBRep_SequenceOfPoint2d::ChangeFirst, "First item access");
	cls_TopOpeBRep_SequenceOfPoint2d.def("Last", (const TopOpeBRep_Point2d & (TopOpeBRep_SequenceOfPoint2d::*)() const ) &TopOpeBRep_SequenceOfPoint2d::Last, "Last item access");
	cls_TopOpeBRep_SequenceOfPoint2d.def("ChangeLast", (TopOpeBRep_Point2d & (TopOpeBRep_SequenceOfPoint2d::*)()) &TopOpeBRep_SequenceOfPoint2d::ChangeLast, "Last item access");
	cls_TopOpeBRep_SequenceOfPoint2d.def("Value", (const TopOpeBRep_Point2d & (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer) const ) &TopOpeBRep_SequenceOfPoint2d::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("__call__", (const TopOpeBRep_Point2d & (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer) const ) &TopOpeBRep_SequenceOfPoint2d::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("ChangeValue", (TopOpeBRep_Point2d & (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer)) &TopOpeBRep_SequenceOfPoint2d::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("__call__", (TopOpeBRep_Point2d & (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer)) &TopOpeBRep_SequenceOfPoint2d::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("SetValue", (void (TopOpeBRep_SequenceOfPoint2d::*)(const Standard_Integer, const TopOpeBRep_Point2d &)) &TopOpeBRep_SequenceOfPoint2d::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TopOpeBRep_SequenceOfPoint2d.def("__iter__", [](const TopOpeBRep_SequenceOfPoint2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_PFacesIntersector.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_PLineInter.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TopOpeBRep_DataMapOfTopolTool, std::unique_ptr<TopOpeBRep_DataMapOfTopolTool, Deleter<TopOpeBRep_DataMapOfTopolTool>>, NCollection_BaseMap> cls_TopOpeBRep_DataMapOfTopolTool(mod, "TopOpeBRep_DataMapOfTopolTool", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TopOpeBRep_DataMapOfTopolTool.def(py::init<>());
	cls_TopOpeBRep_DataMapOfTopolTool.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TopOpeBRep_DataMapOfTopolTool.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TopOpeBRep_DataMapOfTopolTool.def(py::init([] (const TopOpeBRep_DataMapOfTopolTool &other) {return new TopOpeBRep_DataMapOfTopolTool(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("begin", (TopOpeBRep_DataMapOfTopolTool::iterator (TopOpeBRep_DataMapOfTopolTool::*)() const ) &TopOpeBRep_DataMapOfTopolTool::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TopOpeBRep_DataMapOfTopolTool.def("end", (TopOpeBRep_DataMapOfTopolTool::iterator (TopOpeBRep_DataMapOfTopolTool::*)() const ) &TopOpeBRep_DataMapOfTopolTool::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRep_DataMapOfTopolTool.def("cbegin", (TopOpeBRep_DataMapOfTopolTool::const_iterator (TopOpeBRep_DataMapOfTopolTool::*)() const ) &TopOpeBRep_DataMapOfTopolTool::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TopOpeBRep_DataMapOfTopolTool.def("cend", (TopOpeBRep_DataMapOfTopolTool::const_iterator (TopOpeBRep_DataMapOfTopolTool::*)() const ) &TopOpeBRep_DataMapOfTopolTool::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TopOpeBRep_DataMapOfTopolTool.def("Exchange", (void (TopOpeBRep_DataMapOfTopolTool::*)(TopOpeBRep_DataMapOfTopolTool &)) &TopOpeBRep_DataMapOfTopolTool::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("Assign", (TopOpeBRep_DataMapOfTopolTool & (TopOpeBRep_DataMapOfTopolTool::*)(const TopOpeBRep_DataMapOfTopolTool &)) &TopOpeBRep_DataMapOfTopolTool::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("assign", (TopOpeBRep_DataMapOfTopolTool & (TopOpeBRep_DataMapOfTopolTool::*)(const TopOpeBRep_DataMapOfTopolTool &)) &TopOpeBRep_DataMapOfTopolTool::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("ReSize", (void (TopOpeBRep_DataMapOfTopolTool::*)(const Standard_Integer)) &TopOpeBRep_DataMapOfTopolTool::ReSize, "ReSize", py::arg("N"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("Bind", (Standard_Boolean (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &, const opencascade::handle<BRepTopAdaptor_TopolTool> &)) &TopOpeBRep_DataMapOfTopolTool::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TopOpeBRep_DataMapOfTopolTool.def("Bound", (opencascade::handle<BRepTopAdaptor_TopolTool> * (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &, const opencascade::handle<BRepTopAdaptor_TopolTool> &)) &TopOpeBRep_DataMapOfTopolTool::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("IsBound", (Standard_Boolean (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &) const ) &TopOpeBRep_DataMapOfTopolTool::IsBound, "IsBound", py::arg("theKey"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("UnBind", (Standard_Boolean (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &)) &TopOpeBRep_DataMapOfTopolTool::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TopOpeBRep_DataMapOfTopolTool.def("Seek", (const opencascade::handle<BRepTopAdaptor_TopolTool> * (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &) const ) &TopOpeBRep_DataMapOfTopolTool::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TopOpeBRep_DataMapOfTopolTool.def("Find", (const opencascade::handle<BRepTopAdaptor_TopolTool> & (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &) const ) &TopOpeBRep_DataMapOfTopolTool::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TopOpeBRep_DataMapOfTopolTool.def("Find", (Standard_Boolean (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &, opencascade::handle<BRepTopAdaptor_TopolTool> &) const ) &TopOpeBRep_DataMapOfTopolTool::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("__call__", (const opencascade::handle<BRepTopAdaptor_TopolTool> & (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &) const ) &TopOpeBRep_DataMapOfTopolTool::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TopOpeBRep_DataMapOfTopolTool.def("ChangeSeek", (opencascade::handle<BRepTopAdaptor_TopolTool> * (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &)) &TopOpeBRep_DataMapOfTopolTool::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("ChangeFind", (opencascade::handle<BRepTopAdaptor_TopolTool> & (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &)) &TopOpeBRep_DataMapOfTopolTool::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("__call__", (opencascade::handle<BRepTopAdaptor_TopolTool> & (TopOpeBRep_DataMapOfTopolTool::*)(const TopoDS_Shape &)) &TopOpeBRep_DataMapOfTopolTool::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("Clear", [](TopOpeBRep_DataMapOfTopolTool &self) -> void { return self.Clear(); });
	cls_TopOpeBRep_DataMapOfTopolTool.def("Clear", (void (TopOpeBRep_DataMapOfTopolTool::*)(const Standard_Boolean)) &TopOpeBRep_DataMapOfTopolTool::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("Clear", (void (TopOpeBRep_DataMapOfTopolTool::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRep_DataMapOfTopolTool::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TopOpeBRep_DataMapOfTopolTool.def("Size", (Standard_Integer (TopOpeBRep_DataMapOfTopolTool::*)() const ) &TopOpeBRep_DataMapOfTopolTool::Size, "Size");
	cls_TopOpeBRep_DataMapOfTopolTool.def("__iter__", [](const TopOpeBRep_DataMapOfTopolTool &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_DataMapOfTopolTool.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_PEdgesIntersector.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_PFacesFiller.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TopOpeBRep_ListOfBipoint, std::unique_ptr<TopOpeBRep_ListOfBipoint, Deleter<TopOpeBRep_ListOfBipoint>>, NCollection_BaseList> cls_TopOpeBRep_ListOfBipoint(mod, "TopOpeBRep_ListOfBipoint", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TopOpeBRep_ListOfBipoint.def(py::init<>());
	cls_TopOpeBRep_ListOfBipoint.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TopOpeBRep_ListOfBipoint.def(py::init([] (const TopOpeBRep_ListOfBipoint &other) {return new TopOpeBRep_ListOfBipoint(other);}), "Copy constructor", py::arg("other"));
	cls_TopOpeBRep_ListOfBipoint.def("begin", (TopOpeBRep_ListOfBipoint::iterator (TopOpeBRep_ListOfBipoint::*)() const ) &TopOpeBRep_ListOfBipoint::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TopOpeBRep_ListOfBipoint.def("end", (TopOpeBRep_ListOfBipoint::iterator (TopOpeBRep_ListOfBipoint::*)() const ) &TopOpeBRep_ListOfBipoint::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TopOpeBRep_ListOfBipoint.def("cbegin", (TopOpeBRep_ListOfBipoint::const_iterator (TopOpeBRep_ListOfBipoint::*)() const ) &TopOpeBRep_ListOfBipoint::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TopOpeBRep_ListOfBipoint.def("cend", (TopOpeBRep_ListOfBipoint::const_iterator (TopOpeBRep_ListOfBipoint::*)() const ) &TopOpeBRep_ListOfBipoint::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TopOpeBRep_ListOfBipoint.def("Size", (Standard_Integer (TopOpeBRep_ListOfBipoint::*)() const ) &TopOpeBRep_ListOfBipoint::Size, "Size - Number of items");
	cls_TopOpeBRep_ListOfBipoint.def("Assign", (TopOpeBRep_ListOfBipoint & (TopOpeBRep_ListOfBipoint::*)(const TopOpeBRep_ListOfBipoint &)) &TopOpeBRep_ListOfBipoint::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopOpeBRep_ListOfBipoint.def("assign", (TopOpeBRep_ListOfBipoint & (TopOpeBRep_ListOfBipoint::*)(const TopOpeBRep_ListOfBipoint &)) &TopOpeBRep_ListOfBipoint::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TopOpeBRep_ListOfBipoint.def("Clear", [](TopOpeBRep_ListOfBipoint &self) -> void { return self.Clear(); });
	cls_TopOpeBRep_ListOfBipoint.def("Clear", (void (TopOpeBRep_ListOfBipoint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRep_ListOfBipoint::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TopOpeBRep_ListOfBipoint.def("First", (const TopOpeBRep_Bipoint & (TopOpeBRep_ListOfBipoint::*)() const ) &TopOpeBRep_ListOfBipoint::First, "First item");
	cls_TopOpeBRep_ListOfBipoint.def("First", (TopOpeBRep_Bipoint & (TopOpeBRep_ListOfBipoint::*)()) &TopOpeBRep_ListOfBipoint::First, "First item (non-const)");
	cls_TopOpeBRep_ListOfBipoint.def("Last", (const TopOpeBRep_Bipoint & (TopOpeBRep_ListOfBipoint::*)() const ) &TopOpeBRep_ListOfBipoint::Last, "Last item");
	cls_TopOpeBRep_ListOfBipoint.def("Last", (TopOpeBRep_Bipoint & (TopOpeBRep_ListOfBipoint::*)()) &TopOpeBRep_ListOfBipoint::Last, "Last item (non-const)");
	cls_TopOpeBRep_ListOfBipoint.def("Append", (TopOpeBRep_Bipoint & (TopOpeBRep_ListOfBipoint::*)(const TopOpeBRep_Bipoint &)) &TopOpeBRep_ListOfBipoint::Append, "Append one item at the end", py::arg("theItem"));
	cls_TopOpeBRep_ListOfBipoint.def("Append", (void (TopOpeBRep_ListOfBipoint::*)(const TopOpeBRep_Bipoint &, TopOpeBRep_ListOfBipoint::Iterator &)) &TopOpeBRep_ListOfBipoint::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TopOpeBRep_ListOfBipoint.def("Append", (void (TopOpeBRep_ListOfBipoint::*)(TopOpeBRep_ListOfBipoint &)) &TopOpeBRep_ListOfBipoint::Append, "Append another list at the end", py::arg("theOther"));
	cls_TopOpeBRep_ListOfBipoint.def("Prepend", (TopOpeBRep_Bipoint & (TopOpeBRep_ListOfBipoint::*)(const TopOpeBRep_Bipoint &)) &TopOpeBRep_ListOfBipoint::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TopOpeBRep_ListOfBipoint.def("Prepend", (void (TopOpeBRep_ListOfBipoint::*)(TopOpeBRep_ListOfBipoint &)) &TopOpeBRep_ListOfBipoint::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TopOpeBRep_ListOfBipoint.def("RemoveFirst", (void (TopOpeBRep_ListOfBipoint::*)()) &TopOpeBRep_ListOfBipoint::RemoveFirst, "RemoveFirst item");
	cls_TopOpeBRep_ListOfBipoint.def("Remove", (void (TopOpeBRep_ListOfBipoint::*)(TopOpeBRep_ListOfBipoint::Iterator &)) &TopOpeBRep_ListOfBipoint::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TopOpeBRep_ListOfBipoint.def("InsertBefore", (TopOpeBRep_Bipoint & (TopOpeBRep_ListOfBipoint::*)(const TopOpeBRep_Bipoint &, TopOpeBRep_ListOfBipoint::Iterator &)) &TopOpeBRep_ListOfBipoint::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TopOpeBRep_ListOfBipoint.def("InsertBefore", (void (TopOpeBRep_ListOfBipoint::*)(TopOpeBRep_ListOfBipoint &, TopOpeBRep_ListOfBipoint::Iterator &)) &TopOpeBRep_ListOfBipoint::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TopOpeBRep_ListOfBipoint.def("InsertAfter", (TopOpeBRep_Bipoint & (TopOpeBRep_ListOfBipoint::*)(const TopOpeBRep_Bipoint &, TopOpeBRep_ListOfBipoint::Iterator &)) &TopOpeBRep_ListOfBipoint::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TopOpeBRep_ListOfBipoint.def("InsertAfter", (void (TopOpeBRep_ListOfBipoint::*)(TopOpeBRep_ListOfBipoint &, TopOpeBRep_ListOfBipoint::Iterator &)) &TopOpeBRep_ListOfBipoint::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TopOpeBRep_ListOfBipoint.def("Reverse", (void (TopOpeBRep_ListOfBipoint::*)()) &TopOpeBRep_ListOfBipoint::Reverse, "Reverse the list");
	cls_TopOpeBRep_ListOfBipoint.def("__iter__", [](const TopOpeBRep_ListOfBipoint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TopOpeBRep_ListIteratorOfListOfBipoint, std::unique_ptr<TopOpeBRep_ListIteratorOfListOfBipoint, Deleter<TopOpeBRep_ListIteratorOfListOfBipoint>>> cls_TopOpeBRep_ListIteratorOfListOfBipoint(mod, "TopOpeBRep_ListIteratorOfListOfBipoint", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TopOpeBRep_ListIteratorOfListOfBipoint.def(py::init<>());
	cls_TopOpeBRep_ListIteratorOfListOfBipoint.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TopOpeBRep_ListIteratorOfListOfBipoint.def("More", (Standard_Boolean (TopOpeBRep_ListIteratorOfListOfBipoint::*)() const ) &TopOpeBRep_ListIteratorOfListOfBipoint::More, "Check end");
	cls_TopOpeBRep_ListIteratorOfListOfBipoint.def("Next", (void (TopOpeBRep_ListIteratorOfListOfBipoint::*)()) &TopOpeBRep_ListIteratorOfListOfBipoint::Next, "Make step");
	cls_TopOpeBRep_ListIteratorOfListOfBipoint.def("Value", (const TopOpeBRep_Bipoint & (TopOpeBRep_ListIteratorOfListOfBipoint::*)() const ) &TopOpeBRep_ListIteratorOfListOfBipoint::Value, "Constant Value access");
	cls_TopOpeBRep_ListIteratorOfListOfBipoint.def("Value", (TopOpeBRep_Bipoint & (TopOpeBRep_ListIteratorOfListOfBipoint::*)()) &TopOpeBRep_ListIteratorOfListOfBipoint::Value, "Non-const Value access");
	cls_TopOpeBRep_ListIteratorOfListOfBipoint.def("ChangeValue", (TopOpeBRep_Bipoint & (TopOpeBRep_ListIteratorOfListOfBipoint::*)() const ) &TopOpeBRep_ListIteratorOfListOfBipoint::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopOpeBRep_PIntRes2d_IntersectionPoint.hxx

}
