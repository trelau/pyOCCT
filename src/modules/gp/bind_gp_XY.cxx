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
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <gp_Mat2d.hxx>

void bind_gp_XY(py::module &mod){

py::class_<gp_XY, std::unique_ptr<gp_XY>> cls_gp_XY(mod, "gp_XY", "This class describes a cartesian coordinate entity in 2D space {X,Y}. This class is non persistent. This entity used for algebraic calculation. An XY can be transformed with a Trsf2d or a GTrsf2d from package gp. It is used in vectorial computations or for holding this type of information in data structures.");

// Constructors
cls_gp_XY.def(py::init<>());
cls_gp_XY.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"));

// Fields

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

// Enums

}