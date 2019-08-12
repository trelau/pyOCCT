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
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <TopOpeBRepBuild_LoopClassifier.hxx>

void bind_TopOpeBRepBuild_LoopClassifier(py::module &mod){

py::class_<TopOpeBRepBuild_LoopClassifier, std::unique_ptr<TopOpeBRepBuild_LoopClassifier, Deleter<TopOpeBRepBuild_LoopClassifier>>> cls_TopOpeBRepBuild_LoopClassifier(mod, "TopOpeBRepBuild_LoopClassifier", "classify loops in order to build Areas");

// Fields

// Methods
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_LoopClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_LoopClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_LoopClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_LoopClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_LoopClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_LoopClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_LoopClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_LoopClassifier.def("Compare", (TopAbs_State (TopOpeBRepBuild_LoopClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_LoopClassifier::Compare, "Returns the state of loop <L1> compared with loop <L2>.", py::arg("L1"), py::arg("L2"));

// Enums

}