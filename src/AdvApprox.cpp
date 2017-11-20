#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <AdvApprox_Cutting.hxx>
#include <AdvApprox_EvaluatorFunction.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_OStream.hxx>
#include <AdvApprox_ApproxAFunction.hxx>
#include <AdvApprox_DichoCutting.hxx>
#include <AdvApprox_PrefAndRec.hxx>
#include <AdvApprox_PrefCutting.hxx>
#include <PLib_JacobiPolynomial.hxx>
#include <AdvApprox_SimpleApprox.hxx>

PYBIND11_MODULE(AdvApprox, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.PLib");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\AdvApprox_Cutting.hxx
	py::class_<AdvApprox_Cutting, std::unique_ptr<AdvApprox_Cutting, Deleter<AdvApprox_Cutting>>> cls_AdvApprox_Cutting(mod, "AdvApprox_Cutting", "to choose the way of cutting in approximation");
	cls_AdvApprox_Cutting.def("Value", [](AdvApprox_Cutting &self, const Standard_Real a, const Standard_Real b, Standard_Real & cuttingvalue){ Standard_Boolean rv = self.Value(a, b, cuttingvalue); return std::tuple<Standard_Boolean, Standard_Real &>(rv, cuttingvalue); }, "None", py::arg("a"), py::arg("b"), py::arg("cuttingvalue"));

	// Callback for AdvApprox_EvaluatorFunction.
	class PyCallback_AdvApprox_EvaluatorFunction : public AdvApprox_EvaluatorFunction {
	public:
		using AdvApprox_EvaluatorFunction::AdvApprox_EvaluatorFunction;

		void Evaluate(Standard_Integer * Dimension, Standard_Real  StartEnd[2], Standard_Real * Parameter, Standard_Integer * DerivativeRequest, Standard_Real * Result, Standard_Integer * ErrorCode) override { PYBIND11_OVERLOAD_PURE(void, AdvApprox_EvaluatorFunction, Evaluate, Dimension, StartEnd, Parameter, DerivativeRequest, Result, ErrorCode); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\AdvApprox_EvaluatorFunction.hxx
	py::class_<AdvApprox_EvaluatorFunction, std::unique_ptr<AdvApprox_EvaluatorFunction, Deleter<AdvApprox_EvaluatorFunction>>, PyCallback_AdvApprox_EvaluatorFunction> cls_AdvApprox_EvaluatorFunction(mod, "AdvApprox_EvaluatorFunction", "Interface for a class implementing a function to be approximated by AdvApprox_ApproxAFunction");
	cls_AdvApprox_EvaluatorFunction.def(py::init<>());
	// FIXME 	cls_AdvApprox_EvaluatorFunction.def("Evaluate", [](AdvApprox_EvaluatorFunction &self, Standard_Integer * Dimension, Standard_Real [2] StartEnd, Standard_Real * Parameter, Standard_Integer * DerivativeRequest, Standard_Real * Result, Standard_Integer * ErrorCode){ self.Evaluate(Dimension, StartEnd, Parameter, DerivativeRequest, Result, ErrorCode); return std::tuple<Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *>(Dimension, Parameter, DerivativeRequest, Result, ErrorCode); }, "Function evaluation method to be defined by descendant", py::arg("Dimension"), py::arg("StartEnd"), py::arg("Parameter"), py::arg("DerivativeRequest"), py::arg("Result"), py::arg("ErrorCode"));
	// FIXME cls_AdvApprox_EvaluatorFunction.def("__call__", (void (AdvApprox_EvaluatorFunction::*)(Standard_Integer *, Standard_Real [2], Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *)) &AdvApprox_EvaluatorFunction::operator(), py::is_operator(), "Shortcut for function-call style usage", py::arg("Dimension"), py::arg("StartEnd"), py::arg("Parameter"), py::arg("DerivativeRequest"), py::arg("Result"), py::arg("ErrorCode"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\AdvApprox_ApproxAFunction.hxx
	py::class_<AdvApprox_ApproxAFunction, std::unique_ptr<AdvApprox_ApproxAFunction, Deleter<AdvApprox_ApproxAFunction>>> cls_AdvApprox_ApproxAFunction(mod, "AdvApprox_ApproxAFunction", "this approximate a given function");
	cls_AdvApprox_ApproxAFunction.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const AdvApprox_EvaluatorFunction &>(), py::arg("Num1DSS"), py::arg("Num2DSS"), py::arg("Num3DSS"), py::arg("OneDTol"), py::arg("TwoDTol"), py::arg("ThreeDTol"), py::arg("First"), py::arg("Last"), py::arg("Continuity"), py::arg("MaxDeg"), py::arg("MaxSeg"), py::arg("Func"));
	cls_AdvApprox_ApproxAFunction.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const AdvApprox_EvaluatorFunction &, const AdvApprox_Cutting &>(), py::arg("Num1DSS"), py::arg("Num2DSS"), py::arg("Num3DSS"), py::arg("OneDTol"), py::arg("TwoDTol"), py::arg("ThreeDTol"), py::arg("First"), py::arg("Last"), py::arg("Continuity"), py::arg("MaxDeg"), py::arg("MaxSeg"), py::arg("Func"), py::arg("CutTool"));
	cls_AdvApprox_ApproxAFunction.def_static("Approximation_", [](const Standard_Integer TotalDimension, const Standard_Integer TotalNumSS, const TColStd_Array1OfInteger & LocalDimension, const Standard_Real First, const Standard_Real Last, AdvApprox_EvaluatorFunction & Evaluator, const AdvApprox_Cutting & CutTool, const Standard_Integer ContinuityOrder, const Standard_Integer NumMaxCoeffs, const Standard_Integer MaxSegments, const TColStd_Array1OfReal & TolerancesArray, const Standard_Integer code_precis, Standard_Integer & NumCurves, TColStd_Array1OfInteger & NumCoeffPerCurveArray, TColStd_Array1OfReal & LocalCoefficientArray, TColStd_Array1OfReal & IntervalsArray, TColStd_Array1OfReal & ErrorMaxArray, TColStd_Array1OfReal & AverageErrorArray, Standard_Integer & ErrorCode){ AdvApprox_ApproxAFunction::Approximation(TotalDimension, TotalNumSS, LocalDimension, First, Last, Evaluator, CutTool, ContinuityOrder, NumMaxCoeffs, MaxSegments, TolerancesArray, code_precis, NumCurves, NumCoeffPerCurveArray, LocalCoefficientArray, IntervalsArray, ErrorMaxArray, AverageErrorArray, ErrorCode); return std::tuple<Standard_Integer &, Standard_Integer &>(NumCurves, ErrorCode); }, "None", py::arg("TotalDimension"), py::arg("TotalNumSS"), py::arg("LocalDimension"), py::arg("First"), py::arg("Last"), py::arg("Evaluator"), py::arg("CutTool"), py::arg("ContinuityOrder"), py::arg("NumMaxCoeffs"), py::arg("MaxSegments"), py::arg("TolerancesArray"), py::arg("code_precis"), py::arg("NumCurves"), py::arg("NumCoeffPerCurveArray"), py::arg("LocalCoefficientArray"), py::arg("IntervalsArray"), py::arg("ErrorMaxArray"), py::arg("AverageErrorArray"), py::arg("ErrorCode"));
	cls_AdvApprox_ApproxAFunction.def("IsDone", (Standard_Boolean (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::IsDone, "None");
	cls_AdvApprox_ApproxAFunction.def("HasResult", (Standard_Boolean (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::HasResult, "None");
	cls_AdvApprox_ApproxAFunction.def("Poles1d", (opencascade::handle<TColStd_HArray2OfReal> (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::Poles1d, "returns the poles from the algorithms as is");
	cls_AdvApprox_ApproxAFunction.def("Poles2d", (opencascade::handle<TColgp_HArray2OfPnt2d> (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::Poles2d, "returns the poles from the algorithms as is");
	cls_AdvApprox_ApproxAFunction.def("Poles", (opencascade::handle<TColgp_HArray2OfPnt> (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::Poles, "-- returns the poles from the algorithms as is");
	cls_AdvApprox_ApproxAFunction.def("NbPoles", (Standard_Integer (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::NbPoles, "as the name says");
	cls_AdvApprox_ApproxAFunction.def("Poles1d", (void (AdvApprox_ApproxAFunction::*)(const Standard_Integer, TColStd_Array1OfReal &) const ) &AdvApprox_ApproxAFunction::Poles1d, "returns the poles at Index from the 1d subspace", py::arg("Index"), py::arg("P"));
	cls_AdvApprox_ApproxAFunction.def("Poles2d", (void (AdvApprox_ApproxAFunction::*)(const Standard_Integer, TColgp_Array1OfPnt2d &) const ) &AdvApprox_ApproxAFunction::Poles2d, "returns the poles at Index from the 2d subspace", py::arg("Index"), py::arg("P"));
	cls_AdvApprox_ApproxAFunction.def("Poles", (void (AdvApprox_ApproxAFunction::*)(const Standard_Integer, TColgp_Array1OfPnt &) const ) &AdvApprox_ApproxAFunction::Poles, "returns the poles at Index from the 3d subspace", py::arg("Index"), py::arg("P"));
	cls_AdvApprox_ApproxAFunction.def("Degree", (Standard_Integer (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::Degree, "None");
	cls_AdvApprox_ApproxAFunction.def("NbKnots", (Standard_Integer (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::NbKnots, "None");
	cls_AdvApprox_ApproxAFunction.def("NumSubSpaces", (Standard_Integer (AdvApprox_ApproxAFunction::*)(const Standard_Integer) const ) &AdvApprox_ApproxAFunction::NumSubSpaces, "None", py::arg("Dimension"));
	cls_AdvApprox_ApproxAFunction.def("Knots", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::Knots, "None");
	cls_AdvApprox_ApproxAFunction.def("Multiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (AdvApprox_ApproxAFunction::*)() const ) &AdvApprox_ApproxAFunction::Multiplicities, "None");
	cls_AdvApprox_ApproxAFunction.def("MaxError", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_ApproxAFunction::*)(const Standard_Integer) const ) &AdvApprox_ApproxAFunction::MaxError, "returns the error as is in the algorithms", py::arg("Dimension"));
	cls_AdvApprox_ApproxAFunction.def("AverageError", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_ApproxAFunction::*)(const Standard_Integer) const ) &AdvApprox_ApproxAFunction::AverageError, "returns the error as is in the algorithms", py::arg("Dimension"));
	cls_AdvApprox_ApproxAFunction.def("MaxError", (Standard_Real (AdvApprox_ApproxAFunction::*)(const Standard_Integer, const Standard_Integer) const ) &AdvApprox_ApproxAFunction::MaxError, "None", py::arg("Dimension"), py::arg("Index"));
	cls_AdvApprox_ApproxAFunction.def("AverageError", (Standard_Real (AdvApprox_ApproxAFunction::*)(const Standard_Integer, const Standard_Integer) const ) &AdvApprox_ApproxAFunction::AverageError, "None", py::arg("Dimension"), py::arg("Index"));
	// FIXME cls_AdvApprox_ApproxAFunction.def("Dump", (void (AdvApprox_ApproxAFunction::*)(Standard_OStream &) const ) &AdvApprox_ApproxAFunction::Dump, "diplay information on approximation.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\AdvApprox_DichoCutting.hxx
	py::class_<AdvApprox_DichoCutting, std::unique_ptr<AdvApprox_DichoCutting, Deleter<AdvApprox_DichoCutting>>, AdvApprox_Cutting> cls_AdvApprox_DichoCutting(mod, "AdvApprox_DichoCutting", "if Cutting is necessary in [a,b], we cut at (a+b) / 2.");
	cls_AdvApprox_DichoCutting.def(py::init<>());
	cls_AdvApprox_DichoCutting.def("Value", [](AdvApprox_DichoCutting &self, const Standard_Real a, const Standard_Real b, Standard_Real & cuttingvalue){ Standard_Boolean rv = self.Value(a, b, cuttingvalue); return std::tuple<Standard_Boolean, Standard_Real &>(rv, cuttingvalue); }, "None", py::arg("a"), py::arg("b"), py::arg("cuttingvalue"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\AdvApprox_PrefAndRec.hxx
	py::class_<AdvApprox_PrefAndRec, std::unique_ptr<AdvApprox_PrefAndRec, Deleter<AdvApprox_PrefAndRec>>, AdvApprox_Cutting> cls_AdvApprox_PrefAndRec(mod, "AdvApprox_PrefAndRec", "inherits class Cutting; contains a list of preferential points (pi)i and a list of Recommended points used in cutting management. if Cutting is necessary in [a,b], we cut at the di nearest from (a+b)/2");
	cls_AdvApprox_PrefAndRec.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("RecomendedCut"), py::arg("PrefferedCut"));
	cls_AdvApprox_PrefAndRec.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const Standard_Real>(), py::arg("RecomendedCut"), py::arg("PrefferedCut"), py::arg("Weight"));
	cls_AdvApprox_PrefAndRec.def("Value", [](AdvApprox_PrefAndRec &self, const Standard_Real a, const Standard_Real b, Standard_Real & cuttingvalue){ Standard_Boolean rv = self.Value(a, b, cuttingvalue); return std::tuple<Standard_Boolean, Standard_Real &>(rv, cuttingvalue); }, "cuting value is - the recommended point nerest of (a+b)/2 if pi is in ]a,b[ or else - the preferential point nearest of (a+b) / 2 if pi is in ](r*a+b)/(r+1) , (a+r*b)/(r+1)[ where r = Weight - or (a+b)/2 else.", py::arg("a"), py::arg("b"), py::arg("cuttingvalue"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\AdvApprox_PrefCutting.hxx
	py::class_<AdvApprox_PrefCutting, std::unique_ptr<AdvApprox_PrefCutting, Deleter<AdvApprox_PrefCutting>>, AdvApprox_Cutting> cls_AdvApprox_PrefCutting(mod, "AdvApprox_PrefCutting", "inherits class Cutting; contains a list of preferential points (di)i if Cutting is necessary in [a,b], we cut at the di nearest from (a+b)/2.");
	cls_AdvApprox_PrefCutting.def(py::init<const TColStd_Array1OfReal &>(), py::arg("CutPnts"));
	cls_AdvApprox_PrefCutting.def("Value", [](AdvApprox_PrefCutting &self, const Standard_Real a, const Standard_Real b, Standard_Real & cuttingvalue){ Standard_Boolean rv = self.Value(a, b, cuttingvalue); return std::tuple<Standard_Boolean, Standard_Real &>(rv, cuttingvalue); }, "None", py::arg("a"), py::arg("b"), py::arg("cuttingvalue"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\AdvApprox_SimpleApprox.hxx
	py::class_<AdvApprox_SimpleApprox, std::unique_ptr<AdvApprox_SimpleApprox, Deleter<AdvApprox_SimpleApprox>>> cls_AdvApprox_SimpleApprox(mod, "AdvApprox_SimpleApprox", "Approximate a function on an intervall [First,Last] The result is a simple polynomial whose degree is as low as possible to satisfy the required tolerance and the maximum degree. The maximum error and the averrage error resulting from approximating the function by the polynomial are computed");
	cls_AdvApprox_SimpleApprox.def(py::init<const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const opencascade::handle<PLib_JacobiPolynomial> &, const AdvApprox_EvaluatorFunction &>(), py::arg("TotalDimension"), py::arg("TotalNumSS"), py::arg("Continuity"), py::arg("WorkDegree"), py::arg("NbGaussPoints"), py::arg("JacobiBase"), py::arg("Func"));
	cls_AdvApprox_SimpleApprox.def("Perform", (void (AdvApprox_SimpleApprox::*)(const TColStd_Array1OfInteger &, const TColStd_Array1OfReal &, const Standard_Real, const Standard_Real, const Standard_Integer)) &AdvApprox_SimpleApprox::Perform, "Constructs approximator tool.", py::arg("LocalDimension"), py::arg("LocalTolerancesArray"), py::arg("First"), py::arg("Last"), py::arg("MaxDegree"));
	cls_AdvApprox_SimpleApprox.def("IsDone", (Standard_Boolean (AdvApprox_SimpleApprox::*)() const ) &AdvApprox_SimpleApprox::IsDone, "None");
	cls_AdvApprox_SimpleApprox.def("Degree", (Standard_Integer (AdvApprox_SimpleApprox::*)() const ) &AdvApprox_SimpleApprox::Degree, "None");
	cls_AdvApprox_SimpleApprox.def("Coefficients", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_SimpleApprox::*)() const ) &AdvApprox_SimpleApprox::Coefficients, "returns the coefficients in the Jacobi Base");
	cls_AdvApprox_SimpleApprox.def("FirstConstr", (opencascade::handle<TColStd_HArray2OfReal> (AdvApprox_SimpleApprox::*)() const ) &AdvApprox_SimpleApprox::FirstConstr, "returns the constraints at First");
	cls_AdvApprox_SimpleApprox.def("LastConstr", (opencascade::handle<TColStd_HArray2OfReal> (AdvApprox_SimpleApprox::*)() const ) &AdvApprox_SimpleApprox::LastConstr, "returns the constraints at Last");
	cls_AdvApprox_SimpleApprox.def("SomTab", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_SimpleApprox::*)() const ) &AdvApprox_SimpleApprox::SomTab, "None");
	cls_AdvApprox_SimpleApprox.def("DifTab", (opencascade::handle<TColStd_HArray1OfReal> (AdvApprox_SimpleApprox::*)() const ) &AdvApprox_SimpleApprox::DifTab, "None");
	cls_AdvApprox_SimpleApprox.def("MaxError", (Standard_Real (AdvApprox_SimpleApprox::*)(const Standard_Integer) const ) &AdvApprox_SimpleApprox::MaxError, "None", py::arg("Index"));
	cls_AdvApprox_SimpleApprox.def("AverageError", (Standard_Real (AdvApprox_SimpleApprox::*)(const Standard_Integer) const ) &AdvApprox_SimpleApprox::AverageError, "None", py::arg("Index"));
	// FIXME cls_AdvApprox_SimpleApprox.def("Dump", (void (AdvApprox_SimpleApprox::*)(Standard_OStream &) const ) &AdvApprox_SimpleApprox::Dump, "display information on approximation", py::arg("o"));


}
