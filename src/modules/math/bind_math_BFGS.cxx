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
#include <math_Vector.hxx>
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <Standard_OStream.hxx>
#include <math_Status.hxx>
#include <math_BFGS.hxx>

void bind_math_BFGS(py::module &mod){

py::class_<math_BFGS> cls_math_BFGS(mod, "math_BFGS", "This class implements the Broyden-Fletcher-Goldfarb-Shanno variant of Davidson-Fletcher-Powell minimization algorithm of a function of multiple variables.Knowledge of the function's gradient is required.");

// Constructors
cls_math_BFGS.def(py::init<const Standard_Integer>(), py::arg("NbVariables"));
cls_math_BFGS.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("NbVariables"), py::arg("Tolerance"));
cls_math_BFGS.def(py::init<const Standard_Integer, const Standard_Real, const Standard_Integer>(), py::arg("NbVariables"), py::arg("Tolerance"), py::arg("NbIterations"));
cls_math_BFGS.def(py::init<const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("NbVariables"), py::arg("Tolerance"), py::arg("NbIterations"), py::arg("ZEPS"));

// Fields

// Methods
// cls_math_BFGS.def_static("operator new_", (void * (*)(size_t)) &math_BFGS::operator new, "None", py::arg("theSize"));
// cls_math_BFGS.def_static("operator delete_", (void (*)(void *)) &math_BFGS::operator delete, "None", py::arg("theAddress"));
// cls_math_BFGS.def_static("operator new[]_", (void * (*)(size_t)) &math_BFGS::operator new[], "None", py::arg("theSize"));
// cls_math_BFGS.def_static("operator delete[]_", (void (*)(void *)) &math_BFGS::operator delete[], "None", py::arg("theAddress"));
// cls_math_BFGS.def_static("operator new_", (void * (*)(size_t, void *)) &math_BFGS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_BFGS.def_static("operator delete_", (void (*)(void *, void *)) &math_BFGS::operator delete, "None", py::arg(""), py::arg(""));
cls_math_BFGS.def("SetBoundary", (void (math_BFGS::*)(const math_Vector &, const math_Vector &)) &math_BFGS::SetBoundary, "Set boundaries for conditional optimization. The expected indices range of vectors is [1, NbVariables].", py::arg("theLeftBorder"), py::arg("theRightBorder"));
cls_math_BFGS.def("Perform", (void (math_BFGS::*)(math_MultipleVarFunctionWithGradient &, const math_Vector &)) &math_BFGS::Perform, "Given the starting point StartingPoint, minimization is done on the function F. The solution F = Fi is found when : 2.0 * abs(Fi - Fi-1) <= Tolerance * (abs(Fi) + abs(Fi-1) + ZEPS). Tolerance, ZEPS and maximum number of iterations are given in the constructor.", py::arg("F"), py::arg("StartingPoint"));
cls_math_BFGS.def("IsSolutionReached", (Standard_Boolean (math_BFGS::*)(math_MultipleVarFunctionWithGradient &) const) &math_BFGS::IsSolutionReached, "This method is called at the end of each iteration to check if the solution is found. It can be redefined in a sub-class to implement a specific test to stop the iterations.", py::arg("F"));
cls_math_BFGS.def("IsDone", (Standard_Boolean (math_BFGS::*)() const) &math_BFGS::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_BFGS.def("Location", (const math_Vector & (math_BFGS::*)() const) &math_BFGS::Location, "returns the location vector of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_BFGS.def("Location", (void (math_BFGS::*)(math_Vector &) const) &math_BFGS::Location, "outputs the location vector of the minimum in Loc. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Loc is not equal to the range of the StartingPoint.", py::arg("Loc"));
cls_math_BFGS.def("Minimum", (Standard_Real (math_BFGS::*)() const) &math_BFGS::Minimum, "returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_BFGS.def("Gradient", (const math_Vector & (math_BFGS::*)() const) &math_BFGS::Gradient, "Returns the gradient vector at the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_BFGS.def("Gradient", (void (math_BFGS::*)(math_Vector &) const) &math_BFGS::Gradient, "Returns the value of the gradient vector at the minimum in Grad. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Grad is not equal to the range of the StartingPoint.", py::arg("Grad"));
cls_math_BFGS.def("NbIterations", (Standard_Integer (math_BFGS::*)() const) &math_BFGS::NbIterations, "Returns the number of iterations really done in the calculation of the minimum. The exception NotDone is raised if the minimum was not found.");
cls_math_BFGS.def("Dump", (void (math_BFGS::*)(Standard_OStream &) const) &math_BFGS::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}