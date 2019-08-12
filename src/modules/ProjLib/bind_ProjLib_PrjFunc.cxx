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
#include <Adaptor3d_Surface.hxx>
#include <Adaptor3d_Curve.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard.hxx>
#include <Adaptor3d_CurvePtr.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt2d.hxx>
#include <ProjLib_PrjFunc.hxx>

void bind_ProjLib_PrjFunc(py::module &mod){

py::class_<ProjLib_PrjFunc, std::unique_ptr<ProjLib_PrjFunc, Deleter<ProjLib_PrjFunc>>, math_FunctionSetWithDerivatives> cls_ProjLib_PrjFunc(mod, "ProjLib_PrjFunc", "None");

// Constructors
cls_ProjLib_PrjFunc.def(py::init<const Adaptor3d_CurvePtr &, const Standard_Real, const Adaptor3d_SurfacePtr &, const Standard_Integer>(), py::arg("C"), py::arg("FixVal"), py::arg("S"), py::arg("Fix"));

// Fields

// Methods
// cls_ProjLib_PrjFunc.def_static("operator new_", (void * (*)(size_t)) &ProjLib_PrjFunc::operator new, "None", py::arg("theSize"));
// cls_ProjLib_PrjFunc.def_static("operator delete_", (void (*)(void *)) &ProjLib_PrjFunc::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_PrjFunc.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_PrjFunc::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_PrjFunc.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_PrjFunc::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_PrjFunc.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_PrjFunc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_PrjFunc.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_PrjFunc::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_PrjFunc.def("NbVariables", (Standard_Integer (ProjLib_PrjFunc::*)() const) &ProjLib_PrjFunc::NbVariables, "returns the number of variables of the function.");
cls_ProjLib_PrjFunc.def("NbEquations", (Standard_Integer (ProjLib_PrjFunc::*)() const) &ProjLib_PrjFunc::NbEquations, "returns the number of equations of the function.");
cls_ProjLib_PrjFunc.def("Value", (Standard_Boolean (ProjLib_PrjFunc::*)(const math_Vector &, math_Vector &)) &ProjLib_PrjFunc::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_ProjLib_PrjFunc.def("Derivatives", (Standard_Boolean (ProjLib_PrjFunc::*)(const math_Vector &, math_Matrix &)) &ProjLib_PrjFunc::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_ProjLib_PrjFunc.def("Values", (Standard_Boolean (ProjLib_PrjFunc::*)(const math_Vector &, math_Vector &, math_Matrix &)) &ProjLib_PrjFunc::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_ProjLib_PrjFunc.def("Solution", (gp_Pnt2d (ProjLib_PrjFunc::*)() const) &ProjLib_PrjFunc::Solution, "returns point on surface");

// Enums

}