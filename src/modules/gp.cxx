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
#include <gp_TrsfForm.hxx>
#include <gp_EulerSequence.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <gp_Mat2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Ax2d.hxx>
#include <gp_XYZ.hxx>
#include <gp_Mat.hxx>
#include <gp_Quaternion.hxx>
#include <gp_Trsf.hxx>
#include <gp_GTrsf.hxx>
#include <gp_Vec.hxx>
#include <gp_Ax3.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <gp_Cone.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_GTrsf2d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp.hxx>
#include <NCollection_Mat4.hxx>
#include <Standard_DomainError.hxx>
#include <Standard_Handle.hxx>
#include <gp_VectorWithNullMagnitude.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_QuaternionNLerp.hxx>
#include <Precision.hxx>
#include <NCollection_Lerp.hxx>
#include <gp_TrsfNLerp.hxx>
#include <gp_QuaternionSLerp.hxx>

PYBIND11_MODULE(gp, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Precision");

// ENUM: GP_TRSFFORM
py::enum_<gp_TrsfForm>(mod, "gp_TrsfForm", "Identifies the type of a geometric transformation.")
	.value("gp_Identity", gp_TrsfForm::gp_Identity)
	.value("gp_Rotation", gp_TrsfForm::gp_Rotation)
	.value("gp_Translation", gp_TrsfForm::gp_Translation)
	.value("gp_PntMirror", gp_TrsfForm::gp_PntMirror)
	.value("gp_Ax1Mirror", gp_TrsfForm::gp_Ax1Mirror)
	.value("gp_Ax2Mirror", gp_TrsfForm::gp_Ax2Mirror)
	.value("gp_Scale", gp_TrsfForm::gp_Scale)
	.value("gp_CompoundTrsf", gp_TrsfForm::gp_CompoundTrsf)
	.value("gp_Other", gp_TrsfForm::gp_Other)
	.export_values();


// ENUM: GP_EULERSEQUENCE
py::enum_<gp_EulerSequence>(mod, "gp_EulerSequence", "Enumerates all 24 possible variants of generalized Euler angles, defining general 3d rotation by three rotations around main axes of coordinate system, in different possible orders.")
	.value("gp_EulerAngles", gp_EulerSequence::gp_EulerAngles)
	.value("gp_YawPitchRoll", gp_EulerSequence::gp_YawPitchRoll)
	.value("gp_Extrinsic_XYZ", gp_EulerSequence::gp_Extrinsic_XYZ)
	.value("gp_Extrinsic_XZY", gp_EulerSequence::gp_Extrinsic_XZY)
	.value("gp_Extrinsic_YZX", gp_EulerSequence::gp_Extrinsic_YZX)
	.value("gp_Extrinsic_YXZ", gp_EulerSequence::gp_Extrinsic_YXZ)
	.value("gp_Extrinsic_ZXY", gp_EulerSequence::gp_Extrinsic_ZXY)
	.value("gp_Extrinsic_ZYX", gp_EulerSequence::gp_Extrinsic_ZYX)
	.value("gp_Intrinsic_XYZ", gp_EulerSequence::gp_Intrinsic_XYZ)
	.value("gp_Intrinsic_XZY", gp_EulerSequence::gp_Intrinsic_XZY)
	.value("gp_Intrinsic_YZX", gp_EulerSequence::gp_Intrinsic_YZX)
	.value("gp_Intrinsic_YXZ", gp_EulerSequence::gp_Intrinsic_YXZ)
	.value("gp_Intrinsic_ZXY", gp_EulerSequence::gp_Intrinsic_ZXY)
	.value("gp_Intrinsic_ZYX", gp_EulerSequence::gp_Intrinsic_ZYX)
	.value("gp_Extrinsic_XYX", gp_EulerSequence::gp_Extrinsic_XYX)
	.value("gp_Extrinsic_XZX", gp_EulerSequence::gp_Extrinsic_XZX)
	.value("gp_Extrinsic_YZY", gp_EulerSequence::gp_Extrinsic_YZY)
	.value("gp_Extrinsic_YXY", gp_EulerSequence::gp_Extrinsic_YXY)
	.value("gp_Extrinsic_ZYZ", gp_EulerSequence::gp_Extrinsic_ZYZ)
	.value("gp_Extrinsic_ZXZ", gp_EulerSequence::gp_Extrinsic_ZXZ)
	.value("gp_Intrinsic_XYX", gp_EulerSequence::gp_Intrinsic_XYX)
	.value("gp_Intrinsic_XZX", gp_EulerSequence::gp_Intrinsic_XZX)
	.value("gp_Intrinsic_YZY", gp_EulerSequence::gp_Intrinsic_YZY)
	.value("gp_Intrinsic_YXY", gp_EulerSequence::gp_Intrinsic_YXY)
	.value("gp_Intrinsic_ZXZ", gp_EulerSequence::gp_Intrinsic_ZXZ)
	.value("gp_Intrinsic_ZYZ", gp_EulerSequence::gp_Intrinsic_ZYZ)
	.export_values();


// CLASS: GP_XY
py::class_<gp_XY> cls_gp_XY(mod, "gp_XY", "This class describes a cartesian coordinate entity in 2D space {X,Y}. This class is non persistent. This entity used for algebraic calculation. An XY can be transformed with a Trsf2d or a GTrsf2d from package gp. It is used in vectorial computations or for holding this type of information in data structures.");

// Constructors
cls_gp_XY.def(py::init<>());
cls_gp_XY.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"));

// Methods
// cls_gp_XY.def_static("operator new_", (void * (*)(size_t)) &gp_XY::operator new, "None", py::arg("theSize"));
// cls_gp_XY.def_static("operator delete_", (void (*)(void *)) &gp_XY::operator delete, "None", py::arg("theAddress"));
// cls_gp_XY.def_static("operator new[]_", (void * (*)(size_t)) &gp_XY::operator new[], "None", py::arg("theSize"));
// cls_gp_XY.def_static("operator delete[]_", (void (*)(void *)) &gp_XY::operator delete[], "None", py::arg("theAddress"));
// cls_gp_XY.def_static("operator new_", (void * (*)(size_t, void *)) &gp_XY::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_XY.def_static("operator delete_", (void (*)(void *, void *)) &gp_XY::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_XY.def("SetCoord", (void (gp_XY::*)(const Standard_Integer, const Standard_Real)) &gp_XY::SetCoord, "modifies the coordinate of range Index Index = 1 => X is modified Index = 2 => Y is modified Raises OutOfRange if Index != {1, 2}.", py::arg("Index"), py::arg("Xi"));
cls_gp_XY.def("SetCoord", (void (gp_XY::*)(const Standard_Real, const Standard_Real)) &gp_XY::SetCoord, "For this number pair, assigns the values X and Y to its coordinates", py::arg("X"), py::arg("Y"));
cls_gp_XY.def("SetX", (void (gp_XY::*)(const Standard_Real)) &gp_XY::SetX, "Assigns the given value to the X coordinate of this number pair.", py::arg("X"));
cls_gp_XY.def("SetY", (void (gp_XY::*)(const Standard_Real)) &gp_XY::SetY, "Assigns the given value to the Y coordinate of this number pair.", py::arg("Y"));
cls_gp_XY.def("Coord", (Standard_Real (gp_XY::*)(const Standard_Integer) const) &gp_XY::Coord, "returns the coordinate of range Index : Index = 1 => X is returned Index = 2 => Y is returned Raises OutOfRange if Index != {1, 2}.", py::arg("Index"));
cls_gp_XY.def("ChangeCoord", (Standard_Real & (gp_XY::*)(const Standard_Integer)) &gp_XY::ChangeCoord, "None", py::arg("theIndex"));
cls_gp_XY.def("Coord", [](gp_XY &self, Standard_Real & X, Standard_Real & Y){ self.Coord(X, Y); return std::tuple<Standard_Real &, Standard_Real &>(X, Y); }, "For this number pair, returns its coordinates X and Y.", py::arg("X"), py::arg("Y"));
cls_gp_XY.def("X", (Standard_Real (gp_XY::*)() const) &gp_XY::X, "Returns the X coordinate of this number pair.");
cls_gp_XY.def("Y", (Standard_Real (gp_XY::*)() const) &gp_XY::Y, "Returns the Y coordinate of this number pair.");
cls_gp_XY.def("Modulus", (Standard_Real (gp_XY::*)() const) &gp_XY::Modulus, "Computes Sqrt (X*X + Y*Y) where X and Y are the two coordinates of this number pair.");
cls_gp_XY.def("SquareModulus", (Standard_Real (gp_XY::*)() const) &gp_XY::SquareModulus, "Computes X*X + Y*Y where X and Y are the two coordinates of this number pair.");
cls_gp_XY.def("IsEqual", (Standard_Boolean (gp_XY::*)(const gp_XY &, const Standard_Real) const) &gp_XY::IsEqual, "Returns true if the coordinates of this number pair are equal to the respective coordinates of the number pair Other, within the specified tolerance Tolerance. I.e.: abs(<me>.X() - Other.X()) <= Tolerance and abs(<me>.Y() - Other.Y()) <= Tolerance and computations", py::arg("Other"), py::arg("Tolerance"));
cls_gp_XY.def("Add", (void (gp_XY::*)(const gp_XY &)) &gp_XY::Add, "Computes the sum of this number pair and number pair Other <me>.X() = <me>.X() + Other.X() <me>.Y() = <me>.Y() + Other.Y()", py::arg("Other"));
cls_gp_XY.def("__iadd__", (void (gp_XY::*)(const gp_XY &)) &gp_XY::operator+=, py::is_operator(), "None", py::arg("Other"));
cls_gp_XY.def("Added", (gp_XY (gp_XY::*)(const gp_XY &) const) &gp_XY::Added, "Computes the sum of this number pair and number pair Other new.X() = <me>.X() + Other.X() new.Y() = <me>.Y() + Other.Y()", py::arg("Other"));
cls_gp_XY.def("__add__", (gp_XY (gp_XY::*)(const gp_XY &) const) &gp_XY::operator+, py::is_operator(), "None", py::arg("Other"));
cls_gp_XY.def("Crossed", (Standard_Real (gp_XY::*)(const gp_XY &) const) &gp_XY::Crossed, "Real D = <me>.X() * Other.Y() - <me>.Y() * Other.X()", py::arg("Right"));
cls_gp_XY.def("operator^", (Standard_Real (gp_XY::*)(const gp_XY &) const) &gp_XY::operator^, "None", py::arg("Right"));
cls_gp_XY.def("CrossMagnitude", (Standard_Real (gp_XY::*)(const gp_XY &) const) &gp_XY::CrossMagnitude, "computes the magnitude of the cross product between <me> and Right. Returns || <me> ^ Right ||", py::arg("Right"));
cls_gp_XY.def("CrossSquareMagnitude", (Standard_Real (gp_XY::*)(const gp_XY &) const) &gp_XY::CrossSquareMagnitude, "computes the square magnitude of the cross product between <me> and Right. Returns || <me> ^ Right ||**2", py::arg("Right"));
cls_gp_XY.def("Divide", (void (gp_XY::*)(const Standard_Real)) &gp_XY::Divide, "divides <me> by a real.", py::arg("Scalar"));
cls_gp_XY.def("__itruediv__", (void (gp_XY::*)(const Standard_Real)) &gp_XY::operator/=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_XY.def("Divided", (gp_XY (gp_XY::*)(const Standard_Real) const) &gp_XY::Divided, "Divides <me> by a real.", py::arg("Scalar"));
cls_gp_XY.def("__truediv__", (gp_XY (gp_XY::*)(const Standard_Real) const) &gp_XY::operator/, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_XY.def("Dot", (Standard_Real (gp_XY::*)(const gp_XY &) const) &gp_XY::Dot, "Computes the scalar product between <me> and Other", py::arg("Other"));
cls_gp_XY.def("__mul__", (Standard_Real (gp_XY::*)(const gp_XY &) const) &gp_XY::operator*, py::is_operator(), "None", py::arg("Other"));
cls_gp_XY.def("Multiply", (void (gp_XY::*)(const Standard_Real)) &gp_XY::Multiply, "<me>.X() = <me>.X() * Scalar; <me>.Y() = <me>.Y() * Scalar;", py::arg("Scalar"));
cls_gp_XY.def("__imul__", (void (gp_XY::*)(const Standard_Real)) &gp_XY::operator*=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_XY.def("Multiply", (void (gp_XY::*)(const gp_XY &)) &gp_XY::Multiply, "<me>.X() = <me>.X() * Other.X(); <me>.Y() = <me>.Y() * Other.Y();", py::arg("Other"));
cls_gp_XY.def("__imul__", (void (gp_XY::*)(const gp_XY &)) &gp_XY::operator*=, py::is_operator(), "None", py::arg("Other"));
cls_gp_XY.def("Multiply", (void (gp_XY::*)(const gp_Mat2d &)) &gp_XY::Multiply, "<me> = Matrix * <me>", py::arg("Matrix"));
cls_gp_XY.def("__imul__", (void (gp_XY::*)(const gp_Mat2d &)) &gp_XY::operator*=, py::is_operator(), "None", py::arg("Matrix"));
cls_gp_XY.def("Multiplied", (gp_XY (gp_XY::*)(const Standard_Real) const) &gp_XY::Multiplied, "New.X() = <me>.X() * Scalar; New.Y() = <me>.Y() * Scalar;", py::arg("Scalar"));
cls_gp_XY.def("__mul__", (gp_XY (gp_XY::*)(const Standard_Real) const) &gp_XY::operator*, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_XY.def("Multiplied", (gp_XY (gp_XY::*)(const gp_XY &) const) &gp_XY::Multiplied, "new.X() = <me>.X() * Other.X(); new.Y() = <me>.Y() * Other.Y();", py::arg("Other"));
cls_gp_XY.def("Multiplied", (gp_XY (gp_XY::*)(const gp_Mat2d &) const) &gp_XY::Multiplied, "New = Matrix * <me>", py::arg("Matrix"));
cls_gp_XY.def("__mul__", (gp_XY (gp_XY::*)(const gp_Mat2d &) const) &gp_XY::operator*, py::is_operator(), "None", py::arg("Matrix"));
cls_gp_XY.def("Normalize", (void (gp_XY::*)()) &gp_XY::Normalize, "<me>.X() = <me>.X()/ <me>.Modulus() <me>.Y() = <me>.Y()/ <me>.Modulus() Raises ConstructionError if <me>.Modulus() <= Resolution from gp");
cls_gp_XY.def("Normalized", (gp_XY (gp_XY::*)() const) &gp_XY::Normalized, "New.X() = <me>.X()/ <me>.Modulus() New.Y() = <me>.Y()/ <me>.Modulus() Raises ConstructionError if <me>.Modulus() <= Resolution from gp");
cls_gp_XY.def("Reverse", (void (gp_XY::*)()) &gp_XY::Reverse, "<me>.X() = -<me>.X() <me>.Y() = -<me>.Y()");
cls_gp_XY.def("Reversed", (gp_XY (gp_XY::*)() const) &gp_XY::Reversed, "New.X() = -<me>.X() New.Y() = -<me>.Y()");
cls_gp_XY.def("__sub__", (gp_XY (gp_XY::*)() const) &gp_XY::operator-, py::is_operator(), "None");
cls_gp_XY.def("SetLinearForm", (void (gp_XY::*)(const Standard_Real, const gp_XY &, const Standard_Real, const gp_XY &)) &gp_XY::SetLinearForm, "Computes the following linear combination and assigns the result to this number pair: A1 * XY1 + A2 * XY2", py::arg("A1"), py::arg("XY1"), py::arg("A2"), py::arg("XY2"));
cls_gp_XY.def("SetLinearForm", (void (gp_XY::*)(const Standard_Real, const gp_XY &, const Standard_Real, const gp_XY &, const gp_XY &)) &gp_XY::SetLinearForm, "-- Computes the following linear combination and assigns the result to this number pair: A1 * XY1 + A2 * XY2 + XY3", py::arg("A1"), py::arg("XY1"), py::arg("A2"), py::arg("XY2"), py::arg("XY3"));
cls_gp_XY.def("SetLinearForm", (void (gp_XY::*)(const Standard_Real, const gp_XY &, const gp_XY &)) &gp_XY::SetLinearForm, "Computes the following linear combination and assigns the result to this number pair: A1 * XY1 + XY2", py::arg("A1"), py::arg("XY1"), py::arg("XY2"));
cls_gp_XY.def("SetLinearForm", (void (gp_XY::*)(const gp_XY &, const gp_XY &)) &gp_XY::SetLinearForm, "Computes the following linear combination and assigns the result to this number pair: XY1 + XY2", py::arg("XY1"), py::arg("XY2"));
cls_gp_XY.def("Subtract", (void (gp_XY::*)(const gp_XY &)) &gp_XY::Subtract, "<me>.X() = <me>.X() - Other.X() <me>.Y() = <me>.Y() - Other.Y()", py::arg("Right"));
cls_gp_XY.def("__isub__", (void (gp_XY::*)(const gp_XY &)) &gp_XY::operator-=, py::is_operator(), "None", py::arg("Right"));
cls_gp_XY.def("Subtracted", (gp_XY (gp_XY::*)(const gp_XY &) const) &gp_XY::Subtracted, "new.X() = <me>.X() - Other.X() new.Y() = <me>.Y() - Other.Y()", py::arg("Right"));
cls_gp_XY.def("__sub__", (gp_XY (gp_XY::*)(const gp_XY &) const) &gp_XY::operator-, py::is_operator(), "None", py::arg("Right"));

// CLASS: GP
py::class_<gp> cls_gp(mod, "gp", "The geometric processor package, called gp, provides an implementation of entities used : . for algebraic calculation such as 'XYZ' coordinates, 'Mat' matrix . for basis analytic geometry such as Transformations, point, vector, line, plane, axis placement, conics, and elementary surfaces. These entities are defined in 2d and 3d space. All the classes of this package are non-persistent.");

// Methods
// cls_gp.def_static("operator new_", (void * (*)(size_t)) &gp::operator new, "None", py::arg("theSize"));
// cls_gp.def_static("operator delete_", (void (*)(void *)) &gp::operator delete, "None", py::arg("theAddress"));
// cls_gp.def_static("operator new[]_", (void * (*)(size_t)) &gp::operator new[], "None", py::arg("theSize"));
// cls_gp.def_static("operator delete[]_", (void (*)(void *)) &gp::operator delete[], "None", py::arg("theAddress"));
// cls_gp.def_static("operator new_", (void * (*)(size_t, void *)) &gp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp.def_static("operator delete_", (void (*)(void *, void *)) &gp::operator delete, "None", py::arg(""), py::arg(""));
cls_gp.def_static("Resolution_", (Standard_Real (*)()) &gp::Resolution, "Method of package gp");
cls_gp.def_static("Origin_", (const gp_Pnt & (*)()) &gp::Origin, "Identifies a Cartesian point with coordinates X = Y = Z = 0.0.0");
cls_gp.def_static("DX_", (const gp_Dir & (*)()) &gp::DX, "Returns a unit vector with the combination (1,0,0)");
cls_gp.def_static("DY_", (const gp_Dir & (*)()) &gp::DY, "Returns a unit vector with the combination (0,1,0)");
cls_gp.def_static("DZ_", (const gp_Dir & (*)()) &gp::DZ, "Returns a unit vector with the combination (0,0,1)");
cls_gp.def_static("OX_", (const gp_Ax1 & (*)()) &gp::OX, "Identifies an axis where its origin is Origin and its unit vector coordinates X = 1.0, Y = Z = 0.0");
cls_gp.def_static("OY_", (const gp_Ax1 & (*)()) &gp::OY, "Identifies an axis where its origin is Origin and its unit vector coordinates Y = 1.0, X = Z = 0.0");
cls_gp.def_static("OZ_", (const gp_Ax1 & (*)()) &gp::OZ, "Identifies an axis where its origin is Origin and its unit vector coordinates Z = 1.0, Y = X = 0.0");
cls_gp.def_static("XOY_", (const gp_Ax2 & (*)()) &gp::XOY, "Identifies a coordinate system where its origin is Origin, and its 'main Direction' and 'X Direction' coordinates Z = 1.0, X = Y =0.0 and X direction coordinates X = 1.0, Y = Z = 0.0");
cls_gp.def_static("ZOX_", (const gp_Ax2 & (*)()) &gp::ZOX, "Identifies a coordinate system where its origin is Origin, and its 'main Direction' and 'X Direction' coordinates Y = 1.0, X = Z =0.0 and X direction coordinates Z = 1.0, X = Y = 0.0");
cls_gp.def_static("YOZ_", (const gp_Ax2 & (*)()) &gp::YOZ, "Identifies a coordinate system where its origin is Origin, and its 'main Direction' and 'X Direction' coordinates X = 1.0, Z = Y =0.0 and X direction coordinates Y = 1.0, X = Z = 0.0 In 2D space");
cls_gp.def_static("Origin2d_", (const gp_Pnt2d & (*)()) &gp::Origin2d, "Identifies a Cartesian point with coordinates X = Y = 0.0");
cls_gp.def_static("DX2d_", (const gp_Dir2d & (*)()) &gp::DX2d, "Returns a unit vector with the combinations (1,0)");
cls_gp.def_static("DY2d_", (const gp_Dir2d & (*)()) &gp::DY2d, "Returns a unit vector with the combinations (0,1)");
cls_gp.def_static("OX2d_", (const gp_Ax2d & (*)()) &gp::OX2d, "Identifies an axis where its origin is Origin2d and its unit vector coordinates are: X = 1.0, Y = 0.0");
cls_gp.def_static("OY2d_", (const gp_Ax2d & (*)()) &gp::OY2d, "Identifies an axis where its origin is Origin2d and its unit vector coordinates are Y = 1.0, X = 0.0");

// CLASS: GP_MAT2D
py::class_<gp_Mat2d> cls_gp_Mat2d(mod, "gp_Mat2d", "Describes a two column, two row matrix. This sort of object is used in various vectorial or matrix computations.");

// Constructors
cls_gp_Mat2d.def(py::init<>());
cls_gp_Mat2d.def(py::init<const gp_XY &, const gp_XY &>(), py::arg("Col1"), py::arg("Col2"));

// Methods
// cls_gp_Mat2d.def_static("operator new_", (void * (*)(size_t)) &gp_Mat2d::operator new, "None", py::arg("theSize"));
// cls_gp_Mat2d.def_static("operator delete_", (void (*)(void *)) &gp_Mat2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Mat2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Mat2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Mat2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Mat2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Mat2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Mat2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Mat2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Mat2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Mat2d.def("SetCol", (void (gp_Mat2d::*)(const Standard_Integer, const gp_XY &)) &gp_Mat2d::SetCol, "Assigns the two coordinates of Value to the column of range Col of this matrix Raises OutOfRange if Col < 1 or Col > 2.", py::arg("Col"), py::arg("Value"));
cls_gp_Mat2d.def("SetCols", (void (gp_Mat2d::*)(const gp_XY &, const gp_XY &)) &gp_Mat2d::SetCols, "Assigns the number pairs Col1, Col2 to the two columns of this matrix", py::arg("Col1"), py::arg("Col2"));
cls_gp_Mat2d.def("SetDiagonal", (void (gp_Mat2d::*)(const Standard_Real, const Standard_Real)) &gp_Mat2d::SetDiagonal, "Modifies the main diagonal of the matrix. <me>.Value (1, 1) = X1 <me>.Value (2, 2) = X2 The other coefficients of the matrix are not modified.", py::arg("X1"), py::arg("X2"));
cls_gp_Mat2d.def("SetIdentity", (void (gp_Mat2d::*)()) &gp_Mat2d::SetIdentity, "Modifies this matrix, so that it represents the Identity matrix.");
cls_gp_Mat2d.def("SetRotation", (void (gp_Mat2d::*)(const Standard_Real)) &gp_Mat2d::SetRotation, "Modifies this matrix, so that it representso a rotation. Ang is the angular value in radian of the rotation.", py::arg("Ang"));
cls_gp_Mat2d.def("SetRow", (void (gp_Mat2d::*)(const Standard_Integer, const gp_XY &)) &gp_Mat2d::SetRow, "Assigns the two coordinates of Value to the row of index Row of this matrix. Raises OutOfRange if Row < 1 or Row > 2.", py::arg("Row"), py::arg("Value"));
cls_gp_Mat2d.def("SetRows", (void (gp_Mat2d::*)(const gp_XY &, const gp_XY &)) &gp_Mat2d::SetRows, "Assigns the number pairs Row1, Row2 to the two rows of this matrix.", py::arg("Row1"), py::arg("Row2"));
cls_gp_Mat2d.def("SetScale", (void (gp_Mat2d::*)(const Standard_Real)) &gp_Mat2d::SetScale, "Modifies the matrix such that it represents a scaling transformation, where S is the scale factor : | S 0.0 | <me> = | 0.0 S |", py::arg("S"));
cls_gp_Mat2d.def("SetValue", (void (gp_Mat2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &gp_Mat2d::SetValue, "Assigns <Value> to the coefficient of row Row, column Col of this matrix. Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 2", py::arg("Row"), py::arg("Col"), py::arg("Value"));
cls_gp_Mat2d.def("Column", (gp_XY (gp_Mat2d::*)(const Standard_Integer) const) &gp_Mat2d::Column, "Returns the column of Col index. Raises OutOfRange if Col < 1 or Col > 2", py::arg("Col"));
cls_gp_Mat2d.def("Determinant", (Standard_Real (gp_Mat2d::*)() const) &gp_Mat2d::Determinant, "Computes the determinant of the matrix.");
cls_gp_Mat2d.def("Diagonal", (gp_XY (gp_Mat2d::*)() const) &gp_Mat2d::Diagonal, "Returns the main diagonal of the matrix.");
cls_gp_Mat2d.def("Row", (gp_XY (gp_Mat2d::*)(const Standard_Integer) const) &gp_Mat2d::Row, "Returns the row of index Row. Raised if Row < 1 or Row > 2", py::arg("Row"));
cls_gp_Mat2d.def("Value", (const Standard_Real & (gp_Mat2d::*)(const Standard_Integer, const Standard_Integer) const) &gp_Mat2d::Value, "Returns the coefficient of range (Row, Col) Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 2", py::arg("Row"), py::arg("Col"));
cls_gp_Mat2d.def("__call__", (const Standard_Real & (gp_Mat2d::*)(const Standard_Integer, const Standard_Integer) const) &gp_Mat2d::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
cls_gp_Mat2d.def("ChangeValue", (Standard_Real & (gp_Mat2d::*)(const Standard_Integer, const Standard_Integer)) &gp_Mat2d::ChangeValue, "Returns the coefficient of range (Row, Col) Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 2", py::arg("Row"), py::arg("Col"));
cls_gp_Mat2d.def("__call__", (Standard_Real & (gp_Mat2d::*)(const Standard_Integer, const Standard_Integer)) &gp_Mat2d::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
cls_gp_Mat2d.def("IsSingular", (Standard_Boolean (gp_Mat2d::*)() const) &gp_Mat2d::IsSingular, "Returns true if this matrix is singular (and therefore, cannot be inverted). The Gauss LU decomposition is used to invert the matrix so the matrix is considered as singular if the largest pivot found is lower or equal to Resolution from gp.");
cls_gp_Mat2d.def("Add", (void (gp_Mat2d::*)(const gp_Mat2d &)) &gp_Mat2d::Add, "None", py::arg("Other"));
cls_gp_Mat2d.def("__iadd__", (void (gp_Mat2d::*)(const gp_Mat2d &)) &gp_Mat2d::operator+=, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat2d.def("Added", (gp_Mat2d (gp_Mat2d::*)(const gp_Mat2d &) const) &gp_Mat2d::Added, "Computes the sum of this matrix and the matrix Other.for each coefficient of the matrix : <me>.Coef(i,j) + <Other>.Coef(i,j) Note: - operator += assigns the result to this matrix, while - operator + creates a new one.", py::arg("Other"));
cls_gp_Mat2d.def("__add__", (gp_Mat2d (gp_Mat2d::*)(const gp_Mat2d &) const) &gp_Mat2d::operator+, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat2d.def("Divide", (void (gp_Mat2d::*)(const Standard_Real)) &gp_Mat2d::Divide, "None", py::arg("Scalar"));
cls_gp_Mat2d.def("__itruediv__", (void (gp_Mat2d::*)(const Standard_Real)) &gp_Mat2d::operator/=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Mat2d.def("Divided", (gp_Mat2d (gp_Mat2d::*)(const Standard_Real) const) &gp_Mat2d::Divided, "Divides all the coefficients of the matrix by a scalar.", py::arg("Scalar"));
cls_gp_Mat2d.def("__truediv__", (gp_Mat2d (gp_Mat2d::*)(const Standard_Real) const) &gp_Mat2d::operator/, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Mat2d.def("Invert", (void (gp_Mat2d::*)()) &gp_Mat2d::Invert, "None");
cls_gp_Mat2d.def("Inverted", (gp_Mat2d (gp_Mat2d::*)() const) &gp_Mat2d::Inverted, "Inverses the matrix and raises exception if the matrix is singular.");
cls_gp_Mat2d.def("Multiplied", (gp_Mat2d (gp_Mat2d::*)(const gp_Mat2d &) const) &gp_Mat2d::Multiplied, "None", py::arg("Other"));
cls_gp_Mat2d.def("__mul__", (gp_Mat2d (gp_Mat2d::*)(const gp_Mat2d &) const) &gp_Mat2d::operator*, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat2d.def("Multiply", (void (gp_Mat2d::*)(const gp_Mat2d &)) &gp_Mat2d::Multiply, "Computes the product of two matrices <me> * <Other>", py::arg("Other"));
cls_gp_Mat2d.def("PreMultiply", (void (gp_Mat2d::*)(const gp_Mat2d &)) &gp_Mat2d::PreMultiply, "Modifies this matrix by premultiplying it by the matrix Other <me> = Other * <me>.", py::arg("Other"));
cls_gp_Mat2d.def("Multiplied", (gp_Mat2d (gp_Mat2d::*)(const Standard_Real) const) &gp_Mat2d::Multiplied, "None", py::arg("Scalar"));
cls_gp_Mat2d.def("__mul__", (gp_Mat2d (gp_Mat2d::*)(const Standard_Real) const) &gp_Mat2d::operator*, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Mat2d.def("Multiply", (void (gp_Mat2d::*)(const Standard_Real)) &gp_Mat2d::Multiply, "Multiplies all the coefficients of the matrix by a scalar.", py::arg("Scalar"));
cls_gp_Mat2d.def("__imul__", (void (gp_Mat2d::*)(const Standard_Real)) &gp_Mat2d::operator*=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Mat2d.def("Power", (void (gp_Mat2d::*)(const Standard_Integer)) &gp_Mat2d::Power, "None", py::arg("N"));
cls_gp_Mat2d.def("Powered", (gp_Mat2d (gp_Mat2d::*)(const Standard_Integer) const) &gp_Mat2d::Powered, "computes <me> = <me> * <me> * .......* <me>, N time. if N = 0 <me> = Identity if N < 0 <me> = <me>.Invert() *...........* <me>.Invert(). If N < 0 an exception can be raised if the matrix is not inversible", py::arg("N"));
cls_gp_Mat2d.def("Subtract", (void (gp_Mat2d::*)(const gp_Mat2d &)) &gp_Mat2d::Subtract, "None", py::arg("Other"));
cls_gp_Mat2d.def("__isub__", (void (gp_Mat2d::*)(const gp_Mat2d &)) &gp_Mat2d::operator-=, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat2d.def("Subtracted", (gp_Mat2d (gp_Mat2d::*)(const gp_Mat2d &) const) &gp_Mat2d::Subtracted, "Computes for each coefficient of the matrix : <me>.Coef(i,j) - <Other>.Coef(i,j)", py::arg("Other"));
cls_gp_Mat2d.def("__sub__", (gp_Mat2d (gp_Mat2d::*)(const gp_Mat2d &) const) &gp_Mat2d::operator-, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat2d.def("Transpose", (void (gp_Mat2d::*)()) &gp_Mat2d::Transpose, "None");
cls_gp_Mat2d.def("Transposed", (gp_Mat2d (gp_Mat2d::*)() const) &gp_Mat2d::Transposed, "Transposes the matrix. A(j, i) -> A (i, j)");

// CLASS: GP_PNT2D
py::class_<gp_Pnt2d> cls_gp_Pnt2d(mod, "gp_Pnt2d", "Defines a non-persistent 2D cartesian point.");

// Constructors
cls_gp_Pnt2d.def(py::init<>());
cls_gp_Pnt2d.def(py::init<const gp_XY &>(), py::arg("Coord"));
cls_gp_Pnt2d.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Xp"), py::arg("Yp"));

// Methods
// cls_gp_Pnt2d.def_static("operator new_", (void * (*)(size_t)) &gp_Pnt2d::operator new, "None", py::arg("theSize"));
// cls_gp_Pnt2d.def_static("operator delete_", (void (*)(void *)) &gp_Pnt2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Pnt2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Pnt2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Pnt2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Pnt2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Pnt2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Pnt2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Pnt2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Pnt2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Pnt2d.def("SetCoord", (void (gp_Pnt2d::*)(const Standard_Integer, const Standard_Real)) &gp_Pnt2d::SetCoord, "Assigns the value Xi to the coordinate that corresponds to Index: Index = 1 => X is modified Index = 2 => Y is modified Raises OutOfRange if Index != {1, 2}.", py::arg("Index"), py::arg("Xi"));
cls_gp_Pnt2d.def("SetCoord", (void (gp_Pnt2d::*)(const Standard_Real, const Standard_Real)) &gp_Pnt2d::SetCoord, "For this point, assigns the values Xp and Yp to its two coordinates", py::arg("Xp"), py::arg("Yp"));
cls_gp_Pnt2d.def("SetX", (void (gp_Pnt2d::*)(const Standard_Real)) &gp_Pnt2d::SetX, "Assigns the given value to the X coordinate of this point.", py::arg("X"));
cls_gp_Pnt2d.def("SetY", (void (gp_Pnt2d::*)(const Standard_Real)) &gp_Pnt2d::SetY, "Assigns the given value to the Y coordinate of this point.", py::arg("Y"));
cls_gp_Pnt2d.def("SetXY", (void (gp_Pnt2d::*)(const gp_XY &)) &gp_Pnt2d::SetXY, "Assigns the two coordinates of Coord to this point.", py::arg("Coord"));
cls_gp_Pnt2d.def("Coord", (Standard_Real (gp_Pnt2d::*)(const Standard_Integer) const) &gp_Pnt2d::Coord, "Returns the coordinate of range Index : Index = 1 => X is returned Index = 2 => Y is returned Raises OutOfRange if Index != {1, 2}.", py::arg("Index"));
cls_gp_Pnt2d.def("Coord", [](gp_Pnt2d &self, Standard_Real & Xp, Standard_Real & Yp){ self.Coord(Xp, Yp); return std::tuple<Standard_Real &, Standard_Real &>(Xp, Yp); }, "For this point returns its two coordinates as a number pair.", py::arg("Xp"), py::arg("Yp"));
cls_gp_Pnt2d.def("X", (Standard_Real (gp_Pnt2d::*)() const) &gp_Pnt2d::X, "For this point, returns its X coordinate.");
cls_gp_Pnt2d.def("Y", (Standard_Real (gp_Pnt2d::*)() const) &gp_Pnt2d::Y, "For this point, returns its Y coordinate.");
cls_gp_Pnt2d.def("XY", (const gp_XY & (gp_Pnt2d::*)() const) &gp_Pnt2d::XY, "For this point, returns its two coordinates as a number pair.");
cls_gp_Pnt2d.def("Coord", (const gp_XY & (gp_Pnt2d::*)() const) &gp_Pnt2d::Coord, "For this point, returns its two coordinates as a number pair.");
cls_gp_Pnt2d.def("ChangeCoord", (gp_XY & (gp_Pnt2d::*)()) &gp_Pnt2d::ChangeCoord, "Returns the coordinates of this point. Note: This syntax allows direct modification of the returned value.");
cls_gp_Pnt2d.def("IsEqual", (Standard_Boolean (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Pnt2d::IsEqual, "Comparison Returns True if the distance between the two points is lower or equal to LinearTolerance.", py::arg("Other"), py::arg("LinearTolerance"));
cls_gp_Pnt2d.def("Distance", (Standard_Real (gp_Pnt2d::*)(const gp_Pnt2d &) const) &gp_Pnt2d::Distance, "Computes the distance between two points.", py::arg("Other"));
cls_gp_Pnt2d.def("SquareDistance", (Standard_Real (gp_Pnt2d::*)(const gp_Pnt2d &) const) &gp_Pnt2d::SquareDistance, "Computes the square distance between two points.", py::arg("Other"));
cls_gp_Pnt2d.def("Mirror", (void (gp_Pnt2d::*)(const gp_Pnt2d &)) &gp_Pnt2d::Mirror, "Performs the symmetrical transformation of a point with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Pnt2d.def("Mirrored", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Pnt2d &) const) &gp_Pnt2d::Mirrored, "Performs the symmetrical transformation of a point with respect to an axis placement which is the axis", py::arg("P"));
cls_gp_Pnt2d.def("Mirror", (void (gp_Pnt2d::*)(const gp_Ax2d &)) &gp_Pnt2d::Mirror, "None", py::arg("A"));
cls_gp_Pnt2d.def("Mirrored", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Ax2d &) const) &gp_Pnt2d::Mirrored, "Rotates a point. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A"));
cls_gp_Pnt2d.def("Rotate", (void (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Pnt2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Pnt2d.def("Rotated", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Pnt2d::Rotated, "Scales a point. S is the scaling value.", py::arg("P"), py::arg("Ang"));
cls_gp_Pnt2d.def("Scale", (void (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Pnt2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Pnt2d.def("Scaled", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Pnt2d::Scaled, "Transforms a point with the transformation T.", py::arg("P"), py::arg("S"));
cls_gp_Pnt2d.def("Transform", (void (gp_Pnt2d::*)(const gp_Trsf2d &)) &gp_Pnt2d::Transform, "None", py::arg("T"));
cls_gp_Pnt2d.def("Transformed", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Trsf2d &) const) &gp_Pnt2d::Transformed, "Translates a point in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("T"));
cls_gp_Pnt2d.def("Translate", (void (gp_Pnt2d::*)(const gp_Vec2d &)) &gp_Pnt2d::Translate, "None", py::arg("V"));
cls_gp_Pnt2d.def("Translated", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Vec2d &) const) &gp_Pnt2d::Translated, "Translates a point from the point P1 to the point P2.", py::arg("V"));
cls_gp_Pnt2d.def("Translate", (void (gp_Pnt2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Pnt2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Pnt2d.def("Translated", (gp_Pnt2d (gp_Pnt2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Pnt2d::Translated, "None", py::arg("P1"), py::arg("P2"));

// CLASS: GP_VEC2D
py::class_<gp_Vec2d> cls_gp_Vec2d(mod, "gp_Vec2d", "Defines a non-persistent vector in 2D space.");

// Constructors
cls_gp_Vec2d.def(py::init<>());
cls_gp_Vec2d.def(py::init<const gp_Dir2d &>(), py::arg("V"));
cls_gp_Vec2d.def(py::init<const gp_XY &>(), py::arg("Coord"));
cls_gp_Vec2d.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"));
cls_gp_Vec2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));

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

// CLASS: GP_DIR2D
py::class_<gp_Dir2d> cls_gp_Dir2d(mod, "gp_Dir2d", "Describes a unit vector in the plane (2D space). This unit vector is also called 'Direction'. See Also gce_MakeDir2d which provides functions for more complex unit vector constructions Geom2d_Direction which provides additional functions for constructing unit vectors and works, in particular, with the parametric equations of unit vectors");

// Constructors
cls_gp_Dir2d.def(py::init<>());
cls_gp_Dir2d.def(py::init<const gp_Vec2d &>(), py::arg("V"));
cls_gp_Dir2d.def(py::init<const gp_XY &>(), py::arg("Coord"));
cls_gp_Dir2d.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"));

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

// CLASS: GP_AX2D
py::class_<gp_Ax2d> cls_gp_Ax2d(mod, "gp_Ax2d", "Describes an axis in the plane (2D space). An axis is defined by: - its origin (also referred to as its 'Location point'), and - its unit vector (referred to as its 'Direction'). An axis implicitly defines a direct, right-handed coordinate system in 2D space by: - its origin, - its 'Direction' (giving the 'X Direction' of the coordinate system), and - the unit vector normal to 'Direction' (positive angle measured in the trigonometric sense). An axis is used: - to describe 2D geometric entities (for example, the axis which defines angular coordinates on a circle). It serves for the same purpose as the STEP function 'axis placement one axis', or - to define geometric transformations (axis of symmetry, axis of rotation, and so on). Note: to define a left-handed 2D coordinate system, use gp_Ax22d.");

// Constructors
cls_gp_Ax2d.def(py::init<>());
cls_gp_Ax2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));

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

// CLASS: GP_TRSF2D
py::class_<gp_Trsf2d> cls_gp_Trsf2d(mod, "gp_Trsf2d", "Defines a non-persistent transformation in 2D space. The following transformations are implemented : . Translation, Rotation, Scale . Symmetry with respect to a point and a line. Complex transformations can be obtained by combining the previous elementary transformations using the method Multiply. The transformations can be represented as follow :");

// Constructors
cls_gp_Trsf2d.def(py::init<>());
cls_gp_Trsf2d.def(py::init<const gp_Trsf &>(), py::arg("T"));

// Methods
// cls_gp_Trsf2d.def_static("operator new_", (void * (*)(size_t)) &gp_Trsf2d::operator new, "None", py::arg("theSize"));
// cls_gp_Trsf2d.def_static("operator delete_", (void (*)(void *)) &gp_Trsf2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Trsf2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Trsf2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Trsf2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Trsf2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Trsf2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Trsf2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Trsf2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Trsf2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Trsf2d.def("SetMirror", (void (gp_Trsf2d::*)(const gp_Pnt2d &)) &gp_Trsf2d::SetMirror, "Changes the transformation into a symmetrical transformation. P is the center of the symmetry.", py::arg("P"));
cls_gp_Trsf2d.def("SetMirror", (void (gp_Trsf2d::*)(const gp_Ax2d &)) &gp_Trsf2d::SetMirror, "Changes the transformation into a symmetrical transformation. A is the center of the axial symmetry.", py::arg("A"));
cls_gp_Trsf2d.def("SetRotation", (void (gp_Trsf2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Trsf2d::SetRotation, "Changes the transformation into a rotation. P is the rotation's center and Ang is the angular value of the rotation in radian.", py::arg("P"), py::arg("Ang"));
cls_gp_Trsf2d.def("SetScale", (void (gp_Trsf2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Trsf2d::SetScale, "Changes the transformation into a scale. P is the center of the scale and S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Trsf2d.def("SetTransformation", (void (gp_Trsf2d::*)(const gp_Ax2d &, const gp_Ax2d &)) &gp_Trsf2d::SetTransformation, "Changes a transformation allowing passage from the coordinate system 'FromSystem1' to the coordinate system 'ToSystem2'.", py::arg("FromSystem1"), py::arg("ToSystem2"));
cls_gp_Trsf2d.def("SetTransformation", (void (gp_Trsf2d::*)(const gp_Ax2d &)) &gp_Trsf2d::SetTransformation, "Changes the transformation allowing passage from the basic coordinate system {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.)} to the local coordinate system defined with the Ax2d ToSystem.", py::arg("ToSystem"));
cls_gp_Trsf2d.def("SetTranslation", (void (gp_Trsf2d::*)(const gp_Vec2d &)) &gp_Trsf2d::SetTranslation, "Changes the transformation into a translation. V is the vector of the translation.", py::arg("V"));
cls_gp_Trsf2d.def("SetTranslation", (void (gp_Trsf2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Trsf2d::SetTranslation, "Makes the transformation into a translation from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));
cls_gp_Trsf2d.def("SetTranslationPart", (void (gp_Trsf2d::*)(const gp_Vec2d &)) &gp_Trsf2d::SetTranslationPart, "Replaces the translation vector with V.", py::arg("V"));
cls_gp_Trsf2d.def("SetScaleFactor", (void (gp_Trsf2d::*)(const Standard_Real)) &gp_Trsf2d::SetScaleFactor, "Modifies the scale factor.", py::arg("S"));
cls_gp_Trsf2d.def("IsNegative", (Standard_Boolean (gp_Trsf2d::*)() const) &gp_Trsf2d::IsNegative, "Returns true if the determinant of the vectorial part of this transformation is negative..");
cls_gp_Trsf2d.def("Form", (gp_TrsfForm (gp_Trsf2d::*)() const) &gp_Trsf2d::Form, "Returns the nature of the transformation. It can be an identity transformation, a rotation, a translation, a mirror (relative to a point or an axis), a scaling transformation, or a compound transformation.");
cls_gp_Trsf2d.def("ScaleFactor", (Standard_Real (gp_Trsf2d::*)() const) &gp_Trsf2d::ScaleFactor, "Returns the scale factor.");
cls_gp_Trsf2d.def("TranslationPart", (const gp_XY & (gp_Trsf2d::*)() const) &gp_Trsf2d::TranslationPart, "Returns the translation part of the transformation's matrix");
cls_gp_Trsf2d.def("VectorialPart", (gp_Mat2d (gp_Trsf2d::*)() const) &gp_Trsf2d::VectorialPart, "Returns the vectorial part of the transformation. It is a 2*2 matrix which includes the scale factor.");
cls_gp_Trsf2d.def("HVectorialPart", (const gp_Mat2d & (gp_Trsf2d::*)() const) &gp_Trsf2d::HVectorialPart, "Returns the homogeneous vectorial part of the transformation. It is a 2*2 matrix which doesn't include the scale factor. The coefficients of this matrix must be multiplied by the scale factor to obtain the coefficients of the transformation.");
cls_gp_Trsf2d.def("RotationPart", (Standard_Real (gp_Trsf2d::*)() const) &gp_Trsf2d::RotationPart, "Returns the angle corresponding to the rotational component of the transformation matrix (operation opposite to SetRotation()).");
cls_gp_Trsf2d.def("Value", (Standard_Real (gp_Trsf2d::*)(const Standard_Integer, const Standard_Integer) const) &gp_Trsf2d::Value, "Returns the coefficients of the transformation's matrix. It is a 2 rows * 3 columns matrix. Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3", py::arg("Row"), py::arg("Col"));
cls_gp_Trsf2d.def("Invert", (void (gp_Trsf2d::*)()) &gp_Trsf2d::Invert, "None");
cls_gp_Trsf2d.def("Inverted", (gp_Trsf2d (gp_Trsf2d::*)() const) &gp_Trsf2d::Inverted, "Computes the reverse transformation. Raises an exception if the matrix of the transformation is not inversible, it means that the scale factor is lower or equal to Resolution from package gp.");
cls_gp_Trsf2d.def("Multiplied", (gp_Trsf2d (gp_Trsf2d::*)(const gp_Trsf2d &) const) &gp_Trsf2d::Multiplied, "None", py::arg("T"));
cls_gp_Trsf2d.def("__mul__", (gp_Trsf2d (gp_Trsf2d::*)(const gp_Trsf2d &) const) &gp_Trsf2d::operator*, py::is_operator(), "None", py::arg("T"));
cls_gp_Trsf2d.def("Multiply", (void (gp_Trsf2d::*)(const gp_Trsf2d &)) &gp_Trsf2d::Multiply, "Computes the transformation composed from <me> and T. <me> = <me> * T", py::arg("T"));
cls_gp_Trsf2d.def("__imul__", (void (gp_Trsf2d::*)(const gp_Trsf2d &)) &gp_Trsf2d::operator*=, py::is_operator(), "None", py::arg("T"));
cls_gp_Trsf2d.def("PreMultiply", (void (gp_Trsf2d::*)(const gp_Trsf2d &)) &gp_Trsf2d::PreMultiply, "Computes the transformation composed from <me> and T. <me> = T * <me>", py::arg("T"));
cls_gp_Trsf2d.def("Power", (void (gp_Trsf2d::*)(const Standard_Integer)) &gp_Trsf2d::Power, "None", py::arg("N"));
cls_gp_Trsf2d.def("Powered", (gp_Trsf2d (gp_Trsf2d::*)(const Standard_Integer)) &gp_Trsf2d::Powered, "Computes the following composition of transformations <me> * <me> * .......* <me>, N time. if N = 0 <me> = Identity if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().", py::arg("N"));
cls_gp_Trsf2d.def("Transforms", [](gp_Trsf2d &self, Standard_Real & X, Standard_Real & Y){ self.Transforms(X, Y); return std::tuple<Standard_Real &, Standard_Real &>(X, Y); }, "None", py::arg("X"), py::arg("Y"));
cls_gp_Trsf2d.def("Transforms", (void (gp_Trsf2d::*)(gp_XY &) const) &gp_Trsf2d::Transforms, "Transforms a doublet XY with a Trsf2d", py::arg("Coord"));
cls_gp_Trsf2d.def("SetValues", (void (gp_Trsf2d::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Trsf2d::SetValues, "Sets the coefficients of the transformation. The transformation of the point x,y is the point x',y' with :", py::arg("a11"), py::arg("a12"), py::arg("a13"), py::arg("a21"), py::arg("a22"), py::arg("a23"));

// CLASS: GP_MAT
py::class_<gp_Mat> cls_gp_Mat(mod, "gp_Mat", "Describes a three column, three row matrix. This sort of object is used in various vectorial or matrix computations.");

// Constructors
cls_gp_Mat.def(py::init<>());
cls_gp_Mat.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("a11"), py::arg("a12"), py::arg("a13"), py::arg("a21"), py::arg("a22"), py::arg("a23"), py::arg("a31"), py::arg("a32"), py::arg("a33"));
cls_gp_Mat.def(py::init<const gp_XYZ &, const gp_XYZ &, const gp_XYZ &>(), py::arg("Col1"), py::arg("Col2"), py::arg("Col3"));

// Methods
// cls_gp_Mat.def_static("operator new_", (void * (*)(size_t)) &gp_Mat::operator new, "None", py::arg("theSize"));
// cls_gp_Mat.def_static("operator delete_", (void (*)(void *)) &gp_Mat::operator delete, "None", py::arg("theAddress"));
// cls_gp_Mat.def_static("operator new[]_", (void * (*)(size_t)) &gp_Mat::operator new[], "None", py::arg("theSize"));
// cls_gp_Mat.def_static("operator delete[]_", (void (*)(void *)) &gp_Mat::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Mat.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Mat::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Mat.def_static("operator delete_", (void (*)(void *, void *)) &gp_Mat::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Mat.def("SetCol", (void (gp_Mat::*)(const Standard_Integer, const gp_XYZ &)) &gp_Mat::SetCol, "Assigns the three coordinates of Value to the column of index Col of this matrix. Raises OutOfRange if Col < 1 or Col > 3.", py::arg("Col"), py::arg("Value"));
cls_gp_Mat.def("SetCols", (void (gp_Mat::*)(const gp_XYZ &, const gp_XYZ &, const gp_XYZ &)) &gp_Mat::SetCols, "Assigns the number triples Col1, Col2, Col3 to the three columns of this matrix.", py::arg("Col1"), py::arg("Col2"), py::arg("Col3"));
cls_gp_Mat.def("SetCross", (void (gp_Mat::*)(const gp_XYZ &)) &gp_Mat::SetCross, "Modifies the matrix M so that applying it to any number triple (X, Y, Z) produces the same result as the cross product of Ref and the number triple (X, Y, Z): i.e.: M * {X,Y,Z}t = Ref.Cross({X, Y ,Z}) this matrix is anti symmetric. To apply this matrix to the triplet {XYZ} is the same as to do the cross product between the triplet Ref and the triplet {XYZ}. Note: this matrix is anti-symmetric.", py::arg("Ref"));
cls_gp_Mat.def("SetDiagonal", (void (gp_Mat::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Mat::SetDiagonal, "Modifies the main diagonal of the matrix. <me>.Value (1, 1) = X1 <me>.Value (2, 2) = X2 <me>.Value (3, 3) = X3 The other coefficients of the matrix are not modified.", py::arg("X1"), py::arg("X2"), py::arg("X3"));
cls_gp_Mat.def("SetDot", (void (gp_Mat::*)(const gp_XYZ &)) &gp_Mat::SetDot, "Modifies this matrix so that applying it to any number triple (X, Y, Z) produces the same result as the scalar product of Ref and the number triple (X, Y, Z): this * (X,Y,Z) = Ref.(X,Y,Z) Note: this matrix is symmetric.", py::arg("Ref"));
cls_gp_Mat.def("SetIdentity", (void (gp_Mat::*)()) &gp_Mat::SetIdentity, "Modifies this matrix so that it represents the Identity matrix.");
cls_gp_Mat.def("SetRotation", (void (gp_Mat::*)(const gp_XYZ &, const Standard_Real)) &gp_Mat::SetRotation, "Modifies this matrix so that it represents a rotation. Ang is the angular value in radians and the XYZ axis gives the direction of the rotation. Raises ConstructionError if XYZ.Modulus() <= Resolution()", py::arg("Axis"), py::arg("Ang"));
cls_gp_Mat.def("SetRow", (void (gp_Mat::*)(const Standard_Integer, const gp_XYZ &)) &gp_Mat::SetRow, "Assigns the three coordinates of Value to the row of index Row of this matrix. Raises OutOfRange if Row < 1 or Row > 3.", py::arg("Row"), py::arg("Value"));
cls_gp_Mat.def("SetRows", (void (gp_Mat::*)(const gp_XYZ &, const gp_XYZ &, const gp_XYZ &)) &gp_Mat::SetRows, "Assigns the number triples Row1, Row2, Row3 to the three rows of this matrix.", py::arg("Row1"), py::arg("Row2"), py::arg("Row3"));
cls_gp_Mat.def("SetScale", (void (gp_Mat::*)(const Standard_Real)) &gp_Mat::SetScale, "Modifies the the matrix so that it represents a scaling transformation, where S is the scale factor. : | S 0.0 0.0 | <me> = | 0.0 S 0.0 | | 0.0 0.0 S |", py::arg("S"));
cls_gp_Mat.def("SetValue", (void (gp_Mat::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &gp_Mat::SetValue, "Assigns <Value> to the coefficient of row Row, column Col of this matrix. Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 3", py::arg("Row"), py::arg("Col"), py::arg("Value"));
cls_gp_Mat.def("Column", (gp_XYZ (gp_Mat::*)(const Standard_Integer) const) &gp_Mat::Column, "Returns the column of Col index. Raises OutOfRange if Col < 1 or Col > 3", py::arg("Col"));
cls_gp_Mat.def("Determinant", (Standard_Real (gp_Mat::*)() const) &gp_Mat::Determinant, "Computes the determinant of the matrix.");
cls_gp_Mat.def("Diagonal", (gp_XYZ (gp_Mat::*)() const) &gp_Mat::Diagonal, "Returns the main diagonal of the matrix.");
cls_gp_Mat.def("Row", (gp_XYZ (gp_Mat::*)(const Standard_Integer) const) &gp_Mat::Row, "returns the row of Row index. Raises OutOfRange if Row < 1 or Row > 3", py::arg("Row"));
cls_gp_Mat.def("Value", (const Standard_Real & (gp_Mat::*)(const Standard_Integer, const Standard_Integer) const) &gp_Mat::Value, "Returns the coefficient of range (Row, Col) Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 3", py::arg("Row"), py::arg("Col"));
cls_gp_Mat.def("__call__", (const Standard_Real & (gp_Mat::*)(const Standard_Integer, const Standard_Integer) const) &gp_Mat::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
cls_gp_Mat.def("ChangeValue", (Standard_Real & (gp_Mat::*)(const Standard_Integer, const Standard_Integer)) &gp_Mat::ChangeValue, "Returns the coefficient of range (Row, Col) Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 3", py::arg("Row"), py::arg("Col"));
cls_gp_Mat.def("__call__", (Standard_Real & (gp_Mat::*)(const Standard_Integer, const Standard_Integer)) &gp_Mat::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
cls_gp_Mat.def("IsSingular", (Standard_Boolean (gp_Mat::*)() const) &gp_Mat::IsSingular, "The Gauss LU decomposition is used to invert the matrix (see Math package) so the matrix is considered as singular if the largest pivot found is lower or equal to Resolution from gp.");
cls_gp_Mat.def("Add", (void (gp_Mat::*)(const gp_Mat &)) &gp_Mat::Add, "None", py::arg("Other"));
cls_gp_Mat.def("__iadd__", (void (gp_Mat::*)(const gp_Mat &)) &gp_Mat::operator+=, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat.def("Added", (gp_Mat (gp_Mat::*)(const gp_Mat &) const) &gp_Mat::Added, "Computes the sum of this matrix and the matrix Other for each coefficient of the matrix : <me>.Coef(i,j) + <Other>.Coef(i,j)", py::arg("Other"));
cls_gp_Mat.def("__add__", (gp_Mat (gp_Mat::*)(const gp_Mat &) const) &gp_Mat::operator+, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat.def("Divide", (void (gp_Mat::*)(const Standard_Real)) &gp_Mat::Divide, "None", py::arg("Scalar"));
cls_gp_Mat.def("__itruediv__", (void (gp_Mat::*)(const Standard_Real)) &gp_Mat::operator/=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Mat.def("Divided", (gp_Mat (gp_Mat::*)(const Standard_Real) const) &gp_Mat::Divided, "Divides all the coefficients of the matrix by Scalar", py::arg("Scalar"));
cls_gp_Mat.def("__truediv__", (gp_Mat (gp_Mat::*)(const Standard_Real) const) &gp_Mat::operator/, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Mat.def("Invert", (void (gp_Mat::*)()) &gp_Mat::Invert, "None");
cls_gp_Mat.def("Inverted", (gp_Mat (gp_Mat::*)() const) &gp_Mat::Inverted, "Inverses the matrix and raises if the matrix is singular. - Invert assigns the result to this matrix, while - Inverted creates a new one. Warning The Gauss LU decomposition is used to invert the matrix. Consequently, the matrix is considered as singular if the largest pivot found is less than or equal to gp::Resolution(). Exceptions Standard_ConstructionError if this matrix is singular, and therefore cannot be inverted.");
cls_gp_Mat.def("Multiplied", (gp_Mat (gp_Mat::*)(const gp_Mat &) const) &gp_Mat::Multiplied, "Computes the product of two matrices <me> * <Other>", py::arg("Other"));
cls_gp_Mat.def("__mul__", (gp_Mat (gp_Mat::*)(const gp_Mat &) const) &gp_Mat::operator*, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat.def("Multiply", (void (gp_Mat::*)(const gp_Mat &)) &gp_Mat::Multiply, "Computes the product of two matrices <me> = <Other> * <me>.", py::arg("Other"));
cls_gp_Mat.def("__imul__", (void (gp_Mat::*)(const gp_Mat &)) &gp_Mat::operator*=, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat.def("PreMultiply", (void (gp_Mat::*)(const gp_Mat &)) &gp_Mat::PreMultiply, "None", py::arg("Other"));
cls_gp_Mat.def("Multiplied", (gp_Mat (gp_Mat::*)(const Standard_Real) const) &gp_Mat::Multiplied, "None", py::arg("Scalar"));
cls_gp_Mat.def("__mul__", (gp_Mat (gp_Mat::*)(const Standard_Real) const) &gp_Mat::operator*, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Mat.def("Multiply", (void (gp_Mat::*)(const Standard_Real)) &gp_Mat::Multiply, "Multiplies all the coefficients of the matrix by Scalar", py::arg("Scalar"));
cls_gp_Mat.def("__imul__", (void (gp_Mat::*)(const Standard_Real)) &gp_Mat::operator*=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_Mat.def("Power", (void (gp_Mat::*)(const Standard_Integer)) &gp_Mat::Power, "None", py::arg("N"));
cls_gp_Mat.def("Powered", (gp_Mat (gp_Mat::*)(const Standard_Integer) const) &gp_Mat::Powered, "Computes <me> = <me> * <me> * .......* <me>, N time. if N = 0 <me> = Identity if N < 0 <me> = <me>.Invert() *...........* <me>.Invert(). If N < 0 an exception will be raised if the matrix is not inversible", py::arg("N"));
cls_gp_Mat.def("Subtract", (void (gp_Mat::*)(const gp_Mat &)) &gp_Mat::Subtract, "None", py::arg("Other"));
cls_gp_Mat.def("__isub__", (void (gp_Mat::*)(const gp_Mat &)) &gp_Mat::operator-=, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat.def("Subtracted", (gp_Mat (gp_Mat::*)(const gp_Mat &) const) &gp_Mat::Subtracted, "cOmputes for each coefficient of the matrix : <me>.Coef(i,j) - <Other>.Coef(i,j)", py::arg("Other"));
cls_gp_Mat.def("__sub__", (gp_Mat (gp_Mat::*)(const gp_Mat &) const) &gp_Mat::operator-, py::is_operator(), "None", py::arg("Other"));
cls_gp_Mat.def("Transpose", (void (gp_Mat::*)()) &gp_Mat::Transpose, "None");
cls_gp_Mat.def("Transposed", (gp_Mat (gp_Mat::*)() const) &gp_Mat::Transposed, "Transposes the matrix. A(j, i) -> A (i, j)");

// CLASS: GP_XYZ
py::class_<gp_XYZ> cls_gp_XYZ(mod, "gp_XYZ", "This class describes a cartesian coordinate entity in 3D space {X,Y,Z}. This entity is used for algebraic calculation. This entity can be transformed with a 'Trsf' or a 'GTrsf' from package 'gp'. It is used in vectorial computations or for holding this type of information in data structures.");

// Constructors
cls_gp_XYZ.def(py::init<>());
cls_gp_XYZ.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"), py::arg("Z"));

// Methods
// cls_gp_XYZ.def_static("operator new_", (void * (*)(size_t)) &gp_XYZ::operator new, "None", py::arg("theSize"));
// cls_gp_XYZ.def_static("operator delete_", (void (*)(void *)) &gp_XYZ::operator delete, "None", py::arg("theAddress"));
// cls_gp_XYZ.def_static("operator new[]_", (void * (*)(size_t)) &gp_XYZ::operator new[], "None", py::arg("theSize"));
// cls_gp_XYZ.def_static("operator delete[]_", (void (*)(void *)) &gp_XYZ::operator delete[], "None", py::arg("theAddress"));
// cls_gp_XYZ.def_static("operator new_", (void * (*)(size_t, void *)) &gp_XYZ::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_XYZ.def_static("operator delete_", (void (*)(void *, void *)) &gp_XYZ::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_XYZ.def("SetCoord", (void (gp_XYZ::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &gp_XYZ::SetCoord, "For this XYZ object, assigns the values X, Y and Z to its three coordinates", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_gp_XYZ.def("SetCoord", (void (gp_XYZ::*)(const Standard_Integer, const Standard_Real)) &gp_XYZ::SetCoord, "modifies the coordinate of range Index Index = 1 => X is modified Index = 2 => Y is modified Index = 3 => Z is modified Raises OutOfRange if Index != {1, 2, 3}.", py::arg("Index"), py::arg("Xi"));
cls_gp_XYZ.def("SetX", (void (gp_XYZ::*)(const Standard_Real)) &gp_XYZ::SetX, "Assigns the given value to the X coordinate", py::arg("X"));
cls_gp_XYZ.def("SetY", (void (gp_XYZ::*)(const Standard_Real)) &gp_XYZ::SetY, "Assigns the given value to the Y coordinate", py::arg("Y"));
cls_gp_XYZ.def("SetZ", (void (gp_XYZ::*)(const Standard_Real)) &gp_XYZ::SetZ, "Assigns the given value to the Z coordinate", py::arg("Z"));
cls_gp_XYZ.def("Coord", (Standard_Real (gp_XYZ::*)(const Standard_Integer) const) &gp_XYZ::Coord, "returns the coordinate of range Index : Index = 1 => X is returned Index = 2 => Y is returned Index = 3 => Z is returned", py::arg("Index"));
cls_gp_XYZ.def("ChangeCoord", (Standard_Real & (gp_XYZ::*)(const Standard_Integer)) &gp_XYZ::ChangeCoord, "None", py::arg("theIndex"));
cls_gp_XYZ.def("Coord", [](gp_XYZ &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Coord(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "None", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_gp_XYZ.def("GetData", (const Standard_Real * (gp_XYZ::*)() const) &gp_XYZ::GetData, "Returns a const ptr to coordinates location. Is useful for algorithms, but DOES NOT PERFORM ANY CHECKS!");
cls_gp_XYZ.def("ChangeData", (Standard_Real * (gp_XYZ::*)()) &gp_XYZ::ChangeData, "Returns a ptr to coordinates location. Is useful for algorithms, but DOES NOT PERFORM ANY CHECKS!");
cls_gp_XYZ.def("X", (Standard_Real (gp_XYZ::*)() const) &gp_XYZ::X, "Returns the X coordinate");
cls_gp_XYZ.def("Y", (Standard_Real (gp_XYZ::*)() const) &gp_XYZ::Y, "Returns the Y coordinate");
cls_gp_XYZ.def("Z", (Standard_Real (gp_XYZ::*)() const) &gp_XYZ::Z, "Returns the Z coordinate");
cls_gp_XYZ.def("Modulus", (Standard_Real (gp_XYZ::*)() const) &gp_XYZ::Modulus, "computes Sqrt (X*X + Y*Y + Z*Z) where X, Y and Z are the three coordinates of this XYZ object.");
cls_gp_XYZ.def("SquareModulus", (Standard_Real (gp_XYZ::*)() const) &gp_XYZ::SquareModulus, "Computes X*X + Y*Y + Z*Z where X, Y and Z are the three coordinates of this XYZ object.");
cls_gp_XYZ.def("IsEqual", (Standard_Boolean (gp_XYZ::*)(const gp_XYZ &, const Standard_Real) const) &gp_XYZ::IsEqual, "Returns True if he coordinates of this XYZ object are equal to the respective coordinates Other, within the specified tolerance Tolerance. I.e.: abs(<me>.X() - Other.X()) <= Tolerance and abs(<me>.Y() - Other.Y()) <= Tolerance and abs(<me>.Z() - Other.Z()) <= Tolerance.", py::arg("Other"), py::arg("Tolerance"));
cls_gp_XYZ.def("Add", (void (gp_XYZ::*)(const gp_XYZ &)) &gp_XYZ::Add, "<me>.X() = <me>.X() + Other.X() <me>.Y() = <me>.Y() + Other.Y() <me>.Z() = <me>.Z() + Other.Z()", py::arg("Other"));
cls_gp_XYZ.def("__iadd__", (void (gp_XYZ::*)(const gp_XYZ &)) &gp_XYZ::operator+=, py::is_operator(), "None", py::arg("Other"));
cls_gp_XYZ.def("Added", (gp_XYZ (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::Added, "new.X() = <me>.X() + Other.X() new.Y() = <me>.Y() + Other.Y() new.Z() = <me>.Z() + Other.Z()", py::arg("Other"));
cls_gp_XYZ.def("__add__", (gp_XYZ (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::operator+, py::is_operator(), "None", py::arg("Other"));
cls_gp_XYZ.def("Cross", (void (gp_XYZ::*)(const gp_XYZ &)) &gp_XYZ::Cross, "<me>.X() = <me>.Y() * Other.Z() - <me>.Z() * Other.Y() <me>.Y() = <me>.Z() * Other.X() - <me>.X() * Other.Z() <me>.Z() = <me>.X() * Other.Y() - <me>.Y() * Other.X()", py::arg("Right"));
cls_gp_XYZ.def("operator^=", (void (gp_XYZ::*)(const gp_XYZ &)) &gp_XYZ::operator^=, "None", py::arg("Right"));
cls_gp_XYZ.def("Crossed", (gp_XYZ (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::Crossed, "new.X() = <me>.Y() * Other.Z() - <me>.Z() * Other.Y() new.Y() = <me>.Z() * Other.X() - <me>.X() * Other.Z() new.Z() = <me>.X() * Other.Y() - <me>.Y() * Other.X()", py::arg("Right"));
cls_gp_XYZ.def("operator^", (gp_XYZ (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::operator^, "None", py::arg("Right"));
cls_gp_XYZ.def("CrossMagnitude", (Standard_Real (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::CrossMagnitude, "Computes the magnitude of the cross product between <me> and Right. Returns || <me> ^ Right ||", py::arg("Right"));
cls_gp_XYZ.def("CrossSquareMagnitude", (Standard_Real (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::CrossSquareMagnitude, "Computes the square magnitude of the cross product between <me> and Right. Returns || <me> ^ Right ||**2", py::arg("Right"));
cls_gp_XYZ.def("CrossCross", (void (gp_XYZ::*)(const gp_XYZ &, const gp_XYZ &)) &gp_XYZ::CrossCross, "Triple vector product Computes <me> = <me>.Cross(Coord1.Cross(Coord2))", py::arg("Coord1"), py::arg("Coord2"));
cls_gp_XYZ.def("CrossCrossed", (gp_XYZ (gp_XYZ::*)(const gp_XYZ &, const gp_XYZ &) const) &gp_XYZ::CrossCrossed, "Triple vector product computes New = <me>.Cross(Coord1.Cross(Coord2))", py::arg("Coord1"), py::arg("Coord2"));
cls_gp_XYZ.def("Divide", (void (gp_XYZ::*)(const Standard_Real)) &gp_XYZ::Divide, "divides <me> by a real.", py::arg("Scalar"));
cls_gp_XYZ.def("__itruediv__", (void (gp_XYZ::*)(const Standard_Real)) &gp_XYZ::operator/=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_XYZ.def("Divided", (gp_XYZ (gp_XYZ::*)(const Standard_Real) const) &gp_XYZ::Divided, "divides <me> by a real.", py::arg("Scalar"));
cls_gp_XYZ.def("__truediv__", (gp_XYZ (gp_XYZ::*)(const Standard_Real) const) &gp_XYZ::operator/, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_XYZ.def("Dot", (Standard_Real (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::Dot, "computes the scalar product between <me> and Other", py::arg("Other"));
cls_gp_XYZ.def("__mul__", (Standard_Real (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::operator*, py::is_operator(), "None", py::arg("Other"));
cls_gp_XYZ.def("DotCross", (Standard_Real (gp_XYZ::*)(const gp_XYZ &, const gp_XYZ &) const) &gp_XYZ::DotCross, "computes the triple scalar product", py::arg("Coord1"), py::arg("Coord2"));
cls_gp_XYZ.def("Multiply", (void (gp_XYZ::*)(const Standard_Real)) &gp_XYZ::Multiply, "<me>.X() = <me>.X() * Scalar; <me>.Y() = <me>.Y() * Scalar; <me>.Z() = <me>.Z() * Scalar;", py::arg("Scalar"));
cls_gp_XYZ.def("__imul__", (void (gp_XYZ::*)(const Standard_Real)) &gp_XYZ::operator*=, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_XYZ.def("Multiply", (void (gp_XYZ::*)(const gp_XYZ &)) &gp_XYZ::Multiply, "<me>.X() = <me>.X() * Other.X(); <me>.Y() = <me>.Y() * Other.Y(); <me>.Z() = <me>.Z() * Other.Z();", py::arg("Other"));
cls_gp_XYZ.def("__imul__", (void (gp_XYZ::*)(const gp_XYZ &)) &gp_XYZ::operator*=, py::is_operator(), "None", py::arg("Other"));
cls_gp_XYZ.def("Multiply", (void (gp_XYZ::*)(const gp_Mat &)) &gp_XYZ::Multiply, "<me> = Matrix * <me>", py::arg("Matrix"));
cls_gp_XYZ.def("__imul__", (void (gp_XYZ::*)(const gp_Mat &)) &gp_XYZ::operator*=, py::is_operator(), "None", py::arg("Matrix"));
cls_gp_XYZ.def("Multiplied", (gp_XYZ (gp_XYZ::*)(const Standard_Real) const) &gp_XYZ::Multiplied, "New.X() = <me>.X() * Scalar; New.Y() = <me>.Y() * Scalar; New.Z() = <me>.Z() * Scalar;", py::arg("Scalar"));
cls_gp_XYZ.def("__mul__", (gp_XYZ (gp_XYZ::*)(const Standard_Real) const) &gp_XYZ::operator*, py::is_operator(), "None", py::arg("Scalar"));
cls_gp_XYZ.def("Multiplied", (gp_XYZ (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::Multiplied, "new.X() = <me>.X() * Other.X(); new.Y() = <me>.Y() * Other.Y(); new.Z() = <me>.Z() * Other.Z();", py::arg("Other"));
cls_gp_XYZ.def("Multiplied", (gp_XYZ (gp_XYZ::*)(const gp_Mat &) const) &gp_XYZ::Multiplied, "New = Matrix * <me>", py::arg("Matrix"));
cls_gp_XYZ.def("__mul__", (gp_XYZ (gp_XYZ::*)(const gp_Mat &) const) &gp_XYZ::operator*, py::is_operator(), "None", py::arg("Matrix"));
cls_gp_XYZ.def("Normalize", (void (gp_XYZ::*)()) &gp_XYZ::Normalize, "<me>.X() = <me>.X()/ <me>.Modulus() <me>.Y() = <me>.Y()/ <me>.Modulus() <me>.Z() = <me>.Z()/ <me>.Modulus() Raised if <me>.Modulus() <= Resolution from gp");
cls_gp_XYZ.def("Normalized", (gp_XYZ (gp_XYZ::*)() const) &gp_XYZ::Normalized, "New.X() = <me>.X()/ <me>.Modulus() New.Y() = <me>.Y()/ <me>.Modulus() New.Z() = <me>.Z()/ <me>.Modulus() Raised if <me>.Modulus() <= Resolution from gp");
cls_gp_XYZ.def("Reverse", (void (gp_XYZ::*)()) &gp_XYZ::Reverse, "<me>.X() = -<me>.X() <me>.Y() = -<me>.Y() <me>.Z() = -<me>.Z()");
cls_gp_XYZ.def("Reversed", (gp_XYZ (gp_XYZ::*)() const) &gp_XYZ::Reversed, "New.X() = -<me>.X() New.Y() = -<me>.Y() New.Z() = -<me>.Z()");
cls_gp_XYZ.def("Subtract", (void (gp_XYZ::*)(const gp_XYZ &)) &gp_XYZ::Subtract, "<me>.X() = <me>.X() - Other.X() <me>.Y() = <me>.Y() - Other.Y() <me>.Z() = <me>.Z() - Other.Z()", py::arg("Right"));
cls_gp_XYZ.def("__isub__", (void (gp_XYZ::*)(const gp_XYZ &)) &gp_XYZ::operator-=, py::is_operator(), "None", py::arg("Right"));
cls_gp_XYZ.def("Subtracted", (gp_XYZ (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::Subtracted, "new.X() = <me>.X() - Other.X() new.Y() = <me>.Y() - Other.Y() new.Z() = <me>.Z() - Other.Z()", py::arg("Right"));
cls_gp_XYZ.def("__sub__", (gp_XYZ (gp_XYZ::*)(const gp_XYZ &) const) &gp_XYZ::operator-, py::is_operator(), "None", py::arg("Right"));
cls_gp_XYZ.def("SetLinearForm", (void (gp_XYZ::*)(const Standard_Real, const gp_XYZ &, const Standard_Real, const gp_XYZ &, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &gp_XYZ::SetLinearForm, "<me> is set to the following linear form : A1 * XYZ1 + A2 * XYZ2 + A3 * XYZ3 + XYZ4", py::arg("A1"), py::arg("XYZ1"), py::arg("A2"), py::arg("XYZ2"), py::arg("A3"), py::arg("XYZ3"), py::arg("XYZ4"));
cls_gp_XYZ.def("SetLinearForm", (void (gp_XYZ::*)(const Standard_Real, const gp_XYZ &, const Standard_Real, const gp_XYZ &, const Standard_Real, const gp_XYZ &)) &gp_XYZ::SetLinearForm, "<me> is set to the following linear form : A1 * XYZ1 + A2 * XYZ2 + A3 * XYZ3", py::arg("A1"), py::arg("XYZ1"), py::arg("A2"), py::arg("XYZ2"), py::arg("A3"), py::arg("XYZ3"));
cls_gp_XYZ.def("SetLinearForm", (void (gp_XYZ::*)(const Standard_Real, const gp_XYZ &, const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &gp_XYZ::SetLinearForm, "<me> is set to the following linear form : A1 * XYZ1 + A2 * XYZ2 + XYZ3", py::arg("A1"), py::arg("XYZ1"), py::arg("A2"), py::arg("XYZ2"), py::arg("XYZ3"));
cls_gp_XYZ.def("SetLinearForm", (void (gp_XYZ::*)(const Standard_Real, const gp_XYZ &, const Standard_Real, const gp_XYZ &)) &gp_XYZ::SetLinearForm, "<me> is set to the following linear form : A1 * XYZ1 + A2 * XYZ2", py::arg("A1"), py::arg("XYZ1"), py::arg("A2"), py::arg("XYZ2"));
cls_gp_XYZ.def("SetLinearForm", (void (gp_XYZ::*)(const Standard_Real, const gp_XYZ &, const gp_XYZ &)) &gp_XYZ::SetLinearForm, "<me> is set to the following linear form : A1 * XYZ1 + XYZ2", py::arg("A1"), py::arg("XYZ1"), py::arg("XYZ2"));
cls_gp_XYZ.def("SetLinearForm", (void (gp_XYZ::*)(const gp_XYZ &, const gp_XYZ &)) &gp_XYZ::SetLinearForm, "<me> is set to the following linear form : XYZ1 + XYZ2", py::arg("XYZ1"), py::arg("XYZ2"));

// CLASS: GP_TRSF
py::class_<gp_Trsf> cls_gp_Trsf(mod, "gp_Trsf", "Defines a non-persistent transformation in 3D space. The following transformations are implemented : . Translation, Rotation, Scale . Symmetry with respect to a point, a line, a plane. Complex transformations can be obtained by combining the previous elementary transformations using the method Multiply. The transformations can be represented as follow :");

// Constructors
cls_gp_Trsf.def(py::init<>());
cls_gp_Trsf.def(py::init<const gp_Trsf2d &>(), py::arg("T"));

// Methods
// cls_gp_Trsf.def_static("operator new_", (void * (*)(size_t)) &gp_Trsf::operator new, "None", py::arg("theSize"));
// cls_gp_Trsf.def_static("operator delete_", (void (*)(void *)) &gp_Trsf::operator delete, "None", py::arg("theAddress"));
// cls_gp_Trsf.def_static("operator new[]_", (void * (*)(size_t)) &gp_Trsf::operator new[], "None", py::arg("theSize"));
// cls_gp_Trsf.def_static("operator delete[]_", (void (*)(void *)) &gp_Trsf::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Trsf.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Trsf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Trsf.def_static("operator delete_", (void (*)(void *, void *)) &gp_Trsf::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Trsf.def("SetMirror", (void (gp_Trsf::*)(const gp_Pnt &)) &gp_Trsf::SetMirror, "Makes the transformation into a symmetrical transformation. P is the center of the symmetry.", py::arg("P"));
cls_gp_Trsf.def("SetMirror", (void (gp_Trsf::*)(const gp_Ax1 &)) &gp_Trsf::SetMirror, "Makes the transformation into a symmetrical transformation. A1 is the center of the axial symmetry.", py::arg("A1"));
cls_gp_Trsf.def("SetMirror", (void (gp_Trsf::*)(const gp_Ax2 &)) &gp_Trsf::SetMirror, "Makes the transformation into a symmetrical transformation. A2 is the center of the planar symmetry and defines the plane of symmetry by its origin, 'X Direction' and 'Y Direction'.", py::arg("A2"));
cls_gp_Trsf.def("SetRotation", (void (gp_Trsf::*)(const gp_Ax1 &, const Standard_Real)) &gp_Trsf::SetRotation, "Changes the transformation into a rotation. A1 is the rotation axis and Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Trsf.def("SetRotation", (void (gp_Trsf::*)(const gp_Quaternion &)) &gp_Trsf::SetRotation, "Changes the transformation into a rotation defined by quaternion. Note that rotation is performed around origin, i.e. no translation is involved.", py::arg("R"));
cls_gp_Trsf.def("SetScale", (void (gp_Trsf::*)(const gp_Pnt &, const Standard_Real)) &gp_Trsf::SetScale, "Changes the transformation into a scale. P is the center of the scale and S is the scaling value. Raises ConstructionError If <S> is null.", py::arg("P"), py::arg("S"));
cls_gp_Trsf.def("SetDisplacement", (void (gp_Trsf::*)(const gp_Ax3 &, const gp_Ax3 &)) &gp_Trsf::SetDisplacement, "Modifies this transformation so that it transforms the coordinate system defined by FromSystem1 into the one defined by ToSystem2. After this modification, this transformation transforms: - the origin of FromSystem1 into the origin of ToSystem2, - the 'X Direction' of FromSystem1 into the 'X Direction' of ToSystem2, - the 'Y Direction' of FromSystem1 into the 'Y Direction' of ToSystem2, and - the 'main Direction' of FromSystem1 into the 'main Direction' of ToSystem2. Warning When you know the coordinates of a point in one coordinate system and you want to express these coordinates in another one, do not use the transformation resulting from this function. Use the transformation that results from SetTransformation instead. SetDisplacement and SetTransformation create related transformations: the vectorial part of one is the inverse of the vectorial part of the other.", py::arg("FromSystem1"), py::arg("ToSystem2"));
cls_gp_Trsf.def("SetTransformation", (void (gp_Trsf::*)(const gp_Ax3 &, const gp_Ax3 &)) &gp_Trsf::SetTransformation, "Modifies this transformation so that it transforms the coordinates of any point, (x, y, z), relative to a source coordinate system into the coordinates (x', y', z') which are relative to a target coordinate system, but which represent the same point The transformation is from the coordinate system 'FromSystem1' to the coordinate system 'ToSystem2'. Example : In a C++ implementation : Real x1, y1, z1; // are the coordinates of a point in the // local system FromSystem1 Real x2, y2, z2; // are the coordinates of a point in the // local system ToSystem2 gp_Pnt P1 (x1, y1, z1) Trsf T; T.SetTransformation (FromSystem1, ToSystem2); gp_Pnt P2 = P1.Transformed (T); P2.Coord (x2, y2, z2);", py::arg("FromSystem1"), py::arg("ToSystem2"));
cls_gp_Trsf.def("SetTransformation", (void (gp_Trsf::*)(const gp_Ax3 &)) &gp_Trsf::SetTransformation, "Modifies this transformation so that it transforms the coordinates of any point, (x, y, z), relative to a source coordinate system into the coordinates (x', y', z') which are relative to a target coordinate system, but which represent the same point The transformation is from the default coordinate system {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.), VZ (0., 0. ,1.) } to the local coordinate system defined with the Ax3 ToSystem. Use in the same way as the previous method. FromSystem1 is defaulted to the absolute coordinate system.", py::arg("ToSystem"));
cls_gp_Trsf.def("SetTransformation", (void (gp_Trsf::*)(const gp_Quaternion &, const gp_Vec &)) &gp_Trsf::SetTransformation, "Sets transformation by directly specified rotation and translation.", py::arg("R"), py::arg("T"));
cls_gp_Trsf.def("SetTranslation", (void (gp_Trsf::*)(const gp_Vec &)) &gp_Trsf::SetTranslation, "Changes the transformation into a translation. V is the vector of the translation.", py::arg("V"));
cls_gp_Trsf.def("SetTranslation", (void (gp_Trsf::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Trsf::SetTranslation, "Makes the transformation into a translation where the translation vector is the vector (P1, P2) defined from point P1 to point P2.", py::arg("P1"), py::arg("P2"));
cls_gp_Trsf.def("SetTranslationPart", (void (gp_Trsf::*)(const gp_Vec &)) &gp_Trsf::SetTranslationPart, "Replaces the translation vector with the vector V.", py::arg("V"));
cls_gp_Trsf.def("SetScaleFactor", (void (gp_Trsf::*)(const Standard_Real)) &gp_Trsf::SetScaleFactor, "Modifies the scale factor. Raises ConstructionError If S is null.", py::arg("S"));
cls_gp_Trsf.def("SetForm", (void (gp_Trsf::*)(const gp_TrsfForm)) &gp_Trsf::SetForm, "None", py::arg("P"));
cls_gp_Trsf.def("SetValues", (void (gp_Trsf::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Trsf::SetValues, "Sets the coefficients of the transformation. The transformation of the point x,y,z is the point x',y',z' with :", py::arg("a11"), py::arg("a12"), py::arg("a13"), py::arg("a14"), py::arg("a21"), py::arg("a22"), py::arg("a23"), py::arg("a24"), py::arg("a31"), py::arg("a32"), py::arg("a33"), py::arg("a34"));
cls_gp_Trsf.def("IsNegative", (Standard_Boolean (gp_Trsf::*)() const) &gp_Trsf::IsNegative, "Returns true if the determinant of the vectorial part of this transformation is negative.");
cls_gp_Trsf.def("Form", (gp_TrsfForm (gp_Trsf::*)() const) &gp_Trsf::Form, "Returns the nature of the transformation. It can be: an identity transformation, a rotation, a translation, a mirror transformation (relative to a point, an axis or a plane), a scaling transformation, or a compound transformation.");
cls_gp_Trsf.def("ScaleFactor", (Standard_Real (gp_Trsf::*)() const) &gp_Trsf::ScaleFactor, "Returns the scale factor.");
cls_gp_Trsf.def("TranslationPart", (const gp_XYZ & (gp_Trsf::*)() const) &gp_Trsf::TranslationPart, "Returns the translation part of the transformation's matrix");
cls_gp_Trsf.def("GetRotation", [](gp_Trsf &self, gp_XYZ & theAxis, Standard_Real & theAngle){ Standard_Boolean rv = self.GetRotation(theAxis, theAngle); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theAngle); }, "Returns the boolean True if there is non-zero rotation. In the presence of rotation, the output parameters store the axis and the angle of rotation. The method always returns positive value 'theAngle', i.e., 0. < theAngle <= PI. Note that this rotation is defined only by the vectorial part of the transformation; generally you would need to check also the translational part to obtain the axis (gp_Ax1) of rotation.", py::arg("theAxis"), py::arg("theAngle"));
cls_gp_Trsf.def("GetRotation", (gp_Quaternion (gp_Trsf::*)() const) &gp_Trsf::GetRotation, "Returns quaternion representing rotational part of the transformation.");
cls_gp_Trsf.def("VectorialPart", (gp_Mat (gp_Trsf::*)() const) &gp_Trsf::VectorialPart, "Returns the vectorial part of the transformation. It is a 3*3 matrix which includes the scale factor.");
cls_gp_Trsf.def("HVectorialPart", (const gp_Mat & (gp_Trsf::*)() const) &gp_Trsf::HVectorialPart, "Computes the homogeneous vectorial part of the transformation. It is a 3*3 matrix which doesn't include the scale factor. In other words, the vectorial part of this transformation is equal to its homogeneous vectorial part, multiplied by the scale factor. The coefficients of this matrix must be multiplied by the scale factor to obtain the coefficients of the transformation.");
cls_gp_Trsf.def("Value", (Standard_Real (gp_Trsf::*)(const Standard_Integer, const Standard_Integer) const) &gp_Trsf::Value, "Returns the coefficients of the transformation's matrix. It is a 3 rows * 4 columns matrix. This coefficient includes the scale factor. Raises OutOfRanged if Row < 1 or Row > 3 or Col < 1 or Col > 4", py::arg("Row"), py::arg("Col"));
cls_gp_Trsf.def("Invert", (void (gp_Trsf::*)()) &gp_Trsf::Invert, "None");
cls_gp_Trsf.def("Inverted", (gp_Trsf (gp_Trsf::*)() const) &gp_Trsf::Inverted, "Computes the reverse transformation Raises an exception if the matrix of the transformation is not inversible, it means that the scale factor is lower or equal to Resolution from package gp. Computes the transformation composed with T and <me>. In a C++ implementation you can also write Tcomposed = <me> * T. Example : Trsf T1, T2, Tcomp; ............... Tcomp = T2.Multiplied(T1); // or (Tcomp = T2 * T1) Pnt P1(10.,3.,4.); Pnt P2 = P1.Transformed(Tcomp); //using Tcomp Pnt P3 = P1.Transformed(T1); //using T1 then T2 P3.Transform(T2); // P3 = P2 !!!");
cls_gp_Trsf.def("Multiplied", (gp_Trsf (gp_Trsf::*)(const gp_Trsf &) const) &gp_Trsf::Multiplied, "None", py::arg("T"));
cls_gp_Trsf.def("__mul__", (gp_Trsf (gp_Trsf::*)(const gp_Trsf &) const) &gp_Trsf::operator*, py::is_operator(), "None", py::arg("T"));
cls_gp_Trsf.def("Multiply", (void (gp_Trsf::*)(const gp_Trsf &)) &gp_Trsf::Multiply, "Computes the transformation composed with <me> and T. <me> = <me> * T", py::arg("T"));
cls_gp_Trsf.def("__imul__", (void (gp_Trsf::*)(const gp_Trsf &)) &gp_Trsf::operator*=, py::is_operator(), "None", py::arg("T"));
cls_gp_Trsf.def("PreMultiply", (void (gp_Trsf::*)(const gp_Trsf &)) &gp_Trsf::PreMultiply, "Computes the transformation composed with <me> and T. <me> = T * <me>", py::arg("T"));
cls_gp_Trsf.def("Power", (void (gp_Trsf::*)(const Standard_Integer)) &gp_Trsf::Power, "None", py::arg("N"));
cls_gp_Trsf.def("Powered", (gp_Trsf (gp_Trsf::*)(const Standard_Integer) const) &gp_Trsf::Powered, "Computes the following composition of transformations <me> * <me> * .......* <me>, N time. if N = 0 <me> = Identity if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().", py::arg("N"));
cls_gp_Trsf.def("Transforms", [](gp_Trsf &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Transforms(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "None", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_gp_Trsf.def("Transforms", (void (gp_Trsf::*)(gp_XYZ &) const) &gp_Trsf::Transforms, "Transformation of a triplet XYZ with a Trsf", py::arg("Coord"));

// CLASS: GP_VEC
py::class_<gp_Vec> cls_gp_Vec(mod, "gp_Vec", "Defines a non-persistent vector in 3D space.");

// Constructors
cls_gp_Vec.def(py::init<>());
cls_gp_Vec.def(py::init<const gp_Dir &>(), py::arg("V"));
cls_gp_Vec.def(py::init<const gp_XYZ &>(), py::arg("Coord"));
cls_gp_Vec.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));
cls_gp_Vec.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));

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

// CLASS: GP_DIR
py::class_<gp_Dir> cls_gp_Dir(mod, "gp_Dir", "Describes a unit vector in 3D space. This unit vector is also called 'Direction'. See Also gce_MakeDir which provides functions for more complex unit vector constructions Geom_Direction which provides additional functions for constructing unit vectors and works, in particular, with the parametric equations of unit vectors.");

// Constructors
cls_gp_Dir.def(py::init<>());
cls_gp_Dir.def(py::init<const gp_Vec &>(), py::arg("V"));
cls_gp_Dir.def(py::init<const gp_XYZ &>(), py::arg("Coord"));
cls_gp_Dir.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));

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

// CLASS: GP_PNT
py::class_<gp_Pnt> cls_gp_Pnt(mod, "gp_Pnt", "Defines a 3D cartesian point.");

// Constructors
cls_gp_Pnt.def(py::init<>());
cls_gp_Pnt.def(py::init<const gp_XYZ &>(), py::arg("Coord"));
cls_gp_Pnt.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Xp"), py::arg("Yp"), py::arg("Zp"));

// Methods
// cls_gp_Pnt.def_static("operator new_", (void * (*)(size_t)) &gp_Pnt::operator new, "None", py::arg("theSize"));
// cls_gp_Pnt.def_static("operator delete_", (void (*)(void *)) &gp_Pnt::operator delete, "None", py::arg("theAddress"));
// cls_gp_Pnt.def_static("operator new[]_", (void * (*)(size_t)) &gp_Pnt::operator new[], "None", py::arg("theSize"));
// cls_gp_Pnt.def_static("operator delete[]_", (void (*)(void *)) &gp_Pnt::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Pnt.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Pnt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Pnt.def_static("operator delete_", (void (*)(void *, void *)) &gp_Pnt::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Pnt.def("SetCoord", (void (gp_Pnt::*)(const Standard_Integer, const Standard_Real)) &gp_Pnt::SetCoord, "Changes the coordinate of range Index : Index = 1 => X is modified Index = 2 => Y is modified Index = 3 => Z is modified Raised if Index != {1, 2, 3}.", py::arg("Index"), py::arg("Xi"));
cls_gp_Pnt.def("SetCoord", (void (gp_Pnt::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Pnt::SetCoord, "For this point, assigns the values Xp, Yp and Zp to its three coordinates.", py::arg("Xp"), py::arg("Yp"), py::arg("Zp"));
cls_gp_Pnt.def("SetX", (void (gp_Pnt::*)(const Standard_Real)) &gp_Pnt::SetX, "Assigns the given value to the X coordinate of this point.", py::arg("X"));
cls_gp_Pnt.def("SetY", (void (gp_Pnt::*)(const Standard_Real)) &gp_Pnt::SetY, "Assigns the given value to the Y coordinate of this point.", py::arg("Y"));
cls_gp_Pnt.def("SetZ", (void (gp_Pnt::*)(const Standard_Real)) &gp_Pnt::SetZ, "Assigns the given value to the Z coordinate of this point.", py::arg("Z"));
cls_gp_Pnt.def("SetXYZ", (void (gp_Pnt::*)(const gp_XYZ &)) &gp_Pnt::SetXYZ, "Assigns the three coordinates of Coord to this point.", py::arg("Coord"));
cls_gp_Pnt.def("Coord", (Standard_Real (gp_Pnt::*)(const Standard_Integer) const) &gp_Pnt::Coord, "Returns the coordinate of corresponding to the value of Index : Index = 1 => X is returned Index = 2 => Y is returned Index = 3 => Z is returned Raises OutOfRange if Index != {1, 2, 3}. Raised if Index != {1, 2, 3}.", py::arg("Index"));
cls_gp_Pnt.def("Coord", [](gp_Pnt &self, Standard_Real & Xp, Standard_Real & Yp, Standard_Real & Zp){ self.Coord(Xp, Yp, Zp); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Xp, Yp, Zp); }, "For this point gives its three coordinates Xp, Yp and Zp.", py::arg("Xp"), py::arg("Yp"), py::arg("Zp"));
cls_gp_Pnt.def("X", (Standard_Real (gp_Pnt::*)() const) &gp_Pnt::X, "For this point, returns its X coordinate.");
cls_gp_Pnt.def("Y", (Standard_Real (gp_Pnt::*)() const) &gp_Pnt::Y, "For this point, returns its Y coordinate.");
cls_gp_Pnt.def("Z", (Standard_Real (gp_Pnt::*)() const) &gp_Pnt::Z, "For this point, returns its Z coordinate.");
cls_gp_Pnt.def("XYZ", (const gp_XYZ & (gp_Pnt::*)() const) &gp_Pnt::XYZ, "For this point, returns its three coordinates as a XYZ object.");
cls_gp_Pnt.def("Coord", (const gp_XYZ & (gp_Pnt::*)() const) &gp_Pnt::Coord, "For this point, returns its three coordinates as a XYZ object.");
cls_gp_Pnt.def("ChangeCoord", (gp_XYZ & (gp_Pnt::*)()) &gp_Pnt::ChangeCoord, "Returns the coordinates of this point. Note: This syntax allows direct modification of the returned value.");
cls_gp_Pnt.def("BaryCenter", (void (gp_Pnt::*)(const Standard_Real, const gp_Pnt &, const Standard_Real)) &gp_Pnt::BaryCenter, "Assigns the result of the following expression to this point (Alpha*this + Beta*P) / (Alpha + Beta)", py::arg("Alpha"), py::arg("P"), py::arg("Beta"));
cls_gp_Pnt.def("IsEqual", (Standard_Boolean (gp_Pnt::*)(const gp_Pnt &, const Standard_Real) const) &gp_Pnt::IsEqual, "Comparison Returns True if the distance between the two points is lower or equal to LinearTolerance.", py::arg("Other"), py::arg("LinearTolerance"));
cls_gp_Pnt.def("Distance", (Standard_Real (gp_Pnt::*)(const gp_Pnt &) const) &gp_Pnt::Distance, "Computes the distance between two points.", py::arg("Other"));
cls_gp_Pnt.def("SquareDistance", (Standard_Real (gp_Pnt::*)(const gp_Pnt &) const) &gp_Pnt::SquareDistance, "Computes the square distance between two points.", py::arg("Other"));
cls_gp_Pnt.def("Mirror", (void (gp_Pnt::*)(const gp_Pnt &)) &gp_Pnt::Mirror, "Performs the symmetrical transformation of a point with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Pnt.def("Mirrored", (gp_Pnt (gp_Pnt::*)(const gp_Pnt &) const) &gp_Pnt::Mirrored, "Performs the symmetrical transformation of a point with respect to an axis placement which is the axis of the symmetry.", py::arg("P"));
cls_gp_Pnt.def("Mirror", (void (gp_Pnt::*)(const gp_Ax1 &)) &gp_Pnt::Mirror, "None", py::arg("A1"));
cls_gp_Pnt.def("Mirrored", (gp_Pnt (gp_Pnt::*)(const gp_Ax1 &) const) &gp_Pnt::Mirrored, "Performs the symmetrical transformation of a point with respect to a plane. The axis placement A2 locates the plane of the symmetry : (Location, XDirection, YDirection).", py::arg("A1"));
cls_gp_Pnt.def("Mirror", (void (gp_Pnt::*)(const gp_Ax2 &)) &gp_Pnt::Mirror, "None", py::arg("A2"));
cls_gp_Pnt.def("Mirrored", (gp_Pnt (gp_Pnt::*)(const gp_Ax2 &) const) &gp_Pnt::Mirrored, "Rotates a point. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A2"));
cls_gp_Pnt.def("Rotate", (void (gp_Pnt::*)(const gp_Ax1 &, const Standard_Real)) &gp_Pnt::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Pnt.def("Rotated", (gp_Pnt (gp_Pnt::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Pnt::Rotated, "Scales a point. S is the scaling value.", py::arg("A1"), py::arg("Ang"));
cls_gp_Pnt.def("Scale", (void (gp_Pnt::*)(const gp_Pnt &, const Standard_Real)) &gp_Pnt::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Pnt.def("Scaled", (gp_Pnt (gp_Pnt::*)(const gp_Pnt &, const Standard_Real) const) &gp_Pnt::Scaled, "Transforms a point with the transformation T.", py::arg("P"), py::arg("S"));
cls_gp_Pnt.def("Transform", (void (gp_Pnt::*)(const gp_Trsf &)) &gp_Pnt::Transform, "None", py::arg("T"));
cls_gp_Pnt.def("Transformed", (gp_Pnt (gp_Pnt::*)(const gp_Trsf &) const) &gp_Pnt::Transformed, "Translates a point in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("T"));
cls_gp_Pnt.def("Translate", (void (gp_Pnt::*)(const gp_Vec &)) &gp_Pnt::Translate, "None", py::arg("V"));
cls_gp_Pnt.def("Translated", (gp_Pnt (gp_Pnt::*)(const gp_Vec &) const) &gp_Pnt::Translated, "Translates a point from the point P1 to the point P2.", py::arg("V"));
cls_gp_Pnt.def("Translate", (void (gp_Pnt::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Pnt::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Pnt.def("Translated", (gp_Pnt (gp_Pnt::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Pnt::Translated, "None", py::arg("P1"), py::arg("P2"));

// CLASS: GP_VECTORWITHNULLMAGNITUDE
py::class_<gp_VectorWithNullMagnitude, opencascade::handle<gp_VectorWithNullMagnitude>, Standard_DomainError> cls_gp_VectorWithNullMagnitude(mod, "gp_VectorWithNullMagnitude", "None");

// Constructors
cls_gp_VectorWithNullMagnitude.def(py::init<>());
cls_gp_VectorWithNullMagnitude.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_gp_VectorWithNullMagnitude.def_static("Raise_", (void (*)(const Standard_CString)) &gp_VectorWithNullMagnitude::Raise, "None", py::arg("theMessage"));
cls_gp_VectorWithNullMagnitude.def_static("Raise_", (void (*)(Standard_SStream &)) &gp_VectorWithNullMagnitude::Raise, "None", py::arg("theMessage"));
cls_gp_VectorWithNullMagnitude.def_static("NewInstance_", (opencascade::handle<gp_VectorWithNullMagnitude> (*)(const Standard_CString)) &gp_VectorWithNullMagnitude::NewInstance, "None", py::arg("theMessage"));
cls_gp_VectorWithNullMagnitude.def_static("get_type_name_", (const char * (*)()) &gp_VectorWithNullMagnitude::get_type_name, "None");
cls_gp_VectorWithNullMagnitude.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &gp_VectorWithNullMagnitude::get_type_descriptor, "None");
cls_gp_VectorWithNullMagnitude.def("DynamicType", (const opencascade::handle<Standard_Type> & (gp_VectorWithNullMagnitude::*)() const) &gp_VectorWithNullMagnitude::DynamicType, "None");

// CLASS: GP_LIN2D
py::class_<gp_Lin2d> cls_gp_Lin2d(mod, "gp_Lin2d", "Describes a line in 2D space. A line is positioned in the plane with an axis (a gp_Ax2d object) which gives the line its origin and unit vector. A line and an axis are similar objects, thus, we can convert one into the other. A line provides direct access to the majority of the edit and query functions available on its positioning axis. In addition, however, a line has specific functions for computing distances and positions. See Also GccAna and Geom2dGcc packages which provide functions for constructing lines defined by geometric constraints gce_MakeLin2d which provides functions for more complex line constructions Geom2d_Line which provides additional functions for constructing lines and works, in particular, with the parametric equations of lines");

// Constructors
cls_gp_Lin2d.def(py::init<>());
cls_gp_Lin2d.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_gp_Lin2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));
cls_gp_Lin2d.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"));

// Methods
// cls_gp_Lin2d.def_static("operator new_", (void * (*)(size_t)) &gp_Lin2d::operator new, "None", py::arg("theSize"));
// cls_gp_Lin2d.def_static("operator delete_", (void (*)(void *)) &gp_Lin2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Lin2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Lin2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Lin2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Lin2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Lin2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Lin2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Lin2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Lin2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Lin2d.def("Reverse", (void (gp_Lin2d::*)()) &gp_Lin2d::Reverse, "None");
cls_gp_Lin2d.def("Reversed", (gp_Lin2d (gp_Lin2d::*)() const) &gp_Lin2d::Reversed, "Reverses the positioning axis of this line. Note: - Reverse assigns the result to this line, while - Reversed creates a new one.");
cls_gp_Lin2d.def("SetDirection", (void (gp_Lin2d::*)(const gp_Dir2d &)) &gp_Lin2d::SetDirection, "Changes the direction of the line.", py::arg("V"));
cls_gp_Lin2d.def("SetLocation", (void (gp_Lin2d::*)(const gp_Pnt2d &)) &gp_Lin2d::SetLocation, "Changes the origin of the line.", py::arg("P"));
cls_gp_Lin2d.def("SetPosition", (void (gp_Lin2d::*)(const gp_Ax2d &)) &gp_Lin2d::SetPosition, "Complete redefinition of the line. The 'Location' point of <A> is the origin of the line. The 'Direction' of <A> is the direction of the line.", py::arg("A"));
cls_gp_Lin2d.def("Coefficients", [](gp_Lin2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C){ self.Coefficients(A, B, C); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C); }, "Returns the normalized coefficients of the line : A * X + B * Y + C = 0.", py::arg("A"), py::arg("B"), py::arg("C"));
cls_gp_Lin2d.def("Direction", (const gp_Dir2d & (gp_Lin2d::*)() const) &gp_Lin2d::Direction, "Returns the direction of the line.");
cls_gp_Lin2d.def("Location", (const gp_Pnt2d & (gp_Lin2d::*)() const) &gp_Lin2d::Location, "Returns the location point (origin) of the line.");
cls_gp_Lin2d.def("Position", (const gp_Ax2d & (gp_Lin2d::*)() const) &gp_Lin2d::Position, "Returns the axis placement one axis whith the same location and direction as <me>.");
cls_gp_Lin2d.def("Angle", (Standard_Real (gp_Lin2d::*)(const gp_Lin2d &) const) &gp_Lin2d::Angle, "Computes the angle between two lines in radians.", py::arg("Other"));
cls_gp_Lin2d.def("Contains", (Standard_Boolean (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Lin2d::Contains, "Returns true if this line contains the point P, that is, if the distance between point P and this line is less than or equal to LinearTolerance.", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Lin2d.def("Distance", (Standard_Real (gp_Lin2d::*)(const gp_Pnt2d &) const) &gp_Lin2d::Distance, "Computes the distance between <me> and the point <P>.", py::arg("P"));
cls_gp_Lin2d.def("Distance", (Standard_Real (gp_Lin2d::*)(const gp_Lin2d &) const) &gp_Lin2d::Distance, "Computes the distance between two lines.", py::arg("Other"));
cls_gp_Lin2d.def("SquareDistance", (Standard_Real (gp_Lin2d::*)(const gp_Pnt2d &) const) &gp_Lin2d::SquareDistance, "Computes the square distance between <me> and the point <P>.", py::arg("P"));
cls_gp_Lin2d.def("SquareDistance", (Standard_Real (gp_Lin2d::*)(const gp_Lin2d &) const) &gp_Lin2d::SquareDistance, "Computes the square distance between two lines.", py::arg("Other"));
cls_gp_Lin2d.def("Normal", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &) const) &gp_Lin2d::Normal, "Computes the line normal to the direction of <me>, passing through the point <P>.", py::arg("P"));
cls_gp_Lin2d.def("Mirror", (void (gp_Lin2d::*)(const gp_Pnt2d &)) &gp_Lin2d::Mirror, "None", py::arg("P"));
cls_gp_Lin2d.def("Mirrored", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &) const) &gp_Lin2d::Mirrored, "Performs the symmetrical transformation of a line with respect to the point <P> which is the center of the symmetry", py::arg("P"));
cls_gp_Lin2d.def("Mirror", (void (gp_Lin2d::*)(const gp_Ax2d &)) &gp_Lin2d::Mirror, "None", py::arg("A"));
cls_gp_Lin2d.def("Mirrored", (gp_Lin2d (gp_Lin2d::*)(const gp_Ax2d &) const) &gp_Lin2d::Mirrored, "Performs the symmetrical transformation of a line with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Lin2d.def("Rotate", (void (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Lin2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Lin2d.def("Rotated", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Lin2d::Rotated, "Rotates a line. P is the center of the rotation. Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Lin2d.def("Scale", (void (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Lin2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Lin2d.def("Scaled", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Lin2d::Scaled, "Scales a line. S is the scaling value. Only the origin of the line is modified.", py::arg("P"), py::arg("S"));
cls_gp_Lin2d.def("Transform", (void (gp_Lin2d::*)(const gp_Trsf2d &)) &gp_Lin2d::Transform, "None", py::arg("T"));
cls_gp_Lin2d.def("Transformed", (gp_Lin2d (gp_Lin2d::*)(const gp_Trsf2d &) const) &gp_Lin2d::Transformed, "Transforms a line with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Lin2d.def("Translate", (void (gp_Lin2d::*)(const gp_Vec2d &)) &gp_Lin2d::Translate, "None", py::arg("V"));
cls_gp_Lin2d.def("Translated", (gp_Lin2d (gp_Lin2d::*)(const gp_Vec2d &) const) &gp_Lin2d::Translated, "Translates a line in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Lin2d.def("Translate", (void (gp_Lin2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Lin2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Lin2d.def("Translated", (gp_Lin2d (gp_Lin2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Lin2d::Translated, "Translates a line from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_AX22D
py::class_<gp_Ax22d> cls_gp_Ax22d(mod, "gp_Ax22d", "Describes a coordinate system in a plane (2D space). A coordinate system is defined by: - its origin (also referred to as its 'Location point'), and - two orthogonal unit vectors, respectively, called the 'X Direction' and the 'Y Direction'. A gp_Ax22d may be right-handed ('direct sense') or left-handed ('inverse' or 'indirect sense'). You use a gp_Ax22d to: - describe 2D geometric entities, in particular to position them. The local coordinate system of a geometric entity serves for the same purpose as the STEP function 'axis placement two axes', or - define geometric transformations. Note: we refer to the 'X Axis' and 'Y Axis' as the axes having: - the origin of the coordinate system as their origin, and - the unit vectors 'X Direction' and 'Y Direction', respectively, as their unit vectors.");

// Constructors
cls_gp_Ax22d.def(py::init<>());
cls_gp_Ax22d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("Vx"), py::arg("Vy"));
cls_gp_Ax22d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));
cls_gp_Ax22d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &, const Standard_Boolean>(), py::arg("P"), py::arg("V"), py::arg("Sense"));
cls_gp_Ax22d.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_gp_Ax22d.def(py::init<const gp_Ax2d &, const Standard_Boolean>(), py::arg("A"), py::arg("Sense"));

// Methods
// cls_gp_Ax22d.def_static("operator new_", (void * (*)(size_t)) &gp_Ax22d::operator new, "None", py::arg("theSize"));
// cls_gp_Ax22d.def_static("operator delete_", (void (*)(void *)) &gp_Ax22d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Ax22d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Ax22d::operator new[], "None", py::arg("theSize"));
// cls_gp_Ax22d.def_static("operator delete[]_", (void (*)(void *)) &gp_Ax22d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Ax22d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Ax22d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Ax22d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Ax22d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Ax22d.def("SetAxis", (void (gp_Ax22d::*)(const gp_Ax22d &)) &gp_Ax22d::SetAxis, "Assigns the origin and the two unit vectors of the coordinate system A1 to this coordinate system.", py::arg("A1"));
cls_gp_Ax22d.def("SetXAxis", (void (gp_Ax22d::*)(const gp_Ax2d &)) &gp_Ax22d::SetXAxis, "Changes the XAxis and YAxis ('Location' point and 'Direction') of <me>. The 'YDirection' is recomputed in the same sense as before.", py::arg("A1"));
cls_gp_Ax22d.def("SetYAxis", (void (gp_Ax22d::*)(const gp_Ax2d &)) &gp_Ax22d::SetYAxis, "Changes the XAxis and YAxis ('Location' point and 'Direction') of <me>. The 'XDirection' is recomputed in the same sense as before.", py::arg("A1"));
cls_gp_Ax22d.def("SetLocation", (void (gp_Ax22d::*)(const gp_Pnt2d &)) &gp_Ax22d::SetLocation, "Changes the 'Location' point (origin) of <me>.", py::arg("P"));
cls_gp_Ax22d.def("SetXDirection", (void (gp_Ax22d::*)(const gp_Dir2d &)) &gp_Ax22d::SetXDirection, "Assigns Vx to the 'X Direction' of this coordinate system. The other unit vector of this coordinate system is recomputed, normal to Vx , without modifying the orientation (right-handed or left-handed) of this coordinate system.", py::arg("Vx"));
cls_gp_Ax22d.def("SetYDirection", (void (gp_Ax22d::*)(const gp_Dir2d &)) &gp_Ax22d::SetYDirection, "Assignsr Vy to the 'Y Direction' of this coordinate system. The other unit vector of this coordinate system is recomputed, normal to Vy, without modifying the orientation (right-handed or left-handed) of this coordinate system.", py::arg("Vy"));
cls_gp_Ax22d.def("XAxis", (gp_Ax2d (gp_Ax22d::*)() const) &gp_Ax22d::XAxis, "Returns an axis, for which - the origin is that of this coordinate system, and - the unit vector is either the 'X Direction' of this coordinate system. Note: the result is the 'X Axis' of this coordinate system.");
cls_gp_Ax22d.def("YAxis", (gp_Ax2d (gp_Ax22d::*)() const) &gp_Ax22d::YAxis, "Returns an axis, for which - the origin is that of this coordinate system, and - the unit vector is either the 'Y Direction' of this coordinate system. Note: the result is the 'Y Axis' of this coordinate system.");
cls_gp_Ax22d.def("Location", (const gp_Pnt2d & (gp_Ax22d::*)() const) &gp_Ax22d::Location, "Returns the 'Location' point (origin) of <me>.");
cls_gp_Ax22d.def("XDirection", (const gp_Dir2d & (gp_Ax22d::*)() const) &gp_Ax22d::XDirection, "Returns the 'XDirection' of <me>.");
cls_gp_Ax22d.def("YDirection", (const gp_Dir2d & (gp_Ax22d::*)() const) &gp_Ax22d::YDirection, "Returns the 'YDirection' of <me>.");
cls_gp_Ax22d.def("Mirror", (void (gp_Ax22d::*)(const gp_Pnt2d &)) &gp_Ax22d::Mirror, "None", py::arg("P"));
cls_gp_Ax22d.def("Mirrored", (gp_Ax22d (gp_Ax22d::*)(const gp_Pnt2d &) const) &gp_Ax22d::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to the point P which is the center of the symmetry. Warnings : The main direction of the axis placement is not changed. The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"));
cls_gp_Ax22d.def("Mirror", (void (gp_Ax22d::*)(const gp_Ax2d &)) &gp_Ax22d::Mirror, "None", py::arg("A"));
cls_gp_Ax22d.def("Mirrored", (gp_Ax22d (gp_Ax22d::*)(const gp_Ax2d &) const) &gp_Ax22d::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to an axis placement which is the axis of the symmetry. The transformation is performed on the 'Location' point, on the 'XDirection' and 'YDirection'. The resulting main 'Direction' is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("A"));
cls_gp_Ax22d.def("Rotate", (void (gp_Ax22d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Ax22d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Ax22d.def("Rotated", (gp_Ax22d (gp_Ax22d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Ax22d::Rotated, "Rotates an axis placement. <A1> is the axis of the rotation . Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Ax22d.def("Scale", (void (gp_Ax22d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Ax22d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Ax22d.def("Scaled", (gp_Ax22d (gp_Ax22d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Ax22d::Scaled, "Applies a scaling transformation on the axis placement. The 'Location' point of the axisplacement is modified. Warnings : If the scale <S> is negative : . the main direction of the axis placement is not changed. . The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"), py::arg("S"));
cls_gp_Ax22d.def("Transform", (void (gp_Ax22d::*)(const gp_Trsf2d &)) &gp_Ax22d::Transform, "None", py::arg("T"));
cls_gp_Ax22d.def("Transformed", (gp_Ax22d (gp_Ax22d::*)(const gp_Trsf2d &) const) &gp_Ax22d::Transformed, "Transforms an axis placement with a Trsf. The 'Location' point, the 'XDirection' and the 'YDirection' are transformed with T. The resulting main 'Direction' of <me> is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("T"));
cls_gp_Ax22d.def("Translate", (void (gp_Ax22d::*)(const gp_Vec2d &)) &gp_Ax22d::Translate, "None", py::arg("V"));
cls_gp_Ax22d.def("Translated", (gp_Ax22d (gp_Ax22d::*)(const gp_Vec2d &) const) &gp_Ax22d::Translated, "Translates an axis plaxement in the direction of the vector <V>. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Ax22d.def("Translate", (void (gp_Ax22d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Ax22d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Ax22d.def("Translated", (gp_Ax22d (gp_Ax22d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Ax22d::Translated, "Translates an axis placement from the point <P1> to the point <P2>.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_CIRC2D
py::class_<gp_Circ2d> cls_gp_Circ2d(mod, "gp_Circ2d", "Describes a circle in the plane (2D space). A circle is defined by its radius and positioned in the plane with a coordinate system (a gp_Ax22d object) as follows: - the origin of the coordinate system is the center of the circle, and - the orientation (direct or indirect) of the coordinate system gives an implicit orientation to the circle (and defines its trigonometric sense). This positioning coordinate system is the 'local coordinate system' of the circle. Note: when a gp_Circ2d circle is converted into a Geom2d_Circle circle, some implicit properties of the circle are used explicitly: - the implicit orientation corresponds to the direction in which parameter values increase, - the starting point for parameterization is that of the 'X Axis' of the local coordinate system (i.e. the 'X Axis' of the circle). See Also GccAna and Geom2dGcc packages which provide functions for constructing circles defined by geometric constraints gce_MakeCirc2d which provides functions for more complex circle constructions Geom2d_Circle which provides additional functions for constructing circles and works, with the parametric equations of circles in particular gp_Ax22d");

// Constructors
cls_gp_Circ2d.def(py::init<>());
cls_gp_Circ2d.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("XAxis"), py::arg("Radius"));
cls_gp_Circ2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("XAxis"), py::arg("Radius"), py::arg("Sense"));
cls_gp_Circ2d.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));

// Methods
// cls_gp_Circ2d.def_static("operator new_", (void * (*)(size_t)) &gp_Circ2d::operator new, "None", py::arg("theSize"));
// cls_gp_Circ2d.def_static("operator delete_", (void (*)(void *)) &gp_Circ2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Circ2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Circ2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Circ2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Circ2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Circ2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Circ2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Circ2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Circ2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Circ2d.def("SetLocation", (void (gp_Circ2d::*)(const gp_Pnt2d &)) &gp_Circ2d::SetLocation, "Changes the location point (center) of the circle.", py::arg("P"));
cls_gp_Circ2d.def("SetXAxis", (void (gp_Circ2d::*)(const gp_Ax2d &)) &gp_Circ2d::SetXAxis, "Changes the X axis of the circle.", py::arg("A"));
cls_gp_Circ2d.def("SetAxis", (void (gp_Circ2d::*)(const gp_Ax22d &)) &gp_Circ2d::SetAxis, "Changes the X axis of the circle.", py::arg("A"));
cls_gp_Circ2d.def("SetYAxis", (void (gp_Circ2d::*)(const gp_Ax2d &)) &gp_Circ2d::SetYAxis, "Changes the Y axis of the circle.", py::arg("A"));
cls_gp_Circ2d.def("SetRadius", (void (gp_Circ2d::*)(const Standard_Real)) &gp_Circ2d::SetRadius, "Modifies the radius of this circle. This class does not prevent the creation of a circle where Radius is null. Exceptions Standard_ConstructionError if Radius is negative.", py::arg("Radius"));
cls_gp_Circ2d.def("Area", (Standard_Real (gp_Circ2d::*)() const) &gp_Circ2d::Area, "Computes the area of the circle.");
cls_gp_Circ2d.def("Coefficients", [](gp_Circ2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Coefficients(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "Returns the normalized coefficients from the implicit equation of the circle : A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.0", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_gp_Circ2d.def("Contains", (Standard_Boolean (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Circ2d::Contains, "Does <me> contain P ? Returns True if the distance between P and any point on the circumference of the circle is lower of equal to <LinearTolerance>.", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Circ2d.def("Distance", (Standard_Real (gp_Circ2d::*)(const gp_Pnt2d &) const) &gp_Circ2d::Distance, "Computes the minimum of distance between the point P and any point on the circumference of the circle.", py::arg("P"));
cls_gp_Circ2d.def("SquareDistance", (Standard_Real (gp_Circ2d::*)(const gp_Pnt2d &) const) &gp_Circ2d::SquareDistance, "Computes the square distance between <me> and the point P.", py::arg("P"));
cls_gp_Circ2d.def("Length", (Standard_Real (gp_Circ2d::*)() const) &gp_Circ2d::Length, "computes the circumference of the circle.");
cls_gp_Circ2d.def("Location", (const gp_Pnt2d & (gp_Circ2d::*)() const) &gp_Circ2d::Location, "Returns the location point (center) of the circle.");
cls_gp_Circ2d.def("Radius", (Standard_Real (gp_Circ2d::*)() const) &gp_Circ2d::Radius, "Returns the radius value of the circle.");
cls_gp_Circ2d.def("Axis", (const gp_Ax22d & (gp_Circ2d::*)() const) &gp_Circ2d::Axis, "returns the position of the circle.");
cls_gp_Circ2d.def("Position", (const gp_Ax22d & (gp_Circ2d::*)() const) &gp_Circ2d::Position, "returns the position of the circle. Idem Axis(me).");
cls_gp_Circ2d.def("XAxis", (gp_Ax2d (gp_Circ2d::*)() const) &gp_Circ2d::XAxis, "returns the X axis of the circle.");
cls_gp_Circ2d.def("YAxis", (gp_Ax2d (gp_Circ2d::*)() const) &gp_Circ2d::YAxis, "Returns the Y axis of the circle. Reverses the direction of the circle.");
cls_gp_Circ2d.def("Reverse", (void (gp_Circ2d::*)()) &gp_Circ2d::Reverse, "Reverses the orientation of the local coordinate system of this circle (the 'Y Direction' is reversed) and therefore changes the implicit orientation of this circle. Reverse assigns the result to this circle,");
cls_gp_Circ2d.def("Reversed", (gp_Circ2d (gp_Circ2d::*)() const) &gp_Circ2d::Reversed, "Reverses the orientation of the local coordinate system of this circle (the 'Y Direction' is reversed) and therefore changes the implicit orientation of this circle. Reversed creates a new circle.");
cls_gp_Circ2d.def("IsDirect", (Standard_Boolean (gp_Circ2d::*)() const) &gp_Circ2d::IsDirect, "Returns true if the local coordinate system is direct and false in the other case.");
cls_gp_Circ2d.def("Mirror", (void (gp_Circ2d::*)(const gp_Pnt2d &)) &gp_Circ2d::Mirror, "None", py::arg("P"));
cls_gp_Circ2d.def("Mirrored", (gp_Circ2d (gp_Circ2d::*)(const gp_Pnt2d &) const) &gp_Circ2d::Mirrored, "Performs the symmetrical transformation of a circle with respect to the point P which is the center of the symmetry", py::arg("P"));
cls_gp_Circ2d.def("Mirror", (void (gp_Circ2d::*)(const gp_Ax2d &)) &gp_Circ2d::Mirror, "None", py::arg("A"));
cls_gp_Circ2d.def("Mirrored", (gp_Circ2d (gp_Circ2d::*)(const gp_Ax2d &) const) &gp_Circ2d::Mirrored, "Performs the symmetrical transformation of a circle with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Circ2d.def("Rotate", (void (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Circ2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Circ2d.def("Rotated", (gp_Circ2d (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Circ2d::Rotated, "Rotates a circle. P is the center of the rotation. Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Circ2d.def("Scale", (void (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Circ2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Circ2d.def("Scaled", (gp_Circ2d (gp_Circ2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Circ2d::Scaled, "Scales a circle. S is the scaling value. Warnings : If S is negative the radius stay positive but the 'XAxis' and the 'YAxis' are reversed as for an ellipse.", py::arg("P"), py::arg("S"));
cls_gp_Circ2d.def("Transform", (void (gp_Circ2d::*)(const gp_Trsf2d &)) &gp_Circ2d::Transform, "None", py::arg("T"));
cls_gp_Circ2d.def("Transformed", (gp_Circ2d (gp_Circ2d::*)(const gp_Trsf2d &) const) &gp_Circ2d::Transformed, "Transforms a circle with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Circ2d.def("Translate", (void (gp_Circ2d::*)(const gp_Vec2d &)) &gp_Circ2d::Translate, "None", py::arg("V"));
cls_gp_Circ2d.def("Translated", (gp_Circ2d (gp_Circ2d::*)(const gp_Vec2d &) const) &gp_Circ2d::Translated, "Translates a circle in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Circ2d.def("Translate", (void (gp_Circ2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Circ2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Circ2d.def("Translated", (gp_Circ2d (gp_Circ2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Circ2d::Translated, "Translates a circle from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_ELIPS2D
py::class_<gp_Elips2d> cls_gp_Elips2d(mod, "gp_Elips2d", "Describes an ellipse in the plane (2D space). An ellipse is defined by its major and minor radii and positioned in the plane with a coordinate system (a gp_Ax22d object) as follows: - the origin of the coordinate system is the center of the ellipse, - its 'X Direction' defines the major axis of the ellipse, and - its 'Y Direction' defines the minor axis of the ellipse. This coordinate system is the 'local coordinate system' of the ellipse. Its orientation (direct or indirect) gives an implicit orientation to the ellipse. In this coordinate system, the equation of the ellipse is: X*X / (MajorRadius**2) + Y*Y / (MinorRadius**2) = 1.0 See Also gce_MakeElips2d which provides functions for more complex ellipse constructions Geom2d_Ellipse which provides additional functions for constructing ellipses and works, in particular, with the parametric equations of ellipses");

// Constructors
cls_gp_Elips2d.def(py::init<>());
cls_gp_Elips2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gp_Elips2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
cls_gp_Elips2d.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Methods
// cls_gp_Elips2d.def_static("operator new_", (void * (*)(size_t)) &gp_Elips2d::operator new, "None", py::arg("theSize"));
// cls_gp_Elips2d.def_static("operator delete_", (void (*)(void *)) &gp_Elips2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Elips2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Elips2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Elips2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Elips2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Elips2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Elips2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Elips2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Elips2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Elips2d.def("SetLocation", (void (gp_Elips2d::*)(const gp_Pnt2d &)) &gp_Elips2d::SetLocation, "Modifies this ellipse, by redefining its local coordinate system so that - its origin becomes P.", py::arg("P"));
cls_gp_Elips2d.def("SetMajorRadius", (void (gp_Elips2d::*)(const Standard_Real)) &gp_Elips2d::SetMajorRadius, "Changes the value of the major radius. Raises ConstructionError if MajorRadius < MinorRadius.", py::arg("MajorRadius"));
cls_gp_Elips2d.def("SetMinorRadius", (void (gp_Elips2d::*)(const Standard_Real)) &gp_Elips2d::SetMinorRadius, "Changes the value of the minor radius. Raises ConstructionError if MajorRadius < MinorRadius or MinorRadius < 0.0", py::arg("MinorRadius"));
cls_gp_Elips2d.def("SetAxis", (void (gp_Elips2d::*)(const gp_Ax22d &)) &gp_Elips2d::SetAxis, "Modifies this ellipse, by redefining its local coordinate system so that it becomes A.", py::arg("A"));
cls_gp_Elips2d.def("SetXAxis", (void (gp_Elips2d::*)(const gp_Ax2d &)) &gp_Elips2d::SetXAxis, "Modifies this ellipse, by redefining its local coordinate system so that its origin and its 'X Direction' become those of the axis A. The 'Y Direction' is then recomputed. The orientation of the local coordinate system is not modified.", py::arg("A"));
cls_gp_Elips2d.def("SetYAxis", (void (gp_Elips2d::*)(const gp_Ax2d &)) &gp_Elips2d::SetYAxis, "Modifies this ellipse, by redefining its local coordinate system so that its origin and its 'Y Direction' become those of the axis A. The 'X Direction' is then recomputed. The orientation of the local coordinate system is not modified.", py::arg("A"));
cls_gp_Elips2d.def("Area", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::Area, "Computes the area of the ellipse.");
cls_gp_Elips2d.def("Coefficients", [](gp_Elips2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Coefficients(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "Returns the coefficients of the implicit equation of the ellipse. A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_gp_Elips2d.def("Directrix1", (gp_Ax2d (gp_Elips2d::*)() const) &gp_Elips2d::Directrix1, "This directrix is the line normal to the XAxis of the ellipse in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the ellipse, where e is the eccentricity of the ellipse. This line is parallel to the 'YAxis'. The intersection point between directrix1 and the 'XAxis' is the location point of the directrix1. This point is on the positive side of the 'XAxis'.");
cls_gp_Elips2d.def("Directrix2", (gp_Ax2d (gp_Elips2d::*)() const) &gp_Elips2d::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the minor axis of the ellipse.");
cls_gp_Elips2d.def("Eccentricity", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::Eccentricity, "Returns the eccentricity of the ellipse between 0.0 and 1.0 If f is the distance between the center of the ellipse and the Focus1 then the eccentricity e = f / MajorRadius. Returns 0 if MajorRadius = 0.");
cls_gp_Elips2d.def("Focal", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::Focal, "Returns the distance between the center of the ellipse and focus1 or focus2.");
cls_gp_Elips2d.def("Focus1", (gp_Pnt2d (gp_Elips2d::*)() const) &gp_Elips2d::Focus1, "Returns the first focus of the ellipse. This focus is on the positive side of the major axis of the ellipse.");
cls_gp_Elips2d.def("Focus2", (gp_Pnt2d (gp_Elips2d::*)() const) &gp_Elips2d::Focus2, "Returns the second focus of the ellipse. This focus is on the negative side of the major axis of the ellipse.");
cls_gp_Elips2d.def("Location", (const gp_Pnt2d & (gp_Elips2d::*)() const) &gp_Elips2d::Location, "Returns the center of the ellipse.");
cls_gp_Elips2d.def("MajorRadius", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::MajorRadius, "Returns the major radius of the Ellipse.");
cls_gp_Elips2d.def("MinorRadius", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::MinorRadius, "Returns the minor radius of the Ellipse.");
cls_gp_Elips2d.def("Parameter", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::Parameter, "Returns p = (1 - e * e) * MajorRadius where e is the eccentricity of the ellipse. Returns 0 if MajorRadius = 0");
cls_gp_Elips2d.def("Axis", (const gp_Ax22d & (gp_Elips2d::*)() const) &gp_Elips2d::Axis, "Returns the major axis of the ellipse.");
cls_gp_Elips2d.def("XAxis", (gp_Ax2d (gp_Elips2d::*)() const) &gp_Elips2d::XAxis, "Returns the major axis of the ellipse.");
cls_gp_Elips2d.def("YAxis", (gp_Ax2d (gp_Elips2d::*)() const) &gp_Elips2d::YAxis, "Returns the minor axis of the ellipse. Reverses the direction of the circle.");
cls_gp_Elips2d.def("Reverse", (void (gp_Elips2d::*)()) &gp_Elips2d::Reverse, "None");
cls_gp_Elips2d.def("Reversed", (gp_Elips2d (gp_Elips2d::*)() const) &gp_Elips2d::Reversed, "None");
cls_gp_Elips2d.def("IsDirect", (Standard_Boolean (gp_Elips2d::*)() const) &gp_Elips2d::IsDirect, "Returns true if the local coordinate system is direct and false in the other case.");
cls_gp_Elips2d.def("Mirror", (void (gp_Elips2d::*)(const gp_Pnt2d &)) &gp_Elips2d::Mirror, "None", py::arg("P"));
cls_gp_Elips2d.def("Mirrored", (gp_Elips2d (gp_Elips2d::*)(const gp_Pnt2d &) const) &gp_Elips2d::Mirrored, "Performs the symmetrical transformation of a ellipse with respect to the point P which is the center of the symmetry", py::arg("P"));
cls_gp_Elips2d.def("Mirror", (void (gp_Elips2d::*)(const gp_Ax2d &)) &gp_Elips2d::Mirror, "None", py::arg("A"));
cls_gp_Elips2d.def("Mirrored", (gp_Elips2d (gp_Elips2d::*)(const gp_Ax2d &) const) &gp_Elips2d::Mirrored, "Performs the symmetrical transformation of a ellipse with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Elips2d.def("Rotate", (void (gp_Elips2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Elips2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Elips2d.def("Rotated", (gp_Elips2d (gp_Elips2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Elips2d::Rotated, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Elips2d.def("Scale", (void (gp_Elips2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Elips2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Elips2d.def("Scaled", (gp_Elips2d (gp_Elips2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Elips2d::Scaled, "Scales a ellipse. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Elips2d.def("Transform", (void (gp_Elips2d::*)(const gp_Trsf2d &)) &gp_Elips2d::Transform, "None", py::arg("T"));
cls_gp_Elips2d.def("Transformed", (gp_Elips2d (gp_Elips2d::*)(const gp_Trsf2d &) const) &gp_Elips2d::Transformed, "Transforms an ellipse with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Elips2d.def("Translate", (void (gp_Elips2d::*)(const gp_Vec2d &)) &gp_Elips2d::Translate, "None", py::arg("V"));
cls_gp_Elips2d.def("Translated", (gp_Elips2d (gp_Elips2d::*)(const gp_Vec2d &) const) &gp_Elips2d::Translated, "Translates a ellipse in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Elips2d.def("Translate", (void (gp_Elips2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Elips2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Elips2d.def("Translated", (gp_Elips2d (gp_Elips2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Elips2d::Translated, "Translates a ellipse from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_HYPR2D
py::class_<gp_Hypr2d> cls_gp_Hypr2d(mod, "gp_Hypr2d", "Describes a branch of a hyperbola in the plane (2D space). A hyperbola is defined by its major and minor radii, and positioned in the plane with a coordinate system (a gp_Ax22d object) of which: - the origin is the center of the hyperbola, - the 'X Direction' defines the major axis of the hyperbola, and - the 'Y Direction' defines the minor axis of the hyperbola. This coordinate system is the 'local coordinate system' of the hyperbola. The orientation of this coordinate system (direct or indirect) gives an implicit orientation to the hyperbola. In this coordinate system, the equation of the hyperbola is: X*X/(MajorRadius**2)-Y*Y/(MinorRadius**2) = 1.0 The branch of the hyperbola described is the one located on the positive side of the major axis. The following schema shows the plane of the hyperbola, and in it, the respective positions of the three branches of hyperbolas constructed with the functions OtherBranch, ConjugateBranch1, and ConjugateBranch2: ^YAxis | FirstConjugateBranch | Other | Main --------------------- C ------------------------------>XAxis Branch | Branch | | SecondConjugateBranch |");

// Constructors
cls_gp_Hypr2d.def(py::init<>());
cls_gp_Hypr2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gp_Hypr2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
cls_gp_Hypr2d.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Methods
// cls_gp_Hypr2d.def_static("operator new_", (void * (*)(size_t)) &gp_Hypr2d::operator new, "None", py::arg("theSize"));
// cls_gp_Hypr2d.def_static("operator delete_", (void (*)(void *)) &gp_Hypr2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Hypr2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Hypr2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Hypr2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Hypr2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Hypr2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Hypr2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Hypr2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Hypr2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Hypr2d.def("SetLocation", (void (gp_Hypr2d::*)(const gp_Pnt2d &)) &gp_Hypr2d::SetLocation, "Modifies this hyperbola, by redefining its local coordinate system so that its origin becomes P.", py::arg("P"));
cls_gp_Hypr2d.def("SetMajorRadius", (void (gp_Hypr2d::*)(const Standard_Real)) &gp_Hypr2d::SetMajorRadius, "Modifies the major or minor radius of this hyperbola. Exceptions Standard_ConstructionError if MajorRadius or MinorRadius is negative.", py::arg("MajorRadius"));
cls_gp_Hypr2d.def("SetMinorRadius", (void (gp_Hypr2d::*)(const Standard_Real)) &gp_Hypr2d::SetMinorRadius, "Modifies the major or minor radius of this hyperbola. Exceptions Standard_ConstructionError if MajorRadius or MinorRadius is negative.", py::arg("MinorRadius"));
cls_gp_Hypr2d.def("SetAxis", (void (gp_Hypr2d::*)(const gp_Ax22d &)) &gp_Hypr2d::SetAxis, "Modifies this hyperbola, by redefining its local coordinate system so that it becomes A.", py::arg("A"));
cls_gp_Hypr2d.def("SetXAxis", (void (gp_Hypr2d::*)(const gp_Ax2d &)) &gp_Hypr2d::SetXAxis, "Changes the major axis of the hyperbola. The minor axis is recomputed and the location of the hyperbola too.", py::arg("A"));
cls_gp_Hypr2d.def("SetYAxis", (void (gp_Hypr2d::*)(const gp_Ax2d &)) &gp_Hypr2d::SetYAxis, "Changes the minor axis of the hyperbola.The minor axis is recomputed and the location of the hyperbola too.", py::arg("A"));
cls_gp_Hypr2d.def("Asymptote1", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Asymptote1, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = (B/A)*X where A is the major radius of the hyperbola and B the minor radius of the hyperbola. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Hypr2d.def("Asymptote2", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Asymptote2, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = -(B/A)*X where A is the major radius of the hyperbola and B the minor radius of the hyperbola. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Hypr2d.def("Coefficients", [](gp_Hypr2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Coefficients(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "Computes the coefficients of the implicit equation of the hyperbola : A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_gp_Hypr2d.def("ConjugateBranch1", (gp_Hypr2d (gp_Hypr2d::*)() const) &gp_Hypr2d::ConjugateBranch1, "Computes the branch of hyperbola which is on the positive side of the 'YAxis' of <me>.");
cls_gp_Hypr2d.def("ConjugateBranch2", (gp_Hypr2d (gp_Hypr2d::*)() const) &gp_Hypr2d::ConjugateBranch2, "Computes the branch of hyperbola which is on the negative side of the 'YAxis' of <me>.");
cls_gp_Hypr2d.def("Directrix1", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Directrix1, "Computes the directrix which is the line normal to the XAxis of the hyperbola in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the hyperbola, where e is the eccentricity of the hyperbola. This line is parallel to the 'YAxis'. The intersection point between the 'Directrix1' and the 'XAxis' is the 'Location' point of the 'Directrix1'. This point is on the positive side of the 'XAxis'.");
cls_gp_Hypr2d.def("Directrix2", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the 'YAxis' of the hyperbola.");
cls_gp_Hypr2d.def("Eccentricity", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::Eccentricity, "Returns the excentricity of the hyperbola (e > 1). If f is the distance between the location of the hyperbola and the Focus1 then the eccentricity e = f / MajorRadius. Raises DomainError if MajorRadius = 0.0.");
cls_gp_Hypr2d.def("Focal", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::Focal, "Computes the focal distance. It is the distance between the 'Location' of the hyperbola and 'Focus1' or 'Focus2'.");
cls_gp_Hypr2d.def("Focus1", (gp_Pnt2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Focus1, "Returns the first focus of the hyperbola. This focus is on the positive side of the 'XAxis' of the hyperbola.");
cls_gp_Hypr2d.def("Focus2", (gp_Pnt2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Focus2, "Returns the second focus of the hyperbola. This focus is on the negative side of the 'XAxis' of the hyperbola.");
cls_gp_Hypr2d.def("Location", (const gp_Pnt2d & (gp_Hypr2d::*)() const) &gp_Hypr2d::Location, "Returns the location point of the hyperbola. It is the intersection point between the 'XAxis' and the 'YAxis'.");
cls_gp_Hypr2d.def("MajorRadius", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::MajorRadius, "Returns the major radius of the hyperbola (it is the radius corresponding to the 'XAxis' of the hyperbola).");
cls_gp_Hypr2d.def("MinorRadius", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::MinorRadius, "Returns the minor radius of the hyperbola (it is the radius corresponding to the 'YAxis' of the hyperbola).");
cls_gp_Hypr2d.def("OtherBranch", (gp_Hypr2d (gp_Hypr2d::*)() const) &gp_Hypr2d::OtherBranch, "Returns the branch of hyperbola obtained by doing the symmetrical transformation of <me> with respect to the 'YAxis' of <me>.");
cls_gp_Hypr2d.def("Parameter", (Standard_Real (gp_Hypr2d::*)() const) &gp_Hypr2d::Parameter, "Returns p = (e * e - 1) * MajorRadius where e is the eccentricity of the hyperbola. Raises DomainError if MajorRadius = 0.0");
cls_gp_Hypr2d.def("Axis", (const gp_Ax22d & (gp_Hypr2d::*)() const) &gp_Hypr2d::Axis, "Returns the axisplacement of the hyperbola.");
cls_gp_Hypr2d.def("XAxis", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::XAxis, "Computes an axis whose - the origin is the center of this hyperbola, and - the unit vector is the 'X Direction' or 'Y Direction' respectively of the local coordinate system of this hyperbola Returns the major axis of the hyperbola.");
cls_gp_Hypr2d.def("YAxis", (gp_Ax2d (gp_Hypr2d::*)() const) &gp_Hypr2d::YAxis, "Computes an axis whose - the origin is the center of this hyperbola, and - the unit vector is the 'X Direction' or 'Y Direction' respectively of the local coordinate system of this hyperbola Returns the minor axis of the hyperbola.");
cls_gp_Hypr2d.def("Reverse", (void (gp_Hypr2d::*)()) &gp_Hypr2d::Reverse, "None");
cls_gp_Hypr2d.def("Reversed", (gp_Hypr2d (gp_Hypr2d::*)() const) &gp_Hypr2d::Reversed, "Reverses the orientation of the local coordinate system of this hyperbola (the 'Y Axis' is reversed). Therefore, the implicit orientation of this hyperbola is reversed. Note: - Reverse assigns the result to this hyperbola, while - Reversed creates a new one.");
cls_gp_Hypr2d.def("IsDirect", (Standard_Boolean (gp_Hypr2d::*)() const) &gp_Hypr2d::IsDirect, "Returns true if the local coordinate system is direct and false in the other case.");
cls_gp_Hypr2d.def("Mirror", (void (gp_Hypr2d::*)(const gp_Pnt2d &)) &gp_Hypr2d::Mirror, "None", py::arg("P"));
cls_gp_Hypr2d.def("Mirrored", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Pnt2d &) const) &gp_Hypr2d::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Hypr2d.def("Mirror", (void (gp_Hypr2d::*)(const gp_Ax2d &)) &gp_Hypr2d::Mirror, "None", py::arg("A"));
cls_gp_Hypr2d.def("Mirrored", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Ax2d &) const) &gp_Hypr2d::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Hypr2d.def("Rotate", (void (gp_Hypr2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Hypr2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Hypr2d.def("Rotated", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Hypr2d::Rotated, "Rotates an hyperbola. P is the center of the rotation. Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Hypr2d.def("Scale", (void (gp_Hypr2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Hypr2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Hypr2d.def("Scaled", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Hypr2d::Scaled, "Scales an hyperbola. <S> is the scaling value. If <S> is positive only the location point is modified. But if <S> is negative the 'XAxis' is reversed and the 'YAxis' too.", py::arg("P"), py::arg("S"));
cls_gp_Hypr2d.def("Transform", (void (gp_Hypr2d::*)(const gp_Trsf2d &)) &gp_Hypr2d::Transform, "None", py::arg("T"));
cls_gp_Hypr2d.def("Transformed", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Trsf2d &) const) &gp_Hypr2d::Transformed, "Transforms an hyperbola with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Hypr2d.def("Translate", (void (gp_Hypr2d::*)(const gp_Vec2d &)) &gp_Hypr2d::Translate, "None", py::arg("V"));
cls_gp_Hypr2d.def("Translated", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Vec2d &) const) &gp_Hypr2d::Translated, "Translates an hyperbola in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Hypr2d.def("Translate", (void (gp_Hypr2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Hypr2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Hypr2d.def("Translated", (gp_Hypr2d (gp_Hypr2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Hypr2d::Translated, "Translates an hyperbola from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_PARAB2D
py::class_<gp_Parab2d> cls_gp_Parab2d(mod, "gp_Parab2d", "Describes a parabola in the plane (2D space). A parabola is defined by its focal length (that is, the distance between its focus and apex) and positioned in the plane with a coordinate system (a gp_Ax22d object) where: - the origin of the coordinate system is on the apex of the parabola, and - the 'X Axis' of the coordinate system is the axis of symmetry; the parabola is on the positive side of this axis. This coordinate system is the 'local coordinate system' of the parabola. Its orientation (direct or indirect sense) gives an implicit orientation to the parabola. In this coordinate system, the equation for the parabola is: Y**2 = (2*P) * X. where P, referred to as the parameter of the parabola, is the distance between the focus and the directrix (P is twice the focal length). See Also GCE2d_MakeParab2d which provides functions for more complex parabola constructions Geom2d_Parabola which provides additional functions for constructing parabolas and works, in particular, with the parametric equations of parabolas");

// Constructors
cls_gp_Parab2d.def(py::init<>());
cls_gp_Parab2d.def(py::init<const gp_Ax2d &, const Standard_Real>(), py::arg("theMirrorAxis"), py::arg("theFocalLength"));
cls_gp_Parab2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Boolean>(), py::arg("theMirrorAxis"), py::arg("theFocalLength"), py::arg("theSense"));
cls_gp_Parab2d.def(py::init<const gp_Ax22d &, const Standard_Real>(), py::arg("theAxes"), py::arg("theFocalLength"));
cls_gp_Parab2d.def(py::init<const gp_Ax2d &, const gp_Pnt2d &>(), py::arg("theDirectrix"), py::arg("theFocus"));
cls_gp_Parab2d.def(py::init<const gp_Ax2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("theDirectrix"), py::arg("theFocus"), py::arg("theSense"));

// Methods
// cls_gp_Parab2d.def_static("operator new_", (void * (*)(size_t)) &gp_Parab2d::operator new, "None", py::arg("theSize"));
// cls_gp_Parab2d.def_static("operator delete_", (void (*)(void *)) &gp_Parab2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Parab2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Parab2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Parab2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Parab2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Parab2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Parab2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Parab2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Parab2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Parab2d.def("SetFocal", (void (gp_Parab2d::*)(const Standard_Real)) &gp_Parab2d::SetFocal, "Changes the focal distance of the parabola Warnings : It is possible to have Focal = 0. Raises ConstructionError if Focal < 0.0", py::arg("Focal"));
cls_gp_Parab2d.def("SetLocation", (void (gp_Parab2d::*)(const gp_Pnt2d &)) &gp_Parab2d::SetLocation, "Changes the 'Location' point of the parabola. It is the vertex of the parabola.", py::arg("P"));
cls_gp_Parab2d.def("SetMirrorAxis", (void (gp_Parab2d::*)(const gp_Ax2d &)) &gp_Parab2d::SetMirrorAxis, "Modifies this parabola, by redefining its local coordinate system so that its origin and 'X Direction' become those of the axis MA. The 'Y Direction' of the local coordinate system is then recomputed. The orientation of the local coordinate system is not modified.", py::arg("A"));
cls_gp_Parab2d.def("SetAxis", (void (gp_Parab2d::*)(const gp_Ax22d &)) &gp_Parab2d::SetAxis, "Changes the local coordinate system of the parabola. The 'Location' point of A becomes the vertex of the parabola.", py::arg("A"));
cls_gp_Parab2d.def("Coefficients", [](gp_Parab2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Coefficients(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "Computes the coefficients of the implicit equation of the parabola (in WCS - World Coordinate System). A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_gp_Parab2d.def("Directrix", (gp_Ax2d (gp_Parab2d::*)() const) &gp_Parab2d::Directrix, "Computes the directrix of the parabola. The directrix is: - a line parallel to the 'Y Direction' of the local coordinate system of this parabola, and - located on the negative side of the axis of symmetry, at a distance from the apex which is equal to the focal length of this parabola. The directrix is returned as an axis (a gp_Ax2d object), the origin of which is situated on the 'X Axis' of this parabola.");
cls_gp_Parab2d.def("Focal", (Standard_Real (gp_Parab2d::*)() const) &gp_Parab2d::Focal, "Returns the distance between the vertex and the focus of the parabola.");
cls_gp_Parab2d.def("Focus", (gp_Pnt2d (gp_Parab2d::*)() const) &gp_Parab2d::Focus, "Returns the focus of the parabola.");
cls_gp_Parab2d.def("Location", (gp_Pnt2d (gp_Parab2d::*)() const) &gp_Parab2d::Location, "Returns the vertex of the parabola.");
cls_gp_Parab2d.def("MirrorAxis", (gp_Ax2d (gp_Parab2d::*)() const) &gp_Parab2d::MirrorAxis, "Returns the symmetry axis of the parabola. The 'Location' point of this axis is the vertex of the parabola.");
cls_gp_Parab2d.def("Axis", (gp_Ax22d (gp_Parab2d::*)() const) &gp_Parab2d::Axis, "Returns the local coordinate system of the parabola. The 'Location' point of this axis is the vertex of the parabola.");
cls_gp_Parab2d.def("Parameter", (Standard_Real (gp_Parab2d::*)() const) &gp_Parab2d::Parameter, "Returns the distance between the focus and the directrix of the parabola.");
cls_gp_Parab2d.def("Reverse", (void (gp_Parab2d::*)()) &gp_Parab2d::Reverse, "None");
cls_gp_Parab2d.def("Reversed", (gp_Parab2d (gp_Parab2d::*)() const) &gp_Parab2d::Reversed, "Reverses the orientation of the local coordinate system of this parabola (the 'Y Direction' is reversed). Therefore, the implicit orientation of this parabola is reversed. Note: - Reverse assigns the result to this parabola, while - Reversed creates a new one.");
cls_gp_Parab2d.def("IsDirect", (Standard_Boolean (gp_Parab2d::*)() const) &gp_Parab2d::IsDirect, "Returns true if the local coordinate system is direct and false in the other case.");
cls_gp_Parab2d.def("Mirror", (void (gp_Parab2d::*)(const gp_Pnt2d &)) &gp_Parab2d::Mirror, "None", py::arg("P"));
cls_gp_Parab2d.def("Mirrored", (gp_Parab2d (gp_Parab2d::*)(const gp_Pnt2d &) const) &gp_Parab2d::Mirrored, "Performs the symmetrical transformation of a parabola with respect to the point P which is the center of the symmetry", py::arg("P"));
cls_gp_Parab2d.def("Mirror", (void (gp_Parab2d::*)(const gp_Ax2d &)) &gp_Parab2d::Mirror, "None", py::arg("A"));
cls_gp_Parab2d.def("Mirrored", (gp_Parab2d (gp_Parab2d::*)(const gp_Ax2d &) const) &gp_Parab2d::Mirrored, "Performs the symmetrical transformation of a parabola with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Parab2d.def("Rotate", (void (gp_Parab2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Parab2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Parab2d.def("Rotated", (gp_Parab2d (gp_Parab2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Parab2d::Rotated, "Rotates a parabola. P is the center of the rotation. Ang is the angular value of the rotation in radians.", py::arg("P"), py::arg("Ang"));
cls_gp_Parab2d.def("Scale", (void (gp_Parab2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Parab2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Parab2d.def("Scaled", (gp_Parab2d (gp_Parab2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Parab2d::Scaled, "Scales a parabola. S is the scaling value. If S is negative the direction of the symmetry axis 'XAxis' is reversed and the direction of the 'YAxis' too.", py::arg("P"), py::arg("S"));
cls_gp_Parab2d.def("Transform", (void (gp_Parab2d::*)(const gp_Trsf2d &)) &gp_Parab2d::Transform, "None", py::arg("T"));
cls_gp_Parab2d.def("Transformed", (gp_Parab2d (gp_Parab2d::*)(const gp_Trsf2d &) const) &gp_Parab2d::Transformed, "Transforms an parabola with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Parab2d.def("Translate", (void (gp_Parab2d::*)(const gp_Vec2d &)) &gp_Parab2d::Translate, "None", py::arg("V"));
cls_gp_Parab2d.def("Translated", (gp_Parab2d (gp_Parab2d::*)(const gp_Vec2d &) const) &gp_Parab2d::Translated, "Translates a parabola in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Parab2d.def("Translate", (void (gp_Parab2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Parab2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Parab2d.def("Translated", (gp_Parab2d (gp_Parab2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Parab2d::Translated, "Translates a parabola from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_AX1
py::class_<gp_Ax1> cls_gp_Ax1(mod, "gp_Ax1", "Describes an axis in 3D space. An axis is defined by: - its origin (also referred to as its 'Location point'), and - its unit vector (referred to as its 'Direction' or 'main Direction'). An axis is used: - to describe 3D geometric entities (for example, the axis of a revolution entity). It serves the same purpose as the STEP function 'axis placement one axis', or - to define geometric transformations (axis of symmetry, axis of rotation, and so on). For example, this entity can be used to locate a geometric entity or to define a symmetry axis.");

// Constructors
cls_gp_Ax1.def(py::init<>());
cls_gp_Ax1.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

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

// CLASS: GP_AX2
py::class_<gp_Ax2> cls_gp_Ax2(mod, "gp_Ax2", "Describes a right-handed coordinate system in 3D space. A coordinate system is defined by: - its origin (also referred to as its 'Location point'), and - three orthogonal unit vectors, termed respectively the 'X Direction', the 'Y Direction' and the 'Direction' (also referred to as the 'main Direction'). The 'Direction' of the coordinate system is called its 'main Direction' because whenever this unit vector is modified, the 'X Direction' and the 'Y Direction' are recomputed. However, when we modify either the 'X Direction' or the 'Y Direction', 'Direction' is not modified. The 'main Direction' is also the 'Z Direction'. Since an Ax2 coordinate system is right-handed, its 'main Direction' is always equal to the cross product of its 'X Direction' and 'Y Direction'. (To define a left-handed coordinate system, use gp_Ax3.) A coordinate system is used: - to describe geometric entities, in particular to position them. The local coordinate system of a geometric entity serves the same purpose as the STEP function 'axis placement two axes', or - to define geometric transformations. Note: we refer to the 'X Axis', 'Y Axis' and 'Z Axis', respectively, as to axes having: - the origin of the coordinate system as their origin, and - the unit vectors 'X Direction', 'Y Direction' and 'main Direction', respectively, as their unit vectors. The 'Z Axis' is also the 'main Axis'.");

// Constructors
cls_gp_Ax2.def(py::init<>());
cls_gp_Ax2.def(py::init<const gp_Pnt &, const gp_Dir &, const gp_Dir &>(), py::arg("P"), py::arg("N"), py::arg("Vx"));
cls_gp_Ax2.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

// Methods
// cls_gp_Ax2.def_static("operator new_", (void * (*)(size_t)) &gp_Ax2::operator new, "None", py::arg("theSize"));
// cls_gp_Ax2.def_static("operator delete_", (void (*)(void *)) &gp_Ax2::operator delete, "None", py::arg("theAddress"));
// cls_gp_Ax2.def_static("operator new[]_", (void * (*)(size_t)) &gp_Ax2::operator new[], "None", py::arg("theSize"));
// cls_gp_Ax2.def_static("operator delete[]_", (void (*)(void *)) &gp_Ax2::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Ax2.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Ax2::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Ax2.def_static("operator delete_", (void (*)(void *, void *)) &gp_Ax2::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Ax2.def("SetAxis", (void (gp_Ax2::*)(const gp_Ax1 &)) &gp_Ax2::SetAxis, "Assigns the origin and 'main Direction' of the axis A1 to this coordinate system, then recomputes its 'X Direction' and 'Y Direction'. Note: The new 'X Direction' is computed as follows: new 'X Direction' = V1 ^(previous 'X Direction' ^ V) where V is the 'Direction' of A1. Exceptions Standard_ConstructionError if A1 is parallel to the 'X Direction' of this coordinate system.", py::arg("A1"));
cls_gp_Ax2.def("SetDirection", (void (gp_Ax2::*)(const gp_Dir &)) &gp_Ax2::SetDirection, "Changes the 'main Direction' of this coordinate system, then recomputes its 'X Direction' and 'Y Direction'. Note: the new 'X Direction' is computed as follows: new 'X Direction' = V ^ (previous 'X Direction' ^ V) Exceptions Standard_ConstructionError if V is parallel to the 'X Direction' of this coordinate system.", py::arg("V"));
cls_gp_Ax2.def("SetLocation", (void (gp_Ax2::*)(const gp_Pnt &)) &gp_Ax2::SetLocation, "Changes the 'Location' point (origin) of <me>.", py::arg("P"));
cls_gp_Ax2.def("SetXDirection", (void (gp_Ax2::*)(const gp_Dir &)) &gp_Ax2::SetXDirection, "Changes the 'Xdirection' of <me>. The main direction 'Direction' is not modified, the 'Ydirection' is modified. If <Vx> is not normal to the main direction then <XDirection> is computed as follows XDirection = Direction ^ (Vx ^ Direction). Exceptions Standard_ConstructionError if Vx or Vy is parallel to the 'main Direction' of this coordinate system.", py::arg("Vx"));
cls_gp_Ax2.def("SetYDirection", (void (gp_Ax2::*)(const gp_Dir &)) &gp_Ax2::SetYDirection, "Changes the 'Ydirection' of <me>. The main direction is not modified but the 'Xdirection' is changed. If <Vy> is not normal to the main direction then 'YDirection' is computed as follows YDirection = Direction ^ (<Vy> ^ Direction). Exceptions Standard_ConstructionError if Vx or Vy is parallel to the 'main Direction' of this coordinate system.", py::arg("Vy"));
cls_gp_Ax2.def("Angle", (Standard_Real (gp_Ax2::*)(const gp_Ax2 &) const) &gp_Ax2::Angle, "Computes the angular value, in radians, between the main direction of <me> and the main direction of <Other>. Returns the angle between 0 and PI in radians.", py::arg("Other"));
cls_gp_Ax2.def("Axis", (const gp_Ax1 & (gp_Ax2::*)() const) &gp_Ax2::Axis, "Returns the main axis of <me>. It is the 'Location' point and the main 'Direction'.");
cls_gp_Ax2.def("Direction", (const gp_Dir & (gp_Ax2::*)() const) &gp_Ax2::Direction, "Returns the main direction of <me>.");
cls_gp_Ax2.def("Location", (const gp_Pnt & (gp_Ax2::*)() const) &gp_Ax2::Location, "Returns the 'Location' point (origin) of <me>.");
cls_gp_Ax2.def("XDirection", (const gp_Dir & (gp_Ax2::*)() const) &gp_Ax2::XDirection, "Returns the 'XDirection' of <me>.");
cls_gp_Ax2.def("YDirection", (const gp_Dir & (gp_Ax2::*)() const) &gp_Ax2::YDirection, "Returns the 'YDirection' of <me>.");
cls_gp_Ax2.def("IsCoplanar", (Standard_Boolean (gp_Ax2::*)(const gp_Ax2 &, const Standard_Real, const Standard_Real) const) &gp_Ax2::IsCoplanar, "None", py::arg("Other"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Ax2.def("IsCoplanar", (Standard_Boolean (gp_Ax2::*)(const gp_Ax1 &, const Standard_Real, const Standard_Real) const) &gp_Ax2::IsCoplanar, "Returns True if . the distance between <me> and the 'Location' point of A1 is lower of equal to LinearTolerance and . the main direction of <me> and the direction of A1 are normal. Note: the tolerance criterion for angular equality is given by AngularTolerance.", py::arg("A1"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Ax2.def("Mirror", (void (gp_Ax2::*)(const gp_Pnt &)) &gp_Ax2::Mirror, "Performs a symmetrical transformation of this coordinate system with respect to: - the point P, and assigns the result to this coordinate system. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("P"));
cls_gp_Ax2.def("Mirrored", (gp_Ax2 (gp_Ax2::*)(const gp_Pnt &) const) &gp_Ax2::Mirrored, "Performs a symmetrical transformation of this coordinate system with respect to: - the point P, and creates a new one. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("P"));
cls_gp_Ax2.def("Mirror", (void (gp_Ax2::*)(const gp_Ax1 &)) &gp_Ax2::Mirror, "Performs a symmetrical transformation of this coordinate system with respect to: - the axis A1, and assigns the result to this coordinate systeme. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("A1"));
cls_gp_Ax2.def("Mirrored", (gp_Ax2 (gp_Ax2::*)(const gp_Ax1 &) const) &gp_Ax2::Mirrored, "Performs a symmetrical transformation of this coordinate system with respect to: - the axis A1, and creates a new one. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("A1"));
cls_gp_Ax2.def("Mirror", (void (gp_Ax2::*)(const gp_Ax2 &)) &gp_Ax2::Mirror, "Performs a symmetrical transformation of this coordinate system with respect to: - the plane defined by the origin, 'X Direction' and 'Y Direction' of coordinate system A2 and assigns the result to this coordinate systeme. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("A2"));
cls_gp_Ax2.def("Mirrored", (gp_Ax2 (gp_Ax2::*)(const gp_Ax2 &) const) &gp_Ax2::Mirrored, "Performs a symmetrical transformation of this coordinate system with respect to: - the plane defined by the origin, 'X Direction' and 'Y Direction' of coordinate system A2 and creates a new one. Warning This transformation is always performed on the origin. In case of a reflection with respect to a point: - the main direction of the coordinate system is not changed, and - the 'X Direction' and the 'Y Direction' are simply reversed In case of a reflection with respect to an axis or a plane: - the transformation is applied to the 'X Direction' and the 'Y Direction', then - the 'main Direction' is recomputed as the cross product 'X Direction' ^ 'Y Direction'. This maintains the right-handed property of the coordinate system.", py::arg("A2"));
cls_gp_Ax2.def("Rotate", (void (gp_Ax2::*)(const gp_Ax1 &, const Standard_Real)) &gp_Ax2::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax2.def("Rotated", (gp_Ax2 (gp_Ax2::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Ax2::Rotated, "Rotates an axis placement. <A1> is the axis of the rotation . Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax2.def("Scale", (void (gp_Ax2::*)(const gp_Pnt &, const Standard_Real)) &gp_Ax2::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Ax2.def("Scaled", (gp_Ax2 (gp_Ax2::*)(const gp_Pnt &, const Standard_Real) const) &gp_Ax2::Scaled, "Applies a scaling transformation on the axis placement. The 'Location' point of the axisplacement is modified. Warnings : If the scale <S> is negative : . the main direction of the axis placement is not changed. . The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"), py::arg("S"));
cls_gp_Ax2.def("Transform", (void (gp_Ax2::*)(const gp_Trsf &)) &gp_Ax2::Transform, "None", py::arg("T"));
cls_gp_Ax2.def("Transformed", (gp_Ax2 (gp_Ax2::*)(const gp_Trsf &) const) &gp_Ax2::Transformed, "Transforms an axis placement with a Trsf. The 'Location' point, the 'XDirection' and the 'YDirection' are transformed with T. The resulting main 'Direction' of <me> is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("T"));
cls_gp_Ax2.def("Translate", (void (gp_Ax2::*)(const gp_Vec &)) &gp_Ax2::Translate, "None", py::arg("V"));
cls_gp_Ax2.def("Translated", (gp_Ax2 (gp_Ax2::*)(const gp_Vec &) const) &gp_Ax2::Translated, "Translates an axis plaxement in the direction of the vector <V>. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Ax2.def("Translate", (void (gp_Ax2::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Ax2::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Ax2.def("Translated", (gp_Ax2 (gp_Ax2::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Ax2::Translated, "Translates an axis placement from the point <P1> to the point <P2>.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_CIRC
py::class_<gp_Circ> cls_gp_Circ(mod, "gp_Circ", "Describes a circle in 3D space. A circle is defined by its radius and positioned in space with a coordinate system (a gp_Ax2 object) as follows: - the origin of the coordinate system is the center of the circle, and - the origin, 'X Direction' and 'Y Direction' of the coordinate system define the plane of the circle. This positioning coordinate system is the 'local coordinate system' of the circle. Its 'main Direction' gives the normal vector to the plane of the circle. The 'main Axis' of the coordinate system is referred to as the 'Axis' of the circle. Note: when a gp_Circ circle is converted into a Geom_Circle circle, some implicit properties of the circle are used explicitly: - the 'main Direction' of the local coordinate system gives an implicit orientation to the circle (and defines its trigonometric sense), - this orientation corresponds to the direction in which parameter values increase, - the starting point for parameterization is that of the 'X Axis' of the local coordinate system (i.e. the 'X Axis' of the circle). See Also gce_MakeCirc which provides functions for more complex circle constructions Geom_Circle which provides additional functions for constructing circles and works, in particular, with the parametric equations of circles");

// Constructors
cls_gp_Circ.def(py::init<>());
cls_gp_Circ.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));

// Methods
// cls_gp_Circ.def_static("operator new_", (void * (*)(size_t)) &gp_Circ::operator new, "None", py::arg("theSize"));
// cls_gp_Circ.def_static("operator delete_", (void (*)(void *)) &gp_Circ::operator delete, "None", py::arg("theAddress"));
// cls_gp_Circ.def_static("operator new[]_", (void * (*)(size_t)) &gp_Circ::operator new[], "None", py::arg("theSize"));
// cls_gp_Circ.def_static("operator delete[]_", (void (*)(void *)) &gp_Circ::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Circ.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Circ::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Circ.def_static("operator delete_", (void (*)(void *, void *)) &gp_Circ::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Circ.def("SetAxis", (void (gp_Circ::*)(const gp_Ax1 &)) &gp_Circ::SetAxis, "Changes the main axis of the circle. It is the axis perpendicular to the plane of the circle. Raises ConstructionError if the direction of A1 is parallel to the 'XAxis' of the circle.", py::arg("A1"));
cls_gp_Circ.def("SetLocation", (void (gp_Circ::*)(const gp_Pnt &)) &gp_Circ::SetLocation, "Changes the 'Location' point (center) of the circle.", py::arg("P"));
cls_gp_Circ.def("SetPosition", (void (gp_Circ::*)(const gp_Ax2 &)) &gp_Circ::SetPosition, "Changes the position of the circle.", py::arg("A2"));
cls_gp_Circ.def("SetRadius", (void (gp_Circ::*)(const Standard_Real)) &gp_Circ::SetRadius, "Modifies the radius of this circle. Warning. This class does not prevent the creation of a circle where Radius is null. Exceptions Standard_ConstructionError if Radius is negative.", py::arg("Radius"));
cls_gp_Circ.def("Area", (Standard_Real (gp_Circ::*)() const) &gp_Circ::Area, "Computes the area of the circle.");
cls_gp_Circ.def("Axis", (const gp_Ax1 & (gp_Circ::*)() const) &gp_Circ::Axis, "Returns the main axis of the circle. It is the axis perpendicular to the plane of the circle, passing through the 'Location' point (center) of the circle.");
cls_gp_Circ.def("Length", (Standard_Real (gp_Circ::*)() const) &gp_Circ::Length, "Computes the circumference of the circle.");
cls_gp_Circ.def("Location", (const gp_Pnt & (gp_Circ::*)() const) &gp_Circ::Location, "Returns the center of the circle. It is the 'Location' point of the local coordinate system of the circle");
cls_gp_Circ.def("Position", (const gp_Ax2 & (gp_Circ::*)() const) &gp_Circ::Position, "Returns the position of the circle. It is the local coordinate system of the circle.");
cls_gp_Circ.def("Radius", (Standard_Real (gp_Circ::*)() const) &gp_Circ::Radius, "Returns the radius of this circle.");
cls_gp_Circ.def("XAxis", (gp_Ax1 (gp_Circ::*)() const) &gp_Circ::XAxis, "Returns the 'XAxis' of the circle. This axis is perpendicular to the axis of the conic. This axis and the 'Yaxis' define the plane of the conic.");
cls_gp_Circ.def("YAxis", (gp_Ax1 (gp_Circ::*)() const) &gp_Circ::YAxis, "Returns the 'YAxis' of the circle. This axis and the 'Xaxis' define the plane of the conic. The 'YAxis' is perpendicular to the 'Xaxis'.");
cls_gp_Circ.def("Distance", (Standard_Real (gp_Circ::*)(const gp_Pnt &) const) &gp_Circ::Distance, "Computes the minimum of distance between the point P and any point on the circumference of the circle.", py::arg("P"));
cls_gp_Circ.def("SquareDistance", (Standard_Real (gp_Circ::*)(const gp_Pnt &) const) &gp_Circ::SquareDistance, "Computes the square distance between <me> and the point P.", py::arg("P"));
cls_gp_Circ.def("Contains", (Standard_Boolean (gp_Circ::*)(const gp_Pnt &, const Standard_Real) const) &gp_Circ::Contains, "Returns True if the point P is on the circumference. The distance between <me> and <P> must be lower or equal to LinearTolerance.", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Circ.def("Mirror", (void (gp_Circ::*)(const gp_Pnt &)) &gp_Circ::Mirror, "None", py::arg("P"));
cls_gp_Circ.def("Mirrored", (gp_Circ (gp_Circ::*)(const gp_Pnt &) const) &gp_Circ::Mirrored, "Performs the symmetrical transformation of a circle with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Circ.def("Mirror", (void (gp_Circ::*)(const gp_Ax1 &)) &gp_Circ::Mirror, "None", py::arg("A1"));
cls_gp_Circ.def("Mirrored", (gp_Circ (gp_Circ::*)(const gp_Ax1 &) const) &gp_Circ::Mirrored, "Performs the symmetrical transformation of a circle with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Circ.def("Mirror", (void (gp_Circ::*)(const gp_Ax2 &)) &gp_Circ::Mirror, "None", py::arg("A2"));
cls_gp_Circ.def("Mirrored", (gp_Circ (gp_Circ::*)(const gp_Ax2 &) const) &gp_Circ::Mirrored, "Performs the symmetrical transformation of a circle with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Circ.def("Rotate", (void (gp_Circ::*)(const gp_Ax1 &, const Standard_Real)) &gp_Circ::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Circ.def("Rotated", (gp_Circ (gp_Circ::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Circ::Rotated, "Rotates a circle. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Circ.def("Scale", (void (gp_Circ::*)(const gp_Pnt &, const Standard_Real)) &gp_Circ::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Circ.def("Scaled", (gp_Circ (gp_Circ::*)(const gp_Pnt &, const Standard_Real) const) &gp_Circ::Scaled, "Scales a circle. S is the scaling value. Warnings : If S is negative the radius stay positive but the 'XAxis' and the 'YAxis' are reversed as for an ellipse.", py::arg("P"), py::arg("S"));
cls_gp_Circ.def("Transform", (void (gp_Circ::*)(const gp_Trsf &)) &gp_Circ::Transform, "None", py::arg("T"));
cls_gp_Circ.def("Transformed", (gp_Circ (gp_Circ::*)(const gp_Trsf &) const) &gp_Circ::Transformed, "Transforms a circle with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Circ.def("Translate", (void (gp_Circ::*)(const gp_Vec &)) &gp_Circ::Translate, "None", py::arg("V"));
cls_gp_Circ.def("Translated", (gp_Circ (gp_Circ::*)(const gp_Vec &) const) &gp_Circ::Translated, "Translates a circle in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Circ.def("Translate", (void (gp_Circ::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Circ::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Circ.def("Translated", (gp_Circ (gp_Circ::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Circ::Translated, "Translates a circle from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_LIN
py::class_<gp_Lin> cls_gp_Lin(mod, "gp_Lin", "Describes a line in 3D space. A line is positioned in space with an axis (a gp_Ax1 object) which gives it an origin and a unit vector. A line and an axis are similar objects, thus, we can convert one into the other. A line provides direct access to the majority of the edit and query functions available on its positioning axis. In addition, however, a line has specific functions for computing distances and positions. See Also gce_MakeLin which provides functions for more complex line constructions Geom_Line which provides additional functions for constructing lines and works, in particular, with the parametric equations of lines");

// Constructors
cls_gp_Lin.def(py::init<>());
cls_gp_Lin.def(py::init<const gp_Ax1 &>(), py::arg("A1"));
cls_gp_Lin.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

// Methods
// cls_gp_Lin.def_static("operator new_", (void * (*)(size_t)) &gp_Lin::operator new, "None", py::arg("theSize"));
// cls_gp_Lin.def_static("operator delete_", (void (*)(void *)) &gp_Lin::operator delete, "None", py::arg("theAddress"));
// cls_gp_Lin.def_static("operator new[]_", (void * (*)(size_t)) &gp_Lin::operator new[], "None", py::arg("theSize"));
// cls_gp_Lin.def_static("operator delete[]_", (void (*)(void *)) &gp_Lin::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Lin.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Lin::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Lin.def_static("operator delete_", (void (*)(void *, void *)) &gp_Lin::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Lin.def("Reverse", (void (gp_Lin::*)()) &gp_Lin::Reverse, "None");
cls_gp_Lin.def("Reversed", (gp_Lin (gp_Lin::*)() const) &gp_Lin::Reversed, "Reverses the direction of the line. Note: - Reverse assigns the result to this line, while - Reversed creates a new one.");
cls_gp_Lin.def("SetDirection", (void (gp_Lin::*)(const gp_Dir &)) &gp_Lin::SetDirection, "Changes the direction of the line.", py::arg("V"));
cls_gp_Lin.def("SetLocation", (void (gp_Lin::*)(const gp_Pnt &)) &gp_Lin::SetLocation, "Changes the location point (origin) of the line.", py::arg("P"));
cls_gp_Lin.def("SetPosition", (void (gp_Lin::*)(const gp_Ax1 &)) &gp_Lin::SetPosition, "Complete redefinition of the line. The 'Location' point of <A1> is the origin of the line. The 'Direction' of <A1> is the direction of the line.", py::arg("A1"));
cls_gp_Lin.def("Direction", (const gp_Dir & (gp_Lin::*)() const) &gp_Lin::Direction, "Returns the direction of the line.");
cls_gp_Lin.def("Location", (const gp_Pnt & (gp_Lin::*)() const) &gp_Lin::Location, "Returns the location point (origin) of the line.");
cls_gp_Lin.def("Position", (const gp_Ax1 & (gp_Lin::*)() const) &gp_Lin::Position, "Returns the axis placement one axis whith the same location and direction as <me>.");
cls_gp_Lin.def("Angle", (Standard_Real (gp_Lin::*)(const gp_Lin &) const) &gp_Lin::Angle, "Computes the angle between two lines in radians.", py::arg("Other"));
cls_gp_Lin.def("Contains", (Standard_Boolean (gp_Lin::*)(const gp_Pnt &, const Standard_Real) const) &gp_Lin::Contains, "Returns true if this line contains the point P, that is, if the distance between point P and this line is less than or equal to LinearTolerance..", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Lin.def("Distance", (Standard_Real (gp_Lin::*)(const gp_Pnt &) const) &gp_Lin::Distance, "Computes the distance between <me> and the point P.", py::arg("P"));
cls_gp_Lin.def("Distance", (Standard_Real (gp_Lin::*)(const gp_Lin &) const) &gp_Lin::Distance, "Computes the distance between two lines.", py::arg("Other"));
cls_gp_Lin.def("SquareDistance", (Standard_Real (gp_Lin::*)(const gp_Pnt &) const) &gp_Lin::SquareDistance, "Computes the square distance between <me> and the point P.", py::arg("P"));
cls_gp_Lin.def("SquareDistance", (Standard_Real (gp_Lin::*)(const gp_Lin &) const) &gp_Lin::SquareDistance, "Computes the square distance between two lines.", py::arg("Other"));
cls_gp_Lin.def("Normal", (gp_Lin (gp_Lin::*)(const gp_Pnt &) const) &gp_Lin::Normal, "Computes the line normal to the direction of <me>, passing through the point P. Raises ConstructionError if the distance between <me> and the point P is lower or equal to Resolution from gp because there is an infinity of solutions in 3D space.", py::arg("P"));
cls_gp_Lin.def("Mirror", (void (gp_Lin::*)(const gp_Pnt &)) &gp_Lin::Mirror, "None", py::arg("P"));
cls_gp_Lin.def("Mirrored", (gp_Lin (gp_Lin::*)(const gp_Pnt &) const) &gp_Lin::Mirrored, "Performs the symmetrical transformation of a line with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Lin.def("Mirror", (void (gp_Lin::*)(const gp_Ax1 &)) &gp_Lin::Mirror, "None", py::arg("A1"));
cls_gp_Lin.def("Mirrored", (gp_Lin (gp_Lin::*)(const gp_Ax1 &) const) &gp_Lin::Mirrored, "Performs the symmetrical transformation of a line with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Lin.def("Mirror", (void (gp_Lin::*)(const gp_Ax2 &)) &gp_Lin::Mirror, "None", py::arg("A2"));
cls_gp_Lin.def("Mirrored", (gp_Lin (gp_Lin::*)(const gp_Ax2 &) const) &gp_Lin::Mirrored, "Performs the symmetrical transformation of a line with respect to a plane. The axis placement <A2> locates the plane of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Lin.def("Rotate", (void (gp_Lin::*)(const gp_Ax1 &, const Standard_Real)) &gp_Lin::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Lin.def("Rotated", (gp_Lin (gp_Lin::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Lin::Rotated, "Rotates a line. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Lin.def("Scale", (void (gp_Lin::*)(const gp_Pnt &, const Standard_Real)) &gp_Lin::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Lin.def("Scaled", (gp_Lin (gp_Lin::*)(const gp_Pnt &, const Standard_Real) const) &gp_Lin::Scaled, "Scales a line. S is the scaling value. The 'Location' point (origin) of the line is modified. The 'Direction' is reversed if the scale is negative.", py::arg("P"), py::arg("S"));
cls_gp_Lin.def("Transform", (void (gp_Lin::*)(const gp_Trsf &)) &gp_Lin::Transform, "None", py::arg("T"));
cls_gp_Lin.def("Transformed", (gp_Lin (gp_Lin::*)(const gp_Trsf &) const) &gp_Lin::Transformed, "Transforms a line with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Lin.def("Translate", (void (gp_Lin::*)(const gp_Vec &)) &gp_Lin::Translate, "None", py::arg("V"));
cls_gp_Lin.def("Translated", (gp_Lin (gp_Lin::*)(const gp_Vec &) const) &gp_Lin::Translated, "Translates a line in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Lin.def("Translate", (void (gp_Lin::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Lin::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Lin.def("Translated", (gp_Lin (gp_Lin::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Lin::Translated, "Translates a line from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_ELIPS
py::class_<gp_Elips> cls_gp_Elips(mod, "gp_Elips", "Describes an ellipse in 3D space. An ellipse is defined by its major and minor radii and positioned in space with a coordinate system (a gp_Ax2 object) as follows: - the origin of the coordinate system is the center of the ellipse, - its 'X Direction' defines the major axis of the ellipse, and - its 'Y Direction' defines the minor axis of the ellipse. Together, the origin, 'X Direction' and 'Y Direction' of this coordinate system define the plane of the ellipse. This coordinate system is the 'local coordinate system' of the ellipse. In this coordinate system, the equation of the ellipse is: X*X / (MajorRadius**2) + Y*Y / (MinorRadius**2) = 1.0 The 'main Direction' of the local coordinate system gives the normal vector to the plane of the ellipse. This vector gives an implicit orientation to the ellipse (definition of the trigonometric sense). We refer to the 'main Axis' of the local coordinate system as the 'Axis' of the ellipse. See Also gce_MakeElips which provides functions for more complex ellipse constructions Geom_Ellipse which provides additional functions for constructing ellipses and works, in particular, with the parametric equations of ellipses");

// Constructors
cls_gp_Elips.def(py::init<>());
cls_gp_Elips.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Methods
// cls_gp_Elips.def_static("operator new_", (void * (*)(size_t)) &gp_Elips::operator new, "None", py::arg("theSize"));
// cls_gp_Elips.def_static("operator delete_", (void (*)(void *)) &gp_Elips::operator delete, "None", py::arg("theAddress"));
// cls_gp_Elips.def_static("operator new[]_", (void * (*)(size_t)) &gp_Elips::operator new[], "None", py::arg("theSize"));
// cls_gp_Elips.def_static("operator delete[]_", (void (*)(void *)) &gp_Elips::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Elips.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Elips::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Elips.def_static("operator delete_", (void (*)(void *, void *)) &gp_Elips::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Elips.def("SetAxis", (void (gp_Elips::*)(const gp_Ax1 &)) &gp_Elips::SetAxis, "Changes the axis normal to the plane of the ellipse. It modifies the definition of this plane. The 'XAxis' and the 'YAxis' are recomputed. The local coordinate system is redefined so that: - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed in the same way as for any gp_Ax2), or Raises ConstructionError if the direction of A1 is parallel to the direction of the 'XAxis' of the ellipse.", py::arg("A1"));
cls_gp_Elips.def("SetLocation", (void (gp_Elips::*)(const gp_Pnt &)) &gp_Elips::SetLocation, "Modifies this ellipse, by redefining its local coordinate so that its origin becomes P.", py::arg("P"));
cls_gp_Elips.def("SetMajorRadius", (void (gp_Elips::*)(const Standard_Real)) &gp_Elips::SetMajorRadius, "The major radius of the ellipse is on the 'XAxis' (major axis) of the ellipse. Raises ConstructionError if MajorRadius < MinorRadius.", py::arg("MajorRadius"));
cls_gp_Elips.def("SetMinorRadius", (void (gp_Elips::*)(const Standard_Real)) &gp_Elips::SetMinorRadius, "The minor radius of the ellipse is on the 'YAxis' (minor axis) of the ellipse. Raises ConstructionError if MinorRadius > MajorRadius or MinorRadius < 0.", py::arg("MinorRadius"));
cls_gp_Elips.def("SetPosition", (void (gp_Elips::*)(const gp_Ax2 &)) &gp_Elips::SetPosition, "Modifies this ellipse, by redefining its local coordinate so that it becomes A2e.", py::arg("A2"));
cls_gp_Elips.def("Area", (Standard_Real (gp_Elips::*)() const) &gp_Elips::Area, "Computes the area of the Ellipse.");
cls_gp_Elips.def("Axis", (const gp_Ax1 & (gp_Elips::*)() const) &gp_Elips::Axis, "Computes the axis normal to the plane of the ellipse.");
cls_gp_Elips.def("Directrix1", (gp_Ax1 (gp_Elips::*)() const) &gp_Elips::Directrix1, "Computes the first or second directrix of this ellipse. These are the lines, in the plane of the ellipse, normal to the major axis, at a distance equal to MajorRadius/e from the center of the ellipse, where e is the eccentricity of the ellipse. The first directrix (Directrix1) is on the positive side of the major axis. The second directrix (Directrix2) is on the negative side. The directrix is returned as an axis (gp_Ax1 object), the origin of which is situated on the 'X Axis' of the local coordinate system of this ellipse. Exceptions Standard_ConstructionError if the eccentricity is null (the ellipse has degenerated into a circle).");
cls_gp_Elips.def("Directrix2", (gp_Ax1 (gp_Elips::*)() const) &gp_Elips::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the 'YAxis' of the ellipse. Exceptions Standard_ConstructionError if the eccentricity is null (the ellipse has degenerated into a circle).");
cls_gp_Elips.def("Eccentricity", (Standard_Real (gp_Elips::*)() const) &gp_Elips::Eccentricity, "Returns the eccentricity of the ellipse between 0.0 and 1.0 If f is the distance between the center of the ellipse and the Focus1 then the eccentricity e = f / MajorRadius. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Elips.def("Focal", (Standard_Real (gp_Elips::*)() const) &gp_Elips::Focal, "Computes the focal distance. It is the distance between the two focus focus1 and focus2 of the ellipse.");
cls_gp_Elips.def("Focus1", (gp_Pnt (gp_Elips::*)() const) &gp_Elips::Focus1, "Returns the first focus of the ellipse. This focus is on the positive side of the 'XAxis' of the ellipse.");
cls_gp_Elips.def("Focus2", (gp_Pnt (gp_Elips::*)() const) &gp_Elips::Focus2, "Returns the second focus of the ellipse. This focus is on the negative side of the 'XAxis' of the ellipse.");
cls_gp_Elips.def("Location", (const gp_Pnt & (gp_Elips::*)() const) &gp_Elips::Location, "Returns the center of the ellipse. It is the 'Location' point of the coordinate system of the ellipse.");
cls_gp_Elips.def("MajorRadius", (Standard_Real (gp_Elips::*)() const) &gp_Elips::MajorRadius, "Returns the major radius of the ellipse.");
cls_gp_Elips.def("MinorRadius", (Standard_Real (gp_Elips::*)() const) &gp_Elips::MinorRadius, "Returns the minor radius of the ellipse.");
cls_gp_Elips.def("Parameter", (Standard_Real (gp_Elips::*)() const) &gp_Elips::Parameter, "Returns p = (1 - e * e) * MajorRadius where e is the eccentricity of the ellipse. Returns 0 if MajorRadius = 0");
cls_gp_Elips.def("Position", (const gp_Ax2 & (gp_Elips::*)() const) &gp_Elips::Position, "Returns the coordinate system of the ellipse.");
cls_gp_Elips.def("XAxis", (gp_Ax1 (gp_Elips::*)() const) &gp_Elips::XAxis, "Returns the 'XAxis' of the ellipse whose origin is the center of this ellipse. It is the major axis of the ellipse.");
cls_gp_Elips.def("YAxis", (gp_Ax1 (gp_Elips::*)() const) &gp_Elips::YAxis, "Returns the 'YAxis' of the ellipse whose unit vector is the 'X Direction' or the 'Y Direction' of the local coordinate system of this ellipse. This is the minor axis of the ellipse.");
cls_gp_Elips.def("Mirror", (void (gp_Elips::*)(const gp_Pnt &)) &gp_Elips::Mirror, "None", py::arg("P"));
cls_gp_Elips.def("Mirrored", (gp_Elips (gp_Elips::*)(const gp_Pnt &) const) &gp_Elips::Mirrored, "Performs the symmetrical transformation of an ellipse with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Elips.def("Mirror", (void (gp_Elips::*)(const gp_Ax1 &)) &gp_Elips::Mirror, "None", py::arg("A1"));
cls_gp_Elips.def("Mirrored", (gp_Elips (gp_Elips::*)(const gp_Ax1 &) const) &gp_Elips::Mirrored, "Performs the symmetrical transformation of an ellipse with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Elips.def("Mirror", (void (gp_Elips::*)(const gp_Ax2 &)) &gp_Elips::Mirror, "None", py::arg("A2"));
cls_gp_Elips.def("Mirrored", (gp_Elips (gp_Elips::*)(const gp_Ax2 &) const) &gp_Elips::Mirrored, "Performs the symmetrical transformation of an ellipse with respect to a plane. The axis placement A2 locates the plane of the symmetry (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Elips.def("Rotate", (void (gp_Elips::*)(const gp_Ax1 &, const Standard_Real)) &gp_Elips::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Elips.def("Rotated", (gp_Elips (gp_Elips::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Elips::Rotated, "Rotates an ellipse. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Elips.def("Scale", (void (gp_Elips::*)(const gp_Pnt &, const Standard_Real)) &gp_Elips::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Elips.def("Scaled", (gp_Elips (gp_Elips::*)(const gp_Pnt &, const Standard_Real) const) &gp_Elips::Scaled, "Scales an ellipse. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Elips.def("Transform", (void (gp_Elips::*)(const gp_Trsf &)) &gp_Elips::Transform, "None", py::arg("T"));
cls_gp_Elips.def("Transformed", (gp_Elips (gp_Elips::*)(const gp_Trsf &) const) &gp_Elips::Transformed, "Transforms an ellipse with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Elips.def("Translate", (void (gp_Elips::*)(const gp_Vec &)) &gp_Elips::Translate, "None", py::arg("V"));
cls_gp_Elips.def("Translated", (gp_Elips (gp_Elips::*)(const gp_Vec &) const) &gp_Elips::Translated, "Translates an ellipse in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Elips.def("Translate", (void (gp_Elips::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Elips::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Elips.def("Translated", (gp_Elips (gp_Elips::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Elips::Translated, "Translates an ellipse from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_HYPR
py::class_<gp_Hypr> cls_gp_Hypr(mod, "gp_Hypr", "Describes a branch of a hyperbola in 3D space. A hyperbola is defined by its major and minor radii and positioned in space with a coordinate system (a gp_Ax2 object) of which: - the origin is the center of the hyperbola, - the 'X Direction' defines the major axis of the hyperbola, and - the 'Y Direction' defines the minor axis of the hyperbola. The origin, 'X Direction' and 'Y Direction' of this coordinate system together define the plane of the hyperbola. This coordinate system is the 'local coordinate system' of the hyperbola. In this coordinate system, the equation of the hyperbola is: X*X/(MajorRadius**2)-Y*Y/(MinorRadius**2) = 1.0 The branch of the hyperbola described is the one located on the positive side of the major axis. The 'main Direction' of the local coordinate system is a normal vector to the plane of the hyperbola. This vector gives an implicit orientation to the hyperbola. We refer to the 'main Axis' of the local coordinate system as the 'Axis' of the hyperbola. The following schema shows the plane of the hyperbola, and in it, the respective positions of the three branches of hyperbolas constructed with the functions OtherBranch, ConjugateBranch1, and ConjugateBranch2:");

// Constructors
cls_gp_Hypr.def(py::init<>());
cls_gp_Hypr.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Methods
// cls_gp_Hypr.def_static("operator new_", (void * (*)(size_t)) &gp_Hypr::operator new, "None", py::arg("theSize"));
// cls_gp_Hypr.def_static("operator delete_", (void (*)(void *)) &gp_Hypr::operator delete, "None", py::arg("theAddress"));
// cls_gp_Hypr.def_static("operator new[]_", (void * (*)(size_t)) &gp_Hypr::operator new[], "None", py::arg("theSize"));
// cls_gp_Hypr.def_static("operator delete[]_", (void (*)(void *)) &gp_Hypr::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Hypr.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Hypr::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Hypr.def_static("operator delete_", (void (*)(void *, void *)) &gp_Hypr::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Hypr.def("SetAxis", (void (gp_Hypr::*)(const gp_Ax1 &)) &gp_Hypr::SetAxis, "Modifies this hyperbola, by redefining its local coordinate system so that: - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed in the same way as for any gp_Ax2). Raises ConstructionError if the direction of A1 is parallel to the direction of the 'XAxis' of the hyperbola.", py::arg("A1"));
cls_gp_Hypr.def("SetLocation", (void (gp_Hypr::*)(const gp_Pnt &)) &gp_Hypr::SetLocation, "Modifies this hyperbola, by redefining its local coordinate system so that its origin becomes P.", py::arg("P"));
cls_gp_Hypr.def("SetMajorRadius", (void (gp_Hypr::*)(const Standard_Real)) &gp_Hypr::SetMajorRadius, "Modifies the major radius of this hyperbola. Exceptions Standard_ConstructionError if MajorRadius is negative.", py::arg("MajorRadius"));
cls_gp_Hypr.def("SetMinorRadius", (void (gp_Hypr::*)(const Standard_Real)) &gp_Hypr::SetMinorRadius, "Modifies the minor radius of this hyperbola. Exceptions Standard_ConstructionError if MinorRadius is negative.", py::arg("MinorRadius"));
cls_gp_Hypr.def("SetPosition", (void (gp_Hypr::*)(const gp_Ax2 &)) &gp_Hypr::SetPosition, "Modifies this hyperbola, by redefining its local coordinate system so that it becomes A2.", py::arg("A2"));
cls_gp_Hypr.def("Asymptote1", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::Asymptote1, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = (B/A)*X where A is the major radius and B is the minor radius. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Hypr.def("Asymptote2", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::Asymptote2, "In the local coordinate system of the hyperbola the equation of the hyperbola is (X*X)/(A*A) - (Y*Y)/(B*B) = 1.0 and the equation of the first asymptote is Y = -(B/A)*X. where A is the major radius and B is the minor radius. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Hypr.def("Axis", (const gp_Ax1 & (gp_Hypr::*)() const) &gp_Hypr::Axis, "Returns the axis passing through the center, and normal to the plane of this hyperbola.");
cls_gp_Hypr.def("ConjugateBranch1", (gp_Hypr (gp_Hypr::*)() const) &gp_Hypr::ConjugateBranch1, "Computes the branch of hyperbola which is on the positive side of the 'YAxis' of <me>.");
cls_gp_Hypr.def("ConjugateBranch2", (gp_Hypr (gp_Hypr::*)() const) &gp_Hypr::ConjugateBranch2, "Computes the branch of hyperbola which is on the negative side of the 'YAxis' of <me>.");
cls_gp_Hypr.def("Directrix1", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::Directrix1, "This directrix is the line normal to the XAxis of the hyperbola in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the hyperbola, where e is the eccentricity of the hyperbola. This line is parallel to the 'YAxis'. The intersection point between the directrix1 and the 'XAxis' is the 'Location' point of the directrix1. This point is on the positive side of the 'XAxis'.");
cls_gp_Hypr.def("Directrix2", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the 'YAxis' of the hyperbola.");
cls_gp_Hypr.def("Eccentricity", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::Eccentricity, "Returns the excentricity of the hyperbola (e > 1). If f is the distance between the location of the hyperbola and the Focus1 then the eccentricity e = f / MajorRadius. Raises DomainError if MajorRadius = 0.0");
cls_gp_Hypr.def("Focal", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::Focal, "Computes the focal distance. It is the distance between the the two focus of the hyperbola.");
cls_gp_Hypr.def("Focus1", (gp_Pnt (gp_Hypr::*)() const) &gp_Hypr::Focus1, "Returns the first focus of the hyperbola. This focus is on the positive side of the 'XAxis' of the hyperbola.");
cls_gp_Hypr.def("Focus2", (gp_Pnt (gp_Hypr::*)() const) &gp_Hypr::Focus2, "Returns the second focus of the hyperbola. This focus is on the negative side of the 'XAxis' of the hyperbola.");
cls_gp_Hypr.def("Location", (const gp_Pnt & (gp_Hypr::*)() const) &gp_Hypr::Location, "Returns the location point of the hyperbola. It is the intersection point between the 'XAxis' and the 'YAxis'.");
cls_gp_Hypr.def("MajorRadius", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::MajorRadius, "Returns the major radius of the hyperbola. It is the radius on the 'XAxis' of the hyperbola.");
cls_gp_Hypr.def("MinorRadius", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::MinorRadius, "Returns the minor radius of the hyperbola. It is the radius on the 'YAxis' of the hyperbola.");
cls_gp_Hypr.def("OtherBranch", (gp_Hypr (gp_Hypr::*)() const) &gp_Hypr::OtherBranch, "Returns the branch of hyperbola obtained by doing the symmetrical transformation of <me> with respect to the 'YAxis' of <me>.");
cls_gp_Hypr.def("Parameter", (Standard_Real (gp_Hypr::*)() const) &gp_Hypr::Parameter, "Returns p = (e * e - 1) * MajorRadius where e is the eccentricity of the hyperbola. Raises DomainError if MajorRadius = 0.0");
cls_gp_Hypr.def("Position", (const gp_Ax2 & (gp_Hypr::*)() const) &gp_Hypr::Position, "Returns the coordinate system of the hyperbola.");
cls_gp_Hypr.def("XAxis", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::XAxis, "Computes an axis, whose - the origin is the center of this hyperbola, and - the unit vector is the 'X Direction' of the local coordinate system of this hyperbola. These axes are, the major axis (the 'X Axis') and of this hyperboReturns the 'XAxis' of the hyperbola.");
cls_gp_Hypr.def("YAxis", (gp_Ax1 (gp_Hypr::*)() const) &gp_Hypr::YAxis, "Computes an axis, whose - the origin is the center of this hyperbola, and - the unit vector is the 'Y Direction' of the local coordinate system of this hyperbola. These axes are the minor axis (the 'Y Axis') of this hyperbola");
cls_gp_Hypr.def("Mirror", (void (gp_Hypr::*)(const gp_Pnt &)) &gp_Hypr::Mirror, "None", py::arg("P"));
cls_gp_Hypr.def("Mirrored", (gp_Hypr (gp_Hypr::*)(const gp_Pnt &) const) &gp_Hypr::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Hypr.def("Mirror", (void (gp_Hypr::*)(const gp_Ax1 &)) &gp_Hypr::Mirror, "None", py::arg("A1"));
cls_gp_Hypr.def("Mirrored", (gp_Hypr (gp_Hypr::*)(const gp_Ax1 &) const) &gp_Hypr::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Hypr.def("Mirror", (void (gp_Hypr::*)(const gp_Ax2 &)) &gp_Hypr::Mirror, "None", py::arg("A2"));
cls_gp_Hypr.def("Mirrored", (gp_Hypr (gp_Hypr::*)(const gp_Ax2 &) const) &gp_Hypr::Mirrored, "Performs the symmetrical transformation of an hyperbola with respect to a plane. The axis placement A2 locates the plane of the symmetry (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Hypr.def("Rotate", (void (gp_Hypr::*)(const gp_Ax1 &, const Standard_Real)) &gp_Hypr::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Hypr.def("Rotated", (gp_Hypr (gp_Hypr::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Hypr::Rotated, "Rotates an hyperbola. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Hypr.def("Scale", (void (gp_Hypr::*)(const gp_Pnt &, const Standard_Real)) &gp_Hypr::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Hypr.def("Scaled", (gp_Hypr (gp_Hypr::*)(const gp_Pnt &, const Standard_Real) const) &gp_Hypr::Scaled, "Scales an hyperbola. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Hypr.def("Transform", (void (gp_Hypr::*)(const gp_Trsf &)) &gp_Hypr::Transform, "None", py::arg("T"));
cls_gp_Hypr.def("Transformed", (gp_Hypr (gp_Hypr::*)(const gp_Trsf &) const) &gp_Hypr::Transformed, "Transforms an hyperbola with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Hypr.def("Translate", (void (gp_Hypr::*)(const gp_Vec &)) &gp_Hypr::Translate, "None", py::arg("V"));
cls_gp_Hypr.def("Translated", (gp_Hypr (gp_Hypr::*)(const gp_Vec &) const) &gp_Hypr::Translated, "Translates an hyperbola in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Hypr.def("Translate", (void (gp_Hypr::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Hypr::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Hypr.def("Translated", (gp_Hypr (gp_Hypr::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Hypr::Translated, "Translates an hyperbola from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_PARAB
py::class_<gp_Parab> cls_gp_Parab(mod, "gp_Parab", "Describes a parabola in 3D space. A parabola is defined by its focal length (that is, the distance between its focus and apex) and positioned in space with a coordinate system (a gp_Ax2 object) where: - the origin of the coordinate system is on the apex of the parabola, - the 'X Axis' of the coordinate system is the axis of symmetry; the parabola is on the positive side of this axis, and - the origin, 'X Direction' and 'Y Direction' of the coordinate system define the plane of the parabola. The equation of the parabola in this coordinate system, which is the 'local coordinate system' of the parabola, is: Y**2 = (2*P) * X. where P, referred to as the parameter of the parabola, is the distance between the focus and the directrix (P is twice the focal length). The 'main Direction' of the local coordinate system gives the normal vector to the plane of the parabola. See Also gce_MakeParab which provides functions for more complex parabola constructions Geom_Parabola which provides additional functions for constructing parabolas and works, in particular, with the parametric equations of parabolas");

// Constructors
cls_gp_Parab.def(py::init<>());
cls_gp_Parab.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Focal"));
cls_gp_Parab.def(py::init<const gp_Ax1 &, const gp_Pnt &>(), py::arg("D"), py::arg("F"));

// Methods
// cls_gp_Parab.def_static("operator new_", (void * (*)(size_t)) &gp_Parab::operator new, "None", py::arg("theSize"));
// cls_gp_Parab.def_static("operator delete_", (void (*)(void *)) &gp_Parab::operator delete, "None", py::arg("theAddress"));
// cls_gp_Parab.def_static("operator new[]_", (void * (*)(size_t)) &gp_Parab::operator new[], "None", py::arg("theSize"));
// cls_gp_Parab.def_static("operator delete[]_", (void (*)(void *)) &gp_Parab::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Parab.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Parab::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Parab.def_static("operator delete_", (void (*)(void *, void *)) &gp_Parab::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Parab.def("SetAxis", (void (gp_Parab::*)(const gp_Ax1 &)) &gp_Parab::SetAxis, "Modifies this parabola by redefining its local coordinate system so that - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed in the same way as for any gp_Ax2) Raises ConstructionError if the direction of A1 is parallel to the previous XAxis of the parabola.", py::arg("A1"));
cls_gp_Parab.def("SetFocal", (void (gp_Parab::*)(const Standard_Real)) &gp_Parab::SetFocal, "Changes the focal distance of the parabola. Raises ConstructionError if Focal < 0.0", py::arg("Focal"));
cls_gp_Parab.def("SetLocation", (void (gp_Parab::*)(const gp_Pnt &)) &gp_Parab::SetLocation, "Changes the location of the parabola. It is the vertex of the parabola.", py::arg("P"));
cls_gp_Parab.def("SetPosition", (void (gp_Parab::*)(const gp_Ax2 &)) &gp_Parab::SetPosition, "Changes the local coordinate system of the parabola.", py::arg("A2"));
cls_gp_Parab.def("Axis", (const gp_Ax1 & (gp_Parab::*)() const) &gp_Parab::Axis, "Returns the main axis of the parabola. It is the axis normal to the plane of the parabola passing through the vertex of the parabola.");
cls_gp_Parab.def("Directrix", (gp_Ax1 (gp_Parab::*)() const) &gp_Parab::Directrix, "Computes the directrix of this parabola. The directrix is: - a line parallel to the 'Y Direction' of the local coordinate system of this parabola, and - located on the negative side of the axis of symmetry, at a distance from the apex which is equal to the focal length of this parabola. The directrix is returned as an axis (a gp_Ax1 object), the origin of which is situated on the 'X Axis' of this parabola.");
cls_gp_Parab.def("Focal", (Standard_Real (gp_Parab::*)() const) &gp_Parab::Focal, "Returns the distance between the vertex and the focus of the parabola.");
cls_gp_Parab.def("Focus", (gp_Pnt (gp_Parab::*)() const) &gp_Parab::Focus, "- Computes the focus of the parabola.");
cls_gp_Parab.def("Location", (const gp_Pnt & (gp_Parab::*)() const) &gp_Parab::Location, "Returns the vertex of the parabola. It is the 'Location' point of the coordinate system of the parabola.");
cls_gp_Parab.def("Parameter", (Standard_Real (gp_Parab::*)() const) &gp_Parab::Parameter, "Computes the parameter of the parabola. It is the distance between the focus and the directrix of the parabola. This distance is twice the focal length.");
cls_gp_Parab.def("Position", (const gp_Ax2 & (gp_Parab::*)() const) &gp_Parab::Position, "Returns the local coordinate system of the parabola.");
cls_gp_Parab.def("XAxis", (gp_Ax1 (gp_Parab::*)() const) &gp_Parab::XAxis, "Returns the symmetry axis of the parabola. The location point of the axis is the vertex of the parabola.");
cls_gp_Parab.def("YAxis", (gp_Ax1 (gp_Parab::*)() const) &gp_Parab::YAxis, "It is an axis parallel to the directrix of the parabola. The location point of this axis is the vertex of the parabola.");
cls_gp_Parab.def("Mirror", (void (gp_Parab::*)(const gp_Pnt &)) &gp_Parab::Mirror, "None", py::arg("P"));
cls_gp_Parab.def("Mirrored", (gp_Parab (gp_Parab::*)(const gp_Pnt &) const) &gp_Parab::Mirrored, "Performs the symmetrical transformation of a parabola with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Parab.def("Mirror", (void (gp_Parab::*)(const gp_Ax1 &)) &gp_Parab::Mirror, "None", py::arg("A1"));
cls_gp_Parab.def("Mirrored", (gp_Parab (gp_Parab::*)(const gp_Ax1 &) const) &gp_Parab::Mirrored, "Performs the symmetrical transformation of a parabola with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Parab.def("Mirror", (void (gp_Parab::*)(const gp_Ax2 &)) &gp_Parab::Mirror, "None", py::arg("A2"));
cls_gp_Parab.def("Mirrored", (gp_Parab (gp_Parab::*)(const gp_Ax2 &) const) &gp_Parab::Mirrored, "Performs the symmetrical transformation of a parabola with respect to a plane. The axis placement A2 locates the plane of the symmetry (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Parab.def("Rotate", (void (gp_Parab::*)(const gp_Ax1 &, const Standard_Real)) &gp_Parab::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Parab.def("Rotated", (gp_Parab (gp_Parab::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Parab::Rotated, "Rotates a parabola. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Parab.def("Scale", (void (gp_Parab::*)(const gp_Pnt &, const Standard_Real)) &gp_Parab::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Parab.def("Scaled", (gp_Parab (gp_Parab::*)(const gp_Pnt &, const Standard_Real) const) &gp_Parab::Scaled, "Scales a parabola. S is the scaling value. If S is negative the direction of the symmetry axis XAxis is reversed and the direction of the YAxis too.", py::arg("P"), py::arg("S"));
cls_gp_Parab.def("Transform", (void (gp_Parab::*)(const gp_Trsf &)) &gp_Parab::Transform, "None", py::arg("T"));
cls_gp_Parab.def("Transformed", (gp_Parab (gp_Parab::*)(const gp_Trsf &) const) &gp_Parab::Transformed, "Transforms a parabola with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Parab.def("Translate", (void (gp_Parab::*)(const gp_Vec &)) &gp_Parab::Translate, "None", py::arg("V"));
cls_gp_Parab.def("Translated", (gp_Parab (gp_Parab::*)(const gp_Vec &) const) &gp_Parab::Translated, "Translates a parabola in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Parab.def("Translate", (void (gp_Parab::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Parab::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Parab.def("Translated", (gp_Parab (gp_Parab::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Parab::Translated, "Translates a parabola from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_AX3
py::class_<gp_Ax3> cls_gp_Ax3(mod, "gp_Ax3", "Describes a coordinate system in 3D space. Unlike a gp_Ax2 coordinate system, a gp_Ax3 can be right-handed ('direct sense') or left-handed ('indirect sense'). A coordinate system is defined by: - its origin (also referred to as its 'Location point'), and - three orthogonal unit vectors, termed the 'X Direction', the 'Y Direction' and the 'Direction' (also referred to as the 'main Direction'). The 'Direction' of the coordinate system is called its 'main Direction' because whenever this unit vector is modified, the 'X Direction' and the 'Y Direction' are recomputed. However, when we modify either the 'X Direction' or the 'Y Direction', 'Direction' is not modified. 'Direction' is also the 'Z Direction'. The 'main Direction' is always parallel to the cross product of its 'X Direction' and 'Y Direction'. If the coordinate system is right-handed, it satisfies the equation: 'main Direction' = 'X Direction' ^ 'Y Direction' and if it is left-handed, it satisfies the equation: 'main Direction' = -'X Direction' ^ 'Y Direction' A coordinate system is used: - to describe geometric entities, in particular to position them. The local coordinate system of a geometric entity serves the same purpose as the STEP function 'axis placement three axes', or - to define geometric transformations. Note: - We refer to the 'X Axis', 'Y Axis' and 'Z Axis', respectively, as the axes having: - the origin of the coordinate system as their origin, and - the unit vectors 'X Direction', 'Y Direction' and 'main Direction', respectively, as their unit vectors. - The 'Z Axis' is also the 'main Axis'. - gp_Ax2 is used to define a coordinate system that must be always right-handed.");

// Constructors
cls_gp_Ax3.def(py::init<>());
cls_gp_Ax3.def(py::init<const gp_Ax2 &>(), py::arg("A"));
cls_gp_Ax3.def(py::init<const gp_Pnt &, const gp_Dir &, const gp_Dir &>(), py::arg("P"), py::arg("N"), py::arg("Vx"));
cls_gp_Ax3.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));

// Methods
// cls_gp_Ax3.def_static("operator new_", (void * (*)(size_t)) &gp_Ax3::operator new, "None", py::arg("theSize"));
// cls_gp_Ax3.def_static("operator delete_", (void (*)(void *)) &gp_Ax3::operator delete, "None", py::arg("theAddress"));
// cls_gp_Ax3.def_static("operator new[]_", (void * (*)(size_t)) &gp_Ax3::operator new[], "None", py::arg("theSize"));
// cls_gp_Ax3.def_static("operator delete[]_", (void (*)(void *)) &gp_Ax3::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Ax3.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Ax3::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Ax3.def_static("operator delete_", (void (*)(void *, void *)) &gp_Ax3::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Ax3.def("XReverse", (void (gp_Ax3::*)()) &gp_Ax3::XReverse, "Reverses the X direction of <me>.");
cls_gp_Ax3.def("YReverse", (void (gp_Ax3::*)()) &gp_Ax3::YReverse, "Reverses the Y direction of <me>.");
cls_gp_Ax3.def("ZReverse", (void (gp_Ax3::*)()) &gp_Ax3::ZReverse, "Reverses the Z direction of <me>.");
cls_gp_Ax3.def("SetAxis", (void (gp_Ax3::*)(const gp_Ax1 &)) &gp_Ax3::SetAxis, "Assigns the origin and 'main Direction' of the axis A1 to this coordinate system, then recomputes its 'X Direction' and 'Y Direction'. Note: - The new 'X Direction' is computed as follows: new 'X Direction' = V1 ^(previous 'X Direction' ^ V) where V is the 'Direction' of A1. - The orientation of this coordinate system (right-handed or left-handed) is not modified. Raises ConstructionError if the 'Direction' of <A1> and the 'XDirection' of <me> are parallel (same or opposite orientation) because it is impossible to calculate the new 'XDirection' and the new 'YDirection'.", py::arg("A1"));
cls_gp_Ax3.def("SetDirection", (void (gp_Ax3::*)(const gp_Dir &)) &gp_Ax3::SetDirection, "Changes the main direction of this coordinate system, then recomputes its 'X Direction' and 'Y Direction'. Note: - The new 'X Direction' is computed as follows: new 'X Direction' = V ^ (previous 'X Direction' ^ V). - The orientation of this coordinate system (left- or right-handed) is not modified. Raises ConstructionError if <V< and the previous 'XDirection' are parallel because it is impossible to calculate the new 'XDirection' and the new 'YDirection'.", py::arg("V"));
cls_gp_Ax3.def("SetLocation", (void (gp_Ax3::*)(const gp_Pnt &)) &gp_Ax3::SetLocation, "Changes the 'Location' point (origin) of <me>.", py::arg("P"));
cls_gp_Ax3.def("SetXDirection", (void (gp_Ax3::*)(const gp_Dir &)) &gp_Ax3::SetXDirection, "Changes the 'Xdirection' of <me>. The main direction 'Direction' is not modified, the 'Ydirection' is modified. If <Vx> is not normal to the main direction then <XDirection> is computed as follows XDirection = Direction ^ (Vx ^ Direction). Raises ConstructionError if <Vx> is parallel (same or opposite orientation) to the main direction of <me>", py::arg("Vx"));
cls_gp_Ax3.def("SetYDirection", (void (gp_Ax3::*)(const gp_Dir &)) &gp_Ax3::SetYDirection, "Changes the 'Ydirection' of <me>. The main direction is not modified but the 'Xdirection' is changed. If <Vy> is not normal to the main direction then 'YDirection' is computed as follows YDirection = Direction ^ (<Vy> ^ Direction). Raises ConstructionError if <Vy> is parallel to the main direction of <me>", py::arg("Vy"));
cls_gp_Ax3.def("Angle", (Standard_Real (gp_Ax3::*)(const gp_Ax3 &) const) &gp_Ax3::Angle, "Computes the angular value between the main direction of <me> and the main direction of <Other>. Returns the angle between 0 and PI in radians.", py::arg("Other"));
cls_gp_Ax3.def("Axis", (const gp_Ax1 & (gp_Ax3::*)() const) &gp_Ax3::Axis, "Returns the main axis of <me>. It is the 'Location' point and the main 'Direction'.");
cls_gp_Ax3.def("Ax2", (gp_Ax2 (gp_Ax3::*)() const) &gp_Ax3::Ax2, "Computes a right-handed coordinate system with the same 'X Direction' and 'Y Direction' as those of this coordinate system, then recomputes the 'main Direction'. If this coordinate system is right-handed, the result returned is the same coordinate system. If this coordinate system is left-handed, the result is reversed.");
cls_gp_Ax3.def("Direction", (const gp_Dir & (gp_Ax3::*)() const) &gp_Ax3::Direction, "Returns the main direction of <me>.");
cls_gp_Ax3.def("Location", (const gp_Pnt & (gp_Ax3::*)() const) &gp_Ax3::Location, "Returns the 'Location' point (origin) of <me>.");
cls_gp_Ax3.def("XDirection", (const gp_Dir & (gp_Ax3::*)() const) &gp_Ax3::XDirection, "Returns the 'XDirection' of <me>.");
cls_gp_Ax3.def("YDirection", (const gp_Dir & (gp_Ax3::*)() const) &gp_Ax3::YDirection, "Returns the 'YDirection' of <me>.");
cls_gp_Ax3.def("Direct", (Standard_Boolean (gp_Ax3::*)() const) &gp_Ax3::Direct, "Returns True if the coordinate system is right-handed. i.e. XDirection().Crossed(YDirection()).Dot(Direction()) > 0");
cls_gp_Ax3.def("IsCoplanar", (Standard_Boolean (gp_Ax3::*)(const gp_Ax3 &, const Standard_Real, const Standard_Real) const) &gp_Ax3::IsCoplanar, "Returns True if . the distance between the 'Location' point of <me> and <Other> is lower or equal to LinearTolerance and . the distance between the 'Location' point of <Other> and <me> is lower or equal to LinearTolerance and . the main direction of <me> and the main direction of <Other> are parallel (same or opposite orientation).", py::arg("Other"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Ax3.def("IsCoplanar", (Standard_Boolean (gp_Ax3::*)(const gp_Ax1 &, const Standard_Real, const Standard_Real) const) &gp_Ax3::IsCoplanar, "Returns True if . the distance between <me> and the 'Location' point of A1 is lower of equal to LinearTolerance and . the distance between A1 and the 'Location' point of <me> is lower or equal to LinearTolerance and . the main direction of <me> and the direction of A1 are normal.", py::arg("A1"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Ax3.def("Mirror", (void (gp_Ax3::*)(const gp_Pnt &)) &gp_Ax3::Mirror, "None", py::arg("P"));
cls_gp_Ax3.def("Mirrored", (gp_Ax3 (gp_Ax3::*)(const gp_Pnt &) const) &gp_Ax3::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to the point P which is the center of the symmetry. Warnings : The main direction of the axis placement is not changed. The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"));
cls_gp_Ax3.def("Mirror", (void (gp_Ax3::*)(const gp_Ax1 &)) &gp_Ax3::Mirror, "None", py::arg("A1"));
cls_gp_Ax3.def("Mirrored", (gp_Ax3 (gp_Ax3::*)(const gp_Ax1 &) const) &gp_Ax3::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to an axis placement which is the axis of the symmetry. The transformation is performed on the 'Location' point, on the 'XDirection' and 'YDirection'. The resulting main 'Direction' is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("A1"));
cls_gp_Ax3.def("Mirror", (void (gp_Ax3::*)(const gp_Ax2 &)) &gp_Ax3::Mirror, "None", py::arg("A2"));
cls_gp_Ax3.def("Mirrored", (gp_Ax3 (gp_Ax3::*)(const gp_Ax2 &) const) &gp_Ax3::Mirrored, "Performs the symmetrical transformation of an axis placement with respect to a plane. The axis placement <A2> locates the plane of the symmetry : (Location, XDirection, YDirection). The transformation is performed on the 'Location' point, on the 'XDirection' and 'YDirection'. The resulting main 'Direction' is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("A2"));
cls_gp_Ax3.def("Rotate", (void (gp_Ax3::*)(const gp_Ax1 &, const Standard_Real)) &gp_Ax3::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax3.def("Rotated", (gp_Ax3 (gp_Ax3::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Ax3::Rotated, "Rotates an axis placement. <A1> is the axis of the rotation . Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Ax3.def("Scale", (void (gp_Ax3::*)(const gp_Pnt &, const Standard_Real)) &gp_Ax3::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Ax3.def("Scaled", (gp_Ax3 (gp_Ax3::*)(const gp_Pnt &, const Standard_Real) const) &gp_Ax3::Scaled, "Applies a scaling transformation on the axis placement. The 'Location' point of the axisplacement is modified. Warnings : If the scale <S> is negative : . the main direction of the axis placement is not changed. . The 'XDirection' and the 'YDirection' are reversed. So the axis placement stay right handed.", py::arg("P"), py::arg("S"));
cls_gp_Ax3.def("Transform", (void (gp_Ax3::*)(const gp_Trsf &)) &gp_Ax3::Transform, "None", py::arg("T"));
cls_gp_Ax3.def("Transformed", (gp_Ax3 (gp_Ax3::*)(const gp_Trsf &) const) &gp_Ax3::Transformed, "Transforms an axis placement with a Trsf. The 'Location' point, the 'XDirection' and the 'YDirection' are transformed with T. The resulting main 'Direction' of <me> is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("T"));
cls_gp_Ax3.def("Translate", (void (gp_Ax3::*)(const gp_Vec &)) &gp_Ax3::Translate, "None", py::arg("V"));
cls_gp_Ax3.def("Translated", (gp_Ax3 (gp_Ax3::*)(const gp_Vec &) const) &gp_Ax3::Translated, "Translates an axis plaxement in the direction of the vector <V>. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Ax3.def("Translate", (void (gp_Ax3::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Ax3::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Ax3.def("Translated", (gp_Ax3 (gp_Ax3::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Ax3::Translated, "Translates an axis placement from the point <P1> to the point <P2>.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_PLN
py::class_<gp_Pln> cls_gp_Pln(mod, "gp_Pln", "Describes a plane. A plane is positioned in space with a coordinate system (a gp_Ax3 object), such that the plane is defined by the origin, 'X Direction' and 'Y Direction' of this coordinate system, which is the 'local coordinate system' of the plane. The 'main Direction' of the coordinate system is a vector normal to the plane. It gives the plane an implicit orientation such that the plane is said to be 'direct', if the coordinate system is right-handed, or 'indirect' in the other case. Note: when a gp_Pln plane is converted into a Geom_Plane plane, some implicit properties of its local coordinate system are used explicitly: - its origin defines the origin of the two parameters of the planar surface, - its implicit orientation is also that of the Geom_Plane. See Also gce_MakePln which provides functions for more complex plane constructions Geom_Plane which provides additional functions for constructing planes and works, in particular, with the parametric equations of planes");

// Constructors
cls_gp_Pln.def(py::init<>());
cls_gp_Pln.def(py::init<const gp_Ax3 &>(), py::arg("A3"));
cls_gp_Pln.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("P"), py::arg("V"));
cls_gp_Pln.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));

// Methods
// cls_gp_Pln.def_static("operator new_", (void * (*)(size_t)) &gp_Pln::operator new, "None", py::arg("theSize"));
// cls_gp_Pln.def_static("operator delete_", (void (*)(void *)) &gp_Pln::operator delete, "None", py::arg("theAddress"));
// cls_gp_Pln.def_static("operator new[]_", (void * (*)(size_t)) &gp_Pln::operator new[], "None", py::arg("theSize"));
// cls_gp_Pln.def_static("operator delete[]_", (void (*)(void *)) &gp_Pln::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Pln.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Pln::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Pln.def_static("operator delete_", (void (*)(void *, void *)) &gp_Pln::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Pln.def("Coefficients", [](gp_Pln &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D){ self.Coefficients(A, B, C, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D); }, "Returns the coefficients of the plane's cartesian equation : A * X + B * Y + C * Z + D = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_gp_Pln.def("SetAxis", (void (gp_Pln::*)(const gp_Ax1 &)) &gp_Pln::SetAxis, "Modifies this plane, by redefining its local coordinate system so that - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed). Raises ConstructionError if the A1 is parallel to the 'XAxis' of the plane.", py::arg("A1"));
cls_gp_Pln.def("SetLocation", (void (gp_Pln::*)(const gp_Pnt &)) &gp_Pln::SetLocation, "Changes the origin of the plane.", py::arg("Loc"));
cls_gp_Pln.def("SetPosition", (void (gp_Pln::*)(const gp_Ax3 &)) &gp_Pln::SetPosition, "Changes the local coordinate system of the plane.", py::arg("A3"));
cls_gp_Pln.def("UReverse", (void (gp_Pln::*)()) &gp_Pln::UReverse, "Reverses the U parametrization of the plane reversing the XAxis.");
cls_gp_Pln.def("VReverse", (void (gp_Pln::*)()) &gp_Pln::VReverse, "Reverses the V parametrization of the plane reversing the YAxis.");
cls_gp_Pln.def("Direct", (Standard_Boolean (gp_Pln::*)() const) &gp_Pln::Direct, "returns true if the Ax3 is right handed.");
cls_gp_Pln.def("Axis", (const gp_Ax1 & (gp_Pln::*)() const) &gp_Pln::Axis, "Returns the plane's normal Axis.");
cls_gp_Pln.def("Location", (const gp_Pnt & (gp_Pln::*)() const) &gp_Pln::Location, "Returns the plane's location (origin).");
cls_gp_Pln.def("Position", (const gp_Ax3 & (gp_Pln::*)() const) &gp_Pln::Position, "Returns the local coordinate system of the plane .");
cls_gp_Pln.def("Distance", (Standard_Real (gp_Pln::*)(const gp_Pnt &) const) &gp_Pln::Distance, "Computes the distance between <me> and the point <P>.", py::arg("P"));
cls_gp_Pln.def("Distance", (Standard_Real (gp_Pln::*)(const gp_Lin &) const) &gp_Pln::Distance, "Computes the distance between <me> and the line <L>.", py::arg("L"));
cls_gp_Pln.def("Distance", (Standard_Real (gp_Pln::*)(const gp_Pln &) const) &gp_Pln::Distance, "Computes the distance between two planes.", py::arg("Other"));
cls_gp_Pln.def("SquareDistance", (Standard_Real (gp_Pln::*)(const gp_Pnt &) const) &gp_Pln::SquareDistance, "Computes the square distance between <me> and the point <P>.", py::arg("P"));
cls_gp_Pln.def("SquareDistance", (Standard_Real (gp_Pln::*)(const gp_Lin &) const) &gp_Pln::SquareDistance, "Computes the square distance between <me> and the line <L>.", py::arg("L"));
cls_gp_Pln.def("SquareDistance", (Standard_Real (gp_Pln::*)(const gp_Pln &) const) &gp_Pln::SquareDistance, "Computes the square distance between two planes.", py::arg("Other"));
cls_gp_Pln.def("XAxis", (gp_Ax1 (gp_Pln::*)() const) &gp_Pln::XAxis, "Returns the X axis of the plane.");
cls_gp_Pln.def("YAxis", (gp_Ax1 (gp_Pln::*)() const) &gp_Pln::YAxis, "Returns the Y axis of the plane.");
cls_gp_Pln.def("Contains", (Standard_Boolean (gp_Pln::*)(const gp_Pnt &, const Standard_Real) const) &gp_Pln::Contains, "Returns true if this plane contains the point P. This means that - the distance between point P and this plane is less than or equal to LinearTolerance, or - line L is normal to the 'main Axis' of the local coordinate system of this plane, within the tolerance AngularTolerance, and the distance between the origin of line L and this plane is less than or equal to LinearTolerance.", py::arg("P"), py::arg("LinearTolerance"));
cls_gp_Pln.def("Contains", (Standard_Boolean (gp_Pln::*)(const gp_Lin &, const Standard_Real, const Standard_Real) const) &gp_Pln::Contains, "Returns true if this plane contains the line L. This means that - the distance between point P and this plane is less than or equal to LinearTolerance, or - line L is normal to the 'main Axis' of the local coordinate system of this plane, within the tolerance AngularTolerance, and the distance between the origin of line L and this plane is less than or equal to LinearTolerance.", py::arg("L"), py::arg("LinearTolerance"), py::arg("AngularTolerance"));
cls_gp_Pln.def("Mirror", (void (gp_Pln::*)(const gp_Pnt &)) &gp_Pln::Mirror, "None", py::arg("P"));
cls_gp_Pln.def("Mirrored", (gp_Pln (gp_Pln::*)(const gp_Pnt &) const) &gp_Pln::Mirrored, "Performs the symmetrical transformation of a plane with respect to the point <P> which is the center of the symmetry Warnings : The normal direction to the plane is not changed. The 'XAxis' and the 'YAxis' are reversed.", py::arg("P"));
cls_gp_Pln.def("Mirror", (void (gp_Pln::*)(const gp_Ax1 &)) &gp_Pln::Mirror, "None", py::arg("A1"));
cls_gp_Pln.def("Mirrored", (gp_Pln (gp_Pln::*)(const gp_Ax1 &) const) &gp_Pln::Mirrored, "Performs the symmetrical transformation of a plane with respect to an axis placement which is the axis of the symmetry. The transformation is performed on the 'Location' point, on the 'XAxis' and the 'YAxis'. The resulting normal direction is the cross product between the 'XDirection' and the 'YDirection' after transformation if the initial plane was right handed, else it is the opposite.", py::arg("A1"));
cls_gp_Pln.def("Mirror", (void (gp_Pln::*)(const gp_Ax2 &)) &gp_Pln::Mirror, "None", py::arg("A2"));
cls_gp_Pln.def("Mirrored", (gp_Pln (gp_Pln::*)(const gp_Ax2 &) const) &gp_Pln::Mirrored, "Performs the symmetrical transformation of a plane with respect to an axis placement. The axis placement <A2> locates the plane of the symmetry. The transformation is performed on the 'Location' point, on the 'XAxis' and the 'YAxis'. The resulting normal direction is the cross product between the 'XDirection' and the 'YDirection' after transformation if the initial plane was right handed, else it is the opposite.", py::arg("A2"));
cls_gp_Pln.def("Rotate", (void (gp_Pln::*)(const gp_Ax1 &, const Standard_Real)) &gp_Pln::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Pln.def("Rotated", (gp_Pln (gp_Pln::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Pln::Rotated, "rotates a plane. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Pln.def("Scale", (void (gp_Pln::*)(const gp_Pnt &, const Standard_Real)) &gp_Pln::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Pln.def("Scaled", (gp_Pln (gp_Pln::*)(const gp_Pnt &, const Standard_Real) const) &gp_Pln::Scaled, "Scales a plane. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Pln.def("Transform", (void (gp_Pln::*)(const gp_Trsf &)) &gp_Pln::Transform, "None", py::arg("T"));
cls_gp_Pln.def("Transformed", (gp_Pln (gp_Pln::*)(const gp_Trsf &) const) &gp_Pln::Transformed, "Transforms a plane with the transformation T from class Trsf. The transformation is performed on the 'Location' point, on the 'XAxis' and the 'YAxis'. The resulting normal direction is the cross product between the 'XDirection' and the 'YDirection' after transformation.", py::arg("T"));
cls_gp_Pln.def("Translate", (void (gp_Pln::*)(const gp_Vec &)) &gp_Pln::Translate, "None", py::arg("V"));
cls_gp_Pln.def("Translated", (gp_Pln (gp_Pln::*)(const gp_Vec &) const) &gp_Pln::Translated, "Translates a plane in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Pln.def("Translate", (void (gp_Pln::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Pln::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Pln.def("Translated", (gp_Pln (gp_Pln::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Pln::Translated, "Translates a plane from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_CYLINDER
py::class_<gp_Cylinder> cls_gp_Cylinder(mod, "gp_Cylinder", "Describes an infinite cylindrical surface. A cylinder is defined by its radius and positioned in space with a coordinate system (a gp_Ax3 object), the 'main Axis' of which is the axis of the cylinder. This coordinate system is the 'local coordinate system' of the cylinder. Note: when a gp_Cylinder cylinder is converted into a Geom_CylindricalSurface cylinder, some implicit properties of its local coordinate system are used explicitly: - its origin, 'X Direction', 'Y Direction' and 'main Direction' are used directly to define the parametric directions on the cylinder and the origin of the parameters, - its implicit orientation (right-handed or left-handed) gives an orientation (direct or indirect) to the Geom_CylindricalSurface cylinder. See Also gce_MakeCylinder which provides functions for more complex cylinder constructions Geom_CylindricalSurface which provides additional functions for constructing cylinders and works, in particular, with the parametric equations of cylinders gp_Ax3");

// Constructors
cls_gp_Cylinder.def(py::init<>());
cls_gp_Cylinder.def(py::init<const gp_Ax3 &, const Standard_Real>(), py::arg("A3"), py::arg("Radius"));

// Methods
// cls_gp_Cylinder.def_static("operator new_", (void * (*)(size_t)) &gp_Cylinder::operator new, "None", py::arg("theSize"));
// cls_gp_Cylinder.def_static("operator delete_", (void (*)(void *)) &gp_Cylinder::operator delete, "None", py::arg("theAddress"));
// cls_gp_Cylinder.def_static("operator new[]_", (void * (*)(size_t)) &gp_Cylinder::operator new[], "None", py::arg("theSize"));
// cls_gp_Cylinder.def_static("operator delete[]_", (void (*)(void *)) &gp_Cylinder::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Cylinder.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Cylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Cylinder.def_static("operator delete_", (void (*)(void *, void *)) &gp_Cylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Cylinder.def("SetAxis", (void (gp_Cylinder::*)(const gp_Ax1 &)) &gp_Cylinder::SetAxis, "Changes the symmetry axis of the cylinder. Raises ConstructionError if the direction of A1 is parallel to the 'XDirection' of the coordinate system of the cylinder.", py::arg("A1"));
cls_gp_Cylinder.def("SetLocation", (void (gp_Cylinder::*)(const gp_Pnt &)) &gp_Cylinder::SetLocation, "Changes the location of the surface.", py::arg("Loc"));
cls_gp_Cylinder.def("SetPosition", (void (gp_Cylinder::*)(const gp_Ax3 &)) &gp_Cylinder::SetPosition, "Change the local coordinate system of the surface.", py::arg("A3"));
cls_gp_Cylinder.def("SetRadius", (void (gp_Cylinder::*)(const Standard_Real)) &gp_Cylinder::SetRadius, "Modifies the radius of this cylinder. Exceptions Standard_ConstructionError if R is negative.", py::arg("R"));
cls_gp_Cylinder.def("UReverse", (void (gp_Cylinder::*)()) &gp_Cylinder::UReverse, "Reverses the U parametrization of the cylinder reversing the YAxis.");
cls_gp_Cylinder.def("VReverse", (void (gp_Cylinder::*)()) &gp_Cylinder::VReverse, "Reverses the V parametrization of the plane reversing the Axis.");
cls_gp_Cylinder.def("Direct", (Standard_Boolean (gp_Cylinder::*)() const) &gp_Cylinder::Direct, "Returns true if the local coordinate system of this cylinder is right-handed.");
cls_gp_Cylinder.def("Axis", (const gp_Ax1 & (gp_Cylinder::*)() const) &gp_Cylinder::Axis, "Returns the symmetry axis of the cylinder.");
cls_gp_Cylinder.def("Coefficients", [](gp_Cylinder &self, Standard_Real & A1, Standard_Real & A2, Standard_Real & A3, Standard_Real & B1, Standard_Real & B2, Standard_Real & B3, Standard_Real & C1, Standard_Real & C2, Standard_Real & C3, Standard_Real & D){ self.Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); }, "Computes the coefficients of the implicit equation of the quadric in the absolute cartesian coordinate system : A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0", py::arg("A1"), py::arg("A2"), py::arg("A3"), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("D"));
cls_gp_Cylinder.def("Location", (const gp_Pnt & (gp_Cylinder::*)() const) &gp_Cylinder::Location, "Returns the 'Location' point of the cylinder.");
cls_gp_Cylinder.def("Position", (const gp_Ax3 & (gp_Cylinder::*)() const) &gp_Cylinder::Position, "Returns the local coordinate system of the cylinder.");
cls_gp_Cylinder.def("Radius", (Standard_Real (gp_Cylinder::*)() const) &gp_Cylinder::Radius, "Returns the radius of the cylinder.");
cls_gp_Cylinder.def("XAxis", (gp_Ax1 (gp_Cylinder::*)() const) &gp_Cylinder::XAxis, "Returns the axis X of the cylinder.");
cls_gp_Cylinder.def("YAxis", (gp_Ax1 (gp_Cylinder::*)() const) &gp_Cylinder::YAxis, "Returns the axis Y of the cylinder.");
cls_gp_Cylinder.def("Mirror", (void (gp_Cylinder::*)(const gp_Pnt &)) &gp_Cylinder::Mirror, "None", py::arg("P"));
cls_gp_Cylinder.def("Mirrored", (gp_Cylinder (gp_Cylinder::*)(const gp_Pnt &) const) &gp_Cylinder::Mirrored, "Performs the symmetrical transformation of a cylinder with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Cylinder.def("Mirror", (void (gp_Cylinder::*)(const gp_Ax1 &)) &gp_Cylinder::Mirror, "None", py::arg("A1"));
cls_gp_Cylinder.def("Mirrored", (gp_Cylinder (gp_Cylinder::*)(const gp_Ax1 &) const) &gp_Cylinder::Mirrored, "Performs the symmetrical transformation of a cylinder with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Cylinder.def("Mirror", (void (gp_Cylinder::*)(const gp_Ax2 &)) &gp_Cylinder::Mirror, "None", py::arg("A2"));
cls_gp_Cylinder.def("Mirrored", (gp_Cylinder (gp_Cylinder::*)(const gp_Ax2 &) const) &gp_Cylinder::Mirrored, "Performs the symmetrical transformation of a cylinder with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Cylinder.def("Rotate", (void (gp_Cylinder::*)(const gp_Ax1 &, const Standard_Real)) &gp_Cylinder::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Cylinder.def("Rotated", (gp_Cylinder (gp_Cylinder::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Cylinder::Rotated, "Rotates a cylinder. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Cylinder.def("Scale", (void (gp_Cylinder::*)(const gp_Pnt &, const Standard_Real)) &gp_Cylinder::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Cylinder.def("Scaled", (gp_Cylinder (gp_Cylinder::*)(const gp_Pnt &, const Standard_Real) const) &gp_Cylinder::Scaled, "Scales a cylinder. S is the scaling value. The absolute value of S is used to scale the cylinder", py::arg("P"), py::arg("S"));
cls_gp_Cylinder.def("Transform", (void (gp_Cylinder::*)(const gp_Trsf &)) &gp_Cylinder::Transform, "None", py::arg("T"));
cls_gp_Cylinder.def("Transformed", (gp_Cylinder (gp_Cylinder::*)(const gp_Trsf &) const) &gp_Cylinder::Transformed, "Transforms a cylinder with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Cylinder.def("Translate", (void (gp_Cylinder::*)(const gp_Vec &)) &gp_Cylinder::Translate, "None", py::arg("V"));
cls_gp_Cylinder.def("Translated", (gp_Cylinder (gp_Cylinder::*)(const gp_Vec &) const) &gp_Cylinder::Translated, "Translates a cylinder in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Cylinder.def("Translate", (void (gp_Cylinder::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Cylinder::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Cylinder.def("Translated", (gp_Cylinder (gp_Cylinder::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Cylinder::Translated, "Translates a cylinder from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_CONE
py::class_<gp_Cone> cls_gp_Cone(mod, "gp_Cone", "Defines an infinite conical surface. A cone is defined by its half-angle at the apex and positioned in space with a coordinate system (a gp_Ax3 object) and a 'reference radius' where: - the 'main Axis' of the coordinate system is the axis of revolution of the cone, - the plane defined by the origin, the 'X Direction' and the 'Y Direction' of the coordinate system is the reference plane of the cone; the intersection of the cone with this reference plane is a circle of radius equal to the reference radius, if the half-angle is positive, the apex of the cone is on the negative side of the 'main Axis' of the coordinate system. If the half-angle is negative, the apex is on the positive side. This coordinate system is the 'local coordinate system' of the cone. Note: when a gp_Cone cone is converted into a Geom_ConicalSurface cone, some implicit properties of its local coordinate system are used explicitly: - its origin, 'X Direction', 'Y Direction' and 'main Direction' are used directly to define the parametric directions on the cone and the origin of the parameters, - its implicit orientation (right-handed or left-handed) gives the orientation (direct or indirect) of the Geom_ConicalSurface cone. See Also gce_MakeCone which provides functions for more complex cone constructions Geom_ConicalSurface which provides additional functions for constructing cones and works, in particular, with the parametric equations of cones gp_Ax3");

// Constructors
cls_gp_Cone.def(py::init<>());
cls_gp_Cone.def(py::init<const gp_Ax3 &, const Standard_Real, const Standard_Real>(), py::arg("A3"), py::arg("Ang"), py::arg("Radius"));

// Methods
// cls_gp_Cone.def_static("operator new_", (void * (*)(size_t)) &gp_Cone::operator new, "None", py::arg("theSize"));
// cls_gp_Cone.def_static("operator delete_", (void (*)(void *)) &gp_Cone::operator delete, "None", py::arg("theAddress"));
// cls_gp_Cone.def_static("operator new[]_", (void * (*)(size_t)) &gp_Cone::operator new[], "None", py::arg("theSize"));
// cls_gp_Cone.def_static("operator delete[]_", (void (*)(void *)) &gp_Cone::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Cone.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Cone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Cone.def_static("operator delete_", (void (*)(void *, void *)) &gp_Cone::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Cone.def("SetAxis", (void (gp_Cone::*)(const gp_Ax1 &)) &gp_Cone::SetAxis, "Changes the symmetry axis of the cone. Raises ConstructionError the direction of A1 is parallel to the 'XDirection' of the coordinate system of the cone.", py::arg("A1"));
cls_gp_Cone.def("SetLocation", (void (gp_Cone::*)(const gp_Pnt &)) &gp_Cone::SetLocation, "Changes the location of the cone.", py::arg("Loc"));
cls_gp_Cone.def("SetPosition", (void (gp_Cone::*)(const gp_Ax3 &)) &gp_Cone::SetPosition, "Changes the local coordinate system of the cone. This coordinate system defines the reference plane of the cone.", py::arg("A3"));
cls_gp_Cone.def("SetRadius", (void (gp_Cone::*)(const Standard_Real)) &gp_Cone::SetRadius, "Changes the radius of the cone in the reference plane of the cone. Raised if R < 0.0", py::arg("R"));
cls_gp_Cone.def("SetSemiAngle", (void (gp_Cone::*)(const Standard_Real)) &gp_Cone::SetSemiAngle, "Changes the semi-angle of the cone. Ang is the conical surface semi-angle ]0,PI/2[. Raises ConstructionError if Ang < Resolution from gp or Ang >= PI/2 - Resolution", py::arg("Ang"));
cls_gp_Cone.def("Apex", (gp_Pnt (gp_Cone::*)() const) &gp_Cone::Apex, "Computes the cone's top. The Apex of the cone is on the negative side of the symmetry axis of the cone.");
cls_gp_Cone.def("UReverse", (void (gp_Cone::*)()) &gp_Cone::UReverse, "Reverses the U parametrization of the cone reversing the YAxis.");
cls_gp_Cone.def("VReverse", (void (gp_Cone::*)()) &gp_Cone::VReverse, "Reverses the V parametrization of the cone reversing the ZAxis.");
cls_gp_Cone.def("Direct", (Standard_Boolean (gp_Cone::*)() const) &gp_Cone::Direct, "Returns true if the local coordinate system of this cone is right-handed.");
cls_gp_Cone.def("Axis", (const gp_Ax1 & (gp_Cone::*)() const) &gp_Cone::Axis, "returns the symmetry axis of the cone.");
cls_gp_Cone.def("Coefficients", [](gp_Cone &self, Standard_Real & A1, Standard_Real & A2, Standard_Real & A3, Standard_Real & B1, Standard_Real & B2, Standard_Real & B3, Standard_Real & C1, Standard_Real & C2, Standard_Real & C3, Standard_Real & D){ self.Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); }, "Computes the coefficients of the implicit equation of the quadric in the absolute cartesian coordinates system : A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0", py::arg("A1"), py::arg("A2"), py::arg("A3"), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("D"));
cls_gp_Cone.def("Location", (const gp_Pnt & (gp_Cone::*)() const) &gp_Cone::Location, "returns the 'Location' point of the cone.");
cls_gp_Cone.def("Position", (const gp_Ax3 & (gp_Cone::*)() const) &gp_Cone::Position, "Returns the local coordinates system of the cone.");
cls_gp_Cone.def("RefRadius", (Standard_Real (gp_Cone::*)() const) &gp_Cone::RefRadius, "Returns the radius of the cone in the reference plane.");
cls_gp_Cone.def("SemiAngle", (Standard_Real (gp_Cone::*)() const) &gp_Cone::SemiAngle, "Returns the half-angle at the apex of this cone.");
cls_gp_Cone.def("XAxis", (gp_Ax1 (gp_Cone::*)() const) &gp_Cone::XAxis, "Returns the XAxis of the reference plane.");
cls_gp_Cone.def("YAxis", (gp_Ax1 (gp_Cone::*)() const) &gp_Cone::YAxis, "Returns the YAxis of the reference plane.");
cls_gp_Cone.def("Mirror", (void (gp_Cone::*)(const gp_Pnt &)) &gp_Cone::Mirror, "None", py::arg("P"));
cls_gp_Cone.def("Mirrored", (gp_Cone (gp_Cone::*)(const gp_Pnt &) const) &gp_Cone::Mirrored, "Performs the symmetrical transformation of a cone with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Cone.def("Mirror", (void (gp_Cone::*)(const gp_Ax1 &)) &gp_Cone::Mirror, "None", py::arg("A1"));
cls_gp_Cone.def("Mirrored", (gp_Cone (gp_Cone::*)(const gp_Ax1 &) const) &gp_Cone::Mirrored, "Performs the symmetrical transformation of a cone with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Cone.def("Mirror", (void (gp_Cone::*)(const gp_Ax2 &)) &gp_Cone::Mirror, "None", py::arg("A2"));
cls_gp_Cone.def("Mirrored", (gp_Cone (gp_Cone::*)(const gp_Ax2 &) const) &gp_Cone::Mirrored, "Performs the symmetrical transformation of a cone with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Cone.def("Rotate", (void (gp_Cone::*)(const gp_Ax1 &, const Standard_Real)) &gp_Cone::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Cone.def("Rotated", (gp_Cone (gp_Cone::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Cone::Rotated, "Rotates a cone. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Cone.def("Scale", (void (gp_Cone::*)(const gp_Pnt &, const Standard_Real)) &gp_Cone::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Cone.def("Scaled", (gp_Cone (gp_Cone::*)(const gp_Pnt &, const Standard_Real) const) &gp_Cone::Scaled, "Scales a cone. S is the scaling value. The absolute value of S is used to scale the cone", py::arg("P"), py::arg("S"));
cls_gp_Cone.def("Transform", (void (gp_Cone::*)(const gp_Trsf &)) &gp_Cone::Transform, "None", py::arg("T"));
cls_gp_Cone.def("Transformed", (gp_Cone (gp_Cone::*)(const gp_Trsf &) const) &gp_Cone::Transformed, "Transforms a cone with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Cone.def("Translate", (void (gp_Cone::*)(const gp_Vec &)) &gp_Cone::Translate, "None", py::arg("V"));
cls_gp_Cone.def("Translated", (gp_Cone (gp_Cone::*)(const gp_Vec &) const) &gp_Cone::Translated, "Translates a cone in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Cone.def("Translate", (void (gp_Cone::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Cone::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Cone.def("Translated", (gp_Cone (gp_Cone::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Cone::Translated, "Translates a cone from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_SPHERE
py::class_<gp_Sphere> cls_gp_Sphere(mod, "gp_Sphere", "Describes a sphere. A sphere is defined by its radius and positioned in space with a coordinate system (a gp_Ax3 object). The origin of the coordinate system is the center of the sphere. This coordinate system is the 'local coordinate system' of the sphere. Note: when a gp_Sphere sphere is converted into a Geom_SphericalSurface sphere, some implicit properties of its local coordinate system are used explicitly: - its origin, 'X Direction', 'Y Direction' and 'main Direction' are used directly to define the parametric directions on the sphere and the origin of the parameters, - its implicit orientation (right-handed or left-handed) gives the orientation (direct, indirect) to the Geom_SphericalSurface sphere. See Also gce_MakeSphere which provides functions for more complex sphere constructions Geom_SphericalSurface which provides additional functions for constructing spheres and works, in particular, with the parametric equations of spheres.");

// Constructors
cls_gp_Sphere.def(py::init<>());
cls_gp_Sphere.def(py::init<const gp_Ax3 &, const Standard_Real>(), py::arg("A3"), py::arg("Radius"));

// Methods
// cls_gp_Sphere.def_static("operator new_", (void * (*)(size_t)) &gp_Sphere::operator new, "None", py::arg("theSize"));
// cls_gp_Sphere.def_static("operator delete_", (void (*)(void *)) &gp_Sphere::operator delete, "None", py::arg("theAddress"));
// cls_gp_Sphere.def_static("operator new[]_", (void * (*)(size_t)) &gp_Sphere::operator new[], "None", py::arg("theSize"));
// cls_gp_Sphere.def_static("operator delete[]_", (void (*)(void *)) &gp_Sphere::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Sphere.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Sphere::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Sphere.def_static("operator delete_", (void (*)(void *, void *)) &gp_Sphere::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Sphere.def("SetLocation", (void (gp_Sphere::*)(const gp_Pnt &)) &gp_Sphere::SetLocation, "Changes the center of the sphere.", py::arg("Loc"));
cls_gp_Sphere.def("SetPosition", (void (gp_Sphere::*)(const gp_Ax3 &)) &gp_Sphere::SetPosition, "Changes the local coordinate system of the sphere.", py::arg("A3"));
cls_gp_Sphere.def("SetRadius", (void (gp_Sphere::*)(const Standard_Real)) &gp_Sphere::SetRadius, "Assigns R the radius of the Sphere. Warnings : It is not forbidden to create a sphere with null radius. Raises ConstructionError if R < 0.0", py::arg("R"));
cls_gp_Sphere.def("Area", (Standard_Real (gp_Sphere::*)() const) &gp_Sphere::Area, "Computes the aera of the sphere.");
cls_gp_Sphere.def("Coefficients", [](gp_Sphere &self, Standard_Real & A1, Standard_Real & A2, Standard_Real & A3, Standard_Real & B1, Standard_Real & B2, Standard_Real & B3, Standard_Real & C1, Standard_Real & C2, Standard_Real & C3, Standard_Real & D){ self.Coefficients(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A1, A2, A3, B1, B2, B3, C1, C2, C3, D); }, "Computes the coefficients of the implicit equation of the quadric in the absolute cartesian coordinates system : A1.X**2 + A2.Y**2 + A3.Z**2 + 2.(B1.X.Y + B2.X.Z + B3.Y.Z) + 2.(C1.X + C2.Y + C3.Z) + D = 0.0", py::arg("A1"), py::arg("A2"), py::arg("A3"), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("D"));
cls_gp_Sphere.def("UReverse", (void (gp_Sphere::*)()) &gp_Sphere::UReverse, "Reverses the U parametrization of the sphere reversing the YAxis.");
cls_gp_Sphere.def("VReverse", (void (gp_Sphere::*)()) &gp_Sphere::VReverse, "Reverses the V parametrization of the sphere reversing the ZAxis.");
cls_gp_Sphere.def("Direct", (Standard_Boolean (gp_Sphere::*)() const) &gp_Sphere::Direct, "Returns true if the local coordinate system of this sphere is right-handed.");
cls_gp_Sphere.def("Location", (const gp_Pnt & (gp_Sphere::*)() const) &gp_Sphere::Location, "--- Purpose ; Returns the center of the sphere.");
cls_gp_Sphere.def("Position", (const gp_Ax3 & (gp_Sphere::*)() const) &gp_Sphere::Position, "Returns the local coordinates system of the sphere.");
cls_gp_Sphere.def("Radius", (Standard_Real (gp_Sphere::*)() const) &gp_Sphere::Radius, "Returns the radius of the sphere.");
cls_gp_Sphere.def("Volume", (Standard_Real (gp_Sphere::*)() const) &gp_Sphere::Volume, "Computes the volume of the sphere");
cls_gp_Sphere.def("XAxis", (gp_Ax1 (gp_Sphere::*)() const) &gp_Sphere::XAxis, "Returns the axis X of the sphere.");
cls_gp_Sphere.def("YAxis", (gp_Ax1 (gp_Sphere::*)() const) &gp_Sphere::YAxis, "Returns the axis Y of the sphere.");
cls_gp_Sphere.def("Mirror", (void (gp_Sphere::*)(const gp_Pnt &)) &gp_Sphere::Mirror, "None", py::arg("P"));
cls_gp_Sphere.def("Mirrored", (gp_Sphere (gp_Sphere::*)(const gp_Pnt &) const) &gp_Sphere::Mirrored, "Performs the symmetrical transformation of a sphere with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Sphere.def("Mirror", (void (gp_Sphere::*)(const gp_Ax1 &)) &gp_Sphere::Mirror, "None", py::arg("A1"));
cls_gp_Sphere.def("Mirrored", (gp_Sphere (gp_Sphere::*)(const gp_Ax1 &) const) &gp_Sphere::Mirrored, "Performs the symmetrical transformation of a sphere with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Sphere.def("Mirror", (void (gp_Sphere::*)(const gp_Ax2 &)) &gp_Sphere::Mirror, "None", py::arg("A2"));
cls_gp_Sphere.def("Mirrored", (gp_Sphere (gp_Sphere::*)(const gp_Ax2 &) const) &gp_Sphere::Mirrored, "Performs the symmetrical transformation of a sphere with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Sphere.def("Rotate", (void (gp_Sphere::*)(const gp_Ax1 &, const Standard_Real)) &gp_Sphere::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Sphere.def("Rotated", (gp_Sphere (gp_Sphere::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Sphere::Rotated, "Rotates a sphere. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Sphere.def("Scale", (void (gp_Sphere::*)(const gp_Pnt &, const Standard_Real)) &gp_Sphere::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Sphere.def("Scaled", (gp_Sphere (gp_Sphere::*)(const gp_Pnt &, const Standard_Real) const) &gp_Sphere::Scaled, "Scales a sphere. S is the scaling value. The absolute value of S is used to scale the sphere", py::arg("P"), py::arg("S"));
cls_gp_Sphere.def("Transform", (void (gp_Sphere::*)(const gp_Trsf &)) &gp_Sphere::Transform, "None", py::arg("T"));
cls_gp_Sphere.def("Transformed", (gp_Sphere (gp_Sphere::*)(const gp_Trsf &) const) &gp_Sphere::Transformed, "Transforms a sphere with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Sphere.def("Translate", (void (gp_Sphere::*)(const gp_Vec &)) &gp_Sphere::Translate, "None", py::arg("V"));
cls_gp_Sphere.def("Translated", (gp_Sphere (gp_Sphere::*)(const gp_Vec &) const) &gp_Sphere::Translated, "Translates a sphere in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Sphere.def("Translate", (void (gp_Sphere::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Sphere::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Sphere.def("Translated", (gp_Sphere (gp_Sphere::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Sphere::Translated, "Translates a sphere from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_TORUS
py::class_<gp_Torus> cls_gp_Torus(mod, "gp_Torus", "Describes a torus. A torus is defined by its major and minor radii and positioned in space with a coordinate system (a gp_Ax3 object) as follows: - The origin of the coordinate system is the center of the torus; - The surface is obtained by rotating a circle of radius equal to the minor radius of the torus about the 'main Direction' of the coordinate system. This circle is located in the plane defined by the origin, the 'X Direction' and the 'main Direction' of the coordinate system. It is centered on the 'X Axis' of this coordinate system, and located at a distance, from the origin of this coordinate system, equal to the major radius of the torus; - The 'X Direction' and 'Y Direction' define the reference plane of the torus. The coordinate system described above is the 'local coordinate system' of the torus. Note: when a gp_Torus torus is converted into a Geom_ToroidalSurface torus, some implicit properties of its local coordinate system are used explicitly: - its origin, 'X Direction', 'Y Direction' and 'main Direction' are used directly to define the parametric directions on the torus and the origin of the parameters, - its implicit orientation (right-handed or left-handed) gives the orientation (direct, indirect) to the Geom_ToroidalSurface torus. See Also gce_MakeTorus which provides functions for more complex torus constructions Geom_ToroidalSurface which provides additional functions for constructing tori and works, in particular, with the parametric equations of tori.");

// Constructors
cls_gp_Torus.def(py::init<>());
cls_gp_Torus.def(py::init<const gp_Ax3 &, const Standard_Real, const Standard_Real>(), py::arg("A3"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Methods
// cls_gp_Torus.def_static("operator new_", (void * (*)(size_t)) &gp_Torus::operator new, "None", py::arg("theSize"));
// cls_gp_Torus.def_static("operator delete_", (void (*)(void *)) &gp_Torus::operator delete, "None", py::arg("theAddress"));
// cls_gp_Torus.def_static("operator new[]_", (void * (*)(size_t)) &gp_Torus::operator new[], "None", py::arg("theSize"));
// cls_gp_Torus.def_static("operator delete[]_", (void (*)(void *)) &gp_Torus::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Torus.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Torus::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Torus.def_static("operator delete_", (void (*)(void *, void *)) &gp_Torus::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Torus.def("SetAxis", (void (gp_Torus::*)(const gp_Ax1 &)) &gp_Torus::SetAxis, "Modifies this torus, by redefining its local coordinate system so that: - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed). Raises ConstructionError if the direction of A1 is parallel to the 'XDirection' of the coordinate system of the toroidal surface.", py::arg("A1"));
cls_gp_Torus.def("SetLocation", (void (gp_Torus::*)(const gp_Pnt &)) &gp_Torus::SetLocation, "Changes the location of the torus.", py::arg("Loc"));
cls_gp_Torus.def("SetMajorRadius", (void (gp_Torus::*)(const Standard_Real)) &gp_Torus::SetMajorRadius, "Assigns value to the major radius of this torus. Raises ConstructionError if MajorRadius - MinorRadius <= Resolution()", py::arg("MajorRadius"));
cls_gp_Torus.def("SetMinorRadius", (void (gp_Torus::*)(const Standard_Real)) &gp_Torus::SetMinorRadius, "Assigns value to the minor radius of this torus. Raises ConstructionError if MinorRadius < 0.0 or if MajorRadius - MinorRadius <= Resolution from gp.", py::arg("MinorRadius"));
cls_gp_Torus.def("SetPosition", (void (gp_Torus::*)(const gp_Ax3 &)) &gp_Torus::SetPosition, "Changes the local coordinate system of the surface.", py::arg("A3"));
cls_gp_Torus.def("Area", (Standard_Real (gp_Torus::*)() const) &gp_Torus::Area, "Computes the area of the torus.");
cls_gp_Torus.def("UReverse", (void (gp_Torus::*)()) &gp_Torus::UReverse, "Reverses the U parametrization of the torus reversing the YAxis.");
cls_gp_Torus.def("VReverse", (void (gp_Torus::*)()) &gp_Torus::VReverse, "Reverses the V parametrization of the torus reversing the ZAxis.");
cls_gp_Torus.def("Direct", (Standard_Boolean (gp_Torus::*)() const) &gp_Torus::Direct, "returns true if the Ax3, the local coordinate system of this torus, is right handed.");
cls_gp_Torus.def("Axis", (const gp_Ax1 & (gp_Torus::*)() const) &gp_Torus::Axis, "returns the symmetry axis of the torus.");
cls_gp_Torus.def("Coefficients", (void (gp_Torus::*)(TColStd_Array1OfReal &) const) &gp_Torus::Coefficients, "Computes the coefficients of the implicit equation of the surface in the absolute Cartesian coordinate system: Coef(1) * X^4 + Coef(2) * Y^4 + Coef(3) * Z^4 + Coef(4) * X^3 * Y + Coef(5) * X^3 * Z + Coef(6) * Y^3 * X + Coef(7) * Y^3 * Z + Coef(8) * Z^3 * X + Coef(9) * Z^3 * Y + Coef(10) * X^2 * Y^2 + Coef(11) * X^2 * Z^2 + Coef(12) * Y^2 * Z^2 + Coef(13) * X^2 * Y * Z + Coef(14) * X * Y^2 * Z + Coef(15) * X * Y * Z^2 + Coef(16) * X^3 + Coef(17) * Y^3 + Coef(18) * Z^3 + Coef(19) * X^2 * Y + Coef(20) * X^2 * Z + Coef(21) * Y^2 * X + Coef(22) * Y^2 * Z + Coef(23) * Z^2 * X + Coef(24) * Z^2 * Y + Coef(25) * X * Y * Z + Coef(26) * X^2 + Coef(27) * Y^2 + Coef(28) * Z^2 + Coef(29) * X * Y + Coef(30) * X * Z + Coef(31) * Y * Z + Coef(32) * X + Coef(33) * Y + Coef(34) * Z + Coef(35) = 0.0 Raises DimensionError if the length of Coef is lower than 35.", py::arg("Coef"));
cls_gp_Torus.def("Location", (const gp_Pnt & (gp_Torus::*)() const) &gp_Torus::Location, "Returns the Torus's location.");
cls_gp_Torus.def("Position", (const gp_Ax3 & (gp_Torus::*)() const) &gp_Torus::Position, "Returns the local coordinates system of the torus.");
cls_gp_Torus.def("MajorRadius", (Standard_Real (gp_Torus::*)() const) &gp_Torus::MajorRadius, "returns the major radius of the torus.");
cls_gp_Torus.def("MinorRadius", (Standard_Real (gp_Torus::*)() const) &gp_Torus::MinorRadius, "returns the minor radius of the torus.");
cls_gp_Torus.def("Volume", (Standard_Real (gp_Torus::*)() const) &gp_Torus::Volume, "Computes the volume of the torus.");
cls_gp_Torus.def("XAxis", (gp_Ax1 (gp_Torus::*)() const) &gp_Torus::XAxis, "returns the axis X of the torus.");
cls_gp_Torus.def("YAxis", (gp_Ax1 (gp_Torus::*)() const) &gp_Torus::YAxis, "returns the axis Y of the torus.");
cls_gp_Torus.def("Mirror", (void (gp_Torus::*)(const gp_Pnt &)) &gp_Torus::Mirror, "None", py::arg("P"));
cls_gp_Torus.def("Mirrored", (gp_Torus (gp_Torus::*)(const gp_Pnt &) const) &gp_Torus::Mirrored, "Performs the symmetrical transformation of a torus with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Torus.def("Mirror", (void (gp_Torus::*)(const gp_Ax1 &)) &gp_Torus::Mirror, "None", py::arg("A1"));
cls_gp_Torus.def("Mirrored", (gp_Torus (gp_Torus::*)(const gp_Ax1 &) const) &gp_Torus::Mirrored, "Performs the symmetrical transformation of a torus with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Torus.def("Mirror", (void (gp_Torus::*)(const gp_Ax2 &)) &gp_Torus::Mirror, "None", py::arg("A2"));
cls_gp_Torus.def("Mirrored", (gp_Torus (gp_Torus::*)(const gp_Ax2 &) const) &gp_Torus::Mirrored, "Performs the symmetrical transformation of a torus with respect to a plane. The axis placement A2 locates the plane of the of the symmetry : (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Torus.def("Rotate", (void (gp_Torus::*)(const gp_Ax1 &, const Standard_Real)) &gp_Torus::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Torus.def("Rotated", (gp_Torus (gp_Torus::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Torus::Rotated, "Rotates a torus. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Torus.def("Scale", (void (gp_Torus::*)(const gp_Pnt &, const Standard_Real)) &gp_Torus::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Torus.def("Scaled", (gp_Torus (gp_Torus::*)(const gp_Pnt &, const Standard_Real) const) &gp_Torus::Scaled, "Scales a torus. S is the scaling value. The absolute value of S is used to scale the torus", py::arg("P"), py::arg("S"));
cls_gp_Torus.def("Transform", (void (gp_Torus::*)(const gp_Trsf &)) &gp_Torus::Transform, "None", py::arg("T"));
cls_gp_Torus.def("Transformed", (gp_Torus (gp_Torus::*)(const gp_Trsf &) const) &gp_Torus::Transformed, "Transforms a torus with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Torus.def("Translate", (void (gp_Torus::*)(const gp_Vec &)) &gp_Torus::Translate, "None", py::arg("V"));
cls_gp_Torus.def("Translated", (gp_Torus (gp_Torus::*)(const gp_Vec &) const) &gp_Torus::Translated, "Translates a torus in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Torus.def("Translate", (void (gp_Torus::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Torus::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Torus.def("Translated", (gp_Torus (gp_Torus::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Torus::Translated, "Translates a torus from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// CLASS: GP_GTRSF
py::class_<gp_GTrsf> cls_gp_GTrsf(mod, "gp_GTrsf", "Defines a non-persistent transformation in 3D space. This transformation is a general transformation. It can be a Trsf from gp, an affinity, or you can define your own transformation giving the matrix of transformation.");

// Constructors
cls_gp_GTrsf.def(py::init<>());
cls_gp_GTrsf.def(py::init<const gp_Trsf &>(), py::arg("T"));
cls_gp_GTrsf.def(py::init<const gp_Mat &, const gp_XYZ &>(), py::arg("M"), py::arg("V"));

// Methods
// cls_gp_GTrsf.def_static("operator new_", (void * (*)(size_t)) &gp_GTrsf::operator new, "None", py::arg("theSize"));
// cls_gp_GTrsf.def_static("operator delete_", (void (*)(void *)) &gp_GTrsf::operator delete, "None", py::arg("theAddress"));
// cls_gp_GTrsf.def_static("operator new[]_", (void * (*)(size_t)) &gp_GTrsf::operator new[], "None", py::arg("theSize"));
// cls_gp_GTrsf.def_static("operator delete[]_", (void (*)(void *)) &gp_GTrsf::operator delete[], "None", py::arg("theAddress"));
// cls_gp_GTrsf.def_static("operator new_", (void * (*)(size_t, void *)) &gp_GTrsf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_GTrsf.def_static("operator delete_", (void (*)(void *, void *)) &gp_GTrsf::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_GTrsf.def("SetAffinity", (void (gp_GTrsf::*)(const gp_Ax1 &, const Standard_Real)) &gp_GTrsf::SetAffinity, "Changes this transformation into an affinity of ratio Ratio with respect to the axis A1. Note: an affinity is a point-by-point transformation that transforms any point P into a point P' such that if H is the orthogonal projection of P on the axis A1 or the plane A2, the vectors HP and HP' satisfy: HP' = Ratio * HP.", py::arg("A1"), py::arg("Ratio"));
cls_gp_GTrsf.def("SetAffinity", (void (gp_GTrsf::*)(const gp_Ax2 &, const Standard_Real)) &gp_GTrsf::SetAffinity, "Changes this transformation into an affinity of ratio Ratio with respect to the plane defined by the origin, the 'X Direction' and the 'Y Direction' of coordinate system A2. Note: an affinity is a point-by-point transformation that transforms any point P into a point P' such that if H is the orthogonal projection of P on the axis A1 or the plane A2, the vectors HP and HP' satisfy: HP' = Ratio * HP.", py::arg("A2"), py::arg("Ratio"));
cls_gp_GTrsf.def("SetValue", (void (gp_GTrsf::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &gp_GTrsf::SetValue, "Replaces the coefficient (Row, Col) of the matrix representing this transformation by Value. Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 4", py::arg("Row"), py::arg("Col"), py::arg("Value"));
cls_gp_GTrsf.def("SetVectorialPart", (void (gp_GTrsf::*)(const gp_Mat &)) &gp_GTrsf::SetVectorialPart, "Replaces the vectorial part of this transformation by Matrix.", py::arg("Matrix"));
cls_gp_GTrsf.def("SetTranslationPart", (void (gp_GTrsf::*)(const gp_XYZ &)) &gp_GTrsf::SetTranslationPart, "Replaces the translation part of this transformation by the coordinates of the number triple Coord.", py::arg("Coord"));
cls_gp_GTrsf.def("SetTrsf", (void (gp_GTrsf::*)(const gp_Trsf &)) &gp_GTrsf::SetTrsf, "Assigns the vectorial and translation parts of T to this transformation.", py::arg("T"));
cls_gp_GTrsf.def("IsNegative", (Standard_Boolean (gp_GTrsf::*)() const) &gp_GTrsf::IsNegative, "Returns true if the determinant of the vectorial part of this transformation is negative.");
cls_gp_GTrsf.def("IsSingular", (Standard_Boolean (gp_GTrsf::*)() const) &gp_GTrsf::IsSingular, "Returns true if this transformation is singular (and therefore, cannot be inverted). Note: The Gauss LU decomposition is used to invert the transformation matrix. Consequently, the transformation is considered as singular if the largest pivot found is less than or equal to gp::Resolution(). Warning If this transformation is singular, it cannot be inverted.");
cls_gp_GTrsf.def("Form", (gp_TrsfForm (gp_GTrsf::*)() const) &gp_GTrsf::Form, "Returns the nature of the transformation. It can be an identity transformation, a rotation, a translation, a mirror transformation (relative to a point, an axis or a plane), a scaling transformation, a compound transformation or some other type of transformation.");
cls_gp_GTrsf.def("SetForm", (void (gp_GTrsf::*)()) &gp_GTrsf::SetForm, "verify and set the shape of the GTrsf Other or CompoundTrsf Ex : myGTrsf.SetValue(row1,col1,val1); myGTrsf.SetValue(row2,col2,val2); ... myGTrsf.SetForm();");
cls_gp_GTrsf.def("TranslationPart", (const gp_XYZ & (gp_GTrsf::*)() const) &gp_GTrsf::TranslationPart, "Returns the translation part of the GTrsf.");
cls_gp_GTrsf.def("VectorialPart", (const gp_Mat & (gp_GTrsf::*)() const) &gp_GTrsf::VectorialPart, "Computes the vectorial part of the GTrsf. The returned Matrix is a 3*3 matrix.");
cls_gp_GTrsf.def("Value", (Standard_Real (gp_GTrsf::*)(const Standard_Integer, const Standard_Integer) const) &gp_GTrsf::Value, "Returns the coefficients of the global matrix of transformation. Raises OutOfRange if Row < 1 or Row > 3 or Col < 1 or Col > 4", py::arg("Row"), py::arg("Col"));
cls_gp_GTrsf.def("__call__", (Standard_Real (gp_GTrsf::*)(const Standard_Integer, const Standard_Integer) const) &gp_GTrsf::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
cls_gp_GTrsf.def("Invert", (void (gp_GTrsf::*)()) &gp_GTrsf::Invert, "None");
cls_gp_GTrsf.def("Inverted", (gp_GTrsf (gp_GTrsf::*)() const) &gp_GTrsf::Inverted, "Computes the reverse transformation. Raises an exception if the matrix of the transformation is not inversible.");
cls_gp_GTrsf.def("Multiplied", (gp_GTrsf (gp_GTrsf::*)(const gp_GTrsf &) const) &gp_GTrsf::Multiplied, "Computes the transformation composed from T and <me>. In a C++ implementation you can also write Tcomposed = <me> * T. Example : GTrsf T1, T2, Tcomp; ............... //composition : Tcomp = T2.Multiplied(T1); // or (Tcomp = T2 * T1) // transformation of a point XYZ P(10.,3.,4.); XYZ P1(P); Tcomp.Transforms(P1); //using Tcomp XYZ P2(P); T1.Transforms(P2); //using T1 then T2 T2.Transforms(P2); // P1 = P2 !!!", py::arg("T"));
cls_gp_GTrsf.def("__mul__", (gp_GTrsf (gp_GTrsf::*)(const gp_GTrsf &) const) &gp_GTrsf::operator*, py::is_operator(), "None", py::arg("T"));
cls_gp_GTrsf.def("Multiply", (void (gp_GTrsf::*)(const gp_GTrsf &)) &gp_GTrsf::Multiply, "Computes the transformation composed with <me> and T. <me> = <me> * T", py::arg("T"));
cls_gp_GTrsf.def("__imul__", (void (gp_GTrsf::*)(const gp_GTrsf &)) &gp_GTrsf::operator*=, py::is_operator(), "None", py::arg("T"));
cls_gp_GTrsf.def("PreMultiply", (void (gp_GTrsf::*)(const gp_GTrsf &)) &gp_GTrsf::PreMultiply, "Computes the product of the transformation T and this transformation and assigns the result to this transformation. this = T * this", py::arg("T"));
cls_gp_GTrsf.def("Power", (void (gp_GTrsf::*)(const Standard_Integer)) &gp_GTrsf::Power, "None", py::arg("N"));
cls_gp_GTrsf.def("Powered", (gp_GTrsf (gp_GTrsf::*)(const Standard_Integer) const) &gp_GTrsf::Powered, "Computes: - the product of this transformation multiplied by itself N times, if N is positive, or - the product of the inverse of this transformation multiplied by itself |N| times, if N is negative. If N equals zero, the result is equal to the Identity transformation. I.e.: <me> * <me> * .......* <me>, N time. if N =0 <me> = Identity if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().", py::arg("N"));
cls_gp_GTrsf.def("Transforms", (void (gp_GTrsf::*)(gp_XYZ &) const) &gp_GTrsf::Transforms, "None", py::arg("Coord"));
cls_gp_GTrsf.def("Transforms", [](gp_GTrsf &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Transforms(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Transforms a triplet XYZ with a GTrsf.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_gp_GTrsf.def("Trsf", (gp_Trsf (gp_GTrsf::*)() const) &gp_GTrsf::Trsf, "None");

// CLASS: GP_QUATERNION
py::class_<gp_Quaternion> cls_gp_Quaternion(mod, "gp_Quaternion", "Represents operation of rotation in 3d space as queternion and implements operations with rotations basing on quaternion mathematics.");

// Constructors
cls_gp_Quaternion.def(py::init<>());
cls_gp_Quaternion.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_gp_Quaternion.def(py::init<const gp_Quaternion &>(), py::arg("theToCopy"));
cls_gp_Quaternion.def(py::init<const gp_Vec &, const gp_Vec &>(), py::arg("theVecFrom"), py::arg("theVecTo"));
cls_gp_Quaternion.def(py::init<const gp_Vec &, const gp_Vec &, const gp_Vec &>(), py::arg("theVecFrom"), py::arg("theVecTo"), py::arg("theHelpCrossVec"));
cls_gp_Quaternion.def(py::init<const gp_Vec &, const Standard_Real>(), py::arg("theAxis"), py::arg("theAngle"));
cls_gp_Quaternion.def(py::init<const gp_Mat &>(), py::arg("theMat"));

// Methods
// cls_gp_Quaternion.def_static("operator new_", (void * (*)(size_t)) &gp_Quaternion::operator new, "None", py::arg("theSize"));
// cls_gp_Quaternion.def_static("operator delete_", (void (*)(void *)) &gp_Quaternion::operator delete, "None", py::arg("theAddress"));
// cls_gp_Quaternion.def_static("operator new[]_", (void * (*)(size_t)) &gp_Quaternion::operator new[], "None", py::arg("theSize"));
// cls_gp_Quaternion.def_static("operator delete[]_", (void (*)(void *)) &gp_Quaternion::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Quaternion.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Quaternion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Quaternion.def_static("operator delete_", (void (*)(void *, void *)) &gp_Quaternion::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Quaternion.def("IsEqual", (Standard_Boolean (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::IsEqual, "Simple equal test without precision", py::arg("theOther"));
cls_gp_Quaternion.def("SetRotation", (void (gp_Quaternion::*)(const gp_Vec &, const gp_Vec &)) &gp_Quaternion::SetRotation, "Sets quaternion to shortest-arc rotation producing vector theVecTo from vector theVecFrom. If vectors theVecFrom and theVecTo are opposite then rotation axis is computed as theVecFrom ^ (1,0,0) or theVecFrom ^ (0,0,1).", py::arg("theVecFrom"), py::arg("theVecTo"));
cls_gp_Quaternion.def("SetRotation", (void (gp_Quaternion::*)(const gp_Vec &, const gp_Vec &, const gp_Vec &)) &gp_Quaternion::SetRotation, "Sets quaternion to shortest-arc rotation producing vector theVecTo from vector theVecFrom. If vectors theVecFrom and theVecTo are opposite then rotation axis is computed as theVecFrom ^ theHelpCrossVec.", py::arg("theVecFrom"), py::arg("theVecTo"), py::arg("theHelpCrossVec"));
cls_gp_Quaternion.def("SetVectorAndAngle", (void (gp_Quaternion::*)(const gp_Vec &, const Standard_Real)) &gp_Quaternion::SetVectorAndAngle, "Create a unit quaternion from Axis+Angle representation", py::arg("theAxis"), py::arg("theAngle"));
cls_gp_Quaternion.def("GetVectorAndAngle", [](gp_Quaternion &self, gp_Vec & theAxis, Standard_Real & theAngle){ self.GetVectorAndAngle(theAxis, theAngle); return theAngle; }, "Convert a quaternion to Axis+Angle representation, preserve the axis direction and angle from -PI to +PI", py::arg("theAxis"), py::arg("theAngle"));
cls_gp_Quaternion.def("SetMatrix", (void (gp_Quaternion::*)(const gp_Mat &)) &gp_Quaternion::SetMatrix, "Create a unit quaternion by rotation matrix matrix must contain only rotation (not scale or shear)", py::arg("theMat"));
cls_gp_Quaternion.def("GetMatrix", (gp_Mat (gp_Quaternion::*)() const) &gp_Quaternion::GetMatrix, "Returns rotation operation as 3*3 matrix");
cls_gp_Quaternion.def("SetEulerAngles", (void (gp_Quaternion::*)(const gp_EulerSequence, const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Quaternion::SetEulerAngles, "Create a unit quaternion representing rotation defined by generalized Euler angles", py::arg("theOrder"), py::arg("theAlpha"), py::arg("theBeta"), py::arg("theGamma"));
cls_gp_Quaternion.def("GetEulerAngles", [](gp_Quaternion &self, const gp_EulerSequence theOrder, Standard_Real & theAlpha, Standard_Real & theBeta, Standard_Real & theGamma){ self.GetEulerAngles(theOrder, theAlpha, theBeta, theGamma); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theAlpha, theBeta, theGamma); }, "Returns Euler angles describing current rotation", py::arg("theOrder"), py::arg("theAlpha"), py::arg("theBeta"), py::arg("theGamma"));
cls_gp_Quaternion.def("Set", (void (gp_Quaternion::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Quaternion::Set, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_gp_Quaternion.def("Set", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::Set, "None", py::arg("theQuaternion"));
cls_gp_Quaternion.def("X", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::X, "None");
cls_gp_Quaternion.def("Y", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::Y, "None");
cls_gp_Quaternion.def("Z", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::Z, "None");
cls_gp_Quaternion.def("W", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::W, "None");
cls_gp_Quaternion.def("SetIdent", (void (gp_Quaternion::*)()) &gp_Quaternion::SetIdent, "Make identity quaternion (zero-rotation)");
cls_gp_Quaternion.def("Reverse", (void (gp_Quaternion::*)()) &gp_Quaternion::Reverse, "Reverse direction of rotation (conjugate quaternion)");
cls_gp_Quaternion.def("Reversed", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::Reversed, "Return rotation with reversed direction (conjugated quaternion)");
cls_gp_Quaternion.def("Invert", (void (gp_Quaternion::*)()) &gp_Quaternion::Invert, "Inverts quaternion (both rotation direction and norm)");
cls_gp_Quaternion.def("Inverted", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::Inverted, "Return inversed quaternion q^-1");
cls_gp_Quaternion.def("SquareNorm", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::SquareNorm, "Returns square norm of quaternion");
cls_gp_Quaternion.def("Norm", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::Norm, "Returns norm of quaternion");
cls_gp_Quaternion.def("Scale", (void (gp_Quaternion::*)(const Standard_Real)) &gp_Quaternion::Scale, "Scale all components by quaternion by theScale; note that rotation is not changed by this operation (except 0-scaling)", py::arg("theScale"));
cls_gp_Quaternion.def("__imul__", (void (gp_Quaternion::*)(const Standard_Real)) &gp_Quaternion::operator*=, py::is_operator(), "None", py::arg("theScale"));
cls_gp_Quaternion.def("Scaled", (gp_Quaternion (gp_Quaternion::*)(const Standard_Real) const) &gp_Quaternion::Scaled, "Returns scaled quaternion", py::arg("theScale"));
cls_gp_Quaternion.def("__mul__", (gp_Quaternion (gp_Quaternion::*)(const Standard_Real) const) &gp_Quaternion::operator*, py::is_operator(), "None", py::arg("theScale"));
cls_gp_Quaternion.def("StabilizeLength", (void (gp_Quaternion::*)()) &gp_Quaternion::StabilizeLength, "Stabilize quaternion length within 1 - 1/4. This operation is a lot faster than normalization and preserve length goes to 0 or infinity");
cls_gp_Quaternion.def("Normalize", (void (gp_Quaternion::*)()) &gp_Quaternion::Normalize, "Scale quaternion that its norm goes to 1. The appearing of 0 magnitude or near is a error, so we can be sure that can divide by magnitude");
cls_gp_Quaternion.def("Normalized", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::Normalized, "Returns quaternion scaled so that its norm goes to 1.");
cls_gp_Quaternion.def("Negated", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::Negated, "Returns quaternion with all components negated. Note that this operation does not affect neither rotation operator defined by quaternion nor its norm.");
cls_gp_Quaternion.def("__sub__", (gp_Quaternion (gp_Quaternion::*)() const) &gp_Quaternion::operator-, py::is_operator(), "None");
cls_gp_Quaternion.def("Added", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::Added, "Makes sum of quaternion components; result is 'rotations mix'", py::arg("theOther"));
cls_gp_Quaternion.def("__add__", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::operator+, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Subtracted", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::Subtracted, "Makes difference of quaternion components; result is 'rotations mix'", py::arg("theOther"));
cls_gp_Quaternion.def("__sub__", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::operator-, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Multiplied", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::Multiplied, "Multiply function - work the same as Matrices multiplying. qq' = (cross(v,v') + wv' + w'v, ww' - dot(v,v')) Result is rotation combination: q' than q (here q=this, q'=theQ). Notices than: qq' != q'q; qq^-1 = q;", py::arg("theOther"));
cls_gp_Quaternion.def("__mul__", (gp_Quaternion (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::operator*, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Add", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::Add, "Adds componnets of other quaternion; result is 'rotations mix'", py::arg("theOther"));
cls_gp_Quaternion.def("__iadd__", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::operator+=, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Subtract", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::Subtract, "Subtracts componnets of other quaternion; result is 'rotations mix'", py::arg("theOther"));
cls_gp_Quaternion.def("__isub__", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::operator-=, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Multiply", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::Multiply, "Adds rotation by multiplication", py::arg("theOther"));
cls_gp_Quaternion.def("__imul__", (void (gp_Quaternion::*)(const gp_Quaternion &)) &gp_Quaternion::operator*=, py::is_operator(), "None", py::arg("theOther"));
cls_gp_Quaternion.def("Dot", (Standard_Real (gp_Quaternion::*)(const gp_Quaternion &) const) &gp_Quaternion::Dot, "Computes inner product / scalar product / Dot", py::arg("theOther"));
cls_gp_Quaternion.def("GetRotationAngle", (Standard_Real (gp_Quaternion::*)() const) &gp_Quaternion::GetRotationAngle, "Return rotation angle from -PI to PI");
cls_gp_Quaternion.def("Multiply", (gp_Vec (gp_Quaternion::*)(const gp_Vec &) const) &gp_Quaternion::Multiply, "Rotates vector by quaternion as rotation operator", py::arg("theVec"));
cls_gp_Quaternion.def("__mul__", (gp_Vec (gp_Quaternion::*)(const gp_Vec &) const) &gp_Quaternion::operator*, py::is_operator(), "None", py::arg("theVec"));

// CLASS: GP_QUATERNIONNLERP
py::class_<gp_QuaternionNLerp> cls_gp_QuaternionNLerp(mod, "gp_QuaternionNLerp", "Class perform linear interpolation (approximate rotation interpolation), result quaternion nonunit, its length lay between. sqrt(2)/2 and 1.0");

// Constructors
cls_gp_QuaternionNLerp.def(py::init<>());
cls_gp_QuaternionNLerp.def(py::init<const gp_Quaternion &, const gp_Quaternion &>(), py::arg("theQStart"), py::arg("theQEnd"));

// Methods
cls_gp_QuaternionNLerp.def_static("Interpolate_", (gp_Quaternion (*)(const gp_Quaternion &, const gp_Quaternion &, Standard_Real)) &gp_QuaternionNLerp::Interpolate, "Compute interpolated quaternion between two quaternions.", py::arg("theQStart"), py::arg("theQEnd"), py::arg("theT"));
cls_gp_QuaternionNLerp.def("Init", (void (gp_QuaternionNLerp::*)(const gp_Quaternion &, const gp_Quaternion &)) &gp_QuaternionNLerp::Init, "Initialize the tool with Start and End values.", py::arg("theQStart"), py::arg("theQEnd"));
cls_gp_QuaternionNLerp.def("InitFromUnit", (void (gp_QuaternionNLerp::*)(const gp_Quaternion &, const gp_Quaternion &)) &gp_QuaternionNLerp::InitFromUnit, "Initialize the tool with Start and End unit quaternions.", py::arg("theQStart"), py::arg("theQEnd"));
cls_gp_QuaternionNLerp.def("Interpolate", (void (gp_QuaternionNLerp::*)(Standard_Real, gp_Quaternion &) const) &gp_QuaternionNLerp::Interpolate, "Set interpolated quaternion for theT position (from 0.0 to 1.0)", py::arg("theT"), py::arg("theResultQ"));

// CLASS: NCOLLECTION_LERP
py::class_<NCollection_Lerp<gp_Trsf>> cls_NCollection_Lerp(mod, "gp_TrsfNLerp", "Linear interpolation tool for transformation defined by gp_Trsf.");

// Constructors
cls_NCollection_Lerp.def(py::init<>());
cls_NCollection_Lerp.def(py::init<const gp_Trsf &, const gp_Trsf &>(), py::arg("theStart"), py::arg("theEnd"));

// Methods
cls_NCollection_Lerp.def("Init", (void (NCollection_Lerp<gp_Trsf>::*)(const gp_Trsf &, const gp_Trsf &)) &NCollection_Lerp<gp_Trsf>::Init, "Initialize values.", py::arg("theStart"), py::arg("theEnd"));
cls_NCollection_Lerp.def("Interpolate", (void (NCollection_Lerp<gp_Trsf>::*)(double, gp_Trsf &) const) &NCollection_Lerp<gp_Trsf>::Interpolate, "Compute interpolated value between two values.", py::arg("theT"), py::arg("theResult"));

// TYPEDEF: GP_TRSFNLERP
/*
if (py::hasattr(mod, "NCollection_Lerp")) {
	mod.attr("gp_TrsfNLerp") = mod.attr("NCollection_Lerp");
}
*/

// CLASS: GP_GTRSF2D
py::class_<gp_GTrsf2d> cls_gp_GTrsf2d(mod, "gp_GTrsf2d", "Defines a non persistent transformation in 2D space. This transformation is a general transformation. It can be a Trsf2d from package gp, an affinity, or you can define your own transformation giving the corresponding matrix of transformation.");

// Constructors
cls_gp_GTrsf2d.def(py::init<>());
cls_gp_GTrsf2d.def(py::init<const gp_Trsf2d &>(), py::arg("T"));
cls_gp_GTrsf2d.def(py::init<const gp_Mat2d &, const gp_XY &>(), py::arg("M"), py::arg("V"));

// Methods
// cls_gp_GTrsf2d.def_static("operator new_", (void * (*)(size_t)) &gp_GTrsf2d::operator new, "None", py::arg("theSize"));
// cls_gp_GTrsf2d.def_static("operator delete_", (void (*)(void *)) &gp_GTrsf2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_GTrsf2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_GTrsf2d::operator new[], "None", py::arg("theSize"));
// cls_gp_GTrsf2d.def_static("operator delete[]_", (void (*)(void *)) &gp_GTrsf2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_GTrsf2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_GTrsf2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_GTrsf2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_GTrsf2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_GTrsf2d.def("SetAffinity", (void (gp_GTrsf2d::*)(const gp_Ax2d &, const Standard_Real)) &gp_GTrsf2d::SetAffinity, "Changes this transformation into an affinity of ratio Ratio with respect to the axis A. Note: An affinity is a point-by-point transformation that transforms any point P into a point P' such that if H is the orthogonal projection of P on the axis A, the vectors HP and HP' satisfy: HP' = Ratio * HP.", py::arg("A"), py::arg("Ratio"));
cls_gp_GTrsf2d.def("SetValue", (void (gp_GTrsf2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &gp_GTrsf2d::SetValue, "Replaces the coefficient (Row, Col) of the matrix representing this transformation by Value, Raises OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3", py::arg("Row"), py::arg("Col"), py::arg("Value"));
cls_gp_GTrsf2d.def("SetTranslationPart", (void (gp_GTrsf2d::*)(const gp_XY &)) &gp_GTrsf2d::SetTranslationPart, "Replacesthe translation part of this transformation by the coordinates of the number pair Coord.", py::arg("Coord"));
cls_gp_GTrsf2d.def("SetTrsf2d", (void (gp_GTrsf2d::*)(const gp_Trsf2d &)) &gp_GTrsf2d::SetTrsf2d, "Assigns the vectorial and translation parts of T to this transformation.", py::arg("T"));
cls_gp_GTrsf2d.def("SetVectorialPart", (void (gp_GTrsf2d::*)(const gp_Mat2d &)) &gp_GTrsf2d::SetVectorialPart, "Replaces the vectorial part of this transformation by Matrix.", py::arg("Matrix"));
cls_gp_GTrsf2d.def("IsNegative", (Standard_Boolean (gp_GTrsf2d::*)() const) &gp_GTrsf2d::IsNegative, "Returns true if the determinant of the vectorial part of this transformation is negative.");
cls_gp_GTrsf2d.def("IsSingular", (Standard_Boolean (gp_GTrsf2d::*)() const) &gp_GTrsf2d::IsSingular, "Returns true if this transformation is singular (and therefore, cannot be inverted). Note: The Gauss LU decomposition is used to invert the transformation matrix. Consequently, the transformation is considered as singular if the largest pivot found is less than or equal to gp::Resolution(). Warning If this transformation is singular, it cannot be inverted.");
cls_gp_GTrsf2d.def("Form", (gp_TrsfForm (gp_GTrsf2d::*)() const) &gp_GTrsf2d::Form, "Returns the nature of the transformation. It can be an identity transformation, a rotation, a translation, a mirror transformation (relative to a point or axis), a scaling transformation, a compound transformation or some other type of transformation.");
cls_gp_GTrsf2d.def("TranslationPart", (const gp_XY & (gp_GTrsf2d::*)() const) &gp_GTrsf2d::TranslationPart, "Returns the translation part of the GTrsf2d.");
cls_gp_GTrsf2d.def("VectorialPart", (const gp_Mat2d & (gp_GTrsf2d::*)() const) &gp_GTrsf2d::VectorialPart, "Computes the vectorial part of the GTrsf2d. The returned Matrix is a 2*2 matrix.");
cls_gp_GTrsf2d.def("Value", (Standard_Real (gp_GTrsf2d::*)(const Standard_Integer, const Standard_Integer) const) &gp_GTrsf2d::Value, "Returns the coefficients of the global matrix of transformation. Raised OutOfRange if Row < 1 or Row > 2 or Col < 1 or Col > 3", py::arg("Row"), py::arg("Col"));
cls_gp_GTrsf2d.def("__call__", (Standard_Real (gp_GTrsf2d::*)(const Standard_Integer, const Standard_Integer) const) &gp_GTrsf2d::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
cls_gp_GTrsf2d.def("Invert", (void (gp_GTrsf2d::*)()) &gp_GTrsf2d::Invert, "None");
cls_gp_GTrsf2d.def("Inverted", (gp_GTrsf2d (gp_GTrsf2d::*)() const) &gp_GTrsf2d::Inverted, "Computes the reverse transformation. Raised an exception if the matrix of the transformation is not inversible.");
cls_gp_GTrsf2d.def("Multiplied", (gp_GTrsf2d (gp_GTrsf2d::*)(const gp_GTrsf2d &) const) &gp_GTrsf2d::Multiplied, "Computes the transformation composed with T and <me>. In a C++ implementation you can also write Tcomposed = <me> * T. Example : GTrsf2d T1, T2, Tcomp; ............... //composition : Tcomp = T2.Multiplied(T1); // or (Tcomp = T2 * T1) // transformation of a point XY P(10.,3.); XY P1(P); Tcomp.Transforms(P1); //using Tcomp XY P2(P); T1.Transforms(P2); //using T1 then T2 T2.Transforms(P2); // P1 = P2 !!!", py::arg("T"));
cls_gp_GTrsf2d.def("__mul__", (gp_GTrsf2d (gp_GTrsf2d::*)(const gp_GTrsf2d &) const) &gp_GTrsf2d::operator*, py::is_operator(), "None", py::arg("T"));
cls_gp_GTrsf2d.def("Multiply", (void (gp_GTrsf2d::*)(const gp_GTrsf2d &)) &gp_GTrsf2d::Multiply, "None", py::arg("T"));
cls_gp_GTrsf2d.def("__imul__", (void (gp_GTrsf2d::*)(const gp_GTrsf2d &)) &gp_GTrsf2d::operator*=, py::is_operator(), "None", py::arg("T"));
cls_gp_GTrsf2d.def("PreMultiply", (void (gp_GTrsf2d::*)(const gp_GTrsf2d &)) &gp_GTrsf2d::PreMultiply, "Computes the product of the transformation T and this transformation, and assigns the result to this transformation: this = T * this", py::arg("T"));
cls_gp_GTrsf2d.def("Power", (void (gp_GTrsf2d::*)(const Standard_Integer)) &gp_GTrsf2d::Power, "None", py::arg("N"));
cls_gp_GTrsf2d.def("Powered", (gp_GTrsf2d (gp_GTrsf2d::*)(const Standard_Integer) const) &gp_GTrsf2d::Powered, "Computes the following composition of transformations <me> * <me> * .......* <me>, N time. if N = 0 <me> = Identity if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().", py::arg("N"));
cls_gp_GTrsf2d.def("Transforms", (void (gp_GTrsf2d::*)(gp_XY &) const) &gp_GTrsf2d::Transforms, "None", py::arg("Coord"));
cls_gp_GTrsf2d.def("Transformed", (gp_XY (gp_GTrsf2d::*)(const gp_XY &) const) &gp_GTrsf2d::Transformed, "None", py::arg("Coord"));
cls_gp_GTrsf2d.def("Transforms", [](gp_GTrsf2d &self, Standard_Real & X, Standard_Real & Y){ self.Transforms(X, Y); return std::tuple<Standard_Real &, Standard_Real &>(X, Y); }, "Applies this transformation to the coordinates: - of the number pair Coord, or - X and Y.", py::arg("X"), py::arg("Y"));
cls_gp_GTrsf2d.def("Trsf2d", (gp_Trsf2d (gp_GTrsf2d::*)() const) &gp_GTrsf2d::Trsf2d, "Converts this transformation into a gp_Trsf2d transformation. Exceptions Standard_ConstructionError if this transformation cannot be converted, i.e. if its form is gp_Other.");

// CLASS: GP_QUATERNIONSLERP
py::class_<gp_QuaternionSLerp> cls_gp_QuaternionSLerp(mod, "gp_QuaternionSLerp", "Perform Spherical Linear Interpolation of the quaternions, return unit length quaternion.");

// Constructors
cls_gp_QuaternionSLerp.def(py::init<>());
cls_gp_QuaternionSLerp.def(py::init<const gp_Quaternion &, const gp_Quaternion &>(), py::arg("theQStart"), py::arg("theQEnd"));

// Methods
cls_gp_QuaternionSLerp.def_static("Interpolate_", (gp_Quaternion (*)(const gp_Quaternion &, const gp_Quaternion &, Standard_Real)) &gp_QuaternionSLerp::Interpolate, "Compute interpolated quaternion between two quaternions.", py::arg("theQStart"), py::arg("theQEnd"), py::arg("theT"));
cls_gp_QuaternionSLerp.def("Init", (void (gp_QuaternionSLerp::*)(const gp_Quaternion &, const gp_Quaternion &)) &gp_QuaternionSLerp::Init, "Initialize the tool with Start and End values.", py::arg("theQStart"), py::arg("theQEnd"));
cls_gp_QuaternionSLerp.def("InitFromUnit", (void (gp_QuaternionSLerp::*)(const gp_Quaternion &, const gp_Quaternion &)) &gp_QuaternionSLerp::InitFromUnit, "Initialize the tool with Start and End unit quaternions.", py::arg("theQStart"), py::arg("theQEnd"));
cls_gp_QuaternionSLerp.def("Interpolate", (void (gp_QuaternionSLerp::*)(Standard_Real, gp_Quaternion &) const) &gp_QuaternionSLerp::Interpolate, "Set interpolated quaternion for theT position (from 0.0 to 1.0)", py::arg("theT"), py::arg("theResultQ"));


}
