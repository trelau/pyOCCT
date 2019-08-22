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
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_ListOfShapeOn1State.hxx>

void bind_TopOpeBRepDS_ListOfShapeOn1State(py::module &mod){

py::class_<TopOpeBRepDS_ListOfShapeOn1State> cls_TopOpeBRepDS_ListOfShapeOn1State(mod, "TopOpeBRepDS_ListOfShapeOn1State", "represent a list of shape");

// Constructors
cls_TopOpeBRepDS_ListOfShapeOn1State.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_ListOfShapeOn1State::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_ListOfShapeOn1State::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_ListOfShapeOn1State::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_ListOfShapeOn1State::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_ListOfShapeOn1State::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_ListOfShapeOn1State.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_ListOfShapeOn1State::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_ListOfShapeOn1State.def("ListOnState", (const TopTools_ListOfShape & (TopOpeBRepDS_ListOfShapeOn1State::*)() const) &TopOpeBRepDS_ListOfShapeOn1State::ListOnState, "None");
cls_TopOpeBRepDS_ListOfShapeOn1State.def("ChangeListOnState", (TopTools_ListOfShape & (TopOpeBRepDS_ListOfShapeOn1State::*)()) &TopOpeBRepDS_ListOfShapeOn1State::ChangeListOnState, "None");
cls_TopOpeBRepDS_ListOfShapeOn1State.def("IsSplit", (Standard_Boolean (TopOpeBRepDS_ListOfShapeOn1State::*)() const) &TopOpeBRepDS_ListOfShapeOn1State::IsSplit, "None");
cls_TopOpeBRepDS_ListOfShapeOn1State.def("Split", [](TopOpeBRepDS_ListOfShapeOn1State &self) -> void { return self.Split(); });
cls_TopOpeBRepDS_ListOfShapeOn1State.def("Split", (void (TopOpeBRepDS_ListOfShapeOn1State::*)(const Standard_Boolean)) &TopOpeBRepDS_ListOfShapeOn1State::Split, "None", py::arg("B"));
cls_TopOpeBRepDS_ListOfShapeOn1State.def("Clear", (void (TopOpeBRepDS_ListOfShapeOn1State::*)()) &TopOpeBRepDS_ListOfShapeOn1State::Clear, "None");

// Enums

}