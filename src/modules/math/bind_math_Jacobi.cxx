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
#include <math_Jacobi.hxx>

void bind_math_Jacobi(py::module &mod){

py::class_<math_Jacobi> cls_math_Jacobi(mod, "math_Jacobi", "This class implements the Jacobi method to find the eigenvalues and the eigenvectors of a real symmetric square matrix. A sort of eigenvalues is done.");

// Constructors
cls_math_Jacobi.def(py::init<const math_Matrix &>(), py::arg("A"));

// Fields

// Methods
// cls_math_Jacobi.def_static("operator new_", (void * (*)(size_t)) &math_Jacobi::operator new, "None", py::arg("theSize"));
// cls_math_Jacobi.def_static("operator delete_", (void (*)(void *)) &math_Jacobi::operator delete, "None", py::arg("theAddress"));
// cls_math_Jacobi.def_static("operator new[]_", (void * (*)(size_t)) &math_Jacobi::operator new[], "None", py::arg("theSize"));
// cls_math_Jacobi.def_static("operator delete[]_", (void (*)(void *)) &math_Jacobi::operator delete[], "None", py::arg("theAddress"));
// cls_math_Jacobi.def_static("operator new_", (void * (*)(size_t, void *)) &math_Jacobi::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_Jacobi.def_static("operator delete_", (void (*)(void *, void *)) &math_Jacobi::operator delete, "None", py::arg(""), py::arg(""));
cls_math_Jacobi.def("IsDone", (Standard_Boolean (math_Jacobi::*)() const) &math_Jacobi::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_Jacobi.def("Values", (const math_Vector & (math_Jacobi::*)() const) &math_Jacobi::Values, "Returns the eigenvalues vector. Exception NotDone is raised if calculation is not done successfully.");
cls_math_Jacobi.def("Value", (Standard_Real (math_Jacobi::*)(const Standard_Integer) const) &math_Jacobi::Value, "returns the eigenvalue number Num. Eigenvalues are in the range (1..n). Exception NotDone is raised if calculation is not done successfully.", py::arg("Num"));
cls_math_Jacobi.def("Vectors", (const math_Matrix & (math_Jacobi::*)() const) &math_Jacobi::Vectors, "returns the eigenvectors matrix. Exception NotDone is raised if calculation is not done successfully.");
cls_math_Jacobi.def("Vector", (void (math_Jacobi::*)(const Standard_Integer, math_Vector &) const) &math_Jacobi::Vector, "Returns the eigenvector V of number Num. Eigenvectors are in the range (1..n). Exception NotDone is raised if calculation is not done successfully.", py::arg("Num"), py::arg("V"));
cls_math_Jacobi.def("Dump", (void (math_Jacobi::*)(Standard_OStream &) const) &math_Jacobi::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}