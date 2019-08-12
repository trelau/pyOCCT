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
#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <LocOpe_WiresOnShape.hxx>
#include <Standard_Type.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>

void bind_LocOpe_WiresOnShape(py::module &mod){

py::class_<LocOpe_WiresOnShape, opencascade::handle<LocOpe_WiresOnShape>, Standard_Transient> cls_LocOpe_WiresOnShape(mod, "LocOpe_WiresOnShape", "None");

// Constructors
cls_LocOpe_WiresOnShape.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
cls_LocOpe_WiresOnShape.def("Init", (void (LocOpe_WiresOnShape::*)(const TopoDS_Shape &)) &LocOpe_WiresOnShape::Init, "None", py::arg("S"));
cls_LocOpe_WiresOnShape.def("Add", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopTools_SequenceOfShape &)) &LocOpe_WiresOnShape::Add, "Add splitting edges or wires for whole initial shape withot additional specification edge->face, edge->edge This method puts edge on the corresponding faces from initial shape", py::arg("theEdges"));
cls_LocOpe_WiresOnShape.def("SetCheckInterior", (void (LocOpe_WiresOnShape::*)(const Standard_Boolean)) &LocOpe_WiresOnShape::SetCheckInterior, "Set the flag of check internal intersections default value is True (to check)", py::arg("ToCheckInterior"));
cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Wire &, const TopoDS_Face &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("W"), py::arg("F"));
cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Compound &, const TopoDS_Face &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("Comp"), py::arg("F"));
cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Edge &, const TopoDS_Face &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("E"), py::arg("F"));
cls_LocOpe_WiresOnShape.def("Bind", (void (LocOpe_WiresOnShape::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &LocOpe_WiresOnShape::Bind, "None", py::arg("EfromW"), py::arg("EonFace"));
cls_LocOpe_WiresOnShape.def("BindAll", (void (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::BindAll, "None");
cls_LocOpe_WiresOnShape.def("IsDone", (Standard_Boolean (LocOpe_WiresOnShape::*)() const) &LocOpe_WiresOnShape::IsDone, "None");
cls_LocOpe_WiresOnShape.def("InitEdgeIterator", (void (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::InitEdgeIterator, "None");
cls_LocOpe_WiresOnShape.def("MoreEdge", (Standard_Boolean (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::MoreEdge, "None");
cls_LocOpe_WiresOnShape.def("Edge", (TopoDS_Edge (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::Edge, "None");
cls_LocOpe_WiresOnShape.def("OnFace", (TopoDS_Face (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::OnFace, "Returns the face of the shape on which the current edge is projected.");
cls_LocOpe_WiresOnShape.def("OnEdge", (Standard_Boolean (LocOpe_WiresOnShape::*)(TopoDS_Edge &)) &LocOpe_WiresOnShape::OnEdge, "If the current edge is projected on an edge, returns <Standard_True> and sets the value of <E>. Otherwise, returns <Standard_False>.", py::arg("E"));
cls_LocOpe_WiresOnShape.def("NextEdge", (void (LocOpe_WiresOnShape::*)()) &LocOpe_WiresOnShape::NextEdge, "None");
cls_LocOpe_WiresOnShape.def("OnVertex", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopoDS_Vertex &, TopoDS_Vertex &)) &LocOpe_WiresOnShape::OnVertex, "None", py::arg("Vwire"), py::arg("Vshape"));
cls_LocOpe_WiresOnShape.def("OnEdge", [](LocOpe_WiresOnShape &self, const TopoDS_Vertex & V, TopoDS_Edge & E, Standard_Real & P){ Standard_Boolean rv = self.OnEdge(V, E, P); return std::tuple<Standard_Boolean, Standard_Real &>(rv, P); }, "If the vertex <V> lies on an edge of the original shape, returns <Standard_True> and sets the concerned edge in <E>, and the parameter on the edge in <P>. Else returns <Standard_False>.", py::arg("V"), py::arg("E"), py::arg("P"));
cls_LocOpe_WiresOnShape.def("OnEdge", [](LocOpe_WiresOnShape &self, const TopoDS_Vertex & V, const TopoDS_Edge & EdgeFrom, TopoDS_Edge & E, Standard_Real & P){ Standard_Boolean rv = self.OnEdge(V, EdgeFrom, E, P); return std::tuple<Standard_Boolean, Standard_Real &>(rv, P); }, "If the vertex <V> lies on an edge of the original shape, returns <Standard_True> and sets the concerned edge in <E>, and the parameter on the edge in <P>. Else returns <Standard_False>.", py::arg("V"), py::arg("EdgeFrom"), py::arg("E"), py::arg("P"));
cls_LocOpe_WiresOnShape.def("IsFaceWithSection", (Standard_Boolean (LocOpe_WiresOnShape::*)(const TopoDS_Shape &) const) &LocOpe_WiresOnShape::IsFaceWithSection, "tells is the face to be split by section or not", py::arg("aFace"));
cls_LocOpe_WiresOnShape.def_static("get_type_name_", (const char * (*)()) &LocOpe_WiresOnShape::get_type_name, "None");
cls_LocOpe_WiresOnShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LocOpe_WiresOnShape::get_type_descriptor, "None");
cls_LocOpe_WiresOnShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (LocOpe_WiresOnShape::*)() const) &LocOpe_WiresOnShape::DynamicType, "None");

// Enums

}