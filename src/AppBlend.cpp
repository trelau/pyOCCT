#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <AppBlend_Approx.hxx>

PYBIND11_MODULE(AppBlend, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppBlend_Approx.hxx
	py::class_<AppBlend_Approx, std::unique_ptr<AppBlend_Approx, Deleter<AppBlend_Approx>>> cls_AppBlend_Approx(mod, "AppBlend_Approx", "Bspline approximation of a surface.");
	cls_AppBlend_Approx.def("IsDone", (Standard_Boolean (AppBlend_Approx::*)() const ) &AppBlend_Approx::IsDone, "None");
	cls_AppBlend_Approx.def("SurfShape", (void (AppBlend_Approx::*)(Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &AppBlend_Approx::SurfShape, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
	cls_AppBlend_Approx.def("Surface", (void (AppBlend_Approx::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const ) &AppBlend_Approx::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
	cls_AppBlend_Approx.def("UDegree", (Standard_Integer (AppBlend_Approx::*)() const ) &AppBlend_Approx::UDegree, "None");
	cls_AppBlend_Approx.def("VDegree", (Standard_Integer (AppBlend_Approx::*)() const ) &AppBlend_Approx::VDegree, "None");
	cls_AppBlend_Approx.def("SurfPoles", (const TColgp_Array2OfPnt & (AppBlend_Approx::*)() const ) &AppBlend_Approx::SurfPoles, "None");
	cls_AppBlend_Approx.def("SurfWeights", (const TColStd_Array2OfReal & (AppBlend_Approx::*)() const ) &AppBlend_Approx::SurfWeights, "None");
	cls_AppBlend_Approx.def("SurfUKnots", (const TColStd_Array1OfReal & (AppBlend_Approx::*)() const ) &AppBlend_Approx::SurfUKnots, "None");
	cls_AppBlend_Approx.def("SurfVKnots", (const TColStd_Array1OfReal & (AppBlend_Approx::*)() const ) &AppBlend_Approx::SurfVKnots, "None");
	cls_AppBlend_Approx.def("SurfUMults", (const TColStd_Array1OfInteger & (AppBlend_Approx::*)() const ) &AppBlend_Approx::SurfUMults, "None");
	cls_AppBlend_Approx.def("SurfVMults", (const TColStd_Array1OfInteger & (AppBlend_Approx::*)() const ) &AppBlend_Approx::SurfVMults, "None");
	cls_AppBlend_Approx.def("NbCurves2d", (Standard_Integer (AppBlend_Approx::*)() const ) &AppBlend_Approx::NbCurves2d, "None");
	cls_AppBlend_Approx.def("Curves2dShape", (void (AppBlend_Approx::*)(Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &AppBlend_Approx::Curves2dShape, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
	cls_AppBlend_Approx.def("Curve2d", (void (AppBlend_Approx::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const ) &AppBlend_Approx::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
	cls_AppBlend_Approx.def("Curves2dDegree", (Standard_Integer (AppBlend_Approx::*)() const ) &AppBlend_Approx::Curves2dDegree, "None");
	cls_AppBlend_Approx.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (AppBlend_Approx::*)(const Standard_Integer) const ) &AppBlend_Approx::Curve2dPoles, "None", py::arg("Index"));
	cls_AppBlend_Approx.def("Curves2dKnots", (const TColStd_Array1OfReal & (AppBlend_Approx::*)() const ) &AppBlend_Approx::Curves2dKnots, "None");
	cls_AppBlend_Approx.def("Curves2dMults", (const TColStd_Array1OfInteger & (AppBlend_Approx::*)() const ) &AppBlend_Approx::Curves2dMults, "None");
	cls_AppBlend_Approx.def("TolReached", (void (AppBlend_Approx::*)(Standard_Real &, Standard_Real &) const ) &AppBlend_Approx::TolReached, "None", py::arg("Tol3d"), py::arg("Tol2d"));
	cls_AppBlend_Approx.def("TolCurveOnSurf", (Standard_Real (AppBlend_Approx::*)(const Standard_Integer) const ) &AppBlend_Approx::TolCurveOnSurf, "None", py::arg("Index"));


}
