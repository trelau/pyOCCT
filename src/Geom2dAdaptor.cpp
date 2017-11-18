#include <pyOCCT_Common.hpp>

#include <Adaptor2d_Curve2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
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
#include <Geom2dAdaptor_Curve.hxx>
#include <Geom2dAdaptor_GHCurve.hxx>
#include <Standard_Type.hxx>
#include <Geom2dAdaptor_HCurve.hxx>
#include <Geom2dAdaptor.hxx>

PYBIND11_MODULE(Geom2dAdaptor, mod) {

	// IMPORT
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dAdaptor_Curve.hxx
	py::class_<Geom2dAdaptor_Curve, std::unique_ptr<Geom2dAdaptor_Curve, Deleter<Geom2dAdaptor_Curve>>, Adaptor2d_Curve2d> cls_Geom2dAdaptor_Curve(mod, "Geom2dAdaptor_Curve", "An interface between the services provided by any curve from the package Geom2d and those required of the curve by algorithms which use it.");
	cls_Geom2dAdaptor_Curve.def(py::init<>());
	cls_Geom2dAdaptor_Curve.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("C"));
	cls_Geom2dAdaptor_Curve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("UFirst"), py::arg("ULast"));
	cls_Geom2dAdaptor_Curve.def("Load", (void (Geom2dAdaptor_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dAdaptor_Curve::Load, "None", py::arg("C"));
	cls_Geom2dAdaptor_Curve.def("Load", (void (Geom2dAdaptor_Curve::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &Geom2dAdaptor_Curve::Load, "ConstructionError is raised if Ufirst>Ulast", py::arg("C"), py::arg("UFirst"), py::arg("ULast"));
	cls_Geom2dAdaptor_Curve.def("Curve", (const opencascade::handle<Geom2d_Curve> & (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Curve, "None");
	cls_Geom2dAdaptor_Curve.def("FirstParameter", (Standard_Real (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::FirstParameter, "None");
	cls_Geom2dAdaptor_Curve.def("LastParameter", (Standard_Real (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::LastParameter, "None");
	cls_Geom2dAdaptor_Curve.def("Continuity", (GeomAbs_Shape (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Continuity, "None");
	cls_Geom2dAdaptor_Curve.def("NbIntervals", (Standard_Integer (Geom2dAdaptor_Curve::*)(const GeomAbs_Shape) const ) &Geom2dAdaptor_Curve::NbIntervals, "If necessary, breaks the curve in intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
	cls_Geom2dAdaptor_Curve.def("Intervals", (void (Geom2dAdaptor_Curve::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Geom2dAdaptor_Curve::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Geom2dAdaptor_Curve.def("Trim", (opencascade::handle<Adaptor2d_HCurve2d> (Geom2dAdaptor_Curve::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Geom2dAdaptor_Curve::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. If <First> >= <Last>", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Geom2dAdaptor_Curve.def("IsClosed", (Standard_Boolean (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::IsClosed, "None");
	cls_Geom2dAdaptor_Curve.def("IsPeriodic", (Standard_Boolean (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::IsPeriodic, "None");
	cls_Geom2dAdaptor_Curve.def("Period", (Standard_Real (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Period, "None");
	cls_Geom2dAdaptor_Curve.def("Value", (gp_Pnt2d (Geom2dAdaptor_Curve::*)(const Standard_Real) const ) &Geom2dAdaptor_Curve::Value, "Computes the point of parameter U on the curve", py::arg("U"));
	cls_Geom2dAdaptor_Curve.def("D0", (void (Geom2dAdaptor_Curve::*)(const Standard_Real, gp_Pnt2d &) const ) &Geom2dAdaptor_Curve::D0, "Computes the point of parameter U.", py::arg("U"), py::arg("P"));
	cls_Geom2dAdaptor_Curve.def("D1", (void (Geom2dAdaptor_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &Geom2dAdaptor_Curve::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Geom2dAdaptor_Curve.def("D2", (void (Geom2dAdaptor_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &Geom2dAdaptor_Curve::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Geom2dAdaptor_Curve.def("D3", (void (Geom2dAdaptor_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const ) &Geom2dAdaptor_Curve::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Geom2dAdaptor_Curve.def("DN", (gp_Vec2d (Geom2dAdaptor_Curve::*)(const Standard_Real, const Standard_Integer) const ) &Geom2dAdaptor_Curve::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("U"), py::arg("N"));
	cls_Geom2dAdaptor_Curve.def("Resolution", (Standard_Real (Geom2dAdaptor_Curve::*)(const Standard_Real) const ) &Geom2dAdaptor_Curve::Resolution, "returns the parametric resolution", py::arg("Ruv"));
	cls_Geom2dAdaptor_Curve.def("GetType", (GeomAbs_CurveType (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::GetType, "None");
	cls_Geom2dAdaptor_Curve.def("Line", (gp_Lin2d (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Line, "None");
	cls_Geom2dAdaptor_Curve.def("Circle", (gp_Circ2d (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Circle, "None");
	cls_Geom2dAdaptor_Curve.def("Ellipse", (gp_Elips2d (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Ellipse, "None");
	cls_Geom2dAdaptor_Curve.def("Hyperbola", (gp_Hypr2d (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Hyperbola, "None");
	cls_Geom2dAdaptor_Curve.def("Parabola", (gp_Parab2d (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Parabola, "None");
	cls_Geom2dAdaptor_Curve.def("Degree", (Standard_Integer (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Degree, "None");
	cls_Geom2dAdaptor_Curve.def("IsRational", (Standard_Boolean (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::IsRational, "None");
	cls_Geom2dAdaptor_Curve.def("NbPoles", (Standard_Integer (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::NbPoles, "None");
	cls_Geom2dAdaptor_Curve.def("NbKnots", (Standard_Integer (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::NbKnots, "None");
	cls_Geom2dAdaptor_Curve.def("NbSamples", (Standard_Integer (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::NbSamples, "None");
	cls_Geom2dAdaptor_Curve.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::Bezier, "None");
	cls_Geom2dAdaptor_Curve.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (Geom2dAdaptor_Curve::*)() const ) &Geom2dAdaptor_Curve::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dAdaptor_GHCurve.hxx
	py::class_<Geom2dAdaptor_GHCurve, opencascade::handle<Geom2dAdaptor_GHCurve>, Adaptor2d_HCurve2d> cls_Geom2dAdaptor_GHCurve(mod, "Geom2dAdaptor_GHCurve", "None");
	cls_Geom2dAdaptor_GHCurve.def(py::init<>());
	cls_Geom2dAdaptor_GHCurve.def(py::init<const Geom2dAdaptor_Curve &>(), py::arg("C"));
	cls_Geom2dAdaptor_GHCurve.def("Set", (void (Geom2dAdaptor_GHCurve::*)(const Geom2dAdaptor_Curve &)) &Geom2dAdaptor_GHCurve::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
	cls_Geom2dAdaptor_GHCurve.def("Curve2d", (const Adaptor2d_Curve2d & (Geom2dAdaptor_GHCurve::*)() const ) &Geom2dAdaptor_GHCurve::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
	cls_Geom2dAdaptor_GHCurve.def("ChangeCurve2d", (Geom2dAdaptor_Curve & (Geom2dAdaptor_GHCurve::*)()) &Geom2dAdaptor_GHCurve::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
	cls_Geom2dAdaptor_GHCurve.def_static("get_type_name_", (const char * (*)()) &Geom2dAdaptor_GHCurve::get_type_name, "None");
	cls_Geom2dAdaptor_GHCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2dAdaptor_GHCurve::get_type_descriptor, "None");
	cls_Geom2dAdaptor_GHCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2dAdaptor_GHCurve::*)() const ) &Geom2dAdaptor_GHCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dAdaptor_HCurve.hxx
	py::class_<Geom2dAdaptor_HCurve, opencascade::handle<Geom2dAdaptor_HCurve>, Geom2dAdaptor_GHCurve> cls_Geom2dAdaptor_HCurve(mod, "Geom2dAdaptor_HCurve", "Provides an interface between the services provided by any curve from the package Geom2d and those required of the curve by algorithms, which use it.");
	cls_Geom2dAdaptor_HCurve.def(py::init<>());
	cls_Geom2dAdaptor_HCurve.def(py::init<const Geom2dAdaptor_Curve &>(), py::arg("AS"));
	cls_Geom2dAdaptor_HCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("S"));
	cls_Geom2dAdaptor_HCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"));
	cls_Geom2dAdaptor_HCurve.def_static("get_type_name_", (const char * (*)()) &Geom2dAdaptor_HCurve::get_type_name, "None");
	cls_Geom2dAdaptor_HCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2dAdaptor_HCurve::get_type_descriptor, "None");
	cls_Geom2dAdaptor_HCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2dAdaptor_HCurve::*)() const ) &Geom2dAdaptor_HCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dAdaptor.hxx
	py::class_<Geom2dAdaptor, std::unique_ptr<Geom2dAdaptor, Deleter<Geom2dAdaptor>>> cls_Geom2dAdaptor(mod, "Geom2dAdaptor", "this package contains the geometric definition of 2d curves compatible with the Adaptor package templates.");
	cls_Geom2dAdaptor.def(py::init<>());
	cls_Geom2dAdaptor.def_static("MakeCurve_", (opencascade::handle<Geom2d_Curve> (*)(const Adaptor2d_Curve2d &)) &Geom2dAdaptor::MakeCurve, "Inherited from GHCurve. Provides a curve handled by reference. Creates a 2d curve from a HCurve2d. This cannot process the OtherCurves.", py::arg("HC"));


}
