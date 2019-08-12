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
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>

void bind_gp_Dir(py::module &mod){

py::class_<gp_Dir, std::unique_ptr<gp_Dir, Deleter<gp_Dir>>> cls_gp_Dir(mod, "gp_Dir", "Describes a unit vector in 3D space. This unit vector is also called 'Direction'. See Also gce_MakeDir which provides functions for more complex unit vector constructions Geom_Direction which provides additional functions for constructing unit vectors and works, in particular, with the parametric equations of unit vectors.");

// Constructors
cls_gp_Dir.def(py::init<>());
cls_gp_Dir.def(py::init<const gp_Vec &>(), py::arg("V"));
cls_gp_Dir.def(py::init<const gp_XYZ &>(), py::arg("Coord"));
cls_gp_Dir.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));

// Fields

// Methods
// cls_gp_Dir.def_static("operator new_", (void * (*)(size_t)) &gp_Dir::operator new, "None", py::arg("theSize"));
// cls_gp_Dir.def_static("operator delete_", (void (*)(void *)) &gp_Dir::operator delete, "None", py::arg("theAddress"));
// cls_gp_Dir.def_static("operator new[]_", (void * (*)(size_t)) &gp_Dir::operator new[], "None", py::arg("theSize"));
// cls_gp_Dir.def_static("operator delete[]_", (void (*)(void *)) &gp_Dir::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Dir.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Dir::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Dir.def_static("operator delete_", (void (*)(void *, void *)) &gp_Dir::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Dir.def("SetCoord", (void (gp_Dir::*)(const Standard_Integer, const Standard_Real)) &gp_Dir::SetCoord, "For this unit vector, assigns the value Xi to: - the X coordinate if Index is 1, or - the Y coordinate if Index is 2, or - the Z coordinate if Index is 3, and then normalizes it. Warning Remember that all the coordinates of a unit vector are implicitly modified when any single one is changed directly. Exceptions Standard_OutOfRange if Index is not 1, 2, or 3. Standard_ConstructionError if either of the following is less than or equal to gp::Resolution(): - Sqrt(Xv*Xv + Yv*Yv + Zv*Zv), or - the modulus of the number triple formed by the new value Xi and the two other coordinates of this vector that were not directly modified.", py::arg("Index"), py::arg("Xi"));
cls_gp_Dir.def("SetCoord", (void (gp_Dir::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Dir::SetCoord, "For this unit vector, assigns the values Xv, Yv and Zv to its three coordinates. Remember that all the coordinates of a unit vector are implicitly modified when any single one is changed directly.", py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));
cls_gp_Dir.def("SetX", (void (gp_Dir::*)(const Standard_Real)) &gp_Dir::SetX, "Assigns the given value to the X coordinate of this unit vector.", py::arg("X"));
cls_gp_Dir.def("SetY", (void (gp_Dir::*)(const Standard_Real)) &gp_Dir::SetY, "Assigns the given value to the Y coordinate of this unit vector.", py::arg("Y"));
cls_gp_Dir.def("SetZ", (void (gp_Dir::*)(const Standard_Real)) &gp_Dir::SetZ, "Assigns the given value to the Z coordinate of this unit vector.", py::arg("Z"));
cls_gp_Dir.def("SetXYZ", (void (gp_Dir::*)(const gp_XYZ &)) &gp_Dir::SetXYZ, "Assigns the three coordinates of Coord to this unit vector.", py::arg("Coord"));
cls_gp_Dir.def("Coord", (Standard_Real (gp_Dir::*)(const Standard_Integer) const) &gp_Dir::Coord, "Returns the coordinate of range Index : Index = 1 => X is returned Index = 2 => Y is returned Index = 3 => Z is returned Exceptions Standard_OutOfRange if Index is not 1, 2, or 3.", py::arg("Index"));
cls_gp_Dir.def("Coord", [](gp_Dir &self, Standard_Real & Xv, Standard_Real & Yv, Standard_Real & Zv){ self.Coord(Xv, Yv, Zv); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Xv, Yv, Zv); }, "Returns for the unit vector its three coordinates Xv, Yv, and Zv.", py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));
cls_gp_Dir.def("X", (Standard_Real (gp_Dir::*)() const) &gp_Dir::X, "Returns the X coordinate for a unit vector.");
cls_gp_Dir.def("Y", (Standard_Real (gp_Dir::*)() const) &gp_Dir::Y, "Returns the Y coordinate for a unit vector.");
cls_gp_Dir.def("Z", (Standard_Real (gp_Dir::*)() const) &gp_Dir::Z, "Returns the Z coordinate for a unit vector.");
cls_gp_Dir.def("XYZ", (const gp_XYZ & (gp_Dir::*)() const) &gp_Dir::XYZ, "for this unit vector, returns its three coordinates as a number triplea.");
cls_gp_Dir.def("IsEqual", (Standard_Boolean (gp_Dir::*)(const gp_Dir &, const Standard_Real) const) &gp_Dir::IsEqual, "Returns True if the angle between the two directions is lower or equal to AngularTolerance.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Dir.def("IsNormal", (Standard_Boolean (gp_Dir::*)(const gp_Dir &, const Standard_Real) const) &gp_Dir::IsNormal, "Returns True if the angle between this unit vector and the unit vector Other is equal to Pi/2 (normal).", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Dir.def("IsOpposite", (Standard_Boolean (gp_Dir::*)(const gp_Dir &, const Standard_Real) const) &gp_Dir::IsOpposite, "Returns True if the angle between this unit vector and the unit vector Other is equal to Pi (opposite).", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Dir.def("IsParallel", (Standard_Boolean (gp_Dir::*)(const gp_Dir &, const Standard_Real) const) &gp_Dir::IsParallel, "Returns true if the angle between this unit vector and the unit vector Other is equal to 0 or to Pi. Note: the tolerance criterion is given by AngularTolerance.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Dir.def("Angle", (Standard_Real (gp_Dir::*)(const gp_Dir &) const) &gp_Dir::Angle, "Computes the angular value in radians between <me> and <Other>. This value is always positive in 3D space. Returns the angle in the range [0, PI]", py::arg("Other"));
cls_gp_Dir.def("AngleWithRef", (Standard_Real (gp_Dir::*)(const gp_Dir &, const gp_Dir &) const) &gp_Dir::AngleWithRef, "Computes the angular value between <me> and <Other>. <VRef> is the direction of reference normal to <me> and <Other> and its orientation gives the positive sense of rotation. If the cross product <me> ^ <Other> has the same orientation as <VRef> the angular value is positive else negative. Returns the angular value in the range -PI and PI (in radians). Raises DomainError if <me> and <Other> are not parallel this exception is raised when <VRef> is in the same plane as <me> and <Other> The tolerance criterion is Resolution from package gp.", py::arg("Other"), py::arg("VRef"));
cls_gp_Dir.def("Cross", (void (gp_Dir::*)(const gp_Dir &)) &gp_Dir::Cross, "Computes the cross product between two directions Raises the exception ConstructionError if the two directions are parallel because the computed vector cannot be normalized to create a direction.", py::arg("Right"));
cls_gp_Dir.def("operator^=", (void (gp_Dir::*)(const gp_Dir &)) &gp_Dir::operator^=, "None", py::arg("Right"));
cls_gp_Dir.def("Crossed", (gp_Dir (gp_Dir::*)(const gp_Dir &) const) &gp_Dir::Crossed, "Computes the triple vector product. <me> ^ (V1 ^ V2) Raises the exception ConstructionError if V1 and V2 are parallel or <me> and (V1^V2) are parallel because the computed vector can't be normalized to create a direction.", py::arg("Right"));
cls_gp_Dir.def("operator^", (gp_Dir (gp_Dir::*)(const gp_Dir &) const) &gp_Dir::operator^, "None", py::arg("Right"));
cls_gp_Dir.def("CrossCross", (void (gp_Dir::*)(const gp_Dir &, const gp_Dir &)) &gp_Dir::CrossCross, "None", py::arg("V1"), py::arg("V2"));
cls_gp_Dir.def("CrossCrossed", (gp_Dir (gp_Dir::*)(const gp_Dir &, const gp_Dir &) const) &gp_Dir::CrossCrossed, "Computes the double vector product this ^ (V1 ^ V2). - CrossCrossed creates a new unit vector. Exceptions Standard_ConstructionError if: - V1 and V2 are parallel, or - this unit vector and (V1 ^ V2) are parallel. This is because, in these conditions, the computed vector is null and cannot be normalized.", py::arg("V1"), py::arg("V2"));
cls_gp_Dir.def("Dot", (Standard_Real (gp_Dir::*)(const gp_Dir &) const) &gp_Dir::Dot, "Computes the scalar product", py::arg("Other"));
cls_gp_Dir.def("__mul__", (Standard_Real (gp_Dir::*)(const gp_Dir &) const) &gp_Dir::operator*, py::is_operator(), "None", py::arg("Other"));
cls_gp_Dir.def("DotCross", (Standard_Real (gp_Dir::*)(const gp_Dir &, const gp_Dir &) const) &gp_Dir::DotCross, "Computes the triple scalar product <me> * (V1 ^ V2). Warnings : The computed vector V1' = V1 ^ V2 is not normalized to create a unitary vector. So this method never raises an exception even if V1 and V2 are parallel.", py::arg("V1"), py::arg("V2"));
cls_gp_Dir.def("Reverse", (void (gp_Dir::*)()) &gp_Dir::Reverse, "None");
cls_gp_Dir.def("Reversed", (gp_Dir (gp_Dir::*)() const) &gp_Dir::Reversed, "Reverses the orientation of a direction geometric transformations Performs the symmetrical transformation of a direction with respect to the direction V which is the center of the symmetry.]");
cls_gp_Dir.def("__sub__", (gp_Dir (gp_Dir::*)() const) &gp_Dir::operator-, py::is_operator(), "None");
cls_gp_Dir.def("Mirror", (void (gp_Dir::*)(const gp_Dir &)) &gp_Dir::Mirror, "None", py::arg("V"));
cls_gp_Dir.def("Mirrored", (gp_Dir (gp_Dir::*)(const gp_Dir &) const) &gp_Dir::Mirrored, "Performs the symmetrical transformation of a direction with respect to the direction V which is the center of the symmetry.", py::arg("V"));
cls_gp_Dir.def("Mirror", (void (gp_Dir::*)(const gp_Ax1 &)) &gp_Dir::Mirror, "None", py::arg("A1"));
cls_gp_Dir.def("Mirrored", (gp_Dir (gp_Dir::*)(const gp_Ax1 &) const) &gp_Dir::Mirrored, "Performs the symmetrical transformation of a direction with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Dir.def("Mirror", (void (gp_Dir::*)(const gp_Ax2 &)) &gp_Dir::Mirror, "None", py::arg("A2"));
cls_gp_Dir.def("Mirrored", (gp_Dir (gp_Dir::*)(const gp_Ax2 &) const) &gp_Dir::Mirrored, "Performs the symmetrical transformation of a direction with respect to a plane. The axis placement A2 locates the plane of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Dir.def("Rotate", (void (gp_Dir::*)(const gp_Ax1 &, const Standard_Real)) &gp_Dir::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Dir.def("Rotated", (gp_Dir (gp_Dir::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Dir::Rotated, "Rotates a direction. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Dir.def("Transform", (void (gp_Dir::*)(const gp_Trsf &)) &gp_Dir::Transform, "None", py::arg("T"));
cls_gp_Dir.def("Transformed", (gp_Dir (gp_Dir::*)(const gp_Trsf &) const) &gp_Dir::Transformed, "Transforms a direction with a 'Trsf' from gp. Warnings : If the scale factor of the 'Trsf' T is negative then the direction <me> is reversed.", py::arg("T"));

// Enums

}