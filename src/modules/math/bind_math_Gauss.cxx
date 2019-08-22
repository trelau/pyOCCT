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
#include <math_Matrix.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <Standard_OStream.hxx>
#include <math_IntegerVector.hxx>
#include <math_Gauss.hxx>

void bind_math_Gauss(py::module &mod){

py::class_<math_Gauss> cls_math_Gauss(mod, "math_Gauss", "This class implements the Gauss LU decomposition (Crout algorithm) with partial pivoting (rows interchange) of a square matrix and the different possible derived calculation : - solution of a set of linear equations. - inverse of a matrix. - determinant of a matrix.");

// Constructors
cls_math_Gauss.def(py::init<const math_Matrix &>(), py::arg("A"));
cls_math_Gauss.def(py::init<const math_Matrix &, const Standard_Real>(), py::arg("A"), py::arg("MinPivot"));

// Fields

// Methods
// cls_math_Gauss.def_static("operator new_", (void * (*)(size_t)) &math_Gauss::operator new, "None", py::arg("theSize"));
// cls_math_Gauss.def_static("operator delete_", (void (*)(void *)) &math_Gauss::operator delete, "None", py::arg("theAddress"));
// cls_math_Gauss.def_static("operator new[]_", (void * (*)(size_t)) &math_Gauss::operator new[], "None", py::arg("theSize"));
// cls_math_Gauss.def_static("operator delete[]_", (void (*)(void *)) &math_Gauss::operator delete[], "None", py::arg("theAddress"));
// cls_math_Gauss.def_static("operator new_", (void * (*)(size_t, void *)) &math_Gauss::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_Gauss.def_static("operator delete_", (void (*)(void *, void *)) &math_Gauss::operator delete, "None", py::arg(""), py::arg(""));
cls_math_Gauss.def("IsDone", (Standard_Boolean (math_Gauss::*)() const) &math_Gauss::IsDone, "Returns true if the computations are successful, otherwise returns false");
cls_math_Gauss.def("Solve", (void (math_Gauss::*)(const math_Vector &, math_Vector &) const) &math_Gauss::Solve, "Given the input Vector B this routine returns the solution X of the set of linear equations A . X = B. Exception NotDone is raised if the decomposition of A was not done successfully. Exception DimensionError is raised if the range of B is not equal to the number of rows of A.", py::arg("B"), py::arg("X"));
cls_math_Gauss.def("Solve", (void (math_Gauss::*)(math_Vector &) const) &math_Gauss::Solve, "Given the input Vector B this routine solves the set of linear equations A . X = B. B is replaced by the vector solution X. Exception NotDone is raised if the decomposition of A was not done successfully. Exception DimensionError is raised if the range of B is not equal to the number of rows of A.", py::arg("B"));
cls_math_Gauss.def("Determinant", (Standard_Real (math_Gauss::*)() const) &math_Gauss::Determinant, "This routine returns the value of the determinant of the previously LU decomposed matrix A. Exception NotDone may be raised if the decomposition of A was not done successfully, zero is returned if the matrix A was considered as singular.");
cls_math_Gauss.def("Invert", (void (math_Gauss::*)(math_Matrix &) const) &math_Gauss::Invert, "This routine outputs Inv the inverse of the previously LU decomposed matrix A. Exception DimensionError is raised if the ranges of B are not equal to the ranges of A.", py::arg("Inv"));
cls_math_Gauss.def("Dump", (void (math_Gauss::*)(Standard_OStream &) const) &math_Gauss::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}