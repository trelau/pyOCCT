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
#include <GeomFill_Boundary.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_DegeneratedBound.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_DegeneratedBound(py::module &mod){

py::class_<GeomFill_DegeneratedBound, opencascade::handle<GeomFill_DegeneratedBound>, GeomFill_Boundary> cls_GeomFill_DegeneratedBound(mod, "GeomFill_DegeneratedBound", "Description of a degenerated boundary (a point). Class defining a degenerated boundary for a constrained filling with a point and no other constraint. Only used to simulate an ordinary bound, may not be usefull and desapear soon.");

// Constructors
cls_GeomFill_DegeneratedBound.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Point"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tolang"));

// Fields

// Methods
cls_GeomFill_DegeneratedBound.def("Value", (gp_Pnt (GeomFill_DegeneratedBound::*)(const Standard_Real) const) &GeomFill_DegeneratedBound::Value, "None", py::arg("U"));
cls_GeomFill_DegeneratedBound.def("D1", (void (GeomFill_DegeneratedBound::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_DegeneratedBound::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_DegeneratedBound.def("Reparametrize", (void (GeomFill_DegeneratedBound::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GeomFill_DegeneratedBound::Reparametrize, "None", py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DF"), py::arg("DL"), py::arg("Rev"));
cls_GeomFill_DegeneratedBound.def("Bounds", [](GeomFill_DegeneratedBound &self, Standard_Real & First, Standard_Real & Last){ self.Bounds(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_DegeneratedBound.def("IsDegenerated", (Standard_Boolean (GeomFill_DegeneratedBound::*)() const) &GeomFill_DegeneratedBound::IsDegenerated, "None");
cls_GeomFill_DegeneratedBound.def_static("get_type_name_", (const char * (*)()) &GeomFill_DegeneratedBound::get_type_name, "None");
cls_GeomFill_DegeneratedBound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_DegeneratedBound::get_type_descriptor, "None");
cls_GeomFill_DegeneratedBound.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_DegeneratedBound::*)() const) &GeomFill_DegeneratedBound::DynamicType, "None");

// Enums

}