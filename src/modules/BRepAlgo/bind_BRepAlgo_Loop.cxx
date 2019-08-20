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
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepAlgo_Loop.hxx>

void bind_BRepAlgo_Loop(py::module &mod){

py::class_<BRepAlgo_Loop, std::unique_ptr<BRepAlgo_Loop>> cls_BRepAlgo_Loop(mod, "BRepAlgo_Loop", "Builds the loops from a set of edges on a face.");

// Constructors
cls_BRepAlgo_Loop.def(py::init<>());

// Fields

// Methods
// cls_BRepAlgo_Loop.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_Loop::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_Loop.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_Loop::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_Loop.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_Loop::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_Loop.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_Loop::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_Loop.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_Loop::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_Loop.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_Loop::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo_Loop.def("Init", (void (BRepAlgo_Loop::*)(const TopoDS_Face &)) &BRepAlgo_Loop::Init, "Init with <F> the set of edges must have pcurves on <F>.", py::arg("F"));
cls_BRepAlgo_Loop.def("AddEdge", (void (BRepAlgo_Loop::*)(TopoDS_Edge &, const TopTools_ListOfShape &)) &BRepAlgo_Loop::AddEdge, "Add E with <LV>. <E> will be copied and trim by vertices in <LV>.", py::arg("E"), py::arg("LV"));
cls_BRepAlgo_Loop.def("AddConstEdge", (void (BRepAlgo_Loop::*)(const TopoDS_Edge &)) &BRepAlgo_Loop::AddConstEdge, "Add <E> as const edge, E can be in the result.", py::arg("E"));
cls_BRepAlgo_Loop.def("AddConstEdges", (void (BRepAlgo_Loop::*)(const TopTools_ListOfShape &)) &BRepAlgo_Loop::AddConstEdges, "Add <LE> as a set of const edges.", py::arg("LE"));
cls_BRepAlgo_Loop.def("Perform", (void (BRepAlgo_Loop::*)()) &BRepAlgo_Loop::Perform, "Make loops.");
cls_BRepAlgo_Loop.def("CutEdge", (void (BRepAlgo_Loop::*)(const TopoDS_Edge &, const TopTools_ListOfShape &, TopTools_ListOfShape &) const) &BRepAlgo_Loop::CutEdge, "Cut the edge <E> in several edges <NE> on the vertices<VonE>.", py::arg("E"), py::arg("VonE"), py::arg("NE"));
cls_BRepAlgo_Loop.def("NewWires", (const TopTools_ListOfShape & (BRepAlgo_Loop::*)() const) &BRepAlgo_Loop::NewWires, "Returns the list of wires performed. can be an empty list.");
cls_BRepAlgo_Loop.def("WiresToFaces", (void (BRepAlgo_Loop::*)()) &BRepAlgo_Loop::WiresToFaces, "Build faces from the wires result.");
cls_BRepAlgo_Loop.def("NewFaces", (const TopTools_ListOfShape & (BRepAlgo_Loop::*)() const) &BRepAlgo_Loop::NewFaces, "Returns the list of faces. Warning: The method <WiresToFaces> as to be called before. can be an empty list.");
cls_BRepAlgo_Loop.def("NewEdges", (const TopTools_ListOfShape & (BRepAlgo_Loop::*)(const TopoDS_Edge &) const) &BRepAlgo_Loop::NewEdges, "Returns the list of new edges built from an edge <E> it can be an empty list.", py::arg("E"));
cls_BRepAlgo_Loop.def("GetVerticesForSubstitute", (void (BRepAlgo_Loop::*)(TopTools_DataMapOfShapeShape &) const) &BRepAlgo_Loop::GetVerticesForSubstitute, "Returns the datamap of vertices with their substitutes.", py::arg("VerVerMap"));
cls_BRepAlgo_Loop.def("VerticesForSubstitute", (void (BRepAlgo_Loop::*)(TopTools_DataMapOfShapeShape &)) &BRepAlgo_Loop::VerticesForSubstitute, "None", py::arg("VerVerMap"));

// Enums

}