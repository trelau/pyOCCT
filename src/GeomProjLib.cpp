#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Plane.hxx>
#include <gp_Dir.hxx>
#include <GeomProjLib.hxx>

PYBIND11_MODULE(GeomProjLib, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomProjLib.hxx
	py::class_<GeomProjLib, std::unique_ptr<GeomProjLib, Deleter<GeomProjLib>>> cls_GeomProjLib(mod, "GeomProjLib", "Projection of a curve on a surface.");
	cls_GeomProjLib.def(py::init<>());
	// FIXME cls_GeomProjLib.def_static("Curve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real &)) &GeomProjLib::Curve2d, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ) The 3dCurve is taken between the parametrization range [First, Last] <Tolerance> is used as input if the projection needs an approximation. In this case, the reached tolerance is set in <Tolerance> as output. WARNING : if the projection has failed, this method returns a null Handle.", py::arg("C"), py::arg("First"), py::arg("Last"), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("Tolerance"));
	// FIXME cls_GeomProjLib.def_static("Curve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, Standard_Real &)) &GeomProjLib::Curve2d, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ) The 3dCurve is taken between the parametrization range [First, Last] <Tolerance> is used as input if the projection needs an approximation. In this case, the reached tolerance is set in <Tolerance> as output. WARNING : if the projection has failed, this method returns a null Handle.", py::arg("C"), py::arg("First"), py::arg("Last"), py::arg("S"), py::arg("Tolerance"));
	// FIXME cls_GeomProjLib.def_static("Curve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &)) &GeomProjLib::Curve2d, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ) The 3dCurve is taken between the parametrization range [First, Last] If the projection needs an approximation, Precision::PApproximation() is used. WARNING : if the projection has failed, this method returns a null Handle.", py::arg("C"), py::arg("First"), py::arg("Last"), py::arg("S"));
	cls_GeomProjLib.def_static("Curve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &)) &GeomProjLib::Curve2d, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ). If the projection needs an approximation, Precision::PApproximation() is used. WARNING : if the projection has failed, this method returns a null Handle.", py::arg("C"), py::arg("S"));
	cls_GeomProjLib.def_static("Curve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomProjLib::Curve2d, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ). If the projection needs an approximation, Precision::PApproximation() is used. WARNING : if the projection has failed, this method returns a null Handle. can expand a little the bounds of surface", py::arg("C"), py::arg("S"), py::arg("UDeb"), py::arg("UFin"), py::arg("VDeb"), py::arg("VFin"));
	cls_GeomProjLib.def_static("Curve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real &)) &GeomProjLib::Curve2d, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ). If the projection needs an approximation, Precision::PApproximation() is used. WARNING : if the projection has failed, this method returns a null Handle. can expand a little the bounds of surface", py::arg("C"), py::arg("S"), py::arg("UDeb"), py::arg("UFin"), py::arg("VDeb"), py::arg("VFin"), py::arg("Tolerance"));
	cls_GeomProjLib.def_static("Project_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &)) &GeomProjLib::Project, "Constructs the 3d-curve from the normal projection of the Curve <C> on the surface <S>. WARNING : if the projection has failes returns a null Handle.", py::arg("C"), py::arg("S"));
	cls_GeomProjLib.def_static("ProjectOnPlane_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Plane> &, const gp_Dir &, const Standard_Boolean)) &GeomProjLib::ProjectOnPlane, "Constructs the 3d-curves from the projection of the curve <Curve> on the plane <Plane> along the direction <Dir>. If <KeepParametrization> is true, the parametrization of the Projected Curve <PC> will be the same as the parametrization of the initial curve <C>. It meens: proj(C(u)) = PC(u) for each u. Otherwize, the parametrization may change.", py::arg("Curve"), py::arg("Plane"), py::arg("Dir"), py::arg("KeepParametrization"));


}
