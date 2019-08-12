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
#include <Poly_Polygon3D.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <BRep_Polygon3D.hxx>
#include <Standard_Type.hxx>

void bind_BRep_Polygon3D(py::module &mod){

py::class_<BRep_Polygon3D, opencascade::handle<BRep_Polygon3D>, BRep_CurveRepresentation> cls_BRep_Polygon3D(mod, "BRep_Polygon3D", "Representation by a 3D polygon.");

// Constructors
cls_BRep_Polygon3D.def(py::init<const opencascade::handle<Poly_Polygon3D> &, const TopLoc_Location &>(), py::arg("P"), py::arg("L"));

// Fields

// Methods
cls_BRep_Polygon3D.def("IsPolygon3D", (Standard_Boolean (BRep_Polygon3D::*)() const) &BRep_Polygon3D::IsPolygon3D, "Returns True.");
cls_BRep_Polygon3D.def("Polygon3D", (const opencascade::handle<Poly_Polygon3D> & (BRep_Polygon3D::*)() const) &BRep_Polygon3D::Polygon3D, "None");
cls_BRep_Polygon3D.def("Polygon3D", (void (BRep_Polygon3D::*)(const opencascade::handle<Poly_Polygon3D> &)) &BRep_Polygon3D::Polygon3D, "None", py::arg("P"));
cls_BRep_Polygon3D.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_Polygon3D::*)() const) &BRep_Polygon3D::Copy, "Return a copy of this representation.");
cls_BRep_Polygon3D.def_static("get_type_name_", (const char * (*)()) &BRep_Polygon3D::get_type_name, "None");
cls_BRep_Polygon3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_Polygon3D::get_type_descriptor, "None");
cls_BRep_Polygon3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_Polygon3D::*)() const) &BRep_Polygon3D::DynamicType, "None");

// Enums

}