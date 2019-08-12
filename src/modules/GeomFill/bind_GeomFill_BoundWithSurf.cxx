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
#include <Adaptor3d_CurveOnSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_BoundWithSurf.hxx>
#include <Standard_Type.hxx>
#include <Law_Function.hxx>

void bind_GeomFill_BoundWithSurf(py::module &mod){

py::class_<GeomFill_BoundWithSurf, opencascade::handle<GeomFill_BoundWithSurf>, GeomFill_Boundary> cls_GeomFill_BoundWithSurf(mod, "GeomFill_BoundWithSurf", "Defines a 3d curve as a boundary for a GeomFill_ConstrainedFilling algorithm. This curve is attached to an existing surface. Defines a constrained boundary for filling the computations are done with a CurveOnSurf and a normals field defined by the normalized normal to the surface along the PCurve. Contains fields to allow a reparametrization of curve and normals field.");

// Constructors
cls_GeomFill_BoundWithSurf.def(py::init<const Adaptor3d_CurveOnSurface &, const Standard_Real, const Standard_Real>(), py::arg("CurveOnSurf"), py::arg("Tol3d"), py::arg("Tolang"));

// Fields

// Methods
cls_GeomFill_BoundWithSurf.def("Value", (gp_Pnt (GeomFill_BoundWithSurf::*)(const Standard_Real) const) &GeomFill_BoundWithSurf::Value, "None", py::arg("U"));
cls_GeomFill_BoundWithSurf.def("D1", (void (GeomFill_BoundWithSurf::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_BoundWithSurf::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_BoundWithSurf.def("HasNormals", (Standard_Boolean (GeomFill_BoundWithSurf::*)() const) &GeomFill_BoundWithSurf::HasNormals, "None");
cls_GeomFill_BoundWithSurf.def("Norm", (gp_Vec (GeomFill_BoundWithSurf::*)(const Standard_Real) const) &GeomFill_BoundWithSurf::Norm, "None", py::arg("U"));
cls_GeomFill_BoundWithSurf.def("D1Norm", (void (GeomFill_BoundWithSurf::*)(const Standard_Real, gp_Vec &, gp_Vec &) const) &GeomFill_BoundWithSurf::D1Norm, "None", py::arg("U"), py::arg("N"), py::arg("DN"));
cls_GeomFill_BoundWithSurf.def("Reparametrize", (void (GeomFill_BoundWithSurf::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GeomFill_BoundWithSurf::Reparametrize, "None", py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DF"), py::arg("DL"), py::arg("Rev"));
cls_GeomFill_BoundWithSurf.def("Bounds", [](GeomFill_BoundWithSurf &self, Standard_Real & First, Standard_Real & Last){ self.Bounds(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_BoundWithSurf.def("IsDegenerated", (Standard_Boolean (GeomFill_BoundWithSurf::*)() const) &GeomFill_BoundWithSurf::IsDegenerated, "None");
cls_GeomFill_BoundWithSurf.def_static("get_type_name_", (const char * (*)()) &GeomFill_BoundWithSurf::get_type_name, "None");
cls_GeomFill_BoundWithSurf.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_BoundWithSurf::get_type_descriptor, "None");
cls_GeomFill_BoundWithSurf.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_BoundWithSurf::*)() const) &GeomFill_BoundWithSurf::DynamicType, "None");

// Enums

}