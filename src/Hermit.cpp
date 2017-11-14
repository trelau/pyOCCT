#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Handle.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Hermit.hxx>

PYBIND11_MODULE(Hermit, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.Geom");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Hermit.hxx
	py::class_<Hermit, std::unique_ptr<Hermit, Deleter<Hermit>>> cls_Hermit(mod, "Hermit", "This is used to reparameterize Rational BSpline Curves so that we can concatenate them later to build C1 Curves It builds and 1D-reparameterizing function starting from an Hermite interpolation and adding knots and modifying poles of the 1D BSpline obtained that way. The goal is to build a(u) so that if we consider a BSpline curve N(u) f(u) = ----- D(u)");
	cls_Hermit.def(py::init<>());
	cls_Hermit.def_static("Solution_", [](const opencascade::handle<Geom_BSplineCurve> & a0) -> opencascade::handle<Geom2d_BSplineCurve> { return Hermit::Solution(a0); }, py::arg("BS"));
	cls_Hermit.def_static("Solution_", [](const opencascade::handle<Geom_BSplineCurve> & a0, const Standard_Real a1) -> opencascade::handle<Geom2d_BSplineCurve> { return Hermit::Solution(a0, a1); }, py::arg("BS"), py::arg("TolPoles"));
	cls_Hermit.def_static("Solution_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Geom_BSplineCurve> &, const Standard_Real, const Standard_Real)) &Hermit::Solution, "returns the correct spline a(u) which will be multiplicated with BS later.", py::arg("BS"), py::arg("TolPoles"), py::arg("TolKnots"));
	cls_Hermit.def_static("Solution_", [](const opencascade::handle<Geom2d_BSplineCurve> & a0) -> opencascade::handle<Geom2d_BSplineCurve> { return Hermit::Solution(a0); }, py::arg("BS"));
	cls_Hermit.def_static("Solution_", [](const opencascade::handle<Geom2d_BSplineCurve> & a0, const Standard_Real a1) -> opencascade::handle<Geom2d_BSplineCurve> { return Hermit::Solution(a0, a1); }, py::arg("BS"), py::arg("TolPoles"));
	cls_Hermit.def_static("Solution_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real, const Standard_Real)) &Hermit::Solution, "returns the correct spline a(u) which will be multiplicated with BS later.", py::arg("BS"), py::arg("TolPoles"), py::arg("TolKnots"));
	cls_Hermit.def_static("Solutionbis_", [](const opencascade::handle<Geom_BSplineCurve> & a0, Standard_Real & a1, Standard_Real & a2) -> void { return Hermit::Solutionbis(a0, a1, a2); }, py::arg("BS"), py::arg("Knotmin"), py::arg("Knotmax"));
	cls_Hermit.def_static("Solutionbis_", [](const opencascade::handle<Geom_BSplineCurve> & a0, Standard_Real & a1, Standard_Real & a2, const Standard_Real a3) -> void { return Hermit::Solutionbis(a0, a1, a2, a3); }, py::arg("BS"), py::arg("Knotmin"), py::arg("Knotmax"), py::arg("TolPoles"));
	cls_Hermit.def_static("Solutionbis_", (void (*)(const opencascade::handle<Geom_BSplineCurve> &, Standard_Real &, Standard_Real &, const Standard_Real, const Standard_Real)) &Hermit::Solutionbis, "returns the knots to insert to a(u) to stay with a constant sign and in the tolerances.", py::arg("BS"), py::arg("Knotmin"), py::arg("Knotmax"), py::arg("TolPoles"), py::arg("TolKnots"));


}
