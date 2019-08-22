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
#include <TopOpeBRepBuild_CompositeClassifier.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepBuild_BlockBuilder.hxx>
#include <TopAbs_State.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_Loop.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepClass_Edge.hxx>
#include <BRepClass_FacePassiveClassifier.hxx>
#include <TopOpeBRepBuild_WireEdgeClassifier.hxx>

void bind_TopOpeBRepBuild_WireEdgeClassifier(py::module &mod){

py::class_<TopOpeBRepBuild_WireEdgeClassifier, TopOpeBRepBuild_CompositeClassifier> cls_TopOpeBRepBuild_WireEdgeClassifier(mod, "TopOpeBRepBuild_WireEdgeClassifier", "Classify edges and wires. shapes are Wires, Element are Edge.");

// Constructors
cls_TopOpeBRepBuild_WireEdgeClassifier.def(py::init<const TopoDS_Shape &, const TopOpeBRepBuild_BlockBuilder &>(), py::arg("F"), py::arg("BB"));

// Fields

// Methods
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_WireEdgeClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_WireEdgeClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_WireEdgeClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_WireEdgeClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_WireEdgeClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireEdgeClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_WireEdgeClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("Compare", (TopAbs_State (TopOpeBRepBuild_WireEdgeClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &, const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_WireEdgeClassifier::Compare, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("LoopToShape", (TopoDS_Shape (TopOpeBRepBuild_WireEdgeClassifier::*)(const opencascade::handle<TopOpeBRepBuild_Loop> &)) &TopOpeBRepBuild_WireEdgeClassifier::LoopToShape, "None", py::arg("L"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("CompareShapes", (TopAbs_State (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::CompareShapes, "classify wire <B1> with wire <B2>", py::arg("B1"), py::arg("B2"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("CompareElementToShape", (TopAbs_State (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::CompareElementToShape, "classify edge <E> with wire <B>", py::arg("E"), py::arg("B"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("ResetShape", (void (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::ResetShape, "prepare classification involving wire <B> calls ResetElement on first edge of <B>", py::arg("B"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("ResetElement", (void (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::ResetElement, "prepare classification involving edge <E> define 2D point (later used in Compare()) on first vertex of edge <E>.", py::arg("E"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("CompareElement", (Standard_Boolean (TopOpeBRepBuild_WireEdgeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepBuild_WireEdgeClassifier::CompareElement, "Add the edge <E> in the set of edges used in 2D point classification.", py::arg("E"));
cls_TopOpeBRepBuild_WireEdgeClassifier.def("State", (TopAbs_State (TopOpeBRepBuild_WireEdgeClassifier::*)()) &TopOpeBRepBuild_WireEdgeClassifier::State, "Returns state of classification of 2D point, defined by ResetElement, with the current set of edges, defined by Compare.");

// Enums

}