#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
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
#include <Geom_OffsetCurve.hxx>
#include <Standard_Type.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <gp_Ax1.hxx>
#include <gp_Dir.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <Adaptor3d_CurveOnSurfacePtr.hxx>
#include <Adaptor3d_CurvePtr.hxx>
#include <Adaptor3d_HCurveOnSurface.hxx>
#include <GeomAbs_IsoType.hxx>
#include <Adaptor3d_IsoCurve.hxx>
#include <Adaptor3d_HIsoCurve.hxx>
#include <Adaptor3d_HSurfaceTool.hxx>
#include <gp_Pnt2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Adaptor3d_InterFunc.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <TopAbs_State.hxx>
#include <Adaptor3d_TopolTool.hxx>

PYBIND11_MODULE(Adaptor3d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.math");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_HCurve.hxx
	py::class_<Adaptor3d_HCurve, opencascade::handle<Adaptor3d_HCurve>, Standard_Transient> cls_Adaptor3d_HCurve(mod, "Adaptor3d_HCurve", "Root class for 3D curves manipulated by handles, on which geometric algorithms work. An adapted curve is an interface between the services provided by a curve and those required of the curve by algorithms which use it. Two derived concrete classes are provided: - GeomAdaptor_HCurve for a curve from the Geom package - Adaptor3d_HCurveOnSurface for a curve lying on a surface from the Geom package.");
	cls_Adaptor3d_HCurve.def("Curve", (const Adaptor3d_Curve & (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Curve, "Returns a pointer to the Curve inside the HCurve.");
	cls_Adaptor3d_HCurve.def("GetCurve", (Adaptor3d_Curve & (Adaptor3d_HCurve::*)()) &Adaptor3d_HCurve::GetCurve, "Returns a pointer to the Curve inside the HCurve.");
	cls_Adaptor3d_HCurve.def("FirstParameter", (Standard_Real (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::FirstParameter, "None");
	cls_Adaptor3d_HCurve.def("LastParameter", (Standard_Real (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::LastParameter, "None");
	cls_Adaptor3d_HCurve.def("Continuity", (GeomAbs_Shape (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Continuity, "None");
	cls_Adaptor3d_HCurve.def("NbIntervals", (Standard_Integer (Adaptor3d_HCurve::*)(const GeomAbs_Shape) const ) &Adaptor3d_HCurve::NbIntervals, "None", py::arg("S"));
	cls_Adaptor3d_HCurve.def("Intervals", (void (Adaptor3d_HCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor3d_HCurve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Adaptor3d_HCurve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_HCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor3d_HCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion.", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_HCurve.def("IsClosed", (Standard_Boolean (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::IsClosed, "None");
	cls_Adaptor3d_HCurve.def("IsPeriodic", (Standard_Boolean (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::IsPeriodic, "None");
	cls_Adaptor3d_HCurve.def("Period", (Standard_Real (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Period, "None");
	cls_Adaptor3d_HCurve.def("Value", (gp_Pnt (Adaptor3d_HCurve::*)(const Standard_Real) const ) &Adaptor3d_HCurve::Value, "None", py::arg("U"));
	cls_Adaptor3d_HCurve.def("D0", (void (Adaptor3d_HCurve::*)(const Standard_Real, gp_Pnt &) const ) &Adaptor3d_HCurve::D0, "None", py::arg("U"), py::arg("P"));
	cls_Adaptor3d_HCurve.def("D1", (void (Adaptor3d_HCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &Adaptor3d_HCurve::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Adaptor3d_HCurve.def("D2", (void (Adaptor3d_HCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_HCurve::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Adaptor3d_HCurve.def("D3", (void (Adaptor3d_HCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_HCurve::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Adaptor3d_HCurve.def("DN", (gp_Vec (Adaptor3d_HCurve::*)(const Standard_Real, const Standard_Integer) const ) &Adaptor3d_HCurve::DN, "None", py::arg("U"), py::arg("N"));
	cls_Adaptor3d_HCurve.def("Resolution", (Standard_Real (Adaptor3d_HCurve::*)(const Standard_Real) const ) &Adaptor3d_HCurve::Resolution, "None", py::arg("R3d"));
	cls_Adaptor3d_HCurve.def("GetType", (GeomAbs_CurveType (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::GetType, "None");
	cls_Adaptor3d_HCurve.def("Line", (gp_Lin (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Line, "None");
	cls_Adaptor3d_HCurve.def("Circle", (gp_Circ (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Circle, "None");
	cls_Adaptor3d_HCurve.def("Ellipse", (gp_Elips (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Ellipse, "None");
	cls_Adaptor3d_HCurve.def("Hyperbola", (gp_Hypr (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Hyperbola, "None");
	cls_Adaptor3d_HCurve.def("Parabola", (gp_Parab (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Parabola, "None");
	cls_Adaptor3d_HCurve.def("Degree", (Standard_Integer (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Degree, "None");
	cls_Adaptor3d_HCurve.def("IsRational", (Standard_Boolean (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::IsRational, "None");
	cls_Adaptor3d_HCurve.def("NbPoles", (Standard_Integer (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::NbPoles, "None");
	cls_Adaptor3d_HCurve.def("NbKnots", (Standard_Integer (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::NbKnots, "None");
	cls_Adaptor3d_HCurve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::Bezier, "None");
	cls_Adaptor3d_HCurve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::BSpline, "None");
	cls_Adaptor3d_HCurve.def("OffsetCurve", (opencascade::handle<Geom_OffsetCurve> (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::OffsetCurve, "None");
	cls_Adaptor3d_HCurve.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_HCurve::get_type_name, "None");
	cls_Adaptor3d_HCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_HCurve::get_type_descriptor, "None");
	cls_Adaptor3d_HCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_HCurve::*)() const ) &Adaptor3d_HCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_Curve.hxx
	py::class_<Adaptor3d_Curve, std::unique_ptr<Adaptor3d_Curve, Deleter<Adaptor3d_Curve>>> cls_Adaptor3d_Curve(mod, "Adaptor3d_Curve", "Root class for 3D curves on which geometric algorithms work. An adapted curve is an interface between the services provided by a curve and those required of the curve by algorithms which use it. Two derived concrete classes are provided: - GeomAdaptor_Curve for a curve from the Geom package - Adaptor3d_CurveOnSurface for a curve lying on a surface from the Geom package.");
	cls_Adaptor3d_Curve.def(py::init<>());
	cls_Adaptor3d_Curve.def("FirstParameter", (Standard_Real (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::FirstParameter, "None");
	cls_Adaptor3d_Curve.def("LastParameter", (Standard_Real (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::LastParameter, "None");
	cls_Adaptor3d_Curve.def("Continuity", (GeomAbs_Shape (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::Continuity, "None");
	cls_Adaptor3d_Curve.def("NbIntervals", (Standard_Integer (Adaptor3d_Curve::*)(const GeomAbs_Shape) const ) &Adaptor3d_Curve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_Adaptor3d_Curve.def("Intervals", (void (Adaptor3d_Curve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor3d_Curve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Adaptor3d_Curve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_Curve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor3d_Curve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_Curve.def("IsClosed", (Standard_Boolean (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::IsClosed, "None");
	cls_Adaptor3d_Curve.def("IsPeriodic", (Standard_Boolean (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::IsPeriodic, "None");
	cls_Adaptor3d_Curve.def("Period", (Standard_Real (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::Period, "None");
	cls_Adaptor3d_Curve.def("Value", (gp_Pnt (Adaptor3d_Curve::*)(const Standard_Real) const ) &Adaptor3d_Curve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_Adaptor3d_Curve.def("D0", (void (Adaptor3d_Curve::*)(const Standard_Real, gp_Pnt &) const ) &Adaptor3d_Curve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_Adaptor3d_Curve.def("D1", (void (Adaptor3d_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &Adaptor3d_Curve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Adaptor3d_Curve.def("D2", (void (Adaptor3d_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_Curve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Adaptor3d_Curve.def("D3", (void (Adaptor3d_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Adaptor3d_Curve.def("DN", (gp_Vec (Adaptor3d_Curve::*)(const Standard_Real, const Standard_Integer) const ) &Adaptor3d_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_Adaptor3d_Curve.def("Resolution", (Standard_Real (Adaptor3d_Curve::*)(const Standard_Real) const ) &Adaptor3d_Curve::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_Adaptor3d_Curve.def("GetType", (GeomAbs_CurveType (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
	cls_Adaptor3d_Curve.def("Line", (gp_Lin (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::Line, "None");
	cls_Adaptor3d_Curve.def("Circle", (gp_Circ (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::Circle, "None");
	cls_Adaptor3d_Curve.def("Ellipse", (gp_Elips (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::Ellipse, "None");
	cls_Adaptor3d_Curve.def("Hyperbola", (gp_Hypr (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::Hyperbola, "None");
	cls_Adaptor3d_Curve.def("Parabola", (gp_Parab (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::Parabola, "None");
	cls_Adaptor3d_Curve.def("Degree", (Standard_Integer (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::Degree, "None");
	cls_Adaptor3d_Curve.def("IsRational", (Standard_Boolean (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::IsRational, "None");
	cls_Adaptor3d_Curve.def("NbPoles", (Standard_Integer (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::NbPoles, "None");
	cls_Adaptor3d_Curve.def("NbKnots", (Standard_Integer (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::NbKnots, "None");
	cls_Adaptor3d_Curve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::Bezier, "None");
	cls_Adaptor3d_Curve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::BSpline, "None");
	cls_Adaptor3d_Curve.def("OffsetCurve", (opencascade::handle<Geom_OffsetCurve> (Adaptor3d_Curve::*)() const ) &Adaptor3d_Curve::OffsetCurve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_HSurface.hxx
	py::class_<Adaptor3d_HSurface, opencascade::handle<Adaptor3d_HSurface>, Standard_Transient> cls_Adaptor3d_HSurface(mod, "Adaptor3d_HSurface", "Root class for surfaces manipulated by handles, on which geometric algorithms work. An adapted surface is an interface between the services provided by a surface and those required of the surface by algorithms which use it. A derived concrete class is provided: GeomAdaptor_HSurface for a surface from the Geom package.");
	cls_Adaptor3d_HSurface.def("Surface", (const Adaptor3d_Surface & (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::Surface, "Returns a reference to the Surface inside the HSurface.");
	cls_Adaptor3d_HSurface.def("FirstUParameter", (Standard_Real (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::FirstUParameter, "None");
	cls_Adaptor3d_HSurface.def("LastUParameter", (Standard_Real (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::LastUParameter, "None");
	cls_Adaptor3d_HSurface.def("FirstVParameter", (Standard_Real (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::FirstVParameter, "None");
	cls_Adaptor3d_HSurface.def("LastVParameter", (Standard_Real (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::LastVParameter, "None");
	cls_Adaptor3d_HSurface.def("UContinuity", (GeomAbs_Shape (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::UContinuity, "None");
	cls_Adaptor3d_HSurface.def("VContinuity", (GeomAbs_Shape (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::VContinuity, "None");
	cls_Adaptor3d_HSurface.def("NbUIntervals", (Standard_Integer (Adaptor3d_HSurface::*)(const GeomAbs_Shape) const ) &Adaptor3d_HSurface::NbUIntervals, "None", py::arg("S"));
	cls_Adaptor3d_HSurface.def("NbVIntervals", (Standard_Integer (Adaptor3d_HSurface::*)(const GeomAbs_Shape) const ) &Adaptor3d_HSurface::NbVIntervals, "None", py::arg("S"));
	cls_Adaptor3d_HSurface.def("UIntervals", (void (Adaptor3d_HSurface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor3d_HSurface::UIntervals, "None", py::arg("T"), py::arg("S"));
	cls_Adaptor3d_HSurface.def("VIntervals", (void (Adaptor3d_HSurface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor3d_HSurface::VIntervals, "None", py::arg("T"), py::arg("S"));
	cls_Adaptor3d_HSurface.def("UTrim", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor3d_HSurface::UTrim, "None", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_HSurface.def("VTrim", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor3d_HSurface::VTrim, "None", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_HSurface.def("IsUClosed", (Standard_Boolean (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::IsUClosed, "None");
	cls_Adaptor3d_HSurface.def("IsVClosed", (Standard_Boolean (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::IsVClosed, "None");
	cls_Adaptor3d_HSurface.def("IsUPeriodic", (Standard_Boolean (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::IsUPeriodic, "None");
	cls_Adaptor3d_HSurface.def("UPeriod", (Standard_Real (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::UPeriod, "None");
	cls_Adaptor3d_HSurface.def("IsVPeriodic", (Standard_Boolean (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::IsVPeriodic, "None");
	cls_Adaptor3d_HSurface.def("VPeriod", (Standard_Real (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::VPeriod, "None");
	cls_Adaptor3d_HSurface.def("Value", (gp_Pnt (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real) const ) &Adaptor3d_HSurface::Value, "None", py::arg("U"), py::arg("V"));
	cls_Adaptor3d_HSurface.def("D0", (void (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const ) &Adaptor3d_HSurface::D0, "None", py::arg("U"), py::arg("V"), py::arg("P"));
	cls_Adaptor3d_HSurface.def("D1", (void (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_HSurface::D1, "None", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
	cls_Adaptor3d_HSurface.def("D2", (void (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_HSurface::D2, "None", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
	cls_Adaptor3d_HSurface.def("D3", (void (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_HSurface::D3, "None", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
	cls_Adaptor3d_HSurface.def("DN", (gp_Vec (Adaptor3d_HSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &Adaptor3d_HSurface::DN, "None", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
	cls_Adaptor3d_HSurface.def("UResolution", (Standard_Real (Adaptor3d_HSurface::*)(const Standard_Real) const ) &Adaptor3d_HSurface::UResolution, "None", py::arg("R3d"));
	cls_Adaptor3d_HSurface.def("VResolution", (Standard_Real (Adaptor3d_HSurface::*)(const Standard_Real) const ) &Adaptor3d_HSurface::VResolution, "None", py::arg("R3d"));
	cls_Adaptor3d_HSurface.def("GetType", (GeomAbs_SurfaceType (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::GetType, "None");
	cls_Adaptor3d_HSurface.def("Plane", (gp_Pln (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::Plane, "None");
	cls_Adaptor3d_HSurface.def("Cylinder", (gp_Cylinder (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::Cylinder, "None");
	cls_Adaptor3d_HSurface.def("Cone", (gp_Cone (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::Cone, "None");
	cls_Adaptor3d_HSurface.def("Sphere", (gp_Sphere (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::Sphere, "None");
	cls_Adaptor3d_HSurface.def("Torus", (gp_Torus (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::Torus, "None");
	cls_Adaptor3d_HSurface.def("UDegree", (Standard_Integer (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::UDegree, "None");
	cls_Adaptor3d_HSurface.def("NbUPoles", (Standard_Integer (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::NbUPoles, "None");
	cls_Adaptor3d_HSurface.def("VDegree", (Standard_Integer (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::VDegree, "None");
	cls_Adaptor3d_HSurface.def("NbVPoles", (Standard_Integer (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::NbVPoles, "None");
	cls_Adaptor3d_HSurface.def("NbUKnots", (Standard_Integer (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::NbUKnots, "None");
	cls_Adaptor3d_HSurface.def("NbVKnots", (Standard_Integer (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::NbVKnots, "None");
	cls_Adaptor3d_HSurface.def("IsURational", (Standard_Boolean (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::IsURational, "None");
	cls_Adaptor3d_HSurface.def("IsVRational", (Standard_Boolean (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::IsVRational, "None");
	cls_Adaptor3d_HSurface.def("Bezier", (opencascade::handle<Geom_BezierSurface> (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::Bezier, "None");
	cls_Adaptor3d_HSurface.def("BSpline", (opencascade::handle<Geom_BSplineSurface> (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::BSpline, "None");
	cls_Adaptor3d_HSurface.def("AxeOfRevolution", (gp_Ax1 (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::AxeOfRevolution, "None");
	cls_Adaptor3d_HSurface.def("Direction", (gp_Dir (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::Direction, "None");
	cls_Adaptor3d_HSurface.def("BasisCurve", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::BasisCurve, "None");
	cls_Adaptor3d_HSurface.def("BasisSurface", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::BasisSurface, "None");
	cls_Adaptor3d_HSurface.def("OffsetValue", (Standard_Real (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::OffsetValue, "None");
	cls_Adaptor3d_HSurface.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_HSurface::get_type_name, "None");
	cls_Adaptor3d_HSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_HSurface::get_type_descriptor, "None");
	cls_Adaptor3d_HSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_HSurface::*)() const ) &Adaptor3d_HSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_CurveOnSurface.hxx
	py::class_<Adaptor3d_CurveOnSurface, std::unique_ptr<Adaptor3d_CurveOnSurface, Deleter<Adaptor3d_CurveOnSurface>>, Adaptor3d_Curve> cls_Adaptor3d_CurveOnSurface(mod, "Adaptor3d_CurveOnSurface", "An interface between the services provided by a curve lying on a surface from the package Geom and those required of the curve by algorithms which use it. The curve is defined as a 2D curve from the Geom2d package, in the parametric space of the surface.");
	cls_Adaptor3d_CurveOnSurface.def(py::init<>());
	cls_Adaptor3d_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S"));
	cls_Adaptor3d_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("C"), py::arg("S"));
	cls_Adaptor3d_CurveOnSurface.def("Load", (void (Adaptor3d_CurveOnSurface::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_CurveOnSurface::Load, "Changes the surface.", py::arg("S"));
	cls_Adaptor3d_CurveOnSurface.def("Load", (void (Adaptor3d_CurveOnSurface::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_CurveOnSurface::Load, "Changes the 2d curve.", py::arg("C"));
	cls_Adaptor3d_CurveOnSurface.def("Load", (void (Adaptor3d_CurveOnSurface::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_CurveOnSurface::Load, "Load both curve and surface.", py::arg("C"), py::arg("S"));
	cls_Adaptor3d_CurveOnSurface.def("GetCurve", (const opencascade::handle<Adaptor2d_HCurve2d> & (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::GetCurve, "None");
	cls_Adaptor3d_CurveOnSurface.def("GetSurface", (const opencascade::handle<Adaptor3d_HSurface> & (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::GetSurface, "None");
	cls_Adaptor3d_CurveOnSurface.def("ChangeCurve", (opencascade::handle<Adaptor2d_HCurve2d> & (Adaptor3d_CurveOnSurface::*)()) &Adaptor3d_CurveOnSurface::ChangeCurve, "None");
	cls_Adaptor3d_CurveOnSurface.def("ChangeSurface", (opencascade::handle<Adaptor3d_HSurface> & (Adaptor3d_CurveOnSurface::*)()) &Adaptor3d_CurveOnSurface::ChangeSurface, "None");
	cls_Adaptor3d_CurveOnSurface.def("FirstParameter", (Standard_Real (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::FirstParameter, "None");
	cls_Adaptor3d_CurveOnSurface.def("LastParameter", (Standard_Real (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::LastParameter, "None");
	cls_Adaptor3d_CurveOnSurface.def("Continuity", (GeomAbs_Shape (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::Continuity, "None");
	cls_Adaptor3d_CurveOnSurface.def("NbIntervals", (Standard_Integer (Adaptor3d_CurveOnSurface::*)(const GeomAbs_Shape) const ) &Adaptor3d_CurveOnSurface::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_Adaptor3d_CurveOnSurface.def("Intervals", (void (Adaptor3d_CurveOnSurface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor3d_CurveOnSurface::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Adaptor3d_CurveOnSurface.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_CurveOnSurface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor3d_CurveOnSurface::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_CurveOnSurface.def("IsClosed", (Standard_Boolean (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::IsClosed, "None");
	cls_Adaptor3d_CurveOnSurface.def("IsPeriodic", (Standard_Boolean (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::IsPeriodic, "None");
	cls_Adaptor3d_CurveOnSurface.def("Period", (Standard_Real (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::Period, "None");
	cls_Adaptor3d_CurveOnSurface.def("Value", (gp_Pnt (Adaptor3d_CurveOnSurface::*)(const Standard_Real) const ) &Adaptor3d_CurveOnSurface::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_Adaptor3d_CurveOnSurface.def("D0", (void (Adaptor3d_CurveOnSurface::*)(const Standard_Real, gp_Pnt &) const ) &Adaptor3d_CurveOnSurface::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_Adaptor3d_CurveOnSurface.def("D1", (void (Adaptor3d_CurveOnSurface::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &Adaptor3d_CurveOnSurface::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Adaptor3d_CurveOnSurface.def("D2", (void (Adaptor3d_CurveOnSurface::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_CurveOnSurface::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Adaptor3d_CurveOnSurface.def("D3", (void (Adaptor3d_CurveOnSurface::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_CurveOnSurface::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Adaptor3d_CurveOnSurface.def("DN", (gp_Vec (Adaptor3d_CurveOnSurface::*)(const Standard_Real, const Standard_Integer) const ) &Adaptor3d_CurveOnSurface::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_Adaptor3d_CurveOnSurface.def("Resolution", (Standard_Real (Adaptor3d_CurveOnSurface::*)(const Standard_Real) const ) &Adaptor3d_CurveOnSurface::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_Adaptor3d_CurveOnSurface.def("GetType", (GeomAbs_CurveType (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
	cls_Adaptor3d_CurveOnSurface.def("Line", (gp_Lin (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::Line, "None");
	cls_Adaptor3d_CurveOnSurface.def("Circle", (gp_Circ (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::Circle, "None");
	cls_Adaptor3d_CurveOnSurface.def("Ellipse", (gp_Elips (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::Ellipse, "None");
	cls_Adaptor3d_CurveOnSurface.def("Hyperbola", (gp_Hypr (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::Hyperbola, "None");
	cls_Adaptor3d_CurveOnSurface.def("Parabola", (gp_Parab (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::Parabola, "None");
	cls_Adaptor3d_CurveOnSurface.def("Degree", (Standard_Integer (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::Degree, "None");
	cls_Adaptor3d_CurveOnSurface.def("IsRational", (Standard_Boolean (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::IsRational, "None");
	cls_Adaptor3d_CurveOnSurface.def("NbPoles", (Standard_Integer (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::NbPoles, "None");
	cls_Adaptor3d_CurveOnSurface.def("NbKnots", (Standard_Integer (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::NbKnots, "None");
	cls_Adaptor3d_CurveOnSurface.def("Bezier", (opencascade::handle<Geom_BezierCurve> (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::Bezier, "None");
	cls_Adaptor3d_CurveOnSurface.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (Adaptor3d_CurveOnSurface::*)() const ) &Adaptor3d_CurveOnSurface::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_HCurveOnSurface.hxx
	py::class_<Adaptor3d_HCurveOnSurface, opencascade::handle<Adaptor3d_HCurveOnSurface>, Adaptor3d_HCurve> cls_Adaptor3d_HCurveOnSurface(mod, "Adaptor3d_HCurveOnSurface", "None");
	cls_Adaptor3d_HCurveOnSurface.def(py::init<>());
	cls_Adaptor3d_HCurveOnSurface.def(py::init<const Adaptor3d_CurveOnSurface &>(), py::arg("C"));
	cls_Adaptor3d_HCurveOnSurface.def("Set", (void (Adaptor3d_HCurveOnSurface::*)(const Adaptor3d_CurveOnSurface &)) &Adaptor3d_HCurveOnSurface::Set, "Sets the field of the GenHCurve.", py::arg("C"));
	cls_Adaptor3d_HCurveOnSurface.def("Curve", (const Adaptor3d_Curve & (Adaptor3d_HCurveOnSurface::*)() const ) &Adaptor3d_HCurveOnSurface::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_Adaptor3d_HCurveOnSurface.def("GetCurve", (Adaptor3d_Curve & (Adaptor3d_HCurveOnSurface::*)()) &Adaptor3d_HCurveOnSurface::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_Adaptor3d_HCurveOnSurface.def("ChangeCurve", (Adaptor3d_CurveOnSurface & (Adaptor3d_HCurveOnSurface::*)()) &Adaptor3d_HCurveOnSurface::ChangeCurve, "Returns the curve used to create the GenHCurve.");
	cls_Adaptor3d_HCurveOnSurface.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_HCurveOnSurface::get_type_name, "None");
	cls_Adaptor3d_HCurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_HCurveOnSurface::get_type_descriptor, "None");
	cls_Adaptor3d_HCurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_HCurveOnSurface::*)() const ) &Adaptor3d_HCurveOnSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_IsoCurve.hxx
	py::class_<Adaptor3d_IsoCurve, std::unique_ptr<Adaptor3d_IsoCurve, Deleter<Adaptor3d_IsoCurve>>, Adaptor3d_Curve> cls_Adaptor3d_IsoCurve(mod, "Adaptor3d_IsoCurve", "Defines an isoparametric curve on a surface. The type of isoparametric curve (U or V) is defined with the enumeration IsoType from GeomAbs if NoneIso is given an error is raised.");
	cls_Adaptor3d_IsoCurve.def(py::init<>());
	cls_Adaptor3d_IsoCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S"));
	cls_Adaptor3d_IsoCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const GeomAbs_IsoType, const Standard_Real>(), py::arg("S"), py::arg("Iso"), py::arg("Param"));
	cls_Adaptor3d_IsoCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("Iso"), py::arg("Param"), py::arg("WFirst"), py::arg("WLast"));
	cls_Adaptor3d_IsoCurve.def("Load", (void (Adaptor3d_IsoCurve::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_IsoCurve::Load, "Changes the surface. The iso is reset to NoneIso.", py::arg("S"));
	cls_Adaptor3d_IsoCurve.def("Load", (void (Adaptor3d_IsoCurve::*)(const GeomAbs_IsoType, const Standard_Real)) &Adaptor3d_IsoCurve::Load, "Changes the iso on the current surface.", py::arg("Iso"), py::arg("Param"));
	cls_Adaptor3d_IsoCurve.def("Load", (void (Adaptor3d_IsoCurve::*)(const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real)) &Adaptor3d_IsoCurve::Load, "Changes the iso on the current surface.", py::arg("Iso"), py::arg("Param"), py::arg("WFirst"), py::arg("WLast"));
	cls_Adaptor3d_IsoCurve.def("Surface", (const opencascade::handle<Adaptor3d_HSurface> & (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Surface, "None");
	cls_Adaptor3d_IsoCurve.def("Iso", (GeomAbs_IsoType (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Iso, "None");
	cls_Adaptor3d_IsoCurve.def("Parameter", (Standard_Real (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Parameter, "None");
	cls_Adaptor3d_IsoCurve.def("FirstParameter", (Standard_Real (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::FirstParameter, "None");
	cls_Adaptor3d_IsoCurve.def("LastParameter", (Standard_Real (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::LastParameter, "None");
	cls_Adaptor3d_IsoCurve.def("Continuity", (GeomAbs_Shape (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Continuity, "None");
	cls_Adaptor3d_IsoCurve.def("NbIntervals", (Standard_Integer (Adaptor3d_IsoCurve::*)(const GeomAbs_Shape) const ) &Adaptor3d_IsoCurve::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_Adaptor3d_IsoCurve.def("Intervals", (void (Adaptor3d_IsoCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor3d_IsoCurve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Adaptor3d_IsoCurve.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_IsoCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor3d_IsoCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_IsoCurve.def("IsClosed", (Standard_Boolean (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::IsClosed, "None");
	cls_Adaptor3d_IsoCurve.def("IsPeriodic", (Standard_Boolean (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::IsPeriodic, "None");
	cls_Adaptor3d_IsoCurve.def("Period", (Standard_Real (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Period, "None");
	cls_Adaptor3d_IsoCurve.def("Value", (gp_Pnt (Adaptor3d_IsoCurve::*)(const Standard_Real) const ) &Adaptor3d_IsoCurve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_Adaptor3d_IsoCurve.def("D0", (void (Adaptor3d_IsoCurve::*)(const Standard_Real, gp_Pnt &) const ) &Adaptor3d_IsoCurve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_Adaptor3d_IsoCurve.def("D1", (void (Adaptor3d_IsoCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &Adaptor3d_IsoCurve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Adaptor3d_IsoCurve.def("D2", (void (Adaptor3d_IsoCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_IsoCurve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Adaptor3d_IsoCurve.def("D3", (void (Adaptor3d_IsoCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_IsoCurve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Adaptor3d_IsoCurve.def("DN", (gp_Vec (Adaptor3d_IsoCurve::*)(const Standard_Real, const Standard_Integer) const ) &Adaptor3d_IsoCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_Adaptor3d_IsoCurve.def("Resolution", (Standard_Real (Adaptor3d_IsoCurve::*)(const Standard_Real) const ) &Adaptor3d_IsoCurve::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_Adaptor3d_IsoCurve.def("GetType", (GeomAbs_CurveType (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
	cls_Adaptor3d_IsoCurve.def("Line", (gp_Lin (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Line, "None");
	cls_Adaptor3d_IsoCurve.def("Circle", (gp_Circ (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Circle, "None");
	cls_Adaptor3d_IsoCurve.def("Ellipse", (gp_Elips (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Ellipse, "None");
	cls_Adaptor3d_IsoCurve.def("Hyperbola", (gp_Hypr (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Hyperbola, "None");
	cls_Adaptor3d_IsoCurve.def("Parabola", (gp_Parab (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Parabola, "None");
	cls_Adaptor3d_IsoCurve.def("Degree", (Standard_Integer (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Degree, "None");
	cls_Adaptor3d_IsoCurve.def("IsRational", (Standard_Boolean (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::IsRational, "None");
	cls_Adaptor3d_IsoCurve.def("NbPoles", (Standard_Integer (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::NbPoles, "None");
	cls_Adaptor3d_IsoCurve.def("NbKnots", (Standard_Integer (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::NbKnots, "None");
	cls_Adaptor3d_IsoCurve.def("Bezier", (opencascade::handle<Geom_BezierCurve> (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::Bezier, "None");
	cls_Adaptor3d_IsoCurve.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (Adaptor3d_IsoCurve::*)() const ) &Adaptor3d_IsoCurve::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_HIsoCurve.hxx
	py::class_<Adaptor3d_HIsoCurve, opencascade::handle<Adaptor3d_HIsoCurve>, Adaptor3d_HCurve> cls_Adaptor3d_HIsoCurve(mod, "Adaptor3d_HIsoCurve", "None");
	cls_Adaptor3d_HIsoCurve.def(py::init<>());
	cls_Adaptor3d_HIsoCurve.def(py::init<const Adaptor3d_IsoCurve &>(), py::arg("C"));
	cls_Adaptor3d_HIsoCurve.def("Set", (void (Adaptor3d_HIsoCurve::*)(const Adaptor3d_IsoCurve &)) &Adaptor3d_HIsoCurve::Set, "Sets the field of the GenHCurve.", py::arg("C"));
	cls_Adaptor3d_HIsoCurve.def("Curve", (const Adaptor3d_Curve & (Adaptor3d_HIsoCurve::*)() const ) &Adaptor3d_HIsoCurve::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_Adaptor3d_HIsoCurve.def("GetCurve", (Adaptor3d_Curve & (Adaptor3d_HIsoCurve::*)()) &Adaptor3d_HIsoCurve::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_Adaptor3d_HIsoCurve.def("ChangeCurve", (Adaptor3d_IsoCurve & (Adaptor3d_HIsoCurve::*)()) &Adaptor3d_HIsoCurve::ChangeCurve, "Returns the curve used to create the GenHCurve.");
	cls_Adaptor3d_HIsoCurve.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_HIsoCurve::get_type_name, "None");
	cls_Adaptor3d_HIsoCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_HIsoCurve::get_type_descriptor, "None");
	cls_Adaptor3d_HIsoCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_HIsoCurve::*)() const ) &Adaptor3d_HIsoCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_Surface.hxx
	py::class_<Adaptor3d_Surface, std::unique_ptr<Adaptor3d_Surface, Deleter<Adaptor3d_Surface>>> cls_Adaptor3d_Surface(mod, "Adaptor3d_Surface", "Root class for surfaces on which geometric algorithms work. An adapted surface is an interface between the services provided by a surface and those required of the surface by algorithms which use it. A derived concrete class is provided: GeomAdaptor_Surface for a surface from the Geom package. The Surface class describes the standard behaviour of a surface for generic algorithms.");
	cls_Adaptor3d_Surface.def(py::init<>());
	cls_Adaptor3d_Surface.def("FirstUParameter", (Standard_Real (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::FirstUParameter, "None");
	cls_Adaptor3d_Surface.def("LastUParameter", (Standard_Real (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::LastUParameter, "None");
	cls_Adaptor3d_Surface.def("FirstVParameter", (Standard_Real (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::FirstVParameter, "None");
	cls_Adaptor3d_Surface.def("LastVParameter", (Standard_Real (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::LastVParameter, "None");
	cls_Adaptor3d_Surface.def("UContinuity", (GeomAbs_Shape (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::UContinuity, "None");
	cls_Adaptor3d_Surface.def("VContinuity", (GeomAbs_Shape (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::VContinuity, "None");
	cls_Adaptor3d_Surface.def("NbUIntervals", (Standard_Integer (Adaptor3d_Surface::*)(const GeomAbs_Shape) const ) &Adaptor3d_Surface::NbUIntervals, "Returns the number of U intervals for continuity <S>. May be one if UContinuity(me) >= <S>", py::arg("S"));
	cls_Adaptor3d_Surface.def("NbVIntervals", (Standard_Integer (Adaptor3d_Surface::*)(const GeomAbs_Shape) const ) &Adaptor3d_Surface::NbVIntervals, "Returns the number of V intervals for continuity <S>. May be one if VContinuity(me) >= <S>", py::arg("S"));
	cls_Adaptor3d_Surface.def("UIntervals", (void (Adaptor3d_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor3d_Surface::UIntervals, "Returns the intervals with the requested continuity in the U direction.", py::arg("T"), py::arg("S"));
	cls_Adaptor3d_Surface.def("VIntervals", (void (Adaptor3d_Surface::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Adaptor3d_Surface::VIntervals, "Returns the intervals with the requested continuity in the V direction.", py::arg("T"), py::arg("S"));
	cls_Adaptor3d_Surface.def("UTrim", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor3d_Surface::UTrim, "Returns a surface trimmed in the U direction equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_Surface.def("VTrim", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Adaptor3d_Surface::VTrim, "Returns a surface trimmed in the V direction between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_Surface.def("IsUClosed", (Standard_Boolean (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::IsUClosed, "None");
	cls_Adaptor3d_Surface.def("IsVClosed", (Standard_Boolean (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::IsVClosed, "None");
	cls_Adaptor3d_Surface.def("IsUPeriodic", (Standard_Boolean (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::IsUPeriodic, "None");
	cls_Adaptor3d_Surface.def("UPeriod", (Standard_Real (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::UPeriod, "None");
	cls_Adaptor3d_Surface.def("IsVPeriodic", (Standard_Boolean (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::IsVPeriodic, "None");
	cls_Adaptor3d_Surface.def("VPeriod", (Standard_Real (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::VPeriod, "None");
	cls_Adaptor3d_Surface.def("Value", (gp_Pnt (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real) const ) &Adaptor3d_Surface::Value, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"));
	cls_Adaptor3d_Surface.def("D0", (void (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const ) &Adaptor3d_Surface::D0, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
	cls_Adaptor3d_Surface.def("D1", (void (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_Surface::D1, "Computes the point and the first derivatives on the surface. Raised if the continuity of the current intervals is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
	cls_Adaptor3d_Surface.def("D2", (void (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_Surface::D2, "Computes the point, the first and second derivatives on the surface. Raised if the continuity of the current intervals is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
	cls_Adaptor3d_Surface.def("D3", (void (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &Adaptor3d_Surface::D3, "Computes the point, the first, second and third derivatives on the surface. Raised if the continuity of the current intervals is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
	cls_Adaptor3d_Surface.def("DN", (gp_Vec (Adaptor3d_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &Adaptor3d_Surface::DN, "Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V). Raised if the current U interval is not not CNu and the current V interval is not CNv. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
	cls_Adaptor3d_Surface.def("UResolution", (Standard_Real (Adaptor3d_Surface::*)(const Standard_Real) const ) &Adaptor3d_Surface::UResolution, "Returns the parametric U resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_Adaptor3d_Surface.def("VResolution", (Standard_Real (Adaptor3d_Surface::*)(const Standard_Real) const ) &Adaptor3d_Surface::VResolution, "Returns the parametric V resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_Adaptor3d_Surface.def("GetType", (GeomAbs_SurfaceType (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::GetType, "Returns the type of the surface : Plane, Cylinder, Cone, Sphere, Torus, BezierSurface, BSplineSurface, SurfaceOfRevolution, SurfaceOfExtrusion, OtherSurface");
	cls_Adaptor3d_Surface.def("Plane", (gp_Pln (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::Plane, "None");
	cls_Adaptor3d_Surface.def("Cylinder", (gp_Cylinder (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::Cylinder, "None");
	cls_Adaptor3d_Surface.def("Cone", (gp_Cone (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::Cone, "None");
	cls_Adaptor3d_Surface.def("Sphere", (gp_Sphere (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::Sphere, "None");
	cls_Adaptor3d_Surface.def("Torus", (gp_Torus (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::Torus, "None");
	cls_Adaptor3d_Surface.def("UDegree", (Standard_Integer (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::UDegree, "None");
	cls_Adaptor3d_Surface.def("NbUPoles", (Standard_Integer (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::NbUPoles, "None");
	cls_Adaptor3d_Surface.def("VDegree", (Standard_Integer (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::VDegree, "None");
	cls_Adaptor3d_Surface.def("NbVPoles", (Standard_Integer (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::NbVPoles, "None");
	cls_Adaptor3d_Surface.def("NbUKnots", (Standard_Integer (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::NbUKnots, "None");
	cls_Adaptor3d_Surface.def("NbVKnots", (Standard_Integer (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::NbVKnots, "None");
	cls_Adaptor3d_Surface.def("IsURational", (Standard_Boolean (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::IsURational, "None");
	cls_Adaptor3d_Surface.def("IsVRational", (Standard_Boolean (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::IsVRational, "None");
	cls_Adaptor3d_Surface.def("Bezier", (opencascade::handle<Geom_BezierSurface> (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::Bezier, "None");
	cls_Adaptor3d_Surface.def("BSpline", (opencascade::handle<Geom_BSplineSurface> (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::BSpline, "None");
	cls_Adaptor3d_Surface.def("AxeOfRevolution", (gp_Ax1 (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::AxeOfRevolution, "None");
	cls_Adaptor3d_Surface.def("Direction", (gp_Dir (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::Direction, "None");
	cls_Adaptor3d_Surface.def("BasisCurve", (opencascade::handle<Adaptor3d_HCurve> (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::BasisCurve, "None");
	cls_Adaptor3d_Surface.def("BasisSurface", (opencascade::handle<Adaptor3d_HSurface> (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::BasisSurface, "None");
	cls_Adaptor3d_Surface.def("OffsetValue", (Standard_Real (Adaptor3d_Surface::*)() const ) &Adaptor3d_Surface::OffsetValue, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_HSurfaceTool.hxx
	py::class_<Adaptor3d_HSurfaceTool, std::unique_ptr<Adaptor3d_HSurfaceTool, Deleter<Adaptor3d_HSurfaceTool>>> cls_Adaptor3d_HSurfaceTool(mod, "Adaptor3d_HSurfaceTool", "None");
	cls_Adaptor3d_HSurfaceTool.def(py::init<>());
	cls_Adaptor3d_HSurfaceTool.def_static("FirstUParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::FirstUParameter, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("FirstVParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::FirstVParameter, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("LastUParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::LastUParameter, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("LastVParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::LastVParameter, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("NbUIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const GeomAbs_Shape)) &Adaptor3d_HSurfaceTool::NbUIntervals, "None", py::arg("S"), py::arg("Sh"));
	cls_Adaptor3d_HSurfaceTool.def_static("NbVIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const GeomAbs_Shape)) &Adaptor3d_HSurfaceTool::NbVIntervals, "None", py::arg("S"), py::arg("Sh"));
	cls_Adaptor3d_HSurfaceTool.def_static("UIntervals_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &Adaptor3d_HSurfaceTool::UIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
	cls_Adaptor3d_HSurfaceTool.def_static("VIntervals_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &Adaptor3d_HSurfaceTool::VIntervals, "None", py::arg("S"), py::arg("T"), py::arg("Sh"));
	cls_Adaptor3d_HSurfaceTool.def_static("UTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::UTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_HSurfaceTool.def_static("VTrim_", (opencascade::handle<Adaptor3d_HSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::VTrim, "If <First> >= <Last>", py::arg("S"), py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Adaptor3d_HSurfaceTool.def_static("IsUClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::IsUClosed, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("IsVClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::IsVClosed, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("IsUPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::IsUPeriodic, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("UPeriod_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::UPeriod, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("IsVPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::IsVPeriodic, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("VPeriod_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::VPeriod, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("Value_", (gp_Pnt (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::Value, "None", py::arg("S"), py::arg("u"), py::arg("v"));
	cls_Adaptor3d_HSurfaceTool.def_static("D0_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &)) &Adaptor3d_HSurfaceTool::D0, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"));
	cls_Adaptor3d_HSurfaceTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &Adaptor3d_HSurfaceTool::D1, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1u"), py::arg("D1v"));
	cls_Adaptor3d_HSurfaceTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &Adaptor3d_HSurfaceTool::D2, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
	cls_Adaptor3d_HSurfaceTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &Adaptor3d_HSurfaceTool::D3, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
	cls_Adaptor3d_HSurfaceTool.def_static("DN_", (gp_Vec (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &Adaptor3d_HSurfaceTool::DN, "None", py::arg("S"), py::arg("u"), py::arg("v"), py::arg("Nu"), py::arg("Nv"));
	cls_Adaptor3d_HSurfaceTool.def_static("UResolution_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real)) &Adaptor3d_HSurfaceTool::UResolution, "None", py::arg("S"), py::arg("R3d"));
	cls_Adaptor3d_HSurfaceTool.def_static("VResolution_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real)) &Adaptor3d_HSurfaceTool::VResolution, "None", py::arg("S"), py::arg("R3d"));
	cls_Adaptor3d_HSurfaceTool.def_static("GetType_", (GeomAbs_SurfaceType (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::GetType, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("Plane_", (gp_Pln (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Plane, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("Cylinder_", (gp_Cylinder (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Cylinder, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("Cone_", (gp_Cone (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Cone, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("Torus_", (gp_Torus (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Torus, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("Sphere_", (gp_Sphere (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Sphere, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("Bezier_", (opencascade::handle<Geom_BezierSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Bezier, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::BSpline, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("AxeOfRevolution_", (gp_Ax1 (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::AxeOfRevolution, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("Direction_", (gp_Dir (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::Direction, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("BasisCurve_", (opencascade::handle<Adaptor3d_HCurve> (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::BasisCurve, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("BasisSurface_", (opencascade::handle<Adaptor3d_HSurface> (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::BasisSurface, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("OffsetValue_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::OffsetValue, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::NbSamplesU, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_HSurfaceTool::NbSamplesV, "None", py::arg("S"));
	cls_Adaptor3d_HSurfaceTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
	cls_Adaptor3d_HSurfaceTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Adaptor3d_HSurfaceTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_HVertex.hxx
	py::class_<Adaptor3d_HVertex, opencascade::handle<Adaptor3d_HVertex>, Standard_Transient> cls_Adaptor3d_HVertex(mod, "Adaptor3d_HVertex", "None");
	cls_Adaptor3d_HVertex.def(py::init<>());
	cls_Adaptor3d_HVertex.def(py::init<const gp_Pnt2d &, const TopAbs_Orientation, const Standard_Real>(), py::arg("P"), py::arg("Ori"), py::arg("Resolution"));
	cls_Adaptor3d_HVertex.def("Value", (gp_Pnt2d (Adaptor3d_HVertex::*)()) &Adaptor3d_HVertex::Value, "None");
	cls_Adaptor3d_HVertex.def("Parameter", (Standard_Real (Adaptor3d_HVertex::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_HVertex::Parameter, "None", py::arg("C"));
	cls_Adaptor3d_HVertex.def("Resolution", (Standard_Real (Adaptor3d_HVertex::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_HVertex::Resolution, "Parametric resolution (2d).", py::arg("C"));
	cls_Adaptor3d_HVertex.def("Orientation", (TopAbs_Orientation (Adaptor3d_HVertex::*)()) &Adaptor3d_HVertex::Orientation, "None");
	cls_Adaptor3d_HVertex.def("IsSame", (Standard_Boolean (Adaptor3d_HVertex::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &Adaptor3d_HVertex::IsSame, "None", py::arg("Other"));
	cls_Adaptor3d_HVertex.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_HVertex::get_type_name, "None");
	cls_Adaptor3d_HVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_HVertex::get_type_descriptor, "None");
	cls_Adaptor3d_HVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_HVertex::*)() const ) &Adaptor3d_HVertex::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_InterFunc.hxx
	py::class_<Adaptor3d_InterFunc, std::unique_ptr<Adaptor3d_InterFunc, Deleter<Adaptor3d_InterFunc>>, math_FunctionWithDerivative> cls_Adaptor3d_InterFunc(mod, "Adaptor3d_InterFunc", "Used to find the points U(t) = U0 or V(t) = V0 in order to determine the Cn discontinuities of an Adpator_CurveOnSurface relativly to the discontinuities of the surface. Used to find the roots of the functions");
	cls_Adaptor3d_InterFunc.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("FixVal"), py::arg("Fix"));
	cls_Adaptor3d_InterFunc.def("Value", (Standard_Boolean (Adaptor3d_InterFunc::*)(const Standard_Real, Standard_Real &)) &Adaptor3d_InterFunc::Value, "computes the value <F>of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"));
	cls_Adaptor3d_InterFunc.def("Derivative", (Standard_Boolean (Adaptor3d_InterFunc::*)(const Standard_Real, Standard_Real &)) &Adaptor3d_InterFunc::Derivative, "computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
	cls_Adaptor3d_InterFunc.def("Values", (Standard_Boolean (Adaptor3d_InterFunc::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &Adaptor3d_InterFunc::Values, "computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_TopolTool.hxx
	py::class_<Adaptor3d_TopolTool, opencascade::handle<Adaptor3d_TopolTool>, Standard_Transient> cls_Adaptor3d_TopolTool(mod, "Adaptor3d_TopolTool", "This class provides a default topological tool, based on the Umin,Vmin,Umax,Vmax of an HSurface from Adaptor3d. All methods and fields may be redefined when inheriting from this class. This class is used to instantiate algorithmes as Intersection, outlines,...");
	cls_Adaptor3d_TopolTool.def(py::init<>());
	cls_Adaptor3d_TopolTool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("Surface"));
	cls_Adaptor3d_TopolTool.def("Initialize", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Initialize, "None");
	cls_Adaptor3d_TopolTool.def("Initialize", (void (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_TopolTool::Initialize, "None", py::arg("S"));
	cls_Adaptor3d_TopolTool.def("Initialize", (void (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_TopolTool::Initialize, "None", py::arg("Curve"));
	cls_Adaptor3d_TopolTool.def("Init", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Init, "None");
	cls_Adaptor3d_TopolTool.def("More", (Standard_Boolean (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::More, "None");
	cls_Adaptor3d_TopolTool.def("Value", (opencascade::handle<Adaptor2d_HCurve2d> (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Value, "None");
	cls_Adaptor3d_TopolTool.def("Next", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Next, "None");
	cls_Adaptor3d_TopolTool.def("InitVertexIterator", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::InitVertexIterator, "None");
	cls_Adaptor3d_TopolTool.def("MoreVertex", (Standard_Boolean (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::MoreVertex, "None");
	cls_Adaptor3d_TopolTool.def("Vertex", (opencascade::handle<Adaptor3d_HVertex> (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Vertex, "None");
	cls_Adaptor3d_TopolTool.def("NextVertex", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::NextVertex, "None");
	cls_Adaptor3d_TopolTool.def("Classify", [](Adaptor3d_TopolTool &self, const gp_Pnt2d & a0, const Standard_Real a1) -> TopAbs_State { return self.Classify(a0, a1); }, py::arg("P"), py::arg("Tol"));
	cls_Adaptor3d_TopolTool.def("Classify", (TopAbs_State (Adaptor3d_TopolTool::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &Adaptor3d_TopolTool::Classify, "None", py::arg("P"), py::arg("Tol"), py::arg("ReacdreOnPeriodic"));
	cls_Adaptor3d_TopolTool.def("IsThePointOn", [](Adaptor3d_TopolTool &self, const gp_Pnt2d & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsThePointOn(a0, a1); }, py::arg("P"), py::arg("Tol"));
	cls_Adaptor3d_TopolTool.def("IsThePointOn", (Standard_Boolean (Adaptor3d_TopolTool::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &Adaptor3d_TopolTool::IsThePointOn, "None", py::arg("P"), py::arg("Tol"), py::arg("ReacdreOnPeriodic"));
	cls_Adaptor3d_TopolTool.def("Orientation", (TopAbs_Orientation (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_TopolTool::Orientation, "If the function returns the orientation of the arc. If the orientation is FORWARD or REVERSED, the arc is a 'real' limit of the surface. If the orientation is INTERNAL or EXTERNAL, the arc is considered as an arc on the surface.", py::arg("C"));
	cls_Adaptor3d_TopolTool.def("Orientation", (TopAbs_Orientation (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &Adaptor3d_TopolTool::Orientation, "Returns the orientation of the vertex V. The vertex has been found with an exploration on a given arc. The orientation is the orientation of the vertex on this arc.", py::arg("V"));
	cls_Adaptor3d_TopolTool.def("Identical", (Standard_Boolean (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor3d_HVertex> &)) &Adaptor3d_TopolTool::Identical, "Returns True if the vertices V1 and V2 are identical. This method does not take the orientation of the vertices in account.", py::arg("V1"), py::arg("V2"));
	cls_Adaptor3d_TopolTool.def("Has3d", (Standard_Boolean (Adaptor3d_TopolTool::*)() const ) &Adaptor3d_TopolTool::Has3d, "answers if arcs and vertices may have 3d representations, so that we could use Tol3d and Pnt methods.");
	cls_Adaptor3d_TopolTool.def("Tol3d", (Standard_Real (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &) const ) &Adaptor3d_TopolTool::Tol3d, "returns 3d tolerance of the arc C", py::arg("C"));
	cls_Adaptor3d_TopolTool.def("Tol3d", (Standard_Real (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &) const ) &Adaptor3d_TopolTool::Tol3d, "returns 3d tolerance of the vertex V", py::arg("V"));
	cls_Adaptor3d_TopolTool.def("Pnt", (gp_Pnt (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &) const ) &Adaptor3d_TopolTool::Pnt, "returns 3d point of the vertex V", py::arg("V"));
	cls_Adaptor3d_TopolTool.def("ComputeSamplePoints", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::ComputeSamplePoints, "None");
	cls_Adaptor3d_TopolTool.def("NbSamplesU", (Standard_Integer (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::NbSamplesU, "compute the sample-points for the intersections algorithms");
	cls_Adaptor3d_TopolTool.def("NbSamplesV", (Standard_Integer (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::NbSamplesV, "compute the sample-points for the intersections algorithms");
	cls_Adaptor3d_TopolTool.def("NbSamples", (Standard_Integer (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::NbSamples, "compute the sample-points for the intersections algorithms");
	cls_Adaptor3d_TopolTool.def("UParameters", (void (Adaptor3d_TopolTool::*)(TColStd_Array1OfReal &) const ) &Adaptor3d_TopolTool::UParameters, "return the set of U parameters on the surface obtained by the method SamplePnts", py::arg("theArray"));
	cls_Adaptor3d_TopolTool.def("VParameters", (void (Adaptor3d_TopolTool::*)(TColStd_Array1OfReal &) const ) &Adaptor3d_TopolTool::VParameters, "return the set of V parameters on the surface obtained by the method SamplePnts", py::arg("theArray"));
	cls_Adaptor3d_TopolTool.def("SamplePoint", (void (Adaptor3d_TopolTool::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt &)) &Adaptor3d_TopolTool::SamplePoint, "None", py::arg("Index"), py::arg("P2d"), py::arg("P3d"));
	cls_Adaptor3d_TopolTool.def("DomainIsInfinite", (Standard_Boolean (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::DomainIsInfinite, "None");
	cls_Adaptor3d_TopolTool.def("Edge", (Standard_Address (Adaptor3d_TopolTool::*)() const ) &Adaptor3d_TopolTool::Edge, "None");
	cls_Adaptor3d_TopolTool.def("SamplePnts", (void (Adaptor3d_TopolTool::*)(const Standard_Real, const Standard_Integer, const Standard_Integer)) &Adaptor3d_TopolTool::SamplePnts, "compute the sample-points for the intersections algorithms by adaptive algorithm for BSpline surfaces. For other surfaces algorithm is the same as in method ComputeSamplePoints(), but only fill arrays of U and V sample parameters; theDefl is a requred deflection theNUmin, theNVmin are minimal nb points for U and V.", py::arg("theDefl"), py::arg("theNUmin"), py::arg("theNVmin"));
	cls_Adaptor3d_TopolTool.def("BSplSamplePnts", (void (Adaptor3d_TopolTool::*)(const Standard_Real, const Standard_Integer, const Standard_Integer)) &Adaptor3d_TopolTool::BSplSamplePnts, "compute the sample-points for the intersections algorithms by adaptive algorithm for BSpline surfaces - is used in SamplePnts theDefl is a requred deflection theNUmin, theNVmin are minimal nb points for U and V.", py::arg("theDefl"), py::arg("theNUmin"), py::arg("theNVmin"));
	cls_Adaptor3d_TopolTool.def("IsUniformSampling", (Standard_Boolean (Adaptor3d_TopolTool::*)() const ) &Adaptor3d_TopolTool::IsUniformSampling, "Returns true if provide uniform sampling of points.");
	cls_Adaptor3d_TopolTool.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_TopolTool::get_type_name, "None");
	cls_Adaptor3d_TopolTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_TopolTool::get_type_descriptor, "None");
	cls_Adaptor3d_TopolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_TopolTool::*)() const ) &Adaptor3d_TopolTool::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_CurveOnSurfacePtr.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_CurvePtr.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Adaptor3d_SurfacePtr.hxx

}
