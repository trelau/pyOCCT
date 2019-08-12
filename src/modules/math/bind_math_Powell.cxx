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
#include <math_MultipleVarFunction.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Standard_OStream.hxx>
#include <math_Status.hxx>
#include <math_Powell.hxx>

void bind_math_Powell(py::module &mod){

py::class_<math_Powell, std::unique_ptr<math_Powell, Deleter<math_Powell>>> cls_math_Powell(mod, "math_Powell", "This class implements the Powell method to find the minimum of function of multiple variables (the gradient does not have to be known).");

// Constructors
cls_math_Powell.def(py::init<const math_MultipleVarFunction &, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"));
cls_math_Powell.def(py::init<const math_MultipleVarFunction &, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"));
cls_math_Powell.def(py::init<const math_MultipleVarFunction &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theFunction"), py::arg("theTolerance"), py::arg("theNbIterations"), py::arg("theZEPS"));

// Fields

// Methods
// cls_math_Powell.def_static("operator new_", (void * (*)(size_t)) &math_Powell::operator new, "None", py::arg("theSize"));
// cls_math_Powell.def_static("operator delete_", (void (*)(void *)) &math_Powell::operator delete, "None", py::arg("theAddress"));
// cls_math_Powell.def_static("operator new[]_", (void * (*)(size_t)) &math_Powell::operator new[], "None", py::arg("theSize"));
// cls_math_Powell.def_static("operator delete[]_", (void (*)(void *)) &math_Powell::operator delete[], "None", py::arg("theAddress"));
// cls_math_Powell.def_static("operator new_", (void * (*)(size_t, void *)) &math_Powell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_Powell.def_static("operator delete_", (void (*)(void *, void *)) &math_Powell::operator delete, "None", py::arg(""), py::arg(""));
cls_math_Powell.def("Perform", (void (math_Powell::*)(math_MultipleVarFunction &, const math_Vector &, const math_Matrix &)) &math_Powell::Perform, "Computes Powell minimization on the function F given theStartingPoint, and an initial matrix theStartingDirection whose columns contain the initial set of directions. The solution F = Fi is found when: 2.0 * abs(Fi - Fi-1) =< Tolerance * (abs(Fi) + abs(Fi-1) + ZEPS).", py::arg("theFunction"), py::arg("theStartingPoint"), py::arg("theStartingDirections"));
cls_math_Powell.def("IsSolutionReached", (Standard_Boolean (math_Powell::*)(math_MultipleVarFunction &)) &math_Powell::IsSolutionReached, "Solution F = Fi is found when: 2.0 * abs(Fi - Fi-1) <= Tolerance * (abs(Fi) + abs(Fi-1)) + ZEPS. The maximum number of iterations allowed is given by NbIterations.", py::arg("theFunction"));
cls_math_Powell.def("IsDone", (Standard_Boolean (math_Powell::*)() const) &math_Powell::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_Powell.def("Location", (const math_Vector & (math_Powell::*)() const) &math_Powell::Location, "returns the location vector of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_Powell.def("Location", (void (math_Powell::*)(math_Vector &) const) &math_Powell::Location, "outputs the location vector of the minimum in Loc. Exception NotDone is raised if the minimum was not found. Exception DimensionError is raised if the range of Loc is not equal to the range of the StartingPoint.", py::arg("Loc"));
cls_math_Powell.def("Minimum", (Standard_Real (math_Powell::*)() const) &math_Powell::Minimum, "Returns the value of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_Powell.def("NbIterations", (Standard_Integer (math_Powell::*)() const) &math_Powell::NbIterations, "Returns the number of iterations really done during the computation of the minimum. Exception NotDone is raised if the minimum was not found.");
cls_math_Powell.def("Dump", (void (math_Powell::*)(Standard_OStream &) const) &math_Powell::Dump, "Prints information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}