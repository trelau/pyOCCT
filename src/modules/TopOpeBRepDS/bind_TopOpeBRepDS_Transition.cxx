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
#include <TopAbs_State.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Transition.hxx>

void bind_TopOpeBRepDS_Transition(py::module &mod){

py::class_<TopOpeBRepDS_Transition, std::unique_ptr<TopOpeBRepDS_Transition, Deleter<TopOpeBRepDS_Transition>>> cls_TopOpeBRepDS_Transition(mod, "TopOpeBRepDS_Transition", "None");

// Constructors
cls_TopOpeBRepDS_Transition.def(py::init<>());
cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_State, const TopAbs_State>(), py::arg("StateBefore"), py::arg("StateAfter"));
cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_State, const TopAbs_State, const TopAbs_ShapeEnum>(), py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"));
cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_State, const TopAbs_State, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum>(), py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"), py::arg("ShapeAfter"));
cls_TopOpeBRepDS_Transition.def(py::init<const TopAbs_Orientation>(), py::arg("O"));

// Fields

// Methods
// cls_TopOpeBRepDS_Transition.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Transition::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Transition.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Transition::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Transition.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Transition::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Transition.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Transition::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Transition.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Transition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Transition.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Transition::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Transition.def("Set", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0, const TopAbs_State a1) -> void { return self.Set(a0, a1); });
cls_TopOpeBRepDS_Transition.def("Set", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0, const TopAbs_State a1, const TopAbs_ShapeEnum a2) -> void { return self.Set(a0, a1, a2); });
cls_TopOpeBRepDS_Transition.def("Set", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_State, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::Set, "None", py::arg("StateBefore"), py::arg("StateAfter"), py::arg("ShapeBefore"), py::arg("ShapeAfter"));
cls_TopOpeBRepDS_Transition.def("StateBefore", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State)) &TopOpeBRepDS_Transition::StateBefore, "None", py::arg("S"));
cls_TopOpeBRepDS_Transition.def("StateAfter", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State)) &TopOpeBRepDS_Transition::StateAfter, "None", py::arg("S"));
cls_TopOpeBRepDS_Transition.def("ShapeBefore", (void (TopOpeBRepDS_Transition::*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::ShapeBefore, "None", py::arg("SE"));
cls_TopOpeBRepDS_Transition.def("ShapeAfter", (void (TopOpeBRepDS_Transition::*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::ShapeAfter, "None", py::arg("SE"));
cls_TopOpeBRepDS_Transition.def("Before", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0) -> void { return self.Before(a0); });
cls_TopOpeBRepDS_Transition.def("Before", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::Before, "None", py::arg("S"), py::arg("ShapeBefore"));
cls_TopOpeBRepDS_Transition.def("After", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0) -> void { return self.After(a0); });
cls_TopOpeBRepDS_Transition.def("After", (void (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_ShapeEnum)) &TopOpeBRepDS_Transition::After, "None", py::arg("S"), py::arg("ShapeAfter"));
cls_TopOpeBRepDS_Transition.def("Index", (void (TopOpeBRepDS_Transition::*)(const Standard_Integer)) &TopOpeBRepDS_Transition::Index, "None", py::arg("I"));
cls_TopOpeBRepDS_Transition.def("IndexBefore", (void (TopOpeBRepDS_Transition::*)(const Standard_Integer)) &TopOpeBRepDS_Transition::IndexBefore, "None", py::arg("I"));
cls_TopOpeBRepDS_Transition.def("IndexAfter", (void (TopOpeBRepDS_Transition::*)(const Standard_Integer)) &TopOpeBRepDS_Transition::IndexAfter, "None", py::arg("I"));
cls_TopOpeBRepDS_Transition.def("Before", (TopAbs_State (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::Before, "None");
cls_TopOpeBRepDS_Transition.def("ONBefore", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::ONBefore, "None");
cls_TopOpeBRepDS_Transition.def("After", (TopAbs_State (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::After, "None");
cls_TopOpeBRepDS_Transition.def("ONAfter", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::ONAfter, "None");
cls_TopOpeBRepDS_Transition.def("ShapeBefore", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::ShapeBefore, "None");
cls_TopOpeBRepDS_Transition.def("ShapeAfter", (TopAbs_ShapeEnum (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::ShapeAfter, "None");
cls_TopOpeBRepDS_Transition.def("Index", (Standard_Integer (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::Index, "None");
cls_TopOpeBRepDS_Transition.def("IndexBefore", (Standard_Integer (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::IndexBefore, "None");
cls_TopOpeBRepDS_Transition.def("IndexAfter", (Standard_Integer (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::IndexAfter, "None");
cls_TopOpeBRepDS_Transition.def("Set", (void (TopOpeBRepDS_Transition::*)(const TopAbs_Orientation)) &TopOpeBRepDS_Transition::Set, "set the transition corresponding to orientation <O>", py::arg("O"));
cls_TopOpeBRepDS_Transition.def("Orientation", [](TopOpeBRepDS_Transition &self, const TopAbs_State a0) -> TopAbs_Orientation { return self.Orientation(a0); });
cls_TopOpeBRepDS_Transition.def("Orientation", (TopAbs_Orientation (TopOpeBRepDS_Transition::*)(const TopAbs_State, const TopAbs_ShapeEnum) const) &TopOpeBRepDS_Transition::Orientation, "returns the orientation corresponding to state <S>", py::arg("S"), py::arg("T"));
cls_TopOpeBRepDS_Transition.def("Complement", (TopOpeBRepDS_Transition (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::Complement, "None");
cls_TopOpeBRepDS_Transition.def("IsUnknown", (Standard_Boolean (TopOpeBRepDS_Transition::*)() const) &TopOpeBRepDS_Transition::IsUnknown, "returns True if both states are UNKNOWN");

// Enums

}