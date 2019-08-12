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
#include <math_GaussLeastSquare.hxx>

void bind_math_GaussLeastSquare(py::module &mod){

py::class_<math_GaussLeastSquare, std::unique_ptr<math_GaussLeastSquare, Deleter<math_GaussLeastSquare>>> cls_math_GaussLeastSquare(mod, "math_GaussLeastSquare", "This class implements the least square solution of a set of n linear equations of m unknowns (n >= m) using the gauss LU decomposition algorithm. This algorithm is more likely subject to numerical instability than math_SVD.");

// Constructors
cls_math_GaussLeastSquare.def(py::init<const math_Matrix &>(), py::arg("A"));
cls_math_GaussLeastSquare.def(py::init<const math_Matrix &, const Standard_Real>(), py::arg("A"), py::arg("MinPivot"));

// Fields

// Methods
// cls_math_GaussLeastSquare.def_static("operator new_", (void * (*)(size_t)) &math_GaussLeastSquare::operator new, "None", py::arg("theSize"));
// cls_math_GaussLeastSquare.def_static("operator delete_", (void (*)(void *)) &math_GaussLeastSquare::operator delete, "None", py::arg("theAddress"));
// cls_math_GaussLeastSquare.def_static("operator new[]_", (void * (*)(size_t)) &math_GaussLeastSquare::operator new[], "None", py::arg("theSize"));
// cls_math_GaussLeastSquare.def_static("operator delete[]_", (void (*)(void *)) &math_GaussLeastSquare::operator delete[], "None", py::arg("theAddress"));
// cls_math_GaussLeastSquare.def_static("operator new_", (void * (*)(size_t, void *)) &math_GaussLeastSquare::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_GaussLeastSquare.def_static("operator delete_", (void (*)(void *, void *)) &math_GaussLeastSquare::operator delete, "None", py::arg(""), py::arg(""));
cls_math_GaussLeastSquare.def("IsDone", (Standard_Boolean (math_GaussLeastSquare::*)() const) &math_GaussLeastSquare::IsDone, "Returns true if the computations are successful, otherwise returns false.e");
cls_math_GaussLeastSquare.def("Solve", (void (math_GaussLeastSquare::*)(const math_Vector &, math_Vector &) const) &math_GaussLeastSquare::Solve, "Given the input Vector <B> this routine solves the set of linear equations A . X = B. Exception NotDone is raised if the decomposition of A was not done successfully. Exception DimensionError is raised if the range of B Inv is not equal to the rowrange of A. Exception DimensionError is raised if the range of X Inv is not equal to the colrange of A.", py::arg("B"), py::arg("X"));
cls_math_GaussLeastSquare.def("Dump", (void (math_GaussLeastSquare::*)(Standard_OStream &) const) &math_GaussLeastSquare::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}