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
#include <math_SVD.hxx>

void bind_math_SVD(py::module &mod){

py::class_<math_SVD> cls_math_SVD(mod, "math_SVD", "SVD implements the solution of a set of N linear equations of M unknowns without condition on N or M. The Singular Value Decomposition algorithm is used. For singular or nearly singular matrices SVD is a better choice than Gauss or GaussLeastSquare.");

// Constructors
cls_math_SVD.def(py::init<const math_Matrix &>(), py::arg("A"));

// Fields

// Methods
// cls_math_SVD.def_static("operator new_", (void * (*)(size_t)) &math_SVD::operator new, "None", py::arg("theSize"));
// cls_math_SVD.def_static("operator delete_", (void (*)(void *)) &math_SVD::operator delete, "None", py::arg("theAddress"));
// cls_math_SVD.def_static("operator new[]_", (void * (*)(size_t)) &math_SVD::operator new[], "None", py::arg("theSize"));
// cls_math_SVD.def_static("operator delete[]_", (void (*)(void *)) &math_SVD::operator delete[], "None", py::arg("theAddress"));
// cls_math_SVD.def_static("operator new_", (void * (*)(size_t, void *)) &math_SVD::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_SVD.def_static("operator delete_", (void (*)(void *, void *)) &math_SVD::operator delete, "None", py::arg(""), py::arg(""));
cls_math_SVD.def("IsDone", (Standard_Boolean (math_SVD::*)() const) &math_SVD::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_SVD.def("Solve", [](math_SVD &self, const math_Vector & a0, math_Vector & a1) -> void { return self.Solve(a0, a1); });
cls_math_SVD.def("Solve", (void (math_SVD::*)(const math_Vector &, math_Vector &, const Standard_Real) const) &math_SVD::Solve, "Given the input Vector B this routine solves the set of linear equations A . X = B. Exception NotDone is raised if the decomposition of A was not done successfully. Exception DimensionError is raised if the range of B is not equal to the rowrange of A. Exception DimensionError is raised if the range of X is not equal to the colrange of A.", py::arg("B"), py::arg("X"), py::arg("Eps"));
cls_math_SVD.def("PseudoInverse", [](math_SVD &self, math_Matrix & a0) -> void { return self.PseudoInverse(a0); });
cls_math_SVD.def("PseudoInverse", (void (math_SVD::*)(math_Matrix &, const Standard_Real) const) &math_SVD::PseudoInverse, "Computes the inverse Inv of matrix A such as A * Inverse = Identity. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false). Standard_DimensionError if the ranges of Inv are compatible with the ranges of A.", py::arg("Inv"), py::arg("Eps"));
cls_math_SVD.def("Dump", (void (math_SVD::*)(Standard_OStream &) const) &math_SVD::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}