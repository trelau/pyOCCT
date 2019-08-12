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
#include <math_Crout.hxx>

void bind_math_Crout(py::module &mod){

py::class_<math_Crout, std::unique_ptr<math_Crout, Deleter<math_Crout>>> cls_math_Crout(mod, "math_Crout", "This class implements the Crout algorithm used to solve a system A*X = B where A is a symmetric matrix. It can be used to invert a symmetric matrix. This algorithm is similar to Gauss but is faster than Gauss. Only the inferior triangle of A and the diagonal can be given.");

// Constructors
cls_math_Crout.def(py::init<const math_Matrix &>(), py::arg("A"));
cls_math_Crout.def(py::init<const math_Matrix &, const Standard_Real>(), py::arg("A"), py::arg("MinPivot"));

// Fields

// Methods
// cls_math_Crout.def_static("operator new_", (void * (*)(size_t)) &math_Crout::operator new, "None", py::arg("theSize"));
// cls_math_Crout.def_static("operator delete_", (void (*)(void *)) &math_Crout::operator delete, "None", py::arg("theAddress"));
// cls_math_Crout.def_static("operator new[]_", (void * (*)(size_t)) &math_Crout::operator new[], "None", py::arg("theSize"));
// cls_math_Crout.def_static("operator delete[]_", (void (*)(void *)) &math_Crout::operator delete[], "None", py::arg("theAddress"));
// cls_math_Crout.def_static("operator new_", (void * (*)(size_t, void *)) &math_Crout::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_Crout.def_static("operator delete_", (void (*)(void *, void *)) &math_Crout::operator delete, "None", py::arg(""), py::arg(""));
cls_math_Crout.def("IsDone", (Standard_Boolean (math_Crout::*)() const) &math_Crout::IsDone, "Returns True if all has been correctly done.");
cls_math_Crout.def("Solve", (void (math_Crout::*)(const math_Vector &, math_Vector &) const) &math_Crout::Solve, "Given an input vector <B>, this routine returns the solution of the set of linear equations A . X = B. Exception NotDone is raised if the decomposition was not done successfully. Exception DimensionError is raised if the range of B is not equal to the rowrange of A.", py::arg("B"), py::arg("X"));
cls_math_Crout.def("Inverse", (const math_Matrix & (math_Crout::*)() const) &math_Crout::Inverse, "returns the inverse matrix of A. Only the inferior triangle is returned. Exception NotDone is raised if NotDone.");
cls_math_Crout.def("Invert", (void (math_Crout::*)(math_Matrix &) const) &math_Crout::Invert, "returns in Inv the inverse matrix of A. Only the inferior triangle is returned. Exception NotDone is raised if NotDone.", py::arg("Inv"));
cls_math_Crout.def("Determinant", (Standard_Real (math_Crout::*)() const) &math_Crout::Determinant, "Returns the value of the determinant of the previously LU decomposed matrix A. Zero is returned if the matrix A is considered as singular. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).");
cls_math_Crout.def("Dump", (void (math_Crout::*)(Standard_OStream &) const) &math_Crout::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

// Enums

}