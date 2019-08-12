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
#include <Geom2d_Conic.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Geometry.hxx>
#include <Geom2d_Circle.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Circle(py::module &mod){

py::class_<Geom2d_Circle, opencascade::handle<Geom2d_Circle>, Geom2d_Conic> cls_Geom2d_Circle(mod, "Geom2d_Circle", "Describes a circle in the plane (2D space). A circle is defined by its radius and, as with any conic curve, is positioned in the plane with a coordinate system (gp_Ax22d object) where the origin is the center of the circle. The coordinate system is the local coordinate system of the circle. The orientation (direct or indirect) of the local coordinate system gives an explicit orientation to the circle, determining the direction in which the parameter increases along the circle. The Geom2d_Circle circle is parameterized by an angle: P(U) = O + R*Cos(U)*XDir + R*Sin(U)*YDir where: - P is the point of parameter U, - O, XDir and YDir are respectively the origin, 'X Direction' and 'Y Direction' of its local coordinate system, - R is the radius of the circle. The 'X Axis' of the local coordinate system therefore defines the origin of the parameter of the circle. The parameter is the angle with this 'X Direction'. A circle is a closed and periodic curve. The period is 2.*Pi and the parameter range is [ 0,2.*Pi [. See Also GCE2d_MakeCircle which provides functions for more complex circle constructions gp_Ax22d and gp_Circ2d for an equivalent, non-parameterized data structure.");

// Constructors
cls_Geom2d_Circle.def(py::init<const gp_Circ2d &>(), py::arg("C"));
cls_Geom2d_Circle.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("A"), py::arg("Radius"));
cls_Geom2d_Circle.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("A"), py::arg("Radius"), py::arg("Sense"));
cls_Geom2d_Circle.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("A"), py::arg("Radius"));

// Fields

// Methods
cls_Geom2d_Circle.def("SetCirc2d", (void (Geom2d_Circle::*)(const gp_Circ2d &)) &Geom2d_Circle::SetCirc2d, "Converts the gp_Circ2d circle C into this circle.", py::arg("C"));
cls_Geom2d_Circle.def("SetRadius", (void (Geom2d_Circle::*)(const Standard_Real)) &Geom2d_Circle::SetRadius, "None", py::arg("R"));
cls_Geom2d_Circle.def("Circ2d", (gp_Circ2d (Geom2d_Circle::*)() const) &Geom2d_Circle::Circ2d, "Returns the non persistent circle from gp with the same geometric properties as <me>.");
cls_Geom2d_Circle.def("Radius", (Standard_Real (Geom2d_Circle::*)() const) &Geom2d_Circle::Radius, "Returns the radius of this circle.");
cls_Geom2d_Circle.def("ReversedParameter", (Standard_Real (Geom2d_Circle::*)(const Standard_Real) const) &Geom2d_Circle::ReversedParameter, "Computes the parameter on the reversed circle for the point of parameter U on this circle. For a circle, the returned value is: 2.*Pi - U.", py::arg("U"));
cls_Geom2d_Circle.def("Eccentricity", (Standard_Real (Geom2d_Circle::*)() const) &Geom2d_Circle::Eccentricity, "Returns 0., which is the eccentricity of any circle.");
cls_Geom2d_Circle.def("FirstParameter", (Standard_Real (Geom2d_Circle::*)() const) &Geom2d_Circle::FirstParameter, "Returns 0.0");
cls_Geom2d_Circle.def("LastParameter", (Standard_Real (Geom2d_Circle::*)() const) &Geom2d_Circle::LastParameter, "Returns 2*PI.");
cls_Geom2d_Circle.def("IsClosed", (Standard_Boolean (Geom2d_Circle::*)() const) &Geom2d_Circle::IsClosed, "returns True.");
cls_Geom2d_Circle.def("IsPeriodic", (Standard_Boolean (Geom2d_Circle::*)() const) &Geom2d_Circle::IsPeriodic, "returns True. The period of a circle is 2.*Pi.");
cls_Geom2d_Circle.def("D0", (void (Geom2d_Circle::*)(const Standard_Real, gp_Pnt2d &) const) &Geom2d_Circle::D0, "Returns in P the point of parameter U. P = C + R * Cos (U) * XDir + R * Sin (U) * YDir where C is the center of the circle , XDir the XDirection and YDir the YDirection of the circle's local coordinate system.", py::arg("U"), py::arg("P"));
cls_Geom2d_Circle.def("D1", (void (Geom2d_Circle::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Geom2d_Circle::D1, "Returns the point P of parameter U and the first derivative V1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom2d_Circle.def("D2", (void (Geom2d_Circle::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Circle::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom2d_Circle.def("D3", (void (Geom2d_Circle::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Circle::D3, "Returns the point P of parameter u, the first second and third derivatives V1 V2 and V3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom2d_Circle.def("DN", (gp_Vec2d (Geom2d_Circle::*)(const Standard_Real, const Standard_Integer) const) &Geom2d_Circle::DN, "For the point of parameter U of this circle, computes the vector corresponding to the Nth derivative. Exceptions: Standard_RangeError if N is less than 1.", py::arg("U"), py::arg("N"));
cls_Geom2d_Circle.def("Transform", (void (Geom2d_Circle::*)(const gp_Trsf2d &)) &Geom2d_Circle::Transform, "Applies the transformation T to this circle.", py::arg("T"));
cls_Geom2d_Circle.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_Circle::*)() const) &Geom2d_Circle::Copy, "Creates a new object which is a copy of this circle.");
cls_Geom2d_Circle.def_static("get_type_name_", (const char * (*)()) &Geom2d_Circle::get_type_name, "None");
cls_Geom2d_Circle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Circle::get_type_descriptor, "None");
cls_Geom2d_Circle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Circle::*)() const) &Geom2d_Circle::DynamicType, "None");

// Enums

}