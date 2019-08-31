/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <IntCurveSurface_TransitionOnCurve.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <IntCurveSurface_IntersectionPoint.hxx>
#include <NCollection_Sequence.hxx>
#include <IntCurveSurface_SequenceOfPnt.hxx>
#include <IntCurveSurface_IntersectionSegment.hxx>
#include <IntCurveSurface_SequenceOfSeg.hxx>
#include <IntCurveSurface_Intersection.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntCurveSurface_ThePolygonOfHInter.hxx>
#include <IntCurveSurface_ThePolyhedronOfHInter.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <IntAna_IntConicQuad.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <Bnd_Box.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntCurveSurface_HInter.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <IntCurveSurface_TheCSFunctionOfHInter.hxx>
#include <math_FunctionSetRoot.hxx>
#include <IntCurveSurface_TheExactHInter.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_CurveType.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <IntCurveSurface_TheHCurveTool.hxx>
#include <Intf_Interference.hxx>
#include <Intf_Array1OfLin.hxx>
#include <gp_XYZ.hxx>
#include <IntCurveSurface_TheInterferenceOfHInter.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <IntCurveSurface_ThePolygonToolOfHInter.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <IntCurveSurface_ThePolyhedronToolOfHInter.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <IntCurveSurface_TheQuadCurvExactHInter.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <IntSurf_Quadric.hxx>
#include <IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(IntCurveSurface, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.IntAna");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Intf");
py::module::import("OCCT.IntSurf");

// ENUM: INTCURVESURFACE_TRANSITIONONCURVE
py::enum_<IntCurveSurface_TransitionOnCurve>(mod, "IntCurveSurface_TransitionOnCurve", "\ Uo ^ \ U1 ^ \ | n \ | n Surf ====\======|=== ====\======|=== \ . \ . \ . \ . U1 \ . Uo \ .")
	.value("IntCurveSurface_Tangent", IntCurveSurface_TransitionOnCurve::IntCurveSurface_Tangent)
	.value("IntCurveSurface_In", IntCurveSurface_TransitionOnCurve::IntCurveSurface_In)
	.value("IntCurveSurface_Out", IntCurveSurface_TransitionOnCurve::IntCurveSurface_Out)
	.export_values();


// CLASS: INTCURVESURFACE_INTERSECTIONPOINT
py::class_<IntCurveSurface_IntersectionPoint> cls_IntCurveSurface_IntersectionPoint(mod, "IntCurveSurface_IntersectionPoint", "Definition of an interserction point between a curve and a surface.");

// Constructors
cls_IntCurveSurface_IntersectionPoint.def(py::init<>());
cls_IntCurveSurface_IntersectionPoint.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const IntCurveSurface_TransitionOnCurve>(), py::arg("P"), py::arg("USurf"), py::arg("VSurf"), py::arg("UCurv"), py::arg("TrCurv"));

// Methods
// cls_IntCurveSurface_IntersectionPoint.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_IntersectionPoint::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_IntersectionPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_IntersectionPoint::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_IntersectionPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_IntersectionPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_IntersectionPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_IntersectionPoint.def("SetValues", (void (IntCurveSurface_IntersectionPoint::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const IntCurveSurface_TransitionOnCurve)) &IntCurveSurface_IntersectionPoint::SetValues, "Set the fields of the current IntersectionPoint.", py::arg("P"), py::arg("USurf"), py::arg("VSurf"), py::arg("UCurv"), py::arg("TrCurv"));
cls_IntCurveSurface_IntersectionPoint.def("Values", [](IntCurveSurface_IntersectionPoint &self, gp_Pnt & P, Standard_Real & USurf, Standard_Real & VSurf, Standard_Real & UCurv, IntCurveSurface_TransitionOnCurve & TrCurv){ self.Values(P, USurf, VSurf, UCurv, TrCurv); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(USurf, VSurf, UCurv); }, "Get the fields of the current IntersectionPoint.", py::arg("P"), py::arg("USurf"), py::arg("VSurf"), py::arg("UCurv"), py::arg("TrCurv"));
cls_IntCurveSurface_IntersectionPoint.def("Pnt", (const gp_Pnt & (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::Pnt, "returns the geometric point.");
cls_IntCurveSurface_IntersectionPoint.def("U", (Standard_Real (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::U, "returns the U parameter on the surface.");
cls_IntCurveSurface_IntersectionPoint.def("V", (Standard_Real (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::V, "returns the V parameter on the surface.");
cls_IntCurveSurface_IntersectionPoint.def("W", (Standard_Real (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::W, "returns the parameter on the curve.");
cls_IntCurveSurface_IntersectionPoint.def("Transition", (IntCurveSurface_TransitionOnCurve (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::Transition, "returns the Transition of the point.");
cls_IntCurveSurface_IntersectionPoint.def("Dump", (void (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::Dump, "Dump all the fields.");

// TYPEDEF: INTCURVESURFACE_SEQUENCEOFPNT
bind_NCollection_Sequence<IntCurveSurface_IntersectionPoint>(mod, "IntCurveSurface_SequenceOfPnt", py::module_local(false));

// CLASS: INTCURVESURFACE_INTERSECTIONSEGMENT
py::class_<IntCurveSurface_IntersectionSegment> cls_IntCurveSurface_IntersectionSegment(mod, "IntCurveSurface_IntersectionSegment", "A IntersectionSegment describes a segment of curve (w1,w2) where distance(C(w),Surface) is less than a given tolerances.");

// Constructors
cls_IntCurveSurface_IntersectionSegment.def(py::init<>());
cls_IntCurveSurface_IntersectionSegment.def(py::init<const IntCurveSurface_IntersectionPoint &, const IntCurveSurface_IntersectionPoint &>(), py::arg("P1"), py::arg("P2"));

// Methods
// cls_IntCurveSurface_IntersectionSegment.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_IntersectionSegment::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_IntersectionSegment::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_IntersectionSegment::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_IntersectionSegment::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_IntersectionSegment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_IntersectionSegment::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_IntersectionSegment.def("SetValues", (void (IntCurveSurface_IntersectionSegment::*)(const IntCurveSurface_IntersectionPoint &, const IntCurveSurface_IntersectionPoint &)) &IntCurveSurface_IntersectionSegment::SetValues, "None", py::arg("P1"), py::arg("P2"));
cls_IntCurveSurface_IntersectionSegment.def("Values", (void (IntCurveSurface_IntersectionSegment::*)(IntCurveSurface_IntersectionPoint &, IntCurveSurface_IntersectionPoint &) const) &IntCurveSurface_IntersectionSegment::Values, "None", py::arg("P1"), py::arg("P2"));
cls_IntCurveSurface_IntersectionSegment.def("FirstPoint", (void (IntCurveSurface_IntersectionSegment::*)(IntCurveSurface_IntersectionPoint &) const) &IntCurveSurface_IntersectionSegment::FirstPoint, "None", py::arg("P1"));
cls_IntCurveSurface_IntersectionSegment.def("SecondPoint", (void (IntCurveSurface_IntersectionSegment::*)(IntCurveSurface_IntersectionPoint &) const) &IntCurveSurface_IntersectionSegment::SecondPoint, "None", py::arg("P2"));
cls_IntCurveSurface_IntersectionSegment.def("FirstPoint", (const IntCurveSurface_IntersectionPoint & (IntCurveSurface_IntersectionSegment::*)() const) &IntCurveSurface_IntersectionSegment::FirstPoint, "None");
cls_IntCurveSurface_IntersectionSegment.def("SecondPoint", (const IntCurveSurface_IntersectionPoint & (IntCurveSurface_IntersectionSegment::*)() const) &IntCurveSurface_IntersectionSegment::SecondPoint, "None");
cls_IntCurveSurface_IntersectionSegment.def("Dump", (void (IntCurveSurface_IntersectionSegment::*)() const) &IntCurveSurface_IntersectionSegment::Dump, "None");

// TYPEDEF: INTCURVESURFACE_SEQUENCEOFSEG
bind_NCollection_Sequence<IntCurveSurface_IntersectionSegment>(mod, "IntCurveSurface_SequenceOfSeg", py::module_local(false));

// CLASS: INTCURVESURFACE_INTERSECTION
py::class_<IntCurveSurface_Intersection, std::unique_ptr<IntCurveSurface_Intersection, py::nodelete>> cls_IntCurveSurface_Intersection(mod, "IntCurveSurface_Intersection", "None");

// Methods
// cls_IntCurveSurface_Intersection.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_Intersection::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_Intersection.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_Intersection::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_Intersection.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_Intersection::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_Intersection.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_Intersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_Intersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_Intersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_Intersection.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_Intersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_Intersection.def("IsDone", (Standard_Boolean (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::IsDone, "returns the <done> field.");
cls_IntCurveSurface_Intersection.def("NbPoints", (Standard_Integer (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::NbPoints, "returns the number of IntersectionPoint if IsDone returns True. else NotDone is raised.");
cls_IntCurveSurface_Intersection.def("Point", (const IntCurveSurface_IntersectionPoint & (IntCurveSurface_Intersection::*)(const Standard_Integer) const) &IntCurveSurface_Intersection::Point, "returns the IntersectionPoint of range <Index> raises NotDone if the computation has failed or if the computation has not been done raises OutOfRange if Index is not in the range <1..NbPoints>", py::arg("Index"));
cls_IntCurveSurface_Intersection.def("NbSegments", (Standard_Integer (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::NbSegments, "returns the number of IntersectionSegment if IsDone returns True. else NotDone is raised.");
cls_IntCurveSurface_Intersection.def("Segment", (const IntCurveSurface_IntersectionSegment & (IntCurveSurface_Intersection::*)(const Standard_Integer) const) &IntCurveSurface_Intersection::Segment, "returns the IntersectionSegment of range <Index> raises NotDone if the computation has failed or if the computation has not been done raises OutOfRange if Index is not in the range <1..NbSegment>", py::arg("Index"));
cls_IntCurveSurface_Intersection.def("IsParallel", (Standard_Boolean (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::IsParallel, "Returns true if curve is parallel or belongs surface This case is recognized only for some pairs of analytical curves and surfaces (plane - line, ...)");
cls_IntCurveSurface_Intersection.def("Dump", (void (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::Dump, "Dump all the fields.");

// CLASS: INTCURVESURFACE_HINTER
py::class_<IntCurveSurface_HInter, IntCurveSurface_Intersection> cls_IntCurveSurface_HInter(mod, "IntCurveSurface_HInter", "None");

// Constructors
cls_IntCurveSurface_HInter.def(py::init<>());

// Methods
// cls_IntCurveSurface_HInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_HInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_HInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_HInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_HInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_HInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_HInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_HInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_HInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_HInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_HInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_HInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface", py::arg("Curve"), py::arg("Surface"));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const IntCurveSurface_ThePolygonOfHInter &, const opencascade::handle<Adaptor3d_HSurface> &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given.", py::arg("Curve"), py::arg("Polygon"), py::arg("Surface"));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const IntCurveSurface_ThePolygonOfHInter &, const opencascade::handle<Adaptor3d_HSurface> &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given. The Surface is also sampled and <Polyhedron> is given.", py::arg("Curve"), py::arg("ThePolygon"), py::arg("Surface"), py::arg("Polyhedron"));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const IntCurveSurface_ThePolygonOfHInter &, const opencascade::handle<Adaptor3d_HSurface> &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given. The Surface is also sampled and <Polyhedron> is given.", py::arg("Curve"), py::arg("ThePolygon"), py::arg("Surface"), py::arg("Polyhedron"), py::arg("BndBSB"));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface. The Surface is already sampled and its polyhedron : <Polyhedron> is given.", py::arg("Curve"), py::arg("Surface"), py::arg("Polyhedron"));

// CLASS: INTCURVESURFACE_THECSFUNCTIONOFHINTER
py::class_<IntCurveSurface_TheCSFunctionOfHInter, math_FunctionSetWithDerivatives> cls_IntCurveSurface_TheCSFunctionOfHInter(mod, "IntCurveSurface_TheCSFunctionOfHInter", "None");

// Constructors
cls_IntCurveSurface_TheCSFunctionOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"));

// Methods
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheCSFunctionOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheCSFunctionOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheCSFunctionOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheCSFunctionOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheCSFunctionOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheCSFunctionOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheCSFunctionOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheCSFunctionOfHInter.def("NbVariables", (Standard_Integer (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::NbVariables, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("NbEquations", (Standard_Integer (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::NbEquations, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Value", (Standard_Boolean (IntCurveSurface_TheCSFunctionOfHInter::*)(const math_Vector &, math_Vector &)) &IntCurveSurface_TheCSFunctionOfHInter::Value, "None", py::arg("X"), py::arg("F"));
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Derivatives", (Standard_Boolean (IntCurveSurface_TheCSFunctionOfHInter::*)(const math_Vector &, math_Matrix &)) &IntCurveSurface_TheCSFunctionOfHInter::Derivatives, "None", py::arg("X"), py::arg("D"));
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Values", (Standard_Boolean (IntCurveSurface_TheCSFunctionOfHInter::*)(const math_Vector &, math_Vector &, math_Matrix &)) &IntCurveSurface_TheCSFunctionOfHInter::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Point", (const gp_Pnt & (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::Point, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("Root", (Standard_Real (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::Root, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("AuxillarSurface", (const opencascade::handle<Adaptor3d_HSurface> & (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::AuxillarSurface, "None");
cls_IntCurveSurface_TheCSFunctionOfHInter.def("AuxillarCurve", (const opencascade::handle<Adaptor3d_HCurve> & (IntCurveSurface_TheCSFunctionOfHInter::*)() const) &IntCurveSurface_TheCSFunctionOfHInter::AuxillarCurve, "None");

// CLASS: INTCURVESURFACE_THEEXACTHINTER
py::class_<IntCurveSurface_TheExactHInter> cls_IntCurveSurface_TheExactHInter(mod, "IntCurveSurface_TheExactHInter", "None");

// Constructors
cls_IntCurveSurface_TheExactHInter.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const IntCurveSurface_TheCSFunctionOfHInter &, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"));
cls_IntCurveSurface_TheExactHInter.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const IntCurveSurface_TheCSFunctionOfHInter &, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("F"), py::arg("TolTangency"), py::arg("MarginCoef"));
cls_IntCurveSurface_TheExactHInter.def(py::init<const IntCurveSurface_TheCSFunctionOfHInter &, const Standard_Real>(), py::arg("F"), py::arg("TolTangency"));

// Methods
// cls_IntCurveSurface_TheExactHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheExactHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheExactHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheExactHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheExactHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheExactHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheExactHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheExactHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheExactHInter.def("Perform", (void (IntCurveSurface_TheExactHInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_FunctionSetRoot &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntCurveSurface_TheExactHInter::Perform, "compute the solution it's possible to write to optimize: IntImp_IntCS inter(S1,C1,Toltangency) math_FunctionSetRoot rsnld(Inter.function()) while ...{ u=... v=... w=... inter.Perform(u,v,w,rsnld) } or IntImp_IntCS inter(Toltangency) inter.SetSurface(S); math_FunctionSetRoot rsnld(Inter.function()) while ...{ C=... inter.SetCurve(C); u=... v=... w=... inter.Perform(u,v,w,rsnld) }", py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Rsnld"), py::arg("u0"), py::arg("v0"), py::arg("u1"), py::arg("v1"), py::arg("w0"), py::arg("w1"));
cls_IntCurveSurface_TheExactHInter.def("IsDone", (Standard_Boolean (IntCurveSurface_TheExactHInter::*)() const) &IntCurveSurface_TheExactHInter::IsDone, "Returns TRUE if the creation completed without failure.");
cls_IntCurveSurface_TheExactHInter.def("IsEmpty", (Standard_Boolean (IntCurveSurface_TheExactHInter::*)() const) &IntCurveSurface_TheExactHInter::IsEmpty, "None");
cls_IntCurveSurface_TheExactHInter.def("Point", (const gp_Pnt & (IntCurveSurface_TheExactHInter::*)() const) &IntCurveSurface_TheExactHInter::Point, "returns the intersection point The exception NotDone is raised if IsDone is false. The exception DomainError is raised if IsEmpty is true.");
cls_IntCurveSurface_TheExactHInter.def("ParameterOnCurve", (Standard_Real (IntCurveSurface_TheExactHInter::*)() const) &IntCurveSurface_TheExactHInter::ParameterOnCurve, "None");
cls_IntCurveSurface_TheExactHInter.def("ParameterOnSurface", [](IntCurveSurface_TheExactHInter &self, Standard_Real & U, Standard_Real & V){ self.ParameterOnSurface(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_IntCurveSurface_TheExactHInter.def("Function", (IntCurveSurface_TheCSFunctionOfHInter & (IntCurveSurface_TheExactHInter::*)()) &IntCurveSurface_TheExactHInter::Function, "return the math function which is used to compute the intersection");

// CLASS: INTCURVESURFACE_THEHCURVETOOL
py::class_<IntCurveSurface_TheHCurveTool> cls_IntCurveSurface_TheHCurveTool(mod, "IntCurveSurface_TheHCurveTool", "None");

// Methods
// cls_IntCurveSurface_TheHCurveTool.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheHCurveTool::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheHCurveTool.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheHCurveTool::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheHCurveTool.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheHCurveTool::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheHCurveTool.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheHCurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheHCurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheHCurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheHCurveTool.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheHCurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheHCurveTool.def_static("FirstParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::FirstParameter, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("LastParameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::LastParameter, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("Continuity_", (GeomAbs_Shape (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::Continuity, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("NbIntervals_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HCurve> &, const GeomAbs_Shape)) &IntCurveSurface_TheHCurveTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(myclass) >= <S>", py::arg("C"), py::arg("S"));
cls_IntCurveSurface_TheHCurveTool.def_static("Intervals_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &IntCurveSurface_TheHCurveTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));
cls_IntCurveSurface_TheHCurveTool.def_static("IsClosed_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::IsClosed, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("IsPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::IsPeriodic, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("Period_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::Period, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("Value_", (gp_Pnt (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &IntCurveSurface_TheHCurveTool::Value, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"));
cls_IntCurveSurface_TheHCurveTool.def_static("D0_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &)) &IntCurveSurface_TheHCurveTool::D0, "Computes the point of parameter U on the curve.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_IntCurveSurface_TheHCurveTool.def_static("D1_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &)) &IntCurveSurface_TheHCurveTool::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V"));
cls_IntCurveSurface_TheHCurveTool.def_static("D2_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &IntCurveSurface_TheHCurveTool::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_IntCurveSurface_TheHCurveTool.def_static("D3_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &IntCurveSurface_TheHCurveTool::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C3.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_IntCurveSurface_TheHCurveTool.def_static("DN_", (gp_Vec (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Integer)) &IntCurveSurface_TheHCurveTool::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if the continuity of the current interval is not CN. Raised if N < 1.", py::arg("C"), py::arg("U"), py::arg("N"));
cls_IntCurveSurface_TheHCurveTool.def_static("Resolution_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &IntCurveSurface_TheHCurveTool::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("C"), py::arg("R3d"));
cls_IntCurveSurface_TheHCurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("Line_", (gp_Lin (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::Line, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("Circle_", (gp_Circ (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::Circle, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("Ellipse_", (gp_Elips (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::Ellipse, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("Hyperbola_", (gp_Hypr (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::Hyperbola, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("Parabola_", (gp_Parab (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::Parabola, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("Bezier_", (opencascade::handle<Geom_BezierCurve> (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::Bezier, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("BSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<Adaptor3d_HCurve> &)) &IntCurveSurface_TheHCurveTool::BSpline, "None", py::arg("C"));
cls_IntCurveSurface_TheHCurveTool.def_static("NbSamples_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real)) &IntCurveSurface_TheHCurveTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));
cls_IntCurveSurface_TheHCurveTool.def_static("SamplePars_", (void (*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, opencascade::handle<TColStd_HArray1OfReal> &)) &IntCurveSurface_TheHCurveTool::SamplePars, "None", py::arg("C"), py::arg("U0"), py::arg("U1"), py::arg("Defl"), py::arg("NbMin"), py::arg("Pars"));

// CLASS: INTCURVESURFACE_THEINTERFERENCEOFHINTER
py::class_<IntCurveSurface_TheInterferenceOfHInter, Intf_Interference> cls_IntCurveSurface_TheInterferenceOfHInter(mod, "IntCurveSurface_TheInterferenceOfHInter", "None");

// Constructors
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<>());
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &>(), py::arg("thePolyg"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const gp_Lin &, const IntCurveSurface_ThePolyhedronOfHInter &>(), py::arg("theLin"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const Intf_Array1OfLin &, const IntCurveSurface_ThePolyhedronOfHInter &>(), py::arg("theLins"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &>(), py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const gp_Lin &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &>(), py::arg("theLin"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def(py::init<const Intf_Array1OfLin &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &>(), py::arg("theLins"), py::arg("thePolyh"), py::arg("theBoundSB"));

// Methods
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheInterferenceOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheInterferenceOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheInterferenceOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheInterferenceOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheInterferenceOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheInterferenceOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheInterferenceOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Polygon and the Polyhedron.", py::arg("thePolyg"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const gp_Lin &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Straight Line and the Polyhedron.", py::arg("theLin"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const Intf_Array1OfLin &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Straight Lines and the Polyhedron.", py::arg("theLins"), py::arg("thePolyh"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Polygon and the Polyhedron.", py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const gp_Lin &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Straight Line and the Polyhedron.", py::arg("theLin"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Perform", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const Intf_Array1OfLin &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_TheInterferenceOfHInter::Perform, "Computes an interference between the Straight Lines and the Polyhedron.", py::arg("theLins"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Interference", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_TheInterferenceOfHInter::Interference, "Compares the boundings between the segment of <thePolyg> and the facets of <thePolyh>.", py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_IntCurveSurface_TheInterferenceOfHInter.def("Interference", (void (IntCurveSurface_TheInterferenceOfHInter::*)(const IntCurveSurface_ThePolygonOfHInter &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_TheInterferenceOfHInter::Interference, "Compares the boundings between the segment of <thePolyg> and the facets of <thePolyh>.", py::arg("thePolyg"), py::arg("thePolyh"));

// CLASS: INTCURVESURFACE_THEPOLYGONOFHINTER
py::class_<IntCurveSurface_ThePolygonOfHInter> cls_IntCurveSurface_ThePolygonOfHInter(mod, "IntCurveSurface_ThePolygonOfHInter", "None");

// Constructors
cls_IntCurveSurface_ThePolygonOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer>(), py::arg("Curve"), py::arg("NbPnt"));
cls_IntCurveSurface_ThePolygonOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Curve"), py::arg("U1"), py::arg("U2"), py::arg("NbPnt"));
cls_IntCurveSurface_ThePolygonOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const TColStd_Array1OfReal &>(), py::arg("Curve"), py::arg("Upars"));

// Methods
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_ThePolygonOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_ThePolygonOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_ThePolygonOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_ThePolygonOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_ThePolygonOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_ThePolygonOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_ThePolygonOfHInter.def("Bounding", (const Bnd_Box & (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::Bounding, "Give the bounding box of the polygon.");
cls_IntCurveSurface_ThePolygonOfHInter.def("DeflectionOverEstimation", (Standard_Real (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::DeflectionOverEstimation, "None");
cls_IntCurveSurface_ThePolygonOfHInter.def("SetDeflectionOverEstimation", (void (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Real)) &IntCurveSurface_ThePolygonOfHInter::SetDeflectionOverEstimation, "None", py::arg("x"));
cls_IntCurveSurface_ThePolygonOfHInter.def("Closed", (void (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolygonOfHInter::Closed, "None", py::arg("clos"));
cls_IntCurveSurface_ThePolygonOfHInter.def("Closed", (Standard_Boolean (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::Closed, "None");
cls_IntCurveSurface_ThePolygonOfHInter.def("NbSegments", (Standard_Integer (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::NbSegments, "Give the number of Segments in the polyline.");
cls_IntCurveSurface_ThePolygonOfHInter.def("BeginOfSeg", (const gp_Pnt & (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Integer) const) &IntCurveSurface_ThePolygonOfHInter::BeginOfSeg, "Give the point of range Index in the Polygon.", py::arg("Index"));
cls_IntCurveSurface_ThePolygonOfHInter.def("EndOfSeg", (const gp_Pnt & (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Integer) const) &IntCurveSurface_ThePolygonOfHInter::EndOfSeg, "Give the point of range Index in the Polygon.", py::arg("Index"));
cls_IntCurveSurface_ThePolygonOfHInter.def("InfParameter", (Standard_Real (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::InfParameter, "Returns the parameter (On the curve) of the first point of the Polygon");
cls_IntCurveSurface_ThePolygonOfHInter.def("SupParameter", (Standard_Real (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::SupParameter, "Returns the parameter (On the curve) of the last point of the Polygon");
cls_IntCurveSurface_ThePolygonOfHInter.def("ApproxParamOnCurve", (Standard_Real (IntCurveSurface_ThePolygonOfHInter::*)(const Standard_Integer, const Standard_Real) const) &IntCurveSurface_ThePolygonOfHInter::ApproxParamOnCurve, "Give an approximation of the parameter on the curve according to the discretization of the Curve.", py::arg("Index"), py::arg("ParamOnLine"));
cls_IntCurveSurface_ThePolygonOfHInter.def("Dump", (void (IntCurveSurface_ThePolygonOfHInter::*)() const) &IntCurveSurface_ThePolygonOfHInter::Dump, "None");

// CLASS: INTCURVESURFACE_THEPOLYGONTOOLOFHINTER
py::class_<IntCurveSurface_ThePolygonToolOfHInter> cls_IntCurveSurface_ThePolygonToolOfHInter(mod, "IntCurveSurface_ThePolygonToolOfHInter", "None");

// Methods
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_ThePolygonToolOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_ThePolygonToolOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_ThePolygonToolOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_ThePolygonToolOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_ThePolygonToolOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_ThePolygonToolOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("Bounding_", (const Bnd_Box & (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::Bounding, "Give the bounding box of the polygon.", py::arg("thePolygon"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("DeflectionOverEstimation_", (Standard_Real (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::DeflectionOverEstimation, "None", py::arg("thePolygon"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("Closed_", (Standard_Boolean (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::Closed, "None", py::arg("thePolygon"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("NbSegments_", (Standard_Integer (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::NbSegments, "None", py::arg("thePolygon"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("BeginOfSeg_", (const gp_Pnt & (*)(const IntCurveSurface_ThePolygonOfHInter &, const Standard_Integer)) &IntCurveSurface_ThePolygonToolOfHInter::BeginOfSeg, "Give the point of range Index in the Polygon.", py::arg("thePolygon"), py::arg("Index"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("EndOfSeg_", (const gp_Pnt & (*)(const IntCurveSurface_ThePolygonOfHInter &, const Standard_Integer)) &IntCurveSurface_ThePolygonToolOfHInter::EndOfSeg, "Give the point of range Index in the Polygon.", py::arg("thePolygon"), py::arg("Index"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("Dump_", (void (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::Dump, "None", py::arg("thePolygon"));

// CLASS: INTCURVESURFACE_THEPOLYHEDRONOFHINTER
py::class_<IntCurveSurface_ThePolyhedronOfHInter> cls_IntCurveSurface_ThePolyhedronOfHInter(mod, "IntCurveSurface_ThePolyhedronOfHInter", "None");

// Constructors
cls_IntCurveSurface_ThePolyhedronOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surface"), py::arg("nbdU"), py::arg("nbdV"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("Surface"), py::arg("Upars"), py::arg("Vpars"));

// Methods
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_ThePolyhedronOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_ThePolyhedronOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_ThePolyhedronOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_ThePolyhedronOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_ThePolyhedronOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_ThePolyhedronOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Destroy", (void (IntCurveSurface_ThePolyhedronOfHInter::*)()) &IntCurveSurface_ThePolyhedronOfHInter::Destroy, "None");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("DeflectionOverEstimation", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Real)) &IntCurveSurface_ThePolyhedronOfHInter::DeflectionOverEstimation, "None", py::arg("flec"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("DeflectionOnTriangle", (Standard_Real (IntCurveSurface_ThePolyhedronOfHInter::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer) const) &IntCurveSurface_ThePolyhedronOfHInter::DeflectionOnTriangle, "None", py::arg("Surface"), py::arg("Index"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("UMinSingularity", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolyhedronOfHInter::UMinSingularity, "None", py::arg("Sing"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("UMaxSingularity", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolyhedronOfHInter::UMaxSingularity, "None", py::arg("Sing"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("VMinSingularity", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolyhedronOfHInter::VMinSingularity, "None", py::arg("Sing"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("VMaxSingularity", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolyhedronOfHInter::VMaxSingularity, "None", py::arg("Sing"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Size", [](IntCurveSurface_ThePolyhedronOfHInter &self, Standard_Integer & nbdu, Standard_Integer & nbdv){ self.Size(nbdu, nbdv); return std::tuple<Standard_Integer &, Standard_Integer &>(nbdu, nbdv); }, "get the size of the discretization.", py::arg("nbdu"), py::arg("nbdv"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("NbTriangles", (Standard_Integer (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::NbTriangles, "Give the number of triangles in this double array of");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Triangle", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Index, Standard_Integer & P1, Standard_Integer & P2, Standard_Integer & P3){ self.Triangle(Index, P1, P2, P3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(P1, P2, P3); }, "Give the 3 points of the triangle of addresse Index in the double array of triangles.", py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("TriConnex", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Triang, const Standard_Integer Pivot, const Standard_Integer Pedge, Standard_Integer & TriCon, Standard_Integer & OtherP){ Standard_Integer rv = self.TriConnex(Triang, Pivot, Pedge, TriCon, OtherP); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &>(rv, TriCon, OtherP); }, "Give the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("NbPoints", (Standard_Integer (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::NbPoints, "Give the number of point in the double array of triangles ((nbdu+1)*(nbdv+1)).");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Point", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const gp_Pnt &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real)) &IntCurveSurface_ThePolyhedronOfHInter::Point, "Set the value of a field of the double array of points.", py::arg("thePnt"), py::arg("lig"), py::arg("col"), py::arg("U"), py::arg("V"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Point", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ const gp_Pnt & rv = self.Point(Index, U, V); return std::tuple<const gp_Pnt &, Standard_Real &, Standard_Real &>(rv, U, V); }, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Point", (const gp_Pnt & (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Integer) const) &IntCurveSurface_ThePolyhedronOfHInter::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Point", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Integer, gp_Pnt &) const) &IntCurveSurface_ThePolyhedronOfHInter::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("P"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Bounding", (const Bnd_Box & (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::Bounding, "Give the bounding box of the MaTriangle.");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("FillBounding", (void (IntCurveSurface_ThePolyhedronOfHInter::*)()) &IntCurveSurface_ThePolyhedronOfHInter::FillBounding, "Compute the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("ComponentsBounding", (const opencascade::handle<Bnd_HArray1OfBox> & (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("DeflectionOverEstimation", (Standard_Real (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::DeflectionOverEstimation, "None");
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("HasUMinSingularity", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::HasUMinSingularity, "None");
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("HasUMaxSingularity", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::HasUMaxSingularity, "None");
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("HasVMinSingularity", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::HasVMinSingularity, "None");
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("HasVMaxSingularity", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::HasVMaxSingularity, "None");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("PlaneEquation", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Triang, gp_XYZ & NormalVector, Standard_Real & PolarDistance){ self.PlaneEquation(Triang, NormalVector, PolarDistance); return PolarDistance; }, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("NormalVector"), py::arg("PolarDistance"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Contain", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Integer, const gp_Pnt &) const) &IntCurveSurface_ThePolyhedronOfHInter::Contain, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("ThePnt"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Parameters", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("IsOnBound", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Integer, const Standard_Integer) const) &IntCurveSurface_ThePolyhedronOfHInter::IsOnBound, "This method returns true if the edge based on points with indices Index1 and Index2 represents a boundary edge. It is necessary to take into account the boundary deflection for this edge.", py::arg("Index1"), py::arg("Index2"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("GetBorderDeflection", (Standard_Real (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::GetBorderDeflection, "This method returns a border deflection.");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Dump", (void (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::Dump, "None");

// CLASS: INTCURVESURFACE_THEPOLYHEDRONTOOLOFHINTER
py::class_<IntCurveSurface_ThePolyhedronToolOfHInter> cls_IntCurveSurface_ThePolyhedronToolOfHInter(mod, "IntCurveSurface_ThePolyhedronToolOfHInter", "None");

// Methods
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("Bounding_", (const Bnd_Box & (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::Bounding, "Give the bounding box of the PolyhedronTool.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("ComponentsBounding_", (const opencascade::handle<Bnd_HArray1OfBox> & (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("DeflectionOverEstimation_", (Standard_Real (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::DeflectionOverEstimation, "Give the tolerance of the polygon.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("NbTriangles_", (Standard_Integer (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::NbTriangles, "Give the number of triangles in this polyedral surface.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("Triangle_", [](const IntCurveSurface_ThePolyhedronOfHInter & thePolyh, const Standard_Integer Index, Standard_Integer & P1, Standard_Integer & P2, Standard_Integer & P3){ IntCurveSurface_ThePolyhedronToolOfHInter::Triangle(thePolyh, Index, P1, P2, P3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(P1, P2, P3); }, "Give the indices of the 3 points of the triangle of address Index in the PolyhedronTool.", py::arg("thePolyh"), py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("Point_", (const gp_Pnt & (*)(const IntCurveSurface_ThePolyhedronOfHInter &, const Standard_Integer)) &IntCurveSurface_ThePolyhedronToolOfHInter::Point, "Give the point of index i in the polyedral surface.", py::arg("thePolyh"), py::arg("Index"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("TriConnex_", [](const IntCurveSurface_ThePolyhedronOfHInter & thePolyh, const Standard_Integer Triang, const Standard_Integer Pivot, const Standard_Integer Pedge, Standard_Integer & TriCon, Standard_Integer & OtherP){ Standard_Integer rv = IntCurveSurface_ThePolyhedronToolOfHInter::TriConnex(thePolyh, Triang, Pivot, Pedge, TriCon, OtherP); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &>(rv, TriCon, OtherP); }, "Give the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("thePolyh"), py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("IsOnBound_", (Standard_Boolean (*)(const IntCurveSurface_ThePolyhedronOfHInter &, const Standard_Integer, const Standard_Integer)) &IntCurveSurface_ThePolyhedronToolOfHInter::IsOnBound, "This method returns true if the edge based on points with indices Index1 and Index2 represents a boundary edge. It is necessary to take into account the boundary deflection for this edge.", py::arg("thePolyh"), py::arg("Index1"), py::arg("Index2"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("GetBorderDeflection_", (Standard_Real (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::GetBorderDeflection, "This method returns a border deflection of the polyhedron.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("Dump_", (void (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::Dump, "None", py::arg("thePolyh"));

// CLASS: INTCURVESURFACE_THEQUADCURVEXACTHINTER
py::class_<IntCurveSurface_TheQuadCurvExactHInter> cls_IntCurveSurface_TheQuadCurvExactHInter(mod, "IntCurveSurface_TheQuadCurvExactHInter", "None");

// Constructors
cls_IntCurveSurface_TheQuadCurvExactHInter.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"));

// Methods
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheQuadCurvExactHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheQuadCurvExactHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheQuadCurvExactHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheQuadCurvExactHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheQuadCurvExactHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheQuadCurvExactHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheQuadCurvExactHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheQuadCurvExactHInter.def("IsDone", (Standard_Boolean (IntCurveSurface_TheQuadCurvExactHInter::*)() const) &IntCurveSurface_TheQuadCurvExactHInter::IsDone, "None");
cls_IntCurveSurface_TheQuadCurvExactHInter.def("NbRoots", (Standard_Integer (IntCurveSurface_TheQuadCurvExactHInter::*)() const) &IntCurveSurface_TheQuadCurvExactHInter::NbRoots, "None");
cls_IntCurveSurface_TheQuadCurvExactHInter.def("Root", (Standard_Real (IntCurveSurface_TheQuadCurvExactHInter::*)(const Standard_Integer) const) &IntCurveSurface_TheQuadCurvExactHInter::Root, "None", py::arg("Index"));
cls_IntCurveSurface_TheQuadCurvExactHInter.def("NbIntervals", (Standard_Integer (IntCurveSurface_TheQuadCurvExactHInter::*)() const) &IntCurveSurface_TheQuadCurvExactHInter::NbIntervals, "None");
cls_IntCurveSurface_TheQuadCurvExactHInter.def("Intervals", [](IntCurveSurface_TheQuadCurvExactHInter &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & U2){ self.Intervals(Index, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "U1 and U2 are the parameters of a segment on the curve.", py::arg("Index"), py::arg("U1"), py::arg("U2"));

// CLASS: INTCURVESURFACE_THEQUADCURVFUNCOFTHEQUADCURVEXACTHINTER
py::class_<IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter, math_FunctionWithDerivative> cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter(mod, "IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter", "None");

// Constructors
cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def(py::init<const IntSurf_Quadric &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("Q"), py::arg("C"));

// Methods
// cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def("Value", [](IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter &self, const Standard_Real Param, Standard_Real & F){ Standard_Boolean rv = self.Value(Param, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the signed distance between the implicit surface and the point at parameter Param on the parametrised curve. Value always returns True.", py::arg("Param"), py::arg("F"));
cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def("Derivative", [](IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter &self, const Standard_Real Param, Standard_Real & D){ Standard_Boolean rv = self.Derivative(Param, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Computes the derivative of the previous function at parameter Param. Derivative always returns True.", py::arg("Param"), py::arg("D"));
cls_IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter.def("Values", [](IntCurveSurface_TheQuadCurvFuncOfTheQuadCurvExactHInter &self, const Standard_Real Param, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(Param, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Computes the value and the derivative of the function. returns True.", py::arg("Param"), py::arg("F"), py::arg("D"));


}
