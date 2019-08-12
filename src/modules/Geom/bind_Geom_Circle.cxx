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
#include <Geom_Conic.hxx>
#include <gp_Circ.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Circle.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Circle(py::module &mod){

py::class_<Geom_Circle, opencascade::handle<Geom_Circle>, Geom_Conic> cls_Geom_Circle(mod, "Geom_Circle", "Describes a circle in 3D space. A circle is defined by its radius and, as with any conic curve, is positioned in space with a right-handed coordinate system (gp_Ax2 object) where: - the origin is the center of the circle, and - the origin, 'X Direction' and 'Y Direction' define the plane of the circle. This coordinate system is the local coordinate system of the circle. The 'main Direction' of this coordinate system is the vector normal to the plane of the circle. The axis, of which the origin and unit vector are respectively the origin and 'main Direction' of the local coordinate system, is termed the 'Axis' or 'main Axis' of the circle. The 'main Direction' of the local coordinate system gives an explicit orientation to the circle (definition of the trigonometric sense), determining the direction in which the parameter increases along the circle. The Geom_Circle circle is parameterized by an angle: P(U) = O + R*Cos(U)*XDir + R*Sin(U)*YDir, where: - P is the point of parameter U, - O, XDir and YDir are respectively the origin, 'X Direction' and 'Y Direction' of its local coordinate system, - R is the radius of the circle. The 'X Axis' of the local coordinate system therefore defines the origin of the parameter of the circle. The parameter is the angle with this 'X Direction'. A circle is a closed and periodic curve. The period is 2.*Pi and the parameter range is [ 0, 2.*Pi [.");

// Constructors
cls_Geom_Circle.def(py::init<const gp_Circ &>(), py::arg("C"));
cls_Geom_Circle.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));

// Fields

// Methods
cls_Geom_Circle.def("SetCirc", (void (Geom_Circle::*)(const gp_Circ &)) &Geom_Circle::SetCirc, "Set <me> so that <me> has the same geometric properties as C.", py::arg("C"));
cls_Geom_Circle.def("SetRadius", (void (Geom_Circle::*)(const Standard_Real)) &Geom_Circle::SetRadius, "Assigns the value R to the radius of this circle. Note: it is possible to have a circle with a radius equal to 0.0. Exceptions - Standard_ConstructionError if R is negative.", py::arg("R"));
cls_Geom_Circle.def("Circ", (gp_Circ (Geom_Circle::*)() const) &Geom_Circle::Circ, "returns the non transient circle from gp with the same geometric properties as <me>.");
cls_Geom_Circle.def("Radius", (Standard_Real (Geom_Circle::*)() const) &Geom_Circle::Radius, "Returns the radius of this circle.");
cls_Geom_Circle.def("ReversedParameter", (Standard_Real (Geom_Circle::*)(const Standard_Real) const) &Geom_Circle::ReversedParameter, "Computes the parameter on the reversed circle for the point of parameter U on this circle. For a circle, the returned value is: 2.*Pi - U.", py::arg("U"));
cls_Geom_Circle.def("Eccentricity", (Standard_Real (Geom_Circle::*)() const) &Geom_Circle::Eccentricity, "Returns the eccentricity e = 0 for a circle.");
cls_Geom_Circle.def("FirstParameter", (Standard_Real (Geom_Circle::*)() const) &Geom_Circle::FirstParameter, "Returns the value of the first parameter of this circle. This is 0.0, which gives the start point of this circle, or The start point and end point of a circle are coincident.");
cls_Geom_Circle.def("LastParameter", (Standard_Real (Geom_Circle::*)() const) &Geom_Circle::LastParameter, "Returns the value of the last parameter of this circle. This is 2.*Pi, which gives the end point of this circle. The start point and end point of a circle are coincident.");
cls_Geom_Circle.def("IsClosed", (Standard_Boolean (Geom_Circle::*)() const) &Geom_Circle::IsClosed, "returns True.");
cls_Geom_Circle.def("IsPeriodic", (Standard_Boolean (Geom_Circle::*)() const) &Geom_Circle::IsPeriodic, "returns True.");
cls_Geom_Circle.def("D0", (void (Geom_Circle::*)(const Standard_Real, gp_Pnt &) const) &Geom_Circle::D0, "Returns in P the point of parameter U. P = C + R * Cos (U) * XDir + R * Sin (U) * YDir where C is the center of the circle , XDir the XDirection and YDir the YDirection of the circle's local coordinate system.", py::arg("U"), py::arg("P"));
cls_Geom_Circle.def("D1", (void (Geom_Circle::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Geom_Circle::D1, "Returns the point P of parameter U and the first derivative V1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom_Circle.def("D2", (void (Geom_Circle::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_Circle::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom_Circle.def("D3", (void (Geom_Circle::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Circle::D3, "Returns the point P of parameter u, the first second and third derivatives V1 V2 and V3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom_Circle.def("DN", (gp_Vec (Geom_Circle::*)(const Standard_Real, const Standard_Integer) const) &Geom_Circle::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_Geom_Circle.def("Transform", (void (Geom_Circle::*)(const gp_Trsf &)) &Geom_Circle::Transform, "Applies the transformation T to this circle.", py::arg("T"));
cls_Geom_Circle.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Circle::*)() const) &Geom_Circle::Copy, "Creates a new object which is a copy of this circle.");
cls_Geom_Circle.def_static("get_type_name_", (const char * (*)()) &Geom_Circle::get_type_name, "None");
cls_Geom_Circle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Circle::get_type_descriptor, "None");
cls_Geom_Circle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Circle::*)() const) &Geom_Circle::DynamicType, "None");

// Enums

}