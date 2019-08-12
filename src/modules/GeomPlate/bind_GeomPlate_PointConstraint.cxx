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
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <gp_Vec.hxx>
#include <gp_Pnt2d.hxx>
#include <GeomLProp_SLProps.hxx>
#include <GeomPlate_PointConstraint.hxx>
#include <Standard_Type.hxx>

void bind_GeomPlate_PointConstraint(py::module &mod){

py::class_<GeomPlate_PointConstraint, opencascade::handle<GeomPlate_PointConstraint>, Standard_Transient> cls_GeomPlate_PointConstraint(mod, "GeomPlate_PointConstraint", "Defines points as constraints to be used to deform a surface.");

// Constructors
cls_GeomPlate_PointConstraint.def(py::init<const gp_Pnt &, const Standard_Integer>(), py::arg("Pt"), py::arg("Order"));
cls_GeomPlate_PointConstraint.def(py::init<const gp_Pnt &, const Standard_Integer, const Standard_Real>(), py::arg("Pt"), py::arg("Order"), py::arg("TolDist"));
cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"));
cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"), py::arg("TolDist"));
cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"), py::arg("TolDist"), py::arg("TolAng"));
cls_GeomPlate_PointConstraint.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("U"), py::arg("V"), py::arg("Surf"), py::arg("Order"), py::arg("TolDist"), py::arg("TolAng"), py::arg("TolCurv"));

// Fields

// Methods
cls_GeomPlate_PointConstraint.def("SetOrder", (void (GeomPlate_PointConstraint::*)(const Standard_Integer)) &GeomPlate_PointConstraint::SetOrder, "None", py::arg("Order"));
cls_GeomPlate_PointConstraint.def("Order", (Standard_Integer (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::Order, "Returns the order of constraint: G0, G1, and G2, controlled respectively by G0Criterion G1Criterion and G2Criterion.");
cls_GeomPlate_PointConstraint.def("SetG0Criterion", (void (GeomPlate_PointConstraint::*)(const Standard_Real)) &GeomPlate_PointConstraint::SetG0Criterion, "Allows you to set the G0 criterion. This is the law defining the greatest distance allowed between the constraint and the target surface. If this criterion is not set, {TolDist, the distance tolerance from the constructor, is used", py::arg("TolDist"));
cls_GeomPlate_PointConstraint.def("SetG1Criterion", (void (GeomPlate_PointConstraint::*)(const Standard_Real)) &GeomPlate_PointConstraint::SetG1Criterion, "Allows you to set the G1 criterion. This is the law defining the greatest angle allowed between the constraint and the target surface. If this criterion is not set, TolAng, the angular tolerance from the constructor, is used. Raises ConstructionError if the point is not on the surface", py::arg("TolAng"));
cls_GeomPlate_PointConstraint.def("SetG2Criterion", (void (GeomPlate_PointConstraint::*)(const Standard_Real)) &GeomPlate_PointConstraint::SetG2Criterion, "Allows you to set the G2 criterion. This is the law defining the greatest difference in curvature allowed between the constraint and the target surface. If this criterion is not set, TolCurv, the curvature tolerance from the constructor, is used. Raises ConstructionError if the point is not on the surface", py::arg("TolCurv"));
cls_GeomPlate_PointConstraint.def("G0Criterion", (Standard_Real (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::G0Criterion, "Returns the G0 criterion. This is the greatest distance allowed between the constraint and the target surface.");
cls_GeomPlate_PointConstraint.def("G1Criterion", (Standard_Real (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::G1Criterion, "Returns the G1 criterion. This is the greatest angle allowed between the constraint and the target surface. Raises ConstructionError if the point is not on the surface.");
cls_GeomPlate_PointConstraint.def("G2Criterion", (Standard_Real (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::G2Criterion, "Returns the G2 criterion. This is the greatest difference in curvature allowed between the constraint and the target surface. Raises ConstructionError if the point is not on the surface");
cls_GeomPlate_PointConstraint.def("D0", (void (GeomPlate_PointConstraint::*)(gp_Pnt &) const) &GeomPlate_PointConstraint::D0, "None", py::arg("P"));
cls_GeomPlate_PointConstraint.def("D1", (void (GeomPlate_PointConstraint::*)(gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomPlate_PointConstraint::D1, "None", py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_GeomPlate_PointConstraint.def("D2", (void (GeomPlate_PointConstraint::*)(gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomPlate_PointConstraint::D2, "None", py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("V5"));
cls_GeomPlate_PointConstraint.def("HasPnt2dOnSurf", (Standard_Boolean (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::HasPnt2dOnSurf, "None");
cls_GeomPlate_PointConstraint.def("SetPnt2dOnSurf", (void (GeomPlate_PointConstraint::*)(const gp_Pnt2d &)) &GeomPlate_PointConstraint::SetPnt2dOnSurf, "None", py::arg("Pnt"));
cls_GeomPlate_PointConstraint.def("Pnt2dOnSurf", (gp_Pnt2d (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::Pnt2dOnSurf, "None");
cls_GeomPlate_PointConstraint.def("LPropSurf", (GeomLProp_SLProps & (GeomPlate_PointConstraint::*)()) &GeomPlate_PointConstraint::LPropSurf, "None");
cls_GeomPlate_PointConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_PointConstraint::get_type_name, "None");
cls_GeomPlate_PointConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_PointConstraint::get_type_descriptor, "None");
cls_GeomPlate_PointConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_PointConstraint::*)() const) &GeomPlate_PointConstraint::DynamicType, "None");

// Enums

}