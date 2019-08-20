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
#include <math_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <math_Uzawa.hxx>

void bind_math_Uzawa(py::module &mod){

py::class_<math_Uzawa, std::unique_ptr<math_Uzawa>> cls_math_Uzawa(mod, "math_Uzawa", "This class implements a system resolution C*X = B with an approach solution X0. There are no conditions on the number of equations. The algorithm used is the Uzawa algorithm. It is possible to have equal or inequal (<) equations to solve. The resolution is done with a minimization of Norm(X-X0). If there are only equal equations, the resolution is directly done and is similar to Gauss resolution with an optimisation because the matrix is a symmetric matrix. (The resolution is done with Crout algorithm)");

// Constructors
cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"));
cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Real>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("EpsLix"));
cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("EpsLix"), py::arg("EpsLic"));
cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("EpsLix"), py::arg("EpsLic"), py::arg("NbIterations"));
cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("Nci"), py::arg("Nce"));
cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("Nci"), py::arg("Nce"), py::arg("EpsLix"));
cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("Nci"), py::arg("Nce"), py::arg("EpsLix"), py::arg("EpsLic"));
cls_math_Uzawa.def(py::init<const math_Matrix &, const math_Vector &, const math_Vector &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Cont"), py::arg("Secont"), py::arg("StartingPoint"), py::arg("Nci"), py::arg("Nce"), py::arg("EpsLix"), py::arg("EpsLic"), py::arg("NbIterations"));

// Fields

// Methods
// cls_math_Uzawa.def_static("operator new_", (void * (*)(size_t)) &math_Uzawa::operator new, "None", py::arg("theSize"));
// cls_math_Uzawa.def_static("operator delete_", (void (*)(void *)) &math_Uzawa::operator delete, "None", py::arg("theAddress"));
// cls_math_Uzawa.def_static("operator new[]_", (void * (*)(size_t)) &math_Uzawa::operator new[], "None", py::arg("theSize"));
// cls_math_Uzawa.def_static("operator delete[]_", (void (*)(void *)) &math_Uzawa::operator delete[], "None", py::arg("theAddress"));
// cls_math_Uzawa.def_static("operator new_", (void * (*)(size_t, void *)) &math_Uzawa::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_Uzawa.def_static("operator delete_", (void (*)(void *, void *)) &math_Uzawa::operator delete, "None", py::arg(""), py::arg(""));
cls_math_Uzawa.def("IsDone", (Standard_Boolean (math_Uzawa::*)() const) &math_Uzawa::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_Uzawa.def("Value", (const math_Vector & (math_Uzawa::*)() const) &math_Uzawa::Value, "Returns the vector solution of the system above. An exception is raised if NotDone.");
cls_math_Uzawa.def("InitialError", (const math_Vector & (math_Uzawa::*)() const) &math_Uzawa::InitialError, "Returns the initial error Cont*StartingPoint-Secont. An exception is raised if NotDone.");
cls_math_Uzawa.def("Duale", (void (math_Uzawa::*)(math_Vector &) const) &math_Uzawa::Duale, "returns the duale variables V of the systeme.", py::arg("V"));
cls_math_Uzawa.def("Error", (const math_Vector & (math_Uzawa::*)() const) &math_Uzawa::Error, "Returns the difference between X solution and the StartingPoint. An exception is raised if NotDone.");
cls_math_Uzawa.def("NbIterations", (Standard_Integer (math_Uzawa::*)() const) &math_Uzawa::NbIterations, "returns the number of iterations really done. An exception is raised if NotDone.");
cls_math_Uzawa.def("InverseCont", (const math_Matrix & (math_Uzawa::*)() const) &math_Uzawa::InverseCont, "returns the inverse matrix of (C * Transposed(C)). This result is needed for the computation of the gradient when approximating a curve.");
cls_math_Uzawa.def("Dump", (void (math_Uzawa::*)(Standard_OStream &) const) &math_Uzawa::Dump, "Prints information on the current state of the object.", py::arg("o"));

// Enums

}