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
#include <BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.hxx>

void bind_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox(py::module &mod){

py::class_<BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox, std::unique_ptr<BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox>, math_BFGS> cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox(mod, "BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox", "None");

// Constructors
cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"));
cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.def(py::init<math_MultipleVarFunctionWithGradient &, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("F"), py::arg("StartingPoint"), py::arg("Tolerance3d"), py::arg("Tolerance2d"), py::arg("Eps"), py::arg("NbIterations"));

// Fields

// Methods
// cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.def_static("operator delete_", (void (*)(void *)) &BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.def("IsSolutionReached", (Standard_Boolean (BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox::*)(math_MultipleVarFunctionWithGradient &) const) &BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox::IsSolutionReached, "None", py::arg("F"));

// Enums

}