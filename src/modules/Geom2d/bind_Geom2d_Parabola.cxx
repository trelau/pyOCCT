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
#include <gp_Parab2d.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Geometry.hxx>
#include <Geom2d_Parabola.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_Parabola(py::module &mod){

py::class_<Geom2d_Parabola, opencascade::handle<Geom2d_Parabola>, Geom2d_Conic> cls_Geom2d_Parabola(mod, "Geom2d_Parabola", "Describes a parabola in the plane (2D space). A parabola is defined by its focal length (i.e. the distance between its focus and its apex) and is positioned in the plane with a coordinate system (gp_Ax22d object) where: - the origin is the apex of the parabola, and - the 'X Axis' defines the axis of symmetry; the parabola is on the positive side of this axis. This coordinate system is the local coordinate system of the parabola. The orientation (direct or indirect) of the local coordinate system gives an explicit orientation to the parabola, determining the direction in which the parameter increases along the parabola. The Geom_Parabola parabola is parameterized as follows: P(U) = O + U*U/(4.*F)*XDir + U*YDir, where: - P is the point of parameter U, - O, XDir and YDir are respectively the origin, 'X Direction' and 'Y Direction' of its local coordinate system, - F is the focal length of the parabola. The parameter of the parabola is therefore its Y coordinate in the local coordinate system, with the 'X Axis' of the local coordinate system defining the origin of the parameter. The parameter range is ] -infinite,+infinite [.");

// Constructors
cls_Geom2d_Parabola.def(py::init<const gp_Parab2d &>(), py::arg("Prb"));
cls_Geom2d_Parabola.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("MirrorAxis"), py::arg("Focal"));
cls_Geom2d_Parabola.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("MirrorAxis"), py::arg("Focal"), py::arg("Sense"));
cls_Geom2d_Parabola.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("Axis"), py::arg("Focal"));
cls_Geom2d_Parabola.def(py::init<const gp_Ax2d &, const gp_Pnt2d &>(), py::arg("D"), py::arg("F"));

// Fields

// Methods
cls_Geom2d_Parabola.def("SetFocal", (void (Geom2d_Parabola::*)(const Standard_Real)) &Geom2d_Parabola::SetFocal, "Assigns the value Focal to the focal length of this parabola. Exceptions Standard_ConstructionError if Focal is negative.", py::arg("Focal"));
cls_Geom2d_Parabola.def("SetParab2d", (void (Geom2d_Parabola::*)(const gp_Parab2d &)) &Geom2d_Parabola::SetParab2d, "Converts the gp_Parab2d parabola Prb into this parabola.", py::arg("Prb"));
cls_Geom2d_Parabola.def("Parab2d", (gp_Parab2d (Geom2d_Parabola::*)() const) &Geom2d_Parabola::Parab2d, "Returns the non persistent parabola from gp with the same geometric properties as <me>.");
cls_Geom2d_Parabola.def("ReversedParameter", (Standard_Real (Geom2d_Parabola::*)(const Standard_Real) const) &Geom2d_Parabola::ReversedParameter, "Computes the parameter on the reversed parabola for the point of parameter U on this parabola. For a parabola, the returned value is -U.", py::arg("U"));
cls_Geom2d_Parabola.def("FirstParameter", (Standard_Real (Geom2d_Parabola::*)() const) &Geom2d_Parabola::FirstParameter, "Returns RealFirst from Standard.");
cls_Geom2d_Parabola.def("LastParameter", (Standard_Real (Geom2d_Parabola::*)() const) &Geom2d_Parabola::LastParameter, "Returns RealLast from Standard.");
cls_Geom2d_Parabola.def("IsClosed", (Standard_Boolean (Geom2d_Parabola::*)() const) &Geom2d_Parabola::IsClosed, "Returns False");
cls_Geom2d_Parabola.def("IsPeriodic", (Standard_Boolean (Geom2d_Parabola::*)() const) &Geom2d_Parabola::IsPeriodic, "Returns False");
cls_Geom2d_Parabola.def("Directrix", (gp_Ax2d (Geom2d_Parabola::*)() const) &Geom2d_Parabola::Directrix, "The directrix is parallel to the 'YAxis' of the parabola. The 'Location' point of the directrix is the intersection point between the directrix and the symmetry axis ('XAxis') of the parabola.");
cls_Geom2d_Parabola.def("Eccentricity", (Standard_Real (Geom2d_Parabola::*)() const) &Geom2d_Parabola::Eccentricity, "Returns the eccentricity e = 1.0");
cls_Geom2d_Parabola.def("Focus", (gp_Pnt2d (Geom2d_Parabola::*)() const) &Geom2d_Parabola::Focus, "Computes the focus of this parabola The focus is on the positive side of the 'X Axis' of the local coordinate system of the parabola.");
cls_Geom2d_Parabola.def("Focal", (Standard_Real (Geom2d_Parabola::*)() const) &Geom2d_Parabola::Focal, "Computes the focal length of this parabola. The focal length is the distance between the apex and the focus of the parabola.");
cls_Geom2d_Parabola.def("Parameter", (Standard_Real (Geom2d_Parabola::*)() const) &Geom2d_Parabola::Parameter, "Computes the parameter of this parabola, which is the distance between its focus and its directrix. This distance is twice the focal length. If P is the parameter of the parabola, the equation of the parabola in its local coordinate system is: Y**2 = 2.*P*X.");
cls_Geom2d_Parabola.def("D0", (void (Geom2d_Parabola::*)(const Standard_Real, gp_Pnt2d &) const) &Geom2d_Parabola::D0, "Returns in P the point of parameter U. If U = 0 the returned point is the origin of the XAxis and the YAxis of the parabola and it is the vertex of the parabola. P = S + F * (U * U * XDir + * U * YDir) where S is the vertex of the parabola, XDir the XDirection and YDir the YDirection of the parabola's local coordinate system.", py::arg("U"), py::arg("P"));
cls_Geom2d_Parabola.def("D1", (void (Geom2d_Parabola::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Geom2d_Parabola::D1, "Returns the point P of parameter U and the first derivative V1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom2d_Parabola.def("D2", (void (Geom2d_Parabola::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Parabola::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom2d_Parabola.def("D3", (void (Geom2d_Parabola::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2d_Parabola::D3, "Returns the point P of parameter U, the first second and third derivatives V1 V2 and V3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom2d_Parabola.def("DN", (gp_Vec2d (Geom2d_Parabola::*)(const Standard_Real, const Standard_Integer) const) &Geom2d_Parabola::DN, "For the point of parameter U of this parabola, computes the vector corresponding to the Nth derivative. Exceptions Standard_RangeError if N is less than 1.", py::arg("U"), py::arg("N"));
cls_Geom2d_Parabola.def("Transform", (void (Geom2d_Parabola::*)(const gp_Trsf2d &)) &Geom2d_Parabola::Transform, "Applies the transformation T to this parabola.", py::arg("T"));
cls_Geom2d_Parabola.def("TransformedParameter", (Standard_Real (Geom2d_Parabola::*)(const Standard_Real, const gp_Trsf2d &) const) &Geom2d_Parabola::TransformedParameter, "Computes the parameter on the transformed parabola, for the point of parameter U on this parabola. For a parabola, the returned value is equal to U multiplied by the scale factor of transformation T.", py::arg("U"), py::arg("T"));
cls_Geom2d_Parabola.def("ParametricTransformation", (Standard_Real (Geom2d_Parabola::*)(const gp_Trsf2d &) const) &Geom2d_Parabola::ParametricTransformation, "Returns a coefficient to compute the parameter on the transformed curve for the transform of the point on <me>.", py::arg("T"));
cls_Geom2d_Parabola.def("Copy", (opencascade::handle<Geom2d_Geometry> (Geom2d_Parabola::*)() const) &Geom2d_Parabola::Copy, "Creates a new object, which is a copy of this parabola.");
cls_Geom2d_Parabola.def_static("get_type_name_", (const char * (*)()) &Geom2d_Parabola::get_type_name, "None");
cls_Geom2d_Parabola.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_Parabola::get_type_descriptor, "None");
cls_Geom2d_Parabola.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_Parabola::*)() const) &Geom2d_Parabola::DynamicType, "None");

// Enums

}