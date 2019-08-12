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
#include <TopoDS_TVertex.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <BRep_ListOfPointRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <BRep_TVertex.hxx>
#include <Standard_Type.hxx>

void bind_BRep_TVertex(py::module &mod){

py::class_<BRep_TVertex, opencascade::handle<BRep_TVertex>, TopoDS_TVertex> cls_BRep_TVertex(mod, "BRep_TVertex", "The TVertex from BRep inherits from the TVertex from TopoDS. It contains the geometric data.");

// Constructors
cls_BRep_TVertex.def(py::init<>());

// Fields

// Methods
cls_BRep_TVertex.def("Tolerance", (Standard_Real (BRep_TVertex::*)() const) &BRep_TVertex::Tolerance, "None");
cls_BRep_TVertex.def("Tolerance", (void (BRep_TVertex::*)(const Standard_Real)) &BRep_TVertex::Tolerance, "None", py::arg("T"));
cls_BRep_TVertex.def("UpdateTolerance", (void (BRep_TVertex::*)(const Standard_Real)) &BRep_TVertex::UpdateTolerance, "Sets the tolerance to the max of <T> and the current tolerance.", py::arg("T"));
cls_BRep_TVertex.def("Pnt", (const gp_Pnt & (BRep_TVertex::*)() const) &BRep_TVertex::Pnt, "None");
cls_BRep_TVertex.def("Pnt", (void (BRep_TVertex::*)(const gp_Pnt &)) &BRep_TVertex::Pnt, "None", py::arg("P"));
cls_BRep_TVertex.def("Points", (const BRep_ListOfPointRepresentation & (BRep_TVertex::*)() const) &BRep_TVertex::Points, "None");
cls_BRep_TVertex.def("ChangePoints", (BRep_ListOfPointRepresentation & (BRep_TVertex::*)()) &BRep_TVertex::ChangePoints, "None");
cls_BRep_TVertex.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (BRep_TVertex::*)() const) &BRep_TVertex::EmptyCopy, "Returns a copy of the TShape with no sub-shapes.");
cls_BRep_TVertex.def_static("get_type_name_", (const char * (*)()) &BRep_TVertex::get_type_name, "None");
cls_BRep_TVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_TVertex::get_type_descriptor, "None");
cls_BRep_TVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_TVertex::*)() const) &BRep_TVertex::DynamicType, "None");

// Enums

}