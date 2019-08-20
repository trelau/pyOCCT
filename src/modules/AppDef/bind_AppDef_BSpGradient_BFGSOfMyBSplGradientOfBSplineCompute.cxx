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
#include <math_BFGS.hxx>
#include <Standard.hxx>
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <math_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.hxx>

void bind_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute(py::module &mod){

py::class_<AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute, std::unique_ptr<AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute>, math_BFGS> cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute(mod, "AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute", "None");

// Constructors
cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"));
cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"), py::arg("NbIterations"));

// Fields

// Methods
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute.def("IsSolutionReached", (Standard_Boolean (AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::*)(math_MultipleVarFunctionWithGradient &) const) &AppDef_BSpGradient_BFGSOfMyBSplGradientOfBSplineCompute::IsSolutionReached, "None", py::arg("F"));

// Enums

}