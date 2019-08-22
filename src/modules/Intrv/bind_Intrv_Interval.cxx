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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Intrv_Position.hxx>
#include <Intrv_Interval.hxx>

void bind_Intrv_Interval(py::module &mod){

py::class_<Intrv_Interval> cls_Intrv_Interval(mod, "Intrv_Interval", "**-----------**** Other ***---* IsBefore ***----------* IsJustBefore ***---------------* IsOverlappingAtStart ***------------------------* IsJustEnclosingAtEnd ***-----------------------------------* IsEnclosing ***----* IsJustOverlappingAtStart ***-------------* IsSimilar ***------------------------* IsJustEnclosingAtStart ***-* IsInside ***------* IsJustOverlappingAtEnd ***-----------------* IsOverlappingAtEnd ***--------* IsJustAfter ***---* IsAfter");

// Constructors
cls_Intrv_Interval.def(py::init<>());
cls_Intrv_Interval.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Start"), py::arg("End"));
cls_Intrv_Interval.def(py::init<const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal>(), py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));

// Fields

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

// Enums

}