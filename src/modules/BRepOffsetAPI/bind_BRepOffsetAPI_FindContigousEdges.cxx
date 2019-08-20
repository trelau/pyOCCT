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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <BRepOffsetAPI_FindContigousEdges.hxx>

void bind_BRepOffsetAPI_FindContigousEdges(py::module &mod){

py::class_<BRepOffsetAPI_FindContigousEdges, std::unique_ptr<BRepOffsetAPI_FindContigousEdges>> cls_BRepOffsetAPI_FindContigousEdges(mod, "BRepOffsetAPI_FindContigousEdges", "Provides methods to identify contigous boundaries for continuity control (C0, C1, ...)");

// Constructors
cls_BRepOffsetAPI_FindContigousEdges.def(py::init<>());
cls_BRepOffsetAPI_FindContigousEdges.def(py::init<const Standard_Real>(), py::arg("tolerance"));
cls_BRepOffsetAPI_FindContigousEdges.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("tolerance"), py::arg("option"));

// Fields

// Methods
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_FindContigousEdges::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_FindContigousEdges::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_FindContigousEdges::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_FindContigousEdges::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_FindContigousEdges::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_FindContigousEdges.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_FindContigousEdges::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_FindContigousEdges.def("Init", (void (BRepOffsetAPI_FindContigousEdges::*)(const Standard_Real, const Standard_Boolean)) &BRepOffsetAPI_FindContigousEdges::Init, "Initializes this algorithm for identifying contiguous edges on shapes using the tolerance of contiguity tolerance. This tolerance value is used to determine whether two edges or sections of edges are coincident. Use the function Add to define the shapes to be checked. Sets <option> to false.", py::arg("tolerance"), py::arg("option"));
cls_BRepOffsetAPI_FindContigousEdges.def("Add", (void (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Shape &)) &BRepOffsetAPI_FindContigousEdges::Add, "Adds the shape shape to the list of shapes to be checked by this algorithm. Once all the shapes to be checked have been added, use the function Perform to find the contiguous edges and the function ContigousEdge to return these edges.", py::arg("shape"));
cls_BRepOffsetAPI_FindContigousEdges.def("Perform", (void (BRepOffsetAPI_FindContigousEdges::*)()) &BRepOffsetAPI_FindContigousEdges::Perform, "Finds coincident parts of edges of two or more shapes added to this algorithm and breaks down these edges into contiguous and non-contiguous sections on copies of the initial shapes. The function ContigousEdge returns contiguous edges. The function Modified can be used to return modified copies of the initial shapes where one or more edges were broken down into contiguous and non-contiguous sections. Warning This function must be used once all the shapes to be checked have been added. It is not possible to add further shapes subsequently and then to repeat the call to Perform.");
// cls_BRepOffsetAPI_FindContigousEdges.def("NbEdges", (Standard_Integer (BRepOffsetAPI_FindContigousEdges::*)() const) &BRepOffsetAPI_FindContigousEdges::NbEdges, "Gives the number of edges (free edges + contigous edges + multiple edge)");
cls_BRepOffsetAPI_FindContigousEdges.def("NbContigousEdges", (Standard_Integer (BRepOffsetAPI_FindContigousEdges::*)() const) &BRepOffsetAPI_FindContigousEdges::NbContigousEdges, "Returns the number of contiguous edges found by the function Perform on the shapes added to this algorithm.");
cls_BRepOffsetAPI_FindContigousEdges.def("ContigousEdge", (const TopoDS_Edge & (BRepOffsetAPI_FindContigousEdges::*)(const Standard_Integer) const) &BRepOffsetAPI_FindContigousEdges::ContigousEdge, "Returns the contiguous edge of index index found by the function Perform on the shapes added to this algorithm. Exceptions Standard_OutOfRange if: - index is less than 1, or - index is greater than the number of contiguous edges found by the function Perform on the shapes added to this algorithm.", py::arg("index"));
cls_BRepOffsetAPI_FindContigousEdges.def("ContigousEdgeCouple", (const TopTools_ListOfShape & (BRepOffsetAPI_FindContigousEdges::*)(const Standard_Integer) const) &BRepOffsetAPI_FindContigousEdges::ContigousEdgeCouple, "Returns a list of edges coincident with the contiguous edge of index index found by the function Perform. There are as many edges in the list as there are faces adjacent to this contiguous edge. Exceptions Standard_OutOfRange if: - index is less than 1, or - index is greater than the number of contiguous edges found by the function Perform on the shapes added to this algorithm.", py::arg("index"));
cls_BRepOffsetAPI_FindContigousEdges.def("SectionToBoundary", (const TopoDS_Edge & (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Edge &) const) &BRepOffsetAPI_FindContigousEdges::SectionToBoundary, "Returns the edge on the initial shape, of which the modified copy contains the edge section. section is coincident with a contiguous edge found by the function Perform. Use the function ContigousEdgeCouple to obtain a valid section. This information is useful for verification purposes, since it provides a means of determining the surface to which the contiguous edge belongs. Exceptions Standard_NoSuchObject if section is not coincident with a contiguous edge. Use the function ContigousEdgeCouple to obtain a valid section.", py::arg("section"));
cls_BRepOffsetAPI_FindContigousEdges.def("NbDegeneratedShapes", (Standard_Integer (BRepOffsetAPI_FindContigousEdges::*)() const) &BRepOffsetAPI_FindContigousEdges::NbDegeneratedShapes, "Gives the number of degenerated shapes");
cls_BRepOffsetAPI_FindContigousEdges.def("DegeneratedShape", (const TopoDS_Shape & (BRepOffsetAPI_FindContigousEdges::*)(const Standard_Integer) const) &BRepOffsetAPI_FindContigousEdges::DegeneratedShape, "Gives a degenerated shape", py::arg("index"));
cls_BRepOffsetAPI_FindContigousEdges.def("IsDegenerated", (Standard_Boolean (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_FindContigousEdges::IsDegenerated, "Indicates if a input shape is degenerated", py::arg("shape"));
cls_BRepOffsetAPI_FindContigousEdges.def("IsModified", (Standard_Boolean (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_FindContigousEdges::IsModified, "Returns true if the copy of the initial shape shape was modified by the function Perform (i.e. if one or more of its edges was broken down into contiguous and non-contiguous sections). Warning Returns false if shape is not one of the initial shapes added to this algorithm.", py::arg("shape"));
cls_BRepOffsetAPI_FindContigousEdges.def("Modified", (const TopoDS_Shape & (BRepOffsetAPI_FindContigousEdges::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_FindContigousEdges::Modified, "Gives a modifieded shape Raises NoSuchObject if shape has not been modified", py::arg("shape"));
cls_BRepOffsetAPI_FindContigousEdges.def("Dump", (void (BRepOffsetAPI_FindContigousEdges::*)() const) &BRepOffsetAPI_FindContigousEdges::Dump, "Dump properties of resulting shape.");

// Enums

}