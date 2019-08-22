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
#include <math_MultipleVarFunctionWithHessian.hxx>
#include <Standard_TypeDef.hxx>
#include <Precision.hxx>
#include <math_Vector.hxx>
#include <math_Status.hxx>
#include <Standard_OStream.hxx>
#include <math_Matrix.hxx>
#include <math_NewtonMinimum.hxx>

void bind_math_NewtonMinimum(py::module &mod){

py::class_<math_NewtonMinimum> cls_math_NewtonMinimum(mod, "math_NewtonMinimum", "None");

// Constructors
cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &>(), py::arg("theFunction"));
cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"));
cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"));
cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"), py::arg("theConvexity"));
cls_math_NewtonMinimum.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Boolean>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"), py::arg("theConvexity"), py::arg("theWithSingularity"));

// Fields

// Methods
// cls_math_NewtonMinimum.def_static("operator new_", (void * (*)(size_t)) &math_NewtonMinimum::operator new, "None", py::arg("theSize"));
// cls_math_NewtonMinimum.def_static("operator delete_", (void (*)(void *)) &math_NewtonMinimum::operator delete, "None", py::arg("theAddress"));
// cls_math_NewtonMinimum.def_static("operator new[]_", (void * (*)(size_t)) &math_NewtonMinimum::operator new[], "None", py::arg("theSize"));
// cls_math_NewtonMinimum.def_static("operator delete[]_", (void (*)(void *)) &math_NewtonMinimum::operator delete[], "None", py::arg("theAddress"));
// cls_math_NewtonMinimum.def_static("operator new_", (void * (*)(size_t, void *)) &math_NewtonMinimum::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_NewtonMinimum.def_static("operator delete_", (void (*)(void *, void *)) &math_NewtonMinimum::operator delete, "None", py::arg(""), py::arg(""));
cls_math_NewtonMinimum.def("Perform", (void (math_NewtonMinimum::*)(math_MultipleVarFunctionWithHessian &, const math_Vector &)) &math_NewtonMinimum::Perform, "Search the solution.", py::arg("theFunction"), py::arg("theStartingPoint"));
cls_math_NewtonMinimum.def("IsConverged", (Standard_Boolean (math_NewtonMinimum::*)() const) &math_NewtonMinimum::IsConverged, "This method is called at the end of each iteration to check the convergence: || Xi+1 - Xi || < Tolerance or || F(Xi+1) - F(Xi)|| < Tolerance * || F(Xi) || It can be redefined in a sub-class to implement a specific test.");
cls_math_NewtonMinimum.def("IsDone", (Standard_Boolean (math_NewtonMinimum::*)() const) &math_NewtonMinimum::IsDone, "Tests if an error has occured.");
// cls_math_NewtonMinimum.def("IsConvex", (Standard_Boolean (math_NewtonMinimum::*)() const) &math_NewtonMinimum::IsConvex, "Tests if the Function is convexe during optimization.");
cls_math_NewtonMinimum.def("Location", (const math_Vector & (math_NewtonMinimum::*)() const) &math_NewtonMinimum::Location, "returns the location vector of the minimum. Exception NotDone is raised if an error has occured.");
cls_math_NewtonMinimum.def("Location", (void (math_NewtonMinimum::*)(math_Vector &) const) &math_NewtonMinimum::Location, "outputs the location vector of the minimum in Loc. Exception NotDone is raised if an error has occured. Exception DimensionError is raised if the range of Loc is not equal to the range of the StartingPoint.", py::arg("Loc"));
cls_math_NewtonMinimum.def("SetBoundary", (void (math_NewtonMinimum::*)(const math_Vector &, const math_Vector &)) &math_NewtonMinimum::SetBoundary, "Set boundaries.", py::arg("theLeftBorder"), py::arg("theRightBorder"));
cls_math_NewtonMinimum.def("Minimum", (Standard_Real (math_NewtonMinimum::*)() const) &math_NewtonMinimum::Minimum, "returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_NewtonMinimum.def("Gradient", (const math_Vector & (math_NewtonMinimum::*)() const) &math_NewtonMinimum::Gradient, "returns the gradient vector at the minimum. Exception NotDone is raised if an error has occured.the minimum was not found.");
cls_math_NewtonMinimum.def("Gradient", (void (math_NewtonMinimum::*)(math_Vector &) const) &math_NewtonMinimum::Gradient, "outputs the gradient vector at the minimum in Grad. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Grad is not equal to the range of the StartingPoint.", py::arg("Grad"));
cls_math_NewtonMinimum.def("NbIterations", (Standard_Integer (math_NewtonMinimum::*)() const) &math_NewtonMinimum::NbIterations, "returns the number of iterations really done in the calculation of the minimum. The exception NotDone is raised if an error has occured.");
cls_math_NewtonMinimum.def("GetStatus", (math_Status (math_NewtonMinimum::*)() const) &math_NewtonMinimum::GetStatus, "Returns the Status of computation. The exception NotDone is raised if an error has occured.");
cls_math_NewtonMinimum.def("Dump", (void (math_NewtonMinimum::*)(Standard_OStream &) const) &math_NewtonMinimum::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}