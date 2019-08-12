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
#include <math_FunctionSetRoot.hxx>

void bind_math_FunctionSetRoot(py::module &mod){

py::class_<math_FunctionSetRoot, std::unique_ptr<math_FunctionSetRoot, Deleter<math_FunctionSetRoot>>> cls_math_FunctionSetRoot(mod, "math_FunctionSetRoot", "The math_FunctionSetRoot class calculates the root of a set of N functions of M variables (N<M, N=M or N>M). Knowing an initial guess of the solution and using a minimization algorithm, a search is made in the Newton direction and then in the Gradient direction if there is no success in the Newton direction. This algorithm can also be used for functions minimization. Knowledge of all the partial derivatives (the Jacobian) is required.");

// Constructors
cls_math_FunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const math_Vector &>(), py::arg("F"), py::arg("Tolerance"));
cls_math_FunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const math_Vector &, const Standard_Integer>(), py::arg("F"), py::arg("Tolerance"), py::arg("NbIterations"));
cls_math_FunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &>(), py::arg("F"));
cls_math_FunctionSetRoot.def(py::init<math_FunctionSetWithDerivatives &, const Standard_Integer>(), py::arg("F"), py::arg("NbIterations"));

// Fields

// Methods
// cls_math_FunctionSetRoot.def_static("operator new_", (void * (*)(size_t)) &math_FunctionSetRoot::operator new, "None", py::arg("theSize"));
// cls_math_FunctionSetRoot.def_static("operator delete_", (void (*)(void *)) &math_FunctionSetRoot::operator delete, "None", py::arg("theAddress"));
// cls_math_FunctionSetRoot.def_static("operator new[]_", (void * (*)(size_t)) &math_FunctionSetRoot::operator new[], "None", py::arg("theSize"));
// cls_math_FunctionSetRoot.def_static("operator delete[]_", (void (*)(void *)) &math_FunctionSetRoot::operator delete[], "None", py::arg("theAddress"));
// cls_math_FunctionSetRoot.def_static("operator new_", (void * (*)(size_t, void *)) &math_FunctionSetRoot::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_FunctionSetRoot.def_static("operator delete_", (void (*)(void *, void *)) &math_FunctionSetRoot::operator delete, "None", py::arg(""), py::arg(""));
cls_math_FunctionSetRoot.def("SetTolerance", (void (math_FunctionSetRoot::*)(const math_Vector &)) &math_FunctionSetRoot::SetTolerance, "Initializes the tolerance values.", py::arg("Tolerance"));
cls_math_FunctionSetRoot.def("IsSolutionReached", (Standard_Boolean (math_FunctionSetRoot::*)(math_FunctionSetWithDerivatives &)) &math_FunctionSetRoot::IsSolutionReached, "This routine is called at the end of each iteration to check if the solution was found. It can be redefined in a sub-class to implement a specific test to stop the iterations. In this case, the solution is found when: abs(Xi - Xi-1) <= Tolerance for all unknowns.", py::arg("F"));
cls_math_FunctionSetRoot.def("Perform", [](math_FunctionSetRoot &self, math_FunctionSetWithDerivatives & a0, const math_Vector & a1) -> void { return self.Perform(a0, a1); });
cls_math_FunctionSetRoot.def("Perform", (void (math_FunctionSetRoot::*)(math_FunctionSetWithDerivatives &, const math_Vector &, const Standard_Boolean)) &math_FunctionSetRoot::Perform, "Improves the root of function from the initial guess point. The infinum and supremum may be given to constrain the solution. In this case, the solution is found when: abs(Xi - Xi-1)(j) <= Tolerance(j) for all unknowns.", py::arg("theFunction"), py::arg("theStartingPoint"), py::arg("theStopOnDivergent"));
cls_math_FunctionSetRoot.def("Perform", [](math_FunctionSetRoot &self, math_FunctionSetWithDerivatives & a0, const math_Vector & a1, const math_Vector & a2, const math_Vector & a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_math_FunctionSetRoot.def("Perform", (void (math_FunctionSetRoot::*)(math_FunctionSetWithDerivatives &, const math_Vector &, const math_Vector &, const math_Vector &, const Standard_Boolean)) &math_FunctionSetRoot::Perform, "Improves the root of function from the initial guess point. The infinum and supremum may be given to constrain the solution. In this case, the solution is found when: abs(Xi - Xi-1) <= Tolerance for all unknowns.", py::arg("theFunction"), py::arg("theStartingPoint"), py::arg("theInfBound"), py::arg("theSupBound"), py::arg("theStopOnDivergent"));
cls_math_FunctionSetRoot.def("IsDone", (Standard_Boolean (math_FunctionSetRoot::*)() const) &math_FunctionSetRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_FunctionSetRoot.def("NbIterations", (Standard_Integer (math_FunctionSetRoot::*)() const) &math_FunctionSetRoot::NbIterations, "Returns the number of iterations really done during the computation of the root. Exception NotDone is raised if the root was not found.");
cls_math_FunctionSetRoot.def("StateNumber", (Standard_Integer (math_FunctionSetRoot::*)() const) &math_FunctionSetRoot::StateNumber, "returns the stateNumber (as returned by F.GetStateNumber()) associated to the root found.");
cls_math_FunctionSetRoot.def("Root", (const math_Vector & (math_FunctionSetRoot::*)() const) &math_FunctionSetRoot::Root, "Returns the value of the root of function F. Exception NotDone is raised if the root was not found.");
cls_math_FunctionSetRoot.def("Root", (void (math_FunctionSetRoot::*)(math_Vector &) const) &math_FunctionSetRoot::Root, "Outputs the root vector in Root. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Root is not equal to the range of the StartingPoint.", py::arg("Root"));
cls_math_FunctionSetRoot.def("Derivative", (const math_Matrix & (math_FunctionSetRoot::*)() const) &math_FunctionSetRoot::Derivative, "Returns the matrix value of the derivative at the root. Exception NotDone is raised if the root was not found.");
cls_math_FunctionSetRoot.def("Derivative", (void (math_FunctionSetRoot::*)(math_Matrix &) const) &math_FunctionSetRoot::Derivative, "outputs the matrix value of the derivative at the root in Der. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the column range of <Der> is not equal to the range of the startingPoint.", py::arg("Der"));
cls_math_FunctionSetRoot.def("FunctionSetErrors", (const math_Vector & (math_FunctionSetRoot::*)() const) &math_FunctionSetRoot::FunctionSetErrors, "returns the vector value of the error done on the functions at the root. Exception NotDone is raised if the root was not found.");
cls_math_FunctionSetRoot.def("FunctionSetErrors", (void (math_FunctionSetRoot::*)(math_Vector &) const) &math_FunctionSetRoot::FunctionSetErrors, "outputs the vector value of the error done on the functions at the root in Err. Exception NotDone is raised if the root was not found. Exception DimensionError is raised if the range of Err is not equal to the range of the StartingPoint.", py::arg("Err"));
cls_math_FunctionSetRoot.def("Dump", (void (math_FunctionSetRoot::*)(Standard_OStream &) const) &math_FunctionSetRoot::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));
cls_math_FunctionSetRoot.def("IsDivergent", (Standard_Boolean (math_FunctionSetRoot::*)() const) &math_FunctionSetRoot::IsDivergent, "None");

// Enums

}