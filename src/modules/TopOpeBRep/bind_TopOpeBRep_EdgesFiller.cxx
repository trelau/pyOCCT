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
#include <TopoDS_Shape.hxx>
#include <TopOpeBRep_EdgesIntersector.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRep_Point2d.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepDS_PDataStructure.hxx>
#include <TopOpeBRep_PEdgesIntersector.hxx>
#include <TopOpeBRep_EdgesFiller.hxx>

void bind_TopOpeBRep_EdgesFiller(py::module &mod){

py::class_<TopOpeBRep_EdgesFiller, std::unique_ptr<TopOpeBRep_EdgesFiller>> cls_TopOpeBRep_EdgesFiller(mod, "TopOpeBRep_EdgesFiller", "Fills a TopOpeBRepDS_DataStructure with Edge/Edge instersection data described by TopOpeBRep_EdgesIntersector.");

// Constructors
cls_TopOpeBRep_EdgesFiller.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_EdgesFiller.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_EdgesFiller::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_EdgesFiller.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_EdgesFiller::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_EdgesFiller.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_EdgesFiller::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_EdgesFiller.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_EdgesFiller::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_EdgesFiller.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_EdgesFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_EdgesFiller.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_EdgesFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_EdgesFiller.def("Insert", (void (TopOpeBRep_EdgesFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopOpeBRep_EdgesIntersector &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_EdgesFiller::Insert, "None", py::arg("E1"), py::arg("E2"), py::arg("EI"), py::arg("HDS"));
cls_TopOpeBRep_EdgesFiller.def("Face", (void (TopOpeBRep_EdgesFiller::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRep_EdgesFiller::Face, "None", py::arg("I"), py::arg("F"));
cls_TopOpeBRep_EdgesFiller.def("Face", (const TopoDS_Shape & (TopOpeBRep_EdgesFiller::*)(const Standard_Integer) const) &TopOpeBRep_EdgesFiller::Face, "None", py::arg("I"));

// Enums

}