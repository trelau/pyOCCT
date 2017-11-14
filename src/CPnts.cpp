#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <CPnts_RealFunction.hxx>
#include <math_Function.hxx>
#include <Standard_TypeDef.hxx>
#include <CPnts_MyGaussFunction.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <CPnts_MyRootFunction.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <CPnts_AbscissaPoint.hxx>
#include <gp_Pnt.hxx>
#include <CPnts_UniformDeflection.hxx>

PYBIND11_MODULE(CPnts, mod) {

	// IMPORT
	py::module::import("OCCT.math");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\CPnts_MyGaussFunction.hxx
	py::class_<CPnts_MyGaussFunction, std::unique_ptr<CPnts_MyGaussFunction, Deleter<CPnts_MyGaussFunction>>, math_Function> cls_CPnts_MyGaussFunction(mod, "CPnts_MyGaussFunction", "for implementation, compute values for Gauss");
	cls_CPnts_MyGaussFunction.def(py::init<>());
	cls_CPnts_MyGaussFunction.def("Init", (void (CPnts_MyGaussFunction::*)(const CPnts_RealFunction &, const Standard_Address)) &CPnts_MyGaussFunction::Init, "F is a pointer on a function D is a client data", py::arg("F"), py::arg("D"));
	cls_CPnts_MyGaussFunction.def("Value", (Standard_Boolean (CPnts_MyGaussFunction::*)(const Standard_Real, Standard_Real &)) &CPnts_MyGaussFunction::Value, "None", py::arg("X"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\CPnts_MyRootFunction.hxx
	py::class_<CPnts_MyRootFunction, std::unique_ptr<CPnts_MyRootFunction, Deleter<CPnts_MyRootFunction>>, math_FunctionWithDerivative> cls_CPnts_MyRootFunction(mod, "CPnts_MyRootFunction", "Implements a function for the Newton algorithm to find the solution of Integral(F) = L (compute Length and Derivative of the curve for Newton)");
	cls_CPnts_MyRootFunction.def(py::init<>());
	cls_CPnts_MyRootFunction.def("Init", (void (CPnts_MyRootFunction::*)(const CPnts_RealFunction &, const Standard_Address, const Standard_Integer)) &CPnts_MyRootFunction::Init, "F is a pointer on a function D is a client data Order is the order of integration to use", py::arg("F"), py::arg("D"), py::arg("Order"));
	cls_CPnts_MyRootFunction.def("Init", (void (CPnts_MyRootFunction::*)(const Standard_Real, const Standard_Real)) &CPnts_MyRootFunction::Init, "We want to solve Integral(X0,X,F(X,D)) = L", py::arg("X0"), py::arg("L"));
	cls_CPnts_MyRootFunction.def("Init", (void (CPnts_MyRootFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_MyRootFunction::Init, "We want to solve Integral(X0,X,F(X,D)) = L with given tolerance", py::arg("X0"), py::arg("L"), py::arg("Tol"));
	cls_CPnts_MyRootFunction.def("Value", (Standard_Boolean (CPnts_MyRootFunction::*)(const Standard_Real, Standard_Real &)) &CPnts_MyRootFunction::Value, "This is Integral(X0,X,F(X,D)) - L", py::arg("X"), py::arg("F"));
	cls_CPnts_MyRootFunction.def("Derivative", (Standard_Boolean (CPnts_MyRootFunction::*)(const Standard_Real, Standard_Real &)) &CPnts_MyRootFunction::Derivative, "This is F(X,D)", py::arg("X"), py::arg("Df"));
	cls_CPnts_MyRootFunction.def("Values", (Standard_Boolean (CPnts_MyRootFunction::*)(const Standard_Real, Standard_Real &, Standard_Real &)) &CPnts_MyRootFunction::Values, "None", py::arg("X"), py::arg("F"), py::arg("Df"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\CPnts_AbscissaPoint.hxx
	py::class_<CPnts_AbscissaPoint, std::unique_ptr<CPnts_AbscissaPoint, Deleter<CPnts_AbscissaPoint>>> cls_CPnts_AbscissaPoint(mod, "CPnts_AbscissaPoint", "the algorithm computes a point on a curve at a given distance from another point on the curve");
	cls_CPnts_AbscissaPoint.def(py::init<>());
	cls_CPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Resolution"));
	cls_CPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Resolution"));
	cls_CPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Resolution"));
	cls_CPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Resolution"));
	cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"));
	cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"));
	cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("Tol"));
	cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("Tol"));
	cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> between <U1> and <U2>.", py::arg("C"), py::arg("U1"), py::arg("U2"));
	cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> between <U1> and <U2>.", py::arg("C"), py::arg("U1"), py::arg("U2"));
	cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> between <U1> and <U2> with the given tolerance.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
	cls_CPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> between <U1> and <U2> with the given tolerance. creation of a indefinite AbscissaPoint.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
	cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor3d_Curve &)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C>.", py::arg("C"));
	cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor2d_Curve2d &)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C>.", py::arg("C"));
	cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor3d_Curve &, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C>.", py::arg("C"), py::arg("Tol"));
	cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor2d_Curve2d &, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C>.", py::arg("C"), py::arg("Tol"));
	cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C> between U1 and U2.", py::arg("C"), py::arg("U1"), py::arg("U2"));
	cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C> between U1 and U2.", py::arg("C"), py::arg("U1"), py::arg("U2"));
	cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C> between U1 and U2.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
	cls_CPnts_AbscissaPoint.def("Init", (void (CPnts_AbscissaPoint::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Init, "Initializes the resolution function with <C> between U1 and U2.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
	cls_CPnts_AbscissaPoint.def("Perform", (void (CPnts_AbscissaPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Perform, "Computes the point at the distance <Abscissa> of the curve. U0 is the parameter of the point from which the distance is measured.", py::arg("Abscissa"), py::arg("U0"), py::arg("Resolution"));
	cls_CPnts_AbscissaPoint.def("Perform", (void (CPnts_AbscissaPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::Perform, "Computes the point at the distance <Abscissa> of the curve. U0 is the parameter of the point from which the distance is measured and Ui is the starting value for the iterative process (should be close to the final solution).", py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Resolution"));
	cls_CPnts_AbscissaPoint.def("AdvPerform", (void (CPnts_AbscissaPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &CPnts_AbscissaPoint::AdvPerform, "Computes the point at the distance <Abscissa> of the curve; performs more appropriate tolerance managment; to use this method in right way it is necessary to call empty consructor. then call method Init with Tolerance = Resolution, then call AdvPermorm. U0 is the parameter of the point from which the distance is measured and Ui is the starting value for the iterative process (should be close to the final solution).", py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Resolution"));
	cls_CPnts_AbscissaPoint.def("IsDone", (Standard_Boolean (CPnts_AbscissaPoint::*)() const ) &CPnts_AbscissaPoint::IsDone, "True if the computation was successful, False otherwise.");
	cls_CPnts_AbscissaPoint.def("Parameter", (Standard_Real (CPnts_AbscissaPoint::*)() const ) &CPnts_AbscissaPoint::Parameter, "Returns the parameter of the solution.");
	cls_CPnts_AbscissaPoint.def("SetParameter", (void (CPnts_AbscissaPoint::*)(const Standard_Real)) &CPnts_AbscissaPoint::SetParameter, "Enforce the solution, used by GCPnts.", py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\CPnts_UniformDeflection.hxx
	py::class_<CPnts_UniformDeflection, std::unique_ptr<CPnts_UniformDeflection, Deleter<CPnts_UniformDeflection>>> cls_CPnts_UniformDeflection(mod, "CPnts_UniformDeflection", "This class defines an algorithm to create a set of points (with a given chordal deviation) at the positions of constant deflection of a given parametrized curve or a trimmed circle. The continuity of the curve must be at least C2.");
	cls_CPnts_UniformDeflection.def(py::init<>());
	cls_CPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("Resolution"), py::arg("WithControl"));
	cls_CPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("Resolution"), py::arg("WithControl"));
	cls_CPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Resolution"), py::arg("WithControl"));
	cls_CPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Resolution"), py::arg("WithControl"));
	cls_CPnts_UniformDeflection.def("Initialize", (void (CPnts_UniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &CPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <UStep>, <Resolution> and <WithControl>", py::arg("C"), py::arg("Deflection"), py::arg("Resolution"), py::arg("WithControl"));
	cls_CPnts_UniformDeflection.def("Initialize", (void (CPnts_UniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &CPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <UStep>, <Resolution> and <WithControl>", py::arg("C"), py::arg("Deflection"), py::arg("Resolution"), py::arg("WithControl"));
	cls_CPnts_UniformDeflection.def("Initialize", (void (CPnts_UniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &CPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <UStep>, <U1>, <U2> and <WithControl>", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Resolution"), py::arg("WithControl"));
	cls_CPnts_UniformDeflection.def("Initialize", (void (CPnts_UniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &CPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <UStep>, <U1>, <U2> and <WithControl>", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Resolution"), py::arg("WithControl"));
	cls_CPnts_UniformDeflection.def("IsAllDone", (Standard_Boolean (CPnts_UniformDeflection::*)() const ) &CPnts_UniformDeflection::IsAllDone, "To know if all the calculus were done successfully (ie all the points have been computed). The calculus can fail if the Curve is not C1 in the considered domain. Returns True if the calculus was successful.");
	cls_CPnts_UniformDeflection.def("Next", (void (CPnts_UniformDeflection::*)()) &CPnts_UniformDeflection::Next, "go to the next Point.");
	cls_CPnts_UniformDeflection.def("More", (Standard_Boolean (CPnts_UniformDeflection::*)()) &CPnts_UniformDeflection::More, "returns True if it exists a next Point.");
	cls_CPnts_UniformDeflection.def("Value", (Standard_Real (CPnts_UniformDeflection::*)() const ) &CPnts_UniformDeflection::Value, "return the computed parameter");
	cls_CPnts_UniformDeflection.def("Point", (gp_Pnt (CPnts_UniformDeflection::*)() const ) &CPnts_UniformDeflection::Point, "return the computed parameter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CPnts_RealFunction.hxx

}
