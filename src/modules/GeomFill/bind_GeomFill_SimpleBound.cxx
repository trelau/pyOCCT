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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomFill_SimpleBound.hxx>
#include <Standard_Type.hxx>
#include <Law_Function.hxx>

void bind_GeomFill_SimpleBound(py::module &mod){

py::class_<GeomFill_SimpleBound, opencascade::handle<GeomFill_SimpleBound>, GeomFill_Boundary> cls_GeomFill_SimpleBound(mod, "GeomFill_SimpleBound", "Defines a 3d curve as a boundary for a GeomFill_ConstrainedFilling algorithm. This curve is unattached to an existing surface.D Contains fields to allow a reparametrization of curve.");

// Constructors
cls_GeomFill_SimpleBound.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real>(), py::arg("Curve"), py::arg("Tol3d"), py::arg("Tolang"));

// Fields

// Methods
cls_GeomFill_SimpleBound.def("Value", (gp_Pnt (GeomFill_SimpleBound::*)(const Standard_Real) const) &GeomFill_SimpleBound::Value, "None", py::arg("U"));
cls_GeomFill_SimpleBound.def("D1", (void (GeomFill_SimpleBound::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_SimpleBound::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_SimpleBound.def("Reparametrize", (void (GeomFill_SimpleBound::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GeomFill_SimpleBound::Reparametrize, "None", py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DF"), py::arg("DL"), py::arg("Rev"));
cls_GeomFill_SimpleBound.def("Bounds", [](GeomFill_SimpleBound &self, Standard_Real & First, Standard_Real & Last){ self.Bounds(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_SimpleBound.def("IsDegenerated", (Standard_Boolean (GeomFill_SimpleBound::*)() const) &GeomFill_SimpleBound::IsDegenerated, "None");
cls_GeomFill_SimpleBound.def_static("get_type_name_", (const char * (*)()) &GeomFill_SimpleBound::get_type_name, "None");
cls_GeomFill_SimpleBound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_SimpleBound::get_type_descriptor, "None");
cls_GeomFill_SimpleBound.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_SimpleBound::*)() const) &GeomFill_SimpleBound::DynamicType, "None");

// Enums

}