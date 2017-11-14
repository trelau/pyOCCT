#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_Spine.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Geom_Surface.hxx>
#include <ChFiDS_ErrorStatus.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <ChFiDS_SurfData.hxx>
#include <ChFiDS_SequenceOfSurfData.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <math_Vector.hxx>
#include <ChFiDS_Stripe.hxx>
#include <ChFiDS_ListOfStripe.hxx>
#include <TopAbs_State.hxx>
#include <ChFi3d_Builder.hxx>
#include <TopoDS_Face.hxx>
#include <ChFiDS_ChamfMethod.hxx>
#include <ChFiDS_SecHArray1.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <ChFi3d_ChBuilder.hxx>
#include <ChFi3d_FilletShape.hxx>
#include <Law_Function.hxx>
#include <gp_XY.hxx>
#include <ChFi3d_FilBuilder.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Geom_Curve.hxx>
#include <ChFi3d_SearchSing.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <ChFi3d.hxx>
#include <ChFi3d_Builder_0.hxx>
#include <gp_Pnt2d.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <Bnd_Box.hxx>
#include <ChFiDS_Map.hxx>
#include <ChFiDS_State.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Geom_Circle.hxx>
#include <Geom_BezierCurve.hxx>
#include <GeomFill_Boundary.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Vec2d.hxx>
#include <ChFiDS_CommonPoint.hxx>
#include <TopOpeBRepDS_SurfaceCurveInterference.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <BRepBlend_Extremity.hxx>
#include <TopOpeBRepDS_CurvePointInterference.hxx>
#include <ChFiDS_Regularities.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <ChFiDS_FaceInterference.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <Geom_BSplineCurve.hxx>

PYBIND11_MODULE(ChFi3d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.ChFiDS");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopOpeBRepBuild");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.BRepAdaptor");
	py::module::import("OCCT.math");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.Law");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopOpeBRepDS");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.GeomAdaptor");
	py::module::import("OCCT.GeomFill");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.IntSurf");
	py::module::import("OCCT.BRepBlend");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_FilletShape.hxx
	py::enum_<ChFi3d_FilletShape>(mod, "ChFi3d_FilletShape", "Lists the types of fillet shapes. These include the following: - ChFi3d_Rational (default value), which is the standard NURBS representation of circles, - ChFi3d_QuasiAngular, which is a NURBS representation of circles where the parameters match those of the circle, - ChFi3d_Polynomial, which corresponds to a polynomial approximation of circles. This type facilitates the implementation of the construction algorithm.")
		.value("ChFi3d_Rational", ChFi3d_FilletShape::ChFi3d_Rational)
		.value("ChFi3d_QuasiAngular", ChFi3d_FilletShape::ChFi3d_QuasiAngular)
		.value("ChFi3d_Polynomial", ChFi3d_FilletShape::ChFi3d_Polynomial)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_InPeriod", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ChFi3d_InPeriod, "None", py::arg("U"), py::arg("UFirst"), py::arg("ULast"), py::arg("Eps"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_Boite", (void (*)(const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &)) &ChFi3d_Boite, "None", py::arg("p1"), py::arg("p2"), py::arg("p3"), py::arg("p4"), py::arg("Du"), py::arg("Dv"), py::arg("mu"), py::arg("Mu"), py::arg("mv"), py::arg("Mv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_SetPointTolerance", (void (*)(TopOpeBRepDS_DataStructure &, const Bnd_Box &, const Standard_Integer)) &ChFi3d_SetPointTolerance, "None", py::arg("DStr"), py::arg("box"), py::arg("IP"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_EnlargeBox", (void (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_Stripe> &, const opencascade::handle<ChFiDS_SurfData> &, Bnd_Box &, Bnd_Box &, const Standard_Boolean)) &ChFi3d_EnlargeBox, "None", py::arg("DStr"), py::arg("st"), py::arg("sd"), py::arg("b1"), py::arg("b2"), py::arg("isfirst"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_evalconti", (GeomAbs_Shape (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &ChFi3d_evalconti, "None", py::arg("E"), py::arg("F1"), py::arg("F2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_conexfaces", (void (*)(const TopoDS_Edge &, TopoDS_Face &, TopoDS_Face &, const ChFiDS_Map &)) &ChFi3d_conexfaces, "None", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("EFMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_EdgeState", (ChFiDS_State (*)(TopoDS_Edge *, const ChFiDS_Map &)) &ChFi3d_EdgeState, "None", py::arg("E"), py::arg("EFMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_KParticular", (Standard_Boolean (*)(const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer, const BRepAdaptor_Surface &, const BRepAdaptor_Surface &)) &ChFi3d_KParticular, "None", py::arg("Spine"), py::arg("IE"), py::arg("S1"), py::arg("S2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_BoundFac", (void (*)(BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &ChFi3d_BoundFac, "None", py::arg("S"), py::arg("umin"), py::arg("umax"), py::arg("vmin"), py::arg("vmax"), py::arg("checknaturalbounds") = Standard_True);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_BoundSrf", (void (*)(GeomAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &ChFi3d_BoundSrf, "None", py::arg("S"), py::arg("umin"), py::arg("umax"), py::arg("vmin"), py::arg("vmax"), py::arg("checknaturalbounds") = Standard_True);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_InterPlaneEdge", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, Standard_Real &, const Standard_Boolean, const Standard_Real)) &ChFi3d_InterPlaneEdge, "None", py::arg("Plan"), py::arg("C"), py::arg("W"), py::arg("Sens"), py::arg("tolc"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ExtrSpineCarac", (void (*)(const TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_Stripe> &, const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer, gp_Pnt &, gp_Vec &, Standard_Real &)) &ChFi3d_ExtrSpineCarac, "None", py::arg("DStr"), py::arg("cd"), py::arg("i"), py::arg("p"), py::arg("jf"), py::arg("sens"), py::arg("P"), py::arg("V"), py::arg("R"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_CircularSpine", (opencascade::handle<Geom_Circle> (*)(Standard_Real &, Standard_Real &, const gp_Pnt &, const gp_Vec &, const gp_Pnt &, const gp_Vec &, const Standard_Real)) &ChFi3d_CircularSpine, "None", py::arg("WFirst"), py::arg("WLast"), py::arg("Pdeb"), py::arg("Vdeb"), py::arg("Pfin"), py::arg("Vfin"), py::arg("rad"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_Spine", (opencascade::handle<Geom_BezierCurve> (*)(const gp_Pnt &, gp_Vec &, const gp_Pnt &, gp_Vec &, const Standard_Real)) &ChFi3d_Spine, "None", py::arg("pd"), py::arg("vd"), py::arg("pf"), py::arg("vf"), py::arg("R"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_mkbound", (opencascade::handle<GeomFill_Boundary> (*)(const opencascade::handle<Adaptor3d_HSurface> &, opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &ChFi3d_mkbound, "None", py::arg("Fac"), py::arg("curv"), py::arg("p1"), py::arg("p2"), py::arg("t3d"), py::arg("ta"), py::arg("isfreeboundary") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_Coefficient", (void (*)(const gp_Vec &, const gp_Vec &, const gp_Vec &, Standard_Real &, Standard_Real &)) &ChFi3d_Coefficient, "None", py::arg("V3d"), py::arg("D1u"), py::arg("D1v"), py::arg("DU"), py::arg("DV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_BuildPCurve", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Adaptor3d_HSurface> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Pnt2d &, const gp_Vec2d &, const Standard_Boolean)) &ChFi3d_BuildPCurve, "None", py::arg("Surf"), py::arg("p1"), py::arg("v1"), py::arg("p2"), py::arg("v2"), py::arg("redresse") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_CheckSameParameter", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HCurve> &, opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, Standard_Real &)) &ChFi3d_CheckSameParameter, "None", py::arg("C3d"), py::arg("Pcurv"), py::arg("S"), py::arg("tol3d"), py::arg("tolreached"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_SameParameter", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &, opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real &)) &ChFi3d_SameParameter, "None", py::arg("C3d"), py::arg("Pcurv"), py::arg("S"), py::arg("Pardeb"), py::arg("Parfin"), py::arg("tol3d"), py::arg("tolreached"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ComputePCurv", (void (*)(const gp_Pnt2d &, const gp_Pnt2d &, opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &ChFi3d_ComputePCurv, "None", py::arg("UV1"), py::arg("UV2"), py::arg("Pcurv"), py::arg("Pardeb"), py::arg("Parfin"), py::arg("reverse") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_IntTraces", (Standard_Boolean (*)(const opencascade::handle<ChFiDS_SurfData> &, const Standard_Real, Standard_Real &, const Standard_Integer, const Standard_Integer, const opencascade::handle<ChFiDS_SurfData> &, const Standard_Real, Standard_Real &, const Standard_Integer, const Standard_Integer, const gp_Pnt2d &, const Standard_Boolean, const Standard_Boolean)) &ChFi3d_IntTraces, "None", py::arg("fd1"), py::arg("pref1"), py::arg("p1"), py::arg("jf1"), py::arg("sens1"), py::arg("fd2"), py::arg("pref2"), py::arg("p2"), py::arg("jf2"), py::arg("sens2"), py::arg("RefP2d"), py::arg("Check2dDistance") = Standard_False, py::arg("enlarge") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_IsInFront", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_Stripe> &, const opencascade::handle<ChFiDS_Stripe> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, Standard_Real &, Standard_Real &, TopoDS_Face &, Standard_Boolean &, Standard_Integer &, Standard_Integer &, Standard_Boolean &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean)) &ChFi3d_IsInFront, "None", py::arg("DStr"), py::arg("cd1"), py::arg("cd2"), py::arg("i1"), py::arg("i2"), py::arg("sens1"), py::arg("sens2"), py::arg("p1"), py::arg("p2"), py::arg("face"), py::arg("sameside"), py::arg("jf1"), py::arg("jf2"), py::arg("visavis"), py::arg("Vtx"), py::arg("Check2dDistance") = Standard_False, py::arg("enlarge") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ProjectPCurv", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, opencascade::handle<Geom2d_Curve> &, const Standard_Real, Standard_Real &)) &ChFi3d_ProjectPCurv, "None", py::arg("HCg"), py::arg("HSg"), py::arg("Pcurv"), py::arg("tol3d"), py::arg("tolreached"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ReparamPcurv", (void (*)(const Standard_Real, const Standard_Real, opencascade::handle<Geom2d_Curve> &)) &ChFi3d_ReparamPcurv, "None", py::arg("Uf"), py::arg("Ul"), py::arg("Pcurv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ComputeArete", (void (*)(const ChFiDS_CommonPoint &, const gp_Pnt2d &, const ChFiDS_CommonPoint &, const gp_Pnt2d &, const opencascade::handle<Geom_Surface> &, opencascade::handle<Geom_Curve> &, opencascade::handle<Geom2d_Curve> &, Standard_Real &, Standard_Real &, const Standard_Real, const Standard_Real, Standard_Real &, const Standard_Integer)) &ChFi3d_ComputeArete, "None", py::arg("P1"), py::arg("UV1"), py::arg("P2"), py::arg("UV2"), py::arg("Surf"), py::arg("C3d"), py::arg("Pcurv"), py::arg("Pardeb"), py::arg("Parfin"), py::arg("tol3d"), py::arg("tol2d"), py::arg("tolreached"), py::arg("IFlag"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_FilCurveInDS", (opencascade::handle<TopOpeBRepDS_SurfaceCurveInterference> (*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<Geom2d_Curve> &, const TopAbs_Orientation)) &ChFi3d_FilCurveInDS, "None", py::arg("Icurv"), py::arg("Isurf"), py::arg("Pcurv"), py::arg("Et"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_TrsfTrans", (TopAbs_Orientation (*)(const IntSurf_TypeTrans)) &ChFi3d_TrsfTrans, "None", py::arg("T1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_FilCommonPoint", (void (*)(const BRepBlend_Extremity &, const IntSurf_TypeTrans, const Standard_Boolean, ChFiDS_CommonPoint &, const Standard_Real)) &ChFi3d_FilCommonPoint, "None", py::arg("SP"), py::arg("TransLine"), py::arg("Start"), py::arg("CP"), py::arg("Tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_SolidIndex", (Standard_Integer (*)(const opencascade::handle<ChFiDS_Spine> &, TopOpeBRepDS_DataStructure &, ChFiDS_Map &, ChFiDS_Map &)) &ChFi3d_SolidIndex, "None", py::arg("sp"), py::arg("DStr"), py::arg("MapESo"), py::arg("MapESh"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_IndexPointInDS", (Standard_Integer (*)(const ChFiDS_CommonPoint &, TopOpeBRepDS_DataStructure &)) &ChFi3d_IndexPointInDS, "None", py::arg("P1"), py::arg("DStr"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_FilPointInDS", (opencascade::handle<TopOpeBRepDS_CurvePointInterference> (*)(const TopAbs_Orientation, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Boolean)) &ChFi3d_FilPointInDS, "None", py::arg("Et"), py::arg("Ic"), py::arg("Ip"), py::arg("Par"), py::arg("IsVertex") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_FilVertexInDS", (opencascade::handle<TopOpeBRepDS_CurvePointInterference> (*)(const TopAbs_Orientation, const Standard_Integer, const Standard_Integer, const Standard_Real)) &ChFi3d_FilVertexInDS, "None", py::arg("Et"), py::arg("Ic"), py::arg("Ip"), py::arg("Par"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_FilDS", (void (*)(const Standard_Integer, const opencascade::handle<ChFiDS_Stripe> &, TopOpeBRepDS_DataStructure &, ChFiDS_Regularities &, const Standard_Real, const Standard_Real)) &ChFi3d_FilDS, "None", py::arg("SolidIndex"), py::arg("CorDat"), py::arg("DStr"), py::arg("reglist"), py::arg("tol3d"), py::arg("tol2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_StripeEdgeInter", (void (*)(const opencascade::handle<ChFiDS_Stripe> &, const opencascade::handle<ChFiDS_Stripe> &, TopOpeBRepDS_DataStructure &, const Standard_Real)) &ChFi3d_StripeEdgeInter, "None", py::arg("theStripe1"), py::arg("theStripe2"), py::arg("DStr"), py::arg("tol2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_IndexOfSurfData", (Standard_Integer (*)(const TopoDS_Vertex &, const opencascade::handle<ChFiDS_Stripe> &, Standard_Integer &)) &ChFi3d_IndexOfSurfData, "None", py::arg("V1"), py::arg("CD"), py::arg("sens"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_EdgeFromV1", (TopoDS_Edge (*)(const TopoDS_Vertex &, const opencascade::handle<ChFiDS_Stripe> &, Standard_Integer &)) &ChFi3d_EdgeFromV1, "None", py::arg("V1"), py::arg("CD"), py::arg("sens"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ConvTol2dToTol3d", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real)) &ChFi3d_ConvTol2dToTol3d, "None", py::arg("S"), py::arg("tol2d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ComputeCurves", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, opencascade::handle<Geom_Curve> &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, Standard_Real &, const Standard_Boolean)) &ChFi3d_ComputeCurves, "None", py::arg("S1"), py::arg("S2"), py::arg("Pardeb"), py::arg("Parfin"), py::arg("C3d"), py::arg("Pc1"), py::arg("Pc2"), py::arg("tol3d"), py::arg("tol2d"), py::arg("tolreached"), py::arg("wholeCurv") = Standard_True);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_IntCS", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, gp_Pnt2d &, Standard_Real &)) &ChFi3d_IntCS, "None", py::arg("S"), py::arg("C"), py::arg("p2dS"), py::arg("wc"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ComputesIntPC", (void (*)(const ChFiDS_FaceInterference &, const ChFiDS_FaceInterference &, const opencascade::handle<GeomAdaptor_HSurface> &, const opencascade::handle<GeomAdaptor_HSurface> &, Standard_Real &, Standard_Real &, gp_Pnt &)) &ChFi3d_ComputesIntPC, "None", py::arg("Fi1"), py::arg("Fi2"), py::arg("HS1"), py::arg("HS2"), py::arg("UInt1"), py::arg("UInt2"), py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_BoundSurf", (opencascade::handle<GeomAdaptor_HSurface> (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const Standard_Integer &, const Standard_Integer &)) &ChFi3d_BoundSurf, "None", py::arg("DStr"), py::arg("Fd1"), py::arg("IFaCo1"), py::arg("IFaArc1"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_SearchPivot", (Standard_Integer (*)(Standard_Integer *, Standard_Real [3][3], const Standard_Real)) &ChFi3d_SearchPivot, "None", py::arg("s"), py::arg("u"), py::arg("t"));
	*/
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_SearchFD", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_Stripe> &, const opencascade::handle<ChFiDS_Stripe> &, const Standard_Integer, const Standard_Integer, Standard_Integer &, Standard_Integer &, Standard_Real &, Standard_Real &, const Standard_Integer, const Standard_Integer, TopoDS_Face &, Standard_Boolean &, Standard_Integer &, Standard_Integer &)) &ChFi3d_SearchFD, "None", py::arg("DStr"), py::arg("cd1"), py::arg("cd2"), py::arg("sens1"), py::arg("sens2"), py::arg("i1"), py::arg("i2"), py::arg("p1"), py::arg("p2"), py::arg("ind1"), py::arg("ind2"), py::arg("face"), py::arg("sameside"), py::arg("jf1"), py::arg("jf2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_Parameters", (void (*)(const opencascade::handle<Geom_Surface> &, const gp_Pnt &, Standard_Real &, Standard_Real &)) &ChFi3d_Parameters, "None", py::arg("S"), py::arg("p3d"), py::arg("u"), py::arg("v"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_TrimCurve", (void (*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, opencascade::handle<Geom_TrimmedCurve> &)) &ChFi3d_TrimCurve, "None", py::arg("gc"), py::arg("FirstP"), py::arg("LastP"), py::arg("gtc"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_PerformElSpine", (void (*)(opencascade::handle<ChFiDS_HElSpine> &, opencascade::handle<ChFiDS_Spine> &, const GeomAbs_Shape, const Standard_Real)) &ChFi3d_PerformElSpine, "None", py::arg("HES"), py::arg("Spine"), py::arg("continuity"), py::arg("tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_EnlargeFace", (TopoDS_Face (*)(const opencascade::handle<ChFiDS_Spine> &, const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Real)) &ChFi3d_EnlargeFace, "None", py::arg("Spine"), py::arg("HS"), py::arg("Tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_cherche_face1", (void (*)(const TopTools_ListOfShape &, const TopoDS_Face &, TopoDS_Face &)) &ChFi3d_cherche_face1, "None", py::arg("map"), py::arg("F1"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_cherche_element", (void (*)(const TopoDS_Vertex &, const TopoDS_Edge &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Vertex &)) &ChFi3d_cherche_element, "None", py::arg("V"), py::arg("E1"), py::arg("F1"), py::arg("E"), py::arg("Vtx"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_EvalTolReached", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Curve> &)) &ChFi3d_EvalTolReached, "None", py::arg("S1"), py::arg("pc1"), py::arg("S2"), py::arg("pc2"), py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_cherche_edge", (void (*)(const TopoDS_Vertex &, const TopTools_Array1OfShape &, const TopoDS_Face &, TopoDS_Edge &, TopoDS_Vertex &)) &ChFi3d_cherche_edge, "None", py::arg("V"), py::arg("E1"), py::arg("F1"), py::arg("E"), py::arg("Vtx"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_nbface", (Standard_Integer (*)(const TopTools_ListOfShape &)) &ChFi3d_nbface, "None", py::arg("mapVF"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_edge_common_faces", (void (*)(const TopTools_ListOfShape &, TopoDS_Face &, TopoDS_Face &)) &ChFi3d_edge_common_faces, "None", py::arg("mapEF"), py::arg("F1"), py::arg("F2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_AngleEdge", (Standard_Real (*)(const TopoDS_Vertex &, const TopoDS_Edge &, const TopoDS_Edge &)) &ChFi3d_AngleEdge, "None", py::arg("Vtx"), py::arg("E1"), py::arg("E2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ChercheBordsLibres", (void (*)(const ChFiDS_Map &, const TopoDS_Vertex &, Standard_Boolean &, TopoDS_Edge &, TopoDS_Edge &)) &ChFi3d_ChercheBordsLibres, "None", py::arg("myVEMap"), py::arg("V1"), py::arg("bordlibre"), py::arg("edgelibre1"), py::arg("edgelibre2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_isTangentFaces", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const GeomAbs_Shape)) &ChFi3d_isTangentFaces, "None", py::arg("theEdge"), py::arg("theFace1"), py::arg("theFace2"), py::arg("Order") = GeomAbs_G1);

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_NbNotDegeneratedEdges", (Standard_Integer (*)(const TopoDS_Vertex &, const ChFiDS_Map &)) &ChFi3d_NbNotDegeneratedEdges, "None", py::arg("Vtx"), py::arg("VEMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_NumberOfEdges", (Standard_Integer (*)(const TopoDS_Vertex &, const ChFiDS_Map &)) &ChFi3d_NumberOfEdges, "None", py::arg("Vtx"), py::arg("VEMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_NumberOfSharpEdges", (Standard_Integer (*)(const TopoDS_Vertex &, const ChFiDS_Map &, const ChFiDS_Map &)) &ChFi3d_NumberOfSharpEdges, "None", py::arg("Vtx"), py::arg("VEMap"), py::arg("EFmap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_cherche_vertex", (void (*)(const TopoDS_Edge &, const TopoDS_Edge &, TopoDS_Vertex &, Standard_Boolean &)) &ChFi3d_cherche_vertex, "None", py::arg("E1"), py::arg("E2"), py::arg("vertex"), py::arg("trouve"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_Couture", (void (*)(const TopoDS_Face &, Standard_Boolean &, TopoDS_Edge &)) &ChFi3d_Couture, "None", py::arg("F"), py::arg("couture"), py::arg("edgecouture"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_CoutureOnVertex", (void (*)(const TopoDS_Face &, const TopoDS_Vertex &, Standard_Boolean &, TopoDS_Edge &)) &ChFi3d_CoutureOnVertex, "None", py::arg("F"), py::arg("V"), py::arg("couture"), py::arg("edgecouture"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_IsPseudoSeam", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &ChFi3d_IsPseudoSeam, "None", py::arg("E"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_ApproxByC2", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<Geom_Curve> &)) &ChFi3d_ApproxByC2, "None", py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder_0.hxx
	mod.def("ChFi3d_IsSmooth", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &)) &ChFi3d_IsSmooth, "None", py::arg("C"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_Builder.hxx
	py::class_<ChFi3d_Builder, std::unique_ptr<ChFi3d_Builder, Deleter<ChFi3d_Builder>>> cls_ChFi3d_Builder(mod, "ChFi3d_Builder", "Root class for calculation of surfaces (fillets, chamfers) destined to smooth edges of a gap on a Shape and the reconstruction of the Shape.");
	cls_ChFi3d_Builder.def("SetParams", (void (ChFi3d_Builder::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ChFi3d_Builder::SetParams, "None", py::arg("Tang"), py::arg("Tesp"), py::arg("T2d"), py::arg("TApp3d"), py::arg("TolApp2d"), py::arg("Fleche"));
	cls_ChFi3d_Builder.def("SetContinuity", (void (ChFi3d_Builder::*)(const GeomAbs_Shape, const Standard_Real)) &ChFi3d_Builder::SetContinuity, "None", py::arg("InternalContinuity"), py::arg("AngularTolerance"));
	cls_ChFi3d_Builder.def("Remove", (void (ChFi3d_Builder::*)(const TopoDS_Edge &)) &ChFi3d_Builder::Remove, "extracts from the list the contour containing edge E.", py::arg("E"));
	cls_ChFi3d_Builder.def("Contains", (Standard_Integer (ChFi3d_Builder::*)(const TopoDS_Edge &) const ) &ChFi3d_Builder::Contains, "gives the number of the contour containing E or 0 if E does not belong to any contour.", py::arg("E"));
	cls_ChFi3d_Builder.def("Contains", (Standard_Integer (ChFi3d_Builder::*)(const TopoDS_Edge &, Standard_Integer &) const ) &ChFi3d_Builder::Contains, "gives the number of the contour containing E or 0 if E does not belong to any contour. Sets in IndexInSpine the index of E in the contour if it's found", py::arg("E"), py::arg("IndexInSpine"));
	cls_ChFi3d_Builder.def("NbElements", (Standard_Integer (ChFi3d_Builder::*)() const ) &ChFi3d_Builder::NbElements, "gives the number of disjoint contours on which the fillets are calculated");
	cls_ChFi3d_Builder.def("Value", (opencascade::handle<ChFiDS_Spine> (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::Value, "gives the n'th set of edges (contour) if I >NbElements()", py::arg("I"));
	cls_ChFi3d_Builder.def("Length", (Standard_Real (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::Length, "returns the length of the contour of index IC.", py::arg("IC"));
	cls_ChFi3d_Builder.def("FirstVertex", (TopoDS_Vertex (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::FirstVertex, "returns the First vertex V of the contour of index IC.", py::arg("IC"));
	cls_ChFi3d_Builder.def("LastVertex", (TopoDS_Vertex (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::LastVertex, "returns the Last vertex V of the contour of index IC.", py::arg("IC"));
	cls_ChFi3d_Builder.def("Abscissa", (Standard_Real (ChFi3d_Builder::*)(const Standard_Integer, const TopoDS_Vertex &) const ) &ChFi3d_Builder::Abscissa, "returns the abscissa of the vertex V on the contour of index IC.", py::arg("IC"), py::arg("V"));
	// FIXME cls_ChFi3d_Builder.def("RelativeAbscissa", (Standard_Real (ChFi3d_Builder::*)(const Standard_Integer, const TopoDS_Vertex &) const ) &ChFi3d_Builder::RelativeAbscissa, "returns the relative abscissa([0.,1.]) of the vertex V on the contour of index IC.", py::arg("IC"), py::arg("V"));
	cls_ChFi3d_Builder.def("ClosedAndTangent", (Standard_Boolean (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::ClosedAndTangent, "returns true if the contour of index IC is closed an tangent.", py::arg("IC"));
	cls_ChFi3d_Builder.def("Closed", (Standard_Boolean (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::Closed, "returns true if the contour of index IC is closed", py::arg("IC"));
	cls_ChFi3d_Builder.def("Compute", (void (ChFi3d_Builder::*)()) &ChFi3d_Builder::Compute, "general calculation of geometry on all edges, topologic reconstruction.");
	cls_ChFi3d_Builder.def("IsDone", (Standard_Boolean (ChFi3d_Builder::*)() const ) &ChFi3d_Builder::IsDone, "returns True if the computation is success");
	cls_ChFi3d_Builder.def("Shape", (TopoDS_Shape (ChFi3d_Builder::*)() const ) &ChFi3d_Builder::Shape, "if (Isdone()) makes the result. if (!Isdone())");
	cls_ChFi3d_Builder.def("Generated", (const TopTools_ListOfShape & (ChFi3d_Builder::*)(const TopoDS_Shape &)) &ChFi3d_Builder::Generated, "Advanced function for the history", py::arg("EouV"));
	cls_ChFi3d_Builder.def("NbFaultyContours", (Standard_Integer (ChFi3d_Builder::*)() const ) &ChFi3d_Builder::NbFaultyContours, "Returns the number of contours on which the calculation has failed.");
	cls_ChFi3d_Builder.def("FaultyContour", (Standard_Integer (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::FaultyContour, "Returns the number of I'th contour on which the calculation has failed.", py::arg("I"));
	cls_ChFi3d_Builder.def("NbComputedSurfaces", (Standard_Integer (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::NbComputedSurfaces, "Returns the number of surfaces calculated on the contour IC.", py::arg("IC"));
	cls_ChFi3d_Builder.def("ComputedSurface", (opencascade::handle<Geom_Surface> (ChFi3d_Builder::*)(const Standard_Integer, const Standard_Integer) const ) &ChFi3d_Builder::ComputedSurface, "Returns the IS'th surface calculated on the contour IC.", py::arg("IC"), py::arg("IS"));
	cls_ChFi3d_Builder.def("NbFaultyVertices", (Standard_Integer (ChFi3d_Builder::*)() const ) &ChFi3d_Builder::NbFaultyVertices, "Returns the number of vertices on which the calculation has failed.");
	cls_ChFi3d_Builder.def("FaultyVertex", (TopoDS_Vertex (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::FaultyVertex, "Returns the IV'th vertex on which the calculation has failed.", py::arg("IV"));
	cls_ChFi3d_Builder.def("HasResult", (Standard_Boolean (ChFi3d_Builder::*)() const ) &ChFi3d_Builder::HasResult, "returns True if a partial result has been calculated");
	cls_ChFi3d_Builder.def("BadShape", (TopoDS_Shape (ChFi3d_Builder::*)() const ) &ChFi3d_Builder::BadShape, "if (HasResult()) returns partial result if (!HasResult())");
	cls_ChFi3d_Builder.def("StripeStatus", (ChFiDS_ErrorStatus (ChFi3d_Builder::*)(const Standard_Integer) const ) &ChFi3d_Builder::StripeStatus, "for the stripe IC ,indication on the cause of failure WalkingFailure,TwistedSurface,Error, Ok", py::arg("IC"));
	cls_ChFi3d_Builder.def("Reset", (void (ChFi3d_Builder::*)()) &ChFi3d_Builder::Reset, "Reset all results of compute and returns the algorythm in the state of the last acquisition to enable modification of contours or areas.");
	cls_ChFi3d_Builder.def("Builder", (opencascade::handle<TopOpeBRepBuild_HBuilder> (ChFi3d_Builder::*)() const ) &ChFi3d_Builder::Builder, "Returns the Builder of topologic operations.");
	cls_ChFi3d_Builder.def("SplitKPart", (Standard_Boolean (ChFi3d_Builder::*)(const opencascade::handle<ChFiDS_SurfData> &, ChFiDS_SequenceOfSurfData &, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, Standard_Boolean &, Standard_Boolean &)) &ChFi3d_Builder::SplitKPart, "Method, implemented in the inheritants, calculates the elements of construction of the surface (fillet or chamfer).", py::arg("Data"), py::arg("SetData"), py::arg("Spine"), py::arg("Iedge"), py::arg("S1"), py::arg("I1"), py::arg("S2"), py::arg("I2"), py::arg("Intf"), py::arg("Intl"));
	cls_ChFi3d_Builder.def("PerformTwoCornerbyInter", (Standard_Boolean (ChFi3d_Builder::*)(const Standard_Integer)) &ChFi3d_Builder::PerformTwoCornerbyInter, "None", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_ChBuilder.hxx
	py::class_<ChFi3d_ChBuilder, std::unique_ptr<ChFi3d_ChBuilder, Deleter<ChFi3d_ChBuilder>>, ChFi3d_Builder> cls_ChFi3d_ChBuilder(mod, "ChFi3d_ChBuilder", "construction tool for 3D chamfers on edges (on a solid).");
	cls_ChFi3d_ChBuilder.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_ChFi3d_ChBuilder.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("S"), py::arg("Ta"));
	cls_ChFi3d_ChBuilder.def("Add", (void (ChFi3d_ChBuilder::*)(const TopoDS_Edge &)) &ChFi3d_ChBuilder::Add, "initializes a contour with the edge <E> as first (the next are found by propagation ). The two distances (parameters of the chamfer) must be set after. if the edge <E> has more than 2 adjacent faces", py::arg("E"));
	cls_ChFi3d_ChBuilder.def("Add", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &ChFi3d_ChBuilder::Add, "initializes a new contour with the edge <E> as first (the next are found by propagation ), and the distance <Dis> if the edge <E> has more than 2 adjacent faces", py::arg("Dis"), py::arg("E"), py::arg("F"));
	cls_ChFi3d_ChBuilder.def("SetDist", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Integer, const TopoDS_Face &)) &ChFi3d_ChBuilder::SetDist, "set the distance <Dis> of the fillet contour of index <IC> in the DS with <Dis> on <F>. if the face <F> is not one of common faces of an edge of the contour <IC>", py::arg("Dis"), py::arg("IC"), py::arg("F"));
	cls_ChFi3d_ChBuilder.def("GetDist", (void (ChFi3d_ChBuilder::*)(const Standard_Integer, Standard_Real &) const ) &ChFi3d_ChBuilder::GetDist, "gives the distances <Dis> of the fillet contour of index <IC> in the DS", py::arg("IC"), py::arg("Dis"));
	cls_ChFi3d_ChBuilder.def("Add", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &ChFi3d_ChBuilder::Add, "initializes a new contour with the edge <E> as first (the next are found by propagation ), and the distance <Dis1> and <Dis2> if the edge <E> has more than 2 adjacent faces", py::arg("Dis1"), py::arg("Dis2"), py::arg("E"), py::arg("F"));
	cls_ChFi3d_ChBuilder.def("SetDists", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const TopoDS_Face &)) &ChFi3d_ChBuilder::SetDists, "set the distances <Dis1> and <Dis2> of the fillet contour of index <IC> in the DS with <Dis1> on <F>. if the face <F> is not one of common faces of an edge of the contour <IC>", py::arg("Dis1"), py::arg("Dis2"), py::arg("IC"), py::arg("F"));
	cls_ChFi3d_ChBuilder.def("Dists", (void (ChFi3d_ChBuilder::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &ChFi3d_ChBuilder::Dists, "gives the distances <Dis1> and <Dis2> of the fillet contour of index <IC> in the DS", py::arg("IC"), py::arg("Dis1"), py::arg("Dis2"));
	cls_ChFi3d_ChBuilder.def("AddDA", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &ChFi3d_ChBuilder::AddDA, "initializes a new contour with the edge <E> as first (the next are found by propagation ), and the distance <Dis1> and <Angle> if the edge <E> has more than 2 adjacent faces", py::arg("Dis"), py::arg("Angle"), py::arg("E"), py::arg("F"));
	cls_ChFi3d_ChBuilder.def("SetDistAngle", (void (ChFi3d_ChBuilder::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const TopoDS_Face &)) &ChFi3d_ChBuilder::SetDistAngle, "set the distance <Dis> and <Angle> of the fillet contour of index <IC> in the DS with <Dis> on <F>. if the face <F> is not one of common faces of an edge of the contour <IC>", py::arg("Dis"), py::arg("Angle"), py::arg("IC"), py::arg("F"));
	cls_ChFi3d_ChBuilder.def("GetDistAngle", (void (ChFi3d_ChBuilder::*)(const Standard_Integer, Standard_Real &, Standard_Real &, Standard_Boolean &) const ) &ChFi3d_ChBuilder::GetDistAngle, "gives the distances <Dis> and <Angle> of the fillet contour of index <IC> in the DS", py::arg("IC"), py::arg("Dis"), py::arg("Angle"), py::arg("DisOnFace1"));
	cls_ChFi3d_ChBuilder.def("IsChamfer", (ChFiDS_ChamfMethod (ChFi3d_ChBuilder::*)(const Standard_Integer) const ) &ChFi3d_ChBuilder::IsChamfer, "renvoi la methode des chanfreins utilisee", py::arg("IC"));
	cls_ChFi3d_ChBuilder.def("ResetContour", (void (ChFi3d_ChBuilder::*)(const Standard_Integer)) &ChFi3d_ChBuilder::ResetContour, "Reset tous rayons du contour IC.", py::arg("IC"));
	cls_ChFi3d_ChBuilder.def("Simulate", (void (ChFi3d_ChBuilder::*)(const Standard_Integer)) &ChFi3d_ChBuilder::Simulate, "None", py::arg("IC"));
	cls_ChFi3d_ChBuilder.def("NbSurf", (Standard_Integer (ChFi3d_ChBuilder::*)(const Standard_Integer) const ) &ChFi3d_ChBuilder::NbSurf, "None", py::arg("IC"));
	cls_ChFi3d_ChBuilder.def("Sect", (opencascade::handle<ChFiDS_SecHArray1> (ChFi3d_ChBuilder::*)(const Standard_Integer, const Standard_Integer) const ) &ChFi3d_ChBuilder::Sect, "None", py::arg("IC"), py::arg("IS"));
	cls_ChFi3d_ChBuilder.def("SimulSurf", (void (ChFi3d_ChBuilder::*)(opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<ChFiDS_HElSpine> &, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, Standard_Boolean &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const TopAbs_Orientation, const Standard_Real, const Standard_Real, Standard_Real &, Standard_Real &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const math_Vector &)) &ChFi3d_ChBuilder::SimulSurf, "None", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("PC1"), py::arg("Sref1"), py::arg("PCref1"), py::arg("Decroch1"), py::arg("S2"), py::arg("I2"), py::arg("Or2"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP"), py::arg("RecS"), py::arg("RecRst"), py::arg("Soldep"));
	cls_ChFi3d_ChBuilder.def("SimulSurf", (void (ChFi3d_ChBuilder::*)(opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<ChFiDS_HElSpine> &, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const TopAbs_Orientation, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, Standard_Boolean &, const Standard_Real, const Standard_Real, Standard_Real &, Standard_Real &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const math_Vector &)) &ChFi3d_ChBuilder::SimulSurf, "None", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("Or1"), py::arg("S2"), py::arg("I2"), py::arg("PC2"), py::arg("Sref2"), py::arg("PCref2"), py::arg("Decroch2"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP"), py::arg("RecS"), py::arg("RecRst"), py::arg("Soldep"));
	cls_ChFi3d_ChBuilder.def("SimulSurf", (void (ChFi3d_ChBuilder::*)(opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<ChFiDS_HElSpine> &, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, Standard_Boolean &, const TopAbs_Orientation, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, Standard_Boolean &, const TopAbs_Orientation, const Standard_Real, const Standard_Real, Standard_Real &, Standard_Real &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const math_Vector &)) &ChFi3d_ChBuilder::SimulSurf, "None", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("PC1"), py::arg("Sref1"), py::arg("PCref1"), py::arg("Decroch1"), py::arg("Or1"), py::arg("S2"), py::arg("I2"), py::arg("PC2"), py::arg("Sref2"), py::arg("PCref2"), py::arg("Decroch2"), py::arg("Or2"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP1"), py::arg("RecRst1"), py::arg("RecP2"), py::arg("RecRst2"), py::arg("Soldep"));
	cls_ChFi3d_ChBuilder.def("PerformSurf", (Standard_Boolean (ChFi3d_ChBuilder::*)(ChFiDS_SequenceOfSurfData &, const opencascade::handle<ChFiDS_HElSpine> &, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real &, Standard_Real &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const math_Vector &, Standard_Integer &, Standard_Integer &)) &ChFi3d_ChBuilder::PerformSurf, "Methode, implemented in inheritants, calculates the elements of construction of the surface (fillet or chamfer).", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("S2"), py::arg("I2"), py::arg("MaxStep"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecOnS1"), py::arg("RecOnS2"), py::arg("Soldep"), py::arg("Intf"), py::arg("Intl"));
	cls_ChFi3d_ChBuilder.def("PerformSurf", (void (ChFi3d_ChBuilder::*)(ChFiDS_SequenceOfSurfData &, const opencascade::handle<ChFiDS_HElSpine> &, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, Standard_Boolean &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real &, Standard_Real &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const math_Vector &)) &ChFi3d_ChBuilder::PerformSurf, "Method, implemented in the inheritants, calculates the elements of construction of the surface (fillet or chamfer) contact edge/face.", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("PC1"), py::arg("Sref1"), py::arg("PCref1"), py::arg("Decroch1"), py::arg("S2"), py::arg("I2"), py::arg("Or2"), py::arg("MaxStep"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP"), py::arg("RecS"), py::arg("RecRst"), py::arg("Soldep"));
	cls_ChFi3d_ChBuilder.def("PerformSurf", (void (ChFi3d_ChBuilder::*)(ChFiDS_SequenceOfSurfData &, const opencascade::handle<ChFiDS_HElSpine> &, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const TopAbs_Orientation, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, Standard_Boolean &, const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real &, Standard_Real &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const math_Vector &)) &ChFi3d_ChBuilder::PerformSurf, "Method, implemented in inheritants, calculates the elements of construction of the surface (fillet or chamfer) contact edge/face.", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("Or1"), py::arg("S2"), py::arg("I2"), py::arg("PC2"), py::arg("Sref2"), py::arg("PCref2"), py::arg("Decroch2"), py::arg("MaxStep"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP"), py::arg("RecS"), py::arg("RecRst"), py::arg("Soldep"));
	cls_ChFi3d_ChBuilder.def("PerformSurf", (void (ChFi3d_ChBuilder::*)(ChFiDS_SequenceOfSurfData &, const opencascade::handle<ChFiDS_HElSpine> &, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, Standard_Boolean &, const TopAbs_Orientation, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<BRepAdaptor_HCurve2d> &, Standard_Boolean &, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real &, Standard_Real &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const math_Vector &)) &ChFi3d_ChBuilder::PerformSurf, "Method, implemented in inheritants, calculates the elements of construction of the surface (fillet or chamfer) contact edge/edge.", py::arg("Data"), py::arg("Guide"), py::arg("Spine"), py::arg("Choix"), py::arg("S1"), py::arg("I1"), py::arg("PC1"), py::arg("Sref1"), py::arg("PCref1"), py::arg("Decroch1"), py::arg("Or1"), py::arg("S2"), py::arg("I2"), py::arg("PC2"), py::arg("Sref2"), py::arg("PCref2"), py::arg("Decroch2"), py::arg("Or2"), py::arg("MaxStep"), py::arg("Fleche"), py::arg("TolGuide"), py::arg("First"), py::arg("Last"), py::arg("Inside"), py::arg("Appro"), py::arg("Forward"), py::arg("RecP1"), py::arg("RecRst1"), py::arg("RecP2"), py::arg("RecRst2"), py::arg("Soldep"));
	cls_ChFi3d_ChBuilder.def("FindChoiceDistAngle", (Standard_Integer (ChFi3d_ChBuilder::*)(const Standard_Integer, const Standard_Boolean) const ) &ChFi3d_ChBuilder::FindChoiceDistAngle, "None", py::arg("Choice"), py::arg("DisOnF1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_FilBuilder.hxx
	py::class_<ChFi3d_FilBuilder, std::unique_ptr<ChFi3d_FilBuilder, Deleter<ChFi3d_FilBuilder>>, ChFi3d_Builder> cls_ChFi3d_FilBuilder(mod, "ChFi3d_FilBuilder", "Tool of construction of fillets 3d on edges (on a solid).");
	cls_ChFi3d_FilBuilder.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_ChFi3d_FilBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape>(), py::arg("S"), py::arg("FShape"));
	cls_ChFi3d_FilBuilder.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape, const Standard_Real>(), py::arg("S"), py::arg("FShape"), py::arg("Ta"));
	cls_ChFi3d_FilBuilder.def("SetFilletShape", (void (ChFi3d_FilBuilder::*)(const ChFi3d_FilletShape)) &ChFi3d_FilBuilder::SetFilletShape, "Sets the type of fillet surface.", py::arg("FShape"));
	cls_ChFi3d_FilBuilder.def("GetFilletShape", (ChFi3d_FilletShape (ChFi3d_FilBuilder::*)() const ) &ChFi3d_FilBuilder::GetFilletShape, "Returns the type of fillet surface.");
	cls_ChFi3d_FilBuilder.def("Add", (void (ChFi3d_FilBuilder::*)(const TopoDS_Edge &)) &ChFi3d_FilBuilder::Add, "initialisation of a contour with the first edge (the following are found by propagation). Attention, you need to start with SetRadius.", py::arg("E"));
	cls_ChFi3d_FilBuilder.def("Add", (void (ChFi3d_FilBuilder::*)(const Standard_Real, const TopoDS_Edge &)) &ChFi3d_FilBuilder::Add, "initialisation of the constant vector the corresponding 1st edge.", py::arg("Radius"), py::arg("E"));
	cls_ChFi3d_FilBuilder.def("SetRadius", (void (ChFi3d_FilBuilder::*)(const opencascade::handle<Law_Function> &, const Standard_Integer, const Standard_Integer)) &ChFi3d_FilBuilder::SetRadius, "Set the radius of the contour of index IC.", py::arg("C"), py::arg("IC"), py::arg("IinC"));
	cls_ChFi3d_FilBuilder.def("IsConstant", (Standard_Boolean (ChFi3d_FilBuilder::*)(const Standard_Integer)) &ChFi3d_FilBuilder::IsConstant, "Returns true the contour is flaged as edge constant.", py::arg("IC"));
	cls_ChFi3d_FilBuilder.def("Radius", (Standard_Real (ChFi3d_FilBuilder::*)(const Standard_Integer)) &ChFi3d_FilBuilder::Radius, "Returns the vector if the contour is flagged as edge constant.", py::arg("IC"));
	cls_ChFi3d_FilBuilder.def("ResetContour", (void (ChFi3d_FilBuilder::*)(const Standard_Integer)) &ChFi3d_FilBuilder::ResetContour, "Reset all vectors of contour IC.", py::arg("IC"));
	cls_ChFi3d_FilBuilder.def("SetRadius", (void (ChFi3d_FilBuilder::*)(const Standard_Real, const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::SetRadius, "Set a constant on edge E of the contour of index IC. Since then E is flagged as constant.", py::arg("Radius"), py::arg("IC"), py::arg("E"));
	cls_ChFi3d_FilBuilder.def("UnSet", (void (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::UnSet, "Extracts the flag constant and the vector of edge E.", py::arg("IC"), py::arg("E"));
	cls_ChFi3d_FilBuilder.def("SetRadius", (void (ChFi3d_FilBuilder::*)(const Standard_Real, const Standard_Integer, const TopoDS_Vertex &)) &ChFi3d_FilBuilder::SetRadius, "Set a vector on vertex V of the contour of index IC.", py::arg("Radius"), py::arg("IC"), py::arg("V"));
	cls_ChFi3d_FilBuilder.def("UnSet", (void (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Vertex &)) &ChFi3d_FilBuilder::UnSet, "Extracts the vector of the vertex V.", py::arg("IC"), py::arg("V"));
	cls_ChFi3d_FilBuilder.def("SetRadius", (void (ChFi3d_FilBuilder::*)(const gp_XY &, const Standard_Integer, const Standard_Integer)) &ChFi3d_FilBuilder::SetRadius, "Set a vertex on the point of parametre U in the edge IinC of the contour of index IC", py::arg("UandR"), py::arg("IC"), py::arg("IinC"));
	cls_ChFi3d_FilBuilder.def("IsConstant", (Standard_Boolean (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::IsConstant, "Returns true E is flagged as edge constant.", py::arg("IC"), py::arg("E"));
	cls_ChFi3d_FilBuilder.def("Radius", (Standard_Real (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::Radius, "Returns the vector if E is flagged as edge constant.", py::arg("IC"), py::arg("E"));
	cls_ChFi3d_FilBuilder.def("GetBounds", (Standard_Boolean (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &, Standard_Real &, Standard_Real &)) &ChFi3d_FilBuilder::GetBounds, "Returns in First and Last les extremities of the part of variable vector framing E, returns False if E is flagged as edge constant.", py::arg("IC"), py::arg("E"), py::arg("First"), py::arg("Last"));
	cls_ChFi3d_FilBuilder.def("GetLaw", (opencascade::handle<Law_Function> (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &)) &ChFi3d_FilBuilder::GetLaw, "Returns the rule of elementary evolution of the part to variable vector framing E, returns a rule zero if E is flagged as edge constant.", py::arg("IC"), py::arg("E"));
	cls_ChFi3d_FilBuilder.def("SetLaw", (void (ChFi3d_FilBuilder::*)(const Standard_Integer, const TopoDS_Edge &, const opencascade::handle<Law_Function> &)) &ChFi3d_FilBuilder::SetLaw, "Sets the rule of elementary evolution of the part to variable vector framing E.", py::arg("IC"), py::arg("E"), py::arg("L"));
	cls_ChFi3d_FilBuilder.def("Simulate", (void (ChFi3d_FilBuilder::*)(const Standard_Integer)) &ChFi3d_FilBuilder::Simulate, "None", py::arg("IC"));
	cls_ChFi3d_FilBuilder.def("NbSurf", (Standard_Integer (ChFi3d_FilBuilder::*)(const Standard_Integer) const ) &ChFi3d_FilBuilder::NbSurf, "None", py::arg("IC"));
	cls_ChFi3d_FilBuilder.def("Sect", (opencascade::handle<ChFiDS_SecHArray1> (ChFi3d_FilBuilder::*)(const Standard_Integer, const Standard_Integer) const ) &ChFi3d_FilBuilder::Sect, "None", py::arg("IC"), py::arg("IS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d_SearchSing.hxx
	py::class_<ChFi3d_SearchSing, std::unique_ptr<ChFi3d_SearchSing, Deleter<ChFi3d_SearchSing>>, math_FunctionWithDerivative> cls_ChFi3d_SearchSing(mod, "ChFi3d_SearchSing", "Searches singularities on fillet. F(t) = (C1(t) - C2(t)).(C1'(t) - C2'(t));");
	cls_ChFi3d_SearchSing.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("C1"), py::arg("C2"));
	cls_ChFi3d_SearchSing.def("Value", (Standard_Boolean (ChFi3d_SearchSing::*)(const Standard_Real, Standard_Real &)) &ChFi3d_SearchSing::Value, "computes the value of the function <F> for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_ChFi3d_SearchSing.def("Derivative", (Standard_Boolean (ChFi3d_SearchSing::*)(const Standard_Real, Standard_Real &)) &ChFi3d_SearchSing::Derivative, "computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
	cls_ChFi3d_SearchSing.def("Values", (Standard_Boolean (ChFi3d_SearchSing::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &ChFi3d_SearchSing::Values, "computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi3d.hxx
	py::class_<ChFi3d, std::unique_ptr<ChFi3d, Deleter<ChFi3d>>> cls_ChFi3d(mod, "ChFi3d", "creation of spatial fillets on a solid.");
	cls_ChFi3d.def(py::init<>());
	cls_ChFi3d.def_static("ConcaveSide_", (Standard_Integer (*)(const BRepAdaptor_Surface &, const BRepAdaptor_Surface &, const TopoDS_Edge &, TopAbs_Orientation &, TopAbs_Orientation &)) &ChFi3d::ConcaveSide, "Returns Reversed in Or1 and(or) Or2 if the concave edge defined by the interior of faces F1 and F2, in the neighbourhood of their boundary E is of the edge opposite to the normal of their surface support. The orientation of faces is not taken into consideration in the calculation. The function returns 0 if the calculation fails (tangence), if not, it returns the number of choice of the fillet or chamfer corresponding to the orientations calculated and to the tangent to the guide line read in E.", py::arg("S1"), py::arg("S2"), py::arg("E"), py::arg("Or1"), py::arg("Or2"));
	cls_ChFi3d.def_static("NextSide_", (Standard_Integer (*)(TopAbs_Orientation &, TopAbs_Orientation &, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Integer)) &ChFi3d::NextSide, "Same as ConcaveSide, but the orientations are logically deduced from the result of the call of ConcaveSide on the first pair of faces of the fillet or chamnfer.", py::arg("Or1"), py::arg("Or2"), py::arg("OrSave1"), py::arg("OrSave2"), py::arg("ChoixSauv"));
	cls_ChFi3d.def_static("NextSide_", (void (*)(TopAbs_Orientation &, const TopAbs_Orientation, const TopAbs_Orientation)) &ChFi3d::NextSide, "Same as the other NextSide, but the calculation is done on an edge only.", py::arg("Or"), py::arg("OrSave"), py::arg("OrFace"));
	cls_ChFi3d.def_static("SameSide_", (Standard_Boolean (*)(const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation)) &ChFi3d::SameSide, "Enables to determine while processing an angle, if two fillets or chamfers constituting a face have identic or opposed concave edges.", py::arg("Or"), py::arg("OrSave1"), py::arg("OrSave2"), py::arg("OrFace1"), py::arg("OrFace2"));


}
