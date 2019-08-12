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
#include <Geom_Curve.hxx>
#include <gp_Ax1.hxx>
#include <gp_Lin.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Line.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Line(py::module &mod){

py::class_<Geom_Line, opencascade::handle<Geom_Line>, Geom_Curve> cls_Geom_Line(mod, "Geom_Line", "Describes an infinite line. A line is defined and positioned in space with an axis (gp_Ax1 object) which gives it an origin and a unit vector. The Geom_Line line is parameterized: P (U) = O + U*Dir, where: - P is the point of parameter U, - O is the origin and Dir the unit vector of its positioning axis. The parameter range is ] -infinite, +infinite [. The orientation of the line is given by the unit vector of its positioning axis.");

// Constructors
cls_Geom_Line.def(py::init<const gp_Ax1 &>(), py::arg("A1"));
cls_Geom_Line.def(py::init<const gp_Lin &>(), py::arg("L"));
cls_Geom_Line.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

// Fields

// Methods
cls_Geom_Line.def("SetLin", (void (Geom_Line::*)(const gp_Lin &)) &Geom_Line::SetLin, "Set <me> so that <me> has the same geometric properties as L.", py::arg("L"));
cls_Geom_Line.def("SetDirection", (void (Geom_Line::*)(const gp_Dir &)) &Geom_Line::SetDirection, "changes the direction of the line.", py::arg("V"));
cls_Geom_Line.def("SetLocation", (void (Geom_Line::*)(const gp_Pnt &)) &Geom_Line::SetLocation, "changes the 'Location' point (origin) of the line.", py::arg("P"));
cls_Geom_Line.def("SetPosition", (void (Geom_Line::*)(const gp_Ax1 &)) &Geom_Line::SetPosition, "changes the 'Location' and a the 'Direction' of <me>.", py::arg("A1"));
cls_Geom_Line.def("Lin", (gp_Lin (Geom_Line::*)() const) &Geom_Line::Lin, "Returns non transient line from gp with the same geometric properties as <me>");
cls_Geom_Line.def("Position", (const gp_Ax1 & (Geom_Line::*)() const) &Geom_Line::Position, "Returns the positioning axis of this line; this is also its local coordinate system.");
cls_Geom_Line.def("Reverse", (void (Geom_Line::*)()) &Geom_Line::Reverse, "Changes the orientation of this line. As a result, the unit vector of the positioning axis of this line is reversed.");
cls_Geom_Line.def("ReversedParameter", (Standard_Real (Geom_Line::*)(const Standard_Real) const) &Geom_Line::ReversedParameter, "Computes the parameter on the reversed line for the point of parameter U on this line. For a line, the returned value is -U.", py::arg("U"));
cls_Geom_Line.def("FirstParameter", (Standard_Real (Geom_Line::*)() const) &Geom_Line::FirstParameter, "Returns the value of the first parameter of this line. This is Standard_Real::RealFirst().");
cls_Geom_Line.def("LastParameter", (Standard_Real (Geom_Line::*)() const) &Geom_Line::LastParameter, "Returns the value of the last parameter of this line. This is Standard_Real::RealLast().");
cls_Geom_Line.def("IsClosed", (Standard_Boolean (Geom_Line::*)() const) &Geom_Line::IsClosed, "returns False");
cls_Geom_Line.def("IsPeriodic", (Standard_Boolean (Geom_Line::*)() const) &Geom_Line::IsPeriodic, "returns False");
cls_Geom_Line.def("Continuity", (GeomAbs_Shape (Geom_Line::*)() const) &Geom_Line::Continuity, "Returns GeomAbs_CN, which is the global continuity of any line.");
cls_Geom_Line.def("IsCN", (Standard_Boolean (Geom_Line::*)(const Standard_Integer) const) &Geom_Line::IsCN, "returns True. Raised if N < 0.", py::arg("N"));
cls_Geom_Line.def("D0", (void (Geom_Line::*)(const Standard_Real, gp_Pnt &) const) &Geom_Line::D0, "Returns in P the point of parameter U. P (U) = O + U * Dir where O is the 'Location' point of the line and Dir the direction of the line.", py::arg("U"), py::arg("P"));
cls_Geom_Line.def("D1", (void (Geom_Line::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Geom_Line::D1, "Returns the point P of parameter u and the first derivative V1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom_Line.def("D2", (void (Geom_Line::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_Line::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. V2 is a vector with null magnitude for a line.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom_Line.def("D3", (void (Geom_Line::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Line::D3, "V2 and V3 are vectors with null magnitude for a line.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom_Line.def("DN", (gp_Vec (Geom_Line::*)(const Standard_Real, const Standard_Integer) const) &Geom_Line::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_Geom_Line.def("Transform", (void (Geom_Line::*)(const gp_Trsf &)) &Geom_Line::Transform, "Applies the transformation T to this line.", py::arg("T"));
cls_Geom_Line.def("TransformedParameter", (Standard_Real (Geom_Line::*)(const Standard_Real, const gp_Trsf &) const) &Geom_Line::TransformedParameter, "Returns the parameter on the transformed curve for the transform of the point of parameter U on <me>.", py::arg("U"), py::arg("T"));
cls_Geom_Line.def("ParametricTransformation", (Standard_Real (Geom_Line::*)(const gp_Trsf &) const) &Geom_Line::ParametricTransformation, "Returns a coefficient to compute the parameter on the transformed curve for the transform of the point on <me>.", py::arg("T"));
cls_Geom_Line.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Line::*)() const) &Geom_Line::Copy, "Creates a new object which is a copy of this line.");
cls_Geom_Line.def_static("get_type_name_", (const char * (*)()) &Geom_Line::get_type_name, "None");
cls_Geom_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Line::get_type_descriptor, "None");
cls_Geom_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Line::*)() const) &Geom_Line::DynamicType, "None");

// Enums

}