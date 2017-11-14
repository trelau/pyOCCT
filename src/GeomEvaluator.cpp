#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <GeomEvaluator_Surface.hxx>
#include <GeomEvaluator_Curve.hxx>
#include <Geom_Curve.hxx>
#include <gp_Dir.hxx>
#include <GeomAdaptor_HCurve.hxx>
#include <GeomEvaluator_OffsetCurve.hxx>
#include <Geom_Surface.hxx>
#include <Geom_OsculatingSurface.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <GeomEvaluator_OffsetSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <GeomEvaluator_SurfaceOfExtrusion.hxx>
#include <gp_Ax1.hxx>
#include <GeomEvaluator_SurfaceOfRevolution.hxx>

PYBIND11_MODULE(GeomEvaluator, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.GeomAdaptor");
	py::module::import("OCCT.Adaptor3d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// Callback for GeomEvaluator_Surface.
	class PyCallback_GeomEvaluator_Surface : public GeomEvaluator_Surface {
	public:
		using GeomEvaluator_Surface::GeomEvaluator_Surface;

		void D0(const Standard_Real theU, const Standard_Real theV, gp_Pnt & theValue) const  override { PYBIND11_OVERLOAD_PURE(void, GeomEvaluator_Surface, D0, theU, theV, theValue); }
		void D1(const Standard_Real theU, const Standard_Real theV, gp_Pnt & theValue, gp_Vec & theD1U, gp_Vec & theD1V) const  override { PYBIND11_OVERLOAD_PURE(void, GeomEvaluator_Surface, D1, theU, theV, theValue, theD1U, theD1V); }
		void D2(const Standard_Real theU, const Standard_Real theV, gp_Pnt & theValue, gp_Vec & theD1U, gp_Vec & theD1V, gp_Vec & theD2U, gp_Vec & theD2V, gp_Vec & theD2UV) const  override { PYBIND11_OVERLOAD_PURE(void, GeomEvaluator_Surface, D2, theU, theV, theValue, theD1U, theD1V, theD2U, theD2V, theD2UV); }
		void D3(const Standard_Real theU, const Standard_Real theV, gp_Pnt & theValue, gp_Vec & theD1U, gp_Vec & theD1V, gp_Vec & theD2U, gp_Vec & theD2V, gp_Vec & theD2UV, gp_Vec & theD3U, gp_Vec & theD3V, gp_Vec & theD3UUV, gp_Vec & theD3UVV) const  override { PYBIND11_OVERLOAD_PURE(void, GeomEvaluator_Surface, D3, theU, theV, theValue, theD1U, theD1V, theD2U, theD2V, theD2UV, theD3U, theD3V, theD3UUV, theD3UVV); }
		gp_Vec DN(const Standard_Real theU, const Standard_Real theV, const Standard_Integer theDerU, const Standard_Integer theDerV) const  override { PYBIND11_OVERLOAD_PURE(gp_Vec, GeomEvaluator_Surface, DN, theU, theV, theDerU, theDerV); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomEvaluator_Surface.hxx
	py::class_<GeomEvaluator_Surface, opencascade::handle<GeomEvaluator_Surface>, PyCallback_GeomEvaluator_Surface, Standard_Transient> cls_GeomEvaluator_Surface(mod, "GeomEvaluator_Surface", "Interface for calculation of values and derivatives for different kinds of surfaces. Works both with adaptors and surfaces.");
	cls_GeomEvaluator_Surface.def(py::init<>());
	cls_GeomEvaluator_Surface.def("D0", (void (GeomEvaluator_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const ) &GeomEvaluator_Surface::D0, "Value of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"));
	cls_GeomEvaluator_Surface.def("D1", (void (GeomEvaluator_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_Surface::D1, "Value and first derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"));
	cls_GeomEvaluator_Surface.def("D2", (void (GeomEvaluator_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_Surface::D2, "Value, first and second derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"));
	cls_GeomEvaluator_Surface.def("D3", (void (GeomEvaluator_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_Surface::D3, "Value, first, second and third derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"), py::arg("theD3U"), py::arg("theD3V"), py::arg("theD3UUV"), py::arg("theD3UVV"));
	cls_GeomEvaluator_Surface.def("DN", (gp_Vec (GeomEvaluator_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &GeomEvaluator_Surface::DN, "Calculates N-th derivatives of surface, where N = theDerU + theDerV.", py::arg("theU"), py::arg("theV"), py::arg("theDerU"), py::arg("theDerV"));
	cls_GeomEvaluator_Surface.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_Surface::get_type_name, "None");
	cls_GeomEvaluator_Surface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_Surface::get_type_descriptor, "None");
	cls_GeomEvaluator_Surface.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_Surface::*)() const ) &GeomEvaluator_Surface::DynamicType, "None");

	// Callback for GeomEvaluator_Curve.
	class PyCallback_GeomEvaluator_Curve : public GeomEvaluator_Curve {
	public:
		using GeomEvaluator_Curve::GeomEvaluator_Curve;

		void D0(const Standard_Real theU, gp_Pnt & theValue) const  override { PYBIND11_OVERLOAD_PURE(void, GeomEvaluator_Curve, D0, theU, theValue); }
		void D1(const Standard_Real theU, gp_Pnt & theValue, gp_Vec & theD1) const  override { PYBIND11_OVERLOAD_PURE(void, GeomEvaluator_Curve, D1, theU, theValue, theD1); }
		void D2(const Standard_Real theU, gp_Pnt & theValue, gp_Vec & theD1, gp_Vec & theD2) const  override { PYBIND11_OVERLOAD_PURE(void, GeomEvaluator_Curve, D2, theU, theValue, theD1, theD2); }
		void D3(const Standard_Real theU, gp_Pnt & theValue, gp_Vec & theD1, gp_Vec & theD2, gp_Vec & theD3) const  override { PYBIND11_OVERLOAD_PURE(void, GeomEvaluator_Curve, D3, theU, theValue, theD1, theD2, theD3); }
		gp_Vec DN(const Standard_Real theU, const Standard_Integer theDerU) const  override { PYBIND11_OVERLOAD_PURE(gp_Vec, GeomEvaluator_Curve, DN, theU, theDerU); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomEvaluator_Curve.hxx
	py::class_<GeomEvaluator_Curve, opencascade::handle<GeomEvaluator_Curve>, PyCallback_GeomEvaluator_Curve, Standard_Transient> cls_GeomEvaluator_Curve(mod, "GeomEvaluator_Curve", "Interface for calculation of values and derivatives for different kinds of curves in 3D. Works both with adaptors and curves.");
	cls_GeomEvaluator_Curve.def(py::init<>());
	cls_GeomEvaluator_Curve.def("D0", (void (GeomEvaluator_Curve::*)(const Standard_Real, gp_Pnt &) const ) &GeomEvaluator_Curve::D0, "Value of 3D curve", py::arg("theU"), py::arg("theValue"));
	cls_GeomEvaluator_Curve.def("D1", (void (GeomEvaluator_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &GeomEvaluator_Curve::D1, "Value and first derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"));
	cls_GeomEvaluator_Curve.def("D2", (void (GeomEvaluator_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_Curve::D2, "Value, first and second derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"));
	cls_GeomEvaluator_Curve.def("D3", (void (GeomEvaluator_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_Curve::D3, "Value, first, second and third derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"), py::arg("theD3"));
	cls_GeomEvaluator_Curve.def("DN", (gp_Vec (GeomEvaluator_Curve::*)(const Standard_Real, const Standard_Integer) const ) &GeomEvaluator_Curve::DN, "Calculates N-th derivatives of curve, where N = theDerU. Raises if N < 1", py::arg("theU"), py::arg("theDerU"));
	cls_GeomEvaluator_Curve.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_Curve::get_type_name, "None");
	cls_GeomEvaluator_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_Curve::get_type_descriptor, "None");
	cls_GeomEvaluator_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_Curve::*)() const ) &GeomEvaluator_Curve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomEvaluator_OffsetCurve.hxx
	py::class_<GeomEvaluator_OffsetCurve, opencascade::handle<GeomEvaluator_OffsetCurve>, GeomEvaluator_Curve> cls_GeomEvaluator_OffsetCurve(mod, "GeomEvaluator_OffsetCurve", "Allows to calculate values and derivatives for offset curves in 3D");
	cls_GeomEvaluator_OffsetCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const gp_Dir &>(), py::arg("theBase"), py::arg("theOffset"), py::arg("theDirection"));
	cls_GeomEvaluator_OffsetCurve.def(py::init<const opencascade::handle<GeomAdaptor_HCurve> &, const Standard_Real, const gp_Dir &>(), py::arg("theBase"), py::arg("theOffset"), py::arg("theDirection"));
	cls_GeomEvaluator_OffsetCurve.def("SetOffsetValue", (void (GeomEvaluator_OffsetCurve::*)(Standard_Real)) &GeomEvaluator_OffsetCurve::SetOffsetValue, "Change the offset value", py::arg("theOffset"));
	cls_GeomEvaluator_OffsetCurve.def("SetOffsetDirection", (void (GeomEvaluator_OffsetCurve::*)(const gp_Dir &)) &GeomEvaluator_OffsetCurve::SetOffsetDirection, "None", py::arg("theDirection"));
	cls_GeomEvaluator_OffsetCurve.def("D0", (void (GeomEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt &) const ) &GeomEvaluator_OffsetCurve::D0, "Value of curve", py::arg("theU"), py::arg("theValue"));
	cls_GeomEvaluator_OffsetCurve.def("D1", (void (GeomEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &GeomEvaluator_OffsetCurve::D1, "Value and first derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"));
	cls_GeomEvaluator_OffsetCurve.def("D2", (void (GeomEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_OffsetCurve::D2, "Value, first and second derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"));
	cls_GeomEvaluator_OffsetCurve.def("D3", (void (GeomEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_OffsetCurve::D3, "Value, first, second and third derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"), py::arg("theD3"));
	cls_GeomEvaluator_OffsetCurve.def("DN", (gp_Vec (GeomEvaluator_OffsetCurve::*)(const Standard_Real, const Standard_Integer) const ) &GeomEvaluator_OffsetCurve::DN, "Calculates N-th derivatives of curve, where N = theDeriv. Raises if N < 1", py::arg("theU"), py::arg("theDeriv"));
	cls_GeomEvaluator_OffsetCurve.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_OffsetCurve::get_type_name, "None");
	cls_GeomEvaluator_OffsetCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_OffsetCurve::get_type_descriptor, "None");
	cls_GeomEvaluator_OffsetCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_OffsetCurve::*)() const ) &GeomEvaluator_OffsetCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomEvaluator_OffsetSurface.hxx
	py::class_<GeomEvaluator_OffsetSurface, opencascade::handle<GeomEvaluator_OffsetSurface>, GeomEvaluator_Surface> cls_GeomEvaluator_OffsetSurface(mod, "GeomEvaluator_OffsetSurface", "Allows to calculate values and derivatives for offset surfaces");
	cls_GeomEvaluator_OffsetSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("theBase"), py::arg("theOffset"));
	cls_GeomEvaluator_OffsetSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const opencascade::handle<Geom_OsculatingSurface> &>(), py::arg("theBase"), py::arg("theOffset"), py::arg("theOscSurf"));
	cls_GeomEvaluator_OffsetSurface.def(py::init<const opencascade::handle<GeomAdaptor_HSurface> &, const Standard_Real>(), py::arg("theBase"), py::arg("theOffset"));
	cls_GeomEvaluator_OffsetSurface.def(py::init<const opencascade::handle<GeomAdaptor_HSurface> &, const Standard_Real, const opencascade::handle<Geom_OsculatingSurface> &>(), py::arg("theBase"), py::arg("theOffset"), py::arg("theOscSurf"));
	cls_GeomEvaluator_OffsetSurface.def("SetOffsetValue", (void (GeomEvaluator_OffsetSurface::*)(Standard_Real)) &GeomEvaluator_OffsetSurface::SetOffsetValue, "Change the offset value", py::arg("theOffset"));
	cls_GeomEvaluator_OffsetSurface.def("D0", (void (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const ) &GeomEvaluator_OffsetSurface::D0, "Value of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"));
	cls_GeomEvaluator_OffsetSurface.def("D1", (void (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_OffsetSurface::D1, "Value and first derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"));
	cls_GeomEvaluator_OffsetSurface.def("D2", (void (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_OffsetSurface::D2, "Value, first and second derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"));
	cls_GeomEvaluator_OffsetSurface.def("D3", (void (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_OffsetSurface::D3, "Value, first, second and third derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"), py::arg("theD3U"), py::arg("theD3V"), py::arg("theD3UUV"), py::arg("theD3UVV"));
	cls_GeomEvaluator_OffsetSurface.def("DN", (gp_Vec (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &GeomEvaluator_OffsetSurface::DN, "Calculates N-th derivatives of surface, where N = theDerU + theDerV.", py::arg("theU"), py::arg("theV"), py::arg("theDerU"), py::arg("theDerV"));
	cls_GeomEvaluator_OffsetSurface.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_OffsetSurface::get_type_name, "None");
	cls_GeomEvaluator_OffsetSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_OffsetSurface::get_type_descriptor, "None");
	cls_GeomEvaluator_OffsetSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_OffsetSurface::*)() const ) &GeomEvaluator_OffsetSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomEvaluator_SurfaceOfExtrusion.hxx
	py::class_<GeomEvaluator_SurfaceOfExtrusion, opencascade::handle<GeomEvaluator_SurfaceOfExtrusion>, GeomEvaluator_Surface> cls_GeomEvaluator_SurfaceOfExtrusion(mod, "GeomEvaluator_SurfaceOfExtrusion", "Allows to calculate values and derivatives for surfaces of linear extrusion");
	cls_GeomEvaluator_SurfaceOfExtrusion.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Dir &>(), py::arg("theBase"), py::arg("theExtrusionDir"));
	cls_GeomEvaluator_SurfaceOfExtrusion.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const gp_Dir &>(), py::arg("theBase"), py::arg("theExtrusionDir"));
	cls_GeomEvaluator_SurfaceOfExtrusion.def("SetDirection", (void (GeomEvaluator_SurfaceOfExtrusion::*)(const gp_Dir &)) &GeomEvaluator_SurfaceOfExtrusion::SetDirection, "! Changes the direction of extrusion", py::arg("theDirection"));
	cls_GeomEvaluator_SurfaceOfExtrusion.def("D0", (void (GeomEvaluator_SurfaceOfExtrusion::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const ) &GeomEvaluator_SurfaceOfExtrusion::D0, "Value of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"));
	cls_GeomEvaluator_SurfaceOfExtrusion.def("D1", (void (GeomEvaluator_SurfaceOfExtrusion::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_SurfaceOfExtrusion::D1, "Value and first derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"));
	cls_GeomEvaluator_SurfaceOfExtrusion.def("D2", (void (GeomEvaluator_SurfaceOfExtrusion::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_SurfaceOfExtrusion::D2, "Value, first and second derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"));
	cls_GeomEvaluator_SurfaceOfExtrusion.def("D3", (void (GeomEvaluator_SurfaceOfExtrusion::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_SurfaceOfExtrusion::D3, "Value, first, second and third derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"), py::arg("theD3U"), py::arg("theD3V"), py::arg("theD3UUV"), py::arg("theD3UVV"));
	cls_GeomEvaluator_SurfaceOfExtrusion.def("DN", (gp_Vec (GeomEvaluator_SurfaceOfExtrusion::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &GeomEvaluator_SurfaceOfExtrusion::DN, "Calculates N-th derivatives of surface, where N = theDerU + theDerV.", py::arg("theU"), py::arg("theV"), py::arg("theDerU"), py::arg("theDerV"));
	cls_GeomEvaluator_SurfaceOfExtrusion.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_SurfaceOfExtrusion::get_type_name, "None");
	cls_GeomEvaluator_SurfaceOfExtrusion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_SurfaceOfExtrusion::get_type_descriptor, "None");
	cls_GeomEvaluator_SurfaceOfExtrusion.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_SurfaceOfExtrusion::*)() const ) &GeomEvaluator_SurfaceOfExtrusion::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomEvaluator_SurfaceOfRevolution.hxx
	py::class_<GeomEvaluator_SurfaceOfRevolution, opencascade::handle<GeomEvaluator_SurfaceOfRevolution>, GeomEvaluator_Surface> cls_GeomEvaluator_SurfaceOfRevolution(mod, "GeomEvaluator_SurfaceOfRevolution", "Allows to calculate values and derivatives for surfaces of revolution");
	cls_GeomEvaluator_SurfaceOfRevolution.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Dir &, const gp_Pnt &>(), py::arg("theBase"), py::arg("theRevolDir"), py::arg("theRevolLoc"));
	cls_GeomEvaluator_SurfaceOfRevolution.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const gp_Dir &, const gp_Pnt &>(), py::arg("theBase"), py::arg("theRevolDir"), py::arg("theRevolLoc"));
	cls_GeomEvaluator_SurfaceOfRevolution.def("SetDirection", (void (GeomEvaluator_SurfaceOfRevolution::*)(const gp_Dir &)) &GeomEvaluator_SurfaceOfRevolution::SetDirection, "Change direction of the axis of revolution", py::arg("theDirection"));
	cls_GeomEvaluator_SurfaceOfRevolution.def("SetLocation", (void (GeomEvaluator_SurfaceOfRevolution::*)(const gp_Pnt &)) &GeomEvaluator_SurfaceOfRevolution::SetLocation, "Change location of the axis of revolution", py::arg("theLocation"));
	cls_GeomEvaluator_SurfaceOfRevolution.def("SetAxis", (void (GeomEvaluator_SurfaceOfRevolution::*)(const gp_Ax1 &)) &GeomEvaluator_SurfaceOfRevolution::SetAxis, "Change the axis of revolution", py::arg("theAxis"));
	cls_GeomEvaluator_SurfaceOfRevolution.def("D0", (void (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const ) &GeomEvaluator_SurfaceOfRevolution::D0, "Value of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"));
	cls_GeomEvaluator_SurfaceOfRevolution.def("D1", (void (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_SurfaceOfRevolution::D1, "Value and first derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"));
	cls_GeomEvaluator_SurfaceOfRevolution.def("D2", (void (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_SurfaceOfRevolution::D2, "Value, first and second derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"));
	cls_GeomEvaluator_SurfaceOfRevolution.def("D3", (void (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &GeomEvaluator_SurfaceOfRevolution::D3, "Value, first, second and third derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"), py::arg("theD3U"), py::arg("theD3V"), py::arg("theD3UUV"), py::arg("theD3UVV"));
	cls_GeomEvaluator_SurfaceOfRevolution.def("DN", (gp_Vec (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &GeomEvaluator_SurfaceOfRevolution::DN, "Calculates N-th derivatives of surface, where N = theDerU + theDerV.", py::arg("theU"), py::arg("theV"), py::arg("theDerU"), py::arg("theDerV"));
	cls_GeomEvaluator_SurfaceOfRevolution.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_SurfaceOfRevolution::get_type_name, "None");
	cls_GeomEvaluator_SurfaceOfRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_SurfaceOfRevolution::get_type_descriptor, "None");
	cls_GeomEvaluator_SurfaceOfRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_SurfaceOfRevolution::*)() const ) &GeomEvaluator_SurfaceOfRevolution::DynamicType, "None");


}
