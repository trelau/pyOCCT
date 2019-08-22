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
#include <TopOpeBRepBuild_WireEdgeSet.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopOpeBRepBuild_ShapeSet.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepBuild_LoopSet.hxx>
#include <TopOpeBRepBuild_BlockIterator.hxx>
#include <TopOpeBRepBuild_BlockBuilder.hxx>
#include <TopOpeBRepBuild_FaceAreaBuilder.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopOpeBRepBuild_FaceBuilder.hxx>

void bind_TopOpeBRepBuild_FaceBuilder(py::module &mod){

py::class_<TopOpeBRepBuild_FaceBuilder> cls_TopOpeBRepBuild_FaceBuilder(mod, "TopOpeBRepBuild_FaceBuilder", "None");

// Constructors
cls_TopOpeBRepBuild_FaceBuilder.def(py::init<>());
cls_TopOpeBRepBuild_FaceBuilder.def(py::init<TopOpeBRepBuild_WireEdgeSet &, const TopoDS_Shape &>(), py::arg("ES"), py::arg("F"));
cls_TopOpeBRepBuild_FaceBuilder.def(py::init<TopOpeBRepBuild_WireEdgeSet &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("ES"), py::arg("F"), py::arg("ForceClass"));

// Fields

// Methods
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_FaceBuilder::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_FaceBuilder::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_FaceBuilder::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_FaceBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_FaceBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_FaceBuilder.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_FaceBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_FaceBuilder.def("InitFaceBuilder", (void (TopOpeBRepBuild_FaceBuilder::*)(TopOpeBRepBuild_WireEdgeSet &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepBuild_FaceBuilder::InitFaceBuilder, "None", py::arg("ES"), py::arg("F"), py::arg("ForceClass"));
cls_TopOpeBRepBuild_FaceBuilder.def("DetectUnclosedWire", (void (TopOpeBRepBuild_FaceBuilder::*)(TopTools_IndexedDataMapOfShapeShape &, TopTools_IndexedDataMapOfShapeShape &)) &TopOpeBRepBuild_FaceBuilder::DetectUnclosedWire, "Removes are non 3d-closed wires. Fills up maps <mapVVsameG> and <mapVon1Edge>, in order to correct 3d-closed but unclosed (topologic connexity) wires. modifies myBlockBuilder", py::arg("mapVVsameG"), py::arg("mapVon1Edge"));
cls_TopOpeBRepBuild_FaceBuilder.def("CorrectGclosedWire", (void (TopOpeBRepBuild_FaceBuilder::*)(const TopTools_IndexedDataMapOfShapeShape &, const TopTools_IndexedDataMapOfShapeShape &)) &TopOpeBRepBuild_FaceBuilder::CorrectGclosedWire, "Using the given maps, change the topology of the 3d-closed wires, in order to get closed wires.", py::arg("mapVVref"), py::arg("mapVon1Edge"));
cls_TopOpeBRepBuild_FaceBuilder.def("DetectPseudoInternalEdge", (void (TopOpeBRepBuild_FaceBuilder::*)(TopTools_IndexedMapOfShape &)) &TopOpeBRepBuild_FaceBuilder::DetectPseudoInternalEdge, "Removes edges appearing twice (FORWARD,REVERSED) with a bounding vertex not connected to any other edge. mapE contains edges found. modifies myBlockBuilder.", py::arg("mapE"));
cls_TopOpeBRepBuild_FaceBuilder.def("Face", (const TopoDS_Shape & (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::Face, "return myFace");
cls_TopOpeBRepBuild_FaceBuilder.def("InitFace", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::InitFace, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("MoreFace", (Standard_Boolean (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::MoreFace, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("NextFace", (void (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::NextFace, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("InitWire", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::InitWire, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("MoreWire", (Standard_Boolean (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::MoreWire, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("NextWire", (void (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::NextWire, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("IsOldWire", (Standard_Boolean (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::IsOldWire, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("OldWire", (const TopoDS_Shape & (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::OldWire, "Returns current wire This wire may be : * an old wire OldWire(), which has not been reconstructed; * a new wire made of edges described by ...NewEdge() methods.");
cls_TopOpeBRepBuild_FaceBuilder.def("FindNextValidElement", (void (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::FindNextValidElement, "Iterates on myBlockIterator until finding a valid element");
cls_TopOpeBRepBuild_FaceBuilder.def("InitEdge", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::InitEdge, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("MoreEdge", (Standard_Boolean (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::MoreEdge, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("NextEdge", (void (TopOpeBRepBuild_FaceBuilder::*)()) &TopOpeBRepBuild_FaceBuilder::NextEdge, "None");
cls_TopOpeBRepBuild_FaceBuilder.def("Edge", (const TopoDS_Shape & (TopOpeBRepBuild_FaceBuilder::*)() const) &TopOpeBRepBuild_FaceBuilder::Edge, "Returns current new edge of current new wire.");
cls_TopOpeBRepBuild_FaceBuilder.def("EdgeConnexity", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)(const TopoDS_Shape &) const) &TopOpeBRepBuild_FaceBuilder::EdgeConnexity, "None", py::arg("E"));
cls_TopOpeBRepBuild_FaceBuilder.def("AddEdgeWire", (Standard_Integer (TopOpeBRepBuild_FaceBuilder::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepBuild_FaceBuilder::AddEdgeWire, "None", py::arg("E"), py::arg("W"));

// Enums

}