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
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopOpeBRepDS_Explorer.hxx>

void bind_TopOpeBRepDS_Explorer(py::module &mod){

py::class_<TopOpeBRepDS_Explorer, std::unique_ptr<TopOpeBRepDS_Explorer, Deleter<TopOpeBRepDS_Explorer>>> cls_TopOpeBRepDS_Explorer(mod, "TopOpeBRepDS_Explorer", "None");

// Constructors
cls_TopOpeBRepDS_Explorer.def(py::init<>());
cls_TopOpeBRepDS_Explorer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &>(), py::arg("HDS"));
cls_TopOpeBRepDS_Explorer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopAbs_ShapeEnum>(), py::arg("HDS"), py::arg("T"));
cls_TopOpeBRepDS_Explorer.def(py::init<const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopAbs_ShapeEnum, const Standard_Boolean>(), py::arg("HDS"), py::arg("T"), py::arg("findkeep"));

// Fields

// Methods
// cls_TopOpeBRepDS_Explorer.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Explorer::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Explorer.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Explorer::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Explorer.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Explorer::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Explorer.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Explorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Explorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Explorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Explorer.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Explorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Explorer.def("Init", [](TopOpeBRepDS_Explorer &self, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a0) -> void { return self.Init(a0); });
cls_TopOpeBRepDS_Explorer.def("Init", [](TopOpeBRepDS_Explorer &self, const opencascade::handle<TopOpeBRepDS_HDataStructure> & a0, const TopAbs_ShapeEnum a1) -> void { return self.Init(a0, a1); });
cls_TopOpeBRepDS_Explorer.def("Init", (void (TopOpeBRepDS_Explorer::*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopAbs_ShapeEnum, const Standard_Boolean)) &TopOpeBRepDS_Explorer::Init, "None", py::arg("HDS"), py::arg("T"), py::arg("findkeep"));
cls_TopOpeBRepDS_Explorer.def("Type", (TopAbs_ShapeEnum (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Type, "None");
cls_TopOpeBRepDS_Explorer.def("More", (Standard_Boolean (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::More, "None");
cls_TopOpeBRepDS_Explorer.def("Next", (void (TopOpeBRepDS_Explorer::*)()) &TopOpeBRepDS_Explorer::Next, "None");
cls_TopOpeBRepDS_Explorer.def("Current", (const TopoDS_Shape & (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Current, "None");
cls_TopOpeBRepDS_Explorer.def("Index", (Standard_Integer (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Index, "None");
cls_TopOpeBRepDS_Explorer.def("Face", (const TopoDS_Face & (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Face, "None");
cls_TopOpeBRepDS_Explorer.def("Edge", (const TopoDS_Edge & (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Edge, "None");
cls_TopOpeBRepDS_Explorer.def("Vertex", (const TopoDS_Vertex & (TopOpeBRepDS_Explorer::*)() const) &TopOpeBRepDS_Explorer::Vertex, "None");

// Enums

}