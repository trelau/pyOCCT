#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TopoDS_Shape.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <IntCurveSurface_IntersectionPoint.hxx>
#include <gp_Pnt.hxx>
#include <TopAbs_State.hxx>
#include <IntCurveSurface_TransitionOnCurve.hxx>
#include <TopoDS_Face.hxx>
#include <BRepIntCurveSurface_Inter.hxx>

PYBIND11_MODULE(BRepIntCurveSurface, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.GeomAdaptor");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.IntCurveSurface");
	py::module::import("OCCT.TopAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepIntCurveSurface_Inter.hxx
	py::class_<BRepIntCurveSurface_Inter, std::unique_ptr<BRepIntCurveSurface_Inter, Deleter<BRepIntCurveSurface_Inter>>> cls_BRepIntCurveSurface_Inter(mod, "BRepIntCurveSurface_Inter", "Computes the intersection between a face and a curve. To intersect one curve with shape method Init(Shape, curve, tTol) should be used. To intersect a few curves with specified shape it is necessary to load shape one time using method Load(shape, tol) and find intersection points for each curve using method Init(curve). For iteration by intersection points method More() and Next() should be used.");
	cls_BRepIntCurveSurface_Inter.def(py::init<>());
	cls_BRepIntCurveSurface_Inter.def("Init", (void (BRepIntCurveSurface_Inter::*)(const TopoDS_Shape &, const GeomAdaptor_Curve &, const Standard_Real)) &BRepIntCurveSurface_Inter::Init, "Load the Shape, the curve and initialize the tolerance used for the classification.", py::arg("theShape"), py::arg("theCurve"), py::arg("theTol"));
	cls_BRepIntCurveSurface_Inter.def("Init", (void (BRepIntCurveSurface_Inter::*)(const TopoDS_Shape &, const gp_Lin &, const Standard_Real)) &BRepIntCurveSurface_Inter::Init, "Load the Shape, the curve and initialize the tolerance used for the classification.", py::arg("theShape"), py::arg("theLine"), py::arg("theTol"));
	cls_BRepIntCurveSurface_Inter.def("Load", (void (BRepIntCurveSurface_Inter::*)(const TopoDS_Shape &, const Standard_Real)) &BRepIntCurveSurface_Inter::Load, "Load the Shape, and initialize the tolerance used for the classification.", py::arg("theShape"), py::arg("theTol"));
	cls_BRepIntCurveSurface_Inter.def("Init", (void (BRepIntCurveSurface_Inter::*)(const GeomAdaptor_Curve &)) &BRepIntCurveSurface_Inter::Init, "Method to find intersections of specified curve with loaded shape.", py::arg("theCurve"));
	cls_BRepIntCurveSurface_Inter.def("More", (Standard_Boolean (BRepIntCurveSurface_Inter::*)() const ) &BRepIntCurveSurface_Inter::More, "returns True if there is a current face.");
	cls_BRepIntCurveSurface_Inter.def("Next", (void (BRepIntCurveSurface_Inter::*)()) &BRepIntCurveSurface_Inter::Next, "Sets the next intersection point to check.");
	cls_BRepIntCurveSurface_Inter.def("Point", (IntCurveSurface_IntersectionPoint (BRepIntCurveSurface_Inter::*)() const ) &BRepIntCurveSurface_Inter::Point, "returns the current Intersection point.");
	cls_BRepIntCurveSurface_Inter.def("Pnt", (const gp_Pnt & (BRepIntCurveSurface_Inter::*)() const ) &BRepIntCurveSurface_Inter::Pnt, "returns the current geometric Point");
	cls_BRepIntCurveSurface_Inter.def("U", (Standard_Real (BRepIntCurveSurface_Inter::*)() const ) &BRepIntCurveSurface_Inter::U, "returns the U parameter of the current point on the current face.");
	cls_BRepIntCurveSurface_Inter.def("V", (Standard_Real (BRepIntCurveSurface_Inter::*)() const ) &BRepIntCurveSurface_Inter::V, "returns the V parameter of the current point on the current face.");
	cls_BRepIntCurveSurface_Inter.def("W", (Standard_Real (BRepIntCurveSurface_Inter::*)() const ) &BRepIntCurveSurface_Inter::W, "returns the parameter of the current point on the curve.");
	cls_BRepIntCurveSurface_Inter.def("State", (TopAbs_State (BRepIntCurveSurface_Inter::*)() const ) &BRepIntCurveSurface_Inter::State, "returns the current state (IN or ON)");
	cls_BRepIntCurveSurface_Inter.def("Transition", (IntCurveSurface_TransitionOnCurve (BRepIntCurveSurface_Inter::*)() const ) &BRepIntCurveSurface_Inter::Transition, "returns the transition of the line on the surface (IN or OUT or UNKNOWN)");
	cls_BRepIntCurveSurface_Inter.def("Face", (const TopoDS_Face & (BRepIntCurveSurface_Inter::*)() const ) &BRepIntCurveSurface_Inter::Face, "returns the current face.");


}
