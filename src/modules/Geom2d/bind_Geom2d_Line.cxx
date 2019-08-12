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
#include <Geom2d_Curve.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Geometry.hxx>
#include <Geom2d_Line.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Line(py::module &mod){

py::class_<Geom2d_Line, opencascade::handle<Geom2d_Line>, Geom2d_Curve> cls_Geom2d_Line(mod, "Geom2d_Line", "Describes an infinite line in the plane (2D space). A line is defined and positioned in the plane with an axis (gp_Ax2d object) which gives it an origin and a unit vector. The Geom2d_Line line is parameterized as follows: P (U) = O + U*Dir where: - P is the point of parameter U, - O is the origin and Dir the unit vector of its positioning axis. The parameter range is ] -infinite, +infinite [. The orientation of the line is given by the unit vector of its positioning axis. See Also GCE2d_MakeLine which provides functions for more complex line constructions gp_Ax2d gp_Lin2d for an equivalent, non-parameterized data structure.");

// Constructors
cls_Geom2d_Line.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_Geom2d_Line.def(py::init<const gp_Lin2d &>(), py::arg("L"));
cls_Geom2d_Line.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));

// Fields

// Methods
cls_Geom2d_Line.def("SetLin2d", (void (Geom2d_Line::*)(const gp_Lin2d &)) &Geom2d_Line::SetLin2d, "Set <me> so that <me> has the same geometric properties as L.", py::arg("L"));
cls_Geom2d_Line.def("SetDirection", (void (Geom2d_Line::*)(const gp_Dir2d &)) &Geom2d_Line::SetDirection, "changes the direction of the line.", py::arg("V"));
cls_Geom2d_Line.def("Direction", (const gp_Dir2d & (Geom2d_Line::*)() const) &Geom2d_Line::Direction, "changes the direction of the line.");
cls_Geom2d_Line.def("SetLocation", (void (Geom2d_Line::*)(const gp_Pnt2d &)) &Geom2d_Line::SetLocation, "Changes the 'Location' point (origin) of the line.", py::arg("P"));
cls_Geom2d_Line.def("Location", (const gp_Pnt2d & (Geom2d_Line::*)() const) &Geom2d_Line::Location, "Changes the 'Location' point (origin) of the line.");
cls_Geom2d_Line.def("SetPosition", (void (Geom2d_Line::*)(const gp_Ax2d &)) &Geom2d_Line::SetPosition, "Changes the 'Location' and a the 'Direction' of <me>.", py::arg("A"));
cls_Geom2d_Line.def("Position", (const gp_Ax2d & (Geom2d_Line::*)() const) &Geom2d_Line::Position, "None");
cls_Geom2d_Line.def("Lin2d", (gp_Lin2d (Geom2d_Line::*)() const) &Geom2d_Line::Lin2d, "Returns non persistent line from gp with the same geometric properties as <me>");
cls_Geom2d_Line.def("Reverse", (void (Geom2d_Line::*)()) &Geom2d_Line::Reverse, "Changes the orientation of this line. As a result, the unit vector of the positioning axis of this line is reversed.");
cls_Geom2d_Line.def("ReversedParameter", (Standard_Real (Geom2d_Line::*)(const Standard_Real) const) &Geom2d_Line::ReversedParameter, "Computes the parameter on the reversed line for the point of parameter U on this line. For a line, the returned value is -U.", py::arg("U"));
cls_Geom2d_Line.def("FirstParameter", (Standard_Real (Geom2d_Line::*)() const) &Geom2d_Line::FirstParameter, "Returns RealFirst from Standard.");
cls_Geom2d_Line.def("LastParameter", (Standard_Real (Geom2d_Line::*)() const) &Geom2d_Line::LastParameter, "Returns RealLast from Standard");
cls_Geom2d_Line.def("IsClosed", (Standard_Boolean (Geom2d_Line::*)() const) &Geom2d_Line::IsClosed, "Returns False");
cls_Geom2d_Line.def("IsPeriodic", (Standard_Boolean (Geom2d_Line::*)() const) &Geom2d_Line::IsPeriodic, "Returns False");
cls_Geom2d_Line.def("Continuity", (GeomAbs_Shape (Geom2d_Line::*)() const) &Geom2d_Line::Continuity, "Returns GeomAbs_CN, which is the global continuity of any line.");
cls_Geom2d_Line.def("Distance", (Standard_Real (Geom2d_Line::*)(const gp_Pnt2d &) const) &Geom2d_Line::Distance, "Computes the distance between <me> and the point P.", py::arg("P"));
cls_Geom2d_Line.def("IsCN", (Standard_Boolean (Geom2d_Line::*)(const Standard_Integer) const) &Geom2d_Line::IsCN, "Returns True.", py::arg("N"));
cls_Geom2d_Line.def("D0", (void (Geom2d_Line::*)(const Standard_Real, gp_Pnt2d &) const) &Geom2d_Line::D0, "Returns in P the point of parameter U. P (U) = O + U * Dir where O is the 'Location' point of the line and Dir the direction of the line.", py::arg("U"), py::arg("P"));
cls_Geom2d_Line.def("D1", (void (Geom2d_Line::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Geom2d_Line::D1, "Returns the point P of parameter u and the first derivative V1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom2d_Line.def("D2", (void (Geom2d_Line::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Line::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. V2 is a vector with null magnitude for a line.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom2d_Line.def("D3", (void (Geom2d_Line::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Line::D3, "V2 and V3 are vectors with null magnitude for a line.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom2d_Line.def("DN", (gp_Vec2d (Geom2d_Line::*)(const Standard_Real, const Standard_Integer) const) &Geom2d_Line::DN, "For the point of parameter U of this line, computes the vector corresponding to the Nth derivative. Note: if N is greater than or equal to 2, the result is a vector with null magnitude. Exceptions Standard_RangeError if N is less than 1.", py::arg("U"), py::arg("N"));
cls_Geom2d_Line.def("Transform", (void (Geom2d_Line::*)(const gp_Trsf2d &)) &Geom2d_Line::Transform, "Applies the transformation T to this line.", py::arg("T"));
cls_Geom2d_Line.def("TransformedParameter", (Standard_Real (Geom2d_Line::*)(const Standard_Real, const gp_Trsf2d &) const) &Geom2d_Line::TransformedParameter, "Computes the parameter on the line transformed by T for the point of parameter U on this line. For a line, the returned value is equal to U multiplied by the scale factor of transformation T.", py::arg("U"), py::arg("T"));
cls_Geom2d_Line.def("ParametricTransformation", (Standard_Real (Geom2d_Line::*)(const gp_Trsf2d &) const) &Geom2d_Line::ParametricTransformation, "Returns the coefficient required to compute the parametric transformation of this line when transformation T is applied. This coefficient is the ratio between the parameter of a point on this line and the parameter of the transformed point on the new line transformed by T. For a line, the returned value is the scale factor of the transformation T.", py::arg("T"));
cls_Geom2d_Line.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_Line::*)() const) &Geom2d_Line::Copy, "Creates a new object, which is a copy of this line.");
cls_Geom2d_Line.def_static("get_type_name_", (const char * (*)()) &Geom2d_Line::get_type_name, "None");
cls_Geom2d_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Line::get_type_descriptor, "None");
cls_Geom2d_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Line::*)() const) &Geom2d_Line::DynamicType, "None");

// Enums

}