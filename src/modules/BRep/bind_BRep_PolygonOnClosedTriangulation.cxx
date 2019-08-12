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
#include <BRep_PolygonOnTriangulation.hxx>
#include <Standard_Handle.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Triangulation.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <BRep_PolygonOnClosedTriangulation.hxx>
#include <Standard_Type.hxx>

void bind_BRep_PolygonOnClosedTriangulation(py::module &mod){

py::class_<BRep_PolygonOnClosedTriangulation, opencascade::handle<BRep_PolygonOnClosedTriangulation>, BRep_PolygonOnTriangulation> cls_BRep_PolygonOnClosedTriangulation(mod, "BRep_PolygonOnClosedTriangulation", "A representation by two arrays of nodes on a triangulation.");

// Constructors
cls_BRep_PolygonOnClosedTriangulation.def(py::init<const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &>(), py::arg("P1"), py::arg("P2"), py::arg("Tr"), py::arg("L"));

// Fields

// Methods
cls_BRep_PolygonOnClosedTriangulation.def("IsPolygonOnClosedTriangulation", (Standard_Boolean (BRep_PolygonOnClosedTriangulation::*)() const) &BRep_PolygonOnClosedTriangulation::IsPolygonOnClosedTriangulation, "Returns True.");
cls_BRep_PolygonOnClosedTriangulation.def("PolygonOnTriangulation2", (void (BRep_PolygonOnClosedTriangulation::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRep_PolygonOnClosedTriangulation::PolygonOnTriangulation2, "None", py::arg("P2"));
cls_BRep_PolygonOnClosedTriangulation.def("PolygonOnTriangulation2", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRep_PolygonOnClosedTriangulation::*)() const) &BRep_PolygonOnClosedTriangulation::PolygonOnTriangulation2, "None");
cls_BRep_PolygonOnClosedTriangulation.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_PolygonOnClosedTriangulation::*)() const) &BRep_PolygonOnClosedTriangulation::Copy, "Return a copy of this representation.");
cls_BRep_PolygonOnClosedTriangulation.def_static("get_type_name_", (const char * (*)()) &BRep_PolygonOnClosedTriangulation::get_type_name, "None");
cls_BRep_PolygonOnClosedTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PolygonOnClosedTriangulation::get_type_descriptor, "None");
cls_BRep_PolygonOnClosedTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PolygonOnClosedTriangulation::*)() const) &BRep_PolygonOnClosedTriangulation::DynamicType, "None");

// Enums

}