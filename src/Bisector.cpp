#include <pyOCCT_Common.hpp>

#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Trsf2d.hxx>
#include <Geom2d_Geometry.hxx>
#include <Bisector_Curve.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Geom2d_Point.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <Bisector_BisecAna.hxx>
#include <Bisector_BisecPC.hxx>
#include <Bisector_BisecCC.hxx>
#include <Bisector_PolyBis.hxx>
#include <Bisector_Bisec.hxx>
#include <IntRes2d_Intersection.hxx>
#include <IntRes2d_Domain.hxx>
#include <Bisector_Inter.hxx>
#include <Bisector_PointOnBis.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Bisector_FunctionH.hxx>
#include <Bisector_FunctionInter.hxx>
#include <Bisector.hxx>

PYBIND11_MODULE(Bisector, mod) {

	// IMPORT
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.IntRes2d");
	py::module::import("OCCT.math");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_Curve.hxx
	py::class_<Bisector_Curve, opencascade::handle<Bisector_Curve>, Geom2d_Curve> cls_Bisector_Curve(mod, "Bisector_Curve", "None");
	cls_Bisector_Curve.def("Parameter", (Standard_Real (Bisector_Curve::*)(const gp_Pnt2d &) const ) &Bisector_Curve::Parameter, "None", py::arg("P"));
	cls_Bisector_Curve.def("IsExtendAtStart", (Standard_Boolean (Bisector_Curve::*)() const ) &Bisector_Curve::IsExtendAtStart, "None");
	cls_Bisector_Curve.def("IsExtendAtEnd", (Standard_Boolean (Bisector_Curve::*)() const ) &Bisector_Curve::IsExtendAtEnd, "None");
	cls_Bisector_Curve.def("NbIntervals", (Standard_Integer (Bisector_Curve::*)() const ) &Bisector_Curve::NbIntervals, "If necessary, breaks the curve in intervals of continuity <C1>. And returns the number of intervals.");
	cls_Bisector_Curve.def("IntervalFirst", (Standard_Real (Bisector_Curve::*)(const Standard_Integer) const ) &Bisector_Curve::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("Index"));
	cls_Bisector_Curve.def("IntervalLast", (Standard_Real (Bisector_Curve::*)(const Standard_Integer) const ) &Bisector_Curve::IntervalLast, "Returns the last parameter of the current interval.", py::arg("Index"));
	cls_Bisector_Curve.def_static("get_type_name_", (const char * (*)()) &Bisector_Curve::get_type_name, "None");
	cls_Bisector_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bisector_Curve::get_type_descriptor, "None");
	cls_Bisector_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bisector_Curve::*)() const ) &Bisector_Curve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_BisecAna.hxx
	py::class_<Bisector_BisecAna, opencascade::handle<Bisector_BisecAna>, Bisector_Curve> cls_Bisector_BisecAna(mod, "Bisector_BisecAna", "This class provides the bisecting line between two geometric elements.The elements are Circles,Lines or Points.");
	cls_Bisector_BisecAna.def(py::init<>());
	cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Curve> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const GeomAbs_JoinType a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("Cu1"), py::arg("Cu2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("jointype"), py::arg("Tolerance"));
	cls_Bisector_BisecAna.def("Perform", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const GeomAbs_JoinType, const Standard_Real, const Standard_Boolean)) &Bisector_BisecAna::Perform, "Performs the bisecting line between the curves <Cu1> and <Cu2>. <oncurve> is True if the point <P> is common to <Cu1> and <Cu2>.", py::arg("Cu1"), py::arg("Cu2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("jointype"), py::arg("Tolerance"), py::arg("oncurve"));
	cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("Cu"), py::arg("Pnt"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"));
	cls_Bisector_BisecAna.def("Perform", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Point> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_BisecAna::Perform, "Performs the bisecting line between the curve <Cu1> and the point <Pnt>. <oncurve> is True if the point <P> is the point <Pnt>.", py::arg("Cu"), py::arg("Pnt"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
	cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Curve> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("Pnt"), py::arg("Cu"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"));
	cls_Bisector_BisecAna.def("Perform", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_BisecAna::Perform, "Performs the bisecting line between the curve <Cu> and the point <Pnt>. <oncurve> is True if the point <P> is the point <Pnt>.", py::arg("Pnt"), py::arg("Cu"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
	cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); }, py::arg("Pnt1"), py::arg("Pnt2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"));
	cls_Bisector_BisecAna.def("Perform", [](Bisector_BisecAna &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("Pnt1"), py::arg("Pnt2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"));
	cls_Bisector_BisecAna.def("Perform", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_BisecAna::Perform, "Performs the bisecting line between the two points <Pnt1> and <Pnt2>.", py::arg("Pnt1"), py::arg("Pnt2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
	cls_Bisector_BisecAna.def("Init", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_TrimmedCurve> &)) &Bisector_BisecAna::Init, "None", py::arg("bisector"));
	cls_Bisector_BisecAna.def("IsExtendAtStart", (Standard_Boolean (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::IsExtendAtStart, "None");
	cls_Bisector_BisecAna.def("IsExtendAtEnd", (Standard_Boolean (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::IsExtendAtEnd, "None");
	cls_Bisector_BisecAna.def("SetTrim", (void (Bisector_BisecAna::*)(const opencascade::handle<Geom2d_Curve> &)) &Bisector_BisecAna::SetTrim, "Trim <me> by a domain defined by the curve <Cu>. This domain is the set of the points which are nearest from <Cu> than the extremitis of <Cu>.", py::arg("Cu"));
	cls_Bisector_BisecAna.def("SetTrim", (void (Bisector_BisecAna::*)(const Standard_Real, const Standard_Real)) &Bisector_BisecAna::SetTrim, "Trim <me> by a domain defined by uf and ul", py::arg("uf"), py::arg("ul"));
	cls_Bisector_BisecAna.def("Reverse", (void (Bisector_BisecAna::*)()) &Bisector_BisecAna::Reverse, "None");
	cls_Bisector_BisecAna.def("ReversedParameter", (Standard_Real (Bisector_BisecAna::*)(const Standard_Real) const ) &Bisector_BisecAna::ReversedParameter, "None", py::arg("U"));
	cls_Bisector_BisecAna.def("IsCN", (Standard_Boolean (Bisector_BisecAna::*)(const Standard_Integer) const ) &Bisector_BisecAna::IsCN, "Returns the order of continuity of the curve. Raised if N < 0.", py::arg("N"));
	cls_Bisector_BisecAna.def("Copy", (opencascade::handle<Geom2d_Geometry> (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::Copy, "None");
	cls_Bisector_BisecAna.def("Transform", (void (Bisector_BisecAna::*)(const gp_Trsf2d &)) &Bisector_BisecAna::Transform, "None", py::arg("T"));
	cls_Bisector_BisecAna.def("FirstParameter", (Standard_Real (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::FirstParameter, "None");
	cls_Bisector_BisecAna.def("LastParameter", (Standard_Real (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::LastParameter, "None");
	cls_Bisector_BisecAna.def("IsClosed", (Standard_Boolean (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::IsClosed, "None");
	cls_Bisector_BisecAna.def("IsPeriodic", (Standard_Boolean (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::IsPeriodic, "None");
	cls_Bisector_BisecAna.def("Continuity", (GeomAbs_Shape (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::Continuity, "None");
	cls_Bisector_BisecAna.def("D0", (void (Bisector_BisecAna::*)(const Standard_Real, gp_Pnt2d &) const ) &Bisector_BisecAna::D0, "None", py::arg("U"), py::arg("P"));
	cls_Bisector_BisecAna.def("D1", (void (Bisector_BisecAna::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &Bisector_BisecAna::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"));
	cls_Bisector_BisecAna.def("D2", (void (Bisector_BisecAna::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &Bisector_BisecAna::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Bisector_BisecAna.def("D3", (void (Bisector_BisecAna::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const ) &Bisector_BisecAna::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Bisector_BisecAna.def("DN", (gp_Vec2d (Bisector_BisecAna::*)(const Standard_Real, const Standard_Integer) const ) &Bisector_BisecAna::DN, "None", py::arg("U"), py::arg("N"));
	cls_Bisector_BisecAna.def("Geom2dCurve", (opencascade::handle<Geom2d_Curve> (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::Geom2dCurve, "None");
	cls_Bisector_BisecAna.def("Parameter", (Standard_Real (Bisector_BisecAna::*)(const gp_Pnt2d &) const ) &Bisector_BisecAna::Parameter, "None", py::arg("P"));
	cls_Bisector_BisecAna.def("ParameterOfStartPoint", (Standard_Real (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::ParameterOfStartPoint, "None");
	cls_Bisector_BisecAna.def("ParameterOfEndPoint", (Standard_Real (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::ParameterOfEndPoint, "None");
	cls_Bisector_BisecAna.def("NbIntervals", (Standard_Integer (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::NbIntervals, "If necessary, breaks the curve in intervals of continuity <C1>. And returns the number of intervals.");
	cls_Bisector_BisecAna.def("IntervalFirst", (Standard_Real (Bisector_BisecAna::*)(const Standard_Integer) const ) &Bisector_BisecAna::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("Index"));
	cls_Bisector_BisecAna.def("IntervalLast", (Standard_Real (Bisector_BisecAna::*)(const Standard_Integer) const ) &Bisector_BisecAna::IntervalLast, "Returns the last parameter of the current interval.", py::arg("Index"));
	// FIXME cls_Bisector_BisecAna.def("Dump", [](Bisector_BisecAna &self) -> void { return self.Dump(); });
	// FIXME cls_Bisector_BisecAna.def("Dump", [](Bisector_BisecAna &self, const Standard_Integer a0) -> void { return self.Dump(a0); }, py::arg("Deep"));
	// FIXME cls_Bisector_BisecAna.def("Dump", (void (Bisector_BisecAna::*)(const Standard_Integer, const Standard_Integer) const ) &Bisector_BisecAna::Dump, "None", py::arg("Deep"), py::arg("Offset"));
	cls_Bisector_BisecAna.def_static("get_type_name_", (const char * (*)()) &Bisector_BisecAna::get_type_name, "None");
	cls_Bisector_BisecAna.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bisector_BisecAna::get_type_descriptor, "None");
	cls_Bisector_BisecAna.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bisector_BisecAna::*)() const ) &Bisector_BisecAna::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_BisecPC.hxx
	py::class_<Bisector_BisecPC, opencascade::handle<Bisector_BisecPC>, Bisector_Curve> cls_Bisector_BisecPC(mod, "Bisector_BisecPC", "Provides the bisector between a point and a curve. the curvature on the curve has to be monoton. the point can't be on the curve exept at the extremitys.");
	cls_Bisector_BisecPC.def(py::init<>());
	cls_Bisector_BisecPC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Cu"), py::arg("P"), py::arg("Side"));
	cls_Bisector_BisecPC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Cu"), py::arg("P"), py::arg("Side"), py::arg("DistMax"));
	cls_Bisector_BisecPC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Cu"), py::arg("P"), py::arg("Side"), py::arg("UMin"), py::arg("UMax"));
	cls_Bisector_BisecPC.def("Perform", [](Bisector_BisecPC &self, const opencascade::handle<Geom2d_Curve> & a0, const gp_Pnt2d & a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); }, py::arg("Cu"), py::arg("P"), py::arg("Side"));
	cls_Bisector_BisecPC.def("Perform", (void (Bisector_BisecPC::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &Bisector_BisecPC::Perform, "Construct the bisector between the point <P> and the curve <Cu>. <Side> = 1. if the bisector curve is on the Left of <Cu> else <Side> = -1. <DistMax> is used to trim the bisector.The distance between the points of the bisector and <Cu> is smaller than <DistMax>.", py::arg("Cu"), py::arg("P"), py::arg("Side"), py::arg("DistMax"));
	cls_Bisector_BisecPC.def("IsExtendAtStart", (Standard_Boolean (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::IsExtendAtStart, "Returns True if the bisector is extended at start.");
	cls_Bisector_BisecPC.def("IsExtendAtEnd", (Standard_Boolean (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::IsExtendAtEnd, "Returns True if the bisector is extended at end.");
	cls_Bisector_BisecPC.def("Reverse", (void (Bisector_BisecPC::*)()) &Bisector_BisecPC::Reverse, "Changes the direction of parametrization of <me>. The orientation of the curve is modified. If the curve is bounded the StartPoint of the initial curve becomes the EndPoint of the reversed curve and the EndPoint of the initial curve becomes the StartPoint of the reversed curve.");
	cls_Bisector_BisecPC.def("ReversedParameter", (Standard_Real (Bisector_BisecPC::*)(const Standard_Real) const ) &Bisector_BisecPC::ReversedParameter, "Returns the parameter on the reversed curve for the point of parameter U on <me>.", py::arg("U"));
	cls_Bisector_BisecPC.def("Copy", (opencascade::handle<Geom2d_Geometry> (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::Copy, "None");
	cls_Bisector_BisecPC.def("Transform", (void (Bisector_BisecPC::*)(const gp_Trsf2d &)) &Bisector_BisecPC::Transform, "Transformation of a geometric object. This tansformation can be a translation, a rotation, a symmetry, a scaling or a complex transformation obtained by combination of the previous elementaries transformations.", py::arg("T"));
	cls_Bisector_BisecPC.def("IsCN", (Standard_Boolean (Bisector_BisecPC::*)(const Standard_Integer) const ) &Bisector_BisecPC::IsCN, "Returns the order of continuity of the curve. Raised if N < 0.", py::arg("N"));
	cls_Bisector_BisecPC.def("FirstParameter", (Standard_Real (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::FirstParameter, "Value of the first parameter.");
	cls_Bisector_BisecPC.def("LastParameter", (Standard_Real (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::LastParameter, "Value of the last parameter.");
	cls_Bisector_BisecPC.def("Continuity", (GeomAbs_Shape (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::Continuity, "None");
	cls_Bisector_BisecPC.def("NbIntervals", (Standard_Integer (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::NbIntervals, "If necessary, breaks the curve in intervals of continuity <C1>. And returns the number of intervals.");
	cls_Bisector_BisecPC.def("IntervalFirst", (Standard_Real (Bisector_BisecPC::*)(const Standard_Integer) const ) &Bisector_BisecPC::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("Index"));
	cls_Bisector_BisecPC.def("IntervalLast", (Standard_Real (Bisector_BisecPC::*)(const Standard_Integer) const ) &Bisector_BisecPC::IntervalLast, "Returns the last parameter of the current interval.", py::arg("Index"));
	cls_Bisector_BisecPC.def("IntervalContinuity", (GeomAbs_Shape (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::IntervalContinuity, "None");
	cls_Bisector_BisecPC.def("IsClosed", (Standard_Boolean (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::IsClosed, "None");
	cls_Bisector_BisecPC.def("IsPeriodic", (Standard_Boolean (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::IsPeriodic, "None");
	cls_Bisector_BisecPC.def("Distance", (Standard_Real (Bisector_BisecPC::*)(const Standard_Real) const ) &Bisector_BisecPC::Distance, "Returns the distance between the point of parameter U on <me> and my point or my curve.", py::arg("U"));
	cls_Bisector_BisecPC.def("D0", (void (Bisector_BisecPC::*)(const Standard_Real, gp_Pnt2d &) const ) &Bisector_BisecPC::D0, "None", py::arg("U"), py::arg("P"));
	cls_Bisector_BisecPC.def("D1", (void (Bisector_BisecPC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &Bisector_BisecPC::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Bisector_BisecPC.def("D2", (void (Bisector_BisecPC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &Bisector_BisecPC::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Bisector_BisecPC.def("D3", (void (Bisector_BisecPC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const ) &Bisector_BisecPC::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Bisector_BisecPC.def("DN", (gp_Vec2d (Bisector_BisecPC::*)(const Standard_Real, const Standard_Integer) const ) &Bisector_BisecPC::DN, "None", py::arg("U"), py::arg("N"));
	// FIXME cls_Bisector_BisecPC.def("Dump", [](Bisector_BisecPC &self) -> void { return self.Dump(); });
	// FIXME cls_Bisector_BisecPC.def("Dump", [](Bisector_BisecPC &self, const Standard_Integer a0) -> void { return self.Dump(a0); }, py::arg("Deep"));
	// FIXME cls_Bisector_BisecPC.def("Dump", (void (Bisector_BisecPC::*)(const Standard_Integer, const Standard_Integer) const ) &Bisector_BisecPC::Dump, "None", py::arg("Deep"), py::arg("Offset"));
	cls_Bisector_BisecPC.def("LinkBisCurve", (Standard_Real (Bisector_BisecPC::*)(const Standard_Real) const ) &Bisector_BisecPC::LinkBisCurve, "Returns the parameter on the curve1 of the projection of the point of parameter U on <me>.", py::arg("U"));
	cls_Bisector_BisecPC.def("LinkCurveBis", (Standard_Real (Bisector_BisecPC::*)(const Standard_Real) const ) &Bisector_BisecPC::LinkCurveBis, "Returns the reciproque of LinkBisCurve.", py::arg("U"));
	cls_Bisector_BisecPC.def("Parameter", (Standard_Real (Bisector_BisecPC::*)(const gp_Pnt2d &) const ) &Bisector_BisecPC::Parameter, "Returns the parameter on <me> corresponding to <P>.", py::arg("P"));
	cls_Bisector_BisecPC.def("IsEmpty", (Standard_Boolean (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::IsEmpty, "Returns <True> if the bisector is empty.");
	cls_Bisector_BisecPC.def_static("get_type_name_", (const char * (*)()) &Bisector_BisecPC::get_type_name, "None");
	cls_Bisector_BisecPC.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bisector_BisecPC::get_type_descriptor, "None");
	cls_Bisector_BisecPC.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bisector_BisecPC::*)() const ) &Bisector_BisecPC::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_BisecCC.hxx
	py::class_<Bisector_BisecCC, opencascade::handle<Bisector_BisecCC>, Bisector_Curve> cls_Bisector_BisecCC(mod, "Bisector_BisecCC", "Construct the bisector between two curves. The curves can intersect only in their extremities.");
	cls_Bisector_BisecCC.def(py::init<>());
	cls_Bisector_BisecCC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const gp_Pnt2d &>(), py::arg("Cu1"), py::arg("Cu2"), py::arg("Side1"), py::arg("Side2"), py::arg("Origin"));
	cls_Bisector_BisecCC.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real>(), py::arg("Cu1"), py::arg("Cu2"), py::arg("Side1"), py::arg("Side2"), py::arg("Origin"), py::arg("DistMax"));
	cls_Bisector_BisecCC.def("Perform", [](Bisector_BisecCC &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Curve> & a1, const Standard_Real a2, const Standard_Real a3, const gp_Pnt2d & a4) -> void { return self.Perform(a0, a1, a2, a3, a4); }, py::arg("Cu1"), py::arg("Cu2"), py::arg("Side1"), py::arg("Side2"), py::arg("Origin"));
	cls_Bisector_BisecCC.def("Perform", (void (Bisector_BisecCC::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real)) &Bisector_BisecCC::Perform, "Computes the bisector between the curves <Cu1> and <Cu2>.", py::arg("Cu1"), py::arg("Cu2"), py::arg("Side1"), py::arg("Side2"), py::arg("Origin"), py::arg("DistMax"));
	cls_Bisector_BisecCC.def("IsExtendAtStart", (Standard_Boolean (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::IsExtendAtStart, "None");
	cls_Bisector_BisecCC.def("IsExtendAtEnd", (Standard_Boolean (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::IsExtendAtEnd, "None");
	cls_Bisector_BisecCC.def("Reverse", (void (Bisector_BisecCC::*)()) &Bisector_BisecCC::Reverse, "None");
	cls_Bisector_BisecCC.def("ReversedParameter", (Standard_Real (Bisector_BisecCC::*)(const Standard_Real) const ) &Bisector_BisecCC::ReversedParameter, "None", py::arg("U"));
	cls_Bisector_BisecCC.def("IsCN", (Standard_Boolean (Bisector_BisecCC::*)(const Standard_Integer) const ) &Bisector_BisecCC::IsCN, "Returns the order of continuity of the curve. Raised if N < 0.", py::arg("N"));
	cls_Bisector_BisecCC.def("ChangeGuide", (opencascade::handle<Bisector_BisecCC> (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::ChangeGuide, "The parameter on <me> is linked to the parameter on the first curve. This method creates the same bisector where the curves are inversed.");
	cls_Bisector_BisecCC.def("Copy", (opencascade::handle<Geom2d_Geometry> (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::Copy, "None");
	cls_Bisector_BisecCC.def("Transform", (void (Bisector_BisecCC::*)(const gp_Trsf2d &)) &Bisector_BisecCC::Transform, "Transformation of a geometric object. This tansformation can be a translation, a rotation, a symmetry, a scaling or a complex transformation obtained by combination of the previous elementaries transformations.", py::arg("T"));
	cls_Bisector_BisecCC.def("FirstParameter", (Standard_Real (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::FirstParameter, "None");
	cls_Bisector_BisecCC.def("LastParameter", (Standard_Real (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::LastParameter, "None");
	cls_Bisector_BisecCC.def("Continuity", (GeomAbs_Shape (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::Continuity, "None");
	cls_Bisector_BisecCC.def("NbIntervals", (Standard_Integer (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::NbIntervals, "If necessary, breaks the curve in intervals of continuity <C1>. And returns the number of intervals.");
	cls_Bisector_BisecCC.def("IntervalFirst", (Standard_Real (Bisector_BisecCC::*)(const Standard_Integer) const ) &Bisector_BisecCC::IntervalFirst, "Returns the first parameter of the current interval.", py::arg("Index"));
	cls_Bisector_BisecCC.def("IntervalLast", (Standard_Real (Bisector_BisecCC::*)(const Standard_Integer) const ) &Bisector_BisecCC::IntervalLast, "Returns the last parameter of the current interval.", py::arg("Index"));
	cls_Bisector_BisecCC.def("IntervalContinuity", (GeomAbs_Shape (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::IntervalContinuity, "None");
	cls_Bisector_BisecCC.def("IsClosed", (Standard_Boolean (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::IsClosed, "None");
	cls_Bisector_BisecCC.def("IsPeriodic", (Standard_Boolean (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::IsPeriodic, "None");
	cls_Bisector_BisecCC.def("ValueAndDist", [](Bisector_BisecCC &self, const Standard_Real U, Standard_Real & U1, Standard_Real & U2, Standard_Real & Distance){ gp_Pnt2d rv = self.ValueAndDist(U, U1, U2, Distance); return std::tuple<gp_Pnt2d, Standard_Real &, Standard_Real &, Standard_Real &>(rv, U1, U2, Distance); }, "Returns the point of parameter U. Computes the distance between the current point and the two curves I separate. Computes the parameters on each curve corresponding of the projection of the current point.", py::arg("U"), py::arg("U1"), py::arg("U2"), py::arg("Distance"));
	cls_Bisector_BisecCC.def("ValueByInt", [](Bisector_BisecCC &self, const Standard_Real U, Standard_Real & U1, Standard_Real & U2, Standard_Real & Distance){ gp_Pnt2d rv = self.ValueByInt(U, U1, U2, Distance); return std::tuple<gp_Pnt2d, Standard_Real &, Standard_Real &, Standard_Real &>(rv, U1, U2, Distance); }, "Returns the point of parameter U. Computes the distance between the current point and the two curves I separate. Computes the parameters on each curve corresponding of the projection of the current point.", py::arg("U"), py::arg("U1"), py::arg("U2"), py::arg("Distance"));
	cls_Bisector_BisecCC.def("D0", (void (Bisector_BisecCC::*)(const Standard_Real, gp_Pnt2d &) const ) &Bisector_BisecCC::D0, "None", py::arg("U"), py::arg("P"));
	cls_Bisector_BisecCC.def("D1", (void (Bisector_BisecCC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const ) &Bisector_BisecCC::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
	cls_Bisector_BisecCC.def("D2", (void (Bisector_BisecCC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const ) &Bisector_BisecCC::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Bisector_BisecCC.def("D3", (void (Bisector_BisecCC::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const ) &Bisector_BisecCC::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Bisector_BisecCC.def("DN", (gp_Vec2d (Bisector_BisecCC::*)(const Standard_Real, const Standard_Integer) const ) &Bisector_BisecCC::DN, "None", py::arg("U"), py::arg("N"));
	cls_Bisector_BisecCC.def("IsEmpty", (Standard_Boolean (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::IsEmpty, "None");
	cls_Bisector_BisecCC.def("LinkBisCurve", (Standard_Real (Bisector_BisecCC::*)(const Standard_Real) const ) &Bisector_BisecCC::LinkBisCurve, "Returns the parameter on the curve1 of the projection of the point of parameter U on <me>.", py::arg("U"));
	cls_Bisector_BisecCC.def("LinkCurveBis", (Standard_Real (Bisector_BisecCC::*)(const Standard_Real) const ) &Bisector_BisecCC::LinkCurveBis, "Returns the reciproque of LinkBisCurve.", py::arg("U"));
	cls_Bisector_BisecCC.def("Parameter", (Standard_Real (Bisector_BisecCC::*)(const gp_Pnt2d &) const ) &Bisector_BisecCC::Parameter, "None", py::arg("P"));
	cls_Bisector_BisecCC.def("Curve", (opencascade::handle<Geom2d_Curve> (Bisector_BisecCC::*)(const Standard_Integer) const ) &Bisector_BisecCC::Curve, "None", py::arg("IndCurve"));
	cls_Bisector_BisecCC.def("Polygon", (const Bisector_PolyBis & (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::Polygon, "None");
	// FIXME cls_Bisector_BisecCC.def("Dump", [](Bisector_BisecCC &self) -> void { return self.Dump(); });
	// FIXME cls_Bisector_BisecCC.def("Dump", [](Bisector_BisecCC &self, const Standard_Integer a0) -> void { return self.Dump(a0); }, py::arg("Deep"));
	// FIXME cls_Bisector_BisecCC.def("Dump", (void (Bisector_BisecCC::*)(const Standard_Integer, const Standard_Integer) const ) &Bisector_BisecCC::Dump, "None", py::arg("Deep"), py::arg("Offset"));
	cls_Bisector_BisecCC.def_static("get_type_name_", (const char * (*)()) &Bisector_BisecCC::get_type_name, "None");
	cls_Bisector_BisecCC.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bisector_BisecCC::get_type_descriptor, "None");
	cls_Bisector_BisecCC.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bisector_BisecCC::*)() const ) &Bisector_BisecCC::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_Bisec.hxx
	py::class_<Bisector_Bisec, std::unique_ptr<Bisector_Bisec, Deleter<Bisector_Bisec>>> cls_Bisector_Bisec(mod, "Bisector_Bisec", "Bisec provides the bisecting line between two elements This line is trimed by a point <P> and it's contained in the domain defined by the two vectors <V1>, <V2> and <Sense>.");
	cls_Bisector_Bisec.def(py::init<>());
	cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Curve> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const GeomAbs_JoinType a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("Cu1"), py::arg("Cu2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("ajointype"), py::arg("Tolerance"));
	cls_Bisector_Bisec.def("Perform", (void (Bisector_Bisec::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const GeomAbs_JoinType, const Standard_Real, const Standard_Boolean)) &Bisector_Bisec::Perform, "Performs the bisecting line between the curves <Cu1> and <Cu2>. <oncurve> is True if the point <P> is common to <Cu1> and <Cu2>.", py::arg("Cu1"), py::arg("Cu2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("ajointype"), py::arg("Tolerance"), py::arg("oncurve"));
	cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("Cu"), py::arg("Pnt"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"));
	cls_Bisector_Bisec.def("Perform", (void (Bisector_Bisec::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Point> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_Bisec::Perform, "Performs the bisecting line between the curve <Cu1> and the point <Pnt>. <oncurve> is True if the point <P> is the point <Pnt>.", py::arg("Cu"), py::arg("Pnt"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
	cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Curve> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("Pnt"), py::arg("Cu"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"));
	cls_Bisector_Bisec.def("Perform", (void (Bisector_Bisec::*)(const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_Bisec::Perform, "Performs the bisecting line between the curve <Cu> and the point <Pnt>. <oncurve> is True if the point <P> is the point <Pnt>.", py::arg("Pnt"), py::arg("Cu"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
	cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); }, py::arg("Pnt1"), py::arg("Pnt2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"));
	cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("Pnt1"), py::arg("Pnt2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"));
	cls_Bisector_Bisec.def("Perform", (void (Bisector_Bisec::*)(const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_Bisec::Perform, "Performs the bisecting line between the two points <Pnt1> and <Pnt2>.", py::arg("Pnt1"), py::arg("Pnt2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
	cls_Bisector_Bisec.def("Value", (const opencascade::handle<Geom2d_TrimmedCurve> & (Bisector_Bisec::*)() const ) &Bisector_Bisec::Value, "Returns the Curve of <me>.");
	cls_Bisector_Bisec.def("ChangeValue", (const opencascade::handle<Geom2d_TrimmedCurve> & (Bisector_Bisec::*)()) &Bisector_Bisec::ChangeValue, "Returns the Curve of <me>.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_Inter.hxx
	py::class_<Bisector_Inter, std::unique_ptr<Bisector_Inter, Deleter<Bisector_Inter>>, IntRes2d_Intersection> cls_Bisector_Inter(mod, "Bisector_Inter", "Intersection between two <Bisec> from Bisector.");
	cls_Bisector_Inter.def(py::init<>());
	cls_Bisector_Inter.def(py::init<const Bisector_Bisec &, const IntRes2d_Domain &, const Bisector_Bisec &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"), py::arg("ComunElement"));
	cls_Bisector_Inter.def("Perform", (void (Bisector_Inter::*)(const Bisector_Bisec &, const IntRes2d_Domain &, const Bisector_Bisec &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_Inter::Perform, "Intersection between 2 curves. C1 separates the element A and B. C2 separates the elements C et D. If B an C have the same geometry. <ComunElement> Has to be True. It Permits an optimiztion of the computation.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"), py::arg("ComunElement"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_PointOnBis.hxx
	py::class_<Bisector_PointOnBis, std::unique_ptr<Bisector_PointOnBis, Deleter<Bisector_PointOnBis>>> cls_Bisector_PointOnBis(mod, "Bisector_PointOnBis", "None");
	cls_Bisector_PointOnBis.def(py::init<>());
	cls_Bisector_PointOnBis.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt2d &>(), py::arg("Param1"), py::arg("Param2"), py::arg("ParamBis"), py::arg("Distance"), py::arg("Point"));
	cls_Bisector_PointOnBis.def("ParamOnC1", (void (Bisector_PointOnBis::*)(const Standard_Real)) &Bisector_PointOnBis::ParamOnC1, "None", py::arg("Param"));
	cls_Bisector_PointOnBis.def("ParamOnC2", (void (Bisector_PointOnBis::*)(const Standard_Real)) &Bisector_PointOnBis::ParamOnC2, "None", py::arg("Param"));
	cls_Bisector_PointOnBis.def("ParamOnBis", (void (Bisector_PointOnBis::*)(const Standard_Real)) &Bisector_PointOnBis::ParamOnBis, "None", py::arg("Param"));
	cls_Bisector_PointOnBis.def("Distance", (void (Bisector_PointOnBis::*)(const Standard_Real)) &Bisector_PointOnBis::Distance, "None", py::arg("Distance"));
	cls_Bisector_PointOnBis.def("IsInfinite", (void (Bisector_PointOnBis::*)(const Standard_Boolean)) &Bisector_PointOnBis::IsInfinite, "None", py::arg("Infinite"));
	cls_Bisector_PointOnBis.def("Point", (void (Bisector_PointOnBis::*)(const gp_Pnt2d &)) &Bisector_PointOnBis::Point, "None", py::arg("P"));
	cls_Bisector_PointOnBis.def("ParamOnC1", (Standard_Real (Bisector_PointOnBis::*)() const ) &Bisector_PointOnBis::ParamOnC1, "None");
	cls_Bisector_PointOnBis.def("ParamOnC2", (Standard_Real (Bisector_PointOnBis::*)() const ) &Bisector_PointOnBis::ParamOnC2, "None");
	cls_Bisector_PointOnBis.def("ParamOnBis", (Standard_Real (Bisector_PointOnBis::*)() const ) &Bisector_PointOnBis::ParamOnBis, "None");
	cls_Bisector_PointOnBis.def("Distance", (Standard_Real (Bisector_PointOnBis::*)() const ) &Bisector_PointOnBis::Distance, "None");
	cls_Bisector_PointOnBis.def("Point", (gp_Pnt2d (Bisector_PointOnBis::*)() const ) &Bisector_PointOnBis::Point, "None");
	cls_Bisector_PointOnBis.def("IsInfinite", (Standard_Boolean (Bisector_PointOnBis::*)() const ) &Bisector_PointOnBis::IsInfinite, "None");
	// FIXME cls_Bisector_PointOnBis.def("Dump", (void (Bisector_PointOnBis::*)() const ) &Bisector_PointOnBis::Dump, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_PolyBis.hxx
	py::class_<Bisector_PolyBis, std::unique_ptr<Bisector_PolyBis, Deleter<Bisector_PolyBis>>> cls_Bisector_PolyBis(mod, "Bisector_PolyBis", "Polygon of PointOnBis");
	cls_Bisector_PolyBis.def(py::init<>());
	cls_Bisector_PolyBis.def("Append", (void (Bisector_PolyBis::*)(const Bisector_PointOnBis &)) &Bisector_PolyBis::Append, "None", py::arg("Point"));
	cls_Bisector_PolyBis.def("Length", (Standard_Integer (Bisector_PolyBis::*)() const ) &Bisector_PolyBis::Length, "None");
	cls_Bisector_PolyBis.def("IsEmpty", (Standard_Boolean (Bisector_PolyBis::*)() const ) &Bisector_PolyBis::IsEmpty, "None");
	cls_Bisector_PolyBis.def("Value", (const Bisector_PointOnBis & (Bisector_PolyBis::*)(const Standard_Integer) const ) &Bisector_PolyBis::Value, "None", py::arg("Index"));
	cls_Bisector_PolyBis.def("First", (const Bisector_PointOnBis & (Bisector_PolyBis::*)() const ) &Bisector_PolyBis::First, "None");
	cls_Bisector_PolyBis.def("Last", (const Bisector_PointOnBis & (Bisector_PolyBis::*)() const ) &Bisector_PolyBis::Last, "None");
	cls_Bisector_PolyBis.def("Interval", (Standard_Integer (Bisector_PolyBis::*)(const Standard_Real) const ) &Bisector_PolyBis::Interval, "None", py::arg("U"));
	cls_Bisector_PolyBis.def("Transform", (void (Bisector_PolyBis::*)(const gp_Trsf2d &)) &Bisector_PolyBis::Transform, "None", py::arg("T"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_FunctionH.hxx
	py::class_<Bisector_FunctionH, std::unique_ptr<Bisector_FunctionH, Deleter<Bisector_FunctionH>>, math_FunctionWithDerivative> cls_Bisector_FunctionH(mod, "Bisector_FunctionH", "H(v) = (T1 .P2(v) - P1) * ||T(v)|| - 2 2 (T(v).P2(v) - P1) * ||T1||");
	cls_Bisector_FunctionH.def(py::init<const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Vec2d &>(), py::arg("C2"), py::arg("P1"), py::arg("T1"));
	cls_Bisector_FunctionH.def("Value", [](Bisector_FunctionH &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the values of the Functions for the variable <X>.", py::arg("X"), py::arg("F"));
	cls_Bisector_FunctionH.def("Derivative", [](Bisector_FunctionH &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "None", py::arg("X"), py::arg("D"));
	cls_Bisector_FunctionH.def("Values", [](Bisector_FunctionH &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Returns the values of the functions and the derivatives for the variable <X>.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector_FunctionInter.hxx
	py::class_<Bisector_FunctionInter, std::unique_ptr<Bisector_FunctionInter, Deleter<Bisector_FunctionInter>>, math_FunctionWithDerivative> cls_Bisector_FunctionInter(mod, "Bisector_FunctionInter", "2 2 F(u) = (PC(u) - PBis1(u)) + (PC(u) - PBis2(u))");
	cls_Bisector_FunctionInter.def(py::init<>());
	cls_Bisector_FunctionInter.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Bisector_Curve> &, const opencascade::handle<Bisector_Curve> &>(), py::arg("C"), py::arg("Bis1"), py::arg("Bis2"));
	cls_Bisector_FunctionInter.def("Perform", (void (Bisector_FunctionInter::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Bisector_Curve> &, const opencascade::handle<Bisector_Curve> &)) &Bisector_FunctionInter::Perform, "None", py::arg("C"), py::arg("Bis1"), py::arg("Bis2"));
	cls_Bisector_FunctionInter.def("Value", [](Bisector_FunctionInter &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the values of the Functions for the variable <X>.", py::arg("X"), py::arg("F"));
	cls_Bisector_FunctionInter.def("Derivative", [](Bisector_FunctionInter &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "None", py::arg("X"), py::arg("D"));
	cls_Bisector_FunctionInter.def("Values", [](Bisector_FunctionInter &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Returns the values of the functions and the derivatives for the variable <X>.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Bisector.hxx
	py::class_<Bisector, std::unique_ptr<Bisector, Deleter<Bisector>>> cls_Bisector(mod, "Bisector", "This package provides the bisecting line between two geometric elements.");
	cls_Bisector.def(py::init<>());
	cls_Bisector.def_static("IsConvex_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real)) &Bisector::IsConvex, "None", py::arg("Cu"), py::arg("Sign"));


}
