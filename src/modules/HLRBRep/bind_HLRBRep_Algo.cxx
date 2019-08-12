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
#include <HLRBRep_InternalAlgo.hxx>
#include <Standard_Handle.hxx>
#include <HLRBRep_Algo.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>

void bind_HLRBRep_Algo(py::module &mod){

py::class_<HLRBRep_Algo, opencascade::handle<HLRBRep_Algo>, HLRBRep_InternalAlgo> cls_HLRBRep_Algo(mod, "HLRBRep_Algo", "Inherited from InternalAlgo to provide methods with Shape from TopoDS. A framework to compute a shape as seen in a projection plane. This is done by calculating the visible and the hidden parts of the shape. HLRBRep_Algo works with three types of entity: - shapes to be visualized - edges in these shapes (these edges are the basic entities which will be visualized or hidden), and - faces in these shapes which hide the edges. HLRBRep_Algo is based on the principle of comparing each edge of the shape to be visualized with each of its faces, and calculating the visible and the hidden parts of each edge. For a given projection, HLRBRep_Algo calculates a set of lines characteristic of the object being represented. It is also used in conjunction with the HLRBRep_HLRToShape extraction utilities, which reconstruct a new, simplified shape from a selection of calculation results. This new shape is made up of edges, which represent the shape visualized in the projection. HLRBRep_Algo takes the shape itself into account whereas HLRBRep_PolyAlgo works with a polyhedral simplification of the shape. When you use HLRBRep_Algo, you obtain an exact result, whereas, when you use HLRBRep_PolyAlgo, you reduce computation time but obtain polygonal segments. In the case of complicated shapes, HLRBRep_Algo may be time-consuming. An HLRBRep_Algo object provides a framework for: - defining the point of view - identifying the shape or shapes to be visualized - calculating the outlines - calculating the visible and hidden lines of the shape. Warning - Superimposed lines are not eliminated by this algorithm. - There must be no unfinished objects inside the shape you wish to visualize. - Points are not treated. - Note that this is not the sort of algorithm used in generating shading, which calculates the visible and hidden parts of each face in a shape to be visualized by comparing each face in the shape with every other face in the same shape.");

// Constructors
cls_HLRBRep_Algo.def(py::init<>());
cls_HLRBRep_Algo.def(py::init<const opencascade::handle<HLRBRep_Algo> &>(), py::arg("A"));

// Fields

// Methods
cls_HLRBRep_Algo.def("Add", [](HLRBRep_Algo &self, const TopoDS_Shape & a0, const opencascade::handle<Standard_Transient> & a1) -> void { return self.Add(a0, a1); });
cls_HLRBRep_Algo.def("Add", (void (HLRBRep_Algo::*)(const TopoDS_Shape &, const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &HLRBRep_Algo::Add, "add the Shape <S>.", py::arg("S"), py::arg("SData"), py::arg("nbIso"));
cls_HLRBRep_Algo.def("Add", [](HLRBRep_Algo &self, const TopoDS_Shape & a0) -> void { return self.Add(a0); });
cls_HLRBRep_Algo.def("Add", (void (HLRBRep_Algo::*)(const TopoDS_Shape &, const Standard_Integer)) &HLRBRep_Algo::Add, "Adds the shape S to this framework, and specifies the number of isoparameters nbiso desired in visualizing S. You may add as many shapes as you wish. Use the function Add once for each shape.", py::arg("S"), py::arg("nbIso"));
cls_HLRBRep_Algo.def("Index", (Standard_Integer (HLRBRep_Algo::*)(const TopoDS_Shape &)) &HLRBRep_Algo::Index, "return the index of the Shape <S> and return 0 if the Shape <S> is not found.", py::arg("S"));
cls_HLRBRep_Algo.def("OutLinedShapeNullify", (void (HLRBRep_Algo::*)()) &HLRBRep_Algo::OutLinedShapeNullify, "nullify all the results of OutLiner from HLRTopoBRep.");
cls_HLRBRep_Algo.def_static("get_type_name_", (const char * (*)()) &HLRBRep_Algo::get_type_name, "None");
cls_HLRBRep_Algo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_Algo::get_type_descriptor, "None");
cls_HLRBRep_Algo.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_Algo::*)() const) &HLRBRep_Algo::DynamicType, "None");

// Enums

}