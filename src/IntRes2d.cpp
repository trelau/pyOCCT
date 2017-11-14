#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <IntRes2d_Position.hxx>
#include <IntRes2d_TypeTrans.hxx>
#include <IntRes2d_Situation.hxx>
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Transition.hxx>
#include <gp_Pnt2d.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <IntRes2d_SequenceOfIntersectionPoint.hxx>
#include <IntRes2d_IntersectionSegment.hxx>
#include <IntRes2d_SequenceOfIntersectionSegment.hxx>
#include <IntRes2d_Intersection.hxx>
#include <IntRes2d_Domain.hxx>

PYBIND11_MODULE(IntRes2d, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntRes2d_Position.hxx
	py::enum_<IntRes2d_Position>(mod, "IntRes2d_Position", "None")
		.value("IntRes2d_Head", IntRes2d_Position::IntRes2d_Head)
		.value("IntRes2d_Middle", IntRes2d_Position::IntRes2d_Middle)
		.value("IntRes2d_End", IntRes2d_Position::IntRes2d_End)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntRes2d_TypeTrans.hxx
	py::enum_<IntRes2d_TypeTrans>(mod, "IntRes2d_TypeTrans", "None")
		.value("IntRes2d_In", IntRes2d_TypeTrans::IntRes2d_In)
		.value("IntRes2d_Out", IntRes2d_TypeTrans::IntRes2d_Out)
		.value("IntRes2d_Touch", IntRes2d_TypeTrans::IntRes2d_Touch)
		.value("IntRes2d_Undecided", IntRes2d_TypeTrans::IntRes2d_Undecided)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntRes2d_Situation.hxx
	py::enum_<IntRes2d_Situation>(mod, "IntRes2d_Situation", "None")
		.value("IntRes2d_Inside", IntRes2d_Situation::IntRes2d_Inside)
		.value("IntRes2d_Outside", IntRes2d_Situation::IntRes2d_Outside)
		.value("IntRes2d_Unknown", IntRes2d_Situation::IntRes2d_Unknown)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntRes2d_Transition.lxx
	mod.def("operator<<", (std::ostream & (*)(std::ostream &, IntRes2d_Transition &)) &operator<<, "None", py::arg(""), py::arg(""));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntRes2d_Transition.hxx
	py::class_<IntRes2d_Transition, std::unique_ptr<IntRes2d_Transition, Deleter<IntRes2d_Transition>>> cls_IntRes2d_Transition(mod, "IntRes2d_Transition", "Definition of the type of transition near an intersection point between two curves. The transition is either a 'true transition', which means that one of the curves goes inside or outside the area defined by the other curve near the intersection, or a 'touch transition' which means that the first curve does not cross the other one, or an 'undecided' transition, which means that the curves are superposed.");
	cls_IntRes2d_Transition.def(py::init<>());
	cls_IntRes2d_Transition.def(py::init<const Standard_Boolean, const IntRes2d_Position, const IntRes2d_TypeTrans>(), py::arg("Tangent"), py::arg("Pos"), py::arg("Type"));
	cls_IntRes2d_Transition.def(py::init<const Standard_Boolean, const IntRes2d_Position, const IntRes2d_Situation, const Standard_Boolean>(), py::arg("Tangent"), py::arg("Pos"), py::arg("Situ"), py::arg("Oppos"));
	cls_IntRes2d_Transition.def(py::init<const IntRes2d_Position>(), py::arg("Pos"));
	cls_IntRes2d_Transition.def("SetValue", (void (IntRes2d_Transition::*)(const Standard_Boolean, const IntRes2d_Position, const IntRes2d_TypeTrans)) &IntRes2d_Transition::SetValue, "Sets the values of an IN or OUT transition.", py::arg("Tangent"), py::arg("Pos"), py::arg("Type"));
	cls_IntRes2d_Transition.def("SetValue", (void (IntRes2d_Transition::*)(const Standard_Boolean, const IntRes2d_Position, const IntRes2d_Situation, const Standard_Boolean)) &IntRes2d_Transition::SetValue, "Sets the values of a TOUCH transition.", py::arg("Tangent"), py::arg("Pos"), py::arg("Situ"), py::arg("Oppos"));
	cls_IntRes2d_Transition.def("SetValue", (void (IntRes2d_Transition::*)(const IntRes2d_Position)) &IntRes2d_Transition::SetValue, "Sets the values of an UNDECIDED transition.", py::arg("Pos"));
	cls_IntRes2d_Transition.def("SetPosition", (void (IntRes2d_Transition::*)(const IntRes2d_Position)) &IntRes2d_Transition::SetPosition, "Sets the value of the position.", py::arg("Pos"));
	cls_IntRes2d_Transition.def("PositionOnCurve", (IntRes2d_Position (IntRes2d_Transition::*)() const ) &IntRes2d_Transition::PositionOnCurve, "Indicates if the intersection is at the beginning (IntRes2d_Head), at the end (IntRes2d_End), or in the middle (IntRes2d_Middle) of the curve.");
	cls_IntRes2d_Transition.def("TransitionType", (IntRes2d_TypeTrans (IntRes2d_Transition::*)() const ) &IntRes2d_Transition::TransitionType, "Returns the type of transition at the intersection. It may be IN or OUT or TOUCH, or UNDECIDED if the two first derivatives are not enough to give the tangent to one of the two curves.");
	cls_IntRes2d_Transition.def("IsTangent", (Standard_Boolean (IntRes2d_Transition::*)() const ) &IntRes2d_Transition::IsTangent, "Returns TRUE when the 2 curves are tangent at the intersection point. Theexception DomainError is raised if the type of transition is UNDECIDED.");
	cls_IntRes2d_Transition.def("Situation", (IntRes2d_Situation (IntRes2d_Transition::*)() const ) &IntRes2d_Transition::Situation, "returns a significant value if TransitionType returns TOUCH. In this case, the function returns : INSIDE when the curve remains inside the other one, OUTSIDE when it remains outside the other one, UNKNOWN when the calculus, based on the second derivatives cannot give the result. If TransitionType returns IN or OUT or UNDECIDED, the exception DomainError is raised.");
	cls_IntRes2d_Transition.def("IsOpposite", (Standard_Boolean (IntRes2d_Transition::*)() const ) &IntRes2d_Transition::IsOpposite, "returns a significant value if TransitionType returns TOUCH. In this case, the function returns true when the 2 curves locally define two different parts of the space. If TransitionType returns IN or OUT or UNDECIDED, the exception DomainError is raised.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntRes2d_IntersectionPoint.hxx
	py::class_<IntRes2d_IntersectionPoint, std::unique_ptr<IntRes2d_IntersectionPoint, Deleter<IntRes2d_IntersectionPoint>>> cls_IntRes2d_IntersectionPoint(mod, "IntRes2d_IntersectionPoint", "Definition of an intersection point between two 2D curves.");
	cls_IntRes2d_IntersectionPoint.def(py::init<>());
	cls_IntRes2d_IntersectionPoint.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Real, const IntRes2d_Transition &, const IntRes2d_Transition &, const Standard_Boolean>(), py::arg("P"), py::arg("Uc1"), py::arg("Uc2"), py::arg("Trans1"), py::arg("Trans2"), py::arg("ReversedFlag"));
	cls_IntRes2d_IntersectionPoint.def("SetValues", (void (IntRes2d_IntersectionPoint::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Real, const IntRes2d_Transition &, const IntRes2d_Transition &, const Standard_Boolean)) &IntRes2d_IntersectionPoint::SetValues, "Sets the values for an existing intersection point. The meaning of the parameters are the same as for the Create.", py::arg("P"), py::arg("Uc1"), py::arg("Uc2"), py::arg("Trans1"), py::arg("Trans2"), py::arg("ReversedFlag"));
	cls_IntRes2d_IntersectionPoint.def("Value", (const gp_Pnt2d & (IntRes2d_IntersectionPoint::*)() const ) &IntRes2d_IntersectionPoint::Value, "Returns the value of the coordinates of the intersection point in the 2D space.");
	cls_IntRes2d_IntersectionPoint.def("ParamOnFirst", (Standard_Real (IntRes2d_IntersectionPoint::*)() const ) &IntRes2d_IntersectionPoint::ParamOnFirst, "Returns the parameter on the first curve.");
	cls_IntRes2d_IntersectionPoint.def("ParamOnSecond", (Standard_Real (IntRes2d_IntersectionPoint::*)() const ) &IntRes2d_IntersectionPoint::ParamOnSecond, "Returns the parameter on the second curve.");
	cls_IntRes2d_IntersectionPoint.def("TransitionOfFirst", (const IntRes2d_Transition & (IntRes2d_IntersectionPoint::*)() const ) &IntRes2d_IntersectionPoint::TransitionOfFirst, "Returns the transition of the 1st curve compared to the 2nd one.");
	cls_IntRes2d_IntersectionPoint.def("TransitionOfSecond", (const IntRes2d_Transition & (IntRes2d_IntersectionPoint::*)() const ) &IntRes2d_IntersectionPoint::TransitionOfSecond, "returns the transition of the 2nd curve compared to the 1st one.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntRes2d_IntersectionSegment.hxx
	py::class_<IntRes2d_IntersectionSegment, std::unique_ptr<IntRes2d_IntersectionSegment, Deleter<IntRes2d_IntersectionSegment>>> cls_IntRes2d_IntersectionSegment(mod, "IntRes2d_IntersectionSegment", "Definition of an intersection curve between two 2D curves.");
	cls_IntRes2d_IntersectionSegment.def(py::init<>());
	cls_IntRes2d_IntersectionSegment.def(py::init<const IntRes2d_IntersectionPoint &, const IntRes2d_IntersectionPoint &, const Standard_Boolean, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("Oppos"), py::arg("ReverseFlag"));
	cls_IntRes2d_IntersectionSegment.def(py::init<const IntRes2d_IntersectionPoint &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("P"), py::arg("First"), py::arg("Oppos"), py::arg("ReverseFlag"));
	cls_IntRes2d_IntersectionSegment.def(py::init<const Standard_Boolean>(), py::arg("Oppos"));
	cls_IntRes2d_IntersectionSegment.def("IsOpposite", (Standard_Boolean (IntRes2d_IntersectionSegment::*)() const ) &IntRes2d_IntersectionSegment::IsOpposite, "Returns FALSE if the intersection segment has got the same orientation on both curves.");
	cls_IntRes2d_IntersectionSegment.def("HasFirstPoint", (Standard_Boolean (IntRes2d_IntersectionSegment::*)() const ) &IntRes2d_IntersectionSegment::HasFirstPoint, "Returns True if the segment is limited by a first point. This point defines the lowest parameter admitted on the first curve for the segment. If IsOpposite returns False, it defines the lowest parameter on the second curve, otherwise, it is the highest parameter on the second curve.");
	cls_IntRes2d_IntersectionSegment.def("FirstPoint", (const IntRes2d_IntersectionPoint & (IntRes2d_IntersectionSegment::*)() const ) &IntRes2d_IntersectionSegment::FirstPoint, "Returns the first point of the segment as an IntersectionPoint (with a transition). The exception DomainError is raised if HasFirstPoint returns False.");
	cls_IntRes2d_IntersectionSegment.def("HasLastPoint", (Standard_Boolean (IntRes2d_IntersectionSegment::*)() const ) &IntRes2d_IntersectionSegment::HasLastPoint, "Returns True if the segment is limited by a last point. This point defines the highest parameter admitted on the first curve for the segment. If IsOpposite returns False, it defines the highest parameter on the second curve, otherwise, it is the lowest parameter on the second curve.");
	cls_IntRes2d_IntersectionSegment.def("LastPoint", (const IntRes2d_IntersectionPoint & (IntRes2d_IntersectionSegment::*)() const ) &IntRes2d_IntersectionSegment::LastPoint, "Returns the last point of the segment as an IntersectionPoint (with a transition). The exception DomainError is raised if HasLastExtremity returns False.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntRes2d_Intersection.hxx
	py::class_<IntRes2d_Intersection, std::unique_ptr<IntRes2d_Intersection, py::nodelete>> cls_IntRes2d_Intersection(mod, "IntRes2d_Intersection", "Defines the root class of all the Intersections between two 2D-Curves, and provides all the methods about the results of the Intersections Algorithms.");
	cls_IntRes2d_Intersection.def("IsDone", (Standard_Boolean (IntRes2d_Intersection::*)() const ) &IntRes2d_Intersection::IsDone, "returns TRUE when the computation was successful.");
	cls_IntRes2d_Intersection.def("IsEmpty", (Standard_Boolean (IntRes2d_Intersection::*)() const ) &IntRes2d_Intersection::IsEmpty, "Returns TRUE if there is no intersection between the given arguments. The exception NotDone is raised if IsDone returns FALSE.");
	cls_IntRes2d_Intersection.def("NbPoints", (Standard_Integer (IntRes2d_Intersection::*)() const ) &IntRes2d_Intersection::NbPoints, "This function returns the number of intersection points between the 2 curves. The exception NotDone is raised if IsDone returns FALSE.");
	cls_IntRes2d_Intersection.def("Point", (const IntRes2d_IntersectionPoint & (IntRes2d_Intersection::*)(const Standard_Integer) const ) &IntRes2d_Intersection::Point, "This function returns the intersection point of range N; The exception NotDone is raised if IsDone returns FALSE. The exception OutOfRange is raised if (N <= 0) or (N > NbPoints).", py::arg("N"));
	cls_IntRes2d_Intersection.def("NbSegments", (Standard_Integer (IntRes2d_Intersection::*)() const ) &IntRes2d_Intersection::NbSegments, "This function returns the number of intersection segments between the two curves. The exception NotDone is raised if IsDone returns FALSE.");
	cls_IntRes2d_Intersection.def("Segment", (const IntRes2d_IntersectionSegment & (IntRes2d_Intersection::*)(const Standard_Integer) const ) &IntRes2d_Intersection::Segment, "This function returns the intersection segment of range N; The exception NotDone is raised if IsDone returns FALSE. The exception OutOfRange is raised if (N <= 0) or (N > NbPoints).", py::arg("N"));
	cls_IntRes2d_Intersection.def("SetReversedParameters", (void (IntRes2d_Intersection::*)(const Standard_Boolean)) &IntRes2d_Intersection::SetReversedParameters, "None", py::arg("Reverseflag"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntRes2d_Domain.hxx
	py::class_<IntRes2d_Domain, std::unique_ptr<IntRes2d_Domain, Deleter<IntRes2d_Domain>>> cls_IntRes2d_Domain(mod, "IntRes2d_Domain", "Definition of the domain of parameter on a 2d-curve. Most of the time, a domain is defined by two extremities. An extremity is made of : - a point in 2d-space (Pnt2d from gp), - a parameter on the curve, - a tolerance in the 2d-space. Sometimes, it can be made of 0 or 1 point ( for an infinite or semi-infinite line for example).");
	cls_IntRes2d_Domain.def(py::init<>());
	cls_IntRes2d_Domain.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Pnt1"), py::arg("Par1"), py::arg("Tol1"), py::arg("Pnt2"), py::arg("Par2"), py::arg("Tol2"));
	cls_IntRes2d_Domain.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Pnt"), py::arg("Par"), py::arg("Tol"), py::arg("First"));
	cls_IntRes2d_Domain.def("SetValues", (void (IntRes2d_Domain::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &IntRes2d_Domain::SetValues, "Sets the values for a bounded domain.", py::arg("Pnt1"), py::arg("Par1"), py::arg("Tol1"), py::arg("Pnt2"), py::arg("Par2"), py::arg("Tol2"));
	cls_IntRes2d_Domain.def("SetValues", (void (IntRes2d_Domain::*)()) &IntRes2d_Domain::SetValues, "Sets the values for an infinite domain.");
	cls_IntRes2d_Domain.def("SetValues", (void (IntRes2d_Domain::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &IntRes2d_Domain::SetValues, "Sets the values for a semi-infinite domain.", py::arg("Pnt"), py::arg("Par"), py::arg("Tol"), py::arg("First"));
	cls_IntRes2d_Domain.def("SetEquivalentParameters", (void (IntRes2d_Domain::*)(const Standard_Real, const Standard_Real)) &IntRes2d_Domain::SetEquivalentParameters, "Defines a closed domain.", py::arg("zero"), py::arg("period"));
	cls_IntRes2d_Domain.def("HasFirstPoint", (Standard_Boolean (IntRes2d_Domain::*)() const ) &IntRes2d_Domain::HasFirstPoint, "Returns True if the domain has a first point, i-e a point defining the lowest admitted parameter on the curve.");
	cls_IntRes2d_Domain.def("FirstParameter", (Standard_Real (IntRes2d_Domain::*)() const ) &IntRes2d_Domain::FirstParameter, "Returns the parameter of the first point of the domain The exception DomainError is raised if HasFirstPoint returns False.");
	cls_IntRes2d_Domain.def("FirstPoint", (const gp_Pnt2d & (IntRes2d_Domain::*)() const ) &IntRes2d_Domain::FirstPoint, "Returns the first point of the domain. The exception DomainError is raised if HasFirstPoint returns False.");
	cls_IntRes2d_Domain.def("FirstTolerance", (Standard_Real (IntRes2d_Domain::*)() const ) &IntRes2d_Domain::FirstTolerance, "Returns the tolerance of the first (left) bound. The exception DomainError is raised if HasFirstPoint returns False.");
	cls_IntRes2d_Domain.def("HasLastPoint", (Standard_Boolean (IntRes2d_Domain::*)() const ) &IntRes2d_Domain::HasLastPoint, "Returns True if the domain has a last point, i-e a point defining the highest admitted parameter on the curve.");
	cls_IntRes2d_Domain.def("LastParameter", (Standard_Real (IntRes2d_Domain::*)() const ) &IntRes2d_Domain::LastParameter, "Returns the parameter of the last point of the domain. The exception DomainError is raised if HasLastPoint returns False.");
	cls_IntRes2d_Domain.def("LastPoint", (const gp_Pnt2d & (IntRes2d_Domain::*)() const ) &IntRes2d_Domain::LastPoint, "Returns the last point of the domain. The exception DomainError is raised if HasLastPoint returns False.");
	cls_IntRes2d_Domain.def("LastTolerance", (Standard_Real (IntRes2d_Domain::*)() const ) &IntRes2d_Domain::LastTolerance, "Returns the tolerance of the last (right) bound. The exception DomainError is raised if HasLastPoint returns False.");
	cls_IntRes2d_Domain.def("IsClosed", (Standard_Boolean (IntRes2d_Domain::*)() const ) &IntRes2d_Domain::IsClosed, "Returns True if the domain is closed.");
	cls_IntRes2d_Domain.def("EquivalentParameters", (void (IntRes2d_Domain::*)(Standard_Real &, Standard_Real &) const ) &IntRes2d_Domain::EquivalentParameters, "Returns Equivalent parameters if the domain is closed. Otherwise, the exception DomainError is raised.", py::arg("zero"), py::arg("zeroplusperiod"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntRes2d_SequenceOfIntersectionPoint, std::unique_ptr<IntRes2d_SequenceOfIntersectionPoint, Deleter<IntRes2d_SequenceOfIntersectionPoint>>, NCollection_BaseSequence> cls_IntRes2d_SequenceOfIntersectionPoint(mod, "IntRes2d_SequenceOfIntersectionPoint", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntRes2d_SequenceOfIntersectionPoint.def(py::init<>());
	cls_IntRes2d_SequenceOfIntersectionPoint.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def(py::init([] (const IntRes2d_SequenceOfIntersectionPoint &other) {return new IntRes2d_SequenceOfIntersectionPoint(other);}), "Copy constructor", py::arg("other"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("begin", (IntRes2d_SequenceOfIntersectionPoint::iterator (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("end", (IntRes2d_SequenceOfIntersectionPoint::iterator (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("cbegin", (IntRes2d_SequenceOfIntersectionPoint::const_iterator (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("cend", (IntRes2d_SequenceOfIntersectionPoint::const_iterator (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Size", (Standard_Integer (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::Size, "Number of items");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Length", (Standard_Integer (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::Length, "Number of items");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Lower", (Standard_Integer (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::Lower, "Method for consistency with other collections.");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Upper", (Standard_Integer (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::Upper, "Method for consistency with other collections.");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("IsEmpty", (Standard_Boolean (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::IsEmpty, "Empty query");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Reverse", (void (IntRes2d_SequenceOfIntersectionPoint::*)()) &IntRes2d_SequenceOfIntersectionPoint::Reverse, "Reverse sequence");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Exchange", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer, const Standard_Integer)) &IntRes2d_SequenceOfIntersectionPoint::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntRes2d_SequenceOfIntersectionPoint::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Clear", [](IntRes2d_SequenceOfIntersectionPoint &self) -> void { return self.Clear(); });
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Clear", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntRes2d_SequenceOfIntersectionPoint::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Assign", (IntRes2d_SequenceOfIntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)(const IntRes2d_SequenceOfIntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("assign", (IntRes2d_SequenceOfIntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)(const IntRes2d_SequenceOfIntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Remove", (void (IntRes2d_SequenceOfIntersectionPoint::*)(IntRes2d_SequenceOfIntersectionPoint::Iterator &)) &IntRes2d_SequenceOfIntersectionPoint::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Remove", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer)) &IntRes2d_SequenceOfIntersectionPoint::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Remove", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer, const Standard_Integer)) &IntRes2d_SequenceOfIntersectionPoint::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Append", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const IntRes2d_IntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::Append, "Append one item", py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Append", (void (IntRes2d_SequenceOfIntersectionPoint::*)(IntRes2d_SequenceOfIntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Prepend", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const IntRes2d_IntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Prepend", (void (IntRes2d_SequenceOfIntersectionPoint::*)(IntRes2d_SequenceOfIntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("InsertBefore", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer, const IntRes2d_IntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("InsertBefore", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer, IntRes2d_SequenceOfIntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("InsertAfter", (void (IntRes2d_SequenceOfIntersectionPoint::*)(IntRes2d_SequenceOfIntersectionPoint::Iterator &, const IntRes2d_IntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("InsertAfter", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer, IntRes2d_SequenceOfIntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("InsertAfter", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer, const IntRes2d_IntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Split", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer, IntRes2d_SequenceOfIntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("First", (const IntRes2d_IntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::First, "First item access");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("ChangeFirst", (IntRes2d_IntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)()) &IntRes2d_SequenceOfIntersectionPoint::ChangeFirst, "First item access");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Last", (const IntRes2d_IntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)() const ) &IntRes2d_SequenceOfIntersectionPoint::Last, "Last item access");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("ChangeLast", (IntRes2d_IntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)()) &IntRes2d_SequenceOfIntersectionPoint::ChangeLast, "Last item access");
	cls_IntRes2d_SequenceOfIntersectionPoint.def("Value", (const IntRes2d_IntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer) const ) &IntRes2d_SequenceOfIntersectionPoint::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("__call__", (const IntRes2d_IntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer) const ) &IntRes2d_SequenceOfIntersectionPoint::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("ChangeValue", (IntRes2d_IntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer)) &IntRes2d_SequenceOfIntersectionPoint::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("__call__", (IntRes2d_IntersectionPoint & (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer)) &IntRes2d_SequenceOfIntersectionPoint::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("SetValue", (void (IntRes2d_SequenceOfIntersectionPoint::*)(const Standard_Integer, const IntRes2d_IntersectionPoint &)) &IntRes2d_SequenceOfIntersectionPoint::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionPoint.def("__iter__", [](const IntRes2d_SequenceOfIntersectionPoint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntRes2d_SequenceOfIntersectionSegment, std::unique_ptr<IntRes2d_SequenceOfIntersectionSegment, Deleter<IntRes2d_SequenceOfIntersectionSegment>>, NCollection_BaseSequence> cls_IntRes2d_SequenceOfIntersectionSegment(mod, "IntRes2d_SequenceOfIntersectionSegment", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntRes2d_SequenceOfIntersectionSegment.def(py::init<>());
	cls_IntRes2d_SequenceOfIntersectionSegment.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def(py::init([] (const IntRes2d_SequenceOfIntersectionSegment &other) {return new IntRes2d_SequenceOfIntersectionSegment(other);}), "Copy constructor", py::arg("other"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("begin", (IntRes2d_SequenceOfIntersectionSegment::iterator (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("end", (IntRes2d_SequenceOfIntersectionSegment::iterator (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("cbegin", (IntRes2d_SequenceOfIntersectionSegment::const_iterator (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("cend", (IntRes2d_SequenceOfIntersectionSegment::const_iterator (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Size", (Standard_Integer (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::Size, "Number of items");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Length", (Standard_Integer (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::Length, "Number of items");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Lower", (Standard_Integer (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::Lower, "Method for consistency with other collections.");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Upper", (Standard_Integer (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::Upper, "Method for consistency with other collections.");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("IsEmpty", (Standard_Boolean (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::IsEmpty, "Empty query");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Reverse", (void (IntRes2d_SequenceOfIntersectionSegment::*)()) &IntRes2d_SequenceOfIntersectionSegment::Reverse, "Reverse sequence");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Exchange", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer, const Standard_Integer)) &IntRes2d_SequenceOfIntersectionSegment::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntRes2d_SequenceOfIntersectionSegment::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Clear", [](IntRes2d_SequenceOfIntersectionSegment &self) -> void { return self.Clear(); });
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Clear", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntRes2d_SequenceOfIntersectionSegment::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Assign", (IntRes2d_SequenceOfIntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)(const IntRes2d_SequenceOfIntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("assign", (IntRes2d_SequenceOfIntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)(const IntRes2d_SequenceOfIntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Remove", (void (IntRes2d_SequenceOfIntersectionSegment::*)(IntRes2d_SequenceOfIntersectionSegment::Iterator &)) &IntRes2d_SequenceOfIntersectionSegment::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Remove", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer)) &IntRes2d_SequenceOfIntersectionSegment::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Remove", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer, const Standard_Integer)) &IntRes2d_SequenceOfIntersectionSegment::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Append", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const IntRes2d_IntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::Append, "Append one item", py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Append", (void (IntRes2d_SequenceOfIntersectionSegment::*)(IntRes2d_SequenceOfIntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Prepend", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const IntRes2d_IntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Prepend", (void (IntRes2d_SequenceOfIntersectionSegment::*)(IntRes2d_SequenceOfIntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("InsertBefore", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer, const IntRes2d_IntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("InsertBefore", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer, IntRes2d_SequenceOfIntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("InsertAfter", (void (IntRes2d_SequenceOfIntersectionSegment::*)(IntRes2d_SequenceOfIntersectionSegment::Iterator &, const IntRes2d_IntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("InsertAfter", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer, IntRes2d_SequenceOfIntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("InsertAfter", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer, const IntRes2d_IntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Split", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer, IntRes2d_SequenceOfIntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("First", (const IntRes2d_IntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::First, "First item access");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("ChangeFirst", (IntRes2d_IntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)()) &IntRes2d_SequenceOfIntersectionSegment::ChangeFirst, "First item access");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Last", (const IntRes2d_IntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)() const ) &IntRes2d_SequenceOfIntersectionSegment::Last, "Last item access");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("ChangeLast", (IntRes2d_IntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)()) &IntRes2d_SequenceOfIntersectionSegment::ChangeLast, "Last item access");
	cls_IntRes2d_SequenceOfIntersectionSegment.def("Value", (const IntRes2d_IntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer) const ) &IntRes2d_SequenceOfIntersectionSegment::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("__call__", (const IntRes2d_IntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer) const ) &IntRes2d_SequenceOfIntersectionSegment::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("ChangeValue", (IntRes2d_IntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer)) &IntRes2d_SequenceOfIntersectionSegment::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("__call__", (IntRes2d_IntersectionSegment & (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer)) &IntRes2d_SequenceOfIntersectionSegment::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("SetValue", (void (IntRes2d_SequenceOfIntersectionSegment::*)(const Standard_Integer, const IntRes2d_IntersectionSegment &)) &IntRes2d_SequenceOfIntersectionSegment::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntRes2d_SequenceOfIntersectionSegment.def("__iter__", [](const IntRes2d_SequenceOfIntersectionSegment &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
