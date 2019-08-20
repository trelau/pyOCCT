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
#include <math_NewtonMinimum.hxx>
#include <Standard.hxx>
#include <math_MultipleVarFunctionWithHessian.hxx>
#include <Standard_TypeDef.hxx>
#include <FairCurve_Newton.hxx>

void bind_FairCurve_Newton(py::module &mod){

py::class_<FairCurve_Newton, std::unique_ptr<FairCurve_Newton>, math_NewtonMinimum> cls_FairCurve_Newton(mod, "FairCurve_Newton", "Algorithme of Optimization used to make 'FairCurve'");

// Constructors
cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &>(), py::arg("theFunction"));
cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real>(), py::arg("theFunction"), py::arg("theSpatialTolerance"));
cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Real>(), py::arg("theFunction"), py::arg("theSpatialTolerance"), py::arg("theCriteriumTolerance"));
cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theSpatialTolerance"), py::arg("theCriteriumTolerance"), py::arg("theNbIterations"));
cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("theFunction"), py::arg("theSpatialTolerance"), py::arg("theCriteriumTolerance"), py::arg("theNbIterations"), py::arg("theConvexity"));
cls_FairCurve_Newton.def(py::init<const math_MultipleVarFunctionWithHessian &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Boolean>(), py::arg("theFunction"), py::arg("theSpatialTolerance"), py::arg("theCriteriumTolerance"), py::arg("theNbIterations"), py::arg("theConvexity"), py::arg("theWithSingularity"));

// Fields

// Methods
// cls_FairCurve_Newton.def_static("operator new_", (void * (*)(size_t)) &FairCurve_Newton::operator new, "None", py::arg("theSize"));
// cls_FairCurve_Newton.def_static("operator delete_", (void (*)(void *)) &FairCurve_Newton::operator delete, "None", py::arg("theAddress"));
// cls_FairCurve_Newton.def_static("operator new[]_", (void * (*)(size_t)) &FairCurve_Newton::operator new[], "None", py::arg("theSize"));
// cls_FairCurve_Newton.def_static("operator delete[]_", (void (*)(void *)) &FairCurve_Newton::operator delete[], "None", py::arg("theAddress"));
// cls_FairCurve_Newton.def_static("operator new_", (void * (*)(size_t, void *)) &FairCurve_Newton::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FairCurve_Newton.def_static("operator delete_", (void (*)(void *, void *)) &FairCurve_Newton::operator delete, "None", py::arg(""), py::arg(""));
cls_FairCurve_Newton.def("IsConverged", (Standard_Boolean (FairCurve_Newton::*)() const) &FairCurve_Newton::IsConverged, "This method is called at the end of each iteration to check the convergence : || Xi+1 - Xi || < SpatialTolerance/100 Or || Xi+1 - Xi || < SpatialTolerance and |F(Xi+1) - F(Xi)| < CriteriumTolerance * |F(xi)| It can be redefined in a sub-class to implement a specific test.");

// Enums

}