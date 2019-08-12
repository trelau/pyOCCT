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
#include <math_FunctionWithDerivative.hxx>
#include <math_FunctionSample.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <math_FunctionAllRoots.hxx>

void bind_math_FunctionAllRoots(py::module &mod){

py::class_<math_FunctionAllRoots, std::unique_ptr<math_FunctionAllRoots, Deleter<math_FunctionAllRoots>>> cls_math_FunctionAllRoots(mod, "math_FunctionAllRoots", "This algorithm uses a sample of the function to find all intervals on which the function is null, and afterwards uses the FunctionRoots algorithm to find the points where the function is null outside the 'null intervals'. Knowledge of the derivative is required.");

// Constructors
cls_math_FunctionAllRoots.def(py::init<math_FunctionWithDerivative &, const math_FunctionSample &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("S"), py::arg("EpsX"), py::arg("EpsF"), py::arg("EpsNul"));

// Fields

// Methods
// cls_math_FunctionAllRoots.def_static("operator new_", (void * (*)(size_t)) &math_FunctionAllRoots::operator new, "None", py::arg("theSize"));
// cls_math_FunctionAllRoots.def_static("operator delete_", (void (*)(void *)) &math_FunctionAllRoots::operator delete, "None", py::arg("theAddress"));
// cls_math_FunctionAllRoots.def_static("operator new[]_", (void * (*)(size_t)) &math_FunctionAllRoots::operator new[], "None", py::arg("theSize"));
// cls_math_FunctionAllRoots.def_static("operator delete[]_", (void (*)(void *)) &math_FunctionAllRoots::operator delete[], "None", py::arg("theAddress"));
// cls_math_FunctionAllRoots.def_static("operator new_", (void * (*)(size_t, void *)) &math_FunctionAllRoots::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_FunctionAllRoots.def_static("operator delete_", (void (*)(void *, void *)) &math_FunctionAllRoots::operator delete, "None", py::arg(""), py::arg(""));
cls_math_FunctionAllRoots.def("IsDone", (Standard_Boolean (math_FunctionAllRoots::*)() const) &math_FunctionAllRoots::IsDone, "Returns True if the computation has been done successfully.");
cls_math_FunctionAllRoots.def("NbIntervals", (Standard_Integer (math_FunctionAllRoots::*)() const) &math_FunctionAllRoots::NbIntervals, "Returns the number of intervals on which the function is Null. An exception is raised if IsDone returns False.");
cls_math_FunctionAllRoots.def("GetInterval", [](math_FunctionAllRoots &self, const Standard_Integer Index, Standard_Real & A, Standard_Real & B){ self.GetInterval(Index, A, B); return std::tuple<Standard_Real &, Standard_Real &>(A, B); }, "Returns the interval of parameter of range Index. An exception is raised if IsDone returns False; An exception is raised if Index<=0 or Index >Nbintervals.", py::arg("Index"), py::arg("A"), py::arg("B"));
cls_math_FunctionAllRoots.def("GetIntervalState", [](math_FunctionAllRoots &self, const Standard_Integer Index, Standard_Integer & IFirst, Standard_Integer & ILast){ self.GetIntervalState(Index, IFirst, ILast); return std::tuple<Standard_Integer &, Standard_Integer &>(IFirst, ILast); }, "returns the State Number associated to the interval Index. An exception is raised if IsDone returns False; An exception is raised if Index<=0 or Index >Nbintervals.", py::arg("Index"), py::arg("IFirst"), py::arg("ILast"));
cls_math_FunctionAllRoots.def("NbPoints", (Standard_Integer (math_FunctionAllRoots::*)() const) &math_FunctionAllRoots::NbPoints, "returns the number of points where the function is Null. An exception is raised if IsDone returns False.");
cls_math_FunctionAllRoots.def("GetPoint", (Standard_Real (math_FunctionAllRoots::*)(const Standard_Integer) const) &math_FunctionAllRoots::GetPoint, "Returns the parameter of the point of range Index. An exception is raised if IsDone returns False; An exception is raised if Index<=0 or Index >NbPoints.", py::arg("Index"));
cls_math_FunctionAllRoots.def("GetPointState", (Standard_Integer (math_FunctionAllRoots::*)(const Standard_Integer) const) &math_FunctionAllRoots::GetPointState, "returns the State Number associated to the point Index. An exception is raised if IsDone returns False; An exception is raised if Index<=0 or Index >Nbintervals.", py::arg("Index"));
cls_math_FunctionAllRoots.def("Dump", (void (math_FunctionAllRoots::*)(Standard_OStream &) const) &math_FunctionAllRoots::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

// Enums

}