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
#include <TopOpeBRep_FaceEdgeIntersector.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRep_FaceEdgeFiller.hxx>

void bind_TopOpeBRep_FaceEdgeFiller(py::module &mod){

py::class_<TopOpeBRep_FaceEdgeFiller, std::unique_ptr<TopOpeBRep_FaceEdgeFiller>> cls_TopOpeBRep_FaceEdgeFiller(mod, "TopOpeBRep_FaceEdgeFiller", "None");

// Constructors
cls_TopOpeBRep_FaceEdgeFiller.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_FaceEdgeFiller.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_FaceEdgeFiller::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_FaceEdgeFiller.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_FaceEdgeFiller::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_FaceEdgeFiller.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_FaceEdgeFiller::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_FaceEdgeFiller.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_FaceEdgeFiller::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_FaceEdgeFiller.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_FaceEdgeFiller::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_FaceEdgeFiller.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_FaceEdgeFiller::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_FaceEdgeFiller.def("Insert", (void (TopOpeBRep_FaceEdgeFiller::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopOpeBRep_FaceEdgeIntersector &, const opencascade::handle<TopOpeBRepDS_HDataStructure> &)) &TopOpeBRep_FaceEdgeFiller::Insert, "None", py::arg("F"), py::arg("E"), py::arg("FEINT"), py::arg("HDS"));

// Enums

}