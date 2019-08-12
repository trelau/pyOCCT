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
#include <gp_Elips.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Ellipse.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Ellipse(py::module &mod){

py::class_<Geom_Ellipse, opencascade::handle<Geom_Ellipse>, Geom_Conic> cls_Geom_Ellipse(mod, "Geom_Ellipse", "Describes an ellipse in 3D space. An ellipse is defined by its major and minor radii and, as with any conic curve, is positioned in space with a right-handed coordinate system (gp_Ax2 object) where: - the origin is the center of the ellipse, - the 'X Direction' defines the major axis, and - the 'Y Direction' defines the minor axis. The origin, 'X Direction' and 'Y Direction' of this coordinate system define the plane of the ellipse. The coordinate system is the local coordinate system of the ellipse. The 'main Direction' of this coordinate system is the vector normal to the plane of the ellipse. The axis, of which the origin and unit vector are respectively the origin and 'main Direction' of the local coordinate system, is termed the 'Axis' or 'main Axis' of the ellipse. The 'main Direction' of the local coordinate system gives an explicit orientation to the ellipse (definition of the trigonometric sense), determining the direction in which the parameter increases along the ellipse. The Geom_Ellipse ellipse is parameterized by an angle: P(U) = O + MajorRad*Cos(U)*XDir + MinorRad*Sin(U)*YDir where: - P is the point of parameter U, - O, XDir and YDir are respectively the origin, 'X Direction' and 'Y Direction' of its local coordinate system, - MajorRad and MinorRad are the major and minor radii of the ellipse. The 'X Axis' of the local coordinate system therefore defines the origin of the parameter of the ellipse. An ellipse is a closed and periodic curve. The period is 2.*Pi and the parameter range is [ 0, 2.*Pi [.");

// Constructors
cls_Geom_Ellipse.def(py::init<const gp_Elips &>(), py::arg("E"));
cls_Geom_Ellipse.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Fields

// Methods
cls_Geom_Ellipse.def("SetElips", (void (Geom_Ellipse::*)(const gp_Elips &)) &Geom_Ellipse::SetElips, "Converts the gp_Elips ellipse E into this ellipse.", py::arg("E"));
cls_Geom_Ellipse.def("SetMajorRadius", (void (Geom_Ellipse::*)(const Standard_Real)) &Geom_Ellipse::SetMajorRadius, "Assigns a value to the major radius of this ellipse. ConstructionError raised if MajorRadius < MinorRadius.", py::arg("MajorRadius"));
cls_Geom_Ellipse.def("SetMinorRadius", (void (Geom_Ellipse::*)(const Standard_Real)) &Geom_Ellipse::SetMinorRadius, "Assigns a value to the minor radius of this ellipse. ConstructionError raised if MajorRadius < MinorRadius or if MinorRadius < 0.", py::arg("MinorRadius"));
cls_Geom_Ellipse.def("Elips", (gp_Elips (Geom_Ellipse::*)() const) &Geom_Ellipse::Elips, "returns the non transient ellipse from gp with the same");
cls_Geom_Ellipse.def("ReversedParameter", (Standard_Real (Geom_Ellipse::*)(const Standard_Real) const) &Geom_Ellipse::ReversedParameter, "Computes the parameter on the reversed ellipse for the point of parameter U on this ellipse. For an ellipse, the returned value is: 2.*Pi - U.", py::arg("U"));
cls_Geom_Ellipse.def("Directrix1", (gp_Ax1 (Geom_Ellipse::*)() const) &Geom_Ellipse::Directrix1, "This directrix is the line normal to the XAxis of the ellipse in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the ellipse, where e is the eccentricity of the ellipse. This line is parallel to the 'YAxis'. The intersection point between directrix1 and the 'XAxis' is the 'Location' point of the directrix1. This point is on the positive side of the 'XAxis'. Raised if Eccentricity = 0.0. (The ellipse degenerates into a circle)");
cls_Geom_Ellipse.def("Directrix2", (gp_Ax1 (Geom_Ellipse::*)() const) &Geom_Ellipse::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the 'YAxis' of the ellipse.");
cls_Geom_Ellipse.def("Eccentricity", (Standard_Real (Geom_Ellipse::*)() const) &Geom_Ellipse::Eccentricity, "Returns the eccentricity of the ellipse between 0.0 and 1.0 If f is the distance between the center of the ellipse and the Focus1 then the eccentricity e = f / MajorRadius. Returns 0 if MajorRadius = 0");
cls_Geom_Ellipse.def("Focal", (Standard_Real (Geom_Ellipse::*)() const) &Geom_Ellipse::Focal, "Computes the focal distance. It is the distance between the the two focus of the ellipse.");
cls_Geom_Ellipse.def("Focus1", (gp_Pnt (Geom_Ellipse::*)() const) &Geom_Ellipse::Focus1, "Returns the first focus of the ellipse. This focus is on the positive side of the 'XAxis' of the ellipse.");
cls_Geom_Ellipse.def("Focus2", (gp_Pnt (Geom_Ellipse::*)() const) &Geom_Ellipse::Focus2, "Returns the second focus of the ellipse. This focus is on the negative side of the 'XAxis' of the ellipse.");
cls_Geom_Ellipse.def("MajorRadius", (Standard_Real (Geom_Ellipse::*)() const) &Geom_Ellipse::MajorRadius, "Returns the major radius of this ellipse.");
cls_Geom_Ellipse.def("MinorRadius", (Standard_Real (Geom_Ellipse::*)() const) &Geom_Ellipse::MinorRadius, "Returns the minor radius of this ellipse.");
cls_Geom_Ellipse.def("Parameter", (Standard_Real (Geom_Ellipse::*)() const) &Geom_Ellipse::Parameter, "Returns p = (1 - e * e) * MajorRadius where e is the eccentricity of the ellipse. Returns 0 if MajorRadius = 0");
cls_Geom_Ellipse.def("FirstParameter", (Standard_Real (Geom_Ellipse::*)() const) &Geom_Ellipse::FirstParameter, "Returns the value of the first parameter of this ellipse. This is respectively: - 0.0, which gives the start point of this ellipse, or The start point and end point of an ellipse are coincident.");
cls_Geom_Ellipse.def("LastParameter", (Standard_Real (Geom_Ellipse::*)() const) &Geom_Ellipse::LastParameter, "Returns the value of the last parameter of this ellipse. This is respectively: - 2.*Pi, which gives the end point of this ellipse. The start point and end point of an ellipse are coincident.");
cls_Geom_Ellipse.def("IsClosed", (Standard_Boolean (Geom_Ellipse::*)() const) &Geom_Ellipse::IsClosed, "return True.");
cls_Geom_Ellipse.def("IsPeriodic", (Standard_Boolean (Geom_Ellipse::*)() const) &Geom_Ellipse::IsPeriodic, "return True.");
cls_Geom_Ellipse.def("D0", (void (Geom_Ellipse::*)(const Standard_Real, gp_Pnt &) const) &Geom_Ellipse::D0, "Returns in P the point of parameter U. P = C + MajorRadius * Cos (U) * XDir + MinorRadius * Sin (U) * YDir where C is the center of the ellipse , XDir the direction of the 'XAxis' and 'YDir' the 'YAxis' of the ellipse.", py::arg("U"), py::arg("P"));
cls_Geom_Ellipse.def("D1", (void (Geom_Ellipse::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Geom_Ellipse::D1, "None", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom_Ellipse.def("D2", (void (Geom_Ellipse::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_Ellipse::D2, "Returns the point P of parameter U. The vectors V1 and V2 are the first and second derivatives at this point.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom_Ellipse.def("D3", (void (Geom_Ellipse::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Ellipse::D3, "Returns the point P of parameter U, the first second and third derivatives V1 V2 and V3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom_Ellipse.def("DN", (gp_Vec (Geom_Ellipse::*)(const Standard_Real, const Standard_Integer) const) &Geom_Ellipse::DN, "For the point of parameter U of this ellipse, computes the vector corresponding to the Nth derivative. Exceptions Standard_RangeError if N is less than 1.", py::arg("U"), py::arg("N"));
cls_Geom_Ellipse.def("Transform", (void (Geom_Ellipse::*)(const gp_Trsf &)) &Geom_Ellipse::Transform, "Applies the transformation T to this ellipse.", py::arg("T"));
cls_Geom_Ellipse.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Ellipse::*)() const) &Geom_Ellipse::Copy, "Creates a new object which is a copy of this ellipse.");
cls_Geom_Ellipse.def_static("get_type_name_", (const char * (*)()) &Geom_Ellipse::get_type_name, "None");
cls_Geom_Ellipse.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Ellipse::get_type_descriptor, "None");
cls_Geom_Ellipse.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Ellipse::*)() const) &Geom_Ellipse::DynamicType, "None");

// Enums

}