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
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <Blend_CurvPointFuncInv.hxx>

void bind_Blend_CurvPointFuncInv(py::module &mod){

py::class_<Blend_CurvPointFuncInv, std::unique_ptr<Blend_CurvPointFuncInv>, math_FunctionSetWithDerivatives> cls_Blend_CurvPointFuncInv(mod, "Blend_CurvPointFuncInv", "Deferred class for a function used to compute a blending surface between a surface and a curve, using a guide line. This function is used to find a solution on a done point of the curve. The vector <X> used in Value, Values and Derivatives methods has to be the vector of the parametric coordinates w, U, V where w is the parameter on the guide line, U,V are the parametric coordinates of a point on the partner surface.");

// Fields

// Methods
// cls_Blend_CurvPointFuncInv.def_static("operator new_", (void * (*)(size_t)) &Blend_CurvPointFuncInv::operator new, "None", py::arg("theSize"));
// cls_Blend_CurvPointFuncInv.def_static("operator delete_", (void (*)(void *)) &Blend_CurvPointFuncInv::operator delete, "None", py::arg("theAddress"));
// cls_Blend_CurvPointFuncInv.def_static("operator new[]_", (void * (*)(size_t)) &Blend_CurvPointFuncInv::operator new[], "None", py::arg("theSize"));
// cls_Blend_CurvPointFuncInv.def_static("operator delete[]_", (void (*)(void *)) &Blend_CurvPointFuncInv::operator delete[], "None", py::arg("theAddress"));
// cls_Blend_CurvPointFuncInv.def_static("operator new_", (void * (*)(size_t, void *)) &Blend_CurvPointFuncInv::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Blend_CurvPointFuncInv.def_static("operator delete_", (void (*)(void *, void *)) &Blend_CurvPointFuncInv::operator delete, "None", py::arg(""), py::arg(""));
cls_Blend_CurvPointFuncInv.def("NbVariables", (Standard_Integer (Blend_CurvPointFuncInv::*)() const) &Blend_CurvPointFuncInv::NbVariables, "Returns 3.");
cls_Blend_CurvPointFuncInv.def("NbEquations", (Standard_Integer (Blend_CurvPointFuncInv::*)() const) &Blend_CurvPointFuncInv::NbEquations, "returns the number of equations of the function.");
cls_Blend_CurvPointFuncInv.def("Value", (Standard_Boolean (Blend_CurvPointFuncInv::*)(const math_Vector &, math_Vector &)) &Blend_CurvPointFuncInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_Blend_CurvPointFuncInv.def("Derivatives", (Standard_Boolean (Blend_CurvPointFuncInv::*)(const math_Vector &, math_Matrix &)) &Blend_CurvPointFuncInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_Blend_CurvPointFuncInv.def("Values", (Standard_Boolean (Blend_CurvPointFuncInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Blend_CurvPointFuncInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Blend_CurvPointFuncInv.def("Set", (void (Blend_CurvPointFuncInv::*)(const gp_Pnt &)) &Blend_CurvPointFuncInv::Set, "Set the Point on which a solution has to be found.", py::arg("P"));
cls_Blend_CurvPointFuncInv.def("GetTolerance", (void (Blend_CurvPointFuncInv::*)(math_Vector &, const Standard_Real) const) &Blend_CurvPointFuncInv::GetTolerance, "Returns in the vector Tolerance the parametric tolerance for each of the 3 variables; Tol is the tolerance used in 3d space.", py::arg("Tolerance"), py::arg("Tol"));
cls_Blend_CurvPointFuncInv.def("GetBounds", (void (Blend_CurvPointFuncInv::*)(math_Vector &, math_Vector &) const) &Blend_CurvPointFuncInv::GetBounds, "Returns in the vector InfBound the lowest values allowed for each of the 3 variables. Returns in the vector SupBound the greatest values allowed for each of the 3 variables.", py::arg("InfBound"), py::arg("SupBound"));
cls_Blend_CurvPointFuncInv.def("IsSolution", (Standard_Boolean (Blend_CurvPointFuncInv::*)(const math_Vector &, const Standard_Real)) &Blend_CurvPointFuncInv::IsSolution, "Returns Standard_True if Sol is a zero of the function. Tol is the tolerance used in 3d space.", py::arg("Sol"), py::arg("Tol"));

// Enums

}