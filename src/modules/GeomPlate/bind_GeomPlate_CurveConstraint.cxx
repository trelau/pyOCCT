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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Law_Function.hxx>
#include <GeomLProp_SLProps.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Geom2d_Curve.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <GeomPlate_CurveConstraint.hxx>
#include <Standard_Type.hxx>
#include <Adaptor3d_HCurveOnSurface.hxx>

void bind_GeomPlate_CurveConstraint(py::module &mod){

py::class_<GeomPlate_CurveConstraint, opencascade::handle<GeomPlate_CurveConstraint>, Standard_Transient> cls_GeomPlate_CurveConstraint(mod, "GeomPlate_CurveConstraint", "Defines curves as constraints to be used to deform a surface.");

// Constructors
cls_GeomPlate_CurveConstraint.def(py::init<>());
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"));
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"));
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"));
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"));
cls_GeomPlate_CurveConstraint.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Boundary"), py::arg("Order"), py::arg("NPt"), py::arg("TolDist"), py::arg("TolAng"), py::arg("TolCurv"));

// Fields

// Methods
cls_GeomPlate_CurveConstraint.def("SetOrder", (void (GeomPlate_CurveConstraint::*)(const Standard_Integer)) &GeomPlate_CurveConstraint::SetOrder, "Allows you to set the order of continuity required for the constraints: G0, G1, and G2, controlled respectively by G0Criterion G1Criterion and G2Criterion.", py::arg("Order"));
cls_GeomPlate_CurveConstraint.def("Order", (Standard_Integer (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::Order, "Returns the order of constraint, one of G0, G1 or G2.");
cls_GeomPlate_CurveConstraint.def("NbPoints", (Standard_Integer (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::NbPoints, "Returns the number of points on the curve used as a constraint. The default setting is 10. This parameter affects computation time, which increases by the cube of the number of points.");
cls_GeomPlate_CurveConstraint.def("SetNbPoints", (void (GeomPlate_CurveConstraint::*)(const Standard_Integer)) &GeomPlate_CurveConstraint::SetNbPoints, "Allows you to set the number of points on the curve constraint. The default setting is 10. This parameter affects computation time, which increases by the cube of the number of points.", py::arg("NewNb"));
cls_GeomPlate_CurveConstraint.def("SetG0Criterion", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Law_Function> &)) &GeomPlate_CurveConstraint::SetG0Criterion, "Allows you to set the G0 criterion. This is the law defining the greatest distance allowed between the constraint and the target surface for each point of the constraint. If this criterion is not set, TolDist, the distance tolerance from the constructor, is used.", py::arg("G0Crit"));
cls_GeomPlate_CurveConstraint.def("SetG1Criterion", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Law_Function> &)) &GeomPlate_CurveConstraint::SetG1Criterion, "Allows you to set the G1 criterion. This is the law defining the greatest angle allowed between the constraint and the target surface. If this criterion is not set, TolAng, the angular tolerance from the constructor, is used. Raises ConstructionError if the curve is not on a surface", py::arg("G1Crit"));
cls_GeomPlate_CurveConstraint.def("SetG2Criterion", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Law_Function> &)) &GeomPlate_CurveConstraint::SetG2Criterion, "None", py::arg("G2Crit"));
cls_GeomPlate_CurveConstraint.def("G0Criterion", (Standard_Real (GeomPlate_CurveConstraint::*)(const Standard_Real) const) &GeomPlate_CurveConstraint::G0Criterion, "Returns the G0 criterion at the parametric point U on the curve. This is the greatest distance allowed between the constraint and the target surface at U.", py::arg("U"));
cls_GeomPlate_CurveConstraint.def("G1Criterion", (Standard_Real (GeomPlate_CurveConstraint::*)(const Standard_Real) const) &GeomPlate_CurveConstraint::G1Criterion, "Returns the G1 criterion at the parametric point U on the curve. This is the greatest angle allowed between the constraint and the target surface at U. Raises ConstructionError if the curve is not on a surface", py::arg("U"));
cls_GeomPlate_CurveConstraint.def("G2Criterion", (Standard_Real (GeomPlate_CurveConstraint::*)(const Standard_Real) const) &GeomPlate_CurveConstraint::G2Criterion, "Returns the G2 criterion at the parametric point U on the curve. This is the greatest difference in curvature allowed between the constraint and the target surface at U. Raises ConstructionError if the curve is not on a surface", py::arg("U"));
cls_GeomPlate_CurveConstraint.def("FirstParameter", (Standard_Real (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::FirstParameter, "None");
cls_GeomPlate_CurveConstraint.def("LastParameter", (Standard_Real (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::LastParameter, "None");
cls_GeomPlate_CurveConstraint.def("Length", (Standard_Real (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::Length, "None");
cls_GeomPlate_CurveConstraint.def("LPropSurf", (GeomLProp_SLProps & (GeomPlate_CurveConstraint::*)(const Standard_Real)) &GeomPlate_CurveConstraint::LPropSurf, "None", py::arg("U"));
cls_GeomPlate_CurveConstraint.def("D0", (void (GeomPlate_CurveConstraint::*)(const Standard_Real, gp_Pnt &) const) &GeomPlate_CurveConstraint::D0, "None", py::arg("U"), py::arg("P"));
cls_GeomPlate_CurveConstraint.def("D1", (void (GeomPlate_CurveConstraint::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomPlate_CurveConstraint::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_GeomPlate_CurveConstraint.def("D2", (void (GeomPlate_CurveConstraint::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomPlate_CurveConstraint::D2, "None", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"), py::arg("V4"), py::arg("V5"));
cls_GeomPlate_CurveConstraint.def("Curve3d", (opencascade::handle<Adaptor3d_HCurve> (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::Curve3d, "None");
cls_GeomPlate_CurveConstraint.def("SetCurve2dOnSurf", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Geom2d_Curve> &)) &GeomPlate_CurveConstraint::SetCurve2dOnSurf, "loads a 2d curve associated the surface resulting of the constraints", py::arg("Curve2d"));
cls_GeomPlate_CurveConstraint.def("Curve2dOnSurf", (opencascade::handle<Geom2d_Curve> (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::Curve2dOnSurf, "Returns a 2d curve associated the surface resulting of the constraints");
cls_GeomPlate_CurveConstraint.def("SetProjectedCurve", (void (GeomPlate_CurveConstraint::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const Standard_Real)) &GeomPlate_CurveConstraint::SetProjectedCurve, "loads a 2d curve resulting from the normal projection of the curve on the initial surface", py::arg("Curve2d"), py::arg("TolU"), py::arg("TolV"));
cls_GeomPlate_CurveConstraint.def("ProjectedCurve", (opencascade::handle<Adaptor2d_HCurve2d> (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::ProjectedCurve, "Returns the projected curve resulting from the normal projection of the curve on the initial surface");
cls_GeomPlate_CurveConstraint.def_static("get_type_name_", (const char * (*)()) &GeomPlate_CurveConstraint::get_type_name, "None");
cls_GeomPlate_CurveConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomPlate_CurveConstraint::get_type_descriptor, "None");
cls_GeomPlate_CurveConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomPlate_CurveConstraint::*)() const) &GeomPlate_CurveConstraint::DynamicType, "None");

// Enums

}