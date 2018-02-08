/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

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
#include <NCollection_Templates.hpp>

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\HatchGen_PointsOnElement.hxx
	bind_NCollection_Sequence<HatchGen_PointOnElement>(mod, "HatchGen_PointsOnElement");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HatchGen_PointsOnHatching.hxx
	bind_NCollection_Sequence<HatchGen_PointOnHatching>(mod, "HatchGen_PointsOnHatching");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HatchGen_Domains.hxx
	bind_NCollection_Sequence<HatchGen_Domain>(mod, "HatchGen_Domains");


}
