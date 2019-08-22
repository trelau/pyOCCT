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
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Ax1(py::module &mod){

py::class_<gp_Ax1> cls_gp_Ax1(mod, "gp_Ax1", "Describes an axis in 3D space. An axis is defined by: - its origin (also referred to as its 'Location point'), and - its unit vector (referred to as its 'Direction' or 'main Direction'). An axis is used: - to describe 3D geometric entities (for example, the axis of a revolution entity). It serves the same purpose as the STEP function 'axis placement one axis', or - to define geometric transformations (axis of symmetry, axis of rotation, and so on). For example, this entity can be used to locate a geometric entity or to define a symmetry axis.");

// Constructors
cls_gp_Ax1.def(py::init<>());
cls_gp_Ax1.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

// Fields

// Methods
// cls_gp_Ax1.def_static("operator new_", (void * (*)(size_t)) &gp_Ax1::operator new, "None", py::arg("theSize"));
// cls_gp_Ax1.def_static("operator delete_", (void (*)(void *)) &gp_Ax1::operator delete, "None", py::arg("theAddress"));
// cls_gp_Ax1.def_static("operator new[]_", (void * (*)(size_t)) &gp_Ax1::operator new[], "None", py::arg("theSize"));
// cls_gp_Ax1.def_static("operator delete[]_", (void (*)(void *)) &gp_Ax1::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Ax1.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Ax1::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Ax1.def_static("operator delete_", (void (*)(void *, void *)) &gp_Ax1::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Ax1.def("SetDirection", (void (gp_Ax1::*)(const gp_Dir &)) &gp_Ax1::SetDirection, "Assigns V as the 'Direction' of this axis.", py::arg("V"));
cls_gp_Ax1.def("SetLocation", (void (gp_Ax1::*)(const gp_Pnt &)) &gp_Ax1::SetLocation, "Assigns P as the origin of this axis.", py::arg("P"));
cls_gp_Ax1.def("Direction", (const gp_Dir & (gp_Ax1::*)() const) &gp_Ax1::Direction, "Returns the direction of <me>.");
cls_gp_Ax1.def("Location", (const gp_Pnt & (gp_Ax1::*)() const) &gp_Ax1::Location, "Returns the location point of <me>.");
cls_gp_Ax1.def("IsCoaxial", (Standard_Boolean (gp_Ax1::*)(const gp_Ax1 &, const Standard_Real, const Standard_Real) const) &gp_Ax1::IsCoaxial, "Returns True if : . the angle between <me> and <Other> is lower or equal to <AngularTolerance> and . the distance between <me>.Location() and <Other> is lower or equal to <LinearTolerance> and . the distance between <Other>.Location() and <me> is lower or equal to LinearTolerance.", py::arg("Other"), py::arg("AngularTolerance"), py::arg("LinearTolerance"));
cls_gp_Ax1.def("IsNormal", (Standard_Boolean (gp_Ax1::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Ax1::IsNormal, "Returns True if the direction of the <me> and <Other> are normal to each other. That is, if the angle between the two axes is equal to Pi/2. Note: the tolerance criterion is given by AngularTolerance..", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Ax1.def("IsOpposite", (Standard_Boolean (gp_Ax1::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Ax1::IsOpposite, "Returns True if the direction of <me> and <Other> are parallel with opposite orientation. That is, if the angle between the two axes is equal to Pi. Note: the tolerance criterion is given by AngularTolerance.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Ax1.def("IsParallel", (Standard_Boolean (gp_Ax1::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Ax1::IsParallel, "Returns True if the direction of <me> and <Other> are parallel with same orientation or opposite orientation. That is, if the angle between the two axes is equal to 0 or Pi. Note: the tolerance criterion is given by AngularTolerance.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Ax1.def("Angle", (Standard_Real (gp_Ax1::*)(const gp_Ax1 &) const) &gp_Ax1::Angle, "Computes the angular value, in radians, between <me>.Direction() and <Other>.Direction(). Returns the angle between 0 and 2*PI radians.", py::arg("Other"));
cls_gp_Ax1.def("Reverse", (void (gp_Ax1::*)()) &gp_Ax1::Reverse, "Reverses the unit vector of this axis. and assigns the result to this axis.");
cls_gp_Ax1.def("Reversed", (gp_Ax1 (gp_Ax1::*)() const) &gp_Ax1::Reversed, "Reverses the unit vector of this axis and creates a new one.");
cls_gp_Ax1.def("Mirror", (void (gp_Ax1::*)(const gp_Pnt &)) &gp_Ax1::Mirror, "Performs the symmetrical transformation of an axis placement with respect to the point P which is the center of the symmetry and assigns the result to this axis.", py::arg("P"));
cls_gp_Ax1.def("Mirrored", (gp_Ax1 (gp_Ax1::*)(const gp_Pnt &) const) &gp_Ax1::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to the point P which is the center of the symmetry and creates a new axis.", py::arg("P"));
cls_gp_Ax1.def("Mirror", (void (gp_Ax1::*)(const gp_Ax1 &)) &gp_Ax1::Mirror, "Performs the symmetrical transformation of an axis placement with respect to an axis placement which is the axis of the symmetry and assigns the result to this axis.", py::arg("A1"));
cls_gp_Ax1.def("Mirrored", (gp_Ax1 (gp_Ax1::*)(const gp_Ax1 &) const) &gp_Ax1::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to an axis placement which is the axis of the symmetry and creates a new axis.", py::arg("A1"));
cls_gp_Ax1.def("Mirror", (void (gp_Ax1::*)(const gp_Ax2 &)) &gp_Ax1::Mirror, "Performs the symmetrical transformation of an axis placement with respect to a plane. The axis placement <A2> locates the plane of the symmetry : (Location, XDirection, YDirection) and assigns the result to this axis.", py::arg("A2"));
cls_gp_Ax1.def("Mirrored", (gp_Ax1 (gp_Ax1::*)(const gp_Ax2 &) const) &gp_Ax1::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to a plane. The axis placement <A2> locates the plane of the symmetry : (Location, XDirection, YDirection) and creates a new axis.", py::arg("A2"));
cls_gp_Ax1.def("Rotate", (void (gp_Ax1::*)(const gp_Ax1 &, const Standard_Real)) &gp_Ax1::Rotate, "Rotates this axis at an angle Ang (in radians) about the axis A1 and assigns the result to this axis.", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax1.def("Rotated", (gp_Ax1 (gp_Ax1::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Ax1::Rotated, "Rotates this axis at an angle Ang (in radians) about the axis A1 and creates a new one.", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax1.def("Scale", (void (gp_Ax1::*)(const gp_Pnt &, const Standard_Real)) &gp_Ax1::Scale, "Applies a scaling transformation to this axis with: - scale factor S, and - center P and assigns the result to this axis.", py::arg("P"), py::arg("S"));
cls_gp_Ax1.def("Scaled", (gp_Ax1 (gp_Ax1::*)(const gp_Pnt &, const Standard_Real) const) &gp_Ax1::Scaled, "Applies a scaling transformation to this axis with: - scale factor S, and - center P and creates a new axis.", py::arg("P"), py::arg("S"));
cls_gp_Ax1.def("Transform", (void (gp_Ax1::*)(const gp_Trsf &)) &gp_Ax1::Transform, "Applies the transformation T to this axis. and assigns the result to this axis.", py::arg("T"));
cls_gp_Ax1.def("Transformed", (gp_Ax1 (gp_Ax1::*)(const gp_Trsf &) const) &gp_Ax1::Transformed, "Applies the transformation T to this axis and creates a new one.", py::arg("T"));
cls_gp_Ax1.def("Translate", (void (gp_Ax1::*)(const gp_Vec &)) &gp_Ax1::Translate, "Translates this axis by the vector V, and assigns the result to this axis.", py::arg("V"));
cls_gp_Ax1.def("Translated", (gp_Ax1 (gp_Ax1::*)(const gp_Vec &) const) &gp_Ax1::Translated, "Translates this axis by the vector V, and creates a new one.", py::arg("V"));
cls_gp_Ax1.def("Translate", (void (gp_Ax1::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Ax1::Translate, "Translates this axis by: the vector (P1, P2) defined from point P1 to point P2. and assigns the result to this axis.", py::arg("P1"), py::arg("P2"));
cls_gp_Ax1.def("Translated", (gp_Ax1 (gp_Ax1::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Ax1::Translated, "Translates this axis by: the vector (P1, P2) defined from point P1 to point P2. and creates a new one.", py::arg("P1"), py::arg("P2"));

// Enums

}