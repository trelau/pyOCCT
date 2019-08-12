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
#include <gp_Elips2d.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Geometry.hxx>
#include <Geom2d_Ellipse.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Ellipse(py::module &mod){

py::class_<Geom2d_Ellipse, opencascade::handle<Geom2d_Ellipse>, Geom2d_Conic> cls_Geom2d_Ellipse(mod, "Geom2d_Ellipse", "Describes an ellipse in the plane (2D space). An ellipse is defined by its major and minor radii and, as with any conic curve, is positioned in the plane with a coordinate system (gp_Ax22d object) where: - the origin is the center of the ellipse, - the 'X Direction' defines the major axis, and - the 'Y Direction' defines the minor axis. This coordinate system is the local coordinate system of the ellipse. The orientation (direct or indirect) of the local coordinate system gives an explicit orientation to the ellipse, determining the direction in which the parameter increases along the ellipse. The Geom2d_Ellipse ellipse is parameterized by an angle: P(U) = O + MajorRad*Cos(U)*XDir + MinorRad*Sin(U)*YDir where: - P is the point of parameter U, - O, XDir and YDir are respectively the origin, 'X Direction' and 'Y Direction' of its local coordinate system, - MajorRad and MinorRad are the major and minor radii of the ellipse. The 'X Axis' of the local coordinate system therefore defines the origin of the parameter of the ellipse. An ellipse is a closed and periodic curve. The period is 2.*Pi and the parameter range is [ 0,2.*Pi [. See Also GCE2d_MakeEllipse which provides functions for more complex ellipse constructions gp_Ax22d gp_Elips2d for an equivalent, non-parameterized data structure");

// Constructors
cls_Geom2d_Ellipse.def(py::init<const gp_Elips2d &>(), py::arg("E"));
cls_Geom2d_Ellipse.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_Geom2d_Ellipse.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
cls_Geom2d_Ellipse.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Fields

// Methods
cls_Geom2d_Ellipse.def("SetElips2d", (void (Geom2d_Ellipse::*)(const gp_Elips2d &)) &Geom2d_Ellipse::SetElips2d, "Converts the gp_Elips2d ellipse E into this ellipse.", py::arg("E"));
cls_Geom2d_Ellipse.def("SetMajorRadius", (void (Geom2d_Ellipse::*)(const Standard_Real)) &Geom2d_Ellipse::SetMajorRadius, "Assigns a value to the major radius of this ellipse. Exceptions Standard_ConstructionError if: - the major radius of this ellipse becomes less than the minor radius, or - MinorRadius is less than 0.", py::arg("MajorRadius"));
cls_Geom2d_Ellipse.def("SetMinorRadius", (void (Geom2d_Ellipse::*)(const Standard_Real)) &Geom2d_Ellipse::SetMinorRadius, "Assigns a value to the minor radius of this ellipse. Exceptions Standard_ConstructionError if: - the major radius of this ellipse becomes less than the minor radius, or - MinorRadius is less than 0.", py::arg("MinorRadius"));
cls_Geom2d_Ellipse.def("Elips2d", (gp_Elips2d (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::Elips2d, "Converts this ellipse into a gp_Elips2d ellipse.");
cls_Geom2d_Ellipse.def("ReversedParameter", (Standard_Real (Geom2d_Ellipse::*)(const Standard_Real) const) &Geom2d_Ellipse::ReversedParameter, "Computes the parameter on the reversed ellipse for the point of parameter U on this ellipse. For an ellipse, the returned value is: 2.*Pi - U.", py::arg("U"));
cls_Geom2d_Ellipse.def("Directrix1", (gp_Ax2d (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::Directrix1, "Computes the directrices of this ellipse. This directrix is the line normal to the XAxis of the ellipse in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the ellipse, where e is the eccentricity of the ellipse. This line is parallel to the 'YAxis'. The intersection point between directrix1 and the 'XAxis' is the 'Location' point of the directrix1. This point is on the positive side of the 'XAxis'. Raises ConstructionError if Eccentricity = 0.0. (The ellipse degenerates into a circle)");
cls_Geom2d_Ellipse.def("Directrix2", (gp_Ax2d (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the 'YAxis' of the ellipse. Raises ConstructionError if Eccentricity = 0.0. (The ellipse degenerates into a circle).");
cls_Geom2d_Ellipse.def("Eccentricity", (Standard_Real (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::Eccentricity, "Returns the eccentricity of the ellipse between 0.0 and 1.0 If f is the distance between the center of the ellipse and the Focus1 then the eccentricity e = f / MajorRadius. Returns 0 if MajorRadius = 0");
cls_Geom2d_Ellipse.def("Focal", (Standard_Real (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::Focal, "Computes the focal distance. The focal distance is the distance between the center and a focus of the ellipse.");
cls_Geom2d_Ellipse.def("Focus1", (gp_Pnt2d (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::Focus1, "Returns the first focus of the ellipse. This focus is on the positive side of the 'XAxis' of the ellipse.");
cls_Geom2d_Ellipse.def("Focus2", (gp_Pnt2d (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::Focus2, "Returns the second focus of the ellipse. This focus is on the negative side of the 'XAxis' of the ellipse.");
cls_Geom2d_Ellipse.def("MajorRadius", (Standard_Real (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::MajorRadius, "Returns the major radius of this ellipse.");
cls_Geom2d_Ellipse.def("MinorRadius", (Standard_Real (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::MinorRadius, "Returns the minor radius of this ellipse.");
cls_Geom2d_Ellipse.def("Parameter", (Standard_Real (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::Parameter, "Computes the parameter of this ellipse. This value is given by the formula p = (1 - e * e) * MajorRadius where e is the eccentricity of the ellipse. Returns 0 if MajorRadius = 0");
cls_Geom2d_Ellipse.def("FirstParameter", (Standard_Real (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::FirstParameter, "Returns the value of the first parameter of this ellipse. This is 0.0, which gives the start point of this ellipse. The start point and end point of an ellipse are coincident.");
cls_Geom2d_Ellipse.def("LastParameter", (Standard_Real (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::LastParameter, "Returns the value of the last parameter of this ellipse. This is 2.*Pi, which gives the end point of this ellipse. The start point and end point of an ellipse are coincident.");
cls_Geom2d_Ellipse.def("IsClosed", (Standard_Boolean (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::IsClosed, "return True.");
cls_Geom2d_Ellipse.def("IsPeriodic", (Standard_Boolean (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::IsPeriodic, "return True.");
cls_Geom2d_Ellipse.def("D0", (void (Geom2d_Ellipse::*)(const Standard_Real, gp_Pnt2d &) const) &Geom2d_Ellipse::D0, "Returns in P the point of parameter U. P = C + MajorRadius * Cos (U) * XDir + MinorRadius * Sin (U) * YDir where C is the center of the ellipse , XDir the direction of the 'XAxis' and 'YDir' the 'YAxis' of the ellipse.", py::arg("U"), py::arg("P"));
cls_Geom2d_Ellipse.def("D1", (void (Geom2d_Ellipse::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Geom2d_Ellipse::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom2d_Ellipse.def("D2", (void (Geom2d_Ellipse::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Ellipse::D2, "Returns the point P of parameter U. The vectors V1 and V2 are the first and second derivatives at this point.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom2d_Ellipse.def("D3", (void (Geom2d_Ellipse::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Ellipse::D3, "Returns the point P of parameter U, the first second and third derivatives V1 V2 and V3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom2d_Ellipse.def("DN", (gp_Vec2d (Geom2d_Ellipse::*)(const Standard_Real, const Standard_Integer) const) &Geom2d_Ellipse::DN, "For the point of parameter U of this ellipse, computes the vector corresponding to the Nth derivative. Exceptions Standard_RangeError if N is less than 1.", py::arg("U"), py::arg("N"));
cls_Geom2d_Ellipse.def("Transform", (void (Geom2d_Ellipse::*)(const gp_Trsf2d &)) &Geom2d_Ellipse::Transform, "Applies the transformation T to this ellipse.", py::arg("T"));
cls_Geom2d_Ellipse.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::Copy, "Creates a new object which is a copy of this ellipse.");
cls_Geom2d_Ellipse.def_static("get_type_name_", (const char * (*)()) &Geom2d_Ellipse::get_type_name, "None");
cls_Geom2d_Ellipse.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Ellipse::get_type_descriptor, "None");
cls_Geom2d_Ellipse.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Ellipse::*)() const) &Geom2d_Ellipse::DynamicType, "None");

// Enums

}