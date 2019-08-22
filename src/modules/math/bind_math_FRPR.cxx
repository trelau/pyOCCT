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
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <Standard_OStream.hxx>
#include <math_Status.hxx>
#include <math_FRPR.hxx>

void bind_math_FRPR(py::module &mod){

py::class_<math_FRPR> cls_math_FRPR(mod, "math_FRPR", "this class implements the Fletcher-Reeves-Polak_Ribiere minimization algorithm of a function of multiple variables. Knowledge of the function's gradient is required.");

// Constructors
cls_math_FRPR.def(py::init<const math_MultipleVarFunctionWithGradient &, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"));
cls_math_FRPR.def(py::init<const math_MultipleVarFunctionWithGradient &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"));
cls_math_FRPR.def(py::init<const math_MultipleVarFunctionWithGradient &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"), py::arg("theZEPS"));

// Fields

// Methods
// cls_math_FRPR.def_static("operator new_", (void * (*)(size_t)) &math_FRPR::operator new, "None", py::arg("theSize"));
// cls_math_FRPR.def_static("operator delete_", (void (*)(void *)) &math_FRPR::operator delete, "None", py::arg("theAddress"));
// cls_math_FRPR.def_static("operator new[]_", (void * (*)(size_t)) &math_FRPR::operator new[], "None", py::arg("theSize"));
// cls_math_FRPR.def_static("operator delete[]_", (void (*)(void *)) &math_FRPR::operator delete[], "None", py::arg("theAddress"));
// cls_math_FRPR.def_static("operator new_", (void * (*)(size_t, void *)) &math_FRPR::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_FRPR.def_static("operator delete_", (void (*)(void *, void *)) &math_FRPR::operator delete, "None", py::arg(""), py::arg(""));
cls_math_FRPR.def("Perform", (void (math_FRPR::*)(math_MultipleVarFunctionWithGradient &, const math_Vector &)) &math_FRPR::Perform, "The solution F = Fi is found when 2.0 * abs(Fi - Fi-1) <= Tolerance * (abs(Fi) + abs(Fi-1) + ZEPS).", py::arg("theFunction"), py::arg("theStartingPoint"));
cls_math_FRPR.def("IsSolutionReached", (Standard_Boolean (math_FRPR::*)(math_MultipleVarFunctionWithGradient &)) &math_FRPR::IsSolutionReached, "The solution F = Fi is found when: 2.0 * abs(Fi - Fi-1) <= Tolerance * (abs(Fi) + abs(Fi-1)) + ZEPS. The maximum number of iterations allowed is given by NbIterations.", py::arg("theFunction"));
cls_math_FRPR.def("IsDone", (Standard_Boolean (math_FRPR::*)() const) &math_FRPR::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_FRPR.def("Location", (const math_Vector & (math_FRPR::*)() const) &math_FRPR::Location, "returns the location vector of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_FRPR.def("Location", (void (math_FRPR::*)(math_Vector &) const) &math_FRPR::Location, "outputs the location vector of the minimum in Loc. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Loc is not equal to the range of the StartingPoint.", py::arg("Loc"));
cls_math_FRPR.def("Minimum", (Standard_Real (math_FRPR::*)() const) &math_FRPR::Minimum, "returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_FRPR.def("Gradient", (const math_Vector & (math_FRPR::*)() const) &math_FRPR::Gradient, "returns the gradient vector at the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_FRPR.def("Gradient", (void (math_FRPR::*)(math_Vector &) const) &math_FRPR::Gradient, "outputs the gradient vector at the minimum in Grad. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Grad is not equal to the range of the StartingPoint.", py::arg("Grad"));
cls_math_FRPR.def("NbIterations", (Standard_Integer (math_FRPR::*)() const) &math_FRPR::NbIterations, "returns the number of iterations really done during the computation of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_FRPR.def("Dump", (void (math_FRPR::*)(Standard_OStream &) const) &math_FRPR::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}