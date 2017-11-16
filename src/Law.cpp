#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Law_Function.hxx>
#include <Standard_Type.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <Law_Laws.hxx>
#include <Law_Composite.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomAbs_BSplKnotDistribution.hxx>
#include <Law_BSpline.hxx>
#include <Law_BSpFunc.hxx>
#include <Law_Linear.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <Law_Interpolate.hxx>
#include <Law_Constant.hxx>
#include <Law_S.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Law_Interpol.hxx>
#include <Law_BSplineKnotSplitting.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Law.hxx>

PYBIND11_MODULE(Law, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.Adaptor3d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_Function.hxx
	py::class_<Law_Function, opencascade::handle<Law_Function>, Standard_Transient> cls_Law_Function(mod, "Law_Function", "Root class for evolution laws.");
	cls_Law_Function.def("Continuity", (GeomAbs_Shape (Law_Function::*)() const ) &Law_Function::Continuity, "None");
	cls_Law_Function.def("NbIntervals", (Standard_Integer (Law_Function::*)(const GeomAbs_Shape) const ) &Law_Function::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_Law_Function.def("Intervals", (void (Law_Function::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Law_Function::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Law_Function.def("Value", (Standard_Real (Law_Function::*)(const Standard_Real)) &Law_Function::Value, "Returns the value of the function at the point of parameter X.", py::arg("X"));
	cls_Law_Function.def("D1", (void (Law_Function::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &Law_Function::D1, "Returns the value F and the first derivative D of the function at the point of parameter X.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_Law_Function.def("D2", (void (Law_Function::*)(const Standard_Real, Standard_Real &, Standard_Real &, Standard_Real &)) &Law_Function::D2, "Returns the value, first and seconde derivatives at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"), py::arg("D2"));
	cls_Law_Function.def("Trim", (opencascade::handle<Law_Function> (Law_Function::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Law_Function::Trim, "Returns a law equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. It is usfule to determines the derivatives in these values <First> and <Last> if the Law is not Cn.", py::arg("PFirst"), py::arg("PLast"), py::arg("Tol"));
	cls_Law_Function.def("Bounds", (void (Law_Function::*)(Standard_Real &, Standard_Real &)) &Law_Function::Bounds, "Returns the parametric bounds of the function.", py::arg("PFirst"), py::arg("PLast"));
	cls_Law_Function.def_static("get_type_name_", (const char * (*)()) &Law_Function::get_type_name, "None");
	cls_Law_Function.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_Function::get_type_descriptor, "None");
	cls_Law_Function.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_Function::*)() const ) &Law_Function::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_Composite.hxx
	py::class_<Law_Composite, opencascade::handle<Law_Composite>, Law_Function> cls_Law_Composite(mod, "Law_Composite", "Loi composite constituee d une liste de lois de ranges consecutifs. Cette implementation un peu lourde permet de reunir en une seule loi des portions de loi construites de facon independantes (par exemple en interactif) et de lancer le walking d un coup a l echelle d une ElSpine. CET OBJET REPOND DONC A UN PROBLEME D IMPLEMENTATION SPECIFIQUE AUX CONGES!!!");
	cls_Law_Composite.def(py::init<>());
	cls_Law_Composite.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Law_Composite.def("Continuity", (GeomAbs_Shape (Law_Composite::*)() const ) &Law_Composite::Continuity, "None");
	cls_Law_Composite.def("NbIntervals", (Standard_Integer (Law_Composite::*)(const GeomAbs_Shape) const ) &Law_Composite::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_Law_Composite.def("Intervals", (void (Law_Composite::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Law_Composite::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Law_Composite.def("Value", (Standard_Real (Law_Composite::*)(const Standard_Real)) &Law_Composite::Value, "Returns the value at parameter X.", py::arg("X"));
	cls_Law_Composite.def("D1", (void (Law_Composite::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &Law_Composite::D1, "Returns the value and the first derivative at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_Law_Composite.def("D2", (void (Law_Composite::*)(const Standard_Real, Standard_Real &, Standard_Real &, Standard_Real &)) &Law_Composite::D2, "Returns the value, first and second derivatives at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"), py::arg("D2"));
	cls_Law_Composite.def("Trim", (opencascade::handle<Law_Function> (Law_Composite::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Law_Composite::Trim, "Returns a law equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. It is usfule to determines the derivatives in these values <First> and <Last> if the Law is not Cn.", py::arg("PFirst"), py::arg("PLast"), py::arg("Tol"));
	cls_Law_Composite.def("Bounds", (void (Law_Composite::*)(Standard_Real &, Standard_Real &)) &Law_Composite::Bounds, "Returns the parametric bounds of the function.", py::arg("PFirst"), py::arg("PLast"));
	cls_Law_Composite.def("ChangeElementaryLaw", (opencascade::handle<Law_Function> & (Law_Composite::*)(const Standard_Real)) &Law_Composite::ChangeElementaryLaw, "Returns the elementary function of the composite used to compute at parameter W.", py::arg("W"));
	cls_Law_Composite.def("ChangeLaws", (Law_Laws & (Law_Composite::*)()) &Law_Composite::ChangeLaws, "None");
	cls_Law_Composite.def("IsPeriodic", (Standard_Boolean (Law_Composite::*)() const ) &Law_Composite::IsPeriodic, "None");
	cls_Law_Composite.def("SetPeriodic", (void (Law_Composite::*)()) &Law_Composite::SetPeriodic, "None");
	cls_Law_Composite.def_static("get_type_name_", (const char * (*)()) &Law_Composite::get_type_name, "None");
	cls_Law_Composite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_Composite::get_type_descriptor, "None");
	cls_Law_Composite.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_Composite::*)() const ) &Law_Composite::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_BSpline.hxx
	py::class_<Law_BSpline, opencascade::handle<Law_BSpline>, Standard_Transient> cls_Law_BSpline(mod, "Law_BSpline", "Definition of the 1D B_spline curve.");
	cls_Law_BSpline.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer>(), py::arg("Poles"), py::arg("Knots"), py::arg("Multiplicities"), py::arg("Degree"));
	cls_Law_BSpline.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Boolean>(), py::arg("Poles"), py::arg("Knots"), py::arg("Multiplicities"), py::arg("Degree"), py::arg("Periodic"));
	cls_Law_BSpline.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer>(), py::arg("Poles"), py::arg("Weights"), py::arg("Knots"), py::arg("Multiplicities"), py::arg("Degree"));
	cls_Law_BSpline.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Integer, const Standard_Boolean>(), py::arg("Poles"), py::arg("Weights"), py::arg("Knots"), py::arg("Multiplicities"), py::arg("Degree"), py::arg("Periodic"));
	cls_Law_BSpline.def("IncreaseDegree", (void (Law_BSpline::*)(const Standard_Integer)) &Law_BSpline::IncreaseDegree, "Increase the degree to <Degree>. Nothing is done if <Degree> is lower or equal to the current degree.", py::arg("Degree"));
	cls_Law_BSpline.def("IncreaseMultiplicity", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Integer)) &Law_BSpline::IncreaseMultiplicity, "Increases the multiplicity of the knot <Index> to <M>.", py::arg("Index"), py::arg("M"));
	cls_Law_BSpline.def("IncreaseMultiplicity", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Law_BSpline::IncreaseMultiplicity, "Increases the multiplicities of the knots in [I1,I2] to <M>.", py::arg("I1"), py::arg("I2"), py::arg("M"));
	cls_Law_BSpline.def("IncrementMultiplicity", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Law_BSpline::IncrementMultiplicity, "Increment the multiplicities of the knots in [I1,I2] by <M>.", py::arg("I1"), py::arg("I2"), py::arg("M"));
	cls_Law_BSpline.def("InsertKnot", [](Law_BSpline &self, const Standard_Real a0) -> void { return self.InsertKnot(a0); }, py::arg("U"));
	cls_Law_BSpline.def("InsertKnot", [](Law_BSpline &self, const Standard_Real a0, const Standard_Integer a1) -> void { return self.InsertKnot(a0, a1); }, py::arg("U"), py::arg("M"));
	cls_Law_BSpline.def("InsertKnot", [](Law_BSpline &self, const Standard_Real a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.InsertKnot(a0, a1, a2); }, py::arg("U"), py::arg("M"), py::arg("ParametricTolerance"));
	cls_Law_BSpline.def("InsertKnot", (void (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Boolean)) &Law_BSpline::InsertKnot, "Inserts a knot value in the sequence of knots. If <U> is an existing knot the multiplicity is increased by <M>.", py::arg("U"), py::arg("M"), py::arg("ParametricTolerance"), py::arg("Add"));
	cls_Law_BSpline.def("InsertKnots", [](Law_BSpline &self, const TColStd_Array1OfReal & a0, const TColStd_Array1OfInteger & a1) -> void { return self.InsertKnots(a0, a1); }, py::arg("Knots"), py::arg("Mults"));
	cls_Law_BSpline.def("InsertKnots", [](Law_BSpline &self, const TColStd_Array1OfReal & a0, const TColStd_Array1OfInteger & a1, const Standard_Real a2) -> void { return self.InsertKnots(a0, a1, a2); }, py::arg("Knots"), py::arg("Mults"), py::arg("ParametricTolerance"));
	cls_Law_BSpline.def("InsertKnots", (void (Law_BSpline::*)(const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Real, const Standard_Boolean)) &Law_BSpline::InsertKnots, "Inserts a set of knots values in the sequence of knots.", py::arg("Knots"), py::arg("Mults"), py::arg("ParametricTolerance"), py::arg("Add"));
	cls_Law_BSpline.def("RemoveKnot", (Standard_Boolean (Law_BSpline::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &Law_BSpline::RemoveKnot, "Decrement the knots multiplicity to <M>. If M is 0 the knot is removed. The Poles sequence is modified.", py::arg("Index"), py::arg("M"), py::arg("Tolerance"));
	cls_Law_BSpline.def("Reverse", (void (Law_BSpline::*)()) &Law_BSpline::Reverse, "Changes the direction of parametrization of <me>. The Knot sequence is modified, the FirstParameter and the LastParameter are not modified. The StartPoint of the initial curve becomes the EndPoint of the reversed curve and the EndPoint of the initial curve becomes the StartPoint of the reversed curve.");
	cls_Law_BSpline.def("ReversedParameter", (Standard_Real (Law_BSpline::*)(const Standard_Real) const ) &Law_BSpline::ReversedParameter, "Returns the parameter on the reversed curve for the point of parameter U on <me>.", py::arg("U"));
	cls_Law_BSpline.def("Segment", (void (Law_BSpline::*)(const Standard_Real, const Standard_Real)) &Law_BSpline::Segment, "Segments the curve between U1 and U2. The control points are modified, the first and the last point are not the same. Warnings : Even if <me> is not closed it can become closed after the segmentation for example if U1 or U2 are out of the bounds of the curve <me> or if the curve makes loop. After the segmentation the length of a curve can be null. raises if U2 < U1.", py::arg("U1"), py::arg("U2"));
	cls_Law_BSpline.def("SetKnot", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real)) &Law_BSpline::SetKnot, "Changes the knot of range Index. The multiplicity of the knot is not modified. Raised if K >= Knots(Index+1) or K <= Knots(Index-1). Raised if Index < 1 || Index > NbKnots", py::arg("Index"), py::arg("K"));
	cls_Law_BSpline.def("SetKnots", (void (Law_BSpline::*)(const TColStd_Array1OfReal &)) &Law_BSpline::SetKnots, "Changes all the knots of the curve The multiplicity of the knots are not modified.", py::arg("K"));
	cls_Law_BSpline.def("SetKnot", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real, const Standard_Integer)) &Law_BSpline::SetKnot, "Changes the knot of range Index with its multiplicity. You can increase the multiplicity of a knot but it is not allowed to decrease the multiplicity of an existing knot.", py::arg("Index"), py::arg("K"), py::arg("M"));
	cls_Law_BSpline.def("PeriodicNormalization", (void (Law_BSpline::*)(Standard_Real &) const ) &Law_BSpline::PeriodicNormalization, "returns the parameter normalized within the period if the curve is periodic : otherwise does not do anything", py::arg("U"));
	cls_Law_BSpline.def("SetPeriodic", (void (Law_BSpline::*)()) &Law_BSpline::SetPeriodic, "Makes a closed B-spline into a periodic curve. The curve is periodic if the knot sequence is periodic and if the curve is closed (The tolerance criterion is Resolution from gp). The period T is equal to Knot(LastUKnotIndex) - Knot(FirstUKnotIndex). A periodic B-spline can be uniform or not. Raised if the curve is not closed.");
	cls_Law_BSpline.def("SetOrigin", (void (Law_BSpline::*)(const Standard_Integer)) &Law_BSpline::SetOrigin, "Set the origin of a periodic curve at Knot(index) KnotVector and poles are modified. Raised if the curve is not periodic Raised if index not in the range [FirstUKnotIndex , LastUKnotIndex]", py::arg("Index"));
	cls_Law_BSpline.def("SetNotPeriodic", (void (Law_BSpline::*)()) &Law_BSpline::SetNotPeriodic, "Makes a non periodic curve. If the curve was non periodic the curve is not modified.");
	cls_Law_BSpline.def("SetPole", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real)) &Law_BSpline::SetPole, "Substitutes the Pole of range Index with P.", py::arg("Index"), py::arg("P"));
	cls_Law_BSpline.def("SetPole", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &Law_BSpline::SetPole, "Substitutes the pole and the weight of range Index. If the curve <me> is not rational it can become rational If the curve was rational it can become non rational", py::arg("Index"), py::arg("P"), py::arg("Weight"));
	cls_Law_BSpline.def("SetWeight", (void (Law_BSpline::*)(const Standard_Integer, const Standard_Real)) &Law_BSpline::SetWeight, "Changes the weight for the pole of range Index. If the curve was non rational it can become rational. If the curve was rational it can become non rational.", py::arg("Index"), py::arg("Weight"));
	cls_Law_BSpline.def("IsCN", (Standard_Boolean (Law_BSpline::*)(const Standard_Integer) const ) &Law_BSpline::IsCN, "Returns the continuity of the curve, the curve is at least C0. Raised if N < 0.", py::arg("N"));
	cls_Law_BSpline.def("IsClosed", (Standard_Boolean (Law_BSpline::*)() const ) &Law_BSpline::IsClosed, "Returns true if the distance between the first point and the last point of the curve is lower or equal to Resolution from package gp. Warnings : The first and the last point can be different from the first pole and the last pole of the curve.");
	cls_Law_BSpline.def("IsPeriodic", (Standard_Boolean (Law_BSpline::*)() const ) &Law_BSpline::IsPeriodic, "Returns True if the curve is periodic.");
	cls_Law_BSpline.def("IsRational", (Standard_Boolean (Law_BSpline::*)() const ) &Law_BSpline::IsRational, "Returns True if the weights are not identical. The tolerance criterion is Epsilon of the class Real.");
	cls_Law_BSpline.def("Continuity", (GeomAbs_Shape (Law_BSpline::*)() const ) &Law_BSpline::Continuity, "Returns the global continuity of the curve : C0 : only geometric continuity, C1 : continuity of the first derivative all along the Curve, C2 : continuity of the second derivative all along the Curve, C3 : continuity of the third derivative all along the Curve, CN : the order of continuity is infinite. For a B-spline curve of degree d if a knot Ui has a multiplicity p the B-spline curve is only Cd-p continuous at Ui. So the global continuity of the curve can't be greater than Cd-p where p is the maximum multiplicity of the interior Knots. In the interior of a knot span the curve is infinitely continuously differentiable.");
	cls_Law_BSpline.def("Degree", (Standard_Integer (Law_BSpline::*)() const ) &Law_BSpline::Degree, "Computation of value and derivatives");
	cls_Law_BSpline.def("Value", (Standard_Real (Law_BSpline::*)(const Standard_Real) const ) &Law_BSpline::Value, "None", py::arg("U"));
	cls_Law_BSpline.def("D0", (void (Law_BSpline::*)(const Standard_Real, Standard_Real &) const ) &Law_BSpline::D0, "None", py::arg("U"), py::arg("P"));
	cls_Law_BSpline.def("D1", (void (Law_BSpline::*)(const Standard_Real, Standard_Real &, Standard_Real &) const ) &Law_BSpline::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"));
	cls_Law_BSpline.def("D2", (void (Law_BSpline::*)(const Standard_Real, Standard_Real &, Standard_Real &, Standard_Real &) const ) &Law_BSpline::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Law_BSpline.def("D3", (void (Law_BSpline::*)(const Standard_Real, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &Law_BSpline::D3, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Law_BSpline.def("DN", (Standard_Real (Law_BSpline::*)(const Standard_Real, const Standard_Integer) const ) &Law_BSpline::DN, "The following functions computes the point of parameter U and the derivatives at this point on the B-spline curve arc defined between the knot FromK1 and the knot ToK2. U can be out of bounds [Knot (FromK1), Knot (ToK2)] but for the computation we only use the definition of the curve between these two knots. This method is useful to compute local derivative, if the order of continuity of the whole curve is not greater enough. Inside the parametric domain Knot (FromK1), Knot (ToK2) the evaluations are the same as if we consider the whole definition of the curve. Of course the evaluations are different outside this parametric domain.", py::arg("U"), py::arg("N"));
	cls_Law_BSpline.def("LocalValue", (Standard_Real (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &Law_BSpline::LocalValue, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"));
	cls_Law_BSpline.def("LocalD0", (void (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Integer, Standard_Real &) const ) &Law_BSpline::LocalD0, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("P"));
	cls_Law_BSpline.def("LocalD1", (void (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Integer, Standard_Real &, Standard_Real &) const ) &Law_BSpline::LocalD1, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("P"), py::arg("V1"));
	cls_Law_BSpline.def("LocalD2", (void (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &) const ) &Law_BSpline::LocalD2, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Law_BSpline.def("LocalD3", (void (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &Law_BSpline::LocalD3, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Law_BSpline.def("LocalDN", (Standard_Real (Law_BSpline::*)(const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &Law_BSpline::LocalDN, "None", py::arg("U"), py::arg("FromK1"), py::arg("ToK2"), py::arg("N"));
	cls_Law_BSpline.def("EndPoint", (Standard_Real (Law_BSpline::*)() const ) &Law_BSpline::EndPoint, "Returns the last point of the curve. Warnings : The last point of the curve is different from the last pole of the curve if the multiplicity of the last knot is lower than Degree.");
	cls_Law_BSpline.def("FirstUKnotIndex", (Standard_Integer (Law_BSpline::*)() const ) &Law_BSpline::FirstUKnotIndex, "For a B-spline curve the first parameter (which gives the start point of the curve) is a knot value but if the multiplicity of the first knot index is lower than Degree + 1 it is not the first knot of the curve. This method computes the index of the knot corresponding to the first parameter.");
	cls_Law_BSpline.def("FirstParameter", (Standard_Real (Law_BSpline::*)() const ) &Law_BSpline::FirstParameter, "Computes the parametric value of the start point of the curve. It is a knot value.");
	cls_Law_BSpline.def("Knot", (Standard_Real (Law_BSpline::*)(const Standard_Integer) const ) &Law_BSpline::Knot, "Returns the knot of range Index. When there is a knot with a multiplicity greater than 1 the knot is not repeated. The method Multiplicity can be used to get the multiplicity of the Knot. Raised if Index < 1 or Index > NbKnots", py::arg("Index"));
	cls_Law_BSpline.def("Knots", (void (Law_BSpline::*)(TColStd_Array1OfReal &) const ) &Law_BSpline::Knots, "returns the knot values of the B-spline curve;", py::arg("K"));
	cls_Law_BSpline.def("KnotSequence", (void (Law_BSpline::*)(TColStd_Array1OfReal &) const ) &Law_BSpline::KnotSequence, "Returns the knots sequence. In this sequence the knots with a multiplicity greater than 1 are repeated. Example : K = {k1, k1, k1, k2, k3, k3, k4, k4, k4}", py::arg("K"));
	cls_Law_BSpline.def("KnotDistribution", (GeomAbs_BSplKnotDistribution (Law_BSpline::*)() const ) &Law_BSpline::KnotDistribution, "Returns NonUniform or Uniform or QuasiUniform or PiecewiseBezier. If all the knots differ by a positive constant from the preceding knot the BSpline Curve can be : - Uniform if all the knots are of multiplicity 1, - QuasiUniform if all the knots are of multiplicity 1 except for the first and last knot which are of multiplicity Degree + 1, - PiecewiseBezier if the first and last knots have multiplicity Degree + 1 and if interior knots have multiplicity Degree A piecewise Bezier with only two knots is a BezierCurve. else the curve is non uniform. The tolerance criterion is Epsilon from class Real.");
	cls_Law_BSpline.def("LastUKnotIndex", (Standard_Integer (Law_BSpline::*)() const ) &Law_BSpline::LastUKnotIndex, "For a BSpline curve the last parameter (which gives the end point of the curve) is a knot value but if the multiplicity of the last knot index is lower than Degree + 1 it is not the last knot of the curve. This method computes the index of the knot corresponding to the last parameter.");
	cls_Law_BSpline.def("LastParameter", (Standard_Real (Law_BSpline::*)() const ) &Law_BSpline::LastParameter, "Computes the parametric value of the end point of the curve. It is a knot value.");
	cls_Law_BSpline.def("LocateU", [](Law_BSpline &self, const Standard_Real a0, const Standard_Real a1, Standard_Integer & a2, Standard_Integer & a3) -> void { return self.LocateU(a0, a1, a2, a3); }, py::arg("U"), py::arg("ParametricTolerance"), py::arg("I1"), py::arg("I2"));
	cls_Law_BSpline.def("LocateU", (void (Law_BSpline::*)(const Standard_Real, const Standard_Real, Standard_Integer &, Standard_Integer &, const Standard_Boolean) const ) &Law_BSpline::LocateU, "Locates the parametric value U in the sequence of knots. If 'WithKnotRepetition' is True we consider the knot's representation with repetition of multiple knot value, otherwise we consider the knot's representation with no repetition of multiple knot values. Knots (I1) <= U <= Knots (I2) . if I1 = I2 U is a knot value (the tolerance criterion ParametricTolerance is used). . if I1 < 1 => U < Knots (1) - Abs(ParametricTolerance) . if I2 > NbKnots => U > Knots (NbKnots) + Abs(ParametricTolerance)", py::arg("U"), py::arg("ParametricTolerance"), py::arg("I1"), py::arg("I2"), py::arg("WithKnotRepetition"));
	cls_Law_BSpline.def("Multiplicity", (Standard_Integer (Law_BSpline::*)(const Standard_Integer) const ) &Law_BSpline::Multiplicity, "Returns the multiplicity of the knots of range Index. Raised if Index < 1 or Index > NbKnots", py::arg("Index"));
	cls_Law_BSpline.def("Multiplicities", (void (Law_BSpline::*)(TColStd_Array1OfInteger &) const ) &Law_BSpline::Multiplicities, "Returns the multiplicity of the knots of the curve.", py::arg("M"));
	cls_Law_BSpline.def("NbKnots", (Standard_Integer (Law_BSpline::*)() const ) &Law_BSpline::NbKnots, "Returns the number of knots. This method returns the number of knot without repetition of multiple knots.");
	cls_Law_BSpline.def("NbPoles", (Standard_Integer (Law_BSpline::*)() const ) &Law_BSpline::NbPoles, "Returns the number of poles");
	cls_Law_BSpline.def("Pole", (Standard_Real (Law_BSpline::*)(const Standard_Integer) const ) &Law_BSpline::Pole, "Returns the pole of range Index. Raised if Index < 1 or Index > NbPoles.", py::arg("Index"));
	cls_Law_BSpline.def("Poles", (void (Law_BSpline::*)(TColStd_Array1OfReal &) const ) &Law_BSpline::Poles, "Returns the poles of the B-spline curve;", py::arg("P"));
	cls_Law_BSpline.def("StartPoint", (Standard_Real (Law_BSpline::*)() const ) &Law_BSpline::StartPoint, "Returns the start point of the curve. Warnings : This point is different from the first pole of the curve if the multiplicity of the first knot is lower than Degree.");
	cls_Law_BSpline.def("Weight", (Standard_Real (Law_BSpline::*)(const Standard_Integer) const ) &Law_BSpline::Weight, "Returns the weight of the pole of range Index . Raised if Index < 1 or Index > NbPoles.", py::arg("Index"));
	cls_Law_BSpline.def("Weights", (void (Law_BSpline::*)(TColStd_Array1OfReal &) const ) &Law_BSpline::Weights, "Returns the weights of the B-spline curve;", py::arg("W"));
	cls_Law_BSpline.def_static("MaxDegree_", (Standard_Integer (*)()) &Law_BSpline::MaxDegree, "Returns the value of the maximum degree of the normalized B-spline basis functions in this package.");
	cls_Law_BSpline.def("MovePointAndTangent", (void (Law_BSpline::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, Standard_Integer &)) &Law_BSpline::MovePointAndTangent, "Changes the value of the Law at parameter U to NewValue. and makes its derivative at U be derivative. StartingCondition = -1 means first can move EndingCondition = -1 means last point can move StartingCondition = 0 means the first point cannot move EndingCondition = 0 means the last point cannot move StartingCondition = 1 means the first point and tangent cannot move EndingCondition = 1 means the last point and tangent cannot move and so forth ErrorStatus != 0 means that there are not enought degree of freedom with the constrain to deform the curve accordingly", py::arg("U"), py::arg("NewValue"), py::arg("Derivative"), py::arg("Tolerance"), py::arg("StartingCondition"), py::arg("EndingCondition"), py::arg("ErrorStatus"));
	cls_Law_BSpline.def("Resolution", (void (Law_BSpline::*)(const Standard_Real, Standard_Real &) const ) &Law_BSpline::Resolution, "given Tolerance3D returns UTolerance such that if f(t) is the curve we have | t1 - t0| < Utolerance ===> |f(t1) - f(t0)| < Tolerance3D", py::arg("Tolerance3D"), py::arg("UTolerance"));
	cls_Law_BSpline.def("Copy", (opencascade::handle<Law_BSpline> (Law_BSpline::*)() const ) &Law_BSpline::Copy, "None");
	cls_Law_BSpline.def_static("get_type_name_", (const char * (*)()) &Law_BSpline::get_type_name, "None");
	cls_Law_BSpline.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_BSpline::get_type_descriptor, "None");
	cls_Law_BSpline.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_BSpline::*)() const ) &Law_BSpline::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_BSpFunc.hxx
	py::class_<Law_BSpFunc, opencascade::handle<Law_BSpFunc>, Law_Function> cls_Law_BSpFunc(mod, "Law_BSpFunc", "Law Function based on a BSpline curve 1d. Package methods and classes are implemented in package Law to construct the basis curve with several constraints.");
	cls_Law_BSpFunc.def(py::init<>());
	cls_Law_BSpFunc.def(py::init<const opencascade::handle<Law_BSpline> &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("First"), py::arg("Last"));
	cls_Law_BSpFunc.def("Continuity", (GeomAbs_Shape (Law_BSpFunc::*)() const ) &Law_BSpFunc::Continuity, "None");
	cls_Law_BSpFunc.def("NbIntervals", (Standard_Integer (Law_BSpFunc::*)(const GeomAbs_Shape) const ) &Law_BSpFunc::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_Law_BSpFunc.def("Intervals", (void (Law_BSpFunc::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Law_BSpFunc::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Law_BSpFunc.def("Value", (Standard_Real (Law_BSpFunc::*)(const Standard_Real)) &Law_BSpFunc::Value, "None", py::arg("X"));
	cls_Law_BSpFunc.def("D1", (void (Law_BSpFunc::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &Law_BSpFunc::D1, "None", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_Law_BSpFunc.def("D2", (void (Law_BSpFunc::*)(const Standard_Real, Standard_Real &, Standard_Real &, Standard_Real &)) &Law_BSpFunc::D2, "None", py::arg("X"), py::arg("F"), py::arg("D"), py::arg("D2"));
	cls_Law_BSpFunc.def("Trim", (opencascade::handle<Law_Function> (Law_BSpFunc::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Law_BSpFunc::Trim, "Returns a law equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. It is usfule to determines the derivatives in these values <First> and <Last> if the Law is not Cn.", py::arg("PFirst"), py::arg("PLast"), py::arg("Tol"));
	cls_Law_BSpFunc.def("Bounds", (void (Law_BSpFunc::*)(Standard_Real &, Standard_Real &)) &Law_BSpFunc::Bounds, "None", py::arg("PFirst"), py::arg("PLast"));
	cls_Law_BSpFunc.def("Curve", (opencascade::handle<Law_BSpline> (Law_BSpFunc::*)() const ) &Law_BSpFunc::Curve, "None");
	cls_Law_BSpFunc.def("SetCurve", (void (Law_BSpFunc::*)(const opencascade::handle<Law_BSpline> &)) &Law_BSpFunc::SetCurve, "None", py::arg("C"));
	cls_Law_BSpFunc.def_static("get_type_name_", (const char * (*)()) &Law_BSpFunc::get_type_name, "None");
	cls_Law_BSpFunc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_BSpFunc::get_type_descriptor, "None");
	cls_Law_BSpFunc.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_BSpFunc::*)() const ) &Law_BSpFunc::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_Linear.hxx
	py::class_<Law_Linear, opencascade::handle<Law_Linear>, Law_Function> cls_Law_Linear(mod, "Law_Linear", "Describes an linear evolution law.");
	cls_Law_Linear.def(py::init<>());
	cls_Law_Linear.def("Set", (void (Law_Linear::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Law_Linear::Set, "Defines this linear evolution law by assigning both: - the bounds Pdeb and Pfin of the parameter, and - the values Valdeb and Valfin of the function at these two parametric bounds.", py::arg("Pdeb"), py::arg("Valdeb"), py::arg("Pfin"), py::arg("Valfin"));
	cls_Law_Linear.def("Continuity", (GeomAbs_Shape (Law_Linear::*)() const ) &Law_Linear::Continuity, "Returns GeomAbs_CN");
	cls_Law_Linear.def("NbIntervals", (Standard_Integer (Law_Linear::*)(const GeomAbs_Shape) const ) &Law_Linear::NbIntervals, "Returns 1", py::arg("S"));
	cls_Law_Linear.def("Intervals", (void (Law_Linear::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Law_Linear::Intervals, "None", py::arg("T"), py::arg("S"));
	cls_Law_Linear.def("Value", (Standard_Real (Law_Linear::*)(const Standard_Real)) &Law_Linear::Value, "Returns the value of this function at the point of parameter X.", py::arg("X"));
	cls_Law_Linear.def("D1", (void (Law_Linear::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &Law_Linear::D1, "Returns the value F and the first derivative D of this function at the point of parameter X.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_Law_Linear.def("D2", (void (Law_Linear::*)(const Standard_Real, Standard_Real &, Standard_Real &, Standard_Real &)) &Law_Linear::D2, "Returns the value, first and second derivatives at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"), py::arg("D2"));
	cls_Law_Linear.def("Trim", (opencascade::handle<Law_Function> (Law_Linear::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Law_Linear::Trim, "Returns a law equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion. It is usfule to determines the derivatives in these values <First> and <Last> if the Law is not Cn.", py::arg("PFirst"), py::arg("PLast"), py::arg("Tol"));
	cls_Law_Linear.def("Bounds", (void (Law_Linear::*)(Standard_Real &, Standard_Real &)) &Law_Linear::Bounds, "Returns the parametric bounds of the function.", py::arg("PFirst"), py::arg("PLast"));
	cls_Law_Linear.def_static("get_type_name_", (const char * (*)()) &Law_Linear::get_type_name, "None");
	cls_Law_Linear.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_Linear::get_type_descriptor, "None");
	cls_Law_Linear.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_Linear::*)() const ) &Law_Linear::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_Interpolate.hxx
	py::class_<Law_Interpolate, std::unique_ptr<Law_Interpolate, Deleter<Law_Interpolate>>> cls_Law_Interpolate(mod, "Law_Interpolate", "This class is used to interpolate a BsplineCurve passing through an array of points, with a C2 Continuity if tangency is not requested at the point. If tangency is requested at the point the continuity will be C1. If Perodicity is requested the curve will be closed and the junction will be the first point given. The curve will than be only C1");
	cls_Law_Interpolate.def(py::init<const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Boolean, const Standard_Real>(), py::arg("Points"), py::arg("PeriodicFlag"), py::arg("Tolerance"));
	cls_Law_Interpolate.def(py::init<const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Boolean, const Standard_Real>(), py::arg("Points"), py::arg("Parameters"), py::arg("PeriodicFlag"), py::arg("Tolerance"));
	cls_Law_Interpolate.def("Load", (void (Law_Interpolate::*)(const Standard_Real, const Standard_Real)) &Law_Interpolate::Load, "loads initial and final tangents if any.", py::arg("InitialTangent"), py::arg("FinalTangent"));
	cls_Law_Interpolate.def("Load", (void (Law_Interpolate::*)(const TColStd_Array1OfReal &, const opencascade::handle<TColStd_HArray1OfBoolean> &)) &Law_Interpolate::Load, "loads the tangents. We should have as many tangents as they are points in the array if TangentFlags.Value(i) is Standard_True use the tangent Tangents.Value(i) otherwise the tangent is not constrained.", py::arg("Tangents"), py::arg("TangentFlags"));
	cls_Law_Interpolate.def("ClearTangents", (void (Law_Interpolate::*)()) &Law_Interpolate::ClearTangents, "Clears the tangents if any");
	cls_Law_Interpolate.def("Perform", (void (Law_Interpolate::*)()) &Law_Interpolate::Perform, "Makes the interpolation");
	cls_Law_Interpolate.def("Curve", (const opencascade::handle<Law_BSpline> & (Law_Interpolate::*)() const ) &Law_Interpolate::Curve, "None");
	cls_Law_Interpolate.def("IsDone", (Standard_Boolean (Law_Interpolate::*)() const ) &Law_Interpolate::IsDone, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_Constant.hxx
	py::class_<Law_Constant, opencascade::handle<Law_Constant>, Law_Function> cls_Law_Constant(mod, "Law_Constant", "Loi constante");
	cls_Law_Constant.def(py::init<>());
	cls_Law_Constant.def("Set", (void (Law_Constant::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Law_Constant::Set, "Set the radius and the range of the constant Law.", py::arg("Radius"), py::arg("PFirst"), py::arg("PLast"));
	cls_Law_Constant.def("Continuity", (GeomAbs_Shape (Law_Constant::*)() const ) &Law_Constant::Continuity, "Returns GeomAbs_CN");
	cls_Law_Constant.def("NbIntervals", (Standard_Integer (Law_Constant::*)(const GeomAbs_Shape) const ) &Law_Constant::NbIntervals, "Returns 1", py::arg("S"));
	cls_Law_Constant.def("Intervals", (void (Law_Constant::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Law_Constant::Intervals, "None", py::arg("T"), py::arg("S"));
	cls_Law_Constant.def("Value", (Standard_Real (Law_Constant::*)(const Standard_Real)) &Law_Constant::Value, "Returns the value at parameter X.", py::arg("X"));
	cls_Law_Constant.def("D1", (void (Law_Constant::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &Law_Constant::D1, "Returns the value and the first derivative at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_Law_Constant.def("D2", (void (Law_Constant::*)(const Standard_Real, Standard_Real &, Standard_Real &, Standard_Real &)) &Law_Constant::D2, "Returns the value, first and second derivatives at parameter X.", py::arg("X"), py::arg("F"), py::arg("D"), py::arg("D2"));
	cls_Law_Constant.def("Trim", (opencascade::handle<Law_Function> (Law_Constant::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &Law_Constant::Trim, "None", py::arg("PFirst"), py::arg("PLast"), py::arg("Tol"));
	cls_Law_Constant.def("Bounds", (void (Law_Constant::*)(Standard_Real &, Standard_Real &)) &Law_Constant::Bounds, "Returns the parametric bounds of the function.", py::arg("PFirst"), py::arg("PLast"));
	cls_Law_Constant.def_static("get_type_name_", (const char * (*)()) &Law_Constant::get_type_name, "None");
	cls_Law_Constant.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_Constant::get_type_descriptor, "None");
	cls_Law_Constant.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_Constant::*)() const ) &Law_Constant::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_S.hxx
	py::class_<Law_S, opencascade::handle<Law_S>, Law_BSpFunc> cls_Law_S(mod, "Law_S", "Describes an 'S' evolution law.");
	cls_Law_S.def(py::init<>());
	cls_Law_S.def("Set", (void (Law_S::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Law_S::Set, "Defines this S evolution law by assigning both: - the bounds Pdeb and Pfin of the parameter, and - the values Valdeb and Valfin of the function at these two parametric bounds. The function is assumed to have the first derivatives equal to 0 at the two parameter points Pdeb and Pfin.", py::arg("Pdeb"), py::arg("Valdeb"), py::arg("Pfin"), py::arg("Valfin"));
	cls_Law_S.def("Set", (void (Law_S::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Law_S::Set, "Defines this S evolution law by assigning - the bounds Pdeb and Pfin of the parameter, - the values Valdeb and Valfin of the function at these two parametric bounds, and - the values Ddeb and Dfin of the first derivative of the function at these two parametric bounds.", py::arg("Pdeb"), py::arg("Valdeb"), py::arg("Ddeb"), py::arg("Pfin"), py::arg("Valfin"), py::arg("Dfin"));
	cls_Law_S.def_static("get_type_name_", (const char * (*)()) &Law_S::get_type_name, "None");
	cls_Law_S.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_S::get_type_descriptor, "None");
	cls_Law_S.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_S::*)() const ) &Law_S::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_Interpol.hxx
	py::class_<Law_Interpol, opencascade::handle<Law_Interpol>, Law_BSpFunc> cls_Law_Interpol(mod, "Law_Interpol", "Provides an evolution law that interpolates a set of parameter and value pairs (wi, radi)");
	cls_Law_Interpol.def(py::init<>());
	cls_Law_Interpol.def("Set", [](Law_Interpol &self, const TColgp_Array1OfPnt2d & a0) -> void { return self.Set(a0); }, py::arg("ParAndRad"));
	cls_Law_Interpol.def("Set", (void (Law_Interpol::*)(const TColgp_Array1OfPnt2d &, const Standard_Boolean)) &Law_Interpol::Set, "Defines this evolution law by interpolating the set of 2D points ParAndRad. The Y coordinate of a point of ParAndRad is the value of the function at the parameter point given by its X coordinate. If Periodic is true, this function is assumed to be periodic. Warning - The X coordinates of points in the table ParAndRad must be given in ascendant order. - If Periodic is true, the first and last Y coordinates of points in the table ParAndRad are assumed to be equal. In addition, with the second syntax, Dd and Df are also assumed to be equal. If this is not the case, Set uses the first value(s) as last value(s).", py::arg("ParAndRad"), py::arg("Periodic"));
	cls_Law_Interpol.def("SetInRelative", [](Law_Interpol &self, const TColgp_Array1OfPnt2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetInRelative(a0, a1, a2); }, py::arg("ParAndRad"), py::arg("Ud"), py::arg("Uf"));
	cls_Law_Interpol.def("SetInRelative", (void (Law_Interpol::*)(const TColgp_Array1OfPnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Law_Interpol::SetInRelative, "None", py::arg("ParAndRad"), py::arg("Ud"), py::arg("Uf"), py::arg("Periodic"));
	cls_Law_Interpol.def("Set", [](Law_Interpol &self, const TColgp_Array1OfPnt2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Set(a0, a1, a2); }, py::arg("ParAndRad"), py::arg("Dd"), py::arg("Df"));
	cls_Law_Interpol.def("Set", (void (Law_Interpol::*)(const TColgp_Array1OfPnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Law_Interpol::Set, "Defines this evolution law by interpolating the set of 2D points ParAndRad. The Y coordinate of a point of ParAndRad is the value of the function at the parameter point given by its X coordinate. If Periodic is true, this function is assumed to be periodic. In the second syntax, Dd and Df define the values of the first derivative of the function at its first and last points. Warning - The X coordinates of points in the table ParAndRad must be given in ascendant order. - If Periodic is true, the first and last Y coordinates of points in the table ParAndRad are assumed to be equal. In addition, with the second syntax, Dd and Df are also assumed to be equal. If this is not the case, Set uses the first value(s) as last value(s).", py::arg("ParAndRad"), py::arg("Dd"), py::arg("Df"), py::arg("Periodic"));
	cls_Law_Interpol.def("SetInRelative", [](Law_Interpol &self, const TColgp_Array1OfPnt2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.SetInRelative(a0, a1, a2, a3, a4); }, py::arg("ParAndRad"), py::arg("Ud"), py::arg("Uf"), py::arg("Dd"), py::arg("Df"));
	cls_Law_Interpol.def("SetInRelative", (void (Law_Interpol::*)(const TColgp_Array1OfPnt2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Law_Interpol::SetInRelative, "None", py::arg("ParAndRad"), py::arg("Ud"), py::arg("Uf"), py::arg("Dd"), py::arg("Df"), py::arg("Periodic"));
	cls_Law_Interpol.def_static("get_type_name_", (const char * (*)()) &Law_Interpol::get_type_name, "None");
	cls_Law_Interpol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Law_Interpol::get_type_descriptor, "None");
	cls_Law_Interpol.def("DynamicType", (const opencascade::handle<Standard_Type> & (Law_Interpol::*)() const ) &Law_Interpol::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law_BSplineKnotSplitting.hxx
	py::class_<Law_BSplineKnotSplitting, std::unique_ptr<Law_BSplineKnotSplitting, Deleter<Law_BSplineKnotSplitting>>> cls_Law_BSplineKnotSplitting(mod, "Law_BSplineKnotSplitting", "For a B-spline curve the discontinuities are localised at the knot values and between two knots values the B-spline is infinitely continuously differentiable. At a knot of range index the continuity is equal to : Degree - Mult (Index) where Degree is the degree of the basis B-spline functions and Mult the multiplicity of the knot of range Index. If for your computation you need to have B-spline curves with a minima of continuity it can be interesting to know between which knot values, a B-spline curve arc, has a continuity of given order. This algorithm computes the indexes of the knots where you should split the curve, to obtain arcs with a constant continuity given at the construction time. The splitting values are in the range [FirstUKnotValue, LastUKnotValue] (See class B-spline curve from package Geom). If you just want to compute the local derivatives on the curve you don't need to create the B-spline curve arcs, you can use the functions LocalD1, LocalD2, LocalD3, LocalDN of the class BSplineCurve.");
	cls_Law_BSplineKnotSplitting.def(py::init<const opencascade::handle<Law_BSpline> &, const Standard_Integer>(), py::arg("BasisLaw"), py::arg("ContinuityRange"));
	cls_Law_BSplineKnotSplitting.def("NbSplits", (Standard_Integer (Law_BSplineKnotSplitting::*)() const ) &Law_BSplineKnotSplitting::NbSplits, "Returns the number of knots corresponding to the splitting.");
	cls_Law_BSplineKnotSplitting.def("Splitting", (void (Law_BSplineKnotSplitting::*)(TColStd_Array1OfInteger &) const ) &Law_BSplineKnotSplitting::Splitting, "Returns the indexes of the BSpline curve knots corresponding to the splitting.", py::arg("SplitValues"));
	cls_Law_BSplineKnotSplitting.def("SplitValue", (Standard_Integer (Law_BSplineKnotSplitting::*)(const Standard_Integer) const ) &Law_BSplineKnotSplitting::SplitValue, "Returns the index of the knot corresponding to the splitting of range Index.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Law.hxx
	py::class_<Law, std::unique_ptr<Law, Deleter<Law>>> cls_Law(mod, "Law", "Multiple services concerning 1d functions.");
	cls_Law.def(py::init<>());
	cls_Law.def_static("MixBnd_", (opencascade::handle<Law_BSpFunc> (*)(const opencascade::handle<Law_Linear> &)) &Law::MixBnd, "This algorithm searches the knot values corresponding to the splitting of a given B-spline law into several arcs with the same continuity. The continuity order is given at the construction time. Builds a 1d bspline that is near from Lin with null derivatives at the extremities.", py::arg("Lin"));
	cls_Law.def_static("MixBnd_", (opencascade::handle<TColStd_HArray1OfReal> (*)(const Standard_Integer, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const opencascade::handle<Law_Linear> &)) &Law::MixBnd, "Builds the poles of the 1d bspline that is near from Lin with null derivatives at the extremities.", py::arg("Degree"), py::arg("Knots"), py::arg("Mults"), py::arg("Lin"));
	cls_Law.def_static("MixTgt_", (opencascade::handle<TColStd_HArray1OfReal> (*)(const Standard_Integer, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &, const Standard_Boolean, const Standard_Integer)) &Law::MixTgt, "Builds the poles of the 1d bspline that is null on the rigth side of Knots(Index) (on the left if NulOnTheRight is false) and that is like a t*(1-t)(1-t) curve on the left side of Knots(Index) (on the rigth if NulOnTheRight is false). The result curve is C1 with a derivative equal to 1. at first parameter (-1 at last parameter if NulOnTheRight is false). Warning: Mults(Index) must greater or equal to degree-1.", py::arg("Degree"), py::arg("Knots"), py::arg("Mults"), py::arg("NulOnTheRight"), py::arg("Index"));
	cls_Law.def_static("Reparametrize_", (opencascade::handle<Law_BSpline> (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer)) &Law::Reparametrize, "Computes a 1 d curve to reparametrize a curve. Its an interpolation of NbPoints points calculated at quasi constant abscissa.", py::arg("Curve"), py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DFirst"), py::arg("DLast"), py::arg("Rev"), py::arg("NbPoints"));
	cls_Law.def_static("Scale_", (opencascade::handle<Law_BSpline> (*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real)) &Law::Scale, "Computes a 1 d curve to scale a field of tangency. Value is 1. for t = (First+Last)/2 . If HasFirst value for t = First is VFirst (null derivative). If HasLast value for t = Last is VLast (null derivative).", py::arg("First"), py::arg("Last"), py::arg("HasF"), py::arg("HasL"), py::arg("VFirst"), py::arg("VLast"));
	cls_Law.def_static("ScaleCub_", (opencascade::handle<Law_BSpline> (*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real)) &Law::ScaleCub, "None", py::arg("First"), py::arg("Last"), py::arg("HasF"), py::arg("HasL"), py::arg("VFirst"), py::arg("VLast"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<Law_Laws, std::unique_ptr<Law_Laws, Deleter<Law_Laws>>, NCollection_BaseList> cls_Law_Laws(mod, "Law_Laws", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_Law_Laws.def(py::init<>());
	cls_Law_Laws.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Law_Laws.def(py::init([] (const Law_Laws &other) {return new Law_Laws(other);}), "Copy constructor", py::arg("other"));
	cls_Law_Laws.def("begin", (Law_Laws::iterator (Law_Laws::*)() const ) &Law_Laws::begin, "Returns an iterator pointing to the first element in the list.");
	cls_Law_Laws.def("end", (Law_Laws::iterator (Law_Laws::*)() const ) &Law_Laws::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_Law_Laws.def("cbegin", (Law_Laws::const_iterator (Law_Laws::*)() const ) &Law_Laws::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_Law_Laws.def("cend", (Law_Laws::const_iterator (Law_Laws::*)() const ) &Law_Laws::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_Law_Laws.def("Size", (Standard_Integer (Law_Laws::*)() const ) &Law_Laws::Size, "Size - Number of items");
	cls_Law_Laws.def("Assign", (Law_Laws & (Law_Laws::*)(const Law_Laws &)) &Law_Laws::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_Law_Laws.def("assign", (Law_Laws & (Law_Laws::*)(const Law_Laws &)) &Law_Laws::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Law_Laws.def("Clear", [](Law_Laws &self) -> void { return self.Clear(); });
	cls_Law_Laws.def("Clear", (void (Law_Laws::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Law_Laws::Clear, "Clear this list", py::arg("theAllocator"));
	cls_Law_Laws.def("First", (const opencascade::handle<Law_Function> & (Law_Laws::*)() const ) &Law_Laws::First, "First item");
	cls_Law_Laws.def("First", (opencascade::handle<Law_Function> & (Law_Laws::*)()) &Law_Laws::First, "First item (non-const)");
	cls_Law_Laws.def("Last", (const opencascade::handle<Law_Function> & (Law_Laws::*)() const ) &Law_Laws::Last, "Last item");
	cls_Law_Laws.def("Last", (opencascade::handle<Law_Function> & (Law_Laws::*)()) &Law_Laws::Last, "Last item (non-const)");
	cls_Law_Laws.def("Append", (opencascade::handle<Law_Function> & (Law_Laws::*)(const opencascade::handle<Law_Function> &)) &Law_Laws::Append, "Append one item at the end", py::arg("theItem"));
	cls_Law_Laws.def("Append", (void (Law_Laws::*)(const opencascade::handle<Law_Function> &, Law_Laws::Iterator &)) &Law_Laws::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_Law_Laws.def("Append", (void (Law_Laws::*)(Law_Laws &)) &Law_Laws::Append, "Append another list at the end", py::arg("theOther"));
	cls_Law_Laws.def("Prepend", (opencascade::handle<Law_Function> & (Law_Laws::*)(const opencascade::handle<Law_Function> &)) &Law_Laws::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_Law_Laws.def("Prepend", (void (Law_Laws::*)(Law_Laws &)) &Law_Laws::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_Law_Laws.def("RemoveFirst", (void (Law_Laws::*)()) &Law_Laws::RemoveFirst, "RemoveFirst item");
	cls_Law_Laws.def("Remove", (void (Law_Laws::*)(Law_Laws::Iterator &)) &Law_Laws::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_Law_Laws.def("InsertBefore", (opencascade::handle<Law_Function> & (Law_Laws::*)(const opencascade::handle<Law_Function> &, Law_Laws::Iterator &)) &Law_Laws::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_Law_Laws.def("InsertBefore", (void (Law_Laws::*)(Law_Laws &, Law_Laws::Iterator &)) &Law_Laws::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_Law_Laws.def("InsertAfter", (opencascade::handle<Law_Function> & (Law_Laws::*)(const opencascade::handle<Law_Function> &, Law_Laws::Iterator &)) &Law_Laws::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_Law_Laws.def("InsertAfter", (void (Law_Laws::*)(Law_Laws &, Law_Laws::Iterator &)) &Law_Laws::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_Law_Laws.def("Reverse", (void (Law_Laws::*)()) &Law_Laws::Reverse, "Reverse the list");
	cls_Law_Laws.def("__iter__", [](const Law_Laws &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<Law_ListIteratorOfLaws, std::unique_ptr<Law_ListIteratorOfLaws, Deleter<Law_ListIteratorOfLaws>>> cls_Law_ListIteratorOfLaws(mod, "Law_ListIteratorOfLaws", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_Law_ListIteratorOfLaws.def(py::init<>());
	cls_Law_ListIteratorOfLaws.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_Law_ListIteratorOfLaws.def("More", (Standard_Boolean (Law_ListIteratorOfLaws::*)() const ) &Law_ListIteratorOfLaws::More, "Check end");
	cls_Law_ListIteratorOfLaws.def("Next", (void (Law_ListIteratorOfLaws::*)()) &Law_ListIteratorOfLaws::Next, "Make step");
	cls_Law_ListIteratorOfLaws.def("Value", (const opencascade::handle<Law_Function> & (Law_ListIteratorOfLaws::*)() const ) &Law_ListIteratorOfLaws::Value, "Constant Value access");
	cls_Law_ListIteratorOfLaws.def("Value", (opencascade::handle<Law_Function> & (Law_ListIteratorOfLaws::*)()) &Law_ListIteratorOfLaws::Value, "Non-const Value access");
	cls_Law_ListIteratorOfLaws.def("ChangeValue", (opencascade::handle<Law_Function> & (Law_ListIteratorOfLaws::*)() const ) &Law_ListIteratorOfLaws::ChangeValue, "Non-const Value access");


}
