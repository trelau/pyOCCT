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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepBuilderAPI_WireError.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepLib_MakeWire.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>

void bind_BRepBuilderAPI_MakeWire(py::module &mod){

py::class_<BRepBuilderAPI_MakeWire, std::unique_ptr<BRepBuilderAPI_MakeWire>, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeWire(mod, "BRepBuilderAPI_MakeWire", "Describes functions to build wires from edges. A wire can be built from any number of edges. To build a wire you first initialize the construction, then add edges in sequence. An unlimited number of edges can be added. The initialization of construction is done with: - no edge (an empty wire), or - edges of an existing wire, or - up to four connectable edges. In order to be added to a wire under construction, an edge (unless it is the first one) must satisfy the following condition: one of its vertices must be geometrically coincident with one of the vertices of the wire (provided that the highest tolerance factor is assigned to the two vertices). It could also be the same vertex. - The given edge is shared by the wire if it contains: - two vertices, identical to two vertices of the wire under construction (a general case of the wire closure), or - one vertex, identical to a vertex of the wire under construction; the other vertex not being geometrically coincident with another vertex of the wire. - In other cases, when one of the vertices of the edge is simply geometrically coincident with a vertex of the wire under construction (provided that the highest tolerance factor is assigned to the two vertices), the given edge is first copied and the coincident vertex is replaced in this new edge, by the coincident vertex of the wire. Note: it is possible to build non manifold wires using this construction tool. A MakeWire object provides a framework for: - initializing the construction of a wire, - adding edges to the wire under construction, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_MakeWire.def(py::init<>());
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Edge &>(), py::arg("E"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"), py::arg("E4"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepBuilderAPI_MakeWire.def(py::init<const TopoDS_Wire &, const TopoDS_Edge &>(), py::arg("W"), py::arg("E"));

// Fields

// Methods
// cls_BRepBuilderAPI_MakeWire.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeWire::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeWire::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeWire::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeWire::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeWire::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeWire.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeWire::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeWire.def("Add", (void (BRepBuilderAPI_MakeWire::*)(const TopoDS_Edge &)) &BRepBuilderAPI_MakeWire::Add, "Adds the edge E to the wire under construction. E must be connectable to the wire under construction, and, unless it is the first edge of the wire, must satisfy the following condition: one of its vertices must be geometrically coincident with one of the vertices of the wire (provided that the highest tolerance factor is assigned to the two vertices). It could also be the same vertex. Warning If E is not connectable to the wire under construction it is not added. The function Error will return BRepBuilderAPI_DisconnectedWire, the function IsDone will return false and the function Wire will raise an error, until a new connectable edge is added.", py::arg("E"));
cls_BRepBuilderAPI_MakeWire.def("Add", (void (BRepBuilderAPI_MakeWire::*)(const TopoDS_Wire &)) &BRepBuilderAPI_MakeWire::Add, "Add the edges of <W> to the current wire.", py::arg("W"));
cls_BRepBuilderAPI_MakeWire.def("Add", (void (BRepBuilderAPI_MakeWire::*)(const TopTools_ListOfShape &)) &BRepBuilderAPI_MakeWire::Add, "Adds the edges of <L> to the current wire. The edges are not to be consecutive. But they are to be all connected geometrically or topologically. If some of them are not connected the Status give DisconnectedWire but the 'Maker' is Done() and you can get the partial result. (ie connected to the first edgeof the list <L>)", py::arg("L"));
cls_BRepBuilderAPI_MakeWire.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeWire::*)() const) &BRepBuilderAPI_MakeWire::IsDone, "Returns true if this algorithm contains a valid wire. IsDone returns false if: - there are no edges in the wire, or - the last edge which you tried to add was not connectable.");
cls_BRepBuilderAPI_MakeWire.def("Error", (BRepBuilderAPI_WireError (BRepBuilderAPI_MakeWire::*)() const) &BRepBuilderAPI_MakeWire::Error, "Returns the construction status - BRepBuilderAPI_WireDone if the wire is built, or - another value of the BRepBuilderAPI_WireError enumeration indicating why the construction failed.");
cls_BRepBuilderAPI_MakeWire.def("Wire", (const TopoDS_Wire & (BRepBuilderAPI_MakeWire::*)()) &BRepBuilderAPI_MakeWire::Wire, "Returns the constructed wire; or the part of the wire under construction already built. Exceptions StdFail_NotDone if a wire is not built.");
cls_BRepBuilderAPI_MakeWire.def("Edge", (const TopoDS_Edge & (BRepBuilderAPI_MakeWire::*)() const) &BRepBuilderAPI_MakeWire::Edge, "Returns the last edge added to the wire under construction. Warning - This edge can be different from the original one (the argument of the function Add, for instance,) - A null edge is returned if there are no edges in the wire under construction, or if the last edge which you tried to add was not connectable..");
cls_BRepBuilderAPI_MakeWire.def("Vertex", (const TopoDS_Vertex & (BRepBuilderAPI_MakeWire::*)() const) &BRepBuilderAPI_MakeWire::Vertex, "Returns the last vertex of the last edge added to the wire under construction. Warning A null vertex is returned if there are no edges in the wire under construction, or if the last edge which you tried to add was not connectableR");

// Enums

}