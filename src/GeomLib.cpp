#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomLib_CheckCurveOnSurface.hxx>
#include <AdvApprox_ApproxAFunction.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <GeomLib_MakeCurvefromApprox.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomLib_InterpolationErrors.hxx>
#include <GeomLib_Interpolate.hxx>
#include <Geom_BSplineSurface.hxx>
#include <GeomLib_DenominatorMultiplier.hxx>
#include <GeomLib_CheckBSplineCurve.hxx>
#include <GeomLib_Check2dBSplineCurve.hxx>
#include <gp_Pln.hxx>
#include <GeomLib_IsPlanarSurface.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <GeomLib_Tool.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <math_Vector.hxx>
#include <GeomLib_PolyFunc.hxx>
#include <math_FunctionSample.hxx>
#include <GeomLib_LogSample.hxx>
#include <gp_Ax2.hxx>
#include <gp_GTrsf2d.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_BoundedCurve.hxx>
#include <gp_Vec.hxx>
#include <Geom_BoundedSurface.hxx>
#include <gp_Dir.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Geom_BezierSurface.hxx>
#include <GeomLib.hxx>
#include <NCollection_Array1.hxx>
#include <GeomLib_Array1OfMat.hxx>
#include <GeomLib_DenominatorMultiplierPtr.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(GeomLib, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.AdvApprox");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.math");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_InterpolationErrors.hxx
	py::enum_<GeomLib_InterpolationErrors>(mod, "GeomLib_InterpolationErrors", "in case the interpolation errors out, this tells what happened")
		.value("GeomLib_NoError", GeomLib_InterpolationErrors::GeomLib_NoError)
		.value("GeomLib_NotEnoughtPoints", GeomLib_InterpolationErrors::GeomLib_NotEnoughtPoints)
		.value("GeomLib_DegreeSmallerThan3", GeomLib_InterpolationErrors::GeomLib_DegreeSmallerThan3)
		.value("GeomLib_InversionProblem", GeomLib_InterpolationErrors::GeomLib_InversionProblem)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_CheckCurveOnSurface.hxx
	py::class_<GeomLib_CheckCurveOnSurface, std::unique_ptr<GeomLib_CheckCurveOnSurface, Deleter<GeomLib_CheckCurveOnSurface>>> cls_GeomLib_CheckCurveOnSurface(mod, "GeomLib_CheckCurveOnSurface", "Computes the max distance between 3D-curve and 2D-curve in some surface.");
	cls_GeomLib_CheckCurveOnSurface.def(py::init<>());
	cls_GeomLib_CheckCurveOnSurface.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirst"), py::arg("theLast"));
	cls_GeomLib_CheckCurveOnSurface.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirst"), py::arg("theLast"), py::arg("theTolRange"));
	cls_GeomLib_CheckCurveOnSurface.def("Init", [](GeomLib_CheckCurveOnSurface &self, const opencascade::handle<Geom_Curve> & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Init(a0, a1, a2, a3); }, py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirst"), py::arg("theLast"));
	cls_GeomLib_CheckCurveOnSurface.def("Init", (void (GeomLib_CheckCurveOnSurface::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib_CheckCurveOnSurface::Init, "Sets the data for the algorithm", py::arg("theCurve"), py::arg("theSurface"), py::arg("theFirst"), py::arg("theLast"), py::arg("theTolRange"));
	cls_GeomLib_CheckCurveOnSurface.def("Init", (void (GeomLib_CheckCurveOnSurface::*)()) &GeomLib_CheckCurveOnSurface::Init, "Initializes all members by dafault values");
	cls_GeomLib_CheckCurveOnSurface.def("Perform", [](GeomLib_CheckCurveOnSurface &self, const opencascade::handle<Geom2d_Curve> & a0) -> void { return self.Perform(a0); }, py::arg("thePCurve"));
	cls_GeomLib_CheckCurveOnSurface.def("Perform", (void (GeomLib_CheckCurveOnSurface::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Boolean)) &GeomLib_CheckCurveOnSurface::Perform, "Computes the max distance for the 3d curve <myCurve> and 2d curve <thePCurve> If isTheMultyTheadDisabled == TRUE then computation will be made without any parallelization.", py::arg("thePCurve"), py::arg("isTheMultyTheradDisabled"));
	cls_GeomLib_CheckCurveOnSurface.def("Curve", (const opencascade::handle<Geom_Curve> & (GeomLib_CheckCurveOnSurface::*)() const ) &GeomLib_CheckCurveOnSurface::Curve, "Returns my3DCurve");
	cls_GeomLib_CheckCurveOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (GeomLib_CheckCurveOnSurface::*)() const ) &GeomLib_CheckCurveOnSurface::Surface, "Returns mySurface");
	cls_GeomLib_CheckCurveOnSurface.def("Range", [](GeomLib_CheckCurveOnSurface &self, Standard_Real & theFirst, Standard_Real & theLast){ self.Range(theFirst, theLast); return std::tuple<Standard_Real &, Standard_Real &>(theFirst, theLast); }, "Returns first and last parameter of the curves (2D- and 3D-curves are considered to have same range)", py::arg("theFirst"), py::arg("theLast"));
	cls_GeomLib_CheckCurveOnSurface.def("IsDone", (Standard_Boolean (GeomLib_CheckCurveOnSurface::*)() const ) &GeomLib_CheckCurveOnSurface::IsDone, "Returns true if the max distance has been found");
	cls_GeomLib_CheckCurveOnSurface.def("ErrorStatus", (Standard_Integer (GeomLib_CheckCurveOnSurface::*)() const ) &GeomLib_CheckCurveOnSurface::ErrorStatus, "Returns error status The possible values are: 0 - OK; 1 - null curve or surface or 2d curve; 2 - invalid parametric range; 3 - error in calculations.");
	cls_GeomLib_CheckCurveOnSurface.def("MaxDistance", (Standard_Real (GeomLib_CheckCurveOnSurface::*)() const ) &GeomLib_CheckCurveOnSurface::MaxDistance, "Returns max distance");
	cls_GeomLib_CheckCurveOnSurface.def("MaxParameter", (Standard_Real (GeomLib_CheckCurveOnSurface::*)() const ) &GeomLib_CheckCurveOnSurface::MaxParameter, "Returns parameter in which the distance is maximal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_MakeCurvefromApprox.hxx
	py::class_<GeomLib_MakeCurvefromApprox, std::unique_ptr<GeomLib_MakeCurvefromApprox, Deleter<GeomLib_MakeCurvefromApprox>>> cls_GeomLib_MakeCurvefromApprox(mod, "GeomLib_MakeCurvefromApprox", "this class is used to construct the BSpline curve from an Approximation ( ApproxAFunction from AdvApprox).");
	cls_GeomLib_MakeCurvefromApprox.def(py::init<const AdvApprox_ApproxAFunction &>(), py::arg("Approx"));
	cls_GeomLib_MakeCurvefromApprox.def("IsDone", (Standard_Boolean (GeomLib_MakeCurvefromApprox::*)() const ) &GeomLib_MakeCurvefromApprox::IsDone, "None");
	cls_GeomLib_MakeCurvefromApprox.def("Nb1DSpaces", (Standard_Integer (GeomLib_MakeCurvefromApprox::*)() const ) &GeomLib_MakeCurvefromApprox::Nb1DSpaces, "returns the number of 1D spaces of the Approx");
	cls_GeomLib_MakeCurvefromApprox.def("Nb2DSpaces", (Standard_Integer (GeomLib_MakeCurvefromApprox::*)() const ) &GeomLib_MakeCurvefromApprox::Nb2DSpaces, "returns the number of 3D spaces of the Approx");
	cls_GeomLib_MakeCurvefromApprox.def("Nb3DSpaces", (Standard_Integer (GeomLib_MakeCurvefromApprox::*)() const ) &GeomLib_MakeCurvefromApprox::Nb3DSpaces, "returns the number of 3D spaces of the Approx");
	cls_GeomLib_MakeCurvefromApprox.def("Curve2d", (opencascade::handle<Geom2d_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer) const ) &GeomLib_MakeCurvefromApprox::Curve2d, "returns a polynomial curve whose poles correspond to the Index2d 2D space if Index2d not in the Range [1,Nb2dSpaces] if the Approx is not Done", py::arg("Index2d"));
	cls_GeomLib_MakeCurvefromApprox.def("Curve2dFromTwo1d", (opencascade::handle<Geom2d_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer, const Standard_Integer) const ) &GeomLib_MakeCurvefromApprox::Curve2dFromTwo1d, "returns a 2D curve building it from the 1D curve in x at Index1d and y at Index2d amongst the 1D curves if Index1d not in the Range [1,Nb1dSpaces] if Index2d not in the Range [1,Nb1dSpaces] if the Approx is not Done", py::arg("Index1d"), py::arg("Index2d"));
	cls_GeomLib_MakeCurvefromApprox.def("Curve2d", (opencascade::handle<Geom2d_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer, const Standard_Integer) const ) &GeomLib_MakeCurvefromApprox::Curve2d, "returns a rational curve whose poles correspond to the index2d of the 2D space and whose weights correspond to one dimensional space of index 1d if Index1d not in the Range [1,Nb1dSpaces] if Index2d not in the Range [1,Nb2dSpaces] if the Approx is not Done", py::arg("Index1d"), py::arg("Index2d"));
	cls_GeomLib_MakeCurvefromApprox.def("Curve", (opencascade::handle<Geom_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer) const ) &GeomLib_MakeCurvefromApprox::Curve, "returns a polynomial curve whose poles correspond to the Index3D 3D space if Index3D not in the Range [1,Nb3dSpaces] if the Approx is not Done", py::arg("Index3d"));
	cls_GeomLib_MakeCurvefromApprox.def("Curve", (opencascade::handle<Geom_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer, const Standard_Integer) const ) &GeomLib_MakeCurvefromApprox::Curve, "returns a rational curve whose poles correspond to the index3D of the 3D space and whose weights correspond to the index1d 1D space. if Index1D not in the Range [1,Nb1dSpaces] if Index3D not in the Range [1,Nb3dSpaces] if the Approx is not Done", py::arg("Index1D"), py::arg("Index3D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_Interpolate.hxx
	py::class_<GeomLib_Interpolate, std::unique_ptr<GeomLib_Interpolate, Deleter<GeomLib_Interpolate>>> cls_GeomLib_Interpolate(mod, "GeomLib_Interpolate", "this class is used to construct a BSpline curve by interpolation of points at given parameters The continuity of the curve is degree - 1 and the method used when boundary condition are not given is to use odd degrees and null the derivatives on both sides from degree -1 down to (degree+1) / 2 When even degree is given the returned curve is of degree - 1 so that the degree of the curve is odd");
	cls_GeomLib_Interpolate.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &>(), py::arg("Degree"), py::arg("NumPoints"), py::arg("Points"), py::arg("Parameters"));
	cls_GeomLib_Interpolate.def("IsDone", (Standard_Boolean (GeomLib_Interpolate::*)() const ) &GeomLib_Interpolate::IsDone, "returns if everything went OK");
	cls_GeomLib_Interpolate.def("Error", (GeomLib_InterpolationErrors (GeomLib_Interpolate::*)() const ) &GeomLib_Interpolate::Error, "returns the error type if any");
	cls_GeomLib_Interpolate.def("Curve", (opencascade::handle<Geom_BSplineCurve> (GeomLib_Interpolate::*)() const ) &GeomLib_Interpolate::Curve, "returns the interpolated curve of the requested degree");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_DenominatorMultiplier.hxx
	py::class_<GeomLib_DenominatorMultiplier, std::unique_ptr<GeomLib_DenominatorMultiplier, Deleter<GeomLib_DenominatorMultiplier>>> cls_GeomLib_DenominatorMultiplier(mod, "GeomLib_DenominatorMultiplier", "this defines an evaluator for a function of 2 variables that will be used by CancelDenominatorDerivative in one direction.");
	cls_GeomLib_DenominatorMultiplier.def(py::init<const opencascade::handle<Geom_BSplineSurface> &, const TColStd_Array1OfReal &>(), py::arg("Surface"), py::arg("KnotVector"));
	cls_GeomLib_DenominatorMultiplier.def("Value", (Standard_Real (GeomLib_DenominatorMultiplier::*)(const Standard_Real, const Standard_Real) const ) &GeomLib_DenominatorMultiplier::Value, "Returns the value of a(UParameter,VParameter)=", py::arg("UParameter"), py::arg("VParameter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_CheckBSplineCurve.hxx
	py::class_<GeomLib_CheckBSplineCurve, std::unique_ptr<GeomLib_CheckBSplineCurve, Deleter<GeomLib_CheckBSplineCurve>>> cls_GeomLib_CheckBSplineCurve(mod, "GeomLib_CheckBSplineCurve", "Checks for the end tangents : wether or not those are reversed regarding the third or n-3rd control");
	cls_GeomLib_CheckBSplineCurve.def(py::init<const opencascade::handle<Geom_BSplineCurve> &, const Standard_Real, const Standard_Real>(), py::arg("Curve"), py::arg("Tolerance"), py::arg("AngularTolerance"));
	cls_GeomLib_CheckBSplineCurve.def("IsDone", (Standard_Boolean (GeomLib_CheckBSplineCurve::*)() const ) &GeomLib_CheckBSplineCurve::IsDone, "None");
	cls_GeomLib_CheckBSplineCurve.def("NeedTangentFix", [](GeomLib_CheckBSplineCurve &self, Standard_Boolean & FirstFlag, Standard_Boolean & SecondFlag){ self.NeedTangentFix(FirstFlag, SecondFlag); return std::tuple<Standard_Boolean &, Standard_Boolean &>(FirstFlag, SecondFlag); }, "None", py::arg("FirstFlag"), py::arg("SecondFlag"));
	cls_GeomLib_CheckBSplineCurve.def("FixTangent", (void (GeomLib_CheckBSplineCurve::*)(const Standard_Boolean, const Standard_Boolean)) &GeomLib_CheckBSplineCurve::FixTangent, "None", py::arg("FirstFlag"), py::arg("LastFlag"));
	cls_GeomLib_CheckBSplineCurve.def("FixedTangent", (opencascade::handle<Geom_BSplineCurve> (GeomLib_CheckBSplineCurve::*)(const Standard_Boolean, const Standard_Boolean)) &GeomLib_CheckBSplineCurve::FixedTangent, "modifies the curve by fixing the first or the last tangencies", py::arg("FirstFlag"), py::arg("LastFlag"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_Check2dBSplineCurve.hxx
	py::class_<GeomLib_Check2dBSplineCurve, std::unique_ptr<GeomLib_Check2dBSplineCurve, Deleter<GeomLib_Check2dBSplineCurve>>> cls_GeomLib_Check2dBSplineCurve(mod, "GeomLib_Check2dBSplineCurve", "Checks for the end tangents : wether or not those are reversed");
	cls_GeomLib_Check2dBSplineCurve.def(py::init<const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real, const Standard_Real>(), py::arg("Curve"), py::arg("Tolerance"), py::arg("AngularTolerance"));
	cls_GeomLib_Check2dBSplineCurve.def("IsDone", (Standard_Boolean (GeomLib_Check2dBSplineCurve::*)() const ) &GeomLib_Check2dBSplineCurve::IsDone, "None");
	cls_GeomLib_Check2dBSplineCurve.def("NeedTangentFix", [](GeomLib_Check2dBSplineCurve &self, Standard_Boolean & FirstFlag, Standard_Boolean & SecondFlag){ self.NeedTangentFix(FirstFlag, SecondFlag); return std::tuple<Standard_Boolean &, Standard_Boolean &>(FirstFlag, SecondFlag); }, "None", py::arg("FirstFlag"), py::arg("SecondFlag"));
	cls_GeomLib_Check2dBSplineCurve.def("FixTangent", (void (GeomLib_Check2dBSplineCurve::*)(const Standard_Boolean, const Standard_Boolean)) &GeomLib_Check2dBSplineCurve::FixTangent, "None", py::arg("FirstFlag"), py::arg("LastFlag"));
	cls_GeomLib_Check2dBSplineCurve.def("FixedTangent", (opencascade::handle<Geom2d_BSplineCurve> (GeomLib_Check2dBSplineCurve::*)(const Standard_Boolean, const Standard_Boolean)) &GeomLib_Check2dBSplineCurve::FixedTangent, "modifies the curve by fixing the first or the last tangencies", py::arg("FirstFlag"), py::arg("LastFlag"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_IsPlanarSurface.hxx
	py::class_<GeomLib_IsPlanarSurface, std::unique_ptr<GeomLib_IsPlanarSurface, Deleter<GeomLib_IsPlanarSurface>>> cls_GeomLib_IsPlanarSurface(mod, "GeomLib_IsPlanarSurface", "Find if a surface is a planar surface.");
	cls_GeomLib_IsPlanarSurface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
	cls_GeomLib_IsPlanarSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S"), py::arg("Tol"));
	cls_GeomLib_IsPlanarSurface.def("IsPlanar", (Standard_Boolean (GeomLib_IsPlanarSurface::*)() const ) &GeomLib_IsPlanarSurface::IsPlanar, "Return if the Surface is a plan");
	cls_GeomLib_IsPlanarSurface.def("Plan", (const gp_Pln & (GeomLib_IsPlanarSurface::*)() const ) &GeomLib_IsPlanarSurface::Plan, "Return the plan definition");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_Tool.hxx
	py::class_<GeomLib_Tool, std::unique_ptr<GeomLib_Tool, Deleter<GeomLib_Tool>>> cls_GeomLib_Tool(mod, "GeomLib_Tool", "Provides various methods with Geom2d and Geom curves and surfaces. The methods of this class compute the parameter(s) of a given point on a curve or a surface. To get the valid result the point must be located rather close to the curve (surface) or at least to allow getting unambiguous result (do not put point at center of circle...), but choice of 'trust' distance between curve/surface and point is responcibility of user (parameter MaxDist). Return FALSE if the point is beyond the MaxDist limit or if computation fails.");
	cls_GeomLib_Tool.def(py::init<>());
	cls_GeomLib_Tool.def_static("Parameter_", [](const opencascade::handle<Geom_Curve> & Curve, const gp_Pnt & Point, const Standard_Real MaxDist, Standard_Real & U){ Standard_Boolean rv = GeomLib_Tool::Parameter(Curve, Point, MaxDist, U); return std::tuple<Standard_Boolean, Standard_Real &>(rv, U); }, "Extracts the parameter of a 3D point lying on a 3D curve or at a distance less than the MaxDist value.", py::arg("Curve"), py::arg("Point"), py::arg("MaxDist"), py::arg("U"));
	cls_GeomLib_Tool.def_static("Parameters_", [](const opencascade::handle<Geom_Surface> & Surface, const gp_Pnt & Point, const Standard_Real MaxDist, Standard_Real & U, Standard_Real & V){ Standard_Boolean rv = GeomLib_Tool::Parameters(Surface, Point, MaxDist, U, V); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, U, V); }, "Extracts the parameter of a 3D point lying on a surface or at a distance less than the MaxDist value.", py::arg("Surface"), py::arg("Point"), py::arg("MaxDist"), py::arg("U"), py::arg("V"));
	cls_GeomLib_Tool.def_static("Parameter_", [](const opencascade::handle<Geom2d_Curve> & Curve, const gp_Pnt2d & Point, const Standard_Real MaxDist, Standard_Real & U){ Standard_Boolean rv = GeomLib_Tool::Parameter(Curve, Point, MaxDist, U); return std::tuple<Standard_Boolean, Standard_Real &>(rv, U); }, "Extracts the parameter of a 2D point lying on a 2D curve or at a distance less than the MaxDist value.", py::arg("Curve"), py::arg("Point"), py::arg("MaxDist"), py::arg("U"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_PolyFunc.hxx
	py::class_<GeomLib_PolyFunc, std::unique_ptr<GeomLib_PolyFunc, Deleter<GeomLib_PolyFunc>>, math_FunctionWithDerivative> cls_GeomLib_PolyFunc(mod, "GeomLib_PolyFunc", "Polynomial Function");
	cls_GeomLib_PolyFunc.def(py::init<const math_Vector &>(), py::arg("Coeffs"));
	cls_GeomLib_PolyFunc.def("Value", [](GeomLib_PolyFunc &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F>of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"));
	cls_GeomLib_PolyFunc.def("Derivative", [](GeomLib_PolyFunc &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
	cls_GeomLib_PolyFunc.def("Values", [](GeomLib_PolyFunc &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_LogSample.hxx
	py::class_<GeomLib_LogSample, std::unique_ptr<GeomLib_LogSample, Deleter<GeomLib_LogSample>>, math_FunctionSample> cls_GeomLib_LogSample(mod, "GeomLib_LogSample", "None");
	cls_GeomLib_LogSample.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("A"), py::arg("B"), py::arg("N"));
	cls_GeomLib_LogSample.def("GetParameter", (Standard_Real (GeomLib_LogSample::*)(const Standard_Integer) const ) &GeomLib_LogSample::GetParameter, "Returns the value of parameter of the point of range Index : A + ((Index-1)/(NbPoints-1))*B. An exception is raised if Index<=0 or Index>NbPoints.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib.hxx
	py::class_<GeomLib, std::unique_ptr<GeomLib, Deleter<GeomLib>>> cls_GeomLib(mod, "GeomLib", "Geom Library. This package provides an implementation of functions for basic computation on geometric entity from packages Geom and Geom2d.");
	cls_GeomLib.def(py::init<>());
	cls_GeomLib.def_static("To3d_", (opencascade::handle<Geom_Curve> (*)(const gp_Ax2 &, const opencascade::handle<Geom2d_Curve> &)) &GeomLib::To3d, "Computes the curve 3d from package Geom corresponding to curve 2d from package Geom2d, on the plan defined with the local coordinate system Position.", py::arg("Position"), py::arg("Curve2d"));
	cls_GeomLib.def_static("GTransform_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom2d_Curve> &, const gp_GTrsf2d &)) &GeomLib::GTransform, "Computes the curve 3d from package Geom corresponding to the curve 3d from package Geom, transformed with the transformation <GTrsf> WARNING : this method may return a null Handle if it's impossible to compute the transformation of a curve. It's not implemented when : 1) the curve is an infinite parabola or hyperbola 2) the curve is an offsetcurve", py::arg("Curve"), py::arg("GTrsf"));
	cls_GeomLib.def_static("SameRange_", (void (*)(const Standard_Real, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, opencascade::handle<Geom2d_Curve> &)) &GeomLib::SameRange, "Make the curve Curve2dPtr have the imposed range First to List the most economic way, that is if it can change the range without changing the nature of the curve it will try to do that. Otherwise it will produce a Bspline curve that has the required range", py::arg("Tolerance"), py::arg("Curve2dPtr"), py::arg("First"), py::arg("Last"), py::arg("RequestedFirst"), py::arg("RequestedLast"), py::arg("NewCurve2dPtr"));
	cls_GeomLib.def_static("BuildCurve3d_", [](const Standard_Real Tolerance, Adaptor3d_CurveOnSurface & CurvePtr, const Standard_Real FirstParameter, const Standard_Real LastParameter, opencascade::handle<Geom_Curve> & NewCurvePtr, Standard_Real & MaxDeviation, Standard_Real & AverageDeviation, const GeomAbs_Shape Continuity, const Standard_Integer MaxDegree, const Standard_Integer MaxSegment){ GeomLib::BuildCurve3d(Tolerance, CurvePtr, FirstParameter, LastParameter, NewCurvePtr, MaxDeviation, AverageDeviation, Continuity, MaxDegree, MaxSegment); return std::tuple<Standard_Real &, Standard_Real &>(MaxDeviation, AverageDeviation); }, "None", py::arg("Tolerance"), py::arg("CurvePtr"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("NewCurvePtr"), py::arg("MaxDeviation"), py::arg("AverageDeviation"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegment"));
	cls_GeomLib.def_static("AdjustExtremity_", (void (*)(opencascade::handle<Geom_BoundedCurve> &, const gp_Pnt &, const gp_Pnt &, const gp_Vec &, const gp_Vec &)) &GeomLib::AdjustExtremity, "None", py::arg("Curve"), py::arg("P1"), py::arg("P2"), py::arg("T1"), py::arg("T2"));
	cls_GeomLib.def_static("ExtendCurveToPoint_", (void (*)(opencascade::handle<Geom_BoundedCurve> &, const gp_Pnt &, const Standard_Integer, const Standard_Boolean)) &GeomLib::ExtendCurveToPoint, "Extends the bounded curve Curve to the point Point. The extension is built: - at the end of the curve if After equals true, or - at the beginning of the curve if After equals false. The extension is performed according to a degree of continuity equal to Cont, which in its turn must be equal to 1, 2 or 3. This function converts the bounded curve Curve into a BSpline curve. Warning - Nothing is done, and Curve is not modified if Cont is not equal to 1, 2 or 3. - It is recommended that the extension should not be too large with respect to the size of the bounded curve Curve: Point must not be located too far from one of the extremities of Curve.", py::arg("Curve"), py::arg("Point"), py::arg("Cont"), py::arg("After"));
	cls_GeomLib.def_static("ExtendSurfByLength_", (void (*)(opencascade::handle<Geom_BoundedSurface> &, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean)) &GeomLib::ExtendSurfByLength, "Extends the bounded surface Surf along one of its boundaries. The chord length of the extension is equal to Length. The direction of the extension is given as: - the u parametric direction of Surf, if InU equals true, or - the v parametric direction of Surf, if InU equals false. In this parametric direction, the extension is built on the side of: - the last parameter of Surf, if After equals true, or - the first parameter of Surf, if After equals false. The extension is performed according to a degree of continuity equal to Cont, which in its turn must be equal to 1, 2 or 3. This function converts the bounded surface Surf into a BSpline surface. Warning - Nothing is done, and Surf is not modified if Cont is not equal to 1, 2 or 3. - It is recommended that Length, the size of the extension should not be too large with respect to the size of the bounded surface Surf. - Surf must not be a periodic BSpline surface in the parametric direction corresponding to the direction of extension.", py::arg("Surf"), py::arg("Length"), py::arg("Cont"), py::arg("InU"), py::arg("After"));
	cls_GeomLib.def_static("AxeOfInertia_", [](const TColgp_Array1OfPnt & Points, gp_Ax2 & Axe, Standard_Boolean & IsSingular, const Standard_Real Tol){ GeomLib::AxeOfInertia(Points, Axe, IsSingular, Tol); return IsSingular; }, "Compute axes of inertia, of some points -- -- -- <Axe>.Location() is the BaryCentre -- -- -- -- -- <Axe>.XDirection is the axe of upper inertia -- -- -- -- <Axe>.Direction is the Normal to the average plane -- -- -- IsSingular is True if points are on line -- Tol is used to determine singular cases.", py::arg("Points"), py::arg("Axe"), py::arg("IsSingular"), py::arg("Tol"));
	cls_GeomLib.def_static("Inertia_", [](const TColgp_Array1OfPnt & Points, gp_Pnt & Bary, gp_Dir & XDir, gp_Dir & YDir, Standard_Real & Xgap, Standard_Real & YGap, Standard_Real & ZGap){ GeomLib::Inertia(Points, Bary, XDir, YDir, Xgap, YGap, ZGap); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Xgap, YGap, ZGap); }, "Compute principale axes of inertia, and dispertion value of some points.", py::arg("Points"), py::arg("Bary"), py::arg("XDir"), py::arg("YDir"), py::arg("Xgap"), py::arg("YGap"), py::arg("ZGap"));
	cls_GeomLib.def_static("RemovePointsFromArray_", (void (*)(const Standard_Integer, const TColStd_Array1OfReal &, opencascade::handle<TColStd_HArray1OfReal> &)) &GeomLib::RemovePointsFromArray, "Warning! This assume that the InParameter is an increasing sequence of real number and it will not check for that : Unpredictable result can happen if this is not satisfied. It is the caller responsability to check for that property.", py::arg("NumPoints"), py::arg("InParameters"), py::arg("OutParameters"));
	cls_GeomLib.def_static("DensifyArray1OfReal_", (void (*)(const Standard_Integer, const TColStd_Array1OfReal &, opencascade::handle<TColStd_HArray1OfReal> &)) &GeomLib::DensifyArray1OfReal, "this makes sure that there is at least MinNumPoints in OutParameters taking into account the parameters in the InParameters array provided those are in order, that is the sequence of real in the InParameter is strictly non decreasing", py::arg("MinNumPoints"), py::arg("InParameters"), py::arg("OutParameters"));
	cls_GeomLib.def_static("FuseIntervals_", [](const TColStd_Array1OfReal & a0, const TColStd_Array1OfReal & a1, TColStd_SequenceOfReal & a2) -> void { return GeomLib::FuseIntervals(a0, a1, a2); }, py::arg("Interval1"), py::arg("Interval2"), py::arg("Fusion"));
	cls_GeomLib.def_static("FuseIntervals_", (void (*)(const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, TColStd_SequenceOfReal &, const Standard_Real)) &GeomLib::FuseIntervals, "None", py::arg("Interval1"), py::arg("Interval2"), py::arg("Fusion"), py::arg("Confusion"));
	cls_GeomLib.def_static("EvalMaxParametricDistance_", [](const Adaptor3d_Curve & Curve, const Adaptor3d_Curve & AReferenceCurve, const Standard_Real Tolerance, const TColStd_Array1OfReal & Parameters, Standard_Real & MaxDistance){ GeomLib::EvalMaxParametricDistance(Curve, AReferenceCurve, Tolerance, Parameters, MaxDistance); return MaxDistance; }, "this will compute the maximum distance at the parameters given in the Parameters array by evaluating each parameter the two curves and taking the maximum of the evaluated distance", py::arg("Curve"), py::arg("AReferenceCurve"), py::arg("Tolerance"), py::arg("Parameters"), py::arg("MaxDistance"));
	cls_GeomLib.def_static("EvalMaxDistanceAlongParameter_", [](const Adaptor3d_Curve & Curve, const Adaptor3d_Curve & AReferenceCurve, const Standard_Real Tolerance, const TColStd_Array1OfReal & Parameters, Standard_Real & MaxDistance){ GeomLib::EvalMaxDistanceAlongParameter(Curve, AReferenceCurve, Tolerance, Parameters, MaxDistance); return MaxDistance; }, "this will compute the maximum distancef at the parameters given in the Parameters array by projecting from the Curve to the reference curve and taking the minimum distance Than the maximum will be taken on those minimas.", py::arg("Curve"), py::arg("AReferenceCurve"), py::arg("Tolerance"), py::arg("Parameters"), py::arg("MaxDistance"));
	cls_GeomLib.def_static("CancelDenominatorDerivative_", (void (*)(opencascade::handle<Geom_BSplineSurface> &, const Standard_Boolean, const Standard_Boolean)) &GeomLib::CancelDenominatorDerivative, "Cancel,on the boudaries,the denominator first derivative in the directions wished by the user and set its value to 1.", py::arg("BSurf"), py::arg("UDirection"), py::arg("VDirection"));
	cls_GeomLib.def_static("NormEstim_", (Standard_Integer (*)(const opencascade::handle<Geom_Surface> &, const gp_Pnt2d &, const Standard_Real, gp_Dir &)) &GeomLib::NormEstim, "None", py::arg("S"), py::arg("UV"), py::arg("Tol"), py::arg("N"));
	cls_GeomLib.def_static("IsClosed_", [](const opencascade::handle<Geom_Surface> & S, const Standard_Real Tol, Standard_Boolean & isUClosed, Standard_Boolean & isVClosed){ GeomLib::IsClosed(S, Tol, isUClosed, isVClosed); return std::tuple<Standard_Boolean &, Standard_Boolean &>(isUClosed, isVClosed); }, "This method defines if opposite boundaries of surface coincide with given tolerance", py::arg("S"), py::arg("Tol"), py::arg("isUClosed"), py::arg("isVClosed"));
	cls_GeomLib.def_static("IsBSplUClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib::IsBSplUClosed, "Returns true if the poles of U1 isoline and the poles of U2 isoline of surface are identical according to tolerance criterion. For rational surfaces Weights(i)*Poles(i) are checked.", py::arg("S"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
	cls_GeomLib.def_static("IsBSplVClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib::IsBSplVClosed, "Returns true if the poles of V1 isoline and the poles of V2 isoline of surface are identical according to tolerance criterion. For rational surfaces Weights(i)*Poles(i) are checked.", py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("Tol"));
	cls_GeomLib.def_static("IsBzUClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_BezierSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib::IsBzUClosed, "Returns true if the poles of U1 isoline and the poles of U2 isoline of surface are identical according to tolerance criterion.", py::arg("S"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
	cls_GeomLib.def_static("IsBzVClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_BezierSurface> &, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomLib::IsBzVClosed, "Returns true if the poles of V1 isoline and the poles of V2 isoline of surface are identical according to tolerance criterion.", py::arg("S"), py::arg("V1"), py::arg("V2"), py::arg("Tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_Array1OfMat.hxx
	bind_NCollection_Array1<gp_Mat>(mod, "GeomLib_Array1OfMat");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomLib_DenominatorMultiplierPtr.hxx

}
