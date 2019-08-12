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
#include <gp_Trsf.hxx>
#include <gp_GTrsf.hxx>

void bind_gp_Mat(py::module &mod){

py::class_<gp_Mat, std::unique_ptr<gp_Mat, Deleter<gp_Mat>>> cls_gp_Mat(mod, "gp_Mat", "Describes a three column, three row matrix. This sort of object is used in various vectorial or matrix computations.");

// Constructors
cls_gp_Mat.def(py::init<>());
cls_gp_Mat.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("a11"), py::arg("a12"), py::arg("a13"), py::arg("a21"), py::arg("a22"), py::arg("a23"), py::arg("a31"), py::arg("a32"), py::arg("a33"));
cls_gp_Mat.def(py::init<const gp_XYZ &, const gp_XYZ &, const gp_XYZ &>(), py::arg("Col1"), py::arg("Col2"), py::arg("Col3"));

// Fields

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

// Enums

}