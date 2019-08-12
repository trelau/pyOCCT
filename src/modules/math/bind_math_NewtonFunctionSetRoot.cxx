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
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Matrix.hxx>
#include <Standard_OStream.hxx>
#include <math_IntegerVector.hxx>
#include <math_NewtonFunctionSetRoot.hxx>

void bind_math_NewtonFunctionSetRoot(py::module &mod){

py::class_<math_NewtonFunctionSetRoot, std::unique_ptr<math_NewtonFunctionSetRoot, Deleter<math_NewtonFunctionSetRoot>>> cls_math_NewtonFunctionSetRoot(mod, "math_NewtonFunctionSetRoot", "This class computes the root of a set of N functions of N variables, knowing an initial guess at the solution and using the Newton Raphson algorithm. Knowledge of all the partial derivatives (Jacobian) is required.");

// Constructors
cls_math_NewtonFunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const math_Vector &, const Standard_Real>(), py::arg("theFunction"), py::arg("theXTolerance"), py::arg("theFTolerance"));
cls_math_NewtonFunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const math_Vector &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theXTolerance"), py::arg("theFTolerance"), py::arg("tehNbIterations"));
cls_math_NewtonFunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const Standard_Real>(), py::arg("theFunction"), py::arg("theFTolerance"));
cls_math_NewtonFunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theFTolerance"), py::arg("theNbIterations"));

// Fields

// Methods
// cls_math_NewtonFunctionSetRoot.def_static("operator new_", (void * (*)(size_t)) &math_NewtonFunctionSetRoot::operator new, "None", py::arg("theSize"));
// cls_math_NewtonFunctionSetRoot.def_static("operator delete_", (void (*)(void *)) &math_NewtonFunctionSetRoot::operator delete, "None", py::arg("theAddress"));
// cls_math_NewtonFunctionSetRoot.def_static("operator new[]_", (void * (*)(size_t)) &math_NewtonFunctionSetRoot::operator new[], "None", py::arg("theSize"));
// cls_math_NewtonFunctionSetRoot.def_static("operator delete[]_", (void (*)(void *)) &math_NewtonFunctionSetRoot::operator delete[], "None", py::arg("theAddress"));
// cls_math_NewtonFunctionSetRoot.def_static("operator new_", (void * (*)(size_t, void *)) &math_NewtonFunctionSetRoot::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_NewtonFunctionSetRoot.def_static("operator delete_", (void (*)(void *, void *)) &math_NewtonFunctionSetRoot::operator delete, "None", py::arg(""), py::arg(""));
cls_math_NewtonFunctionSetRoot.def("SetTolerance", (void (math_NewtonFunctionSetRoot::*)(const math_Vector &)) &math_NewtonFunctionSetRoot::SetTolerance, "Initializes the tolerance values for the unknowns.", py::arg("XTol"));
cls_math_NewtonFunctionSetRoot.def("Perform", (void (math_NewtonFunctionSetRoot::*)(math_FunctionSetWithDerivatives &, const math_Vector &)) &math_NewtonFunctionSetRoot::Perform, "The Newton method is done to improve the root of the function from the initial guess point. The solution is found when: abs(Xj - Xj-1)(i) <= XTol(i) and abs(Fi) <= FTol for all i;", py::arg("theFunction"), py::arg("theStartingPoint"));
cls_math_NewtonFunctionSetRoot.def("Perform", (void (math_NewtonFunctionSetRoot::*)(math_FunctionSetWithDerivatives &, const math_Vector &, const math_Vector &, const math_Vector &)) &math_NewtonFunctionSetRoot::Perform, "The Newton method is done to improve the root of the function from the initial guess point. Bounds may be given, to constrain the solution. The solution is found when: abs(Xj - Xj-1)(i) <= XTol(i) and abs(Fi) <= FTol for all i;", py::arg("theFunction"), py::arg("theStartingPoint"), py::arg("theInfBound"), py::arg("theSupBound"));
cls_math_NewtonFunctionSetRoot.def("IsSolutionReached", (Standard_Boolean (math_NewtonFunctionSetRoot::*)(math_FunctionSetWithDerivatives &)) &math_NewtonFunctionSetRoot::IsSolutionReached, "This method is called at the end of each iteration to check if the solution is found. Vectors DeltaX, Fvalues and Jacobian Matrix are consistent with the possible solution Vector Sol and can be inspected to decide whether the solution is reached or not.", py::arg("F"));
cls_math_NewtonFunctionSetRoot.def("IsDone", (Standard_Boolean (math_NewtonFunctionSetRoot::*)() const) &math_NewtonFunctionSetRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_NewtonFunctionSetRoot.def("Root", (const math_Vector & (math_NewtonFunctionSetRoot::*)() const) &math_NewtonFunctionSetRoot::Root, "Returns the value of the root of function F. Exceptions StdFail_NotDone if the algorithm fails (and IsDone returns false).");
cls_math_NewtonFunctionSetRoot.def("Root", (void (math_NewtonFunctionSetRoot::*)(math_Vector &) const) &math_NewtonFunctionSetRoot::Root, "outputs the root vector in Root. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Root is not equal to the range of the StartingPoint.", py::arg("Root"));
// cls_math_NewtonFunctionSetRoot.def("StateNumber", (Standard_Integer (math_NewtonFunctionSetRoot::*)() const) &math_NewtonFunctionSetRoot::StateNumber, "Outputs the state number associated with the solution vector root.");
cls_math_NewtonFunctionSetRoot.def("Derivative", (const math_Matrix & (math_NewtonFunctionSetRoot::*)() const) &math_NewtonFunctionSetRoot::Derivative, "Returns the matrix value of the derivative at the root. Exception NotDone is raised if the root was not found.");
cls_math_NewtonFunctionSetRoot.def("Derivative", (void (math_NewtonFunctionSetRoot::*)(math_Matrix &) const) &math_NewtonFunctionSetRoot::Derivative, "Outputs the matrix value of the derivative at the root in Der. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Der is not equal to the range of the StartingPoint.", py::arg("Der"));
cls_math_NewtonFunctionSetRoot.def("FunctionSetErrors", (const math_Vector & (math_NewtonFunctionSetRoot::*)() const) &math_NewtonFunctionSetRoot::FunctionSetErrors, "Returns the vector value of the error done on the functions at the root. Exception NotDone is raised if the root was not found.");
cls_math_NewtonFunctionSetRoot.def("FunctionSetErrors", (void (math_NewtonFunctionSetRoot::*)(math_Vector &) const) &math_NewtonFunctionSetRoot::FunctionSetErrors, "Outputs the vector value of the error done on the functions at the root in Err. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Err is not equal to the range of the StartingPoint.", py::arg("Err"));
cls_math_NewtonFunctionSetRoot.def("NbIterations", (Standard_Integer (math_NewtonFunctionSetRoot::*)() const) &math_NewtonFunctionSetRoot::NbIterations, "Returns the number of iterations really done during the computation of the Root. Exception NotDone is raised if the root was not found.");
cls_math_NewtonFunctionSetRoot.def("Dump", (void (math_NewtonFunctionSetRoot::*)(Standard_OStream &) const) &math_NewtonFunctionSetRoot::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}