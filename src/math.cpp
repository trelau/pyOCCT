/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <Standard_OStream.hxx>
#include <math_Function.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <math_SingleTab.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <math_DoubleTab.hxx>
#include <math_Uzawa.hxx>
#include <math_Status.hxx>
#include <math_MultipleVarFunction.hxx>
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <math_BFGS.hxx>
#include <math_IntegerVector.hxx>
#include <math_FunctionSet.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_FunctionSetRoot.hxx>
#include <math_MultipleVarFunctionWithHessian.hxx>
#include <math_NewtonMinimum.hxx>
#include <math_FunctionSample.hxx>
#include <math_DirectPolynomialRoots.hxx>
#include <math_TrigonometricFunctionRoots.hxx>
#include <math_Gauss.hxx>
#include <math_GaussLeastSquare.hxx>
#include <math_SVD.hxx>
#include <math_FunctionRoots.hxx>
#include <math_BissecNewton.hxx>
#include <math_FunctionRoot.hxx>
#include <math_NewtonFunctionRoot.hxx>
#include <math_BracketedRoot.hxx>
#include <math_NewtonFunctionSetRoot.hxx>
#include <math_BracketMinimum.hxx>
#include <math_BrentMinimum.hxx>
#include <math_Powell.hxx>
#include <math_FRPR.hxx>
#include <math_Jacobi.hxx>
#include <math_GaussSingleIntegration.hxx>
#include <math_GaussMultipleIntegration.hxx>
#include <math_GaussSetIntegration.hxx>
#include <math_FunctionAllRoots.hxx>
#include <math_Householder.hxx>
#include <math_Crout.hxx>
#include <math_KronrodSingleIntegration.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <math_EigenValuesSearcher.hxx>
#include <math_ComputeGaussPointsAndWeights.hxx>
#include <math_ComputeKronrodPointsAndWeights.hxx>
#include <math.hxx>
#include <math_ValueAndWeight.hxx>
#include <NCollection_Array1.hxx>
#include <math_Array1OfValueAndWeight.hxx>
#include <math_BullardGenerator.hxx>
#include <Standard_DimensionError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Handle.hxx>
#include <math_NotSquare.hxx>
#include <Standard_Type.hxx>
#include <math_GaussPoints.hxx>
#include <math_GlobOptMin.hxx>
#include <math_PSOParticlesPool.hxx>
#include <math_PSO.hxx>
#include <math_Recipes.hxx>
#include <Standard_Failure.hxx>
#include <math_SingularMatrix.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(math, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Status.hxx
	py::enum_<math_Status>(mod, "math_Status", "None")
		.value("math_OK", math_Status::math_OK)
		.value("math_TooManyIterations", math_Status::math_TooManyIterations)
		.value("math_FunctionError", math_Status::math_FunctionError)
		.value("math_DirectionSearchError", math_Status::math_DirectionSearchError)
		.value("math_NotBracketed", math_Status::math_NotBracketed)
		.export_values();

	// FUNCTIONS
	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Uzawa.lxx
	mod.def("bits_left", (Standard_OStream & (*)(Standard_OStream &, const math_Uzawa &)) &operator<<, py::is_operator(), "None", py::arg("o"), py::arg("U"));
	*/
	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Matrix.lxx
	// mod.def("__mul__", (math_Matrix (*)(const Standard_Real, const math_Matrix &)) &operator*, py::is_operator(), "None", py::arg("Left"), py::arg("Right"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_ValueAndWeight.hxx
	// mod.def("__lt__", (bool (*)(const math_ValueAndWeight &, const math_ValueAndWeight &)) &operator<, py::is_operator(), "Comparison operator for math_ValueAndWeight, needed for sorting algorithms", py::arg("theLeft"), py::arg("theRight"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_GaussPoints.hxx
	// mod.def("GPoints", (math_Vector (*)(const Standard_Integer)) &GPoints, "None", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_GaussPoints.hxx
	// mod.def("GWeights", (math_Vector (*)(const Standard_Integer)) &GWeights, "None", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Recipes.hxx
	mod.def("LU_Decompose", (Standard_Integer (*)(math_Matrix &, math_IntegerVector &, Standard_Real &, math_Vector &, Standard_Real)) &LU_Decompose, "None", py::arg("a"), py::arg("indx"), py::arg("d"), py::arg("vv"), py::arg("TINY") = 1.0e-30);

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Recipes.hxx
	mod.def("LU_Solve", (void (*)(const math_Matrix &, const math_IntegerVector &, math_Vector &)) &LU_Solve, "None", py::arg("a"), py::arg("indx"), py::arg("b"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Recipes.hxx
	mod.def("LU_Invert", (Standard_Integer (*)(math_Matrix &)) &LU_Invert, "None", py::arg("a"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Recipes.hxx
	mod.def("SVD_Decompose", (Standard_Integer (*)(math_Matrix &, math_Vector &, math_Matrix &, math_Vector &)) &SVD_Decompose, "None", py::arg("a"), py::arg("w"), py::arg("v"), py::arg("rv1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Recipes.hxx
	mod.def("SVD_Solve", (void (*)(const math_Matrix &, const math_Vector &, const math_Matrix &, const math_Vector &, math_Vector &)) &SVD_Solve, "None", py::arg("u"), py::arg("w"), py::arg("v"), py::arg("b"), py::arg("x"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Recipes.hxx
	mod.def("DACTCL_Decompose", (Standard_Integer (*)(math_Vector &, const math_IntegerVector &, const Standard_Real)) &DACTCL_Decompose, "None", py::arg("a"), py::arg("indx"), py::arg("MinPivot") = 1.e-20);

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Recipes.hxx
	mod.def("DACTCL_Solve", (Standard_Integer (*)(const math_Vector &, math_Vector &, const math_IntegerVector &, const Standard_Real)) &DACTCL_Solve, "None", py::arg("a"), py::arg("b"), py::arg("indx"), py::arg("MinPivot") = 1.e-20);

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Recipes.hxx
	mod.def("Jacobi", (Standard_Integer (*)(math_Matrix &, math_Vector &, math_Matrix &, Standard_Integer &)) &Jacobi, "None", py::arg("a"), py::arg("d"), py::arg("v"), py::arg("nrot"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Matrix.hxx
	py::class_<math_Matrix, std::unique_ptr<math_Matrix, Deleter<math_Matrix>>> cls_math_Matrix(mod, "math_Matrix", "This class implements the real matrix abstract data type. Matrixes can have an arbitrary range which must be defined at the declaration and cannot be changed after this declaration math_Matrix(-3,5,2,4); //a vector with range [-3..5, 2..4] Matrix values may be initialized and retrieved using indexes which must lie within the range of definition of the matrix. Matrix objects follow 'value semantics', that is, they cannot be shared and are copied through assignment. Matrices are copied through assignment: math_Matrix M2(1, 9, 1, 3); ... M2 = M1; M1(1) = 2.0;//the matrix M2 will not be modified.");
	cls_math_Matrix.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"));
	cls_math_Matrix.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"), py::arg("InitialValue"));
	cls_math_Matrix.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Tab"), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"));
	cls_math_Matrix.def(py::init([] (const math_Matrix &other) {return new math_Matrix(other);}), "Copy constructor", py::arg("other"));
	cls_math_Matrix.def("Init", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::Init, "Initialize all the elements of a matrix to InitialValue.", py::arg("InitialValue"));
	cls_math_Matrix.def("RowNumber", (Standard_Integer (math_Matrix::*)() const ) &math_Matrix::RowNumber, "Returns the number of rows of this matrix. Note that for a matrix A you always have the following relations: - A.RowNumber() = A.UpperRow() - A.LowerRow() + 1 - A.ColNumber() = A.UpperCol() - A.LowerCol() + 1 - the length of a row of A is equal to the number of columns of A, - the length of a column of A is equal to the number of rows of A.returns the row range of a matrix.");
	cls_math_Matrix.def("ColNumber", (Standard_Integer (math_Matrix::*)() const ) &math_Matrix::ColNumber, "Returns the number of rows of this matrix. Note that for a matrix A you always have the following relations: - A.RowNumber() = A.UpperRow() - A.LowerRow() + 1 - A.ColNumber() = A.UpperCol() - A.LowerCol() + 1 - the length of a row of A is equal to the number of columns of A, - the length of a column of A is equal to the number of rows of A.returns the row range of a matrix.");
	cls_math_Matrix.def("LowerRow", (Standard_Integer (math_Matrix::*)() const ) &math_Matrix::LowerRow, "Returns the value of the Lower index of the row range of a matrix.");
	cls_math_Matrix.def("UpperRow", (Standard_Integer (math_Matrix::*)() const ) &math_Matrix::UpperRow, "Returns the Upper index of the row range of a matrix.");
	cls_math_Matrix.def("LowerCol", (Standard_Integer (math_Matrix::*)() const ) &math_Matrix::LowerCol, "Returns the value of the Lower index of the column range of a matrix.");
	cls_math_Matrix.def("UpperCol", (Standard_Integer (math_Matrix::*)() const ) &math_Matrix::UpperCol, "Returns the value of the upper index of the column range of a matrix.");
	cls_math_Matrix.def("Determinant", (Standard_Real (math_Matrix::*)() const ) &math_Matrix::Determinant, "Computes the determinant of a matrix. An exception is raised if the matrix is not a square matrix.");
	cls_math_Matrix.def("Transpose", (void (math_Matrix::*)()) &math_Matrix::Transpose, "Transposes a given matrix. An exception is raised if the matrix is not a square matrix.");
	cls_math_Matrix.def("Invert", (void (math_Matrix::*)()) &math_Matrix::Invert, "Inverts a matrix using Gauss algorithm. Exception NotSquare is raised if the matrix is not square. Exception SingularMatrix is raised if the matrix is singular.");
	cls_math_Matrix.def("Multiply", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::Multiply, "Sets this matrix to the product of the matrix Left, and the matrix Right. Example math_Matrix A (1, 3, 1, 3); math_Matrix B (1, 3, 1, 3); // A = ... , B = ... math_Matrix C (1, 3, 1, 3); C.Multiply(A, B); Exceptions Standard_DimensionError if matrices are of incompatible dimensions, i.e. if: - the number of columns of matrix Left, or the number of rows of matrix TLeft is not equal to the number of rows of matrix Right, or - the number of rows of matrix Left, or the number of columns of matrix TLeft is not equal to the number of rows of this matrix, or - the number of columns of matrix Right is not equal to the number of columns of this matrix.", py::arg("Right"));
	cls_math_Matrix.def("__imul__", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::operator*=, "None", py::arg("Right"));
	cls_math_Matrix.def("Multiplied", (math_Matrix (math_Matrix::*)(const Standard_Real) const ) &math_Matrix::Multiplied, "multiplies all the elements of a matrix by the value <Right>.", py::arg("Right"));
	cls_math_Matrix.def("__mul__", (math_Matrix (math_Matrix::*)(const Standard_Real) const ) &math_Matrix::operator*, py::is_operator(), "None", py::arg("Right"));
	cls_math_Matrix.def("TMultiplied", (math_Matrix (math_Matrix::*)(const Standard_Real) const ) &math_Matrix::TMultiplied, "Sets this matrix to the product of the transposed matrix TLeft, and the matrix Right. Example math_Matrix A (1, 3, 1, 3); math_Matrix B (1, 3, 1, 3); // A = ... , B = ... math_Matrix C (1, 3, 1, 3); C.Multiply(A, B); Exceptions Standard_DimensionError if matrices are of incompatible dimensions, i.e. if: - the number of columns of matrix Left, or the number of rows of matrix TLeft is not equal to the number of rows of matrix Right, or - the number of rows of matrix Left, or the number of columns of matrix TLeft is not equal to the number of rows of this matrix, or - the number of columns of matrix Right is not equal to the number of columns of this matrix.", py::arg("Right"));
	cls_math_Matrix.def("Divide", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::Divide, "divides all the elements of a matrix by the value <Right>. An exception is raised if <Right> = 0.", py::arg("Right"));
	cls_math_Matrix.def("__itruediv__", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::operator/=, "None", py::arg("Right"));
	cls_math_Matrix.def("Divided", (math_Matrix (math_Matrix::*)(const Standard_Real) const ) &math_Matrix::Divided, "divides all the elements of a matrix by the value <Right>. An exception is raised if <Right> = 0.", py::arg("Right"));
	cls_math_Matrix.def("__truediv__", (math_Matrix (math_Matrix::*)(const Standard_Real) const ) &math_Matrix::operator/, py::is_operator(), "None", py::arg("Right"));
	cls_math_Matrix.def("Add", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::Add, "adds the matrix <Right> to a matrix. An exception is raised if the dimensions are different. Warning In order to save time when copying matrices, it is preferable to use operator += or the function Add whenever possible.", py::arg("Right"));
	cls_math_Matrix.def("__iadd__", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::operator+=, "None", py::arg("Right"));
	cls_math_Matrix.def("Added", (math_Matrix (math_Matrix::*)(const math_Matrix &) const ) &math_Matrix::Added, "adds the matrix <Right> to a matrix. An exception is raised if the dimensions are different.", py::arg("Right"));
	cls_math_Matrix.def("__add__", (math_Matrix (math_Matrix::*)(const math_Matrix &) const ) &math_Matrix::operator+, py::is_operator(), "None", py::arg("Right"));
	cls_math_Matrix.def("Add", (void (math_Matrix::*)(const math_Matrix &, const math_Matrix &)) &math_Matrix::Add, "sets a matrix to the addition of <Left> and <Right>. An exception is raised if the dimensions are different.", py::arg("Left"), py::arg("Right"));
	cls_math_Matrix.def("Subtract", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::Subtract, "Subtracts the matrix <Right> from <me>. An exception is raised if the dimensions are different. Warning In order to avoid time-consuming copying of matrices, it is preferable to use operator -= or the function Subtract whenever possible.", py::arg("Right"));
	cls_math_Matrix.def("__isub__", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::operator-=, "None", py::arg("Right"));
	cls_math_Matrix.def("Subtracted", (math_Matrix (math_Matrix::*)(const math_Matrix &) const ) &math_Matrix::Subtracted, "Returns the result of the subtraction of <Right> from <me>. An exception is raised if the dimensions are different.", py::arg("Right"));
	cls_math_Matrix.def("__sub__", (math_Matrix (math_Matrix::*)(const math_Matrix &) const ) &math_Matrix::operator-, py::is_operator(), "None", py::arg("Right"));
	cls_math_Matrix.def("Set", (void (math_Matrix::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const math_Matrix &)) &math_Matrix::Set, "Sets the values of this matrix, - from index I1 to index I2 on the row dimension, and - from index J1 to index J2 on the column dimension, to those of matrix M. Exceptions Standard_DimensionError if: - I1 is less than the index of the lower row bound of this matrix, or - I2 is greater than the index of the upper row bound of this matrix, or - J1 is less than the index of the lower column bound of this matrix, or - J2 is greater than the index of the upper column bound of this matrix, or - I2 - I1 + 1 is not equal to the number of rows of matrix M, or - J2 - J1 + 1 is not equal to the number of columns of matrix M.", py::arg("I1"), py::arg("I2"), py::arg("J1"), py::arg("J2"), py::arg("M"));
	cls_math_Matrix.def("SetRow", (void (math_Matrix::*)(const Standard_Integer, const math_Vector &)) &math_Matrix::SetRow, "Sets the row of index Row of a matrix to the vector <V>. An exception is raised if the dimensions are different. An exception is raises if <Row> is inferior to the lower row of the matrix or <Row> is superior to the upper row.", py::arg("Row"), py::arg("V"));
	cls_math_Matrix.def("SetCol", (void (math_Matrix::*)(const Standard_Integer, const math_Vector &)) &math_Matrix::SetCol, "Sets the column of index Col of a matrix to the vector <V>. An exception is raised if the dimensions are different. An exception is raises if <Col> is inferior to the lower column of the matrix or <Col> is superior to the upper column.", py::arg("Col"), py::arg("V"));
	cls_math_Matrix.def("SetDiag", (void (math_Matrix::*)(const Standard_Real)) &math_Matrix::SetDiag, "Sets the diagonal of a matrix to the value <Value>. An exception is raised if the matrix is not square.", py::arg("Value"));
	cls_math_Matrix.def("Row", (math_Vector (math_Matrix::*)(const Standard_Integer) const ) &math_Matrix::Row, "Returns the row of index Row of a matrix.", py::arg("Row"));
	cls_math_Matrix.def("Col", (math_Vector (math_Matrix::*)(const Standard_Integer) const ) &math_Matrix::Col, "Returns the column of index <Col> of a matrix.", py::arg("Col"));
	cls_math_Matrix.def("SwapRow", (void (math_Matrix::*)(const Standard_Integer, const Standard_Integer)) &math_Matrix::SwapRow, "Swaps the rows of index Row1 and Row2. An exception is raised if <Row1> or <Row2> is out of range.", py::arg("Row1"), py::arg("Row2"));
	cls_math_Matrix.def("SwapCol", (void (math_Matrix::*)(const Standard_Integer, const Standard_Integer)) &math_Matrix::SwapCol, "Swaps the columns of index <Col1> and <Col2>. An exception is raised if <Col1> or <Col2> is out of range.", py::arg("Col1"), py::arg("Col2"));
	cls_math_Matrix.def("Transposed", (math_Matrix (math_Matrix::*)() const ) &math_Matrix::Transposed, "Teturns the transposed of a matrix. An exception is raised if the matrix is not a square matrix.");
	cls_math_Matrix.def("Inverse", (math_Matrix (math_Matrix::*)() const ) &math_Matrix::Inverse, "Returns the inverse of a matrix. Exception NotSquare is raised if the matrix is not square. Exception SingularMatrix is raised if the matrix is singular.");
	cls_math_Matrix.def("TMultiply", (math_Matrix (math_Matrix::*)(const math_Matrix &) const ) &math_Matrix::TMultiply, "Returns the product of the transpose of a matrix with the matrix <Right>. An exception is raised if the dimensions are different.", py::arg("Right"));
	cls_math_Matrix.def("Multiply", (void (math_Matrix::*)(const math_Vector &, const math_Vector &)) &math_Matrix::Multiply, "Computes a matrix as the product of 2 vectors. An exception is raised if the dimensions are different. <me> = <Left> * <Right>.", py::arg("Left"), py::arg("Right"));
	cls_math_Matrix.def("Multiply", (void (math_Matrix::*)(const math_Matrix &, const math_Matrix &)) &math_Matrix::Multiply, "Computes a matrix as the product of 2 matrixes. An exception is raised if the dimensions are different.", py::arg("Left"), py::arg("Right"));
	cls_math_Matrix.def("TMultiply", (void (math_Matrix::*)(const math_Matrix &, const math_Matrix &)) &math_Matrix::TMultiply, "Computes a matrix to the product of the transpose of the matrix <TLeft> with the matrix <Right>. An exception is raised if the dimensions are different.", py::arg("TLeft"), py::arg("Right"));
	cls_math_Matrix.def("Subtract", (void (math_Matrix::*)(const math_Matrix &, const math_Matrix &)) &math_Matrix::Subtract, "Sets a matrix to the Subtraction of the matrix <Right> from the matrix <Left>. An exception is raised if the dimensions are different.", py::arg("Left"), py::arg("Right"));
	cls_math_Matrix.def("Value", (Standard_Real & (math_Matrix::*)(const Standard_Integer, const Standard_Integer) const ) &math_Matrix::Value, "Accesses (in read or write mode) the value of index <Row> and <Col> of a matrix. An exception is raised if <Row> and <Col> are not in the correct range.", py::arg("Row"), py::arg("Col"));
	cls_math_Matrix.def("__call__", (Standard_Real & (math_Matrix::*)(const Standard_Integer, const Standard_Integer) const ) &math_Matrix::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"));
	cls_math_Matrix.def("Initialized", (math_Matrix & (math_Matrix::*)(const math_Matrix &)) &math_Matrix::Initialized, "Matrixes are copied through assignment. An exception is raised if the dimensions are different.", py::arg("Other"));
	cls_math_Matrix.def("assign", (math_Matrix & (math_Matrix::*)(const math_Matrix &)) &math_Matrix::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_math_Matrix.def("Multiply", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::Multiply, "Returns the product of 2 matrices. An exception is raised if the dimensions are different.", py::arg("Right"));
	cls_math_Matrix.def("__imul__", (void (math_Matrix::*)(const math_Matrix &)) &math_Matrix::operator*=, "None", py::arg("Right"));
	cls_math_Matrix.def("Multiplied", (math_Matrix (math_Matrix::*)(const math_Matrix &) const ) &math_Matrix::Multiplied, "Returns the product of 2 matrices. An exception is raised if the dimensions are different.", py::arg("Right"));
	cls_math_Matrix.def("__mul__", (math_Matrix (math_Matrix::*)(const math_Matrix &) const ) &math_Matrix::operator*, py::is_operator(), "None", py::arg("Right"));
	cls_math_Matrix.def("Multiplied", (math_Vector (math_Matrix::*)(const math_Vector &) const ) &math_Matrix::Multiplied, "Returns the product of a matrix by a vector. An exception is raised if the dimensions are different.", py::arg("Right"));
	cls_math_Matrix.def("__mul__", (math_Vector (math_Matrix::*)(const math_Vector &) const ) &math_Matrix::operator*, py::is_operator(), "None", py::arg("Right"));
	cls_math_Matrix.def("Opposite", (math_Matrix (math_Matrix::*)()) &math_Matrix::Opposite, "Returns the opposite of a matrix. An exception is raised if the dimensions are different.");
	cls_math_Matrix.def("__sub__", (math_Matrix (math_Matrix::*)()) &math_Matrix::operator-, py::is_operator(), "None");
	// FIXME cls_math_Matrix.def("Dump", (void (math_Matrix::*)(Standard_OStream &) const ) &math_Matrix::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Function.hxx
	py::class_<math_Function, std::unique_ptr<math_Function, Deleter<math_Function>>> cls_math_Function(mod, "math_Function", "This abstract class describes the virtual functions associated with a Function of a single variable.");
	cls_math_Function.def("Value", [](math_Function &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the function <F> for a given value of variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_math_Function.def("GetStateNumber", (Standard_Integer (math_Function::*)()) &math_Function::GetStateNumber, "returns the state of the function corresponding to the latest call of any methods associated with the function. This function is called by each of the algorithms described later which defined the function Integer Algorithm::StateNumber(). The algorithm has the responsibility to call this function when it has found a solution (i.e. a root or a minimum) and has to maintain the association between the solution found and this StateNumber. Byu default, this method returns 0 (which means for the algorithm: no state has been saved). It is the responsibility of the programmer to decide if he needs to save the current state of the function and to return an Integer that allows retrieval of the state.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_FunctionWithDerivative.hxx
	py::class_<math_FunctionWithDerivative, std::unique_ptr<math_FunctionWithDerivative, Deleter<math_FunctionWithDerivative>>, math_Function> cls_math_FunctionWithDerivative(mod, "math_FunctionWithDerivative", "This abstract class describes the virtual functions associated with a function of a single variable for which the first derivative is available.");
	cls_math_FunctionWithDerivative.def("Value", [](math_FunctionWithDerivative &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value <F>of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"));
	cls_math_FunctionWithDerivative.def("Derivative", [](math_FunctionWithDerivative &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
	cls_math_FunctionWithDerivative.def("Values", [](math_FunctionWithDerivative &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Vector.hxx
	py::class_<math_Vector, std::unique_ptr<math_Vector, Deleter<math_Vector>>> cls_math_Vector(mod, "math_Vector", "This class implements the real vector abstract data type. Vectors can have an arbitrary range which must be defined at the declaration and cannot be changed after this declaration.");
	cls_math_Vector.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_math_Vector.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theInitialValue"));
	cls_math_Vector.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer>(), py::arg("theTab"), py::arg("theLower"), py::arg("theUpper"));
	cls_math_Vector.def(py::init<const gp_XY &>(), py::arg("Other"));
	cls_math_Vector.def(py::init<const gp_XYZ &>(), py::arg("Other"));
	cls_math_Vector.def(py::init([] (const math_Vector &other) {return new math_Vector(other);}), "Copy constructor", py::arg("other"));
	cls_math_Vector.def("Init", (void (math_Vector::*)(const Standard_Real)) &math_Vector::Init, "Initialize all the elements of a vector with 'theInitialValue'.", py::arg("theInitialValue"));
	cls_math_Vector.def("Length", (Standard_Integer (math_Vector::*)() const ) &math_Vector::Length, "Returns the length of a vector");
	cls_math_Vector.def("Lower", (Standard_Integer (math_Vector::*)() const ) &math_Vector::Lower, "Returns the value of the theLower index of a vector.");
	cls_math_Vector.def("Upper", (Standard_Integer (math_Vector::*)() const ) &math_Vector::Upper, "Returns the value of the theUpper index of a vector.");
	cls_math_Vector.def("Norm", (Standard_Real (math_Vector::*)() const ) &math_Vector::Norm, "Returns the value or the square of the norm of this vector.");
	cls_math_Vector.def("Norm2", (Standard_Real (math_Vector::*)() const ) &math_Vector::Norm2, "Returns the value of the square of the norm of a vector.");
	cls_math_Vector.def("Max", (Standard_Integer (math_Vector::*)() const ) &math_Vector::Max, "Returns the value of the 'Index' of the maximum element of a vector.");
	cls_math_Vector.def("Min", (Standard_Integer (math_Vector::*)() const ) &math_Vector::Min, "Returns the value of the 'Index' of the minimum element of a vector.");
	cls_math_Vector.def("Normalize", (void (math_Vector::*)()) &math_Vector::Normalize, "Normalizes this vector (the norm of the result is equal to 1.0) and assigns the result to this vector Exceptions Standard_NullValue if this vector is null (i.e. if its norm is less than or equal to Standard_Real::RealEpsilon().");
	cls_math_Vector.def("Normalized", (math_Vector (math_Vector::*)() const ) &math_Vector::Normalized, "Normalizes this vector (the norm of the result is equal to 1.0) and creates a new vector Exceptions Standard_NullValue if this vector is null (i.e. if its norm is less than or equal to Standard_Real::RealEpsilon().");
	cls_math_Vector.def("Invert", (void (math_Vector::*)()) &math_Vector::Invert, "Inverts this vector and assigns the result to this vector.");
	cls_math_Vector.def("Inverse", (math_Vector (math_Vector::*)() const ) &math_Vector::Inverse, "Inverts this vector and creates a new vector.");
	cls_math_Vector.def("Set", (void (math_Vector::*)(const Standard_Integer, const Standard_Integer, const math_Vector &)) &math_Vector::Set, "sets a vector from 'theI1' to 'theI2' to the vector 'theV'; An exception is raised if 'theI1' is less than 'LowerIndex' or 'theI2' is greater than 'UpperIndex' or 'theI1' is greater than 'theI2'. An exception is raised if 'theI2-theI1+1' is different from the 'Length' of 'theV'.", py::arg("theI1"), py::arg("theI2"), py::arg("theV"));
	cls_math_Vector.def("Slice", (math_Vector (math_Vector::*)(const Standard_Integer, const Standard_Integer) const ) &math_Vector::Slice, "Creates a new vector by inverting the values of this vector between indexes 'theI1' and 'theI2'. If the values of this vector were (1., 2., 3., 4.,5., 6.), by slicing it between indexes 2 and 5 the values of the resulting vector are (1., 5., 4., 3., 2., 6.)", py::arg("theI1"), py::arg("theI2"));
	cls_math_Vector.def("Multiply", (void (math_Vector::*)(const Standard_Real)) &math_Vector::Multiply, "returns the product of a vector and a real value.", py::arg("theRight"));
	cls_math_Vector.def("__imul__", (void (math_Vector::*)(const Standard_Real)) &math_Vector::operator*=, "None", py::arg("theRight"));
	cls_math_Vector.def("Multiplied", (math_Vector (math_Vector::*)(const Standard_Real) const ) &math_Vector::Multiplied, "returns the product of a vector and a real value.", py::arg("theRight"));
	cls_math_Vector.def("__mul__", (math_Vector (math_Vector::*)(const Standard_Real) const ) &math_Vector::operator*, py::is_operator(), "None", py::arg("theRight"));
	cls_math_Vector.def("TMultiplied", (math_Vector (math_Vector::*)(const Standard_Real) const ) &math_Vector::TMultiplied, "returns the product of a vector and a real value.", py::arg("theRight"));
	cls_math_Vector.def("Divide", (void (math_Vector::*)(const Standard_Real)) &math_Vector::Divide, "divides a vector by the value 'theRight'. An exception is raised if 'theRight' = 0.", py::arg("theRight"));
	cls_math_Vector.def("__itruediv__", (void (math_Vector::*)(const Standard_Real)) &math_Vector::operator/=, "None", py::arg("theRight"));
	cls_math_Vector.def("Divided", (math_Vector (math_Vector::*)(const Standard_Real) const ) &math_Vector::Divided, "divides a vector by the value 'theRight'. An exception is raised if 'theRight' = 0.", py::arg("theRight"));
	cls_math_Vector.def("__truediv__", (math_Vector (math_Vector::*)(const Standard_Real) const ) &math_Vector::operator/, py::is_operator(), "None", py::arg("theRight"));
	cls_math_Vector.def("Add", (void (math_Vector::*)(const math_Vector &)) &math_Vector::Add, "adds the vector 'theRight' to a vector. An exception is raised if the vectors have not the same length. Warning In order to avoid time-consuming copying of vectors, it is preferable to use operator += or the function Add whenever possible.", py::arg("theRight"));
	cls_math_Vector.def("__iadd__", (void (math_Vector::*)(const math_Vector &)) &math_Vector::operator+=, "None", py::arg("theRight"));
	cls_math_Vector.def("Added", (math_Vector (math_Vector::*)(const math_Vector &) const ) &math_Vector::Added, "adds the vector theRight to a vector. An exception is raised if the vectors have not the same length. An exception is raised if the lengths are not equal.", py::arg("theRight"));
	cls_math_Vector.def("__add__", (math_Vector (math_Vector::*)(const math_Vector &) const ) &math_Vector::operator+, py::is_operator(), "None", py::arg("theRight"));
	cls_math_Vector.def("Multiply", (void (math_Vector::*)(const math_Vector &, const math_Matrix &)) &math_Vector::Multiply, "sets a vector to the product of the vector 'theLeft' with the matrix 'theRight'.", py::arg("theLeft"), py::arg("theRight"));
	cls_math_Vector.def("Multiply", (void (math_Vector::*)(const math_Matrix &, const math_Vector &)) &math_Vector::Multiply, "sets a vector to the product of the matrix 'theLeft' with the vector 'theRight'.", py::arg("theLeft"), py::arg("theRight"));
	cls_math_Vector.def("TMultiply", (void (math_Vector::*)(const math_Matrix &, const math_Vector &)) &math_Vector::TMultiply, "sets a vector to the product of the transpose of the matrix 'theTLeft' by the vector 'theRight'.", py::arg("theTLeft"), py::arg("theRight"));
	cls_math_Vector.def("TMultiply", (void (math_Vector::*)(const math_Vector &, const math_Matrix &)) &math_Vector::TMultiply, "sets a vector to the product of the vector 'theLeft' by the transpose of the matrix 'theTRight'.", py::arg("theLeft"), py::arg("theTRight"));
	cls_math_Vector.def("Add", (void (math_Vector::*)(const math_Vector &, const math_Vector &)) &math_Vector::Add, "sets a vector to the sum of the vector 'theLeft' and the vector 'theRight'. An exception is raised if the lengths are different.", py::arg("theLeft"), py::arg("theRight"));
	cls_math_Vector.def("Subtract", (void (math_Vector::*)(const math_Vector &, const math_Vector &)) &math_Vector::Subtract, "sets a vector to the Subtraction of the vector theRight from the vector theLeft. An exception is raised if the vectors have not the same length. Warning In order to avoid time-consuming copying of vectors, it is preferable to use operator -= or the function Subtract whenever possible.", py::arg("theLeft"), py::arg("theRight"));
	cls_math_Vector.def("Value", (Standard_Real & (math_Vector::*)(const Standard_Integer) const ) &math_Vector::Value, "accesses (in read or write mode) the value of index 'theNum' of a vector.", py::arg("theNum"));
	cls_math_Vector.def("__call__", (Standard_Real & (math_Vector::*)(const Standard_Integer) const ) &math_Vector::operator(), py::is_operator(), "None", py::arg("theNum"));
	cls_math_Vector.def("Initialized", (math_Vector & (math_Vector::*)(const math_Vector &)) &math_Vector::Initialized, "Initialises a vector by copying 'theOther'. An exception is raised if the Lengths are different.", py::arg("theOther"));
	cls_math_Vector.def("assign", (math_Vector & (math_Vector::*)(const math_Vector &)) &math_Vector::operator=, py::is_operator(), "None", py::arg("theOther"));
	cls_math_Vector.def("Multiplied", (Standard_Real (math_Vector::*)(const math_Vector &) const ) &math_Vector::Multiplied, "returns the inner product of 2 vectors. An exception is raised if the lengths are not equal.", py::arg("theRight"));
	cls_math_Vector.def("__mul__", (Standard_Real (math_Vector::*)(const math_Vector &) const ) &math_Vector::operator*, py::is_operator(), "None", py::arg("theRight"));
	cls_math_Vector.def("Multiplied", (math_Vector (math_Vector::*)(const math_Matrix &) const ) &math_Vector::Multiplied, "returns the product of a vector by a matrix.", py::arg("theRight"));
	cls_math_Vector.def("__mul__", (math_Vector (math_Vector::*)(const math_Matrix &) const ) &math_Vector::operator*, py::is_operator(), "None", py::arg("theRight"));
	cls_math_Vector.def("Opposite", (math_Vector (math_Vector::*)()) &math_Vector::Opposite, "returns the opposite of a vector.");
	cls_math_Vector.def("__sub__", (math_Vector (math_Vector::*)()) &math_Vector::operator-, py::is_operator(), "None");
	cls_math_Vector.def("Subtract", (void (math_Vector::*)(const math_Vector &)) &math_Vector::Subtract, "returns the subtraction of 'theRight' from 'me'. An exception is raised if the vectors have not the same length.", py::arg("theRight"));
	cls_math_Vector.def("__isub__", (void (math_Vector::*)(const math_Vector &)) &math_Vector::operator-=, "None", py::arg("theRight"));
	cls_math_Vector.def("Subtracted", (math_Vector (math_Vector::*)(const math_Vector &) const ) &math_Vector::Subtracted, "returns the subtraction of 'theRight' from 'me'. An exception is raised if the vectors have not the same length.", py::arg("theRight"));
	cls_math_Vector.def("__sub__", (math_Vector (math_Vector::*)(const math_Vector &) const ) &math_Vector::operator-, py::is_operator(), "None", py::arg("theRight"));
	cls_math_Vector.def("Multiply", (void (math_Vector::*)(const Standard_Real, const math_Vector &)) &math_Vector::Multiply, "returns the multiplication of a real by a vector. 'me' = 'theLeft' * 'theRight'", py::arg("theLeft"), py::arg("theRight"));
	// FIXME cls_math_Vector.def("Dump", (void (math_Vector::*)(Standard_OStream &) const ) &math_Vector::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("theO"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_DoubleTab.hxx
	py::class_<math_DoubleTab, std::unique_ptr<math_DoubleTab, Deleter<math_DoubleTab>>> cls_math_DoubleTab(mod, "math_DoubleTab", "None");
	cls_math_DoubleTab.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"));
	cls_math_DoubleTab.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Tab"), py::arg("LowerRow"), py::arg("UpperRow"), py::arg("LowerCol"), py::arg("UpperCol"));
	cls_math_DoubleTab.def(py::init([] (const math_DoubleTab &other) {return new math_DoubleTab(other);}), "Copy constructor", py::arg("other"));
	cls_math_DoubleTab.def("Init", (void (math_DoubleTab::*)(const Standard_Real)) &math_DoubleTab::Init, "None", py::arg("InitValue"));
	cls_math_DoubleTab.def("Copy", (void (math_DoubleTab::*)(math_DoubleTab &) const ) &math_DoubleTab::Copy, "None", py::arg("Other"));
	cls_math_DoubleTab.def("SetLowerRow", (void (math_DoubleTab::*)(const Standard_Integer)) &math_DoubleTab::SetLowerRow, "None", py::arg("LowerRow"));
	cls_math_DoubleTab.def("SetLowerCol", (void (math_DoubleTab::*)(const Standard_Integer)) &math_DoubleTab::SetLowerCol, "None", py::arg("LowerCol"));
	cls_math_DoubleTab.def("Value", (Standard_Real & (math_DoubleTab::*)(const Standard_Integer, const Standard_Integer) const ) &math_DoubleTab::Value, "None", py::arg("RowIndex"), py::arg("ColIndex"));
	cls_math_DoubleTab.def("__call__", (Standard_Real & (math_DoubleTab::*)(const Standard_Integer, const Standard_Integer) const ) &math_DoubleTab::operator(), py::is_operator(), "None", py::arg("RowIndex"), py::arg("ColIndex"));
	cls_math_DoubleTab.def("Free", (void (math_DoubleTab::*)()) &math_DoubleTab::Free, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_MultipleVarFunction.hxx
	py::class_<math_MultipleVarFunction, std::unique_ptr<math_MultipleVarFunction, Deleter<math_MultipleVarFunction>>> cls_math_MultipleVarFunction(mod, "math_MultipleVarFunction", "Describes the virtual functions associated with a multiple variable function.");
	cls_math_MultipleVarFunction.def("NbVariables", (Standard_Integer (math_MultipleVarFunction::*)() const ) &math_MultipleVarFunction::NbVariables, "Returns the number of variables of the function");
	cls_math_MultipleVarFunction.def("Value", [](math_MultipleVarFunction &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the values of the Functions <F> for the variable <X>. returns True if the computation was done successfully, otherwise false.", py::arg("X"), py::arg("F"));
	cls_math_MultipleVarFunction.def("GetStateNumber", (Standard_Integer (math_MultipleVarFunction::*)()) &math_MultipleVarFunction::GetStateNumber, "return the state of the function corresponding to the latestt call of any methods associated to the function. This function is called by each of the algorithms described later which define the function Integer Algorithm::StateNumber(). The algorithm has the responsibility to call this function when it has found a solution (i.e. a root or a minimum) and has to maintain the association between the solution found and this StateNumber. Byu default, this method returns 0 (which means for the algorithm: no state has been saved). It is the responsibility of the programmer to decide if he needs to save the current state of the function and to return an Integer that allows retrieval of the state.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_BFGS.hxx
	py::class_<math_BFGS, std::unique_ptr<math_BFGS, Deleter<math_BFGS>>> cls_math_BFGS(mod, "math_BFGS", "This class implements the Broyden-Fletcher-Goldfarb-Shanno variant of Davidson-Fletcher-Powell minimization algorithm of a function of multiple variables.Knowledge of the function's gradient is required.");
	cls_math_BFGS.def(py::init<const Standard_Integer>(), py::arg("NbVariables"));
	cls_math_BFGS.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("NbVariables"), py::arg("Tolerance"));
	cls_math_BFGS.def(py::init<const Standard_Integer, const Standard_Real, const Standard_Integer>(), py::arg("NbVariables"), py::arg("Tolerance"), py::arg("NbIterations"));
	cls_math_BFGS.def(py::init<const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("NbVariables"), py::arg("Tolerance"), py::arg("NbIterations"), py::arg("ZEPS"));
	cls_math_BFGS.def("SetBoundary", (void (math_BFGS::*)(const math_Vector &, const math_Vector &)) &math_BFGS::SetBoundary, "Set boundaries for conditional optimization. The expected indices range of vectors is [1, NbVariables].", py::arg("theLeftBorder"), py::arg("theRightBorder"));
	cls_math_BFGS.def("Perform", (void (math_BFGS::*)(math_MultipleVarFunctionWithGradient &, const math_Vector &)) &math_BFGS::Perform, "Given the starting point StartingPoint, minimization is done on the function F. The solution F = Fi is found when : 2.0 * abs(Fi - Fi-1) <= Tolerance * (abs(Fi) + abs(Fi-1) + ZEPS). Tolerance, ZEPS and maximum number of iterations are given in the constructor.", py::arg("F"), py::arg("StartingPoint"));
	cls_math_BFGS.def("IsSolutionReached", (Standard_Boolean (math_BFGS::*)(math_MultipleVarFunctionWithGradient &) const ) &math_BFGS::IsSolutionReached, "This method is called at the end of each iteration to check if the solution is found. It can be redefined in a sub-class to implement a specific test to stop the iterations.", py::arg("F"));
	cls_math_BFGS.def("IsDone", (Standard_Boolean (math_BFGS::*)() const ) &math_BFGS::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_BFGS.def("Location", (const math_Vector & (math_BFGS::*)() const ) &math_BFGS::Location, "returns the location vector of the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_BFGS.def("Location", (void (math_BFGS::*)(math_Vector &) const ) &math_BFGS::Location, "outputs the location vector of the minimum in Loc. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Loc is not equal to the range of the StartingPoint.", py::arg("Loc"));
	cls_math_BFGS.def("Minimum", (Standard_Real (math_BFGS::*)() const ) &math_BFGS::Minimum, "returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_BFGS.def("Gradient", (const math_Vector & (math_BFGS::*)() const ) &math_BFGS::Gradient, "Returns the gradient vector at the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_BFGS.def("Gradient", (void (math_BFGS::*)(math_Vector &) const ) &math_BFGS::Gradient, "Returns the value of the gradient vector at the minimum in Grad. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Grad is not equal to the range of the StartingPoint.", py::arg("Grad"));
	cls_math_BFGS.def("NbIterations", (Standard_Integer (math_BFGS::*)() const ) &math_BFGS::NbIterations, "Returns the number of iterations really done in the calculation of the minimum. The exception NotDone is raised if the minimum was not found.");
	// FIXME cls_math_BFGS.def("Dump", (void (math_BFGS::*)(Standard_OStream &) const ) &math_BFGS::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_IntegerVector.hxx
	py::class_<math_IntegerVector, std::unique_ptr<math_IntegerVector, Deleter<math_IntegerVector>>> cls_math_IntegerVector(mod, "math_IntegerVector", "This class implements the real IntegerVector abstract data type. IntegerVectors can have an arbitrary range which must be define at the declaration and cannot be changed after this declaration. Example:");
	cls_math_IntegerVector.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theFirst"), py::arg("theLast"));
	cls_math_IntegerVector.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theFirst"), py::arg("theLast"), py::arg("theInitialValue"));
	cls_math_IntegerVector.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer>(), py::arg("theTab"), py::arg("theFirst"), py::arg("theLast"));
	cls_math_IntegerVector.def(py::init([] (const math_IntegerVector &other) {return new math_IntegerVector(other);}), "Copy constructor", py::arg("other"));
	cls_math_IntegerVector.def("Init", (void (math_IntegerVector::*)(const Standard_Integer)) &math_IntegerVector::Init, "Initialize an IntegerVector with all the elements set to theInitialValue.", py::arg("theInitialValue"));
	cls_math_IntegerVector.def("Length", (Standard_Integer (math_IntegerVector::*)() const ) &math_IntegerVector::Length, "returns the length of an IntegerVector");
	cls_math_IntegerVector.def("Lower", (Standard_Integer (math_IntegerVector::*)() const ) &math_IntegerVector::Lower, "returns the value of the Lower index of an IntegerVector.");
	cls_math_IntegerVector.def("Upper", (Standard_Integer (math_IntegerVector::*)() const ) &math_IntegerVector::Upper, "returns the value of the Upper index of an IntegerVector.");
	cls_math_IntegerVector.def("Norm", (Standard_Real (math_IntegerVector::*)() const ) &math_IntegerVector::Norm, "returns the value of the norm of an IntegerVector.");
	cls_math_IntegerVector.def("Norm2", (Standard_Real (math_IntegerVector::*)() const ) &math_IntegerVector::Norm2, "returns the value of the square of the norm of an IntegerVector.");
	cls_math_IntegerVector.def("Max", (Standard_Integer (math_IntegerVector::*)() const ) &math_IntegerVector::Max, "returns the value of the Index of the maximum element of an IntegerVector.");
	cls_math_IntegerVector.def("Min", (Standard_Integer (math_IntegerVector::*)() const ) &math_IntegerVector::Min, "returns the value of the Index of the minimum element of an IntegerVector.");
	cls_math_IntegerVector.def("Invert", (void (math_IntegerVector::*)()) &math_IntegerVector::Invert, "inverses an IntegerVector.");
	cls_math_IntegerVector.def("Inverse", (math_IntegerVector (math_IntegerVector::*)() const ) &math_IntegerVector::Inverse, "returns the inverse IntegerVector of an IntegerVector.");
	cls_math_IntegerVector.def("Set", (void (math_IntegerVector::*)(const Standard_Integer, const Standard_Integer, const math_IntegerVector &)) &math_IntegerVector::Set, "sets an IntegerVector from 'theI1' to 'theI2' to the IntegerVector 'theV'; An exception is raised if 'theI1' is less than 'LowerIndex' or 'theI2' is greater than 'UpperIndex' or 'theI1' is greater than 'theI2'. An exception is raised if 'theI2-theI1+1' is different from the Length of 'theV'.", py::arg("theI1"), py::arg("theI2"), py::arg("theV"));
	cls_math_IntegerVector.def("Slice", (math_IntegerVector (math_IntegerVector::*)(const Standard_Integer, const Standard_Integer) const ) &math_IntegerVector::Slice, "slices the values of the IntegerVector between 'theI1' and 'theI2': Example: [2, 1, 2, 3, 4, 5] becomes [2, 4, 3, 2, 1, 5] between 2 and 5. An exception is raised if 'theI1' is less than 'LowerIndex' or 'theI2' is greater than 'UpperIndex'.", py::arg("theI1"), py::arg("theI2"));
	cls_math_IntegerVector.def("Multiply", (void (math_IntegerVector::*)(const Standard_Integer)) &math_IntegerVector::Multiply, "returns the product of an IntegerVector by an integer value.", py::arg("theRight"));
	cls_math_IntegerVector.def("__imul__", (void (math_IntegerVector::*)(const Standard_Integer)) &math_IntegerVector::operator*=, "None", py::arg("theRight"));
	cls_math_IntegerVector.def("Multiplied", (math_IntegerVector (math_IntegerVector::*)(const Standard_Integer) const ) &math_IntegerVector::Multiplied, "returns the product of an IntegerVector by an integer value.", py::arg("theRight"));
	cls_math_IntegerVector.def("__mul__", (math_IntegerVector (math_IntegerVector::*)(const Standard_Integer) const ) &math_IntegerVector::operator*, py::is_operator(), "None", py::arg("theRight"));
	cls_math_IntegerVector.def("TMultiplied", (math_IntegerVector (math_IntegerVector::*)(const Standard_Integer) const ) &math_IntegerVector::TMultiplied, "returns the product of a vector and a real value.", py::arg("theRight"));
	cls_math_IntegerVector.def("Add", (void (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::Add, "adds the IntegerVector 'theRight' to an IntegerVector. An exception is raised if the IntegerVectors have not the same length. An exception is raised if the lengths are not equal.", py::arg("theRight"));
	cls_math_IntegerVector.def("__iadd__", (void (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::operator+=, "None", py::arg("theRight"));
	cls_math_IntegerVector.def("Added", (math_IntegerVector (math_IntegerVector::*)(const math_IntegerVector &) const ) &math_IntegerVector::Added, "adds the IntegerVector 'theRight' to an IntegerVector. An exception is raised if the IntegerVectors have not the same length. An exception is raised if the lengths are not equal.", py::arg("theRight"));
	cls_math_IntegerVector.def("__add__", (math_IntegerVector (math_IntegerVector::*)(const math_IntegerVector &) const ) &math_IntegerVector::operator+, py::is_operator(), "None", py::arg("theRight"));
	cls_math_IntegerVector.def("Add", (void (math_IntegerVector::*)(const math_IntegerVector &, const math_IntegerVector &)) &math_IntegerVector::Add, "sets an IntegerVector to the sum of the IntegerVector 'theLeft' and the IntegerVector 'theRight'. An exception is raised if the lengths are different.", py::arg("theLeft"), py::arg("theRight"));
	cls_math_IntegerVector.def("Subtract", (void (math_IntegerVector::*)(const math_IntegerVector &, const math_IntegerVector &)) &math_IntegerVector::Subtract, "sets an IntegerVector to the substraction of 'theRight' from 'theLeft'. An exception is raised if the IntegerVectors have not the same length.", py::arg("theLeft"), py::arg("theRight"));
	cls_math_IntegerVector.def("Value", (Standard_Integer & (math_IntegerVector::*)(const Standard_Integer) const ) &math_IntegerVector::Value, "accesses (in read or write mode) the value of index theNum of an IntegerVector.", py::arg("theNum"));
	cls_math_IntegerVector.def("__call__", (Standard_Integer & (math_IntegerVector::*)(const Standard_Integer) const ) &math_IntegerVector::operator(), py::is_operator(), "None", py::arg("theNum"));
	cls_math_IntegerVector.def("Initialized", (math_IntegerVector & (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::Initialized, "Initialises an IntegerVector by copying 'theOther'. An exception is raised if the Lengths are different.", py::arg("theOther"));
	cls_math_IntegerVector.def("assign", (math_IntegerVector & (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::operator=, py::is_operator(), "None", py::arg("theOther"));
	cls_math_IntegerVector.def("Multiplied", (Standard_Integer (math_IntegerVector::*)(const math_IntegerVector &) const ) &math_IntegerVector::Multiplied, "returns the inner product of 2 IntegerVectors. An exception is raised if the lengths are not equal.", py::arg("theRight"));
	cls_math_IntegerVector.def("__mul__", (Standard_Integer (math_IntegerVector::*)(const math_IntegerVector &) const ) &math_IntegerVector::operator*, py::is_operator(), "None", py::arg("theRight"));
	cls_math_IntegerVector.def("Opposite", (math_IntegerVector (math_IntegerVector::*)()) &math_IntegerVector::Opposite, "returns the opposite of an IntegerVector.");
	cls_math_IntegerVector.def("__sub__", (math_IntegerVector (math_IntegerVector::*)()) &math_IntegerVector::operator-, py::is_operator(), "None");
	cls_math_IntegerVector.def("Subtract", (void (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::Subtract, "returns the subtraction of 'theRight' from 'me'. An exception is raised if the IntegerVectors have not the same length.", py::arg("theRight"));
	cls_math_IntegerVector.def("__isub__", (void (math_IntegerVector::*)(const math_IntegerVector &)) &math_IntegerVector::operator-=, "None", py::arg("theRight"));
	cls_math_IntegerVector.def("Subtracted", (math_IntegerVector (math_IntegerVector::*)(const math_IntegerVector &) const ) &math_IntegerVector::Subtracted, "returns the subtraction of 'theRight' from 'me'. An exception is raised if the IntegerVectors have not the same length.", py::arg("theRight"));
	cls_math_IntegerVector.def("__sub__", (math_IntegerVector (math_IntegerVector::*)(const math_IntegerVector &) const ) &math_IntegerVector::operator-, py::is_operator(), "None", py::arg("theRight"));
	cls_math_IntegerVector.def("Multiply", (void (math_IntegerVector::*)(const Standard_Integer, const math_IntegerVector &)) &math_IntegerVector::Multiply, "returns the multiplication of an integer by an IntegerVector.", py::arg("theLeft"), py::arg("theRight"));
	// FIXME cls_math_IntegerVector.def("Dump", (void (math_IntegerVector::*)(Standard_OStream &) const ) &math_IntegerVector::Dump, "Prints on the stream theO information on the current state of the object. Is used to redefine the operator <<.", py::arg("theO"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_MultipleVarFunctionWithGradient.hxx
	py::class_<math_MultipleVarFunctionWithGradient, std::unique_ptr<math_MultipleVarFunctionWithGradient, Deleter<math_MultipleVarFunctionWithGradient>>, math_MultipleVarFunction> cls_math_MultipleVarFunctionWithGradient(mod, "math_MultipleVarFunctionWithGradient", "The abstract class MultipleVarFunctionWithGradient describes the virtual functions associated with a multiple variable function.");
	cls_math_MultipleVarFunctionWithGradient.def("NbVariables", (Standard_Integer (math_MultipleVarFunctionWithGradient::*)() const ) &math_MultipleVarFunctionWithGradient::NbVariables, "Returns the number of variables of the function.");
	cls_math_MultipleVarFunctionWithGradient.def("Value", [](math_MultipleVarFunctionWithGradient &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the values of the Functions <F> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_math_MultipleVarFunctionWithGradient.def("Gradient", (Standard_Boolean (math_MultipleVarFunctionWithGradient::*)(const math_Vector &, math_Vector &)) &math_MultipleVarFunctionWithGradient::Gradient, "Computes the gradient <G> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("G"));
	cls_math_MultipleVarFunctionWithGradient.def("Values", [](math_MultipleVarFunctionWithGradient &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F> and the gradient <G> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("G"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_FunctionSet.hxx
	py::class_<math_FunctionSet, std::unique_ptr<math_FunctionSet, Deleter<math_FunctionSet>>> cls_math_FunctionSet(mod, "math_FunctionSet", "This abstract class describes the virtual functions associated to a set on N Functions of M independent variables.");
	cls_math_FunctionSet.def("NbVariables", (Standard_Integer (math_FunctionSet::*)() const ) &math_FunctionSet::NbVariables, "Returns the number of variables of the function.");
	cls_math_FunctionSet.def("NbEquations", (Standard_Integer (math_FunctionSet::*)() const ) &math_FunctionSet::NbEquations, "Returns the number of equations of the function.");
	cls_math_FunctionSet.def("Value", (Standard_Boolean (math_FunctionSet::*)(const math_Vector &, math_Vector &)) &math_FunctionSet::Value, "Computes the values <F> of the functions for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_math_FunctionSet.def("GetStateNumber", (Standard_Integer (math_FunctionSet::*)()) &math_FunctionSet::GetStateNumber, "Returns the state of the function corresponding to the latestcall of any methods associated with the function. This function is called by each of the algorithms described later which define the function Integer Algorithm::StateNumber(). The algorithm has the responsibility to call this function when it has found a solution (i.e. a root or a minimum) and has to maintain the association between the solution found and this StateNumber. Byu default, this method returns 0 (which means for the algorithm: no state has been saved). It is the responsibility of the programmer to decide if he needs to save the current state of the function and to return an Integer that allows retrieval of the state.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_FunctionSetWithDerivatives.hxx
	py::class_<math_FunctionSetWithDerivatives, std::unique_ptr<math_FunctionSetWithDerivatives, Deleter<math_FunctionSetWithDerivatives>>, math_FunctionSet> cls_math_FunctionSetWithDerivatives(mod, "math_FunctionSetWithDerivatives", "This abstract class describes the virtual functions associated with a set of N Functions each of M independent variables.");
	cls_math_FunctionSetWithDerivatives.def("NbVariables", (Standard_Integer (math_FunctionSetWithDerivatives::*)() const ) &math_FunctionSetWithDerivatives::NbVariables, "Returns the number of variables of the function.");
	cls_math_FunctionSetWithDerivatives.def("NbEquations", (Standard_Integer (math_FunctionSetWithDerivatives::*)() const ) &math_FunctionSetWithDerivatives::NbEquations, "Returns the number of equations of the function.");
	cls_math_FunctionSetWithDerivatives.def("Value", (Standard_Boolean (math_FunctionSetWithDerivatives::*)(const math_Vector &, math_Vector &)) &math_FunctionSetWithDerivatives::Value, "Computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_math_FunctionSetWithDerivatives.def("Derivatives", (Standard_Boolean (math_FunctionSetWithDerivatives::*)(const math_Vector &, math_Matrix &)) &math_FunctionSetWithDerivatives::Derivatives, "Returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_math_FunctionSetWithDerivatives.def("Values", (Standard_Boolean (math_FunctionSetWithDerivatives::*)(const math_Vector &, math_Vector &, math_Matrix &)) &math_FunctionSetWithDerivatives::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_FunctionSetRoot.hxx
	py::class_<math_FunctionSetRoot, std::unique_ptr<math_FunctionSetRoot, Deleter<math_FunctionSetRoot>>> cls_math_FunctionSetRoot(mod, "math_FunctionSetRoot", "The math_FunctionSetRoot class calculates the root of a set of N functions of M variables (N<M, N=M or N>M). Knowing an initial guess of the solution and using a minimization algorithm, a search is made in the Newton direction and then in the Gradient direction if there is no success in the Newton direction. This algorithm can also be used for functions minimization. Knowledge of all the partial derivatives (the Jacobian) is required.");
	cls_math_FunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const math_Vector &>(), py::arg("F"), py::arg("Tolerance"));
	cls_math_FunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const math_Vector &, const Standard_Integer>(), py::arg("F"), py::arg("Tolerance"), py::arg("NbIterations"));
	cls_math_FunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &>(), py::arg("F"));
	cls_math_FunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const Standard_Integer>(), py::arg("F"), py::arg("NbIterations"));
	cls_math_FunctionSetRoot.def("SetTolerance", (void (math_FunctionSetRoot::*)(const math_Vector &)) &math_FunctionSetRoot::SetTolerance, "Initializes the tolerance values.", py::arg("Tolerance"));
	cls_math_FunctionSetRoot.def("IsSolutionReached", (Standard_Boolean (math_FunctionSetRoot::*)(math_FunctionSetWithDerivatives &)) &math_FunctionSetRoot::IsSolutionReached, "This routine is called at the end of each iteration to check if the solution was found. It can be redefined in a sub-class to implement a specific test to stop the iterations. In this case, the solution is found when: abs(Xi - Xi-1) <= Tolerance for all unknowns.", py::arg("F"));
	cls_math_FunctionSetRoot.def("Perform", [](math_FunctionSetRoot &self, math_FunctionSetWithDerivatives & a0, const math_Vector & a1) -> void { return self.Perform(a0, a1); }, py::arg("theFunction"), py::arg("theStartingPoint"));
	cls_math_FunctionSetRoot.def("Perform", (void (math_FunctionSetRoot::*)(math_FunctionSetWithDerivatives &, const math_Vector &, const Standard_Boolean)) &math_FunctionSetRoot::Perform, "Improves the root of function from the initial guess point. The infinum and supremum may be given to constrain the solution. In this case, the solution is found when: abs(Xi - Xi-1)(j) <= Tolerance(j) for all unknowns.", py::arg("theFunction"), py::arg("theStartingPoint"), py::arg("theStopOnDivergent"));
	cls_math_FunctionSetRoot.def("Perform", [](math_FunctionSetRoot &self, math_FunctionSetWithDerivatives & a0, const math_Vector & a1, const math_Vector & a2, const math_Vector & a3) -> void { return self.Perform(a0, a1, a2, a3); }, py::arg("theFunction"), py::arg("theStartingPoint"), py::arg("theInfBound"), py::arg("theSupBound"));
	cls_math_FunctionSetRoot.def("Perform", (void (math_FunctionSetRoot::*)(math_FunctionSetWithDerivatives &, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Boolean)) &math_FunctionSetRoot::Perform, "Improves the root of function from the initial guess point. The infinum and supremum may be given to constrain the solution. In this case, the solution is found when: abs(Xi - Xi-1) <= Tolerance for all unknowns.", py::arg("theFunction"), py::arg("theStartingPoint"), py::arg("theInfBound"), py::arg("theSupBound"), py::arg("theStopOnDivergent"));
	cls_math_FunctionSetRoot.def("IsDone", (Standard_Boolean (math_FunctionSetRoot::*)() const ) &math_FunctionSetRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_FunctionSetRoot.def("NbIterations", (Standard_Integer (math_FunctionSetRoot::*)() const ) &math_FunctionSetRoot::NbIterations, "Returns the number of iterations really done during the computation of the root. Exception NotDone is raised if the root was not found.");
	cls_math_FunctionSetRoot.def("StateNumber", (Standard_Integer (math_FunctionSetRoot::*)() const ) &math_FunctionSetRoot::StateNumber, "returns the stateNumber (as returned by F.GetStateNumber()) associated to the root found.");
	cls_math_FunctionSetRoot.def("Root", (const math_Vector & (math_FunctionSetRoot::*)() const ) &math_FunctionSetRoot::Root, "Returns the value of the root of function F. Exception NotDone is raised if the root was not found.");
	cls_math_FunctionSetRoot.def("Root", (void (math_FunctionSetRoot::*)(math_Vector &) const ) &math_FunctionSetRoot::Root, "Outputs the root vector in Root. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Root is not equal to the range of the StartingPoint.", py::arg("Root"));
	cls_math_FunctionSetRoot.def("Derivative", (const math_Matrix & (math_FunctionSetRoot::*)() const ) &math_FunctionSetRoot::Derivative, "Returns the matrix value of the derivative at the root. Exception NotDone is raised if the root was not found.");
	cls_math_FunctionSetRoot.def("Derivative", (void (math_FunctionSetRoot::*)(math_Matrix &) const ) &math_FunctionSetRoot::Derivative, "outputs the matrix value of the derivative at the root in Der. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the column range of <Der> is not equal to the range of the startingPoint.", py::arg("Der"));
	cls_math_FunctionSetRoot.def("FunctionSetErrors", (const math_Vector & (math_FunctionSetRoot::*)() const ) &math_FunctionSetRoot::FunctionSetErrors, "returns the vector value of the error done on the functions at the root. Exception NotDone is raised if the root was not found.");
	cls_math_FunctionSetRoot.def("FunctionSetErrors", (void (math_FunctionSetRoot::*)(math_Vector &) const ) &math_FunctionSetRoot::FunctionSetErrors, "outputs the vector value of the error done on the functions at the root in Err. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Err is not equal to the range of the StartingPoint.", py::arg("Err"));
	// FIXME cls_math_FunctionSetRoot.def("Dump", (void (math_FunctionSetRoot::*)(Standard_OStream &) const ) &math_FunctionSetRoot::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));
	cls_math_FunctionSetRoot.def("IsDivergent", (Standard_Boolean (math_FunctionSetRoot::*)() const ) &math_FunctionSetRoot::IsDivergent, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_MultipleVarFunctionWithHessian.hxx
	py::class_<math_MultipleVarFunctionWithHessian, std::unique_ptr<math_MultipleVarFunctionWithHessian, Deleter<math_MultipleVarFunctionWithHessian>>, math_MultipleVarFunctionWithGradient> cls_math_MultipleVarFunctionWithHessian(mod, "math_MultipleVarFunctionWithHessian", "None");
	cls_math_MultipleVarFunctionWithHessian.def("NbVariables", (Standard_Integer (math_MultipleVarFunctionWithHessian::*)() const ) &math_MultipleVarFunctionWithHessian::NbVariables, "returns the number of variables of the function.");
	cls_math_MultipleVarFunctionWithHessian.def("Value", [](math_MultipleVarFunctionWithHessian &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the values of the Functions <F> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_math_MultipleVarFunctionWithHessian.def("Gradient", (Standard_Boolean (math_MultipleVarFunctionWithHessian::*)(const math_Vector &, math_Vector &)) &math_MultipleVarFunctionWithHessian::Gradient, "computes the gradient <G> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("G"));
	cls_math_MultipleVarFunctionWithHessian.def("Values", [](math_MultipleVarFunctionWithHessian &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F> and the gradient <G> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("G"));
	cls_math_MultipleVarFunctionWithHessian.def("Values", [](math_MultipleVarFunctionWithHessian &self, const math_Vector & X, Standard_Real & F, math_Vector & G, math_Matrix & H){ Standard_Boolean rv = self.Values(X, F, G, H); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F>, the gradient <G> and the hessian <H> of the functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("G"), py::arg("H"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_NewtonMinimum.hxx
	py::class_<math_NewtonMinimum, std::unique_ptr<math_NewtonMinimum, Deleter<math_NewtonMinimum>>> cls_math_NewtonMinimum(mod, "math_NewtonMinimum", "None");
	cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &>(), py::arg("theFunction"));
	cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"));
	cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"));
	cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"), py::arg("theConvexity"));
	cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Boolean>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"), py::arg("theConvexity"), py::arg("theWithSingularity"));
	cls_math_NewtonMinimum.def("Perform", (void (math_NewtonMinimum::*)(math_MultipleVarFunctionWithHessian &, const math_Vector &)) &math_NewtonMinimum::Perform, "Search the solution.", py::arg("theFunction"), py::arg("theStartingPoint"));
	cls_math_NewtonMinimum.def("IsConverged", (Standard_Boolean (math_NewtonMinimum::*)() const ) &math_NewtonMinimum::IsConverged, "This method is called at the end of each iteration to check the convergence: || Xi+1 - Xi || < Tolerance or || F(Xi+1) - F(Xi)|| < Tolerance * || F(Xi) || It can be redefined in a sub-class to implement a specific test.");
	cls_math_NewtonMinimum.def("IsDone", (Standard_Boolean (math_NewtonMinimum::*)() const ) &math_NewtonMinimum::IsDone, "Tests if an error has occurred.");
	// cls_math_NewtonMinimum.def("IsConvex", (Standard_Boolean (math_NewtonMinimum::*)() const ) &math_NewtonMinimum::IsConvex, "Tests if the Function is convexe during optimization.");
	cls_math_NewtonMinimum.def("Location", (const math_Vector & (math_NewtonMinimum::*)() const ) &math_NewtonMinimum::Location, "returns the location vector of the minimum. Exception NotDone is raised if an error has occurred.");
	cls_math_NewtonMinimum.def("Location", (void (math_NewtonMinimum::*)(math_Vector &) const ) &math_NewtonMinimum::Location, "outputs the location vector of the minimum in Loc. Exception NotDone is raised if an error has occurred. Exception DimensionError is raised if the range of Loc is not equal to the range of the StartingPoint.", py::arg("Loc"));
	cls_math_NewtonMinimum.def("SetBoundary", (void (math_NewtonMinimum::*)(const math_Vector &, const math_Vector &)) &math_NewtonMinimum::SetBoundary, "Set boundaries.", py::arg("theLeftBorder"), py::arg("theRightBorder"));
	cls_math_NewtonMinimum.def("Minimum", (Standard_Real (math_NewtonMinimum::*)() const ) &math_NewtonMinimum::Minimum, "returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_NewtonMinimum.def("Gradient", (const math_Vector & (math_NewtonMinimum::*)() const ) &math_NewtonMinimum::Gradient, "returns the gradient vector at the minimum. Exception NotDone is raised if an error has occurred.the minimum was not found.");
	cls_math_NewtonMinimum.def("Gradient", (void (math_NewtonMinimum::*)(math_Vector &) const ) &math_NewtonMinimum::Gradient, "outputs the gradient vector at the minimum in Grad. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Grad is not equal to the range of the StartingPoint.", py::arg("Grad"));
	cls_math_NewtonMinimum.def("NbIterations", (Standard_Integer (math_NewtonMinimum::*)() const ) &math_NewtonMinimum::NbIterations, "returns the number of iterations really done in the calculation of the minimum. The exception NotDone is raised if an error has occurred.");
	cls_math_NewtonMinimum.def("GetStatus", (math_Status (math_NewtonMinimum::*)() const ) &math_NewtonMinimum::GetStatus, "Returns the Status of computation. The exception NotDone is raised if an error has occurred.");
	// FIXME cls_math_NewtonMinimum.def("Dump", (void (math_NewtonMinimum::*)(Standard_OStream &) const ) &math_NewtonMinimum::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_FunctionSample.hxx
	py::class_<math_FunctionSample, std::unique_ptr<math_FunctionSample, Deleter<math_FunctionSample>>> cls_math_FunctionSample(mod, "math_FunctionSample", "This class gives a default sample (constant difference of parameter) for a function defined between two bound A,B.");
	cls_math_FunctionSample.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("A"), py::arg("B"), py::arg("N"));
	cls_math_FunctionSample.def("Bounds", [](math_FunctionSample &self, Standard_Real & A, Standard_Real & B){ self.Bounds(A, B); return std::tuple<Standard_Real &, Standard_Real &>(A, B); }, "Returns the bounds of parameters.", py::arg("A"), py::arg("B"));
	cls_math_FunctionSample.def("NbPoints", (Standard_Integer (math_FunctionSample::*)() const ) &math_FunctionSample::NbPoints, "Returns the number of sample points.");
	cls_math_FunctionSample.def("GetParameter", (Standard_Real (math_FunctionSample::*)(const Standard_Integer) const ) &math_FunctionSample::GetParameter, "Returns the value of parameter of the point of range Index : A + ((Index-1)/(NbPoints-1))*B. An exception is raised if Index<=0 or Index>NbPoints.", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_DirectPolynomialRoots.hxx
	py::class_<math_DirectPolynomialRoots, std::unique_ptr<math_DirectPolynomialRoots, Deleter<math_DirectPolynomialRoots>>> cls_math_DirectPolynomialRoots(mod, "math_DirectPolynomialRoots", "This class implements the calculation of all the real roots of a real polynomial of degree <= 4 using a direct method. Once found, the roots are polished using the Newton method.");
	cls_math_DirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"));
	cls_math_DirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
	cls_math_DirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"));
	cls_math_DirectPolynomialRoots.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"));
	cls_math_DirectPolynomialRoots.def("IsDone", (Standard_Boolean (math_DirectPolynomialRoots::*)() const ) &math_DirectPolynomialRoots::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_DirectPolynomialRoots.def("InfiniteRoots", (Standard_Boolean (math_DirectPolynomialRoots::*)() const ) &math_DirectPolynomialRoots::InfiniteRoots, "Returns true if there is an infinity of roots, otherwise returns false.");
	cls_math_DirectPolynomialRoots.def("NbSolutions", (Standard_Integer (math_DirectPolynomialRoots::*)() const ) &math_DirectPolynomialRoots::NbSolutions, "returns the number of solutions. An exception is raised if there are an infinity of roots.");
	cls_math_DirectPolynomialRoots.def("Value", (Standard_Real (math_DirectPolynomialRoots::*)(const Standard_Integer) const ) &math_DirectPolynomialRoots::Value, "returns the value of the Nieme root. An exception is raised if there are an infinity of roots. Exception RangeError is raised if Nieme is < 1 or Nieme > NbSolutions.", py::arg("Nieme"));
	// FIXME cls_math_DirectPolynomialRoots.def("Dump", (void (math_DirectPolynomialRoots::*)(Standard_OStream &) const ) &math_DirectPolynomialRoots::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_TrigonometricFunctionRoots.hxx
	py::class_<math_TrigonometricFunctionRoots, std::unique_ptr<math_TrigonometricFunctionRoots, Deleter<math_TrigonometricFunctionRoots>>> cls_math_TrigonometricFunctionRoots(mod, "math_TrigonometricFunctionRoots", "This class implements the solutions of the equation a*Cos(x)*Cos(x) + 2*b*Cos(x)*Sin(x) + c*Cos(x) + d*Sin(x) + e The degree of this equation can be 4, 3 or 2.");
	cls_math_TrigonometricFunctionRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("InfBound"), py::arg("SupBound"));
	cls_math_TrigonometricFunctionRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("D"), py::arg("E"), py::arg("InfBound"), py::arg("SupBound"));
	cls_math_TrigonometricFunctionRoots.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("InfBound"), py::arg("SupBound"));
	cls_math_TrigonometricFunctionRoots.def("IsDone", (Standard_Boolean (math_TrigonometricFunctionRoots::*)() const ) &math_TrigonometricFunctionRoots::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_TrigonometricFunctionRoots.def("InfiniteRoots", (Standard_Boolean (math_TrigonometricFunctionRoots::*)() const ) &math_TrigonometricFunctionRoots::InfiniteRoots, "Returns true if there is an infinity of roots, otherwise returns false.");
	cls_math_TrigonometricFunctionRoots.def("Value", (Standard_Real (math_TrigonometricFunctionRoots::*)(const Standard_Integer) const ) &math_TrigonometricFunctionRoots::Value, "Returns the solution of range Index. An exception is raised if NotDone. An exception is raised if Index>NbSolutions. An exception is raised if there is an infinity of solutions.", py::arg("Index"));
	cls_math_TrigonometricFunctionRoots.def("NbSolutions", (Standard_Integer (math_TrigonometricFunctionRoots::*)() const ) &math_TrigonometricFunctionRoots::NbSolutions, "Returns the number of solutions found. An exception is raised if NotDone. An exception is raised if there is an infinity of solutions.");
	// FIXME cls_math_TrigonometricFunctionRoots.def("Dump", (void (math_TrigonometricFunctionRoots::*)(Standard_OStream &) const ) &math_TrigonometricFunctionRoots::Dump, "Prints information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Gauss.hxx
	py::class_<math_Gauss, std::unique_ptr<math_Gauss, Deleter<math_Gauss>>> cls_math_Gauss(mod, "math_Gauss", "This class implements the Gauss LU decomposition (Crout algorithm) with partial pivoting (rows interchange) of a square matrix and the different possible derived calculation : - solution of a set of linear equations. - inverse of a matrix. - determinant of a matrix.");
	cls_math_Gauss.def(py::init<const math_Matrix &>(), py::arg("A"));
	cls_math_Gauss.def(py::init<const math_Matrix &, const Standard_Real>(), py::arg("A"), py::arg("MinPivot"));
	cls_math_Gauss.def("IsDone", (Standard_Boolean (math_Gauss::*)() const ) &math_Gauss::IsDone, "Returns true if the computations are successful, otherwise returns false");
	cls_math_Gauss.def("Solve", (void (math_Gauss::*)(const math_Vector &, math_Vector &) const ) &math_Gauss::Solve, "Given the input Vector B this routine returns the solution X of the set of linear equations A . X = B. Exception NotDone is raised if the decomposition of A was not done successfully. Exception DimensionError is raised if the range of B is not equal to the number of rows of A.", py::arg("B"), py::arg("X"));
	cls_math_Gauss.def("Solve", (void (math_Gauss::*)(math_Vector &) const ) &math_Gauss::Solve, "Given the input Vector B this routine solves the set of linear equations A . X = B. B is replaced by the vector solution X. Exception NotDone is raised if the decomposition of A was not done successfully. Exception DimensionError is raised if the range of B is not equal to the number of rows of A.", py::arg("B"));
	cls_math_Gauss.def("Determinant", (Standard_Real (math_Gauss::*)() const ) &math_Gauss::Determinant, "This routine returns the value of the determinant of the previously LU decomposed matrix A. Exception NotDone may be raised if the decomposition of A was not done successfully, zero is returned if the matrix A was considered as singular.");
	cls_math_Gauss.def("Invert", (void (math_Gauss::*)(math_Matrix &) const ) &math_Gauss::Invert, "This routine outputs Inv the inverse of the previously LU decomposed matrix A. Exception DimensionError is raised if the ranges of B are not equal to the ranges of A.", py::arg("Inv"));
	// FIXME cls_math_Gauss.def("Dump", (void (math_Gauss::*)(Standard_OStream &) const ) &math_Gauss::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_GaussLeastSquare.hxx
	py::class_<math_GaussLeastSquare, std::unique_ptr<math_GaussLeastSquare, Deleter<math_GaussLeastSquare>>> cls_math_GaussLeastSquare(mod, "math_GaussLeastSquare", "This class implements the least square solution of a set of n linear equations of m unknowns (n >= m) using the gauss LU decomposition algorithm. This algorithm is more likely subject to numerical instability than math_SVD.");
	cls_math_GaussLeastSquare.def(py::init<const math_Matrix &>(), py::arg("A"));
	cls_math_GaussLeastSquare.def(py::init<const math_Matrix &, const Standard_Real>(), py::arg("A"), py::arg("MinPivot"));
	cls_math_GaussLeastSquare.def("IsDone", (Standard_Boolean (math_GaussLeastSquare::*)() const ) &math_GaussLeastSquare::IsDone, "Returns true if the computations are successful, otherwise returns false.e");
	cls_math_GaussLeastSquare.def("Solve", (void (math_GaussLeastSquare::*)(const math_Vector &, math_Vector &) const ) &math_GaussLeastSquare::Solve, "Given the input Vector <B> this routine solves the set of linear equations A . X = B. Exception NotDone is raised if the decomposition of A was not done successfully. Exception DimensionError is raised if the range of B Inv is not equal to the rowrange of A. Exception DimensionError is raised if the range of X Inv is not equal to the colrange of A.", py::arg("B"), py::arg("X"));
	// FIXME cls_math_GaussLeastSquare.def("Dump", (void (math_GaussLeastSquare::*)(Standard_OStream &) const ) &math_GaussLeastSquare::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_SVD.hxx
	py::class_<math_SVD, std::unique_ptr<math_SVD, Deleter<math_SVD>>> cls_math_SVD(mod, "math_SVD", "SVD implements the solution of a set of N linear equations of M unknowns without condition on N or M. The Singular Value Decomposition algorithm is used. For singular or nearly singular matrices SVD is a better choice than Gauss or GaussLeastSquare.");
	cls_math_SVD.def(py::init<const math_Matrix &>(), py::arg("A"));
	cls_math_SVD.def("IsDone", (Standard_Boolean (math_SVD::*)() const ) &math_SVD::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_SVD.def("Solve", [](math_SVD &self, const math_Vector & a0, math_Vector & a1) -> void { return self.Solve(a0, a1); }, py::arg("B"), py::arg("X"));
	cls_math_SVD.def("Solve", (void (math_SVD::*)(const math_Vector &, math_Vector &, const Standard_Real) const ) &math_SVD::Solve, "Given the input Vector B this routine solves the set of linear equations A . X = B. Exception NotDone is raised if the decomposition of A was not done successfully. Exception DimensionError is raised if the range of B is not equal to the rowrange of A. Exception DimensionError is raised if the range of X is not equal to the colrange of A.", py::arg("B"), py::arg("X"), py::arg("Eps"));
	cls_math_SVD.def("PseudoInverse", [](math_SVD &self, math_Matrix & a0) -> void { return self.PseudoInverse(a0); }, py::arg("Inv"));
	cls_math_SVD.def("PseudoInverse", (void (math_SVD::*)(math_Matrix &, const Standard_Real) const ) &math_SVD::PseudoInverse, "Computes the inverse Inv of matrix A such as A * Inverse = Identity. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false). Standard_DimensionError if the ranges of Inv are compatible with the ranges of A.", py::arg("Inv"), py::arg("Eps"));
	// FIXME cls_math_SVD.def("Dump", (void (math_SVD::*)(Standard_OStream &) const ) &math_SVD::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_FunctionRoots.hxx
	py::class_<math_FunctionRoots, std::unique_ptr<math_FunctionRoots, Deleter<math_FunctionRoots>>> cls_math_FunctionRoots(mod, "math_FunctionRoots", "This class implements an algorithm which finds all the real roots of a function with derivative within a given range. Knowledge of the derivative is required.");
	cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"));
	cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"), py::arg("EpsX"));
	cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"), py::arg("EpsX"), py::arg("EpsF"));
	cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"), py::arg("EpsX"), py::arg("EpsF"), py::arg("EpsNull"));
	cls_math_FunctionRoots.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("NbSample"), py::arg("EpsX"), py::arg("EpsF"), py::arg("EpsNull"), py::arg("K"));
	cls_math_FunctionRoots.def("IsDone", (Standard_Boolean (math_FunctionRoots::*)() const ) &math_FunctionRoots::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_FunctionRoots.def("IsAllNull", (Standard_Boolean (math_FunctionRoots::*)() const ) &math_FunctionRoots::IsAllNull, "returns true if the function is considered as null between A and B. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).");
	cls_math_FunctionRoots.def("NbSolutions", (Standard_Integer (math_FunctionRoots::*)() const ) &math_FunctionRoots::NbSolutions, "Returns the number of solutions found. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).");
	cls_math_FunctionRoots.def("Value", (Standard_Real (math_FunctionRoots::*)(const Standard_Integer) const ) &math_FunctionRoots::Value, "Returns the Nth value of the root of function F. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).", py::arg("Nieme"));
	cls_math_FunctionRoots.def("StateNumber", (Standard_Integer (math_FunctionRoots::*)(const Standard_Integer) const ) &math_FunctionRoots::StateNumber, "returns the StateNumber of the Nieme root. Exception RangeError is raised if Nieme is < 1 or Nieme > NbSolutions.", py::arg("Nieme"));
	// FIXME cls_math_FunctionRoots.def("Dump", (void (math_FunctionRoots::*)(Standard_OStream &) const ) &math_FunctionRoots::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_BissecNewton.hxx
	py::class_<math_BissecNewton, std::unique_ptr<math_BissecNewton, Deleter<math_BissecNewton>>> cls_math_BissecNewton(mod, "math_BissecNewton", "This class implements a combination of Newton-Raphson and bissection methods to find the root of the function between two bounds. Knowledge of the derivative is required.");
	cls_math_BissecNewton.def(py::init<const Standard_Real>(), py::arg("theXTolerance"));
	cls_math_BissecNewton.def("Perform", [](math_BissecNewton &self, math_FunctionWithDerivative & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); }, py::arg("F"), py::arg("Bound1"), py::arg("Bound2"));
	cls_math_BissecNewton.def("Perform", (void (math_BissecNewton::*)(math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer)) &math_BissecNewton::Perform, "A combination of Newton-Raphson and bissection methods is done to find the root of the function F between the bounds Bound1 and Bound2 on the function F. The tolerance required on the root is given by TolX. The solution is found when: abs(Xi - Xi-1) <= TolX and F(Xi) * F(Xi-1) <= 0 The maximum number of iterations allowed is given by NbIterations.", py::arg("F"), py::arg("Bound1"), py::arg("Bound2"), py::arg("NbIterations"));
	cls_math_BissecNewton.def("IsSolutionReached", (Standard_Boolean (math_BissecNewton::*)(math_FunctionWithDerivative &)) &math_BissecNewton::IsSolutionReached, "This method is called at the end of each iteration to check if the solution has been found. It can be redefined in a sub-class to implement a specific test to stop the iterations.", py::arg("theFunction"));
	cls_math_BissecNewton.def("IsDone", (Standard_Boolean (math_BissecNewton::*)() const ) &math_BissecNewton::IsDone, "Tests is the root has been successfully found.");
	cls_math_BissecNewton.def("Root", (Standard_Real (math_BissecNewton::*)() const ) &math_BissecNewton::Root, "returns the value of the root. Exception NotDone is raised if the minimum was not found.");
	cls_math_BissecNewton.def("Derivative", (Standard_Real (math_BissecNewton::*)() const ) &math_BissecNewton::Derivative, "returns the value of the derivative at the root. Exception NotDone is raised if the minimum was not found.");
	cls_math_BissecNewton.def("Value", (Standard_Real (math_BissecNewton::*)() const ) &math_BissecNewton::Value, "returns the value of the function at the root. Exception NotDone is raised if the minimum was not found.");
	// FIXME cls_math_BissecNewton.def("Dump", (void (math_BissecNewton::*)(Standard_OStream &) const ) &math_BissecNewton::Dump, "Prints on the stream o information on the current state of the object. Is used to redifine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_FunctionRoot.hxx
	py::class_<math_FunctionRoot, std::unique_ptr<math_FunctionRoot, Deleter<math_FunctionRoot>>> cls_math_FunctionRoot(mod, "math_FunctionRoot", "This class implements the computation of a root of a function of a single variable which is near an initial guess using a minimization algorithm.Knowledge of the derivative is required. The algorithm used is the same as in");
	cls_math_FunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Guess"), py::arg("Tolerance"));
	cls_math_FunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Guess"), py::arg("Tolerance"), py::arg("NbIterations"));
	cls_math_FunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Guess"), py::arg("Tolerance"), py::arg("A"), py::arg("B"));
	cls_math_FunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Guess"), py::arg("Tolerance"), py::arg("A"), py::arg("B"), py::arg("NbIterations"));
	cls_math_FunctionRoot.def("IsDone", (Standard_Boolean (math_FunctionRoot::*)() const ) &math_FunctionRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_FunctionRoot.def("Root", (Standard_Real (math_FunctionRoot::*)() const ) &math_FunctionRoot::Root, "returns the value of the root. Exception NotDone is raised if the root was not found.");
	cls_math_FunctionRoot.def("Derivative", (Standard_Real (math_FunctionRoot::*)() const ) &math_FunctionRoot::Derivative, "returns the value of the derivative at the root. Exception NotDone is raised if the root was not found.");
	cls_math_FunctionRoot.def("Value", (Standard_Real (math_FunctionRoot::*)() const ) &math_FunctionRoot::Value, "returns the value of the function at the root. Exception NotDone is raised if the root was not found.");
	cls_math_FunctionRoot.def("NbIterations", (Standard_Integer (math_FunctionRoot::*)() const ) &math_FunctionRoot::NbIterations, "returns the number of iterations really done on the computation of the Root. Exception NotDone is raised if the root was not found.");
	// FIXME cls_math_FunctionRoot.def("Dump", (void (math_FunctionRoot::*)(Standard_OStream &) const ) &math_FunctionRoot::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_NewtonFunctionRoot.hxx
	py::class_<math_NewtonFunctionRoot, std::unique_ptr<math_NewtonFunctionRoot, Deleter<math_NewtonFunctionRoot>>> cls_math_NewtonFunctionRoot(mod, "math_NewtonFunctionRoot", "This class implements the calculation of a root of a function of a single variable starting from an initial near guess using the Newton algorithm. Knowledge of the derivative is required.");
	cls_math_NewtonFunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Guess"), py::arg("EpsX"), py::arg("EpsF"));
	cls_math_NewtonFunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Guess"), py::arg("EpsX"), py::arg("EpsF"), py::arg("NbIterations"));
	cls_math_NewtonFunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Guess"), py::arg("EpsX"), py::arg("EpsF"), py::arg("A"), py::arg("B"));
	cls_math_NewtonFunctionRoot.def(py::init<math_FunctionWithDerivative &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Guess"), py::arg("EpsX"), py::arg("EpsF"), py::arg("A"), py::arg("B"), py::arg("NbIterations"));
	cls_math_NewtonFunctionRoot.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("EpsX"), py::arg("EpsF"));
	cls_math_NewtonFunctionRoot.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("A"), py::arg("B"), py::arg("EpsX"), py::arg("EpsF"), py::arg("NbIterations"));
	cls_math_NewtonFunctionRoot.def("Perform", (void (math_NewtonFunctionRoot::*)(math_FunctionWithDerivative &, const Standard_Real)) &math_NewtonFunctionRoot::Perform, "is used internally by the constructors.", py::arg("F"), py::arg("Guess"));
	cls_math_NewtonFunctionRoot.def("IsDone", (Standard_Boolean (math_NewtonFunctionRoot::*)() const ) &math_NewtonFunctionRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_NewtonFunctionRoot.def("Root", (Standard_Real (math_NewtonFunctionRoot::*)() const ) &math_NewtonFunctionRoot::Root, "Returns the value of the root of function <F>. Exception NotDone is raised if the root was not found.");
	cls_math_NewtonFunctionRoot.def("Derivative", (Standard_Real (math_NewtonFunctionRoot::*)() const ) &math_NewtonFunctionRoot::Derivative, "returns the value of the derivative at the root. Exception NotDone is raised if the root was not found.");
	cls_math_NewtonFunctionRoot.def("Value", (Standard_Real (math_NewtonFunctionRoot::*)() const ) &math_NewtonFunctionRoot::Value, "returns the value of the function at the root. Exception NotDone is raised if the root was not found.");
	cls_math_NewtonFunctionRoot.def("NbIterations", (Standard_Integer (math_NewtonFunctionRoot::*)() const ) &math_NewtonFunctionRoot::NbIterations, "Returns the number of iterations really done on the computation of the Root. Exception NotDone is raised if the root was not found.");
	// FIXME cls_math_NewtonFunctionRoot.def("Dump", (void (math_NewtonFunctionRoot::*)(Standard_OStream &) const ) &math_NewtonFunctionRoot::Dump, "Prints information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_BracketedRoot.hxx
	py::class_<math_BracketedRoot, std::unique_ptr<math_BracketedRoot, Deleter<math_BracketedRoot>>> cls_math_BracketedRoot(mod, "math_BracketedRoot", "This class implements the Brent method to find the root of a function located within two bounds. No knowledge of the derivative is required.");
	cls_math_BracketedRoot.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Bound1"), py::arg("Bound2"), py::arg("Tolerance"));
	cls_math_BracketedRoot.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Bound1"), py::arg("Bound2"), py::arg("Tolerance"), py::arg("NbIterations"));
	cls_math_BracketedRoot.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("F"), py::arg("Bound1"), py::arg("Bound2"), py::arg("Tolerance"), py::arg("NbIterations"), py::arg("ZEPS"));
	cls_math_BracketedRoot.def("IsDone", (Standard_Boolean (math_BracketedRoot::*)() const ) &math_BracketedRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_BracketedRoot.def("Root", (Standard_Real (math_BracketedRoot::*)() const ) &math_BracketedRoot::Root, "returns the value of the root. Exception NotDone is raised if the minimum was not found.");
	cls_math_BracketedRoot.def("Value", (Standard_Real (math_BracketedRoot::*)() const ) &math_BracketedRoot::Value, "returns the value of the function at the root. Exception NotDone is raised if the minimum was not found.");
	cls_math_BracketedRoot.def("NbIterations", (Standard_Integer (math_BracketedRoot::*)() const ) &math_BracketedRoot::NbIterations, "returns the number of iterations really done during the computation of the Root. Exception NotDone is raised if the minimum was not found.");
	// FIXME cls_math_BracketedRoot.def("Dump", (void (math_BracketedRoot::*)(Standard_OStream &) const ) &math_BracketedRoot::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_NewtonFunctionSetRoot.hxx
	py::class_<math_NewtonFunctionSetRoot, std::unique_ptr<math_NewtonFunctionSetRoot, Deleter<math_NewtonFunctionSetRoot>>> cls_math_NewtonFunctionSetRoot(mod, "math_NewtonFunctionSetRoot", "This class computes the root of a set of N functions of N variables, knowing an initial guess at the solution and using the Newton Raphson algorithm. Knowledge of all the partial derivatives (Jacobian) is required.");
	cls_math_NewtonFunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const math_Vector &, const Standard_Real>(), py::arg("theFunction"), py::arg("theXTolerance"), py::arg("theFTolerance"));
	cls_math_NewtonFunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const math_Vector &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theXTolerance"), py::arg("theFTolerance"), py::arg("tehNbIterations"));
	cls_math_NewtonFunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const Standard_Real>(), py::arg("theFunction"), py::arg("theFTolerance"));
	cls_math_NewtonFunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theFTolerance"), py::arg("theNbIterations"));
	cls_math_NewtonFunctionSetRoot.def("SetTolerance", (void (math_NewtonFunctionSetRoot::*)(const math_Vector &)) &math_NewtonFunctionSetRoot::SetTolerance, "Initializes the tolerance values for the unknowns.", py::arg("XTol"));
	cls_math_NewtonFunctionSetRoot.def("Perform", (void (math_NewtonFunctionSetRoot::*)(math_FunctionSetWithDerivatives &, const math_Vector &)) &math_NewtonFunctionSetRoot::Perform, "The Newton method is done to improve the root of the function from the initial guess point. The solution is found when: abs(Xj - Xj-1)(i) <= XTol(i) and abs(Fi) <= FTol for all i;", py::arg("theFunction"), py::arg("theStartingPoint"));
	cls_math_NewtonFunctionSetRoot.def("Perform", (void (math_NewtonFunctionSetRoot::*)(math_FunctionSetWithDerivatives &, const math_Vector &, const math_Vector &, const math_Vector &)) &math_NewtonFunctionSetRoot::Perform, "The Newton method is done to improve the root of the function from the initial guess point. Bounds may be given, to constrain the solution. The solution is found when: abs(Xj - Xj-1)(i) <= XTol(i) and abs(Fi) <= FTol for all i;", py::arg("theFunction"), py::arg("theStartingPoint"), py::arg("theInfBound"), py::arg("theSupBound"));
	cls_math_NewtonFunctionSetRoot.def("IsSolutionReached", (Standard_Boolean (math_NewtonFunctionSetRoot::*)(math_FunctionSetWithDerivatives &)) &math_NewtonFunctionSetRoot::IsSolutionReached, "This method is called at the end of each iteration to check if the solution is found. Vectors DeltaX, Fvalues and Jacobian Matrix are consistent with the possible solution Vector Sol and can be inspected to decide whether the solution is reached or not.", py::arg("F"));
	cls_math_NewtonFunctionSetRoot.def("IsDone", (Standard_Boolean (math_NewtonFunctionSetRoot::*)() const ) &math_NewtonFunctionSetRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_NewtonFunctionSetRoot.def("Root", (const math_Vector & (math_NewtonFunctionSetRoot::*)() const ) &math_NewtonFunctionSetRoot::Root, "Returns the value of the root of function F. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).");
	cls_math_NewtonFunctionSetRoot.def("Root", (void (math_NewtonFunctionSetRoot::*)(math_Vector &) const ) &math_NewtonFunctionSetRoot::Root, "outputs the root vector in Root. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Root is not equal to the range of the StartingPoint.", py::arg("Root"));
	// cls_math_NewtonFunctionSetRoot.def("StateNumber", (Standard_Integer (math_NewtonFunctionSetRoot::*)() const ) &math_NewtonFunctionSetRoot::StateNumber, "Outputs the state number associated with the solution vector root.");
	cls_math_NewtonFunctionSetRoot.def("Derivative", (const math_Matrix & (math_NewtonFunctionSetRoot::*)() const ) &math_NewtonFunctionSetRoot::Derivative, "Returns the matrix value of the derivative at the root. Exception NotDone is raised if the root was not found.");
	cls_math_NewtonFunctionSetRoot.def("Derivative", (void (math_NewtonFunctionSetRoot::*)(math_Matrix &) const ) &math_NewtonFunctionSetRoot::Derivative, "Outputs the matrix value of the derivative at the root in Der. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Der is not equal to the range of the StartingPoint.", py::arg("Der"));
	cls_math_NewtonFunctionSetRoot.def("FunctionSetErrors", (const math_Vector & (math_NewtonFunctionSetRoot::*)() const ) &math_NewtonFunctionSetRoot::FunctionSetErrors, "Returns the vector value of the error done on the functions at the root. Exception NotDone is raised if the root was not found.");
	cls_math_NewtonFunctionSetRoot.def("FunctionSetErrors", (void (math_NewtonFunctionSetRoot::*)(math_Vector &) const ) &math_NewtonFunctionSetRoot::FunctionSetErrors, "Outputs the vector value of the error done on the functions at the root in Err. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Err is not equal to the range of the StartingPoint.", py::arg("Err"));
	cls_math_NewtonFunctionSetRoot.def("NbIterations", (Standard_Integer (math_NewtonFunctionSetRoot::*)() const ) &math_NewtonFunctionSetRoot::NbIterations, "Returns the number of iterations really done during the computation of the Root. Exception NotDone is raised if the root was not found.");
	// FIXME cls_math_NewtonFunctionSetRoot.def("Dump", (void (math_NewtonFunctionSetRoot::*)(Standard_OStream &) const ) &math_NewtonFunctionSetRoot::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_BracketMinimum.hxx
	py::class_<math_BracketMinimum, std::unique_ptr<math_BracketMinimum, Deleter<math_BracketMinimum>>> cls_math_BracketMinimum(mod, "math_BracketMinimum", "Given two distinct initial points, BracketMinimum implements the computation of three points (a, b, c) which bracket the minimum of the function and verify A less than B, B less than C and F(B) less than F(A), F(B) less than F(C).");
	cls_math_BracketMinimum.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"));
	cls_math_BracketMinimum.def(py::init<math_Function &, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"));
	cls_math_BracketMinimum.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("FA"));
	cls_math_BracketMinimum.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("A"), py::arg("B"), py::arg("FA"), py::arg("FB"));
	cls_math_BracketMinimum.def("SetLimits", (void (math_BracketMinimum::*)(const Standard_Real, const Standard_Real)) &math_BracketMinimum::SetLimits, "Set limits of the parameter. By default no limits are applied to the parameter change. If no minimum is found in limits then IsDone() will return false. The user is in charge of providing A and B to be in limits.", py::arg("theLeft"), py::arg("theRight"));
	cls_math_BracketMinimum.def("SetFA", (void (math_BracketMinimum::*)(const Standard_Real)) &math_BracketMinimum::SetFA, "Set function value at A", py::arg("theValue"));
	cls_math_BracketMinimum.def("SetFB", (void (math_BracketMinimum::*)(const Standard_Real)) &math_BracketMinimum::SetFB, "Set function value at B", py::arg("theValue"));
	cls_math_BracketMinimum.def("Perform", (void (math_BracketMinimum::*)(math_Function &)) &math_BracketMinimum::Perform, "The method performing the job. It is called automatically by constructors with the function.", py::arg("F"));
	cls_math_BracketMinimum.def("IsDone", (Standard_Boolean (math_BracketMinimum::*)() const ) &math_BracketMinimum::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_BracketMinimum.def("Values", [](math_BracketMinimum &self, Standard_Real & A, Standard_Real & B, Standard_Real & C){ self.Values(A, B, C); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C); }, "Returns the bracketed triplet of abscissae. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).", py::arg("A"), py::arg("B"), py::arg("C"));
	cls_math_BracketMinimum.def("FunctionValues", [](math_BracketMinimum &self, Standard_Real & FA, Standard_Real & FB, Standard_Real & FC){ self.FunctionValues(FA, FB, FC); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(FA, FB, FC); }, "returns the bracketed triplet function values. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).", py::arg("FA"), py::arg("FB"), py::arg("FC"));
	// FIXME cls_math_BracketMinimum.def("Dump", (void (math_BracketMinimum::*)(Standard_OStream &) const ) &math_BracketMinimum::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_BrentMinimum.hxx
	py::class_<math_BrentMinimum, std::unique_ptr<math_BrentMinimum, Deleter<math_BrentMinimum>>> cls_math_BrentMinimum(mod, "math_BrentMinimum", "This class implements the Brent's method to find the minimum of a function of a single variable. No knowledge of the derivative is required.");
	cls_math_BrentMinimum.def(py::init<const Standard_Real>(), py::arg("TolX"));
	cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Integer>(), py::arg("TolX"), py::arg("NbIterations"));
	cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("TolX"), py::arg("NbIterations"), py::arg("ZEPS"));
	cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("TolX"), py::arg("Fbx"));
	cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("TolX"), py::arg("Fbx"), py::arg("NbIterations"));
	cls_math_BrentMinimum.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("TolX"), py::arg("Fbx"), py::arg("NbIterations"), py::arg("ZEPS"));
	cls_math_BrentMinimum.def("Perform", (void (math_BrentMinimum::*)(math_Function &, const Standard_Real, const Standard_Real, const Standard_Real)) &math_BrentMinimum::Perform, "Brent minimization is performed on function F from a given bracketing triplet of abscissas Ax, Bx, Cx (such that Bx is between Ax and Cx, F(Bx) is less than both F(Bx) and F(Cx)) The solution is found when: abs(Xi - Xi-1) <= TolX * abs(Xi) + ZEPS;", py::arg("F"), py::arg("Ax"), py::arg("Bx"), py::arg("Cx"));
	cls_math_BrentMinimum.def("IsSolutionReached", (Standard_Boolean (math_BrentMinimum::*)(math_Function &)) &math_BrentMinimum::IsSolutionReached, "This method is called at the end of each iteration to check if the solution is found. It can be redefined in a sub-class to implement a specific test to stop the iterations.", py::arg("theFunction"));
	cls_math_BrentMinimum.def("IsDone", (Standard_Boolean (math_BrentMinimum::*)() const ) &math_BrentMinimum::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_BrentMinimum.def("Location", (Standard_Real (math_BrentMinimum::*)() const ) &math_BrentMinimum::Location, "returns the location value of the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_BrentMinimum.def("Minimum", (Standard_Real (math_BrentMinimum::*)() const ) &math_BrentMinimum::Minimum, "returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_BrentMinimum.def("NbIterations", (Standard_Integer (math_BrentMinimum::*)() const ) &math_BrentMinimum::NbIterations, "returns the number of iterations really done during the computation of the minimum. Exception NotDone is raised if the minimum was not found.");
	// FIXME cls_math_BrentMinimum.def("Dump", (void (math_BrentMinimum::*)(Standard_OStream &) const ) &math_BrentMinimum::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Powell.hxx
	py::class_<math_Powell, std::unique_ptr<math_Powell, Deleter<math_Powell>>> cls_math_Powell(mod, "math_Powell", "This class implements the Powell method to find the minimum of function of multiple variables (the gradient does not have to be known).");
	cls_math_Powell.def(py::init<const math_MultipleVarFunction &, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"));
	cls_math_Powell.def(py::init<const math_MultipleVarFunction &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"));
	cls_math_Powell.def(py::init<const math_MultipleVarFunction &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"), py::arg("theZEPS"));
	cls_math_Powell.def("Perform", (void (math_Powell::*)(math_MultipleVarFunction &, const math_Vector &, const math_Matrix &)) &math_Powell::Perform, "Computes Powell minimization on the function F given theStartingPoint, and an initial matrix theStartingDirection whose columns contain the initial set of directions. The solution F = Fi is found when: 2.0 * abs(Fi - Fi-1) =< Tolerance * (abs(Fi) + abs(Fi-1) + ZEPS).", py::arg("theFunction"), py::arg("theStartingPoint"), py::arg("theStartingDirections"));
	cls_math_Powell.def("IsSolutionReached", (Standard_Boolean (math_Powell::*)(math_MultipleVarFunction &)) &math_Powell::IsSolutionReached, "Solution F = Fi is found when: 2.0 * abs(Fi - Fi-1) <= Tolerance * (abs(Fi) + abs(Fi-1)) + ZEPS. The maximum number of iterations allowed is given by NbIterations.", py::arg("theFunction"));
	cls_math_Powell.def("IsDone", (Standard_Boolean (math_Powell::*)() const ) &math_Powell::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_Powell.def("Location", (const math_Vector & (math_Powell::*)() const ) &math_Powell::Location, "returns the location vector of the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_Powell.def("Location", (void (math_Powell::*)(math_Vector &) const ) &math_Powell::Location, "outputs the location vector of the minimum in Loc. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Loc is not equal to the range of the StartingPoint.", py::arg("Loc"));
	cls_math_Powell.def("Minimum", (Standard_Real (math_Powell::*)() const ) &math_Powell::Minimum, "Returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_Powell.def("NbIterations", (Standard_Integer (math_Powell::*)() const ) &math_Powell::NbIterations, "Returns the number of iterations really done during the computation of the minimum. Exception NotDone is raised if the minimum was not found.");
	// FIXME cls_math_Powell.def("Dump", (void (math_Powell::*)(Standard_OStream &) const ) &math_Powell::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_FRPR.hxx
	py::class_<math_FRPR, std::unique_ptr<math_FRPR, Deleter<math_FRPR>>> cls_math_FRPR(mod, "math_FRPR", "this class implements the Fletcher-Reeves-Polak_Ribiere minimization algorithm of a function of multiple variables. Knowledge of the function's gradient is required.");
	cls_math_FRPR.def(py::init<const math_MultipleVarFunctionWithGradient &, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"));
	cls_math_FRPR.def(py::init<const math_MultipleVarFunctionWithGradient &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"));
	cls_math_FRPR.def(py::init<const math_MultipleVarFunctionWithGradient &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"), py::arg("theZEPS"));
	cls_math_FRPR.def("Perform", (void (math_FRPR::*)(math_MultipleVarFunctionWithGradient &, const math_Vector &)) &math_FRPR::Perform, "The solution F = Fi is found when 2.0 * abs(Fi - Fi-1) <= Tolerance * (abs(Fi) + abs(Fi-1) + ZEPS).", py::arg("theFunction"), py::arg("theStartingPoint"));
	cls_math_FRPR.def("IsSolutionReached", (Standard_Boolean (math_FRPR::*)(math_MultipleVarFunctionWithGradient &)) &math_FRPR::IsSolutionReached, "The solution F = Fi is found when: 2.0 * abs(Fi - Fi-1) <= Tolerance * (abs(Fi) + abs(Fi-1)) + ZEPS. The maximum number of iterations allowed is given by NbIterations.", py::arg("theFunction"));
	cls_math_FRPR.def("IsDone", (Standard_Boolean (math_FRPR::*)() const ) &math_FRPR::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_FRPR.def("Location", (const math_Vector & (math_FRPR::*)() const ) &math_FRPR::Location, "returns the location vector of the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_FRPR.def("Location", (void (math_FRPR::*)(math_Vector &) const ) &math_FRPR::Location, "outputs the location vector of the minimum in Loc. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Loc is not equal to the range of the StartingPoint.", py::arg("Loc"));
	cls_math_FRPR.def("Minimum", (Standard_Real (math_FRPR::*)() const ) &math_FRPR::Minimum, "returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_FRPR.def("Gradient", (const math_Vector & (math_FRPR::*)() const ) &math_FRPR::Gradient, "returns the gradient vector at the minimum. Exception NotDone is raised if the minimum was not found.");
	cls_math_FRPR.def("Gradient", (void (math_FRPR::*)(math_Vector &) const ) &math_FRPR::Gradient, "outputs the gradient vector at the minimum in Grad. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Grad is not equal to the range of the StartingPoint.", py::arg("Grad"));
	cls_math_FRPR.def("NbIterations", (Standard_Integer (math_FRPR::*)() const ) &math_FRPR::NbIterations, "returns the number of iterations really done during the computation of the minimum. Exception NotDone is raised if the minimum was not found.");
	// FIXME cls_math_FRPR.def("Dump", (void (math_FRPR::*)(Standard_OStream &) const ) &math_FRPR::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Jacobi.hxx
	py::class_<math_Jacobi, std::unique_ptr<math_Jacobi, Deleter<math_Jacobi>>> cls_math_Jacobi(mod, "math_Jacobi", "This class implements the Jacobi method to find the eigenvalues and the eigenvectors of a real symmetric square matrix. A sort of eigenvalues is done.");
	cls_math_Jacobi.def(py::init<const math_Matrix &>(), py::arg("A"));
	cls_math_Jacobi.def("IsDone", (Standard_Boolean (math_Jacobi::*)() const ) &math_Jacobi::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_Jacobi.def("Values", (const math_Vector & (math_Jacobi::*)() const ) &math_Jacobi::Values, "Returns the eigenvalues vector. Exception NotDone is raised if calculation is not done successfully.");
	cls_math_Jacobi.def("Value", (Standard_Real (math_Jacobi::*)(const Standard_Integer) const ) &math_Jacobi::Value, "returns the eigenvalue number Num. Eigenvalues are in the range (1..n). Exception NotDone is raised if calculation is not done successfully.", py::arg("Num"));
	cls_math_Jacobi.def("Vectors", (const math_Matrix & (math_Jacobi::*)() const ) &math_Jacobi::Vectors, "returns the eigenvectors matrix. Exception NotDone is raised if calculation is not done successfully.");
	cls_math_Jacobi.def("Vector", (void (math_Jacobi::*)(const Standard_Integer, math_Vector &) const ) &math_Jacobi::Vector, "Returns the eigenvector V of number Num. Eigenvectors are in the range (1..n). Exception NotDone is raised if calculation is not done successfully.", py::arg("Num"), py::arg("V"));
	// FIXME cls_math_Jacobi.def("Dump", (void (math_Jacobi::*)(Standard_OStream &) const ) &math_Jacobi::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_GaussSingleIntegration.hxx
	py::class_<math_GaussSingleIntegration, std::unique_ptr<math_GaussSingleIntegration, Deleter<math_GaussSingleIntegration>>> cls_math_GaussSingleIntegration(mod, "math_GaussSingleIntegration", "This class implements the integration of a function of a single variable between the parameter bounds Lower and Upper. Warning: Order must be inferior or equal to 61.");
	cls_math_GaussSingleIntegration.def(py::init<>());
	cls_math_GaussSingleIntegration.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Lower"), py::arg("Upper"), py::arg("Order"));
	cls_math_GaussSingleIntegration.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("F"), py::arg("Lower"), py::arg("Upper"), py::arg("Order"), py::arg("Tol"));
	cls_math_GaussSingleIntegration.def("IsDone", (Standard_Boolean (math_GaussSingleIntegration::*)() const ) &math_GaussSingleIntegration::IsDone, "returns True if all has been correctly done.");
	cls_math_GaussSingleIntegration.def("Value", (Standard_Real (math_GaussSingleIntegration::*)() const ) &math_GaussSingleIntegration::Value, "returns the value of the integral.");
	// FIXME cls_math_GaussSingleIntegration.def("Dump", (void (math_GaussSingleIntegration::*)(Standard_OStream &) const ) &math_GaussSingleIntegration::Dump, "Prints information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_GaussMultipleIntegration.hxx
	py::class_<math_GaussMultipleIntegration, std::unique_ptr<math_GaussMultipleIntegration, Deleter<math_GaussMultipleIntegration>>> cls_math_GaussMultipleIntegration(mod, "math_GaussMultipleIntegration", "This class implements the integration of a function of multiple variables between the parameter bounds Lower[a..b] and Upper[a..b]. Warning: Each element of Order must be inferior or equal to 61.");
	cls_math_GaussMultipleIntegration.def(py::init<math_MultipleVarFunction &, const math_Vector &, const math_Vector &, const math_IntegerVector &>(), py::arg("F"), py::arg("Lower"), py::arg("Upper"), py::arg("Order"));
	cls_math_GaussMultipleIntegration.def("IsDone", (Standard_Boolean (math_GaussMultipleIntegration::*)() const ) &math_GaussMultipleIntegration::IsDone, "returns True if all has been correctly done.");
	cls_math_GaussMultipleIntegration.def("Value", (Standard_Real (math_GaussMultipleIntegration::*)() const ) &math_GaussMultipleIntegration::Value, "returns the value of the integral.");
	// FIXME cls_math_GaussMultipleIntegration.def("Dump", (void (math_GaussMultipleIntegration::*)(Standard_OStream &) const ) &math_GaussMultipleIntegration::Dump, "Prints information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_GaussSetIntegration.hxx
	py::class_<math_GaussSetIntegration, std::unique_ptr<math_GaussSetIntegration, Deleter<math_GaussSetIntegration>>> cls_math_GaussSetIntegration(mod, "math_GaussSetIntegration", "-- This class implements the integration of a set of N functions of M variables variables between the parameter bounds Lower[a..b] and Upper[a..b]. Warning: - The case M>1 is not implemented.");
	cls_math_GaussSetIntegration.def(py::init<math_FunctionSet &, const math_Vector &, const math_Vector &, const math_IntegerVector &>(), py::arg("F"), py::arg("Lower"), py::arg("Upper"), py::arg("Order"));
	cls_math_GaussSetIntegration.def("IsDone", (Standard_Boolean (math_GaussSetIntegration::*)() const ) &math_GaussSetIntegration::IsDone, "returns True if all has been correctly done.");
	cls_math_GaussSetIntegration.def("Value", (const math_Vector & (math_GaussSetIntegration::*)() const ) &math_GaussSetIntegration::Value, "returns the value of the integral.");
	// FIXME cls_math_GaussSetIntegration.def("Dump", (void (math_GaussSetIntegration::*)(Standard_OStream &) const ) &math_GaussSetIntegration::Dump, "Prints information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_FunctionAllRoots.hxx
	py::class_<math_FunctionAllRoots, std::unique_ptr<math_FunctionAllRoots, Deleter<math_FunctionAllRoots>>> cls_math_FunctionAllRoots(mod, "math_FunctionAllRoots", "This algorithm uses a sample of the function to find all intervals on which the function is null, and afterwards uses the FunctionRoots algorithm to find the points where the function is null outside the 'null intervals'. Knowledge of the derivative is required.");
	cls_math_FunctionAllRoots.def(py::init<math_FunctionWithDerivative &, const math_FunctionSample &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("S"), py::arg("EpsX"), py::arg("EpsF"), py::arg("EpsNul"));
	cls_math_FunctionAllRoots.def("IsDone", (Standard_Boolean (math_FunctionAllRoots::*)() const ) &math_FunctionAllRoots::IsDone, "Returns True if the computation has been done successfully.");
	cls_math_FunctionAllRoots.def("NbIntervals", (Standard_Integer (math_FunctionAllRoots::*)() const ) &math_FunctionAllRoots::NbIntervals, "Returns the number of intervals on which the function is Null. An exception is raised if IsDone returns False.");
	cls_math_FunctionAllRoots.def("GetInterval", [](math_FunctionAllRoots &self, const Standard_Integer Index, Standard_Real & A, Standard_Real & B){ self.GetInterval(Index, A, B); return std::tuple<Standard_Real &, Standard_Real &>(A, B); }, "Returns the interval of parameter of range Index. An exception is raised if IsDone returns False; An exception is raised if Index<=0 or Index >Nbintervals.", py::arg("Index"), py::arg("A"), py::arg("B"));
	cls_math_FunctionAllRoots.def("GetIntervalState", [](math_FunctionAllRoots &self, const Standard_Integer Index, Standard_Integer & IFirst, Standard_Integer & ILast){ self.GetIntervalState(Index, IFirst, ILast); return std::tuple<Standard_Integer &, Standard_Integer &>(IFirst, ILast); }, "returns the State Number associated to the interval Index. An exception is raised if IsDone returns False; An exception is raised if Index<=0 or Index >Nbintervals.", py::arg("Index"), py::arg("IFirst"), py::arg("ILast"));
	cls_math_FunctionAllRoots.def("NbPoints", (Standard_Integer (math_FunctionAllRoots::*)() const ) &math_FunctionAllRoots::NbPoints, "returns the number of points where the function is Null. An exception is raised if IsDone returns False.");
	cls_math_FunctionAllRoots.def("GetPoint", (Standard_Real (math_FunctionAllRoots::*)(const Standard_Integer) const ) &math_FunctionAllRoots::GetPoint, "Returns the parameter of the point of range Index. An exception is raised if IsDone returns False; An exception is raised if Index<=0 or Index >NbPoints.", py::arg("Index"));
	cls_math_FunctionAllRoots.def("GetPointState", (Standard_Integer (math_FunctionAllRoots::*)(const Standard_Integer) const ) &math_FunctionAllRoots::GetPointState, "returns the State Number associated to the point Index. An exception is raised if IsDone returns False; An exception is raised if Index<=0 or Index >Nbintervals.", py::arg("Index"));
	// FIXME cls_math_FunctionAllRoots.def("Dump", (void (math_FunctionAllRoots::*)(Standard_OStream &) const ) &math_FunctionAllRoots::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Householder.hxx
	py::class_<math_Householder, std::unique_ptr<math_Householder, Deleter<math_Householder>>> cls_math_Householder(mod, "math_Householder", "This class implements the least square solution of a set of linear equations of m unknowns (n >= m) using the Householder method. It solves A.X = B. This algorithm has more numerical stability than GaussLeastSquare but is longer. It must be used if the matrix is singular or nearly singular. It is about 16% longer than GaussLeastSquare if there is only one member B to solve. It is about 30% longer if there are twenty B members to solve.");
	cls_math_Householder.def(py::init<const math_Matrix &, const math_Matrix &>(), py::arg("A"), py::arg("B"));
	cls_math_Householder.def(py::init<const math_Matrix &, const math_Matrix &, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("EPS"));
	cls_math_Householder.def(py::init<const math_Matrix &, const math_Matrix &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("A"), py::arg("B"), py::arg("lowerArow"), py::arg("upperArow"), py::arg("lowerAcol"), py::arg("upperAcol"));
	cls_math_Householder.def(py::init<const math_Matrix &, const math_Matrix &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("lowerArow"), py::arg("upperArow"), py::arg("lowerAcol"), py::arg("upperAcol"), py::arg("EPS"));
	cls_math_Householder.def(py::init<const math_Matrix &, const math_Vector &>(), py::arg("A"), py::arg("B"));
	cls_math_Householder.def(py::init<const math_Matrix &, const math_Vector &, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("EPS"));
	cls_math_Householder.def("IsDone", (Standard_Boolean (math_Householder::*)() const ) &math_Householder::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_Householder.def("Value", [](math_Householder &self, math_Vector & a0) -> void { return self.Value(a0); }, py::arg("sol"));
	cls_math_Householder.def("Value", (void (math_Householder::*)(math_Vector &, const Standard_Integer) const ) &math_Householder::Value, "Given the integer Index, this routine returns the corresponding least square solution sol. Exception NotDone is raised if the resolution has not be done. Exception OutOfRange is raised if Index <=0 or Index is more than the number of columns of B.", py::arg("sol"), py::arg("Index"));
	cls_math_Householder.def("AllValues", (const math_Matrix & (math_Householder::*)() const ) &math_Householder::AllValues, "Returns the matrix sol of all the solutions of the system A.X = B. Exception NotDone is raised is the resolution has not be done.");
	// FIXME cls_math_Householder.def("Dump", (void (math_Householder::*)(Standard_OStream &) const ) &math_Householder::Dump, "Prints information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Crout.hxx
	py::class_<math_Crout, std::unique_ptr<math_Crout, Deleter<math_Crout>>> cls_math_Crout(mod, "math_Crout", "This class implements the Crout algorithm used to solve a system A*X = B where A is a symmetric matrix. It can be used to invert a symmetric matrix. This algorithm is similar to Gauss but is faster than Gauss. Only the inferior triangle of A and the diagonal can be given.");
	cls_math_Crout.def(py::init<const math_Matrix &>(), py::arg("A"));
	cls_math_Crout.def(py::init<const math_Matrix &, const Standard_Real>(), py::arg("A"), py::arg("MinPivot"));
	cls_math_Crout.def("IsDone", (Standard_Boolean (math_Crout::*)() const ) &math_Crout::IsDone, "Returns True if all has been correctly done.");
	cls_math_Crout.def("Solve", (void (math_Crout::*)(const math_Vector &, math_Vector &) const ) &math_Crout::Solve, "Given an input vector <B>, this routine returns the solution of the set of linear equations A . X = B. Exception NotDone is raised if the decomposition was not done successfully. Exception DimensionError is raised if the range of B is not equal to the rowrange of A.", py::arg("B"), py::arg("X"));
	cls_math_Crout.def("Inverse", (const math_Matrix & (math_Crout::*)() const ) &math_Crout::Inverse, "returns the inverse matrix of A. Only the inferior triangle is returned. Exception NotDone is raised if NotDone.");
	cls_math_Crout.def("Invert", (void (math_Crout::*)(math_Matrix &) const ) &math_Crout::Invert, "returns in Inv the inverse matrix of A. Only the inferior triangle is returned. Exception NotDone is raised if NotDone.", py::arg("Inv"));
	cls_math_Crout.def("Determinant", (Standard_Real (math_Crout::*)() const ) &math_Crout::Determinant, "Returns the value of the determinant of the previously LU decomposed matrix A. Zero is returned if the matrix A is considered as singular. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).");
	// FIXME cls_math_Crout.def("Dump", (void (math_Crout::*)(Standard_OStream &) const ) &math_Crout::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Uzawa.hxx
	py::class_<math_Uzawa, std::unique_ptr<math_Uzawa, Deleter<math_Uzawa>>> cls_math_Uzawa(mod, "math_Uzawa", "This class implements a system resolution C*X = B with an approach solution X0. There are no conditions on the number of equations. The algorithm used is the Uzawa algorithm. It is possible to have equal or inequal (<) equations to solve. The resolution is done with a minimization of Norm(X-X0). If there are only equal equations, the resolution is directly done and is similar to Gauss resolution with an optimisation because the matrix is a symmetric matrix. (The resolution is done with Crout algorithm)");
	cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"));
	cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Real>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("EpsLix"));
	cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("EpsLix"), py::arg("EpsLic"));
	cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("EpsLix"), py::arg("EpsLic"), py::arg("NbIterations"));
	cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("Nci"), py::arg("Nce"));
	cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("Nci"), py::arg("Nce"), py::arg("EpsLix"));
	cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("Nci"), py::arg("Nce"), py::arg("EpsLix"), py::arg("EpsLic"));
	cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("Nci"), py::arg("Nce"), py::arg("EpsLix"), py::arg("EpsLic"), py::arg("NbIterations"));
	cls_math_Uzawa.def("IsDone", (Standard_Boolean (math_Uzawa::*)() const ) &math_Uzawa::IsDone, "Returns true if the computations are successful, otherwise returns false.");
	cls_math_Uzawa.def("Value", (const math_Vector & (math_Uzawa::*)() const ) &math_Uzawa::Value, "Returns the vector solution of the system above. An exception is raised if NotDone.");
	cls_math_Uzawa.def("InitialError", (const math_Vector & (math_Uzawa::*)() const ) &math_Uzawa::InitialError, "Returns the initial error Cont*StartingPoint-Secont. An exception is raised if NotDone.");
	cls_math_Uzawa.def("Duale", (void (math_Uzawa::*)(math_Vector &) const ) &math_Uzawa::Duale, "returns the duale variables V of the systeme.", py::arg("V"));
	cls_math_Uzawa.def("Error", (const math_Vector & (math_Uzawa::*)() const ) &math_Uzawa::Error, "Returns the difference between X solution and the StartingPoint. An exception is raised if NotDone.");
	cls_math_Uzawa.def("NbIterations", (Standard_Integer (math_Uzawa::*)() const ) &math_Uzawa::NbIterations, "returns the number of iterations really done. An exception is raised if NotDone.");
	cls_math_Uzawa.def("InverseCont", (const math_Matrix & (math_Uzawa::*)() const ) &math_Uzawa::InverseCont, "returns the inverse matrix of (C * Transposed(C)). This result is needed for the computation of the gradient when approximating a curve.");
	// FIXME cls_math_Uzawa.def("Dump", (void (math_Uzawa::*)(Standard_OStream &) const ) &math_Uzawa::Dump, "Prints information on the current state of the object.", py::arg("o"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_KronrodSingleIntegration.hxx
	py::class_<math_KronrodSingleIntegration, std::unique_ptr<math_KronrodSingleIntegration, Deleter<math_KronrodSingleIntegration>>> cls_math_KronrodSingleIntegration(mod, "math_KronrodSingleIntegration", "This class implements the Gauss-Kronrod method of integral computation.");
	cls_math_KronrodSingleIntegration.def(py::init<>());
	cls_math_KronrodSingleIntegration.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theNbPnts"));
	cls_math_KronrodSingleIntegration.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theNbPnts"), py::arg("theTolerance"), py::arg("theMaxNbIter"));
	cls_math_KronrodSingleIntegration.def("Perform", (void (math_KronrodSingleIntegration::*)(math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer)) &math_KronrodSingleIntegration::Perform, "Computation of the integral. Takes the function, the lower and upper bound values, the initial number of Kronrod points, the relative tolerance value and the maximal number of iterations as parameters. theNbPnts should be odd and greater then or equal to 3.", py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theNbPnts"));
	cls_math_KronrodSingleIntegration.def("Perform", (void (math_KronrodSingleIntegration::*)(math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Integer)) &math_KronrodSingleIntegration::Perform, "Computation of the integral. Takes the function, the lower and upper bound values, the initial number of Kronrod points, the relative tolerance value and the maximal number of iterations as parameters. theNbPnts should be odd and greater then or equal to 3. Note that theTolerance is relative, i.e. the criterion of solution reaching is: Abs(Kronrod - Gauss)/Abs(Kronrod) < theTolerance. theTolerance should be positive.", py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theNbPnts"), py::arg("theTolerance"), py::arg("theMaxNbIter"));
	cls_math_KronrodSingleIntegration.def("IsDone", (Standard_Boolean (math_KronrodSingleIntegration::*)() const ) &math_KronrodSingleIntegration::IsDone, "Returns Standard_True if computation is performed successfully.");
	cls_math_KronrodSingleIntegration.def("Value", (Standard_Real (math_KronrodSingleIntegration::*)() const ) &math_KronrodSingleIntegration::Value, "Returns the value of the integral.");
	cls_math_KronrodSingleIntegration.def("ErrorReached", (Standard_Real (math_KronrodSingleIntegration::*)() const ) &math_KronrodSingleIntegration::ErrorReached, "Returns the value of the relative error reached.");
	cls_math_KronrodSingleIntegration.def("AbsolutError", (Standard_Real (math_KronrodSingleIntegration::*)() const ) &math_KronrodSingleIntegration::AbsolutError, "Returns the value of the relative error reached.");
	cls_math_KronrodSingleIntegration.def("OrderReached", (Standard_Integer (math_KronrodSingleIntegration::*)() const ) &math_KronrodSingleIntegration::OrderReached, "Returns the number of Kronrod points for which the result is computed.");
	cls_math_KronrodSingleIntegration.def("NbIterReached", (Standard_Integer (math_KronrodSingleIntegration::*)() const ) &math_KronrodSingleIntegration::NbIterReached, "Returns the number of iterations that were made to compute result.");
	cls_math_KronrodSingleIntegration.def_static("GKRule_", [](math_Function & theFunction, const Standard_Real theLower, const Standard_Real theUpper, const math_Vector & theGaussP, const math_Vector & theGaussW, const math_Vector & theKronrodP, const math_Vector & theKronrodW, Standard_Real & theValue, Standard_Real & theError){ Standard_Boolean rv = math_KronrodSingleIntegration::GKRule(theFunction, theLower, theUpper, theGaussP, theGaussW, theKronrodP, theKronrodW, theValue, theError); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theValue, theError); }, "None", py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theGaussP"), py::arg("theGaussW"), py::arg("theKronrodP"), py::arg("theKronrodW"), py::arg("theValue"), py::arg("theError"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_EigenValuesSearcher.hxx
	py::class_<math_EigenValuesSearcher, std::unique_ptr<math_EigenValuesSearcher, Deleter<math_EigenValuesSearcher>>> cls_math_EigenValuesSearcher(mod, "math_EigenValuesSearcher", "This class finds eigen values and vectors of real symmetric tridiagonal matrix");
	cls_math_EigenValuesSearcher.def(py::init<const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("Diagonal"), py::arg("Subdiagonal"));
	cls_math_EigenValuesSearcher.def("IsDone", (Standard_Boolean (math_EigenValuesSearcher::*)() const ) &math_EigenValuesSearcher::IsDone, "Returns Standard_True if computation is performed successfully.");
	cls_math_EigenValuesSearcher.def("Dimension", (Standard_Integer (math_EigenValuesSearcher::*)() const ) &math_EigenValuesSearcher::Dimension, "Returns the dimension of matrix");
	cls_math_EigenValuesSearcher.def("EigenValue", (Standard_Real (math_EigenValuesSearcher::*)(const Standard_Integer) const ) &math_EigenValuesSearcher::EigenValue, "Returns the Index_th eigen value of matrix Index must be in [1, Dimension()]", py::arg("Index"));
	cls_math_EigenValuesSearcher.def("EigenVector", (math_Vector (math_EigenValuesSearcher::*)(const Standard_Integer) const ) &math_EigenValuesSearcher::EigenVector, "Returns the Index_th eigen vector of matrix Index must be in [1, Dimension()]", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_ComputeGaussPointsAndWeights.hxx
	py::class_<math_ComputeGaussPointsAndWeights, std::unique_ptr<math_ComputeGaussPointsAndWeights, Deleter<math_ComputeGaussPointsAndWeights>>> cls_math_ComputeGaussPointsAndWeights(mod, "math_ComputeGaussPointsAndWeights", "None");
	cls_math_ComputeGaussPointsAndWeights.def(py::init<const Standard_Integer>(), py::arg("Number"));
	cls_math_ComputeGaussPointsAndWeights.def("IsDone", (Standard_Boolean (math_ComputeGaussPointsAndWeights::*)() const ) &math_ComputeGaussPointsAndWeights::IsDone, "None");
	cls_math_ComputeGaussPointsAndWeights.def("Points", (math_Vector (math_ComputeGaussPointsAndWeights::*)() const ) &math_ComputeGaussPointsAndWeights::Points, "None");
	cls_math_ComputeGaussPointsAndWeights.def("Weights", (math_Vector (math_ComputeGaussPointsAndWeights::*)() const ) &math_ComputeGaussPointsAndWeights::Weights, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_ComputeKronrodPointsAndWeights.hxx
	py::class_<math_ComputeKronrodPointsAndWeights, std::unique_ptr<math_ComputeKronrodPointsAndWeights, Deleter<math_ComputeKronrodPointsAndWeights>>> cls_math_ComputeKronrodPointsAndWeights(mod, "math_ComputeKronrodPointsAndWeights", "None");
	cls_math_ComputeKronrodPointsAndWeights.def(py::init<const Standard_Integer>(), py::arg("Number"));
	cls_math_ComputeKronrodPointsAndWeights.def("IsDone", (Standard_Boolean (math_ComputeKronrodPointsAndWeights::*)() const ) &math_ComputeKronrodPointsAndWeights::IsDone, "None");
	cls_math_ComputeKronrodPointsAndWeights.def("Points", (math_Vector (math_ComputeKronrodPointsAndWeights::*)() const ) &math_ComputeKronrodPointsAndWeights::Points, "None");
	cls_math_ComputeKronrodPointsAndWeights.def("Weights", (math_Vector (math_ComputeKronrodPointsAndWeights::*)() const ) &math_ComputeKronrodPointsAndWeights::Weights, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math.hxx
	py::class_<math, std::unique_ptr<math, Deleter<math>>> cls_math(mod, "math", "None");
	cls_math.def(py::init<>());
	cls_math.def_static("GaussPointsMax_", (Standard_Integer (*)()) &math::GaussPointsMax, "None");
	cls_math.def_static("GaussPoints_", (void (*)(const Standard_Integer, math_Vector &)) &math::GaussPoints, "None", py::arg("Index"), py::arg("Points"));
	cls_math.def_static("GaussWeights_", (void (*)(const Standard_Integer, math_Vector &)) &math::GaussWeights, "None", py::arg("Index"), py::arg("Weights"));
	cls_math.def_static("KronrodPointsMax_", (Standard_Integer (*)()) &math::KronrodPointsMax, "Returns the maximal number of points for that the values are stored in the table. If the number is greater then KronrodPointsMax, the points will be computed.");
	cls_math.def_static("OrderedGaussPointsAndWeights_", (Standard_Boolean (*)(const Standard_Integer, math_Vector &, math_Vector &)) &math::OrderedGaussPointsAndWeights, "Returns a vector of Gauss points and a vector of their weights. The difference with the method GaussPoints is the following: - the points are returned in increasing order. - if Index is greater then GaussPointsMax, the points are computed. Returns Standard_True if Index is positive, Points' and Weights' length is equal to Index, Points and Weights are successfully computed.", py::arg("Index"), py::arg("Points"), py::arg("Weights"));
	cls_math.def_static("KronrodPointsAndWeights_", (Standard_Boolean (*)(const Standard_Integer, math_Vector &, math_Vector &)) &math::KronrodPointsAndWeights, "Returns a vector of Kronrod points and a vector of their weights for Gauss-Kronrod computation method. Index should be odd and greater then or equal to 3, as the number of Kronrod points is equal to 2*N + 1, where N is a number of Gauss points. Points and Weights should have the size equal to Index. Each even element of Points represents a Gauss point value of N-th Gauss quadrature. The values from Index equal to 3 to 123 are stored in a table (see the file math_Kronrod.cxx). If Index is greater, then points and weights will be computed. Returns Standard_True if Index is odd, it is equal to the size of Points and Weights and the computation of Points and Weights is performed successfully. Otherwise this method returns Standard_False.", py::arg("Index"), py::arg("Points"), py::arg("Weights"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_ValueAndWeight.hxx
	py::class_<math_ValueAndWeight, std::unique_ptr<math_ValueAndWeight, Deleter<math_ValueAndWeight>>> cls_math_ValueAndWeight(mod, "math_ValueAndWeight", "Simple container storing two reals: value and weight");
	cls_math_ValueAndWeight.def(py::init<>());
	cls_math_ValueAndWeight.def(py::init<Standard_Real, Standard_Real>(), py::arg("theValue"), py::arg("theWeight"));
	cls_math_ValueAndWeight.def("Value", (Standard_Real (math_ValueAndWeight::*)() const ) &math_ValueAndWeight::Value, "None");
	cls_math_ValueAndWeight.def("Weight", (Standard_Real (math_ValueAndWeight::*)() const ) &math_ValueAndWeight::Weight, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_BullardGenerator.hxx
	py::class_<math_BullardGenerator, std::unique_ptr<math_BullardGenerator, Deleter<math_BullardGenerator>>> cls_math_BullardGenerator(mod, "math_BullardGenerator", "Fast random number generator (the algorithm proposed by Ian C. Bullard).");
	cls_math_BullardGenerator.def(py::init<>());
	cls_math_BullardGenerator.def(py::init<unsigned int>(), py::arg("theSeed"));
	cls_math_BullardGenerator.def("SetSeed", [](math_BullardGenerator &self) -> void { return self.SetSeed(); });
	cls_math_BullardGenerator.def("SetSeed", (void (math_BullardGenerator::*)(unsigned int)) &math_BullardGenerator::SetSeed, "Setup new seed / reset defaults.", py::arg("theSeed"));
	cls_math_BullardGenerator.def("NextInt", (unsigned int (math_BullardGenerator::*)()) &math_BullardGenerator::NextInt, "Generates new 64-bit integer value.");
	cls_math_BullardGenerator.def("NextReal", (Standard_Real (math_BullardGenerator::*)()) &math_BullardGenerator::NextReal, "Generates new floating-point value.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_NotSquare.hxx
	py::class_<math_NotSquare, opencascade::handle<math_NotSquare>, Standard_DimensionError> cls_math_NotSquare(mod, "math_NotSquare", "None");
	cls_math_NotSquare.def(py::init<>());
	cls_math_NotSquare.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_math_NotSquare.def_static("Raise_", (void (*)(const Standard_CString)) &math_NotSquare::Raise, "None", py::arg("theMessage"));
	cls_math_NotSquare.def_static("Raise_", (void (*)(Standard_SStream &)) &math_NotSquare::Raise, "None", py::arg("theMessage"));
	cls_math_NotSquare.def_static("NewInstance_", (opencascade::handle<math_NotSquare> (*)(const Standard_CString)) &math_NotSquare::NewInstance, "None", py::arg("theMessage"));
	cls_math_NotSquare.def_static("get_type_name_", (const char * (*)()) &math_NotSquare::get_type_name, "None");
	cls_math_NotSquare.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &math_NotSquare::get_type_descriptor, "None");
	cls_math_NotSquare.def("DynamicType", (const opencascade::handle<Standard_Type> & (math_NotSquare::*)() const ) &math_NotSquare::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_GlobOptMin.hxx
	py::class_<math_GlobOptMin, std::unique_ptr<math_GlobOptMin, Deleter<math_GlobOptMin>>> cls_math_GlobOptMin(mod, "math_GlobOptMin", "This class represents Evtushenko's algorithm of global optimization based on non-uniform mesh. Article: Yu. Evtushenko. Numerical methods for finding global extreme (case of a non-uniform mesh). U.S.S.R. Comput. Maths. Math. Phys., Vol. 11, N 6, pp. 38-54.");
	cls_math_GlobOptMin.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &>(), py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"));
	cls_math_GlobOptMin.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const Standard_Real>(), py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"));
	cls_math_GlobOptMin.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real>(), py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"), py::arg("theDiscretizationTol"));
	cls_math_GlobOptMin.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"), py::arg("theDiscretizationTol"), py::arg("theSameTol"));
	cls_math_GlobOptMin.def("SetGlobalParams", [](math_GlobOptMin &self, math_MultipleVarFunction * a0, const math_Vector & a1, const math_Vector & a2) -> void { return self.SetGlobalParams(a0, a1, a2); }, py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"));
	cls_math_GlobOptMin.def("SetGlobalParams", [](math_GlobOptMin &self, math_MultipleVarFunction * a0, const math_Vector & a1, const math_Vector & a2, const Standard_Real a3) -> void { return self.SetGlobalParams(a0, a1, a2, a3); }, py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"));
	cls_math_GlobOptMin.def("SetGlobalParams", [](math_GlobOptMin &self, math_MultipleVarFunction * a0, const math_Vector & a1, const math_Vector & a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.SetGlobalParams(a0, a1, a2, a3, a4); }, py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"), py::arg("theDiscretizationTol"));
	cls_math_GlobOptMin.def("SetGlobalParams", (void (math_GlobOptMin::*)(math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real)) &math_GlobOptMin::SetGlobalParams, "", py::arg("theFunc"), py::arg("theLowerBorder"), py::arg("theUpperBorder"), py::arg("theC"), py::arg("theDiscretizationTol"), py::arg("theSameTol"));
	cls_math_GlobOptMin.def("SetLocalParams", (void (math_GlobOptMin::*)(const math_Vector &, const math_Vector &)) &math_GlobOptMin::SetLocalParams, "Method to reduce bounding box. Perform will use this box.", py::arg("theLocalA"), py::arg("theLocalB"));
	cls_math_GlobOptMin.def("SetTol", (void (math_GlobOptMin::*)(const Standard_Real, const Standard_Real)) &math_GlobOptMin::SetTol, "Method to set tolerances.", py::arg("theDiscretizationTol"), py::arg("theSameTol"));
	cls_math_GlobOptMin.def("GetTol", [](math_GlobOptMin &self, Standard_Real & theDiscretizationTol, Standard_Real & theSameTol){ self.GetTol(theDiscretizationTol, theSameTol); return std::tuple<Standard_Real &, Standard_Real &>(theDiscretizationTol, theSameTol); }, "Method to get tolerances.", py::arg("theDiscretizationTol"), py::arg("theSameTol"));
	cls_math_GlobOptMin.def("Perform", [](math_GlobOptMin &self) -> void { return self.Perform(); });
	cls_math_GlobOptMin.def("Perform", (void (math_GlobOptMin::*)(const Standard_Boolean)) &math_GlobOptMin::Perform, "", py::arg("isFindSingleSolution"));
	cls_math_GlobOptMin.def("Points", (void (math_GlobOptMin::*)(const Standard_Integer, math_Vector &)) &math_GlobOptMin::Points, "Return solution theIndex, 1 <= theIndex <= NbExtrema.", py::arg("theIndex"), py::arg("theSol"));
	cls_math_GlobOptMin.def("SetContinuity", (void (math_GlobOptMin::*)(const Standard_Integer)) &math_GlobOptMin::SetContinuity, "Set / Get continuity of local borders splits (0 ~ C0, 1 ~ C1, 2 ~ C2).", py::arg("theCont"));
	cls_math_GlobOptMin.def("GetContinuity", (Standard_Integer (math_GlobOptMin::*)() const ) &math_GlobOptMin::GetContinuity, "None");
	cls_math_GlobOptMin.def("SetFunctionalMinimalValue", (void (math_GlobOptMin::*)(const Standard_Real)) &math_GlobOptMin::SetFunctionalMinimalValue, "Set / Get functional minimal value.", py::arg("theMinimalValue"));
	cls_math_GlobOptMin.def("GetFunctionalMinimalValue", (Standard_Real (math_GlobOptMin::*)() const ) &math_GlobOptMin::GetFunctionalMinimalValue, "None");
	cls_math_GlobOptMin.def("SetLipConstState", (void (math_GlobOptMin::*)(const Standard_Boolean)) &math_GlobOptMin::SetLipConstState, "Set / Get Lipchitz constant modification state. True means that the constant is locked and unlocked otherwise.", py::arg("theFlag"));
	cls_math_GlobOptMin.def("GetLipConstState", (Standard_Boolean (math_GlobOptMin::*)() const ) &math_GlobOptMin::GetLipConstState, "None");
	cls_math_GlobOptMin.def("isDone", (Standard_Boolean (math_GlobOptMin::*)() const ) &math_GlobOptMin::isDone, "Return computation state of the algorithm.");
	cls_math_GlobOptMin.def("GetF", (Standard_Real (math_GlobOptMin::*)() const ) &math_GlobOptMin::GetF, "Get best functional value.");
	cls_math_GlobOptMin.def("NbExtrema", (Standard_Integer (math_GlobOptMin::*)() const ) &math_GlobOptMin::NbExtrema, "Return count of global extremas.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_PSOParticlesPool.hxx
	py::class_<math_PSOParticlesPool, std::unique_ptr<math_PSOParticlesPool, Deleter<math_PSOParticlesPool>>> cls_math_PSOParticlesPool(mod, "math_PSOParticlesPool", "None");
	cls_math_PSOParticlesPool.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theParticlesCount"), py::arg("theDimensionCount"));
	cls_math_PSOParticlesPool.def("GetParticle", (PSO_Particle * (math_PSOParticlesPool::*)(const Standard_Integer)) &math_PSOParticlesPool::GetParticle, "None", py::arg("theIdx"));
	cls_math_PSOParticlesPool.def("GetBestParticle", (PSO_Particle * (math_PSOParticlesPool::*)()) &math_PSOParticlesPool::GetBestParticle, "None");
	cls_math_PSOParticlesPool.def("GetWorstParticle", (PSO_Particle * (math_PSOParticlesPool::*)()) &math_PSOParticlesPool::GetWorstParticle, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_PSO.hxx
	py::class_<math_PSO, std::unique_ptr<math_PSO, Deleter<math_PSO>>> cls_math_PSO(mod, "math_PSO", "In this class implemented variation of Particle Swarm Optimization (PSO) method. A. Ismael F. Vaz, L. N. Vicente 'A particle swarm pattern search method for bound constrained global optimization'");
	cls_math_PSO.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const math_Vector &>(), py::arg("theFunc"), py::arg("theLowBorder"), py::arg("theUppBorder"), py::arg("theSteps"));
	cls_math_PSO.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Integer>(), py::arg("theFunc"), py::arg("theLowBorder"), py::arg("theUppBorder"), py::arg("theSteps"), py::arg("theNbParticles"));
	cls_math_PSO.def(py::init<math_MultipleVarFunction *, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("theFunc"), py::arg("theLowBorder"), py::arg("theUppBorder"), py::arg("theSteps"), py::arg("theNbParticles"), py::arg("theNbIter"));
	cls_math_PSO.def("Perform", [](math_PSO &self, const math_Vector & theSteps, Standard_Real & theValue, math_Vector & theOutPnt, const Standard_Integer theNbIter){ self.Perform(theSteps, theValue, theOutPnt, theNbIter); return theValue; }, "Perform computations, particles array is constructed inside of this function.", py::arg("theSteps"), py::arg("theValue"), py::arg("theOutPnt"), py::arg("theNbIter"));
	cls_math_PSO.def("Perform", [](math_PSO &self, math_PSOParticlesPool & theParticles, Standard_Integer theNbParticles, Standard_Real & theValue, math_Vector & theOutPnt, const Standard_Integer theNbIter){ self.Perform(theParticles, theNbParticles, theValue, theOutPnt, theNbIter); return theValue; }, "Perform computations with given particles array.", py::arg("theParticles"), py::arg("theNbParticles"), py::arg("theValue"), py::arg("theOutPnt"), py::arg("theNbIter"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_PSOParticlesPool.hxx
	py::class_<PSO_Particle, std::unique_ptr<PSO_Particle, Deleter<PSO_Particle>>> cls_PSO_Particle(mod, "PSO_Particle", "Describes particle pool for using in PSO algorithm. Indexes: 0 <= aDimidx <= myDimensionCount - 1");
	cls_PSO_Particle.def(py::init<>());
	cls_PSO_Particle.def("__lt__", (bool (PSO_Particle::*)(const PSO_Particle &) const ) &PSO_Particle::operator<, py::is_operator(), "Compares the particles according to their distances.", py::arg("thePnt"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_SingularMatrix.hxx
	py::class_<math_SingularMatrix, opencascade::handle<math_SingularMatrix>, Standard_Failure> cls_math_SingularMatrix(mod, "math_SingularMatrix", "None");
	cls_math_SingularMatrix.def(py::init<>());
	cls_math_SingularMatrix.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_math_SingularMatrix.def_static("Raise_", (void (*)(const Standard_CString)) &math_SingularMatrix::Raise, "None", py::arg("theMessage"));
	cls_math_SingularMatrix.def_static("Raise_", (void (*)(Standard_SStream &)) &math_SingularMatrix::Raise, "None", py::arg("theMessage"));
	cls_math_SingularMatrix.def_static("NewInstance_", (opencascade::handle<math_SingularMatrix> (*)(const Standard_CString)) &math_SingularMatrix::NewInstance, "None", py::arg("theMessage"));
	cls_math_SingularMatrix.def_static("get_type_name_", (const char * (*)()) &math_SingularMatrix::get_type_name, "None");
	cls_math_SingularMatrix.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &math_SingularMatrix::get_type_descriptor, "None");
	cls_math_SingularMatrix.def("DynamicType", (const opencascade::handle<Standard_Type> & (math_SingularMatrix::*)() const ) &math_SingularMatrix::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_Array1OfValueAndWeight.hxx
	bind_NCollection_Array1<math_ValueAndWeight>(mod, "math_Array1OfValueAndWeight");


}
