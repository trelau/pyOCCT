#include <pyOCCT_Common.hpp>

#include <BRepClass3d_SClassifier.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepClass3d_SolidClassifier.hxx>
#include <gp_Lin.hxx>
#include <TopoDS_Face.hxx>
#include <IntCurveSurface_TransitionOnCurve.hxx>
#include <TopAbs_State.hxx>
#include <BRepClass3d_Intersector3d.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <TopoDS_Shell.hxx>
#include <Bnd_Box.hxx>
#include <IntCurvesFace_Intersector.hxx>
#include <BRepClass3d_BndBoxTree.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRepClass3d_SolidExplorer.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepClass3d_SolidPassiveClassifier.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepClass3d.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_UBTree.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <BRepClass3d_MapOfInter.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(BRepClass3d, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.IntCurveSurface");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.BRepAdaptor");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.IntCurvesFace");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_SClassifier.hxx
	py::class_<BRepClass3d_SClassifier, std::unique_ptr<BRepClass3d_SClassifier, Deleter<BRepClass3d_SClassifier>>> cls_BRepClass3d_SClassifier(mod, "BRepClass3d_SClassifier", "Provides an algorithm to classify a point in a solid.");
	cls_BRepClass3d_SClassifier.def(py::init<>());
	cls_BRepClass3d_SClassifier.def(py::init<BRepClass3d_SolidExplorer &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("P"), py::arg("Tol"));
	cls_BRepClass3d_SClassifier.def("Perform", (void (BRepClass3d_SClassifier::*)(BRepClass3d_SolidExplorer &, const gp_Pnt &, const Standard_Real)) &BRepClass3d_SClassifier::Perform, "Classify the point P with the tolerance Tol on the solid S.", py::arg("S"), py::arg("P"), py::arg("Tol"));
	cls_BRepClass3d_SClassifier.def("PerformInfinitePoint", (void (BRepClass3d_SClassifier::*)(BRepClass3d_SolidExplorer &, const Standard_Real)) &BRepClass3d_SClassifier::PerformInfinitePoint, "Classify an infinite point with the tolerance Tol on the solid S.", py::arg("S"), py::arg("Tol"));
	cls_BRepClass3d_SClassifier.def("Rejected", (Standard_Boolean (BRepClass3d_SClassifier::*)() const ) &BRepClass3d_SClassifier::Rejected, "Returns True if the classification has been computed by rejection. The State is then OUT.");
	cls_BRepClass3d_SClassifier.def("State", (TopAbs_State (BRepClass3d_SClassifier::*)() const ) &BRepClass3d_SClassifier::State, "Returns the result of the classification.");
	cls_BRepClass3d_SClassifier.def("IsOnAFace", (Standard_Boolean (BRepClass3d_SClassifier::*)() const ) &BRepClass3d_SClassifier::IsOnAFace, "Returns True when the point is a point of a face.");
	cls_BRepClass3d_SClassifier.def("Face", (TopoDS_Face (BRepClass3d_SClassifier::*)() const ) &BRepClass3d_SClassifier::Face, "Returns the face used to determine the classification. When the state is ON, this is the face containing the point.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_Intersector3d.hxx
	py::class_<BRepClass3d_Intersector3d, std::unique_ptr<BRepClass3d_Intersector3d, Deleter<BRepClass3d_Intersector3d>>> cls_BRepClass3d_Intersector3d(mod, "BRepClass3d_Intersector3d", "None");
	cls_BRepClass3d_Intersector3d.def(py::init<>());
	cls_BRepClass3d_Intersector3d.def("Perform", (void (BRepClass3d_Intersector3d::*)(const gp_Lin &, const Standard_Real, const Standard_Real, const TopoDS_Face &)) &BRepClass3d_Intersector3d::Perform, "Perform the intersection between the segment L(0) ... L(Prm) and the Shape <Sh>.", py::arg("L"), py::arg("Prm"), py::arg("Tol"), py::arg("F"));
	cls_BRepClass3d_Intersector3d.def("IsDone", (Standard_Boolean (BRepClass3d_Intersector3d::*)() const ) &BRepClass3d_Intersector3d::IsDone, "True is returned when the intersection have been computed.");
	cls_BRepClass3d_Intersector3d.def("HasAPoint", (Standard_Boolean (BRepClass3d_Intersector3d::*)() const ) &BRepClass3d_Intersector3d::HasAPoint, "True is returned if a point has been found.");
	cls_BRepClass3d_Intersector3d.def("UParameter", (Standard_Real (BRepClass3d_Intersector3d::*)() const ) &BRepClass3d_Intersector3d::UParameter, "Returns the U parameter of the intersection point on the surface.");
	cls_BRepClass3d_Intersector3d.def("VParameter", (Standard_Real (BRepClass3d_Intersector3d::*)() const ) &BRepClass3d_Intersector3d::VParameter, "Returns the V parameter of the intersection point on the surface.");
	cls_BRepClass3d_Intersector3d.def("WParameter", (Standard_Real (BRepClass3d_Intersector3d::*)() const ) &BRepClass3d_Intersector3d::WParameter, "Returns the parameter of the intersection point on the line.");
	cls_BRepClass3d_Intersector3d.def("Pnt", (const gp_Pnt & (BRepClass3d_Intersector3d::*)() const ) &BRepClass3d_Intersector3d::Pnt, "Returns the geometric point of the intersection between the line and the surface.");
	cls_BRepClass3d_Intersector3d.def("Transition", (IntCurveSurface_TransitionOnCurve (BRepClass3d_Intersector3d::*)() const ) &BRepClass3d_Intersector3d::Transition, "Returns the transition of the line on the surface.");
	cls_BRepClass3d_Intersector3d.def("State", (TopAbs_State (BRepClass3d_Intersector3d::*)() const ) &BRepClass3d_Intersector3d::State, "Returns the state of the point on the face. The values can be either TopAbs_IN ( the point is in the face) or TopAbs_ON ( the point is on a boudary of the face).");
	cls_BRepClass3d_Intersector3d.def("Face", (const TopoDS_Face & (BRepClass3d_Intersector3d::*)() const ) &BRepClass3d_Intersector3d::Face, "Returns the significant face used to determine the intersection.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_SolidExplorer.hxx
	py::class_<BRepClass3d_SolidExplorer, std::unique_ptr<BRepClass3d_SolidExplorer, Deleter<BRepClass3d_SolidExplorer>>> cls_BRepClass3d_SolidExplorer(mod, "BRepClass3d_SolidExplorer", "Provide an exploration of a BRep Shape for the classification. Provide access to the special UB tree to obtain fast search.");
	cls_BRepClass3d_SolidExplorer.def(py::init<>());
	cls_BRepClass3d_SolidExplorer.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_BRepClass3d_SolidExplorer.def("InitShape", (void (BRepClass3d_SolidExplorer::*)(const TopoDS_Shape &)) &BRepClass3d_SolidExplorer::InitShape, "None", py::arg("S"));
	cls_BRepClass3d_SolidExplorer.def("Reject", (Standard_Boolean (BRepClass3d_SolidExplorer::*)(const gp_Pnt &) const ) &BRepClass3d_SolidExplorer::Reject, "Should return True if P outside of bounding vol. of the shape", py::arg("P"));
	cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", (Standard_Boolean (*)(const TopoDS_Face &, gp_Pnt &, Standard_Real &)) &BRepClass3d_SolidExplorer::FindAPointInTheFace, "compute a point P in the face F. Param is a Real in ]0,1[ and is used to initialise the algorithm. For different values , different points are returned.", py::arg("F"), py::arg("P"), py::arg("Param"));
	cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", (Standard_Boolean (*)(const TopoDS_Face &, gp_Pnt &, Standard_Real &, Standard_Real &, Standard_Real &)) &BRepClass3d_SolidExplorer::FindAPointInTheFace, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"));
	cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", (Standard_Boolean (*)(const TopoDS_Face &, gp_Pnt &, Standard_Real &, Standard_Real &, Standard_Real &, gp_Vec &, gp_Vec &)) &BRepClass3d_SolidExplorer::FindAPointInTheFace, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"), py::arg("theVecD1U"), py::arg("theVecD1V"));
	cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", (Standard_Boolean (*)(const TopoDS_Face &, gp_Pnt &, Standard_Real &, Standard_Real &)) &BRepClass3d_SolidExplorer::FindAPointInTheFace, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"));
	cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", (Standard_Boolean (*)(const TopoDS_Face &, gp_Pnt &)) &BRepClass3d_SolidExplorer::FindAPointInTheFace, "None", py::arg("F"), py::arg("P"));
	cls_BRepClass3d_SolidExplorer.def_static("FindAPointInTheFace_", (Standard_Boolean (*)(const TopoDS_Face &, Standard_Real &, Standard_Real &)) &BRepClass3d_SolidExplorer::FindAPointInTheFace, "None", py::arg("F"), py::arg("u"), py::arg("v"));
	cls_BRepClass3d_SolidExplorer.def("PointInTheFace", (Standard_Boolean (BRepClass3d_SolidExplorer::*)(const TopoDS_Face &, gp_Pnt &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Integer &) const ) &BRepClass3d_SolidExplorer::PointInTheFace, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"), py::arg("Index"));
	cls_BRepClass3d_SolidExplorer.def("PointInTheFace", (Standard_Boolean (BRepClass3d_SolidExplorer::*)(const TopoDS_Face &, gp_Pnt &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Integer &, const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real) const ) &BRepClass3d_SolidExplorer::PointInTheFace, "None", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"), py::arg("Index"), py::arg("surf"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"));
	cls_BRepClass3d_SolidExplorer.def("PointInTheFace", (Standard_Boolean (BRepClass3d_SolidExplorer::*)(const TopoDS_Face &, gp_Pnt &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Integer &, const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &) const ) &BRepClass3d_SolidExplorer::PointInTheFace, "<Index> gives point index to search from and returns point index of succeseful search", py::arg("F"), py::arg("P"), py::arg("u"), py::arg("v"), py::arg("Param"), py::arg("Index"), py::arg("surf"), py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("theVecD1U"), py::arg("theVecD1V"));
	cls_BRepClass3d_SolidExplorer.def("InitShell", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::InitShell, "Starts an exploration of the shells.");
	cls_BRepClass3d_SolidExplorer.def("MoreShell", (Standard_Boolean (BRepClass3d_SolidExplorer::*)() const ) &BRepClass3d_SolidExplorer::MoreShell, "Returns True if there is a current shell.");
	cls_BRepClass3d_SolidExplorer.def("NextShell", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::NextShell, "Sets the explorer to the next shell.");
	cls_BRepClass3d_SolidExplorer.def("CurrentShell", (TopoDS_Shell (BRepClass3d_SolidExplorer::*)() const ) &BRepClass3d_SolidExplorer::CurrentShell, "Returns the current shell.");
	cls_BRepClass3d_SolidExplorer.def("RejectShell", (Standard_Boolean (BRepClass3d_SolidExplorer::*)(const gp_Lin &) const ) &BRepClass3d_SolidExplorer::RejectShell, "Returns True if the Shell is rejected.", py::arg("L"));
	cls_BRepClass3d_SolidExplorer.def("InitFace", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::InitFace, "Starts an exploration of the faces of the current shell.");
	cls_BRepClass3d_SolidExplorer.def("MoreFace", (Standard_Boolean (BRepClass3d_SolidExplorer::*)() const ) &BRepClass3d_SolidExplorer::MoreFace, "Returns True if current face in current shell.");
	cls_BRepClass3d_SolidExplorer.def("NextFace", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::NextFace, "Sets the explorer to the next Face of the current shell.");
	cls_BRepClass3d_SolidExplorer.def("CurrentFace", (TopoDS_Face (BRepClass3d_SolidExplorer::*)() const ) &BRepClass3d_SolidExplorer::CurrentFace, "Returns the current face.");
	cls_BRepClass3d_SolidExplorer.def("RejectFace", (Standard_Boolean (BRepClass3d_SolidExplorer::*)(const gp_Lin &) const ) &BRepClass3d_SolidExplorer::RejectFace, "returns True if the face is rejected.", py::arg("L"));
	cls_BRepClass3d_SolidExplorer.def("Segment", (Standard_Integer (BRepClass3d_SolidExplorer::*)(const gp_Pnt &, gp_Lin &, Standard_Real &)) &BRepClass3d_SolidExplorer::Segment, "Returns in <L>, <Par> a segment having at least one intersection with the shape boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
	cls_BRepClass3d_SolidExplorer.def("OtherSegment", (Standard_Integer (BRepClass3d_SolidExplorer::*)(const gp_Pnt &, gp_Lin &, Standard_Real &)) &BRepClass3d_SolidExplorer::OtherSegment, "Returns in <L>, <Par> a segment having at least one intersection with the shape boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
	cls_BRepClass3d_SolidExplorer.def("GetFaceSegmentIndex", (Standard_Integer (BRepClass3d_SolidExplorer::*)() const ) &BRepClass3d_SolidExplorer::GetFaceSegmentIndex, "Returns the index of face for which last segment is calculated.");
	cls_BRepClass3d_SolidExplorer.def("DumpSegment", (void (BRepClass3d_SolidExplorer::*)(const gp_Pnt &, const gp_Lin &, const Standard_Real, const TopAbs_State) const ) &BRepClass3d_SolidExplorer::DumpSegment, "None", py::arg("P"), py::arg("L"), py::arg("Par"), py::arg("S"));
	cls_BRepClass3d_SolidExplorer.def("Box", (const Bnd_Box & (BRepClass3d_SolidExplorer::*)() const ) &BRepClass3d_SolidExplorer::Box, "None");
	cls_BRepClass3d_SolidExplorer.def("GetShape", (const TopoDS_Shape & (BRepClass3d_SolidExplorer::*)() const ) &BRepClass3d_SolidExplorer::GetShape, "None");
	cls_BRepClass3d_SolidExplorer.def("Intersector", (IntCurvesFace_Intersector & (BRepClass3d_SolidExplorer::*)(const TopoDS_Face &) const ) &BRepClass3d_SolidExplorer::Intersector, "None", py::arg("F"));
	cls_BRepClass3d_SolidExplorer.def("GetTree", (const BRepClass3d_BndBoxTree & (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::GetTree, "Return UB-tree instance which is used for edge / vertex checks.");
	cls_BRepClass3d_SolidExplorer.def("GetMapEV", (const TopTools_IndexedMapOfShape & (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::GetMapEV, "Return edge/vertices map for current shape.");
	cls_BRepClass3d_SolidExplorer.def("Destroy", (void (BRepClass3d_SolidExplorer::*)()) &BRepClass3d_SolidExplorer::Destroy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_SolidPassiveClassifier.hxx
	py::class_<BRepClass3d_SolidPassiveClassifier, std::unique_ptr<BRepClass3d_SolidPassiveClassifier, Deleter<BRepClass3d_SolidPassiveClassifier>>> cls_BRepClass3d_SolidPassiveClassifier(mod, "BRepClass3d_SolidPassiveClassifier", "None");
	cls_BRepClass3d_SolidPassiveClassifier.def(py::init<>());
	cls_BRepClass3d_SolidPassiveClassifier.def("Reset", (void (BRepClass3d_SolidPassiveClassifier::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &BRepClass3d_SolidPassiveClassifier::Reset, "Starts a classification process. The point to classify is the origin of the line <L>. <P> is the original length of the segment on <L> used to compute intersections. <Tol> is the tolerance attached to the intersections.", py::arg("L"), py::arg("P"), py::arg("Tol"));
	cls_BRepClass3d_SolidPassiveClassifier.def("Compare", (void (BRepClass3d_SolidPassiveClassifier::*)(const TopoDS_Face &, const TopAbs_Orientation)) &BRepClass3d_SolidPassiveClassifier::Compare, "Updates the classification process with the face <F> from the boundary.", py::arg("F"), py::arg("Or"));
	cls_BRepClass3d_SolidPassiveClassifier.def("Parameter", (Standard_Real (BRepClass3d_SolidPassiveClassifier::*)() const ) &BRepClass3d_SolidPassiveClassifier::Parameter, "Returns the current value of the parameter.");
	cls_BRepClass3d_SolidPassiveClassifier.def("HasIntersection", (Standard_Boolean (BRepClass3d_SolidPassiveClassifier::*)() const ) &BRepClass3d_SolidPassiveClassifier::HasIntersection, "Returns True if an intersection is computed.");
	cls_BRepClass3d_SolidPassiveClassifier.def("Intersector", (BRepClass3d_Intersector3d & (BRepClass3d_SolidPassiveClassifier::*)()) &BRepClass3d_SolidPassiveClassifier::Intersector, "Returns the intersecting algorithm.");
	cls_BRepClass3d_SolidPassiveClassifier.def("State", (TopAbs_State (BRepClass3d_SolidPassiveClassifier::*)() const ) &BRepClass3d_SolidPassiveClassifier::State, "Returns the current state of the point.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_SolidClassifier.hxx
	py::class_<BRepClass3d_SolidClassifier, std::unique_ptr<BRepClass3d_SolidClassifier, Deleter<BRepClass3d_SolidClassifier>>, BRepClass3d_SClassifier> cls_BRepClass3d_SolidClassifier(mod, "BRepClass3d_SolidClassifier", "Provides an algorithm to classify a point in a solid.");
	cls_BRepClass3d_SolidClassifier.def(py::init<>());
	cls_BRepClass3d_SolidClassifier.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_BRepClass3d_SolidClassifier.def(py::init<const TopoDS_Shape &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("P"), py::arg("Tol"));
	cls_BRepClass3d_SolidClassifier.def("Load", (void (BRepClass3d_SolidClassifier::*)(const TopoDS_Shape &)) &BRepClass3d_SolidClassifier::Load, "None", py::arg("S"));
	cls_BRepClass3d_SolidClassifier.def("Perform", (void (BRepClass3d_SolidClassifier::*)(const gp_Pnt &, const Standard_Real)) &BRepClass3d_SolidClassifier::Perform, "Classify the point P with the tolerance Tol on the solid S.", py::arg("P"), py::arg("Tol"));
	cls_BRepClass3d_SolidClassifier.def("PerformInfinitePoint", (void (BRepClass3d_SolidClassifier::*)(const Standard_Real)) &BRepClass3d_SolidClassifier::PerformInfinitePoint, "Classify an infinite point with the tolerance Tol on the solid S. Useful for compute the orientation of a solid.", py::arg("Tol"));
	cls_BRepClass3d_SolidClassifier.def("Destroy", (void (BRepClass3d_SolidClassifier::*)()) &BRepClass3d_SolidClassifier::Destroy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d.hxx
	py::class_<BRepClass3d, std::unique_ptr<BRepClass3d, Deleter<BRepClass3d>>> cls_BRepClass3d(mod, "BRepClass3d", "None");
	cls_BRepClass3d.def(py::init<>());
	cls_BRepClass3d.def_static("OuterShell_", (TopoDS_Shell (*)(const TopoDS_Solid &)) &BRepClass3d::OuterShell, "Returns the outer most shell of <S>. Returns a Null shell if <S> has no outer shell. If <S> has only one shell, then it will return, without checking orientation.", py::arg("S"));

	// Callback for BRepClass3d_BndBoxTreeSelectorPoint.
	class PyCallback_BRepClass3d_BndBoxTreeSelectorPoint : public BRepClass3d_BndBoxTreeSelectorPoint {
	public:
		using BRepClass3d_BndBoxTreeSelectorPoint::BRepClass3d_BndBoxTreeSelectorPoint;

		Standard_Boolean Accept(const int & a0) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, BRepClass3d_BndBoxTreeSelectorPoint, Accept, a0); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_BndBoxTree.hxx
	py::class_<BRepClass3d_BndBoxTreeSelectorPoint, std::unique_ptr<BRepClass3d_BndBoxTreeSelectorPoint, Deleter<BRepClass3d_BndBoxTreeSelectorPoint>>, PyCallback_BRepClass3d_BndBoxTreeSelectorPoint> cls_BRepClass3d_BndBoxTreeSelectorPoint(mod, "BRepClass3d_BndBoxTreeSelectorPoint", "None");
	cls_BRepClass3d_BndBoxTreeSelectorPoint.def(py::init<const TopTools_IndexedMapOfShape &>(), py::arg("theMapOfShape"));
	cls_BRepClass3d_BndBoxTreeSelectorPoint.def("Reject", (Standard_Boolean (BRepClass3d_BndBoxTreeSelectorPoint::*)(const Bnd_Box &) const ) &BRepClass3d_BndBoxTreeSelectorPoint::Reject, "None", py::arg("theBox"));
	cls_BRepClass3d_BndBoxTreeSelectorPoint.def("Accept", (Standard_Boolean (BRepClass3d_BndBoxTreeSelectorPoint::*)(const Standard_Integer &)) &BRepClass3d_BndBoxTreeSelectorPoint::Accept, "None", py::arg("theObj"));
	cls_BRepClass3d_BndBoxTreeSelectorPoint.def("SetCurrentPoint", (void (BRepClass3d_BndBoxTreeSelectorPoint::*)(const gp_Pnt &)) &BRepClass3d_BndBoxTreeSelectorPoint::SetCurrentPoint, "None", py::arg("theP"));

	// Callback for BRepClass3d_BndBoxTreeSelectorLine.
	class PyCallback_BRepClass3d_BndBoxTreeSelectorLine : public BRepClass3d_BndBoxTreeSelectorLine {
	public:
		using BRepClass3d_BndBoxTreeSelectorLine::BRepClass3d_BndBoxTreeSelectorLine;

		Standard_Boolean Accept(const int & a0) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, BRepClass3d_BndBoxTreeSelectorLine, Accept, a0); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_BndBoxTree.hxx
	py::class_<BRepClass3d_BndBoxTreeSelectorLine, std::unique_ptr<BRepClass3d_BndBoxTreeSelectorLine, Deleter<BRepClass3d_BndBoxTreeSelectorLine>>, PyCallback_BRepClass3d_BndBoxTreeSelectorLine> cls_BRepClass3d_BndBoxTreeSelectorLine(mod, "BRepClass3d_BndBoxTreeSelectorLine", "None");
	cls_BRepClass3d_BndBoxTreeSelectorLine.def(py::init<const TopTools_IndexedMapOfShape &>(), py::arg("theMapOfShape"));
	cls_BRepClass3d_BndBoxTreeSelectorLine.def("Reject", (Standard_Boolean (BRepClass3d_BndBoxTreeSelectorLine::*)(const Bnd_Box &) const ) &BRepClass3d_BndBoxTreeSelectorLine::Reject, "None", py::arg("theBox"));
	cls_BRepClass3d_BndBoxTreeSelectorLine.def("Accept", (Standard_Boolean (BRepClass3d_BndBoxTreeSelectorLine::*)(const Standard_Integer &)) &BRepClass3d_BndBoxTreeSelectorLine::Accept, "None", py::arg("theObj"));
	cls_BRepClass3d_BndBoxTreeSelectorLine.def("SetCurrentLine", (void (BRepClass3d_BndBoxTreeSelectorLine::*)(const gp_Lin &, const Standard_Real)) &BRepClass3d_BndBoxTreeSelectorLine::SetCurrentLine, "None", py::arg("theL"), py::arg("theMaxParam"));
	cls_BRepClass3d_BndBoxTreeSelectorLine.def("GetEdgeParam", (void (BRepClass3d_BndBoxTreeSelectorLine::*)(const Standard_Integer, TopoDS_Edge &, Standard_Real &, Standard_Real &) const ) &BRepClass3d_BndBoxTreeSelectorLine::GetEdgeParam, "None", py::arg("i"), py::arg("theOutE"), py::arg("theOutParam"), py::arg("outLParam"));
	cls_BRepClass3d_BndBoxTreeSelectorLine.def("GetVertParam", (void (BRepClass3d_BndBoxTreeSelectorLine::*)(const Standard_Integer, TopoDS_Vertex &, Standard_Real &) const ) &BRepClass3d_BndBoxTreeSelectorLine::GetVertParam, "None", py::arg("i"), py::arg("theOutV"), py::arg("outLParam"));
	cls_BRepClass3d_BndBoxTreeSelectorLine.def("GetNbEdgeParam", (Standard_Integer (BRepClass3d_BndBoxTreeSelectorLine::*)() const ) &BRepClass3d_BndBoxTreeSelectorLine::GetNbEdgeParam, "None");
	cls_BRepClass3d_BndBoxTreeSelectorLine.def("GetNbVertParam", (Standard_Integer (BRepClass3d_BndBoxTreeSelectorLine::*)() const ) &BRepClass3d_BndBoxTreeSelectorLine::GetNbVertParam, "None");
	cls_BRepClass3d_BndBoxTreeSelectorLine.def("ClearResults", (void (BRepClass3d_BndBoxTreeSelectorLine::*)()) &BRepClass3d_BndBoxTreeSelectorLine::ClearResults, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_BndBoxTree.hxx
	other_mod = py::module::import("OCCT.BOPCol");
	if (py::hasattr(other_mod, "BOPCol_BoxBndTree")) {
		mod.attr("BRepClass3d_BndBoxTree") = other_mod.attr("BOPCol_BoxBndTree");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_MapOfInter.hxx
	other_mod = py::module::import("OCCT.BOPCol");
	if (py::hasattr(other_mod, "BOPCol_DataMapOfShapeAddress")) {
		mod.attr("BRepClass3d_MapOfInter") = other_mod.attr("BOPCol_DataMapOfShapeAddress");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepClass3d_MapOfInter.hxx
	other_mod = py::module::import("OCCT.BOPCol");
	if (py::hasattr(other_mod, "BOPCol_DataMapIteratorOfDataMapOfShapeAddress")) {
		mod.attr("BRepClass3d_DataMapIteratorOfMapOfInter") = other_mod.attr("BOPCol_DataMapIteratorOfDataMapOfShapeAddress");
	}


}
