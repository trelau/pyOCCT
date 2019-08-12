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
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Graphic3d_WorldViewProjState.hxx>

void bind_Graphic3d_WorldViewProjState(py::module &mod){

py::class_<Graphic3d_WorldViewProjState, std::unique_ptr<Graphic3d_WorldViewProjState, Deleter<Graphic3d_WorldViewProjState>>> cls_Graphic3d_WorldViewProjState(mod, "Graphic3d_WorldViewProjState", "Helper class for keeping reference on world-view-projection state. Helpful for synchronizing state of WVP dependent data structures.");

// Constructors
cls_Graphic3d_WorldViewProjState.def(py::init<>());
cls_Graphic3d_WorldViewProjState.def(py::init<const Standard_Size, const Standard_Size>(), py::arg("theProjectionState"), py::arg("theWorldViewState"));
cls_Graphic3d_WorldViewProjState.def(py::init<const Standard_Size, const Standard_Size, const Standard_Transient *>(), py::arg("theProjectionState"), py::arg("theWorldViewState"), py::arg("theCamera"));

// Fields

// Methods
cls_Graphic3d_WorldViewProjState.def("IsValid", (Standard_Boolean (Graphic3d_WorldViewProjState::*)()) &Graphic3d_WorldViewProjState::IsValid, "Check state validity.");
cls_Graphic3d_WorldViewProjState.def("Reset", (void (Graphic3d_WorldViewProjState::*)()) &Graphic3d_WorldViewProjState::Reset, "Invalidate world view projection state.");
cls_Graphic3d_WorldViewProjState.def("Initialize", [](Graphic3d_WorldViewProjState &self, const Standard_Size a0, const Standard_Size a1) -> void { return self.Initialize(a0, a1); });
cls_Graphic3d_WorldViewProjState.def("Initialize", (void (Graphic3d_WorldViewProjState::*)(const Standard_Size, const Standard_Size, const Standard_Transient *)) &Graphic3d_WorldViewProjState::Initialize, "Initialize world view projection state.", py::arg("theProjectionState"), py::arg("theWorldViewState"), py::arg("theCamera"));
cls_Graphic3d_WorldViewProjState.def("Initialize", [](Graphic3d_WorldViewProjState &self) -> void { return self.Initialize(); });
cls_Graphic3d_WorldViewProjState.def("Initialize", (void (Graphic3d_WorldViewProjState::*)(const Standard_Transient *)) &Graphic3d_WorldViewProjState::Initialize, "Initialize world view projection state.", py::arg("theCamera"));
cls_Graphic3d_WorldViewProjState.def("ProjectionState", (Standard_Size & (Graphic3d_WorldViewProjState::*)()) &Graphic3d_WorldViewProjState::ProjectionState, "Returns projection state counter.");
cls_Graphic3d_WorldViewProjState.def("WorldViewState", (Standard_Size & (Graphic3d_WorldViewProjState::*)()) &Graphic3d_WorldViewProjState::WorldViewState, "Returns world view state counter.");
cls_Graphic3d_WorldViewProjState.def("IsProjectionChanged", (Standard_Boolean (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &)) &Graphic3d_WorldViewProjState::IsProjectionChanged, "Compare projection with other state.", py::arg("theState"));
cls_Graphic3d_WorldViewProjState.def("IsWorldViewChanged", (Standard_Boolean (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &)) &Graphic3d_WorldViewProjState::IsWorldViewChanged, "Compare world view transformation with other state.", py::arg("theState"));
cls_Graphic3d_WorldViewProjState.def("IsChanged", (Standard_Boolean (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &)) &Graphic3d_WorldViewProjState::IsChanged, "Compare with other world view projection state.", py::arg("theState"));
cls_Graphic3d_WorldViewProjState.def("__ne__", (bool (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &) const) &Graphic3d_WorldViewProjState::operator!=, py::is_operator(), "Compare with other world view projection state.", py::arg("theOther"));
cls_Graphic3d_WorldViewProjState.def("__eq__", (bool (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &) const) &Graphic3d_WorldViewProjState::operator==, py::is_operator(), "Compare with other world view projection state.", py::arg("theOther"));
// cls_Graphic3d_WorldViewProjState.def("operator=", (void (Graphic3d_WorldViewProjState::*)(const Graphic3d_WorldViewProjState &)) &Graphic3d_WorldViewProjState::operator=, "Copy world view projection state.", py::arg("theOther"));

// Enums

}