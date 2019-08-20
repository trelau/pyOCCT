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
#include <Standard_TypeDef.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopOpeBRepTool_FuseEdges.hxx>

void bind_TopOpeBRepTool_FuseEdges(py::module &mod){

py::class_<TopOpeBRepTool_FuseEdges, std::unique_ptr<TopOpeBRepTool_FuseEdges>> cls_TopOpeBRepTool_FuseEdges(mod, "TopOpeBRepTool_FuseEdges", "This class can detect vertices in a face that can be considered useless and then perform the fuse of the edges and remove the useless vertices. By useles vertices, we mean : * vertices that have exactly two connex edges * the edges connex to the vertex must have exactly the same 2 connex faces . * The edges connex to the vertex must have the same geometric support.");

// Constructors
cls_TopOpeBRepTool_FuseEdges.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_TopOpeBRepTool_FuseEdges.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("PerformNow"));

// Fields

// Methods
// cls_TopOpeBRepTool_FuseEdges.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_FuseEdges::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_FuseEdges::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_FuseEdges::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_FuseEdges::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_FuseEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_FuseEdges.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_FuseEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_FuseEdges.def("AvoidEdges", (void (TopOpeBRepTool_FuseEdges::*)(const TopTools_IndexedMapOfShape &)) &TopOpeBRepTool_FuseEdges::AvoidEdges, "set edges to avoid being fused", py::arg("theMapEdg"));
cls_TopOpeBRepTool_FuseEdges.def("Edges", (void (TopOpeBRepTool_FuseEdges::*)(TopTools_DataMapOfIntegerListOfShape &)) &TopOpeBRepTool_FuseEdges::Edges, "returns all the list of edges to be fused each list of the map represent a set of connex edges that can be fused.", py::arg("theMapLstEdg"));
cls_TopOpeBRepTool_FuseEdges.def("ResultEdges", (void (TopOpeBRepTool_FuseEdges::*)(TopTools_DataMapOfIntegerShape &)) &TopOpeBRepTool_FuseEdges::ResultEdges, "returns all the fused edges. each integer entry in the map corresponds to the integer in the DataMapOfIntegerListOfShape we get in method Edges. That is to say, to the list of edges in theMapLstEdg(i) corresponds the resulting edge theMapEdge(i)", py::arg("theMapEdg"));
cls_TopOpeBRepTool_FuseEdges.def("Faces", (void (TopOpeBRepTool_FuseEdges::*)(TopTools_DataMapOfShapeShape &)) &TopOpeBRepTool_FuseEdges::Faces, "returns the map of modified faces.", py::arg("theMapFac"));
cls_TopOpeBRepTool_FuseEdges.def("Shape", (TopoDS_Shape & (TopOpeBRepTool_FuseEdges::*)()) &TopOpeBRepTool_FuseEdges::Shape, "returns myShape modified with the list of internal edges removed from it.");
cls_TopOpeBRepTool_FuseEdges.def("NbVertices", (Standard_Integer (TopOpeBRepTool_FuseEdges::*)()) &TopOpeBRepTool_FuseEdges::NbVertices, "returns the number of vertices candidate to be removed");
cls_TopOpeBRepTool_FuseEdges.def("Perform", (void (TopOpeBRepTool_FuseEdges::*)()) &TopOpeBRepTool_FuseEdges::Perform, "Using map of list of connex edges, fuse each list to one edge and then update myShape");

// Enums

}