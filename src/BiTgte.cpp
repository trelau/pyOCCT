#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BiTgte_ContactType.hxx>
#include <NCollection_BaseMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <BiTgte_DataMapOfShapeBox.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Surface.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <BiTgte_Blend.hxx>
#include <Adaptor3d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <BiTgte_CurveOnEdge.hxx>
#include <TopoDS_Vertex.hxx>
#include <BiTgte_CurveOnVertex.hxx>
#include <Standard_Type.hxx>
#include <BiTgte_HCurveOnEdge.hxx>
#include <BiTgte_HCurveOnVertex.hxx>

PYBIND11_MODULE(BiTgte, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BiTgte_ContactType.hxx
	py::enum_<BiTgte_ContactType>(mod, "BiTgte_ContactType", "None")
		.value("BiTgte_FaceFace", BiTgte_ContactType::BiTgte_FaceFace)
		.value("BiTgte_FaceEdge", BiTgte_ContactType::BiTgte_FaceEdge)
		.value("BiTgte_FaceVertex", BiTgte_ContactType::BiTgte_FaceVertex)
		.value("BiTgte_EdgeEdge", BiTgte_ContactType::BiTgte_EdgeEdge)
		.value("BiTgte_EdgeVertex", BiTgte_ContactType::BiTgte_EdgeVertex)
		.value("BiTgte_VertexVertex", BiTgte_ContactType::BiTgte_VertexVertex)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BiTgte_Blend.hxx
	py::class_<BiTgte_Blend, std::unique_ptr<BiTgte_Blend, Deleter<BiTgte_Blend>>> cls_BiTgte_Blend(mod, "BiTgte_Blend", "Root class");
	cls_BiTgte_Blend.def(py::init<>());
	cls_BiTgte_Blend.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("Radius"), py::arg("Tol"), py::arg("NUBS"));
	cls_BiTgte_Blend.def("Init", (void (BiTgte_Blend::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BiTgte_Blend::Init, "None", py::arg("S"), py::arg("Radius"), py::arg("Tol"), py::arg("NUBS"));
	cls_BiTgte_Blend.def("Clear", (void (BiTgte_Blend::*)()) &BiTgte_Blend::Clear, "Clear all the Fields.");
	cls_BiTgte_Blend.def("SetFaces", (void (BiTgte_Blend::*)(const TopoDS_Face &, const TopoDS_Face &)) &BiTgte_Blend::SetFaces, "Set two faces of <myShape> on which the Sphere must roll.", py::arg("F1"), py::arg("F2"));
	cls_BiTgte_Blend.def("SetEdge", (void (BiTgte_Blend::*)(const TopoDS_Edge &)) &BiTgte_Blend::SetEdge, "Set an edge of <myShape> to be rounded.", py::arg("Edge"));
	cls_BiTgte_Blend.def("SetStoppingFace", (void (BiTgte_Blend::*)(const TopoDS_Face &)) &BiTgte_Blend::SetStoppingFace, "Set a face on which the fillet must stop.", py::arg("Face"));
	cls_BiTgte_Blend.def("Perform", [](BiTgte_Blend &self) -> void { return self.Perform(); });
	cls_BiTgte_Blend.def("Perform", (void (BiTgte_Blend::*)(const Standard_Boolean)) &BiTgte_Blend::Perform, "Compute the generated surfaces. If <BuildShape> is true, compute the resulting Shape. If false, only the blending surfaces are computed.", py::arg("BuildShape"));
	cls_BiTgte_Blend.def("IsDone", (Standard_Boolean (BiTgte_Blend::*)() const ) &BiTgte_Blend::IsDone, "None");
	cls_BiTgte_Blend.def("Shape", (const TopoDS_Shape & (BiTgte_Blend::*)() const ) &BiTgte_Blend::Shape, "returns the result");
	cls_BiTgte_Blend.def("NbSurfaces", (Standard_Integer (BiTgte_Blend::*)() const ) &BiTgte_Blend::NbSurfaces, "returns the Number of generated surfaces.");
	cls_BiTgte_Blend.def("Surface", (opencascade::handle<Geom_Surface> (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::Surface, "returns the surface of range Index", py::arg("Index"));
	cls_BiTgte_Blend.def("Face", (const TopoDS_Face & (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::Face, "returns the surface of range Index", py::arg("Index"));
	cls_BiTgte_Blend.def("CenterLines", (void (BiTgte_Blend::*)(TopTools_ListOfShape &) const ) &BiTgte_Blend::CenterLines, "set in <LC> all the center lines", py::arg("LC"));
	cls_BiTgte_Blend.def("Surface", (opencascade::handle<Geom_Surface> (BiTgte_Blend::*)(const TopoDS_Shape &) const ) &BiTgte_Blend::Surface, "returns the surface generated by the centerline. <CenterLine> may be - an edge : generate a pipe. - a vertex : generate a sphere. Warning: returns a Null Handle if <CenterLine> generates no surface.", py::arg("CenterLine"));
	cls_BiTgte_Blend.def("Face", (const TopoDS_Face & (BiTgte_Blend::*)(const TopoDS_Shape &) const ) &BiTgte_Blend::Face, "returns the face generated by the centerline. <CenterLine> may be - an edge : generate a pipe. - a vertex : generate a sphere. Warning: returns a Null Shape if <CenterLine> generates no surface.", py::arg("CenterLine"));
	cls_BiTgte_Blend.def("ContactType", (BiTgte_ContactType (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::ContactType, "returns the type of contact", py::arg("Index"));
	cls_BiTgte_Blend.def("SupportShape1", (const TopoDS_Shape & (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::SupportShape1, "gives the first support shape relative to SurfaceFillet(Index);", py::arg("Index"));
	cls_BiTgte_Blend.def("SupportShape2", (const TopoDS_Shape & (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::SupportShape2, "gives the second support shape relative to SurfaceFillet(Index);", py::arg("Index"));
	cls_BiTgte_Blend.def("CurveOnShape1", (opencascade::handle<Geom_Curve> (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::CurveOnShape1, "gives the 3d curve of SurfaceFillet(Index) on SupportShape1(Index)", py::arg("Index"));
	cls_BiTgte_Blend.def("CurveOnShape2", (opencascade::handle<Geom_Curve> (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::CurveOnShape2, "gives the 3d curve of SurfaceFillet(Index) on SupportShape2(Index)", py::arg("Index"));
	cls_BiTgte_Blend.def("PCurveOnFace1", (opencascade::handle<Geom2d_Curve> (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::PCurveOnFace1, "gives the PCurve associated to CurvOnShape1(Index) on the support face Warning: returns a Null Handle if SupportShape1 is not a Face", py::arg("Index"));
	cls_BiTgte_Blend.def("PCurve1OnFillet", (opencascade::handle<Geom2d_Curve> (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::PCurve1OnFillet, "gives the PCurve associated to CurveOnShape1(Index) on the Fillet", py::arg("Index"));
	cls_BiTgte_Blend.def("PCurveOnFace2", (opencascade::handle<Geom2d_Curve> (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::PCurveOnFace2, "gives the PCurve associated to CurveOnShape2(Index) on the support face Warning: returns a Null Handle if SupportShape2 is not a Face", py::arg("Index"));
	cls_BiTgte_Blend.def("PCurve2OnFillet", (opencascade::handle<Geom2d_Curve> (BiTgte_Blend::*)(const Standard_Integer) const ) &BiTgte_Blend::PCurve2OnFillet, "gives the PCurve associated to CurveOnShape2(Index) on the fillet", py::arg("Index"));
	cls_BiTgte_Blend.def("NbBranches", (Standard_Integer (BiTgte_Blend::*)()) &BiTgte_Blend::NbBranches, "None");
	cls_BiTgte_Blend.def("IndicesOfBranche", (void (BiTgte_Blend::*)(const Standard_Integer, Standard_Integer &, Standard_Integer &) const ) &BiTgte_Blend::IndicesOfBranche, "Set in <From>,<To> the indices of the faces of the branche <Index>.", py::arg("Index"), py::arg("From"), py::arg("To"));
	cls_BiTgte_Blend.def("ComputeCenters", (void (BiTgte_Blend::*)()) &BiTgte_Blend::ComputeCenters, "Computes the center lines");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BiTgte_CurveOnEdge.hxx
	py::class_<BiTgte_CurveOnEdge, std::unique_ptr<BiTgte_CurveOnEdge, Deleter<BiTgte_CurveOnEdge>>, Adaptor3d_Curve> cls_BiTgte_CurveOnEdge(mod, "BiTgte_CurveOnEdge", "private class used to create a filler rolling on an edge.");
	cls_BiTgte_CurveOnEdge.def(py::init<>());
	cls_BiTgte_CurveOnEdge.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("EonF"), py::arg("Edge"));
	cls_BiTgte_CurveOnEdge.def("Init", (void (BiTgte_CurveOnEdge::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &BiTgte_CurveOnEdge::Init, "None", py::arg("EonF"), py::arg("Edge"));
	cls_BiTgte_CurveOnEdge.def("FirstParameter", (Standard_Real (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::FirstParameter, "None");
	cls_BiTgte_CurveOnEdge.def("LastParameter", (Standard_Real (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::LastParameter, "None");
	cls_BiTgte_CurveOnEdge.def("Continuity", (GeomAbs_Shape (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::Continuity, "None");
	cls_BiTgte_CurveOnEdge.def("NbIntervals", (Standard_Integer (BiTgte_CurveOnEdge::*)(const GeomAbs_Shape) const ) &BiTgte_CurveOnEdge::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BiTgte_CurveOnEdge.def("Intervals", (void (BiTgte_CurveOnEdge::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BiTgte_CurveOnEdge::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BiTgte_CurveOnEdge.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (BiTgte_CurveOnEdge::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &BiTgte_CurveOnEdge::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_BiTgte_CurveOnEdge.def("IsClosed", (Standard_Boolean (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::IsClosed, "None");
	cls_BiTgte_CurveOnEdge.def("IsPeriodic", (Standard_Boolean (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::IsPeriodic, "None");
	cls_BiTgte_CurveOnEdge.def("Period", (Standard_Real (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::Period, "None");
	cls_BiTgte_CurveOnEdge.def("Value", (gp_Pnt (BiTgte_CurveOnEdge::*)(const Standard_Real) const ) &BiTgte_CurveOnEdge::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_BiTgte_CurveOnEdge.def("D0", (void (BiTgte_CurveOnEdge::*)(const Standard_Real, gp_Pnt &) const ) &BiTgte_CurveOnEdge::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_BiTgte_CurveOnEdge.def("D1", (void (BiTgte_CurveOnEdge::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &BiTgte_CurveOnEdge::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_BiTgte_CurveOnEdge.def("D2", (void (BiTgte_CurveOnEdge::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &BiTgte_CurveOnEdge::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_BiTgte_CurveOnEdge.def("D3", (void (BiTgte_CurveOnEdge::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BiTgte_CurveOnEdge::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_BiTgte_CurveOnEdge.def("DN", (gp_Vec (BiTgte_CurveOnEdge::*)(const Standard_Real, const Standard_Integer) const ) &BiTgte_CurveOnEdge::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_BiTgte_CurveOnEdge.def("Resolution", (Standard_Real (BiTgte_CurveOnEdge::*)(const Standard_Real) const ) &BiTgte_CurveOnEdge::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_BiTgte_CurveOnEdge.def("GetType", (GeomAbs_CurveType (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
	cls_BiTgte_CurveOnEdge.def("Line", (gp_Lin (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::Line, "None");
	cls_BiTgte_CurveOnEdge.def("Circle", (gp_Circ (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::Circle, "None");
	cls_BiTgte_CurveOnEdge.def("Ellipse", (gp_Elips (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::Ellipse, "None");
	cls_BiTgte_CurveOnEdge.def("Hyperbola", (gp_Hypr (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::Hyperbola, "None");
	cls_BiTgte_CurveOnEdge.def("Parabola", (gp_Parab (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::Parabola, "None");
	cls_BiTgte_CurveOnEdge.def("Degree", (Standard_Integer (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::Degree, "None");
	cls_BiTgte_CurveOnEdge.def("IsRational", (Standard_Boolean (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::IsRational, "None");
	cls_BiTgte_CurveOnEdge.def("NbPoles", (Standard_Integer (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::NbPoles, "None");
	cls_BiTgte_CurveOnEdge.def("NbKnots", (Standard_Integer (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::NbKnots, "None");
	cls_BiTgte_CurveOnEdge.def("Bezier", (opencascade::handle<Geom_BezierCurve> (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::Bezier, "None");
	cls_BiTgte_CurveOnEdge.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (BiTgte_CurveOnEdge::*)() const ) &BiTgte_CurveOnEdge::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BiTgte_CurveOnVertex.hxx
	py::class_<BiTgte_CurveOnVertex, std::unique_ptr<BiTgte_CurveOnVertex, Deleter<BiTgte_CurveOnVertex>>, Adaptor3d_Curve> cls_BiTgte_CurveOnVertex(mod, "BiTgte_CurveOnVertex", "private class used to create a filler rolling on an edge.");
	cls_BiTgte_CurveOnVertex.def(py::init<>());
	cls_BiTgte_CurveOnVertex.def(py::init<const TopoDS_Edge &, const TopoDS_Vertex &>(), py::arg("EonF"), py::arg("V"));
	cls_BiTgte_CurveOnVertex.def("Init", (void (BiTgte_CurveOnVertex::*)(const TopoDS_Edge &, const TopoDS_Vertex &)) &BiTgte_CurveOnVertex::Init, "None", py::arg("EonF"), py::arg("V"));
	cls_BiTgte_CurveOnVertex.def("FirstParameter", (Standard_Real (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::FirstParameter, "None");
	cls_BiTgte_CurveOnVertex.def("LastParameter", (Standard_Real (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::LastParameter, "None");
	cls_BiTgte_CurveOnVertex.def("Continuity", (GeomAbs_Shape (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::Continuity, "None");
	cls_BiTgte_CurveOnVertex.def("NbIntervals", (Standard_Integer (BiTgte_CurveOnVertex::*)(const GeomAbs_Shape) const ) &BiTgte_CurveOnVertex::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BiTgte_CurveOnVertex.def("Intervals", (void (BiTgte_CurveOnVertex::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BiTgte_CurveOnVertex::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BiTgte_CurveOnVertex.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (BiTgte_CurveOnVertex::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &BiTgte_CurveOnVertex::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_BiTgte_CurveOnVertex.def("IsClosed", (Standard_Boolean (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::IsClosed, "None");
	cls_BiTgte_CurveOnVertex.def("IsPeriodic", (Standard_Boolean (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::IsPeriodic, "None");
	cls_BiTgte_CurveOnVertex.def("Period", (Standard_Real (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::Period, "None");
	cls_BiTgte_CurveOnVertex.def("Value", (gp_Pnt (BiTgte_CurveOnVertex::*)(const Standard_Real) const ) &BiTgte_CurveOnVertex::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_BiTgte_CurveOnVertex.def("D0", (void (BiTgte_CurveOnVertex::*)(const Standard_Real, gp_Pnt &) const ) &BiTgte_CurveOnVertex::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_BiTgte_CurveOnVertex.def("D1", (void (BiTgte_CurveOnVertex::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &BiTgte_CurveOnVertex::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_BiTgte_CurveOnVertex.def("D2", (void (BiTgte_CurveOnVertex::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &BiTgte_CurveOnVertex::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_BiTgte_CurveOnVertex.def("D3", (void (BiTgte_CurveOnVertex::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BiTgte_CurveOnVertex::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_BiTgte_CurveOnVertex.def("DN", (gp_Vec (BiTgte_CurveOnVertex::*)(const Standard_Real, const Standard_Integer) const ) &BiTgte_CurveOnVertex::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_BiTgte_CurveOnVertex.def("Resolution", (Standard_Real (BiTgte_CurveOnVertex::*)(const Standard_Real) const ) &BiTgte_CurveOnVertex::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_BiTgte_CurveOnVertex.def("GetType", (GeomAbs_CurveType (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
	cls_BiTgte_CurveOnVertex.def("Line", (gp_Lin (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::Line, "None");
	cls_BiTgte_CurveOnVertex.def("Circle", (gp_Circ (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::Circle, "None");
	cls_BiTgte_CurveOnVertex.def("Ellipse", (gp_Elips (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::Ellipse, "None");
	cls_BiTgte_CurveOnVertex.def("Hyperbola", (gp_Hypr (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::Hyperbola, "None");
	cls_BiTgte_CurveOnVertex.def("Parabola", (gp_Parab (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::Parabola, "None");
	cls_BiTgte_CurveOnVertex.def("Degree", (Standard_Integer (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::Degree, "None");
	cls_BiTgte_CurveOnVertex.def("IsRational", (Standard_Boolean (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::IsRational, "None");
	cls_BiTgte_CurveOnVertex.def("NbPoles", (Standard_Integer (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::NbPoles, "None");
	cls_BiTgte_CurveOnVertex.def("NbKnots", (Standard_Integer (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::NbKnots, "None");
	cls_BiTgte_CurveOnVertex.def("Bezier", (opencascade::handle<Geom_BezierCurve> (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::Bezier, "None");
	cls_BiTgte_CurveOnVertex.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (BiTgte_CurveOnVertex::*)() const ) &BiTgte_CurveOnVertex::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BiTgte_HCurveOnEdge.hxx
	py::class_<BiTgte_HCurveOnEdge, opencascade::handle<BiTgte_HCurveOnEdge>, Adaptor3d_HCurve> cls_BiTgte_HCurveOnEdge(mod, "BiTgte_HCurveOnEdge", "None");
	cls_BiTgte_HCurveOnEdge.def(py::init<>());
	cls_BiTgte_HCurveOnEdge.def(py::init<const BiTgte_CurveOnEdge &>(), py::arg("C"));
	cls_BiTgte_HCurveOnEdge.def("Set", (void (BiTgte_HCurveOnEdge::*)(const BiTgte_CurveOnEdge &)) &BiTgte_HCurveOnEdge::Set, "Sets the field of the GenHCurve.", py::arg("C"));
	cls_BiTgte_HCurveOnEdge.def("Curve", (const Adaptor3d_Curve & (BiTgte_HCurveOnEdge::*)() const ) &BiTgte_HCurveOnEdge::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_BiTgte_HCurveOnEdge.def("GetCurve", (Adaptor3d_Curve & (BiTgte_HCurveOnEdge::*)()) &BiTgte_HCurveOnEdge::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_BiTgte_HCurveOnEdge.def("ChangeCurve", (BiTgte_CurveOnEdge & (BiTgte_HCurveOnEdge::*)()) &BiTgte_HCurveOnEdge::ChangeCurve, "Returns the curve used to create the GenHCurve.");
	cls_BiTgte_HCurveOnEdge.def_static("get_type_name_", (const char * (*)()) &BiTgte_HCurveOnEdge::get_type_name, "None");
	cls_BiTgte_HCurveOnEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BiTgte_HCurveOnEdge::get_type_descriptor, "None");
	cls_BiTgte_HCurveOnEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BiTgte_HCurveOnEdge::*)() const ) &BiTgte_HCurveOnEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BiTgte_HCurveOnVertex.hxx
	py::class_<BiTgte_HCurveOnVertex, opencascade::handle<BiTgte_HCurveOnVertex>, Adaptor3d_HCurve> cls_BiTgte_HCurveOnVertex(mod, "BiTgte_HCurveOnVertex", "None");
	cls_BiTgte_HCurveOnVertex.def(py::init<>());
	cls_BiTgte_HCurveOnVertex.def(py::init<const BiTgte_CurveOnVertex &>(), py::arg("C"));
	cls_BiTgte_HCurveOnVertex.def("Set", (void (BiTgte_HCurveOnVertex::*)(const BiTgte_CurveOnVertex &)) &BiTgte_HCurveOnVertex::Set, "Sets the field of the GenHCurve.", py::arg("C"));
	cls_BiTgte_HCurveOnVertex.def("Curve", (const Adaptor3d_Curve & (BiTgte_HCurveOnVertex::*)() const ) &BiTgte_HCurveOnVertex::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_BiTgte_HCurveOnVertex.def("GetCurve", (Adaptor3d_Curve & (BiTgte_HCurveOnVertex::*)()) &BiTgte_HCurveOnVertex::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_BiTgte_HCurveOnVertex.def("ChangeCurve", (BiTgte_CurveOnVertex & (BiTgte_HCurveOnVertex::*)()) &BiTgte_HCurveOnVertex::ChangeCurve, "Returns the curve used to create the GenHCurve.");
	cls_BiTgte_HCurveOnVertex.def_static("get_type_name_", (const char * (*)()) &BiTgte_HCurveOnVertex::get_type_name, "None");
	cls_BiTgte_HCurveOnVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BiTgte_HCurveOnVertex::get_type_descriptor, "None");
	cls_BiTgte_HCurveOnVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (BiTgte_HCurveOnVertex::*)() const ) &BiTgte_HCurveOnVertex::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BiTgte_DataMapOfShapeBox, std::unique_ptr<BiTgte_DataMapOfShapeBox, Deleter<BiTgte_DataMapOfShapeBox>>, NCollection_BaseMap> cls_BiTgte_DataMapOfShapeBox(mod, "BiTgte_DataMapOfShapeBox", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BiTgte_DataMapOfShapeBox.def(py::init<>());
	cls_BiTgte_DataMapOfShapeBox.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BiTgte_DataMapOfShapeBox.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BiTgte_DataMapOfShapeBox.def(py::init([] (const BiTgte_DataMapOfShapeBox &other) {return new BiTgte_DataMapOfShapeBox(other);}), "Copy constructor", py::arg("other"));
	cls_BiTgte_DataMapOfShapeBox.def("begin", (BiTgte_DataMapOfShapeBox::iterator (BiTgte_DataMapOfShapeBox::*)() const ) &BiTgte_DataMapOfShapeBox::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BiTgte_DataMapOfShapeBox.def("end", (BiTgte_DataMapOfShapeBox::iterator (BiTgte_DataMapOfShapeBox::*)() const ) &BiTgte_DataMapOfShapeBox::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BiTgte_DataMapOfShapeBox.def("cbegin", (BiTgte_DataMapOfShapeBox::const_iterator (BiTgte_DataMapOfShapeBox::*)() const ) &BiTgte_DataMapOfShapeBox::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BiTgte_DataMapOfShapeBox.def("cend", (BiTgte_DataMapOfShapeBox::const_iterator (BiTgte_DataMapOfShapeBox::*)() const ) &BiTgte_DataMapOfShapeBox::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BiTgte_DataMapOfShapeBox.def("Exchange", (void (BiTgte_DataMapOfShapeBox::*)(BiTgte_DataMapOfShapeBox &)) &BiTgte_DataMapOfShapeBox::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BiTgte_DataMapOfShapeBox.def("Assign", (BiTgte_DataMapOfShapeBox & (BiTgte_DataMapOfShapeBox::*)(const BiTgte_DataMapOfShapeBox &)) &BiTgte_DataMapOfShapeBox::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BiTgte_DataMapOfShapeBox.def("assign", (BiTgte_DataMapOfShapeBox & (BiTgte_DataMapOfShapeBox::*)(const BiTgte_DataMapOfShapeBox &)) &BiTgte_DataMapOfShapeBox::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BiTgte_DataMapOfShapeBox.def("ReSize", (void (BiTgte_DataMapOfShapeBox::*)(const Standard_Integer)) &BiTgte_DataMapOfShapeBox::ReSize, "ReSize", py::arg("N"));
	cls_BiTgte_DataMapOfShapeBox.def("Bind", (Standard_Boolean (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &, const Bnd_Box &)) &BiTgte_DataMapOfShapeBox::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BiTgte_DataMapOfShapeBox.def("Bound", (Bnd_Box * (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &, const Bnd_Box &)) &BiTgte_DataMapOfShapeBox::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BiTgte_DataMapOfShapeBox.def("IsBound", (Standard_Boolean (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &BiTgte_DataMapOfShapeBox::IsBound, "IsBound", py::arg("theKey"));
	cls_BiTgte_DataMapOfShapeBox.def("UnBind", (Standard_Boolean (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &)) &BiTgte_DataMapOfShapeBox::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BiTgte_DataMapOfShapeBox.def("Seek", (const Bnd_Box * (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &BiTgte_DataMapOfShapeBox::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BiTgte_DataMapOfShapeBox.def("Find", (const Bnd_Box & (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &BiTgte_DataMapOfShapeBox::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BiTgte_DataMapOfShapeBox.def("Find", (Standard_Boolean (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &, Bnd_Box &) const ) &BiTgte_DataMapOfShapeBox::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BiTgte_DataMapOfShapeBox.def("__call__", (const Bnd_Box & (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &BiTgte_DataMapOfShapeBox::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BiTgte_DataMapOfShapeBox.def("ChangeSeek", (Bnd_Box * (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &)) &BiTgte_DataMapOfShapeBox::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BiTgte_DataMapOfShapeBox.def("ChangeFind", (Bnd_Box & (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &)) &BiTgte_DataMapOfShapeBox::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BiTgte_DataMapOfShapeBox.def("__call__", (Bnd_Box & (BiTgte_DataMapOfShapeBox::*)(const TopoDS_Shape &)) &BiTgte_DataMapOfShapeBox::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BiTgte_DataMapOfShapeBox.def("Clear", [](BiTgte_DataMapOfShapeBox &self) -> void { return self.Clear(); });
	cls_BiTgte_DataMapOfShapeBox.def("Clear", (void (BiTgte_DataMapOfShapeBox::*)(const Standard_Boolean)) &BiTgte_DataMapOfShapeBox::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BiTgte_DataMapOfShapeBox.def("Clear", (void (BiTgte_DataMapOfShapeBox::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BiTgte_DataMapOfShapeBox::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BiTgte_DataMapOfShapeBox.def("Size", (Standard_Integer (BiTgte_DataMapOfShapeBox::*)() const ) &BiTgte_DataMapOfShapeBox::Size, "Size");
	cls_BiTgte_DataMapOfShapeBox.def("__iter__", [](const BiTgte_DataMapOfShapeBox &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BiTgte_DataMapOfShapeBox.hxx

}
