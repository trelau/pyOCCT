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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pnt2d.hxx>
#include <TopAbs_State.hxx>
#include <TopOpeBRepTool_makeTransition.hxx>

void bind_TopOpeBRepTool_makeTransition(py::module &mod){

py::class_<TopOpeBRepTool_makeTransition, std::unique_ptr<TopOpeBRepTool_makeTransition, Deleter<TopOpeBRepTool_makeTransition>>> cls_TopOpeBRepTool_makeTransition(mod, "TopOpeBRepTool_makeTransition", "None");

// Constructors
cls_TopOpeBRepTool_makeTransition.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepTool_makeTransition.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_makeTransition::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_makeTransition::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_makeTransition::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_makeTransition::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_makeTransition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_makeTransition.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_makeTransition::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_makeTransition.def("Initialize", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Face &, const gp_Pnt2d &, const Standard_Real)) &TopOpeBRepTool_makeTransition::Initialize, "None", py::arg("E"), py::arg("pbef"), py::arg("paft"), py::arg("parE"), py::arg("FS"), py::arg("uv"), py::arg("factor"));
cls_TopOpeBRepTool_makeTransition.def("Setfactor", (void (TopOpeBRepTool_makeTransition::*)(const Standard_Real)) &TopOpeBRepTool_makeTransition::Setfactor, "None", py::arg("factor"));
cls_TopOpeBRepTool_makeTransition.def("Getfactor", (Standard_Real (TopOpeBRepTool_makeTransition::*)() const) &TopOpeBRepTool_makeTransition::Getfactor, "None");
cls_TopOpeBRepTool_makeTransition.def("IsT2d", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)() const) &TopOpeBRepTool_makeTransition::IsT2d, "None");
cls_TopOpeBRepTool_makeTransition.def("SetRest", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(const TopoDS_Edge &, const Standard_Real)) &TopOpeBRepTool_makeTransition::SetRest, "None", py::arg("ES"), py::arg("parES"));
cls_TopOpeBRepTool_makeTransition.def("HasRest", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)() const) &TopOpeBRepTool_makeTransition::HasRest, "None");
cls_TopOpeBRepTool_makeTransition.def("MkT2donE", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepTool_makeTransition::MkT2donE, "None", py::arg("stb"), py::arg("sta"));
cls_TopOpeBRepTool_makeTransition.def("MkT3onE", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepTool_makeTransition::MkT3onE, "None", py::arg("stb"), py::arg("sta"));
cls_TopOpeBRepTool_makeTransition.def("MkT3dproj", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepTool_makeTransition::MkT3dproj, "None", py::arg("stb"), py::arg("sta"));
cls_TopOpeBRepTool_makeTransition.def("MkTonE", (Standard_Boolean (TopOpeBRepTool_makeTransition::*)(TopAbs_State &, TopAbs_State &)) &TopOpeBRepTool_makeTransition::MkTonE, "None", py::arg("stb"), py::arg("sta"));

// Enums

}