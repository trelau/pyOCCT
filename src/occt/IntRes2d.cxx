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
#include <IntRes2d_Position.hxx>
#include <IntRes2d_TypeTrans.hxx>
#include <IntRes2d_Situation.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Transition.hxx>
#include <gp_Pnt2d.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <NCollection_Sequence.hxx>
#include <IntRes2d_SequenceOfIntersectionPoint.hxx>
#include <IntRes2d_IntersectionSegment.hxx>
#include <IntRes2d_SequenceOfIntersectionSegment.hxx>
#include <IntRes2d_Intersection.hxx>
#include <IntRes2d_Domain.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(IntRes2d, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");

// ENUM: INTRES2D_POSITION
py::enum_<IntRes2d_Position>(mod, "IntRes2d_Position", "None")
	.value("IntRes2d_Head", IntRes2d_Position::IntRes2d_Head)
	.value("IntRes2d_Middle", IntRes2d_Position::IntRes2d_Middle)
	.value("IntRes2d_End", IntRes2d_Position::IntRes2d_End)
	.export_values();


// ENUM: INTRES2D_TYPETRANS
py::enum_<IntRes2d_TypeTrans>(mod, "IntRes2d_TypeTrans", "None")
	.value("IntRes2d_In", IntRes2d_TypeTrans::IntRes2d_In)
	.value("IntRes2d_Out", IntRes2d_TypeTrans::IntRes2d_Out)
	.value("IntRes2d_Touch", IntRes2d_TypeTrans::IntRes2d_Touch)
	.value("IntRes2d_Undecided", IntRes2d_TypeTrans::IntRes2d_Undecided)
	.export_values();


// ENUM: INTRES2D_SITUATION
py::enum_<IntRes2d_Situation>(mod, "IntRes2d_Situation", "None")
	.value("IntRes2d_Inside", IntRes2d_Situation::IntRes2d_Inside)
	.value("IntRes2d_Outside", IntRes2d_Situation::IntRes2d_Outside)
	.value("IntRes2d_Unknown", IntRes2d_Situation::IntRes2d_Unknown)
	.export_values();


// CLASS: INTRES2D_TRANSITION
py::class_<IntRes2d_Transition> cls_IntRes2d_Transition(mod, "IntRes2d_Transition", "Definition of the type of transition near an intersection point between two curves. The transition is either a 'true transition', which means that one of the curves goes inside or outside the area defined by the other curve near the intersection, or a 'touch transition' which means that the first curve does not cross the other one, or an 'undecided' transition, which means that the curves are superposed.");

// Constructors
cls_IntRes2d_Transition.def(py::init<>());
cls_IntRes2d_Transition.def(py::init<const Standard_Boolean, const IntRes2d_Position, const IntRes2d_TypeTrans>(), py::arg("Tangent"), py::arg("Pos"), py::arg("Type"));
cls_IntRes2d_Transition.def(py::init<const Standard_Boolean, const IntRes2d_Position, const IntRes2d_Situation, const Standard_Boolean>(), py::arg("Tangent"), py::arg("Pos"), py::arg("Situ"), py::arg("Oppos"));
cls_IntRes2d_Transition.def(py::init<const IntRes2d_Position>(), py::arg("Pos"));

// Methods
// cls_IntRes2d_Transition.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_Transition::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_Transition.def_static("operator delete_", (void (*)(void *)) &IntRes2d_Transition::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_Transition.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_Transition::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_Transition.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_Transition::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_Transition.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_Transition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_Transition.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_Transition::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_Transition.def("SetValue", (void (IntRes2d_Transition::*)(const Standard_Boolean, const IntRes2d_Position, const IntRes2d_TypeTrans)) &IntRes2d_Transition::SetValue, "Sets the values of an IN or OUT transition.", py::arg("Tangent"), py::arg("Pos"), py::arg("Type"));
cls_IntRes2d_Transition.def("SetValue", (void (IntRes2d_Transition::*)(const Standard_Boolean, const IntRes2d_Position, const IntRes2d_Situation, const Standard_Boolean)) &IntRes2d_Transition::SetValue, "Sets the values of a TOUCH transition.", py::arg("Tangent"), py::arg("Pos"), py::arg("Situ"), py::arg("Oppos"));
cls_IntRes2d_Transition.def("SetValue", (void (IntRes2d_Transition::*)(const IntRes2d_Position)) &IntRes2d_Transition::SetValue, "Sets the values of an UNDECIDED transition.", py::arg("Pos"));
cls_IntRes2d_Transition.def("SetPosition", (void (IntRes2d_Transition::*)(const IntRes2d_Position)) &IntRes2d_Transition::SetPosition, "Sets the value of the position.", py::arg("Pos"));
cls_IntRes2d_Transition.def("PositionOnCurve", (IntRes2d_Position (IntRes2d_Transition::*)() const) &IntRes2d_Transition::PositionOnCurve, "Indicates if the intersection is at the beginning (IntRes2d_Head), at the end (IntRes2d_End), or in the middle (IntRes2d_Middle) of the curve.");
cls_IntRes2d_Transition.def("TransitionType", (IntRes2d_TypeTrans (IntRes2d_Transition::*)() const) &IntRes2d_Transition::TransitionType, "Returns the type of transition at the intersection. It may be IN or OUT or TOUCH, or UNDECIDED if the two first derivatives are not enough to give the tangent to one of the two curves.");
cls_IntRes2d_Transition.def("IsTangent", (Standard_Boolean (IntRes2d_Transition::*)() const) &IntRes2d_Transition::IsTangent, "Returns TRUE when the 2 curves are tangent at the intersection point. Theexception DomainError is raised if the type of transition is UNDECIDED.");
cls_IntRes2d_Transition.def("Situation", (IntRes2d_Situation (IntRes2d_Transition::*)() const) &IntRes2d_Transition::Situation, "returns a significant value if TransitionType returns TOUCH. In this case, the function returns : INSIDE when the curve remains inside the other one, OUTSIDE when it remains outside the other one, UNKNOWN when the calculus, based on the second derivatives cannot give the result. If TransitionType returns IN or OUT or UNDECIDED, the exception DomainError is raised.");
cls_IntRes2d_Transition.def("IsOpposite", (Standard_Boolean (IntRes2d_Transition::*)() const) &IntRes2d_Transition::IsOpposite, "returns a significant value if TransitionType returns TOUCH. In this case, the function returns true when the 2 curves locally define two different parts of the space. If TransitionType returns IN or OUT or UNDECIDED, the exception DomainError is raised.");

// CLASS: INTRES2D_INTERSECTIONPOINT
py::class_<IntRes2d_IntersectionPoint> cls_IntRes2d_IntersectionPoint(mod, "IntRes2d_IntersectionPoint", "Definition of an intersection point between two 2D curves.");

// Constructors
cls_IntRes2d_IntersectionPoint.def(py::init<>());
cls_IntRes2d_IntersectionPoint.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Real, const IntRes2d_Transition &, const IntRes2d_Transition &, const Standard_Boolean>(), py::arg("P"), py::arg("Uc1"), py::arg("Uc2"), py::arg("Trans1"), py::arg("Trans2"), py::arg("ReversedFlag"));

// Methods
// cls_IntRes2d_IntersectionPoint.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_IntersectionPoint::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_IntersectionPoint.def_static("operator delete_", (void (*)(void *)) &IntRes2d_IntersectionPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_IntersectionPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_IntersectionPoint::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_IntersectionPoint.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_IntersectionPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_IntersectionPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_IntersectionPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_IntersectionPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_IntersectionPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_IntersectionPoint.def("SetValues", (void (IntRes2d_IntersectionPoint::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Real, const IntRes2d_Transition &, const IntRes2d_Transition &, const Standard_Boolean)) &IntRes2d_IntersectionPoint::SetValues, "Sets the values for an existing intersection point. The meaning of the parameters are the same as for the Create.", py::arg("P"), py::arg("Uc1"), py::arg("Uc2"), py::arg("Trans1"), py::arg("Trans2"), py::arg("ReversedFlag"));
cls_IntRes2d_IntersectionPoint.def("Value", (const gp_Pnt2d & (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::Value, "Returns the value of the coordinates of the intersection point in the 2D space.");
cls_IntRes2d_IntersectionPoint.def("ParamOnFirst", (Standard_Real (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::ParamOnFirst, "Returns the parameter on the first curve.");
cls_IntRes2d_IntersectionPoint.def("ParamOnSecond", (Standard_Real (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::ParamOnSecond, "Returns the parameter on the second curve.");
cls_IntRes2d_IntersectionPoint.def("TransitionOfFirst", (const IntRes2d_Transition & (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::TransitionOfFirst, "Returns the transition of the 1st curve compared to the 2nd one.");
cls_IntRes2d_IntersectionPoint.def("TransitionOfSecond", (const IntRes2d_Transition & (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::TransitionOfSecond, "returns the transition of the 2nd curve compared to the 1st one.");

// TYPEDEF: INTRES2D_SEQUENCEOFINTERSECTIONPOINT
bind_NCollection_Sequence<IntRes2d_IntersectionPoint>(mod, "IntRes2d_SequenceOfIntersectionPoint", py::module_local(false));

// CLASS: INTRES2D_INTERSECTIONSEGMENT
py::class_<IntRes2d_IntersectionSegment> cls_IntRes2d_IntersectionSegment(mod, "IntRes2d_IntersectionSegment", "Definition of an intersection curve between two 2D curves.");

// Constructors
cls_IntRes2d_IntersectionSegment.def(py::init<>());
cls_IntRes2d_IntersectionSegment.def(py::init<const IntRes2d_IntersectionPoint &, const IntRes2d_IntersectionPoint &, const Standard_Boolean, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("Oppos"), py::arg("ReverseFlag"));
cls_IntRes2d_IntersectionSegment.def(py::init<const IntRes2d_IntersectionPoint &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("P"), py::arg("First"), py::arg("Oppos"), py::arg("ReverseFlag"));
cls_IntRes2d_IntersectionSegment.def(py::init<const Standard_Boolean>(), py::arg("Oppos"));

// Methods
// cls_IntRes2d_IntersectionSegment.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_IntersectionSegment::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_IntersectionSegment.def_static("operator delete_", (void (*)(void *)) &IntRes2d_IntersectionSegment::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_IntersectionSegment.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_IntersectionSegment::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_IntersectionSegment.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_IntersectionSegment::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_IntersectionSegment.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_IntersectionSegment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_IntersectionSegment.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_IntersectionSegment::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_IntersectionSegment.def("IsOpposite", (Standard_Boolean (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::IsOpposite, "Returns FALSE if the intersection segment has got the same orientation on both curves.");
cls_IntRes2d_IntersectionSegment.def("HasFirstPoint", (Standard_Boolean (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::HasFirstPoint, "Returns True if the segment is limited by a first point. This point defines the lowest parameter admitted on the first curve for the segment. If IsOpposite returns False, it defines the lowest parameter on the second curve, otherwise, it is the highest parameter on the second curve.");
cls_IntRes2d_IntersectionSegment.def("FirstPoint", (const IntRes2d_IntersectionPoint & (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::FirstPoint, "Returns the first point of the segment as an IntersectionPoint (with a transition). The exception DomainError is raised if HasFirstPoint returns False.");
cls_IntRes2d_IntersectionSegment.def("HasLastPoint", (Standard_Boolean (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::HasLastPoint, "Returns True if the segment is limited by a last point. This point defines the highest parameter admitted on the first curve for the segment. If IsOpposite returns False, it defines the highest parameter on the second curve, otherwise, it is the lowest parameter on the second curve.");
cls_IntRes2d_IntersectionSegment.def("LastPoint", (const IntRes2d_IntersectionPoint & (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::LastPoint, "Returns the last point of the segment as an IntersectionPoint (with a transition). The exception DomainError is raised if HasLastExtremity returns False.");

// TYPEDEF: INTRES2D_SEQUENCEOFINTERSECTIONSEGMENT
bind_NCollection_Sequence<IntRes2d_IntersectionSegment>(mod, "IntRes2d_SequenceOfIntersectionSegment", py::module_local(false));

// CLASS: INTRES2D_INTERSECTION
py::class_<IntRes2d_Intersection, std::unique_ptr<IntRes2d_Intersection, py::nodelete>> cls_IntRes2d_Intersection(mod, "IntRes2d_Intersection", "Defines the root class of all the Intersections between two 2D-Curves, and provides all the methods about the results of the Intersections Algorithms.");

// Methods
// cls_IntRes2d_Intersection.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_Intersection::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_Intersection.def_static("operator delete_", (void (*)(void *)) &IntRes2d_Intersection::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_Intersection.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_Intersection::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_Intersection.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_Intersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_Intersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_Intersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_Intersection.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_Intersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_Intersection.def("IsDone", (Standard_Boolean (IntRes2d_Intersection::*)() const) &IntRes2d_Intersection::IsDone, "returns TRUE when the computation was successful.");
cls_IntRes2d_Intersection.def("IsEmpty", (Standard_Boolean (IntRes2d_Intersection::*)() const) &IntRes2d_Intersection::IsEmpty, "Returns TRUE if there is no intersection between the given arguments. The exception NotDone is raised if IsDone returns FALSE.");
cls_IntRes2d_Intersection.def("NbPoints", (Standard_Integer (IntRes2d_Intersection::*)() const) &IntRes2d_Intersection::NbPoints, "This function returns the number of intersection points between the 2 curves. The exception NotDone is raised if IsDone returns FALSE.");
cls_IntRes2d_Intersection.def("Point", (const IntRes2d_IntersectionPoint & (IntRes2d_Intersection::*)(const Standard_Integer) const) &IntRes2d_Intersection::Point, "This function returns the intersection point of range N; The exception NotDone is raised if IsDone returns FALSE. The exception OutOfRange is raised if (N <= 0) or (N > NbPoints).", py::arg("N"));
cls_IntRes2d_Intersection.def("NbSegments", (Standard_Integer (IntRes2d_Intersection::*)() const) &IntRes2d_Intersection::NbSegments, "This function returns the number of intersection segments between the two curves. The exception NotDone is raised if IsDone returns FALSE.");
cls_IntRes2d_Intersection.def("Segment", (const IntRes2d_IntersectionSegment & (IntRes2d_Intersection::*)(const Standard_Integer) const) &IntRes2d_Intersection::Segment, "This function returns the intersection segment of range N; The exception NotDone is raised if IsDone returns FALSE. The exception OutOfRange is raised if (N <= 0) or (N > NbPoints).", py::arg("N"));
cls_IntRes2d_Intersection.def("SetReversedParameters", (void (IntRes2d_Intersection::*)(const Standard_Boolean)) &IntRes2d_Intersection::SetReversedParameters, "None", py::arg("Reverseflag"));

// CLASS: INTRES2D_DOMAIN
py::class_<IntRes2d_Domain> cls_IntRes2d_Domain(mod, "IntRes2d_Domain", "Definition of the domain of parameter on a 2d-curve. Most of the time, a domain is defined by two extremities. An extremity is made of : - a point in 2d-space (Pnt2d from gp), - a parameter on the curve, - a tolerance in the 2d-space. Sometimes, it can be made of 0 or 1 point ( for an infinite or semi-infinite line for example).");

// Constructors
cls_IntRes2d_Domain.def(py::init<>());
cls_IntRes2d_Domain.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Pnt1"), py::arg("Par1"), py::arg("Tol1"), py::arg("Pnt2"), py::arg("Par2"), py::arg("Tol2"));
cls_IntRes2d_Domain.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Pnt"), py::arg("Par"), py::arg("Tol"), py::arg("First"));

// Methods
// cls_IntRes2d_Domain.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_Domain::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_Domain.def_static("operator delete_", (void (*)(void *)) &IntRes2d_Domain::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_Domain.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_Domain::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_Domain.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_Domain::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_Domain.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_Domain::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_Domain.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_Domain::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_Domain.def("SetValues", (void (IntRes2d_Domain::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &IntRes2d_Domain::SetValues, "Sets the values for a bounded domain.", py::arg("Pnt1"), py::arg("Par1"), py::arg("Tol1"), py::arg("Pnt2"), py::arg("Par2"), py::arg("Tol2"));
cls_IntRes2d_Domain.def("SetValues", (void (IntRes2d_Domain::*)()) &IntRes2d_Domain::SetValues, "Sets the values for an infinite domain.");
cls_IntRes2d_Domain.def("SetValues", (void (IntRes2d_Domain::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &IntRes2d_Domain::SetValues, "Sets the values for a semi-infinite domain.", py::arg("Pnt"), py::arg("Par"), py::arg("Tol"), py::arg("First"));
cls_IntRes2d_Domain.def("SetEquivalentParameters", (void (IntRes2d_Domain::*)(const Standard_Real, const Standard_Real)) &IntRes2d_Domain::SetEquivalentParameters, "Defines a closed domain.", py::arg("zero"), py::arg("period"));
cls_IntRes2d_Domain.def("HasFirstPoint", (Standard_Boolean (IntRes2d_Domain::*)() const) &IntRes2d_Domain::HasFirstPoint, "Returns True if the domain has a first point, i-e a point defining the lowest admitted parameter on the curve.");
cls_IntRes2d_Domain.def("FirstParameter", (Standard_Real (IntRes2d_Domain::*)() const) &IntRes2d_Domain::FirstParameter, "Returns the parameter of the first point of the domain The exception DomainError is raised if HasFirstPoint returns False.");
cls_IntRes2d_Domain.def("FirstPoint", (const gp_Pnt2d & (IntRes2d_Domain::*)() const) &IntRes2d_Domain::FirstPoint, "Returns the first point of the domain. The exception DomainError is raised if HasFirstPoint returns False.");
cls_IntRes2d_Domain.def("FirstTolerance", (Standard_Real (IntRes2d_Domain::*)() const) &IntRes2d_Domain::FirstTolerance, "Returns the tolerance of the first (left) bound. The exception DomainError is raised if HasFirstPoint returns False.");
cls_IntRes2d_Domain.def("HasLastPoint", (Standard_Boolean (IntRes2d_Domain::*)() const) &IntRes2d_Domain::HasLastPoint, "Returns True if the domain has a last point, i-e a point defining the highest admitted parameter on the curve.");
cls_IntRes2d_Domain.def("LastParameter", (Standard_Real (IntRes2d_Domain::*)() const) &IntRes2d_Domain::LastParameter, "Returns the parameter of the last point of the domain. The exception DomainError is raised if HasLastPoint returns False.");
cls_IntRes2d_Domain.def("LastPoint", (const gp_Pnt2d & (IntRes2d_Domain::*)() const) &IntRes2d_Domain::LastPoint, "Returns the last point of the domain. The exception DomainError is raised if HasLastPoint returns False.");
cls_IntRes2d_Domain.def("LastTolerance", (Standard_Real (IntRes2d_Domain::*)() const) &IntRes2d_Domain::LastTolerance, "Returns the tolerance of the last (right) bound. The exception DomainError is raised if HasLastPoint returns False.");
cls_IntRes2d_Domain.def("IsClosed", (Standard_Boolean (IntRes2d_Domain::*)() const) &IntRes2d_Domain::IsClosed, "Returns True if the domain is closed.");
cls_IntRes2d_Domain.def("EquivalentParameters", [](IntRes2d_Domain &self, Standard_Real & zero, Standard_Real & zeroplusperiod){ self.EquivalentParameters(zero, zeroplusperiod); return std::tuple<Standard_Real &, Standard_Real &>(zero, zeroplusperiod); }, "Returns Equivalent parameters if the domain is closed. Otherwise, the exception DomainError is raised.", py::arg("zero"), py::arg("zeroplusperiod"));


}
