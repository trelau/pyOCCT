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
#include <Intrv_Interval.hxx>
#include <Intrv_Intervals.hxx>
#include <Standard_TypeDef.hxx>
#include <Intrv_SequenceOfInterval.hxx>

void bind_Intrv_Intervals(py::module &mod){

py::class_<Intrv_Intervals, std::unique_ptr<Intrv_Intervals, Deleter<Intrv_Intervals>>> cls_Intrv_Intervals(mod, "Intrv_Intervals", "The class Intervals is a sorted sequence of non overlapping Real Intervals.");

// Constructors
cls_Intrv_Intervals.def(py::init<>());
cls_Intrv_Intervals.def(py::init<const Intrv_Interval &>(), py::arg("Int"));
cls_Intrv_Intervals.def(py::init<const Intrv_Intervals &>(), py::arg("Int"));

// Fields

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

// Enums

}