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
#include <TopOpeBRepBuild_ListOfLoop.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <TopOpeBRepBuild_LoopSet.hxx>

void bind_TopOpeBRepBuild_LoopSet(py::module &mod){

py::class_<TopOpeBRepBuild_LoopSet, std::unique_ptr<TopOpeBRepBuild_LoopSet>> cls_TopOpeBRepBuild_LoopSet(mod, "TopOpeBRepBuild_LoopSet", "None");

// Constructors
cls_TopOpeBRepBuild_LoopSet.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepBuild_LoopSet.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_LoopSet::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_LoopSet::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_LoopSet::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_LoopSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_LoopSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopSet.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_LoopSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_LoopSet.def("ChangeListOfLoop", (TopOpeBRepBuild_ListOfLoop & (TopOpeBRepBuild_LoopSet::*)()) &TopOpeBRepBuild_LoopSet::ChangeListOfLoop, "None");
cls_TopOpeBRepBuild_LoopSet.def("InitLoop", (void (TopOpeBRepBuild_LoopSet::*)()) &TopOpeBRepBuild_LoopSet::InitLoop, "None");
cls_TopOpeBRepBuild_LoopSet.def("MoreLoop", (Standard_Boolean (TopOpeBRepBuild_LoopSet::*)() const) &TopOpeBRepBuild_LoopSet::MoreLoop, "None");
cls_TopOpeBRepBuild_LoopSet.def("NextLoop", (void (TopOpeBRepBuild_LoopSet::*)()) &TopOpeBRepBuild_LoopSet::NextLoop, "None");
cls_TopOpeBRepBuild_LoopSet.def("Loop", (opencascade::handle<TopOpeBRepBuild_Loop> (TopOpeBRepBuild_LoopSet::*)() const) &TopOpeBRepBuild_LoopSet::Loop, "None");

// Enums

}