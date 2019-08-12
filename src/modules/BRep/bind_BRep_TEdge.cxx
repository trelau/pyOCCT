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
#include <TopoDS_TEdge.hxx>
#include <Standard_TypeDef.hxx>
#include <BRep_ListOfCurveRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <BRep_TEdge.hxx>
#include <Standard_Type.hxx>

void bind_BRep_TEdge(py::module &mod){

py::class_<BRep_TEdge, opencascade::handle<BRep_TEdge>, TopoDS_TEdge> cls_BRep_TEdge(mod, "BRep_TEdge", "The TEdge from BRep is inherited from the TEdge from TopoDS. It contains the geometric data.");

// Constructors
cls_BRep_TEdge.def(py::init<>());

// Fields

// Methods
cls_BRep_TEdge.def("Tolerance", (Standard_Real (BRep_TEdge::*)() const) &BRep_TEdge::Tolerance, "None");
cls_BRep_TEdge.def("Tolerance", (void (BRep_TEdge::*)(const Standard_Real)) &BRep_TEdge::Tolerance, "None", py::arg("T"));
cls_BRep_TEdge.def("UpdateTolerance", (void (BRep_TEdge::*)(const Standard_Real)) &BRep_TEdge::UpdateTolerance, "Sets the tolerance to the max of <T> and the current tolerance.", py::arg("T"));
cls_BRep_TEdge.def("SameParameter", (Standard_Boolean (BRep_TEdge::*)() const) &BRep_TEdge::SameParameter, "None");
cls_BRep_TEdge.def("SameParameter", (void (BRep_TEdge::*)(const Standard_Boolean)) &BRep_TEdge::SameParameter, "None", py::arg("S"));
cls_BRep_TEdge.def("SameRange", (Standard_Boolean (BRep_TEdge::*)() const) &BRep_TEdge::SameRange, "None");
cls_BRep_TEdge.def("SameRange", (void (BRep_TEdge::*)(const Standard_Boolean)) &BRep_TEdge::SameRange, "None", py::arg("S"));
cls_BRep_TEdge.def("Degenerated", (Standard_Boolean (BRep_TEdge::*)() const) &BRep_TEdge::Degenerated, "None");
cls_BRep_TEdge.def("Degenerated", (void (BRep_TEdge::*)(const Standard_Boolean)) &BRep_TEdge::Degenerated, "None", py::arg("S"));
cls_BRep_TEdge.def("Curves", (const BRep_ListOfCurveRepresentation & (BRep_TEdge::*)() const) &BRep_TEdge::Curves, "None");
cls_BRep_TEdge.def("ChangeCurves", (BRep_ListOfCurveRepresentation & (BRep_TEdge::*)()) &BRep_TEdge::ChangeCurves, "None");
cls_BRep_TEdge.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (BRep_TEdge::*)() const) &BRep_TEdge::EmptyCopy, "Returns a copy of the TShape with no sub-shapes.");
cls_BRep_TEdge.def_static("get_type_name_", (const char * (*)()) &BRep_TEdge::get_type_name, "None");
cls_BRep_TEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_TEdge::get_type_descriptor, "None");
cls_BRep_TEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_TEdge::*)() const) &BRep_TEdge::DynamicType, "None");

// Enums

}