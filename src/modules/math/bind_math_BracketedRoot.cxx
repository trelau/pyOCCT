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
#include <math_Function.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <math_BracketedRoot.hxx>

void bind_math_BracketedRoot(py::module &mod){

py::class_<math_BracketedRoot> cls_math_BracketedRoot(mod, "math_BracketedRoot", "This class implements the Brent method to find the root of a function located within two bounds. No knowledge of the derivative is required.");

// Constructors
cls_math_BracketedRoot.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("Bound1"), py::arg("Bound2"), py::arg("Tolerance"));
cls_math_BracketedRoot.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("Bound1"), py::arg("Bound2"), py::arg("Tolerance"), py::arg("NbIterations"));
cls_math_BracketedRoot.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("F"), py::arg("Bound1"), py::arg("Bound2"), py::arg("Tolerance"), py::arg("NbIterations"), py::arg("ZEPS"));

// Fields

// Methods
// cls_math_BracketedRoot.def_static("operator new_", (void * (*)(size_t)) &math_BracketedRoot::operator new, "None", py::arg("theSize"));
// cls_math_BracketedRoot.def_static("operator delete_", (void (*)(void *)) &math_BracketedRoot::operator delete, "None", py::arg("theAddress"));
// cls_math_BracketedRoot.def_static("operator new[]_", (void * (*)(size_t)) &math_BracketedRoot::operator new[], "None", py::arg("theSize"));
// cls_math_BracketedRoot.def_static("operator delete[]_", (void (*)(void *)) &math_BracketedRoot::operator delete[], "None", py::arg("theAddress"));
// cls_math_BracketedRoot.def_static("operator new_", (void * (*)(size_t, void *)) &math_BracketedRoot::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_BracketedRoot.def_static("operator delete_", (void (*)(void *, void *)) &math_BracketedRoot::operator delete, "None", py::arg(""), py::arg(""));
cls_math_BracketedRoot.def("IsDone", (Standard_Boolean (math_BracketedRoot::*)() const) &math_BracketedRoot::IsDone, "Returns true if the computations are successful, otherwise returns false.");
cls_math_BracketedRoot.def("Root", (Standard_Real (math_BracketedRoot::*)() const) &math_BracketedRoot::Root, "returns the value of the root. Exception NotDone is raised if the minimum was not found.");
cls_math_BracketedRoot.def("Value", (Standard_Real (math_BracketedRoot::*)() const) &math_BracketedRoot::Value, "returns the value of the function at the root. Exception NotDone is raised if the minimum was not found.");
cls_math_BracketedRoot.def("NbIterations", (Standard_Integer (math_BracketedRoot::*)() const) &math_BracketedRoot::NbIterations, "returns the number of iterations really done during the computation of the Root. Exception NotDone is raised if the minimum was not found.");
cls_math_BracketedRoot.def("Dump", (void (math_BracketedRoot::*)(Standard_OStream &) const) &math_BracketedRoot::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

// Enums

}