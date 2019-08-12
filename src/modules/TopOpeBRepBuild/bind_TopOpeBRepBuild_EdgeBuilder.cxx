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
#include <TopOpeBRepBuild_Area1dBuilder.hxx>
#include <Standard.hxx>
#include <TopOpeBRepBuild_PaveSet.hxx>
#include <TopOpeBRepBuild_PaveClassifier.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepBuild_LoopSet.hxx>
#include <TopOpeBRepBuild_LoopClassifier.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepBuild_EdgeBuilder.hxx>

void bind_TopOpeBRepBuild_EdgeBuilder(py::module &mod){

py::class_<TopOpeBRepBuild_EdgeBuilder, std::unique_ptr<TopOpeBRepBuild_EdgeBuilder, Deleter<TopOpeBRepBuild_EdgeBuilder>>, TopOpeBRepBuild_Area1dBuilder> cls_TopOpeBRepBuild_EdgeBuilder(mod, "TopOpeBRepBuild_EdgeBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_EdgeBuilder.def(py::init<>());
cls_TopOpeBRepBuild_EdgeBuilder.def(py::init<TopOpeBRepBuild_PaveSet &, TopOpeBRepBuild_PaveClassifier &>(), py::arg("LS"), py::arg("LC"));
cls_TopOpeBRepBuild_EdgeBuilder.def(py::init<TopOpeBRepBuild_PaveSet &, TopOpeBRepBuild_PaveClassifier &, const Standard_Boolean>(), py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));

// Fields

// Methods
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_EdgeBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_EdgeBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_EdgeBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_EdgeBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_EdgeBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_EdgeBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_EdgeBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_EdgeBuilder.def("InitEdgeBuilder", [](TopOpeBRepBuild_EdgeBuilder &self, TopOpeBRepBuild_LoopSet & a0, TopOpeBRepBuild_LoopClassifier & a1) -> void { return self.InitEdgeBuilder(a0, a1); });
cls_TopOpeBRepBuild_EdgeBuilder.def("InitEdgeBuilder", (void (TopOpeBRepBuild_EdgeBuilder::*)(TopOpeBRepBuild_LoopSet &, TopOpeBRepBuild_LoopClassifier &, const Standard_Boolean)) &TopOpeBRepBuild_EdgeBuilder::InitEdgeBuilder, "None", py::arg("LS"), py::arg("LC"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_EdgeBuilder.def("InitEdge", (void (TopOpeBRepBuild_EdgeBuilder::*)()) &TopOpeBRepBuild_EdgeBuilder::InitEdge, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("MoreEdge", (Standard_Boolean (TopOpeBRepBuild_EdgeBuilder::*)() const) &TopOpeBRepBuild_EdgeBuilder::MoreEdge, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("NextEdge", (void (TopOpeBRepBuild_EdgeBuilder::*)()) &TopOpeBRepBuild_EdgeBuilder::NextEdge, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("InitVertex", (void (TopOpeBRepBuild_EdgeBuilder::*)()) &TopOpeBRepBuild_EdgeBuilder::InitVertex, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("MoreVertex", (Standard_Boolean (TopOpeBRepBuild_EdgeBuilder::*)() const) &TopOpeBRepBuild_EdgeBuilder::MoreVertex, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("NextVertex", (void (TopOpeBRepBuild_EdgeBuilder::*)()) &TopOpeBRepBuild_EdgeBuilder::NextVertex, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("Vertex", (const TopoDS_Shape & (TopOpeBRepBuild_EdgeBuilder::*)() const) &TopOpeBRepBuild_EdgeBuilder::Vertex, "None");
cls_TopOpeBRepBuild_EdgeBuilder.def("Parameter", (Standard_Real (TopOpeBRepBuild_EdgeBuilder::*)() const) &TopOpeBRepBuild_EdgeBuilder::Parameter, "None");

// Enums

}