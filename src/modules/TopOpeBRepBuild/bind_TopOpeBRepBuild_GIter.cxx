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
#include <TopOpeBRepBuild_GTopo.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_State.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepBuild_GIter.hxx>

void bind_TopOpeBRepBuild_GIter(py::module &mod){

py::class_<TopOpeBRepBuild_GIter, std::unique_ptr<TopOpeBRepBuild_GIter, Deleter<TopOpeBRepBuild_GIter>>> cls_TopOpeBRepBuild_GIter(mod, "TopOpeBRepBuild_GIter", "None");

// Constructors
cls_TopOpeBRepBuild_GIter.def(py::init<>());
cls_TopOpeBRepBuild_GIter.def(py::init<const TopOpeBRepBuild_GTopo &>(), py::arg("G"));

// Fields

// Methods
// cls_TopOpeBRepBuild_GIter.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_GIter::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GIter.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_GIter::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GIter.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_GIter::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_GIter.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_GIter::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_GIter.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_GIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_GIter.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_GIter::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_GIter.def("Init", (void (TopOpeBRepBuild_GIter::*)()) &TopOpeBRepBuild_GIter::Init, "None");
cls_TopOpeBRepBuild_GIter.def("Init", (void (TopOpeBRepBuild_GIter::*)(const TopOpeBRepBuild_GTopo &)) &TopOpeBRepBuild_GIter::Init, "None", py::arg("G"));
cls_TopOpeBRepBuild_GIter.def("More", (Standard_Boolean (TopOpeBRepBuild_GIter::*)() const) &TopOpeBRepBuild_GIter::More, "None");
cls_TopOpeBRepBuild_GIter.def("Next", (void (TopOpeBRepBuild_GIter::*)()) &TopOpeBRepBuild_GIter::Next, "None");
cls_TopOpeBRepBuild_GIter.def("Current", (void (TopOpeBRepBuild_GIter::*)(TopAbs_State &, TopAbs_State &) const) &TopOpeBRepBuild_GIter::Current, "None", py::arg("s1"), py::arg("s2"));
cls_TopOpeBRepBuild_GIter.def("Dump", (void (TopOpeBRepBuild_GIter::*)(Standard_OStream &) const) &TopOpeBRepBuild_GIter::Dump, "None", py::arg("OS"));

// Enums

}