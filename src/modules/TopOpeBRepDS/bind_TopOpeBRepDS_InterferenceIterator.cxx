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
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_InterferenceIterator.hxx>

void bind_TopOpeBRepDS_InterferenceIterator(py::module &mod){

py::class_<TopOpeBRepDS_InterferenceIterator, std::unique_ptr<TopOpeBRepDS_InterferenceIterator, Deleter<TopOpeBRepDS_InterferenceIterator>>> cls_TopOpeBRepDS_InterferenceIterator(mod, "TopOpeBRepDS_InterferenceIterator", "Iterate on interferences of a list, matching conditions on interferences. Nota : inheritance of ListIteratorOfListOfInterference from TopOpeBRepDS has not been done because of the impossibility of naming the classical More, Next methods which are declared as static in TCollection_ListIteratorOfList ... . ListIteratorOfList has benn placed as a field of InterferenceIterator.");

// Constructors
cls_TopOpeBRepDS_InterferenceIterator.def(py::init<>());
cls_TopOpeBRepDS_InterferenceIterator.def(py::init<const TopOpeBRepDS_ListOfInterference &>(), py::arg("L"));

// Fields

// Methods
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_InterferenceIterator::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_InterferenceIterator::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_InterferenceIterator::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_InterferenceIterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_InterferenceIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_InterferenceIterator.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_InterferenceIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_InterferenceIterator.def("Init", (void (TopOpeBRepDS_InterferenceIterator::*)(const TopOpeBRepDS_ListOfInterference &)) &TopOpeBRepDS_InterferenceIterator::Init, "re-initialize interference iteration process on the list of interference <L>. Conditions are not modified.", py::arg("L"));
cls_TopOpeBRepDS_InterferenceIterator.def("GeometryKind", (void (TopOpeBRepDS_InterferenceIterator::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_InterferenceIterator::GeometryKind, "define a condition on interference iteration process. Interference must match the Geometry Kind <ST>", py::arg("GK"));
cls_TopOpeBRepDS_InterferenceIterator.def("Geometry", (void (TopOpeBRepDS_InterferenceIterator::*)(const Standard_Integer)) &TopOpeBRepDS_InterferenceIterator::Geometry, "define a condition on interference iteration process. Interference must match the Geometry <G>", py::arg("G"));
cls_TopOpeBRepDS_InterferenceIterator.def("SupportKind", (void (TopOpeBRepDS_InterferenceIterator::*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS_InterferenceIterator::SupportKind, "define a condition on interference iteration process. Interference must match the Support Kind <ST>", py::arg("ST"));
cls_TopOpeBRepDS_InterferenceIterator.def("Support", (void (TopOpeBRepDS_InterferenceIterator::*)(const Standard_Integer)) &TopOpeBRepDS_InterferenceIterator::Support, "define a condition on interference iteration process. Interference must match the Support <S>", py::arg("S"));
cls_TopOpeBRepDS_InterferenceIterator.def("Match", (void (TopOpeBRepDS_InterferenceIterator::*)()) &TopOpeBRepDS_InterferenceIterator::Match, "reach for an interference matching the conditions (if defined).");
cls_TopOpeBRepDS_InterferenceIterator.def("MatchInterference", (Standard_Boolean (TopOpeBRepDS_InterferenceIterator::*)(const opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_InterferenceIterator::MatchInterference, "Returns True if the Interference <I> matches the conditions (if defined). If no conditions defined, returns True.", py::arg("I"));
cls_TopOpeBRepDS_InterferenceIterator.def("More", (Standard_Boolean (TopOpeBRepDS_InterferenceIterator::*)() const) &TopOpeBRepDS_InterferenceIterator::More, "Returns True if there is a current Interference in the iteration.");
cls_TopOpeBRepDS_InterferenceIterator.def("Next", (void (TopOpeBRepDS_InterferenceIterator::*)()) &TopOpeBRepDS_InterferenceIterator::Next, "Move to the next Interference.");
cls_TopOpeBRepDS_InterferenceIterator.def("Value", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_InterferenceIterator::*)() const) &TopOpeBRepDS_InterferenceIterator::Value, "Returns the current Interference, matching the conditions (if defined).");
cls_TopOpeBRepDS_InterferenceIterator.def("ChangeIterator", (TopOpeBRepDS_ListIteratorOfListOfInterference & (TopOpeBRepDS_InterferenceIterator::*)()) &TopOpeBRepDS_InterferenceIterator::ChangeIterator, "None");

// Enums

}