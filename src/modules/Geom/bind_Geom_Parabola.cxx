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
#include <gp_Parab.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Parabola.hxx>
#include <Standard_Type.hxx>

void bind_Geom_Parabola(py::module &mod){

py::class_<Geom_Parabola, opencascade::handle<Geom_Parabola>, Geom_Conic> cls_Geom_Parabola(mod, "Geom_Parabola", "Describes a parabola in 3D space. A parabola is defined by its focal length (i.e. the distance between its focus and its apex) and is positioned in space with a coordinate system (gp_Ax2 object) where: - the origin is the apex of the parabola, - the 'X Axis' defines the axis of symmetry; the parabola is on the positive side of this axis, - the origin, 'X Direction' and 'Y Direction' define the plane of the parabola. This coordinate system is the local coordinate system of the parabola. The 'main Direction' of this coordinate system is a vector normal to the plane of the parabola. The axis, of which the origin and unit vector are respectively the origin and 'main Direction' of the local coordinate system, is termed the 'Axis' or 'main Axis' of the parabola. The 'main Direction' of the local coordinate system gives an explicit orientation to the parabola, determining the direction in which the parameter increases along the parabola. The Geom_Parabola parabola is parameterized as follows: P(U) = O + U*U/(4.*F)*XDir + U*YDir where: - P is the point of parameter U, - O, XDir and YDir are respectively the origin, 'X Direction' and 'Y Direction' of its local coordinate system, - F is the focal length of the parabola. The parameter of the parabola is therefore its Y coordinate in the local coordinate system, with the 'X Axis' of the local coordinate system defining the origin of the parameter. The parameter range is ] -infinite, +infinite [.");

// Constructors
cls_Geom_Parabola.def(py::init<const gp_Parab &>(), py::arg("Prb"));
cls_Geom_Parabola.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Focal"));
cls_Geom_Parabola.def(py::init<const gp_Ax1 &, const gp_Pnt &>(), py::arg("D"), py::arg("F"));

// Fields

// Methods
cls_Geom_Parabola.def("SetFocal", (void (Geom_Parabola::*)(const Standard_Real)) &Geom_Parabola::SetFocal, "Assigns the value Focal to the focal distance of this parabola. Exceptions Standard_ConstructionError if Focal is negative.", py::arg("Focal"));
cls_Geom_Parabola.def("SetParab", (void (Geom_Parabola::*)(const gp_Parab &)) &Geom_Parabola::SetParab, "Converts the gp_Parab parabola Prb into this parabola.", py::arg("Prb"));
cls_Geom_Parabola.def("Parab", (gp_Parab (Geom_Parabola::*)() const) &Geom_Parabola::Parab, "Returns the non transient parabola from gp with the same geometric properties as <me>.");
cls_Geom_Parabola.def("ReversedParameter", (Standard_Real (Geom_Parabola::*)(const Standard_Real) const) &Geom_Parabola::ReversedParameter, "Computes the parameter on the reversed parabola, for the point of parameter U on this parabola. For a parabola, the returned value is: -U.", py::arg("U"));
cls_Geom_Parabola.def("FirstParameter", (Standard_Real (Geom_Parabola::*)() const) &Geom_Parabola::FirstParameter, "Returns the value of the first or last parameter of this parabola. This is, respectively: - Standard_Real::RealFirst(), or - Standard_Real::RealLast().");
cls_Geom_Parabola.def("LastParameter", (Standard_Real (Geom_Parabola::*)() const) &Geom_Parabola::LastParameter, "Returns the value of the first or last parameter of this parabola. This is, respectively: - Standard_Real::RealFirst(), or - Standard_Real::RealLast().");
cls_Geom_Parabola.def("IsClosed", (Standard_Boolean (Geom_Parabola::*)() const) &Geom_Parabola::IsClosed, "Returns False");
cls_Geom_Parabola.def("IsPeriodic", (Standard_Boolean (Geom_Parabola::*)() const) &Geom_Parabola::IsPeriodic, "Returns False");
cls_Geom_Parabola.def("Directrix", (gp_Ax1 (Geom_Parabola::*)() const) &Geom_Parabola::Directrix, "Computes the directrix of this parabola. This is a line normal to the axis of symmetry, in the plane of this parabola, located on the negative side of its axis of symmetry, at a distance from the apex equal to the focal length. The directrix is returned as an axis (gp_Ax1 object), where the origin is located on the 'X Axis' of this parabola.");
cls_Geom_Parabola.def("Eccentricity", (Standard_Real (Geom_Parabola::*)() const) &Geom_Parabola::Eccentricity, "Returns 1. (which is the eccentricity of any parabola).");
cls_Geom_Parabola.def("Focus", (gp_Pnt (Geom_Parabola::*)() const) &Geom_Parabola::Focus, "Computes the focus of this parabola. The focus is on the positive side of the 'X Axis' of the local coordinate system of the parabola.");
cls_Geom_Parabola.def("Focal", (Standard_Real (Geom_Parabola::*)() const) &Geom_Parabola::Focal, "Computes the focal distance of this parabola The focal distance is the distance between the apex and the focus of the parabola.");
cls_Geom_Parabola.def("Parameter", (Standard_Real (Geom_Parabola::*)() const) &Geom_Parabola::Parameter, "Computes the parameter of this parabola which is the distance between its focus and its directrix. This distance is twice the focal length. If P is the parameter of the parabola, the equation of the parabola in its local coordinate system is: Y**2 = 2.*P*X.");
cls_Geom_Parabola.def("D0", (void (Geom_Parabola::*)(const Standard_Real, gp_Pnt &) const) &Geom_Parabola::D0, "Returns in P the point of parameter U. If U = 0 the returned point is the origin of the XAxis and the YAxis of the parabola and it is the vertex of the parabola. P = S + F * (U * U * XDir + * U * YDir) where S is the vertex of the parabola, XDir the XDirection and YDir the YDirection of the parabola's local coordinate system.", py::arg("U"), py::arg("P"));
cls_Geom_Parabola.def("D1", (void (Geom_Parabola::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &Geom_Parabola::D1, "Returns the point P of parameter U and the first derivative V1.", py::arg("U"), py::arg("P"), py::arg("V1"));
cls_Geom_Parabola.def("D2", (void (Geom_Parabola::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &Geom_Parabola::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_Geom_Parabola.def("D3", (void (Geom_Parabola::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &Geom_Parabola::D3, "Returns the point P of parameter U, the first second and third derivatives V1 V2 and V3.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_Geom_Parabola.def("DN", (gp_Vec (Geom_Parabola::*)(const Standard_Real, const Standard_Integer) const) &Geom_Parabola::DN, "For the point of parameter U of this parabola, computes the vector corresponding to the Nth derivative. Exceptions Standard_RangeError if N is less than 1.", py::arg("U"), py::arg("N"));
cls_Geom_Parabola.def("Transform", (void (Geom_Parabola::*)(const gp_Trsf &)) &Geom_Parabola::Transform, "Applies the transformation T to this parabola.", py::arg("T"));
cls_Geom_Parabola.def("TransformedParameter", (Standard_Real (Geom_Parabola::*)(const Standard_Real, const gp_Trsf &) const) &Geom_Parabola::TransformedParameter, "Returns the parameter on the transformed curve for the transform of the point of parameter U on <me>.", py::arg("U"), py::arg("T"));
cls_Geom_Parabola.def("ParametricTransformation", (Standard_Real (Geom_Parabola::*)(const gp_Trsf &) const) &Geom_Parabola::ParametricTransformation, "Returns a coefficient to compute the parameter on the transformed curve for the transform of the point on <me>.", py::arg("T"));
cls_Geom_Parabola.def("Copy", (opencascade::handle<Geom_Geometry> (Geom_Parabola::*)() const) &Geom_Parabola::Copy, "Creates a new object which is a copy of this parabola.");
cls_Geom_Parabola.def_static("get_type_name_", (const char * (*)()) &Geom_Parabola::get_type_name, "None");
cls_Geom_Parabola.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_Parabola::get_type_descriptor, "None");
cls_Geom_Parabola.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_Parabola::*)() const) &Geom_Parabola::DynamicType, "None");

// Enums

}