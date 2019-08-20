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
#include <NCollection_BaseAllocator.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BOPAlgo_WireEdgeSet.hxx>

void bind_BOPAlgo_WireEdgeSet(py::module &mod){

py::class_<BOPAlgo_WireEdgeSet, std::unique_ptr<BOPAlgo_WireEdgeSet>> cls_BOPAlgo_WireEdgeSet(mod, "BOPAlgo_WireEdgeSet", "None");

// Constructors
cls_BOPAlgo_WireEdgeSet.def(py::init<>());
cls_BOPAlgo_WireEdgeSet.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_WireEdgeSet.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_WireEdgeSet::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_WireEdgeSet::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_WireEdgeSet::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_WireEdgeSet::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_WireEdgeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_WireEdgeSet.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_WireEdgeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_WireEdgeSet.def("Clear", (void (BOPAlgo_WireEdgeSet::*)()) &BOPAlgo_WireEdgeSet::Clear, "None");
cls_BOPAlgo_WireEdgeSet.def("SetFace", (void (BOPAlgo_WireEdgeSet::*)(const TopoDS_Face &)) &BOPAlgo_WireEdgeSet::SetFace, "None", py::arg("aF"));
cls_BOPAlgo_WireEdgeSet.def("Face", (const TopoDS_Face & (BOPAlgo_WireEdgeSet::*)() const) &BOPAlgo_WireEdgeSet::Face, "None");
cls_BOPAlgo_WireEdgeSet.def("AddStartElement", (void (BOPAlgo_WireEdgeSet::*)(const TopoDS_Shape &)) &BOPAlgo_WireEdgeSet::AddStartElement, "None", py::arg("sS"));
cls_BOPAlgo_WireEdgeSet.def("StartElements", (const TopTools_ListOfShape & (BOPAlgo_WireEdgeSet::*)() const) &BOPAlgo_WireEdgeSet::StartElements, "None");
cls_BOPAlgo_WireEdgeSet.def("AddShape", (void (BOPAlgo_WireEdgeSet::*)(const TopoDS_Shape &)) &BOPAlgo_WireEdgeSet::AddShape, "None", py::arg("sS"));
cls_BOPAlgo_WireEdgeSet.def("Shapes", (const TopTools_ListOfShape & (BOPAlgo_WireEdgeSet::*)() const) &BOPAlgo_WireEdgeSet::Shapes, "None");

// Enums

}