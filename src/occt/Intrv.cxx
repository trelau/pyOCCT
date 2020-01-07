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
#include <Intrv_Position.hxx>
#include <Standard_TypeDef.hxx>
#include <Intrv_Interval.hxx>
#include <Standard.hxx>
#include <NCollection_Sequence.hxx>
#include <Intrv_SequenceOfInterval.hxx>
#include <Intrv_Intervals.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(Intrv, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");

// ENUM: INTRV_POSITION
py::enum_<Intrv_Position>(mod, "Intrv_Position", "None")
	.value("Intrv_Before", Intrv_Position::Intrv_Before)
	.value("Intrv_JustBefore", Intrv_Position::Intrv_JustBefore)
	.value("Intrv_OverlappingAtStart", Intrv_Position::Intrv_OverlappingAtStart)
	.value("Intrv_JustEnclosingAtEnd", Intrv_Position::Intrv_JustEnclosingAtEnd)
	.value("Intrv_Enclosing", Intrv_Position::Intrv_Enclosing)
	.value("Intrv_JustOverlappingAtStart", Intrv_Position::Intrv_JustOverlappingAtStart)
	.value("Intrv_Similar", Intrv_Position::Intrv_Similar)
	.value("Intrv_JustEnclosingAtStart", Intrv_Position::Intrv_JustEnclosingAtStart)
	.value("Intrv_Inside", Intrv_Position::Intrv_Inside)
	.value("Intrv_JustOverlappingAtEnd", Intrv_Position::Intrv_JustOverlappingAtEnd)
	.value("Intrv_OverlappingAtEnd", Intrv_Position::Intrv_OverlappingAtEnd)
	.value("Intrv_JustAfter", Intrv_Position::Intrv_JustAfter)
	.value("Intrv_After", Intrv_Position::Intrv_After)
	.export_values();


// FUNCTION: AREFUSED
mod.def("AreFused", (Standard_Boolean (*) (const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal)) &AreFused, "None", py::arg("c1"), py::arg("t1"), py::arg("c2"), py::arg("t2"));

// CLASS: INTRV_INTERVAL
py::class_<Intrv_Interval> cls_Intrv_Interval(mod, "Intrv_Interval", "**-----------**** Other ***---* IsBefore ***----------* IsJustBefore ***---------------* IsOverlappingAtStart ***------------------------* IsJustEnclosingAtEnd ***-----------------------------------* IsEnclosing ***----* IsJustOverlappingAtStart ***-------------* IsSimilar ***------------------------* IsJustEnclosingAtStart ***-* IsInside ***------* IsJustOverlappingAtEnd ***-----------------* IsOverlappingAtEnd ***--------* IsJustAfter ***---* IsAfter");

// Constructors
cls_Intrv_Interval.def(py::init<>());
cls_Intrv_Interval.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Start"), py::arg("End"));
cls_Intrv_Interval.def(py::init<const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal>(), py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));

// Methods
// cls_Intrv_Interval.def_static("operator new_", (void * (*)(size_t)) &Intrv_Interval::operator new, "None", py::arg("theSize"));
// cls_Intrv_Interval.def_static("operator delete_", (void (*)(void *)) &Intrv_Interval::operator delete, "None", py::arg("theAddress"));
// cls_Intrv_Interval.def_static("operator new[]_", (void * (*)(size_t)) &Intrv_Interval::operator new[], "None", py::arg("theSize"));
// cls_Intrv_Interval.def_static("operator delete[]_", (void (*)(void *)) &Intrv_Interval::operator delete[], "None", py::arg("theAddress"));
// cls_Intrv_Interval.def_static("operator new_", (void * (*)(size_t, void *)) &Intrv_Interval::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Intrv_Interval.def_static("operator delete_", (void (*)(void *, void *)) &Intrv_Interval::operator delete, "None", py::arg(""), py::arg(""));
cls_Intrv_Interval.def("Start", (Standard_Real (Intrv_Interval::*)() const) &Intrv_Interval::Start, "None");
cls_Intrv_Interval.def("End", (Standard_Real (Intrv_Interval::*)() const) &Intrv_Interval::End, "None");
cls_Intrv_Interval.def("TolStart", (Standard_ShortReal (Intrv_Interval::*)() const) &Intrv_Interval::TolStart, "None");
cls_Intrv_Interval.def("TolEnd", (Standard_ShortReal (Intrv_Interval::*)() const) &Intrv_Interval::TolEnd, "None");
cls_Intrv_Interval.def("Bounds", [](Intrv_Interval &self, Standard_Real & Start, Standard_ShortReal & TolStart, Standard_Real & End, Standard_ShortReal & TolEnd){ self.Bounds(Start, TolStart, End, TolEnd); return std::tuple<Standard_Real &, Standard_Real &>(Start, End); }, "None", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
cls_Intrv_Interval.def("SetStart", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::SetStart, "None", py::arg("Start"), py::arg("TolStart"));
cls_Intrv_Interval.def("FuseAtStart", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::FuseAtStart, "****+****--------------------> Old one ****+****------------------------> New one to fuse <<< <<< ****+****------------------------> result", py::arg("Start"), py::arg("TolStart"));
cls_Intrv_Interval.def("CutAtStart", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::CutAtStart, "****+****-----------> Old one <----------**+** Tool for cutting >>> >>> ****+****-----------> result", py::arg("Start"), py::arg("TolStart"));
cls_Intrv_Interval.def("SetEnd", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::SetEnd, "None", py::arg("End"), py::arg("TolEnd"));
cls_Intrv_Interval.def("FuseAtEnd", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::FuseAtEnd, "<---------------------****+**** Old one <-----------------**+** New one to fuse >>> >>> <---------------------****+**** result", py::arg("End"), py::arg("TolEnd"));
cls_Intrv_Interval.def("CutAtEnd", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::CutAtEnd, "<-----****+**** Old one **+**------> Tool for cutting <<< <<< <-----****+**** result", py::arg("End"), py::arg("TolEnd"));
cls_Intrv_Interval.def("IsProbablyEmpty", (Standard_Boolean (Intrv_Interval::*)() const) &Intrv_Interval::IsProbablyEmpty, "True if myStart+myTolStart > myEnd-myTolEnd or if myEnd+myTolEnd > myStart-myTolStart");
cls_Intrv_Interval.def("Position", (Intrv_Position (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::Position, "True if me is Before Other **-----------**** Other ***-----* Before ***------------* JustBefore ***-----------------* OverlappingAtStart ***--------------------------* JustEnclosingAtEnd ***-------------------------------------* Enclosing ***----* JustOverlappingAtStart ***-------------* Similar ***------------------------* JustEnclosingAtStart ***-* Inside ***------* JustOverlappingAtEnd ***-----------------* OverlappingAtEnd ***--------* JustAfter ***---* After", py::arg("Other"));
cls_Intrv_Interval.def("IsBefore", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsBefore, "True if me is Before Other ***----------------** me **-----------**** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsAfter", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsAfter, "True if me is After Other **-----------**** me ***----------------** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsInside", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsInside, "True if me is Inside Other **-----------**** me ***--------------------------** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsEnclosing", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsEnclosing, "True if me is Enclosing Other ***----------------------------**** me ***------------------** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsJustEnclosingAtStart", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsJustEnclosingAtStart, "True if me is just Enclosing Other at start ***---------------------------**** me ***------------------** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsJustEnclosingAtEnd", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsJustEnclosingAtEnd, "True if me is just Enclosing Other at End ***----------------------------**** me ***-----------------**** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsJustBefore", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsJustBefore, "True if me is just before Other ***--------**** me ***-----------** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsJustAfter", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsJustAfter, "True if me is just after Other ****-------**** me ***-----------** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsOverlappingAtStart", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsOverlappingAtStart, "True if me is overlapping Other at start ***---------------*** me ***-----------** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsOverlappingAtEnd", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsOverlappingAtEnd, "True if me is overlapping Other at end ***-----------** me ***---------------*** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsJustOverlappingAtStart", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsJustOverlappingAtStart, "True if me is just overlapping Other at start ***-----------*** me ***------------------------** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsJustOverlappingAtEnd", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsJustOverlappingAtEnd, "True if me is just overlapping Other at end ***-----------* me ***------------------------** Other", py::arg("Other"));
cls_Intrv_Interval.def("IsSimilar", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const) &Intrv_Interval::IsSimilar, "True if me and Other have the same bounds *----------------*** me ***-----------------** Other", py::arg("Other"));

// TYPEDEF: INTRV_SEQUENCEOFINTERVAL
bind_NCollection_Sequence<Intrv_Interval>(mod, "Intrv_SequenceOfInterval", py::module_local(false));

// CLASS: INTRV_INTERVALS
py::class_<Intrv_Intervals> cls_Intrv_Intervals(mod, "Intrv_Intervals", "The class Intervals is a sorted sequence of non overlapping Real Intervals.");

// Constructors
cls_Intrv_Intervals.def(py::init<>());
cls_Intrv_Intervals.def(py::init<const Intrv_Interval &>(), py::arg("Int"));
cls_Intrv_Intervals.def(py::init<const Intrv_Intervals &>(), py::arg("Int"));

// Methods
// cls_Intrv_Intervals.def_static("operator new_", (void * (*)(size_t)) &Intrv_Intervals::operator new, "None", py::arg("theSize"));
// cls_Intrv_Intervals.def_static("operator delete_", (void (*)(void *)) &Intrv_Intervals::operator delete, "None", py::arg("theAddress"));
// cls_Intrv_Intervals.def_static("operator new[]_", (void * (*)(size_t)) &Intrv_Intervals::operator new[], "None", py::arg("theSize"));
// cls_Intrv_Intervals.def_static("operator delete[]_", (void (*)(void *)) &Intrv_Intervals::operator delete[], "None", py::arg("theAddress"));
// cls_Intrv_Intervals.def_static("operator new_", (void * (*)(size_t, void *)) &Intrv_Intervals::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Intrv_Intervals.def_static("operator delete_", (void (*)(void *, void *)) &Intrv_Intervals::operator delete, "None", py::arg(""), py::arg(""));
cls_Intrv_Intervals.def("Intersect", (void (Intrv_Intervals::*)(const Intrv_Interval &)) &Intrv_Intervals::Intersect, "Intersects the intervals with the interval <Tool>.", py::arg("Tool"));
cls_Intrv_Intervals.def("Intersect", (void (Intrv_Intervals::*)(const Intrv_Intervals &)) &Intrv_Intervals::Intersect, "Intersects the intervals with the intervals in the sequence <Tool>.", py::arg("Tool"));
cls_Intrv_Intervals.def("Subtract", (void (Intrv_Intervals::*)(const Intrv_Interval &)) &Intrv_Intervals::Subtract, "None", py::arg("Tool"));
cls_Intrv_Intervals.def("Subtract", (void (Intrv_Intervals::*)(const Intrv_Intervals &)) &Intrv_Intervals::Subtract, "None", py::arg("Tool"));
cls_Intrv_Intervals.def("Unite", (void (Intrv_Intervals::*)(const Intrv_Interval &)) &Intrv_Intervals::Unite, "None", py::arg("Tool"));
cls_Intrv_Intervals.def("Unite", (void (Intrv_Intervals::*)(const Intrv_Intervals &)) &Intrv_Intervals::Unite, "None", py::arg("Tool"));
cls_Intrv_Intervals.def("XUnite", (void (Intrv_Intervals::*)(const Intrv_Interval &)) &Intrv_Intervals::XUnite, "None", py::arg("Tool"));
cls_Intrv_Intervals.def("XUnite", (void (Intrv_Intervals::*)(const Intrv_Intervals &)) &Intrv_Intervals::XUnite, "None", py::arg("Tool"));
cls_Intrv_Intervals.def("NbIntervals", (Standard_Integer (Intrv_Intervals::*)() const) &Intrv_Intervals::NbIntervals, "None");
cls_Intrv_Intervals.def("Value", (const Intrv_Interval & (Intrv_Intervals::*)(const Standard_Integer) const) &Intrv_Intervals::Value, "None", py::arg("Index"));


}
