#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <HatchGen_IntersectionType.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <HatchGen_IntersectionPoint.hxx>
#include <HatchGen_PointOnElement.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <HatchGen_PointsOnElement.hxx>
#include <HatchGen_PointOnHatching.hxx>
#include <HatchGen_PointsOnHatching.hxx>
#include <HatchGen_ErrorStatus.hxx>
#include <HatchGen_Domain.hxx>
#include <HatchGen_Domains.hxx>

PYBIND11_MODULE(HatchGen, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.IntRes2d");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\HatchGen_IntersectionType.hxx
	py::enum_<HatchGen_IntersectionType>(mod, "HatchGen_IntersectionType", "Intersection type between the hatching and the element.")
		.value("HatchGen_TRUE", HatchGen_IntersectionType::HatchGen_TRUE)
		.value("HatchGen_TOUCH", HatchGen_IntersectionType::HatchGen_TOUCH)
		.value("HatchGen_TANGENT", HatchGen_IntersectionType::HatchGen_TANGENT)
		.value("HatchGen_UNDETERMINED", HatchGen_IntersectionType::HatchGen_UNDETERMINED)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\HatchGen_ErrorStatus.hxx
	py::enum_<HatchGen_ErrorStatus>(mod, "HatchGen_ErrorStatus", "Error status.")
		.value("HatchGen_NoProblem", HatchGen_ErrorStatus::HatchGen_NoProblem)
		.value("HatchGen_TrimFailure", HatchGen_ErrorStatus::HatchGen_TrimFailure)
		.value("HatchGen_TransitionFailure", HatchGen_ErrorStatus::HatchGen_TransitionFailure)
		.value("HatchGen_IncoherentParity", HatchGen_ErrorStatus::HatchGen_IncoherentParity)
		.value("HatchGen_IncompatibleStates", HatchGen_ErrorStatus::HatchGen_IncompatibleStates)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\HatchGen_IntersectionPoint.hxx
	py::class_<HatchGen_IntersectionPoint, std::unique_ptr<HatchGen_IntersectionPoint, py::nodelete>> cls_HatchGen_IntersectionPoint(mod, "HatchGen_IntersectionPoint", "None");
	cls_HatchGen_IntersectionPoint.def("SetIndex", (void (HatchGen_IntersectionPoint::*)(const Standard_Integer)) &HatchGen_IntersectionPoint::SetIndex, "Sets the index of the supporting curve.", py::arg("Index"));
	cls_HatchGen_IntersectionPoint.def("Index", (Standard_Integer (HatchGen_IntersectionPoint::*)() const ) &HatchGen_IntersectionPoint::Index, "Returns the index of the supporting curve.");
	cls_HatchGen_IntersectionPoint.def("SetParameter", (void (HatchGen_IntersectionPoint::*)(const Standard_Real)) &HatchGen_IntersectionPoint::SetParameter, "Sets the parameter on the curve.", py::arg("Parameter"));
	cls_HatchGen_IntersectionPoint.def("Parameter", (Standard_Real (HatchGen_IntersectionPoint::*)() const ) &HatchGen_IntersectionPoint::Parameter, "Returns the parameter on the curve.");
	cls_HatchGen_IntersectionPoint.def("SetPosition", (void (HatchGen_IntersectionPoint::*)(const TopAbs_Orientation)) &HatchGen_IntersectionPoint::SetPosition, "Sets the position of the point on the curve.", py::arg("Position"));
	cls_HatchGen_IntersectionPoint.def("Position", (TopAbs_Orientation (HatchGen_IntersectionPoint::*)() const ) &HatchGen_IntersectionPoint::Position, "Returns the position of the point on the curve.");
	cls_HatchGen_IntersectionPoint.def("SetStateBefore", (void (HatchGen_IntersectionPoint::*)(const TopAbs_State)) &HatchGen_IntersectionPoint::SetStateBefore, "Sets the transition state before the intersection.", py::arg("State"));
	cls_HatchGen_IntersectionPoint.def("StateBefore", (TopAbs_State (HatchGen_IntersectionPoint::*)() const ) &HatchGen_IntersectionPoint::StateBefore, "Returns the transition state before the intersection.");
	cls_HatchGen_IntersectionPoint.def("SetStateAfter", (void (HatchGen_IntersectionPoint::*)(const TopAbs_State)) &HatchGen_IntersectionPoint::SetStateAfter, "Sets the transition state after the intersection.", py::arg("State"));
	cls_HatchGen_IntersectionPoint.def("StateAfter", (TopAbs_State (HatchGen_IntersectionPoint::*)() const ) &HatchGen_IntersectionPoint::StateAfter, "Returns the transition state after of the intersection.");
	cls_HatchGen_IntersectionPoint.def("SetSegmentBeginning", [](HatchGen_IntersectionPoint &self) -> void { return self.SetSegmentBeginning(); });
	cls_HatchGen_IntersectionPoint.def("SetSegmentBeginning", (void (HatchGen_IntersectionPoint::*)(const Standard_Boolean)) &HatchGen_IntersectionPoint::SetSegmentBeginning, "Sets the flag that the point is the beginning of a segment.", py::arg("State"));
	cls_HatchGen_IntersectionPoint.def("SegmentBeginning", (Standard_Boolean (HatchGen_IntersectionPoint::*)() const ) &HatchGen_IntersectionPoint::SegmentBeginning, "Returns the flag that the point is the beginning of a segment.");
	cls_HatchGen_IntersectionPoint.def("SetSegmentEnd", [](HatchGen_IntersectionPoint &self) -> void { return self.SetSegmentEnd(); });
	cls_HatchGen_IntersectionPoint.def("SetSegmentEnd", (void (HatchGen_IntersectionPoint::*)(const Standard_Boolean)) &HatchGen_IntersectionPoint::SetSegmentEnd, "Sets the flag that the point is the end of a segment.", py::arg("State"));
	cls_HatchGen_IntersectionPoint.def("SegmentEnd", (Standard_Boolean (HatchGen_IntersectionPoint::*)() const ) &HatchGen_IntersectionPoint::SegmentEnd, "Returns the flag that the point is the end of a segment.");
	// FIXME cls_HatchGen_IntersectionPoint.def("Dump", [](HatchGen_IntersectionPoint &self) -> void { return self.Dump(); });
	// FIXME cls_HatchGen_IntersectionPoint.def("Dump", (void (HatchGen_IntersectionPoint::*)(const Standard_Integer) const ) &HatchGen_IntersectionPoint::Dump, "Dump of the point on element.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\HatchGen_PointOnElement.hxx
	py::class_<HatchGen_PointOnElement, std::unique_ptr<HatchGen_PointOnElement, Deleter<HatchGen_PointOnElement>>, HatchGen_IntersectionPoint> cls_HatchGen_PointOnElement(mod, "HatchGen_PointOnElement", "None");
	cls_HatchGen_PointOnElement.def(py::init<>());
	cls_HatchGen_PointOnElement.def(py::init([] (const HatchGen_PointOnElement &other) {return new HatchGen_PointOnElement(other);}), "Copy constructor", py::arg("other"));
	cls_HatchGen_PointOnElement.def(py::init<const IntRes2d_IntersectionPoint &>(), py::arg("Point"));
	cls_HatchGen_PointOnElement.def("SetIntersectionType", (void (HatchGen_PointOnElement::*)(const HatchGen_IntersectionType)) &HatchGen_PointOnElement::SetIntersectionType, "Sets the intersection type at this point.", py::arg("Type"));
	cls_HatchGen_PointOnElement.def("IntersectionType", (HatchGen_IntersectionType (HatchGen_PointOnElement::*)() const ) &HatchGen_PointOnElement::IntersectionType, "Returns the intersection type at this point.");
	cls_HatchGen_PointOnElement.def("IsIdentical", (Standard_Boolean (HatchGen_PointOnElement::*)(const HatchGen_PointOnElement &, const Standard_Real) const ) &HatchGen_PointOnElement::IsIdentical, "Tests if the point is identical to an other. That is to say : P1.myIndex = P2.myIndex Abs (P1.myParam - P2.myParam) <= Confusion P1.myPosit = P2.myPosit P1.myBefore = P2.myBefore P1.myAfter = P2.myAfter P1.mySegBeg = P2.mySegBeg P1.mySegEnd = P2.mySegEnd P1.myType = P2.myType", py::arg("Point"), py::arg("Confusion"));
	cls_HatchGen_PointOnElement.def("IsDifferent", (Standard_Boolean (HatchGen_PointOnElement::*)(const HatchGen_PointOnElement &, const Standard_Real) const ) &HatchGen_PointOnElement::IsDifferent, "Tests if the point is different from an other.", py::arg("Point"), py::arg("Confusion"));
	// FIXME cls_HatchGen_PointOnElement.def("Dump", [](HatchGen_PointOnElement &self) -> void { return self.Dump(); });
	// FIXME cls_HatchGen_PointOnElement.def("Dump", (void (HatchGen_PointOnElement::*)(const Standard_Integer) const ) &HatchGen_PointOnElement::Dump, "Dump of the point on element.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\HatchGen_PointOnHatching.hxx
	py::class_<HatchGen_PointOnHatching, std::unique_ptr<HatchGen_PointOnHatching, Deleter<HatchGen_PointOnHatching>>, HatchGen_IntersectionPoint> cls_HatchGen_PointOnHatching(mod, "HatchGen_PointOnHatching", "None");
	cls_HatchGen_PointOnHatching.def(py::init<>());
	cls_HatchGen_PointOnHatching.def(py::init([] (const HatchGen_PointOnHatching &other) {return new HatchGen_PointOnHatching(other);}), "Copy constructor", py::arg("other"));
	cls_HatchGen_PointOnHatching.def(py::init<const IntRes2d_IntersectionPoint &>(), py::arg("Point"));
	cls_HatchGen_PointOnHatching.def("AddPoint", (void (HatchGen_PointOnHatching::*)(const HatchGen_PointOnElement &, const Standard_Real)) &HatchGen_PointOnHatching::AddPoint, "Adds a point on element to the point.", py::arg("Point"), py::arg("Confusion"));
	cls_HatchGen_PointOnHatching.def("NbPoints", (Standard_Integer (HatchGen_PointOnHatching::*)() const ) &HatchGen_PointOnHatching::NbPoints, "Returns the number of elements intersecting the hatching at this point.");
	cls_HatchGen_PointOnHatching.def("Point", (const HatchGen_PointOnElement & (HatchGen_PointOnHatching::*)(const Standard_Integer) const ) &HatchGen_PointOnHatching::Point, "Returns the Index-th point on element of the point. The exception OutOfRange is raised if Index > NbPoints.", py::arg("Index"));
	cls_HatchGen_PointOnHatching.def("RemPoint", (void (HatchGen_PointOnHatching::*)(const Standard_Integer)) &HatchGen_PointOnHatching::RemPoint, "Removes the Index-th point on element of the point. The exception OutOfRange is raised if Index > NbPoints.", py::arg("Index"));
	cls_HatchGen_PointOnHatching.def("ClrPoints", (void (HatchGen_PointOnHatching::*)()) &HatchGen_PointOnHatching::ClrPoints, "Removes all the points on element of the point.");
	cls_HatchGen_PointOnHatching.def("IsLower", (Standard_Boolean (HatchGen_PointOnHatching::*)(const HatchGen_PointOnHatching &, const Standard_Real) const ) &HatchGen_PointOnHatching::IsLower, "Tests if the point is lower than an other. A point on hatching P1 is said to be lower than an other P2 if : P2.myParam - P1.myParam > Confusion", py::arg("Point"), py::arg("Confusion"));
	cls_HatchGen_PointOnHatching.def("IsEqual", (Standard_Boolean (HatchGen_PointOnHatching::*)(const HatchGen_PointOnHatching &, const Standard_Real) const ) &HatchGen_PointOnHatching::IsEqual, "Tests if the point is equal to an other. A point on hatching P1 is said to be equal to an other P2 if : | P2.myParam - P1.myParam | <= Confusion", py::arg("Point"), py::arg("Confusion"));
	cls_HatchGen_PointOnHatching.def("IsGreater", (Standard_Boolean (HatchGen_PointOnHatching::*)(const HatchGen_PointOnHatching &, const Standard_Real) const ) &HatchGen_PointOnHatching::IsGreater, "Tests if the point is greater than an other. A point on hatching P1 is said to be greater than an other P2 if : P1.myParam - P2.myParam > Confusion", py::arg("Point"), py::arg("Confusion"));
	// FIXME cls_HatchGen_PointOnHatching.def("Dump", [](HatchGen_PointOnHatching &self) -> void { return self.Dump(); });
	// FIXME cls_HatchGen_PointOnHatching.def("Dump", (void (HatchGen_PointOnHatching::*)(const Standard_Integer) const ) &HatchGen_PointOnHatching::Dump, "Dump of the point.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\HatchGen_Domain.hxx
	py::class_<HatchGen_Domain, std::unique_ptr<HatchGen_Domain, Deleter<HatchGen_Domain>>> cls_HatchGen_Domain(mod, "HatchGen_Domain", "None");
	cls_HatchGen_Domain.def(py::init<>());
	cls_HatchGen_Domain.def(py::init<const HatchGen_PointOnHatching &, const HatchGen_PointOnHatching &>(), py::arg("P1"), py::arg("P2"));
	cls_HatchGen_Domain.def(py::init<const HatchGen_PointOnHatching &, const Standard_Boolean>(), py::arg("P"), py::arg("First"));
	cls_HatchGen_Domain.def("SetPoints", (void (HatchGen_Domain::*)(const HatchGen_PointOnHatching &, const HatchGen_PointOnHatching &)) &HatchGen_Domain::SetPoints, "Sets the first and the second points of the domain.", py::arg("P1"), py::arg("P2"));
	cls_HatchGen_Domain.def("SetPoints", (void (HatchGen_Domain::*)()) &HatchGen_Domain::SetPoints, "Sets the first and the second points of the domain as the infinite.");
	cls_HatchGen_Domain.def("SetFirstPoint", (void (HatchGen_Domain::*)(const HatchGen_PointOnHatching &)) &HatchGen_Domain::SetFirstPoint, "Sets the first point of the domain.", py::arg("P"));
	cls_HatchGen_Domain.def("SetFirstPoint", (void (HatchGen_Domain::*)()) &HatchGen_Domain::SetFirstPoint, "Sets the first point of the domain at the infinite.");
	cls_HatchGen_Domain.def("SetSecondPoint", (void (HatchGen_Domain::*)(const HatchGen_PointOnHatching &)) &HatchGen_Domain::SetSecondPoint, "Sets the second point of the domain.", py::arg("P"));
	cls_HatchGen_Domain.def("SetSecondPoint", (void (HatchGen_Domain::*)()) &HatchGen_Domain::SetSecondPoint, "Sets the second point of the domain at the infinite.");
	cls_HatchGen_Domain.def("HasFirstPoint", (Standard_Boolean (HatchGen_Domain::*)() const ) &HatchGen_Domain::HasFirstPoint, "Returns True if the domain has a first point.");
	cls_HatchGen_Domain.def("FirstPoint", (const HatchGen_PointOnHatching & (HatchGen_Domain::*)() const ) &HatchGen_Domain::FirstPoint, "Returns the first point of the domain. The exception DomainError is raised if HasFirstPoint returns False.");
	cls_HatchGen_Domain.def("HasSecondPoint", (Standard_Boolean (HatchGen_Domain::*)() const ) &HatchGen_Domain::HasSecondPoint, "Returns True if the domain has a second point.");
	cls_HatchGen_Domain.def("SecondPoint", (const HatchGen_PointOnHatching & (HatchGen_Domain::*)() const ) &HatchGen_Domain::SecondPoint, "Returns the second point of the domain. The exception DomainError is raised if HasSecondPoint returns False.");
	// FIXME cls_HatchGen_Domain.def("Dump", [](HatchGen_Domain &self) -> void { return self.Dump(); });
	// FIXME cls_HatchGen_Domain.def("Dump", (void (HatchGen_Domain::*)(const Standard_Integer) const ) &HatchGen_Domain::Dump, "Dump of the domain.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<HatchGen_PointsOnElement, std::unique_ptr<HatchGen_PointsOnElement, Deleter<HatchGen_PointsOnElement>>, NCollection_BaseSequence> cls_HatchGen_PointsOnElement(mod, "HatchGen_PointsOnElement", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_HatchGen_PointsOnElement.def(py::init<>());
	cls_HatchGen_PointsOnElement.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_HatchGen_PointsOnElement.def(py::init([] (const HatchGen_PointsOnElement &other) {return new HatchGen_PointsOnElement(other);}), "Copy constructor", py::arg("other"));
	cls_HatchGen_PointsOnElement.def("begin", (HatchGen_PointsOnElement::iterator (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_HatchGen_PointsOnElement.def("end", (HatchGen_PointsOnElement::iterator (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_HatchGen_PointsOnElement.def("cbegin", (HatchGen_PointsOnElement::const_iterator (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_HatchGen_PointsOnElement.def("cend", (HatchGen_PointsOnElement::const_iterator (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_HatchGen_PointsOnElement.def("Size", (Standard_Integer (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::Size, "Number of items");
	cls_HatchGen_PointsOnElement.def("Length", (Standard_Integer (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::Length, "Number of items");
	cls_HatchGen_PointsOnElement.def("Lower", (Standard_Integer (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::Lower, "Method for consistency with other collections.");
	cls_HatchGen_PointsOnElement.def("Upper", (Standard_Integer (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::Upper, "Method for consistency with other collections.");
	cls_HatchGen_PointsOnElement.def("IsEmpty", (Standard_Boolean (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::IsEmpty, "Empty query");
	cls_HatchGen_PointsOnElement.def("Reverse", (void (HatchGen_PointsOnElement::*)()) &HatchGen_PointsOnElement::Reverse, "Reverse sequence");
	cls_HatchGen_PointsOnElement.def("Exchange", (void (HatchGen_PointsOnElement::*)(const Standard_Integer, const Standard_Integer)) &HatchGen_PointsOnElement::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_HatchGen_PointsOnElement.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &HatchGen_PointsOnElement::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_HatchGen_PointsOnElement.def("Clear", [](HatchGen_PointsOnElement &self) -> void { return self.Clear(); });
	cls_HatchGen_PointsOnElement.def("Clear", (void (HatchGen_PointsOnElement::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &HatchGen_PointsOnElement::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_HatchGen_PointsOnElement.def("Assign", (HatchGen_PointsOnElement & (HatchGen_PointsOnElement::*)(const HatchGen_PointsOnElement &)) &HatchGen_PointsOnElement::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_HatchGen_PointsOnElement.def("assign", (HatchGen_PointsOnElement & (HatchGen_PointsOnElement::*)(const HatchGen_PointsOnElement &)) &HatchGen_PointsOnElement::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_HatchGen_PointsOnElement.def("Remove", (void (HatchGen_PointsOnElement::*)(HatchGen_PointsOnElement::Iterator &)) &HatchGen_PointsOnElement::Remove, "Remove one item", py::arg("thePosition"));
	cls_HatchGen_PointsOnElement.def("Remove", (void (HatchGen_PointsOnElement::*)(const Standard_Integer)) &HatchGen_PointsOnElement::Remove, "Remove one item", py::arg("theIndex"));
	cls_HatchGen_PointsOnElement.def("Remove", (void (HatchGen_PointsOnElement::*)(const Standard_Integer, const Standard_Integer)) &HatchGen_PointsOnElement::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_HatchGen_PointsOnElement.def("Append", (void (HatchGen_PointsOnElement::*)(const HatchGen_PointOnElement &)) &HatchGen_PointsOnElement::Append, "Append one item", py::arg("theItem"));
	cls_HatchGen_PointsOnElement.def("Append", (void (HatchGen_PointsOnElement::*)(HatchGen_PointsOnElement &)) &HatchGen_PointsOnElement::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_HatchGen_PointsOnElement.def("Prepend", (void (HatchGen_PointsOnElement::*)(const HatchGen_PointOnElement &)) &HatchGen_PointsOnElement::Prepend, "Prepend one item", py::arg("theItem"));
	cls_HatchGen_PointsOnElement.def("Prepend", (void (HatchGen_PointsOnElement::*)(HatchGen_PointsOnElement &)) &HatchGen_PointsOnElement::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_HatchGen_PointsOnElement.def("InsertBefore", (void (HatchGen_PointsOnElement::*)(const Standard_Integer, const HatchGen_PointOnElement &)) &HatchGen_PointsOnElement::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_HatchGen_PointsOnElement.def("InsertBefore", (void (HatchGen_PointsOnElement::*)(const Standard_Integer, HatchGen_PointsOnElement &)) &HatchGen_PointsOnElement::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_HatchGen_PointsOnElement.def("InsertAfter", (void (HatchGen_PointsOnElement::*)(HatchGen_PointsOnElement::Iterator &, const HatchGen_PointOnElement &)) &HatchGen_PointsOnElement::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_HatchGen_PointsOnElement.def("InsertAfter", (void (HatchGen_PointsOnElement::*)(const Standard_Integer, HatchGen_PointsOnElement &)) &HatchGen_PointsOnElement::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_HatchGen_PointsOnElement.def("InsertAfter", (void (HatchGen_PointsOnElement::*)(const Standard_Integer, const HatchGen_PointOnElement &)) &HatchGen_PointsOnElement::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_HatchGen_PointsOnElement.def("Split", (void (HatchGen_PointsOnElement::*)(const Standard_Integer, HatchGen_PointsOnElement &)) &HatchGen_PointsOnElement::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_HatchGen_PointsOnElement.def("First", (const HatchGen_PointOnElement & (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::First, "First item access");
	cls_HatchGen_PointsOnElement.def("ChangeFirst", (HatchGen_PointOnElement & (HatchGen_PointsOnElement::*)()) &HatchGen_PointsOnElement::ChangeFirst, "First item access");
	cls_HatchGen_PointsOnElement.def("Last", (const HatchGen_PointOnElement & (HatchGen_PointsOnElement::*)() const ) &HatchGen_PointsOnElement::Last, "Last item access");
	cls_HatchGen_PointsOnElement.def("ChangeLast", (HatchGen_PointOnElement & (HatchGen_PointsOnElement::*)()) &HatchGen_PointsOnElement::ChangeLast, "Last item access");
	cls_HatchGen_PointsOnElement.def("Value", (const HatchGen_PointOnElement & (HatchGen_PointsOnElement::*)(const Standard_Integer) const ) &HatchGen_PointsOnElement::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_HatchGen_PointsOnElement.def("__call__", (const HatchGen_PointOnElement & (HatchGen_PointsOnElement::*)(const Standard_Integer) const ) &HatchGen_PointsOnElement::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_HatchGen_PointsOnElement.def("ChangeValue", (HatchGen_PointOnElement & (HatchGen_PointsOnElement::*)(const Standard_Integer)) &HatchGen_PointsOnElement::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_HatchGen_PointsOnElement.def("__call__", (HatchGen_PointOnElement & (HatchGen_PointsOnElement::*)(const Standard_Integer)) &HatchGen_PointsOnElement::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_HatchGen_PointsOnElement.def("SetValue", (void (HatchGen_PointsOnElement::*)(const Standard_Integer, const HatchGen_PointOnElement &)) &HatchGen_PointsOnElement::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_HatchGen_PointsOnElement.def("__iter__", [](const HatchGen_PointsOnElement &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<HatchGen_PointsOnHatching, std::unique_ptr<HatchGen_PointsOnHatching, Deleter<HatchGen_PointsOnHatching>>, NCollection_BaseSequence> cls_HatchGen_PointsOnHatching(mod, "HatchGen_PointsOnHatching", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_HatchGen_PointsOnHatching.def(py::init<>());
	cls_HatchGen_PointsOnHatching.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_HatchGen_PointsOnHatching.def(py::init([] (const HatchGen_PointsOnHatching &other) {return new HatchGen_PointsOnHatching(other);}), "Copy constructor", py::arg("other"));
	cls_HatchGen_PointsOnHatching.def("begin", (HatchGen_PointsOnHatching::iterator (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_HatchGen_PointsOnHatching.def("end", (HatchGen_PointsOnHatching::iterator (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_HatchGen_PointsOnHatching.def("cbegin", (HatchGen_PointsOnHatching::const_iterator (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_HatchGen_PointsOnHatching.def("cend", (HatchGen_PointsOnHatching::const_iterator (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_HatchGen_PointsOnHatching.def("Size", (Standard_Integer (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::Size, "Number of items");
	cls_HatchGen_PointsOnHatching.def("Length", (Standard_Integer (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::Length, "Number of items");
	cls_HatchGen_PointsOnHatching.def("Lower", (Standard_Integer (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::Lower, "Method for consistency with other collections.");
	cls_HatchGen_PointsOnHatching.def("Upper", (Standard_Integer (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::Upper, "Method for consistency with other collections.");
	cls_HatchGen_PointsOnHatching.def("IsEmpty", (Standard_Boolean (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::IsEmpty, "Empty query");
	cls_HatchGen_PointsOnHatching.def("Reverse", (void (HatchGen_PointsOnHatching::*)()) &HatchGen_PointsOnHatching::Reverse, "Reverse sequence");
	cls_HatchGen_PointsOnHatching.def("Exchange", (void (HatchGen_PointsOnHatching::*)(const Standard_Integer, const Standard_Integer)) &HatchGen_PointsOnHatching::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_HatchGen_PointsOnHatching.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &HatchGen_PointsOnHatching::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_HatchGen_PointsOnHatching.def("Clear", [](HatchGen_PointsOnHatching &self) -> void { return self.Clear(); });
	cls_HatchGen_PointsOnHatching.def("Clear", (void (HatchGen_PointsOnHatching::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &HatchGen_PointsOnHatching::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_HatchGen_PointsOnHatching.def("Assign", (HatchGen_PointsOnHatching & (HatchGen_PointsOnHatching::*)(const HatchGen_PointsOnHatching &)) &HatchGen_PointsOnHatching::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_HatchGen_PointsOnHatching.def("assign", (HatchGen_PointsOnHatching & (HatchGen_PointsOnHatching::*)(const HatchGen_PointsOnHatching &)) &HatchGen_PointsOnHatching::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_HatchGen_PointsOnHatching.def("Remove", (void (HatchGen_PointsOnHatching::*)(HatchGen_PointsOnHatching::Iterator &)) &HatchGen_PointsOnHatching::Remove, "Remove one item", py::arg("thePosition"));
	cls_HatchGen_PointsOnHatching.def("Remove", (void (HatchGen_PointsOnHatching::*)(const Standard_Integer)) &HatchGen_PointsOnHatching::Remove, "Remove one item", py::arg("theIndex"));
	cls_HatchGen_PointsOnHatching.def("Remove", (void (HatchGen_PointsOnHatching::*)(const Standard_Integer, const Standard_Integer)) &HatchGen_PointsOnHatching::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_HatchGen_PointsOnHatching.def("Append", (void (HatchGen_PointsOnHatching::*)(const HatchGen_PointOnHatching &)) &HatchGen_PointsOnHatching::Append, "Append one item", py::arg("theItem"));
	cls_HatchGen_PointsOnHatching.def("Append", (void (HatchGen_PointsOnHatching::*)(HatchGen_PointsOnHatching &)) &HatchGen_PointsOnHatching::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_HatchGen_PointsOnHatching.def("Prepend", (void (HatchGen_PointsOnHatching::*)(const HatchGen_PointOnHatching &)) &HatchGen_PointsOnHatching::Prepend, "Prepend one item", py::arg("theItem"));
	cls_HatchGen_PointsOnHatching.def("Prepend", (void (HatchGen_PointsOnHatching::*)(HatchGen_PointsOnHatching &)) &HatchGen_PointsOnHatching::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_HatchGen_PointsOnHatching.def("InsertBefore", (void (HatchGen_PointsOnHatching::*)(const Standard_Integer, const HatchGen_PointOnHatching &)) &HatchGen_PointsOnHatching::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_HatchGen_PointsOnHatching.def("InsertBefore", (void (HatchGen_PointsOnHatching::*)(const Standard_Integer, HatchGen_PointsOnHatching &)) &HatchGen_PointsOnHatching::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_HatchGen_PointsOnHatching.def("InsertAfter", (void (HatchGen_PointsOnHatching::*)(HatchGen_PointsOnHatching::Iterator &, const HatchGen_PointOnHatching &)) &HatchGen_PointsOnHatching::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_HatchGen_PointsOnHatching.def("InsertAfter", (void (HatchGen_PointsOnHatching::*)(const Standard_Integer, HatchGen_PointsOnHatching &)) &HatchGen_PointsOnHatching::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_HatchGen_PointsOnHatching.def("InsertAfter", (void (HatchGen_PointsOnHatching::*)(const Standard_Integer, const HatchGen_PointOnHatching &)) &HatchGen_PointsOnHatching::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_HatchGen_PointsOnHatching.def("Split", (void (HatchGen_PointsOnHatching::*)(const Standard_Integer, HatchGen_PointsOnHatching &)) &HatchGen_PointsOnHatching::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_HatchGen_PointsOnHatching.def("First", (const HatchGen_PointOnHatching & (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::First, "First item access");
	cls_HatchGen_PointsOnHatching.def("ChangeFirst", (HatchGen_PointOnHatching & (HatchGen_PointsOnHatching::*)()) &HatchGen_PointsOnHatching::ChangeFirst, "First item access");
	cls_HatchGen_PointsOnHatching.def("Last", (const HatchGen_PointOnHatching & (HatchGen_PointsOnHatching::*)() const ) &HatchGen_PointsOnHatching::Last, "Last item access");
	cls_HatchGen_PointsOnHatching.def("ChangeLast", (HatchGen_PointOnHatching & (HatchGen_PointsOnHatching::*)()) &HatchGen_PointsOnHatching::ChangeLast, "Last item access");
	cls_HatchGen_PointsOnHatching.def("Value", (const HatchGen_PointOnHatching & (HatchGen_PointsOnHatching::*)(const Standard_Integer) const ) &HatchGen_PointsOnHatching::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_HatchGen_PointsOnHatching.def("__call__", (const HatchGen_PointOnHatching & (HatchGen_PointsOnHatching::*)(const Standard_Integer) const ) &HatchGen_PointsOnHatching::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_HatchGen_PointsOnHatching.def("ChangeValue", (HatchGen_PointOnHatching & (HatchGen_PointsOnHatching::*)(const Standard_Integer)) &HatchGen_PointsOnHatching::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_HatchGen_PointsOnHatching.def("__call__", (HatchGen_PointOnHatching & (HatchGen_PointsOnHatching::*)(const Standard_Integer)) &HatchGen_PointsOnHatching::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_HatchGen_PointsOnHatching.def("SetValue", (void (HatchGen_PointsOnHatching::*)(const Standard_Integer, const HatchGen_PointOnHatching &)) &HatchGen_PointsOnHatching::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_HatchGen_PointsOnHatching.def("__iter__", [](const HatchGen_PointsOnHatching &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<HatchGen_Domains, std::unique_ptr<HatchGen_Domains, Deleter<HatchGen_Domains>>, NCollection_BaseSequence> cls_HatchGen_Domains(mod, "HatchGen_Domains", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_HatchGen_Domains.def(py::init<>());
	cls_HatchGen_Domains.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_HatchGen_Domains.def(py::init([] (const HatchGen_Domains &other) {return new HatchGen_Domains(other);}), "Copy constructor", py::arg("other"));
	cls_HatchGen_Domains.def("begin", (HatchGen_Domains::iterator (HatchGen_Domains::*)() const ) &HatchGen_Domains::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_HatchGen_Domains.def("end", (HatchGen_Domains::iterator (HatchGen_Domains::*)() const ) &HatchGen_Domains::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_HatchGen_Domains.def("cbegin", (HatchGen_Domains::const_iterator (HatchGen_Domains::*)() const ) &HatchGen_Domains::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_HatchGen_Domains.def("cend", (HatchGen_Domains::const_iterator (HatchGen_Domains::*)() const ) &HatchGen_Domains::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_HatchGen_Domains.def("Size", (Standard_Integer (HatchGen_Domains::*)() const ) &HatchGen_Domains::Size, "Number of items");
	cls_HatchGen_Domains.def("Length", (Standard_Integer (HatchGen_Domains::*)() const ) &HatchGen_Domains::Length, "Number of items");
	cls_HatchGen_Domains.def("Lower", (Standard_Integer (HatchGen_Domains::*)() const ) &HatchGen_Domains::Lower, "Method for consistency with other collections.");
	cls_HatchGen_Domains.def("Upper", (Standard_Integer (HatchGen_Domains::*)() const ) &HatchGen_Domains::Upper, "Method for consistency with other collections.");
	cls_HatchGen_Domains.def("IsEmpty", (Standard_Boolean (HatchGen_Domains::*)() const ) &HatchGen_Domains::IsEmpty, "Empty query");
	cls_HatchGen_Domains.def("Reverse", (void (HatchGen_Domains::*)()) &HatchGen_Domains::Reverse, "Reverse sequence");
	cls_HatchGen_Domains.def("Exchange", (void (HatchGen_Domains::*)(const Standard_Integer, const Standard_Integer)) &HatchGen_Domains::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_HatchGen_Domains.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &HatchGen_Domains::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_HatchGen_Domains.def("Clear", [](HatchGen_Domains &self) -> void { return self.Clear(); });
	cls_HatchGen_Domains.def("Clear", (void (HatchGen_Domains::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &HatchGen_Domains::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_HatchGen_Domains.def("Assign", (HatchGen_Domains & (HatchGen_Domains::*)(const HatchGen_Domains &)) &HatchGen_Domains::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_HatchGen_Domains.def("assign", (HatchGen_Domains & (HatchGen_Domains::*)(const HatchGen_Domains &)) &HatchGen_Domains::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_HatchGen_Domains.def("Remove", (void (HatchGen_Domains::*)(HatchGen_Domains::Iterator &)) &HatchGen_Domains::Remove, "Remove one item", py::arg("thePosition"));
	cls_HatchGen_Domains.def("Remove", (void (HatchGen_Domains::*)(const Standard_Integer)) &HatchGen_Domains::Remove, "Remove one item", py::arg("theIndex"));
	cls_HatchGen_Domains.def("Remove", (void (HatchGen_Domains::*)(const Standard_Integer, const Standard_Integer)) &HatchGen_Domains::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_HatchGen_Domains.def("Append", (void (HatchGen_Domains::*)(const HatchGen_Domain &)) &HatchGen_Domains::Append, "Append one item", py::arg("theItem"));
	cls_HatchGen_Domains.def("Append", (void (HatchGen_Domains::*)(HatchGen_Domains &)) &HatchGen_Domains::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_HatchGen_Domains.def("Prepend", (void (HatchGen_Domains::*)(const HatchGen_Domain &)) &HatchGen_Domains::Prepend, "Prepend one item", py::arg("theItem"));
	cls_HatchGen_Domains.def("Prepend", (void (HatchGen_Domains::*)(HatchGen_Domains &)) &HatchGen_Domains::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_HatchGen_Domains.def("InsertBefore", (void (HatchGen_Domains::*)(const Standard_Integer, const HatchGen_Domain &)) &HatchGen_Domains::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_HatchGen_Domains.def("InsertBefore", (void (HatchGen_Domains::*)(const Standard_Integer, HatchGen_Domains &)) &HatchGen_Domains::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_HatchGen_Domains.def("InsertAfter", (void (HatchGen_Domains::*)(HatchGen_Domains::Iterator &, const HatchGen_Domain &)) &HatchGen_Domains::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_HatchGen_Domains.def("InsertAfter", (void (HatchGen_Domains::*)(const Standard_Integer, HatchGen_Domains &)) &HatchGen_Domains::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_HatchGen_Domains.def("InsertAfter", (void (HatchGen_Domains::*)(const Standard_Integer, const HatchGen_Domain &)) &HatchGen_Domains::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_HatchGen_Domains.def("Split", (void (HatchGen_Domains::*)(const Standard_Integer, HatchGen_Domains &)) &HatchGen_Domains::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_HatchGen_Domains.def("First", (const HatchGen_Domain & (HatchGen_Domains::*)() const ) &HatchGen_Domains::First, "First item access");
	cls_HatchGen_Domains.def("ChangeFirst", (HatchGen_Domain & (HatchGen_Domains::*)()) &HatchGen_Domains::ChangeFirst, "First item access");
	cls_HatchGen_Domains.def("Last", (const HatchGen_Domain & (HatchGen_Domains::*)() const ) &HatchGen_Domains::Last, "Last item access");
	cls_HatchGen_Domains.def("ChangeLast", (HatchGen_Domain & (HatchGen_Domains::*)()) &HatchGen_Domains::ChangeLast, "Last item access");
	cls_HatchGen_Domains.def("Value", (const HatchGen_Domain & (HatchGen_Domains::*)(const Standard_Integer) const ) &HatchGen_Domains::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_HatchGen_Domains.def("__call__", (const HatchGen_Domain & (HatchGen_Domains::*)(const Standard_Integer) const ) &HatchGen_Domains::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_HatchGen_Domains.def("ChangeValue", (HatchGen_Domain & (HatchGen_Domains::*)(const Standard_Integer)) &HatchGen_Domains::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_HatchGen_Domains.def("__call__", (HatchGen_Domain & (HatchGen_Domains::*)(const Standard_Integer)) &HatchGen_Domains::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_HatchGen_Domains.def("SetValue", (void (HatchGen_Domains::*)(const Standard_Integer, const HatchGen_Domain &)) &HatchGen_Domains::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_HatchGen_Domains.def("__iter__", [](const HatchGen_Domains &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
