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
#include <ShapeExtend_WireData.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <ShapeFix_WireSegment.hxx>

void bind_ShapeFix_WireSegment(py::module &mod){

py::class_<ShapeFix_WireSegment> cls_ShapeFix_WireSegment(mod, "ShapeFix_WireSegment", "This class is auxiliary class (data storage) used in ComposeShell. It is intended for representing segment of the wire (or whole wire). The segment itself is represented by ShapeExtend_WireData. In addition, some associated data necessary for computations are stored:");

// Constructors
cls_ShapeFix_WireSegment.def(py::init<>());
cls_ShapeFix_WireSegment.def(py::init<const opencascade::handle<ShapeExtend_WireData> &>(), py::arg("wire"));
cls_ShapeFix_WireSegment.def(py::init<const opencascade::handle<ShapeExtend_WireData> &, const TopAbs_Orientation>(), py::arg("wire"), py::arg("ori"));
// cls_ShapeFix_WireSegment.def(py::init<const TopoDS_Wire &>(), py::arg("wire"));
// cls_ShapeFix_WireSegment.def(py::init<const TopoDS_Wire &, const TopAbs_Orientation>(), py::arg("wire"), py::arg("ori"));

// Fields

// Methods
// cls_ShapeFix_WireSegment.def_static("operator new_", (void * (*)(size_t)) &ShapeFix_WireSegment::operator new, "None", py::arg("theSize"));
// cls_ShapeFix_WireSegment.def_static("operator delete_", (void (*)(void *)) &ShapeFix_WireSegment::operator delete, "None", py::arg("theAddress"));
// cls_ShapeFix_WireSegment.def_static("operator new[]_", (void * (*)(size_t)) &ShapeFix_WireSegment::operator new[], "None", py::arg("theSize"));
// cls_ShapeFix_WireSegment.def_static("operator delete[]_", (void (*)(void *)) &ShapeFix_WireSegment::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeFix_WireSegment.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeFix_WireSegment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeFix_WireSegment.def_static("operator delete_", (void (*)(void *, void *)) &ShapeFix_WireSegment::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeFix_WireSegment.def("Clear", (void (ShapeFix_WireSegment::*)()) &ShapeFix_WireSegment::Clear, "Clears all fields.");
cls_ShapeFix_WireSegment.def("Load", (void (ShapeFix_WireSegment::*)(const opencascade::handle<ShapeExtend_WireData> &)) &ShapeFix_WireSegment::Load, "Loads wire.", py::arg("wire"));
cls_ShapeFix_WireSegment.def("WireData", (const opencascade::handle<ShapeExtend_WireData> & (ShapeFix_WireSegment::*)() const) &ShapeFix_WireSegment::WireData, "Returns wire.");
cls_ShapeFix_WireSegment.def("Orientation", (void (ShapeFix_WireSegment::*)(const TopAbs_Orientation)) &ShapeFix_WireSegment::Orientation, "Sets orientation flag.", py::arg("ori"));
cls_ShapeFix_WireSegment.def("Orientation", (TopAbs_Orientation (ShapeFix_WireSegment::*)() const) &ShapeFix_WireSegment::Orientation, "Returns orientation flag.");
cls_ShapeFix_WireSegment.def("FirstVertex", (TopoDS_Vertex (ShapeFix_WireSegment::*)() const) &ShapeFix_WireSegment::FirstVertex, "Returns first vertex of the first edge in the wire (no dependance on Orientation()).");
cls_ShapeFix_WireSegment.def("LastVertex", (TopoDS_Vertex (ShapeFix_WireSegment::*)() const) &ShapeFix_WireSegment::LastVertex, "Returns last vertex of the last edge in the wire (no dependance on Orientation()).");
cls_ShapeFix_WireSegment.def("IsClosed", (Standard_Boolean (ShapeFix_WireSegment::*)() const) &ShapeFix_WireSegment::IsClosed, "Returns True if FirstVertex() == LastVertex()");
cls_ShapeFix_WireSegment.def("NbEdges", (Standard_Integer (ShapeFix_WireSegment::*)() const) &ShapeFix_WireSegment::NbEdges, "Returns Number of edges in the wire");
cls_ShapeFix_WireSegment.def("Edge", (TopoDS_Edge (ShapeFix_WireSegment::*)(const Standard_Integer) const) &ShapeFix_WireSegment::Edge, "Returns edge by given index in the wire", py::arg("i"));
cls_ShapeFix_WireSegment.def("SetEdge", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const TopoDS_Edge &)) &ShapeFix_WireSegment::SetEdge, "Replaces edge at index i by new one.", py::arg("i"), py::arg("edge"));
cls_ShapeFix_WireSegment.def("AddEdge", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const TopoDS_Edge &)) &ShapeFix_WireSegment::AddEdge, "Insert a new edge with index i and implicitly defined patch indices (indefinite patch). If i==0, edge is inserted at end of wire.", py::arg("i"), py::arg("edge"));
cls_ShapeFix_WireSegment.def("AddEdge", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const TopoDS_Edge &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::AddEdge, "Insert a new edge with index i and explicitly defined patch indices. If i==0, edge is inserted at end of wire.", py::arg("i"), py::arg("edge"), py::arg("iumin"), py::arg("iumax"), py::arg("ivmin"), py::arg("ivmax"));
cls_ShapeFix_WireSegment.def("SetPatchIndex", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::SetPatchIndex, "Set patch indices for edge i.", py::arg("i"), py::arg("iumin"), py::arg("iumax"), py::arg("ivmin"), py::arg("ivmax"));
cls_ShapeFix_WireSegment.def("DefineIUMin", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::DefineIUMin, "None", py::arg("i"), py::arg("iumin"));
cls_ShapeFix_WireSegment.def("DefineIUMax", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::DefineIUMax, "None", py::arg("i"), py::arg("iumax"));
cls_ShapeFix_WireSegment.def("DefineIVMin", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::DefineIVMin, "None", py::arg("i"), py::arg("ivmin"));
cls_ShapeFix_WireSegment.def("DefineIVMax", (void (ShapeFix_WireSegment::*)(const Standard_Integer, const Standard_Integer)) &ShapeFix_WireSegment::DefineIVMax, "Modify minimal or maximal patch index for edge i. The corresponding patch index for that edge is modified so as to satisfy eq. iumin <= myIUMin(i) <= myIUMax(i) <= iumax", py::arg("i"), py::arg("ivmax"));
cls_ShapeFix_WireSegment.def("GetPatchIndex", [](ShapeFix_WireSegment &self, const Standard_Integer i, Standard_Integer & iumin, Standard_Integer & iumax, Standard_Integer & ivmin, Standard_Integer & ivmax){ self.GetPatchIndex(i, iumin, iumax, ivmin, ivmax); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(iumin, iumax, ivmin, ivmax); }, "Returns patch indices for edge i.", py::arg("i"), py::arg("iumin"), py::arg("iumax"), py::arg("ivmin"), py::arg("ivmax"));
cls_ShapeFix_WireSegment.def("CheckPatchIndex", (Standard_Boolean (ShapeFix_WireSegment::*)(const Standard_Integer) const) &ShapeFix_WireSegment::CheckPatchIndex, "Checks patch indices for edge i to satisfy equations IUMin(i) <= IUMax(i) <= IUMin(i)+1", py::arg("i"));
cls_ShapeFix_WireSegment.def("SetVertex", (void (ShapeFix_WireSegment::*)(const TopoDS_Vertex &)) &ShapeFix_WireSegment::SetVertex, "None", py::arg("theVertex"));
cls_ShapeFix_WireSegment.def("GetVertex", (TopoDS_Vertex (ShapeFix_WireSegment::*)() const) &ShapeFix_WireSegment::GetVertex, "None");
cls_ShapeFix_WireSegment.def("IsVertex", (Standard_Boolean (ShapeFix_WireSegment::*)() const) &ShapeFix_WireSegment::IsVertex, "None");

// Enums

}