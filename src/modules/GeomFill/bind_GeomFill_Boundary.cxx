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
#include <Standard_Transient.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_Boundary.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_Boundary(py::module &mod){

py::class_<GeomFill_Boundary, opencascade::handle<GeomFill_Boundary>, Standard_Transient> cls_GeomFill_Boundary(mod, "GeomFill_Boundary", "Root class to define a boundary which will form part of a contour around a gap requiring filling. Any new type of constrained boundary must inherit this class. The GeomFill package provides two classes to define constrained boundaries: - GeomFill_SimpleBound to define an unattached boundary - GeomFill_BoundWithSurf to define a boundary attached to a surface. These objects are used to define the boundaries for a GeomFill_ConstrainedFilling framework.");

// Fields

// Methods
cls_GeomFill_Boundary.def("Value", (gp_Pnt (GeomFill_Boundary::*)(const Standard_Real) const) &GeomFill_Boundary::Value, "None", py::arg("U"));
cls_GeomFill_Boundary.def("D1", (void (GeomFill_Boundary::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_Boundary::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_Boundary.def("HasNormals", (Standard_Boolean (GeomFill_Boundary::*)() const) &GeomFill_Boundary::HasNormals, "None");
cls_GeomFill_Boundary.def("Norm", (gp_Vec (GeomFill_Boundary::*)(const Standard_Real) const) &GeomFill_Boundary::Norm, "None", py::arg("U"));
cls_GeomFill_Boundary.def("D1Norm", (void (GeomFill_Boundary::*)(const Standard_Real, gp_Vec &, gp_Vec &) const) &GeomFill_Boundary::D1Norm, "None", py::arg("U"), py::arg("N"), py::arg("DN"));
cls_GeomFill_Boundary.def("Reparametrize", (void (GeomFill_Boundary::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GeomFill_Boundary::Reparametrize, "None", py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DF"), py::arg("DL"), py::arg("Rev"));
cls_GeomFill_Boundary.def("Points", (void (GeomFill_Boundary::*)(gp_Pnt &, gp_Pnt &) const) &GeomFill_Boundary::Points, "None", py::arg("PFirst"), py::arg("PLast"));
cls_GeomFill_Boundary.def("Bounds", [](GeomFill_Boundary &self, Standard_Real & First, Standard_Real & Last){ self.Bounds(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_Boundary.def("IsDegenerated", (Standard_Boolean (GeomFill_Boundary::*)() const) &GeomFill_Boundary::IsDegenerated, "None");
cls_GeomFill_Boundary.def("Tol3d", (Standard_Real (GeomFill_Boundary::*)() const) &GeomFill_Boundary::Tol3d, "None");
cls_GeomFill_Boundary.def("Tol3d", (void (GeomFill_Boundary::*)(const Standard_Real)) &GeomFill_Boundary::Tol3d, "None", py::arg("Tol"));
cls_GeomFill_Boundary.def("Tolang", (Standard_Real (GeomFill_Boundary::*)() const) &GeomFill_Boundary::Tolang, "None");
cls_GeomFill_Boundary.def("Tolang", (void (GeomFill_Boundary::*)(const Standard_Real)) &GeomFill_Boundary::Tolang, "None", py::arg("Tol"));
cls_GeomFill_Boundary.def_static("get_type_name_", (const char * (*)()) &GeomFill_Boundary::get_type_name, "None");
cls_GeomFill_Boundary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_Boundary::get_type_descriptor, "None");
cls_GeomFill_Boundary.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_Boundary::*)() const) &GeomFill_Boundary::DynamicType, "None");

// Enums

}