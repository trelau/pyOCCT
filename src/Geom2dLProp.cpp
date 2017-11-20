#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Geom2dLProp_Curve2dTool.hxx>
#include <gp_Dir2d.hxx>
#include <Geom2dLProp_CLProps2d.hxx>
#include <LProp_CurAndInf.hxx>
#include <Geom2dLProp_CurAndInf2d.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Geom2dLProp_FuncCurExt.hxx>
#include <Geom2dLProp_FuncCurNul.hxx>
#include <Geom2dLProp_NumericCurInf2d.hxx>

PYBIND11_MODULE(Geom2dLProp, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.LProp");
	py::module::import("OCCT.math");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dLProp_Curve2dTool.hxx
	py::class_<Geom2dLProp_Curve2dTool, std::unique_ptr<Geom2dLProp_Curve2dTool, Deleter<Geom2dLProp_Curve2dTool>>> cls_Geom2dLProp_Curve2dTool(mod, "Geom2dLProp_Curve2dTool", "None");
	cls_Geom2dLProp_Curve2dTool.def(py::init<>());
	cls_Geom2dLProp_Curve2dTool.def_static("Value_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, gp_Pnt2d &)) &Geom2dLProp_Curve2dTool::Value, "Computes the point <P> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"));
	cls_Geom2dLProp_Curve2dTool.def_static("D1_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &Geom2dLProp_Curve2dTool::D1, "Computes the point <P> and first derivative <V1> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"));
	cls_Geom2dLProp_Curve2dTool.def_static("D2_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dLProp_Curve2dTool::D2, "Computes the point <P>, the first derivative <V1> and second derivative <V2> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_Geom2dLProp_Curve2dTool.def_static("D3_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dLProp_Curve2dTool::D3, "Computes the point <P>, the first derivative <V1>, the second derivative <V2> and third derivative <V3> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_Geom2dLProp_Curve2dTool.def_static("Continuity_", (Standard_Integer (*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_Curve2dTool::Continuity, "returns the order of continuity of the curve <C>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable. returns 3 : first, second and third are computable.", py::arg("C"));
	cls_Geom2dLProp_Curve2dTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_Curve2dTool::FirstParameter, "returns the first parameter bound of the curve.", py::arg("C"));
	cls_Geom2dLProp_Curve2dTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_Curve2dTool::LastParameter, "returns the last parameter bound of the curve. FirstParameter must be less than LastParameter.", py::arg("C"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dLProp_CLProps2d.hxx
	py::class_<Geom2dLProp_CLProps2d, std::unique_ptr<Geom2dLProp_CLProps2d, Deleter<Geom2dLProp_CLProps2d>>> cls_Geom2dLProp_CLProps2d(mod, "Geom2dLProp_CLProps2d", "None");
	cls_Geom2dLProp_CLProps2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
	cls_Geom2dLProp_CLProps2d.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
	cls_Geom2dLProp_CLProps2d.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));
	cls_Geom2dLProp_CLProps2d.def("SetParameter", (void (Geom2dLProp_CLProps2d::*)(const Standard_Real)) &Geom2dLProp_CLProps2d::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
	cls_Geom2dLProp_CLProps2d.def("SetCurve", (void (Geom2dLProp_CLProps2d::*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_CLProps2d::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
	cls_Geom2dLProp_CLProps2d.def("Value", (const gp_Pnt2d & (Geom2dLProp_CLProps2d::*)() const ) &Geom2dLProp_CLProps2d::Value, "Returns the Point.");
	cls_Geom2dLProp_CLProps2d.def("D1", (const gp_Vec2d & (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
	cls_Geom2dLProp_CLProps2d.def("D2", (const gp_Vec2d & (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
	cls_Geom2dLProp_CLProps2d.def("D3", (const gp_Vec2d & (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
	cls_Geom2dLProp_CLProps2d.def("IsTangentDefined", (Standard_Boolean (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
	cls_Geom2dLProp_CLProps2d.def("Tangent", (void (Geom2dLProp_CLProps2d::*)(gp_Dir2d &)) &Geom2dLProp_CLProps2d::Tangent, "output the tangent direction <D>", py::arg("D"));
	cls_Geom2dLProp_CLProps2d.def("Curvature", (Standard_Real (Geom2dLProp_CLProps2d::*)()) &Geom2dLProp_CLProps2d::Curvature, "Returns the curvature.");
	cls_Geom2dLProp_CLProps2d.def("Normal", (void (Geom2dLProp_CLProps2d::*)(gp_Dir2d &)) &Geom2dLProp_CLProps2d::Normal, "Returns the normal direction <N>.", py::arg("N"));
	cls_Geom2dLProp_CLProps2d.def("CentreOfCurvature", (void (Geom2dLProp_CLProps2d::*)(gp_Pnt2d &)) &Geom2dLProp_CLProps2d::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dLProp_CurAndInf2d.hxx
	py::class_<Geom2dLProp_CurAndInf2d, std::unique_ptr<Geom2dLProp_CurAndInf2d, Deleter<Geom2dLProp_CurAndInf2d>>, LProp_CurAndInf> cls_Geom2dLProp_CurAndInf2d(mod, "Geom2dLProp_CurAndInf2d", "An algorithm for computing local properties of a curve. These properties include: - the maximum and minimum curvatures - the inflection points. A CurAndInf2d object provides the framework for: - defining the curve to be analyzed - implementing the computation algorithms - consulting the results.");
	cls_Geom2dLProp_CurAndInf2d.def(py::init<>());
	cls_Geom2dLProp_CurAndInf2d.def("Perform", (void (Geom2dLProp_CurAndInf2d::*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_CurAndInf2d::Perform, "For the curve C, Computes both the inflection points and the maximum and minimum curvatures.", py::arg("C"));
	cls_Geom2dLProp_CurAndInf2d.def("PerformCurExt", (void (Geom2dLProp_CurAndInf2d::*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_CurAndInf2d::PerformCurExt, "For the curve C, Computes the locals extremas of curvature.", py::arg("C"));
	cls_Geom2dLProp_CurAndInf2d.def("PerformInf", (void (Geom2dLProp_CurAndInf2d::*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_CurAndInf2d::PerformInf, "For the curve C, Computes the inflections. After computation, the following functions can be used: - IsDone to check if the computation was successful - NbPoints to obtain the number of computed particular points - Parameter to obtain the parameter on the curve for each particular point - Type to check if the point is an inflection point or an extremum of curvature of the curve C. Warning These functions can be used to analyze a series of curves, however it is necessary to clear the table of results between each computation.", py::arg("C"));
	cls_Geom2dLProp_CurAndInf2d.def("IsDone", (Standard_Boolean (Geom2dLProp_CurAndInf2d::*)() const ) &Geom2dLProp_CurAndInf2d::IsDone, "True if the solutions are found.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dLProp_FuncCurExt.hxx
	py::class_<Geom2dLProp_FuncCurExt, std::unique_ptr<Geom2dLProp_FuncCurExt, Deleter<Geom2dLProp_FuncCurExt>>, math_FunctionWithDerivative> cls_Geom2dLProp_FuncCurExt(mod, "Geom2dLProp_FuncCurExt", "Function used to find the extremas of curvature in 2d.");
	cls_Geom2dLProp_FuncCurExt.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real>(), py::arg("C"), py::arg("Tol"));
	cls_Geom2dLProp_FuncCurExt.def("Value", [](Geom2dLProp_FuncCurExt &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Returns the value for the variable <X>.", py::arg("X"), py::arg("F"));
	cls_Geom2dLProp_FuncCurExt.def("Derivative", [](Geom2dLProp_FuncCurExt &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Returns the derivative for the variable <X>.", py::arg("X"), py::arg("D"));
	cls_Geom2dLProp_FuncCurExt.def("Values", [](Geom2dLProp_FuncCurExt &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Returns the value of the function and the derivative for the variable <X>.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_Geom2dLProp_FuncCurExt.def("IsMinKC", (Standard_Boolean (Geom2dLProp_FuncCurExt::*)(const Standard_Real) const ) &Geom2dLProp_FuncCurExt::IsMinKC, "True if Param corresponds to a minus of the radius of curvature.", py::arg("Param"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dLProp_FuncCurNul.hxx
	py::class_<Geom2dLProp_FuncCurNul, std::unique_ptr<Geom2dLProp_FuncCurNul, Deleter<Geom2dLProp_FuncCurNul>>, math_FunctionWithDerivative> cls_Geom2dLProp_FuncCurNul(mod, "Geom2dLProp_FuncCurNul", "Function used to find the inflections in 2d.");
	cls_Geom2dLProp_FuncCurNul.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("C"));
	cls_Geom2dLProp_FuncCurNul.def("Value", [](Geom2dLProp_FuncCurNul &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Returns the value for the variable <X>.", py::arg("X"), py::arg("F"));
	cls_Geom2dLProp_FuncCurNul.def("Derivative", [](Geom2dLProp_FuncCurNul &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Returns the derivative for the variable <X>", py::arg("X"), py::arg("D"));
	cls_Geom2dLProp_FuncCurNul.def("Values", [](Geom2dLProp_FuncCurNul &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Returns the value of the function and the derivative for the variable <X>.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dLProp_NumericCurInf2d.hxx
	py::class_<Geom2dLProp_NumericCurInf2d, std::unique_ptr<Geom2dLProp_NumericCurInf2d, Deleter<Geom2dLProp_NumericCurInf2d>>> cls_Geom2dLProp_NumericCurInf2d(mod, "Geom2dLProp_NumericCurInf2d", "Computes the locals extremas of curvature and the inflections of a bounded curve in 2d.");
	cls_Geom2dLProp_NumericCurInf2d.def(py::init<>());
	cls_Geom2dLProp_NumericCurInf2d.def("PerformCurExt", (void (Geom2dLProp_NumericCurInf2d::*)(const opencascade::handle<Geom2d_Curve> &, LProp_CurAndInf &)) &Geom2dLProp_NumericCurInf2d::PerformCurExt, "Computes the locals extremas of curvature.", py::arg("C"), py::arg("Result"));
	cls_Geom2dLProp_NumericCurInf2d.def("PerformInf", (void (Geom2dLProp_NumericCurInf2d::*)(const opencascade::handle<Geom2d_Curve> &, LProp_CurAndInf &)) &Geom2dLProp_NumericCurInf2d::PerformInf, "Computes the inflections.", py::arg("C"), py::arg("Result"));
	cls_Geom2dLProp_NumericCurInf2d.def("PerformCurExt", (void (Geom2dLProp_NumericCurInf2d::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, LProp_CurAndInf &)) &Geom2dLProp_NumericCurInf2d::PerformCurExt, "Computes the locals extremas of curvature. in the interval of parmeters [UMin,UMax].", py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("Result"));
	cls_Geom2dLProp_NumericCurInf2d.def("PerformInf", (void (Geom2dLProp_NumericCurInf2d::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, LProp_CurAndInf &)) &Geom2dLProp_NumericCurInf2d::PerformInf, "Computes the inflections in the interval of parmeters [UMin,UMax].", py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("Result"));
	cls_Geom2dLProp_NumericCurInf2d.def("IsDone", (Standard_Boolean (Geom2dLProp_NumericCurInf2d::*)() const ) &Geom2dLProp_NumericCurInf2d::IsDone, "True if the solutions are found.");


}
