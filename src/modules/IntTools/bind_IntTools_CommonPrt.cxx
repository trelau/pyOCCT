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
#include <IntTools_CommonPrt.hxx>
#include <TopoDS_Edge.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <IntTools_Range.hxx>
#include <Standard_TypeDef.hxx>
#include <IntTools_SequenceOfRanges.hxx>
#include <gp_Pnt.hxx>

void bind_IntTools_CommonPrt(py::module &mod){

py::class_<IntTools_CommonPrt, std::unique_ptr<IntTools_CommonPrt, Deleter<IntTools_CommonPrt>>> cls_IntTools_CommonPrt(mod, "IntTools_CommonPrt", "The class is to describe a common part between two edges in 3-d space.");

// Constructors
cls_IntTools_CommonPrt.def(py::init<>());
cls_IntTools_CommonPrt.def(py::init<const IntTools_CommonPrt &>(), py::arg("aCPrt"));

// Fields

// Methods
// cls_IntTools_CommonPrt.def_static("operator new_", (void * (*)(size_t)) &IntTools_CommonPrt::operator new, "None", py::arg("theSize"));
// cls_IntTools_CommonPrt.def_static("operator delete_", (void (*)(void *)) &IntTools_CommonPrt::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_CommonPrt.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_CommonPrt::operator new[], "None", py::arg("theSize"));
// cls_IntTools_CommonPrt.def_static("operator delete[]_", (void (*)(void *)) &IntTools_CommonPrt::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_CommonPrt.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_CommonPrt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_CommonPrt.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_CommonPrt::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_CommonPrt.def("Assign", (IntTools_CommonPrt & (IntTools_CommonPrt::*)(const IntTools_CommonPrt &)) &IntTools_CommonPrt::Assign, "None", py::arg("Other"));
// cls_IntTools_CommonPrt.def("operator=", (IntTools_CommonPrt & (IntTools_CommonPrt::*)(const IntTools_CommonPrt &)) &IntTools_CommonPrt::operator=, "None", py::arg("Other"));
cls_IntTools_CommonPrt.def("SetEdge1", (void (IntTools_CommonPrt::*)(const TopoDS_Edge &)) &IntTools_CommonPrt::SetEdge1, "Sets the first edge.", py::arg("anE"));
cls_IntTools_CommonPrt.def("SetEdge2", (void (IntTools_CommonPrt::*)(const TopoDS_Edge &)) &IntTools_CommonPrt::SetEdge2, "Sets the second edge.", py::arg("anE"));
cls_IntTools_CommonPrt.def("SetType", (void (IntTools_CommonPrt::*)(const TopAbs_ShapeEnum)) &IntTools_CommonPrt::SetType, "Sets the type of the common part Vertex or Edge", py::arg("aType"));
cls_IntTools_CommonPrt.def("SetRange1", (void (IntTools_CommonPrt::*)(const IntTools_Range &)) &IntTools_CommonPrt::SetRange1, "Sets the range of first edge.", py::arg("aR"));
cls_IntTools_CommonPrt.def("SetRange1", (void (IntTools_CommonPrt::*)(const Standard_Real, const Standard_Real)) &IntTools_CommonPrt::SetRange1, "Sets the range of first edge.", py::arg("tf"), py::arg("tl"));
cls_IntTools_CommonPrt.def("AppendRange2", (void (IntTools_CommonPrt::*)(const IntTools_Range &)) &IntTools_CommonPrt::AppendRange2, "Appends the range of second edge.", py::arg("aR"));
cls_IntTools_CommonPrt.def("AppendRange2", (void (IntTools_CommonPrt::*)(const Standard_Real, const Standard_Real)) &IntTools_CommonPrt::AppendRange2, "Appends the range of second edge.", py::arg("tf"), py::arg("tl"));
cls_IntTools_CommonPrt.def("SetVertexParameter1", (void (IntTools_CommonPrt::*)(const Standard_Real)) &IntTools_CommonPrt::SetVertexParameter1, "Sets a parameter of first vertex", py::arg("tV"));
cls_IntTools_CommonPrt.def("SetVertexParameter2", (void (IntTools_CommonPrt::*)(const Standard_Real)) &IntTools_CommonPrt::SetVertexParameter2, "Sets a parameter of second vertex", py::arg("tV"));
cls_IntTools_CommonPrt.def("Edge1", (const TopoDS_Edge & (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Edge1, "Returns the first edge.");
cls_IntTools_CommonPrt.def("Edge2", (const TopoDS_Edge & (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Edge2, "Returns the second edge");
cls_IntTools_CommonPrt.def("Type", (TopAbs_ShapeEnum (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Type, "Returns the type of the common part");
cls_IntTools_CommonPrt.def("Range1", (const IntTools_Range & (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Range1, "Returns the range of first edge");
cls_IntTools_CommonPrt.def("Range1", [](IntTools_CommonPrt &self, Standard_Real & tf, Standard_Real & tl){ self.Range1(tf, tl); return std::tuple<Standard_Real &, Standard_Real &>(tf, tl); }, "Returns the range of first edge.", py::arg("tf"), py::arg("tl"));
cls_IntTools_CommonPrt.def("Ranges2", (const IntTools_SequenceOfRanges & (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::Ranges2, "Returns the ranges of second edge.");
cls_IntTools_CommonPrt.def("ChangeRanges2", (IntTools_SequenceOfRanges & (IntTools_CommonPrt::*)()) &IntTools_CommonPrt::ChangeRanges2, "Returns the ranges of second edge.");
cls_IntTools_CommonPrt.def("VertexParameter1", (Standard_Real (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::VertexParameter1, "Returns parameter of first vertex");
cls_IntTools_CommonPrt.def("VertexParameter2", (Standard_Real (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::VertexParameter2, "Returns parameter of second vertex");
cls_IntTools_CommonPrt.def("Copy", (void (IntTools_CommonPrt::*)(IntTools_CommonPrt &) const) &IntTools_CommonPrt::Copy, "Copies me to anOther", py::arg("anOther"));
cls_IntTools_CommonPrt.def("AllNullFlag", (Standard_Boolean (IntTools_CommonPrt::*)() const) &IntTools_CommonPrt::AllNullFlag, "Modifier");
cls_IntTools_CommonPrt.def("SetAllNullFlag", (void (IntTools_CommonPrt::*)(const Standard_Boolean)) &IntTools_CommonPrt::SetAllNullFlag, "Selector", py::arg("aFlag"));
cls_IntTools_CommonPrt.def("SetBoundingPoints", (void (IntTools_CommonPrt::*)(const gp_Pnt &, const gp_Pnt &)) &IntTools_CommonPrt::SetBoundingPoints, "Modifier", py::arg("aP1"), py::arg("aP2"));
cls_IntTools_CommonPrt.def("BoundingPoints", (void (IntTools_CommonPrt::*)(gp_Pnt &, gp_Pnt &) const) &IntTools_CommonPrt::BoundingPoints, "Selector", py::arg("aP1"), py::arg("aP2"));

// Enums

}