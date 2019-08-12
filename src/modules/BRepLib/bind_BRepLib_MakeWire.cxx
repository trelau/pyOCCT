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
#include <BRepLib_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepLib_WireError.hxx>
#include <TopoDS_Vertex.hxx>
#include <NCollection_UBTree.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRepLib_MakeWire.hxx>
#include <gp_Pnt.hxx>
#include <NCollection_List.hxx>
#include <NCollection_DataMap.hxx>

void bind_BRepLib_MakeWire(py::module &mod){

py::class_<BRepLib_MakeWire, std::unique_ptr<BRepLib_MakeWire, Deleter<BRepLib_MakeWire>>, BRepLib_MakeShape> cls_BRepLib_MakeWire(mod, "BRepLib_MakeWire", "Provides methods to build wires.");

// Constructors
cls_BRepLib_MakeWire.def(py::init<>());
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &>(), py::arg("E"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("E1"), py::arg("E2"), py::arg("E3"), py::arg("E4"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Wire &>(), py::arg("W"));
cls_BRepLib_MakeWire.def(py::init<const TopoDS_Wire &, const TopoDS_Edge &>(), py::arg("W"), py::arg("E"));

// Fields

// Methods
// cls_BRepLib_MakeWire.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeWire::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeWire.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeWire::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeWire.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeWire::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeWire.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeWire::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeWire.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeWire::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeWire.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeWire::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeWire.def("Add", (void (BRepLib_MakeWire::*)(const TopoDS_Edge &)) &BRepLib_MakeWire::Add, "Add the edge <E> to the current wire.", py::arg("E"));
cls_BRepLib_MakeWire.def("Add", (void (BRepLib_MakeWire::*)(const TopoDS_Wire &)) &BRepLib_MakeWire::Add, "Add the edges of <W> to the current wire.", py::arg("W"));
cls_BRepLib_MakeWire.def("Add", (void (BRepLib_MakeWire::*)(const TopTools_ListOfShape &)) &BRepLib_MakeWire::Add, "Add the edges of <L> to the current wire. The edges are not to be consecutive. But they are to be all connected geometrically or topologically.", py::arg("L"));
cls_BRepLib_MakeWire.def("Error", (BRepLib_WireError (BRepLib_MakeWire::*)() const) &BRepLib_MakeWire::Error, "None");
cls_BRepLib_MakeWire.def("Wire", (const TopoDS_Wire & (BRepLib_MakeWire::*)()) &BRepLib_MakeWire::Wire, "Returns the new wire.");
cls_BRepLib_MakeWire.def("Edge", (const TopoDS_Edge & (BRepLib_MakeWire::*)() const) &BRepLib_MakeWire::Edge, "Returns the last edge added to the wire.");
cls_BRepLib_MakeWire.def("Vertex", (const TopoDS_Vertex & (BRepLib_MakeWire::*)() const) &BRepLib_MakeWire::Vertex, "Returns the last connecting vertex.");

// Enums

}