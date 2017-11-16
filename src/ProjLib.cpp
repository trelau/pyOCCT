#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Adaptor2d_Curve2d.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <ProjLib_ProjectedCurve.hxx>
#include <Adaptor3d_Curve.hxx>
#include <gp_Ax3.hxx>
#include <gp_Dir.hxx>
#include <GeomAdaptor_HCurve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <ProjLib_ProjectOnPlane.hxx>
#include <ProjLib_ProjectOnSurface.hxx>
#include <ProjLib_ComputeApprox.hxx>
#include <Geom2d_Curve.hxx>
#include <ProjLib_ComputeApproxOnPolarSurface.hxx>
#include <Standard_Type.hxx>
#include <ProjLib_HProjectedCurve.hxx>
#include <ProjLib_HSequenceOfHSequenceOfPnt.hxx>
#include <ProjLib_CompProjectedCurve.hxx>
#include <ProjLib_HCompProjectedCurve.hxx>
#include <Adaptor3d_Surface.hxx>
#include <ProjLib_PrjResolve.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <Adaptor3d_CurvePtr.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <ProjLib_PrjFunc.hxx>
#include <ProjLib_Projector.hxx>
#include <gp_Pln.hxx>
#include <ProjLib_Plane.hxx>
#include <gp_Cylinder.hxx>
#include <ProjLib_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <ProjLib_Cone.hxx>
#include <gp_Sphere.hxx>
#include <ProjLib_Sphere.hxx>
#include <gp_Torus.hxx>
#include <ProjLib_Torus.hxx>
#include <ProjLib.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <ProjLib_SequenceOfHSequenceOfPnt.hxx>
#include <Standard_Transient.hxx>

PYBIND11_MODULE(ProjLib, mod) {

	// IMPORT
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.GeomAdaptor");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.math");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_ProjectedCurve.hxx
	py::class_<ProjLib_ProjectedCurve, std::unique_ptr<ProjLib_ProjectedCurve, Deleter<ProjLib_ProjectedCurve>>, Adaptor2d_Curve2d> cls_ProjLib_ProjectedCurve(mod, "ProjLib_ProjectedCurve", "Compute the 2d-curve. Try to solve the particular case if possible. Otherwize, an approximation is done.");
	cls_ProjLib_ProjectedCurve.def(py::init<>());
	cls_ProjLib_ProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S"));
	cls_ProjLib_ProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"));
	cls_ProjLib_ProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("S"), py::arg("C"), py::arg("Tol"));
	cls_ProjLib_ProjectedCurve.def("Load", (void (ProjLib_ProjectedCurve::*)(const Standard_Real)) &ProjLib_ProjectedCurve::Load, "Changes the tolerance used to project the curve on the surface", py::arg("Tolerance"));
	cls_ProjLib_ProjectedCurve.def("Load", (void (ProjLib_ProjectedCurve::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ProjectedCurve::Load, "Changes the Surface.", py::arg("S"));
	cls_ProjLib_ProjectedCurve.def("Load", (void (ProjLib_ProjectedCurve::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &ProjLib_ProjectedCurve::Load, "Changes the Curve.", py::arg("C"));
	cls_ProjLib_ProjectedCurve.def("GetSurface", (const opencascade::handle<Adaptor3d_HSurface> & (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::GetSurface, "None");
	cls_ProjLib_ProjectedCurve.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::GetCurve, "None");
	cls_ProjLib_ProjectedCurve.def("GetTolerance", (Standard_Real (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::GetTolerance, "returns the tolerance reached if an approximation is Done.");
	cls_ProjLib_ProjectedCurve.def("FirstParameter", (Standard_Real (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::FirstParameter, "None");
	cls_ProjLib_ProjectedCurve.def("LastParameter", (Standard_Real (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::LastParameter, "None");
	cls_ProjLib_ProjectedCurve.def("Continuity", (GeomAbs_Shape (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::Continuity, "None");
	cls_ProjLib_ProjectedCurve.def("NbIntervals", (Standard_Integer (ProjLib_ProjectedCurve::*)(const GeomAbs_Shape) const ) &ProjLib_ProjectedCurve::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
	cls_ProjLib_ProjectedCurve.def("Intervals", (void (ProjLib_ProjectedCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &ProjLib_ProjectedCurve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_ProjLib_ProjectedCurve.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (ProjLib_ProjectedCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &ProjLib_ProjectedCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_ProjLib_ProjectedCurve.def("IsClosed", (Standard_Boolean (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::IsClosed, "None");
	cls_ProjLib_ProjectedCurve.def("IsPeriodic", (Standard_Boolean (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::IsPeriodic, "None");
	cls_ProjLib_ProjectedCurve.def("Period", (Standard_Real (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::Period, "None");
	cls_ProjLib_ProjectedCurve.def("Value", (gp_Pnt2d (ProjLib_ProjectedCurve::*)(const Standard_Real) const ) &ProjLib_ProjectedCurve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_ProjLib_ProjectedCurve.def("D0", (void (ProjLib_ProjectedCurve::*)(const Standard_Real, gp_Pnt2d &) const ) &ProjLib_ProjectedCurve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_ProjLib_ProjectedCurve.def("D1", (void (ProjLib_ProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &ProjLib_ProjectedCurve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_ProjLib_ProjectedCurve.def("D2", (void (ProjLib_ProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &ProjLib_ProjectedCurve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_ProjLib_ProjectedCurve.def("D3", (void (ProjLib_ProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const ) &ProjLib_ProjectedCurve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_ProjLib_ProjectedCurve.def("DN", (gp_Vec2d (ProjLib_ProjectedCurve::*)(const Standard_Real, const Standard_Integer) const ) &ProjLib_ProjectedCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_ProjLib_ProjectedCurve.def("Resolution", (Standard_Real (ProjLib_ProjectedCurve::*)(const Standard_Real) const ) &ProjLib_ProjectedCurve::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_ProjLib_ProjectedCurve.def("GetType", (GeomAbs_CurveType (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
	cls_ProjLib_ProjectedCurve.def("Line", (gp_Lin2d (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::Line, "None");
	cls_ProjLib_ProjectedCurve.def("Circle", (gp_Circ2d (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::Circle, "None");
	cls_ProjLib_ProjectedCurve.def("Ellipse", (gp_Elips2d (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::Ellipse, "None");
	cls_ProjLib_ProjectedCurve.def("Hyperbola", (gp_Hypr2d (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::Hyperbola, "None");
	cls_ProjLib_ProjectedCurve.def("Parabola", (gp_Parab2d (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::Parabola, "None");
	cls_ProjLib_ProjectedCurve.def("Degree", (Standard_Integer (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::Degree, "None");
	cls_ProjLib_ProjectedCurve.def("IsRational", (Standard_Boolean (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::IsRational, "None");
	cls_ProjLib_ProjectedCurve.def("NbPoles", (Standard_Integer (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::NbPoles, "None");
	cls_ProjLib_ProjectedCurve.def("NbKnots", (Standard_Integer (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::NbKnots, "None");
	cls_ProjLib_ProjectedCurve.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::Bezier, "Warning ! This will NOT make a copy of the -- Bezier Curve - If you want to modify -- the Curve please make a copy yourself -- Also it will NOT trim the surface to -- myFirst/Last.");
	cls_ProjLib_ProjectedCurve.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ProjectedCurve::*)() const ) &ProjLib_ProjectedCurve::BSpline, "Warning ! This will NOT make a copy of the BSpline Curve - If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_ProjectOnPlane.hxx
	py::class_<ProjLib_ProjectOnPlane, std::unique_ptr<ProjLib_ProjectOnPlane, Deleter<ProjLib_ProjectOnPlane>>, Adaptor3d_Curve> cls_ProjLib_ProjectOnPlane(mod, "ProjLib_ProjectOnPlane", "Class used to project a 3d curve on a plane. The result will be a 3d curve.");
	cls_ProjLib_ProjectOnPlane.def(py::init<>());
	cls_ProjLib_ProjectOnPlane.def(py::init<const gp_Ax3 &>(), py::arg("Pl"));
	cls_ProjLib_ProjectOnPlane.def(py::init<const gp_Ax3 &, const gp_Dir &>(), py::arg("Pl"), py::arg("D"));
	cls_ProjLib_ProjectOnPlane.def("Load", [](ProjLib_ProjectOnPlane &self, const opencascade::handle<Adaptor3d_HCurve> & a0, const Standard_Real a1) -> void { return self.Load(a0, a1); }, py::arg("C"), py::arg("Tolerance"));
	cls_ProjLib_ProjectOnPlane.def("Load", (void (ProjLib_ProjectOnPlane::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Boolean)) &ProjLib_ProjectOnPlane::Load, "Sets the Curve and perform the projection. if <KeepParametrization> is true, the parametrization of the Projected Curve <PC> will be the same as the parametrization of the initial curve <C>. It meens: proj(C(u)) = PC(u) for each u. Otherwize, the parametrization may change.", py::arg("C"), py::arg("Tolerance"), py::arg("KeepParametrization"));
	cls_ProjLib_ProjectOnPlane.def("GetPlane", (const gp_Ax3 & (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::GetPlane, "None");
	cls_ProjLib_ProjectOnPlane.def("GetDirection", (const gp_Dir & (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::GetDirection, "None");
	cls_ProjLib_ProjectOnPlane.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::GetCurve, "None");
	cls_ProjLib_ProjectOnPlane.def("GetResult", (const opencascade::handle<GeomAdaptor_HCurve> & (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::GetResult, "None");
	cls_ProjLib_ProjectOnPlane.def("FirstParameter", (Standard_Real (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::FirstParameter, "None");
	cls_ProjLib_ProjectOnPlane.def("LastParameter", (Standard_Real (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::LastParameter, "None");
	cls_ProjLib_ProjectOnPlane.def("Continuity", (GeomAbs_Shape (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::Continuity, "None");
	cls_ProjLib_ProjectOnPlane.def("NbIntervals", (Standard_Integer (ProjLib_ProjectOnPlane::*)(const GeomAbs_Shape) const ) &ProjLib_ProjectOnPlane::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
	cls_ProjLib_ProjectOnPlane.def("Intervals", (void (ProjLib_ProjectOnPlane::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &ProjLib_ProjectOnPlane::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_ProjLib_ProjectOnPlane.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (ProjLib_ProjectOnPlane::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &ProjLib_ProjectOnPlane::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_ProjLib_ProjectOnPlane.def("IsClosed", (Standard_Boolean (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::IsClosed, "None");
	cls_ProjLib_ProjectOnPlane.def("IsPeriodic", (Standard_Boolean (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::IsPeriodic, "None");
	cls_ProjLib_ProjectOnPlane.def("Period", (Standard_Real (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::Period, "None");
	cls_ProjLib_ProjectOnPlane.def("Value", (gp_Pnt (ProjLib_ProjectOnPlane::*)(const Standard_Real) const ) &ProjLib_ProjectOnPlane::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_ProjLib_ProjectOnPlane.def("D0", (void (ProjLib_ProjectOnPlane::*)(const Standard_Real, gp_Pnt &) const ) &ProjLib_ProjectOnPlane::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_ProjLib_ProjectOnPlane.def("D1", (void (ProjLib_ProjectOnPlane::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &ProjLib_ProjectOnPlane::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_ProjLib_ProjectOnPlane.def("D2", (void (ProjLib_ProjectOnPlane::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &ProjLib_ProjectOnPlane::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_ProjLib_ProjectOnPlane.def("D3", (void (ProjLib_ProjectOnPlane::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &ProjLib_ProjectOnPlane::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_ProjLib_ProjectOnPlane.def("DN", (gp_Vec (ProjLib_ProjectOnPlane::*)(const Standard_Real, const Standard_Integer) const ) &ProjLib_ProjectOnPlane::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_ProjLib_ProjectOnPlane.def("Resolution", (Standard_Real (ProjLib_ProjectOnPlane::*)(const Standard_Real) const ) &ProjLib_ProjectOnPlane::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
	cls_ProjLib_ProjectOnPlane.def("GetType", (GeomAbs_CurveType (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");
	cls_ProjLib_ProjectOnPlane.def("Line", (gp_Lin (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::Line, "None");
	cls_ProjLib_ProjectOnPlane.def("Circle", (gp_Circ (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::Circle, "None");
	cls_ProjLib_ProjectOnPlane.def("Ellipse", (gp_Elips (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::Ellipse, "None");
	cls_ProjLib_ProjectOnPlane.def("Hyperbola", (gp_Hypr (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::Hyperbola, "None");
	cls_ProjLib_ProjectOnPlane.def("Parabola", (gp_Parab (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::Parabola, "None");
	cls_ProjLib_ProjectOnPlane.def("Degree", (Standard_Integer (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::Degree, "None");
	cls_ProjLib_ProjectOnPlane.def("IsRational", (Standard_Boolean (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::IsRational, "None");
	cls_ProjLib_ProjectOnPlane.def("NbPoles", (Standard_Integer (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::NbPoles, "None");
	cls_ProjLib_ProjectOnPlane.def("NbKnots", (Standard_Integer (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::NbKnots, "None");
	cls_ProjLib_ProjectOnPlane.def("Bezier", (opencascade::handle<Geom_BezierCurve> (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::Bezier, "Warning ! this will NOT make a copy of the Bezier Curve : If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");
	cls_ProjLib_ProjectOnPlane.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (ProjLib_ProjectOnPlane::*)() const ) &ProjLib_ProjectOnPlane::BSpline, "Warning ! this will NOT make a copy of the BSpline Curve : If you want to modify the Curve please make a copy yourself Also it will NOT trim the surface to myFirst/Last.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_ProjectOnSurface.hxx
	py::class_<ProjLib_ProjectOnSurface, std::unique_ptr<ProjLib_ProjectOnSurface, Deleter<ProjLib_ProjectOnSurface>>> cls_ProjLib_ProjectOnSurface(mod, "ProjLib_ProjectOnSurface", "Project a curve on a surface. The result ( a 3D Curve) will be an approximation");
	cls_ProjLib_ProjectOnSurface.def(py::init<>());
	cls_ProjLib_ProjectOnSurface.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S"));
	cls_ProjLib_ProjectOnSurface.def("Load", (void (ProjLib_ProjectOnSurface::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ProjectOnSurface::Load, "Set the Surface to <S>. To compute the projection, you have to Load the Curve.", py::arg("S"));
	cls_ProjLib_ProjectOnSurface.def("Load", (void (ProjLib_ProjectOnSurface::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &ProjLib_ProjectOnSurface::Load, "Compute the projection of the curve <C> on the Surface.", py::arg("C"), py::arg("Tolerance"));
	cls_ProjLib_ProjectOnSurface.def("IsDone", (Standard_Boolean (ProjLib_ProjectOnSurface::*)() const ) &ProjLib_ProjectOnSurface::IsDone, "None");
	cls_ProjLib_ProjectOnSurface.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (ProjLib_ProjectOnSurface::*)() const ) &ProjLib_ProjectOnSurface::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_ComputeApprox.hxx
	py::class_<ProjLib_ComputeApprox, std::unique_ptr<ProjLib_ComputeApprox, Deleter<ProjLib_ComputeApprox>>> cls_ProjLib_ComputeApprox(mod, "ProjLib_ComputeApprox", "Approximate the projection of a 3d curve on an analytic surface and stores the result in Approx. The result is a 2d curve.");
	cls_ProjLib_ComputeApprox.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("Tol"));
	cls_ProjLib_ComputeApprox.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ComputeApprox::*)() const ) &ProjLib_ComputeApprox::BSpline, "None");
	cls_ProjLib_ComputeApprox.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (ProjLib_ComputeApprox::*)() const ) &ProjLib_ComputeApprox::Bezier, "None");
	cls_ProjLib_ComputeApprox.def("Tolerance", (Standard_Real (ProjLib_ComputeApprox::*)() const ) &ProjLib_ComputeApprox::Tolerance, "returns the reached Tolerance.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_ComputeApproxOnPolarSurface.hxx
	py::class_<ProjLib_ComputeApproxOnPolarSurface, std::unique_ptr<ProjLib_ComputeApproxOnPolarSurface, Deleter<ProjLib_ComputeApproxOnPolarSurface>>> cls_ProjLib_ComputeApproxOnPolarSurface(mod, "ProjLib_ComputeApproxOnPolarSurface", "Approximate the projection of a 3d curve on an polar surface and stores the result in Approx. The result is a 2d curve. The evaluation of the current point of the 2d curve is done with the evaluation of the extrema P3d - Surface.");
	cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<>());
	cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("C"), py::arg("S"));
	cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("Tol"));
	cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("InitCurve2d"), py::arg("C"), py::arg("S"), py::arg("Tol"));
	cls_ProjLib_ComputeApproxOnPolarSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("InitCurve2d"), py::arg("InitCurve2dBis"), py::arg("C"), py::arg("S"), py::arg("Tol"));
	cls_ProjLib_ComputeApproxOnPolarSurface.def("Perform", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ComputeApproxOnPolarSurface::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ComputeApproxOnPolarSurface::Perform, "None", py::arg("InitCurve2d"), py::arg("C"), py::arg("S"));
	cls_ProjLib_ComputeApproxOnPolarSurface.def("BuildInitialCurve2d", (opencascade::handle<Adaptor2d_HCurve2d> (ProjLib_ComputeApproxOnPolarSurface::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ComputeApproxOnPolarSurface::BuildInitialCurve2d, "None", py::arg("Curve"), py::arg("S"));
	cls_ProjLib_ComputeApproxOnPolarSurface.def("ProjectUsingInitialCurve2d", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ComputeApproxOnPolarSurface::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &ProjLib_ComputeApproxOnPolarSurface::ProjectUsingInitialCurve2d, "None", py::arg("Curve"), py::arg("S"), py::arg("InitCurve2d"));
	cls_ProjLib_ComputeApproxOnPolarSurface.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_ComputeApproxOnPolarSurface::*)() const ) &ProjLib_ComputeApproxOnPolarSurface::BSpline, "None");
	cls_ProjLib_ComputeApproxOnPolarSurface.def("Curve2d", (opencascade::handle<Geom2d_Curve> (ProjLib_ComputeApproxOnPolarSurface::*)() const ) &ProjLib_ComputeApproxOnPolarSurface::Curve2d, "None");
	cls_ProjLib_ComputeApproxOnPolarSurface.def("IsDone", (Standard_Boolean (ProjLib_ComputeApproxOnPolarSurface::*)() const ) &ProjLib_ComputeApproxOnPolarSurface::IsDone, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_HProjectedCurve.hxx
	py::class_<ProjLib_HProjectedCurve, opencascade::handle<ProjLib_HProjectedCurve>, Adaptor2d_HCurve2d> cls_ProjLib_HProjectedCurve(mod, "ProjLib_HProjectedCurve", "None");
	cls_ProjLib_HProjectedCurve.def(py::init<>());
	cls_ProjLib_HProjectedCurve.def(py::init<const ProjLib_ProjectedCurve &>(), py::arg("C"));
	cls_ProjLib_HProjectedCurve.def("Set", (void (ProjLib_HProjectedCurve::*)(const ProjLib_ProjectedCurve &)) &ProjLib_HProjectedCurve::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
	cls_ProjLib_HProjectedCurve.def("Curve2d", (const Adaptor2d_Curve2d & (ProjLib_HProjectedCurve::*)() const ) &ProjLib_HProjectedCurve::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
	cls_ProjLib_HProjectedCurve.def("ChangeCurve2d", (ProjLib_ProjectedCurve & (ProjLib_HProjectedCurve::*)()) &ProjLib_HProjectedCurve::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
	cls_ProjLib_HProjectedCurve.def_static("get_type_name_", (const char * (*)()) &ProjLib_HProjectedCurve::get_type_name, "None");
	cls_ProjLib_HProjectedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ProjLib_HProjectedCurve::get_type_descriptor, "None");
	cls_ProjLib_HProjectedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (ProjLib_HProjectedCurve::*)() const ) &ProjLib_HProjectedCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_CompProjectedCurve.hxx
	py::class_<ProjLib_CompProjectedCurve, std::unique_ptr<ProjLib_CompProjectedCurve, Deleter<ProjLib_CompProjectedCurve>>, Adaptor2d_Curve2d> cls_ProjLib_CompProjectedCurve(mod, "ProjLib_CompProjectedCurve", "None");
	cls_ProjLib_CompProjectedCurve.def(py::init<>());
	cls_ProjLib_CompProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("C"), py::arg("TolU"), py::arg("TolV"));
	cls_ProjLib_CompProjectedCurve.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("C"), py::arg("TolU"), py::arg("TolV"), py::arg("MaxDist"));
	cls_ProjLib_CompProjectedCurve.def("Init", (void (ProjLib_CompProjectedCurve::*)()) &ProjLib_CompProjectedCurve::Init, "computes a set of projected point and determine the continuous parts of the projected curves. The points corresponding to a projection on the bounds of the surface are included in this set of points.");
	cls_ProjLib_CompProjectedCurve.def("Load", (void (ProjLib_CompProjectedCurve::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_CompProjectedCurve::Load, "Changes the surface.", py::arg("S"));
	cls_ProjLib_CompProjectedCurve.def("Load", (void (ProjLib_CompProjectedCurve::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &ProjLib_CompProjectedCurve::Load, "Changes the curve.", py::arg("C"));
	cls_ProjLib_CompProjectedCurve.def("GetSurface", (const opencascade::handle<Adaptor3d_HSurface> & (ProjLib_CompProjectedCurve::*)() const ) &ProjLib_CompProjectedCurve::GetSurface, "None");
	cls_ProjLib_CompProjectedCurve.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (ProjLib_CompProjectedCurve::*)() const ) &ProjLib_CompProjectedCurve::GetCurve, "None");
	cls_ProjLib_CompProjectedCurve.def("GetTolerance", (void (ProjLib_CompProjectedCurve::*)(Standard_Real &, Standard_Real &) const ) &ProjLib_CompProjectedCurve::GetTolerance, "None", py::arg("TolU"), py::arg("TolV"));
	cls_ProjLib_CompProjectedCurve.def("NbCurves", (Standard_Integer (ProjLib_CompProjectedCurve::*)() const ) &ProjLib_CompProjectedCurve::NbCurves, "returns the number of continuous part of the projected curve");
	cls_ProjLib_CompProjectedCurve.def("Bounds", (void (ProjLib_CompProjectedCurve::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &ProjLib_CompProjectedCurve::Bounds, "returns the bounds of the continuous part corresponding to Index", py::arg("Index"), py::arg("Udeb"), py::arg("Ufin"));
	cls_ProjLib_CompProjectedCurve.def("IsSinglePnt", (Standard_Boolean (ProjLib_CompProjectedCurve::*)(const Standard_Integer, gp_Pnt2d &) const ) &ProjLib_CompProjectedCurve::IsSinglePnt, "returns True if part of projection with number Index is a single point and writes its coordinates in P", py::arg("Index"), py::arg("P"));
	cls_ProjLib_CompProjectedCurve.def("IsUIso", (Standard_Boolean (ProjLib_CompProjectedCurve::*)(const Standard_Integer, Standard_Real &) const ) &ProjLib_CompProjectedCurve::IsUIso, "returns True if part of projection with number Index is an u-isoparametric curve of input surface", py::arg("Index"), py::arg("U"));
	cls_ProjLib_CompProjectedCurve.def("IsVIso", (Standard_Boolean (ProjLib_CompProjectedCurve::*)(const Standard_Integer, Standard_Real &) const ) &ProjLib_CompProjectedCurve::IsVIso, "returns True if part of projection with number Index is an v-isoparametric curve of input surface", py::arg("Index"), py::arg("V"));
	cls_ProjLib_CompProjectedCurve.def("Value", (gp_Pnt2d (ProjLib_CompProjectedCurve::*)(const Standard_Real) const ) &ProjLib_CompProjectedCurve::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
	cls_ProjLib_CompProjectedCurve.def("D0", (void (ProjLib_CompProjectedCurve::*)(const Standard_Real, gp_Pnt2d &) const ) &ProjLib_CompProjectedCurve::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
	cls_ProjLib_CompProjectedCurve.def("D1", (void (ProjLib_CompProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &ProjLib_CompProjectedCurve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_ProjLib_CompProjectedCurve.def("D2", (void (ProjLib_CompProjectedCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &ProjLib_CompProjectedCurve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_ProjLib_CompProjectedCurve.def("DN", (gp_Vec2d (ProjLib_CompProjectedCurve::*)(const Standard_Real, const Standard_Integer) const ) &ProjLib_CompProjectedCurve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if N < 1. Raised if N > 2.", py::arg("U"), py::arg("N"));
	cls_ProjLib_CompProjectedCurve.def("FirstParameter", (Standard_Real (ProjLib_CompProjectedCurve::*)() const ) &ProjLib_CompProjectedCurve::FirstParameter, "Returns the first parameter of the curve C which has a projection on S.");
	cls_ProjLib_CompProjectedCurve.def("LastParameter", (Standard_Real (ProjLib_CompProjectedCurve::*)() const ) &ProjLib_CompProjectedCurve::LastParameter, "Returns the last parameter of the curve C which has a projection on S.");
	cls_ProjLib_CompProjectedCurve.def("NbIntervals", (Standard_Integer (ProjLib_CompProjectedCurve::*)(const GeomAbs_Shape) const ) &ProjLib_CompProjectedCurve::NbIntervals, "Returns the number of intervals which define an S continuous part of the projected curve", py::arg("S"));
	cls_ProjLib_CompProjectedCurve.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (ProjLib_CompProjectedCurve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &ProjLib_CompProjectedCurve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 2d points confusion. If <First> >= <Last>", py::arg("FirstParam"), py::arg("LastParam"), py::arg("Tol"));
	cls_ProjLib_CompProjectedCurve.def("Intervals", (void (ProjLib_CompProjectedCurve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &ProjLib_CompProjectedCurve::Intervals, "Returns the parameters corresponding to S discontinuities.", py::arg("T"), py::arg("S"));
	cls_ProjLib_CompProjectedCurve.def("MaxDistance", (Standard_Real (ProjLib_CompProjectedCurve::*)(const Standard_Integer) const ) &ProjLib_CompProjectedCurve::MaxDistance, "returns the maximum distance between curve to project and surface", py::arg("Index"));
	cls_ProjLib_CompProjectedCurve.def("GetSequence", (const opencascade::handle<ProjLib_HSequenceOfHSequenceOfPnt> & (ProjLib_CompProjectedCurve::*)() const ) &ProjLib_CompProjectedCurve::GetSequence, "None");
	cls_ProjLib_CompProjectedCurve.def("GetType", (GeomAbs_CurveType (ProjLib_CompProjectedCurve::*)() const ) &ProjLib_CompProjectedCurve::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_HCompProjectedCurve.hxx
	py::class_<ProjLib_HCompProjectedCurve, opencascade::handle<ProjLib_HCompProjectedCurve>, Adaptor2d_HCurve2d> cls_ProjLib_HCompProjectedCurve(mod, "ProjLib_HCompProjectedCurve", "None");
	cls_ProjLib_HCompProjectedCurve.def(py::init<>());
	cls_ProjLib_HCompProjectedCurve.def(py::init<const ProjLib_CompProjectedCurve &>(), py::arg("C"));
	cls_ProjLib_HCompProjectedCurve.def("Set", (void (ProjLib_HCompProjectedCurve::*)(const ProjLib_CompProjectedCurve &)) &ProjLib_HCompProjectedCurve::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
	cls_ProjLib_HCompProjectedCurve.def("Curve2d", (const Adaptor2d_Curve2d & (ProjLib_HCompProjectedCurve::*)() const ) &ProjLib_HCompProjectedCurve::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
	cls_ProjLib_HCompProjectedCurve.def("ChangeCurve2d", (ProjLib_CompProjectedCurve & (ProjLib_HCompProjectedCurve::*)()) &ProjLib_HCompProjectedCurve::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
	cls_ProjLib_HCompProjectedCurve.def_static("get_type_name_", (const char * (*)()) &ProjLib_HCompProjectedCurve::get_type_name, "None");
	cls_ProjLib_HCompProjectedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ProjLib_HCompProjectedCurve::get_type_descriptor, "None");
	cls_ProjLib_HCompProjectedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (ProjLib_HCompProjectedCurve::*)() const ) &ProjLib_HCompProjectedCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_PrjResolve.hxx
	py::class_<ProjLib_PrjResolve, std::unique_ptr<ProjLib_PrjResolve, Deleter<ProjLib_PrjResolve>>> cls_ProjLib_PrjResolve(mod, "ProjLib_PrjResolve", "None");
	cls_ProjLib_PrjResolve.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Integer>(), py::arg("C"), py::arg("S"), py::arg("Fix"));
	cls_ProjLib_PrjResolve.def("Perform", [](ProjLib_PrjResolve &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const gp_Pnt2d & a3, const gp_Pnt2d & a4, const gp_Pnt2d & a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); }, py::arg("t"), py::arg("U"), py::arg("V"), py::arg("Tol"), py::arg("Inf"), py::arg("Sup"));
	cls_ProjLib_PrjResolve.def("Perform", [](ProjLib_PrjResolve &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const gp_Pnt2d & a3, const gp_Pnt2d & a4, const gp_Pnt2d & a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("t"), py::arg("U"), py::arg("V"), py::arg("Tol"), py::arg("Inf"), py::arg("Sup"), py::arg("FTol"));
	cls_ProjLib_PrjResolve.def("Perform", (void (ProjLib_PrjResolve::*)(const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &ProjLib_PrjResolve::Perform, "Calculates the ort from C(t) to S with a close point. The close point is defined by the parameter values U0 and V0. The function F(u,v)=distance(S(u,v),C(t)) has an extremum when gradient(F)=0. The algorithm searchs a zero near the close point.", py::arg("t"), py::arg("U"), py::arg("V"), py::arg("Tol"), py::arg("Inf"), py::arg("Sup"), py::arg("FTol"), py::arg("StrictInside"));
	cls_ProjLib_PrjResolve.def("IsDone", (Standard_Boolean (ProjLib_PrjResolve::*)() const ) &ProjLib_PrjResolve::IsDone, "Returns True if the distance is found.");
	cls_ProjLib_PrjResolve.def("Solution", (gp_Pnt2d (ProjLib_PrjResolve::*)() const ) &ProjLib_PrjResolve::Solution, "Returns the point of the extremum distance.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_PrjFunc.hxx
	py::class_<ProjLib_PrjFunc, std::unique_ptr<ProjLib_PrjFunc, Deleter<ProjLib_PrjFunc>>, math_FunctionSetWithDerivatives> cls_ProjLib_PrjFunc(mod, "ProjLib_PrjFunc", "None");
	cls_ProjLib_PrjFunc.def(py::init<const Adaptor3d_CurvePtr &, const Standard_Real, const Adaptor3d_SurfacePtr &, const Standard_Integer>(), py::arg("C"), py::arg("FixVal"), py::arg("S"), py::arg("Fix"));
	cls_ProjLib_PrjFunc.def("NbVariables", (Standard_Integer (ProjLib_PrjFunc::*)() const ) &ProjLib_PrjFunc::NbVariables, "returns the number of variables of the function.");
	cls_ProjLib_PrjFunc.def("NbEquations", (Standard_Integer (ProjLib_PrjFunc::*)() const ) &ProjLib_PrjFunc::NbEquations, "returns the number of equations of the function.");
	cls_ProjLib_PrjFunc.def("Value", (Standard_Boolean (ProjLib_PrjFunc::*)(const math_Vector &, math_Vector &)) &ProjLib_PrjFunc::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_ProjLib_PrjFunc.def("Derivatives", (Standard_Boolean (ProjLib_PrjFunc::*)(const math_Vector &, math_Matrix &)) &ProjLib_PrjFunc::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_ProjLib_PrjFunc.def("Values", (Standard_Boolean (ProjLib_PrjFunc::*)(const math_Vector &, math_Vector &, math_Matrix &)) &ProjLib_PrjFunc::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_ProjLib_PrjFunc.def("Solution", (gp_Pnt2d (ProjLib_PrjFunc::*)() const ) &ProjLib_PrjFunc::Solution, "returns point on surface");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_Projector.hxx
	py::class_<ProjLib_Projector, std::unique_ptr<ProjLib_Projector, Deleter<ProjLib_Projector>>> cls_ProjLib_Projector(mod, "ProjLib_Projector", "Root class for projection algorithms, stores the result.");
	cls_ProjLib_Projector.def(py::init<>());
	cls_ProjLib_Projector.def("IsDone", (Standard_Boolean (ProjLib_Projector::*)() const ) &ProjLib_Projector::IsDone, "None");
	cls_ProjLib_Projector.def("Done", (void (ProjLib_Projector::*)()) &ProjLib_Projector::Done, "Set isDone = Standard_True;");
	cls_ProjLib_Projector.def("GetType", (GeomAbs_CurveType (ProjLib_Projector::*)() const ) &ProjLib_Projector::GetType, "None");
	cls_ProjLib_Projector.def("SetBSpline", (void (ProjLib_Projector::*)(const opencascade::handle<Geom2d_BSplineCurve> &)) &ProjLib_Projector::SetBSpline, "None", py::arg("C"));
	cls_ProjLib_Projector.def("SetBezier", (void (ProjLib_Projector::*)(const opencascade::handle<Geom2d_BezierCurve> &)) &ProjLib_Projector::SetBezier, "None", py::arg("C"));
	cls_ProjLib_Projector.def("SetType", (void (ProjLib_Projector::*)(const GeomAbs_CurveType)) &ProjLib_Projector::SetType, "None", py::arg("Type"));
	cls_ProjLib_Projector.def("IsPeriodic", (Standard_Boolean (ProjLib_Projector::*)() const ) &ProjLib_Projector::IsPeriodic, "None");
	cls_ProjLib_Projector.def("SetPeriodic", (void (ProjLib_Projector::*)()) &ProjLib_Projector::SetPeriodic, "None");
	cls_ProjLib_Projector.def("Line", (const gp_Lin2d & (ProjLib_Projector::*)() const ) &ProjLib_Projector::Line, "None");
	cls_ProjLib_Projector.def("Circle", (const gp_Circ2d & (ProjLib_Projector::*)() const ) &ProjLib_Projector::Circle, "None");
	cls_ProjLib_Projector.def("Ellipse", (const gp_Elips2d & (ProjLib_Projector::*)() const ) &ProjLib_Projector::Ellipse, "None");
	cls_ProjLib_Projector.def("Hyperbola", (const gp_Hypr2d & (ProjLib_Projector::*)() const ) &ProjLib_Projector::Hyperbola, "None");
	cls_ProjLib_Projector.def("Parabola", (const gp_Parab2d & (ProjLib_Projector::*)() const ) &ProjLib_Projector::Parabola, "None");
	cls_ProjLib_Projector.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (ProjLib_Projector::*)() const ) &ProjLib_Projector::Bezier, "None");
	cls_ProjLib_Projector.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_Projector::*)() const ) &ProjLib_Projector::BSpline, "None");
	cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Lin &)) &ProjLib_Projector::Project, "None", py::arg("L"));
	cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Circ &)) &ProjLib_Projector::Project, "None", py::arg("C"));
	cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Elips &)) &ProjLib_Projector::Project, "None", py::arg("E"));
	cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Parab &)) &ProjLib_Projector::Project, "None", py::arg("P"));
	cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Hypr &)) &ProjLib_Projector::Project, "None", py::arg("H"));
	cls_ProjLib_Projector.def("UFrame", (void (ProjLib_Projector::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ProjLib_Projector::UFrame, "Translates the 2d curve to set the part of the curve [CFirst, CLast] in the range [ UFirst, UFirst + Period [", py::arg("CFirst"), py::arg("CLast"), py::arg("UFirst"), py::arg("Period"));
	cls_ProjLib_Projector.def("VFrame", (void (ProjLib_Projector::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ProjLib_Projector::VFrame, "Translates the 2d curve to set the part of the curve [CFirst, CLast] in the range [ VFirst, VFirst + Period [", py::arg("CFirst"), py::arg("CLast"), py::arg("VFirst"), py::arg("Period"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_Plane.hxx
	py::class_<ProjLib_Plane, std::unique_ptr<ProjLib_Plane, Deleter<ProjLib_Plane>>, ProjLib_Projector> cls_ProjLib_Plane(mod, "ProjLib_Plane", "Projects elementary curves on a plane.");
	cls_ProjLib_Plane.def(py::init<>());
	cls_ProjLib_Plane.def(py::init<const gp_Pln &>(), py::arg("Pl"));
	cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Lin &>(), py::arg("Pl"), py::arg("L"));
	cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Circ &>(), py::arg("Pl"), py::arg("C"));
	cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Elips &>(), py::arg("Pl"), py::arg("E"));
	cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Parab &>(), py::arg("Pl"), py::arg("P"));
	cls_ProjLib_Plane.def(py::init<const gp_Pln &, const gp_Hypr &>(), py::arg("Pl"), py::arg("H"));
	cls_ProjLib_Plane.def("Init", (void (ProjLib_Plane::*)(const gp_Pln &)) &ProjLib_Plane::Init, "None", py::arg("Pl"));
	cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Lin &)) &ProjLib_Plane::Project, "None", py::arg("L"));
	cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Circ &)) &ProjLib_Plane::Project, "None", py::arg("C"));
	cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Elips &)) &ProjLib_Plane::Project, "None", py::arg("E"));
	cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Parab &)) &ProjLib_Plane::Project, "None", py::arg("P"));
	cls_ProjLib_Plane.def("Project", (void (ProjLib_Plane::*)(const gp_Hypr &)) &ProjLib_Plane::Project, "None", py::arg("H"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_Cylinder.hxx
	py::class_<ProjLib_Cylinder, std::unique_ptr<ProjLib_Cylinder, Deleter<ProjLib_Cylinder>>, ProjLib_Projector> cls_ProjLib_Cylinder(mod, "ProjLib_Cylinder", "Projects elementary curves on a cylinder.");
	cls_ProjLib_Cylinder.def(py::init<>());
	cls_ProjLib_Cylinder.def(py::init<const gp_Cylinder &>(), py::arg("Cyl"));
	cls_ProjLib_Cylinder.def(py::init<const gp_Cylinder &, const gp_Lin &>(), py::arg("Cyl"), py::arg("L"));
	cls_ProjLib_Cylinder.def(py::init<const gp_Cylinder &, const gp_Circ &>(), py::arg("Cyl"), py::arg("C"));
	cls_ProjLib_Cylinder.def(py::init<const gp_Cylinder &, const gp_Elips &>(), py::arg("Cyl"), py::arg("E"));
	cls_ProjLib_Cylinder.def("Init", (void (ProjLib_Cylinder::*)(const gp_Cylinder &)) &ProjLib_Cylinder::Init, "None", py::arg("Cyl"));
	cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Lin &)) &ProjLib_Cylinder::Project, "None", py::arg("L"));
	cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Circ &)) &ProjLib_Cylinder::Project, "None", py::arg("C"));
	cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Elips &)) &ProjLib_Cylinder::Project, "None", py::arg("E"));
	cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Parab &)) &ProjLib_Cylinder::Project, "None", py::arg("P"));
	cls_ProjLib_Cylinder.def("Project", (void (ProjLib_Cylinder::*)(const gp_Hypr &)) &ProjLib_Cylinder::Project, "None", py::arg("H"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_Cone.hxx
	py::class_<ProjLib_Cone, std::unique_ptr<ProjLib_Cone, Deleter<ProjLib_Cone>>, ProjLib_Projector> cls_ProjLib_Cone(mod, "ProjLib_Cone", "Projects elementary curves on a cone.");
	cls_ProjLib_Cone.def(py::init<>());
	cls_ProjLib_Cone.def(py::init<const gp_Cone &>(), py::arg("Co"));
	cls_ProjLib_Cone.def(py::init<const gp_Cone &, const gp_Lin &>(), py::arg("Co"), py::arg("L"));
	cls_ProjLib_Cone.def(py::init<const gp_Cone &, const gp_Circ &>(), py::arg("Co"), py::arg("C"));
	cls_ProjLib_Cone.def("Init", (void (ProjLib_Cone::*)(const gp_Cone &)) &ProjLib_Cone::Init, "None", py::arg("Co"));
	cls_ProjLib_Cone.def("Project", (void (ProjLib_Cone::*)(const gp_Lin &)) &ProjLib_Cone::Project, "None", py::arg("L"));
	cls_ProjLib_Cone.def("Project", (void (ProjLib_Cone::*)(const gp_Circ &)) &ProjLib_Cone::Project, "None", py::arg("C"));
	cls_ProjLib_Cone.def("Project", (void (ProjLib_Cone::*)(const gp_Elips &)) &ProjLib_Cone::Project, "None", py::arg("E"));
	cls_ProjLib_Cone.def("Project", (void (ProjLib_Cone::*)(const gp_Parab &)) &ProjLib_Cone::Project, "None", py::arg("P"));
	cls_ProjLib_Cone.def("Project", (void (ProjLib_Cone::*)(const gp_Hypr &)) &ProjLib_Cone::Project, "None", py::arg("H"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_Sphere.hxx
	py::class_<ProjLib_Sphere, std::unique_ptr<ProjLib_Sphere, Deleter<ProjLib_Sphere>>, ProjLib_Projector> cls_ProjLib_Sphere(mod, "ProjLib_Sphere", "Projects elementary curves on a sphere.");
	cls_ProjLib_Sphere.def(py::init<>());
	cls_ProjLib_Sphere.def(py::init<const gp_Sphere &>(), py::arg("Sp"));
	cls_ProjLib_Sphere.def(py::init<const gp_Sphere &, const gp_Circ &>(), py::arg("Sp"), py::arg("C"));
	cls_ProjLib_Sphere.def("Init", (void (ProjLib_Sphere::*)(const gp_Sphere &)) &ProjLib_Sphere::Init, "None", py::arg("Sp"));
	cls_ProjLib_Sphere.def("Project", (void (ProjLib_Sphere::*)(const gp_Lin &)) &ProjLib_Sphere::Project, "None", py::arg("L"));
	cls_ProjLib_Sphere.def("Project", (void (ProjLib_Sphere::*)(const gp_Circ &)) &ProjLib_Sphere::Project, "None", py::arg("C"));
	cls_ProjLib_Sphere.def("Project", (void (ProjLib_Sphere::*)(const gp_Elips &)) &ProjLib_Sphere::Project, "None", py::arg("E"));
	cls_ProjLib_Sphere.def("Project", (void (ProjLib_Sphere::*)(const gp_Parab &)) &ProjLib_Sphere::Project, "None", py::arg("P"));
	cls_ProjLib_Sphere.def("Project", (void (ProjLib_Sphere::*)(const gp_Hypr &)) &ProjLib_Sphere::Project, "None", py::arg("H"));
	cls_ProjLib_Sphere.def("SetInBounds", (void (ProjLib_Sphere::*)(const Standard_Real)) &ProjLib_Sphere::SetInBounds, "Set the point of parameter U on C in the natural restrictions of the sphere.", py::arg("U"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_Torus.hxx
	py::class_<ProjLib_Torus, std::unique_ptr<ProjLib_Torus, Deleter<ProjLib_Torus>>, ProjLib_Projector> cls_ProjLib_Torus(mod, "ProjLib_Torus", "Projects elementary curves on a torus.");
	cls_ProjLib_Torus.def(py::init<>());
	cls_ProjLib_Torus.def(py::init<const gp_Torus &>(), py::arg("To"));
	cls_ProjLib_Torus.def(py::init<const gp_Torus &, const gp_Circ &>(), py::arg("To"), py::arg("C"));
	cls_ProjLib_Torus.def("Init", (void (ProjLib_Torus::*)(const gp_Torus &)) &ProjLib_Torus::Init, "None", py::arg("To"));
	cls_ProjLib_Torus.def("Project", (void (ProjLib_Torus::*)(const gp_Lin &)) &ProjLib_Torus::Project, "None", py::arg("L"));
	cls_ProjLib_Torus.def("Project", (void (ProjLib_Torus::*)(const gp_Circ &)) &ProjLib_Torus::Project, "None", py::arg("C"));
	cls_ProjLib_Torus.def("Project", (void (ProjLib_Torus::*)(const gp_Elips &)) &ProjLib_Torus::Project, "None", py::arg("E"));
	cls_ProjLib_Torus.def("Project", (void (ProjLib_Torus::*)(const gp_Parab &)) &ProjLib_Torus::Project, "None", py::arg("P"));
	cls_ProjLib_Torus.def("Project", (void (ProjLib_Torus::*)(const gp_Hypr &)) &ProjLib_Torus::Project, "None", py::arg("H"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib.hxx
	py::class_<ProjLib, std::unique_ptr<ProjLib, Deleter<ProjLib>>> cls_ProjLib(mod, "ProjLib", "The projLib package first provides projection of curves on a plane along a given Direction. The result will be a 3D curve. The ProjLib package provides projection of curves on surfaces to compute the curve in the parametric space.");
	cls_ProjLib.def(py::init<>());
	cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Pln &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("P"));
	cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Pln &, const gp_Lin &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("L"));
	cls_ProjLib.def_static("Project_", (gp_Circ2d (*)(const gp_Pln &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("C"));
	cls_ProjLib.def_static("Project_", (gp_Elips2d (*)(const gp_Pln &, const gp_Elips &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("E"));
	cls_ProjLib.def_static("Project_", (gp_Parab2d (*)(const gp_Pln &, const gp_Parab &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("P"));
	cls_ProjLib.def_static("Project_", (gp_Hypr2d (*)(const gp_Pln &, const gp_Hypr &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("H"));
	cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Cylinder &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("Cy"), py::arg("P"));
	cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Cylinder &, const gp_Lin &)) &ProjLib::Project, "None", py::arg("Cy"), py::arg("L"));
	cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Cylinder &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("Cy"), py::arg("Ci"));
	cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Cone &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("Co"), py::arg("P"));
	cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Cone &, const gp_Lin &)) &ProjLib::Project, "None", py::arg("Co"), py::arg("L"));
	cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Cone &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("Co"), py::arg("Ci"));
	cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Sphere &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("Sp"), py::arg("P"));
	cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Sphere &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("Sp"), py::arg("Ci"));
	cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Torus &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("To"), py::arg("P"));
	cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Torus &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("To"), py::arg("Ci"));
	cls_ProjLib.def_static("MakePCurveOfType_", (void (*)(const ProjLib_ProjectedCurve &, opencascade::handle<Geom2d_Curve> &)) &ProjLib::MakePCurveOfType, "Make empty P-Curve <aC> of relevant to <PC> type", py::arg("PC"), py::arg("aC"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<ProjLib_SequenceOfHSequenceOfPnt, std::unique_ptr<ProjLib_SequenceOfHSequenceOfPnt, Deleter<ProjLib_SequenceOfHSequenceOfPnt>>, NCollection_BaseSequence> cls_ProjLib_SequenceOfHSequenceOfPnt(mod, "ProjLib_SequenceOfHSequenceOfPnt", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def(py::init<>());
	cls_ProjLib_SequenceOfHSequenceOfPnt.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def(py::init([] (const ProjLib_SequenceOfHSequenceOfPnt &other) {return new ProjLib_SequenceOfHSequenceOfPnt(other);}), "Copy constructor", py::arg("other"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("begin", (ProjLib_SequenceOfHSequenceOfPnt::iterator (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("end", (ProjLib_SequenceOfHSequenceOfPnt::iterator (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("cbegin", (ProjLib_SequenceOfHSequenceOfPnt::const_iterator (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("cend", (ProjLib_SequenceOfHSequenceOfPnt::const_iterator (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Size", (Standard_Integer (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::Size, "Number of items");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Length", (Standard_Integer (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::Length, "Number of items");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Lower", (Standard_Integer (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::Lower, "Method for consistency with other collections.");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Upper", (Standard_Integer (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::Upper, "Method for consistency with other collections.");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("IsEmpty", (Standard_Boolean (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::IsEmpty, "Empty query");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Reverse", (void (ProjLib_SequenceOfHSequenceOfPnt::*)()) &ProjLib_SequenceOfHSequenceOfPnt::Reverse, "Reverse sequence");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Exchange", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer, const Standard_Integer)) &ProjLib_SequenceOfHSequenceOfPnt::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &ProjLib_SequenceOfHSequenceOfPnt::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Clear", [](ProjLib_SequenceOfHSequenceOfPnt &self) -> void { return self.Clear(); });
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Clear", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &ProjLib_SequenceOfHSequenceOfPnt::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Assign", (ProjLib_SequenceOfHSequenceOfPnt & (ProjLib_SequenceOfHSequenceOfPnt::*)(const ProjLib_SequenceOfHSequenceOfPnt &)) &ProjLib_SequenceOfHSequenceOfPnt::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("assign", (ProjLib_SequenceOfHSequenceOfPnt & (ProjLib_SequenceOfHSequenceOfPnt::*)(const ProjLib_SequenceOfHSequenceOfPnt &)) &ProjLib_SequenceOfHSequenceOfPnt::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Remove", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(ProjLib_SequenceOfHSequenceOfPnt::Iterator &)) &ProjLib_SequenceOfHSequenceOfPnt::Remove, "Remove one item", py::arg("thePosition"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Remove", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer)) &ProjLib_SequenceOfHSequenceOfPnt::Remove, "Remove one item", py::arg("theIndex"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Remove", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer, const Standard_Integer)) &ProjLib_SequenceOfHSequenceOfPnt::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Append", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const opencascade::handle<TColgp_HSequenceOfPnt> &)) &ProjLib_SequenceOfHSequenceOfPnt::Append, "Append one item", py::arg("theItem"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Append", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(ProjLib_SequenceOfHSequenceOfPnt &)) &ProjLib_SequenceOfHSequenceOfPnt::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Prepend", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const opencascade::handle<TColgp_HSequenceOfPnt> &)) &ProjLib_SequenceOfHSequenceOfPnt::Prepend, "Prepend one item", py::arg("theItem"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Prepend", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(ProjLib_SequenceOfHSequenceOfPnt &)) &ProjLib_SequenceOfHSequenceOfPnt::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("InsertBefore", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer, const opencascade::handle<TColgp_HSequenceOfPnt> &)) &ProjLib_SequenceOfHSequenceOfPnt::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("InsertBefore", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer, ProjLib_SequenceOfHSequenceOfPnt &)) &ProjLib_SequenceOfHSequenceOfPnt::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("InsertAfter", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(ProjLib_SequenceOfHSequenceOfPnt::Iterator &, const opencascade::handle<TColgp_HSequenceOfPnt> &)) &ProjLib_SequenceOfHSequenceOfPnt::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("InsertAfter", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer, ProjLib_SequenceOfHSequenceOfPnt &)) &ProjLib_SequenceOfHSequenceOfPnt::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("InsertAfter", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer, const opencascade::handle<TColgp_HSequenceOfPnt> &)) &ProjLib_SequenceOfHSequenceOfPnt::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Split", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer, ProjLib_SequenceOfHSequenceOfPnt &)) &ProjLib_SequenceOfHSequenceOfPnt::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("First", (const opencascade::handle<TColgp_HSequenceOfPnt> & (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::First, "First item access");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("ChangeFirst", (opencascade::handle<TColgp_HSequenceOfPnt> & (ProjLib_SequenceOfHSequenceOfPnt::*)()) &ProjLib_SequenceOfHSequenceOfPnt::ChangeFirst, "First item access");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Last", (const opencascade::handle<TColgp_HSequenceOfPnt> & (ProjLib_SequenceOfHSequenceOfPnt::*)() const ) &ProjLib_SequenceOfHSequenceOfPnt::Last, "Last item access");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("ChangeLast", (opencascade::handle<TColgp_HSequenceOfPnt> & (ProjLib_SequenceOfHSequenceOfPnt::*)()) &ProjLib_SequenceOfHSequenceOfPnt::ChangeLast, "Last item access");
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("Value", (const opencascade::handle<TColgp_HSequenceOfPnt> & (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer) const ) &ProjLib_SequenceOfHSequenceOfPnt::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("__call__", (const opencascade::handle<TColgp_HSequenceOfPnt> & (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer) const ) &ProjLib_SequenceOfHSequenceOfPnt::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("ChangeValue", (opencascade::handle<TColgp_HSequenceOfPnt> & (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer)) &ProjLib_SequenceOfHSequenceOfPnt::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("__call__", (opencascade::handle<TColgp_HSequenceOfPnt> & (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer)) &ProjLib_SequenceOfHSequenceOfPnt::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("SetValue", (void (ProjLib_SequenceOfHSequenceOfPnt::*)(const Standard_Integer, const opencascade::handle<TColgp_HSequenceOfPnt> &)) &ProjLib_SequenceOfHSequenceOfPnt::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_ProjLib_SequenceOfHSequenceOfPnt.def("__iter__", [](const ProjLib_SequenceOfHSequenceOfPnt &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\ProjLib_HSequenceOfHSequenceOfPnt.hxx
	py::class_<ProjLib_HSequenceOfHSequenceOfPnt, opencascade::handle<ProjLib_HSequenceOfHSequenceOfPnt>, ProjLib_SequenceOfHSequenceOfPnt, Standard_Transient> cls_ProjLib_HSequenceOfHSequenceOfPnt(mod, "ProjLib_HSequenceOfHSequenceOfPnt", "None");
	cls_ProjLib_HSequenceOfHSequenceOfPnt.def(py::init<>());
	cls_ProjLib_HSequenceOfHSequenceOfPnt.def(py::init<const ProjLib_SequenceOfHSequenceOfPnt &>(), py::arg("theOther"));
	cls_ProjLib_HSequenceOfHSequenceOfPnt.def("Sequence", (const ProjLib_SequenceOfHSequenceOfPnt & (ProjLib_HSequenceOfHSequenceOfPnt::*)() const ) &ProjLib_HSequenceOfHSequenceOfPnt::Sequence, "None");
	cls_ProjLib_HSequenceOfHSequenceOfPnt.def("Append", (void (ProjLib_HSequenceOfHSequenceOfPnt::*)(const ProjLib_SequenceOfHSequenceOfPnt::value_type &)) &ProjLib_HSequenceOfHSequenceOfPnt::Append, "None", py::arg("theItem"));
	cls_ProjLib_HSequenceOfHSequenceOfPnt.def("Append", (void (ProjLib_HSequenceOfHSequenceOfPnt::*)(ProjLib_SequenceOfHSequenceOfPnt &)) &ProjLib_HSequenceOfHSequenceOfPnt::Append, "None", py::arg("theSequence"));
	cls_ProjLib_HSequenceOfHSequenceOfPnt.def("ChangeSequence", (ProjLib_SequenceOfHSequenceOfPnt & (ProjLib_HSequenceOfHSequenceOfPnt::*)()) &ProjLib_HSequenceOfHSequenceOfPnt::ChangeSequence, "None");
	cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("get_type_name_", (const char * (*)()) &ProjLib_HSequenceOfHSequenceOfPnt::get_type_name, "None");
	cls_ProjLib_HSequenceOfHSequenceOfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ProjLib_HSequenceOfHSequenceOfPnt::get_type_descriptor, "None");
	cls_ProjLib_HSequenceOfHSequenceOfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (ProjLib_HSequenceOfHSequenceOfPnt::*)() const ) &ProjLib_HSequenceOfHSequenceOfPnt::DynamicType, "None");


}
