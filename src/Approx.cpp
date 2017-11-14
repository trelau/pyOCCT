#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Approx_ParametrizationType.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <Approx_SequenceOfHArray1OfReal.hxx>
#include <Approx_Status.hxx>
#include <NCollection_Array1.hxx>
#include <Approx_Array1OfAdHSurface.hxx>
#include <Approx_Array1OfGTrsf2d.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Approx_Curve2d.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Standard_OStream.hxx>
#include <Approx_Curve3d.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Approx_CurveOnSurface.hxx>
#include <Approx_CurvilinearParameter.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Type.hxx>
#include <Approx_CurvlinFunc.hxx>
#include <AppCont_Function.hxx>
#include <AppParCurves_Constraint.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <Approx_FitAndDivide.hxx>
#include <Approx_FitAndDivide2d.hxx>
#include <Approx_HArray1OfAdHSurface.hxx>
#include <Approx_HArray1OfGTrsf2d.hxx>
#include <AppParCurves_SequenceOfMultiCurve.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <Approx_MCurvesToBSpCurve.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Approx_SameParameter.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <gp_Pnt.hxx>
#include <Approx_SweepFunction.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <Approx_SweepApproximation.hxx>

PYBIND11_MODULE(Approx, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.AppCont");
	py::module::import("OCCT.AppParCurves");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_ParametrizationType.hxx
	py::enum_<Approx_ParametrizationType>(mod, "Approx_ParametrizationType", "None")
		.value("Approx_ChordLength", Approx_ParametrizationType::Approx_ChordLength)
		.value("Approx_Centripetal", Approx_ParametrizationType::Approx_Centripetal)
		.value("Approx_IsoParametric", Approx_ParametrizationType::Approx_IsoParametric)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_Status.hxx
	py::enum_<Approx_Status>(mod, "Approx_Status", "None")
		.value("Approx_PointsAdded", Approx_Status::Approx_PointsAdded)
		.value("Approx_NoPointsAdded", Approx_Status::Approx_NoPointsAdded)
		.value("Approx_NoApproximation", Approx_Status::Approx_NoApproximation)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_Curve2d.hxx
	py::class_<Approx_Curve2d, std::unique_ptr<Approx_Curve2d, Deleter<Approx_Curve2d>>> cls_Approx_Curve2d(mod, "Approx_Curve2d", "Makes an approximation for HCurve2d from Adaptor3d");
	cls_Approx_Curve2d.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C2D"), py::arg("First"), py::arg("Last"), py::arg("TolU"), py::arg("TolV"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegments"));
	cls_Approx_Curve2d.def("IsDone", (Standard_Boolean (Approx_Curve2d::*)() const ) &Approx_Curve2d::IsDone, "None");
	cls_Approx_Curve2d.def("HasResult", (Standard_Boolean (Approx_Curve2d::*)() const ) &Approx_Curve2d::HasResult, "None");
	cls_Approx_Curve2d.def("Curve", (opencascade::handle<Geom2d_BSplineCurve> (Approx_Curve2d::*)() const ) &Approx_Curve2d::Curve, "None");
	cls_Approx_Curve2d.def("MaxError2dU", (Standard_Real (Approx_Curve2d::*)() const ) &Approx_Curve2d::MaxError2dU, "None");
	cls_Approx_Curve2d.def("MaxError2dV", (Standard_Real (Approx_Curve2d::*)() const ) &Approx_Curve2d::MaxError2dV, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_Curve3d.hxx
	py::class_<Approx_Curve3d, std::unique_ptr<Approx_Curve3d, Deleter<Approx_Curve3d>>> cls_Approx_Curve3d(mod, "Approx_Curve3d", "None");
	cls_Approx_Curve3d.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("Curve"), py::arg("Tol3d"), py::arg("Order"), py::arg("MaxSegments"), py::arg("MaxDegree"));
	cls_Approx_Curve3d.def("Curve", (opencascade::handle<Geom_BSplineCurve> (Approx_Curve3d::*)() const ) &Approx_Curve3d::Curve, "None");
	cls_Approx_Curve3d.def("IsDone", (Standard_Boolean (Approx_Curve3d::*)() const ) &Approx_Curve3d::IsDone, "returns Standard_True if the approximation has been done within requiered tolerance");
	cls_Approx_Curve3d.def("HasResult", (Standard_Boolean (Approx_Curve3d::*)() const ) &Approx_Curve3d::HasResult, "returns Standard_True if the approximation did come out with a result that is not NECESSARELY within the required tolerance");
	cls_Approx_Curve3d.def("MaxError", (Standard_Real (Approx_Curve3d::*)() const ) &Approx_Curve3d::MaxError, "returns the Maximum Error (>0 when an approximation has been done, 0 if no approximation)");
	// FIXME cls_Approx_Curve3d.def("Dump", (void (Approx_Curve3d::*)(Standard_OStream &) const ) &Approx_Curve3d::Dump, "Print on the stream o information about the object", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_CurveOnSurface.hxx
	py::class_<Approx_CurveOnSurface, std::unique_ptr<Approx_CurveOnSurface, Deleter<Approx_CurveOnSurface>>> cls_Approx_CurveOnSurface(mod, "Approx_CurveOnSurface", "Approximation of curve on surface");
	cls_Approx_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C2D"), py::arg("Surf"), py::arg("First"), py::arg("Last"), py::arg("Tol"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegments"));
	cls_Approx_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("C2D"), py::arg("Surf"), py::arg("First"), py::arg("Last"), py::arg("Tol"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegments"), py::arg("Only3d"));
	cls_Approx_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("C2D"), py::arg("Surf"), py::arg("First"), py::arg("Last"), py::arg("Tol"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegments"), py::arg("Only3d"), py::arg("Only2d"));
	cls_Approx_CurveOnSurface.def("IsDone", (Standard_Boolean (Approx_CurveOnSurface::*)() const ) &Approx_CurveOnSurface::IsDone, "None");
	cls_Approx_CurveOnSurface.def("HasResult", (Standard_Boolean (Approx_CurveOnSurface::*)() const ) &Approx_CurveOnSurface::HasResult, "None");
	cls_Approx_CurveOnSurface.def("Curve3d", (opencascade::handle<Geom_BSplineCurve> (Approx_CurveOnSurface::*)() const ) &Approx_CurveOnSurface::Curve3d, "None");
	cls_Approx_CurveOnSurface.def("MaxError3d", (Standard_Real (Approx_CurveOnSurface::*)() const ) &Approx_CurveOnSurface::MaxError3d, "None");
	cls_Approx_CurveOnSurface.def("Curve2d", (opencascade::handle<Geom2d_BSplineCurve> (Approx_CurveOnSurface::*)() const ) &Approx_CurveOnSurface::Curve2d, "None");
	cls_Approx_CurveOnSurface.def("MaxError2dU", (Standard_Real (Approx_CurveOnSurface::*)() const ) &Approx_CurveOnSurface::MaxError2dU, "None");
	cls_Approx_CurveOnSurface.def("MaxError2dV", (Standard_Real (Approx_CurveOnSurface::*)() const ) &Approx_CurveOnSurface::MaxError2dV, "returns the maximum errors relativly to the U component or the V component of the 2d Curve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_CurvilinearParameter.hxx
	py::class_<Approx_CurvilinearParameter, std::unique_ptr<Approx_CurvilinearParameter, Deleter<Approx_CurvilinearParameter>>> cls_Approx_CurvilinearParameter(mod, "Approx_CurvilinearParameter", "Approximation of a Curve to make its parameter be its curvilinear abscissa If the curve is a curve on a surface S, C2D is the corresponding Pcurve, we considere the curve is given by its representation S(C2D(u)) If the curve is a curve on 2 surfaces S1 and S2 and C2D1 C2D2 are the two corresponding Pcurve, we considere the curve is given by its representation 1/2(S1(C2D1(u) + S2 (C2D2(u)))");
	cls_Approx_CurvilinearParameter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C3D"), py::arg("Tol"), py::arg("Order"), py::arg("MaxDegree"), py::arg("MaxSegments"));
	cls_Approx_CurvilinearParameter.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C2D"), py::arg("Surf"), py::arg("Tol"), py::arg("Order"), py::arg("MaxDegree"), py::arg("MaxSegments"));
	cls_Approx_CurvilinearParameter.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C2D1"), py::arg("Surf1"), py::arg("C2D2"), py::arg("Surf2"), py::arg("Tol"), py::arg("Order"), py::arg("MaxDegree"), py::arg("MaxSegments"));
	cls_Approx_CurvilinearParameter.def("IsDone", (Standard_Boolean (Approx_CurvilinearParameter::*)() const ) &Approx_CurvilinearParameter::IsDone, "None");
	cls_Approx_CurvilinearParameter.def("HasResult", (Standard_Boolean (Approx_CurvilinearParameter::*)() const ) &Approx_CurvilinearParameter::HasResult, "None");
	cls_Approx_CurvilinearParameter.def("Curve3d", (opencascade::handle<Geom_BSplineCurve> (Approx_CurvilinearParameter::*)() const ) &Approx_CurvilinearParameter::Curve3d, "returns the Bspline curve corresponding to the reparametrized 3D curve");
	cls_Approx_CurvilinearParameter.def("MaxError3d", (Standard_Real (Approx_CurvilinearParameter::*)() const ) &Approx_CurvilinearParameter::MaxError3d, "returns the maximum error on the reparametrized 3D curve");
	cls_Approx_CurvilinearParameter.def("Curve2d1", (opencascade::handle<Geom2d_BSplineCurve> (Approx_CurvilinearParameter::*)() const ) &Approx_CurvilinearParameter::Curve2d1, "returns the BsplineCurve representing the reparametrized 2D curve on the first surface (case of a curve on one or two surfaces)");
	cls_Approx_CurvilinearParameter.def("MaxError2d1", (Standard_Real (Approx_CurvilinearParameter::*)() const ) &Approx_CurvilinearParameter::MaxError2d1, "returns the maximum error on the first reparametrized 2D curve");
	cls_Approx_CurvilinearParameter.def("Curve2d2", (opencascade::handle<Geom2d_BSplineCurve> (Approx_CurvilinearParameter::*)() const ) &Approx_CurvilinearParameter::Curve2d2, "returns the BsplineCurve representing the reparametrized 2D curve on the second surface (case of a curve on two surfaces)");
	cls_Approx_CurvilinearParameter.def("MaxError2d2", (Standard_Real (Approx_CurvilinearParameter::*)() const ) &Approx_CurvilinearParameter::MaxError2d2, "returns the maximum error on the second reparametrized 2D curve");
	// FIXME cls_Approx_CurvilinearParameter.def("Dump", (void (Approx_CurvilinearParameter::*)(Standard_OStream &) const ) &Approx_CurvilinearParameter::Dump, "print the maximum errors(s)", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_CurvlinFunc.hxx
	py::class_<Approx_CurvlinFunc, opencascade::handle<Approx_CurvlinFunc>, Standard_Transient> cls_Approx_CurvlinFunc(mod, "Approx_CurvlinFunc", "defines an abstract curve with curvilinear parametrization");
	cls_Approx_CurvlinFunc.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("C"), py::arg("Tol"));
	cls_Approx_CurvlinFunc.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C2D"), py::arg("S"), py::arg("Tol"));
	cls_Approx_CurvlinFunc.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C2D1"), py::arg("C2D2"), py::arg("S1"), py::arg("S2"), py::arg("Tol"));
	cls_Approx_CurvlinFunc.def("SetTol", (void (Approx_CurvlinFunc::*)(const Standard_Real)) &Approx_CurvlinFunc::SetTol, "---Purpose Update the tolerance to used", py::arg("Tol"));
	cls_Approx_CurvlinFunc.def("FirstParameter", (Standard_Real (Approx_CurvlinFunc::*)() const ) &Approx_CurvlinFunc::FirstParameter, "None");
	cls_Approx_CurvlinFunc.def("LastParameter", (Standard_Real (Approx_CurvlinFunc::*)() const ) &Approx_CurvlinFunc::LastParameter, "None");
	cls_Approx_CurvlinFunc.def("NbIntervals", (Standard_Integer (Approx_CurvlinFunc::*)(const GeomAbs_Shape) const ) &Approx_CurvlinFunc::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_Approx_CurvlinFunc.def("Intervals", (void (Approx_CurvlinFunc::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Approx_CurvlinFunc::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Approx_CurvlinFunc.def("Trim", (void (Approx_CurvlinFunc::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Approx_CurvlinFunc::Trim, "if First < 0 or Last > 1", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_Approx_CurvlinFunc.def("Length", (void (Approx_CurvlinFunc::*)()) &Approx_CurvlinFunc::Length, "Computes length of the curve.");
	cls_Approx_CurvlinFunc.def("Length", (Standard_Real (Approx_CurvlinFunc::*)(Adaptor3d_Curve &, const Standard_Real, const Standard_Real) const ) &Approx_CurvlinFunc::Length, "Computes length of the curve segment.", py::arg("C"), py::arg("FirstU"), py::arg("LasrU"));
	cls_Approx_CurvlinFunc.def("GetLength", (Standard_Real (Approx_CurvlinFunc::*)() const ) &Approx_CurvlinFunc::GetLength, "None");
	cls_Approx_CurvlinFunc.def("GetUParameter", (Standard_Real (Approx_CurvlinFunc::*)(Adaptor3d_Curve &, const Standard_Real, const Standard_Integer) const ) &Approx_CurvlinFunc::GetUParameter, "returns original parameter correponding S. if Case == 1 computation is performed on myC2D1 and mySurf1, otherwise it is done on myC2D2 and mySurf2.", py::arg("C"), py::arg("S"), py::arg("NumberOfCurve"));
	cls_Approx_CurvlinFunc.def("GetSParameter", (Standard_Real (Approx_CurvlinFunc::*)(const Standard_Real) const ) &Approx_CurvlinFunc::GetSParameter, "returns original parameter correponding S.", py::arg("U"));
	cls_Approx_CurvlinFunc.def("EvalCase1", (Standard_Boolean (Approx_CurvlinFunc::*)(const Standard_Real, const Standard_Integer, TColStd_Array1OfReal &) const ) &Approx_CurvlinFunc::EvalCase1, "if myCase != 1", py::arg("S"), py::arg("Order"), py::arg("Result"));
	cls_Approx_CurvlinFunc.def("EvalCase2", (Standard_Boolean (Approx_CurvlinFunc::*)(const Standard_Real, const Standard_Integer, TColStd_Array1OfReal &) const ) &Approx_CurvlinFunc::EvalCase2, "if myCase != 2", py::arg("S"), py::arg("Order"), py::arg("Result"));
	cls_Approx_CurvlinFunc.def("EvalCase3", (Standard_Boolean (Approx_CurvlinFunc::*)(const Standard_Real, const Standard_Integer, TColStd_Array1OfReal &)) &Approx_CurvlinFunc::EvalCase3, "if myCase != 3", py::arg("S"), py::arg("Order"), py::arg("Result"));
	cls_Approx_CurvlinFunc.def_static("get_type_name_", (const char * (*)()) &Approx_CurvlinFunc::get_type_name, "None");
	cls_Approx_CurvlinFunc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Approx_CurvlinFunc::get_type_descriptor, "None");
	cls_Approx_CurvlinFunc.def("DynamicType", (const opencascade::handle<Standard_Type> & (Approx_CurvlinFunc::*)() const ) &Approx_CurvlinFunc::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_FitAndDivide.hxx
	py::class_<Approx_FitAndDivide, std::unique_ptr<Approx_FitAndDivide, Deleter<Approx_FitAndDivide>>> cls_Approx_FitAndDivide(mod, "Approx_FitAndDivide", "None");
	cls_Approx_FitAndDivide.def(py::init<const AppCont_Function &>(), py::arg("Line"));
	cls_Approx_FitAndDivide.def(py::init<const AppCont_Function &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
	cls_Approx_FitAndDivide.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
	cls_Approx_FitAndDivide.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
	cls_Approx_FitAndDivide.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
	cls_Approx_FitAndDivide.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
	cls_Approx_FitAndDivide.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
	cls_Approx_FitAndDivide.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));
	cls_Approx_FitAndDivide.def(py::init<>());
	cls_Approx_FitAndDivide.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
	cls_Approx_FitAndDivide.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
	cls_Approx_FitAndDivide.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
	cls_Approx_FitAndDivide.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
	cls_Approx_FitAndDivide.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
	cls_Approx_FitAndDivide.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
	cls_Approx_FitAndDivide.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));
	cls_Approx_FitAndDivide.def("Perform", (void (Approx_FitAndDivide::*)(const AppCont_Function &)) &Approx_FitAndDivide::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
	cls_Approx_FitAndDivide.def("SetDegrees", (void (Approx_FitAndDivide::*)(const Standard_Integer, const Standard_Integer)) &Approx_FitAndDivide::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
	cls_Approx_FitAndDivide.def("SetTolerances", (void (Approx_FitAndDivide::*)(const Standard_Real, const Standard_Real)) &Approx_FitAndDivide::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
	cls_Approx_FitAndDivide.def("SetConstraints", (void (Approx_FitAndDivide::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &Approx_FitAndDivide::SetConstraints, "Changes the constraints of the approximation.", py::arg("FirstC"), py::arg("LastC"));
	cls_Approx_FitAndDivide.def("IsAllApproximated", (Standard_Boolean (Approx_FitAndDivide::*)() const ) &Approx_FitAndDivide::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
	cls_Approx_FitAndDivide.def("IsToleranceReached", (Standard_Boolean (Approx_FitAndDivide::*)() const ) &Approx_FitAndDivide::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
	cls_Approx_FitAndDivide.def("Error", (void (Approx_FitAndDivide::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &Approx_FitAndDivide::Error, "returns the tolerances 2d and 3d of the <Index> MultiCurve.", py::arg("Index"), py::arg("tol3d"), py::arg("tol2d"));
	cls_Approx_FitAndDivide.def("NbMultiCurves", (Standard_Integer (Approx_FitAndDivide::*)() const ) &Approx_FitAndDivide::NbMultiCurves, "Returns the number of MultiCurve doing the approximation of the MultiLine.");
	cls_Approx_FitAndDivide.def("Value", [](Approx_FitAndDivide &self) -> AppParCurves_MultiCurve { return self.Value(); });
	cls_Approx_FitAndDivide.def("Value", (AppParCurves_MultiCurve (Approx_FitAndDivide::*)(const Standard_Integer) const ) &Approx_FitAndDivide::Value, "returns the approximation MultiCurve of range <Index>.", py::arg("Index"));
	cls_Approx_FitAndDivide.def("Parameters", (void (Approx_FitAndDivide::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &Approx_FitAndDivide::Parameters, "None", py::arg("Index"), py::arg("firstp"), py::arg("lastp"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_FitAndDivide2d.hxx
	py::class_<Approx_FitAndDivide2d, std::unique_ptr<Approx_FitAndDivide2d, Deleter<Approx_FitAndDivide2d>>> cls_Approx_FitAndDivide2d(mod, "Approx_FitAndDivide2d", "None");
	cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &>(), py::arg("Line"));
	cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"));
	cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"));
	cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
	cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
	cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
	cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
	cls_Approx_FitAndDivide2d.def(py::init<const AppCont_Function &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("Line"), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));
	cls_Approx_FitAndDivide2d.def(py::init<>());
	cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer>(), py::arg("degreemin"));
	cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("degreemin"), py::arg("degreemax"));
	cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"));
	cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"));
	cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"));
	cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"));
	cls_Approx_FitAndDivide2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Boolean, const AppParCurves_Constraint, const AppParCurves_Constraint>(), py::arg("degreemin"), py::arg("degreemax"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("cutting"), py::arg("FirstC"), py::arg("LastC"));
	cls_Approx_FitAndDivide2d.def("Perform", (void (Approx_FitAndDivide2d::*)(const AppCont_Function &)) &Approx_FitAndDivide2d::Perform, "runs the algorithm after having initialized the fields.", py::arg("Line"));
	cls_Approx_FitAndDivide2d.def("SetDegrees", (void (Approx_FitAndDivide2d::*)(const Standard_Integer, const Standard_Integer)) &Approx_FitAndDivide2d::SetDegrees, "changes the degrees of the approximation.", py::arg("degreemin"), py::arg("degreemax"));
	cls_Approx_FitAndDivide2d.def("SetTolerances", (void (Approx_FitAndDivide2d::*)(const Standard_Real, const Standard_Real)) &Approx_FitAndDivide2d::SetTolerances, "Changes the tolerances of the approximation.", py::arg("Tolerance3d"), py::arg("Tolerance2d"));
	cls_Approx_FitAndDivide2d.def("SetConstraints", (void (Approx_FitAndDivide2d::*)(const AppParCurves_Constraint, const AppParCurves_Constraint)) &Approx_FitAndDivide2d::SetConstraints, "Changes the constraints of the approximation.", py::arg("FirstC"), py::arg("LastC"));
	cls_Approx_FitAndDivide2d.def("IsAllApproximated", (Standard_Boolean (Approx_FitAndDivide2d::*)() const ) &Approx_FitAndDivide2d::IsAllApproximated, "returns False if at a moment of the approximation, the status NoApproximation has been sent by the user when more points were needed.");
	cls_Approx_FitAndDivide2d.def("IsToleranceReached", (Standard_Boolean (Approx_FitAndDivide2d::*)() const ) &Approx_FitAndDivide2d::IsToleranceReached, "returns False if the status NoPointsAdded has been sent.");
	cls_Approx_FitAndDivide2d.def("Error", (void (Approx_FitAndDivide2d::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &Approx_FitAndDivide2d::Error, "returns the tolerances 2d and 3d of the <Index> MultiCurve.", py::arg("Index"), py::arg("tol3d"), py::arg("tol2d"));
	cls_Approx_FitAndDivide2d.def("NbMultiCurves", (Standard_Integer (Approx_FitAndDivide2d::*)() const ) &Approx_FitAndDivide2d::NbMultiCurves, "Returns the number of MultiCurve doing the approximation of the MultiLine.");
	cls_Approx_FitAndDivide2d.def("Value", [](Approx_FitAndDivide2d &self) -> AppParCurves_MultiCurve { return self.Value(); });
	cls_Approx_FitAndDivide2d.def("Value", (AppParCurves_MultiCurve (Approx_FitAndDivide2d::*)(const Standard_Integer) const ) &Approx_FitAndDivide2d::Value, "returns the approximation MultiCurve of range <Index>.", py::arg("Index"));
	cls_Approx_FitAndDivide2d.def("Parameters", (void (Approx_FitAndDivide2d::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &Approx_FitAndDivide2d::Parameters, "None", py::arg("Index"), py::arg("firstp"), py::arg("lastp"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Approx_Array1OfAdHSurface, std::unique_ptr<Approx_Array1OfAdHSurface, Deleter<Approx_Array1OfAdHSurface>>> cls_Approx_Array1OfAdHSurface(mod, "Approx_Array1OfAdHSurface", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Approx_Array1OfAdHSurface.def(py::init<>());
	cls_Approx_Array1OfAdHSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Approx_Array1OfAdHSurface.def(py::init([] (const Approx_Array1OfAdHSurface &other) {return new Approx_Array1OfAdHSurface(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Approx_Array1OfAdHSurface.def(py::init<Approx_Array1OfAdHSurface &&>(), py::arg("theOther"));
	cls_Approx_Array1OfAdHSurface.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Approx_Array1OfAdHSurface.def("begin", (Approx_Array1OfAdHSurface::iterator (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Approx_Array1OfAdHSurface.def("end", (Approx_Array1OfAdHSurface::iterator (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Approx_Array1OfAdHSurface.def("cbegin", (Approx_Array1OfAdHSurface::const_iterator (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Approx_Array1OfAdHSurface.def("cend", (Approx_Array1OfAdHSurface::const_iterator (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Approx_Array1OfAdHSurface.def("Init", (void (Approx_Array1OfAdHSurface::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Approx_Array1OfAdHSurface::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Approx_Array1OfAdHSurface.def("Size", (Standard_Integer (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::Size, "Size query");
	cls_Approx_Array1OfAdHSurface.def("Length", (Standard_Integer (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::Length, "Length query (the same)");
	cls_Approx_Array1OfAdHSurface.def("IsEmpty", (Standard_Boolean (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::IsEmpty, "Return TRUE if array has zero length.");
	cls_Approx_Array1OfAdHSurface.def("Lower", (Standard_Integer (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::Lower, "Lower bound");
	cls_Approx_Array1OfAdHSurface.def("Upper", (Standard_Integer (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::Upper, "Upper bound");
	cls_Approx_Array1OfAdHSurface.def("IsDeletable", (Standard_Boolean (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::IsDeletable, "myDeletable flag");
	cls_Approx_Array1OfAdHSurface.def("IsAllocated", (Standard_Boolean (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Approx_Array1OfAdHSurface.def("Assign", (Approx_Array1OfAdHSurface & (Approx_Array1OfAdHSurface::*)(const Approx_Array1OfAdHSurface &)) &Approx_Array1OfAdHSurface::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Approx_Array1OfAdHSurface.def("Move", (Approx_Array1OfAdHSurface & (Approx_Array1OfAdHSurface::*)(Approx_Array1OfAdHSurface &&)) &Approx_Array1OfAdHSurface::Move, "Move assignment", py::arg("theOther"));
	cls_Approx_Array1OfAdHSurface.def("assign", (Approx_Array1OfAdHSurface & (Approx_Array1OfAdHSurface::*)(const Approx_Array1OfAdHSurface &)) &Approx_Array1OfAdHSurface::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Approx_Array1OfAdHSurface.def("assign", (Approx_Array1OfAdHSurface & (Approx_Array1OfAdHSurface::*)(Approx_Array1OfAdHSurface &&)) &Approx_Array1OfAdHSurface::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Approx_Array1OfAdHSurface.def("First", (const opencascade::handle<Adaptor3d_HSurface> & (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::First, "Returns first element");
	cls_Approx_Array1OfAdHSurface.def("ChangeFirst", (opencascade::handle<Adaptor3d_HSurface> & (Approx_Array1OfAdHSurface::*)()) &Approx_Array1OfAdHSurface::ChangeFirst, "Returns first element");
	cls_Approx_Array1OfAdHSurface.def("Last", (const opencascade::handle<Adaptor3d_HSurface> & (Approx_Array1OfAdHSurface::*)() const ) &Approx_Array1OfAdHSurface::Last, "Returns last element");
	cls_Approx_Array1OfAdHSurface.def("ChangeLast", (opencascade::handle<Adaptor3d_HSurface> & (Approx_Array1OfAdHSurface::*)()) &Approx_Array1OfAdHSurface::ChangeLast, "Returns last element");
	cls_Approx_Array1OfAdHSurface.def("Value", (const opencascade::handle<Adaptor3d_HSurface> & (Approx_Array1OfAdHSurface::*)(const Standard_Integer) const ) &Approx_Array1OfAdHSurface::Value, "Constant value access", py::arg("theIndex"));
	cls_Approx_Array1OfAdHSurface.def("__call__", (const opencascade::handle<Adaptor3d_HSurface> & (Approx_Array1OfAdHSurface::*)(const Standard_Integer) const ) &Approx_Array1OfAdHSurface::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Approx_Array1OfAdHSurface.def("ChangeValue", (opencascade::handle<Adaptor3d_HSurface> & (Approx_Array1OfAdHSurface::*)(const Standard_Integer)) &Approx_Array1OfAdHSurface::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Approx_Array1OfAdHSurface.def("__call__", (opencascade::handle<Adaptor3d_HSurface> & (Approx_Array1OfAdHSurface::*)(const Standard_Integer)) &Approx_Array1OfAdHSurface::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Approx_Array1OfAdHSurface.def("SetValue", (void (Approx_Array1OfAdHSurface::*)(const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &)) &Approx_Array1OfAdHSurface::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Approx_Array1OfAdHSurface.def("Resize", (void (Approx_Array1OfAdHSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Approx_Array1OfAdHSurface::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Approx_Array1OfAdHSurface.def("__iter__", [](const Approx_Array1OfAdHSurface &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Approx_Array1OfGTrsf2d, std::unique_ptr<Approx_Array1OfGTrsf2d, Deleter<Approx_Array1OfGTrsf2d>>> cls_Approx_Array1OfGTrsf2d(mod, "Approx_Array1OfGTrsf2d", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Approx_Array1OfGTrsf2d.def(py::init<>());
	cls_Approx_Array1OfGTrsf2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Approx_Array1OfGTrsf2d.def(py::init([] (const Approx_Array1OfGTrsf2d &other) {return new Approx_Array1OfGTrsf2d(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Approx_Array1OfGTrsf2d.def(py::init<Approx_Array1OfGTrsf2d &&>(), py::arg("theOther"));
	cls_Approx_Array1OfGTrsf2d.def(py::init<const gp_GTrsf2d &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Approx_Array1OfGTrsf2d.def("begin", (Approx_Array1OfGTrsf2d::iterator (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Approx_Array1OfGTrsf2d.def("end", (Approx_Array1OfGTrsf2d::iterator (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Approx_Array1OfGTrsf2d.def("cbegin", (Approx_Array1OfGTrsf2d::const_iterator (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Approx_Array1OfGTrsf2d.def("cend", (Approx_Array1OfGTrsf2d::const_iterator (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Approx_Array1OfGTrsf2d.def("Init", (void (Approx_Array1OfGTrsf2d::*)(const gp_GTrsf2d &)) &Approx_Array1OfGTrsf2d::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Approx_Array1OfGTrsf2d.def("Size", (Standard_Integer (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::Size, "Size query");
	cls_Approx_Array1OfGTrsf2d.def("Length", (Standard_Integer (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::Length, "Length query (the same)");
	cls_Approx_Array1OfGTrsf2d.def("IsEmpty", (Standard_Boolean (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::IsEmpty, "Return TRUE if array has zero length.");
	cls_Approx_Array1OfGTrsf2d.def("Lower", (Standard_Integer (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::Lower, "Lower bound");
	cls_Approx_Array1OfGTrsf2d.def("Upper", (Standard_Integer (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::Upper, "Upper bound");
	cls_Approx_Array1OfGTrsf2d.def("IsDeletable", (Standard_Boolean (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::IsDeletable, "myDeletable flag");
	cls_Approx_Array1OfGTrsf2d.def("IsAllocated", (Standard_Boolean (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Approx_Array1OfGTrsf2d.def("Assign", (Approx_Array1OfGTrsf2d & (Approx_Array1OfGTrsf2d::*)(const Approx_Array1OfGTrsf2d &)) &Approx_Array1OfGTrsf2d::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Approx_Array1OfGTrsf2d.def("Move", (Approx_Array1OfGTrsf2d & (Approx_Array1OfGTrsf2d::*)(Approx_Array1OfGTrsf2d &&)) &Approx_Array1OfGTrsf2d::Move, "Move assignment", py::arg("theOther"));
	cls_Approx_Array1OfGTrsf2d.def("assign", (Approx_Array1OfGTrsf2d & (Approx_Array1OfGTrsf2d::*)(const Approx_Array1OfGTrsf2d &)) &Approx_Array1OfGTrsf2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Approx_Array1OfGTrsf2d.def("assign", (Approx_Array1OfGTrsf2d & (Approx_Array1OfGTrsf2d::*)(Approx_Array1OfGTrsf2d &&)) &Approx_Array1OfGTrsf2d::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Approx_Array1OfGTrsf2d.def("First", (const gp_GTrsf2d & (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::First, "Returns first element");
	cls_Approx_Array1OfGTrsf2d.def("ChangeFirst", (gp_GTrsf2d & (Approx_Array1OfGTrsf2d::*)()) &Approx_Array1OfGTrsf2d::ChangeFirst, "Returns first element");
	cls_Approx_Array1OfGTrsf2d.def("Last", (const gp_GTrsf2d & (Approx_Array1OfGTrsf2d::*)() const ) &Approx_Array1OfGTrsf2d::Last, "Returns last element");
	cls_Approx_Array1OfGTrsf2d.def("ChangeLast", (gp_GTrsf2d & (Approx_Array1OfGTrsf2d::*)()) &Approx_Array1OfGTrsf2d::ChangeLast, "Returns last element");
	cls_Approx_Array1OfGTrsf2d.def("Value", (const gp_GTrsf2d & (Approx_Array1OfGTrsf2d::*)(const Standard_Integer) const ) &Approx_Array1OfGTrsf2d::Value, "Constant value access", py::arg("theIndex"));
	cls_Approx_Array1OfGTrsf2d.def("__call__", (const gp_GTrsf2d & (Approx_Array1OfGTrsf2d::*)(const Standard_Integer) const ) &Approx_Array1OfGTrsf2d::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Approx_Array1OfGTrsf2d.def("ChangeValue", (gp_GTrsf2d & (Approx_Array1OfGTrsf2d::*)(const Standard_Integer)) &Approx_Array1OfGTrsf2d::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Approx_Array1OfGTrsf2d.def("__call__", (gp_GTrsf2d & (Approx_Array1OfGTrsf2d::*)(const Standard_Integer)) &Approx_Array1OfGTrsf2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Approx_Array1OfGTrsf2d.def("SetValue", (void (Approx_Array1OfGTrsf2d::*)(const Standard_Integer, const gp_GTrsf2d &)) &Approx_Array1OfGTrsf2d::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Approx_Array1OfGTrsf2d.def("Resize", (void (Approx_Array1OfGTrsf2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Approx_Array1OfGTrsf2d::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Approx_Array1OfGTrsf2d.def("__iter__", [](const Approx_Array1OfGTrsf2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_MCurvesToBSpCurve.hxx
	py::class_<Approx_MCurvesToBSpCurve, std::unique_ptr<Approx_MCurvesToBSpCurve, Deleter<Approx_MCurvesToBSpCurve>>> cls_Approx_MCurvesToBSpCurve(mod, "Approx_MCurvesToBSpCurve", "None");
	cls_Approx_MCurvesToBSpCurve.def(py::init<>());
	cls_Approx_MCurvesToBSpCurve.def("Reset", (void (Approx_MCurvesToBSpCurve::*)()) &Approx_MCurvesToBSpCurve::Reset, "None");
	cls_Approx_MCurvesToBSpCurve.def("Append", (void (Approx_MCurvesToBSpCurve::*)(const AppParCurves_MultiCurve &)) &Approx_MCurvesToBSpCurve::Append, "None", py::arg("MC"));
	cls_Approx_MCurvesToBSpCurve.def("Perform", (void (Approx_MCurvesToBSpCurve::*)()) &Approx_MCurvesToBSpCurve::Perform, "None");
	cls_Approx_MCurvesToBSpCurve.def("Perform", (void (Approx_MCurvesToBSpCurve::*)(const AppParCurves_SequenceOfMultiCurve &)) &Approx_MCurvesToBSpCurve::Perform, "None", py::arg("TheSeq"));
	cls_Approx_MCurvesToBSpCurve.def("Value", (const AppParCurves_MultiBSpCurve & (Approx_MCurvesToBSpCurve::*)() const ) &Approx_MCurvesToBSpCurve::Value, "return the composite MultiCurves as a MultiBSpCurve.");
	cls_Approx_MCurvesToBSpCurve.def("ChangeValue", (const AppParCurves_MultiBSpCurve & (Approx_MCurvesToBSpCurve::*)()) &Approx_MCurvesToBSpCurve::ChangeValue, "return the composite MultiCurves as a MultiBSpCurve.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_SameParameter.hxx
	py::class_<Approx_SameParameter, std::unique_ptr<Approx_SameParameter, Deleter<Approx_SameParameter>>> cls_Approx_SameParameter(mod, "Approx_SameParameter", "Approximation of a PCurve on a surface to make its parameter be the same that the parameter of a given 3d reference curve.");
	cls_Approx_SameParameter.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("C3D"), py::arg("C2D"), py::arg("S"), py::arg("Tol"));
	cls_Approx_SameParameter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C3D"), py::arg("C2D"), py::arg("S"), py::arg("Tol"));
	cls_Approx_SameParameter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C3D"), py::arg("C2D"), py::arg("S"), py::arg("Tol"));
	cls_Approx_SameParameter.def("IsDone", (Standard_Boolean (Approx_SameParameter::*)() const ) &Approx_SameParameter::IsDone, "None");
	cls_Approx_SameParameter.def("TolReached", (Standard_Real (Approx_SameParameter::*)() const ) &Approx_SameParameter::TolReached, "None");
	cls_Approx_SameParameter.def("IsSameParameter", (Standard_Boolean (Approx_SameParameter::*)() const ) &Approx_SameParameter::IsSameParameter, "Tells whether the original data had already the same parameter up to the tolerance : in that case nothing is done.");
	cls_Approx_SameParameter.def("Curve2d", (opencascade::handle<Geom2d_BSplineCurve> (Approx_SameParameter::*)() const ) &Approx_SameParameter::Curve2d, "Returns the 2D curve that has the same parameter as the 3D curve once evaluated on the surface up to the specified tolerance");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_SweepFunction.hxx
	py::class_<Approx_SweepFunction, opencascade::handle<Approx_SweepFunction>, Standard_Transient> cls_Approx_SweepFunction(mod, "Approx_SweepFunction", "defined the function used by SweepApproximation to perform sweeping application.");
	cls_Approx_SweepFunction.def("D0", (Standard_Boolean (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &Approx_SweepFunction::D0, "compute the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
	cls_Approx_SweepFunction.def("D1", (Standard_Boolean (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Approx_SweepFunction::D1, "compute the first derivative in v direction of the section for v = param Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
	cls_Approx_SweepFunction.def("D2", (Standard_Boolean (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Approx_SweepFunction::D2, "compute the second derivative in v direction of the section for v = param Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
	cls_Approx_SweepFunction.def("Nb2dCurves", (Standard_Integer (Approx_SweepFunction::*)() const ) &Approx_SweepFunction::Nb2dCurves, "get the number of 2d curves to approximate.");
	cls_Approx_SweepFunction.def("SectionShape", (void (Approx_SweepFunction::*)(Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &Approx_SweepFunction::SectionShape, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
	cls_Approx_SweepFunction.def("Knots", (void (Approx_SweepFunction::*)(TColStd_Array1OfReal &) const ) &Approx_SweepFunction::Knots, "get the Knots of the section", py::arg("TKnots"));
	cls_Approx_SweepFunction.def("Mults", (void (Approx_SweepFunction::*)(TColStd_Array1OfInteger &) const ) &Approx_SweepFunction::Mults, "get the Multplicities of the section", py::arg("TMults"));
	cls_Approx_SweepFunction.def("IsRational", (Standard_Boolean (Approx_SweepFunction::*)() const ) &Approx_SweepFunction::IsRational, "Returns if the sections are rationnal or not");
	cls_Approx_SweepFunction.def("NbIntervals", (Standard_Integer (Approx_SweepFunction::*)(const GeomAbs_Shape) const ) &Approx_SweepFunction::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_Approx_SweepFunction.def("Intervals", (void (Approx_SweepFunction::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &Approx_SweepFunction::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_Approx_SweepFunction.def("SetInterval", (void (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real)) &Approx_SweepFunction::SetInterval, "Sets the bounds of the parametric interval on the fonction This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
	cls_Approx_SweepFunction.def("Resolution", (void (Approx_SweepFunction::*)(const Standard_Integer, const Standard_Real, Standard_Real &, Standard_Real &) const ) &Approx_SweepFunction::Resolution, "Returns the resolutions in the sub-space 2d <Index> This information is usfull to find an good tolerance in 2d approximation.", py::arg("Index"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
	cls_Approx_SweepFunction.def("GetTolerance", (void (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const ) &Approx_SweepFunction::GetTolerance, "Returns the tolerance to reach in approximation to satisfy. BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
	cls_Approx_SweepFunction.def("SetTolerance", (void (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real)) &Approx_SweepFunction::SetTolerance, "Is usefull, if (me) have to run numerical algorithm to perform D0, D1 or D2", py::arg("Tol3d"), py::arg("Tol2d"));
	cls_Approx_SweepFunction.def("BarycentreOfSurf", (gp_Pnt (Approx_SweepFunction::*)() const ) &Approx_SweepFunction::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditioned rational approximation. Warning: Used only if <me> IsRational");
	cls_Approx_SweepFunction.def("MaximalSection", (Standard_Real (Approx_SweepFunction::*)() const ) &Approx_SweepFunction::MaximalSection, "Returns the length of the greater section. This information is usefull to G1's control. Warning: With an little value, approximation can be slower.");
	cls_Approx_SweepFunction.def("GetMinimalWeight", (void (Approx_SweepFunction::*)(TColStd_Array1OfReal &) const ) &Approx_SweepFunction::GetMinimalWeight, "Compute the minimal value of weight for each poles in all sections. This information is usefull to control error in rational approximation. Warning: Used only if <me> IsRational", py::arg("Weigths"));
	cls_Approx_SweepFunction.def_static("get_type_name_", (const char * (*)()) &Approx_SweepFunction::get_type_name, "None");
	cls_Approx_SweepFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Approx_SweepFunction::get_type_descriptor, "None");
	cls_Approx_SweepFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Approx_SweepFunction::*)() const ) &Approx_SweepFunction::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_SweepApproximation.hxx
	py::class_<Approx_SweepApproximation, std::unique_ptr<Approx_SweepApproximation, Deleter<Approx_SweepApproximation>>> cls_Approx_SweepApproximation(mod, "Approx_SweepApproximation", "Approximation of an Surface S(u,v) (and eventually associate 2d Curves) defined by section's law.");
	cls_Approx_SweepApproximation.def(py::init<const opencascade::handle<Approx_SweepFunction> &>(), py::arg("Func"));
	cls_Approx_SweepApproximation.def("Perform", [](Approx_SweepApproximation &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); }, py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"), py::arg("TolAngular"));
	cls_Approx_SweepApproximation.def("Perform", [](Approx_SweepApproximation &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const GeomAbs_Shape a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); }, py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"));
	cls_Approx_SweepApproximation.def("Perform", [](Approx_SweepApproximation &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const GeomAbs_Shape a6, const Standard_Integer a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"), py::arg("Degmax"));
	// FIXME cls_Approx_SweepApproximation.def("Perform", (void (Approx_SweepApproximation::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &Approx_SweepApproximation::Perform, "Perform the Approximation [First, Last] : Approx_SweepApproximation.cdl Tol3d : Tolerance to surface approximation Tol2d : Tolerance used to perform curve approximation Normaly the 2d curve are approximated with a tolerance given by the resolution on support surfaces, but if this tolerance is too large Tol2d is used. TolAngular : Tolerance (in radian) to control the angle beetween tangents on the section law and tangent of iso-v on approximed surface Continuity : The continuity in v waiting on the surface Degmax : The maximum degree in v requiered on the surface Segmax : The maximum number of span in v requiered on the surface Warning : The continuity ci can be obtained only if Ft is Ci", py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"), py::arg("TolAngular"), py::arg("Continuity"), py::arg("Degmax"), py::arg("Segmax"));
	cls_Approx_SweepApproximation.def("Eval", (Standard_Integer (Approx_SweepApproximation::*)(const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real, Standard_Real &)) &Approx_SweepApproximation::Eval, "The EvaluatorFunction from AdvApprox;", py::arg("Parameter"), py::arg("DerivativeRequest"), py::arg("First"), py::arg("Last"), py::arg("Result"));
	cls_Approx_SweepApproximation.def("IsDone", (Standard_Boolean (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::IsDone, "returns if we have an result");
	cls_Approx_SweepApproximation.def("SurfShape", (void (Approx_SweepApproximation::*)(Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &Approx_SweepApproximation::SurfShape, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
	cls_Approx_SweepApproximation.def("Surface", (void (Approx_SweepApproximation::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const ) &Approx_SweepApproximation::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
	cls_Approx_SweepApproximation.def("UDegree", (Standard_Integer (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::UDegree, "None");
	cls_Approx_SweepApproximation.def("VDegree", (Standard_Integer (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::VDegree, "None");
	cls_Approx_SweepApproximation.def("SurfPoles", (const TColgp_Array2OfPnt & (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::SurfPoles, "None");
	cls_Approx_SweepApproximation.def("SurfWeights", (const TColStd_Array2OfReal & (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::SurfWeights, "None");
	cls_Approx_SweepApproximation.def("SurfUKnots", (const TColStd_Array1OfReal & (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::SurfUKnots, "None");
	cls_Approx_SweepApproximation.def("SurfVKnots", (const TColStd_Array1OfReal & (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::SurfVKnots, "None");
	cls_Approx_SweepApproximation.def("SurfUMults", (const TColStd_Array1OfInteger & (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::SurfUMults, "None");
	cls_Approx_SweepApproximation.def("SurfVMults", (const TColStd_Array1OfInteger & (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::SurfVMults, "None");
	cls_Approx_SweepApproximation.def("MaxErrorOnSurf", (Standard_Real (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::MaxErrorOnSurf, "returns the maximum error in the suface approximation.");
	cls_Approx_SweepApproximation.def("AverageErrorOnSurf", (Standard_Real (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::AverageErrorOnSurf, "returns the average error in the suface approximation.");
	cls_Approx_SweepApproximation.def("NbCurves2d", (Standard_Integer (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::NbCurves2d, "None");
	cls_Approx_SweepApproximation.def("Curves2dShape", (void (Approx_SweepApproximation::*)(Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &Approx_SweepApproximation::Curves2dShape, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
	cls_Approx_SweepApproximation.def("Curve2d", (void (Approx_SweepApproximation::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const ) &Approx_SweepApproximation::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
	cls_Approx_SweepApproximation.def("Curves2dDegree", (Standard_Integer (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::Curves2dDegree, "None");
	cls_Approx_SweepApproximation.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (Approx_SweepApproximation::*)(const Standard_Integer) const ) &Approx_SweepApproximation::Curve2dPoles, "None", py::arg("Index"));
	cls_Approx_SweepApproximation.def("Curves2dKnots", (const TColStd_Array1OfReal & (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::Curves2dKnots, "None");
	cls_Approx_SweepApproximation.def("Curves2dMults", (const TColStd_Array1OfInteger & (Approx_SweepApproximation::*)() const ) &Approx_SweepApproximation::Curves2dMults, "None");
	cls_Approx_SweepApproximation.def("Max2dError", (Standard_Real (Approx_SweepApproximation::*)(const Standard_Integer) const ) &Approx_SweepApproximation::Max2dError, "returns the maximum error of the <Index> 2d curve approximation.", py::arg("Index"));
	cls_Approx_SweepApproximation.def("Average2dError", (Standard_Real (Approx_SweepApproximation::*)(const Standard_Integer) const ) &Approx_SweepApproximation::Average2dError, "returns the average error of the <Index> 2d curve approximation.", py::arg("Index"));
	cls_Approx_SweepApproximation.def("TolCurveOnSurf", (Standard_Real (Approx_SweepApproximation::*)(const Standard_Integer) const ) &Approx_SweepApproximation::TolCurveOnSurf, "returns the maximum 3d error of the <Index> 2d curve approximation on the Surface.", py::arg("Index"));
	// FIXME cls_Approx_SweepApproximation.def("Dump", (void (Approx_SweepApproximation::*)(Standard_OStream &) const ) &Approx_SweepApproximation::Dump, "display information on approximation.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Approx_SequenceOfHArray1OfReal, std::unique_ptr<Approx_SequenceOfHArray1OfReal, Deleter<Approx_SequenceOfHArray1OfReal>>, NCollection_BaseSequence> cls_Approx_SequenceOfHArray1OfReal(mod, "Approx_SequenceOfHArray1OfReal", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Approx_SequenceOfHArray1OfReal.def(py::init<>());
	cls_Approx_SequenceOfHArray1OfReal.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Approx_SequenceOfHArray1OfReal.def(py::init([] (const Approx_SequenceOfHArray1OfReal &other) {return new Approx_SequenceOfHArray1OfReal(other);}), "Copy constructor", py::arg("other"));
	cls_Approx_SequenceOfHArray1OfReal.def("begin", (Approx_SequenceOfHArray1OfReal::iterator (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Approx_SequenceOfHArray1OfReal.def("end", (Approx_SequenceOfHArray1OfReal::iterator (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Approx_SequenceOfHArray1OfReal.def("cbegin", (Approx_SequenceOfHArray1OfReal::const_iterator (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Approx_SequenceOfHArray1OfReal.def("cend", (Approx_SequenceOfHArray1OfReal::const_iterator (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Approx_SequenceOfHArray1OfReal.def("Size", (Standard_Integer (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::Size, "Number of items");
	cls_Approx_SequenceOfHArray1OfReal.def("Length", (Standard_Integer (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::Length, "Number of items");
	cls_Approx_SequenceOfHArray1OfReal.def("Lower", (Standard_Integer (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::Lower, "Method for consistency with other collections.");
	cls_Approx_SequenceOfHArray1OfReal.def("Upper", (Standard_Integer (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::Upper, "Method for consistency with other collections.");
	cls_Approx_SequenceOfHArray1OfReal.def("IsEmpty", (Standard_Boolean (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::IsEmpty, "Empty query");
	cls_Approx_SequenceOfHArray1OfReal.def("Reverse", (void (Approx_SequenceOfHArray1OfReal::*)()) &Approx_SequenceOfHArray1OfReal::Reverse, "Reverse sequence");
	cls_Approx_SequenceOfHArray1OfReal.def("Exchange", (void (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer, const Standard_Integer)) &Approx_SequenceOfHArray1OfReal::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Approx_SequenceOfHArray1OfReal.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Approx_SequenceOfHArray1OfReal::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Approx_SequenceOfHArray1OfReal.def("Clear", [](Approx_SequenceOfHArray1OfReal &self) -> void { return self.Clear(); });
	cls_Approx_SequenceOfHArray1OfReal.def("Clear", (void (Approx_SequenceOfHArray1OfReal::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Approx_SequenceOfHArray1OfReal::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Approx_SequenceOfHArray1OfReal.def("Assign", (Approx_SequenceOfHArray1OfReal & (Approx_SequenceOfHArray1OfReal::*)(const Approx_SequenceOfHArray1OfReal &)) &Approx_SequenceOfHArray1OfReal::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Approx_SequenceOfHArray1OfReal.def("assign", (Approx_SequenceOfHArray1OfReal & (Approx_SequenceOfHArray1OfReal::*)(const Approx_SequenceOfHArray1OfReal &)) &Approx_SequenceOfHArray1OfReal::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Approx_SequenceOfHArray1OfReal.def("Remove", (void (Approx_SequenceOfHArray1OfReal::*)(Approx_SequenceOfHArray1OfReal::Iterator &)) &Approx_SequenceOfHArray1OfReal::Remove, "Remove one item", py::arg("thePosition"));
	cls_Approx_SequenceOfHArray1OfReal.def("Remove", (void (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer)) &Approx_SequenceOfHArray1OfReal::Remove, "Remove one item", py::arg("theIndex"));
	cls_Approx_SequenceOfHArray1OfReal.def("Remove", (void (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer, const Standard_Integer)) &Approx_SequenceOfHArray1OfReal::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Approx_SequenceOfHArray1OfReal.def("Append", (void (Approx_SequenceOfHArray1OfReal::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &Approx_SequenceOfHArray1OfReal::Append, "Append one item", py::arg("theItem"));
	cls_Approx_SequenceOfHArray1OfReal.def("Append", (void (Approx_SequenceOfHArray1OfReal::*)(Approx_SequenceOfHArray1OfReal &)) &Approx_SequenceOfHArray1OfReal::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Approx_SequenceOfHArray1OfReal.def("Prepend", (void (Approx_SequenceOfHArray1OfReal::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &Approx_SequenceOfHArray1OfReal::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Approx_SequenceOfHArray1OfReal.def("Prepend", (void (Approx_SequenceOfHArray1OfReal::*)(Approx_SequenceOfHArray1OfReal &)) &Approx_SequenceOfHArray1OfReal::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Approx_SequenceOfHArray1OfReal.def("InsertBefore", (void (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &)) &Approx_SequenceOfHArray1OfReal::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Approx_SequenceOfHArray1OfReal.def("InsertBefore", (void (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer, Approx_SequenceOfHArray1OfReal &)) &Approx_SequenceOfHArray1OfReal::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Approx_SequenceOfHArray1OfReal.def("InsertAfter", (void (Approx_SequenceOfHArray1OfReal::*)(Approx_SequenceOfHArray1OfReal::Iterator &, const opencascade::handle<TColStd_HArray1OfReal> &)) &Approx_SequenceOfHArray1OfReal::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Approx_SequenceOfHArray1OfReal.def("InsertAfter", (void (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer, Approx_SequenceOfHArray1OfReal &)) &Approx_SequenceOfHArray1OfReal::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Approx_SequenceOfHArray1OfReal.def("InsertAfter", (void (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &)) &Approx_SequenceOfHArray1OfReal::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Approx_SequenceOfHArray1OfReal.def("Split", (void (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer, Approx_SequenceOfHArray1OfReal &)) &Approx_SequenceOfHArray1OfReal::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Approx_SequenceOfHArray1OfReal.def("First", (const opencascade::handle<TColStd_HArray1OfReal> & (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::First, "First item access");
	cls_Approx_SequenceOfHArray1OfReal.def("ChangeFirst", (opencascade::handle<TColStd_HArray1OfReal> & (Approx_SequenceOfHArray1OfReal::*)()) &Approx_SequenceOfHArray1OfReal::ChangeFirst, "First item access");
	cls_Approx_SequenceOfHArray1OfReal.def("Last", (const opencascade::handle<TColStd_HArray1OfReal> & (Approx_SequenceOfHArray1OfReal::*)() const ) &Approx_SequenceOfHArray1OfReal::Last, "Last item access");
	cls_Approx_SequenceOfHArray1OfReal.def("ChangeLast", (opencascade::handle<TColStd_HArray1OfReal> & (Approx_SequenceOfHArray1OfReal::*)()) &Approx_SequenceOfHArray1OfReal::ChangeLast, "Last item access");
	cls_Approx_SequenceOfHArray1OfReal.def("Value", (const opencascade::handle<TColStd_HArray1OfReal> & (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer) const ) &Approx_SequenceOfHArray1OfReal::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Approx_SequenceOfHArray1OfReal.def("__call__", (const opencascade::handle<TColStd_HArray1OfReal> & (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer) const ) &Approx_SequenceOfHArray1OfReal::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Approx_SequenceOfHArray1OfReal.def("ChangeValue", (opencascade::handle<TColStd_HArray1OfReal> & (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer)) &Approx_SequenceOfHArray1OfReal::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Approx_SequenceOfHArray1OfReal.def("__call__", (opencascade::handle<TColStd_HArray1OfReal> & (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer)) &Approx_SequenceOfHArray1OfReal::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Approx_SequenceOfHArray1OfReal.def("SetValue", (void (Approx_SequenceOfHArray1OfReal::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &)) &Approx_SequenceOfHArray1OfReal::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Approx_SequenceOfHArray1OfReal.def("__iter__", [](const Approx_SequenceOfHArray1OfReal &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_HArray1OfAdHSurface.hxx
	py::class_<Approx_HArray1OfAdHSurface, opencascade::handle<Approx_HArray1OfAdHSurface>, Approx_Array1OfAdHSurface, Standard_Transient> cls_Approx_HArray1OfAdHSurface(mod, "Approx_HArray1OfAdHSurface", "None");
	cls_Approx_HArray1OfAdHSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Approx_HArray1OfAdHSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Approx_Array1OfAdHSurface::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_Approx_HArray1OfAdHSurface.def(py::init<const Approx_Array1OfAdHSurface &>(), py::arg("theOther"));
	cls_Approx_HArray1OfAdHSurface.def("Array1", (const Approx_Array1OfAdHSurface & (Approx_HArray1OfAdHSurface::*)() const ) &Approx_HArray1OfAdHSurface::Array1, "None");
	cls_Approx_HArray1OfAdHSurface.def("ChangeArray1", (Approx_Array1OfAdHSurface & (Approx_HArray1OfAdHSurface::*)()) &Approx_HArray1OfAdHSurface::ChangeArray1, "None");
	cls_Approx_HArray1OfAdHSurface.def_static("get_type_name_", (const char * (*)()) &Approx_HArray1OfAdHSurface::get_type_name, "None");
	cls_Approx_HArray1OfAdHSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Approx_HArray1OfAdHSurface::get_type_descriptor, "None");
	cls_Approx_HArray1OfAdHSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Approx_HArray1OfAdHSurface::*)() const ) &Approx_HArray1OfAdHSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Approx_HArray1OfGTrsf2d.hxx
	py::class_<Approx_HArray1OfGTrsf2d, opencascade::handle<Approx_HArray1OfGTrsf2d>, Approx_Array1OfGTrsf2d, Standard_Transient> cls_Approx_HArray1OfGTrsf2d(mod, "Approx_HArray1OfGTrsf2d", "None");
	cls_Approx_HArray1OfGTrsf2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Approx_HArray1OfGTrsf2d.def(py::init<const Standard_Integer, const Standard_Integer, const Approx_Array1OfGTrsf2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_Approx_HArray1OfGTrsf2d.def(py::init<const Approx_Array1OfGTrsf2d &>(), py::arg("theOther"));
	cls_Approx_HArray1OfGTrsf2d.def("Array1", (const Approx_Array1OfGTrsf2d & (Approx_HArray1OfGTrsf2d::*)() const ) &Approx_HArray1OfGTrsf2d::Array1, "None");
	cls_Approx_HArray1OfGTrsf2d.def("ChangeArray1", (Approx_Array1OfGTrsf2d & (Approx_HArray1OfGTrsf2d::*)()) &Approx_HArray1OfGTrsf2d::ChangeArray1, "None");
	cls_Approx_HArray1OfGTrsf2d.def_static("get_type_name_", (const char * (*)()) &Approx_HArray1OfGTrsf2d::get_type_name, "None");
	cls_Approx_HArray1OfGTrsf2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Approx_HArray1OfGTrsf2d::get_type_descriptor, "None");
	cls_Approx_HArray1OfGTrsf2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Approx_HArray1OfGTrsf2d::*)() const ) &Approx_HArray1OfGTrsf2d::DynamicType, "None");


}
