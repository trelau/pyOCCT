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
#include <gp_Dir2d.hxx>
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Trsf2d.hxx>

void bind_gp_Vec2d(py::module &mod){

py::class_<gp_Vec2d, std::unique_ptr<gp_Vec2d, Deleter<gp_Vec2d>>> cls_gp_Vec2d(mod, "gp_Vec2d", "Defines a non-persistent vector in 2D space.");

// Constructors
cls_gp_Vec2d.def(py::init<>());
cls_gp_Vec2d.def(py::init<const gp_Dir2d &>(), py::arg("V"));
cls_gp_Vec2d.def(py::init<const gp_XY &>(), py::arg("Coord"));
cls_gp_Vec2d.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"));
cls_gp_Vec2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_gp_Vec2d.def_static("operator new_", (void * (*)(size_t)) &gp_Vec2d::operator new, "None", py::arg("theSize"));
// cls_gp_Vec2d.def_static("operator delete_", (void (*)(void *)) &gp_Vec2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Vec2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Vec2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Vec2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Vec2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Vec2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Vec2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Vec2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Vec2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Vec2d.def("SetCoord", (void (gp_Vec2d::*)(const Standard_Integer, const Standard_Real)) &gp_Vec2d::SetCoord, "Changes the coordinate of range Index Index = 1 => X is modified Index = 2 => Y is modified Raises OutOfRange if Index != {1, 2}.", py::arg("Index"), py::arg("Xi"));
cls_gp_Vec2d.def("SetCoord", (void (gp_Vec2d::*)(const Standard_Real, const Standard_Real)) &gp_Vec2d::SetCoord, "For this vector, assigns the values Xv and Yv to its two coordinates", py::arg("Xv"), py::arg("Yv"));
cls_gp_Vec2d.def("SetX", (void (gp_Vec2d::*)(const Standard_Real)) &gp_Vec2d::SetX, "Assigns the given value to the X coordinate of this vector.", py::arg("X"));
cls_gp_Vec2d.def("SetY", (void (gp_Vec2d::*)(const Standard_Real)) &gp_Vec2d::SetY, "Assigns the given value to the Y coordinate of this vector.", py::arg("Y"));
cls_gp_Vec2d.def("SetXY", (void (gp_Vec2d::*)(const gp_XY &)) &gp_Vec2d::SetXY, "Assigns the two coordinates of Coord to this vector.", py::arg("Coord"));
cls_gp_Vec2d.def("Coord", (Standard_Real (gp_Vec2d::*)(const Standard_Integer) const) &gp_Vec2d::Coord, "Returns the coordinate of range Index : Index = 1 => X is returned Index = 2 => Y is returned Raised if Index != {1, 2}.", py::arg("Index"));
cls_gp_Vec2d.def("Coord", [](gp_Vec2d &self, Standard_Real & Xv, Standard_Real & Yv){ self.Coord(Xv, Yv); return std::tuple<Standard_Real &, Standard_Real &>(Xv, Yv); }, "For this vector, returns its two coordinates Xv and Yv", py::arg("Xv"), py::arg("Yv"));
cls_gp_Vec2d.def("X", (Standard_Real (gp_Vec2d::*)() const) &gp_Vec2d::X, "For this vector, returns its X coordinate.");
cls_gp_Vec2d.def("Y", (Standard_Real (gp_Vec2d::*)() const) &gp_Vec2d::Y, "For this vector, returns its Y coordinate.");
cls_gp_Vec2d.def("XY", (const gp_XY & (gp_Vec2d::*)() const) &gp_Vec2d::XY, "For this vector, returns its two coordinates as a number pair");
cls_gp_Vec2d.def("IsEqual", (Standard_Boolean (gp_Vec2d::*)(const gp_Vec2d &, const Standard_Real, const Standard_Real) const) &gp_Vec2d::IsEqual, "Returns True if the two vectors have the same magnitude value and the same direction. The precision values are LinearTolerance for the magnitude and AngularTolerance for the direction.", py::arg("Other"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Vec2d.def("IsNormal", (Standard_Boolean (gp_Vec2d::*)(const gp_Vec2d &, const Standard_Real) const) &gp_Vec2d::IsNormal, "Returns True if abs(Abs(<me>.Angle(Other)) - PI/2.) <= AngularTolerance Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or Other.Magnitude() <= Resolution from gp.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Vec2d.def("IsOpposite", (Standard_Boolean (gp_Vec2d::*)(const gp_Vec2d &, const Standard_Real) const) &gp_Vec2d::IsOpposite, "Returns True if PI - Abs(<me>.Angle(Other)) <= AngularTolerance Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or Other.Magnitude() <= Resolution from gp.", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Vec2d.def("IsParallel", (Standard_Boolean (gp_Vec2d::*)(const gp_Vec2d &, const Standard_Real) const) &gp_Vec2d::IsParallel, "Returns true if Abs(Angle(<me>, Other)) <= AngularTolerance or PI - Abs(Angle(<me>, Other)) <= AngularTolerance Two vectors with opposite directions are considered as parallel. Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or Other.Magnitude() <= Resolution from gp", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Vec2d.def("Angle", (Standard_Real (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::Angle, "Computes the angular value between <me> and <Other> returns the angle value between -PI and PI in radian. The orientation is from <me> to Other. The positive sense is the trigonometric sense. Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution from gp or Other.Magnitude() <= Resolution because the angular value is indefinite if one of the vectors has a null magnitude.", py::arg("Other"));
cls_gp_Vec2d.def("Magnitude", (Standard_Real (gp_Vec2d::*)() const) &gp_Vec2d::Magnitude, "Computes the magnitude of this vector.");
cls_gp_Vec2d.def("SquareMagnitude", (Standard_Real (gp_Vec2d::*)() const) &gp_Vec2d::SquareMagnitude, "Computes the square magnitude of this vector.");
cls_gp_Vec2d.def("Add", (void (gp_Vec2d::*)(const gp_Vec2d &)) &gp_Vec2d::Add, "None", py::arg("Other"));
cls_gp_Vec2d.def("__iadd__", (void (gp_Vec2d::*)(const gp_Vec2d &)) &gp_Vec2d::operator+=, py::is_operator(), "None", py::arg("Other"));
cls_gp_Vec2d.def("Added", (gp_Vec2d (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::Added, "Adds two vectors", py::arg("Other"));
cls_gp_Vec2d.def("__add__", (gp_Vec2d (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::operator+, py::is_operator(), "None", py::arg("Other"));
cls_gp_Vec2d.def("Crossed", (Standard_Real (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::Crossed, "Computes the crossing product between two vectors", py::arg("Right"));
cls_gp_Vec2d.def("operator^", (Standard_Real (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::operator^, "None", py::arg("Right"));
cls_gp_Vec2d.def("CrossMagnitude", (Standard_Real (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::CrossMagnitude, "Computes the magnitude of the cross product between <me> and Right. Returns || <me> ^ Right ||", py::arg("Right"));
cls_gp_Vec2d.def("CrossSquareMagnitude", (Standard_Real (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::CrossSquareMagnitude, "Computes the square magnitude of the cross product between <me> and Right. Returns || <me> ^ Right ||**2", py::arg("Right"));
cls_gp_Vec2d.def("Divide", (void (gp_Vec2d::*)(const Standard_Real)) &gp_Vec2d::Divide, "None", py::arg("Scalar"));
cls_gp_Vec2d.def("__itruediv__", (void (gp_Vec2d::*)(const Standard_Real)) &gp_Vec2d::operator/=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Vec2d.def("Divided", (gp_Vec2d (gp_Vec2d::*)(const Standard_Real) const) &gp_Vec2d::Divided, "divides a vector by a scalar", py::arg("Scalar"));
cls_gp_Vec2d.def("__truediv__", (gp_Vec2d (gp_Vec2d::*)(const Standard_Real) const) &gp_Vec2d::operator/, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Vec2d.def("Dot", (Standard_Real (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::Dot, "Computes the scalar product", py::arg("Other"));
cls_gp_Vec2d.def("__mul__", (Standard_Real (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::operator*, py::is_operator(), "None", py::arg("Other"));
cls_gp_Vec2d.def("GetNormal", (gp_Vec2d (gp_Vec2d::*)() const) &gp_Vec2d::GetNormal, "None");
cls_gp_Vec2d.def("Multiply", (void (gp_Vec2d::*)(const Standard_Real)) &gp_Vec2d::Multiply, "None", py::arg("Scalar"));
cls_gp_Vec2d.def("__imul__", (void (gp_Vec2d::*)(const Standard_Real)) &gp_Vec2d::operator*=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Vec2d.def("Multiplied", (gp_Vec2d (gp_Vec2d::*)(const Standard_Real) const) &gp_Vec2d::Multiplied, "Normalizes a vector Raises an exception if the magnitude of the vector is lower or equal to Resolution from package gp.", py::arg("Scalar"));
cls_gp_Vec2d.def("__mul__", (gp_Vec2d (gp_Vec2d::*)(const Standard_Real) const) &gp_Vec2d::operator*, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Vec2d.def("Normalize", (void (gp_Vec2d::*)()) &gp_Vec2d::Normalize, "None");
cls_gp_Vec2d.def("Normalized", (gp_Vec2d (gp_Vec2d::*)() const) &gp_Vec2d::Normalized, "Normalizes a vector Raises an exception if the magnitude of the vector is lower or equal to Resolution from package gp. Reverses the direction of a vector");
cls_gp_Vec2d.def("Reverse", (void (gp_Vec2d::*)()) &gp_Vec2d::Reverse, "None");
cls_gp_Vec2d.def("Reversed", (gp_Vec2d (gp_Vec2d::*)() const) &gp_Vec2d::Reversed, "Reverses the direction of a vector");
cls_gp_Vec2d.def("__sub__", (gp_Vec2d (gp_Vec2d::*)() const) &gp_Vec2d::operator-, py::is_operator(), "None");
cls_gp_Vec2d.def("Subtract", (void (gp_Vec2d::*)(const gp_Vec2d &)) &gp_Vec2d::Subtract, "Subtracts two vectors", py::arg("Right"));
cls_gp_Vec2d.def("__isub__", (void (gp_Vec2d::*)(const gp_Vec2d &)) &gp_Vec2d::operator-=, py::is_operator(), "None", py::arg("Right"));
cls_gp_Vec2d.def("Subtracted", (gp_Vec2d (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::Subtracted, "Subtracts two vectors", py::arg("Right"));
cls_gp_Vec2d.def("__sub__", (gp_Vec2d (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::operator-, py::is_operator(), "None", py::arg("Right"));
cls_gp_Vec2d.def("SetLinearForm", (void (gp_Vec2d::*)(const Standard_Real, const gp_Vec2d &, const Standard_Real, const gp_Vec2d &, const gp_Vec2d &)) &gp_Vec2d::SetLinearForm, "<me> is set to the following linear form : A1 * V1 + A2 * V2 + V3", py::arg("A1"), py::arg("V1"), py::arg("A2"), py::arg("V2"), py::arg("V3"));
cls_gp_Vec2d.def("SetLinearForm", (void (gp_Vec2d::*)(const Standard_Real, const gp_Vec2d &, const Standard_Real, const gp_Vec2d &)) &gp_Vec2d::SetLinearForm, "<me> is set to the following linear form : A1 * V1 + A2 * V2", py::arg("A1"), py::arg("V1"), py::arg("A2"), py::arg("V2"));
cls_gp_Vec2d.def("SetLinearForm", (void (gp_Vec2d::*)(const Standard_Real, const gp_Vec2d &, const gp_Vec2d &)) &gp_Vec2d::SetLinearForm, "<me> is set to the following linear form : A1 * V1 + V2", py::arg("A1"), py::arg("V1"), py::arg("V2"));
cls_gp_Vec2d.def("SetLinearForm", (void (gp_Vec2d::*)(const gp_Vec2d &, const gp_Vec2d &)) &gp_Vec2d::SetLinearForm, "<me> is set to the following linear form : Left + Right", py::arg("Left"), py::arg("Right"));
cls_gp_Vec2d.def("Mirror", (void (gp_Vec2d::*)(const gp_Vec2d &)) &gp_Vec2d::Mirror, "Performs the symmetrical transformation of a vector with respect to the vector V which is the center of the symmetry.", py::arg("V"));
cls_gp_Vec2d.def("Mirrored", (gp_Vec2d (gp_Vec2d::*)(const gp_Vec2d &) const) &gp_Vec2d::Mirrored, "Performs the symmetrical transformation of a vector with respect to the vector V which is the center of the symmetry.", py::arg("V"));
cls_gp_Vec2d.def("Mirror", (void (gp_Vec2d::*)(const gp_Ax2d &)) &gp_Vec2d::Mirror, "Performs the symmetrical transformation of a vector with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Vec2d.def("Mirrored", (gp_Vec2d (gp_Vec2d::*)(const gp_Ax2d &) const) &gp_Vec2d::Mirrored, "Performs the symmetrical transformation of a vector with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Vec2d.def("Rotate", (void (gp_Vec2d::*)(const Standard_Real)) &gp_Vec2d::Rotate, "None", py::arg("Ang"));
cls_gp_Vec2d.def("Rotated", (gp_Vec2d (gp_Vec2d::*)(const Standard_Real) const) &gp_Vec2d::Rotated, "Rotates a vector. Ang is the angular value of the rotation in radians.", py::arg("Ang"));
cls_gp_Vec2d.def("Scale", (void (gp_Vec2d::*)(const Standard_Real)) &gp_Vec2d::Scale, "None", py::arg("S"));
cls_gp_Vec2d.def("Scaled", (gp_Vec2d (gp_Vec2d::*)(const Standard_Real) const) &gp_Vec2d::Scaled, "Scales a vector. S is the scaling value.", py::arg("S"));
cls_gp_Vec2d.def("Transform", (void (gp_Vec2d::*)(const gp_Trsf2d &)) &gp_Vec2d::Transform, "None", py::arg("T"));
cls_gp_Vec2d.def("Transformed", (gp_Vec2d (gp_Vec2d::*)(const gp_Trsf2d &) const) &gp_Vec2d::Transformed, "Transforms a vector with a Trsf from gp.", py::arg("T"));

// Enums

}