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
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Mat2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_GTrsf2d.hxx>

void bind_gp_Mat2d(py::module &mod){

py::class_<gp_Mat2d, std::unique_ptr<gp_Mat2d, Deleter<gp_Mat2d>>> cls_gp_Mat2d(mod, "gp_Mat2d", "Describes a two column, two row matrix. This sort of object is used in various vectorial or matrix computations.");

// Constructors
cls_gp_Mat2d.def(py::init<>());
cls_gp_Mat2d.def(py::init<const gp_XY &, const gp_XY &>(), py::arg("Col1"), py::arg("Col2"));

// Fields

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

// Enums

}