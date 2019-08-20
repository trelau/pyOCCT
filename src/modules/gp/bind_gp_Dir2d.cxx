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
#include <gp_Vec2d.hxx>
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Trsf2d.hxx>

void bind_gp_Dir2d(py::module &mod){

py::class_<gp_Dir2d, std::unique_ptr<gp_Dir2d>> cls_gp_Dir2d(mod, "gp_Dir2d", "Describes a unit vector in the plane (2D space). This unit vector is also called 'Direction'. See Also gce_MakeDir2d which provides functions for more complex unit vector constructions Geom2d_Direction which provides additional functions for constructing unit vectors and works, in particular, with the parametric equations of unit vectors");

// Constructors
cls_gp_Dir2d.def(py::init<>());
cls_gp_Dir2d.def(py::init<const gp_Vec2d &>(), py::arg("V"));
cls_gp_Dir2d.def(py::init<const gp_XY &>(), py::arg("Coord"));
cls_gp_Dir2d.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"));

// Fields

// Methods
// cls_gp_Dir2d.def_static("operator new_", (void * (*)(size_t)) &gp_Dir2d::operator new, "None", py::arg("theSize"));
// cls_gp_Dir2d.def_static("operator delete_", (void (*)(void *)) &gp_Dir2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Dir2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Dir2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Dir2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Dir2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Dir2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Dir2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Dir2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Dir2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Dir2d.def("SetCoord", (void (gp_Dir2d::*)(const Standard_Integer, const Standard_Real)) &gp_Dir2d::SetCoord, "For this unit vector, assigns: the value Xi to: - the X coordinate if Index is 1, or - the Y coordinate if Index is 2, and then normalizes it. Warning Remember that all the coordinates of a unit vector are implicitly modified when any single one is changed directly. Exceptions Standard_OutOfRange if Index is not 1 or 2. Standard_ConstructionError if either of the following is less than or equal to gp::Resolution(): - Sqrt(Xv*Xv + Yv*Yv), or - the modulus of the number pair formed by the new value Xi and the other coordinate of this vector that was not directly modified. Raises OutOfRange if Index != {1, 2}.", py::arg("Index"), py::arg("Xi"));
cls_gp_Dir2d.def("SetCoord", (void (gp_Dir2d::*)(const Standard_Real, const Standard_Real)) &gp_Dir2d::SetCoord, "For this unit vector, assigns: - the values Xv and Yv to its two coordinates, Warning Remember that all the coordinates of a unit vector are implicitly modified when any single one is changed directly. Exceptions Standard_OutOfRange if Index is not 1 or 2. Standard_ConstructionError if either of the following is less than or equal to gp::Resolution(): - Sqrt(Xv*Xv + Yv*Yv), or - the modulus of the number pair formed by the new value Xi and the other coordinate of this vector that was not directly modified. Raises OutOfRange if Index != {1, 2}.", py::arg("Xv"), py::arg("Yv"));
cls_gp_Dir2d.def("SetX", (void (gp_Dir2d::*)(const Standard_Real)) &gp_Dir2d::SetX, "Assigns the given value to the X coordinate of this unit vector, and then normalizes it. Warning Remember that all the coordinates of a unit vector are implicitly modified when any single one is changed directly. Exceptions Standard_ConstructionError if either of the following is less than or equal to gp::Resolution(): - the modulus of Coord, or - the modulus of the number pair formed from the new X or Y coordinate and the other coordinate of this vector that was not directly modified.", py::arg("X"));
cls_gp_Dir2d.def("SetY", (void (gp_Dir2d::*)(const Standard_Real)) &gp_Dir2d::SetY, "Assigns the given value to the Y coordinate of this unit vector, and then normalizes it. Warning Remember that all the coordinates of a unit vector are implicitly modified when any single one is changed directly. Exceptions Standard_ConstructionError if either of the following is less than or equal to gp::Resolution(): - the modulus of Coord, or - the modulus of the number pair formed from the new X or Y coordinate and the other coordinate of this vector that was not directly modified.", py::arg("Y"));
cls_gp_Dir2d.def("SetXY", (void (gp_Dir2d::*)(const gp_XY &)) &gp_Dir2d::SetXY, "Assigns: - the two coordinates of Coord to this unit vector, and then normalizes it. Warning Remember that all the coordinates of a unit vector are implicitly modified when any single one is changed directly. Exceptions Standard_ConstructionError if either of the following is less than or equal to gp::Resolution(): - the modulus of Coord, or - the modulus of the number pair formed from the new X or Y coordinate and the other coordinate of this vector that was not directly modified.", py::arg("Coord"));
cls_gp_Dir2d.def("Coord", (Standard_Real (gp_Dir2d::*)(const Standard_Integer) const) &gp_Dir2d::Coord, "For this unit vector returns the coordinate of range Index : Index = 1 => X is returned Index = 2 => Y is returned Raises OutOfRange if Index != {1, 2}.", py::arg("Index"));
cls_gp_Dir2d.def("Coord", [](gp_Dir2d &self, Standard_Real & Xv, Standard_Real & Yv){ self.Coord(Xv, Yv); return std::tuple<Standard_Real &, Standard_Real &>(Xv, Yv); }, "For this unit vector returns its two coordinates Xv and Yv. Raises OutOfRange if Index != {1, 2}.", py::arg("Xv"), py::arg("Yv"));
cls_gp_Dir2d.def("X", (Standard_Real (gp_Dir2d::*)() const) &gp_Dir2d::X, "For this unit vector, returns its X coordinate.");
cls_gp_Dir2d.def("Y", (Standard_Real (gp_Dir2d::*)() const) &gp_Dir2d::Y, "For this unit vector, returns its Y coordinate.");
cls_gp_Dir2d.def("XY", (const gp_XY & (gp_Dir2d::*)() const) &gp_Dir2d::XY, "For this unit vector, returns its two coordinates as a number pair. Comparison between Directions The precision value is an input data.");
cls_gp_Dir2d.def("IsEqual", (Standard_Boolean (gp_Dir2d::*)(const gp_Dir2d &, const Standard_Real) const) &gp_Dir2d::IsEqual, "Returns True if the two vectors have the same direction i.e. the angle between this unit vector and the unit vector Other is less than or equal to AngularTolerance.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Dir2d.def("IsNormal", (Standard_Boolean (gp_Dir2d::*)(const gp_Dir2d &, const Standard_Real) const) &gp_Dir2d::IsNormal, "Returns True if the angle between this unit vector and the unit vector Other is equal to Pi/2 or -Pi/2 (normal) i.e. Abs(Abs(<me>.Angle(Other)) - PI/2.) <= AngularTolerance", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Dir2d.def("IsOpposite", (Standard_Boolean (gp_Dir2d::*)(const gp_Dir2d &, const Standard_Real) const) &gp_Dir2d::IsOpposite, "Returns True if the angle between this unit vector and the unit vector Other is equal to Pi or -Pi (opposite). i.e. PI - Abs(<me>.Angle(Other)) <= AngularTolerance", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Dir2d.def("IsParallel", (Standard_Boolean (gp_Dir2d::*)(const gp_Dir2d &, const Standard_Real) const) &gp_Dir2d::IsParallel, "returns true if if the angle between this unit vector and unit vector Other is equal to 0, Pi or -Pi. i.e. Abs(Angle(<me>, Other)) <= AngularTolerance or PI - Abs(Angle(<me>, Other)) <= AngularTolerance", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Dir2d.def("Angle", (Standard_Real (gp_Dir2d::*)(const gp_Dir2d &) const) &gp_Dir2d::Angle, "Computes the angular value in radians between <me> and <Other>. Returns the angle in the range [-PI, PI].", py::arg("Other"));
cls_gp_Dir2d.def("Crossed", (Standard_Real (gp_Dir2d::*)(const gp_Dir2d &) const) &gp_Dir2d::Crossed, "Computes the cross product between two directions.", py::arg("Right"));
cls_gp_Dir2d.def("operator^", (Standard_Real (gp_Dir2d::*)(const gp_Dir2d &) const) &gp_Dir2d::operator^, "None", py::arg("Right"));
cls_gp_Dir2d.def("Dot", (Standard_Real (gp_Dir2d::*)(const gp_Dir2d &) const) &gp_Dir2d::Dot, "Computes the scalar product", py::arg("Other"));
cls_gp_Dir2d.def("__mul__", (Standard_Real (gp_Dir2d::*)(const gp_Dir2d &) const) &gp_Dir2d::operator*, py::is_operator(), "None", py::arg("Other"));
cls_gp_Dir2d.def("Reverse", (void (gp_Dir2d::*)()) &gp_Dir2d::Reverse, "None");
cls_gp_Dir2d.def("Reversed", (gp_Dir2d (gp_Dir2d::*)() const) &gp_Dir2d::Reversed, "Reverses the orientation of a direction");
cls_gp_Dir2d.def("__sub__", (gp_Dir2d (gp_Dir2d::*)() const) &gp_Dir2d::operator-, py::is_operator(), "None");
cls_gp_Dir2d.def("Mirror", (void (gp_Dir2d::*)(const gp_Dir2d &)) &gp_Dir2d::Mirror, "None", py::arg("V"));
cls_gp_Dir2d.def("Mirrored", (gp_Dir2d (gp_Dir2d::*)(const gp_Dir2d &) const) &gp_Dir2d::Mirrored, "Performs the symmetrical transformation of a direction with respect to the direction V which is the center of the symmetry.", py::arg("V"));
cls_gp_Dir2d.def("Mirror", (void (gp_Dir2d::*)(const gp_Ax2d &)) &gp_Dir2d::Mirror, "None", py::arg("A"));
cls_gp_Dir2d.def("Mirrored", (gp_Dir2d (gp_Dir2d::*)(const gp_Ax2d &) const) &gp_Dir2d::Mirrored, "Performs the symmetrical transformation of a direction with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Dir2d.def("Rotate", (void (gp_Dir2d::*)(const Standard_Real)) &gp_Dir2d::Rotate, "None", py::arg("Ang"));
cls_gp_Dir2d.def("Rotated", (gp_Dir2d (gp_Dir2d::*)(const Standard_Real) const) &gp_Dir2d::Rotated, "Rotates a direction. Ang is the angular value of the rotation in radians.", py::arg("Ang"));
cls_gp_Dir2d.def("Transform", (void (gp_Dir2d::*)(const gp_Trsf2d &)) &gp_Dir2d::Transform, "None", py::arg("T"));
cls_gp_Dir2d.def("Transformed", (gp_Dir2d (gp_Dir2d::*)(const gp_Trsf2d &) const) &gp_Dir2d::Transformed, "Transforms a direction with the 'Trsf' T. Warnings : If the scale factor of the 'Trsf' T is negative then the direction <me> is reversed.", py::arg("T"));

// Enums

}