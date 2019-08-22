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
#include <TopoDS_Compound.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <ShapeAnalysis_FreeBounds.hxx>

void bind_ShapeAnalysis_FreeBounds(py::module &mod){

py::class_<ShapeAnalysis_FreeBounds> cls_ShapeAnalysis_FreeBounds(mod, "ShapeAnalysis_FreeBounds", "This class is intended to output free bounds of the shape (free bounds are the wires consisting of edges referenced by the only face). This class works on two distinct types of shapes when analyzing their free bounds: 1. compound of faces. Analyzer of sewing algorithm (BRepAlgo_Sewing) is used for for forecasting free bounds that would be obtained after performing sewing 2. compound of shells. Actual free bounds (edges shared by the only face in the shell) are output in this case. ShapeAnalysis_Shell is used for that.");

// Constructors
cls_ShapeAnalysis_FreeBounds.def(py::init<>());
cls_ShapeAnalysis_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("shape"), py::arg("toler"));
cls_ShapeAnalysis_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean>(), py::arg("shape"), py::arg("toler"), py::arg("splitclosed"));
cls_ShapeAnalysis_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("shape"), py::arg("toler"), py::arg("splitclosed"), py::arg("splitopen"));
cls_ShapeAnalysis_FreeBounds.def(py::init<const TopoDS_Shape &>(), py::arg("shape"));
cls_ShapeAnalysis_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("shape"), py::arg("splitclosed"));
cls_ShapeAnalysis_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("shape"), py::arg("splitclosed"), py::arg("splitopen"));
cls_ShapeAnalysis_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("shape"), py::arg("splitclosed"), py::arg("splitopen"), py::arg("checkinternaledges"));

// Fields

// Methods
// cls_ShapeAnalysis_FreeBounds.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_FreeBounds::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_FreeBounds.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_FreeBounds::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_FreeBounds.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_FreeBounds::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_FreeBounds.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_FreeBounds::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_FreeBounds.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_FreeBounds::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_FreeBounds.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_FreeBounds::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_FreeBounds.def("GetClosedWires", (const TopoDS_Compound & (ShapeAnalysis_FreeBounds::*)() const) &ShapeAnalysis_FreeBounds::GetClosedWires, "Returns compound of closed wires out of free edges.");
cls_ShapeAnalysis_FreeBounds.def("GetOpenWires", (const TopoDS_Compound & (ShapeAnalysis_FreeBounds::*)() const) &ShapeAnalysis_FreeBounds::GetOpenWires, "Returns compound of open wires out of free edges.");
cls_ShapeAnalysis_FreeBounds.def_static("ConnectEdgesToWires_", (void (*)(opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Real, const Standard_Boolean, opencascade::handle<TopTools_HSequenceOfShape> &)) &ShapeAnalysis_FreeBounds::ConnectEdgesToWires, "Builds sequnce of <wires> out of sequence of not sorted <edges>. Tries to build wires of maximum length. Building a wire is stopped when no edges can be connected to it at its head or at its tail.", py::arg("edges"), py::arg("toler"), py::arg("shared"), py::arg("wires"));
cls_ShapeAnalysis_FreeBounds.def_static("ConnectWiresToWires_", (void (*)(opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Real, const Standard_Boolean, opencascade::handle<TopTools_HSequenceOfShape> &)) &ShapeAnalysis_FreeBounds::ConnectWiresToWires, "None", py::arg("iwires"), py::arg("toler"), py::arg("shared"), py::arg("owires"));
cls_ShapeAnalysis_FreeBounds.def_static("ConnectWiresToWires_", (void (*)(opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Real, const Standard_Boolean, opencascade::handle<TopTools_HSequenceOfShape> &, TopTools_DataMapOfShapeShape &)) &ShapeAnalysis_FreeBounds::ConnectWiresToWires, "Builds sequnce of <owires> out of sequence of not sorted <iwires>. Tries to build wires of maximum length. Building a wire is stopped when no wires can be connected to it at its head or at its tail.", py::arg("iwires"), py::arg("toler"), py::arg("shared"), py::arg("owires"), py::arg("vertices"));
cls_ShapeAnalysis_FreeBounds.def_static("SplitWires_", (void (*)(const opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Real, const Standard_Boolean, opencascade::handle<TopTools_HSequenceOfShape> &, opencascade::handle<TopTools_HSequenceOfShape> &)) &ShapeAnalysis_FreeBounds::SplitWires, "Extracts closed sub-wires out of <wires> and adds them to <closed>, open wires remained after extraction are put into <open>. If <shared> is True extraction is performed only when edges share the same vertex. If <shared> is False connection is performed only when ends of the edges are at distance less than <toler>.", py::arg("wires"), py::arg("toler"), py::arg("shared"), py::arg("closed"), py::arg("open"));
cls_ShapeAnalysis_FreeBounds.def_static("DispatchWires_", (void (*)(const opencascade::handle<TopTools_HSequenceOfShape> &, TopoDS_Compound &, TopoDS_Compound &)) &ShapeAnalysis_FreeBounds::DispatchWires, "Dispatches sequence of <wires> into two compounds <closed> for closed wires and <open> for open wires. If a compound is not empty wires are added into it.", py::arg("wires"), py::arg("closed"), py::arg("open"));

// Enums

}