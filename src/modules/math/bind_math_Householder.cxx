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
#include <math_Householder.hxx>

void bind_math_Householder(py::module &mod){

py::class_<math_Householder, std::unique_ptr<math_Householder>> cls_math_Householder(mod, "math_Householder", "This class implements the least square solution of a set of linear equations of m unknowns (n >= m) using the Householder method. It solves A.X = B. This algorithm has more numerical stability than GaussLeastSquare but is longer. It must be used if the matrix is singular or nearly singular. It is about 16% longer than GaussLeastSquare if there is only one member B to solve. It is about 30% longer if there are twenty B members to solve.");

// Constructors
cls_math_Householder.def(py::init<const math_Matrix &, const math_Matrix &>(), py::arg("A"), py::arg("B"));
cls_math_Householder.def(py::init<const math_Matrix &, const math_Matrix &, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("EPS"));
cls_math_Householder.def(py::init<const math_Matrix &, const math_Matrix &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("A"), py::arg("B"), py::arg("lowerArow"), py::arg("upperArow"), py::arg("lowerAcol"), py::arg("upperAcol"));
cls_math_Householder.def(py::init<const math_Matrix &, const math_Matrix &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("lowerArow"), py::arg("upperArow"), py::arg("lowerAcol"), py::arg("upperAcol"), py::arg("EPS"));
cls_math_Householder.def(py::init<const math_Matrix &, const math_Vector &>(), py::arg("A"), py::arg("B"));
cls_math_Householder.def(py::init<const math_Matrix &, const math_Vector &, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("EPS"));

// Fields

// Methods
// cls_math_Householder.def_static("operator new_", (void * (*)(size_t)) &math_Householder::operator new, "None", py::arg("theSize"));
// cls_math_Householder.def_static("operator delete_", (void (*)(void *)) &math_Householder::operator delete, "None", py::arg("theAddress"));
// cls_math_Householder.def_static("operator new[]_", (void * (*)(size_t)) &math_Householder::operator new[], "None", py::arg("theSize"));
// cls_math_Householder.def_static("operator delete[]_", (void (*)(void *)) &math_Householder::operator delete[], "None", py::arg("theAddress"));
// cls_math_Householder.def_static("operator new_", (void * (*)(size_t, void *)) &math_Householder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_Householder.def_static("operator delete_", (void (*)(void *, void *)) &math_Householder::operator delete, "None", py::arg(""), py::arg(""));
cls_math_Householder.def("IsDone", (Standard_Boolean (math_Householder::*)() const) &math_Householder::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_Householder.def("Value", [](math_Householder &self, math_Vector & a0) -> void { return self.Value(a0); });
cls_math_Householder.def("Value", (void (math_Householder::*)(math_Vector &, const Standard_Integer) const) &math_Householder::Value, "Given the integer Index, this routine returns the corresponding least square solution sol. Exception NotDone is raised if the resolution has not be done. Exception OutOfRange is raised if Index <=0 or Index is more than the number of columns of B.", py::arg("sol"), py::arg("Index"));
cls_math_Householder.def("AllValues", (const math_Matrix & (math_Householder::*)() const) &math_Householder::AllValues, "Returns the matrix sol of all the solutions of the system A.X = B. Exception NotDone is raised is the resolution has not be done.");
cls_math_Householder.def("Dump", (void (math_Householder::*)(Standard_OStream &) const) &math_Householder::Dump, "Prints informations on the current state of the object.", py::arg("o"));

// Enums

}