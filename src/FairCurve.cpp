#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <FairCurve_AnalysisCode.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Standard_OStream.hxx>
#include <FairCurve_Batten.hxx>
#include <FairCurve_MinimalVariation.hxx>
#include <math_Function.hxx>
#include <FairCurve_BattenLaw.hxx>
#include <math_FunctionSet.hxx>
#include <math_Vector.hxx>
#include <FairCurve_DistributionOfEnergy.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <FairCurve_DistributionOfJerk.hxx>
#include <FairCurve_DistributionOfSagging.hxx>
#include <FairCurve_DistributionOfTension.hxx>
#include <math_MultipleVarFunctionWithHessian.hxx>
#include <math_Matrix.hxx>
#include <FairCurve_Energy.hxx>
#include <FairCurve_EnergyOfBatten.hxx>
#include <FairCurve_EnergyOfMVC.hxx>
#include <math_NewtonMinimum.hxx>
#include <FairCurve_Newton.hxx>

PYBIND11_MODULE(FairCurve, mod) {

	// IMPORT
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.math");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TColgp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_AnalysisCode.hxx
	py::enum_<FairCurve_AnalysisCode>(mod, "FairCurve_AnalysisCode", "To deal with different results in the computation of curvatures. - FairCurve_OK describes the case where computation is successfully completed - FairCurve_NotConverged describes the case where the algorithm does not converge. In this case, you can not be certain of the result quality and should resume computation if you want to make use of the curve. - FairCurve_InfiniteSliding describes the case where sliding is infinite, and, consequently, computation stops. The solution is to use an imposed sliding value. - FairCurve_NullHeight describes the case where no matter is left at one of the ends of the curve, and as a result, computation stops. The solution is to change (increase or reduce) the slope value by increasing or decreasing it.")
		.value("FairCurve_OK", FairCurve_AnalysisCode::FairCurve_OK)
		.value("FairCurve_NotConverged", FairCurve_AnalysisCode::FairCurve_NotConverged)
		.value("FairCurve_InfiniteSliding", FairCurve_AnalysisCode::FairCurve_InfiniteSliding)
		.value("FairCurve_NullHeight", FairCurve_AnalysisCode::FairCurve_NullHeight)
		.export_values();

	// FUNCTIONS
	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_MinimalVariation.lxx
	mod.def("operator<<", (Standard_OStream & (*)(Standard_OStream &, const FairCurve_MinimalVariation &)) &operator<<, "None", py::arg("o"), py::arg("MVC"));
	*/

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_Batten.hxx
	py::class_<FairCurve_Batten, std::unique_ptr<FairCurve_Batten, Deleter<FairCurve_Batten>>> cls_FairCurve_Batten(mod, "FairCurve_Batten", "Constructs curves with a constant or linearly increasing section to be used in the design of wooden or plastic battens. These curves are two-dimensional, and simulate physical splines or battens.");
	cls_FairCurve_Batten.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Height"));
	cls_FairCurve_Batten.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Height"), py::arg("Slope"));
	cls_FairCurve_Batten.def("SetFreeSliding", (void (FairCurve_Batten::*)(const Standard_Boolean)) &FairCurve_Batten::SetFreeSliding, "Freesliding is initialized with the default setting false. When Freesliding is set to true and, as a result, sliding is free, the sliding factor is automatically computed to satisfy the equilibrium of the batten.", py::arg("FreeSliding"));
	cls_FairCurve_Batten.def("SetConstraintOrder1", (void (FairCurve_Batten::*)(const Standard_Integer)) &FairCurve_Batten::SetConstraintOrder1, "Allows you to change the order of the constraint on the first point. ConstraintOrder has the default setting of 1. The following settings are available: - 0-the curve must pass through a point - 1-the curve must pass through a point and have a given tangent - 2-the curve must pass through a point, have a given tangent and a given curvature. The third setting is only valid for FairCurve_MinimalVariation curves. These constraints, though geometric, represent the mechanical constraints due, for example, to the resistance of the material the actual physical batten is made of.", py::arg("ConstraintOrder"));
	cls_FairCurve_Batten.def("SetConstraintOrder2", (void (FairCurve_Batten::*)(const Standard_Integer)) &FairCurve_Batten::SetConstraintOrder2, "Allows you to change the order of the constraint on the second point. ConstraintOrder is initialized with the default setting of 1. The following settings are available: - 0-the curve must pass through a point - 1-the curve must pass through a point and have a given tangent - 2-the curve must pass through a point, have a given tangent and a given curvature. The third setting is only valid for FairCurve_MinimalVariation curves. These constraints, though geometric, represent the mechanical constraints due, for example, to the resistance of the material the actual physical batten is made of.", py::arg("ConstraintOrder"));
	cls_FairCurve_Batten.def("SetP1", (void (FairCurve_Batten::*)(const gp_Pnt2d &)) &FairCurve_Batten::SetP1, "Allows you to change the location of the point, P1, and in doing so, modify the curve. Warning This method changes the angle as well as the point. Exceptions NullValue if the distance between P1 and P2 is less than or equal to the tolerance value for distance in Precision::Confusion: P1.IsEqual(P2, Precision::Confusion()). The function gp_Pnt2d::IsEqual tests to see if this is the case.", py::arg("P1"));
	cls_FairCurve_Batten.def("SetP2", (void (FairCurve_Batten::*)(const gp_Pnt2d &)) &FairCurve_Batten::SetP2, "Allows you to change the location of the point, P1, and in doing so, modify the curve. Warning This method changes the angle as well as the point. Exceptions NullValue if the distance between P1 and P2 is less than or equal to the tolerance value for distance in Precision::Confusion: P1.IsEqual(P2, Precision::Confusion()). The function gp_Pnt2d::IsEqual tests to see if this is the case.", py::arg("P2"));
	cls_FairCurve_Batten.def("SetAngle1", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetAngle1, "Allows you to change the angle Angle1 at the first point, P1. The default setting is 0.", py::arg("Angle1"));
	cls_FairCurve_Batten.def("SetAngle2", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetAngle2, "Allows you to change the angle Angle2 at the second point, P2. The default setting is 0.", py::arg("Angle2"));
	cls_FairCurve_Batten.def("SetHeight", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetHeight, "Allows you to change the height of the deformation. Raises NegativeValue; -- if Height <= 0 if Height <= 0", py::arg("Height"));
	cls_FairCurve_Batten.def("SetSlope", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetSlope, "Allows you to set the slope value, Slope.", py::arg("Slope"));
	cls_FairCurve_Batten.def("SetSlidingFactor", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetSlidingFactor, "Allows you to change the ratio SlidingFactor. This compares the length of the batten and the reference length, which is, in turn, a function of the constraints. This modification has one of the following two effects: - if you increase the value, it inflates the batten - if you decrease the value, it flattens the batten. When sliding is free, the sliding factor is automatically computed to satisfy the equilibrium of the batten. When sliding is imposed, a value is required for the sliding factor. SlidingFactor is initialized with the default setting of 1.", py::arg("SlidingFactor"));
	cls_FairCurve_Batten.def("Compute", [](FairCurve_Batten &self, FairCurve_AnalysisCode & a0) -> Standard_Boolean { return self.Compute(a0); }, py::arg("Code"));
	cls_FairCurve_Batten.def("Compute", [](FairCurve_Batten &self, FairCurve_AnalysisCode & a0, const Standard_Integer a1) -> Standard_Boolean { return self.Compute(a0, a1); }, py::arg("Code"), py::arg("NbIterations"));
	cls_FairCurve_Batten.def("Compute", (Standard_Boolean (FairCurve_Batten::*)(FairCurve_AnalysisCode &, const Standard_Integer, const Standard_Real)) &FairCurve_Batten::Compute, "Performs the algorithm, using the arguments Code, NbIterations and Tolerance and computes the curve with respect to the constraints. Code will have one of the following values: - OK - NotConverged - InfiniteSliding - NullHeight The parameters Tolerance and NbIterations control how precise the computation is, and how long it will take.", py::arg("Code"), py::arg("NbIterations"), py::arg("Tolerance"));
	cls_FairCurve_Batten.def("SlidingOfReference", (Standard_Real (FairCurve_Batten::*)() const ) &FairCurve_Batten::SlidingOfReference, "Computes the real number value for length Sliding of Reference for new constraints. If you want to give a specific length to a batten curve, use the following syntax: b.SetSlidingFactor(L / b.SlidingOfReference()) where b is the name of the batten curve object.");
	cls_FairCurve_Batten.def("GetFreeSliding", (Standard_Boolean (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetFreeSliding, "Returns the initial free sliding value, false by default. Free sliding is generally more aesthetically pleasing than constrained sliding. However, the computation can fail with values such as angles greater than PI/2. This is because the resulting batten length is theoretically infinite.");
	cls_FairCurve_Batten.def("GetConstraintOrder1", (Standard_Integer (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetConstraintOrder1, "Returns the established first constraint order.");
	cls_FairCurve_Batten.def("GetConstraintOrder2", (Standard_Integer (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetConstraintOrder2, "Returns the established second constraint order.");
	cls_FairCurve_Batten.def("GetP1", (const gp_Pnt2d & (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetP1, "Returns the established location of the point P1.");
	cls_FairCurve_Batten.def("GetP2", (const gp_Pnt2d & (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetP2, "Returns the established location of the point P2.");
	cls_FairCurve_Batten.def("GetAngle1", (Standard_Real (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetAngle1, "Returns the established first angle.");
	cls_FairCurve_Batten.def("GetAngle2", (Standard_Real (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetAngle2, "Returns the established second angle.");
	cls_FairCurve_Batten.def("GetHeight", (Standard_Real (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetHeight, "Returns the thickness of the lathe.");
	cls_FairCurve_Batten.def("GetSlope", (Standard_Real (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetSlope, "Returns the established slope value.");
	cls_FairCurve_Batten.def("GetSlidingFactor", (Standard_Real (FairCurve_Batten::*)() const ) &FairCurve_Batten::GetSlidingFactor, "Returns the initial sliding factor.");
	cls_FairCurve_Batten.def("Curve", (opencascade::handle<Geom2d_BSplineCurve> (FairCurve_Batten::*)() const ) &FairCurve_Batten::Curve, "Returns the computed curve a 2d BSpline.");
	// FIXME cls_FairCurve_Batten.def("Dump", (void (FairCurve_Batten::*)(Standard_OStream &) const ) &FairCurve_Batten::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_BattenLaw.hxx
	py::class_<FairCurve_BattenLaw, std::unique_ptr<FairCurve_BattenLaw, Deleter<FairCurve_BattenLaw>>, math_Function> cls_FairCurve_BattenLaw(mod, "FairCurve_BattenLaw", "This class compute the Heigth of an batten");
	cls_FairCurve_BattenLaw.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Heigth"), py::arg("Slope"), py::arg("Sliding"));
	cls_FairCurve_BattenLaw.def("SetSliding", (void (FairCurve_BattenLaw::*)(const Standard_Real)) &FairCurve_BattenLaw::SetSliding, "Change the value of sliding", py::arg("Sliding"));
	cls_FairCurve_BattenLaw.def("SetHeigth", (void (FairCurve_BattenLaw::*)(const Standard_Real)) &FairCurve_BattenLaw::SetHeigth, "Change the value of Heigth at the middle point.", py::arg("Heigth"));
	cls_FairCurve_BattenLaw.def("SetSlope", (void (FairCurve_BattenLaw::*)(const Standard_Real)) &FairCurve_BattenLaw::SetSlope, "Change the value of the geometric slope.", py::arg("Slope"));
	cls_FairCurve_BattenLaw.def("Value", (Standard_Boolean (FairCurve_BattenLaw::*)(const Standard_Real, Standard_Real &)) &FairCurve_BattenLaw::Value, "computes the value of the heigth for the parameter T on the neutral fibber", py::arg("T"), py::arg("THeigth"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_DistributionOfEnergy.hxx
	py::class_<FairCurve_DistributionOfEnergy, std::unique_ptr<FairCurve_DistributionOfEnergy, Deleter<FairCurve_DistributionOfEnergy>>, math_FunctionSet> cls_FairCurve_DistributionOfEnergy(mod, "FairCurve_DistributionOfEnergy", "Abstract class to use the Energy of an FairCurve");
	cls_FairCurve_DistributionOfEnergy.def("NbVariables", (Standard_Integer (FairCurve_DistributionOfEnergy::*)() const ) &FairCurve_DistributionOfEnergy::NbVariables, "returns the number of variables of the function.");
	cls_FairCurve_DistributionOfEnergy.def("NbEquations", (Standard_Integer (FairCurve_DistributionOfEnergy::*)() const ) &FairCurve_DistributionOfEnergy::NbEquations, "returns the number of equations of the function.");
	cls_FairCurve_DistributionOfEnergy.def("SetDerivativeOrder", (void (FairCurve_DistributionOfEnergy::*)(const Standard_Integer)) &FairCurve_DistributionOfEnergy::SetDerivativeOrder, "None", py::arg("DerivativeOrder"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_DistributionOfJerk.hxx
	py::class_<FairCurve_DistributionOfJerk, std::unique_ptr<FairCurve_DistributionOfJerk, Deleter<FairCurve_DistributionOfJerk>>, FairCurve_DistributionOfEnergy> cls_FairCurve_DistributionOfJerk(mod, "FairCurve_DistributionOfJerk", "Compute the 'Jerk' distribution.");
	cls_FairCurve_DistributionOfJerk.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const FairCurve_BattenLaw &>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("Law"));
	cls_FairCurve_DistributionOfJerk.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Integer>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("Law"), py::arg("NbValAux"));
	cls_FairCurve_DistributionOfJerk.def("Value", (Standard_Boolean (FairCurve_DistributionOfJerk::*)(const math_Vector &, math_Vector &)) &FairCurve_DistributionOfJerk::Value, "computes the values <F> of the functions for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_DistributionOfSagging.hxx
	py::class_<FairCurve_DistributionOfSagging, std::unique_ptr<FairCurve_DistributionOfSagging, Deleter<FairCurve_DistributionOfSagging>>, FairCurve_DistributionOfEnergy> cls_FairCurve_DistributionOfSagging(mod, "FairCurve_DistributionOfSagging", "Compute the Sagging Distribution");
	cls_FairCurve_DistributionOfSagging.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const FairCurve_BattenLaw &>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("Law"));
	cls_FairCurve_DistributionOfSagging.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Integer>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("Law"), py::arg("NbValAux"));
	cls_FairCurve_DistributionOfSagging.def("Value", (Standard_Boolean (FairCurve_DistributionOfSagging::*)(const math_Vector &, math_Vector &)) &FairCurve_DistributionOfSagging::Value, "computes the values <F> of the functions for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_DistributionOfTension.hxx
	py::class_<FairCurve_DistributionOfTension, std::unique_ptr<FairCurve_DistributionOfTension, Deleter<FairCurve_DistributionOfTension>>, FairCurve_DistributionOfEnergy> cls_FairCurve_DistributionOfTension(mod, "FairCurve_DistributionOfTension", "Compute the Tension Distribution");
	cls_FairCurve_DistributionOfTension.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Real, const FairCurve_BattenLaw &>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("LengthSliding"), py::arg("Law"));
	cls_FairCurve_DistributionOfTension.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Real, const FairCurve_BattenLaw &, const Standard_Integer>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("LengthSliding"), py::arg("Law"), py::arg("NbValAux"));
	cls_FairCurve_DistributionOfTension.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Real, const FairCurve_BattenLaw &, const Standard_Integer, const Standard_Boolean>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("DerivativeOrder"), py::arg("LengthSliding"), py::arg("Law"), py::arg("NbValAux"), py::arg("Uniform"));
	cls_FairCurve_DistributionOfTension.def("SetLengthSliding", (void (FairCurve_DistributionOfTension::*)(const Standard_Real)) &FairCurve_DistributionOfTension::SetLengthSliding, "change the length sliding", py::arg("LengthSliding"));
	cls_FairCurve_DistributionOfTension.def("Value", (Standard_Boolean (FairCurve_DistributionOfTension::*)(const math_Vector &, math_Vector &)) &FairCurve_DistributionOfTension::Value, "computes the values <F> of the functions for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_Energy.hxx
	py::class_<FairCurve_Energy, std::unique_ptr<FairCurve_Energy, Deleter<FairCurve_Energy>>, math_MultipleVarFunctionWithHessian> cls_FairCurve_Energy(mod, "FairCurve_Energy", "necessary methodes to compute the energy of an FairCurve.");
	cls_FairCurve_Energy.def("NbVariables", (Standard_Integer (FairCurve_Energy::*)() const ) &FairCurve_Energy::NbVariables, "returns the number of variables of the energy.");
	cls_FairCurve_Energy.def("Value", (Standard_Boolean (FairCurve_Energy::*)(const math_Vector &, Standard_Real &)) &FairCurve_Energy::Value, "computes the values of the Energys E for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("E"));
	cls_FairCurve_Energy.def("Gradient", (Standard_Boolean (FairCurve_Energy::*)(const math_Vector &, math_Vector &)) &FairCurve_Energy::Gradient, "computes the gradient <G> of the energys for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("G"));
	cls_FairCurve_Energy.def("Values", (Standard_Boolean (FairCurve_Energy::*)(const math_Vector &, Standard_Real &, math_Vector &)) &FairCurve_Energy::Values, "computes the Energy <E> and the gradient <G> of the energy for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("E"), py::arg("G"));
	cls_FairCurve_Energy.def("Values", (Standard_Boolean (FairCurve_Energy::*)(const math_Vector &, Standard_Real &, math_Vector &, math_Matrix &)) &FairCurve_Energy::Values, "computes the Energy <E>, the gradient <G> and the Hessian <H> of the energy for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("E"), py::arg("G"), py::arg("H"));
	cls_FairCurve_Energy.def("Variable", (Standard_Boolean (FairCurve_Energy::*)(math_Vector &) const ) &FairCurve_Energy::Variable, "compute the variables <X> wich correspond with the field <MyPoles>", py::arg("X"));
	cls_FairCurve_Energy.def("Poles", (const opencascade::handle<TColgp_HArray1OfPnt2d> & (FairCurve_Energy::*)() const ) &FairCurve_Energy::Poles, "return the poles");

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_EnergyOfBatten.hxx
	py::class_<FairCurve_EnergyOfBatten, std::unique_ptr<FairCurve_EnergyOfBatten, Deleter<FairCurve_EnergyOfBatten>>, FairCurve_Energy> cls_FairCurve_EnergyOfBatten(mod, "FairCurve_EnergyOfBatten", "Energy Criterium to minimize in Batten.");
	cls_FairCurve_EnergyOfBatten.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("LengthSliding"));
	cls_FairCurve_EnergyOfBatten.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Boolean>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("LengthSliding"), py::arg("FreeSliding"));
	cls_FairCurve_EnergyOfBatten.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("LengthSliding"), py::arg("FreeSliding"), py::arg("Angle1"));
	cls_FairCurve_EnergyOfBatten.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("LengthSliding"), py::arg("FreeSliding"), py::arg("Angle1"), py::arg("Angle2"));
	cls_FairCurve_EnergyOfBatten.def("LengthSliding", (Standard_Real (FairCurve_EnergyOfBatten::*)() const ) &FairCurve_EnergyOfBatten::LengthSliding, "return the lengthSliding = P1P2 + Sliding");
	cls_FairCurve_EnergyOfBatten.def("Status", (FairCurve_AnalysisCode (FairCurve_EnergyOfBatten::*)() const ) &FairCurve_EnergyOfBatten::Status, "return the status");
	cls_FairCurve_EnergyOfBatten.def("Variable", (Standard_Boolean (FairCurve_EnergyOfBatten::*)(math_Vector &) const ) &FairCurve_EnergyOfBatten::Variable, "compute the variables <X> wich correspond with the field <MyPoles>", py::arg("X"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_EnergyOfMVC.hxx
	py::class_<FairCurve_EnergyOfMVC, std::unique_ptr<FairCurve_EnergyOfMVC, Deleter<FairCurve_EnergyOfMVC>>, FairCurve_Energy> cls_FairCurve_EnergyOfMVC(mod, "FairCurve_EnergyOfMVC", "Energy Criterium to minimize in MinimalVariationCurve.");
	cls_FairCurve_EnergyOfMVC.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("PhysicalRatio"), py::arg("LengthSliding"));
	cls_FairCurve_EnergyOfMVC.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("PhysicalRatio"), py::arg("LengthSliding"), py::arg("FreeSliding"));
	cls_FairCurve_EnergyOfMVC.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("PhysicalRatio"), py::arg("LengthSliding"), py::arg("FreeSliding"), py::arg("Angle1"));
	cls_FairCurve_EnergyOfMVC.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("PhysicalRatio"), py::arg("LengthSliding"), py::arg("FreeSliding"), py::arg("Angle1"), py::arg("Angle2"));
	cls_FairCurve_EnergyOfMVC.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("PhysicalRatio"), py::arg("LengthSliding"), py::arg("FreeSliding"), py::arg("Angle1"), py::arg("Angle2"), py::arg("Curvature1"));
	cls_FairCurve_EnergyOfMVC.def(py::init<const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfPnt2d> &, const Standard_Integer, const Standard_Integer, const FairCurve_BattenLaw &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("BSplOrder"), py::arg("FlatKnots"), py::arg("Poles"), py::arg("ContrOrder1"), py::arg("ContrOrder2"), py::arg("Law"), py::arg("PhysicalRatio"), py::arg("LengthSliding"), py::arg("FreeSliding"), py::arg("Angle1"), py::arg("Angle2"), py::arg("Curvature1"), py::arg("Curvature2"));
	cls_FairCurve_EnergyOfMVC.def("LengthSliding", (Standard_Real (FairCurve_EnergyOfMVC::*)() const ) &FairCurve_EnergyOfMVC::LengthSliding, "return the lengthSliding = P1P2 + Sliding");
	cls_FairCurve_EnergyOfMVC.def("Status", (FairCurve_AnalysisCode (FairCurve_EnergyOfMVC::*)() const ) &FairCurve_EnergyOfMVC::Status, "return the status");
	cls_FairCurve_EnergyOfMVC.def("Variable", (Standard_Boolean (FairCurve_EnergyOfMVC::*)(math_Vector &) const ) &FairCurve_EnergyOfMVC::Variable, "compute the variables <X> wich correspond with the field <MyPoles>", py::arg("X"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_MinimalVariation.hxx
	py::class_<FairCurve_MinimalVariation, std::unique_ptr<FairCurve_MinimalVariation, Deleter<FairCurve_MinimalVariation>>, FairCurve_Batten> cls_FairCurve_MinimalVariation(mod, "FairCurve_MinimalVariation", "Computes a 2D curve using an algorithm which minimizes tension, sagging, and jerk energy. As in FairCurve_Batten, two reference points are used. Unlike that class, FairCurve_MinimalVariation requires curvature settings at the first and second reference points. These are defined by the rays of curvature desired at each point.");
	cls_FairCurve_MinimalVariation.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Heigth"));
	cls_FairCurve_MinimalVariation.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Heigth"), py::arg("Slope"));
	cls_FairCurve_MinimalVariation.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Heigth"), py::arg("Slope"), py::arg("PhysicalRatio"));
	cls_FairCurve_MinimalVariation.def("SetCurvature1", (void (FairCurve_MinimalVariation::*)(const Standard_Real)) &FairCurve_MinimalVariation::SetCurvature1, "Allows you to set a new constraint on curvature at the first point.", py::arg("Curvature"));
	cls_FairCurve_MinimalVariation.def("SetCurvature2", (void (FairCurve_MinimalVariation::*)(const Standard_Real)) &FairCurve_MinimalVariation::SetCurvature2, "Allows you to set a new constraint on curvature at the second point.", py::arg("Curvature"));
	cls_FairCurve_MinimalVariation.def("SetPhysicalRatio", (void (FairCurve_MinimalVariation::*)(const Standard_Real)) &FairCurve_MinimalVariation::SetPhysicalRatio, "Allows you to set the physical ratio Ratio. The kinds of energy which you can specify include: 0 is only 'Jerk' Energy 1 is only 'Sagging' Energy like batten Warning: if Ratio is 1 it is impossible to impose curvature constraints. Raises DomainError if Ratio < 0 or Ratio > 1", py::arg("Ratio"));
	cls_FairCurve_MinimalVariation.def("Compute", [](FairCurve_MinimalVariation &self, FairCurve_AnalysisCode & a0) -> Standard_Boolean { return self.Compute(a0); }, py::arg("ACode"));
	cls_FairCurve_MinimalVariation.def("Compute", [](FairCurve_MinimalVariation &self, FairCurve_AnalysisCode & a0, const Standard_Integer a1) -> Standard_Boolean { return self.Compute(a0, a1); }, py::arg("ACode"), py::arg("NbIterations"));
	cls_FairCurve_MinimalVariation.def("Compute", (Standard_Boolean (FairCurve_MinimalVariation::*)(FairCurve_AnalysisCode &, const Standard_Integer, const Standard_Real)) &FairCurve_MinimalVariation::Compute, "Computes the curve with respect to the constraints, NbIterations and Tolerance. The tolerance setting allows you to control the precision of computation, and the maximum number of iterations allows you to set a limit on computation time.", py::arg("ACode"), py::arg("NbIterations"), py::arg("Tolerance"));
	cls_FairCurve_MinimalVariation.def("GetCurvature1", (Standard_Real (FairCurve_MinimalVariation::*)() const ) &FairCurve_MinimalVariation::GetCurvature1, "Returns the first established curvature.");
	cls_FairCurve_MinimalVariation.def("GetCurvature2", (Standard_Real (FairCurve_MinimalVariation::*)() const ) &FairCurve_MinimalVariation::GetCurvature2, "Returns the second established curvature.");
	cls_FairCurve_MinimalVariation.def("GetPhysicalRatio", (Standard_Real (FairCurve_MinimalVariation::*)() const ) &FairCurve_MinimalVariation::GetPhysicalRatio, "Returns the physical ratio, or kind of energy.");
	// FIXME cls_FairCurve_MinimalVariation.def("Dump", (void (FairCurve_MinimalVariation::*)(Standard_OStream &) const ) &FairCurve_MinimalVariation::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\FairCurve_Newton.hxx
	py::class_<FairCurve_Newton, std::unique_ptr<FairCurve_Newton, Deleter<FairCurve_Newton>>, math_NewtonMinimum> cls_FairCurve_Newton(mod, "FairCurve_Newton", "Algorithme of Optimization used to make 'FairCurve'");
	cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &>(), py::arg("theFunction"));
	cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real>(), py::arg("theFunction"), py::arg("theSpatialTolerance"));
	cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Real>(), py::arg("theFunction"), py::arg("theSpatialTolerance"), py::arg("theCriteriumTolerance"));
	cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theSpatialTolerance"), py::arg("theCriteriumTolerance"), py::arg("theNbIterations"));
	cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theFunction"), py::arg("theSpatialTolerance"), py::arg("theCriteriumTolerance"), py::arg("theNbIterations"), py::arg("theConvexity"));
	cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Boolean>(), py::arg("theFunction"), py::arg("theSpatialTolerance"), py::arg("theCriteriumTolerance"), py::arg("theNbIterations"), py::arg("theConvexity"), py::arg("theWithSingularity"));
	cls_FairCurve_Newton.def("IsConverged", (Standard_Boolean (FairCurve_Newton::*)() const ) &FairCurve_Newton::IsConverged, "This method is called at the end of each iteration to check the convergence : || Xi+1 - Xi || < SpatialTolerance/100 Or || Xi+1 - Xi || < SpatialTolerance and |F(Xi+1) - F(Xi)| < CriteriumTolerance * |F(xi)| It can be redefined in a sub-class to implement a specific test.");


}
