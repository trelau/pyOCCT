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
#include <TopAbs_State.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_ShapeWithState.hxx>

void bind_TopOpeBRepDS_ShapeWithState(py::module &mod){

py::class_<TopOpeBRepDS_ShapeWithState, std::unique_ptr<TopOpeBRepDS_ShapeWithState, Deleter<TopOpeBRepDS_ShapeWithState>>> cls_TopOpeBRepDS_ShapeWithState(mod, "TopOpeBRepDS_ShapeWithState", "None");

// Constructors
cls_TopOpeBRepDS_ShapeWithState.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_ShapeWithState::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_ShapeWithState::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_ShapeWithState::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_ShapeWithState::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_ShapeWithState::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_ShapeWithState.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_ShapeWithState::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_ShapeWithState.def("Part", (const TopTools_ListOfShape & (TopOpeBRepDS_ShapeWithState::*)(const TopAbs_State) const) &TopOpeBRepDS_ShapeWithState::Part, "None", py::arg("aState"));
cls_TopOpeBRepDS_ShapeWithState.def("AddPart", (void (TopOpeBRepDS_ShapeWithState::*)(const TopoDS_Shape &, const TopAbs_State)) &TopOpeBRepDS_ShapeWithState::AddPart, "None", py::arg("aShape"), py::arg("aState"));
cls_TopOpeBRepDS_ShapeWithState.def("AddParts", (void (TopOpeBRepDS_ShapeWithState::*)(const TopTools_ListOfShape &, const TopAbs_State)) &TopOpeBRepDS_ShapeWithState::AddParts, "None", py::arg("aListOfShape"), py::arg("aState"));
cls_TopOpeBRepDS_ShapeWithState.def("SetState", (void (TopOpeBRepDS_ShapeWithState::*)(const TopAbs_State)) &TopOpeBRepDS_ShapeWithState::SetState, "None", py::arg("aState"));
cls_TopOpeBRepDS_ShapeWithState.def("State", (TopAbs_State (TopOpeBRepDS_ShapeWithState::*)() const) &TopOpeBRepDS_ShapeWithState::State, "None");
cls_TopOpeBRepDS_ShapeWithState.def("SetIsSplitted", (void (TopOpeBRepDS_ShapeWithState::*)(const Standard_Boolean)) &TopOpeBRepDS_ShapeWithState::SetIsSplitted, "None", py::arg("anIsSplitted"));
cls_TopOpeBRepDS_ShapeWithState.def("IsSplitted", (Standard_Boolean (TopOpeBRepDS_ShapeWithState::*)() const) &TopOpeBRepDS_ShapeWithState::IsSplitted, "None");

// Enums

}