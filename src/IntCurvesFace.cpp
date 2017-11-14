#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Pnt.hxx>
#include <IntCurveSurface_TransitionOnCurve.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <Bnd_Box.hxx>
#include <IntCurvesFace_Intersector.hxx>
#include <TopoDS_Shape.hxx>
#include <IntCurvesFace_ShapeIntersector.hxx>

PYBIND11_MODULE(IntCurvesFace, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.IntCurveSurface");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.Bnd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntCurvesFace_Intersector.hxx
	py::class_<IntCurvesFace_Intersector, std::unique_ptr<IntCurvesFace_Intersector, Deleter<IntCurvesFace_Intersector>>> cls_IntCurvesFace_Intersector(mod, "IntCurvesFace_Intersector", "None");
	cls_IntCurvesFace_Intersector.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("aTol"));
	cls_IntCurvesFace_Intersector.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Boolean>(), py::arg("F"), py::arg("aTol"), py::arg("aRestr"));
	cls_IntCurvesFace_Intersector.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("F"), py::arg("aTol"), py::arg("aRestr"), py::arg("UseBToler"));
	cls_IntCurvesFace_Intersector.def("Perform", (void (IntCurvesFace_Intersector::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &IntCurvesFace_Intersector::Perform, "Perform the intersection between the segment L and the loaded face.", py::arg("L"), py::arg("PInf"), py::arg("PSup"));
	cls_IntCurvesFace_Intersector.def("Perform", (void (IntCurvesFace_Intersector::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real)) &IntCurvesFace_Intersector::Perform, "same method for a HCurve from Adaptor3d. PInf an PSup can also be - and + INF.", py::arg("HCu"), py::arg("PInf"), py::arg("PSup"));
	cls_IntCurvesFace_Intersector.def("SurfaceType", (GeomAbs_SurfaceType (IntCurvesFace_Intersector::*)() const ) &IntCurvesFace_Intersector::SurfaceType, "Return the surface type");
	cls_IntCurvesFace_Intersector.def("IsDone", (Standard_Boolean (IntCurvesFace_Intersector::*)() const ) &IntCurvesFace_Intersector::IsDone, "True is returned when the intersection have been computed.");
	cls_IntCurvesFace_Intersector.def("NbPnt", (Standard_Integer (IntCurvesFace_Intersector::*)() const ) &IntCurvesFace_Intersector::NbPnt, "None");
	cls_IntCurvesFace_Intersector.def("UParameter", (Standard_Real (IntCurvesFace_Intersector::*)(const Standard_Integer) const ) &IntCurvesFace_Intersector::UParameter, "Returns the U parameter of the ith intersection point on the surface.", py::arg("I"));
	cls_IntCurvesFace_Intersector.def("VParameter", (Standard_Real (IntCurvesFace_Intersector::*)(const Standard_Integer) const ) &IntCurvesFace_Intersector::VParameter, "Returns the V parameter of the ith intersection point on the surface.", py::arg("I"));
	cls_IntCurvesFace_Intersector.def("WParameter", (Standard_Real (IntCurvesFace_Intersector::*)(const Standard_Integer) const ) &IntCurvesFace_Intersector::WParameter, "Returns the parameter of the ith intersection point on the line.", py::arg("I"));
	cls_IntCurvesFace_Intersector.def("Pnt", (const gp_Pnt & (IntCurvesFace_Intersector::*)(const Standard_Integer) const ) &IntCurvesFace_Intersector::Pnt, "Returns the geometric point of the ith intersection between the line and the surface.", py::arg("I"));
	cls_IntCurvesFace_Intersector.def("Transition", (IntCurveSurface_TransitionOnCurve (IntCurvesFace_Intersector::*)(const Standard_Integer) const ) &IntCurvesFace_Intersector::Transition, "Returns the ith transition of the line on the surface.", py::arg("I"));
	cls_IntCurvesFace_Intersector.def("State", (TopAbs_State (IntCurvesFace_Intersector::*)(const Standard_Integer) const ) &IntCurvesFace_Intersector::State, "Returns the ith state of the point on the face. The values can be either TopAbs_IN ( the point is in the face) or TopAbs_ON ( the point is on a boudary of the face).", py::arg("I"));
	cls_IntCurvesFace_Intersector.def("Face", (const TopoDS_Face & (IntCurvesFace_Intersector::*)() const ) &IntCurvesFace_Intersector::Face, "Returns the significant face used to determine the intersection.");
	cls_IntCurvesFace_Intersector.def("ClassifyUVPoint", (TopAbs_State (IntCurvesFace_Intersector::*)(const gp_Pnt2d &) const ) &IntCurvesFace_Intersector::ClassifyUVPoint, "None", py::arg("Puv"));
	cls_IntCurvesFace_Intersector.def("Bounding", (Bnd_Box (IntCurvesFace_Intersector::*)() const ) &IntCurvesFace_Intersector::Bounding, "None");
	cls_IntCurvesFace_Intersector.def("SetUseBoundToler", (void (IntCurvesFace_Intersector::*)(Standard_Boolean)) &IntCurvesFace_Intersector::SetUseBoundToler, "Sets the boundary tolerance flag", py::arg("UseBToler"));
	cls_IntCurvesFace_Intersector.def("GetUseBoundToler", (Standard_Boolean (IntCurvesFace_Intersector::*)() const ) &IntCurvesFace_Intersector::GetUseBoundToler, "Returns the boundary tolerance flag");
	cls_IntCurvesFace_Intersector.def("Destroy", (void (IntCurvesFace_Intersector::*)()) &IntCurvesFace_Intersector::Destroy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntCurvesFace_ShapeIntersector.hxx
	py::class_<IntCurvesFace_ShapeIntersector, std::unique_ptr<IntCurvesFace_ShapeIntersector, Deleter<IntCurvesFace_ShapeIntersector>>> cls_IntCurvesFace_ShapeIntersector(mod, "IntCurvesFace_ShapeIntersector", "None");
	cls_IntCurvesFace_ShapeIntersector.def(py::init<>());
	cls_IntCurvesFace_ShapeIntersector.def("Load", (void (IntCurvesFace_ShapeIntersector::*)(const TopoDS_Shape &, const Standard_Real)) &IntCurvesFace_ShapeIntersector::Load, "None", py::arg("Sh"), py::arg("Tol"));
	cls_IntCurvesFace_ShapeIntersector.def("Perform", (void (IntCurvesFace_ShapeIntersector::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &IntCurvesFace_ShapeIntersector::Perform, "Perform the intersection between the segment L and the loaded shape.", py::arg("L"), py::arg("PInf"), py::arg("PSup"));
	cls_IntCurvesFace_ShapeIntersector.def("PerformNearest", (void (IntCurvesFace_ShapeIntersector::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &IntCurvesFace_ShapeIntersector::PerformNearest, "Perform the intersection between the segment L and the loaded shape.", py::arg("L"), py::arg("PInf"), py::arg("PSup"));
	cls_IntCurvesFace_ShapeIntersector.def("Perform", (void (IntCurvesFace_ShapeIntersector::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real)) &IntCurvesFace_ShapeIntersector::Perform, "same method for a HCurve from Adaptor3d. PInf an PSup can also be - and + INF.", py::arg("HCu"), py::arg("PInf"), py::arg("PSup"));
	cls_IntCurvesFace_ShapeIntersector.def("IsDone", (Standard_Boolean (IntCurvesFace_ShapeIntersector::*)() const ) &IntCurvesFace_ShapeIntersector::IsDone, "True is returned when the intersection have been computed.");
	cls_IntCurvesFace_ShapeIntersector.def("NbPnt", (Standard_Integer (IntCurvesFace_ShapeIntersector::*)() const ) &IntCurvesFace_ShapeIntersector::NbPnt, "None");
	cls_IntCurvesFace_ShapeIntersector.def("UParameter", (Standard_Real (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const ) &IntCurvesFace_ShapeIntersector::UParameter, "Returns the U parameter of the ith intersection point on the surface.", py::arg("I"));
	cls_IntCurvesFace_ShapeIntersector.def("VParameter", (Standard_Real (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const ) &IntCurvesFace_ShapeIntersector::VParameter, "Returns the V parameter of the ith intersection point on the surface.", py::arg("I"));
	cls_IntCurvesFace_ShapeIntersector.def("WParameter", (Standard_Real (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const ) &IntCurvesFace_ShapeIntersector::WParameter, "Returns the parameter of the ith intersection point on the line.", py::arg("I"));
	cls_IntCurvesFace_ShapeIntersector.def("Pnt", (const gp_Pnt & (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const ) &IntCurvesFace_ShapeIntersector::Pnt, "Returns the geometric point of the ith intersection between the line and the surface.", py::arg("I"));
	cls_IntCurvesFace_ShapeIntersector.def("Transition", (IntCurveSurface_TransitionOnCurve (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const ) &IntCurvesFace_ShapeIntersector::Transition, "Returns the ith transition of the line on the surface.", py::arg("I"));
	cls_IntCurvesFace_ShapeIntersector.def("State", (TopAbs_State (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const ) &IntCurvesFace_ShapeIntersector::State, "Returns the ith state of the point on the face. The values can be either TopAbs_IN ( the point is in the face) or TopAbs_ON ( the point is on a boudary of the face).", py::arg("I"));
	cls_IntCurvesFace_ShapeIntersector.def("Face", (const TopoDS_Face & (IntCurvesFace_ShapeIntersector::*)(const Standard_Integer) const ) &IntCurvesFace_ShapeIntersector::Face, "Returns the significant face used to determine the intersection.", py::arg("I"));
	cls_IntCurvesFace_ShapeIntersector.def("SortResult", (void (IntCurvesFace_ShapeIntersector::*)()) &IntCurvesFace_ShapeIntersector::SortResult, "Internal method. Sort the result on the Curve parameter.");
	cls_IntCurvesFace_ShapeIntersector.def("Destroy", (void (IntCurvesFace_ShapeIntersector::*)()) &IntCurvesFace_ShapeIntersector::Destroy, "None");


}
