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
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <Standard_OStream.hxx>
#include <math_DoubleTab.hxx>

void bind_math_Matrix(py::module &mod){

py::class_<math_Matrix> cls_math_Matrix(mod, "math_Matrix", "This class implements the real matrix abstract data type. Matrixes can have an arbitrary range which must be defined at the declaration and cannot be changed after this declaration math_Matrix(-3,5,2,4); //a vector with range [-3..5, 2..4] Matrix values may be initialized and retrieved using indexes which must lie within the range of definition of the matrix. Matrix objects follow 'value semantics', that is, they cannot be shared and are copied through assignment Matrices are copied through assignement: math_Matrix M2(1, 9, 1, 3); ... M2 = M1; M1(1) = 2.0;//the matrix M2 will not be modified.");

// Constructors
cls_math_Matrix.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"));
cls_math_Matrix.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"), py::arg("InitialValue"));
cls_math_Matrix.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Tab"), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"));
cls_math_Matrix.def(py::init<const math_Matrix &>(), py::arg("Other"));

// Fields

// Methods
// cls_math_Matrix.def_static("operator new_", (void * (*)(size_t)) &math_Matrix::operator new, "None", py::arg("theSize"));
// cls_math_Matrix.def_static("operator delete_", (void (*)(void *)) &math_Matrix::operator delete, "None", py::arg("theAddress"));
// cls_math_Matrix.def_static("operator new[]_", (void * (*)(size_t)) &math_Matrix::operator new[], "None", py::arg("theSize"));
// cls_math_Matrix.def_static("operator delete[]_", (void (*)(void *)) &math_Matrix::operator delete[], "None", py::arg("theAddress"));
// cls_math_Matrix.def_static("operator new_", (void * (*)(size_t, void *)) &math_Matrix::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_Matrix.def_static("operator delete_", (void (*)(void *, void *)) &math_Matrix::operator delete, "None", py::arg(""), py::arg(""));
cls_math_Matrix.def("Init", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::Init, "Initialize all the elements of a matrix to InitialValue.", py::arg("InitialValue"));
cls_math_Matrix.def("RowNumber", (Standard_Integer (math_Matrix::*)() const) &math_Matrix::RowNumber, "Returns the number of rows of this matrix. Note that for a matrix A you always have the following relations: - A.RowNumber() = A.UpperRow() - A.LowerRow() + 1 - A.ColNumber() = A.UpperCol() - A.LowerCol() + 1 - the length of a row of A is equal to the number of columns of A, - the length of a column of A is equal to the number of rows of A.returns the row range of a matrix.");
cls_math_Matrix.def("ColNumber", (Standard_Integer (math_Matrix::*)() const) &math_Matrix::ColNumber, "Returns the number of rows of this matrix. Note that for a matrix A you always have the following relations: - A.RowNumber() = A.UpperRow() - A.LowerRow() + 1 - A.ColNumber() = A.UpperCol() - A.LowerCol() + 1 - the length of a row of A is equal to the number of columns of A, - the length of a column of A is equal to the number of rows of A.returns the row range of a matrix.");
cls_math_Matrix.def("LowerRow", (Standard_Integer (math_Matrix::*)() const) &math_Matrix::LowerRow, "Returns the value of the Lower index of the row range of a matrix.");
cls_math_Matrix.def("UpperRow", (Standard_Integer (math_Matrix::*)() const) &math_Matrix::UpperRow, "Returns the Upper index of the row range of a matrix.");
cls_math_Matrix.def("LowerCol", (Standard_Integer (math_Matrix::*)() const) &math_Matrix::LowerCol, "Returns the value of the Lower index of the column range of a matrix.");
cls_math_Matrix.def("UpperCol", (Standard_Integer (math_Matrix::*)() const) &math_Matrix::UpperCol, "Returns the value of the upper index of the column range of a matrix.");
cls_math_Matrix.def("Determinant", (Standard_Real (math_Matrix::*)() const) &math_Matrix::Determinant, "Computes the determinant of a matrix. An exception is raised if the matrix is not a square matrix.");
cls_math_Matrix.def("Transpose", (void (math_Matrix::*)()) &math_Matrix::Transpose, "Transposes a given matrix. An exception is raised if the matrix is not a square matrix.");
cls_math_Matrix.def("Invert", (void (math_Matrix::*)()) &math_Matrix::Invert, "Inverts a matrix using Gauss algorithm. Exception NotSquare is raised if the matrix is not square. Exception SingularMatrix is raised if the matrix is singular.");
cls_math_Matrix.def("Multiply", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::Multiply, "Sets this matrix to the product of the matrix Left, and the matrix Right. Example math_Matrix A (1, 3, 1, 3); math_Matrix B (1, 3, 1, 3); // A = ... , B = ... math_Matrix C (1, 3, 1, 3); C.Multiply(A, B); Exceptions Standard_DimensionError if matrices are of incompatible dimensions, i.e. if: - the number of columns of matrix Left, or the number of rows of matrix TLeft is not equal to the number of rows of matrix Right, or - the number of rows of matrix Left, or the number of columns of matrix TLeft is not equal to the number of rows of this matrix, or - the number of columns of matrix Right is not equal to the number of columns of this matrix.", py::arg("Right"));
cls_math_Matrix.def("__imul__", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::operator*=, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Multiplied", (math_Matrix (math_Matrix::*)(const Standard_Real) const) &math_Matrix::Multiplied, "multiplies all the elements of a matrix by the value <Right>.", py::arg("Right"));
cls_math_Matrix.def("__mul__", (math_Matrix (math_Matrix::*)(const Standard_Real) const) &math_Matrix::operator*, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("TMultiplied", (math_Matrix (math_Matrix::*)(const Standard_Real) const) &math_Matrix::TMultiplied, "Sets this matrix to the product of the transposed matrix TLeft, and the matrix Right. Example math_Matrix A (1, 3, 1, 3); math_Matrix B (1, 3, 1, 3); // A = ... , B = ... math_Matrix C (1, 3, 1, 3); C.Multiply(A, B); Exceptions Standard_DimensionError if matrices are of incompatible dimensions, i.e. if: - the number of columns of matrix Left, or the number of rows of matrix TLeft is not equal to the number of rows of matrix Right, or - the number of rows of matrix Left, or the number of columns of matrix TLeft is not equal to the number of rows of this matrix, or - the number of columns of matrix Right is not equal to the number of columns of this matrix.", py::arg("Right"));
cls_math_Matrix.def("Divide", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::Divide, "divides all the elements of a matrix by the value <Right>. An exception is raised if <Right> = 0.", py::arg("Right"));
cls_math_Matrix.def("__itruediv__", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::operator/=, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Divided", (math_Matrix (math_Matrix::*)(const Standard_Real) const) &math_Matrix::Divided, "divides all the elements of a matrix by the value <Right>. An exception is raised if <Right> = 0.", py::arg("Right"));
cls_math_Matrix.def("__truediv__", (math_Matrix (math_Matrix::*)(const Standard_Real) const) &math_Matrix::operator/, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Add", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::Add, "adds the matrix <Right> to a matrix. An exception is raised if the dimensions are different. Warning In order to save time when copying matrices, it is preferable to use operator += or the function Add whenever possible.", py::arg("Right"));
cls_math_Matrix.def("__iadd__", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::operator+=, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Added", (math_Matrix (math_Matrix::*)(const math_Matrix &) const) &math_Matrix::Added, "adds the matrix <Right> to a matrix. An exception is raised if the dimensions are different.", py::arg("Right"));
cls_math_Matrix.def("__add__", (math_Matrix (math_Matrix::*)(const math_Matrix &) const) &math_Matrix::operator+, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Add", (void (math_Matrix::*)(const math_Matrix &, const math_Matrix &)) &math_Matrix::Add, "sets a matrix to the addition of <Left> and <Right>. An exception is raised if the dimensions are different.", py::arg("Left"), py::arg("Right"));
cls_math_Matrix.def("Subtract", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::Subtract, "Subtracts the matrix <Right> from <me>. An exception is raised if the dimensions are different. Warning In order to avoid time-consuming copying of matrices, it is preferable to use operator -= or the function Subtract whenever possible.", py::arg("Right"));
cls_math_Matrix.def("__isub__", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::operator-=, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Subtracted", (math_Matrix (math_Matrix::*)(const math_Matrix &) const) &math_Matrix::Subtracted, "Returns the result of the subtraction of <Right> from <me>. An exception is raised if the dimensions are different.", py::arg("Right"));
cls_math_Matrix.def("__sub__", (math_Matrix (math_Matrix::*)(const math_Matrix &) const) &math_Matrix::operator-, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Set", (void (math_Matrix::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const math_Matrix &)) &math_Matrix::Set, "Sets the values of this matrix, - from index I1 to index I2 on the row dimension, and - from index J1 to index J2 on the column dimension, to those of matrix M. Exceptions Standard_DimensionError if: - I1 is less than the index of the lower row bound of this matrix, or - I2 is greater than the index of the upper row bound of this matrix, or - J1 is less than the index of the lower column bound of this matrix, or - J2 is greater than the index of the upper column bound of this matrix, or - I2 - I1 + 1 is not equal to the number of rows of matrix M, or - J2 - J1 + 1 is not equal to the number of columns of matrix M.", py::arg("I1"), py::arg("I2"), py::arg("J1"), py::arg("J2"), py::arg("M"));
cls_math_Matrix.def("SetRow", (void (math_Matrix::*)(const Standard_Integer, const math_Vector &)) &math_Matrix::SetRow, "Sets the row of index Row of a matrix to the vector <V>. An exception is raised if the dimensions are different. An exception is raises if <Row> is inferior to the lower row of the matrix or <Row> is superior to the upper row.", py::arg("Row"), py::arg("V"));
cls_math_Matrix.def("SetCol", (void (math_Matrix::*)(const Standard_Integer, const math_Vector &)) &math_Matrix::SetCol, "Sets the column of index Col of a matrix to the vector <V>. An exception is raised if the dimensions are different. An exception is raises if <Col> is inferior to the lower column of the matrix or <Col> is superior to the upper column.", py::arg("Col"), py::arg("V"));
cls_math_Matrix.def("SetDiag", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::SetDiag, "Sets the diagonal of a matrix to the value <Value>. An exception is raised if the matrix is not square.", py::arg("Value"));
cls_math_Matrix.def("Row", (math_Vector (math_Matrix::*)(const Standard_Integer) const) &math_Matrix::Row, "Returns the row of index Row of a matrix.", py::arg("Row"));
cls_math_Matrix.def("Col", (math_Vector (math_Matrix::*)(const Standard_Integer) const) &math_Matrix::Col, "Returns the column of index <Col> of a matrix.", py::arg("Col"));
cls_math_Matrix.def("SwapRow", (void (math_Matrix::*)(const Standard_Integer, const Standard_Integer)) &math_Matrix::SwapRow, "Swaps the rows of index Row1 and Row2. An exception is raised if <Row1> or <Row2> is out of range.", py::arg("Row1"), py::arg("Row2"));
cls_math_Matrix.def("SwapCol", (void (math_Matrix::*)(const Standard_Integer, const Standard_Integer)) &math_Matrix::SwapCol, "Swaps the columns of index <Col1> and <Col2>. An exception is raised if <Col1> or <Col2> is out of range.", py::arg("Col1"), py::arg("Col2"));
cls_math_Matrix.def("Transposed", (math_Matrix (math_Matrix::*)() const) &math_Matrix::Transposed, "Teturns the transposed of a matrix. An exception is raised if the matrix is not a square matrix.");
cls_math_Matrix.def("Inverse", (math_Matrix (math_Matrix::*)() const) &math_Matrix::Inverse, "Returns the inverse of a matrix. Exception NotSquare is raised if the matrix is not square. Exception SingularMatrix is raised if the matrix is singular.");
cls_math_Matrix.def("TMultiply", (math_Matrix (math_Matrix::*)(const math_Matrix &) const) &math_Matrix::TMultiply, "Returns the product of the transpose of a matrix with the matrix <Right>. An exception is raised if the dimensions are different.", py::arg("Right"));
cls_math_Matrix.def("Multiply", (void (math_Matrix::*)(const math_Vector &, const math_Vector &)) &math_Matrix::Multiply, "Computes a matrix as the product of 2 vectors. An exception is raised if the dimensions are different. <me> = <Left> * <Right>.", py::arg("Left"), py::arg("Right"));
cls_math_Matrix.def("Multiply", (void (math_Matrix::*)(const math_Matrix &, const math_Matrix &)) &math_Matrix::Multiply, "Computes a matrix as the product of 2 matrixes. An exception is raised if the dimensions are different.", py::arg("Left"), py::arg("Right"));
cls_math_Matrix.def("TMultiply", (void (math_Matrix::*)(const math_Matrix &, const math_Matrix &)) &math_Matrix::TMultiply, "Computes a matrix to the product of the transpose of the matrix <TLeft> with the matrix <Right>. An exception is raised if the dimensions are different.", py::arg("TLeft"), py::arg("Right"));
cls_math_Matrix.def("Subtract", (void (math_Matrix::*)(const math_Matrix &, const math_Matrix &)) &math_Matrix::Subtract, "Sets a matrix to the Subtraction of the matrix <Right> from the matrix <Left>. An exception is raised if the dimensions are different.", py::arg("Left"), py::arg("Right"));
cls_math_Matrix.def("Value", (Standard_Real & (math_Matrix::*)(const Standard_Integer, const Standard_Integer) const) &math_Matrix::Value, "Accesses (in read or write mode) the value of index <Row> and <Col> of a matrix. An exception is raised if <Row> and <Col> are not in the correct range.", py::arg("Row"), py::arg("Col"));
cls_math_Matrix.def("__call__", (Standard_Real & (math_Matrix::*)(const Standard_Integer, const Standard_Integer) const) &math_Matrix::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
cls_math_Matrix.def("Initialized", (math_Matrix & (math_Matrix::*)(const math_Matrix &)) &math_Matrix::Initialized, "Matrixes are copied through assignement. An exception is raised if the dimensions are differents.", py::arg("Other"));
// cls_math_Matrix.def("operator=", (math_Matrix & (math_Matrix::*)(const math_Matrix &)) &math_Matrix::operator=, "None", py::arg("Other"));
cls_math_Matrix.def("Multiply", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::Multiply, "Returns the product of 2 matrices. An exception is raised if the dimensions are different.", py::arg("Right"));
cls_math_Matrix.def("__imul__", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::operator*=, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Multiplied", (math_Matrix (math_Matrix::*)(const math_Matrix &) const) &math_Matrix::Multiplied, "Returns the product of 2 matrices. An exception is raised if the dimensions are different.", py::arg("Right"));
cls_math_Matrix.def("__mul__", (math_Matrix (math_Matrix::*)(const math_Matrix &) const) &math_Matrix::operator*, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Multiplied", (math_Vector (math_Matrix::*)(const math_Vector &) const) &math_Matrix::Multiplied, "Returns the product of a matrix by a vector. An exception is raised if the dimensions are different.", py::arg("Right"));
cls_math_Matrix.def("__mul__", (math_Vector (math_Matrix::*)(const math_Vector &) const) &math_Matrix::operator*, py::is_operator(), "None", py::arg("Right"));
cls_math_Matrix.def("Opposite", (math_Matrix (math_Matrix::*)()) &math_Matrix::Opposite, "Returns the opposite of a matrix. An exception is raised if the dimensions are different.");
cls_math_Matrix.def("__sub__", (math_Matrix (math_Matrix::*)()) &math_Matrix::operator-, py::is_operator(), "None");
cls_math_Matrix.def("Dump", (void (math_Matrix::*)(Standard_OStream &) const) &math_Matrix::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}