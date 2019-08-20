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
#include <gp_XYZ.hxx>
#include <gp_Mat.hxx>

void bind_gp_XYZ(py::module &mod){

py::class_<gp_XYZ, std::unique_ptr<gp_XYZ>> cls_gp_XYZ(mod, "gp_XYZ", "This class describes a cartesian coordinate entity in 3D space {X,Y,Z}. This entity is used for algebraic calculation. This entity can be transformed with a 'Trsf' or a 'GTrsf' from package 'gp'. It is used in vectorial computations or for holding this type of information in data structures.");

// Constructors
cls_gp_XYZ.def(py::init<>());
cls_gp_XYZ.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("X"), py::arg("Y"), py::arg("Z"));

// Fields

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

// Enums

}