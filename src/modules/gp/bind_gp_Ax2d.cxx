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
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Vec2d.hxx>

void bind_gp_Ax2d(py::module &mod){

py::class_<gp_Ax2d> cls_gp_Ax2d(mod, "gp_Ax2d", "Describes an axis in the plane (2D space). An axis is defined by: - its origin (also referred to as its 'Location point'), and - its unit vector (referred to as its 'Direction'). An axis implicitly defines a direct, right-handed coordinate system in 2D space by: - its origin, - its 'Direction' (giving the 'X Direction' of the coordinate system), and - the unit vector normal to 'Direction' (positive angle measured in the trigonometric sense). An axis is used: - to describe 2D geometric entities (for example, the axis which defines angular coordinates on a circle). It serves for the same purpose as the STEP function 'axis placement one axis', or - to define geometric transformations (axis of symmetry, axis of rotation, and so on). Note: to define a left-handed 2D coordinate system, use gp_Ax22d.");

// Constructors
cls_gp_Ax2d.def(py::init<>());
cls_gp_Ax2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));

// Fields

// Methods
// cls_gp_Ax2d.def_static("operator new_", (void * (*)(size_t)) &gp_Ax2d::operator new, "None", py::arg("theSize"));
// cls_gp_Ax2d.def_static("operator delete_", (void (*)(void *)) &gp_Ax2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Ax2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Ax2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Ax2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Ax2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Ax2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Ax2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Ax2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Ax2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Ax2d.def("SetLocation", (void (gp_Ax2d::*)(const gp_Pnt2d &)) &gp_Ax2d::SetLocation, "Changes the 'Location' point (origin) of <me>.", py::arg("Locat"));
cls_gp_Ax2d.def("SetDirection", (void (gp_Ax2d::*)(const gp_Dir2d &)) &gp_Ax2d::SetDirection, "Changes the direction of <me>.", py::arg("V"));
cls_gp_Ax2d.def("Location", (const gp_Pnt2d & (gp_Ax2d::*)() const) &gp_Ax2d::Location, "Returns the origin of <me>.");
cls_gp_Ax2d.def("Direction", (const gp_Dir2d & (gp_Ax2d::*)() const) &gp_Ax2d::Direction, "Returns the direction of <me>.");
cls_gp_Ax2d.def("IsCoaxial", (Standard_Boolean (gp_Ax2d::*)(const gp_Ax2d &, const Standard_Real, const Standard_Real) const) &gp_Ax2d::IsCoaxial, "Returns True if : . the angle between <me> and <Other> is lower or equal to <AngularTolerance> and . the distance between <me>.Location() and <Other> is lower or equal to <LinearTolerance> and . the distance between <Other>.Location() and <me> is lower or equal to LinearTolerance.", py::arg("Other"), py::arg("AngularTolerance"), py::arg("LinearTolerance"));
cls_gp_Ax2d.def("IsNormal", (Standard_Boolean (gp_Ax2d::*)(const gp_Ax2d &, const Standard_Real) const) &gp_Ax2d::IsNormal, "Returns true if this axis and the axis Other are normal to each other. That is, if the angle between the two axes is equal to Pi/2 or -Pi/2. Note: the tolerance criterion is given by AngularTolerance.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Ax2d.def("IsOpposite", (Standard_Boolean (gp_Ax2d::*)(const gp_Ax2d &, const Standard_Real) const) &gp_Ax2d::IsOpposite, "Returns true if this axis and the axis Other are parallel, and have opposite orientations. That is, if the angle between the two axes is equal to Pi or -Pi. Note: the tolerance criterion is given by AngularTolerance.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Ax2d.def("IsParallel", (Standard_Boolean (gp_Ax2d::*)(const gp_Ax2d &, const Standard_Real) const) &gp_Ax2d::IsParallel, "Returns true if this axis and the axis Other are parallel, and have either the same or opposite orientations. That is, if the angle between the two axes is equal to 0, Pi or -Pi. Note: the tolerance criterion is given by AngularTolerance.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Ax2d.def("Angle", (Standard_Real (gp_Ax2d::*)(const gp_Ax2d &) const) &gp_Ax2d::Angle, "Computes the angle, in radians, between this axis and the axis Other. The value of the angle is between -Pi and Pi.", py::arg("Other"));
cls_gp_Ax2d.def("Reverse", (void (gp_Ax2d::*)()) &gp_Ax2d::Reverse, "Reverses the direction of <me> and assigns the result to this axis.");
cls_gp_Ax2d.def("Reversed", (gp_Ax2d (gp_Ax2d::*)() const) &gp_Ax2d::Reversed, "Computes a new axis placement with a direction opposite to the direction of <me>.");
cls_gp_Ax2d.def("Mirror", (void (gp_Ax2d::*)(const gp_Pnt2d &)) &gp_Ax2d::Mirror, "None", py::arg("P"));
cls_gp_Ax2d.def("Mirrored", (gp_Ax2d (gp_Ax2d::*)(const gp_Pnt2d &) const) &gp_Ax2d::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Ax2d.def("Mirror", (void (gp_Ax2d::*)(const gp_Ax2d &)) &gp_Ax2d::Mirror, "None", py::arg("A"));
cls_gp_Ax2d.def("Mirrored", (gp_Ax2d (gp_Ax2d::*)(const gp_Ax2d &) const) &gp_Ax2d::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Ax2d.def("Rotate", (void (gp_Ax2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Ax2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Ax2d.def("Rotated", (gp_Ax2d (gp_Ax2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Ax2d::Rotated, "Rotates an axis placement. <P> is the center of the rotation . Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Ax2d.def("Scale", (void (gp_Ax2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Ax2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Ax2d.def("Scaled", (gp_Ax2d (gp_Ax2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Ax2d::Scaled, "Applies a scaling transformation on the axis placement. The 'Location' point of the axisplacement is modified. The 'Direction' is reversed if the scale is negative.", py::arg("P"), py::arg("S"));
cls_gp_Ax2d.def("Transform", (void (gp_Ax2d::*)(const gp_Trsf2d &)) &gp_Ax2d::Transform, "None", py::arg("T"));
cls_gp_Ax2d.def("Transformed", (gp_Ax2d (gp_Ax2d::*)(const gp_Trsf2d &) const) &gp_Ax2d::Transformed, "Transforms an axis placement with a Trsf.", py::arg("T"));
cls_gp_Ax2d.def("Translate", (void (gp_Ax2d::*)(const gp_Vec2d &)) &gp_Ax2d::Translate, "None", py::arg("V"));
cls_gp_Ax2d.def("Translated", (gp_Ax2d (gp_Ax2d::*)(const gp_Vec2d &) const) &gp_Ax2d::Translated, "Translates an axis placement in the direction of the vector <V>. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Ax2d.def("Translate", (void (gp_Ax2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Ax2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Ax2d.def("Translated", (gp_Ax2d (gp_Ax2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Ax2d::Translated, "Translates an axis placement from the point <P1> to the point <P2>.", py::arg("P1"), py::arg("P2"));

// Enums

}