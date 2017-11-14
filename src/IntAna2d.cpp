#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <IntAna2d_IntPoint.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_XY.hxx>
#include <gp_Ax2d.hxx>
#include <IntAna2d_Conic.hxx>
#include <IntAna2d_AnaIntersection.hxx>
#include <IntAna2d_Outils.hxx>

PYBIND11_MODULE(IntAna2d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna2d_Outils.hxx
	mod.def("Points_Confondus", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Points_Confondus, "None", py::arg("xa"), py::arg("ya"), py::arg("xb"), py::arg("yb"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna2d_Outils.hxx
	mod.def("Traitement_Points_Confondus", (void (*)(Standard_Integer &, IntAna2d_IntPoint *)) &Traitement_Points_Confondus, "None", py::arg("nb_pts"), py::arg("pts"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna2d_Outils.hxx
	mod.def("Coord_Ancien_Repere", (void (*)(Standard_Real &, Standard_Real &, const gp_Ax2d)) &Coord_Ancien_Repere, "None", py::arg("Ancien_X"), py::arg("Ancien_Y"), py::arg("Axe_Nouveau_Repere"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna2d_IntPoint.hxx
	py::class_<IntAna2d_IntPoint, std::unique_ptr<IntAna2d_IntPoint, Deleter<IntAna2d_IntPoint>>> cls_IntAna2d_IntPoint(mod, "IntAna2d_IntPoint", "Geometrical intersection between two 2d elements.");
	cls_IntAna2d_IntPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"), py::arg("U1"), py::arg("U2"));
	cls_IntAna2d_IntPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"), py::arg("U1"));
	cls_IntAna2d_IntPoint.def(py::init<>());
	cls_IntAna2d_IntPoint.def("SetValue", (void (IntAna2d_IntPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntAna2d_IntPoint::SetValue, "Set the values for a 'non-implicit' point.", py::arg("X"), py::arg("Y"), py::arg("U1"), py::arg("U2"));
	cls_IntAna2d_IntPoint.def("SetValue", (void (IntAna2d_IntPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &IntAna2d_IntPoint::SetValue, "Set the values for an 'implicit' point.", py::arg("X"), py::arg("Y"), py::arg("U1"));
	cls_IntAna2d_IntPoint.def("Value", (const gp_Pnt2d & (IntAna2d_IntPoint::*)() const ) &IntAna2d_IntPoint::Value, "Returns the geometric point.");
	cls_IntAna2d_IntPoint.def("SecondIsImplicit", (Standard_Boolean (IntAna2d_IntPoint::*)() const ) &IntAna2d_IntPoint::SecondIsImplicit, "Returns True if the second curve is implicit.");
	cls_IntAna2d_IntPoint.def("ParamOnFirst", (Standard_Real (IntAna2d_IntPoint::*)() const ) &IntAna2d_IntPoint::ParamOnFirst, "Returns the parameter on the first element.");
	cls_IntAna2d_IntPoint.def("ParamOnSecond", (Standard_Real (IntAna2d_IntPoint::*)() const ) &IntAna2d_IntPoint::ParamOnSecond, "Returns the parameter on the second element. If the second element is an implicit curve, an exception is raised.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna2d_Conic.hxx
	py::class_<IntAna2d_Conic, std::unique_ptr<IntAna2d_Conic, Deleter<IntAna2d_Conic>>> cls_IntAna2d_Conic(mod, "IntAna2d_Conic", "Definition of a conic by its implicit quadaratic equation: A.X**2 + B.Y**2 + 2.C.X*Y + 2.D.X + 2.E.Y + F = 0.");
	cls_IntAna2d_Conic.def(py::init<const gp_Circ2d &>(), py::arg("C"));
	cls_IntAna2d_Conic.def(py::init<const gp_Lin2d &>(), py::arg("C"));
	cls_IntAna2d_Conic.def(py::init<const gp_Parab2d &>(), py::arg("C"));
	cls_IntAna2d_Conic.def(py::init<const gp_Hypr2d &>(), py::arg("C"));
	cls_IntAna2d_Conic.def(py::init<const gp_Elips2d &>(), py::arg("C"));
	cls_IntAna2d_Conic.def("Value", (Standard_Real (IntAna2d_Conic::*)(const Standard_Real, const Standard_Real) const ) &IntAna2d_Conic::Value, "value of the function F at the point X,Y.", py::arg("X"), py::arg("Y"));
	cls_IntAna2d_Conic.def("Grad", (gp_XY (IntAna2d_Conic::*)(const Standard_Real, const Standard_Real) const ) &IntAna2d_Conic::Grad, "returns the value of the gradient of F at the point X,Y.", py::arg("X"), py::arg("Y"));
	cls_IntAna2d_Conic.def("ValAndGrad", (void (IntAna2d_Conic::*)(const Standard_Real, const Standard_Real, Standard_Real &, gp_XY &) const ) &IntAna2d_Conic::ValAndGrad, "Returns the value of the function and its gradient at the point X,Y.", py::arg("X"), py::arg("Y"), py::arg("Val"), py::arg("Grd"));
	// FIXME cls_IntAna2d_Conic.def("Coefficients", (void (IntAna2d_Conic::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &IntAna2d_Conic::Coefficients, "returns the coefficients of the polynomial equation wich defines the conic: A.X**2 + B.Y**2 + 2.C.X*Y + 2.D.X + 2.E.Y + F = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
	cls_IntAna2d_Conic.def("NewCoefficients", (void (IntAna2d_Conic::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, const gp_Ax2d &) const ) &IntAna2d_Conic::NewCoefficients, "Returns the coefficients of the polynomial equation ( written in the natural coordinates system ) A x x + B y y + 2 C x y + 2 D x + 2 E y + F in the local coordinates system defined by Axis", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"), py::arg("Axis"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna2d_AnaIntersection.hxx
	py::class_<IntAna2d_AnaIntersection, std::unique_ptr<IntAna2d_AnaIntersection, Deleter<IntAna2d_AnaIntersection>>> cls_IntAna2d_AnaIntersection(mod, "IntAna2d_AnaIntersection", "Implementation of the analytical intersection between: - two Lin2d, - two Circ2d, - a Lin2d and a Circ2d, - an element of gp (Lin2d, Circ2d, Elips2d, Parab2d, Hypr2d) and another conic. No tolerance is given for all the intersections: the tolerance will be the 'precision machine'.");
	cls_IntAna2d_AnaIntersection.def(py::init<>());
	cls_IntAna2d_AnaIntersection.def(py::init<const gp_Lin2d &, const gp_Lin2d &>(), py::arg("L1"), py::arg("L2"));
	cls_IntAna2d_AnaIntersection.def(py::init<const gp_Circ2d &, const gp_Circ2d &>(), py::arg("C1"), py::arg("C2"));
	cls_IntAna2d_AnaIntersection.def(py::init<const gp_Lin2d &, const gp_Circ2d &>(), py::arg("L"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def(py::init<const gp_Lin2d &, const IntAna2d_Conic &>(), py::arg("L"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def(py::init<const gp_Circ2d &, const IntAna2d_Conic &>(), py::arg("C"), py::arg("Co"));
	cls_IntAna2d_AnaIntersection.def(py::init<const gp_Elips2d &, const IntAna2d_Conic &>(), py::arg("E"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def(py::init<const gp_Parab2d &, const IntAna2d_Conic &>(), py::arg("P"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def(py::init<const gp_Hypr2d &, const IntAna2d_Conic &>(), py::arg("H"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Lin2d &, const gp_Lin2d &)) &IntAna2d_AnaIntersection::Perform, "Intersection between two lines.", py::arg("L1"), py::arg("L2"));
	cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Circ2d &, const gp_Circ2d &)) &IntAna2d_AnaIntersection::Perform, "Intersection between two circles.", py::arg("C1"), py::arg("C2"));
	cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Lin2d &, const gp_Circ2d &)) &IntAna2d_AnaIntersection::Perform, "Intersection between a line and a circle.", py::arg("L"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Lin2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between a line and a conic.", py::arg("L"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Circ2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between a circle and another conic.", py::arg("C"), py::arg("Co"));
	cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Elips2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between an ellipse and another conic.", py::arg("E"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Parab2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between a parabola and another conic.", py::arg("P"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Hypr2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between an hyperbola and another conic.", py::arg("H"), py::arg("C"));
	cls_IntAna2d_AnaIntersection.def("IsDone", (Standard_Boolean (IntAna2d_AnaIntersection::*)() const ) &IntAna2d_AnaIntersection::IsDone, "Returns TRUE if the computation was succesfull.");
	cls_IntAna2d_AnaIntersection.def("IsEmpty", (Standard_Boolean (IntAna2d_AnaIntersection::*)() const ) &IntAna2d_AnaIntersection::IsEmpty, "Returns TRUE when there is no intersection, i-e - no intersection point - the elements are not identical. The element may be parallel in this case.");
	cls_IntAna2d_AnaIntersection.def("IdenticalElements", (Standard_Boolean (IntAna2d_AnaIntersection::*)() const ) &IntAna2d_AnaIntersection::IdenticalElements, "For the intersection between an element of gp and a conic known by an implicit equation, the result will be TRUE if the element of gp verifies the implicit equation. For the intersection between two Lin2d or two Circ2d, the result will be TRUE if the elements are identical. The function returns FALSE in all the other cases.");
	cls_IntAna2d_AnaIntersection.def("ParallelElements", (Standard_Boolean (IntAna2d_AnaIntersection::*)() const ) &IntAna2d_AnaIntersection::ParallelElements, "For the intersection between two Lin2d or two Circ2d, the function returns TRUE if the elements are parallel. The function returns FALSE in all the other cases.");
	cls_IntAna2d_AnaIntersection.def("NbPoints", (Standard_Integer (IntAna2d_AnaIntersection::*)() const ) &IntAna2d_AnaIntersection::NbPoints, "returns the number of IntPoint between the 2 curves.");
	cls_IntAna2d_AnaIntersection.def("Point", (const IntAna2d_IntPoint & (IntAna2d_AnaIntersection::*)(const Standard_Integer) const ) &IntAna2d_AnaIntersection::Point, "returns the intersection point of range N; If (N<=0) or (N>NbPoints), an exception is raised.", py::arg("N"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna2d_Outils.hxx
	py::class_<MyDirectPolynomialRoots, std::unique_ptr<MyDirectPolynomialRoots, Deleter<MyDirectPolynomialRoots>>> cls_MyDirectPolynomialRoots(mod, "MyDirectPolynomialRoots", "None");
	cls_MyDirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A4"), py::arg("A3"), py::arg("A2"), py::arg("A1"), py::arg("A0"));
	cls_MyDirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("A1"), py::arg("A0"));
	cls_MyDirectPolynomialRoots.def("NbSolutions", (Standard_Integer (MyDirectPolynomialRoots::*)() const ) &MyDirectPolynomialRoots::NbSolutions, "None");
	cls_MyDirectPolynomialRoots.def("Value", (Standard_Real (MyDirectPolynomialRoots::*)(const Standard_Integer) const ) &MyDirectPolynomialRoots::Value, "None", py::arg("i"));
	cls_MyDirectPolynomialRoots.def("IsDone", (Standard_Real (MyDirectPolynomialRoots::*)() const ) &MyDirectPolynomialRoots::IsDone, "None");
	cls_MyDirectPolynomialRoots.def("InfiniteRoots", (Standard_Boolean (MyDirectPolynomialRoots::*)() const ) &MyDirectPolynomialRoots::InfiniteRoots, "None");


}
