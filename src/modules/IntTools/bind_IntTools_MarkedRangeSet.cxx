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
#include <IntTools_CArray1OfReal.hxx>
#include <IntTools_Range.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <IntTools_MarkedRangeSet.hxx>

void bind_IntTools_MarkedRangeSet(py::module &mod){

py::class_<IntTools_MarkedRangeSet, std::unique_ptr<IntTools_MarkedRangeSet>> cls_IntTools_MarkedRangeSet(mod, "IntTools_MarkedRangeSet", "class MarkedRangeSet provides continuous set of ranges marked with flags");

// Constructors
cls_IntTools_MarkedRangeSet.def(py::init<>());
cls_IntTools_MarkedRangeSet.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theInitFlag"));
cls_IntTools_MarkedRangeSet.def(py::init<const IntTools_CArray1OfReal &, const Standard_Integer>(), py::arg("theSortedArray"), py::arg("theInitFlag"));

// Fields

// Methods
// cls_IntTools_MarkedRangeSet.def_static("operator new_", (void * (*)(size_t)) &IntTools_MarkedRangeSet::operator new, "None", py::arg("theSize"));
// cls_IntTools_MarkedRangeSet.def_static("operator delete_", (void (*)(void *)) &IntTools_MarkedRangeSet::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_MarkedRangeSet.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_MarkedRangeSet::operator new[], "None", py::arg("theSize"));
// cls_IntTools_MarkedRangeSet.def_static("operator delete[]_", (void (*)(void *)) &IntTools_MarkedRangeSet::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_MarkedRangeSet.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_MarkedRangeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_MarkedRangeSet.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_MarkedRangeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_MarkedRangeSet.def("SetBoundaries", (void (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &IntTools_MarkedRangeSet::SetBoundaries, "build set of ranges which consists of one range with boundary values theFirstBoundary and theLastBoundary", py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theInitFlag"));
cls_IntTools_MarkedRangeSet.def("SetRanges", (void (IntTools_MarkedRangeSet::*)(const IntTools_CArray1OfReal &, const Standard_Integer)) &IntTools_MarkedRangeSet::SetRanges, "Build set of ranges based on the array of progressive sorted values", py::arg("theSortedArray"), py::arg("theInitFlag"));
cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theFlag"));
cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const IntTools_Range &, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theRange"), py::arg("theFlag"));
cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. The index theIndex is a position where the range will be inserted. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theFirstBoundary"), py::arg("theLastBoundary"), py::arg("theFlag"), py::arg("theIndex"));
cls_IntTools_MarkedRangeSet.def("InsertRange", (Standard_Boolean (IntTools_MarkedRangeSet::*)(const IntTools_Range &, const Standard_Integer, const Standard_Integer)) &IntTools_MarkedRangeSet::InsertRange, "Inserts a new range marked with flag theFlag It replace the existing ranges or parts of ranges and their flags. The index theIndex is a position where the range will be inserted. Returns True if the range is inside the initial boundaries, otherwise or in case of some error returns False", py::arg("theRange"), py::arg("theFlag"), py::arg("theIndex"));
cls_IntTools_MarkedRangeSet.def("SetFlag", (void (IntTools_MarkedRangeSet::*)(const Standard_Integer, const Standard_Integer)) &IntTools_MarkedRangeSet::SetFlag, "Set flag theFlag for range with index theIndex", py::arg("theIndex"), py::arg("theFlag"));
cls_IntTools_MarkedRangeSet.def("Flag", (Standard_Integer (IntTools_MarkedRangeSet::*)(const Standard_Integer) const) &IntTools_MarkedRangeSet::Flag, "Returns flag of the range with index theIndex", py::arg("theIndex"));
cls_IntTools_MarkedRangeSet.def("GetIndex", (Standard_Integer (IntTools_MarkedRangeSet::*)(const Standard_Real) const) &IntTools_MarkedRangeSet::GetIndex, "Returns index of range which contains theValue. If theValue do not belong any range returns 0.", py::arg("theValue"));
cls_IntTools_MarkedRangeSet.def("GetIndices", (const TColStd_SequenceOfInteger & (IntTools_MarkedRangeSet::*)(const Standard_Real)) &IntTools_MarkedRangeSet::GetIndices, "None", py::arg("theValue"));
cls_IntTools_MarkedRangeSet.def("GetIndex", (Standard_Integer (IntTools_MarkedRangeSet::*)(const Standard_Real, const Standard_Boolean) const) &IntTools_MarkedRangeSet::GetIndex, "Returns index of range which contains theValue If theValue do not belong any range returns 0. If UseLower is Standard_True then lower boundary of the range can be equal to theValue, otherwise upper boundary of the range can be equal to theValue.", py::arg("theValue"), py::arg("UseLower"));
cls_IntTools_MarkedRangeSet.def("Length", (Standard_Integer (IntTools_MarkedRangeSet::*)() const) &IntTools_MarkedRangeSet::Length, "Returns number of ranges");
cls_IntTools_MarkedRangeSet.def("Range", (IntTools_Range (IntTools_MarkedRangeSet::*)(const Standard_Integer) const) &IntTools_MarkedRangeSet::Range, "Returns the range with index theIndex. the Index can be from 1 to Length()", py::arg("theIndex"));

// Enums

}