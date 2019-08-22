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
#include <TopOpeBRepBuild_LoopClassifier.hxx>
#include <Standard.hxx>
#include <TopAbs_State.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepBuild_BlockBuilder.hxx>
#include <TopOpeBRepBuild_CompositeClassifier.hxx>

void bind_TopOpeBRepBuild_CompositeClassifier(py::module &mod){

py::class_<TopOpeBRepBuild_CompositeClassifier, TopOpeBRepBuild_LoopClassifier> cls_TopOpeBRepBuild_CompositeClassifier(mod, "TopOpeBRepBuild_CompositeClassifier", "classify composite Loops, i.e, loops that can be either a Shape, or a block of Elements.");

// Fields

// Methods
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_CompositeClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_CompositeClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_CompositeClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_CompositeClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_CompositeClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_CompositeClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_CompositeClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_CompositeClassifier.def("Compare", (TopAbs_State (TopOpeBRepBuild_CompositeClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_CompositeClassifier::Compare, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_CompositeClassifier.def("CompareShapes", (TopAbs_State (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::CompareShapes, "classify shape <B1> with shape <B2>", py::arg("B1"), py::arg("B2"));
cls_TopOpeBRepBuild_CompositeClassifier.def("CompareElementToShape", (TopAbs_State (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::CompareElementToShape, "classify element <E> with shape <B>", py::arg("E"), py::arg("B"));
cls_TopOpeBRepBuild_CompositeClassifier.def("ResetShape", (void (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::ResetShape, "prepare classification involving shape <B> calls ResetElement on first element of <B>", py::arg("B"));
cls_TopOpeBRepBuild_CompositeClassifier.def("ResetElement", (void (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::ResetElement, "prepare classification involving element <E>.", py::arg("E"));
cls_TopOpeBRepBuild_CompositeClassifier.def("CompareElement", (Standard_Boolean (TopOpeBRepBuild_CompositeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_CompositeClassifier::CompareElement, "Add element <E> in the set of elements used in classification. Returns FALSE if the element <E> has been already added to the set of elements, otherwise returns TRUE.", py::arg("E"));
cls_TopOpeBRepBuild_CompositeClassifier.def("State", (TopAbs_State (TopOpeBRepBuild_CompositeClassifier::*)()) &TopOpeBRepBuild_CompositeClassifier::State, "Returns state of classification of 2D point, defined by ResetElement, with the current set of elements, defined by Compare.");

// Enums

}