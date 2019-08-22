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
#include <TopOpeBRepBuild_LoopSet.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Pave.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <TopoDS_Edge.hxx>
#include <TopOpeBRepBuild_ListOfPave.hxx>
#include <TopOpeBRepBuild_PaveSet.hxx>

void bind_TopOpeBRepBuild_PaveSet(py::module &mod){

py::class_<TopOpeBRepBuild_PaveSet, TopOpeBRepBuild_LoopSet> cls_TopOpeBRepBuild_PaveSet(mod, "TopOpeBRepBuild_PaveSet", "class providing an exploration of a set of vertices to build edges. It is similar to LoopSet from TopOpeBRepBuild where Loop is Pave.");

// Constructors
cls_TopOpeBRepBuild_PaveSet.def(py::init<const TopoDS_Shape &>(), py::arg("E"));

// Fields

// Methods
// cls_TopOpeBRepBuild_PaveSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_PaveSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_PaveSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_PaveSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_PaveSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_PaveSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_PaveSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_PaveSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_PaveSet.def("RemovePV", (void (TopOpeBRepBuild_PaveSet::*)(const Standard_Boolean)) &TopOpeBRepBuild_PaveSet::RemovePV, "None", py::arg("B"));
cls_TopOpeBRepBuild_PaveSet.def("Append", (void (TopOpeBRepBuild_PaveSet::*)(const opencascade::handle<TopOpeBRepBuild_Pave> &)) &TopOpeBRepBuild_PaveSet::Append, "Add <PV> in the Pave set.", py::arg("PV"));
cls_TopOpeBRepBuild_PaveSet.def("InitLoop", (void (TopOpeBRepBuild_PaveSet::*)()) &TopOpeBRepBuild_PaveSet::InitLoop, "None");
cls_TopOpeBRepBuild_PaveSet.def("MoreLoop", (Standard_Boolean (TopOpeBRepBuild_PaveSet::*)() const) &TopOpeBRepBuild_PaveSet::MoreLoop, "None");
cls_TopOpeBRepBuild_PaveSet.def("NextLoop", (void (TopOpeBRepBuild_PaveSet::*)()) &TopOpeBRepBuild_PaveSet::NextLoop, "None");
cls_TopOpeBRepBuild_PaveSet.def("Loop", (opencascade::handle<TopOpeBRepBuild_Loop> (TopOpeBRepBuild_PaveSet::*)() const) &TopOpeBRepBuild_PaveSet::Loop, "None");
cls_TopOpeBRepBuild_PaveSet.def("Edge", (const TopoDS_Edge & (TopOpeBRepBuild_PaveSet::*)() const) &TopOpeBRepBuild_PaveSet::Edge, "None");
cls_TopOpeBRepBuild_PaveSet.def("HasEqualParameters", (Standard_Boolean (TopOpeBRepBuild_PaveSet::*)()) &TopOpeBRepBuild_PaveSet::HasEqualParameters, "None");
cls_TopOpeBRepBuild_PaveSet.def("EqualParameters", (Standard_Real (TopOpeBRepBuild_PaveSet::*)() const) &TopOpeBRepBuild_PaveSet::EqualParameters, "None");
cls_TopOpeBRepBuild_PaveSet.def("ClosedVertices", (Standard_Boolean (TopOpeBRepBuild_PaveSet::*)()) &TopOpeBRepBuild_PaveSet::ClosedVertices, "None");
cls_TopOpeBRepBuild_PaveSet.def_static("SortPave_", (void (*)(const TopOpeBRepBuild_ListOfPave &, TopOpeBRepBuild_ListOfPave &)) &TopOpeBRepBuild_PaveSet::SortPave, "None", py::arg("Lin"), py::arg("Lout"));

// Enums

}