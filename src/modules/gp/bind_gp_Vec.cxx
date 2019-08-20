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
#include <gp_Dir.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Trsf.hxx>

void bind_gp_Vec(py::module &mod){

py::class_<gp_Vec, std::unique_ptr<gp_Vec>> cls_gp_Vec(mod, "gp_Vec", "Defines a non-persistent vector in 3D space.");

// Constructors
cls_gp_Vec.def(py::init<>());
cls_gp_Vec.def(py::init<const gp_Dir &>(), py::arg("V"));
cls_gp_Vec.def(py::init<const gp_XYZ &>(), py::arg("Coord"));
cls_gp_Vec.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));
cls_gp_Vec.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_gp_Vec.def_static("operator new_", (void * (*)(size_t)) &gp_Vec::operator new, "None", py::arg("theSize"));
// cls_gp_Vec.def_static("operator delete_", (void (*)(void *)) &gp_Vec::operator delete, "None", py::arg("theAddress"));
// cls_gp_Vec.def_static("operator new[]_", (void * (*)(size_t)) &gp_Vec::operator new[], "None", py::arg("theSize"));
// cls_gp_Vec.def_static("operator delete[]_", (void (*)(void *)) &gp_Vec::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Vec.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Vec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Vec.def_static("operator delete_", (void (*)(void *, void *)) &gp_Vec::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Vec.def("SetCoord", (void (gp_Vec::*)(const Standard_Integer, const Standard_Real)) &gp_Vec::SetCoord, "Changes the coordinate of range Index Index = 1 => X is modified Index = 2 => Y is modified Index = 3 => Z is modified Raised if Index != {1, 2, 3}.", py::arg("Index"), py::arg("Xi"));
cls_gp_Vec.def("SetCoord", (void (gp_Vec::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Vec::SetCoord, "For this vector, assigns - the values Xv, Yv and Zv to its three coordinates.", py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));
cls_gp_Vec.def("SetX", (void (gp_Vec::*)(const Standard_Real)) &gp_Vec::SetX, "Assigns the given value to the X coordinate of this vector.", py::arg("X"));
cls_gp_Vec.def("SetY", (void (gp_Vec::*)(const Standard_Real)) &gp_Vec::SetY, "Assigns the given value to the X coordinate of this vector.", py::arg("Y"));
cls_gp_Vec.def("SetZ", (void (gp_Vec::*)(const Standard_Real)) &gp_Vec::SetZ, "Assigns the given value to the X coordinate of this vector.", py::arg("Z"));
cls_gp_Vec.def("SetXYZ", (void (gp_Vec::*)(const gp_XYZ &)) &gp_Vec::SetXYZ, "Assigns the three coordinates of Coord to this vector.", py::arg("Coord"));
cls_gp_Vec.def("Coord", (Standard_Real (gp_Vec::*)(const Standard_Integer) const) &gp_Vec::Coord, "Returns the coordinate of range Index : Index = 1 => X is returned Index = 2 => Y is returned Index = 3 => Z is returned Raised if Index != {1, 2, 3}.", py::arg("Index"));
cls_gp_Vec.def("Coord", [](gp_Vec &self, Standard_Real & Xv, Standard_Real & Yv, Standard_Real & Zv){ self.Coord(Xv, Yv, Zv); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Xv, Yv, Zv); }, "For this vector returns its three coordinates Xv, Yv, and Zvinline", py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));
cls_gp_Vec.def("X", (Standard_Real (gp_Vec::*)() const) &gp_Vec::X, "For this vector, returns its X coordinate.");
cls_gp_Vec.def("Y", (Standard_Real (gp_Vec::*)() const) &gp_Vec::Y, "For this vector, returns its Y coordinate.");
cls_gp_Vec.def("Z", (Standard_Real (gp_Vec::*)() const) &gp_Vec::Z, "For this vector, returns its Z coordinate.");
cls_gp_Vec.def("XYZ", (const gp_XYZ & (gp_Vec::*)() const) &gp_Vec::XYZ, "For this vector, returns - its three coordinates as a number triple");
cls_gp_Vec.def("IsEqual", (Standard_Boolean (gp_Vec::*)(const gp_Vec &, const Standard_Real, const Standard_Real) const) &gp_Vec::IsEqual, "Returns True if the two vectors have the same magnitude value and the same direction. The precision values are LinearTolerance for the magnitude and AngularTolerance for the direction.", py::arg("Other"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Vec.def("IsNormal", (Standard_Boolean (gp_Vec::*)(const gp_Vec &, const Standard_Real) const) &gp_Vec::IsNormal, "Returns True if abs(<me>.Angle(Other) - PI/2.) <= AngularTolerance Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or Other.Magnitude() <= Resolution from gp", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Vec.def("IsOpposite", (Standard_Boolean (gp_Vec::*)(const gp_Vec &, const Standard_Real) const) &gp_Vec::IsOpposite, "Returns True if PI - <me>.Angle(Other) <= AngularTolerance Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or Other.Magnitude() <= Resolution from gp", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Vec.def("IsParallel", (Standard_Boolean (gp_Vec::*)(const gp_Vec &, const Standard_Real) const) &gp_Vec::IsParallel, "Returns True if Angle(<me>, Other) <= AngularTolerance or PI - Angle(<me>, Other) <= AngularTolerance This definition means that two parallel vectors cannot define a plane but two vectors with opposite directions are considered as parallel. Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution or Other.Magnitude() <= Resolution from gp", py::arg("Other"), py::arg("AngularTolerance"));
cls_gp_Vec.def("Angle", (Standard_Real (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::Angle, "Computes the angular value between <me> and <Other> Returns the angle value between 0 and PI in radian. Raises VectorWithNullMagnitude if <me>.Magnitude() <= Resolution from gp or Other.Magnitude() <= Resolution because the angular value is indefinite if one of the vectors has a null magnitude.", py::arg("Other"));
cls_gp_Vec.def("AngleWithRef", (Standard_Real (gp_Vec::*)(const gp_Vec &, const gp_Vec &) const) &gp_Vec::AngleWithRef, "Computes the angle, in radians, between this vector and vector Other. The result is a value between -Pi and Pi. For this, VRef defines the positive sense of rotation: the angular value is positive, if the cross product this ^ Other has the same orientation as VRef relative to the plane defined by the vectors this and Other. Otherwise, the angular value is negative. Exceptions gp_VectorWithNullMagnitude if the magnitude of this vector, the vector Other, or the vector VRef is less than or equal to gp::Resolution(). Standard_DomainError if this vector, the vector Other, and the vector VRef are coplanar, unless this vector and the vector Other are parallel.", py::arg("Other"), py::arg("VRef"));
cls_gp_Vec.def("Magnitude", (Standard_Real (gp_Vec::*)() const) &gp_Vec::Magnitude, "Computes the magnitude of this vector.");
cls_gp_Vec.def("SquareMagnitude", (Standard_Real (gp_Vec::*)() const) &gp_Vec::SquareMagnitude, "Computes the square magnitude of this vector.");
cls_gp_Vec.def("Add", (void (gp_Vec::*)(const gp_Vec &)) &gp_Vec::Add, "Adds two vectors", py::arg("Other"));
cls_gp_Vec.def("__iadd__", (void (gp_Vec::*)(const gp_Vec &)) &gp_Vec::operator+=, py::is_operator(), "None", py::arg("Other"));
cls_gp_Vec.def("Added", (gp_Vec (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::Added, "Adds two vectors", py::arg("Other"));
cls_gp_Vec.def("__add__", (gp_Vec (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::operator+, py::is_operator(), "None", py::arg("Other"));
cls_gp_Vec.def("Subtract", (void (gp_Vec::*)(const gp_Vec &)) &gp_Vec::Subtract, "Subtracts two vectors", py::arg("Right"));
cls_gp_Vec.def("__isub__", (void (gp_Vec::*)(const gp_Vec &)) &gp_Vec::operator-=, py::is_operator(), "None", py::arg("Right"));
cls_gp_Vec.def("Subtracted", (gp_Vec (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::Subtracted, "Subtracts two vectors", py::arg("Right"));
cls_gp_Vec.def("__sub__", (gp_Vec (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::operator-, py::is_operator(), "None", py::arg("Right"));
cls_gp_Vec.def("Multiply", (void (gp_Vec::*)(const Standard_Real)) &gp_Vec::Multiply, "Multiplies a vector by a scalar", py::arg("Scalar"));
cls_gp_Vec.def("__imul__", (void (gp_Vec::*)(const Standard_Real)) &gp_Vec::operator*=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Vec.def("Multiplied", (gp_Vec (gp_Vec::*)(const Standard_Real) const) &gp_Vec::Multiplied, "Multiplies a vector by a scalar", py::arg("Scalar"));
cls_gp_Vec.def("__mul__", (gp_Vec (gp_Vec::*)(const Standard_Real) const) &gp_Vec::operator*, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Vec.def("Divide", (void (gp_Vec::*)(const Standard_Real)) &gp_Vec::Divide, "Divides a vector by a scalar", py::arg("Scalar"));
cls_gp_Vec.def("__itruediv__", (void (gp_Vec::*)(const Standard_Real)) &gp_Vec::operator/=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Vec.def("Divided", (gp_Vec (gp_Vec::*)(const Standard_Real) const) &gp_Vec::Divided, "Divides a vector by a scalar", py::arg("Scalar"));
cls_gp_Vec.def("__truediv__", (gp_Vec (gp_Vec::*)(const Standard_Real) const) &gp_Vec::operator/, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Vec.def("Cross", (void (gp_Vec::*)(const gp_Vec &)) &gp_Vec::Cross, "computes the cross product between two vectors", py::arg("Right"));
cls_gp_Vec.def("operator^=", (void (gp_Vec::*)(const gp_Vec &)) &gp_Vec::operator^=, "None", py::arg("Right"));
cls_gp_Vec.def("Crossed", (gp_Vec (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::Crossed, "computes the cross product between two vectors", py::arg("Right"));
cls_gp_Vec.def("operator^", (gp_Vec (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::operator^, "None", py::arg("Right"));
cls_gp_Vec.def("CrossMagnitude", (Standard_Real (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::CrossMagnitude, "Computes the magnitude of the cross product between <me> and Right. Returns || <me> ^ Right ||", py::arg("Right"));
cls_gp_Vec.def("CrossSquareMagnitude", (Standard_Real (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::CrossSquareMagnitude, "Computes the square magnitude of the cross product between <me> and Right. Returns || <me> ^ Right ||**2", py::arg("Right"));
cls_gp_Vec.def("CrossCross", (void (gp_Vec::*)(const gp_Vec &, const gp_Vec &)) &gp_Vec::CrossCross, "Computes the triple vector product. <me> ^= (V1 ^ V2)", py::arg("V1"), py::arg("V2"));
cls_gp_Vec.def("CrossCrossed", (gp_Vec (gp_Vec::*)(const gp_Vec &, const gp_Vec &) const) &gp_Vec::CrossCrossed, "Computes the triple vector product. <me> ^ (V1 ^ V2)", py::arg("V1"), py::arg("V2"));
cls_gp_Vec.def("Dot", (Standard_Real (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::Dot, "computes the scalar product", py::arg("Other"));
cls_gp_Vec.def("__mul__", (Standard_Real (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::operator*, py::is_operator(), "None", py::arg("Other"));
cls_gp_Vec.def("DotCross", (Standard_Real (gp_Vec::*)(const gp_Vec &, const gp_Vec &) const) &gp_Vec::DotCross, "Computes the triple scalar product <me> * (V1 ^ V2).", py::arg("V1"), py::arg("V2"));
cls_gp_Vec.def("Normalize", (void (gp_Vec::*)()) &gp_Vec::Normalize, "normalizes a vector Raises an exception if the magnitude of the vector is lower or equal to Resolution from gp.");
cls_gp_Vec.def("Normalized", (gp_Vec (gp_Vec::*)() const) &gp_Vec::Normalized, "normalizes a vector Raises an exception if the magnitude of the vector is lower or equal to Resolution from gp.");
cls_gp_Vec.def("Reverse", (void (gp_Vec::*)()) &gp_Vec::Reverse, "Reverses the direction of a vector");
cls_gp_Vec.def("Reversed", (gp_Vec (gp_Vec::*)() const) &gp_Vec::Reversed, "Reverses the direction of a vector");
cls_gp_Vec.def("__sub__", (gp_Vec (gp_Vec::*)() const) &gp_Vec::operator-, py::is_operator(), "None");
cls_gp_Vec.def("SetLinearForm", (void (gp_Vec::*)(const Standard_Real, const gp_Vec &, const Standard_Real, const gp_Vec &, const Standard_Real, const gp_Vec &, const gp_Vec &)) &gp_Vec::SetLinearForm, "<me> is set to the following linear form : A1 * V1 + A2 * V2 + A3 * V3 + V4", py::arg("A1"), py::arg("V1"), py::arg("A2"), py::arg("V2"), py::arg("A3"), py::arg("V3"), py::arg("V4"));
cls_gp_Vec.def("SetLinearForm", (void (gp_Vec::*)(const Standard_Real, const gp_Vec &, const Standard_Real, const gp_Vec &, const Standard_Real, const gp_Vec &)) &gp_Vec::SetLinearForm, "<me> is set to the following linear form : A1 * V1 + A2 * V2 + A3 * V3", py::arg("A1"), py::arg("V1"), py::arg("A2"), py::arg("V2"), py::arg("A3"), py::arg("V3"));
cls_gp_Vec.def("SetLinearForm", (void (gp_Vec::*)(const Standard_Real, const gp_Vec &, const Standard_Real, const gp_Vec &, const gp_Vec &)) &gp_Vec::SetLinearForm, "<me> is set to the following linear form : A1 * V1 + A2 * V2 + V3", py::arg("A1"), py::arg("V1"), py::arg("A2"), py::arg("V2"), py::arg("V3"));
cls_gp_Vec.def("SetLinearForm", (void (gp_Vec::*)(const Standard_Real, const gp_Vec &, const Standard_Real, const gp_Vec &)) &gp_Vec::SetLinearForm, "<me> is set to the following linear form : A1 * V1 + A2 * V2", py::arg("A1"), py::arg("V1"), py::arg("A2"), py::arg("V2"));
cls_gp_Vec.def("SetLinearForm", (void (gp_Vec::*)(const Standard_Real, const gp_Vec &, const gp_Vec &)) &gp_Vec::SetLinearForm, "<me> is set to the following linear form : A1 * V1 + V2", py::arg("A1"), py::arg("V1"), py::arg("V2"));
cls_gp_Vec.def("SetLinearForm", (void (gp_Vec::*)(const gp_Vec &, const gp_Vec &)) &gp_Vec::SetLinearForm, "<me> is set to the following linear form : V1 + V2", py::arg("V1"), py::arg("V2"));
cls_gp_Vec.def("Mirror", (void (gp_Vec::*)(const gp_Vec &)) &gp_Vec::Mirror, "None", py::arg("V"));
cls_gp_Vec.def("Mirrored", (gp_Vec (gp_Vec::*)(const gp_Vec &) const) &gp_Vec::Mirrored, "Performs the symmetrical transformation of a vector with respect to the vector V which is the center of the symmetry.", py::arg("V"));
cls_gp_Vec.def("Mirror", (void (gp_Vec::*)(const gp_Ax1 &)) &gp_Vec::Mirror, "None", py::arg("A1"));
cls_gp_Vec.def("Mirrored", (gp_Vec (gp_Vec::*)(const gp_Ax1 &) const) &gp_Vec::Mirrored, "Performs the symmetrical transformation of a vector with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Vec.def("Mirror", (void (gp_Vec::*)(const gp_Ax2 &)) &gp_Vec::Mirror, "None", py::arg("A2"));
cls_gp_Vec.def("Mirrored", (gp_Vec (gp_Vec::*)(const gp_Ax2 &) const) &gp_Vec::Mirrored, "Performs the symmetrical transformation of a vector with respect to a plane. The axis placement A2 locates the plane of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Vec.def("Rotate", (void (gp_Vec::*)(const gp_Ax1 &, const Standard_Real)) &gp_Vec::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Vec.def("Rotated", (gp_Vec (gp_Vec::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Vec::Rotated, "Rotates a vector. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Vec.def("Scale", (void (gp_Vec::*)(const Standard_Real)) &gp_Vec::Scale, "None", py::arg("S"));
cls_gp_Vec.def("Scaled", (gp_Vec (gp_Vec::*)(const Standard_Real) const) &gp_Vec::Scaled, "Scales a vector. S is the scaling value.", py::arg("S"));
cls_gp_Vec.def("Transform", (void (gp_Vec::*)(const gp_Trsf &)) &gp_Vec::Transform, "Transforms a vector with the transformation T.", py::arg("T"));
cls_gp_Vec.def("Transformed", (gp_Vec (gp_Vec::*)(const gp_Trsf &) const) &gp_Vec::Transformed, "Transforms a vector with the transformation T.", py::arg("T"));

// Enums

}