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
#include <BRep_CurveRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Triangulation.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <BRep_PolygonOnTriangulation.hxx>
#include <Standard_Type.hxx>

void bind_BRep_PolygonOnTriangulation(py::module &mod){

py::class_<BRep_PolygonOnTriangulation, opencascade::handle<BRep_PolygonOnTriangulation>, BRep_CurveRepresentation> cls_BRep_PolygonOnTriangulation(mod, "BRep_PolygonOnTriangulation", "A representation by an array of nodes on a triangulation.");

// Constructors
cls_BRep_PolygonOnTriangulation.def(py::init<const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &>(), py::arg("P"), py::arg("T"), py::arg("L"));

// Fields

// Methods
cls_BRep_PolygonOnTriangulation.def("IsPolygonOnTriangulation", (Standard_Boolean (BRep_PolygonOnTriangulation::*)() const) &BRep_PolygonOnTriangulation::IsPolygonOnTriangulation, "returns True.");
cls_BRep_PolygonOnTriangulation.def("IsPolygonOnTriangulation", (Standard_Boolean (BRep_PolygonOnTriangulation::*)(const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const) &BRep_PolygonOnTriangulation::IsPolygonOnTriangulation, "Is it a polygon in the definition of <T> with location <L>.", py::arg("T"), py::arg("L"));
cls_BRep_PolygonOnTriangulation.def("PolygonOnTriangulation", (void (BRep_PolygonOnTriangulation::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRep_PolygonOnTriangulation::PolygonOnTriangulation, "returns True.", py::arg("P"));
cls_BRep_PolygonOnTriangulation.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (BRep_PolygonOnTriangulation::*)() const) &BRep_PolygonOnTriangulation::Triangulation, "None");
cls_BRep_PolygonOnTriangulation.def("PolygonOnTriangulation", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRep_PolygonOnTriangulation::*)() const) &BRep_PolygonOnTriangulation::PolygonOnTriangulation, "None");
cls_BRep_PolygonOnTriangulation.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_PolygonOnTriangulation::*)() const) &BRep_PolygonOnTriangulation::Copy, "Return a copy of this representation.");
cls_BRep_PolygonOnTriangulation.def_static("get_type_name_", (const char * (*)()) &BRep_PolygonOnTriangulation::get_type_name, "None");
cls_BRep_PolygonOnTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PolygonOnTriangulation::get_type_descriptor, "None");
cls_BRep_PolygonOnTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PolygonOnTriangulation::*)() const) &BRep_PolygonOnTriangulation::DynamicType, "None");

// Enums

}